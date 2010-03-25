//
// C++ Implementation: wrap_MaxSubImage
//
// Description: 
//
//
// Author: Karl Krissian <>, (C) 2009
//
// Copyright: See COPYING file that comes with this distribution
//
//

#include "wrap_MaxSubImage.h"
#include "fonctions.h"
#include "wrapfunctions.hpp"

//----------------------------------------------
void wrap_MaxSubImage(ParamList* p)
{
    char functionname[] = "MaxSubImage";
    char description[]=" \n\
      Point to point maximum between an input image and a subimage, at a given pixel/voxel position, the filter modifies directly the input image.\n\
            ";
    char parameters[] =" \n\
          Parameters:\n\
              input image:    Needs to be scalar\n\
              input subimage: Needs to be scalar\n\
              pos x (def:0) position in X in pixel coordinates (positive integer)\n\
              pos y (def:0) position in Y in pixel coordinates (positive integer)\n\
              pos z (def:0) position in Z in pixel coordinates (positive integer)\n\
            ";

    InrImage* input;
    InrImage* subimage;
    int posx=0;
    int posy=0;
    int posz=0;
    int n=0;

  if (!get_val_ptr_param<InrImage>( input,       p, n)) HelpAndReturn;
  if (!get_val_ptr_param<InrImage>( subimage,    p, n)) HelpAndReturn;
  if (!get_int_param(   posx,        p, n)) HelpAndReturn;
  if (!get_int_param(   posy,        p, n)) HelpAndReturn;
  if (!get_int_param(   posz,        p, n)) HelpAndReturn;

  if ((posx<0)||(posy<0)||(posz<0)) HelpAndReturn;
  if ((posx>=input->DimX())||
      (posy>=input->DimY())||
      (posz>=input->DimZ())) HelpAndReturn;

  int x,y,z;
  // compute min-max position in X,Y,Z
  int xmin = posx;
  int xmax = macro_min(posx + subimage->DimX()-1,input->DimX()-1);
  int ymin = posy;
  int ymax = macro_min(posy + subimage->DimY()-1,input->DimY()-1);
  int zmin = posz;
  int zmax = macro_min(posz + subimage->DimZ()-1,input->DimZ()-1);


  if (input->ScalarFormat()&&subimage->ScalarFormat()) {
    //cout << "**" << endl;
    for(z=zmin;z<=zmax;z++)
    for(y=ymin;y<=ymax;y++) {
      input   ->BufferPos(xmin,y,z);
      subimage->BufferPos(0,y-posy,z-posz);
      for(x=xmin;x<=xmax;x++) {
        input->FixeValeur(macro_max(input->ValeurBuffer(),subimage->ValeurBuffer()));
        input   ->IncScalarBufferFast();
        subimage->IncScalarBufferFast();
      }
    }
  } else {
    HelpAndReturn;
  }

}
