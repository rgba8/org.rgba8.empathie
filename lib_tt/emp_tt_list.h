//-----------------------------------------------------------------------------
// emp_tt_list.h - @rgba8.org
//-----------------------------------------------------------------------------
#ifndef EMP_TT_LIST_H
#define EMP_TT_LIST_H

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
// @@0 remove
/*namespace emp { namespace tt {

template <size_t t_stSize, typename L>
struct list_get_t
{ typedef typename list_get_t<t_stSize - 1, typename L::tail>::type type; };

template <typename H>
struct list_get_t<0, H>
{ typedef typename H::head type; };

template <size_t t_stSize, typename L>
using list_get = typename list_get_t<t_stSize, L>::type;

static_assert(equal<list_get<0, list<unsigned int, int, char, float>>, unsigned int>::value, "");
static_assert(equal<list_get<1, list<unsigned int, int, char, float>>, int>::value, "");
static_assert(equal<list_get<2, list<unsigned int, int, char, float>>, char>::value, "");
static_assert(equal<list_get<3, list<unsigned int, int, char, float>>, float>::value, "");

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
} }*/

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#endif

