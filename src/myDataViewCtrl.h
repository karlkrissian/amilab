//
// C++ Interface: MyDataViewCtrl
//
// Description: wxDataViewCtrl wxWidgets custom implementation.
//
//
// Author:  <Karl Krissian>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef MYDATAVIEWCTRL_H
#define MYDATAVIEWCTRL_H

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

#include <wx/dataview.h>
#include "myDataViewModels.h"
#include <boost/weak_ptr.hpp>

class BasicVariable;

template <class T>
class Variable;

//=======================================================

class MyDataViewItemData : public wxDataViewItem
{
  public:
    MyDataViewItemData(boost::shared_ptr<BasicVariable> lvar) : _var(lvar) { }

    boost::weak_ptr<BasicVariable> GetVar() const { return _var; }

  private:
    /// weak pointer to the Variable
    boost::weak_ptr<BasicVariable> _var;
};

//=======================================================

class myDataViewCtrl: public wxDataViewCtrl
{
  public:
    myDataViewCtrl(wxWindow* parent, wxWindowID id,
      const wxPoint& pos = wxDefaultPosition,
      const wxSize& size = wxDefaultSize,
      long style = wxTR_HAS_BUTTONS,
      const wxValidator& validator = wxDefaultValidator);

  protected:
    void OnContextMenu( wxDataViewEvent &event );

    void OnBeginDrag( wxDataViewEvent &event );
    void OnDropPossible( wxDataViewEvent &event );
    void OnDrop( wxDataViewEvent &event );

    void OnActivated( wxDataViewEvent &event );
    void OnExpanding( wxDataViewEvent &event );
    void OnExpanded( wxDataViewEvent &event );
    void OnCollapsing( wxDataViewEvent &event );
    void OnCollapsed( wxDataViewEvent &event );
    void OnSelectionChanged( wxDataViewEvent &event );

    void OnStartEditing( wxDataViewEvent &event );
    void OnEditingStarted( wxDataViewEvent &event );
    void OnEditingDone( wxDataViewEvent &event );
    void OnValueChanged( wxDataViewEvent &event );

    void OnHeaderClick( wxDataViewEvent &event );
    void OnHeaderRightClick( wxDataViewEvent &event );
    void OnSorted( wxDataViewEvent &event );

// Eventos a comprobar que están implementados en el DataView.
//  void OnItemMenu(wxTreeEvent& event);
//   void OnAbout(wxCommandEvent& event);
//   void ToConsole(wxCommandEvent& event);
//   void ShowMenu(wxTreeItemId id, const wxPoint& pt);
//   void OnItemRightClick(wxTreeEvent& event);

  private:
    boost::weak_ptr<BasicVariable> _currentmenu_var;
    DECLARE_EVENT_TABLE();
}

#endif // MYDATAVIEWCTRL_H