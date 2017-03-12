##-----------------------------------------------------------------------------
## @rgba8.org
##-----------------------------------------------------------------------------
ifeq (, $(wildcard $(ROOT)makeuser))
$(error no $(ROOT)makeuser found)
else
include $(ROOT)makeuser
endif

BIN        	?= test
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
INCLUDES    ?=
LIBRARIES   ?=# -static -static-libgcc -static-libstdc++

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
SDK_ROOT    ?= /C/Users/rgba8/Documents/git/

#LIBXML2_ROOT  ?= $(SDK_ROOT)libxml2-2.7.8.win32/
LIBXML2_ROOT ?= /usr/
LIBXML2_H_DIR ?= $(LIBXML2_ROOT)include/
LIBXML2_L_DIR ?= $(LIBXML2_ROOT)lib/
LIBXML2_LIB   ?= -lxml2

LIBPNG_ROOT     ?= $(SDK_ROOT)libpng/
LIBPNG_H_DIR    ?= $(LIBPNG_ROOT)
LIBPNG_L_DIR    ?= $(LIBPNG_ROOT)projects/vsstudio/Release/
LIBPNG_LIB      ?= -lpng16.dll

OPENGL_H_DIR	?= /c/
#Program Files (x86)/Windows Kits/8.1/Include/um/
OPENGL_L_DIR    ?= #C:/MinGW/msys/1.0/lib/
OPENGL_LIB      ?= -lopengl32

FREETYPE2_ROOT ?=

#OPENAL_ROOT     ?= /C/Users/rgba8/Documents/git/openal-soft-1.17.2-bin/
OPENAL_ROOT ?= /mingw64/
OPENAL_H_DIR	?= $(OPENAL_ROOT)include/
OPENAL_L_DIR    ?= $(OPENAL_ROOT)bin/
OPENAL_LIB	    ?= -lopenal #-Wl, -Bstatic

ifeq ($(COMPILER), llvm)
INCLUDES    += -I/mingw64/include/c++/5.4.0/
INCLUDES    += -I/mingw64/include/c++/5.4.0/x86_64-w64-mingw32/
LIBRARIES   += -lpthread
endif

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
