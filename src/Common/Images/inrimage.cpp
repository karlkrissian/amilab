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

#include <iomanip>
#include <cassert>
#include "boost/format.hpp"

#include "AMILabConfig.h"

#ifdef AMI_USE_VTK
  //#include <vtkImageWriter.h> 
  #include "vtkStructuredPointsReader.h"
  #include "vtkStructuredPointsWriter.h"
  #include "vtkImageReader2Factory.h"
  #include "vtkImageReader2.h"
  #include "vtkJPEGWriter.h"
  #include "vtkTIFFWriter.h"
  #include "vtkPNGWriter.h"
  #include <vtkTIFFReader.h>
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
#endif // AMI_USE_VTK



#include <boost/scoped_array.hpp>
using namespace boost;

#include "style.hpp"
#include "inrimage.hpp"

#include "InrImageIterator.h"
#include "InrImageConstIterator.h"

#include "amimage.hpp"
#include "StringUtils.hpp"

#include "math1.hpp"


#ifdef AMI_USE_ITK
  #include "ami_itkRead.h"
  #include "ami_itkWrite.h"
#endif // AMI_USE_ITK

#if defined(_MSC_VER) 
//|| defined(__MINGW32__)
int rint(const float& a)
{
  return (int) floor(a+0.5);
}

/* roundf defined now in math1.cpp
float roundf(const float& a)
{
  return (float) floor(a+0.5);
}
*/
#endif

#include "amilab_messages.h"

#include "ImagePositions.h"
#include "InrImageIteratorBase.h"
#include "InrImageIterator.h"

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


InrImage::DepassementLimites::DepassementLimites( const std::string message)
{
  std::cout << "InrImage "
          << " Out of image limits"
      << "\t " << message  << std::endl;
}


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
    
    //   std::cout << "guardando: " << name << " size:" << w << "*" << h << std::endl;
    
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

  CLASS_MESSAGE(_nom.c_str());

  // Read AMImage
  boost::shared_ptr<amimage> im (new amimage());
  res = im->read( (char*) _nom.c_str());

  if ( res ) {

    //      im.displayinfo();
    res = GetFormatFromAMI(im.get(),_format);

    _translation_x = im->GetTX();
    _translation_y = im->GetTY();
    _translation_z = im->GetTZ();

    // Get the transformation matrix
    im->GetTransfMatrix(_transf_matrix);

    if ( res ) {
        _tx     = im->GetXDim();
        _ty     = im->GetYDim();
        _tz     = im->GetZDim();
        _vdim   = im->GetVDim();
        _txy    = _tx*_ty;
        _taille = (unsigned long) _tx * _ty * _tz;

        _amimage = im;
        //_amimage_allocated = true;

    }    // end if

  } // end if


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

    CLASS_MESSAGE((boost::format("tz = %d") % tz).str().c_str());

    _vdim = 3;
    _amimage = boost::shared_ptr<amimage>(new amimage());
    _amimage->SetDim( image->columns,  image->rows, tz,_vdim);
    _amimage->SetType(AMI_VECTOR);
    _amimage->SetRepres(AMI_UNSIGNED_CHAR);
    _amimage->allocate();
    //_amimage_allocated = true;

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

    for(z=0;z<=tz-1;z++) {

      if ( (image != (const Image *) NULL) ) {

        GetPixels( image,
           red_pixels,
           green_pixels,
           blue_pixels,
           NULL);

        //
        InitBuffer(z*_txy);
        for(i=0;i<=_txy-1;i++) {
          VectFixeValeurs( 255*red_pixels[i],
               255*green_pixels[i], 
               255*blue_pixels[i]
               );
          IncBuffer();
        } // endfor

        image = image->next;

      } // end if

    } // endfor

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

#ifdef AMI_USE_VTK
  
   shared_ptr<vtkStructuredPointsReader> reader = vtk_new<vtkStructuredPointsReader>()();
    vtkStructuredPoints* in;
    int       x,y,z,n;

  CLASS_MESSAGE((boost::format("InrImage::ReadVTK()  begin ")).str().c_str());

  reader->SetFileName((char*) _nom.c_str());
  reader->Update();

  in = reader->GetOutput();

  if (reader->GetErrorCode()!=0) { 
    return false; 
  }

  _vdim = in->GetNumberOfScalarComponents();
  CLASS_MESSAGE((boost::format("vdim = %d") % _vdim).str().c_str());

  // Check for Tensor data
  vtkPointData* pd = in->GetPointData();
  if (pd==NULL) 
    CLASS_ERROR((boost::format("not point data")).str().c_str());
  vtkDataArray* tensor = pd->GetTensors();

  if (tensor!=NULL) {
    _vdim = tensor->GetNumberOfComponents();
    CLASS_MESSAGE((boost::format("Reading Tensor data (size %d)") % _vdim).str().c_str())
  }

  switch ( (in->GetScalarType()) ){
    case VTK_FLOAT:          _format = WT_FLOAT;
    break;
    case VTK_UNSIGNED_SHORT: _format = WT_UNSIGNED_SHORT;
    break;
    case VTK_SHORT:          _format = WT_SIGNED_SHORT;
    break;
    case VTK_UNSIGNED_INT:   _format = WT_UNSIGNED_INT;
    break;
    case VTK_INT:            _format = WT_SIGNED_INT;
    break;
    case VTK_UNSIGNED_CHAR:
     switch (_vdim) {
       case 1: _format = WT_UNSIGNED_CHAR; break;
       case 3: _format = WT_RGB; break;
       default: 
          CLASS_ERROR((boost::format("Non-scalar UCHAR vdim=%1% !=3 not available")%_vdim).str().c_str());
     }
    break;

    case VTK_DOUBLE:
     _format = WT_DOUBLE;
    break;

    default: 
      CLASS_ERROR((boost::format("Scalar type %1% non available")
                           % in->GetScalarType()).str().c_str());
    _format = WT_FLOAT;

  } // end switch

  CLASS_MESSAGE("1");

  _tx     = in->GetDimensions()[0];
  _ty     = in->GetDimensions()[1];
  _tz     = in->GetDimensions()[2];
  _txy    = _tx*_ty;
  _taille = (unsigned long) _tx * _ty * _tz;


  CLASS_MESSAGE((boost::format(" %d %d %d ") % _tx % _ty % _tz).str().c_str());

    _amimage = boost::shared_ptr<amimage>(new amimage());
    _amimage->SetDim( _tx, _ty, _tz, _vdim);
    AMIFromWT(_vdim,_format,_amimage.get());
    if (_amimage->allocate()) {

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
      for(z=0;z<=_tz-1;z++) {
        pos[2]=z;
        //printf("Converting VTK to ami z = %d \n",z);
      for(y=0;y<=_ty-1;y++) {
        pos[1]=y; // Flip in Y ???
      for(x=0;x<=_tx-1;x++) {
        pos[0] = x;
        inPtId = in->ComputePointId(pos);
        if (tensor!=NULL) {
          tensor->GetTuple(inPtId, t);
          for(n=0;n<=_vdim-1;n++) {
            VectFixeValeur(n,t[n]);
          } // endfor
        } else 
        if (_vdim==1) {
          scalars->GetTuple(inPtId, val.get());
          FixeValeur(*val.get());
        } else {
          scalars->GetTuple(inPtId, val.get());
          for(n=0;n<=_vdim-1;n++) {
            VectFixeValeur(n,val[n]);
          } // endfor
        }
        IncBuffer();
      } // endfor
      } // endfor
      } // endfor
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
#endif // AMI_USE_VTK
  
  
} // ReadVTK()


//--------------------------------------------------------------------------
unsigned char InrImage :: ReadVTKImage( ) throw (ErreurLecture)
//                           ------------
{

#ifdef AMI_USE_VTK

    vtkImageData* in;
    int       x,y,z,n;

  CLASS_MESSAGE("begin");

  shared_ptr<vtkImageReader2Factory> create_reader = vtk_new<vtkImageReader2Factory>()();
//cout << "0.1" << std::endl;
  vtkImageReader2* imreader = create_reader->CreateImageReader2( _nom.c_str()); 
//cout << "0.2" << std::endl;
  if (imreader==NULL) {
    CLASS_MESSAGE("No reader found from vtkImageReader2Factory")
    return false;
  }
//cout << "1" << std::endl;
  shared_ptr<vtkImageReader2> reader = vtk_new<vtkImageReader2>()(imreader);

// std::cout << "2" << std::endl;

  reader->SetFileName(_nom.c_str());
  reader->Update();

 std::cout << "GetFileLowerLeft() = " << reader->GetFileLowerLeft() << std::endl;
 std::cout << "Reader is [" << reader->GetDescriptiveName() << "]" << std::endl;

  in = reader->GetOutput();

  std::string readername = reader->GetDescriptiveName();
  if (readername.compare("TIFF")) {
    // get specific tiff information?
    vtkTIFFReader* tiffreader = (dynamic_cast<vtkTIFFReader*> (reader.get()));
    //cout << "GetOrientationType =" << tiffreader->GetOrientationType() << std::endl;
  }

  if (reader->GetErrorCode()!=0) { 
    return false; 
  }

  _vdim = in->GetNumberOfScalarComponents();

  switch ( (in->GetScalarType()) ){

    case VTK_FLOAT:
     switch (_vdim) {
       case 1: _format = WT_FLOAT; break;
       default: _format = WT_FLOAT_VECTOR; break;
     }
     
    break;
    case VTK_UNSIGNED_SHORT:
      _format = WT_UNSIGNED_SHORT;
    break;
    case VTK_SHORT:
      _format = WT_SIGNED_SHORT;
    break;
    case VTK_UNSIGNED_INT:
      _format = WT_UNSIGNED_INT;
    break;
    case VTK_INT:
      _format = WT_SIGNED_INT;
    break;
    case VTK_UNSIGNED_CHAR:
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
    break;

    default:   
      CLASS_ERROR("type not available");
      _format = WT_FLOAT;

  } // end switch

  CLASS_MESSAGE("1");

  _tx     = in->GetDimensions()[0];
  _ty     = in->GetDimensions()[1];
  _tz     = in->GetDimensions()[2];
  _txy    = _tx*_ty;
  _taille = (unsigned long) _tx * _ty * _tz;


  CLASS_MESSAGE((boost::format(" image size: %d x %d x %d ") % _tx % _ty % _tz).str().c_str());

    _amimage = boost::shared_ptr<amimage>(new amimage());
    _amimage->SetDim( _tx, _ty, _tz, _vdim);
    AMIFromWT(_vdim,_format,_amimage.get());
    if (_amimage->allocate()) {

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
      for(z=0;z<=_tz-1;z++) {
        pos[2]=z;
        //printf("Converting VTK to ami z = %d \n",z);
      for(y=0;y<=_ty-1;y++) {
        pos[1]=_ty-1-y; //    flip in Y
      for(x=0;x<=_tx-1;x++) {
        pos[0] = x;
        inPtId = in->ComputePointId(pos);
        if (_vdim==1) {
          scalars->GetTuple(inPtId, val.get());
          FixeValeur(*val.get());
        } else {
          scalars->GetTuple(inPtId, val.get());
          for(n=0;n<=_vdim-1;n++) {
            VectFixeValeur(n,val[n]);
          } // endfor
        }
        IncBuffer();
      } // endfor
      } // endfor
      } // endfor
    }
    else {
      CLASS_ERROR("allocation problem");
      return false;
    }

  if ( GB_debug )  fprintf(stderr,"InrImage::ReadVTKImage()  3 \n");
  if ( GB_debug )  fprintf(stderr,"InrImage::ReadVTKImage()  end \n");

  return true;

#else
  CLASS_ERROR(" AMILab compiled without VTK, function not available");
  return false;
#endif // AMI_USE_VTK

} // ReadVTKImage()


//--------------------------------------------------------------------------
unsigned char InrImage :: Read( ) throw (ErreurLecture)
//                           ---
{

//  inrimage* ptr;
  unsigned char   res; 

  CLASS_MESSAGE("Begin");

  res = ReadAMI();

/*
  if ( !(res) ) {
    if ( (_nom == "<") ) {
      // entree standard
      ptr = readZInrimage( NULL);
    } else {
      ptr = readZInrimage( (char*) _nom);
    } // end if

    if ( ptr != NULL ) {
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
    } // end if
  } // end if
*/

  //  if ( ptr == NULL ) {
#ifdef USE_MAGICK
  if (!res) { 
    CLASS_MESSAGE("Trying to read with ImageMagick");  
    res = ReadMagick();
  }
#endif // USE_MAGICK

#ifdef AMI_USE_ITK
  // trying with ITK
  if (!res) {
    InrImage* tmpim = itkRead(_nom);
    res = (tmpim!=NULL);
    if (res) {
      // need to allocate the image first
      _tx     = tmpim->_tx;
      _ty     = tmpim->_ty;
      _tz     = tmpim->_tz;
      _vdim   = tmpim->_vdim;
      _format = tmpim->_format;
      _txy    = _tx*_ty;
      _taille = (unsigned long) _tx * _ty * _tz;

      _amimage = boost::shared_ptr<amimage>(new amimage());
      _amimage->SetDim( _tx, _ty, _tz, _vdim);
      AMIFromWT(_vdim,_format,_amimage);
      if (_amimage->allocate()) {
        SetVoxelSize(tmpim->VoxSizeX(),tmpim->VoxSizeY(),tmpim->VoxSizeZ());
        SetTranslation(tmpim->TrX(),tmpim->TrY(),tmpim->TrZ());
        (*this) = (*tmpim);
        delete tmpim;
      }
    }
  }
#endif

  // try with the vtk image reader factory
  if (!res) {
   std::cout << "Trying reading with VTK image factory" << std::endl;  
    res = ReadVTKImage();
  }

  if (!res) {
    CLASS_MESSAGE("Trying reading with ReadVTK");  
    res = ReadVTK();
  }


  if ( !res ) {
    std::cerr << " Error reading image " << std::endl;
    throw ErreurLecture();
  } // end if


  return (res);

} // Read()


//--------------------------------------------------------------------------
unsigned char InrImage :: LitEntete( )  throw (ErreurLecture)
//                           ---------
{

//  INRIMAGE_HEADER* ptr;
//  inrimage*        ptr_image;

//  printf("lecture de l'ent�e de %s \n", (char*) _nom);

/*
  if ( (_nom == "<") ) {
    // entree standard
    printf("InrImage::LitEntete()\t on ne lit pas que ");
    printf("l'entete sur l'entree standard\n");
    ptr_image = readZInrimage( NULL);
//    _inrimage_allouee = true;
  } else {
    ptr = readZInrimageHeader( (char*) _nom);
    ptr_image = ptr->inr;
//    _inrimage_allouee = false;
  } // end if

  if ( ptr_image == NULL ) {
  //    E_SETERR(E_ERRR, "reading in file", (char*) _nom);
    throw ErreurLecture();
  } // end if


  // put the information in the _amimage member and free the pointer

  _format = ptr_image->type;

  if (_amimage==NULL)
    _amimage = new amimage();

  _amimage->SetDim(ptr_image->ncols, ptr_image->nrows, ptr_image->nplanes );
  AMIFromWT(ptr_image->vdim,ptr_image->type,_amimage);
  _amimage->SetVoxelSize(ptr_image->vx,ptr_image->vy,ptr_image->vz);

  free(ptr_image);
*/

  return true;

} // LitEntete()


//--------------------------------------------------------------------------
unsigned char InrImage :: Alloue( ) throw (ErreurAllocation)
//                           ------ 
{

// std::cout << "allocation de "  <<  _nom << " \t taille = "
//       <<  (long int ) _tx*_ty*_tz*TailleFormat[_format]  
//       << "( " << _tx << ", " << _ty << ", " << _tz << ")"
//       << " " <<  TailleFormat[_format]  
//       << std::endl;

  if ( _vdim == 1 ) {
    switch ( (WORDTYPE) _format ){

      case WT_DOUBLE:        
      case WT_FLOAT:         
      case WT_UNSIGNED_CHAR: 
      case WT_UNSIGNED_SHORT:
      case WT_SIGNED_SHORT:  
      case WT_UNSIGNED_INT: 
      case WT_SIGNED_INT:  _vdim = 1;
      break;

      case WT_RGB:
        _vdim = 3;
      break;
      default:  _vdim=1;

    } // end switch
  } // end if

  _amimage = boost::shared_ptr<amimage>(new amimage());
  _amimage->SetDim(_tx,_ty,_tz, _vdim );
  AMIFromWT(_vdim,_format,_amimage);
  _amimage->SetVoxelSize(_size_x,_size_y,_size_z);
  _amimage->SetTranslation(_translation_x,
               _translation_y,
               _translation_z);
  CLASS_MESSAGE((boost::format("Allocation of image %1%")%_nom).str().c_str());
  bool ok = _amimage->allocate();

  if ( !ok ) {
    CLASS_ERROR( (boost::format(" Image allocation problem for image %1%") % _nom).str().c_str() );
    throw ErreurAllocation();
  } // end if


  return true;

} // Alloue()


//--------------------------------------------------------------------------
 unsigned char InrImage :: Ecrit( ) throw( ImageWriteError)
//                           -----     
{

  
#ifdef AMI_USE_VTK
    vtkImageData_ptr   vtk_id;
#endif
//    inrimage*       inrimage_ptr;
    char  name[200];


  strcpy(name,_nom.c_str());
  RemoveEndString(name,".gz");

/*
  if ( (CheckEndString( name, ".inr"))||(CheckEndString( name, ".hdr")) ) {
    // Convert to inrimage first ...
    inrimage_ptr = (inrimage*) (*this);
    if ( (writeZInrimage( inrimage_ptr, (char*) _nom)<0) ) {
      throw ImageWriteError();
    } // end if
    // delete inrimage_ptr ?
    free(inrimage_ptr);
    //  freeInrimage(inrimage_ptr);
  } else
*/

  if (CheckEndString( name, ".ami"))   {
    return _amimage->write((char*) _nom.c_str());
  } else
  if ( (CheckEndString( name, ".raw"))  ) {
    // write only raw data
    return _amimage->write((char*) _nom.c_str(),0);
  } else
#ifdef AMI_USE_ITK
  // here need to check using MetaDataDictionary
/*
if (  CheckEndString( name, ".mhd")  || 
        CheckEndString( name, ".jpg")  ||  
        CheckEndString( name, ".jpeg") ||
        CheckEndString( name, ".tif")  ||  
        CheckEndString( name, ".tiff") ||
        CheckEndString( name, ".png")  ||  
        CheckEndString( name, ".bmp")  ||
        CheckEndString( name, ".hdr")  
     ) 
  {
    return itkWrite(this,_nom);
  } else
    */
  // better support itk types by not limiting the possible extensions here
  if (itkWrite(this,_nom))
    return true;
  else
#else
#endif // AMI_USE_ITK

#ifdef AMI_USE_VTK
  if ( (CheckEndString( name, ".vtk")) ) {
    shared_ptr<vtkStructuredPointsWriter> vtk_iw;
    vtk_id = (vtkImageData_ptr) (*this);
    vtk_iw = vtk_new<vtkStructuredPointsWriter>()();

    vtk_iw->SetInput(vtk_id.get());
    vtk_iw->SetFileName( _nom.c_str());
    vtk_iw->SetFileTypeToBinary();
//    vtk_iw->SetFileDimensionality(3);

    vtk_iw->Write();

  } else
  // Use VTK for writing jpeg if possible
  if ( (CheckEndString( name, ".jpg") || 
      CheckEndString( name, ".jpeg")) ) {
    vtk_id    = (vtkImageData_ptr) (*this);
    shared_ptr<vtkJPEGWriter> vtk_jpegw = vtk_new<vtkJPEGWriter>()();

    shared_ptr<vtkImageFlip> flipY = vtk_new<vtkImageFlip>()();
    flipY->SetInput(vtk_id.get());
    flipY->SetFilteredAxis(1);
    flipY->Update();

    vtk_jpegw->SetInput(flipY->GetOutput());
//    vtk_jpegw->SetInput(vtk_id.get());
    vtk_jpegw->SetFileName((char*) _nom.c_str());
    vtk_jpegw->Write();

  } else
  if ( (CheckEndString( name, ".tiff") || CheckEndString( name, ".tif")) ) {
    vtk_id = (vtkImageData_ptr) (*this);
    shared_ptr<vtkTIFFWriter> vtk_tiffw = vtk_new<vtkTIFFWriter>()();

    shared_ptr<vtkImageFlip> flipY = vtk_new<vtkImageFlip>()();
    flipY->SetInput(vtk_id.get());
    flipY->SetFilteredAxis(1);
    flipY->Update();

    vtk_tiffw->SetInput(flipY->GetOutput());
//    vtk_tiffw->SetInput(vtk_id.get());
    vtk_tiffw->SetFileName((char*) _nom.c_str());
    vtk_tiffw->Write();

  } else
  if ( (CheckEndString( name, ".png") || CheckEndString( name, ".PNG")) ) {
    vtk_id = (vtkImageData_ptr) (*this);
    shared_ptr<vtkPNGWriter> vtk_pngw = vtk_new<vtkPNGWriter>()();

    shared_ptr<vtkImageFlip> flipY = vtk_new<vtkImageFlip>()();
    flipY->SetInput(vtk_id.get());
    flipY->SetFilteredAxis(1);
    flipY->Update();

    vtk_pngw->SetInput(flipY->GetOutput());
//    vtk_pngw->SetInput(vtk_id.get());
    vtk_pngw->SetFileName((char*) _nom.c_str());
    vtk_pngw->Write();
//    flipY->Delete();
  } else
#endif // AMI_USE_VTK
  {
//  if ( (CheckEndString( name, ".ami")) || ( _format != WT_RGB) ) {

    return _amimage->write((char*) _nom.c_str());

#ifdef USE_MAGICK
  } else {
    
      float* r;
      float* g;
      float* b;
      int n,z;

    NEW(r , float, _tx*_ty);
    NEW(g , float, _tx*_ty);
    NEW(b , float, _tx*_ty);

    if ( _tz == 1 ) {
      if ( _format == WT_RGB ) {
        InitBuffer();
        for(n=0;n<=_txy-1;n++) {
      r[n] = VectValeurBuffer(0)/255.0;
      g[n] = VectValeurBuffer(1)/255.0;
      b[n] = VectValeurBuffer(2)/255.0;
          IncBuffer();
        } // endfor
      } else {
        fprintf(stderr,"InrImage::Ecrit() \t Magick seulement pour RGB \n");
        delete r;
        delete g;
        delete b;
        throw ImageWriteError();
      } // end if
      IM_WriteImage(_nom,r,g,b,_tx,_ty);
    } else {
      
        char name[256];
        char num[10];
        int  pos1,pos2;

      if ( _format == WT_RGB ) {
        for(z=0;z<=_tz-1;z++) {
          BufferPos(0,0,z);
          for(n=0;n<=_txy-1;n++) {
        r[n] = VectValeurBuffer(0)/255.0;
        g[n] = VectValeurBuffer(1)/255.0;
        b[n] = VectValeurBuffer(2)/255.0;
            IncBuffer();
          } // endfor
          
          sprintf(num,"%03d",z);
          pos1 = pos2 =0;
          while ((_nom[pos1]!='.')&&(_nom[pos1]!='\0'))
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
        } // endfor
      } else {
        fprintf(stderr,"InrImage::Ecrit() \t Magick seulement pour RGB \n");
        delete r;
        delete g;
        delete b;
        throw ImageWriteError();
      } // end if
    } // end if

    delete r;
    delete g;
    delete b;
#endif // USE_MAGICK

  } // end if

  return true;

} // Ecrit()


//--------------------------------------------------------------------------
unsigned char InrImage :: Desalloue( )
//                           ---------       
{

//  printf("liberation de %s \n", (char*) _nom);
  CLASS_MESSAGE((boost::format(" freeing image %s ") % (char*) _nom.c_str()).str().c_str())

/*
  if ( (_amimage_allocated) && (_amimage != NULL) ) {
    delete _amimage;
    _amimage = NULL;
    _amimage_allocated = false;
    //delete _nom;
  } // end if
*/
  // free previous smart pointer
  _amimage = boost::shared_ptr<amimage>();

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
  if ( fic == NULL ) {
    printf("InrImage::LitMaple()\t Erreur dans l'ouverture du fichier de %s \n", nom);
    return false;
  } // end if

  fscanf(fic,"Type:\t%s\n",chaine);
  printf("chaine = '%s'\n",chaine);
  if ( strcmp(chaine,"Image1D")!=0 ) {
    printf("InrImage::LitMaple()\t Erreur, Pour lecture d'image 1D uniquement ... \n");
    return false;
  } // end if

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
  for(x=0;x<=_tx-1;x++) {
    fscanf(fic,"%f\t",&r);
    ((FORMAT_FLOAT*)_amimage->data)[x]=r;
  } // endfor

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
  if ( fic == NULL ) {
    printf(" Erreur dans l'ouverture du fichier de %s \n", nom);
    return false;
  } // end if

  fprintf(fic,"Type:\tImage1D\n");
  fprintf(fic,"Dimension:\t%d\n",_tx);

  for(x=0;x<=_tx-1;x++) {
    r = ((FORMAT_FLOAT*)_amimage->data)[x];
    fprintf(fic,"%f\t",r);
  } // endfor

  fclose(fic);

  return true;

} // EcritMaple()


//--------------------------------------------------------------------------
unsigned char InrImage :: InitPositions( )
//                        -------------
{

  //cout << "InitPositions() for " << GetName() << std::endl;

  // here we will initialize the ImagePositionBase* _positions member
  switch (_format) {
    case WT_RGB: 
    case WT_RGBA: 
    case WT_UNSIGNED_CHAR: {
      ImagePositions<unsigned char> *positions = new ImagePositions<unsigned char>(this);
      _positions = positions;}
    break;
    case WT_UNSIGNED_SHORT:{
      ImagePositions<unsigned short> *positions = new ImagePositions<unsigned short>(this);
      _positions = positions;}
    break;
    case WT_SIGNED_SHORT  :  {
      ImagePositions<short> *positions = new ImagePositions<short>(this);
      _positions = positions;}
    break;
    case WT_UNSIGNED_INT  :  {
      ImagePositions<unsigned int> *positions = new ImagePositions<unsigned int>(this);
      _positions = positions;}
    break;
    case WT_SIGNED_INT  :  {
      ImagePositions<int> *positions = new ImagePositions<int>(this);
      _positions = positions;}
    break;
    case WT_UNSIGNED_LONG  :  {
      ImagePositions<unsigned long> *positions = new ImagePositions<unsigned long>(this);
      _positions = positions;}
    break;
    case WT_SIGNED_LONG  :  {
      ImagePositions<long> *positions = new ImagePositions<long>(this);
      _positions = positions;}
    break;
    case WT_FLOAT : 
    case WT_FLOAT_VECTOR : {
      ImagePositions<float> *positions = new ImagePositions<float>(this);
      _positions = positions;}
    break;
    case WT_DOUBLE : {
      ImagePositions<double> *positions = new ImagePositions<double>(this);
      _positions = positions;}
    break;
    default:
      CLASS_ERROR((boost::format(" format not processed %1% ... \n") % _format).str().c_str());
      return false;
  }

  _positions_allocated = true;

  return true;

} // InitPositions()


//--------------------------------------------------------------------------
unsigned char InrImage :: FreePositions( )
//                           ---------------
{

  //cout << "FreePositions() for " << GetName() << std::endl;

  // here we will initialize the ImagePositionBase* _positions member
  switch (_format) {
    case WT_RGB: 
    case WT_RGBA: 
    case WT_UNSIGNED_CHAR: 
      delete (ImagePositions<unsigned char> *)_positions;     break;
    case WT_UNSIGNED_SHORT:
      delete (ImagePositions<unsigned short> *)_positions;    break;
    case WT_SIGNED_SHORT  :  
      delete (ImagePositions<short> *)_positions;             break;
    case WT_UNSIGNED_INT  :  
      delete (ImagePositions<unsigned int> *)_positions;      break;
    case WT_SIGNED_INT  :
      delete (ImagePositions<int> *)_positions;               break;
    case WT_UNSIGNED_LONG  :  
      delete (ImagePositions<unsigned long> *)_positions;     break;
    case WT_SIGNED_LONG  :  
      delete (ImagePositions<long> *)_positions;              break;
    case WT_FLOAT : 
    case WT_FLOAT_VECTOR :
      delete (ImagePositions<float> *)_positions;             break;
    case WT_DOUBLE :
      delete (ImagePositions<double> *)_positions;            break;
    default:
      CLASS_ERROR((boost::format(" format not processed %1% ... \n") % _format).str().c_str());
      return false;
  }
   
  _positions_allocated = false;

  return true;

} // FreePositions()


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
  _translation_x =
  _translation_y =
  _translation_z = 0;
//  _inrimage = NULL;
//  _amimage = NULL;
//_data = NULL;

//  _inrimage_allouee   = false;
//  _amimage_allocated   = false;
  _positions_allocated = false;

  // Identity Matrix
  for(i=0;i<4;i++) 
  for(j=0;j<4;j++)
    _transf_matrix[i][j] = 0;
  for(i=0;i<3;i++) _transf_matrix[i][i] = 1;


} // InitParams()


//----------------------------------------------------------------------
InrImageIteratorBase::ptr InrImage::CreateIterator() 
{

  // here we will initialize the ImagePositionBase* _positions member
  switch (_format) {
    case WT_RGB: 
    case WT_RGBA: 
    case WT_UNSIGNED_CHAR: 
      return InrImageIterator<unsigned char>::ptr(
          new InrImageIterator<unsigned char>(this));
    break;
    case WT_UNSIGNED_SHORT:
      return InrImageIterator<unsigned short>::ptr(
          new InrImageIterator<unsigned short>(this));
    break;
    case WT_SIGNED_SHORT  : 
      return InrImageIterator<short>::ptr(
          new InrImageIterator<short>(this));
    break;
    case WT_UNSIGNED_INT  :
      return InrImageIterator<unsigned int>::ptr(
          new InrImageIterator<unsigned int>(this));
    break;
    case WT_SIGNED_INT  : 
      return InrImageIterator<int>::ptr(
          new InrImageIterator<int>(this));
    break;
    case WT_UNSIGNED_LONG  :
      return InrImageIterator<unsigned long>::ptr(
          new InrImageIterator<unsigned long>(this));
    break;
    case WT_SIGNED_LONG  : 
      return InrImageIterator<long>::ptr(
          new InrImageIterator<long>(this));
    break;
    case WT_FLOAT : 
    case WT_FLOAT_VECTOR :
      return InrImageIterator<float>::ptr(
          new InrImageIterator<float>(this));
    break;
    case WT_DOUBLE :
      return InrImageIterator<double>::ptr(
          new InrImageIterator<double>(this));
    default:
      CLASS_ERROR((boost::format(" format not processed ... (%1%) \n")%_format).str().c_str());
  }
  return InrImageIteratorBase::ptr();

}

//----------------------------------------------------------------------
InrImageIteratorBase::ptr InrImage::CreateConstIterator() const
{

  // here we will initialize the ImagePositionBase* _positions member
  switch (_format) {
    case WT_RGB: 
    case WT_RGBA: 
    case WT_UNSIGNED_CHAR: 
      return InrImageIteratorBase::ptr(
          new InrImageConstIterator<unsigned char>(this));
    break;
    case WT_UNSIGNED_SHORT:
      return InrImageIteratorBase::ptr(
          new InrImageConstIterator<unsigned short>(this));
    break;
    case WT_SIGNED_SHORT  : 
      return InrImageIteratorBase::ptr(
          new InrImageConstIterator<short>(this));
    break;
    case WT_UNSIGNED_INT  :
      return InrImageIteratorBase::ptr(
          new InrImageConstIterator<unsigned int>(this));
    break;
    case WT_SIGNED_INT  : 
      return InrImageIteratorBase::ptr(
          new InrImageConstIterator<int>(this));
    break;
    case WT_UNSIGNED_LONG  :
      return InrImageIteratorBase::ptr(
          new InrImageConstIterator<unsigned long>(this));
    break;
    case WT_SIGNED_LONG  : 
      return InrImageIteratorBase::ptr(
          new InrImageConstIterator<long>(this));
    break;
    case WT_FLOAT : 
    case WT_FLOAT_VECTOR :
      return InrImageIteratorBase::ptr(
          new InrImageConstIterator<float>(this));
    break;
    case WT_DOUBLE :
      return InrImageIteratorBase::ptr(
          new InrImageConstIterator<double>(this));
    default:
      CLASS_ERROR((boost::format(" format not processed ... (%1%) \n")%_format).str().c_str());
  }
  return InrImageIteratorBase::ptr();

}

//==========================================================================
// MEMBRES PUBLICS
//==========================================================================

//--------------------------------------------------------------------------
InrImage ::  InrImage( )
//                                 --------
{

  InitParams();

/*
  _Iterator = CreateIterator();
  _linear_interpolator = ImageLinearInterpolator::ptr( new ImageLinearInterpolator(this));
*/

} // Construteur


//--------------------------------------------------------------------------
InrImage ::  InrImage( const char* nom)
//                                 --------
{

  InitParams();

  //----- Lecture de l'image d'entree
  _nom = nom;

  Read();

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

  _Iterator = CreateIterator();
  _linear_interpolator = ImageLinearInterpolator::ptr( new ImageLinearInterpolator(this));

} // Construteur



//--------------------------------------------------------------------------
InrImage ::  InrImage( const char* nom, int type)
//                                 --------
{

  InitParams();

  if ( type != TYPE_MAPLE AlorsRetourne;

  LitMaple( nom);

  InitPositions();

  _Iterator = CreateIterator();
  _linear_interpolator = ImageLinearInterpolator::ptr( new ImageLinearInterpolator(this));

} // Construteur


//--------------------------------------------------------------------------
// default  char* nom=NULL
//
InrImage ::  InrImage( int dimx, int dimy, 
//                                 --------            
                         int dimz, WORDTYPE format, const char* nom)
{

  InitParams();

  if ( nom == NULL ) {
    _nom = "sans_nom.inr";
  } else {
    _nom = nom;
  } // end if

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

  _Iterator = CreateIterator();
  _linear_interpolator = ImageLinearInterpolator::ptr( new ImageLinearInterpolator(this));

} // Construteur


//--------------------------------------------------------------------------
// default  char* nom=NULL
//
InrImage ::  InrImage( int dimx, int dimy, 
//                                 --------            
                         int dimz, int vdim, WORDTYPE format, const char* nom)
{

  InitParams();

  if ( nom == NULL ) {
    _nom = "sans_nom.inr";
  } else {
    _nom = nom;
  } // end if

  _tx     = dimx;
  _ty     = dimy;
  _tz     = dimz;
  _txy    = _tx*_ty;
  _taille = (unsigned long) _tx * _ty * _tz;
 
  _format = (WORDTYPE) format;
  _vdim   = vdim;

  Alloue();

  InitPositions();

  _Iterator = CreateIterator();
  _linear_interpolator = ImageLinearInterpolator::ptr( new ImageLinearInterpolator(this));

} // Construteur


//--------------------------------------------------------------------------
// default  char* nom=NULL
//
InrImage ::  InrImage(  WORDTYPE format, 
//                                 --------  
                          const char* nom,
                          const InrImage* image )
{

  InitParams();

  if ( nom == NULL ) {
    _nom = "sans_nom.inr";
  } else {
    _nom = nom;
  } // end if

  _tx = image->DimX();
  _ty = image->DimY();
  _tz = image->DimZ();
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

  _Iterator = CreateIterator();
  _linear_interpolator = ImageLinearInterpolator::ptr( new ImageLinearInterpolator(this));

} // Construteur

//--------------------------------------------------------------------------
// default  char* nom=NULL
//
InrImage ::  InrImage(  WORDTYPE format, int vdim,
//                                 --------  
                          const char* nom,
                          const InrImage* image )
{

  InitParams();

  if ( nom == NULL ) {
    _nom = "sans_nom.inr";
  } else {
    _nom = nom;
  } // end if

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

  _Iterator = CreateIterator();
  _linear_interpolator = ImageLinearInterpolator::ptr( new ImageLinearInterpolator(this));

} // Construteur

#ifdef AMI_USE_VTK
//--------------------------------------------------------------------------
InrImage ::  InrImage( vtkImageData* vtkim)
//                                 --------
{
    int x,y,z,n;
    float val;

  if ( vtkim==NULL ) {
    fprintf(stderr,"InrImage::InrImage(vtkImageData*) \t NULL input \n");
    return;
  } // end if


  _tx     = vtkim->GetDimensions()[0];
  _ty     = vtkim->GetDimensions()[1];
  _tz     = vtkim->GetDimensions()[2];
  _txy    = _tx*_ty;
  _taille = (unsigned long) _tx * _ty * _tz;

  
  _vdim = vtkim->GetNumberOfScalarComponents() ;


  switch ( (vtkim->GetScalarType()) ){
    case VTK_DOUBLE:
      if ( _vdim==1 ) { 
        _format = WT_DOUBLE;
      } else {
        _format = WT_DOUBLE_VECTOR;
      } // end if
    break;
    case VTK_FLOAT:
        _format = WT_FLOAT;
    break;
    case VTK_SHORT:
      _format = WT_SIGNED_SHORT;
    break;
    case VTK_UNSIGNED_SHORT:
      _format = WT_UNSIGNED_SHORT;
    break;
    case VTK_INT:
      _format = WT_SIGNED_INT;
    break;
    case VTK_UNSIGNED_INT:
      _format = WT_UNSIGNED_INT;
    break;
    case VTK_UNSIGNED_CHAR:
      if ( _vdim==1 ) { 
        _format = WT_UNSIGNED_CHAR;
      } else
      if ( _vdim==3 ) { 
        _format = WT_RGB;
      } else
        fprintf(stderr,"Vector of unsigned char not available \n");
    break;
    default: fprintf(stderr,"type non available \n");
    _format = WT_FLOAT;
  } // end switch

  //  printf("dim: %d %d %d ; %d\n", _tx,_ty,_tz, _vdim);
  //  printf("format: %s \n", FormatName()   );

  _amimage = boost::shared_ptr<amimage>(new amimage());
  AMIFromWT(_vdim,_format,_amimage);
  _amimage->SetDim(_tx,_ty,_tz, _vdim);
  _amimage->allocate();
   
  //_amimage_allocated = true;

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

  _Iterator = CreateIterator();
  _linear_interpolator = ImageLinearInterpolator::ptr( new ImageLinearInterpolator(this));

  printf("vox size: %f %f %f \n", _size_x,_size_y,_size_z);


  // Use memcpy() ???
  if ( ScalarFormat() ) {
    memcpy(Buffer(), vtkim->GetScalarPointer(), _taille*TailleFormat[_format]*_vdim);    
  } else {
    InitBuffer();
    for(z=0;z<=_tz-1;z++) {
    for(y=0;y<=_ty-1;y++) {
    for(x=0;x<=_tx-1;x++) {
//std::cout << boost::format("x,y= %1% %2% %3%/ %4% %5%")% x % y % z % _tx % _ty<< std::endl;
      for(n=0;n<=_vdim-1;n++) {
        val = vtkim->GetScalarComponentAsDouble(x,y,z,n);
//        printf("val = %f \n",val);
        VectFixeValeur(n,val);
      } // endfor
      IncBuffer();
    } // endfor
    } // endfor
    } // endfor
  } // end if
//std::cout << "end" << std::endl;
    //  InitPositions();
} // Constructor

#endif // AMI_USE_VTK

//--------------------------------------------------------------------------
InrImage :: ~InrImage()
//                    -----------
{

  Desalloue();
  FreePositions();

} // Destructor


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
       CLASS_ERROR(" format not processed ... ");
     }
   return 0;
   
} // GetFormatFromAMI


///----------------------------------------------------------------
bool InrImage::AMIFromWT(int vdim, WORDTYPE type, amimage* amim)
//                                   ---------
{
    if (vdim==1) 
      amim->SetType(AMI_SCALAR); 
    else
      amim->SetType(AMI_VECTOR); 

    switch (type) {
      case WT_UNSIGNED_CHAR :   amim->SetRepres(AMI_UNSIGNED_CHAR);     return true;
      case WT_UNSIGNED_SHORT:   amim->SetRepres(AMI_UNSIGNED_SHORT);    return true;
      case WT_SIGNED_SHORT  :   amim->SetRepres(AMI_SIGNED_SHORT);      return true;
      case WT_UNSIGNED_INT  :   amim->SetRepres(AMI_UNSIGNED_INT);      return true;
      case WT_SIGNED_INT    :   amim->SetRepres(AMI_SIGNED_INT);        return true;
      case WT_UNSIGNED_LONG :   amim->SetRepres(AMI_UNSIGNED_LONG);     return true;
      case WT_SIGNED_LONG   :   amim->SetRepres(AMI_SIGNED_LONG);       return true;
      case WT_FLOAT         :   amim->SetRepres(AMI_FLOAT);             return true;
      case WT_DOUBLE        :   amim->SetRepres(AMI_DOUBLE);            return true;
      case WT_FLOAT_VECTOR  :   amim->SetRepres(AMI_FLOAT);
        amim->SetType(AMI_VECTOR); 
        amim->SetVDim(vdim);
        return true;
      case WT_RGBA          : 
        amim->SetRepres(AMI_UNSIGNED_CHAR);   
        amim->SetType(AMI_VECTOR); 
        amim->SetVDim(vdim);
        return true;
      case WT_RGB           : 
        amim->SetRepres(AMI_UNSIGNED_CHAR);   
        amim->SetType(AMI_VECTOR); 
        amim->SetVDim(3);
        return true;
      default: 
      fprintf(stderr,"type=%d Format not available \n",
          type);
      return false;
    }

} // AMIFromWT()


// ------------------------------------------------------------
bool InrImage::AMIFromWT( int vdim, WORDTYPE type,  boost::shared_ptr<amimage>& amim)
{
  return AMIFromWT(vdim,type,amim.get());
}

//----------------------------------------------------------------
void InrImage :: SetAMImage( const amimage::ptr& amim)
//                         ----------
{
  if (GB_debug) fprintf(stderr,"SetAMImage() begin\n");

  this->_amimage = amim;
  //this->_amimage_allocated = true;

  // Convert to InrImage
   if (GB_debug) fprintf(stderr,"SetAMImage() set format\n");
  this->GetFormatFromAMI(amim.get(),this->_format);
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

  _Iterator = CreateIterator();
  _linear_interpolator = ImageLinearInterpolator::ptr( new ImageLinearInterpolator(this));

  if (GB_debug) fprintf(stderr,"SetAMImage() end\n");

} // SetAMImage()


//----------------------------------------------------------------
void InrImage :: SetImageData( int dimx, int dimy, int dimz, 
//                                                    ----------
               WORDTYPE format, void* data, int vdim)
{

  Desalloue();
  FreePositions();

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
  if ( !_amimage.get()  ) {
  //   std::cout << "*"<< std::endl;
    _amimage = boost::shared_ptr<amimage>(new amimage());
    //_amimage_allocated = true;
  } // end if

  _amimage->SetDim(_tx,_ty,_tz,_vdim);
  AMIFromWT(_vdim,_format,_amimage.get());

  // ------ Fin init image 

  _amimage->SetData( data);

  InitPositions();

  _Iterator = CreateIterator();
  _linear_interpolator = ImageLinearInterpolator::ptr( new ImageLinearInterpolator(this));

} // SetImageData()


//----------------------------------------------------------------
void InrImage :: SetImageData( int dimx, int dimy, int dimz, int vdim,
//                         ------------
               WORDTYPE format, void* data)
{

  Desalloue();
  FreePositions();

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
  if ( !_amimage.get() ) {
  //   std::cout << "*"<< std::endl;
    _amimage = boost::shared_ptr<amimage>(new amimage());
  } // end if

  _amimage->SetDim(_tx,_ty,_tz);
  AMIFromWT(_vdim,_format,_amimage.get());

// ------ Fin init image 

  /*
  setInrimageData(_inrimage, data);
  */
  _amimage->SetData( data);

  InitPositions();

  _Iterator = CreateIterator();
  _linear_interpolator = ImageLinearInterpolator::ptr( new ImageLinearInterpolator(this));

} // SetImageData()


//----------------------------------------------------------------
void InrImage :: SetVoxelSize( float sx, float sy, float sz)
//                         ------------------
{

  _size_x = sx;
  _size_y = sy;
  _size_z = sz;

  if (_size_x<1E-10) _size_x=1;
  if (_size_y<1E-10) _size_y=1;
  if (_size_z<1E-10) _size_z=1;

  _amimage->SetVoxelSize(_size_x,_size_y,_size_z);

} // SetVoxelSize()


//----------------------------------------------------------------
void InrImage :: InitImage( double val)
//                         ---------
{

  InitBuffer();
  do {
    FixeValeur( val);
  } while (IncBuffer());
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
  do {
    VectFixeValeurs( val0, val1, val2);
  } while (IncBuffer());
  
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
  do {
    for(n=0;n<dim;n++) 
      VectFixeValeur( n,val[n]);
  } while (IncBuffer());
} // InitImage()



//----------------------------------------------------------------
const std::string InrImage :: FormatName()
//
{

  switch ( (WORDTYPE) _format ){

    case WT_DOUBLE        : return "DOUBLE";        
    case WT_FLOAT         : return "FLOAT";         
    case WT_UNSIGNED_CHAR : return "UNSIGNED CHAR"; 
    case WT_UNSIGNED_SHORT: return "UNSIGNED SHORT";
    case WT_SIGNED_SHORT  : return "SIGNED SHORT";  
    case WT_SIGNED_INT    : return "SIGNED INT";    
    case WT_UNSIGNED_INT  : return "UNSIGNED INT";    
    case WT_RGB           : return "RGB";       
    case WT_RGBA          : return "RGBA";
    case WT_FLOAT_VECTOR  : return "FLOAT_VECTOR";  

    default: return "UNKNOWN";
  } // end switch  


} // FormatName()


//----------------------------------------------------------------
// Initialisation du buffer correspondant au type de l'image
// a la position souhait�
// default int pos = 0
void InrImage :: InitBuffer( int pos )
//                         ---------
{
  _Iterator->InitBuffer(pos);

} // InitBuffer()


//-----------------------------------------------------------------
void InrImage::BufferPos( int x, int y, int z) throw (DepassementLimites)
//             ---------
{
  #ifdef _debug_
  if ( x<0 || x>=_tx || y<0 || y>=_ty || z<0 || z>=_tz ) {
    char message[100];
    sprintf(message, " image %s ( %d %d %d )", (char*)_nom, x, y, z);
    throw DepassementLimites( message);
  } // end if
  #endif

  _Iterator->BufferPos(x,y,z);

} // BufferPos()


//--------------------------------------------------------------------------
InrImage :: operator amimage*()
//                    ---------
{

  return _amimage.get();

} // operator amimage*()


#ifdef AMI_USE_VTK

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

  switch ( (WORDTYPE) _format ){
     case WT_DOUBLE        : vtk_image->SetScalarType( VTK_DOUBLE); break;
     case WT_FLOAT         : 
     case WT_FLOAT_VECTOR  : vtk_image->SetScalarType(VTK_FLOAT);  break;
     case WT_UNSIGNED_CHAR : 
     case WT_RGB           : vtk_image->SetScalarType(VTK_UNSIGNED_CHAR);  break;
     case WT_UNSIGNED_SHORT: vtk_image->SetScalarType(VTK_UNSIGNED_SHORT); break;
     case WT_SIGNED_SHORT  : vtk_image->SetScalarType(VTK_SHORT);  break;
     case WT_UNSIGNED_INT    : vtk_image->SetScalarType(VTK_UNSIGNED_INT);    break;
     case WT_SIGNED_INT    : vtk_image->SetScalarType(VTK_INT);    break;
     default: printf("InrImage::operator vtkImageData*()\t format non gere...\n");
  } // end switch
  
  // interpret 9 components vectors as tensors for now
  if (_vdim==9) {
    vtk_image->AllocateScalars();
    vtkDoubleArray* mat = vtkDoubleArray::New();
    mat->SetNumberOfComponents(9);

    InitBuffer();
    do {
      mat->InsertNextTuple9 ( 
        VectValeurBuffer(0), VectValeurBuffer(1), VectValeurBuffer(2),
        VectValeurBuffer(3), VectValeurBuffer(4), VectValeurBuffer(5),
        VectValeurBuffer(6), VectValeurBuffer(7), VectValeurBuffer(8) );
    } while (IncBuffer());


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
      if ( _vdim == 1 ) {
        vtk_scalars->SetTuple1(i,ValeurBuffer());
      } else {
      for(n=0;n<=_vdim-1;n++) {
        vtk_scalars->SetComponent(i,n,VectValeurBuffer(n));
      } // endfor
      } // end if
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

#endif // AMI_USE_VTK

//--------------------------------------------------------------------------
// default char* nom = NULL
unsigned char InrImage :: Sauve( const char* nom )
//                        -----
{

  if ( nom!=NULL ) {
    _nom = nom;
  } // end if

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

  if ( (max_x < min_x) || (max_y < min_y) || (max_z < min_z) ||
     (min_x < 0)     || (min_y < 0)     || (min_z < 0)     ||
     (max_x > _tx)   || (max_y > _ty)   || (max_z > _tz)     
  ) {
    return NULL;
  } // end if

  res = new InrImage( max_x - min_x + 1, max_y - min_y + 1, max_z - min_z +1, _format);
  res->SetVoxelSize( _size_x, _size_y, _size_z );

  for(z= 0;z<= res->_tz-1 ;z++) {
  for(y= 0;y<= res->_ty-1 ;y++) {
  for(x= 0;x<= res->_tx-1 ;x++) {

    switch ( (WORDTYPE) _format ){

      case WT_DOUBLE:
        ((FORMAT_DOUBLE*) res->GetData())[ (z*_ty + y)*_tx + x ] = 
        ((FORMAT_DOUBLE*)      this->GetData())
                  [ ((z+min_z)*_ty + (y+min_y))*_tx + x + min_x];
      break;

      case WT_FLOAT:
        ((FORMAT_FLOAT*) res->GetData())[ (z*_ty +  y)*_tx + x ] = 
        ((FORMAT_FLOAT*)      this->GetData())
              [ ((z+min_z)*_ty + (y+min_y))*_tx + x + min_x];
      break;

      case WT_UNSIGNED_CHAR:
        ((FORMAT_UNSIGNED_CHAR*) res->GetData())[ (z*_ty + y)*_tx + x ] =
        ((FORMAT_UNSIGNED_CHAR*)      this->GetData())
              [ ((z+min_z)*_ty + (y+min_y))*_tx + x + min_x];
      break;

      case WT_UNSIGNED_SHORT:
        ((FORMAT_UNSIGNED_SHORT*) res->GetData())[ (z*_ty + y)*_tx + x] = 
        ((FORMAT_UNSIGNED_SHORT*)      this->GetData())
              [ ((z+min_z)*_ty + (y+min_y))*_tx + x + min_x];
      break;

      case WT_SIGNED_SHORT:
        ((FORMAT_SIGNED_SHORT*) res->GetData())[ (z*_ty + y)*_tx + x] = 
        ((FORMAT_SIGNED_SHORT*)      this->GetData())
              [ ((z+min_z)*_ty + (y+min_y))*_tx + x + min_x];
      break;

      case WT_UNSIGNED_INT:
        ((FORMAT_UNSIGNED_INT*) res->GetData())[ (z*_ty + y)*_tx + x] = 
        ((FORMAT_UNSIGNED_INT*)      this->GetData())
              [ ((z+min_z)*_ty + (y+min_y))*_tx + x + min_x];
      break;

      case WT_SIGNED_INT:
        ((FORMAT_SIGNED_INT*) res->GetData())[ (z*_ty + y)*_tx + x] = 
        ((FORMAT_SIGNED_INT*)      this->GetData())
              [ ((z+min_z)*_ty + (y+min_y))*_tx + x + min_x];
      break;

      default: printf("InrImage::CreeSousImage()\t format non g��..\n");

    } // end switch

  } // endfor // x
  } // endfor // y
  } // endfor // z
  
  return( res);

} // CreeSousImage()




//--------------------------------------------------------------------------
InrImage* InrImage :: Convert256( float min, float max)
//                              ----------
// if ( l'image n'est pas de type WT_UNSIGNED_CHAR, alloue une nouvelle image
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

  if ( _format == WT_UNSIGNED_CHAR AlorsRetourne (InrImage*) this;

  image_res = new InrImage( _tx, _ty, _tz, WT_UNSIGNED_CHAR);

  diff = max - min;

  buf_resultat = (FORMAT_UNSIGNED_CHAR*) image_res->Buffer();

  switch ( (WORDTYPE) _format ){

    case WT_DOUBLE:
    //     --------
      buf_DOUBLE = (FORMAT_DOUBLE*) this->GetData();
      for(  n=0 ;  n < _tx*_ty*_tz ;  n++ ) {

        if ( fabs(diff) < 1E-5 ) {
          *buf_resultat = 0;      
        } else    
        if ( *buf_DOUBLE <= min ) {
           *buf_resultat = 0;
        } else    
        if ( *buf_DOUBLE >= max ) {
           *buf_resultat = 255;
        } else {
          *buf_resultat = (FORMAT_UNSIGNED_CHAR) ( 255 * (*buf_DOUBLE - min) / diff);          
        } // end if

        buf_DOUBLE++;
        buf_resultat++;
      } // end for // n
    break;

    case WT_FLOAT:
    //     --------
      buf_FLOAT = (FORMAT_FLOAT*) this->GetData();
      for(  n=0 ;  n < _tx*_ty*_tz ;  n++ ) {

        if ( fabs(diff) < 1E-5 ) {
          *buf_resultat = 0;      
        } else    
        if ( *buf_FLOAT <= min ) {
           *buf_resultat = 0;
        } else    
        if ( *buf_FLOAT >= max ) {
           *buf_resultat = 255;
        } else {
          *buf_resultat = (FORMAT_UNSIGNED_CHAR) ( 255 * (*buf_FLOAT - min) / diff);          
        } // end if

        buf_FLOAT++;
        buf_resultat++;
      } // end for // n
    break;

    case WT_UNSIGNED_SHORT:
    //     ----------
      buf_UNSIGNED_SHORT = (FORMAT_UNSIGNED_SHORT*) this->GetData();
      for(  n=0 ;  n < _tx*_ty*_tz ;  n++ ) {
        if ( fabs(diff) < 1E-5 ) {
          *buf_resultat = 0;          
        } else    
        if ( *buf_UNSIGNED_SHORT <= min ) {
           *buf_resultat = 0;
        } else    
        if ( *buf_UNSIGNED_SHORT >= max ) {
           *buf_resultat = 255;
        } else {
          *buf_resultat = (FORMAT_UNSIGNED_CHAR) ( 255 * (*buf_UNSIGNED_SHORT - min) / diff);          
        } // end if

        buf_UNSIGNED_SHORT++;
        buf_resultat++;
      } // end for // n
    break;

    case WT_SIGNED_SHORT:
    //     -----------
      buf_SIGNED_SHORT = (FORMAT_SIGNED_SHORT*) this->GetData();
      for(  n=0 ;  n < _tx*_ty*_tz ;  n++ ) {

        if ( fabs(diff) < 1E-5 ) {
          *buf_resultat = 0;          
        } else    
        if ( *buf_SIGNED_SHORT <= min ) {
           *buf_resultat = 0;
        } else    
        if ( *buf_SIGNED_SHORT >= max ) {
           *buf_resultat = 255;
        } else {
          *buf_resultat = (FORMAT_UNSIGNED_CHAR) ( 255 * (*buf_SIGNED_SHORT - min) / diff);          
        } // end if

        buf_SIGNED_SHORT++;
        buf_resultat++;
      } // end for // n
    break;

    case WT_SIGNED_INT:
    //     -----------
      buf_SIGNED_INT = (FORMAT_SIGNED_INT*) this->GetData();
      for(  n=0 ;  n < _tx*_ty*_tz ;  n++ ) {

        if ( fabs(diff) < 1E-5 ) {
          *buf_resultat = 0;          
        } else    
        if ( *buf_SIGNED_INT <= min ) {
           *buf_resultat = 0;
        } else    
        if ( *buf_SIGNED_INT >= max ) {
           *buf_resultat = 255;
        } else {
          *buf_resultat = (FORMAT_UNSIGNED_CHAR) ( 255 * (*buf_SIGNED_INT - min) / diff);          
        } // end if

        buf_SIGNED_INT++;
        buf_resultat++;
      } // end for // n
    break;

    default: printf("InrImage::convert256()\t format non g��..\n");

  } // end switch

  return image_res;

} // Convert256()


//--------------------------------------------------------------------------
InrImage* InrImage :: Convert256( )
//                              ----------
// if ( l'image n'est pas de type WT_UNSIGNED_CHAR, alloue une nouvelle image
// et la convertit en TYPE_UNSIGNED_CHAR
// avec le minimum �0 et le maximum �255
{
  float          min, max;

  MinMax(&min, &max);  
  return Convert256(min, max);

} // Convert256()


//--------------------------------------------------------------------------------------
const std::string& InrImage :: MessageErreur()
//                            -------------
{

  return _message_erreur;

} // MessageErreur()


//--------------------------------------------------
InrImage* operator -(  InrImage& i1,  InrImage& i2)
//        -----------
{

  InrImage* res;

  if (( i1.DimX() != i2.DimX()) ||
      ( i1.DimY() != i2.DimY()) ||
      ( i1.DimZ() != i2.DimZ())) 
  {
    FILE_ERROR("different dimensions");
   std::cout << "*" << std::endl;
    return NULL;
  }

  WORDTYPE format;

  if ((i1.GetFormat()==WT_DOUBLE)||(i2.GetFormat()==WT_DOUBLE))
    format = WT_DOUBLE;
  else 
    format = WT_FLOAT;

  if ( i1.ScalarFormat() && i2.ScalarFormat() ) {

    res = new InrImage(format,"minusop.inr.gz",&i1);
    res->InitBuffer();
    i1.InitBuffer();                
    i2.InitBuffer();                
    do {                           
      res->FixeValeur(i1.ValeurBuffer() - i2.ValeurBuffer()); 
      i1.IncBuffer();               
      i2.IncBuffer();               
    } while (!( !(res->IncBuffer())      
    ));                        

    return res;

  } else
  if ( i1.VectorialFormat() && i2.VectorialFormat() ) {
    int vdim = (i1.GetVDim()<i2.GetVDim()?i1.GetVDim():i2.GetVDim());
    res = new InrImage(format,vdim,"minusop.inr.gz",&i1);
    res->InitBuffer();
    i1.InitBuffer();                
    i2.InitBuffer();                
    do {                          
      for(int i=0;i<vdim;i++) 
      res->VectFixeValeur(i,i1.VectValeurBuffer(i) - i2.VectValeurBuffer(i));
      i1.IncBuffer();               
      i2.IncBuffer();               
    } while (!( !(res->IncBuffer())      
    ));                        

    return res;

  } else {
    fprintf(stderr,"operator - (InrImage*, InrImage*) \t Error: scalar and vectorial types \n");
  } // end if

  return NULL;
}


//--------------------------------------------------
InrImage* operator - ( InrImage& i1,  double r )
//        -----------
{

  InrImage* res;
  WORDTYPE format;

  if ( i1.GetFormat() ==WT_DOUBLE )
    format = WT_DOUBLE;
  else
    format = WT_FLOAT;

  if ( i1.ScalarFormat() )
  {

    res = new InrImage ( format,"minusop.inr.gz",&i1 );

    InrImageIteratorBase::ptr res_it(res->CreateIterator());
    InrImageIteratorBase::ptr i1_it(i1.CreateConstIterator());
    i1_it->InitBuffer(); 
    res_it->InitBuffer();
    do
    {
      res_it->SetDoubleValue( i1_it->GetDoubleValue() - r );
      (*i1_it)++;
    }
    while (  (*res_it)++  );

    return res;

  }
  else
    if ( i1.VectorialFormat() )
    {

      res = new InrImage ( i1._format,"minusop.inr.gz",&i1 );

      InrImageIteratorBase::ptr res_it(res->CreateIterator());
      InrImageIteratorBase::ptr i1_it(i1.CreateConstIterator());
      i1_it->InitBuffer(); 
      res_it->InitBuffer();

      do
      {
        for ( int i=0;i<i1.GetVDim();i++ )
          res_it->SetDoubleValue( i,i1_it->GetDoubleValue( i ) - r );
        (*i1_it)++;
      }
      while (  (*res_it)++  );

      return res;

    }
    else
    {
      fprintf ( stderr,"operator - (InrImage*, double) \t Error: scalar and vectorial types \n" );
    } // end if

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

  if ( i1._tx != i2._tx )  return NULL;
  if ( i1._ty != i2._ty )  return NULL;
  if ( i1._tz != i2._tz )  return NULL;

  if ( i1.ScalarFormat() && i2.ScalarFormat() ) {
    res = new InrImage(format,"plusop.inr.gz",&i1);

    InrImageIteratorBase::ptr res_it(res->CreateIterator());
    InrImageIteratorBase::ptr i1_it(i1.CreateConstIterator());
    InrImageIteratorBase::ptr i2_it(i2.CreateConstIterator());

    i1_it->InitBuffer(); 
    i2_it->InitBuffer();
    res_it->InitBuffer();

    long size = i1.Size();
    long i;
    for(i=0;i<size;i++) {
      res_it->SetDoubleValue( i1_it->GetDoubleValue() +
                              i2_it->GetDoubleValue()); 
      res_it->IncScalarBufferFast();
      i1_it->IncScalarBufferFast();
      i2_it->IncScalarBufferFast();
    }

    return res;

  } else
  if ( i1.VectorialFormat() && i2.VectorialFormat() ) {

    if ( i1.GetVDim() != i2.GetVDim() ) {
      fprintf(stderr,"InrImage*InrImage \t Vector dimensions don't match \n");
      return NULL;
    } // end if

    res = new InrImage(i1._format,"plusop.inr.gz",&i1);

    InrImageIteratorBase::ptr res_it(res->CreateIterator());
    InrImageIteratorBase::ptr i1_it(i1.CreateConstIterator());
    InrImageIteratorBase::ptr i2_it(i2.CreateConstIterator());

    i1_it->InitBuffer(); 
    i2_it->InitBuffer();
    res_it->InitBuffer();

    do {
      for(i=0;i<=i1.GetVDim()-1;i++) {
        val = i1_it->GetDoubleValue(i)+i2_it->GetDoubleValue(i);
        res_it->SetDoubleValue(i,val);
      } // endfor
      (*i1_it)++; 
      (*i2_it)++;
    } while (!( !((*res_it)++)  ));

    return res;

  } else {
    fprintf(stderr,"operator + (InrImage*, InrImage*) \t Error: scalar and vectorial types \n");
  } // end if

  return NULL;
}


//--------------------------------------------------
InrImage& operator +=(  InrImage& i1,  InrImage& i2)
//        -----------
{

  int i;
  double val;
  WORDTYPE format;

  if ((i1.GetFormat()==WT_DOUBLE)||(i2.GetFormat()==WT_DOUBLE))
    format = WT_DOUBLE;
  else 
    format = WT_FLOAT;

  if ( i1.DimX() != i2.DimX() )  return i1;
  if ( i1.DimY() != i2.DimY() )  return i1;
  if ( i1.DimZ() != i2.DimZ() )  return i1;

  if ( i1.ScalarFormat() && i2.ScalarFormat() ) {
    InrImageIteratorBase::ptr i1_it( i1.CreateIterator());
    InrImageIteratorBase::ptr i2_it( i2.CreateConstIterator());

    i1_it->InitBuffer();
    i2_it->InitBuffer();
    long size = i1.Size();
    long i;
    for(i=0;i<size;i++) {
      i1_it->SetDoubleValue(  i1_it->GetDoubleValue() +
                              i2_it->GetDoubleValue()); 
      i1_it->IncScalarBufferFast();
      i2_it->IncScalarBufferFast();
    }

    return i1;

  } else
  if ( i1.VectorialFormat() && i2.VectorialFormat() ) {

    if ( i1.GetVDim() != i2.GetVDim() ) {
      fprintf(stderr,"InrImage*InrImage \t Vector dimensions don't match \n");
      return i1;
    } // end if

    InrImageIteratorBase::ptr i1_it( i1.CreateIterator());
    InrImageIteratorBase::ptr i2_it( i2.CreateConstIterator());
    i1_it->InitBuffer(); 
    i2_it->InitBuffer();
    do { 
      for(i=0;i<=i1.GetVDim()-1;i++) {
        val = i1_it->GetDoubleValue(i)+i2_it->GetDoubleValue(i);
        i1_it->SetDoubleValue(i,val);
      } // endfor
      (*i2_it)++;
    } while (!( !((*i1_it)++)
    )); 

    return i1;

  } else {
    FILE_ERROR("Scalar and vectorial types ");
  } // end if

  return i1;
}


//--------------------------------------------------
InrImage* operator *(  const InrImage& i1,  const InrImage& i2)
//        -----------
{

  InrImage* res;
  double val;
  double val1;
  double val2;
  long   i;

  if ( i1.DimX() != i2.DimX() )  return NULL;
  if ( i1.DimY() != i2.DimY() )  return NULL;
  if ( i1.DimZ() != i2.DimZ() )  return NULL;


  WORDTYPE format;
  if ((i1.GetFormat()==WT_DOUBLE)||(i2.GetFormat()==WT_DOUBLE))
    format = WT_DOUBLE;
  else 
    format = WT_FLOAT;

  InrImageIteratorBase::ptr i1_it(i1.CreateConstIterator());
  InrImageIteratorBase::ptr i2_it(i2.CreateConstIterator());

  if ( i1.ScalarFormat() && i2.ScalarFormat() ) {

    res = new InrImage(format,1,"multop.inr.gz",&i1);
    InrImageIteratorBase::ptr res_it(res->CreateIterator());

    res_it->InitBuffer();
    i1_it->InitBuffer();
    i2_it->InitBuffer();
    for(i=0;i<=i1.Size()-1;i++) {
      res_it->SetDoubleValue(i1_it->GetValueIncDoubleValue(i) * i2_it->GetValueIncDoubleValue(i)); 
      res_it->IncScalarBufferFast();
    } // endfor

    return res;

  } else
  if ( i1.VectorialFormat() && i2.VectorialFormat() ) {
    printf("dim im1 = %d \n",i1.GetVDim());
    printf("dim im2 = %d \n",i2.GetVDim());
    if ( i1.GetVDim() != i2.GetVDim() ) {
      fprintf(stderr,"InrImage*InrImage \t Vector dimensions don't match \n");
      return NULL;
    } // end if
    res = new InrImage(format,1,"scalar.inr.gz",&i1);

    InrImageIteratorBase::ptr res_it(res->CreateIterator());
    res_it->InitBuffer();
    i1_it->InitBuffer();
    i2_it->InitBuffer();
    do {
      val = 0;
      for(i=0;i<=i1.GetVDim()-1;i++) {
        val += i1_it->GetDoubleValue(i)*i2_it->GetDoubleValue(i);
      } // endfor
      res_it->SetDoubleValue(val);
      ++(*i1_it);
      ++(*i2_it);
    } while (!( !((*res_it)++)
    ));

    return res;

  } else {
    // i1 vectorial and i2 scalar
    if ( i1.VectorialFormat() ) {
      res = new InrImage(format,i1.GetVDim(),"prod.inr.gz",&i1);
      InrImageIteratorBase::ptr res_it(res->CreateIterator());
      res_it->InitBuffer();
      i1_it->InitBuffer();
      i2_it->InitBuffer();
      do {
        val2 = i2_it->GetDoubleValue();
        for(i=0;i<=i1.GetVDim()-1;i++) {
          val = i1_it->GetDoubleValue(i)*val2;
          res_it->SetDoubleValue(i,val);
        } // endfor
        (*i1_it)++;
        (*i2_it)++;
      } while (!( !((*res_it)++)
      ));

      return res;

    } else {
    // i2 vectorial and i1 scalar
      res = new InrImage(format,i2.GetVDim(),"prod.inr.gz",&i2);
      InrImageIteratorBase::ptr res_it(res->CreateIterator());
      res_it->InitBuffer();
      i1_it->InitBuffer();
      i2_it->InitBuffer();
      do {
        val1 = i1_it->GetDoubleValue();
        for(i=0;i<=i2.GetVDim()-1;i++) {
          val = i2_it->GetDoubleValue(i)*val1;
          res_it->SetDoubleValue(i,val);
        } // endfor
        (*i1_it)++;
        (*i2_it)++;
      } while (!( !((*res_it)++)
      ));

      return res;

    } // end if

  } // end if

  return NULL;

}


//--------------------------------------------------
InrImage* operator / ( InrImage& i1,  InrImage& i2 )
//        -----------
{

  InrImage* res;
  float val;
  float val1;
  float val2;
  long   i;

  if ( i1._tx != i2._tx )  return NULL;
  if ( i1._ty != i2._ty )  return NULL;
  if ( i1._tz != i2._tz )  return NULL;

  WORDTYPE format;
  if ( ( i1.GetFormat() ==WT_DOUBLE ) || ( i2.GetFormat() ==WT_DOUBLE ) )
    format = WT_DOUBLE;
  else
    format = WT_FLOAT;

  if ( i1.ScalarFormat() && i2.ScalarFormat() )
  {

    res = new InrImage ( format,"multop.inr.gz",&i1 );

    InrImageIteratorBase::ptr i1_it (  i1.CreateConstIterator());
    InrImageIteratorBase::ptr i2_it (  i2.CreateConstIterator());
    InrImageIteratorBase::ptr res_it(res->CreateIterator()     );
    res_it->InitBuffer();
    i1_it ->InitBuffer();
    i2_it ->InitBuffer();

    for ( i=0;i<=i1.Size()-1;i++ )
    {
      if ( fabsf ( i2_it->GetDoubleValue() ) >0 )
        res_it->SetDoubleValue( i1_it->GetDoubleValue() / i2_it->GetDoubleValue() );
      (*res_it)++;
      (*i1_it)++;
      (*i2_it)++;
    } // endfor

    return res;

  }
  else
    if ( i1.VectorialFormat() && i2.VectorialFormat() )
    {
      fprintf ( stderr,"InrImage/InrImage \t no vector/vector operation \n" );
      return NULL;

    }
    else
    {
      // i1 vectorial and i2 scalar
      if ( i1.VectorialFormat() )
      {
        res = new InrImage ( format,i1.GetVDim(),"prod.inr.gz",&i1 );

        InrImageIteratorBase::ptr i1_it (  i1.CreateConstIterator());
        InrImageIteratorBase::ptr i2_it (  i2.CreateConstIterator());
        InrImageIteratorBase::ptr res_it(res->CreateIterator()     );
        res_it->InitBuffer();
        i1_it ->InitBuffer();
        i2_it ->InitBuffer();

        do
        {
          val2 = i2_it->GetDoubleValue();
          for ( i=0;i<=i1.GetVDim()-1;i++ )
          {
            if ( fabsf ( val2 ) >0 )
              val = i1_it->GetDoubleValue( i ) /val2;
            else
              val = 0;
            res_it->SetDoubleValue( i,val );
          } // endfor
          (*i1_it)++;
          (*i2_it)++;
        }
        while (  (*res_it)++  );

        return res;

      }
      else
      {
        // i2 vectorial and i1 scalar
        res = new InrImage ( format,i2.GetVDim(),"prod.inr.gz",&i2 );

        InrImageIteratorBase::ptr i1_it (  i1.CreateConstIterator());
        InrImageIteratorBase::ptr i2_it (  i2.CreateConstIterator());
        InrImageIteratorBase::ptr res_it(res->CreateIterator()     );
        res_it->InitBuffer();
        i1_it ->InitBuffer();
        i2_it ->InitBuffer();

        do
        {
          val1 = i1_it->GetDoubleValue();
          for ( i=0;i<=i2.GetVDim()-1;i++ )
          {
            if ( fabsf ( val1 ) >0 )
              val = i2_it->GetDoubleValue( i ) /val1;
            else
              val = 0;
            res_it->SetDoubleValue( i,val );
          } // endfor
          (*i1_it)++;
          (*i2_it)++;
        }
        while (  (*res_it)++  );

        return res;

      } // end if

    } // end if

  return NULL;

}


//--------------------------------------------------
InrImage* operator ^ ( InrImage& i1,  InrImage& i2 )
//        -----------
{

  InrImage* res;
  register float ux,uy,uz,vx,vy,vz;

  if ( i1._tx != i2._tx )  return NULL;
  if ( i1._ty != i2._ty )  return NULL;
  if ( i1._tz != i2._tz )  return NULL;

  WORDTYPE format;
  if ( ( i1.GetFormat() ==WT_DOUBLE ) || ( i2.GetFormat() ==WT_DOUBLE ) )
    format = WT_DOUBLE;
  else
    format = WT_FLOAT;

  if ( i1.ScalarFormat() || i2.ScalarFormat() )
  {

    return NULL;

  }
  else
    if ( i1.VectorialFormat() && i2.VectorialFormat() )
    {

      if ( i1.GetVDim() !=3 || i2.GetVDim() !=3 )
      {
        fprintf ( stderr,"operator^(InrImage,InrImage) \t only for dimension 3 vectors \n" );
        return NULL;
      } // end if

      res = new InrImage ( format,3,"vect_prod.ami.gz",&i1 );

      InrImageIteratorBase::ptr i1_it (  i1.CreateConstIterator());
      InrImageIteratorBase::ptr i2_it (  i2.CreateConstIterator());
      InrImageIteratorBase::ptr res_it(res->CreateIterator()     );
      res_it->InitBuffer();
      i1_it ->InitBuffer();
      i2_it ->InitBuffer();

      do
      {
        ux = i1_it->GetDoubleValue( 0 );
        uy = i1_it->GetDoubleValue( 1 );
        uz = i1_it->GetDoubleValue( 2 );

        vx = i2_it->GetDoubleValue( 0 );
        vy = i2_it->GetDoubleValue( 1 );
        vz = i2_it->GetDoubleValue( 2 );

        res_it->SetDoubleVectorValues( uy*vz-uz*vy,
                               uz*vx-ux*vz,
                               ux*vy-uy*vx );

        (*i1_it)++;
        (*i2_it)++;
      }
      while (  (*res_it)++  );

      return res;

    } // end if

  return NULL;

}



// Norm (for vectorial images) or absolute value for scalars
InrImage* Norm ( InrImage& i1 )
{

  InrImage* res;

  if ( i1.ScalarFormat() )
  {

    res = new InrImage ( WT_FLOAT,"norm.ami.gz",&i1 );

    InrImageIteratorBase::ptr i1_it ( i1.CreateConstIterator() );
    InrImageIteratorBase::ptr res_it ( res->CreateIterator() );
    res_it->InitBuffer();
    i1_it ->InitBuffer();

    do
    {
      res_it->SetDoubleValue ( fabsf ( i1_it->GetDoubleValue() ) );
      ( *i1_it ) ++;
    }
    while ( ( *res_it ) ++ );
    return res;

  }
  else
    if ( i1.VectorialFormat() )
    {

      double n2,tmp;
      int i;

      res = new InrImage ( WT_FLOAT,1,"norm.ami.gz",&i1 );

      InrImageIteratorBase::ptr i1_it ( i1.CreateConstIterator() );
      InrImageIteratorBase::ptr res_it ( res->CreateIterator() );
      res_it->InitBuffer();
      i1_it ->InitBuffer();

      do
      {
        n2 = 0;
        for ( i=0;i<i1.GetVDim();i++ )
        {
          tmp = i1_it->GetDoubleValue ( i );
          n2 += tmp*tmp;
        }

        res_it->SetDoubleValue ( sqrt ( n2 ) );

        ( *i1_it ) ++;
      }
      while (  ( *res_it ) ++  );

      return res;

    } // end if

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


