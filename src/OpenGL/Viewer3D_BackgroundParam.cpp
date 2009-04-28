

#include "Viewer3D.hpp"


Viewer3D_BackgroundParam::Viewer3D_BackgroundParam(Viewer3D* parent): ParamBox(parent, "Background Color")
{
  parent_class = parent;
  CreateParameters();
}


void Viewer3D_BackgroundParam::CreateParameters()
{
  ami_wxGLCanvas* mc = parent_class->m_canvas;

  //-------------- Background type
  AddEnumeration( &_id_backgroundtype,
		2, 
		&mc->_GLParam._background_type , 
		"Background Type");
  AddEnumChoice(
                _id_backgroundtype, 
		&_id_bg_onecolor,
		" One Color");
  AddEnumChoice(
                _id_backgroundtype, 
		&_id_bg_gradient,
		" Gradient");

  //-------------- Background color
  AddColor( &_id_backgroundcolor,
		"Background Color",
		&mc->_GLParam._background);

  ChangedValueCallback( _id_backgroundcolor,
		(void*) Viewer3D::CB_redessine,
		(void*) parent_class);

  BeginHorizontal();
  //-------------- Background top left color
  AddColor( &_id_bg_tl,
		"Top Left",
		&mc->_GLParam._bg_topleft);

  ChangedValueCallback( _id_bg_tl,
		(void*) Viewer3D::CB_redessine,
		(void*) parent_class);

  //-------------- Background top right color
  AddColor( &_id_bg_tr,
		"Top Right",
		&mc->_GLParam._bg_topright);

  ChangedValueCallback( _id_bg_tr,
		(void*) Viewer3D::CB_redessine,
		(void*) parent_class);

  EndHorizontal();
  BeginHorizontal();
  //-------------- Background bottom left color
  AddColor( &_id_bg_bl,
		"Bottom Left",
		&mc->_GLParam._bg_botleft);

  ChangedValueCallback( _id_bg_bl,
		(void*) Viewer3D::CB_redessine,
		(void*) parent_class);

  //-------------- Background bottom right color
  AddColor( &_id_bg_br,
		"Bottom Right",
		&mc->_GLParam._bg_botright);

  ChangedValueCallback( _id_bg_br,
		(void*) Viewer3D::CB_redessine,
		(void*) parent_class);

  EndHorizontal();

  //-------------- Close button
  AddButton( &_id_bc_close,  "Close",
	(void*) CB_BackgroundColorClose,
	(void*) parent_class);

  //--------------
  EnleveBouttons();
  CreeDialogue( );
  MAJ();

}


//----------------------------------------------
void Viewer3D_BackgroundParam::CB_BackgroundColorClose(  void* cd)
{
    Viewer3D*  tgl = (Viewer3D*) cd;

  tgl->_param_backgroundcolor->FermeDialogue();
  tgl->UpdateMenu();

} // CB_BackgroundColorClose()


