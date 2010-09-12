# Create a library called "Hello" which includes the source file "hello.cxx".
# The extension is already found.  Any number of sources could be listed here.

MESSAGE("***** Boost_INCLUDE_DIR=${Boost_INCLUDE_DIR}")

# Make sure the compiler can find include files from our Hello library.
include_directories (
  ${AMILAB_SOURCE_DIR}/Common
  ${AMILAB_SOURCE_DIR}/AMILab
  ${AMILAB_SOURCE_DIR}/Language
  ${AMILAB_SOURCE_DIR}/Graphic/include
  ${AMILAB_SOURCE_DIR}/wxParams
  ${AMILAB_SOURCE_DIR}/myVTK4
  ${AMILAB_SOURCE_DIR}/Algorithms/include
  ${AMILAB_SOURCE_DIR}/Wrapping/WrapSurface
  ${Boost_INCLUDE_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}
)

INCLUDE( ${VTK_USE_FILE} )

INCLUDE( ${wxWidgets_USE_FILE})

SET(  WrapVTK_SRCS
  vtkwrap.cpp
  wrapVTK.cpp
)

SET(WrapVTK_HDRS
	vtkwrap.h
	wrapVTK.h
)

SET(WrapVTK_SRCS
     ${WrapVTK_SRCS}
     ${WrapVTK_HDRS}
)

my_add_library ( WrapVTK)
