//-----------------------------------------------------------------------------
//
// File Name : emp_tt_try_remove_const.h
//
// Creation Date : Mon 08 Nov 2010 03:31:40 PM CET
//
// Modification Date : mar. 05 nov. 2013 20:09:53 CET
//
// Created By : rgba8 (ksej) - www.empathy.fr
//
// Description :
//
//-----------------------------------------------------------------------------
#ifndef EMP_TT_TRY_REMOVE_CONST_H
#define EMP_TT_TRY_REMOVE_CONST_H

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#ifndef EMP_TT_IS_CONST_H
#include "emp_tt_is_const.h"
#endif

#ifndef EMP_TT_REMOVE_CONST_H
#include "emp_tt_remove_const.h"
#endif

#ifndef EMP_TT_TRAIT_H
#include "emp_tt_trait.h"
#endif

#ifndef EMP_TT_TRY_H
#include "emp_tt_try.h"
#endif

#ifndef EMP_PP_FORWARD_H
#include "emp_pp_forward.h"
#endif

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
namespace emp { namespace tt {

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
EMP_TT_DECLARE_TYPE(try_remove_const, typename EMP_PP_FORWARD_3(
                                                emp::tt::try_<T,
                                                emp::tt::is_const,
                                                emp::tt::remove_const>::type));

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
} } // tt // emp

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#endif

