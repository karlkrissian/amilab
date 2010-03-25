//
// C++ Implementation: wrap_ImTranslate
//
// Description: 
//
//
// Author: Karl Krissian <>, (C) 2009
//
// Copyright: See COPYING file that comes with this distribution
//
//

#include "wrap_ImTranslate.h"
#include "fonctions.h"
#include "wrapfunctions.hpp"

//----------------------------------------------
InrImage* wrap_ImTranslate(ParamList* p)
{
    char functionname[] = "ImTranslate";
    char description[]=" \n\
      Apply image translation based on a displacement given in pixels \n\
            ";
    char parameters[] =" \n\
          Parameters:\n\
              input image\n\
              displacement in x (def:0) \n\
              displacement in y (def:0) \n\
              displacement in z (def:0) \n\
              border mode (def:0): if 0 extension of border intensity, if 1 the resulting image is smaller and only contains the translated pixels that fit into the initial image domain. \n\
            ";

    InrImage* input = NULL;
    int dx=0;
    int dy=0;
    int dz=0;
    int border_mode = 0;
    int n=0;
    InrImage* result;

  if (!get_val_ptr_param<InrImage>( input,       p, n)) HelpAndReturnNULL;
  if (!get_int_param(   dx,          p, n)) HelpAndReturnNULL;
  if (!get_int_param(   dy,          p, n)) HelpAndReturnNULL;
  if (!get_int_param(   dz,          p, n)) HelpAndReturnNULL;
  if (!get_int_param(   border_mode, p, n)) HelpAndReturnNULL;

  // TODO: check that displacements are smaller that image dimensions !!
  
  switch (border_mode) {
    case 0:
      result = new InrImage( input->GetFormat(), "ImTranslate.ami.gz", input);
      break;
    case 1:
      result = new InrImage(  input->DimX()-abs(dx),
                              input->DimY()-abs(dy),
                              input->DimZ()-abs(dz),
                              input->GetVDim(),
                              input->GetFormat(),
                              "ImTranslate.ami.gz");
      result->SetVoxelSize( input->VoxSizeX(),
                            input->VoxSizeY(), 
                            input->VoxSizeZ());
      result->SetTranslation(
        input->TrX()+macro_max(dx,0)*input->VoxSizeX(),
        input->TrY()+macro_max(dy,0)*input->VoxSizeY(),
        input->TrZ()+macro_max(dz,0)*input->VoxSizeZ());
      break;
    default:
      FILE_ERROR("Wrong border mode");
      return NULL;
  }

  //(*result)=(*input);

  int x,y,z;
  // compute min-max position in X,Y,Z
  int xmin = macro_max(dx,0);
  int xmax = macro_min(input->DimX()-1+dx,input->DimX()-1);
  int ymin = macro_max(dy,0);
  int ymax = macro_min(input->DimY()-1+dy,input->DimY()-1);
  int zmin = macro_max(dz,0);
  int zmax = macro_min(input->DimZ()-1+dz,input->DimZ()-1);

  int incx,incy,incz;
  input->GetBufferIncrements(incx,incy,incz);

  int displ = dx*incx+dy*incy+dz*incz;
  //cout << "displ = " << displ << endl;

  if (input->ScalarFormat()) {
    //cout << "**" << endl;
    for(z=zmin;z<=zmax;z++)
    for(y=ymin;y<=ymax;y++) {
      if (border_mode==0) 
        result->BufferPos(xmin,y,z);
      else
        result->BufferPos(xmin - macro_max(0,dx),
                          y    - macro_max(0,dy),
                          z    - macro_max(0,dz));
      input->BufferPos(xmin-dx,y-dy,z-dz);
      for(x=xmin;x<=xmax;x++) {
        result->FixeValeur(input->ValeurBuffer());
        result->IncBuffer();
        input->IncBuffer();
      }
    }
  } else {
    for(z=zmin;z<=zmax;z++)
    for(y=ymin;y<=ymax;y++) {
      if (border_mode==0) 
        result->BufferPos(xmin,y,z);
      else
        result->BufferPos(xmin - macro_max(0,dx),
                          y    - macro_max(0,dy),
                          z    - macro_max(0,dz));
      input->BufferPos(xmin-dx,y-dy,z-dz);
      for(x=xmin;x<=xmax;x++) {
        for(int n=0;n<input->GetVDim();n++) {
          result->VectFixeValeur(n,input->VectValeurBuffer(n));
        }
        result->IncBuffer();
        input->IncBuffer();
      }
    }
  }

  // chek borders if needed
  if (border_mode==0) {
    //cout << "**" << endl;
    for(z=0;z<=result->DimZ()-1;z++)
    for(y=0;y<=result->DimY()-1;y++) 
    for(x=0;x<=result->DimX()-1;x++) {
      if (!input->CoordOK(x-dx,y-dy,z-dz)) {
        int x1 = x-dx;
        if (x1<0) x1=0;
        if (x1>input->DimX()-1) x1 = input->DimX()-1;
        int y1 = y-dy;
        if (y1<0) y1=0;
        if (y1>input->DimY()-1) y1 = input->DimY()-1;
        int z1 = z-dz;
        if (z1<0) z1=0;
        if (z1>input->DimZ()-1) z1 = input->DimZ()-1;
        input->BufferPos(x1,y1,z1);
        result->BufferPos(x,y,z);
        if (input->ScalarFormat()) {
          result->FixeValeur(input->ValeurBuffer());
        } else {
          for(int n=0;n<input->GetVDim();n++) {
            result->VectFixeValeur(n,input->VectValeurBuffer(n));
          }
        }
      }
    }
  }

  return result;

}
