# Create a library called "Hello" which includes the source file "hello.cxx".
# The extension is already found.  Any number of sources could be listed here.

# Make sure the compiler can find include files from our Hello library.

cmake_minimum_required(VERSION 2.4)

project (wxParams)

FIND_PACKAGE(wxWidgets COMPONENTS adv core base  )
FIND_PACKAGE( Boost 1.34.1 COMPONENTS date_time filesystem iostreams )


INCLUDE(${wxWidgets_USE_FILE})

include_directories (
  ${Boost_INCLUDE_DIR}
)

add_subdirectory (src)



FILE(GLOB files "${CMAKE_CURRENT_SOURCE_DIR}/src/*.h" "${CMAKE_CURRENT_SOURCE_DIR}/src/*.hpp")
INSTALL(FILES ${files} DESTINATION include/wxParams )





