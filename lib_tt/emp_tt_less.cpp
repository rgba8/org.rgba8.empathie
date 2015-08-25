//-----------------------------------------------------------------------------
// @rgba8.org
//-----------------------------------------------------------------------------
#include "emp_tt_less.h"

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#ifdef EMP_XX_STATIC_ASSERT

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#include "emp_tt_assert.h"

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
namespace emp { namespace tt { namespace test {

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
typedef emp::tt::less<size_t, 0, 1> tless0;
EMP_STATIC_ASSERT(tless0::value);

typedef emp::tt::less<size_t, 0, 0> tless1;
EMP_STATIC_ASSERT(tless1::value == false);

typedef emp::tt::less<size_t, 1, 0> tless2;
EMP_STATIC_ASSERT(tless2::value == false);

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
} } }

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#endif

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

