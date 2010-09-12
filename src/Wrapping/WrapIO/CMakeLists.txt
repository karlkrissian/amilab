# Create a library called "Hello" which includes the source file "hello.cxx".
# The extension is already found.  Any number of sources could be listed here.

# Make sure the compiler can find include files from our Hello library.
include_directories (
  ${AMILAB_SOURCE_DIR}/Common
  ${AMILAB_SOURCE_DIR}/Wrapping/WrapCommon
  ${AMILAB_SOURCE_DIR}/Wrapping/WrapIO
  ${AMILAB_SOURCE_DIR}
  ${Boost_INCLUDE_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${PTHREADS_INCLUDE_DIR}
)

INCLUDE( ${wxWidgets_USE_FILE})

SET(  WrapIO_SRCS
  wrap_ReadRawImages.cpp
)

SET(WrapIO_HDRS
  wrap_ReadRawImages.h
)

SET(WrapIO_SRCS
     ${WrapIO_SRCS}
     ${WrapIO_HDRS}
)

my_add_library ( WrapIO)
