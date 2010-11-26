/**
 * C++ Interface: wrap_wxValidator
 *
 * Description: wrapping wxValidator
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxValidator_h_
#define _wrap_wxValidator_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "wx/wx.h"

// include what is needed for inheritence and for types ...

#include "wrap_wxEvtHandler.h"



AMI_DECLARE_TYPE(wxValidator);

// TODO: check for inheritence ...
class WrapClass_wxValidator : public WrapClass<wxValidator>
    , public   WrapClass_wxEvtHandler
{
  DEFINE_CLASS(WrapClass_wxValidator);

  protected:
    typedef WrapClass<wxValidator>::ptr _parentclass_ptr;
    typedef wxValidator ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxValidator>& GetObj() const { return WrapClass<wxValidator>::GetObj(); }

    /// Constructor
    WrapClass_wxValidator(boost::shared_ptr<wxValidator > si): 
    WrapClass<wxValidator>(si)
    , WrapClass_wxEvtHandler(si)
    {}

    /// Destructor
    ~WrapClass_wxValidator()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxValidator,"Constructor wxValidator::wxValidator() (http://docs.wxwidgets.org/stable/wx_wxvalidator.html#wxvalidator).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxValidator*);

    // Static methods
    
    ADD_CLASS_STATICMETHOD(IsSilent,"bool wxValidator::IsSilent() (http://docs.wxwidgets.org/stable/wx_wxvalidator.html#issilent).");
    ADD_CLASS_STATICMETHOD(SetBellOnError,"void wxValidator::SetBellOnError(bool doIt = true) (http://docs.wxwidgets.org/stable/wx_wxvalidator.html#setbellonerror).");



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(Clone,"wxObject * wxValidator::Clone()  (http://docs.wxwidgets.org/stable/wx_wxvalidator.html#clone)")
    ADD_CLASS_METHOD(Copy,"bool wxValidator::Copy(wxValidator const & val)  (http://docs.wxwidgets.org/stable/wx_wxvalidator.html#copy)")
    ADD_CLASS_METHOD(Validate,"bool wxValidator::Validate(wxWindow * param0)  (http://docs.wxwidgets.org/stable/wx_wxvalidator.html#validate)")
    ADD_CLASS_METHOD(TransferToWindow,"bool wxValidator::TransferToWindow()  (http://docs.wxwidgets.org/stable/wx_wxvalidator.html#transfertowindow)")
    ADD_CLASS_METHOD(TransferFromWindow,"bool wxValidator::TransferFromWindow()  (http://docs.wxwidgets.org/stable/wx_wxvalidator.html#transferfromwindow)")
    ADD_CLASS_METHOD(GetWindow,"wxWindow * wxValidator::GetWindow()  (http://docs.wxwidgets.org/stable/wx_wxvalidator.html#getwindow)")
    ADD_CLASS_METHOD(SetWindow,"void wxValidator::SetWindow(wxWindowBase * win)  (http://docs.wxwidgets.org/stable/wx_wxvalidator.html#setwindow)")
    ADD_CLASS_METHOD(GetClassInfo,"wxClassInfo * wxValidator::GetClassInfo()  (http://docs.wxwidgets.org/stable/wx_wxvalidator.html#getclassinfo)")





    void AddMethods(WrapClass<wxValidator>::ptr this_ptr );

};


#endif // _wrap_wxValidator_h
