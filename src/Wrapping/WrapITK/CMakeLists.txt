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
  ${Boost_INCLUDE_DIR}
  )

INCLUDE( ${USE_ITK_FILE} )
MESSAGE( "USE_ITK_FILE = ${USE_ITK_FILE}")

INCLUDE( ${wxWidgets_USE_FILE})
MESSAGE( "wxWidgets_USE_FILE = ${wxWidgets_USE_FILE}")

SET(  WrapITK_SRCS
    itkCannyEdgeDetector.cpp
    wrapITK.cpp
    LeastSquares.cpp
    wrapitkRecursiveGaussianImageFilter.cpp
    wrapitkRead_3D_US.cpp
    wrapitkRead.cpp
    wrapitkWrite.cpp
    wrapitkIsoContourDist.cpp
    wrapitkBasicNLMeansFilter.cpp
    itkBasicNLMeansFilter.txx
    wrapitkFastMarchingImageFilter.cpp
    wrapitkWaterShedImageFilter.cpp
    wrapitkMultiScaleVesselnessFilter.cpp
    wrapitkDICOMReadWrite.cpp
    wrapitkSigmoidImageFilter.cpp
    wrapitkLevelSet.cpp
    wrapitkBinaryThresholdImageFilter.cpp
    #wrapitkFastNLMeansImageFilter.cpp
)

my_add_library ( WrapITK)
