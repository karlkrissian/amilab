# Create a library called "Hello" which includes the source file "hello.cxx".
# The extension is already found.  Any number of sources could be listed here.

# Make sure the compiler can find include files from our Hello library.
include_directories (
  ${wxParams_INCLUDE_DIRS}
  ${AMILAB_SOURCE_DIR}
  ${AMILAB_SOURCE_DIR}/Graphic/include
  ${AMILAB_SOURCE_DIR}/Algorithms/include
  ${AMILAB_SOURCE_DIR}/AMILab
)

INCLUDE( ${wxWidgets_USE_FILE})

SET(  WrapWxWidgets_SRCS
  wrap_wxsamples.cpp
  wrap_wxfunctions.cpp
  wrap_wxWindow.cpp
  wrap_wxHtmlWindow.cpp
  wrap_wxSizerItem.cpp
  wrap_wxSize.cpp
  wrap_wxColour.cpp
  wrap_wxImage.cpp
  wrap_wxBitmap.cpp
  wrap_wxString.cpp
  wrap_wxFileName.cpp
  wrap_wxSizer.cpp
  wrap_wxBoxSizer.cpp
  wrap_wxAuiManager.cpp
  wrap_wxAuiPaneInfo.cpp
  wrap_wxPoint.cpp
  wrap_wxRect.cpp
  wrap_wxFrame.cpp
)

SET(WrapWxWidgets_HDRS
  ../include/wrap_wxsamples.h
  ../include/wrap_wxfunctions.h
  ../include/wrap_wxWindow.h
  ../include/wrap_wxHtmlWindow.h
  ../include/wrap_wxSizerItem.h
  ../include/wrap_wxSize.h
  ../include/wrap_wxColour.h
  ../include/wrap_wxImage.h
  ../include/wrap_wxBitmap.h
  ../include/wrap_wxString.h
  ../include/wrap_wxFileName.h
  ../include/wrap_wxSizer.h
  ../include/wrap_wxBoxSizer.h
  ../include/wrap_wxAuiManager.h
  ../include/wrap_wxAuiPaneInfo.h
  ../include/wrap_wxPoint.h
  ../include/wrap_wxRect.h
  ../include/wrap_wxFrame.h
)

SET(WrapWxWidgets_SRCS
     ${WrapWxWidgets_SRCS}
     ${WrapWxWidgets_HDRS}
)

IF (AMI_USE_PRECOM_HEADERS)
  IF(CMAKE_COMPILER_IS_GNUCXX)
    ADD_PCH_RULE(${AMILAB_SOURCE_DIR}/Wrapping/include/WrapWxWidgets_header.h WrapWxWidgets_SRCS)
  ENDIF(CMAKE_COMPILER_IS_GNUCXX )
ENDIF(AMI_USE_PRECOM_HEADERS)


my_add_library ( WrapWxWidgets)
