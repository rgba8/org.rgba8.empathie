//-----------------------------------------------------------------------------
//
// File Name : emp_tt_try_add_const.h
//
// Creation Date : Thu 25 Nov 2010 04:15:02 PM CET
//
// Modification Date : mar. 26 nov. 2013 18:11:45 CET
//
// Created By : luh - www.rgba8.org
//
// Description :
//
//-----------------------------------------------------------------------------
#ifndef EMP_TT_TRY_ADD_CONST_H
#define EMP_TT_TRY_ADD_CONST_H

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#ifndef EMP_TT_IS_NOT_CONST_H
#include "emp_tt_is_not_const.h"
#endif

#ifndef EMP_TT_ADD_CONST_H
#include "emp_tt_add_const.h"
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
EMP_TT_DECLARE_TYPE(try_add_const, typename EMP_PP_FORWARD_3(
                                                emp::tt::try_<T,
                                                emp::tt::is_not_const,
                                                emp::tt::add_const>::type));

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
} } // tt // emp

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#endif

