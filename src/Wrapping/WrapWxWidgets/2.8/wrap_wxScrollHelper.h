/**
 * C++ Interface: wrap_wxScrollHelper
 *
 * Description: wrapping wxScrollHelper
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxScrollHelper_h_
#define _wrap_wxScrollHelper_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "wx/wx.h"

// include what is needed for inheritence and for types ...




AMI_DECLARE_TYPE(wxScrollHelper);

// TODO: check for inheritence ...
class WrapClass_wxScrollHelper : public WrapClass<wxScrollHelper>
    
{
  DEFINE_CLASS(WrapClass_wxScrollHelper);

  protected:
    typedef WrapClass<wxScrollHelper>::ptr _parentclass_ptr;
    typedef wxScrollHelper ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxScrollHelper>& GetObj() const { return WrapClass<wxScrollHelper>::GetObj(); }

    /// Constructor
    WrapClass_wxScrollHelper(boost::shared_ptr<wxScrollHelper > si): 
    WrapClass<wxScrollHelper>(si)
    
    {}

    /// Destructor
    ~WrapClass_wxScrollHelper()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxScrollHelper,"Constructor wxScrollHelper::wxScrollHelper(wxWindow * winToScroll) (http://docs.wxwidgets.org/stable/wx_wxscrollhelper.html#wxscrollhelper).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxScrollHelper*);

    // Static methods
    



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(SetScrollbars,"void wxScrollHelper::SetScrollbars(int pixelsPerUnitX, int pixelsPerUnitY, int noUnitsX, int noUnitsY, int xPos = 0, int yPos = 0, bool noRefresh = false)  (http://docs.wxwidgets.org/stable/wx_wxscrollhelper.html#setscrollbars)")
    ADD_CLASS_METHOD(Scroll,"void wxScrollHelper::Scroll(int x, int y)  (http://docs.wxwidgets.org/stable/wx_wxscrollhelper.html#scroll)")
    ADD_CLASS_METHOD(GetScrollPageSize,"int wxScrollHelper::GetScrollPageSize(int orient)  (http://docs.wxwidgets.org/stable/wx_wxscrollhelper.html#getscrollpagesize)")
    ADD_CLASS_METHOD(SetScrollPageSize,"void wxScrollHelper::SetScrollPageSize(int orient, int pageSize)  (http://docs.wxwidgets.org/stable/wx_wxscrollhelper.html#setscrollpagesize)")
    ADD_CLASS_METHOD(GetScrollLines,"int wxScrollHelper::GetScrollLines(int orient)  (http://docs.wxwidgets.org/stable/wx_wxscrollhelper.html#getscrolllines)")
    ADD_CLASS_METHOD(SetScrollRate,"void wxScrollHelper::SetScrollRate(int xstep, int ystep)  (http://docs.wxwidgets.org/stable/wx_wxscrollhelper.html#setscrollrate)")
    ADD_CLASS_METHOD(GetScrollPixelsPerUnit,"void wxScrollHelper::GetScrollPixelsPerUnit(int * pixelsPerUnitX, int * pixelsPerUnitY)  (http://docs.wxwidgets.org/stable/wx_wxscrollhelper.html#getscrollpixelsperunit)")
    ADD_CLASS_METHOD(EnableScrolling,"void wxScrollHelper::EnableScrolling(bool x_scrolling, bool y_scrolling)  (http://docs.wxwidgets.org/stable/wx_wxscrollhelper.html#enablescrolling)")
    ADD_CLASS_METHOD(GetViewStart,"void wxScrollHelper::GetViewStart(int * x, int * y)  (http://docs.wxwidgets.org/stable/wx_wxscrollhelper.html#getviewstart)")
    ADD_CLASS_METHOD(SetScale,"void wxScrollHelper::SetScale(double xs, double ys)  (http://docs.wxwidgets.org/stable/wx_wxscrollhelper.html#setscale)")
    ADD_CLASS_METHOD(GetScaleX,"double wxScrollHelper::GetScaleX()  (http://docs.wxwidgets.org/stable/wx_wxscrollhelper.html#getscalex)")
    ADD_CLASS_METHOD(GetScaleY,"double wxScrollHelper::GetScaleY()  (http://docs.wxwidgets.org/stable/wx_wxscrollhelper.html#getscaley)")
    ADD_CLASS_METHOD(CalcScrolledPosition_1,"void wxScrollHelper::CalcScrolledPosition(int x, int y, int * xx, int * yy)  (http://docs.wxwidgets.org/stable/wx_wxscrollhelper.html#calcscrolledposition)")
    ADD_CLASS_METHOD(CalcScrolledPosition,"wxScrollHelper::CalcScrolledPosition()  (http://docs.wxwidgets.org/stable/wx_wxscrollhelper.html#calcscrolledposition)")
    ADD_CLASS_METHOD(CalcScrolledPosition_2,"wxPoint wxScrollHelper::CalcScrolledPosition(wxPoint const & pt)  (http://docs.wxwidgets.org/stable/wx_wxscrollhelper.html#calcscrolledposition)")
    ADD_CLASS_METHOD(CalcUnscrolledPosition_1,"void wxScrollHelper::CalcUnscrolledPosition(int x, int y, int * xx, int * yy)  (http://docs.wxwidgets.org/stable/wx_wxscrollhelper.html#calcunscrolledposition)")
    ADD_CLASS_METHOD(CalcUnscrolledPosition,"wxScrollHelper::CalcUnscrolledPosition()  (http://docs.wxwidgets.org/stable/wx_wxscrollhelper.html#calcunscrolledposition)")
    ADD_CLASS_METHOD(CalcUnscrolledPosition_2,"wxPoint wxScrollHelper::CalcUnscrolledPosition(wxPoint const & pt)  (http://docs.wxwidgets.org/stable/wx_wxscrollhelper.html#calcunscrolledposition)")
    ADD_CLASS_METHOD(DoCalcScrolledPosition,"void wxScrollHelper::DoCalcScrolledPosition(int x, int y, int * xx, int * yy)  (http://docs.wxwidgets.org/stable/wx_wxscrollhelper.html#docalcscrolledposition)")
    ADD_CLASS_METHOD(DoCalcUnscrolledPosition,"void wxScrollHelper::DoCalcUnscrolledPosition(int x, int y, int * xx, int * yy)  (http://docs.wxwidgets.org/stable/wx_wxscrollhelper.html#docalcunscrolledposition)")
    ADD_CLASS_METHOD(AdjustScrollbars,"void wxScrollHelper::AdjustScrollbars()  (http://docs.wxwidgets.org/stable/wx_wxscrollhelper.html#adjustscrollbars)")
    ADD_CLASS_METHOD(CalcScrollInc,"int wxScrollHelper::CalcScrollInc(wxScrollWinEvent & event)  (http://docs.wxwidgets.org/stable/wx_wxscrollhelper.html#calcscrollinc)")
    ADD_CLASS_METHOD(SetTargetWindow,"void wxScrollHelper::SetTargetWindow(wxWindow * target)  (http://docs.wxwidgets.org/stable/wx_wxscrollhelper.html#settargetwindow)")
    ADD_CLASS_METHOD(GetTargetWindow,"wxWindow * wxScrollHelper::GetTargetWindow()  (http://docs.wxwidgets.org/stable/wx_wxscrollhelper.html#gettargetwindow)")
    ADD_CLASS_METHOD(SetTargetRect,"void wxScrollHelper::SetTargetRect(wxRect const & rect)  (http://docs.wxwidgets.org/stable/wx_wxscrollhelper.html#settargetrect)")
    ADD_CLASS_METHOD(GetTargetRect,"wxRect wxScrollHelper::GetTargetRect()  (http://docs.wxwidgets.org/stable/wx_wxscrollhelper.html#gettargetrect)")
    ADD_CLASS_METHOD(OnDraw,"void wxScrollHelper::OnDraw(wxDC & param0)  (http://docs.wxwidgets.org/stable/wx_wxscrollhelper.html#ondraw)")
    ADD_CLASS_METHOD(DoPrepareDC,"void wxScrollHelper::DoPrepareDC(wxDC & dc)  (http://docs.wxwidgets.org/stable/wx_wxscrollhelper.html#dopreparedc)")
    ADD_CLASS_METHOD(IsAutoScrolling,"bool wxScrollHelper::IsAutoScrolling()  (http://docs.wxwidgets.org/stable/wx_wxscrollhelper.html#isautoscrolling)")
    ADD_CLASS_METHOD(StopAutoScrolling,"void wxScrollHelper::StopAutoScrolling()  (http://docs.wxwidgets.org/stable/wx_wxscrollhelper.html#stopautoscrolling)")
    ADD_CLASS_METHOD(SendAutoScrollEvents,"bool wxScrollHelper::SendAutoScrollEvents(wxScrollWinEvent & event)  (http://docs.wxwidgets.org/stable/wx_wxscrollhelper.html#sendautoscrollevents)")
    ADD_CLASS_METHOD(HandleOnScroll,"void wxScrollHelper::HandleOnScroll(wxScrollWinEvent & event)  (http://docs.wxwidgets.org/stable/wx_wxscrollhelper.html#handleonscroll)")
    ADD_CLASS_METHOD(HandleOnSize,"void wxScrollHelper::HandleOnSize(wxSizeEvent & event)  (http://docs.wxwidgets.org/stable/wx_wxscrollhelper.html#handleonsize)")
    ADD_CLASS_METHOD(HandleOnPaint,"void wxScrollHelper::HandleOnPaint(wxPaintEvent & event)  (http://docs.wxwidgets.org/stable/wx_wxscrollhelper.html#handleonpaint)")
    ADD_CLASS_METHOD(HandleOnChar,"void wxScrollHelper::HandleOnChar(wxKeyEvent & event)  (http://docs.wxwidgets.org/stable/wx_wxscrollhelper.html#handleonchar)")
    ADD_CLASS_METHOD(HandleOnMouseEnter,"void wxScrollHelper::HandleOnMouseEnter(wxMouseEvent & event)  (http://docs.wxwidgets.org/stable/wx_wxscrollhelper.html#handleonmouseenter)")
    ADD_CLASS_METHOD(HandleOnMouseLeave,"void wxScrollHelper::HandleOnMouseLeave(wxMouseEvent & event)  (http://docs.wxwidgets.org/stable/wx_wxscrollhelper.html#handleonmouseleave)")
    ADD_CLASS_METHOD(HandleOnMouseWheel,"void wxScrollHelper::HandleOnMouseWheel(wxMouseEvent & event)  (http://docs.wxwidgets.org/stable/wx_wxscrollhelper.html#handleonmousewheel)")
    ADD_CLASS_METHOD(HandleOnChildFocus,"void wxScrollHelper::HandleOnChildFocus(wxChildFocusEvent & event)  (http://docs.wxwidgets.org/stable/wx_wxscrollhelper.html#handleonchildfocus)")
    ADD_CLASS_METHOD(OnScroll,"void wxScrollHelper::OnScroll(wxScrollWinEvent & event)  (http://docs.wxwidgets.org/stable/wx_wxscrollhelper.html#onscroll)")





    void AddMethods(WrapClass<wxScrollHelper>::ptr this_ptr );

};


#endif // _wrap_wxScrollHelper_h
