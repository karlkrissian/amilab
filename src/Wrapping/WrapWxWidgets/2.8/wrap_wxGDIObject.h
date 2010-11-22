/**
 * C++ Interface: wrap_wxGDIObject
 *
 * Description: wrapping wxGDIObject
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxGDIObject_h_
#define _wrap_wxGDIObject_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "wx/wx.h"

// include what is needed for inheritence and for types ...

#include "wrap_wxObject.h"


AMI_DECLARE_TYPE(wxGDIObject);

// TODO: check for inheritence ...
class WrapClass_wxGDIObject : public WrapClass<wxGDIObject>
    , public   WrapClass_wxObject
{
  DEFINE_CLASS(WrapClass_wxGDIObject);

  protected:
    typedef WrapClass<wxGDIObject>::ptr _parentclass_ptr;
    typedef wxGDIObject ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxGDIObject>& GetObj() const { return WrapClass<wxGDIObject>::GetObj(); }

    /// Constructor
    WrapClass_wxGDIObject(boost::shared_ptr<wxGDIObject > si): 
    WrapClass<wxGDIObject>(si)
    , WrapClass_wxObject(si)
    {}

    /// Destructor
    ~WrapClass_wxGDIObject()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxGDIObject_1,"Constructor wxGDIObject::wxGDIObject(wxGDIObject const & param0) (http://docs.wxwidgets.org/stable/wx_wxgdiobject.html#wxgdiobject).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxGDIObject,"Constructor wxGDIObject::wxGDIObject() (http://docs.wxwidgets.org/stable/wx_wxgdiobject.html#wxgdiobject).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxGDIObject_2,"Constructor wxGDIObject::wxGDIObject() (http://docs.wxwidgets.org/stable/wx_wxgdiobject.html#wxgdiobject).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxGDIObject*);

    // Static methods
    



    // Standard methods
    
    // Adding copy method
    ADD_CLASS_METHOD(__copy__,"Copy method, uses the copy constructor.");
    // Adding standard methods
    ADD_CLASS_METHOD(IsNull,"bool wxGDIObject::IsNull()  (http://docs.wxwidgets.org/stable/wx_wxgdiobject.html#isnull)")
    ADD_CLASS_METHOD(GetClassInfo,"wxClassInfo * wxGDIObject::GetClassInfo()  (http://docs.wxwidgets.org/stable/wx_wxgdiobject.html#getclassinfo)")

    // Operators:
    ADD_CLASS_METHOD(__assign__,            "wxGDIObject & wxGDIObject::operator =(wxGDIObject const & param0) (http://docs.wxwidgets.org/stable/wx_wxgdiobject.html#__assign__)")




    void AddMethods(WrapClass<wxGDIObject>::ptr this_ptr );

};


#endif // _wrap_wxGDIObject_h
