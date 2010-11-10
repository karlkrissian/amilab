/**
 * C++ Interface: wrap_TestClass
 *
 * Description: wrapping TestClass
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_TestClass_h_
#define _wrap_TestClass_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "TestClass.h"

// include what is needed for inheritence and for types ...




AMI_DECLARE_TYPE(TestClass);

// TODO: check for inheritence ...
class WrapClass_TestClass : public WrapClass<TestClass>
    
{
  DEFINE_CLASS(WrapClass_TestClass);

  protected:
    typedef WrapClass<TestClass>::ptr _parentclass_ptr;
    typedef TestClass ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<TestClass>& GetObj() const { return WrapClass<TestClass>::GetObj(); }

    /// Constructor
    WrapClass_TestClass(boost::shared_ptr<TestClass > si): 
    WrapClass<TestClass>(si)
    
    {}

    /// Destructor
    ~WrapClass_TestClass()
    {
      std::cout << "~WrapClass_TestClass()" << std::endl;
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(TestClass1,"Wrapping of TestClass.");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(TestClass,"Wrapping of TestClass.");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(TestClass2,"Wrapping of TestClass.");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( TestClass*);

    // here add each method
    
    ADD_CLASS_METHOD(GetVal,"")
    ADD_CLASS_METHOD(SetVal,"")

    // Operators:
    ADD_CLASS_METHOD(assign,"")
    ADD_CLASS_METHOD(add,"")




    void AddMethods(WrapClass<TestClass>::ptr this_ptr )
    {
      // here inheritence
      


      // check that the method name is not a token
      
      AddVar_GetVal( this_ptr);
      AddVar_SetVal( this_ptr);

      // Operators:
      AddVar_assign( this_ptr);
      AddVar_add( this_ptr);


    };
};


#endif // _wrap_TestClass_h
