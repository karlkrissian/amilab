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

#include <iostream>


BEGIN_EVENT_TABLE(myTreeCtrl, wxTreeCtrl)
  EVT_MENU(wxID_ABOUT, myTreeCtrl::OnAbout)
/*
  EVT_ERASE_BACKGROUND(    myTreeCtrl::OnEraseBackground)
  EVT_PAINT(               myTreeCtrl::OnPaint)
*/
//  EVT_RIGHT_DOWN(myTreeCtrl::OnMouseRightDown)
//  EVT_TIMER(ID_TIMER_TIPWINDOW myTreeCtrl::OnTimerTip)
END_EVENT_TABLE()

myTreeCtrl::myTreeCtrl(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size , long style , const wxValidator& validator , const wxString& name ) : wxTreeCtrl(parent,id,pos,size,style,validator,name)
{
    Connect(wxEVT_COMMAND_TREE_ITEM_MENU,wxTreeEventHandler(myTreeCtrl::OnItemMenu));
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
      Variable* var = item->GetVar();
     _currentmenu_var = var;
     if (var) {
        std::string com = var->GetComments();
        if (com.compare("")!=0) {
          wxString comments(com.c_str(), wxConvUTF8);
          menu.Append(wxID_ANY, comments);
        }
      }
      menu.Append(wxID_ABOUT, wxT("&About..."));
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
  if (_currentmenu_var) {
    switch (_currentmenu_var->Type()) {
      case type_c_procedure     : 
        ((void (*)(ParamList*)) _currentmenu_var->Pointer())(NULL);
        return;

      case type_class_procedure     : 
        // getting the associated help
        (*((WrapClassMember::ptr*) _currentmenu_var->Pointer()))->ShowHelp();
        return;
      case type_c_image_function:
       ((InrImage* (*)(ParamList*)) _currentmenu_var->Pointer())(NULL);
        return;
      case type_c_function:
        ((Variable::ptr (*)(ParamList*)) _currentmenu_var->Pointer())(NULL);
        return;
      default:
        mess = _currentmenu_var->GetComments();
    }
  } else {
    mess = "No variable for this item";
  }
  wxMessageDialog* msg = new wxMessageDialog(NULL,wxString::FromAscii(mess.c_str()),
      wxString::FromAscii("Help"),wxOK | wxICON_INFORMATION );
  msg->ShowModal();
}



/*
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