//
// C++ Implementation: wxParamTypes
//
// Description: 
//
//
// Author: karl krissian <krissian@dis.ulpgc.es>, (C) 2007
//
// Copyright: See COPYING file that comes with this distribution
//
//


#include "wxParamTypes.hpp"
#include "boost/format.hpp"

using namespace std;
using namespace boost;

#if defined(_MSC_VER) || defined(__MINGW32__)
inline double round( double d )
{
return floor( d + 0.5 );
}
#endif


wxString GetwxStr(const char* str) {
  return wxString::FromAscii(str);
}

wxString GetwxStr(const string& str) {
  return wxString::FromAscii(str.c_str());
}

//==============================================================================
//          wxBooleanParameter
//==============================================================================

   
BEGIN_EVENT_TABLE(wxBooleanParameter, wxCheckBox)
    EVT_CHECKBOX(  wxID_ANY, wxBooleanParameter::OnCheck)
END_EVENT_TABLE()


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

  
    //    int i;

     // printf("wxBooleanParameter :: FixeDefaut( %d) \n",defaut);
      
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
  //printf("wxBooleanParameter::OnCheck()\n");
  this->Callback();
}



//==============================================================================
// wxMenuEnum enumeration for Menus with wxWidgets
//==============================================================================
  
/*
BEGIN_EVENT_TABLE(wxMenuEnum, wxMenu)
  EVT_MENU(wxID_MenuItem,  wxMenuEnum::OnEnumUpdate)
END_EVENT_TABLE()
*/

wxMenuEnum::wxMenuEnum( wxMenu* parent, int* param, const char* label)
{
  this->_parameter = param;
  parent->Append( wxID_ANY, wxString::FromAscii(label), this );
  this->_array_size=0;
 
}
  
wxMenuEnum::~wxMenuEnum()
{
}
  
void wxMenuEnum::AddChoice( int id, const wxString&  item, const wxString& helpString )
{
  myMenuItem* mitem = new myMenuItem(this,id,item, helpString);
  this->Append( mitem);
  mitem->Check(_array_size==*_parameter);
  _id_array[_array_size] = id;
  _array_size++;
}
  
void wxMenuEnum::SetSelection(int id)
{
  int i;
  for(i=0;i<_array_size;i++) {
    wxMenuItem* wxmi = FindItem(_id_array[i]);
    wxmi->Check(_id_array[i]==id);
    if (_id_array[i]==id) {
      if (*_parameter!=i)  {
        *_parameter=i;
      }
    }
  }
}

void wxMenuEnum::SetSelectionParameter()
{
  int i;
  for(i=0;i<_array_size;i++) {
    wxMenuItem* wxmi = FindItem(_id_array[i]);
    wxmi->Check(i==*_parameter);
  }
}
  
void wxMenuEnum::Update()
{
  this->SetSelectionParameter();
}
  
unsigned char wxMenuEnum::ValueChanged(wxCommandEvent& event)
{
  int i,id;
  id = event.GetId();
//  printf("event.GetId       = %d \n",event.GetId()      );
  for(i=0;i<_array_size;i++) {
    wxMenuItem* wxmi = FindItem(_id_array[i]);
    wxmi->Check(_id_array[i]==id);
    if (_id_array[i]==id) {
      if (*_parameter!=i)  {
//        printf("value changed \n");
        *_parameter=i;
      }
    }
  }
  return 1;
}

void wxMenuEnum::OnEnumUpdate(wxCommandEvent&)
{
  printf("update \n");
}




//==============================================================================
//          Filename Parameter
//==============================================================================

wxStringParameter::wxStringParameter( wxWindow* parent, string_ptr* param,
                                      const char* label): wxBoxSizer(wxHORIZONTAL)
{
  this->_parameter = param;
  // allocate a new string if needed
  if (!(*_parameter).get()) 
    (*_parameter) = string_ptr(new std::string(""));

  this->_parent    = parent;
  this->_label     = new wxStaticText(this->_parent, wxID_ANY, wxString::FromAscii(label));

  this->_text = new MyTextCtrl( this->_parent, wxID_ANY,
                              wxString::FromAscii((*param)->c_str()),
                              wxDefaultPosition, 
                              //wxSize(40, wxDefaultCoord),
                              wxDefaultSize,
                               wxTE_PROCESS_ENTER);
  //this->_text->SetSize(wxSIZE_AUTO_HEIGHT,10);
  this->_text->SetCallback((void*)wxStringParameter::OnStringUpdate,(void*) this);
  //this->_text->SetMinSize(wxSize(80,25));
  //this->_text->SetMinClientSize(wxSize(80,25));
  this->Add(this->_label, 0, wxLEFT | wxALIGN_CENTRE_VERTICAL, 2);
  this->Add(this->_text,  1, wxALL | wxEXPAND,5 );
//wxALL, 5);
//wxLEFT | wxALIGN_CENTRE_VERTICAL, 5);
}


void wxStringParameter::OnStringUpdate( void* data) 
{
  wxStringParameter* _this=(wxStringParameter*)data;
  _this->SetValue((const char*) (_this->_text->GetValue()).mb_str(wxConvUTF8));
  
}

// updating displayed value
void wxStringParameter::Update()
//   ------
{
  this->_text->SetValue(wxString::FromAscii((*this->_parameter)->c_str()));
} // Update()


//==============================================================================
//          Filename Parameter
//==============================================================================

BEGIN_EVENT_TABLE(myButton, wxButton)
    EVT_BUTTON(  wxID_ANY,myButton::OnButton)
END_EVENT_TABLE()

wxFilenameParameter::wxFilenameParameter( wxWindow* parent,
                                          string_ptr* param,
                                          const char* label,
                                          type_label type): wxBoxSizer(wxHORIZONTAL)
{
  this->_parameter = param;
  // allocate a new string if needed
  if (!(*_parameter).get()) 
    (*_parameter) = string_ptr(new std::string(""));

  this->_default_path      = wxString::FromAscii("");
  this->_default_filename  = wxString::FromAscii("");
  this->_default_extension = wxString::FromAscii("");
  this->_wildcard          = wxString::FromAscii("*.*");
  
  this->_parent    = parent;
  this->_label     = new wxStaticText(this->_parent,
                                      wxID_ANY,
                                      wxString::FromAscii(label));

  this->_text = new MyTextCtrl( this->_parent,
                                wxID_ANY,
                                wxString::FromAscii((*param)->c_str()),
                                wxDefaultPosition, 
                                wxSize(40, wxDefaultCoord),
                                wxTE_PROCESS_ENTER);
  this->_text->SetCallback((void*)wxFilenameParameter::OnStringUpdate,(void*) this);
 //   this->_text->SetCallback((void*)wxFloatParameter::OnTextUpdate,(void*) this);
  this->_button = new myButton( this->_parent,
                                wxID_ANY,
                                wxString::FromAscii("Browse"));
  this->_button->SetCallback((void*)wxFilenameParameter::BrowseFile, (void*) this);

  this->Add(this->_label, 0, wxLEFT | wxALIGN_CENTRE_VERTICAL, 2);
  this->Add(this->_text,  1, 0,5);
//wxLEFT | wxALIGN_CENTRE_VERTICAL, 5);
  this->Add(this->_button,0, wxLEFT | wxALIGN_CENTRE_VERTICAL, 5);
}

void wxFilenameParameter::BrowseFile(void* data)
{
  wxFilenameParameter* _this = (wxFilenameParameter*) data;
  wxString filename = wxFileSelector(
    wxString::FromAscii("Choose a file to open"),
    _this->_default_path,
    _this->_default_filename,
    _this->_default_extension,
    _this->_wildcard);
    
  if ( !filename.empty() )
  {
     _this->_text->SetValue(filename);
     _this->SetValue((const char*)filename.mb_str(wxConvUTF8));
  }
}
 

void wxFilenameParameter::OnStringUpdate( void* data) 
{
  wxFilenameParameter* _this=(wxFilenameParameter*)data;
  _this->SetValue((const char*)_this->_text->GetValue().mb_str(wxConvUTF8));
  
}

//==============================================================================
//          PARAMETRE  wxButtonParameter
//==============================================================================

BEGIN_EVENT_TABLE(wxButtonParameter, wxButton)
    EVT_BUTTON( wxID_ANY, wxButtonParameter::OnButton)
    EVT_RIGHT_DOWN( wxButtonParameter::OnRightDown) 
END_EVENT_TABLE()

//------------------------------------------------------------------------------
/*
//
wxButtonParameter ::  wxButtonParameter( wxWindow* parent,
//                            ------------
                             char* libelle,  XtCallbackProc callback,
                             void* data,
                             button_type type) : wxButton(parent, wxID_ANY, _T( libelle))
{

  _libelle  = libelle;
//  printf("button %s constructor\n",(char*)libelle);
  _btn3callback = NULL;
  _btn3data     = NULL;
  ChangedValueCallback( callback, data);
  _type         = type;

}
//  wxButtonParameter()
*/

//------------------------------------------------------------------------------
//
wxButtonParameter ::  wxButtonParameter( wxWindow* parent,
//                            ------------
                             const char* libelle,
                             void* callback,
                             void* data,
                             button_type type) : 
                  wxButton( parent, wxID_ANY, 
                            wxString::FromAscii( libelle),
                            wxDefaultPosition,
                            wxDefaultSize,
                            wxBU_EXACTFIT)
{
  _libelle  = libelle;
  _btn3callback = NULL;
  _btn3data     = NULL;
  ChangedValueCallback( callback, data);
  _type         = type;

}
//  wxButtonParameter()

//------------------------------------------------------------------------------
wxButtonParameter :: ~ wxButtonParameter()
//                           -----------
{

} // ~ wxButtonParameter()

//------------------------------------------------------------------------------
void wxButtonParameter::OnButton(wxCommandEvent& event)
{
  this->Callback();
  event.Skip();
}

//------------------------------------------------------------------------------
void wxButtonParameter::OnRightDown(wxMouseEvent& event)
{
  printf("wxButtonParameter::OnRightButton() no specific right button for the moment\n");
  this->Callback();
  event.Skip();
}

//------------------------------------------------------------------------------
void wxButtonParameter :: ChangeLibelle( const char* libelle)
//                                 -------------
{

} // wxButtonParameter :: ChangeLibelle()


/*
//------------------------------------------------------------------------------
void wxButtonParameter :: FixeCouleurFond( Pixel couleur)
//                                 -------------
{
   this->SetBackgroundColour( (wxColour)couleur);
}
 // FixeCouleurFond()
*/

/*
//------------------------------------------------------------------------------
void wxButtonParameter :: FixeCouleurCaracteres( Pixel couleur)
//                                 ---------------------
{
  this->SetForegroundColour( (wxColour)couleur);
}
 // FixeCouleurCaracteres()
*/


//==============================================================================
//          PARAMETRE  wxBitmapButtonParameter
//==============================================================================

   
BEGIN_EVENT_TABLE(wxBitmapButtonParameter, wxBitmapButton)
    EVT_BUTTON( wxID_ANY, wxBitmapButtonParameter::OnButton)
    EVT_RIGHT_DOWN( wxBitmapButtonParameter::OnRightDown)
END_EVENT_TABLE()
   

//------------------------------------------------------------------
/*
wxBitmapButtonParameter ::  wxBitmapButtonParameter( wxWindow* parent,
//                            ------------
                         char* libelle, 
                         const wxBitmap& bm, XtCallbackProc callback,
                         void* data,
                         button_type type) : wxBitmapButton(parent, wxID_ANY, bm)
{

  _libelle  = libelle;
//  printf("button %s constructor\n",(char*)libelle);
  _btn3callback = NULL;
  _btn3data     = NULL;
  ChangedValueCallback( callback, data);
  _type         = type;

}
//  wxBitmapButtonParameter()
*/

//------------------------------------------------------------------
wxBitmapButtonParameter ::  wxBitmapButtonParameter( wxWindow* parent,
//                            ------------
                         const char* libelle, 
                         const wxBitmap& bm, void* callback,
                         void* data,
                         button_type type) : wxBitmapButton(parent, wxID_ANY, bm)
{

  _libelle  = libelle;
  _btn3callback = NULL;
  _btn3data     = NULL;
  ChangedValueCallback( callback, data);
  _type         = type;

}
//  wxBitmapButtonParameter()

//------------------------------------------------------------------------------
wxBitmapButtonParameter :: ~ wxBitmapButtonParameter()
//                           -----------
{

} // ~ wxBitmapButtonParameter()

//------------------------------------------------------------------------------
void wxBitmapButtonParameter::OnButton(wxCommandEvent& event)
{

//  printf("wxBitmapButtonParameter::OnLeftButton()\n");

  this->Callback();
  event.Skip();
}

//------------------------------------------------------------------------------
void wxBitmapButtonParameter::OnRightDown(wxMouseEvent& event)
{

  printf("wxBitmapButtonParameter::OnRightButton() no specific right button for the moment\n");
  this->Callback();
  event.Skip();
}

//------------------------------------------------------------------------------
void wxBitmapButtonParameter :: ChangeLibelle( const char* libelle)
//                                 -------------
{

} // wxBitmapButtonParameter :: ChangeLibelle()


/*
//------------------------------------------------------------------------------
void wxBitmapButtonParameter :: FixeCouleurFond( Pixel couleur)
//                                 -------------
{
   this->SetBackgroundColour( (wxColour)couleur);
}
 // FixeCouleurFond()
*/

/*
//------------------------------------------------------------------------------
void wxBitmapButtonParameter :: FixeCouleurCaracteres( Pixel couleur)
//                                 ---------------------
{
  this->SetForegroundColour( (wxColour)couleur);
}
 // FixeCouleurCaracteres()
*/


//==============================================================================
//          wxLabelParameter
//==============================================================================

wxLabelParameter::wxLabelParameter( wxWindow* parent,
                                    const char* label,
                                    const char* value,
                                    type_label type): wxBoxSizer(wxHORIZONTAL)
{
  
  this->_parent    = parent;
  
  this->_label_name  = label;
  this->_label_value = value;
  this->_type        = type;

  this->_wxlabel = NULL;
  this->_wxvalue = NULL;
    
  switch ( _type ) {
    case LabelLabel:
    {
      std::string chaine;
      chaine = _label_name;
      chaine += " ";
      chaine += _label_value;
      this->_wxlabel     = new wxStaticText(this->_parent,
                                            wxID_ANY,
                                            wxString::FromAscii((char*)chaine.c_str()));
      this->  Add(this->_wxlabel, 0, wxLEFT | wxALIGN_CENTRE_VERTICAL, 5);
      break;
    }
    case LabelTexte:
      this->_wxlabel     = new wxStaticText(this->_parent,
                                            wxID_ANY,
                                            wxString::FromAscii(label));
      this->_wxvalue     = new wxTextCtrl(  this->_parent,
                                            wxID_ANY,
                                            wxString::FromAscii(value));
      this->_wxvalue->SetEditable(0);
      this->  Add(this->_wxlabel, 0, wxLEFT | wxALIGN_CENTRE_VERTICAL, 5);
      this->Add(this->_wxvalue,0, wxLEFT | wxALIGN_CENTRE_VERTICAL, 5);
      break;
    }
}

wxLabelParameter::~wxLabelParameter()
{
//  printf("~wxLabelParameter()\n");
/*
    if (this->_wxlabel!=NULL) { delete this->_wxlabel; this->_wxlabel=NULL;}
  if (this->_wxvalue!=NULL) { delete this->_wxvalue; this->_wxvalue=NULL;}
  */
  }

void wxLabelParameter::SetValue( const char* value) {
  _label_value = value;
  switch ( _type ) {
    case LabelLabel: {
      std::string chaine;
      chaine = _label_name + " " + _label_value;
      this->_wxlabel->SetLabel(wxString::FromAscii((char*)chaine.c_str()));
      break;
      }
    case LabelTexte:
      this->_wxvalue->SetValue(wxString::FromAscii((char*)this->_label_value.c_str()));
      break;
    }
}
