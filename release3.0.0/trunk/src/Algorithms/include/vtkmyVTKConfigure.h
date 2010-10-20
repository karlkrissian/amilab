/* 
 * Here is where system computed values get stored.
 * These values should only change when the target compile platform changes.
 */

//#define VTKMYVTK_BUILD_SHARED_LIBS

#ifndef VTKMYVTK_BUILD_SHARED_LIBS
  #define VTKMYVTK_STATIC
#endif

#if defined(WIN32) && !defined(VTKMYVTK_STATIC)
  #pragma warning ( disable : 4275 )

  #if defined(vtkLevelSets_EXPORTS)
    #define VTK_MYVTK_EXPORT __declspec( dllexport ) 
  #else
    #define VTK_MYVTK_EXPORT __declspec( dllimport ) 
  #endif
#else
  #define VTK_MYVTK_EXPORT
#endif
