# Create a library called "Hello" which includes the source file "hello.cxx".
# The extension is already found.  Any number of sources could be listed here.

INCLUDE( ${VTK_USE_FILE} )

# Make sure the compiler can find include files from our Hello library.

include_directories (
  ${AMILAB_SOURCE_DIR}/Common
  ${AMILAB_SOURCE_DIR}/Zinrimage
  ${AMILAB_SOURCE_DIR}/Images
  ${AMILAB_SOURCE_DIR}/Math
  ${AMILAB_SOURCE_DIR}/AMImage
  ${AMILAB_SOURCE_DIR}/Coordonnees
  ${AMILAB_SOURCE_DIR}/Vaisseaux
  ${AMILAB_SOURCE_DIR}/Graphic
  ${AMILAB_SOURCE_DIR}/Crest
  ${AMILAB_SOURCE_DIR}/Filtering
  ${AMILAB_SOURCE_DIR}/Contours
  ${Boost_INCLUDE_DIR}
  )


SET(Contours_SRCS
      CalculAireSection.cpp
      IsoContour2.cpp
      IsoContour2D.cpp
      IsoContour.cpp
      PointContour.cpp
)

SET(Contours_HDRS
	CalculAireSection.hpp
	IsoContour.hpp
	IsoContour2.hpp
	IsoContour2D.hpp
	PointContour.hpp
	PropagePoints.hpp
)

SET(Contours_SRCS
     ${Contours_SRCS}
     ${Contours_HDRS}
)

my_add_library (Contours)
