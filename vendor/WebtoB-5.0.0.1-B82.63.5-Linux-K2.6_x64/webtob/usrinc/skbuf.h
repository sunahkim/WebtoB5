
/* --------------------- usrinc/skbuf.h ----------------------- */
/*                                                              */
/*              Copyright (c) 2000 TmaxSoft Co., Ltd            */
/*                   All Rights Reserved                        */
/*                                                              */
/* ------------------------------------------------------------ */

#ifndef _WEBTOB_SKBUF_H
#define _WEBTOB_SKBUF_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef _WIN32
#define __cdecl
#endif

/* ---- type definition --- */
typedef struct skbuf_s SKBUF;
typedef SKBUF* pSKBUF;

/* ------- FBUF API ------- */
#if defined(__cplusplus)
extern "C" {
#endif

SKBUF * __cdecl skbcreate(int size);
void __cdecl skbfree(SKBUF *skbuf);
char * __cdecl skbget(SKBUF *skbuf, char *key);
char * __cdecl skbgetnth(SKBUF *skbuf, char *key, int nth);
int __cdecl skbput(SKBUF *skbuf, char *key, char *value);
int __cdecl skbputnth(SKBUF *skbuf, char *key, char *value, int nth);
int __cdecl skbdelall(SKBUF *skbuf, char *key);
int __cdecl skbdelete(SKBUF *skbuf, char *key, int nth);
int __cdecl skbupdate(SKBUF *skbuf, char *key, char *value, int nth);
int __cdecl skbelemcount(SKBUF *skbuf);
int __cdecl skbkeyoccur(SKBUF *skbuf, char *key);

int __cdecl skbget_used(SKBUF *skbuf);
int __cdecl skbget_asize(SKBUF *skbuf);

int __cdecl skbprint(SKBUF *skbuf, char *key);
int __cdecl skbread(SKBUF *skbuf, char *pathname);
int __cdecl skbwrite(SKBUF *skbuf, char *pathname);

#if defined(__cplusplus)
}
#endif

#endif /* _WEBTOB_SKBUF_H */
