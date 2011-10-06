
# Make sure the compiler can find include files from our Hello library.
include_directories (
  ${wxParams_INCLUDE_DIRS}
  ${AMILAB_SOURCE_DIR}
  ${AMILAB_SOURCE_DIR}/Graphic/include
  ${AMILAB_SOURCE_DIR}/AMILab
  ${AMILAB_SOURCE_DIR}/Language
  ${AMILAB_SOURCE_DIR}/Algorithms/include
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${PTHREADS_INCLUDE_DIR}
)

INCLUDE( ${wxWidgets_USE_FILE})

SET(  WrapSurface_SRCS
  wrap_SurfacePoly.cpp
)

SET(WrapSurface_HDRS
  ../include/wrap_SurfacePoly.h
)

SET(WrapSurface_SRCS
     ${WrapSurface_SRCS}
     ${WrapSurface_HDRS}
)

my_add_library ( WrapSurface)
