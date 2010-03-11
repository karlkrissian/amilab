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
  The class AMIObject can be created either with or without a link to a class object.
  If a class object is present, it will create a context of variables by running the code
  present in the class object, otherwise it can be considered as a namespace.
*/
class AMIObject {

  DEFINE_CLASS(AMIObject);

private:

  /// Smart pointer to the corresponding class if any
  AMIClass::ptr   _class;

  // why should object have a name, while a variable has one
/*
  /// Object name
  std::string     _name;
*/

  // What happens with references here???
  /// Pointer to the language variable containing the object
  BasicVariable::ptr _var;

  /// Own list of variables
  Variables::ptr  _vars;

 public:

  /**
   * Constructor: creates a smart pointer to the list of variables
   */
  AMIObject()
    {
     // _name     = "";
      _vars     = Variables::ptr(new Variables);
/*
      _vars->SetName("object");
*/
    }

  /**
   * Destructor : empties the list of variables
   */
  virtual ~AMIObject() 
    {
    _vars->EmptyVariables();
    }

  /**
   * Associates the class to the object
   * @param amiclass 
   */
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

  /**
   * Gets a smart pointer to the associated class if any
   * @return 
   */
  AMIClass::ptr& GetClass() { return _class;}

  /**
   * Sets the object name
   * @param fname 
   */
  void SetName( const string& fname) 
  { 
//    _name = fname; 
    _vars->SetName(fname);
  }

  /**
   * Gets the object name
   * @return object name
   */
  const string GetName() const 
  { 
    return _vars->GetName();
  }

  /**
   * Gets the list of variables 
   * @return object context (contains its variables)
   */
  Variables::ptr& GetContext() { return _vars;}

}; // AMIObject


#endif // _ami_object_h_

