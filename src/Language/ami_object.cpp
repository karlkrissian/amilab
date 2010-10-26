
#include "ami_object.h"
#include "wrapfunction_class.h"

/**
  * Destructor : empties the list of variables
  */
AMIObject::~AMIObject() 
{
  //CLASS_MESSAGE(boost::format("_wrapped_object count = %1%") % _wrapped_object->GetObjCounter() );
  _vars->EmptyVariables();
  //CLASS_MESSAGE(boost::format("_wrapped_object count = %1%") % _wrapped_object->GetObjCounter() );
}

//--------------------------------------------------------
void AMIObject::SetClass(AMIClass::ptr& amiclass)
{
    if (amiclass.get()!=NULL)
      std::cout  << "will run the code of the class "
            << amiclass->GetName()
            << " for the object " 
            << GetName()
            << std::endl;
    _class = amiclass;
}
