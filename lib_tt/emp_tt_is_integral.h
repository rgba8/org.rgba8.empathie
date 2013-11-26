//-----------------------------------------------------------------------------
//
// File Name : emp_tt_is_integral.h
//
// Creation Date : Mon 08 Nov 2010 03:05:47 PM CET
//
// Modification Date : mar. 26 nov. 2013 18:10:29 CET
//
// Created By : luh - www.rgba8.org
//
// Description :
//
//-----------------------------------------------------------------------------
#ifndef EMP_TT_IS_INTEGRAL_H
#define EMP_TT_IS_INTEGRAL_H

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#include "emp_tt_bool.h"
#include "emp_tt_def.h"
#include "emp_tt_trait.h"

#include "emp_pp_if.h"
#include "emp_pp_if_else.h"

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
namespace emp { namespace tt {

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
EMP_TT_DECLARE_VALUE(is_integral, emp::tt::false_);

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#define XTMP_TT_TYPE(x_Type, x_Name, x_Integral, x_Signedness, x_Distinct,\
                    x_Signed)\
EMP_PP_IF(x_Integral,\
    EMP_PP_IF_ELSE(x_Signedness,\
     EMP_PP_IF_ELSE(x_Distinct,\
EMP_TT_DECLARE_VALUE_SPECIAL_CV(is_integral, x_Type, emp::tt::true_);\
EMP_TT_DECLARE_VALUE_SPECIAL_CV(is_integral, signed x_Type, emp::tt::true_);\
EMP_TT_DECLARE_VALUE_SPECIAL_CV(is_integral, unsigned x_Type, emp::tt::true_);\
            ,\
EMP_TT_DECLARE_VALUE_SPECIAL_CV(is_integral, x_Type, emp::tt::true_);\
EMP_TT_DECLARE_VALUE_SPECIAL_CV(is_integral, unsigned x_Type,\
                                emp::tt::true_);)\
            ,\
    EMP_TT_DECLARE_VALUE_SPECIAL_CV(is_integral, x_Type, emp::tt::true_);))
EMP_TT_TYPES()
#undef XTMP_TT_TYPE


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
} }

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#endif

