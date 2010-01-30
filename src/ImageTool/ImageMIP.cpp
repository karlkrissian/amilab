/*
    ==================================================
    Software : AMILab
    Authors  : Karl Krissian
    Email    : karl@bwh.harvard.edu

    AMILab is a language for image processing
    ==================================================
    Copyright (C) 1996-2005  Karl Krissian

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

    ================================================== 
   The full GNU Lesser General Public License file is in Devel/Sources/Prog/LesserGPL_license.txt
*/
/*
    ==================================================
    Software : AMILab
    Authors  : Karl Krissian
    Email    : karl@bwh.harvard.edu

    AMILab is a language for image processing
    ==================================================
    Copyright (C) 1996-2005  Karl Krissian

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

    ================================================== 
   The full GNU Lesser General Public License file is in Devel/Sources/Prog/LesserGPL_license.txt
*/
// Creation de projection MIP d'inrimage
// fichier ImageMIP.cpp
//
// Karl KRISSIAN 
//
// Sophia Antipolis le 09-07-97
//

// Objectif de cet objet:
//   A partir d'un pointeur sur une inrimage de format quelconque,
//   generer une inrimage de la projection MIP, 
//   a l'aide de la matrice de projection
//

// On va definir un objet "matrice de projection"
// qui va contenir des methodes permettant
// differente rotations


#include "style.hpp"
#include "ImageMIP.hpp"
#include "chaine.hpp"

//==========================================================================
// MEMBRES PRIVES
//==========================================================================

//
// MACROS
//

#define mat(i,j) _mat_rot[i][j]


//--------------------------------------------------------------------------
void ImageMIP :: InitInterpolLineaire()
//                        -------------------- 
{

   
    int i,y;

  //------- 8 voisins
  _Voisins    = new float** [2];
  _Voisins[0] = new float*  [2];
  _Voisins[1] = new float*  [2];
  _Voisins[0][0] = new float[2];
  _Voisins[0][1] = new float[2];
  _Voisins[1][0] = new float[2];
  _Voisins[1][1] = new float[2];

  //------ Subdivision en X, en Y, en Z
  _nbx = (int) (2*_voxel_size_x + 1E-10);
  _nby = (int) (2*_voxel_size_y + 1E-10);
  _nbz = (int) (2*_voxel_size_z + 1E-10);

  //------Interpolation sur deux plans YZ
  Pour(i, 0, 1)
    _Iyz[i] = new float*  [_nby];
    Pour(y,0,_nby-1)
      _Iyz[i][y] = new float[_nbz];
    FinPour
  FinPour

  //----- _delta_z
  _delta_z = new float [_nby];

  //----- _delta_yz
  _delta_yz = new float* [_nby];
  Pour(y,0,_nby-1)
    _delta_yz[y] = new float[_nbz];
  FinPour

} // InitInterpolLineaire()


//--------------------------------------------------------------------------
void ImageMIP :: FinInterpolLineaire()
//                        ------------------- 
{

  
    int i,y;

  delete [] _Voisins[1][1];
  delete [] _Voisins[1][0];
  delete [] _Voisins[0][1];
  delete [] _Voisins[0][0];
  delete [] _Voisins[1];
  delete [] _Voisins[0];
  delete [] _Voisins;

  //------Interpolation sur deux plans YZ
  Pour(i, 0, 1)
    Pour(y,0,_nby-1)
      delete [] _Iyz[i][y];
    FinPour
    delete [] _Iyz[i];
  FinPour

  //----- _delta_z
  delete[] _delta_z;

  //----- _delta_yz
  Pour(y,0,_nby-1)
    delete [] _delta_yz[y];
  FinPour
  delete [] _delta_yz;

} // FinInterpolLineaire()


//--------------------------------------------------------------------------
inline void ImageMIP :: InterpolePlanX( int pos)
//                                --------------
{

  
    register int posy,posz;
    register double r1,r2;
    register double dy1,dy2;
    register float** Iyz;
    register float** vois;
  // Intepoler _Iyz[pos]                            

  Iyz  = _Iyz[pos];
  vois = _Voisins[pos];

  // z = pos                                        
  dy1 = (vois[1][0] - vois[0][0])/ ((double) _nby); 
  r1 = vois[0][0]; 
  Iyz[0][0] = r1;

  // z = _nbz (stocke dans z=1)
  dy2 = (vois[1][1] - vois[0][1])/ ((double) _nby);
  r2 = vois[0][1];
  Iyz[0][1] = r2;

  Pour(posy,1,_nby-1)

    r1 += dy1;
    Iyz[posy][0] = r1;

    r2 += dy2;
    Iyz[posy][1] = r2;

  FinPour

  // posy -> 0, _nby -1
  Pour(posy,0,_nby-1)
    _delta_z[posy] = (Iyz[posy][1] - Iyz[posy][0])/((double) _nbz);
  FinPour
      
  // calcul final
  Pour(posz,1,_nbz-1)
  Pour(posy,0,_nby-1)
    Iyz[posy][posz] = Iyz[posy][posz-1] + _delta_z[posy];
  FinPour
  FinPour

} //  InterpolePlanX()


//--------------------------------------------------------------------------
inline void ImageMIP :: AppliqueRotation( const float x, const float y, const float z, 
//                                ----------------
                                            float* x1, float* y1, float* z1)
{

  *x1 = x*mat(0,0) + y*mat(0,1) + z*mat(0,2);
  *y1 = x*mat(1,0) + y*mat(1,1) + z*mat(1,2);
  *z1 = x*mat(2,0) + y*mat(2,1) + z*mat(2,2);

} // AppliqueRotation()


//--------------------------------------------------------------------------
inline void ImageMIP :: AppliqueRotation( const Vect3D<float> & v1, Vect3D<float>& v2)  
//                                ----------------
{

  v2.x = v1.x*mat(0,0) + v1.y*mat(0,1) + v1.z*mat(0,2);
  v2.y = v1.x*mat(1,0) + v1.y*mat(1,1) + v1.z*mat(1,2);
  v2.z = v1.x*mat(2,0) + v1.y*mat(2,1) + v1.z*mat(2,2);

} // AppliqueRotation()


//--------------------------------------------------------------------------
inline void ImageMIP :: AppliqueRotation(  double x, double y, double z, 
//                                ----------------
                                            double* x1, double* y1, double* z1)
{

  *x1 = x*mat(0,0) + y*mat(0,1) + z*mat(0,2);
  *y1 = x*mat(1,0) + y*mat(1,1) + z*mat(1,2);
  *z1 = x*mat(2,0) + y*mat(2,1) + z*mat(2,2);

} // AppliqueRotation()


//--------------------------------------------------------------------------
void ImageMIP :: AlloueImage()
//                        ----------- 
{

   Chaine nom,nom_pos;


  if (_imageMIP.use_count()==0) {
    nom = _image->Nom();
    nom += ".MIP";
    _imageMIP = InrImage::ptr(new InrImage( 
        _taille_MIP, _taille_MIP, 1, 
        _image->_format, (char*) nom ));
  }

  if (_imageMIP_posX.use_count()==0) {
    nom_pos = nom;
    nom_pos += ".X";
    _imageMIP_posX = InrImage::ptr(new InrImage(
          _taille_MIP, _taille_MIP, 1, 		 WT_UNSIGNED_CHAR, (char*) nom_pos ));
  }

  if (_imageMIP_posY.use_count()==0) {
    nom_pos = nom;
    nom_pos += ".Y";
    _imageMIP_posY = InrImage::ptr(new InrImage(
        _taille_MIP, _taille_MIP, 1, 
        WT_UNSIGNED_CHAR, (char*) nom_pos ));
  }

  if (_imageMIP_posZ.use_count()==0) {
    nom_pos = nom;
    nom_pos += ".Z";
    _imageMIP_posZ = InrImage::ptr(new InrImage( _taille_MIP, _taille_MIP, 1, 
                                    WT_UNSIGNED_CHAR, (char*) nom_pos ));
  }

  InitImage0();

} // AlloueImage()


//--------------------------------------------------------------------------
void ImageMIP :: AlloueImageMasque()
//                        -----------------
{

  
    Chaine nom;

  nom =  _image->Nom();
  nom+= ".masque";
  _image_masque = new InrImage( WT_UNSIGNED_CHAR, nom, _image);
  _image_masque->InitImage(1);

} // AlloueImageMasque()


//--------------------------------------------------------------------------
void ImageMIP :: ReAlloueImage()
//                        ------------- 
{


  _imageMIP.reset();
  _imageMIP_posX.reset();
  _imageMIP_posY.reset();
  _imageMIP_posZ.reset();

//  Si _image_masque != NULL AlorsFait delete _image_masque;

  AlloueImage();

} // AlloueImage()


//--------------------------------------------------------------------------
void ImageMIP :: InitImage0()
//                        ----------
{

  _imageMIP->InitImage(0);

  _imageMIP_posX->InitImage(0);
  _imageMIP_posY->InitImage(0);
  _imageMIP_posZ->InitImage(0);

} // InitImage0()


//==========================================================================
// MEMBRES PUBLICS
//==========================================================================

//--------------------------------------------------------------------------
ImageMIP ::  ImageMIP( InrImage* image)
//                                 --------
{

  _image = image;

  _voxel_size_x = _image->_size_x;
  _voxel_size_y = _image->_size_y;
  _voxel_size_z = _image->_size_z;

  _taille_MIP = (int)
                ( 1 + sqrt( _image->_tx * _voxel_size_x * _image->_tx * _voxel_size_x + 
                            _image->_ty * _voxel_size_y * _image->_ty * _voxel_size_y +
                            _image->_tz * _voxel_size_z * _image->_tz * _voxel_size_z) );


  _xmin = _ymin = _zmin = 0;
  _xmax = _image->_tx -1;
  _ymax = _image->_ty -1;
  _zmax = _image->_tz -1;

  _image_masque = NULL;

//  AlloueImage();

  InitMatriceId();

  // Par d�faut: valeur minimale = 0, valeur maximale = 1E20
  FixeLimites();

  _DepthCueing = false;
  _DepthCueingFactor = 0;

  _stereo = false;

  _Rapide = false;

} // Constructor 


//-----------------------------------------------------------------------
inline void ImageMIP :: Projection( float x, float y, float z,
//                    ------------
                                               float* px, float* py, float* pz)
{

  
    register float       x1,y1,z1;
    register double OMx,OMy,OMz, alpha;

  AppliqueRotation( x,y,z, &x1, &y1, &z1);
  
  Si _stereo Alors
    OMx = x1 - _d_oeil;
    OMy = y1;
    OMz = _d_oeil_ecran + _d_ecran_objet +z1;
 
    alpha = _d_oeil_ecran / OMz;

    *px = alpha*OMx + _d_oeil;
    *py = alpha*OMy;
    *pz = z1;
  Sinon
    *px = x1;
    *py = y1;
    *pz = z1;
  FinSi
         
  alpha = (_taille_MIP / 2.0);
  *px =  *px + alpha;   
  *py =  *py + alpha;

} // Projection()


//-----------------------------------------------------------------------
inline void ImageMIP :: Projection( double x, double y, double z,
//                    ------------
                                               double* px, double* py, double* pz)
{

  
    register double       x1,y1,z1;
    register double OMx,OMy,OMz, alpha;

  AppliqueRotation( x,y,z, &x1, &y1, &z1);
  
  Si _stereo Alors
    OMx = x1 - _d_oeil;
    OMy = y1;
    OMz = _d_oeil_ecran + _d_ecran_objet +z1;
 
    alpha = _d_oeil_ecran / OMz;

    *px = alpha*OMx + _d_oeil;
    *py = alpha*OMy;
    *pz = z1;
  Sinon
    *px = x1;
    *py = y1;
    *pz = z1;
  FinSi
         
  alpha = (_taille_MIP / 2.0);
  *px =  *px + alpha;   
  *py =  *py + alpha;

} // Projection()


//--------------------------------------------------------------------------
void ImageMIP :: ActiveStereo( float d_yeux, float d_oeil_ecran, 
//                         ------------
					float d_ecran_objet)
{

  _stereo        = true;
  _d_yeux        = d_yeux;
  _d_oeil_ecran  = d_oeil_ecran;
  _d_ecran_objet = d_ecran_objet;
  _d_oeil        = d_yeux/2.0;

} // ActiveStereo()


//--------------------------------------------------------------------------
void ImageMIP ::  FixeVoxelSize( float sx , float sy, float sz)
//                          -------------
{

  Si (sx == _voxel_size_x) Et (sy == _voxel_size_y) Et (sz == _voxel_size_z)
  AlorsRetourne;

  _voxel_size_x = sx;
  _voxel_size_y = sy;
  _voxel_size_z = sz;

  _taille_MIP = (int)
                ( 1 + sqrt( _image->_tx * _voxel_size_x * 
			    _image->_tx * _voxel_size_x + 
                            _image->_ty * _voxel_size_y * 
			    _image->_ty * _voxel_size_y +
                            _image->_tz * _voxel_size_z * 
			    _image->_tz * _voxel_size_z) );

  ReAlloueImage();

} // FixeVoxelSize


//--------------------------------------------------------------------------
void ImageMIP ::  FixeLimites( float min , float max)
//                          -----------
{

  _val_min = min;
  _val_max = max;


  Si _image_masque != NULL AlorsFait
    InitMasque();

} // FixeLimites


//--------------------------------------------------------------------------
void ImageMIP ::  InitMasque( )
//                          ----------
{

  
    int     x,y,z;
    double val;
    int     n;
    

  _image        -> InitBuffer();
  _image_masque -> InitBuffer();
  n = 1;

  Pour( z, _zmin, _zmax)
  Pour( y, _ymin, _ymax)

    _image        -> BufferPos( _xmin, y, z);
    _image_masque -> BufferPos( _xmin, y, z);
    Pour( x, _xmin, _xmax)

      val = _image->ValeurBuffer();
      Si (val <  _val_min + 1E-4) Ou
         (val > _val_max  - 1E-4) Alors
        n++;
      Sinon
        _image_masque->FixeValeur(n);
        _image_masque->IncBuffer(n);
        n = 1;
      FinSi

      _image->IncBuffer();

    FinPour

    Si n>1 Alors
      _image_masque->FixeValeur(n);
      _image_masque->IncBuffer(n);
      n = 1;
    FinSi

  FinPour
  FinPour


} // InitMasque()


//--------------------------------------------------------------------------
void ImageMIP ::  FixeDepthCue( unsigned char dephtcue, float facteur)
//                          -----------
{

  _DepthCueing = dephtcue;
  _DepthCueingFactor = facteur;

  Si facteur < 0.01 AlorsFait _DepthCueing = false;

} // FixeDepthCue()


//--------------------------------------------------------------------------
void ImageMIP ::  FixeRotation( float rX, float rY, float rZ)
//                          ------------
{

  // Calcul de la matrice de rotation
  //
  InitMatriceId();
  RotationX( rX);
  RotationY( rY);
  RotationZ( rZ);

} // FixeRotation()


//--------------------------------------------------------------------------
InrImage::ptr ImageMIP ::  CreeMIP( float rX, float rY, float rZ)
//                               -------
{

// printf("CreeMIP(_,_,_)");

  // Calcul de la matrice de rotation
  //
  InitMatriceId();
  RotationX( rX);
  RotationY( rY);
  RotationZ( rZ);

//  printf("%g %g %g\n", mat(0,0), mat(0,1), mat(0,2));
//  printf("%g %g %g\n", mat(1,0), mat(1,1), mat(1,2));
//  printf("%g %g %g\n", mat(2,0), mat(2,1), mat(2,2));

  return CreeMIP();

} // CreeMIP()


//--------------------------------------------------------------------------
InrImage::ptr ImageMIP ::  CreeMIPRapide( )
//                               -------------
{ 

  
    register int x,y,z;    // coordonnees d'un point dans l'image initiale
    float   x1,y1,z1; // coordonnes dans le repere centre au centre de
                              // l'image
    register int x3,y3,z3; // coordonnees dans l'image MIP
    register float   val_intensite,val;
    register float   tMIP_2;
    double   dz_x,dz_y,dz_z; // coordonnees dans le nouveau repere
    double   dy_x,dy_y,dy_z; // coordonnees dans le nouveau repere
    register double   x2,y2,z2; // coordonnees dans le nouveau repere
    register double   dx_x,dx_y,dx_z; // coordonnees dans le nouveau repere

   double x_yinit,y_yinit,z_yinit;
   double x_xinit,y_xinit,z_xinit;
   int n;
   long nb_points;

//  printf("CreeMIP()\n");

  nb_points = 0;

  Si _imageMIP == NULL Alors
    AlloueImage();
  Sinon
    InitImage0();
  FinSi

  Si _image_masque == NULL Alors
    AlloueImageMasque();
    InitMasque();
  FinSi

  // Initialisation de quelques variables
  tMIP_2 = (_taille_MIP / 2.0);

  AppliqueRotation( _voxel_size_x, 0,             0, 
		    &dx_x, &dx_y, &dx_z);
  AppliqueRotation( 0            , _voxel_size_y, 0, 
		    &dy_x, &dy_y, &dy_z);
  AppliqueRotation( 0           ,0            , _voxel_size_z, 
		    &dz_x, &dz_y, &dz_z);

  z1 = ( _zmin - (_image->_tz / 2.0))*_voxel_size_z;
  y1 = ( _ymin - (_image->_ty / 2.0))*_voxel_size_y;
  x1 = ( _xmin - (_image->_tx / 2.0))*_voxel_size_x;
  Projection( x1,y1,z1, &x2, &y2, &z2);

  // Parcours de l'image initiale
  //
  _image        -> InitBuffer();
  _image_masque -> InitBuffer();

  Pour( z, _zmin, _zmax)
    //cout << "z = " << z << endl;
    x_yinit = x2;
    y_yinit = y2;
    z_yinit = z2;
    Pour( y, _ymin, _ymax)
      x_xinit = x2;
      y_xinit = y2;
      z_xinit = z2;
      _image       ->BufferPos(_xmin,y,z);
      _image_masque->BufferPos(_xmin,y,z);

      x=_xmin;
      Repeter

        Si x>_xmin Alors
          nb_points++;
          val_intensite = _image->ValeurBuffer();

          x3 = (int) x2;
          y3 = (int) y2;

          _imageMIP->BufferPos( x3, y3, 0);

          Si _DepthCueing Alors
                z3 = (int) ( z2 + tMIP_2 );
                val = val_intensite * exp( -1.0 * z3 * _DepthCueingFactor / _taille_MIP );
              Sinon
	        val = val_intensite;
          FinSi

          Si  val >  _imageMIP->ValeurBuffer() Alors
                _imageMIP->FixeValeur( val);
          FinSi
        FinSi

        n = (int) _image_masque->ValeurBuffer();
        
        x  += n;
        x2 += n*dx_x;
        y2 += n*dx_y;
        z2 += n*dx_z;
        _image       ->IncBuffer(n);
        _image_masque->IncBuffer(n);

      JusquA x > _xmax FinRepeter

      x2 = x_xinit + dy_x;
      y2 = y_xinit + dy_y;
      z2 = z_xinit + dy_z;
    FinPour // y
    x2 = x_yinit + dz_x;
    y2 = y_yinit + dz_y;
    z2 = z_yinit + dz_z;

  FinPour // z

  //  cout <<  "Nombre de points traites = " << nb_points << endl;
  //  cout <<  "Pourcentage = " << nb_points/(_zmax-_zmin+1.0)/(_ymax-_ymin+1.0)/(_xmax-_xmin+1.0)*100.0 
  //       << endl;

  return _imageMIP;

} // CreeMIPRapide()


//--------------------------------------------------------------------------
InrImage::ptr ImageMIP ::  CreeMIP( )
//                               -------
{ 

  
    register int x,y,z;    // coordonnees d'un point dans l'image initiale
    register float   x1,y1,z1; // coordonnes dans le repere centre au centre de
                              // l'image
    register float   x2,y2,z2; // coordonnees dans le nouveau repere
    register int x3,y3,z3; // coordonnees dans l'image MIP
    register float   nz;
    register float   val_intensite, val;
    register float   tMIP_2;

//  printf("CreeMIP()\n");

  Si _Rapide Alors
    return CreeMIPRapide();
  FinSi

  Si _imageMIP == NULL Alors
    AlloueImage();
  Sinon
    InitImage0();
  FinSi

  // Initialisation de quelques variables
  tMIP_2 = (_taille_MIP / 2.0);

  // Parcours de l'image initiale
  //
  _image->InitBuffer();

  z1 = ( _zmin - (_image->_tz / 2.0))*_voxel_size_z;
  Pour( z, _zmin, _zmax)
    //cout << "z = " << z << endl;
    y1 = ( _ymin - (_image->_ty / 2.0))*_voxel_size_y;
    Pour( y, _ymin, _ymax)
      x1 = ( _xmin - (_image->_tx / 2.0))*_voxel_size_x;
      Pour( x, _xmin, _xmax)

        _image->BufferPos(x,y,z);

        val_intensite = _image->ValeurBuffer();
        Si (val_intensite >  _val_min + 1E-4) Et
           (val_intensite <= _val_max + 1E-4) Alors

          for(  nz=z1 ;  nz<z1+_voxel_size_z ;  nz+=0.5 Faire

            // T2 : (x1,y1,z1) -> (x2,y2,z2)
            Projection( x1, y1, nz, &x2, &y2, &z2);

            x3 = (int) x2;
            y3 = (int) y2;

            _imageMIP->BufferPos( x3, y3, 0);

            _imageMIP_posX->BufferPos( x3, y3, 0);
            _imageMIP_posY->BufferPos( x3, y3, 0);
            _imageMIP_posZ->BufferPos( x3, y3, 0);

            Si _DepthCueing Alors
              z3 = (int) ( z2 + tMIP_2 );
              val = val_intensite * exp( -1.0 * z3 * _DepthCueingFactor / _taille_MIP );
            Sinon
	      val = val_intensite;
            FinSi

            Si  val >  _imageMIP->ValeurBuffer() Alors
              _imageMIP->FixeValeur( val);
              _imageMIP_posX->FixeValeur(x);
              _imageMIP_posY->FixeValeur(y);
              _imageMIP_posZ->FixeValeur(z);
            FinSi

          } // end for

        FinSi

        x1 += _voxel_size_x;
      FinPour // x
      y1 += _voxel_size_y;
    FinPour // y
    z1 += _voxel_size_z;

  FinPour // z

  return _imageMIP;

} // CreeMIP()


//--------------------------------------------------------------------------
InrImage::ptr ImageMIP ::  CreeMIP2( )
//                               --------
{ 

  
    register int x,y,z;    // coordonnees d'un point dans l'image initiale
    register float   x1,y1,z1; // coordonnes dans le repere centre au centre de
                              // l'image
    register int x3,y3,z3; // coordonnees dans l'image MIP
    register float   nz;
    register float   val_intensite, val;
    register float   tMIP_2;

    // Projection de (x1,y1,z1)
    register float   px,py,pz;  
    // projection du vecteur unitaire de l'axe des X
    register float   dpx,dpy,dpz;

    // Projection de (x1,y1,nz)
    register float   px2,py2,pz2;
    // projection de la moitie du vecteur unitaire de l'axe des Z
    register float   dpx2,dpy2,dpz2;

//  printf("CreeMIP2()\n");

  Si _imageMIP == NULL Alors
    AlloueImage();
  Sinon
    InitImage0();
  FinSi

  // Initialisation de quelques variables
  tMIP_2 = (_taille_MIP / 2.0);

  // Parcours de l'image initiale
  //
  _image->InitBuffer();

  AppliqueRotation( 1, 0, 0,   &dpx,  &dpy,  &dpz);
  AppliqueRotation( 0, 0, 0.5, &dpx2, &dpy2, &dpz2);

  z1 = - (_image->_tz / 2.0)*_voxel_size_z;
  Pour( z, 0, _image->_tz - 1)
    y1 = - (_image->_ty / 2.0)*_voxel_size_y;
    Pour( y, 0, _image->_ty - 1)

      x1 = - (_image->_tx / 2.0)*_voxel_size_x;

      Projection( x1, y1, z1, &px, &py, &pz);

      Pour( x, 0, _image->_tx - 1)

        val_intensite = _image->ValeurBuffer();
        Si (val_intensite >  _val_min + 1E-4) Et
           (val_intensite <= _val_max + 1E-4) Alors

          px2 = px;
          py2 = py;
          pz2 = pz;

          for(  nz=z1 ;  nz<z1+_voxel_size_z ;  nz+=0.5 Faire

            x3 = (int) px2;
            y3 = (int) py2;

            _imageMIP->BufferPos( x3, y3, 0);

            Si _DepthCueing Alors
              z3 = (int) ( pz2 + tMIP_2 );
              val = val_intensite * exp( -1.0 * z3 * _DepthCueingFactor / _taille_MIP );
            Sinon
	      val = val_intensite;
            FinSi

            Si  val >  _imageMIP->ValeurBuffer() Alors
              _imageMIP->FixeValeur( val);
            FinSi

            px2 += dpx2;
            py2 += dpy2;
            pz2 += dpz2;

          } // end for

        FinSi

        _image->IncBuffer();
        x1 += _voxel_size_x;

        px += dpx;
        py += dpy;
        pz += dpz;

      FinPour // x
      y1 += _voxel_size_y;
    FinPour // y
    z1 += _voxel_size_z;

  FinPour // z

  return _imageMIP;

} // CreeMIP2()


//--------------------------------------------------------------------------
// take into account the voxel sizes
// to add more points to the projection
// the step size is 0.5 voxel in each direction
//
InrImage::ptr ImageMIP ::  CreeMIP_precise( )
//                               ---------------
{ 

  
    register int x,y,z;    // coordonnees d'un point dans l'image initiale
    register float   x1,y1,z1; // coordonnes dans le repere centre au centre de
                              // l'image
    register float   x2,y2,z2; // coordonnees dans le nouveau repere
    register int x3,y3,z3; // coordonnees dans l'image MIP
    register float   nx,ny,nz;
    register float   val_intensite, val;
    register float   tMIP_2;

//  printf("CreeMIP_precise\n");

  Si _imageMIP == NULL Alors
    AlloueImage();
  Sinon
    InitImage0();
  FinSi

  // Initialisation de quelques variables
  tMIP_2 = (_taille_MIP / 2.0);

  // Parcours de l'image initiale
  //
  _image->InitBuffer();

  z1 = - (_image->_tz / 2.0)*_voxel_size_z;
  Pour( z, 0, _image->_tz - 1)

    y1 = - (_image->_ty / 2.0)*_voxel_size_y;
    Pour( y, 0, _image->_ty - 1)

      x1 = - (_image->_tx / 2.0)*_voxel_size_x;
      Pour( x, 0, _image->_tx - 1)

        val_intensite = _image->ValeurBuffer();
        Si (val_intensite >  _val_min + 1E-4) Et
           (val_intensite <= _val_max + 1E-4) Alors

          for(  nx=x1 ;  nx<x1+_voxel_size_x ;  nx+=0.5 Faire
          for(  ny=y1 ;  ny<y1+_voxel_size_y ;  ny+=0.5 Faire
          for(  nz=z1 ;  nz<z1+_voxel_size_z ;  nz+=0.5 Faire

            // T2 : (x1,y1,z1) -> (x2,y2,z2)
            Projection( nx, ny, nz, &x2, &y2, &z2);

            // T3 : (x2,y2,z2) -> (x3,y3)
            x3 = (int) x2;
            y3 = (int) y2;

            _imageMIP->BufferPos( x3, y3, 0);

            Si _DepthCueing Alors
              z3 = (int) ( z2 + tMIP_2 );
              val = val_intensite * exp( -1.0 * z3 * _DepthCueingFactor / _taille_MIP );
            Sinon
	      val = val_intensite;
            FinSi

            Si  val >  _imageMIP->ValeurBuffer() Alors
              _imageMIP->FixeValeur( val);
            FinSi

          } // end for
          } // end for
          } // end for

        FinSi

        _image->IncBuffer();
        x1 += _voxel_size_x;

      FinPour // x
      y1 += _voxel_size_y;

    FinPour // y
    z1 += _voxel_size_z;

  FinPour // z

  return _imageMIP;

} // CreeMIP_precise()


//--------------------------------------------------------------------------
InrImage::ptr ImageMIP ::  CreeMIP_interpol_lineaire( )
//                               -------------------------
{ 

  
    register int  x,y,z;    // coordonnees d'un point dans l'image initiale
    register float    x1,y1,z1; // coordonnes dans le repere centre au centre de
                              // l'image
    register float    x2,y2,z2; // coordonnees dans le nouveau repere
    register int  x3,y3,z3; // coordonnees dans l'image MIP
    register float    nx,ny,nz;
    register float    val_intensite, val;
    register float    tMIP_2;
    register float    dx,dy,dz;
    register float    rx,ry,rz;


  Si _imageMIP == NULL Alors
    AlloueImage();
  Sinon
    InitImage0();
  FinSi

  // Initialisation de quelques variables
  tMIP_2 = (_taille_MIP / 2.0);

  // Parcours de l'image initiale
  //
  _image->InitBuffer();

  dx = 0.5/_voxel_size_x;
  dy = 0.5/_voxel_size_y;
  dz = 0.5/_voxel_size_z;

  z1 = - (_image->_tz / 2.0)*_voxel_size_z;
  Pour( z, 0, _image->_tz - 1)

    y1 = - (_image->_ty / 2.0)*_voxel_size_y;
    Pour( y, 0, _image->_ty - 1)


      x1 = - (_image->_tx / 2.0)*_voxel_size_x;
      Pour( x, 0, _image->_tx - 1)


        for(  nx=x1, rx=x 
        ;  nx<x1+_voxel_size_x - 1E-10
        ;  nx+=0.5, rx+=dx Faire

        for(  ny=y1, ry=y 
        ;  ny<y1+_voxel_size_y - 1E-10
        ;  ny+=0.5, ry+=dy Faire

        for(  nz=z1 , rz=z
        ;  nz<z1+_voxel_size_z - 1E-10
        ;  nz+=0.5, rz+=dz Faire

          val_intensite = (*_image)( (int) rx, (int) ry, (int)rz);
          Si (val_intensite >  _val_min + 1E-4) Et
             (val_intensite <= _val_max + 1E-4) Alors

            val_intensite = _image->InterpLinIntensite( rx, ry, rz );


            // T2 : (x1,y1,z1) -> (x2,y2,z2)
            Projection( nx, ny, nz, &x2, &y2, &z2);

            // T3 : (x2,y2,z2) -> (x3,y3)
            x3 = (int) x2;
            y3 = (int) y2;

            _imageMIP->BufferPos( x3, y3, 0);

            Si _DepthCueing Alors
              z3 = (int) ( z2 + tMIP_2 );
              val = val_intensite * exp( -1.0 * z3 * _DepthCueingFactor / _taille_MIP );
            Sinon
	      val = val_intensite;
            FinSi

            Si  val >  _imageMIP->ValeurBuffer() Alors
              _imageMIP->FixeValeur( val);
            FinSi

          FinSi

        } // end for
        } // end for
        } // end for

        _image->IncBuffer();
        x1 += _voxel_size_x;

      FinPour // x
      y1 += _voxel_size_y;

    FinPour // y
    z1 += _voxel_size_z;

  FinPour // z

  return _imageMIP;

} // CreeMIP_interpol_lineaire()


//--------------------------------------------------------------------------
InrImage::ptr ImageMIP ::  CreeMIP_interpol_lineaire2( )
//                               --------------------------
{ 

  
    register int  x,y,z;    // coordonnees d'un point dans l'image initiale
    register float    x1,y1,z1; // coordonnes dans le repere centre au centre de
                              // l'image
    register float    x2,y2,z2; // coordonnees dans le nouveau repere
    register int  x3,y3,z3; // coordonnees dans l'image MIP
    register float    nx,ny,nz;
    register float    val_intensite, val;
    register float    tMIP_2;
    register float**  tmp;

    register int  posy,posz;

//  printf("CreeMIP_interpol_lineaire2() \n");

  InitInterpolLineaire();

  //-----------------------------------------------
  Si _imageMIP == NULL Alors
    AlloueImage();
  Sinon
    InitImage0();
  FinSi

  // Initialisation de quelques variables
  tMIP_2 = (_taille_MIP / 2.0);

  z1 = - (_image->_tz / 2.0)*_voxel_size_z;
  Pour( z, 0, _image->_tz - 2)

    y1 = - (_image->_ty / 2.0)*_voxel_size_y;
    Pour( y, 0, _image->_ty - 2)

      x1 = - (_image->_tx / 2.0)*_voxel_size_x;
      
      // Si x < _image->_tx - 1 Alors Interpoler _Iyz[1]
      _image->VoisinageYZ( 0, y, z, _Voisins[0]);

      // Intepoler _Iyz[0]
      InterpolePlanX(0);

      Pour( x, 0, _image->_tx - 1)

        _image->VoisinageYZ(x+1,y,z,_Voisins[1]);

        // Sinon _Iyz[1] = _Iyz[0]
        Si x < _image->_tx - 1 Alors 
          // Intepoler _Iyz[1]
          InterpolePlanX(1);
        Sinon 
          _Iyz[1] = _Iyz[0];
        FinSi

        // Calcul des _delta_yz
        Pour(posy, 0, _nby-1)
        Pour(posz, 0, _nbz-1)
          _delta_yz[posy][posz] = (_Iyz[1][posy][posz] - 
                                   _Iyz[0][posy][posz]  )/((double)_nbx);
        FinPour
        FinPour

        for(  nx=x1
        ;  nx<x1+_voxel_size_x - 1E-10
        ;  nx+=0.5 Faire

        for(  ny=y1, posy = 0 
        ;  ny<y1+_voxel_size_y - 1E-10
        ;  ny+=0.5, posy++ Faire

        for(  nz=z1 , posz = 0
        ;  nz<z1+_voxel_size_z - 1E-10
        ;  nz+=0.5, posz++ Faire

          val_intensite = _Iyz[0][posy][posz];

          // Incrementation pour la prochaine it�ration
          _Iyz[0][posy][posz] += _delta_yz[posy][posz];

          Si (val_intensite >  _val_min + 1E-4) Et
             (val_intensite <= _val_max + 1E-4) Alors


            // T2 : (x1,y1,z1) -> (x2,y2,z2)
            Projection( nx, ny, nz, &x2, &y2, &z2);

            // T3 : (x2,y2,z2) -> (x3,y3)
            x3 = (int) x2;
            y3 = (int) y2;

            _imageMIP->BufferPos( x3, y3, 0);

            Si _DepthCueing Alors
              z3 = (int) ( z2 + tMIP_2 );
              val = val_intensite * exp( -1.0 * z3 * _DepthCueingFactor / _taille_MIP );
            Sinon
	      val = val_intensite;
            FinSi

            Si  val >  _imageMIP->ValeurBuffer() Alors
              _imageMIP->FixeValeur( val);
            FinSi

          FinSi

        } // end for  // nz
        } // end for  // ny
        } // end for  // nx

//        _image->IncBuffer();
        x1 += _voxel_size_x;

        // On intervertit les voisins d'un plan
        tmp = _Voisins[0];
        _Voisins[0] = _Voisins[1];
        _Voisins[1] = tmp;

        // On intervertit l'interpolation d'un plan
        tmp = _Iyz[0];
        _Iyz[0] = _Iyz[1];
        _Iyz[1] = tmp;

      FinPour // x
      y1 += _voxel_size_y;

    FinPour // y
    z1 += _voxel_size_z;

  FinPour // z

  FinInterpolLineaire();

  return _imageMIP;

} // CreeMIP_interpol_lineaire2()


//--------------------------------------------------------------------------
InrImage::ptr ImageMIP ::  CreeMIP_interpol_lineaire3( )
//                               --------------------------
{ 

  return InrImage::ptr();

} // CreeMIP_interpol_lineaire3()


//--------------------------------------------------------------------------
void ImageMIP :: RotationX( double angle)
//                         ---------
{ 
     double m10,m11,m12,m20,m21,m22;
     double c,s; // cosinus et sinus

  c = cosd(angle);
  s = sind(angle);

  m10 =  c*mat(1,0) + s*mat(2,0);
  m11 =  c*mat(1,1) + s*mat(2,1);
  m12 =  c*mat(1,2) + s*mat(2,2);
  m20 = -s*mat(1,0) + c*mat(2,0);
  m21 = -s*mat(1,1) + c*mat(2,1);
  m22 = -s*mat(1,2) + c*mat(2,2);

  mat(1,0) = m10;
  mat(1,1) = m11;
  mat(1,2) = m12;
  mat(2,0) = m20;
  mat(2,1) = m21;
  mat(2,2) = m22; 

} // RotationX


//--------------------------------------------------------------------------
void ImageMIP :: RotationY( double angle)
//                         ---------
{
     double m22,m21,m20,m02,m01,m00;
     double c,s; // cosinus et sinus

  c = cosd(angle);
  s = sind(angle);

  m21 =  c*mat(2,1) + s*mat(0,1);
  m22 =  c*mat(2,2) + s*mat(0,2);
  m20 =  c*mat(2,0) + s*mat(0,0);
  m01 = -s*mat(2,1) + c*mat(0,1);
  m02 = -s*mat(2,2) + c*mat(0,2);
  m00 = -s*mat(2,0) + c*mat(0,0);

  mat(2,1) = m21;
  mat(2,2) = m22;
  mat(2,0) = m20;
  mat(0,1) = m01;
  mat(0,2) = m02;
  mat(0,0) = m00; 

} // RotationY

//--------------------------------------------------------------------------
void ImageMIP :: RotationZ( double angle)
//                         ---------
{
     double m00,m02,m01,m10,m12,m11;
     double c,s; // cosinus et sinus

  c = cosd(angle);
  s = sind(angle);

  m02 =  c*mat(0,2) + s*mat(1,2);
  m00 =  c*mat(0,0) + s*mat(1,0);
  m01 =  c*mat(0,1) + s*mat(1,1);
  m12 = -s*mat(0,2) + c*mat(1,2);
  m10 = -s*mat(0,0) + c*mat(1,0);
  m11 = -s*mat(0,1) + c*mat(1,1);

  mat(0,2) = m02;
  mat(0,0) = m00;
  mat(0,1) = m01;
  mat(1,2) = m12;
  mat(1,0) = m10;
  mat(1,1) = m11; 

} // RotationZ


//-----------------------------------------------------------------------
void ImageMIP :: DetecteRotations( int *rot_x, int *rot_y, int *rot_z )
//                         ----------------
{

  
    double cosa,sina,cosb,sinb,cosc,sinc;

  sinb = mat(2,0);
  cosb = sqrt( 1 - sinb*sinb );

  Si fabsf(cosb) > 1E-3 Alors

    cosc =   mat(0,0) / cosb;
    sinc = - mat(1,0) / cosb;

    cosa =   mat(2,2) / cosb;
    sina = - mat(2,1) / cosb;

    *rot_x = (int) atand2( sina, cosa);
    *rot_y = (int) atand2( sinb, cosb);
    *rot_z = (int) atand2( sinc, cosc);
  
  Sinon

    *rot_y = (int) atand2( sinb, cosb);
    *rot_z = (int) (atand2( mat(0,1), mat(1,1)) - sinb* *rot_z);

  FinSi

} // DetecteRotations()


//-----------------------------------------------------------------------
void ImageMIP :: Projection2( float x, float y, float z, float* px, float* py, float* pz)
//                         -----------
{

  
    register float       x0,y0,z0;
//    register double OMx,OMy,OMz, alpha;

  x0 = ( x - (_image->_tx/2.0))*_voxel_size_x;
  y0 = ( y - (_image->_ty/2.0))*_voxel_size_y;
  z0 = ( z - (_image->_tz/2.0))*_voxel_size_z;

  *px = x0*mat(0,0) + y0*mat(0,1) + z0*mat(0,2) + (_taille_MIP/2.0);
  *py = x0*mat(1,0) + y0*mat(1,1) + z0*mat(1,2) + (_taille_MIP/2.0);
  *pz = x0*mat(2,0) + y0*mat(2,1) + z0*mat(2,2);
//  Projection( x0,y0,z0,px,py,pz);

} // Projection2()


//-----------------------------------------------------------------------
float ImageMIP :: ValDepthCue( float x, float y, float z)
//                         -----------
{

  
    register float res;

  // Valeur dans le repere centre de la distance du point a l'origine
  // le long de l'axe des Z
  res  = ( x - (_image->_tx / 2.0) ) * mat(2,0);
  res += ( y - (_image->_ty / 2.0) ) * mat(2,1);
  res += ( z - (_image->_tz / 2.0) ) * mat(2,2);

  // Normalisation par rapport a l'observateur
  res = _taille_MIP / 2.0 + res;

  // Facteur de DepthCueing
  return  exp( -1.0 * res * _DepthCueingFactor / _taille_MIP );

} // ValDepthCue()


//-----------------------------------------------------------------------
/// Position dans l'image 3D du point projete
void ImageMIP :: PosPoint( int x, int y, int& posx, int& posy, int& posz)
//                         --------
{

  posx = (unsigned char) (*_imageMIP_posX)(x,y,0);
  posy = (unsigned char) (*_imageMIP_posY)(x,y,0);
  posz = (unsigned char) (*_imageMIP_posZ)(x,y,0);

} // PosPoint()


//-----------------------------------------------------------------------
Vect3D<float>  ImageMIP :: ProjetteVecteur( const Vect3D<float>& vect)
//                                  ---------------
{

  
    Vect3D<float> vproj;

  AppliqueRotation( vect, vproj );
  return vproj;

} //  ProjetteVecteur()
