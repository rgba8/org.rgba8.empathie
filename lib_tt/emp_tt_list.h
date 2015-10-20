//-----------------------------------------------------------------------------
// emp_tt_list.h - @rgba8.org
//-----------------------------------------------------------------------------
#ifndef EMP_TT_LIST_H
#define EMP_TT_LIST_H

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
namespace emp { namespace tt {

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
template <typename t_Head, typename t_Tail>
EMP_NOINSTANCE_CLASS(list)
public:
    typedef t_Head head;
    typedef t_Tail tail;
};

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
template <typename t_List>
EMP_NOINSTANCE_CLASS(list_count)
public:
    static size_t value = list_count<typename t_List::tail>::value + 1;
};

template <>
EMP_NOINSTANCE_CLASS(list_count<emp::tt::null>)
public:
    static size_t value = 0;
};

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
template <typename t_List, size_t t_stIndex>
EMP_NOINSTANCE_CLASS(list_type)
public:
    typedef typename list_type
        <typename t_List::tail, t_stIndex - 1>::type type;
};

template <typename t_List>
EMP_NOINSTANCE_CLASS(EMP_PP_FORWARD(list_type<t_List, 0>))
public:
    typedef typename t_List::head type;
};

template <size_t t_stIndex>
class list_type<emp::tt::null, t_stIndex>;

template <>
class list_type<emp::tt::null, 0>;

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
template <typename t_List, typename T, size_t t_stIndex>
EMP_NOINSTANCE_CLASS(list_index_impl)
public:
    typedef if_else<
        emp::tt::equal<typename t_List::head, T>::value,
        emp::tt::integral<size_t, t_stIndex>,
        typename list_index_impl<typename t_List::tail, T, t_stIndex + 1>::type
    > type;
};

template <typename T, size_t t_stIndex>
EMP_NOINSTANCE_CLASS(    typedef t_Signature tsignature;
EMP_PP_FORWARD(list_index_impl<emp::tt::null, T, t_stIndex>))
public:
    typedef emp::tt::integral<size_t, t_stIndex> type;
};

template <typename t_List, typename T>
EMP_NOINSTANCE_CLASS(list_index)
public:
    typedef typename list_index_impl<t_List, T, 0>::type type;
    static size_t value = type::value;
};

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#define EMP_TT_LIST_1(T1) emp::tt::list<T1, emp::tt::null>
#define EMP_TT_LIST_2(T1, T2) emp::tt::list<T1, EMP_TT_LIST_1(T2)>
#define EMP_TT_LIST_3(T1, T2, T3) emp::tt::list<T1, EMP_TT_LIST_2(T2, T3)>
#define EMP_TT_LIST_4(T1, T2, T3, T4) emp::tt::list<T1, EMP_TT_LIST_3(T2, T3, T4)>
#define EMP_TT_LIST_5(T1, T2, T3, T4, T5) emp::tt::list<T1, EMP_TT_LIST_4(T2, T3, T4, T5)>
#define EMP_TT_LIST_6(T1, T2, T3, T4, T5, T6) emp::tt::list<T1, EMP_TT_LIST_5(T2, T3, T4, T5, T6)>
#define EMP_TT_LIST_7(T1, T2, T3, T4, T5, T6, T7) emp::tt::list<T1, EMP_TT_LIST_6(T2, T3, T4, T5, T6, T7)>
#define EMP_TT_LIST_8(T1, T2, T3, T4, T5, T6, T7, T8) emp::tt::list<T1, EMP_TT_LIST_7(T2, T3, T4, T5, T6, T7, T8)>
#define EMP_TT_LIST_9(T1, T2, T3, T4, T5, T6, T7, T8, T9) emp::tt::list<T1, EMP_TT_LIST_8(T2, T3, T4, T5, T6, T7, T8, T9)>

static_assert(equal<list_type<EMP_TT_LIST_2(unsigned int, int), 0>::type), unsigned int>::value, "");
static_assert(equal<list_type<EMP_TT_LIST_2(unsigned int, int), 1>::type), int>::value, "");
static_assert(equal<list_index<EMP_TT_LIST_2(unsigned int, int), unsigned int>::value == 0, "");
static_assert(equal<list_index<EMP_TT_LIST_2(unsigned int, int), int>::value == 1, "");

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
} }


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#endif

