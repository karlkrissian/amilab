# Create a library called "Hello" which includes the source file "hello.cxx".
# The extension is already found.  Any number of sources could be listed here.

add_subdirectory (myVTK4)
add_subdirectory (DerivAndOrient)

# Make sure the compiler can find include files from our Hello library.
include_directories (
  ${AMILAB_SOURCE_DIR}/Graphic/include
  ${AMILAB_SOURCE_DIR}/Algorithms/include
  ${AMILAB_SOURCE_DIR}/CommonBase
  ${AMILAB_SOURCE_DIR}/Common/include
  ${AMILAB_SOURCE_DIR}/AMILab
  ${AMILAB_SOURCE_DIR}/LanguageBase
  ${AMILAB_SOURCE_DIR}/Language
  ${AMILAB_SOURCE_DIR}/Wrapping/include
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
  amiImageToImageFilter.cpp
  amiImageAddScalar.cpp
  amiImageCos.cpp
  amiGrayscaleMorpho.cpp
  amiSRAD.cpp
  amiThinning.cpp
  amivtkFastMarchingFunctions.cpp

  # functions
  amiFind.cpp

  localstats.cpp
  ShortestPathClass.cpp

  amiAnisoGS.cpp
  #WrapOld_AnisoGS.cpp
  NLmeans.cpp

  amiRegionGrowingBase.cpp

  #AnalyticFunctionBase.cpp
  ComputePartialVolume.cpp
  StructureTensor.cpp
  HessianMatrix.cpp
  Eigen3D.cpp
  DiscSecDerGrad.cpp
  NormGrad.cpp
  DiscNormGrad.cpp
  DiscMeanCurvature.cpp
  ImageDerivatives.cpp
  Chamfer.cpp
  DistanceTransforms.cpp
  func_globalstats.cpp

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

  # from SplineThevenaz
  SplineThevenaz/coeff.c 
  SplineThevenaz/interpol.c
  
  # from Graph
  Graph/dijkstra.cpp
)


SET(Algorithms_HDRS
  include/amiImageToImageFilter.h
  include/amiImageAddScalar.h
  include/amiImageCos.h
  include/amiGrayscaleMorpho.h
  include/amiSRAD.h
  include/amiRegionGrowingBase.h
  include/amiIntensityBasedRegionGrowing.h
  include/amiFieldOrientationRegionGrowing.h
  include/amiThinning.h
  # functions
  include/amiFind.h
  include/amivtkFastMarchingFunctions.h

  include/localstats.h
  include/ShortestPathClass.h

  include/amiAnisoGS.h
  #include/WrapOld_AnisoGS.h
  include/NLmeans.h


  include/AnalyticFunctionBase.h
  include/ComputePartialVolume.h
  include/StructureTensor.h
  include/HessianMatrix.h
  include/Eigen3D.h
  include/DiscSecDerGrad.h
  include/NormGrad.h
  include/DiscNormGrad.h
  include/DiscMeanCurvature.h
  include/ImageDerivatives.h
  include/FastVector.hpp
  include/FastVector.tpp
  include/Chamfer.h
  include/DistanceTransforms.h
  include/func_globalstats.h

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

  # from SplineThevenaz
  include/coeff.h
  include/interpol.h

  # from Graph
  include/dijkstra.h
)

IF(WIN32)
  set_source_files_properties(${Algorithms_SRCS} PROPERTIES COMPILE_FLAGS "-DAlgorithms_EXPORTS")
ENDIF(WIN32)

SET(Algorithms_SRCS
     ${Algorithms_SRCS}
     ${Algorithms_HDRS}
)

my_add_library ( Algorithms)
