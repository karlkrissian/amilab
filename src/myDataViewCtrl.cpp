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
//   Connect(wxEVT_COMMAND_DATAVIEW_ITEM_BEGIN_DRAG,
//           wxKeyEventHandler(myDataViewCtrl::OnBeginDrag),
//           NULL, this);
//           Connect(wxEVT_COMMAND_TREE_BEGIN_DRAG,wxTreeEventHandler(myTreeCtrl::OnBeginDrag));
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
    BasicVariable::ptr var = this->_amilab_model->GetVar(item).lock();
    _currentmenu_var = var;

    if (var.get()) {
      std::string com = var->GetComments();
      if (com.compare("")!=0) {
        wxString comments(com.c_str(), wxConvUTF8);
        menu.Append(wxID_ANY, comments);
      }
    }

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
  std::string mess;
  BasicVariable::ptr var = _currentmenu_var.lock();
  if (var.get()) {
    switch (var->Type()) {
      case type_c_procedure     :
        {
        DYNAMIC_CAST_VARIABLE(C_wrap_procedure, var, varproc);
        (*varproc->Pointer())(NULL);
        return;
        }

      case type_class_member     :
        {
        // getting the associated help
        DYNAMIC_CAST_VARIABLE(WrapClassMember, var, mem);
        mem->Pointer()->ShowHelp();
        return;
        }

      case type_c_image_function:
        {
        DYNAMIC_CAST_VARIABLE(C_wrap_imagefunction, var, func);
        (*func->Pointer())(NULL);
        return;
        }
      case type_c_function:
        {
        DYNAMIC_CAST_VARIABLE(C_wrap_varfunction, var, func);
        (*func->Pointer())(NULL);
        return;
        }
      default:
        mess = var->GetComments();
    }
  } else {
    mess = "No variable for this item";
  }
  wxMessageDialog msg(NULL,wxString::FromAscii(mess.c_str()),
      wxString::FromAscii("Help"),wxOK | wxICON_INFORMATION );
  msg.ShowModal();
}

void myDataViewCtrl::ToConsole( wxCommandEvent& event )
{
  BasicVariable::ptr var(_currentmenu_var.lock());
  GB_main_wxFrame->GetConsole()->IncCommand(var->Name());  
}


void myDataViewCtrl::OnBeginDrag( wxDataViewEvent &event )
{
  wxDataViewItem item( event.GetItem() );

//  wxDataViewItem *node1 = (wxDataViewItem*) item.GetID();

  // only allow drags for item, not containers
  if (_amilab_model->IsContainer( item ) )
  {
      std::cout << "myDataViewCtrl::OnBeginDrag - Only allow drags for item, not containers"
                << std::endl;
      event.Veto();
      return;
  }

  AMILabTreeModelNode *node = (AMILabTreeModelNode*) item.GetID();
  wxTextDataObject *obj = new wxTextDataObject;
  obj->SetText( node->m_Name );
  event.SetDataObject( obj );

  std::cout << "myDataViewCtrl::OnBeginDrag - Drag text: "
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
  
  GB_main_wxFrame->GetConsole()->IncCommand(obj.GetText());

  std::cout << std::endl
            << "myDataViewCtrl::OnDrop - Text dropped: "
            << obj.GetText()
            << std::endl;
}
