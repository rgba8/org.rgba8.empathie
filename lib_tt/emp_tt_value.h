//-----------------------------------------------------------------------------
// emp_tt_value.h - @rgba8.org
//-----------------------------------------------------------------------------
#ifndef EMP_TT_VALUE_H
#define EMP_TT_VALUE_H

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
namespace emp { namespace tt {

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
/* @@0 remove template <typename T>
class value
{
    T m_tValue;
};

template <>
class value<void>
{
};*/


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
template <typename t_Values, typename T, size_t t_stCount>
EMP_NOINSTANCE_CLASS(value_initialize_impl)
public:
    static EMP_RETURN bool apply(t_Values& a_rValues, T const a_tFrom)
    {
        size_t const stIndex = t_stCount - 1;
        typedef typename emp::tt::list_type<
            typename t_Values::tlist, stIndex>::type tto;
        tto tTo = 0;


        if (emp::saf::try_cast(a_tFrom, tTo) == false)
        { EMP_ASSERT(false); return false; }

        a_rValues.template ref<stIndex>() = tTo;

        return value_initialize_impl<t_Values, T, stIndex>
            ::apply(a_rValues, a_tFrom);
    }
};

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
template <typename t_Values, typename T>
EMP_NOINSTANCE_CLASS(value_initialize_impl<t_Values, T, 0>)
public:
    static EMP_RETURN bool apply( t_Values& a_rValues EMP_UNUSED,
                                T const a_tFrom EMP_UNUSED)
    { return true; }
};

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
template <typename t_Values, typename T>
EMP_NOINSTANCE_CLASS(value_initialize)
public:
    static EMP_RETURN bool apply(t_Values& a_rValues, T const a_tFrom)
    {
        return value_initialize_impl<t_Values, T, t_Values::numberof_T>
            ::apply(a_rValues, a_tFrom);
    }
};

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
template <typename t_Values, typename T>
EMP_NOINSTANCE_CLASS(value_get)
public:
    static EMP_RETURN T apply(t_Values const& a_rValues)
    {
        size_t const stIndex = emp::tt::list_index<
            typename t_Values::tlist, T>::value;
        return a_rValues.template val<stIndex>();
    }
};

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
template <typename t_Values, size_t t_stCount>
EMP_NOINSTANCE_CLASS(value_compare_impl)
public:
    static EMP_RETURN bool apply( t_Values const& a_rLeft,
                                t_Values const& a_rRight)
    {
        size_t const stIndex = t_stCount - 1;
        if (emp::tt::equal_(
            a_rLeft.template ref<stIndex>(),
            a_rRight.template ref<stIndex>()))
        { EMP_ASSERT(false); return false; }

        return value_compare_impl<t_Values, stIndex>
            ::apply(a_rLeft, a_rRight);
    }
};

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
template <typename t_Values>
EMP_NOINSTANCE_CLASS(EMP_PP_FORWARD(value_compare_impl<t_Values, 0>))
public:
    static EMP_RETURN bool apply( t_Values const& a_rLeft EMP_UNUSED,
                                t_Values const& a_rRight EMP_UNUSED)
    { return true; }
};

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
template <typename t_Values>
EMP_NOINSTANCE_CLASS(value_compare)
public:
    static EMP_RETURN bool apply( t_Values const& a_rLeft,
                                t_Values const& a_rRight)
    {
        return value_compare_impl<t_Values, t_Values::numberof_T>
            ::apply(a_rLeft, a_rRight);
    }
};

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
template <typename t_Values>
EMP_CLASS(value)
public:
    value(void):
    m_tValues(),
    m_bInitialized(false)
    { }

public:
    template <typename T>
    EMP_RETURN bool create(T const a_tValue)
    {
        EMP_ASSERT(false == initialized());

        if (value_initialize<t_Values, T>
            ::apply(m_tValues, a_tValue) == false)
        { EMP_ASSERT(false); return false; }

        m_bInitialized = true;

        return true;
    }

    void destroy(void)
    {
        EMP_ASSERT(initialized());
        m_bInitialized = false;
    }

public:
    template <typename T>
    EMP_RETURN T val(void) const
    {
        EMP_ASSERT(initialized());
        return value_get<t_Values, T>::apply(m_tValues);
    }

public:
    EMP_RETURN bool operator==(value const& a_rFrom) const
    {
        EMP_ASSERT(initialized());
        EMP_ASSERT(a_rFrom.initialized());
        return value_compare
            <t_Values>::apply(m_tValues, a_rFrom.m_tValues);
    }

    template <typename T>
    EMP_RETURN bool operator==(T const& a_rFrom) const
    {
        EMP_ASSERT(initialized());
        return emp::tt::equal_(
            value_get<t_Values, T>::apply(m_tValues), a_rFrom);
    }

public:
    EMP_RETURN bool initialized(void) const
    { return m_bInitialized; }

private:
    t_Values m_tValues;
    bool m_bInitialized;
};

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
template <>
EMP_INLINE value<emp::cnt::tuple<uint, int> >::value(void):
m_tValues(0, 0),
m_bInitialized(false)
{}

template <>
EMP_INLINE value<emp::cnt::tuple<uint, int, float> >::value(void):
m_tValues(0, 0, 0.0f),
m_bInitialized(false)
{}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
typedef value<emp::cnt::tuple<uint, int> > value_ui_si;
typedef value<emp::cnt::tuple<uint, int, float> > value_ui_si_f;


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
} }

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#endif

