# Create a library called "Hello" which includes the source file "hello.cxx".
# The extension is already found.  Any number of sources could be listed here.


# Make sure the compiler can find include files from our Hello library.
include_directories (
  ${AMILAB_SOURCE_DIR}/ImageTool
  ${AMILAB_SOURCE_DIR}/Crest
  ${AMILAB_SOURCE_DIR}/Vaisseaux
  ${AMILAB_SOURCE_DIR}/Graphic
  ${AMILAB_SOURCE_DIR}/Common
  ${AMILAB_SOURCE_DIR}/Images
  ${AMILAB_SOURCE_DIR}/AMImage
  ${AMILAB_SOURCE_DIR}/Coordonnees
  ${AMILAB_SOURCE_DIR}/Filtering
  ${AMILAB_SOURCE_DIR}/Graph
  ${AMILAB_SOURCE_DIR}/AMILab
  ${AMILAB_SOURCE_DIR}/Language
  ${AMILAB_SOURCE_DIR}/OpenGL
  ${AMILAB_SOURCE_DIR}/Algorithms
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
  ImageToImageFilter.cpp
  ImageAddScalar.cpp
  ImageCos.cpp
  localstats.cpp
  func_shortestpath.cpp

  AnisoGS.cpp
  WrapOld_AnisoGS.cpp
  NLmeans.cpp

  RegionGrowingTest.cpp

  ComputePartialVolume.cpp

  # files coming from previous Filtering directory
  bruit.cpp
  DeriveesLissees.cpp
  GaussianFilter.cpp
  filtrage_rec.cpp
  GeneralGaussianFilter.cpp

  # files coming from previous Line directory
  reponse_cercle.cpp
)


SET(Algorithms_HDRS
  ImageToImageFilter.h
  ImageAddScalar.h
  ImageCos.h
  localstats.h
  func_shortestpath.h

  AnisoGS.h
  WrapOld_AnisoGS.h
  NLmeans.h

  RegionGrowingTest.h

  ComputePartialVolume.h

  # files coming from previous Filtering directory
  bruit.hpp
  DeriveesLissees.hpp
  GaussianFilter.h
  filtrage_rec.hpp
  GeneralGaussianFilter.h
  filtre_param.hpp

  # files coming from previous Line directory
  reponse_cercle.hpp
)

SET(OpenGL_SRCS
     ${OpenGL_SRCS}
     ${OpenGL_HDRS}
)

my_add_library ( Algorithms)
