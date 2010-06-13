
include_directories (
  ${AMILAB_SOURCE_DIR}/wxCode/wxTreeListCtrl
  )

INCLUDE(${wxWidgets_USE_FILE})

SET(wxTreeListCtrl_SRCS
  treelistctrl.cpp
)

SET(wxTreeListCtrl_HDRS
  treelistctrl.h
)

SET(wxTreeListCtrl_SRCS
     ${wxTreeListCtrl_SRCS}
     ${wxTreeListCtrl_HDRS}
)

my_add_library ( wxTreeListCtrl)
