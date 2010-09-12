/*
 *  ImageDraw_VectorsParam.h
 *  AMILab
 */

#ifndef _ImageDraw_VectorsParam_h_
#define _ImageDraw_VectorsParam_h_

#include "DefineClass.hpp"
#include "ParamPanel.hpp"

class DessinImage;

class ImageDraw_VectorsParam: public ParamPanel
{
  DEFINE_CLASS(ImageDraw_VectorsParam);

private:
  
  DessinImage* parent_class;
  
  // Parameters
  int _id_print_vectors;
  int _id_display_vectors;
  int _id_vector_distance_unit;
  int _id_vecteurs_taille;
  int _id_vecteurs_espacement;
  int _id_vecteur_type;
  int _id_vector_image_pixels;
  int _id_vecteur_fleche;
  int _id_vecteur_fleche_prop;
  int _id_vector_screen_pixels;
  
public:
  
  ImageDraw_VectorsParam (DessinImage* parent);
  void CreateParameters  ();
  
  // Callbacks 
  static void CB_AfficheVecteurs (void* cd);
  static void CB_taille_vecteurs (void* cd);
  static void CB_type_vecteur    (void* cd);
  
}; // class ImageDraw_VectorsParam

#endif // _ImageDraw_VectorsParam_h_