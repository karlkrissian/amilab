/*
 *  ImageDraw_PositionParam.cpp
 *  AMILab
 */

#include "ImageDraw_PositionParam.h"

#include "DessinImage.hpp"

#include "amilab_messages.h"


//----------------------------------------------------
ImageDraw_PositionParam::ImageDraw_PositionParam (DessinImage* parent): ParamPanel(parent, "Pos.")
{
  parent_class = parent;
  CreateParameters();
  SetToolTip(_T("Position Parameters"));
//  SetMinSize(wxSize(200,200));
  SetMinSize(GetEffectiveMinSize());
}

//----------------------------------------------------
void ImageDraw_PositionParam::CreateParameters ()
{
  
  DessinImageParametres* Param = parent_class->GetParam();
  InrImage::ptr img = parent_class->Get_image();

  BeginHorizontal();
    //-------------- Show axes
    AddBoolean( &_id_show_axes,
                  &Param->_show_axes,
                  "Axes");
    BooleanDefault( _id_show_axes, Param->_show_axes);

    ChangedValueCallback( _id_show_axes,
                         (void*) DessinImage::CB_redessine,
                         (void*) parent_class);
    //-------------- axes information
    AddEnumeration( &_id_axes_info, 2,
                      &Param->_axes_info ,
                      "Unit");

    AddEnumChoice( _id_axes_info,
                    &_id_voxel_pos,
                    "Voxel");
    AddEnumChoice( _id_axes_info,
                    &_id_space_pos,
                    "Spatial");

    EnumerationDefaut( _id_axes_info, Param->_axes_info);
    ChangedValueCallback( _id_axes_info,
                         (void*) DessinImage::CB_redessine,
                         (void*) parent_class);
  EndHorizontal();

  //--------------
  BeginBox("Cursor position");
    BeginPanel("Cursor position");
      AddInteger( &_id_planX, &Param->_pos._x, "X", "X plane");
      IntegerConstraints( _id_planX, 0, img->_tx - 1, Param->_pos._x);

      ChangedValueCallback( _id_planX,
                           (void*) ImageDraw_PositionParam::CB_PlanX,
                           (void*) this);
  

      AddInteger( &_id_planY, &Param->_pos._y, "Y", "Y plane");
      IntegerConstraints( _id_planY, 0, img->_ty - 1, Param->_pos._y);
      ChangedValueCallback( _id_planY,
                           (void*) ImageDraw_PositionParam::CB_PlanY,
                           (void*) this);


      AddInteger( &_id_planZ, &Param->_pos._z, "Z", "Z plane");

      if (img->_tz > 1)
      {
        IntegerConstraints( _id_planZ,
                          0,
                          img->_tz - 1,
                          Param->_pos._z);
      }
       
      ChangedValueCallback( _id_planZ,
                           (void*) ImageDraw_PositionParam::CB_PlanZ,
                           (void*) this);
    EndPanel();
  EndBox();
  
  FixeVisible(_id_planX, (img->_tx>1));
  FixeVisible(_id_planY, (img->_ty>1));
  FixeVisible(_id_planZ, (img->_tz>1));
  
  SetDragCallback(_id_planX, true);
  SetDragCallback(_id_planY, true);
  SetDragCallback(_id_planZ, true);
  
  EnleveBouttons();
  CreeDialogue();
  MAJ();

}

//----------------------------------------------------
void ImageDraw_PositionParam::CB_PlanX (void* cd)
{
  ImageDraw_PositionParam* _this = (ImageDraw_PositionParam*) cd;
  if (!_this) {
    CLASS_MESSAGE_STATIC(_this, "Invalid parameter");
    return;
  }
  DessinImage*    di = (DessinImage*) _this->parent_class;
  DessinImageParametres* Param = di->GetParam();
  InrImage::ptr img = di->Get_image();

  if ((Param->_option_traitement == OPTION_COUPE) ||
     (Param->_option_traitement == OPTION_ANIM))
  {
    if (Param->_pos._x < 0)
    {
      Param->_pos._x = 0;
      _this->UpdateParameter(_this->_id_planX);
    }

    if (Param->_pos._x > img->_tx-1)
    {
      Param->_pos._x = img->_tx-1;
      _this->UpdateParameter(_this->_id_planX);
    }

    Param->_MAJ._planZY = true;
    di->Paint( );
  }
} // CB_PlanX()

//----------------------------------------------------
void ImageDraw_PositionParam::CB_PlanY (void* cd)
{
  ImageDraw_PositionParam* _this = (ImageDraw_PositionParam*) cd;
  if (!_this) {
    CLASS_MESSAGE_STATIC(_this, "Invalid parameter");
    return;
  }
  DessinImage*    di = (DessinImage*) _this->parent_class;
  DessinImageParametres* Param = di->GetParam();
  InrImage::ptr img = di->Get_image();

  if ((Param->_option_traitement == OPTION_COUPE)  ||
     (Param->_option_traitement == OPTION_ANIM))
  {
    if (Param->_pos._y < 0)
    {
      Param->_pos._y = 0;
      _this->UpdateParameter(_this->_id_planY);
    }

    if (Param->_pos._y > img->_ty-1)
    {
      Param->_pos._y = img->_ty-1;
      _this->UpdateParameter(_this->_id_planZ);
    }

    Param->_MAJ._planXZ = true;
    di->Paint( );
  }
} // CB_PlanY()

//----------------------------------------------------
void ImageDraw_PositionParam::CB_PlanZ (void* cd)
{
  ImageDraw_PositionParam* _this = (ImageDraw_PositionParam*) cd;
  if (!_this) {
    CLASS_MESSAGE_STATIC(_this, "Invalid parameter");
    return;
  }
  DessinImage*    di = (DessinImage*) _this->parent_class;
  DessinImageParametres* Param = di->GetParam();
  InrImage::ptr img = di->Get_image();

  if ((Param->_option_traitement == OPTION_COUPE) ||
      (Param->_option_traitement == OPTION_ANIM))
  {
    if (Param->_pos._z < 0)
    {
      Param->_pos._z = 0;
      _this->UpdateParameter(_this->_id_planZ);
    }

    if (Param->_pos._z > img->_tz-1)
    {
      Param->_pos._z = img->_tz-1;
      _this->UpdateParameter(_this->_id_planZ);
    }

    Param->_MAJ._planXY = true;
    di->Paint( );
  }
} // CB_PlanZ()
