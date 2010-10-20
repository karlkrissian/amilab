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

bool TextControlDropTarget::OnDropNode(wxCoord x, wxCoord y, const MyNode& node)
{
//   std::cout << "recieving --> " << text.c_str() << std::endl;
  std::cout << "recieving data..." << std::endl;

  wxString Text = node.GetAbsoluteName();
  boost::shared_ptr<BasicVariable> var = node.GetVar().lock();

  if (var.get())
    Text = Text + " : " + wxString(var->GetTypeName().c_str(), wxConvUTF8);

  std::cout << "recieving --> " << Text << std::endl;

  m_pOwner->IncCommand(Text);

  return true;
}

wxDragResult TextControlDropTarget::OnEnter(wxCoord x, wxCoord y, wxDragResult def)
{
  std::cout << "recieving data..." << std::endl;
  return def;
};

bool TextControlTextDropTarget::OnDropText(wxCoord x, wxCoord y, const wxString& text)
{
  std::cout << "recieving --> " << text.c_str() << std::endl;

  m_pOwner->IncCommand(text);

  return true;
}

wxDragResult TextControlTextDropTarget::OnEnter(wxCoord x, wxCoord y, wxDragResult def)
{
  std::cout << "recieving data..." << std::endl;
  return def;
};