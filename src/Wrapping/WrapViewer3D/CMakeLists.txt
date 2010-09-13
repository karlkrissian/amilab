
# Make sure the compiler can find include files from our Hello library.
include_directories (
  ${AMILAB_SOURCE_DIR}
  ${AMILAB_SOURCE_DIR}/Graphic/include
  ${AMILAB_SOURCE_DIR}/AMILab
  ${AMILAB_SOURCE_DIR}/Algorithms/include
  ${AMILAB_SOURCE_DIR}/wxCode/wxTreeListCtrl
  ${CMAKE_CURRENT_SOURCE_DIR}
)

INCLUDE( ${wxWidgets_USE_FILE})

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
