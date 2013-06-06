/***************************************************************************
 * $Author: karl $
 * $Revision: 1.1.1.1 $
 * $Log: CalculRepCercle.hpp,v $
 * Revision 1.1.1.1  2004/02/02 20:47:09  karl
 * source code in C++
 *
 * Revision 1.1.1.1  2000/04/07 16:08:28  karl
 * Sources code
 *
 * Revision 1.7  1998/10/02 20:10:01  kkrissia
 * Creation d'une classe InrImage Template
 *
 */

#ifndef REPONSE_CERCLE_HPP
#define REPONSE_CERCLE_HPP

#include "style.hpp"

#include "GeneralGaussianFilter.h"
#include "math1.hpp"
#include "Coordonnees.hpp"
#include "Point3D.hpp"
#include "coord_image.hpp"

#include <boost/shared_ptr.hpp>
#include <boost/shared_array.hpp>

#define PAIRS_MIN  0 
#define PAIRS_MAX  1
#define PAIRS_MEAN 2


/*
#define CIRCLE_RESPONSE_MIN            0
#define CIRCLE_RESPONSE_MEAN           1
#define CIRCLE_RESPONSE_MEDIAN         2
*/

#include <vector>

class response_info {
public:
  float radius_gradient;  // gradient vector scalar radius direction
  float tangent_gradient; // gradient vector scalar tangent direction

  response_info(): radius_gradient(0),tangent_gradient(0) {}
  bool operator < (const response_info& r) const {
    return radius_gradient < r.radius_gradient;
  }
};

// sort in decreasing order
bool sort_operator(const response_info& r1,const response_info& r2);


/** Class to compute boundary information over a given circle at the specified
 * voxel.
 */
class CalculRepCercle
//     ---------------
{

  public:
    /// Type of integration for the boundary information along the circle.
    enum CircleResponseType {
      circle_min,   /**< Minimal value along the circle. */
      circle_mean,  /**< Maximal value along the circle. */
      circle_median /**< Median  value along the circle. */
    };

  protected:
    /// input image
    InrImage*   _image;
    /// integration radius
    double      _rayon;

    
    boost::shared_ptr<CoordImage> _coord_image;

    /// Response type
    CircleResponseType  _type_reponse;

    /// If pairing opposite points
    bool        _reduce_pairs;
    int         _pairs_type;

    /// If selecting the highest values
    bool        _keep_highest;
    int         _highest_percentage;

    /// vector containing the responses information
    std::vector<response_info> responses;

    /// Precomputed cosinus and sinus value
    boost::shared_array<double>   coeff_cos;
    boost::shared_array<double>   coeff_sin;

    /// Number of points used along the circle 
    int       nb_points;
    /// Number of points used along the circle divided by 2
    int       nb_points2;
    /// Angle step
    double    d_alpha;

    // If _filter is not NULL, we take the gradient field
    // from it otherwise, we use the gradient image

    /// filter to get the gradient image
    GeneralGaussianFilter*   _filter;

    /// gradient image
    InrImage*         _grad;


    unsigned char _NoLinearInterp; /**< Flag for trilinear interpolation */
    unsigned char _OptReponse;     /**< if true, reduce the number of points along the circle */

    bool      _use_SD;    /**< use standard deviation contraint */
    bool      _use_EXC;   /**< use excentricity constraint: compare radius 
                               and tangent gradients */

    float     _SeuilET;  /**< Threshold on the standard deviation along the circle */
    float     _SeuilEXC; /**< Threshold on Excentricity */

    ImageLinearInterpolator::ptr _linear_interpolator;

    
    bool debug;
    int  debug_at_x,debug_at_y,debug_at_z;
    
private:

  /// 
  unsigned char GradientCorrect(  const Vect3D<double>& p);

public:

  /**
   *  Constructor.
   * Takes the input image and the response type as parameters.
   * @param image input image
   * @param type_reponse response type
   */
   CalculRepCercle( InrImage* image, CircleResponseType type_reponse);
  //           ---------------

  /**
   * Destructor.
   */
  ~CalculRepCercle();
  //          ---------------

  /**
   * Sets the filter to compute the gradient information.
   */
  void SetFilter(GeneralGaussianFilter* f ) { _filter = f; }
  //   ---------

  /**
   * Sets linear interpolation option.
   */
  void SetNoLinearInterp(unsigned char b) { _NoLinearInterp = b; }

  void SetOptReponse(unsigned char b) { _OptReponse = b; }
  //   -------------

  void SetDebug(bool b) { debug = b; }
  bool GetDebug() const {return debug;}
  
  /**
   * Sets gradient image as a vector field.
   */
  void SetGradient(InrImage* g ) { 
    _grad = g; 
    _linear_interpolator = ImageLinearInterpolator::ptr(
                                  new ImageLinearInterpolator(g));
  }
  
  /**
   *  Returns the gradient image.
   */
  InrImage* GetGradient() { return _grad; }
  
  int GetResponseType() { return _type_reponse; }

  // if s<1E-5 desactivate SD
  void useSD(  float s=1 )   
  { 
    _use_SD  = (s>1E-5);
    _SeuilET = s;
  }

  // if s<1E-5 desactivate EXC
  void useEXC( float s=1 )   
  { 
    _use_EXC  = (s>1E-5); 
    _SeuilEXC = s; 
  }

  // if percent == 100, desactivate KeepHighest
  void KeepHighest( int percent ) 
  {
    if (percent<100-1E-5) {
      _keep_highest       = true;
      _highest_percentage = percent;
    } else {
      _keep_highest       = false;
      _highest_percentage = percent;
    }
  }

  void ReducePairs( bool rp, int mode) 
  {
    _reduce_pairs = rp;
    _pairs_type   = mode;
  }

  ///
  void FixeRayon( double rayon, float coeff_rayon);
  //   ---------

  void InitCoeff();
  //   ---------

  ///
  void  ComputeResponse( const Vect3D<double>& pos, const Vect3D<double>& vect, 
  //    ---------------
                         response_info& rep, bool debuginfo=false);

  ///
  void  CalculReponses( const int& x, const int& y, const int& z, 
  //      --------------
        const Vect3D<double>& vep0, 
        const Vect3D<double>& vep1, 
        const float& rap_ellipse  );
 
  ///
  double Reponse( );
  //     -------



}; // CalculRepCercle   

#endif // REPONSE_CERCLE_HPP
