/*
 *  ImageDraw_VolRenParam.cpp
 *  AMILab
 */

#include "ImageDraw_VolRenParam.h"

#include "DessinImage.hpp"

#include "amilab_messages.h"
#include "Viewer3D.hpp"

#include "VolumeRender.hpp"


//----------------------------------------------------
ImageDraw_VolRenParam::ImageDraw_VolRenParam (DessinImage* parent): ParamPanel(parent, "VolRen")
{
  parent_class = parent;
  CreateParameters();
  SetToolTip(_T("Volume Rendering Parameters"));
//  SetMinSize(wxSize(200,200));
  SetMinSize(GetEffectiveMinSize());
}

//----------------------------------------------------
void ImageDraw_VolRenParam::CreateParameters ()
{

  int* _volren_mode = parent_class->Get_volren_mode();
  int* _volren_planes = parent_class->Get_volren_planes();
  unsigned char* _volren_texture = parent_class->Get_volren_texture();
  unsigned char* _volren_power2dim = parent_class->Get_volren_power2dim();
  
  
  //-------------------- Volume Rendering Format
  AddEnumeration(&_id_volren_mode,3,_volren_mode,
                   "Volume Rendering Mode");
  AddEnumChoice(_id_volren_mode,&_id_volren_RGBA,"RGBA");
  AddEnumChoice(_id_volren_mode,&_id_volren_Intensity,"Intensity");
  AddEnumChoice(_id_volren_mode,&_id_volren_IntensityAlpha,"IntensityAlpha");


  ChangedValueCallback( _id_volren_mode,
                       (void*) ImageDraw_VolRenParam::CB_ResetVOLREN,
                       (void*) this);

  //-------------------- Number of planes
  AddInteger(&_id_volren_planes,_volren_planes, "Num.", "Number of planes (log2 scale)");

  IntegerConstraints(_id_volren_planes,0,9,*_volren_planes);

  ChangedValueCallback( _id_volren_planes,
                       (void*) ImageDraw_VolRenParam::CB_ResetVOLREN,
                       (void*) this);

  //-------------------- Boutton Dessin
  AddBoolean( &_id_volren_texture,
                  _volren_texture,
                  "Texture Mapping",
                  CaractereToggle);


  ChangedValueCallback( _id_volren_texture,
                       (void*) ImageDraw_VolRenParam::CB_ResetVOLREN,
                       (void*) this);

  //-------------------- Boutton Dessin
  AddBoolean( &_id_volren_power2dim,
                  _volren_power2dim,
                  "Enforce power 2 dimensions",
                  CaractereToggle);


  ChangedValueCallback( _id_volren_power2dim,
                       (void*) ImageDraw_VolRenParam::CB_ResetVOLREN,
                       (void*) this);

  //-------------------- Boutton Dessin
  AddButton( &_id_dessine_VOLREN,
                   "Draw",
                   (void*) ImageDraw_VolRenParam::CB_DessineVOLREN,
                   (void*) this);

    
  ReAfficheParametres();
  EnleveBouttons();
  CreeDialogue();
  MAJ();

}

//----------------------------------------------------
void ImageDraw_VolRenParam::CB_ResetVOLREN (void* cd)
{
  ImageDraw_VolRenParam* _this = (ImageDraw_VolRenParam*) cd;
  if (!_this) {
    CLASS_MESSAGE_STATIC(_this, "Invalid parameter");
    return;
  }
  DessinImage*    di = (DessinImage*) _this->parent_class;
  InrImage::ptr _image = di->Get_image();
  int* _volren_planes = di->Get_volren_planes();
  unsigned char* _volren_texture = di->Get_volren_texture();
  unsigned char* _volren_power2dim = di->Get_volren_power2dim();
  InrImage* _volren_opacity = di->Get_volren_opacity();
  
  if (!(di->Call_CheckGLWindow()))
    return;

  Viewer3D_ptr glwin =  di->Lock_GLWindow();
  glwin->GetCanvas()->InitVolRen( _image.get(),
                 di->GetMinIntensity(),
                 di->GetMaxIntensity(),
                 di,
                 _volren_opacity);
  
  glwin->GetCanvas()->GetVolRen()->SetPower2Dim(*_volren_power2dim);
  glwin->GetCanvas()->GetVolRen()->SetTexture(*_volren_texture);
  glwin->GetCanvas()->GetVolRen()->SetPlanes(  (int) pow(2.0,*_volren_planes));

  glwin->Paint();
  
} // CB_ResetVOLREN()

//----------------------------------------------------
void ImageDraw_VolRenParam::CB_DessineVOLREN (void* cd)
{
  ImageDraw_VolRenParam* _this = (ImageDraw_VolRenParam*) cd;
  if (!_this) {
    CLASS_MESSAGE_STATIC(_this, "Invalid parameter");
    return;
  }
  DessinImage*    di = (DessinImage*) _this->parent_class;
  InrImage::ptr _image = di->Get_image();
  int* _volren_planes = di->Get_volren_planes();
  unsigned char* _volren_texture = di->Get_volren_texture();
  unsigned char* _volren_power2dim = di->Get_volren_power2dim();

  if (!(di->Call_CheckGLWindow()))
      return;

//  Si di->_image->_format != WT_FLOAT Alors
//    fprintf(stderr,"Limited to FLOAT images for the moment\n");
//    return;
//  FinSi

  Viewer3D_ptr glwin = di->Lock_GLWindow();
  glwin->GetCanvas()->InitVolRen( _image.get(),
                 di->GetMinIntensity(),
                 di->GetMaxIntensity(),
                 di);


  glwin->GetCanvas()->GetVolRen()->SetPower2Dim(*_volren_power2dim);
  glwin->GetCanvas()->GetVolRen()->SetTexture(*_volren_texture);
  glwin->GetCanvas()->GetVolRen()->SetPlanes(  (int) pow(2.0,*_volren_planes));

  glwin->Paint();

} // CB_DessineVOLREN()
