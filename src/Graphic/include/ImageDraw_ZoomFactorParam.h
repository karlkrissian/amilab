/*
 *  ImageDraw_ZoomFactorParam.h
 *  AMILab
 */

#ifndef _ImageDraw_ZoomFactorParam_h_
#define _ImageDraw_ZoomFactorParam_h_

#include "DefineClass.hpp"
#include "ParamPanel.hpp"

class DessinImage;

class ImageDraw_ZoomFactorParam: public ParamPanel
{
  DEFINE_CLASS(ImageDraw_ZoomFactorParam);
  friend class DessinImage;
private:
  
  DessinImage* parent_class;
  
  // Parameters
  int _id_type_facteur;
  int _id_facteur_valentier;
  int _id_facteur_valreel;
  int _id_facteur_entier;
  int _id_facteur_reel;
  
public:
  
  ImageDraw_ZoomFactorParam (DessinImage* parent);
  void CreateParameters     ();
  
  // Callbacks 
  static void CB_facteur (void* cd);
  
}; // class ImageDraw_ZoomFactorParam

#endif // _ImageDraw_ZoomFactorParam_h_
