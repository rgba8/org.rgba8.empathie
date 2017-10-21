// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
//-----------------------------------------------------------------------------
// @rgba8.org
//-----------------------------------------------------------------------------
#include "emp_tt_return.h"

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
namespace emp { namespace tt {

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
static_assert(equal<return_<char>, char>::value, "");
static_assert(equal<return_<char const>, char>::value, "");
static_assert(equal<return_<char const*>, char const*>::value, "");
static_assert(equal<return_<char const* const>, char const*>::value, "");
static_assert(equal<return_<char&>, char&>::value, "");
static_assert(equal<return_<char const&>, char const&>::value, "");
static_assert(equal<return_<return_<char>>, return_<char>>::value, "");

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
} }
