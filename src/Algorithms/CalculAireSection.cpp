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
/***************************************************************************
 * $Author: karl $
 * $Revision: 1.3 $
 * $Log: CalculAireSection.cpp,v $
 * Revision 1.3  2005/11/16 14:03:07  karl
 * added LGPL license
 *
 * Revision 1.2  2004/04/30 20:10:15  karl
 * several improcements
 *
 * Revision 1.1.1.1  2004/02/02 20:47:07  karl
 * source code in C++
 *
 * Revision 1.1.1.1  2000/04/07 16:10:13  karl
 * Sources code
 *
 * Revision 1.1  1999/05/31 16:30:04  kkrissia
 * *** empty log message ***
 *
 ***************************************************************************/


#include "CalculAireSection.hpp"



//======================================================================
// class CalculAireSection
//======================================================================

//----------------------------------------------------------------
float CalculAireSection :: InterpoleZero( float val1, float val2)
//                                 -------------
{
 
  Si (fabsf(val1) < EPSILON)  AlorsRetourne 0.0;
  Si (fabsf(val2) < EPSILON)  AlorsRetourne 1.0;

  Si val1 > 0 Alors
    Si val2 < 0 Alors
      return (val1/(val1-val2));
    Sinon
      return -1;
    FinSi
  Sinon
    Si val2 > 0 Alors
      return (-val1/(-val1+val2));
    Sinon
      return -1;
    FinSi
  FinSi

} // InterpoleZero()


//--------------------------------------------------
///
  /**
    calcul de l'aire du triangle positif, 
    le signe de l'element i est different de celui
    de son successeur ainsi que de celui de son predecesseur
   */
float CalculAireSection :: SurfaceTriangle( float* val, int i)
//
{

  return ( 0.5 * 
	     InterpoleZero(val[i],val[ (i+1)%4]) * 
	     InterpoleZero(val[i],val[ (i+3)%4])
           );

} // SurfaceTriangle()



//--------------------------------------------------
///
  /**
    calcul de l'aire du trapeze
    le deux valeurs negatives de val sont i et (i+1)%4
   */
float CalculAireSection :: SurfaceTrapeze( float* val, int i)
//
{

  return ( 0.5 * 
	     InterpoleZero(val[ i       ],val[ (i+3)%4 ]) + 
	     InterpoleZero(val[ (i+1)%4 ],val[ (i+2)%4 ])
	     );

} // SurfaceTrapeze()


//--------------------------------------------------
///
float CalculAireSection :: InterpoleSurface( float* val)
//
{

  
    int i,j;

  // cas 1: 1 seul sommet negatif
  Si _negatifs==1 Alors
    i = 0;
    TantQue (Signe(val[i])>=0)Et(i<4) Faire i++; FinTantQue
    Si i==4 Alors
      std::cerr << "CalculAireSection::InterpoleSurface() \t _negatifs==1 Valeur negative non trouvee\n";
      return 0;
    FinSi
    return SurfaceTriangle( val, i);
  Autrement

  // cas 2: 3 sommets negatifs
  Si _negatifs==3 Alors
    i = 0;
    TantQue (Signe(val[i])<0)Et(i<4) Faire i++; FinTantQue
    Si i==4 Alors
      std::cerr << "CalculAireSection::InterpoleSurface() \t _negatifs==3 Valeur positive non trouvee\n";
      std::cerr << val[0] << " , "  << val[1] << " , "  << val[2] << " , "  << val[3] << std::endl;
      return 0;
    FinSi
    return (1.0-SurfaceTriangle( val, i));
  Autrement

  Si _negatifs==2 Alors

    // Recherche du premier element positif
    i = 0;
    TantQue (Signe(val[i])<0)Et(i<4) Faire i++; FinTantQue
    Si i==4 Alors
      std::cerr << "CalculAireSection::InterpoleSurface() \t negatifs=2 Valeur positive non trouvee\n";
      return 0;
    FinSi

    // Recherche du premier element negatif
    j = 0;
    TantQue (Signe(val[i])>=0)Et(j<4) Faire i=(i+1)%4; j++; FinTantQue
    Si j==4 Alors
      std::cerr << "CalculAireSection::InterpoleSurface() \t negatifs=2 Valeur negative non trouvee\n";
      return 0;
    FinSi
     
    // cas 3: 2 sommets consecutifs negatifs
    Si Signe(val[(i+1)%4])<0 Alors
      return SurfaceTrapeze( val, i);
    Autrement

    // cas 4: a gerer a part ? 2 sommet negatifs non consecutifs
    Si Signe(val[(i+2)%4])<0 Alors
      // interpolation de la valeur au centre pour lever l'ambiguite ?
      // Est-ce bin rigoureux ??
      Si Signe(val[4]) <0 Alors
        return (1 - 
		  SurfaceTriangle( val, (i+1)%4) - 
		  SurfaceTriangle( val, (i+3)%4)
		  );
      Sinon
        // Faut-il tenir compte des 2 triangles ?
        return ( 
		  SurfaceTriangle( val, (i+1)%4) + 
		  SurfaceTriangle( val, (i+3)%4)
		  );
      FinSi
    //
    Sinon
      std::cerr << "CalculAireSection::InterpoleSurface() \t Probleme dans l'algo ? \n";
    FinSi

  FinSi // _negatifs == 2

  std::cerr << "CalculAireSection::InterpoleSurface() \t la valeur de _negatifs n'est pas";
  std::cerr << " comprise entre 1 et 4 ...\n";

  return 0.5;

} // InterpoleSsurface()


//--------------------------------------------------
///
int CalculAireSection :: Signe( float val)
//
{

    Si val < -EPSILON AlorsRetourne -1;
    Si val >  EPSILON AlorsRetourne  1;
    return 0;


}

//--------------------------------------------------
///
void CalculAireSection :: CreeGrille( )
//
{

  
    int i;

    _grille_signe      = (int**) new int*[ _max_i-_min_i+1];
    _grille_parcours   = (int**) new int*[ _max_i-_min_i+1];
    _grille_dans_liste = (int**) new int*[ _max_i-_min_i+1];
    _grille_valeurs    = (float**)   new float*  [ _max_i-_min_i+1];

    Pour( i, 0, _max_i-_min_i)
      _grille_signe     [i]  = new int[ _max_j-_min_j+1];
      _grille_parcours  [i]  = new int[ _max_j-_min_j+1];
      _grille_dans_liste[i]  = new int[ _max_j-_min_j+1];
      _grille_valeurs   [i]  = new float  [ _max_j-_min_j+1];
    FinPour

} // CreeGrille()


//--------------------------------------------------
///
void CalculAireSection :: InitGrille( )
//
{

  
    int i,j;

  Pour(i,_min_i,_max_i)
  Pour(j,_min_j,_max_j)
    GParcours(i,j)  = 0;
    GDansListe(i,j) = 0;
    GSigne(i,j)     = 0;
    GValeurs(i,j)   = 0.0;
  FinPour
  FinPour

} // InitGrille()


//--------------------------------------------------
///
void CalculAireSection :: DeleteGrille( )
//
{

  
    int i;

    Pour( i, 0, _max_i-_min_i)
      delete [] _grille_signe     [i];
      delete [] _grille_parcours  [i];
      delete [] _grille_dans_liste[i];
      delete [] _grille_valeurs   [i];
    FinPour
    delete [] _grille_signe;
    delete [] _grille_parcours;
    delete [] _grille_dans_liste;
    delete [] _grille_valeurs;

} // DeleteGrille()

//--------------------------------------------------
/// Ajoute un point dans la liste des points a propager
void CalculAireSection :: AjoutePropage( int i, int j)
  throw (LimitesAtteintes)
//
{


  Si ( i<_min_i ) Ou ( i>=_max_i ) Ou
     ( j<_min_j ) Ou ( j>=_max_j ) 
  AlorsFait
    throw LimitesAtteintes("CalculAireSection::AjoutePropage()");
  // On teste si le point est strictement a l'interieur de la grille,
  // Les points du bord superieur de la grille de sont pas propage car
  // on ne connait pas le signe de leurs voisins

  Si (GParcours(i,j) == 0) Et (GDansListe(i,j)==false)
  Alors
    _propage->AjoutePoint(i,j,0);
    GDansListe(i,j)=true;
  FinSi


} // AjoutePropage()

//======================================================================
// Membres Publics

//---------------------------------------------------
  CalculAireSection ::  CalculAireSection( 
				InrImage* image, float resolution)
    //:propage(10000)
//
{

  Si GB_debug AlorsFait
   std::cout << "CalculAireSection  \n";  


  
    int n;

  // initialisation des quadrillages
  _resolution = resolution;
  n = (int) (macro_min( 200, 18.0/image->_size_x/_resolution)) ;
  _min_i = _min_j = - n;
  _max_i = _max_j =   n;
  _surf_carre  = _resolution*_resolution*
                 image->_size_x*image->_size_y;

  CreeGrille();

  _image_contour = image;
  _coord_image  = new CoordImage( _image_contour);


  _image_surfinf    = (InrImage*) NULL;
  _image_surfsup    = (InrImage*) NULL;
  _image_sections   = (InrImage*) NULL;

  _propage = new PropagePoints(10000);

} // Constructor()


//---------------------------------------------------
CalculAireSection :: ~CalculAireSection( )
//
{

  Si GB_debug AlorsFait
   std::cout << "CalculAireSection ~\n";  

  delete _propage;

  DeleteGrille();
  delete _coord_image;

} // Destructor()


//---------------------------------------------------
///
void CalculAireSection :: ChangeImage( InrImage* image)
//
{


  Si GB_debug AlorsFait
   std::cout << "CalculAireSection::ChangeImage() \n";  

  _image_contour = image;


} // ChangeImage()

//---------------------------------------------------
///
int CalculAireSection :: TailleX()
//
{

  return _max_i-_min_i+1;

} // TailleX()

//---------------------------------------------------
///
int CalculAireSection :: TailleY()
//
{

  return _max_i-_min_i+1;

} // TailleY()

//---------------------------------------------------
///
int CalculAireSection :: CalculSigne( int i, int j, int p, const Point3D point, float& val)
//
{


    
      Point3D        pos;
      Vect3D<float>  vecteur;
      int         signe, posOK;

    signe = 0;
    val   = 0.0;

    posOK = ((i>=_min_i) Et (i<=_max_i) Et (j>=_min_j) Et (j<=_max_j));
    Si posOK Alors
      signe = GSigne(i,j);
      val   = GValeurs(i,j);
    FinSi

    Si signe == 0 Alors
      vecteur = ((float) i*_resolution)*v1 + ((float) j*_resolution)*v2;

      // image 2D
      Si _image_contour->_tz == 1 Alors
        pos = point + vecteur;
        val = _image_contour->InterpLinIntensite(pos.x,pos.y);
        signe = Signe(val);
      // image 3D
      Sinon
        pos = point + _coord_image->CoordReelles2Image( vecteur);
        Si _coord_image->DansImage(pos) Alors
          val = _image_contour->InterpLinIntensite(pos.x,pos.y,pos.z);
          signe = Signe(val);
        FinSi
      FinSi

      Si posOK Alors 
         GSigne(i,j)   = signe;
         GValeurs(i,j) = val;
      FinSi

    FinSi
    
    Si signe >= 0  Alors
    //   std::cout << " val pos: " << val << " ";
       _positifs++;
    Sinon 
    //   std::cout << " val neg: " << val << " ";
       _negatifs++;
    FinSi

    return signe;

	  
} // CalculSigne()


//---------------------------------------------------
///
int CalculAireSection :: CalculSigneMilieu( int i, int j, const Point3D point, float& val)
//
{


  
    Point3D        pos;
    Vect3D<float>  vecteur;

  val   = 0.0;

  vecteur = ((float) (i+0.5)*_resolution)*v1 + ((float) (j+0.5)*_resolution)*v2;

  // image 2D
  Si _image_contour->_tz == 1 Alors
    pos = point + vecteur;
    val = _image_contour->InterpLinIntensite(pos.x,pos.y);

  // image 3D
  Sinon
    pos = point + _coord_image->CoordReelles2Image( vecteur);
    Si _coord_image->DansImage(pos) Alors
      val = _image_contour->InterpLinIntensite(pos.x,pos.y,pos.z);
    FinSi
  FinSi

  return Signe(val);

	  
} // CalculSigneMilieu()


//---------------------------------------------------
///
void CalculAireSection :: InitImagesSurf( InrImage* imsurfinf, 
//
						    InrImage* imsurfsup, 
						    InrImage* imsections, 
						    InrImage* iminitiale)
{


  _image_surfinf  = imsurfinf;
  _image_surfsup  = imsurfsup;
  _image_sections = imsections;
  _image_initiale = iminitiale;


} // InitImagesSurf()


//---------------------------------------------------
///
void CalculAireSection :: RemplitSection( int p, const Point3D point )
//
{


  
    int i,j;
    Point3D        pos;
    Vect3D<float>  vecteur;


  Si _image_sections == NULL AlorsFait return;

  Pour(i,_min_i,_max_i)
  Pour(j,_min_j,_max_j)

    vecteur = ((float) i*_resolution)*v1 + ((float) j*_resolution)*v2;

    _image_sections->BufferPos(i-_min_i,j-_min_j,p);

    Si _image_initiale->_tz == 1 Alors
      pos = point +  vecteur;
      Si pos.x >= _image_initiale->_tx-1 Ou
         pos.y >= _image_initiale->_ty-1 
      Alors
      _image_sections->FixeValeur( (*_image_initiale)((int)pos.x,(int)pos.y,0) );
      Sinon
        _image_sections->FixeValeur( 
          _image_initiale->InterpLinIntensite(pos.x,pos.y) );
      FinSi
    Sinon
      pos = point + _coord_image->CoordReelles2Image( vecteur);
      _image_sections->FixeValeur( 
         _image_initiale->InterpLinIntensite(pos.x,pos.y,pos.z) );
    FinSi

  FinPour
  FinPour


      
} // RemplitSection()


//---------------------------------------------------
///
float CalculAireSection :: Aire( int p, Point3D point, 
					    Vect3D<float> vect1, Vect3D<float> vect2,
					    float* surf_inf, float* surf_sup, float* surf_interp)
//
{


  
    int         i,j,k;
    float           val[5];
    int         posneg[4]; // position des sommets negatifs trouves

  v1 = vect1;
  v2 = vect2;

  point.x = point.x/_image_initiale->_size_x-_image_initiale->_translation_x;
  point.y = point.y/_image_initiale->_size_y-_image_initiale->_translation_y;
  point.z = point.z/_image_initiale->_size_z-_image_initiale->_translation_z;

  RemplitSection( p, point);

  // Calcul de l'aire par propagation
  InitGrille();

  _propage->Init(0,0,0);
  TantQue _propage->PointsATraiter() > 0 Faire
    Si Non(_propage->ProchainPoint( i, j, k)) Alors
      break;
    FinSi

    Si j<0 Alors
      _positifs=0;
    FinSi

    Si GParcours(i,j) != 0 Alors
      _propage->EnlevePointCourant();
      continue;
    FinSi

    _positifs = _negatifs = 0;

    k = 0;
    Si CalculSigne( i  , j  , p, point, val[0]) <0 AlorsFait posneg[k++] = 0;
    Si CalculSigne( i+1, j  , p, point, val[1]) <0 AlorsFait posneg[k++] = 1;
    Si CalculSigne( i  , j+1, p, point, val[2]) <0 AlorsFait posneg[k++] = 2;
    Si CalculSigne( i+1, j+1, p, point, val[3]) <0 AlorsFait posneg[k++] = 3;

    Si _image_surfinf!= NULL AlorsFait _image_surfinf->BufferPos(i-_min_i,j-_min_j,p);
    Si _image_surfsup!= NULL AlorsFait _image_surfsup->BufferPos(i-_min_i,j-_min_j,p);

    Si _negatifs == 4 Alors
      surf_inf   [p] += _surf_carre;
      Si _image_surfinf!= NULL AlorsFait _image_surfinf->FixeValeur(255); 

      surf_sup   [p] += _surf_carre;
      Si _image_surfsup!= NULL AlorsFait _image_surfsup->FixeValeur(255); 

      surf_interp[p] += _surf_carre;
    Autrement
    Si _negatifs > 0 Alors
      // en cas d'ambiguite: 2 sommets negatifs opposes, on rajoute la valeur du milieu
      // Mauvais critere: a refaire ...
      Si _negatifs == 2 Et ((posneg[1]-posneg[0]) == 2) Alors
        CalculSigneMilieu(i,j,point,val[4]);
      FinSi

      surf_sup[p]    += _surf_carre;
      Si _image_surfsup != NULL AlorsFait _image_surfsup->FixeValeur(255); 

      surf_interp[p] += InterpoleSurface( val) * _surf_carre;
    FinSi

try
{
    Si _negatifs>0 Alors
      Si (GSigne(i  ,j  )<0) Ou (GSigne(i+1,j  )<0) AlorsFait AjoutePropage(i  ,j-1);
      Si (GSigne(i+1,j  )<0) Ou (GSigne(i+1,j+1)<0) AlorsFait AjoutePropage(i+1,j  );
      Si (GSigne(i  ,j  )<0) Ou (GSigne(i  ,j+1)<0) AlorsFait AjoutePropage(i-1,j  );
      Si (GSigne(i  ,j+1)<0) Ou (GSigne(i+1,j+1)<0) AlorsFait AjoutePropage(i  ,j+1);
    FinSi
      }
catch (LimitesAtteintes)
{
}
    _propage->EnlevePointCourant();
    GParcours(i,j) = 1;

  FinTantQue

  /*
 std::cout << "********** "<< std::endl << std::endl;
 std::cout << p << " " << surf_inf[p] << ":" 
                   << surf_sup[p] 
                   << " interp " <<  surf_interp[p] << std::endl;
 std::cout << "********** "<< std::endl << std::endl;
  */

  return surf_interp[p];


} // Aire()


