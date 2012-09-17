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

#include "AMILabTreeModel.h"
#include "amiDataViewTreeList.h"

///@cond wxCHECK
#if wxCHECK_VERSION(2,9,0)
// #include <wx/any.h>


class myDataViewTreeListCtrl: public wxDataViewTreeListCtrl
{
  public:
    myDataViewTreeListCtrl(wxWindow* parent, wxWindowID id,
      const wxPoint& pos = wxDefaultPosition,
      const wxSize& size = wxDefaultSize,
      long style = 0,
      const wxValidator& validator = wxDefaultValidator);


  protected:
    void OnContextMenu( wxDataViewEvent &event );
    void OnAbout( wxCommandEvent& event );
    void ToConsole( wxCommandEvent& event );
    void ShowHideImage( wxCommandEvent& event );

    void OnActivated(  wxDataViewEvent& event);
    void OnExpanding(  wxDataViewEvent& event);
    void OnCollapsing( wxDataViewEvent& event);

  private:
    boost::weak_ptr<BasicVariable> _currentmenu_var;
    void _ShowMenu( const wxDataViewItem &item, const wxPoint& pt );

    DECLARE_EVENT_TABLE();
};



//=======================================================

class myDataViewCtrl: public wxDataViewCtrl
{
  public:
    myDataViewCtrl(wxWindow* parent, wxWindowID id,
      const wxPoint& pos = wxDefaultPosition,
      const wxSize& size = wxDefaultSize,
      long style = 0,
      const wxValidator& validator = wxDefaultValidator);

    void InternalAssociateModel( AMILabTreeModel *model );

  protected:
    void OnContextMenu( wxDataViewEvent &event );
    void OnAbout( wxCommandEvent& event );
    void ToConsole( wxCommandEvent& event );

    void OnActivated( wxDataViewEvent &event );
    void OnSorted( wxDataViewEvent &event );

#if wxUSE_DRAG_AND_DROP
    void OnBeginDrag( wxDataViewEvent &event );
    void OnDropPossible( wxDataViewEvent &event );
//    void OnDrop( wxDataViewEvent &event );
#endif

  private:
    boost::weak_ptr<BasicVariable> _currentmenu_var;
    AMILabTreeModel* _amilab_model;

    void _ShowMenu( const wxDataViewItem &item, const wxPoint& pt );
    
    DECLARE_EVENT_TABLE();
};

#endif
/// @endcond

#endif // MYDATAVIEWCTRL_H