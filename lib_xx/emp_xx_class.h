//-----------------------------------------------------------------------------
// emp_xx_class.h - @rgba8.org
//-----------------------------------------------------------------------------
#ifndef EMP_XX_CLASS_H
#define EMP_XX_CLASS_H

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#include "emp_pp_forward.h"

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
namespace emp { namespace rfx  {

    template <typename> class type_t;
    // @@0 rfx template <typename> class member_t;
    // @@0 rfx class reflection_c;
    // @@0 rfx template <typename T> EMP_RETURN bool reflect(reflection_c& a_rReflection);
} }

#define EMP_RFX_FRIEND(...)\
    friend class emp::rfx::type_t<__VA_ARGS__>;

    // @@0 rfx
//    friend EMP_RETURN bool emp::rfx::reflect<__VA_ARGS__>(emp::rfx::reflection_c&);

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#define EMP_XX_NOINSTANCE(...)\
EMP_XX_NOCOPY(__VA_ARGS__);\
private:\
    class emp_nofriend {};\
    friend class emp_nofriend;\
    __VA_ARGS__(void);\
    virtual ~__VA_ARGS__(void) = 0

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#define EMP_XX_NOASSIGN(...)\
public:\
    void emp_nopublic(void) {};\
private:\
    __VA_ARGS__(__VA_ARGS__ const& a_rFrom);\
    __VA_ARGS__ const& operator=(__VA_ARGS__ const& a_rFrom)

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#define EMP_XX_NOCOPY(...)\
    EMP_XX_NOASSIGN(__VA_ARGS__)

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#define EMP_XX_NODEFAULT(...)\
private:\
    __VA_ARGS__(void)

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#define EMP_CLASS(x_Name)\
class x_Name\
{\
    EMP_RFX_FRIEND(x_Name)

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#define EMP_CLASS_BASE(x_Name, x_Modifier, ...)\
class x_Name : x_Modifier __VA_ARGS__\
{\
    EMP_RFX_FRIEND(x_Name)\
public:\
    typedef __VA_ARGS__ tbase;\
private:

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#define EMP_NOCOPY_CLASS(x_Name)\
class x_Name\
{\
    EMP_RFX_FRIEND(x_Name)\
    EMP_XX_NOCOPY(x_Name);

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#define EMP_NOCOPY_CLASS_BASE(x_Name, x_Modifier, ...)\
class x_Name : x_Modifier __VA_ARGS__\
{\
    EMP_RFX_FRIEND(x_Name)\
public:\
    typedef __VA_ARGS__ tbase;\
private:\
    EMP_XX_NOCOPY(x_Name);

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#define EMP_NOCOPY_CLASS_BASE_2(x_Name, x_Modifier, x_Base, x_Mod2, x_Base2)\
class x_Name : x_Modifier x_Base, x_Mod2 x_Base2\
{\
    EMP_RFX_FRIEND(x_Name)\
public:\
    typedef x_Base tbase;\
    typedef x_Base2 tbase2;\
private:\
    EMP_XX_NOCOPY(x_Name);

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#define EMP_NOINSTANCE_IMPL(x_Type, ...)\
x_Type __VA_ARGS__\
{\
private:\
    EMP_XX_NOINSTANCE(__VA_ARGS__);

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#define EMP_NOINSTANCE_CLASS(...) EMP_NOINSTANCE_IMPL(class, __VA_ARGS__)
#define EMP_NOINSTANCE_STRUCT(...) EMP_NOINSTANCE_IMPL(struct, __VA_ARGS__) public:

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#define EMP_NOINSTANCE_CLASS_BASE(x_Name, x_Modifier, ...)\
class x_Name : x_Modifier __VA_ARGS__\
{\
public:\
    typedef __VA_ARGS__ tbase;\
private:\
    EMP_XX_NOINSTANCE(x_Name);

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#endif

