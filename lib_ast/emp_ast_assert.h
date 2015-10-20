//-----------------------------------------------------------------------------
// emp_ast_assert.h - @rgba8.org
//-----------------------------------------------------------------------------
#ifndef EMP_AST_ASSERTER_H
#define EMP_AST_ASSERTER_H

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#include "emp_pp_comma.h"
#include "emp_pp_string.h"

#include "emp_tt_silent.h"

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#define EMP_TRACE()\
    emp::ast::trace_c(\
        EMP_XX_FILE,\
        EMP_XX_LINE,\
        EMP_PP_STRING(EMP_XX_LINE),\
        EMP_XX_FUNCTION,\
        EMP_XX_SIGNATURE)

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#define EMP_TRACE_COMMA EMP_PP_COMMA()
#define EMP_TRACE_ARG a_rTrace
#define EMP_TRACE_PARAM emp::ast::trace_c const& a_rTrace
#define EMP_TRACE_UNUSED EMP_UNUSED
#define EMP_TRACE_HERE EMP_TRACE()
namespace emp { namespace ast { class trace_c; } }

#define EMP_TRACE_ARG_COMMA EMP_TRACE_ARG EMP_TRACE_COMMA
#define EMP_TRACE_PARAM_COMMA EMP_TRACE_PARAM EMP_TRACE_COMMA
#define EMP_TRACE_PARAM_UNUSED EMP_TRACE_PARAM EMP_TRACE_UNUSED
#define EMP_TRACE_PARAM_UNUSED_COMMA EMP_TRACE_PARAM_UNUSED EMP_TRACE_COMMA
#define EMP_TRACE_HERE_COMMA EMP_TRACE_HERE EMP_TRACE_COMMA

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
namespace emp { namespace ast {

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
EMP_CLASS(trace_c)
private:
    tt::aliteral m_sFile;
    uint m_uiLine;
    tt::aliteral m_sLine;
    tt::aliteral m_sFunction;
    tt::aliteral m_sSignature;

public:
    trace_c(
        tt::c_aliteral& a_sFile,
        c_uint a_uiLine,
        tt::c_aliteral& a_sLine,
        tt::c_aliteral& a_sFunction,
        tt::c_aliteral& a_sSignature):
        m_sFile(a_sFile),
        m_uiLine(a_uiLine),
        m_sLine(a_sLine),
        m_sFunction(a_sFunction),
        m_sSignature(a_sSignature)
    {}

public:
    EMP_RETURN tt::c_aliteral& file(void) const { return m_sFile; }
    EMP_RETURN uint ui_line(void) const { return m_uiLine; }
    EMP_RETURN tt::c_aliteral& sz_line(void) const { return m_sLine; }
    EMP_RETURN tt::c_aliteral& function(void) const { return m_sFunction; }
    EMP_RETURN tt::c_aliteral& signature(void) const { return m_sSignature; }
};

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
EMP_CLASS(assert_c)
private:
    bool m_bCondition;
    tt::aliteral m_sCondition;
    trace_c  m_Trace;

public:
    assert_c(
        c_bool a_bCondition,
        tt::c_aliteral& a_sCondition,
        trace_c const& a_rTrace):
        m_bCondition(a_bCondition),
        m_sCondition(a_sCondition),
        m_Trace(a_rTrace)
    { }

public:
    EMP_RETURN bool b_condition(void) const { return m_bCondition; }
    EMP_RETURN tt::c_aliteral& sz_condition(void) const { return m_sCondition; }
    EMP_RETURN trace_c const& trace(void) const { return m_Trace; }
};

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
EMP_NOCOPY_CLASS(asserter_c)
public:
    asserter_c(void) {}
    void condition(assert_c const& a_rAssert);
};

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
EMP_RETURN asserter_c& asserter(void);

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void output_char(c_char a_cValue);
void output_pchar(cpc_char a_pValue);
void output_line(cpc_char a_szName, cpc_char a_szValue, c_bool a_bVerbose);
void output_header(cpc_char a_szName, c_char a_cAlias, c_bool a_bVerbose);
void output_trace(trace_c const& a_rTrace, c_bool a_bVerbose);
void output_assert(assert_c const& a_rAssert, c_bool a_bVerbose);

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
} }

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#ifdef EMP_XX_ASSERT

#define EMP_ASSERTER emp::ast::asserter()
#define EMP_ASSERT_HERE(x_Condition) emp::ast::assert_c(x_Condition, EMP_PP_STRING(x_Condition), EMP_TRACE_HERE)
#define EMP_ASSERT(x_Condition) do { EMP_ASSERTER.condition(EMP_ASSERT_HERE(x_Condition)); } while(0)
#define EMP_ASSERT_UNREACHABLE() EMP_ASSERT(false);
#define EMP_ASSERT_NOT_IMPLEMENTED() EMP_ASSERT(false);
#define EMP_ASSERT_BOOL_CALL(x_Call) EMP_ASSERT(x_Call)

#else

#define EMP_ASSERT(x_Condition) EMP_XX_NOOP()
#define EMP_ASSERT_UNREACHABLE() EMP_XX_NOOP()
#define EMP_ASSERT_NOT_IMPLEMENTED() static_assert(false, "not implemented")
#define EMP_ASSERT_BOOL_CALL(x_Call) emp::tt::silent(x_Call)

#endif

#define EMP_ASSERT_NOT(x_Condition) EMP_ASSERT((x_Condition))


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#endif

