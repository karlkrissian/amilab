//
// C++ Interface: wxIntegerParameter
//
// Description: 
//
//
// Author: Karl Krissian <krissian@dis.ulpgc.es>, (C) 2009
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _wxIntegerParameter_h_
#define _wxIntegerParameter_h_

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

//===============================================================
/*!
  \brief wxIntegerParameter: GUI for an integer parameter
*/
class wxIntegerParameter : public wxBoxSizer, public wxGenericWidget
//     ===============
{
  int*          _parameter;
  wxWindow*     _parent;
  mySlider* _slider;
  wxSizerItem*  _slider_item;
  wxBoxSizer*   _sizer2;
  wxWindow* _boutton;
  wxStaticText* _label;
  MyTextCtrl*   _text;
  mySpinButton* _spinbut;
  
  wxBoxSizer*   _limits_sizer;
  wxSizerItem*  _limits_item;
  wxStaticText* _label_min;
  MyTextCtrl*   _text_min;
  wxStaticText* _label_max;
  MyTextCtrl*   _text_max;
  
  mySpinButton* _spinbut_limits;
  char          val_texte[100];
  int           _mode;
  int         _min;
  int         _max;
  int         _default;
  std::string _libelle;

public:

  wxIntegerParameter( wxWindow* parent, int* param, const char* libelle);

  void SetConstraints(int min, int max, int def);
  
  ~wxIntegerParameter();
  
  static void OnSliderUpdate( void* data);
  
  static void OnSpinCtrlUpdate(void* data);
  
  static void OnTextUpdate(void* data);
  
  static void OnLimitsUpdate(void* data);
  
  static void OnMinMaxUpdate(void* data);
  
  void GetLimits(int& min,int& max) { min=_min; max=_max;}
  
  void ShowSlider( bool showslider)
  {
    this->_slider->Show(showslider);
  }

//  void Show( bool show) { this->Show(show); }
  
  void UpdateValue();
  
  void Update();

  void SetToolTip( const wxString& tt);

}; // wxIntegerParameter



#endif //  _wxIntegerParameter_h_
