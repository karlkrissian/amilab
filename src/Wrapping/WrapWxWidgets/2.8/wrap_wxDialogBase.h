/**
 * C++ Interface: wrap_wxDialogBase
 *
 * Description: wrapping wxDialogBase
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxDialogBase_h_
#define _wrap_wxDialogBase_h_

/*
#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"
*/

#include "wx_includes.h"

// include what is needed for inheritence and for types ...

#include "wrap_wxTopLevelWindow.h"


#ifndef wxDialogBase_declared
  #define wxDialogBase_declared
  AMI_DECLARE_TYPE(wxDialogBase);
#endif

// TODO: check for inheritence ...
class WrapClass_wxDialogBase : public WrapClass<wxDialogBase>
    , public   WrapClass_wxTopLevelWindow
{
  DEFINE_CLASS(WrapClass_wxDialogBase);

  protected:
    typedef WrapClass<wxDialogBase>::ptr _parentclass_ptr;
    typedef wxDialogBase ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxDialogBase>& GetObj() const { return WrapClass<wxDialogBase>::GetObj(); }

    /// Constructor
    WrapClass_wxDialogBase(boost::shared_ptr<wxDialogBase > si): 
    WrapClass<wxDialogBase>(si)
    , WrapClass_wxTopLevelWindow(si)
    {}

    /// Destructor
    ~WrapClass_wxDialogBase()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    


    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxDialogBase*);

    // Static methods
    



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(SetReturnCode,"void wxDialogBase::SetReturnCode(int returnCode)  (http://docs.wxwidgets.org/stable/wx_wxdialogbase.html#setreturncode)")
    ADD_CLASS_METHOD(GetReturnCode,"int wxDialogBase::GetReturnCode()  (http://docs.wxwidgets.org/stable/wx_wxdialogbase.html#getreturncode)")
    ADD_CLASS_METHOD(SetAffirmativeId,"void wxDialogBase::SetAffirmativeId(int affirmativeId)  (http://docs.wxwidgets.org/stable/wx_wxdialogbase.html#setaffirmativeid)")
    ADD_CLASS_METHOD(GetAffirmativeId,"int wxDialogBase::GetAffirmativeId()  (http://docs.wxwidgets.org/stable/wx_wxdialogbase.html#getaffirmativeid)")
    ADD_CLASS_METHOD(SetEscapeId,"void wxDialogBase::SetEscapeId(int escapeId)  (http://docs.wxwidgets.org/stable/wx_wxdialogbase.html#setescapeid)")
    ADD_CLASS_METHOD(GetEscapeId,"int wxDialogBase::GetEscapeId()  (http://docs.wxwidgets.org/stable/wx_wxdialogbase.html#getescapeid)")
    ADD_CLASS_METHOD(CreateTextSizer,"wxSizer * wxDialogBase::CreateTextSizer(wxString const & message)  (http://docs.wxwidgets.org/stable/wx_wxdialogbase.html#createtextsizer)")
    ADD_CLASS_METHOD(CreateButtonSizer,"wxSizer * wxDialogBase::CreateButtonSizer(long int flags)  (http://docs.wxwidgets.org/stable/wx_wxdialogbase.html#createbuttonsizer)")
    ADD_CLASS_METHOD(CreateSeparatedButtonSizer,"wxSizer * wxDialogBase::CreateSeparatedButtonSizer(long int flags)  (http://docs.wxwidgets.org/stable/wx_wxdialogbase.html#createseparatedbuttonsizer)")
    ADD_CLASS_METHOD(CreateStdDialogButtonSizer,"wxStdDialogButtonSizer * wxDialogBase::CreateStdDialogButtonSizer(long int flags)  (http://docs.wxwidgets.org/stable/wx_wxdialogbase.html#createstddialogbuttonsizer)")
    ADD_CLASS_METHOD(OnNavigationKey,"void wxDialogBase::OnNavigationKey(wxNavigationKeyEvent & event)  (http://docs.wxwidgets.org/stable/wx_wxdialogbase.html#onnavigationkey)")
    ADD_CLASS_METHOD(OnFocus,"void wxDialogBase::OnFocus(wxFocusEvent & event)  (http://docs.wxwidgets.org/stable/wx_wxdialogbase.html#onfocus)")
    ADD_CLASS_METHOD(OnChildFocus,"void wxDialogBase::OnChildFocus(wxChildFocusEvent & event)  (http://docs.wxwidgets.org/stable/wx_wxdialogbase.html#onchildfocus)")
    ADD_CLASS_METHOD(SetFocus,"void wxDialogBase::SetFocus()  (http://docs.wxwidgets.org/stable/wx_wxdialogbase.html#setfocus)")
    ADD_CLASS_METHOD(SetFocusIgnoringChildren,"void wxDialogBase::SetFocusIgnoringChildren()  (http://docs.wxwidgets.org/stable/wx_wxdialogbase.html#setfocusignoringchildren)")
    ADD_CLASS_METHOD(RemoveChild,"void wxDialogBase::RemoveChild(wxWindowBase * child)  (http://docs.wxwidgets.org/stable/wx_wxdialogbase.html#removechild)")
    ADD_CLASS_METHOD(AcceptsFocus,"bool wxDialogBase::AcceptsFocus()  (http://docs.wxwidgets.org/stable/wx_wxdialogbase.html#acceptsfocus)")





    void AddMethods(WrapClass<wxDialogBase>::ptr this_ptr );
    

};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxDialogBase_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_wxDialogBase_h
