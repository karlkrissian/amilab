# Create a library called "Hello" which includes the source file "hello.cxx".
# The extension is already found.  Any number of sources could be listed here.

MESSAGE("***** Boost_INCLUDE_DIR=${Boost_INCLUDE_DIR}")

# Make sure the compiler can find include files from our Hello library.
include_directories (
  ${AMILAB_SOURCE_DIR}/Common
  ${AMILAB_SOURCE_DIR}/Zinrimage
  ${AMILAB_SOURCE_DIR}/Images
  ${AMILAB_SOURCE_DIR}/Math
  ${AMILAB_SOURCE_DIR}/AMImage
  ${AMILAB_SOURCE_DIR}/AMILab
  ${AMILAB_SOURCE_DIR}/Language
  ${AMILAB_SOURCE_DIR}/OpenGL
  ${AMILAB_SOURCE_DIR}/Graphic
  ${AMILAB_SOURCE_DIR}/wxParams
  ${AMILAB_SOURCE_DIR}/myVTK4
  ${AMILAB_SOURCE_DIR}/Algorithms/Basic
  ${AMILAB_SOURCE_DIR}/Algorithms/Denoising
  ${AMILAB_SOURCE_DIR}/Algorithms/Others
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

my_add_library ( WrapAMIFluid)
