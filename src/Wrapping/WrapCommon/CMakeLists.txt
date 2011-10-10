# Create a library called "Hello" which includes the source file "hello.cxx".
# The extension is already found.  Any number of sources could be listed here.

SET(CURRENT_LIB WrapCommon)
#SET(WrapCommon_TYPE SHARED) 
SET(WrapCommon_TYPE STATIC) 

CONFIGURE_FILE(
    ${CMAKE_SOURCE_DIR}/libConfigure.h.in
    ${CMAKE_BINARY_DIR}/${CURRENT_LIB}Configure.h)

# Make sure the compiler can find include files from our Hello library.
include_directories (
  ${AMILAB_SOURCE_DIR}/CommonBase
  ${AMILAB_SOURCE_DIR}/Common/include
#  ${AMILAB_SOURCE_DIR}/Graphic/include
#  ${AMILAB_SOURCE_DIR}/Algorithms/include
  ${Boost_INCLUDE_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_BINARY_DIR}
)

INCLUDE( ${wxWidgets_USE_FILE})
#INCLUDE( ${VTK_USE_FILE} )
#INCLUDE( ${USE_ITK_FILE} )

SET(  WrapCommon_SRCS
  wrapfunctions.cpp
#  wrapfunctions_draw.cpp
  wrapfunction_class.cpp
  wrap_ImageViewerBase.cpp  
)

SET(WrapCommon_HDRS
#	wrapfunctions_draw.h
  ${CMAKE_BINARY_DIR}/${CURRENT_LIB}Configure.h
  ../include/wrapfunctions.hpp
  ../include/wrapfunctions.tpp
  ../include/wrapfunction_class.h
  ../include/wrap_ImageViewerBase.h
)

SET(WrapCommon_SRCS
     ${WrapCommon_SRCS}
     ${WrapCommon_HDRS}
)

ADD_LIBRARY(${CURRENT_LIB} ${${CURRENT_LIB}_TYPE}  ${${CURRENT_LIB}_SRCS})

# recursive dependencies
#target_link_libraries(WrapCommon 
#  CommonBase
#  Common
#  LanguageBase
#  Language
#)

IF(CMAKE_SYSTEM_NAME STREQUAL "Linux" AND CMAKE_COMPILER_IS_GNUCC)
  SET_TARGET_PROPERTIES(${CURRENT_LIB} PROPERTIES COMPILE_FLAGS -fPIC)
ENDIF(CMAKE_SYSTEM_NAME STREQUAL "Linux" AND CMAKE_COMPILER_IS_GNUCC)
