//-----------------------------------------------------------------------------
//
// File Name : emp_tt_dereference.h
//
// Creation Date : Tue 23 Nov 2010 11:42:25 AM CET
//
// Modification Date : mar. 26 nov. 2013 18:10:03 CET
//
// Created By : ksej - www.rgba8.org
//
// Description :
//
//-----------------------------------------------------------------------------
#ifndef EMP_TT_DEREFERENCE_H
#define EMP_TT_DEREFERENCE_H

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#include "emp_tt_if_else.h"
#include "emp_tt_is_pointer.h"
#include "emp_tt_is_reference.h"
#include "emp_tt_try_add_pointer.h"
#include "emp_tt_try_add_reference.h"
#include "emp_tt_try_remove_const.h"
#include "emp_tt_try_remove_pointer.h"
#include "emp_tt_try_remove_reference.h"
#include "emp_tt_try_remove_volatile.h"

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#include "emp_xx_noinstance_class.h"
#include "emp_xx_return.h"

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
namespace emp { namespace tt {

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
template <typename T>
EMP_NOINSTANCE_CLASS(dereference)
public:
    typedef typename emp::tt::if_else
    <
        emp::tt::is_reference<T>::value,
        typename emp::tt::if_else
        <
            emp::tt::is_pointer<
                typename emp::tt::try_remove_reference<T>::type
            >::value,
            typename emp::tt::try_remove_const<
                typename emp::tt::try_remove_volatile<
                    typename emp::tt::try_remove_reference<T>::type
                >::type
            >::type,
            T
        >::type,
        typename emp::tt::if_else<
            emp::tt::is_pointer<T>::value,
            typename emp::tt::try_remove_const<
                typename emp::tt::try_remove_volatile<T>::type
            >::type,
            typename emp::tt::add_reference<T>::type
        >::type
    >::type timpl;

    typedef typename emp::tt::try_add_reference<
        typename emp::tt::try_remove_pointer<timpl>::type
    >::type treturn;

    typedef typename emp::tt::if_else
    <
        emp::tt::is_reference<T>::value,
        T,
        typename emp::tt::add_reference<T>::type
    >::type tparam;

    static treturn apply(tparam a_rtValue);
};

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
template <typename T>
class dereference_impl;

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
template <typename  T>
EMP_NOINSTANCE_CLASS(dereference_impl<T&>)
public:
    static EMP_RETURN T& apply(T& a_rValue) { return a_rValue; }
};

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
template <typename T>
EMP_NOINSTANCE_CLASS(dereference_impl<T*>)
public:
    static EMP_RETURN T& apply(T* const a_pValue)
    { return emp::tt::dereference<T>::apply(*a_pValue); }
};

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
template <typename T>
EMP_RETURN typename dereference<T>::treturn dereference<T>::apply(
                                    typename dereference<T>::tparam a_rtValue)
{ return dereference_impl<timpl>::apply(a_rtValue); }

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
} }

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

#ifndef EMP_TT_ASSERT_H
#include "emp_tt_assert.h"
#endif

EMP_STATIC_ASSERT_TYPE_EQUAL(emp::tt::dereference<char>::treturn, char&);
EMP_STATIC_ASSERT_TYPE_EQUAL(   emp::tt::dereference<char const>::treturn,
                                char const &);
EMP_STATIC_ASSERT_TYPE_EQUAL(   emp::tt::dereference<char const&>::treturn,
                                char const &);

EMP_STATIC_ASSERT_TYPE_EQUAL(
                            emp::tt::dereference<char const* const>::treturn,
                            char const&);

EMP_STATIC_ASSERT_TYPE_EQUAL(
                            emp::tt::dereference<char const* const&>::treturn,
                            char const&);

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#endif

