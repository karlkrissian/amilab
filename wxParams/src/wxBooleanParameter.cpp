//
// C++ Implementation: wxBooleanParameter
//
// Description: 
//
//
// Author: Karl Krissian <>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//

#include "wxBooleanParameter.h"

//==============================================================================
//          wxBooleanParameter
//==============================================================================

   
BEGIN_EVENT_TABLE(wxBooleanParameter, wxCheckBox)
    EVT_CHECKBOX(  wxID_ANY, wxBooleanParameter::OnCheck)
END_EVENT_TABLE();


//------------------------------------------------------------------------------
//
wxBooleanParameter ::  wxBooleanParameter(  wxWindow* parent,
//                           ------------
        unsigned char* param, const char* libelle) : wxCheckBox( parent, wxID_ANY, wxString::FromAscii( libelle) )
{
  parametre  = param;
  val_defaut = false;
  _libelle = libelle;
  _type = CaractereToggle;

} //  wxBooleanParameter()


//------------------------------------------------------------------------------
wxBooleanParameter :: ~ wxBooleanParameter()
//                           -----------
{

} // ~ wxBooleanParameter()


//------------------------------------------------------------------------------
void wxBooleanParameter :: FixeDefaut( unsigned char defaut)
//                                 ----------
{
  val_defaut = defaut;
  *(parametre) = val_defaut;

  switch ( _type ) {
  case CaractereToggle:
    //printf("this->SetValue() \n");
    this->SetValue(defaut);
    break;
  case CaracterePixmap:
    break;
  default:
    break;
  } // end switch

  
} // wxBooleanParameter :: FixeDefaut()


//----------------------------------------------------------------------
///
void wxBooleanParameter ::  FixeAccelerateur( std::string accelerateur, 
                              std::string texte)
//
{

  /*
  */
} // FixeAccelerateur()


//----------------------------------------------------------------------
void wxBooleanParameter::UpdateValue()
{
  *this->parametre = (this->IsChecked());
}

//------------------------------------------------------------------------------
void wxBooleanParameter :: Update()
//                         ------
{
  this->SetValue(*this->parametre);
} // wxBooleanParameter :: Update()


//------------------------------------------------------------------------------
void wxBooleanParameter::OnCheck(wxCommandEvent& event)
{
  this->UpdateValue();
  this->Callback();
}


