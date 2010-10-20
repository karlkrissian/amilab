# Create a library called "Hello" which includes the source file "hello.cxx".
# The extension is already found.  Any number of sources could be listed here.

# Make sure the compiler can find include files from our Hello library.
include_directories (
  ${AMILAB_SOURCE_DIR}
  ${AMILAB_SOURCE_DIR}/AMILab
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
  ${AMILAB_SOURCE_DIR}/wxCode/wxTreeListCtrl
  ${AMILAB_SOURCE_DIR}/Language
  )

INCLUDE(${wxWidgets_USE_FILE})


SET(Graphic_HDRS
    FenetreDessin.hpp
    fonction2D.hpp
    gnuplot.hpp
    wxDrawingArea.h
    wxDrawingWindow.h
    dwControlPoint.h
    dwCurve.h
    dwControlledCurve.h
    dwPoint2D.h
    LinearColorMap.h
    wxDragAndDrop.h
)

SET(Graphic_SRCS
    FenetreDessin.cpp
    fonction2D.cpp
    gnuplot.cpp
    wxDrawingArea.cpp
    wxDrawingWindow.cpp
    LinearColorMap.cpp
    dwControlledCurve.cpp
    wxDragAndDrop.cpp
)

SET(Graphic_SRCS
  ${Graphic_SRCS}
  ${Graphic_HDRS}
)

my_add_library (Graphic)
