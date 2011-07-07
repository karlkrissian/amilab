# Create a library called "Hello" which includes the source file "hello.cxx".
# The extension is already found.  Any number of sources could be listed here.

add_subdirectory (myVTK4)
add_subdirectory (DerivAndOrient)

# Make sure the compiler can find include files from our Hello library.
include_directories (
  ${AMILAB_SOURCE_DIR}/Graphic/include
  ${AMILAB_SOURCE_DIR}/Algorithms/include
  ${AMILAB_SOURCE_DIR}/Common/include
  ${AMILAB_SOURCE_DIR}/AMILab
  ${AMILAB_SOURCE_DIR}/Language
  ${AMILAB_SOURCE_DIR}/Wrapping/WrapCommon
  ${AMILAB_SOURCE_DIR}
  ${AMIFLUID_INCLUDE_DIR}
  ${PTHREADS_INCLUDE_DIR}
  ${Boost_INCLUDE_DIR}
  ${wxParams_INCLUDE_DIRS}
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
  ShortestPathClass.cpp

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
  CalculRepCercle.cpp
  CircleBoundaries3D.cpp

  Gradient.cpp
  Curvatures.cpp

  # from Contours
  CalculAireSection.cpp
  IsoContour2.cpp
  IsoContour2D.cpp
  IsoContour.cpp
  PointContour.cpp

  # from Vaisseaux
  Vaisseaux/CalculBoules.cpp
  Vaisseaux/IntersectIsosurf.cpp
  Vaisseaux/IsoLigne.cpp
  Vaisseaux/Vaisseau.cpp
  Vaisseaux/CalculIsoLignes.cpp
  Vaisseaux/ImageVaisseaux.cpp
  Vaisseaux/IsoLigne2.cpp
  Vaisseaux/Voxel.cpp

  # from SplineThevenaz
  SplineThevenaz/coeff.c 
  SplineThevenaz/interpol.c
  
  # from Graph
  Graph/dijkstra.cpp
)


SET(Algorithms_HDRS
  include/ImageToImageFilter.h
  include/ImageAddScalar.h
  include/ImageCos.h
  include/localstats.h
  include/ShortestPathClass.h

  include/AnisoGS.h
  include/WrapOld_AnisoGS.h
  include/NLmeans.h

  include/RegionGrowingTest.h

  include/ComputePartialVolume.h

  # files coming from previous Filtering directory
  include/bruit.hpp
  include/DeriveesLissees.hpp
  include/GaussianFilter.h
  include/filtrage_rec.hpp
  include/GeneralGaussianFilter.h
  include/filtre_param.hpp

  # files coming from previous Line directory
  include/CalculRepCercle.hpp
  include/CircleBoundaries3D.h

  include/Gradient.h
  include/Curvatures.h

  # from Contours
  include/CalculAireSection.hpp
  include/IsoContour.hpp
  include/IsoContour2.hpp
  include/IsoContour2D.hpp
  include/PointContour.hpp
  include/PropagePoints.hpp

  # from Vaisseaux
  include/CalculBoules.hpp
  include/CalculIsoLignes.hpp
  include/ImageVaisseaux.hpp
  include/InrViewIsoLignes.hpp
  include/IntersectIsosurf.hpp
  include/IsoLigne.hpp
  include/IsoLigne2.hpp
  include/Vaisseau.hpp
  include/Voxel.hpp

  # from SplineThevenaz
  include/coeff.h
  include/interpol.h

  # from Graph
  include/dijkstra.h
)

SET(OpenGL_SRCS
     ${OpenGL_SRCS}
     ${OpenGL_HDRS}
)

my_add_library ( Algorithms)
