##-----------------------------------------------------------------------------
##
## File Name : makefile
##
## Creation Date : Mon 31 Jan 2011 08:01:47 PM CET
##
## Modification Date : Sun Dec 15 21:51:06 2013
##
## Created By : luh - www.rgba8.org
##
## Description :
##
##-----------------------------------------------------------------------------
ifeq (, $(wildcard $(ROOT)makeuser))
$(error no $(ROOT)makeuser found)
else
include $(ROOT)makeuser
endif

BIN         	?= test
#COMPILER 	?= llvm 
COMPILER 	?= gcc
#ARCH		?= x86_32
ARCH		?= x86_64
#TARGET_OS	?= osx
TARGET_OS	?= lin

##-----------------------------------------------------------------------------
##-----------------------------------------------------------------------------
ROOT        ?= ../

##-----------------------------------------------------------------------------
##-----------------------------------------------------------------------------
DIR		    ?= pro_$(BIN)
BUILD	    ?= debug
FATAL	    ?= FALSE
MUD		    ?= false
VALGRIND    ?= false
CHECK       ?=

ifeq ($(TARGET_OS), osx)
SDK_ROOT	?= /Applications/XCode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.9.sdk/
else
SDK_ROOT	?= /usr/include/
endif

ifeq ($(TARGET_OS), osx)
LIBXML2_ROOT	?= $(SDK_ROOT)usr/include/libxml2/
else
LIBXML2_ROOT	?= $(SDK_ROOT)libxml2/
endif

ifeq ($(TARGET_OS), osx)
OPENGL_ROOT	?= $(SDK_ROOT)System/Library/Frameworks/OpenGL.framework/Versions/A/
OPENGL_H    ?= $(OPENGL_ROOT)Headers/
OPENGL_LIB  ?= -framework OpenGL
else
ifeq ($(TARGET_OS), lin)
OPENGL_H	?= $(SDK_ROOT)GL/
OPENGL_LIB  ?= -lGL
endif
endif

ifeq ($(TARGET_OS), osx)
X11_ROOT	?= $(SDK_ROOT)System/Library/Frameworks/Tk.framework/Versions/8.5/Headers/X11/
else
X11_ROOT	?= $(SDK_ROOT)X11/
endif

ifeq ($(TARGET_OS), osx)
FREETYPE2_ROOT  ?= $(SDK_ROOT)usr/include/freetype2/
else
FREETYPE2_ROOT  ?= $(SDK_ROOT)freetype2/
endif

ifeq ($(TARGET_OS), osx)
OPENAL_ROOT     ?=  $(SDK_ROOT)System/Library/Frameworks/OpenAL.framework/Versions/A/
OPENAL_H        ?=  $(OPENAL_ROOT)Headers/
OPENAL_LIB      ?=  -framework OpenAL
else
ifeq ($(TARGET_OS), lin)
OPENAL_H        ?= $(SDK_ROOT)AL/
OPENAL_LIB      ?= -lopenal
endif
endif

ifeq ($(TARGET_OS), osx)
COCOA_LIB       ?= -framework cocoa -framework QuartzCore
endif

#ifeq ($(TARGET_OS), osx)
#PCI_ROOT        ?= $(SDK_ROOT)usr/include/pci
##-----------------------------------------------------------------------------
##-----------------------------------------------------------------------------
ARGS		?= 	ARCH="$(ARCH)" BUILD="$(BUILD)" FATAL="$(FATAL)" MUD="$(MUD)"\
                ROOT="$(ROOT)" COMPILER="$(COMPILER)" TARGET_OS="$(TARGET_OS)"\
                VALGRIND="$(VALGRIND)"

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
	cd $(DIR); time make -j4 -f $(MAKETARGET) all TARGET="all"\
		BINARY="$(BIN)"\
		IMACROS="$(IMACROS)"\
		INCLUDES="$(INCLUDES)"\
        	LIBRARIES="$(LIBRARIES)"\
		SOURCES="$(SOURCES)"\
		$(ARGS)

##-----------------------------------------------------------------------------
##-----------------------------------------------------------------------------
check:
	cd $(DIR); time make -j4 -f $(MAKETARGET) check TARGET="check"\
		$(ARGS) CHECK="$(CHECK)"

##-----------------------------------------------------------------------------
##-----------------------------------------------------------------------------
compile:
	cd $(DIR); time make -j4 -f $(MAKETARGET) compile TARGET="compile"\
		IMACROS="$(IMACROS)"\
        	INCLUDES="$(INCLUDES)"\
		$(ARGS)

##-----------------------------------------------------------------------------
##-----------------------------------------------------------------------------
clean:
	cd $(DIR); time make -j4 -f $(MAKETARGET) clean TARGET="clean"\
		BINARY="$(BIN)"\
		$(ARGS)

##-----------------------------------------------------------------------------
##-----------------------------------------------------------------------------
.PHONY: all check compile clean
:
