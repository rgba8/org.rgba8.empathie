//-----------------------------------------------------------------------------
// emp_tt_enum.def.h - @rgba8.org
//-----------------------------------------------------------------------------
#include "emp_tt_enum.h"
 
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#ifndef enum_name
#error enum_name NOT defined
#endif

#ifndef enum_values
#error enum_values NOT defined
#endif

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#ifdef enum_value_1
#error enum_value_1 is defined
#endif

#ifdef enum_value_2
#error enum_value_2 is defined
#endif

#ifdef enum_value_ex_2
#error enum_value_ex_2 is defined
#endif

#ifdef enum_value_ex_3
#error enum_value_ex_3 is defined
#endif

#ifndef enum_base
#define enum_base ui32
#endif

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
enum class enum_name : enum_base
{
#define enum_value_1(x_Name)                     x_Name,
#define enum_value_2(x_Name, x_Value)            x_Name = x_Value,
#define enum_value_ex_2(x_Name, x_User)          enum_value_1(x_Name)
#define enum_value_ex_3(x_Name, x_Value, x_User) enum_value_2(x_Name, x_Value)
        enum_values
#undef enum_value_1
#undef enum_value_2
#undef enum_value_ex_2
#undef enum_value_ex_3
};
typedef enum_name const EMP_PP_CAT(c_, enum_name);


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#ifdef enum_type
template <typename Dummy = void>
EMP_NOINSTANCE_STRUCT(enum_class)
//{

    static constexpr c_size count =
#define enum_value_1(x_Name)                     1 +
#define enum_value_2(x_Name, x_Value)            enum_value_1(x_Name)
#define enum_value_ex_2(x_Name, x_User)          enum_value_1(x_Name)
#define enum_value_ex_3(x_Name, x_Value, x_User) enum_value_1(x_Name)
        enum_values
#undef enum_value_1
#undef enum_value_2
#undef enum_value_ex_2
#undef enum_value_ex_3
        0;

    static constexpr enum_name max = emp::tt::max_t<enum_name
#define enum_value_1(x_Name)                     ,enum_name::x_Name
#define enum_value_2(x_Name, x_Value)            enum_value_1(x_Name)
#define enum_value_ex_2(x_Name, x_User)          enum_value_1(x_Name)
#define enum_value_ex_3(x_Name, x_Value, x_User) enum_value_1(x_Name)
        enum_values
#undef enum_value_1
#undef enum_value_2
#undef enum_value_ex_2
#undef enum_value_ex_3
        >::value;

    static constexpr aliteral m_sEmpty = "";
    static constexpr aliteral names[enum_class::count]
    {
#define enum_value_1(x_Name)                     EMP_PP_STRING(x_Name),
#define enum_value_2(x_Name, x_Value)            enum_value_1(x_Name)
#define enum_value_ex_2(x_Name, x_user)          enum_value_1(x_Name)
#define enum_value_ex_3(x_Name, x_Value, x_User) enum_value_1(x_Name)
        enum_values
#undef enum_value_1
#undef enum_value_2
#undef enum_value_ex_2
#undef enum_value_ex_3
    };

public:
    static constexpr enum_name e_values[enum_class::count]
    {
#define enum_value_1(x_Name)                     enum_name::x_Name,
#define enum_value_2(x_Name, x_Value)            enum_value_1(x_Name)
#define enum_value_ex_2(x_Name, x_user)          enum_value_1(x_Name)
#define enum_value_ex_3(x_Name, x_Value, x_User) enum_value_1(x_Name)
        enum_values
#undef enum_value_1
#undef enum_value_2
#undef enum_value_ex_2
#undef enum_value_ex_3
    };

    static constexpr size_t st_values[enum_class::count]
    {
#define enum_value_1(x_Name)                     static_cast<size_t>(enum_name::x_Name),
#define enum_value_2(x_Name, x_Value)            enum_value_1(x_Name)
#define enum_value_ex_2(x_Name, x_user)          enum_value_1(x_Name)
#define enum_value_ex_3(x_Name, x_Value, x_User) enum_value_1(x_Name)
        enum_values
#undef enum_value_1
#undef enum_value_2
#undef enum_value_ex_2
#undef enum_value_ex_3
    };

    // is_valid
    //
    template <enum_name t_eValue>
    static constexpr EMP_RETURN bool is_valid(void)
    { return is_valid_t<t_eValue>::value; }

    template <size_t t_stValue>
    static constexpr EMP_RETURN bool is_valid(void)
    { return t_stValue < to_t<max>::value; }

    static constexpr EMP_RETURN bool is_valid(enum_name a_eValue)
    { return a_eValue <= max; }

    template <enum_name t_eValue>
    EMP_NOINSTANCE_STRUCT(is_valid_t)
        static constexpr const bool value = t_eValue <= max;
    };

    // from
    //
    static EMP_RETURN enum_name from(size_t const a_stFrom)
    {
        // @@2 : runtime_cast
        enum_name const eValue = static_cast<enum_name>(a_stFrom);
        EMP_ASSERT(is_valid(eValue));
        return eValue;
    }

    template <size_t t_stValue>
    static constexpr EMP_RETURN enum_name from(void)
    {
        static_assert(is_valid<t_stValue>(), "");
        constexpr enum_name const eValue = static_cast<enum_name>(t_stValue);
        static_assert(is_valid<eValue>(), "");
        return eValue;
    }

    template <size_t t_stValue>
    EMP_NOINSTANCE_STRUCT(from_t)
        static_assert(is_valid<t_stValue>(), "");
        static constexpr enum_name const value = static_cast<enum_name>(t_stValue);
    };

    // to
    //
    template <typename T = size_t>
    static EMP_RETURN T to(enum_name const a_eValue)
    {
        EMP_ASSERT(is_valid(a_eValue));
        return static_cast<T>(a_eValue);
    }

    template <enum_name t_eValue, typename T = size_t>
    static constexpr EMP_RETURN T to(void)
    {
        static_assert(is_valid<t_eValue>(), "");
        static_assert(static_cast<size_t>(t_eValue) <= emp::tt::max<T>::value, "");
        static_assert(t_eValue <= e_values[count - 1], "");
        return static_cast<T>(t_eValue);
    }

    template <enum_name t_eValue, typename T = size_t>
    EMP_NOINSTANCE_STRUCT(to_t)
        static_assert(is_valid_t<t_eValue>::value, "");
        static_assert(static_cast<size_t>(t_eValue) <= emp::tt::max<T>::value, "");
        static_assert(t_eValue <= e_values[count - 1], "");
        static constexpr c_size value = static_cast<T>(t_eValue);
    };

    // name
    //
    static EMP_RETURN c_aliteral& name(enum_name const a_eValue)
    {
        EMP_ASSERT(is_valid(a_eValue));
        if (is_valid(a_eValue))
        { return names[to(a_eValue)]; }
        return m_sEmpty;
    }

    // assert
    static_assert(count <= emp::tt::max<size_t>::value, "");
    static_assert(emp::tt::max<enum_base>::value <= emp::tt::max<size_t>::value, "");
    static_assert(to_t<max, size_t>::value <= emp::tt::max<size_t>::value, "");
};
template <typename D>
EMP_RETURN enum_class<D>& enum_alias(enum_name const& a_rFrom);

//template <typename D>
//EMP_RETURN enum_class<D>& enum_alias_t(enum_name const& a_rFrom);

template <typename D> constexpr aliteral enum_class<D>::names[enum_class<D>::count];

template <typename D> constexpr aliteral enum_class<D>::m_sEmpty;

#endif

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#undef enum_name
#undef enum_values
#undef enum_base
#undef enum_type

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
