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


/**
 *  AnalyticFunctionBase class.
 *  @author Karl Krissian (krissian@dis.ulpgc.es)
 *  @author Daniel Elías Santana Cedrés (daniel.santana104@estudiantes.ulpgc.es)
 */
//---------------------------------------------------------------------
class AnalyticFunctionBase {
  
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

/**
 *  AnalyticCircle class.
 *  @author Karl Krissian (krissian@dis.ulpgc.es)
 *  @author Daniel Elías Santana Cedrés (daniel.santana104@estudiantes.ulpgc.es)
 */
class AnalyticCircle : public AnalyticFunctionBase {
  
  DEFINE_CLASS(AnalyticCircle);
  
private:
  //Center of the circle
  float center[2];
  //Radius of the circle
  float radius;
  
public:
  /**
   *  Creates an analytic circle.
   *  @param x Component of the center. Default 50.
   *  @param y Component of the center. Default 50.
   *  @param r Radius of the circle. Default 20.
   */
  AnalyticCircle(float x = 50, float y = 50, float r = 20);
  
  ~AnalyticCircle();
  
  /**
   *  Operator () redefinition. Evaluates if a point is inside the circle.
   *  @param x Component of the point.
   *  @param y Component of the point.
   *  @param z Unused.
   *  @return double A double number that represents the value of the point in
   *  the circle image.
   */
  double operator () (const double& x, const double& y, const double& z) const;
  
  /**
   *  Set the center of the circle.
   *  @param c1 X component of the center.
   *  @param c2 Y component of the center.
   */
  void setCenter(float c1, float c2);
  
  /**
   *  Get the center of the circle.
   *  @return float* A pointer to a vector with the center value.
   */
  float* getCenter();
  
  /**
   *  Set the radius of the circle.
   *  @param r The value of the radius.
   */
  void setRadius(float r);
  
  /**
   *  Get the radius of the circle.
   *  @return float The radius value.
   */
  float getRadius();
};

/**
 *  AnalyticLine class.
 *  @author Karl Krissian (krissian@dis.ulpgc.es)
 *  @author Agustín Trujillo Pino (agustin@dis.ulpgc.es)
 *  @author Daniel Elías Santana Cedrés (daniel.santana104@estudiantes.ulpgc.es)
 */
class AnalyticLine : public AnalyticFunctionBase {
  
  DEFINE_CLASS(AnalyticLine);
  
private:
  /** Normal of the line, cut point on 'y' axis and angle */
  float m[2], _n, angle;
  
public:
  /**
   *  Creates an analytic line.
   *  @param angle Line angle. Default 45.0.
   *  @param n Cut point value. Default 50.0.
   */
  AnalyticLine(float angle = 45.0, float n = 50.0);
  
  ~AnalyticLine();
  
  /**
   *  Operator () redefinition. Evaluates if a point is inside the line.
   *  @param x Component of the point.
   *  @param y Component of the point.
   *  @param z Unused.
   *  @return double A double number that represents the value of the point in the
   *  line image.
   */
  double operator () (const double& x, const double& y, const double& z) const;
  
  /**
   *  Set line angle.
   *  @param alpha The new angle value.
   */
  void setAngle(float alpha);
  
  /**
   *  Get line normal.
   *  @return float The value of the angle.
   */
  float getAngle();
  
  /**
   *  Set y axis cut point value.
   *  @param n Point value on y axis.
   */
  void set_n(float n);
  
  /**
   *  Get y axis cut point value.
   *  @return float The cut point value.
   */
  float get_n();
};

/**
 *  AnalyticStraightVessel2D class.
 *  @author Karl Krissian (krissian@dis.ulpgc.es)
 *  @author Agustín Trujillo Pino (agustin@dis.ulpgc.es)
 *  @author Daniel Elías Santana Cedrés (daniel.santana104@estudiantes.ulpgc.es)
 */
class AnalyticStraightVessel2D : public AnalyticFunctionBase {
  DEFINE_CLASS(AnalyticStraightVessel2D);

private:
  //Center of the vessel
  float center[2];
  //Thickness
  float thickness;
  //Angle 
  float angle;
  //Components of the normal
  double nx;
  double ny;

public:
  /**
   *  Creates a 2D analytic straight vessel.
   *  @param x Component of the center. Default 50.0.
   *  @param y Component of the center. Default 50.0.
   *  @param g Thickness of the vessel. Default 4.0.
   *  @param alpha Angle of the vessel. Default 20.0.
   */
  AnalyticStraightVessel2D(float x = 50.0, float y = 50.0, float g = 4.0, 
                           float alpha = 20.0);
  
  ~AnalyticStraightVessel2D();

  /**
   *  Operator () redefinition. Evaluates if a point is inside the vessel.
   *  @param x Component of the point.
   *  @param y Component of the point.
   *  @param z Unused.
   *  @return double A double number that represents the value of the point in the
   *  vessel image.
   */
  double operator () (const double& x, const double& y, const double& z) const;
  
  /**
   *  Get the center of the vessel.
   *  @return float* A pointer to a float vector with the two components of the
   *  center.
   */
  float* getCenter();
  
  /**
   *  Set the center of the vessel.
   *  @param x Component of the center.
   *  @param y Component of the center.
   */
  void setCenter(float x, float y);
  
  /**
   *  Get the thickness of the vessel.
   *  @return float The value of the thickness.
   */
  float getThickness();
  
  /**
   *  Set the thickness of the vessel.
   *  @param g The new thickness value.
   */
  void setThickness(float g);
  
  /**
   *  Get the angle of the vessel.
   *  @return float The value of the angle.
   */
  float getAngle();
  
  /**
   *  Set the angle of the vessel.
   *  @param alpha The new value of the angle.
   */
  void setAngle(float alpha);
};

/**
 *  AnalyticRing2D class.
 *  @author Karl Krissian (krissian@dis.ulpgc.es)
 *  @author Agustín Trujillo Pino (agustin@dis.ulpgc.es)
 *  @author Daniel Elías Santana Cedrés (daniel.santana104@estudiantes.ulpgc.es)
 */
class AnalyticRing2D : public AnalyticFunctionBase {
  //Ash Nazg durbatulûk, ash Nazg gimbatul, 
  //ash Nazg thrakatulûk agh burzum-ishi krimpatul
  DEFINE_CLASS(AnalyticRing2D);
  
private:
  //Center
  float center[2];
  //Central radius
  float radius;
  //Thickness of the ring
  float thickness;
  
public:
  /**
   *  Creates a 2D analytic ring.
   *  @param x Component of the center. Default 50.0.
   *  @param y Component of the center. Default 50.0.
   *  @param r Central radius. Default 30.0.
   *  @param g Thickness of the ring. Default 2.0.
   */
  AnalyticRing2D(float x = 50.0, float y = 50.0, float r = 30.0, float g = 2.0);
  
  ~AnalyticRing2D();

  /**
   *  Operator () redefinition. Evaluates if a point is inside the ring.
   *  @param x Component of the point.
   *  @param y Component of the point.
   *  @param z Unused.
   *  @return double A double number that represents the value of the point in the
   *  ring image.
   */
  double operator () (const double& x, const double& y, const double& z) const;
  
  /**
   *  Get the center of the ring.
   *  @return float* A pointer to a float vector with the two components of the
   *  center.
   */
  float* getCenter();
  
  /**
   *  Set the center of the ring.
   *  @param x Component of the center.
   *  @param y Component of the center.
   */
  void setCenter(float x, float y);
  
  /**
   *  Get the central radius of the ring.
   *  @return float The value of the radius.
   */
  float getRadius();
  
  /**
   *  Set the central radius of the ring.
   *  @param r The new value for the radius.
   */
  void setRadius(float r);
  
  /**
   *  Get the thickness of the ring.
   *  @return float The value of the thickness.
   */
  float getThickness();
  
  /**
   *  Set the thickness of the ring.
   *  @param g The new value for the thickness.
   */
  void setThickness(float g);
  
};

/**
 *  AnalyticSphere class.
 *  @author Karl Krissian (krissian@dis.ulpgc.es)
 *  @author Daniel Elías Santana Cedrés (daniel.santana104@estudiantes.ulpgc.es)
 */
class AnalyticSphere : public AnalyticFunctionBase {
  
  DEFINE_CLASS(AnalyticSphere);
  
private:
  //The center of the sphere
  float center[3];
  //Radius
  float radius;
  
public:
  /**
   *  Creates an analytic sphere.
   *  @param x Component of the center. Default 50.
   *  @param y Component of the center. Default 50.
   *  @param z Component of the center. Default 50.
   *  @param r Radius. Default 20.
   */
  AnalyticSphere(float x = 50, float y = 50, float z = 50, float r = 20);
  
  ~AnalyticSphere();
  
  /**
   *  Operator () redefinition. Evaluates if a point is inside the sphere.
   *  @param x Component of the point.
   *  @param y Component of the point.
   *  @param z Component of the point.
   *  @return double A double number that represents the value of the point in
   *  the sphere image.
   */
  double operator () (const double& x, const double& y, const double& z) const;
  
  /**
   *  Set the center of the sphere.
   *  @param c1 X component of the center.
   *  @param c2 Y component of the center.
   *  @param c3 Z component of the center.
   */
  void setCenter(float c1, float c2, float c3);
  
  /**
   *  Get the center of the sphere.
   *  @return float* A pointer to a vector with the center value.
   */
  float* getCenter();
  
  /**
   *  Set the radius of the sphere.
   *  @param r The new radius value.
   */
  void setRadius(float r);
  
  /**
   *  Get the radius of the sphere.
   *  @return float The radius value.
   */
  float getRadius();
};

/**
 *  AnalyticTorus class.
 *  @author Karl Krissian (krissian@dis.ulpgc.es)
 *  @author Daniel Elías Santana Cedrés (daniel.santana104@estudiantes.ulpgc.es)
 */
class AnalyticTorus : public AnalyticFunctionBase {
  
  DEFINE_CLASS(AnalyticTorus);
  
private:
  //The center of the torus
  float center[3];
  // Minimum radius
  float rmin;
  // Maximum radius
  float rmax;
public:
  /**
   *  Creates an analytic torus.
   *  @param x Component of the center. Default 50.
   *  @param y Component of the center. Default 50.
   *  @param z Component of the center. Default 50.
   *  @param r Minimum radius. Default 3.
   *  @param R Maximum radius. Default 20.
   */
  AnalyticTorus(float x = 50, float y = 50, float z = 50,
                float r = 3, float R = 20);
  
  ~AnalyticTorus();
  
  /**
   *  Operator () redefinition. Evaluates if a point is inside the torus.
   *  @param x Component of the point.
   *  @param y Component of the point.
   *  @param z Component of the point.
   *  @return double A double number that represents the value of the point in
   *  the torus image.
   */
  double operator () (const double& x, const double& y, const double& z) const;
  
  /**
   *  Set the center of the torus.
   *  @param c1 X component of the center.
   *  @param c2 Y component of the center.
   *  @param c3 Z component of the center.
   */
  void setCenter(float c1, float c2, float c3);
  
  /**
   *  Get the center of the torus.
   *  @return float* A pointer to a vector with the center value.
   */
  float* getCenter();
  
  /**
   *  Set the minimum radius of the torus.
   *  @param rm The new minimum radius value.
   */
  void set_rmin(float rm);
  
  /**
   *  Get the minimum radius of the torus.
   *  @return float The minimum radius value.
   */
  float get_rmin();
  
  /**
   *  Set the maximum radius of the torus.
   *  @param rM The new maximum radius value.
   */
  void set_rmax(float rM);
  
  /**
   *  Get the maximum radius of the torus.
   *  @return float The maximum radius value.
   */
  float get_rmax();
};

/**
 *  ComputePV class.
 *  @author Karl Krissian (krissian@dis.ulpgc.es)
 */
//---------------------------------------------------------------------
class ComputePV {
  
  DEFINE_CLASS(ComputePV);
  
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
   *  Creates a ComputePV object. Sets subdivision level at 2, resolution at 3,
   *  f and input at NULL.
   */
  ComputePV()
  {
    subdiv       = 2;
//    analyticfunc = NULL;
//    input        = NULL;
    resolution   = 3;
  }
  
  virtual ~ComputePV(){}
  
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
  InrImage::ptr ComputeAnalyticPartialVolumeSubdiv(float ipos, float ineg);

  //Linear interpolation functions
  /**
   *  Compute partial volume iteratively.
   *  @return InrImage* A pointer to an InrImage object.
   */
  InrImage::ptr ComputePartialVolume();
  
  /**
   *  Compute partial volume (linear interpolation).
   *  @return InrImage* A pointer to an InrImage object.
   */
  InrImage::ptr ComputePartialVolumeSubdiv();
  
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



//InrImage* ComputeAnalyticPartialSurfaceSubdiv(InrImage* input, int subdiv, const AnalyticFunc2D& f );
//
//InrImage* ComputeAnalyticPartialVolumeSubdiv(InrImage* input, int subdiv, const AnalyticFunc& f );
//
//
////
//double RecursivePositiveVolume( double val[8], double subvols[8], 
//                                double volume, int subdiv_level );
//
////
//InrImage* ComputePartialVolume(InrImage* input, int resolution=3);
//
////
//InrImage* ComputePartialVolumeSubdiv(InrImage* input, int subdiv=2);

#endif // _ComputePartialVolume_h_
