//-----------------------------------------------------------------------------
//
// File Name : emp_tt_const_param.h
//
// Creation Date : Thu 25 Nov 2010 02:31:02 PM CET
//
// Modification Date : mar. 05 nov. 2013 20:07:13 CET
//
// Created By : rgba8 (ksej) - www.empathy.fr
//
// Description :
//
//-----------------------------------------------------------------------------
#ifndef EMP_TT_CONST_PARAM_H
#define EMP_TT_CONST_PARAM_H

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#include "emp_tt_if_else.h"
#include "emp_tt_is_pointer.h"
#include "emp_tt_param.h"
#include "emp_tt_try_add_const.h"
#include "emp_tt_try_add_pointer.h"
#include "emp_tt_try_add_reference.h"
#include "emp_tt_try_remove_pointer.h"
#include "emp_tt_try_remove_reference.h"

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
namespace emp { namespace tt {

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
template <typename T>
EMP_NOINSTANCE_CLASS(const_param_impl)
public:
    typedef
    typename emp::tt::if_else
    <
        emp::tt::is_pointer<T>::value,
        typename emp::tt::try_add_const<
            typename emp::tt::try_add_pointer<
                typename emp::tt::try_impl<
                    typename emp::tt::try_remove_pointer<T>::type,
                    emp::tt::is_pointer<T>::value,
                    emp::tt::const_param_impl
                >::type
            >::type
        >::type,
        typename emp::tt::if_else
        <
            emp::tt::is_reference<T>::value,
            typename emp::tt::try_add_reference<
                typename emp::tt::try_impl<
                    typename emp::tt::try_remove_reference<T>::type,
                    emp::tt::is_reference<T>::value,
                    emp::tt::const_param_impl
                >::type
            >::type,
            typename emp::tt::try_add_const<T>::type
        >::type
    >::type type;
};

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
template <typename T>
EMP_NOINSTANCE_CLASS(const_param)
public:
    typedef typename emp::tt::param<
        typename emp::tt::const_param_impl<T>::type
    >::type type;
};


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
} }

EMP_STATIC_ASSERT_TYPE_EQUAL(emp::tt::const_param<int>::type, int const);

EMP_STATIC_ASSERT_TYPE_EQUAL(   emp::tt::const_param<int*>::type,
                                int const* const);

EMP_STATIC_ASSERT_TYPE_EQUAL(   emp::tt::const_param<int**>::type,
                                int const* const* const);

EMP_STATIC_ASSERT_TYPE_EQUAL(   emp::tt::const_param<int**&>::type,
                                int const* const* const&);

EMP_STATIC_ASSERT_TYPE_EQUAL(   emp::tt::const_param<char const* const>::type,
                                char const* const);

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#endif

