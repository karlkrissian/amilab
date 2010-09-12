/*
 *  ImageDraw_IsoContourParam.h
 *  AMILab
 */

#ifndef _ImageDraw_IsoContourParam_h_
#define _ImageDraw_IsoContourParam_h_

#include "DefineClass.hpp"
#include "ParamPanel.hpp"

class DessinImage;

class ImageDraw_IsoContourParam: public ParamPanel
{
  DEFINE_CLASS(ImageDraw_IsoContourParam);
  friend class DessinImage;
private:
  
  DessinImage* parent_class;
  
  // Parameters
  int _id_dessine_contour [3];
  int _id_couleur_contour [3];
  int _id_all_contours;
  int _id_seuil_contour   [3];
  int _id_step_contours;
  int _id_contours_winsize;
  int _id_isosurface;
  int _id_use_compareimage_colors;
  
public:
  
  ImageDraw_IsoContourParam (DessinImage* parent);
  void CreateParameters     ();
  
  // Callbacks 
  static void CB_IsoContourVisible (void* cd);
  static void CB_DessineIsoContour (void* cd);
  static void CB_isosurface        (void* cd);
  static void CB_UseCompareColors  (void* cd);
  
}; // class ImageDraw_IsoContourParam

#endif // _ImageDraw_IsoContourParam_h_
