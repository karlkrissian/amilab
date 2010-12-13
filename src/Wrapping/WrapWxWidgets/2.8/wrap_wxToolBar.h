/**
 * C++ Interface: wrap_wxToolBar
 *
 * Description: wrapping wxToolBar
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxToolBar_h_
#define _wrap_wxToolBar_h_

/*
#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"
*/

#include "wx_includes.h"

// include what is needed for inheritence and for types ...

#include "wrap_wxToolBarBase.h"


#ifndef wxToolBar_declared
  #define wxToolBar_declared
  AMI_DECLARE_TYPE(wxToolBar);
#endif

// TODO: check for inheritence ...
class WrapClass_wxToolBar : public WrapClass<wxToolBar>
    , public   WrapClass_wxToolBarBase
{
  DEFINE_CLASS(WrapClass_wxToolBar);

  protected:
    typedef WrapClass<wxToolBar>::ptr _parentclass_ptr;
    typedef wxToolBar ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxToolBar>& GetObj() const { return WrapClass<wxToolBar>::GetObj(); }

    /// Constructor
    WrapClass_wxToolBar(boost::shared_ptr<wxToolBar > si): 
    WrapClass<wxToolBar>(si)
    , WrapClass_wxToolBarBase(si)
    {}

    /// Destructor
    ~WrapClass_wxToolBar()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxToolBar_1,"Constructor wxToolBar::wxToolBar() (http://docs.wxwidgets.org/stable/wx_wxtoolbar.html#wxtoolbar).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxToolBar,"Constructor wxToolBar::wxToolBar() (http://docs.wxwidgets.org/stable/wx_wxtoolbar.html#wxtoolbar).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxToolBar_2,"Constructor wxToolBar::wxToolBar(wxWindow * parent, wxWindowID id, wxPoint const & pos = wxDefaultPosition, wxSize const & size = wxDefaultSize, long int style = wxTB_HORIZONTAL, wxString const & name = wxToolBarNameStr) (http://docs.wxwidgets.org/stable/wx_wxtoolbar.html#wxtoolbar).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxToolBar*);

    // Static methods
    
    ADD_CLASS_STATICMETHOD(GetClassDefaultAttributes,"wxVisualAttributes wxToolBar::GetClassDefaultAttributes(wxWindowVariant variant = wxWINDOW_VARIANT_NORMAL) (http://docs.wxwidgets.org/stable/wx_wxtoolbar.html#getclassdefaultattributes).");



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(Create,"bool wxToolBar::Create(wxWindow * parent, wxWindowID id, wxPoint const & pos = wxDefaultPosition, wxSize const & size = wxDefaultSize, long int style = 0, wxString const & name = wxToolBarNameStr)  (http://docs.wxwidgets.org/stable/wx_wxtoolbar.html#create)")
    ADD_CLASS_METHOD(SetMargins,"void wxToolBar::SetMargins(int x, int y)  (http://docs.wxwidgets.org/stable/wx_wxtoolbar.html#setmargins)")
    ADD_CLASS_METHOD(SetToolSeparation,"void wxToolBar::SetToolSeparation(int separation)  (http://docs.wxwidgets.org/stable/wx_wxtoolbar.html#settoolseparation)")
    ADD_CLASS_METHOD(FindToolForPosition,"wxToolBarToolBase * wxToolBar::FindToolForPosition(wxCoord x, wxCoord y)  (http://docs.wxwidgets.org/stable/wx_wxtoolbar.html#findtoolforposition)")
    ADD_CLASS_METHOD(SetToolShortHelp,"void wxToolBar::SetToolShortHelp(int id, wxString const & helpString)  (http://docs.wxwidgets.org/stable/wx_wxtoolbar.html#settoolshorthelp)")
    ADD_CLASS_METHOD(SetWindowStyleFlag,"void wxToolBar::SetWindowStyleFlag(long int style)  (http://docs.wxwidgets.org/stable/wx_wxtoolbar.html#setwindowstyleflag)")
    ADD_CLASS_METHOD(SetToolNormalBitmap,"void wxToolBar::SetToolNormalBitmap(int id, wxBitmap const & bitmap)  (http://docs.wxwidgets.org/stable/wx_wxtoolbar.html#settoolnormalbitmap)")
    ADD_CLASS_METHOD(SetToolDisabledBitmap,"void wxToolBar::SetToolDisabledBitmap(int id, wxBitmap const & bitmap)  (http://docs.wxwidgets.org/stable/wx_wxtoolbar.html#settooldisabledbitmap)")
    ADD_CLASS_METHOD(OnInternalIdle,"void wxToolBar::OnInternalIdle()  (http://docs.wxwidgets.org/stable/wx_wxtoolbar.html#oninternalidle)")
    ADD_CLASS_METHOD(GetClassInfo,"wxClassInfo * wxToolBar::GetClassInfo()  (http://docs.wxwidgets.org/stable/wx_wxtoolbar.html#getclassinfo)")





    void AddMethods(WrapClass<wxToolBar>::ptr this_ptr );
    

};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxToolBar_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_wxToolBar_h
