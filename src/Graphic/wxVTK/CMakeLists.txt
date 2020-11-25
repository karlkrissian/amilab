
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
    #IF(NOT VTK_USE_X)
    #  MESSAGE(FATAL_ERROR "You need to have VTK_USE_X")
    #ENDIF(NOT VTK_USE_X)


    # this for GTK3
#     # Use the package PkgConfig to detect GTK+ headers/library files
#     FIND_PACKAGE(PkgConfig REQUIRED)
#     PKG_CHECK_MODULES(GTK3 REQUIRED gtk+-3.0)
#     # Setup CMake to use GTK+, tell the compiler where to look for headers
#     # and to the linker where to look for libraries
#     MESSAGE("GTK3_INCLUDE_DIRS=${GTK3_INCLUDE_DIRS}")
#     INCLUDE_DIRECTORIES(${GTK3_INCLUDE_DIRS})
#     LINK_DIRECTORIES(${GTK3_LIBRARY_DIRS})
#     # Add other flags to the compiler
#     ADD_DEFINITIONS(${GTK3_CFLAGS_OTHER})

    # this for GTK2
    # CMake 2.6:
    # technically those packages are not required since one can still use the Motif/X11 version and not the gtk one:
    FIND_PACKAGE(PkgConfig)
    pkg_check_modules (GTK2 gtk+-2.0)
    #pkg_check_modules (GTK3 gtk+-3.0)
    #MESSAGE("${GTK2_INCLUDE_DIRS}")
    INCLUDE_DIRECTORIES(${GTK2_INCLUDE_DIRS})
    LINK_LIBRARIES(${GTK2_LIBRARIES})
    # Can I require all my user to have the gl lib on linux, even if they do not really need it...
    #SET(WXGLCANVASLIBS "gl")
  ENDIF(APPLE)
ENDIF(WIN32)

SET(wxVTK_HDRS
   wxVTKRenderWindowInteractor.h
)

SET(wxVTK_SRCS
   wxVTKRenderWindowInteractor.cxx
   ${wxVTK_HDRS}
)

my_add_library ( wxVTK)
