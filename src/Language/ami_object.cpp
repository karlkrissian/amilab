
#include "ami_object.h"
#include "wrapfunction_class.h"

/**
  * Destructor : empties the list of variables
  */
AMIObject::~AMIObject() 
{
  CLASS_MESSAGE(boost::format("_wrapped_object count = %1%") % _wrapped_object->GetObjCounter() );
  _vars->EmptyVariables();
  CLASS_MESSAGE(boost::format("_wrapped_object count = %1%") % _wrapped_object->GetObjCounter() );
}
