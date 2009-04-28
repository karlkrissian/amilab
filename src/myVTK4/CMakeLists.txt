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

my_add_library ( myVTK4)
