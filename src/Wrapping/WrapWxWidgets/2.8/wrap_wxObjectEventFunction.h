/**
 * C++ Interface: wrap_wxObjectEventFunction
 *
 * Description: wrapping wxObjectEventFunction
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxObjectEventFunction_h_
#define _wrap_wxObjectEventFunction_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "wx_includes.h"

// include what is needed for inheritence and for types ...


#ifndef wxObjectEventFunction_declared
  #define wxObjectEventFunction_declared
  AMI_DECLARE_TYPE(wxObjectEventFunction);
#endif

// TODO: check for inheritence ...
class WrapClass_wxObjectEventFunction : public WrapClass<wxObjectEventFunction>
    
{
  DEFINE_CLASS(WrapClass_wxObjectEventFunction);

  protected:
    typedef WrapClass<wxObjectEventFunction>::ptr _parentclass_ptr;
    typedef wxObjectEventFunction ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxObjectEventFunction>& GetObj() const { return WrapClass<wxObjectEventFunction>::GetObj(); }

    /// Constructor
    WrapClass_wxObjectEventFunction(boost::shared_ptr<wxObjectEventFunction > si): 
    WrapClass<wxObjectEventFunction>(si)
    
    {}

    /// Destructor
    ~WrapClass_wxObjectEventFunction()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    

    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxObjectEventFunction*);

    // Static methods
    

    // Standard methods
    



    void AddMethods(WrapClass<wxObjectEventFunction>::ptr this_ptr );
    

};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxObjectEventFunction_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_wxObjectEventFunction_h
