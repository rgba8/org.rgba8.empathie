//-----------------------------------------------------------------------------
//
// File Name : emp_tt_signed.h
//
// Creation Date : Mon 06 Jun 2011 08:51:10 AM CEST
//
// Modification Date : mar. 26 nov. 2013 18:11:41 CET
//
// Created By : ksej - www.rgba8.org
//
// Description :
//
//-----------------------------------------------------------------------------
#ifndef EMP_TT_SIGNED_H
#define EMP_TT_SIGNED_H

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#include "emp_tt_def.h"

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#include "emp_xx_noinstance_class.h"

#include "emp_pp_if.h"

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
namespace emp { namespace tt {

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
template <typename T>
EMP_NOINSTANCE_CLASS(signed_)
public:
};

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#define XTMP_TT_TYPE(   x_Type, x_Name, x_Integral, x_Signdness, x_Distinct,\
                        x_Signed)\
EMP_PP_IF(x_Signdness,\
EMP_PP_IF(x_Distinct,\
template <>\
EMP_NOINSTANCE_CLASS(signed_<signed x_Type const volatile>)\
public:\
    typedef signed x_Type type;\
};\
template <>\
EMP_NOINSTANCE_CLASS(signed_<signed x_Type volatile>)\
public:\
    typedef signed x_Type type;\
};\
template <>\
EMP_NOINSTANCE_CLASS(signed_<signed x_Type const>)\
public:\
    typedef signed x_Type type;\
};\
template <>\
EMP_NOINSTANCE_CLASS(signed_<signed x_Type>)\
public:\
    typedef signed x_Type type;\
};)\
template <>\
EMP_NOINSTANCE_CLASS(signed_<x_Type const volatile>)\
public:\
    typedef signed x_Type type;\
};\
template <>\
EMP_NOINSTANCE_CLASS(signed_<x_Type volatile>)\
public:\
    typedef signed x_Type type;\
};\
template <>\
EMP_NOINSTANCE_CLASS(signed_<x_Type const>)\
public:\
    typedef signed x_Type type;\
};\
template <>\
EMP_NOINSTANCE_CLASS(signed_<x_Type>)\
public:\
    typedef signed x_Type type;\
};\
)

EMP_TT_TYPES()

#undef XTMP_TT_TYPE

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
} }

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#endif

