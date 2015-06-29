//-----------------------------------------------------------------------------
//
// File Name : emp_ast_assert.h
//
// Creation Date : Mon 4 Jan 2009 10:41:27 PM CEST
//
// Modification Date : lun. 29 juin 2015 23:13:46 CEST
//
// Created By : ksej - www.rgba8.org
//
// Description :
//
//-----------------------------------------------------------------------------
#ifndef EMP_AST_ASSERT_H
#define EMP_AST_ASSERT_H

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#include "emp_pp_comma.h"
#include "emp_pp_string.h"

#include "emp_tt_ignore_return.h"

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#define EMP_STATEMENT_INFO()\
    emp::ast::statement_c(\
        EMP_XX_FILE,\
        EMP_XX_LINE,\
        EMP_PP_STRING(EMP_XX_LINE),\
        EMP_XX_FUNCTION,\
        EMP_XX_SIGNATURE)

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#ifdef EMP_XX_TRACK_LEAKS_ENABLE
#define EMP_XX_DBG_STATEMENT_COMMA EMP_PP_COMMA()
#define EMP_XX_DBG_STATEMENT_ARGUMENT a_rStatement
#define EMP_XX_DBG_STATEMENT_PARAMETER\
    emp::ast::statement_c const& a_rStatement
#define EMP_XX_DBG_STATEMENT_UNUSED EMP_UNUSED
#define EMP_XX_DBG_STATEMENT_INFO EMP_STATEMENT_INFO()
namespace emp { namespace ast { class statement_c; } }
#else
#define EMP_XX_DBG_STATEMENT_COMMA
#define EMP_XX_DBG_STATEMENT_ARGUMENT
#define EMP_XX_DBG_STATEMENT_PARAMETER
#define EMP_XX_DBG_STATEMENT_UNUSED
#define EMP_XX_DBG_STATEMENT_INFO
#endif

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#ifdef EMP_XX_ASSERT_ENABLE

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#define EMP_ASSERT_INFO(x_Condition)\
    emp::ast::assert_c(x_Condition, EMP_PP_STRING(x_Condition), EMP_STATEMENT_INFO())

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#define EMP_ASSERT(x_Condition)\
do { emp::ast::condition(EMP_ASSERT_INFO(x_Condition)); } while(0)

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#define EMP_ASSERT_UNREACHABLE() EMP_ASSERT(false);
#define EMP_ASSERT_NOT_IMPLEMENTED() EMP_ASSERT(false);
#define EMP_ASSERT_BOOL_CALL(x_Call) EMP_ASSERT(x_Call)

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#else

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#define EMP_ASSERT(x_Condition) EMP_XX_NOOP()
#define EMP_ASSERT_UNREACHABLE() EMP_XX_NOOP()
#define EMP_ASSERT_NOT_IMPLEMENTED() EMP_STATIC_ASSERT(false)
#define EMP_ASSERT_BOOL_CALL(x_Call) emp::tt::ignore_return(x_Call)

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#endif

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
namespace emp { namespace ast {

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
EMP_CLASS(statement_c)
private:
    char const* m_szFile;
    unsigned int m_uiLine;
    char const* m_szLine;
    char const* m_szFunction;
    char const* m_szSignature;

public:
    statement_c(
        char const* const a_szFile,
        unsigned int const a_uiLine,
        char const* const a_szLine,
        char const* const a_szFunction,
        char const* const a_szSignature):
        m_szFile(a_szFile),
        m_uiLine(a_uiLine),
        m_szLine(a_szLine),
        m_szFunction(a_szFunction),
        m_szSignature(a_szSignature)
    {}

public:
    EMP_RETURN char const* file(void) const
    { return m_szFile; }

    EMP_RETURN unsigned int ui_line(void) const
    { return m_uiLine; }

    EMP_RETURN char const* sz_line(void) const
    { return m_szLine; }

    EMP_RETURN char const* function(void) const
    { return m_szFunction; }

    EMP_RETURN char const* signature(void) const
    { return m_szSignature; }
};

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
EMP_CLASS(assert_c)
private:
    bool m_bCondition;
    char const* m_szCondition;
    statement_c  m_Statement;

public:
    assert_c(
        bool const a_bCondition,
        char const* const a_szCondition,
        statement_c const& a_rStatement):
        m_bCondition(a_bCondition),
        m_szCondition(a_szCondition),
        m_Statement(a_rStatement)
    { }

public:
    EMP_RETURN bool b_condition(void) const
    { return m_bCondition; }

    EMP_RETURN char const* sz_condition(void) const
    { return m_szCondition; }

    EMP_RETURN statement_c const& statement(void) const
    { return m_Statement; }
};

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
EMP_NOCOPY_CLASS(asserter_c)
public:
    asserter_c(void)
    {}

    void condition(assert_c const& a_rAssert);
};

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void condition(assert_c const& a_rAssert);

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void output_char(char const a_cValue);
void output_pchar(char const* const a_pValue);
void output_line(char const* const a_szName, char const* const a_szValue, bool const a_bVerbose);
void output_header(char const* const a_szName, char const a_cAlias, bool const a_bVerbose);
void output_statement(statement_c const& a_rStatement, bool const a_bVerbose);
void output_assert(assert_c const& a_rAssert, bool const a_bVerbose);

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
} }

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#endif

