/*
 *  ImageDraw_VolRenParam.h
 *  AMILab
 */

#ifndef _ImageDraw_VolRenParam_h_
#define _ImageDraw_VolRenParam_h_

#include "DefineClass.hpp"
#include "ParamPanel.hpp"

class DessinImage;

class ImageDraw_VolRenParam: public ParamPanel
{
  DEFINE_CLASS(ImageDraw_VolRenParam);
  
private:
  
  DessinImage* parent_class;
  
  // Parameters
  int _id_volren_mode;
  int _id_volren_planes;
  int _id_volren_texture;
  int _id_volren_power2dim;
  int _id_dessine_VOLREN;
  int _id_volren_RGBA;
  int _id_volren_Intensity;
  int _id_volren_IntensityAlpha;
  
public:
  
  ImageDraw_VolRenParam (DessinImage* parent);
  void CreateParameters ();
  
  // Callbacks 
  static void CB_ResetVOLREN   (void* cd);
  static void CB_DessineVOLREN (void* cd);
  
}; // class ImageDraw_VolRenParam

#endif // _ImageDraw_VolRenParam_h_
