//-----------------------------------------------------------------------------
// emp_tt_class.h - @rgba8.org
//-----------------------------------------------------------------------------
#ifndef EMP_TT_CLASS_H
#define EMP_TT_CLASS_H

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#define EMP_TT_HAS_FUNCTION(x_Function, x_Signature)\
template <typename T>\
EMP_NOINSTANCE_CLASS(EMP_PP_CAT(has_, x_Function))\
private:\
    template <typename S, x_Signature>\
    EMP_NOCOPY_CLASS(signature_t)\
    };\
    typedef char yes_type_c;\
    typedef struct { char m_acNo[2]; } no_type_c;\
    template <typename V>\
    static yes_type_c test_t(signature_t<V, &V::x_Function>*);\
    template <typename V>\
    static no_type_c test_t(...);\
public:\
    static const size_t value = sizeof(test_t<T>(nullptr)) == sizeof(yes_type_c) ||\
        EMP_PP_CAT(has_, x_Function) <\
        EMP_PP_FORWARD(typename emp::tt::get_base_t<T, void, emp::tt::has_base_t<T>::value>::type)>::value;\
};\
template <>\
EMP_NOINSTANCE_CLASS(EMP_PP_CAT(has_, x_Function<void>))\
public:\
    static const bool value = false;\
};

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
namespace emp { namespace tt {

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
template <typename T>
EMP_NOINSTANCE_CLASS(has_base_t)
private:
    typedef char yes_type_c;
    typedef struct { char m_acNo[2]; } no_type_c;

    template <typename V>
    static yes_type_c test_t(typename V::tbase*);

    template <typename V>
    static no_type_c test_t(...);

public:
    static const size_t value = sizeof(test_t<T>(nullptr)) == sizeof(yes_type_c);
};

template <typename T, typename V, bool a_bValue>
EMP_NOINSTANCE_CLASS(get_base_t)
public:
    typedef typename T::tbase type;
};

template <typename T, typename V>
EMP_NOINSTANCE_CLASS(get_base_t<T, V, false>)
public:
    typedef V type;
};

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
EMP_TT_HAS_FUNCTION(pre_load, bool (S::*)(void))

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
struct test_1
{
    virtual ~test_1(void) {}
    bool pre_load(void) { return true; };
};

EMP_NOCOPY_CLASS_BASE(test_2, public, test_1)
public:
};

struct test_3
{
};

static_assert(has_pre_load<test_3>::value == false, "");
static_assert(has_pre_load<test_2>::value, "");
static_assert(has_pre_load<test_1>::value, "");

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
class not_empty_base
{
public:
    not_empty_base(void) : m_siPadding(0) {}
private:
#ifdef EMP_XX_COMPILER_LLVM
EMP_PRAGMA_PUSH_IGNORE(EMP_W_UNUSED_PRIVATE_FIELD)
#endif
    int m_siPadding;
#ifdef EMP_XX_COMPILER_LLVM
EMP_PRAGMA_POP_IGNORE(EMP_W_UNUSED_PRIVATE_FIELD)
#endif
};

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
template <typename B, typename D>
EMP_NOINSTANCE_CLASS(is_derived_t)
private:
    typedef char yes_type_c;
    typedef struct { char m_acNo[2]; } no_type_c;

    template <typename V>
    static yes_type_c test(B*);

    template <typename V>
    static no_type_c test(...);

    static D* get_derived(void);

public:
    static const size_t value = sizeof(test<B>(get_derived())) == sizeof(yes_type_c);
};

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
} }

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#endif

