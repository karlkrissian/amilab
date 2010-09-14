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

myDataViewCtrl::myDataViewCtrl( wxWindow* parent, wxWindowID id,
  const wxPoint& pos = wxDefaultPosition,
  const wxSize& size = wxDefaultSize,
  long style = wxTR_HAS_BUTTONS,
  const wxValidator& validator = wxDefaultValidator)
{
  // CONSTRUCTOR DEFINITION.
  wxASSERT(!m_ctrl && !m_amilab_model);
  m_ctrl = new wxDataViewCtrl(parent, id, pos, size, style, validator);

  m_amilab_model = new AMILabTreeModel();
  m_ctrl->AssociateModel( m_amilab_model.get() );

  m_ctrl->EnableDragSource( wxDF_UNICODETEXT );
  m_ctrl->EnableDropTarget( wxDF_UNICODETEXT );

  // column 0 of the view control: Name
  wxDataViewTextRenderer *tr =
    new wxDataViewTextRenderer( "string", wxDATAVIEW_CELL_INERT );

  wxDataViewColumn *column0 =
    new wxDataViewColumn( "Name", tr, 0, 250, wxALIGN_LEFT,
      wxDATAVIEW_COL_SORTABLE | wxDATAVIEW_COL_RESIZABLE );
  column0->SetMinWidth(150);
  m_ctrl->AppendColumn( column0 );

  // column 1 of the view control: Type
  wxDataViewColumn *column1 =
      new wxDataViewColumn( "Type", tr, 1, 100, wxALIGN_LEFT,
                            wxDATAVIEW_COL_SORTABLE | wxDATAVIEW_COL_REORDERABLE |
                            wxDATAVIEW_COL_RESIZABLE );
  column1->SetMinWidth(100); // this column can't be resized to be smaller
  m_ctrl->AppendColumn( column1 );

  // column 2 of the view control: Val
  wxDataViewColumn *column2 =
      new wxDataViewColumn( "Val", tr, 2, 60, wxALIGN_LEFT,
                            wxDATAVIEW_COL_SORTABLE | wxDATAVIEW_COL_REORDERABLE |
                            wxDATAVIEW_COL_RESIZABLE );
  column2->SetMinWidth(60); // this column can't be resized to be smaller
  m_ctrl->AppendColumn( column2 );

  // column 3 of the view control: Details
  wxDataViewColumn *column3 =
      new wxDataViewColumn( "Details", tr, 3, 250, wxALIGN_LEFT,
                            wxDATAVIEW_COL_SORTABLE | wxDATAVIEW_COL_REORDERABLE |
                            wxDATAVIEW_COL_RESIZABLE );
  column3->SetMinWidth(250); // this column can't be resized to be smaller
  m_ctrl->AppendColumn( column3 );
}

void myDataViewCtrl::OnContextMenu( wxDataViewEvent &event )
{
  MyDataViewItemData item( event.GetItem() );

  wxPoint clientpt = event.GetPosition();
  wxPoint screenpt = ClientToScreen(clientpt);

  ShowMenu(item, clientpt);
  event.Skip();
}

void myDataViewCtrl::ShowMenu(MyDataViewItemData id, const wxPoint& pt)
{
  if ( id.IsOk() )
  {
    wxMenu menu(m_amilab_model->GetName(id));
    BasicVariable::ptr var = m_amilab_model->GetVar(id).lock();
    _currentmenu_var = var;

    if (var.get()) {
      std::string com = var->GetComments();
      if (com.compare("")!=0) {
        wxString comments(com.c_str(), wxConvUTF8);
        menu.Append(wxID_ANY, comments);
      }
    }

    // Write in console menu
    wxMenuItem* item1 = new wxMenuItem(&menu,wxMENU_ID_ToConsole,wxT("Write in console"),
      wxT("write name in the console"));
    wxBitmap bitmap1 = wxArtProvider::GetBitmap(wxART_PASTE, wxART_OTHER, wxDefaultSize);
    if (bitmap1.Ok()) item1->SetBitmap(bitmap1);
    menu.Append(item1 );

    //Put a book icon in the &About item
    wxMenuItem* item2 = new wxMenuItem(&menu,wxMENU_ID_myABOUT,wxT("&About..."),
      wxT("more information about this variable"));
    wxBitmap bitmap2 = wxArtProvider::GetBitmap(wxART_HELP_BOOK, wxART_OTHER, wxDefaultSize);
    if (bitmap2.Ok())
      item2->SetBitmap(bitmap2);
    menu.Append(item2 );
    PopupMenu(&menu, pt);
  }
  else
  {
    wxMenu menu(wxT("No particular item"));
    PopupMenu(&menu, pt);
  }
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
