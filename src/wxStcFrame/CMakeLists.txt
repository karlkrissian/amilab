
include_directories (
  ${AMILAB_SOURCE_DIR}/wxStcFrame
  ${GLEXT_INCLUDE_DIR}
  )

INCLUDE(${wxWidgets_USE_FILE})

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
