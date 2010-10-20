# Create a library called "Hello" which includes the source file "hello.cxx".
# The extension is already found.  Any number of sources could be listed here.

# Make sure the compiler can find include files from our Hello library.
include_directories (
    ${AMILAB_SOURCE_DIR}/Common/include
    ${AMILAB_SOURCE_DIR}/Algorithms/include
    ${Boost_INCLUDE_DIR}
  )
INCLUDE( ${VTK_USE_FILE} )


SET(myVTK4_SRCS
    PrincipalCurvatures.cxx
    vtkAnisoGaussSeidel.cxx
    vtkConvexHull.cxx
    vtkDecimate.cxx
    vtkImageFastSignedChamfer.cxx
    vtkImageIsoContourDist.cxx
    vtkImagePropagateDist.cxx
    vtkImagePropagateDist2.cxx
    vtkLevelSetFastMarching.cxx
    vtkLevelSets.cxx
    vtkMINCImageAttributes.cxx
    vtkMINCImageReader.cxx
    vtkSkeleton2Lines.cxx
)

SET(myVTK4_HDRS
  ../include/DynTable.h
  ../include/PrincipalCurvatures.h
  ../include/vtkAnisoGaussSeidel.h
  ../include/vtkConvexHull.h
  ../include/vtkConvexHullConfigure.h
  ../include/vtkCorCTAConfigure.h
  ../include/vtkDecimate.h
  ../include/vtkDecimateConfigure.h
  ../include/vtkFluxDiffusionConfigure.h
  ../include/vtkImageDataBase.h
  ../include/vtkImageFastSignedChamfer.h
  ../include/vtkImageIsoContourDist.h
  ../include/vtkImagePropagateDist.h
  ../include/vtkImagePropagateDist2.h
  ../include/vtkImageTemplate.h
  ../include/vtkLevelSetFastMarching.h
  ../include/vtkLevelSets.h
  ../include/vtkLevelSetsConfigure.h
  ../include/vtkMINC.h
  ../include/vtkMINCImageAttributes.h
  ../include/vtkMINCImageReader.h
  ../include/vtkMinHeap.h
  ../include/vtkmyVTKConfigure.h
  ../include/vtkSkeleton2Lines.h
  ../include/vtkThinning.h
)

SET(myVTK4_SRCS
     ${myVTK4_SRCS}
     ${myVTK4_HDRS}
)

my_add_library ( myVTK4)
