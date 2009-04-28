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

#include "reponse_cercle.hpp"

//
// integration over a circle of a vector field scalar the normal of a circle
//
InrImage* Func_2DFlux( InrImage* vectors, float radius)
{
  InrImage* res;
  int n,total;
  int i,j;
  float angle;
  double tmp,ca,sa;
  float xpos,ypos,vx,vy;

  res = new InrImage(WT_FLOAT,1,"2DFlux.ami.gz",vectors);
  res->InitImage(0);

  total = (int) (2.0*PI*radius);
  
  res->InitBuffer();
  for(j=0;j<res->DimY();j++)
  for(i=0;i<res->DimX();i++) {
    tmp=0;
    for(n=0;n<total;n++) {
      angle = (2.0*PI/n)*total;
      ca = cos(angle);
      sa = sin(angle);
      xpos = i + radius*ca;
      ypos = j + radius*sa;
      // get interpolated vector at (xpos,ypos)
      vx = vectors->InterpLinIntensite(xpos,ypos,0, 0);
      vy = vectors->InterpLinIntensite(xpos,ypos,0, 1);
      tmp += vx*ca+vy*sa;
    }
    res->FixeValeur(tmp);
    res->IncBuffer();
  }

  return res;
}

InrImage*    Func_CircleIntegration( InrImage* grad, InrImage* vep0, 
                     InrImage* vep1, float radius,
                     int type,
                     InrImage* mask)
{

   
    int              x,y,z;
    CalculRepCercle* rep;
    InrImage*        out;
    Vect3D<double>   v0;
    Vect3D<double>   v1;
    

  out = new InrImage(WT_FLOAT,1,"circle_integral.ami.gz",grad);
  out->InitImage(0);

  rep = new CalculRepCercle( grad, type);
  rep->FixeRayon(            radius, 1);
  rep->SetGradient(          grad);
  //  rep->SetFilter(         filtre);
  //  rep->SetNoLinearInterp( NoLinearInterp);
  //  rep->SetOptReponse(     OptReponse);
  //  rep->SetSeuilET(        SeuilET);
  //  rep->SetSeuilEXC(       SeuilEXC);

  out ->InitBuffer();
  vep0->InitBuffer();
  vep1->InitBuffer();
  mask->InitBuffer();

  Pour( z, 0, grad->_tz - 1)
  Pour( y, 0, grad->_ty - 1)
  Pour( x, 0, grad->_tx - 1)

    Si mask==NULL Ou mask->ValeurBuffer()>0.5 Alors

      v0.Init( vep0->VectValeurBuffer(0),
           vep0->VectValeurBuffer(1),
           vep0->VectValeurBuffer(2));

      v1.Init( vep1->VectValeurBuffer(0),
           vep1->VectValeurBuffer(1),
           vep1->VectValeurBuffer(2));

      rep->CalculReponses(x,y,z,v0,v1, 1);
      out->FixeValeur(rep->Reponse(type));

    FinSi

    out ->IncBuffer();
    vep0->IncBuffer();
    vep1->IncBuffer();
    mask->IncBuffer();

  FinPour
  FinPour
  FinPour

  delete rep;  

  return out;

} // Func_CircleIntegration()


//----------------------------------------------------------------------
//
//
InrImage*    Func_CircleIntSdExc( InrImage* grad, InrImage* vep0, 
                  InrImage* vep1, float radius,
                  InrImage* mask,
                  float th_sd,
                  float th_exc,
                  int pairs_mode,
                  int highest_percentage,
                  int mode )
{
    int              x,y,z;
    CalculRepCercle* rep;
    InrImage*        out;
    Vect3D<double>   v0;
    Vect3D<double>   v1;

  out = new InrImage(WT_FLOAT,1,"circle_integral.ami.gz",grad);
  out->InitImage(0);

  rep = new CalculRepCercle( grad, mode);
  //  rep->SetFilter(         filtre);
  rep->SetNoLinearInterp( 1);
  //  rep->SetOptReponse(     1);
  rep->useSD(  true, th_sd);

  rep->ReducePairs( true, pairs_mode);
  rep->KeepHighest( true, highest_percentage);

  if (th_exc<5) 
    rep->useEXC( true, th_exc);
  else
    rep->useEXC( false);

  rep->FixeRayon(            radius, 1);
  rep->SetGradient(          grad);

  out ->InitBuffer();
  vep0->InitBuffer();
  vep1->InitBuffer();
  mask->InitBuffer();

  Pour( z, 0, grad->_tz - 1)
  Pour( y, 0, grad->_ty - 1)
  Pour( x, 0, grad->_tx - 1)

    Si mask==NULL Ou mask->ValeurBuffer()>0.5 Alors

      v0.Init( vep0->VectValeurBuffer(0),
           vep0->VectValeurBuffer(1),
           vep0->VectValeurBuffer(2));

      v1.Init( vep1->VectValeurBuffer(0),
           vep1->VectValeurBuffer(1),
           vep1->VectValeurBuffer(2));

      rep->CalculReponses(x,y,z,v0,v1, 1);
      out->FixeValeur(rep->Reponse(mode));

    FinSi

    out ->IncBuffer();
    vep0->IncBuffer();
    vep1->IncBuffer();
    mask->IncBuffer();

  FinPour
  FinPour
  FinPour

  delete rep;  

  return out;

} // Func_CircleIntSdExc()


//----------------------------------------------------------------------
// Check for local maxima of the image im
// in the plane given by vep0 and vep1
// over a circle of radius 0.5 with 'samples' sample points.
//
//
InrImage*    Func_LocalExtrema( InrImage* im, 
                InrImage* vep0, 
                InrImage* vep1, 
                InrImage* mask,
                int samples)
{

   
    int              x,y,z;
    InrImage*        out;
    int              i;
    Vect3D<float>    v0;
    Vect3D<float>    v1;
    Point_3D<float>  p;
    Point_3D<float>  pos;

    float            I0,I;

    unsigned char          extrema;
    double       alpha;
    double       d_alpha;

    // number of neighbors in the cross-section which have higher reponse

    int               nb_neighbors_sup; 

  out = new InrImage(WT_FLOAT,1,"local_extrema.ami.gz",im);
  out->InitImage(0);

  out ->InitBuffer();
  im  ->InitBuffer();
  vep0->InitBuffer();
  vep1->InitBuffer();
  mask->InitBuffer();

  Pour( z, 0, im->_tz - 1)
  Pour( y, 0, im->_ty - 1)
  Pour( x, 0, im->_tx - 1)

    Si mask==NULL Ou mask->ValeurBuffer()>0.5 Alors

      v0.Init( vep0->VectValeurBuffer(0),
           vep0->VectValeurBuffer(1),
           vep0->VectValeurBuffer(2));

      v1.Init( vep1->VectValeurBuffer(0),
           vep1->VectValeurBuffer(1),
           vep1->VectValeurBuffer(2));

      p.Init(x,y,z);

      I0 = (*im)(x,y,z);

      // Check the local extrema
      extrema = true;
      //      n = 16;
      //      n = (int) (4*radius);
      //      Si n<4 AlorsFait n = 4;
      alpha = 0.0;
      d_alpha = 2.0*PI/samples;
      i = 0;
      nb_neighbors_sup = 0;
      TantQue (i<samples) Et (extrema) Faire

        pos = p + (float)(0.5*cos(alpha))*v0 + (float)(0.5*sin(alpha)) *v1;

        I = im->InterpLinIntensite( pos.x, pos.y, pos.z);
        Si I>I0 AlorsFait nb_neighbors_sup++;
        Si nb_neighbors_sup>1 AlorsFait extrema=false;

        i++;
        alpha += d_alpha;

      FinTantQue

      Si extrema  AlorsFait out->FixeValeur(I0);

    FinSi

    out ->IncBuffer();
    vep0->IncBuffer();
    vep1->IncBuffer();
    mask->IncBuffer();
    im  ->IncBuffer();

  FinPour
  FinPour
  FinPour


  return out;

} // Func_LocalExtrema()
