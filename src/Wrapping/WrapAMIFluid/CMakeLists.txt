# Create a library called "Hello" which includes the source file "hello.cxx".
# The extension is already found.  Any number of sources could be listed here.

MESSAGE("***** Boost_INCLUDE_DIR=${Boost_INCLUDE_DIR}")

# Make sure the compiler can find include files from our Hello library.
include_directories (
  ${AMILAB_SOURCE_DIR}/Common
  ${AMILAB_SOURCE_DIR}/AMILab
  ${AMILAB_SOURCE_DIR}/Language
  ${AMILAB_SOURCE_DIR}/OpenGL
  ${AMILAB_SOURCE_DIR}/Graphic
  ${AMILAB_SOURCE_DIR}/wxParams
  ${AMILAB_SOURCE_DIR}/myVTK4
  ${AMILAB_SOURCE_DIR}/Algorithms/include
  ${AMILAB_SOURCE_DIR}/Wrapping/WrapCommon
  ${OPTICFLOW_INCLUDE_DIR}
  ${OPTICFLOW_INCLUDE_DIR}/OpticalFlow
  ${OPTICFLOW_INCLUDE_DIR}/OpticalFlow/src
  ${AMILAB_SOURCE_DIR}
  ${AMIFLUID_INCLUDE_DIR}
  ${Boost_INCLUDE_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${PTHREADS_INCLUDE_DIR}
)

INCLUDE( ${VTK_USE_FILE} )
INCLUDE( ${wxWidgets_USE_FILE})

SET(  WrapAMIFluid_SRCS
  wrapAMIFluid.cpp
)

SET(WrapAMIFluid_HDRS
	wrapAMIFluid.h
)

SET(WrapAMIFluid_SRCS
     ${WrapAMIFluid_SRCS}
     ${WrapAMIFluid_HDRS}
)

my_add_library ( WrapAMIFluid)
