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
  ${AMILAB_SOURCE_DIR}/Filtering
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
  ${AMILAB_SOURCE_DIR}/Algorithms/Basic
  ${AMILAB_SOURCE_DIR}/Algorithms/Graph
  ${AMILAB_SOURCE_DIR}/Algorithms/Denoising
  ${OPTICFLOW_INCLUDE_DIR}
  ${OPTICFLOW_INCLUDE_DIR}/OpticalFlow
  ${OPTICFLOW_INCLUDE_DIR}/OpticalFlow/src
  ${AMILAB_SOURCE_DIR}/wxCode/wxTreeListCtrl
  ${AMILAB_SOURCE_DIR}
  ${AMIFLUID_INCLUDE_DIR}
  ${PTHREADS_INCLUDE_DIR}
  ${Boost_INCLUDE_DIR}
)


INCLUDE( ${VTK_USE_FILE} )
INCLUDE(${wxWidgets_USE_FILE})

SET(AMILab_SRCS
    Chamfer.cpp
    CircleIntegration.cpp
    ConnectLines.cpp
    Curvatures.cpp
//    EDPmorpho.cpp #To remove.
    ContinuousMorphology.cpp
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
#    func_shortestpath.cpp
#    localstats.cpp
#    vtkwrap.cpp
#    wrapAMIFluid.cpp
#    wrapFilters.cpp
#    wrapVTK.cpp
#    wrapWII.cpp
#    wrap_StructureTensor.cpp
    xmtext.cpp
)

SET (AMILab_HDRS
	Chamfer.h
//	EDPmorpho.h #to remove.
    ContinuousMorphology.h
	EigenDecomp.h
	FluidProject.h
	fonctions.h
	func_globalstats.h
	func_imagebasictools.h
	Func_ReadCTALine.h
	InterpolateTransform.h
	LevelSetsCURVES.h
	LineCC.h
	LineRecons.h
	messages.h
	myscan.h
	Rudin.h
	StructureTensor.h
	token_list.h
	VectorImage2StructuredGrid.h
	dif_param.hpp
	DirPrincipales.hpp
	FastVector.hpp
	func_isoline.hpp
	Resize.hpp
	xmtext.hpp
)

SET (AMILab_SRCS
     ${AMILab_SRCS}
     ${AMILab_HDRS}
)

my_add_library ( AMILab)
