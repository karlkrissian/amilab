/**
 * C++ Interface: wrap_wxControlBase
 *
 * Description: wrapping wxControlBase
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxControlBase_h_
#define _wrap_wxControlBase_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "wx_includes.h"

// include what is needed for inheritence and for types ...

#include "wrap_wxWindow.h"



AMI_DECLARE_TYPE(wxControlBase);

// TODO: check for inheritence ...
class WrapClass_wxControlBase : public WrapClass<wxControlBase>
    , public   WrapClass_wxWindow
{
  DEFINE_CLASS(WrapClass_wxControlBase);

  protected:
    typedef WrapClass<wxControlBase>::ptr _parentclass_ptr;
    typedef wxControlBase ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxControlBase>& GetObj() const { return WrapClass<wxControlBase>::GetObj(); }

    /// Constructor
    WrapClass_wxControlBase(boost::shared_ptr<wxControlBase > si): 
    WrapClass<wxControlBase>(si)
    , WrapClass_wxWindow(si)
    {}

    /// Destructor
    ~WrapClass_wxControlBase()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxControlBase,"Constructor wxControlBase::wxControlBase() (http://docs.wxwidgets.org/stable/wx_wxcontrolbase.html#wxcontrolbase).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxControlBase*);

    // Static methods
    



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(Create,"bool wxControlBase::Create(wxWindow * parent, wxWindowID id, wxPoint const & pos = wxDefaultPosition, wxSize const & size = wxDefaultSize, long int style = 0, wxValidator const & validator = wxDefaultValidator, wxString const & name = wxControlNameStr)  (http://docs.wxwidgets.org/stable/wx_wxcontrolbase.html#create)")
    ADD_CLASS_METHOD(GetAlignment,"int wxControlBase::GetAlignment()  (http://docs.wxwidgets.org/stable/wx_wxcontrolbase.html#getalignment)")
    ADD_CLASS_METHOD(ShouldInheritColours,"bool wxControlBase::ShouldInheritColours()  (http://docs.wxwidgets.org/stable/wx_wxcontrolbase.html#shouldinheritcolours)")
    ADD_CLASS_METHOD(Command,"void wxControlBase::Command(wxCommandEvent & event)  (http://docs.wxwidgets.org/stable/wx_wxcontrolbase.html#command)")
    ADD_CLASS_METHOD(SetLabel,"void wxControlBase::SetLabel(wxString const & label)  (http://docs.wxwidgets.org/stable/wx_wxcontrolbase.html#setlabel)")
    ADD_CLASS_METHOD(SetFont,"bool wxControlBase::SetFont(wxFont const & font)  (http://docs.wxwidgets.org/stable/wx_wxcontrolbase.html#setfont)")
    ADD_CLASS_METHOD(DoUpdateWindowUI,"void wxControlBase::DoUpdateWindowUI(wxUpdateUIEvent & event)  (http://docs.wxwidgets.org/stable/wx_wxcontrolbase.html#doupdatewindowui)")





    void AddMethods(WrapClass<wxControlBase>::ptr this_ptr );
    
    /*
     * Adds the constructor and the static methods to the given context
     */
    static void AddStaticMethods( Variables::ptr& context);

};


#endif // _wrap_wxControlBase_h
