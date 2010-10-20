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
 * $Log: IsoContour.cpp,v $
 * Revision 1.3  2005/11/16 14:03:07  karl
 * added LGPL license
 *
 * Revision 1.2  2005/08/08 21:52:11  karl
 * local statistics for noise
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

#if defined(_MSC_VER)
  #include <windows.h>
#endif

#include "IsoContour.hpp"


extern InrImage* image_contours;

//======================================================================
// class IsoContour
//======================================================================

//======================================================================
// Fonctions Membres Privees
//======================================================================

//-----------------------------------------------------------------------------------------
unsigned char IsoContour :: CoordOK( int x, int y, int z)
//
{

    Si x < 0 Ou x >= _image->_tx AlorsFait return false;
    Si y < 0 Ou y >= _image->_ty AlorsFait return false;
    Si z < 0 Ou z >= _image->_tz AlorsFait return false;

    return true;

} // CoordOK()


//-----------------------------------------------------------------------------------------
// Initialisation des 4 positions des sommets de la face
void IsoContour :: InitFace( int num, int s1, int s2, int s3, int s4)
//
{

    _face[num][0] = s1;
    _face[num][1] = s2;
    _face[num][2] = s3;
    _face[num][3] = s4;

} // InitFace()


//--------------------------------------------------
///
unsigned char   IsoContour :: PassageParZero( int& signe,   double valeur)
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
unsigned char IsoContour :: ExisteContour( int x, int y, int z) throw ( OutOfRange)
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
int IsoContour :: contour( const PointContour& p1, const PointContour& p2 )
//
{

    return (int) ( (*image_num_contour)( macro_min(p1.x,p2.x),
					      macro_min(p1.y,p2.y),
					      macro_min(p1.z,p2.z)) );

} // contour()



//--------------------------------------------------
///
void IsoContour :: InitImagesSurf( int tx, int ty, int tz)
//
{


    Chaine nom;

  nom = nom_image_resultat;
  nom += "-sections.inr.gz";
  _image_sections = new InrImage( tx, ty, tz, WT_FLOAT, nom);
  _image_sections->InitImage(0.0);
  _image_sections->SetVoxelSize( resolution, resolution, pas_abscisse);


  nom = nom_image_resultat;
  nom += "-surfinf.inr.gz";
  _image_surfinf = new InrImage( WT_UNSIGNED_CHAR, nom, _image_sections);
  _image_surfinf->InitImage(0);


  nom = nom_image_resultat;
  nom += "-surfsup.inr.gz";
  _image_surfsup = new InrImage( WT_UNSIGNED_CHAR, nom, _image_sections);
  _image_surfsup->InitImage(0);

} // InitImagesSurf()


//--------------------------------------------------
///
void IsoContour :: DeleteImagesSurf( )
//
{

  delete _image_surfinf;
  delete _image_surfsup;
  delete _image_sections;

} // DeleteImagesSurf()

//-------------------------------------------------
/// Calcule le nombre total de points de la ligne inclus dans le contour
void IsoContour :: CalculTotalPointsLigne()
//
{


    int i,c,nbpts;

  Pour(i,1,_nb_contours)

    c = i;
    nbpts = _tab_ptsligne[i];

    TantQue (c!=0) Faire
      _tab_ptsligne_total[c] += nbpts;

      Si c>=0 Et c<=_nb_contours Alors
        c = _tab_contenance[c];
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
IsoContour ::  IsoContour( InrImage* image0)
//
{

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

    _tab_contenance       = (int*) NULL;
    _tab_signe            = (int*) NULL;
    _tab_ptsligne         = (int*) NULL;
    _tab_ptsligne_total   = (int*) NULL;
    _tab_nbpts            = (int*) NULL;
    _tab_moygrad          = (float*  ) NULL;

    _centre_sphere = (int*) NULL;
    _rayon_sphere  = 0.0;

} // Constructor

//----------------------------------------------------------------------
///
IsoContour :: ~IsoContour()
//
{



  EffaceImage( _image_contour);

  EffaceTabEntier( _tab_contenance);
  EffaceTabEntier( _tab_signe);
  EffaceTabEntier( _tab_ptsligne);
  EffaceTabEntier( _tab_ptsligne_total);
  EffaceTabEntier( _tab_nbpts);

  EffaceTabReel(   _tab_moygrad);

} // Destructor


//----------------------------------------------------------------------
///
void IsoContour :: RechercheContours( InrImage* image)
//
{


      int x,y,z;
      int num;
      int taille;

   _max_points = 0;

    Si GB_debug AlorsFait
     std::cout << " RechercheContours \n";

    num = 0;

    Si GB_debug AlorsFait
     std::cout << " InitImage \n";

    image->InitImage(0.0);

    Pour(x,0,image->_tx-2)
    Pour(y,0,image->_ty-2)
    Pour(z,0,image->_tz-2)



      Si (*image_num_contour)(x,y,z)==0 Alors

        Si ExisteContour(x,y,z) Alors
          Si GB_debug AlorsFait
	   std::cout << "existe contour"  << std::endl;
          num++;
          Si GB_debug AlorsFait
  	   std::cout << "ParcoursContour"
	         << x << "," << y <<"," << z <<","
	         << num  << std::endl;
          ParcoursContour(x,y,z,num,&taille);
          Si GB_debug AlorsFait
	   std::cout << "Fin ParcoursContour"  << std::endl;
        FinSi
      Sinon
	/*
        Si GB_debug AlorsFait
  	 std::cout << "image_num_contour"
               << (*image_num_contour)(x,y,z)
               << std::endl;
	*/
      FinSi

    FinPour
    FinPour
    Si verbose Alors
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
void IsoContour :: ParcoursContour( int x, int y, int z,  int num,  int* taille)
//
{


    int x1,y1,z1;
    int posx, posy, posz;
    int x2,y2,z2;
    int  signe, sommet, som, face;
    PropagePoints propage(500000);
    int  max_points;

  max_points = 0;

//  Si verbose AlorsFait
//   std::cout << "Parcours du contour numero " << num << std::endl;

  propage.Init( x,y,z);
  *taille = 0;
  TantQue propage.PointsATraiter() > 0 Faire

    Si propage.PointsATraiter()>max_points AlorsFait max_points = propage.PointsATraiter();

    Si Non(propage.ProchainPoint( x1, y1, z1)) Alors
      break;
    FinSi

    Pour( face, 0, 5)
     signe = 0;
     Pour( sommet, 0, 3)
        // numero du sommet dans le voxel
        som = _voxel.NumSommet( face,sommet);
        x2 = x1 + _voxel.PosX(som);
        y2 = y1 + _voxel.PosY(som);
        z2 = z1 + _voxel.PosZ(som);

        Si Non(CoordOK(x2,y2,z2)) AlorsFait continue;

        Si PassageParZero( signe, (*_image)(x2,y2,z2)) Alors

          posx = x1;
          posy = y1;
          posz = z1;
          switch ( face ){
  	    case 0: posz -= 1; break;
  	    case 1: posy -= 1; break;
  	    case 2: posx -= 1; break;
  	    case 3: posz += 1; break;
  	    case 4: posy += 1; break;
  	    case 5: posx += 1; break;
          } // end switch

          Si (CoordOK(posx, posy, posz))
	     Et
            ( (*image_num_contour)( posx, posy, posz) == 0)
	  Alors
            Si Non(propage.AjoutePoint( posx, posy, posz)) AlorsFait
              return;

            image_num_contour->BufferPos( posx, posy, posz);
            image_num_contour->FixeValeur( -1);

          FinSi
          break;
        FinSi

     FinPour

    FinPour // _face

    propage.EnlevePointCourant();

    image_num_contour->BufferPos( x1, y1, z1);
    image_num_contour->FixeValeur( num);

//    nbpoints++;

//    nb_points--;

    (*taille)++;

  FinTantQue

  Si max_points > _max_points Alors
    _max_points = max_points;
   std::cout << " max points " << max_points << std::endl;
  FinSi

} // ParcoursContour()


//----------------------------------------------------------------------
void IsoContour :: PropageContour( InrImage* image_contour, int num_contour)
//
{


      int     x,y,z,sommet;
      int     x1,y1,z1;
      float       moy;        // moyenne sur les voisins non nuls
      int     nb_voisins; // nombre de voisins non nuls
      long pts_zero;
      float       val;


    Pour(z,0,image_num_contour->_tz-2)
    Pour(y,0,image_num_contour->_ty-2)
    Pour(x,0,image_num_contour->_tx-2)

      Si (*image_num_contour)(x,y,z) == num_contour Alors
        Pour( sommet, 0, 7)
          x1 = x + _voxel.PosX(sommet);
          y1 = y + _voxel.PosY(sommet);
          z1 = z + _voxel.PosZ(sommet);
          image_un_contour->BufferPos( x1, y1, z1);
          image_un_contour->FixeValeur( (*_image)(x1,y1,z1));
        FinPour
      FinSi

    FinPour
    FinPour
    FinPour


    Repeter

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
	          ((*image_num_contour)(x1,y1,z1) != num_contour)
               Alors
  	         std::cerr << "IsoContour::PropageContour() \t Probleme : point "
                      << x << "," << y << "," << z
                      << " voisins de signes differents " << std::endl;
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

     std::cout << "*** il reste " << pts_zero << " points nuls \n";

    JusquA pts_zero == 0 FinRepeter

} // PropageContour()


//----------------------------------------------------------------------
void IsoContour :: DefinitInterieur( )
//
{


      PointContour point_courant, point_suivant;
      int contour_courant, nouv_contour;
      int x0,y0,z0;
      int i,n,c;
      float   pourcent,pourcent_total;
      float dx,dy,dz;


    _tab_contenance       = new int[ _nb_contours+1];
    _tab_signe            = new int[ _nb_contours+1];
    _tab_ptsligne         = new int[ _nb_contours+1];
    _tab_ptsligne_total   = new int[ _nb_contours+1];
    _tab_moygrad          = new float  [ _nb_contours+1];
    _tab_nbpts            = new int[ _nb_contours+1];
    Pour(i,1,_nb_contours)
      _tab_contenance[i]       = -1;
      _tab_signe[i]            =  0;
      _tab_ptsligne[i]         =  0;
      _tab_ptsligne_total[i]   =  0;
      _tab_moygrad[i]          =  0;
      _tab_nbpts[i]            =  0;
    FinSi

    // 1. choisir un point a l'exterieur dans le plan z=0
    x0=y0=z0 = 0;
    Pour(y0,0, image_contours->_ty-1)
      Pour(x0,0, image_contours->_tx-1)
         Si (*image)(x0,y0,z0) < max_fond AlorsFait break;
      FinPour
      Si (*image)(x0,y0,z0) < max_fond AlorsFait break;
    FinPour

    Si ( x0 >  image_contours->_tx-1) Ou ( y0> image_contours->_ty-1) Ou
       ((*image)(x0,y0,z0) >= max_fond ) Alors
      std::cerr<< "IsoContour::DefinitInterieur() \t point a zero non trouve \n";
      return;
    FinSi

    point_courant.InitImage( image_contours );
    point_courant.Init(x0,y0,z0,-1);
    point_courant.InitVal( );

    contour_courant = 0; // contour exterieur

    // Propagation du point et definition des informations relatives aux contours
    point_suivant = point_courant;

    TantQue (point_suivant++) Faire
      point_suivant.InitVal( );

      Si point_courant.Signe()*point_suivant.Signe() < 0 Alors
        // Changement de signe: changement de contour
        nouv_contour = contour(point_courant, point_suivant);
        // Mise a jour du nombre de traversees du contour et de la moyenne de la norme du gradient
        _tab_nbpts[nouv_contour]++;
        _tab_moygrad[nouv_contour] += (*image_gradient)( point_courant.x,
							 point_courant.y,
							 point_courant.z);

        Si nouv_contour != contour_courant Alors
          // on entre dans un nouveau contour

	  // Traitement du signe
          Si _tab_signe[nouv_contour] == 0 Alors
            _tab_signe[nouv_contour] = point_suivant.Signe();
          Sinon
            Si point_suivant.Signe() != _tab_signe[nouv_contour] AlorsFait
  	      std::cerr << "IsoContour::DefinitInterieur() \t probleme de signe du contour "
 	           << nouv_contour << std::endl;
          FinSi

          // Traitement de l'appartenance
          Si _tab_contenance[nouv_contour] == -1 Alors
            _tab_contenance[nouv_contour] = contour_courant;
          Sinon
            Si contour_courant != _tab_contenance[nouv_contour] AlorsFait
  	      std::cerr << "IsoContour::DefinitInterieur() \t probleme d'appartenance du contour "
 	           << nouv_contour << std::endl;
          FinSi

          point_courant   = point_suivant;
          contour_courant = nouv_contour;

        Sinon
          // on sort du contour courant

          point_courant   = point_suivant;
          contour_courant = _tab_contenance[contour_courant];

        FinSi
      Sinon
        // Pas de changement de contour
        point_courant   = point_suivant;

      FinSi

      Si image_ligne != (InrImage*) NULL Alors
        Si (*image_ligne)(point_courant.x,
			  point_courant.y,
			  point_courant.z) > 127 AlorsFait
          _tab_ptsligne[contour_courant]++;
      Autrement
      Si _centre_sphere != (int*) NULL Alors
        dx = point_courant.x - _centre_sphere[0];
        dy = point_courant.y - _centre_sphere[1];
        dz = point_courant.z - _centre_sphere[2];
        Si sqrt(dx*dx+dy*dy+dz*dz) < _rayon_sphere AlorsFait
          _tab_ptsligne[contour_courant]++;
      FinSi

    FinTantQue

    Si _centre_sphere != (int*) NULL Alors
      nbpts_ligne = (int) (4.0/3.0*PI*_rayon_sphere*
			   _rayon_sphere*_rayon_sphere);
    FinSi

    Si nbpts_ligne != 0 AlorsFait
   std::cout << " contour 0 : " << (100.0*_tab_ptsligne      [0])/(nbpts_ligne) << std::endl;

    CalculTotalPointsLigne();

    Si nbpts_ligne != 0 AlorsFait
   std::cout << " contour 0 : " << (100.0*_tab_ptsligne      [0])/(nbpts_ligne) << std::endl;

    n = 0;

    Si nbpts_ligne != 0 AlorsFait
    Pour(i,1,_nb_contours)
      pourcent       = (100.0*_tab_ptsligne      [i])/(nbpts_ligne);
      pourcent_total = (100.0*_tab_ptsligne_total[i])/(nbpts_ligne);

      printf(" contour %3d %3d %3d %e %2.2f ",
	     i, _tab_signe[i],
	     _tab_contenance[i],
	     _tab_moygrad[i]/_tab_nbpts[i],
	     pourcent);

      printf("  %2.1f ",
	     pourcent_total);

      Si i%3 == 0 Alors
        printf("\n");
      Sinon
        printf("\t");
      FinSi

      Si (_tab_ptsligne_total[i]> 0.6*nbpts_ligne) Et
         (_tab_signe[i]==-1)
      Alors
       std::cout << n << " " << i << std::endl;
        Si n>0 Alors

          // Si plusieurs contours negatifs contiennent toute la ligne
          // on prend le plus petit:
          // On garde le contour s'il est inclus dans le pr�c�dent.

          c = i;
          TantQue (c!=0) Et (c!=contour_choisi) Faire
            Si c>=0 Et c<=_nb_contours Alors
              c = _tab_contenance[c];
            Sinon
              // Probleme ...
              c = 0;
            FinSi
          FinTantQue

          Si c==contour_choisi Alors
            contour_choisi = i;
          FinSi

        Sinon
          contour_choisi = i;
        FinSi
        n++;
      FinSi

    FinPour

} // DefinitInterieur( )


//----------------------------------------------------------------------
///
void IsoContour :: CalculAire( float taille_voxels )
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
      float*          diam_3D;
      float*          diam_2D;
      float*          sigma0;
      float           rayon;
      float           rayon2D;
      GnuPlot*       gnuplot;
      Chaine         nom_plot;
      Crest*         wireframe;
      Chaine         nom_wireframe;
      LigneCrest     ligne;
      int         num_pt;
      int         num_surfinterp;
      CalculAireSection* calcul_aire_section;

    // initialisation des quadrillages
    calcul_aire_section = new CalculAireSection( image_un_contour, resolution);
    coord_image  = new CoordImage( _image);

    // pas de l'abscisse curviligne
    abs_curv = 0.0;
    pas_abs  = pas_abscisse;

    // Parcours des points de la ligne et creation de l'image binaire
    longueur  = lignes->LongueurLigne( num_ligne);
    nb_points = (int) (longueur/pas_abs) + 1;

    InitImagesSurf( calcul_aire_section->TailleX(),
		    calcul_aire_section->TailleY(),
		    nb_points);

    calcul_aire_section->InitImagesSurf(  _image_surfinf,
					  _image_surfsup,
					  _image_sections,
					  image);

    abscisses   = new float[nb_points];
    surf_inf    = new float[nb_points];
    surf_sup    = new float[nb_points];
    surf_interp = new float[nb_points];
    diam_2D     = new float[nb_points];
    diam_3D     = new float[nb_points];
    sigma0      = new float[nb_points];

    wireframe = new Crest();

    Si corrige AlorsFait CreeImagesCorrection();

    p = 0;
    TantQue p<=nb_points-1 Faire

      abscisses[p] = abs_curv;
      surf_inf[p]  = surf_sup[p] = surf_interp[p] = 0.0;

      // Calcul du repere t, v1, v2
      n = lignes->Position( num_ligne, abs_curv, point);

      num_pt = wireframe->AddPoint( point);
      ligne += num_pt;

      t = point.vecteur;
      Si Norme(t) < 0.5 Alors
        p1 = lignes->Point(num_ligne,n);
        Si n == lignes->NbPoints(num_ligne) - 1 Alors
          p2 = lignes->Point(num_ligne,n-1);
        Sinon
          p2 = lignes->Point(num_ligne,n+1);
        FinSi

        t = coord_image->CoordImage2Reelles( p2 - p1);
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

try{
      calcul_aire_section->Aire( p, point, v1, v2,
				 surf_inf, surf_sup, surf_interp);
}
catch (CalculAireSection::LimitesAtteintes)
{
  surf_inf[p] = surf_sup[p] = surf_interp[p] = 0;
}

      rayon      = sqrt(surf_interp[p]/PI);

      Si verbose Alors
       std::cout << "=============================" << std::endl;
       std::cout << " z = " << p << "\t";
       std::cout << " rayon 3D = " << rayon << std::endl;
       std::cout << std::endl;
      FinSi

      Si corrige Alors
        diam_3D[p] = rayon*2*taille_voxels;
        Si rayon != 0 Alors
          rayon2D    = AppliqueCorrection( p, rayon, sigma0[p]);
          diam_2D[p] = rayon2D*2*taille_voxels;
        Sinon
          diam_2D[p] = 0;
        FinSi

        Si verbose Alors
         std::cout << std::endl;
         std::cout << " diam initial = " << diam_3D[p]
    	       << " diam corrige = " << diam_2D[p]
    	       << " sigma0 = " << sigma0[p]
	       << std::endl;
        FinSi
      FinSi

      p        += 1;
      abs_curv += pas_abs;

    FinTantQue // p

    Si corrige AlorsFait EffaceImagesCorrection();

    // Sauvegarde du wireframe
    wireframe->AjouteLigne( ligne);
    nom_wireframe = nom_image_resultat;
    nom_wireframe += "-lignecentrale.crest";
    wireframe->Sauve( nom_wireframe);

    delete wireframe;

    // Plot des courbes
    gnuplot = new GnuPlot( );

    gnuplot->AddCourbe(nb_points, abscisses, surf_inf,
		       nom_image_resultat + "-surface_inf" );

    gnuplot->AddCourbe(nb_points, abscisses, surf_sup,
		       nom_image_resultat + "-surface_sup");

    Si corrige Alors
      gnuplot->AddCourbe(nb_points, abscisses, diam_3D,
	  	       nom_image_resultat + "-diam_3D");

      gnuplot->AddCourbe(nb_points, abscisses, diam_2D,
		       nom_image_resultat + "-diam_2D");

      gnuplot->AddCourbe(nb_points, abscisses, sigma0,
		       nom_image_resultat + "-sigma0");
    FinSi

    num_surfinterp = gnuplot->AddCourbe(nb_points, abscisses, surf_interp,
					 nom_image_resultat + "-surface_interp");

    gnuplot->XPlot( nom_image_resultat);

    gnuplot->SaveData( num_surfinterp, TYPE_SECTION);
    delete gnuplot;

    Si Sauve Alors
      _image_surfinf ->Sauve();
      _image_surfsup ->Sauve();
      _image_sections->Sauve();
    FinSi

    DeleteImagesSurf();

    delete [] abscisses;
    delete [] surf_inf;
    delete [] surf_sup;
    delete [] surf_interp;
    delete [] diam_3D;
    delete [] diam_2D;
    delete [] sigma0;

    delete coord_image;
    delete calcul_aire_section;

} // CalculAire()


//----------------------------------------------------------------------
///
void IsoContour :: CreeImagesCorrection()
//
{

// Creation des images
  _section = new InrImage( _image_sections->_tx,
			  _image_sections->_ty,
			  1,
			  WT_FLOAT,
			  nom_image_resultat + "2D-sec.inr.gz");
  _section->SetVoxelSize( resolution, resolution, 1);

  _contour_ref = new InrImage( WT_UNSIGNED_CHAR,
			      nom_image_resultat + "2D-ref.inr.gz",
			      _section);

//
  _isocontour2D = (IsoContour2D*) NULL;


} // CreeImagesCorrection()


//----------------------------------------------------------------------
///
void IsoContour :: EffaceImagesCorrection()
//
{

// Liberation des images
  delete _section;
  delete _contour_ref;

//
  Si _isocontour2D != (IsoContour2D*) NULL AlorsFait
    delete _isocontour2D;

} // EffaceImagesCorrection()


//----------------------------------------------------------------------
///
float IsoContour :: AppliqueCorrection( int z, float rayon_3D, float& sigma0)
//
{


    int        x,y;
    float          rayon;
    float          val_min,val_sec;


// Copie depuis _image_sections et _image_surfinf
  val_min = 0.0;

  _section    ->InitBuffer();
  _contour_ref->InitBuffer();

  Pour(x,0,_section->_tx-1)
  Pour(y,0,_section->_ty-1)

    val_sec = (*_image_sections)(x,y,z);
    val_min = macro_min( val_min, val_sec);

    _section    ->FixeValeur( val_sec);

    _contour_ref->FixeValeur( (*_image_surfinf) (x,y,z));

    _section    ->IncBuffer();
    _contour_ref->IncBuffer();

  FinPour
  FinPour

// Calcul du rayon corrige:

  Si _isocontour2D == (IsoContour2D*) NULL Alors
    _isocontour2D = new IsoContour2D( _section,
				      nom_image_resultat + "2D",
				      false);
    _isocontour2D->FixeSilencieux(     true);
    _isocontour2D->FixePrecisionSigma( precision_sigma);
  Sinon
    _isocontour2D->ChangeImage( _section);
  FinSi

  _isocontour2D->FixeMaxFond( val_min+1.0 );

/*
  rayon = _isocontour2D->CorrigeEstimation( _contour_ref,
					   // contour de reference a suivre
					   rayon_3D,
					   // rayon estime en 3D
					   0.1,
					   // precision en voxel
					   1
					   // resolution 1
					   );
*/

  Si (z== 0) Ou (rayon_3D == 0) AlorsFait
    _sigma_correction = rayon_3D * 0.55;

try{
  rayon = _isocontour2D->CorrigeEstimation2(
					    // contour de reference a suivre
					    _contour_ref,
					    // rayon estime en 3D
					    rayon_3D,
					    // precision en voxel
					    0.05,
					    // resolution 1
					    macro_min(1.0,0.2/resolution),
					    // sigma de depart
					    _sigma_correction
					    );
}
catch (CalculAireSection::LimitesAtteintes)
{
  rayon = sigma0 = 0;
}
  Si verbose Alors

    Si ( (0.55*rayon)*(0.55*rayon) -
         _sigma_correction*_sigma_correction) > 0
    Alors
      sigma0 = sqrt((0.55*rayon)*(0.55*rayon) -
		   _sigma_correction*_sigma_correction);
    Sinon
      sigma0 = 0;
    FinSi
   std::cout << std::endl;
  FinSi


  return rayon;

} // AppliqueCorrection()
