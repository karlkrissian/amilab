/*
 *  ImageDraw_IntensityParam.cpp
 *  AMILab
 */

#include "ImageDraw_IntensityParam.h"

#include "DessinImage.hpp"

#include "amilab_messages.h"


//----------------------------------------------------
ImageDraw_IntensityParam::ImageDraw_IntensityParam (DessinImage* parent): ParamPanel(parent, "Int.")
{
  parent_class = parent;
  CreateParameters();
  SetToolTip(_T("Intensity Parameters"));
//  SetMinSize(wxSize(250,200));
  SetMinSize(GetEffectiveMinSize());
}

//----------------------------------------------------
void ImageDraw_IntensityParam::CreateParameters ()
{

  DessinImageParametres* Param = parent_class->GetParam();
  InrImage::ptr _image = parent_class->Get_image();
  float* _intensite_float_min = parent_class->Get_intensite_float_min();
  float* _intensite_float_max = parent_class->Get_intensite_float_max();
  int* _intensite_entier_min = parent_class->Get_intensite_entier_min();
  int* _intensite_entier_max = parent_class->Get_intensite_entier_max();
  float* _val_min = parent_class->Get_val_min();
  float* _val_max = parent_class->Get_val_max();

//  BeginHorizontal();
    //-------------- Show colorbar
    AddBoolean( &_id_show_colorbar,
                  &Param->_show_colorbar,
                  "Colorbar");
    BooleanDefault( _id_show_colorbar, Param->_show_colorbar);

    ChangedValueCallback( _id_show_colorbar,
                         (void*) DessinImage::CB_redessine,
                         (void*) parent_class);

    //-------------- COLORSPACE
    AddEnumeration( &_id_colorspace, 3,
                      &Param->_I._colorspace ,
                      "Scale");

    AddEnumChoice( _id_colorspace,
                    &_id_colorspace_grey,
                    "Grey");
    AddEnumChoice( _id_colorspace,
                    &_id_colorspace_rainbow,
                    "Rainbow");
    AddEnumChoice( _id_colorspace,
                    &_id_colorspace_user,
                    "User");

    EnumerationDefaut( _id_colorspace, Param->_I._colorspace);
    ChangedValueCallback( _id_colorspace,
                         (void*) ImageDraw_IntensityParam::CB_colorspace,
                         (void*) this);
//  EndHorizontal();
  //--------------
 // BeginHorizontal();
    //--------------
    AddEnumeration( &_id_type_courbe, 4,
                      &Param->_I._type_courbe ,
                      "Curve");

    AddEnumChoice( _id_type_courbe, &_id_courbe_pente,
                    "Slope    __/ --");
    AddEnumChoice( _id_type_courbe, &_id_courbe_plateau,
                    "Plateau  __--__");
    AddEnumChoice( _id_type_courbe, &_id_courbe_pente2,
                    "Slope2   __/ __");
    AddEnumChoice( _id_type_courbe, &_id_courbe_interpole,
                         "Linear interp.");

    EnumerationDefaut( _id_type_courbe, _id_courbe_pente);
    ChangedValueCallback( _id_type_courbe,
                            (void*) ImageDraw_IntensityParam::CB_type_courbe, (void*) this);

    //--------------
 // EndHorizontal();

  //--------------
  BeginBox("Range");
    BeginPanel("Range");
      if ((_image->_format == WT_FLOAT ) ||
        (_image->_format == WT_DOUBLE))
      {
        AddFloat( &_id_min, _intensite_float_min,
                      "Min.",
                      2,
                      "Minimum intensity");
        FloatConstraints( _id_min,  *_val_min,  *_val_max, *_val_min);
    
        AddFloat( &_id_max, _intensite_float_max,
                      "Max.",
                      2,
                      "Maximum intensity");
        FloatConstraints( _id_max,  *_val_min,  *_val_max, *_val_max);
      }
      else 
      {
        AddInteger( &_id_min, _intensite_entier_min,
                    "Min.", "Minimum int");
        IntegerConstraints( _id_min,  (int) *_val_min,  (int) *_val_max,
                                          *_intensite_entier_min);
    
        AddInteger( &_id_max, _intensite_entier_max,
                    "Max.", "Maximum int");
        IntegerConstraints( _id_max,   (int) *_val_min,  (int) *_val_max,
                                          *_intensite_entier_max);
      }
    EndPanel();
  EndBox();
  

  ChangedValueCallback( _id_min,
                       (void*) ImageDraw_IntensityParam::CB_barre_min,
                       (void*) this);

  ChangedValueCallback( _id_max,
                       (void*) ImageDraw_IntensityParam::CB_barre_max,
                       (void*) this);

  
  if (Param->_I._type_courbe == TYPE_COURBE_INTERPOLE)
  {
    FixeVisible( _id_min, false);
    FixeVisible( _id_max, false);
  }
  else 
  {
    // todo
    //pb->FixeVisible( _id_interpole, false);
  }

  SetDragCallback(_id_min, true);
  SetDragCallback(_id_max, true);
  
  EnleveBouttons();
  CreeDialogue();
  MAJ();

}

//----------------------------------------------------
void ImageDraw_IntensityParam::CB_colorspace (void* cd)
{
  ImageDraw_IntensityParam* _this = (ImageDraw_IntensityParam*) cd;
  
  if (!_this) {
    CLASS_MESSAGE_STATIC(_this, "Invalid parameter");
    return;
  }
  
  DessinImage*    di = (DessinImage*) _this->parent_class;
  di->UpdateColormap();
  di->EffaceTousLesEcrans( false);
  di->Paint();
} // CB_colorspace()

//----------------------------------------------------
void ImageDraw_IntensityParam::CB_type_courbe (void* cd)
{
  ImageDraw_IntensityParam* _this = (ImageDraw_IntensityParam*) cd;
  
  if (!_this) {
    CLASS_MESSAGE_STATIC(_this, "Invalid parameter");
    return;
  }
  
  DessinImage*    di = (DessinImage*) _this->parent_class;
  DessinImageParametres* Param = di->GetParam();
  InrImage::ptr _image = di->Get_image();
  //     unsigned char         nouvelle_valeur;
  unsigned char         interpole;

  /*  nouvelle_valeur =  (*di->_param_dialog)[di->_id_type_courbe]->ValueChanged();

  Si nouvelle_valeur Alors
   */
  interpole = (Param->_I._type_courbe==TYPE_COURBE_INTERPOLE);
  //    Si interpole Alors di->_interpole_ligne->Manage();
  //                 Sinon di->_interpole_ligne->Unmanage();
  //    FinSi
     // TODO
  // di->_param_dialog->FixeVisible( di->_id_interpole,     interpole );
  _this->FixeVisible( _this->_id_min, !(interpole));
  _this->FixeVisible( _this->_id_max, !(interpole));
  _this->ReAfficheParametres();
  //  FinSi

  Param->_MAJ._intensite = true;
  Param->_MAJ.MAJCoupes();
  di->EffaceTousLesEcrans( false);
  di->Paint();

} // CB_type_courbe()

//----------------------------------------------------
void ImageDraw_IntensityParam::CB_barre_min (void* cd)
{
  ImageDraw_IntensityParam* _this = (ImageDraw_IntensityParam*) cd;
  
  if (!_this) {
    CLASS_MESSAGE_STATIC(_this, "Invalid parameter");
    return;
  }
  
  DessinImage*    di = (DessinImage*) _this->parent_class;
  DessinImageParametres* Param = di->GetParam();
  InrImage::ptr _image = di->Get_image();
  //     NoyauParametre* param;
  int int_min;
  float   float_min;

  int_min = *(di->Get_intensite_entier_min());
  float_min = *(di->Get_intensite_float_min());

  if (!(di->VerifyMinMax()))
  {
    di->Set_intensite_entier_min(int_min);
    di->Set_intensite_float_min(float_min);
  }

  di->MinMaxChecker();

  Param->_MAJ._intensite = true;
  Param->_MAJ.MAJCoupes();
//  di->EffaceTousLesEcrans( false);
  di->Paint();
} // CB_barre_min()

//----------------------------------------------------
void ImageDraw_IntensityParam::CB_barre_max (void* cd)
{
  ImageDraw_IntensityParam* _this = (ImageDraw_IntensityParam*) cd;
  
  if (!_this) {
    CLASS_MESSAGE_STATIC(_this, "Invalid parameter");
    return;
  }
  
  DessinImage*    di = (DessinImage*) _this->parent_class;
  DessinImageParametres* Param = di->GetParam();
  InrImage::ptr _image = di->Get_image();
  
  //     NoyauParametre* param;
  int int_max;
  float   float_max;

  int_max = *(di->Get_intensite_entier_max());
  float_max = *(di->Get_intensite_float_max());

  if (!(di->VerifyMinMax()))
  {
    di->Set_intensite_entier_max(int_max);
    di->Set_intensite_float_max(float_max);
  }

  di->MinMaxChecker();

  Param->_MAJ._intensite = true;
  Param->_MAJ.MAJCoupes();
//  di->EffaceTousLesEcrans( false);
  di->Paint();
} // CB_barre_max()
