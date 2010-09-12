
# Make sure the compiler can find include files from our Hello library.
include_directories (
  ${AMILAB_SOURCE_DIR}
  ${AMILAB_SOURCE_DIR}/OpenGL
  ${AMILAB_SOURCE_DIR}/AMILab
  ${AMILAB_SOURCE_DIR}/Language
  ${AMILAB_SOURCE_DIR}/Wrapping/WrapVTK
  ${Boost_INCLUDE_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${PTHREADS_INCLUDE_DIR}
)

INCLUDE( ${wxWidgets_USE_FILE})

SET(  WrapSurface_SRCS
  wrap_SurfacePoly.cpp
)

SET(WrapSurface_HDRS
  wrap_SurfacePoly.h
)

SET(WrapSurface_SRCS
     ${WrapSurface_SRCS}
     ${WrapSurface_HDRS}
)

my_add_library ( WrapSurface)
