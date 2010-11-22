/**
 * C++ Interface: wrap_wxPen
 *
 * Description: wrapping wxPen
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxPen_h_
#define _wrap_wxPen_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "wx/wx.h"

// include what is needed for inheritence and for types ...

#include "wrap_wxGDIObject.h"


AMI_DECLARE_TYPE(wxPen);

// TODO: check for inheritence ...
class WrapClass_wxPen : public WrapClass<wxPen>
    , public   WrapClass_wxGDIObject
{
  DEFINE_CLASS(WrapClass_wxPen);

  protected:
    typedef WrapClass<wxPen>::ptr _parentclass_ptr;
    typedef wxPen ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxPen>& GetObj() const { return WrapClass<wxPen>::GetObj(); }

    /// Constructor
    WrapClass_wxPen(boost::shared_ptr<wxPen > si): 
    WrapClass<wxPen>(si)
    , WrapClass_wxGDIObject(si)
    {}

    /// Destructor
    ~WrapClass_wxPen()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxPen_1,"Constructor wxPen::wxPen(wxPen const & param0) (http://docs.wxwidgets.org/stable/wx_wxpen.html#wxpen).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxPen,"Constructor wxPen::wxPen() (http://docs.wxwidgets.org/stable/wx_wxpen.html#wxpen).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxPen_2,"Constructor wxPen::wxPen() (http://docs.wxwidgets.org/stable/wx_wxpen.html#wxpen).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxPen_3,"Constructor wxPen::wxPen(wxColour const & colour, int width = 1, int style = wxSOLID) (http://docs.wxwidgets.org/stable/wx_wxpen.html#wxpen).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxPen*);

    // Static methods
    



    // Standard methods
    
    // Adding copy method
    ADD_CLASS_METHOD(__copy__,"Copy method, uses the copy constructor.");
    // Adding standard methods
    ADD_CLASS_METHOD(Ok,"bool wxPen::Ok()  (http://docs.wxwidgets.org/stable/wx_wxpen.html#ok)")
    ADD_CLASS_METHOD(IsOk,"bool wxPen::IsOk()  (http://docs.wxwidgets.org/stable/wx_wxpen.html#isok)")
    ADD_CLASS_METHOD(SetColour_1,"void wxPen::SetColour(wxColour const & colour)  (http://docs.wxwidgets.org/stable/wx_wxpen.html#setcolour)")
    ADD_CLASS_METHOD(SetColour,"wxPen::SetColour()  (http://docs.wxwidgets.org/stable/wx_wxpen.html#setcolour)")
    ADD_CLASS_METHOD(SetColour_2,"void wxPen::SetColour(unsigned char red, unsigned char green, unsigned char blue)  (http://docs.wxwidgets.org/stable/wx_wxpen.html#setcolour)")
    ADD_CLASS_METHOD(SetCap,"void wxPen::SetCap(int capStyle)  (http://docs.wxwidgets.org/stable/wx_wxpen.html#setcap)")
    ADD_CLASS_METHOD(SetJoin,"void wxPen::SetJoin(int joinStyle)  (http://docs.wxwidgets.org/stable/wx_wxpen.html#setjoin)")
    ADD_CLASS_METHOD(SetStyle,"void wxPen::SetStyle(int style)  (http://docs.wxwidgets.org/stable/wx_wxpen.html#setstyle)")
    ADD_CLASS_METHOD(SetWidth,"void wxPen::SetWidth(int width)  (http://docs.wxwidgets.org/stable/wx_wxpen.html#setwidth)")
/* The following types are missing: signed char
    ADD_CLASS_METHOD(SetDashes,"void wxPen::SetDashes(int number_of_dashes, wxDash const * dash)  (http://docs.wxwidgets.org/stable/wx_wxpen.html#setdashes)")
*/
    ADD_CLASS_METHOD(GetColour,"wxColour & wxPen::GetColour()  (http://docs.wxwidgets.org/stable/wx_wxpen.html#getcolour)")
    ADD_CLASS_METHOD(GetCap,"int wxPen::GetCap()  (http://docs.wxwidgets.org/stable/wx_wxpen.html#getcap)")
    ADD_CLASS_METHOD(GetJoin,"int wxPen::GetJoin()  (http://docs.wxwidgets.org/stable/wx_wxpen.html#getjoin)")
    ADD_CLASS_METHOD(GetStyle,"int wxPen::GetStyle()  (http://docs.wxwidgets.org/stable/wx_wxpen.html#getstyle)")
    ADD_CLASS_METHOD(GetWidth,"int wxPen::GetWidth()  (http://docs.wxwidgets.org/stable/wx_wxpen.html#getwidth)")
/* The following types are missing: signed char
    ADD_CLASS_METHOD(GetDashes,"int wxPen::GetDashes(wxDash * * ptr)  (http://docs.wxwidgets.org/stable/wx_wxpen.html#getdashes)")
*/
    ADD_CLASS_METHOD(GetDashCount,"int wxPen::GetDashCount()  (http://docs.wxwidgets.org/stable/wx_wxpen.html#getdashcount)")
/* The following types are missing: signed char
    ADD_CLASS_METHOD(GetDash,"wxDash * wxPen::GetDash()  (http://docs.wxwidgets.org/stable/wx_wxpen.html#getdash)")
*/
    ADD_CLASS_METHOD(GetClassInfo,"wxClassInfo * wxPen::GetClassInfo()  (http://docs.wxwidgets.org/stable/wx_wxpen.html#getclassinfo)")

    // Operators:
    ADD_CLASS_METHOD(__assign__,            "wxPen & wxPen::operator =(wxPen const & param0) (http://docs.wxwidgets.org/stable/wx_wxpen.html#__assign__)")
    ADD_CLASS_METHOD(__equal__,            "bool wxPen::operator ==(wxPen const & pen) (http://docs.wxwidgets.org/stable/wx_wxpen.html#__equal__)")
    ADD_CLASS_METHOD(__not_equal__,            "bool wxPen::operator !=(wxPen const & pen) (http://docs.wxwidgets.org/stable/wx_wxpen.html#__not_equal__)")




    void AddMethods(WrapClass<wxPen>::ptr this_ptr );

};


#endif // _wrap_wxPen_h
