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
int   ami::count( InrImage* im)
{
  int num;

  num = 0;

  InrImageIteratorBase::ptr im_it (im->CreateConstIterator());

  im_it->InitBuffer();
  do {
    if ( im_it->GetDoubleValue() > 1E-8 ) 
      num++;
  } while (++(*im_it));
  
  return num;
}

//------------------------------------------------------------------------------
boost::shared_ptr<ami::Mean> ami::Mean::operator[](InrImage::ptr m)
{
  boost::shared_ptr<Mean> res(new Mean());
  res->mask = m;
  return res;
}

//------------------------------------------------------------------------------
double ami::Mean::operator()(InrImage::ptr im, InrImage::ptr m) {
  if (im.get())
    if (m.get())
      return Func_mean(im.get(),m.get());
    else
      if (mask.get())
        return Func_mean(im.get(),mask.get());
      else
        return Func_mean(im.get());
  else
    return 0.0;
}

//--------------------------------------------------
double     Func_sum( InrImage* im)
{
  double sum;

  sum = 0;
  im->InitBuffer();
  do {
    sum += im->ValeurBuffer();
  } while (im->IncBuffer());
  
  return sum;
}

//--------------------------------------------------
double     Func_sum( InrImage* im, InrImage* mask)
{
  long  numpoints;
  double  sum;

  sum      = 0;
  numpoints = 0;
  im  ->InitBuffer();
  if (mask!=NULL) mask->InitBuffer();
  do {
    if ( (mask!=NULL) && (mask->ValeurBuffer() > 0.5) ) {
      sum += im->ValeurBuffer();
      numpoints++;
    } // end if
    if (mask!=NULL) mask->IncBuffer();
  } while (im->IncBuffer());
  
  return sum;
}

//------------------------------------------------------------------------------
boost::shared_ptr<ami::Sum> ami::Sum::operator[](InrImage::ptr m)
{
  boost::shared_ptr<Sum> res(new Sum());
  res->mask = m;
  return res;
}

//------------------------------------------------------------------------------
double ami::Sum::operator()(InrImage::ptr im, InrImage::ptr m) {
  if (im.get())
    if (m.get())
      return Func_sum(im.get(),m.get());
    else
      if (mask.get())
        return Func_sum(im.get(),mask.get());
      else
        return Func_sum(im.get());
  else
    return 0.0;
}

//--------------------------------------------------
double     Func_mean( InrImage* im)
{
  double mean;

  mean = 0;
  im->InitBuffer();
  do {
    mean += im->ValeurBuffer();
  } while (im->IncBuffer());
  
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
  do {
    if ( (mask!=NULL) && (mask->ValeurBuffer() > 0.5) ) {
      mean += im->ValeurBuffer();
      numpoints++;
    } // end if
    if (mask!=NULL) mask->IncBuffer();
  } while (im->IncBuffer());
  
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
    do {
      val = im->ValeurBuffer();
    if (val>lmax) lmax = val;
    } while (im->IncBuffer());
  } else {
    im->InitBuffer();
    mask->InitBuffer();
    if ( mask->ValeurBuffer() > 0.5 ) 
      lmax = im->ValeurBuffer();
    do {
      if ( mask->ValeurBuffer() > 0.5 ) {
        val = im->ValeurBuffer();
        if (val>lmax) lmax = val;
      } // end if
      mask->IncBuffer();
    } while (im->IncBuffer());
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

  for(x=0;x<=im->DimX()-1;x++) {
  for(y=0;y<=im->DimY()-1;y++) {
  for(z=0;z<=im->DimZ()-1;z++) {

    if (mask!=NULL) 
      if ((*mask)(x,y,z)<0.5) continue;

    val = (*im)(x,y,z);
    if (val>lmax) {
      xm = x;
      ym = y;
      zm = z;
      lmax = val;
    }
  } // endfor 
  } // endfor 
  } // endfor 

  return xm+im->DimX()*(ym+im->DimY()*zm);

} // Func_argmax()



/**
 * @brief Return the maximal value position in the image
 *
 * @param im input image
 * @param mask mask (optional)
 * @return std::vector<int> position in each coordinate
 **/
std::vector<int>  ami::argmax( InrImage* im, InrImage* mask)
{
  double lmax = -1E-10;
  int x,y,z;
  int xm,ym,zm;
  double val;

  xm = ym = zm = 0;
  lmax = (*im)(xm,ym,zm);

  for(x=0;x<=im->DimX()-1;x++) {
  for(y=0;y<=im->DimY()-1;y++) {
  for(z=0;z<=im->DimZ()-1;z++) {

    if (mask!=NULL) 
      if ((*mask)(x,y,z)<0.5) continue;

    val = (*im)(x,y,z);
    if (val>lmax) {
      xm = x;
      ym = y;
      zm = z;
      lmax = val;
    }
  } // endfor 
  } // endfor 
  } // endfor 

  std::vector<int> res;
  res.push_back(xm);
  res.push_back(ym);
  res.push_back(zm);
  return res;
  //xm+im->DimX()*(ym+im->DimY()*zm);

} // Func_argmax()


//--------------------------------------------------
double     Func_min( InrImage* im, InrImage* mask)
{
  double lmin = 1E10;
  double val;

  InrImageIteratorBase::ptr im_it   (im  ->CreateConstIterator());
  InrImageIteratorBase* im_it_ptr = im_it.get();
  int vdim = im->GetVDim();
  if ( (mask==NULL) ) {
    im_it_ptr->InitBuffer();
    im_it_ptr->SetEnd(im->Size());
    lmin = im_it_ptr->GetDoubleValue();
    do {
      val = im_it_ptr->GetDoubleValue();
      if (val<lmin) lmin = val;
      im_it_ptr->ValueInc(vdim);
    } while (im_it_ptr->NotAtEnd());
  } else {
    InrImageIteratorBase::ptr mask_it (mask->CreateConstIterator());
    im_it->InitBuffer();
    mask_it->InitBuffer();
    if ( mask_it->GetDoubleValue() > 0.5 ) 
      lmin = im_it->GetDoubleValue();
    do {
      if ( mask_it->GetDoubleValue() > 0.5 ) {
        val = im_it->GetDoubleValue();
        if (val<lmin) lmin = val;
      } // end if
      ++(*mask_it);
    } while (++(*im_it));
  } // end if
  
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

  InrImageIteratorBase::ptr im_it   (im  ->CreateConstIterator());

  values = (double*) malloc(im->Size()*sizeof(double));
  num_values = 0;

  // use qsort to sort the array and find the median value

  if ( (mask==NULL) ) {
    im_it->InitBuffer();
    do {
      values[num_values] = im_it->GetDoubleValue();
      num_values++;
    } while ((*im_it)++);
  } else {
    InrImageIteratorBase::ptr mask_it (mask->CreateConstIterator());
    im_it->InitBuffer();
    mask_it->InitBuffer();
    do {
      if ( mask_it->GetDoubleValue() > 0.5 ) {
        values[num_values] = im_it->GetDoubleValue();
        num_values++;
      } // end if
      (*mask_it)++;
    } while (++(*im_it));
  } // end if
  
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
  double step=(vmax-vmin)/(1.0*nint);
  res->SetTranslation(vmin+step/2.0,0,0);
  res->SetVoxelSize(step,1,1);

  numpts = new int[nint];
  for(n=0;n<=nint-1;n++) { 
    numpts[n]=0;
  } // endfor

  im->InitBuffer();
  do {
    v = im->ValeurBuffer();
    if ( v>=vmin && v<vmax ) {
      n = (int) ((v-vmin)/(vmax-vmin)*nint);
      if ( n==nint )  n=nint-1;
      numpts[n]++;
    } // end if
  } while (im->IncBuffer());

  res->InitBuffer();
  for(n=0;n<=nint-1;n++) { 
    res->FixeValeur(numpts[n]);
    res->IncBuffer();
  } // endfor

  delete [] numpts;
  return res;
} // Func_Histogram()

