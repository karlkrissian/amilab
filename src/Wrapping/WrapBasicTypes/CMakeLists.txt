# Create a library called "Hello" which includes the source file "hello.cxx".
# The extension is already found.  Any number of sources could be listed here.

# Make sure the compiler can find include files from our Hello library.
include_directories (
  ${AMILAB_SOURCE_DIR}/Common
  ${AMILAB_SOURCE_DIR}/ImageTool
  ${AMILAB_SOURCE_DIR}/OpenGL
  ${AMILAB_SOURCE_DIR}/Graphic
  ${AMILAB_SOURCE_DIR}/Vaisseaux
  ${AMILAB_SOURCE_DIR}/Language
  ${Boost_INCLUDE_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${PTHREADS_INCLUDE_DIR}
)

INCLUDE( ${wxWidgets_USE_FILE})

SET(  WrapBasicTypes_SRCS
  wrap_varlist.cpp
  wrap_varvector.cpp
  wrap_File.cpp
  wrap_stdvector.cpp
)

SET(WrapBasicTypes_HDRS
  wrap_varlist.h
  wrap_varvector.h
  wrap_File.h
  wrap_stdvector.h
  wrap_stdvector.tpp
)

SET(WrapBasicTypes_SRCS
     ${WrapBasicTypes_SRCS}
     ${WrapBasicTypes_HDRS}
)

my_add_library ( WrapBasicTypes)
