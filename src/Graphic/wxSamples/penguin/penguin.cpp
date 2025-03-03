/////////////////////////////////////////////////////////////////////////////
// Name:        penguin.cpp
// Purpose:     wxGLCanvas demo program
// Author:      Robert Roebling
// Modified by: Sandro Sigala
// Created:     04/01/98
// RCS-ID:      $Id: penguin.cpp 43272 2006-11-10 15:16:02Z VZ $
// Copyright:   (c) Robert Roebling
// Licence:     wxWindows licence
/////////////////////////////////////////////////////////////////////////////

// For compilers that support precompilation, includes "wx.h".
#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

#if !wxUSE_GLCANVAS
    #error "OpenGL required: set wxUSE_GLCANVAS to 1 and rebuild the library"
#endif

#include "penguin.h"
#ifdef __DARWIN__
    #include <OpenGL/glu.h>
#else
    #include <GL/glu.h>
#endif

#include "sample.xpm"

/*
// ---------------------------------------------------------------------------
// MyApp
// ---------------------------------------------------------------------------

// `Main program' equivalent, creating windows and returning main app frame
bool MyApp::OnInit()
{
    // Create the main frame window
    PenguinFrame *frame = new PenguinFrame(NULL, wxT("wxWidgets Penguin Sample"),
        wxDefaultPosition, wxDefaultSize);

#if wxUSE_ZLIB
    if (wxFileExists(wxT("penguin.dxf.gz")))
        frame->GetCanvas()->LoadDXF(wxT("penguin.dxf.gz"));
#else
    if (wxFileExists(wxT("penguin.dxf")))
        frame->GetCanvas()->LoadDXF(wxT("penguin.dxf"));
#endif

    // Show the frame 
    frame->Show(true);

    return true;
}

IMPLEMENT_APP(MyApp)

*/

// ---------------------------------------------------------------------------
// PenguinFrame
// ---------------------------------------------------------------------------

BEGIN_EVENT_TABLE(PenguinFrame, wxFrame)
    EVT_MENU(wxID_OPEN, PenguinFrame::OnMenuFileOpen)
    EVT_MENU(wxID_EXIT, PenguinFrame::OnMenuFileExit)
    EVT_MENU(wxID_HELP, PenguinFrame::OnMenuHelpAbout)
END_EVENT_TABLE()

// PenguinFrame constructor
PenguinFrame::PenguinFrame(wxFrame *frame, const wxString& title, const wxPoint& pos,
    const wxSize& size, long style)
    : wxFrame(frame, wxID_ANY, title, pos, size, style)
{
    SetIcon(wxIcon(sample_xpm));

    // Make the "File" menu
    wxMenu *fileMenu = new wxMenu;
    fileMenu->Append(wxID_OPEN, wxT("&Open..."));
    fileMenu->AppendSeparator();
    fileMenu->Append(wxID_EXIT, wxT("E&xit\tALT-X"));
    // Make the "Help" menu
    wxMenu *helpMenu = new wxMenu;
    helpMenu->Append(wxID_HELP, wxT("&About..."));

    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append(fileMenu, wxT("&File"));
    menuBar->Append(helpMenu, wxT("&Help"));
    SetMenuBar(menuBar);

    m_canvas = new TestGLCanvas(this, wxID_ANY, wxDefaultPosition,
        wxSize(300, 300), wxSUNKEN_BORDER);
}

// File|Open... command
void PenguinFrame::OnMenuFileOpen( wxCommandEvent& WXUNUSED(event) )
{
    wxString filename = wxFileSelector(wxT("Choose DXF Model"), wxT(""), wxT(""), wxT(""),
#if wxUSE_ZLIB
        wxT("DXF Drawing (*.dxf;*.dxf.gz)|*.dxf;*.dxf.gz|All files (*.*)|*.*"),
#else
        wxT("DXF Drawing (*.dxf)|*.dxf)|All files (*.*)|*.*"),
#endif
        wxFD_OPEN);
    if (!filename.IsEmpty())
    {
        m_canvas->LoadDXF(filename);
        m_canvas->Refresh(false);
    }
}

// File|Exit command
void PenguinFrame::OnMenuFileExit( wxCommandEvent& WXUNUSED(event) )
{
    // true is to force the frame to close
    Close(true);
}

// Help|About... command
void PenguinFrame::OnMenuHelpAbout( wxCommandEvent& WXUNUSED(event) )
{
    wxMessageBox(wxT("OpenGL Penguin Sample (c) Robert Roebling, Sandro Sigala et al"));
}

// ---------------------------------------------------------------------------
// TestGLCanvas
// ---------------------------------------------------------------------------

BEGIN_EVENT_TABLE(TestGLCanvas, wxGLCanvas)
    EVT_SIZE(TestGLCanvas::OnSize)
    EVT_PAINT(TestGLCanvas::OnPaint)
    EVT_ERASE_BACKGROUND(TestGLCanvas::OnEraseBackground)
    EVT_MOUSE_EVENTS(TestGLCanvas::OnMouse)
END_EVENT_TABLE()

TestGLCanvas::TestGLCanvas(wxWindow *parent, wxWindowID id,
    const wxPoint& pos, const wxSize& size, long style, const wxString& name)
    : wxGLCanvas(parent, id, pos, size, style|wxFULL_REPAINT_ON_RESIZE, name)
{
    m_gldata.initialized = false;

    // initialize view matrix
    m_gldata.beginx = 0.0f;
    m_gldata.beginy = 0.0f;
    m_gldata.zoom   = 45.0f;
    trackball(m_gldata.quat, 0.0f, 0.0f, 0.0f, 0.0f);
}

TestGLCanvas::~TestGLCanvas()
{
}

void TestGLCanvas::OnPaint( wxPaintEvent& WXUNUSED(event) )
{
    // must always be here
    wxPaintDC dc(this);

#ifndef __WXMOTIF__
    if (!GetContext()) return;
#endif

    SetCurrent();

    // Initialize OpenGL
    if (!m_gldata.initialized)
    {
        InitGL();
        ResetProjectionMode();
        m_gldata.initialized = true;
    }

    // Clear
    glClearColor( 0.3f, 0.4f, 0.6f, 1.0f );
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    // Transformations
    glLoadIdentity();
    glTranslatef( 0.0f, 0.0f, -20.0f );
    GLfloat m[4][4];
    build_rotmatrix( m, m_gldata.quat );
    glMultMatrixf( &m[0][0] );

    m_renderer.Render();

    // Flush
    glFlush();

    // Swap
    SwapBuffers();
}

void TestGLCanvas::OnSize(wxSizeEvent& event)
{
    // this is also necessary to update the context on some platforms
    wxGLCanvas::OnSize(event);
    // Reset the OpenGL view aspect
    ResetProjectionMode();
}

void TestGLCanvas::OnEraseBackground(wxEraseEvent& WXUNUSED(event))
{
    // Do nothing, to avoid flashing on MSW
}

// Load the DXF file.  If the zlib support is compiled in wxWidgets,
// supports also the ".dxf.gz" gzip compressed files.
void TestGLCanvas::LoadDXF(const wxString& filename)
{
    wxFileInputStream stream(filename);
    if (stream.Ok())
#if wxUSE_ZLIB
    {
        if (filename.Right(3).Lower() == wxT(".gz"))
        {
            wxZlibInputStream zstream(stream);
            m_renderer.Load(zstream);
        } else
        {
            m_renderer.Load(stream);
        }
    }
#else
    {
        m_renderer.Load(stream);
    }
#endif
}

void TestGLCanvas::OnMouse(wxMouseEvent& event)
{
    if (event.Dragging())
    {
        wxSize sz(GetClientSize());

        /* drag in progress, simulate trackball */
        float spin_quat[4];
        trackball(spin_quat,
            (2.0*m_gldata.beginx - sz.x) / sz.x,
            (sz.y - 2.0*m_gldata.beginy) / sz.y,
            (2.0*event.GetX() - sz.x)    / sz.x,
            (sz.y - 2.0*event.GetY())    / sz.y);

        add_quats(spin_quat, m_gldata.quat, m_gldata.quat);

        /* orientation has changed, redraw mesh */
        Refresh(false);
    }

    m_gldata.beginx = event.GetX();
    m_gldata.beginy = event.GetY();
}

void TestGLCanvas::InitGL()
{
    static const GLfloat light0_pos[4]   = { -50.0f, 50.0f, 0.0f, 0.0f };

    // white light
    static const GLfloat light0_color[4] = { 0.6f, 0.6f, 0.6f, 1.0f };

    static const GLfloat light1_pos[4]   = {  50.0f, 50.0f, 0.0f, 0.0f };

    // cold blue light
    static const GLfloat light1_color[4] = { 0.4f, 0.4f, 1.0f, 1.0f };

    /* remove back faces */
    glDisable(GL_CULL_FACE);
    glEnable(GL_DEPTH_TEST);

    /* speedups */
    glEnable(GL_DITHER);
    glShadeModel(GL_SMOOTH);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_FASTEST);
    glHint(GL_POLYGON_SMOOTH_HINT, GL_FASTEST);

    /* light */
    glLightfv(GL_LIGHT0, GL_POSITION, light0_pos);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light0_color);
    glLightfv(GL_LIGHT1, GL_POSITION, light1_pos);
    glLightfv(GL_LIGHT1, GL_DIFFUSE,  light1_color);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
    glEnable(GL_LIGHTING);

    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
    glEnable(GL_COLOR_MATERIAL);
}

void TestGLCanvas::ResetProjectionMode()
{
    int w, h;
    GetClientSize(&w, &h);
#ifndef __WXMOTIF__
    if ( GetContext() )
#endif
    {
        SetCurrent();
        glViewport(0, 0, (GLint) w, (GLint) h);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluPerspective(45.0f, (GLfloat)w/h, 1.0, 100.0);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
    }
}
