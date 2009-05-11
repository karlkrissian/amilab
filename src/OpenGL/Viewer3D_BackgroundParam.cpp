

#include "Viewer3D.hpp"


Viewer3D_BackgroundParam::Viewer3D_BackgroundParam(Viewer3D* parent): ParamPanel(parent->GetParamBook(), "Bg")
{
  parent_class = parent;
  CreateParameters();
  SetToolTip(_T("Background Colors"));
}


void Viewer3D_BackgroundParam::CreateParameters()
{
  ami_wxGLCanvas* mc = parent_class->m_canvas;

  //-------------- Background type
  AddEnumeration( &_id_backgroundtype,
                  2, 
                  &mc->_GLParam._background_type , 
                  "Type");
  ChangedValueCallback( _id_backgroundtype,
    (void*) CB_BackgroundColorApply,
    (void*) parent_class);

  AddEnumChoice(
                _id_backgroundtype, 
                &_id_bg_onecolor,
                "Uniform");
  AddEnumChoice(
              _id_backgroundtype, 
              &_id_bg_gradient,
              "Gradient");

  //-------------- Background color
  AddColor( &_id_backgroundcolor,
    "Uniform",
    &mc->_GLParam._background,
    "Uniform color");
  

  ChangedValueCallback( _id_backgroundcolor,
    (void*) CB_BackgroundColorApply,
    (void*) parent_class);

  BeginHorizontal();
    //-------------- Background top left color
    AddColor( &_id_bg_tl,
      "Top L",
      &mc->_GLParam._bg_topleft,
      "Top Left Color");
    // Set proportional position
    SetLastPositionProperties(1);
  
    ChangedValueCallback( _id_bg_tl,
      (void*) CB_BackgroundColorApply,
      (void*) parent_class);
  
    //-------------- Background top right color
    AddColor( &_id_bg_tr,
      "Top R",
      &mc->_GLParam._bg_topright,
      "Top Right Color");
    // Set proportional position
    SetLastPositionProperties(1);
  
    ChangedValueCallback( _id_bg_tr,
      (void*) CB_BackgroundColorApply,
      (void*) parent_class);
  
  EndHorizontal();
  BeginHorizontal();
    //-------------- Background bottom left color
    AddColor( &_id_bg_bl,
      "Bot L",
      &mc->_GLParam._bg_botleft,
      "Bottom Left Color");
    // Set proportional position
    SetLastPositionProperties(1);
  
    ChangedValueCallback( _id_bg_bl,
      (void*) CB_BackgroundColorApply,
      (void*) parent_class);
  
    //-------------- Background bottom right color
    AddColor( &_id_bg_br,
      "Bot R",
      &mc->_GLParam._bg_botright,
      "Botton Right Color");
    // Set proportional position
    SetLastPositionProperties(1);
  
    ChangedValueCallback( _id_bg_br,
      (void*) CB_BackgroundColorApply,
      (void*) parent_class);
  EndHorizontal();

  /*
  //-------------- Close button
  AddButton( &_id_bc_close,  "Apply",
              (void*) CB_BackgroundColorApply,
              (void*) parent_class);

  */
  //--------------
  EnleveBouttons();
  CreeDialogue( );
  MAJ();

}


//----------------------------------------------
void Viewer3D_BackgroundParam::CB_BackgroundColorApply(  void* cd)
{
  ((Viewer3D*) cd)->Refresh();
} // CB_BackgroundColorClose()


