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
//
//
//

#include "MyToolBar.h"
#include <iostream>
#include <wx/msgdlg.h>
//extern std::ostream  out;
#include <wx/event.h>
#include <wx/bmpcbox.h>

using namespace std;


class myBitmapComboBox: public wxBitmapComboBox
{
private:

  void*        rc_callback;
  void*        rc_calldata;
  wxString     rc_help;

public:
    myBitmapComboBox(wxWindow* parent, wxWindowID id, 
      const wxString& value = _T(""), 
      const wxPoint& pos = wxDefaultPosition, 
      const wxSize& size = wxDefaultSize, 
      int n = 0, const wxString choices[] = NULL, 
      long style = 0, 
      const wxValidator& validator = wxDefaultValidator, 
      const wxString& name = _T("comboBox")):
    wxBitmapComboBox(parent,id,value,pos,size,n,choices,style,validator,name)
  {
    rc_callback = NULL;
    rc_calldata = NULL;
    rc_help = _T("");
  }

  void add_right_click( void* cb, void* cd, const wxString& h)
  {
    rc_callback = cb;
    rc_calldata = cd;
    rc_help = h;
  }

  void OnRightDown(wxMouseEvent& )
  {
    if (rc_callback!=NULL) {
      void (*pf)( void*) = (void (*)(void*)) this->rc_callback;
      pf( this->rc_calldata);
    }
  }

  void OnMiddleDown(wxMouseEvent& )
  {
    this->Select((this->GetSelection()+1) % this->GetCount() );
    // through selection event
    wxCommandEvent event( wxEVT_COMMAND_COMBOBOX_SELECTED,
                          this->GetId() );
    event.SetEventObject( this );
    // Send it
    GetEventHandler()->ProcessEvent( event );

  }


private:

 DECLARE_EVENT_TABLE()

};

BEGIN_EVENT_TABLE(myBitmapComboBox, wxBitmapComboBox)
  EVT_RIGHT_DOWN( myBitmapComboBox::OnRightDown)
  EVT_MIDDLE_DOWN(myBitmapComboBox::OnMiddleDown)
END_EVENT_TABLE()



//------------------------------------------------------------------------------
void MyToolBarBase::UpdateTool(int enum_id)
{

//#ifndef WIN32

  //out << "MyToolBar::Update begin" << endl;

/*
  if (this->GetParent()->IsShown())
    wxMessageBox(_T("Parent is shown\n"));
  else
    wxMessageBox(_T("Parent is not shown \n"));
*/

  if (enum_id<0) enum_id = 0;
  if (enum_id>=enum_info.size()) enum_id = enum_info.size()-1;

  toolbar_enum_info_base* info = enum_info[enum_id];

  // find current position
  int current_pos = info->CurrentPosition();
  if (current_pos==-1) current_pos = 0;

  if (current_pos == info->displayed_tool) return;

  info->combo->Select(current_pos);
  info->displayed_tool = current_pos;

}

//------------------------------------------------------------------------------
void MyToolBarBase::AddRightClick(  int enum_id,
                                void* rc_callback,
                                void* rc_calldata,
                                const wxString& rc_help)
{

  //out << "MyToolBar::AddRightClick begin" << endl;

  ((myBitmapComboBox*) (enum_info[enum_id]->combo))
    ->add_right_click(rc_callback,rc_calldata,rc_help);


  //out << "MyToolBar::AddRightClick end" << endl;
}

//------------------------------------------------------------------------------
void MyToolBarBase::OnEnumPressed( wxCommandEvent& event)
{
  // Button pressed: locate the corresponding tool
  //wxMessageBox(_T("MyToolBar::OnEnumPressed\n"));

  vector<toolbar_enum_info_base*>::iterator Iter;
  int id=0;
  for (Iter  = enum_info.begin();
       Iter != enum_info.end()  ; Iter++,id++ )
  {
    if ((*Iter)->combo->GetId()==event.GetId())
    {
      (*Iter)->SetParam((*Iter)->combo->GetSelection());
      this->UpdateTool(id);
      if ((*Iter)->callback!=NULL) {
        void (*pf)( void*) = (void (*)(void*)) (*Iter)->callback;
        pf( (*Iter)->calldata);
      }
    }
  }

}


//----------------------------------------------------------
wxBitmapComboBox* MyToolBarBase::GetCombo( int enum_id)
{
  return enum_info[enum_id]->combo;
}


//--------------------------------------------------------------------------------
void MyToolBar::AddEnumChoice(int enum_id, 
    int combo_id, 
    int value, 
    const wxBitmap& bitmap, 
    const wxString& text)
{
  //out << "MyToolBar::AddEnumChoice begin" << endl;

  // first create the combo is needed
  if (enum_info[enum_id]->combo==NULL) {
    myBitmapComboBox *combo = new myBitmapComboBox(
        (wxToolBar*)this,
        combo_id, 
        enum_info[enum_id]->label, 
        wxDefaultPosition, 
        wxSize(55,-1) ,0,NULL, 
        wxCB_READONLY  );
    enum_info[enum_id]->combo=combo;
    // Connect event
    wxToolBar::Connect(combo_id,wxEVT_COMMAND_COMBOBOX_SELECTED,
                 wxCommandEventHandler(MyToolBar::OnEnumPressed));
    combo->SetToolTip(enum_info[enum_id]->shortHelpString);
    this->AddControl(combo);
  }

  enum_info[enum_id]->combo->Append(text,bitmap);

  // add it to the list
  enum_info[enum_id]->values.push_back(value);

  int xsize = enum_info[enum_id]->combo->GetBitmapSize().GetWidth();
  int ysize = enum_info[enum_id]->combo->GetBitmapSize().GetWidth();
  enum_info[enum_id]->combo->SetSize(xsize+25,ysize+4);

  //out << "MyToolBar::AddEnumChoice end" << endl;
}


//--------------------------------------------------------------------------------
void MyAuiToolBar::AddEnumChoice(int enum_id, 
    int combo_id, 
    int value, 
    const wxBitmap& bitmap, 
    const wxString& text)
{

  // first create the combo is needed
  if (enum_info[enum_id]->combo==NULL) {
    myBitmapComboBox *combo = new myBitmapComboBox(
        (wxAuiToolBar*)this,
        combo_id, 
        enum_info[enum_id]->label, 
        wxDefaultPosition, 
        wxSize(55,-1) ,0,NULL, 
        wxCB_READONLY  );
    enum_info[enum_id]->combo=combo;
    // Connect event
    wxAuiToolBar::Connect(combo_id,wxEVT_COMMAND_COMBOBOX_SELECTED,
                 wxCommandEventHandler(MyAuiToolBar::OnEnumPressed));
    combo->SetToolTip(enum_info[enum_id]->shortHelpString);
    this->AddControl(combo);
  }

  enum_info[enum_id]->combo->Append(text,bitmap);
  // add it to the list
  enum_info[enum_id]->values.push_back(value);

  int xsize = enum_info[enum_id]->combo->GetBitmapSize().GetWidth();
  int ysize = enum_info[enum_id]->combo->GetBitmapSize().GetWidth();
  enum_info[enum_id]->combo->SetSize(xsize+25,ysize+4);
  //cout << "size = " << xsize << endl;
  //out << "MyToolBar::AddEnumChoice end" << endl;
}
