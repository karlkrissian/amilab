//
// C++ Implementation: wxFloatParameter
//
// Description: 
//
//
// Author: Karl Krissian <krissian@dis.ulpgc.es>, (C) 2009
//
// Copyright: See COPYING file that comes with this distribution
//
//

#include "wxFloatParameter.h"

using namespace std;
using namespace boost;

#if defined(WIN32)
inline double round( double d )
{
return floor( d + 0.5 );
}
#endif

//================================================================
//              wxFloatParameter
//================================================================


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
                          wxSP_ARROW_KEYS
                          | wxSP_VERTICAL
                          | wxBORDER_SIMPLE );
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
