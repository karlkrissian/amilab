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

#ifndef _vtkAmiCommand_h_
#define _vtkAmiCommand_h_

#include <itkCommand.h>
class AMIFunction;

class itkAmiCommand : public itk::Command
{
public:
  typedef  itkAmiCommand           Self;
  typedef  itk::Command            Superclass;
  typedef  itk::SmartPointer<Self> Pointer;
  itkNewMacro( Self );

public:
  void Execute(itk::Object *caller, const itk::EventObject & event);
//  {
//    Execute( (const itk::Object *)caller, event);
//  }

  void Execute(const itk::Object * object, const itk::EventObject & event);

  void SetAmiFunction(AMIFunction* f=NULL) 
  {
    callback_function = f;
  }

protected:
  itkAmiCommand() 
    { this->callback_function = NULL; }

  AMIFunction* callback_function;
};

#endif
// _itkAmiCommand_h_
