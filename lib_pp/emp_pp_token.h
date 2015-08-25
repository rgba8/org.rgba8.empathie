//-----------------------------------------------------------------------------
// @rgba8.org
//-----------------------------------------------------------------------------
#ifndef EMP_PP_TOKEN_H
#define EMP_PP_TOKEN_H

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#define EMP_PP_TOKEN(x_Left, ...) EMP_PP_TOKEN_IMP(x_Left, __VA_ARGS__)
#define EMP_PP_TOKEN_IMP(x_Left, ...) x_Left ## __VA_ARGS__

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#define EMP_PP_TOKEN_3(x_a, x_b, x_c) EMP_PP_TOKEN_3_IMP(x_a, x_b, x_c)
#define EMP_PP_TOKEN_3_IMP(x_a, x_b, x_c) x_a ## x_b ## x_c

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#endif

