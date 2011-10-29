//
// C++ Interface: ComputePartialVolume
//
// Description: Estimate the partial volume creating an image
//  between 0 and 1 (0 for negative intensity values, 1 for positive values)
//
// Author:  <Karl Krissian>, (C) 2009
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _ComputePartialVolume_h_
#define _ComputePartialVolume_h_

#include "DefineClass.hpp"
#include "inrimage.hpp"
#include "AnalyticFunctionBase.h"

/**
 *  ComputePartialVolume class.
 *  @author Karl Krissian (krissian@dis.ulpgc.es)
 */
//---------------------------------------------------------------------
class ComputePartialVolume {
  
  DEFINE_CLASS(ComputePartialVolume);
  
private:
  //Subdivision level
  int subdiv;
  //Analytic function
  AnalyticFunctionBase::wptr analyticfunc;
  //Input image
  InrImage::wptr input;
  //Iterative method
  int resolution;
  
protected:
  /**
   *  Compute recursively the partial effect on an analytic surface.
   *  @param val[4] Subdivisions values.
   *  @param subvols[4] Return value.
   *  @param size Pixel size.
   *  @param subdiv_level Subdivision level.
   *  @param x pixel position.
   *  @param y pixel position.
   *  @return The pixel region value
   */
  double AnalyticRecursivePositiveSurface( double val[4], double subvols[4], 
                                           double size, int subdiv_level,
                                           double x, double y);
  
  /**
   *  Compute recursively the partial effect on an analytic volume.
   *  @param val[8] Subdivisions values.
   *  @param subvols[8] Return value.
   *  @param size Voxel size.
   *  @param subdiv_level Subdivision level.
   *  @param x Voxel position.
   *  @param y Voxel position.
   *  @param z Voxel position.
   *  @return double The voxel region value.
   */
  double AnalyticRecursivePositiveVolume( double val[8], double subvols[8], 
                                          double size, int subdiv_level,
                                          double x, double y, double z);
  
  /**
   *  Compute recursively the partial effect on volume with linear interpolation.
   *  @param val[8] Subdivisions values.
   *  @param subvols[8] Return value.
   *  @param volume Volume size.
   *  @param subdiv_level Subdivision level.
   *  @return double The voxel region value.
   */
  double RecursivePositiveVolume( double val[8], double subvols[8], 
                                  double volume, int subdiv_level );
  
public:
  /**
   *  Creates a ComputePartialVolume object. Sets subdivision level at 2, resolution at 3,
   *  f and input at NULL.
   */
  ComputePartialVolume()
  {
    subdiv       = 2;
//    analyticfunc = NULL;
//    input        = NULL;
    resolution   = 3;
  }
  
  virtual ~ComputePartialVolume(){}
  
  //Analytic functions
  /**
   *  Computes the analytic partial surface subdivision.
   *  @return InrImage* A pointer to an InrImage object.
   */
  InrImage::ptr ComputeAnalyticPartialSurfaceSubdiv(float ipos, float ineg);
  
  /**
   *  Computes the analytic partial volume subdivision.
   *  @return InrImage* A pointer to an InrImage object.
   */
  InrImage::ptr RunAnalyticSubdiv(float ipos, float ineg);

  //Linear interpolation functions
  /**
   *  Compute partial volume iteratively.
   *  @return InrImage* A pointer to an InrImage object.
   */
  InrImage::ptr Run();
  
  /**
   *  Compute partial volume (linear interpolation).
   *  @return InrImage* A pointer to an InrImage object.
   */
  InrImage::ptr RunSubdiv();
  
  //Get and set methods
  /**
   *  Set subdivision level.
   *  @param s Subdivison level value.
   */
  void setSubdiv(int s);
  
  /**
   *  Get subdivision level.
   *  @return int Subdivision level value.
   */
  int  getSubdiv();
  
  /**
   *  Set the analytic function.
   *  @param fun A pointer to an AnalyticFunctionBase object.
   */
  void setAnalyticFunction(AnalyticFunctionBase::ptr fun);
  
  /**
   *  Gets the analytic function.
   *  @return AnalyticFunctionBase* A pointer to an AnalyticFunctionBase object.
   */
  AnalyticFunctionBase::wptr getAnalyticFunction();
  
  /**
   *  Set input image.
   *  @param i A pointer to an InrImage object.
   */
  void setInputImage(InrImage::ptr input_image);
  
  /**
   *  Get the input image.
   *  @return InrImage* A pointer to the InrImage input image.
   */
  InrImage::wptr getInputImage();
  
  /**
   *  Set the resolution.
   *  @param r The resolution value.
   */
  void setResolution(int resol);
  
  /**
   *  Get the resoltion.
   *  @return int The resolution value.
   */
  int getResolution();
  
};

#endif // _ComputePartialVolume_h_
