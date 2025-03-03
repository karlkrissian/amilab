/* 
 * Here is where system computed values get stored.
 * These values should only change when the target compile platform changes.
 */

//#define VTKLEVELSETS_BUILD_SHARED_LIBS

#ifndef VTKLEVELSETS_BUILD_SHARED_LIBS
  #define VTKLEVELSETS_STATIC
#endif

#if defined(WIN32) && !defined(VTKLEVELSETS_STATIC)
  //#pragma warning ( disable : 4275 )

  #if defined(vtkLevelSets_EXPORTS)
    #define VTK_LEVELSETS_EXPORT __declspec( dllexport ) 
  #else
    #define VTK_LEVELSETS_EXPORT __declspec( dllimport ) 
  #endif
#else
  #define VTK_LEVELSETS_EXPORT
#endif
