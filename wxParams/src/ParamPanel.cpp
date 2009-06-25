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

#include <iostream>
using namespace std;

#include "boost/format.hpp"

#if defined(_MSC_VER) || defined(__MINGW32__)
inline double round( double d )
{
return floor( d + 0.5 );
}
#endif

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
      wxPanel( parent, 
                wxID_ANY,
                wxDefaultPosition,
                wxDefaultSize,
                wxTAB_TRAVERSAL //| wxVSCROLL
                ,
                wxString::FromAscii(titre)
                ) 
// the dialog needs to have a NULL parent
// or it crashes when closing the window
// wxPropertySheetDialog(w, wxID_ANY,
// wxString(_T(titre)))
{

  this->SetSizeHints(200,150,700,800);

  //SetSheetStyle(wxPROPSHEET_TREEBOOK);
  //SetSheetStyle(style);

  // Add page
  _main_sizer = new wxBoxSizer( wxVERTICAL);
  SetSizer(_main_sizer);
  _current_sizer.push(_main_sizer);

  _inclu_bouttons = false;

} //  ParamPanel()


//---------------------------------------------------------------
void ParamPanel::BeginBook()
{
  wxNotebook* nb;

  nb = new wxNotebook(CurrentParent(), wxID_ANY,
                      wxDefaultPosition,
                      wxDefaultSize//,
                      //wxVSCROLL
                      );
  //  nb->SetFont(wxFont(12, wxDEFAULT, wxNORMAL, wxBOLD));

  //nb->SetOwnBackgroundColour(wxColour("#e1dfff"));
  _current_book.push(nb);
  _current_sizer.top()->Add(GetBookCtrl(), 1, wxEXPAND, 0);

} // ParamPanel::BeginBook()

//---------------------------------------------------------------
void ParamPanel::EndBook()
{
  // closes previous page if any
  if (GetBookCtrl()->GetPageCount())
    this->EndPanel();

  _current_book.pop();

} // ParamPanel::EndBook()


//---------------------------------------------------------
// add a page to the book
// with a new panel
// if the book has another page, close it first
void ParamPanel::AddPage(const std::string& panel_name)
//             -------
{
  wxBoxSizer* panelsizer;

  if (!GetBookCtrl()) {
    cerr << "AddPage without any Book ! " << endl;
    return;
  }

  // closes previous page if any
  if (GetBookCtrl()->GetPageCount())
    this->EndPanel();

  _panels.push( 
    new wxPanel(GetBookCtrl(),
                wxID_ANY,
                wxDefaultPosition,
                wxDefaultSize,
                wxTAB_TRAVERSAL|
                wxFULL_REPAINT_ON_RESIZE 
                //|
                //wxVSCROLL
                ));

  GetBookCtrl()->AddPage( LastPanel(),
                          wxString::FromAscii(panel_name.c_str()));
  LastPanel()->SetToolTip(wxString::FromAscii(panel_name.c_str()));
  panelsizer   = new wxBoxSizer( wxVERTICAL );
  LastPanel()->SetSizer(panelsizer);
  _current_sizer.push(panelsizer);

} // AddPage()


//---------------------------------------------------------
void ParamPanel::BeginPanel(const std::string& panel_name)
//             --------
{
  wxBoxSizer* panelsizer;

  _panels.push( new wxPanel(CurrentParent(),
                            wxID_ANY, 
                            wxDefaultPosition, 
                            wxDefaultSize, 
                            wxTAB_TRAVERSAL // | wxVSCROLL
                          ));

  LastPanel()->SetToolTip(wxString::FromAscii(panel_name.c_str()));

  panelsizer   = new wxBoxSizer( wxVERTICAL );

  LastPanel()->SetSizer(panelsizer);

  // add new panel to the current sizer
  _current_sizer.top()->Add(LastPanel(), 1, wxEXPAND, 0);
  _current_sizer.push(panelsizer);

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
        int proportional,
        int border,
        int flag)
{

  wxBoxSizer * s = _current_sizer.top();
  switch(s->GetOrientation()) {
    case wxHORIZONTAL: 
      proportional = 0;
      border = 5;
      flag = wxEXPAND | wxALL; //| wxHORIZONTAL;
    break;
    case wxVERTICAL: 
      proportional = 0;
      border = 5;
      flag = wxEXPAND | wxALL; //| wxVERTICAL;
    break;
    default: break;
  }

  return 
      s->Add( w, proportional, flag,  border);
}


//----------------------------------------------------------
wxSizerItem* ParamPanel::AddWidget( wxWindow* w)
//
{
  return AddParam<wxWindow>(w);
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

  ParamInfo pi(  TYPE_PARAMETRE_BOOLEEN,
                 wxbp,
                 AddWidget(wxbp));

  _tab_param.push_back(pi);
  *id = _tab_param.size()-1;

  return( true);
} // AddBoolean()


//------------------------------------------------------------------------------
void ParamPanel::BooleanDefault( int id, unsigned char defaut)
//                -------------
{
  macro_CheckParameterId(id,return)

  if (_tab_param[id].GetType() != TYPE_PARAMETRE_BOOLEEN) {
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

  ParamInfo pi( TYPE_PARAMETRE_ENTIER,
                wxi,
                AddWidget(wxi));
  _tab_param.push_back(pi);
  return _tab_param.size()-1;
} // AddInteger()


//------------------------------------------------------------------------------
void ParamPanel::IntegerConstraints( int id, int min, int max, int defaut)
//                -----------------
{
  macro_CheckParameterId(id, return)

  if (_tab_param[id].GetType() != TYPE_PARAMETRE_ENTIER) {
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

  if (_tab_param[id].GetType() != TYPE_PARAMETRE_ENTIER) {
    printf("ParamPanel::ParamIntGetLimits \t Erreur, identificateur non valide\n");
    return;
  } // end if
  
  if (_tab_param[id].GetWidget()!=NULL)
    ((wxNumericParameter<int>*) _tab_param[id].GetWidget())->GetLimits( min, max);

} // ParamIntGetLimits()


//------------------------------------------------------------
unsigned char ParamPanel::AddFloat( int* id, float* param,
//                      --------
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

  ParamInfo pi( TYPE_PARAMETRE_REEL,
                wxi,
                AddWidget(wxi));
  _tab_param.push_back(pi);
  return _tab_param.size()-1;
} // AddFloat()


//---------------------------------------------------------------
void ParamPanel::FloatConstraints( int id, const float& min, const float& max, const float& defaut)
//                ---------------
{
  macro_CheckParameterId(id, return)

  if (_tab_param[id].GetType() != TYPE_PARAMETRE_REEL) {
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

  if (_tab_param[id].GetType() != TYPE_PARAMETRE_REEL) {
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

  if (_tab_param[id].GetType() == TYPE_PARAMETRE_REEL) {
    if (_tab_param[id].GetWidget()!=NULL)
      ((wxNumericParameter<float>*) _tab_param[id].GetWidget())->ShowSlider( show);
  } else 
  if (_tab_param[id].GetType() == TYPE_PARAMETRE_ENTIER) {
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

  ParamInfo pi( TYPE_PARAMETRE_ENUMERATION,
                wxe,
                AddWidget(wxe));
  _tab_param.push_back(pi);

  *id = _tab_param.size()-1;
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

  ParamInfo pi( TYPE_PARAMETRE_ENUMERATION,
                wxe,
                AddWidget(wxe));
  _tab_param.push_back(pi);

  *id = _tab_param.size()-1;
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

  if (_tab_param[id].GetType() != TYPE_PARAMETRE_ENUMERATION) {
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

  if (_tab_param[id].GetType() != TYPE_PARAMETRE_ENUMERATION) {
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

  if (_tab_param[id].GetType() != TYPE_PARAMETRE_ENUMERATION) {
    printf("ParamPanel::ContraintesEnumeration \t Erreur, identificateur non valide\n");
    return;
  } // end if

  if (_tab_param[id].GetWidget()!=NULL) 
    ((wxEnumerationParameter*) _tab_param[id].GetWidget())->SetSelection( id_defaut ); 

} // EnumerationDefaut()


//--------------------------------------------------------------
bool ParamPanel::AddListChoice( int* id,  
//               -------------
          std::string* selection_param,
          const char* libelle, 
          const boost::shared_ptr<wxArrayString>& choicelist,
          void* update_cb,
          type_enum type,
          const std::string& tooltip
          )
{
  wxEnumerationParameter* wxe = new wxEnumerationParameter(
      CurrentParent(), selection_param, libelle, tooltip);
  wxe->AddUpdateButton(update_cb);
  wxe->SetChoices(choicelist);

  ParamInfo pi( TYPE_PARAMETRE_ENUMERATION,
                wxe,
                AddWidget(wxe));
  _tab_param.push_back(pi);

  *id = _tab_param.size()-1;
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

  ParamInfo pi( TYPE_PARAMETRE_BOUTTON,
                wxbp,
                AddWidget(wxbp));
  _tab_param.push_back(pi);
  *id = _tab_param.size()-1;
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

  ParamInfo pi( TYPE_PARAMETRE_BOUTTON,
                wxbp,
                AddWidget(wxbp));
  _tab_param.push_back(pi);
  *id = _tab_param.size()-1;
  return( true);
} // AddPixmapButton()


//---------------------------------------------------------------
unsigned char ParamPanel::AddColor( int* id,
//                      --------
                    const char* libelle,
                    ClasseCouleur*  couleur,
                    const std::string& tt
                    )
{
  wxColorParameter* wxcp = new wxColorParameter(CurrentParent(), libelle, couleur);
  if (tt!="") wxcp->SetToolTip(GetwxStr(tt.c_str()));

  ParamInfo pi( TYPE_PARAMETRE_COULEUR,
                wxcp,
                AddWidget(wxcp));
  _tab_param.push_back(pi);
  *id = _tab_param.size()-1;
  return( true);
} // AddColor()


//----------------------------------------------------------------
unsigned char ParamPanel::AddLabel( int* id, const char* libelle,
//                      --------
                          char* contenu, type_label type)
{
  wxLabelParameter* wxl = new wxLabelParameter(CurrentParent(), libelle, contenu, type);

  ParamInfo pi( TYPE_PARAMETRE_LABEL,
                wxl,
                AddWidget(wxl));
  _tab_param.push_back(pi);
  *id = _tab_param.size()-1;
  return( true);
} // AddLabel()


///--------------------------------------------------------------
void ParamPanel::SetLabelValue( int id,  char* value)
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

    if (visible!=_tab_param[id].GetSizerItem()->IsShown())
    _tab_param[id].GetSizerItem()->Show(visible);
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
    NbParameters()-1, proportion,border,flags);
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
unsigned char ParamPanel::AjouteChaine( int* id, std::string* param, 
//                      ------------
                const char* libelle)
{
  wxStringParameter* wsp;
  wsp= new wxStringParameter(CurrentParent(),param,libelle);

  ParamInfo pi( TYPE_PARAMETRE_CHAINE,
                wsp,
                AddWidget(wsp));
  _tab_param.push_back(pi);
  *id = _tab_param.size()-1;
  return( true);
} // AjouteChaine()


//----------------------------------------------------------------
void ParamPanel::ContraintesChaine( int id, char* defaut)
//                -----------------
{
  macro_CheckParameterId(id, return)

  if (_tab_param[id].GetType() != TYPE_PARAMETRE_CHAINE) {
    printf("ParamPanel::ContraintesChaine \t Erreur, identificateur non valide\n");
    return;
  } // end if

} // ContraintesChaine()


//------------------------------------------------------------------------------
unsigned char ParamPanel::AjouteNomFichier( int* id, std::string* param, 
//                   ----------------
                const char* libelle)
{

  wxFilenameParameter* wxi = new wxFilenameParameter(CurrentParent(), param, libelle);

  ParamInfo pi( TYPE_PARAMETRE_NOM_FICHIER,
                wxi,
                AddWidget(wxi));
  _tab_param.push_back(pi);
  *id = _tab_param.size()-1;
  return( true);
} // AjouteNomFichier()


//------------------------------------------------------------------------------
// le troisieme parametre est le repertoire par defaut : non utilise
// le dernier parametre est le masque : non utilise
//
void ParamPanel::ContraintesNomFichier( int id, const char* defaut,
//                ---------------------
                const char* , const char* mask)
{
  macro_CheckParameterId(id, return)

  if (_tab_param[id].GetType() != TYPE_PARAMETRE_NOM_FICHIER) {
    printf("ParamPanel::ContraintesNomFichier \t Erreur, identificateur non valide\n");
    return;
  } // end if

  
  ((wxFilenameParameter*)_tab_param[id].GetWidget())->SetDefaultPath(defaut);
  ((wxFilenameParameter*)_tab_param[id].GetWidget())->SetWildcard(mask);
  

} // ContraintesNomFichier()


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
void ParamPanel::SetDragCallback( int id) {

  macro_CheckParameterId(id, return)
  
//  (*this)[id]->SetDragCallback();
    
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
void ParamPanel::BeginBox( const char* boxname)
{
  int BoxBorder=2;

  wxStaticBox* sb = new wxStaticBox(CurrentParent(),
                                    wxID_ANY,
                                    wxString::FromAscii(boxname));
  wxStaticBoxSizer* sizer  = new wxStaticBoxSizer( sb, wxVERTICAL );
  _current_sizer.top()->Add(sizer, 0,wxEXPAND | wxALL, BoxBorder);
  _current_sizer.push(sizer);

} // BeginBox


//-------------------------------------------------------
void ParamPanel::EndBox()
{
  _current_sizer.pop();
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

