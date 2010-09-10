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
  /** Circle's center */
  float center[2];
  /** Circle's radius */
  float radius;
  
public:
  /**
   *  Creates an analytic circle.
   *  @param x Component of the circle's center. Default 50.
   *  @param y Component of the circle's center. Default 50.
   *  @param r Circle's radius. Default 20.
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
   *  Set the circle's center.
   *  @param c1 X component of the circle's center.
   *  @param c2 Y component of the circle's center.
   */
  void setCenter(float c1, float c2);
  
  /**
   *  Get the circle's center.
   *  @return float* A pointer to a vector with the center value.
   */
  float* getCenter();
  
  /**
   *  Set the circle's radius.
   *  @param r The value of circle's radius.
   */
  void setRadius(float r);
  
  /**
   *  Get the circle's radius.
   *  @return float The radius value.
   */
  float getRadius();
};

/**
 *  AnalyticLine class.
 *  @author Karl Krissian (krissian@dis.ulpgc.es)
 *  @author Daniel Elías Santana Cedrés (daniel.santana104@estudiantes.ulpgc.es)
 */
class AnalyticLine : public AnalyticFunctionBase {
  
  DEFINE_CLASS(AnalyticLine);
  
private:
  /** Line's normal and cut point on y axis */
  float m[2], _n;
  
public:
  /**
   *  Creates an analytic line.
   *  @param mx X normal component. Default 1.
   *  @param my Y normal component. Default 1.
   *  @param n Cut point value. Default 0.
   */
  AnalyticLine(float mx = 1, float my = 1, float n = 0);
  
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
   *  Set line normal.
   *  @param m1 X component of the normal.
   *  @param m2 Y component of the normal.
   */
  void setM(float m1, float m2);
  
  /**
   *  Get line normal.
   *  @return float* A pointer to a vector with normal value.
   */
  float* getM();
  
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

//******** NUEVO! 09/09/2010 *******
//Nueva clase para la creación de venas sintéticas rectas en 2D
class AnalyticStraightVessel2D : public AnalyticFunctionBase {
  DEFINE_CLASS(AnalyticStraightVessel2D);

private:
  //El centro
  float center[2];
  //El grosor del vaso
  float thickness;
  //angulo
  float angle;
  //Pendientes
  double nx;
  double ny;

public:
  //Constructor
  AnalyticStraightVessel2D(float x = 50.0, float y = 50.0, float g = 4.0, 
                           float alpha = 20.0);
  //Destructor
  ~AnalyticStraightVessel2D();
  //Operador paréntesis (obtención de la imagen de la ecuación)
  double operator () (const double& x, const double& y, const double& z) const;
  //Obtener el centro
  float* getCenter();
  //Asignar centro
  void setCenter(float x, float y);
  //Obtener grosor
  float getThickness();
  //Asignar grosor
  void setThickness(float g);
  //Obtener ángulo
  float getAngle();
  //Asignar ángulo
  void setAngle(float alpha);
};

/**
 *  AnalyticSphere class.
 *  @author Karl Krissian (krissian@dis.ulpgc.es)
 *  @author Daniel Elías Santana Cedrés (daniel.santana104@estudiantes.ulpgc.es)
 */
class AnalyticSphere : public AnalyticFunctionBase {
  
  DEFINE_CLASS(AnalyticSphere);
  
private:
  /** Sphere center */
  float center[3];
  /** Sphere radius */
  float radius;
  
public:
  /**
   *  Creates an analytic sphere.
   *  @param x Component of sphere's center. Default 50.
   *  @param y Component of sphere's center. Default 50.
   *  @param z Component of sphere's center. Default 50.
   *  @param r Sphere's radius. Default 20.
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
   *  Set sphere's center.
   *  @param c1 X component of sphere's center.
   *  @param c2 Y component of sphere's center.
   *  @param c3 Z component of sphere's center.
   */
  void setCenter(float c1, float c2, float c3);
  
  /**
   *  Get sphere's center.
   *  @return float* A pointer to a vector with sphere's center value.
   */
  float* getCenter();
  
  /**
   *  Set sphere's radius.
   *  @param r Sphere's radius value.
   */
  void setRadius(float r);
  
  /**
   *  Get sphere's radius.
   *  @return float Sphere's radius value.
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
  /** Torus' center */
  float center[3];
  /** Minimum torus' radius */
  float rmin;
  /** Maximum torus' radius */
  float rmax;
public:
  /**
   *  Creates an analytic torus.
   *  @param x Component of torus' center. Default 50.
   *  @param y Component of torus' center. Default 50.
   *  @param z Component of torus' center. Default 50.
   *  @param r Minimum torus' radius. Default 3.
   *  @param R Maximum torus' radius. Default 20.
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
   *  Set torus' center.
   *  @param c1 X component of torus' center.
   *  @param c2 Y component of torus' center.
   *  @param c3 Z component of torus' center.
   */
  void setCenter(float c1, float c2, float c3);
  
  /**
   *  Get torus' center.
   *  @return float* A pointer to a vector with the torus' center value.
   */
  float* getCenter();
  
  /**
   *  Set minimum torus' radius.
   *  @param rm Minimum torus' radius value.
   */
  void set_rmin(float rm);
  
  /**
   *  Get minimum torus' radius.
   *  @return float Minimum torus' radius value.
   */
  float get_rmin();
  
  /**
   *  Set maximum torus' radius.
   *  @param rM Maximum torus' radius value.
   */
  void set_rmax(float rM);
  
  /**
   *  Get maximum torus' radius.
   *  @return float Maximum torus' radius value.
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
  
  ~ComputePV(){}
  
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
