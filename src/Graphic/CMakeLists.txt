# Create a library called "Hello" which includes the source file "hello.cxx".
# The extension is already found.  Any number of sources could be listed here.

# Make sure the compiler can find include files from our Hello library.
include_directories (
  ${AMILAB_SOURCE_DIR}/Common
  ${AMILAB_SOURCE_DIR}/Graphic/include
  ${AMILAB_SOURCE_DIR}/Algorithms/include
  ${AMILAB_SOURCE_DIR}/Graphic/include
  ${AMILAB_SOURCE_DIR}/../Pixmaps
  ${AMILAB_SOURCE_DIR}/AMILab
  ${AMILAB_SOURCE_DIR}/Language
  ${AMILAB_SOURCE_DIR}/wxCode/wxTreeListCtrl
  ${wxParams_INCLUDE_DIRS}
  ${AMILAB_SOURCE_DIR}
  ${GLEXT_INCLUDE_DIR}
  )


INCLUDE( ${VTK_USE_FILE} )

INCLUDE(${wxWidgets_USE_FILE})


SET(Graphic_HDRS
    include/FenetreDessin.hpp
    include/fonction2D.hpp
    include/gnuplot.hpp
    include/wxDrawingArea.h
    include/wxDrawingWindow.h
    include/dwControlPoint.h
    include/dwCurve.h
    include/dwControlledCurve.h
    include/dwPoint2D.h
    include/LinearColorMap.h
    include/Voxels.h

    # from ImageTool
    include/DessinImageMenu.h
    include/Menu.h
    include/CompareImage.hpp
    include/DessinFonction2D.hpp
    include/DessinHisto.hpp
    include/DessinImage.hpp
    include/DessinImageBase.hpp
    include/DessinImageParam.hpp
    include/histo.hpp
    include/HistoPoints.hpp
    include/ImageDraw.hpp
    include/ImageMIP.hpp
    include/Stereo.hpp
    include/ImageDraw_PositionParam.h
    include/ImageDraw_IntensityParam.h
    include/ImageDraw_VectorsParam.h
    include/ImageDraw_IsoContourParam.h
    include/ImageDraw_ImageSurfaceParam.h
    include/ImageDraw_ColorsParam.h
    include/ImageDraw_Sections3DParam.h
    include/ImageDraw_VolRenParam.h
    include/ImageDraw_GLMIPParam.h
    include/ImageDraw_Voxels3DParam.h
    include/ImageDraw_CirclesParam.h
    include/ImageDraw_ZoomFactorParam.h
    include/ImageDraw_MIPParam.h
    include/ImageDraw_AnimationParam.h
    include/ImageDraw_VoxelSizeParam.h
    include/ImageDraw_InfoParam.h
    include/ImageDraw_CoupesXYParam.h

    # from OpenGL
    include/Viewer3D_BackgroundParam.h
    include/Viewer3D_FogParam.h
    include/Viewer3D_LightingParam.h
    include/Viewer3D_LineParam.h
    include/Viewer3D_MaterialParam.h
    include/Viewer3D_PointParam.h
    include/Viewer3D_ProjParam.h
    include/Viewer3D_VectorsParam.h
    include/Viewer3D_ViewParam.h
    include/ami_wxGLCanvas.hpp
    include/GLparam.hpp
    include/isosurface.hpp
    include/surface.hpp
    include/TestGL.hpp
    include/Viewer3D.hpp
    include/VolumeRender.hpp

)

SET(Graphic_SRCS
    Common/FenetreDessin.cpp
    Common/fonction2D.cpp
    Common/gnuplot.cpp
    Common/wxDrawingArea.cpp
    Common/wxDrawingWindow.cpp
    Common/LinearColorMap.cpp
    Common/dwControlledCurve.cpp
    Common/Voxels.cpp

    # from ImageTool
    ImageTool/CompareImage.cpp
    ImageTool/DessinImage.cpp
    ImageTool/DessinImageBase.cpp
    ImageTool/ImageMIP.cpp
    ImageTool/Stereo.cpp
    ImageTool/ImageDraw_PositionParam.cpp
    ImageTool/ImageDraw_IntensityParam.cpp
    ImageTool/ImageDraw_VectorsParam.cpp
    ImageTool/ImageDraw_IsoContourParam.cpp
    ImageTool/ImageDraw_ImageSurfaceParam.cpp
    ImageTool/ImageDraw_ColorsParam.cpp
    ImageTool/ImageDraw_Sections3DParam.cpp
    ImageTool/ImageDraw_VolRenParam.cpp
    ImageTool/ImageDraw_GLMIPParam.cpp
    ImageTool/ImageDraw_Voxels3DParam.cpp
    ImageTool/ImageDraw_CirclesParam.cpp
    ImageTool/ImageDraw_ZoomFactorParam.cpp
    ImageTool/ImageDraw_MIPParam.cpp
    ImageTool/ImageDraw_AnimationParam.cpp
    ImageTool/ImageDraw_VoxelSizeParam.cpp
    ImageTool/ImageDraw_InfoParam.cpp
    ImageTool/ImageDraw_CoupesXYParam.cpp

    # from OpenGL
    OpenGL/GLparam.cpp
    OpenGL/Viewer3D.cpp
    OpenGL/Viewer3D_BackgroundParam.cpp
    OpenGL/Viewer3D_FogParam.cpp
    OpenGL/Viewer3D_LightingParam.cpp
    OpenGL/Viewer3D_LineParam.cpp
    OpenGL/Viewer3D_MaterialParam.cpp
    OpenGL/Viewer3D_PointParam.cpp
    OpenGL/Viewer3D_ProjParam.cpp
    OpenGL/Viewer3D_VectorsParam.cpp
    OpenGL/Viewer3D_ViewParam.cpp
    OpenGL/VolumeRender.cpp
    OpenGL/ami_wxGLCanvas.cpp
    OpenGL/isosurface.cpp 
    OpenGL/surface.cpp
)

SET(Graphic_SRCS
  ${Graphic_SRCS}
  ${Graphic_HDRS}
)

my_add_library (Graphic)
