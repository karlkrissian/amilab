//
// C++ Implementation: wxNumericParameter
//
// Description: 
//
//
// Author: Karl Krissian <krissian@dis.ulpgc.es>, (C) 2009
//
// Copyright: See COPYING file that comes with this distribution
//
//

#include <string>
#include <boost/format.hpp>

#include "wxNumericParameter.h"


//========================================================
//              wxNumericParameter
//========================================================

/// Constructor
template <class T>
wxNumericParameter<T>::wxNumericParameter( 
//                  ------------------
    wxWindow* parent,
    T* param,
    const char* libelle):
    wxBoxSizer(wxHORIZONTAL)
{
    _parameter = param;
    _display_format = boost::format("%1%");
    _parent = parent;
    _min     = -100;
    _max     = 100;
    _default = 0;
    _text = NULL;
    // need _text to exists to change its size
    {
      T tmp=0;
      // if integer number
      if (tmp == (T)(tmp+0.5)) 
        SetDecimate(0); 
      else // floating number
        SetDecimate(2);
    } 
    _slider = new mySlider(_parent, wxID_ANY,
                            (int)round((_default*_factor)),
                            (int)round((_min    *_factor)),
                            (int)round((_max    *_factor)));
   _slider->SetCallback(
      (void*)wxNumericParameter<T>::OnSliderUpdate,
      (void*) this);
/*
        _sizer1 = new wxStaticBoxSizer(this,wxHORIZONTAL);
    _sizer2 = new wxBoxSizer(wxHORIZONTAL);
*/
    _sizer2 = new wxBoxSizer(wxHORIZONTAL);
        
    _label  = new wxStaticText(
                        _parent,
                        wxID_ANY,
                        wxString::FromAscii(libelle),
                        wxDefaultPosition,
                        wxDefaultSize,
                        wxALIGN_LEFT 
                        );
    _label->Wrap(1);
    std::string value;
    value = str(_display_format % (*_parameter));
//    _label_value = new wxStaticText(_parent, wxID_ANY, value);

    _text = new MyTextCtrl(
                      _parent,
                      wxID_ANY, 
                      wxString::FromAscii(value.c_str()),
                      wxDefaultPosition, 
                      //wxDefaultSize, 
                      wxSize( 40+10*_decimate,
                              wxDefaultCoord),
                      wxTE_PROCESS_ENTER);
    _text->SetCallback( (void*)wxNumericParameter<T>::OnTextUpdate,
                              (void*) this);

    //cout << "text left ident in mm = " << _text->GetLeftIdent(); << endl;

    _spinbut = new mySpinButton(
                        _parent,
                        wxID_ANY,
                        wxDefaultPosition,
                        wxSize( wxDefaultCoord,
                                _text->GetSize().GetHeight()),
                        wxSP_ARROW_KEYS | wxSP_VERTICAL);
    _spinbut->SetRange(0,1000);
    _spinbut->SetValue(500);
    _spinbut->SetCallback((void*)wxNumericParameter<T>::OnSpinCtrlUpdate, (void*) this);

    // Reset the slider's size
    _slider->SetSize(wxSize( wxDefaultCoord,
                            _text->GetSize().GetHeight()));

    // Create texts for changing the limits
    _limits_sizer = new wxBoxSizer(wxHORIZONTAL);
    _label_open_sqb = new wxStaticText(_parent,
                                        wxID_ANY,
                                        wxString::FromAscii("["));
    _label_comma = new wxStaticText(_parent,
                                        wxID_ANY,
                                        wxString::FromAscii(","));
    _label_close_sqb = new wxStaticText(_parent,
                                        wxID_ANY,
                                        wxString::FromAscii("]"));
    _text_min  = new MyTextCtrl(_parent,
                                      wxID_ANY,
                                      wxString::FromAscii("0"),
                                      wxDefaultPosition,
                                      wxDefaultSize, 
                                      wxTE_PROCESS_ENTER);
    _text_min->SetToolTip(_T("Scale minimal value"));
    _text_min->SetCallback((void*)wxNumericParameter<T>::OnMinMaxUpdate,(void*) this);

    _text_max  = new MyTextCtrl(_parent,
                                wxID_ANY,
                                wxString::FromAscii("0"),
                                wxDefaultPosition,
                                wxDefaultSize, 
                                wxTE_PROCESS_ENTER | wxTE_RIGHT );
    _text_max->SetToolTip(_T("Scale maximal value"));
    _text_max->SetCallback( (void*)wxNumericParameter<T>::OnMinMaxUpdate,
                                  (void*) this);

    _limits_sizer->Add( _label_open_sqb,0,
                            wxLEFT | wxALIGN_CENTRE_VERTICAL, 2);
    _limits_sizer->Add( _text_min,1,
                            wxLEFT | wxRIGHT | wxALIGN_CENTRE_VERTICAL, 1);
    _limits_sizer->Add( _label_comma,0,
                            wxLEFT | wxRIGHT | wxALIGN_CENTRE_VERTICAL, 1);
    _limits_sizer->Add( _text_max,1,
                            wxLEFT | wxRIGHT | wxALIGN_CENTRE_VERTICAL, 1);
    _limits_sizer->Add( _label_close_sqb,0,
                            wxRIGHT | wxALIGN_CENTRE_VERTICAL, 2);

    // Create Spinbutton to change scale limits
    _spinbut_limits = new mySpinButton( _parent, wxID_ANY, 
        wxPoint(200, 160), 
        wxSize( wxDefaultCoord,
                _text->GetSize().GetHeight()),
        //wxDefaultSize,
        wxSP_ARROW_KEYS | wxSP_VERTICAL | wxSP_WRAP | wxBORDER_SIMPLE );
    _spinbut_limits->SetRange(0,1);
    _spinbut_limits->SetValue(1);
    _spinbut_limits->SetCallback((void*)wxNumericParameter<T>::OnLimitsUpdate, (void*) this);
    _spinbut_limits->SetToolTip(wxString::FromAscii("Change variable range"));

    // Layout
    _sizer2->Add( _label,   0, 
                      wxLEFT  | wxALIGN_CENTRE_VERTICAL, 0);
    _sizer2->Add( _text,    1, 
                        wxLEFT  
                      | wxALIGN_CENTRE_VERTICAL 
                      , 
                    2);
    _sizer2->Add( _spinbut, 0, 
                       wxALIGN_CENTRE_VERTICAL, 0);
    
    
    Add(_sizer2, 0, wxALIGN_CENTRE_VERTICAL | wxEXPAND, 0);
    _slider_item = Add(_slider, 1, wxEXPAND , 0);
    Add(_spinbut_limits, 0,
                  //wxFIXED_MINSIZE 
                  //|
                   wxRIGHT 
                  |
                    wxALIGN_CENTRE_VERTICAL, 1);

    _limits_sizer->Show(false);
    _slider_detached = false;
    _limits_sizer_detached = true;

 }

/// Destructor
template <class T>
wxNumericParameter<T>::~wxNumericParameter()
{

  // free the detached sizer
  if (_limits_sizer_detached) 
    delete this->_limits_sizer;

  if (_slider_detached)
    delete this->_slider;

/*
  // free memory ?? does not seem to work well ...
  _sizer2->Remove(_limits_sizer);
  Remove(_sizer2);
  Remove(_limits_sizer);
*/

}

//-----------------------------------------------------------
template <class T>
void wxNumericParameter<T>::RecomputeTextSize()
{
  //int smin;
  //int smax;
  int newsize;

  // to do it well, we need to get the text extent:
  {
    // first get a drawing context
    wxClientDC dc(_text);
    // get the same fonts
    dc.SetFont(_text->GetFont());
    // truncate min and max based on _decimate value
    double min1 = round((_min*_factor))/(1.0*_factor);
    double max1 = round((_max*_factor))/(1.0*_factor);
    // get the displacement value
    double displ = 1.0/_factor;

    int         max_width = 0,tmp;
    std::string mstr;
    // get min1
    mstr = (_display_format % min1).str();
    tmp = dc.GetTextExtent(
                wxString::FromAscii(mstr.c_str())
              ).GetWidth();
    max_width = (max_width>tmp?max_width:tmp);
    // get min1+displ 
    mstr = (_display_format % (min1+displ)).str();
    tmp = dc.GetTextExtent(
                wxString::FromAscii(mstr.c_str())
              ).GetWidth();
    max_width = (max_width>tmp?max_width:tmp);
    // get max1-displ
    mstr = (_display_format % (max1-displ)).str();
    tmp = dc.GetTextExtent(
                wxString::FromAscii(mstr.c_str())
              ).GetWidth();
    max_width = (max_width>tmp?max_width:tmp);
    // get max1
    mstr = (_display_format % max1).str();
    tmp = dc.GetTextExtent(
                wxString::FromAscii(mstr.c_str())
              ).GetWidth();
    max_width = (max_width>tmp?max_width:tmp);

    newsize = max_width+(int)(2*_text->GetWindowBorderSize().GetWidth());
    // ad-hoc how to compute the margin with the wxTextCtl ?
    #if defined(__WIN32__) 
      newsize += 5;
    #endif
    #if defined(__WXGTK__)
      newsize += 10;
    #endif

  } // we don´t need dc anymore


  // Replace method the wxTextCtrl widget
  if (_text->GetSize().GetWidth()!=newsize) {
    _text->SetMinSize(wxSize(newsize,wxDefaultCoord));
    _parent->Layout();
  }
}

//--------------------------------------------------------
template <class T>
void wxNumericParameter<T>::SetConstraints( 
    const T& min,
    const T& max,
    const T& def)
{
  int oldmin,oldmax,newmin,newmax;
  std::string number_str;
  
  oldmin=(int)round((_min*_factor));
  oldmax=(int)round((_max*_factor));
  newmin=(int)round((min       *_factor));
  newmax=(int)round((max       *_factor));
  
  // Do the change in 2 steps to avoid annoying warning (from Motif ...)
  if (oldmin<newmax) {
    _slider->SetValue(oldmin);
    _slider->SetRange(oldmin,newmax);
    _slider->SetValue(newmax);
    _slider->SetRange(newmin,newmax);
  } else {
    // no way to avoid the warning
    _slider->SetRange(newmin,newmax);
  }
  
  T newdef = def;
  if (newdef<min) newdef=min;
  if (newdef>max) newdef=max;
  
  _slider->SetValue((int)round((newdef*_factor)));
  _spinbut->SetRange(newmin,newmax);
  _spinbut->SetValue((int)round((newdef*_factor)));
  number_str = str(_display_format % newdef);
  _text->SetValue(wxString::FromAscii(number_str.c_str()));
  _min     = min;
  _max     = max;
  _default = newdef;
  
  number_str= str(_display_format % min);
  _text_min->SetValue( wxString::FromAscii(number_str.c_str()) );
  number_str=str(_display_format % max);
  _text_max->SetValue( wxString::FromAscii(number_str.c_str()) );

  RecomputeTextSize();

}  

//--------------------------------------------------------
template <class T>
void wxNumericParameter<T>::OnSliderUpdate( void* data)
{
  wxNumericParameter<T>* _this = (wxNumericParameter*) data;

  T previous_value = (*_this->_parameter);
  T new_value      = (T)_this->_slider->GetValue()/
                        _this->_factor;
  if (previous_value!=new_value) {
    (*_this->_parameter) = new_value;
    _this->_spinbut->SetValue( (int) round(*_this->_parameter*_this->_factor));
    std::string value = str(_this->_display_format % (*_this->_parameter));
    _this->_text->SetValue(wxString::FromAscii(value.c_str()));
    _this->Callback();
  }
}
  
//--------------------------------------------------------
template <class T>
void wxNumericParameter<T>::OnSpinCtrlUpdate(void* data)
{
  wxNumericParameter<T>* _this = (wxNumericParameter*) data;
  _this->UpdateValue();
  _this->_slider->SetValue( (int) round((*_this->_parameter) *_this->_factor));
  std::string value;
  value = str(_this->_display_format % *_this->_parameter);
  _this->_text->SetValue(wxString::FromAscii(value.c_str()));
  _this->Callback();
//  printf("param = %f \n",*_this->_parameter);
}
  
//--------------------------------------------------------
template <class T>
void wxNumericParameter<T>::OnTextUpdate( void* data)
{
  double val;
  bool res;
  wxNumericParameter<T>* _this = (wxNumericParameter*) data;
  
  wxString val_str= _this->_text->GetValue();

  res = val_str.ToDouble(&val);
  if (res) {
    (*_this->_parameter) = (T)val;
  //  _UpdateValue();
    _this->_slider->SetValue( (int) round((*_this->_parameter) *_this->_factor));
    _this->_spinbut->SetValue( (int) round((*_this->_parameter) *_this->_factor));
    _this->Callback();
  }
}

//--------------------------------------------------------
template <class T>
void wxNumericParameter<T>::OnLimitsUpdate( void* data)
{
  wxNumericParameter<T>* _this = (wxNumericParameter*) data;
  
/*
  if (_this->_spinbut_limits->GetValue()) {
    _this->_limits_item->Show(0);
    _Detach(_this->_limits_sizer);
    _this->_slider_item=_Add(_this->_slider,      1,wxEXPAND | wxALL, 5);
    _this->_slider_item->Show(1);
 } else {
    _this->_slider_item->Show(0);
    _Detach(_this->_slider);
    _this->_limits_item=_Add(_this->_limits_sizer,      1,wxEXPAND | wxALL, 5);
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
    _this->_slider_detached = false;
    _this->_limits_sizer_detached = true;
 } else {
    _this->_slider_item->Show(0);
    _this->Detach(_this->_spinbut_limits);
    _this->Detach(_this->_slider);
    _this->_limits_item=_this->Add(_this->_limits_sizer,      1,
                wxEXPAND | wxLEFT, 5);
    _this->Add(_this->_spinbut_limits, 0,
                  wxFIXED_MINSIZE | wxRIGHT |  wxALIGN_CENTRE_VERTICAL, 2);
    _this->_limits_item->Show(1);
    _this->_slider_detached = true;
    _this->_limits_sizer_detached = false;
  }

//  _SetSizeHints(_this->_parent);
//  _Fit(_this->_parent);
  _this->Layout();
}

//--------------------------------------------------------
template <class T>
void wxNumericParameter<T>::OnMinMaxUpdate( void* data)
{
  double valmin,valmax;
  bool res1,res2;
  wxNumericParameter<T>* _this = (wxNumericParameter*) data;
  
  wxString val_str= _this->_text_min->GetValue();
  res1 = val_str.ToDouble(&valmin);
  val_str= _this->_text_max->GetValue();
  res2 = val_str.ToDouble(&valmax);
  
  
  if (res1&&res2&&(valmin<valmax)) {
    _this->SetConstraints((T)valmin,(T)valmax,(*_this->_parameter));
  }
  
}

//--------------------------------------------------------
template <class T>
void wxNumericParameter<T>::UpdateValue( )
{
  (*_parameter) = (T)_spinbut->GetValue()/_factor;
}


//--------------------------------------------------------
template <class T>
void wxNumericParameter<T>::Update( )
{
  _spinbut->SetValue( (int) round(*_parameter*_factor));
  _slider->SetValue( (int) round((*_parameter) *_factor));   
  std::string value = str(_display_format % *_parameter);
  _text->SetValue(wxString::FromAscii(value.c_str()));
}

//-------------------------------------------
template <class T>
void wxNumericParameter<T>::SetToolTip( const wxString& tt)
{
   _label  ->SetToolTip(tt);
   _slider ->SetToolTip(tt);
   _text   ->SetToolTip(tt);
   _spinbut->SetToolTip(tt);
}

//-------------------------------------------
template <class T>
void wxNumericParameter<T>::Enable(bool enable)
{
  if (enable!=_enabled) {
    _label          ->Enable(enable);
    _slider         ->Enable(enable);
    _text           ->Enable(enable);
    _spinbut        ->Enable(enable);
    _spinbut_limits ->Enable(enable);
    _enabled = enable;
  }
}

