

#include "Viewer3D.hpp"


Viewer3D_LightingParam::Viewer3D_LightingParam(Viewer3D* parent): ParamBox(parent, "Lighting Parameters")
{
  parent_class = parent;
  CreateParameters();
}


void Viewer3D_LightingParam::CreateParameters()
{
  ami_wxGLCanvas* mc = parent_class->m_canvas;

  //-------------- Light Number
  AddInteger( &_id_light_number,
	      &mc->_light_number,
	      "Light Number");
  
  IntegerConstraints( _id_light_number,
		   0, MAX_LIGHTS-1,
		   mc->_light_number);

  ChangedValueCallback( _id_light_number,
	      (void*) CB_light_number,
              (void*) parent_class);

  //-------------- Light Enable/Disable
  AddBoolean( &_id_light_enabled,
          &mc->_GLLight_display._enabled,
          "Light Enabled",
          CaractereToggle);

  BooleanDefault( _id_light_enabled, mc->_GLLight_display._enabled);
  

  ChangedValueCallback( _id_light_enabled,
	      (void*) CB_light_update,
	      (void*) parent_class);


  //-------------- Ambient
  AddColor( &_id_light_ambient,
	     "Ambient",
	     &mc->_GLLight_display._ambient);

  ChangedValueCallback( _id_light_ambient,
	      (void*) CB_light_update,
	      (void*) parent_class);

  //-------------- Diffuse
  AddColor( &_id_light_diffuse,
	       "Diffuse",
	       &mc->_GLLight_display._diffuse);

  ChangedValueCallback( _id_light_diffuse,
	      (void*) CB_light_update,
	      (void*) parent_class);

  //-------------- Specular
  AddColor( &_id_light_specular,
	       "Specular",
	       &mc->_GLLight_display._specular);

  ChangedValueCallback( _id_light_specular,
	      (void*) CB_light_update,
	      (void*) parent_class);

  //-------------- Position X
  AddFloat( &_id_light_position_x, 
	   &mc->_GLLight_display._position[0],
	   "X coordinate");
  FloatConstraints( _id_light_position_x, 
		 -5.0, 5.0,
		 mc->_GLLight_display._position[0]);

  ChangedValueCallback( _id_light_position_x,
	      (void*) CB_light_update,
	      (void*) parent_class);

  //-------------- Position Y
  AddFloat( &_id_light_position_y, 
	   &mc->_GLLight_display._position[1],
	   "Y coordinate");
  FloatConstraints( _id_light_position_y, 
		 -5.0, 5.0,
		 mc->_GLLight_display._position[1]);

  ChangedValueCallback( _id_light_position_y,
	      (void*) CB_light_update,
	      (void*) parent_class);

  //-------------- Position Z
  AddFloat( &_id_light_position_z, 
	   &mc->_GLLight_display._position[2],
	   "Z coordinate");
  FloatConstraints( _id_light_position_z, 
	 -5.0, 5.0,
	 mc->_GLLight_display._position[2]);

  ChangedValueCallback( _id_light_position_z,
	      (void*) CB_light_update,
	      (void*) parent_class);

  //-------------- Light Directional
  AddBoolean( &_id_light_directional,
	      &mc->_GLLight_display._directional,
	       "Light Directional",
	       CaractereToggle);

  BooleanDefault( _id_light_directional, mc->_GLLight_display._directional);
  

  //--------------
  AddButton( &_id_light_valider,  "Validate",
       (void*) CB_light_update,
       (void*) parent_class);

  //--------------
  AddButton( &_id_light_fermer,  "Close",
	       (void*) CB_light_fermer, 
	       (void*) parent_class);

  //--------------
  EnleveBouttons();
  CreeDialogue( );

  SetDragCallback(_id_light_position_x);
  SetDragCallback(_id_light_position_y);
  SetDragCallback(_id_light_position_z);

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


//-------------------------------------------------------
void Viewer3D_LightingParam::CB_light_visible( void* cd)
//                           ----------------
{
   Viewer3D*  tgl = (Viewer3D*) cd;

  Si !(tgl->_param_light->IsShown()) Alors
    tgl->_param_light->AfficheDialogue();
    tgl->_param_light->MAJ();
  Sinon
    tgl->_param_light->FermeDialogue( );
  FinSi

} // CB_light_visible()


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


