/*
 *  ImageDraw_CoupesXYParam.cpp
 *  AMILab
 */

#include "ImageDraw_CoupesXYParam.h"

#include "DessinImage.hpp"

#include "amilab_messages.h"


//----------------------------------------------------
ImageDraw_CoupesXYParam::ImageDraw_CoupesXYParam (DessinImage* parent): ParamPanel(parent, "Many XY")
{
  parent_class = parent;
  CreateParameters();
  SetToolTip(_T("Many XY Parameters"));
//  SetMinSize(wxSize(200,200));
  SetMinSize(GetEffectiveMinSize());
}

//----------------------------------------------------
void ImageDraw_CoupesXYParam::CreateParameters ()
{

  DessinImageParametres* Param = parent_class->GetParam();
  InrImage::ptr _image = parent_class->Get_image();
  
  //-------------- Z min et Z max
  AddInteger( &_id_zmin, &Param->_Zoom._zmin, "Z min");
  IntegerConstraints(    _id_zmin, 0, _image->_tz-1, Param->_Zoom._zmin);
  ChangedValueCallback( _id_zmin,
                                   (void*) ImageDraw_CoupesXYParam::CB_CoupesXY, (void*) this);

  //--------------
  AddInteger( &_id_zmax, &Param->_Zoom._zmax, "Z max");
  IntegerConstraints(    _id_zmax, 0, _image->_tz-1, Param->_Zoom._zmax);
  ChangedValueCallback( _id_zmax,
                                   (void*) ImageDraw_CoupesXYParam::CB_CoupesXY, (void*) this);


  ReAfficheParametres();
  EnleveBouttons();
  CreeDialogue();
  MAJ();

}

//----------------------------------------------------
void ImageDraw_CoupesXYParam:: CB_CoupesXY (void* cd)
{
  ImageDraw_CoupesXYParam* _this = (ImageDraw_CoupesXYParam*) cd;
  if (!_this) {
    CLASS_MESSAGE_STATIC(_this, "Invalid parameter");
    return;
  }
  DessinImage*    di = (DessinImage*) _this->parent_class;
  DessinImageParametres* Param = di->GetParam();

  if (Param->_Zoom._zmin >= Param->_Zoom._zmax)
  {
    Param->_Zoom._zmin = Param->_Zoom._zmax;
    _this->UpdateParameter( _this->_id_zmin);
    _this->UpdateParameter( _this->_id_zmax);
  }

  Param->_Zoom.ComputeSize();

  Param->_MAJ._coupes = true;
  di->EffaceTousLesEcrans( false);
  di->Paint();
  
} // CB_CoupesXY()
