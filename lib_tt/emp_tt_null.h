//-----------------------------------------------------------------------------
//
// File Name : emp_tt_null.h
//
// Creation Date : Mon 08 Nov 2010 11:40:46 AM CET
//
// Modification Date : mar. 26 nov. 2013 18:11:25 CET
//
// Created By : luh - www.rgba8.org
//
// Description :
//
//-----------------------------------------------------------------------------
#ifndef EMP_TT_NULL_H
#define EMP_TT_NULL_H

//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
#include "emp_tt_integral.h"

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#include "emp_xx_noinstance_class_base.h"

#include "emp_pp_forward.h"

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
namespace emp { namespace tt {

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
EMP_NOINSTANCE_CLASS_BASE(null, private, EMP_PP_FORWARD(integral<int, 0>))
public:
    using tbase::value;
};

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
} }

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#endif

