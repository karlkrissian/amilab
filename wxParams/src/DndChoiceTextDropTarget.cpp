//
// C++ Interface: DragAndDrop
//
// Description: Drag and drop operation for wxChoice.
//
//
// Author:  <Karl Krissian>, (C) 2009
//
// Copyright: See COPYING file that comes with this distribution
//
//

#include "DndChoiceTextDropTarget.h"

bool DndChoiceTextDropTarget::OnDropText(wxCoord x, wxCoord y, const wxString& text)
{
  std::cout << "DndChoiceTextDropTarget::OnDropText->"
            << "recieving: " << text << std::endl;

  // Process the string received to determine if it is an image
  int Pos = text.First(_T("-"));
  wxString Type = text.SubString(0, Pos-1); //Get prefix
  wxString Value = text.SubString(Pos+1, text.Len()); //Get text

  std::cout << "DndChoiceTextDropTarget::OnDropText->"
            << "Received information: "
            << "Type: " << Type << " "
            << "Text: " << Value
            << std::endl;

  if (Type == wxT("InrImage"))
  {
    if (!m_pOwner->SetStringSelection(Value))
    {
      // if not able to set the same selection, set to the first item
      m_pOwner->Append(Value);
      m_pOwner->SetStringSelection(Value);
    }

    std::cout << "DndChoiceTextDropTarget::OnDropText->"
              << "Selected Item: "
              << m_pOwner->GetString(m_pOwner->GetCurrentSelection())
              << std::endl;
  }
  else
    std::cout << "DndChoiceTextDropTarget::OnDropText->"
              << "Not allowed operation(It is not an image)"
              << std::endl;

  return true;
}

wxDragResult DndChoiceTextDropTarget::OnEnter(wxCoord x, wxCoord y, wxDragResult def)
{
  std::cout << "DndChoiceTextDropTarget::OnEnter->"
            << "recieving data..." << std::endl;
  return def;
};
