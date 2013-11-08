//-----------------------------------------------------------------------------
//
// File Name : emp_ast_dbg_statement.h
//
// Creation Date : Thu 10 Mar 2011 03:58:56 PM CET
//
// Modification Date : sam. 09 nov. 2013 00:05:58 CET
//
// Created By : rgba8 (ksej) - www.empathy.fr
//
// Description :
//
//-----------------------------------------------------------------------------
#ifndef EMP_AST_DBG_STATEMENT_H
#define EMP_AST_DBG_STATEMENT_H

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#include "emp_pp_comma.h"

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#ifdef EMP_XX_TRACK_LEAKS_ENABLE
#define EMP_XX_DBG_STATEMENT_COMMA EMP_PP_COMMA()
#define EMP_XX_DBG_STATEMENT_ARGUMENT a_rStatement
#define EMP_XX_DBG_STATEMENT_PARAMETER\
    emp::ast::statement_t const& a_rStatement
#define EMP_XX_DBG_STATEMENT_UNUSED EMP_AA_UNUSED
#define EMP_XX_DBG_STATEMENT_INFO EMP_STATEMENT_INFO()
namespace emp { namespace ast { class statement_t; } }
#else
#define EMP_XX_DBG_STATEMENT_COMMA
#define EMP_XX_DBG_STATEMENT_ARGUMENT
#define EMP_XX_DBG_STATEMENT_PARAMETER
#define EMP_XX_DBG_STATEMENT_UNUSED
#define EMP_XX_DBG_STATEMENT_INFO
#endif

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#endif

