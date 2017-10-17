/*****************************************************************************
 * Refer to the language interface documentation for details on
 * which header and .obj files to include in your project.
 *****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <dos.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include <assert.h>
#include <float.h>

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <process.h>
#include <mmsystem.h>
#include <windowsx.h>
#include <setupapi.h>

//msavic
//#define BUILDING_GPIBLIB

#include "gpiblib.h"

#include "decl-32.h"

#define SERIAL_CONTROL_MODE 0
#include "comblock.h"

// *****************************************************************************
//
// Misc. Windows file utilities
//
// *****************************************************************************

//
// Automatically generate tempfile pathname, optionally open the file, and ensure file is 
// closed/deleted when it goes out of scope
//
// Command-line utilities should use TEMPFNs or TEMPFILEs instead of calling GetTempFileName() directly, to ensure
// they're well-behaved in a (possibly concurrent) batch job.  Just declare a TEMPFILE with an 
// optional suffix param for the generated filename, and access the filename with .name.
//
// To take advantage of automatic cleanup, don't call exit() while TEMPFNs are on the stack!
//

enum TFMSGLVL
{
   TF_DEBUG = 0,  // Debugging traffic
   TF_VERBOSE,    // Low-level notice
   TF_NOTICE,     // Standard notice
   TF_WARNING,    // Warning
   TF_ERROR       // Error
};

struct TEMPFN
{
   C8   path_buffer        [MAX_PATH-32];   // leave some room for 8.3 tempname and user-supplied suffix if any
   C8   original_temp_name [MAX_PATH-32];   // e.g., c:\temp\TF43AE.tmp
   C8   name               [MAX_PATH];      // e.g., c:\temp\TF43AE.tmp.wav (if .wav was passed as suffix)
   bool keep;
   bool show;
   bool active;

   virtual void message_sink(TFMSGLVL level,   
                             C8      *text)
      {
      ::printf("%s\n",text);
      }

   virtual void message_printf(TFMSGLVL level,
                               C8 *fmt,
                               ...)
      {
      C8 buffer[4096];

      va_list ap;

      va_start(ap, 
               fmt);

      memset(buffer, 0, sizeof(buffer));

      _vsnprintf(buffer,
                 sizeof(buffer)-1,
                 fmt,
                 ap);

      va_end(ap);

      //
      // Remove trailing whitespace
      //

      C8 *end = &buffer[strlen(buffer)-1];

      while (end > buffer)
         {
         if (!isspace((U8) *end)) 
            {
            break;
            }

         *end = 0;
         end--;
         }

      message_sink(level,
                   buffer);
      }

   TEMPFN(C8 *suffix = NULL, bool keep_files=FALSE)
      {
      keep = keep_files;
      active = TRUE;

      path_buffer[0]        = 0;
      original_temp_name[0] = 0;
      name[0]               = 0;

      if (!GetTempPathA(sizeof(path_buffer)-1,
                       path_buffer))
         {
         message_printf(TF_ERROR, "TEMPFN: GetTempPath() failed, code 0x%X",GetLastError());
         active = FALSE;
         return;
         }

      if (!GetTempFileNameA(path_buffer,
                          "TF",
                           0,
                           original_temp_name))
         {
         message_printf(TF_ERROR, "TEMPFN: GetTempFileName() failed, code 0x%X",GetLastError());
         active = FALSE;
         return;
         }

      strcpy(name, original_temp_name);

      if (suffix == NULL)
         {
         //
         // No suffix was provided, caller will use the tempfile the OS gave us
         // 

         original_temp_name[0] = 0;       
         }
      else
         {
         //
         // A suffix was provided: the caller will create *another* tempfile whose name 
         // will begin with the guaranteed-unique name of the first one.  This file also
         // must be cleaned up
         //

         strncat(name, suffix, 15); 
         }

      message_printf(TF_VERBOSE, "TEMPFN: original_temp_name: %s",original_temp_name);
      message_printf(TF_VERBOSE, "TEMPFN: name: %s",name);
      }

   virtual ~TEMPFN()           
      {                  
      //
      // Ensure that both the original tempfile and the user-extended version (if any)  
      // are cleaned up at end of scope                                                 
      //

      if (!keep)
         {
         if (original_temp_name[0])
            {
            message_printf(TF_VERBOSE, "TEMPFN: Deleting %s",original_temp_name);
            _unlink(original_temp_name);
            original_temp_name[0] = 0;
            }

         if (name[0])
            {
            message_printf(TF_VERBOSE, "TEMPFN: Deleting %s",name);
            _unlink(name);
            name[0] = 0;
            }
         }
      }

   virtual bool status(void)
      {
      return active;
      }
};

struct TEMPFILE : public TEMPFN
{
   FILE *file;

   TEMPFILE(C8  *suffix         = NULL, 
            C8  *file_operation = NULL, 
            bool keep_files     = FALSE) : TEMPFN (suffix, keep_files)  
            
      {
      if (file_operation == NULL)
         {
         file = NULL;
         return;    
         }
      
      file = fopen(name, file_operation);

      if (file == NULL)
         {
         message_printf(TF_ERROR, "TEMPFILE: Couldn't open %s for %s",
            name,
            (tolower((U8) file_operation[0]) == 'r') ? "reading" : "writing");

         active = FALSE;
         return;
         }
      }

   virtual ~TEMPFILE()
      {
      close();
      }

   virtual void close(void)
      {
      if (file != NULL)
         {
         fclose(file);
         file = NULL;
         }
      }
};

//
// Encapsulate various Windows file/directory behavior and policies
//

#include <shlobj.h>

struct APPDIRS
{
   C8 EXE     [MAX_PATH];    // Directory containing .exe corresponding to current process       
   C8 DOCS    [MAX_PATH];    // Directory where user documents are to be loaded/saved by default 
   C8 ICW     [MAX_PATH];    // Current working directory when object was created
   C8 VLDATA  [MAX_PATH];    // Directory for user-specific vendor .INI files and data
   C8 VCDATA  [MAX_PATH];    // Directory for vendor .INI files and data common to all users
   C8 LOCDATA [MAX_PATH];    // Directory for user-specific application data (not good for .INI files unless they're genuinely user-specific)
   C8 COMDATA [MAX_PATH];    // Directory for application .INI files common to all users
   C8 DESKTOP [MAX_PATH];    // User's desktop

   static void trailslash(C8 *target)
      {
      if (target[strlen(target)-1] != '\\')
         {
         strcat(target,"\\");
         }
      }

   APPDIRS()
      {
      EXE    [0] = 0;     
      DOCS   [0] = 0;     
      ICW    [0] = 0;
      VLDATA [0] = 0;
      VCDATA [0] = 0;
      LOCDATA[0] = 0;
      COMDATA[0] = 0;
      DESKTOP[0] = 0;
      }

   bool initialized(void)
      {
      return (EXE[0] != 0);
      }

   void init(C8 *vendor_name=NULL,     // Vendor name that refers to VLDATA and VCDATA subdirectories beneath %localappdata% and %programdata%
             C8 *app_name=NULL)        // App name used to reference LOCDATA and COMDATA subdirectories underneath VLDATA and VCDATA
      {
      //
      // Get CWD and .exe directories
      //

      if (GetCurrentDirectoryA(sizeof(ICW), ICW))
         trailslash(ICW);

      if (!GetModuleFileNameA(NULL, EXE, sizeof(EXE)-1))
         strcpy(EXE,".\\");
      else
         {
         C8 *path = strrchr(EXE,'\\');

         if (path != NULL)
            path[1] = 0;
         else
            strcpy(EXE,".\\");
         }

      //
      // See http://msdn.microsoft.com/en-us/library/ms995853.aspx for data and settings
      // management guidelines.  Vista replaced CSIDL identifiers with GUIDs but the
      // legacy functions are still used for backwards compatibility
      //
      // Furthermore, SHGetSpecialFolderPath() was deprecated in favor of SHGetFolderPath(), 
      // but the latter has various Windows header/macro-definition dependencies, and 
      // there doesn't seem to be any real reason to switch to it
      //
      // Typical paths on WinXP:
      //
      //    CSIDL_PERSONAL          c:\documents and settings\johnm\my documents
      //    CSIDL_DESKTOPDIRECTORY  c:\documents and settings\johnm\desktop
      //
      // Note 3 different application data locations:
      //
      //    CSIDL_LOCAL_APPDATA     c:\documents and settings\johnm\local settings (hidden)\application data
      //    CSIDL_APPDATA           c:\documents and settings\johnm\application data
      //    CSIDL_COMMON_APPDATA    c:\documents and settings\all users\application data (hidden)
      //
      // On Windows 7:
      //
      //    CSIDL_PERSONAL          c:\users\johnm\documents
      //    CSIDL_DESKTOPDIRECTORY  c:\users\johnm\desktop
      //
      //    CSIDL_LOCAL_APPDATA     c:\users\johnm\appdata\local    (%localappdata% in both OS and Inno Setup)
      //    CSIDL_APPDATA           c:\users\johnm\appdata\roaming  (%appdata%)
      //    CSIDL_COMMON_APPDATA    c:\ProgramData                  (%programdata%, or %commonappdata% in Inno Setup)
      //

      C8 local_appdata [MAX_PATH] = "";
      C8 common_appdata[MAX_PATH] = "";
      C8 mydocs        [MAX_PATH] = "";

      SHGetSpecialFolderPathA(HWND_DESKTOP,
                             DESKTOP,
                             CSIDL_DESKTOPDIRECTORY,
                             FALSE);

      SHGetSpecialFolderPathA(HWND_DESKTOP,
                             mydocs,
                             CSIDL_PERSONAL,
                             FALSE);

      SHGetSpecialFolderPathA(HWND_DESKTOP,
                             local_appdata,
                             CSIDL_LOCAL_APPDATA, 
                             FALSE);

      SHGetSpecialFolderPathA(HWND_DESKTOP,
                             common_appdata,
                             CSIDL_COMMON_APPDATA, 
                             FALSE);

      trailslash(DESKTOP);
      trailslash(mydocs);
      trailslash(local_appdata);
      trailslash(common_appdata);

      //
      // Create paths to vendor- and app-specific common data directories
      //
      // These directories are assumed to have been created at install time and
      // are available for all users
      //

      strcpy(VCDATA, common_appdata);

      if ((vendor_name != NULL) && (vendor_name[0] != 0))
         {
         strcat(VCDATA, vendor_name);
         trailslash(VCDATA);
         CreateDirectoryA(VCDATA, NULL);
         }

      strcpy(COMDATA, VCDATA);

      if ((app_name != NULL) && (app_name[0] != 0))
         {
         strcat(COMDATA, app_name);
         trailslash(COMDATA);
         CreateDirectoryA(COMDATA, NULL);
         }

      //
      // Create paths to vendor- and app-specific local data directories,
      // e.g., c:\documents and settings\johnm\local settings\application data\vendor_name\app_name\
      //
      // These directories may not have been created at install time if a different user 
      // (e.g, an administrator) ran the installer
      //

      strcpy(VLDATA, local_appdata);

      if ((vendor_name != NULL) && (vendor_name[0] != 0))
         {
         strcat(VLDATA, vendor_name);
         trailslash(VLDATA);
         CreateDirectoryA(VLDATA, NULL);
         }

      strcpy(LOCDATA, VLDATA);

      if ((app_name != NULL) && (app_name[0] != 0))
         {
         strcat(LOCDATA, app_name);
         trailslash(LOCDATA);
         CreateDirectoryA(LOCDATA, NULL);
         }

      //
      // By default, for development convenience, the docs directory is set
      // to the current working directory.  This also permits use of the "Start In" field
      // in a desktop shortcut.
      //
      // If the CWD is the Windows desktop, contains "Program Files", or could not 
      // be determined, the default docs directory is set to the current user's My Documents folder
      //

      strcpy(DOCS, ICW);

      if ((!strlen(DOCS)) 
           ||
          (!_stricmp(DOCS, DESKTOP)) 
           ||
          (strstr(DOCS,"Program Files") != NULL))
         {
         strcpy(DOCS, mydocs);   

         SetCurrentDirectoryA(DOCS);
         }
      }
};

APPDIRS global_dirs;

S32 Device = 0;                   /* Device unit descriptor                  */
S32 GPIB_ID = -1;                 // Unit descriptor for GPIB_ID

GPIBERR err_handler = NULL;
S32 device_address = -1;
S32 online = 0;
S32 using_connect_ex = 0;

S32 timeout_period_msecs = 100000;

S32 EOS_char = -1;
S32 max_read_len = 0;
S32 serial_dropout_ms = 500;
SRPROGRESSCB serial_progress_cb = NULL;
S32 serial_timeout_ms = 0;

S32 prologix_major_version = 1;
S32 prologix_minor_version = 0;
S32 prologix_letter_version = 0;
S32 prologix_312c = 0;
S32 prologix_V4 = 0;
S32 prologix_440 = 0;
S32 prologix_auto_read_enabled = 1;
S32 prologix_was_auto_read_enabled = 1;
S32 prologix_listen_only_mode = 0;

enum GPTIMEOUT
{
   TIMEOUT_TNONE  = 0,   /* Infinite timeout (disabled)   */
   TIMEOUT_T10us  = 1,   /* Timeout of 10 us (ideal)      */
   TIMEOUT_T30us  = 2,   /* Timeout of 30 us (ideal)      */
   TIMEOUT_T100us = 3,   /* Timeout of 100 us (ideal)     */
   TIMEOUT_T300us = 4,   /* Timeout of 300 us (ideal)     */
   TIMEOUT_T1ms   = 5,   /* Timeout of 1 ms (ideal)       */
   TIMEOUT_T3ms   = 6,   /* Timeout of 3 ms (ideal)       */
   TIMEOUT_T10ms  = 7,   /* Timeout of 10 ms (ideal)      */
   TIMEOUT_T30ms  = 8,   /* Timeout of 30 ms (ideal)      */
   TIMEOUT_T100ms = 9,   /* Timeout of 100 ms (ideal)     */
   TIMEOUT_T300ms =10,   /* Timeout of 300 ms (ideal)     */
   TIMEOUT_T1s    =11,   /* Timeout of 1 s (ideal)        */
   TIMEOUT_T3s    =12,   /* Timeout of 3 s (ideal)        */
   TIMEOUT_T10s   =13,   /* Timeout of 10 s (ideal)       */
   TIMEOUT_T30s   =14,   /* Timeout of 30 s (ideal)       */
   TIMEOUT_T100s  =15,   /* Timeout of 100 s (ideal)      */
   TIMEOUT_T300s  =16,   /* Timeout of 300 s (ideal)      */
   TIMEOUT_T1000s =17    /* Timeout of 1000 s (ideal)     */
};

S32 GPIB_timeout_ms[18] = // Fudged upwards, after National Instruments' example
{
   -1,            // 0
   1,             // 1
   1,             // 2
   1,             // 3
   1,             // 4
   1,             // 5
   4,             // 6
   12,            // 7
   35,            // 8
   120,           // 9
   350,           // 10
   1200,          // 11
   3500,          // 12
   12000,         // 13
   35000,         // 14
   120000,        // 15
   350000,        // 16
   1200000        // 17
};

GPTIMEOUT GPT(S32 ms)
{
   for (S32 i=0; i < 18; i++)
      {
      if (GPIB_timeout_ms[i] >= ms)
         {
         return (GPTIMEOUT) i;
         }
      }

   return TIMEOUT_TNONE;
}

void GpibError(C8 *msg, ...);          /* Error function declaration              */

//
// GPIB connection setup
//

GPIB_CTYPE INI_connection_type = GC_NONE;
C8  INI_setup_string[MAX_PATH] = "";     
S32 INI_is_NI488 = 0;
S32 INI_is_TCP = 0;
S32 INI_is_Prologix = 0;
S32 INI_write_delay_ms = 0;
S32 INI_reset_to_local = 0;
S32 INI_restore_auto_read = 0;
S32 INI_force_auto_read = 1;
HANDLE hCOMSem = NULL;

COMBLOCK *serial_device = NULL;

S32    WINAPI GPIB_online   (void)
{
   if (online)
      {
      GpibError("Only one GPIB connection may be active at a time\n\n");
      return 0;
      }

   //
   // Make sure Prologix.exe isn't running
   //

   HANDLE hPrologixSem = CreateSemaphoreA(NULL,     
                                          0,        
                                          1,        
                                         "Prologix");

   if ((hPrologixSem != NULL) && (GetLastError() == ERROR_ALREADY_EXISTS))
      {
      GpibError("Port in use -- please exit from PROLOGIX.EXE first\n\n");
      return 0;
      }

   if (hPrologixSem != NULL)
      {
      CloseHandle(hPrologixSem);
      hPrologixSem = NULL;
      }

   //
   // Assert ownership of port
   //

   hCOMSem = CreateSemaphoreA(NULL,     
                             0,        
                             1,        
                             INI_setup_string);

   if ((hCOMSem != NULL) && (GetLastError() == ERROR_ALREADY_EXISTS))
      {
      CloseHandle(hCOMSem);
      hCOMSem = NULL;

      GpibError("Port in use -- please exit from all other GPIB Toolkit applications first\n\n");
      return 0;
      }

   //
   // Initialize selected interface
   //

   if (!INI_is_NI488)
      {
      if (INI_is_TCP)
         serial_device = new TCPBLOCK(INI_setup_string);
      else
         serial_device = new SERBLOCK(INI_setup_string);

      // TODO: failure check
      }
   else
      {
      serial_device = NULL;

      S32 BoardIndex = atoi(&INI_setup_string[4]);    // Get interface index from GPIB0...GPIBnn string

      UINT err = SetErrorMode(SEM_NOOPENFILEERRORBOX | SEM_FAILCRITICALERRORS);
      GPIB_ID = ibfindA(INI_setup_string);             // avoid errors due to partial uninstall of old NI drivers
      SetErrorMode(err);

      if (GPIB_ID == -1)
         {
         CloseHandle(hCOMSem);
         hCOMSem = NULL;

         GpibError("National Instruments board (%s) not found\n\n- Are you attempting "
                   "to use a Prologix adapter?  If so, you must run\n"
                   "the PROLOGIX.EXE configurator first, and select \"Update "
                   "CONNECT.INI\" after\nselecting your adapter's address.\n\n"
                   "- Are you running Windows Vista or later versions?  If so, you may\n"
                   "need to mark all GPIB Toolkit applications, including Prologix.exe,\n"
                   "to run in Windows XP compatibility mode with full Administrator\n"
                   "rights. Then, run PROLOGIX.EXE and select \"Update CONNECT.INI\" again.\n\n"
                   "Otherwise, make sure your NI488.2-compatible GPIB adapter is configured\nas %s.\n\nibfind Error\n",
                    INI_setup_string,
                    INI_setup_string); 

         return 0;
         }

#if 0
      int val = -1;
      ibask(GPIB_ID, IbaTMO, &val);
      fprintf(stderr,"IbaTMO = %d\n",val);
      ibask(GPIB_ID, IbaEOT, &val);
      fprintf(stderr,"IbaEOT = %d\n",val);
      ibask(GPIB_ID, IbaCICPROT, &val);
      fprintf(stderr,"IbaCICPROT = %d\n",val);
      ibask(GPIB_ID, IbaEndBitIsNormal, &val);
      fprintf(stderr,"IbaEndBitIsNormal = %d\n",val);
      ibask(GPIB_ID, IbaEOSwrt, &val);
      fprintf(stderr,"IbaEOSwrt = %d\n",val);
      ibask(GPIB_ID, IbaEOSrd, &val);
      fprintf(stderr,"IbaEOSrd = %d\n",val);
      ibask(GPIB_ID, IbaSRE, &val);
      fprintf(stderr,"IbaSRE = %d\n",val);
      ibask(GPIB_ID, IbaEOSchar, &val);
      fprintf(stderr,"IbaEOSchar = %d\n",val);
#endif

      S32 PrimaryAddress = device_address;   /* Primary address of the device           */
      S32 SecondaryAddress = 0;              /* Secondary address of the device         */

      Device = -1;

      if (PrimaryAddress != -1)              // (Device is the board itself)
//         {                                 // (Enabling this breaks NI compatibility...)
//         Device = ibdev(                     /* Create a unit descriptor handle (necessary on ICS but not NI)   */
//               BoardIndex,                   /* Board Index (GPIB0 = 0, GPIB1 = 1, ...) */
//               0,                            /* Device primary address                  */
//               SecondaryAddress,             /* Device secondary address                */
//               GPT(timeout_period_msecs),    /* Timeout setting (T10s = 10 seconds)     */
//               1,                            /* Assert EOI line at end of write         */
//               0);                           /* EOS termination mode                    */
//         }
//      else                                   // (Device is the target instrument)
         {
         Device = ibdev(                     /* Create a unit descriptor handle         */
               BoardIndex,                   /* Board Index (GPIB0 = 0, GPIB1 = 1, ...) */
               PrimaryAddress,               /* Device primary address                  */
               SecondaryAddress,             /* Device secondary address                */
               GPT(timeout_period_msecs),    /* Timeout setting (T10s = 10 seconds)     */
               1,                            /* Assert EOI line at end of write         */
               0);                           /* EOS termination mode                    */
         }

      if (ibsta & ERR) 
         {                                /* Check for GPIB Error                    */
         CloseHandle(hCOMSem);
         hCOMSem = NULL;

         GpibError("ibdev Error\n");
         return 0;
         }
      }

   online = 1;

   return 1;
}

S32    WINAPI GPIB_offline  (S32 reset_to_local)
{
   if (!online)
      {
      return 1;
      }

   if (hCOMSem != NULL)
      {
      CloseHandle(hCOMSem);
      hCOMSem = NULL;
      }

   if (!INI_is_NI488)
      {
      //
      // Close serial or TCP connection
      //
      // Late-model Prologix boards can reset to local     
      // when shutting down ... this can be overridden     
      // by either connect.ini or the application, because 
      // it causes flooding problems on some instruments  
      // (e.g., the rev-B HP 8568A)                       
      //
      // 9-Aug-09: due to problems with 5370B chatter on GPIB-LAN, added 
      // restore_auto_read field to connect.ini.  1=put auto-read back to 
      // its original state before transmitting ++loc at shutdown time (old behavior), 
      // 0=always leave auto-read disabled at shutdown time.  Default is 0
      //

      if (serial_device != NULL)
         {
         if (INI_is_Prologix)
            {
            if (prologix_auto_read_enabled && ((!prologix_was_auto_read_enabled) || (INI_restore_auto_read == 0)))
               {
               GPIB_write("++auto 0");
               prologix_auto_read_enabled = FALSE;
               }
            else if ((!prologix_auto_read_enabled) && prologix_was_auto_read_enabled && INI_restore_auto_read)
               {
               GPIB_write("++auto 1");
               prologix_auto_read_enabled = TRUE;
               }

            if (INI_reset_to_local &&     
                reset_to_local)           
               {       
               //
               // HP 5370 chatters if auto-read enabled at shutdown time when using rates >1pps
               // HP 53131 will not reset to local with GPIB-USB if auto-read is *not* enabled at shutdown time
               //

               if (INI_reset_to_local == 53131) GPIB_write("++auto 1");
               GPIB_write("++loc");
               }  

            GPIB_flush_receive_buffers();    // Swallow any unread data before disconnecting TODO
            }
         
         delete serial_device;
         serial_device = NULL;
         }
      }
   else
      {
      //
      // Close NI488.2 connection
      //

      if (Device != -1)
         {
         if (reset_to_local)
            {
            ibloc(Device);              // Reset to local (8566B rev 3022 doesn't do this automatically)
            }

         ibonl(Device, 0);              /* Take the device offline                 */

//         if (ibsta & ERR)             // These report spurious timeout errors on ICS USB-488 if a previous ibrd() timed out,
//            {                         // so we'll disable them for now
//            GpibError("ibonl 0/1 Error\n");	
//            return 0;
//            }

         ibonl(GPIB_ID, 0);            /* Take the interface offline              */

//         if (ibsta & ERR) 
//            {
//            GpibError("ibonl 1/1 Error\n");	   
//            return 0;
//            }
         }
      else
         {
         ibonl(GPIB_ID, 0);

//         if (ibsta & ERR) 
//            {
//            GpibError("ibonl 0/0 Error\n");	   
//            return 0;
//            }
         }
      }

   online = 0;

   return 1;
}

//
// GPIB_connect / GPIB_connect_ex()
//

S32 WINAPI GPIB_connect(S32        dev_address,
                        GPIBERR    handler, 
                        S32        clear, 
                        S32        timeout_msecs,
                        S32        board_address,
                        S32        release_system_control,
                        S32        max_read_buffer_len,
                        S32        force_auto_read)
{
   device_address       = dev_address;
   err_handler          = handler;
   timeout_period_msecs = timeout_msecs;
   max_read_len         = max_read_buffer_len;
   serial_dropout_ms    = 500;
   serial_progress_cb   = NULL;
   serial_timeout_ms    = timeout_msecs;

   //
   // Load connect.ini
   //
   // Allow INI_force_auto_read to be overridden so our ++ commands at startup
   // don't cause "Addressed to talk with nothing to say" errors
   // 

   GPIB_connection_type();

   if (force_auto_read != -1)
      {
      INI_force_auto_read = force_auto_read;
      }

   //
   // If we're opening in listen-only mode, don't try to alter
   // any Prologix settings or flush the serial buffers
   // The only exception is the transmission of ++mode 0 to a Prologix adapter
   // to ensure it's in Device mode.
   //

   if (device_address == LISTEN_ONLY_NO_COMMANDS)
      {
      prologix_listen_only_mode = INI_is_Prologix;

      INI_is_Prologix = 0;
      device_address = -1;
      }

   //
   // Connect to instrument
   //

   if (!GPIB_online())
      {
      return 0;
      }

   Sleep(25);    // Needed to avoid ENOL errors on HP 3562A and syntax errors on HP 3561A, at least with NI

   //
   // Configure GPIB properties
   //

   if (!INI_is_NI488)
      {
      if (prologix_listen_only_mode)   // This is the only Prologix-specific command used in listen-only mode. 
         {                             // No queries, no buffer flushing, no address alteration...
         prologix_312c = 0;
         prologix_V4 = 0;
         prologix_440 = 0;

         GPIB_write("++mode 0");       
         }
      else if (INI_is_Prologix)
         {
         //
         // Get version of Prologix GPIB-USB or GPIB-LAN controller
         //

         prologix_major_version = 1;
         prologix_minor_version = 0;
         prologix_letter_version = 0;
         prologix_312c = 0;
         prologix_V4 = 0;
         prologix_440 = 0;
         prologix_was_auto_read_enabled = TRUE;
         prologix_auto_read_enabled = TRUE;

         if (INI_is_TCP)   
            {
            GPIB_write("++eot_enable 0");           // some GPIB-LAN adapters seem to have this turned on by default, which is a showstopper
            }

         C8 *ver = GPIB_query("++ver", TRUE);
         C8 *v = strstr(ver,"ersion ");

         if (v != NULL)
            {
            sscanf(v,"ersion %d.%d",
               &prologix_major_version,
               &prologix_minor_version);
            }

         if (prologix_major_version == 3)
            {
            prologix_letter_version = v[11];
            }

         S32 n = (prologix_major_version * 100) + prologix_minor_version;

         if (n >= 400) 
            {
            prologix_312c = prologix_V4 = TRUE;
            if (n >= 440) prologix_440 = TRUE;
            }
         else
            {
            if ((n > 312) || ((n == 312) && (prologix_letter_version >= 'c')))
               {
               prologix_312c = TRUE;
               }
            }

         if (prologix_312c || (INI_is_Prologix && INI_is_TCP))
            {
            C8 *a = GPIB_query("++auto", TRUE);

            if (a[0] == '0')
               {
               prologix_was_auto_read_enabled = FALSE;

               if (INI_force_auto_read)
                  {
                  GPIB_write("++auto 1");
                  prologix_auto_read_enabled = TRUE;
                  }
               else
                  {
                  prologix_auto_read_enabled = FALSE;
                  }
               }
            else 
               {
               prologix_was_auto_read_enabled = TRUE;

               if (!INI_force_auto_read)
                  {
                  GPIB_write("++auto 0");
                  prologix_auto_read_enabled = FALSE;
                  }
               else
                  {
                  prologix_auto_read_enabled = TRUE;
                  }
               }

            GPIB_write("++eos 0");        // we depend on CR/LF transmission

            C8 buffer[256];

            if (device_address != -1)
               {
               GPIB_write("++mode 1");    // if we're addressing a device, we need Controller mode

               sprintf(buffer,"++addr %d",device_address);
               GPIB_write(buffer);
               }
            else
               {
               GPIB_write("++mode 0");    // if no device address specified, use Device mode

               if (board_address != -1)
                  {
                  sprintf(buffer,"++addr %d",board_address);
                  GPIB_write(buffer);
                  }
               }
            }

         GPIB_flush_receive_buffers();    // Swallow any data left over from previous connection
         }
      }
   else
      {
      ibsad(GPIB_ID, 0);

      if ((device_address == -1) && (board_address == -1))
         {
         ibconfig(GPIB_ID, IbcLON, 1);
         }

      ibtmo(GPIB_ID, GPT(timeout_msecs));

      if (board_address != -1)
         {
         ibpad(GPIB_ID, board_address);  // ibconfig version of this call is buggy on ICS 488-USB

         if (ibsta & ERR)
            {                          
            GpibError("ibpad Error\n"); 
            return 0;
            }
         }

      if (release_system_control)
         {
         ibrsc(GPIB_ID, 0);            // Don't release by default; can't turn on 49x graticule if released
         }
      else
         {
         //
         // If we're not already CIC, assert it by sending an interface-clear message
         //
         // This is necessary for NI GPIB-USB-A with 1.1 drivers, as well as ICS 488-USB boards,
         // but to avoid breaking something else we won't do it unless we have to
         //
         // TODO: Causes async_read() to fail with ADR error when waiting for 
         // device-initiated plots on NI PCI-GPIB, so we'll leave it disabled for now
         //

//         if (!(ibsta & CIC))
//            {
//            ibrsc(GPIB_ID, 1);
//            ibsic(GPIB_ID);
//            }
         }
      
      ibconfig(GPIB_ID, IbcAUTOPOLL, 1);
      ibconfig(GPIB_ID, IbcCICPROT, 0);

      GPIB_set_EOS_mode(-1, TRUE, FALSE);   // 8566A/8568A apps will need to set EOT mode to FALSE...

      if (clear)
         {
         ibclr(Device);                

         if (ibsta & ERR) 
            {
            GpibError("ibclr Error\n");
            return 0;
            }
         }
      }

   //
   // Return success
   //

   return 1;
}

S32 WINAPI GPIB_connect_ex(C8        *dev_address,
                           GPIBERR    handler, 
                           S32        clear, 
                           S32        timeout_msecs,
                           S32        board_address,
                           S32        release_system_control,
                           S32        max_read_buffer_len,
                           S32        force_auto_read)
{
   //
   // If dev_address contains a colon, treat the portion before it
   // as an interface_settings line for Prologix (COMx:addr) or NI (GPIBx:addr) boards
   //

   C8 *dup = _strdup(dev_address);

   C8 *ptr = strchr(dup,':');

   if (ptr == NULL)
      {
      ptr = dup;
      }
   else
      {
      *ptr = NULL;
      ptr++;
      }

   S32 dev_addr = atoi(ptr);

   if (!_strnicmp(dup,"COM",3))
      {
      //
      // Replace connect.ini variables with a typical Prologix controller 
      // configuration
      //
      // (This doesn't support listen-only mode yet...)
      //

      strcpy(INI_setup_string, dup);
      strcat(INI_setup_string,":baud=115200 parity=N data=8 stop=1");

      INI_connection_type   = GC_PROLOGIX_SERIAL;
      INI_is_Prologix       = 1;
      INI_is_TCP            = 0;
      INI_is_NI488          = 0;
      INI_write_delay_ms    = 0;
      INI_reset_to_local    = 1;
      INI_restore_auto_read = 0;
      INI_force_auto_read   = force_auto_read;
      }
   else if (!_strnicmp(dup,"GPIB",4))
      {
      //
      // Replace connect.ini variables with a typical NI488.2 configuration
      //

      strcpy(INI_setup_string, dup);

      INI_connection_type   = GC_NI488;
      INI_is_Prologix       = 0;
      INI_is_TCP            = 0;
      INI_is_NI488          = 1;
      INI_write_delay_ms    = 0;
      INI_reset_to_local    = 1;
      INI_restore_auto_read = 0;
      INI_force_auto_read   = force_auto_read;
      }

   //
   // Set flag to prevent GPIB_connection_type() from overriding these
   // settings
   //

   using_connect_ex = TRUE;

   free(dup);

   return GPIB_connect(dev_addr, 
                       handler,
                       clear,
                       timeout_msecs,
                       board_address,
                       release_system_control,
                       max_read_buffer_len,
                       -1);
}

S32 WINAPI GPIB_disconnect(BOOL32 reset_to_local)
{
   S32 result = GPIB_offline(reset_to_local);

   device_address   = -1;
   err_handler      = NULL;
   using_connect_ex = FALSE;
   prologix_listen_only_mode = FALSE;

   return result;
}

S32 WINAPI GPIB_flush_receive_buffers(void)
{
   //
   // Swallow any data in the receive buffer (e.g., that may have been
   // left over from previous aborted connections)
   //
   // This has no effect with NI hardware
   //

   if (INI_is_NI488)
      {
      return 0;
      }

   S32 n=0;

   C8 *res = NULL;

   //
   // Issue repetitive read operations with 250-millisecond timeouts,
   // continuing until one of the reads times out or fails, or a total 
   // of 2 seconds is spent in the loop
   // 
   // If we receive data for more than 2 seconds in this loop, the instrument is 
   // probably flooding the line with zeroes (e.g., HP 8568A rev B 
   // in local mode).  Address it to talk by sending a blank line, which stops 
   // the flood... and retry the flush operation once before giving up altogether
   //

   U32    start          = timeGetTime();
   BOOL32 flood_detected = FALSE;

   while (1)
      {
      if ((timeGetTime() - start) >= 2048) 
         {
         if (flood_detected)
            {
            break;
            }

         serial_device->send("\r\n");

         start = timeGetTime();
         flood_detected = TRUE;
         }

      S32         b = 0;
      TERM_REASON r;

      serial_device->receive(-1,-1,250,250,NULL,&b,&r);

      n += b;

      if ((r == SR_ERROR)        || 
          (r == SR_DISCONNECTED) ||
         ((r == SR_TIMEOUT) && (b == 0)))
         {
         break;
         }
      }

   return n;
}

GPIB_CTYPE WINAPI GPIB_connection_type(void)
{
   if (!global_dirs.initialized())
      {
      global_dirs.init("KE5FX", "GPIB");
      }

   //
   // If GPIB_connect_ex() has been called, don't load or report connect.ini settings
   //

   if (using_connect_ex)
      {
      return INI_connection_type;
      }

   //
   // If .INI file has not yet been created, do it now
   //
   // (Can't do this at installation time because the installer may be run
   // by a different user)
   //

   C8 INI_user_pathname[MAX_PATH] = { 0 };
   _snprintf(INI_user_pathname, sizeof(INI_user_pathname)-1, "%sconnect.ini", global_dirs.LOCDATA);

   FILE *ser = fopen(INI_user_pathname, "rt");

   if (ser != NULL)
      {
      fclose(ser);
      }
   else
      {
      C8 default_INI_pathname[MAX_PATH] = { 0 } ;
      _snprintf(default_INI_pathname, sizeof(default_INI_pathname)-1, "%sdefault_connect.ini", global_dirs.EXE);

      CopyFileA(default_INI_pathname, 
               INI_user_pathname,
               FALSE);
      }

   //
   // If the CWD contains a copy of connect.ini, use it in preference to the 
   // user-global one
   // 

   C8 INI_working_pathname[MAX_PATH] = { 0 };
   _snprintf(INI_working_pathname, sizeof(INI_working_pathname)-1, "%sconnect.ini", global_dirs.ICW);

   ser = fopen(INI_working_pathname, "rt");
   
   if (ser == NULL)
      {
      ser = fopen(INI_user_pathname, "rt");
      }

   if (ser == NULL)
      {
      GpibError("CONNECT.INI not found -- please reinstall the GPIB Toolkit\n");
      return GC_NONE;
      }

   INI_setup_string[0]   = 0;
   INI_connection_type   = GC_NONE;
   INI_is_Prologix       = 0;
   INI_is_TCP            = 0;
   INI_is_NI488          = 0;
   INI_write_delay_ms    = 0;
   INI_reset_to_local    = 0;
   INI_restore_auto_read = 0;
   INI_force_auto_read   = 1;

   //
   // connect.ini found -- if it has a valid interface_settings line other than one
   // beginning with "GPIB", we'll be able to construct a COMBLOCK provider
   //

   while (1)
      {
      //
      // Read input line
      //

      C8 linbuf[512];

      memset(linbuf,
             0,
             sizeof(linbuf));

      C8 *result = fgets(linbuf, 
                         sizeof(linbuf) - 1, 
                         ser);

      if ((result == NULL) || (feof(ser)))
         {
         break;
         }

      //
      // Skip blank lines, and kill trailing and leading spaces
      //

      S32 l = strlen(linbuf);

      if ((!l) || (linbuf[0] == ';'))
         {
         continue;
         }

      C8 *lexeme  = linbuf;
      C8 *end     = linbuf;
      S32 leading = 1;

      for (S32 i=0; i < l; i++)
         {
         if (!isspace(linbuf[i]))
            {
            if (leading)
               {
               lexeme = &linbuf[i];
               leading = 0;
               }

            end = &linbuf[i];
            }
         }

      end[1] = 0;

      if ((leading) || (!strlen(lexeme)))
         {
         continue;
         }

      //
      // Terminate key substring at first space
      //

      C8 *value = strchr(lexeme,' ');

      if (value == NULL)
         {
         continue;
         }

      *value = 0;
      value++;

      //
      // Look for key/value pairs
      // Skip spaces and tabs between key and value
      //
      
      while (1)
         {
         if ((*value == ' ') || (*value == '\t'))
            {
            ++value;
            }
         else
            {
            break;
            }
         }

      if (*value == 0)
         {
         continue;
         }

      //
      // Kill trailing comment and any spaces before it
      //

      C8 *lin_comment = strchr(value,'`');

      if (lin_comment != NULL)
         {
         *lin_comment = 0;

         while (1)
            {
            --lin_comment;

            if (*lin_comment == ' ')
               {
               *lin_comment = 0;
               }
            else
               {
               break;
               }
            }
         }

           if (!_stricmp(lexeme,"is_Prologix"))          INI_is_Prologix        = atoi(value);
      else if (!_stricmp(lexeme,"reset_to_local"))       INI_reset_to_local     = atoi(value);
      else if (!_stricmp(lexeme,"restore_auto_read"))    INI_restore_auto_read  = atoi(value);
      else if (!_stricmp(lexeme,"force_auto_read"))      INI_force_auto_read    = atoi(value);
      else if (!_stricmp(lexeme,"write_delay_ms"))       INI_write_delay_ms     = atoi(value);
      else if (!_stricmp(lexeme,"interface_settings"))   strcpy(INI_setup_string, value);
      else 
         {
         GpibError("Unknown connect.ini entry '%s'\n",lexeme);
         }
      }

   fclose(ser);

   if (!INI_setup_string[0])
      {
      GpibError("CONNECT.INI not valid -- please reinstall the GPIB Toolkit\n");
      return GC_NONE;
      }

   //
   // Assumptions:
   //
   //    Settings string beginning "GPIBx" = National Instruments
   //    Settings string containing a period = IP address or DNS name
   //    Otherwise, it's a COM port specifier
   // 

   if (prologix_listen_only_mode)      // (a previous call to GPIB_connect requested listen-only support)
      {
      INI_is_Prologix = FALSE;
      }

   if (!strncmp(INI_setup_string,"GPIB",4))
      {
      INI_is_NI488 = TRUE;
      INI_is_Prologix = FALSE;
      INI_connection_type = GC_NI488;
      }
   else if (strchr(INI_setup_string,'.') != NULL) 
      {
      INI_is_TCP = TRUE;
      INI_connection_type = INI_is_Prologix ? GC_PROLOGIX_LAN : GC_OTHER_LAN;
      }
   else
      {
      INI_connection_type = INI_is_Prologix ? GC_PROLOGIX_SERIAL : GC_OTHER_SERIAL;
      }

   return INI_connection_type;
}

S32 WINAPI GPIB_set_serial_read_dropout (S32 ms)
{
   S32 prev = serial_dropout_ms;
   serial_dropout_ms = ms;

   if (INI_is_Prologix && (!prologix_auto_read_enabled))    // (Technically ++spoll uses this too, so we should always do it...)
      {
      char buffer[64];
      sprintf(buffer,"++read_tmo_ms %d",min(ms, 3000));     // Prologix ignores anything > 3000
      GPIB_write(buffer);                                      
      }

   return prev;
}

S32 WINAPI GPIB_auto_read_mode (S32 set_mode)
{
   if (!(prologix_312c || (INI_is_Prologix && INI_is_TCP)))
      {
      return FALSE;        // Only Prologix >3.12c supports auto-read mode
      }

   if (set_mode == FALSE)
      {
      if (prologix_auto_read_enabled)
         {
         GPIB_write("++auto 0");
         prologix_auto_read_enabled = FALSE;
         }
      }
   else if (set_mode == TRUE)
      {
      if (!prologix_auto_read_enabled)
         {
         GPIB_write("++auto 1");
         prologix_auto_read_enabled = TRUE;
         }
      }

   return prologix_auto_read_enabled;
}

SRPROGRESSCB WINAPI GPIB_set_serial_read_progress_callback (SRPROGRESSCB progress_cb)
{
   SRPROGRESSCB prev = serial_progress_cb;
   serial_progress_cb = progress_cb;

   return prev;
}

S32 WINAPI GPIB_set_EOS_mode(S32    new_EOS_char, //)
                             BOOL32 send_EOI_at_EOT,
                             BOOL32 enable_board_configuration)
{
   S32 prev = EOS_char;
   EOS_char = new_EOS_char;

   if (INI_is_NI488)
      {
      //
      // Set END bit of ibsta when EOS match *or* EOI occurs during a read                                                      
      //

      ibconfig(GPIB_ID, IbcEndBitIsNormal, 1);               

      //
      // On HP 8566A/8568A, we must not assert EOI at the last character of a query 
      // command (send_EOI_at_EOT must be 0).  Otherwise, the read will time out 
      // (although it appears to be OK to set EOI at EOT if the query ends in \r or \r\n).
      //
      // We never want to automatically assert EOI during EOS-character writes (IbcEOSwrt is
      // always 0)
      //

      if (Device != -1)
         {
         ibconfig(Device, IbcEOT,    send_EOI_at_EOT);         // (optionally assert EOS with last byte)
         ibconfig(Device, IbcEOSwrt, 0);                       // (don't assert EOI when we send EOS character)

         if (EOS_char == -1)
            {
            ibconfig(Device, IbcEOSchar, 0);
            ibconfig(Device, IbcEOSrd,   0);         
            }
         else
            {
            ibconfig(Device, IbcEOSchar, EOS_char);
            ibconfig(Device, IbcEOSrd,   1);
            }
         }
      else if (enable_board_configuration)   // (Added 2/07 for listen.exe: can turn this off if it breaks existing apps...)
         {                                  
         ibconfig(GPIB_ID, IbcEOT,    send_EOI_at_EOT); 
         ibconfig(GPIB_ID, IbcEOSwrt, 0);               

         if (EOS_char == -1)
            {
            ibconfig(GPIB_ID, IbcEOSchar, 0);
            ibconfig(GPIB_ID, IbcEOSrd,   0);         
            }
         else
            {
            ibconfig(GPIB_ID, IbcEOSchar, EOS_char);
            ibconfig(GPIB_ID, IbcEOSrd,   1);
            }
         }
      }
   else
      {
      //
      // Serial routines do their own IbcEOSchar/IbcEOSrd checks when appropriate, but we
      // do need to control outgoing-EOI-at-last-byte assertion here (IbcEOT equivalent).
      //

      if (prologix_312c || (INI_is_Prologix && INI_is_TCP))
         {
         if (send_EOI_at_EOT)
            {
            GPIB_write("++eoi 1");
            }
         else
            {
            GPIB_write("++eoi 0");
            }
         }
      }

   return prev;
}

S32 WINAPI GPIB_write(C8    *string, //)
                      S32    len, 
                      BOOL32 to_board, 
                      BOOL32 ignore_aborts)
{
   static C8 buffer[524288];

   if (len == -1)
      {
      len = strlen(string);
      }

   memcpy(buffer, string, len+1);

   buffer[len] = 0;           // Always append CR/LF (which will be removed and replaced with the ++eos string by Prologix)
   strcat(buffer,"\r\n");
   len += 2;

   if (!INI_is_NI488)
      {
      Sleep(INI_write_delay_ms / 2);
      serial_device->send(buffer, len);
      Sleep(INI_write_delay_ms / 2);
      }
   else
      {
      if ((Device == -1) || (to_board))
         {
         ibwrt(GPIB_ID, buffer, len);
         }
      else
         {
         ibwrt(Device, buffer, len);
         }

      if (ibsta & ERR)
         {
         S32 err = iberr;

         if ((err == EABO) && (ignore_aborts))
            {
            return 1;
            }

         if (err)
            {
            GpibError("ibwrt Error\n");
            return 0;
            }
         }
      }
   
   return 1;
}

S32 WINAPI GPIB_write_BIN(void  *string, //)
                          S32    len,
                          BOOL32 to_board, 
                          BOOL32 ignore_aborts)
{
   if (!INI_is_NI488)
      {
      //
      // If this is a Prologix device, we must escape various reserved characters
      // (so we don't need to issue ++eos 3 to inhibit CR/LF insertion)
      //

      U8 *text = (U8 *) calloc(len*2, 1);
      U8 *d = text;

      for (S32 i=0; i < len; i++)
         {
         C8 ch = ((C8 *) string)[i];

         if (INI_is_Prologix 
              && 
            ((ch == 27) || (ch == '+') || (ch == 13) || (ch == 10)))
            {
            *d++ = 27;
            }

         *d++ = ch;
         }

      Sleep(INI_write_delay_ms / 2);
      serial_device->send((C8 *) text, d-text);
      Sleep(INI_write_delay_ms / 2);

      free(text);
      text = NULL;
      }
   else
      {
      if ((Device == -1) || (to_board))
         {
         ibwrt(GPIB_ID, string, len);
         }
      else
         {
         ibwrt(Device, string, len);
         }

      if (ibsta & ERR)
         {
         S32 err = iberr;

         if ((err == EABO) && (ignore_aborts))
            {
            return 1;
            }

         if (err)
            {
            GpibError("ibwrt Error\n");
            return 0;
            }
         }
      }
   
   return 1;
}

C8 * WINAPI GPIB_read_ASC   (S32    max_len, //)   
                             BOOL32 report_timeout, 
                             BOOL32 from_board)
{
   //
   // Larger buffers than 4K are needed to read the results of
   // things like PLOT? queries... but they don't work on NI GPIB-232 
   // adapters.  NI488.2 applications that read large amounts of data need 
   // to use simulated async reads (as in 7470.cpp) when possible
   //
   // Serial reads, on the other hand, need a large line buffer
   //

   static char buffer[262144];  
   buffer[0] = 0;

   S32 cnt = 0;

   if (!INI_is_NI488)
      {
      if (INI_is_Prologix && (!prologix_auto_read_enabled) && (!from_board))
         {
         if (EOS_char != -1)
            {
            sprintf(buffer,"++read %d",EOS_char); 
            GPIB_write(buffer);
            buffer[0] = 0;
            }
         else
            {
            GPIB_write("++read eoi");
            }
         }

      TERM_REASON reason;

      U8 *result = serial_device->receive(max_len, 
                                          from_board ? 10 : EOS_char,  // (assume board-level reads such as ++spoll are always LF-terminated)
                                          serial_timeout_ms,
                                          serial_dropout_ms, 
                                          serial_progress_cb,
                                         &cnt,
                                         &reason);

      if ((reason == SR_TIMEOUT) || (reason == SR_ERROR) || (reason == SR_DISCONNECTED))
         {
         result = NULL;
         }

      if (result != NULL)
         {
         memcpy(buffer, result, cnt);
         }
      else
         {
         if (report_timeout)
            {
            GpibError("Read error: 0x%X\n",reason);	
            return NULL;
            }
         }
      }
   else
      {
      S32 limit = (max_len == -1) ? max_read_len : max_len;
      if (limit == -1) limit = sizeof(buffer)-1;

      if ((Device == -1) || (from_board))
         {
         ibconfig(GPIB_ID, IbcEOSrd, (EOS_char != -1));         
         ibrd(GPIB_ID, buffer, limit);
         }
      else
         {
         ibconfig(Device, IbcEOSrd, (EOS_char != -1));         
         ibrd(Device, buffer, limit);
         }

      cnt = ibcntl;

      if (ibsta & ERR)
         {
         S32 err = iberr;

         if (err)
            {
            if ((!(err == EABO)) || report_timeout)
               {
               GpibError("ibrd() Error\n");	
               return NULL;
               }
            }
         }
      }

   buffer[cnt] = '\0';         /* Null terminate the ASCII string */

   return buffer;
}

C8 * WINAPI GPIB_read_BIN   (S32    max_len,  //)
                             BOOL32 report_timeout,  
                             BOOL32 from_board,
                             S32   *actual_len)
{
   //
   // Larger buffers than 4K are needed to read the results of
   // things like PLOT? queries... but they don't work on NI GPIB-232 
   // adapters.  NI488.2 applications that read large amounts of data need 
   // to use simulated async reads (as in 7470.cpp) when possible
   //
   // Serial reads, on the other hand, need a large line buffer
   //

   static char buffer[262144];  
   buffer[0] = 0;

   if (!INI_is_NI488)
      {
      if (INI_is_Prologix && (!prologix_auto_read_enabled) && (!from_board))
         {
         GPIB_write("++read eoi");
         }

      S32         cnt = 0;
      TERM_REASON reason;

      U8 *result = serial_device->receive(max_len, 
                                         -1, 
                                          serial_timeout_ms,
                                          serial_dropout_ms, 
                                          serial_progress_cb,
                                         &cnt,
                                         &reason);

      if ((reason == SR_TIMEOUT) || (reason == SR_ERROR) || (reason == SR_DISCONNECTED))
         {
         result = NULL;
         }

      if (actual_len != NULL)
         {
         *actual_len = cnt;
         }

      if (result != NULL)
         {
         memcpy(buffer, result, cnt);
         }
      else
         {
         if (report_timeout)
            {
            GpibError("Read error 0x%X, cnt=%d\n",reason,cnt);	
            return NULL;
            }
         }
      }
   else
      {
      S32 limit = (max_len == -1) ? max_read_len : max_len;
      if (limit == -1) limit = sizeof(buffer)-1;

      if ((Device == -1) || (from_board))
         {
         ibconfig(GPIB_ID, IbcEOSrd, 0);         
         ibrd(GPIB_ID, buffer, limit);
         }
      else
         {
         ibconfig(Device, IbcEOSrd, 0);         
         ibrd(Device, buffer, limit);
         }

      if (actual_len != NULL)
         {
         *actual_len = ibcntl;
         }

      if (ibsta & ERR)  
         {
         S32 err = iberr;

         if (err)
            {
            if ((!(err == EABO)) || report_timeout)
               {
               GpibError("ibrd() Error\n");	
               return NULL;
               }
            }
         }
      }

   return buffer;
}

S32 WINAPI GPIB_status     (BOOL32 from_board)
{
   if (!INI_is_NI488)
      {
      return 0; 
      }

   if ((Device == -1) || (from_board))
      {
      return ibwait(GPIB_ID,0);
      }
   else
      {
      return ibwait(Device,0);
      }
}

U8 WINAPI GPIB_serial_poll (void)
{
   U8 result = -1;

   if (INI_is_NI488)
      {
      ibrsp(Device, (C8 *) &result);
      }
   else if (INI_is_Prologix)
      {
      C8 buffer[256];

      sprintf(buffer,"++spoll %d",device_address);
      GPIB_write(buffer);

      C8 *response = GPIB_read_ASC (-1,      // max_len
                                    FALSE,   // report_timeout
                                    TRUE);   // from_board
      if (response != NULL)
         {
         result = atoi(response);
         }
      }

   return result;
}

C8 *   WINAPI GPIB_query    (C8    *string, 
                             BOOL32 from_board)
{     
   if (!GPIB_write(string))
      {
      return NULL;
      }

   //
   // See comment at GPIB_read()
   //

   return GPIB_read_ASC(-1, TRUE, from_board);
}

//****************************************************************************
//
// Send unformatted string to GPIB
//
//****************************************************************************

S32 WINAPI GPIB_puts (C8    *string,
                      BOOL32 ignore_aborts)
{
   S32 result = GPIB_write(string,
                          -1,
                           FALSE,
                           ignore_aborts);
   return result;
}

//****************************************************************************
//
// Send formatted string to GPIB
//
//****************************************************************************

void __cdecl GPIB_printf(C8 *fmt, ...)
{
   C8 work_string[16384] = { 0 };
   float k = 0.0;    // (Forces inclusion of floating point support)

   va_list ap;

   va_start(ap,
            fmt);

   _vsnprintf(work_string,
              sizeof(work_string)-1,
              fmt,
              ap);

   va_end(ap);

   //
   // Remove any trailing whitespace
   //

   S32 l = strlen(work_string);

   while (l > 0)
      {
      --l;

      if (!isspace((U8) work_string[l]))
         {
         break;
         }

      work_string[l] = 0;
      }

   GPIB_puts(work_string);
}

/*****************************************************************************
 *                      Function GPIBERROR
 * This function will notify you that a NI-488 function failed by
 * printing an error message.  The status variable IBSTA will also be
 * printed in hexadecimal along with the mnemonic meaning of the bit
 * position. The status variable IBERR will be printed in decimal
 * along with the mnemonic meaning of the decimal value.  The status
 * variable IBCNTL will be printed in decimal.
 *
 * The EXIT function will terminate this program.
 *****************************************************************************/

S32 in_error_handler = 0;

void GpibError(C8 *msg, ...) 
{
   if (in_error_handler)
      {
      return;
      }

   in_error_handler = 1;

   #define APPEND (&errbuf[strlen(errbuf)])

   static char errbuf[4096];
   errbuf[0] = 0;

   if (msg) 
      {
      va_list ap;

      va_start(ap, 
               msg);

      vsprintf(errbuf, 
               msg,
               ap);

      va_end  (ap);
      }

   if (!INI_is_NI488)
      {
      sprintf(APPEND," (Communications error)\n");
      }
   else
      {
      sprintf (APPEND,"ibsta=&H%x  <", ibsta);
      if (ibsta & ERR )  sprintf (APPEND," ERR");
      if (ibsta & TIMO)  sprintf (APPEND," TIMO");
      if (ibsta & END )  sprintf (APPEND," END");
      if (ibsta & SRQI)  sprintf (APPEND," SRQI");
      if (ibsta & RQS )  sprintf (APPEND," RQS");
      if (ibsta & CMPL)  sprintf (APPEND," CMPL");
      if (ibsta & LOK )  sprintf (APPEND," LOK");
      if (ibsta & REM )  sprintf (APPEND," REM");
      if (ibsta & CIC )  sprintf (APPEND," CIC");
      if (ibsta & ATN )  sprintf (APPEND," ATN");
      if (ibsta & TACS)  sprintf (APPEND," TACS");
      if (ibsta & LACS)  sprintf (APPEND," LACS");
      if (ibsta & DTAS)  sprintf (APPEND," DTAS");
      if (ibsta & DCAS)  sprintf (APPEND," DCAS");
      sprintf (APPEND," >\n");
     
      sprintf (APPEND,"iberr=%d ", iberr);
      if (iberr == EDVR) sprintf (APPEND," EDVR <DOS Error>\n");
      if (iberr == ECIC) sprintf (APPEND," ECIC <Not Controller-In-Charge>\n");
      if (iberr == ENOL) sprintf (APPEND," ENOL <No Listener>\n");
      if (iberr == EADR) sprintf (APPEND," EADR <Address error>\n");
      if (iberr == EARG) sprintf (APPEND," EARG <Invalid argument>\n");
      if (iberr == ESAC) sprintf (APPEND," ESAC <Not System Controller>\n");
      if (iberr == EABO) sprintf (APPEND," EABO <Operation aborted>\n");
      if (iberr == EHDL) sprintf (APPEND," EHDL <Invalid input handle>\n");
      if (iberr == ENEB) sprintf (APPEND," ENEB <No GPIB board>\n");
      if (iberr == EOIP) sprintf (APPEND," EOIP <Async I/O in progress>\n");
      if (iberr == ECAP) sprintf (APPEND," ECAP <No capability>\n");
      if (iberr == EFSO) sprintf (APPEND," EFSO <File system error>\n");
      if (iberr == EBUS) sprintf (APPEND," EBUS <Command error>\n");
      if (iberr == ESTB) sprintf (APPEND," ESTB <Status byte lost>\n");
      if (iberr == ESRQ) sprintf (APPEND," ESRQ <SRQ stuck on>\n");
      if (iberr == ETAB) sprintf (APPEND," ETAB <Table Overflow>\n");
     
      sprintf (APPEND,"ibcntl=%ld\n", ibcntl);
      }

   sprintf (APPEND,"\n");

   if (err_handler != NULL)
      {
      err_handler(errbuf, ibsta, iberr, ibcntl);
      }
   else
      {
      MessageBoxA(NULL,errbuf,"GPIBLIB Fatal Error",MB_OK);
      exit(1);
      }

   in_error_handler = 0;
}

//--------------------------------
void main(void)
{
   //
   // Test
   //

}

