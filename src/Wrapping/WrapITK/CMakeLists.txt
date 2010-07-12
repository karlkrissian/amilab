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
  ${AMILAB_SOURCE_DIR}/Wrapping/WrapSurface
  ${Boost_INCLUDE_DIR}
  )

INCLUDE( ${USE_ITK_FILE} )
MESSAGE( "USE_ITK_FILE = ${USE_ITK_FILE}")

INCLUDE( ${wxWidgets_USE_FILE})
MESSAGE( "wxWidgets_USE_FILE = ${wxWidgets_USE_FILE}")

SET(  WrapITK_SRCS
    itkCannyEdgeDetector.cpp
    wrapITK.cpp
    wrapitkRecursiveGaussianImageFilter.cpp
    #wrapitkRead_3D_US.cpp
    ami_itkRead.cpp
    wrapitkRead.cpp
    ami_itkWrite.cpp
    wrapitkWrite.cpp
    wrapitkIsoContourDist.cpp
    #wrapitkBasicNLMeansFilter.cpp
    #itkBasicNLMeansFilter.txx
    wrapitkFastMarchingImageFilter.cpp
	wrapitkWaterShedImageFilter.cpp
)

SET(WrapITK_HDRS
	itkCannyEdgeDetector.h
	wrapConversion.h
	wrapITK.h
	wrapitkFastMarchingImageFilter.h
	wrapitkIsoContourDist.h
  ami_itkRead.h
	wrapitkRead.h
	#wrapitkRead_3D_US.h
	wrapitkRecursiveGaussianImageFilter.h
	wrapitkWaterShedImageFilter.h
  ami_itkWrite.h
	wrapitkWrite.h
)

SET(WrapITK_SRCS
     ${WrapITK_SRCS}
     ${WrapITK_HDRS}
)

my_add_library ( WrapITK)
