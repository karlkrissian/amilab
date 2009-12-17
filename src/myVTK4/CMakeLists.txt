# Create a library called "Hello" which includes the source file "hello.cxx".
# The extension is already found.  Any number of sources could be listed here.

# Make sure the compiler can find include files from our Hello library.
include_directories (
    ${AMILAB_SOURCE_DIR}/Common
    ${AMILAB_SOURCE_DIR}/myVTK4
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
	DynTable.h
	PrincipalCurvatures.h
	vtkAnisoGaussSeidel.h
	vtkConvexHull.h
	vtkConvexHullConfigure.h
	vtkCorCTAConfigure.h
	vtkDecimate.h
	vtkDecimateConfigure.h
	vtkFluxDiffusionConfigure.h
	vtkImageDataBase.h
	vtkImageFastSignedChamfer.h
	vtkImageIsoContourDist.h
	vtkImagePropagateDist.h
	vtkImagePropagateDist2.h
	vtkImageTemplate.h
	vtkLevelSetFastMarching.h
	vtkLevelSets.h
	vtkLevelSetsConfigure.h
	vtkMINC.h
	vtkMINCImageAttributes.h
	vtkMINCImageReader.h
	vtkMinHeap.h
	vtkmyVTKConfigure.h
	vtkSkeleton2Lines.h
	vtkThinning.h
)

SET(myVTK4_SRCS
     ${myVTK4_SRCS}
     ${myVTK4_HDRS}
)

my_add_library ( myVTK4)
