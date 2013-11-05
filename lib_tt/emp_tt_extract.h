//-----------------------------------------------------------------------------
//
// File Name : emp_tt_extract.h
//
// Creation Date : Tue 18 Jan 2011 02:13:18 PM CET
//
// Modification Date : mar. 05 nov. 2013 20:07:22 CET
//
// Created By : rgba8 (ksej) - www.empathy.fr
//
// Description :
//
//-----------------------------------------------------------------------------
#ifndef EMP_TT_EXTRACT_H
#define EMP_TT_EXTRACT_H

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#ifndef EMP_TT_NULL_H
#include "emp_tt_null.h"
#endif

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
    //TODO:true_type;
    typedef char true_type;
    //TODO:false_type;
    typedef int false_type;

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
} } // tt // emp

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#endif

