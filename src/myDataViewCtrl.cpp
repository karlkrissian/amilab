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
#define MYDATAVIEWCTRL_H

#include "Variable.hpp"
#include "paramlist.h"
#include "wrapfunction_class.h"

//icons
#include "wx/artprov.h"

#include "MainFrame.h"
extern MainFrame*    GB_main_wxFrame;
#include <iostream>

#include "myDataViewCtrl.h"

//Pop menu: two options ("Write in console" and "About..")
enum
{
  wxMENU_ID_myABOUT = 1000,
  wxMENU_ID_ToConsole
};

BEGIN_EVENT_TABLE(myDataViewCtrl, wxDataViewCtrl)
  EVT_MENU(wxMENU_ID_myABOUT,   myDataViewCtrl::OnAbout)
  EVT_MENU(wxMENU_ID_ToConsole, myDataViewCtrl::ToConsole)

  EVT_DATAVIEW_ITEM_CONTEXT_MENU(wxID_ANY, myDataViewCtrl::OnContextMenu)
  EVT_DATAVIEW_ITEM_BEGIN_DRAG( wxID_ANY, myDataViewCtrl::OnBeginDrag )
  EVT_DATAVIEW_ITEM_DROP_POSSIBLE( wxID_ANY, myDataViewCtrl::OnDropPossible )
  EVT_DATAVIEW_ITEM_DROP( wxID_ANY, myDataViewCtrl::OnDrop )

  EVT_DATAVIEW_ITEM_ACTIVATED(wxID_ANY, myDataViewCtrl::OnActivated )
  EVT_DATAVIEW_ITEM_EXPANDING(wxID_ANY, myDataViewCtrl::OnExpanding)
  EVT_DATAVIEW_ITEM_EXPANDED(wxID_ANY, myDataViewCtrl::OnExpanded)
  EVT_DATAVIEW_ITEM_COLLAPSING(wxID_ANY, myDataViewCtrl::OnCollapsing)
  EVT_DATAVIEW_ITEM_COLLAPSED(wxID_ANY, myDataViewCtrl::OnCollapsed)
  EVT_DATAVIEW_SELECTION_CHANGED(wxID_ANY, myDataViewCtrl::OnSelectionChanged)

  EVT_DATAVIEW_ITEM_START_EDITING(wxID_ANY, myDataViewCtrl::OnStartEditing)
  EVT_DATAVIEW_ITEM_EDITING_STARTED(wxID_ANY, myDataViewCtrl::OnEditingStarted)
  EVT_DATAVIEW_ITEM_EDITING_DONE(wxID_ANY, myDataViewCtrl::OnEditingDone)

  EVT_DATAVIEW_COLUMN_HEADER_CLICK(wxID_ANY, myDataViewCtrl::OnHeaderClick)
  EVT_DATAVIEW_COLUMN_HEADER_RIGHT_CLICKED(wxID_ANY, myDataViewCtrl::OnHeaderRightClick)
  EVT_DATAVIEW_COLUMN_SORTED(wxID_ANY, myDataViewCtrl::OnSorted)

END_EVENT_TABLE()

myDataViewCtrl::myDataViewCtrl(wxWindow* parent, wxWindowID id,
      const wxPoint& pos = wxDefaultPosition,
      const wxSize& size = wxDefaultSize,
      long style = wxTR_HAS_BUTTONS,
      const wxValidator& validator = wxDefaultValidator) :
  myDataViewCtrl(parent,id,pos,size,style,validator)
{
  // CONSTRUCTOR DEFINITION.
}


void myDataViewCtrl::OnContextMenu( wxDataViewEvent &event )
{
      wxMenu menu;
    menu.Append( 1, "menuitem 1" );
    menu.Append( 2, "menuitem 2" );
    menu.Append( 3, "menuitem 3" );
}

void myDataViewCtrl::OnBeginDrag( wxDataViewEvent &event )
{

}

void myDataViewCtrl::OnDropPossible( wxDataViewEvent &event )
{

}

void myDataViewCtrl::OnDrop( wxDataViewEvent &event )
{

}

void myDataViewCtrl::OnActivated( wxDataViewEvent &event )
{

}

void myDataViewCtrl::OnExpanding( wxDataViewEvent &event )
{

}
void myDataViewCtrl::OnExpanded( wxDataViewEvent &event )
{

}

void myDataViewCtrl::OnCollapsing( wxDataViewEvent &event )
{

}

void myDataViewCtrl::OnCollapsed( wxDataViewEvent &event )
{

}

void myDataViewCtrl::OnSelectionChanged( wxDataViewEvent &event )
{

}

void myDataViewCtrl::OnStartEditing( wxDataViewEvent &event )
{

}

void myDataViewCtrl::OnEditingStarted( wxDataViewEvent &event )
{

}

void myDataViewCtrl::OnEditingDone( wxDataViewEvent &event )
{

}

void myDataViewCtrl::OnValueChanged( wxDataViewEvent &event )
{

}

void myDataViewCtrl::OnHeaderClick( wxDataViewEvent &event )
{

}

void myDataViewCtrl::OnHeaderRightClick( wxDataViewEvent &event )
{

}

void myDataViewCtrl::OnSorted( wxDataViewEvent &event )
{

}
