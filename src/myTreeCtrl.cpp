//
// C++ Implementation: myTreeCtrl
//
// Description: 
//
//
// Author:  <Karl Krissian>, (C) 2009
//
// Copyright: See COPYING file that comes with this distribution
//
//

#include "myTreeCtrl.h"
#include "Variable.hpp"
#include "paramlist.h"
#include "wrapfunction_class.h"

//icons
#include "wx/artprov.h"

#include "MainFrame.h"

#include "AMILabConfigure.h"
AMILab_VAR_IMPORT MainFrame*    GB_main_wxFrame;
#include <iostream>

//dnd operation
//#include "wxDragAndDrop.h"
#include <wx/dnd.h>
#include <wx/dataobj.h>

//Used for &About menu item
enum
{
  wxID_myABOUT = 1000,
  wxID_ToConsole
};

//BEGIN_EVENT_TABLE(myTreeCtrl, wxTreeCtrl)
BEGIN_EVENT_TABLE(myTreeCtrl, wxTreeListCtrl)
  EVT_MENU(wxID_myABOUT,   myTreeCtrl::OnAbout)
  EVT_MENU(wxID_ToConsole, myTreeCtrl::ToConsole)

//  EVT_TREE_BEGIN_DRAG(wxID_ANY, myTreeCtrl::OnBeginDrag)
#if wxUSE_DRAG_AND_DROP
    EVT_TREE_BEGIN_DRAG(wxID_ANY, myTreeCtrl::OnBeginDrag)
#endif   
/*
  EVT_ERASE_BACKGROUND(    myTreeCtrl::OnEraseBackground)
  EVT_PAINT(               myTreeCtrl::OnPaint)
*/
//  EVT_LEFT_DOWN(myTreeCtrl::OnLeftDown)
//  EVT_RIGHT_DOWN(myTreeCtrl::OnMouseRightDown)
//  EVT_TIMER(ID_TIMER_TIPWINDOW myTreeCtrl::OnTimerTip)

END_EVENT_TABLE()

myTreeCtrl::myTreeCtrl(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size , long style , const wxValidator& validator , const wxString& name ) : //wxTreeCtrl(parent,id,pos,size,style,validator,name)
wxTreeListCtrl(parent,id,pos,size,style,validator,name)
{
  Connect(wxEVT_COMMAND_TREE_ITEM_MENU,wxTreeEventHandler(myTreeCtrl::OnItemMenu));
  //Connect(wxEVT_COMMAND_TREE_BEGIN_DRAG,wxTreeEventHandler(myTreeCtrl::OnBeginDrag));
  //Connect(wxEVT_LEFT_DOWN,wxTreeEventHandler(myTreeCtrl::OnBeginDrag));
  //Connect(wxEVT_LEFT_DOWN,wxTreeEventHandler(myTreeCtrl::OnBeginDrag));
//   Connect
//   (
//     wxEVT_COMMAND_TREE_BEGIN_DRAG,
//     //wxEVT_COMMAND_LIST_BEGIN_DRAG,
//     wxTreeEventHandler(myTreeCtrl::OnBeginDrag),
//     NULL,
//     this
//   );
}

void myTreeCtrl::ShowMenu(wxTreeItemId id, const wxPoint& pt)
{
  
  wxString title;
  if ( id.IsOk() )
  {
    title << GetItemText(id);
    MyTreeItemData *item = (MyTreeItemData *)GetItemData(id);
    if (item) {
      wxMenu menu(title);
      BasicVariable::ptr var = item->GetVar().lock();
     _currentmenu_var = var;
     if (var.get()) {
        std::string com = var->GetComments();
        if (com.compare("")!=0) {
          wxString comments(com.c_str(), wxConvUTF8);
          menu.Append(wxID_ANY, comments);
        }
      }

      // Write in console menu
      wxMenuItem* item1 = new wxMenuItem(&menu,wxID_ToConsole,wxT("Write in console"),
        wxT("write name in the console"));
      wxBitmap bitmap1 = wxArtProvider::GetBitmap(wxART_PASTE, wxART_OTHER, wxDefaultSize);
      if (bitmap1.Ok()) item1->SetBitmap(bitmap1);
      menu.Append(item1 );

      //Put a book icon in the &About item
      wxMenuItem* item2 = new wxMenuItem(&menu,wxID_myABOUT,wxT("&About..."),
        wxT("more information about this variable"));
      wxBitmap bitmap2 = wxArtProvider::GetBitmap(wxART_HELP_BOOK, wxART_OTHER, wxDefaultSize);
      if (bitmap2.Ok()) 
        item2->SetBitmap(bitmap2);
      menu.Append(item2 );
      PopupMenu(&menu, pt);
    }
  }
  else
  {
    title = wxT("No particular item");
    wxMenu menu(title);
    PopupMenu(&menu, pt);
  }

}

void myTreeCtrl::OnItemMenu(wxTreeEvent& event)
{
  wxTreeItemId itemId = event.GetItem();
/*
  MyTreeItemData *item = itemId.IsOk() ? (MyTreeItemData *)GetItemData(itemId)
                                        : NULL;
*/
  wxPoint clientpt = event.GetPoint();
  wxPoint screenpt = ClientToScreen(clientpt);

/*
  wxLogMessage(wxT("OnItemMenu for item \"%s\" at screen coords (%i, %i)"), 
                item ? item->GetDesc() : _T(""), screenpt.x, screenpt.y);
*/

  ShowMenu(itemId, clientpt);
  event.Skip();
}

void myTreeCtrl::OnAbout(wxCommandEvent& event)
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
  wxMessageDialog msg(NULL,wxString(mess.c_str(),wxConvUTF8),
      wxString::FromAscii("Help"),wxOK | wxICON_INFORMATION );
  msg.ShowModal();
}

void myTreeCtrl::ToConsole(wxCommandEvent& event)
{
  BasicVariable::ptr var(_currentmenu_var.lock());
  GB_main_wxFrame->GetConsole()->IncCommand(var->Name());
}

#if wxUSE_DRAG_AND_DROP
void myTreeCtrl::OnBeginDrag(wxTreeEvent& event)
{
  wxTreeItemId itemid( event.GetItem() );

  wxString Text;
  wxString Type;

  if (itemid.IsOk()) // get the item name
  {
    Text = GetItemText(itemid);
    Type = GetItemText (itemid, 1); //Type column.
  }
  else
    Text = _T("No item has been captured");

  std::cout << "myTreeCtrl::OnBeginDrag->"
            << "Dnd: Item Type: "
            << Type.ToAscii() 
            << std::endl;

  if(Type == _T("InrImage"))
  {
    wxTextDataObject dragData(Text); //Create data object.
    wxDropSource dragSource( this ); //Create data source
    dragSource.SetData( dragData );  //Assign the data
    wxDragResult result = dragSource.DoDragDrop( ); //Begin the drag operation.

    //event.Allow();

    switch (result)
    {
      case wxDragCopy: // copy the data
        std::cout << "myTreeCtrl::OnBeginDrag->Drag operation: the data was successfully copied" << std::endl;
        break;
      case wxDragMove: // move the data
        std::cout << "myTreeCtrl::OnBeginDrag->Drag operation: the data was successfully moved" << std::endl;
        break;
      case wxDragError: // Error
        std::cout << "myTreeCtrl::OnBeginDrag->Drag operation: Error" << std::endl;
        break;
      case wxDragNone: // target didn't accept the data
        std::cout << "myTreeCtrl::OnBeginDrag->Drag operation: target didn't accept the data" << std::endl;
        break;
      case wxDragCancel: // the operation was cancelled by user
        std::cout << "myTreeCtrl::OnBeginDrag->Drag operation: the operation was cancelled by user" << std::endl;
        break;
      case wxDragLink: // operation is a drag-link
        std::cout << "myTreeCtrl::OnBeginDrag->Drag operation: this was a link operation" << std::endl;
        break;
      default: // do nothing
        std::cout << "myTreeCtrl::OnBeginDrag->Drag operation: do nothing" << std::endl;
        break;
    }

    std::cout << "myTreeCtrl::OnBeginDrag->"
              << "Dnd: Drag operation(text: "
              << Text.ToAscii() << ")"
              << std::endl;

    event.Skip();
  }
}

#endif

/*
void myTreeCtrl::OnBeginDrag(wxTreeEvent& event)
//void myTreeCtrl::OnLeftDown(wxMouseEvent& event)
{
  std::cout << "\ndragging ..." << std::endl;

  wxString data; // the text we drag
  wxTreeItemId itemid; // the corresponding item

//  itemid = HitTest(event.GetPosition());
  itemid = event.GetItem();

  if (itemid.IsOk()) // get the item name
    data = GetItemText(itemid);
  else
    data = _T("No item has been captured");

  std::cout << "\nsending ---> " << data.c_str() << std::endl;

  wxTextDataObject dragData(data); //Create data object.
  wxDropSource dragSource( this ); //Create data source
  dragSource.SetData( dragData );  //Assign the data
  wxDragResult result = dragSource.DoDragDrop( ); //Begin the drag operation.

  //event.Allow();
  
  switch (result)
  {
      case wxDragCopy:
        / * copy the data *
        std::cout << "\nDrag operation: the data was successfully copied\n" << std::endl;
        break;
      case wxDragMove:
        / * move the data *
        std::cout << "\nDrag operation: the data was successfully moved\n" << std::endl;
        break;
      case wxDragError:
        / * Error *
        std::cout << "\nDrag operation: Error\n" << std::endl;
        break;
      case wxDragNone:
        / * target didn't accept the data *
        std::cout << "\nDrag operation: target didn't accept the data\n" << std::endl;
        break;
      case wxDragCancel:
        / * the operation was cancelled by user *
        std::cout << "\nDrag operation: the operation was cancelled by user\n" << std::endl;
        break;
      case wxDragLink:
        / * operation is a drag-link *
        std::cout << "\nDrag operation: this was a link operation\n" << std::endl;
        break;
      default:
        / * do nothing *
        std::cout << "\nDrag operation: do nothing\n" << std::endl;
        break;
  }

  event.Skip();
}

void myTreeCtrl::OnMouseRightDown(wxMouseEvent& event)
{
  // find the corresponding item
  wxTreeItemId itemid = HitTest(event.GetPosition());
  // popup a menu at this position
  wxMenu* popup_menu = new wxMenu("tree element menu");
  
  if (itemid.IsOk()) {
    // get the item name
    wxString text = GetItemText(itemid);
    std::cout << "Under item " << text.mb_str() << std::endl;
  }
  event.Skip();
}
*/

/*
void myTreeCtrl::OnEraseBackground( wxEraseEvent& WXUNUSED(event) )
{
}

void myTreeCtrl::OnPaint( wxPaintEvent& event )
{
  wxRect rec = this->GetRect();
  wxPaintDC dc;
  dc.GradientFillLinear(rec,wxColour(0,0,0),wxColour(0,0,100),wxWEST);

  event.Skip();
}

*/
