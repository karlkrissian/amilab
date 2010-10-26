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

#include "wxDragAndDrop.h"

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
//   Connect(wxEVT_CHAR,
//           wxKeyEventHandler(myDataViewCtrl::OnDataViewChar),
//           NULL, this);
//   Connect(wxEVT_COMMAND_DATAVIEW_ITEM_BEGIN_DRAG,
//           wxDataViewEventHandler(myDataViewCtrl::OnBeginDrag),
//           NULL, this);
//   Connect(wxEVT_COMMAND_DATAVIEW_ITEM_DROP_POSSIBLE,
//           wxDataViewEventHandler(myDataViewCtrl::OnDropPossible),
//           NULL, this);
//   Connect(wxEVT_COMMAND_DATAVIEW_ITEM_DROP,
//           wxDataViewEventHandler(myDataViewCtrl::OnDrop),
//           NULL, this);
}

void myDataViewCtrl::InternalAssociateModel( AMILabTreeModel *model )
{
  this->_amilab_model = model;
}

// void myDataViewCtrl::OnDataViewChar(wxKeyEvent& event)
// {
// //     if ( event.GetKeyCode() == WXK_DELETE )
// //         //DeleteSelectedItems();
// //     else
//         event.Skip();
// }


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
  EVT_DATAVIEW_ITEM_ACTIVATED( wxID_ANY, myDataViewCtrl::OnActivated )
  EVT_DATAVIEW_COLUMN_SORTED( wxID_ANY, myDataViewCtrl::OnSorted)
//   EVT_DATAVIEW_ITEM_DROP_POSSIBLE( wxID_ANY, myDataViewCtrl::OnDropPossible )
//   EVT_DATAVIEW_ITEM_DROP( wxID_ANY, myDataViewCtrl::OnDrop )

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

  AMILabTreeModelNode *node = (AMILabTreeModelNode*) item.GetID();
  boost::shared_ptr<BasicVariable> variable = node->m_Var.lock();
  MyNode mynode;
  if (variable.get())  
  {
    mynode.SetAbsoluteName( node->m_AbsoluteName );
    mynode.SetVar( variable );
  }
  MyNodeDataObject obj;
  obj.SetNode( mynode );
//   MyNodeDataObject *obj =new MyNodeDataObject();
//   obj->SetNode( mynode );
//   event.SetDataObject( obj );
  
  wxDropSource dragSource(obj, this ); //Create data source
  //dragSource.SetData( obj );  //Assign the data
  wxDragResult result = dragSource.DoDragDrop( TRUE ); //Begin the drag operation.

  switch (result)
  {
      case wxDragCopy:
        // copy the data
        std::cout << "DnD result: the data was successfully copied" << std::endl;
        break;
      case wxDragMove:
        // move the data
        std::cout << "DnD result: the data was successfully moved" << std::endl;
        break;
      case wxDragError:
        // Error
        std::cout << "DnD result: Error" << std::endl;
        break;
      case wxDragNone:
        // target didn't accept the data
        std::cout << "DnD result: target didn't accept the data" << std::endl;
        break;
      case wxDragCancel:
        // the operation was cancelled by user
        std::cout << "DnD result: the operation was cancelled by user" << std::endl;
        break;
      case wxDragLink:
        // operation is a drag-link
        std::cout << "DnD result: this was a link operation" << std::endl;
        break;
      default:
        // do nothing
        std::cout << "DnD result: do nothing" << std::endl;
        break;
  }

  //wxTextDataObject *obj = new wxTextDataObject;
//   MyNodeDataObject * obj =  new MyNodeDataObject();
//   boost::shared_ptr<BasicVariable> variable = node->m_Var.lock();
//   MyNode mynode;
//   if (variable.get())
//   {
//     mynode.SetAbsoluteName( node->m_AbsoluteName );
//     mynode.SetVar( variable );
// //     obj->SetText( node->m_AbsoluteName );
//   }
// //   else
// //     obj->SetText( "" );
//   //MyNodeDataObject * obj =  new MyNodeDataObject(mynode);
//   obj->SetNode( mynode );
//   event.SetDataObject( obj );
}

void myDataViewCtrl::OnActivated( wxDataViewEvent &event )
{
  if(!IsExpanded( event.GetItem() ))
    Expand( event.GetItem() );
  else
    Collapse( event.GetItem() );
}

void myDataViewCtrl::OnSorted( wxDataViewEvent &event )
{
  GetColumnPosition( event.GetDataViewColumn() );
}

/*
void myDataViewCtrl::OnDropPossible( wxDataViewEvent &event )
{
  wxDataViewItem item( event.GetItem() );

  // only allow drags for item, not containers
  if (_amilab_model->IsContainer( item ) )
    std::cout << "myDataViewCtrl::OnDropPossible: only allow drops for item, not containers"
              << std::endl;

  if (event.GetDataFormat() != wxDF_UNICODETEXT)
    std::cout << "myDataViewCtrl::OnDropPossible: Unsupported format"
              << std::endl;

    std::cout << "myDataViewCtrl::OnDropPossible: Begin process..."
              << std::endl;
}

void myDataViewCtrl::OnDrop( wxDataViewEvent &event )
{
  wxDataViewItem item( event.GetItem() );

  // only allow drops for item, not containers
  if (_amilab_model->IsContainer( item ) )
  {
    std::cout << "myDataViewCtrl::OnDrop: only allow drops for item, not containers"
              << std::endl;
    return;
  }

  if (event.GetDataFormat() != wxDF_UNICODETEXT)
  {
    std::cout << "myDataViewCtrl::OnDrop: Unsupported format"
              << std::endl;
    return;
  }

  wxTextDataObject obj;
  obj.SetData( wxDF_UNICODETEXT, event.GetDataSize(), event.GetDataBuffer() );
  GB_main_wxFrame->GetConsole()->IncCommand(obj.GetText());

  std::cout << "myDataViewCtrl::OnDrop - Text dropped: "
            << obj.GetText()
            << std::endl;
}
*/