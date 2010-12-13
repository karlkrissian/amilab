# Create a library called "Hello" which includes the source file "hello.cxx".
# The extension is already found.  Any number of sources could be listed here.

INCLUDE( ${wxWidgets_USE_FILE})

include_directories (
  ${wxParams_INCLUDE_DIRS}
  ${AMILAB_SOURCE_DIR}
  ${AMILAB_SOURCE_DIR}/Graphic/include
  ${AMILAB_SOURCE_DIR}/Algorithms/include
  ${AMILAB_SOURCE_DIR}/AMILab
  ${CMAKE_CURRENT_SOURCE_DIR}/${AMI_WXWIDGETS_VERSION}
)



file(GLOB wx_HDRS  "${AMI_WXWIDGETS_VERSION}/*.h"  )
file(GLOB wx_SRCS  "${AMI_WXWIDGETS_VERSION}/*.cpp")

MESSAGE("\nWrapping wxWidgets...\n")
MESSAGE( "AMI_USE_PRECOMP_HEADERS = ${AMI_USE_PRECOMP_HEADERS} ")

IF(NUMBER_SOURCES_TO_PACKAGE EQUAL 1)
  SET(new_wx_source_code_list ${wx_SRCS})
ELSE(NUMBER_SOURCES_TO_PACKAGE EQUAL 1)
  SET(source_path "${AMILAB_SOURCE_DIR}/Wrapping/WrapWxWidgets")
  GenerateSourcesWrapping (new_wx_source_code_list source_path wx_SRCS)
ENDIF(NUMBER_SOURCES_TO_PACKAGE EQUAL 1) 
#MESSAGE("wxWidgets ${AMI_WXWIDGETS_VERSION} wrap files: ${new_source_code_list}\n")

IF (AMI_USE_PRECOMP_HEADERS)
  SET(  WrapWxWidgets_SRCS
    wrap_wxsamples.cpp
    wrap_wxfunctions.cpp
    #${wx_SRCS}
    ${new_wx_source_code_list}
  )
ELSE(AMI_USE_PRECOMP_HEADERS)
  SET(  WrapWxWidgets_SRCS
    wrap_wxsamples.cpp
    wrap_wxfunctions.cpp
    ${new_wx_source_code_list}
  )
ENDIF(AMI_USE_PRECOMP_HEADERS)


SET(WrapWxWidgets_HDRS
  ../include/wrap_wxsamples.h
  ../include/wrap_wxfunctions.h
  ${wx_HDRS}
)


SET(WrapWxWidgets_SRCS
     ${WrapWxWidgets_SRCS}
     ${WrapWxWidgets_HDRS}
)

#MESSAGE("WrapWxWidgets_SRCS = ${WrapWxWidgets_SRCS}")

IF (AMI_USE_PRECOMP_HEADERS)
  IF(CMAKE_COMPILER_IS_GNUCXX)
    ADD_PCH_RULE(${CMAKE_CURRENT_SOURCE_DIR}/${AMI_WXWIDGETS_VERSION}/wx_includes.h WrapWxWidgets_SRCS)
  ENDIF(CMAKE_COMPILER_IS_GNUCXX )
ENDIF(AMI_USE_PRECOMP_HEADERS)


my_add_library ( WrapWxWidgets)
