/**
 * C++ Interface: wrap_wxIcon
 *
 * Description: wrapping wxIcon
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxIcon_h_
#define _wrap_wxIcon_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "wx_includes.h"

// include what is needed for inheritence and for types ...

#include "wrap_wxBitmap.h"



AMI_DECLARE_TYPE(wxIcon);

// TODO: check for inheritence ...
class WrapClass_wxIcon : public WrapClass<wxIcon>
    , public   WrapClass_wxBitmap
{
  DEFINE_CLASS(WrapClass_wxIcon);

  protected:
    typedef WrapClass<wxIcon>::ptr _parentclass_ptr;
    typedef wxIcon ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxIcon>& GetObj() const { return WrapClass<wxIcon>::GetObj(); }

    /// Constructor
    WrapClass_wxIcon(boost::shared_ptr<wxIcon > si): 
    WrapClass<wxIcon>(si)
    , WrapClass_wxBitmap(si)
    {}

    /// Destructor
    ~WrapClass_wxIcon()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxIcon_1,"Constructor wxIcon::wxIcon(wxIcon const & param0) (http://docs.wxwidgets.org/stable/wx_wxicon.html#wxicon).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxIcon,"Constructor wxIcon::wxIcon() (http://docs.wxwidgets.org/stable/wx_wxicon.html#wxicon).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxIcon_2,"Constructor wxIcon::wxIcon() (http://docs.wxwidgets.org/stable/wx_wxicon.html#wxicon).");
    /* The following types are missing: char const * *
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxIcon_3,"Constructor wxIcon::wxIcon(char const * * bits, int width = -0x00000000000000001, int height = -0x00000000000000001) (http://docs.wxwidgets.org/stable/wx_wxicon.html#wxicon).");
    */
    /* The following types are missing: char * *
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxIcon_4,"Constructor wxIcon::wxIcon(char * * bits, int width = -0x00000000000000001, int height = -0x00000000000000001) (http://docs.wxwidgets.org/stable/wx_wxicon.html#wxicon).");
    */
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxIcon_5,"Constructor wxIcon::wxIcon(wxString const & filename, wxBitmapType type = wxBITMAP_TYPE_XPM, int param2 = -0x00000000000000001, int param3 = -0x00000000000000001) (http://docs.wxwidgets.org/stable/wx_wxicon.html#wxicon).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxIcon_6,"Constructor wxIcon::wxIcon(wxIconLocation const & loc) (http://docs.wxwidgets.org/stable/wx_wxicon.html#wxicon).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxIcon*);

    // Static methods
    



    // Standard methods
    
    // Adding copy method
    ADD_CLASS_METHOD(__copy__,"Copy method, uses the copy constructor.");
    // Adding standard methods
    ADD_CLASS_METHOD(CopyFromBitmap,"void wxIcon::CopyFromBitmap(wxBitmap const & bmp)  (http://docs.wxwidgets.org/stable/wx_wxicon.html#copyfrombitmap)")
    ADD_CLASS_METHOD(GetClassInfo,"wxClassInfo * wxIcon::GetClassInfo()  (http://docs.wxwidgets.org/stable/wx_wxicon.html#getclassinfo)")

    // Operators:
    ADD_CLASS_METHOD(__assign__,            "wxIcon & wxIcon::operator =(wxIcon const & param0) (http://docs.wxwidgets.org/stable/wx_wxicon.html#__assign__)")




    void AddMethods(WrapClass<wxIcon>::ptr this_ptr );
    
    /*
     * Adds the constructor and the static methods to the given context
     */
    static void AddStaticMethods( Variables::ptr& context);

};


#endif // _wrap_wxIcon_h
