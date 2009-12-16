# Create a library called "Hello" which includes the source file "hello.cxx".
# The extension is already found.  Any number of sources could be listed here.

# Make sure the compiler can find include files from our Hello library.
include_directories (
  ${AMILAB_SOURCE_DIR}/Common
  ${AMILAB_SOURCE_DIR}/Zinrimage
  ${AMILAB_SOURCE_DIR}/Images
  ${AMILAB_SOURCE_DIR}/Math
  ${AMILAB_SOURCE_DIR}/AMImage
  ${AMILAB_SOURCE_DIR}/Coordonnees
  ${AMILAB_SOURCE_DIR}/Graphic
  ${AMILAB_SOURCE_DIR}/OpenGL
  ${AMILAB_SOURCE_DIR}/Graphic
  ${AMILAB_SOURCE_DIR}/wxParams
  ${AMILAB_SOURCE_DIR}/../Pixmaps
  )

INCLUDE(${wxWidgets_USE_FILE})


SET(Graphic_HDRS
    FenetreDessin.hpp
    fonction2D.hpp
    gnuplot.hpp
    wxDrawingArea.h
    wxDrawingWindow.h
    dw_Curve.h
    dw_Point2D.h
)

SET(Graphic_SRCS
    FenetreDessin.cpp
    fonction2D.cpp
    gnuplot.cpp
    wxDrawingArea.cpp
    wxDrawingWindow.cpp
)

SET(Graphic_SRCS
  ${Graphic_SRCS}
  ${Graphic_HDRS}
)

my_add_library (Graphic)
