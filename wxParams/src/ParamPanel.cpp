
/*
    ==================================================
    Software : AMILab
    Authors  : Karl Krissian
    Email    : karl@bwh.harvard.edu

    AMILab is a language for image processing
    ==================================================
    Copyright (C) 1996-2005  Karl Krissian

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public1, wxEXPAND | wxALL, 5
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

    ================================================== 
   The full GNU Lesser General Public License file is in Devel/Sources/Prog/LesserGPL_license.txt
*/
// 
//  Fichier ParamPanel.cpp
//
//  Creation d'une boite de dialogue pour les parametres
//  de maniere generique
//
//  Karl KRISSIAN   Sophia Antipolis, le 24-07-96
//
//  Sophia Antipolis,       le 04-10-96,   Creation des mises a jour MAJ()
//

//extern unsigned char GB_debug;

#define _use_wxWidgets_

#include <stdio.h>
#include "ParamPanel.hpp"
#include "wxParamTypes.hpp"
#include "wxNumericParameter.h"
#include "wxColorParameter.h"
#include "wxBooleanParameter.h"
#include "wxStringParameter.h"
#include "wxFilenameParameter.h"
#include "wxDirnameParameter.h"

#include <wx/scrolbar.h>
#include <wx/scrolwin.h>
#include <iostream>
//#include <wx/artprov.h>

#ifdef USING_AUINB
  #include <wx/aui/auibook.h>
#else
  #include <wx/notebook.h>
#endif

using namespace std;

#include "boost/format.hpp"

/*
#if defined(_MSC_VER) || defined(__MINGW32__)
inline double round( double d )
{
return floor( d + 0.5 );
}
#endif
*/

#ifdef _MSC_VER
  #define __func__ __FUNCTION__
#endif

#define macro_CheckParameterId(id, returning) \
  if ((id < 0) || (id >= NbParameters())) { \
    cerr  << __func__ << " " \
          << this->GetName().mb_str() << "\t" \
          <<  "Error \t wrong widget id" \
          << id << " " << NbParameters() << "\n" \
          << endl; \
    returning; \
  } // end if

IMPLEMENT_CLASS(ParamPanel, wxPanel)

BEGIN_EVENT_TABLE(ParamPanel, wxPanel)
  EVT_BUTTON(wxID_OK, ParamPanel::OnOK)
  EVT_BUTTON(wxID_APPLY, ParamPanel::OnApply)
  EVT_BUTTON(wxID_CANCEL, ParamPanel::OnCancel)
  EVT_CLOSE(ParamPanel::OnClose)
END_EVENT_TABLE()

//==============================================================================
//      BOITE DE PARAMETRES
//==============================================================================


//------------------------------------------------------------------------------
ParamPanel::ParamPanel( wxWindow* parent,
//                           ------------
                                const char* titre,
                                long style ):
      wxScrolledWindow( parent, 
                wxID_ANY,
                wxDefaultPosition,
                wxDefaultSize,
                wxTAB_TRAVERSAL 
                | wxVSCROLL
                | wxFULL_REPAINT_ON_RESIZE 
                ,
                wxString::FromAscii(titre)
                ) 
// the dialog needs to have a NULL parent
// or it crashes when closing the window
// wxPropertySheetDialog(w, wxID_ANY,
// wxString(_T(titre)))
{

  this->SetSizeHints(200,150);
//,700,800);

  //SetSheetStyle(wxPROPSHEET_TREEBOOK);
  //SetSheetStyle(style);

  // Add page
  _main_sizer = new wxBoxSizer( wxVERTICAL);
  SetSizer(_main_sizer);
  _current_sizer.push(_main_sizer);

  _inclu_bouttons = false;

//  wxScrollBar* sb = new wxScrollBar(this, wxID_ANY);
//  _current_sizer.top()->Add(sb, 1, wxEXPAND, 0);
//  this->SetScrollbar(wxVERTICAL, 0, 16, 50);
  this->SetScrollbars(3,3,10,10);
  this->EnableScrolling(true,true);

//  _toolbar = new wxToolBar(this,wxID_ANY);
//  _toolbar->AddTool(wxID_ANY, wxT("Quit"), wxArtProvider::GetBitmap(wxART_QUIT),
//    wxT("Quit Panel"));


} //  ParamPanel()


//---------------------------------------------------------------
int ParamPanel::BeginBook()
{
  NotebookClass* nb;


  nb = new NotebookClass( CurrentParent()
                          ,wxID_ANY
                          ,wxDefaultPosition
                          ,wxDefaultSize
#ifdef USING_AUINB
                          , wxAUI_NB_TOP 
                            //| wxAUI_NB_TAB_SPLIT 
                            //| wxAUI_NB_TAB_MOVE 
                            | wxAUI_NB_SCROLL_BUTTONS
                            | wxAUI_NB_WINDOWLIST_BUTTON 
#endif
                      //wxVSCROLL
                      );
  //  nb->SetFont(wxFont(12, wxDEFAULT, wxNORMAL, wxBOLD));

  //nb->SetOwnBackgroundColour(wxColour("#e1dfff"));
  _current_book.push(nb);
  _current_sizer.top()->Add(GetBookCtrl(), 1, wxEXPAND, 0);

  _tab_books.push_back(nb);
  return (int)_tab_books.size()-1;

} // ParamPanel::BeginBook()

//---------------------------------------------------------------
void ParamPanel::EndBook()
{
  NotebookClass* book = GetBookCtrl();

  if (book) {
    // closes previous page if any
    if (GetBookCtrl()->GetPageCount())
      this->EndPanel();
  
    _current_book.pop();
  } 
  else 
    cerr << "EndBook() no current book ... ! " << endl;
    

} // ParamPanel::EndBook()


//---------------------------------------------------------
// add a page to the book
// with a new panel
// if the book has another page, close it first
int ParamPanel::AddPage(wxScrolledWindow* panel, const std::string& panel_name)
//             -------
{
  wxBoxSizer* panelsizer;

  if (!GetBookCtrl()) {
    cerr << "AddPage without any Book ! " 
          << panel_name << endl;
    return 0;
  }

  // closes previous page if any
  if (GetBookCtrl()->GetPageCount())
    this->EndPanel();

  panel->SetScrollbars(3,3,10,10);
  panel->EnableScrolling(true,true);
  _tab_panels.push_back(panel);

  _panels.push( panel);

  GetBookCtrl()->AddPage( LastPanel(),
                          wxString::FromAscii(panel_name.c_str()));
  LastPanel()->SetToolTip(wxString::FromAscii(panel_name.c_str()));
  panelsizer = dynamic_cast<wxBoxSizer*>(LastPanel()->GetSizer());
  if (panelsizer==NULL) {
    panelsizer   = new wxBoxSizer( wxVERTICAL );
    LastPanel()->SetSizer(panelsizer);
  }
  _current_sizer.push(panelsizer);

  return (int)_tab_panels.size()-1;
}

//---------------------------------------------------------
// add a page to the book
// with a new panel
// if the book has another page, close it first
int ParamPanel::AddPage(const std::string& panel_name)
//             -------
{
  wxBoxSizer* panelsizer;

  if (!GetBookCtrl()) {
    cerr << "AddPage without any Book ! " 
          << panel_name << endl;
    return 0;
  }

  // closes previous page if any
  if (GetBookCtrl()->GetPageCount())
    this->EndPanel();

  wxScrolledWindow* panel = 
    new wxScrolledWindow(GetBookCtrl(),
                wxID_ANY,
                wxDefaultPosition,
                wxDefaultSize,
                wxTAB_TRAVERSAL|
                wxFULL_REPAINT_ON_RESIZE 
                |wxVSCROLL
                );
  panel->SetScrollbars(3,3,10,10);
  panel->EnableScrolling(true,true);
  _tab_panels.push_back(panel);

  _panels.push( panel);

  GetBookCtrl()->AddPage( LastPanel(),
                          wxString::FromAscii(panel_name.c_str()));
  LastPanel()->SetToolTip(wxString::FromAscii(panel_name.c_str()));
  panelsizer   = new wxBoxSizer( wxVERTICAL );
  LastPanel()->SetSizer(panelsizer);
  _current_sizer.push(panelsizer);

  return (int)_tab_panels.size()-1;
} // AddPage()


//---------------------------------------------------------
int ParamPanel::BeginPanel(const std::string& panel_name)
//             --------
{
  wxBoxSizer* panelsizer;

  wxScrolledWindow* panel = new wxScrolledWindow(CurrentParent(),
                            wxID_ANY, 
                            wxDefaultPosition, 
                            wxDefaultSize, 
                            wxTAB_TRAVERSAL  | wxVSCROLL
                          );
//  panel->SetScrollbars(3,3,10,10);
//  panel->EnableScrolling(true,true);
  _tab_panels.push_back(panel);

  _panels.push( panel);

  LastPanel()->SetToolTip(wxString::FromAscii(panel_name.c_str()));

  panelsizer   = new wxBoxSizer( wxVERTICAL );

  LastPanel()->SetSizer(panelsizer);

  // add new panel to the current sizer
  _current_sizer.top()->Add(LastPanel(), 0, wxEXPAND, 0);
  _current_sizer.push(panelsizer);

  return (int)_tab_panels.size()-1;
} // BeginPanel()


//-------------------------------------------------------
void ParamPanel::EndPanel()
{
//  LastPanelSizer()->SetSizeHints(LastPanel());
  LastPanelSizer()->Fit(LastPanel());
  _current_sizer.pop();
  _panels.pop();

} // ParamPanel::EndPanel()



//------------------------------------------------------------------------------
ParamPanel::~ParamPanel()
//                           -----------
{
//  if (GB_debug)  
//      cerr << boost::format("~ParamPanel(%s)")
//            %this->GetName().c_str() << endl;

} // ~ ParamPanel()


//------------------------------------------------------------------------------
void ParamPanel::RecupereDimensions( int* l, int* h)
//                ------------------
{
  wxSize s = this->GetSize();
  *l = s.GetWidth();
  *h = s.GetHeight();
} // RecupereDimensions( )


/**
  Adds the param w to the current top sizer
*/
template <class T>
wxSizerItem* ParamPanel::AddParam( T* w,
        int proportion,
        int border,
        int flag)
{

  wxBoxSizer * s = _current_sizer.top();
  switch(s->GetOrientation()) {
    case wxHORIZONTAL: 
      border = 5;
      flag = wxEXPAND | wxALL; //| wxHORIZONTAL;
    break;
    case wxVERTICAL: 
      border = 5;
      flag = wxEXPAND | wxALL; //| wxVERTICAL;
    break;
    default: break;
  }

  return 
      s->Add( w, proportion, flag,  border);
}


//----------------------------------------------------------
wxSizerItem* ParamPanel::AddWidget( wxWindow* w, int proportion)
//
{
  return AddParam<wxWindow>(w, proportion);
} // AddWidget()


//--------------------------------------------------------------
wxSizerItem* ParamPanel::AddWidget( wxSizer* w)
//
{
  return AddParam<wxSizer>(w);
} // AddWidget()


//--------------------------------------------------------------
unsigned char ParamPanel::AddBoolean(
//                        ----------
    int* id, unsigned char* param, 
    const char* libelle,
    type_booleen type,
    const std::string& tt
    )
{
  wxBooleanParameter* wxbp = new wxBooleanParameter(
      CurrentParent(), param, libelle);
  if (tt!="") wxbp->SetToolTip(GetwxStr(tt.c_str()));

  ParamInfo pi(  TYPE_PARAMETER_BOOLEEN,
                 wxbp,
                 AddWidget(wxbp));

  _tab_param.push_back(pi);
  *id = (int)_tab_param.size()-1;

  return( true);
} // AddBoolean()


//------------------------------------------------------------------------------
void ParamPanel::BooleanDefault( int id, unsigned char defaut)
//                -------------
{
  macro_CheckParameterId(id,return)

  if (_tab_param[id].GetType() != TYPE_PARAMETER_BOOLEEN) {
    printf("ParamPanel::BooleanDefault \t Erreur, identificateur non valide\n");
    return;
  } // end if
  
  if (_tab_param[id].GetWidget()!=NULL) 
    ((wxBooleanParameter*) _tab_param[id].GetWidget())->FixeDefaut( defaut);

} // BooleanDefault()


//--------------------------------------------------------------
unsigned char ParamPanel::AddInteger( int* id, int* param, 
//                      ------------
                const char* libelle,
                const std::string& tt)
{
  *id = AddInteger(param,libelle,tt);
  return( true);
} // AddInteger()


//--------------------------------------------------------------
int ParamPanel::AddInteger( int* param, 
//                   ------------
                const char* libelle,
                const std::string& tt)
{
  wxNumericParameter<int>* wxi = new 
    wxNumericParameter<int>( CurrentParent(), param, libelle);
  if (tt!="") wxi->SetToolTip(GetwxStr(tt.c_str()));
  wxi->SetDecimate(0);

  ParamInfo pi( TYPE_PARAMETER_ENTIER,
                wxi,
                AddWidget(wxi));
  _tab_param.push_back(pi);
  return (int)_tab_param.size()-1;
} // AddInteger()


//------------------------------------------------------------------------------
void ParamPanel::IntegerConstraints( int id, int min, int max, int defaut)
//                -----------------
{
  macro_CheckParameterId(id, return)

  if (_tab_param[id].GetType() != TYPE_PARAMETER_ENTIER) {
    printf("ParamPanel::IntegerConstraints \t Erreur, identificateur non valide\n");
    return;
  } // end if

  if (_tab_param[id].GetWidget()!=NULL)
    ((wxNumericParameter<int>*) _tab_param[id].GetWidget())->SetConstraints( min, max, defaut);

} // IntegerConstraints()


//------------------------------------------------------------------------------
void ParamPanel::ParamIntGetLimits( int id, int& min, int& max)
{
  macro_CheckParameterId(id, return)

  if (_tab_param[id].GetType() != TYPE_PARAMETER_ENTIER) {
    printf("ParamPanel::ParamIntGetLimits \t Erreur, identificateur non valide\n");
    return;
  } // end if
  
  if (_tab_param[id].GetWidget()!=NULL)
    ((wxNumericParameter<int>*) _tab_param[id].GetWidget())->GetLimits( min, max);

} // ParamIntGetLimits()


//------------------------------------------------------------
bool ParamPanel::AddFloat(  int* id, float* param,
                            const char* libelle, int precision,
                            const std::string& tt)
{
  *id = AddFloat(param,libelle,precision,tt);
  return( true);
} // AddFloat()


//-----------------------------------------------------------
int  ParamPanel::AddFloat(
//               --------
      float* param,
      const char* libelle, 
      int precision,
      const std::string& tt)
{
  wxNumericParameter<float>* wxi = new wxNumericParameter<float>(
      CurrentParent(), param, libelle);
  if (tt!="") wxi->SetToolTip(GetwxStr(tt.c_str()));

  wxi->SetDecimate(precision);

  ParamInfo pi( TYPE_PARAMETER_REEL,
                wxi,
                AddWidget(wxi));
  _tab_param.push_back(pi);
  return (int)_tab_param.size()-1;
} // AddFloat()


//---------------------------------------------------------------
void ParamPanel::FloatConstraints( int id, const float& min, const float& max, const float& defaut)
//                ---------------
{
  macro_CheckParameterId(id, return)

  if (_tab_param[id].GetType() != TYPE_PARAMETER_REEL) {
    printf("ParamPanel::FloatConstraints \t Erreur, identificateur non valide\n");
    return;
  } // end if

  if (_tab_param[id].GetWidget()!=NULL)
    ((wxNumericParameter<float>*) _tab_param[id].GetWidget())->SetConstraints( min, max, defaut);

} // FloatConstraints()

//---------------------------------------------------------------
void ParamPanel::ParamFloatGetLimits( int id, float& min, float& max)
{
  macro_CheckParameterId(id, return)

  if (_tab_param[id].GetType() != TYPE_PARAMETER_REEL) {
    printf("ParamPanel::ParamFloatGetLimits \t Erreur, identificateur non valide\n");
    return;
  } // end if
  
  if (_tab_param[id].GetWidget()!=NULL)
      ((wxNumericParameter<float>*) _tab_param[id].GetWidget())->GetLimits( min, max);

} // ParamFloatGetLimits()

//-----------------------------------------------------------
void ParamPanel::ParamShowSlider( int id, bool show)
{
  macro_CheckParameterId(id, return)

  if (_tab_param[id].GetType() == TYPE_PARAMETER_REEL) {
    if (_tab_param[id].GetWidget()!=NULL)
      ((wxNumericParameter<float>*) _tab_param[id].GetWidget())->ShowSlider( show);
  } else 
  if (_tab_param[id].GetType() == TYPE_PARAMETER_ENTIER) {
    if (_tab_param[id].GetWidget()!=NULL)
      ((wxNumericParameter<int>*) _tab_param[id].GetWidget())->ShowSlider( show);
  } else {
    printf("ParamPanel::ParamFloatGetLimits \t Erreur, identificateur neither float nor integer\n");
    return;
  } // end if
  
} // ParamShowSlider()


//------------------------------------------------------------------------------
unsigned char ParamPanel::AddEnumeration( int* id, int taille, 
//                      --------------
            int* param, const char* libelle,
                type_enum type,
                  const std::string& tt) 
{
  wxEnumerationParameter* wxe = new wxEnumerationParameter(
      CurrentParent(), param, libelle, tt);

  ParamInfo pi( TYPE_PARAMETER_ENUMERATION,
                wxe,
                AddWidget(wxe));
  _tab_param.push_back(pi);

  *id = (int)_tab_param.size()-1;
  return( true);
} // AddEnumeration()


//------------------------------------------------------------------------------
unsigned char ParamPanel::AddEnumeration( int* id, 
//                      --------------
            int* param, const char* libelle,
                type_enum type,
                  const std::string& tt) 
{
  wxEnumerationParameter* wxe = new wxEnumerationParameter(
      CurrentParent(), param, libelle,tt);

  ParamInfo pi( TYPE_PARAMETER_ENUMERATION,
                wxe,
                AddWidget(wxe));
  _tab_param.push_back(pi);

  *id = (int)_tab_param.size()-1;
  return( true);
} // AddEnumeration()


//------------------------------------------------------------------------------
unsigned char ParamPanel::AddEnumChoice( int id, 
//                   ---------------
            int* id_enum_choix,
            const char* libelle,
            const char* pixmap_name)
{
  macro_CheckParameterId(id, return false)

  if (_tab_param[id].GetType() != TYPE_PARAMETER_ENUMERATION) {
    printf("ParamPanel::AddEnumChoice \t Erreur, identificateur non valide\n");
    return false;
  } // end if

  int res2;

  if (_tab_param[id].GetWidget()!=NULL) {
    ((wxEnumerationParameter*) _tab_param[id].GetWidget())->AddChoice( &res2, libelle );  
    *id_enum_choix = res2;
  }
  
    return 1;

} // AddEnumChoice()


//------------------------------------------------------------------------------
unsigned char ParamPanel::AddEnumChoice( int id, 
//                   ---------------
            int* id_enum_choix, 
            const char* libelle,
            const char** pixmap_string)
{
  macro_CheckParameterId(id, return false)

  if (_tab_param[id].GetType() != TYPE_PARAMETER_ENUMERATION) {
    printf("ParamPanel::AddEnumChoice \t Erreur, identificateur non valide\n");
    return false;
  } // end if

  int res2=0;
  
  if (_tab_param[id].GetWidget()!=NULL) {
    ((wxEnumerationParameter*) _tab_param[id].GetWidget())->AddChoice( &res2, libelle );  
      *id_enum_choix=res2;
  }
  
    return 1;

} // AddEnumChoice()


//------------------------------------------------------------------------------
void ParamPanel::EnumerationDefaut( int id, int id_defaut)
//                -----------------
{
  macro_CheckParameterId(id, return)

  if (_tab_param[id].GetType() != TYPE_PARAMETER_ENUMERATION) {
    printf("ParamPanel::ContraintesEnumeration \t Erreur, identificateur non valide\n");
    return;
  } // end if

  if (_tab_param[id].GetWidget()!=NULL) 
    ((wxEnumerationParameter*) _tab_param[id].GetWidget())->SetSelection( id_defaut ); 

} // EnumerationDefaut()


//--------------------------------------------------------------
bool ParamPanel::AddListChoice( int* id,  
//               -------------
          string_ptr selection_param,
          const char* libelle, 
          const boost::shared_ptr<wxArrayString>& choicelist,
          void* update_cb,
          type_enum type,
          const std::string& tooltip,
          bool allowdrop
          )
{
  wxEnumerationParameter* wxe = new wxEnumerationParameter(
      CurrentParent(), selection_param, libelle, tooltip,allowdrop);
  std::string update_string = "Update list";
  wxe->AddUpdateCallback(update_cb,update_string);
  wxe->SetChoices(choicelist);

  ParamInfo pi( TYPE_PARAMETER_ENUMERATION,
                wxe,
                AddWidget(wxe));
  _tab_param.push_back(pi);

  *id = (int)_tab_param.size()-1;
  return( true);
}

//--------------------------------------------------------------
unsigned char ParamPanel::AddButton( int* id,  const char* libelle,
//                      ---------
        void* callback,
        void* data,
        const std::string& tt
        )
{
  // add a wxButton
  wxButtonParameter* wxbp = new wxButtonParameter(
      CurrentParent(), libelle, callback, data);
  if (tt!="") wxbp->SetToolTip(GetwxStr(tt.c_str()));

  ParamInfo pi( TYPE_PARAMETER_BOUTTON,
                wxbp,
                AddWidget(wxbp));
  _tab_param.push_back(pi);
  *id = (int)_tab_param.size()-1;
  return( true);
} // AddButton()


//-----------------------------------------------------------------
unsigned char ParamPanel::AddPixmapButton( int* id,  const char* libelle,
//                      ---------------
                      void* callback,
                      void* data,
                      const char** pixmap_string,
                      const std::string& tt
                      )
{
  // add a wxButton 
  wxBitmap bm(pixmap_string);
  wxBitmapButtonParameter* wxbp = new wxBitmapButtonParameter(CurrentParent(), libelle, bm, callback, data);
  if (tt!="") wxbp->SetToolTip(GetwxStr(tt.c_str()));

  ParamInfo pi( TYPE_PARAMETER_BOUTTON,
                wxbp,
                AddWidget(wxbp));
  _tab_param.push_back(pi);
  *id = (int)_tab_param.size()-1;
  return( true);
} // AddPixmapButton()


//-----------------------------------------------------------------
unsigned char ParamPanel::AddBitmapButton( int* id,  const char* libelle,
//                      ---------------
                      void* callback,
                      void* data,
                      const wxBitmap& bm,
                      const std::string& tt
                      )
{
  wxBitmapButtonParameter* wxbp = new wxBitmapButtonParameter(CurrentParent(), libelle, bm, callback, data);
  if (tt!="") wxbp->SetToolTip(GetwxStr(tt.c_str()));

  ParamInfo pi( TYPE_PARAMETER_BOUTTON,
                wxbp,
                AddWidget(wxbp));
  _tab_param.push_back(pi);
  *id = (int)_tab_param.size()-1;
  return( true);
} // AddPixmapButton()

//---------------------------------------------------------------
unsigned char ParamPanel::AddColor( int* id,
//                      --------
                    const char* libelle,
                    wxColour*  couleur,
                    const std::string& tt
                    )
{
  wxColorParameter* wxcp = new wxColorParameter(CurrentParent(), libelle, couleur);
  if (tt!="") wxcp->SetToolTip(GetwxStr(tt.c_str()));

  ParamInfo pi( TYPE_PARAMETER_COULEUR,
                wxcp,
                AddWidget(wxcp));
  _tab_param.push_back(pi);
  *id = (int)_tab_param.size()-1;
  return( true);
} // AddColor()


//----------------------------------------------------------------
unsigned char ParamPanel::AddLabel( int* id, const char* libelle,
//                      --------
                          const char* contenu, type_label type,
                                   const std::string& tt)
{
  wxLabelParameter* wxl = new wxLabelParameter(CurrentParent(), 
                                              libelle, contenu, type);
  if (tt!="") wxl->SetToolTip(GetwxStr(tt.c_str()));

  ParamInfo pi( TYPE_PARAMETER_LABEL,
                wxl,
                AddWidget(wxl));
  _tab_param.push_back(pi);
  *id = (int)_tab_param.size()-1;
  return( true);
} // AddLabel()


///--------------------------------------------------------------
void ParamPanel::SetLabelValue( int id,  const char* value)
//             -------------
{
   ((wxLabelParameter*) _tab_param[id].GetWidget())->SetValue( value);
} // SetLabelValue()

/*
//------------------------------------------------------------------------------
unsigned char ParamPanel::AjouteWidget( int* id,  Widget widget)
//                   ------------
{
  return( true);
} // AjouteWidget()
*/


//------------------------------------------------------------------------------
void ParamPanel::FixeVisible( int id, unsigned char visible)
//                -----------
{
  macro_CheckParameterId(id, return)

  if ((wxGenericWidget*) _tab_param[id].GetWidget() !=NULL) {
    // TODO: change visible to bool type
    if ((visible!=0)!=_tab_param[id].GetSizerItem()->IsShown())
    _tab_param[id].GetSizerItem()->Show((visible!=0));
  }
} // FixeVisible()


//--------------------------------------------------------
void ParamPanel::SetPositionProperties(
//               ---------------------
      int id, 
      int proportion,
      int border,
      int flags
      )
{
  macro_CheckParameterId(id, return)

  if ((wxGenericWidget*) _tab_param[id].GetWidget() !=NULL) {
    if (proportion>=0)
      _tab_param[id].GetSizerItem()->SetProportion( proportion);
    if (border>=0)
      _tab_param[id].GetSizerItem()->SetBorder(     border    );
    if (flags>=0)
      _tab_param[id].GetSizerItem()->SetFlag(       flags     );
  }
} // SetPositionProperties()

//--------------------------------------------------------
void ParamPanel::SetLastPositionProperties(
//               ---------------------
      int proportion,
      int border,
      int flags
      )
{
  SetPositionProperties( 
    (int)NbParameters()-1, proportion,border,flags);
} // SetLastPositionProperties()

//------------------------------------------------------------------------------
void ParamPanel::ChangedValueCallback( int id, void* callback, void* calldata)
//                --------------------
{
  macro_CheckParameterId(id, return)

  if ((wxGenericWidget*) _tab_param[id].GetWidget() !=NULL)
    ((wxGenericWidget*) _tab_param[id].GetWidget())->ChangedValueCallback( callback, calldata);

} // ChangedValueCallback()


//----------------------------------------------------------------
unsigned char ParamPanel::AjouteChaine( int* id, string_ptr param, 
//                      ------------
                const char* libelle,
                const std::string& tt
                )
{
  wxStringParameter* wsp;
  wsp= new wxStringParameter(CurrentParent(),param,libelle);

  ParamInfo pi( TYPE_PARAMETER_CHAINE,
                wsp,
                AddWidget(wsp));
  if (tt!="") wsp->SetToolTip(GetwxStr(tt.c_str()));
  _tab_param.push_back(pi);
  *id = (int)_tab_param.size()-1;
  return( true);
} // AjouteChaine()


//----------------------------------------------------------------
void ParamPanel::ContraintesChaine( int id, char* defaut)
//                -----------------
{
  macro_CheckParameterId(id, return)

  if (_tab_param[id].GetType() != TYPE_PARAMETER_CHAINE) {
    printf("ParamPanel::ContraintesChaine \t Erreur, identificateur non valide\n");
    return;
  } // end if

} // ContraintesChaine()


//------------------------------------------------------------------------------
unsigned char ParamPanel::AddFilename( int* id, string_ptr& param, 
//                   ----------------
                const char* libelle,
                const std::string& tt)
{
  wxFilenameParameter* wxi = new wxFilenameParameter(CurrentParent(), param, libelle);

  ParamInfo pi( TYPE_PARAMETER_ANY,
                wxi,
                AddWidget(wxi));

  if (tt!="") wxi->SetToolTip(GetwxStr(tt.c_str()));

  _tab_param.push_back(pi);
  *id = (int)_tab_param.size()-1;
  return( true);
} // AddFilename()


//------------------------------------------------------------------------------
// le troisieme parametre est le repertoire par defaut : non utilise
// le dernier parametre est le masque : non utilise
//
void ParamPanel::ContraintesNomFichier( int id, const char* defaut,
//                ---------------------
                const char* , const char* mask)
{
  macro_CheckParameterId(id, return)

  wxFilenameParameter* fnp;
  fnp = dynamic_cast<wxFilenameParameter*>
            (_tab_param[id].GetWidget());
  if (fnp==NULL) {
    printf("ParamPanel::ContraintesNomFichier \t Erreur, identificateur non valide\n");
    return;
  } // end if

  fnp->SetDefaultPath(defaut);
  fnp->SetWildcard(mask);

} // ContraintesNomFichier()


//------------------------------------------------------------
bool ParamPanel::AddDirname( 
//               ----------
                            int* id,
                            string_ptr& dirname,
                            const char* label,
                            const std::string& tt)
{
  wxDirnameParameter* wxi = new wxDirnameParameter(CurrentParent(), dirname, label);

  ParamInfo pi( TYPE_PARAMETER_ANY,
                wxi,
                AddWidget(wxi));

  if (tt!="") wxi->SetToolTip(GetwxStr(tt.c_str()));

  _tab_param.push_back(pi);
  *id = (int)_tab_param.size()-1;
  return( true);
}

//---------------------------------------------------------------------
void ParamPanel::EnleveBouttons( )
//                                --------------
{
  _inclu_bouttons = false;
} // CreeDialogue()


//---------------------------------------------------------------------
void ParamPanel::CreeDialogue( )
//                                ------------
{

//  if (_inclu_bouttons)   CreateButtons(wxOK|wxCANCEL|wxHELP);

//  LastPanelSizer()->Fit(LastPanel());
  this->Layout();

} // CreeDialogue()


//---------------------------------------------------------------------
void ParamPanel::ReAfficheParametres( )
//             -------------------
{
  //LastPanelSizer()->SetSizeHints(_current_panel);
  if (_panels.empty()) {
    this->Layout();
  } else
    LastPanelSizer()->Layout();

//  _current_panel->Layout();
//  _current_panel->SetClientSize(LastPanelSizer()->GetSize());
// too slow
//  LayoutDialog();
} // ReAfficheParametres()


//---------------------------------------------------------------------
void ParamPanel::RecupereValeur( int id )
//               ---------------
{
  macro_CheckParameterId(id, return)

  _tab_param[id].GetWidget()->UpdateValue();

} // RecupereValeurs()


//---------------------------------------------------------------------
void ParamPanel::RecupereValeurs( )
//                                ---------------
{
    int i;

  for( i=0; i<= NbParameters()-1;i++)
    this->RecupereValeur(i);

} // RecupereValeurs()


//---------------------------------------------------------------------
void ParamPanel::MAJ( )
//                                ---
{
  int i;
  for( i=0; i<= NbParameters()-1;i++)
    this->UpdateParameter(i);

} // MAJ()


//---------------------------------------------------------------------
void ParamPanel::AfficheDialogue()
//               ---------------
{
  //----- Mise a jour des valeurs dans les widgets ...
  if (this->IsShown())  this->MAJ();

  _main_sizer->Fit(this);
  this->Layout();
  this->Fit();
  this->Show();
  cout << boost::format("GetEffectiveMinSize() %d %d ") 
        % GetEffectiveMinSize().GetWidth()
        % GetEffectiveMinSize().GetHeight()
        << endl;

} // AfficheDialogue()


//---------------------------------------------------------------------
void ParamPanel::FermeDialogue( )
//                                -------------
{

  if (this->IsShown()) {
    this->Show(false);
//    *_etat_sortie = SORTIE_CANCEL;
  }
} // FermeDialogue()


/*
//---------------------------------------------------------------------
NoyauParametre* ParamPanel::RecupereParametre( int id)
//                                           -----------------
{

  if ((id < 0) || (id >= NbParameters() )) {
    printf("ParamPanel::RecupereParametre \t Erreur, identificateur incorrect \n");
    return( NULL);
  } // end if

//  return( _tab_param[id]);
  return NULL;
  
} // RecupereParametre()
*/

//---------------------------------------------------------------------
void ParamPanel::UpdateParameter( int id)
//                                -----------------
{
  macro_CheckParameterId(id, return)

  if ((_tab_param[id].GetWidget()!=NULL)&&
      (_tab_param[id].GetSizerItem()->IsShown())) 
    _tab_param[id].GetWidget()->Update();
  
} // RecupereParametre()


//---------------------------------------------------------------------
void ParamPanel::SetStackDirection( int id, int type_empilement)
//   -----------------
{
  macro_CheckParameterId(id, return)

} // SetStackDirection()


  
/*
//------------------------------------------------------------------------------
void  ParamPanel::Attache(int id, int id_h, int id_g, 
//                                 -------
                                  int id_b, int id_d)
{

  Widget wh,wg,wb,wd;

  wh=wg=wb=wd=NULL;


} // Attache()
*/

//---------------------------------------------------------------------
void ParamPanel::SetDragCallback( int id, bool dcb) {

  macro_CheckParameterId(id, return)
  
  if (_tab_param[id].GetType() == TYPE_PARAMETER_ENTIER) {
    if (_tab_param[id].GetWidget()!=NULL)
    ((wxNumericParameter<int>*) _tab_param[id].GetWidget())->SetDragCallback(dcb);
  } else
  if (_tab_param[id].GetType() == TYPE_PARAMETER_REEL) {
    if (_tab_param[id].GetWidget()!=NULL)
    ((wxNumericParameter<float>*) _tab_param[id].GetWidget())->SetDragCallback(dcb);
  } else
    cerr << __func__ << " only available for integers and floats." << endl;
}


//---------------------------------------------------------------------
void ParamPanel::Enable( int id, bool enable) {

  macro_CheckParameterId(id, return)
  
  if ((wxGenericWidget*) _tab_param[id].GetWidget() !=NULL) {
    wxGenericWidget* pwidget = (wxGenericWidget*) _tab_param[id].GetWidget();

    if (enable!=pwidget->IsEnabled())
      pwidget->EnableWidget(enable);
  }
}

//---------------------------------------------------------------------
void ParamPanel::EnableBox( int id, bool enable) {

  if (id<(int)_tab_boxes.size()) {
    wxStaticBox* box = _tab_boxes[id];
    if (enable!=box->IsEnabled())
      box->Enable(enable);
  } else {
    cerr  << __func__ << " " \
          << this->GetName().mb_str() << "\t" \
          <<  "Error \t wrong box id" \
          << id << " " << _tab_boxes.size() << "\n" \
          << endl; \
    return;
  }
}

//------------------------------------------------------------
void ParamPanel::EnablePanel( int id, bool enable) {

  if (id<(int)_tab_panels.size()) {
    wxWindow* panel = _tab_panels[id];
    if (enable!=panel->IsEnabled())
      panel->Enable(enable);
  } else {
    cerr  << __func__ << " " \
          << this->GetName().mb_str() << "\t" \
          <<  "Error \t wrong box id" \
          << id << " " << _tab_panels.size() << "\n" \
          << endl; \
    return;
  }
}

//------------------------------------------------------------
void ParamPanel::SelectPage( int book_id, int panel_nb)
{
  if (book_id<(int)_tab_books.size()) {
    NotebookClass* book = _tab_books[book_id];
    book->SetSelection(panel_nb);
  } else {
    cerr  << __func__ << " " \
          << this->GetName().mb_str() << "\t" \
          <<  "Error \t wrong book id" \
          << book_id << " " << _tab_books.size() << "\n" \
          << endl; \
    return;
  }
}

/*
//---------------------------------------------------------------------
Widget ParamPanel::GetWidget( int id)
//                                  ---------
{

  Widget widget=NULL;

  if ((id < 0) || (id >= NbParameters() )) {
    printf("ParamPanel::GetWidget \t Erreur, identificateur incorrect \n");
    return( NULL);
  } // end if

  if (widget == NULL) {
    printf("ParamPanel::GetWidget \t Erreur, widget non cr� ...  \n");
  } // end if

  return NULL;
  
} // GetWidget()
*/



//---------------------------------------------------------------------
int ParamPanel::BeginBox( const char* boxname)
{
  int BoxBorder=2;

  wxStaticBox* sb = new wxStaticBox(CurrentParent(),
                                    wxID_ANY,
                                    wxString::FromAscii(boxname));
  _tab_boxes.push_back(sb);

#if wxCHECK_VERSION(2,9,0)
  _panels.push( sb);
#endif

  wxStaticBoxSizer* sizer  = new wxStaticBoxSizer( sb, wxVERTICAL );
  _current_sizer.top()->Add(sizer, 0,wxEXPAND | wxALL, BoxBorder);
  _current_sizer.push(sizer);
  

  return (int)_tab_boxes.size()-1;
} // BeginBox


//-------------------------------------------------------
void ParamPanel::EndBox()
{
  _current_sizer.pop();
#if wxCHECK_VERSION(2,9,0)
  _panels.pop();
#endif
}
  
//-----------------------------------------------------------
void ParamPanel::BeginHorizontal( int border)
{
  wxBoxSizer* sizer  = new wxBoxSizer( wxHORIZONTAL );
  _current_sizer.top()->Add(
    sizer,
    0,
    wxEXPAND | wxALL,
    border);
  _current_sizer.push(sizer);
}


//--------------------------------------------------
void ParamPanel::EndHorizontal()
{
  _current_sizer.pop();
}

// Standard buttons
void ParamPanel::OnOK(wxCommandEvent& WXUNUSED(event))
{
  this->Show(false);
}

void ParamPanel::OnApply(wxCommandEvent& WXUNUSED(event))
{
//  ParamPanel* pd = this;

}

void ParamPanel::OnCancel(wxCommandEvent& WXUNUSED(event))
{
  this->Show(false);
//  *(this->_etat_sortie) = SORTIE_CANCEL;
}


void ParamPanel::OnClose(wxCloseEvent& event)
{
  this->Show(false);
}  

