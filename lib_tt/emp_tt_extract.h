//-----------------------------------------------------------------------------
//
// File Name : emp_tt_extract.h
//
// Creation Date : Tue 18 Jan 2011 02:13:18 PM CET
//
// Modification Date : ven. 08 nov. 2013 23:19:22 CET
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
#include "emp_tt_null.h"

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
    static true_ apply(typename t_Extract::type*);

    template <typename t_Extract>
    static false_ apply(...);

public:
    typedef typename extract_impl<T,
        sizeof(apply<T>(0)) == sizeof(true_)>::type type;

private:
    EMP_XX_NOINSTANCE(extract);
};

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
} }

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#endif

