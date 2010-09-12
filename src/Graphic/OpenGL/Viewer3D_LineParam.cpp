

#include "Viewer3D.hpp"
#include "ParamPanel.hpp"
#include "Viewer3D_LineParam.h"

//----------------------------------------------------
Viewer3D_LineParam::Viewer3D_LineParam(Viewer3D* parent): ParamPanel(parent, "Line Parameters")
{
  parent_class = parent;
  CreateParameters();
}


//----------------------------------------------------
void Viewer3D_LineParam::CreateParameters()
{
  ami_wxGLCanvas* mc = parent_class->m_canvas;

  //--------------------------------------------------
  //  Line Action
  //--------------------------------------------------

  AddEnumeration( &_id_line_action, 
	   5, 
	   &mc->_line_action,
	   "Line Action");

  AddEnumChoice( _id_line_action, 
	   &_id_line_info,    "Info");
  AddEnumChoice( _id_line_action, 
	   &_id_line_select,    "Select");
  AddEnumChoice( _id_line_action, 
	   &_id_line_remove,  "Remove");
  AddEnumChoice( _id_line_action, 
	   &_id_line_connect, "Connect");
  AddEnumChoice( _id_line_action, 
	   &_id_line_connect, "Junction");

  EnumerationDefaut( _id_line_action, mc->_line_action);


  //--------------
  // Remove Selection
  //
  AddButton( &_id_lines_remove_selection,  
       "Remove Selection",
       (void*) CB_lines_remove, 
       (void*) parent_class);

  //--------------
  // Remove Non Selected
  //
  AddButton( &_id_lines_remove_non_selected,  
       "Remove Non Selected",
       (void*) CB_lines_remove_non_selected, 
       (void*) parent_class);


  //--------------
  // Connect Selection
  //
  AddButton( &_id_lines_connect_selection,  
			       "Connect Selection",
			       (void*) CB_lines_connect, 
			       (void*) parent_class);

  //--------------
  // New Selection
  //
  AddButton( &_id_lines_new_selection,  
			       "New Selection",
			       (void*) CB_lines_new, 
			       (void*) parent_class);


  //--------------
  // Undo Last Operation
  //
  AddButton( &_id_lines_undo,  
			       "Undo Last",
			       (void*) CB_lines_undo, 
			       (void*)parent_class);


/*
  //--------------
  // Save Selection
  //
  AddButton( &_id_lines_save_selection,  
			       "Save Selection",
			       CB_lines_save_selection, 
			       (void*)this);

*/

  //--------------
  EnleveBouttons();
  CreeDialogue( );
  MAJ();
}


//----------------------------------------------------------------
void Viewer3D_LineParam :: CB_lines_connect(void* cd)
//                       ----------------
{
    Viewer3D*    tgl = (Viewer3D*) cd;
    ami_wxGLCanvas* mcanv = tgl->m_canvas;
    SurfacePoly* points;

  GLObject::ptr current(mcanv->_current_globject);
  if (current.use_count()) {
    points = (SurfacePoly*) current.get();
    points->ConnectSelection();
    points->GLRecomputeList();
    tgl->Paint();
  }

} // CB_lines_connect()


//----------------------------------------------------------------
void Viewer3D_LineParam :: CB_lines_new(void* cd)
//                       ---------------
{
    Viewer3D*    tgl = (Viewer3D*) cd;
    ami_wxGLCanvas* mcanv = tgl->m_canvas;
    SurfacePoly* points;

  GLObject::ptr current(mcanv->_current_globject);
  if (current.use_count()) {
    points = (SurfacePoly*) current.get();
    if (points==NULL) return;

    points->ClearSelectedLines();
    points->GLRecomputeList();
    tgl->Paint();
  }

} // CB_lines_new()

/*
//----------------------------------------------------------------
void Viewer3D_LineParam :: CB_lines_save_selection(void* cd)
//                       -----------------------
{

   
    Viewer3D_LineParam*         tgl = (Viewer3D_LineParam*) cd;
    int	    etat;
    SurfacePoly* Lines;
    GLObject*  current;

  current = tgl->GetGLObject(tgl->_current_globject_num);
  if (current!=NULL) {
  
    Lines = (SurfacePoly*) current;
    tgl->_param_nom_image->AfficheDialogue();
    
    Si etat == SORTIE_OK Alors 
      Lines->SaveSelectedLines((char*)tgl->_nom_nouvelle_image.c_str());
    FinSi
   }

} // CB_lines_save_selection()
*/


//----------------------------------------------------------------
void Viewer3D_LineParam :: CB_lines_remove(void* cd)
//                       ---------------
{
    Viewer3D*    tgl = (Viewer3D*) cd;
    ami_wxGLCanvas* mcanv = tgl->m_canvas;
    SurfacePoly* points;

  GLObject::ptr current(mcanv->_current_globject);
  if (current.use_count()) {
    points = (SurfacePoly*) current.get();
    if (points==NULL) return;
    points->RemoveSelection();
    points->GLRecomputeList();
    tgl->Paint();
  }

} // CB_lines_remove()


//----------------------------------------------------------------
void Viewer3D_LineParam :: CB_lines_remove_non_selected(void* cd)
//                       ----------------------------
{
    Viewer3D*    tgl = (Viewer3D*) cd;
    ami_wxGLCanvas* mcanv = tgl->m_canvas;
    SurfacePoly* points;

  GLObject::ptr current(mcanv->_current_globject);
  if (current.use_count()) {
    points = (SurfacePoly*) current.get();
    if (points==NULL) return;
    points->RemoveNonSelected();
    points->GLRecomputeList();
    tgl->Paint();
  }

} // CB_lines_remove_non_selected()


//----------------------------------------------------------------
void Viewer3D_LineParam :: CB_lines_undo(void* cd)
//                       -------------
{
    Viewer3D*    tgl = (Viewer3D*) cd;
    ami_wxGLCanvas* mcanv = tgl->m_canvas;
    SurfacePoly* points;

  GLObject::ptr current(mcanv->_current_globject);
  if (current.use_count()) {
    points = (SurfacePoly*) current.get();
    if (points==NULL) return;
    points->UndoLast();
    points->GLRecomputeList();
    tgl->Paint();
  }
} // CB_lines_undo()



