//-----------------------------------------------------------------------------
// @rgba8.org
//-----------------------------------------------------------------------------
#ifndef EMP_HH_STDIO_H
#define EMP_HH_STDIO_H

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#ifdef __STRICT_ANSI__
// TODO : ugly
#undef __STRICT_ANSI__
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#define __STRICT_ANSI__
#else
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#endif

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#endif

