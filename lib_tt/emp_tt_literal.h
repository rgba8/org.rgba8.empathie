//-----------------------------------------------------------------------------
// emp_tt_literal.h - @rgba8.org
//-----------------------------------------------------------------------------
#ifndef EMP_TT_LITERAL_H
#define EMP_TT_LITERAL_H

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
EMP_INLINE constexpr bool const_assert(c_bool a_bCondition)
{ return a_bCondition ? true : not_const(a_bCondition); }

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
template <typename T>
class literal_t
{
public:
    T const* m_szLiteral;
    size_t m_stSize;
    size_t m_stLen;

public:
    literal_t(void):
        m_szLiteral(nullptr),
        m_stSize(0),
        m_stLen(0)
    {}

    template <size_t t_stSize>
    constexpr EMP_INLINE literal_t(T const (&a_szLiteral)[t_stSize] ) :
        m_szLiteral(a_szLiteral),
        m_stSize(t_stSize - 1),
        m_stLen()
    {
        static_assert(t_stSize >= 1, "");
    }
 
    constexpr EMP_INLINE EMP_RETURN T operator[](c_size a_stIndex) const
    {
        const_assert(a_stIndex < m_stSize);
        return m_szLiteral[a_stIndex];
    }

    constexpr EMP_INLINE EMP_RETURN size_t size(void) const
    { return m_stSize; }

    constexpr EMP_INLINE EMP_RETURN size_t len(void) const
    { return m_stLen; }

    //constexpr EMP_INLINE EMP_RETURN operator const T *(void) const
    //{ return m_szLiteral; }

    constexpr EMP_INLINE EMP_RETURN T const* cstr(void) const
    { return m_szLiteral; }
    
private:
    static constexpr EMP_INLINE EMP_RETURN size_t len_impl(literal_t const str, c_size i, c_size result)
    { return i == str.size() ? result : str[i] == '\0' ? result : len_impl(str, i + 1, result + 1); }

public:
    static constexpr EMP_INLINE EMP_RETURN size_t len(literal_t const str)
    {
        c_size stLen = len_impl(str, 0, 0);
        const_assert(stLen == str.size());
        return stLen;
    }
};

using aliteral = literal_t<char>;
EMP_TYPEDEF(aliteral);

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
} }

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#endif

