/*
 *  ImageDraw_CirclesParam.h
 *  AMILab
 */

#ifndef _ImageDraw_CirclesParam_h_
#define _ImageDraw_CirclesParam_h_

#include "DefineClass.hpp"
#include "ParamPanel.hpp"

class DessinImage;

class ImageDraw_CirclesParam: public ParamPanel
{
  DEFINE_CLASS(ImageDraw_CirclesParam);

private:
  
  DessinImage* parent_class;
  
  // Parameters
   int _id_circles_ON;
   int _id_circles_min_radius;
   int _id_circles_max_radius;
   int _id_circles_fill;
   int _id_circles_positive_color;
   int _id_circles_negative_color;
  
public:
  
  ImageDraw_CirclesParam (DessinImage* parent);
  void CreateParameters  ();
  
  // Callbacks 
  
  
}; // class ImageDraw_CirclesParam

#endif // _ImageDraw_CirclesParam_h_
