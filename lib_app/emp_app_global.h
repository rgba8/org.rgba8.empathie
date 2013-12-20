//-----------------------------------------------------------------------------
//
// File Name : emp_app_global.h
//
// Creation Date : Sat 16 Oct 2010 03:40:36 PM CEST
//
// Modification Date : Wed Dec 11 22:02:50 2013
//
// Created By : luh - www.rgba8.org
//
// Description :
//
//-----------------------------------------------------------------------------
#ifndef EMP_APP_GLOBAL_H
#define EMP_APP_GLOBAL_H

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#include "emp_xx_nocopy_class.h"
#include "emp_xx_return.h"

#include "emp_pp_comma.h"

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#define EMP_GLOBAL() emp::app::global_c::instance()

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#ifdef EMP_XX_LOG_ENABLE
#define EMP_LOGGER() EMP_GLOBAL().logger()
#endif

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#if defined(EMP_XX_ASSERT_ENABLE)
#define EMP_ASSERTER() EMP_GLOBAL().asserter()
#endif

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#if defined(EMP_XX_LOCALIZE_ENABLE)
#define EMP_LOCALIZER() EMP_GLOBAL().localizer()
#endif

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#define EMP_ALLOCATOR() EMP_GLOBAL().allocator()
#define EMP_ALIGNATOR() EMP_GLOBAL().alignator()

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#define EMP_STRING() EMP_GLOBAL().string()

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#define EMP_GAME() EMP_GLOBAL().game()

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
namespace emp
{
    namespace ast { class asserter; }
    namespace str { class manager_t; }
    namespace loc { class localizer_c; }
    namespace log { class logger_t; }
    namespace rfx { class factory_c; }
    namespace app { class game_c; }
}

EMP_XX_FORWARD_MEM_ALLOCATOR()

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
namespace emp { namespace app {

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
EMP_NOCOPY_CLASS(global_c)

#ifdef EMP_XX_ASSERT_ENABLE
private:
    emp::ast::asserter* m_pAsserter;
public:
    EMP_RETURN emp::ast::asserter& asserter(void)
    { return *m_pAsserter; }
    void set_asserter(emp::ast::asserter* const a_pValue)
    { m_pAsserter = a_pValue; }
#endif

private:
    emp::mem::allocator* m_pAllocator;
public:
    EMP_RETURN emp::mem::allocator& allocator(void)
    { return *m_pAllocator; }
    void set_allocator(emp::mem::allocator* const a_pValue)
    { m_pAllocator = a_pValue; }

private:
    emp::mem::alignator* m_pAlignator;
public:
    EMP_RETURN emp::mem::alignator& alignator(void)
    { return *m_pAlignator; }
    void set_alignator(emp::mem::alignator* const a_pValue)
    { m_pAlignator = a_pValue; }

private:
    emp::str::manager_t* m_pString;
public:
    EMP_RETURN emp::str::manager_t& string(void)
    { return *m_pString; }
    void set_string(emp::str::manager_t* const a_pValue)
    { m_pString = a_pValue; }

private:
    emp::rfx::factory_c* m_pFactory;
public:
    EMP_RETURN emp::rfx::factory_c& factory(void)
    { return *m_pFactory; }
    void set_factory(emp::rfx::factory_c* const a_pValue)
    { m_pFactory = a_pValue; }

#ifdef EMP_XX_LOCALIZE_ENABLE
private:
    emp::loc::localizer_c* m_pLocalizer;
public:
    EMP_RETURN emp::loc::localizer_c& localizer(void)
    { return *m_pLocalizer; }
    void set_localizer(emp::loc::localizer_c* const a_pValue)
    { m_pLocalizer = a_pValue; }
#endif

#ifdef EMP_XX_LOG_ENABLE
private:
    emp::log::logger_t* m_pLogger;
public:
    EMP_RETURN emp::log::logger_t& logger(void)
    { return *m_pLogger; }
    void set_logger(emp::log::logger_t* const a_pValue)
    { m_pLogger = a_pValue; }
#endif

private:
    emp::app::game_c* m_pGame;
public:
    EMP_RETURN emp::app::game_c& game(void)
    { return *m_pGame; }
    void set_game(emp::app::game_c* const a_pValue)
    { m_pGame = a_pValue; }

public:
    global_c(void):
    EMP_XX_IF_ASSERT(   m_pAsserter()   EMP_PP_COMMA())
                        m_pAllocator()  ,
                        m_pAlignator()  ,
                        m_pString()     ,
                        m_pFactory()    ,
    EMP_XX_IF_LOCALIZE( m_pLocalizer()  EMP_PP_COMMA())
    EMP_XX_IF_LOG(      m_pLogger())    ,
                        m_pGame()
    { }

private:
    static global_c* m_pInstance;
public:
    static EMP_RETURN global_c& instance(void)
    { return *m_pInstance; }
    static void set_instance(global_c* a_pValue)
    { m_pInstance = a_pValue; }
};

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
} }

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#endif

