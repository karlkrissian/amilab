/*
 *  ImageDraw_MIPParam.h
 *  AMILab
 */

#ifndef _ImageDraw_MIPParam_h_
#define _ImageDraw_MIPParam_h_

#include "DefineClass.hpp"
#include "ParamPanel.hpp"

class DessinImage;

class ImageDraw_MIPParam: public ParamPanel
{
  DEFINE_CLASS(ImageDraw_MIPParam);
  friend class DessinImage;
private:
  
  DessinImage* parent_class;
  
  // Parameters
  int _id_boutton_XY;
  int _id_boutton_XZ;
  int _id_boutton_YZ;
  int _id_decal_stereo;
  int _id_rot_X;
  int _id_rot_Y;
  int _id_rot_Z;
  int _id_depth_cue;
  int _id_boutton_fermer_MIP;
  
public:
  
  ImageDraw_MIPParam    (DessinImage* parent);
  void CreateParameters ();
  
  // Callbacks 
  static void CB_projette_XY          (void* cd);
  static void CB_projette_XZ          (void* cd);
  static void CB_projette_YZ          (void* cd);
  static void CB_MIP_decal_stereo     (void* cd);
  static void CB_projette_MIP         (void* cd);
  static void CB_MIP_depth_cue        (void* cd);
  static void CB_Fermer_parametresMIP (void* cd);
  
}; // class ImageDraw_MIPParam

#endif // _ImageDraw_MIPParam_h_
