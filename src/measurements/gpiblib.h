#ifndef GPIBLIB_H
#define GPIBLIB_H

#include "typedefs.h"

#ifdef __cplusplus
extern "C"
{
#endif

//msavic
/*
#ifdef BUILDING_GPIBLIB
   #define GPIBDEF __declspec(dllexport)
#else
   #define GPIBDEF __declspec(dllimport)
#endif
*/

#define GPIBDEF  

enum GPIB_CTYPE
{
   GC_NONE,
   GC_NI488,
   GC_PROLOGIX_SERIAL,
   GC_PROLOGIX_LAN,
   GC_OTHER_LAN,
   GC_OTHER_SERIAL
};

const S32 LISTEN_ONLY_NO_COMMANDS = -2;      // Special value to force is_Prologix=0 in listen-only mode

typedef void (WINAPI *GPIBERR)      (C8 *msg, S32 ibsta, S32 iberr, S32 ibcntl);
typedef int  (WINAPI *SRPROGRESSCB) (void);
                                                  
GPIBDEF S32    WINAPI GPIB_connect                 (S32        device_address, 
                                                    GPIBERR    handler, 
                                                    S32        clear                  = 0, 
                                                    S32        timeout_msecs          = 100000,  // use -1 to disable timeout checks
                                                    S32        board_address          = -1, 
                                                    S32        release_system_control = 0,
                                                    S32        max_read_buffer_len    = 4096,    // >4K will not work with NI GPIB-232! 
                                                    S32        force_auto_read        = -1);     // -1 = use INI_force_auto_read setting

GPIBDEF S32    WINAPI GPIB_connect_ex              (C8        *device_address,                   // alternate version that takes a full setup/address string 
                                                    GPIBERR    handler, 
                                                    S32        clear                  = 0, 
                                                    S32        timeout_msecs          = 100000,  // use -1 to disable timeout checks
                                                    S32        board_address          = -1, 
                                                    S32        release_system_control = 0,
                                                    S32        max_read_buffer_len    = 4096,    // >4K will not work with NI GPIB-232! 
                                                    S32        force_auto_read        = 0);   

GPIBDEF S32          WINAPI  GPIB_disconnect                        (S32 reset_to_local = TRUE);
GPIBDEF S32          WINAPI  GPIB_set_EOS_mode                      (S32 new_EOS_char, BOOL32 send_EOI_at_EOT = TRUE, BOOL32 enable_board_configuration = TRUE);
GPIBDEF S32          WINAPI  GPIB_write                             (C8 *string, S32 len=-1, BOOL32 to_board = FALSE, BOOL32 ignore_aborts = TRUE); 
GPIBDEF S32          WINAPI  GPIB_write_BIN                         (void *string, S32 len, BOOL32 to_board = FALSE, BOOL32 ignore_aborts = TRUE); 
GPIBDEF S32          WINAPI  GPIB_puts                              (C8 *string, BOOL32 ignore_aborts = TRUE);
GPIBDEF void         __cdecl GPIB_printf                            (C8 *fmt, ...);
GPIBDEF S32          WINAPI  GPIB_set_serial_read_dropout           (S32 ms); 
GPIBDEF SRPROGRESSCB WINAPI  GPIB_set_serial_read_progress_callback (SRPROGRESSCB progress_callback = NULL); 
GPIBDEF GPIB_CTYPE   WINAPI  GPIB_connection_type                   (void);
GPIBDEF S32          WINAPI  GPIB_auto_read_mode                    (S32 set_mode=-1);
GPIBDEF C8 *         WINAPI  GPIB_read_ASC                          (S32 max_len=-1, BOOL32 report_timeout = TRUE, BOOL32 from_board = FALSE);
GPIBDEF C8 *         WINAPI  GPIB_read_BIN                          (S32 max_len=-1, BOOL32 report_timeout = TRUE, BOOL32 from_board = FALSE, S32 *actual_len = NULL);
GPIBDEF S32          WINAPI  GPIB_status                            (BOOL32 from_board = FALSE);
GPIBDEF C8 *         WINAPI  GPIB_query                             (C8 *string, BOOL32 from_board = FALSE);
GPIBDEF U8           WINAPI  GPIB_serial_poll                       (void);
GPIBDEF S32          WINAPI  GPIB_flush_receive_buffers             (void);
                                                                   
#ifdef __cplusplus
}
#endif

#endif
