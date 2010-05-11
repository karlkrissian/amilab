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
  ${AMILAB_SOURCE_DIR}/Vaisseaux
  ${AMILAB_SOURCE_DIR}/Graphic
  ${AMILAB_SOURCE_DIR}/Crest
  ${AMILAB_SOURCE_DIR}/Filtering
  ${AMILAB_SOURCE_DIR}/ImageTool
  ${AMILAB_SOURCE_DIR}/OpenGL
  ${AMILAB_SOURCE_DIR}
  ${AMILAB_SOURCE_DIR}/AMILab
  ${AMILAB_SOURCE_DIR}/Language
  ${wxParams_INCLUDE_DIRS}
  )

INCLUDE(${wxWidgets_USE_FILE})

SET(ImageTool_SRCS
    CompareImage.cpp
    DessinImage.cpp
    DessinImageBase.cpp
    ImageMIP.cpp
    Stereo.cpp
)

SET(ImageTool_HDRS
	DessinImageMenu.h
	Menu.h
	CompareImage.hpp
	DessinFonction2D.hpp
	DessinHisto.hpp
	DessinImage.hpp
	DessinImageBase.hpp
	DessinImageParam.hpp
	histo.hpp
	HistoPoints.hpp
	ImageDraw.hpp
	ImageMIP.hpp
	Stereo.hpp
)

SET(ImageTool_SRCS
     ${ImageTool_SRCS}
     ${ImageTool_HDRS}
)

my_add_library (ImageTool)
