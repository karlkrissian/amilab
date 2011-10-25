
#ifndef _AlgorithmsConfigure_h_
#define _AlgorithmsConfigure_h_

#if defined(WIN32)
  //disable warnings on extern before template instantiation
  #pragma warning (disable : 4231)
  // annoying warning 4251, passing for now ...
  #pragma warning (disable : 4251)
#endif

//#define Algorithms_SHARED
#if defined(WIN32) && defined(Algorithms_SHARED)
  //#pragma warning ( disable : 4275 )
  #if defined(Algorithms_EXPORTS)
    #define Algorithms_EXPORT __declspec( dllexport ) 
    #define Algorithms_EXPIMP_TEMPLATE
  #else
    #define Algorithms_EXPORT __declspec( dllimport ) 
    #define Algorithms_EXPIMP_TEMPLATE extern
  #endif
#else
  #define Algorithms_EXPORT 
#endif

#if defined(WIN32) && defined(Algorithms_SHARED)
  //#pragma warning ( disable : 4275 )
  #if defined(Algorithms_EXPORTS)
    #define Algorithms_VAR_EXPORT __declspec( dllexport ) 
    #define Algorithms_VAR_IMPORT __declspec( dllexport ) extern
  #else
    #define Algorithms_VAR_IMPORT __declspec( dllimport ) 
  #endif
#else
  #define Algorithms_VAR_EXPORT 
  #define Algorithms_VAR_IMPORT extern
#endif


#endif // _AlgorithmsConfigure_h_
