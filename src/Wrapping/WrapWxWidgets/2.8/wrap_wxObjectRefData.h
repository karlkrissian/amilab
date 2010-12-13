/**
 * C++ Interface: wrap_wxObjectRefData
 *
 * Description: wrapping wxObjectRefData
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxObjectRefData_h_
#define _wrap_wxObjectRefData_h_

/*
#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"
*/

#include "wx_includes.h"

// include what is needed for inheritence and for types ...



#ifndef wxObjectRefData_declared
  #define wxObjectRefData_declared
  AMI_DECLARE_TYPE(wxObjectRefData);
#endif

// TODO: check for inheritence ...
class WrapClass_wxObjectRefData : public WrapClass<wxObjectRefData>
    
{
  DEFINE_CLASS(WrapClass_wxObjectRefData);

  protected:
    typedef WrapClass<wxObjectRefData>::ptr _parentclass_ptr;
    typedef wxObjectRefData ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxObjectRefData>& GetObj() const { return WrapClass<wxObjectRefData>::GetObj(); }

    /// Constructor
    WrapClass_wxObjectRefData(boost::shared_ptr<wxObjectRefData > si): 
    WrapClass<wxObjectRefData>(si)
    
    {}

    /// Destructor
    ~WrapClass_wxObjectRefData()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxObjectRefData_1,"Constructor wxObjectRefData::wxObjectRefData(wxObjectRefData const & param0) (http://docs.wxwidgets.org/stable/wx_wxobjectrefdata.html#wxobjectrefdata).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxObjectRefData,"Constructor wxObjectRefData::wxObjectRefData() (http://docs.wxwidgets.org/stable/wx_wxobjectrefdata.html#wxobjectrefdata).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxObjectRefData_2,"Constructor wxObjectRefData::wxObjectRefData() (http://docs.wxwidgets.org/stable/wx_wxobjectrefdata.html#wxobjectrefdata).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxObjectRefData*);

    // Static methods
    



    // Standard methods
    
    // Adding copy method
    ADD_CLASS_METHOD(__copy__,"Copy method, uses the copy constructor.");
    // Adding standard methods
    ADD_CLASS_METHOD(GetRefCount,"int wxObjectRefData::GetRefCount()  (http://docs.wxwidgets.org/stable/wx_wxobjectrefdata.html#getrefcount)")

    // Operators:
    ADD_CLASS_METHOD(__assign__,            "wxObjectRefData & wxObjectRefData::operator =(wxObjectRefData const & param0) (http://docs.wxwidgets.org/stable/wx_wxobjectrefdata.html#__assign__)")




    void AddMethods(WrapClass<wxObjectRefData>::ptr this_ptr );
    

};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxObjectRefData_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_wxObjectRefData_h
