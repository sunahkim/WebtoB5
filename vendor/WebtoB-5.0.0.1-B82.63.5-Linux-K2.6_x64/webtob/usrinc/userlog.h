
/* ------------------------- usrinc/userlog.h ----------------- */
/*                                                              */
/*              Copyright (c) 2000 TmaxSoft Co., Ltd            */
/*                   All Rights Reserved                        */
/*                                                              */
/* ------------------------------------------------------------ */

#ifndef _WEBTOB_USERLOG_H
#define _WEBTOB_USERLOG_H

#include <time.h>

#ifndef _WIN32
#define __cdecl
#endif

#if defined (__cplusplus)
extern "C" {
#endif

int __cdecl userlog(const char *fmt, ...);
int __cdecl UserLog(const char *fmt, ...);
int __cdecl ulogsync();

#if defined (__cplusplus)
}
#endif

#endif
