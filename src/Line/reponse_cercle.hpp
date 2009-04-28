/***************************************************************************
 * $Author: karl $
 * $Revision: 1.1.1.1 $
 * $Log: reponse_cercle.hpp,v $
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

#include "FiltreRec.hpp"
#include "math1.hpp"
#include "Coordonnees.hpp"
#include "Point3D.hpp"
#include "coord_image.hpp"

#define PAIRS_MIN  0 
#define PAIRS_MAX  1
#define PAIRS_MEAN 2

#define CIRCLE_RESPONSE_MIN            0
#define CIRCLE_RESPONSE_MEAN           1
#define CIRCLE_RESPONSE_MEDIAN         2

#include <list>

class response_info {
public:
  float radius_gradient;  // gradient vector scalar radius direction
  float tangent_gradient; // gradient vector scalar tangent direction

  response_info(): radius_gradient(0),tangent_gradient(0) {}
  bool operator < (const response_info& r) const
  { 
    return radius_gradient < r.radius_gradient; 
  }
};

//======================================================================
class CalculRepCercle
//     ---------------
{

  InrImage*   _image;
  double      _rayon;

  CoordImage* _coord_image;

  int         _type_reponse;

  bool        _reduce_pairs;
  int         _pairs_type;

  bool        _keep_highest;
  int         _highest_percentage;

  std::list<response_info> responses;

  // Precompute cosinus and sinus
  double*   coeff_cos;
  double*   coeff_sin;

  /// nombre de points le long du cercle 
  int       nb_points;
  // nombre de points le long du cercle divise par 2
  int       nb_points2;
  /// pas de l'angle
  double    d_alpha;

  // If _filter is not NULL, we take the gradient field
  // from it otherwise, we use the gradient image

  // filter to get the gradient image
  FiltreRecursif*   _filter;

  // gradient image
  InrImage*         _grad;


  unsigned char _NoLinearInterp; // Flag for trilinear interpolation
  unsigned char _OptReponse;     // if true, reduce the number of points along the circle

  bool      _use_SD;    // use standard deviation contraint
  bool      _use_EXC;   // use excentricity constraint: compare radius 
                        // and tangent gradients

  float     _SeuilET;  // Threshold on the standard deviation along the circle
  float     _SeuilEXC; // Threshold on Excentricity

private:

  ///
  int  VT_Mediane( float* tab, int dim, double* res );

  /// 
  unsigned char GradientCorrect(  const Point3D& p);

public:

  ///
  Constructeur CalculRepCercle( InrImage* image, int type_reponse);
  //           ---------------

  ///
  Destructeur CalculRepCercle();
  //          ---------------

  void SetFilter(FiltreRecursif* f ) { _filter = f; }
  //   ---------

  void SetNoLinearInterp(unsigned char b) { _NoLinearInterp = b; }
  //   -----------------

  void SetOptReponse(unsigned char b) { _OptReponse = b; }
  //   -------------

  void SetGradient(InrImage* g )     { _grad = g; }
  //   -----------

  void useSD( bool usesd,  float s=1 )   
  { 
    _use_SD  = usesd;
    _SeuilET = s;
  }

  void useEXC(bool useexc, float s=1 )   
  { 
    _use_EXC  = useexc; 
    _SeuilEXC = s; 
  }

  void KeepHighest(bool kh, int percent ) 
  {
    _keep_highest       = kh;
    _highest_percentage = percent;
  }

  void ReducePairs( bool rp, int mode) 
  {
    _reduce_pairs = rp;
    _pairs_type   = mode;
  }

  ///
  void FixeRayon( double rayon, float coeff_rayon);
  //   ---------


  ///
  void  ComputeResponse( const Point3D& pos, const Vect3D<double>& vect, response_info& rep);
  //    ---------------

  ///
  void  CalculReponses( int x, int y, int z, 
  //      --------------
        Vect3D<double> vep0, 
        Vect3D<double> vep1, 
        float rap_ellipse  );
 
  ///
  double Reponse( int type_rep);
  //     -------



}; // CalculRepCercle   

#endif // REPONSE_CERCLE_HPP
