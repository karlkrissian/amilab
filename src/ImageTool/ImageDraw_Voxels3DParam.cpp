/*
 *  ImageDraw_Voxels3DParam.cpp
 *  AMILab
 */

#include "ImageDraw_Voxels3DParam.h"

#include "DessinImage.hpp"

#include "amilab_messages.h"


//----------------------------------------------------
ImageDraw_Voxels3DParam::ImageDraw_Voxels3DParam (DessinImage* parent): ParamPanel(parent, "Voxels3D")
{
  parent_class = parent;
  CreateParameters();
  SetToolTip(_T("Voxels3D Parameters"));
//  SetMinSize(wxSize(200,200));
  SetMinSize(GetEffectiveMinSize());
}

//----------------------------------------------------
void ImageDraw_Voxels3DParam::CreateParameters ()
{

  float* _voxels3D_seuilbas = parent_class->Get_voxels3D_seuilbas();
  float* _voxels3D_seuilhaut = parent_class->Get_voxels3D_seuilhaut();
  float* _val_min = parent_class->Get_val_min();
  float* _val_max = parent_class->Get_val_max();

  BeginBox("Threshold");
    //-------------- Seuil Bas
    AddFloat( &_id_voxels_seuilbas,
                     _voxels3D_seuilbas,
                      "Low",
                      2,
                      "Low Threshold");
    FloatConstraints( _id_voxels_seuilbas,
                      *_val_min, *_val_max, *_val_min);


    //-------------- Seuil Haut
    AddFloat( &_id_voxels_seuilhaut,
                     _voxels3D_seuilhaut,
                      "High",
                      2,
                      "High Threshold");
    FloatConstraints( _id_voxels_seuilhaut,
                      *_val_min, *_val_max, *_val_max);

  EndBox();
  //-------------------- Boutton Dessin
  AddButton( &_id_dessine_voxels3D,
                  "Draw",
                  (void*) ImageDraw_Voxels3DParam::CB_DessineVoxels3D,
                  (void*) this);
    
  ReAfficheParametres();
  EnleveBouttons();
  CreeDialogue();
  MAJ();

}

//----------------------------------------------------
void ImageDraw_Voxels3DParam::CB_DessineVoxels3D (void* cd)
{
  ImageDraw_Voxels3DParam* _this = (ImageDraw_Voxels3DParam*) cd;
  if (!_this) {
    CLASS_MESSAGE_STATIC(_this, "Invalid parameter");
    return;
  }
  DessinImage*    di = (DessinImage*) _this->parent_class;
  InrImage::ptr _image = di->Get_image();
  float* _voxels3D_seuilbas = di->Get_voxels3D_seuilbas();
  float* _voxels3D_seuilhaut = di->Get_voxels3D_seuilhaut();

  if (!(di->Call_CheckGLWindow()))
    return;

  _this->RecupereValeur(_this->_id_voxels_seuilbas);
  _this->RecupereValeur(_this->_id_voxels_seuilhaut);


//  Si di->_image->_format != WT_FLOAT Alors
//    fprintf(stderr,"Limited to FLOAT images for the moment\n");
//    return;
//  FinSi

  Viewer3D_ptr glwin = di->Lock_GLWindow();
  glwin->GetCanvas()->CreeVoxels3D( _image.get(),
                   *_voxels3D_seuilbas,
                   *_voxels3D_seuilhaut,
                   di->GetMinIntensity(),
                   di->GetMaxIntensity(),
                   _image->_size_x,
                   _image->_size_y,
                   _image->_size_z);

  glwin->Paint();
  
} // CB_DessineVoxels3D()
