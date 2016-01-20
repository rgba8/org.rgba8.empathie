//-----------------------------------------------------------------------------
// emp_xx_class.h - @rgba8.org
//-----------------------------------------------------------------------------
#ifndef EMP_XX_CLASS_H
#define EMP_XX_CLASS_H

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#include "emp_hh_stddef.h"

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#include <tuple>

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
namespace emp { namespace rfx  { template <typename> class type_t; } }

#define EMP_RFX_FRIEND(...)\
    friend class emp::rfx::type_t<EMP_PP_TRY_SOLVE(__VA_ARGS__)>;

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#define EMP_XX_NOCOPY(...)\
public:\
    void emp_nopublic(void) {};\
private:\
    EMP_PP_TRY_SOLVE(__VA_ARGS__)(EMP_PP_TRY_SOLVE(__VA_ARGS__) const& a_rFrom);\
    EMP_PP_TRY_SOLVE(__VA_ARGS__) const& operator=(EMP_PP_TRY_SOLVE(__VA_ARGS__) const& a_rFrom);

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#define EMP_XX_NOINSTANCE(...)\
private:\
    class emp_nofriend {};\
    friend class emp_nofriend;\
    EMP_PP_TRY_SOLVE(__VA_ARGS__)(void);\
    virtual ~EMP_PP_TRY_SOLVE(__VA_ARGS__)(void) = 0;

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#define EMP_XX_NODEFAULT(...)\
private:\
    EMP_PP_TRY_SOLVE(__VA_ARGS__)(void);

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#define EMP_XX_TYPE_ACCESS_struct public:
#define EMP_XX_TYPE_ACCESS_class private:
#define EMP_XX_TYPE_ACCESS(x_Type) EMP_PP_CAT(EMP_XX_TYPE_ACCESS_, x_Type)

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#define EMP_(x_Type, ...)\
x_Type EMP_PP_TRY_SOLVE(__VA_ARGS__)\
{\
    EMP_RFX_FRIEND(__VA_ARGS__)

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#define EMP_NOCOPY(x_Type, ...)\
    EMP_(x_Type, __VA_ARGS__)\
    EMP_XX_NOCOPY(__VA_ARGS__)

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#define EMP_NOINSTANCE(x_Type, ...)\
    EMP_NOCOPY(x_Type, __VA_ARGS__)\
    EMP_XX_NOINSTANCE(__VA_ARGS__)\
    EMP_XX_TYPE_ACCESS(x_Type)

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#define EMP_TYPEDEF_BASE_2(x_Modifier1, ...)\
    typedef EMP_PP_TRY_SOLVE(__VA_ARGS__) tbase1;\
    typedef std::tuple<EMP_PP_TRY_SOLVE(__VA_ARGS__)> tbases;

#define EMP_TYPEDEF_BASE_4(x_Modifier1, x_Base1, x_Modifier2, ...)\
    typedef EMP_PP_TRY_SOLVE(x_Base1) tbase1;\
    typedef EMP_PP_TRY_SOLVE(__VA_ARGS__) tbase2;\
    typedef std::tuple<x_Base1, EMP_PP_TRY_SOLVE(__VA_ARGS__)> tbases;

#define EMP_TYPEDEF_BASE_6(x_Modifier1, x_Base1, x_Modifier2, x_Base2, x_Modifier3, ...)\
    typedef EMP_PP_TRY_SOLVE(x_Base1) tbase1;\
    typedef EMP_PP_TRY_SOLVE(x_Base2) tbase2;\
    typedef EMP_PP_TRY_SOLVE(__VA_ARGS__) tbase3;\
    typedef std::tuple<x_Base1, x_Base2, EMP_PP_TRY_SOLVE(__VA_ARGS__)> tbases;

#define EMP_TYPEDEF_BASE(...)\
    EMP_PP_CAT(EMP_TYPEDEF_BASE_, EMP_VAARGS_COUNT(__VA_ARGS__))(__VA_ARGS__)

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#define EMP_INHERITANCE_2(x_Modifier1, ...)\
    x_Modifier1 EMP_PP_TRY_SOLVE(__VA_ARGS__)

#define EMP_INHERITANCE_4(x_Modifier1, x_Base1, x_Modifier2, ...)\
    x_Modifier1 EMP_PP_TRY_SOLVE(x_Base1), x_Modifier2 EMP_PP_TRY_SOLVE(__VA_ARGS__)

#define EMP_INHERITANCE_6(x_Modifier1, x_Base1, x_Modifier2, x_Base2, x_Modifier3, ...)\
    x_Modifier1 EMP_PP_TRY_SOLVE(x_Base1), x_Modifier2 EMP_PP_TRY_SOLVE(x_Base2), x_Modifier3 EMP_PP_TRY_SOLVE(__VA_ARGS__)

#define EMP_INHERITANCE(...)\
    EMP_PP_CAT(EMP_INHERITANCE_, EMP_VAARGS_COUNT(__VA_ARGS__))(__VA_ARGS__)

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#define EMP_BASE(x_Type, x_Name, ...)\
x_Type EMP_PP_TRY_SOLVE(x_Name) : EMP_INHERITANCE(__VA_ARGS__)\
{\
    EMP_RFX_FRIEND(x_Name)\
public:\
    EMP_TYPEDEF_BASE(__VA_ARGS__)\
    EMP_XX_TYPE_ACCESS(x_Type)

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#define EMP_NOCOPY_BASE(x_Type, x_Name, ...)\
    EMP_BASE(x_Type, x_Name, __VA_ARGS__)\
    EMP_XX_NOCOPY(x_Name)\
    EMP_XX_TYPE_ACCESS(x_Type)

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#define EMP_NOINSTANCE_BASE(x_Type, x_Name, ...)\
    EMP_NOCOPY_BASE(x_Type, x_Name, __VA_ARGS__)\
    EMP_XX_NOINSTANCE(x_Name)\
    EMP_XX_TYPE_ACCESS(x_Type)

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#endif

