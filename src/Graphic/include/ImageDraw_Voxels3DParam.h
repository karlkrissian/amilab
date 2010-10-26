/*
 *  ImageDraw_Voxels3DParam.h
 *  AMILab
 */

#ifndef _ImageDraw_Voxels3DParam_h_
#define _ImageDraw_Voxels3DParam_h_

#include "DefineClass.hpp"
#include "ParamPanel.hpp"

class DessinImage;

class ImageDraw_Voxels3DParam: public ParamPanel
{
  DEFINE_CLASS(ImageDraw_Voxels3DParam);
  friend class DessinImage;
private:
  
  DessinImage* parent_class;
  
  // Parameters
  int _id_voxels_seuilbas;
  int _id_voxels_seuilhaut;
  int _id_dessine_voxels3D;
  
public:
  
  ImageDraw_Voxels3DParam (DessinImage* parent);
  void CreateParameters   ();
  
  // Callbacks 
  static void CB_DessineVoxels3D (void* cd);
  
}; // class ImageDraw_Voxels3DParam

#endif // _ImageDraw_Voxels3DParam_h_
