/**
 * C++ Interface: wrap_wxRect
 *
 * Description: wrapping wxRect
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxRect_h_
#define _wrap_wxRect_h_

/*
#include "Variable.hpp"
#include "ami_object.h"
*/
#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "paramlist.h"

#include "wx_includes.h"

// include what is needed for inheritence and for types ...



#ifndef wxRect_declared
  #define wxRect_declared
  AMI_DECLARE_TYPE(wxRect);
#endif

// TODO: check for inheritence ...
class WrapClass_wxRect : public WrapClass<wxRect>
    
{
  DEFINE_CLASS(WrapClass_wxRect);

  protected:
    typedef WrapClass<wxRect>::ptr _parentclass_ptr;
    typedef wxRect ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxRect>& GetObj() const { return WrapClass<wxRect>::GetObj(); }

    /// Constructor
    WrapClass_wxRect(boost::shared_ptr<wxRect > si): 
    WrapClass<wxRect>(si)
    
    {}

    /// Destructor
    ~WrapClass_wxRect()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxRect_1,"Constructor wxRect::wxRect(wxRect const & param0) (http://docs.wxwidgets.org/stable/wx_wxrect.html#wxrect).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxRect,"Constructor wxRect::wxRect() (http://docs.wxwidgets.org/stable/wx_wxrect.html#wxrect).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxRect_2,"Constructor wxRect::wxRect() (http://docs.wxwidgets.org/stable/wx_wxrect.html#wxrect).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxRect_3,"Constructor wxRect::wxRect(int xx, int yy, int ww, int hh) (http://docs.wxwidgets.org/stable/wx_wxrect.html#wxrect).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxRect_4,"Constructor wxRect::wxRect(wxPoint const & topLeft, wxPoint const & bottomRight) (http://docs.wxwidgets.org/stable/wx_wxrect.html#wxrect).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxRect_5,"Constructor wxRect::wxRect(wxPoint const & pt, wxSize const & size) (http://docs.wxwidgets.org/stable/wx_wxrect.html#wxrect).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxRect_6,"Constructor wxRect::wxRect(wxSize const & size) (http://docs.wxwidgets.org/stable/wx_wxrect.html#wxrect).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxRect*);

    // Static methods
    



    // Standard methods
    
    // Adding copy method
    ADD_CLASS_METHOD(__copy__,"Copy method, uses the copy constructor.");
    // Adding standard methods
    ADD_CLASS_METHOD(GetX,"int wxRect::GetX()  (http://docs.wxwidgets.org/stable/wx_wxrect.html#getx)")
    ADD_CLASS_METHOD(SetX,"void wxRect::SetX(int xx)  (http://docs.wxwidgets.org/stable/wx_wxrect.html#setx)")
    ADD_CLASS_METHOD(GetY,"int wxRect::GetY()  (http://docs.wxwidgets.org/stable/wx_wxrect.html#gety)")
    ADD_CLASS_METHOD(SetY,"void wxRect::SetY(int yy)  (http://docs.wxwidgets.org/stable/wx_wxrect.html#sety)")
    ADD_CLASS_METHOD(GetWidth,"int wxRect::GetWidth()  (http://docs.wxwidgets.org/stable/wx_wxrect.html#getwidth)")
    ADD_CLASS_METHOD(SetWidth,"void wxRect::SetWidth(int w)  (http://docs.wxwidgets.org/stable/wx_wxrect.html#setwidth)")
    ADD_CLASS_METHOD(GetHeight,"int wxRect::GetHeight()  (http://docs.wxwidgets.org/stable/wx_wxrect.html#getheight)")
    ADD_CLASS_METHOD(SetHeight,"void wxRect::SetHeight(int h)  (http://docs.wxwidgets.org/stable/wx_wxrect.html#setheight)")
    ADD_CLASS_METHOD(GetPosition,"wxPoint wxRect::GetPosition()  (http://docs.wxwidgets.org/stable/wx_wxrect.html#getposition)")
    ADD_CLASS_METHOD(SetPosition,"void wxRect::SetPosition(wxPoint const & p)  (http://docs.wxwidgets.org/stable/wx_wxrect.html#setposition)")
    ADD_CLASS_METHOD(GetSize,"wxSize wxRect::GetSize()  (http://docs.wxwidgets.org/stable/wx_wxrect.html#getsize)")
    ADD_CLASS_METHOD(SetSize,"void wxRect::SetSize(wxSize const & s)  (http://docs.wxwidgets.org/stable/wx_wxrect.html#setsize)")
    ADD_CLASS_METHOD(IsEmpty,"bool wxRect::IsEmpty()  (http://docs.wxwidgets.org/stable/wx_wxrect.html#isempty)")
    ADD_CLASS_METHOD(GetLeft,"int wxRect::GetLeft()  (http://docs.wxwidgets.org/stable/wx_wxrect.html#getleft)")
    ADD_CLASS_METHOD(GetTop,"int wxRect::GetTop()  (http://docs.wxwidgets.org/stable/wx_wxrect.html#gettop)")
    ADD_CLASS_METHOD(GetBottom,"int wxRect::GetBottom()  (http://docs.wxwidgets.org/stable/wx_wxrect.html#getbottom)")
    ADD_CLASS_METHOD(GetRight,"int wxRect::GetRight()  (http://docs.wxwidgets.org/stable/wx_wxrect.html#getright)")
    ADD_CLASS_METHOD(SetLeft,"void wxRect::SetLeft(int left)  (http://docs.wxwidgets.org/stable/wx_wxrect.html#setleft)")
    ADD_CLASS_METHOD(SetRight,"void wxRect::SetRight(int right)  (http://docs.wxwidgets.org/stable/wx_wxrect.html#setright)")
    ADD_CLASS_METHOD(SetTop,"void wxRect::SetTop(int top)  (http://docs.wxwidgets.org/stable/wx_wxrect.html#settop)")
    ADD_CLASS_METHOD(SetBottom,"void wxRect::SetBottom(int bottom)  (http://docs.wxwidgets.org/stable/wx_wxrect.html#setbottom)")
    ADD_CLASS_METHOD(GetTopLeft,"wxPoint wxRect::GetTopLeft()  (http://docs.wxwidgets.org/stable/wx_wxrect.html#gettopleft)")
    ADD_CLASS_METHOD(GetLeftTop,"wxPoint wxRect::GetLeftTop()  (http://docs.wxwidgets.org/stable/wx_wxrect.html#getlefttop)")
    ADD_CLASS_METHOD(SetTopLeft,"void wxRect::SetTopLeft(wxPoint const & p)  (http://docs.wxwidgets.org/stable/wx_wxrect.html#settopleft)")
    ADD_CLASS_METHOD(SetLeftTop,"void wxRect::SetLeftTop(wxPoint const & p)  (http://docs.wxwidgets.org/stable/wx_wxrect.html#setlefttop)")
    ADD_CLASS_METHOD(GetBottomRight,"wxPoint wxRect::GetBottomRight()  (http://docs.wxwidgets.org/stable/wx_wxrect.html#getbottomright)")
    ADD_CLASS_METHOD(GetRightBottom,"wxPoint wxRect::GetRightBottom()  (http://docs.wxwidgets.org/stable/wx_wxrect.html#getrightbottom)")
    ADD_CLASS_METHOD(SetBottomRight,"void wxRect::SetBottomRight(wxPoint const & p)  (http://docs.wxwidgets.org/stable/wx_wxrect.html#setbottomright)")
    ADD_CLASS_METHOD(SetRightBottom,"void wxRect::SetRightBottom(wxPoint const & p)  (http://docs.wxwidgets.org/stable/wx_wxrect.html#setrightbottom)")
    ADD_CLASS_METHOD(GetTopRight,"wxPoint wxRect::GetTopRight()  (http://docs.wxwidgets.org/stable/wx_wxrect.html#gettopright)")
    ADD_CLASS_METHOD(GetRightTop,"wxPoint wxRect::GetRightTop()  (http://docs.wxwidgets.org/stable/wx_wxrect.html#getrighttop)")
    ADD_CLASS_METHOD(SetTopRight,"void wxRect::SetTopRight(wxPoint const & p)  (http://docs.wxwidgets.org/stable/wx_wxrect.html#settopright)")
    ADD_CLASS_METHOD(SetRightTop,"void wxRect::SetRightTop(wxPoint const & p)  (http://docs.wxwidgets.org/stable/wx_wxrect.html#setrighttop)")
    ADD_CLASS_METHOD(GetBottomLeft,"wxPoint wxRect::GetBottomLeft()  (http://docs.wxwidgets.org/stable/wx_wxrect.html#getbottomleft)")
    ADD_CLASS_METHOD(GetLeftBottom,"wxPoint wxRect::GetLeftBottom()  (http://docs.wxwidgets.org/stable/wx_wxrect.html#getleftbottom)")
    ADD_CLASS_METHOD(SetBottomLeft,"void wxRect::SetBottomLeft(wxPoint const & p)  (http://docs.wxwidgets.org/stable/wx_wxrect.html#setbottomleft)")
    ADD_CLASS_METHOD(SetLeftBottom,"void wxRect::SetLeftBottom(wxPoint const & p)  (http://docs.wxwidgets.org/stable/wx_wxrect.html#setleftbottom)")
    ADD_CLASS_METHOD(Inflate_1,"wxRect & wxRect::Inflate(wxCoord dx, wxCoord dy)  (http://docs.wxwidgets.org/stable/wx_wxrect.html#inflate)")
    ADD_CLASS_METHOD(Inflate,"wxRect::Inflate()  (http://docs.wxwidgets.org/stable/wx_wxrect.html#inflate)")
    ADD_CLASS_METHOD(Inflate_2,"wxRect & wxRect::Inflate(wxSize const & d)  (http://docs.wxwidgets.org/stable/wx_wxrect.html#inflate)")
    ADD_CLASS_METHOD(Inflate_3,"wxRect & wxRect::Inflate(wxCoord d)  (http://docs.wxwidgets.org/stable/wx_wxrect.html#inflate)")
    ADD_CLASS_METHOD(Inflate_4,"wxRect wxRect::Inflate(wxCoord dx, wxCoord dy)  (http://docs.wxwidgets.org/stable/wx_wxrect.html#inflate)")
    ADD_CLASS_METHOD(Deflate_1,"wxRect & wxRect::Deflate(wxCoord dx, wxCoord dy)  (http://docs.wxwidgets.org/stable/wx_wxrect.html#deflate)")
    ADD_CLASS_METHOD(Deflate,"wxRect::Deflate()  (http://docs.wxwidgets.org/stable/wx_wxrect.html#deflate)")
    ADD_CLASS_METHOD(Deflate_2,"wxRect & wxRect::Deflate(wxSize const & d)  (http://docs.wxwidgets.org/stable/wx_wxrect.html#deflate)")
    ADD_CLASS_METHOD(Deflate_3,"wxRect & wxRect::Deflate(wxCoord d)  (http://docs.wxwidgets.org/stable/wx_wxrect.html#deflate)")
    ADD_CLASS_METHOD(Deflate_4,"wxRect wxRect::Deflate(wxCoord dx, wxCoord dy)  (http://docs.wxwidgets.org/stable/wx_wxrect.html#deflate)")
    ADD_CLASS_METHOD(Offset_1,"void wxRect::Offset(wxCoord dx, wxCoord dy)  (http://docs.wxwidgets.org/stable/wx_wxrect.html#offset)")
    ADD_CLASS_METHOD(Offset,"wxRect::Offset()  (http://docs.wxwidgets.org/stable/wx_wxrect.html#offset)")
    ADD_CLASS_METHOD(Offset_2,"void wxRect::Offset(wxPoint const & pt)  (http://docs.wxwidgets.org/stable/wx_wxrect.html#offset)")
    ADD_CLASS_METHOD(Intersect_1,"wxRect & wxRect::Intersect(wxRect const & rect)  (http://docs.wxwidgets.org/stable/wx_wxrect.html#intersect)")
    ADD_CLASS_METHOD(Intersect,"wxRect::Intersect()  (http://docs.wxwidgets.org/stable/wx_wxrect.html#intersect)")
    ADD_CLASS_METHOD(Intersect_2,"wxRect wxRect::Intersect(wxRect const & rect)  (http://docs.wxwidgets.org/stable/wx_wxrect.html#intersect)")
    ADD_CLASS_METHOD(Union_1,"wxRect & wxRect::Union(wxRect const & rect)  (http://docs.wxwidgets.org/stable/wx_wxrect.html#union)")
    ADD_CLASS_METHOD(Union,"wxRect::Union()  (http://docs.wxwidgets.org/stable/wx_wxrect.html#union)")
    ADD_CLASS_METHOD(Union_2,"wxRect wxRect::Union(wxRect const & rect)  (http://docs.wxwidgets.org/stable/wx_wxrect.html#union)")
    ADD_CLASS_METHOD(Contains_1,"bool wxRect::Contains(int x, int y)  (http://docs.wxwidgets.org/stable/wx_wxrect.html#contains)")
    ADD_CLASS_METHOD(Contains,"wxRect::Contains()  (http://docs.wxwidgets.org/stable/wx_wxrect.html#contains)")
    ADD_CLASS_METHOD(Contains_2,"bool wxRect::Contains(wxPoint const & pt)  (http://docs.wxwidgets.org/stable/wx_wxrect.html#contains)")
    ADD_CLASS_METHOD(Contains_3,"bool wxRect::Contains(wxRect const & rect)  (http://docs.wxwidgets.org/stable/wx_wxrect.html#contains)")
    ADD_CLASS_METHOD(Intersects,"bool wxRect::Intersects(wxRect const & rect)  (http://docs.wxwidgets.org/stable/wx_wxrect.html#intersects)")
    ADD_CLASS_METHOD(CentreIn,"wxRect wxRect::CentreIn(wxRect const & r, int dir = wxBOTH)  (http://docs.wxwidgets.org/stable/wx_wxrect.html#centrein)")
    ADD_CLASS_METHOD(CenterIn,"wxRect wxRect::CenterIn(wxRect const & r, int dir = wxBOTH)  (http://docs.wxwidgets.org/stable/wx_wxrect.html#centerin)")

    // Operators:
    ADD_CLASS_METHOD(__assign__,            "wxRect & wxRect::operator =(wxRect const & param0) (http://docs.wxwidgets.org/stable/wx_wxrect.html#__assign__)")
    ADD_CLASS_METHOD(__equal__,            "bool wxRect::operator ==(wxRect const & rect) (http://docs.wxwidgets.org/stable/wx_wxrect.html#__equal__)")
    ADD_CLASS_METHOD(__not_equal__,            "bool wxRect::operator !=(wxRect const & rect) (http://docs.wxwidgets.org/stable/wx_wxrect.html#__not_equal__)")
    ADD_CLASS_METHOD(__add__,            "wxRect wxRect::operator +(wxRect const & rect) (http://docs.wxwidgets.org/stable/wx_wxrect.html#__add__)")
    ADD_CLASS_METHOD(__add_assign__,            "wxRect & wxRect::operator +=(wxRect const & rect) (http://docs.wxwidgets.org/stable/wx_wxrect.html#__add_assign__)")




    void AddMethods(WrapClass<wxRect>::ptr this_ptr );
    

};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxRect_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_wxRect_h
