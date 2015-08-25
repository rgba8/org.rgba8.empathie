//-----------------------------------------------------------------------------
// @rgba8.org
//-----------------------------------------------------------------------------
#ifndef EMP_TT_REMOVE_QUALIFIER_H
#define EMP_TT_REMOVE_QUALIFIER_H

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#include "emp_tt_are_equal.h"
#include "emp_tt_if_else.h"
#include "emp_tt_try_remove_const.h"
#include "emp_tt_try_remove_pointer.h"
#include "emp_tt_try_remove_reference.h"
#include "emp_tt_try_remove_volatile.h"

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
namespace emp { namespace tt {

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
template <typename T>
class remove_qualifier
{
private:
    typedef
    typename emp::tt::try_remove_const<
        typename emp::tt::try_remove_volatile<
            typename emp::tt::try_remove_reference<
                typename emp::tt::try_remove_const<
                    typename emp::tt::try_remove_volatile<
                        typename emp::tt::try_remove_pointer<T>::type
                    >::type
                >::type
            >::type
        >::type
    >::type tdestination;

public:
    typedef typename emp::tt::if_else
    <
        emp::tt::are_equal<T, tdestination>::value,
        typename remove_qualifier<tdestination>::type,
        T
    >::type type;

private:
    EMP_XX_NOINSTANCE(remove_qualifier);
};

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
} }

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#endif

