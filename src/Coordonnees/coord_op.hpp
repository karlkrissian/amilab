/***************************************************************************
 * $Author: karl $
 * $Revision: 1.1.1.1 $
 * $Log: coord_op.hpp,v $
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
#include "coordonnees.hpp"
#include "inrimage.hpp"

///
class CoordImage
//
{

private:
  
  ///
  InrImage* _inrimage;

public:

  ///
   CoordImage( InrImage* inrimage = NULL);
  
  ///
  ~ CoordImage();

  ///
  Vect3D<float> CoordImage2Reelles( const Vect3D<float>& v);

  ///
  Vect3D<float> CoordReelles2Image( const Vect3D<float>& v);

  ///
  unsigned char DansImage( const Point3D& p);

  ///
  void CalculVecteursOrthogonaux( const Vect3D<float>& v, Vect3D<float>& v1, Vect3D<float>& v2);

}; // CoordImage

#endif // COORDIMAGE_HPP
