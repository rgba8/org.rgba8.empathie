// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
//-----------------------------------------------------------------------------
// @rgba8.org
//-----------------------------------------------------------------------------
#include "emp_tt_reference.h"

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
namespace emp { namespace tt {

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
static_assert(is_reference<char&>::value, "");
static_assert(is_reference<char>::value == false, "");
static_assert(is_reference<char const*&>::value, "");

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
static_assert(equal<add_reference<int>, int&>::value, "");
static_assert(equal<try_add_reference<int>, int&>::value, "");
static_assert(equal<try_add_reference<int&>, int&>::value, "");

} }
