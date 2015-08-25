//-----------------------------------------------------------------------------
// @rgba8.org
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

