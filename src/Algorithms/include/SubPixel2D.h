/*
 *  SubPixel2D.h
 *  AMILab
 */

#ifndef SUBPIXEL2D
#define SUBPIXEL2D

#include "DessinImage.hpp"
#include "inrimage.hpp"
#include "DefineClass.hpp"
#include <vector>
using namespace std;

/**
 *  This class represent the information of a pixel that is a member of the edge.
 *  Is used by the SubPixel2D class.
 *  @author Agustín Trujillo Pino (agustin@dis.ulpgc.es)
 *  @author Karl Krissian (krissian@dis.ulpgc.es)
 *  @author Daniel Elías Santana Cedrés (daniel.santana104@estudiantes.ulpgc.es)
 */
class borderPixel {
public:
  /**
   *  Creates a new borderPixel object. Default constructor.
   */
  borderPixel() {}
  
  ~borderPixel() {}
  
  /**
   *  Set the border pixel values.
   *  @param intA A intensity.
   *  @param intB B intensity.
   *  @param bord Edge type (horizontal or vertical).
   *  @param coef_a The 'a' coefficient of the equation.
   *  @param coef_b The 'b' coefficient of the equation.
   *  @param coef_c The 'c' coefficient of the equation.
   *  @param cu Curvature.
   *  @param posx x position.
   *  @param posy y position.
   */
  void setBorderPixelValues(double intA, double intB, unsigned char bord,
                            double coef_a, double coef_b, double coef_c,
                            double cu, int posx, int posy);
  
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
   *  @return The value of the edge type (horizontal or vertical macros).
   */
  unsigned char getBorder();
  
  /**
   *  Get the 'a' coefficient.
   *  @return The value of the 'a' coefficient of the parable equation.
   */
  double        getCoefficient_a();
  
  /**
   *  Get the 'b' coefficient.
   *  @return The value of the 'b' coefficient of the parable equation.
   */
  double        getCoefficient_b();
  
  /**
   *  Get the 'c' coefficient.
   *  @return The value of the 'c' coefficient of the parable equation.
   */
  double        getCoefficient_c();
  
  /**
   *  Get the curvature.
   *  @return The value of the curvature of the parable equation.
   */
  double        getCurvature();
  
  /**
   *  Get the x position.
   *  @return The value of the x position of the pixel.
   */
  int           getPosX();
  
  /**
   *  Get the y position.
   *  @return The value of the y position of the pixel.
   */
  int           getPosY();
  
  /**
   *  Print the information of the pixel.
   *  @param  linear_case Indicates if it is first or second order (line or parable).
   *  @return Show in the screen the information of the pixel: The position of 
   *  the pixel, the edge type, the 'A' and 'B' intensity value and the 
   *  coefficients of the curve. If linear_case is
   *  equal to 1, it shows the angle of the line. Else, it shows the radius.p
   */
  void          printBorderPixel(int linear_case);
  
private:
  //Intensity values
  double A;
  double B;
  //Border type
  unsigned char border;
  //Curve coefficients (y = a + bx + cx^2)
  double a;
  double b;
  double c;
  //Curvature
  double curvature;
  //Position(x,y)
  int px;
  int py;

};


/**
 *  This class contains the methods of the SubPixel method for 2D images.
 *  Also includes the method that draw the sub-pixel edge.
 *  @author Agustín Trujillo Pino (agustin@dis.ulpgc.es)
 *  @author Karl Krissian (krissian@dis.ulpgc.es)
 *  @author Daniel Elías Santana Cedrés (daniel.santana104@estudiantes.ulpgc.es)
 */
class SubPixel2D {
  
  DEFINE_CLASS(SubPixel2D);
  
public:
  /**
   *  SubPixel2D constructor.
   *  @param inp_image The input image.
   *  @param thres     The threshold value.
   *  @param lc        Linear case. Indicates if the border that will be processed
   *                   is a line (first order) or a parable (second order).
   */
  SubPixel2D(InrImage* inp_image, float thres, int lc);
  
  virtual ~ SubPixel2D();
  
  /**
   *  Draw the sub-pixel edge.
   *  @param viewer       A pointer to the viewer of the image.
   *  @param inside       Image that indicates the points inside the view.
   *  @param border_pts   Image that contains the points of the edge.
   *  @param bcolor       The color of the edge.
   *  @param bthickness   The thickness of the edge.
   *  @param bstyle       The style of the edge.
   *  @param draw_normals Indicates if the normals will be drawn.
   *  @param norm_pts     Image that contains the points of the normals of the edge.
   *  @param ncolor       The color of the normals.
   *  @param nthickness   The thickness of the normals.
   *  @param nstyle       The style of the normals.
   */
  void drawBorder(DessinImage* viewer, InrImage* inside, InrImage* border_pts, 
                  wxColour* bcolor, int bthickness, int bstyle, int draw_normals, 
                  InrImage* norm_pts, wxColour* ncolor, int nthickness, int nstyle);
  
  /**
   *  This procedure applies the basic method for sub-pixel edge detection in 2D
   *  images.
   */
  void SuperGradienteCurvo();
  
  /**
   *  This procedure applies the sub-pixel edge detection in 2D noisy images.
   */
  void SuperGradienteGaussianoCurvo();
  
  /**
   *  This procedure applies the sub-pixel edge detection in 2D noisy images
   *  using a dynamic window and a close edge detection.
   */
  void DenoisingGus();
  
  /**
   *  This procedure applies the sub-pixel edge detection in 2D noisy images
   *  using a dynamic window and a close edge detection. Use a iterative
   *  scheme (restoration).
   */
  void SubpixelDenoising(int niter);
  
  
  /**
   *  This procedure optimize the second order edges.
   *  @param a         The 'a' coefficient of the curve.
   *  @param b         The 'b' coefficient of the curve.
   *  @param c         The 'c' coefficient of the curve.
   *  @param threshold The threshold for the intensity.
   *  @param rmin      Minimum radius.
   *  @param rmax      Maximum radius.
   */
  void OptimizarParabola(double &a, double &b, double &c, double threshold, 
                         double rmin, double rmax);
  
  /**
   *  Based on the content of the vector of the pixels members of the edge, this
   *  procedure fill some images.
   *  @param AIntensity Smart pointer to an InrImage for 'A' intensity values.
   *  @param BIntensity Smart pointer to an InrImage for 'B' intensity values.
   *  @param border     Smart pointer to an InrImage for the edge type.
   *  @param a          Smart pointer to an InrImage for 'a' coefficients.
   *  @param b          Smart pointer to an InrImage for 'b' coefficients.
   *  @param c          Smart pointer to an InrImage for 'c' coefficients.
   *  @param curvature  Smart pointer to an InrImage for curvatures.
   *  @param posx       Smart pointer to an InrImage for x positions.
   *  @param posy       Smart pointer to an InrImage for y positions.
   */
  void fillImages(InrImage::ptr AIntensity, InrImage::ptr BIntensity, 
                  InrImage::ptr border, InrImage::ptr a, InrImage::ptr b, 
                  InrImage::ptr c, InrImage::ptr curvature, InrImage::ptr posx, 
                  InrImage::ptr posy);
  
  /**
   *  Set the input image.
   *  @param inp_image A pointer to an InrImage object.
   */
  void setInput(InrImage* inp_image);
  
  /**
   *  Get the input image.
   *  @return A pointer to an InrImage object.
   */
  InrImage* getInput();
  
  /**
   *  Get the denoised image.
   *  @return A pointer to an InrImage object.
   */
  InrImage* getDenoised();
  
  /**
   *  Get the vector that contains the pixels members of the edge.
   *  @return A STL vector of borderPixel type.
   */
  vector<borderPixel> getBorderPixelVector();
  
private:
  //Input image
  InrImage* input;
  //Denoised image
  InrImage* denoised;
  //borderPixel vector
  vector<borderPixel> borderPixelVector;
  //Gradient threshold
  float threshold;
  //Linear case (first or second order)
  int linear_case;
   
};

#endif
