//
// C++ Interface: vtkAmiCommand
//
// Description: 
//
//
// Author: Karl Krissian <krissian@dis.ulpgc.es>, (C) 2011
//
// Copyright: See COPYING file that comes with this distribution
//
//

#include "vtkAmiCommand.h"

#include "ami_function.h"
#include <vtkCommand.h>

#ifndef vtkObject_declared
  #define vtkObject_declared
  AMI_DECLARE_TYPE(vtkObject)
#endif

void CallAmiFunction(AMIFunction* f, const ParamList::ptr& p);


vtkAmiCommand *  vtkAmiCommand::New()
{ 
  return new vtkAmiCommand; 
}

void vtkAmiCommand::Execute(vtkObject *caller, unsigned long eventid, void*)
{
  if (callback_function!=NULL)
  {
    ParamList::ptr p(new ParamList());
    // Add the caller object
    BasicVariable::ptr c = AMILabType<vtkObject>::CreateVar(caller,true);
    p->AddParam(c);
    BasicVariable::ptr id = AMILabType<long>::CreateVar((long)eventid);
    p->AddParam(id);
    CallAmiFunction(callback_function,p);
  }
}

