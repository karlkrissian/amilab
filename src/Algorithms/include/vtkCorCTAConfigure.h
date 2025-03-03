/* 
 * Here is where system computed values get stored.
 * These values should only change when the target compile platform changes.
 */

//#define VTKCORCTA_BUILD_SHARED_LIBS

#ifndef VTKCORCTA_BUILD_SHARED_LIBS
  #define VTKCORCTA_STATIC
#endif

#if defined(WIN32) && !defined(VTKCORCTA_STATIC)
  //#pragma warning ( disable : 4275 )

  #if defined(vtkCorCTA_EXPORTS)
    #define VTK_CORCTA_EXPORT __declspec( dllexport ) 
  #else
    #define VTK_CORCTA_EXPORT __declspec( dllimport ) 
  #endif
#else
  #define VTK_CORCTA_EXPORT
#endif
