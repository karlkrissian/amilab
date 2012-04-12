
#include "PruebaClass.h"
#include <iostream>

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

