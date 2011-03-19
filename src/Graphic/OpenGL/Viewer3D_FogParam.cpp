

#include "Viewer3D.hpp"
#include "ParamPanel.hpp"
#include "Viewer3D_FogParam.h"

using namespace amilab;

//----------------------------------------------------
Viewer3D_FogParam::Viewer3D_FogParam(Viewer3D* parent): ParamPanel(parent, "Fog")
{
  parent_class = parent;
  CreateParameters();
  SetToolTip(_T("Fog Effect Parameters"));
}


//----------------------------------------------------
void Viewer3D_FogParam::CreateParameters()
{
  ami_wxGLCanvas::ptr mc = parent_class->m_canvas;

  //-------------- Fog Enable/Disable
  AddBoolean( &_id_fog_enabled,
	     &mc->_GLFogParam._enabled,
	     "Fog Enabled",
	     CaractereToggle);

  BooleanDefault( _id_fog_enabled, 
	     mc->_GLFogParam._enabled);
  
  ChangedValueCallback( _id_fog_enabled,
    (void*) Viewer3D::CB_redessine,
    (void*) parent_class);

  //-------------- Fog Mode
  AddEnumeration( &_id_fog_mode, 
                     3,
                     &mc->_GLFogParam._fogmode, 
                     "Mode");
  AddEnumChoice( _id_fog_mode, 
	       &_id_mode_exp,      
	       "GL_EXP");
  AddEnumChoice( _id_fog_mode, 
	       &_id_mode_exp2,
	       "GL_EXP2");
  AddEnumChoice( _id_fog_mode, 
	       &_id_mode_linear,
	       "GL_LINEAR");
  
  EnumerationDefaut( _id_fog_mode, mc->_GLFogParam._fogmode);
  ChangedValueCallback( _id_fog_mode, 
    (void*) Viewer3D::CB_redessine,
    (void*) parent_class);


  //-------------- unsigned char Use Background Color
  AddBoolean( &_id_fog_use_backgroundcolor,
              &mc->_GLFogParam._use_bg_color,
              "Bg Color",
              CaractereToggle,
              "Use the background color");
  BooleanDefault( _id_fog_use_backgroundcolor,
	     mc->_GLFogParam._use_bg_color);

  ChangedValueCallback( _id_fog_use_backgroundcolor,
    (void*) Viewer3D_FogParam::CB_fog_use_bg_color, 
    (void*) parent_class);


  //-------------- Fog Color
  AddColor( &_id_fog_color,
	     "Color",
	     &mc->_GLFogParam._color,
      "Fog Color");

  ChangedValueCallback( _id_fog_color,
    (void*) Viewer3D::CB_redessine,
    (void*) parent_class);

  //-------------- Fog Density
  AddFloat( &_id_fog_density, 
	  &mc->_GLFogParam._density,
	  "Density",
    2,
    "Fog Density");
  FloatConstraints( _id_fog_density, 
	       0.1, 3.0,
	       mc->_GLFogParam._density);

  ChangedValueCallback( _id_fog_density, 
    (void*) Viewer3D::CB_redessine,
    (void*) parent_class);

  //-------------- Fog Start
  AddFloat( &_id_fog_start, 
	  &mc->_GLFogParam._start,
	  "Start",
    2,
    "Fog Starting Position");
  FloatConstraints( _id_fog_start, 
	       -5.0, 5.0,
	       mc->_GLFogParam._start);

  ChangedValueCallback( _id_fog_start, 
    (void*) Viewer3D::CB_redessine,
    (void*) parent_class);

  //-------------- Fog End
  AddFloat( &_id_fog_end, 
	  &mc->_GLFogParam._end,
	  "End",
    2,
    "Fog Ending Position");
  FloatConstraints( _id_fog_end, 
	       -5.0, 5.0,
	       mc->_GLFogParam._end);

  ChangedValueCallback( _id_fog_end, 
    (void*) Viewer3D::CB_redessine,
    (void*) parent_class);

 
/*
  //-------------- Boutton Fermer
  AddButton( &_id_fog_fermer,  "Close",
	     (void*) Viewer3D_FogParam::CB_fog_fermer, 
	     (void*) parent_class);
*/
  //--------------
  EnleveBouttons();
  CreeDialogue( );
  MAJ();
}


//-----------------------------------------------------
void Viewer3D_FogParam :: CB_fog_use_bg_color( void* cd)
//                       -------------------
{
   Viewer3D*  tgl = (Viewer3D*) cd;
   ami_wxGLCanvas::ptr glc = tgl->m_canvas;

//  tgl->_GLFogParam.SetUseBGColor( true, &tgl->_GLParam._background);
//  (*tgl->_param_fog)[tgl->_id_fog_color]->MAJ();

    glc->Paint();

} //  CB_fog_use_bg_color()

/*
//----------------------------------------------------------------
void Viewer3D_FogParam :: CB_fog_fermer(void* cd)
//                       ---------------
{
   Viewer3D*  tgl = (Viewer3D*) cd;

   tgl->_param_fog->FermeDialogue( );
   tgl->UpdateMenu();
} // CB_fog_fermer()
*/

