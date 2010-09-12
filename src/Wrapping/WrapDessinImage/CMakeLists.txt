
# Make sure the compiler can find include files from our Hello library.
include_directories (
  ${AMILAB_SOURCE_DIR}
  ${AMILAB_SOURCE_DIR}/Graphic/include
  ${AMILAB_SOURCE_DIR}/AMILab
  ${AMILAB_SOURCE_DIR}/Language
  ${AMILAB_SOURCE_DIR}/Wrapping/WrapVTK
  ${AMILAB_SOURCE_DIR}/wxCode/wxTreeListCtrl
  ${AMILAB_SOURCE_DIR}/Wrapping/WrapWxWidgets
  ${AMILAB_SOURCE_DIR}/Wrapping/WrapInterface
  ${AMILAB_SOURCE_DIR}/Wrapping/WrapViewer3D
  ${AMILAB_SOURCE_DIR}/Wrapping/WrapGLTransfMatrix
  ${AMILAB_SOURCE_DIR}/Wrapping/WrapSurface
  ${Boost_INCLUDE_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${PTHREADS_INCLUDE_DIR}
)

INCLUDE( ${wxWidgets_USE_FILE})

SET(  WrapDessinImage_SRCS
  wrap_DessinImage.cpp
)

SET(WrapDessinImage_HDRS
  wrap_DessinImage.h
)

SET(WrapDessinImage_SRCS
     ${WrapDessinImage_SRCS}
     ${WrapDessinImage_HDRS}
)

my_add_library ( WrapDessinImage)