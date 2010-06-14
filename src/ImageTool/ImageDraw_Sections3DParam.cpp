/*
 *  ImageDraw_Sections3DParam.cpp
 *  AMILab
 */

#include "ImageDraw_Sections3DParam.h"

#include "DessinImage.hpp"

#include "amilab_messages.h"


//----------------------------------------------------
ImageDraw_Sections3DParam::ImageDraw_Sections3DParam (DessinImage* parent): ParamPanel(parent, "Sections3D")
{
  parent_class = parent;
  CreateParameters();
  SetToolTip(_T("Sections3D Parameters"));
//  SetMinSize(wxSize(200,200));
  SetMinSize(GetEffectiveMinSize());
}

//----------------------------------------------------
void ImageDraw_Sections3DParam::CreateParameters ()
{
  
  unsigned char* _sectionXY_visible = parent_class->Get_sectionXY_visible();
  unsigned char* _sectionXZ_visible = parent_class->Get_sectionXZ_visible();
  unsigned char* _sectionYZ_visible = parent_class->Get_sectionYZ_visible();

  //------------- section XY
  AddBoolean( &_id_sectionXY_visible,
                  _sectionXY_visible,
                  "View XY section",
                  CaractereToggle);
  BooleanDefault( _id_sectionXY_visible,
                  *_sectionXY_visible);

  ChangedValueCallback( _id_sectionXY_visible,
                         (void*) DessinImage::CB_DessineSections3D,
                         (void*) parent_class);


  //------------- section XZ
  AddBoolean( &_id_sectionXZ_visible,
                  _sectionXZ_visible,
                  "View XZ section",
                  CaractereToggle);
  BooleanDefault( _id_sectionXZ_visible,
                  *_sectionXZ_visible);

  ChangedValueCallback( _id_sectionXZ_visible,
                         (void*) DessinImage::CB_DessineSections3D,
                         (void*) parent_class);


  //------------- section YZ
  AddBoolean( &_id_sectionYZ_visible,
                  _sectionYZ_visible,
                  "View YZ section",
                  CaractereToggle);
  BooleanDefault( _id_sectionYZ_visible,
                  *_sectionYZ_visible);

  ChangedValueCallback( _id_sectionYZ_visible,
              (void*) DessinImage::CB_DessineSections3D,
                         (void*) parent_class);


  ReAfficheParametres();
  EnleveBouttons();
  CreeDialogue();
  MAJ();

}

