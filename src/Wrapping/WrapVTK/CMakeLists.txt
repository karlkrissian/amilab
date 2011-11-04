# Create a library called "Hello" which includes the source file "hello.cxx".
# The extension is already found.  Any number of sources could be listed here.

# MESSAGE("***** Boost_INCLUDE_DIR=${Boost_INCLUDE_DIR}")

# Make sure the compiler can find include files from our Hello library.
include_directories (
  ${wxParams_INCLUDE_DIRS}
  ${AMILAB_SOURCE_DIR}/AMILab
  ${AMILAB_SOURCE_DIR}/Graphic/include
  ${AMILAB_SOURCE_DIR}/Graphic/wxVTK/
  ${AMILAB_SOURCE_DIR}/Graphic/wxVTKSamples/
  ${AMILAB_SOURCE_DIR}/wxParams
  ${AMILAB_SOURCE_DIR}/Algorithms/include
  ${AMILAB_SOURCE_DIR}/Wrapping/WrapWxWidgets/${AMI_WXWIDGETS_VERSION}
  ${AMILAB_SOURCE_DIR}/Wrapping/WrapWxWidgets/${AMI_WXWIDGETS_VERSION}/Generated
  ${AMILAB_SOURCE_DIR}/Wrapping/WrapWxVTK
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}/${AMI_VTK_VERSION}
  ${CMAKE_CURRENT_SOURCE_DIR}/${AMI_VTK_VERSION}/Generated
)

INCLUDE( ${VTK_USE_FILE} )
INCLUDE( ${wxWidgets_USE_FILE})

# if automatic wrapping, generate source files
IF(AMI_ENABLE_WRAPPING AND AMI_WRAP_VTK)
  # Generate XML file
  MESSAGE("***************************")
  MESSAGE(" Generate XML file for VTK")
  MESSAGE("***************************")
  #
  SET(WRAPVTK_OUTDIR ${CMAKE_CURRENT_SOURCE_DIR}/${AMI_VTK_VERSION}/Generated)
  CreateDirectory( ${WRAPVTK_OUTDIR})

  INCLUDE(${AMILAB_SOURCE_DIR}/../CMAKE/amiWrapping.cmake)
  INCLUDE(${AMILAB_SOURCE_DIR}/../CMAKE/amiWrapVTK.cmake)
  GCCXML_USE_VTK()
  SET(XML_OUTPUT "${WRAPVTK_OUTDIR}/vtk_includes.xml")
  SET(XML_INPUT  "${CMAKE_CURRENT_SOURCE_DIR}/${AMI_VTK_VERSION}/vtk_includes.h")
  # Adding needed includes for wrapping
  SET(GCCXML_INCLUDES ${GCCXML_INCLUDES} "-I${CMAKE_CURRENT_SOURCE_DIR}")
  # Run GCCXML
  RUN_GCCXML( ${XML_INPUT} ${XML_OUTPUT})

  IF(GENERATE_HTML_HELP)
    SET(CLASSES_URL_LIST "http://www.vtk.org/doc/release/5.6/html/")
    SET(HTML_DIR "${WRAPVTK_OUTDIR}/html")
    CreateDirectory( ${HTML_DIR} )
  ENDIF(GENERATE_HTML_HELP)

  # Generate the classes list

  # Read list of classes to wrap
  FILE(STRINGS "${CMAKE_CURRENT_SOURCE_DIR}/${AMI_VTK_VERSION}/classes.txt" classes_list REGEX "[^#].*")
  MESSAGE("classes_list = ${classes_list}")

  SET(ANCESTORS_FILE "${CMAKE_CURRENT_SOURCE_DIR}/${AMI_VTK_VERSION}/Generated/ancestors.txt")
  SET(AMI_WRAPPER "${AMILAB_SOURCE_DIR}/../PythonWrap/parse_xml/parse_xml2.py")

  IF(GENERATE_HTML_HELP)
    MESSAGE("COMMAND: ${PYTHON_EXECUTABLE}  ${AMI_WRAPPER} ${XML_OUTPUT} --libname vtk --ancestors ${classes_list} --ancestors-file ${ANCESTORS_FILE} --generate-html --url ${CLASSES_URL_LIST} --outputhtmldir ${HTML_DIR} --templates --templatefile_dir "${AMILAB_SOURCE_DIR}/../PythonWrap/" -q")
    EXECUTE_PROCESS(
      COMMAND  ${PYTHON_EXECUTABLE}  ${AMI_WRAPPER} ${XML_OUTPUT} --libname vtk --ancestors ${classes_list} --ancestors-file ${ANCESTORS_FILE} --generate-html --url ${CLASSES_URL_LIST} --outputhtmldir ${HTML_DIR} --templates --templatefile_dir "${AMILAB_SOURCE_DIR}/../PythonWrap/" -q
      OUTPUT_VARIABLE ancestors_result
      ERROR_VARIABLE ancestors_error
    )
  ELSE(GENERATE_HTML_HELP)
    MESSAGE("COMMAND IS: ${PYTHON_EXECUTABLE}  ${AMI_WRAPPER} ${XML_OUTPUT} --libname vtk --ancestors ${classes_list} --templates --templatefile_dir "${AMILAB_SOURCE_DIR}/../PythonWrap/" --ancestors-file ${ANCESTORS_FILE} -q")
    EXECUTE_PROCESS(
      COMMAND  ${PYTHON_EXECUTABLE}  ${AMI_WRAPPER} ${XML_OUTPUT} --libname vtk --ancestors ${classes_list}  --templates --templatefile_dir "${AMILAB_SOURCE_DIR}/../PythonWrap/" --ancestors-file ${ANCESTORS_FILE} -q
      OUTPUT_VARIABLE ancestors_result
      ERROR_VARIABLE ancestors_error
    )
  ENDIF(GENERATE_HTML_HELP)

  MESSAGE(" ancestors_result = ${ancestors_result} ")
  MESSAGE(" ancestors_error = ${ancestors_error} ")

  FILE(READ "${ANCESTORS_FILE}" ancestors_txt)
  STRING(REGEX REPLACE "[\r\n]" ";" ancestors_list ${ancestors_txt} )

  # Read list of method pointers to wrap
  #FILE(READ "${CMAKE_CURRENT_SOURCE_DIR}/${AMI_WXWIDGETS_VERSION}/methodpointers.txt" methodpointers_txt)
  #STRING(REGEX REPLACE "[\r\n]" ";" methodpointers_list ${methodpointers_txt} )

  # Wrap all classes at once since it is now fast
  FOREACH( class ${ancestors_list})
    ClassUsedName( class m_class )
    IF( (NOT EXISTS ${WRAPVTK_OUTDIR}/wrap_${m_class}.cpp) OR
        (NOT EXISTS ${WRAPVTK_OUTDIR}/wrap_${m_class}.h))
      SET(OUTPUT_LIST ${WRAPVTK_OUTDIR}/wrap_${m_class}.cpp ${OUTPUT_LIST})
      SET(OUTPUT_LIST ${WRAPVTK_OUTDIR}/wrap_${m_class}.h ${OUTPUT_LIST})
      SET(MISSING_CLASSES ${class} ${MISSING_CLASSES})
    ENDIF( (NOT EXISTS ${WRAPVTK_OUTDIR}/wrap_${m_class}.cpp) OR
        (NOT EXISTS ${WRAPVTK_OUTDIR}/wrap_${m_class}.h))
  ENDFOREACH( class ${ancestors_list}) 

  LIST(LENGTH MISSING_CLASSES NB_MISSING_CLASSES)

  #MESSAGE("Processing classes ${ancestors_list} and addwrap")
  IF ((${NB_MISSING_CLASSES} GREATER 0) OR 
      (NOT EXISTS ${WRAPVTK_OUTDIR}/addwrap_vtk.h) OR
      (NOT EXISTS ${WRAPVTK_OUTDIR}/addwrap_vtk.cpp))
    # Go for python wrapping
    IF(GENERATE_HTML_HELP)
      ADD_CUSTOM_COMMAND(
        OUTPUT  ${OUTPUT_LIST} ${WRAPVTK_OUTDIR}/addwrap_vtk.h ${WRAPVTK_OUTDIR}/addwrap_vtk.cpp
        COMMAND
            ${PYTHON_EXECUTABLE}
              ${AMI_WRAPPER} ${XML_OUTPUT}
              --libname vtk
              --filter "vtk*"
              --classes ${MISSING_CLASSES}
              --constructor New
              --available_classes ${ancestors_list}
              --outputdir "${WRAPVTK_OUTDIR}"
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
        OUTPUT  ${OUTPUT_LIST} ${WRAPVTK_OUTDIR}/addwrap_vtk.h ${WRAPVTK_OUTDIR}/addwrap_vtk.cpp
        COMMAND
          ${PYTHON_EXECUTABLE}
            ${AMI_WRAPPER} ${XML_OUTPUT}
            --libname vtk
            --filter "vtk*"
            --classes ${MISSING_CLASSES}
            --constructor New
            --available_classes ${ancestors_list}
            --outputdir "${WRAPVTK_OUTDIR}"
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
      (NOT EXISTS ${WRAPVTK_OUTDIR}/addwrap_vtk.h) OR
      (NOT EXISTS ${WRAPVTK_OUTDIR}/addwrap_vtk.cpp))

ENDIF(AMI_ENABLE_WRAPPING AND AMI_WRAP_VTK)

FOREACH( class ${ancestors_list}  ) 
  ClassUsedName( class m_class )
  SET( vtk_HDRS ${WRAPVTK_OUTDIR}/wrap_${m_class}.h ${vtk_HDRS})
  SET( vtk_SRCS ${WRAPVTK_OUTDIR}/wrap_${m_class}.cpp ${vtk_SRCS})
ENDFOREACH( class ${ancestors_list}  ) 
SET( vtk_HDRS ${WRAPVTK_OUTDIR}/addwrap_vtk.h   ${vtk_HDRS})
SET( vtk_SRCS ${WRAPVTK_OUTDIR}/addwrap_vtk.cpp ${vtk_SRCS})

# file(GLOB vtk_HDRS  "${AMI_VTK_VERSION}/*.h"  )
# file(GLOB vtk_SRCS  "${AMI_VTK_VERSION}/*.cpp")

MESSAGE("Wrapping VTK...")

IF(NUMBER_SOURCES_TO_PACKAGE EQUAL 1)
  SET(new_vtk_source_code_list ${vtk_SRCS})
ELSE(NUMBER_SOURCES_TO_PACKAGE EQUAL 1)
  SET(source_path "${AMILAB_SOURCE_DIR}/Wrapping/WrapVTK")
  GenerateSourcesWrapping (new_vtk_source_code_list source_path vtk_SRCS)
ENDIF(NUMBER_SOURCES_TO_PACKAGE EQUAL 1) 

SET(  WrapVTK_SRCS
  vtkwrap.cpp
  wrapVTK.cpp
  vtkAmiCommand.cpp
)

SET(WrapVTK_HDRS
	../include/vtkwrap.h
	../include/wrapVTK.h
  vtkAmiCommand.h
)

SET(WrapVTK_SRCS
     ${WrapVTK_SRCS}
     ${WrapVTK_HDRS}
     ${new_vtk_source_code_list}
     #${vtk_SRCS}
     ${vtk_HDRS}
)

MESSAGE("WrapVTK_SRCS =  ${WrapVTK_SRCS}")


my_add_library ( WrapVTK)
add_dependencies ( WrapVTK WrapWxWidgets )