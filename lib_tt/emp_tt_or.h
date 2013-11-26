//-----------------------------------------------------------------------------
//
// File Name : emp_tt_or.h
//
// Creation Date : Mon 08 Nov 2010 11:46:00 AM CET
//
// Modification Date : mar. 26 nov. 2013 18:11:27 CET
//
// Created By : luh - www.rgba8.org
//
// Description :
//
//-----------------------------------------------------------------------------
#ifndef EMP_TT_OR_H
#define EMP_TT_OR_H

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#include "emp_tt_bool.h"

#include "emp_xx_noinstance_class_base.h"

#include "emp_pp_forward.h"

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
namespace emp { namespace tt {

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
template <bool b0, bool b1, bool b2 = false, bool b3 = false, bool b4 = false>
EMP_NOINSTANCE_CLASS_BASE(or, public, true_)
public:
    using true_::value;
};

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
template <>
EMP_NOINSTANCE_CLASS_BASE(
EMP_PP_FORWARD_5(or<false, false, false, false, false>), public, false_)
public:
    using false_::value;
};

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
} }

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#endif

