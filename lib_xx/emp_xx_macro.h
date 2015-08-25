//-----------------------------------------------------------------------------
// @rgba8.org
//-----------------------------------------------------------------------------
#ifndef EMP_XX_MACRO_H
#define EMP_XX_MACRO_H

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#if defined EMP_XX_LOUSY
#include "emp_xx_macro_lousy.h"
#elif defined EMP_XX_DEBUG
#include "emp_xx_macro_debug.h"
#elif defined EMP_XX_RELEASE
#include "emp_xx_macro_release.h"
#elif defined EMP_XX_FINAL
#include "emp_xx_macro_final.h"
#else
#error unknown build
#endif

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#if defined EMP_XX_OS_IOS
#define EMP_XX_IF_IOS(x_Then) x_Then
#define EMP_XX_IF_NOT_IOS(x_Then)
#else
#define EMP_XX_IF_IOS(x_Then)
#define EMP_XX_IF_NOT_IOS(x_Then) x_Then
#endif

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#ifndef EMP_XX_TT_ARRAY_COUNT
#error EMP_XX_TT_ARRAY_COUNT not defined
#endif

#ifndef EMP_XX_CNT_TUPLE_COUNT
#error EMP_XX_CNT_TUPLE_COUNT not defined
#endif

#ifndef EMP_XX_MEM_ALLOCATE_COUNT
#error EMP_XX_MEM_ALLOCATE_COUNT not defined
#endif

#ifndef EMP_XX_STR_FORMAT_COUNT
#error EMP_XX_STR_FORMAT_COUNT not defined
#endif

#ifndef EMP_XX_FCT_FUNCTION_COUNT
#error EMP_XX_FCT_FUNCTION_COUNT not defined
#endif

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#if defined(EMP_XX_ASSERT)
#define EMP_XX_IF_ASSERT(x_Then) x_Then
#define EMP_XX_IF_NOT_ASSERT(x_Then)
#define EMP_XX_IF_ELSE_ASSERT(x_Then, x_Else) x_Then
#else
#define EMP_XX_IF_ASSERT(x_Then)
#define EMP_XX_IF_NOT_ASSERT(x_Then) x_Then
#define EMP_XX_IF_ELSE_ASSERT(x_Then, x_Else) x_Else
#endif

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#if defined(EMP_XX_LOCALIZE)
#define EMP_XX_IF_LOCALIZE(x_Then) x_Then
#define EMP_XX_IF_NOT_LOCALIZE(x_Then)
#define EMP_XX_IF_ELSE_LOCALIZE(x_Then, x_Else) x_Then
#else
#define EMP_XX_IF_LOCALIZE(x_Then)
#define EMP_XX_IF_NOT_LOCALIZE(x_Then) x_Then
#define EMP_XX_IF_ELSE_LOCALIZE(x_Then, x_Else) x_Else
#endif

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#ifdef EMP_XX_TRACE_LEAKS
#define EMP_XX_TRACE
#endif

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#ifdef EMP_XX_DEBUG
#define EMP_XX_IF_DEBUG(x_Then) x_Then
#else
#define EMP_XX_IF_DEBUG(x_Then)
#endif

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#include "emp_xx_attribute.h"
#include "emp_xx_build.h"
#include "emp_xx_call.h"
#include "emp_xx_class.h"
#include "emp_xx_pragma.h"
#include "emp_xx_noop.h"

#include "emp_hh_typedef.h"

#include "emp_ast_asserter.h"

#include "emp_log_logger.h"

#include "emp_str_string.h"

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#endif

