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
#ifndef DNDCHOICETEXTDROPTARGET_H
#define DNDCHOICETEXTDROPTARGET_H

#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

#include "wx/dnd.h"
#include "wx/dataobj.h"
#include <wx/string.h>
#include "wxEnumerationParameter.h"

class DndChoiceTextDropTarget : public wxTextDropTarget
{
public:
  DndChoiceTextDropTarget(wxEnumerationParameter *pOwner) {
    m_pOwner = pOwner;
  }

  virtual bool OnDropText(wxCoord x, wxCoord y, const wxString& text);

  virtual wxDragResult OnEnter(wxCoord x, wxCoord y, wxDragResult def);

private:
  wxEnumerationParameter* m_pOwner;
};

#endif // DNDCHOICETEXTDROPTARGET_H
