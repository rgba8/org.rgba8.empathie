//-----------------------------------------------------------------------------
//
// File Name : emp_xx_nocopy_class_base.h
//
// Creation Date : Thu 10 Mar 2011 02:57:48 PM CET
//
// Modification Date : mar. 26 nov. 2013 18:14:15 CET
//
// Created By : luh - www.rgba8.org
//
// Description :
//
//-----------------------------------------------------------------------------
#ifndef EMP_XX_NOCOPY_CLASS_BASE_H
#define EMP_XX_NOCOPY_CLASS_BASE_H

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#include "emp_xx_nocopy.h"

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#define EMP_NOCOPY_CLASS_BASE(x_Name, x_Modifier, x_Base)\
class x_Name : x_Modifier x_Base\
{\
    friend class emp::rfx::class_t<x_Name>;\
public:\
    typedef x_Base tbase;\
private:\
    EMP_XX_NOCOPY(x_Name);

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#define EMP_NOCOPY_CLASS_BASE_2(x_Name, x_Modifier, x_Base, x_Mod2, x_Base2)\
class x_Name : x_Modifier x_Base, x_Mod2 x_Base2\
{\
    friend class emp::rfx::class_t<x_Name>;\
public:\
    typedef x_Base tbase;\
    typedef x_Base2 tbase2;\
private:\
    EMP_XX_NOCOPY(x_Name);

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#endif

