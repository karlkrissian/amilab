/**
 * C++ Interface: wrap_ClassBase3
 *
 * Description: wrapping ClassBase3
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_ClassBase3_h_
#define _wrap_ClassBase3_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "TestClass.h"

// include what is needed for inheritence and for types ...

#include "wrap_ClassBase2.h"


AMI_DECLARE_TYPE(ClassBase3);

// TODO: check for inheritence ...
class WrapClass_ClassBase3 : public WrapClass<ClassBase3>
    , public   WrapClass_ClassBase2
{
  DEFINE_CLASS(WrapClass_ClassBase3);

  protected:
    typedef WrapClass<ClassBase3>::ptr _parentclass_ptr;
    typedef ClassBase3 ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<ClassBase3>& GetObj() const { return WrapClass<ClassBase3>::GetObj(); }
    std::string ObjPointerAsString() { return "ClassBase3"; }

    /// Constructor
    WrapClass_ClassBase3(boost::shared_ptr<ClassBase3 > si): 
    WrapClass<ClassBase3>(si)
    , WrapClass_ClassBase2(si)
    {}

    /// Destructor
    ~WrapClass_ClassBase3()
    {
      std::cout << "~WrapClass_ClassBase3()" << std::endl;
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(ClassBase3_1,"Wrapping of ClassBase3, http://docs.wxwidgets.org/stable/wx_classbase3.html#classbase3.");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(ClassBase3,"Wrapping of ClassBase3, http://docs.wxwidgets.org/stable/wx_classbase3.html#classbase3.");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(ClassBase3_2,"Wrapping of ClassBase3, http://docs.wxwidgets.org/stable/wx_classbase3.html#classbase3.");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( ClassBase3*);

    // here add each method
    
    // Adding copy method
    ADD_CLASS_METHOD(__copy__,"Copy method, uses the copy constructor.");
    // Adding standard methods
    ADD_CLASS_METHOD(Method3,"http://docs.wxwidgets.org/stable/wx_classbase3.html#method3")

    // Operators:
    ADD_CLASS_METHOD(__assign__,"http://docs.wxwidgets.org/stable/wx_classbase3.html#__assign__")




    void AddMethods(WrapClass<ClassBase3>::ptr this_ptr )
    {
      
      // Add members from ClassBase2
      WrapClass_ClassBase2::ptr parent_ClassBase2(        boost::dynamic_pointer_cast<WrapClass_ClassBase2 >(this_ptr));
      parent_ClassBase2->AddMethods(parent_ClassBase2);


      // check that the method name is not a token
      
      // Adding copy method 
      AddVar___copy__( this_ptr);
      // Adding standard methods 
      AddVar_Method3( this_ptr);

      // Adding operators
      AddVar___assign__( this_ptr);



      
    };
};


#endif // _wrap_ClassBase3_h
