//-----------------------------------------------------------------------------
// @rgba8.org
//-----------------------------------------------------------------------------
#ifndef EMP_TT_UNSIGNED_H
#define EMP_TT_UNSIGNED_H

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#include "emp_tt_def.h"

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#include "emp_pp_if.h"

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
namespace emp { namespace tt {

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
template <typename T>
EMP_NOINSTANCE_CLASS(unsigned_)
public:
};

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#define XTMP_TT_TYPE(   x_Type, x_Name, x_Integral, x_Signdness, x_Distinct,\
                        x_Signed)\
EMP_PP_IF(x_Signdness,\
template <>\
EMP_NOINSTANCE_CLASS(unsigned_<unsigned x_Type const volatile>)\
public:\
    typedef unsigned x_Type type;\
};\
template <>\
EMP_NOINSTANCE_CLASS(unsigned_<unsigned x_Type volatile>)\
public:\
    typedef unsigned x_Type type;\
};\
template <>\
EMP_NOINSTANCE_CLASS(unsigned_<unsigned x_Type const>)\
public:\
    typedef unsigned x_Type type;\
};\
template <>\
EMP_NOINSTANCE_CLASS(unsigned_<unsigned x_Type>)\
public:\
    typedef unsigned x_Type type;\
};\
template <>\
EMP_NOINSTANCE_CLASS(unsigned_<x_Type const volatile>)\
public:\
    typedef unsigned x_Type type;\
};\
template <>\
EMP_NOINSTANCE_CLASS(unsigned_<x_Type volatile>)\
public:\
    typedef unsigned x_Type type;\
};\
template <>\
EMP_NOINSTANCE_CLASS(unsigned_<x_Type const>)\
public:\
    typedef unsigned x_Type type;\
};\
template <>\
EMP_NOINSTANCE_CLASS(unsigned_<x_Type>)\
public:\
    typedef unsigned x_Type type;\
};\
)

EMP_TT_TYPES()

template <>
EMP_NOINSTANCE_CLASS(unsigned_<bool>)
public:
    typedef bool type;
};

#undef XTMP_TT_TYPE

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
} }

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#endif

