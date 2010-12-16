
INCLUDE( ${wxWidgets_USE_FILE})

# Make sure the compiler can find include files from our Hello library.
include_directories (
  ${wxParams_INCLUDE_DIRS}
  ${AMILAB_SOURCE_DIR}
  ${AMILAB_SOURCE_DIR}/Graphic/include
  ${AMILAB_SOURCE_DIR}/AMILab
  ${AMILAB_SOURCE_DIR}/Algorithms/include
  ${AMILAB_SOURCE_DIR}/Wrapping/WrapWxWidgets/${AMI_WXWIDGETS_VERSION}
  ${AMILAB_SOURCE_DIR}/Wrapping/WrapWxWidgets/${AMI_WXWIDGETS_VERSION}/Generated
)


SET(WrapViewer3D_SRCS
  wrap_Viewer3D.cpp
)

SET(WrapViewer3D_HDRS
  ../include/wrap_Viewer3D.h
)

SET(WrapViewer3D_SRCS
     ${WrapViewer3D_SRCS}
     ${WrapViewer3D_HDRS}
)

my_add_library ( WrapViewer3D)
