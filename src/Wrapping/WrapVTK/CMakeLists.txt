# Create a library called "Hello" which includes the source file "hello.cxx".
# The extension is already found.  Any number of sources could be listed here.

# MESSAGE("***** Boost_INCLUDE_DIR=${Boost_INCLUDE_DIR}")

# Make sure the compiler can find include files from our Hello library.
include_directories (
  #${AMILAB_SOURCE_DIR}/Language
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}/${AMI_VTK_VERSION}
  ${CMAKE_CURRENT_BINARY_DIR}/${AMI_VTK_VERSION}/Generated
  ${AMILab_BINARY_DIR}
)

#INCLUDE( ${USE_VTK_FILE} )
#INCLUDE( ${USE_ITK_FILE} )
INCLUDE( ${VTK_USE_FILE} )
INCLUDE( ${ITK_USE_FILE} )
#INCLUDE( ${wxWidgets_USE_FILE})


# Give the option to compile as shared, but need to write dependencies for 
# Windows and MacOS ...
OPTION(WrapVTK_SHARED     "Compile WrapVTK library as shared" OFF)

# if automatic wrapping, generate source files
IF(AMI_ENABLE_WRAPPING AND AMI_WRAP_VTK)

  #------------------------------------------------------------
  # Initialization
  #------------------------------------------------------------

  INCLUDE(${AMILAB_SOURCE_DIR}/../CMAKE/amiWrapping.cmake)
  #SET(GENERATED_DIR ${CMAKE_CURRENT_SOURCE_DIR}/${AMI_VTK_VERSION}/Generated)
  SET(GENERATED_DIR ${CMAKE_CURRENT_BINARY_DIR}/${AMI_VTK_VERSION}/Generated)
  CreateDirectory( ${GENERATED_DIR})
  SET(LIBNAME "vtk")
  WRAP_INIT(" VTK ${AMI_VTK_VERSION}")

  #------------------------------------------------------------
  # Read list of classes and functions to wrap
  #------------------------------------------------------------

  # Read list of classes to wrap
  READ_CLASSES2(
    "${CMAKE_CURRENT_SOURCE_DIR}/classes_common.txt"
    "${CMAKE_CURRENT_SOURCE_DIR}/${AMI_VTK_VERSION}/classes.txt"
  ) 
  #MESSAGE("classes.txt : ${CMAKE_CURRENT_SOURCE_DIR}/${AMI_VTK_VERSION}/classes.txt")

  SET(CASTXMLSTART_LIST ${classes_list} )
  JOIN(CASTXMLSTART "," ${CASTXMLSTART_LIST})
  MESSAGE("CASTXMLSTART = ${CASTXMLSTART}")

  #------------------------------------------------------------
  # Creating XML file
  #------------------------------------------------------------

  INCLUDE(${AMILAB_SOURCE_DIR}/../CMAKE/amiWrapVTK.cmake)
  GCCXML_USE_VTK()
  SET(XML_OUTPUT "${GENERATED_DIR}/vtk_includes.xml")
  SET(XML_INPUT  "${CMAKE_CURRENT_SOURCE_DIR}/${AMI_VTK_VERSION}/vtk_includes.h")
  # Adding needed includes for wrapping
  SET(GCCXML_INCLUDES ${GCCXML_INCLUDES} "-I${CMAKE_CURRENT_SOURCE_DIR}")
  # Run GCCXML
  RUN_GCCXML( ${XML_INPUT} ${XML_OUTPUT})


  #------------------------------------------------------------
  # Setting up the Documentation information
  #------------------------------------------------------------

  IF(GENERATE_HTML_HELP)
    SET(CLASSES_URL_LIST "http://www.vtk.org/doc/release/5.6/html/")
    SET(HTML_DIR "${GENERATED_DIR}/html")
    CreateDirectory( ${HTML_DIR} )
  ENDIF(GENERATE_HTML_HELP)

  #------------------------------------------------------------
  # Generating the classes, functions, etc...  lists
  #------------------------------------------------------------

  SET(WRAPPING_DIR ${CMAKE_CURRENT_SOURCE_DIR})

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
  # Checking for existing and missing files
  #------------------------------------------------------------

  # Wrap all missing classes at once since it is now fast
  #CHECK_WRAPPED_FILES( "${ancestors_list}"       "MISSING_CLASSES")
  UPDATE_OUTPUT_LIST( "${ancestors_list}"  )

  #------------------------------------------------------------
  # Create the rule that wraps the code
  #------------------------------------------------------------

  SET(LIBFILTER       "vtk*")
  SET(LIBCONSTRUCTOR  "New")

  IF(WrapVTK_SHARED)
    SET(DLLNAME "WrapVTK")
  ENDIF(WrapVTK_SHARED)
  SET(NO_METHOD_HELP true)

  WRAP_CODE()


ENDIF(AMI_ENABLE_WRAPPING AND AMI_WRAP_VTK)

FOREACH( class ${ancestors_list}  ) 
  ClassUsedName( class m_class )
  SET( vtk_HDRS ${GENERATED_DIR}/wrap_${m_class}.h ${vtk_HDRS})
  SET( vtk_SRCS ${GENERATED_DIR}/wrap_${m_class}.cpp ${vtk_SRCS})
ENDFOREACH( class ${ancestors_list}  ) 
SET( vtk_HDRS ${GENERATED_DIR}/addwrap_vtk.h   ${vtk_HDRS})
SET( vtk_SRCS ${GENERATED_DIR}/addwrap_vtk.cpp ${vtk_SRCS})

# file(GLOB vtk_HDRS  "${AMI_VTK_VERSION}/*.h"  )
# file(GLOB vtk_SRCS  "${AMI_VTK_VERSION}/*.cpp")

#WRAP_MESSAGE("Wrapping VTK...")

IF(NUMBER_SOURCES_TO_PACKAGE EQUAL 1)
  SET(new_vtk_source_code_list ${vtk_SRCS})
ELSE(NUMBER_SOURCES_TO_PACKAGE EQUAL 1)
  SET(source_path "${AMILAB_SOURCE_DIR}/Wrapping/WrapVTK")
  GenerateSourcesWrapping (new_vtk_source_code_list source_path vtk_SRCS)
ENDIF(NUMBER_SOURCES_TO_PACKAGE EQUAL 1) 

SET(  WrapVTK_SRCS
  wrap_VTK.cpp
  vtkAmiCommand.cpp
)

SET(WrapVTK_HDRS
	../include/wrapVTK.h
  vtkAmiCommand.h
  wrap_vtkprec.hpp
  classes_common.txt
  vtk_includes_common.h
  members_blacklist.py
  ${CMAKE_CURRENT_SOURCE_DIR}/${AMI_VTK_VERSION}/classes.txt
  ${CMAKE_CURRENT_SOURCE_DIR}/${AMI_VTK_VERSION}/vtk_includes.h
)

SET(WrapVTK_SRCS
     ${WrapVTK_SRCS}
     ${WrapVTK_HDRS}
     ${new_vtk_source_code_list}
     #${vtk_SRCS}
     ${vtk_HDRS}
)

WRAP_MESSAGE("WrapVTK_SRCS =  ${WrapVTK_SRCS}")

IF (AMI_USE_PRECOMP_HEADERS)
  IF(MSVC)
    # precompiled header
    SET(WrapVTK_SRCS ${WrapVTK_SRCS} wrap_vtkprec.cpp
    )
  ENDIF(MSVC)
ENDIF(AMI_USE_PRECOMP_HEADERS)

IF (AMI_USE_PRECOMP_HEADERS)
  IF(CMAKE_COMPILER_IS_GNUCXX)
    ADD_PCH_RULE(${AMILAB_SOURCE_DIR}/Wrapping/include/wrap_prec.hpp WrapVTK_SRCS)
    #ADD_PCH_RULE(${AMILAB_SOURCE_DIR}/Common/include/DefineClass.hpp WrapVTK_SRCS)
    #ADD_PCH_RULE(${CMAKE_CURRENT_SOURCE_DIR}/${AMI_WXWIDGETS_VERSION}/wx_includes.h WrapWxWidgets_SRCS)
  ENDIF(CMAKE_COMPILER_IS_GNUCXX )
ENDIF(AMI_USE_PRECOMP_HEADERS)


CONFIGURE_FILE(
    ${AMILab_SOURCE_DIR}/Wrapping/include/WrapVTKConfigure.h.in
    ${AMILab_BINARY_DIR}/WrapVTKConfigure.h)

 
IF(WrapVTK_SHARED)
  set_source_files_properties(${WrapVTK_SRCS} 
    PROPERTIES COMPILE_FLAGS "-DWrapVTK_EXPORTS")
ENDIF(WrapVTK_SHARED)


IF(WrapVTK_SHARED)
  my_add_shared_library ( WrapVTK)
ELSE(WrapVTK_SHARED)
  my_add_library ( WrapVTK)
ENDIF(WrapVTK_SHARED)

# using -fpermissive to be able to wrap the 'long long' type as 'long'
IF(CMAKE_SYSTEM_NAME STREQUAL "Linux" AND CMAKE_COMPILER_IS_GNUCC)
  SET_TARGET_PROPERTIES(WrapVTK PROPERTIES COMPILE_FLAGS "-fPIC -fpermissive")
ENDIF(CMAKE_SYSTEM_NAME STREQUAL "Linux" AND CMAKE_COMPILER_IS_GNUCC)

IF (AMI_USE_PRECOMP_HEADERS)
  # try  precompiled header with visual
  IF(MSVC)
    add_precompiled_header(WrapVTK wrap_vtkprec.hpp SOURCE_CXX wrap_vtkprec.cpp FORCEINCLUDE)
  ENDIF(MSVC )
ENDIF(AMI_USE_PRECOMP_HEADERS)

SET(amilab_ownlibs
  LanguageBase
  CommonBase
  WrapCommon
)

if(VTK_LIBRARIES)
  MESSAGE("VTK_LIBRARIES = ${VTK_LIBRARIES}" )
  SET(LINK_VTK
    ${VTK_LIBRARIES}
   )
else()
  SET(LINK_VTK
    vtkGraphics
    vtkImaging
    #vtkIO
    vtkFiltering
    vtkCommon
    # additional libraries for volume rendering
    vtkRendering 
    vtkVolumeRendering 
    vtkWidgets
    vtkViews
    vtkCharts
  )
endif()

target_link_libraries( WrapVTK
  ${amilab_ownlibs}
  ${LINK_VTK}
  ${Boost_LIBRARIES}
)

IF(MSVC)
  # SET INCREMENTAL LINKING: much faster ...
  set_target_properties( WrapVTK 
    PROPERTIES LINK_FLAGS_RELEASE "/INCREMENTAL:YES")
ENDIF(MSVC)

add_dependencies ( WrapVTK 
    ${amilab_ownlibs}
	)
