//
// C++ Implementation: wxIntegerParameter
//
// Description:
//
//
// Author: Karl Krissian <krissian@dis.ulpgc.es>, (C) 2009
//
// Copyright: See COPYING file that comes with this distribution
//
//

#include "wxIntegerParameter.h"

#include <iostream>
using namespace std;
using namespace boost;

//====================================================
//           wxIntegerParameter
//====================================================



//------------------------------------------------------------------------------
wxIntegerParameter::wxIntegerParameter( wxWindow* parent, int* param, const char* libelle):
//                  ------------------
    wxBoxSizer(wxHORIZONTAL)
{
    _parameter = param;
    _parent = parent;
    _min=-100;
    _max=100;
    _default=0;
    _slider = new mySlider( _parent, wxID_ANY,
                            _default,_min,_max,
                            wxDefaultPosition,
                            wxDefaultSize,
                            wxBORDER_SUNKEN );
    _slider->SetCallback(
      (void*)wxIntegerParameter::OnSliderUpdate,(void*) this);
    _slider->SetLabel(wxString::FromAscii(libelle));
    _slider->SetName(wxString::FromAscii(libelle));
/*
        _sizer1 = new wxStaticBoxSizer(this,wxHORIZONTAL);
    _sizer2 = new wxBoxSizer(wxHORIZONTAL);
*/
    _sizer2 = new wxBoxSizer(wxHORIZONTAL);
    _label = new wxStaticText(_parent,
          wxID_ANY,
          wxString::FromAscii(libelle));


#if wxUSE_SPINCTRL
    _text = new MyTextCtrl( _parent,
                            wxID_ANY,
                            wxString::FromAscii("5"),
                            wxPoint(200, 160),
                            wxSize(40, wxDefaultCoord),
                            wxTE_PROCESS_ENTER);
    _text->SetCallback((void*)wxIntegerParameter::OnTextUpdate,(void*) this);

    _spinbut = new mySpinButton(
                        _parent,
                        wxID_ANY,
                        wxPoint(200, 160),
                        wxSize( wxDefaultCoord,
                                _text->GetSize().GetHeight()),
                        wxSP_ARROW_KEYS | wxSP_VERTICAL);
    _spinbut->SetRange(0,10);
    _spinbut->SetValue(5);
    _spinbut->SetCallback((void*)wxIntegerParameter::OnSpinCtrlUpdate, (void*) this);

    _spinbut_limits = new mySpinButton( _parent, wxID_ANY, wxPoint(200, 160), wxDefaultSize ,wxSP_ARROW_KEYS | wxSP_VERTICAL | wxSP_WRAP);
    _spinbut_limits->SetRange(0,1);
    _spinbut_limits->SetValue(1);
    _spinbut_limits->SetCallback((void*)wxIntegerParameter::OnLimitsUpdate, (void*) this);
#endif

    // Create texts for changing the limits
    _limits_sizer = new wxBoxSizer(wxHORIZONTAL);
    _label_min = new wxStaticText(_parent,
          wxID_ANY,
          wxString::FromAscii("min"));
    _label_min->SetToolTip(_T("Change Minimal Value"));

    _text_min  = new MyTextCtrl(
                              _parent,
                              wxID_ANY,
                              wxString::FromAscii("0"),
                              wxPoint(100, 160),
                              wxSize(40, wxDefaultCoord),
                              wxTE_PROCESS_ENTER);
    _text_min->SetCallback((void*)wxIntegerParameter::OnMinMaxUpdate,(void*) this);

    _label_max = new wxStaticText(_parent,
          wxID_ANY,
          wxString::FromAscii("max"));
    _label_min->SetToolTip(_T("Change Maximal Value"));

    _text_max  = new MyTextCtrl( _parent,
          wxID_ANY,
          wxString::FromAscii("0"),
          wxPoint(200, 160),
          wxSize(40, wxDefaultCoord),
          wxTE_PROCESS_ENTER);
    _text_max->SetCallback(
          (void*)wxIntegerParameter::OnMinMaxUpdate,
          (void*) this);

    // Layout
    _sizer2->Add(_label,   0,
                          wxLEFT  | wxALIGN_CENTRE_VERTICAL, 2);
    _sizer2->Add(_text,    1,
                          wxLEFT  | wxALIGN_CENTRE_VERTICAL, 5);
    _sizer2->Add(_spinbut, 0,
                          wxRIGHT | wxALIGN_CENTRE_VERTICAL, 0);

    _limits_sizer->Add(_label_min,0,
                              wxRIGHT | wxALIGN_CENTRE_VERTICAL, 5);
    _limits_sizer->Add(_text_min,1,
                              wxRIGHT | wxALIGN_CENTRE_VERTICAL, 5);
    _limits_sizer->Add(_label_max,0,
                              wxRIGHT | wxALIGN_CENTRE_VERTICAL, 5);
    _limits_sizer->Add(_text_max,1,
                              wxRIGHT | wxALIGN_CENTRE_VERTICAL, 5);

    Add(_sizer2, 0, wxLEFT | wxALIGN_CENTRE_VERTICAL, 5);
    _slider_item = Add(_slider, 1,wxEXPAND | wxLEFT, 5);

    Add(_spinbut_limits, 0,
        wxFIXED_MINSIZE | wxRIGHT |  wxALIGN_CENTRE_VERTICAL, 2);

    _limits_sizer->Show(false);
}


//
wxIntegerParameter::~wxIntegerParameter()
{
}

void wxIntegerParameter::SetConstraints(int min, int max, int def)
{
  std::string number_str;

  if (max<=min) {
    std::cout << "wxIntegerParameter::SetConstraints() \t for " << this->_label->GetLabel().mb_str()
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

