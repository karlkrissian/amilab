
INCLUDE( ${wxWidgets_USE_FILE})
# Make sure the compiler can find include files from our Hello library.
include_directories (
  ${wxParams_INCLUDE_DIRS}
  ${AMILAB_SOURCE_DIR}
  ${AMILAB_SOURCE_DIR}/Graphic/include
  ${AMILAB_SOURCE_DIR}/Algorithms/include
  ${AMILAB_SOURCE_DIR}/AMILab
  ${AMILAB_SOURCE_DIR}/Wrapping/include
)


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
