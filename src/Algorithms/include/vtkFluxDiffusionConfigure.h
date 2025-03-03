/* 
 * Here is where system computed values get stored.
 * These values should only change when the target compile platform changes.
 */

//#define VTKFLUXDIFFUSION_BUILD_SHARED_LIBS

#ifndef VTKFLUXDIFFUSION_BUILD_SHARED_LIBS
  #define VTKFLUXDIFFUSION_STATIC
#endif

#if defined(WIN32) && !defined(VTKFLUXDIFFUSION_STATIC)
//#pragma warning ( disable : 4275 )

#if defined(vtkFluxDiffusion_EXPORTS)
  #define VTK_FLUXDIFFUSION_EXPORT __declspec( dllexport ) 
  #else
    #define VTK_FLUXDIFFUSION_EXPORT __declspec( dllimport ) 
  #endif
#else
  #define VTK_FLUXDIFFUSION_EXPORT
#endif
