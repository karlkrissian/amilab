/**
 * C++ Interface: wrap_wxBrush
 *
 * Description: wrapping wxBrush
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxBrush_h_
#define _wrap_wxBrush_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "wx/wx.h"

// include what is needed for inheritence and for types ...

//#include "wrap_wxBrushBase.h"



AMI_DECLARE_TYPE(wxBrush);

// TODO: check for inheritence ...
class WrapClass_wxBrush : public WrapClass<wxBrush>
    //, public  WrapClass_wxBrushBase
{
  DEFINE_CLASS(WrapClass_wxBrush);

  protected:
    typedef WrapClass<wxBrush>::ptr _parentclass_ptr;
    typedef wxBrush ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxBrush>& GetObj() const { return WrapClass<wxBrush>::GetObj(); }

    /// Constructor
    WrapClass_wxBrush(boost::shared_ptr<wxBrush > si): 
    WrapClass<wxBrush>(si)
    //, WrapClass_wxBrushBase(si)
    {}

    /// Destructor
    ~WrapClass_wxBrush()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxBrush_1,"Constructor wxBrush::wxBrush(wxBrush const & param0) (http://docs.wxwidgets.org/stable/wx_wxbrush.html#wxbrush).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxBrush,"Constructor wxBrush::wxBrush() (http://docs.wxwidgets.org/stable/wx_wxbrush.html#wxbrush).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxBrush_2,"Constructor wxBrush::wxBrush() (http://docs.wxwidgets.org/stable/wx_wxbrush.html#wxbrush).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxBrush_3,"Constructor wxBrush::wxBrush(wxColour const & colour, int style = wxSOLID) (http://docs.wxwidgets.org/stable/wx_wxbrush.html#wxbrush).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxBrush_4,"Constructor wxBrush::wxBrush(wxBitmap const & stippleBitmap) (http://docs.wxwidgets.org/stable/wx_wxbrush.html#wxbrush).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxBrush*);

    // Static methods
    



    // Standard methods
    
    // Adding copy method
    ADD_CLASS_METHOD(__copy__,"Copy method, uses the copy constructor.");
    // Adding standard methods
    ADD_CLASS_METHOD(Ok,"bool wxBrush::Ok()  (http://docs.wxwidgets.org/stable/wx_wxbrush.html#ok)")
    ADD_CLASS_METHOD(IsOk,"bool wxBrush::IsOk()  (http://docs.wxwidgets.org/stable/wx_wxbrush.html#isok)")
    ADD_CLASS_METHOD(GetStyle,"int wxBrush::GetStyle()  (http://docs.wxwidgets.org/stable/wx_wxbrush.html#getstyle)")
    ADD_CLASS_METHOD(GetColour,"wxColour & wxBrush::GetColour()  (http://docs.wxwidgets.org/stable/wx_wxbrush.html#getcolour)")
    ADD_CLASS_METHOD(GetStipple,"wxBitmap * wxBrush::GetStipple()  (http://docs.wxwidgets.org/stable/wx_wxbrush.html#getstipple)")
    ADD_CLASS_METHOD(SetColour_1,"void wxBrush::SetColour(wxColour const & col)  (http://docs.wxwidgets.org/stable/wx_wxbrush.html#setcolour)")
    ADD_CLASS_METHOD(SetColour,"wxBrush::SetColour()  (http://docs.wxwidgets.org/stable/wx_wxbrush.html#setcolour)")
    ADD_CLASS_METHOD(SetColour_2,"void wxBrush::SetColour(unsigned char r, unsigned char g, unsigned char b)  (http://docs.wxwidgets.org/stable/wx_wxbrush.html#setcolour)")
    ADD_CLASS_METHOD(SetStyle,"void wxBrush::SetStyle(int style)  (http://docs.wxwidgets.org/stable/wx_wxbrush.html#setstyle)")
    ADD_CLASS_METHOD(SetStipple,"void wxBrush::SetStipple(wxBitmap const & stipple)  (http://docs.wxwidgets.org/stable/wx_wxbrush.html#setstipple)")
    ADD_CLASS_METHOD(GetClassInfo,"wxClassInfo * wxBrush::GetClassInfo()  (http://docs.wxwidgets.org/stable/wx_wxbrush.html#getclassinfo)")

    // Operators:
    ADD_CLASS_METHOD(__assign__,            "wxBrush & wxBrush::operator =(wxBrush const & param0) (http://docs.wxwidgets.org/stable/wx_wxbrush.html#__assign__)")
    ADD_CLASS_METHOD(__equal__,            "bool wxBrush::operator ==(wxBrush const & brush) (http://docs.wxwidgets.org/stable/wx_wxbrush.html#__equal__)")
    ADD_CLASS_METHOD(__not_equal__,            "bool wxBrush::operator !=(wxBrush const & brush) (http://docs.wxwidgets.org/stable/wx_wxbrush.html#__not_equal__)")




    void AddMethods(WrapClass<wxBrush>::ptr this_ptr );

};


#endif // _wrap_wxBrush_h
