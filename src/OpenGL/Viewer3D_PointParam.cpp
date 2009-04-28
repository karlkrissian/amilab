

#include "Viewer3D.hpp"


//----------------------------------------------------
Viewer3D_PointParam::Viewer3D_PointParam(Viewer3D* parent): ParamBox(parent, "Point Parameters")
{
  parent_class = parent;
  CreateParameters();
}


//----------------------------------------------------
void Viewer3D_PointParam::CreateParameters()
{
  ami_wxGLCanvas* mc = parent_class->m_canvas;


  //--------------------------------------------------
  //  Point Action
  //--------------------------------------------------

  AddEnumeration( &_id_point_action, 
   &mc->_point_action,
   "Point Action");

  AddEnumChoice( _id_point_action, 
   &_id_point_info,    "Info");
  AddEnumChoice( _id_point_action, 
   &_id_point_info,    "Select");
  AddEnumChoice( _id_point_action, 
   &_id_point_remove,  "Remove");
  AddEnumChoice( _id_point_action, 
   &_id_point_connect, "Connect");
  AddEnumChoice( _id_point_action, 
   &_id_point_connect, "Junction");
  AddEnumChoice( _id_point_action, 
   &_id_point_connect, "Min path");

  EnumerationDefaut( _id_point_action, mc->_point_action);


  //--------------
  // Remove Selection
  //
  AddButton( &_id_points_remove_selection,  
	       "Remove Selection",
	       (void*)CB_points_remove, 
	       (void*)parent_class);


  //--------------
  // Remove Non Selected
  //
  AddButton( &_id_points_remove_non_selected,  
	       "Remove Non Selected",
	       (void*)CB_points_remove_non_selected, 
	       (void*)parent_class);


  //--------------
  // Connect Selection
  //
  AddButton( &_id_points_connect_selection,  
	       "Connect Selection",
	       (void*)CB_points_connect, 
	       (void*)parent_class);

  //--------------
  // New Selection
  //
  AddButton( &_id_points_new_selection,  
	       "New Selection",
	       (void*)CB_points_new, 
	       (void*)parent_class);

/*
  //--------------
  // Save Selection
  //
  AddButton( &_id_points_save_selection,  
	       "Save Selection",
	       (void*)CB_points_save_selection, 
	       (void*)parent_class);
*/

  //--------------
  EnleveBouttons();
  CreeDialogue( );
  MAJ();
}


//----------------------------------------------------------------
void Viewer3D_PointParam::CB_points_connect(void* cd)
//                       ----------------
{
    Viewer3D*    tgl = (Viewer3D*) cd;
    ami_wxGLCanvas* mcanv = tgl->m_canvas;
    SurfacePoly* points;

  GLObject::ptr current(mcanv->_current_globject);
  if (!current.use_count()) return;
  points = (SurfacePoly*) current.get();

  points->ConnectSelectedPoints();
  points->GLRecomputeList();
  tgl->Paint();

} // CB_points_connect()


//----------------------------------------------------------------
void Viewer3D_PointParam::CB_points_new(void* cd)
//                       ---------------
{
    Viewer3D*    tgl = (Viewer3D*) cd;
    ami_wxGLCanvas* mcanv = tgl->m_canvas;
    SurfacePoly* points;

  GLObject::ptr current(mcanv->_current_globject);
  if (!current.use_count()) return;
  points = (SurfacePoly*) current.get();

  points->ClearSelectedPoints();
  points->GLRecomputeList();
  tgl->Paint();

} // CB_points_new()


/* TODO: use filenamedialog
//----------------------------------------------------------------
void Viewer3D_PointParam::CB_points_save_selection(void* cd)
//                       -----------------------
{
    Viewer3D*    tgl = (Viewer3D*) cd;
    ami_wxGLCanvas* mcanv = tgl->m_canvas;
    SurfacePoly* points;

  GLObject::ptr current(mcanv->_current_globject);
  if (!current.use_count()) return;
  points = (SurfacePoly*) current.get();

    int	    etat;

  tgl->_param_nom_image->AfficheDialogue();

  Si etat == SORTIE_OK Alors 
  //    points->SaveSelectedPoints(tgl->_nom_nouvelle_image);
  FinSi

} // CB_points_save_selection()
*/

//----------------------------------------------------------------
void Viewer3D_PointParam::CB_points_remove(void* cd)
//                       ---------------
{
    Viewer3D*    tgl = (Viewer3D*) cd;
    ami_wxGLCanvas* mcanv = tgl->m_canvas;
    SurfacePoly* points;

  GLObject::ptr current(mcanv->_current_globject);
  if (!current.use_count()) return;
  points = (SurfacePoly*) current.get();
 
  points->RemoveSelectedPoints();
  points->GLRecomputeList();
  tgl->Paint();

} // CB_points_remove()


//----------------------------------------------------------------
void Viewer3D_PointParam::CB_points_remove_non_selected(void* cd)
//                       ----------------------------
{
    Viewer3D*    tgl = (Viewer3D*) cd;
    ami_wxGLCanvas* mcanv = tgl->m_canvas;
    SurfacePoly* points;

  GLObject::ptr current(mcanv->_current_globject);
  if (!current.use_count()) return;
  points = (SurfacePoly*) current.get();

  points->RemoveNonSelected();
  points->GLRecomputeList();
  tgl->Paint();

} // CB_points_remove_non_selected()
