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

SET(Graphic_SRCS
    FenetreDessin.cpp
#    ParamBox.cpp
#    ParamPanel.cpp
    fonction2D.cpp
    gnuplot.cpp
#    palette.cpp
#    saveps.cpp
#    widget.cpp
#    wxParamTypes.cpp
#    wxColorParameter.cpp
    wxDrawingArea.cpp
    wxDrawingWindow.cpp
)

my_add_library (Graphic)
