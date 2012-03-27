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

#include "AMILabConfigure.h"
AMILab_VAR_IMPORT MainFrame*    GB_main_wxFrame;
#include <iostream>

#include "myDataViewCtrl.h"

///@cond wxCHECK
#if wxCHECK_VERSION(2,9,0)

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

}

void myDataViewCtrl::InternalAssociateModel( AMILabTreeModel *model )
{
  this->_amilab_model = model;
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
  EVT_DATAVIEW_ITEM_ACTIVATED( wxID_ANY, myDataViewCtrl::OnActivated )
  EVT_DATAVIEW_COLUMN_SORTED( wxID_ANY, myDataViewCtrl::OnSorted)

#if wxUSE_DRAG_AND_DROP
    EVT_DATAVIEW_ITEM_BEGIN_DRAG( wxID_ANY, myDataViewCtrl::OnBeginDrag )
    EVT_DATAVIEW_ITEM_DROP_POSSIBLE( wxID_ANY, myDataViewCtrl::OnDropPossible )
//     EVT_DATAVIEW_ITEM_DROP( wxID_ANY, myDataViewCtrl::OnDrop )
#endif       

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

#if wxUSE_DRAG_AND_DROP
void myDataViewCtrl::OnBeginDrag( wxDataViewEvent &event )
{
  wxDataViewItem item( event.GetItem() );
  wxString Text;
  wxTextDataObject *obj = new wxTextDataObject;
  AMILabTreeModelNode *node = (AMILabTreeModelNode*) item.GetID();

  // only allow drags for item, not containers
  if (node->IsContainer())
  {
      std::cout << "myDataViewCtrl::OnBeginDrag->Only allow drags for item, not containers"
                << std::endl;
      //event.Veto();
//       return;
  }
  else //It is a item node.
    std::cout << "myDataViewCtrl::OnBeginDrag->"
              << "Dnd: node type: "
              << node->m_Type
              << std::endl;

  Text = node->m_Type + "-"+ node->m_AbsoluteName;
  obj->SetText( Text );
  event.SetDataObject( obj );

  std::cout << "myDataViewCtrl::OnBeginDrag->"
            << "Dnd: Drag operation(text: "
            << node->m_AbsoluteName << ")"
            << std::endl;

}

void myDataViewCtrl::OnDropPossible( wxDataViewEvent &event )
{
  wxDataViewItem item( event.GetItem() );

  // only allow drags for item, not containers
  if (_amilab_model->IsContainer( item ) )
    std::cout << "myDataViewCtrl::OnDropPossible->only allow drops for item, not containers"
              << std::endl;

  if (event.GetDataFormat() != wxDF_UNICODETEXT)
    std::cout << "myDataViewCtrl::OnDropPossible->Error: Unsupported format"
              << std::endl;

    std::cout << "myDataViewCtrl::OnDropPossible->Begin process..."
              << std::endl;
}

// void myDataViewCtrl::OnDrop( wxDataViewEvent &event )
// {
//   wxDataViewItem item( event.GetItem() );
// 
//   // only allow drops for item, not containers
//   if (_amilab_model->IsContainer( item ) )
//   {
//     std::cout << "myDataViewCtrl::OnDrop->Only allow drops for item, not containers"
//               << std::endl;
//     return;
//   }
// 
//   if (event.GetDataFormat() != wxDF_UNICODETEXT)
//   {
//     std::cout << "MainFrame::OnDrop->Unsupported format"
//               << std::endl;
//     return;
//   }
// 
//   wxTextDataObject obj;
//   obj.SetData( wxDF_UNICODETEXT, event.GetDataSize(), event.GetDataBuffer() );
// 
//   std::cout << std::endl
//             << "MainFrame::OnDrop->Text dropped: "
//             << obj.GetText()
//             << std::endl;
// }
#endif

#endif
/// @endcond