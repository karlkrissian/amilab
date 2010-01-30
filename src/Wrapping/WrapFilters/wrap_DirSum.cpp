//
// C++ Implementation: wrap_DirSum
//
// Description: 
//
//
// Author: Karl Krissian <>, (C) 2009
//
// Copyright: See COPYING file that comes with this distribution
//
//

#include "wrap_DirSum.h"

InrImage* wrap_DirSum(ParamList* p)
{
    char functionname[] = "DirSum";
    char description[]=" \n\
        Sum image intensity along one dimension, return a new image of format double and dimension 1 along the selected axis.\n\
            ";
    char parameters[] =" \n\
        input image\n\
        orientation: 0 for X, 1 for Y, 2 for Z \n\
            ";

  int dir;
  int x,y,z;
  InrImage* input;
  InrImage* result = NULL;
  int n=0;

  if (!get_var_param<InrImage>(  input, p, n)) HelpAndReturnNULL;
  if (!get_int_param(    dir,   p, n)) HelpAndReturnNULL;

  switch (dir) {
    // sum over X
    case 0:
      result = new InrImage(1,input->DimY(),input->DimZ(),WT_DOUBLE,"SumX.ami.gz");
      for(z=0;z<=input->DimZ()-1;z++)
      for(y=0;y<=input->DimY()-1;y++) {
        double sum=0;
        // TODO: use IncBuffer, ValeurBuffer ...
        for(x=0;x<=input->DimX()-1;x++)
          sum +=(*input)(x,y,z);
        //cout << boost::format(" ( %1%, %2%, %3%) sum=%4%")%x%y%z%sum << endl;
        result->BufferPos(0,y,z);
        result->FixeValeur(sum);
      }
    break;
    // sum over Y
    case 1:
      result = new InrImage(input->DimX(),1,input->DimZ(),WT_DOUBLE,"SumY.ami.gz");
      for(z=0;z<=input->DimZ()-1;z++)
      for(x=0;x<=input->DimX()-1;x++) {
        double sum=0;
        // TODO: use IncBuffer, ValeurBuffer ...
        for(y=0;y<=input->DimY()-1;y++)
          sum +=(*input)(x,y,z);
        result->BufferPos(x,0,z);
        result->FixeValeur(sum);
      }
    break;
    // sum over Z
    case 2:
      result = new InrImage(input->DimX(),input->DimY(),1,WT_DOUBLE,"SumZ.ami.gz");
      for(y=0;y<=input->DimY()-1;y++)
      for(x=0;x<=input->DimX()-1;x++) {
        double sum=0;
        // TODO: use IncBuffer, ValeurBuffer ...
        for(z=0;z<=input->DimZ()-1;z++)
          sum +=(*input)(x,y,z);
        result->BufferPos(x,y,0);
        result->FixeValeur(sum);
      }
    break;
    default:
      cerr << "DirSum() Invalid argument" << endl;
  }

  return result;

}
