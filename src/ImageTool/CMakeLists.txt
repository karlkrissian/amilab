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
  ${AMILAB_SOURCE_DIR}/wxCode/wxTreeListCtrl
  ${wxParams_INCLUDE_DIRS}
  )

INCLUDE(${wxWidgets_USE_FILE})

SET(ImageTool_SRCS
    CompareImage.cpp
    DessinImage.cpp
    DessinImageBase.cpp
    ImageMIP.cpp
    Stereo.cpp
    ImageDraw_PositionParam.cpp
    ImageDraw_IntensityParam.cpp
    ImageDraw_VectorsParam.cpp
    ImageDraw_IsoContourParam.cpp
    ImageDraw_ImageSurfaceParam.cpp
    ImageDraw_ColorsParam.cpp
    ImageDraw_Sections3DParam.cpp
    ImageDraw_VolRenParam.cpp
    ImageDraw_GLMIPParam.cpp
    ImageDraw_Voxels3DParam.cpp
    ImageDraw_CirclesParam.cpp
    ImageDraw_ZoomFactorParam.cpp
    ImageDraw_MIPParam.cpp
    ImageDraw_AnimationParam.cpp
    ImageDraw_VoxelSizeParam.cpp
    ImageDraw_InfoParam.cpp
    ImageDraw_CoupesXYParam.cpp
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
  ImageDraw_PositionParam.h
  ImageDraw_IntensityParam.h
  ImageDraw_VectorsParam.h
  ImageDraw_IsoContourParam.h
  ImageDraw_ImageSurfaceParam.h
  ImageDraw_ColorsParam.h
  ImageDraw_Sections3DParam.h
  ImageDraw_VolRenParam.h
  ImageDraw_GLMIPParam.h
  ImageDraw_Voxels3DParam.h
  ImageDraw_CirclesParam.h
  ImageDraw_ZoomFactorParam.h
  ImageDraw_MIPParam.h
  ImageDraw_AnimationParam.h
  ImageDraw_VoxelSizeParam.h
  ImageDraw_InfoParam.h
  ImageDraw_CoupesXYParam.h
)

SET(ImageTool_SRCS
     ${ImageTool_SRCS}
     ${ImageTool_HDRS}
)

my_add_library (ImageTool)
