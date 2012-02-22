//
// C++ Interface: amiPDESolver
//
// Description: 
//
//
// Author:  <Karl Krissian>, (C) 2009
//
// Copyright: See COPYING file that comes with this distribution
//
//

#pragma once
#ifndef _ami_PDESolver_h_
#define _ami_PDESolver_h_

#include "amiImageToImageFilter.h"



namespace ami {

  #define AddSetGetVar( name, type) \
  type  name; \
  void Set##name( const type& _arg) \
  { \
    this->name = _arg; \
  };  \
  type Get##name() \
  { \
    return this->name; \
  };


  /**
   * 
   */
  class PDESolverParam 
  {
    public:

      /// Equation time step
      AddSetGetVar(dt, double)

      /// Number of iterations
      AddSetGetVar(NbIterations, int)
      
      PDESolverParam() {
        dt=0.05;
        NbIterations=5;
      }

  }; // PDESolverParam;


  /**
  * 
  */
  class PDESolver : public ImageToImageFilter
  {

    protected:
      PDESolverParam PDESolver_params;
      typedef ImageExtent<int> extenttype;
      std::vector<extenttype> extents;

    public:

      PDESolver() {}
      ~PDESolver() {}

      void SetPDESolverParameters( const PDESolverParam& p)
      {
        PDESolver_params = p;
      }

      PDESolverParam& GetDPESolverParameters( )
      {
        return PDESolver_params;
      }

      virtual void Init();

      virtual void Process( int threadid = 0) = 0;

      virtual void Run();

      virtual void Close() {}

  }; // PDESolver

} // namespace ami

#endif // _ami_PDESolver_h_
