//
// C++ Interface: DragAndDrop
//
// Description: Drag and drop operation for wxTreeCtrl.
//
//
// Author:  <Karl Krissian>, (C) 2009
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef DRAGANDDROP_H
#define DRAGANDDROP_H

#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

#include "wx/dnd.h"
#include "wx/dataobj.h"

#include "myTreeCtrl.h"
#include "xmtext.hpp"

// ----------------------------------------------------------------------------
// TextControlTextDropTarget: dragging text to TextControl.
// ----------------------------------------------------------------------------

class TextControlTextDropTarget : public wxTextDropTarget
{
  public:
    TextControlTextDropTarget(TextControl::ptr pOwner) { m_pOwner = pOwner; }

    virtual bool OnDropText(wxCoord x, wxCoord y, const wxString& text);

    virtual wxDragResult OnEnter(wxCoord x, wxCoord y, wxDragResult def);

  private:
    TextControl::ptr m_pOwner;
};


#endif // DRAGANDDROP_H
