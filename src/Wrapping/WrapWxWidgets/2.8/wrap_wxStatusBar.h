/**
 * C++ Interface: wrap_wxStatusBar
 *
 * Description: wrapping wxStatusBar
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxStatusBar_h_
#define _wrap_wxStatusBar_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "wx/wx.h"

// include what is needed for inheritence and for types ...

#include "wrap_wxStatusBarBase.h"



AMI_DECLARE_TYPE(wxStatusBar);

// TODO: check for inheritence ...
class WrapClass_wxStatusBar : public WrapClass<wxStatusBar>
    , public   WrapClass_wxStatusBarBase
{
  DEFINE_CLASS(WrapClass_wxStatusBar);

  protected:
    typedef WrapClass<wxStatusBar>::ptr _parentclass_ptr;
    typedef wxStatusBar ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxStatusBar>& GetObj() const { return WrapClass<wxStatusBar>::GetObj(); }

    /// Constructor
    WrapClass_wxStatusBar(boost::shared_ptr<wxStatusBar > si): 
    WrapClass<wxStatusBar>(si)
    , WrapClass_wxStatusBarBase(si)
    {}

    /// Destructor
    ~WrapClass_wxStatusBar()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxStatusBar_1,"Constructor wxStatusBar::wxStatusBar() (http://docs.wxwidgets.org/stable/wx_wxstatusbar.html#wxstatusbar).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxStatusBar,"Constructor wxStatusBar::wxStatusBar() (http://docs.wxwidgets.org/stable/wx_wxstatusbar.html#wxstatusbar).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxStatusBar_2,"Constructor wxStatusBar::wxStatusBar(wxWindow * parent, wxWindowID winid = wxID_ANY, long int style = 16, wxString const & name = wxStatusBarNameStr) (http://docs.wxwidgets.org/stable/wx_wxstatusbar.html#wxstatusbar).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxStatusBar*);

    // Static methods
    



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(Create,"bool wxStatusBar::Create(wxWindow * parent, wxWindowID winid = wxID_ANY, long int style = 16, wxString const & name = wxStatusBarNameStr)  (http://docs.wxwidgets.org/stable/wx_wxstatusbar.html#create)")
    ADD_CLASS_METHOD(SetFieldsCount,"void wxStatusBar::SetFieldsCount(int number = 1, int const * widths = 0u)  (http://docs.wxwidgets.org/stable/wx_wxstatusbar.html#setfieldscount)")
    ADD_CLASS_METHOD(SetStatusText,"void wxStatusBar::SetStatusText(wxString const & text, int number = 0)  (http://docs.wxwidgets.org/stable/wx_wxstatusbar.html#setstatustext)")
    ADD_CLASS_METHOD(GetStatusText,"wxString wxStatusBar::GetStatusText(int number = 0)  (http://docs.wxwidgets.org/stable/wx_wxstatusbar.html#getstatustext)")
    ADD_CLASS_METHOD(SetStatusWidths,"void wxStatusBar::SetStatusWidths(int n, int const * widths_field)  (http://docs.wxwidgets.org/stable/wx_wxstatusbar.html#setstatuswidths)")
    ADD_CLASS_METHOD(GetFieldRect,"bool wxStatusBar::GetFieldRect(int i, wxRect & rect)  (http://docs.wxwidgets.org/stable/wx_wxstatusbar.html#getfieldrect)")
    ADD_CLASS_METHOD(SetMinHeight,"void wxStatusBar::SetMinHeight(int height)  (http://docs.wxwidgets.org/stable/wx_wxstatusbar.html#setminheight)")
    ADD_CLASS_METHOD(GetBorderX,"int wxStatusBar::GetBorderX()  (http://docs.wxwidgets.org/stable/wx_wxstatusbar.html#getborderx)")
    ADD_CLASS_METHOD(GetBorderY,"int wxStatusBar::GetBorderY()  (http://docs.wxwidgets.org/stable/wx_wxstatusbar.html#getbordery)")
    ADD_CLASS_METHOD(DrawFieldText,"void wxStatusBar::DrawFieldText(wxDC & dc, int i)  (http://docs.wxwidgets.org/stable/wx_wxstatusbar.html#drawfieldtext)")
    ADD_CLASS_METHOD(DrawField,"void wxStatusBar::DrawField(wxDC & dc, int i)  (http://docs.wxwidgets.org/stable/wx_wxstatusbar.html#drawfield)")
    ADD_CLASS_METHOD(OnPaint,"void wxStatusBar::OnPaint(wxPaintEvent & event)  (http://docs.wxwidgets.org/stable/wx_wxstatusbar.html#onpaint)")
    ADD_CLASS_METHOD(OnLeftDown,"void wxStatusBar::OnLeftDown(wxMouseEvent & event)  (http://docs.wxwidgets.org/stable/wx_wxstatusbar.html#onleftdown)")
    ADD_CLASS_METHOD(OnRightDown,"void wxStatusBar::OnRightDown(wxMouseEvent & event)  (http://docs.wxwidgets.org/stable/wx_wxstatusbar.html#onrightdown)")
    ADD_CLASS_METHOD(InitColours,"void wxStatusBar::InitColours()  (http://docs.wxwidgets.org/stable/wx_wxstatusbar.html#initcolours)")
    ADD_CLASS_METHOD(OnSysColourChanged,"void wxStatusBar::OnSysColourChanged(wxSysColourChangedEvent & event)  (http://docs.wxwidgets.org/stable/wx_wxstatusbar.html#onsyscolourchanged)")
    ADD_CLASS_METHOD(GetClassInfo,"wxClassInfo * wxStatusBar::GetClassInfo()  (http://docs.wxwidgets.org/stable/wx_wxstatusbar.html#getclassinfo)")





    void AddMethods(WrapClass<wxStatusBar>::ptr this_ptr );

};


#endif // _wrap_wxStatusBar_h
