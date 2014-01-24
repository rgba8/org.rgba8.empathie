//-----------------------------------------------------------------------------
//
// File Name : emp_tt_is_derived.h
//
// Creation Date : mer. 12 sept. 2012 12:01:56 CEST
//
// Modification Date : mar. 26 nov. 2013 18:10:25 CET
//
// Created By : ksej - www.rgba8.org
//
// Description :
//
//-----------------------------------------------------------------------------
#ifndef EMP_TT_IS_DERIVED_H
#define EMP_TT_IS_DERIVED_H

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#include "emp_hh_stddef.h"

#include "emp_pp_forward.h"

#include "emp_tt_constant.h"

#include "emp_xx_noinstance_class.h"
#include "emp_xx_nullptr.h"

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
namespace emp { namespace tt {

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
template <typename B, typename D>
EMP_NOINSTANCE_CLASS(is_derived_t)
private:
    typedef char yes_type_c;
    typedef struct { char m_acNo[2]; } no_type_c;

    template <typename V>
    static yes_type_c test(B*);

    template <typename V>
    static no_type_c test(...);

    static D* get_derived(void);

public:
    EMP_TT_CONSTANT(
        size_t, value, sizeof(test<B>(get_derived())) == sizeof(yes_type_c));
};

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
} }

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#endif

