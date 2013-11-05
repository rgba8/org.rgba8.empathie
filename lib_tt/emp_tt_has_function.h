//-----------------------------------------------------------------------------
//
// File Name : emp_tt_has_function.h
//
// Creation Date : mer. 12 sept. 2012 12:03:15 CEST
//
// Modification Date : mar. 05 nov. 2013 20:07:33 CET
//
// Created By : rgba8 (ksej) - www.empathy.fr
//
// Description :
//
//-----------------------------------------------------------------------------
#ifndef EMP_TT_HAS_FUNCTION_H
#define EMP_TT_HAS_FUNCTION_H

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#include "emp_pp_forward.h"
#include "emp_pp_token.h"

#include "emp_hh_stddef.h"

#include "emp_tt_constant.h"
#include "emp_tt_has_base.h"

#include "emp_xx_nocopy_class.h"
#include "emp_xx_noinstance_class.h"
#include "emp_xx_nullptr.h"

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#define EMP_TT_HAS_FUNCTION(x_Function, x_Signature)\
template <typename T>\
EMP_NOINSTANCE_CLASS(EMP_PP_TOKEN(has_, x_Function))\
private:\
    template <typename S, x_Signature>\
    EMP_NOCOPY_CLASS(signature_t)\
    };\
    typedef char yes_type_c;\
    typedef struct { char m_acNo[2]; } no_type_c;\
    template <typename V>\
    static yes_type_c test_t(signature_t<V, &V::x_Function>*);\
    template <typename V>\
    static no_type_c test_t(...);\
public:\
    EMP_TT_CONSTANT(\
        size_t, value, sizeof(test_t<T>(nullptr)) == sizeof(yes_type_c) ||\
        EMP_PP_TOKEN(has_, x_Function)<\
        EMP_PP_FORWARD_3(\
            typename emp::tt::get_base_t\
                <T, void, emp::tt::has_base_t<T>::value>::type)>::value);\
};\
template <>\
EMP_NOINSTANCE_CLASS(EMP_PP_TOKEN(has_, x_Function<void>))\
public:\
    EMP_TT_CONSTANT(size_t, value, false);\
};\

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#endif

