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

#include "itkAmiCommand.h"

#include "ami_function.h"
#include <itkCommand.h>

typedef itk::Object Object;
#ifndef Object_declared
  #define Object_declared
  AMI_DECLARE_TYPE(Object)
#endif
  
typedef itk::EventObject EventObject;
#ifndef EventObject_declared
  #define EventObject_declared
  AMI_DECLARE_TYPE(EventObject)
#endif

void CallAmiFunction(AMIFunction* f, const ParamList::ptr& p);


void itkAmiCommand::Execute(itk::Object * object, const itk::EventObject & event)
{
  if (callback_function!=NULL)
  {
    ParamList::ptr p(new ParamList());
/*
    // Add the caller object
    BasicVariable::ptr c = AMILabType<itk::Object>::CreateVar(object,true);
    p->AddParam(c);
    BasicVariable::ptr id = AMILabType<itk::EventObject>::CreateVar(event);
    p->AddParam(id);
    */
    CallAmiFunction(callback_function,p);
  }
}

void itkAmiCommand::Execute(const itk::Object * object, const itk::EventObject & event)
{
  if (callback_function!=NULL)
  {
    ParamList::ptr p(new ParamList());
/*
    // Add the caller object
    BasicVariable::ptr c = AMILabType<itk::Object>::CreateVar(object,true);
    p->AddParam(c);
    BasicVariable::ptr id = AMILabType<itk::EventObject>::CreateVar(event);
    p->AddParam(id);
    */
    CallAmiFunction(callback_function,p);
  }
}


