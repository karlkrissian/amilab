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
#include "wxFloatParameter.h"
#include "wxIntegerParameter.h"

wxString GetwxStr(const char* str);
wxString GetwxStr(const string& str);



/**
 Useful classes
**/
#include "mySlider.h"
#include "mySpinCtrl.h"
#include "mySpinButton.h"
#include "myTextCtrl.h"

#include <boost/shared_ptr.hpp>
typedef boost::shared_ptr<std::string>     string_ptr;



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

  void EnableWidget(bool enable = true)
  {
    this->Enable(enable);
    _enabled = enable;
  }

/*
///
  void FixeCouleurFond( Pixel couleur);

  ///
  void FixeCouleurCaracteres( Pixel couleur);
*/

/*
  //
  void Button3Callback( void* callback, void* calldata) 
  //   ---------------
  {  
      _btn3callback = callback; _btn3data = calldata; 
  }
*/

//  virtual void OnLeft( wxMouseEvent& );
  virtual void OnButton( wxCommandEvent& );
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

  void EnableWidget(bool enable = true)
  {
    this->Enable(enable);
    _enabled = enable;
  }


  virtual void OnButton( wxCommandEvent& );
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

  /// sets the tooltip to all its components
  void SetToolTip( const wxString& tt);

  void EnableWidget(bool enable = true)
  {
    _wxlabel->Enable(enable);
    _wxvalue->Enable(enable);
    _enabled = enable;
  }

}; // wxLabelParameter


#endif // _WXPARAMTYPES_HPP
