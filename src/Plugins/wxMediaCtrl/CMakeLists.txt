#==============================================================================
# wxMediaCtrl
#
# Description: A plugin that wrapper the wxMediaCtrl class of wxWidgets 2.8
#              version and adds it in AMILAB.
#
# Author: xXx <xXX>, (C) 2010
#
# Copyright: See COPYING file that comes with this distribution
#==============================================================================

INCLUDE( ${wxWidgets_USE_FILE})

include_directories (
  ${wxParams_INCLUDE_DIRS}
  ${AMILAB_SOURCE_DIR}
  ${AMILAB_SOURCE_DIR}/Algorithms/include
  ${AMILAB_SOURCE_DIR}/Common/include
  ${AMILAB_SOURCE_DIR}/Graphic/include
  ${AMILAB_SOURCE_DIR}/Language
  ${AMILAB_SOURCE_DIR}/Wrapping/include
  ${AMILAB_SOURCE_DIR}/../Pixmaps
  ${AMILAB_SOURCE_DIR}/AMILab
  ${AMILAB_SOURCE_DIR}/Plugins/wxMediaCtrl
  ${AMILAB_SOURCE_DIR}/Plugins/wxMediaCtrl/Generated
#  ${CMAKE_CURRENT_SOURCE_DIR}/${AMI_WXWIDGETS_VERSION}
)

MESSAGE("BEGIN PLUG-IN: wxMediaCtrl")
IF(wxWidgets_FOUND)

  IF(wxWidgets_INCLUDE_DIRS)
    FOREACH( inc ${wxWidgets_INCLUDE_DIRS})
      SET( WX_INCLUDES  -I${inc}  ${WX_INCLUDES} )
    ENDFOREACH(inc ${wxWidgets_INCLUDE_DIRS})
  ENDIF(wxWidgets_INCLUDE_DIRS)
  MESSAGE("WX_INCLUDES=${WX_INCLUDES}")

  IF(wxWidgets_DEFINITIONS)
    FOREACH( def ${wxWidgets_DEFINITIONS})
      SET( WX_DEFS  -D${def}  ${WX_DEFS} )
    ENDFOREACH(def ${wxWidgets_DEFINITIONS})
    MESSAGE("wxWidgets_DEFINITIONS=${wxWidgets_DEFINITIONS}")
  ENDIF(wxWidgets_DEFINITIONS)

  IF(wxWidgets_DEFINITIONS_DEBUG)
    FOREACH( def ${wxWidgets_DEFINITIONS_DEBUG})
      SET( WX_DEFS  -D${def} ${WX_DEFS} )
    ENDFOREACH(def ${wxWidgets_DEFINITIONS_DEBUG})
    MESSAGE("wxWidgets_DEFINITIONS_DEBUG=${wxWidgets_DEFINITIONS_DEBUG}")
  ENDIF(wxWidgets_DEFINITIONS_DEBUG)

  IF(wxWidgets_CXX_FLAGS)
    SET(WX_FLAGS "${CMAKE_CXX_FLAGS} ${wxWidgets_CXX_FLAGS}")
    MESSAGE("WX_FLAGS=${WX_FLAGS}")
  ENDIF(wxWidgets_CXX_FLAGS)

  MESSAGE("BEGIN AUTOMATIC WRAPPING:")

  SET(WRAPWX_OUTDIR "${AMILAB_SOURCE_DIR}/Plugins/wxMediaCtrl/Generated")
  CreateDirectory( ${WRAPWX_OUTDIR})

  SET(XML_OUTPUT "${WRAPWX_OUTDIR}/wx_includes.xml")
  SET(XML_INPUT  "${AMILAB_SOURCE_DIR}/Plugins/wxMediaCtrl/wx_includes.h")
  SET(GCCXML_result 0)

  SET(MYCOMMAND ${GCCXML}    "-fxml=${XML_OUTPUT}")                     #Command
  SET(MYCOMMAND ${MYCOMMAND} "-I${AMILAB_SOURCE_DIR}/Wrapping/include") #Includes
  SET(MYCOMMAND ${MYCOMMAND} "-I${AMILAB_SOURCE_DIR}/Common/include")
  SET(MYCOMMAND ${MYCOMMAND} "-I${AMILAB_SOURCE_DIR}/Language")
  SET(MYCOMMAND ${MYCOMMAND} "-I${CMAKE_BINARY_DIR}" "-I${Boost_INCLUDE_DIR}")
  SET(MYCOMMAND ${MYCOMMAND} ${WX_INCLUDES})
  SET(MYCOMMAND ${MYCOMMAND} ${WX_DEFS})                                #Flags
  SET(MYCOMMAND ${MYCOMMAND} ${XML_INPUT})                              #Input

  MESSAGE("COMMAND: ${MYCOMMAND}")
  EXECUTE_PROCESS(
    COMMAND ${MYCOMMAND}
    RESULT_VARIABLE MYCOMMAND_RESULT
    ERROR_VARIABLE  MYCOMMAND_ERROR
  )

  IF(MYCOMMAND_RESULT)
    MESSAGE(SEND_ERROR "Failed the generation of XML: ${MYCOMMAND_ERROR} - ${MYCOMMAND_RESULT}")
  ELSE(MYCOMMAND_RESULT)
    MESSAGE("Generated XML file")

    FILE(READ "${AMILAB_SOURCE_DIR}/Plugins/wxMediaCtrl/classes.txt" classes_txt)
    STRING(REGEX REPLACE "[\r\n]" ";" classes_list ${classes_txt} )

    SET(ANCESTORS_FILE "${AMILAB_SOURCE_DIR}/Plugins/wxMediaCtrl/Generated/ancestors.txt")
    SET(AMI_WRAPPER "${AMILAB_SOURCE_DIR}/../PythonWrap/parse_xml/parse_xml2.py")

    SET(MYCOMMAND_2 ${PYTHON_EXECUTABLE})                          #Command
    SET(MYCOMMAND_2 ${MYCOMMAND_2} ${AMI_WRAPPER})                 #Wrapper
    SET(MYCOMMAND_2 ${MYCOMMAND_2} ${XML_OUTPUT})                  #Input
    SET(MYCOMMAND_2 ${MYCOMMAND_2} "--ancestors" ${classes_list})  #Options
    SET(MYCOMMAND_2 ${MYCOMMAND_2} "--ancestors-file" ${ANCESTORS_FILE} "-q")
    MESSAGE("COMMAND: ${MYCOMMAND_2}")
    EXECUTE_PROCESS(
      COMMAND ${MYCOMMAND_2}
      RESULT_VARIABLE MYCOMMAND_2_RESULT
      ERROR_VARIABLE  MYCOMMAND_2_ERROR
      OUTPUT_VARIABLE ancestors_result
    )
    IF(MYCOMMAND_2_RESULT)
      MESSAGE(SEND_ERROR "Failed wrapping: ${MYCOMMAND_2_ERROR} - ${MYCOMMAND_2_RESULT}")
    ELSE(MYCOMMAND_2_RESULT)
      MESSAGE("ancestors_result = ${ancestors_result} ")

      FILE(READ "${ANCESTORS_FILE}" ancestors_txt)
      STRING(REGEX REPLACE "[\r\n]" ";" ancestors_list ${ancestors_txt} )

#       FILE(READ "${AMILAB_SOURCE_DIR}/Plugins/wxMediaCtrl/methodpointers.txt" methodpointers_txt)
#       STRING(REGEX REPLACE "[\r\n]" ";" methodpointers_list ${methodpointers_txt} )

      FOREACH( class ${ancestors_list})
        SET(OUTPUT_LIST
          ${WRAPWX_OUTDIR}/wrap_${class}.cpp ${WRAPWX_OUTDIR}/wrap_${class}.h
          ${OUTPUT_LIST}
        )
      ENDFOREACH( class ${ancestors_list})

#       FOREACH( MP ${methodpointers_list})
#         SET( methodpointers_files ${methodpointers_files} ${WRAPWX_OUTDIR}/wrap_${MP}.h ${WRAPWX_OUTDIR}/wrap_${MP}.cpp )
#       ENDFOREACH( MP ${methodpointers_list})

      IF(${GCCXML_result} EQUAL 0)
        MESSAGE("\n${PYTHON_EXECUTABLE} ${AMI_WRAPPER} ${XML_OUTPUT} --libname wx --filter \"wx*\" --classes ${ancestors_list} --available_classes ${ancestors_list} --outputdir ${WRAPWX_OUTDIR} --addwrap --profile --templatefile_dir ${AMILAB_SOURCE_DIR}/../PythonWrap/ -q")
        ADD_CUSTOM_COMMAND(
          OUTPUT ${OUTPUT_LIST} ${methodpointers_list} ${WRAPWX_OUTDIR}/addwrap_wxMediaCtrl.h ${WRAPWX_OUTDIR}/addwrap_wxMediaCtrl.cpp
          COMMAND
            ${PYTHON_EXECUTABLE}
              ${AMI_WRAPPER} ${XML_OUTPUT}
              --libname wxMediaCtrl #name of the library to wrap
              #--filter "wx*" #Recursively wrap needed classes
              --classes ${ancestors_list} #name of the class(es) to wrap
#               --methodpointers ${methodpointers_list}
              --available_classes ${ancestors_list} #${methodpointers_list}
              --outputdir "${WRAPWX_OUTDIR}"
              --addwrap
              --profile
              --templatefile_dir "${AMILAB_SOURCE_DIR}/../PythonWrap/"
              -q
          DEPENDS
            ${AMILAB_SOURCE_DIR}/Plugins/wxMediaCtrl/classes.txt
        )
      ENDIF(${GCCXML_result} EQUAL 0)

      MESSAGE("END AUTOMATIC WRAPPING")
      MESSAGE("BEGIN TARGET GENERATING:")

      FOREACH( class ${ancestors_list} ${methodpointers_list} )
        SET( wxMediaCtrl_HDRS ${WRAPWX_OUTDIR}/wrap_${class}.h ${wxMediaCtrl_HDRS})
        SET( wxMediaCtrl_SRCS ${WRAPWX_OUTDIR}/wrap_${class}.cpp ${wxMediaCtrl_SRCS})
      ENDFOREACH( class ${ancestors_list} ${methodpointers_list} )
      SET( wxMediaCtrl_HDRS ${WRAPWX_OUTDIR}/addwrap_wxMediaCtrl.h   ${wxMediaCtrl_HDRS})
      SET( wxMediaCtrl_SRCS ${WRAPWX_OUTDIR}/addwrap_wxMediaCtrl.cpp ${wxMediaCtrl_SRCS})

      SET( wxMediaCtrl_HDRS
        wxMediaCtrlPlugin.h
        ${wxMediaCtrl_HDRS}
      )

      SET( wxMediaCtrl_SRCS
        wxMediaCtrlPlugin.cpp
        ${wxMediaCtrl_SRCS}
      )

      SET(wxMediaCtrlPlugin_SRCS
        ${wxMediaCtrl_HDRCS}
        ${wxMediaCtrl_SRCS}
      )

      MESSAGE("Source: ${wxMediaCtrlPlugin_SRCS}")

      ADD_LIBRARY(wxMediaCtrlPlugin SHARED ${wxMediaCtrlPlugin_SRCS})
      TARGET_LINK_LIBRARIES(wxMediaCtrlPlugin ${wxWidgets_LIBRARIES})
      ADD_DEPENDENCIES( wxMediaCtrlPlugin WrapWxWidgets )
      MESSAGE("END TARGET GENERATING")

    ENDIF(MYCOMMAND_2_RESULT)
  ENDIF(MYCOMMAND_RESULT)

ELSE(wxWidgets_FOUND)
  MESSAGE(SEND_ERROR "wxWidgets not found, not generated the wxMediaCtrl plugin")
ENDIF(wxWidgets_FOUND)
MESSAGE("END PLUG-IN: wxMediaCtrl")
