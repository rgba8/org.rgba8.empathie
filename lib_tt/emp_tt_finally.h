//-----------------------------------------------------------------------------
// emp_tt_finally.h - @rgba8.org
//-----------------------------------------------------------------------------
#ifndef EMP_TT_FINALLY_H
#define EMP_TT_FINALLY_H

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#include <utility>

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
namespace emp { namespace tt {

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
template <typename T, bool t_bDefault>
struct finally_t
{
private:
    T m_Finalizer;
    bool m_bFinalize = t_bDefault;

public:
    finally_t(T&& a_rFinalize) :
        m_Finalizer(std::move(a_rFinalize)), m_bFinalize(t_bDefault) {}

    finally_t(finally_t&& a_rFrom) :
        m_Finalizer(std::move(a_rFrom.m_Finalizer)), m_bFinalize(a_rFrom.m_bFinalize)
    { a_rFrom.release(); }

    ~finally_t(void) { if (m_bFinalize) { m_Finalizer(); } }

    void release(void) { m_bFinalize = false; }

private:
    finally_t(finally_t const&) = delete;
    finally_t& operator=(finally_t const&) = delete;
    finally_t& operator=(finally_t&&) = delete;
};

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
template <typename T>
EMP_RETURN auto finally(T&& a_tLambda)
{ return finally_t<T, true>(std::forward<T>(a_tLambda)); }

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
} }

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#endif

