/**
 * C++ Interface: wrap_wxCursor
 *
 * Description: wrapping wxCursor
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxCursor_h_
#define _wrap_wxCursor_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "wx_includes.h"

// include what is needed for inheritence and for types ...

#include "wrap_wxObject.h"



AMI_DECLARE_TYPE(wxCursor);

// TODO: check for inheritence ...
class WrapClass_wxCursor : public WrapClass<wxCursor>
    , public   WrapClass_wxObject
{
  DEFINE_CLASS(WrapClass_wxCursor);

  protected:
    typedef WrapClass<wxCursor>::ptr _parentclass_ptr;
    typedef wxCursor ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxCursor>& GetObj() const { return WrapClass<wxCursor>::GetObj(); }

    /// Constructor
    WrapClass_wxCursor(boost::shared_ptr<wxCursor > si): 
    WrapClass<wxCursor>(si)
    , WrapClass_wxObject(si)
    {}

    /// Destructor
    ~WrapClass_wxCursor()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxCursor_1,"Constructor wxCursor::wxCursor(wxCursor const & param0) (http://docs.wxwidgets.org/stable/wx_wxcursor.html#wxcursor).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxCursor,"Constructor wxCursor::wxCursor() (http://docs.wxwidgets.org/stable/wx_wxcursor.html#wxcursor).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxCursor_2,"Constructor wxCursor::wxCursor() (http://docs.wxwidgets.org/stable/wx_wxcursor.html#wxcursor).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxCursor_3,"Constructor wxCursor::wxCursor(int cursorId) (http://docs.wxwidgets.org/stable/wx_wxcursor.html#wxcursor).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxCursor_4,"Constructor wxCursor::wxCursor(wxImage const & image) (http://docs.wxwidgets.org/stable/wx_wxcursor.html#wxcursor).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxCursor_5,"Constructor wxCursor::wxCursor(char const * bits, int width, int height, int hotSpotX = -0x00000000000000001, int hotSpotY = -0x00000000000000001, char const * maskBits = 0l, wxColour const * fg = 0l, wxColour const * bg = 0l) (http://docs.wxwidgets.org/stable/wx_wxcursor.html#wxcursor).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxCursor*);

    // Static methods
    



    // Standard methods
    
    // Adding copy method
    ADD_CLASS_METHOD(__copy__,"Copy method, uses the copy constructor.");
    // Adding standard methods
    ADD_CLASS_METHOD(Ok,"bool wxCursor::Ok()  (http://docs.wxwidgets.org/stable/wx_wxcursor.html#ok)")
    ADD_CLASS_METHOD(IsOk,"bool wxCursor::IsOk()  (http://docs.wxwidgets.org/stable/wx_wxcursor.html#isok)")
/* The following types are missing: _GdkCursor
    ADD_CLASS_METHOD(GetCursor,"GdkCursor * wxCursor::GetCursor()  (http://docs.wxwidgets.org/stable/wx_wxcursor.html#getcursor)")
*/
    ADD_CLASS_METHOD(GetClassInfo,"wxClassInfo * wxCursor::GetClassInfo()  (http://docs.wxwidgets.org/stable/wx_wxcursor.html#getclassinfo)")

    // Operators:
    ADD_CLASS_METHOD(__assign__,            "wxCursor & wxCursor::operator =(wxCursor const & param0) (http://docs.wxwidgets.org/stable/wx_wxcursor.html#__assign__)")




    void AddMethods(WrapClass<wxCursor>::ptr this_ptr );
    
    /*
     * Adds the constructor and the static methods to the given context
     */
    static void AddStaticMethods( Variables::ptr& context);

};


#endif // _wrap_wxCursor_h
