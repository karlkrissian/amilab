/**
 * C++ Interface: wrap_wxMask
 *
 * Description: wrapping wxMask
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxMask_h_
#define _wrap_wxMask_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "wx_includes.h"

// include what is needed for inheritence and for types ...

#include "wrap_wxObject.h"



AMI_DECLARE_TYPE(wxMask);

// TODO: check for inheritence ...
class WrapClass_wxMask : public WrapClass<wxMask>
    , public   WrapClass_wxObject
{
  DEFINE_CLASS(WrapClass_wxMask);

  protected:
    typedef WrapClass<wxMask>::ptr _parentclass_ptr;
    typedef wxMask ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxMask>& GetObj() const { return WrapClass<wxMask>::GetObj(); }

    /// Constructor
    WrapClass_wxMask(boost::shared_ptr<wxMask > si): 
    WrapClass<wxMask>(si)
    , WrapClass_wxObject(si)
    {}

    /// Destructor
    ~WrapClass_wxMask()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxMask_1,"Constructor wxMask::wxMask(wxMask const & param0) (http://docs.wxwidgets.org/stable/wx_wxmask.html#wxmask).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxMask,"Constructor wxMask::wxMask() (http://docs.wxwidgets.org/stable/wx_wxmask.html#wxmask).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxMask_2,"Constructor wxMask::wxMask() (http://docs.wxwidgets.org/stable/wx_wxmask.html#wxmask).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxMask_3,"Constructor wxMask::wxMask(wxBitmap const & bitmap, wxColour const & colour) (http://docs.wxwidgets.org/stable/wx_wxmask.html#wxmask).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxMask_4,"Constructor wxMask::wxMask(wxBitmap const & bitmap, int paletteIndex) (http://docs.wxwidgets.org/stable/wx_wxmask.html#wxmask).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxMask_5,"Constructor wxMask::wxMask(wxBitmap const & bitmap) (http://docs.wxwidgets.org/stable/wx_wxmask.html#wxmask).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxMask*);

    // Static methods
    



    // Standard methods
    
    // Adding copy method
    ADD_CLASS_METHOD(__copy__,"Copy method, uses the copy constructor.");
    // Adding standard methods
    ADD_CLASS_METHOD(Create_1,"bool wxMask::Create(wxBitmap const & bitmap, wxColour const & colour)  (http://docs.wxwidgets.org/stable/wx_wxmask.html#create)")
    ADD_CLASS_METHOD(Create,"wxMask::Create()  (http://docs.wxwidgets.org/stable/wx_wxmask.html#create)")
    ADD_CLASS_METHOD(Create_2,"bool wxMask::Create(wxBitmap const & bitmap, int paletteIndex)  (http://docs.wxwidgets.org/stable/wx_wxmask.html#create)")
    ADD_CLASS_METHOD(Create_3,"bool wxMask::Create(wxBitmap const & bitmap)  (http://docs.wxwidgets.org/stable/wx_wxmask.html#create)")
/* The following types are missing: _GdkDrawable
    ADD_CLASS_METHOD(GetBitmap,"GdkBitmap * wxMask::GetBitmap()  (http://docs.wxwidgets.org/stable/wx_wxmask.html#getbitmap)")
*/
    ADD_CLASS_METHOD(GetClassInfo,"wxClassInfo * wxMask::GetClassInfo()  (http://docs.wxwidgets.org/stable/wx_wxmask.html#getclassinfo)")

    // Operators:
    ADD_CLASS_METHOD(__assign__,            "wxMask & wxMask::operator =(wxMask const & param0) (http://docs.wxwidgets.org/stable/wx_wxmask.html#__assign__)")




    void AddMethods(WrapClass<wxMask>::ptr this_ptr );
    
    /*
     * Adds the constructor and the static methods to the given context
     */
    static void AddStaticMethods( Variables::ptr& context);

};


#endif // _wrap_wxMask_h
