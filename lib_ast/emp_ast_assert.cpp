//-----------------------------------------------------------------------------
// emp_ast_assert.cpp - @rgba8.org
//-----------------------------------------------------------------------------
#include "emp_ast_assert.h"

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#include "emp_app_application.h"

#include "emp_hh_stdio.h"
#include "emp_hh_stdlib.h"

#include "emp_xx_string.h"

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
namespace emp { namespace ast {

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void output_char(c_char a_cValue)
{ fputc(a_cValue, stdout); }

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void output_pchar(cpc_char a_pValue)
{
    EMP_ASSERT(a_pValue);
    fputs(a_pValue, stdout);
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void output_line(cpc_char a_szName, cpc_char a_szValue, c_bool a_bVerbose)
{
    if (a_bVerbose)
    {
        output_pchar(EMP_XSZ_NEWLINE_S1_SPACE);
        output_pchar(a_szName);
        output_pchar(EMP_XSZ_SPACE_COMMA_SPACE);
    }

    output_pchar(a_szValue);
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void output_header(cpc_char a_szName, c_char a_cAlias, c_bool a_bVerbose)
{
    if (a_bVerbose)
    {
        output_pchar(EMP_XSZ_S0);
        output_pchar(EMP_XSZ_NEWLINE_S1_SPACE);
        output_pchar(a_szName);
        output_pchar(EMP_XSZ_NEWLINE);
        output_pchar(EMP_XSZ_S0);
    }
    else
    {
        output_char(a_cAlias);
        output_pchar(EMP_XSZ_SPACE_COMMA_SPACE);
    }
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void output_trace(trace_c const& a_rTrace, c_bool a_bVerbose)
{
    if (a_bVerbose)
    {
        output_line(EMP_XSZ_FILE, a_rTrace.file().cstr(), a_bVerbose);
        output_line(EMP_XSZ_LINE, a_rTrace.sz_line().cstr(), a_bVerbose);
        output_line(EMP_XSZ_FUNCTION, a_rTrace.function().cstr(), a_bVerbose);
        output_line(EMP_XSZ_SIGNATURE, a_rTrace.signature().cstr(), a_bVerbose);
    }
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void output_assert(assert_c const& a_rAssert, bool const a_bVerbose)
{
    output_trace(a_rAssert.trace(), a_bVerbose);
    output_line(EMP_XSZ_CONDITION, a_rAssert.sz_condition().cstr(), a_bVerbose);
    output_pchar(EMP_XSZ_NEWLINE);
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void asserter_c::condition(emp::ast::assert_c const& a_rAssert)
{
    if (a_rAssert.b_condition() == false)
    {
        output_header(EMP_XSZ_ASSERT, EMP_XC_UPPER_A, true);
        output_assert(a_rAssert, true);
        abort();
    }
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
EMP_RETURN asserter_c& asserter(void)
{ return EMP_APPLICATION.asserter(); }

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
} }

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

