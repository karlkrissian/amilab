# Create a library called "MT" which includes the source file "hello.cxx".
# The extension is already found.  Any number of sources could be listed here.

FIND_PATH( MT_DIR MTC.h PATHS "$ENV{ProgramFiles}/Claron Technology/MicronTracker/Dist")

INCLUDE( ${VTK_USE_FILE} )
INCLUDE( ${wxWidgets_USE_FILE})

include_directories (
  ${AMILAB_SOURCE_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}/include
  ${CMAKE_CURRENT_BINARY_DIR}/Generated
  ${MT_DIR}
  ${AMILAB_SOURCE_DIR}/Wrapping/WrapWxWidgets/${AMI_WXWIDGETS_VERSION}
  ${AMILab_BINARY_DIR}/Wrapping/WrapWxWidgets/${AMI_WXWIDGETS_VERSION}/Generated
  ${AMILAB_SOURCE_DIR}/Wrapping/WrapVTK/${AMI_VTK_VERSION}
  ${AMILab_BINARY_DIR}/Wrapping/WrapVTK/${AMI_VTK_VERSION}/Generated
)

# if automatic wrapping, generate source files
IF(AMI_ENABLE_WRAPPING)
  # Generate XML file
  MESSAGE("Generate XML file  API`s")
  #
  
  SET(AMI_WRAPPER "${AMILAB_SOURCE_DIR}/../PythonWrap/parse_xml/parse_xml2.py")


  #
  # TODO: run gccxml_vcconfig.bat to allow visual studio 9
  #
  
  SET(WRAPMT_OUTDIR ${CMAKE_CURRENT_BINARY_DIR}/Generated)
  CreateDirectory( ${WRAPMT_OUTDIR})
  
  # found wxWidgets
  IF   (wxWidgets_FOUND)
    IF   (wxWidgets_INCLUDE_DIRS)
      FOREACH( inc ${wxWidgets_INCLUDE_DIRS})
        SET( WX_INCLUDES  -I${inc}  ${WX_INCLUDES} )
      ENDFOREACH(inc ${wxWidgets_INCLUDE_DIRS})
    ENDIF(wxWidgets_INCLUDE_DIRS)
    MESSAGE("WX_INCLUDES=${WX_INCLUDES}")

    IF   (wxWidgets_DEFINITIONS)
      FOREACH( def ${wxWidgets_DEFINITIONS})
        SET( WX_DEFS  -D${def}  ${WX_DEFS} )
      ENDFOREACH(def ${wxWidgets_DEFINITIONS})
      MESSAGE("wxWidgets_DEFINITIONS=${wxWidgets_DEFINITIONS}")
    ENDIF(wxWidgets_DEFINITIONS)

    IF   (wxWidgets_DEFINITIONS_DEBUG)
      FOREACH( def ${wxWidgets_DEFINITIONS_DEBUG})
        SET( WX_DEFS  -D${def} ${WX_DEFS} )
      ENDFOREACH(def ${wxWidgets_DEFINITIONS_DEBUG})
      MESSAGE("wxWidgets_DEFINITIONS_DEBUG=${wxWidgets_DEFINITIONS_DEBUG}")
    ENDIF(wxWidgets_DEFINITIONS_DEBUG)

    IF   (wxWidgets_CXX_FLAGS)
      SET(WX_FLAGS "${CMAKE_CXX_FLAGS} ${wxWidgets_CXX_FLAGS}")
      MESSAGE("WX_FLAGS=${WX_FLAGS}")
    ENDIF(wxWidgets_CXX_FLAGS)
  ENDIF (wxWidgets_FOUND)
  
  # Read wxWidgets ancestors list
  SET( WX_OUTDIR ${AMILAB_BINARY_DIR}/Wrapping/WrapWxWidgets/${AMI_WXWIDGETS_VERSION}/Generated)

  FILE(READ "${WX_OUTDIR}/ancestors.txt" wx_ancestors_txt)
  STRING(REGEX REPLACE "[\r\n]" ";" wx_ancestors_list ${wx_ancestors_txt} )

  # end found wxWidgets

  SET(XML_OUTPUT "${WRAPMT_OUTDIR}/mt_includes.xml")
  SET(XML_INPUT  "${CMAKE_CURRENT_SOURCE_DIR}/mt_includes.h")
  SET( GCCXML_result 0)
#   add_custom_command(OUTPUT ${XML_OUTPUT}
#     COMMAND ${GCCXML} -fxml=${XML_OUTPUT} -I${AMILAB_SOURCE_DIR}/Wrapping/include  -I${AMILAB_SOURCE_DIR}/Common/include  -I${AMILAB_SOURCE_DIR}/Language  -I${CMAKE_BINARY_DIR} -I${Boost_INCLUDE_DIR}  ${mt_INCLUDES}  ${WX_DEFS}  ${XML_INPUT}
#     DEPENDS ${XML_INPUT}
#   )
  MESSAGE("\nOBTENER XML ORDEN: ${GCCXML} -fxml=${XML_OUTPUT}  ${WX_INCLUDES}  ${WX_DEFS}  -I${MT_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/mt_includes.h \n")
  execute_process(
    COMMAND ${GCCXML}  ${WX_INCLUDES}  ${WX_DEFS} 
              -fxml=${XML_OUTPUT} 
              -I${MT_DIR} -I${CMAKE_CURRENT_SOURCE_DIR}/include
              ${CMAKE_CURRENT_SOURCE_DIR}/include/mt_includes.h
    RESULT_VARIABLE resvar
    OUTPUT_VARIABLE outvar
    ERROR_VARIABLE  errvar
  )
  MESSAGE("RESULT: ${resvar}")
  MESSAGE("OUTPUT: ${outvar}")
  MESSAGE("ERROR: ${errvar}")

  SET(ancestors_list Cameras MCamera XPoints MTXPoint MTCollection::Collection Facet Vector Persistence Markers MTMarker::Marker)
  
   # Wrap all classes at once since it is now fast
  FOREACH( class ${ancestors_list})
    ClassUsedName( class m_class )
    SET(OUTPUT_LIST 
      ${WRAPMT_OUTDIR}/wrap_${m_class}.cpp ${WRAPMT_OUTDIR}/wrap_${m_class}.h
      ${OUTPUT_LIST}
    )
  ENDFOREACH( class ${ancestors_list}) 

  ADD_CUSTOM_COMMAND(
  OUTPUT ${OUTPUT_LIST}  ${WRAPMT_OUTDIR}/addwrap_mt.h ${WRAPMT_OUTDIR}/addwrap_mt.cpp
  COMMAND
    ${PYTHON_EXECUTABLE} 
      ${AMI_WRAPPER} ${XML_OUTPUT}
      --libname mt
      --classes ${ancestors_list}
      --available_classes ${ancestors_list} 
      --available_external_classes ${wx_ancestors_list}
      --outputdir "${WRAPMT_OUTDIR}"
      --addwrap
      --profile
      --templatefile_dir "${AMILAB_SOURCE_DIR}/../PythonWrap/"
      -q
  COMMENT "${PYTHON_EXECUTABLE} ${AMI_WRAPPER} ${XML_OUTPUT}"
  VERBATIM
  #DEPENDS
  #  ${CMAKE_CURRENT_SOURCE_DIR}/${AMI_WXWIDGETS_VERSION}/classes.txt
  )
    
ENDIF(AMI_ENABLE_WRAPPING)

FOREACH( class ${ancestors_list}  ) 
  ClassUsedName( class m_class )
  SET( mt_HDRS ${WRAPMT_OUTDIR}/wrap_${m_class}.h ${mt_HDRS})
  SET( mt_SRCS ${WRAPMT_OUTDIR}/wrap_${m_class}.cpp ${mt_SRCS})
ENDFOREACH( class ${ancestors_list} ${methodpointers_list} ) 
SET( mt_HDRS ${WRAPMT_OUTDIR}/addwrap_mt.h   ${mt_HDRS})
SET( mt_SRCS ${WRAPMT_OUTDIR}/addwrap_mt.cpp ${mt_SRCS})

# MESSAGE("${mt_HDRS}")

MESSAGE("\nWrapping MicronTracker...\n")
MESSAGE( "AMI_USE_PRECOMP_HEADERS = ${AMI_USE_PRECOMP_HEADERS} ")

IF(NUMBER_SOURCES_TO_PACKAGE EQUAL 1)
  SET(new_mt_source_code_list ${mt_SRCS})
ELSE(NUMBER_SOURCES_TO_PACKAGE EQUAL 1)
  SET(source_path "${AMILAB_SOURCE_DIR}/Wrapping/WrapMicronTracker")
  GenerateSourcesWrapping (new_mt_source_code_list source_path mt_SRCS)
ENDIF(NUMBER_SOURCES_TO_PACKAGE EQUAL 1) 
#MESSAGE("wxWidgets ${AMI_WXWIDGETS_VERSION} wrap files: ${new_source_code_list}\n")

IF (AMI_USE_PRECOMP_HEADERS)
  SET(  WrapMicronTracker_SRCS
    #${mt_SRCS}
    ${new_mt_source_code_list}
  )
ELSE(AMI_USE_PRECOMP_HEADERS)
  SET(  WrapMicronTracker_SRCS
    ${new_mt_source_code_list}
  )
ENDIF(AMI_USE_PRECOMP_HEADERS)

SET(  WrapMicronTracker_SRCS
  ${WrapMicronTracker_SRCS}
  src/MCamera.cpp
  src/Cameras.cpp
  src/UtilityFunctions.cpp
  src/wrapMT.cpp
  src/Collection.cpp
  src/Facet.cpp
  src/Marker.cpp
  src/Markers.cpp
  src/MTXPoint.cpp
  src/Persistence.cpp
  src/Vector.cpp
  src/Xform3D.cpp
  src/XPoints.cpp
)

SET(WrapMicronTracker_HDRS
  ${mt_HDRS}
  include/MCamera.h
  include/Cameras.h
  include/UtilityFunctions.h
  include/wrapMT.h
  include/Collection.h
  include/Facet.h
  include/Marker.h
  include/Markers.h
  include/MTXPoint.h
  include/Persistence.h
  include/Vector.h
  include/Xform3D.h
  include/XPoints.h
)


SET(WrapMicronTracker_SRCS
  ${WrapMicronTracker_SRCS}
  ${WrapMicronTracker_HDRS}
)

#MESSAGE("WrapMicronTracker_SRCS = ${WrapMicronTracker_SRCS}")

IF (AMI_USE_PRECOMP_HEADERS)
  IF(CMAKE_COMPILER_IS_GNUCXX)
    ADD_PCH_RULE(${CMAKE_CURRENT_SOURCE_DIR}/${AMI_WXWIDGETS_VERSION}/mt_includes.h WrapMicronTracker_SRCS)
  ENDIF(CMAKE_COMPILER_IS_GNUCXX )
ENDIF(AMI_USE_PRECOMP_HEADERS)


my_add_library ( WrapMicronTracker)

add_dependencies ( WrapMicronTracker WrapWxWidgets)
