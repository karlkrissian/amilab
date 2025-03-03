/*
 *  SubPixel2D.h
 *  AMILab
 */

#ifndef SUBPIXEL2D
#define SUBPIXEL2D

class DessinImage;
class wxColour;
class InrImage;

#include "DefineClass.hpp"
#include <vector>
#include <boost/shared_ptr.hpp>
//using namespace std;

/**
 *  This class represent the information of a pixel that is a member of the edge.
 *  Is used by the SubPixel2D class.
 *  @author Daniel Elías Santana Cedrés (daniel.santana104@estudiantes.ulpgc.es)
 *  @author Agustín Trujillo Pino (agustin@dis.ulpgc.es)
 *  @author Karl Krissian (krissian@dis.ulpgc.es)
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
   *  equal to 1, it shows the angle of the line. Else, it shows the radius.
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


class SuperGradienteCurvo_res 
{
public:
  boost::shared_ptr<InrImage> denoised;
  boost::shared_ptr<InrImage> aintensity;
  boost::shared_ptr<InrImage> bintensity;
  boost::shared_ptr<InrImage> border;
  boost::shared_ptr<InrImage> acoef;
  boost::shared_ptr<InrImage> bcoef;
  boost::shared_ptr<InrImage> ccoef;
  boost::shared_ptr<InrImage> curvature;
  boost::shared_ptr<InrImage> xpos;
  boost::shared_ptr<InrImage> ypos;

  
  /**
   * @brief Allocate the different images as 1D images with the given size, 
   * apart from denoised comes from the algorithm.
   *
   * @param size Dimension of the 1D (array) images.
   * @return void
   **/
  void InitImages(int size);
  
};


/**
 *  This class contains the methods of the SubPixel method for 2D images.
 *  Also includes the method that draw the sub-pixel edge.
 *  @author Daniel Elías Santana Cedrés (daniel.santana104@estudiantes.ulpgc.es)
 *  @author Agustín Trujillo Pino (agustin@dis.ulpgc.es)
 *  @author Karl Krissian (krissian@dis.ulpgc.es)
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
  
 /*
  void drawBorder(DessinImage* viewer, InrImage* inside, InrImage* border_pts, 
                  wxColour* bcolor, int bthickness, int bstyle, int draw_normals, 
                  InrImage* norm_pts, wxColour* ncolor, int nthickness, int nstyle);
  */
  
  /**
   *  This procedure applies the basic method for sub-pixel edge detection in 2D
   *  images.
   */
  SuperGradienteCurvo_res SuperGradienteCurvo();
  
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
   * @brief Initialize SubpixelDenoising, allocating 3 images.
   * Called within SubpixelDenoising() method.
   * @return void
   **/
  void SubpixelDenoising_Init();

  /**
   * @brief Finalize SubpixelDenoising.
   * Called within SubpixelDenoising() method.
   * @return void
   **/
  void SubpixelDenoising_End();

  /**
   * @brief Runs one iteration of SubpixelDenoising.
   * Called within SubpixelDenoising() method.
   * @return void
   **/
  void SubpixelDenoising_Iterate();

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
  void fillImages(boost::shared_ptr<InrImage> AIntensity, boost::shared_ptr<InrImage> BIntensity, 
                  boost::shared_ptr<InrImage> border, boost::shared_ptr<InrImage> a, boost::shared_ptr<InrImage> b, 
                  boost::shared_ptr<InrImage> c, boost::shared_ptr<InrImage> curvature, boost::shared_ptr<InrImage> posx, 
                  boost::shared_ptr<InrImage> posy);
  
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
  std::vector<borderPixel> getBorderPixelVector();
  
private:
  //Input image
  InrImage* input;
  //Denoised image
  InrImage* denoised;
  //borderPixel vector
  std::vector<borderPixel> borderPixelVector;
  //Gradient threshold
  double threshold;
  //Linear case (first or second order)
  int linear_case;
   
  /// Images needed for the subpixel denoising method
  ///Counters image
  boost::shared_ptr<InrImage> C;
  ///Intensities image
  boost::shared_ptr<InrImage> I;
  ///Averaged image
  boost::shared_ptr<InrImage> G;
  boost::shared_ptr<InrImage> input_copy;
};

#endif
