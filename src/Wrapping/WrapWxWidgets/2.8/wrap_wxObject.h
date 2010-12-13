/**
 * C++ Interface: wrap_wxObject
 *
 * Description: wrapping wxObject
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxObject_h_
#define _wrap_wxObject_h_

/*
#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"
*/

#include "wx_includes.h"

// include what is needed for inheritence and for types ...



#ifndef wxObject_declared
  #define wxObject_declared
  AMI_DECLARE_TYPE(wxObject);
#endif

// TODO: check for inheritence ...
class WrapClass_wxObject : public WrapClass<wxObject>
    
{
  DEFINE_CLASS(WrapClass_wxObject);

  protected:
    typedef WrapClass<wxObject>::ptr _parentclass_ptr;
    typedef wxObject ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxObject>& GetObj() const { return WrapClass<wxObject>::GetObj(); }

    /// Constructor
    WrapClass_wxObject(boost::shared_ptr<wxObject > si): 
    WrapClass<wxObject>(si)
    
    {}

    /// Destructor
    ~WrapClass_wxObject()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxObject_1,"Constructor wxObject::wxObject() (http://docs.wxwidgets.org/stable/wx_wxobject.html#wxobject).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxObject,"Constructor wxObject::wxObject() (http://docs.wxwidgets.org/stable/wx_wxobject.html#wxobject).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxObject_2,"Constructor wxObject::wxObject(wxObject const & other) (http://docs.wxwidgets.org/stable/wx_wxobject.html#wxobject).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxObject*);

    // Static methods
    



    // Standard methods
    
    // Adding copy method
    ADD_CLASS_METHOD(__copy__,"Copy method, uses the copy constructor.");
    // Adding standard methods
    ADD_CLASS_METHOD(GetClassInfo,"wxClassInfo * wxObject::GetClassInfo()  (http://docs.wxwidgets.org/stable/wx_wxobject.html#getclassinfo)")
    ADD_CLASS_METHOD(IsKindOf,"bool wxObject::IsKindOf(wxClassInfo * info)  (http://docs.wxwidgets.org/stable/wx_wxobject.html#iskindof)")
    ADD_CLASS_METHOD(GetRefData,"wxObjectRefData * wxObject::GetRefData()  (http://docs.wxwidgets.org/stable/wx_wxobject.html#getrefdata)")
    ADD_CLASS_METHOD(SetRefData,"void wxObject::SetRefData(wxObjectRefData * data)  (http://docs.wxwidgets.org/stable/wx_wxobject.html#setrefdata)")
    ADD_CLASS_METHOD(Ref,"void wxObject::Ref(wxObject const & clone)  (http://docs.wxwidgets.org/stable/wx_wxobject.html#ref)")
    ADD_CLASS_METHOD(UnRef,"void wxObject::UnRef()  (http://docs.wxwidgets.org/stable/wx_wxobject.html#unref)")
    ADD_CLASS_METHOD(UnShare,"void wxObject::UnShare()  (http://docs.wxwidgets.org/stable/wx_wxobject.html#unshare)")
    ADD_CLASS_METHOD(IsSameAs,"bool wxObject::IsSameAs(wxObject const & o)  (http://docs.wxwidgets.org/stable/wx_wxobject.html#issameas)")

    // Operators:
    ADD_CLASS_METHOD(__assign__,            "wxObject & wxObject::operator =(wxObject const & other) (http://docs.wxwidgets.org/stable/wx_wxobject.html#__assign__)")




    void AddMethods(WrapClass<wxObject>::ptr this_ptr );
    

};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxObject_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_wxObject_h
