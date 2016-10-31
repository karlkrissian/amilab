
#include "PruebaClass.h"
#include <iostream>
#include <vector>
#include <algorithm>

InrImage::ptr PruebaClass::Suma(InrImage::ptr i1, InrImage::ptr i2)
{
  std::cout << "suma start" << std::endl;
  bool check;
  check = (i1->DimX()   == i2->DimX())&&
	  (i1->DimY()   == i2->DimY())&&
	  (i1->DimZ()   == i2->DimZ())&&
	  (i1->GetVDim()== i2->GetVDim())
	  ;
  if (!check)  return InrImage::ptr();

  std::cout << "suma start" << std::endl;
  InrImage::ptr res;
  res = InrImage::ptr(new InrImage(i1->GetFormat(),"suma.ami.gz",i1.get()));
  res->InitBuffer();
  i1 ->InitBuffer();
  i2 ->InitBuffer();
  do {
    for(int n=0;n<i1->GetVDim();n++)
      res->VectFixeValeur(n,i1->VectValeurBuffer(n)+i2->VectValeurBuffer(n));
    i1->IncBuffer();
    i2->IncBuffer();
  } while (res->IncBuffer());
  return res;
}


//------------------------------------------------------------------------------
InrImage::ptr PruebaClass::MediaLocal3x3(InrImage::ptr im)
{
  InrImage::ptr res;
  res = InrImage::ptr(new InrImage(im->GetFormat(),"medialocal3x3.ami.gz",im.get()));
  int x,y;
  int i,j;
  int count;
  double media;

  res->InitBuffer();
  for(y=0;y<im->DimY();y++)
  for(x=0;x<im->DimX();x++)
  {
    for(int n=0;n<im->GetVDim();n++)
    {
      media=0;
      count=0;
      for(i=-1;i<=1;i++)
      for(j=-1;j<=1;j++) {
        if ((x+i>=0)&&(x+i<im->DimX())&&(y+j>=0)&&(y+j<im->DimY())) {
          media += (*im)(x+i,y+j,0,n);
          count++;
        }
      }
      media /= count;
      res->VectFixeValeur(n,media);
    }
    res->IncBuffer();
  }
  return res;
}

//------------------------------------------------------------------------------
InrImage::ptr PruebaClass::MedianaLocal(InrImage::ptr im, int n)
{
  InrImage::ptr res;
  res = InrImage::ptr(new InrImage(im->GetFormat(),"medianalocal.ami.gz",im.get()));
  int x,y;
  int i,j;
  std::vector<double> values;
  
  res->InitBuffer();
  for(y=0;y<im->DimY();y++)
  for(x=0;x<im->DimX();x++)
  {
    for(int n=0;n<im->GetVDim();n++)
    {
      for(i=-n;i<=n;i++)
      for(j=-n;j<=n;j++) {
        if ((x+i>=0)&&(x+i<im->DimX())&&(y+j>=0)&&(y+j<im->DimY())) {
          values.push_back((*im)(x+i,y+j,0,n));
        }
      }
      std::sort(values.begin(), values.end());
      res->VectFixeValeur(n,values[(int)(values.size()/2)]);
    }
    res->IncBuffer();
  }

  return res;
}

//------------------------------------------------------------------------------
void PruebaClass::GetArray(double a[3])
{
  a[0] = 1.0;
  a[1] = sqrt(2);
  a[2] = sqrt(3);
}
