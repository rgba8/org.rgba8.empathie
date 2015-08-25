//-----------------------------------------------------------------------------
// @rgba8.org
//-----------------------------------------------------------------------------
#ifndef EMP_XX_CALL_H
#define EMP_XX_CALL_H

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#define EMP_RET_X_IF_X(x_Call, x_Test, x_Return)\
if ((x_Call) x_Test)\
{\
    EMP_LOG_ERROR(EMP_PP_STRING(x_Call));\
    return x_Return;\
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#define EMP_RET_FMT_X_IF_X(x_Call, x_Test, x_Return, ...)\
if ((x_Call) x_Test)\
{\
    EMP_LOG_ERROR(EMP_PP_STRING(x_Call));\
    EMP_LOG_ERROR(__VA_ARGS__);\
    return x_Return;\
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#define EMP_RET_X_IF(         x_Call, x_Return)      EMP_RET_X_IF_X(       x_Call, == true  , x_Return)
#define EMP_RET_X_IF_NOT(     x_Call, x_Return)      EMP_RET_X_IF_X(       x_Call, == false , x_Return)
#define EMP_RET_FALSE_IF(       x_Call)              EMP_RET_X_IF(         x_Call, false   )
#define EMP_RET_FALSE_IF_NOT(   x_Call)              EMP_RET_X_IF_NOT(     x_Call, false   )
#define EMP_RET_NULL_IF(        x_Call)              EMP_RET_X_IF(         x_Call, nullptr )
#define EMP_RET_NULL_IF_NOT(    x_Call)              EMP_RET_X_IF_NOT(     x_Call, nullptr )

#define EMP_RET_FMT_X_IF(     x_Call, x_Return, ...) EMP_RET_FMT_X_IF_X(   x_Call, == true  , x_Return, __VA_ARGS__)
#define EMP_RET_FMT_X_IF_NOT( x_Call, x_Return, ...) EMP_RET_FMT_X_IF_X(   x_Call, == false , x_Return, __VA_ARGS__)
#define EMP_RET_FMT_FALSE_IF(       x_Call, ...)     EMP_RET_FMT_X_IF(     x_Call, false   , __VA_ARGS__ )
#define EMP_RET_FMT_FALSE_IF_NOT(   x_Call, ...)     EMP_RET_FMT_X_IF_NOT( x_Call, false   , __VA_ARGS__ )
#define EMP_RET_FMT_NULL_IF(        x_Call, ...)     EMP_RET_FMT_X_IF(     x_Call, nullptr , __VA_ARGS__ )
#define EMP_RET_FMT_NULL_IF_NOT(    x_Call, ...)     EMP_RET_FMT_X_IF_NOT( x_Call, nullptr , __VA_ARGS__ )

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#endif

