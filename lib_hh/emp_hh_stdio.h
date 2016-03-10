//-----------------------------------------------------------------------------
// emp_hh_stdio.h - @rgba8.org
//-----------------------------------------------------------------------------
#ifndef EMP_HH_STDIO_H
#define EMP_HH_STDIO_H

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
EMP_PRAGMA_PUSH_IGNORE(EMP_W_UNREFERENCED_INLINE_FUNCTION)
EMP_PRAGMA_PUSH_IGNORE(EMP_W_NOEXPECT)
#ifdef __STRICT_ANSI__
// @@0 ugly
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
EMP_PRAGMA_POP_IGNORE(EMP_W_NOEXPECT)
EMP_PRAGMA_POP_IGNORE(EMP_W_UNREFERENCED_INLINE_FUNCTION)

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#endif

