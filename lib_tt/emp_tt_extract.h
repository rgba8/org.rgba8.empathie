//-----------------------------------------------------------------------------
//
// File Name : emp_tt_extract.h
//
// Creation Date : Tue 18 Jan 2011 02:13:18 PM CET
//
// Modification Date : mar. 26 nov. 2013 18:10:06 CET
//
// Created By : luh - www.rgba8.org
//
// Description :
//
//-----------------------------------------------------------------------------
#ifndef EMP_TT_EXTRACT_H
#define EMP_TT_EXTRACT_H

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#include "emp_tt_false.h"
#include "emp_tt_null.h"
#include "emp_tt_true.h"

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
namespace emp { namespace tt {

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
template <typename T, bool t_bExtract>
class extract_impl
{
public:
    typedef typename T::type type;
private:
    EMP_XX_NOINSTANCE(extract_impl);
};

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
template <typename T>
class extract_impl<T, false>
{
public:
    typedef emp::tt::null type;
private:
    EMP_XX_NOINSTANCE(extract_impl);
};

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
template <typename T>
class extract
{
private:
    template <typename t_Extract>
    static true_type apply(typename t_Extract::type*);

    template <typename t_Extract>
    static false_type apply(...);

public:
    typedef typename extract_impl<T,
        sizeof(apply<T>(0)) == sizeof(true_type)>::type type;

private:
    EMP_XX_NOINSTANCE(extract);
};

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
} }

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#endif

