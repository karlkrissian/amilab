/*
 *  ImageDraw_GLMIPParam.cpp
 *  AMILab
 */

#include "ImageDraw_GLMIPParam.h"

#include "DessinImage.hpp"

#include "amilab_messages.h"


//----------------------------------------------------
ImageDraw_GLMIPParam::ImageDraw_GLMIPParam (DessinImage* parent): ParamPanel(parent, "GLMIP")
{
  parent_class = parent;
  CreateParameters();
  SetToolTip(_T("GLMIP Parameters"));
//  SetMinSize(wxSize(200,200));
  SetMinSize(GetEffectiveMinSize());
}

//----------------------------------------------------
void ImageDraw_GLMIPParam::CreateParameters ()
{
  
  float* _val_min = parent_class->Get_val_min();
  float* _val_max = parent_class->Get_val_max();
  float* _GLMIP_seuilbas = parent_class->Get_GLMIP_seuilbas();
  float* _GLMIP_seuilhaut = parent_class->Get_GLMIP_seuilhaut();
  int* _GLMIP_maxquads = parent_class->Get_GLMIP_maxquads();
  
  BeginBox("Threshold");
    //-------------- Seuil Bas
    AddFloat( &_id_glmip_seuilbas,
                            _GLMIP_seuilbas,
                            "Low",
                            2,
                            "Low intensity level");
    FloatConstraints( _id_glmip_seuilbas,
                   *_val_min, *_val_max, *_val_min);


    //-------------- Seuil Haut
    AddFloat( &_id_glmip_seuilhaut,
                            _GLMIP_seuilhaut,
                            "High",
                            2,
                            "High intensity level");
    FloatConstraints( _id_glmip_seuilhaut,
                   *_val_min, *_val_max, *_val_max);

  EndBox();
 //-------------- MAX QUADS
  AddInteger( &_id_glmip_maxquads,
                  _GLMIP_maxquads,
                  "Quads",
                  "Max quads");
  IntegerConstraints( _id_glmip_maxquads,
                 1, 20, *_GLMIP_maxquads);

  //-------------------- Boutton Dessin
  AddButton( &_id_dessine_GLMIP,
                   "Draw",
                   (void*) ImageDraw_GLMIPParam::CB_DessineGLMIP,
                   (void*) this);
  
    
  ReAfficheParametres();
  EnleveBouttons();
  CreeDialogue();
  MAJ();

}

//----------------------------------------------------
void ImageDraw_GLMIPParam::CB_DessineGLMIP (void* cd)
{
  ImageDraw_GLMIPParam* _this = (ImageDraw_GLMIPParam*) cd;
  if (!_this) {
    CLASS_MESSAGE_STATIC(_this, "Invalid parameter");
    return;
  }
  DessinImage*    di = (DessinImage*) _this->parent_class;
  InrImage::ptr _image = di->Get_image();
  float* _GLMIP_seuilbas = di->Get_GLMIP_seuilbas();
  float* _GLMIP_seuilhaut = di->Get_GLMIP_seuilhaut();
  int* _GLMIP_maxquads = di->Get_GLMIP_maxquads();

  if (!(di->Call_CheckGLWindow()))
    return;

  _this->RecupereValeur(_this->_id_glmip_seuilbas);
  _this->RecupereValeur(_this->_id_glmip_seuilhaut);
  _this->RecupereValeur(_this->_id_glmip_maxquads);


//  Si di->_image->_format != WT_FLOAT Alors
//    fprintf(stderr,"Limited to FLOAT images for the moment\n");
//    return;
//  FinSi

  Viewer3D_ptr glwin =  di->Lock_GLWindow();
  glwin->GetCanvas()->CreeGLMIP( _image,
                *_GLMIP_seuilbas,
                *_GLMIP_seuilhaut,
                di->GetMinIntensity(),
                di->GetMaxIntensity(),
                *_GLMIP_maxquads);

  glwin->Paint();
  
} // CB_DessineGLMIP()

