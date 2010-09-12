
# Make sure the compiler can find include files from our Hello library.
include_directories (
  ${AMILAB_SOURCE_DIR}
  ${AMILAB_SOURCE_DIR}/OpenGL
  ${AMILAB_SOURCE_DIR}/AMILab
  ${AMILAB_SOURCE_DIR}/Language
  ${AMILAB_SOURCE_DIR}/Wrapping/WrapVTK
  ${AMILAB_SOURCE_DIR}/wxCode/wxTreeListCtrl
  ${AMILAB_SOURCE_DIR}/Wrapping/WrapWxWidgets
  ${AMILAB_SOURCE_DIR}/Wrapping/WrapInterface
  ${Boost_INCLUDE_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${PTHREADS_INCLUDE_DIR}
)

INCLUDE( ${wxWidgets_USE_FILE})

SET(  WrapGLTransfMatrix_SRCS
  wrap_GLTransfMatrix.cpp
)

SET(GLTransfMatrix_HDRS
  wrap_GLTransfMatrix.h
)

SET(WrapGLTransfMatrix_SRCS
     ${WrapGLTransfMatrix_SRCS}
     ${WrapGLTransfMatrix_HDRS}
)

my_add_library ( WrapGLTransfMatrix)
