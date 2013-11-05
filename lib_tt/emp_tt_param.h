//-----------------------------------------------------------------------------
//
// File Name : emp_tt_param.h
//
// Creation Date : Thu 11 Nov 2010 01:14:30 PM CET
//
// Modification Date : mar. 05 nov. 2013 20:08:59 CET
//
// Created By : rgba8 (ksej) - www.empathy.fr
//
// Description :
//
//-----------------------------------------------------------------------------
#ifndef EMP_TT_PARAM_H
#define EMP_TT_PARAM_H

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#include "emp_tt_try_add_const.h"
#include "emp_tt_try_add_reference.h"
#include "emp_tt_if_else.h"
#include "emp_tt_is_param.h"

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
namespace emp { namespace tt {

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
template <typename T>
EMP_NOINSTANCE_CLASS(param)
public:
    typedef typename emp::tt::if_else
    <
        emp::tt::is_param<T>::value,
        typename emp::tt::try_add_const<T>::type,
        typename emp::tt::try_add_reference<
            typename emp::tt::try_add_const<T>::type
        >::type
    >::type type;
};

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
} }

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#include "emp_tt_assert.h"
#include "emp_tt_are_equal.h"

EMP_STATIC_ASSERT(emp::tt::is_param<int>::value);

EMP_STATIC_ASSERT((emp::tt::are_equal<
    emp::tt::try_add_const<int>::type,
    int const>::value));


EMP_STATIC_ASSERT((emp::tt::are_equal<
    emp::tt::param<int>::type,
    int const>::value));

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#endif

