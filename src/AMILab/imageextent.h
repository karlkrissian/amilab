//
// C++ Interface: imageextent
//
// Description: 
//
//
// Author:  Karl Krissian <>, (C) 2009
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _imageextent_h_
#define _imageextent_h_

class ImageExtent {

  float xmin,xmax,ymin,ymax,zmin,zmax;

  unsigned char mode; // 0: absolute, 1: relative

 public:
  ImageExtent() {
    xmin=xmax=ymin=ymax=zmin=zmax=0;
    mode = 0;
  }

  ImageExtent(int x1,int x2, int y1=0, int y2=0, int z1=0, int z2=0) {
    xmin=x1;
    xmax=x2;
    ymin=y1;
    ymax=y2;
    zmin=z1;
    zmax=z2;
  }

  ImageExtent(float x1,float x2, float y1=0, float y2=0, float z1=0, float z2=0) {
    xmin=x1;
    xmax=x2;
    ymin=y1;
    ymax=y2;
    zmin=z1;
    zmax=z2;
  }

  float Xmin() { return xmin;}
  float Xmax() { return xmax;}
  float Ymin() { return ymin;}
  float Ymax() { return ymax;}
  float Zmin() { return zmin;}
  float Zmax() { return zmax;}

  void SetXmin(float val) {xmin=val;}
  void SetXmax(float val) {xmax=val;}
  void SetYmin(float val) {ymin=val;}
  void SetYmax(float val) {ymax=val;}
  void SetZmin(float val) {zmin=val;}
  void SetZmax(float val) {zmax=val;}

  unsigned char GetMode() {return mode;}
  void SetMode(unsigned char val) {mode = val;}

  void SetRelative( InrImage* im) {
    if (this->GetMode()==0) {
      xmin =  (int) (im->SpaceToVoxelX(xmin)+0.5);
      xmax =  (int) (im->SpaceToVoxelX(xmax)+0.5);
      ymin =  (int) (im->SpaceToVoxelY(ymin)+0.5);
      ymax =  (int) (im->SpaceToVoxelY(ymax)+0.5);
      zmin =  (int) (im->SpaceToVoxelZ(zmin)+0.5);
      zmax =  (int) (im->SpaceToVoxelZ(zmax)+0.5);

      if (xmin<0) xmin=0;
      if (ymin<0) ymin=0;
      if (zmin<0) zmin=0;
      if (xmax>im->DimX()-1) xmax=im->DimX()-1;
      if (ymax>im->DimY()-1) ymax=im->DimY()-1;
      if (zmax>im->DimZ()-1) zmax=im->DimZ()-1;
      if (xmax<xmin) xmax=xmin;
      if (ymax<ymin) ymax=ymin;
      if (zmax<zmin) zmax=zmin;

      if (GB_debug)
        printf("SetRelative (%02.2f->%02.2f, %02.2f->%02.2f, %02.2f->%02.2f) \n",xmin,xmax,ymin,ymax,zmin,zmax);

     mode = 1; // relative mode
    }
  }

  void print() {
    printf("extent [%3.3f:%3.3f] [%3.3f:%3.3f] [%3.3f:%3.3f] \n",xmin,xmax,ymin,ymax,zmin,zmax);
  }
};

#endif // _imageextent_h_
