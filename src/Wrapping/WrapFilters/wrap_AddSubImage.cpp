//
// C++ Implementation: wrap_AddSubImage
//
// Description: 
//
//
// Author: Karl Krissian <>, (C) 2009
//
// Copyright: See COPYING file that comes with this distribution
//
//

#include <iomanip>
#include <cassert>
#include "boost/format.hpp"

#include "wrap_AddSubImage.h"
#include "fonctions.h"
#include "wrapfunctions.hpp"

//----------------------------------------------
void wrap_AddSubImage(ParamList* p)
{
    char functionname[] = "AddSubImage";
    char description[]=" \n\
      Add an image to another one, at a give pixel/voxel position, the filter modifies directly the input image. \n\
            ";
    char parameters[] =" \n\
          Parameters:\n\
              input image\n\
              input subimage\n\
              pos x (def:0) position in X in pixel coordinates (positive integer)\n\
              pos y (def:0) position in Y in pixel coordinates (positive integer)\n\
              pos z (def:0) position in Z in pixel coordinates (positive integer)\n\
            ";

    InrImage* input;
    InrImage* subimage;
    float posx=0;
    float posy=0;
    float posz=0;
    int n=0;

  if (!get_val_ptr_param<InrImage>( input,       p, n)) HelpAndReturn;
  if (!get_val_ptr_param<InrImage>( subimage,    p, n)) HelpAndReturn;
  if (!get_val_param<float>(   posx,        p, n)) HelpAndReturn;
  if (!get_val_param<float>(   posy,        p, n)) HelpAndReturn;
  if (!get_val_param<float>(   posz,        p, n)) HelpAndReturn;

  if ((posx<0)||(posy<0)||(posz<0)) {
    FILE_ERROR((boost::format("Wrong parameters: negative coordinate (%1%,%2%,%3%)") % posx % posy % posz ).str().c_str());
    HelpAndReturn;
  }
  if ((posx>=input->DimX())||
      (posy>=input->DimY())||
      (posz>=input->DimZ())) {
    FILE_ERROR((boost::format("Wrong parameters: out of range coordinate (%1%,%2%,%3%)")% posx % posy % posz).str().c_str());
    HelpAndReturn;
  }

  int x,y,z;
  // compute min-max position in X,Y,Z
  int xmin = posx;
  int xmax = macro_min(posx + subimage->DimX()-1,input->DimX()-1);
  int ymin = posy;
  int ymax = macro_min(posy + subimage->DimY()-1,input->DimY()-1);
  int zmin = posz;
  int zmax = macro_min(posz + subimage->DimZ()-1,input->DimZ()-1);


  if (input->ScalarFormat()) {
    //cout << "**" << std::endl;
    for(z=zmin;z<=zmax;z++)
    for(y=ymin;y<=ymax;y++) {
      input   ->BufferPos(xmin,y,z);
      subimage->BufferPos(0,y-posy,z-posz);
      for(x=xmin;x<=xmax;x++) {
        input->FixeValeur(input->ValeurBuffer()+subimage->ValeurBuffer());
        input   ->IncScalarBufferFast();
        subimage->IncScalarBufferFast();
      }
    }
  } else {
    for(z=zmin;z<=zmax;z++)
    for(y=ymin;y<=ymax;y++) {
      input   ->BufferPos(xmin,y,z);
      subimage->BufferPos(0,y-posy,z-posz);
      for(x=xmin;x<=xmax;x++) {
        for(int n=0;n<input->GetVDim();n++) {
          input->VectFixeValeur(n,
            input->VectValeurBuffer(n)+
            subimage->VectValeurBuffer(n));
        }
        subimage->IncBuffer();
        input   ->IncBuffer();
      }
    }
  }

}
