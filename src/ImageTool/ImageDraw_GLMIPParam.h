/*
 *  ImageDraw_GLMIPParam.h
 *  AMILab
 */

#ifndef _ImageDraw_GLMIPParam_h_
#define _ImageDraw_GLMIPParam_h_

#include "DefineClass.hpp"
#include "ParamPanel.hpp"

class DessinImage;

class ImageDraw_GLMIPParam: public ParamPanel
{
  DEFINE_CLASS(ImageDraw_GLMIPParam);
  friend class DessinImage;
private:
  
  DessinImage* parent_class;
  
  // Parameters
  int _id_glmip_seuilbas;
  int _id_glmip_seuilhaut;
  int _id_glmip_maxquads;
  int _id_dessine_GLMIP;
  
public:
  
  ImageDraw_GLMIPParam  (DessinImage* parent);
  void CreateParameters ();
  
  // Callbacks 
  static void CB_DessineGLMIP (void* cd);
  
}; // class ImageDraw_GLMIPParam

#endif // _ImageDraw_GLMIPParam_h_
