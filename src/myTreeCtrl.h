//
// C++ Interface: myTreeCtrl
//
// Description: 
//
//
// Author:  <Karl Krissian>, (C) 2009
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _myTreeCtrl_h_
#define _myTreeCtrl_h_

//--------------------------------------------------
// includes for wxWidgets
//--------------------------------------------------
#include "wx/wxprec.h"
#ifdef __BORLANDC__
#pragma hdrstop
#endif
#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

#include "wx/treectrl.h"

//=======================================================
class myTreeCtrl: public wxTreeCtrl
{
public: 
  myTreeCtrl(wxWindow* parent, wxWindowID id, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxTR_HAS_BUTTONS, const wxValidator& validator = wxDefaultValidator, const wxString& name = _T("treeCtrl")):
    wxTreeCtrl(parent,id,pos,size,style,validator,name) {}
protected:
  void OnMouseRightDown(wxMouseEvent& event);
private:
    DECLARE_EVENT_TABLE();
};


#endif // _myTreeCtrl_h_
