//
// Synchronous buffer-oriented serial interface classes for Win32
// jmiles@pop.net
//
// Current providers:
//
//   COMBLOCK: Abstract base class
//   SERBLOCK: RS-232
//   TCPBLOCK: TCP/IP
//   FTDBLOCK: FTDI FTD2XX API
//
// Warning: not multithread-safe!
//

//msavic
#include "lime_E4440A.h"

#define MAX_BLK_LEN      65536 // Maximum bytes in each incoming/outgoing data block
#define RECV_GRANULARITY 1     // Read this many bytes at a time

enum TERM_REASON               // Reasons for termination of receive() method
{
   SR_IN_PROGRESS,             // 0
   SR_ERROR,                   // 1
   SR_TIMEOUT,                 // 2
   SR_DROPOUT,                 // 3
   SR_EOS,                     // 4
   SR_OVERFLOW,                // 5
   SR_REQUEST_FULFILLED,       // 6
   SR_USER_ABORT,              // 7
   SR_DISCONNECTED,            // 8
};

typedef int (WINAPI *SRPROGRESSCB)(void);

//---------------------------------------------------------------------------------
// Functionality common to all providers
//---------------------------------------------------------------------------------

struct COMBLOCK
{
   //
   // (Constructor is implementation-specific)
   //

   virtual bool send     (unsigned char *buffer, 
                          int            len     = -1,             // buffer is treated as ASCIIZ string if -1
                          int            timeout = INFINITE) = 0;

   virtual bool send     (char *buffer,
                          int   len = -1,
                          int   timeout = INFINITE)
      {
      return send((unsigned char *) buffer, len, timeout);
      }

   virtual unsigned char *receive (int          expected_len,      // # of bytes expected (use -1 for timeout or EOS termination only)
                                   int          EOS_char,          // Terminate when this character received (if not -1)
                                   int          timeout_msec,      // Allow this much total time for transfer to finish (if > 0)
                                   int          dropout_msec,      // Terminate after this much time elapses between bytes
                                   SRPROGRESSCB progress_callback, // Give app the chance to abort a lengthy read in progress
                                   int         *actual_cnt,        // Write actual # of received bytes here (if not NULL) 
                                   TERM_REASON *term_reason) = 0;  // Termination reason stored here (if not NULL)

   virtual ~COMBLOCK()
      {
      }
};

//---------------------------------------------------------------------------------
// RS-232 
//---------------------------------------------------------------------------------

#define hfUseDTR     0x01 
#define hfUseRTS     0x02 
#define hfRequireDSR 0x04 
#define hfRequireCTS 0x08 

#ifndef SERIAL_CONTROL_MODE
#define SERIAL_CONTROL_MODE hfUseRTS | hfRequireCTS
#endif

class SERBLOCK : public COMBLOCK
{
   char   device       [MAX_PATH];
   char   setup_string [MAX_PATH];
   char   error_string [512];
   HANDLE hPort;

   // ---------------------------------------
   // Open, configure, and close serial port device
   //
   // Includes config code from Hector Santos's post on
   // microsoft.public.win32.programmer.kernel, 23-Nov-2003
   // ---------------------------------------

   void SetDtrLine(bool on)
      {   
      EscapeCommFunction(hPort, on ? SETDTR : CLRDTR);
      }

   void HWFlowEnable(DWORD options)
      {   
      if (hPort == INVALID_HANDLE_VALUE)
         {
         return;
         }

      DCB dcb;

      GetCommState(hPort, &dcb);
      if ((options & hfUseRTS) == hfUseRTS)
         {
         dcb.fRtsControl = RTS_CONTROL_HANDSHAKE;
         }
      else 
         {
         dcb.fRtsControl = RTS_CONTROL_ENABLE;
         }
      if ((options & hfUseDTR) == hfUseDTR)
         {
         dcb.fDtrControl = DTR_CONTROL_HANDSHAKE;
         }
      else 
         {
         dcb.fDtrControl = DTR_CONTROL_ENABLE;
         }

      COMMPROP prop;
      GetCommProperties(hPort, &prop);

      dcb.XoffLim      = WORD(prop.dwCurrentRxQueue / 4);        // Shutdown when 1/4 is remaining 
      dcb.XonLim       = WORD(prop.dwCurrentRxQueue / 4);        // Resume when 1/4 is full 
      dcb.fOutxCtsFlow = ((options & hfRequireCTS) == hfRequireCTS);
      dcb.fOutxDsrFlow = ((options & hfRequireDSR) == hfRequireDSR);

      SetCommState(hPort, &dcb);
      }

   void SetupCommState(char *config_text, bool Flow, C8 **error_text)
      {   
      DCB config;

      ZeroMemory(&config, sizeof(config));
      config.DCBlength = sizeof(config);

      if (!BuildCommDCBA(config_text, &config))
         {
         show_last_error(error_text, "BuildCommDCB: %s",config_text);
         }

      DCB dcb;

      if (!GetCommState(hPort, &dcb))
         {
         show_last_error(error_text, "GetCommProperties");
         }

      dcb.BaudRate        = config.BaudRate;
      dcb.ByteSize        = config.ByteSize;
      dcb.Parity          = config.Parity;
      dcb.StopBits        = config.StopBits;
      dcb.fBinary         = TRUE;
      dcb.fOutxCtsFlow    = Flow;
      dcb.fOutxDsrFlow    = FALSE;
      dcb.fDtrControl     = DTR_CONTROL_ENABLE;
      dcb.fDsrSensitivity = FALSE;
      dcb.fOutX           = FALSE;
      dcb.fInX            = FALSE;
      dcb.fErrorChar      = FALSE;
      dcb.fNull           = FALSE;
      dcb.fRtsControl     = Flow ? RTS_CONTROL_HANDSHAKE : RTS_CONTROL_ENABLE;
      dcb.fAbortOnError   = FALSE;

      if (Flow)
         {
         COMMPROP prop;

         if (!GetCommProperties(hPort, &prop))
            {
            show_last_error(error_text, "GetCommProperties");
            }

         dcb.XoffLim = WORD(prop.dwCurrentRxQueue / 4);  // Shutdown when 1/4 is remaining 
         dcb.XonLim  = WORD(prop.dwCurrentRxQueue / 4);  // Resume when 1/4 is full 
         }

      if (!SetCommState(hPort, &dcb))
         {
         show_last_error(error_text, "SetCommState");
         }

      //
      // We implement all required timeout logic ourselves -- disable it at the port level
      //

      COMMTIMEOUTS cto = { 0, 0, 0, 0, 0 };

      if (!SetCommTimeouts(hPort, &cto))
         {
         show_last_error(error_text, "SetCommTimeouts");
         }
      }

   void open_port(char **error_text)
      {
      if (hPort != INVALID_HANDLE_VALUE)
         {
         return;
         }

      //
      // Open the port
      //

      SECURITY_ATTRIBUTES sa;
      ZeroMemory(&sa, sizeof(sa));
      sa.nLength = sizeof(sa);
      sa.bInheritHandle = TRUE;

      hPort = CreateFileA(device,
                         GENERIC_READ | GENERIC_WRITE, 
                         FILE_SHARE_READ | FILE_SHARE_WRITE, 
                        &sa, 
                         OPEN_EXISTING, 
                         FILE_FLAG_OVERLAPPED, 
                         0);

      if (hPort == INVALID_HANDLE_VALUE) 
         {
         show_last_error(error_text, "CreateFile error: Port unavailable or in use");

         if (error_text != NULL)
            {
            return;
            }

         exit(1);
         }

      //
      // Configure it
      //

      SetDtrLine(1);

      SetupCommState(setup_string, TRUE, error_text);

      HWFlowEnable(SERIAL_CONTROL_MODE);
      }

   void close_port(void)
      {
      if (hPort == INVALID_HANDLE_VALUE)
         {
         return;
         }

      SetDtrLine(0);

      if (!CloseHandle(hPort))
         {
         show_last_error(NULL, "CloseHandle");
         }

      hPort = INVALID_HANDLE_VALUE;
      }

   // ---------------------------------------
   // Error diags
   // ---------------------------------------

   void show_last_error(C8 **error_text, C8 *caption = NULL, ...)
      {
      LPVOID lpMsgBuf = "Hosed";       // Default message for Win9x (FormatMessage() is NT-only)

      FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS, 
                    NULL, 
                    GetLastError(), 
                    0,
           (LPTSTR) &lpMsgBuf, 
                    0, 
                    NULL);

      if (caption == NULL)
         {
         caption = "Error";
         }
      else
         {
         static char work_string[4096];

         va_list ap;

         va_start(ap, 
                  caption);

         vsprintf(work_string, 
                  caption, 
                  ap);

         va_end  (ap);

         caption = work_string;
         }

      //
      // Change 'file' references to 'port's
      // 

      for (;;)
         {
         char *fix_error_text = strstr((char *) lpMsgBuf,"file");

         if (fix_error_text == NULL)
            {
            break;
            }

         fix_error_text[0] = 'p';
         fix_error_text[1] = 'o';
         fix_error_text[2] = 'r';
         fix_error_text[3] = 't';
         }

      if (error_text)
         {
         sprintf(error_string, "%s -- %s", caption, lpMsgBuf);
         *error_text = error_string;
         }
      else
         {
//msavic
			MessageBoxA(NULL,
				(LPCSTR)lpMsgBuf,
				caption,
				MB_OK | MB_ICONINFORMATION);
			}

/*
         MessageBox(NULL, 
          (LPCTSTR) lpMsgBuf, 
                    caption,
                    MB_OK | MB_ICONINFORMATION); 
         }
*/
      if (strcmp((C8 *) lpMsgBuf,"Hosed"))
         {
         LocalFree(lpMsgBuf);
         }
      }

public:
   // ---------------------------------------
   // Constructor
   // ---------------------------------------

   SERBLOCK::SERBLOCK(char  *config_text,       // e.g., COM1:baud=115200 parity=N data=8 stop=1
                      char **error_text = NULL)
      {
      //
      // kd5tfd hack to handle comm ports > 9
      // see http://support.microsoft.com/default.aspx?scid=kb;%5BLN%5D;115831 for the reasons for
      // the bizarre comm port syntax
      // old code: strcpy(device, config_text);
      //

      strcpy(device, "\\\\.\\");
      strcat(device, config_text);

      char *colon_separator = strchr(device,':');

      if (colon_separator == NULL)
         {
         //
         // Generate a default setup string if one is not provided
         // (the actual parameters don't matter for virtual COM ports)
         //

         strcpy(setup_string,"baud=115200 parity=N data=8 stop=1");
         }
      else
         {
         *colon_separator = 0;
         colon_separator++;

         while (isspace(*colon_separator))
            {
            colon_separator++;
            }

         strcpy(setup_string, colon_separator);
         }

      hPort = INVALID_HANDLE_VALUE;
      open_port(error_text);
      }

   // ---------------------------------------
   // Destructor
   // ---------------------------------------

   virtual SERBLOCK::~SERBLOCK()
      {
      close_port();
      }

   // ---------------------------------------
   // Send a buffer
   // ---------------------------------------

   virtual bool send (unsigned char *buffer, 
                      int            len     = -1,
                      int            timeout = INFINITE)
      {
      if (len == -1)
         {
         len = strlen((char *) buffer);
         }

      HANDLE evWriter = CreateEvent(NULL, TRUE, FALSE, NULL); 

      OVERLAPPED ovWriter;                          
      ZeroMemory(&ovWriter, sizeof(ovWriter));
      ovWriter.hEvent = evWriter;

      bool fRes = FALSE;
      DWORD sent = 0;

      if (WriteFile(hPort, 
                    buffer,
                    len,
                   &sent,
                   &ovWriter))
         {
         fRes = TRUE;
         }
      else
         {
         if (GetLastError() != ERROR_IO_PENDING)
            {
            show_last_error(NULL, "WriteFile");
            }
         else
            {
            DWORD dwRes = WaitForSingleObject(evWriter, timeout);

            switch (dwRes)
               {
               case WAIT_OBJECT_0:
                  {
                  if (GetOverlappedResult(hPort, 
                                         &ovWriter,
                                         &sent,
                                          FALSE))
                     {
                     fRes = TRUE;
                     }
                  break;
                  }
               }
            }
         }

      if (!fRes)
         {
         PurgeComm(hPort, PURGE_TXABORT);
         WaitForSingleObject(evWriter, INFINITE);
         }

      CloseHandle(evWriter);

      return fRes;
      }

   // ---------------------------------------
   // Receive a buffer of up to MAX_BLK_LEN bytes, supporting a variety
   // of termination conditions
   // ---------------------------------------

   virtual unsigned char * receive(int          expected_len,      // # of bytes expected (use -1 for timeout or EOS termination only)
                                   int          EOS_char,          // Terminate when this character received (if not -1)
                                   int          timeout_msec,      // Allow this much total time for transfer to finish (if > 0)
                                   int          dropout_msec,      // Terminate after this much time elapses between bytes
                                   SRPROGRESSCB progress_callback, // Give app the chance to abort a lengthy read in progress
                                   int         *actual_cnt,        // Write actual # of received bytes here (if not NULL) 
                                   TERM_REASON *term_reason)       // Termination reason stored here (if not NULL)
      {
      HANDLE evReader = CreateEvent(NULL, TRUE, FALSE, NULL); 

      OVERLAPPED ovReader;                          
      ZeroMemory(&ovReader, sizeof(ovReader));
      ovReader.hEvent = evReader;

      ResetEvent(evReader);

      int start_time = timeGetTime();

      bool request_data = TRUE;
      bool data_available = FALSE;
      bool waiting_for_completion = FALSE;

      assert(dropout_msec != -1);         

      static unsigned char incoming_buffer[RECV_GRANULARITY];
      static unsigned char received_data  [MAX_BLK_LEN];
      int received_data_len = 0;

      if (actual_cnt != NULL)
         {
         *actual_cnt = 0;
         }

      //
      // State machine handles read requests a byte at a time
      //

      TERM_REASON reason            = SR_IN_PROGRESS;
      int         last_receive_time = start_time;

      for (;;)
         {
         int cur_time = timeGetTime();

         //
         // Check for timeout of entire read operation
         //

         int elapsed = cur_time - start_time;

         if ((timeout_msec > 0) && (elapsed > timeout_msec))
            {
            reason = (received_data_len != 0) ? SR_DROPOUT : SR_TIMEOUT;
            break;                        
            }

         //
         // Check for (typically shorter) dropout-interval expiration
         //

         if (received_data_len != 0)
            {
            elapsed = cur_time - last_receive_time;

            if (elapsed > dropout_msec)
               {
               reason = SR_DROPOUT;
               break;
               }
            }

         //
         // See if we need to issue another async-read operation
         //

         if (request_data)
            {
            request_data = FALSE;

            DWORD rx_bytes_read = 0;

            if (ReadFile(hPort,          
               (void *) &incoming_buffer,
                         RECV_GRANULARITY,
                        &rx_bytes_read,  
                        &ovReader))
               {                          
               if (rx_bytes_read == 0)    // u-Blox VCP does this for some reason, possibly due to invalid port timeout defaults?
                  {
                  waiting_for_completion = FALSE;
                  data_available         = FALSE;
                  }
               else
                  {
                  assert(rx_bytes_read == RECV_GRANULARITY);

                  waiting_for_completion = FALSE;
                  data_available         = TRUE;
                  }
               }
            else
               {
               if (GetLastError() == ERROR_IO_PENDING)
                  {
                  waiting_for_completion = TRUE;
                  data_available         = FALSE;
                  }
               else
                  {
                  show_last_error(NULL, "ReadFile");

                  reason = SR_ERROR;
                  break;
                  }
               }
            }

         if (waiting_for_completion)
            {
            if (progress_callback != NULL)
               {
               if (!progress_callback())
                  {
                  reason = SR_USER_ABORT;
                  break;
                  }
               }

            DWORD result = WaitForSingleObject(evReader, dropout_msec);

            if (result == WAIT_TIMEOUT)
               {
               if (received_data_len != 0)
                  {
                  //
                  // Timed out after at least some valid data received
                  // (otherwise, we ignore the dropout expiration and keep waiting)
                  //

                  reason = SR_DROPOUT;
                  break;   
                  }
               }
            else if (result == WAIT_OBJECT_0)
               {
               int success = GetOverlappedResult(hPort,   
                                                &ovReader,
                                                &result,  
                                                 FALSE);
               ResetEvent(evReader);

               if (!success)
                  {
                  show_last_error(NULL, "GetOverlappedResult");

                  reason = SR_ERROR;
                  break;
                  }
               else if (result == RECV_GRANULARITY)
                  {
//                  assert(result == RECV_GRANULARITY); TODO: Fires w/Prolific GPS, wtf?

                  waiting_for_completion = FALSE;
                  data_available         = TRUE;
                  }
               }
            }

         if (data_available)
            {
            data_available    = FALSE;
            last_receive_time = timeGetTime();

            char received_byte = incoming_buffer[0];  

            received_data[received_data_len++] = received_byte; 

            if (actual_cnt != NULL)
               {
               *actual_cnt = received_data_len;
               }

            if ((EOS_char != -1) && (received_byte == (char) EOS_char))
               {
               //
               // EOS character received
               //

               reason = SR_EOS;
               break;
               }

            if (received_data_len >= MAX_BLK_LEN)
               {
               //
               // Internal data buffer full
               //

               reason = SR_OVERFLOW;
               break;
               }

            if ((expected_len != -1) && (received_data_len >= expected_len))
               {
               //
               // All expected bytes received
               //

               reason = SR_REQUEST_FULFILLED;
               break;
               }

            request_data = TRUE;
            }
         }

      //
      // Cancel any read request that's still in progress before returning
      //
      // We use PurgeComm() in preference to CancelIo() because the latter
      // doesn't work on non-WDM drivers...
      //

      if (waiting_for_completion)
         {
         PurgeComm(hPort, PURGE_RXABORT);
         WaitForSingleObject(evReader, INFINITE);
         }

      if (term_reason != NULL)
         {
         *term_reason = reason;
         }

      CloseHandle(evReader);
      return received_data;
      }
};

//---------------------------------------------------------------------------------
// FTDI2XX
//---------------------------------------------------------------------------------

#ifndef NO_FTDI
#include "ftd2xx.h"

class FTDBLOCK : public COMBLOCK
{
   char   device[MAX_PATH];
   HANDLE hPort;
   int    overlapped;

   void open_port(char **error_text)
      {
      if (hPort != INVALID_HANDLE_VALUE)
         {
         return;
         }

      //
      // Open the port
      //

      hPort = FT_W32_CreateFile(my_A2WS(device).c_str(),
                                GENERIC_READ | GENERIC_WRITE, 
                                0,
                                NULL,
                                OPEN_EXISTING, 
                               (FILE_FLAG_OVERLAPPED * (overlapped != 0)) | FT_OPEN_BY_SERIAL_NUMBER, 
                                0);

      if (hPort == INVALID_HANDLE_VALUE) 
         {
         if (error_text != NULL)
            {
            *error_text = "Device unavailable or in use";
            return;
            }

         show_last_error("FT_W32_CreateFile error: Device unavailable or in use");
         exit(1);
         }
      }

   void close_port(void)
      {
      if (hPort == INVALID_HANDLE_VALUE)
         {
         return;
         }

      if (!FT_W32_CloseHandle(hPort))
         {
         show_last_error("FT_W32_CloseHandle");
         }

      hPort = INVALID_HANDLE_VALUE;
      }

   // ---------------------------------------
   // Error diags
   // ---------------------------------------

   void show_last_error(char *caption = NULL, ...)
      {
      LPVOID lpMsgBuf = "Hosed";       // Default message for Win9x (FormatMessage() is NT-only)

      FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS, 
                    NULL, 
                    FT_W32_GetLastError(hPort), 
                    0,
           (LPTSTR) &lpMsgBuf, 
                    0, 
                    NULL);

      if (caption == NULL)
         {
         caption = "Error";
         }
      else
         {
         static char work_string[4096];

         va_list ap;

         va_start(ap, 
                  caption);

         vsprintf(work_string, 
                  caption, 
                  ap);

         va_end  (ap);

         caption = work_string;
         }

      //
      // Change 'file' references to 'port's
      // 

      for (;;)
         {
         char *fix_error_text = strstr((char *) lpMsgBuf,"file");

         if (fix_error_text == NULL)
            {
            break;
            }

         fix_error_text[0] = 'p';
         fix_error_text[1] = 'o';
         fix_error_text[2] = 'r';
         fix_error_text[3] = 't';
         }

      MessageBox(NULL, 
       (LPCTSTR) lpMsgBuf, 
                 my_A2WS(caption).c_str(),
                 MB_OK | MB_ICONINFORMATION); 

      if (strcmp((C8 *) lpMsgBuf,"Hosed"))
         {
         LocalFree(lpMsgBuf);
         }
      }

public:
   // ---------------------------------------
   // Constructor
   // ---------------------------------------

   FTDBLOCK::FTDBLOCK(char  *config_text,       // FTD2XX serial number identifier
                      char **error_text = NULL,     
                      int   _overlapped = FALSE)
      {
      strcpy(device, config_text); 
      overlapped = _overlapped;

      hPort = INVALID_HANDLE_VALUE;
      open_port(error_text);
      }

   // ---------------------------------------
   // Destructor
   // ---------------------------------------

   virtual FTDBLOCK::~FTDBLOCK()
      {
      close_port();
      }

   // ---------------------------------------
   // Send a buffer
   // ---------------------------------------

   virtual bool send (unsigned char *buffer, 
                      int            len     = -1,
                      int            timeout = INFINITE)
      {
      if (len == -1)
         {
         len = strlen((char *) buffer);
         }

      bool  fRes = FALSE;
      DWORD sent = 0;

      if (!overlapped)
         {
         fRes = FT_W32_WriteFile(hPort, 
                                 buffer,
                                 len,
                                &sent,
                                 NULL) != 0;

         if (fRes && (sent < (DWORD) len))
            {
            return FALSE;
            }

         return fRes;
         }

      HANDLE evWriter = CreateEvent(NULL, TRUE, FALSE, NULL); 

      OVERLAPPED ovWriter;                          
      ZeroMemory(&ovWriter, sizeof(ovWriter));
      ovWriter.hEvent = evWriter;

      if (FT_W32_WriteFile(hPort, 
                           buffer,
                           len,
                          &sent,
                          &ovWriter))
         {
         fRes = TRUE;
         }
      else
         {
         if (FT_W32_GetLastError(hPort) != ERROR_IO_PENDING)
            {
            show_last_error("FT_W32_WriteFile");
            }
         else
            {
            DWORD dwRes = WaitForSingleObject(evWriter, timeout);

            switch (dwRes)
               {
               case WAIT_OBJECT_0:
                  {
                  if (FT_W32_GetOverlappedResult(hPort, 
                                                &ovWriter,
                                                &sent,
                                                 FALSE))
                     {
                     fRes = TRUE;
                     }
                  break;
                  }
               }
            }
         }

      if (!fRes)
         {
         FT_W32_PurgeComm(hPort, PURGE_TXABORT);
         WaitForSingleObject(evWriter, INFINITE);
         }

      CloseHandle(evWriter);

      return fRes;
      }

   // ---------------------------------------
   // Receive a buffer of up to MAX_BLK_LEN bytes, supporting a variety
   // of termination conditions
   // ---------------------------------------

   virtual unsigned char * receive(int          expected_len,      // # of bytes expected (use -1 for timeout or EOS termination only)
                                   int          EOS_char,          // Terminate when this character received (if not -1)
                                   int          timeout_msec,      // Allow this much total time for transfer to finish (if > 0)
                                   int          dropout_msec,      // Terminate after this much time elapses between bytes
                                   SRPROGRESSCB progress_callback, // Give app the chance to abort a lengthy read in progress
                                   int         *actual_cnt,        // Write actual # of received bytes here (if not NULL) 
                                   TERM_REASON *term_reason)       // Termination reason stored here (if not NULL)
      {
      static unsigned char received_data[MAX_BLK_LEN];
      int received_data_len = 0;

      if (!overlapped)
         {
         assert(expected_len != -1);                     // (mandatory for non-overlapped reads)

         bool fRes = FT_W32_ReadFile(hPort,          
                           (void *) &received_data,
                                     expected_len,
                          (DWORD *) &received_data_len,  
                                     NULL) != 0;
         if (!fRes)
            {
            return NULL;
            }

         if (received_data_len < expected_len)
            {
            return NULL;
            }

         return received_data;
         }

      HANDLE evReader = CreateEvent(NULL, TRUE, FALSE, NULL); 

      OVERLAPPED ovReader;                          
      ZeroMemory(&ovReader, sizeof(ovReader));
      ovReader.hEvent = evReader;

      ResetEvent(evReader);

      int start_time = timeGetTime();

      bool request_data = TRUE;
      bool data_available = FALSE;
      bool waiting_for_completion = FALSE;

      assert(dropout_msec != -1);         

      static char incoming_buffer[RECV_GRANULARITY];

      if (actual_cnt != NULL)
         {
         *actual_cnt = 0;
         }

      //
      // State machine handles read requests a byte at a time
      //

      TERM_REASON reason            = SR_IN_PROGRESS;
      int         last_receive_time = start_time;

      for (;;)
         {
         int cur_time = timeGetTime();

         //
         // Check for timeout of entire read operation
         //

         int elapsed = cur_time - start_time;

         if ((timeout_msec > 0) && (elapsed > timeout_msec))
            {
            reason = (received_data_len != 0) ? SR_DROPOUT : SR_TIMEOUT;
            break;                        
            }

         //
         // Check for (typically shorter) dropout-interval expiration
         //

         if (received_data_len != 0)
            {
            elapsed = cur_time - last_receive_time;

            if (elapsed > dropout_msec)
               {
               reason = SR_DROPOUT;
               break;
               }
            }

         //
         // See if we need to issue another async-read operation
         //

         if (request_data)
            {
            request_data = FALSE;

            DWORD rx_bytes_read = 0;

            if (FT_W32_ReadFile(hPort,          
                      (void *) &incoming_buffer,
                                RECV_GRANULARITY,
                               &rx_bytes_read,  
                               &ovReader))
               {                          
               assert(rx_bytes_read == RECV_GRANULARITY);

               waiting_for_completion = FALSE;
               data_available         = TRUE;
               }
            else
               {
               if (FT_W32_GetLastError(hPort) == ERROR_IO_PENDING)
                  {
                  waiting_for_completion = TRUE;
                  data_available         = FALSE;
                  }
               else
                  {
                  show_last_error("FT_W32_ReadFile");

                  reason = SR_ERROR;
                  break;
                  }
               }
            }

         if (waiting_for_completion)
            {
            if (progress_callback != NULL)
               {
               if (!progress_callback())
                  {
                  reason = SR_USER_ABORT;
                  break;
                  }
               }

            DWORD result = WaitForSingleObject(evReader, dropout_msec);

            if (result == WAIT_TIMEOUT)
               {
               if (received_data_len != 0)
                  {
                  //
                  // Timed out after at least some valid data received
                  // (otherwise, we ignore the dropout expiration and keep waiting)
                  //

                  reason = SR_DROPOUT;
                  break;   
                  }
               }
            else if (result == WAIT_OBJECT_0)
               {
               int success = FT_W32_GetOverlappedResult(hPort,   
                                                       &ovReader,
                                                       &result,  
                                                        FALSE);
               ResetEvent(evReader);

               if (!success)
                  {
                  show_last_error("GetOverlappedResult");

                  reason = SR_ERROR;
                  break;
                  }
               else
                  {
                  assert(result == RECV_GRANULARITY);

                  waiting_for_completion = FALSE;
                  data_available         = TRUE;
                  }
               }
            }

         if (data_available)
            {
            data_available    = FALSE;
            last_receive_time = timeGetTime();

            char received_byte = incoming_buffer[0];  

            received_data[received_data_len++] = received_byte; 

            if (actual_cnt != NULL)
               {
               *actual_cnt = received_data_len;
               }

            if ((EOS_char != -1) && (received_byte == (char) EOS_char))
               {
               //
               // EOS character received
               //

               reason = SR_EOS;
               break;
               }

            if (received_data_len >= MAX_BLK_LEN)
               {
               //
               // Internal data buffer full
               //

               reason = SR_OVERFLOW;
               break;
               }

            if ((expected_len != -1) && (received_data_len >= expected_len))
               {
               //
               // All expected bytes received
               //

               reason = SR_REQUEST_FULFILLED;
               break;
               }

            request_data = TRUE;
            }
         }

      //
      // Cancel any read request that's still in progress before returning
      //

      if (waiting_for_completion)
         {
         FT_W32_PurgeComm(hPort, PURGE_RXABORT);
         WaitForSingleObject(evReader, INFINITE);
         }

      if (term_reason != NULL)
         {
         *term_reason = reason;
         }

      CloseHandle(evReader);
      return received_data;
      }
};
#endif

//---------------------------------------------------------------------------------
// TCP/IP               
//---------------------------------------------------------------------------------

#include <winsock2.h>
#include <ws2tcpip.h>
#include <windows.h>
#include <mswsock.h>

class TCPBLOCK : public COMBLOCK
{
   char server_address_name[MAX_PATH];
   int  server_port_num;
   WSADATA wsadata;

   SOCKET      server_connection;
   sockaddr_in server_addr;

   unsigned char WS_buffer[137];      // (used to reduce number of recv() calls for
   int           WS_buffer_ptr;       // improved performance; prime # of bytes seems to improve GPIB-LAN
   int           WS_buffer_len;       // reliability when saving .S2P files?)

   void open_port(char **error_text)
      {
      if (server_connection != NULL)
         {
         return;
         }

      WORD wRequestVer = MAKEWORD(2,2);

      if (WSAStartup(wRequestVer, &wsadata))
         {
         if (error_text != NULL)
            {
            *error_text = "Couldn't open WinSock";
            return;
            }

         show_last_error("Couldn't open WinSock");
         exit(1);
         }

      char buf[MAX_PATH];

      if (gethostname(buf,MAX_PATH-1) == SOCKET_ERROR)
         {
         WSACleanup();

         if (error_text != NULL)
            {
            *error_text = "(Client name unobtainable)";
            return;
            }

         show_last_error("(Client name unobtainable)");
         exit(1);
         }

      LPHOSTENT lphp;
      struct in_addr inaddrIP;

      lphp = gethostbyname(buf);
      inaddrIP = *(struct in_addr*) (lphp->h_addr);

      char ipnum[MAX_PATH];

      strcpy(ipnum,inet_ntoa(inaddrIP));

      fprintf(stderr,"\nClient \"%s\", address %s, Windows Sockets V%d.%d (%s)\n",
         buf,
         ipnum,
         HIBYTE(wsadata.wVersion),
         LOBYTE(wsadata.wVersion),
         wsadata.szDescription);

      server_connection = socket(PF_INET, SOCK_STREAM, 0);

      if (server_connection == INVALID_SOCKET)
         {
         WSACleanup();

         if (error_text != NULL)
            {
            *error_text = "Bad socket!";
            return;
            }

         show_last_error("Bad socket!");
         exit(1);
         }

      memset(&server_addr,0,sizeof(server_addr));

      server_addr.sin_family      = PF_INET;
      server_addr.sin_port        = htons(server_port_num);

      DWORD li = inet_addr(server_address_name);

      if (li == INADDR_NONE)
         {
         HOSTENT *hostinfo = gethostbyname(server_address_name);

         if (hostinfo == NULL)
            {
            if (error_text != NULL)
               {
               *error_text = "Unable to resolve server name";
               close_port();
               return;
               }

            show_last_error("Unable to resolve server name, WSA code %d",WSAGetLastError());
            close_port();
            exit(1);
            }

         memcpy(&server_addr.sin_addr, hostinfo->h_addr, hostinfo->h_length);
         }
      else
         {
         server_addr.sin_addr.s_addr = li;
         }

// server_addr.sin_addr.S_un.S_un_b.s_b1++;     // (Connection error test)

      int result = connect(server_connection,
             (sockaddr *) &server_addr,
                           sizeof(server_addr));
      if (result)
         {
         if (error_text != NULL)
            {
            // show_last_error("Unable to connect to server, WSA code %d",WSAGetLastError());
            *error_text = "Unable to connect to server";
            close_port();
            return;
            }

         show_last_error("Unable to connect to server, WSA code %d",WSAGetLastError());
         close_port();
         exit(1);
         }

      DWORD dwVal = 1;

      setsockopt(server_connection,    // Turn off Nagle algorithm
                 IPPROTO_TCP,
                 TCP_NODELAY,
       (char *) &dwVal,
                 sizeof(dwVal));

//      DWORD recv_size = 1024*1024;
//
//      setsockopt(server_connection,
//                 SOL_SOCKET,
//                 SO_RCVBUF,
//         (C8 *) &recv_size,
//                 sizeof(recv_size));

      ioctlsocket(server_connection,   // Use non-blocking I/O
                  FIONBIO,
                 &dwVal);

      fprintf(stderr,"Connected to server %s:%d\n\n",
              inet_ntoa(server_addr.sin_addr),
              ntohs    (server_addr.sin_port));
      }

   void close_port(void)
      {
      if (server_connection == NULL)
         {
         return;
         }

      closesocket(server_connection);
      server_connection = NULL;

      WSACleanup();
      }

   // ---------------------------------------
   // Error diags
   // ---------------------------------------

   static void show_last_error(char *caption = NULL, ...)
      {
      LPVOID lpMsgBuf = "Hosed";       // Default message for Win9x (FormatMessage() is NT-only)

      FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS, 
                    NULL, 
                    GetLastError(), 
                    0,
           (LPTSTR) &lpMsgBuf, 
                    0, 
                    NULL);

      if (caption == NULL)
         {
         caption = "Error";
         }
      else
         {
         static char work_string[4096];

         va_list ap;

         va_start(ap, 
                  caption);

         vsprintf(work_string, 
                  caption, 
                  ap);

         va_end  (ap);

         caption = work_string;
         }

      //
      // Change 'file' references to 'port's
      // 

      for (;;)
         {
         char *fix_error_text = strstr((char *) lpMsgBuf,"file");

         if (fix_error_text == NULL)
            {
            break;
            }

         fix_error_text[0] = 'p';
         fix_error_text[1] = 'o';
         fix_error_text[2] = 'r';
         fix_error_text[3] = 't';
         }

      MessageBox(NULL, 
       (LPCTSTR) lpMsgBuf, 
		  my_A2WS(caption).c_str(),
                 MB_OK | MB_ICONINFORMATION); 

      if (strcmp((C8 *) lpMsgBuf,"Hosed"))
         {
         LocalFree(lpMsgBuf);
         }
      }

   int NET_receive_traffic(unsigned char *dest, 
                           int            size,
                           int           *WSA_error)
      {
      int index = 0;
   
      //
      // Get as much data as is currently available, up to specified size
      //
   
      while (index < size)
         {
         int amount = recv(server_connection,
                 (char *) &dest[index],
                           size - index,
                           0);
   
         if (amount == 0)
            {
            //
            // Connection has been closed, return failure
            //
   
            *WSA_error = WSAGetLastError();
   
            return -2;
            }
   
         if (amount == SOCKET_ERROR)
            {
            //
            // No (more) data available
            //
   
            *WSA_error = WSAGetLastError();
   
            if (*WSA_error == WSAEWOULDBLOCK)
               {
               //
               // This will be 0 if no data was available at all... else the
               // number of bytes received before starvation
               //
   
               return index;
               }
   
            //
            // Probably WSAECONNRESET or a similar error...
            //
   
            return -1;
            }
   
         index += amount;
   
         if (index < size)
            {
            //
            // If more data expected, continue polling
            //
   
            Sleep(0);
            }
         }
   
      //
      // Return success (request fulfilled)
      //
   
      return index;
      }

   int NET_receive_byte(unsigned char *dest,
                        int           *WSA_error)
      {
      for (;;)
         {
         if (WS_buffer_ptr < WS_buffer_len)
            {
            *dest = WS_buffer[WS_buffer_ptr++];
            return 1;
            }

         WS_buffer_len = 0;
         WS_buffer_ptr = 0;

         int result = NET_receive_traffic(WS_buffer,
                                          sizeof(WS_buffer),
                                          WSA_error);

         if (result <= 0)
            {
            return result;    // either closed, reset, or no data available
            }

         WS_buffer_len = result;
         }
      }

public:
   // ---------------------------------------
   // Constructor
   // ---------------------------------------

   TCPBLOCK::TCPBLOCK(char  *address_name,            // Alphanumeric IP string
                      char **error_text       = NULL,
                      int    default_port_num = 1234) // (Prologix GPIB-LAN adapter, if not overridden in address_name)
      {
      strcpy(server_address_name,address_name);

      char *colon = strrchr(server_address_name,':');

      if (colon == NULL)
         {
         server_port_num = default_port_num;
         }
      else
         {
         *colon = 0;
         server_port_num = atoi(&colon[1]);
         }                                 

      server_connection = NULL;
      open_port(error_text);

      WS_buffer_ptr = 0;
      WS_buffer_len = 0;
      }

   // ---------------------------------------
   // Destructor
   // ---------------------------------------

   virtual TCPBLOCK::~TCPBLOCK()
      {
      close_port();
      }

   virtual bool send (unsigned char *buffer, 
                      int            len     = -1,
                      int            timeout = INFINITE)
      {
      int n_chars = (len != -1) ? len : strlen((char *) buffer);

      int start_time = timeGetTime();

      for (;;)
         {
         int cur_time = timeGetTime();

         int elapsed = cur_time - start_time;
   
         if ((timeout != INFINITE) && (elapsed > timeout))
            {
            return FALSE;
            }

         int result = ::send(server_connection,
                    (char *) buffer,
                             n_chars,
                             0);

         if (result != SOCKET_ERROR)
            {
            return TRUE;
            }

         S32 WSA_error = WSAGetLastError();

         if (WSA_error != WSAEWOULDBLOCK)
            {
            show_last_error("Connection was closed by remote host (WSA code=%d)",WSA_error);
            return FALSE;
            }

         Sleep(0);
         }

      return TRUE;
      }

   virtual unsigned char *receive(int          expected_len,      // # of bytes expected (use -1 for timeout or EOS termination only)
                                  int          EOS_char,          // Terminate when this character received (if not -1)
                                  int          timeout_msec,      // Allow this much total time for transfer to finish (if > 0)
                                  int          dropout_msec,      // Terminate after this much time elapses between bytes
                                  SRPROGRESSCB progress_callback, // Give app the chance to abort a lengthy read in progress
                                  int         *actual_cnt,        // Write actual # of received bytes here (if not NULL) 
                                  TERM_REASON *term_reason)       // Termination reason stored here (if not NULL)
      {
      int start_time = timeGetTime();
   
      bool request_data = TRUE;
      bool data_available = FALSE;
      bool waiting_for_completion = FALSE;
   
      assert(dropout_msec != -1);
      
      static unsigned char incoming_buffer[RECV_GRANULARITY];
      static unsigned char received_data  [MAX_BLK_LEN];
      int received_data_len = 0;
   
      if (actual_cnt != NULL)
         {
         *actual_cnt = 0;
         }
   
      //
      // State machine handles read requests a byte at a time
      //
   
      TERM_REASON reason            = SR_IN_PROGRESS;
      int         last_receive_time = start_time;
   
      for (;;)
         {
         int cur_time = timeGetTime();
   
         //
         // Check for timeout of entire read operation
         //
   
         int elapsed = cur_time - start_time;
   
         if ((timeout_msec > 0) && (elapsed > timeout_msec))
            {
            reason = (received_data_len != 0) ? SR_DROPOUT : SR_TIMEOUT;
            break;                        
            }
   
         //
         // Check for (typically shorter) dropout-interval expiration
         //
   
         if (received_data_len != 0)
            {
            elapsed = cur_time - last_receive_time;
   
            if (elapsed > dropout_msec)
               {
               reason = SR_DROPOUT;
               break;
               }
            }
   
         //
         // See if we need to issue another synchronous read
         //
   
         if (request_data || waiting_for_completion)
            {
            request_data = FALSE;
   
            int WSA_error = 0;
   
            int nr = NET_receive_byte(incoming_buffer,
                                     &WSA_error);
            if (nr == 1)
               {
               waiting_for_completion = FALSE;
               data_available         = TRUE;
               }
            else if (nr == 0) 
               {
               waiting_for_completion = TRUE;
               data_available         = FALSE;
   
               if (progress_callback != NULL)
                  {
                  if (!progress_callback())
                     {
                     reason = SR_USER_ABORT;
                     break;
                     }
                  }
   
               Sleep(0);
               }
            else
               {
               if (nr == -2)
                  {
                  show_last_error("Connection was closed by remote host (WSA code=%d)",WSA_error);
                  reason = SR_DISCONNECTED;
                  }
               else
                  {
                  show_last_error("ReadFile error, result=%d, WSA code=%d",nr,WSA_error);
                  reason = SR_ERROR;
                  }

               break;
               }
            }
   
         if (data_available)
            {
            data_available    = FALSE;
            last_receive_time = timeGetTime();
   
            char received_byte = incoming_buffer[0];  
   
            received_data[received_data_len++] = received_byte; 
   
            if (actual_cnt != NULL)
               {
               *actual_cnt = received_data_len;
               }
   
            if ((EOS_char != -1) && (received_byte == (char) EOS_char))
               {
               //
               // EOS character received
               //
   
               reason = SR_EOS;
               break;
               }
   
            if (received_data_len >= MAX_BLK_LEN)
               {
               //
               // Internal data buffer full
               //
   
               reason = SR_OVERFLOW;
               break;
               }
   
            if ((expected_len != -1) && (received_data_len >= expected_len))
               {
               //
               // All expected bytes received
               //
   
               reason = SR_REQUEST_FULFILLED;
               break;
               }
   
            request_data = TRUE;
            }
         }
   
      if (term_reason != NULL)
         {
         *term_reason = reason;
         }
   
      return received_data;
      }

   virtual S32 act_as_bridge(COMBLOCK *local /* , BRIDGESTATUSCB callback */)
      {
      //
      // Create TCP/IP monitor port to hand off connections
      // Run bridge server
      //    Wait 10 ms for up to 128 bytes from client
      //    Send to local
      //    Wait 10 ms for up to 128 bytes from local
      //    Send to client
      //    New connections kill existing ones
      //      Before accepting new connection, flush local receive buffer
      //      (close/reopen local connection? no, we don't know how, local
      //      must already be open when we're called)
      //
      // Probably should create this as a separate class with a pump function
      //

      return 0;
      }
};
