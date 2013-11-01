//-----------------------------------------------------------------------------
//
// File Name : emp_pp_if.h
//
// Creation Date : Mon 11 Oct 2010 10:53:25 PM CEST
//
// Modification Date : ven. 01 nov. 2013 10:23:27 CET
//
// Created By : rgba8 (ksej) - www.empathy.fr
//
// Description :
//
//-----------------------------------------------------------------------------
#ifndef EMP_PP_IF_H
#define EMP_PP_IF_H

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#include "emp_pp_bool.h"
#include "emp_pp_token.h"

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#define EMP_PP_IF(x_Condition, x_Then) EMP_PP_IF_IMP(x_Condition, x_Then)
#define EMP_PP_IF_IMP(x_Condition, x_Then)\
    EMP_PP_TOKEN(EMP_PP_IF_IMP_, EMP_PP_BOOL(x_Condition))(x_Then)

#define EMP_PP_IF_IMP_0(x_Then)
#define EMP_PP_IF_IMP_1(x_Then) x_Then

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#endif

