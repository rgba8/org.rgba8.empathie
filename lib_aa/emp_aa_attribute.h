//-----------------------------------------------------------------------------
//
// File Name : emp_aa_attribute.h
//
// Creation Date : Fri 24 Sep 2010 01:00:23 PM CEST
//
// Modification Date : ven. 01 nov. 2013 11:56:09 CET
//
// Created By : rgba8 (ksej) - www.empathy.fr
//
// Description :
//
//-----------------------------------------------------------------------------
#ifndef EMP_AA_ATTRIBUTE_H
#define EMP_AA_ATTRIBUTE_H

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#if defined(__GNUC__)
#define EMP_AA_UNUSED __attribute__ ((unused))
#else
#define EMP_AA_UNUSED
#endif

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#if defined(__GNUC__)
#define EMP_AA_WARN_UNUSED __attribute__ ((warn_unused_result))
#else
#define EMP_AA_WARN_UNUSED
#endif

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#if defined(__GNUC__)
#define EMP_AA_ALWAYS_INLINE __attribute__ ((always_inline))
#else
#define EMP_AA_ALWAYS_INLINE
#endif

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#if defined(__GNUC__)
#define EMP_AA_NOINLINE __attribute__ ((noinline))
#else
#define EMP_AA_NOINLINE
#endif

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#endif

