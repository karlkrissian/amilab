/* 
 * Here is where system computed values get stored.
 * These values should only change when the target compile platform changes.
 */

#define VTKCONVEXHULL_BUILD_SHARED_LIBS
#ifndef VTKCONVEXHULL_BUILD_SHARED_LIBS
#define VTKCONVEXHULL_STATIC
#endif

#if defined(WIN32) && !defined(VTKCONVEXHULL_STATIC)
#pragma warning ( disable : 4275 )

#if defined(vtkConvexhull_EXPORTS)
#define VTK_CONVEXHULL_EXPORT __declspec( dllexport ) 
#else
#define VTK_CONVEXHULL_EXPORT __declspec( dllimport ) 
#endif
#else
#define VTK_CONVEXHULL_EXPORT
#endif
