//-----------------------------------------------------------------------------
//
// File Name : emp_tt_has_function.h
//
// Creation Date : mer. 12 sept. 2012 12:03:15 CEST
//
// Modification Date : lun. 29 juin 2015 20:05:28 CEST
//
// Created By : ksej - www.rgba8.org
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

#include "emp_tt_has_base.h"

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
    static const size_t value = sizeof(test_t<T>(nullptr)) == sizeof(yes_type_c) ||\
        EMP_PP_TOKEN(has_, x_Function) <\
        EMP_PP_FORWARD_3(\
            typename emp::tt::get_base_t\
                <T, void, emp::tt::has_base_t<T>::value>::type)>::value;\
};\
template <>\
EMP_NOINSTANCE_CLASS(EMP_PP_TOKEN(has_, x_Function<void>))\
public:\
    static const bool value = false;\
};\

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#endif

