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
#include "treelistctrl.h"

#include <boost/weak_ptr.hpp>

class BasicVariable;

template <class T>
class Variable;

//#include "Variable.hpp"

//----------------------------------------------------
class MyTreeItemData : public wxTreeItemData
{
public:
    MyTreeItemData(boost::shared_ptr<BasicVariable> lvar) : _var(lvar) { }

    boost::weak_ptr<BasicVariable> GetVar() const { return _var; }

private:
    /// weak pointer to the Variable
    boost::weak_ptr<BasicVariable> _var;
};

//=======================================================
//class myTreeCtrl: public wxTreeCtrl
class myTreeCtrl: public wxTreeListCtrl
{
public: 
  myTreeCtrl(wxWindow* parent, wxWindowID id, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxTR_HAS_BUTTONS, const wxValidator& validator = wxDefaultValidator, const wxString& name = _T("treeCtrl"));

protected:
  void OnItemMenu(wxTreeEvent& event);
  void OnAbout(wxCommandEvent& event);
  void ToConsole(wxCommandEvent& event);
  void ShowMenu(wxTreeItemId id, const wxPoint& pt);
  void OnItemRightClick(wxTreeEvent& event);

  /// Drag event: Initiate the drag from myTreeCtrl control.
//  void OnBeginDrag(wxTreeEvent& event);
//  void OnLeftDown(wxMouseEvent& event);
  
/*
  void OnEraseBackground( wxEraseEvent& WXUNUSED(event) );
  void OnPaint( wxPaintEvent& event );
*/
//  void OnMouseRightDown(wxMouseEvent& event);

//  void OnTimerTip(wxTimerEvent &event);

private:
    boost::weak_ptr<BasicVariable> _currentmenu_var;
    DECLARE_EVENT_TABLE();
};


#endif // _myTreeCtrl_h_
