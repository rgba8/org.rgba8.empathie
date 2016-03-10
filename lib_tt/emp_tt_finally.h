//-----------------------------------------------------------------------------
// emp_tt_finally.h - @rgba8.org
//-----------------------------------------------------------------------------
#ifndef EMP_TT_FINALLY_H
#define EMP_TT_FINALLY_H

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#include "emp_hh_utility.h"

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
namespace emp { namespace tt {

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
template <typename T>
EMP_(struct, scope_t)
    T* m_pScopee;
    explicit scope_t(T* a_pScopee) : m_pScopee(a_pScopee) { m_pScopee->start(); }
    ~scope_t(void) { m_pScopee->stop(); }
};

template <typename T>
EMP_RETURN EMP_INLINE scope_t<T> scope(T& a_rScopee)
{ return scope_t<T>(&a_rScopee); }

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
EMP_PRAGMA_PUSH_IGNORE(EMP_W_PADDING_ADDED)
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
EMP_PRAGMA_POP_IGNORE(EMP_W_PADDING_ADDED)

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

