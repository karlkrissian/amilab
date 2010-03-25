//
// C++ Interface: wxNumericParameter
//
// Description: 
//
//
// Author: Karl Krissian <krissian@dis.ulpgc.es>, (C) 2009
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _wxNumericParameter_h_
#define _wxNumericParameter_h_


//--------------------------------------------------
// includes Boost format
//--------------------------------------------------
#include "boost/format.hpp"

//--------------------------------------------------
// includes for wxWidgets
//--------------------------------------------------
#include "widget.hpp"
#include "mySlider.h"
#include "mySpinButton.h"
#include "myTextCtrl.h"

/*!
  \brief wxNumericParameter: template class that allows any numerical parameter;
     int, float, double ...
*/
template <class T>
class wxNumericParameter : public wxBoxSizer, public wxGenericWidget
//     =================
{
  T*            _parameter;
  boost::format _display_format;
  wxWindow*     _parent;
  mySlider*     _slider;
  bool          _slider_detached;
  wxSizerItem*  _slider_item;
  wxBoxSizer*   _sizer2;
  wxWindow*     _boutton;
  wxStaticText* _label;
  wxWindow*     _texte;
  MyTextCtrl*   _text;
  mySpinButton* _spinbut;
  
  // change limits of the slider
  wxBoxSizer*   _limits_sizer;
  bool          _limits_sizer_detached;
  wxSizerItem*  _limits_item;
  wxStaticText* _label_open_sqb;
  wxStaticText* _label_close_sqb;
  wxStaticText* _label_comma;
  MyTextCtrl*   _text_min;
  MyTextCtrl*   _text_max;
  
  mySpinButton* _spinbut_limits;
  
  char          val_texte[100];
  int           _mode;
  T             _min;
  T             _max;
  T             _default;
  std::string   _libelle;
  int           _decimate;
  int           _factor;

public:

  wxNumericParameter( wxWindow* parent, T* param, const char* libelle);

  void SetConstraints(const T& min, const T& max, const T& def);
  
  ~wxNumericParameter();
  
  void RecomputeTextSize();

  void SetDecimate( int d)  { 
    _decimate=d; 
    if (_text!=NULL)
      _text->SetSize(wxSize( 10*(int)log10((double)_max)+
                             10*_decimate,
                             wxDefaultCoord));
    _factor=1;
    for (int i=0; i<_decimate; i++) _factor*=10;
    }
  
  void SetDragCallback(bool dcb) {
    _slider->SetDragCallback(dcb);
  }

  static void OnSliderUpdate  (void* data);
  static void OnSpinCtrlUpdate(void* data);
  static void OnTextUpdate    (void* data);
  static void OnLimitsUpdate  (void* data);
  static void OnMinMaxUpdate  (void* data);
  
  void GetLimits(T& min, T& max) { min=_min; max=_max;}
  
//  void Show( bool show) { this->Show(show); }
  void ShowSlider( bool showslider)
  {
    this->_slider->Show(showslider);
  }
  
  void UpdateValue();
  
  void Update();

  void SetToolTip( const wxString& tt);

  void Enable(bool enable = true);

}; // wxNumericParameter

#include "wxNumericParameter.tpp"

#endif // _wxNumericParameter_h_
