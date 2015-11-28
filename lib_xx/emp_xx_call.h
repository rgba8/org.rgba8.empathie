//-----------------------------------------------------------------------------
// emp_xx_call.h - @rgba8.org
//-----------------------------------------------------------------------------
#ifndef EMP_XX_CALL_H
#define EMP_XX_CALL_H

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#include "emp_xx_vaargs.h"

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#include "emp_pp_bool.h"
#include "emp_pp_equal.h"

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#if defined EMP_XX_DEBUG
#define EMP_XX_ERROR_HOOK
#endif

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#ifdef EMP_XX_ERROR_HOOK
#define EMP_XX_HOOK(x_Error) emp::xx::error_hook(x_Error);
namespace emp { namespace xx {
template <typename T> EMP_INLINE EMP_RETURN T error_hook(T const& a_tError);
template <typename T> EMP_INLINE EMP_RETURN T error_hook(T const& a_tError)
{ return a_tError; }
} }
#else
#define EMP_XX_HOOK(x_Error) x_Error
#endif

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#define EMP_RET_X_IF_X_1(x_Test, x_Return, x_Call)\
EMP_XX_MULTI_STATEMENT_BEGIN()\
if ((x_Call) x_Test)\
{\
    EMP_LOG_ERROR(EMP_PP_STRING(x_Call));\
    return EMP_XX_HOOK(x_Return);\
}\
EMP_XX_MULTI_STATEMENT_END()

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#define EMP_RET_X_IF_X_0(x_Test, x_Return, x_Call, ...)\
EMP_XX_MULTI_STATEMENT_BEGIN()\
if ((x_Call) x_Test)\
{\
    EMP_LOG_ERROR(EMP_PP_STRING(x_Call));\
    EMP_LOG_ERROR(__VA_ARGS__);\
    return EMP_XX_HOOK(x_Return);\
}\
EMP_XX_MULTI_STATEMENT_END()

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#define EMP_RET_X_IF_X(x_Test, x_Return, ...)\
    EMP_PP_CAT(EMP_RET_X_IF_X_, EMP_PP_BOOL(EMP_PP_EQUAL(1, EMP_VAARGS_COUNT(__VA_ARGS__))))(x_Test, x_Return, __VA_ARGS__)

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#define EMP_RET_X_IF(         ...)  EMP_RET_X_IF_X( == true  , __VA_ARGS__ )
#define EMP_RET_X_IF_NOT(     ...)  EMP_RET_X_IF_X( == false , __VA_ARGS__ )

#define EMP_RET_FALSE_IF(     ...)  EMP_RET_X_IF(     false , __VA_ARGS__ )
#define EMP_RET_FALSE_IF_NOT( ...)  EMP_RET_X_IF_NOT( false , __VA_ARGS__ )

#define EMP_RET_NULL_IF(      ...)  EMP_RET_X_IF(     nullptr , __VA_ARGS__ )
#define EMP_RET_NULL_IF_NOT(  ...)  EMP_RET_X_IF_NOT( nullptr , __VA_ARGS__ )

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#endif

