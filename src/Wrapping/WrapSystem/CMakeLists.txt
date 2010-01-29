# Create a library called "Hello" which includes the source file "hello.cxx".
# The extension is already found.  Any number of sources could be listed here.

# Make sure the compiler can find include files from our Hello library.
include_directories (
  ${Boost_INCLUDE_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${PTHREADS_INCLUDE_DIR}
)

INCLUDE( ${wxWidgets_USE_FILE})

SET(  WrapSystem_SRCS
  wrapSystem.cpp
)

SET(WrapSystem_HDRS
	wrapSystem.h
)

SET(WrapSystem_SRCS
     ${WrapSystem_SRCS}
     ${WrapSystem_HDRS}
)

my_add_library ( WrapSystem)
