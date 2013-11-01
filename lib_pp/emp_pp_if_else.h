//-----------------------------------------------------------------------------
//
// File Name : emp_pp_if_else.h
//
// Creation Date : Mon 11 Oct 2010 10:55:51 PM CEST
//
// Modification Date : ven. 01 nov. 2013 12:04:04 CET
//
// Created By : rgba8 (ksej) - www.empathy.fr
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

