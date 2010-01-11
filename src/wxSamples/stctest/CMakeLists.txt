
include_directories (
  ${AMILAB_SOURCE_DIR}/wxSamples/stctest
  ${GLEXT_INCLUDE_DIR}
  )

INCLUDE(${wxWidgets_USE_FILE})

SET(stctest_SRCS
  edit.cpp
  prefs.cpp
  stctest.cpp
)

SET(stctest_HDRS
	defsext.h
	edit.h
	prefs.h
)

SET(stctest_SRCS
     ${stctest_SRCS}
     ${stctest_HDRS}
)

my_add_library ( stctest)
