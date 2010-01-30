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
 * $Revision: 1.5 $
 * $Log: EDPmorpho.c,v $
 * Revision 1.5  2005/11/16 14:03:07  karl
 * added LGPL license
 *
 * Revision 1.4  2005/10/27 18:01:07  karl
 * several improvement while writting filtering paper
 *
 * Revision 1.3  2005/10/17 15:29:44  karl
 * current version
 *
 * Revision 1.2  2004/06/02 22:57:34  karl
 * Connected Components + some bugs fixed
 *
 * Revision 1.1.1.1  2004/02/02 20:47:07  karl
 * source code in C++
 *
 * Revision 1.1.1.1  2003/08/14 07:16:14  karl
 * Source code
 *
 * Revision 1.2  2000/07/10 15:48:03  karl
 * *** empty log message ***
 *
 ***************************************************************************/

#include "style.hpp"
#include "math1.hpp"
#include "EDPmorpho.h"

extern unsigned char GB_debug; 


#define ERODE  1
#define DILATE 2
#define OUVERTURE 3
#define FERMETURE 4


static   const float c0 = (1.-sqrt(2.0)/2.0)*(1.-sqrt(2.0)/2.0);
static   const float c1 = (2.*sqrt(2.0)-2.)/4.0;

class ContinuousMorphology {

 private:
   long tx,ty,tz,txy;
   int     Schema;
   //   InrImage*  result;
   float         Imin,Imax;
   unsigned char use_limits;


   float interp( float* buf_image,  int dx, int dy);

   float NormGradient( float* buf_image, 
              int x, int y, int z, 
              float Vitesse);

   double Schema1D( float Dm, float Dp, float F);

   void Iteration( InrImage* image1, InrImage* image2, 
          float dt, int type);

 public:

   ContinuousMorphology() 
     {
       use_limits=0;
     }

   ~ContinuousMorphology() {}

   void SetScheme(int scheme) { Schema=scheme; }

   void SetLimits(float min, float max) { Imin = min; Imax=max; use_limits=1; }

   InrImage* EDP( InrImage* entree,  float taille, float step, int type);

   InrImage* Dilate(InrImage* entree,  float taille,float step);
   InrImage* Erode( InrImage* entree,  float taille,float step);
   InrImage* Open(  InrImage* entree,  float taille,float step);
   InrImage* Close( InrImage* entree,  float taille,float step);

};





//----------------------------------------------------------------------
float ContinuousMorphology::interp( float* buf_image,  int dx, int dy)
{

  return ((*buf_image)*c0+
          (*(buf_image+dx)+*(buf_image+dy))*c1+
          *(buf_image+dx+dy)*0.5);
}

//----------------------------------------------------------------------
float ContinuousMorphology::NormGradient( float* buf_image, 
                     int x, int y, int z, 
                     float Vitesse)
//
{

   
    int   xp,yp,zp,xm,ym,zm;
    float   dxp,dyp,dzp;
    float   dxm,dym,dzm;
    register float   norm,val; //,normx,normy,normz,  sqrt2, norm1;
    register float   val_max; //,val_min;

  xp = yp = zp = 0;
  xm = ym = zm = 0;

  Si x+1 < tx AlorsFait  xp = 1;
  Si y+1 < ty AlorsFait  yp = tx;
  Si z+1 < tz AlorsFait  zp = txy;
  Si x   > 0  AlorsFait  xm = -1;
  Si y   > 0  AlorsFait  ym = -tx;
  Si z   > 0  AlorsFait  zm = -txy;

  dxp = *(buf_image+xp) - *buf_image;
  dyp = *(buf_image+yp) -  *buf_image;
  dzp = *(buf_image+zp) -  *buf_image;
  dxm = *buf_image - *(buf_image+xm);
  dym = *buf_image - *(buf_image+ym);
  dzm = *buf_image - *(buf_image+zm);

  norm = 0;

  switch ( Schema ){

    case SCHEMA_OS:
    case SCHEMA_BM:
      norm += Schema1D( dxm, dxp, Vitesse);
      norm += Schema1D( dym, dyp, Vitesse);
      norm += Schema1D( dzm, dzp, Vitesse);
      norm = sqrt(norm);
    break;

    case SCHEMA_AUTRE:
      Si Vitesse>0 Alors
        // 6 voisins proches
        norm = 0;
        Si -dxm > norm AlorsFait norm = -dxm;
        Si  dxp > norm AlorsFait norm = dxp; 
        Si -dym > norm AlorsFait norm = -dym;
        Si  dyp > norm AlorsFait norm =  dyp;
        Si -dzm > norm AlorsFait norm = -dzm;
        Si  dzp > norm AlorsFait norm =  dzp;

        // 12 autres voisins

        val_max = *buf_image;

        // XY
        val = interp(buf_image,xp,yp);
        Si val>val_max AlorsFait val_max = val;
        val = interp(buf_image,xp,ym);
        Si val>val_max AlorsFait val_max = val;
        val = interp(buf_image,xm,yp);
        Si val>val_max AlorsFait val_max = val;
        val = interp(buf_image,xm,ym);
        Si val>val_max AlorsFait val_max = val;

       val = (val_max- *buf_image);
       Si val>norm AlorsFait norm = val;

         /*
        val = *(buf_image+xp+yp);
        Si val>val_max AlorsFait val_max = val;
        val = *(buf_image+xp+ym);
        Si val>val_max AlorsFait val_max = val;
        val =*(buf_image+xm+yp);
        Si val>val_max AlorsFait val_max = val;
        val =*(buf_image+xm+ym);
        Si val>val_max AlorsFait val_max = val;
         */

/*
       if (tz>1) {
     // XZ
     Si x< tx-1 Et z<tz-1 AlorsFait  val = *(buf_image+1+txy);
     Si val>val_max AlorsFait val_max = val;
     Si x< tx-1 Et z>0    AlorsFait  val = *(buf_image+1-txy);
     Si val>val_max AlorsFait val_max = val;
     Si x>0 Et z>0        AlorsFait  val =*(buf_image-1-txy);
     Si val>val_max AlorsFait val_max = val;
     Si x>0 Et z<tz-1     AlorsFait  val =*(buf_image-1+txy);
     Si val>val_max AlorsFait val_max = val;
     
     // YZ
     Si y< ty-1 Et z<tz-1 AlorsFait  val =*(buf_image+tx+txy);
     Si val>val_max AlorsFait val_max = val;
     Si y< ty-1 Et z>0    AlorsFait  val =*(buf_image+tx-txy);
     Si val>val_max AlorsFait val_max = val;
     Si y>0 Et z>0        AlorsFait  val =*(buf_image-tx-txy);
     Si val>val_max AlorsFait val_max = val;
     Si y>0 Et z<tz-1     AlorsFait  val =*(buf_image-tx+txy);
     Si val>val_max AlorsFait val_max = val;
       }

       if (tz>1) {
         // 8 autres
       }


       val = (val_max- *buf_image)/sqrt(2);
       Si val>norm AlorsFait norm = val;
*/

      Sinon
        // 6 voisins proches
        norm = 0;
        Si  dxm > norm AlorsFait norm =  dxm;
        Si -dxp > norm AlorsFait norm = -dxp; 
        Si  dym > norm AlorsFait norm =  dym;
        Si -dyp > norm AlorsFait norm = -dyp;
        Si  dzm > norm AlorsFait norm =  dzm;
        Si -dzp > norm AlorsFait norm = -dzp;

        // 12 autres voisins
/*
        val_min = *buf_image;
        // XY
        val = *(buf_image+xp+yp);
        Si val<val_min AlorsFait val_min = val;
        val = *(buf_image+xp+ym);
        Si val<val_min AlorsFait val_min = val;
        val =*(buf_image+xm+ym);
        Si val<val_min AlorsFait val_min = val;
        val =*(buf_image+xm+yp);
        Si val<val_min AlorsFait val_min = val;

       if (tz>1) {
     // XZ
     Si x< tx-1 Et z<tz-1 AlorsFait  val = *(buf_image+1+txy);
     Si val<val_min AlorsFait val_min = val;
     Si x< tx-1 Et z>0    AlorsFait  val = *(buf_image+1-txy);
     Si val<val_min AlorsFait val_min = val;
     Si x>0 Et z>0        AlorsFait  val =*(buf_image-1-txy);
     Si val<val_min AlorsFait val_min = val;
     Si x>0 Et z<tz-1     AlorsFait  val =*(buf_image-1+txy);
     Si val<val_min AlorsFait val_min = val;
     
     // YZ
     Si y< ty-1 Et z<tz-1 AlorsFait  val =*(buf_image+tx+txy);
     Si val<val_min AlorsFait val_min = val;
     Si y< ty-1 Et z>0    AlorsFait  val =*(buf_image+tx-txy);
     Si val<val_min AlorsFait val_min = val;
     Si y>0 Et z>0        AlorsFait  val =*(buf_image-tx-txy);
     Si val<val_min AlorsFait val_min = val;
     Si y>0 Et z<tz-1     AlorsFait  val =*(buf_image-tx+txy);
     Si val<val_min AlorsFait val_min = val;
       }

       val = (*buf_image-val_min)/sqrt(2);
       Si val>norm AlorsFait norm = val;

       if (tz>1) {
         // 8 autres
       }
*/
      FinSi

    break;

  } // end switch


  return norm;

} // NormGradient()


//----------------------------------------------------------------------
// Calcul de la derivee 1D en fonction du sens de propapagation
// et du schema
double ContinuousMorphology::Schema1D( float Dm, float Dp, float F)
//
{

  
    double res;

  res = 0;
  switch ( Schema ){

    case SCHEMA_OS:
      Si F*Dm < 0 AlorsFait res += Dm*Dm;
      Si F*Dp > 0 AlorsFait res += Dp*Dp;
    break;

    case SCHEMA_BM:
    case SCHEMA_AUTRE:
      Si F*Dm < 0 AlorsFait res  = Dm*Dm;
      Si F*Dp > 0 AlorsFait
        Si Dp*Dp > res AlorsFait 
                            res = Dp*Dp;
    break;

  } // end switch

  return res;

} // Schema1D()


//----------------------------------------------------------------------
void ContinuousMorphology::Iteration( InrImage* image1, InrImage* image2, float dt, int type)
//
{

   
    int x,y,z;
    float   val,newval;
    float*  buf_image;

    float   Vitesse=0;
    unsigned char skip;

  switch ( type ){
    case DILATE: Vitesse = 1;    break;
    case ERODE:  Vitesse = -1;   break;
  } // end switch


  image2->InitBuffer();
  image1->InitBuffer();

  tx = image1->_tx;
  ty = image1->_ty;
  tz = image1->_tz;
  txy = image1->_tx*image1->_ty;


  Pour(z,0,image1->_tz-1)
  Pour(y,0,image1->_ty-1)
  Pour(x,0,image1->_tx-1)
  
    val = image1->ValeurBuffer();
    skip=0;
    if (use_limits) {
      if ( ((val>=Imax)&&(Vitesse>0))||
           ((val<=Imin)&&(Vitesse<0)) )
         skip=1;
    }
      
    if (!skip) {
      buf_image = (float*) image1->BufferPtr();

      newval = val + dt*Vitesse*NormGradient(buf_image,x,y,z,Vitesse);
      image2->FixeValeur( newval);

      /*
      Si record_time Alors
        val    -= isovalue;
        newval -= isovalue;
        Si val==0  Alors
          time_image->BufferPos(x,y,z);
          time_image->FixeValeur( evolution_time);
        FinSi
        Si val>0 Et newval<0 Alors
          time_image->BufferPos(x,y,z);
          time_image->FixeValeur( -(evolution_time + dt*val/(val-newval)));
        FinSi
        Si val<0 Et newval>0 Alors
          time_image->BufferPos(x,y,z);
          time_image->FixeValeur( evolution_time + dt*val/(val-newval));
        FinSi
      FinSi
      */
    }
    else
      image2->FixeValeur( val);

    image2->IncBuffer();
    image1->IncBuffer();

  FinPour
  FinPour
  FinPour

} // Iteration()


//----------------------------------------------------------------------
InrImage* ContinuousMorphology::EDP( InrImage* entree, 
           float size,  float step,
           int type)
//
{

  
    int     nb_iter, n;
    float       dt1;
    InrImage*  image_in;
    InrImage*  image_out;
    InrImage*  swap;
  
  image_in  = new InrImage( WT_FLOAT, "image_in.inr.gz", entree);
  image_out = new InrImage( WT_FLOAT, "image_out.inr.gz", entree);

  nb_iter = (int) (size / step + 1);

  Si nb_iter > 100 Alors
    fprintf(stderr,"EDP() number of iterations limited to 100 \n");
    nb_iter=100;
  FinSi

  dt1 = size / nb_iter;

  switch ( type ){

    case ERODE:
    case DILATE:
      (*image_in) = (*entree);
      Pour(n,0,nb_iter-1)
        if (GB_debug) {
      printf("\t iteration %d/%d\n",n+1,nb_iter);
      fflush(stdout);
    }
        Si n>0 Alors
          swap=image_in;
          image_in = image_out;
          image_out = swap;
        FinSi
        Iteration( image_in, image_out, dt1, type);
      FinPour
      if (GB_debug) printf("\n");
    break;

    case OUVERTURE:
      (*image_in) = (*entree);
      Pour(n,0,nb_iter-1)
        if (GB_debug) {
      printf("\t iteration %d/%d\n",n+1,nb_iter);
      fflush(stdout);
    }
        Si n>0 Alors
          swap      = image_in;
          image_in  = image_out;
          image_out = swap;
        FinSi
        Iteration( image_in, image_out, dt1, ERODE);
      FinPour
      if (GB_debug) printf("\n");

      Pour(n,0,nb_iter-1)
        if (GB_debug) {
      printf("\t iteration %d/%d\n",n+1,nb_iter);
      fflush(stdout);
    }
        fflush(stdout);
        Si n>0 Alors
          swap      = image_in;
          image_in  = image_out;
          image_out = swap;
        FinSi
        Iteration( image_in, image_out, dt1, DILATE);
      FinPour
      if (GB_debug) printf("\n");

    break;

    case FERMETURE:
      (*image_in) = (*entree);
      Pour(n,0,nb_iter-1)
        if (GB_debug) {
      printf("\t iteration %d/%d\n",n+1,nb_iter);
      fflush(stdout);
    }
        Si n>0 Alors
          swap      = image_in;
          image_in  = image_out;
          image_out = swap;
        FinSi
        Iteration( image_in, image_out, dt1, DILATE);
      FinPour
      if (GB_debug) printf("\n");

      Pour(n,0,nb_iter-1)
        if (GB_debug) {
      printf("\t iteration %d/%d\n",n+1,nb_iter);
      fflush(stdout);
    }
        Si n>0 Alors
          swap      = image_in;
          image_in  = image_out;
          image_out = swap;
        FinSi
        Iteration( image_in, image_out, dt1, ERODE);
      FinPour
      if (GB_debug) printf("\n");

    break;

  } // end switch

  delete image_in;
  return image_out;

} // EDP()


InrImage* ContinuousMorphology::Dilate( InrImage* input,  float size, float step)
{
  return EDP(input,size,step,DILATE);
}

InrImage* ContinuousMorphology::Erode( InrImage* input,  float size, float step)
{
  return EDP(input,size,step,ERODE);
}

InrImage* ContinuousMorphology::Open( InrImage* input,  float size, float step)
{
  return EDP(input,size,step,OUVERTURE);
}

InrImage* ContinuousMorphology::Close( InrImage* input,  float size, float step)
{
  return EDP(input,size,step,FERMETURE);
}


InrImage* Func_EDP_dilate( InrImage* input,  float size, float step, int schema)
{
  ContinuousMorphology* cm;
  cm  = new ContinuousMorphology();
  InrImage* res;
  cm->SetScheme(schema);
  res=cm->Dilate(input,size,step);
  delete cm;
  return res;
}

InrImage* Func_EDP_erode( InrImage* input,  float size, float step, int schema)
{
  ContinuousMorphology* cm = new ContinuousMorphology();
  InrImage* res;
  cm->SetScheme(schema);
  res=cm->Erode(input,size,step);
  delete cm;
  return res;
}

InrImage* Func_EDP_open( InrImage* input,  float size, float step, int schema)
{
  ContinuousMorphology* cm = new ContinuousMorphology();
  InrImage* res;
  cm->SetScheme(schema);
  res=cm->Open(input,size,step);
  delete cm;
  return res;
}

InrImage* Func_EDP_close( InrImage* input,  float size, float step, int schema)
{
  ContinuousMorphology* cm = new ContinuousMorphology();
  InrImage* res;
  cm->SetScheme(schema);
  res=cm->Close(input,size,step);
  delete cm;
  return res;
}


InrImage* Func_EDP_dilate( InrImage* input,  float size, float step,  
               float min, float max, int schema)
{
  ContinuousMorphology* cm = new ContinuousMorphology();
  InrImage* res;
  cm->SetScheme(schema);
  cm->SetLimits(min,max);
  res=cm->Dilate(input,size,step);
  delete cm;
  return res;
}

InrImage* Func_EDP_erode( InrImage* input,  float size, float step,  
               float min, float max, int schema)
{
  ContinuousMorphology* cm = new ContinuousMorphology();
  InrImage* res;
  cm->SetScheme(schema);
  cm->SetLimits(min,max);
  res=cm->Erode(input,size,step);
  delete cm;
  return res;
}

InrImage* Func_EDP_open( InrImage* input,  float size, float step,  
               float min, float max, int schema)
{
  ContinuousMorphology* cm = new ContinuousMorphology();
  InrImage* res;
  cm->SetScheme(schema);
  cm->SetLimits(min,max);
  res=cm->Open(input,size,step);
  delete cm;
  return res;
}

InrImage* Func_EDP_close( InrImage* input,  float size, float step,  
               float min, float max, int schema)
{
  ContinuousMorphology* cm = new ContinuousMorphology();
  InrImage* res;
  cm->SetScheme(schema);
  cm->SetLimits(min,max);
  res=cm->Close(input,size,step);
  delete cm;
  return res;
}

