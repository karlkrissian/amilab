# Create a library called "Hello" which includes the source file "hello.cxx".
# The extension is already found.  Any number of sources could be listed here.

# Make sure the compiler can find include files from our Hello library.

INCLUDE( ${USE_VTK_FILE} )

include_directories ( 
  ${AMILAB_SOURCE_DIR}/Common 
  ${AMILAB_SOURCE_DIR}/Images 
  ${AMILAB_SOURCE_DIR}/AMImage 
  ${AMILAB_SOURCE_DIR}/Coordonnees)


SET(Coordinates_SRCS
  coord_image.cpp  
  Point3D.cpp
)

SET(Coordinates_HDRS
	coord_image.hpp
	coord_op.hpp
	Point3D.hpp
)

SET(Coordinates_SRCS
     ${Coordinates_SRCS}
     ${Coordinates_HDRS}
)

my_add_library (Coordinates)
