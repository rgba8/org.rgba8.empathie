##-----------------------------------------------------------------------------
## @rgba8.org
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
#TARGET_OS	?= lin

##-----------------------------------------------------------------------------
##-----------------------------------------------------------------------------
ROOT        ?= ../

##-----------------------------------------------------------------------------
##-----------------------------------------------------------------------------
DIR		    ?= pro_$(BIN)
BUILD	    ?= debug
FATAL	    ?= FALSE
MUD		    ?= false
ASAN        ?= false
VALGRIND    ?= false
CHECK       ?=

##-----------------------------------------------------------------------------
##-----------------------------------------------------------------------------
ifeq ($(TARGET_OS), osx)
SDK_ROOT	?= /Applications/XCode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.11.sdk/
X11_ROOT	?= $(SDK_ROOT)System/Library/Frameworks/Tk.framework/Versions/8.5/Headers/X11/
#PCI_ROOT        ?= $(SDK_ROOT)usr/include/pci

LIBXML2_H_DIR	?= $(SDK_ROOT)usr/include/libxml2/
LIBXML2_L_DIR   ?=
LIBXML2_LIB     ?= -lxml2

LIBPNG_H_DIR    ?= /opt/local/include/
LIBPNG_L_DIR    ?= /opt/local/lib/
LIBPNG_LIB      ?= -lpng16

OPENGL_ROOT	    ?= $(SDK_ROOT)System/Library/Frameworks/OpenGL.framework/Versions/A/
OPENGL_H_DIR    ?= $(OPENGL_ROOT)Headers/
OPENGL_L_DIR    ?=
OPENGL_LIB      ?= -framework OpenGL

FREETYPE2_ROOT  ?= $(SDK_ROOT)usr/include/freetype2/

OPENAL_ROOT     ?=  $(SDK_ROOT)System/Library/Frameworks/OpenAL.framework/Versions/A/
OPENAL_H_DIR    ?=  $(OPENAL_ROOT)Headers/
OPENAL_L_DIR    ?=
OPENAL_LIB      ?=  -framework OpenAL

COCOA_LIB       ?= -framework cocoa -framework QuartzCore

else
##-----------------------------------------------------------------------------
##-----------------------------------------------------------------------------
ifeq ($(TARGET_OS), lin)
SDK_ROOT	?= /usr/include/
X11_ROOT	?= $(SDK_ROOT)X11/

LIBXML2_H_DIR	?= $(SDK_ROOT)libxml2/
LIBXML2_L_DIR   ?=
LIBXML2_LIB ?= -lxml2

LIBPNG_H_DIR    ?= /usr/local/include/
LIBPNG_L_DIR    ?= /usr/local/lib/
LIBPNG_LIB      ?= -lpng16

OPENGL_H_DIR	?= $(SDK_ROOT)GL/
OPENGL_L_DIR    ?=
OPENGL_LIB      ?= -lGL

FREETYPE2_ROOT  ?= #$(SDK_ROOT)freetype2/

OPENAL_H_DIR    ?= $(SDK_ROOT)AL/
OPENAL_L_DIR    ?=
OPENAL_LIB      ?= -lopenal

else
##-----------------------------------------------------------------------------
##-----------------------------------------------------------------------------
ifeq ($(TARGET_OS), win)
SDK_ROOT    ?= /usr/include/

LIBXML2_H_DIR	?= $(SDK_ROOT)libxml2/
LIBXML2_H_DIR ?= /c/Users/rgba8/Documents/git/libxml2-2.7.8.win32/include/
#LIBXML2_H_DIR ?= /c/Users/rgba8/Documents/git/libxml2/include/

#LIBXML2_L_DIR ?= /c/usr/bin/msys-xml2-2.dll
LIBXML2_L_DIR ?= /usr/lib/
LIBXML2_LIB   ?= -lxml2

OPENGL_H_DIR	?= /c/
#Program Files (x86)/Windows Kits/8.1/Include/um/
OPENGL_L_DIR    ?= #C:/MinGW/msys/1.0/lib/
OPENGL_LIB      ?= -lopengl32

FREETYPE2_ROOT ?= $(SDK_ROOT)

#OPENAL_H_DIR	?= /c/Users/rgba8/Documents/git/openal-soft/include/
OPENAL_H_DIR ?= /c/Users/rgba8/Documents/git/openal-soft-1.17.2-bin/include/AL/
OPENAL_L_DIR    ?= #C:/MinGW/lib/
OPENAL_LIB	    ?= #-lOpenAL32.dll

endif
endif
endif

##-----------------------------------------------------------------------------
##-----------------------------------------------------------------------------
ARGS		?= 	ARCH="$(ARCH)" BUILD="$(BUILD)" FATAL="$(FATAL)" MUD="$(MUD)"\
                ROOT="$(ROOT)" COMPILER="$(COMPILER)" TARGET_OS="$(TARGET_OS)"\
                VALGRIND="$(VALGRIND)" ASAN="$(ASAN)"

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

TARGET_JOB ?= 

ifeq ($(TARGET_OS), win)
TARGET_JOB ?= 
else
TARGET_JOB ?= -j 4
endif

##-----------------------------------------------------------------------------
##-----------------------------------------------------------------------------
all:
	cd $(DIR); time make $(TARGET_JOB) -f $(MAKETARGET) all TARGET="all"\
		BINARY="$(BIN)"\
		IMACROS="$(IMACROS)"\
		INCLUDES="$(INCLUDES)"\
        	LIBRARIES="$(LIBRARIES)"\
		SOURCES="$(SOURCES)"\
		$(ARGS)

##-----------------------------------------------------------------------------
##-----------------------------------------------------------------------------
check:
	cd $(DIR); time make $(TARGET_JOB) -f $(MAKETARGET) check TARGET="check"\
		$(ARGS) CHECK="$(CHECK)"

##-----------------------------------------------------------------------------
##-----------------------------------------------------------------------------
compile:
	cd $(DIR); time make $(TARGET_JOB) -f $(MAKETARGET) compile TARGET="compile"\
		IMACROS="$(IMACROS)"\
        	INCLUDES="$(INCLUDES)"\
		$(ARGS)

##-----------------------------------------------------------------------------
##-----------------------------------------------------------------------------
clean:
	cd $(DIR); time make $(TARGET_JOB) -f $(MAKETARGET) clean TARGET="clean"\
		BINARY="$(BIN)"\
		$(ARGS)

##-----------------------------------------------------------------------------
##-----------------------------------------------------------------------------
.PHONY: all check compile clean
:
