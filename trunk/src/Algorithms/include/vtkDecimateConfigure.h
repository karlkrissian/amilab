/* 
 * Here is where system computed values get stored.
 * These values should only change when the target compile platform changes.
 */

#define VTKDECIMATE_BUILD_SHARED_LIBS
#ifndef VTKDECIMATE_BUILD_SHARED_LIBS
#define VTKDECIMATE_STATIC
#endif

#if defined(WIN32) && !defined(VTKDECIMATE_STATIC)
#pragma warning ( disable : 4275 )

#if defined(vtkLevelSets_EXPORTS)
#define VTK_DECIMATE_EXPORT __declspec( dllexport ) 
#else
#define VTK_DECIMATE_EXPORT __declspec( dllimport ) 
#endif
#else
#define VTK_DECIMATE_EXPORT
#endif
