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

#include "VarContexts.hpp"
#include "wrapfunctions.hpp"
#include "wrapfunctions_draw.h"
#include "wrap_imports.h"
#include "ami_class.h"
#include "ami_object.h"
#include "wrap_imagedraw.h"
#include "wrap_mainframe.h"
#include "wrapSystem.h"
#include "wrapITK.h"
#include "wrapAMIFluid.h"
#include "wrapFilters.h"
#include "wrap_wxsamples.h"
#include "wrap_parampanel.h"

extern VarContexts  Vars;


void AddWrapImports()
{

  // Create new instance of the class
  AMIObject* amiobject;
  amiobject = new AMIObject;

  amiobject->SetName("ami_import");

  // Set the object context
  Variables::ptr previous_ocontext = Vars.GetObjectContext();
  Vars.SetObjectContext(amiobject->GetContext());

  Vars.AddVar(type_c_procedure, "ImageDraw",  (void*)  wrap_ImageDraw, OBJECT_CONTEXT_NUMBER);
  Vars.AddVar(type_c_procedure, "MainFrame",  (void*)  wrap_MainFrame, OBJECT_CONTEXT_NUMBER);

  Vars.AddVar(type_c_function,  "ParamPanel", (void*) wrap_ParamPanel, OBJECT_CONTEXT_NUMBER);

  Vars.AddVar(type_c_procedure, "System",  (void*)  wrap_System, OBJECT_CONTEXT_NUMBER);
  Vars.AddVar(type_c_procedure, "ITK",  (void*)  wrap_ITK, OBJECT_CONTEXT_NUMBER);
  Vars.AddVar(type_c_procedure, "AMIFluid",  (void*)  wrap_AMIFluid, OBJECT_CONTEXT_NUMBER);
  Vars.AddVar(type_c_procedure, "Filters",  (void*)  wrap_Filters, OBJECT_CONTEXT_NUMBER);
  Vars.AddVar(type_c_procedure, "wxsamples",  (void*)  wrap_wxsamples, OBJECT_CONTEXT_NUMBER);

  // Restore the object context
  Vars.SetObjectContext(previous_ocontext);

  // 3. add the variables to this instance
  Vars.AddVar( type_ami_object, amiobject->GetName().c_str(), (void*) amiobject);
}


