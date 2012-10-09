# Create a library called "Hello" which includes the source file "hello.cxx".
# The extension is already found.  Any number of sources could be listed here.
IF(WIN32)
  ADD_DEFINITIONS(-D_AFX_NO_AFXCMN_SUPPORT)
ENDIF(WIN32)

INCLUDE( ${wxWidgets_USE_FILE})



# Make sure the compiler can find include files from our Hello library.
include_directories (
  ${AMILAB_SOURCE_DIR}/CommonBase
  ${AMILAB_SOURCE_DIR}/Common/include
  ${AMILAB_SOURCE_DIR}/Graphic/include
  ${AMILAB_SOURCE_DIR}/Algorithms/include
  ${AMILAB_SOURCE_DIR}/Wrapping/include
  ${AMILAB_SOURCE_DIR}/Wrapping/WrapWxVTK
  ${AMILAB_SOURCE_DIR}/Wrapping/WrapWxWidgets/${AMI_WXWIDGETS_VERSION}
  ${AMILab_BINARY_DIR}/Wrapping/WrapWxWidgets/${AMI_WXWIDGETS_VERSION}/Generated
  ${AMILab_BINARY_DIR}/Wrapping/WrapAlgorithms/Generated
  ${AMILab_BINARY_DIR}/Wrapping/WrapLanguage/Generated
  ${AMILab_BINARY_DIR}/Wrapping/WrapExamples/Generated
  ${AMILab_BINARY_DIR}/Wrapping/WrapLanguage/Generated
  ${AMILab_BINARY_DIR}/Wrapping/WrapCommon/Generated
  ${AMILAB_SOURCE_DIR}/AMILab
  ${AMILAB_SOURCE_DIR}
  ${PTHREADS_INCLUDE_DIR}
  ${wxParams_INCLUDE_DIRS}
)

IF(AMI_WRAP_MICRONTRACKER)
  include_directories(
    ${AMILAB_SOURCE_DIR}/Wrapping/WrapMicronTracker/src
    ${AMILAB_SOURCE_DIR}/Wrapping/WrapMicronTracker/include
    ${AMILab_BINARY_DIR}/Wrapping/WrapMicronTracker/Generated
  )
ENDIF(AMI_WRAP_MICRONTRACKER)

IF(AMI_WRAP_ULTRASOUND)
  MESSAGE("\nInclude ultrasound... ${ULTRASOUND_DIR}\n")
  include_directories(
    ${AMILAB_SOURCE_DIR}/Wrapping/WrapUltrasound/src
    ${AMILAB_SOURCE_DIR}/Wrapping/WrapUltrasound/include
    ${AMILab_BINARY_DIR}/Wrapping/WrapUltrasound/Generated
    ${AMILAB_SOURCE_DIR}/Wrapping/WrapUltrasound
    ${ULTRASOUND_DIR}
  )
  #definiciones para dll
  ADD_DEFINITIONS(-D_AFXDLL)
  SET(CMAKE_MFC_FLAG 2)
  
  #microsoft visual params
  IF(MSVC) 
 	  set_target_properties( ${FUSION_BIN}
	  PROPERTIES LINK_FLAGS "/NODEFAULTLIB:msvcrtd.lib")

  ENDIF(MSVC)
ENDIF(AMI_WRAP_ULTRASOUND)
  

SET(  WrapImports_SRCS
  wrap_imports.cpp
)

SET(WrapImports_HDRS
	../include/wrap_imports.h
)

SET(WrapImports_SRCS
     ${WrapImports_SRCS}
     ${WrapImports_HDRS}
)

my_add_library ( WrapImports)

target_link_libraries(
 WrapImports
 WrapVTK
)

add_dependencies ( WrapImports 
    WrapWxWidgets 
    WrapAlgorithms 
    WrapLanguage
    WrapVTK
    WrapVTKTools
    )

IF(AMI_WRAP_MICRONTRACKER)
  add_dependencies( WrapImports WrapMicronTracker )
ENDIF(AMI_WRAP_MICRONTRACKER)

IF(AMI_WRAP_ULTRASOUND)
  add_dependencies( WrapImports WrapUltrasound )
ENDIF(AMI_WRAP_ULTRASOUND)