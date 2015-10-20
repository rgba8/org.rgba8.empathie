//-----------------------------------------------------------------------------
// emp_tt_return.h - @rgba8.org
//-----------------------------------------------------------------------------
#ifndef EMP_TT_RETURN_H
#define EMP_TT_RETURN_H

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
namespace emp { namespace tt {

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
template <typename T> using return_ =
    if_else
    <
        or_<is_fundamental<T>::value, is_pointer<T>::value>::value,
        try_remove_const<T>,
        if_else
        <
            is_reference<T>::value,
            T,
            try_add_reference<T>
        >
    >;

static_assert(equal<return_<char>, char>::value, "");
static_assert(equal<return_<char const>, char>::value, "");
static_assert(equal<return_<char const*>, char const*>::value, "");
static_assert(equal<return_<char const* const>, char const*>::value, "");
static_assert(equal<return_<char&>, char&>::value, "");
static_assert(equal<return_<char const&>, char const&>::value, "");
static_assert(equal<return_<return_<char>>, return_<char>>::value, "");

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
template <typename T>
using const_return =
    if_else
    <
        or_<is_fundamental<T>::value, is_pointer<T>::value>::value,
        try_remove_const<T>,
        if_else
        <
            is_reference<T>::value,
            const_param<T>,
            try_add_reference<try_add_const<T>>
        >
    >;

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
} }

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#endif

