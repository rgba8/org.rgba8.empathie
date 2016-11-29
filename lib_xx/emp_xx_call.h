//-----------------------------------------------------------------------------
// emp_xx_call.h - @rgba8.org
//-----------------------------------------------------------------------------
#ifndef EMP_XX_CALL_H
#define EMP_XX_CALL_H

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#include "emp_pp_if_not.h"

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#if defined EMP_XX_DEBUG
#define EMP_XX_ERROR_HOOK
#endif

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#ifdef EMP_XX_ERROR_HOOK
#define EMP_XX_HOOK() emp::xx::error_hook();
namespace emp
{
    namespace xx
    {
        void error_hook(void);
    }
}
#else
#define EMP_XX_HOOK()
#endif

//#define EMP_XX_RELEASE_LOG

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//#if defined EMP_XX_LOG

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#define EMP_RET_X_IF_X_1(x_Test, x_Void, x_Return, x_Call)\
EMP_XX_MULTI_STATEMENT_BEGIN()\
if ((x_Call) x_Test)\
{\
    EMP_XX_IF_LOG(EMP_LOG_ERROR(EMP_PP_STRING(x_Call)));\
    EMP_XX_HOOK()\
    return EMP_PP_IF_NOT(x_Void, x_Return);\
}\
EMP_XX_MULTI_STATEMENT_END()

#define EMP_RET_X_IF_X_0(x_Test, x_Void, x_Return, x_Call, ...)\
EMP_XX_MULTI_STATEMENT_BEGIN()\
if ((x_Call) x_Test)\
{\
    EMP_XX_IF_LOG(EMP_LOG_ERROR(EMP_PP_STRING(x_Call)));\
    EMP_XX_IF_LOG(EMP_PP_FORWARD(EMP_LOG_ERROR(__VA_ARGS__)));\
    EMP_XX_HOOK()\
    return EMP_PP_IF_NOT(x_Void, x_Return);\
}\
EMP_XX_MULTI_STATEMENT_END()


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
/*#define EMP_FUCK_X_IF_X_1(x_Test, x_Void, x_Return, x_Call)\
EMP_XX_MULTI_STATEMENT_BEGIN()\
if ((x_Call) x_Test)\
{\
    EMP_XX_HOOK()\
    return EMP_PP_IF_NOT(x_Void, x_Return);\
}\
EMP_XX_MULTI_STATEMENT_END()

#define EMP_FUCK_X_IF_X_0(x_Test, x_Void, x_Return, x_Call, ...)\
EMP_XX_MULTI_STATEMENT_BEGIN()\
if ((x_Call) x_Test)\
{\
    EMP_XX_HOOK()\
    return EMP_PP_IF_NOT(x_Void, x_Return);\
}\
EMP_XX_MULTI_STATEMENT_END()*/


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
/*#else

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#define EMP_RET_X_IF_X_1(x_Test, x_Void, x_Return, x_Call)\
EMP_XX_MULTI_STATEMENT_BEGIN()\
if ((x_Call) x_Test) { return EMP_PP_IF_NOT(x_Void, x_Return); }\
EMP_XX_MULTI_STATEMENT_END()

#define EMP_RET_X_IF_X_0(x_Test, x_Void, x_Return, x_Call, ...)\
EMP_XX_MULTI_STATEMENT_BEGIN()\
if ((x_Call) x_Test) { return EMP_PP_IF_NOT(x_Void, x_Return); }\
EMP_XX_MULTI_STATEMENT_END()
*/
//#endif

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#define EMP_RET_X_IF_X(x_Test, x_Return, ...)\
    EMP_PP_FORWARD(EMP_PP_CAT(EMP_RET_X_IF_X_, EMP_PP_BOOL(EMP_PP_EQUAL(1, EMP_VAARGS_COUNT(__VA_ARGS__))))(x_Test, false, x_Return, __VA_ARGS__))

#define EMP_RET_IF_X(x_Test, ...)\
    EMP_PP_FORWARD(EMP_PP_CAT(EMP_RET_X_IF_X_, EMP_PP_BOOL(EMP_PP_EQUAL(1, EMP_VAARGS_COUNT(__VA_ARGS__))))(x_Test, true, void, __VA_ARGS__))

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#define EMP_RET_IF(           ...)  EMP_PP_FORWARD(EMP_RET_IF_X(== true  , __VA_ARGS__ ))
#define EMP_RET_IF_NOT(       ...)  EMP_PP_FORWARD(EMP_RET_IF_X(== false , __VA_ARGS__ ))

#define EMP_RET_X_IF(         ...)  EMP_PP_FORWARD(EMP_RET_X_IF_X(== true  , __VA_ARGS__ ))
#define EMP_RET_X_IF_NOT(     ...)  EMP_PP_FORWARD(EMP_RET_X_IF_X(== false , __VA_ARGS__ ))

#define EMP_RET_FALSE_IF(     ...)  EMP_PP_FORWARD(EMP_RET_X_IF(false , __VA_ARGS__ ))
#define EMP_RET_FALSE_IF_NOT( ...)  EMP_PP_FORWARD(EMP_RET_X_IF_NOT(false , __VA_ARGS__ ))

#define EMP_RET_NULL_IF(      ...)  EMP_PP_FORWARD(EMP_RET_X_IF(nullptr , __VA_ARGS__ ))
#define EMP_RET_NULL_IF_NOT(  ...)  EMP_PP_FORWARD(EMP_RET_X_IF_NOT(nullptr , __VA_ARGS__ ))

#define EMP_RET_NEG1_IF(      ...)  EMP_PP_FORWARD(EMP_RET_X_IF(-1 , __VA_ARGS__ ))
#define EMP_RET_NEG1_IF_NOT(  ...)  EMP_PP_FORWARD(EMP_RET_X_IF_NOT(-1 , __VA_ARGS__ ))

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
/*#define EMP_FUCK_X_IF_X(x_Test, x_Return, ...)\
    EMP_PP_FORWARD(EMP_PP_CAT(EMP_FUCK_X_IF_X_, EMP_PP_BOOL(EMP_PP_EQUAL(1, EMP_VAARGS_COUNT(__VA_ARGS__))))(x_Test, false, x_Return, __VA_ARGS__))

#define EMP_FUCK_IF_X(x_Test, ...)\
    EMP_PP_FORWARD(EMP_PP_CAT(EMP_FUCK_X_IF_X_, EMP_PP_BOOL(EMP_PP_EQUAL(1, EMP_VAARGS_COUNT(__VA_ARGS__))))(x_Test, true, void, __VA_ARGS__))

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#define EMP_FUCK_IF(           ...)  EMP_PP_FORWARD(EMP_FUCK_IF_X(== true  , __VA_ARGS__ ))
#define EMP_FUCK_IF_NOT(       ...)  EMP_PP_FORWARD(EMP_FUCK_IF_X(== false , __VA_ARGS__ ))

#define EMP_FUCK_X_IF(         ...)  EMP_PP_FORWARD(EMP_FUCK_X_IF_X(== true  , __VA_ARGS__ ))
#define EMP_FUCK_X_IF_NOT(     ...)  EMP_PP_FORWARD(EMP_FUCK_X_IF_X(== false , __VA_ARGS__ ))

#define EMP_FUCK_FALSE_IF(     ...)  EMP_PP_FORWARD(EMP_FUCK_X_IF(false , __VA_ARGS__ ))
#define EMP_FUCK_FALSE_IF_NOT( ...)  EMP_PP_FORWARD(EMP_FUCK_X_IF_NOT(false , __VA_ARGS__ ))

#define EMP_FUCK_NULL_IF(      ...)  EMP_PP_FORWARD(EMP_FUCK_X_IF(nullptr , __VA_ARGS__ ))
#define EMP_FUCK_NULL_IF_NOT(  ...)  EMP_PP_FORWARD(EMP_FUCK_X_IF_NOT(nullptr , __VA_ARGS__ ))

#define EMP_FUCK_NEG1_IF(      ...)  EMP_PP_FORWARD(EMP_FUCK_X_IF(-1 , __VA_ARGS__ ))
#define EMP_FUCK_NEG1_IF_NOT(  ...)  EMP_PP_FORWARD(EMP_FUCK_X_IF_NOT(-1 , __VA_ARGS__ ))*/

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#endif

