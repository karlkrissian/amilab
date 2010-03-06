/////////////////////////////////////////////////////////////////////////////
// Name:        isosurf.h
// Purpose:     wxGLCanvas demo program
// Author:      Brian Paul (original gltk version), Wolfram Gloger
// Modified by: Julian Smart
// Created:     04/01/98
// RCS-ID:      $Id: isosurf.h,v 1.5 2004/10/06 20:53:53 ABX Exp $
// Copyright:   (c) Julian Smart
// Licence:     wxWindows licence
/////////////////////////////////////////////////////////////////////////////

#ifndef _Viewer3D_h_
#define _Viewer3D_h_

// STL and Boost includes
#include <ostream>
#include <boost/iostreams/device/file.hpp>
#include <boost/iostreams/stream.hpp>
#include <boost/shared_ptr.hpp>
#include "DefineClass.hpp"

// wxWidgets includes
#ifdef __GNUG__
#pragma implementation
#pragma interface
#endif

// For compilers that support precompilation, includes "wx.h".
#include "wx/wxprec.h"
#include <wx/glcanvas.h>

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

#if !wxUSE_GLCANVAS
    #error "OpenGL required: set wxUSE_GLCANVAS to 1 and rebuild the library"
#endif

#include "wx/timer.h"
#include "wx/math.h"
#include "wx/toolbar.h"
#include "wx/aui/aui.h"

// wxParams includes
#include "wxParamTypes.hpp"
#include "MyToolBar.h"

#include "ami_wxGLCanvas.hpp"
#include "ParamBox.hpp"
#include "ParamPanel.hpp"

// AMILab includes
#include "Viewer3D_ViewParam.h"
#include "Viewer3D_ProjParam.h"
#include "Viewer3D_BackgroundParam.h"
#include "Viewer3D_MaterialParam.h"
#include "Viewer3D_LightingParam.h"
#include "Viewer3D_FogParam.h"
#include "Viewer3D_VectorsParam.h"
#include "Viewer3D_LineParam.h"
#include "Viewer3D_PointParam.h"

class Viewer3D;
typedef boost::shared_ptr<Viewer3D> Viewer3D_ptr;
typedef boost::weak_ptr  <Viewer3D> Viewer3D_wptr;



class Viewer3D:  public wxFrame
{

  DEFINE_CLASS(Viewer3D);

#define MAX_COMP_SURF 10

  Viewer3D_wptr   _compare_surf[MAX_COMP_SURF];

public:
  // Own deleter for boost shared pointers
  class deleter
  {
    public:
      void operator()(Viewer3D * p)
      {
        // will be destroyed by its parent which is the main application window
        // but Destroy() is ok and it closes the window too
         p->Destroy();
      }
  };

    Viewer3D(wxFrame *frame, const wxString& title, const wxPoint& pos = wxDefaultPosition,
        const wxSize& size = wxDefaultSize, long style = wxDEFAULT_FRAME_STYLE | wxFRAME_FLOAT_ON_PARENT );

  // Constructor for a shared pointer with the deleter
  static Viewer3D_ptr Create_ptr(
      wxFrame *frame,
      const wxString& title,
      const wxPoint& pos = wxDefaultPosition,
      const wxSize& size = wxDefaultSize,
      long style = wxDEFAULT_FRAME_STYLE)
    {
        Viewer3D_ptr px(new
            Viewer3D(frame,title,pos,size,style),
            Viewer3D::deleter());
        return px;
    }


  virtual ~Viewer3D();

  ami_wxGLCanvas *m_canvas;

  wxAuiManager&  GetAuiManager() {return m_mgr; };
  wxAuiNotebook* GetParamBook()  { return _param_book; }

  void AddCompSurf( Viewer3D_ptr comp_surf);

  void CreateGLCanvas();
  ami_wxGLCanvas* GetCanvas() { return m_canvas;}

  void SetCloseFunction( void* function, void* data )
  {
     CloseFunction = function;
     CloseData = data;
  }

  void CreateParamBook(wxWindow* parent);
  bool AddParamPage(wxWindow* page, const wxString& caption,
                    bool select = false, const wxBitmap& bitmap = wxNullBitmap);
  bool RemoveParamPage(wxWindow* page);
  bool ParamIsDisplayed(wxWindow* page);

protected :

  void* CloseFunction;
  void* CloseData;
  
  wxAuiManager m_mgr;
  MyAuiToolBar*   m_toolbar;
  wxAuiNotebook* _param_book;
  wxString     _initial_perspective;
  
  wxMenuBar*  menuBar;
  wxMenu*     menuFile;
  wxMenu*     menuOptions;
  wxMenu*     menuView;
  wxMenuEnum* _wxm_options_move;
  wxMenuEnum* _wxm_options_GLmode;
  wxMenuEnum* _wxm_options_shade;
  
  int proj_id;
  int fog_id;
  int bb_id;
  int glmode_id;

public:

    // 3D View parameters (object transformation)
    Viewer3D_ViewParam::ptr _param_view;

    // Gestion des parametres de la projection 3D
    Viewer3D_ProjParam::ptr _param_proj;

    //  Background Color
    Viewer3D_BackgroundParam::ptr _param_backgroundcolor;

    //  Gestion des parametres des objets
    Viewer3D_MaterialParam::ptr _param_material;

    //  Lighting Parameters
    Viewer3D_LightingParam::ptr _param_light;

    //  Fog effect Parameters
    Viewer3D_FogParam::ptr      _param_fog;

    //  Vector Field Parameters
    Viewer3D_VectorsParam::ptr _param_vectors;

    //  Vector Field Parameters
    Viewer3D_LineParam::ptr    _param_lines;

    //  Vector Field Parameters
    Viewer3D_PointParam::ptr    _param_points;


    void UpdateMenu();

    void UpdateObjectListGui()
    {
      _param_material->UpdateGui();
    }

    void Paint( bool display=true) { m_canvas->Paint( display); }
    void CompSurfPaint();


private:

  void CreateParameterWindows();

  void Create_wxMenu();

  wxAuiToolBar* CreateAuiToolBar(long style,
        wxWindowID id);

  void Create_Toolbar();

  void CloseWindow();

  /// File Menu
  void CB_Close(wxCommandEvent& event);

  /// Displays or Hides a Parameter Panel
  void ToggleParamPanel(ParamPanel* p);

  /// Options Menu
  void ReDraw              (wxCommandEvent& event);
  void CB_material_visible (wxCommandEvent& event);
  void CB_proj_visible     (wxCommandEvent& event);
  void CB_lighting_visible (wxCommandEvent& event);
  void CB_fog_visible      (wxCommandEvent& event);
  void CB_vectors_visible  (wxCommandEvent& event);
  void CB_lines_visible    (wxCommandEvent& event);
  void CB_points_visible   (wxCommandEvent& event);

  void CB_BackgroundColor (wxCommandEvent&);

  void OnMouseEvent       (wxMouseEvent& event)
  {
    //  printf("OnMouseEvent() \n");
  }
  void OnChar             (wxKeyEvent& event)
  {
    printf("OnChar() \n");
  }

  void OnSize(wxSizeEvent& event);
  void OnClose(wxCloseEvent& event);

  // Toolbar callbacks
  void CB_Ouvrir_surface        (wxCommandEvent&);

  void CB_PixmapCenterNormalize (wxCommandEvent&);
  /// @cond wxCHECK
  #if (wxCHECK_VERSION(2,9,0))
    void CB_ViewParam(wxCommandEvent&);
  #else
    void CB_ViewParam(wxAuiToolBarEvent&);
  #endif
  /// @endcond


public:
  static void CB_redessine           (void* cd);
  static void CB_FogParam            (void* cd);
  static void CB_ProjParam           (void* cd);

private:

  DECLARE_EVENT_TABLE()
};


#endif // #ifndef _Viewer3D_h

