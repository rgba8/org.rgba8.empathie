//-----------------------------------------------------------------------------
// emp_tt_reference.h - @rgba8.org
//-----------------------------------------------------------------------------
#ifndef EMP_TT_REFERENCE_H
#define EMP_TT_REFERENCE_H

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#include "emp_tt_logical.h"

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
namespace emp { namespace tt {

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
EMP_TT_DECLARE_VALUE(is_reference, false_)
EMP_TT_DECLARE_VALUE_PARTIAL(is_reference, T&, true_)
EMP_TT_DECLARE_VALUE(is_not_reference, not_<is_reference<T>::value>)

static_assert(is_reference<char&>::value, "");
static_assert(is_reference<char>::value == false, "");
static_assert(is_reference<char const*&>::value, "");

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
EMP_TT_DECLARE_TYPE(add_reference_t, T&)

template <typename T> using add_reference = typename add_reference_t<T>::type;
template <typename T> using try_add_reference = try_<T, is_not_reference, add_reference>;

static_assert(equal<add_reference<int>, int&>::value, "");
static_assert(equal<try_add_reference<int>, int&>::value, "");
static_assert(equal<try_add_reference<int&>, int&>::value, "");

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
template <typename T> class remove_reference_t;
EMP_TT_DECLARE_TYPE_PARTIAL(remove_reference_t, T&, T)

template <typename T> using remove_reference = typename remove_reference_t<T>::type;
template <typename T> using try_remove_reference = try_<T, is_reference, remove_reference>;

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
} }

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#endif

