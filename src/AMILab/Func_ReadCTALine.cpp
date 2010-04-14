//
// C++ Implementation: Func_ReadCTALine
//
// Description: 
//
//
// Author: Karl Krissian,,, <karl@UBUNTU-KARL>, (C) 2008
//
// Copyright: See COPYING file that comes with this distribution
//
//

#include "wx/wxprec.h"
#ifdef __BORLANDC__
#pragma hdrstop
#endif
#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

#include "Func_ReadCTALine.h"
#include "surface.hpp"
using namespace amilab;


//--------------------------------------------------------------
// mode 0: point + radius + sd
// mode 1: point
SurfacePoly* Func_ReadCTALine( std::string filename, int mode)
{

  FILE*   file;
  float x,y,z,r,sd;
  int n=0;
  int scanres;

  setlocale(LC_NUMERIC,"C");

  SurfacePoly* res = new SurfacePoly();

  // open filename
  file = fopen( (char*)filename.c_str(), "r");
  if (file == NULL) {
    fprintf(stderr," Error opening file %s \n", (char*) filename.c_str());
    return NULL;
  }

  res->NewLine();
  switch (mode) {
    case 0:
      while ((scanres=fscanf( file, "%f %f %f %f %f\n", &x, &y, &z, &r, &sd))>0) {
        //printf("scanres = %d (%f %f %f %f %f) \n",scanres,x,y,z,r,sd);
        //printf("point %d OK\n",n);
        res->AddPoint(x,y,z);
        res->LineAddPointNumber(n);
        n++;
      }
      break;
    case 1:
      while ((scanres=fscanf( file, "%f %f %f \n", &x, &y, &z))>0) {
        //printf("scanres = %d (%f %f %f %f %f) \n",scanres,x,y,z,r,sd);
        //printf("point %d OK\n",n);
        res->AddPoint(x,y,z);
        res->LineAddPointNumber(n);
        n++;
      }
      break;
  }
  //printf("scanres = %d (%f %f %f %f %f) \n",scanres,x,y,z,r,sd);
  res->EndLine();

  fclose(file);

  return res;

}


//--------------------------------------------------------------
InrImage* Func_ReadCTALineRadii(  SurfacePoly* line,
                                  std::string filename)
{

  FILE*   file;
  float x,y,z,r,sd;
  int n=0;
  int scanres;

  setlocale(LC_NUMERIC,"C");

  InrImage* res = new InrImage( line->GetNumberOfPoints(),
                                1,
                                1,
                                1,
                                WT_FLOAT);

  // open filename
  file = fopen( (char*)filename.c_str(), "r");
  if (file == NULL) {
    fprintf(stderr," Error opening file %s \n", (char*) filename.c_str());
    return NULL;
  }

  res->InitBuffer();
  while ((scanres=fscanf( file, "%f %f %f %f %f\n", &x, &y, &z, &r, &sd))>0) {
    res->FixeValeur(r);
    res->IncBuffer();
    n++;
  }

  fclose(file);

  return res;

} //Func_ReadCTALineRadii()


//--------------------------------------------------------------
void Func_WriteCTALine( SurfacePoly* surf, std::string filename)
{

  FILE*   file;

  setlocale(LC_NUMERIC,"C");

  if (surf->GetNumberOfLines()==0) {
    cerr << "Func_WriteCTALine()\t no line in polydata " << endl;
    return;
  }

  // open filename
  file = fopen( (char*)filename.c_str(), "w");
  if (file == NULL) {
    fprintf(stderr," Error opening file %s \n", (char*) filename.c_str());
    return;
  }

  T_Line l = surf->GetLine(0);
  
  //cout << l.NbElts() << endl;

  for(int n=0;n<l.NbElts();n++) {
    //cout << l[n] << endl;
    fprintf(  file,
              "%f %f %f \n",
              (*surf)[l[n]].pt.x,
              (*surf)[l[n]].pt.y,
              (*surf)[l[n]].pt.z
            );
  }

  fclose(file);

} // Func_WriteCTALine()

