/*
    ==================================================
    Software : AMILab
    Authors  : Karl Krissian
    Email    : karl@ctm.ulpgc.es

    OSRAD is a noise reducing filter program
    ==================================================
    Copyright (C) 2008  Karl Krissian

    OSRAD is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    OSRAD is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

    ================================================== 
   The full GNU Lesser General Public License file is in LesserGPL_license.txt
*/

#include "func_imagebasictools.h"

#ifndef macro_min
  #define macro_min(n1,n2) ((n1)<(n2)?(n1):(n2))
#endif

#ifndef macro_max
  #define macro_max(n1,n2) ((n1)>(n2)?(n1):(n2))
#endif 

extern unsigned char GB_debug;

InrImage* Func_AutoCrop( InrImage* im, int margin) 
{

  int xmin,xmax,ymin,ymax,zmin,zmax;
  int x,y,z;

  xmin = im->DimX()-1;
  ymin = im->DimY()-1;
  zmin = im->DimZ()-1;
  xmax = ymax = zmax = 0;

  InrImageIteratorBase::ptr im_it( im->CreateConstIterator());

  im_it->InitBuffer();
  Pour(z,0,im->DimZ()-1)
  Pour(y,0,im->DimY()-1)
  Pour(x,0,im->DimX()-1)
    if (im_it->GetDoubleValue()>0) {
      xmin = macro_min(xmin,x);
      ymin = macro_min(ymin,y);
      zmin = macro_min(zmin,z);
      xmax = macro_max(xmax,x);
      ymax = macro_max(ymax,y);
      zmax = macro_max(zmax,z);
    }
    ++(*im_it);
  FinPour
  FinPour
  FinPour

  xmin = macro_max(0,xmin-margin);
  ymin = macro_max(0,ymin-margin);
  zmin = macro_max(0,zmin-margin);

  xmax = macro_min(im->DimX()-1,xmax+margin);
  ymax = macro_min(im->DimY()-1,ymax+margin);
  zmax = macro_min(im->DimZ()-1,zmax+margin);

  return Func_SubImage(im,xmin,ymin,zmin,xmax,ymax,zmax);

} // Func_AutoCrop


InrImage* Func_SubImage( InrImage* im, 
			 int x1, int y1, int z1,
			 int x2, int y2, int z2)
{

  
    InrImage* subim;
    char imname[255];
    int x,y,z;
    float tx,ty,tz;

  if (GB_debug)
    printf("SubImage [ %d --> %d , %d -->  %d , %d --> %d ] \n",x1,x2,y1,y2,z1,z2);

  im->GetTranslation(tx,ty,tz);
  //  x1-=tx;
  //  x2-=tx;
  //  y1-=ty;
  //  y2-=ty;
  //  z1-=tz;
  //  z2-=tz;

  Si Non(im->CoordOK(x1,y1,z1)) Alors
    fprintf(stderr,"Func_SubImage() \t bad coordinates for the first corner \n");
    fprintf(stderr,"Func_SubImage() \t %d %d %d \n",x1,y1,z1);
    fprintf(stderr,"Func_SubImage() \t dim = %d x %d x %d \n",im->DimX(),im->DimY(),im->DimZ());
    x1 = macro_min(macro_max(x1,0),im->_tx-1);
    y1 = macro_min(macro_max(y1,0),im->_ty-1);
    z1 = macro_min(macro_max(z1,0),im->_tz-1);
    fprintf(stderr,"Func_SubImage() \t new value : %d %d %d \n",x1,y1,z1);
  FinSi

  Si Non(im->CoordOK(x2,y2,z2)) Alors
    fprintf(stderr,"Func_SubImage() \t bad coordinates for the second corner \n");
    x2 = macro_min(macro_max(x2,0),im->_tx-1);
    y2 = macro_min(macro_max(y2,0),im->_ty-1);
    z2 = macro_min(macro_max(z2,0),im->_tz-1);
  FinSi

  Si x2<x1 AlorsFait x2=x1;
  Si y2<y1 AlorsFait y2=y1;
  Si z2<z1 AlorsFait z2=z1;

  sprintf(imname,"sub-%s",im->GetName());
  subim = new InrImage(x2-x1+1,
		       y2-y1+1,
		       z2-z1+1,
           im->GetVDim(),
		       im->_format,
		       imname);

  subim->SetTranslation( tx+x1*im->VoxSizeX(),
			 ty+y1*im->VoxSizeY(),
			 tz+z1*im->VoxSizeZ());

  subim->SetVoxelSize(im->_size_x, im->_size_y, im->_size_z);
  // preserve endianness
  ((amimage*)(*subim))->SetEndianness(((amimage*)(*im))->GetEndianness());

  subim->InitBuffer();
  Pour(z,z1,z2)
  Pour(y,y1,y2)
    im->BufferPos(x1,y,z);
    Pour(x,x1,x2)

      if (im->ScalarFormat())
          subim->FixeValeur(im->ValeurBuffer());


      if (im->VectorialFormat())
        for(int i=0;i<im->GetVDim();i++)
           subim->VectFixeValeur(i,im->VectValeurBuffer(i));
      im->IncBuffer();
      subim->IncBuffer();
    FinPour
  FinPour
  FinPour

  return subim;

}


void Func_PutImage( InrImage* i1, 
		    InrImage* i2,
		    int x1, int y1, int z1)
{

  
    int x,y,z;

  if (i1->GetVDim()!=i2->GetVDim()) {
    cerr << "Func_PutImage() image of different vectorial dimensions " << endl;
    return;
  }

  Si x1<0 AlorsFait x1=0;
  Si y1<0 AlorsFait y1=0;
  Si z1<0 AlorsFait z1=0;
  Si x1>=i1->_tx-1 AlorsFait x1=i1->_tx-1;
  Si y1>=i1->_ty-1 AlorsFait y1=i1->_ty-1;
  Si z1>=i1->_tz-1 AlorsFait z1=i1->_tz-1;

  i2->InitBuffer();
  Pour(z,0,i2->_tz-1)
  Pour(y,0,i2->_ty-1)
    Si i1->CoordOK(x1,y1+y,z1+z) AlorsFait
      i1->BufferPos(x1,y1+y,z1+z);
    Pour(x,0,i2->_tx-1)

      if (i1->ScalarFormat())
          i1->FixeValeur(i2->ValeurBuffer());
      else
      	  for(int i=0;i<i1->GetVDim();i++)
            i1->VectFixeValeur(i,i2->VectValeurBuffer(i));

      i1->IncBuffer();
      i2->IncBuffer();
    FinPour
  FinPour
  FinPour

}
