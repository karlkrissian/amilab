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
#include "vtkCamera.h"
#include "vtkRenderer.h"
#include "vtkRenderWindow.h"
#include "vtkConeSource.h"
#include "vtkPolyDataMapper.h"
#include "vtkActor.h"
#include "vtkPolyDataReader.h"

#include "vtkRenderer.h"
#include "vtkRenderWindow.h"
#include "vtkRenderWindowInteractor.h"
#include "vtkVolume16Reader.h"
#include "vtkPolyDataMapper.h"
#include "vtkActor.h"
#include "vtkOutlineFilter.h"
#include "vtkCamera.h"
#include "vtkStripper.h"
#include "vtkLookupTable.h"
#include "vtkImageDataGeometryFilter.h"
#include "vtkProperty.h"
#include "vtkPolyDataNormals.h"
#include "vtkContourFilter.h"
#include "vtkImageData.h"
#include "vtkImageMapToColors.h"
#include "vtkImageActor.h"
//#include "vtkTesting.h"
//#include "vtkTestUtilities.h"

// the application icon
// #ifndef __WXMSW__
//     #include "mondrian.xpm"
// #endif

//class wxMedical3Frame;
#include "wxMedical3Frame.h"


// IDs for the controls and the menu commands
enum
{
    // menu items
    Minimal_Quit = 1,
    Minimal_About
};

#define MY_FRAME      101
#define MY_VTK_WINDOW 102

// the event tables connect the wxWindows events with the functions (event
// handlers) which process them. It can be also done at run-time, but for the
// simple menu events like this the static method is much simpler.
BEGIN_EVENT_TABLE(wxMedical3Frame, wxFrame)
    EVT_MENU(Minimal_Quit,  wxMedical3Frame::OnQuit)
    EVT_MENU(Minimal_About, wxMedical3Frame::OnAbout)
END_EVENT_TABLE()


/*
// 'Main program' equivalent: the program execution "starts" here
bool MyApp::OnInit()
{
    // create the main application window
    wxMedical3Frame *frame = new wxMedical3Frame(_T("wxWindows-VTK App"),
                                 wxPoint(50, 50), wxSize(450, 340));

    // and show it (the frames, unlike simple controls, are not shown when
    // created initially)
    frame->Show(TRUE);

    // success: wxApp::OnRun() will be called which will enter the main message
    // loop and the application will run. If we returned FALSE here, the
    // application would exit immediately.
    return TRUE;
}
*/

// frame constructor
wxMedical3Frame::wxMedical3Frame(vtkImageData_ptr image, const wxString& title, const wxPoint& pos, const wxSize& size)
       : wxFrame((wxFrame *)NULL, -1, title, pos, size)
{
#ifdef __WXMAC__
    // we need this in order to allow the about menu relocation, since ABOUT is
    // not the default id of the about menu
    wxApp::s_macAboutMenuItemId = Minimal_About;
#endif

    // set the frame icon
//     SetIcon(wxICON(mondrian));

  SetInput(image);

  m_mgr.SetManagedWindow(this);

    // create a menu bar
    wxMenu *menuFile = new wxMenu(_T(""), wxMENU_TEAROFF);

    // the "About" item should be in the help menu
    wxMenu *helpMenu = new wxMenu;
    helpMenu->Append(Minimal_About, _T("&About...\tCtrl-A"), _T("Show about dialog"));

    menuFile->Append(Minimal_Quit, _T("E&xit\tAlt-X"), _T("Quit this program"));

    // now append the freshly created menu to the menu bar...
    wxMenuBar *menuBar = new wxMenuBar();
    menuBar->Append(menuFile, _T("&File"));
    menuBar->Append(helpMenu, _T("&Help"));

    // ... and attach this menu bar to the frame
    SetMenuBar(menuBar);

#if wxUSE_STATUSBAR
    // create a status bar just for fun (by default with 1 pane only)
    CreateStatusBar(2);
    SetStatusText(_T("Drag the mouse here! (wxWindows 2.4.0)"));
#endif // wxUSE_STATUSBAR

   wxSize client_size = GetClientSize();

   wxAuiNotebook*_main_book = new wxAuiNotebook(this, wxID_ANY,
                                    wxPoint(client_size.x, client_size.y),
                                    wxDefaultSize,
                                    wxAUI_NB_TOP          |
                                    #ifndef __WXGTK__ 
                                      wxAUI_NB_TAB_SPLIT    |
                                    #endif
                                    wxAUI_NB_TAB_MOVE     |
                                    wxAUI_NB_SCROLL_BUTTONS
                                  );

//   wxBitmap page_bmp = wxArtProvider::GetBitmap(wxART_NORMAL_FILE, wxART_OTHER, wxSize(16,16));

  wxPanel* _prompt_panel = new wxPanel(_main_book, wxID_ANY,
                    wxDefaultPosition, wxDefaultSize,
                      wxCLIP_CHILDREN
                    |
                      wxTAB_TRAVERSAL
                    |
                      wxFULL_REPAINT_ON_RESIZE
                    // | wxNO_FULL_REPAINT_ON_RESIZE
                    );

  wxBoxSizer* sbox_sizer  = new wxBoxSizer( wxVERTICAL );

  _prompt_panel->SetSizer(sbox_sizer);

  _main_book->AddPage( _prompt_panel,  wxT("Console"), false );

  _main_book->Fit();
  m_mgr.AddPane(_main_book,  wxAuiPaneInfo()
                  .Name(wxT("Main Book"))
                  //.MinSize(wxSize(200,200))
                  .Center()
                  .MaximizeButton(true));

  m_mgr.Update();

  m_pVTKWindow = new wxVTKRenderWindowInteractor(_prompt_panel, MY_VTK_WINDOW);
  m_pVTKWindow->UseCaptureMouseOn();
  vtkRenderer* ren  = vtkRenderer::New();
  m_pVTKWindow->GetRenderWindow()->AddRenderer(ren);
  m_pVTKWindow->Enable(1);

  sbox_sizer->Add(m_pVTKWindow, 1, wxEXPAND | wxALL, 2);
//  _prompt_panel->Layout();

  //turn on mouse grabbing if possible
    ConstructVTK();
    ConfigureVTK();

}

wxMedical3Frame::~wxMedical3Frame()
{
  if(m_pVTKWindow) m_pVTKWindow->Delete();
  DestroyVTK();
}

void wxMedical3Frame::ConstructVTK()
{
  
}

void wxMedical3Frame::ConfigureVTK()
{
  // connect the render window and wxVTK window
  vtkRenderWindow *pRenderWindow = m_pVTKWindow->GetRenderWindow();

  aRenderer = vtkRenderer::New();
  pRenderWindow->AddRenderer(aRenderer);

  vtkVolume16Reader *v16 = NULL;
  if (!input.get())
  {
    #ifndef _MSC_VER
//     char* fname = vtkTestUtilities::ExpandDataFileName(0, 0, "Data/headsq/quarter");
//   
//     // The following reader is used to read a series of 2D slices (images)
//     // that compose the volume. The slice dimensions are set, and the
//     // pixel spacing. The data Endianness must also be specified. The
//     // reader usese the FilePrefix in combination with the slice number to
//     // construct filenames using the format FilePrefix.%d. (In this case
//     // the FilePrefix is the root name of the file: quarter.)
//     v16 = vtkVolume16Reader::New();
//       v16->SetDataDimensions(64,64);
//       v16->SetDataByteOrderToLittleEndian();
//       v16->SetFilePrefix ( fname );
//       v16->SetImageRange(1, 93);
//       v16->SetDataSpacing (3.2, 3.2, 1.5);
//     delete[] fname;
    #endif
    //input = v16->GetOutput();
  }

  // An isosurface, or contour value of 500 is known to correspond to
  // the skin of the patient. Once generated, a vtkPolyDataNormals
  // filter is is used to create normals for smooth surface shading
  // during rendering.  The triangle stripper is used to create triangle
  // strips from the isosurface; these render much faster on may
  // systems.
  vtkContourFilter *skinExtractor = vtkContourFilter::New();
    skinExtractor->SetInputData( this->input.get());
    skinExtractor->SetValue(0, 500);
  vtkPolyDataNormals *skinNormals = vtkPolyDataNormals::New();
    skinNormals->SetInputConnection(skinExtractor->GetOutputPort());
    skinNormals->SetFeatureAngle(60.0);
  vtkStripper *skinStripper = vtkStripper::New();
    skinStripper->SetInputConnection(skinNormals->GetOutputPort());
  vtkPolyDataMapper *skinMapper = vtkPolyDataMapper::New();
    skinMapper->SetInputConnection(skinStripper->GetOutputPort());
    skinMapper->ScalarVisibilityOff();
  vtkActor *skin = vtkActor::New();
    skin->SetMapper(skinMapper);
    skin->GetProperty()->SetDiffuseColor(1, .49, .25);
    skin->GetProperty()->SetSpecular(.3);
    skin->GetProperty()->SetSpecularPower(20);

  // An isosurface, or contour value of 1150 is known to correspond to
  // the skin of the patient. Once generated, a vtkPolyDataNormals
  // filter is is used to create normals for smooth surface shading
  // during rendering.  The triangle stripper is used to create triangle
  // strips from the isosurface; these render much faster on may
  // systems.
  vtkContourFilter *boneExtractor = vtkContourFilter::New();
    boneExtractor->SetInputData(input.get());
    boneExtractor->SetValue(0, 1150);
  vtkPolyDataNormals *boneNormals = vtkPolyDataNormals::New();
    boneNormals->SetInputConnection(boneExtractor->GetOutputPort());
    boneNormals->SetFeatureAngle(60.0);
  vtkStripper *boneStripper = vtkStripper::New();
    boneStripper->SetInputConnection(boneNormals->GetOutputPort());
  vtkPolyDataMapper *boneMapper = vtkPolyDataMapper::New();
    boneMapper->SetInputConnection(boneStripper->GetOutputPort());
    boneMapper->ScalarVisibilityOff();
  vtkActor *bone = vtkActor::New();
    bone->SetMapper(boneMapper);
    bone->GetProperty()->SetDiffuseColor(1, 1, .9412);

  // An outline provides context around the data.
  //
  vtkOutlineFilter *outlineData = vtkOutlineFilter::New();
    outlineData->SetInputData(input.get());
  vtkPolyDataMapper *mapOutline = vtkPolyDataMapper::New();
    mapOutline->SetInputConnection(outlineData->GetOutputPort());
  vtkActor *outline = vtkActor::New();
    outline->SetMapper(mapOutline);
    outline->GetProperty()->SetColor(0,0,0);

  // Now we are creating three orthogonal planes passing through the
  // volume. Each plane uses a different texture map and therefore has
  // diferent coloration.

  // Start by creatin a black/white lookup table.
  vtkLookupTable *bwLut = vtkLookupTable::New();
    bwLut->SetTableRange (0, 2000);
    bwLut->SetSaturationRange (0, 0);
    bwLut->SetHueRange (0, 0);
    bwLut->SetValueRange (0, 1);

  // Now create a lookup table that consists of the full hue circle
  // (from HSV).
  vtkLookupTable *hueLut = vtkLookupTable::New();
    hueLut->SetTableRange (0, 2000);
    hueLut->SetHueRange (0, 1);
    hueLut->SetSaturationRange (1, 1);
    hueLut->SetValueRange (1, 1);

  // Finally, create a lookup table with a single hue but having a range
  // in the saturation of the hue.
  vtkLookupTable *satLut = vtkLookupTable::New();
    satLut->SetTableRange (0, 2000);
    satLut->SetHueRange (.6, .6);
    satLut->SetSaturationRange (0, 1);
    satLut->SetValueRange (1, 1);

  // Create the first of the three planes. The filter vtkImageMapToColors
  // maps the data through the corresponding lookup table created above.  The
  // vtkImageActor is a type of vtkProp and conveniently displays an image on
  // a single quadrilateral plane. It does this using texture mapping and as
  // a result is quite fast. (Note: the input image has to be unsigned char
  // values, which the vtkImageMapToColors produces.) Note also that by
  // specifying the DisplayExtent, the pipeline requests data of this extent
  // and the vtkImageMapToColors only processes a slice of data.
  vtkImageMapToColors *saggitalColors = vtkImageMapToColors::New();
    saggitalColors->SetInputData(input.get());
    saggitalColors->SetLookupTable(bwLut);
  vtkImageActor *saggital = vtkImageActor::New();
    saggital->SetInputData(saggitalColors->GetOutput());
    saggital->SetDisplayExtent(32,32, 0,63, 0,92);

  // Create the second (axial) plane of the three planes. We use the
  // same approach as before except that the extent differs.
  vtkImageMapToColors *axialColors = vtkImageMapToColors::New();
    axialColors->SetInputData(input.get());
    axialColors->SetLookupTable(hueLut);
  vtkImageActor *axial = vtkImageActor::New();
    axial->SetInputData(axialColors->GetOutput());
    axial->SetDisplayExtent(0,63, 0,63, 46,46);

  // Create the third (coronal) plane of the three planes. We use 
  // the same approach as before except that the extent differs.
  vtkImageMapToColors *coronalColors = vtkImageMapToColors::New();
    coronalColors->SetInputData(input.get());
    coronalColors->SetLookupTable(satLut);
  vtkImageActor *coronal = vtkImageActor::New();
    coronal->SetInputData(coronalColors->GetOutput());
    coronal->SetDisplayExtent(0,63, 32,32, 0,92);

  // It is convenient to create an initial view of the data. The
  // FocalPoint and Position form a vector direction. Later on
  // (ResetCamera() method) this vector is used to position the camera
  // to look at the data in this direction.
  vtkCamera *aCamera = vtkCamera::New();
    aCamera->SetViewUp (0, 0, -1);
    aCamera->SetPosition (0, 1, 0);
    aCamera->SetFocalPoint (0, 0, 0);
    aCamera->ComputeViewPlaneNormal();

  // Actors are added to the renderer. 
  aRenderer->AddActor(outline);
  aRenderer->AddActor(saggital);
  aRenderer->AddActor(axial);
  aRenderer->AddActor(coronal);
  aRenderer->AddActor(axial);
  aRenderer->AddActor(coronal);
  aRenderer->AddActor(skin);
  aRenderer->AddActor(bone);

  // Turn off bone for this example.
  bone->VisibilityOff();

  // Set skin to semi-transparent.
  skin->GetProperty()->SetOpacity(0.5);

  // An initial camera view is created.  The Dolly() method moves 
  // the camera towards the FocalPoint, thereby enlarging the image.
  aRenderer->SetActiveCamera(aCamera);
  aRenderer->ResetCamera ();
  aCamera->Dolly(1.5);

  // Set a background color for the renderer and set the size of the
  // render window (expressed in pixels).
  aRenderer->SetBackground(1,1,1);
//  renWin->SetSize(640, 480);

  // Note that when camera movement occurs (as it does in the Dolly()
  // method), the clipping planes often need adjusting. Clipping planes
  // consist of two planes: near and far along the view direction. The 
  // near plane clips out objects in front of the plane; the far plane
  // clips out objects behind the plane. This way only what is drawn
  // between the planes is actually rendered.
  aRenderer->ResetCameraClippingRange ();

  if (v16!=NULL)
    v16->Delete();
  skinExtractor->Delete();
  skinNormals->Delete();
  skinStripper->Delete();
  skinMapper->Delete();
  skin->Delete();
  boneExtractor->Delete();
  boneNormals->Delete();
  boneStripper->Delete();
  boneMapper->Delete();
  bone->Delete();
  outlineData->Delete();
  mapOutline->Delete();
  outline->Delete();
  bwLut->Delete();
  hueLut->Delete();
  satLut->Delete();
  saggitalColors->Delete();
  saggital->Delete();
  axialColors->Delete();
  axial->Delete();
  coronalColors->Delete();
  coronal->Delete();
  aCamera->Delete();
}

void wxMedical3Frame::DestroyVTK()
{
  aRenderer->Delete();
}

// event handlers

void wxMedical3Frame::OnQuit(wxCommandEvent& WXUNUSED(event))
{
    // TRUE is to force the frame to close
    Close(TRUE);
}

void wxMedical3Frame::OnAbout(wxCommandEvent& WXUNUSED(event))
{
    wxString msg;
    msg.Printf( _T("This is the about dialog of wx-vtk sample.\n"));

    wxMessageBox(msg, _T("About wx-vtk"), wxOK | wxICON_INFORMATION, this);
}
