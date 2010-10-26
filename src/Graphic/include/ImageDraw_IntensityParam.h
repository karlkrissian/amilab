/*
 *  ImageDraw_IntensityParam.h
 *  AMILab
 */

#ifndef _ImageDraw_IntensityParam_h_
#define _ImageDraw_IntensityParam_h_

#include "DefineClass.hpp"
#include "ParamPanel.hpp"

class DessinImage;

class ImageDraw_IntensityParam: public ParamPanel
{
  DEFINE_CLASS(ImageDraw_IntensityParam);
  friend class DessinImage;
private:
  
  DessinImage* parent_class;
  
  // Parameters
  int _id_show_colorbar;
  int _id_colorspace;
  int _id_colorspace_grey;
  int _id_colorspace_rainbow;
  int _id_colorspace_user;
  int _id_type_courbe;
  int _id_courbe_pente;
  int _id_courbe_pente2;
  int _id_courbe_plateau;
  int _id_courbe_interpole;
  int _id_min;
  int _id_max;
  
public:
  
  ImageDraw_IntensityParam (DessinImage* parent);
  void CreateParameters    ();
  
  // Callbacks 
  static void CB_colorspace  (void* cd);
  static void CB_type_courbe (void* cd);
  static void CB_barre_min   (void* cd);
  static void CB_barre_max   (void* cd);
  
}; // class ImageDraw_IntensityParam

#endif // _ImageDraw_IntensityParam_h_