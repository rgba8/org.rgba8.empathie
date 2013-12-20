//-----------------------------------------------------------------------------
//
// File Name : emp_ast_assert.cpp
//
// Creation Date : Fri 15 Oct 2010 03:07:37 PM CEST
//
// Modification Date : Wed Dec 11 22:07:32 2013
//
// Created By : luh - www.rgba8.org
//
// Description :
//
//-----------------------------------------------------------------------------
#include "emp_ast_assert.h"

#include "emp_ast_asserter.h"

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#include "emp_app_global.h"

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
namespace emp { namespace ast {

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#ifdef EMP_XX_ASSERT_ENABLE
void condition(assert_t const& a_rAssert)
{ EMP_ASSERTER().condition(a_rAssert); }
#endif

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
} }

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

