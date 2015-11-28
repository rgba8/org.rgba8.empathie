//-----------------------------------------------------------------------------
// emp_tt_literal.h - @rgba8.org
//-----------------------------------------------------------------------------
#ifndef EMP_TT_LITERAL_H
#define EMP_TT_LITERAL_H

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#include <assert.h>

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
namespace emp { namespace tt {

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
EMP_INLINE bool not_const(c_bool a_bCondition);
EMP_INLINE bool not_const(c_bool a_bCondition EMP_UNUSED)
{ return false; }

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//EMP_INLINE constexpr bool const_assert(c_bool a_bCondition)
//{ return a_bCondition ? true : not_const(a_bCondition); }

#define const_assert assert

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#define XLITERAL(x_Literal, x_Cstr) x_Literal(x_Cstr, emp::tt::integral<size_t, x_Literal::len(x_Cstr)>::value)

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
class aliteral
{
public:
    char const* m_szLiteral;
    size_t m_stSize;
    size_t m_stLen;

public:
    aliteral(void):
        m_szLiteral(nullptr),
        m_stSize(0),
        m_stLen(0)
    {}

    template <size_t t_stSize>
    explicit constexpr EMP_INLINE aliteral(char const (&a_szLiteral)[t_stSize], c_size a_stLen) :
        m_szLiteral(a_szLiteral),
        m_stSize(t_stSize),
        m_stLen(a_stLen)
    {
        static_assert(t_stSize >= 1, "");
        const_assert(a_stLen < t_stSize);
        const_assert(aliteral::len(a_szLiteral) == a_stLen);
        //const_assert(a_stLen < t_stSize);
        //const_assert(literal_t::len(a_szLiteral) == a_stLen);
    }
 
    constexpr EMP_INLINE EMP_RETURN char operator[](c_size a_stIndex) const
    {
        const_assert(a_stIndex < m_stSize);
        return m_szLiteral[a_stIndex];
    }

    constexpr EMP_INLINE EMP_RETURN size_t size(void) const { return m_stSize; }
    constexpr EMP_INLINE EMP_RETURN size_t len(void) const { return m_stLen; }
    constexpr EMP_INLINE EMP_RETURN char const* cstr(void) const { return m_szLiteral; }
    
public:
    template <size_t t_stSize>
    static constexpr EMP_INLINE EMP_RETURN size_t len(char const (&a_szLiteral)[t_stSize] )
    {
        size_t stLen = 0;
        const_assert(stLen < t_stSize);
        while (a_szLiteral[stLen] != '\0')
        {
            const_assert(stLen < t_stSize);
            ++stLen;
        }
        return stLen;
    }
};

EMP_TYPEDEF(aliteral);
#define ALITERAL(x_Cstr) XLITERAL(emp::tt::aliteral, x_Cstr)

namespace {

static_assert(aliteral::len("abc") == 3, "");
static_assert(ALITERAL("abs").len() == 3, "");
constexpr c_char toto = ALITERAL("abs")[2];

}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
class u8literal
{
public:
    char const* m_szLiteral;
    size_t m_stSize;
    size_t m_stLen;

public:
    u8literal(void):
        m_szLiteral(nullptr),
        m_stSize(0),
        m_stLen(0)
    {}

    template <size_t t_stSize>
    explicit constexpr EMP_INLINE u8literal(char const (&a_szLiteral)[t_stSize], c_size a_stLen) :
        m_szLiteral(a_szLiteral), // @@0 ascii test
        m_stSize(t_stSize),
        m_stLen(a_stLen)
    {
        static_assert(t_stSize >= 1, "");
        const_assert(a_stLen < t_stSize);
        const_assert(u8literal::len(a_szLiteral) == a_stLen);
        //const_assert(a_stLen < t_stSize);
        //const_assert(literal_t::len(a_szLiteral) == a_stLen);
    }
 
    constexpr EMP_INLINE EMP_RETURN char operator[](c_size a_stIndex) const
    {
        const_assert(a_stIndex < m_stSize);
        return m_szLiteral[a_stIndex];
    }

    constexpr EMP_INLINE EMP_RETURN size_t size(void) const { return m_stSize; }
    constexpr EMP_INLINE EMP_RETURN size_t len(void) const { return m_stLen; }
    constexpr EMP_INLINE EMP_RETURN char const* cstr(void) const { return m_szLiteral; }
    
public:
    template <size_t t_stSize>
    static constexpr EMP_INLINE EMP_RETURN size_t len(char const (&a_szLiteral)[t_stSize] )
    {
        size_t stLen = 0;
        const_assert(stLen < t_stSize);
        while (a_szLiteral[stLen] != '\0')
        {
            const_assert(stLen < t_stSize);
            ++stLen;
        }
        return stLen;
    }
};

EMP_TYPEDEF(u8literal);
#define U8LITERAL(x_Cstr) XLITERAL(emp::tt::u8literal, x_Cstr)

namespace {

// @@0 static_assert

}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
template <typename T, size_t t_stArgs, size_t t_stExpected>
struct format_validator_t
{
    static_assert(t_stArgs == t_stExpected, "invalid format");
    typedef T type;
};

template <typename T, size_t t_stArgs, size_t t_stExpected>
using format_validator = typename format_validator_t<T, t_stArgs, t_stExpected>::type;

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#define XFORMAT(x_Format, x_Literal, x_Cstr, x_Count) emp::tt::format_validator\
    <x_Format, x_Count, x_Format::args(x_Literal(x_Cstr))>(x_Literal(x_Cstr), x_Count)

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
template <typename T>
class format_t
{
public:
    T m_Literal;
    size_t m_stArgs;

public:
    format_t(void):
        m_Literal(),
        m_stArgs(0)
    {}

    explicit constexpr EMP_INLINE format_t(T const& a_Literal, c_size a_stArgs) :
        m_Literal(a_Literal),
        m_stArgs(a_stArgs)
    {
        const_assert(args(a_Literal) == m_stArgs);
    }

public:
    constexpr EMP_RETURN size_t args(void) const
    { return m_stArgs; }

    constexpr EMP_RETURN T const& literal(void) const
    { return m_Literal; }
public:
    static constexpr EMP_INLINE EMP_RETURN size_t args(T const& a_Literal)
    {
        size_t stArgs = 0;
        c_size stLen = a_Literal.len();
        for (size_t stIndex = 0; stIndex < stLen; ++stIndex)
        {
            if (a_Literal[stIndex] == '#')
            { ++stArgs; }
        }
        return stArgs;
    }
};

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
using aformat_c = format_t<aliteral>;
EMP_TYPEDEF(aformat_c);
#define AFORMAT(x_Cstr, x_Count) XFORMAT(emp::tt::aformat_c, ALITERAL, x_Cstr, x_Count)

using u8format_c = format_t<u8literal>;
EMP_TYPEDEF(u8format_c);
#define U8FORMAT(x_Cstr, x_Count) XFORMAT(emp::tt::u8format_c, U8LITERAL, x_Cstr, x_Count)

static_assert(aformat_c::args(ALITERAL("#a#b#c")) == 3, "");
static_assert(AFORMAT("ab##", 2).args() == 2, "");
// @@0 static_assert

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
} }

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#endif

