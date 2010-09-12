# Create a library called "Hello" which includes the source file "hello.cxx".
# The extension is already found.  Any number of sources could be listed here.

# Make sure the compiler can find include files from our Hello library.
include_directories (
  ${AMILAB_SOURCE_DIR}/Common
  ${AMILAB_SOURCE_DIR}/Graphic/include
  ${AMILAB_SOURCE_DIR}/Algorithms/include
  ${AMILAB_SOURCE_DIR}/Wrapping/WrapCommon
  ${AMILAB_SOURCE_DIR}/Wrapping/WrapBasicTypes
  ${AMILAB_SOURCE_DIR}/wxStcFrame
  ${AMILAB_SOURCE_DIR}/wxCode/wxTreeListCtrl
  ${AMILAB_SOURCE_DIR}/Wrapping/WrapWxWidgets
  ${AMILAB_SOURCE_DIR}
  ${Boost_INCLUDE_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${PTHREADS_INCLUDE_DIR}
)

INCLUDE( ${wxWidgets_USE_FILE})

SET(  WrapInterface_SRCS
  wrap_MainFrame.cpp
#  wrap_imagedraw.cpp 
  wrap_parampanel.cpp 
  wrap_wxDrawingWindow.cpp 
  wrap_wxEditor.cpp 
  wrap_wxStcFrame.cpp 
  wrap_FenetreDessin.cpp 
  wrap_dwControlPoint.cpp
  wrap_dwPoint2D.cpp
  wrap_dwCurve.cpp
  wrap_dwControlledCurve.cpp
)

SET(WrapInterface_HDRS
  wrap_MainFrame.h
#  wrap_imagedraw.h
  wrap_parampanel.h 
  wrap_wxDrawingWindow.h
  wrap_wxEditor.h
  wrap_wxStcFrame.h 
  wrap_FenetreDessin.h
  wrap_dwControlPoint.h
  wrap_dwPoint2D.h
  wrap_dwCurve.h
  wrap_dwControlledCurve.h
)

SET(WrapInterface_SRCS
     ${WrapInterface_SRCS}
     ${WrapInterface_HDRS}
)

my_add_library ( WrapInterface)
