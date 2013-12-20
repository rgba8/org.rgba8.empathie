//-----------------------------------------------------------------------------
//
// File Name : emp_ast_statement.h
//
// Creation Date : Tue 12 Oct 2010 03:39:14 PM CEST
//
// Modification Date : Wed Dec 11 21:32:36 2013
//
// Created By : luh - www.rgba8.org
//
// Description :
//
//-----------------------------------------------------------------------------
#ifndef EMP_AST_STATEMENT_H
#define EMP_AST_STATEMENT_H

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#include "emp_xx_class.h"
#include "emp_xx_file.h"
#include "emp_xx_function.h"
#include "emp_xx_line.h"
#include "emp_xx_signature.h"

#include "emp_pp_comma.h"
#include "emp_pp_string.h"

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
namespace emp { namespace ast {

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
EMP_CLASS(statement_t)
public:
    statement_t(char const* const a_szFile,
                unsigned int const a_uiLine,
                char const* const a_szLine,
                char const* const a_szFunction,
                char const* const a_szSignature);

public:
    char const* file(void) const;
    unsigned int ui_line(void) const;
    char const* sz_line(void) const;
    char const* function(void) const;
    char const* signature(void) const;

private:
    char const* m_szFile;
    unsigned int m_uiLine;
    char const* m_szLine;
    char const* m_szFunction;
    char const* m_szSignature;
};

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
} }

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#define EMP_STATEMENT_INFO()\
    emp::ast::statement_t(\
        EMP_XX_FILE,\
        EMP_XX_LINE,\
        EMP_PP_STRING(EMP_XX_LINE),\
        EMP_XX_FUNCTION,\
        EMP_XX_SIGNATURE\
    )

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

