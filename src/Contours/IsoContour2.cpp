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
 * $Revision: 1.12 $
 * $Log: IsoContour2.cpp,v $
 * Revision 1.12  2005/11/16 14:03:07  karl
 * added LGPL license
 *
 * Revision 1.11  2005/08/08 21:52:11  karl
 * local statistics for noise
 *
 * Revision 1.10  2005/04/04 05:05:30  karl
 * Improving Skeletonization: better line connextion and avoiding some local loops
 *
 * Revision 1.9  2005/02/12 01:36:19  karl
 * improved EstimeRayons
 *
 * Revision 1.8  2005/02/01 20:48:46  karl
 * Changed the contour numbers for the inclusion to work better
 *
 * Revision 1.7  2005/01/29 01:56:36  karl
 * changing sign definition for IsoContour2 and also for Computing Connected Components
 *
 * Revision 1.6  2004/08/12 04:23:08  karl
 * put on verbose some outputs
 *
 * Revision 1.5  2004/08/03 20:04:01  karl
 * Connected component + lines in vrml
 *
 * Revision 1.4  2004/07/01 15:03:29  karl
 * Added features to Connected Components, Resize with translation, volume rendering
 *
 * Revision 1.3  2004/06/02 22:57:34  karl
 * Connected Components + some bugs fixed
 *
 * Revision 1.2  2004/04/30 20:10:15  karl
 * several improcements
 *
 * Revision 1.1.1.1  2004/02/02 20:47:07  karl
 * source code in C++
 *
 * Revision 1.2  2000/09/19 12:19:00  karl
 * *** empty log message ***
 *
 * Revision 1.1.1.1  2000/04/07 16:10:14  karl
 * Sources code
 *
 * Revision 1.1  1999/05/31 16:30:04  kkrissia
 * *** empty log message ***
 *
 ***************************************************************************/


#include <boost/scoped_array.hpp>
using namespace boost;

#if defined(WIN32)
  #include <windows.h>
#endif

#include <stdlib.h>
#include "IsoContour2.hpp"


//extern InrImage* image_contours;




//======================================================================
// class IsoContour2
//======================================================================

//======================================================================
// Fonctions Membres Privees
//======================================================================
  
//-----------------------------------------------------------------------------------------
unsigned char IsoContour2 :: CoordOK( int x, int y, int z)
//
{

    Si x < 0 Ou x >= _image->_tx AlorsFait return false;
    Si y < 0 Ou y >= _image->_ty AlorsFait return false;
    Si z < 0 Ou z >= _image->_tz AlorsFait return false;

    return true;

} // CoordOK()


//-----------------------------------------------------------------------------------------
// Initialisation des 4 positions des sommets de la face
void IsoContour2 :: InitFace( int num, int s1, int s2, int s3, int s4)
//
{

    _face[num][0] = s1;
    _face[num][1] = s2;
    _face[num][2] = s3;
    _face[num][3] = s4;

} // InitFace()
  

//--------------------------------------------------
///
unsigned char   IsoContour2 :: PassageParZero( int& signe,   double valeur)
//							    
{

    Si SIGNE(valeur) == 1 Alors 
      Si signe == 0 AlorsFait signe = 1;
      Si signe == -1 Alors
        return true;
      FinSi
    FinSi
    Si SIGNE(valeur) == -1 Alors 
      Si signe == 0 AlorsFait signe = -1;
      Si signe == 1 Alors
        return true;
      FinSi
    FinSi
      //    Si fabs(valeur) < 1E-5 Alors 
      //       return true;
      //    FinSi

    return false;

} // PassageParZero()

//--------------------------------------------------
///
unsigned char IsoContour2 :: ExisteContour( int x, int y, int z) throw ( OutOfRange)
//
{

    
      int   sommet,x1,y1,z1;
      int   signe;

     signe = 0;

     Pour( sommet, 0, 7)

      x1 = x + _voxel.PosX(sommet);
      y1 = y + _voxel.PosY(sommet);
      z1 = z + _voxel.PosZ(sommet);

      Si (x1>=_image->_tx) Ou (y1 >=_image->_ty) Ou (z1>=_image->_tz) 
      AlorsFait
        throw  OutOfRange();

      Si PassageParZero( signe, (*_image)(x1,y1,z1)) AlorsFait
        return true;

    FinPour

    return false;

} // ExisteContour()


//--------------------------------------------------
///
int IsoContour2 :: contour( const PointContour& p1)
//
{

    return (int) ( (*_image_num_contour)( p1.x,p1.y,p1.z));

} // contour()



//--------------------------------------------------
///
void IsoContour2 :: InitImagesSurf( int tx, int ty, int tz)
//
{

  
    Chaine nom;

  nom = _nom_image_resultat;
  nom += "-sections.inr.gz";
  _image_sections = new InrImage( tx, ty, tz, WT_FLOAT, nom);
  _image_sections->InitImage(0.0);
  _image_sections->SetVoxelSize( _resolution, _resolution, _pas_abscisse);


  nom = _nom_image_resultat;
  nom += "-surfinf.inr.gz";
  _image_surfinf = new InrImage( WT_UNSIGNED_CHAR, nom, _image_sections);
  _image_surfinf->InitImage(0);


  nom = _nom_image_resultat;
  nom += "-surfsup.inr.gz";
  _image_surfsup = new InrImage( WT_UNSIGNED_CHAR, nom, _image_sections);
  _image_surfsup->InitImage(0);

} // InitImagesSurf()


//--------------------------------------------------
///
void IsoContour2 :: DeleteImagesSurf( )
//
{

  delete _image_surfinf;
  delete _image_surfsup;
  delete _image_sections;

} // DeleteImagesSurf()

//-------------------------------------------------
/// Calcule le nombre total de points de la ligne inclus dans le contour
void IsoContour2 :: CalculTotalPointsLigne()
//
{

  
    int i,c,nbpts;

  Pour(i,1,_nb_contours)

    c = i;
    nbpts = _tab_ccinfo[i].ptsline;

    TantQue (c!=0) Faire
      _tab_ccinfo[c].ptsline_total += nbpts;

      Si c>=0 Et c<=_nb_contours Alors
        c = _tab_ccinfo[c].contenance;
      Sinon
        // Probleme ...
        c = 0;
      FinSi
    FinTantQue

  FinPour // i

} // CalculTotalPointsLigne()


//======================================================================
// Fonctions Membres Publiques
//======================================================================


//----------------------------------------------------------------------
///
IsoContour2 :: Constructeur IsoContour2( InrImage* image0)
//
{

    _topology=0; // linear interpolation by default

    _image = image0;
    _image_contour = new InrImage( WT_FLOAT, "image_contour.inr.gz", image0);
    _image_contour->InitImage(0.0);

    // Initialisation des 6 faces
    InitFace(0,0,1,3,2);
    InitFace(1,0,1,5,4);
    InitFace(2,0,2,6,4);
    InitFace(3,4,5,7,6);
    InitFace(4,2,3,7,6);
    InitFace(5,1,3,7,5);

    _coord_sommet[0].x = 0;
    _coord_sommet[0].y = 0;

    _coord_sommet[1].x = 1;
    _coord_sommet[1].y = 0;

    _coord_sommet[2].x = 1;
    _coord_sommet[2].y = 1;

    _coord_sommet[3].x = 0;
    _coord_sommet[3].y = 1;

    _tab_ccinfo = (ConnectedComponentInfo*) NULL;
/*
    _tab_contenance       = (int*) NULL;
    _tab_signe            = (int*) NULL;
    _tab_ptsligne         = (int*) NULL;
    _tab_ptsligne_total   = (int*) NULL;
    _tab_nbpts            = (int*) NULL;
    _tab_moygrad          = (float*  ) NULL;
*/

    _centre_sphere = (int*) NULL;
    _rayon_sphere  = 0.0;


    _image_ligne         = NULL;
    _image_contours      = NULL;
    _image_num_contour   = NULL;
    _image_un_contour    = NULL;
    _image_gradient      = NULL;
    _input_image         = NULL;
    _sort_image          = NULL;
    _inclusion_image     = NULL;
    _sign_image          = NULL;
    _size_image          = NULL;

    _max_fond   = 0;
    _resolution = 1;
    _lignes     = NULL;
    _nbpts_ligne = 0;


    _pas_abscisse=1;

    _verbose=0;
    _sauve=0;
    _debug=0;

} // Constructeur

//----------------------------------------------------------------------
///
IsoContour2 :: Destructeur IsoContour2()
//
{



  EffaceImage( _image_contour);

  if (_tab_ccinfo!=(ConnectedComponentInfo*)NULL) {
    delete []_tab_ccinfo;
    _tab_ccinfo=(ConnectedComponentInfo*)NULL;
  }
  
/*
  EffaceTabEntier( _tab_contenance);
  EffaceTabEntier( _tab_signe);
  EffaceTabEntier( _tab_ptsligne);
  EffaceTabEntier( _tab_ptsligne_total);
  EffaceTabEntier( _tab_nbpts);
  EffaceTabReel(   _tab_moygrad);
*/

} // Destructeur

 
//----------------------------------------------------------------------
///
void IsoContour2 :: RechercheContours( InrImage* image)
//
{

     
      int x,y,z;
      int num;
      int taille;

   // Image and _image_num_contour are the same ...
   // Confusing ...

   _max_points = 0;

    Si _debug AlorsFait
      cout << " RechercheContours \n";

    num = 0;

    Si _debug AlorsFait
      cout << " InitImage \n";

    image->InitImage(0.0);

    Pour(x,0,image->_tx-1)
    Pour(y,0,image->_ty-1)
    Pour(z,0,image->_tz-1)

      Si (*_image_num_contour)(x,y,z)==0 Alors
        num++;
        Si _debug AlorsFait
	  printf("parcours contour %d \n",num);
        ParcoursContour(x,y,z,num,&taille);
      FinSi

    FinPour
    FinPour
    Si _verbose Alors
      Si x > 0 Alors 
        printf("\b\b\b");
      Sinon
        printf("x = : ");
      FinSi
      printf("%3d",x); 
      fflush(stdout);
    FinSi
    FinPour

    _nb_contours = num;

} // RechercheContours()


//----------------------------------------------------------------------
void IsoContour2 :: ParcoursContour( int x, int y, int z,  
//
					      int num,  int* taille)
{

  
    int x1,y1,z1;
    int posx, posy, posz;
    int x2,y2,z2;
    int  signe; // sommet;
    PropagePoints propage(500000);
    int  max_points;
    int  dist; // mesure de distance (au carre) du voisin
    Point_3D<int> pt[4];
    float             val[4],test;
    int           nx,ny,n;
    unsigned char          propage_point;
    int           prop,prop0;

  max_points = 0;

//  Si _verbose AlorsFait
//    cout << "Parcours du contour numero " << num << endl;


  prop0 = 0;

  propage.Init( x,y,z);
  *taille = 0;
  TantQue propage.PointsATraiter() > 0 Faire

    Si propage.PointsATraiter()>max_points 
    AlorsFait 
       max_points = propage.PointsATraiter();

    Si Non(propage.ProchainPoint( x1, y1, z1)) Alors
      break;
    FinSi

    pt[0].Init(x1,y1,z1);

    val[0]= (*_image)(x1,y1,z1);
    signe = SIGNE( val[0]);

    switch (_topology) {

    case TOPOLOGY_LINEARINTERPOLATION:
    //   ----------------------------
    // go though 26 neighbors,
    // 6 are direct neighbors, the process must be fast
    // 12 are 2D diagonal neighbors, there is a risk of ambiguity to solve
    // 8 are not taken into account
    // a lot can be done to improve the speed ...
    Pour(posx,-1,1)
      Si posx !=0 Alors
        pt[1].Init(x1+posx,y1,z1);
        nx = 2;
      Sinon
        nx = 1;
      FinSi

    Pour(posy,-1,1)
      ny = nx;
      Si posy != 0 Alors
        pt[ny].Init(x1, y1+posy, z1);
        ny++;
        Si ny==3 AlorsFait
          pt[ny].Init(x1+posx, y1+posy,z1);
      FinSi

    Pour(posz,-1,1)
      n = ny;
      // We only look a 2D diagonal neighbors (4 points to save)
      // only in the case n==2 we need to put more point in pt
      Si n==2 Et posz!=0 Alors
        pt[n].Init(x1,     y1,     z1+posz);
        n++;
        pt[n].Init(x1+posx,y1+posy,z1+posz);
      FinSi

      // 1. les voisins directs:
      dist = macro_abs(posx) + macro_abs(posy) + macro_abs(posz);
      x2 = x1+posx;
      y2 = y1+posy;
      z2 = z1+posz;
      Si Non(CoordOK(x2, y2, z2)) AlorsFait continue;
      propage_point = false;
      Si (*_image_num_contour)( x2, y2, z2) != 0 AlorsFait continue;


      Si dist == 1 Alors
        propage_point = (SIGNE( (*_image)(x2,y2,z2)) == signe);          
      Autrement
        // here only 2D case ...
        Si dist == 2 Alors
         // cas ambigu ??
        Si n!=3 AlorsFait
  	  cout << "IsoContour2::ParcoursContour() \t"
       	       << "Probleme: points mal initialises ...\n";

        val[1] = (*_image)(pt[1].x,pt[1].y,pt[1].z);
        Si (SIGNE( val[1]) == signe)
        AlorsFait continue;

        val[2] = (*_image)(pt[2].x,pt[2].y,pt[2].z);
        Si (SIGNE( val[2]) == signe)
        AlorsFait continue;

        val[3] = (*_image)(pt[3].x,pt[3].y,pt[3].z);
        Si (SIGNE( val[3]) != signe)
        AlorsFait continue;

        // Si on arrive ici, c'est qu'il y a une ambiguite sur la
        // face (pt[0],pt[1],pt[3],pt[2]):

        float sum = val[0]+val[3]-val[1]-val[2];
	Si fabsf(sum)>0 Alors
          test = (val[0]*val[3]-val[1]*val[2])/
                 (val[0]+val[3]-val[1]-val[2]);
	Sinon
          test = 0;
        FinSi

        propage_point =  (signe == SIGNE(test));
          
        FinSi
      Si propage_point Alors
          Si Non(propage.AjoutePoint( x2, y2, z2)) AlorsFait
            return;
          prop = propage.PointsATraiter();
          _image_num_contour->BufferPos( x2, y2, z2);
          _image_num_contour->FixeValeur( -1);

      FinSi

    FinPour
    FinPour
    FinPour

    break;
    case TOPOLOGY_THINNING:
      // only the interior is a C27 neighborhood
      Pour(posx,-1,1)
      Pour(posy,-1,1)
      Pour(posz,-1,1)

      dist = macro_abs(posx) + macro_abs(posy) + macro_abs(posz);
      if (dist==0) continue;
      if ((signe==-1)&&(dist!=1)) continue;

      x2 = x1+posx;
      y2 = y1+posy;
      z2 = z1+posz;
      Si Non(CoordOK(x2, y2, z2)) AlorsFait continue;
      propage_point = false;
      Si (*_image_num_contour)( x2, y2, z2) != 0 AlorsFait continue;

      Si dist == 1 Alors
        propage_point= (SIGNE( (*_image)(x2,y2,z2)) == signe);
      Autrement
	propage_point=((signe==1)Et(SIGNE( (*_image)(x2,y2,z2)) ==1));

      Si propage_point Alors
          Si Non(propage.AjoutePoint( x2, y2, z2)) AlorsFait
            return;
          prop = propage.PointsATraiter();
          _image_num_contour->BufferPos( x2, y2, z2);
          _image_num_contour->FixeValeur( -1);

      FinSi

      FinPour
      FinPour
      FinPour

      break;
    }

    propage.EnlevePointCourant();

    _image_num_contour->BufferPos( x1, y1, z1);
    _image_num_contour->FixeValeur( num);

    (*taille)++;

  FinTantQue

  Si max_points > _max_points Alors
    _max_points = max_points;
    cout << " max points " << max_points << endl;
  FinSi

} // ParcoursContour()


//----------------------------------------------------------------------
// Is this function ever used ???
//
void IsoContour2 :: PropageContour( InrImage* image_contour, int num_contour)
//
{

    
      int     x,y,z;
      int     x1,y1,z1;
      float       moy;        // moyenne sur les voisins non nuls
      int     nb_voisins; // nombre de voisins non nuls
      long pts_zero, pts_zero_prec;
      float       val;
      int     n1,n2, sommet;
 

    Pour(z,0,_image_num_contour->_tz-2)
    Pour(y,0,_image_num_contour->_ty-2)
    Pour(x,0,_image_num_contour->_tx-2)

      n1 = n2 = 0;
      Pour( sommet, 0, 7)
        x1 = x + _voxel.PosX(sommet);
        y1 = y + _voxel.PosY(sommet);
        z1 = z + _voxel.PosZ(sommet);

        Si (*_image_num_contour)(x1,y1,z1) == num_contour
        AlorsFait n1++;

        Si (*_image_num_contour)(x1,y1,z1) == _tab_ccinfo[num_contour].contenance
        AlorsFait n2++;
      FinPour

      Si n1>0 Et n2 > 0 AlorsFait
      Pour( sommet, 0, 7)
        x1 = x + _voxel.PosX(sommet);
        y1 = y + _voxel.PosY(sommet);
        z1 = z + _voxel.PosZ(sommet);
if (_image_un_contour!=NULL) {
        _image_un_contour->BufferPos( x1, y1, z1);
        _image_un_contour->FixeValeur( (*_image)(x1,y1,z1));
}
      FinPour

	/*
      n = (int) (*_image_num_contour)(x,y,z);
      Si n == num_contour Ou
         n == _tab_ccinfo[num_contour].contenance 
      Alors
        val = (*_image)(x,y,z);
        _image_un_contour->BufferPos( x, y, z);
        _image_un_contour->FixeValeur( val);
      FinSi
	*/
    FinPour
    FinPour
    FinPour

    pts_zero=0;
    pts_zero_prec = pts_zero;

    Repeter

      pts_zero_prec = pts_zero;
      pts_zero = 0;

      Pour(z,0,image_contour->_tz-1)
      Pour(y,0,image_contour->_ty-1)
      Pour(x,0,image_contour->_tx-1)

        Si fabsf((*image_contour)(x,y,z)) < 1E-5 Alors
          pts_zero++;

          moy = 0;
          nb_voisins= 0;

          Pour(z1, macro_max(0,z-1), macro_min(image_contour->_tz-1, z+1))
          Pour(y1, macro_max(0,y-1), macro_min(image_contour->_ty-1, y+1))
          Pour(x1, macro_max(0,x-1), macro_min(image_contour->_tx-1, x+1))

             val = (*image_contour)(x1,y1,z1);
             Si fabsf(val) > 1E-5 Alors
               Si (nb_voisins > 0) Et (moy*val < 0) Et
	          ((*_image_num_contour)(x1,y1,z1) != num_contour)
               Alors
  	         cerr << "IsoContour2::PropageContour() \t Probleme : point " 
                      << x << "," << y << "," << z 
                      << " voisins de signes differents " << endl;
               FinSi
               nb_voisins++;
               moy += val;
             FinSi

          FinPour
          FinPour
          FinPour
 
          Si nb_voisins > 0 Alors
            image_contour->BufferPos(x,y,z);
            image_contour->FixeValeur( moy/nb_voisins);
            pts_zero --;
          FinSi

        FinSi

      FinPour
      FinPour
      FinPour

      cout << "*** il reste " << pts_zero << " points nuls \n";

    JusquA (pts_zero == 0)Ou (pts_zero == pts_zero_prec) 
    FinRepeter    

} // PropageContour()


//----------------------------------------------------------------------
void IsoContour2 :: DefinitInterieur( int signe)
//
{

    
      PointContour point_courant, point_suivant;
      int contour_courant, nouv_contour;
      int x0=0;
      int y0,z0;
//      int x,y,z;
      int i,n,c;
      float   pourcent=0.0,pourcent_total=0.0;
      float   dx,dy,dz;

  _tab_ccinfo = new ConnectedComponentInfo[_nb_contours+1];

    Pour(i,1,_nb_contours)
      _tab_ccinfo[i].number       = i;
    FinSi

/*    _tab_contenance       = new int[ _nb_contours+1];
    _tab_signe            = new int[ _nb_contours+1];

if (_lignes!=NULL) {
      _tab_ptsligne         = new int[ _nb_contours+1];
      _tab_ptsligne_total   = new int[ _nb_contours+1];
}
    _tab_moygrad          = new float  [ _nb_contours+1];
    _tab_nbpts            = new int[ _nb_contours+1];
    Pour(i,1,_nb_contours)
      _tab_contenance[i]       = -1;
      _tab_signe[i]            =  0;
if (_lignes!=NULL) {
      _tab_ptsligne[i]         =  0;
      _tab_ptsligne_total[i]   =  0;
}
      _tab_moygrad[i]          =  0;
      _tab_nbpts[i]            =  0;
    FinSi
*/

    // 1. choisir un point a l'exterieur dans le plan z=0
    bool found = false;
    z0 = 0;
    printf("max fond = %f \n", (float)_max_fond);
    Pour(y0,0, _image_contours->_ty-1)
      Pour(x0,0, _image_contours->_tx-1)
         found =  ((*_input_image)(x0,y0,z0) < _max_fond);
         if (found) break;
      FinPour
      if (found) break;
      //Si (*_input_image)(x0,y0,z0) < _max_fond AlorsFait break;
    FinPour

    if (!found) {
      cerr<< "IsoContour2::DefinitInterieur() \t point a zero non trouve \n"; 
      return;
    }

    point_courant.InitImage( _image_contours);
    point_courant.Init(x0,y0,z0,-1);
    point_courant.InitVal( );

    contour_courant = contour(point_courant); // contour exterieur
    _tab_ccinfo[contour_courant].contenance = 0;
    
    // Propagation du point et definition des informations relatives aux contours
    point_suivant = point_courant;

    TantQue (point_suivant++) Faire
      point_suivant.InitVal( );

      Si point_courant.Signe()*point_suivant.Signe() < 0 Alors
        // Changement de signe: changement de contour
        nouv_contour = contour( point_suivant);
        // Mise a jour du nombre de traversees du contour et de la moyenne de la norme du gradient
        _tab_ccinfo[nouv_contour].nbpts++;
        if (_image_gradient!=NULL)
          _tab_ccinfo[nouv_contour].meangrad += (*_image_gradient)( point_courant.x,
							    point_courant.y,
							    point_courant.z);
        else
          _tab_ccinfo[nouv_contour].meangrad = 0;
       
 
        Si nouv_contour != _tab_ccinfo[contour_courant].contenance Alors
          // on entre dans un nouveau contour

	  // Traitement du signe
          Si _tab_ccinfo[nouv_contour].sign == 0 Alors
            _tab_ccinfo[nouv_contour].sign = point_suivant.Signe();
          Sinon
            Si point_suivant.Signe() != _tab_ccinfo[nouv_contour].sign AlorsFait
  	      cerr << "IsoContour2::DefinitInterieur() \t "
	           << "probleme de signe du contour "
 	           << nouv_contour << endl;
          FinSi

          // Traitement de l'appartenance
          Si _tab_ccinfo[nouv_contour].contenance == -1 Alors
            _tab_ccinfo[nouv_contour].contenance = contour_courant;
          Sinon
            Si contour_courant != _tab_ccinfo[nouv_contour].contenance AlorsFait
  	      cerr << "IsoContour2::DefinitInterieur() \t "
	           << "probleme d'appartenance du contour "
 	           << nouv_contour << endl;
          FinSi

          point_courant   = point_suivant;
          contour_courant = nouv_contour;

        Sinon
          // on sort du contour courant

          point_courant   = point_suivant;
          contour_courant = _tab_ccinfo[contour_courant].contenance;    
 
        FinSi
      Sinon
        // Pas de changement de contour
        point_courant   = point_suivant;

      FinSi

      Si _image_ligne != (InrImage*) NULL Alors
        Si (*_image_ligne)(point_courant.x, 
			  point_courant.y, 
			  point_courant.z) > 127 Alors
          _tab_ccinfo[contour_courant].ptsline++;
        FinSi
      Autrement
      Si _centre_sphere != (int*) NULL Alors
        dx = point_courant.x - _centre_sphere[0];
        dy = point_courant.y - _centre_sphere[1];
        dz = point_courant.z - _centre_sphere[2];
        Si sqrt(dx*dx+dy*dy+dz*dz) < _rayon_sphere AlorsFait
          _tab_ccinfo[contour_courant].ptsline++;
      FinSi

    FinTantQue

    if (_image_ligne) {
      Si _centre_sphere != (int*) NULL Alors
        _nbpts_ligne = (int) (4.0/3.0*PI*_rayon_sphere*
			   _rayon_sphere*_rayon_sphere);
        cout << "nbpts_ligne = " << _nbpts_ligne << endl;
      FinSi


      CalculTotalPointsLigne();

    }

    n = 0;

    Pour(i,1,_nb_contours)
      if (_image_ligne) {
        pourcent       = (100.0*_tab_ccinfo[i].ptsline)/(_nbpts_ligne);
        pourcent_total = (100.0*_tab_ccinfo[i].ptsline_total)/(_nbpts_ligne);
      }


      Si _tab_ccinfo[i].nbpts == 0 Alors
        printf(" contour %3d aucun point ...", i);
      Sinon
      if (_image_ligne != (InrImage*) NULL)
        if (_verbose)
	  printf(" contour %3d %3d %3d %e %2.2f\n",
	       i, _tab_ccinfo[i].sign, 
	       _tab_ccinfo[i].contenance, 
	       _tab_ccinfo[i].meangrad/_tab_ccinfo[i].nbpts, 
	       pourcent);
       else
        if (_verbose)
	  printf(" contour %3d %3d %3d %d ",
	       i, _tab_ccinfo[i].sign, 
	       _tab_ccinfo[i].contenance, 
	       _tab_ccinfo[i].nbpts);

      FinSi
      /*
cout << " contour " << i 
     << " " << _tab_signe[i]
     << " " << _tab_contenance[i]
     << " " << pourcent_total << endl;
      */

//      fflush(stdout);
      if (_verbose)
	printf("  %2.1f %%",
	     pourcent_total);

      Si i%3 == 0 Alors
        if (_verbose) printf("\n");
      Sinon
        if (_verbose) printf("\t");
      FinSi

      if (_image_ligne) {
      Si (_tab_ccinfo[i].ptsline_total> 0.6*_nbpts_ligne) Et 
         (_tab_ccinfo[i].sign==signe) 
      Alors
        cout << n << " " << i << endl;
        Si n>0 Alors

          // Si plusieurs contours negatifs contiennent toute la ligne
          // on prend le plus petit:
          // On garde le contour s'il est inclus dans le pr�c�dent.

          c = i;
          TantQue (c!=0) Et (c!=_contour_choisi) Faire
            Si c>=0 Et c<=_nb_contours Alors
              c = _tab_ccinfo[c].contenance;
            Sinon
              // Probleme ...
              c = 0;
            FinSi
          FinTantQue

          Si c==_contour_choisi Alors
            _contour_choisi = i;
          FinSi

        Sinon
          _contour_choisi = i;
        FinSi
        n++;
      FinSi
	} else {
	_contour_choisi = 1;
	}
    FinPour

} // DefinitInterieur( )



//----------------------------------------------------------------------
int cc_compare(const void* c1,const void* c2)
{

  ConnectedComponentInfo cci1 = *((ConnectedComponentInfo*)c1);
  ConnectedComponentInfo cci2 = *((ConnectedComponentInfo*)c2);

  if (cci1.sign==0) return 1;
  if (cci2.sign==0) return -1;

  if (cci1.sign>cci2.sign) return -1;
  if (cci1.sign<cci2.sign) return 1;

  if (cci1.nbpts>cci2.nbpts) return -1;
  if (cci1.nbpts<cci2.nbpts) return 1;
  
  return 0;
}

//----------------------------------------------------------------------
///
void IsoContour2 ::  SortContours()
{
  int i,n;
//   int val;
    scoped_array<int> reorder(new int[_nb_contours+1]);
//	int reorder[_nb_contours+1];

   // sort contours
    qsort((void *)_tab_ccinfo, _nb_contours+1, sizeof (ConnectedComponentInfo), cc_compare);

    if (_verbose) printf("\n Sorted contours \n\n");

    // Display the sorted connected components
    Pour(i,0,_nb_contours)
      //      if (_tab_ccinfo[i].number !=0) {
        if (_verbose)
          printf(" contour %3d %3d %3d %6d ",
            i,_tab_ccinfo[i].number, _tab_ccinfo[i].sign, 
                _tab_ccinfo[i].nbpts);
        reorder[_tab_ccinfo[i].number]=i;
        if (_verbose)
            Si i%3 == 0 Alors
                printf("\n");
            Sinon
                printf("\t");
            FinSi
	  //      }
    FinPour

    _sort_image = new InrImage(_nb_contours+1,1,1,WT_SIGNED_INT,"sort_image.ami.gz");
    Pour(i,0,_nb_contours)
      _sort_image->BufferPos(i,0,0);
      _sort_image->FixeValeur(reorder[i]);
    FinPour

    _inclusion_image = new InrImage(_nb_contours+1,1,1,WT_SIGNED_INT,"inclusion_image.ami.gz");
    Pour(i,0,_nb_contours)
      n=_tab_ccinfo[i].number;
      _inclusion_image->BufferPos(n,0,0);
      _inclusion_image->FixeValeur(_tab_ccinfo[i].contenance);
    FinPour

    _sign_image = new InrImage(_nb_contours+1,1,1,WT_SIGNED_SHORT,"sign_image.ami.gz");
    Pour(i,0,_nb_contours)
      n=_tab_ccinfo[i].number;
      _sign_image->BufferPos(n,0,0);
      _sign_image->FixeValeur(_tab_ccinfo[i].sign);
    FinPour

    _size_image = new InrImage(_nb_contours+1,1,1,WT_SIGNED_INT,"size_image.ami.gz");
    Pour(i,0,_nb_contours)
      n=_tab_ccinfo[i].number;
      _size_image->BufferPos(n,0,0);
      _size_image->FixeValeur(_tab_ccinfo[i].nbpts);
    FinPour

    printf("\n");
    /*
    // Apply the sorting to the image
    _image_num_contour->InitBuffer();
    Repeter
      val=(int)_image_num_contour->ValeurBuffer();
      _image_num_contour->FixeValeur((float)reorder[val]);
    JusquA Non(_image_num_contour->IncBuffer())
    FinRepeter
    */
}


//----------------------------------------------------------------------
///
void IsoContour2 :: CalculAire( )
//
{

    
      Point3D        point,p1,p2;
      Vect3D<float>  v1_prec;
      // Pour assurer la continuite de la direction tangente
      Vect3D<float>  t_prec(0,0,0); 
      int         n,p;
      float           abs_curv, pas_abs;
      float           longueur;
      int         nb_points;
      float*          abscisses;
      float*          surf_inf;
      float*          surf_sup;
      float*          surf_interp;
      GnuPlot*       gnuplot;
      Chaine         nom_plot;
      Crest*         wireframe;
      Chaine         nom_wireframe;
      LigneCrest     ligne;
      int         num_pt;
      int         num_surfinterp;
      CalculAireSection* calcul_aire_section;
      Duree          temps_calcul;

if (_image_un_contour==NULL)
  fprintf(stderr,"Cannot compute surface of section with _image_un_contour==NULL \n");

    // initialisation des quadrillages
    calcul_aire_section = new CalculAireSection( _image_un_contour, _resolution);
    coord_image  = new CoordImage( _image);

    // pas de l'abscisse curviligne
    abs_curv = 0.0;
    pas_abs  = _pas_abscisse;

    // Parcours des points de la ligne et creation de l'image binaire
    longueur  = (float) _lignes->LongueurLigne( _num_ligne);
    nb_points = (int) (longueur/pas_abs) + 1;

    InitImagesSurf( calcul_aire_section->TailleX(), 
		    calcul_aire_section->TailleY(),
		    nb_points);

    calcul_aire_section->InitImagesSurf(  _image_surfinf, 
					 _image_surfsup, 
					 _image_sections,
					 _input_image);

    abscisses   = new float[nb_points];
    surf_inf    = new float[nb_points];
    surf_sup    = new float[nb_points];
    surf_interp = new float[nb_points];

    wireframe = new Crest();

    Si _verbose AlorsFait temps_calcul.Debut();

    p = 0;
    TantQue p<=nb_points-1 Faire

      abscisses[p] = abs_curv;
      surf_inf[p]  = surf_sup[p] = surf_interp[p] = 0.0;

      // Calcul du repere t, v1, v2
      n = _lignes->Position( _num_ligne, abs_curv, point);
    
      num_pt = wireframe->AddPoint( point);
      ligne += num_pt;

      t = point.vecteur;
      Si Norme(t) < 0.5 Alors
        p1 = _lignes->Point(_num_ligne,n);
        Si n == _lignes->NbPoints(_num_ligne) - 1 Alors
          p2 = _lignes->Point(_num_ligne,n-1);
        Sinon
          p2 = _lignes->Point(_num_ligne,n+1);
        FinSi

	//        t = coord_image->CoordImage2Reelles( p2 - p1);
        t = p2 - p1; 
        t.Normalise();
      FinSi

      Si  p>0 Alors
        Si t_prec*t < 0 AlorsFait t = ((float)(-1.0))*t;
        coord_image->CalculVecteursOrthogonaux(v1_prec,t,v1,v2);
      Sinon
        coord_image->CalculVecteursOrthogonaux(t,v1,v2);
      FinSi

      v1_prec = v1;
      t_prec  = t;

      calcul_aire_section->Aire( p, point, v1, v2, 
				 surf_inf, surf_sup, surf_interp);

      p        += 1;
      abs_curv += pas_abs;

    FinTantQue // p

    Si _verbose Alors
      temps_calcul.Fin();
      temps_calcul.AddCumul();
      cout << "Calcul Section " << temps_calcul << endl;
    FinSi

    // Sauvegarde du wireframe
    wireframe->AjouteLigne( ligne);
    nom_wireframe = _nom_image_resultat;
    nom_wireframe += "-lignecentrale.crest";
    wireframe->Sauve( nom_wireframe);

    delete wireframe;

    // Plot des courbes
    gnuplot = new GnuPlot( );

    gnuplot->AddCourbe(nb_points, abscisses, surf_inf, 
		       _nom_image_resultat + "-surface_inf" );
 
    gnuplot->AddCourbe(nb_points, abscisses, surf_sup, 
		       _nom_image_resultat + "-surface_sup");

    num_surfinterp = gnuplot->AddCourbe(nb_points, abscisses, surf_interp, 
					 _nom_image_resultat + "-surface_interp");

    gnuplot->XPlot( _nom_image_resultat);

    gnuplot->SaveData( num_surfinterp, TYPE_SECTION);
    delete gnuplot;

    Si _sauve Alors
      _image_surfinf ->Sauve();
      _image_surfsup ->Sauve();
      _image_sections->Sauve();
    FinSi

    DeleteImagesSurf();

    delete [] abscisses;
    delete [] surf_inf;
    delete [] surf_sup;
    delete [] surf_interp;

    delete coord_image;
    delete calcul_aire_section;

} // CalculAire()


//----------------------------------------------------------------------
///
InrImage* IsoContour2::GetReorderImage()
{
  return _sort_image;
} // GetReorderImage()

//----------------------------------------------------------------------
///
InrImage* IsoContour2::GetInclusionImage()
{
  return _inclusion_image;
} // GetInclusionImage()


//----------------------------------------------------------------------
///
InrImage* IsoContour2::GetSignImage()
{
  return _sign_image;
} // GetSignImage()

//----------------------------------------------------------------------
///
InrImage* IsoContour2::GetSizeImage()
{
  return _size_image;
} // GetSizeImage()
