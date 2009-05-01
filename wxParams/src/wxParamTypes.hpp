/*
    ==================================================
    Software : AMILab
    Authors  : Karl Krissian
    Email    : karl@bwh.harvard.edu

    AMILab is a language for image processing
    ==================================================
    Copyright (C) 1996-2005  Karl Krissian

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

    ================================================== 
   The full GNU Lesser General Public License file is in Devel/Sources/Prog/LesserGPL_license.txt
*/

#ifndef _WXPARAMTYPES_HPP
#define _WXPARAMTYPES_HPP



//--------------------------------------------------
// includes for wxWidgets
#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

#include "wx/progdlg.h"

#if wxUSE_SPINCTRL
    #include "wx/spinctrl.h"
#endif // wxUSE_SPINCTRL

//#include "chaine.hpp"
#include "widget.hpp"
//#include "style.hpp"

#include "StructParams.hpp"
//#include "NoyauParametre.hpp"

#include "couleur.hpp"

#include "wxEnumerationParameter.h"

wxString GetwxStr(const char* str);
wxString GetwxStr(const string& str);


/**
 Useful classes
**/
//==============================================================================
class mySlider: public wxSlider
{
  public:
     mySlider(wxWindow *parent, wxWindowID id,
        int value, int minValue, int maxValue,
        const wxPoint& pos = wxDefaultPosition,
        const wxSize& size = wxDefaultSize,
        long style = wxSL_HORIZONTAL,
        const wxValidator& validator = wxDefaultValidator,
        const wxString& name = wxSliderNameStr) :
        wxSlider(parent,id,value,minValue,maxValue,pos,size,style,validator,name)
    {
    }
    
  void SetCallback(void* cb, void* cd) { _callback=cb; _calldata=cd;}
  virtual void OnSliderUpdate( wxScrollEvent &WXUNUSED(event) )
  {
    void (*cbf)( void*) = (void (*)(void*)) this->_callback;
    cbf(this->_calldata);
  }
protected:
  void* _callback;
  void* _calldata;
private:
    DECLARE_EVENT_TABLE()
};

class mySpinCtrl: public wxSpinCtrl
{
  public:
    mySpinCtrl(wxWindow *parent,
               wxWindowID id = wxID_ANY,
               const wxString& value = wxEmptyString,
               const wxPoint& pos = wxDefaultPosition,
               const wxSize& size = wxDefaultSize,
               long style = wxSP_ARROW_KEYS,
               int min = 0, int max = 100, int initial = 0,
               const wxString& name = _T("wxSpinCtrl")):
        wxSpinCtrl(parent,id,value,pos,size,style,min,max,initial,name)
        {
        }
   
  void SetCallback(void* cb,void* cd) { _callback=cb; _calldata=cd;}
  void OnSpinCtrlUpdate( wxSpinEvent &WXUNUSED(event) )
  {
    printf("OnSpinCtrlUpdate\n");
    void (*cbf)( void*) = (void (*)(void*)) this->_callback;
    cbf(this->_calldata);
  }
  
  void OnSpinCtrlTxtUpdate( wxCommandEvent& event)
  {
    printf("OnSpinCtrlTxtUpdate\n");
    void (*cbf)( void*) = (void (*)(void*)) this->_callback;
    cbf(this->_calldata);
  }
protected:
  void* _callback;
  void* _calldata;
private:
    DECLARE_EVENT_TABLE()
};

class mySpinButton: public wxSpinButton
{
  public:
    mySpinButton(wxWindow *parent,
               wxWindowID id = wxID_ANY,
                const wxPoint& pos = wxDefaultPosition,
               const wxSize& size = wxDefaultSize,
               long style = wxSP_ARROW_KEYS,
               const wxString& name = _T("wxSpinCtrl")):
        wxSpinButton(parent,id,pos,size,style,name)
        {
        }
   
  void SetCallback(void* cb,void* cd) { _callback=cb; _calldata=cd;}
  void OnSpinCtrlUpdate( wxSpinEvent &WXUNUSED(event) )
  {
    //printf("OnSpinCtrlUpdate\n");
    void (*cbf)( void*) = (void (*)(void*)) this->_callback;
    cbf(this->_calldata);
  }
  
protected:
  void* _callback;
  void* _calldata;
private:
    DECLARE_EVENT_TABLE()
};



//----------------------------------------------------------------------------------
class MyTextCtrl : public wxTextCtrl
{
public:
    MyTextCtrl(wxWindow *parent, wxWindowID id, const wxString &value,
               const wxPoint &pos, const wxSize &size, int style = 0)  ;
 
//    void OnKeyDown(wxKeyEvent& event);
//    void OnKeyUp(wxKeyEvent& event);
//    void OnChar(wxKeyEvent& event);

//    void OnText(wxCommandEvent& event);
//    void OnTextURL(wxTextUrlEvent& event);
//    void OnTextMaxLen(wxCommandEvent& event);

//    void OnMouseEvent(wxMouseEvent& event);

//    void OnSetFocus(wxFocusEvent& event);
    void OnKillFocus(wxFocusEvent& event);

//    static bool ms_logKey;
//    static bool ms_logChar;
//    static bool ms_logMouse;
//    static bool ms_logText;
//    static bool ms_logFocus;

  void SetCallback(void* cb,void* cd) { _callback=cb; _calldata=cd;}
  void OnText(wxCommandEvent& event);
  
protected:
  void* _callback;
  void* _calldata;

private:
    static inline wxChar GetChar(bool on, wxChar c) { return on ? c : _T('-'); }
//    void LogKeyEvent(const wxChar *name, wxKeyEvent& event) const;

//    bool m_hasCapture;

    DECLARE_EVENT_TABLE()
};


//
class myButton: public wxButton
{
  public:
     myButton(wxWindow* parent, 
              wxWindowID id, 
              const wxString& label = wxEmptyString, 
              const wxPoint& pos = wxDefaultPosition, 
              const wxSize& size = wxDefaultSize, 
              long style = 0, 
              const wxValidator& validator = wxDefaultValidator, 
              const wxString& name = _T("button")) :
        wxButton(parent, id, label, pos, size, style, validator, name)
    {
    }
    
  void SetCallback(void* cb, void* cd) { _callback=cb; _calldata=cd;}
  void OnButton( wxCommandEvent &WXUNUSED(event) )
  {
    void (*cbf)( void*) = (void (*)(void*)) this->_callback;
    cbf(this->_calldata);
  }
protected:
  void* _callback;
  void* _calldata;
private:
    DECLARE_EVENT_TABLE()
};


/*!
  \brief wxBooleanParameter: GUI for a boolean parameter
*/
class wxBooleanParameter : public wxCheckBox, public wxGenericWidget
//    ==================
{
  unsigned char*	parametre;
  unsigned char	val_defaut;
  std::string   _libelle;
  type_booleen  _type;

public:

  wxBooleanParameter( wxWindow* parent, unsigned char* param,
  //----------
				 const char* libelle);

  ~wxBooleanParameter();
  //---------

  void FixeDefaut( unsigned char defaut);
  //   ----------

  void FixeAccelerateur( std::string accelerateur, std::string texte);
  //   ----------------

  void UpdateValue();
  //   --------------

  unsigned char VerifieContraintes();
  //      ------------------

  /** Cette methode permet de remettre a jour la
      valeur du parametre dans le widget
  */
  void Update();
  //   ------


  virtual void OnCheck( wxCommandEvent& );

private:
    DECLARE_EVENT_TABLE()

}; // wxBooleanParameter


//==============================================================================
/*!
  \brief wxIntegerParameter: GUI for an integer parameter
*/
class wxIntegerParameter : public wxBoxSizer, public wxGenericWidget
//     ===============
{
  int*	        _parameter;
  wxWindow*     _parent;
  mySlider*	_slider;
  wxSizerItem*  _slider_item;
  wxBoxSizer*   _sizer2;
  wxWindow*	_boutton;
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
  char	        val_texte[100];
  int           _mode;
  int	        _min;
  int	        _max;
  int	        _default;
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

  }; // wxIntegerParameter

//==============================================================================
/*!
  \brief wxFloatParameter: GUI for a float parameter
*/
class wxFloatParameter : public wxBoxSizer, public wxGenericWidget
//     ===============
{
  float*	_parameter;
  wxWindow*     _parent;
  mySlider*	_slider;
  wxSizerItem*  _slider_item;
  wxBoxSizer*   _sizer2;
  wxWindow*	_boutton;
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
  
  char	        val_texte[100];
  int           _mode;
  float	        _min;
  float	        _max;
  float	        _default;
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

}; // wxFloatParameter

#define wxID_MenuItem 10

//==============================================================================
class myMenuItem : public wxMenuItem
{

  public:
  
  myMenuItem( wxMenu* parent, int id, const wxString& label, const wxString& helpString = _T("")) :
  wxMenuItem(parent, id, label, helpString , wxITEM_CHECK, NULL) 
  {}
  
  ~myMenuItem() {}

  void OnItemUpdate(wxCommandEvent &WXUNUSED(event)) 
  {
    printf("Event on myMenuItem \n");
  }

//private:
//    DECLARE_EVENT_TABLE()

};

//==============================================================================
/*!
  \brief wxMenuEnum: Enumeration in the menu
*/
class wxMenuEnum: public wxMenu
{
  int*          _parameter;
  int           _id_array[20];
  int           _array_size;

  public:
  
  wxMenuEnum( wxMenu* parent, int* param, const char* label);
  
  ~wxMenuEnum();
  
  void AddChoice( int id, const wxString&  item, const wxString& helpString = _T(""));
  
  void SetSelectionParameter();
  void SetSelection(int id);
  
  void Update();

  unsigned char ValueChanged(wxCommandEvent& );

  void OnEnumUpdate(wxCommandEvent &WXUNUSED(event));

//private:
//    DECLARE_EVENT_TABLE()

};


//==============================================================================
/*!
  \brief wxStringParameter: GUI for a string
*/
class wxStringParameter : public wxBoxSizer, public wxGenericWidget
{
  std::string*         _parameter;
  wxWindow*     _parent;
  wxStaticText* _label;
  MyTextCtrl*   _text;
  
  std::string   _label_name;
  std::string   _label_value;
  int           _type;
  
  public:
  
  wxStringParameter( wxWindow* parent, std::string* value, const char* label);
  
  ~wxStringParameter() {}
    
  ///
  void SetValue( char* value) { *_parameter = value; } 
  
  static void OnStringUpdate(void* data);

  // updating displayed value
  void Update();
  //   ------

}; // wxStringParameter


//==============================================================================
//==============================================================================
/*!
  \brief wxFilenameParameter: GUI for a filename
*/
class wxFilenameParameter : public wxBoxSizer, public wxGenericWidget
{
  std::string*         _parameter;
  wxWindow*     _parent;
  wxStaticText* _label;
  MyTextCtrl*   _text;
  myButton*     _button;
  
  std::string    _label_name;
  std::string        _label_value;
  int           _type;
  
  wxString      _default_path;
  wxString      _default_filename;
  wxString      _default_extension;
  wxString      _wildcard;

  public:
  
  wxFilenameParameter( wxWindow* parent, std::string* value, const char* label,  type_label type=LabelLabel );
  
  ~wxFilenameParameter() {}
  
  static void BrowseFile( void* data);
  
  void SetDefaultPath(    const char* path) 
  { 
    _default_path = wxString::FromAscii(path);
  }

  void SetDefaultExtension(const char* ext)  
  {
    _default_extension=wxString::FromAscii(ext);
  }
  void SetWildcard(        const char* w)    
  {
    _wildcard=wxString::FromAscii(w);
  }
  
  static void OnStringUpdate(void* data);
  
  ///
  void SetValue( char* value) { *_parameter = value; } 

}; // wxFilenameParameter

//============================================================================
//============================================================================
///
/*!
  \brief wxButtonParameter: GUI for a button
*/
class wxButtonParameter : public wxButton, public wxGenericWidget
//     ================
{

protected:

  wxWindow*      _wx_parent;

  ///
  std::string         _libelle;
  ///
  button_type    _type;

  ///
  void*      _btn3callback;
  ///
  void*      _btn3data;

public:

/*
  ///
   wxButtonParameter( wxWindow* parent, char* libelle, 
  //----------
				 XtCallbackProc callback, void* data,
				 button_type type=TextButton);
*/
  ///
  wxButtonParameter( wxWindow* parent, const char* libelle, 
  //----------
				 void* callback, void* data,
				 button_type type=TextButton);

  ///
  ~wxButtonParameter();
  //   ---------


  ///
  void CreateParameter();
  //   ---------------

  ///
  void ChangeLibelle( const char* libelle);
  //   -------------

/*
///
  void FixeCouleurFond( Pixel couleur);

  ///
  void FixeCouleurCaracteres( Pixel couleur);
*/

  //
  void Button3Callback( void* callback, void* calldata) 
  //   ---------------
  {  
      _btn3callback = callback; _btn3data = calldata; 
  }


//  virtual void OnLeft( wxMouseEvent& );
  virtual void OnLeftDown( wxMouseEvent& );
  void OnRightDown(wxMouseEvent& );

private:
    DECLARE_EVENT_TABLE()

}; // wxButtonParameter



///
/*!
  \brief wxBitmapButtonParameter: GUI for a bitmap button
*/

class wxBitmapButtonParameter : public wxBitmapButton, public wxGenericWidget
//     ================
{

protected:

  wxWindow*      _wx_parent;

  ///
  std::string         _libelle;
  ///
  button_type    _type;

  ///
  void*      _btn3callback;
  ///
  void*      _btn3data;

public:



/*
  ///
   wxBitmapButtonParameter( wxWindow* parent, char* libelle, 
  //----------
				 const wxBitmap& bm,
				 XtCallbackProc callback, void* data,
				 button_type type=TextButton);
*/

   wxBitmapButtonParameter( wxWindow* parent, const char* libelle, 
  //----------
				 const wxBitmap& bm,
				 void* callback, void* data,
				 button_type type=TextButton);

  ///
  ~wxBitmapButtonParameter();
  //   ---------


  ///
  void CreateParameter();
  //   ---------------

  ///
  void ChangeLibelle( const char* libelle);
  //   -------------

/*
///
  void FixeCouleurFond( Pixel couleur);

  ///
  void FixeCouleurCaracteres( Pixel couleur);
*/
  //
  void Button3Callback( void* callback, void* calldata) 
  //   ---------------
  {  
      _btn3callback = callback; _btn3data = calldata; 
  }



  virtual void OnLeftDown( wxMouseEvent& );
  void OnRightDown(wxMouseEvent& );

private:
    DECLARE_EVENT_TABLE()

}; // wxBitmapButtonParameter

//============================================================================
/*!
  \brief wxLabelParameter: GUI for a label
*/
class wxLabelParameter: public wxBoxSizer, public wxGenericWidget
{
  wxWindow*     _parent;
  wxStaticText* _wxlabel;
  wxTextCtrl*   _wxvalue;
  
  std::string        _label_name;
  std::string        _label_value;
  int           _type;

  public:
  
  wxLabelParameter( wxWindow* parent, const char* label, const char* value, type_label type=LabelLabel );
  
  ~wxLabelParameter();
  
  ///
  void SetValue( const char* value);

}; // wxLabelParameter


#endif // _WXPARAMTYPES_HPP
