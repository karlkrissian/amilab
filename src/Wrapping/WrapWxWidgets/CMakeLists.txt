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

MESSAGE("Wrapping wxWidgets...")


SET(source_path "${AMILAB_SOURCE_DIR}/Wrapping/WrapWxWidgets")
GenerateSourcesWrapping (new_source_code_list source_path wx_SRCS)

#MESSAGE("wxWidgets ${AMI_WXWIDGETS_VERSION} wrap files: ${new_source_code_list}\n")

SET(  WrapWxWidgets_SRCS
  wrap_wxsamples.cpp
  wrap_wxfunctions.cpp
  ${new_source_code_list}
  #${wx_SRCS}
)


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

IF (AMI_USE_PRECOM_HEADERS)
  IF(CMAKE_COMPILER_IS_GNUCXX)
    ADD_PCH_RULE(${AMILAB_SOURCE_DIR}/Wrapping/include/WrapWxWidgets_header.h WrapWxWidgets_SRCS)
  ENDIF(CMAKE_COMPILER_IS_GNUCXX )
ENDIF(AMI_USE_PRECOM_HEADERS)


my_add_library ( WrapWxWidgets)
