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
  MESSAGE("Generate XML file for VTK")
  #
  IF   (VTK_FOUND)
    IF   (VTK_INCLUDE_DIRS)
      FOREACH( inc ${VTK_INCLUDE_DIRS})
        SET( VTK_INCLUDES  -I${inc}  ${VTK_INCLUDES} )
      ENDFOREACH(inc ${VTK_INCLUDE_DIRS})
    ENDIF(VTK_INCLUDE_DIRS)
    #MESSAGE("VTK_INCLUDES=${VTK_INCLUDES}")

#MESSAGE(" VTK_REQUIRED_CXX_FLAGS=${VTK_REQUIRED_CXX_FLAGS}")
     IF   (VTK_REQUIRED_CXX_FLAGS)
       FOREACH( def ${VTK_REQUIRED_CXX_FLAGS})
         SET( VTK_DEFS  ${def}  ${WX_DEFS} )
       ENDFOREACH(def ${VTK_REQUIRED_CXX_FLAGS})
       MESSAGE("VTK_DEFS=${VTK_DEFS}")
     ENDIF(VTK_REQUIRED_CXX_FLAGS)
# 
#     IF   (wxWidgets_DEFINITIONS_DEBUG)
#       FOREACH( def ${wxWidgets_DEFINITIONS_DEBUG})
#         SET( WX_DEFS  -D${def} ${WX_DEFS} )
#       ENDFOREACH(def ${wxWidgets_DEFINITIONS_DEBUG})
#       MESSAGE("wxWidgets_DEFINITIONS_DEBUG=${wxWidgets_DEFINITIONS_DEBUG}")
#     ENDIF(wxWidgets_DEFINITIONS_DEBUG)
# 
#     IF   (wxWidgets_CXX_FLAGS)
#       SET(WX_FLAGS "${CMAKE_CXX_FLAGS} ${wxWidgets_CXX_FLAGS}")
#       MESSAGE("WX_FLAGS=${WX_FLAGS}")
#     ENDIF(wxWidgets_CXX_FLAGS)
  ENDIF ( VTK_FOUND)
  #
  # TODO: run gccxml_vcconfig.bat to allow visual studio 9
  #
  SET(WRAPVTK_OUTDIR ${CMAKE_CURRENT_SOURCE_DIR}/${AMI_VTK_VERSION}/Generated)
  CreateDirectory( ${WRAPVTK_OUTDIR})

  SET(XML_OUTPUT "${WRAPVTK_OUTDIR}/vtk_includes.xml")
  SET(XML_INPUT  "${CMAKE_CURRENT_SOURCE_DIR}/${AMI_VTK_VERSION}/vtk_includes.h")
  SET( GCCXML_result 0)
#   add_custom_command(OUTPUT ${XML_OUTPUT}
#     COMMAND ${GCCXML} -fxml=${XML_OUTPUT} -I${AMILAB_SOURCE_DIR}/Wrapping/include  -I${AMILAB_SOURCE_DIR}/Common/include  -I${AMILAB_SOURCE_DIR}/Language  -I${CMAKE_BINARY_DIR} -I${Boost_INCLUDE_DIR}  ${VTK_INCLUDES}  ${VTK_DEFS}  ${XML_INPUT}
#     DEPENDS ${XML_INPUT}
#   )
  MESSAGE("${GCCXML} -fxml=${XML_OUTPUT} -I${AMILAB_SOURCE_DIR}/Wrapping/include  -I${AMILAB_SOURCE_DIR}/Common/include  -I${AMILAB_SOURCE_DIR}/Language  -I${CMAKE_BINARY_DIR} -I${Boost_INCLUDE_DIR}  ${VTK_INCLUDES}   ${XML_INPUT}")
  execute_process(
    COMMAND ${GCCXML} -fxml=${XML_OUTPUT} -I${AMILAB_SOURCE_DIR}/Wrapping/include  -I${AMILAB_SOURCE_DIR}/Common/include  -I${AMILAB_SOURCE_DIR}/Language  -I${CMAKE_BINARY_DIR} -I${Boost_INCLUDE_DIR}  ${VTK_INCLUDES}   ${XML_INPUT}
  )
   
  # Generate the classes list

  # Read list of classes to wrap
  FILE(READ "${CMAKE_CURRENT_SOURCE_DIR}/${AMI_VTK_VERSION}/classes.txt" classes_txt)
  STRING(REGEX REPLACE "[\r\n]" ";" classes_list ${classes_txt} )

  SET(ANCESTORS_FILE "${CMAKE_CURRENT_SOURCE_DIR}/${AMI_VTK_VERSION}/Generated/ancestors.txt")
  SET(AMI_WRAPPER "${AMILAB_SOURCE_DIR}/../PythonWrap/parse_xml/parse_xml2.py")

  MESSAGE("command is: ${PYTHON_EXECUTABLE}  ${AMI_WRAPPER} ${XML_OUTPUT} --ancestors ${classes_list} --ancestors-file ${ANCESTORS_FILE} -q")
  EXECUTE_PROCESS(
    COMMAND  ${PYTHON_EXECUTABLE}  ${AMI_WRAPPER} ${XML_OUTPUT} --ancestors ${classes_list} --ancestors-file ${ANCESTORS_FILE} -q
    OUTPUT_VARIABLE ancestors_result
    ERROR_VARIABLE ancestors_error
  )
  MESSAGE(" ancestors_result = ${ancestors_result} ")
  MESSAGE(" ancestors_error = ${ancestors_error} ")

  FILE(READ "${ANCESTORS_FILE}" ancestors_txt)
  STRING(REGEX REPLACE "[\r\n]" ";" ancestors_list ${ancestors_txt} )

  # Read list of method pointers to wrap
  #FILE(READ "${CMAKE_CURRENT_SOURCE_DIR}/${AMI_WXWIDGETS_VERSION}/methodpointers.txt" methodpointers_txt)
  #STRING(REGEX REPLACE "[\r\n]" ";" methodpointers_list ${methodpointers_txt} )

  # Wrap all classes at once since it is now fast
  FOREACH( class ${ancestors_list})
    IF( (NOT EXISTS ${WRAPVTK_OUTDIR}/wrap_${class}.cpp) OR
        (NOT EXISTS ${WRAPVTK_OUTDIR}/wrap_${class}.h))
      SET(OUTPUT_LIST ${WRAPVTK_OUTDIR}/wrap_${class}.cpp ${OUTPUT_LIST})
      SET(OUTPUT_LIST ${WRAPVTK_OUTDIR}/wrap_${class}.h ${OUTPUT_LIST})
      SET(MISSING_CLASSES ${class} ${MISSING_CLASSES})
    ENDIF( (NOT EXISTS ${WRAPVTK_OUTDIR}/wrap_${class}.cpp) OR
        (NOT EXISTS ${WRAPVTK_OUTDIR}/wrap_${class}.h))
  ENDFOREACH( class ${ancestors_list}) 

  LIST(LENGTH MISSING_CLASSES NB_MISSING_CLASSES)

  #MESSAGE("Processing classes ${ancestors_list} and addwrap")
  IF ((${NB_MISSING_CLASSES} GREATER 0) OR 
      (NOT EXISTS ${WRAPVTK_OUTDIR}/addwrap_vtk.h) OR
      (NOT EXISTS ${WRAPVTK_OUTDIR}/addwrap_vtk.cpp))
    # Go for python wrapping
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
          --templatefile_dir "${AMILAB_SOURCE_DIR}/../PythonWrap/"
          --addwrap
          --profile
          -q
#         DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/${AMI_VTK_VERSION}/classes.txt
      VERBATIM
    )
  ENDIF((${NB_MISSING_CLASSES} GREATER 0) OR 
      (NOT EXISTS ${WRAPVTK_OUTDIR}/addwrap_vtk.h) OR
      (NOT EXISTS ${WRAPVTK_OUTDIR}/addwrap_vtk.cpp))

ENDIF(AMI_ENABLE_WRAPPING AND AMI_WRAP_VTK)

FOREACH( class ${ancestors_list}  ) 
  SET( vtk_HDRS ${WRAPVTK_OUTDIR}/wrap_${class}.h ${vtk_HDRS})
  SET( vtk_SRCS ${WRAPVTK_OUTDIR}/wrap_${class}.cpp ${vtk_SRCS})
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
)

SET(WrapVTK_HDRS
	../include/vtkwrap.h
	../include/wrapVTK.h
)

SET(WrapVTK_SRCS
     ${WrapVTK_SRCS}
     ${WrapVTK_HDRS}
     ${new_vtk_source_code_list}
     #${vtk_SRCS}
     ${vtk_HDRS}
)

#MESSAGE("WrapVTK_SRCS =  ${WrapVTK_SRCS}")

my_add_library ( WrapVTK)
add_dependencies ( WrapVTK WrapWxWidgets )