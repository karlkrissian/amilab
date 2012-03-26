# Create a library called "Hello" which includes the source file "hello.cxx".
# The extension is already found.  Any number of sources could be listed here.


# Make sure the compiler can find include files from our Hello library.
include_directories (
  ${AMILAB_SOURCE_DIR}/AMILab
  ${AMILAB_SOURCE_DIR}/Graphic/include
  ${AMILAB_SOURCE_DIR}/Graphic/wxVTK/
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${AMILab_BINARY_DIR}/Wrapping/WrapVTK/${AMI_VTK_VERSION}/Generated
  ${AMILAB_SOURCE_DIR}/Wrapping/WrapWxWidgets/${AMI_WXWIDGETS_VERSION}
  ${AMILab_BINARY_DIR}/Wrapping/WrapWxWidgets/${AMI_WXWIDGETS_VERSION}/Generated
)

INCLUDE( ${VTK_USE_FILE} )
INCLUDE( ${wxWidgets_USE_FILE})

SET(  WrapWxVTK_SRCS
  wrap_wxVTKRenderWindowInteractor.cpp
)

SET(WrapWxVTK_HDRS
  wrap_wxVTKRenderWindowInteractor.h
)

SET(WrapWxVTK_SRCS
     ${WrapWxVTK_SRCS}
     ${WrapWxVTK_HDRS}
)

my_add_library ( WrapWxVTK)

IF(Need_Find_GTK)
  FIND_PACKAGE(GTK2 REQUIRED gtk)
  IF(GTK2_FOUND)
    MESSAGE("Find GTK2!!!")
    INCLUDE_DIRECTORIES(${GTK2_INCLUDE_DIRS})
    TARGET_LINK_LIBRARIES(WrapWxVTK ${GTK2_LIBRARIES})
  ENDIF(GTK2_FOUND)
ENDIF(Need_Find_GTK)

add_dependencies ( WrapWxVTK WrapWxWidgets WrapVTK )