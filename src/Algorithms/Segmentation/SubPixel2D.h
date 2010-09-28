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

//New class for a pixel that is a border member
class borderPixel {
public:
  borderPixel() {}
  ~borderPixel() {}
  void setBorderPixelValues(double intA, double intB, unsigned char bord,
                            double coef_a, double coef_b, double coef_c,
                            double cu, int posx, int posy);
  double        getAIntensity();
  double        getBIntensity();
  unsigned char getBorder();
  double        getCoefficient_a();
  double        getCoefficient_b();
  double        getCoefficient_c();
  double        getCurvature();
  int           getPosX();
  int           getPosY();
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
  //Position
  int px;
  int py;

};


//SubPixel2D Class
class SubPixel2D {
  
  DEFINE_CLASS(SubPixel2D);
  
public:
  //Constructor
  SubPixel2D(InrImage* inp_image, float thres, int lc);
  ~ SubPixel2D();
  //Destructor
  void drawBorder(DessinImage* viewer, InrImage* inside, InrImage* border_pts, 
                  wxColour* bcolor, int bthickness, int bstyle, int draw_normals, 
                  InrImage* norm_pts, wxColour* ncolor, int nthickness, int nstyle);
  //Subpixel2D method
  void SuperGradienteCurvo();
  //Subpixel2D method on noisy images
  void SuperGradienteGaussianoCurvo();
  //Subpixel2D method on noisy images with near edges
  void DenoisingGus();
  //Optimize second order edges
  void OptimizarParabola(double &a, double &b, double &c, double umbral, 
                         double rmin, double rmax);
  //Fill the results images
  void fillImages(vector<borderPixel> &borderPixelVector, InrImage::ptr AIntensity,
                  InrImage::ptr BIntensity, InrImage::ptr border, InrImage::ptr a,
                  InrImage::ptr b, InrImage::ptr c, InrImage::ptr curvature, 
                  InrImage::ptr posx, InrImage::ptr posy);
  //Denoise images in SuperGradienteGaussianoCurvo method
  void Promedio3x3(/*InrImage* input,*/ InrImage* result, 
                   double a00, double a01, double a11);
  //Set input image
  void setInput(InrImage* inp_image);
  
  //Get atributes
  InrImage* getInput();
  vector<borderPixel> getBorderPixelVector();
  
private:
  //Atributes
  //Input image
  InrImage* input;
  //borderPixel vector
  vector<borderPixel> borderPixelVector;
  //Gradient threshold
  float threshold;
  //Linear case
  int linear_case;
   
};

#endif
