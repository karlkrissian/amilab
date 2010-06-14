/*
 *  ImageDraw_ColorsParam.cpp
 *  AMILab
 */

#include "ImageDraw_ColorsParam.h"

#include "DessinImage.hpp"

#include "amilab_messages.h"


//----------------------------------------------------
ImageDraw_ColorsParam::ImageDraw_ColorsParam (DessinImage* parent): ParamPanel(parent, "Colors")
{
  parent_class = parent;
  CreateParameters();
  SetToolTip(_T("Colors Parameters"));
//  SetMinSize(wxSize(200,200));
  SetMinSize(GetEffectiveMinSize());
}

//----------------------------------------------------
void ImageDraw_ColorsParam::CreateParameters ()
{

  ClasseCouleur* _couleur_fond = parent_class->Get_couleur_fond();
  ClasseCouleur* _couleur_objet = parent_class->Get_couleur_objet();
  ClasseCouleur* _couleur_lignes = parent_class->Get_couleur_lignes();
  
  //------------- Couleur du fond
  AddColor( &_id_couleur_fond,
                  "Background",
                  _couleur_fond,
                  "Background color");

  ChangedValueCallback( _id_couleur_fond,
                     (void*) ImageDraw_ColorsParam::CB_maj_couleurs,
                     (void*) this);


  //------------- Couleur de l'objet
  AddColor( &_id_couleur_objet,
                  "Object",
                  _couleur_objet,
                  "Object color");


  ChangedValueCallback( _id_couleur_objet,
                     (void*) ImageDraw_ColorsParam::CB_maj_couleurs,
                     (void*) this);

  //------------- Couleur des lignes
  AddColor( &_id_couleur_lignes,
                  "Lines",
                  _couleur_lignes,
                  "Lines color");


  ChangedValueCallback( _id_couleur_objet,
                     (void*) ImageDraw_ColorsParam::CB_maj_couleur_lignes,
                     (void*) this);

  
  ReAfficheParametres();
  EnleveBouttons();
  CreeDialogue();
  MAJ();

}

//----------------------------------------------------
void ImageDraw_ColorsParam::CB_maj_couleurs (void* cd)
{
  ImageDraw_ColorsParam* _this = (ImageDraw_ColorsParam*) cd;
  if (!_this) {
    CLASS_MESSAGE_STATIC(_this, "Invalid parameter");
    return;
  }
  DessinImage*    di = (DessinImage*) _this->parent_class;
  DessinImageParametres* Param = di->GetParam();

  Param->_MAJ._intensite = true;
  di->Paint();
  
} // CB_maj_couleurs()

//----------------------------------------------------
void ImageDraw_ColorsParam::CB_maj_couleur_lignes (void* cd)
{
  ImageDraw_ColorsParam* _this = (ImageDraw_ColorsParam*) cd;
  if (!_this) {
    CLASS_MESSAGE_STATIC(_this, "Invalid parameter");
    return;
  }
  DessinImage*    di = (DessinImage*) _this->parent_class;
  
  di->Set_Couleur();
  di->Paint();
  
} // CB_maj_couleur_lignes
