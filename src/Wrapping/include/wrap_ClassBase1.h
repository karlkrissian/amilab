/**
 * C++ Interface: wrap_ClassBase1
 *
 * Description: wrapping ClassBase1
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_ClassBase1_h_
#define _wrap_ClassBase1_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "TestClass.h"

// include what is needed for inheritence and for types ...




AMI_DECLARE_TYPE(ClassBase1);

// TODO: check for inheritence ...
class WrapClass_ClassBase1 : public WrapClass<ClassBase1>
    
{
  DEFINE_CLASS(WrapClass_ClassBase1);

  protected:
    typedef WrapClass<ClassBase1>::ptr _parentclass_ptr;
    typedef ClassBase1 ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<ClassBase1>& GetObj() const { return WrapClass<ClassBase1>::GetObj(); }

    /// Constructor
    WrapClass_ClassBase1(boost::shared_ptr<ClassBase1 > si): 
    WrapClass<ClassBase1>(si)
    
    {}

    /// Destructor
    ~WrapClass_ClassBase1()
    {
      std::cout << "~WrapClass_ClassBase1()" << std::endl;
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(ClassBase1_1,"Wrapping of ClassBase1, http://docs.wxwidgets.org/stable/wx_classbase1.html#classbase1.");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(ClassBase1,"Wrapping of ClassBase1, http://docs.wxwidgets.org/stable/wx_classbase1.html#classbase1.");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(ClassBase1_2,"Wrapping of ClassBase1, http://docs.wxwidgets.org/stable/wx_classbase1.html#classbase1.");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( ClassBase1*);

    // here add each method
    
    // Adding copy method
    ADD_CLASS_METHOD(__copy__,"Copy method, uses the copy constructor.");
    // Adding standard methods
    ADD_CLASS_METHOD(Method1,"http://docs.wxwidgets.org/stable/wx_classbase1.html#method1")

    // Operators:
    ADD_CLASS_METHOD(__assign__,"http://docs.wxwidgets.org/stable/wx_classbase1.html#__assign__")




    void AddMethods(WrapClass<ClassBase1>::ptr this_ptr )
    {
      


      // check that the method name is not a token
      
      // Adding copy method 
      AddVar___copy__( this_ptr);
      // Adding standard methods 
      AddVar_Method1( this_ptr);

      // Adding operators
      AddVar___assign__( this_ptr);



      
    };
};


#endif // _wrap_ClassBase1_h
