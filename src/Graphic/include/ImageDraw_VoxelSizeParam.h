/*
 *  ImageDraw_VoxelSizeParam.h
 *  AMILab
 */

#ifndef _ImageDraw_VoxelSizeParam_h_
#define _ImageDraw_VoxelSizeParam_h_

#include "DefineClass.hpp"
#include "ParamPanel.hpp"

class DessinImage;

class ImageDraw_VoxelSizeParam: public ParamPanel
{
  DEFINE_CLASS(ImageDraw_VoxelSizeParam);

private:
  
  DessinImage* parent_class;
  
  // Parameters
  int _id_voxel_size_x;
  int _id_voxel_size_y;
  int _id_voxel_size_z;
  
public:
  
  ImageDraw_VoxelSizeParam (DessinImage* parent);
  void CreateParameters    ();
  
  // Callbacks 
  static void CB_voxel_size (void* cd);
  
}; // class ImageDraw_VoxelSizeParam

#endif // _ImageDraw_VoxelSizeParam_h_
