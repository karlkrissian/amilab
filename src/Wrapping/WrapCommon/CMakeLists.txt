# Create a library called "Hello" which includes the source file "hello.cxx".
# The extension is already found.  Any number of sources could be listed here.

# Make sure the compiler can find include files from our Hello library.
include_directories (
  ${AMILAB_SOURCE_DIR}/Common/include
  ${AMILAB_SOURCE_DIR}/Graphic/include
  ${AMILAB_SOURCE_DIR}/Algorithms/include
  ${Boost_INCLUDE_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}
)

INCLUDE( ${wxWidgets_USE_FILE})

SET(  WrapCommon_SRCS
  wrapfunctions.cpp
#  wrapfunctions_draw.cpp
  wrapfunction_class.cpp
)

SET(WrapCommon_HDRS
#	wrapfunctions_draw.h
  ../include/wrapfunctions.hpp
  ../include/wrapfunctions.tpp
  ../include/wrapfunction_class.h
)

SET(WrapCommon_SRCS
     ${WrapCommon_SRCS}
     ${WrapCommon_HDRS}
)

my_add_library ( WrapCommon)
