// Projet Epidaure
// Fichier DirPrincipales.hpp
//
// Diffusion
//
// Karl Krissian    Sophia Antipolis, le 14-10-96
//

#ifndef _DIR_PRINC_HPP
#define _DIR_PRINC_HPP

#include "style.hpp"

#include "dif_param.hpp"

DebutDeclareC
#include <math.h>
//#include <epidaure.h>
//#include <epidaure.ee>
FinDeclareC

//-------------------------------------------
Structure t_Hessien 
//        ---------
DebutStructure

  double xx;
  double xy;
  double xz;
  double yy;
  double yz;
  double zz;

FinStructure // t_Hessien

//-------------------------------------------
Structure t_Gradient
//        ----------
DebutStructure

  double x;
  double y;
  double z;

  double x2;
  double y2;
  double z2;

  double xy;
  double xz;
  double yz;

  double norme;
  double norme2;

FinStructure // t_Gradient

//==========================================================================
class DirPrincipales
//     ==============
{

protected:

  t_Hessien  H;
  t_Gradient G;

public:

  Constructeur DirPrincipales() {}
  //----------

  Destructeur DirPrincipales( ) {}
  //---------

  void FixeGradient( float gx, float gy, float gz);
  //   ------------

  void FixeHessien( float hxx, float hxy, float hxz, float hyy, float hyz, float hzz);
  //   -----------

/*
  void CalculeDirPrinc( t_3Point* v1, t_3Point* v2);
  //   ---------------
*/

  unsigned char CalculeDirPrinc2( t_3Point* v1, t_3Point* v2, double* k1, double* k2);
  //      ----------------

  unsigned char CalculeCourbures( double* k1, double* k2);
  //      ----------------

  void ValeursDerivees( t_Gradient* g, t_Hessien* h)
  //   ---------------
  {
    g->x = G.x;
    g->y = G.y;
    g->z = G.z;

    g->norme2 = G.norme2;
    g->norme  = G.norme;

    h->xx = H.xx;
    h->xy = H.xy;
    h->xz = H.xz;
    h->yy = H.yy;
    h->yz = H.yz;
    h->zz = H.zz;
  }

}; // DirPrincipales


#endif // _DIR_PRINC_HPP
