//-----------------------------------------------------------------------------
//
// File Name : emp_hh_stdio.h
//
// Creation Date : Mon 10 Jan 2011 12:24:32 PM CET
//
// Modification Date : Tue Jan 14 19:24:44 2014
//
// Created By : ksej - www.rgba8.org
//
// Description :
//
//-----------------------------------------------------------------------------
#ifndef EMP_HH_STDIO_H
#define EMP_HH_STDIO_H

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#ifdef __STRICT_ANSI__
// TODO : ugly
#undef __STRICT_ANSI__
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#define __STRICT_ANSI__
#else
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#endif

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#endif

