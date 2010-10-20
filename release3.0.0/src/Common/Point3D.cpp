/***************************************************************************
 * $Author: karl $
 * $Revision: 1.1.1.1 $ 
 * $Log: Point3D.cpp,v $
 * Revision 1.1.1.1  2004/02/02 20:47:07  karl
 * source code in C++
 *
 * Revision 1.1.1.1  2000/04/07 16:08:26  karl
 * Sources code
 *
 */


#include "Point3D.hpp"

ostream& operator<<(ostream& o, const Point3D& p)
{
  return o << " ( " << p.x << "; "
          	   << p.y << "; "
          	   << p.z << " )";
}

//--------------------------------------------------------------------------------
Vect3D<float> operator-(const Point3D& p2, const Point3D& p1)
//            ---------
{

  return Vect3D<float>( 
                p2.x-p1.x,
                p2.y-p1.y,
                p2.z-p1.z
               );

} // operator-(const Point3D& , const Point3D& )


//--------------------------------------------------------------------------------
Point3D operator+( const Point3D& p, const Vect3D<float>& v)
//      ---------
{

  return Point3D( p.x+v.x, p.y+v.y, p.z+v.z);

}  // operator+( const Point3D& , const Vect3D<float>& )

//--------------------------------------------------------------------------------
Point3D operator+( const Point3D& p, const Vect3D<double>& v)
//      ---------
{

  return Point3D( (float) (p.x+v.x), (float) (p.y+v.y), (float) (p.z+v.z));

}  // operator+( const Point3D& , const Vect3D<float>& )

