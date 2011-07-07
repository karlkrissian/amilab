/*
 *  SubPixel3D.h
 *  AMILab
 */

#ifndef SUBPIXEL3D
#define SUBPIXEL3D

#include "DessinImage.hpp"
#include "inrimage.hpp"
#include "DefineClass.hpp"
#include <vector>
#include <iostream>
using namespace std;

/**
 *  This class represent the information of a voxel that is a member of the edge.
 *  Is used by the SubPixel3D class.
 *  @author Daniel Elías Santana Cedrés (daniel.santana104@estudiantes.ulpgc.es)
 *  @author Agustín Trujillo Pino (agustin@dis.ulpgc.es)
 *  @author Karl Krissian (krissian@dis.ulpgc.es)
 */
class borderVoxel {
public:
  /**
   *  Creates a new borderVoxel object. Default constructor.
   */
  borderVoxel() {}
  
  ~borderVoxel() {}
  
  /**
   *  Set the border pixel values.
   *  @param intA A intensity.
   *  @param intB B intensity.
   *  @param bord Edge type (X, Y or Z).
   *  @param coef_a The 'a' coefficient of the equation.
   *  @param coef_b The 'b' coefficient of the equation.
   *  @param coef_c The 'c' coefficient of the equation.
   *  @param coef_d The 'd' coefficient of the equation.
   *  @param coef_f The 'f' coefficient of the equation.
   *  @param coef_g The 'g' coefficient of the equation.
   *  @param cu Curvature.
   *  @param posx x position.
   *  @param posy y position.
   *  @param posz z position.
   */
  void setBorderVoxelValues(double intA, double intB, unsigned char bord,
                            double coef_a, double coef_b, double coef_c,
                            double coef_d, double coef_f, double coef_g,
                            double cu, int posx, int posy, int posz,
                            double gradx, double grady, double gradz);
  
  /**
   *  Get the 'A' intensity value.
   *  @return The intensity value under the edge.
   */
  double        getAIntensity();
  
  /**
   *  Get the 'B' intensity value.
   *  @return The intensity value over the edge.
   */
  double        getBIntensity();
  
  /**
   *  Get the border type.
   *  @return The value of the edge type.
   */
  unsigned char getBorder();
  
  /**
   *  Get the 'a' coefficient.
   *  @return The value of the 'a' coefficient of the paraboloid equation.
   */
  double        getCoefficient_a();
  
  /**
   *  Get the 'b' coefficient.
   *  @return The value of the 'b' coefficient of the paraboloid equation.
   */
  double        getCoefficient_b();
  
  /**
   *  Get the 'c' coefficient.
   *  @return The value of the 'c' coefficient of the paraboloid equation.
   */
  double        getCoefficient_c();
  
  /**
   *  Get the 'd' coefficient.
   *  @return The value of the 'd' coefficient of the paraboloid equation.
   */
  double        getCoefficient_d();
  
  
  /**
   *  Get the 'f' coefficient.
   *  @return The value of the 'f' coefficient of the paraboloid equation.
   */
  double        getCoefficient_f();
  
  
  /**
   *  Get the 'g' coefficient.
   *  @return The value of the 'g' coefficient of the paraboloid equation.
   */
  double        getCoefficient_g();
  
  /**
   *  Get the curvature.
   *  @return The value of the curvature of the paraboloid equation.
   */
  double        getCurvature();
  
  /**
   *  Get the x position.
   *  @return The value of the x position of the voxel.
   */
  int           getPosX();
  
  /**
   *  Get the y position.
   *  @return The value of the y position of the voxel.
   */
  int           getPosY();
  
  /**
   *  Get the z position.
   *  @return The value of the z position of the voxel.
   */
  int           getPosZ();
  
  /**
   *  Get the x component of the normal.
   *  @return The value of the x component of the normal of the edge.
   */
  double getNx();
  
  /**
   *  Get the y component of the normal.
   *  @return The value of the y component of the normal of the edge.
   */
  double getNy();
  
  /**
   *  Get the z component of the normal.
   *  @return The value of the z component  of the normal of the edge.
   */
  double getNz();
  
  /**
   *  Print the information of the voxel.
   *  @param  linear_case Indicates if it is first or second order (plane or paraboloid).
   *  @return Show in the screen the information of the voxel: The position of 
   *  the voxel, the edge type, the 'A' and 'B' intensity value and the 
   *  coefficients of the paraboloid. If linear_case is
   *  equal to 1, it shows the angle of the line. Else, it shows the radius.
   */
  void          printBorderVoxel(int linear_case);
  
private:
  //Intensity values
  double A;
  double B;
  //Border type
  unsigned char border;
  //Paraboloid coefficients
  double a;
  double b;
  double c;
  double d;
  double f;
  double g;
  //Curvature
  double curvature;
  //Position(x,y,z)
  int px;
  int py;
  int pz;
  //Normal(x,y,z)
  double nx;
  double ny;
  double nz;

};


/**
 *  This class contains the methods of the SubPixel method for 3D images.
 *  @author Daniel Elías Santana Cedrés (daniel.santana104@estudiantes.ulpgc.es)
 *  @author Agustín Trujillo Pino (agustin@dis.ulpgc.es)
 *  @author Karl Krissian (krissian@dis.ulpgc.es)
 */
class SubPixel3D {
  
  DEFINE_CLASS(SubPixel3D);
  
public:
  /**
   *  SubPixel3D constructor.
   *  @param inp_image The input image.
   *  @param thres     The threshold value.
   */
  SubPixel3D(InrImage* inp_image, float thres);
  
  ~SubPixel3D();
  
  /**
   *  Get the vector that contains the voxel members of the edge.
   *  @return A STL vector of borderVoxel type.
   */
  vector<borderVoxel> getBorderVoxelVector();
  
  /**
   *
   */
  void GradienteCurvo3D();
  
    /**
   *  Based on the content of the vector of the voxels members of the edge, this
   *  procedure fill some images.
   *  @param AIntensity Smart pointer to an InrImage for 'A' intensity values.
   *  @param BIntensity Smart pointer to an InrImage for 'B' intensity values.
   *  @param border     Smart pointer to an InrImage for the edge type.
   *  @param a          Smart pointer to an InrImage for 'a' coefficients.
   *  @param b          Smart pointer to an InrImage for 'b' coefficients.
   *  @param c          Smart pointer to an InrImage for 'c' coefficients.
   *  @param d          Smart pointer to an InrImage for 'd' coefficients.
   *  @param f          Smart pointer to an InrImage for 'f' coefficients.
   *  @param g          Smart pointer to an InrImage for 'g' coefficients.
   *  @param curvature  Smart pointer to an InrImage for curvatures.
   *  @param posx       Smart pointer to an InrImage for x positions.
   *  @param posy       Smart pointer to an InrImage for y positions.
   *  @param posz       Smart pointer to an InrImage for z positions.
   *  @param nx         Smart pointer to an InrImage for the x components of the normal.
   *  @param ny         Smart pointer to an InrImage for the y components of the normal.
   *  @param nz         Smart pointer to an InrImage for the z components of the normal.
   */
  void fillImages(InrImage::ptr AIntensity, InrImage::ptr BIntensity, 
                  InrImage::ptr border, InrImage::ptr a, InrImage::ptr b, 
                  InrImage::ptr c, InrImage::ptr d, InrImage::ptr f, 
                  InrImage::ptr g, InrImage::ptr curvature, InrImage::ptr posx, 
                  InrImage::ptr posy, InrImage::ptr posz,
                  InrImage::ptr nx, InrImage::ptr ny, InrImage::ptr nz);
  
private:
  //Input image
  InrImage* input;
  //borderVoxel vector
  vector<borderVoxel> borderVoxelVector;
  //Gradient threshold
  double threshold;
   
};

#endif //SUBPIXEL3D
