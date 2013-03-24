# Wind River Workbench generated Makefile.
# Do not edit!!!
#
# The file ".wrmakefile" is the template used by the Wind River Workbench to
# generate the makefiles of this project. Add user-specific build targets and
# make rules only(!) in this project's ".wrmakefile" file. These will then be
# automatically dumped into the makefiles.

WIND_HOME := $(subst \,/,$(WIND_HOME))
WIND_BASE := $(subst \,/,$(WIND_BASE))
WIND_USR := $(subst \,/,$(WIND_USR))

all : pre_build main_all post_build

_clean ::
	@echo "make: removing targets and objects of `pwd`"

TRACE=0
TRACEON=$(TRACE:0=@)
TRACE_FLAG=$(TRACEON:1=)

MAKEFILE := Makefile

FLEXIBLE_BUILD := 1

BUILD_SPEC = PPC603gnu
DEBUG_MODE = 1
ifeq ($(DEBUG_MODE),1)
MODE_DIR := Debug
else
MODE_DIR := NonDebug
endif
OBJ_DIR := .
WS_ROOT_DIR := C:/
PRJ_ROOT_DIR := $(WS_ROOT_DIR)//FRC830-DriveTrain/DriveTrain



#Global Build Macros
PROJECT_TYPE = DKM
DEFINES = 
EXPAND_DBG = 0


#BuildSpec specific Build Macros
VX_CPU_FAMILY = ppc
CPU = PPC603
TOOL_FAMILY = gnu
TOOL = gnu
TOOL_PATH = 
CC_ARCH_SPEC = -mcpu=603 -mstrict-align -mno-implicit-fp -mlongcall
LIBPATH = 
LIBS = 

IDE_INCLUDES = -I$(WIND_BASE)/target/h/WPILib -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/wrn/coreip 

IDE_LIBRARIES = $(WIND_BASE)/target/lib/WPILib.a 

IDE_DEFINES = 



#BuildTool flags
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_C-Compiler = -g
DEBUGFLAGS_C++-Compiler = -g
DEBUGFLAGS_Linker = -g
DEBUGFLAGS_Partial-Image-Linker = 
DEBUGFLAGS_Librarian = 
DEBUGFLAGS_Assembler = -g
else
DEBUGFLAGS_C-Compiler = -O2 -fstrength-reduce -fno-builtin
DEBUGFLAGS_C++-Compiler = -O2 -fstrength-reduce -fno-builtin
DEBUGFLAGS_Linker = -O2 -fstrength-reduce -fno-builtin
DEBUGFLAGS_Partial-Image-Linker = 
DEBUGFLAGS_Librarian = 
DEBUGFLAGS_Assembler = -O2 -fstrength-reduce -fno-builtin
endif


#Project Targets
PROJECT_TARGETS = DriveTrain/$(MODE_DIR)/DriveTrain.out \
	 DriveTrain_partialImage/$(MODE_DIR)/DriveTrain_partialImage.o


#Rules

# DriveTrain
ifeq ($(DEBUG_MODE),1)
DriveTrain/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -g
DriveTrain/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -g
DriveTrain/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -g
DriveTrain/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
DriveTrain/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
DriveTrain/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -g
else
DriveTrain/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -O2 -fstrength-reduce -fno-builtin
DriveTrain/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -O2 -fstrength-reduce -fno-builtin
DriveTrain/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -O2 -fstrength-reduce -fno-builtin
DriveTrain/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
DriveTrain/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
DriveTrain/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -O2 -fstrength-reduce -fno-builtin
endif
DriveTrain/$(MODE_DIR)/% : IDE_INCLUDES = -I$(WIND_BASE)/target/h/WPILib -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/wrn/coreip 
DriveTrain/$(MODE_DIR)/% : IDE_LIBRARIES = $(WIND_BASE)/target/lib/WPILib.a 
DriveTrain/$(MODE_DIR)/% : IDE_DEFINES = 
DriveTrain/$(MODE_DIR)/% : PROJECT_TYPE = DKM
DriveTrain/$(MODE_DIR)/% : DEFINES = 
DriveTrain/$(MODE_DIR)/% : EXPAND_DBG = 0
DriveTrain/$(MODE_DIR)/% : VX_CPU_FAMILY = ppc
DriveTrain/$(MODE_DIR)/% : CPU = PPC603
DriveTrain/$(MODE_DIR)/% : TOOL_FAMILY = gnu
DriveTrain/$(MODE_DIR)/% : TOOL = gnu
DriveTrain/$(MODE_DIR)/% : TOOL_PATH = 
DriveTrain/$(MODE_DIR)/% : CC_ARCH_SPEC = -mcpu=603 -mstrict-align -mno-implicit-fp -mlongcall
DriveTrain/$(MODE_DIR)/% : LIBPATH = 
DriveTrain/$(MODE_DIR)/% : LIBS = 
DriveTrain/$(MODE_DIR)/% : OBJ_DIR := DriveTrain/$(MODE_DIR)

OBJECTS_DriveTrain = DriveTrain_partialImage/$(MODE_DIR)/DriveTrain_partialImage.o

DriveTrain/$(MODE_DIR)/DriveTrain.out : $(OBJECTS_DriveTrain)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@";rm -f "$@";nmppc $(OBJECTS_DriveTrain) $(IDE_LIBRARIES) | tclsh $(WIND_BASE)/host/resource/hutils/tcl/munch.tcl -c ppc > $(OBJ_DIR)/ctdt.c; $(TOOL_PATH)ccppc $(DEBUGFLAGS_Linker) $(CC_ARCH_SPEC) -fdollars-in-identifiers -Wall $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES)  -o $(OBJ_DIR)/ctdt.o -c $(OBJ_DIR)/ctdt.c; $(TOOL_PATH)ccppc -r -nostdlib -Wl,-X -T $(WIND_BASE)/target/h/tool/gnu/ldscripts/link.OUT -o "$@" $(OBJ_DIR)/ctdt.o $(OBJECTS_DriveTrain) $(IDE_LIBRARIES) $(LIBPATH) $(LIBS)  $(ADDED_LIBPATH) $(ADDED_LIBS) && if [ "$(EXPAND_DBG)" = "1" ]; then plink "$@";fi

DriveTrain/$(MODE_DIR)/DriveTrain_compile_file : $(FILE) ;

_clean :: DriveTrain/$(MODE_DIR)/DriveTrain_clean

DriveTrain/$(MODE_DIR)/DriveTrain_clean : 
	$(TRACE_FLAG)if [ -d "DriveTrain" ]; then cd "DriveTrain"; rm -rf $(MODE_DIR); fi


# DriveTrain_partialImage
ifeq ($(DEBUG_MODE),1)
DriveTrain_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -g
DriveTrain_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -g
DriveTrain_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -g
DriveTrain_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
DriveTrain_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
DriveTrain_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -g
else
DriveTrain_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -O2 -fstrength-reduce -fno-builtin
DriveTrain_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -O2 -fstrength-reduce -fno-builtin
DriveTrain_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -O2 -fstrength-reduce -fno-builtin
DriveTrain_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
DriveTrain_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
DriveTrain_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -O2 -fstrength-reduce -fno-builtin
endif
DriveTrain_partialImage/$(MODE_DIR)/% : IDE_INCLUDES = -I$(WIND_BASE)/target/h/WPILib -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/wrn/coreip 
DriveTrain_partialImage/$(MODE_DIR)/% : IDE_LIBRARIES = $(WIND_BASE)/target/lib/WPILib.a 
DriveTrain_partialImage/$(MODE_DIR)/% : IDE_DEFINES = 
DriveTrain_partialImage/$(MODE_DIR)/% : PROJECT_TYPE = DKM
DriveTrain_partialImage/$(MODE_DIR)/% : DEFINES = 
DriveTrain_partialImage/$(MODE_DIR)/% : EXPAND_DBG = 0
DriveTrain_partialImage/$(MODE_DIR)/% : VX_CPU_FAMILY = ppc
DriveTrain_partialImage/$(MODE_DIR)/% : CPU = PPC603
DriveTrain_partialImage/$(MODE_DIR)/% : TOOL_FAMILY = gnu
DriveTrain_partialImage/$(MODE_DIR)/% : TOOL = gnu
DriveTrain_partialImage/$(MODE_DIR)/% : TOOL_PATH = 
DriveTrain_partialImage/$(MODE_DIR)/% : CC_ARCH_SPEC = -mcpu=603 -mstrict-align -mno-implicit-fp -mlongcall
DriveTrain_partialImage/$(MODE_DIR)/% : LIBPATH = 
DriveTrain_partialImage/$(MODE_DIR)/% : LIBS = 
DriveTrain_partialImage/$(MODE_DIR)/% : OBJ_DIR := DriveTrain_partialImage/$(MODE_DIR)

DriveTrain_partialImage/$(MODE_DIR)/Objects/DriveTrain/DriveEncoder.o : $(PRJ_ROOT_DIR)/DriveEncoder.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


DriveTrain_partialImage/$(MODE_DIR)/Objects/DriveTrain/DriveRobot.o : $(PRJ_ROOT_DIR)/DriveRobot.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


DriveTrain_partialImage/$(MODE_DIR)/Objects/DriveTrain/Gamepad.o : $(PRJ_ROOT_DIR)/Gamepad.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


OBJECTS_DriveTrain_partialImage = DriveTrain_partialImage/$(MODE_DIR)/Objects/DriveTrain/DriveEncoder.o \
	 DriveTrain_partialImage/$(MODE_DIR)/Objects/DriveTrain/DriveRobot.o \
	 DriveTrain_partialImage/$(MODE_DIR)/Objects/DriveTrain/Gamepad.o

DriveTrain_partialImage/$(MODE_DIR)/DriveTrain_partialImage.o : $(OBJECTS_DriveTrain_partialImage)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc -r -nostdlib -Wl,-X  -o "$@" $(OBJECTS_DriveTrain_partialImage) $(LIBPATH) $(LIBS) $(ADDED_LIBPATH) $(ADDED_LIBS)  && if [ "$(EXPAND_DBG)" = "1" ]; then plink "$@";fi

DriveTrain_partialImage/$(MODE_DIR)/DriveTrain_partialImage_compile_file : $(FILE) ;

_clean :: DriveTrain_partialImage/$(MODE_DIR)/DriveTrain_partialImage_clean

DriveTrain_partialImage/$(MODE_DIR)/DriveTrain_partialImage_clean : 
	$(TRACE_FLAG)if [ -d "DriveTrain_partialImage" ]; then cd "DriveTrain_partialImage"; rm -rf $(MODE_DIR); fi

force : 

DEP_FILES := DriveTrain_partialImage/$(MODE_DIR)/Objects/DriveTrain/DriveEncoder.d DriveTrain_partialImage/$(MODE_DIR)/Objects/DriveTrain/DriveRobot.d DriveTrain_partialImage/$(MODE_DIR)/Objects/DriveTrain/Gamepad.d
-include $(DEP_FILES)



-include $(PRJ_ROOT_DIR)/*.makefile

-include *.makefile

main_all : external_build $(PROJECT_TARGETS)
	@echo "make: built targets of `pwd`"

# entry point for extending the build
external_build ::
	@echo ""

# main entry point for pre processing prior to the build
pre_build :: $(PRE_BUILD_STEP) generate_sources
	@echo ""

# entry point for generating sources prior to the build
generate_sources ::
	@echo ""

# main entry point for post processing after the build
post_build :: $(POST_BUILD_STEP) deploy_output
	@echo ""

# entry point for deploying output after the build
deploy_output ::
	@echo ""

clean :: external_clean $(CLEAN_STEP) _clean

# entry point for extending the build clean
external_clean ::
	@echo ""
