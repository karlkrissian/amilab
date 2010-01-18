# Create a library called "Hello" which includes the source file "hello.cxx".
# The extension is already found.  Any number of sources could be listed here.


# Make sure the compiler can find include files from our Hello library.
include_directories (
  ${AMILAB_SOURCE_DIR}/Common
  ${AMILAB_SOURCE_DIR}/Images
  ${AMILAB_SOURCE_DIR}/Math
  ${AMILAB_SOURCE_DIR}/AMImage
  ${AMILAB_SOURCE_DIR}/Coordonnees
  ${AMILAB_SOURCE_DIR}/Filtrage
  ${AMILAB_SOURCE_DIR}/Graph
  ${AMILAB_SOURCE_DIR}/AMILab
  ${AMILAB_SOURCE_DIR}/Language
  ${AMILAB_SOURCE_DIR}/OpenGL
  ${AMILAB_SOURCE_DIR}/Algorithms/Basic
  ${AMILAB_SOURCE_DIR}/Algorithms/Denoising
  ${AMILAB_SOURCE_DIR}/Wrapping/WrapCommon
  ${AMILAB_SOURCE_DIR}
  ${AMIFLUID_INCLUDE_DIR}
  ${PTHREADS_INCLUDE_DIR}
  ${Boost_INCLUDE_DIR}
  )

INCLUDE( ${VTK_USE_FILE} )
INCLUDE(${wxWidgets_USE_FILE})

IF(AMI_USE_FASTNLMEANS)
  MESSAGE("including NewNLMeans_INCLUDE_DIRS=${NewNLMeans_INCLUDE_DIRS}")
  include_directories (
    ${NewNLMeans_INCLUDE_DIRS}
  )
ENDIF(AMI_USE_FASTNLMEANS)

SET(Algorithms_SRCS
  BasicFilter/ImageToImageFilter.cpp
  BasicFilter/ImageAddScalar.cpp
  BasicFilter/ImageCos.cpp
  Basic/localstats.cpp
  Graph/func_shortestpath.cpp

  Denoising/AnisoGS.cpp
  Denoising/Wrap_AnisoGS.cpp
  Denoising/NLmeans.cpp

  Others/ComputePartialVolume.cpp
)


SET(Algorithms_HDRS
  BasicFilter/ImageToImageFilter.h
  BasicFilter/ImageAddScalar.h
  BasicFilter/ImageCos.h
  Basic/localstats.h
  Graph/func_shortestpath.h

  Denoising/AnisoGS.h
  Denoising/Wrap_AnisoGS.h
  Denoising/NLmeans.h

  Others/ComputePartialVolume.h
)

SET(OpenGL_SRCS
     ${OpenGL_SRCS}
     ${OpenGL_HDRS}
)

my_add_library ( Algorithms)
