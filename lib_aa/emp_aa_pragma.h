//-----------------------------------------------------------------------------
//
// File Name : emp_aa_pragma.h
//
// Creation Date : Thu 03 Feb 2011 10:33:42 AM CET
//
// Modification Date : ven. 01 nov. 2013 11:57:44 CET
//
// Created By : rgba8 (ksej) - www.empathy.fr
//
// Description :
//
//-----------------------------------------------------------------------------
#ifndef EMP_AA_PRAGMA_H
#define EMP_AA_PRAGMA_H

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#include "emp_pp_string.h"

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#define EMP_AA_W_OLD_STYLE_CAST "-Wold-style-cast"
#define EMP_AA_W_FLOAT_EQUAL "-Wfloat-equal"
#define EMP_AA_W_FORMAT_NONLITERAL "-Wformat-nonliteral"
#define EMP_AA_W_FORMAT_SECURITY "-Wformat-security"

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#define EMP_AA_GCC_DIAGNOSTIC(x_Value) GCC diagnostic x_Value

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#define EMP_AA_GCC_DIAGNOSTIC_IGNORED ignored
#define EMP_AA_GCC_DIAGNOSTIC_WARNING warning
#define EMP_AA_GCC_DIAGNOSTIC_ERROR error

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#define EMP_AA_PRAGMA(x_Value) _Pragma(EMP_PP_STRING(x_Value))

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#define EMP_AA_PRAGMA_SET(x_State, x_Value)\
    EMP_AA_PRAGMA(EMP_AA_GCC_DIAGNOSTIC(x_State), x_Value)

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#define EMP_AA_PRAGMA_SET_IGNORE(x_Value)\
    EMP_AA_PRAGMA(EMP_AA_GCC_DIAGNOSTIC(EMP_AA_GCC_DIAGNOSTIC_IGNORED) x_Value)

#define EMP_AA_PRAGMA_SET_ERROR(x_Value)\
    EMP_AA_PRAGMA(EMP_AA_GCC_DIAGNOSTIC(EMP_AA_GCC_DIAGNOSTIC_ERROR) x_Value)

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#define EMP_AA_PRAGMA_PUSH_IGNORE(x_Value) EMP_AA_PRAGMA_SET_IGNORE(x_Value)
#define EMP_AA_PRAGMA_POP_IGNORE(x_Value) EMP_AA_PRAGMA_SET_ERROR(x_Value)

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#endif

