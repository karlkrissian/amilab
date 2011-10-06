# Create a library called "Hello" which includes the source file "hello.cxx".
# The extension is already found.  Any number of sources could be listed here.
MESSAGE("***** Boost_INCLUDE_DIR=${Boost_INCLUDE_DIR}")

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
  ${CMAKE_CURRENT_SOURCE_DIR}/${AMI_ITK_VERSION}/Generated
  )

INCLUDE( ${USE_ITK_FILE} )
MESSAGE( "USE_ITK_FILE = ${USE_ITK_FILE}")
INCLUDE( ${wxWidgets_USE_FILE})

INCLUDE( ${USE_VTK_FILE})
MESSAGE( "USE_VTK_FILE = ${USE_VTK_FILE}")


IF(AMI_ENABLE_WRAPPING AND AMI_WRAP_ITK)
  # Generate XML file
  MESSAGE("********************************")
  MESSAGE("Generate XML file for ITK")
  MESSAGE("********************************")

MESSAGE("ITK_SOURCE_DIR=${ITK_SOURCE_DIR}")
MESSAGE("ITK_INCLUDE_DIRS=${ITK_INCLUDE_DIRS}")
MESSAGE("ITK_SOURCE_DIR=${ITK_SOURCE_DIR}")

  IF   (ITK_FOUND)
    IF   (ITK_INCLUDE_DIRS)
      FOREACH( inc ${ITK_INCLUDE_DIRS})
        SET( ITK_INCLUDES  -I${inc}  ${ITK_INCLUDES} )
        IF (inc MATCHES ".*Utilities$")
          SET(ITK_UTILITIES_PATH ${inc})
        ENDIF(inc MATCHES ".*Utilities$")
      ENDFOREACH(inc ${ITK_INCLUDE_DIRS})
      MESSAGE("ITK_UTILITIES_PATH = ${ITK_UTILITIES_PATH}")
      # for unknown reasons I had to add those two directories
      SET( ITK_INCLUDES ${ITK_INCLUDES} -I${ITK_UTILITIES_PATH}/vxl/vcl/iso/)
      SET( ITK_INCLUDES ${ITK_INCLUDES} -I${ITK_UTILITIES_PATH}/vxl/core/vnl/)
      SET( ITK_INCLUDES ${ITK_INCLUDES} -I${ITK_UTILITIES_PATH}/vxl/core/generic/)
      #SET( ITK_INCLUDES -I/home/karl/projects/Install/amilab/InsightToolkit-3.20.0/Utilities/vxl/vcl/generic/ ${ITK_INCLUDES} )
      #SET( ITK_INCLUDES -I/home/karl/projects/Install/amilab/InsightToolkit-3.20.0/Utilities/vxl/core/vnl/ ${ITK_INCLUDES} )
    ENDIF(ITK_INCLUDE_DIRS)
     IF   (ITK_REQUIRED_CXX_FLAGS)
       FOREACH( def ${ITK_REQUIRED_CXX_FLAGS})
         SET( ITK_DEFS  ${def}  ${ITK_DEFS} )
       ENDFOREACH(def ${ITK_REQUIRED_CXX_FLAGS})       
     ENDIF(ITK_REQUIRED_CXX_FLAGS)
     # Add Cable configuration for gccxml compilation
     SET(ITK_DEFS -DCABLE_CONFIGURATION  )
     MESSAGE("ITK_DEFS=${ITK_DEFS}")
  ENDIF ( ITK_FOUND)

  SET(GCCXML_FLAGS "")
  IF(WIN32)
    SET(GCCXML_FLAGS ${GCCXML_FLAGS} -D_WIN32 -DWIN32 -D_MSC_VER)
  ENDIF(WIN32)

  SET(WRAPITK_OUTDIR ${CMAKE_CURRENT_SOURCE_DIR}/${AMI_ITK_VERSION}/Generated)
  MESSAGE("${WRAPITK_OUTDIR}")
  SET(ITKPATH1 ${CMAKE_CURRENT_SOURCE_DIR}/${AMI_ITK_VERSION})
  CreateDirectory( ${ITKPATH1})
  CreateDirectory( ${WRAPITK_OUTDIR})
  IF(GENERATE_HTML_HELP)
    SET(CLASSES_URL_LIST "http://www.itk.org/")
    SET(HTML_DIR "${WRAPITK_OUTDIR}/html")
    CreateDirectory( ${HTML_DIR} )
  ENDIF(GENERATE_HTML_HELP)

  SET(XML_OUTPUT "${WRAPITK_OUTDIR}/itk_includes.xml")
  SET(XML_INPUT  "${CMAKE_CURRENT_SOURCE_DIR}/itk_includes.h")
  #SET( GCCXML_result 0)
#${WX_DEFS} 
  MESSAGE(" ${GCCXML} -fxml=${XML_OUTPUT} ${GCCXML_FLAGS} -I${AMILAB_SOURCE_DIR}/Wrapping/include -I${AMILAB_SOURCE_DIR}/CommonBase  -I${AMILAB_SOURCE_DIR}/Common/include  -I${CMAKE_BINARY_DIR} -I${Boost_INCLUDE_DIR} ${ITK_INCLUDES}  ${ITK_DEFS}  ${XML_INPUT}")

  #${GCCXML} -fxml=${XML_OUTPUT}  -I${AMILAB_SOURCE_DIR}/Wrapping/include/ -I${AMILAB_SOURCE_DIR}/CommonBase/ -I${AMILAB_SOURCE_DIR}/Common/include/  -I${CMAKE_BINARY_DIR} -I${Boost_INCLUDE_DIR} -I${AMILAB_SOURCE_DIR}/Wrapping/include/ -I${CMAKE_BINARY_DIR}  ${ITK_INCLUDES}  ${ITK_DEFS} ${WX_DEFS}  ${XML_INPUT}")
  
  execute_process(
    COMMAND ${GCCXML} -fxml=${XML_OUTPUT} ${GCCXML_FLAGS} -I${AMILAB_SOURCE_DIR}/Wrapping/include -I${AMILAB_SOURCE_DIR}/CommonBase -I${AMILAB_SOURCE_DIR}/Common/include -I${CMAKE_BINARY_DIR} -I${Boost_INCLUDE_DIR} ${ITK_INCLUDES} ${ITK_DEFS} ${XML_INPUT}
    OUTPUT_VARIABLE gccxml_result
    ERROR_VARIABLE gccxml_error
  )
  MESSAGE(" gccxml_result = ${gccxml_result} ")
  MESSAGE(" gccxml_error = ${gccxml_error} ")


  # Generate the classes list

  # Read list of classes to wrap
  FILE(STRINGS "${CMAKE_CURRENT_SOURCE_DIR}/classes.txt" classes_list REGEX "^[^#].*$")
  MESSAGE("classes_list = ${classes_list}")
#   FILE(READ "${CMAKE_CURRENT_SOURCE_DIR}/classes.txt" classes_txt)
#   STRING(REGEX REPLACE "[\r\n]" ";" classes_list ${classes_txt} )

  # Read itk ancestors list
  SET( ITK_OUTDIR ${AMILAB_SOURCE_DIR}/Wrapping/WrapITK/${AMI_ITK_VERSION}/Generated)

  SET(ANCESTORS_FILE "${ITK_OUTDIR}/ancestors.txt")
  SET(AMI_WRAPPER "${AMILAB_SOURCE_DIR}/../PythonWrap/parse_xml/parse_xml2.py")

  IF(GENERATE_HTML_HELP)
    MESSAGE("COMMAND: ${PYTHON_EXECUTABLE}  ${AMI_WRAPPER} ${XML_OUTPUT} --ancestors ${classes_list} --ancestors-file ${ANCESTORS_FILE} --generate-html --url ${CLASSES_URL_LIST} --outputhtmldir ${HTML_DIR} --templates --templatefile_dir "${AMILAB_SOURCE_DIR}/../PythonWrap/" -q")
    EXECUTE_PROCESS(
      COMMAND  ${PYTHON_EXECUTABLE}  ${AMI_WRAPPER} ${XML_OUTPUT} --ancestors ${classes_list} --ancestors-file ${ANCESTORS_FILE} --generate-html --url ${CLASSES_URL_LIST} --outputhtmldir ${HTML_DIR} --templates --templatefile_dir "${AMILAB_SOURCE_DIR}/../PythonWrap/" -q
      OUTPUT_VARIABLE ancestors_result
      ERROR_VARIABLE ancestors_error
    )
  ELSE(GENERATE_HTML_HELP)
    MESSAGE("COMMAND IS: ${PYTHON_EXECUTABLE}  ${AMI_WRAPPER} ${XML_OUTPUT} --ancestors ${classes_list} --templates --templatefile_dir "${AMILAB_SOURCE_DIR}/../PythonWrap/" --ancestors-file ${ANCESTORS_FILE} -q")
    EXECUTE_PROCESS(
      COMMAND  ${PYTHON_EXECUTABLE}  ${AMI_WRAPPER} ${XML_OUTPUT} --ancestors ${classes_list}  --templates --templatefile_dir "${AMILAB_SOURCE_DIR}/../PythonWrap/" --ancestors-file ${ANCESTORS_FILE} -q
      OUTPUT_VARIABLE ancestors_result
      ERROR_VARIABLE ancestors_error
    )
  ENDIF(GENERATE_HTML_HELP)

  MESSAGE(" ancestors_result = ${ancestors_result} ")
  MESSAGE(" ancestors_error = ${ancestors_error} ")


  FILE(READ "${ITK_OUTDIR}/ancestors.txt" ancestors_txt)
  STRING(REGEX REPLACE "[\r\n]" ";" ancestors_list ${ancestors_txt} )

  # Wrap all classes at once since it is now fast
  FOREACH( class ${ancestors_list})
    ClassUsedName( class m_class )
    MESSAGE("m_class=${m_class}")
    IF( (NOT EXISTS ${WRAPITK_OUTDIR}/wrap_${m_class}.cpp) OR
        (NOT EXISTS ${WRAPITK_OUTDIR}/wrap_${m_class}.h))
      SET(OUTPUT_LIST ${WRAPITK_OUTDIR}/wrap_${m_class}.cpp ${OUTPUT_LIST})
      SET(OUTPUT_LIST ${WRAPITK_OUTDIR}/wrap_${m_class}.h ${OUTPUT_LIST})
      SET(MISSING_CLASSES ${class} ${MISSING_CLASSES})
    ENDIF( (NOT EXISTS ${WRAPITK_OUTDIR}/wrap_${m_class}.cpp) OR
        (NOT EXISTS ${WRAPITK_OUTDIR}/wrap_${m_class}.h))
  ENDFOREACH( class ${ancestors_list}) 


  LIST(LENGTH MISSING_CLASSES NB_MISSING_CLASSES)

  MESSAGE("OUTPUT_LIST=${OUTPUT_LIST}")
  MESSAGE("NB_MISSING_CLASSES=${NB_MISSING_CLASSES}")

  #MESSAGE("Processing classes ${ancestors_list} and addwrap")
  IF ((${NB_MISSING_CLASSES} GREATER 0) OR 
      (NOT EXISTS ${WRAPITK_OUTDIR}/addwrap_itk.h) OR
      (NOT EXISTS ${WRAPITK_OUTDIR}/addwrap_itk.cpp))
    # Go for python wrapping
    IF(GENERATE_HTML_HELP)
      ADD_CUSTOM_COMMAND(
        OUTPUT  ${OUTPUT_LIST} ${WRAPITK_OUTDIR}/addwrap_itk.h ${WRAPITK_OUTDIR}/addwrap_itk.cpp
        COMMAND
            ${PYTHON_EXECUTABLE}
              ${AMI_WRAPPER} ${XML_OUTPUT}
              --libname itk
              --classes ${MISSING_CLASSES}
              --available_classes ${ancestors_list}
              --outputdir "${WRAPITK_OUTDIR}"
              --templates
              --templatefile_dir "${AMILAB_SOURCE_DIR}/../PythonWrap/"
              --addwrap
              --profile
              --generate-html             #flag to generate html help
              --url ${CLASSES_URL_LIST}   #base URL html help
              --outputhtmldir ${HTML_DIR} #HTML directory
              -q
          #DEPENDS
          #  ${CMAKE_CURRENT_SOURCE_DIR}/${AMI_WXWIDGETS_VERSION}/classes.txt
          VERBATIM
      )
    ELSE(GENERATE_HTML_HELP)
      ADD_CUSTOM_COMMAND(
        OUTPUT  ${OUTPUT_LIST} ${WRAPITK_OUTDIR}/addwrap_itk.h ${WRAPITK_OUTDIR}/addwrap_itk.cpp
        COMMAND
          ${PYTHON_EXECUTABLE}
            ${AMI_WRAPPER} ${XML_OUTPUT}
            --libname itk
            --classes ${MISSING_CLASSES}
            --available_classes ${ancestors_list}
            --outputdir "${WRAPITK_OUTDIR}"
            --templates
            --templatefile_dir "${AMILAB_SOURCE_DIR}/../PythonWrap/"
            --addwrap
            --profile
            -q
  #         DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/${AMI_VTK_VERSION}/classes.txt
        VERBATIM
      )
    ENDIF(GENERATE_HTML_HELP)
  ENDIF((${NB_MISSING_CLASSES} GREATER 0) OR 
      (NOT EXISTS ${WRAPITK_OUTDIR}/addwrap_itk.h) OR
      (NOT EXISTS ${WRAPITK_OUTDIR}/addwrap_itk.cpp))

ENDIF(AMI_ENABLE_WRAPPING AND AMI_WRAP_ITK)

FOREACH( class ${ancestors_list}  ) 
  ClassUsedName( class m_class )
  SET( itk_HDRS ${WRAPITK_OUTDIR}/wrap_${m_class}.h ${itk_HDRS})
  SET( itk_SRCS ${WRAPITK_OUTDIR}/wrap_${m_class}.cpp ${itk_SRCS})
ENDFOREACH( class ${ancestors_list}  ) 
SET( itk_HDRS ${WRAPITK_OUTDIR}/addwrap_itk.h   ${itk_HDRS})
SET( itk_SRCS ${WRAPITK_OUTDIR}/addwrap_itk.cpp ${itk_SRCS})

MESSAGE("Wrapping ITK...")


SET(  WrapITK_SRCS
    itkCannyEdgeDetector.cpp
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
)

SET(WrapITK_HDRS
    ../include/itkCannyEdgeDetector.h
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
)


SET(WrapITK_SRCS
     ${WrapITK_SRCS}
     ${WrapITK_HDRS}
     ${itk_SRCS}
     ${itk_HDRS}
)


my_add_library ( WrapITK)
