
include_directories (
  ${AMILAB_SOURCE_DIR}/Graphic/include
  )

INCLUDE(${wxWidgets_USE_FILE})

SET(wxTreeListCtrl_SRCS
  treelistctrl.cpp
)

SET(wxTreeListCtrl_HDRS
  ../../include/treelistctrl.h
)

SET(wxTreeListCtrl_SRCS
     ${wxTreeListCtrl_SRCS}
     ${wxTreeListCtrl_HDRS}
)

my_add_library ( wxTreeListCtrl)
