
#ifndef _wxMedical3Frame_h_
#define _wxMedical3Frame_h_

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



// Define a new frame type: this is going to be our main frame
class wxMedical3Frame : public wxFrame
{
public:
    // ctor(s)
    wxMedical3Frame(const wxString& title, const wxPoint& pos, const wxSize& size);
    ~wxMedical3Frame();

    // event handlers (these functions should _not_ be virtual)
    void OnQuit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);

protected:
    void ConstructVTK();
    void ConfigureVTK();
    void DestroyVTK();

private:
  wxVTKRenderWindowInteractor *m_pVTKWindow;

  // vtk classes
  vtkRenderer       *aRenderer;

private:
    // any class wishing to process wxWindows events must use this macro
    DECLARE_EVENT_TABLE()
};

#endif // _wxMedical3Frame_h_
