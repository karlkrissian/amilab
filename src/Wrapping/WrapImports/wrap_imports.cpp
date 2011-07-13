//
// C++ Implementation: wrap_imports
//
// Description: 
// Description:
//
//
// Author: Karl Krissian <>, (C) 2009
//
// Copyright: See COPYING file that comes with this distribution
//
//



#include "AMILabConfig.h"

#ifdef AMI_WRAP_MICRONTRACKER
  //#include "wrap_Ultrasound.h"
  #include "addwrap_us.h"
#endif

#include "paramlist.h"
#include "wrapfunctions.hpp"
#include "VarContexts.hpp"
//#include "wrapfunctions_draw.h"
#include "wrap_imports.h"
#include "ami_class.h"
#include "ami_object.h"
//#include "wrap_imagedraw.h"


#include "wrap_MainFrame.h"
#include "wrap_wxDrawingWindow.h"


#include "wrapSystem.h"
#include "wrapITK.h"
#include "wrapAMIFluid.h"
#include "wrapFilters.h"
#include "wrap_wxsamples.h"
#include "wrap_wxfunctions.h"


#include "wrap_parampanel.h"
#include "wrap_varlist.h"
#include "wrap_varvector.h"
#include "wrap_File.h"



/*
#include "wrap_wxWindow.h"
#include "wrap_wxSize.h"
#include "wrap_wxColour.h"
#include "wrap_wxImage.h"
#include "wrap_wxBitmap.h"
#include "wrap_wxHtmlWindow.h"
#include "wrap_wxString.h"
#include "wrap_wxFileName.h"
#include "wrap_wxAuiPaneInfo.h"
#include "wrap_wxAuiToolBar.h"
#include "wrap_wxButton.h"
#include "wrap_wxBitmapButton.h"
#include "wrap_wxBoxSizer.h"
#include "wrap_wxSizerFlags.h"
#include "wrap_wxPanel.h"
#include "wrap_wxStaticBox.h"
#include "wrap_wxStaticBoxSizer.h"
#include "wrap_wxAmiEventHandler.h"

#include "wrap_wxRect.h"
#include "wrap_wxPoint.h"
#include "wrap_wxFrame.h"
#include "wrap_wxToolBar.h"
*/
#include "addwrap_wx.h"
#include "addwrap_algorithms.h"

#ifdef AMI_WRAP_MICRONTRACKER
  #include "addwrap_mt.h"
  #include "wrapMT.h"
#endif




#include "wrap_vtkLevelSets.h"

#include "wrap_wxEditor.h"

#include "MainFrame.h"

#include "wrap_ReadRawImages.h"
#include "wrap_ImageExtent.h"
#include "wrap_SurfacePoly.h"
#include "wrap_DessinImage.h"
#include "wrap_AnalyticFunctionBase.h"
#include "wrap_AnalyticLine.h"
#include "wrap_AnalyticCircle.h"
#include "wrap_AnalyticStraightVessel2D.h"
#include "wrap_AnalyticRing2D.h"
#include "wrap_AnalyticPlane.h"
#include "wrap_AnalyticCube.h"
#include "wrap_AnalyticCylinder.h"
#include "wrap_AnalyticSphere.h"
#include "wrap_AnalyticTorus.h"
#include "wrap_ComputePartialVolume.h"
#include "wrapSubPixel2D.h"
#include "wrap_SubVoxel3D.h"
#include "wrap_Viewer3D.h"
#include "wrap_GLTransfMatrix.h"

#include "wrap_dwControlPoint.h"
#include "wrap_dwCurve.h"
#include "wrap_dwControlledCurve.h"

#include "wrap_stdvector.h"

//#include "wrap_TestTemplateClass__LT__int__GT__.h"

extern VarContexts  Vars;
extern MainFrame*   GB_main_wxFrame;

/// global Null variable
Variable<int>::ptr nullvar(new Variable<int>(boost::shared_ptr<int>(new int(NULL))));

/**
 * Function to check if the next parameter to parse is the pre-defined NULL variable
 **/
bool CheckNullVar(ParamList* _p, int _n)
{
  if (_n>=_p->GetNumParam())  return false;
  boost::shared_ptr<Variable<int> > var = boost::dynamic_pointer_cast<Variable<int> >(_p->GetParam(_n));
  if (!var.get()) return false;
  return var->Pointer().get() == nullvar->Pointer().get();
}

/**
 * Default wrapping
 */
void AddWrapImports()
{

  AddWrapWxWidgets();

  AddWrapAlgorithms();
#ifdef AMI_WRAP_MICRONTRACKER
  AddWrapMicronTracker();
#endif
#ifdef AMI_WRAP_MICRONTRACKER
  AddWrapUltrasound();
#endif
  AddWrapAmilab();
  AddWrapIO();
  AddWrapImage();
  AddWrapSurface();
  AddWrapDessinImage();
  AddWrapViewer3D();
  AddWrapGLTransfMatrix();
  AddWrapBasicTypes();
  AddWrapTestTemplateClass();

  // Create new instance of the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("ami_import");

  // Set the object context
  Variables::ptr previous_ocontext = Vars.GetObjectContext();
  Vars.SetObjectContext(amiobject->GetContext());

//  ADDOBJECTVAR_NAME(C_wrap_procedure,"ImageDraw",  wrap_ImageDraw);

  WrapClass_wxDrawingWindow::AddVar_wxDrawingWindow(amiobject->GetContext());
  WrapClass_ParamPanel     ::AddVar_ParamPanel     (amiobject->GetContext());

  WrapClass_AnalyticFunctionBase::AddVar_AnalyticFunctionBase(amiobject->GetContext());
  WrapClass_AnalyticCircle::AddVar_AnalyticCircle(            amiobject->GetContext());
  WrapClass_AnalyticLine::AddVar_AnalyticLine(                amiobject->GetContext());
  WrapClass_AnalyticStraightVessel2D::AddVar_AnalyticStraightVessel2D( amiobject->GetContext());
  WrapClass_AnalyticRing2D::AddVar_AnalyticRing2D(            amiobject->GetContext());
  WrapClass_AnalyticPlane::AddVar_AnalyticPlane(              amiobject->GetContext());
  WrapClass_AnalyticCube::AddVar_AnalyticCube(                amiobject->GetContext());
  WrapClass_AnalyticCylinder::AddVar_AnalyticCylinder(        amiobject->GetContext());
  WrapClass_AnalyticSphere::AddVar_AnalyticSphere(            amiobject->GetContext());
  WrapClass_AnalyticTorus::AddVar_AnalyticTorus(              amiobject->GetContext());
  WrapClass_ComputePV:: AddVar_ComputePV(                     amiobject->GetContext());
  
  WrapClass_SubPixel2D::AddVar_SubPixel2D(amiobject->GetContext());
  
  WrapClass_SubVoxel3D::AddVar_SubVoxel3D(amiobject->GetContext());

  WrapClass_vtkLevelSets  ::AddVar_vtkLevelSets(amiobject->GetContext());


  ADDOBJECTVAR_NAME(C_wrap_procedure,  "System",      wrap_System);
  ADDOBJECTVAR_NAME(C_wrap_procedure,  "ITK",         wrap_ITK);
  ADDOBJECTVAR_NAME(C_wrap_procedure,  "AMIFluid",    wrap_AMIFluid);
  ADDOBJECTVAR_NAME(C_wrap_procedure,  "Filters",     wrap_Filters);
  ADDOBJECTVAR_NAME(C_wrap_procedure,  "WxSamples",   wrap_wxsamples);
  //ADDOBJECTVAR_NAME(C_wrap_varfunction,"WxFunctions", wrap_wxfunctions);

  // Restore the object context
  Vars.SetObjectContext(previous_ocontext);

  // 3. add the variables to this instance
  Vars.AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject);
}

void AddWrapWxWidgets()
{

  // Create a new context (or namespace)
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wx");

  // Add classes to wx context
  wrap_wx_classes(amiobject->GetContext());

  ADDLOCAL_OBJECTVAR_NAME(amiobject,C_wrap_varfunction,
                          "LaunchDefaultBrowser",
                          wrap_LaunchDefaultBrowser);

  ADDLOCAL_OBJECTVAR_NAME(amiobject,C_wrap_varfunction,"FromWxString", wrap_FromWxString);

  // Add wx context to builtin
  Vars.GetBuiltinContext()->AddVar<AMIObject>( amiobject->GetName().c_str(),
      amiobject,Vars.GetBuiltinContext());

}

void AddWrapAlgorithms()
{

  // Create a new context (or namespace)
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("algorithms");

  // Add classes to wx context
  wrap_algorithms_classes(amiobject->GetContext());

  // Add wx context to builtin
  Vars.GetBuiltinContext()->AddVar<AMIObject>( amiobject->GetName().c_str(), 
      amiobject,Vars.GetBuiltinContext());

}


#ifdef AMI_WRAP_MICRONTRACKER
  void AddWrapMicronTracker()
  {
    AddWrapMT();
  }
  void AddWrapUltrasound()
  {
    wrap_us_classes( Vars.GetBuiltinContext());

    //WrapClass_Ultrasound::AddVar_Ultrasound( Vars.GetBuiltinContext());
  }
#endif

/*#ifdef AMI_WRAP_MICRONTRACKER
  void AddWrapUltrasound()
  {
    WrapClass_Ultrasound::AddVar_Ultrasound( Vars.GetBuiltinContext());
  }
#endif*/


void AddWrapAmilab()
{

  BasicVariable::ptr vartrue  = AMILabType<bool>::CreateVar(true);
  BasicVariable::ptr varfalse = AMILabType<bool>::CreateVar(false);

  Vars.GetBuiltinContext()->AddVar( "true",vartrue,Vars.GetBuiltinContext());
  Vars.GetBuiltinContext()->AddVar( "false",varfalse,Vars.GetBuiltinContext());

  // NULL variable
  Vars.GetBuiltinContext()->AddVar( "NULL",nullvar,Vars.GetBuiltinContext());

  // Create new instance of the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("ami");

  WrapClass_wxEditor::AddVar_wxEditor( amiobject->GetContext());

  // Add the MainFrame as an object
  BasicVariable::ptr mainframe_var = WrapClass_MainFrame::CreateVar(GB_main_wxFrame);
  amiobject->GetContext()->AddVar("MainFrame", mainframe_var, amiobject->GetContext());

  WrapClass_dwControlPoint   ::AddVar_dwControlPoint(    amiobject->GetContext());
  WrapClass_dwCurve          ::AddVar_dwCurve(           amiobject->GetContext());
  WrapClass_dwControlledCurve::AddVar_dwControlledCurve( amiobject->GetContext());

  // 3. add the variables to this instance
  Vars.GetBuiltinContext()->AddVar<AMIObject>( amiobject->GetName().c_str(),
      amiobject,Vars.GetBuiltinContext());


}

void AddWrapIO()
{
  // Create new instance of the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("IO");

  AddVar_ReadRawImages2D(     amiobject->GetContext());
  AddVar_ReadRawImage3D(      amiobject->GetContext());
  AddVar_ReadRawVectImage3D(  amiobject->GetContext());

  // 3. add the variables to this instance
  Vars.GetBuiltinContext()->AddVar<AMIObject>( amiobject->GetName().c_str(),
    amiobject,
    Vars.GetBuiltinContext());
}


//--------------------------------------------
void AddWrapImage()
{
  // Create new instance of the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("image");

  AddVar_ImageExtent(     amiobject->GetContext());

  // 3. add the variables to this instance
  Vars.GetBuiltinContext()->AddVar<AMIObject>( amiobject->GetName().c_str(),
    amiobject,
    Vars.GetBuiltinContext());
}

//--------------------------------------------
void AddWrapSurface()
{
  WrapClass_SurfacePoly::AddVar_SurfacePoly( Vars.GetBuiltinContext());
}

//--------------------------------------------
void AddWrapDessinImage()
{
  WrapClass_DessinImage::AddVar_DessinImage( Vars.GetBuiltinContext());
}

//--------------------------------------------
void AddWrapViewer3D()
{
  WrapClass_Viewer3D::AddVar_Viewer3D( Vars.GetBuiltinContext());
}

//--------------------------------------------
void AddWrapGLTransfMatrix()
{
  WrapClass_GLTransfMatrix::AddVar_GLTransfMatrix( Vars.GetBuiltinContext());
}

//--------------------------------------------
void AddWrapBasicTypes()
{
//  ADDOBJECTVAR_NAME(C_wrap_varfunction,"VarList",   wrap_VarList);
//  ADDOBJECTVAR_NAME(C_wrap_varfunction,"VarVector", wrap_VarVector);
  WrapClass_VarVector::AddVar_VarVector( Vars.GetBuiltinContext());

  WrapClass_StdVector<int>::AddVar_StdVector( Vars.GetBuiltinContext(), "vector_int");
  WrapClass_StdVector<float>::AddVar_StdVector( Vars.GetBuiltinContext(), "vector_float");
  WrapClass_StdVector<double>::AddVar_StdVector( Vars.GetBuiltinContext(), "vector_double");

  WrapClass_File::AddVar_File( Vars.GetBuiltinContext());
//  AddVar_VarList( Vars.GetBuiltinContext());
}

//--------------------------------------------
void AddWrapTestTemplateClass()
{
//  WrapClassTestTemplateClass__LT__int__GT___AddStaticMethods( Vars.GetBuiltinContext());

}
