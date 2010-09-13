
# Make sure the compiler can find include files from our Hello library.
include_directories (
  ${AMILAB_SOURCE_DIR}
  ${AMILAB_SOURCE_DIR}/Graphic/include
  ${AMILAB_SOURCE_DIR}/Algorithms/include
  ${AMILAB_SOURCE_DIR}/AMILab
  ${AMILAB_SOURCE_DIR}/Wrapping/include
  ${AMILAB_SOURCE_DIR}/wxCode/wxTreeListCtrl
  ${CMAKE_CURRENT_SOURCE_DIR}
)

INCLUDE( ${wxWidgets_USE_FILE})

SET(  WrapGLTransfMatrix_SRCS
  wrap_GLTransfMatrix.cpp
)

SET(GLTransfMatrix_HDRS
  ../include/wrap_GLTransfMatrix.h
)

SET(WrapGLTransfMatrix_SRCS
     ${WrapGLTransfMatrix_SRCS}
     ${WrapGLTransfMatrix_HDRS}
)

my_add_library ( WrapGLTransfMatrix)
