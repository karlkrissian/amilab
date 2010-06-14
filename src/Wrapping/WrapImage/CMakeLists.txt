# Create a library called "Hello" which includes the source file "hello.cxx".
# The extension is already found.  Any number of sources could be listed here.

# Make sure the compiler can find include files from our Hello library.
include_directories (
  ${AMILAB_SOURCE_DIR}
  ${AMILAB_SOURCE_DIR}/Images
  ${Boost_INCLUDE_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${PTHREADS_INCLUDE_DIR}
)

INCLUDE( ${wxWidgets_USE_FILE})

SET(  WrapImage_SRCS
  wrap_ImageExtent.cpp
)

SET(WrapImage_HDRS
  wrap_ImageExtent.h
)

SET(WrapImage_SRCS
     ${WrapImage_SRCS}
     ${WrapImage_HDRS}
)

my_add_library ( WrapImage)
