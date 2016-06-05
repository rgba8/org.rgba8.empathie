
//-----------------------------------------------------------------------------
// @rgba8.org
//-----------------------------------------------------------------------------
#include "emp_xx_call.h"

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#include "emp_hh_intrin.h"

#if defined EMP_XX_OS_WIN
#include "emp_hh_windows.h"
#endif

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
namespace emp { namespace xx {

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#if defined EMP_XX_ERROR_HOOK
void error_hook(void)
{

#ifdef EMP_XX_COMPILER_MSC
    // @@0 not working __debugbreak;
    //DebugBreak();
#else
#endif

    EMP_LOG_ERROR("debug_break");
    return;
}
#endif

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
} }

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

