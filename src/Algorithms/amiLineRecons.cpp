//
// C++ Implementation: LineRecons
//
// Description: 
//
//
// Author: Karl Krissian,,, <karl@UBUNTU-KARL>, (C) 2008
//
// Copyright: See COPYING file that comes with this distribution
//
//

#include "amiLineRecons.h"
#include "inrimage.hpp"
#include "surface.hpp"
using namespace amilab;

#include "Coordonnees.hpp"
#include <stdio.h>

#define inf(x,y) ((x)<=(y))?(x):(y)
#define sup(x,y) ((x)>=(y))?(x):(y)


using namespace ami;

//-------------------------------------------------------------------------
/**
  Modele de Reconstruction:
  i.e. intensite en fonction de la distance au centre
 */
double LineRecons::ModeleReconstruction(  const double& distance, 
                                          const double& rayon,
                                          const double& intensity )
{

  double res = 0;

  if (_profile == EUCLIDEAN_DISTANCE)
  {
    res = distance - rayon;
    // keep minimal in absolute value
    if (fabs(res)>fabs(intensity))
      res = intensity;
//     Si res*intensite < 0 Alors
//       Si res > 0 AlorsFait res = intensite;
//     Sinon
//       Si fabs(res) > fabs(intensite) AlorsFait res = intensite;
//     FinSi
  } else
    if (_profile == GAUSSIAN)
    {
      res =  distance / rayon;
      res = 255 * exp( - res*res/2);
      // keep maximal value
      res = sup(res,intensity);
    }

  return res;

} // ModeleReconstruction()


//------------------------------------------------------------------------------
void LineRecons::DessineCylindre( 
//   ---------------
                      const Point_3D<float>& point0,
                      const Point_3D<float>& point1,
                      const Point_3D<float>& point2,
                      const Point_3D<float>& point3,
                      float rayon1,
                      float rayon2,
                      InrImage::ptr ref,
                      InrImage::ptr recons
                    )  throw (Excep_points_proches)

//  point1 sera nomme M1, point2 sera nomme M2, point0->M0, point3->M3
//  dessin d'un cylindre a base d'une gaussienne circulaire dont
//  le rayon varie linerairement de rayon1 au point M1 a rayon2 au point M2,
//  Si un point M ne se projette sur aucun des 3 segments [M0,M1], [M1,M2] ou [M2,M3]
//  alors on prend une sphere de centre l'extremite de [M1,M2] la plus proche
//
{
  int             x,y,z;
  Point_3D<float> pt;
  int             inf_x, inf_y, inf_z;
  int             sup_x, sup_y, sup_z;
  float           distance;
  float           valeur,rayon;
  int             facteur_cube;
  float           d2; // distance M1,M2 au carre
  float           ps; // produit scalaire  M1,M2 
                     // avec M1,P ou P(x,y,z)
  float           pv2; // norme au carre du produit 
                          // vectoriel de M1,M2 
                          // avec M1,P ou P(x,y,z)


  Si rayon1 < 0.01 Alors
    printf("Erreur,\tDessineCylindre() rayon1 = %f <0.01\n",rayon1);
    return;
  FinSi

  Si rayon2 < 0.01 Alors
    printf("Erreur,\tDessineCylindre() rayon2 = %f < 0.01\n",rayon2);
    return;
  FinSi

  facteur_cube = 3; // ???

  // Calcul des valeurs inferieures et 
  // superieures de la sous-image a parcourir

  double tmp;
  tmp = inf(  point1.x - facteur_cube*rayon1,
              point2.x - facteur_cube*rayon2);
  inf_x = (int) round((double)ref->SpaceToVoxelX(tmp));

  tmp = inf(  point1.y - facteur_cube*rayon1,
              point2.y - facteur_cube*rayon2);
  inf_y = (int) round((double)ref->SpaceToVoxelY(tmp));

  tmp = inf(  point1.z - facteur_cube*rayon1, 
	      point2.z - facteur_cube*rayon2);
  inf_z = (int) round((double)ref->SpaceToVoxelZ(tmp));

  inf_x = sup( 0, inf_x);
  inf_y = sup( 0, inf_y);
  inf_z = sup( 0, inf_z);

  tmp = sup(  point1.x + facteur_cube*rayon1,
	      point2.x + facteur_cube*rayon2);
  sup_x = (int) round((double)ref->SpaceToVoxelX(tmp));

  tmp = sup(  point1.y + facteur_cube*rayon1,
	      point2.y + facteur_cube*rayon2);
  sup_y = (int) round((double)ref->SpaceToVoxelY(tmp));

  tmp = sup(  point1.z + facteur_cube*rayon1,
	      point2.z + facteur_cube*rayon2);
  sup_z = (int) round((double)ref->SpaceToVoxelZ(tmp));

  sup_x = inf( ref->DimX()-1, sup_x);
  sup_y = inf( ref->DimY()-1, sup_y);
  sup_z = inf( ref->DimZ()-1, sup_z);

  // Calcul de d2: la distance (M1,M2) au carre

  d2 = Norme2(point2-point1);

  Si d2 < 1E-4 Alors
    throw Excep_points_proches();
  FinSi
 
  // Parcours de la sous-image: point P(x,y,z)

  for( x= inf_x; x<= sup_x; x++)
  for( y= inf_y; y<= sup_y; y++)
  for( z= inf_z; z<= sup_z; z++)
  {

    // Calcul de ps, le produit scalaire de (M1,M2) avec (M1,P) 

    pt.Init(ref->SpacePosX(x),
            ref->SpacePosY(y),
            ref->SpacePosZ(z));

    ps = (point2-point1)*(pt-point1);

    // 3 cas:
    // cas 1: P se projette entre M1 et M2
    //        dessin d'un cylindre
    if ((ps>=0) Et (ps <= d2)) {

      pv2 = Norme2( (point2-point1)^(pt-point1) );

      rayon = rayon1*(1-sqrt(ps/d2)) + rayon2*sqrt(ps/d2);
      if (sqrt(pv2/d2) < facteur_cube*rayon) {
        recons->BufferPos( x, y, z);
        valeur = ModeleReconstruction(sqrt(pv2/d2),rayon,
                                      recons->ValeurBuffer());
        recons->FixeValeur( valeur);
      }
 
    // cas 2: P se projette avant M1
    //        dessin d'une demi-sphere de rayon rayon1
    } else
    if (ps < 0) {
      // On verifie qu'il ne se projette pas sur le segment precedent
      if (  (point0.x != 0)&&
            (point0.y != 0)&&
            (point0.z != 0) )
      {
        ps = (point0-point1)*(pt-point1);
      } else 
        ps = 0;

      if (ps < 0) {
        distance  = Norme( pt-point1 );
        if (distance < facteur_cube*rayon1) {
          recons->BufferPos( x, y, z);
          valeur = ModeleReconstruction( distance, 
                                         rayon1,
                                         recons->ValeurBuffer());
          recons->FixeValeur( valeur);
        }
      }
    // cas 3: P se projette apres M2
    //        dessin d'une demi-sphere de rayon rayon2
    } else {
      // On verifie qu'il ne se projette pas sur le segment suivant
      if ((point3.x != 0) && 
          (point3.y != 0) &&
          (point3.z != 0) )
      {
        ps = (point3-point2)*(pt-point2);
      } else
        ps = 1;

      if (ps < 0) {
        distance  = Norme( pt-point2);

        if (distance < facteur_cube*rayon2) {
          recons->BufferPos( x, y, z);
          valeur = ModeleReconstruction( distance, rayon2, 
                                         recons->ValeurBuffer());
          recons->FixeValeur( valeur);
        } // end if
      } // end if ps<0
      
    }

  } // end for x,y,z

} // DessineCylindre()



//------------------------------------------------------------------------------
InrImage::ptr LineRecons::Run( SurfacePoly* surf)
{
  InrImage::ptr   recons;
  Point3DPoly p0,p1,p2,p3;
  float _rad1=1;
  float _rad2=1;

  recons = InrImage::ptr(new InrImage( WT_FLOAT,1,"recons.ami.gz", ref.get()));
  recons->InitImage( 5.0);

  //--- Parcours des Lignes dans le fichier Crest
  for( int i=0; i<surf->GetNumberOfLines(); i++) 
  {
    std::cout << "processing line " << i+1 
              << " out of " << surf->GetNumberOfLines() << std::endl;
    T_Line& line = surf->GetLine(i);
    if (line.NbElts()>1) {
      p1 = surf->GetPoint(line[0]);
      if (radii)
        _rad1 = (*radii)(line[0],0,0);
      p0.pt.Init(0,0,0);
      p3 = p0;
  
      //--- Parcours des Points par lignes
      for(int j=1;j<line.NbElts();j++) 
      {

        p2 = surf->GetPoint(line[j]);
        if (radii)
          _rad2 = (*radii)(line[j],0,0);
        // conversion to voxel coordinate
        //ADD_TRANSLATION(p2);
  
        // Parcours de la ligne (M1,M2)
        // Et remplissage du cylindre
        try{
          DessineCylindre (
                            p0.pt, p1.pt,
                            p2.pt, p3.pt,
                            _rad1, _rad2, 
                            ref,
                            recons
                          );
        }
        catch (Excep_points_proches) {
          std::cerr  << "points trop proches ..." 
                << p1.pt << " , " << p2.pt 
                << std::endl;
        }
  
        p0    = p1;
        p1    = p2;
        _rad1  = _rad2;
        p2    = p3;
      } // end for j
    } // if nbpoints>1
  } // end for i

  //--- Libération des objets
  return recons;

} // LineRecons()


// static member LineReconstruction
InrImage::ptr LineRecons::LineReconstruction(amilab::SurfacePoly* surf,
                                            InrImage::ptr ref,
                                            InrImage::ptr rad)
{
  boost::scoped_ptr<LineRecons> lr (new LineRecons());
  lr->SetRadiiImage(rad);
  lr->SetReferenceImage(ref);
  InrImage::ptr res = lr->Run(surf);
  return res;
}
