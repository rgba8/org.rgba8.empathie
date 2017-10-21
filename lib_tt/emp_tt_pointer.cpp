// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
//-----------------------------------------------------------------------------
// @rgba8.org
//-----------------------------------------------------------------------------
#include "emp_tt_pointer.h"

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
namespace emp { namespace tt {

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
static_assert(equal<add_pointer<int>, int*>::value, "");
static_assert(equal<add_pointer<int const>, int const*>::value, "");
static_assert(equal<add_pointer<int*>, int**>::value, "");
static_assert(equal<try_add_pointer<int&>, int&>::value, "");
static_assert(equal<try_add_pointer<int const* const>, int const* const*>::value, "");

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
static_assert(equal<remove_pointer<char*>, char>::value, "");
static_assert(equal<remove_pointer<char const*>, char const>::value, "");
static_assert(equal<remove_pointer<char const* const>, char const>::value, "");

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
} }
