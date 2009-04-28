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

#include "func_globalstats.h"

//--------------------------------------------------
// count the number of positive points of the image
int   Func_count( InrImage* im)
{
  int num;

  num = 0;

  im->InitBuffer();
  Repeter
    Si (double) (*im) > 1E-8 AlorsFait
      num++;
  JusquA Non(++(*im))  FinRepeter
  
  return num;
}


//--------------------------------------------------
double     Func_mean( InrImage* im)
{
  double mean;

  mean = 0;
  im->InitBuffer();
  Repeter
    mean += im->ValeurBuffer();
  JusquA Non(im->IncBuffer())  FinRepeter
  
  mean /= (im->_tx*im->_ty*im->_tz);

  return mean;
}



//--------------------------------------------------
double     Func_mean( InrImage* im, InrImage* mask)
{
  long  numpoints;
  double  mean;

  mean      = 0;
  numpoints = 0;
  im  ->InitBuffer();
  if (mask!=NULL) mask->InitBuffer();
  Repeter
    Si (mask!=NULL) Et (mask->ValeurBuffer() > 0.5) Alors
      mean += im->ValeurBuffer();
      numpoints++;
    FinSi
    if (mask!=NULL) mask->IncBuffer();
  JusquA Non(im->IncBuffer())  FinRepeter
  
  mean /= numpoints;

  return mean;
}


//--------------------------------------------------
double     Func_max( InrImage* im, InrImage* mask)
{
  double lmax = -1E-10;
  double val;

  if (mask==NULL) {
    im->InitBuffer();
    lmax = im->ValeurBuffer();
    Repeter
      val = im->ValeurBuffer();
    if (val>lmax) lmax = val;
    JusquA Non(im->IncBuffer())  FinRepeter
  } else {
    im->InitBuffer();
    mask->InitBuffer();
    Si mask->ValeurBuffer() > 0.5 AlorsFait
      lmax = im->ValeurBuffer();
    Repeter
      Si mask->ValeurBuffer() > 0.5 Alors
        val = im->ValeurBuffer();
        if (val>lmax) lmax = val;
      FinSi
      mask->IncBuffer();
    JusquA Non(im->IncBuffer())  FinRepeter
  }

  return lmax;
} // Func_max()


//--------------------------------------------------
int     Func_argmax( InrImage* im, InrImage* mask)
{
  double lmax = -1E-10;
  int x,y,z;
  int xm,ym,zm;
  double val;

  xm = ym = zm = 0;
  lmax = (*im)(xm,ym,zm);

  Pour(x,0,im->DimX()-1)
  Pour(y,0,im->DimY()-1)
  Pour(z,0,im->DimZ()-1)

    if (mask!=NULL) 
      if ((*mask)(x,y,z)<0.5) continue;

    val = (*im)(x,y,z);
    if (val>lmax) {
      xm = x;
      ym = y;
      zm = z;
      lmax = val;
    }
  FinPour 
  FinPour 
  FinPour 

  return xm+im->DimX()*(ym+im->DimY()*zm);

} // Func_argmax()


//--------------------------------------------------
double     Func_min( InrImage* im, InrImage* mask)
{
  double lmin = 1E10;
  double val;

  Si (mask==NULL) Alors
    im->InitBuffer();
    lmin = im->ValeurBuffer();
    Repeter
      val = im->ValeurBuffer();
      if (val<lmin) lmin = val;
    JusquA Non(im->IncBuffer())  FinRepeter
  Sinon
    im->InitBuffer();
    mask->InitBuffer();
    Si mask->ValeurBuffer() > 0.5 AlorsFait
      lmin = (double) (*im);
    Repeter
      Si (double) (*mask) > 0.5 Alors
        val = (double) (*im);
        if (val<lmin) lmin = val;
      FinSi
      ++(*mask);
    JusquA Non(++(*im))  FinRepeter
  FinSi
  
  return lmin;
} // Func_min()




//--------------------------------------------------
int qsort_compare(const void* a, const void* b) {
  if ((*(float*)a)>(*(float*)b)) return 1;
  if ((*(float*)a)<(*(float*)b)) return -1;
  return 0;
}


//--------------------------------------------------
// median value of the image
double     Func_med( InrImage* im, float percent, InrImage* mask)
{

  double* values;
  int num_values;
  double median;


  values = (double*) malloc(im->Size()*sizeof(double));
  num_values = 0;

  // use qsort to sort the array and find the median value

  Si (mask==NULL) Alors
    im->InitBuffer();
    Repeter
      values[num_values] = im->ValeurBuffer();
      num_values++;
    JusquA Non(im->IncBuffer())  FinRepeter
  Sinon
    im->InitBuffer();
    mask->InitBuffer();
    Repeter
      Si (double) (*mask) > 0.5 Alors
        values[num_values] = im->ValeurBuffer();
        num_values++;
      FinSi
      ++(*mask);
    JusquA Non(++(*im))  FinRepeter
  FinSi
  
  // now use qsort
  qsort(values,num_values,sizeof(double),qsort_compare);

  int pos = (int ) (1.0*num_values*percent+0.499);
  if (pos<0) pos = 0;
  if (pos>num_values-1) pos = num_values-1;
  median = values[pos];
  free(values);
  return median;

} // Func_med()


InrImage*    Func_Histogram( InrImage* im, float vmin, float vmax, int nint)
{
    InrImage* res;
    int* numpts;
    int  n;
    float v;

      res = new InrImage(nint,1,1,WT_SIGNED_INT);
          // set translation and voxel size of reflect real image intensity values
      res->SetTranslation(vmin,0,0);
      res->SetVoxelSize((vmax-vmin)/(1.0*nint),1,1);

      numpts = new int[nint];
      Pour(n,0,nint-1) 
        numpts[n]=0;
      FinPour

      im->InitBuffer();
      Repeter
        v = im->ValeurBuffer();
        Si v>=vmin Et v<vmax Alors
          n = (int) ((v-vmin)/(vmax-vmin)*nint);
          Si n==nint AlorsFait n=nint-1;
          numpts[n]++;
        FinSi
      JusquA Non(im->IncBuffer()) FinRepeter

      res->InitBuffer();
      Pour(n,0,nint-1) 
        res->FixeValeur(numpts[n]);
        res->IncBuffer();
      FinPour

      delete [] numpts;
    return res;
} // Func_Histogram()

