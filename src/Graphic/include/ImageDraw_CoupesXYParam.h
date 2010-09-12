/*
 *  ImageDraw_CoupesXYParam.h
 *  AMILab
 */

#ifndef _ImageDraw_CoupesXYParam_h_
#define _ImageDraw_CoupesXYParam_h_

#include "DefineClass.hpp"
#include "ParamPanel.hpp"

class DessinImage;

class ImageDraw_CoupesXYParam: public ParamPanel
{
  DEFINE_CLASS(ImageDraw_CoupesXYParam);

private:
  
  DessinImage* parent_class;
  
  // Parameters
  int _id_zmin;
  int _id_zmax;
  
public:
  
  ImageDraw_CoupesXYParam (DessinImage* parent);
  void CreateParameters   ();
  
  // Callbacks 
  static void CB_CoupesXY (void* cd);
  
}; // class ImageDraw_CoupesXYParam

#endif // _ImageDraw_CoupesXYParam_h_
