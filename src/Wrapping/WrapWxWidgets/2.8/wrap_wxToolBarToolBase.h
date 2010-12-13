/**
 * C++ Interface: wrap_wxToolBarToolBase
 *
 * Description: wrapping wxToolBarToolBase
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxToolBarToolBase_h_
#define _wrap_wxToolBarToolBase_h_

/*
#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"
*/

#include "wx_includes.h"

// include what is needed for inheritence and for types ...

#include "wrap_wxObject.h"


#ifndef wxToolBarToolBase_declared
  #define wxToolBarToolBase_declared
  AMI_DECLARE_TYPE(wxToolBarToolBase);
#endif

// TODO: check for inheritence ...
class WrapClass_wxToolBarToolBase : public WrapClass<wxToolBarToolBase>
    , public   WrapClass_wxObject
{
  DEFINE_CLASS(WrapClass_wxToolBarToolBase);

  protected:
    typedef WrapClass<wxToolBarToolBase>::ptr _parentclass_ptr;
    typedef wxToolBarToolBase ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxToolBarToolBase>& GetObj() const { return WrapClass<wxToolBarToolBase>::GetObj(); }

    /// Constructor
    WrapClass_wxToolBarToolBase(boost::shared_ptr<wxToolBarToolBase > si): 
    WrapClass<wxToolBarToolBase>(si)
    , WrapClass_wxObject(si)
    {}

    /// Destructor
    ~WrapClass_wxToolBarToolBase()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxToolBarToolBase_1,"Constructor wxToolBarToolBase::wxToolBarToolBase(wxToolBarBase * tbar = 0u, int toolid = wxID_SEPARATOR, wxString const & label = wxEmptyString, wxBitmap const & bmpNormal = wxNullBitmap, wxBitmap const & bmpDisabled = wxNullBitmap, wxItemKind kind = wxITEM_NORMAL, wxObject * clientData = 0u, wxString const & shortHelpString = wxEmptyString, wxString const & longHelpString = wxEmptyString) (http://docs.wxwidgets.org/stable/wx_wxtoolbartoolbase.html#wxtoolbartoolbase).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxToolBarToolBase,"Constructor wxToolBarToolBase::wxToolBarToolBase() (http://docs.wxwidgets.org/stable/wx_wxtoolbartoolbase.html#wxtoolbartoolbase).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxToolBarToolBase_2,"Constructor wxToolBarToolBase::wxToolBarToolBase(wxToolBarBase * tbar, wxControl * control) (http://docs.wxwidgets.org/stable/wx_wxtoolbartoolbase.html#wxtoolbartoolbase).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxToolBarToolBase*);

    // Static methods
    



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(GetId,"int wxToolBarToolBase::GetId()  (http://docs.wxwidgets.org/stable/wx_wxtoolbartoolbase.html#getid)")
    ADD_CLASS_METHOD(GetControl,"wxControl * wxToolBarToolBase::GetControl()  (http://docs.wxwidgets.org/stable/wx_wxtoolbartoolbase.html#getcontrol)")
    ADD_CLASS_METHOD(GetToolBar,"wxToolBarBase * wxToolBarToolBase::GetToolBar()  (http://docs.wxwidgets.org/stable/wx_wxtoolbartoolbase.html#gettoolbar)")
    ADD_CLASS_METHOD(IsButton,"bool wxToolBarToolBase::IsButton()  (http://docs.wxwidgets.org/stable/wx_wxtoolbartoolbase.html#isbutton)")
    ADD_CLASS_METHOD(IsControl,"bool wxToolBarToolBase::IsControl()  (http://docs.wxwidgets.org/stable/wx_wxtoolbartoolbase.html#iscontrol)")
    ADD_CLASS_METHOD(IsSeparator,"bool wxToolBarToolBase::IsSeparator()  (http://docs.wxwidgets.org/stable/wx_wxtoolbartoolbase.html#isseparator)")
    ADD_CLASS_METHOD(GetStyle,"int wxToolBarToolBase::GetStyle()  (http://docs.wxwidgets.org/stable/wx_wxtoolbartoolbase.html#getstyle)")
    ADD_CLASS_METHOD(GetKind,"wxItemKind wxToolBarToolBase::GetKind()  (http://docs.wxwidgets.org/stable/wx_wxtoolbartoolbase.html#getkind)")
    ADD_CLASS_METHOD(IsEnabled,"bool wxToolBarToolBase::IsEnabled()  (http://docs.wxwidgets.org/stable/wx_wxtoolbartoolbase.html#isenabled)")
    ADD_CLASS_METHOD(IsToggled,"bool wxToolBarToolBase::IsToggled()  (http://docs.wxwidgets.org/stable/wx_wxtoolbartoolbase.html#istoggled)")
    ADD_CLASS_METHOD(CanBeToggled,"bool wxToolBarToolBase::CanBeToggled()  (http://docs.wxwidgets.org/stable/wx_wxtoolbartoolbase.html#canbetoggled)")
    ADD_CLASS_METHOD(GetNormalBitmap,"wxBitmap const & wxToolBarToolBase::GetNormalBitmap()  (http://docs.wxwidgets.org/stable/wx_wxtoolbartoolbase.html#getnormalbitmap)")
    ADD_CLASS_METHOD(GetDisabledBitmap,"wxBitmap const & wxToolBarToolBase::GetDisabledBitmap()  (http://docs.wxwidgets.org/stable/wx_wxtoolbartoolbase.html#getdisabledbitmap)")
    ADD_CLASS_METHOD(GetBitmap,"wxBitmap const & wxToolBarToolBase::GetBitmap()  (http://docs.wxwidgets.org/stable/wx_wxtoolbartoolbase.html#getbitmap)")
    ADD_CLASS_METHOD(GetLabel,"wxString const & wxToolBarToolBase::GetLabel()  (http://docs.wxwidgets.org/stable/wx_wxtoolbartoolbase.html#getlabel)")
    ADD_CLASS_METHOD(GetShortHelp,"wxString const & wxToolBarToolBase::GetShortHelp()  (http://docs.wxwidgets.org/stable/wx_wxtoolbartoolbase.html#getshorthelp)")
    ADD_CLASS_METHOD(GetLongHelp,"wxString const & wxToolBarToolBase::GetLongHelp()  (http://docs.wxwidgets.org/stable/wx_wxtoolbartoolbase.html#getlonghelp)")
    ADD_CLASS_METHOD(GetClientData,"wxObject * wxToolBarToolBase::GetClientData()  (http://docs.wxwidgets.org/stable/wx_wxtoolbartoolbase.html#getclientdata)")
    ADD_CLASS_METHOD(Enable,"bool wxToolBarToolBase::Enable(bool enable)  (http://docs.wxwidgets.org/stable/wx_wxtoolbartoolbase.html#enable)")
    ADD_CLASS_METHOD(Toggle_1,"bool wxToolBarToolBase::Toggle(bool toggle)  (http://docs.wxwidgets.org/stable/wx_wxtoolbartoolbase.html#toggle)")
    ADD_CLASS_METHOD(SetToggle,"bool wxToolBarToolBase::SetToggle(bool toggle)  (http://docs.wxwidgets.org/stable/wx_wxtoolbartoolbase.html#settoggle)")
    ADD_CLASS_METHOD(SetShortHelp,"bool wxToolBarToolBase::SetShortHelp(wxString const & help)  (http://docs.wxwidgets.org/stable/wx_wxtoolbartoolbase.html#setshorthelp)")
    ADD_CLASS_METHOD(SetLongHelp,"bool wxToolBarToolBase::SetLongHelp(wxString const & help)  (http://docs.wxwidgets.org/stable/wx_wxtoolbartoolbase.html#setlonghelp)")
    ADD_CLASS_METHOD(Toggle,"wxToolBarToolBase::Toggle()  (http://docs.wxwidgets.org/stable/wx_wxtoolbartoolbase.html#toggle)")
    ADD_CLASS_METHOD(Toggle_2,"void wxToolBarToolBase::Toggle()  (http://docs.wxwidgets.org/stable/wx_wxtoolbartoolbase.html#toggle)")
    ADD_CLASS_METHOD(SetNormalBitmap,"void wxToolBarToolBase::SetNormalBitmap(wxBitmap const & bmp)  (http://docs.wxwidgets.org/stable/wx_wxtoolbartoolbase.html#setnormalbitmap)")
    ADD_CLASS_METHOD(SetDisabledBitmap,"void wxToolBarToolBase::SetDisabledBitmap(wxBitmap const & bmp)  (http://docs.wxwidgets.org/stable/wx_wxtoolbartoolbase.html#setdisabledbitmap)")
    ADD_CLASS_METHOD(SetLabel,"void wxToolBarToolBase::SetLabel(wxString const & label)  (http://docs.wxwidgets.org/stable/wx_wxtoolbartoolbase.html#setlabel)")
    ADD_CLASS_METHOD(SetClientData,"void wxToolBarToolBase::SetClientData(wxObject * clientData)  (http://docs.wxwidgets.org/stable/wx_wxtoolbartoolbase.html#setclientdata)")
    ADD_CLASS_METHOD(Detach,"void wxToolBarToolBase::Detach()  (http://docs.wxwidgets.org/stable/wx_wxtoolbartoolbase.html#detach)")
    ADD_CLASS_METHOD(Attach,"void wxToolBarToolBase::Attach(wxToolBarBase * tbar)  (http://docs.wxwidgets.org/stable/wx_wxtoolbartoolbase.html#attach)")
    ADD_CLASS_METHOD(GetClassInfo,"wxClassInfo * wxToolBarToolBase::GetClassInfo()  (http://docs.wxwidgets.org/stable/wx_wxtoolbartoolbase.html#getclassinfo)")





    void AddMethods(WrapClass<wxToolBarToolBase>::ptr this_ptr );
    

};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxToolBarToolBase_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_wxToolBarToolBase_h
