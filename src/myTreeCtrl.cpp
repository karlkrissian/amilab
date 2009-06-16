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

BEGIN_EVENT_TABLE(myTreeCtrl, wxTreeCtrl)
  EVT_RIGHT_DOWN(myTreeCtrl::OnMouseRightDown)
END_EVENT_TABLE()

void myTreeCtrl::OnMouseRightDown(wxMouseEvent& event)
{
  // find the corresponding item
  wxTreeItemId itemid = HitTest(event.GetPosition());
  if (itemid.IsOk()) {
    // get the item name
    wxString text = GetItemText(itemid);
    std::cout << "Under item " << text.mb_str() << std::endl;
  }
}
