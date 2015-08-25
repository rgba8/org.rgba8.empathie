//-----------------------------------------------------------------------------
// @rgba8.org
//-----------------------------------------------------------------------------
#ifndef EMP_TT_HAS_BASE_H
#define EMP_TT_HAS_BASE_H

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#include "emp_pp_forward.h"

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
EMP_NOINSTANCE_CLASS(EMP_PP_FORWARD_3(get_base_t<T, V, false>))
public:
    typedef V type;
};

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
} }

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#endif

