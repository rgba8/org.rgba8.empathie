//-----------------------------------------------------------------------------
// emp_tt_limit.h - @rgba8.org
//-----------------------------------------------------------------------------
#ifndef EMP_TT_LIMIT_H
#define EMP_TT_LIMIT_H

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#include "emp_tt_trait.h"

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
namespace emp { namespace tt {

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#define XTMP_TT_MIN(x_Name) EMP_PP_CAT(x_Name, _EMP_TT_MIN)
#define XTMP_TT_MAX(x_Name) EMP_PP_CAT(x_Name, _EMP_TT_MAX)

#define XTMP_TT_UMIN(x_Name) EMP_PP_CAT(x_Name, _EMP_TT_U_MIN)
#define XTMP_TT_UMAX(x_Name) EMP_PP_CAT(x_Name, _EMP_TT_U_MAX)

#define XTMP_TT_SMIN(x_Name) EMP_PP_CAT(x_Name, _EMP_TT_S_MIN)
#define XTMP_TT_SMAX(x_Name) EMP_PP_CAT(x_Name, _EMP_TT_S_MAX)

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
template <typename T> EMP_NOINSTANCE_STRUCT(min) };
template <typename T> EMP_NOINSTANCE_STRUCT(max) };

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#define XTMP_TT_TYPE_IMPL(x_Type, x_Name, x_Value)\
template <> EMP_NOINSTANCE_STRUCT(x_Name<x_Type>) static constexpr x_Type value = x_Value; };

#define XTMP_TT_TYPE(x_Type, x_Name, x_Integral, x_Signedness, x_Distinct, x_Signed)\
XTMP_TT_TYPE_IMPL(x_Type, min, XTMP_TT_MIN(x_Name))\
XTMP_TT_TYPE_IMPL(x_Type, max, XTMP_TT_MAX(x_Name))\
EMP_PP_IF(x_Signedness,\
    XTMP_TT_TYPE_IMPL(unsigned x_Type, min, XTMP_TT_UMIN(x_Name))\
    XTMP_TT_TYPE_IMPL(unsigned x_Type, max, XTMP_TT_UMAX(x_Name))\
    EMP_PP_IF(x_Distinct,\
        XTMP_TT_TYPE_IMPL(signed x_Type, min, XTMP_TT_SMIN(x_Name))\
        XTMP_TT_TYPE_IMPL(signed x_Type, max, XTMP_TT_SMAX(x_Name))))


EMP_TT_TYPES()
#undef XTMP_TT_TYPE

EMP_PRAGMA_PUSH_IGNORE(EMP_W_FLOAT_EQUAL)
template <typename T> EMP_INLINE EMP_RETURN bool equal_(T const f0, T const f1);
template <typename T> EMP_INLINE EMP_RETURN bool equal_(T const f0, T const f1) { return f0 == f1; }
EMP_PRAGMA_POP_IGNORE(EMP_W_FLOAT_EQUAL)

template <typename T> EMP_INLINE EMP_RETURN bool not_equal_(T const t0, T const t1);
template <typename T> EMP_INLINE EMP_RETURN bool not_equal_(T const t0, T const t1)
{ return equal_(t0, t1) == false; }

template <typename T> EMP_INLINE void get_min(T& a_rtValue) { a_rtValue = emp::tt::min<T>::value; }
template <typename T> EMP_INLINE void get_max(T& a_rtValue) { a_rtValue = emp::tt::max<T>::value; }
template <typename T> EMP_INLINE EMP_RETURN T get_max(void) { return emp::tt::max<T>::value; }
template <typename T> EMP_INLINE EMP_RETURN bool is_min(T const a_rtValue) { return equal_(a_rtValue, emp::tt::min<T>::value); }
template <typename T> EMP_INLINE EMP_RETURN bool is_max(T const a_rtValue) { return equal_(a_rtValue, emp::tt::max<T>::value); }
template <typename T> EMP_INLINE EMP_RETURN bool is_not_min(T const a_rtValue) { return is_min(a_rtValue) == false; }
template <typename T> EMP_INLINE EMP_RETURN bool is_not_max(T const a_rtValue) { return is_max(a_rtValue) == false; }


template <typename T, T first, T... params>
EMP_NOINSTANCE_STRUCT(max_t) static constexpr const T value = max_t<T, first, max_t<T, params...>::value>::value; };

template <typename T, T first, T last>
EMP_NOINSTANCE_STRUCT(max_t<T, first, last>) static constexpr const T value = first > last ? first : last; };

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#define EMP_TT_MIN_CTOR(x_Variable) x_Variable(emp::tt::min<decltype(x_Variable)>::value)
#define EMP_TT_MAX_CTOR(x_Variable) x_Variable(emp::tt::max<decltype(x_Variable)>::value)

#define EMP_TT_MIN_VAR(x_Variable) x_Variable = emp::tt::min<emp::tt::try_remove_reference<decltype(x_Variable)>>::value
#define EMP_TT_MAX_VAR(x_Variable) x_Variable = emp::tt::max<emp::tt::try_remove_reference<decltype(x_Variable)>>::value

/*template <typename T>
EMP_NOINSTANCE_CLASS(min<T*>)
public:
    static_assert(sizeof(T*) == sizeof(uintptr_t), "");
    static const uintptr_t value = emp::tt::min<uintptr_t>::value;
};

template <typename T>
EMP_NOINSTANCE_CLASS(max<T*>)
public:
    static_assert(sizeof(T*) == sizeof(uintptr_t), "");
    static const uintptr_t value = emp::tt::max<uintptr_t>::value;
};*/

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
} }

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#endif

