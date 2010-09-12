# Create a library called "Hello" which includes the source file "hello.cxx".
# The extension is already found.  Any number of sources could be listed here.

# Make sure the compiler can find include files from our Hello library.
include_directories (
  ${AMILAB_SOURCE_DIR}/Common
  ${AMILAB_SOURCE_DIR}/Images
  ${AMILAB_SOURCE_DIR}/ImageTool
  ${AMILAB_SOURCE_DIR}/OpenGL
  ${AMILAB_SOURCE_DIR}/Graphic
  ${AMILAB_SOURCE_DIR}/Crest
  ${AMILAB_SOURCE_DIR}/Coordonnees
  ${AMILAB_SOURCE_DIR}/Vaisseaux
  ${AMILAB_SOURCE_DIR}/ImageTool
  ${AMILAB_SOURCE_DIR}/Crest
  ${AMILAB_SOURCE_DIR}/Vaisseaux
  ${Boost_INCLUDE_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${PTHREADS_INCLUDE_DIR}
)

INCLUDE( ${wxWidgets_USE_FILE})

SET(  WrapCommon_SRCS
  wrapfunctions.cpp
#  wrapfunctions_draw.cpp
  wrapfunction_class.cpp
)

SET(WrapCommon_HDRS
#	wrapfunctions_draw.h
  wrapfunctions.hpp
  wrapfunctions.tpp
  wrapfunction_class.h
)

SET(WrapCommon_SRCS
     ${WrapCommon_SRCS}
     ${WrapCommon_HDRS}
)

my_add_library ( WrapCommon)
