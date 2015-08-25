//-----------------------------------------------------------------------------
// @rgba8.org
//-----------------------------------------------------------------------------
#ifndef EMP_TT_IS_SIGNED_H
#define EMP_TT_IS_SIGNED_H

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#include "emp_tt_bool.h"
#include "emp_tt_def.h"
#include "emp_tt_trait.h"

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#include "emp_pp_and.h"
#include "emp_pp_if.h"
#include "emp_pp_not.h"

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
namespace emp { namespace tt {

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
EMP_TT_DECLARE_VALUE(is_signed, emp::tt::false_);

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#define XTMP_TT_TYPE(x_Type, x_Name, x_Integral, x_Signedness, x_Distinct, x_Signed)\
EMP_PP_IF(EMP_PP_AND_4(x_Integral, x_Signedness, x_Distinct, x_Signed),\
    EMP_TT_DECLARE_VALUE_SPECIAL_CV(is_signed, x_Type, emp::tt::true_);\
    EMP_TT_DECLARE_VALUE_SPECIAL_CV(is_signed, signed x_Type, emp::tt::true_);)\
EMP_PP_IF(EMP_PP_AND_4(x_Integral, x_Signedness, x_Distinct, EMP_PP_NOT(x_Signed)),\
    EMP_TT_DECLARE_VALUE_SPECIAL_CV(is_signed, signed x_Type, emp::tt::true_);)\
EMP_PP_IF(EMP_PP_AND_4(x_Integral, x_Signedness, EMP_PP_NOT(x_Distinct), x_Signed),\
    EMP_TT_DECLARE_VALUE_SPECIAL_CV(is_signed, x_Type, emp::tt::true_);)\
EMP_PP_IF(EMP_PP_AND_4(x_Integral, EMP_PP_NOT(x_Signedness), EMP_PP_NOT(x_Distinct), x_Signed),\
    EMP_TT_DECLARE_VALUE_SPECIAL_CV(is_signed, x_Type, emp::tt::true_);)
EMP_TT_TYPES()
#undef XTMP_TT_TYPE

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
} }

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#endif

