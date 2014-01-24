//-----------------------------------------------------------------------------
//
// File Name : emp_xx_class_base.h
//
// Creation Date : Thu 10 Mar 2011 02:58:47 PM CET
//
// Modification Date : mar. 26 nov. 2013 18:13:51 CET
//
// Created By : ksej - www.rgba8.org
//
// Description :
//
//-----------------------------------------------------------------------------
#ifndef EMP_XX_CLASS_BASE_H
#define EMP_XX_CLASS_BASE_H

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#define EMP_CLASS_BASE(x_Name, x_Modifier, x_Base)\
class x_Name : x_Modifier x_Base\
{\
    friend class emp::rfx::class_t<x_Name>;\
public:\
    typedef x_Base tbase;\
private:

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#endif

