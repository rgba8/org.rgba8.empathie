//-----------------------------------------------------------------------------
//
// File Name : emp_pp_if_not.h
//
// Creation Date : Mon 11 Oct 2010 10:53:25 PM CEST
//
// Modification Date : Sun Jan 12 23:31:59 2014
//
// Created By : luh - www.rgba8.org
//
// Description :
//
//-----------------------------------------------------------------------------
#ifndef EMP_PP_IF_NOT_H
#define EMP_PP_IF_NOT_H

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#include "emp_pp_bool.h"
#include "emp_pp_token.h"

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#define EMP_PP_IF_NOT(x_Condition, x_Then) EMP_PP_IF_NOT_IMP(x_Condition, x_Then)
#define EMP_PP_IF_NOT_IMP(x_Condition, x_Then)\
    EMP_PP_TOKEN(EMP_PP_IF_NOT_IMP_, EMP_PP_BOOL(x_Condition))(x_Then)

#define EMP_PP_IF_NOT_IMP_0(x_Then) x_Then
#define EMP_PP_IF_NOT_IMP_1(x_Then)

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#endif

