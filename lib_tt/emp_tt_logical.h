//-----------------------------------------------------------------------------
// emp_tt_logical.h - @rgba8.org
//-----------------------------------------------------------------------------
#ifndef EMP_TT_LOGICAL_H
#define EMP_TT_LOGICAL_H

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#include "emp_tt_trait.h"

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
namespace emp { namespace tt {

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
template <typename T, T t_tValue> EMP_NOINSTANCE_STRUCT(integral) static constexpr T const value = t_tValue; };
// @@0 remove //template <typename T, T t_tValue> T const integral<T, t_tValue>::value;

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
template <bool t_bValue> EMP_NOINSTANCE_CLASS_BASE(bool_, public, integral<bool, t_bValue>) };
typedef bool_<true> true_;
typedef bool_<false> false_;

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
template <bool b, bool... bn> EMP_NOINSTANCE_CLASS_BASE(and_, public, and_<b, and_<bn...>::value>) };
template <bool b0, bool b1> EMP_NOINSTANCE_CLASS_BASE(EMP_PP_FORWARD(and_<b0, b1>), public, bool_<b0 && b1>) };
template <bool b0> EMP_NOINSTANCE_CLASS_BASE(and_<b0>, public, bool_<b0>) };

static_assert(and_<true>::value, "");
static_assert(and_<true, true>::value, "");
static_assert(and_<true, false>::value == false, "");
static_assert(and_<false, true>::value == false, "");
static_assert(and_<true, true, true>::value, "");
static_assert(and_<true, true, false>::value == false, "");

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
template <bool b, bool... bn> EMP_NOINSTANCE_CLASS_BASE(or_, public, or_<b, or_<bn...>::value>) };
template <bool b0, bool b1> EMP_NOINSTANCE_CLASS_BASE(EMP_PP_FORWARD(or_<b0, b1>), public, bool_<b0 || b1>) };
template <bool b0> EMP_NOINSTANCE_CLASS_BASE(or_<b0>, public, bool_<b0>) };

static_assert(or_<true>::value, "");
static_assert(or_<true, true>::value, "");
static_assert(or_<true, false>::value, "");
static_assert(or_<false, true>::value, "");
static_assert(or_<true, true, true>::value, "");
static_assert(or_<true, true, false>::value, "");
static_assert(or_<false>::value == false, "");
static_assert(or_<false, false>::value == false, "");
static_assert(or_<false, false, false>::value == false, "");

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
template <bool t_bValue> EMP_NOINSTANCE_CLASS_BASE(not_, public, bool_<t_bValue == false>) };

static_assert(not_<true>::value == false, "");
static_assert(not_<false>::value == true, "");

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
template <typename T, T t_Left, T t_Right> EMP_NOINSTANCE_CLASS_BASE(less_equal, public, bool_<t_Left <= t_Right>) };

static_assert(less_equal<size_t, 0, 1>::value, "");
static_assert(less_equal<size_t, 0, 0>::value, "");
static_assert(less_equal<size_t, 1, 0>::value == false, "");

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
template <typename T, T t_Left, T t_Right> EMP_NOINSTANCE_CLASS_BASE(less, public, bool_<t_Left < t_Right>) };

static_assert(less<size_t, 0, 1>::value, "");
static_assert(less<size_t, 0, 0>::value == false, "");
static_assert(less<size_t, 1, 0>::value == false, "");

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
template <typename T, T t_Left, T t_Right> EMP_NOINSTANCE_CLASS_BASE(more, public, bool_<(t_Left > t_Right)>) };

static_assert(more<size_t, 0, 1>::value == false, "");
static_assert(more<size_t, 0, 0>::value == false, "");
static_assert(more<size_t, 1, 0>::value, "");

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
template <typename T, T t_Left, T t_Right> EMP_NOINSTANCE_CLASS_BASE(more_equal, public, bool_<t_Left >= t_Right>) };

static_assert(more_equal<size_t, 0, 1>::value == false, "");
static_assert(more_equal<size_t, 0, 0>::value, "");
static_assert(more_equal<size_t, 1, 0>::value, "");

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
template <typename L, typename R> EMP_NOINSTANCE_CLASS_BASE(equal, public, false_) };
template <typename T> EMP_NOINSTANCE_CLASS_BASE(EMP_PP_FORWARD(equal<T, T>), public, true_) };

template <typename L, typename R> using not_equal = not_<equal<L, R>::value>;

static_assert(equal<int, int>::value, "");
static_assert(not_equal<int, char>::value, "");

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
EMP_NOINSTANCE_CLASS_BASE(null, public, integral<int, 0>) };
EMP_TT_DECLARE_VALUE(is_null, equal<T, null>)
EMP_TT_DECLARE_VALUE(is_not_null, not_<is_null<T>::value>)

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
template <typename T, bool t_bTry, template <typename> class t_Type>
EMP_NOINSTANCE_STRUCT(try_impl_t)
    typedef T type;
};

template <typename T, template <typename> class t_Type>
EMP_NOINSTANCE_STRUCT(try_impl_t<T, true, t_Type>)
    typedef typename t_Type<T>::type type;
};

template <typename T, bool t_bTry, template <typename> class t_Type>
using try_impl = typename try_impl_t<T, t_bTry, t_Type>::type;

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
template <typename T, bool t_bTry, template <typename> class t_Type>
EMP_NOINSTANCE_STRUCT(try_t)
    typedef T type;
};

template <typename T, template <typename> class t_Type>
EMP_NOINSTANCE_STRUCT(try_t<T, true, t_Type>)
    typedef t_Type<T> type;
};
template <typename T, template <typename> class t_Try, template <typename> class t_Type>
using try_ = typename try_t<T, t_Try<T>::value, t_Type>::type;

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
template <bool t_bIf, typename t_Then, typename t_Else>
EMP_NOINSTANCE_STRUCT(if_else_t)
    typedef t_Then type;
};

template <typename t_Then, typename t_Else>
EMP_NOINSTANCE_STRUCT(if_else_t<false, t_Then, t_Else>)
    typedef t_Else type;
};

template <bool t_bIf, typename t_Then, typename t_Else>
using if_else = typename if_else_t<t_bIf, t_Then, t_Else>::type;

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
template <bool t_bIf, typename T = void>
EMP_NOINSTANCE_STRUCT(enable_if_t)
};

template <typename T>
EMP_NOINSTANCE_STRUCT(enable_if_t<true, T>)
    typedef T type;
};

template <bool t_bIf, typename T = void> using enable_if = typename enable_if_t<t_bIf, T>::type;
template <bool t_bIf, typename T = void> using enable_if_not = typename enable_if_t<t_bIf == false, T>::type;

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

#define ENABLE_IF(...) typename emp::tt::enable_if<__VA_ARGS__>* = nullptr
#define ENABLE_IF_REAL(...) ENABLE_IF(tt::is_real<__VA_ARGS__>::value)
#define ENABLE_IF_NOT_REAL(...) ENABLE_IF(tt::is_not_real<__VA_ARGS__>::value)
#define ENABLE_IF_SIGNED(...) ENABLE_IF(tt::is_signed<__VA_ARGS__>::value)
#define ENABLE_IF_NOT_SIGNED(...) ENABLE_IF(tt::is_not_signed<__VA_ARGS__>::value)
#define ENABLE_IF_POINTER(...) ENABLE_IF(tt::is_pointer<__VA_ARGS__>::value)
#define ENABLE_IF_INTEGRAL(...) ENABLE_IF(tt::is_integral<__VA_ARGS__>::value)
#define ENABLE_IF_NOT_INTEGRAL(...) ENABLE_IF(tt::is_not_integral<__VA_ARGS__>::value)
#define ENABLE_IF_CONST(...) ENABLE_IF(tt::is_const<__VA_ARGS__>::value)
#define ENABLE_IF_NOT_CONST(...) ENABLE_IF(tt::is_not_const<__VA_ARGS__>::value)

#define ENABLE_IF_B(...) template <bool t_bValue, ENABLE_IF(t_bValue == __VA_ARGS__)>
#define ENABLE_IF_T(...) template <typename T, ENABLE_IF(__VA_ARGS__)>
#define ENABLE_IF_REAL_T template <typename T, ENABLE_IF_REAL(T)>
#define ENABLE_IF_SIGNED_T template <typename T, ENABLE_IF_SIGNED(T)>
#define ENABLE_IF_NOT_SIGNED_T template <typename T, ENABLE_IF_NOT_SIGNED(T)>
#define ENABLE_IF_POINTER_T template <typename T, ENABLE_IF_POINTER(T)>
#define ENABLE_IF_INTEGRAL_T template <typename T, ENABLE_IF_INTEGRAL(T)>
#define ENABLE_IF_NOT_INTEGRAL_T template <typename T, ENABLE_IF_NOT_INTEGRAL(T)>

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
} }

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#endif
