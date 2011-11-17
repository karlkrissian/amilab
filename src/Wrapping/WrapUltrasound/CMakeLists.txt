add_definitions(-DMBCS -D_MBCS)
#ADD_DEFINITIONS(-D_AFX_NO_AFXCMN_SUPPORT)

GET_PROPERTY( US_DEF DIRECTORY PROPERTY COMPILE_DEFINITIONS)
MESSAGE("US_DEF = ${US_DEF}")
#FIND_PATH( ULTRASOUND_DIR RPCore.h PATHS "$ENV{ProgramFiles}/EcoResearch/Research_Package/include")

ADD_DEFINITIONS(-D_AFXDLL)
ADD_DEFINITIONS(-D_MT -D_DLL )

#definiciones para dll
#ADD_DEFINITIONS(-D_AFXDLL)
#SET(CMAKE_MFC_FLAG 2) 

INCLUDE( ${wxWidgets_USE_FILE})

include_directories (
  ${AMILAB_SOURCE_DIR}
  ${ULTRASOUND_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}/Generated
  ${AMILAB_SOURCE_DIR}/Graphic/include
  ${AMILAB_SOURCE_DIR}/Algorithms/include
  ${AMILAB_SOURCE_DIR}/AMILab
  ${AMILAB_SOURCE_DIR}/Wrapping/WrapWxWidgets/${AMI_WXWIDGETS_VERSION}
  ${AMILAB_SOURCE_DIR}/Wrapping/WrapWxWidgets/${AMI_WXWIDGETS_VERSION}/Generated
 
  
)

MESSAGE("\nWrapping Ultrasound...\n")


# if automatic wrapping, generate source files
IF(AMI_ENABLE_WRAPPING)
  # Generate XML file
  MESSAGE("Generate XML file  API`s")
  #
  
  SET(AMI_WRAPPER "${AMILAB_SOURCE_DIR}/../PythonWrap/parse_xml/parse_xml2.py")

  #
  # TODO: run gccxml_vcconfig.bat to allow visual studio 9
  #
  
  SET(WRAPULTRASOUND_OUTDIR ${CMAKE_CURRENT_SOURCE_DIR}/Generated)
  CreateDirectory( ${WRAPULTRASOUND_OUTDIR})

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

  # Read vtk ancestors list
  SET( WX_OUTDIR ${AMILAB_SOURCE_DIR}/Wrapping/WrapWxWidgets/${AMI_WXWIDGETS_VERSION}/Generated)

  FILE(READ "${WX_OUTDIR}/ancestors.txt" wx_ancestors_txt)
  STRING(REGEX REPLACE "[\r\n]" ";" wx_ancestors_list ${wx_ancestors_txt} )

  SET(GCCXML_FLAGS "")
  FOREACH( usdef ${US_DEF})
    SET( GCCXML_FLAGS -D${usdef}  ${GCCXML_FLAGS} )
  ENDFOREACH( usdef ${US_DEF} )
 
  IF(WIN32)
    SET(GCCXML_FLAGS ${GCCXML_FLAGS} -D_WIN32 -DWIN32 -D_MSC_VER -D_WINDOWS)
  ENDIF(WIN32)
  MESSAGE("GCCXML_FLAGS='${GCCXML_FLAGS}'")

  SET(XML_OUTPUT "${WRAPULTRASOUND_OUTDIR}/us_includes.xml")
  SET(XML_INPUT  "${CMAKE_CURRENT_SOURCE_DIR}/us_includes.h")
  SET( GCCXML_result 0)
#   add_custom_command(OUTPUT ${XML_OUTPUT}
#     COMMAND ${GCCXML} -fxml=${XML_OUTPUT} -I${AMILAB_SOURCE_DIR}/Wrapping/include  -I${AMILAB_SOURCE_DIR}/Common/include  -I${AMILAB_SOURCE_DIR}/Language  -I${CMAKE_BINARY_DIR} -I${Boost_INCLUDE_DIR}  ${us_includes}  ${WX_DEFS}  ${XML_INPUT}
#     DEPENDS ${XML_INPUT}
#   )
  MESSAGE("\nOBTENER XML ORDEN: ${GCCXML} ${GCCXML_FLAGS} ${WX_INCLUDES}  ${WX_DEFS} -I${Boost_INCLUDE_DIR} -fxml=${XML_OUTPUT}  -I${ULTRASOUND_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/us_includes.h \n")
  execute_process(
    COMMAND ${GCCXML} ${GCCXML_FLAGS} ${WX_INCLUDES}  ${WX_DEFS} -I${Boost_INCLUDE_DIR}
              -fxml=${XML_OUTPUT} 
              -I${ULTRASOUND_DIR} -I${CMAKE_CURRENT_SOURCE_DIR}/include
              ${CMAKE_CURRENT_SOURCE_DIR}/us_includes.h
    RESULT_VARIABLE resvar
    OUTPUT_VARIABLE outvar
    ERROR_VARIABLE  errvar
  )
  MESSAGE("RESULT: ${resvar}")
  MESSAGE("OUTPUT: ${outvar}")
  MESSAGE("ERROR: ${errvar}")

  SET(ancestors_list InterfaceUS)
  
   # Wrap all classes at once since it is now fast
  FOREACH( class ${ancestors_list})
    ClassUsedName( class m_class )
    SET(OUTPUT_LIST 
      ${WRAPULTRASOUND_OUTDIR}/wrap_${m_class}.cpp ${WRAPULTRASOUND_OUTDIR}/wrap_${m_class}.h
      ${OUTPUT_LIST}
    )
  ENDFOREACH( class ${ancestors_list}) 

  ADD_CUSTOM_COMMAND(
  OUTPUT ${OUTPUT_LIST}  ${WRAPULTRASOUND_OUTDIR}/addwrap_us.h ${WRAPULTRASOUND_OUTDIR}/addwrap_us.cpp
  COMMAND
    ${PYTHON_EXECUTABLE} 
      ${AMI_WRAPPER} ${XML_OUTPUT}
      --classes ${ancestors_list}
      --libname us
      --available_classes ${ancestors_list} 
      --available_external_classes ${wx_ancestors_list}
      --outputdir "${WRAPULTRASOUND_OUTDIR}"
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
  SET( us_HDRS ${WRAPULTRASOUND_OUTDIR}/wrap_${m_class}.h ${us_HDRS})
  SET( us_SRCS ${WRAPULTRASOUND_OUTDIR}/wrap_${m_class}.cpp ${us_SRCS})
ENDFOREACH( class ${ancestors_list} ${methodpointers_list} ) 
SET( us_HDRS ${WRAPULTRASOUND_OUTDIR}/addwrap_us.h   ${us_HDRS})
SET( us_SRCS ${WRAPULTRASOUND_OUTDIR}/addwrap_us.cpp ${us_SRCS})

# MESSAGE("${us_HDRS}")

MESSAGE("\nWrapping Ultrasound API...\n")
MESSAGE( "AMI_USE_PRECOMP_HEADERS = ${AMI_USE_PRECOMP_HEADERS} ")

IF(NUMBER_SOURCES_TO_PACKAGE EQUAL 1)
  SET(new_us_source_code_list ${us_SRCS})
ELSE(NUMBER_SOURCES_TO_PACKAGE EQUAL 1)
  SET(source_path "${AMILAB_SOURCE_DIR}/Wrapping/WrapUltrasound")
  GenerateSourcesWrapping (new_us_source_code_list source_path us_SRCS)
ENDIF(NUMBER_SOURCES_TO_PACKAGE EQUAL 1) 
#MESSAGE("wxWidgets ${AMI_WXWIDGETS_VERSION} wrap files: ${new_source_code_list}\n")

  SET(  WrapUltrasound_SRCS
    ${new_us_source_code_list}
  )

SET(  WrapUltrasound_SRCS
  ${WrapUltrasound_SRCS}
  InterfaceUS.cpp
  StdAfx.cpp
)

SET(WrapUltrasound_HDRS
  ${us_HDRS}
  InterfaceUS.h
  StdAfx.h
)


SET(WrapUltrasound_SRCS
  ${WrapUltrasound_SRCS}
  ${WrapUltrasound_HDRS}
)

#MESSAGE("WrapUltrasound_SRCS = ${WrapUltrasound_SRCS}")
  
  SET(CMAKE_MFC_FLAG 2)

my_add_library ( WrapUltrasound)

IF(MSVC) 
 	set_target_properties( WrapUltrasound
	PROPERTIES LINK_FLAGS "/NODEFAULTLIB:msvcrtd.lib")
ENDIF(MSVC)

add_dependencies ( WrapUltrasound WrapWxWidgets)