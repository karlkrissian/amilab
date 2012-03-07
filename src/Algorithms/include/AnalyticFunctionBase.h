/*
 *  AnalyticFunctionBase.h
 *  AMILab
 */

#ifndef _AnalyticFunctionBase_h_
#define _AnalyticFunctionBase_h_

#include "DefineClass.hpp"

#include "AlgorithmsConfigure.h"



/**
 *  AnalyticFunctionBase class.
 *  @author Karl Krissian (krissian@dis.ulpgc.es)
 *  @author Daniel Elías Santana Cedrés (daniel.santana104@estudiantes.ulpgc.es)
 */
//---------------------------------------------------------------------
class Algorithms_EXPORT AnalyticFunctionBase {
  
  DEFINE_CLASS(AnalyticFunctionBase);
  
public:
  virtual ~AnalyticFunctionBase(){}
  /**
   *  Defines a virtual double operator (). It evaluates a point with  the function
   of the image.
   *  @param Three doubles that represent a point in the image.
   *  @return Zero.
   */  
  virtual double operator () (const double&, const double&, const double&) const
  {
    return 0;
  }
};


#endif