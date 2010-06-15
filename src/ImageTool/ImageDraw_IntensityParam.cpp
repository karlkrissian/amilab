/*
 *  ImageDraw_IntensityParam.cpp
 *  AMILab
 */

#include "ImageDraw_IntensityParam.h"

#include "DessinImage.hpp"

#include "amilab_messages.h"


//----------------------------------------------------
ImageDraw_IntensityParam::ImageDraw_IntensityParam (DessinImage* parent): ParamPanel(parent, "Intensity")
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

  BeginHorizontal();
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
  EndHorizontal();
  //--------------
  BeginHorizontal();
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
                         "Linear interpolation");

    EnumerationDefaut( _id_type_courbe, _id_courbe_pente);
    ChangedValueCallback( _id_type_courbe,
                            (void*) ImageDraw_IntensityParam::CB_type_courbe, (void*) this);

    //--------------
  EndHorizontal();

  //--------------
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
  DessinImageParametres* Param = di->GetParam();
  InrImage::ptr _image = di->Get_image();

  switch ( Param->_I._colorspace ){

    case COLORSPACE_GREY:
      di->SetPaletteGrey(PALETTE_RGB);
    break;


    case COLORSPACE_RAINBOW:
      unsigned char rainbow[256*3];
      unsigned char pattern[192];

      for (int i = 0; i <= 63; i++)
      {
        pattern[i]= (unsigned char) (i/63.0*255.0);
      }

      for (int i = 64; i <= 127; i++)
      {
        pattern[i]= (unsigned char) 255;
      }

      for (int i = 128; i <= 191; i++)
      {
        pattern[i]= (unsigned char) (255.0-(i-128.0)/64.0*255.0);
      }

      for (int i = 0; i <= 256*3-1; i++)
      {
        rainbow[i]     = 0;
      }

      for (int i = 0; i <= 255; i++)
      {
        if (i<192-32)
          rainbow[i+512] = pattern[32+i];

        if (i<192)
          rainbow[i+256+32] = pattern[i];

        if ((i<192)&&((i+96)<256))
          rainbow[i+96] = pattern[i];
      }

      di->SetPaletteRU(rainbow);
    break;

    case COLORSPACE_USER:
      InrImage::ptr _user_colormap = di->Get_user_colormap();
    if (_user_colormap.get()) {
      unsigned char colmap[256*3];
      for(int i=0;i<256;i++) {
        colmap[i]    =(unsigned char)(*_user_colormap)(i,0,0,0);
        colmap[i+256]=(unsigned char)(*_user_colormap)(i,0,0,1);
        colmap[i+512]=(unsigned char)(*_user_colormap)(i,0,0,2);
      }
      di->SetPaletteRU(colmap);
    }
    else
      fprintf(stderr,"DessinImage::CB_colorspace() \t no user defined colormap ! \n");
    break;

  } // end switch

  Param->_MAJ._intensite = true;
  Param->_MAJ.MAJCoupes();
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
