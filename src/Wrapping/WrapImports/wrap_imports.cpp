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
#include "wrapfunctions_draw.h"
#include "wrap_imports.h"
#include "ami_class.h"
#include "ami_object.h"
#include "wrap_imagedraw.h"
#include "wrap_mainframe.h"
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

extern VarContexts  Vars;


void AddWrapImports()
{

  AddWrapWxWidgets();

  // Create new instance of the class
  AMIObject::ptr amiobject(new AMIObject);

  amiobject->SetName("ami_import");

  // Set the object context
  Variables::ptr previous_ocontext = Vars.GetObjectContext();
  Vars.SetObjectContext(amiobject->GetContext());

  ADDOBJECTVAR_NAME(C_wrap_procedure,"ImageDraw",  wrap_ImageDraw);
  ADDOBJECTVAR_NAME(C_wrap_procedure,"MainFrame",  wrap_MainFrame);
  ADDOBJECTVAR_NAME(C_wrap_varfunction,"wxDrawingWindow",  wrap_wxDrawingWindow);

  ADDOBJECTVAR_NAME(C_wrap_varfunction,"VarList",   wrap_VarList);
  ADDOBJECTVAR_NAME(C_wrap_varfunction,"VarVector", wrap_VarVector);
  ADDOBJECTVAR_NAME(C_wrap_varfunction,"ParamPanel",wrap_ParamPanel);
  ADDOBJECTVAR_NAME(C_wrap_varfunction,"vtkLevelSets",wrap_vtkLevelSets);


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

