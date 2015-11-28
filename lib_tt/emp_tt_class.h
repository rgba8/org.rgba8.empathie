//-----------------------------------------------------------------------------
// emp_tt_class.h - @rgba8.org
//-----------------------------------------------------------------------------
#ifndef EMP_TT_CLASS_H
#define EMP_TT_CLASS_H

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#include "emp_tt_logical.h"

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#include <type_traits>

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
namespace emp { namespace tt {

#define EMP_TT_HAS_FUNCTION(x_Name)\
template <typename C, typename F, typename = void>\
EMP_NOINSTANCE_BASE(struct, EMP_PP_CAT(has_function_, x_Name), public, emp::tt::false_) };\
template <typename C, typename R, typename... A>\
EMP_NOINSTANCE_BASE(struct, (EMP_PP_CAT(has_function_, x_Name)\
    <\
        C, R(A...),\
        tt::enable_if\
        <\
            tt::equal<R, void>::value ||\
            std::is_convertible<decltype(std::declval<C>().x_Name(std::declval<A>()...)), R>::value\
        >\
    >), public, tt::true_)\
};

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
EMP_TT_HAS_FUNCTION(pre_load)
EMP_TT_HAS_FUNCTION(post_load)

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
struct test_1
{
    virtual ~test_1(void) {}
    bool pre_load(void) { return true; };
};

EMP_NOCOPY_BASE(struct, test_2, public, test_1) };

struct test_3
{
};

static_assert(emp::tt::equal<test_2::tbases, std::tuple<test_1>>::value, "");

static_assert(has_function_pre_load<test_3, bool(*)(void)>::value == false, "");
static_assert(has_function_pre_load<test_2, bool(void)>::value, "");
static_assert(has_function_pre_load<test_1, bool(void)>::value, "");

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
template <typename B, typename D>
using is_base = std::is_base_of<B, D>;

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
template<typename T, typename R = void>
EMP_NOINSTANCE(struct, enable_if_type) typedef R type; };

#define EMP_TT_HAS_TYPEDEF(x_Typedef)\
template <typename T, class D = void>\
EMP_NOINSTANCE_BASE(struct,  has_typedef_##x_Typedef, public, false_) };\
template <typename T>\
EMP_NOINSTANCE_BASE(struct, (has_typedef_##x_Typedef<T, typename enable_if_type<typename T::x_Typedef>::type>), public, true_) };

EMP_TT_HAS_TYPEDEF( type   );
EMP_TT_HAS_TYPEDEF( tbases );
EMP_TT_HAS_TYPEDEF( tbase1 );
EMP_TT_HAS_TYPEDEF( tbase2 );
EMP_TT_HAS_TYPEDEF( tbase3 );

static_assert(has_typedef_tbases<test_3>::value == false, "");
static_assert(has_typedef_tbases<test_2>::value, "");

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
} }

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#endif

