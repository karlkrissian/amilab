/*
 *  ImageDraw_AnimationParam.cpp
 *  AMILab
 */

#include "ImageDraw_AnimationParam.h"

#include "DessinImage.hpp"

#include "amilab_messages.h"


//----------------------------------------------------
ImageDraw_AnimationParam::ImageDraw_AnimationParam (DessinImage* parent): ParamPanel(parent, "Animation")
{
  parent_class = parent;
  CreateParameters();
  SetToolTip(_T("Animation Parameters"));
//  SetMinSize(wxSize(200,200));
  SetMinSize(GetEffectiveMinSize());
}

//----------------------------------------------------
void ImageDraw_AnimationParam::CreateParameters ()
{
  
  int* _ANIM_vitesse = parent_class->Get_ANIM_vitesse();
  int* _type_animation = parent_class->Get_type_animation();

  BeginHorizontal();

    //------------- Bouttons PLAY et STOP
    AddButton( &_id_play_button, " PLAY ",
            (void*) ImageDraw_AnimationParam::CB_Anim_Play,
            (void*) this);

    AddButton( &_id_stop_button, " STOP ",
            (void*) ImageDraw_AnimationParam::CB_Anim_Stop,
            (void*) this);
  
  EndHorizontal();

    //-------------- Affichage des rotations X, Y, Z
  
 //--------------
  AddEnumeration( &_id_type_animation, 3, _type_animation , "curve");

  AddEnumChoice( _id_type_animation, &_id_forward,      "      Forward--->> ");
  AddEnumChoice( _id_type_animation, &_id_backward,     " <<---Backward     ");
  AddEnumChoice( _id_type_animation, &_id_autoreverse,  " <<-AutoReverse->> ");

  EnumerationDefaut( _id_type_animation, _id_forward);
  ChangedValueCallback( _id_type_animation,
                          (void*) ImageDraw_AnimationParam::CB_type_animation, (void*) this);

 

   //--------------
  AddInteger( &_id_vitesse, _ANIM_vitesse, "FPS", "Freq (images/s)");
  IntegerConstraints(    _id_vitesse, 1, 150, *_ANIM_vitesse);
  ChangedValueCallback( _id_vitesse,
                                    (void*) ImageDraw_AnimationParam::CB_Anim_vitesse, (void*) this);

  
  ReAfficheParametres();
  EnleveBouttons();
  CreeDialogue();
  MAJ();

}

//----------------------------------------------------
void ImageDraw_AnimationParam::CB_Anim_Play (void* cd)
{
  ImageDraw_AnimationParam* _this = (ImageDraw_AnimationParam*) cd;
  if (!_this) {
    CLASS_MESSAGE_STATIC(_this, "Invalid parameter");
    return;
  }
  DessinImage*    di = (DessinImage*) _this->parent_class;
  
//  di->_ANIM_etat = ANIM_PLAY;
  di->Set_ANIM_PLAY();
  di->LanceAnimation();
  
} // CB_Anim_Play()

//----------------------------------------------------
void ImageDraw_AnimationParam::CB_Anim_Stop (void* cd)
{
  ImageDraw_AnimationParam* _this = (ImageDraw_AnimationParam*) cd;
  if (!_this) {
    CLASS_MESSAGE_STATIC(_this, "Invalid parameter");
    return;
  }
  DessinImage*    di = (DessinImage*) _this->parent_class;
  
//  di->_ANIM_etat = ANIM_STOP;
  di->Set_ANIM_STOP();
  
} // CB_Anim_Stop()

//----------------------------------------------------
void ImageDraw_AnimationParam::CB_type_animation (void* cd)
{
//  ImageDraw_AnimationParam* _this = (ImageDraw_AnimationParam*) cd;
//  if (!_this) {
//    CLASS_MESSAGE_STATIC(_this, "Invalid parameter");
//    return;
//  }
//  DessinImage*    di = (DessinImage*) _this->parent_class;
//  DessinImageParametres* Param = di->GetParam();
  
  
} // CB_type_animation()

//----------------------------------------------------
void ImageDraw_AnimationParam::CB_Anim_vitesse (void* cd)
{
//  ImageDraw_AnimationParam* _this = (ImageDraw_AnimationParam*) cd;
//  if (!_this) {
//    CLASS_MESSAGE_STATIC(_this, "Invalid parameter");
//    return;
//  }
//  DessinImage*    di = (DessinImage*) _this->parent_class;
//  DessinImageParametres* Param = di->GetParam();
  

} // CB_Anim_vitesse()

