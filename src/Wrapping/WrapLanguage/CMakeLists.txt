
SET(CURRENT_LIB WrapLanguage)
#SET(WrapLanguage_TYPE SHARED) 
SET(WrapLanguage_TYPE STATIC) 

# Make sure the compiler can find include files from our Hello library.
include_directories (
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_BINARY_DIR}/Generated
)

INCLUDE( ${wxWidgets_USE_FILE})

# if automatic wrapping, generate source files
IF(AMI_ENABLE_WRAPPING)
  #-----------------------------------------------------------------------------
  # Initialization
  #-----------------------------------------------------------------------------
  INCLUDE(${AMILAB_SOURCE_DIR}/../CMAKE/amiWrapping.cmake)
  SET(GENERATED_DIR ${CMAKE_CURRENT_BINARY_DIR}/Generated)
  SET(WRAPPING_DIR ${CMAKE_CURRENT_SOURCE_DIR})
  CreateDirectory( ${GENERATED_DIR})
  SET(LIBNAME "Language")
  WRAP_INIT(" Language")

  #-----------------------------------------------------------------------------
  # Creating XML file
  #-----------------------------------------------------------------------------
  SET(GCCXML_FLAGS "")
  IF(WIN32)
    SET(GCCXML_FLAGS ${GCCXML_FLAGS} -D_WIN32 -DWIN32 ) #-D_MSC_VER)
  ENDIF(WIN32)
  
  # Add Frameworks information
  IF(APPLE)
    SET(GCCXML_FLAGS ${GCCXML_FLAGS} -F /System/Library/Frameworks )
  ENDIF(APPLE)
  MESSAGE("GCCXML_FLAGS='${GCCXML_FLAGS}'")
  GCCXML_USE_WXWIDGETS()

  SET(XML_OUTPUT "${GENERATED_DIR}/language_includes.xml")
  SET(XML_INPUT  "${CMAKE_CURRENT_SOURCE_DIR}/language_includes.h")

  # Adding needed includes for wrapping ???
  SET(GCCXML_INCLUDES ${GCCXML_INCLUDES} "-I${AMILAB_SOURCE_DIR}/Wrapping/include")
  SET(GCCXML_INCLUDES ${GCCXML_INCLUDES} "-I${AMILAB_SOURCE_DIR}/Common/include")
  SET(GCCXML_INCLUDES ${GCCXML_INCLUDES} "-I${AMILAB_SOURCE_DIR}/CommonBase")
  SET(GCCXML_INCLUDES ${GCCXML_INCLUDES} "-I${AMILAB_SOURCE_DIR}/LanguageBase")
  SET(GCCXML_INCLUDES ${GCCXML_INCLUDES} "-I${AMILAB_SOURCE_DIR}/Language")
  SET(GCCXML_INCLUDES ${GCCXML_INCLUDES} "-I${CMAKE_BINARY_DIR}")
  SET(GCCXML_INCLUDES ${GCCXML_INCLUDES} "-I${PROJECT_SOURCE_DIR}")
  SET(GCCXML_INCLUDES ${GCCXML_INCLUDES} "-I${Boost_INCLUDE_DIR}")

  RUN_GCCXML( ${XML_INPUT} ${XML_OUTPUT})

  #-----------------------------------------------------------------------------
  # Setting up the Documentation information
  #-----------------------------------------------------------------------------
  IF(GENERATE_HTML_HELP)
    SET(CLASSES_URL_LIST "http://www.ctm.ulpgc.es/amilab_doxygen/3.2.0/html/")
    SET(HTML_DIR "${GENERATED_DIR}/html")
    CreateDirectory( ${HTML_DIR} )
  ENDIF(GENERATE_HTML_HELP)

  #-----------------------------------------------------------------------------
  # Generating the classes, functions, etc...  lists
  #-----------------------------------------------------------------------------
  READ_CLASSES(  "${CMAKE_CURRENT_SOURCE_DIR}/classes.txt"  ) 
  READ_FUNCTIONS("${CMAKE_CURRENT_SOURCE_DIR}/functions.txt")

  #-----------------------------------------------------------------------------
  # Generating and reading ancestors
  #-----------------------------------------------------------------------------
  CREATE_ANCESTORS()
  FILE(READ "${ANCESTORS_FILE}" ancestors_txt)
  STRING(REGEX REPLACE "[\r\n]" ";" ancestors_list ${ancestors_txt} )

  #-----------------------------------------------------------------------------
  # Checking for existing and missing files
  #-----------------------------------------------------------------------------
  # Wrap all missing classes at once since it is now fast
  #CHECK_WRAPPED_FILES( "${ancestors_list}"       "MISSING_CLASSES")
  UPDATE_OUTPUT_LIST( "${ancestors_list}"  )
  UPDATE_OUTPUT_LIST( "${functions_list}"  )

  #-----------------------------------------------------------------------------
  # Create the rule that wraps the code
  #-----------------------------------------------------------------------------
  WRAP_CODE()

ENDIF(AMI_ENABLE_WRAPPING)

FOREACH( class ${ancestors_list} ${functions_list}) 
  ClassUsedName( class m_class )
  SET( WrapLanguage_HDRS ${GENERATED_DIR}/wrap_${m_class}.h ${WrapLanguage_HDRS})
  SET( WrapLanguage_SRCS ${GENERATED_DIR}/wrap_${m_class}.cpp ${WrapLanguage_SRCS})
ENDFOREACH( class ${ancestors_list} ${functions_list}) 
SET( WrapLanguage_HDRS ${GENERATED_DIR}/addwrap_language.h   ${WrapLanguage_HDRS})
SET( WrapLanguage_SRCS ${GENERATED_DIR}/addwrap_language.cpp ${WrapLanguage_SRCS})


# file(GLOB language_HDRS  "*.h"  )
# file(GLOB language_SRCS  "*.cpp")

MESSAGE("---------------------")
MESSAGE("Wrapping Language ...")
MESSAGE("---------------------")


SET(WrapLanguage_SRCS
     ${WrapLanguage_SRCS}
     ${WrapLanguage_HDRS}
     language_includes.h
     classes.txt
)

ADD_LIBRARY(${CURRENT_LIB} ${${CURRENT_LIB}_TYPE}  ${${CURRENT_LIB}_SRCS})

IF(CMAKE_SYSTEM_NAME STREQUAL "Linux" AND CMAKE_COMPILER_IS_GNUCC)
  SET_TARGET_PROPERTIES(${CURRENT_LIB} PROPERTIES COMPILE_FLAGS -fPIC)
ENDIF(CMAKE_SYSTEM_NAME STREQUAL "Linux" AND CMAKE_COMPILER_IS_GNUCC)

ADD_DEPENDENCIES ( ${CURRENT_LIB} WrapWxWidgets)

