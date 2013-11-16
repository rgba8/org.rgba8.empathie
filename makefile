##-----------------------------------------------------------------------------
##
## File Name : makefile
##
## Creation Date : Mon 31 Jan 2011 08:01:47 PM CET
##
## Modification Date : mar. 08 oct. 2013 22:11:00 CEST
##
## Created By : rgba8 (ksej) - www.empathy.fr
##
## Description :
##
##-----------------------------------------------------------------------------
ROOT        	?= ../
BIN         	?= test
COMPILER 	?= llvm 
BUILD		?= debug
ARCH		?= x86_32
FATAL		?= FALSE
MUD		?= false
TARGET_OS	?= osx
SDK_ROOT	?= /Applications/XCode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.9.sdk/

ifeq ($(TARGET_OS), osx)
LIBXML2_ROOT	?= $(SDK_ROOT)usr/include/libxml2
else
LIBXML2_ROOT	?= $(SDK_ROOT)usr/include/
endif

ifeq ($(TARGET_OS), osx)
OPENGL_ROOT	?= $(SDK_ROOT)/System/Library/Frameworks/OpenGL.framework/Versions/A/Headers/
else
OPENGL_ROOT	?= $(SDK_ROOT)/usr/include/GL/
endif

ifeq ($(TARGET_OS), osx)
X11_ROOT	?= $(SDK_ROOT)/System/Library/Frameworks/Tk.framework/Versions/8.5/Headers/
else
X11_ROOT	?= $(SDK_ROOT)/user/include/X11/
endif

##-----------------------------------------------------------------------------
##-----------------------------------------------------------------------------
ARGS		?= 	ARCH="$(ARCH)" BUILD="$(BUILD)" FATAL="$(FATAL)"\
			 MUD="$(MUD)" ROOT="$(ROOT)" COMPILER="$(COMPILER)"

##-----------------------------------------------------------------------------
##-----------------------------------------------------------------------------
MAKETARGET	?=  $(ROOT)uti_make/maketarget
IMACROS		?=	imacro.h

##-----------------------------------------------------------------------------
##-----------------------------------------------------------------------------
ifeq "$(wildcard $(DIR))" ""
$(error invalid project directory : $(DIR))
else
endif

##-----------------------------------------------------------------------------
##-----------------------------------------------------------------------------
include $(DIR)/makefile

##-----------------------------------------------------------------------------
##-----------------------------------------------------------------------------
all:
	cd $(DIR); time make -j2 -f $(MAKETARGET) all TARGET="all"\
		BINARY="$(BIN)"\
		IMACROS="$(IMACROS)"\
		INCLUDES="$(INCLUDES)"\
        LIBRARIES="$(LIBRARIES)"\
		SOURCES="$(SOURCES)"\
		$(ARGS)

##-----------------------------------------------------------------------------
##-----------------------------------------------------------------------------
check:
	cd $(DIR); time make -j2 -f $(MAKETARGET) check TARGET="check"\
		$(ARGS)

##-----------------------------------------------------------------------------
##-----------------------------------------------------------------------------
compile:
	cd $(DIR); time make -j2 -f $(MAKETARGET) compile TARGET="compile"\
		IMACROS="$(IMACROS)"\
        INCLUDES="$(INCLUDES)"\
		$(ARGS)

##-----------------------------------------------------------------------------
##-----------------------------------------------------------------------------
clean:
	cd $(DIR); time make -j2 -f $(MAKETARGET) clean TARGET="clean"\
		BINARY="$(BIN)"\
		$(ARGS)

##-----------------------------------------------------------------------------
##-----------------------------------------------------------------------------
.PHONY: all check compile clean
:
