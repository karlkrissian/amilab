/***************************************************************************
 * $Author: karl $
 * $Revision: 1.2 $
 * $Log: coord_image.hpp,v $
 * Revision 1.2  2005/03/01 14:23:56  karl
 * improving coordinate conversion
 *
 * Revision 1.1.1.1  2004/02/02 20:47:07  karl
 * source code in C++
 *
 * Revision 1.1.1.1  2000/04/07 16:08:27  karl
 * Sources code
 *
 * Revision 1.2  1998/12/13 21:05:59  kkrissia
 * *** empty log message ***
 *
 * Revision 1.1  1998/10/22 20:18:39  kkrissia
 * Dessin des lignes dans les MIP
 *
 */

#ifndef COORDIMAGE_HPP
#define COORDIMAGE_HPP

#include "style.hpp"
#include "Coordonnees.hpp"
#include "inrimage.hpp"
#include "Point3D.hpp"

///
class CoordImage
//
{

private:
  
  ///
  InrImage* _inrimage;

public:

  ///
   CoordImage( InrImage* inrimage = (InrImage*) NULL);
  
  ///
  ~ CoordImage() {}

  ///
  Vect3D<float> CoordImage2Reelles( const Vect3D<float>& v);

  ///
  Vect3D<float> CoordReelles2Image( const Vect3D<float>& v);

  ///
  Point3D CoordReelles2Image( const Point3D& p);

  ///
  Vect3D<double> CoordReelles2Image( const Vect3D<double>& v);

  ///
  unsigned char DansImage( const Point3D& p);

/*
  On cherche une base orthogonale (v1,v2,v),
  connaissant le vecteur v.

  v1_prec donne une idee de la direction du vecteur v1 cherche:

  le repere doit verifier les relations suivantes:
  v1 ^ v2 = v
  v2 ^ v  = v1
  v  ^ v1 = v2

  on definit donc 
  v2 = v ^ v1_prec
  v1 = v2 ^ v
  
 */
  void CalculVecteursOrthogonaux( const Vect3D<float>& v1_prec, 
				  const Vect3D<float>& v, 
				  Vect3D<float>& v1, 
				  Vect3D<float>& v2);

  ///
  void CalculVecteursOrthogonaux( const Vect3D<float>& v, 
				  Vect3D<float>& v1, 
				  Vect3D<float>& v2);

}; // CoordImage

#endif // COORDIMAGE_HPP
