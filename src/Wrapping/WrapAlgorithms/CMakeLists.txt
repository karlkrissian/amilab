# Create a library called "Hello" which includes the source file "hello.cxx".
# The extension is already found.  Any number of sources could be listed here.


# Make sure the compiler can find include files from our Hello library.
include_directories (
  ${AMILAB_SOURCE_DIR}/AMILab
  ${AMILAB_SOURCE_DIR}/Algorithms/include
  ${AMILAB_SOURCE_DIR}/Graphic/include
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_BINARY_DIR}/Generated
  ${AMILab_BINARY_DIR}/Wrapping/WrapVTK/${AMI_VTK_VERSION}/Generated
  ${wxParams_INCLUDE_DIRS}
)

INCLUDE( ${VTK_USE_FILE} )

INCLUDE( ${ITK_USE_FILE} )
# allow direct include of vnl_matrix.h
# include_directories(
#   /usr/local/include/InsightToolkit/Utilities/vxl/core/vnl
# )
#MESSAGE( "*** dir = ${ITK_DIR}/Utilities/vxl/core/vnl/  ${ITK_CHECK_ITK_VXL_DIR}")

INCLUDE( ${wxWidgets_USE_FILE})


# if automatic wrapping, generate source files
IF(AMI_ENABLE_WRAPPING)

  #------------------------------------------------------------
  # Initialization
  #------------------------------------------------------------
  INCLUDE(${AMILAB_SOURCE_DIR}/../CMAKE/amiWrapping.cmake)
  SET(GENERATED_DIR ${CMAKE_CURRENT_BINARY_DIR}/Generated)
  CreateDirectory( ${GENERATED_DIR})
  SET(LIBNAME "algorithms")
  WRAP_INIT(" Algorithms")


  #------------------------------------------------------------
  # Creating XML file
  #------------------------------------------------------------

  INCLUDE(${AMILAB_SOURCE_DIR}/../CMAKE/amiWrapVTK.cmake)
  GCCXML_USE_VTK()

  IF   (ITK_FOUND)
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
        SET( GCCXML_ITK_INCLUDES ${GCCXML_ITK_INCLUDES} -I${ITKVNL_INCLUDE_DIRS}/vnl/)
      ENDIF (${ITK_VERSION_MAJOR} EQUAL "3")
    ENDIF(ITK_INCLUDE_DIRS)
     IF   (ITK_REQUIRED_CXX_FLAGS)
       FOREACH( def ${ITK_REQUIRED_CXX_FLAGS})
         SET( GCCXML_ITK_DEFS  ${def}  ${GCCXML_ITK_DEFS} )
       ENDFOREACH(def ${ITK_REQUIRED_CXX_FLAGS})       
     ENDIF(ITK_REQUIRED_CXX_FLAGS)
     # Add Cable configuration for gccxml compilation
     # it is really needed ???
     SET(GCCXML_ITK_DEFS -DCABLE_CONFIGURATION  )
     WRAP_MESSAGE("GCCXML_ITK_DEFS=${GCCXML_ITK_DEFS}")
  ENDIF ( ITK_FOUND)

  # Update GCCXML variables
  SET( GCCXML_INCLUDES ${GCCXML_INCLUDES}  ${GCCXML_ITK_INCLUDES})
  SET( GCCXML_DEFS     ${GCCXML_DEFS}      ${GCCXML_ITK_DEFS}    )


  INCLUDE(${AMILAB_SOURCE_DIR}/../CMAKE/amiWrapWxWidgets.cmake)
  GCCXML_USE_WXWIDGETS()

  SET(GCCXML_FLAGS "")
  IF(WIN32)
    SET(GCCXML_FLAGS ${GCCXML_FLAGS} -D_WIN32 -DWIN32 -D_MSC_VER)
  ENDIF(WIN32)
  
  IF(OPENGL_INCLUDE_DIR)
    SET(OPENGL_FLAGS -I${OPENGL_INCLUDE_DIR})
  ENDIF(OPENGL_INCLUDE_DIR)
  
  # Add Frameworks information
  IF(APPLE)
    SET(GCCXML_FLAGS ${GCCXML_FLAGS} -F /System/Library/Frameworks )
  ENDIF(APPLE)
  MESSAGE("GCCXML_FLAGS='${GCCXML_FLAGS}'")

  SET( GCCXML_DEFS     ${GCCXML_DEFS}      "${OPENGL_FLAGS}"    )
  SET( GCCXML_DEFS     ${GCCXML_DEFS}      "${GCCXML_FLAGS}"    )

  SET(XML_OUTPUT "${GENERATED_DIR}/algorithms_includes.xml")
  SET(XML_INPUT  "${CMAKE_CURRENT_SOURCE_DIR}/algorithms_includes.h")

  # Adding needed includes for wrapping ???
  SET(GCCXML_INCLUDES ${GCCXML_INCLUDES} "-I${AMILAB_SOURCE_DIR}/AMILab")
  SET(GCCXML_INCLUDES ${GCCXML_INCLUDES} "-I${AMILAB_SOURCE_DIR}/Wrapping/include")
  SET(GCCXML_INCLUDES ${GCCXML_INCLUDES} "-I${AMILAB_SOURCE_DIR}/Common/include")
  SET(GCCXML_INCLUDES ${GCCXML_INCLUDES} "-I${AMILAB_SOURCE_DIR}/CommonBase")
  SET(GCCXML_INCLUDES ${GCCXML_INCLUDES} "-I${AMILAB_SOURCE_DIR}/LanguageBase")
  SET(GCCXML_INCLUDES ${GCCXML_INCLUDES} "-I${AMILAB_SOURCE_DIR}/Language")
  SET(GCCXML_INCLUDES ${GCCXML_INCLUDES} "-I${AMILAB_SOURCE_DIR}/Algorithms/include")
  SET(GCCXML_INCLUDES ${GCCXML_INCLUDES} "-I${AMILAB_SOURCE_DIR}/Graphic/include")
  SET(GCCXML_INCLUDES ${GCCXML_INCLUDES} "-I${wxParams_INCLUDE_DIRS}")
  SET(GCCXML_INCLUDES ${GCCXML_INCLUDES} "-I${CMAKE_CURRENT_SOURCE_DIR}/${AMI_WXWIDGETS_VERSION}")
  SET(GCCXML_INCLUDES ${GCCXML_INCLUDES} "-I${CMAKE_BINARY_DIR}")
  SET(GCCXML_INCLUDES ${GCCXML_INCLUDES} "-I${PROJECT_SOURCE_DIR}")
  SET(GCCXML_INCLUDES ${GCCXML_INCLUDES} "-I${Boost_INCLUDE_DIR}")

  RUN_GCCXML( ${XML_INPUT} ${XML_OUTPUT})

  #------------------------------------------------------------
  # Setting up the Documentation information
  #------------------------------------------------------------

  IF(GENERATE_HTML_HELP)
    SET(CLASSES_URL_LIST "http://www.ctm.ulpgc.es/amilab_doxygen/3.2.0/html/")
    SET(HTML_DIR "${GENERATED_DIR}/html")
    CreateDirectory( ${HTML_DIR} )
  ENDIF(GENERATE_HTML_HELP)

  #------------------------------------------------------------
  # Generating the classes, functions, etc...  lists
  #------------------------------------------------------------

  # Read list of classes to wrap
  READ_CLASSES(
    "${CMAKE_CURRENT_SOURCE_DIR}/classes.txt"
  ) 
  #FILE(READ "${CMAKE_CURRENT_SOURCE_DIR}/classes.txt" classes_txt)
  #STRING(REGEX REPLACE "[\r\n]" ";" classes_list ${classes_txt} )

  #------------------------------------------------------------
  # Generating and reading ancestors
  #------------------------------------------------------------

  # Read vtk ancestors list
  SET( VTK_OUTDIR ${AMILab_BINARY_DIR}/Wrapping/WrapVTK/${AMI_VTK_VERSION}/Generated)
  FILE(READ "${VTK_OUTDIR}/ancestors.txt" vtk_ancestors_txt)
  STRING(REGEX REPLACE "[\r\n]" ";" vtk_ancestors_list ${vtk_ancestors_txt} )
  SET(AVAILABLE_EXTERNAL_CLASSES ${vtk_ancestors_list})
  SET(EXTERNAL_DLLNAME WrapVTK)

  CREATE_ANCESTORS()

  FILE(READ "${ANCESTORS_FILE}" ancestors_txt)
  STRING(REGEX REPLACE "[\r\n]" ";" ancestors_list ${ancestors_txt} )

  #------------------------------------------------------------
  # Checking for existing and missing files
  #------------------------------------------------------------

  # Wrap all missing classes at once since it is now fast
  CHECK_WRAPPED_FILES( "${ancestors_list}"       "MISSING_CLASSES")

  LIST(LENGTH MISSING_CLASSES   NB_MISSING_CLASSES)
  WRAP_MESSAGE("MISSING_CLASSES   = ${MISSING_CLASSES}")

#   # Wrap all classes at once since it is now fast
#   FOREACH( class ${ancestors_list})
# 
#     ClassUsedName( class m_class )
# 
#     # Check that the class is not already wrapped with VTK wrapping
#     IF ((NOT EXISTS ${VTK_OUTDIR}/wrap_${m_class}.h))
#       SET(compilation_list ${compilation_list} ${m_class})
#       IF ( (NOT EXISTS ${GENERATED_DIR}/wrap_${m_class}.cpp) OR
#             (NOT EXISTS ${GENERATED_DIR}/wrap_${m_class}.h))
#         SET(OUTPUT_LIST ${GENERATED_DIR}/wrap_${m_class}.cpp ${OUTPUT_LIST})
#         SET(OUTPUT_LIST ${GENERATED_DIR}/wrap_${m_class}.h ${OUTPUT_LIST})
#         SET(MISSING_CLASSES ${class} ${MISSING_CLASSES})
#       ENDIF( (NOT EXISTS ${GENERATED_DIR}/wrap_${m_class}.cpp) OR
#           (NOT EXISTS ${GENERATED_DIR}/wrap_${m_class}.h))
# #    ELSE((NOT EXISTS ${VTK_OUTDIR}/wrap_${class}.h))
#     ENDIF((NOT EXISTS ${VTK_OUTDIR}/wrap_${m_class}.h))
#   ENDFOREACH( class ${ancestors_list}) 

#   MESSAGE("Processing classes ${ancestors_list} and addwrap")
#   MESSAGE(" GENERATED_DIR = ${GENERATED_DIR} ")
#   MESSAGE(" GENERATE_HTML_HELP = ${GENERATE_HTML_HELP}")

  #------------------------------------------------------------
  # Create the rule that wraps the code
  #------------------------------------------------------------

  WRAP_CODE()
ENDIF(AMI_ENABLE_WRAPPING)


FOREACH( class ${ancestors_list}) #${compilation_list}  ) 
  ClassUsedName( class m_class )
  SET( WrapAlgorithms_HDRS ${GENERATED_DIR}/wrap_${m_class}.h ${WrapAlgorithms_HDRS})
  SET( WrapAlgorithms_SRCS ${GENERATED_DIR}/wrap_${m_class}.cpp ${WrapAlgorithms_SRCS})
ENDFOREACH( class ${ancestors_list}  ) 
SET( WrapAlgorithms_HDRS ${GENERATED_DIR}/addwrap_algorithms.h   ${WrapAlgorithms_HDRS})
SET( WrapAlgorithms_SRCS ${GENERATED_DIR}/addwrap_algorithms.cpp ${WrapAlgorithms_SRCS})

SET(WrapAlgorithms_SRCS
     ${WrapAlgorithms_SRCS}
     ${WrapAlgorithms_HDRS}
)

#MESSAGE("WrapAlgorithms_SRCS =  ${WrapAlgorithms_SRCS}")

my_add_library ( WrapAlgorithms)

target_link_libraries(
  WrapAlgorithms
  WrapVTK
)


add_dependencies ( WrapAlgorithms WrapWxWidgets WrapVTK)
