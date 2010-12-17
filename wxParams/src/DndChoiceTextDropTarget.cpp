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
#include <iostream>

bool DndChoiceTextDropTarget::OnDropText(wxCoord x, wxCoord y, const wxString& text)
{
  std::cout << "DndChoiceTextDropTarget::OnDropText->"
            << "recieving: " << text << std::endl;

  int Pos;

///@cond wxCHECK
#if wxCHECK_VERSION(2,9,0)
  // Process the string received to determine if it is an image
  Pos = text.First(_T("-"));
  wxString Type = text.SubString(0, Pos-1); //Get prefix
  wxString Value = text.SubString(Pos+1, text.Len()); //Get text

  std::cout << "DndChoiceTextDropTarget::OnDropText->"
            << "Received information: "
            << "Type: " << Type << " "
            << "Text: " << Value
            << std::endl;

  if (Type == wxT("InrImage"))
  {
    m_pOwner->AddChoice( &Pos, Value.char_str() );
    m_pOwner->SetSelection( Pos );

    std::cout << "DndChoiceTextDropTarget::OnDropText->"
              << "Selected Item: "
              << m_pOwner->GetStringSelection()
              << std::endl;
  }
  else
    std::cout << "DndChoiceTextDropTarget::OnDropText->"
              << "Not allowed operation(It is not an image)"
              << std::endl;
#else
    wxString Name = m_pOwner->GetAbsoluteName(text);

    m_pOwner->AddChoice( &Pos, Name.char_str() );
    m_pOwner->SetSelection( Pos );

    std::cout << "DndChoiceTextDropTarget::OnDropText->"
              << "Selected Item: "
              << m_pOwner->GetStringSelection().ToAscii()
              << std::endl;
#endif
/// @endcond
  return true;
}

wxDragResult DndChoiceTextDropTarget::OnEnter(wxCoord x, wxCoord y, wxDragResult def)
{
  std::cout << "DndChoiceTextDropTarget::OnEnter->"
            << "recieving data..." << std::endl;
  return def;
};
