# Create a library called "Hello" which includes the source file "hello.cxx".
# The extension is already found.  Any number of sources could be listed here.

# Make sure the compiler can find include files from our Hello library.
include_directories (
  ${wxParams_INCLUDE_DIRS}
  ${AMILAB_SOURCE_DIR}/CommonBase
  ${AMILAB_SOURCE_DIR}/Common/include
  ${AMILAB_SOURCE_DIR}/Graphic/include
  ${AMILAB_SOURCE_DIR}/Algorithms/include
  ${AMILAB_SOURCE_DIR}/Wrapping/include
  ${AMILAB_SOURCE_DIR}/Wrapping/WrapWxWidgets/${AMI_WXWIDGETS_VERSION}
  ${AMILab_BINARY_DIR}/Wrapping/WrapWxWidgets/${AMI_WXWIDGETS_VERSION}/Generated
  ${AMILAB_SOURCE_DIR}/AMILab
  ${AMILAB_SOURCE_DIR}
  ${Boost_INCLUDE_DIR}
  ${PTHREADS_INCLUDE_DIR}
)

INCLUDE( ${wxWidgets_USE_FILE})

SET(  WrapInterface_SRCS
  wrap_MainFrame.cpp
#  wrap_imagedraw.cpp 
  wrap_parampanel.cpp 
  wrap_wxDrawingWindow.cpp 
  wrap_wxEditor.cpp 
  wrap_wxStcFrame.cpp 
  wrap_FenetreDessin.cpp 
  wrap_DessinImage.cpp
  wrap_dwControlPoint.cpp
  wrap_dwPoint2D.cpp
  wrap_dwCurve.cpp
  wrap_dwControlledCurve.cpp
  wrap_Viewer3D.cpp
  wrap_GLTransfMatrix.cpp
  wrap_SurfacePoly.cpp
  wrap_RGBTransformBase.cpp
  wrap_RGBTransformComponent.cpp
  wrap_RGBTransformHSV.cpp
  wrap_RGBTransformInc.cpp
  wrap_RGBTransformGamma.cpp
)

SET(WrapInterface_HDRS
  ../include/wrap_MainFrame.h
#  wrap_imagedraw.h
  ../include/wrap_parampanel.h 
  ../include/wrap_wxDrawingWindow.h
  ../include/wrap_wxEditor.h
  ../include/wrap_wxStcFrame.h 
  ../include/wrap_FenetreDessin.h
  ../include/wrap_DessinImage.h
  ../include/wrap_dwControlPoint.h
  ../include/wrap_dwPoint2D.h
  ../include/wrap_dwCurve.h
  ../include/wrap_dwControlledCurve.h
  ../include/wrap_Viewer3D.h
  ../include/wrap_SurfacePoly.h
  ../include/wrap_RGBTransformBase.h
  ../include/wrap_RGBTransformComponent.h
  ../include/wrap_RGBTransformHSV.h
  ../include/wrap_RGBTransformInc.h
  ../include/wrap_RGBTransformGamma.h
)

SET(WrapInterface_SRCS
     ${WrapInterface_SRCS}
     ${WrapInterface_HDRS}
)

IF(AMI_USE_PRECOM_HEADERS)
  IF(CMAKE_COMPILER_IS_GNUCXX)
    ADD_PCH_RULE(${AMILAB_SOURCE_DIR}/Wrapping/include/WrapInterface_header.h WrapInterface_SRCS)
  ENDIF(CMAKE_COMPILER_IS_GNUCXX )
ENDIF(AMI_USE_PRECOM_HEADERS)

my_add_library ( WrapInterface)
add_dependencies ( WrapInterface WrapWxWidgets )