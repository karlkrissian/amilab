/**
 * C++ Interface: wrap_wxMenuItemBase
 *
 * Description: wrapping wxMenuItemBase
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxMenuItemBase_h_
#define _wrap_wxMenuItemBase_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "wx_includes.h"

// include what is needed for inheritence and for types ...

#include "wrap_wxObject.h"



AMI_DECLARE_TYPE(wxMenuItemBase);

// TODO: check for inheritence ...
class WrapClass_wxMenuItemBase : public WrapClass<wxMenuItemBase>
    , public   WrapClass_wxObject
{
  DEFINE_CLASS(WrapClass_wxMenuItemBase);

  protected:
    typedef WrapClass<wxMenuItemBase>::ptr _parentclass_ptr;
    typedef wxMenuItemBase ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxMenuItemBase>& GetObj() const { return WrapClass<wxMenuItemBase>::GetObj(); }

    /// Constructor
    WrapClass_wxMenuItemBase(boost::shared_ptr<wxMenuItemBase > si): 
    WrapClass<wxMenuItemBase>(si)
    , WrapClass_wxObject(si)
    {}

    /// Destructor
    ~WrapClass_wxMenuItemBase()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxMenuItemBase*);

    // Static methods
    
    ADD_CLASS_STATICMETHOD(New_1,"wxMenuItem * wxMenuItemBase::New(wxMenu * parentMenu = 0u, int itemid = wxID_SEPARATOR, wxString const & text = wxEmptyString, wxString const & help = wxEmptyString, wxItemKind kind = wxITEM_NORMAL, wxMenu * subMenu = 0u) (http://docs.wxwidgets.org/stable/wx_wxmenuitembase.html#new).");
    ADD_CLASS_STATICMETHOD(GetLabelFromText,"wxString wxMenuItemBase::GetLabelFromText(wxString const & text) (http://docs.wxwidgets.org/stable/wx_wxmenuitembase.html#getlabelfromtext).");
    ADD_CLASS_STATICMETHOD(New,"wxMenuItemBase::New() (http://docs.wxwidgets.org/stable/wx_wxmenuitembase.html#new).");
    ADD_CLASS_STATICMETHOD(New_2,"wxMenuItem * wxMenuItemBase::New(wxMenu * parentMenu, int itemid, wxString const & text, wxString const & help, bool isCheckable, wxMenu * subMenu = 0u) (http://docs.wxwidgets.org/stable/wx_wxmenuitembase.html#new).");
    ADD_CLASS_STATICMETHOD(GetLabelText,"wxString wxMenuItemBase::GetLabelText(wxString const & label) (http://docs.wxwidgets.org/stable/wx_wxmenuitembase.html#getlabeltext).");



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(GetMenu,"wxMenu * wxMenuItemBase::GetMenu()  (http://docs.wxwidgets.org/stable/wx_wxmenuitembase.html#getmenu)")
    ADD_CLASS_METHOD(SetMenu,"void wxMenuItemBase::SetMenu(wxMenu * menu)  (http://docs.wxwidgets.org/stable/wx_wxmenuitembase.html#setmenu)")
    ADD_CLASS_METHOD(SetId,"void wxMenuItemBase::SetId(int itemid)  (http://docs.wxwidgets.org/stable/wx_wxmenuitembase.html#setid)")
    ADD_CLASS_METHOD(GetId,"int wxMenuItemBase::GetId()  (http://docs.wxwidgets.org/stable/wx_wxmenuitembase.html#getid)")
    ADD_CLASS_METHOD(IsSeparator,"bool wxMenuItemBase::IsSeparator()  (http://docs.wxwidgets.org/stable/wx_wxmenuitembase.html#isseparator)")
    ADD_CLASS_METHOD(SetText,"void wxMenuItemBase::SetText(wxString const & str)  (http://docs.wxwidgets.org/stable/wx_wxmenuitembase.html#settext)")
    ADD_CLASS_METHOD(GetLabel,"wxString wxMenuItemBase::GetLabel()  (http://docs.wxwidgets.org/stable/wx_wxmenuitembase.html#getlabel)")
    ADD_CLASS_METHOD(GetText,"wxString const & wxMenuItemBase::GetText()  (http://docs.wxwidgets.org/stable/wx_wxmenuitembase.html#gettext)")
    ADD_CLASS_METHOD(GetKind,"wxItemKind wxMenuItemBase::GetKind()  (http://docs.wxwidgets.org/stable/wx_wxmenuitembase.html#getkind)")
    ADD_CLASS_METHOD(SetKind,"void wxMenuItemBase::SetKind(wxItemKind kind)  (http://docs.wxwidgets.org/stable/wx_wxmenuitembase.html#setkind)")
    ADD_CLASS_METHOD(SetCheckable,"void wxMenuItemBase::SetCheckable(bool checkable)  (http://docs.wxwidgets.org/stable/wx_wxmenuitembase.html#setcheckable)")
    ADD_CLASS_METHOD(IsCheckable,"bool wxMenuItemBase::IsCheckable()  (http://docs.wxwidgets.org/stable/wx_wxmenuitembase.html#ischeckable)")
    ADD_CLASS_METHOD(IsSubMenu,"bool wxMenuItemBase::IsSubMenu()  (http://docs.wxwidgets.org/stable/wx_wxmenuitembase.html#issubmenu)")
    ADD_CLASS_METHOD(SetSubMenu,"void wxMenuItemBase::SetSubMenu(wxMenu * menu)  (http://docs.wxwidgets.org/stable/wx_wxmenuitembase.html#setsubmenu)")
    ADD_CLASS_METHOD(GetSubMenu,"wxMenu * wxMenuItemBase::GetSubMenu()  (http://docs.wxwidgets.org/stable/wx_wxmenuitembase.html#getsubmenu)")
    ADD_CLASS_METHOD(Enable,"void wxMenuItemBase::Enable(bool enable = true)  (http://docs.wxwidgets.org/stable/wx_wxmenuitembase.html#enable)")
    ADD_CLASS_METHOD(IsEnabled,"bool wxMenuItemBase::IsEnabled()  (http://docs.wxwidgets.org/stable/wx_wxmenuitembase.html#isenabled)")
    ADD_CLASS_METHOD(Check,"void wxMenuItemBase::Check(bool check = true)  (http://docs.wxwidgets.org/stable/wx_wxmenuitembase.html#check)")
    ADD_CLASS_METHOD(IsChecked,"bool wxMenuItemBase::IsChecked()  (http://docs.wxwidgets.org/stable/wx_wxmenuitembase.html#ischecked)")
    ADD_CLASS_METHOD(Toggle,"void wxMenuItemBase::Toggle()  (http://docs.wxwidgets.org/stable/wx_wxmenuitembase.html#toggle)")
    ADD_CLASS_METHOD(SetHelp,"void wxMenuItemBase::SetHelp(wxString const & str)  (http://docs.wxwidgets.org/stable/wx_wxmenuitembase.html#sethelp)")
    ADD_CLASS_METHOD(GetHelp,"wxString const & wxMenuItemBase::GetHelp()  (http://docs.wxwidgets.org/stable/wx_wxmenuitembase.html#gethelp)")
    ADD_CLASS_METHOD(GetAccel,"wxAcceleratorEntry * wxMenuItemBase::GetAccel()  (http://docs.wxwidgets.org/stable/wx_wxmenuitembase.html#getaccel)")
    ADD_CLASS_METHOD(SetAccel,"void wxMenuItemBase::SetAccel(wxAcceleratorEntry * accel)  (http://docs.wxwidgets.org/stable/wx_wxmenuitembase.html#setaccel)")
    ADD_CLASS_METHOD(SetName,"void wxMenuItemBase::SetName(wxString const & str)  (http://docs.wxwidgets.org/stable/wx_wxmenuitembase.html#setname)")
    ADD_CLASS_METHOD(GetName,"wxString const & wxMenuItemBase::GetName()  (http://docs.wxwidgets.org/stable/wx_wxmenuitembase.html#getname)")
    ADD_CLASS_METHOD(SetItemLabel,"void wxMenuItemBase::SetItemLabel(wxString const & str)  (http://docs.wxwidgets.org/stable/wx_wxmenuitembase.html#setitemlabel)")
    ADD_CLASS_METHOD(GetItemLabelText,"wxString wxMenuItemBase::GetItemLabelText()  (http://docs.wxwidgets.org/stable/wx_wxmenuitembase.html#getitemlabeltext)")





    void AddMethods(WrapClass<wxMenuItemBase>::ptr this_ptr );
    
    /*
     * Adds the constructor and the static methods to the given context
     */
    static void AddStaticMethods( Variables::ptr& context);

};


#endif // _wrap_wxMenuItemBase_h
