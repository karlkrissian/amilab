/*
 *  ImageDraw_ImageSurfaceParam.h
 *  AMILab
 */

#ifndef _ImageDraw_ImageSufaceParam_h_
#define _ImageDraw_ImageSufaceParam_h_

#include "DefineClass.hpp"
#include "ParamPanel.hpp"

class DessinImage;

class ImageDraw_ImageSurfaceParam: public ParamPanel
{
  DEFINE_CLASS(ImageDraw_ImageSurfaceParam);
  
private:
  
  DessinImage* parent_class;
  
  // Parameters
  int _id_imsurf_zscale;
  int _id_imagesurface;
  
public:
  
  ImageDraw_ImageSurfaceParam (DessinImage* parent);
  void CreateParameters       ();
  
  // Callbacks 
  static void CB_imagesurface (void* cd);
  
  
}; // class ImageDraw_ImageSurfaceParam

#endif // _ImageDraw_ImageSurfaceParam_h_
