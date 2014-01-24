//-----------------------------------------------------------------------------
//
// File Name : emp_pp_not_equal.h
//
// Creation Date : Mon 11 Oct 2010 11:00:23 PM CEST
//
// Modification Date : mar. 26 nov. 2013 18:06:28 CET
//
// Created By : ksej - www.rgba8.org
//
// Description :
//
//-----------------------------------------------------------------------------
#ifndef EMP_PP_NOT_EQUAL_H
#define EMP_PP_NOT_EQUAL_H

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#include "emp_pp_if_else.h"
#include "emp_pp_token.h"

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#define EMP_PP_NOT_EQUAL(x_Left, x_Right) EMP_PP_NOT_EQUAL_IMP(x_Left, x_Right)
#define EMP_PP_NOT_EQUAL_IMP(x_Left, x_Right)\
EMP_PP_TOKEN(\
    EMP_PP_NOT_EQUAL_CHECK_,\
    EMP_PP_NOT_EQUAL_ ## x_Left(0, EMP_PP_NOT_EQUAL_ ## x_Right))

#define EMP_PP_NOT_EQUAL_CHECK_EMP_PP_UNDEFINED 1
#define EMP_PP_NOT_EQUAL_CHECK_EMP_PP_NOT_EQUAL_0(x_Condition, x_Right) 0
#define EMP_PP_NOT_EQUAL_CHECK_EMP_PP_NOT_EQUAL_1(x_Condition, x_Right) 0
#define EMP_PP_NOT_EQUAL_CHECK_EMP_PP_NOT_EQUAL_2(x_Condition, x_Right) 0
#define EMP_PP_NOT_EQUAL_CHECK_EMP_PP_NOT_EQUAL_3(x_Condition, x_Right) 0
#define EMP_PP_NOT_EQUAL_CHECK_EMP_PP_NOT_EQUAL_4(x_Condition, x_Right) 0
#define EMP_PP_NOT_EQUAL_CHECK_EMP_PP_NOT_EQUAL_5(x_Condition, x_Right) 0
#define EMP_PP_NOT_EQUAL_CHECK_EMP_PP_NOT_EQUAL_6(x_Condition, x_Right) 0
#define EMP_PP_NOT_EQUAL_CHECK_EMP_PP_NOT_EQUAL_7(x_Condition, x_Right) 0
#define EMP_PP_NOT_EQUAL_CHECK_EMP_PP_NOT_EQUAL_8(x_Condition, x_Right) 0
#define EMP_PP_NOT_EQUAL_CHECK_EMP_PP_NOT_EQUAL_9(x_Condition, x_Right) 0
#define EMP_PP_NOT_EQUAL_CHECK_EMP_PP_NOT_EQUAL_10(x_Condition, x_Right) 0
#define EMP_PP_NOT_EQUAL_CHECK_EMP_PP_NOT_EQUAL_11(x_Condition, x_Right) 0
#define EMP_PP_NOT_EQUAL_CHECK_EMP_PP_NOT_EQUAL_12(x_Condition, x_Right) 0
#define EMP_PP_NOT_EQUAL_CHECK_EMP_PP_NOT_EQUAL_13(x_Condition, x_Right) 0
#define EMP_PP_NOT_EQUAL_CHECK_EMP_PP_NOT_EQUAL_14(x_Condition, x_Right) 0
#define EMP_PP_NOT_EQUAL_CHECK_EMP_PP_NOT_EQUAL_15(x_Condition, x_Right) 0
#define EMP_PP_NOT_EQUAL_CHECK_EMP_PP_NOT_EQUAL_16(x_Condition, x_Right) 0
#define EMP_PP_NOT_EQUAL_CHECK_EMP_PP_NOT_EQUAL_17(x_Condition, x_Right) 0
#define EMP_PP_NOT_EQUAL_CHECK_EMP_PP_NOT_EQUAL_18(x_Condition, x_Right) 0
#define EMP_PP_NOT_EQUAL_CHECK_EMP_PP_NOT_EQUAL_19(x_Condition, x_Right) 0
#define EMP_PP_NOT_EQUAL_CHECK_EMP_PP_NOT_EQUAL_20(x_Condition, x_Right) 0
#define EMP_PP_NOT_EQUAL_CHECK_EMP_PP_NOT_EQUAL_21(x_Condition, x_Right) 0
#define EMP_PP_NOT_EQUAL_CHECK_EMP_PP_NOT_EQUAL_22(x_Condition, x_Right) 0
#define EMP_PP_NOT_EQUAL_CHECK_EMP_PP_NOT_EQUAL_23(x_Condition, x_Right) 0
#define EMP_PP_NOT_EQUAL_CHECK_EMP_PP_NOT_EQUAL_24(x_Condition, x_Right) 0
#define EMP_PP_NOT_EQUAL_CHECK_EMP_PP_NOT_EQUAL_25(x_Condition, x_Right) 0
#define EMP_PP_NOT_EQUAL_CHECK_EMP_PP_NOT_EQUAL_26(x_Condition, x_Right) 0
#define EMP_PP_NOT_EQUAL_CHECK_EMP_PP_NOT_EQUAL_27(x_Condition, x_Right) 0
#define EMP_PP_NOT_EQUAL_CHECK_EMP_PP_NOT_EQUAL_28(x_Condition, x_Right) 0
#define EMP_PP_NOT_EQUAL_CHECK_EMP_PP_NOT_EQUAL_29(x_Condition, x_Right) 0
#define EMP_PP_NOT_EQUAL_CHECK_EMP_PP_NOT_EQUAL_30(x_Condition, x_Right) 0
#define EMP_PP_NOT_EQUAL_CHECK_EMP_PP_NOT_EQUAL_31(x_Condition, x_Right) 0
#define EMP_PP_NOT_EQUAL_CHECK_EMP_PP_NOT_EQUAL_32(x_Condition, x_Right) 0

#define EMP_PP_NOT_EQUAL_0(x_Condition, x_Right)\
EMP_PP_IF_ELSE(x_Condition, EMP_PP_UNDEFINED, x_Right(1, EMP_PP_UNDEFINED))

#define EMP_PP_NOT_EQUAL_1(x_Condition, x_Right)\
EMP_PP_IF_ELSE(x_Condition, EMP_PP_UNDEFINED, x_Right(1, EMP_PP_UNDEFINED))

#define EMP_PP_NOT_EQUAL_2(x_Condition, x_Right)\
EMP_PP_IF_ELSE(x_Condition, EMP_PP_UNDEFINED, x_Right(1, EMP_PP_UNDEFINED))

#define EMP_PP_NOT_EQUAL_3(x_Condition, x_Right)\
EMP_PP_IF_ELSE(x_Condition, EMP_PP_UNDEFINED, x_Right(1, EMP_PP_UNDEFINED))

#define EMP_PP_NOT_EQUAL_4(x_Condition, x_Right)\
EMP_PP_IF_ELSE(x_Condition, EMP_PP_UNDEFINED, x_Right(1, EMP_PP_UNDEFINED))

#define EMP_PP_NOT_EQUAL_5(x_Condition, x_Right)\
EMP_PP_IF_ELSE(x_Condition, EMP_PP_UNDEFINED, x_Right(1, EMP_PP_UNDEFINED))

#define EMP_PP_NOT_EQUAL_6(x_Condition, x_Right)\
EMP_PP_IF_ELSE(x_Condition, EMP_PP_UNDEFINED, x_Right(1, EMP_PP_UNDEFINED))

#define EMP_PP_NOT_EQUAL_7(x_Condition, x_Right)\
EMP_PP_IF_ELSE(x_Condition, EMP_PP_UNDEFINED, x_Right(1, EMP_PP_UNDEFINED))

#define EMP_PP_NOT_EQUAL_8(x_Condition, x_Right)\
EMP_PP_IF_ELSE(x_Condition, EMP_PP_UNDEFINED, x_Right(1, EMP_PP_UNDEFINED))

#define EMP_PP_NOT_EQUAL_9(x_Condition, x_Right)\
EMP_PP_IF_ELSE(x_Condition, EMP_PP_UNDEFINED, x_Right(1, EMP_PP_UNDEFINED))

#define EMP_PP_NOT_EQUAL_10(x_Condition, x_Right)\
EMP_PP_IF_ELSE(x_Condition, EMP_PP_UNDEFINED, x_Right(1, EMP_PP_UNDEFINED))

#define EMP_PP_NOT_EQUAL_11(x_Condition, x_Right)\
EMP_PP_IF_ELSE(x_Condition, EMP_PP_UNDEFINED, x_Right(1, EMP_PP_UNDEFINED))

#define EMP_PP_NOT_EQUAL_12(x_Condition, x_Right)\
EMP_PP_IF_ELSE(x_Condition, EMP_PP_UNDEFINED, x_Right(1, EMP_PP_UNDEFINED))

#define EMP_PP_NOT_EQUAL_13(x_Condition, x_Right)\
EMP_PP_IF_ELSE(x_Condition, EMP_PP_UNDEFINED, x_Right(1, EMP_PP_UNDEFINED))

#define EMP_PP_NOT_EQUAL_14(x_Condition, x_Right)\
EMP_PP_IF_ELSE(x_Condition, EMP_PP_UNDEFINED, x_Right(1, EMP_PP_UNDEFINED))

#define EMP_PP_NOT_EQUAL_15(x_Condition, x_Right)\
EMP_PP_IF_ELSE(x_Condition, EMP_PP_UNDEFINED, x_Right(1, EMP_PP_UNDEFINED))

#define EMP_PP_NOT_EQUAL_16(x_Condition, x_Right)\
EMP_PP_IF_ELSE(x_Condition, EMP_PP_UNDEFINED, x_Right(1, EMP_PP_UNDEFINED))

#define EMP_PP_NOT_EQUAL_17(x_Condition, x_Right)\
EMP_PP_IF_ELSE(x_Condition, EMP_PP_UNDEFINED, x_Right(1, EMP_PP_UNDEFINED))

#define EMP_PP_NOT_EQUAL_18(x_Condition, x_Right)\
EMP_PP_IF_ELSE(x_Condition, EMP_PP_UNDEFINED, x_Right(1, EMP_PP_UNDEFINED))

#define EMP_PP_NOT_EQUAL_19(x_Condition, x_Right)\
EMP_PP_IF_ELSE(x_Condition, EMP_PP_UNDEFINED, x_Right(1, EMP_PP_UNDEFINED))

#define EMP_PP_NOT_EQUAL_20(x_Condition, x_Right)\
EMP_PP_IF_ELSE(x_Condition, EMP_PP_UNDEFINED, x_Right(1, EMP_PP_UNDEFINED))

#define EMP_PP_NOT_EQUAL_21(x_Condition, x_Right)\
EMP_PP_IF_ELSE(x_Condition, EMP_PP_UNDEFINED, x_Right(1, EMP_PP_UNDEFINED))

#define EMP_PP_NOT_EQUAL_22(x_Condition, x_Right)\
EMP_PP_IF_ELSE(x_Condition, EMP_PP_UNDEFINED, x_Right(1, EMP_PP_UNDEFINED))

#define EMP_PP_NOT_EQUAL_23(x_Condition, x_Right)\
EMP_PP_IF_ELSE(x_Condition, EMP_PP_UNDEFINED, x_Right(1, EMP_PP_UNDEFINED))

#define EMP_PP_NOT_EQUAL_24(x_Condition, x_Right)\
EMP_PP_IF_ELSE(x_Condition, EMP_PP_UNDEFINED, x_Right(1, EMP_PP_UNDEFINED))

#define EMP_PP_NOT_EQUAL_25(x_Condition, x_Right)\
EMP_PP_IF_ELSE(x_Condition, EMP_PP_UNDEFINED, x_Right(1, EMP_PP_UNDEFINED))

#define EMP_PP_NOT_EQUAL_26(x_Condition, x_Right)\
EMP_PP_IF_ELSE(x_Condition, EMP_PP_UNDEFINED, x_Right(1, EMP_PP_UNDEFINED))

#define EMP_PP_NOT_EQUAL_27(x_Condition, x_Right)\
EMP_PP_IF_ELSE(x_Condition, EMP_PP_UNDEFINED, x_Right(1, EMP_PP_UNDEFINED))

#define EMP_PP_NOT_EQUAL_28(x_Condition, x_Right)\
EMP_PP_IF_ELSE(x_Condition, EMP_PP_UNDEFINED, x_Right(1, EMP_PP_UNDEFINED))

#define EMP_PP_NOT_EQUAL_29(x_Condition, x_Right)\
EMP_PP_IF_ELSE(x_Condition, EMP_PP_UNDEFINED, x_Right(1, EMP_PP_UNDEFINED))

#define EMP_PP_NOT_EQUAL_30(x_Condition, x_Right)\
EMP_PP_IF_ELSE(x_Condition, EMP_PP_UNDEFINED, x_Right(1, EMP_PP_UNDEFINED))

#define EMP_PP_NOT_EQUAL_31(x_Condition, x_Right)\
EMP_PP_IF_ELSE(x_Condition, EMP_PP_UNDEFINED, x_Right(1, EMP_PP_UNDEFINED))

#define EMP_PP_NOT_EQUAL_32(x_Condition, x_Right)\
EMP_PP_IF_ELSE(x_Condition, EMP_PP_UNDEFINED, x_Right(1, EMP_PP_UNDEFINED))

#define EMP_PP_NOT_EQUAL_33(x_Condition, x_Right)\
    EMP_PP_ERROR_EMP_PP_NOT_EQUAL_OVERFLOW

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#endif

