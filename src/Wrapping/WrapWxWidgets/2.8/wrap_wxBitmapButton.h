/**
 * C++ Interface: wrap_wxBitmapButton
 *
 * Description: wrapping wxBitmapButton
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxBitmapButton_h_
#define _wrap_wxBitmapButton_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "wx/wx.h"

// include what is needed for inheritence and for types ...

#include "wrap_wxBitmapButtonBase.h"


AMI_DECLARE_TYPE(wxBitmapButton);

// TODO: check for inheritence ...
class WrapClass_wxBitmapButton : public WrapClass<wxBitmapButton>
    , public   WrapClass_wxBitmapButtonBase
{
  DEFINE_CLASS(WrapClass_wxBitmapButton);

  protected:
    typedef WrapClass<wxBitmapButton>::ptr _parentclass_ptr;
    typedef wxBitmapButton ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxBitmapButton>& GetObj() const { return WrapClass<wxBitmapButton>::GetObj(); }

    /// Constructor
    WrapClass_wxBitmapButton(boost::shared_ptr<wxBitmapButton > si): 
    WrapClass<wxBitmapButton>(si)
    , WrapClass_wxBitmapButtonBase(si)
    {}

    /// Destructor
    ~WrapClass_wxBitmapButton()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxBitmapButton_1,"Constructor wxBitmapButton::wxBitmapButton() (http://docs.wxwidgets.org/stable/wx_wxbitmapbutton.html#wxbitmapbutton).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxBitmapButton,"Constructor wxBitmapButton::wxBitmapButton() (http://docs.wxwidgets.org/stable/wx_wxbitmapbutton.html#wxbitmapbutton).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxBitmapButton_2,"Constructor wxBitmapButton::wxBitmapButton(wxWindow * parent, wxWindowID id, wxBitmap const & bitmap, wxPoint const & pos = wxDefaultPosition, wxSize const & size = wxDefaultSize, long int style = 4, wxValidator const & validator = wxDefaultValidator, wxString const & name = wxButtonNameStr) (http://docs.wxwidgets.org/stable/wx_wxbitmapbutton.html#wxbitmapbutton).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxBitmapButton*);

    // Static methods
    



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(Create,"bool wxBitmapButton::Create(wxWindow * parent, wxWindowID id, wxBitmap const & bitmap, wxPoint const & pos = wxDefaultPosition, wxSize const & size = wxDefaultSize, long int style = 4, wxValidator const & validator = wxDefaultValidator, wxString const & name = wxButtonNameStr)  (http://docs.wxwidgets.org/stable/wx_wxbitmapbutton.html#create)")
    ADD_CLASS_METHOD(SetLabel_1,"void wxBitmapButton::SetLabel(wxString const & label)  (http://docs.wxwidgets.org/stable/wx_wxbitmapbutton.html#setlabel)")
    ADD_CLASS_METHOD(SetLabel,"wxBitmapButton::SetLabel()  (http://docs.wxwidgets.org/stable/wx_wxbitmapbutton.html#setlabel)")
    ADD_CLASS_METHOD(SetLabel_2,"void wxBitmapButton::SetLabel(wxBitmap const & bitmap)  (http://docs.wxwidgets.org/stable/wx_wxbitmapbutton.html#setlabel)")
    ADD_CLASS_METHOD(SetDefault,"void wxBitmapButton::SetDefault()  (http://docs.wxwidgets.org/stable/wx_wxbitmapbutton.html#setdefault)")
    ADD_CLASS_METHOD(Enable,"bool wxBitmapButton::Enable(bool enable = 1)  (http://docs.wxwidgets.org/stable/wx_wxbitmapbutton.html#enable)")
    ADD_CLASS_METHOD(HasFocus,"void wxBitmapButton::HasFocus()  (http://docs.wxwidgets.org/stable/wx_wxbitmapbutton.html#hasfocus)")
    ADD_CLASS_METHOD(NotFocus,"void wxBitmapButton::NotFocus()  (http://docs.wxwidgets.org/stable/wx_wxbitmapbutton.html#notfocus)")
    ADD_CLASS_METHOD(StartSelect,"void wxBitmapButton::StartSelect()  (http://docs.wxwidgets.org/stable/wx_wxbitmapbutton.html#startselect)")
    ADD_CLASS_METHOD(EndSelect,"void wxBitmapButton::EndSelect()  (http://docs.wxwidgets.org/stable/wx_wxbitmapbutton.html#endselect)")
    ADD_CLASS_METHOD(GetClassInfo,"wxClassInfo * wxBitmapButton::GetClassInfo()  (http://docs.wxwidgets.org/stable/wx_wxbitmapbutton.html#getclassinfo)")





    void AddMethods(WrapClass<wxBitmapButton>::ptr this_ptr );

};


#endif // _wrap_wxBitmapButton_h
