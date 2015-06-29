//-----------------------------------------------------------------------------
//
// File Name : emp_tt_limit.h
//
// Creation Date : Mon 08 Nov 2010 03:42:22 PM CET
//
// Modification Date : lun. 29 juin 2015 19:59:08 CEST
//
// Created By : ksej - www.rgba8.org
//
// Description :
//
//-----------------------------------------------------------------------------
#ifndef EMP_TT_LIMIT_H
#define EMP_TT_LIMIT_H

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#include "emp_tt_assert.h"
#include "emp_tt_def.h"

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#include "emp_pp_if.h"
#include "emp_pp_if_else.h"
#include "emp_pp_not.h"

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
namespace emp { namespace tt {

template <typename T> class max;
template <typename T> class min;

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#define XTMP_TT_MIN(x_Name) EMP_PP_TOKEN(x_Name, _EMP_TT_MIN)
#define XTMP_TT_MAX(x_Name) EMP_PP_TOKEN(x_Name, _EMP_TT_MAX)

#define XTMP_TT_SMIN(x_Name) EMP_PP_TOKEN(x_Name, _EMP_TT_S_MIN)
#define XTMP_TT_SMAX(x_Name) EMP_PP_TOKEN(x_Name, _EMP_TT_S_MAX)

#define XTMP_TT_UMIN(x_Name) EMP_PP_TOKEN(x_Name, _EMP_TT_U_MIN)
#define XTMP_TT_UMAX(x_Name) EMP_PP_TOKEN(x_Name, _EMP_TT_U_MAX)

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#define XTMP_TT_LIM(x_Trait, x_Type, x_Name, x_Integral, x_Value)\
template <> class x_Trait<x_Type>\
{\
public:\
    EMP_PP_IF(x_Integral, static const x_Type value = x_Value;)\
    static inline x_Type get_value(void);\
private:\
    EMP_XX_NOINSTANCE(x_Trait);\
};

#define XTMP_TT_TYPE(x_Type, x_Name, x_Integral, x_Signedness, x_Distinct,\
                    x_Signed)\
XTMP_TT_LIM(min, x_Type, x_Name, x_Integral, XTMP_TT_MIN(x_Name))\
XTMP_TT_LIM(max, x_Type, x_Name, x_Integral, XTMP_TT_MAX(x_Name))\
EMP_PP_IF(x_Signedness,\
XTMP_TT_LIM(min, unsigned x_Type, x_Name, x_Integral, XTMP_TT_UMIN(x_Name))\
XTMP_TT_LIM(max, unsigned x_Type, x_Name, x_Integral, XTMP_TT_UMAX(x_Name))\
    EMP_PP_IF(x_Distinct,\
XTMP_TT_LIM(min, signed x_Type, x_Name, x_Integral, XTMP_TT_SMIN(x_Name))\
XTMP_TT_LIM(max, signed x_Type, x_Name, x_Integral, XTMP_TT_SMIN(x_Name))))
EMP_TT_TYPES()
#undef XTMP_TT_TYPE
#undef XTMP_TT_LIM

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#define XTMP_TT_LIM(x_Trait, x_Type, x_Name, x_Integral, x_Value)\
x_Type x_Trait<x_Type>::get_value(void) { return x_Value; }

#define XTMP_TT_TYPE(x_Type, x_Name, x_Integral, x_Signedness, x_Distinct,\
                    x_Signed)\
EMP_PP_IF_ELSE(EMP_PP_NOT(x_Integral),\
XTMP_TT_LIM(min, x_Type, x_Name, x_Integral, -XTMP_TT_MAX(x_Name)),\
XTMP_TT_LIM(min, x_Type, x_Name, x_Integral, XTMP_TT_MIN(x_Name)))\
XTMP_TT_LIM(max, x_Type, x_Name, x_Integral, XTMP_TT_MAX(x_Name))\
EMP_PP_IF(x_Signedness,\
XTMP_TT_LIM(min, unsigned x_Type, x_Name, x_Integral, XTMP_TT_UMIN(x_Name))\
XTMP_TT_LIM(max, unsigned x_Type, x_Name, x_Integral, XTMP_TT_UMAX(x_Name))\
EMP_PP_IF(x_Distinct,\
XTMP_TT_LIM(min, signed x_Type, x_Name, x_Integral, XTMP_TT_SMIN(x_Name))\
XTMP_TT_LIM(max, signed x_Type, x_Name, x_Integral, XTMP_TT_SMAX(x_Name))))
EMP_TT_TYPES()
#undef XTMP_TT_TYPE
#undef XTMP_TT_LIM

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
template <typename T>
EMP_NOINSTANCE_CLASS(min<T*>)
public:
    EMP_STATIC_ASSERT(sizeof(T*) == sizeof(uintptr_t));
    static const uintptr_t value = emp::tt::min<uintptr_t>::value;
};

template <typename T>
EMP_NOINSTANCE_CLASS(max<T*>)
public:
    EMP_STATIC_ASSERT(sizeof(T*) == sizeof(uintptr_t));
    static const uintptr_t value = emp::tt::max<uintptr_t>::value;
};

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#undef XTMP_TT_MIN
#undef XTMP_TT_MAX

#undef XTMP_TT_SMIN
#undef XTMP_TT_SMAX

#undef XTMP_TT_UMIN
#undef XTMP_TT_UMAX

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
} } // tt // emp

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#endif

