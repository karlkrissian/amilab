/*
    ==================================================
    Software : AMILab
    Authors  : Karl Krissian
    Email    : krissian@dis.ulpgc.es

    AMILab is a language for image processing
    ==================================================
    Copyright (C) 1996-2005  Karl Krissian

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

    ================================================== 
   The full GNU Lesser General Public License file is in Devel/Sources/Prog/LesserGPL_license.txt
*/

#ifndef _ami_object_h_
#define _ami_object_h_


#include <string>
#include <boost/shared_ptr.hpp>
#include "DefineClass.hpp"
#include "AmiInstructionBlock.h"
#include "ami_class.h"
#include "Variables.hpp"

using namespace boost;

/**
  The class AMIObject will contain a link to its class object
  and will create a context of variables by running the code
  present in the class object
*/
class AMIObject {

  DEFINE_CLASS(AMIObject)

private:
  AMIClass::ptr   _class;
  std::string     _name;
  // have its own list of variables
  Variables::ptr  _vars;

 public:

  AMIObject()
    {
      _name     = "";
      _vars     = Variables::ptr(new Variables);
      _vars->SetName("object");
    }

  virtual ~AMIObject() 
    {
    _vars->EmptyVariables();
    }

  void SetClass(AMIClass::ptr& amiclass)
  {
    if (amiclass.get()!=NULL)
      cout  << "will run the code of the class "
            << amiclass->GetName()
            << " for the object " 
            << GetName()
            << endl;
    _class = amiclass;
  }

  AMIClass::ptr& GetClass() { return _class;}

  void SetName( const string& fname) 
  { 
    _name = fname; 
    _vars->SetName(fname);
  }

  const string& GetName() const { return _name; }

  Variables::ptr& GetContext() { return _vars;}

}; // AMIObject


#endif // _ami_object_h_
