# Create a library called "Hello" which includes the source file "hello.cxx".
# The extension is already found.  Any number of sources could be listed here.

# Make sure the compiler can find include files from our Hello library.
include_directories (
  ${AMILAB_SOURCE_DIR}/Graphic/include
  ${AMILAB_SOURCE_DIR}/Algorithms/include
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${PTHREADS_INCLUDE_DIR}
)

#INCLUDE( ${wxWidgets_USE_FILE})

SET(  WrapBasicTypes_SRCS
  wrap_varlist.cpp
  wrap_varvector.cpp
  wrap_File.cpp
  wrap_stdvector.cpp
)

SET(WrapBasicTypes_HDRS
  ../include/wrap_varlist.h
  ../include/wrap_varvector.h
  ../include/wrap_File.h
  ../include/wrap_stdvector.h
  ../include/wrap_stdvector.tpp
)

SET(WrapBasicTypes_SRCS
     ${WrapBasicTypes_SRCS}
     ${WrapBasicTypes_HDRS}
)

my_add_library ( WrapBasicTypes)
