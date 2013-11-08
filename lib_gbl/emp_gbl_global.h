//-----------------------------------------------------------------------------
//
// File Name : emp_gbl_global.h
//
// Creation Date : Sat 16 Oct 2010 03:40:36 PM CEST
//
// Modification Date : sam. 09 nov. 2013 00:04:29 CET
//
// Created By : rgba8 (ksej) - www.empathy.fr
//
// Description :
//
//-----------------------------------------------------------------------------
#ifndef EMP_GBL_GLOBAL_H
#define EMP_GBL_GLOBAL_H

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#include "emp_xx_nocopy_class.h"
#include "emp_xx_return.h"

#include "emp_pp_comma.h"

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#define EMP_GLOBALS() emp::gbl::globals_t::instance()

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#ifdef EMP_XX_LOG_ENABLE
#define EMP_LOGGER() EMP_GLOBALS().logger()
#endif

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#if defined(EMP_XX_ASSERT_ENABLE)
#define EMP_ASSERTER() EMP_GLOBALS().asserter()
#endif

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#if defined(EMP_XX_LOCALIZE_ENABLE)
#define EMP_LOCALIZER() EMP_GLOBALS().localizer()
#endif

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#define EMP_ALLOCATOR() EMP_GLOBALS().allocator()
#define EMP_ALIGNATOR() EMP_GLOBALS().alignator()

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#define EMP_STRING() EMP_GLOBALS().string()

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#define EMP_ENGINE() EMP_GLOBALS().engine()

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
namespace emp
{
    namespace ast { class asserter; }
    namespace str { class manager_t; }
    namespace loc { class localizer_c; }
    namespace log { class logger_t; }
    namespace rfx { class factory_c; }
    namespace eng { class engine_c; }
}

EMP_XX_FORWARD_MEM_ALLOCATOR()

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
namespace emp { namespace gbl {

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
EMP_NOCOPY_CLASS(globals_t)

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
    emp::eng::engine_c* m_pEngine;
public:
    EMP_RETURN emp::eng::engine_c& engine(void)
    { return *m_pEngine; }
    void set_engine(emp::eng::engine_c* const a_pValue)
    { m_pEngine = a_pValue; }

public:
    globals_t(void):
    EMP_XX_IF_ASSERT(   m_pAsserter()   EMP_PP_COMMA())
                        m_pAllocator()  ,
                        m_pAlignator()  ,
                        m_pString()     ,
                        m_pFactory()    ,
    EMP_XX_IF_LOCALIZE( m_pLocalizer()  EMP_PP_COMMA())
    EMP_XX_IF_LOG(      m_pLogger())    ,
                        m_pEngine()
    { }

private:
    static globals_t* m_pInstance;
public:
    static EMP_RETURN globals_t& instance(void)
    { return *m_pInstance; }
    static void set_instance(globals_t* a_pValue)
    { m_pInstance = a_pValue; }
};

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
} }

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#endif

