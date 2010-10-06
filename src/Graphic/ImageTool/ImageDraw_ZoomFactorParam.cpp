/*
 *  ImageDraw_ZoomFactorParam.cpp
 *  AMILab
 */

#include "ImageDraw_ZoomFactorParam.h"

#include "DessinImage.hpp"

#include "amilab_messages.h"


//----------------------------------------------------
ImageDraw_ZoomFactorParam::ImageDraw_ZoomFactorParam (DessinImage* parent): ParamPanel(parent, "Zoom Factor")
{
  parent_class = parent;
  CreateParameters();
  SetToolTip(_T("Zoom Factor Parameters"));
//  SetMinSize(wxSize(200,200));
  SetMinSize(GetEffectiveMinSize());
}

//----------------------------------------------------
void ImageDraw_ZoomFactorParam::CreateParameters ()
{
  
  int* _type_facteur = parent_class->Get_type_facteur();
  int* _facteur_entier = parent_class->Get_facteur_entier();
  float* _facteur_reel = parent_class->Get_facteur_reel();
  
  //--------------
  AddEnumeration( &_id_type_facteur, 2, _type_facteur ,
                    "Factor");

  AddEnumChoice( _id_type_facteur, &_id_facteur_entier,
                  " Integer ");
  AddEnumChoice( _id_type_facteur, &_id_facteur_reel,
                  " Real");

  EnumerationDefaut( _id_type_facteur, _id_facteur_reel);
  ChangedValueCallback( _id_type_facteur,
                          (void*) DessinImage::CB_redessine, (void*) parent_class);

  BeginBox("Resize Factor");
    //--------------
    AddInteger( &_id_facteur_valentier, _facteur_entier,
                     "Integer",
                     "Integer resize factor");
    IntegerConstraints( _id_facteur_valentier, 1, 10, *_facteur_entier);
    ChangedValueCallback( _id_facteur_valentier,
                       (void*) ImageDraw_ZoomFactorParam::CB_facteur, (void*) this);

    //--------------
    AddFloat( &_id_facteur_valreel, _facteur_reel,
                     "Real",
                     2,
                     "Real resize factor");
    FloatConstraints( _id_facteur_valreel, 0.2, 2.0, *_facteur_reel);
    ChangedValueCallback( _id_facteur_valreel,
                       (void*) ImageDraw_ZoomFactorParam::CB_facteur, (void*) this);
  EndBox();

/*
  Si _type_facteur == FACTEUR_ENTIER Alors
    _param_ZoomFacteur->FixeVisible( _id_facteur_valreel, false);
  Sinon
    _param_ZoomFacteur->FixeVisible( _id_facteur_valentier, false);
  FinSi
*/


  ReAfficheParametres();
  EnleveBouttons();
  CreeDialogue();
  MAJ();

}

//----------------------------------------------------
void ImageDraw_ZoomFactorParam:: CB_facteur (void* cd)
{
  ImageDraw_ZoomFactorParam* _this = (ImageDraw_ZoomFactorParam*) cd;
  if (!_this) {
    CLASS_MESSAGE_STATIC(_this, "Invalid parameter");
    return;
  }
  DessinImage*    di = (DessinImage*) _this->parent_class;
  DessinImageParametres* Param = di->GetParam();
  InrImage::ptr _image = di->Get_image();
  
//     NoyauParametre* param;

  if (Param->_type_taille == TAILLE_FACTEUR)
  {
    Param->_MAJ.MAJCoupes();
    di->EffaceTousLesEcrans( false);
    di->Paint();
  }
  
} // CB_facteur()
