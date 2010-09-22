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

// #include <wx/any.h>

// //=======================================================
// 
// class MyDataViewItemData : public wxDataViewItem
// {
//   public:
//     MyDataViewItemData(boost::shared_ptr<BasicVariable> lvar) : _var(lvar) { }
// 
//     boost::weak_ptr<BasicVariable> GetVar() const { return _var; }
// 
//   private:
//     /// weak pointer to the Variable
//     boost::weak_ptr<BasicVariable> _var;
// };

//=======================================================

// ---------------------------------------------------------
// wxDataViewAnyRenderer
// ---------------------------------------------------------

// class wxDataViewAnyRenderer: public wxDataViewCustomRenderer
// {
//   public:
//     wxDataViewAnyRenderer(): wxDataViewCustomRenderer("string",
//                                    wxDATAVIEW_CELL_ACTIVATABLE,
//                                    wxALIGN_CENTER)
//        { }
// 
//     virtual bool SetValue( const wxVariant &value )
//     {
//       m_value = value;
//       return true;
//     }
// 
//     virtual bool GetValue( wxVariant &value ) const
//     {
//       value = m_value;
// 
//       return true;
//     }
// 
//     virtual wxSize GetSize() const
//     {
//         return wxSize();
//     }
// 
//     virtual bool Render( wxRect rect, wxDC *dc, int state )
//     {
//         return true;
//     }
// 
//   private:
//     wxVariant m_value;
// };

//=======================================================

class myDataViewCtrl: public wxDataViewCtrl
{
  public:
    myDataViewCtrl(wxWindow* parent, wxWindowID id,
      const wxPoint& pos = wxDefaultPosition,
      const wxSize& size = wxDefaultSize,
      long style = 0,
      const wxValidator& validator = wxDefaultValidator);

  protected:
    void OnContextMenu( wxDataViewEvent &event );
    void OnAbout( wxCommandEvent& event );
    void ToConsole( wxCommandEvent& event );

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

    void OnDataViewChar(wxKeyEvent& event);

  private:
    boost::weak_ptr<BasicVariable> _currentmenu_var;
//     void _ShowMenu( MyDataViewItemData id, const wxPoint& pt );
    
    DECLARE_EVENT_TABLE();
};

#endif // MYDATAVIEWCTRL_H