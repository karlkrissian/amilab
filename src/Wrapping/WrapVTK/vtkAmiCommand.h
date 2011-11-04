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

#include <vtkCommand.h>
class AMIFunction;

class vtkAmiCommand : public vtkCommand
{
  public:
    static vtkAmiCommand *New();
    //  { return new vtkAmiCommand; }

    void SetAmiFunction(AMIFunction* f=NULL) 
    {
      callback_function = f;
    }

    virtual void Execute(vtkObject *caller, unsigned long eventid, void*);

  protected:
    vtkAmiCommand() 
      { this->callback_function = NULL; }

    AMIFunction* callback_function;
};

#endif
// _vtkAmiCommand_h_
