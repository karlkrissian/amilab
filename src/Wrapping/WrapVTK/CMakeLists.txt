# Create a library called "Hello" which includes the source file "hello.cxx".
# The extension is already found.  Any number of sources could be listed here.

MESSAGE("***** Boost_INCLUDE_DIR=${Boost_INCLUDE_DIR}")

# Make sure the compiler can find include files from our Hello library.
include_directories (
  ${wxParams_INCLUDE_DIRS}
  ${AMILAB_SOURCE_DIR}/AMILab
  ${AMILAB_SOURCE_DIR}/Graphic/include
  ${AMILAB_SOURCE_DIR}/Graphic/wxVTK/
  ${AMILAB_SOURCE_DIR}/Graphic/wxVTKSamples/
  ${AMILAB_SOURCE_DIR}/wxParams
  ${AMILAB_SOURCE_DIR}/Algorithms/include
  ${AMILAB_SOURCE_DIR}/Wrapping/WrapWxWidgets/${AMI_WXWIDGETS_VERSION}
  ${AMILAB_SOURCE_DIR}/Wrapping/WrapWxWidgets/${AMI_WXWIDGETS_VERSION}/Generated
  ${AMILAB_SOURCE_DIR}/Wrapping/WrapWxVTK
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}/${AMI_VTK_VERSION}
)

INCLUDE( ${VTK_USE_FILE} )

INCLUDE( ${wxWidgets_USE_FILE})

file(GLOB vtk_HDRS  "${AMI_VTK_VERSION}/*.h"  )
file(GLOB vtk_SRCS  "${AMI_VTK_VERSION}/*.cpp")

MESSAGE("Wrapping VTK...")

IF(NUMBER_SOURCES_TO_PACKAGE EQUAL 1)
  SET(new_vtk_source_code_list ${vtk_SRCS})
ELSE(NUMBER_SOURCES_TO_PACKAGE EQUAL 1)
  SET(source_path "${AMILAB_SOURCE_DIR}/Wrapping/WrapVTK")
  GenerateSourcesWrapping (new_vtk_source_code_list source_path vtk_SRCS)
ENDIF(NUMBER_SOURCES_TO_PACKAGE EQUAL 1) 

SET(  WrapVTK_SRCS
  vtkwrap.cpp
  wrapVTK.cpp
)

SET(WrapVTK_HDRS
	../include/vtkwrap.h
	../include/wrapVTK.h
)

SET(WrapVTK_SRCS
     ${WrapVTK_SRCS}
     ${WrapVTK_HDRS}
     ${new_vtk_source_code_list}
     #${vtk_SRCS}
     ${vtk_HDRS}
)

my_add_library ( WrapVTK)
