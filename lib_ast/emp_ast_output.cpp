//-----------------------------------------------------------------------------
//
// File Name : emp_ast_output.cpp
//
// Creation Date : Fri 15 Oct 2010 03:07:37 PM CEST
//
// Modification Date : sam. 09 nov. 2013 00:05:44 CET
//
// Created By : rgba8 (ksej) - www.empathy.fr
//
// Description :
//
//-----------------------------------------------------------------------------
#include "emp_ast_output.h"

#include "emp_ast_assert.h"
#include "emp_ast_statement.h"

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#include "emp_tt_assert.h"

#include "emp_hh_stdio.h"

#include "emp_xx_string.h"

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#if defined(EMP_XX_OUTPUT_ENABLE)

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
namespace emp { namespace ast {

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void output_char(char const a_cValue)
{ fputc(a_cValue, stdout); }

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void output_pchar(char const* const a_pValue)
{
    EMP_ASSERT(a_pValue);
    fputs(a_pValue, stdout);
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
/*void output_pwchar(wchar_t const* const a_pValue)
{
    EMP_ASSERT(a_pValue);
    printf("%ls", a_pValue);
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void output_puint32(uint32_t const* const a_pValue)
{
    EMP_STATIC_ASSERT(sizeof(uint32_t) == sizeof(wchar_t));
    //output_pwchar(reinterpret_cast<wchar_t const*>(a_pValue));
    output_pwchar(a_pValue);
}*/

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void output_line(   char const* const a_szName, char const* const a_szValue,
                    bool const a_bVerbose)
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
void output_header( char const* const a_szName, char const a_cAlias,
                    bool const a_bVerbose)
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
void output_statement(statement_t const& a_rStatement, bool const a_bVerbose)
{
    if (a_bVerbose)
    {
        output_line(EMP_XSZ_FILE, a_rStatement.file(), a_bVerbose);
        output_line(EMP_XSZ_LINE, a_rStatement.sz_line(), a_bVerbose);
        output_line(EMP_XSZ_FUNCTION, a_rStatement.function(), a_bVerbose);
        output_line(EMP_XSZ_SIGNATURE, a_rStatement.signature(), a_bVerbose);
    }
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void output_assert(assert_t const& a_rAssert, bool const a_bVerbose)
{
    output_statement(a_rAssert.statement(), a_bVerbose);

    output_line(EMP_XSZ_CONDITION, a_rAssert.sz_condition(), a_bVerbose);

    output_pchar(EMP_XSZ_NEWLINE);
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
} }

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#endif

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
