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

#ifndef _VOLUME_RENDER_H_
#define _VOLUME_RENDER_H_

#define MAP_RGBA_RGBA 1
#define MAP_I_RGBA    2


#include "DessinImageBase.hpp"
#include "GLparam.hpp"


// 1st basic Volume Rendering:
// Set the clipping planes []
// and try to make it work [-1,1] instead of [-100,100]
// rotate, ... object
// Check to free the space of the texture !!!

#define VOLREN_RGBA 0
#define VOLREN_IA   1
#define VOLREN_I    2



enum {OVER, ATTENUATE, NONE, LASTOP};
enum {X, Y, Z, W};
//enum {R, G, B, A};


//==================================================
class ModelLimits {
//    ============
 public:
  float xmin,xmax,ymin,ymax,zmin,zmax;
  float xsize,ysize,zsize;

  ModelLimits()
  {
    xmin=ymin=zmin=-1;
    xmax=ymax=zmax=1;
    UpdateSizes();
  }

  void SetLimits(InrImage* im)
  {
    xmin=im->SpacePosX(0);
    xmax=im->SpacePosX(im->DimX()-1);
    ymin=im->SpacePosY(0);
    ymax=im->SpacePosY(im->DimY()-1);
    zmin=im->SpacePosZ(0);
    zmax=im->SpacePosZ(im->DimZ()-1);
  }

  void UpdateSizes()
  {
      xsize=xmax-xmin;
      ysize=ymax-ymin;
      zsize=zmax-zmin;
  }

};


//int isExtensionSupported(const char *extension);


//==================================================
class VolumeRender {
//    ============


  InrImage* _im;
  float     _minI,_maxI;
  DessinImageBase* _di;
  InrImage* _opacity_image;

  int      _size_x, _size_y,_size_z;
  int      _planes;
  GLubyte* _tex3ddata;

  int _operator;
  int _texture;
  int _power2dim;

  int _using_palette;

  GLTransfMatrix* _Tobject;
  GLTransfMatrix* _Ttexture;
  GLTransfMatrix  _SRT;
  GLTransfMatrix  _VOL;

  ModelLimits _ml;

  GLenum _tex_internal_format;
  GLenum _tex_format;
  GLenum _tex_type;

  int    _level_of_detail;
  GLuint _tex_name;
  GLint  _texture_interpolation;

public:
  VolumeRender(InrImage* im);

  ~VolumeRender()
  {
    if (_tex3ddata!=NULL) {
      free(_tex3ddata);
      _tex3ddata = NULL;
    }
  }
  

  void SetDessinImage(DessinImageBase* di)
  {
    printf("VolumeRenderer::SetDessinImage() \n");
    _di = di;
  }

  void SetOpacityImage(InrImage* op)
  {
    _opacity_image = op;
  }

  void SetTexture( int val)
  {
    _texture = val;
  }


  void SetPower2Dim( int val)
  {
    _power2dim = val;
  }

  void SetObjectTransform( GLTransfMatrix* tobject)
  {
    _Tobject  = tobject;
  }

  void SetTextureTransform( GLTransfMatrix* tobject)
  {
    _Ttexture  = tobject;
  }


  void SetPlanes( int planes)
  {
    _planes=planes;
  }

  void SetMinMax(float minI, float maxI)
  {
    _minI = minI;
    _maxI = maxI;
  }

  void MapTexture();
  void Load3DTexture();
  void InitRender();

  void Render(unsigned char map=0);
};



#endif // _VOLUME_RENDER_H_
