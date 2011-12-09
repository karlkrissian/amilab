/**
 * C++ Interface: wrap_ClassBase2
 *
 * Description: wrapping ClassBase2
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_ClassBase2_h_
#define _wrap_ClassBase2_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "TestClass.h"

// include what is needed for inheritence and for types ...

#include "wrap_ClassBase1.h"


AMI_DECLARE_TYPE(ClassBase2);

// TODO: check for inheritence ...
class WrapClass_ClassBase2 : public WrapClass<ClassBase2>
    , public   WrapClass_ClassBase1
{
  DEFINE_CLASS(WrapClass_ClassBase2);

  protected:
    typedef WrapClass<ClassBase2>::ptr _parentclass_ptr;
    typedef ClassBase2 ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<ClassBase2>& GetObj() const { return WrapClass<ClassBase2>::GetObj(); }
    std::string ObjPointerAsString() { return "ClassBase2"; }

    /// Constructor
    WrapClass_ClassBase2(boost::shared_ptr<ClassBase2 > si): 
    WrapClass<ClassBase2>(si)
    , WrapClass_ClassBase1(si)
    {}

    /// Destructor
    ~WrapClass_ClassBase2()
    {
      std::cout << "~WrapClass_ClassBase2()" << std::endl;
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(ClassBase2_1,"Wrapping of ClassBase2, http://docs.wxwidgets.org/stable/wx_classbase2.html#classbase2.");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(ClassBase2,"Wrapping of ClassBase2, http://docs.wxwidgets.org/stable/wx_classbase2.html#classbase2.");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(ClassBase2_2,"Wrapping of ClassBase2, http://docs.wxwidgets.org/stable/wx_classbase2.html#classbase2.");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( ClassBase2*);

    // here add each method
    
    // Adding copy method
    ADD_CLASS_METHOD(__copy__,"Copy method, uses the copy constructor.");
    // Adding standard methods
    ADD_CLASS_METHOD(Method2,"http://docs.wxwidgets.org/stable/wx_classbase2.html#method2")

    // Operators:
    ADD_CLASS_METHOD(__assign__,"http://docs.wxwidgets.org/stable/wx_classbase2.html#__assign__")




    void AddMethods(WrapClass<ClassBase2>::ptr this_ptr )
    {
      
      // Add members from ClassBase1
      WrapClass_ClassBase1::ptr parent_ClassBase1(        boost::dynamic_pointer_cast<WrapClass_ClassBase1 >(this_ptr));
      parent_ClassBase1->AddMethods(parent_ClassBase1);


      // check that the method name is not a token
      
      // Adding copy method 
      AddVar___copy__( this_ptr);
      // Adding standard methods 
      AddVar_Method2( this_ptr);

      // Adding operators
      AddVar___assign__( this_ptr);



      
    };
};


#endif // _wrap_ClassBase2_h
