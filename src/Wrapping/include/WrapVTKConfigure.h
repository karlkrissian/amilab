#pragma once
#ifndef _WrapVTKConfigure_h_
#define _WrapVTKConfigure_h_

#if defined(WIN32)
  //disable warnings on extern before template instantiation
  #pragma warning (disable : 4231)
  // annoying warning 4251, passing for now ...
  #pragma warning (disable : 4251)
#endif

#define WrapVTK_SHARED
#if defined(WIN32) && defined(WrapVTK_SHARED)
  //#pragma warning ( disable : 4275 )
  #if defined(WrapVTK_EXPORTS)
    #define WrapVTK_EXPORT __declspec( dllexport ) 
    #define WrapVTK_EXPIMP_TEMPLATE
  #else
    #define WrapVTK_EXPORT __declspec( dllimport ) 
    #define WrapVTK_EXPIMP_TEMPLATE extern
  #endif
#else
  #define WrapVTK_EXPORT 
#endif

#if defined(WIN32) && defined(WrapVTK_SHARED)
  //#pragma warning ( disable : 4275 )
  #if defined(WrapVTK_EXPORTS)
    #define WrapVTK_VAR_EXPORT __declspec( dllexport ) 
    #define WrapVTK_VAR_IMPORT __declspec( dllexport ) extern
  #else
    #define WrapVTK_VAR_EXPORT 
    #define WrapVTK_VAR_IMPORT __declspec( dllimport ) 
  #endif
#else
  #define WrapVTK_VAR_EXPORT 
  #define WrapVTK_VAR_IMPORT extern
#endif


#endif // _WrapVTKConfigure_h_
