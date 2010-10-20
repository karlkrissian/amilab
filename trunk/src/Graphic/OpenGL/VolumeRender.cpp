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
//
// Volume Rendering Class based on an example of OpenGL 3D texture mappingvrct
//
//

#ifdef WIN32
  #include <wx/glcanvas.h>
#endif

extern "C" {
#include <GL/gl.h>
#include <GL/glext.h>

 #ifndef __APPLE__
// Compilation pb: I had to add the declaration here: why ???
// to do: fix compatibility problems
extern void glTexImage3DEXT(GLenum, GLint, GLenum, GLsizei, GLsizei, GLsizei, GLint, GLenum, GLenum, const GLvoid *);
#endif // __APPLE__
}

#include <GL/glu.h>
//#include <GL/glut.h>

#include <stdio.h>

#include "VolumeRender.hpp"

#include "amilab_messages.h"


#define TEXIMAGE_INTFORMAT GL_LUMINANCE_ALPHA
//#define TEXIMAGE_INTFORMAT GL_RGBA

#define CHECK_ERROR(str)                                           \
{                                                                  \
    GLenum error;                                                  \
    if(error = glGetError())                                       \
       printf("GL Error: %s (%s)\n", gluErrorString(error), str);  \
}

/* nonzero if not power of 2 */ 
#define NOTPOW2(num) ((num) & (num - 1))

int
makepow2(int val)
{
    int power = 0;
    if(!val)
	return 0;

    while(val >>= 1)
	power++;

    return(1 << power);
}

#define S 0
#define T 1
#define R 2


//-----------------------------------------------------
//Name: isExtensionSupported
//Description: Check if a specific extension is supported
//-----------------------------------------------------
int isExtensionSupported(const char *extension)
{
  const GLubyte *extensions = NULL;
  const GLubyte *start;
  GLubyte *where, *terminator;

  // Extension names should not have spaces. 
  where = (GLubyte *) strchr(extension, ' ');
  if (where || *extension == '\0')
    return 0;
  extensions = glGetString(GL_EXTENSIONS);
  start = extensions;
  for (;;) {
    where = (GLubyte *) strstr((const char *) start, extension);
    if (!where)
      break;
    terminator = where + strlen(extension);
    if (where == start || *(where - 1) == ' ')
      if (*terminator == ' ' || *terminator == '\0')
        return 1;
    start = terminator;
  }
  return 0;
}

//we rather use an own function instead of strstr(..) because
//this might be dangerous if two extensions begin with the same text
bool checkExtension( const char* checkFor)
{
   char *extensions  = (char*)glGetString(GL_EXTENSIONS);
   char *endOfStr;  

   if (!extensions) return false;
   int idx = 0;
   endOfStr = (char*)checkFor + strlen(checkFor);

   while (checkFor < endOfStr)
   {
      idx = strcspn(checkFor, " ");

      if ( ((int)strlen(extensions) == idx) &&
           (strncmp(extensions, checkFor, idx) == 0))
         return true;

      checkFor += (idx + 1);
   }

   return false;
}


VolumeRender::VolumeRender(InrImage* im)
{
    float xmin,xmax,ymin,ymax,zmin,zmax;

    _im = im;
    _size_x = _size_y = _size_z = 0;
    _tex3ddata = NULL;
    _operator = OVER;
    _texture   = GL_TRUE;
    _power2dim = GL_TRUE;
    _Tobject = NULL;
    _Ttexture = NULL;
    _di = NULL;
    _texture_interpolation = GL_NEAREST;

    // Check if using palette ...
//    _using_palette = isExtensionSupported("GL_EXT_paletted_texture");
    _using_palette = checkExtension("GL_EXT_paletted_texture");
    printf("Using palette = %d \n",_using_palette);

    _tex_internal_format = GL_RGBA;
    // try GL_INTENSITY_EXT or GL_COLOR_INDEX8_EXT

    _tex_type            = GL_UNSIGNED_BYTE;
    _tex_format          = GL_RGBA;
    _tex_name            = 0;

    _level_of_detail = 0;
    //    _ml.SetLimits(im);

    // Set the transformation to volume coordinates from the geometry (SRT)
    xmin=im->SpacePosX(0);
    xmax=im->SpacePosX(im->DimX()-1);
    ymin=im->SpacePosY(0);
    ymax=im->SpacePosY(im->DimY()-1);
    zmin=im->SpacePosZ(0);
    zmax=im->SpacePosZ(im->DimZ()-1);


    _VOL.SetIdentity();
    // try to set voxel size
    _VOL.SetScale(im->VoxSizeX(),im->VoxSizeY(),im->VoxSizeZ());
/*
    _VOL.SetScale((xmax-xmin)/_ml.xsize,
      (ymax-ymin)/_ml.ysize,
      (zmax-zmin)/_ml.zsize);
    _VOL.SetTranslation(-_ml.xmin,-_ml.ymin,-_ml.zmin);
*/
    _planes = im->DimY();

}


//----------------------------------------------------------------------
void VolumeRender::InitRender()
{

  // Texture coordinates: TO ADAPT: use image voxel size...
  // Map from the coordinates of the geometry and the one of the texture map

  GLfloat plane[3][4];// = {1.f/_ml.xsize, 0.f, 0.f, .5f};
  /*
  GLfloat rplane[4];// = {0, 1.f/_ml.ysize, 0, .5f};
  GLfloat tplane[4];// = {0, 0, 1.f/_ml.zsize, .5f};
  */
  int i,j;


  // Set the SRT matrix
  _SRT.SetIdentity();
  _SRT.SetTranslation(_ml.xsize/2.f,_ml.ysize/2.f,_ml.zsize/2.f);
  
  // pb with the scale matrix ...
  _SRT.SetScale(1.f/_ml.xsize,1.f/_ml.ysize,1.f/_ml.zsize);
  
  _SRT.GLGetMatrix();
  _SRT.Print();
  
  for (i=0;i<=2;i++) {
    for (j=0;j<=3;j++) {
      plane[i][j] = _SRT._matrix[j][i];
      printf("%3.3f \t",plane[i][j]);
    }
    printf("\n");
  }
  //  printf("%f %f %f %f \n",splane[0],splane[1],splane[2],splane[3]);
  //  printf("%f %f %f %f \n",rplane[0],rplane[1],rplane[2],rplane[3]);
  //  printf("%f %f %f %f \n",tplane[0],tplane[1],tplane[2],tplane[3]);

  // Load and Convert the 3D texture
  this->Load3DTexture();
  
  if (glIsTexture(_tex_name)==GL_TRUE)
    glDeleteTextures(1,&_tex_name);

  glGenTextures(1,&_tex_name);
  glBindTexture(GL_TEXTURE_3D,_tex_name);


  glEnable(GL_DEPTH_TEST);
  glEnable(GL_TEXTURE_3D);
  
  glEnable(GL_TEXTURE_GEN_S);
  glEnable(GL_TEXTURE_GEN_T);
  glEnable(GL_TEXTURE_GEN_R);
  
  glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
  glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
  glTexGeni(GL_R, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
  
  glTexGenfv(GL_S, GL_OBJECT_PLANE, plane[S]);
  glTexGenfv(GL_T, GL_OBJECT_PLANE, plane[T]);
  glTexGenfv(GL_R, GL_OBJECT_PLANE, plane[R]);
  
  /* to avoid boundary problems */
  glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
  glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
  glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
  
  // SetClipPlanes ...
//  glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_MIN_FILTER, _texture_interpolation);

  //  if (wglGetProcAddress(glTexImage3DEXT)!=NULL) {


  //  LookupFunction("glBindTexture");
  #ifndef WIN32
    #if (defined(GL_EXT_texture3D))&&(!defined(__APPLE__))
            glTexImage3DEXT(GL_TEXTURE_3D,
    #else 
            glTexImage3D(GL_TEXTURE_3D,
    #endif
  #else
    PFNGLTEXIMAGE3DPROC glTexImage3D;
    glTexImage3D = (PFNGLTEXIMAGE3DPROC) wglGetProcAddress("glTexImage3D");
	if (!glTexImage3D) { 
      CLASS_ERROR("glTexImage3D not found ...")
	  return;
	}
    glTexImage3D(GL_TEXTURE_3D,
  #endif
      _level_of_detail, 
      _tex_internal_format,
      _size_x, _size_y, _size_z,
      0,
      _tex_format, _tex_type, _tex3ddata);
  //  }
  //  else   {
  //    const GLubyte *extensions = NULL;
  //    extensions = glGetString(GL_EXTENSIONS);
  //    printf("OpenGL Extensions: %s \n",extensions);
  //  }

  this->MapTexture();

} 


//----------------------------------------------------------------------
//
// use pixel path to remap 3D texture data 
//
void VolumeRender::MapTexture()
//   ------------
{
    int      i, size;
    GLfloat  *map = NULL;


    glPixelTransferi(GL_MAP_COLOR, GL_TRUE);

    switch (_tex_format) {
    case GL_RGBA:
      glGetIntegerv(GL_MAX_PIXEL_MAP_TABLE, &size);
      
      printf("MapTexture, size = %d\n",size);
      
      map = (GLfloat *)malloc(sizeof(GLfloat) * size);
      for(i = 0; i < size;i++)
	{
	  map[i] = (GLfloat) i/(size - 1);
	  if ((i%(size/10))==0) printf("map[%d]=%f\n",i,map[i]);
	  
	  /*
	    if(((GLfloat)i/size > minboost) &&
	    ((GLfloat)i/size < minboost + boostwid))
	    {
	    map[i] *= boost;
	    }
	    else
	    map[i] /= boost;
	  */
	}
      glPixelMapfv(GL_PIXEL_MAP_R_TO_R, size, map);
      glPixelMapfv(GL_PIXEL_MAP_G_TO_G, size, map);
      glPixelMapfv(GL_PIXEL_MAP_B_TO_B, size, map);
      glPixelMapfv(GL_PIXEL_MAP_A_TO_A, size, map);


/*      glTexImage3D(GL_TEXTURE_3D, 
		   _level_of_detail, 
		   _tex_internal_format,
		   _size_x, _size_y, _size_z,
		   0,
		   _tex_format, _tex_type, _tex3ddata);
*/
//  if (wglGetProcAddress(glTexImage3DEXT)!=NULL) {
  #ifndef WIN32
    #if (defined(GL_EXT_texture3D))&&(!defined(__APPLE__))
        glTexImage3DEXT(GL_TEXTURE_3D_EXT,
    #else 
        glTexImage3D(GL_TEXTURE_3D,
    #endif
  #else
    PFNGLTEXIMAGE3DPROC glTexImage3D;
    glTexImage3D = (PFNGLTEXIMAGE3DPROC) wglGetProcAddress("glTexImage3D");
	if (!glTexImage3D) { 
      CLASS_ERROR("glTexImage3D not found ...")
	  return;
	}
    glTexImage3D(GL_TEXTURE_3D,
  #endif
            _level_of_detail, 
            _tex_internal_format,
            _size_x, _size_y, _size_z,
            0,
            _tex_format, _tex_type, _tex3ddata);
      
      glPixelTransferi(GL_MAP_COLOR, GL_FALSE);
      break;
      /*
    case GL_:
      size=256;
      map = (GLfloat *)malloc(sizeof(GLfloat) * size);
      for(i = 0; i < size;i++)
	  map[i] = (GLfloat) i/(size - 1);
      glPixelMapfv(GL_PIXEL_MAP_I_TO_R, 8, map);
      glPixelMapfv(GL_PIXEL_MAP_I_TO_G, 8, map);
      glPixelMapfv(GL_PIXEL_MAP_I_TO_B, 8, map);
      glPixelMapfv(GL_PIXEL_MAP_I_TO_A, 8, map);
      glTexImage3D(GL_TEXTURE_3D, 
		   _level_of_detail, 
		   TEXIMAGE_INTFORMAT,
		   _size_x, _size_y, _size_z,
		   0,
		   GL_COLOR_INDEX, GL_UNSIGNED_BYTE, _tex3ddata);
      
      glPixelTransferi(GL_MAP_COLOR, GL_false);
      break;
      */
    }

    free(map);

    //    CHECK_ERROR("OpenGL Error in remaptex()");
}


//----------------------------------------------------------------------
void VolumeRender::Load3DTexture()
//                    -------------
{
    GLint max3dtexdims; /* maximum allowed 3d texture dimension */
    GLint newval;
    int i;
    float val;
    int size=1;
    unsigned char red,green,blue,intensity;

    _size_x = _im->DimX();
    _size_y = _im->DimY();
    _size_z = _im->DimZ();

    /* load 3D texture data */
    switch (_tex_format) {
    case GL_RGBA:
        size=_size_x*_size_y*_size_z*4;
        break;
    case GL_LUMINANCE:
        size = _size_x*_size_y*_size_z;
        break;
    }

    if (_tex3ddata!=NULL)  free(_tex3ddata);

    _tex3ddata = (GLubyte *)malloc( size * sizeof(GLubyte));


    printf("minI,maxI = %f, %f\n",_minI,_maxI);

    printf("_di == NULL : %d\n",(_di==NULL));

    // Convert data
    i=0;
    _im->InitBuffer();
    if (_opacity_image.get()) _opacity_image->InitBuffer();
    do {
        val = _im->ValeurBuffer();
        if (_di!=NULL) {
            if (!_opacity_image.get())
                intensity=_di->IntensiteBuffer(val);
            else
                intensity = (unsigned char)_opacity_image->ValeurBuffer();

            /*
            switch (_map_mode) {
            case MAP_RGBA_RGBA:
            */

            _di->ColorBuffer(val,red,green,blue);
            _tex3ddata[i  ]= red;
//            _tex3ddata[i+1]= green;
//            _tex3ddata[i+2]= blue;
// why are green and blue inverted??
            _tex3ddata[i+1]= blue;
            _tex3ddata[i+2]= green;
            _tex3ddata[i+3]= intensity;
            i+=4;
            /*
            break;
            case MAP_I_RGBA:
            _tex3ddata[i]= intensity;
            i++;
            break;
            }
            */
        } else {
            if (val<_minI) _tex3ddata[i]=0;
            else
                if (val>_maxI) _tex3ddata[i]=255;
                else
                    _tex3ddata[i] = (unsigned char) ((val-_minI)/(_maxI-_minI)*255.0);
            /*
            switch (_map_mode) {
            case MAP_RGBA_RGBA:
            */
            _tex3ddata[i+1]=_tex3ddata[i];
            _tex3ddata[i+2]=_tex3ddata[i];
            _tex3ddata[i+3]=_tex3ddata[i];
            i+=4;
            /*
            break;
            case MAP_I_RGBA:
            i++;
            break;
            }
            */

        }


        if (_opacity_image.get())
            _opacity_image->IncBuffer();
    } while (_im->IncBuffer());


    glGetIntegerv(GL_MAX_3D_TEXTURE_SIZE, &max3dtexdims);

    printf("max3dtexdims=%d\n",max3dtexdims);

    if (_power2dim) {

        /* adjust width */
        newval = _size_x;
        if (_size_x > max3dtexdims)
            newval = max3dtexdims;
        if (NOTPOW2(_size_x))
            newval = makepow2(_size_x);
        if (newval != _size_x) {
            printf("newval!=_size_x\n");
            glPixelStorei(GL_UNPACK_ROW_LENGTH, _size_x);
            glPixelStorei(GL_UNPACK_SKIP_PIXELS, (_size_x - newval)/2);
            _size_x = newval;
        }

        /* adjust height */
        newval = _size_y;
        if (_size_y > max3dtexdims)
            newval = max3dtexdims;
        if (NOTPOW2(_size_y))
            newval = makepow2(_size_y);
        if (_size_y > newval) {
            printf("_size_y>newval\n");
            glPixelStorei(GL_UNPACK_IMAGE_HEIGHT, _size_y);
            glPixelStorei(GL_UNPACK_SKIP_ROWS, (_size_y - newval)/2);
            _size_y = newval;
        }

        /* adjust depth */
        newval = _size_z;
        if (_size_z > max3dtexdims)
            newval = max3dtexdims;
        if (NOTPOW2(_size_z))
            newval = makepow2(_size_z);
        if (_size_z > newval) {
            printf("_size_z>newval skipping images\n");
            _size_z = newval;
            //glPixelStorei(GL_UNPACK_SKIP_IMAGES, (_size_z - newval)/2);
        }
    }

    printf("size=(%d,%d,%d)\n",_size_x,_size_y,_size_z);

}


//----------------------------------------------------------------------
void VolumeRender::Render(unsigned char map)
{

  //  printf("VolumeRender::Render()\n");

  int i;
  GLfloat offS, offT, offR; /* mapping texture to planes */

  GLdouble clipplane0[] = {-1.,  0.,  0., -_ml.xmin}; /* x < 100 out */
  GLdouble clipplane1[] = { 1.,  0.,  0.,  _ml.xmax}; /* x > 100 out */
  GLdouble clipplane2[] = { 0., -1.,  0., -_ml.ymin}; /* y < 100 out */
  GLdouble clipplane3[] = { 0.,  1.,  0.,  _ml.ymax}; /* y > 100 out */
  GLdouble clipplane4[] = { 0.,  0., -1., -_ml.zmin}; /* z < 100 out */
  GLdouble clipplane5[] = { 0.,  0.,  1.,  _ml.zmax}; /* z > 100 out */

  float tpos;

  /*
  tcx = (float)_im->DimX();
  tcy = (float)_im->DimY();
  tcz = (float)_im->DimZ();
  */

  offS = _ml.xsize/_size_x;
  offT = _ml.ysize/_size_y;
  offR = _ml.zsize/_size_z;

  clipplane0[W] = -_ml.xmin - offS;
  clipplane1[W] =  _ml.xmax - offS;
  clipplane2[W] = -_ml.ymin - offT;
  clipplane3[W] =  _ml.ymax - offT;
  clipplane4[W] = -_ml.zmin - offR;
  clipplane5[W] =  _ml.zmax - offR;

  if(map)
    MapTexture();

  glPushMatrix();

  //_VOL.GLApplyInvMatrix();
  _VOL.GLApplyMatrix();
  _Ttexture->GLApplyMatrix();

  glClipPlane(GL_CLIP_PLANE0, clipplane0);
  glClipPlane(GL_CLIP_PLANE1, clipplane1);
  glClipPlane(GL_CLIP_PLANE2, clipplane2);
  glClipPlane(GL_CLIP_PLANE3, clipplane3);
  glClipPlane(GL_CLIP_PLANE4, clipplane4);
  glClipPlane(GL_CLIP_PLANE5, clipplane5);

  glPopMatrix();

  glMatrixMode(GL_TEXTURE);

  glEnable(GL_CLIP_PLANE0);
  glEnable(GL_CLIP_PLANE1);
  glEnable(GL_CLIP_PLANE2);
  glEnable(GL_CLIP_PLANE3);
  glEnable(GL_CLIP_PLANE4);
  glEnable(GL_CLIP_PLANE5);

  glPushMatrix(); /* identity */
  if (_Ttexture != NULL)
    {
    _SRT.GLApplyMatrix();
    _Ttexture->GLApplyInvMatrix();
    _VOL.GLApplyInvMatrix();
    //_VOL.GLApplyMatrix();
    _SRT.GLApplyInvMatrix();
    }
  // Figure out what are the right operations ...
  // Rotation of the texture???
  /*
    glTranslatef( .5f,  .5f, .5f);
    glRotatef(objangle[Y], 1.f, 0.f, 0.f);
    glRotatef(objangle[X], 0.f, 0.f, 1.f);
    glTranslatef( -.5f,  -.5f, -.5f);
  */


    switch(_operator)
    {
    case OVER:
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	break;
    case ATTENUATE:
	glEnable(GL_BLEND);
	glBlendFunc(GL_CONSTANT_ALPHA, GL_ONE);
/*	glBlendColor(1.f, 1.f, 1.f, 1.f/_planes);
*/
    case NONE:
	/* don't blend */
	break;
    }

  
    if(_texture)
       glEnable(GL_TEXTURE_3D);
    else
    {
       glDisable(GL_TEXTURE_3D);
       glEnable(GL_LIGHTING);
       glEnable(GL_LIGHT0);
    }

  // could be changed by interface later
    //  _planes=_size_y;

  glMatrixMode(GL_MODELVIEW);
  glPushMatrix(); /* identity */
  //  if (_Tobject != NULL)
  //   _Tobject-> GLApplyInvMatrix();

  for(i = 0; i < _planes; i++)
    {
      tpos =  _ml.zmin + offR + i * (_ml.zsize - 2 * offR)/(_planes - 1); 
      glBegin(GL_QUADS);
        glVertex3f( _ml.xmin, _ml.ymin,  tpos);
        glVertex3f( _ml.xmax, _ml.ymin,  tpos);
        glVertex3f( _ml.xmax, _ml.ymax,  tpos);
        glVertex3f( _ml.xmin, _ml.ymax,  tpos);
      glEnd();
    }

  glPopMatrix(); /* back to identity */

  glDisable(GL_TEXTURE_3D);
    if(!_texture)
    {
       glDisable(GL_LIGHTING);
    }
  glDisable(GL_BLEND);
    
  glMatrixMode(GL_TEXTURE);

  glPopMatrix(); /* back to identity */
  glMatrixMode(GL_MODELVIEW);


  if(_operator == ATTENUATE)
    {
	glPixelTransferf(GL_RED_SCALE, 3.f); /* brighten image */
	glPixelTransferf(GL_GREEN_SCALE, 3.f);
	glPixelTransferf(GL_BLUE_SCALE, 3.f);
	//	glCopyPixels(0, 0, winWidth, winHeight, GL_COLOR);
    }
}
