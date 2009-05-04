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
//
//  Karl Krissian
//  Las Palmas 
//

// This class ends up being much more complex than expected,
// the parameter for the enumeration can be of any integer type
// and we use a template class to store it
// this force the array of information of the enumerations to 
// be an array of pointers to the non-template base class

#ifndef _MYTOOLBAR_H
#define _MYTOOLBAR_H

#include <wx/toolbar.h>
#include <wx/tbarbase.h>
#include <wx/bmpcbox.h>
#include <wx/msgdlg.h>

#include <vector>
using namespace std;

class toolbar_enum_info_base {
public:
  wxBitmapComboBox * combo;
  int          displayed_tool;
  wxString     label;
  wxString     shortHelpString;
  vector<int>  values;
//  vector<wxToolBarToolBase*>  tools;
  void*        callback;
  void*        calldata;


  toolbar_enum_info_base( const wxString& l, const wxString& h,
                    void* cb, void* cd)
  {
    combo = NULL;
    label = l;
    shortHelpString = h;
    displayed_tool = -1; // no tool displayed yet
    callback = cb;
    calldata = cd;
  }

  virtual void SetParam( int val) = 0;
  virtual void IncParam() = 0;
  virtual int CurrentPosition() = 0;
};

template <class T>
class toolbar_enum_info : public  toolbar_enum_info_base {
public:
  T*         param;

  toolbar_enum_info(T* p, const wxString& l, const wxString& h,
                    void* cb, void* cd) :
    toolbar_enum_info_base(l,h,cb,cd)
  {
    param=p;
  }

  void IncParam()
  {
    *param = (*param+1)%combo->GetCount();
  }

  void SetParam( int val)
  {
    *param = val;
  }

  int CurrentPosition() {
    // find current position
    vector<int>::iterator Iter;
    int current_pos = 0;
    for (Iter  = values.begin(); 
       Iter != values.end()  ; Iter++,current_pos++ )
      if (*Iter==(int)(*param)) return current_pos;
    return -1;
  }

};

//======================================================================
class MyToolBar : public wxToolBar
//
{

  vector<toolbar_enum_info_base*> enum_info;

 public:

  ///
  MyToolBar(  wxWindow* parent, 
              wxWindowID id, 
              const wxPoint& pos = wxDefaultPosition,
              const wxSize& size = wxDefaultSize, 
              long style = wxTB_HORIZONTAL 
                        | wxNO_BORDER,
              const wxString& name = wxPanelNameStr) :
    wxToolBar(parent,id,pos,size,style,name)
  {
  }

  ~MyToolBar() {
    // free memory of toolbar_enum_info_base
    vector<toolbar_enum_info_base*>::iterator Iter;
    for (Iter  = enum_info.begin(); 
       Iter != enum_info.end()  ; Iter++ )
    {
      delete *Iter;
    }
  }

  template <class T>
  int AddEnum(  T* variable,
                const wxString& label, 
                const wxString& shortHelpString = "",
                void* callback = NULL,
                void* calldata = NULL)
  {
    enum_info.push_back(new toolbar_enum_info<T>(variable,label,shortHelpString,callback,calldata));
    return enum_info.size()-1;
  }

  void AddRightClick( int enum_id,
                      void* rc_callback,
                      void* rc_calldata = NULL,
                      const wxString& rc_help = _T(""));

  void AddEnumChoice( int enum_id, 
                      int choice_id, 
                      int value,
                      const wxBitmap& bitmap,
                      const wxString& text= _T(""));

  void Update( int enum_id);

  wxBitmapComboBox* GetCombo( int enum_id);

  void OnEnumPressed(    wxCommandEvent&);


private:

};
 // MyToolBar


#endif // _MYTOOLBAR_H

