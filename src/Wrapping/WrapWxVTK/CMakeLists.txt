# Create a library called "Hello" which includes the source file "hello.cxx".
# The extension is already found.  Any number of sources could be listed here.


# Make sure the compiler can find include files from our Hello library.
include_directories (
  ${AMILAB_SOURCE_DIR}/AMILab
  ${AMILAB_SOURCE_DIR}/Graphic/include
  ${AMILAB_SOURCE_DIR}/Graphic/wxVTK/
  ${AMILAB_SOURCE_DIR}/Graphic/wxVTKSamples/
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${AMILab_BINARY_DIR}/Wrapping/WrapVTK/${AMI_VTK_VERSION}/Generated
  ${AMILAB_SOURCE_DIR}/Wrapping/WrapWxWidgets/${AMI_WXWIDGETS_VERSION}
  ${AMILab_BINARY_DIR}/Wrapping/WrapWxWidgets/${AMI_WXWIDGETS_VERSION}/Generated
)

INCLUDE( ${VTK_USE_FILE} )
INCLUDE( ${wxWidgets_USE_FILE})

SET(  WrapWxVTK_SRCS
  wrap_wxVTKRenderWindowInteractor.cpp
  wrapWxVTK.cpp
)

SET(WrapWxVTK_HDRS
  wrap_wxVTKRenderWindowInteractor.h
  wrapWxVTK.h
)

SET(WrapWxVTK_SRCS
     ${WrapWxVTK_SRCS}
     ${WrapWxVTK_HDRS}
)

my_add_library ( WrapWxVTK)

IF(Need_Find_GTK)

  # this for GTK3
#   # Use the package PkgConfig to detect GTK+ headers/library files
#   FIND_PACKAGE(PkgConfig REQUIRED)
#   PKG_CHECK_MODULES(GTK3 REQUIRED gtk+-3.0)
#   # Setup CMake to use GTK+, tell the compiler where to look for headers
#   # and to the linker where to look for libraries
#   MESSAGE("GTK3_INCLUDE_DIRS=${GTK3_INCLUDE_DIRS}")
#   INCLUDE_DIRECTORIES(${GTK3_INCLUDE_DIRS})
#   LINK_DIRECTORIES(${GTK3_LIBRARY_DIRS})
#   # Add other flags to the compiler
#   ADD_DEFINITIONS(${GTK3_CFLAGS_OTHER})

  # this for GTK2
    FIND_PACKAGE(GTK2 REQUIRED gtk)
    IF(GTK2_FOUND)
      MESSAGE("Find GTK2!!!")
      INCLUDE_DIRECTORIES(${GTK2_INCLUDE_DIRS})
      TARGET_LINK_LIBRARIES(WrapWxVTK ${GTK2_LIBRARIES})
    ENDIF(GTK2_FOUND)
ENDIF(Need_Find_GTK)


add_dependencies ( WrapWxVTK WrapWxWidgets WrapVTK )
