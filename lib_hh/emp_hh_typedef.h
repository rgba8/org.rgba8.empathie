//-----------------------------------------------------------------------------
// emp_hh_typedef.h - @rgba8.org
//-----------------------------------------------------------------------------
#ifndef EMP_HH_TYPEDEF_H
#define EMP_HH_TYPEDEF_H

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#include "emp_hh_stddef.h"
#include "emp_hh_stdint.h"

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#define EMP_TYPEDEF_IMP(x_Type, x_Alias)\
    typedef x_Type const c_##x_Alias;\
    typedef x_Type* p_##x_Alias;\
    typedef x_Type const* pc_##x_Alias;\
    typedef x_Type const* const cpc_##x_Alias;\
    typedef x_Type* const cp_##x_Alias;

#define EMP_TYPEDEF_EX(x_Type, x_Alias)\
    typedef x_Type x_Alias;\
    EMP_TYPEDEF_IMP(x_Type, x_Alias)

#define EMP_TYPEDEF(x_Type)\
    EMP_TYPEDEF_IMP(x_Type, x_Type)

#define EMP_FORWARD_enum_2(x_Mod, x_Name)\
    enum class x_Name : x_Mod;\
    EMP_TYPEDEF(x_Name)

#define EMP_FORWARD_TYPE(x_Class, x_Mod, x_Name)\
    x_Mod x_Class x_Name;\
    EMP_TYPEDEF_EX(x_Mod x_Class x_Name, x_Name)

#define EMP_FORWARD_class_1(x_Name) EMP_FORWARD_TYPE(class, EMP_PP_EMPTY(), x_Name)
#define EMP_FORWARD_class_2(x_Mod, x_Name) EMP_FORWARD_TYPE(class, x_Mod, x_Name)

#define EMP_FORWARD_struct_1(x_Name) EMP_FORWARD_TYPE(struct, EMP_PP_EMPTY(), x_Name)
#define EMP_FORWARD_struct_2(x_Mod, x_Name) EMP_FORWARD_TYPE(struct, x_Mod, x_Name)

#define EMP_FORWARD(x_Class, ...) EMP_PP_CAT(EMP_FORWARD_, EMP_PP_CAT(x_Class, EMP_PP_CAT(_, EMP_VAARGS_COUNT(__VA_ARGS__))))(__VA_ARGS__)

EMP_TYPEDEF     ( int                   )
EMP_TYPEDEF_EX  ( int8_t        , si8   )
EMP_TYPEDEF_EX  ( int16_t       , si16  )
EMP_TYPEDEF_EX  ( int32_t       , si32  )
EMP_TYPEDEF_EX  ( int64_t       , si64  )

EMP_TYPEDEF_EX  ( unsigned int  , uint  )
EMP_TYPEDEF_EX  ( uint8_t       , ui8   )
EMP_TYPEDEF_EX  ( uint16_t      , ui16  )
EMP_TYPEDEF_EX  ( uint32_t      , ui32  )
EMP_TYPEDEF_EX  ( uint64_t      , ui64  )

EMP_TYPEDEF_EX  ( size_t        , size  )

EMP_TYPEDEF     ( char                  )
EMP_TYPEDEF_EX  ( unsigned char , uchar )

EMP_TYPEDEF     ( bool                  )

EMP_TYPEDEF     ( float                 )
EMP_TYPEDEF_EX  ( float         , f32   )
EMP_TYPEDEF     ( double                )
EMP_TYPEDEF_EX  ( double        , f64   )

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#endif

