/***************************************************************************
 * $Author: karl $
 * $Revision: 1.4 $
 * $Log: coord_image.cpp,v $
 * Revision 1.4  2005/04/18 19:11:28  karl
 * bug fixed
 *
 * Revision 1.3  2005/03/31 20:08:08  karl
 * buf fixed in coord_image
 *
 * Revision 1.2  2005/03/01 14:24:02  karl
 * improving coordinate conversion
 *
 * Revision 1.1.1.1  2004/02/02 20:47:07  karl
 * source code in C++
 *
 * Revision 1.2  2000/10/02 16:57:14  karl
 * *** empty log message ***
 *
 * Revision 1.1.1.1  2000/04/07 16:08:26  karl
 * Sources code
 *
 * Revision 1.2  1998/12/13 21:05:59  kkrissia
 * *** empty log message ***
 *
 * Revision 1.1  1998/10/22 20:18:39  kkrissia
 * Dessin des lignes dans les MIP
 *
 */

#include "coord_image.hpp"

//--------------------------------------------------------------------------------
CoordImage ::  CoordImage( InrImage* inrimage )
//
{

  _inrimage = inrimage;

} // Constructor


//--------------------------------------------------------------------------------
Vect3D<float> CoordImage :: CoordImage2Reelles( const Vect3D<float>& v)
//                                    ------------------
{

  Si _inrimage == NULL AlorsRetourne v;

  return Vect3D<float>( 
		       (v.x+_inrimage->TrX())*_inrimage->VoxSizeX(),
		       (v.y+_inrimage->TrY())*_inrimage->VoxSizeY(),
		       (v.z+_inrimage->TrZ())*_inrimage->VoxSizeZ());


}


//--------------------------------------------------------------------------------
Vect3D<float> CoordImage :: CoordReelles2Image( const Vect3D<float>& v)
//                                    ------------------
{

  Si _inrimage == NULL AlorsRetourne v;

  return Vect3D<float>( 
		       v.x / _inrimage->VoxSizeX()- _inrimage->TrX(),
		       v.y / _inrimage->VoxSizeY()- _inrimage->TrY(),
		       v.z / _inrimage->VoxSizeZ()- _inrimage->TrZ());

}


//--------------------------------------------------------------------------------
Point3D CoordImage :: CoordReelles2Image( const Point3D& p)
{
  Si _inrimage == NULL AlorsRetourne p;

  return Point3D( 
		 p.x/ _inrimage->VoxSizeX()- _inrimage->TrX(),
		 p.y/ _inrimage->VoxSizeY()- _inrimage->TrY(),
		 p.z/ _inrimage->VoxSizeZ() - _inrimage->TrZ());

}


//--------------------------------------------------------------------------------
Vect3D<double> CoordImage :: CoordReelles2Image( const Vect3D<double>& v)
//                                    ------------------
{

  Si _inrimage == NULL AlorsRetourne v;

  return Vect3D<double>( 
		       (v.x/ _inrimage->VoxSizeX() - _inrimage->TrX()),
		       (v.y/ _inrimage->VoxSizeY() - _inrimage->TrY()),
		       (v.z/ _inrimage->VoxSizeZ() - _inrimage->TrZ()));

}


//--------------------------------------------------------------------------------
unsigned char CoordImage :: DansImage( const Point3D& p)
//
{

  Si _inrimage == NULL AlorsRetourne false;

    return (
            (p.x >= 0) Et ( p.x <= _inrimage->_tx-1) Et
            (p.y >= 0) Et ( p.y <= _inrimage->_ty-1) Et
            (p.z >= 0) Et ( p.z <= _inrimage->_tz-1) 
           );

} // DansImage()

//--------------------------------------------------------------------------------
/**
  Calcul une base de vecteurs orthogonaux et normes,
  dans le plan orthogonal au vecteur v
 */
void CoordImage :: CalculVecteursOrthogonaux( const Vect3D<float>& v1_prec, 
//                           -------------------------
							const Vect3D<float>& v, 
							Vect3D<float>& v1, 
							Vect3D<float>& v2)
{

  Si Norme(v) < 1E-2 Alors
    cerr << "CalculVecteursOrthogonaux \t norme trop faible \n";
  FinSi


  v2 = v ^ v1_prec;
  // Normalisation de v2
  v2.Normalise();

  v1 = v2 ^ v;
  // Normalisation de v1
  v1.Normalise();

} // CalculVecteursOrthogonaux()




//--------------------------------------------------------------------------------
/**
  Calcul une base de vecteurs orthogonaux et normes,
  dans le plan orthogonal au vecteur v
 */
void CoordImage :: CalculVecteursOrthogonaux( const Vect3D<float>& v,
							Vect3D<float>& v1, 
							Vect3D<float>& v2)
//                           -------------------------
{

// Strategie: on cherche la coordonnee de valeur absolue minimale
// et on prend un vecteur orthogonal dans le plan forme par les 2 autres directions

  Si Norme(v) < 1E-2 Alors
    cerr << "CalculVecteursOrthogonaux \t norme trop faible \n";
  FinSi

  Si fabsf(v.x)<=fabsf(v.y) Et fabsf(v.x)<=fabsf(v.z) Alors
    v1.x = 0;
    v1.y = -v.z;
    v1.z =  v.y;
  Autrement
  Si fabsf(v.y)<=fabsf(v.x) Et fabsf(v.y)<=fabsf(v.z) Alors
    v1.x = -v.z;
    v1.y = 0;
    v1.z =  v.x;
  Sinon
    v1.x = -v.y;
    v1.y =  v.x;
    v1.z = 0;
  FinSi

  // Normalisation de v1
  v1.Normalise();

  // Calcul de v2 = v ^ v1 (produit vectoriel)
  v2 = v^v1;

  // Normalisation de v2
  v2.Normalise();

} // CalculVecteursOrthogonaux()


