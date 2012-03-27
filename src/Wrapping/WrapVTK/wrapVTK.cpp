//
// C++ Implementation: wrapAMIFluid
//
// Description:
//
//
// Author: Karl Krissian,,, <karl@UBUNTU-KARL>, (C) 2006
//
// Copyright: See COPYING file that comes with this distribution
//
//

#include "paramlist.h"
#include "VarContexts.hpp"
#include "wrapfunctions.hpp"
#include "wrapVTK.h"
#include "vtk_common.h"

#ifndef _WITHOUT_VTK_
  // all the needed vtk files
  #include "addwrap_vtk.h"
#endif // _WITHOUT_VTK_



//---------------------------------------------------------
void AddWrapVTK(AMIObject::ptr& obj) {

  // Create vtk context
  AMIObject::ptr amiobject2(new AMIObject);
  amiobject2->SetName("vtk");
    // Add classes to vtk context
    wrap_vtk_classes(amiobject2->GetContext());
  // Add vtk context to builtin
  obj->GetContext()->AddVar<AMIObject>( amiobject2->GetName().c_str(), 
      amiobject2,obj->GetContext());
}

