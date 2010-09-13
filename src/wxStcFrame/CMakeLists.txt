
INCLUDE(${wxWidgets_USE_FILE})

include_directories (
  ${wxParams_INCLUDE_DIRS}
  ${AMILAB_SOURCE_DIR}/wxStcFrame
  ${GLEXT_INCLUDE_DIR}
  )


SET(wxStcFrame_SRCS
  wxEditor.cpp
  prefs.cpp
  wxStcFrame.cpp
)

SET(wxStcFrame_HDRS
  defsext.h
  wxEditor.h
  prefs.h
)

SET(wxStcFrame_SRCS
     ${wxStcFrame_SRCS}
     ${wxStcFrame_HDRS}
)

my_add_library ( wxStcFrame)
