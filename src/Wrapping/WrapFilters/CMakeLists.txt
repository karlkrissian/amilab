# Create a library called "Hello" which includes the source file "hello.cxx".
# The extension is already found.  Any number of sources could be listed here.

MESSAGE("***** Boost_INCLUDE_DIR=${Boost_INCLUDE_DIR}")

# Make sure the compiler can find include files from our Hello library.
include_directories (
  ${wxParams_INCLUDE_DIRS}
  ${AMILAB_SOURCE_DIR}/CommonBase
  ${AMILAB_SOURCE_DIR}/Common/include
  ${AMILAB_SOURCE_DIR}/AMILab
  ${AMILAB_SOURCE_DIR}/LanguageBase
  ${AMILAB_SOURCE_DIR}/Language
  ${AMILAB_SOURCE_DIR}/Graphic/include
  ${AMILAB_SOURCE_DIR}/wxParams
  ${AMILAB_SOURCE_DIR}/Algorithms/include
  ${AMILAB_SOURCE_DIR}/Wrapping/include
  ${AMILAB_SOURCE_DIR}
  ${Boost_INCLUDE_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${PTHREADS_INCLUDE_DIR}
)

IF(AMI_USE_FASTNLMEANS)
  MESSAGE("including NewNLMeans_INCLUDE_DIRS=${NewNLMeans_INCLUDE_DIRS}")
  include_directories (
    ${NewNLMeans_INCLUDE_DIRS}
  )
ENDIF(AMI_USE_FASTNLMEANS)

INCLUDE( ${USE_ITK_FILE} )
INCLUDE( ${VTK_USE_FILE} )
INCLUDE( ${wxWidgets_USE_FILE})

SET(  WrapFilters_SRCS
  wrapFilters.cpp
  wrapAlgorithmsBasic.cpp
  wrapComputePV.cpp
  wrap_StructureTensor.cpp
  wrap_NLmeans.cpp
  Wrap_NewNLMeans.cpp
  wrap_DirSum.cpp
  wrap_ImTranslate.cpp
  wrap_AddSubImage.cpp
  wrap_MaxSubImage.cpp
  LeastSquares.cpp
  wrap_ImageAddScalar.cpp
  wrap_ImageCos.cpp
  wrapBasicEdgeDetection.cpp
  wrapGenerateRamp.cpp
  wrap_ContinuousMorphology.cpp
#   wrap_TestClass.cpp
   wrap_TemplateClass_int_.cpp
#   wrap_ClassBase1.cpp
#   wrap_ClassBase2.cpp
#   wrap_ClassBase3.cpp
)

SET(WrapFilters_HDRS
  ../include/LeastSquares.h
  ../include/wrapAlgorithmsBasic.h
  ../include/wrapComputePV.h
  ../include/wrapFilters.h
  ../include/wrap_AddSubImage.h
  ../include/wrap_DirSum.h
  ../include/wrap_ImTranslate.h
  ../include/wrap_MaxSubImage.h
  ../include/Wrap_NewNLMeans.h
  ../include/wrap_NLmeans.h
  ../include/wrap_StructureTensor.h
  ../include/wrap_ImageAddScalar.h
  ../include/wrap_ImageCos.h
  ../include/wrapBasicEdgeDetection.h
  ../include/wrapGenerateRamp.h
  ../include/wrap_ContinuousMorphology.h
#   ../include/wrap_TestClass.h
   ../include/wrap_TemplateClass_int_.h
#   ../include/wrap_ClassBase1.h
#   ../include/wrap_ClassBase2.h
#   ../include/wrap_ClassBase3.h
)

SET(WrapFilters_SRCS
     ${WrapFilters_SRCS}
     ${WrapFilters_HDRS}
)

my_add_library ( WrapFilters)

#
#add_dependencies ( WrapFilters WrapWxWidgets )
#
target_link_libraries(WrapFilters
  Common
  WrapCommon
  ${Boost_LIBRARIES}
)
