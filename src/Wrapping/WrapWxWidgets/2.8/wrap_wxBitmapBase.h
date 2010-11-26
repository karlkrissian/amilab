/**
 * C++ Interface: wrap_wxBitmapBase
 *
 * Description: wrapping wxBitmapBase
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxBitmapBase_h_
#define _wrap_wxBitmapBase_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "wx/wx.h"

// include what is needed for inheritence and for types ...

#include "wrap_wxGDIObject.h"


AMI_DECLARE_TYPE(wxBitmapBase);

// TODO: check for inheritence ...
class WrapClass_wxBitmapBase : public WrapClass<wxBitmapBase>
    , public   WrapClass_wxGDIObject
{
  DEFINE_CLASS(WrapClass_wxBitmapBase);

  protected:
    typedef WrapClass<wxBitmapBase>::ptr _parentclass_ptr;
    typedef wxBitmapBase ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxBitmapBase>& GetObj() const { return WrapClass<wxBitmapBase>::GetObj(); }

    /// Constructor
    WrapClass_wxBitmapBase(boost::shared_ptr<wxBitmapBase > si): 
    WrapClass<wxBitmapBase>(si)
    , WrapClass_wxGDIObject(si)
    {}

    /// Destructor
    ~WrapClass_wxBitmapBase()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    


    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxBitmapBase*);

    // Static methods
    
    ADD_CLASS_STATICMETHOD(GetHandlers,"wxList & wxBitmapBase::GetHandlers() (http://docs.wxwidgets.org/stable/wx_wxbitmapbase.html#gethandlers).");
    ADD_CLASS_STATICMETHOD(AddHandler,"void wxBitmapBase::AddHandler(wxBitmapHandlerBase * handler) (http://docs.wxwidgets.org/stable/wx_wxbitmapbase.html#addhandler).");
    ADD_CLASS_STATICMETHOD(InsertHandler,"void wxBitmapBase::InsertHandler(wxBitmapHandlerBase * handler) (http://docs.wxwidgets.org/stable/wx_wxbitmapbase.html#inserthandler).");
    ADD_CLASS_STATICMETHOD(RemoveHandler,"bool wxBitmapBase::RemoveHandler(wxString const & name) (http://docs.wxwidgets.org/stable/wx_wxbitmapbase.html#removehandler).");
    ADD_CLASS_STATICMETHOD(FindHandler_1,"wxBitmapHandler * wxBitmapBase::FindHandler(wxString const & name) (http://docs.wxwidgets.org/stable/wx_wxbitmapbase.html#findhandler).");
    ADD_CLASS_STATICMETHOD(FindHandler,"wxBitmapBase::FindHandler() (http://docs.wxwidgets.org/stable/wx_wxbitmapbase.html#findhandler).");
    ADD_CLASS_STATICMETHOD(FindHandler_2,"wxBitmapHandler * wxBitmapBase::FindHandler(wxString const & extension, wxBitmapType bitmapType) (http://docs.wxwidgets.org/stable/wx_wxbitmapbase.html#findhandler).");
    ADD_CLASS_STATICMETHOD(FindHandler_3,"wxBitmapHandler * wxBitmapBase::FindHandler(wxBitmapType bitmapType) (http://docs.wxwidgets.org/stable/wx_wxbitmapbase.html#findhandler).");
    ADD_CLASS_STATICMETHOD(CleanUpHandlers,"void wxBitmapBase::CleanUpHandlers() (http://docs.wxwidgets.org/stable/wx_wxbitmapbase.html#cleanuphandlers).");



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(Ok,"bool wxBitmapBase::Ok()  (http://docs.wxwidgets.org/stable/wx_wxbitmapbase.html#ok)")
    ADD_CLASS_METHOD(QuantizeColour,"wxColour wxBitmapBase::QuantizeColour(wxColour const & colour)  (http://docs.wxwidgets.org/stable/wx_wxbitmapbase.html#quantizecolour)")
    ADD_CLASS_METHOD(GetClassInfo,"wxClassInfo * wxBitmapBase::GetClassInfo()  (http://docs.wxwidgets.org/stable/wx_wxbitmapbase.html#getclassinfo)")

    // Operators:
    ADD_CLASS_METHOD(__assign__,            "wxBitmapBase & wxBitmapBase::operator =(wxBitmapBase const & param0) (http://docs.wxwidgets.org/stable/wx_wxbitmapbase.html#__assign__)")




    void AddMethods(WrapClass<wxBitmapBase>::ptr this_ptr );

};


#endif // _wrap_wxBitmapBase_h
