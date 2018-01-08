# Create a library called "Hello" which includes the source file "hello.cxx".
# The extension is already found.  Any number of sources could be listed here.
#WRAP_MESSAGE("***** Boost_INCLUDE_DIR=${Boost_INCLUDE_DIR}")

# Make sure the compiler can find include files from our Hello library.
include_directories (
  ${wxParams_INCLUDE_DIRS}
  ${AMILAB_SOURCE_DIR}/CommonBase
  ${AMILAB_SOURCE_DIR}/Common/include
  ${AMILAB_SOURCE_DIR}/Graphic/include
  ${AMILAB_SOURCE_DIR}/Wrapping/include
  ${Boost_INCLUDE_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}/${AMI_ITK_VERSION}
  ${CMAKE_CURRENT_BINARY_DIR}/${AMI_ITK_VERSION}/Generated
  )

MESSAGE( "USE_ITK_FILE = ${USE_ITK_FILE}")
MESSAGE( "ITK_USE_FILE = ${ITK_USE_FILE}")
#INCLUDE( ${USE_ITK_FILE} )
INCLUDE( ${ITK_USE_FILE} )
INCLUDE( ${wxWidgets_USE_FILE})

#INCLUDE( ${USE_VTK_FILE})
#WRAP_MESSAGE( "USE_VTK_FILE = ${USE_VTK_FILE}")

OPTION(WrapITK_SHARED     "Compile WrapITK library as shared" OFF)

IF(AMI_ENABLE_WRAPPING AND AMI_WRAP_ITK)

  #------------------------------------------------------------
  # Initialization
  #------------------------------------------------------------

  INCLUDE(${AMILAB_SOURCE_DIR}/../CMAKE/amiWrapping.cmake)
  CreateDirectory( ${CMAKE_CURRENT_BINARY_DIR}/${AMI_ITK_VERSION})
  SET(GENERATED_DIR ${CMAKE_CURRENT_BINARY_DIR}/${AMI_ITK_VERSION}/Generated)
  CreateDirectory( ${GENERATED_DIR})
  SET(LIBNAME "itk")
  WRAP_INIT(" InsigthToolKit ${AMI_ITK_VERSION}")

  WRAP_MESSAGE("ITK_SOURCE_DIR=${ITK_SOURCE_DIR}")
  WRAP_MESSAGE("ITK_INCLUDE_DIRS=${ITK_INCLUDE_DIRS}")
  WRAP_MESSAGE("ITK_SOURCE_DIR=${ITK_SOURCE_DIR}")

  #------------------------------------------------------------
  # Creating XML file
  #------------------------------------------------------------

  MESSAGE("GCCXML_ITK_INCLUDES=${GCCXML_ITK_INCLUDES}")
  IF   (ITK_FOUND)
    WRAP_MESSAGE("GCCXML_ITK_INCLUDES=${GCCXML_ITK_INCLUDES}")
    IF   (ITK_INCLUDE_DIRS)
      FOREACH( inc ${ITK_INCLUDE_DIRS})
        SET( GCCXML_ITK_INCLUDES  -I${inc}  ${GCCXML_ITK_INCLUDES} )
        IF (inc MATCHES ".*Utilities$")
          SET(ITK_UTILITIES_PATH ${inc})
        ENDIF(inc MATCHES ".*Utilities$")
      ENDFOREACH(inc ${ITK_INCLUDE_DIRS})
      WRAP_MESSAGE("ITK_UTILITIES_PATH = ${ITK_UTILITIES_PATH}")
      # for unknown reasons I had to add those two directories
      IF (${ITK_VERSION_MAJOR} EQUAL "3")
        SET( GCCXML_ITK_INCLUDES ${GCCXML_ITK_INCLUDES} -I${ITK_UTILITIES_PATH}/vxl/vcl/iso/)
        SET( GCCXML_ITK_INCLUDES ${GCCXML_ITK_INCLUDES} -I${ITK_UTILITIES_PATH}/vxl/core/q/)
        SET( GCCXML_ITK_INCLUDES ${GCCXML_ITK_INCLUDES} -I${ITK_UTILITIES_PATH}/vxl/core/generic/)
      ELSE (${ITK_VERSION_MAJOR} EQUAL "3")
        FOREACH( inc ${ITKVNL_INCLUDE_DIRS})
          SET( GCCXML_ITK_INCLUDES ${GCCXML_ITK_INCLUDES} -I${inc})
        ENDFOREACH(inc ${ITKVNL_INCLUDE_DIRS})
          #/vnl/)
      ENDIF (${ITK_VERSION_MAJOR} EQUAL "3")
      WRAP_MESSAGE("** GCCXML_ITK_INCLUDES=${GCCXML_ITK_INCLUDES}")
      #SET( GCCXML_ITK_INCLUDES -I/home/karl/projects/Install/amilab/InsightToolkit-3.20.0/Utilities/vxl/vcl/generic/ ${GCCXML_ITK_INCLUDES} )
      #SET( GCCXML_ITK_INCLUDES -I/home/karl/projects/Install/amilab/InsightToolkit-3.20.0/Utilities/vxl/core/vnl/ ${GCCXML_ITK_INCLUDES} )
    ENDIF(ITK_INCLUDE_DIRS)
    WRAP_MESSAGE("GCCXML_ITK_INCLUDES=${GCCXML_ITK_INCLUDES}")
    WRAP_MESSAGE("ITK_REQUIRED_CXX_FLAGS=${ITK_REQUIRED_CXX_FLAGS}")
    IF   (ITK_REQUIRED_CXX_FLAGS)
       FOREACH( def ${ITK_REQUIRED_CXX_FLAGS})
         SET( GCCXML_ITK_DEFS  ${def}  ${GCCXML_ITK_DEFS} )
       ENDFOREACH(def ${ITK_REQUIRED_CXX_FLAGS})       
    ENDIF(ITK_REQUIRED_CXX_FLAGS)
    # Add Cable configuration for gccxml compilation
    # it is really needed ???
    SET(GCCXML_ITK_DEFS -DCABLE_CONFIGURATION -DITK_MANUAL_INSTANTIATION)
    WRAP_MESSAGE("GCCXML_ITK_DEFS=${GCCXML_ITK_DEFS}")
  ENDIF ( ITK_FOUND)

  MESSAGE("GCCXML_ITK_INCLUDES=${GCCXML_ITK_INCLUDES}")
  # Update GCCXML variables
  SET( GCCXML_INCLUDES ${GCCXML_INCLUDES}  ${GCCXML_ITK_INCLUDES})
  SET( GCCXML_DEFS     ${GCCXML_DEFS}      ${GCCXML_ITK_DEFS}    )

  SET(GCCXML_FLAGS "")
  IF(WIN32)
    SET(GCCXML_FLAGS ${GCCXML_FLAGS} -D_WIN32 -DWIN32 ) 
  ENDIF(WIN32)
  SET( GCCXML_DEFS     ${GCCXML_DEFS}      ${GCCXML_FLAGS}    )
  MESSAGE("GCCXML_DEFS=${GCCXML_DEFS}")

  SET(XML_OUTPUT "${GENERATED_DIR}/itk_includes.xml")
  SET(XML_INPUT  "${CMAKE_CURRENT_SOURCE_DIR}/itk_includes.h")
  
  SET(GCCXML_INCLUDES ${GCCXML_INCLUDES} "-I${AMILAB_SOURCE_DIR}/Wrapping/include")
  SET(GCCXML_INCLUDES ${GCCXML_INCLUDES} "-I${AMILAB_SOURCE_DIR}/Common/include")
  SET(GCCXML_INCLUDES ${GCCXML_INCLUDES} "-I${AMILAB_SOURCE_DIR}/CommonBase")
  SET(GCCXML_INCLUDES ${GCCXML_INCLUDES} "-I${CMAKE_CURRENT_SOURCE_DIR}")
  SET(GCCXML_INCLUDES ${GCCXML_INCLUDES} "-I${CMAKE_BINARY_DIR}")
  SET(GCCXML_INCLUDES ${GCCXML_INCLUDES} "-I${Boost_INCLUDE_DIR}")

  RUN_GCCXML( ${XML_INPUT} ${XML_OUTPUT})


  #------------------------------------------------------------
  # Setting up the Documentation information
  #------------------------------------------------------------

  IF(GENERATE_HTML_HELP)
    SET(CLASSES_URL_LIST "http://www.itk.org/")
    SET(HTML_DIR "${GENERATED_DIR}/html")
    CreateDirectory( ${HTML_DIR} )
  ENDIF(GENERATE_HTML_HELP)

  #------------------------------------------------------------
  # Generating the classes, functions, etc...  lists
  #------------------------------------------------------------

  SET(WRAPPING_DIR ${CMAKE_CURRENT_SOURCE_DIR})
  # Read list of classes to wrap
  READ_CLASSES(
    "${CMAKE_CURRENT_SOURCE_DIR}/classes.txt"
  ) 

  #------------------------------------------------------------
  # Generating and reading ancestors
  #------------------------------------------------------------

  # Read WrapCommon ancestors list
  SET( WRAPCOMMON_OUTDIR ${AMILab_BINARY_DIR}/Wrapping/WrapCommon/Generated)
  FILE(READ "${WRAPCOMMON_OUTDIR}/ancestors.txt" wrapcommon_ancestors_txt)
  STRING(REGEX REPLACE "[\r\n]" ";" wrapcommon_ancestors_list ${wrapcommon_ancestors_txt} )
  SET(AVAILABLE_EXTERNAL_CLASSES ${wrapcommon_ancestors_list})

  CREATE_ANCESTORS()

  FILE(READ "${ANCESTORS_FILE}" ancestors_txt)
  STRING(REGEX REPLACE "[\r\n]" ";" ancestors_list ${ancestors_txt} )

  #------------------------------------------------------------
  # Generating and reading ancestors
  #------------------------------------------------------------

  # Read itk ancestors list
#   SET( ITK_OUTDIR ${AMILAB_SOURCE_DIR}/Wrapping/WrapITK/${AMI_ITK_VERSION}/Generated)
# 
#   SET(ANCESTORS_FILE "${ITK_OUTDIR}/ancestors.txt")
#   SET(AMI_WRAPPER "${AMILAB_SOURCE_DIR}/../PythonWrap/parse_xml/parse_xml2.py")
# 
#   IF(GENERATE_HTML_HELP)
#     WRAP_MESSAGE("COMMAND: ${PYTHON_EXECUTABLE}  ${AMI_WRAPPER} ${XML_OUTPUT} --ancestors ${classes_list} --ancestors-file ${ANCESTORS_FILE} --generate-html --url ${CLASSES_URL_LIST} --outputhtmldir ${HTML_DIR} --templates --templatefile_dir "${AMILAB_SOURCE_DIR}/../PythonWrap/" -q")
#     EXECUTE_PROCESS(
#       COMMAND  ${PYTHON_EXECUTABLE}  ${AMI_WRAPPER} ${XML_OUTPUT} --ancestors ${classes_list} --ancestors-file ${ANCESTORS_FILE} --generate-html --url ${CLASSES_URL_LIST} --outputhtmldir ${HTML_DIR} --templates --templatefile_dir "${AMILAB_SOURCE_DIR}/../PythonWrap/" -q
#       OUTPUT_VARIABLE ancestors_result
#       ERROR_VARIABLE ancestors_error
#     )
#   ELSE(GENERATE_HTML_HELP)
#     WRAP_MESSAGE("COMMAND IS: ${PYTHON_EXECUTABLE}  ${AMI_WRAPPER} ${XML_OUTPUT} --ancestors ${classes_list} --templates --templatefile_dir "${AMILAB_SOURCE_DIR}/../PythonWrap/" --ancestors-file ${ANCESTORS_FILE} -q")
#     EXECUTE_PROCESS(
#       COMMAND  ${PYTHON_EXECUTABLE}  ${AMI_WRAPPER} ${XML_OUTPUT} --ancestors ${classes_list}  --templates --templatefile_dir "${AMILAB_SOURCE_DIR}/../PythonWrap/" --ancestors-file ${ANCESTORS_FILE} -q
#       OUTPUT_VARIABLE ancestors_result
#       ERROR_VARIABLE ancestors_error
#     )
#   ENDIF(GENERATE_HTML_HELP)
# 
#   #WRAP_MESSAGE(" ancestors_result = ${ancestors_result} ")
#   MESSAGE(" ancestors_result = ${ancestors_result} ")
#   WRAP_MESSAGE(" ancestors_error = ${ancestors_error} ")
# 
# 
#   FILE(READ "${ITK_OUTDIR}/ancestors.txt" ancestors_txt)
#   STRING(REGEX REPLACE "[\r\n]" ";" ancestors_list ${ancestors_txt} )

  #------------------------------------------------------------
  # Checking for existing and missing files
  #------------------------------------------------------------

  # Wrap all missing classes at once since it is now fast
  #CHECK_WRAPPED_FILES( "${ancestors_list}"       "MISSING_CLASSES")
  UPDATE_OUTPUT_LIST( "${ancestors_list}"  )

  #------------------------------------------------------------
  # Create the rule that wraps the code
  #------------------------------------------------------------

  SET(NO_METHOD_HELP true)

  WRAP_CODE()

#   WRAP_MESSAGE("OUTPUT_LIST=${OUTPUT_LIST}")
# 
#   #MESSAGE("Processing classes ${ancestors_list} and addwrap")
#   IF ((${NB_MISSING_CLASSES} GREATER 0) OR 
#       (NOT EXISTS ${GENERATED_DIR}/addwrap_itk.h) OR
#       (NOT EXISTS ${GENERATED_DIR}/addwrap_itk.cpp))
#     # Go for python wrapping
#     IF(GENERATE_HTML_HELP)
#       ADD_CUSTOM_COMMAND(
#         OUTPUT  ${OUTPUT_LIST} ${GENERATED_DIR}/addwrap_itk.h ${GENERATED_DIR}/addwrap_itk.cpp
#         COMMAND
#             ${PYTHON_EXECUTABLE}
#               ${AMI_WRAPPER} ${XML_OUTPUT}
#               --libname itk
#               --classes ${MISSING_CLASSES}
#               --available_classes ${ancestors_list}
#               --outputdir "${GENERATED_DIR}"
#               --templates
#               --templatefile_dir "${AMILAB_SOURCE_DIR}/../PythonWrap/"
#               --addwrap
#               --profile
#               --generate-html             #flag to generate html help
#               --url ${CLASSES_URL_LIST}   #base URL html help
#               --outputhtmldir ${HTML_DIR} #HTML directory
#               -q
#           #DEPENDS
#           #  ${CMAKE_CURRENT_SOURCE_DIR}/${AMI_WXWIDGETS_VERSION}/classes.txt
#           VERBATIM
#       )
#     ELSE(GENERATE_HTML_HELP)
#       ADD_CUSTOM_COMMAND(
#         OUTPUT  ${OUTPUT_LIST} ${GENERATED_DIR}/addwrap_itk.h ${GENERATED_DIR}/addwrap_itk.cpp
#         COMMAND
#           ${PYTHON_EXECUTABLE}
#             ${AMI_WRAPPER} ${XML_OUTPUT}
#             --libname itk
#             --classes ${MISSING_CLASSES}
#             --available_classes ${ancestors_list}
#             --outputdir "${GENERATED_DIR}"
#             --templates
#             --templatefile_dir "${AMILAB_SOURCE_DIR}/../PythonWrap/"
#             --addwrap
#             --profile
#             -q
#   #         DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/${AMI_VTK_VERSION}/classes.txt
#         VERBATIM
#       )
#     ENDIF(GENERATE_HTML_HELP)
#   ENDIF((${NB_MISSING_CLASSES} GREATER 0) OR 
#       (NOT EXISTS ${GENERATED_DIR}/addwrap_itk.h) OR
#       (NOT EXISTS ${GENERATED_DIR}/addwrap_itk.cpp))

ENDIF(AMI_ENABLE_WRAPPING AND AMI_WRAP_ITK)

FOREACH( class ${ancestors_list}  ) 
  ClassUsedName( class m_class )
  SET( itk_HDRS ${GENERATED_DIR}/wrap_${m_class}.h ${itk_HDRS})
  SET( itk_SRCS ${GENERATED_DIR}/wrap_${m_class}.cpp ${itk_SRCS})
ENDFOREACH( class ${ancestors_list}  ) 
SET( itk_HDRS ${GENERATED_DIR}/addwrap_itk.h   ${itk_HDRS})
SET( itk_SRCS ${GENERATED_DIR}/addwrap_itk.cpp ${itk_SRCS})

WRAP_MESSAGE("Wrapping ITK...")


SET(  WrapITK_SRCS
    wrapITK.cpp
    LeastSquares.cpp
    wrapitkRecursiveGaussianImageFilter.cpp
    #wrapitkRead_3D_US.cpp
    #ami_itkRead.cpp
    wrapitkRead.cpp
    #ami_itkWrite.cpp
    wrapitkWrite.cpp
    wrapitkIsoContourDist.cpp
    wrapitkBasicNLMeansFilter.cpp
    wrapitkFastMarchingImageFilter.cpp
    wrapitkWaterShedImageFilter.cpp
    wrapitkMultiScaleVesselnessFilter.cpp
    wrapitkDICOMRead.cpp
    wrapitkSigmoidImageFilter.cpp
    wrapitkLevelSet.cpp
    wrapitkBinaryThresholdImageFilter.cpp
    wrapitkBackTrackingMeshFilter.cpp
    wrapitkLocalMeanImageFilter.cpp
    wrapitkTranslateImageFilter.cpp
    itkamiConvert.cpp
    itkAmiCommand.cpp
)

SET(WrapITK_HDRS
    #../include/wrapConversion.h
    ../include/wrapITK.h
    ../include/wrapitkFastMarchingImageFilter.h
    ../include/wrapitkIsoContourDist.h
    #../include/ami_itkRead.h
    ../include/wrapitkRead.h
    #wrapitkRead_3D_US.h
    ../include/wrapitkRecursiveGaussianImageFilter.h
    ../include/wrapitkWaterShedImageFilter.h
    #../include/ami_itkWrite.h
    ../include/wrapitkWrite.h
    ../include/wrapitkBackTrackingMeshFilter.h
    ../include/wrapitkLocalMeanImageFilter.h
    ../include/wrapitkTranslateImageFilter.h
    ../include/itkBasicNLMeansFilter.txx
    ../include/itkamiConvert.h
    itkAmiCommand.h
    itk_includes.h
)


SET(WrapITK_SRCS
     ${WrapITK_SRCS}
     ${WrapITK_HDRS}
     ${itk_SRCS}
     ${itk_HDRS}
     itk_includes.h
     classes.txt
)

IF (AMI_USE_PRECOMP_HEADERS)
  IF(MSVC)
    # precompiled header
    SET(WrapITK_SRCS ${WrapITK_SRCS} wrap_itkprec.cpp
    )
  ENDIF(MSVC)
ENDIF(AMI_USE_PRECOMP_HEADERS)

IF(WrapITK_SHARED)
  set_source_files_properties(${WrapITK_SRCS} 
    PROPERTIES COMPILE_FLAGS "-DWrapITK_EXPORTS")
ENDIF(WrapITK_SHARED)

#target_link_libraries( WrapITK
#)

IF(WrapITK_SHARED)
  my_add_shared_library ( WrapITK)
ELSE(WrapITK_SHARED)
  my_add_library ( WrapITK)
ENDIF(WrapITK_SHARED)

IF (AMI_USE_PRECOMP_HEADERS)
  # try  precompiled header with visual
  IF(MSVC)
    add_precompiled_header(WrapITK wrap_itkprec.hpp SOURCE_CXX wrap_itkprec.cpp FORCEINCLUDE)
  ENDIF(MSVC )
ENDIF(AMI_USE_PRECOMP_HEADERS)




