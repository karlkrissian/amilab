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
  ${AMILAB_SOURCE_DIR}/Filtering
  ${AMILAB_SOURCE_DIR}/Algorithms/Basic
  ${AMILAB_SOURCE_DIR}/Algorithms/Denoising
  ${AMILAB_SOURCE_DIR}/Algorithms/Others
  ${AMILAB_SOURCE_DIR}/Algorithms/BasicFilter
  ${AMILAB_SOURCE_DIR}/Algorithms/Segmentation
  ${AMILAB_SOURCE_DIR}/Wrapping/WrapCommon
  ${AMILAB_SOURCE_DIR}/Wrapping/WrapSurface
  ${AMILAB_SOURCE_DIR}
  ${Boost_INCLUDE_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${PTHREADS_INCLUDE_DIR}
)

IF(AMI_USE_FASTNLMEANS)
  MESSAGE("including NewNLMeans_INCLUDE_DIRS=${NewNLMeans_INCLUDE_DIRS}")
  include_directories (
    ${NewNLMeans_INCLUDE_DIRS}
  )
ENDIF(AMI_USE_FASTNLMEANS)

INCLUDE( ${USE_ITK_FILE} )
INCLUDE( ${VTK_USE_FILE} )
INCLUDE( ${wxWidgets_USE_FILE})

SET(  WrapFilters_SRCS
  wrapFilters.cpp
  wrapAlgorithmsBasic.cpp
  wrapComputePV.cpp
  wrap_StructureTensor.cpp
  wrap_NLmeans.cpp
  Wrap_NewNLMeans.cpp
  wrap_DirSum.cpp
  wrap_ImTranslate.cpp
  wrap_AddSubImage.cpp
  wrap_MaxSubImage.cpp
  LeastSquares.cpp
  wrap_ImageAddScalar.cpp
  wrap_ImageCos.cpp
	wrapBasicEdgeDetection.cpp
  wrapSubPixel2D.cpp
  wrapGenerateRamp.cpp
  wrap_AnisoGS.cpp
  wrap_ContinuousMorphology.cpp
)

SET(WrapFilters_HDRS
	LeastSquares.h
	wrapAlgorithmsBasic.h
	wrapComputePV.h
	wrapFilters.h
	wrap_AddSubImage.h
	wrap_DirSum.h
	wrap_ImTranslate.h
	wrap_MaxSubImage.h
	Wrap_NewNLMeans.h
	wrap_NLmeans.h
  wrap_StructureTensor.h
  wrap_ImageAddScalar.h
  wrap_ImageCos.h
	wrapBasicEdgeDetection.h
  wrapSubPixel2D.h
  wrapGenerateRamp.h
  wrap_AnisoGS.h
  wrap_ContinuousMorphology.h
)

SET(WrapFilters_SRCS
     ${WrapFilters_SRCS}
     ${WrapFilters_HDRS}
)

my_add_library ( WrapFilters)
