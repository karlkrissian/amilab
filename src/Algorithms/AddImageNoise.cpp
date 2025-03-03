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
//  bruit.cpp
//
// code dans Numerical Recipies of C
//
// But: Creer une librairie pour generer
// un bruit al�atoire verifiant une loi donnee
//


#include "style.hpp"

extern "C" {
#include <math.h>
#include <stdio.h>
}

#include "AddImageNoise.h"
#include <time.h>
#include <boost/scoped_ptr.hpp>

#define IA   16807
#define IM   2147483647
#define AM   (1.0/IM)
#define IQ   127773
#define IR   2836
#define NTAB 32
#define NDIV (1+(IM-1)/NTAB)
#define EPS  1.2E-7
#define RNMX (1.0-EPS)


namespace ami {
  
//-----------------------------------------------------------------------------
void AddImageNoise::InitRand(int* _idnum)
{
  // initialisation de la sequence
  time_t rawtime;
  struct tm * timeinfo;

  time ( &rawtime );
  timeinfo = localtime ( &rawtime );

  *_idnum = -timeinfo->tm_sec;
  ran1(_idnum);
}

//-----------------------------------------------------------------------------
float AddImageNoise::ran1(int* idum)
//    ----
// Returns a uniform random deviate between 0.0 and 1.0.
// Set idum to any negative value to initialize or reinitialize the sequence.
//
{

  int  j;
  long k;
  static long iy=0;
  static long iv[NTAB];
  float temp;

  if (*idum <= 0 || !iy) {
    if (-(*idum) < 1) *idum=1;
    else *idum = -(*idum);
    for (j=NTAB+7;j>=0;j--) {
      k=(*idum)/IQ;
      *idum = IA*(*idum-k*IQ)-IR*k;
      if (*idum<0) *idum += IM;
      if (j<NTAB) iv[j]=*idum;
    }
    iy=iv[0];
  }
  k=(*idum)/IQ;
  *idum=IA*(*idum-k*IQ)-IR*k;
  if (*idum<0) *idum += IM;
  j=iy/NDIV;
  iy=iv[j];
  iv[j]=*idum;
  if ((temp=AM*iy) > RNMX) return RNMX;
  else return temp;

}


float AddImageNoise::bruit_gaussien(int* idum)
//   --------------
//  return une variable aleatoire qui suit une loi gaussienne
//  de moyenne nulle et d'ecart type 1
//
{

  static int iset=0;
  static float   gset;
  float   fac,r,v1,v2;
  
  Si iset==0 Alors
    Repeter
      v1 = 2.0*ran1(idum)-1.0;
      v2 = 2.0*ran1(idum)-1.0;
      r  = v1*v1+v2*v2;
    JusquA (r > 0.0) Et (r < 1.0)
    FinRepeter

    fac  = sqrt( -2.0*log(r)/r);
    gset = v1*fac;
    iset = 1;
    return v2*fac;
  Sinon
    iset = 0;
    return gset;
  FinSi

} // bruit_gaussien()



float AddImageNoise::bruit_gaussien(int* idum, float moyenne, float ecart_type)
//   --------------
//  return une variable aleatoire qui suit une loi gaussienne
//  de moyenne et d'ecart type donnes
//
{

  return moyenne + ecart_type*bruit_gaussien(idum);

} // bruit_gaussien()


//------------------------------------------------------------------------------
void AddImageNoise::AddGaussianNoise(InrImage* im, float moy, float et)
//
{
  boost::scoped_ptr<int> _idnum(new int(0));
  AddImageNoise::InitRand(_idnum.get());
  
  im->InitBuffer();
  Repeter
    for(int n=0;n<im->GetVDim();n++) {
      im->VectFixeValeur( n,
                          im->VectValeurBuffer(n) + 
                          bruit_gaussien(_idnum.get(),moy,et) );
    }
  JusquA Non(im->IncBuffer()) FinRepeter
  
} // AddGaussianNoise()


//------------------------------------------------------------------------------
void AddImageNoise::AddSaltAndPepper( InrImage* im, 
                                      double salt, double pepper,
                                      double imin, double imax)
{
  boost::scoped_ptr<int> _idnum(new int(0));
  AddImageNoise::InitRand(_idnum.get());

  im->InitBuffer();
  Repeter
    for(int n=0;n<im->GetVDim();n++) {
      double val = ran1(_idnum.get());
      if (val<salt)     im->VectFixeValeur(n, imax );
      if (val>=pepper)  im->VectFixeValeur(n, imin );
    }
  JusquA Non(im->IncBuffer()) FinRepeter
  
}

//------------------------------------------------------------------------------
void AddImageNoise::AddUniformNoise(InrImage* im, float valmax)
{
  boost::scoped_ptr<int> _idnum(new int(0));
  AddImageNoise::InitRand(_idnum.get());

  im->InitBuffer();
  Repeter
    for(int n=0;n<im->GetVDim();n++) {
      double val = ran1(_idnum.get());
      im->VectFixeValeur(n, im->VectValeurBuffer(n+val*valmax) );
    }
  JusquA Non(im->IncBuffer()) FinRepeter
}


}


