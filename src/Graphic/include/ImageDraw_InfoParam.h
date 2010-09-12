/*
 *  ImageDraw_InfoParam.h
 *  AMILab
 */

#ifndef _ImageDraw_InfoParam_h_
#define _ImageDraw_InfoParam_h_

#include "DefineClass.hpp"
#include "ParamPanel.hpp"

class DessinImage;

class ImageDraw_InfoParam: public ParamPanel
{
  DEFINE_CLASS(ImageDraw_InfoParam);

private:
  
  DessinImage* parent_class;
  
  // Parameters
  int _id_info_name;
  int _id_info_format;
  int _id_info_dim;
  int _id_info_voxelsize;
  int _id_info_stat;
  int _id_info_numpoints;
  int _id_info_min_max;
  int _id_info_mean;
  // Standard Deviation
  int _id_info_sd;
  // SD/Mean
  int _id_info_sd_mean;
  
public:
  
  ImageDraw_InfoParam   (DessinImage* parent);
  void CreateParameters ();
  
  // Callbacks 
  static void CB_info_stat (void* cd);
  
}; // class ImageDraw_InfoParam

#endif // _ImageDraw_InfoParam_h_
