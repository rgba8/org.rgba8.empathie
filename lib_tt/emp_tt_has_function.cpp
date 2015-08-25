//-----------------------------------------------------------------------------
// @rgba8.org
//-----------------------------------------------------------------------------
#include "emp_tt_has_function.h"

#include "emp_tt_assert.h"

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
namespace emp { namespace tt {

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
EMP_TT_HAS_FUNCTION(pre_load, bool (S::*)(void))

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
struct test_1
{
    virtual ~test_1(void) {}
    bool pre_load(void) { return true; };
};

EMP_NOCOPY_CLASS_BASE(test_2, public, test_1)
public:
};

struct test_3
{
};

EMP_STATIC_ASSERT(has_pre_load<test_3>::value == false);
EMP_STATIC_ASSERT(has_pre_load<test_2>::value);
EMP_STATIC_ASSERT(has_pre_load<test_1>::value);

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
} }

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

