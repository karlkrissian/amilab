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

#include "wx/wx.h"

// include what is needed for inheritence and for types ...

#include "wrap_wxObject.h"



AMI_DECLARE_TYPE(wxObjectEventFunction);

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
    void AddMethods(WrapClass<wxObjectEventFunction>::ptr this_ptr );

};


#endif // _wrap_wxObjectEventFunction_h
