// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
//-----------------------------------------------------------------------------
// @rgba8.org
//-----------------------------------------------------------------------------
#include "emp_tt_param.h"

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
namespace emp { namespace tt {

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
static_assert(is_param<int>::value, "");
static_assert(equal<try_add_const<int>, int const>::value, "");
static_assert(equal<param<int>, int const>::value, "");

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
static_assert(equal<const_param<int>, int const>::value, "int");
static_assert(equal<const_param<int*>, int const* const>::value, "int*");
static_assert(equal<const_param<int**>, int const* const* const>::value, "int**");
static_assert(equal<const_param<int**&>, int const* const* const&>::value, "int**&");
static_assert(equal<const_param<char const* const>, char const* const>::value, "char const* const");

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
} }
