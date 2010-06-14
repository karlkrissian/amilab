/*
 *  ImageDraw_Sections3DParam.h
 *  AMILab
 */

#ifndef _ImageDraw_Sections3DParam_h_
#define _ImageDraw_Sections3DParam_h_

#include "DefineClass.hpp"
#include "ParamPanel.hpp"

class DessinImage;

class ImageDraw_Sections3DParam: public ParamPanel
{
  DEFINE_CLASS(ImageDraw_Sections3DParam);
  
private:
  
  DessinImage* parent_class;
  
  // Parameters
  int _id_sectionXY_visible;
  int _id_sectionXZ_visible;
  int _id_sectionYZ_visible;
  
public:
  
  ImageDraw_Sections3DParam (DessinImage* parent);
  void CreateParameters     ();
  
  // Callbacks 

  
  
}; // class ImageDraw_Sections3DParam

#endif // _ImageDraw_Sections3DParam_h_

