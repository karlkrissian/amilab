//
// C++ Interface: ami_cpp_object
//
// Description: 
// ami object from a C++ class wrapping
//
// Author: Karl Krissian <>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _ami_cpp_object_h_
#define _ami_cpp_object_h_

#include "ami_object.h"

/**
  The class AMICPPObject is used for wrapped C++ instances of a class. 
  The instance is stored as a void* pointer, which in reality points to a smart pointer of the C++ object.
  If a class object is present, it will create a context of variables by running the code
  present in the class object, otherwise it can be considered as a namespace.
*/
class AMICPPObject : public AMIObject {

  DEFINE_CLASS(AMICPPObject);

private:

  void* _object;

public:

  /**
   * Constructor: creates a smart pointer to the list of variables
   */
  AMICPPObject() : AMIObject()
    {
      _object = NULL;
    }

  void SetObject( void* obj) { _object = obj; }

  void* GetObject() { return _object; }

}; // AMICPPObject


#endif // _ami_cpp_object_h_
