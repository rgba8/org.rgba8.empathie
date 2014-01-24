//-----------------------------------------------------------------------------
//
// File Name : emp_tt_return.h
//
// Creation Date : Wed 17 Nov 2010 12:36:25 PM CET
//
// Modification Date : mar. 26 nov. 2013 18:11:40 CET
//
// Created By : ksej - www.rgba8.org
//
// Description :
//
//-----------------------------------------------------------------------------
#ifndef EMP_TT_RETURN_H
#define EMP_TT_RETURN_H

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#include "emp_tt_if_else.h"
#include "emp_tt_is_fundamental.h"
#include "emp_tt_is_pointer.h"
#include "emp_tt_is_reference.h"
#include "emp_tt_or.h"
#include "emp_tt_try_remove_const.h"
#include "emp_tt_try_add_reference.h"

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
namespace emp { namespace tt {

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
template <typename T>
EMP_NOINSTANCE_CLASS(return_)
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
            T,
            typename emp::tt::try_add_reference<T>::type
        >::type
    >::type type;
};

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
} }

#ifndef EMP_TT_ASSERT_H
#include "emp_tt_assert.h"
#endif

EMP_STATIC_ASSERT_TYPE_EQUAL(emp::tt::return_<char>::type, char);
EMP_STATIC_ASSERT_TYPE_EQUAL(emp::tt::return_<char const>::type, char);
EMP_STATIC_ASSERT_TYPE_EQUAL(emp::tt::return_<char const*>::type, char const*);
EMP_STATIC_ASSERT_TYPE_EQUAL(   emp::tt::return_<char const* const>::type,
                                char const*);
EMP_STATIC_ASSERT_TYPE_EQUAL(emp::tt::return_<char&>::type, char&);
EMP_STATIC_ASSERT_TYPE_EQUAL(emp::tt::return_<char const&>::type, char const&);
EMP_STATIC_ASSERT_TYPE_EQUAL(
                            emp::tt::return_<emp::tt::return_<char> >::type,
                            emp::tt::return_<char>&);

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#endif

