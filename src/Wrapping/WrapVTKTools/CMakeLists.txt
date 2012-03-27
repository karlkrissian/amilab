# Create a library called "Hello" which includes the source file "hello.cxx".
# The extension is already found.  Any number of sources could be listed here.

# MESSAGE("***** Boost_INCLUDE_DIR=${Boost_INCLUDE_DIR}")

# Make sure the compiler can find include files from our Hello library.
include_directories (
  ${wxParams_INCLUDE_DIRS}
  ${AMILAB_SOURCE_DIR}/AMILab
  ${AMILAB_SOURCE_DIR}/Graphic/include
  ${AMILAB_SOURCE_DIR}/Graphic/wxVTK/
  ${AMILAB_SOURCE_DIR}/Algorithms/include
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}/${AMI_VTK_VERSION}
  ${AMILab_BINARY_DIR}/Wrapping/WrapVTK/${AMI_VTK_VERSION}/Generated
)

INCLUDE( ${VTK_USE_FILE} )
INCLUDE( ${wxWidgets_USE_FILE})


SET(  WrapVTKTools_SRCS
  wrapVTKTools.cpp
  vtkwrap.cpp
)

SET(WrapVTKTools_HDRS
  ../include/vtkwrap.h
  ../include/wrapVTKTools.h
)

SET(WrapVTKTools_SRCS
    ${WrapVTKTools_SRCS}
    ${WrapVTKTools_HDRS}
)


my_add_library ( WrapVTKTools)


add_dependencies ( WrapVTKTools 
  WrapVTK )
