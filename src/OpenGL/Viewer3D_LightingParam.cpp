

#include "Viewer3D.hpp"
#include "ParamPanel.hpp"
#include "Viewer3D_LightingParam.h"


Viewer3D_LightingParam::Viewer3D_LightingParam(Viewer3D* parent): 
      ParamPanel(parent->GetParamBook(), 
      "Lig")
{
  parent_class = parent;
  CreateParameters();
  SetToolTip(_T("Lights properties"));
  //SetMinSize(wxSize(200,300));
}


void Viewer3D_LightingParam::CreateParameters()
{
  ami_wxGLCanvas* mc = parent_class->m_canvas;


  //-------------- Light Number
  AddInteger( &_id_light_number,
	      &mc->_light_number,
	      "Nb",
        "Select Light Number");
  
  IntegerConstraints( _id_light_number,
		   0, MAX_LIGHTS-1,
		   mc->_light_number);

  ChangedValueCallback( _id_light_number,
	      (void*) CB_light_number,
              (void*) parent_class);

  BeginHorizontal();
    //-------------- Light Enable/Disable
    AddBoolean( &_id_light_enabled,
            &mc->_GLLight_display._enabled,
            "On",
            CaractereToggle,
            "Activate / Desactivate light");
  
    //-------------- Light Directional
    AddBoolean( &_id_light_directional,
          &mc->_GLLight_display._directional,
          "Directional",
          CaractereToggle,
          "Set Directional Light");
  EndHorizontal();

  BooleanDefault( _id_light_enabled, mc->_GLLight_display._enabled);
  

  ChangedValueCallback( _id_light_enabled,
	      (void*) CB_light_update,
	      (void*) parent_class);

  BeginHorizontal(2);
    //-------------- Ambient
    AddColor( &_id_light_ambient,
        "Amb",
        &mc->_GLLight_display._ambient,
        "Ambient color property");
    // Set proportional position
    SetLastPositionProperties(1);
  
    ChangedValueCallback( _id_light_ambient,
          (void*) CB_light_update,
          (void*) parent_class);
  
    //-------------- Diffuse
    AddColor( &_id_light_diffuse,
          "Diff",
          &mc->_GLLight_display._diffuse,
          "Diffuse color property");
    // Set proportional position
    SetLastPositionProperties(1);

    ChangedValueCallback( _id_light_diffuse,
          (void*) CB_light_update,
          (void*) parent_class);

    //-------------- Specular
    AddColor( &_id_light_specular,
          "Spec",
          &mc->_GLLight_display._specular,
          "Specular color property");
    // Set proportional position
    SetLastPositionProperties(1);

    ChangedValueCallback( _id_light_specular,
          (void*) CB_light_update,
          (void*) parent_class);
  EndHorizontal();

  BeginBox("Position");
    //-------------- Position X
    AddFloat( &_id_light_position_x, 
      &mc->_GLLight_display._position[0],
      "X",
      2,
      "Light position in X axis");
    FloatConstraints( _id_light_position_x, 
      -5.0, 5.0,
      mc->_GLLight_display._position[0]);
  
    ChangedValueCallback( _id_light_position_x,
          (void*) CB_light_update,
          (void*) parent_class);
  
    //-------------- Position Y
    AddFloat( &_id_light_position_y, 
      &mc->_GLLight_display._position[1],
      "Y",
      2,
      "Light position in Y axis");
    FloatConstraints( _id_light_position_y, 
      -5.0, 5.0,
      mc->_GLLight_display._position[1]);
  
    ChangedValueCallback( _id_light_position_y,
          (void*) CB_light_update,
          (void*) parent_class);
  
    //-------------- Position Z
    AddFloat( &_id_light_position_z, 
      &mc->_GLLight_display._position[2],
      "Z",
      2,
      "Light position in Z axis");
    FloatConstraints( _id_light_position_z, 
    -5.0, 5.0,
    mc->_GLLight_display._position[2]);
  
    ChangedValueCallback( _id_light_position_z,
          (void*) CB_light_update,
          (void*) parent_class);
  EndBox();


  BooleanDefault( _id_light_directional, mc->_GLLight_display._directional);
  

/*
  //--------------
  AddButton( &_id_light_valider,  "Validate",
       (void*) CB_light_update,
       (void*) parent_class);

  //--------------
  AddButton( &_id_light_fermer,  "Close",
	       (void*) CB_light_fermer, 
	       (void*) parent_class);
*/


  //--------------
  EnleveBouttons();
  CreeDialogue( );

  SetDragCallback(_id_light_position_x,true);
  SetDragCallback(_id_light_position_y,true);
  SetDragCallback(_id_light_position_z,true);

  MAJ();

}


//------------------------------------------------------
void Viewer3D_LightingParam::CB_light_number( void* cd)
//                           ---------------
{
   Viewer3D*  tgl = (Viewer3D*) cd;
   ami_wxGLCanvas* glc = tgl->m_canvas;

  glc->_GLLight_display = glc->_GLLight[glc->_light_number];
  tgl->_param_light->MAJ();

} // CB_light_number()


//-----------------------------------------------------
void Viewer3D_LightingParam::CB_light_update(void* cd)
//                           ----------------
{
   Viewer3D*  tgl = (Viewer3D*) cd;
   ami_wxGLCanvas* glc = tgl->m_canvas;

  tgl->_param_light->RecupereValeurs( );
  glc->_GLLight[glc->_light_number]=glc->_GLLight_display;
  glc->Paint();

} // CB_light_update()


//----------------------------------------------------------------
void Viewer3D_LightingParam::CB_light_fermer( void* cd)
//                           ---------------
{
   Viewer3D*  tgl = (Viewer3D*) cd;

  tgl->_param_light->FermeDialogue( );
  tgl->UpdateMenu();

} // CB_light_fermer()


