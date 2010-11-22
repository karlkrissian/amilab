/*=========================================================================

  Program:   Visualization Toolkit
  Module:    $RCSfile: GPURenderDemo.cxx,v $

  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
// VTK includes



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

  #include "vtkGPURayCasting.h"
  #include "vtkBoxWidget.h"
  #include "vtkCamera.h"
  #include "vtkCommand.h"
  #include "vtkColorTransferFunction.h"
  #include "vtkImageData.h"
  #include "vtkPiecewiseFunction.h"
  #include "vtkPlanes.h"
  #include "vtkRenderer.h"
  #include "vtkRenderWindow.h"
  #include "vtkRenderWindowInteractor.h"
  #include "vtkVolume.h"
  #include "vtkVolumeProperty.h"
  #include "vtkProperty.h"

#if (VTK_MAJOR_VERSION==5)&&(VTK_MINOR_VERSION>=6)
  #include "vtkGPUVolumeRayCastMapper.h"
  #define VolRenMapper vtkGPUVolumeRayCastMapper
  #define HAS_GPU
#else
  #include "vtkVolumeRayCastMapper.h"
  #define VolRenMapper vtkVolumeRayCastMapper
#endif


#define MY_FRAME      101
#define MY_VTK_WINDOW 102

BEGIN_EVENT_TABLE(vtkGPURayCasting, wxFrame)
//    EVT_MENU(Minimal_Quit,  wxMedical3Frame::OnQuit)
//    EVT_MENU(Minimal_About, wxMedical3Frame::OnAbout)
END_EVENT_TABLE()

  // FB: comment for testing svn

  // Callback for moving the planes from the box widget to the mapper
  class vtkBoxWidgetCallback : public vtkCommand
  {
  public:
    static vtkBoxWidgetCallback *New()
      { return new vtkBoxWidgetCallback; }
    virtual void Execute(vtkObject *caller, unsigned long, void*)
      {
        vtkBoxWidget *widget = reinterpret_cast<vtkBoxWidget*>(caller);
        if (this->Mapper)
          {
          vtkPlanes *planes = vtkPlanes::New();
          widget->GetPlanes(planes);
          this->Mapper->SetClippingPlanes(planes);
          planes->Delete();
          }
      }

    void SetMapper(VolRenMapper* m) 
      { this->Mapper = m; }

  protected:
    vtkBoxWidgetCallback() 
      { this->Mapper = 0; }

    VolRenMapper *Mapper;
  };


  /*
  cout << "Usage: " << endl;
  cout << endl;
  cout << "  GPURenderDemo <options>" << endl;
  cout << endl;
  cout << "where options may include: " << endl;
  cout << endl;
  cout << "  -DICOM <directory>" << endl;
  cout << "  -VTI <filename>" << endl;
  cout << "  -MHA <filename>" << endl;
  cout << "  -VTK <filename>" << endl;
  cout << "  -DependentComponents" << endl;
  cout << "  -Clip" << endl;
  cout << "  -MIP <window> <level>" << endl;
  cout << "  -CompositeRamp <window> <level>" << endl;
  cout << "  -CompositeShadeRamp <window> <level>" << endl;
  cout << "  -CT_Skin" << endl;
  cout << "  -CT_Bone" << endl;
  cout << "  -CT_Muscle" << endl;
  cout << "  -FrameRate <rate>" << endl;
  cout << "  -DataReduction <factor>" << endl;
  cout << endl;
  cout << "You must use either the -DICOM option to specify the directory where" << endl;
  cout << "the data is located or the -VTI or -MHA option to specify the path of a .vti file." << endl;
  cout << endl;
  cout << "By default, the program assumes that the file has independent components," << endl;
  cout << "use -DependentComponents to specify that the file has dependent components." << endl;
  cout << endl;
  cout << "Use the -Clip option to display a cube widget for clipping the volume." << endl;
  cout << "Use the -FrameRate option with a desired frame rate (in frames per second)" << endl;
  cout << "which will control the interactive rendering rate." << endl;
  cout << "Use the -DataReduction option with a reduction factor (greater than zero and" << endl;
  cout << "less than one) to reduce the data before rendering." << endl;
  cout << "Use one of the remaining options to specify the blend function" << endl;
  cout << "and transfer functions. The -MIP option utilizes a maximum intensity" << endl;
  cout << "projection method, while the others utilize compositing. The" << endl;
  cout << "-CompositeRamp option is unshaded compositing, while the other" << endl;
  cout << "compositing options employ shading." << endl;
  cout << endl;
  cout << "Note: MIP, CompositeRamp, CompositeShadeRamp, CT_Skin, CT_Bone," << endl;
  cout << "and CT_Muscle are appropriate for DICOM data. MIP, CompositeRamp," << endl;
  cout << "and RGB_Composite are appropriate for RGB data." << endl;
  cout << endl;
  cout << "Example: GPURenderDemo -DICOM CTNeck -MIP 4096 1024" << endl;
  cout << endl;
  */

    
vtkGPURayCasting::vtkGPURayCasting(vtkImageData_ptr image, bool clipval) : wxFrame((wxFrame *)NULL, -1, wxT("VTK GPU RayCasting"), wxPoint(50, 50), wxSize(450, 340))
{
  blendType = 0;
  opacityWindow = 4096;
  opacityLevel = 2048;
  /// clip 0|1
  clip = clipval; 
  /// within [0,1]
  reductionFactor = 1.0;
  /// within [0.01,60]
  frameRate = 10.0;
  ///
  independentComponents=true;
  
  SetInput(image);
  Display();
//  ConfigureVTK();
}

vtkGPURayCasting::~vtkGPURayCasting()
{
  if(m_pVTKWindow) m_pVTKWindow->Delete();
  DestroyVTK();
}


/*
void wxMedical3Frame::ConfigureVTK()
{
  // connect the render window and wxVTK window
  vtkRenderWindow *pRenderWindow = m_pVTKWindow->GetRenderWindow();

  aRenderer = vtkRenderer::New();
  pRenderWindow->AddRenderer(aRenderer);

  vtkVolume16Reader *v16 = NULL;
  if (!input.get())
  {
    char* fname = vtkTestUtilities::ExpandDataFileName(0, 0, "Data/headsq/quarter");
  
    // The following reader is used to read a series of 2D slices (images)
    // that compose the volume. The slice dimensions are set, and the
    // pixel spacing. The data Endianness must also be specified. The
    // reader usese the FilePrefix in combination with the slice number to
    // construct filenames using the format FilePrefix.%d. (In this case
    // the FilePrefix is the root name of the file: quarter.)
    v16 = vtkVolume16Reader::New();
      v16->SetDataDimensions(64,64);
      v16->SetDataByteOrderToLittleEndian();
      v16->SetFilePrefix ( fname );
      v16->SetImageRange(1, 93);
      v16->SetDataSpacing (3.2, 3.2, 1.5);
    delete[] fname;
    //input = v16->GetOutput();
  }

  // An isosurface, or contour value of 500 is known to correspond to
  // the skin of the patient. Once generated, a vtkPolyDataNormals
  // filter is is used to create normals for smooth surface shading
  // during rendering.  The triangle stripper is used to create triangle
  // strips from the isosurface; these render much faster on may
  // systems.
  vtkContourFilter *skinExtractor = vtkContourFilter::New();
    skinExtractor->SetInput( this->input.get());
    skinExtractor->SetValue(0, 500);
  vtkPolyDataNormals *skinNormals = vtkPolyDataNormals::New();
    skinNormals->SetInput(skinExtractor->GetOutput());
    skinNormals->SetFeatureAngle(60.0);
  vtkStripper *skinStripper = vtkStripper::New();
    skinStripper->SetInput(skinNormals->GetOutput());
  vtkPolyDataMapper *skinMapper = vtkPolyDataMapper::New();
    skinMapper->SetInput(skinStripper->GetOutput());
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
    boneExtractor->SetInput(input.get());
    boneExtractor->SetValue(0, 1150);
  vtkPolyDataNormals *boneNormals = vtkPolyDataNormals::New();
    boneNormals->SetInput(boneExtractor->GetOutput());
    boneNormals->SetFeatureAngle(60.0);
  vtkStripper *boneStripper = vtkStripper::New();
    boneStripper->SetInput(boneNormals->GetOutput());
  vtkPolyDataMapper *boneMapper = vtkPolyDataMapper::New();
    boneMapper->SetInput(boneStripper->GetOutput());
    boneMapper->ScalarVisibilityOff();
  vtkActor *bone = vtkActor::New();
    bone->SetMapper(boneMapper);
    bone->GetProperty()->SetDiffuseColor(1, 1, .9412);

  // An outline provides context around the data.
  //
  vtkOutlineFilter *outlineData = vtkOutlineFilter::New();
    outlineData->SetInput(input.get());
  vtkPolyDataMapper *mapOutline = vtkPolyDataMapper::New();
    mapOutline->SetInput(outlineData->GetOutput());
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
    saggitalColors->SetInput(input.get());
    saggitalColors->SetLookupTable(bwLut);
  vtkImageActor *saggital = vtkImageActor::New();
    saggital->SetInput(saggitalColors->GetOutput());
    saggital->SetDisplayExtent(32,32, 0,63, 0,92);

  // Create the second (axial) plane of the three planes. We use the
  // same approach as before except that the extent differs.
  vtkImageMapToColors *axialColors = vtkImageMapToColors::New();
    axialColors->SetInput(input.get());
    axialColors->SetLookupTable(hueLut);
  vtkImageActor *axial = vtkImageActor::New();
    axial->SetInput(axialColors->GetOutput());
    axial->SetDisplayExtent(0,63, 0,63, 46,46);

  // Create the third (coronal) plane of the three planes. We use 
  // the same approach as before except that the extent differs.
  vtkImageMapToColors *coronalColors = vtkImageMapToColors::New();
    coronalColors->SetInput(input.get());
    coronalColors->SetLookupTable(satLut);
  vtkImageActor *coronal = vtkImageActor::New();
    coronal->SetInput(coronalColors->GetOutput());
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
*/

void vtkGPURayCasting::DestroyVTK()
{
  renderer->Delete();
}


void vtkGPURayCasting::SetInput( vtkImageData_ptr image)
{
  input=image;
}

bool vtkGPURayCasting::Display()
{

  ///
  m_pVTKWindow = new wxVTKRenderWindowInteractor(this, MY_VTK_WINDOW);
  //turn on mouse grabbing if possible
  m_pVTKWindow->UseCaptureMouseOn();

  // Create the renderer, render window and interactor
  vtkRenderWindow *renWin = m_pVTKWindow->GetRenderWindow();
  renderer = vtkRenderer::New();
  renWin->AddRenderer(renderer);

  // Connect it all. Note that funny arithematic on the 
  // SetDesiredUpdateRate - the vtkRenderWindow divides it
  // allocated time across all renderers, and the renderer
  // divides it time across all props. If clip is
  // true then there are two props
//  vtkRenderWindowInteractor *iren = vtkRenderWindowInteractor::New();
//  iren->SetRenderWindow(renWin);
  m_pVTKWindow->SetDesiredUpdateRate(frameRate / (1+clip) );
  //m_pVTKWindow->GetInteractorStyle()->SetDefaultRenderer(renderer);

  // Verify that we actually have a volume
  int dim[3];
  input->GetDimensions(dim);
  if ( dim[0] < 2 ||
      dim[1] < 2 ||
      dim[2] < 2 )
  {
    cout << "Error loading data!" << endl;
    return false;    
  }
  
  // no resample here
  /*
  vtkImageResample *resample = vtkImageResample::New();
  if ( reductionFactor < 1.0 )
    {
      resample->SetInputConnection( reader->GetOutputPort() );
      resample->SetAxisMagnificationFactor(0, reductionFactor);
      resample->SetAxisMagnificationFactor(1, reductionFactor);
      resample->SetAxisMagnificationFactor(2, reductionFactor);    
    }
    */
  
  // Create our volume and mapper
  vtkVolume *volume = vtkVolume::New();
  VolRenMapper *mapper = VolRenMapper::New();
  
  // Add a box widget if the clip option was selected
  vtkBoxWidget *box = vtkBoxWidget::New();
  if (clip)
    {
    box->SetInteractor(m_pVTKWindow);
    box->SetPlaceFactor(1.01);
/*
if ( reductionFactor < 1.0 )
      {      
      box->SetInput(resample->GetOutput());
      }
    else
      {
        */
      box->SetInput(input.get());
//      }
    
    box->SetDefaultRenderer(renderer);
    box->InsideOutOn();
    box->PlaceWidget();
    vtkBoxWidgetCallback *callback = vtkBoxWidgetCallback::New();
    callback->SetMapper(mapper);
    box->AddObserver(vtkCommand::InteractionEvent, callback);
    callback->Delete();
    box->EnabledOn();
    box->GetSelectedFaceProperty()->SetOpacity(0.0);
    }

/*
if ( reductionFactor < 1.0 )
    {
    mapper->SetInputConnection( resample->GetOutputPort() );
    }
  else
    {
      */
    mapper->SetInput( input.get() );
//    }
    
  
  // Set the sample distance on the ray to be 1/2 the average spacing
  double spacing[3];
/*
  if ( reductionFactor < 1.0 )
    {
    resample->GetOutput()->GetSpacing(spacing);
    }
  else
    {
      */
    input->GetSpacing(spacing);
//    }
  
//  mapper->SetSampleDistance( (spacing[0]+spacing[1]+spacing[2])/6.0 );
//  mapper->SetMaximumImageSampleDistance(10.0);
  

  // Create our transfer function
  vtkColorTransferFunction *colorFun = vtkColorTransferFunction::New();
  vtkPiecewiseFunction *opacityFun = vtkPiecewiseFunction::New();
  
  // Create the property and attach the transfer functions
  vtkVolumeProperty *property = vtkVolumeProperty::New();
  property->SetIndependentComponents(independentComponents);
  property->SetColor( colorFun );
  property->SetScalarOpacity( opacityFun );
  property->SetInterpolationTypeToLinear();

  // connect up the volume to the property and the mapper
  volume->SetProperty( property );
  volume->SetMapper( mapper );

  // Depending on the blend type selected as a command line option, 
  // adjust the transfer function
  switch ( blendType )
    {
    // MIP
    // Create an opacity ramp from the window and level values.
    // Color is white. Blending is MIP.
    case 0:
      colorFun->AddRGBSegment(0.0, 1.0, 1.0, 1.0, 255.0, 1.0, 1.0, 1.0 );
      opacityFun->AddSegment( opacityLevel - 0.5*opacityWindow, 0.0, 
                              opacityLevel + 0.5*opacityWindow, 1.0 );
      mapper->SetBlendModeToMaximumIntensity();
      break;
      
    // CompositeRamp
    // Create a ramp from the window and level values. Use compositing
    // without shading. Color is a ramp from black to white.
    case 1:
      colorFun->AddRGBSegment(opacityLevel - 0.5*opacityWindow, 0.0, 0.0, 0.0, 
                              opacityLevel + 0.5*opacityWindow, 1.0, 1.0, 1.0 );
      opacityFun->AddSegment( opacityLevel - 0.5*opacityWindow, 0.0, 
                              opacityLevel + 0.5*opacityWindow, 1.0 );
      mapper->SetBlendModeToComposite();
      property->ShadeOff();
      break;
      
    // CompositeShadeRamp
    // Create a ramp from the window and level values. Use compositing
    // with shading. Color is white.
    case 2:
      colorFun->AddRGBSegment(0.0, 1.0, 1.0, 1.0, 255.0, 1.0, 1.0, 1.0 );
      opacityFun->AddSegment( opacityLevel - 0.5*opacityWindow, 0.0, 
                              opacityLevel + 0.5*opacityWindow, 1.0 );
      mapper->SetBlendModeToComposite();
      property->ShadeOn();
      break;

    // CT_Skin
    // Use compositing and functions set to highlight skin in CT data
    // Not for use on RGB data
    case 3:
      colorFun->AddRGBPoint( -3024, 0, 0, 0, 0.5, 0.0 );
      colorFun->AddRGBPoint( -1000, .62, .36, .18, 0.5, 0.0 );
      colorFun->AddRGBPoint( -500, .88, .60, .29, 0.33, 0.45 );
      colorFun->AddRGBPoint( 3071, .83, .66, 1, 0.5, 0.0 );
      
      opacityFun->AddPoint(-3024, 0, 0.5, 0.0 );
      opacityFun->AddPoint(-1000, 0, 0.5, 0.0 );
      opacityFun->AddPoint(-500, 1.0, 0.33, 0.45 );
      opacityFun->AddPoint(3071, 1.0, 0.5, 0.0);

      mapper->SetBlendModeToComposite();
      property->ShadeOn();
      property->SetAmbient(0.1);
      property->SetDiffuse(0.9);
      property->SetSpecular(0.2);
      property->SetSpecularPower(10.0);
      property->SetScalarOpacityUnitDistance(0.8919);
      break;
      
    // CT_Bone
    // Use compositing and functions set to highlight bone in CT data
    // Not for use on RGB data
    case 4:
      colorFun->AddRGBPoint( -3024, 0, 0, 0, 0.5, 0.0 );
      colorFun->AddRGBPoint( -16, 0.73, 0.25, 0.30, 0.49, .61 );
      colorFun->AddRGBPoint( 641, .90, .82, .56, .5, 0.0 );
      colorFun->AddRGBPoint( 3071, 1, 1, 1, .5, 0.0 );
      
      opacityFun->AddPoint(-3024, 0, 0.5, 0.0 );
      opacityFun->AddPoint(-16, 0, .49, .61 );
      opacityFun->AddPoint(641, .72, .5, 0.0 );
      opacityFun->AddPoint(3071, .71, 0.5, 0.0);

      mapper->SetBlendModeToComposite();
      property->ShadeOn();
      property->SetAmbient(0.1);
      property->SetDiffuse(0.9);
      property->SetSpecular(0.2);
      property->SetSpecularPower(10.0);
      property->SetScalarOpacityUnitDistance(0.8919);
      break;
      
    // CT_Muscle
    // Use compositing and functions set to highlight muscle in CT data
    // Not for use on RGB data
    case 5:
      colorFun->AddRGBPoint( -3024, 0, 0, 0, 0.5, 0.0 );
      colorFun->AddRGBPoint( -155, .55, .25, .15, 0.5, .92 );
      colorFun->AddRGBPoint( 217, .88, .60, .29, 0.33, 0.45 );
      colorFun->AddRGBPoint( 420, 1, .94, .95, 0.5, 0.0 );
      colorFun->AddRGBPoint( 3071, .83, .66, 1, 0.5, 0.0 );
      
      opacityFun->AddPoint(-3024, 0, 0.5, 0.0 );
      opacityFun->AddPoint(-155, 0, 0.5, 0.92 );
      opacityFun->AddPoint(217, .68, 0.33, 0.45 );
      opacityFun->AddPoint(420,.83, 0.5, 0.0);
      opacityFun->AddPoint(3071, .80, 0.5, 0.0);

      mapper->SetBlendModeToComposite();
      property->ShadeOn();
      property->SetAmbient(0.1);
      property->SetDiffuse(0.9);
      property->SetSpecular(0.2);
      property->SetSpecularPower(10.0);
      property->SetScalarOpacityUnitDistance(0.8919);
      break;
      
    // RGB_Composite
    // Use compositing and functions set to highlight red/green/blue regions
    // in RGB data. Not for use on single component data
    case 6:
      opacityFun->AddPoint(0, 0.0);
      opacityFun->AddPoint(5.0, 0.0);
      opacityFun->AddPoint(30.0, 0.05);
      opacityFun->AddPoint(31.0, 0.0);
      opacityFun->AddPoint(90.0, 0.0);
      opacityFun->AddPoint(100.0, 0.3);
      opacityFun->AddPoint(110.0, 0.0);
      opacityFun->AddPoint(190.0, 0.0);
      opacityFun->AddPoint(200.0, 0.4);
      opacityFun->AddPoint(210.0, 0.0);
      opacityFun->AddPoint(245.0, 0.0);
      opacityFun->AddPoint(255.0, 0.5);

      mapper->SetBlendModeToComposite();
      property->ShadeOff();
      property->SetScalarOpacityUnitDistance(1.0);
      break;
    default:
      vtkGenericWarningMacro("Unknown blend type.");
      break;
    }
  
  // Set the default window size
//  renWin->SetSize(600,600);
//  renWin->Render();

/*
#ifdef HAS_GPU
  if ( !mapper->IsRenderSupported(renWin, property) )
    {
      cout << "This mapper is unsupported on this platform" << endl;
      return false;
    }
#endif
*/

  // Add the volume to the scene
  renderer->AddVolume( volume );
  renderer->ResetCamera();

  // interact with data
//  renWin->Render();
//  m_pVTKWindow->Start();
  
  opacityFun->Delete();
  colorFun->Delete();
  property->Delete();

/*
  box->Delete();
  volume->Delete();
  */

//  mapper->Delete();
//  resample->Delete();
//  renWin->Delete();
//  iren->Delete();

  return true;
  
}

