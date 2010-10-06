# Create a library called "Hello" which includes the source file "hello.cxx".
# The extension is already found.  Any number of sources could be listed here.

MESSAGE("***** Boost_INCLUDE_DIR=${Boost_INCLUDE_DIR}")

# Make sure the compiler can find include files from our Hello library.
include_directories (
  ${AMILAB_SOURCE_DIR}/AMILab
  ${AMILAB_SOURCE_DIR}/Algorithms/include
  ${AMILAB_SOURCE_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}
)

INCLUDE( ${VTK_USE_FILE} )
INCLUDE( ${wxWidgets_USE_FILE})


SET(  WrapmyVTK_SRCS
  wrap_vtkLevelSets.cpp
)

SET(WrapmyVTK_HDRS
  ../include/wrap_vtkLevelSets.h
)

SET(WrapmyVTK_SRCS
     ${WrapmyVTK_SRCS}
     ${WrapmyVTK_HDRS}
)

my_add_library ( WrapmyVTK)
