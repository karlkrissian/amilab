
include_directories (
  ${AMILAB_SOURCE_DIR}/CommonBase
  ${AMILAB_SOURCE_DIR}/Common/include
  ${AMILAB_SOURCE_DIR}/Graphic/wxVTK
)

INCLUDE(${wxWidgets_USE_FILE})
INCLUDE( ${VTK_USE_FILE} )

#
# wxVTK stuff ...
#
# The following allows you to access wxGLCanvas for GTK
IF(WIN32)
  SET(GUI_EXECUTABLE WIN32)
ELSE(WIN32)
  IF(APPLE)
    SET(GUI_EXECUTABLE MACOSX_BUNDLE)
    IF(VTK_USE_COCOA)
      SET_SOURCE_FILES_PROPERTIES(
        src/wxVTKRenderWindowInteractor.cxx
        PROPERTIES COMPILE_FLAGS "-ObjC++")
    ENDIF(VTK_USE_COCOA)
  ELSE(APPLE)
    # Ok X11 for sure, but just check:
    IF(NOT VTK_USE_X)
      MESSAGE(FATAL_ERROR "You need to have VTK_USE_X")
    ENDIF(NOT VTK_USE_X)

#     # CMake 2.6:
#     # technically those packages are not required since one can still use the Motif/X11 version and not the gtk one:
#     FIND_PACKAGE(PkgConfig)
#     pkg_check_modules (GTK2 gtk+-2.0)
#     #MESSAGE("${GTK2_INCLUDE_DIRS}")
#     INCLUDE_DIRECTORIES(${GTK2_INCLUDE_DIRS})
#     LINK_LIBRARIES(${GTK2_LIBRARIES})
#     # Can I require all my user to have the gl lib on linux, even if they do not really need it...
#     #SET(WXGLCANVASLIBS "gl")
  ENDIF(APPLE)
ENDIF(WIN32)

SET(wxVTKSmaples_HDRS
  wxMedical3Frame.h
  wxVTKFrame.h
)

SET(wxVTKSamples_SRCS
  wxMedical3.cxx
  wxVTKFrame.cxx
  ${wxVTKSamples_HDRS}
)

my_add_library ( wxVTKSamples)
