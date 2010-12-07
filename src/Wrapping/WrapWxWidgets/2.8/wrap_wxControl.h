/**
 * C++ Interface: wrap_wxControl
 *
 * Description: wrapping wxControl
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxControl_h_
#define _wrap_wxControl_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "wx_includes.h"

// include what is needed for inheritence and for types ...

#include "wrap_wxControlBase.h"



AMI_DECLARE_TYPE(wxControl);

// TODO: check for inheritence ...
class WrapClass_wxControl : public WrapClass<wxControl>
    , public   WrapClass_wxControlBase
{
  DEFINE_CLASS(WrapClass_wxControl);

  protected:
    typedef WrapClass<wxControl>::ptr _parentclass_ptr;
    typedef wxControl ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxControl>& GetObj() const { return WrapClass<wxControl>::GetObj(); }

    /// Constructor
    WrapClass_wxControl(boost::shared_ptr<wxControl > si): 
    WrapClass<wxControl>(si)
    , WrapClass_wxControlBase(si)
    {}

    /// Destructor
    ~WrapClass_wxControl()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxControl_1,"Constructor wxControl::wxControl() (http://docs.wxwidgets.org/stable/wx_wxcontrol.html#wxcontrol).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxControl,"Constructor wxControl::wxControl() (http://docs.wxwidgets.org/stable/wx_wxcontrol.html#wxcontrol).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxControl_2,"Constructor wxControl::wxControl(wxWindow * parent, wxWindowID id, wxPoint const & pos = wxDefaultPosition, wxSize const & size = wxDefaultSize, long int style = 0, wxValidator const & validator = wxDefaultValidator, wxString const & name = wxControlNameStr) (http://docs.wxwidgets.org/stable/wx_wxcontrol.html#wxcontrol).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxControl*);

    // Static methods
    



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(Create,"bool wxControl::Create(wxWindow * parent, wxWindowID id, wxPoint const & pos = wxDefaultPosition, wxSize const & size = wxDefaultSize, long int style = 0, wxValidator const & validator = wxDefaultValidator, wxString const & name = wxControlNameStr)  (http://docs.wxwidgets.org/stable/wx_wxcontrol.html#create)")
    ADD_CLASS_METHOD(SetLabel,"void wxControl::SetLabel(wxString const & label)  (http://docs.wxwidgets.org/stable/wx_wxcontrol.html#setlabel)")
    ADD_CLASS_METHOD(GetLabel,"wxString wxControl::GetLabel()  (http://docs.wxwidgets.org/stable/wx_wxcontrol.html#getlabel)")
    ADD_CLASS_METHOD(GetDefaultAttributes,"wxVisualAttributes wxControl::GetDefaultAttributes()  (http://docs.wxwidgets.org/stable/wx_wxcontrol.html#getdefaultattributes)")
    ADD_CLASS_METHOD(OnInternalIdle,"void wxControl::OnInternalIdle()  (http://docs.wxwidgets.org/stable/wx_wxcontrol.html#oninternalidle)")
    ADD_CLASS_METHOD(GetClassInfo,"wxClassInfo * wxControl::GetClassInfo()  (http://docs.wxwidgets.org/stable/wx_wxcontrol.html#getclassinfo)")





    void AddMethods(WrapClass<wxControl>::ptr this_ptr );
    
    /*
     * Adds the constructor and the static methods to the given context
     */
    static void AddStaticMethods( Variables::ptr& context);

};


#endif // _wrap_wxControl_h
