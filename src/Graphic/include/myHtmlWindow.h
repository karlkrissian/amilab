//
// C++ Interface: myHtmlWindow
//
// Description: 
//
//
// Author: Karl Krissian <krissian@dis.ulpgc.es>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//


#ifndef _myHtmlWindow_h_
#define _myHtmlWindow_h_

// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"

#ifdef __BORLANDC__
    #pragma hdrstop
#endif

// For all others, include the necessary headers (this file is usually all you
// need because it includes almost all "standard" wxWidgets headers
#ifndef WX_PRECOMP
    #include "wx/wx.h"
#endif

#include "wx/html/htmlwin.h"
#include "wx/html/htmlproc.h"
#include "wx/fs_inet.h"


// Define a new html window type: this is a wrapper for handling wxHtmlWindow events
class myHtmlWindow : public wxHtmlWindow
{
public:
    myHtmlWindow(wxWindow *parent) : wxHtmlWindow( parent )
    {
        // no custom background initially to avoid confusing people
        m_drawCustomBg = false;
    }

    virtual wxHtmlOpeningStatus OnOpeningURL(wxHtmlURLType WXUNUSED(type),
                                             const wxString& WXUNUSED(url),
                                             wxString *WXUNUSED(redirect)) const;

    // toggle drawing of custom background
    void DrawCustomBg(bool draw)
    {
        m_drawCustomBg = draw;
        Refresh();
    }

private:
#if wxUSE_CLIPBOARD
    void OnClipboardEvent(wxClipboardTextEvent& event);
#endif // wxUSE_CLIPBOARD
    void OnEraseBgEvent(wxEraseEvent& event);

    void OnHtmlLinkClicked(wxHtmlLinkEvent &event);

    bool m_drawCustomBg;

    DECLARE_EVENT_TABLE()
//    wxDECLARE_NO_COPY_CLASS(myHtmlWindow);
};




#endif // _myHtmlWindow_h_
