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

#include "wrap_wxWindow.h"
#include "wrap_wxSize.h"
#include "wrap_wxColour.h"
#include "wrap_wxImage.h"
#include "wrap_wxBitmap.h"
#include "wrap_wxHtmlWindow.h"
#include "wrap_vtkLevelSets.h"

#include "wrap_wxEditor.h"

#include "MainFrame.h"

#include "wrap_ReadRawImages.h"
#include "wrap_ImageExtent.h"
#include "wrap_SurfacePoly.h"
#include "wrap_DessinImage.h"
#include "wrap_ComputePartialVolume.h"
#include "wrapSubPixel2D.h"

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
  AddWrapBasicTypes();

  // Create new instance of the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("ami_import");

  // Set the object context
  Variables::ptr previous_ocontext = Vars.GetObjectContext();
  Vars.SetObjectContext(amiobject->GetContext());

//  ADDOBJECTVAR_NAME(C_wrap_procedure,"ImageDraw",  wrap_ImageDraw);
  ADDOBJECTVAR_NAME(C_wrap_varfunction,"wxDrawingWindow",  wrap_wxDrawingWindow);

  ADDOBJECTVAR_NAME(C_wrap_varfunction,"ParamPanel",wrap_ParamPanel);
  ADDOBJECTVAR_NAME(C_wrap_varfunction,"vtkLevelSets",wrap_vtkLevelSets);

  AddVar_AnalyticFunctionBase(     amiobject->GetContext());
  AddVar_AnalyticCircle(           amiobject->GetContext());
  AddVar_AnalyticLine(             amiobject->GetContext());
  AddVar_AnalyticStraightVessel2D( amiobject->GetContext());
  AddVar_AnalyticRing2D(           amiobject->GetContext());
  AddVar_AnalyticSphere(           amiobject->GetContext());
  AddVar_AnalyticTorus(            amiobject->GetContext());
  AddVar_ComputePV(                amiobject->GetContext());
  
  AddVar_SubPixel2D(amiobject->GetContext());

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

  ADDOBJECTVAR_NAME(C_wrap_varfunction,"wxWindow",    wrap_wxWindow);

  AddVar_wxSize( amiobject->GetContext(), "wxSize");
//  AddVar_wxSize(    Vars.GetBuiltinContext());

  ADDOBJECTVAR_NAME(C_wrap_varfunction,"wxColour",    wrap_wxColour);
  ADDOBJECTVAR_NAME(C_wrap_varfunction,"wxImage",     wrap_wxImage);
  ADDOBJECTVAR_NAME(C_wrap_varfunction,"wxBitmap",    wrap_wxBitmap);
  ADDOBJECTVAR_NAME(C_wrap_varfunction,"wxHtmlWindow",wrap_wxHtmlWindow);

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

  AddVar_wxEditor( amiobject->GetContext());

  // Add the MainFrame as an object
  AMIObject::ptr obj(AddWrap_MainFrame(GB_main_wxFrame));
  amiobject->GetContext()->AddVar<AMIObject>("MainFrame", obj, amiobject->GetContext());

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
  AddVar_SurfacePoly( Vars.GetBuiltinContext());
}

//--------------------------------------------
void AddWrapDessinImage()
{
  AddVar_DessinImage( Vars.GetBuiltinContext());
}

//--------------------------------------------
void AddWrapBasicTypes()
{
//  ADDOBJECTVAR_NAME(C_wrap_varfunction,"VarList",   wrap_VarList);
//  ADDOBJECTVAR_NAME(C_wrap_varfunction,"VarVector", wrap_VarVector);
  AddVar_VarVector( Vars.GetBuiltinContext());
//  AddVar_VarList( Vars.GetBuiltinContext());
}

