# Create a library called "Hello" which includes the source file "hello.cxx".
# The extension is already found.  Any number of sources could be listed here.

# Make sure the compiler can find include files from our Hello library.

INCLUDE( ${USE_VTK_FILE} )

include_directories ( 
  ${AMILAB_SOURCE_DIR}/Common 
  ${AMILAB_SOURCE_DIR}/Math 
  ${AMILAB_SOURCE_DIR}/Images 
  ${AMILAB_SOURCE_DIR}/AMImage 
  ${AMILAB_SOURCE_DIR}/Zinrimage 
  ${AMILAB_SOURCE_DIR}/Coordonnees)


SET(Coordinates_SRCS
  coord_image.cpp  Point3D.cpp
)

my_add_library (Coordinates)
