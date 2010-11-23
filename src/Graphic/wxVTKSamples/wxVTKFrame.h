
#ifndef _wxVTKFrame_h_
#define _wxVTKFrame_h_

// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"

#ifdef __BORLANDC__
    #pragma hdrstop
#endif

// for all others, include the necessary headers (this file is usually all you
// need because it includes almost all "standard" wxWindows headers)
#ifndef WX_PRECOMP
    #include "wx/wx.h"
#endif

#include "wxVTKRenderWindowInteractor.h"

#include "vtkRenderer.h"
#include "vtk_common.h"


// Define a new frame type: this is going to be our main frame
class wxVTKFrame : public wxFrame
{
public:
    // ctor(s)
    wxVTKFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
    ~wxVTKFrame();

    // event handlers (these functions should _not_ be virtual)
    void OnQuit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);

    wxVTKRenderWindowInteractor* GetRenderWindowInteractor() 
    { 
      return m_pVTKWindow; 
    }

private:
  wxVTKRenderWindowInteractor *m_pVTKWindow;


private:
    // any class wishing to process wxWindows events must use this macro
    DECLARE_EVENT_TABLE();
};

#endif // _wxVTKFrame_h_
