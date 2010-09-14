
INCLUDE( ${wxWidgets_USE_FILE})

# Make sure the compiler can find include files from our Hello library.
include_directories (
  ${wxParams_INCLUDE_DIRS}
  ${AMILAB_SOURCE_DIR}
  ${AMILAB_SOURCE_DIR}/Graphic/include
  ${AMILAB_SOURCE_DIR}/Algorithms/include
  ${AMILAB_SOURCE_DIR}/AMILab
  ${AMILAB_SOURCE_DIR}/Language
  ${AMILAB_SOURCE_DIR}/Wrapping/include
)


SET(  WrapDessinImage_SRCS
  wrap_DessinImage.cpp
)

SET(WrapDessinImage_HDRS
  ../include/wrap_DessinImage.h
)

SET(WrapDessinImage_SRCS
     ${WrapDessinImage_SRCS}
     ${WrapDessinImage_HDRS}
)

my_add_library ( WrapDessinImage)