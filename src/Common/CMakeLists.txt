# Create a library called "Hello" which includes the source file "hello.cxx".
# The extension is already found.  Any number of sources could be listed here.

# Make sure the compiler can find include files from our Hello library.
include_directories (
  ${AMILAB_SOURCE_DIR}/CommonBase
  ${AMILAB_SOURCE_DIR}/Common/include
)

INCLUDE( ${wxWidgets_USE_FILE})
INCLUDE( ${VTK_USE_FILE} )
INCLUDE( ${USE_ITK_FILE} )

SET(Common_SRCS
  common_global_export.cpp
  Erreurs.cpp 
  ficparam.cpp
  message_dialog.cpp
  func_imagebasictools.cpp

  # coming from previous Math dir
  CurvaturasPrincipales.cpp
  Eigen.cpp
  FloatMatrix.cpp
  math1.cpp

  # from AMImage
  amimage.cpp

  # from Coordonnees
  coord_image.cpp  
  Point3D.cpp

  # from Crest
  Crest/CreeCrest.cpp
  Crest/Crest.cpp
  Crest/MultiCrest2.cpp
  Crest/MultiCrest.cpp

  # from Images
  amiImageExtent.cpp
  Images/inrimage.cpp
  Images/ImageLinearInterpolator.cpp
  #      inrimage_base.cpp
  #      inrimage_compressee.cpp
  #      inrimage_all.cpp

  # from Plugin
  wxPluginManager.cpp

  # ami_itk IO
  ami_itkRead.cpp
  ami_itkWrite.cpp

)

SET(Common_HDRS
	include/func_imagebasictools.h
	include/CallBackBase.h
  include/common_global_import.h
  include/vtk_common.h
  include/DefineClass.hpp
  include/ensemble.hpp
  include/Erreurs.hpp
  include/Erreurs.Main.hpp
  include/ficparam.hpp
  include/MinHeap.hpp
  include/TableauDyn.hpp
  include/Voisins27.hpp

  # coming from previous Math dir
  include/complex.hpp
  include/Coordonnees.hpp
  include/CurvaturasPrincipales.hpp
  include/Eigen.hpp
  include/FloatMatrix.hpp
  include/math1.hpp

  # from AMImage
  include/amimage.hpp

  # from Coordonnees
  include/coord_image.hpp
  include/coord_op.hpp
  include/Point3D.hpp

  # from Crest
  include/CreeCrest.hpp
  include/Crest.hpp
  include/MultiCrest.hpp
  include/MultiCrest2.hpp

  # from Images
  include/amiImageExtent.h
  include/inrimage.hpp
  include/ImageLinearInterpolator.h
  include/ImagePositionsBase.h
  include/ImagePositions.h
  include/ImagePositions.tpp
  include/InrImageIteratorBase.h
  include/InrImageIterator.h
  include/InrImageIterator.tpp
  include/InrImageConstIterator.h
  include/InrImageConstIterator.tpp

  # from Plugin
  include/wxPluginInterface.h
  include/wxPluginManager.h
  include/wxPluginBase.h

  # from ami_itk IO
  include/ami_itkRead.h
  include/ami_itkWrite.h
  include/wrapConversion.h
  include/wrapConversion.tpp

)

IF(WIN32)
  set_source_files_properties(${Common_SRCS} PROPERTIES COMPILE_FLAGS "-DCOMMON_EXPORTS")
ENDIF(WIN32)

SET (Common_SRCS
     ${Common_SRCS}
     ${Common_HDRS}
)



# own macro to add the library and print the source files
# using xxx_SRCS variable
#my_add_shared_library (Common)
my_add_library (Common)

IF( NOT DEFINED ITK_LIBRARIES )
  SET(ITK_LIBRARIES 
    ITKIO
    ITKAlgorithms
    itkvnl
    itkvnl_algo
  )
ENDIF( NOT DEFINED ITK_LIBRARIES )

target_link_libraries(Common 
  vtkIO 
  vtkImaging
  ${ITK_LIBRARIES}
  ${wxWidgets_LIBRARIES}
  ${Boost_LIBRARIES}
)

IF(AMI_USE_BZIP2)
  TARGET_LINK_LIBRARIES(Common ${BZIP2_LIBRARIES})
ENDIF(AMI_USE_BZIP2)


IF(CMAKE_SYSTEM_NAME STREQUAL "Linux" AND CMAKE_COMPILER_IS_GNUCC)
  SET_TARGET_PROPERTIES(Common PROPERTIES COMPILE_FLAGS -fPIC)
ENDIF(CMAKE_SYSTEM_NAME STREQUAL "Linux" AND CMAKE_COMPILER_IS_GNUCC)
