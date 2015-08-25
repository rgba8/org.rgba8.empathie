//-----------------------------------------------------------------------------
// @rgba8.org
//-----------------------------------------------------------------------------
#ifndef EMP_TT_IS_NOT_POINTER_H
#define EMP_TT_IS_NOT_POINTER_H

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#include "emp_tt_is_pointer.h"
#include "emp_tt_not.h"
#include "emp_tt_trait.h"

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
namespace emp { namespace tt {

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
EMP_TT_DECLARE_VALUE(is_not_pointer, emp::tt::not_<emp::tt::is_pointer<T>::value>);

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
} }

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#endif

