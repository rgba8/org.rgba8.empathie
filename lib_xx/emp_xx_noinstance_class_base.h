//-----------------------------------------------------------------------------
//
// File Name : emp_xx_noinstance_class_base.h
//
// Creation Date : Thu 10 Mar 2011 02:55:45 PM CET
//
// Modification Date : mar. 26 nov. 2013 18:14:21 CET
//
// Created By : ksej - www.rgba8.org
//
// Description :
//
//-----------------------------------------------------------------------------
#ifndef EMP_XX_NOINSTANCE_CLASS_BASE_H
#define EMP_XX_NOINSTANCE_CLASS_BASE_H

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#include "emp_xx_noinstance.h"

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#define EMP_NOINSTANCE_CLASS_BASE(x_Name, x_Modifier, x_Base)\
class x_Name : x_Modifier x_Base\
{\
public:\
    typedef x_Base tbase;\
private:\
    EMP_XX_NOINSTANCE(x_Name);


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#endif

