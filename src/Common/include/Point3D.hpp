/***************************************************************************
 * $Author: karl $
 * $Revision: 1.1.1.1 $
 * $Log: Point3D.hpp,v $
 * Revision 1.1.1.1  2004/02/02 20:47:07  karl
 * source code in C++
 *
 * Revision 1.1.1.1  2000/04/07 16:08:27  karl
 * Sources code
 *
 */

#ifndef POINT3D_HPP
#define POINT3D_HPP

#include "style.hpp"
#include <iosfwd>
#include "Coordonnees.hpp"
#include "math1.hpp"

#include "CommonConfigure.h"

//============================================================================
//
struct COMMON_EXPORT vect3D
//                   ======
{

  float x;
  float y; 
  float z;

};

//============================================================================
//
class COMMON_EXPORT Point3D
//                  =======
{

public:

  ///
  float   x;
  ///
  float   y;
  ///
  float   z;

  /// nombre de lignes auxquelles il appartient
  int nb_liens;

  /// Rayon pour les vaisseaux
  float  rayon;

  /// Probabilite d'etre au centre d'un vaisseau 
  float  proba;

  /// Test de jonction: vaut 1 si le point est une jonction, 0 sinon
  float  jonction;

  ///
  Vect3D<float> vecteur;

  ///
   Point3D()
  //           -------
  {
    x = y = z = 0;
    nb_liens = 0; 
    rayon = 1;
    proba = 1;
    jonction = 0.0;
    vecteur.Init(0.0,0.0,0.0 );
  }

  ///
   Point3D( float x0, float y0, float z0)
  //           -------
  {
    x = x0;
    y = y0;
    z = z0;
    nb_liens = 0; 
    rayon    = 1;
    proba    = 1;
    jonction = 0;
  }

  void SetRadius( float r) { rayon = r; }

  ///
  void Init( float x0, float y0, float z0)
  //
  {
    x = x0;
    y = y0;
    z = z0;
  }

  ///
  unsigned char operator==(const Point3D& p)
  //      ----------
  {
    return( (fabsf(x-p.x)<1E-4) Et (fabsf(y-p.y)<1E-4) Et (fabsf(z-p.z)<1E-4) );
  }

  ///
  Point3D& operator=(const Point3D& p)
  //       ---------
  {
    x        = p.x;
    y        = p.y;
    z        = p.z;
    nb_liens = p.nb_liens;
    rayon    = p.rayon;
    proba    = p.proba;
    jonction = p.jonction;
    vecteur  = p.vecteur;
    return(*this);
  }

  ///
  Point3D& operator+=(const vect3D& v)
  //       ----------
  {
    x += v.x;
    y += v.y;
    z += v.z;
    return(*this);
  }

  ///
  friend COMMON_EXPORT std::ostream& operator<<(std::ostream& o, const Point3D& p);

};


//----------------------------------------------------------------------
/**
  @name conversion de Point3D a Vect3D<float>
 */
//@{
///
COMMON_EXPORT Vect3D<float> operator-(const Point3D& p1, const Point3D& p2);

///
COMMON_EXPORT Point3D operator+( const Point3D& p, const Vect3D<float>& v);

///
COMMON_EXPORT Point3D operator+( const Point3D& p, const Vect3D<double>& v);
//@}

#endif // POINT3D_HPP
