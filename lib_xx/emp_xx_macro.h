//-----------------------------------------------------------------------------
//
// File Name : emp_xx_macro.h
//
// Creation Date : Mon 11 Oct 2010 10:27:15 PM CEST
//
// Modification Date : lun. 29 juin 2015 23:14:47 CEST
//
// Created By : ksej - www.rgba8.org
//
// Description :
//
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
#elif defined EMP_XX_RETAIL
#include "emp_xx_macro_retail.h"
#elif defined EMP_XX_FINAL
#include "emp_xx_macro_final.h"
#else
#error unknown build
#endif

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#if defined EMP_XX_OS_IOS
#define EMP_IF_IOS(x_Then) x_Then
#define EMP_IF_NOT_IOS(x_Then)
#else
#define EMP_IF_IOS(x_Then)
#define EMP_IF_NOT_IOS(x_Then) x_Then
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
#if defined(EMP_XX_LOG_ENABLE_INFORMATION) ||\
    defined(EMP_XX_LOG_ENABLE_DEBUG) ||\
    defined(EMP_XX_LOG_ENABLE_WARNING) ||\
    defined(EMP_XX_LOG_ENABLE_ERROR) ||\
    defined(EMP_XX_LOG_ENABLE_OUTPUT)
#ifndef EMP_XX_LOG_ENABLE
#define EMP_XX_LOG_ENABLE
#endif
#endif

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#ifdef EMP_XX_LOG_ENABLE
#ifndef EMP_XX_OUTPUT_ENABLE
#define EMP_XX_OUTPUT_ENABLE
#endif
#endif

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#ifdef EMP_XX_ASSERT_ENABLE
#ifndef EMP_XX_OUTPUT_ENABLE
#define EMP_XX_OUTPUT_ENABLE
#endif
#endif

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#if defined(EMP_XX_LOG_ENABLE)
#ifndef EMP_XX_ASSERT_ENABLE
    #define EMP_XX_ASSERT_OUTPUT_ENABLE
#endif
//#ifndef EMP_XX_LOCALIZE_ENABLE
//    #define EMP_XX_LOCALIZE_ENABLE
//#endif
#endif

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#if defined(EMP_XX_ASSERT_ENABLE)
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
#if defined(EMP_XX_LOG_ENABLE_OUTPUT)
#define EMP_XX_IF_LOG_OUTPUT(x_Then) x_Then
#define EMP_XX_IF_NOT_LOG_OUTPUT(x_Then)
#define EMP_XX_IF_ELSE_LOG_OUTPUT(x_Then, x_Else) x_Then
#else
#define EMP_XX_IF_LOG_OUTPUT(x_Then)
#define EMP_XX_IF_NOT_LOG_OUTPUT(x_Then) x_Then
#define EMP_XX_IF_ELSE_LOG_OUTPUT(x_Then, x_Else) x_Else
#endif

#if defined(EMP_XX_LOG_ENABLE)
#define EMP_XX_IF_LOG(x_Then) x_Then
#define EMP_XX_IF_NOT_LOG(x_Then)
#define EMP_XX_IF_ELSE_LOG(x_Then, x_Else) x_Then
#else
#define EMP_XX_IF_LOG(x_Then)
#define EMP_XX_IF_NOT_LOG(x_Then) x_Then
#define EMP_XX_IF_ELSE_LOG(x_Then, x_Else) x_Else
#endif

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#if defined(EMP_XX_LOCALIZE_ENABLE)
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
#ifdef EMP_XX_TRACK_LEAKS_ENABLE
#define EMP_XX_IF_TRACK_LEAKS(x_Then) x_Then
#define EMP_XX_IF_NOT_TRACK_LEAKS(x_Then)
#define EMP_XX_IF_ELSE_TRACK_LEAKS(x_Then, x_Else) x_Then
#else
#define EMP_XX_IF_TRACK_LEAKS(x_Then)
#define EMP_XX_IF_NOT_TRACK_LEAKS(x_Then) x_Then
#define EMP_XX_IF_ELSE_TRACK_LEAKS(x_Then, x_Else) x_Else
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
#if EMP_XX_MEM_ALLOCATE_COUNT > 1
#define EMP_XX_ENABLE_FUNCTOR
#endif

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#define EMP_XX_MEM_ALLOCATOR()\
    basic_allocator<\
        EMP_XX_IF_TRACK_LEAKS(leak_allocator<)\
            sized_allocator<\
                malloc_allocator\
            >\
            EMP_XX_IF_TRACK_LEAKS(>)\
        >

#define EMP_XX_MEM_ALIGNATOR()\
    basic_allocator<\
        aligned_allocator<\
            EMP_XX_IF_TRACK_LEAKS(leak_allocator<)\
                sized_allocator<\
                    malloc_allocator\
                >\
                EMP_XX_IF_TRACK_LEAKS(>)\
            >\
        >

#define EMP_XX_TYPEDEF_MEM_ALLOCATOR()\
    typedef EMP_XX_MEM_ALLOCATOR() allocator

#define EMP_XX_TYPEDEF_MEM_ALIGNATOR()\
    typedef EMP_XX_MEM_ALIGNATOR() alignator

#define EMP_XX_FORWARD_MEM_ALLOCATOR()\
namespace emp { namespace mem {\
    class malloc_allocator;\
    template <typename T> class sized_allocator;\
    template <typename T> class leak_allocator;\
    template <typename T> class aligned_allocator;\
    template <typename T> class basic_allocator;\
    EMP_XX_TYPEDEF_MEM_ALLOCATOR();\
    EMP_XX_TYPEDEF_MEM_ALIGNATOR();\
} }

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#include "emp_xx_attribute.h"
#include "emp_xx_build.h"
#include "emp_xx_call.h"
#include "emp_xx_class.h"
#include "emp_xx_pragma.h"
#include "emp_xx_noop.h"

#include "emp_hh_stddef.h"
#include "emp_hh_stdint.h"

#include "emp_ast_assert.h"

//#include "emp_log_logger.h"

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#endif

