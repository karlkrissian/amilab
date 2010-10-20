//
// C++ Implementation: wrap_imports
//
// Description: 
//
//
// Author: Karl Krissian <>, (C) 2009
//
// Copyright: See COPYING file that comes with this distribution
//
//

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

#include "wrap_wxWindow.h"
#include "wrap_wxSize.h"
#include "wrap_wxColour.h"
#include "wrap_wxImage.h"
#include "wrap_wxBitmap.h"
#include "wrap_wxHtmlWindow.h"
#include "wrap_wxString.h"
#include "wrap_wxFileName.h"
#include "wrap_vtkLevelSets.h"

#include "wrap_wxEditor.h"

#include "MainFrame.h"

#include "wrap_ReadRawImages.h"
#include "wrap_ImageExtent.h"
#include "wrap_SurfacePoly.h"
#include "wrap_DessinImage.h"
#include "wrap_Viewer3D.h"
#include "wrap_GLTransfMatrix.h"

#include "wrap_dwControlPoint.h"
#include "wrap_dwCurve.h"
#include "wrap_dwControlledCurve.h"

#include "wrap_stdvector.h"

extern VarContexts  Vars;
extern MainFrame*   GB_main_wxFrame;


void AddWrapImports()
{

  AddWrapWxWidgets();
  AddWrapAmilab();
  AddWrapIO();
  AddWrapImage();
  AddWrapSurface();
  AddWrapDessinImage();
  AddWrapViewer3D();
  AddWrapGLTransfMatrix();
  AddWrapBasicTypes();



  // Create new instance of the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("ami_import");

  // Set the object context
  Variables::ptr previous_ocontext = Vars.GetObjectContext();
  Vars.SetObjectContext(amiobject->GetContext());

//  ADDOBJECTVAR_NAME(C_wrap_procedure,"ImageDraw",  wrap_ImageDraw);

  WrapClass_wxDrawingWindow::AddVar_wxDrawingWindow(amiobject->GetContext());
  WrapClass_ParamPanel     ::AddVar_ParamPanel     (amiobject->GetContext());

  WrapClass_vtkLevelSets  ::AddVar_vtkLevelSets(amiobject->GetContext());


  ADDOBJECTVAR_NAME(C_wrap_procedure,  "System",    wrap_System);
  ADDOBJECTVAR_NAME(C_wrap_procedure,  "ITK",       wrap_ITK);
  ADDOBJECTVAR_NAME(C_wrap_procedure,  "AMIFluid",  wrap_AMIFluid);
  ADDOBJECTVAR_NAME(C_wrap_procedure,  "Filters",   wrap_Filters);
  ADDOBJECTVAR_NAME(C_wrap_procedure,  "WxSamples",        wrap_wxsamples);
  ADDOBJECTVAR_NAME(C_wrap_varfunction,"WxFunctions",        wrap_wxfunctions);

  // Restore the object context
  Vars.SetObjectContext(previous_ocontext);

  // 3. add the variables to this instance
  Vars.AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject);
}

void AddWrapWxWidgets()
{

  // Create new instance of the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wx");

  // Set the object context
  Variables::ptr previous_ocontext = Vars.GetObjectContext();
  Vars.SetObjectContext(amiobject->GetContext());

//  ADDOBJECTVAR_NAME(C_wrap_varfunction,"wxWindow",    wrap_wxWindow); DEPRECATED

  WrapClass_wxWindow::AddVar_wxWindow( amiobject->GetContext(), "wxWindow");

  AddVar_wxSize( amiobject->GetContext(), "wxSize");

  WrapClass_wxFileName  ::AddVar_wxFileName  ( amiobject->GetContext());
  WrapClass_wxString    ::AddVar_wxString    ( amiobject->GetContext());
  WrapClass_wxColour    ::AddVar_wxColour    ( amiobject->GetContext());
  WrapClass_wxBitmap    ::AddVar_wxBitmap    ( amiobject->GetContext());
  WrapClass_wxImage     ::AddVar_wxImage     ( amiobject->GetContext());
  WrapClass_wxHtmlWindow::AddVar_wxHtmlWindow( amiobject->GetContext());

  // Restore the object context
  Vars.SetObjectContext(previous_ocontext);

  // 3. add the variables to this instance
  Vars.GetBuiltinContext()->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject);

}

void AddWrapAmilab()
{
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

  WrapClass_File::AddVar_File( Vars.GetBuiltinContext());
//  AddVar_VarList( Vars.GetBuiltinContext());
}

