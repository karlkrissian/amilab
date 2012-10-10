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

   
BEGIN_EVENT_TABLE_TEMPLATE1(wxBooleanParameter, wxCheckBox,T1)
  EVT_CHECKBOX(  wxID_ANY, wxBooleanParameter::OnCheck)
END_EVENT_TABLE()

//------------------------------------------------------------------------------
//
template <class T>
wxBooleanParameter<T>::wxBooleanParameter(  
                                          wxWindow* parent,
                                          T* param, 
                                          const char* libelle) : 
                      wxCheckBox( parent, 
                                  wxID_ANY, 
                                  wxString::FromAscii( libelle) )
{
  parametre  = param;
  val_defaut = false;
  _libelle = libelle;
  _type = CaractereToggle;

} //  wxBooleanParameter()


//------------------------------------------------------------------------------
template <class T>
wxBooleanParameter<T>::~wxBooleanParameter()
//                           -----------
{

} // ~ wxBooleanParameter()


//------------------------------------------------------------------------------
template <class T>
void wxBooleanParameter<T>::FixeDefaut( T defaut)
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
template <class T>
void wxBooleanParameter<T>::FixeAccelerateur(  std::string accelerateur, 
                                            std::string texte)
{
} // FixeAccelerateur()


//----------------------------------------------------------------------
template <class T>
void wxBooleanParameter<T>::UpdateValue()
{
  *this->parametre = (this->IsChecked());
}

//------------------------------------------------------------------------------
template <class T>
void wxBooleanParameter<T>:: Update()
//                         ------
{
  this->SetValue(*this->parametre);
} // wxBooleanParameter :: Update()


//------------------------------------------------------------------------------
template <class T>
void wxBooleanParameter<T>::OnCheck(wxCommandEvent& event)
{
  this->UpdateValue();
  this->Callback();
}

//------------------------------------------------------------------------------
template <class T>
void wxBooleanParameter<T>::EnableWidget(bool enable)
{
  if (enable!=_enabled) {
    this->Enable(enable);
    _enabled = enable;
  }
}

