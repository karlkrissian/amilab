# Create a library called "Hello" which includes the source file "hello.cxx".
# The extension is already found.  Any number of sources could be listed here.

# Make sure the compiler can find include files from our Hello library.

INCLUDE( ${USE_VTK_FILE} )

include_directories ( 
  ${AMILAB_SOURCE_DIR}/Common 
)


SET(Coordinates_SRCS
)

SET(Coordinates_HDRS
)

SET(Coordinates_SRCS
     ${Coordinates_SRCS}
     ${Coordinates_HDRS}
)

my_add_library (Coordinates)
