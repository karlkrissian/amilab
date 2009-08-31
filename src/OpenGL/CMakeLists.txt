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
  ${AMILAB_SOURCE_DIR}/ImageTool
  ${AMILAB_SOURCE_DIR}/OpenGL
  ${AMILAB_SOURCE_DIR}/wxParams
  ${AMILAB_SOURCE_DIR}/Graphic
  ${AMILAB_SOURCE_DIR}/../Pixmaps
  ${AMILAB_SOURCE_DIR}/Voxels
  ${AMILAB_SOURCE_DIR}/Crest
  ${AMILAB_SOURCE_DIR}/Graph
  ${AMILAB_SOURCE_DIR}/Language
  ${GLEXT_INCLUDE_DIR}
  ${Boost_INCLUDE_DIR}
  )

INCLUDE( ${VTK_USE_FILE} )
INCLUDE(${wxWidgets_USE_FILE})

SET(OpenGL_SRCS
    GLparam.cpp
    Viewer3D.cpp
    Viewer3D_BackgroundParam.cpp
    Viewer3D_FogParam.cpp
    Viewer3D_LightingParam.cpp
    Viewer3D_LineParam.cpp
    Viewer3D_MaterialParam.cpp
    Viewer3D_PointParam.cpp
    Viewer3D_ProjParam.cpp
    Viewer3D_VectorsParam.cpp
    Viewer3D_ViewParam.cpp
    VolumeRender.cpp
    ami_wxGLCanvas.cpp
    isosurface.cpp 
    surface.cpp
)

my_add_library ( OpenGL)
