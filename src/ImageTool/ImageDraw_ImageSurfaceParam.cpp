/*
 *  ImageDraw_ImageSurfaceParam.cpp
 *  AMILab
 */

#include "ImageDraw_ImageSurfaceParam.h"

#include "DessinImage.hpp"

#include "amilab_messages.h"


//----------------------------------------------------
ImageDraw_ImageSurfaceParam::ImageDraw_ImageSurfaceParam (DessinImage* parent): ParamPanel(parent, "Image Surface")
{
  parent_class = parent;
  CreateParameters();
  SetToolTip(_T("Image Surface Parameters"));
//  SetMinSize(wxSize(200,200));
  SetMinSize(GetEffectiveMinSize());
}

//----------------------------------------------------
void ImageDraw_ImageSurfaceParam::CreateParameters ()
{
  
  float* _imsurf_zscale = parent_class->Get_imsurf_zscale();
  
  //=============

  BeginBox("Image Surface Parameters");
    // Z scale
    AddFloat( &_id_imsurf_zscale,
                    _imsurf_zscale,
                    "Z ",
                     2,
                     "Z scale");
    FloatConstraints( _id_imsurf_zscale,
                          0.1, 5.0, 1.0);

  //  pb->ChangedValueCallback( _id_imsurf_zscale,
  //                       CB_imagesurface,
  //                       (void*) this);


      //-------------- Creation de l'isosurface
    AddButton( &_id_imagesurface,
                      "ImageSurface",
                      (void*) ImageDraw_ImageSurfaceParam::CB_imagesurface,
                      (void*) this);
  EndBox();
  
  ReAfficheParametres();
  EnleveBouttons();
  CreeDialogue();
  MAJ();

}

//----------------------------------------------------
void ImageDraw_ImageSurfaceParam::CB_imagesurface (void* cd)
{
  ImageDraw_ImageSurfaceParam* _this = (ImageDraw_ImageSurfaceParam*) cd;
  if (!_this) {
    CLASS_MESSAGE_STATIC(_this, "Invalid parameter");
    return;
  }
  DessinImage*    di = (DessinImage*) _this->parent_class;
  DessinImageParametres* Param = di->GetParam();
  InrImage::ptr _image = di->Get_image();
  float* _imsurf_zscale = di->Get_imsurf_zscale();
  unsigned char init;
  float* min;
  float* max;

  if (!(di->Call_CheckGLWindow()))
  {
    di->CreateGLWindow();
    init = true;
  }
  else
  {
    init = false;
  }

  if ((_image->_format == WT_FLOAT ) ||
     (_image->_format == WT_DOUBLE))
  {
    min = di->Get_intensite_float_min();
    max = di->Get_intensite_float_max();
    if (GB_debug) printf("min max %f %f \n", *min, *max);
  }
  else
  {
    min = (float*)di->Get_intensite_entier_min();
    max = (float*)di->Get_intensite_entier_max();
  }

  _this->RecupereValeurs();

  Viewer3D_ptr glwin = di->Lock_GLWindow();

  cout << "di->Param._pos._z = " << Param->_pos._z << endl;

  glwin->GetCanvas()->CreeImageSurface(
        _image,
        Param->_pos._z,
        *_imsurf_zscale,
        *min,*max);

  glwin->Paint();

  if (init)
  {
    glwin->GetCanvas()->Normalize();
    glwin->GetCanvas()->Center();
  }
  
} // CB_imagesurface()
