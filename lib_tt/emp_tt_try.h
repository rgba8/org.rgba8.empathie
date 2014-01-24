//-----------------------------------------------------------------------------
//
// File Name : emp_tt_try.h
//
// Creation Date : Thu 25 Nov 2010 03:56:27 PM CET
//
// Modification Date : mar. 26 nov. 2013 18:11:51 CET
//
// Created By : ksej - www.rgba8.org
//
// Description :
//
//-----------------------------------------------------------------------------
#ifndef EMP_TT_TRY_H
#define EMP_TT_TRY_H

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#ifndef EMP_XX_NOINSTANCE_CLASS_H
#include "emp_xx_noinstance_class.h"
#endif

#ifndef EMP_PP_FORWARD_H
#include "emp_pp_forward.h"
#endif

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
namespace emp { namespace tt {

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
template <typename T, bool t_bTry, template <typename> class t_Type>
EMP_NOINSTANCE_CLASS(try_impl)
public:
    typedef T type;
};

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
template <typename T, template <typename> class t_Type>
EMP_NOINSTANCE_CLASS(EMP_PP_FORWARD_3(try_impl<T, true, t_Type>))
public:
    typedef typename t_Type<T>::type type;
};

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
template <typename T,   template <typename> class t_Try,
                        template <typename> class t_Type>
EMP_NOINSTANCE_CLASS(try_)
public:
    typedef typename try_impl<T, t_Try<T>::value, t_Type>::type type;
};

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
} } // tt // emp

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#endif

