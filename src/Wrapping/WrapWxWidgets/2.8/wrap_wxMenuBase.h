/**
 * C++ Interface: wrap_wxMenuBase
 *
 * Description: wrapping wxMenuBase
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxMenuBase_h_
#define _wrap_wxMenuBase_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "wx_includes.h"

// include what is needed for inheritence and for types ...

#include "wrap_wxEvtHandler.h"



AMI_DECLARE_TYPE(wxMenuBase);

// TODO: check for inheritence ...
class WrapClass_wxMenuBase : public WrapClass<wxMenuBase>
    , public   WrapClass_wxEvtHandler
{
  DEFINE_CLASS(WrapClass_wxMenuBase);

  protected:
    typedef WrapClass<wxMenuBase>::ptr _parentclass_ptr;
    typedef wxMenuBase ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxMenuBase>& GetObj() const { return WrapClass<wxMenuBase>::GetObj(); }

    /// Constructor
    WrapClass_wxMenuBase(boost::shared_ptr<wxMenuBase > si): 
    WrapClass<wxMenuBase>(si)
    , WrapClass_wxEvtHandler(si)
    {}

    /// Destructor
    ~WrapClass_wxMenuBase()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxMenuBase_1,"Constructor wxMenuBase::wxMenuBase(wxString const & title, long int style = 0) (http://docs.wxwidgets.org/stable/wx_wxmenubase.html#wxmenubase).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxMenuBase,"Constructor wxMenuBase::wxMenuBase() (http://docs.wxwidgets.org/stable/wx_wxmenubase.html#wxmenubase).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxMenuBase_2,"Constructor wxMenuBase::wxMenuBase(long int style = 0) (http://docs.wxwidgets.org/stable/wx_wxmenubase.html#wxmenubase).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxMenuBase*);

    // Static methods
    
    ADD_CLASS_STATICMETHOD(LockAccels,"void wxMenuBase::LockAccels(bool locked) (http://docs.wxwidgets.org/stable/wx_wxmenubase.html#lockaccels).");



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(Append_1,"wxMenuItem * wxMenuBase::Append(int itemid, wxString const & text = wxEmptyString, wxString const & help = wxEmptyString, wxItemKind kind = wxITEM_NORMAL)  (http://docs.wxwidgets.org/stable/wx_wxmenubase.html#append)")
    ADD_CLASS_METHOD(AppendSeparator,"wxMenuItem * wxMenuBase::AppendSeparator()  (http://docs.wxwidgets.org/stable/wx_wxmenubase.html#appendseparator)")
    ADD_CLASS_METHOD(AppendCheckItem,"wxMenuItem * wxMenuBase::AppendCheckItem(int itemid, wxString const & text, wxString const & help = wxEmptyString)  (http://docs.wxwidgets.org/stable/wx_wxmenubase.html#appendcheckitem)")
    ADD_CLASS_METHOD(AppendRadioItem,"wxMenuItem * wxMenuBase::AppendRadioItem(int itemid, wxString const & text, wxString const & help = wxEmptyString)  (http://docs.wxwidgets.org/stable/wx_wxmenubase.html#appendradioitem)")
    ADD_CLASS_METHOD(AppendSubMenu,"wxMenuItem * wxMenuBase::AppendSubMenu(wxMenu * submenu, wxString const & text, wxString const & help = wxEmptyString)  (http://docs.wxwidgets.org/stable/wx_wxmenubase.html#appendsubmenu)")
    ADD_CLASS_METHOD(Append,"wxMenuBase::Append()  (http://docs.wxwidgets.org/stable/wx_wxmenubase.html#append)")
    ADD_CLASS_METHOD(Append_2,"wxMenuItem * wxMenuBase::Append(wxMenuItem * item)  (http://docs.wxwidgets.org/stable/wx_wxmenubase.html#append)")
    ADD_CLASS_METHOD(Break,"void wxMenuBase::Break()  (http://docs.wxwidgets.org/stable/wx_wxmenubase.html#break)")
    ADD_CLASS_METHOD(Insert_1,"wxMenuItem * wxMenuBase::Insert(size_t pos, wxMenuItem * item)  (http://docs.wxwidgets.org/stable/wx_wxmenubase.html#insert)")
    ADD_CLASS_METHOD(Insert,"wxMenuBase::Insert()  (http://docs.wxwidgets.org/stable/wx_wxmenubase.html#insert)")
    ADD_CLASS_METHOD(Insert_2,"wxMenuItem * wxMenuBase::Insert(size_t pos, int itemid, wxString const & text = wxEmptyString, wxString const & help = wxEmptyString, wxItemKind kind = wxITEM_NORMAL)  (http://docs.wxwidgets.org/stable/wx_wxmenubase.html#insert)")
    ADD_CLASS_METHOD(InsertSeparator,"wxMenuItem * wxMenuBase::InsertSeparator(size_t pos)  (http://docs.wxwidgets.org/stable/wx_wxmenubase.html#insertseparator)")
    ADD_CLASS_METHOD(InsertCheckItem,"wxMenuItem * wxMenuBase::InsertCheckItem(size_t pos, int itemid, wxString const & text, wxString const & help = wxEmptyString)  (http://docs.wxwidgets.org/stable/wx_wxmenubase.html#insertcheckitem)")
    ADD_CLASS_METHOD(InsertRadioItem,"wxMenuItem * wxMenuBase::InsertRadioItem(size_t pos, int itemid, wxString const & text, wxString const & help = wxEmptyString)  (http://docs.wxwidgets.org/stable/wx_wxmenubase.html#insertradioitem)")
    ADD_CLASS_METHOD(Insert_3,"wxMenuItem * wxMenuBase::Insert(size_t pos, int itemid, wxString const & text, wxMenu * submenu, wxString const & help = wxEmptyString)  (http://docs.wxwidgets.org/stable/wx_wxmenubase.html#insert)")
    ADD_CLASS_METHOD(Prepend_1,"wxMenuItem * wxMenuBase::Prepend(wxMenuItem * item)  (http://docs.wxwidgets.org/stable/wx_wxmenubase.html#prepend)")
    ADD_CLASS_METHOD(Prepend,"wxMenuBase::Prepend()  (http://docs.wxwidgets.org/stable/wx_wxmenubase.html#prepend)")
    ADD_CLASS_METHOD(Prepend_2,"wxMenuItem * wxMenuBase::Prepend(int itemid, wxString const & text = wxEmptyString, wxString const & help = wxEmptyString, wxItemKind kind = wxITEM_NORMAL)  (http://docs.wxwidgets.org/stable/wx_wxmenubase.html#prepend)")
    ADD_CLASS_METHOD(PrependSeparator,"wxMenuItem * wxMenuBase::PrependSeparator()  (http://docs.wxwidgets.org/stable/wx_wxmenubase.html#prependseparator)")
    ADD_CLASS_METHOD(PrependCheckItem,"wxMenuItem * wxMenuBase::PrependCheckItem(int itemid, wxString const & text, wxString const & help = wxEmptyString)  (http://docs.wxwidgets.org/stable/wx_wxmenubase.html#prependcheckitem)")
    ADD_CLASS_METHOD(PrependRadioItem,"wxMenuItem * wxMenuBase::PrependRadioItem(int itemid, wxString const & text, wxString const & help = wxEmptyString)  (http://docs.wxwidgets.org/stable/wx_wxmenubase.html#prependradioitem)")
    ADD_CLASS_METHOD(Prepend_3,"wxMenuItem * wxMenuBase::Prepend(int itemid, wxString const & text, wxMenu * submenu, wxString const & help = wxEmptyString)  (http://docs.wxwidgets.org/stable/wx_wxmenubase.html#prepend)")
    ADD_CLASS_METHOD(Remove_1,"wxMenuItem * wxMenuBase::Remove(int itemid)  (http://docs.wxwidgets.org/stable/wx_wxmenubase.html#remove)")
    ADD_CLASS_METHOD(Remove,"wxMenuBase::Remove()  (http://docs.wxwidgets.org/stable/wx_wxmenubase.html#remove)")
    ADD_CLASS_METHOD(Remove_2,"wxMenuItem * wxMenuBase::Remove(wxMenuItem * item)  (http://docs.wxwidgets.org/stable/wx_wxmenubase.html#remove)")
    ADD_CLASS_METHOD(Delete_1,"bool wxMenuBase::Delete(int itemid)  (http://docs.wxwidgets.org/stable/wx_wxmenubase.html#delete)")
    ADD_CLASS_METHOD(Delete,"wxMenuBase::Delete()  (http://docs.wxwidgets.org/stable/wx_wxmenubase.html#delete)")
    ADD_CLASS_METHOD(Delete_2,"bool wxMenuBase::Delete(wxMenuItem * item)  (http://docs.wxwidgets.org/stable/wx_wxmenubase.html#delete)")
    ADD_CLASS_METHOD(Destroy_1,"bool wxMenuBase::Destroy(int itemid)  (http://docs.wxwidgets.org/stable/wx_wxmenubase.html#destroy)")
    ADD_CLASS_METHOD(Destroy,"wxMenuBase::Destroy()  (http://docs.wxwidgets.org/stable/wx_wxmenubase.html#destroy)")
    ADD_CLASS_METHOD(Destroy_2,"bool wxMenuBase::Destroy(wxMenuItem * item)  (http://docs.wxwidgets.org/stable/wx_wxmenubase.html#destroy)")
    ADD_CLASS_METHOD(GetMenuItemCount,"size_t wxMenuBase::GetMenuItemCount()  (http://docs.wxwidgets.org/stable/wx_wxmenubase.html#getmenuitemcount)")
    ADD_CLASS_METHOD(GetMenuItems_1,"wxMenuItemList const & wxMenuBase::GetMenuItems()  (http://docs.wxwidgets.org/stable/wx_wxmenubase.html#getmenuitems)")
    ADD_CLASS_METHOD(GetMenuItems,"wxMenuBase::GetMenuItems()  (http://docs.wxwidgets.org/stable/wx_wxmenubase.html#getmenuitems)")
    ADD_CLASS_METHOD(GetMenuItems_2,"wxMenuItemList & wxMenuBase::GetMenuItems()  (http://docs.wxwidgets.org/stable/wx_wxmenubase.html#getmenuitems)")
    ADD_CLASS_METHOD(FindItem_1,"int wxMenuBase::FindItem(wxString const & item)  (http://docs.wxwidgets.org/stable/wx_wxmenubase.html#finditem)")
    ADD_CLASS_METHOD(FindItem,"wxMenuBase::FindItem()  (http://docs.wxwidgets.org/stable/wx_wxmenubase.html#finditem)")
/* The following types are missing: wxMenu * *
    ADD_CLASS_METHOD(FindItem_2,"wxMenuItem * wxMenuBase::FindItem(int itemid, wxMenu * * menu = 0l)  (http://docs.wxwidgets.org/stable/wx_wxmenubase.html#finditem)")
*/
    ADD_CLASS_METHOD(FindItemByPosition,"wxMenuItem * wxMenuBase::FindItemByPosition(size_t position)  (http://docs.wxwidgets.org/stable/wx_wxmenubase.html#finditembyposition)")
    ADD_CLASS_METHOD(Enable,"void wxMenuBase::Enable(int itemid, bool enable)  (http://docs.wxwidgets.org/stable/wx_wxmenubase.html#enable)")
    ADD_CLASS_METHOD(IsEnabled,"bool wxMenuBase::IsEnabled(int itemid)  (http://docs.wxwidgets.org/stable/wx_wxmenubase.html#isenabled)")
    ADD_CLASS_METHOD(Check,"void wxMenuBase::Check(int itemid, bool check)  (http://docs.wxwidgets.org/stable/wx_wxmenubase.html#check)")
    ADD_CLASS_METHOD(IsChecked,"bool wxMenuBase::IsChecked(int itemid)  (http://docs.wxwidgets.org/stable/wx_wxmenubase.html#ischecked)")
    ADD_CLASS_METHOD(SetLabel,"void wxMenuBase::SetLabel(int itemid, wxString const & label)  (http://docs.wxwidgets.org/stable/wx_wxmenubase.html#setlabel)")
    ADD_CLASS_METHOD(GetLabel,"wxString wxMenuBase::GetLabel(int itemid)  (http://docs.wxwidgets.org/stable/wx_wxmenubase.html#getlabel)")
    ADD_CLASS_METHOD(SetHelpString,"void wxMenuBase::SetHelpString(int itemid, wxString const & helpString)  (http://docs.wxwidgets.org/stable/wx_wxmenubase.html#sethelpstring)")
    ADD_CLASS_METHOD(GetHelpString,"wxString wxMenuBase::GetHelpString(int itemid)  (http://docs.wxwidgets.org/stable/wx_wxmenubase.html#gethelpstring)")
    ADD_CLASS_METHOD(SetTitle,"void wxMenuBase::SetTitle(wxString const & title)  (http://docs.wxwidgets.org/stable/wx_wxmenubase.html#settitle)")
    ADD_CLASS_METHOD(GetTitle,"wxString const wxMenuBase::GetTitle()  (http://docs.wxwidgets.org/stable/wx_wxmenubase.html#gettitle)")
    ADD_CLASS_METHOD(SetEventHandler,"void wxMenuBase::SetEventHandler(wxEvtHandler * handler)  (http://docs.wxwidgets.org/stable/wx_wxmenubase.html#seteventhandler)")
    ADD_CLASS_METHOD(GetEventHandler,"wxEvtHandler * wxMenuBase::GetEventHandler()  (http://docs.wxwidgets.org/stable/wx_wxmenubase.html#geteventhandler)")
    ADD_CLASS_METHOD(SetInvokingWindow,"void wxMenuBase::SetInvokingWindow(wxWindow * win)  (http://docs.wxwidgets.org/stable/wx_wxmenubase.html#setinvokingwindow)")
    ADD_CLASS_METHOD(GetInvokingWindow,"wxWindow * wxMenuBase::GetInvokingWindow()  (http://docs.wxwidgets.org/stable/wx_wxmenubase.html#getinvokingwindow)")
    ADD_CLASS_METHOD(GetStyle,"long int wxMenuBase::GetStyle()  (http://docs.wxwidgets.org/stable/wx_wxmenubase.html#getstyle)")
    ADD_CLASS_METHOD(UpdateUI,"void wxMenuBase::UpdateUI(wxEvtHandler * source = 0u)  (http://docs.wxwidgets.org/stable/wx_wxmenubase.html#updateui)")
    ADD_CLASS_METHOD(GetMenuBar,"wxMenuBar * wxMenuBase::GetMenuBar()  (http://docs.wxwidgets.org/stable/wx_wxmenubase.html#getmenubar)")
    ADD_CLASS_METHOD(Attach,"void wxMenuBase::Attach(wxMenuBarBase * menubar)  (http://docs.wxwidgets.org/stable/wx_wxmenubase.html#attach)")
    ADD_CLASS_METHOD(Detach,"void wxMenuBase::Detach()  (http://docs.wxwidgets.org/stable/wx_wxmenubase.html#detach)")
    ADD_CLASS_METHOD(IsAttached,"bool wxMenuBase::IsAttached()  (http://docs.wxwidgets.org/stable/wx_wxmenubase.html#isattached)")
    ADD_CLASS_METHOD(SetParent,"void wxMenuBase::SetParent(wxMenu * parent)  (http://docs.wxwidgets.org/stable/wx_wxmenubase.html#setparent)")
    ADD_CLASS_METHOD(GetParent,"wxMenu * wxMenuBase::GetParent()  (http://docs.wxwidgets.org/stable/wx_wxmenubase.html#getparent)")
    ADD_CLASS_METHOD(FindChildItem,"wxMenuItem * wxMenuBase::FindChildItem(int itemid, size_t * pos = 0l)  (http://docs.wxwidgets.org/stable/wx_wxmenubase.html#findchilditem)")
    ADD_CLASS_METHOD(SendEvent,"bool wxMenuBase::SendEvent(int itemid, int checked = -0x00000000000000001)  (http://docs.wxwidgets.org/stable/wx_wxmenubase.html#sendevent)")
    ADD_CLASS_METHOD(Append_3,"void wxMenuBase::Append(int itemid, wxString const & text, wxString const & help, bool isCheckable)  (http://docs.wxwidgets.org/stable/wx_wxmenubase.html#append)")
    ADD_CLASS_METHOD(Append_4,"wxMenuItem * wxMenuBase::Append(int itemid, wxString const & text, wxMenu * submenu, wxString const & help = wxEmptyString)  (http://docs.wxwidgets.org/stable/wx_wxmenubase.html#append)")
    ADD_CLASS_METHOD(Insert_4,"void wxMenuBase::Insert(size_t pos, int itemid, wxString const & text, wxString const & help, bool isCheckable)  (http://docs.wxwidgets.org/stable/wx_wxmenubase.html#insert)")
    ADD_CLASS_METHOD(Prepend_4,"void wxMenuBase::Prepend(int itemid, wxString const & text, wxString const & help, bool isCheckable)  (http://docs.wxwidgets.org/stable/wx_wxmenubase.html#prepend)")
    ADD_CLASS_METHOD(GetLabelText,"wxString wxMenuBase::GetLabelText(int itemid)  (http://docs.wxwidgets.org/stable/wx_wxmenubase.html#getlabeltext)")





    void AddMethods(WrapClass<wxMenuBase>::ptr this_ptr );
    
    /*
     * Adds the constructor and the static methods to the given context
     */
    static void AddStaticMethods( Variables::ptr& context);

};


#endif // _wrap_wxMenuBase_h
