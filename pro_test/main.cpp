//-----------------------------------------------------------------------------
//
// File Name : main.cpp
//
// Creation Date : lun. 18 nov. 2013 22:22:29 CET
//
// Modification Date : Mon Dec  2 19:50:23 2013
//
// Created By : ksej - www.rgba8.org
//
// Description :
//
//-----------------------------------------------------------------------------
#include "main.h"

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#include "emp_ast_assert.h"

#include "emp_hh_stdint.h"

#include "emp_pp_forward.h"

#include "emp_tt_is_arithmetic.h"
#include "emp_tt_is_signed.h"

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
EMP_STATIC_ASSERT(sizeof(bool) == 1);
EMP_STATIC_ASSERT(sizeof(int32_t) == 4);
EMP_STATIC_ASSERT(sizeof(int64_t) == 8);
EMP_STATIC_ASSERT(emp::tt::is_signed<short>::value);
EMP_STATIC_ASSERT(emp::tt::is_arithmetic<short>::value);
EMP_STATIC_ASSERT(emp::tt::is_signed<int>::value);
EMP_STATIC_ASSERT(emp::tt::is_arithmetic<int>::value);
EMP_STATIC_ASSERT((emp::tt::are_equal<short,int>::value == false));

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
int main(void);
int main(void)
{ return 0; }

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

