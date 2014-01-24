//-----------------------------------------------------------------------------
//
// File Name : emp_tt_list.h
//
// Creation Date : Mon 07 Feb 2011 05:11:54 PM CET
//
// Modification Date : mar. 26 nov. 2013 18:11:14 CET
//
// Created By : ksej - www.rgba8.org
//
// Description :
//
//-----------------------------------------------------------------------------
#ifndef EMP_TT_LIST_H
#define EMP_TT_LIST_H

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#include "emp_tt_are_equal.h"
#include "emp_tt_constant.h"
#include "emp_tt_if_else.h"
#include "emp_tt_integral.h"
#include "emp_tt_null.h"

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#include "emp_xx_noinstance_class.h"

#include "emp_hh_stddef.h"

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
    EMP_TT_CONSTANT(size_t, value,
                    list_count<typename t_List::tail>::value + 1);
};

template <>
EMP_NOINSTANCE_CLASS(list_count<emp::tt::null>)
public:
    EMP_TT_CONSTANT(size_t, value, 0);
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
    typedef typename emp::tt::if_else<
        emp::tt::are_equal<typename t_List::head, T>::value,
        emp::tt::integral<size_t, t_stIndex>,
        typename list_index_impl<typename t_List::tail, T, t_stIndex + 1>::type
    >::type type;
};

template <typename T, size_t t_stIndex>
EMP_NOINSTANCE_CLASS(
    EMP_PP_FORWARD_3(list_index_impl<emp::tt::null, T, t_stIndex>))
public:
    typedef emp::tt::integral<size_t, t_stIndex> type;
};

template <typename t_List, typename T>
EMP_NOINSTANCE_CLASS(list_index)
public:
    typedef typename list_index_impl<t_List, T, 0>::type type;
    EMP_TT_CONSTANT(size_t, value, type::value);
};

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
} }

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#define EMP_TT_LIST_1(T1) emp::tt::list<T1, emp::tt::null>
#define EMP_TT_LIST_2(T1, T2) emp::tt::list<T1, EMP_TT_LIST_1(T2)>
#define EMP_TT_LIST_3(T1, T2, T3) emp::tt::list<T1, EMP_TT_LIST_2(T2, T3)>
#define EMP_TT_LIST_4(T1, T2, T3, T4)\
    emp::tt::list<T1, EMP_TT_LIST_3(T2, T3, T4)>

#define EMP_TT_LIST_5(T1, T2, T3, T4, T5)\
    emp::tt::list<T1, EMP_TT_LIST_4(T2, T3, T4, T5)>

#define EMP_TT_LIST_6(T1, T2, T3, T4, T5, T6)\
    emp::tt::list<T1, EMP_TT_LIST_5(T2, T3, T4, T5, T6)>

#define EMP_TT_LIST_7(T1, T2, T3, T4, T5, T6, T7)\
    emp::tt::list<T1, EMP_TT_LIST_6(T2, T3, T4, T5, T6, T7)>

#define EMP_TT_LIST_8(T1, T2, T3, T4, T5, T6, T7, T8)\
    emp::tt::list<T1, EMP_TT_LIST_7(T2, T3, T4, T5, T6, T7, T8)>

#define EMP_TT_LIST_9(T1, T2, T3, T4, T5, T6, T7, T8, T9)\
    emp::tt::list<T1, EMP_TT_LIST_8(T2, T3, T4, T5, T6, T7, T8, T9)>


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
typedef EMP_TT_LIST_2(unsigned int, int) list_ui_si;

#ifndef EMP_TT_ASSERT_H
#include "emp_tt_assert.h"
#endif

EMP_STATIC_ASSERT_TYPE_EQUAL(
        EMP_PP_FORWARD(emp::tt::list_type<list_ui_si, 0>::type),
        unsigned int);
EMP_STATIC_ASSERT_TYPE_EQUAL(
        EMP_PP_FORWARD(emp::tt::list_type<list_ui_si, 1>::type),
        int);

EMP_STATIC_ASSERT(
        (emp::tt::list_index<list_ui_si, unsigned int>::value == 0));

EMP_STATIC_ASSERT(
        (emp::tt::list_index<list_ui_si, int>::value == 1));

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#endif

