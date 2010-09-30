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

#include "myHtmlWindow.h"
#include <wx/clipbrd.h>
#include <wx/pen.h> 
#include <wx/utils.h>
#include <wx/gdicmn.h>
#include <wx/regex.h>

wxHtmlOpeningStatus myHtmlWindow::OnOpeningURL(wxHtmlURLType WXUNUSED(type),
                                               const wxString& url,
                                               wxString *WXUNUSED(redirect)) const
{
//    GetRelatedFrame()->SetStatusText(url + wxT(" lately opened"),1);
    std::cout << "opening " << url.c_str() << std::endl;
    return wxHTML_OPEN;
}


void myHtmlWindow::OnHtmlLinkClicked(wxHtmlLinkEvent &event)
{
//    wxLogMessage(wxT("The url '%s' has been clicked!"), event.GetLinkInfo().GetHref().c_str());

  wxRegEx http_link(wxT("[:blank:]*http://.*"));
  if (http_link.Matches(event.GetLinkInfo().GetHref()))
  {
    wxLaunchDefaultBrowser(event.GetLinkInfo().GetHref());
  } else
  {
    // skipping this event the default behaviour (load the clicked URL)
    // will happen...
    event.Skip();
  }
}

BEGIN_EVENT_TABLE(myHtmlWindow, wxHtmlWindow)
#if wxUSE_CLIPBOARD
    EVT_TEXT_COPY(wxID_ANY, myHtmlWindow::OnClipboardEvent)
#endif // wxUSE_CLIPBOARD
    EVT_ERASE_BACKGROUND(myHtmlWindow::OnEraseBgEvent)
    EVT_HTML_LINK_CLICKED(wxID_ANY, myHtmlWindow::OnHtmlLinkClicked)
END_EVENT_TABLE()


#if wxUSE_CLIPBOARD
void myHtmlWindow::OnClipboardEvent(wxClipboardTextEvent& WXUNUSED(event))
{
    // explicitly call wxHtmlWindow::CopySelection() method
    // and show the first 100 characters of the text copied in the status bar
    if ( CopySelection() )
    {
        wxTextDataObject data;
        if ( wxTheClipboard && wxTheClipboard->Open() && wxTheClipboard->GetData(data) )
        {
            const wxString text = data.GetText();
            const size_t maxTextLength = 100;

            wxLogStatus(wxString::Format(wxT("Clipboard: '%s%s'"),
                        wxString(text, maxTextLength).c_str(),
                        (text.length() > maxTextLength) ? wxT("...")
                                                        : wxT("")));
            wxTheClipboard->Close();

            return;
        }
    }

    wxLogStatus(wxT("Clipboard: nothing"));
}
#endif // wxUSE_CLIPBOARD

void myHtmlWindow::OnEraseBgEvent(wxEraseEvent& event)
{
    if ( !m_drawCustomBg )
    {
        event.Skip();
        return;
    }

    // draw a background grid to show that this handler is indeed executed

    wxDC& dc = *event.GetDC();
//    dc.SetPen(*wxBLUE_PEN);
    dc.Clear();

    const wxSize size = GetVirtualSize();
    for ( int x = 0; x < size.x; x += 15 )
    {
        dc.DrawLine(x, 0, x, size.y);
    }

    for ( int y = 0; y < size.y; y += 15 )
    {
        dc.DrawLine(0, y, size.x, y);
    }
}
