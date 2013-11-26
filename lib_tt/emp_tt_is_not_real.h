//-----------------------------------------------------------------------------
//
// File Name : emp_tt_is_not_real.h
//
// Creation Date : Thu 25 Nov 2010 04:27:57 PM CET
//
// Modification Date : mar. 26 nov. 2013 18:10:43 CET
//
// Created By : luh - www.rgba8.org
//
// Description :
//
//-----------------------------------------------------------------------------
#ifndef EMP_TT_IS_NOT_REAL_H
#define EMP_TT_IS_NOT_REAL_H

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#include "emp_tt_is_real.h"
#include "emp_tt_not.h"
#include "emp_tt_trait.h"

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
namespace emp { namespace tt {
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
EMP_TT_DECLARE_VALUE(is_not_real, emp::tt::not_<emp::tt::is_real<T>::value>);

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
} }

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#endif

