/*
 *  ImageDraw_AnimationParam.h
 *  AMILab
 */

#ifndef _ImageDraw_AnimationParam_h_
#define _ImageDraw_AnimationParam_h_

#include "DefineClass.hpp"
#include "ParamPanel.hpp"

class DessinImage;

class ImageDraw_AnimationParam: public ParamPanel
{
  DEFINE_CLASS(ImageDraw_AnimationParam);

private:
  
  DessinImage* parent_class;
  
  // Parameters
  int _id_play_button;
  int _id_stop_button;
  int _id_type_animation;
  int _id_forward;
  int _id_backward;
  int _id_autoreverse;
  int _id_vitesse;
  
public:
  
  ImageDraw_AnimationParam (DessinImage* parent);
  void CreateParameters    ();
  
  // Callbacks 
  static void CB_Anim_Play      (void* cd);
  static void CB_Anim_Stop      (void* cd);
  static void CB_type_animation (void* cd);
  static void CB_Anim_vitesse   (void* cd);
  
}; // class ImageDraw_AnimationParam

#endif // _ImageDraw_AnimationParam_h_
