/*
 *  ImageDraw_PositionParam.h
 *  AMILab
 */

#ifndef _ImageDraw_PositionParam_h_
#define _ImageDraw_PositionParam_h_

#include "DefineClass.hpp"
#include "ParamPanel.hpp"

class DessinImage;

class ImageDraw_PositionParam: public ParamPanel
{
  DEFINE_CLASS(ImageDraw_PositionParam);
  friend class DessinImage;
private:
  
  DessinImage* parent_class;
  
  // Parameters
  int _id_show_axes;
  int _id_axes_info;
  int _id_voxel_pos;
  int _id_space_pos;
  int _id_planX;
  int _id_planY;
  int _id_planZ;
  
public:
  
  ImageDraw_PositionParam (DessinImage* parent);
  void CreateParameters   ();
  
  // Callbacks 
  static void CB_PlanX (void* cd);
  static void CB_PlanY (void* cd);
  static void CB_PlanZ (void* cd);
  
}; // class ImageDraw_PositionParam

#endif // _ImageDraw_PositionParam_h_
