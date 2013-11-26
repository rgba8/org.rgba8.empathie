//-----------------------------------------------------------------------------
//
// File Name : emp_tt_remove_volatile.h
//
// Creation Date : Mon 22 Nov 2010 03:02:55 PM CET
//
// Modification Date : mar. 26 nov. 2013 18:11:38 CET
//
// Created By : luh - www.rgba8.org
//
// Description :
//
//-----------------------------------------------------------------------------
#ifndef EMP_TT_REMOVE_VOLATILE_H
#define EMP_TT_REMOVE_VOLATILE_H

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#include "emp_tt_trait.h"

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
namespace emp { namespace tt {

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
template <typename T>
class remove_volatile;

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
EMP_TT_DECLARE_TYPE_PARTIAL(remove_volatile, T volatile, T);
EMP_TT_DECLARE_TYPE_PARTIAL(remove_volatile, T const volatile, T);

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
} }

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#endif

