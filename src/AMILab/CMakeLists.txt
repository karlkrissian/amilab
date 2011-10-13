# Create a library called "Hello" which includes the source file "hello.cxx".
# The extension is already found.  Any number of sources could be listed here.


# Make sure the compiler can find include files from our Hello library.
include_directories (
  ${AMILAB_SOURCE_DIR}/CommonBase
  ${AMILAB_SOURCE_DIR}/Common/include
  ${AMILAB_SOURCE_DIR}/Graphic/include
  ${AMILAB_SOURCE_DIR}/wxParams
  ${AMILAB_SOURCE_DIR}/AMILab
  ${AMILAB_SOURCE_DIR}/LanguageBase
  ${AMILAB_SOURCE_DIR}/Language
  ${AMILAB_SOURCE_DIR}/Algorithms/include
  ${AMILAB_SOURCE_DIR}
  ${AMIFLUID_INCLUDE_DIR}
  ${PTHREADS_INCLUDE_DIR}
  ${wxParams_INCLUDE_DIRS}
  ${OPTICFLOW_INCLUDE_DIR}/OpticalFlow
  ${OPTICFLOW_INCLUDE_DIR}/OpticalFlow/src
)


INCLUDE( ${VTK_USE_FILE} )
INCLUDE(${wxWidgets_USE_FILE})

SET(AMILab_SRCS
    amilab_global_export.cpp
    Chamfer.cpp
    CircleIntegration.cpp
    ConnectLines.cpp
    ContinuousMorphology.cpp
    Eigen3D.cpp
    EigenDecomp.cpp
    FluidProject.cpp
    Func_ReadCTALine.cpp
    GenRead.cpp
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
    Thinning.cpp
    VectorImage2StructuredGrid.cpp
    Weickert.cpp
    fonctions.cpp
    func_globalstats.cpp
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
    amilab_global_import.h
    Chamfer.h
      ContinuousMorphology.h
    EigenDecomp.h
    FluidProject.h
    fonctions.h
    func_globalstats.h
    Func_ReadCTALine.h
    InterpolateTransform.h
    LevelSetsCURVES.h
    LineCC.h
    LineRecons.h
    messages.h
    myscan.h
    Rudin.h
    token_list.h
    VectorImage2StructuredGrid.h
    dif_param.hpp
    DirPrincipales.hpp
    FastVector.hpp
    func_isoline.hpp
    Resize.hpp
    xmtext.hpp
)

IF(WIN32)
  set_source_files_properties(${AMILab_SRCS} PROPERTIES COMPILE_FLAGS "-DAMILab_EXPORTS")
ENDIF(WIN32)

SET (AMILab_SRCS
     ${AMILab_SRCS}
     ${AMILab_HDRS}
)

my_add_library ( AMILab)

target_link_libraries(AMILab
  Common
  Algorithms
)
