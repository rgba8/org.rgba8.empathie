//-----------------------------------------------------------------------------
//
// File Name : emp_tt_remove_qualifier.h
//
// Creation Date : Mon 22 Nov 2010 02:03:16 PM CET
//
// Modification Date : mar. 26 nov. 2013 18:11:32 CET
//
// Created By : luh - www.rgba8.org
//
// Description :
//
//-----------------------------------------------------------------------------
#ifndef EMP_TT_REMOVE_QUALIFIER_H
#define EMP_TT_REMOVE_QUALIFIER_H

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#ifndef EMP_TT_ARE_EQUAL_H
#include "emp_tt_are_equal.h"
#endif

#ifndef EMP_TT_IF_ELSE_H
#include "emp_tt_if_else.h"
#endif

#ifndef EMP_TT_TRY_REMOVE_CONST_H
#include "emp_tt_try_remove_const.h"
#endif

#ifndef EMP_TT_TRY_REMOVE_POINTER_H
#include "emp_tt_try_remove_pointer.h"
#endif

#ifndef EMP_TT_TRY_REMOVE_REFERENCE_H
#include "emp_tt_try_remove_reference.h"
#endif

#ifndef EMP_TT_TRY_REMOVE_VOLATILE_H
#include "emp_tt_try_remove_volatile.h"
#endif

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
} } // emp // tt

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#endif

