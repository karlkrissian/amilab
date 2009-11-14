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
#include <iostream>

/*
BEGIN_EVENT_TABLE(myTreeCtrl, wxTreeCtrl)
//  EVT_RIGHT_DOWN(myTreeCtrl::OnMouseRightDown)
  EVT_TIMER(ID_TIMER_TIPWINDOW myTreeCtrl::OnTimerTip)
END_EVENT_TABLE()
*/

myTreeCtrl::myTreeCtrl(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size , long style , const wxValidator& validator , const wxString& name ) : wxTreeCtrl(parent,id,pos,size,style,validator,name)
{
    Connect(wxEVT_COMMAND_TREE_ITEM_MENU,wxTreeEventHandler(myTreeCtrl::OnItemMenu));
}

void myTreeCtrl::ShowMenu(wxTreeItemId id, const wxPoint& pt)
{
  wxString title;
  if ( id.IsOk() )
  {
      title << wxT("Menu for ") << GetItemText(id);
  }
  else
  {
      title = wxT("Menu for no particular item");
  }

  wxMenu menu(title);
  menu.Append(wxID_ANY, wxT("&About..."));
  menu.AppendSeparator();
  menu.Append(wxID_ANY, wxT("&Highlight item"));
  menu.Append(wxID_ANY, wxT("&Dump"));

  PopupMenu(&menu, pt);
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