/**
 * C++ Interface: wrap_TemplateClass<int>
 *
 * Description: wrapping TemplateClass<int>
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_TemplateClass_int__h_
#define _wrap_TemplateClass_int__h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "TestClass.h"

// include what is needed for inheritence and for types ...




AMI_DECLARE_TYPE(TemplateClass<int>);

// TODO: check for inheritence ...
class WrapClass_TemplateClass_int_ : public WrapClass<TemplateClass<int> >
    
{
  DEFINE_CLASS(WrapClass_TemplateClass_int_);

  protected:
    typedef WrapClass<TemplateClass<int> >::ptr _parentclass_ptr;
    typedef TemplateClass<int> ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<TemplateClass<int> >& GetObj() const { return WrapClass<TemplateClass<int> >::GetObj(); }

    /// Constructor
    WrapClass_TemplateClass_int_(boost::shared_ptr<TemplateClass<int> > si): 
    WrapClass<TemplateClass<int> >(si)
    {}

    /// Constructor const
    WrapClass_TemplateClass_int_(boost::shared_ptr<TemplateClass<int> const> si, bool): 
    WrapClass<TemplateClass<int> >(si, true)
    {}

    /// Destructor
    ~WrapClass_TemplateClass_int_()
    {
      std::cout << "~WrapClass_TemplateClass<int>()" << std::endl;
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(TemplateClass_1,"Wrapping of TemplateClass<int>, http://docs.wxwidgets.org/stable/wx_templateclass<int>.html#templateclass.");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(TemplateClass,"Wrapping of TemplateClass<int>, http://docs.wxwidgets.org/stable/wx_templateclass<int>.html#templateclass.");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(TemplateClass_2,"Wrapping of TemplateClass<int>, http://docs.wxwidgets.org/stable/wx_templateclass<int>.html#templateclass.");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( TemplateClass<int>*);

    // here add each method
    
    // Adding copy method
    ADD_CLASS_METHOD(__copy__,"Copy method, uses the copy constructor.");
    // Adding standard methods

    // Operators:
    ADD_CLASS_METHOD(__assign__,"http://docs.wxwidgets.org/stable/wx_templateclass<int>.html#__assign__")




    void AddMethods(WrapClass<TemplateClass<int> >::ptr this_ptr )
    {
      


      // check that the method name is not a token
      
      // Adding copy method 
      AddVar___copy__( this_ptr);
      // Adding standard methods 

      // Adding operators
      AddVar___assign__( this_ptr);



      // Add public fields
      AMIObject::ptr tmpobj(amiobject.lock());
      if (!tmpobj.get()) return;
      Variables::ptr context(tmpobj->GetContext());
      
      // Adding public member value
      boost::shared_ptr<int > var_value_ptr(&GetObj()->value, smartpointer_nodeleter<int >());
      BasicVariable::ptr var_value = AMILabType<int >::CreateVarFromSmtPtr(var_value_ptr);
      if (var_value.get()) {
        var_value->Rename("value");
        context->AddVar(var_value,context);
      }

    };
};


#endif // _wrap_TemplateClass_int__h
