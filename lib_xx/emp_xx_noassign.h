//-----------------------------------------------------------------------------
//
// File Name : emp_xx_noassign.h
//
// Creation Date : Wed 08 Dec 2010 05:57:10 PM CET
//
// Modification Date : dim. 03 nov. 2013 13:01:07 CET
//
// Created By : rgba8 (ksej) - www.empathy.fr
//
// Description :
//
//-----------------------------------------------------------------------------
#ifndef EMP_XX_NOASSIGN_H
#define EMP_XX_NOASSIGN_H

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#define EMP_XX_NOASSIGN(...)\
public:\
    void emp_nopublic(void) {};\
private:\
    __VA_ARGS__(__VA_ARGS__ const& a_rFrom);\
    __VA_ARGS__ const& operator=(__VA_ARGS__ const& a_rFrom)

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#endif

