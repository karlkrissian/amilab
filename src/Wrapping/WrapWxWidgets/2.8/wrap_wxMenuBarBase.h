/**
 * C++ Interface: wrap_wxMenuBarBase
 *
 * Description: wrapping wxMenuBarBase
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxMenuBarBase_h_
#define _wrap_wxMenuBarBase_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "wx_includes.h"

// include what is needed for inheritence and for types ...

#include "wrap_wxWindow.h"



AMI_DECLARE_TYPE(wxMenuBarBase);

// TODO: check for inheritence ...
class WrapClass_wxMenuBarBase : public WrapClass<wxMenuBarBase>
    , public   WrapClass_wxWindow
{
  DEFINE_CLASS(WrapClass_wxMenuBarBase);

  protected:
    typedef WrapClass<wxMenuBarBase>::ptr _parentclass_ptr;
    typedef wxMenuBarBase ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxMenuBarBase>& GetObj() const { return WrapClass<wxMenuBarBase>::GetObj(); }

    /// Constructor
    WrapClass_wxMenuBarBase(boost::shared_ptr<wxMenuBarBase > si): 
    WrapClass<wxMenuBarBase>(si)
    , WrapClass_wxWindow(si)
    {}

    /// Destructor
    ~WrapClass_wxMenuBarBase()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    


    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxMenuBarBase*);

    // Static methods
    



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(Append,"bool wxMenuBarBase::Append(wxMenu * menu, wxString const & title)  (http://docs.wxwidgets.org/stable/wx_wxmenubarbase.html#append)")
    ADD_CLASS_METHOD(Insert,"bool wxMenuBarBase::Insert(size_t pos, wxMenu * menu, wxString const & title)  (http://docs.wxwidgets.org/stable/wx_wxmenubarbase.html#insert)")
    ADD_CLASS_METHOD(GetMenuCount,"size_t wxMenuBarBase::GetMenuCount()  (http://docs.wxwidgets.org/stable/wx_wxmenubarbase.html#getmenucount)")
    ADD_CLASS_METHOD(GetMenu,"wxMenu * wxMenuBarBase::GetMenu(size_t pos)  (http://docs.wxwidgets.org/stable/wx_wxmenubarbase.html#getmenu)")
    ADD_CLASS_METHOD(Replace,"wxMenu * wxMenuBarBase::Replace(size_t pos, wxMenu * menu, wxString const & title)  (http://docs.wxwidgets.org/stable/wx_wxmenubarbase.html#replace)")
    ADD_CLASS_METHOD(Remove,"wxMenu * wxMenuBarBase::Remove(size_t pos)  (http://docs.wxwidgets.org/stable/wx_wxmenubarbase.html#remove)")
    ADD_CLASS_METHOD(IsEnabledTop,"bool wxMenuBarBase::IsEnabledTop(size_t param0)  (http://docs.wxwidgets.org/stable/wx_wxmenubarbase.html#isenabledtop)")
    ADD_CLASS_METHOD(FindMenuItem,"int wxMenuBarBase::FindMenuItem(wxString const & menu, wxString const & item)  (http://docs.wxwidgets.org/stable/wx_wxmenubarbase.html#findmenuitem)")
/* The following types are missing: wxMenu * *
    ADD_CLASS_METHOD(FindItem,"wxMenuItem * wxMenuBarBase::FindItem(int itemid, wxMenu * * menu = 0l)  (http://docs.wxwidgets.org/stable/wx_wxmenubarbase.html#finditem)")
*/
    ADD_CLASS_METHOD(FindMenu,"int wxMenuBarBase::FindMenu(wxString const & title)  (http://docs.wxwidgets.org/stable/wx_wxmenubarbase.html#findmenu)")
    ADD_CLASS_METHOD(Enable_1,"void wxMenuBarBase::Enable(int itemid, bool enable)  (http://docs.wxwidgets.org/stable/wx_wxmenubarbase.html#enable)")
    ADD_CLASS_METHOD(Check,"void wxMenuBarBase::Check(int itemid, bool check)  (http://docs.wxwidgets.org/stable/wx_wxmenubarbase.html#check)")
    ADD_CLASS_METHOD(IsChecked,"bool wxMenuBarBase::IsChecked(int itemid)  (http://docs.wxwidgets.org/stable/wx_wxmenubarbase.html#ischecked)")
    ADD_CLASS_METHOD(IsEnabled_1,"bool wxMenuBarBase::IsEnabled(int itemid)  (http://docs.wxwidgets.org/stable/wx_wxmenubarbase.html#isenabled)")
    ADD_CLASS_METHOD(IsEnabled,"wxMenuBarBase::IsEnabled()  (http://docs.wxwidgets.org/stable/wx_wxmenubarbase.html#isenabled)")
    ADD_CLASS_METHOD(IsEnabled_2,"bool wxMenuBarBase::IsEnabled()  (http://docs.wxwidgets.org/stable/wx_wxmenubarbase.html#isenabled)")
    ADD_CLASS_METHOD(SetLabel_1,"void wxMenuBarBase::SetLabel(int itemid, wxString const & label)  (http://docs.wxwidgets.org/stable/wx_wxmenubarbase.html#setlabel)")
    ADD_CLASS_METHOD(GetLabel_1,"wxString wxMenuBarBase::GetLabel(int itemid)  (http://docs.wxwidgets.org/stable/wx_wxmenubarbase.html#getlabel)")
    ADD_CLASS_METHOD(SetHelpString,"void wxMenuBarBase::SetHelpString(int itemid, wxString const & helpString)  (http://docs.wxwidgets.org/stable/wx_wxmenubarbase.html#sethelpstring)")
    ADD_CLASS_METHOD(GetHelpString,"wxString wxMenuBarBase::GetHelpString(int itemid)  (http://docs.wxwidgets.org/stable/wx_wxmenubarbase.html#gethelpstring)")
    ADD_CLASS_METHOD(GetFrame,"wxFrame * wxMenuBarBase::GetFrame()  (http://docs.wxwidgets.org/stable/wx_wxmenubarbase.html#getframe)")
    ADD_CLASS_METHOD(IsAttached,"bool wxMenuBarBase::IsAttached()  (http://docs.wxwidgets.org/stable/wx_wxmenubarbase.html#isattached)")
    ADD_CLASS_METHOD(Attach,"void wxMenuBarBase::Attach(wxFrame * frame)  (http://docs.wxwidgets.org/stable/wx_wxmenubarbase.html#attach)")
    ADD_CLASS_METHOD(Detach,"void wxMenuBarBase::Detach()  (http://docs.wxwidgets.org/stable/wx_wxmenubarbase.html#detach)")
    ADD_CLASS_METHOD(Enable,"wxMenuBarBase::Enable()  (http://docs.wxwidgets.org/stable/wx_wxmenubarbase.html#enable)")
    ADD_CLASS_METHOD(Enable_2,"bool wxMenuBarBase::Enable(bool enable = true)  (http://docs.wxwidgets.org/stable/wx_wxmenubarbase.html#enable)")
    ADD_CLASS_METHOD(SetLabel,"wxMenuBarBase::SetLabel()  (http://docs.wxwidgets.org/stable/wx_wxmenubarbase.html#setlabel)")
    ADD_CLASS_METHOD(SetLabel_2,"void wxMenuBarBase::SetLabel(wxString const & s)  (http://docs.wxwidgets.org/stable/wx_wxmenubarbase.html#setlabel)")
    ADD_CLASS_METHOD(GetLabel,"wxMenuBarBase::GetLabel()  (http://docs.wxwidgets.org/stable/wx_wxmenubarbase.html#getlabel)")
    ADD_CLASS_METHOD(GetLabel_2,"wxString wxMenuBarBase::GetLabel()  (http://docs.wxwidgets.org/stable/wx_wxmenubarbase.html#getlabel)")
    ADD_CLASS_METHOD(AcceptsFocusFromKeyboard,"bool wxMenuBarBase::AcceptsFocusFromKeyboard()  (http://docs.wxwidgets.org/stable/wx_wxmenubarbase.html#acceptsfocusfromkeyboard)")
    ADD_CLASS_METHOD(UpdateMenus,"void wxMenuBarBase::UpdateMenus()  (http://docs.wxwidgets.org/stable/wx_wxmenubarbase.html#updatemenus)")
    ADD_CLASS_METHOD(SetMenuLabel,"void wxMenuBarBase::SetMenuLabel(size_t pos, wxString const & label)  (http://docs.wxwidgets.org/stable/wx_wxmenubarbase.html#setmenulabel)")
    ADD_CLASS_METHOD(GetMenuLabelText,"wxString wxMenuBarBase::GetMenuLabelText(size_t pos)  (http://docs.wxwidgets.org/stable/wx_wxmenubarbase.html#getmenulabeltext)")





    void AddMethods(WrapClass<wxMenuBarBase>::ptr this_ptr );
    
    /*
     * Adds the constructor and the static methods to the given context
     */
    static void AddStaticMethods( Variables::ptr& context);

};


#endif // _wrap_wxMenuBarBase_h
