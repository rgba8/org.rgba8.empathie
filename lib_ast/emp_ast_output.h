//-----------------------------------------------------------------------------
//
// File Name : emp_ast_output.h
//
// Creation Date : Mon 4 Jan 2009 10:41:27 PM CEST
//
// Modification Date : mar. 26 nov. 2013 18:09:08 CET
//
// Created By : luh - www.rgba8.org
//
// Description :
//
//-----------------------------------------------------------------------------
#ifndef EMP_AST_OUTPUT_H
#define EMP_AST_OUTPUT_H

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#include "emp_hh_stdint.h"

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#if defined(EMP_XX_OUTPUT_ENABLE)

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
namespace emp { namespace ast {

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
class assert_t;
class statement_t;

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void output_char(char const a_cValue);
void output_pchar(char const* const a_pValue);
//void output_pwchar(wchar_t const* const a_pValue);
//void output_puint32(uint32_t const* const a_pValue);
void output_line(
    char const* const a_szName, char const* const a_szValue,
    bool const a_bVerbose);

void output_header(
    char const* const a_szName, char const a_cAlias,
    bool const a_bVerbose);

void output_statement(statement_t const& a_rStatement, bool const a_bVerbose);

void output_assert(assert_t const& a_rAssert, bool const a_bVerbose);

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
} }

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#endif

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#endif

