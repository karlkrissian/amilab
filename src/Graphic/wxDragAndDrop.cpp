//
// C++ Interface: DragAndDrop
//
// Description: Drag and drop operation
//
//
// Author:  <Karl Krissian>, (C) 2009
//
// Copyright: See COPYING file that comes with this distribution
//
//

#include "wxDragAndDrop.h"

bool TextControlTextDropTarget::OnDropText(wxCoord x, wxCoord y, const wxString& text)
{
  std::cout << "recieving --> " << text.c_str() << std::endl;

  m_pOwner->AddCommand(text);

  return true;
}

wxDragResult TextControlTextDropTarget::OnEnter(wxCoord x, wxCoord y, wxDragResult def)
{
  std::cout << "recieving data..." << std::endl;
  return def;
};
