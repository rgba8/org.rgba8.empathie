//-----------------------------------------------------------------------------
//
// File Name : emp_tt_const_return.h
//
// Creation Date : Fri 28 Jan 2011 02:13:05 PM CET
//
// Modification Date : mar. 26 nov. 2013 18:09:59 CET
//
// Created By : ksej - www.rgba8.org
//
// Description :
//
//-----------------------------------------------------------------------------
#ifndef EMP_TT_CONST_RETURN_H
#define EMP_TT_CONST_RETURN_H

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#include "emp_tt_const_param.h"
#include "emp_tt_if_else.h"
#include "emp_tt_is_fundamental.h"
#include "emp_tt_is_pointer.h"
#include "emp_tt_is_reference.h"
#include "emp_tt_or.h"
#include "emp_tt_try_add_const.h"
#include "emp_tt_try_add_reference.h"
#include "emp_tt_try_remove_const.h"

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
namespace emp { namespace tt {

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
template <typename T>
EMP_NOINSTANCE_CLASS(const_return)
public:
    typedef typename emp::tt::if_else
    <
        emp::tt::or
        <
            emp::tt::is_fundamental<T>::value,
            emp::tt::is_pointer<T>::value
        >::value,
        typename emp::tt::try_remove_const<T>::type,
        typename emp::tt::if_else
        <
            emp::tt::is_reference<T>::value,
            typename emp::tt::const_param<T>::type,
            typename emp::tt::try_add_reference<
                typename emp::tt::try_add_const<T>::type
            >::type
        >::type
    >::type type;
};

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
} }

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#endif

