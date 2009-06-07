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
/***************************************************************************
 * $Author: karl $
 * Revision 1.6  2004/08/27 23:28:44  karl
 * small changes
 *
 * Revision 1.5  2004/08/27 23:21:23  karl
 * all for automatic grab of results for Book Chapter
 *
 * Revision 1.4  2004/08/25 22:37:39  karl
 * displaying vector field from amilab + read vtk vector field
 *
 * Revision 1.3  2004/08/11 07:54:03  karl
 * FastMarching in AMILab + Origin added to vtkImageData
 *
 * Revision 1.2  2004/08/06 20:48:29  karl
 * removed warnings + fixed bugs in IsoLigne
 *
 * Revision 1.1.1.1  2004/02/02 20:47:08  karl
 * source code in C++
 *
 * Revision 1.1.1.1  2003/08/14 07:16:06  karl
 * Source code
 *
 * Revision 1.3  2001/03/02 11:49:33  karl
 * *** empty log message ***
 *
 * Revision 1.2  2000/09/19 12:19:09  karl
 * *** empty log message ***
 *
 * Revision 1.1.1.1  2000/04/07 16:12:08  karl
 * Sources code
 *
 * Revision 1.7  1998/10/02 20:10:01  kkrissia
 * Creation d'une classe InrImage Template
 *
 */

//  Fichier inrimage2.cpp
// 
// Creation d'une classe InrImage permettant de
// manipuler les images dans le format inrimage
//
// Version sans la librairie epidaure
//
// Karl KRISSIAN    Sophia Antipolis, le 08-12-96
//


#ifdef USE_MAGICK
// Image Magick
extern "C" {
#include "magick/magick.h"
#include "magick/defines.h"
#undef class
}
#endif

#ifndef _WITHOUT_VTK_

//#include <vtkImageWriter.h> 
#include "vtkStructuredPointsReader.h"
#include "vtkStructuredPointsWriter.h"
#include "vtkImageReader2Factory.h"
#include "vtkImageReader2.h"
#include "vtkJPEGWriter.h"
#include "vtkTIFFWriter.h"
#include "vtkPNGWriter.h"
#include "vtkStructuredPoints.h"
#include "vtkPointData.h"
#include "vtkImageData.h"
#include "vtkDataArray.h"
#include "vtkDoubleArray.h"
#include "vtkFloatArray.h"
#include "vtkIntArray.h"
#include "vtkUnsignedCharArray.h"
#include "vtkUnsignedShortArray.h"
#include "vtkShortArray.h"
#include "vtkImageFlip.h"
#include "vtk_common.h"
#endif // _WITHOUT_VTK_

#include <boost/scoped_array.hpp>
using namespace boost;

#include "style.hpp"
#include "inrimage.hpp"
#include "amimage.hpp"
#include "StringUtils.hpp"

#include "math1.hpp"

#if defined(_MSC_VER) || defined(__MINGW32__)
int rint(const float& a)
{
	return (int) floor(a+0.5);
}

float fround(const float& a)
{
	return (float) floor(a+0.5);
}
#endif

#include "amilab_messages.h"


//extern unsigned char GB_debug;
//extern unsigned char GB_verbose;

int InrImage::TailleFormat[NB_FORMATS]  = { 1,   // WT_UNSIGNED_CHAR
                                           2,   // WT_UNSIGNED_SHORT
                                           2,   // WT_SIGNED_SHORT
                                           4,   // WT_UNSIGNED_INT
                                           4,   // WT_SIGNED_INT
                                           8,   // WT_UNSIGNED_LONG
                                           8,   // WT_SIGNED_LONG
                                           4,   // WT_FLOAT
                                           8,   // WT_DOUBLE
                       1,   // WT_RGB
                       1,   // WT_RGBA, 8 bits each
                       4,  // WT_FLOAT_VECTOR
                       8   // WT_DOUBLE_VECTOR
};


#define NEW(ptr,type,size) \
  ptr = new type[size]; \
  fprintf(stderr,"Allocation of %03.2f Mb \n", 1.0*size*sizeof(type)/1000000);


//==========================================================================
// MEMBRES PRIVES
//==========================================================================


#ifdef USE_MAGICK

void IM_ReadImage( char* name, Image*& image, ImageInfo& image_info,
           float*& red_pixels,
           float*& green_pixels,
           float*& blue_pixels
           )
{

  int           tx,ty;

  GetImageInfo(&image_info);
  strcpy(image_info.filename, name);
  image=ReadImage(&image_info);

  tx = image->columns;
  ty = image->rows;

  NEW(red_pixels ,     float, tx*ty);
  NEW(green_pixels ,   float, tx*ty);
  NEW(blue_pixels ,    float, tx*ty);

  GetPixels( image,
         red_pixels,
         green_pixels,
         blue_pixels,
         NULL);

}


//----------------------------------------------------------------------
// Image Magick 4.?./
int IM_WriteImage ( const char *name, 
            const float *r, 
            const float *g, 
            const float *b,
            const unsigned int w, const unsigned int h  ) 
{
    
    Image     *im;
    ImageInfo image_info;
    int       succeed;
    
    //    cout << "guardando: " << name << " size:" << w << "*" << h << endl;
    
    GetImageInfo(&image_info);

    im = CreateImage(w, h, r, g, b, NULL);
    
    strcpy(im->filename,name);
    strcpy(image_info.filename,name);
    
    SetImageInfo(&image_info,True);
    
    succeed = WriteImage(&image_info, im);

    if (!succeed)      
      fprintf(stderr,"Error writing image %s \n", name);

    return succeed;
}

#endif // USE_MAGICK

//--------------------------------------------------------------------------
unsigned char InrImage :: ReadAMI( ) throw (ErreurLecture)
//                           -------
{
  unsigned char   res; 

  CLASS_MESSAGE((char*)_nom);

  // Read AMImage
  amimage* im = new amimage();
  res = im->read( (char*) _nom);

  Si res Alors

    //      im.displayinfo();
    res = GetFormatFromAMI(im,_format);

    _translation_x = im->GetTX();
    _translation_y = im->GetTY();
    _translation_z = im->GetTZ();

    // Get the transformation matrix
    im->GetTransfMatrix(_transf_matrix);

    Si res Alors
        _tx     = im->GetXDim();
        _ty     = im->GetYDim();
        _tz     = im->GetZDim();
        _vdim   = im->GetVDim();
        _txy    = _tx*_ty;
        _taille = (unsigned long) _tx * _ty * _tz;

        _amimage = im;
        _amimage_allocated = true;

    FinSi

  FinSi

  return res;

} // ReadAMI()


#ifdef USE_MAGICK
//--------------------------------------------------------------------------
unsigned char InrImage :: ReadMagick( ) throw (ErreurLecture)
//                           ----------
{


    // Try Image Magick reading ...

    ImageInfo        image_info;
    Image*           image;
    int           tz;
    int           i,z;
    float* red_pixels;
    float* green_pixels;
    float* blue_pixels;
    unsigned char res;

    CLASS_MESSAGE("reading ImageMagick()");

    GetImageInfo(&image_info);
    strcpy(image_info.filename, _nom);
    image=ReadImage(&image_info);

    if (image==NULL)  return false;

    tz = GetNumberScenes(image);

    CLASS_MESSAGE(boost::format("tz = %d") % tz);

    _vdim = 3;
    _amimage = new amimage();
    _amimage->SetDim( image->columns,  image->rows, tz,_vdim);
    _amimage->SetType(AMI_VECTOR);
    _amimage->SetRepres(AMI_UNSIGNED_CHAR);
    _amimage->allocate();
    _amimage_allocated = true;

// Convert the format ...
    res = GetFormatFromAMI(_amimage,_format);

    _tx         = _amimage->GetXDim();
    _ty         = _amimage->GetYDim();
    _tz         = _amimage->GetZDim();
    _txy       = _tx*_ty;
    _taille    = (unsigned long) _tx * _ty * _tz;

    NEW(red_pixels ,      float, _taille);
    NEW(green_pixels ,    float, _taille);
    NEW(blue_pixels ,     float, _taille);

    while (image->previous != (Image *) NULL)
      image=image->previous;

    Pour(z,0,tz-1)

      Si (image != (const Image *) NULL) Alors

        GetPixels( image,
           red_pixels,
           green_pixels,
           blue_pixels,
           NULL);

        //
        InitBuffer(z*_txy);
        Pour(i,0,_txy-1)
          VectFixeValeurs( 255*red_pixels[i],
               255*green_pixels[i], 
               255*blue_pixels[i]
               );
          IncBuffer();
        FinPour

        image = image->next;

      FinSi

    FinPour

    //
    delete [] red_pixels;
    delete [] green_pixels;
    delete [] blue_pixels;

  return true;

} // ReadMagick()

#endif // USE_MAGICK

//--------------------------------------------------------------------------
unsigned char InrImage :: ReadVTK( ) throw (ErreurLecture)
//                           -------
{

#ifndef _WITHOUT_VTK_
  
   shared_ptr<vtkStructuredPointsReader> reader = vtk_new<vtkStructuredPointsReader>()();
    vtkStructuredPoints* in;
    int       x,y,z,n;

  CLASS_MESSAGE(boost::format("InrImage::ReadVTK()  begin "));

  reader->SetFileName((char*) _nom);
  reader->Update();

  in = reader->GetOutput();

  if (reader->GetErrorCode()!=0) { 
    return false; 
  }

  _vdim = in->GetNumberOfScalarComponents();
  CLASS_MESSAGE(boost::format("vdim = %d") % _vdim);

  // Check for Tensor data
  vtkPointData* pd = in->GetPointData();
  if (pd==NULL) 
    CLASS_ERROR(boost::format("not point data"));
  vtkDataArray* tensor = pd->GetTensors();

  if (tensor!=NULL) {
    _vdim = tensor->GetNumberOfComponents();
    CLASS_MESSAGE(boost::format("Reading Tensor data (size %d)") % _vdim)
  }

  SelonQue (in->GetScalarType()) Vaut
    Valeur VTK_FLOAT:          _format = WT_FLOAT;
    FinValeur
    Valeur VTK_UNSIGNED_SHORT: _format = WT_UNSIGNED_SHORT;
    FinValeur
    Valeur VTK_SHORT:          _format = WT_SIGNED_SHORT;
    FinValeur
    Valeur VTK_UNSIGNED_INT:   _format = WT_UNSIGNED_INT;
    FinValeur
    Valeur VTK_INT:            _format = WT_SIGNED_INT;
    FinValeur
    Valeur VTK_UNSIGNED_CHAR:
     switch (_vdim) {
       case 1: _format = WT_UNSIGNED_CHAR; break;
       case 3: _format = WT_RGB; break;
       default: 
          CLASS_ERROR(boost::format("Non-scalar UCHAR vdim=%1% !=3 not available")%_vdim);
     }
    FinValeur

    Valeur VTK_DOUBLE:
     _format = WT_DOUBLE;
    break;

    Defaut: 
      CLASS_ERROR(boost::format("Scalar type %1% non available")
                           % in->GetScalarType());
    _format = WT_FLOAT;

  FinSelonQue

  CLASS_MESSAGE("1");

  _tx     = in->GetDimensions()[0];
  _ty     = in->GetDimensions()[1];
  _tz     = in->GetDimensions()[2];
  _txy    = _tx*_ty;
  _taille = (unsigned long) _tx * _ty * _tz;


  CLASS_MESSAGE(boost::format(" %d %d %d ") % _tx % _ty % _tz);

    _amimage = new amimage();
    _amimage->SetDim( _tx, _ty, _tz, _vdim);
    AMIFromWT(_vdim,_format,_amimage);
    if (_amimage->allocate()) {
      _amimage_allocated = true;

//  _inrimage_allouee = true;

      _amimage->SetVoxelSize( in->GetSpacing()[0],
                  in->GetSpacing()[1],
                  in->GetSpacing()[2]);

      _amimage->SetTX(in->GetOrigin()[0]);
      _amimage->SetTY(in->GetOrigin()[1]);
      _amimage->SetTZ(in->GetOrigin()[2]);


      if (_amimage-> GetVX() < 1E-5) _amimage->SetVX(1.0);
      if (_amimage-> GetVY() < 1E-5) _amimage->SetVY(1.0);
      if (_amimage-> GetVZ() < 1E-5) _amimage->SetVZ(1.0);
      
      CLASS_MESSAGE("2");
      
//  memcpy(_inrimage->data, in->GetScalarPointer() , in->);

      vtkDataArray* scalars = NULL;
      if (tensor==NULL) {
        scalars = pd->GetScalars();
        if (scalars==NULL) {
          CLASS_ERROR("Neither tensor nor scalar data");
            return 0;
        }
      }

      double t[9];
      scoped_array<double> val(new double[_vdim]);
//      double val[_vdim];
      int pos[3];
      int inPtId;

      InitBuffer();
      Pour(z,0,_tz-1)
        pos[2]=z;
        //printf("Converting VTK to ami z = %d \n",z);
      Pour(y,0,_ty-1)
        pos[1]=y; // Flip in Y ???
      Pour(x,0,_tx-1)
        pos[0] = x;
        inPtId = in->ComputePointId(pos);
        if (tensor!=NULL) {
          tensor->GetTuple(inPtId, t);
          Pour(n,0,_vdim-1)
            VectFixeValeur(n,t[n]);
          FinPour
        } else 
        if (_vdim==1) {
          scalars->GetTuple(inPtId, val.get());
          FixeValeur(*val.get());
        } else {
          scalars->GetTuple(inPtId, val.get());
          Pour(n,0,_vdim-1)
            VectFixeValeur(n,val[n]);
          FinPour
        }
        IncBuffer();
      FinPour
      FinPour
      FinPour
    }
    else {
      CLASS_ERROR("Allocation problem");
      return false;
    }

  CLASS_MESSAGE("end");

  return true;

#else
  CLASS_ERROR("AMILab compiled without VTK");
  return false;
#endif // _WITHOUT_VTK_
  
  
} // ReadVTK()


//--------------------------------------------------------------------------
unsigned char InrImage :: ReadVTKImage( ) throw (ErreurLecture)
//                           ------------
{

#ifndef _WITHOUT_VTK_

    vtkImageData* in;
    int       x,y,z,n;

  CLASS_MESSAGE("begin");

  shared_ptr<vtkImageReader2Factory> create_reader = vtk_new<vtkImageReader2Factory>()();
  vtkImageReader2* imreader = create_reader->CreateImageReader2((char*) _nom); 
  if (imreader==NULL) {
    CLASS_MESSAGE("No reader found from vtkImageReader2Factory")
    return false;
  }

  shared_ptr<vtkImageReader2> reader = vtk_new<vtkImageReader2>()(imreader);


  reader->SetFileName((char*) _nom);
  reader->Update();

  in = reader->GetOutput();

  if (reader->GetErrorCode()!=0) { 
    return false; 
  }

  _vdim = in->GetNumberOfScalarComponents();

  SelonQue (in->GetScalarType()) Vaut

    Valeur VTK_FLOAT:
     switch (_vdim) {
       case 1: _format = WT_FLOAT; break;
       default: _format = WT_FLOAT_VECTOR; break;
     }
     
    FinValeur
    Valeur VTK_UNSIGNED_SHORT:
      _format = WT_UNSIGNED_SHORT;
    FinValeur
    Valeur VTK_SHORT:
      _format = WT_SIGNED_SHORT;
    FinValeur
    Valeur VTK_UNSIGNED_INT:
      _format = WT_UNSIGNED_INT;
    FinValeur
    Valeur VTK_INT:
      _format = WT_SIGNED_INT;
    FinValeur
    Valeur VTK_UNSIGNED_CHAR:
     switch (_vdim) {
       case 1: _format = WT_UNSIGNED_CHAR; break;
       case 3: _format = WT_RGB; break;
       case 4: 
         _format = WT_RGBA; 
         //_format = WT_RGB; 
         //_vdim = 3; 
       break;
       default: 
        fprintf(stderr,"InrImage::ReadVTKImage non-scalar uchar vdim!=3 non available %d \n", _vdim);
     }
    FinValeur

    Defaut:   
      CLASS_ERROR("type not available");
      _format = WT_FLOAT;

  FinSelonQue

  CLASS_MESSAGE("1");

  _tx     = in->GetDimensions()[0];
  _ty     = in->GetDimensions()[1];
  _tz     = in->GetDimensions()[2];
  _txy    = _tx*_ty;
  _taille = (unsigned long) _tx * _ty * _tz;


  CLASS_MESSAGE(boost::format(" image size: %d x %d x %d ") % _tx % _ty % _tz);

    _amimage = new amimage();
    _amimage->SetDim( _tx, _ty, _tz, _vdim);
    AMIFromWT(_vdim,_format,_amimage);
    if (_amimage->allocate()) {
      _amimage_allocated = true;

//  _inrimage_allouee = true;

      _amimage->SetVoxelSize( in->GetSpacing()[0],
                  in->GetSpacing()[1],
                  in->GetSpacing()[2]);

      _amimage->SetTX(in->GetOrigin()[0]);
      _amimage->SetTY(in->GetOrigin()[1]);
      _amimage->SetTZ(in->GetOrigin()[2]);


      if (_amimage-> GetVX() < 1E-5) _amimage->SetVX(1.0);
      if (_amimage-> GetVY() < 1E-5) _amimage->SetVY(1.0);
      if (_amimage-> GetVZ() < 1E-5) _amimage->SetVZ(1.0);
      
      CLASS_MESSAGE("2");
      
//  memcpy(_inrimage->data, in->GetScalarPointer() , in->);
      // Flip in Y ?
      vtkPointData* pd = in->GetPointData();
      if (pd==NULL) {
          CLASS_ERROR("no point data");
          return 0;
      }
      vtkDataArray* scalars = NULL;
      scalars = pd->GetScalars();
      if (scalars==NULL) {
          CLASS_ERROR("neither tensor nor scalar data");
          return 0;
      }

      scoped_array<double> val(new double[_vdim]);
//      double val[_vdim];
      int pos[3];
      int inPtId;

      InitBuffer();
      Pour(z,0,_tz-1)
        pos[2]=z;
        //printf("Converting VTK to ami z = %d \n",z);
      Pour(y,0,_ty-1)
        pos[1]=_ty-1-y; //    flip in Y
      Pour(x,0,_tx-1)
        pos[0] = x;
        inPtId = in->ComputePointId(pos);
        if (_vdim==1) {
          scalars->GetTuple(inPtId, val.get());
          FixeValeur(*val.get());
        } else {
          scalars->GetTuple(inPtId, val.get());
          Pour(n,0,_vdim-1)
            VectFixeValeur(n,val[n]);
          FinPour
        }
        IncBuffer();
      FinPour
      FinPour
      FinPour
    }
    else {
      CLASS_ERROR("allocation problem");
      return false;
    }

  Si GB_debug AlorsFait fprintf(stderr,"InrImage::ReadVTKImage()  3 \n");
  Si GB_debug AlorsFait fprintf(stderr,"InrImage::ReadVTKImage()  end \n");

  return true;

#else
  fprintf(stderr,"inrimage.cpp \t AMILab compiled without VTK, function not available \n");
  return false;
#endif // _WITHOUT_VTK_

} // ReadVTKImage()


//--------------------------------------------------------------------------
unsigned char InrImage :: Lit( ) throw (ErreurLecture)
//                           ---
{

  inrimage* ptr;
  unsigned char   res; 

  CLASS_MESSAGE("Begin");

  res = ReadAMI();

  Si Non(res) Alors
    Si (_nom == "<") Alors
      // entree standard
      ptr = readZInrimage( NULL);
    Sinon
      ptr = readZInrimage( (char*) _nom);
    FinSi

    Si ptr != NULL Alors
      _format = ptr->type;
      //    _inrimage = ptr;
      //    _inrimage_allouee = true;

      // Create AMImage Here ...
      _amimage = new amimage();   
 
      AMIFromWT(ptr->vdim,ptr->type,_amimage);
      _amimage->SetDim(ptr->ncols, ptr->nrows, ptr->nplanes);
      _amimage->SetVoxelSize(ptr->vx,ptr->vy,ptr->vz);
      _amimage->allocate();
      memcpy(_amimage->GetData(), ptr->data, _amimage->GetDataSize());
      _amimage_allocated = true;

      // delete _inrimage
      freeInrimage(ptr);
      ptr = NULL;

      return true;
    FinSi
  FinSi

  //  Si ptr == NULL Alors
#ifdef USE_MAGICK
  if (!res) { 
    CLASS_MESSAGE("Trying to read with ImageMagick");  
    res = ReadMagick();
  }
#endif // USE_MAGICK

  // try with the vtk image reader factory
  if (!res) {
    cout << "Trying reading with VTK image factory" << endl;  
    res = ReadVTKImage();
  }

  if (!res) {
    CLASS_MESSAGE("Trying reading with ReadVTK");  
    res = ReadVTK();
  }

  Si !res Alors
    cerr << " Error reading image " << endl;
    throw ErreurLecture();
  FinSi


  return (res);

} // Lit()


//--------------------------------------------------------------------------
unsigned char InrImage :: LitEntete( )  throw (ErreurLecture)
//                           ---------
{

  INRIMAGE_HEADER* ptr;
  inrimage*        ptr_image;

//  printf("lecture de l'ent�e de %s \n", (char*) _nom);

  Si (_nom == "<") Alors
    // entree standard
    printf("InrImage::LitEntete()\t on ne lit pas que ");
    printf("l'entete sur l'entree standard\n");
    ptr_image = readZInrimage( NULL);
//    _inrimage_allouee = true;
  Sinon
    ptr = readZInrimageHeader( (char*) _nom);
    ptr_image = ptr->inr;
//    _inrimage_allouee = false;
  FinSi

  Si ptr_image == NULL Alors
  //    E_SETERR(E_ERRR, "reading in file", (char*) _nom);
    throw ErreurLecture();
  FinSi


  // put the information in the _amimage member and free the pointer

  _format = ptr_image->type;

  if (_amimage==NULL)
    _amimage = new amimage();

  _amimage->SetDim(ptr_image->ncols, ptr_image->nrows, ptr_image->nplanes );
  AMIFromWT(ptr_image->vdim,ptr_image->type,_amimage);
  _amimage->SetVoxelSize(ptr_image->vx,ptr_image->vy,ptr_image->vz);

  free(ptr_image);

  return true;

} // LitEntete()


//--------------------------------------------------------------------------
unsigned char InrImage :: Alloue( ) throw (ErreurAllocation)
//                           ------ 
{

//  cout << "allocation de "  <<  _nom << " \t taille = "
//       <<  (long int ) _tx*_ty*_tz*TailleFormat[_format]  
//       << "( " << _tx << ", " << _ty << ", " << _tz << ")"
//       << " " <<  TailleFormat[_format]  
//       << endl;

  Si _vdim == 1 Alors
    SelonQue (WORDTYPE) _format Vaut

      Valeur WT_DOUBLE:        
      Valeur WT_FLOAT:         
      Valeur WT_UNSIGNED_CHAR: 
      Valeur WT_UNSIGNED_SHORT:
      Valeur WT_SIGNED_SHORT:  
      Valeur WT_UNSIGNED_INT: 
      Valeur WT_SIGNED_INT:  _vdim = 1;
      FinValeur

      Valeur WT_RGB:
        _vdim = 3;
      FinValeur
      Defaut:  _vdim=1;

    FinSelonQue
  FinSi

  _amimage = new amimage();
  _amimage->SetDim(_tx,_ty,_tz, _vdim );
  AMIFromWT(_vdim,_format,_amimage);
  _amimage->SetVoxelSize(_size_x,_size_y,_size_z);
  _amimage->SetTranslation(_translation_x,
               _translation_y,
               _translation_z);
  _amimage->allocate();

  Si _amimage == NULL Alors
    cerr << " Probleme d'allocation de l'image " << _nom << endl;
    throw ErreurAllocation();
  FinSi

  _amimage_allocated = true;

  return true;

} // Alloue()


//--------------------------------------------------------------------------
 unsigned char InrImage :: Ecrit( ) throw( ImageWriteError)
//                           -----     
{

  
#ifndef _WITHOUT_VTK_
    vtkImageData_ptr   vtk_id;
#endif
    inrimage*       inrimage_ptr;
    char  name[200];


  strcpy(name,_nom);
  RemoveEndString(name,".gz");

/*
  Si (CheckEndString( name, ".inr"))Ou(CheckEndString( name, ".hdr")) Alors
    // Convert to inrimage first ...
    inrimage_ptr = (inrimage*) (*this);
    Si (writeZInrimage( inrimage_ptr, (char*) _nom)<0) Alors
      throw ImageWriteError();
    FinSi
    // delete inrimage_ptr ?
    free(inrimage_ptr);
    //  freeInrimage(inrimage_ptr);
  Autrement
*/

#ifndef _WITHOUT_VTK_
  Si (CheckEndString( name, ".vtk")) Alors
    shared_ptr<vtkStructuredPointsWriter> vtk_iw;
    vtk_id = (vtkImageData_ptr) (*this);
    vtk_iw = vtk_new<vtkStructuredPointsWriter>()();

    vtk_iw->SetInput(vtk_id.get());
    vtk_iw->SetFileName((char*) _nom);
    vtk_iw->SetFileTypeToBinary();
//    vtk_iw->SetFileDimensionality(3);

    vtk_iw->Write();

  Autrement
  // Use VTK for writing jpeg if possible
  Si (CheckEndString( name, ".jpg") Ou 
      CheckEndString( name, ".jpeg")) Alors
    vtk_id    = (vtkImageData_ptr) (*this);
    shared_ptr<vtkJPEGWriter> vtk_jpegw = vtk_new<vtkJPEGWriter>()();

//    vtkImageFlip* flipY = vtkImageFlip::New();
//    flipY->SetInput(vtk_id);
//    flipY->SetFilteredAxis(1);

//    vtk_jpegw->SetInput(flipY->GetOutput());
    vtk_jpegw->SetInput(vtk_id.get());
    vtk_jpegw->SetFileName((char*) _nom);
    vtk_jpegw->Write();

//    flipY->Delete();
  Autrement
  Si (CheckEndString( name, ".tiff") Ou CheckEndString( name, ".tif")) Alors
    vtk_id = (vtkImageData_ptr) (*this);
    shared_ptr<vtkTIFFWriter> vtk_tiffw = vtk_new<vtkTIFFWriter>()();

//    vtkImageFlip* flipY = vtkImageFlip::New();
//    flipY->SetInput(vtk_id);
//    flipY->SetFilteredAxis(1);

//    vtk_tiffw->SetInput(flipY->GetOutput());
    vtk_tiffw->SetInput(vtk_id.get());
    vtk_tiffw->SetFileName((char*) _nom);
    vtk_tiffw->Write();

//    flipY->Delete();
  Autrement
  Si (CheckEndString( name, ".png") Ou CheckEndString( name, ".PNG")) Alors
    vtk_id = (vtkImageData_ptr) (*this);
    shared_ptr<vtkPNGWriter> vtk_pngw = vtk_new<vtkPNGWriter>()();

//    vtk_pngw->SetInput(flipY->GetOutput());
    vtk_pngw->SetInput(vtk_id.get());
    vtk_pngw->SetFileName((char*) _nom);
    vtk_pngw->Write();
//    flipY->Delete();
  Autrement

#endif // _WITHOUT_VTK_
      
  Si (CheckEndString( name, ".raw"))  Alors
    // write only raw data
    return _amimage->write((char*) _nom,0);
  Autrement
  Si (CheckEndString( name, ".ami")) Ou ( _format != WT_RGB) Alors

    return _amimage->write((char*) _nom);

#ifdef USE_MAGICK
  Sinon
    
      float* r;
      float* g;
      float* b;
      int n,z;

    NEW(r , float, _tx*_ty);
    NEW(g , float, _tx*_ty);
    NEW(b , float, _tx*_ty);

    Si _tz == 1 Alors
      Si _format == WT_RGB Alors
        InitBuffer();
        Pour(n,0,_txy-1)
      r[n] = VectValeurBuffer(0)/255.0;
      g[n] = VectValeurBuffer(1)/255.0;
      b[n] = VectValeurBuffer(2)/255.0;
          IncBuffer();
        FinPour
      Sinon
        fprintf(stderr,"InrImage::Ecrit() \t Magick seulement pour RGB \n");
        delete r;
        delete g;
        delete b;
        throw ImageWriteError();
      FinSi
      IM_WriteImage(_nom,r,g,b,_tx,_ty);
    Sinon
      
        char name[256];
        char num[10];
        int  pos1,pos2;

      Si _format == WT_RGB Alors
        Pour(z,0,_tz-1)
          BufferPos(0,0,z);
          Pour(n,0,_txy-1)
        r[n] = VectValeurBuffer(0)/255.0;
        g[n] = VectValeurBuffer(1)/255.0;
        b[n] = VectValeurBuffer(2)/255.0;
            IncBuffer();
          FinPour
          
          sprintf(num,"%03d",z);
          pos1 = pos2 =0;
          while ((_nom[pos1]!='.')Et(_nom[pos1]!='\0'))
          {
        name[pos2]=_nom[pos1];
            pos2++; pos1++;
      }
          name[pos2] = '\0';
          strcat(name,".");
          strcat(name,num);
          pos2 = strlen(name);
          while (_nom[pos1]!='\0')
          {
        name[pos2]=_nom[pos1];
            pos2++; pos1++;
      }
          name[pos2] = '\0';

          if (!IM_WriteImage(name,r,g,b,_tx,_ty)) {
            delete r;
            delete g;
            delete b;
            throw ImageWriteError();
      }
        FinPour
      Sinon
        fprintf(stderr,"InrImage::Ecrit() \t Magick seulement pour RGB \n");
        delete r;
        delete g;
        delete b;
        throw ImageWriteError();
      FinSi
    FinSi

    delete r;
    delete g;
    delete b;
#endif // USE_MAGICK

  FinSi

  return true;

} // Ecrit()


//--------------------------------------------------------------------------
unsigned char InrImage :: Desalloue( )
//                           ---------       
{

//  printf("liberation de %s \n", (char*) _nom);
  CLASS_MESSAGE(boost::format(" freeing image %s ") % (char*) _nom)

  Si (_amimage_allocated) Et (_amimage != NULL) Alors
    delete _amimage;
    _amimage = NULL;
    _amimage_allocated = false;
    //delete _nom;
  FinSi

  return true;

} // Desalloue()


//--------------------------------------------------------------------------
unsigned char InrImage :: LitMaple( const char* nom )
//                           --------     
{

    char chaine[100];
    int    x;
    float      r;
    FILE*     fic;

  fic = fopen( nom, "r");
  Si fic == NULL Alors
    printf("InrImage::LitMaple()\t Erreur dans l'ouverture du fichier de %s \n", nom);
    return false;
  FinSi

  fscanf(fic,"Type:\t%s\n",chaine);
  printf("chaine = '%s'\n",chaine);
  Si strcmp(chaine,"Image1D")!=0 Alors
    printf("InrImage::LitMaple()\t Erreur, Pour lecture d'image 1D uniquement ... \n");
    return false;
  FinSi

  // Initialisation
  _nom = nom;
  _nom += ".inr";

  fscanf(fic,"Dimension:\t%d\n",&_tx);
  _ty = _tz = 1;

  _size_x = _size_y = _size_z = 1;

  _translation_x =
  _translation_y =
  _translation_z = 0;

  _format = WT_FLOAT;
  _vdim   = 1;

  // Allocation
  Alloue();

  // Lecture
  Pour(x,0,_tx-1)
    fscanf(fic,"%f\t",&r);
    ((FORMAT_FLOAT*)_amimage->data)[x]=r;
  FinPour

  fclose(fic);

  return true;

} // LitMaple()


//--------------------------------------------------------------------------
unsigned char InrImage :: EcritMaple(const char* nom )
//                           ----------     
{

  
    int    x;
    float      r;
    FILE*     fic;

  fic = fopen( nom, "w");
  Si fic == NULL Alors
    printf(" Erreur dans l'ouverture du fichier de %s \n", nom);
    return false;
  FinSi

  fprintf(fic,"Type:\tImage1D\n");
  fprintf(fic,"Dimension:\t%d\n",_tx);

  Pour(x,0,_tx-1)
    r = ((FORMAT_FLOAT*)_amimage->data)[x];
    fprintf(fic,"%f\t",r);
  FinPour

  fclose(fic);

  return true;

} // EcritMaple()


//--------------------------------------------------------------------------
unsigned char InrImage :: InitPositions( )
//                           -------------
{

   
    int z,y;
    int txy;

  txy = _tx*_ty;

  SelonQue (WORDTYPE) _format Vaut

    Valeur WT_RGBA   : 
    Valeur WT_UNSIGNED_CHAR   : 
      _positions_UNSIGNED_CHAR = new FORMAT_UNSIGNED_CHAR**[_tz];
      Pour( z, 0, _tz-1)
        _positions_UNSIGNED_CHAR[z] = new FORMAT_UNSIGNED_CHAR*[ _ty];
        Pour( y, 0, _ty-1)
          _positions_UNSIGNED_CHAR[z][y] = 
         (FORMAT_UNSIGNED_CHAR*)_amimage->GetData()+_vdim*(z*txy+y*_tx);
        FinPour
      FinPour
    FinValeur

    Valeur WT_UNSIGNED_SHORT   :   
      _positions_UNSIGNED_SHORT = new FORMAT_UNSIGNED_SHORT**[_tz];
      Pour( z, 0, _tz-1)
        _positions_UNSIGNED_SHORT[z] = new FORMAT_UNSIGNED_SHORT*[ _ty];
        Pour( y, 0, _ty-1)
          _positions_UNSIGNED_SHORT[z][y] = 
         (FORMAT_UNSIGNED_SHORT*)_amimage->GetData()+_vdim*(z*txy+y*_tx);
        FinPour
      FinPour
    FinValeur

    Valeur WT_SIGNED_SHORT  :  
      _positions_SIGNED_SHORT = new FORMAT_SIGNED_SHORT**[_tz];
      Pour( z, 0, _tz-1)
        _positions_SIGNED_SHORT[z] = new FORMAT_SIGNED_SHORT*[ _ty];
        Pour( y, 0, _ty-1)
          _positions_SIGNED_SHORT[z][y] = 
         (FORMAT_SIGNED_SHORT*)_amimage->GetData()+_vdim*(z*txy+y*_tx);
        FinPour
      FinPour
    FinValeur

    Valeur WT_UNSIGNED_INT  :  
      _positions_UNSIGNED_INT = new FORMAT_UNSIGNED_INT**[_tz];
      Pour( z, 0, _tz-1)
        _positions_UNSIGNED_INT[z] = new FORMAT_UNSIGNED_INT*[ _ty];
        Pour( y, 0, _ty-1)
          _positions_UNSIGNED_INT[z][y] = 
         (FORMAT_UNSIGNED_INT*)_amimage->GetData()+_vdim*(z*txy+y*_tx);
        FinPour
      FinPour
    FinValeur

    Valeur WT_SIGNED_INT  :  
      _positions_SIGNED_INT = new FORMAT_SIGNED_INT**[_tz];
      Pour( z, 0, _tz-1)
        _positions_SIGNED_INT[z] = new FORMAT_SIGNED_INT*[ _ty];
        Pour( y, 0, _ty-1)
          _positions_SIGNED_INT[z][y] = 
         (FORMAT_SIGNED_INT*)_amimage->GetData()+_vdim*(z*txy+y*_tx);
        FinPour
      FinPour
    FinValeur

    Valeur WT_FLOAT : 
      _positions_FLOAT = new FORMAT_FLOAT**[_tz];
      Pour( z, 0, _tz-1)
        _positions_FLOAT[z] = new FORMAT_FLOAT*[ _ty];
        Pour( y, 0, _ty-1)
          _positions_FLOAT[z][y] = 
             (FORMAT_FLOAT*)_amimage->GetData()+_vdim*(z*txy+y*_tx);
        FinPour
      FinPour
    FinValeur

    Valeur WT_DOUBLE : 
      _positions_DOUBLE = new FORMAT_DOUBLE**[_tz];
      Pour( z, 0, _tz-1)
        _positions_DOUBLE[z] = new FORMAT_DOUBLE*[ _ty];
        Pour( y, 0, _ty-1)
          _positions_DOUBLE[z][y] = 
             (FORMAT_DOUBLE*)_amimage->GetData()+_vdim*(z*txy+y*_tx);
        FinPour
      FinPour
    FinValeur

    Valeur WT_RGB : 
      _positions_RGB = new FORMAT_RGB**[_tz];
      Pour( z, 0, _tz-1)
        _positions_RGB[z] = new FORMAT_RGB*[ _ty];
        Pour( y, 0, _ty-1)
          _positions_RGB[z][y] = 
             (FORMAT_RGB*)_amimage->GetData()+3*(z*txy+y*_tx);
        FinPour
      FinPour
    FinValeur

    Valeur WT_FLOAT_VECTOR : 
      _positions_FLOAT_VECTOR = new FORMAT_FLOAT_VECTOR**[_tz];
      Pour( z, 0, _tz-1)
        _positions_FLOAT_VECTOR[z] = new FORMAT_FLOAT_VECTOR*[ _ty];
        Pour( y, 0, _ty-1)
          _positions_FLOAT_VECTOR[z][y] = 
             (FORMAT_FLOAT_VECTOR*)_amimage->GetData()+_vdim*(z*txy+y*_tx);
        FinPour
      FinPour
    FinValeur

    Defaut:
    fprintf(stderr,"InitPosition, format not processed ... \n");

  FinSelonQue

  _positions_allouees = true;

  return true;

} // InitPositions()


//--------------------------------------------------------------------------
unsigned char InrImage :: EffacePositions( )
//                           ---------------
{

   
    int z;
    int txy;

  Si Non(_positions_allouees) AlorsFait return false;

  txy = _tx*_ty;

  SelonQue (WORDTYPE) _format Vaut

    Valeur WT_RGBA: 
    Valeur WT_UNSIGNED_CHAR: 
       Pour(z,0,_tz-1) delete [] _positions_UNSIGNED_CHAR[z];FinPour
       delete [] _positions_UNSIGNED_CHAR;
    FinValeur

    Valeur WT_UNSIGNED_SHORT: 
       Pour(z,0,_tz-1) delete [] _positions_UNSIGNED_SHORT[z];FinPour
       delete [] _positions_UNSIGNED_SHORT;
    FinValeur

    Valeur WT_SIGNED_SHORT: Pour(z,0,_tz-1) delete [] _positions_SIGNED_SHORT[z];FinPour
       delete [] _positions_SIGNED_SHORT;
    FinValeur

    Valeur WT_UNSIGNED_INT: Pour(z,0,_tz-1) delete [] _positions_UNSIGNED_INT[z];FinPour
       delete [] _positions_UNSIGNED_INT;
    FinValeur

    Valeur WT_SIGNED_INT: Pour(z,0,_tz-1) delete [] _positions_SIGNED_INT[z];FinPour
       delete [] _positions_SIGNED_INT;
    FinValeur

    Valeur WT_FLOAT:
       Pour(z,0,_tz-1) delete [] _positions_FLOAT[z];FinPour
       delete [] _positions_FLOAT;
    FinValeur

    Valeur WT_DOUBLE:
       Pour(z,0,_tz-1) delete [] _positions_DOUBLE[z];FinPour
       delete [] _positions_DOUBLE;
    FinValeur

    Valeur WT_RGB:
       Pour(z,0,_tz-1) delete [] _positions_RGB[z];FinPour
       delete [] _positions_RGB;
    FinValeur

    Valeur WT_FLOAT_VECTOR:
       Pour(z,0,_tz-1) delete [] _positions_FLOAT_VECTOR[z];FinPour
       delete [] _positions_FLOAT_VECTOR;
    FinValeur

    Defaut:
    fprintf(stderr,"InrImage::EffacePositions, format not processed ... \n");
  FinSelonQue

  _positions_allouees = false;

  return true;

} // EffacePositions()


//----------------------------------------------------------------------
void InrImage :: InitParams()
//
{

  int i,j;

  _nom = "";
  _message_erreur = "";
  _tx     =
  _ty     =
  _tz     =
  _txy    =
  _taille = 0;
  _size_x =
  _size_y =
  _size_z = 1;
  _vdim   = 1;
  _coord_vecteur = 0;
  _translation_x =
  _translation_y =
  _translation_z = 0;
//  _inrimage = NULL;
  _amimage = NULL;
//_data = NULL;

//  _inrimage_allouee   = false;
  _amimage_allocated   = false;
  _positions_allouees = false;

  // Identity Matrix
  for(i=0;i<4;i++) 
  for(j=0;j<4;j++)
    _transf_matrix[i][j] = 0;
  for(i=0;i<3;i++) _transf_matrix[i][i] = 1;

} // InitParams()


//==========================================================================
// MEMBRES PUBLICS
//==========================================================================

//--------------------------------------------------------------------------
InrImage :: Constructeur InrImage( )
//                                 --------
{

  InitParams();

} // Construteur


//--------------------------------------------------------------------------
InrImage :: Constructeur InrImage( char* nom)
//                                 --------
{

  InitParams();

  //----- Lecture de l'image d'entree
  _nom = nom;

  Lit();

  _tx     = _amimage->GetXDim();
  _ty     = _amimage->GetYDim();
  _tz     = _amimage->GetZDim();
  _txy    = _tx*_ty;
  _taille = (unsigned long) _tx * _ty * _tz;

  _size_x = _amimage->GetVX();
  _size_y = _amimage->GetVY();
  _size_z = _amimage->GetVZ();

  _translation_x = _amimage->GetTX();
  _translation_y = _amimage->GetTY();
  _translation_z = _amimage->GetTZ();

  InitPositions();


} // Construteur



//--------------------------------------------------------------------------
InrImage :: Constructeur InrImage( char* nom, int type)
//                                 --------
{

  InitParams();

  Si type != TYPE_MAPLE AlorsRetourne;

  LitMaple( nom);

  InitPositions();


} // Construteur


//--------------------------------------------------------------------------
// Defaut  char* nom=NULL
//
InrImage :: Constructeur InrImage( int dimx, int dimy, 
//                                 --------            
                         int dimz, WORDTYPE format, const char* nom)
{

  InitParams();

  Si nom == NULL Alors
    _nom = "sans_nom.inr";
  Sinon
    _nom = nom;
  FinSi

  _tx = dimx;
  _ty = dimy;
  _tz = dimz;
  _txy = _tx*_ty;
  _taille = (unsigned long) _tx * _ty * _tz;
 
  _format = (WORDTYPE) format;

  if (_format==WT_FLOAT_VECTOR) {
    if (_tz>1) _vdim=3;
    else if (_ty>1) _vdim=2;
    else _vdim=1;
  }

  Alloue();

  InitPositions();


} // Construteur


//--------------------------------------------------------------------------
// Defaut  char* nom=NULL
//
InrImage :: Constructeur InrImage( int dimx, int dimy, 
//                                 --------            
                         int dimz, int vdim, WORDTYPE format, const char* nom)
{

  InitParams();

  Si nom == NULL Alors
    _nom = "sans_nom.inr";
  Sinon
    _nom = nom;
  FinSi

  _tx     = dimx;
  _ty     = dimy;
  _tz     = dimz;
  _txy    = _tx*_ty;
  _taille = (unsigned long) _tx * _ty * _tz;
 
  _format = (WORDTYPE) format;
  _vdim   = vdim;

  Alloue();

  InitPositions();


} // Construteur


//--------------------------------------------------------------------------
// Defaut  char* nom=NULL
//
InrImage :: Constructeur InrImage(  WORDTYPE format, 
//                                 --------  
                          const char* nom,
                          InrImage* image )
{

  InitParams();

  Si nom == NULL Alors
    _nom = "sans_nom.inr";
  Sinon
    _nom = nom;
  FinSi

  _tx = image->_tx;
  _ty = image->_ty;
  _tz = image->_tz;
  _vdim = image->GetVDim();
  if ((format==WT_DOUBLE_VECTOR)||(format==WT_FLOAT_VECTOR)) {
    if (_tz>1) _vdim=3;
    else if (_ty>1) _vdim=2;
    else _vdim=1;
  }

  _txy = _tx*_ty;
  _taille = (unsigned long) _tx * _ty * _tz;
 
  _size_x = image->_size_x;
  _size_y = image->_size_y;
  _size_z = image->_size_z;

  _translation_x = image->_translation_x;
  _translation_y = image->_translation_y;
  _translation_z = image->_translation_z;

  _format = (WORDTYPE) format;

/*
  if (_format==WT_FLOAT_VECTOR) {
    if (_tz>1) _vdim=3;
    else if (_ty>1) _vdim=2;
    else _vdim=1;
  }
*/
  Alloue();

  InitPositions();


} // Construteur

//--------------------------------------------------------------------------
// Defaut  char* nom=NULL
//
InrImage :: Constructeur InrImage(  WORDTYPE format, int vdim,
//                                 --------  
                          const char* nom,
                          InrImage* image )
{

  InitParams();

  Si nom == NULL Alors
    _nom = "sans_nom.inr";
  Sinon
    _nom = nom;
  FinSi

  _tx = image->_tx;
  _ty = image->_ty;
  _tz = image->_tz;
  _vdim = vdim;

  _txy = _tx*_ty;
  _taille = (unsigned long) _tx * _ty * _tz;
 
  _size_x = image->_size_x;
  _size_y = image->_size_y;
  _size_z = image->_size_z;

  _translation_x = image->_translation_x;
  _translation_y = image->_translation_y;
  _translation_z = image->_translation_z;

  _format = (WORDTYPE) format;
  Alloue();
  InitPositions();

} // Construteur

#ifndef _WITHOUT_VTK_
//--------------------------------------------------------------------------
InrImage :: Constructeur InrImage( vtkImageData* vtkim)
//                                 --------
{
    int x,y,z,n;
    float val;

  Si vtkim==NULL Alors
    fprintf(stderr,"InrImage::InrImage(vtkImageData*) \t NULL input \n");
    return;
  FinSi


  _tx     = vtkim->GetDimensions()[0];
  _ty     = vtkim->GetDimensions()[1];
  _tz     = vtkim->GetDimensions()[2];
  _txy    = _tx*_ty;
  _taille = (unsigned long) _tx * _ty * _tz;

  
  _vdim = vtkim->GetNumberOfScalarComponents() ;


  SelonQue (vtkim->GetScalarType()) Vaut
    Valeur VTK_DOUBLE:
      Si _vdim==1 Alors 
        _format = WT_DOUBLE;
      Sinon
        _format = WT_DOUBLE_VECTOR;
      FinSi
    FinValeur
    Valeur VTK_FLOAT:
        _format = WT_FLOAT;
    FinValeur
    Valeur VTK_SHORT:
      _format = WT_SIGNED_SHORT;
    FinValeur
    Valeur VTK_UNSIGNED_SHORT:
      _format = WT_UNSIGNED_SHORT;
    FinValeur
    Valeur VTK_INT:
      _format = WT_SIGNED_INT;
    FinValeur
    Valeur VTK_UNSIGNED_INT:
      _format = WT_UNSIGNED_INT;
    FinValeur
    Valeur VTK_UNSIGNED_CHAR:
      Si _vdim==1 Alors 
        _format = WT_UNSIGNED_CHAR;
      Autrement
      Si _vdim==3 Alors 
        _format = WT_RGB;
      Autrement
        fprintf(stderr,"Vector of unsigned char not available \n");
    FinValeur
    Defaut: fprintf(stderr,"type non available \n");
    _format = WT_FLOAT;
  FinSelonQue

  //  printf("dim: %d %d %d ; %d\n", _tx,_ty,_tz, _vdim);
  //  printf("format: %s \n", FormatName()   );

  _amimage = new amimage();   
  AMIFromWT(_vdim,_format,_amimage);
  _amimage->SetDim(_tx,_ty,_tz);
  _amimage->allocate();
   
  _amimage_allocated = true;

  _amimage->SetVX(vtkim->GetSpacing()[0]);
  _amimage->SetVY(vtkim->GetSpacing()[1]);
  _amimage->SetVZ(vtkim->GetSpacing()[2]);

  if (_amimage->GetVX() < 1E-5) _amimage->SetVX(1);
  if (_amimage->GetVY() < 1E-5) _amimage->SetVY(1);
  if (_amimage->GetVZ() < 1E-5) _amimage->SetVZ(1);

  _size_x = _amimage->GetVX();
  _size_y = _amimage->GetVY();
  _size_z = _amimage->GetVZ();

  _amimage->SetTX(vtkim->GetOrigin()[0]);
  _amimage->SetTY(vtkim->GetOrigin()[1]);
  _amimage->SetTZ(vtkim->GetOrigin()[2]);

  _translation_x = vtkim->GetOrigin()[0];
  _translation_y = vtkim->GetOrigin()[1];
  _translation_z = vtkim->GetOrigin()[2];

  InitPositions();

  printf("vox size: %f %f %f \n", _size_x,_size_y,_size_z);


  // Use memcpy() ???
  Si ScalarFormat() Alors
    memcpy(Buffer(), vtkim->GetScalarPointer(), _taille*TailleFormat[_format]*_vdim);    
  Sinon
    InitBuffer();
    Pour(z,0,_tz-1)
    Pour(y,0,_ty-1)
    Pour(x,0,_tx-1)
      Pour(n,0,_vdim-1)
        val = vtkim->GetScalarComponentAsDouble(x,y,z,n);
//        printf("val = %f \n",val);
        VectFixeValeur(n,val);
      FinPour
      IncBuffer();
    FinPour
    FinPour
    FinPour
  FinSi

    //  InitPositions();
} // Constructeur

#endif // _WITHOUT_VTK_

//--------------------------------------------------------------------------
InrImage :: Destructeur InrImage()
//                    -----------
{

  Desalloue();
  EffacePositions();

} // Destructeur


///----------------------------------------------------------------
unsigned char InrImage ::  GetFormatFromAMI(amimage* im, WORDTYPE& type)
//                                   ----------------
{

   switch (im->type) 
     {
     case AMI_SCALAR:
       _vdim = 1;
       switch (im->repres) {
       case AMI_UNSIGNED_CHAR : type = WT_UNSIGNED_CHAR;  return 1;
       case AMI_UNSIGNED_SHORT: type = WT_UNSIGNED_SHORT; return 1;
       case AMI_SIGNED_SHORT  : type = WT_SIGNED_SHORT;   return 1;
       case AMI_UNSIGNED_INT  : type = WT_UNSIGNED_INT;   return 1;
       case AMI_SIGNED_INT    : type = WT_SIGNED_INT;     return 1;
       case AMI_UNSIGNED_LONG : type = WT_UNSIGNED_LONG;  return 1;
       case AMI_SIGNED_LONG   : type = WT_SIGNED_LONG;    return 1;
       case AMI_FLOAT         : type = WT_FLOAT;          return 1; 
       case AMI_DOUBLE        : type = WT_DOUBLE;         return 1;
       default: 
     fprintf(stderr,"repres=%d Format not available \n", im->repres);
     return 0;
       }
       break;
     case AMI_VECTOR:
       _vdim = im->GetVDim();
       switch (im->repres) {
       case AMI_FLOAT  : type = WT_FLOAT_VECTOR;  return 1;
       case AMI_UNSIGNED_CHAR  : 
      if (_vdim==3) {
       type = WT_RGB;  
       return 1;
          }
       default         : 
     fprintf(stderr," AMI_VECTOR: Format not available in InrImage class \n");
     return 0;
       };
       break;
     default:
       fprintf(stderr,"InrImage::GetFormatFromAMI() format not processed ... \n");
     }
   return 0;
   
} // GetFormatFromAMI


///----------------------------------------------------------------
unsigned char InrImage ::  AMIFromWT(int vdim, WORDTYPE type, amimage* amim)
//                                   ---------
{

    if (vdim==1) 
      amim->SetType(AMI_SCALAR); 
    else
      amim->SetType(AMI_VECTOR); 

    switch (type) {
      case WT_UNSIGNED_CHAR :   amim->SetRepres(AMI_UNSIGNED_CHAR);     return 1;
      case WT_UNSIGNED_SHORT:   amim->SetRepres(AMI_UNSIGNED_SHORT);    return 1;
      case WT_SIGNED_SHORT  :   amim->SetRepres(AMI_SIGNED_SHORT);      return 1;
      case WT_UNSIGNED_INT  :   amim->SetRepres(AMI_UNSIGNED_INT);      return 1;
      case WT_SIGNED_INT    :   amim->SetRepres(AMI_SIGNED_INT);        return 1;
      case WT_UNSIGNED_LONG :   amim->SetRepres(AMI_UNSIGNED_LONG);     return 1;
      case WT_SIGNED_LONG   :   amim->SetRepres(AMI_SIGNED_LONG);       return 1;
      case WT_FLOAT         :   amim->SetRepres(AMI_FLOAT);             return 1;
      case WT_DOUBLE        :   amim->SetRepres(AMI_DOUBLE);            return 1;
      case WT_FLOAT_VECTOR  :   amim->SetRepres(AMI_FLOAT);
      amim->SetType(AMI_VECTOR); 
      amim->SetVDim(vdim);
    return 1;
      case WT_RGBA          : 
        amim->SetRepres(AMI_UNSIGNED_CHAR);   
        amim->SetType(AMI_VECTOR); 
        amim->SetVDim(vdim);
        return 1;
      case WT_RGB           : 
        amim->SetRepres(AMI_UNSIGNED_CHAR);   
        amim->SetType(AMI_VECTOR); 
        amim->SetVDim(3);
        return 1;
      default: 
      fprintf(stderr,"repres=%d Format not available \n",
          amim->GetRepres());
      return 0;
    }

} // AMIFromWT()


//----------------------------------------------------------------
void InrImage :: SetAMImage( amimage* amim)
//                         ----------
{
  if (GB_debug) fprintf(stderr,"SetAMImage() begin\n");

  this->_amimage = amim;
  this->_amimage_allocated = true;

  // Convert to InrImage
   if (GB_debug) fprintf(stderr,"SetAMImage() set format\n");
  this->GetFormatFromAMI(amim,this->_format);
   if (GB_debug) fprintf(stderr,"SetAMImage() set translation %f %f %f\n",
    amim->GetTX(),amim->GetTY(),amim->GetTZ());
  this->SetTranslation(amim->GetTX(),amim->GetTY(),amim->GetTZ());
  // Get the transformation matrix
   if (GB_debug) fprintf(stderr,"SetAMImage() set transf matrix\n");
  amim->GetTransfMatrix(this->_transf_matrix);
       
  if (GB_debug) fprintf(stderr,"SetAMImage() set params\n");

  this->_tx     = amim->GetXDim();
  this->_ty     = amim->GetYDim();
  this->_tz     = amim->GetZDim();
  this->_vdim   = amim->GetVDim();
  this->_txy    = this->_tx*this->_ty;
  this->_taille = (unsigned long) this->_tx * this->_ty * this->_tz;


  if (GB_debug) fprintf(stderr,"SetAMImage() set positions\n");

  this->InitPositions();

  if (GB_debug) fprintf(stderr,"SetAMImage() end\n");

} // SetAMImage()


//----------------------------------------------------------------
void InrImage :: SetImageData( int dimx, int dimy, int dimz, 
//                                                    ----------
               WORDTYPE format, void* data, int vdim)
{

  Desalloue();
  EffacePositions();

  _tx = dimx;
  _ty = dimy;
  _tz = dimz;
  _txy = _tx*_ty;
  _taille = (unsigned long) _tx * _ty * _tz;
 
  _size_x = _size_y = _size_z = 1;

  _translation_x =
  _translation_y =
  _translation_z = 0;

  _format = (WORDTYPE) format;

   switch((WORDTYPE) _format) {
    case WT_RGB:          _vdim = 3;    break;
    case WT_RGBA:         _vdim = 4;    break;
    default:              _vdim = vdim;
    }

//  _inrimage = initInrimage( _tx, _ty, _tz, 1, (WORDTYPE) _format );
// ----- Debut init image
  Si _amimage == NULL Alors
  //    cout << "*"<< endl;
    _amimage = new amimage();
    _amimage_allocated = true;
  FinSi

  _amimage->SetDim(_tx,_ty,_tz,_vdim);
  AMIFromWT(_vdim,_format,_amimage);

  // ------ Fin init image 

  _amimage->SetData( data);

  InitPositions();

} // SetImageData()


//----------------------------------------------------------------
void InrImage :: SetImageData( int dimx, int dimy, int dimz, int vdim,
//                         ------------
               WORDTYPE format, void* data)
{

  Desalloue();
  EffacePositions();

  _tx = dimx;
  _ty = dimy;
  _tz = dimz;
  _txy = _tx*_ty;
  _taille = (unsigned long) _tx * _ty * _tz;
 
  _size_x = _size_y = _size_z = 1;

  _translation_x =
  _translation_y =
  _translation_z = 0;

  _format = (WORDTYPE) format;

  _vdim = vdim;

//  _inrimage = initInrimage( _tx, _ty, _tz, 1, (WORDTYPE) _format );
// ----- Debut init image
  Si _amimage == NULL Alors
  //    cout << "*"<< endl;
    _amimage = new amimage();
  FinSi

  _amimage->SetDim(_tx,_ty,_tz);
  AMIFromWT(_vdim,_format,_amimage);

// ------ Fin init image 

  /*
  setInrimageData(_inrimage, data);
  */
  _amimage->SetData( data);

  InitPositions();


} // SetImageData()


//----------------------------------------------------------------
void InrImage :: SetVoxelSize( float sx, float sy, float sz)
//                         ------------------
{

  _size_x = sx;
  _size_y = sy;
  _size_z = sz;

  _amimage->SetVoxelSize(sx,sy,sz);

} // SetVoxelSize()


//----------------------------------------------------------------
void InrImage :: InitImage( double val)
//                         ---------
{

  InitBuffer();
  Repeter
    FixeValeur( val);
  JusquA Non(IncBuffer()) FinRepeter
} // InitImage()


//----------------------------------------------------------------
void InrImage :: InitZero()
//               --------
{
  _amimage->ComputeDataSize();
  memset(_amimage->GetData(),0,_amimage->GetDataSize());
}


//----------------------------------------------------------------
void InrImage :: InitImage( double val0, double val1, double val2)
//                         ---------
{
  InitBuffer();
  Repeter
    VectFixeValeurs( val0, val1, val2);
  JusquA Non(IncBuffer()) FinRepeter
  
} // InitImage()


//----------------------------------------------------------------
// Initialisation tous les voxels a la valeur d'un vecteur
void InrImage::InitImage( double* val, int size)
//   --------
{
  int dim,n;
  if (GetVDim()!=size) 
    printf("Warning \t InrImage::InitImage() vector and image voxels of different sizes \n");

  dim = (GetVDim()>size?GetVDim():size);

  InitBuffer();
  Repeter
    for(n=0;n<dim;n++) 
      VectFixeValeur( n,val[n]);
  JusquA Non(IncBuffer()) FinRepeter
} // InitImage()



//----------------------------------------------------------------
const string InrImage :: FormatName()
//
{

  SelonQue (WORDTYPE) _format Vaut

    Valeur WT_DOUBLE        : return "DOUBLE";        
    Valeur WT_FLOAT         : return "FLOAT";         
    Valeur WT_UNSIGNED_CHAR : return "UNSIGNED CHAR"; 
    Valeur WT_UNSIGNED_SHORT: return "UNSIGNED SHORT";
    Valeur WT_SIGNED_SHORT  : return "SIGNED SHORT";  
    Valeur WT_SIGNED_INT    : return "SIGNED INT";    
    Valeur WT_RGB           : return "RGB";       
    Valeur WT_RGBA          : return "RGBA";
    Valeur WT_FLOAT_VECTOR  : return "FLOAT_VECTOR";  

    Defaut: return "UNKNOWN";
  FinSelonQue  


} // FormatName()


//----------------------------------------------------------------
// Initialisation du buffer correspondant au type de l'image
// a la position souhait�
// Defaut int pos = 0
void InrImage :: InitBuffer( int pos )
//                         ---------
{

  _pos_buf = pos;

  SelonQue (WORDTYPE) _format Vaut

    Valeur WT_DOUBLE:
      _buffer_DOUBLE          = (FORMAT_DOUBLE*)         this->GetData() + _vdim*pos;  
    FinValeur

    Valeur WT_FLOAT:
      _buffer_FLOAT           = (FORMAT_FLOAT*)          this->GetData() + _vdim*pos;  
    FinValeur

    Valeur WT_RGBA:
    Valeur WT_UNSIGNED_CHAR:
      _buffer_UNSIGNED_CHAR   = (FORMAT_UNSIGNED_CHAR*)  this->GetData() + _vdim*pos;  
    FinValeur

    Valeur WT_UNSIGNED_SHORT:
      _buffer_UNSIGNED_SHORT  = (FORMAT_UNSIGNED_SHORT*) this->GetData() + _vdim*pos;  
    FinValeur

    Valeur WT_SIGNED_SHORT:
      _buffer_SIGNED_SHORT    = (FORMAT_SIGNED_SHORT*)  this->GetData() + _vdim*pos;  
    FinValeur

    Valeur WT_UNSIGNED_INT:
      _buffer_UNSIGNED_INT      = (FORMAT_UNSIGNED_INT*)    this->GetData() + _vdim*pos;  
    FinValeur

    Valeur WT_SIGNED_INT:
      _buffer_SIGNED_INT      = (FORMAT_SIGNED_INT*)    this->GetData() + _vdim*pos;  
    FinValeur

    Valeur WT_RGB:
      _buffer_RGB             = (FORMAT_UNSIGNED_CHAR*) this->GetData() + _vdim*pos;  
    FinValeur

    Valeur WT_FLOAT_VECTOR:
      _buffer_FLOAT_VECTOR    = (FORMAT_FLOAT*)          this->GetData() + _vdim*pos;  
    FinValeur

    default:
    fprintf(stderr,"InrImage::InitBuffer() format not processed ... \n");

  FinSelonQue

} // InitBuffer()




//--------------------------------------------------------------------------
InrImage :: operator amimage*()
//                    ---------
{

  return _amimage;

} // operator amimage*()


#ifndef _WITHOUT_VTK_

//--------------------------------------------------------------------------
//
// Allocate and copy the image into a vtkImageData
//
InrImage :: operator vtkImageData*()
//                    ---------
{
    vtkImageData*      vtk_image;
    vtkDataArray*      vtk_scalars;
    int                i,n;

  printf("(vtkImageData*) ...\n");
  // Convert InrImage to vtkImageData
  vtk_image = vtkImageData::New();
  vtk_image->SetDimensions(_tx,_ty,_tz);
  vtk_image->SetSpacing(   _size_x, _size_y, _size_z);
  vtk_image->SetOrigin(this->TrX(),
               this->TrY(),
               this->TrZ());

  SelonQue (WORDTYPE) _format Vaut
     Valeur WT_DOUBLE        : vtk_image->SetScalarType( VTK_DOUBLE); FinValeur
     Valeur WT_FLOAT         : 
     Valeur WT_FLOAT_VECTOR  : vtk_image->SetScalarType(VTK_FLOAT);  FinValeur
     Valeur WT_UNSIGNED_CHAR : 
     Valeur WT_RGB           : vtk_image->SetScalarType(VTK_UNSIGNED_CHAR);  FinValeur
     Valeur WT_UNSIGNED_SHORT: vtk_image->SetScalarType(VTK_UNSIGNED_SHORT); FinValeur
     Valeur WT_SIGNED_SHORT  : vtk_image->SetScalarType(VTK_SHORT);  FinValeur
     Valeur WT_UNSIGNED_INT    : vtk_image->SetScalarType(VTK_UNSIGNED_INT);    FinValeur
     Valeur WT_SIGNED_INT    : vtk_image->SetScalarType(VTK_INT);    FinValeur
     Defaut: printf("InrImage::operator vtkImageData*()\t format non gere...\n");
  FinSelonQue
  
  // interpret 9 components vectors as tensors for now
  if (_vdim==9) {
    vtk_image->AllocateScalars();
    vtkDoubleArray* mat = vtkDoubleArray::New();
    mat->SetNumberOfComponents(9);

    InitBuffer();
    Repeter
      mat->InsertNextTuple9 ( 
        VectValeurBuffer(0), VectValeurBuffer(1), VectValeurBuffer(2),
        VectValeurBuffer(3), VectValeurBuffer(4), VectValeurBuffer(5),
        VectValeurBuffer(6), VectValeurBuffer(7), VectValeurBuffer(8) );
    JusquA Non(IncBuffer()) FinRepeter


    vtk_image->GetPointData()->SetTensors(mat);


  } else {
    int x,y,z;
    vtk_image->SetNumberOfScalarComponents(_vdim);
    vtk_image->AllocateScalars();
    // Essayer memcpy ???
    vtk_scalars = vtk_image->GetPointData()->GetScalars();
    InitBuffer();
    i = 0;
    for(z=0;z<DimZ();z++)
    for(y=0;y<DimY();y++)
    for(x=0;x<DimX();x++) {
      // Flip in Y, only for 2D images???
      BufferPos(x,y,z);
      Si _vdim == 1 Alors
        vtk_scalars->SetTuple1(i,ValeurBuffer());
      Sinon
      Pour(n,0,_vdim-1)
        vtk_scalars->SetComponent(i,n,VectValeurBuffer(n));
      FinPour
      FinSi
      i++;
    }
  }

  return vtk_image;

} // operator vtkImageData*()


//---------------------------------------------------
InrImage :: operator vtkImageData_ptr()
{
  return vtk_new<vtkImageData>()((vtkImageData*)(*this));
}

#endif // _WITHOUT_VTK_

//--------------------------------------------------------------------------
// Defaut char* nom = NULL
unsigned char InrImage :: Sauve( const char* nom )
//                        -----
{

  Si nom!=NULL Alors
    _nom = nom;
  FinSi

  return Ecrit();

}


//--------------------------------------------------------------------------
InrImage* InrImage :: CreeSousImage( int min_x, int max_x, 
//                              -------------
                           int min_y, int max_y,
                           int min_z, int max_z)
{

  
    InrImage*  res;
    int     x,y,z;
//    float      val;

  Si (max_x < min_x) Ou (max_y < min_y) Ou (max_z < min_z) Ou
     (min_x < 0)     Ou (min_y < 0)     Ou (min_z < 0)     Ou
     (max_x > _tx)   Ou (max_y > _ty)   Ou (max_z > _tz)     
  Alors
    return NULL;
  FinSi

  res = new InrImage( max_x - min_x + 1, max_y - min_y + 1, max_z - min_z +1, _format);
  res->SetVoxelSize( _size_x, _size_y, _size_z );

  Pour( z, 0, res->_tz-1 )
  Pour( y, 0, res->_ty-1 )
  Pour( x, 0, res->_tx-1 )

    SelonQue (WORDTYPE) _format Vaut

      Valeur WT_DOUBLE:
        ((FORMAT_DOUBLE*) res->GetData())[ (z*_ty + y)*_tx + x ] = 
        ((FORMAT_DOUBLE*)      this->GetData())
                  [ ((z+min_z)*_ty + (y+min_y))*_tx + x + min_x];
      FinValeur

      Valeur WT_FLOAT:
        ((FORMAT_FLOAT*) res->GetData())[ (z*_ty +  y)*_tx + x ] = 
        ((FORMAT_FLOAT*)      this->GetData())
              [ ((z+min_z)*_ty + (y+min_y))*_tx + x + min_x];
      FinValeur

      Valeur WT_UNSIGNED_CHAR:
        ((FORMAT_UNSIGNED_CHAR*) res->GetData())[ (z*_ty + y)*_tx + x ] =
        ((FORMAT_UNSIGNED_CHAR*)      this->GetData())
              [ ((z+min_z)*_ty + (y+min_y))*_tx + x + min_x];
      FinValeur

      Valeur WT_UNSIGNED_SHORT:
        ((FORMAT_UNSIGNED_SHORT*) res->GetData())[ (z*_ty + y)*_tx + x] = 
        ((FORMAT_UNSIGNED_SHORT*)      this->GetData())
              [ ((z+min_z)*_ty + (y+min_y))*_tx + x + min_x];
      FinValeur

      Valeur WT_SIGNED_SHORT:
        ((FORMAT_SIGNED_SHORT*) res->GetData())[ (z*_ty + y)*_tx + x] = 
        ((FORMAT_SIGNED_SHORT*)      this->GetData())
              [ ((z+min_z)*_ty + (y+min_y))*_tx + x + min_x];
      FinValeur

      Valeur WT_UNSIGNED_INT:
        ((FORMAT_UNSIGNED_INT*) res->GetData())[ (z*_ty + y)*_tx + x] = 
        ((FORMAT_UNSIGNED_INT*)      this->GetData())
              [ ((z+min_z)*_ty + (y+min_y))*_tx + x + min_x];
      FinValeur

      Valeur WT_SIGNED_INT:
        ((FORMAT_SIGNED_INT*) res->GetData())[ (z*_ty + y)*_tx + x] = 
        ((FORMAT_SIGNED_INT*)      this->GetData())
              [ ((z+min_z)*_ty + (y+min_y))*_tx + x + min_x];
      FinValeur

      Defaut: printf("InrImage::CreeSousImage()\t format non g��..\n");

    FinSelonQue

  FinPour // x
  FinPour // y
  FinPour // z
  
  return( res);

} // CreeSousImage()




//--------------------------------------------------------------------------
InrImage* InrImage :: Convert256( float min, float max)
//                              ----------
// Si l'image n'est pas de type WT_UNSIGNED_CHAR, alloue une nouvelle image
// et la convertit en TYPE_UNSIGNED_CHAR
// avec le minimum �0 et le maximum �255
{

  
       FORMAT_UNSIGNED_CHAR*  buf_resultat;
       FORMAT_UNSIGNED_SHORT* buf_UNSIGNED_SHORT;
       FORMAT_SIGNED_SHORT*   buf_SIGNED_SHORT;
       FORMAT_SIGNED_INT*   buf_SIGNED_INT;
       FORMAT_FLOAT*          buf_FLOAT;
       FORMAT_DOUBLE*         buf_DOUBLE;
       long n;
       InrImage*     image_res;
       float          diff;

  Si _format == WT_UNSIGNED_CHAR AlorsRetourne (InrImage*) this;

  image_res = new InrImage( _tx, _ty, _tz, WT_UNSIGNED_CHAR);

  diff = max - min;

  buf_resultat = (FORMAT_UNSIGNED_CHAR*) image_res->Buffer();

  SelonQue (WORDTYPE) _format Vaut

    Valeur WT_DOUBLE:
    //     --------
      buf_DOUBLE = (FORMAT_DOUBLE*) this->GetData();
      DebutBoucle n=0 ItererTantQue n < _tx*_ty*_tz Pas n++ Faire

        Si fabs(diff) < 1E-5 Alors
          *buf_resultat = 0;      
        Autrement    
        Si *buf_DOUBLE <= min Alors
           *buf_resultat = 0;
        Autrement    
        Si *buf_DOUBLE >= max Alors
           *buf_resultat = 255;
        Sinon
          *buf_resultat = (FORMAT_UNSIGNED_CHAR) ( 255 * (*buf_DOUBLE - min) / diff);          
        FinSi

        buf_DOUBLE++;
        buf_resultat++;
      FinBoucle // n
    FinValeur

    Valeur WT_FLOAT:
    //     --------
      buf_FLOAT = (FORMAT_FLOAT*) this->GetData();
      DebutBoucle n=0 ItererTantQue n < _tx*_ty*_tz Pas n++ Faire

        Si fabs(diff) < 1E-5 Alors
          *buf_resultat = 0;      
        Autrement    
        Si *buf_FLOAT <= min Alors
           *buf_resultat = 0;
        Autrement    
        Si *buf_FLOAT >= max Alors
           *buf_resultat = 255;
        Sinon
          *buf_resultat = (FORMAT_UNSIGNED_CHAR) ( 255 * (*buf_FLOAT - min) / diff);          
        FinSi

        buf_FLOAT++;
        buf_resultat++;
      FinBoucle // n
    FinValeur

    Valeur WT_UNSIGNED_SHORT:
    //     ----------
      buf_UNSIGNED_SHORT = (FORMAT_UNSIGNED_SHORT*) this->GetData();
      DebutBoucle n=0 ItererTantQue n < _tx*_ty*_tz Pas n++ Faire
        Si fabs(diff) < 1E-5 Alors
          *buf_resultat = 0;          
        Autrement    
        Si *buf_UNSIGNED_SHORT <= min Alors
           *buf_resultat = 0;
        Autrement    
        Si *buf_UNSIGNED_SHORT >= max Alors
           *buf_resultat = 255;
        Sinon
          *buf_resultat = (FORMAT_UNSIGNED_CHAR) ( 255 * (*buf_UNSIGNED_SHORT - min) / diff);          
        FinSi

        buf_UNSIGNED_SHORT++;
        buf_resultat++;
      FinBoucle // n
    FinValeur

    Valeur WT_SIGNED_SHORT:
    //     -----------
      buf_SIGNED_SHORT = (FORMAT_SIGNED_SHORT*) this->GetData();
      DebutBoucle n=0 ItererTantQue n < _tx*_ty*_tz Pas n++ Faire

        Si fabs(diff) < 1E-5 Alors
          *buf_resultat = 0;          
        Autrement    
        Si *buf_SIGNED_SHORT <= min Alors
           *buf_resultat = 0;
        Autrement    
        Si *buf_SIGNED_SHORT >= max Alors
           *buf_resultat = 255;
        Sinon
          *buf_resultat = (FORMAT_UNSIGNED_CHAR) ( 255 * (*buf_SIGNED_SHORT - min) / diff);          
        FinSi

        buf_SIGNED_SHORT++;
        buf_resultat++;
      FinBoucle // n
    FinValeur

    Valeur WT_SIGNED_INT:
    //     -----------
      buf_SIGNED_INT = (FORMAT_SIGNED_INT*) this->GetData();
      DebutBoucle n=0 ItererTantQue n < _tx*_ty*_tz Pas n++ Faire

        Si fabs(diff) < 1E-5 Alors
          *buf_resultat = 0;          
        Autrement    
        Si *buf_SIGNED_INT <= min Alors
           *buf_resultat = 0;
        Autrement    
        Si *buf_SIGNED_INT >= max Alors
           *buf_resultat = 255;
        Sinon
          *buf_resultat = (FORMAT_UNSIGNED_CHAR) ( 255 * (*buf_SIGNED_INT - min) / diff);          
        FinSi

        buf_SIGNED_INT++;
        buf_resultat++;
      FinBoucle // n
    FinValeur

    Defaut: printf("InrImage::convert256()\t format non g��..\n");

  FinSelonQue

  return image_res;

} // Convert256()


//--------------------------------------------------------------------------
InrImage* InrImage :: Convert256( )
//                              ----------
// Si l'image n'est pas de type WT_UNSIGNED_CHAR, alloue une nouvelle image
// et la convertit en TYPE_UNSIGNED_CHAR
// avec le minimum �0 et le maximum �255
{
  float          min, max;

  MinMax(&min, &max);  
  return Convert256(min, max);

} // Convert256()


//--------------------------------------------------------------------------------------
Chaine* InrImage :: MessageErreur()
//                            -------------
{

  return &_message_erreur;

} // MessageErreur()


//--------------------------------------------------
InrImage* operator -(  InrImage& i1,  InrImage& i2)
//        -----------
{

  InrImage* res;

  Si i1._tx != i2._tx AlorsFait return NULL;
  Si i1._ty != i2._ty AlorsFait return NULL;
  Si i1._tz != i2._tz AlorsFait return NULL;

  WORDTYPE format;

  if ((i1.GetFormat()==WT_DOUBLE)||(i2.GetFormat()==WT_DOUBLE))
    format = WT_DOUBLE;
  else 
    format = WT_FLOAT;

  Si i1.ScalarFormat() Et i2.ScalarFormat() Alors

    res = new InrImage(format,"minusop.inr.gz",&i1);
    res->InitBuffer();
    i1.InitBuffer();                
    i2.InitBuffer();                
    Repeter                           
      res->FixeValeur(i1.ValeurBuffer() - i2.ValeurBuffer()); 
      i1.IncBuffer();               
      i2.IncBuffer();               
    JusquA Non(res->IncBuffer())      
    FinRepeter                        

    return res;

  Autrement
  Si i1.VectorialFormat() Et i2.VectorialFormat() Alors
    int vdim = (i1.GetVDim()<i2.GetVDim()?i1.GetVDim():i2.GetVDim());
    res = new InrImage(format,vdim,"minusop.inr.gz",&i1);
    res->InitBuffer();
    i1.InitBuffer();                
    i2.InitBuffer();                
    Repeter                          
      for(int i=0;i<vdim;i++) 
      res->VectFixeValeur(i,i1.VectValeurBuffer(i) - i2.VectValeurBuffer(i));
      i1.IncBuffer();               
      i2.IncBuffer();               
    JusquA Non(res->IncBuffer())      
    FinRepeter                        

    return res;

  Sinon
    fprintf(stderr,"operator - (InrImage*, InrImage*) \t Error: scalar and vectorial types \n");
  FinSi

  return NULL;
}


//--------------------------------------------------
InrImage* operator -(  InrImage& i1,  double r)
//        -----------
{

  InrImage* res;
  WORDTYPE format;

  if (i1.GetFormat()==WT_DOUBLE)
    format = WT_DOUBLE;
  else 
    format = WT_FLOAT;

  Si i1.ScalarFormat()  Alors

    res = new InrImage(format,"minusop.inr.gz",&i1);
    res->InitBuffer();
    i1.InitBuffer();
    Repeter                           
      res->FixeValeur(i1.ValeurBuffer() - r); 
      i1.IncBuffer();               
    JusquA Non(res->IncBuffer())      
    FinRepeter                        

    return res;

  Autrement
  Si i1.VectorialFormat() Alors

    res = new InrImage(i1._format,"minusop.inr.gz",&i1);
    res->InitBuffer();
    i1.InitBuffer();                
    Repeter                           
      for(int i=0;i<i1.GetVDim();i++)
        res->VectFixeValeur(i,i1.VectValeurBuffer(i) - r);
      i1.IncBuffer();               
    JusquA Non(res->IncBuffer())      
    FinRepeter                        

    return res;

  Sinon
    fprintf(stderr,"operator - (InrImage*, double) \t Error: scalar and vectorial types \n");
  FinSi

  return NULL;
}


//--------------------------------------------------
InrImage* operator +(  InrImage& i1,  InrImage& i2)
//        -----------
{

  InrImage* res;
  int i;
  double val;
  WORDTYPE format;

  if ((i1.GetFormat()==WT_DOUBLE)||(i2.GetFormat()==WT_DOUBLE))
    format = WT_DOUBLE;
  else 
    format = WT_FLOAT;

  Si i1._tx != i2._tx AlorsFait return NULL;
  Si i1._ty != i2._ty AlorsFait return NULL;
  Si i1._tz != i2._tz AlorsFait return NULL;

  Si i1.ScalarFormat() Et i2.ScalarFormat() Alors
    res = new InrImage(format,"plusop.inr.gz",&i1);
    res->InitBuffer();
    i1.InitBuffer();                
    i2.InitBuffer();                
    Repeter                           
      res->FixeValeur(i1.ValeurBuffer() + i2.ValeurBuffer()); 
      i1.IncBuffer();               
      i2.IncBuffer();               
    JusquA Non(res->IncBuffer())      
    FinRepeter                        

    return res;

  Autrement
  Si i1.VectorialFormat() Et i2.VectorialFormat() Alors

    Si i1.GetVDim() != i2.GetVDim() Alors
      fprintf(stderr,"InrImage*InrImage \t Vector dimensions don't match \n");
      return NULL;
    FinSi

    res = new InrImage(i1._format,"plusop.inr.gz",&i1);
    res->InitBuffer();
    i1.InitBuffer();                
    i2.InitBuffer();                
    Repeter                           
      Pour(i,0,i1.GetVDim()-1)
        val = i1.VectValeurBuffer(i)+i2.VectValeurBuffer(i);
        res->VectFixeValeur(i,val);
      FinPour
      i1.IncBuffer();               
      i2.IncBuffer();               
    JusquA Non(res->IncBuffer())      
    FinRepeter                        

    return res;

  Sinon
    fprintf(stderr,"operator + (InrImage*, InrImage*) \t Error: scalar and vectorial types \n");
  FinSi

  return NULL;
}


//--------------------------------------------------
InrImage* operator *(  InrImage& i1,  InrImage& i2)
//        -----------
{

  InrImage* res;
  double val;
  double val1;
  double val2;
  long   i;

  Si i1._tx != i2._tx AlorsFait return NULL;
  Si i1._ty != i2._ty AlorsFait return NULL;
  Si i1._tz != i2._tz AlorsFait return NULL;

  WORDTYPE format;
  if ((i1.GetFormat()==WT_DOUBLE)||(i2.GetFormat()==WT_DOUBLE))
    format = WT_DOUBLE;
  else 
    format = WT_FLOAT;

  Si i1.ScalarFormat() Et i2.ScalarFormat() Alors

    res = new InrImage(format,1,"multop.inr.gz",&i1);
    res->InitBuffer();
    i1.InitBuffer();                
    i2.InitBuffer();                
    Pour(i,0,i1.Size()-1)
      res->FixeValeur(i1.ValeurBuffer(i) * i2.ValeurBuffer(i)); 
      res->IncBuffer();
    FinPour

    return res;

  Autrement
  Si i1.VectorialFormat() Et i2.VectorialFormat() Alors
    printf("dim im1 = %d \n",i1.GetVDim());
    printf("dim im2 = %d \n",i2.GetVDim());
    Si i1.GetVDim() != i2.GetVDim() Alors
      fprintf(stderr,"InrImage*InrImage \t Vector dimensions don't match \n");
      return NULL;
    FinSi
    res = new InrImage(format,1,"scalar.inr.gz",&i1);
    res->InitBuffer();
    i1.InitBuffer();                
    i2.InitBuffer();                
    Repeter
      val = 0;
      Pour(i,0,i1.GetVDim()-1)
        val += i1.VectValeurBuffer(i)*i2.VectValeurBuffer(i);
      FinPour
      res->FixeValeur(val);
      i1.IncBuffer();               
      i2.IncBuffer();               
    JusquA Non(res->IncBuffer())      
    FinRepeter                        

    return res;

  Sinon
    // i1 vectorial and i2 scalar
    Si i1.VectorialFormat() Alors
      res = new InrImage(format,i1.GetVDim(),"prod.inr.gz",&i1);
      res->InitBuffer();
      i1.InitBuffer();                
      i2.InitBuffer();                
      Repeter                           
    val2 = i2.ValeurBuffer();
        Pour(i,0,i1.GetVDim()-1)
      val = i1.VectValeurBuffer(i)*val2;
      res->VectFixeValeur(i,val);
        FinPour
        i1.IncBuffer();
        i2.IncBuffer();               
      JusquA Non(res->IncBuffer())      
      FinRepeter

      return res;

    Sinon
    // i2 vectorial and i1 scalar
      res = new InrImage(format,i2.GetVDim(),"prod.inr.gz",&i2);
      res->InitBuffer();
      i1.InitBuffer();                
      i2.InitBuffer();                
      Repeter                           
    val1 = i1.ValeurBuffer();
        Pour(i,0,i2.GetVDim()-1)
      val = i2.VectValeurBuffer(i)*val1;
      res->VectFixeValeur(i,val);
        FinPour
        i1.IncBuffer();
        i2.IncBuffer();               
      JusquA Non(res->IncBuffer())      
      FinRepeter                        

      return res;

    FinSi

  FinSi

  return NULL;

}


//--------------------------------------------------
InrImage* operator /(  InrImage& i1,  InrImage& i2)
//        -----------
{

  InrImage* res;
  float val;
  float val1;
  float val2;
  long   i;

  Si i1._tx != i2._tx AlorsFait return NULL;
  Si i1._ty != i2._ty AlorsFait return NULL;
  Si i1._tz != i2._tz AlorsFait return NULL;

  WORDTYPE format;
  if ((i1.GetFormat()==WT_DOUBLE)||(i2.GetFormat()==WT_DOUBLE))
    format = WT_DOUBLE;
  else 
    format = WT_FLOAT;

  Si i1.ScalarFormat() Et i2.ScalarFormat() Alors

    res = new InrImage(format,"multop.inr.gz",&i1);
    res->InitBuffer();
    i1.InitBuffer();                
    i2.InitBuffer();                
    Pour(i,0,i1.Size()-1)
      if (fabsf(i2.ValeurBuffer(i))>0)
    res->FixeValeur(i1.ValeurBuffer(i) / i2.ValeurBuffer(i)); 
      res->IncBuffer();
    FinPour

    return res;

  Autrement
  Si i1.VectorialFormat() Et i2.VectorialFormat() Alors
    fprintf(stderr,"InrImage/InrImage \t no vector/vector operation \n");
    return NULL;

  Sinon
    // i1 vectorial and i2 scalar
    Si i1.VectorialFormat() Alors
      res = new InrImage(format,i1.GetVDim(),"prod.inr.gz",&i1);
      res->InitBuffer();
      i1.InitBuffer();                
      i2.InitBuffer();                
      Repeter                           
    val2 = i2.ValeurBuffer();
        Pour(i,0,i1.GetVDim()-1)
      if (fabsf(val2)>0)
        val = i1.VectValeurBuffer(i)/val2;
      else
        val = 0;
      res->VectFixeValeur(i,val);
        FinPour
        i1.IncBuffer();
        i2.IncBuffer();               
      JusquA Non(res->IncBuffer())      
      FinRepeter

      return res;

    Sinon
    // i2 vectorial and i1 scalar
      res = new InrImage(format,i2.GetVDim(),"prod.inr.gz",&i2);
      res->InitBuffer();
      i1.InitBuffer();                
      i2.InitBuffer();                
      Repeter                           
    val1 = i1.ValeurBuffer();
        Pour(i,0,i2.GetVDim()-1)
      if (fabsf(val1)>0)
        val = i2.VectValeurBuffer(i)/val1;
      else
        val = 0;
      res->VectFixeValeur(i,val);
        FinPour
        i1.IncBuffer();
        i2.IncBuffer();               
      JusquA Non(res->IncBuffer())      
      FinRepeter                        

      return res;

    FinSi

  FinSi

  return NULL;

}


//--------------------------------------------------
InrImage* operator ^(  InrImage& i1,  InrImage& i2)
//        -----------
{

  InrImage* res;
  register float ux,uy,uz,vx,vy,vz;

  Si i1._tx != i2._tx AlorsFait return NULL;
  Si i1._ty != i2._ty AlorsFait return NULL;
  Si i1._tz != i2._tz AlorsFait return NULL;

  WORDTYPE format;
  if ((i1.GetFormat()==WT_DOUBLE)||(i2.GetFormat()==WT_DOUBLE))
    format = WT_DOUBLE;
  else 
    format = WT_FLOAT;

  Si i1.ScalarFormat() Ou i2.ScalarFormat() Alors

    return NULL;

  Autrement
  Si i1.VectorialFormat() Et i2.VectorialFormat() Alors

    Si i1.GetVDim()!=3 Ou i2.GetVDim()!=3 Alors
      fprintf(stderr,"operator^(InrImage,InrImage) \t only for dimension 3 vectors \n");
      return NULL;
    FinSi

    res = new InrImage(format,3,"vect_prod.ami.gz",&i1);
    res->InitBuffer();
    i1.InitBuffer();                
    i2.InitBuffer();                
    Repeter
      ux = i1.VectValeurBuffer(0);
      uy = i1.VectValeurBuffer(1);
      uz = i1.VectValeurBuffer(2);

      vx = i2.VectValeurBuffer(0);
      vy = i2.VectValeurBuffer(1);
      vz = i2.VectValeurBuffer(2);

      res->VectFixeValeurs(uy*vz-uz*vy,
               uz*vx-ux*vz,
               ux*vy-uy*vx);

      i1.IncBuffer();               
      i2.IncBuffer();               
    JusquA Non(res->IncBuffer())      
    FinRepeter                        

    return res;

  FinSi

  return NULL;

}



// Norm (for vectorial images) or absolute value for scalars
InrImage* Norm(  InrImage& i1)
{

  InrImage* res;

  Si i1.ScalarFormat() Alors

    res = new InrImage(WT_FLOAT,"norm.ami.gz",&i1);
    res->InitBuffer();
    i1.InitBuffer();                
    Repeter
      res->FixeValeur(fabsf(i1.ValeurBuffer()));
      i1.IncBuffer();               
    JusquA Non(res->IncBuffer())      
    FinRepeter                        
    return res;

  Autrement
  Si i1.VectorialFormat() Alors

    double n2,tmp; 
    int i;

    res = new InrImage(WT_FLOAT,1,"norm.ami.gz",&i1);
    res->InitBuffer();
    i1.InitBuffer();                
    Repeter
      n2 = 0;
      for(i=0;i<i1.GetVDim();i++) { 
        tmp = i1.VectValeurBuffer(i);
        n2 += tmp*tmp;
      }

      res->FixeValeur(sqrt(n2));

      i1.IncBuffer();               
    JusquA Non(res->IncBuffer())      
    FinRepeter                        

    return res;

  FinSi

  return NULL;

}

#define ami_malloc2d(direccion,tipo,height,width) {int ml; \
          direccion=(tipo **) malloc(sizeof(tipo *)*(height)); \
          direccion[0]=(tipo *)malloc(sizeof(tipo)*(width)*(height)); \
          for(ml=0;ml<(height);ml++) direccion[ml]=&(direccion[0][ml*(width)]);\
        }
#define ami_malloc2d_punteros(direccion,puntero_simple,tipo,height,width) {int ml; \
          direccion=(tipo **) malloc(sizeof(tipo *)*(height)); \
          direccion[0]=(tipo *) puntero_simple; \
          for(ml=0;ml<(height);ml++) direccion[ml]=&(direccion[0][ml*(width)]);\
        }
#define ami_free2d(direccion) { free(direccion[0]); free(direccion); }
#define ami_free2d_punteros(direccion) { free(direccion); }

float** InrImage::create_float_positions_2D(int order) {
    float** pos;
    int     i,j;

    // make allocations and copies to avoid problems ???
    // could create memory problems ...
    // libami convention:  columns index first ...
    // amimage convention: line index first ...

    if (order==0) {
    ami_malloc2d(pos,float,this->DimX(),this->DimY());
    this->InitBuffer();
    for(j=0;j<DimY();j++)
      for(i=0;i<DimX();i++) {
        pos[i][j] = this->ValeurBuffer();
    this->IncBuffer();
    }
    } else {
      ami_malloc2d(pos,float,this->DimY(),this->DimX());
      this->InitBuffer();
      for(j=0;j<DimY();j++)
    for(i=0;i<DimX();i++) {
    pos[j][i] = this->ValeurBuffer();
    this->IncBuffer();
    }
    }
    
    return pos;
}

// free the positions and copy the values to the image
void    InrImage::free_float_positions_2D(float** pos, int order)
{
  int     i,j;
  
  if (order==0) {
    this->InitBuffer();
    for(j=0;j<DimY();j++)
      for(i=0;i<DimX();i++) {
      this->FixeValeur(pos[i][j]);
      this->IncBuffer();
      }
  } else {
    this->InitBuffer();
    for(j=0;j<DimY();j++)
      for(i=0;i<DimX();i++) {
      this->FixeValeur(pos[j][i]);
      this->IncBuffer();
      }
  }
  
  ami_free2d(pos);
}


