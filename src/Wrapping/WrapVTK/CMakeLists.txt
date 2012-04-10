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

INCLUDE( ${USE_VTK_FILE} )
INCLUDE( ${USE_ITK_FILE} )
#INCLUDE( ${VTK_USE_FILE} )
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

  # Read list of classes to wrap
  READ_CLASSES2(
    "${CMAKE_CURRENT_SOURCE_DIR}/classes_common.txt"
    "${CMAKE_CURRENT_SOURCE_DIR}/${AMI_VTK_VERSION}/classes.txt"
  ) 
  #MESSAGE("classes.txt : ${CMAKE_CURRENT_SOURCE_DIR}/${AMI_VTK_VERSION}/classes.txt")

  SET(WRAPPING_DIR ${CMAKE_CURRENT_SOURCE_DIR})

  #------------------------------------------------------------
  # Generating and reading ancestors
  #------------------------------------------------------------

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

#   #MESSAGE("Processing classes ${ancestors_list} and addwrap")
#   IF ((${NB_MISSING_CLASSES} GREATER 0) OR 
#       (NOT EXISTS ${GENERATED_DIR}/addwrap_vtk.h) OR
#       (NOT EXISTS ${GENERATED_DIR}/addwrap_vtk.cpp))
#     # Go for python wrapping
#     IF(GENERATE_HTML_HELP)
#       ADD_CUSTOM_COMMAND(
#         OUTPUT  ${OUTPUT_LIST} ${GENERATED_DIR}/addwrap_vtk.h ${GENERATED_DIR}/addwrap_vtk.cpp
#         COMMAND
#             ${PYTHON_EXECUTABLE}
#               ${AMI_WRAPPER} ${XML_OUTPUT}
#               --libname vtk
#               --filter "vtk*"
#               --classes ${MISSING_CLASSES}
#               --constructor New
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
#         OUTPUT  ${OUTPUT_LIST} ${GENERATED_DIR}/addwrap_vtk.h ${GENERATED_DIR}/addwrap_vtk.cpp
#         COMMAND
#           ${PYTHON_EXECUTABLE}
#             ${AMI_WRAPPER} ${XML_OUTPUT}
#             --libname vtk
#             --filter "vtk*"
#             --classes ${MISSING_CLASSES}
#             --constructor New
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
#       (NOT EXISTS ${GENERATED_DIR}/addwrap_vtk.h) OR
#       (NOT EXISTS ${GENERATED_DIR}/addwrap_vtk.cpp))

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


IF(CMAKE_SYSTEM_NAME STREQUAL "Linux" AND CMAKE_COMPILER_IS_GNUCC)
  SET_TARGET_PROPERTIES(WrapVTK PROPERTIES COMPILE_FLAGS -fPIC)
ENDIF(CMAKE_SYSTEM_NAME STREQUAL "Linux" AND CMAKE_COMPILER_IS_GNUCC)

SET(amilab_ownlibs
  LanguageBase
  CommonBase
  WrapCommon
)
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
