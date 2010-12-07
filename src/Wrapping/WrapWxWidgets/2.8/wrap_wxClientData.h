/**
 * C++ Interface: wrap_wxClientData
 *
 * Description: wrapping wxClientData
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxClientData_h_
#define _wrap_wxClientData_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "wx_includes.h"

// include what is needed for inheritence and for types ...




AMI_DECLARE_TYPE(wxClientData);

// TODO: check for inheritence ...
class WrapClass_wxClientData : public WrapClass<wxClientData>
    
{
  DEFINE_CLASS(WrapClass_wxClientData);

  protected:
    typedef WrapClass<wxClientData>::ptr _parentclass_ptr;
    typedef wxClientData ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxClientData>& GetObj() const { return WrapClass<wxClientData>::GetObj(); }

    /// Constructor
    WrapClass_wxClientData(boost::shared_ptr<wxClientData > si): 
    WrapClass<wxClientData>(si)
    
    {}

    /// Destructor
    ~WrapClass_wxClientData()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxClientData_1,"Constructor wxClientData::wxClientData(wxClientData const & param0) (http://docs.wxwidgets.org/stable/wx_wxclientdata.html#wxclientdata).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxClientData,"Constructor wxClientData::wxClientData() (http://docs.wxwidgets.org/stable/wx_wxclientdata.html#wxclientdata).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxClientData_2,"Constructor wxClientData::wxClientData() (http://docs.wxwidgets.org/stable/wx_wxclientdata.html#wxclientdata).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxClientData*);

    // Static methods
    



    // Standard methods
    
    // Adding copy method
    ADD_CLASS_METHOD(__copy__,"Copy method, uses the copy constructor.");
    // Adding standard methods

    // Operators:
    ADD_CLASS_METHOD(__assign__,            "wxClientData & wxClientData::operator =(wxClientData const & param0) (http://docs.wxwidgets.org/stable/wx_wxclientdata.html#__assign__)")




    void AddMethods(WrapClass<wxClientData>::ptr this_ptr );
    
    /*
     * Adds the constructor and the static methods to the given context
     */
    static void AddStaticMethods( Variables::ptr& context);

};


#endif // _wrap_wxClientData_h
