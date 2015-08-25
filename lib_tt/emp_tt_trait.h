//-----------------------------------------------------------------------------
// @rgba8.org
//-----------------------------------------------------------------------------
#ifndef EMP_TT_TRAIT_H
#define EMP_TT_TRAIT_H

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#include "emp_tt_def.h"

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#include "emp_pp_if.h"
#include "emp_pp_if_else.h"

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#define EMP_TT_DECLARE_TYPE(x_Trait, x_Type)\
template <typename T>\
class x_Trait\
{\
public:\
    typedef x_Type type;\
private:\
    EMP_XX_NOINSTANCE(x_Trait);\
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#define EMP_TT_DECLARE_TYPE_PARTIAL(x_Trait, x_Partial, x_Type)\
template <typename T>\
class x_Trait<x_Partial>\
{\
public:\
    typedef x_Type type;\
private:\
    EMP_XX_NOINSTANCE(x_Trait);\
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#define EMP_TT_DECLARE_VALUE(x_Trait, x_Value)\
template <typename T>\
class x_Trait : public x_Value\
{\
public:\
    using x_Value::value;\
private:\
    EMP_XX_NOINSTANCE(x_Trait);\
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#define EMP_TT_DECLARE_VALUE_PARTIAL_SPECIAL(   x_bPartial, x_Trait,\
                                                x_Partial, x_Value)\
template <EMP_PP_IF(x_bPartial, typename T)>\
class x_Trait <x_Partial> : public x_Value\
{\
public:\
    using x_Value::value;\
private:\
    EMP_XX_NOINSTANCE(x_Trait);\
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#define EMP_TT_DECLARE_VALUE_PARTIAL(x_Trait, x_Partial, x_Value)\
EMP_TT_DECLARE_VALUE_PARTIAL_SPECIAL(true, x_Trait, x_Partial, x_Value)

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#define EMP_TT_DECLARE_VALUE_SPECIAL(x_Trait, x_Special, x_Value)\
EMP_TT_DECLARE_VALUE_PARTIAL_SPECIAL(false, x_Trait, x_Special, x_Value)

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#define EMP_TT_DECLARE_VALUE_PARTIAL_SPECIAL_CV(x_bPartial, x_Trait, x_Type,\
                                                x_Value)\
    EMP_PP_IF_ELSE(  x_bPartial,\
                EMP_TT_DECLARE_VALUE_PARTIAL,\
                EMP_TT_DECLARE_VALUE_SPECIAL)(x_Trait, x_Type, x_Value);\
    EMP_PP_IF_ELSE(  x_bPartial,\
                EMP_TT_DECLARE_VALUE_PARTIAL,\
                EMP_TT_DECLARE_VALUE_SPECIAL)\
                    (x_Trait, x_Type const, x_Value);\
    EMP_PP_IF_ELSE(  x_bPartial,\
                EMP_TT_DECLARE_VALUE_PARTIAL,\
                EMP_TT_DECLARE_VALUE_SPECIAL)\
                    (x_Trait, x_Type volatile, x_Value);\
    EMP_PP_IF_ELSE(  x_bPartial,\
                EMP_TT_DECLARE_VALUE_PARTIAL,\
                EMP_TT_DECLARE_VALUE_SPECIAL)\
                    (x_Trait, x_Type const volatile, x_Value)

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#define EMP_TT_DECLARE_VALUE_PARTIAL_CV(x_Trait, x_Type, x_Value)\
    EMP_TT_DECLARE_VALUE_PARTIAL_SPECIAL_CV(true, x_Trait, x_Type, x_Value)

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#define EMP_TT_DECLARE_VALUE_SPECIAL_CV(x_Trait, x_Type, x_Value)\
    EMP_TT_DECLARE_VALUE_PARTIAL_SPECIAL_CV(false, x_Trait, x_Type, x_Value)

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#endif

