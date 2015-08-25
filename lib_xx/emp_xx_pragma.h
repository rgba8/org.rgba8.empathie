//-----------------------------------------------------------------------------
// @rgba8.org
//-----------------------------------------------------------------------------
#ifndef EMP_XX_PRAGMA_H
#define EMP_XX_PRAGMA_H

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#include "emp_pp_string.h"

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#define EMP_W_OLD_STYLE_CAST "-Wold-style-cast"
#define EMP_W_FLOAT_EQUAL "-Wfloat-equal"
#define EMP_W_FORMAT_NONLITERAL "-Wformat-nonliteral"
#define EMP_W_FORMAT_SECURITY "-Wformat-security"
#define EMP_W_UNUSED_PRIVATE_FIELD "-Wunused-private-field"

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#define EMP_GCC_DIAGNOSTIC(x_Value) GCC diagnostic x_Value

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#define EMP_GCC_DIAGNOSTIC_IGNORED ignored
#define EMP_GCC_DIAGNOSTIC_WARNING warning
#define EMP_GCC_DIAGNOSTIC_ERROR error

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#define EMP_PRAGMA(x_Value) _Pragma(EMP_PP_STRING(x_Value))
#define EMP_PRAGMA_SET(x_State, x_Value) EMP_PRAGMA(EMP_GCC_DIAGNOSTIC(x_State), x_Value)
#define EMP_PRAGMA_SET_IGNORE(x_Value) EMP_PRAGMA(EMP_GCC_DIAGNOSTIC(EMP_GCC_DIAGNOSTIC_IGNORED) x_Value)
#define EMP_PRAGMA_SET_ERROR(x_Value) EMP_PRAGMA(EMP_GCC_DIAGNOSTIC(EMP_GCC_DIAGNOSTIC_ERROR) x_Value)

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#define EMP_PRAGMA_PUSH_IGNORE(x_Value) EMP_PRAGMA_SET_IGNORE(x_Value)
#define EMP_PRAGMA_POP_IGNORE(x_Value) EMP_PRAGMA_SET_ERROR(x_Value)

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#endif

