//-----------------------------------------------------------------------------
//
// File Name : emp_pp_if_else.h
//
// Creation Date : Mon 11 Oct 2010 10:55:51 PM CEST
//
// Modification Date : mar. 26 nov. 2013 18:05:12 CET
//
// Created By : ksej - www.rgba8.org
//
// Description :
//
//-----------------------------------------------------------------------------
#ifndef EMP_PP_IF_ELSE_H
#define EMP_PP_IF_ELSE_H

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#include "emp_pp_bool.h"
#include "emp_pp_token.h"

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#define EMP_PP_IF_ELSE(x_Condition, x_Then, x_Else)\
    EMP_PP_IF_ELSE_IMP(x_Condition, x_Then, x_Else)
#define EMP_PP_IF_ELSE_IMP(x_Condition, x_Then, x_Else)\
    EMP_PP_TOKEN(EMP_PP_IF_ELSE_IMP_,\
        EMP_PP_BOOL(x_Condition))(x_Then, x_Else)

#define EMP_PP_IF_ELSE_IMP_0(x_Then, x_Else) x_Else
#define EMP_PP_IF_ELSE_IMP_1(x_Then, x_Else) x_Then

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#endif

