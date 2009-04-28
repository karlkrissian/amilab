# The name of our project is "HELLO".  CMakeLists files in this project can
# refer to the root source directory of the project as ${HELLO_SOURCE_DIR} and
# to the root binary directory of the project as ${HELLO_BINARY_DIR}.
project (test_toolbar)

cmake_minimum_required(VERSION 2.4)

    if(COMMAND cmake_policy)
       cmake_policy(SET CMP0003 NEW)
     endif(COMMAND cmake_policy)


SET(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_ROOT}/Modules  ${CMAKE_CURRENT_SOURCE_DIR}/../../CMAKE )

FIND_PACKAGE(wxWidgets COMPONENTS html aui gl core base )
FIND_PACKAGE(wxParams )

INCLUDE(${wxWidgets_USE_FILE})

SET(test_toolbar_SRCS
  test_toolbar.cpp
)

include_directories(
  ${wxParams_INCLUDE_DIRS}
   ${test_toolbar_SOURCE_DIR}/../../Pixmaps
)

add_executable(test_toolbar WIN32  ${test_toolbar_SRCS})

# conflict between freetype and vtkfreetype
TARGET_LINK_LIBRARIES(test_toolbar
  ${wxParams_LIBRARY}
  ${wxWidgets_LIBRARIES}
)


if (WIN32)
TARGET_LINK_LIBRARIES(test_toolbar
  ole32
  oleaut32
  uuid
)
endif (WIN32)
