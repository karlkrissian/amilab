
# Make sure the compiler can find include files from our Hello library.
include_directories (
  ${AMILAB_SOURCE_DIR}
  ${AMILAB_SOURCE_DIR}/Images
  ${AMILAB_SOURCE_DIR}/OpenGL
  ${AMILAB_SOURCE_DIR}/AMILab
  ${AMILAB_SOURCE_DIR}/Language
  ${AMILAB_SOURCE_DIR}/Wrapping/WrapVTK
  ${AMILAB_SOURCE_DIR}/wxCode/wxTreeListCtrl
  ${AMILAB_SOURCE_DIR}/Wrapping/WrapWxWidgets
  ${AMILAB_SOURCE_DIR}/Wrapping/WrapInterface
  ${AMILAB_SOURCE_DIR}/Wrapping/WrapSurface
  ${Boost_INCLUDE_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${PTHREADS_INCLUDE_DIR}
)

INCLUDE( ${wxWidgets_USE_FILE})

SET(  WrapViewer3D_SRCS
  wrap_Viewer3D.cpp
)

SET(WrapViewer3D_HDRS
  wrap_Viewer3D.h
)

SET(WrapViewer3D_SRCS
     ${WrapViewer3D_SRCS}
     ${WrapViewer3D_HDRS}
)

my_add_library ( WrapViewer3D)
