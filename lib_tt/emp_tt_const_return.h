//-----------------------------------------------------------------------------
// @rgba8.org
//-----------------------------------------------------------------------------
#ifndef EMP_TT_CONST_RETURN_H
#define EMP_TT_CONST_RETURN_H

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#include "emp_tt_const_param.h"
#include "emp_tt_if_else.h"
#include "emp_tt_is_fundamental.h"
#include "emp_tt_is_pointer.h"
#include "emp_tt_is_reference.h"
#include "emp_tt_or.h"
#include "emp_tt_try_add_const.h"
#include "emp_tt_try_add_reference.h"
#include "emp_tt_try_remove_const.h"

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
namespace emp { namespace tt {

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
template <typename T>
EMP_NOINSTANCE_CLASS(const_return)
public:
    typedef typename if_else<or_<is_fundamental<T>::value, is_pointer<T>::value>::value,
        typename try_remove_const<T>::type,
        typename if_else<is_reference<T>::value,
            typename const_param<T>::type,
            typename try_add_reference<typename try_add_const<T>::type>::type
        >::type
    >::type type;
};

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
} }

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#endif

