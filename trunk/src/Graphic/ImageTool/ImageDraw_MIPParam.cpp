/*
 *  ImageDraw_MIPParam.cpp
 *  AMILab
 */

#include "ImageDraw_MIPParam.h"

#include "DessinImage.hpp"

#include "amilab_messages.h"


//----------------------------------------------------
ImageDraw_MIPParam::ImageDraw_MIPParam (DessinImage* parent): ParamPanel(parent, "MIP")
{
  parent_class = parent;
  CreateParameters();
  SetToolTip(_T("MIP Parameters"));
//  SetMinSize(wxSize(200,200));
  SetMinSize(GetEffectiveMinSize());
}

//----------------------------------------------------
void ImageDraw_MIPParam::CreateParameters ()
{
  
  DessinImageParametres* Param = parent_class->GetParam();
 
  //------------- Affichage des projections XY, XZ, YZ
  BeginHorizontal();

    AddButton(&_id_boutton_XY,  "proj XY",
              (void*) CB_projette_XY,
              (void*) this);

    AddButton(&_id_boutton_XZ,  "proj XZ",
              (void*) CB_projette_XZ,
              (void*) this);

    AddButton(&_id_boutton_YZ,  "proj YZ",
              (void*) CB_projette_YZ,
              (void*) this);

  EndHorizontal();

  //-------------- Angle de d�allage pour la st��
  AddInteger( &_id_decal_stereo, &Param->_MIP._decal_stereo, "Angle","Stereo Angle");
  IntegerConstraints(    _id_decal_stereo, 0, 20, 5);
  ChangedValueCallback( _id_decal_stereo,
                                   (void*) ImageDraw_MIPParam::CB_MIP_decal_stereo,
                                   (void*) this);
  
  BeginBox("Rotation");
    //-------------- Affichage des rotations X, Y, Z
    AddInteger( &_id_rot_X, &Param->_MIP._rot_X, " X ", "Rotation / X");
    IntegerConstraints(    _id_rot_X, -180, 180, Param->_MIP._rot_X);
    ChangedValueCallback( _id_rot_X,
                                     (void*) ImageDraw_MIPParam::CB_projette_MIP, (void*) this);

    //--------------
    AddInteger( &_id_rot_Y, &Param->_MIP._rot_Y, " Y ", "Rotation / Y");
    IntegerConstraints(    _id_rot_Y, -180, 180, Param->_MIP._rot_Y);
    ChangedValueCallback( _id_rot_Y,
                                      (void*) ImageDraw_MIPParam::CB_projette_MIP, (void*) this);

    //--------------
    AddInteger( &_id_rot_Z, &Param->_MIP._rot_Z, " Z ", "Rotation / Z");
    IntegerConstraints(    _id_rot_Z, -180, 180, Param->_MIP._rot_Z);
    ChangedValueCallback( _id_rot_Z,
                                      (void*) ImageDraw_MIPParam::CB_projette_MIP, (void*) this);
  EndBox();
  
  //--------------
  AddFloat( &_id_depth_cue, &Param->_MIP._depth_cue, "DepthCue", 2, "DepthCue Factor");
  FloatConstraints(    _id_depth_cue, 0, 2, Param->_MIP._depth_cue);
  ChangedValueCallback( _id_depth_cue,
                                    (void*) ImageDraw_MIPParam::CB_MIP_depth_cue, (void*) this);

  //--------------
  AddButton( &_id_boutton_fermer_MIP,
                  "Close",
                  (void*) ImageDraw_MIPParam::CB_Fermer_parametresMIP,
                  (void*) this);


  ReAfficheParametres();
  EnleveBouttons();
  CreeDialogue();
  MAJ();

}

//----------------------------------------------------
void ImageDraw_MIPParam::CB_projette_XY (void* cd)
{
  ImageDraw_MIPParam* _this = (ImageDraw_MIPParam*) cd;
  if (!_this) {
    CLASS_MESSAGE_STATIC(_this, "Invalid parameter");
    return;
  }
  DessinImage*    di = (DessinImage*) _this->parent_class;
  DessinImageParametres* Param = di->GetParam();
  InrImage::ptr _image_MIP = di->Get_image_MIP();
  ImageMIP* _MIP = di->Get_MIP();

  Param->_MIP._rot_X = 0;
  Param->_MIP._rot_Y = 0;
  Param->_MIP._rot_Z = 0;

  _this->UpdateParameter( _this->_id_rot_X);
  _this->UpdateParameter( _this->_id_rot_Y);
  _this->UpdateParameter( _this->_id_rot_Z);

  _image_MIP = InrImage::ptr(_MIP->CreeMIP(
                                  Param->_MIP._rot_X,
                                  Param->_MIP._rot_Y,
                                  Param->_MIP._rot_Z ));
  
  Param->_MIP._MAJ   = true;
  Param->_MAJ.MAJCoupes();
  di->Paint();
  
} // CB_projette_XY()

//----------------------------------------------------
void ImageDraw_MIPParam::CB_projette_XZ (void* cd)
{
  ImageDraw_MIPParam* _this = (ImageDraw_MIPParam*) cd;
  if (!_this) {
    CLASS_MESSAGE_STATIC(_this, "Invalid parameter");
    return;
  }
  DessinImage*    di = (DessinImage*) _this->parent_class;
  DessinImageParametres* Param = di->GetParam();
  InrImage::ptr _image_MIP = di->Get_image_MIP();
  ImageMIP* _MIP = di->Get_MIP();
  
  Param->_MIP._rot_X = 90;
  Param->_MIP._rot_Y = 0;
  Param->_MIP._rot_Z = 0;

  _this->UpdateParameter( _this->_id_rot_X);
  _this->UpdateParameter( _this->_id_rot_Y);
  _this->UpdateParameter( _this->_id_rot_Z);

  _image_MIP = InrImage::ptr(_MIP->CreeMIP(
                                  Param->_MIP._rot_X,
                                  Param->_MIP._rot_Y,
                                  Param->_MIP._rot_Z ));
  Param->_MIP._MAJ   = true;
  Param->_MAJ.MAJCoupes();
  di->Paint();
  
} // CB_projette_XZ()

//----------------------------------------------------
void ImageDraw_MIPParam::CB_projette_YZ (void* cd)
{
  ImageDraw_MIPParam* _this = (ImageDraw_MIPParam*) cd;
  if (!_this) {
    CLASS_MESSAGE_STATIC(_this, "Invalid parameter");
    return;
  }
  DessinImage*    di = (DessinImage*) _this->parent_class;
  DessinImageParametres* Param = di->GetParam();
  InrImage::ptr _image_MIP = di->Get_image_MIP();
  ImageMIP* _MIP = di->Get_MIP();

  Param->_MIP._rot_X = 0;
  Param->_MIP._rot_Y = -90;
  Param->_MIP._rot_Z = 0;

  _this->UpdateParameter( _this->_id_rot_X);
  _this->UpdateParameter( _this->_id_rot_Y);
  _this->UpdateParameter( _this->_id_rot_Z);

  _image_MIP = InrImage::ptr(_MIP->CreeMIP(
                                  Param->_MIP._rot_X,
                                  Param->_MIP._rot_Y,
                                  Param->_MIP._rot_Z ));
  Param->_MIP._MAJ   = true;
  Param->_MAJ.MAJCoupes();
  di->Paint();
  
} // CB_projette_YZ()

//----------------------------------------------------
void ImageDraw_MIPParam::CB_MIP_decal_stereo (void* cd)
{
//  ImageDraw_MIPParam* _this = (ImageDraw_MIPParam*) cd;
//  if (!_this) {
//    CLASS_MESSAGE_STATIC(_this, "Invalid parameter");
//    return;
//  }
//  ImageDraw_MIPParam*    di = (ImageDraw_MIPParam*) _this->parent_class;
//  DessinImageParametres* Param = di->GetParam();  
  
  /* deprecated
    DessinImage*    di = (DessinImage*) cd;
    CompareImage*   im_stereo;

  Si Non(di->Param._MIP._stereo) AlorsRetourne;

  im_stereo = (CompareImage*) di->_tab_compare_image[ di->_MIP_num_stereo];
  im_stereo->FixeDecalStereo( di->Param._MIP._decal_stereo);
  im_stereo->Paint( );
*/
  
} // CB_MIP_decal_stereo()

//----------------------------------------------------
void ImageDraw_MIPParam::CB_projette_MIP (void* cd)
{
  ImageDraw_MIPParam* _this = (ImageDraw_MIPParam*) cd;
  if (!_this) {
    CLASS_MESSAGE_STATIC(_this, "Invalid parameter");
    return;
  }
  DessinImage*    di = (DessinImage*) _this->parent_class;
  DessinImageParametres* Param = di->GetParam();
  InrImage::ptr _image_MIP = di->Get_image_MIP();
  ImageMIP* _MIP = di->Get_MIP();
  
  _image_MIP = InrImage::ptr(_MIP->CreeMIP(
                                  Param->_MIP._rot_X,
                                  Param->_MIP._rot_Y,
                                  Param->_MIP._rot_Z ));
  Param->_MIP._MAJ   = true;
  Param->_MAJ.MAJCoupes();
  di->Paint();
  
} // CB_projette_MIP()

//----------------------------------------------------
void ImageDraw_MIPParam::CB_MIP_depth_cue (void* cd)
{
  ImageDraw_MIPParam* _this = (ImageDraw_MIPParam*) cd;
  if (!_this) {
    CLASS_MESSAGE_STATIC(_this, "Invalid parameter");
    return;
  }
  DessinImage*    di = (DessinImage*) _this->parent_class;
  DessinImageParametres* Param = di->GetParam();
  InrImage::ptr _image_MIP = di->Get_image_MIP();
  ImageMIP* _MIP = di->Get_MIP();
  
  _MIP->FixeDepthCue(  true, Param->_MIP._depth_cue);

  _image_MIP = InrImage::ptr(_MIP->CreeMIP(
                                  Param->_MIP._rot_X,
                                  Param->_MIP._rot_Y,
                                  Param->_MIP._rot_Z ));
  Param->_MIP._MAJ   = true;
  Param->_MAJ.MAJCoupes();
  di->Paint();
  
} // CB_MIP_depth_cue()

//----------------------------------------------------
void ImageDraw_MIPParam::CB_Fermer_parametresMIP (void* cd)
{
  ImageDraw_MIPParam* _this = (ImageDraw_MIPParam*) cd;
  if (!_this) {
    CLASS_MESSAGE_STATIC(_this, "Invalid parameter");
    return;
  }
  DessinImage*    di = (DessinImage*) _this->parent_class;
  
//  di->_param_MIP->FermeDialogue( );
  di->Call_ToggleParamPanel();
//  di->_MIP_parametres_visibles = false;
  di->Set_MIP_parametres_visibles();
//  di->menuMIP->Check(ID_MenuMIP_param,di->_MIP_parametres_visibles);
//  di->_Mmip_param_visibles->MAJ();
  
} // CB_Fermer_parametresMIP()

