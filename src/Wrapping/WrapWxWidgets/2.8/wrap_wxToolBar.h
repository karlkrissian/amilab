/**
 * C++ Interface: wrap_wxToolBar
 *
 * Description: wrapping wxToolBar
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxToolBar_h_
#define _wrap_wxToolBar_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "wx/wx.h"

// include what is needed for inheritence and for types ...

#include "wrap_wxToolBarBase.h"


AMI_DECLARE_TYPE(wxToolBar);

// TODO: check for inheritence ...
class WrapClass_wxToolBar : public WrapClass<wxToolBar>
    , public   WrapClass_wxToolBarBase
{
  DEFINE_CLASS(WrapClass_wxToolBar);

  protected:
    typedef WrapClass<wxToolBar>::ptr _parentclass_ptr;
    typedef wxToolBar ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxToolBar>& GetObj() const { return WrapClass<wxToolBar>::GetObj(); }

    /// Constructor
    WrapClass_wxToolBar(boost::shared_ptr<wxToolBar > si): 
    WrapClass<wxToolBar>(si)
    , WrapClass_wxToolBarBase(si)
    {}

    /// Destructor
    ~WrapClass_wxToolBar()
    {
      std::cout << "~WrapClass_wxToolBar()" << std::endl;
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxToolBar_1,"Constructor wxToolBar::wxToolBar() (http://docs.wxwidgets.org/stable/wx_wxtoolbar.html#wxtoolbar).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxToolBar,"Constructor wxToolBar::wxToolBar() (http://docs.wxwidgets.org/stable/wx_wxtoolbar.html#wxtoolbar).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxToolBar_2,"Constructor wxToolBar::wxToolBar(wxWindow * parent, wxWindowID id, wxPoint const & pos = wxDefaultPosition, wxSize const & size = wxDefaultSize, long int style = wxTB_HORIZONTAL, wxString const & name = wxToolBarNameStr) (http://docs.wxwidgets.org/stable/wx_wxtoolbar.html#wxtoolbar).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxToolBar*);

    // here add each method
    
    // Adding standard methods
    ADD_CLASS_METHOD(Create,"bool wxToolBar::Create(wxWindow * parent, wxWindowID id, wxPoint const & pos = wxDefaultPosition, wxSize const & size = wxDefaultSize, long int style = 0, wxString const & name = wxToolBarNameStr)  (http://docs.wxwidgets.org/stable/wx_wxtoolbar.html#create)")
    ADD_CLASS_METHOD(SetMargins,"void wxToolBar::SetMargins(int x, int y)  (http://docs.wxwidgets.org/stable/wx_wxtoolbar.html#setmargins)")
    ADD_CLASS_METHOD(SetToolSeparation,"void wxToolBar::SetToolSeparation(int separation)  (http://docs.wxwidgets.org/stable/wx_wxtoolbar.html#settoolseparation)")
    ADD_CLASS_METHOD(FindToolForPosition,"wxToolBarToolBase * wxToolBar::FindToolForPosition(wxCoord x, wxCoord y)  (http://docs.wxwidgets.org/stable/wx_wxtoolbar.html#findtoolforposition)")
    ADD_CLASS_METHOD(SetToolShortHelp,"void wxToolBar::SetToolShortHelp(int id, wxString const & helpString)  (http://docs.wxwidgets.org/stable/wx_wxtoolbar.html#settoolshorthelp)")
    ADD_CLASS_METHOD(SetWindowStyleFlag,"void wxToolBar::SetWindowStyleFlag(long int style)  (http://docs.wxwidgets.org/stable/wx_wxtoolbar.html#setwindowstyleflag)")
    ADD_CLASS_METHOD(SetToolNormalBitmap,"void wxToolBar::SetToolNormalBitmap(int id, wxBitmap const & bitmap)  (http://docs.wxwidgets.org/stable/wx_wxtoolbar.html#settoolnormalbitmap)")
    ADD_CLASS_METHOD(SetToolDisabledBitmap,"void wxToolBar::SetToolDisabledBitmap(int id, wxBitmap const & bitmap)  (http://docs.wxwidgets.org/stable/wx_wxtoolbar.html#settooldisabledbitmap)")
    ADD_CLASS_METHOD(GetClassDefaultAttributes,"wxVisualAttributes wxToolBar::GetClassDefaultAttributes(wxWindowVariant variant = wxWINDOW_VARIANT_NORMAL)  (http://docs.wxwidgets.org/stable/wx_wxtoolbar.html#getclassdefaultattributes)")
    ADD_CLASS_METHOD(OnInternalIdle,"void wxToolBar::OnInternalIdle()  (http://docs.wxwidgets.org/stable/wx_wxtoolbar.html#oninternalidle)")
    ADD_CLASS_METHOD(GetClassInfo,"wxClassInfo * wxToolBar::GetClassInfo()  (http://docs.wxwidgets.org/stable/wx_wxtoolbar.html#getclassinfo)")





    void AddMethods(WrapClass<wxToolBar>::ptr this_ptr )
    {
      
      // Add members from wxToolBarBase
      WrapClass_wxToolBarBase::ptr parent_wxToolBarBase(        boost::dynamic_pointer_cast<WrapClass_wxToolBarBase >(this_ptr));
      parent_wxToolBarBase->AddMethods(parent_wxToolBarBase);


      // check that the method name is not a token
      
      // Adding standard methods 
      AddVar_Create( this_ptr);
      AddVar_SetMargins( this_ptr);
      AddVar_SetToolSeparation( this_ptr);
      AddVar_FindToolForPosition( this_ptr);
      AddVar_SetToolShortHelp( this_ptr);
      AddVar_SetWindowStyleFlag( this_ptr);
      AddVar_SetToolNormalBitmap( this_ptr);
      AddVar_SetToolDisabledBitmap( this_ptr);
      AddVar_GetClassDefaultAttributes( this_ptr);
      AddVar_OnInternalIdle( this_ptr);
      AddVar_GetClassInfo( this_ptr);



      // Add public fields
      AMIObject::ptr tmpobj(amiobject.lock());
      if (!tmpobj.get()) return;
      Variables::ptr context(tmpobj->GetContext());
      
      /* type not available
      // Adding public member m_toolbar
      boost::shared_ptr<_GtkToolbar > var_m_toolbar_ptr(&GetObj()->m_toolbar, smartpointer_nodeleter<_GtkToolbar >());
      BasicVariable::ptr var_m_toolbar = AMILabType<_GtkToolbar >::CreateVarFromSmtPtr(var_m_toolbar_ptr);
      if (var_m_toolbar.get()) {
        var_m_toolbar->Rename("m_toolbar");
        context->AddVar(var_m_toolbar,context);
      }
      */
      
      /* type not available
      // Adding public member m_blockEvent
      boost::shared_ptr<bool > var_m_blockEvent_ptr(&GetObj()->m_blockEvent, smartpointer_nodeleter<bool >());
      BasicVariable::ptr var_m_blockEvent = AMILabType<bool >::CreateVarFromSmtPtr(var_m_blockEvent_ptr);
      if (var_m_blockEvent.get()) {
        var_m_blockEvent->Rename("m_blockEvent");
        context->AddVar(var_m_blockEvent,context);
      }
      */

    };
};


#endif // _wrap_wxToolBar_h
