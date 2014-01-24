//-----------------------------------------------------------------------------
//
// File Name : emp_tt_def.h
//
// Creation Date : Fri 08 Oct 2010 08:39:11 AM CEST
//
// Modification Date : mar. 26 nov. 2013 18:10:01 CET
//
// Created By : ksej - www.rgba8.org
//
// Description :
//
//-----------------------------------------------------------------------------
#ifndef EMP_TT_DEF_H
#define EMP_TT_DEF_H

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
// TODO : check inclusion CHAR_MIN WCHAR_MIN etc
#include <limits.h>
#include <wchar.h>
#include <float.h>

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#if (defined(CHAR_MIN) && (CHAR_MIN != 0))
#define EMP_TT_CHAR_EMP_TT_MIN CHAR_MIN
#else
#define EMP_TT_CHAR_EMP_TT_MIN 0
#endif
#define EMP_TT_CHAR_EMP_TT_MAX CHAR_MAX

#define EMP_TT_CHAR_EMP_TT_S_MIN SCHAR_MIN
#define EMP_TT_CHAR_EMP_TT_S_MAX SCHAR_MIN

#define EMP_TT_CHAR_EMP_TT_U_MIN 0
#define EMP_TT_CHAR_EMP_TT_U_MAX UCHAR_MAX

#define EMP_TT_CHAR_MIN EMP_TT_CHAR_EMP_TT_MIN
#define EMP_TT_CHAR_MAX EMP_TT_CHAR_EMP_TT_MAX

#define EMP_TT_CHAR_S_MIN EMP_TT_CHAR_EMP_TT_S_MIN
#define EMP_TT_CHAR_S_MAX EMP_TT_CHAR_EMP_TT_S_MAX

#define EMP_TT_CHAR_U_MIN EMP_TT_CHAR_EMP_TT_U_MIN
#define EMP_TT_CHAR_U_MAX EMP_TT_CHAR_EMP_TT_U_MAX

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
// TODO : #if wchar
#if (defined(WCHAR_MIN) && (WCHAR_MIN != 0))
#define EMP_TT_WCHAR_EMP_TT_MIN WCHAR_MIN
#else
#define EMP_TT_WCHAR_EMP_TT_MIN 0
#endif
#define EMP_TT_WCHAR_EMP_TT_MAX WCHAR_MAX

#define EMP_TT_WCHAR_MIN EMP_TT_WCHAR_EMP_TT_MIN
#define EMP_TT_WCHAR_MAX EMP_TT_WCHAR_EMP_TT_MAX

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#define EMP_TT_BOOL_EMP_TT_MIN 0
#define EMP_TT_BOOL_EMP_TT_MAX 1

#define EMP_TT_BOOL_MIN EMP_TT_BOOL_EMP_TT_MIN
#define EMP_TT_BOOL_MAX EMP_TT_BOOL_EMP_TT_BAX

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#define EMP_TT_SHORT_EMP_TT_MIN SHRT_MIN
#define EMP_TT_SHORT_EMP_TT_MAX SHRT_MAX

#define EMP_TT_SHORT_EMP_TT_U_MIN 0
#define EMP_TT_SHORT_EMP_TT_U_MAX USHRT_MAX

#define EMP_TT_SHORT_MIN EMP_TT_SHORT_EMP_TT_MIN
#define EMP_TT_SHORT_MAX EMP_TT_SHORT_EMP_TT_MAX

#define EMP_TT_SHORT_U_MIN EMP_TT_SHORT_EMP_TT_U_MIN
#define EMP_TT_SHORT_U_MAX EMP_TT_SHORT_EMP_TT_U_MAX

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#define EMP_TT_INT_EMP_TT_MIN INT_MIN
#define EMP_TT_INT_EMP_TT_MAX INT_MAX

#define EMP_TT_INT_EMP_TT_U_MIN 0
#define EMP_TT_INT_EMP_TT_U_MAX UINT_MAX

#define EMP_TT_INT_MIN EMP_TT_INT_EMP_TT_MIN
#define EMP_TT_INT_MAX EMP_TT_INT_EMP_TT_MAX

#define EMP_TT_INT_U_MIN EMP_TT_INT_EMP_TT_U_MIN
#define EMP_TT_INT_U_MAX EMP_TT_INT_EMP_TT_U_MAX

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#define EMP_TT_LONG_EMP_TT_MIN LONG_MIN
#define EMP_TT_LONG_EMP_TT_MAX LONG_MAX

#define EMP_TT_LONG_EMP_TT_U_MIN 0
#define EMP_TT_LONG_EMP_TT_U_MAX ULONG_MAX

#define EMP_TT_LONG_MIN EMP_TT_LONG_EMP_TT_MIN
#define EMP_TT_LONG_MAX EMP_TT_LONG_EMP_TT_MAX

#define EMP_TT_LONG_U_MIN EMP_TT_LONG_EMP_TT_U_MIN
#define EMP_TT_LONG_U_MAX EMP_TT_LONG_EMP_TT_U_MAX

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#define EMP_TT_LONG_LONG_ENABLE
#if defined(EMP_TT_LONG_LONG_ENABLE)
#define EMP_TT_LONG_LONG_EMP_TT_MIN LLONG_MIN
#define EMP_TT_LONG_LONG_EMP_TT_MAX LLONG_MAX

#define EMP_TT_LONG_LONG_EMP_TT_U_MIN 0
#define EMP_TT_LONG_LONG_EMP_TT_U_MAX ULLONG_MAX

#define EMP_TT_LONG_LONG_MIN EMP_TT_LONG_LONG_EMP_TT_MIN
#define EMP_TT_LONG_LONG_MAX EMP_TT_LONG_LONG_EMP_TT_MAX

#define EMP_TT_LONG_LONG_U_MIN EMP_TT_LONG_LONG_EMP_TT_U_MIN
#define EMP_TT_LONG_LONG_U_MAX EMP_TT_LONG_LONG_EMP_TT_U_MAX
#endif

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#define EMP_TT_FLOAT_EMP_TT_MIN FLT_MIN
#define EMP_TT_FLOAT_EMP_TT_MAX FLT_MAX

#define EMP_TT_FLOAT_MIN EMP_TT_FLOAT_EMP_TT_MIN
#define EMP_TT_FLOAT_MAX EMP_TT_FLOAT_EMP_TT_MAX

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#define EMP_TT_DOUBLE_EMP_TT_MIN DBL_MIN
#define EMP_TT_DOUBLE_EMP_TT_MAX DBL_MAX

#define EMP_TT_DOUBLE_MIN EMP_TT_DOUBLE_EMP_TT_MIN
#define EMP_TT_DOUBLE_MAX EMP_TT_DOUBLE_EMP_TT_MAX

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#define EMP_TT_LONG_DOUBLE_EMP_TT_MIN LDBL_MIN
#define EMP_TT_LONG_DOUBLE_EMP_TT_MAX LDBL_MAX

#define EMP_TT_LONG_DOUBLE_MIN EMP_TT_LONG_DOUBLE_EMP_TT_MIN
#define EMP_TT_LONG_DOUBLE_MAX EMP_TT_LONG_DOUBLE_EMP_TT_MAX

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#if (EMP_TT_CHAR_MIN != 0)
#define EMP_TT_CHAR_SIGNED true
#else
#define EMP_TT_CHAR_SIGNED false
#endif

#if (EMP_TT_WCHAR_MIN != 0)
#define EMP_TT_WCHAR_SIGNED true
#else
#define EMP_TT_WCHAR_SIGNED false
#endif

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#if defined (EMP_TT_LONG_LONG_ENABLE)
#define EMP_TT_TYPE_LONG_LONG\
    XTMP_TT_TYPE(long long int, EMP_TT_LONG_LONG, true, true, false, true)
#else
#define EMP_TT_TYPE_LONG_LONG
#endif

//-----------------------------------------------------------------------------
// EMP_TT_TYPE(x_Type, x_Name, x_Integral, x_Signdness, x_Distinct, x_Signed)
//-----------------------------------------------------------------------------
#define EMP_TT_TYPES()\
XTMP_TT_TYPE(char, EMP_TT_CHAR      , true, true , true, EMP_TT_CHAR_SIGNED)\
XTMP_TT_TYPE(wchar_t, EMP_TT_WCHAR  , true, false, false, EMP_TT_WCHAR_SIGNED)\
XTMP_TT_TYPE(bool, EMP_TT_BOOL      , true, false, false, false)\
XTMP_TT_TYPE(short, EMP_TT_SHORT    , true, true , false, true)\
XTMP_TT_TYPE(int, EMP_TT_INT        , true, true , false, true)\
XTMP_TT_TYPE(long int, EMP_TT_LONG  , true, true , false, true)\
EMP_TT_TYPE_LONG_LONG \
XTMP_TT_TYPE(float, EMP_TT_FLOAT    , false, false, false, false)\
XTMP_TT_TYPE(double, EMP_TT_DOUBLE  , false, false, false, false)\
XTMP_TT_TYPE(long double, EMP_TT_LONG_DOUBLE, false, false, false, false)

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#endif

