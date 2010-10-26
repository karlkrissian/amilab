# Create a library called "Hello" which includes the source file "hello.cxx".
# The extension is already found.  Any number of sources could be listed here.
MESSAGE("***** Boost_INCLUDE_DIR=${Boost_INCLUDE_DIR}")

# Make sure the compiler can find include files from our Hello library.
include_directories (
  ${wxParams_INCLUDE_DIRS}
  ${AMILAB_SOURCE_DIR}/Common/include
  ${AMILAB_SOURCE_DIR}/Graphic/include
  ${AMILAB_SOURCE_DIR}/Wrapping/include
  ${Boost_INCLUDE_DIR}
  )

INCLUDE( ${USE_ITK_FILE} )
MESSAGE( "USE_ITK_FILE = ${USE_ITK_FILE}")
INCLUDE( ${wxWidgets_USE_FILE})

INCLUDE( ${USE_VTK_FILE})
MESSAGE( "USE_VTK_FILE = ${USE_VTK_FILE}")

SET(  WrapITK_SRCS
    itkCannyEdgeDetector.cpp
    wrapITK.cpp
    LeastSquares.cpp
    wrapitkRecursiveGaussianImageFilter.cpp
    #wrapitkRead_3D_US.cpp
    ami_itkRead.cpp
    wrapitkRead.cpp
    ami_itkWrite.cpp
    wrapitkWrite.cpp
    wrapitkIsoContourDist.cpp
    wrapitkBasicNLMeansFilter.cpp
    wrapitkFastMarchingImageFilter.cpp
    wrapitkWaterShedImageFilter.cpp
    wrapitkMultiScaleVesselnessFilter.cpp
    wrapitkDICOMRead.cpp
    wrapitkSigmoidImageFilter.cpp
    wrapitkLevelSet.cpp
    wrapitkBinaryThresholdImageFilter.cpp
    wrapitkBackTrackingMeshFilter.cpp
    wrapitkLocalMeanImageFilter.cpp
    wrapitkTranslateImageFilter.cpp
)

SET(WrapITK_HDRS
	../include/itkCannyEdgeDetector.h
	../include/wrapConversion.h
	../include/wrapITK.h
	../include/wrapitkFastMarchingImageFilter.h
	../include/wrapitkIsoContourDist.h
  ../include/ami_itkRead.h
	../include/wrapitkRead.h
	#wrapitkRead_3D_US.h
	../include/wrapitkRecursiveGaussianImageFilter.h
	../include/wrapitkWaterShedImageFilter.h
  ../include/ami_itkWrite.h
	../include/wrapitkWrite.h
	../include/wrapitkBackTrackingMeshFilter.h
	../include/wrapitkLocalMeanImageFilter.h
	../include/wrapitkTranslateImageFilter.h
  ../include/itkBasicNLMeansFilter.txx
)

SET(WrapITK_SRCS
     ${WrapITK_SRCS}
     ${WrapITK_HDRS}
)

my_add_library ( WrapITK)
