# Create a library called "Hello" which includes the source file "hello.cxx".
# The extension is already found.  Any number of sources could be listed here.

# Make sure the compiler can find include files from our Hello library.
include_directories (
  ${AMILAB_SOURCE_DIR}/Common
  ${AMILAB_SOURCE_DIR}/Zinrimage
  ${AMILAB_SOURCE_DIR}/Images
  ${AMILAB_SOURCE_DIR}/Math
  ${AMILAB_SOURCE_DIR}/ImageTool
  ${AMILAB_SOURCE_DIR}/Crest
  ${AMILAB_SOURCE_DIR}/Vaisseaux
  ${AMILAB_SOURCE_DIR}/Coordonnees
  ${AMILAB_SOURCE_DIR}/wxStcFrame
  ${AMILAB_SOURCE_DIR}/Wrapping/WrapBasicTypes
  ${AMILAB_SOURCE_DIR}/Wrapping/WrapInterface
  ${AMILAB_SOURCE_DIR}/Wrapping/WrapIO
  ${AMILAB_SOURCE_DIR}/Wrapping/WrapSystem
  ${AMILAB_SOURCE_DIR}/Wrapping/WrapITK
  ${AMILAB_SOURCE_DIR}/Wrapping/WrapAMIFluid
  ${AMILAB_SOURCE_DIR}/Wrapping/WrapFilters
  ${AMILAB_SOURCE_DIR}/Wrapping/WrapWxWidgets
  ${AMILAB_SOURCE_DIR}/Wrapping/WrapImage
  ${AMILAB_SOURCE_DIR}/Wrapping/WrapSurface
  ${AMILAB_SOURCE_DIR}/Wrapping/WrapDessinImage
  ${AMILAB_SOURCE_DIR}/Wrapping/WrapmyVTK
  ${AMILAB_SOURCE_DIR}
  ${Boost_INCLUDE_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${PTHREADS_INCLUDE_DIR}
)

INCLUDE( ${wxWidgets_USE_FILE})

SET(  WrapImports_SRCS
  wrap_imports.cpp
)

SET(WrapImports_HDRS
	wrap_imports.h
)

SET(WrapImports_SRCS
     ${WrapImports_SRCS}
     ${WrapImports_HDRS}
)

my_add_library ( WrapImports)
