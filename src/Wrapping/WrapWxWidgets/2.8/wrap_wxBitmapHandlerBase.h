/**
 * C++ Interface: wrap_wxBitmapHandlerBase
 *
 * Description: wrapping wxBitmapHandlerBase
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxBitmapHandlerBase_h_
#define _wrap_wxBitmapHandlerBase_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "wx_includes.h"

// include what is needed for inheritence and for types ...

#include "wrap_wxObject.h"



AMI_DECLARE_TYPE(wxBitmapHandlerBase);

// TODO: check for inheritence ...
class WrapClass_wxBitmapHandlerBase : public WrapClass<wxBitmapHandlerBase>
    , public   WrapClass_wxObject
{
  DEFINE_CLASS(WrapClass_wxBitmapHandlerBase);

  protected:
    typedef WrapClass<wxBitmapHandlerBase>::ptr _parentclass_ptr;
    typedef wxBitmapHandlerBase ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxBitmapHandlerBase>& GetObj() const { return WrapClass<wxBitmapHandlerBase>::GetObj(); }

    /// Constructor
    WrapClass_wxBitmapHandlerBase(boost::shared_ptr<wxBitmapHandlerBase > si): 
    WrapClass<wxBitmapHandlerBase>(si)
    , WrapClass_wxObject(si)
    {}

    /// Destructor
    ~WrapClass_wxBitmapHandlerBase()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxBitmapHandlerBase_1,"Constructor wxBitmapHandlerBase::wxBitmapHandlerBase(wxBitmapHandlerBase const & param0) (http://docs.wxwidgets.org/stable/wx_wxbitmaphandlerbase.html#wxbitmaphandlerbase).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxBitmapHandlerBase,"Constructor wxBitmapHandlerBase::wxBitmapHandlerBase() (http://docs.wxwidgets.org/stable/wx_wxbitmaphandlerbase.html#wxbitmaphandlerbase).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxBitmapHandlerBase_2,"Constructor wxBitmapHandlerBase::wxBitmapHandlerBase() (http://docs.wxwidgets.org/stable/wx_wxbitmaphandlerbase.html#wxbitmaphandlerbase).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxBitmapHandlerBase*);

    // Static methods
    



    // Standard methods
    
    // Adding copy method
    ADD_CLASS_METHOD(__copy__,"Copy method, uses the copy constructor.");
    // Adding standard methods
/* The following types are missing: void
    ADD_CLASS_METHOD(Create,"bool wxBitmapHandlerBase::Create(wxBitmap * bitmap, void const * data, long int flags, int width, int height, int depth = 1)  (http://docs.wxwidgets.org/stable/wx_wxbitmaphandlerbase.html#create)")
*/
    ADD_CLASS_METHOD(LoadFile,"bool wxBitmapHandlerBase::LoadFile(wxBitmap * bitmap, wxString const & name, long int flags, int desiredWidth, int desiredHeight)  (http://docs.wxwidgets.org/stable/wx_wxbitmaphandlerbase.html#loadfile)")
    ADD_CLASS_METHOD(SaveFile,"bool wxBitmapHandlerBase::SaveFile(wxBitmap const * bitmap, wxString const & name, int type, wxPalette const * palette = 0l)  (http://docs.wxwidgets.org/stable/wx_wxbitmaphandlerbase.html#savefile)")
    ADD_CLASS_METHOD(SetName,"void wxBitmapHandlerBase::SetName(wxString const & name)  (http://docs.wxwidgets.org/stable/wx_wxbitmaphandlerbase.html#setname)")
    ADD_CLASS_METHOD(SetExtension,"void wxBitmapHandlerBase::SetExtension(wxString const & ext)  (http://docs.wxwidgets.org/stable/wx_wxbitmaphandlerbase.html#setextension)")
    ADD_CLASS_METHOD(SetType,"void wxBitmapHandlerBase::SetType(wxBitmapType type)  (http://docs.wxwidgets.org/stable/wx_wxbitmaphandlerbase.html#settype)")
    ADD_CLASS_METHOD(GetName,"wxString const & wxBitmapHandlerBase::GetName()  (http://docs.wxwidgets.org/stable/wx_wxbitmaphandlerbase.html#getname)")
    ADD_CLASS_METHOD(GetExtension,"wxString const & wxBitmapHandlerBase::GetExtension()  (http://docs.wxwidgets.org/stable/wx_wxbitmaphandlerbase.html#getextension)")
    ADD_CLASS_METHOD(GetType,"wxBitmapType wxBitmapHandlerBase::GetType()  (http://docs.wxwidgets.org/stable/wx_wxbitmaphandlerbase.html#gettype)")
    ADD_CLASS_METHOD(GetClassInfo,"wxClassInfo * wxBitmapHandlerBase::GetClassInfo()  (http://docs.wxwidgets.org/stable/wx_wxbitmaphandlerbase.html#getclassinfo)")

    // Operators:
    ADD_CLASS_METHOD(__assign__,            "wxBitmapHandlerBase & wxBitmapHandlerBase::operator =(wxBitmapHandlerBase const & param0) (http://docs.wxwidgets.org/stable/wx_wxbitmaphandlerbase.html#__assign__)")




    void AddMethods(WrapClass<wxBitmapHandlerBase>::ptr this_ptr );
    
    /*
     * Adds the constructor and the static methods to the given context
     */
    static void AddStaticMethods( Variables::ptr& context);

};


#endif // _wrap_wxBitmapHandlerBase_h
