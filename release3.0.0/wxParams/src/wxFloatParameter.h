//
// C++ Interface: wxFloatParameter
//
// Description: 
//
//
// Author: Karl Krissian <krissian@dis.ulpgc.es>, (C) 2009
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _wxFloatParameter_h_
#define _wxFloatParameter_h_

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


//================================================================
/*!
  \brief wxFloatParameter: GUI for a float parameter
*/
class wxFloatParameter : public wxBoxSizer, public wxGenericWidget
//     ===============
{
  float*  _parameter;
  wxWindow*     _parent;
  mySlider* _slider;
  wxSizerItem*  _slider_item;
  wxBoxSizer*   _sizer2;
  wxWindow* _boutton;
  wxStaticText* _label;
  wxWindow*     _texte;
  MyTextCtrl*   _text;
  mySpinButton* _spinbut;
  
  // change limits of the slider
  wxBoxSizer*   _limits_sizer;
  wxSizerItem*  _limits_item;
  wxStaticText* _label_min;
  MyTextCtrl*   _text_min;
  wxStaticText* _label_max;
  MyTextCtrl*   _text_max;
  
  mySpinButton* _spinbut_limits;
  
  char          val_texte[100];
  int           _mode;
  float         _min;
  float         _max;
  float         _default;
  std::string   _libelle;
  int           _decimate;
  int           _factor;

public:

  wxFloatParameter( wxWindow* parent, float* param, const char* libelle);

  void SetConstraints( float min, float max, float def);
  
  ~wxFloatParameter();
  
  void SetDecimate( int d)  { 
    _decimate=d; 
    _factor=1;
    for (int i=0; i<_decimate; i++) _factor*=10;
    }
  
  static void OnSliderUpdate  (void* data);
  static void OnSpinCtrlUpdate(void* data);
  static void OnTextUpdate    (void* data);
  static void OnLimitsUpdate  (void* data);
  static void OnMinMaxUpdate  (void* data);
  
  void GetLimits(float& min, float& max) { min=_min; max=_max;}
  
//  void Show( bool show) { this->Show(show); }
  void ShowSlider( bool showslider)
  {
    this->_slider->Show(showslider);
  }
  
  void UpdateValue();
  
  void Update();

  void SetToolTip( const wxString& tt);

}; // wxFloatParameter



#endif // ifndef _wxFloatParameter_h_
