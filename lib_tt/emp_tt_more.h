//-----------------------------------------------------------------------------
//
// File Name : emp_tt_more.h
//
// Creation Date : Tue 11 Jan 2011 01:45:50 PM CET
//
// Modification Date : Fri Jun 26 20:13:22 2015
//
// Created By : ksej - www.rgba8.org
//
// Description :
//
//-----------------------------------------------------------------------------
#ifndef EMP_TT_MORE_H
#define EMP_TT_MORE_H

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#include "emp_tt_constant.h"

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
namespace emp { namespace tt {

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
template <typename T, T t_Left, T t_Right>
EMP_NOINSTANCE_CLASS(more)
public:
    EMP_TT_CONSTANT(bool, value, t_Left > t_Right);
};

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
} }

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#endif

