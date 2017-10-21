// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
//-----------------------------------------------------------------------------
// @rgba8.org
//-----------------------------------------------------------------------------
#include "emp_tt_dereference.h"

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
namespace emp { namespace tt {

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
static_assert(equal<dereference<char>::treturn, char&>::value, "");
static_assert(equal<dereference<char const>::treturn, char const &>::value, "");
static_assert(equal<dereference<char const&>::treturn, char const &>::value, "");
static_assert(equal<dereference<char const* const>::treturn, char const&>::value, "");
static_assert(equal<dereference<char const* const&>::treturn, char const&>::value, "");

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
} }
