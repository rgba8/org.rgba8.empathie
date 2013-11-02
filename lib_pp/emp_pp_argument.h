//-----------------------------------------------------------------------------
//
// File Name : emp_pp_argument.h
//
// Creation Date : Tue 14 Sep 2010 05:32:26 PM CEST
//
// Modification Date : sam. 02 nov. 2013 19:30:37 CET
//
// Created By : rgba8 (ksej) - www.empathy.fr
//
// Description :
//
//-----------------------------------------------------------------------------
#ifndef EMP_PP_ARGUMENT_H
#define EMP_PP_ARGUMENT_H

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#include "emp_pp_and.h"
#include "emp_pp_comma_if.h"
#include "emp_pp_for.h"
#include "emp_pp_inc.h"
#include "emp_pp_not_equal.h"
#include "emp_pp_token.h"

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#define EMP_PP_TYPE(x_Index)\
    EMP_PP_TOKEN(t_tType, x_Index)

#define EMP_PP_TYPEDEF(x_Index)\
    EMP_PP_TOKEN(type, x_Index)

#define EMP_PP_PARAMETER(x_Index)\
    EMP_PP_TOKEN(a_trParam, x_Index)

#define EMP_PP_ARGUMENT(x_Index)\
    EMP_PP_TYPE(x_Index) const& EMP_PP_PARAMETER(x_Index)

#define EMP_PP_MEMBER(x_Index)\
    EMP_PP_TOKEN(m_tValue, x_Index)

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#define EMP_PP_COMMA_IF_NOT_LAST(x_Depth, x_Index, x_Count)\
    EMP_PP_COMMA_IF(EMP_PP_NOT_EQUAL(EMP_PP_INC(x_Index), x_Count))

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#define EMP_PP_TEMPLATE_PARAMETER(x_Depth, x_Index, x_Count)\
    typename EMP_PP_TYPE(x_Index)\
    EMP_PP_COMMA_IF_NOT_LAST(x_Depth, x_Index, x_Count)

#define EMP_PP_TEMPLATE_PARAMETER_DEFAULT(x_Depth, x_Index, x_Count)\
    typename EMP_PP_TYPE(x_Index) = emp::tt::null\
    EMP_PP_COMMA_IF_NOT_LAST(x_Depth, x_Index, x_Count)

#define EMP_PP_TEMPLATE_ARGUMENT(x_Depth, x_Index, x_Count)\
    EMP_PP_TYPE(x_Index)\
    EMP_PP_COMMA_IF_NOT_LAST(x_Depth, x_Index, x_Count)

#define EMP_PP_TEMPLATE_ARGUMENT_CONST(x_Depth, x_Index, x_Count)\
    typename emp::tt::const_param<EMP_PP_TYPE(x_Index)>::type\
    EMP_PP_COMMA_IF_NOT_LAST(x_Depth, x_Index, x_Count)

#define EMP_PP_TEMPLATE_LIST_BEGIN(x_Depth, x_Index, x_Count)\
    emp::tt::list<EMP_PP_TYPE(x_Index),

#define EMP_PP_TEMPLATE_LIST_END(x_Depth, x_Index, x_Count)\
    >

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#define EMP_PP_FUNCTION_PARAMETER(x_Depth, x_Index, x_Count)\
    EMP_PP_ARGUMENT(x_Index)\
    EMP_PP_COMMA_IF_NOT_LAST(x_Depth, x_Index, x_Count)

#define EMP_PP_FUNCTION_ARGUMENT(x_Depth, x_Index, x_Count)\
    EMP_PP_PARAMETER(x_Index)\
    EMP_PP_COMMA_IF_NOT_LAST(x_Depth, x_Index, x_Count)

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#define EMP_PP_CLASS_TYPEDEF(x_Depth, x_Index, x_Count)\
    typedef EMP_PP_TYPE(x_Index) EMP_PP_TYPEDEF(x_Index);

#define EMP_PP_CLASS_MEMBER(x_Depth, x_Index, x_Count)\
    EMP_PP_TYPE(x_Index) EMP_PP_MEMBER(x_Index);

#define EMP_PP_CLASS_CTOR(x_Depth, x_Index, x_Count)\
    EMP_PP_MEMBER(x_Index)()\
    EMP_PP_COMMA_IF_NOT_LAST(x_Depth, x_Index, x_Count)

#define EMP_PP_CLASS_INIT(x_Depth, x_Index, x_Count)\
    EMP_PP_MEMBER(x_Index)(EMP_PP_PARAMETER(x_Index))\
    EMP_PP_COMMA_IF_NOT_LAST(x_Depth, x_Index, x_Count)

#define EMP_PP_CLASS_ARGUMENT(x_Depth, x_Index, x_Count)\
    EMP_PP_MEMBER(x_Index)\
    EMP_PP_COMMA_IF_NOT_LAST(x_Depth, x_Index, x_Count)

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#define EMP_PP_FOR_ARGUMENTS(x_Depth, x_Count, x_Macro, x_Left, x_Right)\
    EMP_PP_COMMA_IF(EMP_PP_AND(x_Left, x_Count))\
    EMP_PP_TOKEN(EMP_PP_FOR_, x_Depth)(x_Depth, 0, x_Count, x_Macro)\
    EMP_PP_COMMA_IF(EMP_PP_AND(x_Right, x_Count))

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#endif

