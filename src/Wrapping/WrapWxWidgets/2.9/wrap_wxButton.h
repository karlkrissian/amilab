/**
 * C++ Interface: wrap_wxButton
 *
 * Description: wrapping wxButton
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxButton_h_
#define _wrap_wxButton_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "wx/wx.h"

// include what is needed for inheritence and for types ...

#include "wrap_wxButtonBase.h"


AMI_DECLARE_TYPE(wxButton);

// TODO: check for inheritence ...
class WrapClass_wxButton : public WrapClass<wxButton>
    , public   WrapClass_wxButtonBase
{
  DEFINE_CLASS(WrapClass_wxButton);

  protected:
    typedef WrapClass<wxButton>::ptr _parentclass_ptr;
    typedef wxButton ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxButton>& GetObj() const { return WrapClass<wxButton>::GetObj(); }

    /// Constructor
    WrapClass_wxButton(boost::shared_ptr<wxButton > si): 
    WrapClass<wxButton>(si)
    , WrapClass_wxButtonBase(si)
    {}

    /// Destructor
    ~WrapClass_wxButton()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxButton_1,"Constructor wxButton::wxButton() (http://docs.wxwidgets.org/stable/wx_wxbutton.html#wxbutton).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxButton,"Constructor wxButton::wxButton() (http://docs.wxwidgets.org/stable/wx_wxbutton.html#wxbutton).");
    /* The following types are missing: wxValidator
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxButton_2,"Constructor wxButton::wxButton(wxWindow * parent, wxWindowID id, wxString const & label = wxEmptyString, wxPoint const & pos = wxDefaultPosition, wxSize const & size = wxDefaultSize, long int style = 0, wxValidator const & validator = wxDefaultValidator, wxString const & name = wxButtonNameStr) (http://docs.wxwidgets.org/stable/wx_wxbutton.html#wxbutton).");
    */



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxButton*);

    // here add each method
    
    // Adding standard methods
/* The following types are missing: wxValidator
    ADD_CLASS_METHOD(Create,"bool wxButton::Create(wxWindow * parent, wxWindowID id, wxString const & label = wxEmptyString, wxPoint const & pos = wxDefaultPosition, wxSize const & size = wxDefaultSize, long int style = 0, wxValidator const & validator = wxDefaultValidator, wxString const & name = wxButtonNameStr)  (http://docs.wxwidgets.org/stable/wx_wxbutton.html#create)")
*/
    ADD_CLASS_METHOD(SetDefault,"wxWindow * wxButton::SetDefault()  (http://docs.wxwidgets.org/stable/wx_wxbutton.html#setdefault)")
    ADD_CLASS_METHOD(SetLabel,"void wxButton::SetLabel(wxString const & label)  (http://docs.wxwidgets.org/stable/wx_wxbutton.html#setlabel)")
    ADD_CLASS_METHOD(Enable,"bool wxButton::Enable(bool enable = true)  (http://docs.wxwidgets.org/stable/wx_wxbutton.html#enable)")
/* The following types are missing: wxVisualAttributes
    ADD_CLASS_METHOD(GetClassDefaultAttributes,"wxVisualAttributes wxButton::GetClassDefaultAttributes(wxWindowVariant variant = wxWINDOW_VARIANT_NORMAL)  (http://docs.wxwidgets.org/stable/wx_wxbutton.html#getclassdefaultattributes)")
*/
    ADD_CLASS_METHOD(MoveWindow,"void wxButton::MoveWindow(int x, int y, int width, int height)  (http://docs.wxwidgets.org/stable/wx_wxbutton.html#movewindow)")
    ADD_CLASS_METHOD(GTKMouseEnters,"void wxButton::GTKMouseEnters()  (http://docs.wxwidgets.org/stable/wx_wxbutton.html#gtkmouseenters)")
    ADD_CLASS_METHOD(GTKMouseLeaves,"void wxButton::GTKMouseLeaves()  (http://docs.wxwidgets.org/stable/wx_wxbutton.html#gtkmouseleaves)")
    ADD_CLASS_METHOD(GTKPressed,"void wxButton::GTKPressed()  (http://docs.wxwidgets.org/stable/wx_wxbutton.html#gtkpressed)")
    ADD_CLASS_METHOD(GTKReleased,"void wxButton::GTKReleased()  (http://docs.wxwidgets.org/stable/wx_wxbutton.html#gtkreleased)")
    ADD_CLASS_METHOD(GetClassInfo,"wxClassInfo * wxButton::GetClassInfo()  (http://docs.wxwidgets.org/stable/wx_wxbutton.html#getclassinfo)")





    void AddMethods(WrapClass<wxButton>::ptr this_ptr );

};


#endif // _wrap_wxButton_h
