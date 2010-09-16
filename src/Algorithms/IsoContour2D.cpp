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
 * $Log: IsoContour2D.cpp,v $
 * Revision 1.3  2005/11/16 14:03:07  karl
 * added LGPL license
 *
 * Revision 1.2  2004/08/06 20:48:29  karl
 * removed warnings + fixed bugs in IsoLigne
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

#include "IsoContour2D.hpp"




//======================================================================
// class IsoContour2D
//======================================================================

//======================================================================
// Fonctions Membres Privees
//======================================================================

//-----------------------------------------------------------------------------------------
unsigned char IsoContour2D :: CoordOK( int x, int y, int z)
//
{

    Si x < 0 Ou x >= _image_initiale->_tx AlorsFait return false;
    Si y < 0 Ou y >= _image_initiale->_ty AlorsFait return false;

    return true;

} // CoordOK()


//--------------------------------------------------
///
int IsoContour2D :: contour( const PointContour& p1)
//
{

    return (int) ( (*_image_num_contour)( p1.x,p1.y,p1.z));

} // contour()



//--------------------------------------------------
///
void IsoContour2D :: InitImagesSurf( int tx, int ty, int tz,
					      float   resolution )
//
{


    Chaine nom;

  nom = _nom_image_resultat;
  nom += "-sections.inr.gz";
  _image_sections = new InrImage( tx, ty, tz, WT_FLOAT, nom);
  _image_sections->InitImage(0.0);
  _image_sections->SetVoxelSize( resolution, resolution, 1);

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
void IsoContour2D :: DeleteImagesSurf( )
//
{

  delete _image_surfinf;
  delete _image_surfsup;
  delete _image_sections;

} // DeleteImagesSurf()


//--------------------------------------------------
///
void IsoContour2D :: InitFiltre( )
//
{

  _filtre = new GeneralGaussianFilter(_image_initiale, MODE_2D);

  _filtre->FixeSilencieux( true);

  _filtre->UtiliseImage(    false);
  _filtre->UtiliseGradient( true);
  _filtre->UtiliseHessien(  true);

//  Si masque_compression == (InrImage*) NULL Alors
  _filtre->InitDerivees();
//  Sinon
//    filtre->InitDeriveesCompressees(masque_compression, nb_points_masque );
//  FinSi

  _filtre->GammaNormalise(true);
  _filtre->FixeGamma( 1.0);

} // InitFiltre()


//--------------------------------------------------
///
void IsoContour2D :: EffaceFiltre( )
//
{

  delete _filtre;

} // EffaceFiltre()


//======================================================================
// Fonctions Membres Publiques
//======================================================================


//----------------------------------------------------------------------
///
IsoContour2D ::  IsoContour2D( InrImage* image_initiale,
						     const     Chaine& nom_res,
						     unsigned char   sauve)
//
{

    _silencieux      = false;
    _precision_sigma = 0.02;

    _image_initiale     = image_initiale;
    _nom_image_resultat = nom_res;
    _sauve              = sauve;

    _image_num_contour = new InrImage( WT_FLOAT,
				       _nom_image_resultat + "-num_contour.inr.gz",
				       _image_initiale);
    _image_num_contour->InitImage(0.0);

    _image_contour = new InrImage( WT_FLOAT,
				   _nom_image_resultat + "-contour.inr.gz",
				   _image_initiale);
    _image_contour->InitImage(0.0);

    _image_contours = new InrImage( WT_FLOAT,
				    _nom_image_resultat + "-contours.inr.gz",
				    _image_initiale);
    _image_contours->InitImage(0.0);

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
    _tab_in               = (int*) NULL;
    _tab_out              = (int*) NULL;
    _tab_distance         = (int*) NULL;
    _tab_nbpts            = (int*) NULL;
    _tab_moygrad          = (float*  ) NULL;

    _calcul_aire = (CalculAireSection*) NULL;

    InitFiltre();

    _propage = (PropagePoints*) NULL;

} // Constructor

//----------------------------------------------------------------------
///
IsoContour2D :: ~IsoContour2D()
//
{

  EffaceImage( _image_num_contour);
  EffaceImage( _image_contour);
  EffaceImage( _image_contours);

  EffaceTabEntier( _tab_contenance);
  EffaceTabEntier( _tab_signe);
  EffaceTabEntier( _tab_in);
  EffaceTabEntier( _tab_out);
  EffaceTabEntier( _tab_distance);
  EffaceTabEntier( _tab_nbpts);

  EffaceTabReel(   _tab_moygrad);

  Si _calcul_aire != (CalculAireSection*) NULL AlorsFait
    delete _calcul_aire;

  EffaceFiltre();

} // Destructor


//----------------------------------------------------------------------
///
void IsoContour2D :: ChangeImage( InrImage* image)
//
{

// Il faudrait verifier que
// les dimensions de la nouvelle
// image sont les memes que celles
// de l'image precedente

  _image_initiale     = image;
  _image_num_contour -> InitImage(0.0);
  _image_contour     -> InitImage(0.0);
  _image_contours    -> InitImage(0.0);

} // ChangeImage()


//----------------------------------------------------------------------
///
void IsoContour2D :: RechercheContours( )
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


    _propage = new PropagePoints(500000);

    _image_num_contour->InitImage(0.0);

    z = 0;
    Pour(x,0,_image_contours->_tx-2)
    Pour(y,0,_image_contours->_ty-2)

      Si (*_image_num_contour)(x,y,z)==0 Alors
        num++;
        ParcoursContour(x,y,z,num,&taille);
      FinSi

    FinPour
    Si verbose Et Non(_silencieux) Alors
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

    delete _propage;
    _propage = (PropagePoints*) NULL;

} // RechercheContours()


//----------------------------------------------------------------------
void IsoContour2D :: ParcoursContour( int x, int y, int z,
//
						int num,  int* taille)
{


    int x1,y1,z1;
    int posx, posy, posz;
    int x2,y2,z2;
    int  signe;
    int  max_points;
    int  dist; // mesure de distance (au carre) du voisin
    Point_3D<int> pt[4];
    float             val[4],test;
    int           nx,ny,n;
    int           prop0,prop;
    unsigned char          propage_point;

  max_points = 0;

//  Si verbose AlorsFait
//   std::cout << "Parcours du contour numero " << num << std::endl;


  prop0 = 0;

  _propage->Init( x,y,z);
  *taille = 0;
  TantQue _propage->PointsATraiter() > 0 Faire

    Si _propage->PointsATraiter()>max_points
    AlorsFait
       max_points = _propage->PointsATraiter();

    Si Non(_propage->ProchainPoint( x1, y1, z1)) Alors
      break;
    FinSi

    pt[0].Init(x1,y1,z1);

    val[0]= (*_image_contours)(x1,y1,z1);
    signe = SIGNE( val[0]);

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

      posz = 0;
      n = ny;

      // 1. les voisins directs:
      dist = macro_abs(posx) +
             macro_abs(posy);

      x2 = x1+posx;
      y2 = y1+posy;
      z2 = z1;

      Si Non(CoordOK(x2, y2, z2)) AlorsFait continue;

      propage_point = false;

      Si dist == 1 Alors
        Si (SIGNE( (*_image_contours)(x2,y2,z2)) == signe) Et
           ((*_image_num_contour)( x2, y2, z2) == 0)
        AlorsFait
          propage_point = true;

      Autrement
      Si dist == 2 Alors

        // cas ambigu ??
        Si n!=3 AlorsFait
  	 std::cout << "IsoContour2D::ParcoursContour() \t"
       	       << "Probleme: points mal initialises ...\n";

        val[1] = (*_image_contours)(pt[1].x,pt[1].y,pt[1].z);
        Si (SIGNE( val[1]) == signe)
        AlorsFait continue;

        val[2] = (*_image_contours)(pt[2].x,pt[2].y,pt[2].z);
        Si (SIGNE( val[2]) == signe)
        AlorsFait continue;

        val[3] = (*_image_contours)(pt[3].x,pt[3].y,pt[3].z);
        Si (SIGNE( val[3]) != signe)
        AlorsFait continue;

        // Si on arrive ici, c'est qu'il y a une ambiguite sur la
        // face (pt[0],pt[1],pt[3],pt[2]):

        test = (val[0]*val[3]-val[1]*val[2])/
               (val[0]+val[3]-val[1]-val[2]);

        Si signe == SIGNE(test) Et
           ((*_image_num_contour)( x2, y2, z2) == 0)
        AlorsFait
          propage_point = true;

      FinSi

      Si propage_point Alors

          Si Non(_propage->AjoutePoint( x2, y2, z2)) AlorsFait
            return;

          prop = _propage->PointsATraiter();

          _image_num_contour->BufferPos( x2, y2, z2);
          _image_num_contour->FixeValeur( -1);

      FinSi

    FinPour
    FinPour

    _propage->EnlevePointCourant();

    _image_num_contour->BufferPos( x1, y1, z1);
    _image_num_contour->FixeValeur( num);

    (*taille)++;

  FinTantQue

  Si max_points > _max_points Alors
    _max_points = max_points;
    Si Non(_silencieux) AlorsFait
     std::cout << " max points " << max_points << std::endl;
  FinSi

} // ParcoursContour()


//----------------------------------------------------------------------
void IsoContour2D :: PropageContour( )
//
{


      int     x,y,z;
      int     x1,y1,z1;
      float       moy;        // moyenne sur les voisins non nuls
      int     nb_voisins; // nombre de voisins non nuls
      long pts_zero;
      long pts_zero_prec;
      float       val;
      int     n;


    z = 0;
    Pour(y,0,_image_num_contour->_ty-2)
    Pour(x,0,_image_num_contour->_tx-2)

      n = (int) (*_image_num_contour)(x,y,z);
      Si n == _contour_choisi
      Alors
        _image_contour->BufferPos( x, y, z);
        _image_contour->FixeValeur( (*_image_contours)(x,y,z));
      Autrement
      Si n == _tab_contenance[_contour_choisi]
      Alors
        _image_contour->BufferPos( x, y, z);
        _image_contour->FixeValeur( (*_image_contours)(x,y,z));
      FinSi

    FinPour
    FinPour

    Si _sauve AlorsFait
      _image_contour->Sauve();

    pts_zero = 0;

    Repeter

      pts_zero_prec = pts_zero;
      pts_zero = 0;

      z = 0;
      Pour(y,0,_image_contour->_ty-1)
      Pour(x,0,_image_contour->_tx-1)

        n = (int) (*_image_num_contour)(x,y,z);
        Si fabsf((*_image_contour)(x,y,z)) < 1E-5 Et
           n != _contour_choisi Et
           n != _tab_contenance[_contour_choisi]
        Alors
          pts_zero++;

          moy = 0;
          nb_voisins= 0;

          z1 = 0;
          Pour(y1, macro_max(0,y-1), macro_min(_image_num_contour->_ty-1, y+1))
          Pour(x1, macro_max(0,x-1), macro_min(_image_num_contour->_tx-1, x+1))

             val = (*_image_contour)(x1,y1,z1);

             Si fabsf(val) > 1E-5 Alors
               Si (nb_voisins > 0) Et (moy*val < 0) Et
	          ((*_image_num_contour)(x1,y1,z1) != _contour_choisi) Et
	          ((*_image_num_contour)(x1,y1,z1) !=
		   _tab_contenance[_contour_choisi])
               Alors
                 Si Non(_silencieux) AlorsFait
  	         std::cerr << "IsoContour2D::PropageContour() \t Probleme : point "
    	              << x << "," << y << "," << z << " \t "
                      << " voisins de signes differents " << std::endl;
               FinSi
               nb_voisins++;
               moy += val;
             FinSi

          FinPour
          FinPour

          Si nb_voisins > 0 Alors
            _image_contour->BufferPos(x,y,z);
            _image_contour->FixeValeur( moy/nb_voisins);
            pts_zero --;
           FinSi

        FinSi

      FinPour
      FinPour

      Si GB_debug AlorsFait
       std::cout << "Fin de parcours" << std::endl;

      Si Non(_silencieux) Ou GB_debug AlorsFait
       std::cout << "*** Nb points a zero = " <<  pts_zero <<"\n";

    JusquA (pts_zero == 0) Ou (pts_zero == pts_zero_prec) FinRepeter

  Si pts_zero != 0 Alors
    std::cerr << "IsoContour2D::PropageContour()\t il reste " << pts_zero
    << " points nuls \n";
  FinSi

  Si GB_debug AlorsFait
   std::cout << "Fin de PropageContour" << std::endl;

} // PropageContour()


//----------------------------------------------------------------------
void IsoContour2D :: DefinitInterieur( float max_fond)
//
{


      PointContour point_courant, point_suivant;
      int       contour_courant, nouv_contour;
      int       x0,y0,z0;
      int       x,y;
      int       i,n,j;
      int       c,dist_min;
      Vect3D<double> grad;


    EffaceTabEntier( _tab_contenance);
    EffaceTabEntier( _tab_signe);
    EffaceTabEntier( _tab_in);
    EffaceTabEntier( _tab_out);
    EffaceTabEntier( _tab_distance);
    EffaceTabEntier( _tab_nbpts);
    _tab_contenance       = new int[ _nb_contours+1];
    _tab_signe            = new int[ _nb_contours+1];
    _tab_out              = new int[ _nb_contours+1];
    _tab_in               = new int[ _nb_contours+1];
    _tab_distance         = new int[ _nb_contours+1];
    _tab_moygrad          = new float  [ _nb_contours+1];
    _tab_nbpts            = new int[ _nb_contours+1];
    Pour(i,1,_nb_contours)
      _tab_contenance[i]       = -1;
      _tab_signe[i]            =  0;
      _tab_in[i]               =  0;
      _tab_out[i]              =  0;
      _tab_distance[i]         =  0;
      _tab_moygrad[i]          =  0;
      _tab_nbpts[i]            =  0;
    FinSi

    // 1. choisir un point a l'exterieur dans la ligne y=0
    z0 = 0;
    y0 = 0;
    Pour(x0,0, _image_initiale->_tx-1)
       Si (*_image_initiale)(x0,y0,z0) < max_fond AlorsFait break;
    FinPour

    Si ( x0 >  _image_initiale->_tx-1) Ou
       ((*_image_initiale)(x0,y0,z0) >= max_fond ) Alors
       std::cerr << "IsoContour2D::DefinitInterieur() \t "
            << "point exterieur non trouve \n";
      x0 = y0 = 0;
    FinSi

    contour_courant = (int) (*_image_num_contour)( x0,y0,z0);

    point_courant.InitImage( _image_contours);
    point_courant.Init(x0,y0,z0, contour_courant);
    point_courant.InitVal( );

    _tab_contenance[contour_courant] = 0;

    // Propagation du point et definition des informations
    // relatives aux contours
    point_suivant = point_courant;

    TantQue (point_suivant++) Faire
      point_suivant.InitVal( );

      Si point_courant.Signe()*point_suivant.Signe() < 0 Alors
        // Changement de signe: changement de contour
        nouv_contour = contour( point_suivant);
        // Mise a jour du nombre de traversees du contour et
        // de la moyenne de la norme du gradient
        _tab_nbpts[nouv_contour]++;

        grad = _filtre->Gradient(point_courant.x,
				 point_courant.y,
				 point_courant.z);

        _tab_moygrad[nouv_contour] += Norme(grad);

        Si nouv_contour != _tab_contenance[contour_courant] Alors
          // on entre dans un nouveau contour

	  // Traitement du signe
          Si _tab_signe[nouv_contour] == 0 Alors
            _tab_signe[nouv_contour] = point_suivant.Signe();
          Sinon
            Si point_suivant.Signe() != _tab_signe[nouv_contour] AlorsFait
  	      std::cerr << "IsoContour2D::DefinitInterieur() \t "
	           << "probleme de signe du contour "
 	           << nouv_contour << std::endl;
          FinSi

          // Traitement de l'appartenance
          Si _tab_contenance[nouv_contour] == -1 Alors
            _tab_contenance[nouv_contour] = contour_courant;
          Sinon
            Si contour_courant != _tab_contenance[nouv_contour] AlorsFait
  	      std::cerr << "IsoContour2D::DefinitInterieur() \t "
                   << "probleme d'appartenance du contour "
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

    FinTantQue

    // Calcul des distances,
    // par rapport au contour de reference (_image_ref)
    // pour chaque contour.

    Pour(y,0,_image_ref->_ty-1)
    Pour(x,0,_image_ref->_tx-1)
      n = (int) (*_image_num_contour)(x,y,0);
      Si (*_image_ref)(x,y,0) < 127 Alors
        _tab_out[n]++;
      Sinon
        _tab_in[n]++;
      FinSi
    FinPour
    FinPour

    // Calcul de la distance au contour de reference
    // distance(c0) = Sum {c<=c0} out(c) + Sum(c>c0) in(c)
    Pour(i,1,_nb_contours)
      Pour(j,1,_nb_contours)

        c = j;
        TantQue (c!=0)&&(c!=i) Faire
           Si c>=0 Et c<=_nb_contours Alors
            c = _tab_contenance[c];
          Sinon
            // Probleme ...
            c = 0;
          FinSi
        FinTantQue

        Si c==0 Alors
          _tab_distance[i]+=_tab_in[j];
        Sinon
          _tab_distance[i]+=_tab_out[j];
        FinSi

     FinPour
    FinPour

    dist_min = -1;
    // Choix du contour le plus pres
    Pour(i,1,_nb_contours)

      Si (dist_min == -1) Alors
        Si (_tab_signe[i]==-1) Alors
          _contour_choisi = i;
          dist_min = _tab_distance[i];
        FinSi
      Sinon
        Si (_tab_distance[i] < dist_min) Et (_tab_signe[i]==-1) Alors
          _contour_choisi = i;
          dist_min = _tab_distance[i];
        FinSi
      FinSi

    FinPour  // i


    Si Non(_silencieux) AlorsFait
    Pour(i,1,_nb_contours)

      Si _tab_nbpts[i] == 0 Alors
        printf(" contour %3d aucun point ...", i);
      Sinon
        printf(" contour %3d %3d %3d %e %d",
	       i, _tab_signe[i],
	       _tab_contenance[i],
	       _tab_moygrad[i]/_tab_nbpts[i],
	       _tab_distance[i]);
      FinSi

      Si i%3 == 0 Alors
        printf("\n");
      Sinon
        printf("\t");
      FinSi

    FinPour

} // DefinitInterieur( )


//----------------------------------------------------------------------
///
float IsoContour2D :: CalculAire( float resolution )
//
{

    Si GB_debug AlorsFait
     std::cout << " IsoContour2D::CalculAire() \t variables locales\n";


      float           surf_inf[1];
      float           surf_sup[1];
      float           surf_interp[1];
      Chaine         nom_plot;
      Point3D        point,p1,p2;
      Vect3D<float>  v1_prec;
      // Pour assurer la continuite de la direction tangente
      Vect3D<float>  t_prec;

//      LigneCrest     ligne;


    Si GB_debug AlorsFait
     std::cout << " Debut CalculAire \n";

    surf_inf[0] = surf_sup[0] = surf_interp[0] = 0.0;
    // initialisation des quadrillages


    Si GB_debug AlorsFait
     std::cout << " initialisation de _calcul_aire \n";

    Si _calcul_aire != (CalculAireSection*) NULL Alors
      _calcul_aire->ChangeImage( _image_contour );
    Sinon
      _calcul_aire = new CalculAireSection( _image_contour,
    					    resolution);
    FinSi


    // pas de l'abscisse curviligne


//    InitImagesSurf( calcul_aire_section->TailleX(),
//		    calcul_aire_section->TailleY(),
//		    1, resolution);
//
//    calcul_aire_section->InitImagesSurf(  _image_surfinf,
//					  _image_surfsup,
//					  _image_sections,
//                                        _image_initiale);


   _calcul_aire->InitImagesSurf((InrImage*) NULL, (InrImage*) NULL,
				(InrImage*) NULL, (InrImage*) NULL);

   surf_inf[0]  = surf_sup[0] = surf_interp[0] = 0.0;
   v1.Init( 1.0, 0.0, 0.0);
   v2.Init( 0.0, 1.0, 0.0);
   point.Init( _image_contour->_tx/2,
	       _image_contour->_ty/2,
	       0);

    Si GB_debug AlorsFait
     std::cout << " _calcul_aire->Aire \n";

  _calcul_aire->Aire( 0, point, v1, v2,
		     surf_inf, surf_sup, surf_interp);



//  Si _sauve Alors
//    _image_surfinf ->Sauve();
//    _image_surfsup ->Sauve();
//    _image_sections->Sauve();
//  FinSi
//
//  DeleteImagesSurf();


    Si GB_debug AlorsFait
     std::cout << " Fin CalculAire() \n";

  return surf_interp[0];

} // CalculAire()


//----------------------------------------------------------------------
/*
  le resultat est dans _image_contours
*/
void IsoContour2D :: CalculImageContours( float sigma)
//
{


    int         x,y,z;
    Vect3D<double> grad;
    double         hessien[4];
    double     norme;
    double         px,py;
    float           res;

//  _filtre->InitFiltre( sigma, FILTRE_REC);
  _filtre->InitFiltre( sigma, MY_FILTRE_CONV);
  _filtre->CalculFiltres();

  Pour( z, 0, _image_contours->_tz - 1)
  Pour( y, 0, _image_contours->_ty - 1)
  Pour( x, 0, _image_contours->_tx - 1)

    _image_contours->BufferPos(x,y,z);

    grad = _filtre->Gradient(x,y,z);
    _filtre->Hessien2D( hessien, x,y);


    norme = Norme(grad);

    Si norme < 1E-2 Alors
      // le point en question ne peut pas etre un contour
      res = 0.0;
    Sinon

      px = (grad.x * hessien[0] + grad.y * hessien[1]) / norme;
      py = (grad.x * hessien[2] + grad.y * hessien[3]) / norme;

      res = ((px*grad.x+py*grad.y)/norme);
    FinSi

    _image_contours->FixeValeur( res);

  FinPour
  FinPour

   Si (verbose) Et Non(_silencieux) Alors
      Si z > 0 Alors
        printf("\b\b\b");
      Sinon
        printf("IsoContour2D:CalculImageContours() : ");
      FinSi
      printf("%3d",z);
      fflush(stdout);
    FinSi

  FinPour

} // CalculImageContours()


//----------------------------------------------------------------------
void IsoContour2D :: MAJContourRef()
//
{

  _image_ref->InitBuffer();
  _image_contour->InitBuffer();

  Repeter

    Si SIGNE(_image_contour->ValeurBuffer()) == -1
    Alors
      _image_ref->FixeValeur(255);
    Sinon
      _image_ref->FixeValeur(0);
    FinSi

    _image_contour->IncBuffer();

  JusquA Non(_image_ref->IncBuffer())
  FinRepeter

} // MAJContourRef()


//----------------------------------------------------------------------
/*
   Utilise l' image de reference
 */
float IsoContour2D :: EstimeRayon( float sigma,
					    InrImage* image_ref,
					    float resolution
					  )
//
{


    float aire,rayon;

  rayon = 0.0;

  // 1. Calcul des contours a l'echelle sigma
  //    calcul de _image_contours
  CalculImageContours( sigma);

  // 2. Regions connexes de signe constant,
  //    calcul de _image_num_contours
  RechercheContours( );

  // 3.  choix de la region a partir de l'image de reference
  ContourReference( image_ref);

  //   calcul de la variable _contour_choisi
  DefinitInterieur( _max_fond);

  //   mise a jour de l'image _image_ref,
  //   au nouveau contour
  MAJContourRef();

  Si GB_debug AlorsFait
   std::cout << " IsoContour2D::EstimeRayon() \t Etape 4: PropageContour()\n";
  // 4. Creation d'une image negative a l'interieur, positive a l'exterieur
  //    calcul de _image_contour
  PropageContour( );

  // 5. Calcul de l'aire
  //    Il faut changer image_ref

  Si GB_debug AlorsFait
   std::cout << " IsoContour2D::EstimeRayon() \t Etape 5: calcul de l'aire\n";

  aire = CalculAire( resolution );


  rayon = sqrt(aire/PI);

 std::cout << "\t Sigma = " << sigma << "\t Rayon = " << rayon << std::endl;

  return rayon;

} // EstimeRayon()


//----------------------------------------------------------------------
///
float IsoContour2D :: CorrigeEstimation(
						  InrImage* image2Dref,
						  float rayon_estime,
						  float precision,
						  float resolution
						  )
//
{


    float sigma, sigma_min, sigma_max, pas_sigma;
    float r0,r1,r2;
    float coeff_corr;

  coeff_corr = 0.9015625f;

  sigma_min = 0.8f;
  sigma_max = rayon_estime  / resolution;
  sigma     = sigma_min;
  pas_sigma = 1;

  r0 = EstimeRayon( sigma, image2Dref, resolution) / coeff_corr;
  sigma += pas_sigma;
  r1 = EstimeRayon( sigma, image2Dref, resolution) / coeff_corr;

  // Cas 1: r1 > r0
  TantQue (r1 > r0) Et (r1-r0)>precision Faire
    pas_sigma /= 2.0;
    sigma -= pas_sigma;
    r1 = EstimeRayon( sigma, image2Dref, resolution) / coeff_corr;
  FinTantQue

  Si (r1>r0) Alors
    std::cerr << "IsoContour2D::CorrigeEstimation() \t "
         << " Attention, rayon < " << r0 << std::endl;
    return r0;
  FinSi

  sigma += pas_sigma;
  r2 = EstimeRayon( sigma, image2Dref, resolution) / coeff_corr;

  // 2e partie
  Repeter

    TantQue (r2<r1) Et (sigma<sigma_max) Faire
      r0 = r1;
      r1 = r2;
      sigma += pas_sigma;
      r2 = EstimeRayon( sigma, image2Dref, resolution) / coeff_corr;
    FinTantQue

    Si sigma >= sigma_max Alors
      std::cerr << "IsoContour2D::CorrigeEstimation() \t "
           << " Attention, minimum non atteint, rayon > "
           << r2 << std::endl;
      return r2;
    Sinon
      Si (r0-r1)<precision Et (r2-r1)<precision Alors
        return r1;
      Sinon
        r2 = r1;
        sigma = sigma - pas_sigma;
        pas_sigma /= 2.0;
        r1 = EstimeRayon( sigma-pas_sigma,
			  image2Dref, resolution) / coeff_corr;
        Si r1 > r0 Alors
          std::cerr << "IsoContour2D::CorrigeEstimation() \t "
	       << " Probleme : r1 > r0 ... " << std::endl;
        FinSi
      FinSi
    FinSi

  JusquA (pas_sigma < 0.05) FinRepeter

  std::cerr << "IsoContour2D::CorrigeEstimation() \t "
       << " Pb ? pas_sigma < 0.05 ... ";

  return r1;


} // CorrigeEstimation()


//----------------------------------------------------------------------
///
float IsoContour2D :: CorrigeEstimation2(
						  InrImage* image2Dref,
						  float rayon_estime,
						  float precision,
						  float resolution,
						  float& sigma
						  )
//
{


    float sigma_min, sigma_max, pas_sigma;
    float r0,r1,r2, rmin, rmax, s0, s2;
    float coeff_corr;

  coeff_corr = 0.9015625f;

  sigma_min = 0.8 * resolution;
  sigma_max = rayon_estime ;
  pas_sigma = 0.06*rayon_estime;

  rmin = rmax = -1.0; // non initialises

  Si sigma - pas_sigma < sigma_min Alors
    sigma += sigma_min + pas_sigma;
  FinSi

  r0 = EstimeRayon( sigma - pas_sigma, image2Dref, resolution) / coeff_corr;
  r1 = EstimeRayon( sigma,             image2Dref, resolution) / coeff_corr;
  r2 = EstimeRayon( sigma + pas_sigma, image2Dref, resolution) / coeff_corr;

  TantQue (sigma>sigma_min) Et (sigma<sigma_max) Faire

  // std::cout << "sigma " << sigma << " pas_sigma " << pas_sigma << std::endl;
  // std::cout << "sigma min " << sigma_min << " rmin " << rmin << std::endl;

    /* cas 1 : probleme */
    Si r1>r0 Et r1>r2 Alors
      std::cerr << "IsoContour2D::CorrigeEstimation2() "
           << "\t Probleme maximum local \n";
      sigma += pas_sigma;
      r0 = r1;
      r1 = r2;
      r2 = EstimeRayon( sigma + pas_sigma, image2Dref, resolution)
	   / coeff_corr;
    Autrement
    /* Cas 2 : decroissance */
    Si r0>r1 Et r1>r2 Alors
      r0 = r1;
      r1 = r2;
      sigma += pas_sigma;
      Si sigma+pas_sigma > sigma_max Alors
        Si rmax < 0.0 Alors
          rmax = EstimeRayon( sigma_max, image2Dref, resolution)
                 / coeff_corr;
        FinSi
        Si fabsf(rmax - r1) < precision Alors
  	  std::cerr << "IsoContour2D::CorrigeEstimation2() "
               << "\t sigma max atteint \n";
          return rmax;
        Sinon
          pas_sigma = (sigma_max - sigma)/2.0;
          r0 =  EstimeRayon( sigma - pas_sigma, image2Dref, resolution)
                / coeff_corr;
        FinSi
      FinSi
      r2 = EstimeRayon( sigma + pas_sigma, image2Dref, resolution)
	   / coeff_corr;
    Autrement
    /* Cas 3 : croissance */
    Si r0<r1 Et r1<r2 Alors
      r2 = r1;
      r1 = r0;
      sigma -= pas_sigma;
      Si sigma-pas_sigma < sigma_min Alors
        Si rmin < 0.0 Alors
          rmin = EstimeRayon( sigma_min, image2Dref, resolution)
                 / coeff_corr;
        FinSi
        Si fabsf(rmin - r1) < precision Alors
  	  std::cerr << "IsoContour2D::CorrigeEstimation2() "
               << "\t sigma min atteint \n";
          return rmin;
        Sinon
          pas_sigma = (sigma - sigma_min)/2.0;
          r2 =  EstimeRayon( sigma + pas_sigma, image2Dref, resolution)
                / coeff_corr;
        FinSi
      FinSi
      r0 = EstimeRayon( sigma - pas_sigma, image2Dref, resolution)
	   / coeff_corr;
    Autrement
    /* Cas 4 : Minimum */
    Si r0 > r1 Et r1 < r2 Alors
      // La precision est-elle atteinte ?
      Si (r0-r1) < precision Et (r2-r1) < precision Et
         pas_sigma < _precision_sigma
      Alors
    //   std::cout << "pas sigma = " << pas_sigma << std::endl;
        return r0;
      Sinon
        pas_sigma /= 2.0;
        s0 = EstimeRayon( sigma - pas_sigma, image2Dref, resolution)
	     / coeff_corr;
        Si s0 < r1 Alors
          sigma -= pas_sigma;
          r2 = r1;
          r1 = s0;
        Sinon
          s2 =  EstimeRayon( sigma + pas_sigma, image2Dref, resolution)
                / coeff_corr;
          Si s2 < r1 Alors
            sigma += pas_sigma;
            r0 = r1;
            r1 = s2;
          Sinon
            r0 = s0;
            s2 = s2;
          FinSi
        FinSi
      FinSi
      // Cas non traite: s0 < r1 > s2
      Si s0 < r1 Et r1 > s2 Alors
        std::cerr << "IsoContour2D::CorrigeEstimation2()";
        std::cerr << "\t maximum local s0 < r1 > s2 \n";
        return r1;
      FinSi
    FinSi

    Si fabsf(r1-r0) < 1E-3 AlorsRetourne r1;
    Si fabsf(r2-r1) < 1E-3 AlorsRetourne r1;
    Si pas_sigma < 1E-3    AlorsRetourne r1;

  FinTantQue

  return r1;

} // CorrigeEstimation2()
