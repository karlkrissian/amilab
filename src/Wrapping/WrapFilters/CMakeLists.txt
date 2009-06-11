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
  ${AMILAB_SOURCE_DIR}/Vaisseaux
  ${AMILAB_SOURCE_DIR}/Algorithms/Basic
  ${AMILAB_SOURCE_DIR}/Algorithms/Denoising
  ${Boost_INCLUDE_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}
)

IF(AMI_USE_FASTNLMEANS)
  MESSAGE("including NewNLMeans_INCLUDE_DIRS=${NewNLMeans_INCLUDE_DIRS}")
  include_directories (
    ${NewNLMeans_INCLUDE_DIRS}
  )
ENDIF(AMI_USE_FASTNLMEANS)

INCLUDE( ${VTK_USE_FILE} )
INCLUDE( ${wxWidgets_USE_FILE})

SET(  WrapFilters_SRCS
  wrapFilters.cpp
  wrapAlgorithmsBasic.cpp
)

my_add_library ( WrapFilters)
