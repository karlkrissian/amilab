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
  ${AMILAB_SOURCE_DIR}/Filtrage
  ${AMILAB_SOURCE_DIR}/Vaisseaux
  ${AMILAB_SOURCE_DIR}/Graphic
  ${AMILAB_SOURCE_DIR}/ImageTool
  ${AMILAB_SOURCE_DIR}/OpenGL
  ${AMILAB_SOURCE_DIR}/Graphic
  ${AMILAB_SOURCE_DIR}/wxParams
  ${AMILAB_SOURCE_DIR}/Voxels
  ${AMILAB_SOURCE_DIR}/Crest
  ${AMILAB_SOURCE_DIR}/Graph
  ${AMILAB_SOURCE_DIR}/AMILab
  ${AMILAB_SOURCE_DIR}/Line
  ${AMILAB_SOURCE_DIR}/myVTK4
  ${AMILAB_SOURCE_DIR}/SplineThevenaz
  ${AMILAB_SOURCE_DIR}/Contours
  ${AMILAB_SOURCE_DIR}/Language
# still needed for now

#  ${AMILAB_SOURCE_DIR}/libamiFluid
#  ${AMILAB_SOURCE_DIR}/libamiFluid/opticflow/
#  ${AMILAB_SOURCE_DIR}/libamiFluid/opticflow/version_inversa
#  ${AMILAB_SOURCE_DIR}/JavierHornSchunck
  ${OPTICFLOW_INCLUDE_DIR}
  ${OPTICFLOW_INCLUDE_DIR}/OpticalFlow
  ${OPTICFLOW_INCLUDE_DIR}/OpticalFlow/src
  ${AMILAB_SOURCE_DIR}
  ${AMIFLUID_INCLUDE_DIR}
  ${PTHREADS_INCLUDE_DIR}
  ${Boost_INCLUDE_DIR}
  )

INCLUDE( ${VTK_USE_FILE} )
INCLUDE(${wxWidgets_USE_FILE})

SET(AMILab_SRCS
    AnisoGaussSeidel.cpp
    Chamfer.cpp
    CircleIntegration.cpp
    ConnectLines.cpp
    Curvatures.cpp
    EDPmorpho.cpp
    Eigen3D.cpp
    EigenDecomp.cpp
    FluidProject.cpp
    Func_ReadCTALine.cpp
    GenRead.cpp
    HessianMatrix.cpp
    InterpolateTransform.cpp
    LevelSetsCURVES.cpp
    LineCC.cpp
    LineRecons.cpp
    NormalSmoothField.cpp
    PositiveArea.cpp
    PropagationDistance.cpp
    ReSlice.cpp
    ResampleLines.cpp
    Resize.cpp
    Rudin.cpp
    SNR.cpp
    SRAD.cpp
    Skeleton2lines.cpp
    SmoothLines.cpp
    SmoothLinesToSplines.cpp
    StructureTensor.cpp
    Thinning.cpp
    VectorImage2StructuredGrid.cpp
    Weickert.cpp
    fonctions.cpp
    func_globalstats.cpp
    func_imagebasictools.cpp
    func_isoline.cpp
    func_shortestpath.cpp
    localstats.cpp
    paramlist.cpp
    vtkwrap.cpp
    wrapAMIFluid.cpp
    wrapFilters.cpp
    wrapVTK.cpp
    wrapWII.cpp
    wrap_StructureTensor.cpp
    wrapfunctions.cpp
    xmtext.cpp
)



my_add_library ( AMILab)
