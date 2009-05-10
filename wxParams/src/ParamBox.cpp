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
//  Fichier ParamBox.cpp
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
#include "ParamBox.hpp"
#include "wxParamTypes.hpp"
#include "wxColorParameter.h"

#include <iostream>
using namespace std;

#include "boost/format.hpp"


IMPLEMENT_CLASS(ParamBox, wxDialog)

BEGIN_EVENT_TABLE(ParamBox, wxDialog)
  EVT_BUTTON(wxID_OK, ParamBox::OnOK)
  EVT_BUTTON(wxID_APPLY, ParamBox::OnApply)
  EVT_BUTTON(wxID_CANCEL, ParamBox::OnCancel)
  EVT_CLOSE(ParamBox::OnClose)
END_EVENT_TABLE()

//==============================================================================
//      BOITE DE PARAMETRES
//==============================================================================


//------------------------------------------------------------------------------
ParamBox:: ParamBox( wxWindow* parent,
//                           ------------
                                const char* titre,
                                long style ):
      wxDialog( parent, 
                wxID_ANY,
                wxString::FromAscii(titre), 
                wxDefaultPosition,
                wxDefaultSize,
                wxDEFAULT_DIALOG_STYLE | wxFULL_REPAINT_ON_RESIZE)
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

} //  ParamBox()


//---------------------------------------------------------------
void ParamBox::BeginBook()
{
  wxNotebook* nb;

  nb = new wxNotebook(CurrentParent(), wxID_ANY,
                      wxDefaultPosition,
                      wxDefaultSize,
                      0);
  //  nb->SetFont(wxFont(12, wxDEFAULT, wxNORMAL, wxBOLD));

  //nb->SetOwnBackgroundColour(wxColour("#e1dfff"));
  _current_book.push(nb);
  _current_sizer.top()->Add(GetBookCtrl(), 1, wxEXPAND, 0);

} // ParamBox::BeginBook()

//---------------------------------------------------------------
void ParamBox::EndBook()
{
  // closes previous page if any
  if (GetBookCtrl()->GetPageCount())
    this->EndPanel();

  _current_book.pop();

} // ParamBox::EndBook()


//---------------------------------------------------------
// add a page to the book
// with a new panel
// if the book has another page, close it first
void ParamBox::AddPage(const std::string& panel_name)
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
                wxFULL_REPAINT_ON_RESIZE));

  GetBookCtrl()->AddPage( LastPanel(),
                          wxString::FromAscii(panel_name.c_str()));
  LastPanel()->SetToolTip(wxString::FromAscii(panel_name.c_str()));
  panelsizer   = new wxBoxSizer( wxVERTICAL );
  LastPanel()->SetSizer(panelsizer);
  _current_sizer.push(panelsizer);

} // AddPage()


//---------------------------------------------------------
void ParamBox::BeginPanel(const std::string& panel_name)
//             --------
{
  wxBoxSizer* panelsizer;

  _panels.push( new wxPanel(CurrentParent()));

  LastPanel()->SetToolTip(wxString::FromAscii(panel_name.c_str()));

  panelsizer   = new wxBoxSizer( wxVERTICAL );

  LastPanel()->SetSizer(panelsizer);

  // add new panel to the current sizer
  _current_sizer.top()->Add(LastPanel(), 0, wxEXPAND, 0);
  _current_sizer.push(panelsizer);

} // BeginPanel()


//-------------------------------------------------------
void ParamBox::EndPanel()
{
//  LastPanelSizer()->SetSizeHints(LastPanel());
  LastPanelSizer()->Fit(LastPanel());
  _current_sizer.pop();
  _panels.pop();

} // ParamBox::EndPanel()



//------------------------------------------------------------------------------
ParamBox::~ ParamBox()
//                           -----------
{
//  if (GB_debug)  
//      cerr << boost::format("~ParamBox(%s)")
//            %this->GetName().c_str() << endl;

} // ~ ParamBox()


//------------------------------------------------------------------------------
void ParamBox::RecupereDimensions( int* l, int* h)
//                ------------------
{
  wxSize s = this->GetSize();
  *l = s.GetWidth();
  *h = s.GetHeight();
} // RecupereDimensions( )


//-----------------------------------------------------------
template <class T>
wxSizerItem* ParamBox::AddParam( T* w)
{
  int proportional = 0;
  int border = 5;
  int flag =  wxEXPAND |wxALL;

  wxBoxSizer * s = _current_sizer.top();
  switch(s->GetOrientation()) {
    case wxHORIZONTAL: 
      proportional = 1;
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
wxSizerItem* ParamBox::AddWidget( wxWindow* w)
//
{
  return AddParam<wxWindow>(w);
} // AddWidget()


//--------------------------------------------------------------
wxSizerItem* ParamBox::AddWidget( wxSizer* w)
//
{
  return AddParam<wxSizer>(w);
} // AddWidget()


//--------------------------------------------------------------
unsigned char ParamBox::AddBoolean( int* id, unsigned char* param, 
//                   -------------
                const char* libelle, type_booleen type)
{
  wxBooleanParameter* wxbp = new wxBooleanParameter(
      CurrentParent(), param, libelle);

  ParamInfo pi(  TYPE_PARAMETRE_BOOLEEN,
                 wxbp,
                 AddWidget(wxbp));

  _tab_param.push_back(pi);
  *id = _tab_param.size()-1;

  return( true);
} // AddBoolean()


//------------------------------------------------------------------------------
void ParamBox::BooleanDefault( int id, unsigned char defaut)
//                -------------
{

  if ((id < 0) || (id >= NbParameters())) {
    printf("ParamBox::BooleanDefault \t Erreur, identificateur  inexistant\n");
    return;
  } // end if

  if (_tab_param[id].GetType() != TYPE_PARAMETRE_BOOLEEN) {
    printf("ParamBox::BooleanDefault \t Erreur, identificateur non valide\n");
    return;
  } // end if
  
  if (_tab_param[id].GetWidget()!=NULL) 
    ((wxBooleanParameter*) _tab_param[id].GetWidget())->FixeDefaut( defaut);

} // BooleanDefault()


//--------------------------------------------------------------
unsigned char ParamBox::AddInteger( int* id, int* param, 
//                      ------------
                const char* libelle)
{
  *id = AddInteger(param,libelle);
  return( true);
} // AddInteger()


//--------------------------------------------------------------
int ParamBox::AddInteger( int* param, 
//                   ------------
                const char* libelle)
{
  wxIntegerParameter* wxi = new wxIntegerParameter(
      CurrentParent(), param, libelle);

  ParamInfo pi( TYPE_PARAMETRE_ENTIER,
                wxi,
                AddWidget(wxi));
  _tab_param.push_back(pi);
  return _tab_param.size()-1;
} // AddInteger()


//------------------------------------------------------------------------------
void ParamBox::IntegerConstraints( int id, int min, int max, int defaut)
//                -----------------
{

  if ((id < 0) || (id >= NbParameters())) {
    printf("ParamBox::IntegerConstraints \t Erreur, identificateur  inexistant\n");
    return;
  } // end if

  if (_tab_param[id].GetType() != TYPE_PARAMETRE_ENTIER) {
    printf("ParamBox::IntegerConstraints \t Erreur, identificateur non valide\n");
    return;
  } // end if

  if (_tab_param[id].GetWidget()!=NULL)
    ((wxIntegerParameter*) _tab_param[id].GetWidget())->SetConstraints( min, max, defaut);

} // IntegerConstraints()


//------------------------------------------------------------------------------
void ParamBox::ParamIntGetLimits( int id, int& min, int& max)
{
  if ((id < 0) || (id >= NbParameters())) {
    printf("ParamBox::ParamIntGetLimits \t Erreur, identificateur  inexistant\n");
    return;
  } // end if

  if (_tab_param[id].GetType() != TYPE_PARAMETRE_ENTIER) {
    printf("ParamBox::ParamIntGetLimits \t Erreur, identificateur non valide\n");
    return;
  } // end if
  
  if (_tab_param[id].GetWidget()!=NULL)
    ((wxIntegerParameter*) _tab_param[id].GetWidget())->GetLimits( min, max);

} // ParamIntGetLimits()


//------------------------------------------------------------
unsigned char ParamBox::AddFloat( int* id, float* param,
//                      --------
                const char* libelle, int precision)
{
  *id = AddFloat(param,libelle,precision);
  return( true);
} // AddFloat()


//-----------------------------------------------------------
int  ParamBox::AddFloat(  float* param,
//             --------
                const char* libelle, int precision)
{
  wxFloatParameter* wxi = new wxFloatParameter(
      CurrentParent(), param, libelle);
  wxi->SetDecimate(precision);

  ParamInfo pi( TYPE_PARAMETRE_REEL,
                wxi,
                AddWidget(wxi));
  _tab_param.push_back(pi);
  return _tab_param.size()-1;
} // AddFloat()


//---------------------------------------------------------------
void ParamBox::FloatConstraints( 
//             ---------------
    int id,
    const float& min,
    const float& max,
    const float& defaut)
{

  if ((id < 0) || (id >= NbParameters())) {
    printf("ParamBox::FloatConstraints \t Erreur, identificateur  inexistant\n");
    return;
  } // end if

  if (_tab_param[id].GetType() != TYPE_PARAMETRE_REEL) {
    printf("ParamBox::FloatConstraints \t Erreur, identificateur non valide\n");
    return;
  } // end if

  if (_tab_param[id].GetWidget()!=NULL)
    ((wxFloatParameter*) _tab_param[id].GetWidget())->SetConstraints( min, max, defaut);

} // FloatConstraints()

//---------------------------------------------------------------
void ParamBox::ParamFloatGetLimits( int id, float& min, float& max)
{
  if ((id < 0) || (id >= NbParameters())) {
    printf("ParamBox::ParamFloatGetLimits \t Erreur, identificateur  inexistant\n");
    return;
  } // end if

  if (_tab_param[id].GetType() != TYPE_PARAMETRE_REEL) {
    printf("ParamBox::ParamFloatGetLimits \t Erreur, identificateur non valide\n");
    return;
  } // end if
  
  if (_tab_param[id].GetWidget()!=NULL)
      ((wxFloatParameter*) _tab_param[id].GetWidget())->GetLimits( min, max);

} // ParamIntGetLimits()

//-----------------------------------------------------------
void ParamBox::ParamShowSlider( int id, bool show)
{
  if ((id < 0) || (id >= NbParameters())) {
    printf("ParamBox::ParamFloatGetLimits \t Erreur, identificateur  inexistant\n");
    return;
  } // end if

  if (_tab_param[id].GetType() != TYPE_PARAMETRE_REEL) {
    printf("ParamBox::ParamFloatGetLimits \t Erreur, identificateur non valide\n");
    return;
  } // end if
  
    if (_tab_param[id].GetWidget()!=NULL)
      ((wxFloatParameter*) _tab_param[id].GetWidget())->ShowSlider( show);
} // ParamShowSlider()


//------------------------------------------------------------------------------
unsigned char ParamBox::AddEnumeration( int* id, int taille, 
//                      --------------
            int* param, const char* libelle,
                type_enum type) 
{
  wxEnumerationParameter* wxe = new wxEnumerationParameter(
      CurrentParent(), param, libelle);

  ParamInfo pi( TYPE_PARAMETRE_ENUMERATION,
                wxe,
                AddWidget(wxe));
  _tab_param.push_back(pi);

  *id = _tab_param.size()-1;
  return( true);
} // AddEnumeration()


//------------------------------------------------------------------------------
unsigned char ParamBox::AddEnumeration( int* id, 
//                      --------------
            int* param, const char* libelle,
                type_enum type) 
{
  wxEnumerationParameter* wxe = new wxEnumerationParameter(
      CurrentParent(), param, libelle);

  ParamInfo pi( TYPE_PARAMETRE_ENUMERATION,
                wxe,
                AddWidget(wxe));
  _tab_param.push_back(pi);

  *id = _tab_param.size()-1;
  return( true);
} // AddEnumeration()


//------------------------------------------------------------------------------
unsigned char ParamBox::AddEnumChoice( int id, 
//                   ---------------
            int* id_enum_choix, const char* libelle,
            const char* pixmap_name)
{

  if ((id < 0) || (id >= NbParameters())) {
    printf("ParamBox::AddEnumChoice \t Erreur, identificateur  inexistant\n");
    return false;
  } // end if

  if (_tab_param[id].GetType() != TYPE_PARAMETRE_ENUMERATION) {
    printf("ParamBox::AddEnumChoice \t Erreur, identificateur non valide\n");
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
unsigned char ParamBox::AddEnumChoice( int id, 
//                   ---------------
            int* id_enum_choix, const char* libelle,
            const char** pixmap_string)
{

  if ((id < 0) || (id >= NbParameters())) {
    printf("ParamBox::AddEnumChoice \t Erreur, identificateur  inexistant\n");
    return false;
  } // end if

  if (_tab_param[id].GetType() != TYPE_PARAMETRE_ENUMERATION) {
    printf("ParamBox::AddEnumChoice \t Erreur, identificateur non valide\n");
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
void ParamBox::EnumerationDefaut( int id, int id_defaut)
//                -----------------
{

  if ((id < 0) || (id >= NbParameters())) {
    printf("ParamBox::ContraintesEnumeration \t Erreur, identificateur  inexistant\n");
    return;
  } // end if

  if (_tab_param[id].GetType() != TYPE_PARAMETRE_ENUMERATION) {
    printf("ParamBox::ContraintesEnumeration \t Erreur, identificateur non valide\n");
    return;
  } // end if

  if (_tab_param[id].GetWidget()!=NULL) 
    ((wxEnumerationParameter*) _tab_param[id].GetWidget())->SetSelection( id_defaut ); 

} // EnumerationDefaut()



//--------------------------------------------------------------
unsigned char ParamBox::AddButton( int* id,  const char* libelle,
//                      ---------
        void* callback,
        void* data)
{
  // add a wxButton
  wxButtonParameter* wxbp = new wxButtonParameter(
      CurrentParent(), libelle, callback, data);

  ParamInfo pi( TYPE_PARAMETRE_BOUTTON,
                wxbp,
                AddWidget(wxbp));
  _tab_param.push_back(pi);
  *id = _tab_param.size()-1;
  return( true);
} // AddButton()


//-----------------------------------------------------------------
unsigned char ParamBox::AddPixmapButton( int* id,  const char* libelle,
//                      ---------------
                      void* callback,
                      void* data,
                      const char** pixmap_string)
{
  // add a wxButton 
  wxBitmap bm(pixmap_string);
  wxBitmapButtonParameter* wxbp = new wxBitmapButtonParameter(CurrentParent(), libelle, bm, callback, data);

  ParamInfo pi( TYPE_PARAMETRE_BOUTTON,
                wxbp,
                AddWidget(wxbp));
  _tab_param.push_back(pi);
  *id = _tab_param.size()-1;
  return( true);
} // AddPixmapButton()


//---------------------------------------------------------------
unsigned char ParamBox::AddColor( int* id,
//                      --------
                    const char* libelle,
                    ClasseCouleur*  couleur)
{
  wxColorParameter* wxcp = new wxColorParameter(CurrentParent(), libelle, couleur);

  ParamInfo pi( TYPE_PARAMETRE_COULEUR,
                wxcp,
                AddWidget(wxcp));
  _tab_param.push_back(pi);
  *id = _tab_param.size()-1;
  return( true);
} // AddColor()


//----------------------------------------------------------------
unsigned char ParamBox::AddLabel( int* id,  const char* libelle,
//                      --------
                          const char* contenu, type_label type)
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
void ParamBox::SetLabelValue( int id,  char* value)
//             -------------
{
   ((wxLabelParameter*) _tab_param[id].GetWidget())->SetValue( value);
} // SetLabelValue()

/*
//------------------------------------------------------------------------------
unsigned char ParamBox::AjouteWidget( int* id,  Widget widget)
//                   ------------
{
  return( true);
} // AjouteWidget()
*/


//------------------------------------------------------------------------------
void ParamBox::FixeVisible( int id, unsigned char visible)
//                -----------
{

  if ((id < 0) || (id >= NbParameters())) {
    printf("ParamBox::FixeVisible %s \t Erreur, identificateur  inexistant %d %d\n",
      (const char*)this->GetTitle().mb_str(wxConvUTF8),
      id,
      NbParameters());
    return;
  } // end if


  if ((wxGenericWidget*) _tab_param[id].GetWidget() !=NULL) {

    if (visible!=_tab_param[id].GetSizerItem()->IsShown())
    _tab_param[id].GetSizerItem()->Show(visible);

  }
  
} // FixeVisible()


//------------------------------------------------------------------------------
void ParamBox::ChangedValueCallback( int id, void* callback, void* calldata)
//                --------------------
{

  if ((id < 0) || (id >= NbParameters())) {
    printf("ParamBox::ChangedValueCallback \t Erreur, identificateur  inexistant\n");
    return;
  } // end if

  if ((wxGenericWidget*) _tab_param[id].GetWidget() !=NULL)
    ((wxGenericWidget*) _tab_param[id].GetWidget())->ChangedValueCallback( callback, calldata);

} // ChangedValueCallback()


//----------------------------------------------------------------
unsigned char ParamBox::AjouteChaine( int* id, std::string* param, 
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
void ParamBox::ContraintesChaine( int id, char* defaut)
//                -----------------
{

  if ((id < 0) || (id >= NbParameters())) {
    printf("ParamBox::ContraintesChaine \t Erreur, identificateur  inexistant\n");
    return;
  } // end if

  if (_tab_param[id].GetType() != TYPE_PARAMETRE_CHAINE) {
    printf("ParamBox::ContraintesChaine \t Erreur, identificateur non valide\n");
    return;
  } // end if

} // ContraintesChaine()


//------------------------------------------------------------------------------
unsigned char ParamBox::AjouteNomFichier( int* id, std::string* param, 
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
void ParamBox::ContraintesNomFichier( int id, const char* defaut,
//                ---------------------
                const char* , const char* mask)
{

  if ((id < 0) || (id >= NbParameters())) {
    printf("ParamBox::ContraintesNomFichier \t Erreur, identificateur  inexistant\n");
    return;
  } // end if

  if (_tab_param[id].GetType() != TYPE_PARAMETRE_NOM_FICHIER) {
    printf("ParamBox::ContraintesNomFichier \t Erreur, identificateur non valide\n");
    return;
  } // end if

  
  ((wxFilenameParameter*)_tab_param[id].GetWidget())->SetDefaultPath(defaut);
  ((wxFilenameParameter*)_tab_param[id].GetWidget())->SetWildcard(mask);
  

} // ContraintesNomFichier()


//---------------------------------------------------------------------
void ParamBox::EnleveBouttons( )
//                                --------------
{
  _inclu_bouttons = false;
} // CreeDialogue()


//---------------------------------------------------------------------
void ParamBox::CreeDialogue( )
//                                ------------
{

//  if (_inclu_bouttons)   CreateButtons(wxOK|wxCANCEL|wxHELP);

//  LastPanelSizer()->Fit(LastPanel());
  this->Layout();

} // CreeDialogue()


//---------------------------------------------------------------------
void ParamBox::ReAfficheParametres( )
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
void ParamBox::RecupereValeur( int id )
//                                ---------------
{

  if ((id < 0) || (id >= NbParameters())) {
    printf("ParamBox:: \t Erreur, identificateur  inexistant\n");
    return;
  } // end if

  _tab_param[id].GetWidget()->UpdateValue();

} // RecupereValeurs()


//---------------------------------------------------------------------
void ParamBox::RecupereValeurs( )
//                                ---------------
{
    int i;

  for( i=0; i<=NbParameters()-1; i++)
    this->RecupereValeur(i);

} // RecupereValeurs()


//---------------------------------------------------------------------
void ParamBox::MAJ( )
//                                ---
{
  int i;
  for( i= 0; i<=NbParameters()-1; i++)
    this->UpdateParameter(i);

} // MAJ()


//---------------------------------------------------------------------
void ParamBox::AfficheDialogue()
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
void ParamBox::FermeDialogue( )
//                                -------------
{

  if (this->IsShown()) {
    this->Show(false);
//    *_etat_sortie = SORTIE_CANCEL;
  }
} // FermeDialogue()


/*
//---------------------------------------------------------------------
NoyauParametre* ParamBox::RecupereParametre( int id)
//                                           -----------------
{

  if ((id < 0) || (id >= NbParameters() )) {
    printf("ParamBox::RecupereParametre \t Erreur, identificateur incorrect \n");
    return( NULL);
  } // end if

//  return( _tab_param[id]);
  return NULL;
  
} // RecupereParametre()
*/

//---------------------------------------------------------------------
void ParamBox::UpdateParameter( int id)
//                                -----------------
{

  if ((id < 0) || (id >= NbParameters() )) {
    printf("ParamBox::RecupereParametre \t Erreur, identificateur incorrect \n");
    return;
  } // end if

  if ((_tab_param[id].GetWidget()!=NULL)&&
      (_tab_param[id].GetSizerItem()->IsShown())) 
    _tab_param[id].GetWidget()->Update();
  
} // RecupereParametre()


//---------------------------------------------------------------------
void ParamBox::SetStackDirection( int id, int type_empilement)
//   -----------------
{
  if ((id < 0) || (id >= NbParameters() )) {
    printf("ParamBox::RecupereParametre \t Erreur, identificateur incorrect \n");
    return;
  } // end if

} // SetStackDirection()


  
/*
//------------------------------------------------------------------------------
void  ParamBox::Attache(int id, int id_h, int id_g, 
//                                 -------
                                  int id_b, int id_d)
{

  Widget wh,wg,wb,wd;

  wh=wg=wb=wd=NULL;


} // Attache()
*/

//---------------------------------------------------------------------
void ParamBox::SetDragCallback( int id) {

  if ((id < 0) || (id >= NbParameters() )) {
    printf("ParamBox::SetDragCallback \t Erreur, identificateur incorrect \n");
    return;
  } // end if
  
//  (*this)[id]->SetDragCallback();
    
}


/*
//---------------------------------------------------------------------
Widget ParamBox::GetWidget( int id)
//                                  ---------
{

  Widget widget=NULL;

  if ((id < 0) || (id >= NbParameters() )) {
    printf("ParamBox::GetWidget \t Erreur, identificateur incorrect \n");
    return( NULL);
  } // end if

  if (widget == NULL) {
    printf("ParamBox::GetWidget \t Erreur, widget non cr� ...  \n");
  } // end if

  return NULL;
  
} // GetWidget()
*/



//---------------------------------------------------------------------
void ParamBox::BeginBox( const char* boxname)
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
void ParamBox::EndBox()
{
  _current_sizer.pop();
}
  
//-----------------------------------------------------------
void ParamBox::BeginHorizontal()
{
  wxBoxSizer* sizer  = new wxBoxSizer( wxHORIZONTAL );
  _current_sizer.top()->Add(sizer, 0,wxEXPAND | wxALL, 5);
  _current_sizer.push(sizer);
}


//--------------------------------------------------
void ParamBox::EndHorizontal()
{
  _current_sizer.pop();
}

// Standard buttons
void ParamBox::OnOK(wxCommandEvent& WXUNUSED(event))
{
  this->Show(false);
}

void ParamBox::OnApply(wxCommandEvent& WXUNUSED(event))
{
//  ParamBox* pd = this;

}

void ParamBox::OnCancel(wxCommandEvent& WXUNUSED(event))
{
  this->Show(false);
//  *(this->_etat_sortie) = SORTIE_CANCEL;
}


void ParamBox::OnClose(wxCloseEvent& event)
{
  this->Show(false);
}  

