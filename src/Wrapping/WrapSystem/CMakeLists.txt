# Create a library called "Hello" which includes the source file "hello.cxx".
# The extension is already found.  Any number of sources could be listed here.

# Make sure the compiler can find include files from our Hello library.
include_directories (
  ${AMILAB_SOURCE_DIR}/AMILab
  ${AMILAB_SOURCE_DIR}/Language
  ${CMAKE_CURRENT_SOURCE_DIR}
)

INCLUDE( ${wxWidgets_USE_FILE})

SET(  WrapSystem_SRCS
  wrapSystem.cpp
)

SET(WrapSystem_HDRS
	../include/wrapSystem.h
)

SET(WrapSystem_SRCS
     ${WrapSystem_SRCS}
     ${WrapSystem_HDRS}
)

my_add_library ( WrapSystem)

SET_TARGET_PROPERTIES( WrapSystem
  PROPERTIES
    COMPILE_DEFINITIONS_DEBUG           "_CMAKEBUILDTYPE_DEBUG_"
    COMPILE_DEFINITIONS_RELEASE         "_CMAKEBUILDTYPE_RELEASE_"
    COMPILE_DEFINITIONS_MINSIZEREL      "_CMAKEBUILDTYPE_MINSIZEREL_"
    COMPILE_DEFINITIONS_RELWITHDEBINFO  "_CMAKEBUILDTYPE_RELWITHDEBINFO_"
)
