/**
 * C++ Interface: wrap_wxCommandEventFunction
 *
 * Description: wrapping wxCommandEventFunction
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxCommandEventFunction_h_
#define _wrap_wxCommandEventFunction_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "wx_includes.h"

// include what is needed for inheritence and for types ...


#ifndef wxCommandEventFunction_declared
  #define wxCommandEventFunction_declared
  AMI_DECLARE_TYPE(wxCommandEventFunction);
#endif

// TODO: check for inheritence ...
class WrapClass_wxCommandEventFunction : public WrapClass<wxCommandEventFunction>
    
{
  DEFINE_CLASS(WrapClass_wxCommandEventFunction);

  protected:
    typedef WrapClass<wxCommandEventFunction>::ptr _parentclass_ptr;
    typedef wxCommandEventFunction ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxCommandEventFunction>& GetObj() const { return WrapClass<wxCommandEventFunction>::GetObj(); }

    /// Constructor
    WrapClass_wxCommandEventFunction(boost::shared_ptr<wxCommandEventFunction > si): 
    WrapClass<wxCommandEventFunction>(si)
    
    {}

    /// Destructor
    ~WrapClass_wxCommandEventFunction()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    

    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxCommandEventFunction*);

    // Static methods
    

    // Standard methods
    



    void AddMethods(WrapClass<wxCommandEventFunction>::ptr this_ptr );
    

};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxCommandEventFunction_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_wxCommandEventFunction_h
