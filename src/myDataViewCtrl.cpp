//
// C++ Interface: MyDataViewCtrl
//
// Description: wxDataViewCtrl wxWidgets custom implementation.
//
//
// Author:  <Karl Krissian>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//
#include "Variable.hpp"
#include "paramlist.h"
#include "wrapfunction_class.h"

//icons
#include "wx/artprov.h"

#include "MainFrame.h"
extern MainFrame*    GB_main_wxFrame;
#include <iostream>

#include "myDataViewCtrl.h"

//Pop menu: two options ("Write in console" and "About..")
enum
{
  wxMENU_ID_myABOUT = 1000,
  wxMENU_ID_ToConsole
};

myDataViewCtrl::myDataViewCtrl( wxWindow* parent, wxWindowID id,
  const wxPoint& pos, const wxSize& size, long style,
  const wxValidator& validator):wxDataViewCtrl(parent, id, pos, size, style, validator)
{
  // CONSTRUCTOR DEFINITION.
  Connect(wxEVT_CHAR,
          wxKeyEventHandler(myDataViewCtrl::OnDataViewChar),
          NULL, this);
}

void myDataViewCtrl::InternalAssociateModel( AMILabTreeModel *model )
{
  this->_amilab_model = model;
}

void myDataViewCtrl::OnDataViewChar(wxKeyEvent& event)
{
//     if ( event.GetKeyCode() == WXK_DELETE )
//         //DeleteSelectedItems();
//     else
        event.Skip();
}


void myDataViewCtrl::_ShowMenu(const wxDataViewItem &item, const wxPoint& pt)
{
  if ( item.IsOk() )
  {
    wxMenu menu(_amilab_model->GetName(item));
//     BasicVariable::ptr var = m_amilab_model->GetVar(id).lock();
//     _currentmenu_var = var;
// 
//     if (var.get()) {
//       std::string com = var->GetComments();
//       if (com.compare("")!=0) {
//         wxString comments(com.c_str(), wxConvUTF8);
//         menu.Append(wxID_ANY, comments);
//       }
//     }

    // Write in console menu
    wxMenuItem* item1 = new wxMenuItem(&menu,wxMENU_ID_ToConsole,wxT("Write in console"),
      wxT("write name in the console"));
    wxBitmap bitmap1 = wxArtProvider::GetBitmap(wxART_PASTE, wxART_OTHER, wxDefaultSize);
    if (bitmap1.Ok()) item1->SetBitmap(bitmap1);
    menu.Append(item1 );

    //Put a book icon in the &About item
    wxMenuItem* item2 = new wxMenuItem(&menu,wxMENU_ID_myABOUT,wxT("&About..."),
      wxT("more information about this variable"));
    wxBitmap bitmap2 = wxArtProvider::GetBitmap(wxART_HELP_BOOK, wxART_OTHER, wxDefaultSize);
    if (bitmap2.Ok())
      item2->SetBitmap(bitmap2);
    menu.Append(item2 );
    PopupMenu(&menu, pt);
  }
  else
  {
    wxMenu menu(wxT("No particular item"));
    PopupMenu(&menu, pt);
  }

}

BEGIN_EVENT_TABLE(myDataViewCtrl, wxDataViewCtrl)
  EVT_MENU(wxMENU_ID_myABOUT,   myDataViewCtrl::OnAbout)
  EVT_MENU(wxMENU_ID_ToConsole, myDataViewCtrl::ToConsole)

  EVT_DATAVIEW_ITEM_CONTEXT_MENU(wxID_ANY, myDataViewCtrl::OnContextMenu)
  EVT_DATAVIEW_ITEM_BEGIN_DRAG( wxID_ANY, myDataViewCtrl::OnBeginDrag )
  EVT_DATAVIEW_ITEM_DROP_POSSIBLE( wxID_ANY, myDataViewCtrl::OnDropPossible )
  EVT_DATAVIEW_ITEM_DROP( wxID_ANY, myDataViewCtrl::OnDrop )

END_EVENT_TABLE()

void myDataViewCtrl::OnContextMenu( wxDataViewEvent &event )
{
  wxDataViewItem item( event.GetItem() );

  if (_amilab_model->IsContainer( item ) )
  {
      event.Veto();
      return;
  }
  
  wxPoint clientpt = event.GetPosition();
  wxPoint screenpt = ClientToScreen(clientpt);

  _ShowMenu(item, clientpt);
  event.Skip();
}

void myDataViewCtrl::OnAbout( wxCommandEvent& event )
{
  
}

void myDataViewCtrl::ToConsole( wxCommandEvent& event )
{
  
}


void myDataViewCtrl::OnBeginDrag( wxDataViewEvent &event )
{
  wxDataViewItem item( event.GetItem() );

  wxDataViewItem *node1 = (wxDataViewItem*) item.GetID();

  // only allow drags for item, not containers
  if (_amilab_model->IsContainer( item ) )
  {
      event.Veto();
      return;
  }

  AMILabTreeModelNode *node = (AMILabTreeModelNode*) item.GetID();
  wxTextDataObject *obj = new wxTextDataObject;
  obj->SetText( node->m_Name );
  event.SetDataObject( obj );

  std::cout << std::endl
          << "myDataViewCtrl::OnBeginDrag - Drag text: "
          << node->m_Name
          << std::endl;
}

void myDataViewCtrl::OnDropPossible( wxDataViewEvent &event )
{
  wxDataViewItem item( event.GetItem() );

  // only allow drags for item, not containers
  if (_amilab_model->IsContainer( item ) )
      event.Veto();

  if (event.GetDataFormat() != wxDF_UNICODETEXT)
      event.Veto();

}

void myDataViewCtrl::OnDrop( wxDataViewEvent &event )
{
  wxDataViewItem item( event.GetItem() );

  // only allow drops for item, not containers
  if (_amilab_model->IsContainer( item ) )
  {
      event.Veto();
      return;
  }

  if (event.GetDataFormat() != wxDF_UNICODETEXT)
  {
      event.Veto();
      return;
  }

  wxTextDataObject obj;
  obj.SetData( wxDF_UNICODETEXT, event.GetDataSize(), event.GetDataBuffer() );

  std::cout << std::endl
            << "myDataViewCtrl::OnDrop - Text dropped: "
            << obj.GetText()
            << std::endl;
}
