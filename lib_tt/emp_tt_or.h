//-----------------------------------------------------------------------------
// @rgba8.org
//-----------------------------------------------------------------------------
#ifndef EMP_TT_OR_H
#define EMP_TT_OR_H

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#include "emp_tt_bool.h"

#include "emp_pp_forward.h"

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
namespace emp { namespace tt {

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
template <bool b0, bool b1, bool b2 = false, bool b3 = false, bool b4 = false>
EMP_NOINSTANCE_CLASS_BASE(or_, public, true_)
public:
    using true_::value;
};

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
template <>
EMP_NOINSTANCE_CLASS_BASE(
EMP_PP_FORWARD_5(or_<false, false, false, false, false>), public, false_)
public:
    using false_::value;
};

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
} }

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#endif

