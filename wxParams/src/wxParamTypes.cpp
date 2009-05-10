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
//           wxIntegerParameter
//==============================================================================

BEGIN_EVENT_TABLE(mySlider, wxSlider)
  EVT_SCROLL    ( mySlider::OnSliderUpdate)
END_EVENT_TABLE()

BEGIN_EVENT_TABLE(mySpinButton, wxSpinButton)
  EVT_SPIN    (wxID_ANY,  mySpinButton::OnSpinCtrlUpdate)
END_EVENT_TABLE()

BEGIN_EVENT_TABLE(mySpinCtrl, wxSpinCtrl)
  EVT_SPINCTRL    (wxID_ANY,  mySpinCtrl::OnSpinCtrlUpdate)
END_EVENT_TABLE()

//BEGIN_EVENT_TABLE(MyStaticText, wxStaticText)
//  EVT_TEXT    (wxID_ANY,  MyStaticText::OnTextUpdate)
//END_EVENT_TABLE()

BEGIN_EVENT_TABLE(MyTextCtrl, wxTextCtrl)
//    EVT_KEY_DOWN(MyTextCtrl::OnKeyDown)
//    EVT_KEY_UP(MyTextCtrl::OnKeyUp)
//    EVT_CHAR(MyTextCtrl::OnChar)

    EVT_TEXT_ENTER(wxID_ANY, MyTextCtrl::OnText)
//    EVT_TEXT_URL(wxID_ANY, MyTextCtrl::OnTextURL)
//    EVT_TEXT_MAXLEN(wxID_ANY, MyTextCtrl::OnTextMaxLen)

//    EVT_MOUSE_EVENTS(MyTextCtrl::OnMouseEvent)

//    EVT_SET_FOCUS(MyTextCtrl::OnSetFocus)
    EVT_KILL_FOCUS(MyTextCtrl::OnKillFocus)
END_EVENT_TABLE()

MyTextCtrl::MyTextCtrl(wxWindow *parent, wxWindowID id, const wxString &value,
               const wxPoint &pos, const wxSize &size, int style)
        : wxTextCtrl(parent, id, value, pos, size, style)
{
}

void MyTextCtrl::OnText(wxCommandEvent& event)
{
    void (*cbf)( void*) = (void (*)(void*)) this->_callback;
    cbf(this->_calldata);
}
 
void MyTextCtrl::OnKillFocus(wxFocusEvent& event)
{
  //printf("Kill Focus \n");
    void (*cbf)( void*) = (void (*)(void*)) this->_callback;
    cbf(this->_calldata);
}
 
//------------------------------------------------------------------------------
wxIntegerParameter::wxIntegerParameter( wxWindow* parent, int* param, const char* libelle):
//                  ------------------
    wxBoxSizer(wxHORIZONTAL)
{        
    this->_parameter = param;
    this->_parent = parent;
    this->_min=-100;
    this->_max=100;
    this->_default=0;
    this->_slider = new mySlider(this->_parent, wxID_ANY,this->_default,this->_min,this->_max);
    this->_slider->SetCallback(
      (void*)wxIntegerParameter::OnSliderUpdate,(void*) this);
    this->_slider->SetLabel(wxString::FromAscii(libelle));
    this->_slider->SetName(wxString::FromAscii(libelle));
/*
        this->_sizer1 = new wxStaticBoxSizer(this,wxHORIZONTAL);
    this->_sizer2 = new wxBoxSizer(wxHORIZONTAL);
*/
    this->_sizer2 = new wxBoxSizer(wxHORIZONTAL);
    this->_label = new wxStaticText(this->_parent, 
          wxID_ANY,
          wxString::FromAscii(libelle));

 
#if wxUSE_SPINCTRL
    this->_text = new MyTextCtrl( this->_parent, wxID_ANY, wxString::FromAscii("5"),
                             wxPoint(200, 160), wxSize(40, wxDefaultCoord), wxTE_PROCESS_ENTER);
    this->_text->SetCallback((void*)wxIntegerParameter::OnTextUpdate,(void*) this);
    
    this->_spinbut = new mySpinButton( this->_parent, wxID_ANY, wxPoint(200, 160), wxDefaultSize ,wxSP_ARROW_KEYS | wxSP_VERTICAL);
    this->_spinbut->SetRange(0,10);
    this->_spinbut->SetValue(5);
    this->_spinbut->SetCallback((void*)wxIntegerParameter::OnSpinCtrlUpdate, (void*) this);
    
    this->_spinbut_limits = new mySpinButton( this->_parent, wxID_ANY, wxPoint(200, 160), wxDefaultSize ,wxSP_ARROW_KEYS | wxSP_VERTICAL | wxSP_WRAP);
    this->_spinbut_limits->SetRange(0,1);
    this->_spinbut_limits->SetValue(1);
    this->_spinbut_limits->SetCallback((void*)wxIntegerParameter::OnLimitsUpdate, (void*) this);
#endif

    // Create texts for changing the limits
    this->_limits_sizer = new wxBoxSizer(wxHORIZONTAL);
    this->_label_min = new wxStaticText(this->_parent,
          wxID_ANY,
          wxString::FromAscii("min"));
    this->_label_min->SetToolTip("Change Minimal Value");

    this->_text_min  = new MyTextCtrl(
                              this->_parent,
                              wxID_ANY,
                              wxString::FromAscii("0"),
                              wxPoint(100, 160),
                              wxSize(40, wxDefaultCoord),
                              wxTE_PROCESS_ENTER);
    this->_text_min->SetCallback((void*)wxIntegerParameter::OnMinMaxUpdate,(void*) this);
                             
    this->_label_max = new wxStaticText(this->_parent,
          wxID_ANY,
          wxString::FromAscii("max"));
    this->_label_min->SetToolTip("Change Maximal Value");

    this->_text_max  = new MyTextCtrl( this->_parent,
          wxID_ANY,
          wxString::FromAscii("0"),
          wxPoint(200, 160),
          wxSize(40, wxDefaultCoord), 
          wxTE_PROCESS_ENTER);
    this->_text_max->SetCallback(
          (void*)wxIntegerParameter::OnMinMaxUpdate,
          (void*) this);
    
    // Layout
    this->_sizer2->Add(this->_label,   0, 
                          wxLEFT  | wxALIGN_CENTRE_VERTICAL, 2);
    this->_sizer2->Add(this->_text,    1, 
                          wxLEFT  | wxALIGN_CENTRE_VERTICAL, 5);
    this->_sizer2->Add(this->_spinbut, 0, 
                          wxRIGHT | wxALIGN_CENTRE_VERTICAL, 2);
    
    this->_limits_sizer->Add(this->_label_min,0, 
                              wxRIGHT | wxALIGN_CENTRE_VERTICAL, 5);
    this->_limits_sizer->Add(this->_text_min,1, 
                              wxRIGHT | wxALIGN_CENTRE_VERTICAL, 5);
    this->_limits_sizer->Add(this->_label_max,0, 
                              wxRIGHT | wxALIGN_CENTRE_VERTICAL, 5);
    this->_limits_sizer->Add(this->_text_max,1, 
                              wxRIGHT | wxALIGN_CENTRE_VERTICAL, 5);

    this->Add(this->_sizer2, 0, 
                  wxLEFT | wxALIGN_CENTRE_VERTICAL, 5);
    this->_slider_item = this->Add(this->_slider, 1,
                  wxEXPAND | wxLEFT, 5);
    this->Add(this->_spinbut_limits, 0,
                  wxFIXED_MINSIZE | wxRIGHT |  wxALIGN_CENTRE_VERTICAL, 2);


    this->_limits_sizer->Show(false);
}


// 
wxIntegerParameter::~wxIntegerParameter()
{
}

void wxIntegerParameter::SetConstraints(int min, int max, int def)
{
  string number_str;
  
  if (max<=min) {
    cout << "wxIntegerParameter::SetConstraints() \t for " << this->_label->GetLabel().mb_str()
        << " setting maximum to " << min+1 << endl;
    max = min+1;
  }
  // Do the change in 2 steps to avoid annoying warning
  if (_min<max) {
    this->_slider->SetValue(_min);
    this->_slider->SetRange(_min,max);
    this->_slider->SetValue(max);
    this->_slider->SetRange(min,max);
  } else {
    // no way to avoid the warning
    this->_slider->SetRange(min,max);
  }
  if (def<min) def=min;
  if (def>max) def=max;
  this->_slider->SetValue(def);
  this->_spinbut->SetRange(min,max);
  this->_spinbut->SetValue(def);
  number_str = str(format("%d") % def);
  this->_text->SetValue( wxString::FromAscii(number_str.c_str()) );
  _min     = min;
  _max     = max;
  _default = def;

  number_str = str(format("%d") % min);
  this->_text_min->SetValue( wxString::FromAscii(number_str.c_str()) );
  number_str = str(format("%d") % max);
  this->_text_max->SetValue( wxString::FromAscii(number_str.c_str()) );

}

void wxIntegerParameter::OnSliderUpdate( void* data)
{
  wxIntegerParameter* _this = (wxIntegerParameter*) data;
  char number_str[100];

  int previous_value = (*_this->_parameter);
  int new_value      = (int)_this->_slider->GetValue();
  if (previous_value!=new_value) {
    (*_this->_parameter) = new_value;
    _this->_spinbut->SetValue( (*_this->_parameter));
    sprintf(number_str,"%d",*_this->_parameter);
    _this->_text->SetValue(  wxString::FromAscii(number_str) );
    _this->Callback();
  }
}

void wxIntegerParameter::OnSpinCtrlUpdate( void* data)
{
  string number_str;
  wxIntegerParameter* _this = (wxIntegerParameter*) data;
  (*_this->_parameter) = (int)_this->_spinbut->GetValue();
//  _this->UpdateValue();
  _this->_slider->SetValue( (*_this->_parameter) );   
  number_str = str(format("%d") % *_this->_parameter);
  _this->_text->SetValue( wxString::FromAscii(number_str.c_str()) );
  _this->Callback();
}

void wxIntegerParameter::OnTextUpdate( void* data)
{
  long val;
  bool res;
  wxIntegerParameter* _this = (wxIntegerParameter*) data;
  
  wxString val_str= _this->_text->GetValue();

  res = val_str.ToLong(&val);
  if (res) {
    (*_this->_parameter) = (int)val;
  //  _this->UpdateValue();
    _this->_slider->SetValue( (*_this->_parameter) );
    _this->_spinbut->SetValue( (*_this->_parameter));
    _this->Callback();
  }
}

void wxIntegerParameter::OnLimitsUpdate( void* data)
{
  wxIntegerParameter* _this = (wxIntegerParameter*) data;
  
  if (_this->_spinbut_limits->GetValue()) {
    _this->_limits_item->Show(0);
    _this->Detach(_this->_spinbut_limits);
    _this->Detach(_this->_limits_sizer);
    _this->_slider_item=_this->Add(_this->_slider,      1,
                  wxLEFT|wxEXPAND, 5);
    _this->Add(_this->_spinbut_limits, 0,
                  wxFIXED_MINSIZE | wxRIGHT |  wxALIGN_CENTRE_VERTICAL, 2);
    _this->_slider_item->Show(1);
 } else {
    _this->_slider_item->Show(0);
    _this->Detach(_this->_spinbut_limits);
    _this->Detach(_this->_slider);
    _this->_limits_item=_this->Add(_this->_limits_sizer,      1,
                wxEXPAND | wxLEFT, 5);
    _this->Add(_this->_spinbut_limits, 0,
                  wxFIXED_MINSIZE | wxRIGHT |  wxALIGN_CENTRE_VERTICAL, 2);
    _this->_limits_item->Show(1);
  }
  _this->Layout();
}

void wxIntegerParameter::OnMinMaxUpdate( void* data)
{
  long valmin,valmax;
  bool res1,res2;
  wxIntegerParameter* _this = (wxIntegerParameter*) data;
  
  wxString val_str= _this->_text_min->GetValue();
  res1 = val_str.ToLong(&valmin);
  val_str= _this->_text_max->GetValue();
  res2 = val_str.ToLong(&valmax);
  
  
  if (res1&&res2&&(valmin<valmax)) {
    _this->SetConstraints(valmin,valmax,(*_this->_parameter));
  }
  
}

void wxIntegerParameter::UpdateValue( )
{
  (*this->_parameter) = (int)this->_slider->GetValue();
  //this->_spinctrl->GetValue();
}

void wxIntegerParameter::Update( )
{
  string number_str;
  
  this->_spinbut->SetValue( (*this->_parameter));
  this->_slider->SetValue( (*this->_parameter) );
  number_str = str(format("%d") % *this->_parameter);
  this->_text->SetValue( wxString::FromAscii(number_str.c_str()));
}

//-------------------------------------------
void wxIntegerParameter::SetToolTip( const wxString& tt)
{
   this->_label ->SetToolTip(tt);
   this->_slider->SetToolTip(tt);
}

//==============================================================================
//              wxFloatParameter
//==============================================================================


wxFloatParameter::wxFloatParameter( wxWindow* parent, float* param, const char* libelle):
//                  ------------------
    wxBoxSizer(wxHORIZONTAL)
{
    this->_parameter = param;
    this->_parent = parent;
    this->_min     = -100;
    this->_max     = 100;
    this->_default = 0;
    this->SetDecimate(2);
    this->_slider = new mySlider(this->_parent, wxID_ANY,
                                 (int)round((this->_default*this->_factor)),
                                 (int)round((this->_min    *this->_factor)),
                                 (int)round((this->_max    *this->_factor)));
   this->_slider->SetCallback(
      (void*)wxFloatParameter::OnSliderUpdate,
      (void*) this);
/*
        this->_sizer1 = new wxStaticBoxSizer(this,wxHORIZONTAL);
    this->_sizer2 = new wxBoxSizer(wxHORIZONTAL);
*/
    this->_sizer2 = new wxBoxSizer(wxHORIZONTAL);
        
    this->_label  = new wxStaticText(
                        this->_parent,
                        wxID_ANY,
                        wxString::FromAscii(libelle),
                        wxDefaultPosition,
                        wxDefaultSize
                        );
    this->_label->Wrap(1);
    string value;
    value = str(format("%.2f") %*this->_parameter);
//    this->_label_value = new wxStaticText(this->_parent, wxID_ANY, value);

    this->_text = new MyTextCtrl(
                      this->_parent,
                      wxID_ANY, 
                      wxString::FromAscii(value.c_str()),
                      wxPoint(200, 160), 
                      wxSize(70, wxDefaultCoord),
                      wxTE_PROCESS_ENTER);
    this->_text->SetCallback( (void*)wxFloatParameter::OnTextUpdate,
                              (void*) this);
    
    this->_spinbut = new mySpinButton( this->_parent,
                          wxID_ANY,
                          wxPoint(200, 160),
                          wxDefaultSize,
                          wxSP_ARROW_KEYS | wxSP_VERTICAL);
    this->_spinbut->SetRange(0,1000);
    this->_spinbut->SetValue(500);
    this->_spinbut->SetCallback((void*)wxFloatParameter::OnSpinCtrlUpdate, (void*) this);

    this->_spinbut_limits = new mySpinButton( this->_parent, wxID_ANY, wxPoint(200, 160), wxDefaultSize ,wxSP_ARROW_KEYS | wxSP_VERTICAL | wxSP_WRAP);
    this->_spinbut_limits->SetRange(0,1);
    this->_spinbut_limits->SetValue(1);
    this->_spinbut_limits->SetCallback((void*)wxFloatParameter::OnLimitsUpdate, (void*) this);
    this->_spinbut_limits->SetToolTip(wxString::FromAscii("Change variable range"));

    // Create texts for changing the limits
    this->_limits_sizer = new wxBoxSizer(wxHORIZONTAL);
    this->_label_min = new wxStaticText(this->_parent,
                                        wxID_ANY,
                                        wxString::FromAscii("min:"));
    this->_text_min  = new MyTextCtrl(this->_parent,
                                      wxID_ANY,
                                      wxString::FromAscii("0"),
                                      wxPoint(100, 160),
                                      wxSize(60, wxDefaultCoord), 
                                      wxTE_PROCESS_ENTER);
    this->_text_min->SetCallback((void*)wxFloatParameter::OnMinMaxUpdate,(void*) this);
                             
    this->_label_max = new wxStaticText(this->_parent,
                                        wxID_ANY,
                                        wxString::FromAscii("max:"));
    this->_text_max  = new MyTextCtrl(this->_parent,
                                      wxID_ANY,
                                      wxString::FromAscii("0"),
                                      wxPoint(200, 160),
                                      wxSize(60, wxDefaultCoord), 
                                      wxTE_PROCESS_ENTER);
    this->_text_max->SetCallback( (void*)wxFloatParameter::OnMinMaxUpdate,
                                  (void*) this);
    
    // Layout
    this->_sizer2->Add(this->_label,   0, 
                          wxLEFT  | wxALIGN_CENTRE_VERTICAL, 2);
    this->_sizer2->Add(this->_text,    1, 
                          wxLEFT  | wxALIGN_CENTRE_VERTICAL, 5);
    this->_sizer2->Add(this->_spinbut, 0, 
                          wxRIGHT | wxALIGN_CENTRE_VERTICAL, 2);
    
    this->_limits_sizer->Add(this->_label_min,0, 
                              wxRIGHT | wxALIGN_CENTRE_VERTICAL, 5);
    this->_limits_sizer->Add(this->_text_min,1, 
                              wxRIGHT | wxALIGN_CENTRE_VERTICAL, 5);
    this->_limits_sizer->Add(this->_label_max,0, 
                              wxRIGHT | wxALIGN_CENTRE_VERTICAL, 5);
    this->_limits_sizer->Add(this->_text_max,1, 
                              wxRIGHT | wxALIGN_CENTRE_VERTICAL, 5);
    
    this->Add(this->_sizer2, 0, 
                  wxLEFT | wxALIGN_CENTRE_VERTICAL, 5);
    this->_slider_item = this->Add(this->_slider, 1,
                  wxEXPAND | wxLEFT, 5);
    this->Add(this->_spinbut_limits, 0,
                  wxFIXED_MINSIZE | wxRIGHT |  wxALIGN_CENTRE_VERTICAL, 2);
    
    this->_limits_sizer->Show(false);

 }

wxFloatParameter::~wxFloatParameter()
{
}

void wxFloatParameter::SetConstraints( float min, float max, float def)
{
  int oldmin,oldmax,newmin,newmax;
  string number_str;
  
  oldmin=(int)round((this->_min*this->_factor));
  oldmax=(int)round((this->_max*this->_factor));
  newmin=(int)round((min       *this->_factor));
  newmax=(int)round((max       *this->_factor));
  
  // Do the change in 2 steps to avoid annoying warning (from Motif ...)
  if (oldmin<newmax) {
    this->_slider->SetValue(oldmin);
    this->_slider->SetRange(oldmin,newmax);
    this->_slider->SetValue(newmax);
    this->_slider->SetRange(newmin,newmax);
  } else {
    // no way to avoid the warning
    this->_slider->SetRange(newmin,newmax);
  }
  
  if (def<min) def=min;
  if (def>max) def=max;
  
  this->_slider->SetValue((int)round((def*this->_factor)));
  this->_spinbut->SetRange(newmin,newmax);
  this->_spinbut->SetValue((int)round((def*this->_factor)));
  number_str = str(format("%.2f")%def);
  this->_text->SetValue(wxString::FromAscii(number_str.c_str()));
  this->_min     = min;
  this->_max     = max;
  this->_default = def;
  
  number_str= str(format("%.2f")%min);
  this->_text_min->SetValue( wxString::FromAscii(number_str.c_str()) );
  number_str=str(format("%.2f")%max);
  this->_text_max->SetValue( wxString::FromAscii(number_str.c_str()) );

}  

void wxFloatParameter::OnSliderUpdate( void* data)
{
  wxFloatParameter* _this = (wxFloatParameter*) data;

  float previous_value = (*_this->_parameter);
  float new_value      = (float)_this->_slider->GetValue()/
                          _this->_factor;
  if (previous_value!=new_value) {
    (*_this->_parameter) = new_value;
    _this->_spinbut->SetValue( (int) round(*_this->_parameter*_this->_factor));
    std::string value = str(format("%.2f") % *_this->_parameter);
    _this->_text->SetValue(wxString::FromAscii(value.c_str()));
    _this->Callback();
  }
}
  
void wxFloatParameter::OnSpinCtrlUpdate(void* data)
{
  wxFloatParameter* _this = (wxFloatParameter*) data;
  _this->UpdateValue();
  _this->_slider->SetValue( (int) round((*_this->_parameter) *_this->_factor));
  string value;
  value = str(format("%.2f") % *_this->_parameter);
  _this->_text->SetValue(wxString::FromAscii(value.c_str()));
  _this->Callback();
//  printf("param = %f \n",*_this->_parameter);
}
  
void wxFloatParameter::OnTextUpdate( void* data)
{
  double val;
  bool res;
  wxFloatParameter* _this = (wxFloatParameter*) data;
  
  wxString val_str= _this->_text->GetValue();

  res = val_str.ToDouble(&val);
  if (res) {
    (*_this->_parameter) = (float)val;
  //  _this->UpdateValue();
    _this->_slider->SetValue( (int) round((*_this->_parameter) *_this->_factor));
    _this->_spinbut->SetValue( (int) round((*_this->_parameter) *_this->_factor));
    _this->Callback();
  }
}

void wxFloatParameter::OnLimitsUpdate( void* data)
{
  wxFloatParameter* _this = (wxFloatParameter*) data;
  
/*
  if (_this->_spinbut_limits->GetValue()) {
    _this->_limits_item->Show(0);
    _this->Detach(_this->_limits_sizer);
    _this->_slider_item=_this->Add(_this->_slider,      1,wxEXPAND | wxALL, 5);
    _this->_slider_item->Show(1);
 } else {
    _this->_slider_item->Show(0);
    _this->Detach(_this->_slider);
    _this->_limits_item=_this->Add(_this->_limits_sizer,      1,wxEXPAND | wxALL, 5);
    _this->_limits_item->Show(1);
  }
*/

  if (_this->_spinbut_limits->GetValue()) {
    _this->_limits_item->Show(0);
    _this->Detach(_this->_spinbut_limits);
    _this->Detach(_this->_limits_sizer);
    _this->_slider_item=_this->Add(_this->_slider,      1,
                  wxLEFT|wxEXPAND, 5);
    _this->Add(_this->_spinbut_limits, 0,
                  wxFIXED_MINSIZE | wxRIGHT |  wxALIGN_CENTRE_VERTICAL, 2);
    _this->_slider_item->Show(1);
 } else {
    _this->_slider_item->Show(0);
    _this->Detach(_this->_spinbut_limits);
    _this->Detach(_this->_slider);
    _this->_limits_item=_this->Add(_this->_limits_sizer,      1,
                wxEXPAND | wxLEFT, 5);
    _this->Add(_this->_spinbut_limits, 0,
                  wxFIXED_MINSIZE | wxRIGHT |  wxALIGN_CENTRE_VERTICAL, 2);
    _this->_limits_item->Show(1);
  }

//  _this->SetSizeHints(_this->_parent);
//  _this->Fit(_this->_parent);
  _this->Layout();
}

void wxFloatParameter::OnMinMaxUpdate( void* data)
{
  double valmin,valmax;
  bool res1,res2;
  wxFloatParameter* _this = (wxFloatParameter*) data;
  
  wxString val_str= _this->_text_min->GetValue();
  res1 = val_str.ToDouble(&valmin);
  val_str= _this->_text_max->GetValue();
  res2 = val_str.ToDouble(&valmax);
  
  
  if (res1&&res2&&(valmin<valmax)) {
    _this->SetConstraints((float)valmin,(float)valmax,(*_this->_parameter));
  }
  
}

void wxFloatParameter::UpdateValue( )
{
  (*this->_parameter) = (float)this->_spinbut->GetValue()/this->_factor;
}


void wxFloatParameter::Update( )
{
  this->_spinbut->SetValue( (int) round(*this->_parameter*this->_factor));
  this->_slider->SetValue( (int) round((*this->_parameter) *this->_factor));   
  std::string value = str(format("%.2f") % *this->_parameter);
  this->_text->SetValue(wxString::FromAscii(value.c_str()));
}

//-------------------------------------------
void wxFloatParameter::SetToolTip( const wxString& tt)
{
   this->_label ->SetToolTip(tt);
   this->_slider->SetToolTip(tt);
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

wxStringParameter::wxStringParameter( wxWindow* parent, std::string* value,
                                      const char* label): wxBoxSizer(wxHORIZONTAL)
{

  this->_parameter = value;
  this->_parent    = parent;
  this->_label     = new wxStaticText(this->_parent, wxID_ANY, wxString::FromAscii(label));

  this->_text = new MyTextCtrl( this->_parent, wxID_ANY,
                              wxString::FromAscii(value->c_str()),
                              wxDefaultPosition, 
                              //wxSize(40, wxDefaultCoord),
                              wxDefaultSize,
                               wxTE_PROCESS_ENTER);
  //this->_text->SetSize(wxSIZE_AUTO_HEIGHT,10);
  this->_text->SetCallback((void*)wxStringParameter::OnStringUpdate,(void*) this);
  //this->_text->SetMinSize(wxSize(80,25));
  //this->_text->SetMinClientSize(wxSize(80,25));
  this->Add(this->_label, 0, wxLEFT | wxALIGN_CENTRE_VERTICAL, 5);
  this->Add(this->_text,  1, wxALL | wxEXPAND,5 );
//wxALL, 5);
//wxLEFT | wxALIGN_CENTRE_VERTICAL, 5);
}


void wxStringParameter::OnStringUpdate( void* data) 
{
  wxStringParameter* _this=(wxStringParameter*)data;
  // risky operation ... parameter has to be allocated with enough space ...
  *_this->_parameter = (_this->_text->GetValue()).mb_str(wxConvUTF8);
  
}

// updating displayed value
void wxStringParameter::Update()
//   ------
{
  this->_text->SetValue(wxString::FromAscii((*this->_parameter).c_str()));
} // Update()


//==============================================================================
//          Filename Parameter
//==============================================================================

BEGIN_EVENT_TABLE(myButton, wxButton)
    EVT_BUTTON(  wxID_ANY,myButton::OnButton)
END_EVENT_TABLE()

wxFilenameParameter::wxFilenameParameter( wxWindow* parent,
                                          std::string* value,
                                          const char* label,
                                          type_label type): wxBoxSizer(wxHORIZONTAL)
{

  this->_default_path      = wxString::FromAscii("");
  this->_default_filename  = wxString::FromAscii("");
  this->_default_extension = wxString::FromAscii("");
  this->_wildcard          = wxString::FromAscii("*.*");
  
  this->_parameter = value;
  this->_parent    = parent;
  this->_label     = new wxStaticText(this->_parent,
                                      wxID_ANY,
                                      wxString::FromAscii(label));

  this->_text = new MyTextCtrl( this->_parent,
                                wxID_ANY,
                                wxString::FromAscii(value->c_str()),
                                wxDefaultPosition, 
                                wxSize(40, wxDefaultCoord),
                                wxTE_PROCESS_ENTER);
  this->_text->SetCallback((void*)wxFilenameParameter::OnStringUpdate,(void*) this);
 //   this->_text->SetCallback((void*)wxFloatParameter::OnTextUpdate,(void*) this);
  this->_button = new myButton( this->_parent,
                                wxID_ANY,
                                wxString::FromAscii("Browse"));
  this->_button->SetCallback((void*)wxFilenameParameter::BrowseFile, (void*) this);

  this->Add(this->_label, 0, wxLEFT | wxALIGN_CENTRE_VERTICAL, 5);
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
     // risky operation ... parameter has to be allocated with enough space ...
     *_this->_parameter = filename.mb_str(wxConvUTF8);
  }
}
 

void wxFilenameParameter::OnStringUpdate( void* data) 
{
  wxFilenameParameter* _this=(wxFilenameParameter*)data;
  // risky operation ... parameter has to be allocated with enough space ...
  *_this->_parameter = _this->_text->GetValue().mb_str(wxConvUTF8);
  
}

//==============================================================================
//          PARAMETRE  wxButtonParameter
//==============================================================================

BEGIN_EVENT_TABLE(wxButtonParameter, wxButton)
    EVT_LEFT_DOWN(  wxButtonParameter::OnLeftDown)
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
void wxButtonParameter::OnLeftDown(wxMouseEvent& event)
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
    EVT_LEFT_DOWN(  wxBitmapButtonParameter::OnLeftDown)
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
void wxBitmapButtonParameter::OnLeftDown(wxMouseEvent& event)
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
