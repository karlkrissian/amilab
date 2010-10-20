/*
 *  ImageDraw_ColorsParam.h
 *  AMILab
 */

#ifndef _ImageDraw_ColorsParam_h_
#define _ImageDraw_ColorsParam_h_

#include "DefineClass.hpp"
#include "ParamPanel.hpp"

class DessinImage;

class ImageDraw_ColorsParam: public ParamPanel
{
  DEFINE_CLASS(ImageDraw_ColorsParam);
  
private:
  
  DessinImage* parent_class;
  
  // Parameters
  int _id_couleur_fond;
  int _id_couleur_objet;
  int _id_couleur_lignes;
  
public:
  
  ImageDraw_ColorsParam (DessinImage* parent);
  void CreateParameters ();
  
  // Callbacks 
  static void CB_maj_couleurs       (void* cd);
  static void CB_maj_couleur_lignes (void* cd);
  
  
}; // class ImageDraw_ColorsParam

#endif // _ImageDraw_ColorsParam_h_
