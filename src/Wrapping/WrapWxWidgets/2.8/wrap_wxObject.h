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

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "wx/wx.h"

// include what is needed for inheritence and for types ...




AMI_DECLARE_TYPE(wxObject);

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
      std::cout << "~WrapClass_wxObject()" << std::endl;
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

    // here add each method
    
    // Adding copy method
    ADD_CLASS_METHOD(__copy__,"Copy method, uses the copy constructor.");
    // Adding standard methods
    ADD_CLASS_METHOD(GetClassInfo,"wxClassInfo * wxObject::GetClassInfo()  (http://docs.wxwidgets.org/stable/wx_wxobject.html#getclassinfo)")
    ADD_CLASS_METHOD(IsKindOf,"bool wxObject::IsKindOf(wxClassInfo * info)  (http://docs.wxwidgets.org/stable/wx_wxobject.html#iskindof)")
/* The following types are missing: wxObjectRefData
    ADD_CLASS_METHOD(GetRefData,"wxObjectRefData * wxObject::GetRefData()  (http://docs.wxwidgets.org/stable/wx_wxobject.html#getrefdata)")
*/
/* The following types are missing: wxObjectRefData
    ADD_CLASS_METHOD(SetRefData,"void wxObject::SetRefData(wxObjectRefData * data)  (http://docs.wxwidgets.org/stable/wx_wxobject.html#setrefdata)")
*/
    ADD_CLASS_METHOD(Ref,"void wxObject::Ref(wxObject const & clone)  (http://docs.wxwidgets.org/stable/wx_wxobject.html#ref)")
    ADD_CLASS_METHOD(UnRef,"void wxObject::UnRef()  (http://docs.wxwidgets.org/stable/wx_wxobject.html#unref)")
    ADD_CLASS_METHOD(UnShare,"void wxObject::UnShare()  (http://docs.wxwidgets.org/stable/wx_wxobject.html#unshare)")
    ADD_CLASS_METHOD(IsSameAs,"bool wxObject::IsSameAs(wxObject const & o)  (http://docs.wxwidgets.org/stable/wx_wxobject.html#issameas)")

    // Operators:
    ADD_CLASS_METHOD(__assign__,            "wxObject & wxObject::=(wxObject const & other) (http://docs.wxwidgets.org/stable/wx_wxobject.html#__assign__)")




    void AddMethods(WrapClass<wxObject>::ptr this_ptr )
    {
      


      // check that the method name is not a token
      
      // Adding copy method 
      AddVar___copy__( this_ptr);
      // Adding standard methods 
      AddVar_GetClassInfo( this_ptr);
      AddVar_IsKindOf( this_ptr);
/* The following types are missing: wxObjectRefData
      AddVar_GetRefData( this_ptr);
*/
/* The following types are missing: wxObjectRefData
      AddVar_SetRefData( this_ptr);
*/
      AddVar_Ref( this_ptr);
      AddVar_UnRef( this_ptr);
      AddVar_UnShare( this_ptr);
      AddVar_IsSameAs( this_ptr);

      // Adding operators
      AddVar___assign__( this_ptr);



      
    };
};


#endif // _wrap_wxObject_h
