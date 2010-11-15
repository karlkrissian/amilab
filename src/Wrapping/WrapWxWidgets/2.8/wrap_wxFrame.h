/**
 * C++ Interface: wrap_wxFrame
 *
 * Description: wrapping wxFrame
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxFrame_h_
#define _wrap_wxFrame_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "wx/wx.h"

// include what is needed for inheritence and for types ...

#include "wrap_wxFrameBase.h"


AMI_DECLARE_TYPE(wxFrame);

// TODO: check for inheritence ...
class WrapClass_wxFrame : public WrapClass<wxFrame>
    , public   WrapClass_wxFrameBase
{
  DEFINE_CLASS(WrapClass_wxFrame);

  protected:
    typedef WrapClass<wxFrame>::ptr _parentclass_ptr;
    typedef wxFrame ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxFrame>& GetObj() const { return WrapClass<wxFrame>::GetObj(); }

    /// Constructor
    WrapClass_wxFrame(boost::shared_ptr<wxFrame > si): 
    WrapClass<wxFrame>(si)
    , WrapClass_wxFrameBase(si)
    {}

    /// Destructor
    ~WrapClass_wxFrame()
    {
      std::cout << "~WrapClass_wxFrame()" << std::endl;
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxFrame_1,"Constructor wxFrame::wxFrame() (http://docs.wxwidgets.org/stable/wx_wxframe.html#wxframe).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxFrame,"Constructor wxFrame::wxFrame() (http://docs.wxwidgets.org/stable/wx_wxframe.html#wxframe).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxFrame_2,"Constructor wxFrame::wxFrame(wxWindow * parent, wxWindowID id, wxString const & title, wxPoint const & pos = wxDefaultPosition, wxSize const & size = wxDefaultSize, long int style = 541072960, wxString const & name = wxFrameNameStr) (http://docs.wxwidgets.org/stable/wx_wxframe.html#wxframe).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxFrame*);

    // here add each method
    
    // Adding standard methods
    ADD_CLASS_METHOD(Create,"bool wxFrame::Create(wxWindow * parent, wxWindowID id, wxString const & title, wxPoint const & pos = wxDefaultPosition, wxSize const & size = wxDefaultSize, long int style = 541072960, wxString const & name = wxFrameNameStr)  (http://docs.wxwidgets.org/stable/wx_wxframe.html#create)")
/* The following types are missing: wxStatusBar
    ADD_CLASS_METHOD(CreateStatusBar,"wxStatusBar * wxFrame::CreateStatusBar(int number = 1, long int style = 65552, wxWindowID id = 0, wxString const & name = wxStatusLineNameStr)  (http://docs.wxwidgets.org/stable/wx_wxframe.html#createstatusbar)")
*/
/* The following types are missing: wxStatusBar
    ADD_CLASS_METHOD(SetStatusBar,"void wxFrame::SetStatusBar(wxStatusBar * statbar)  (http://docs.wxwidgets.org/stable/wx_wxframe.html#setstatusbar)")
*/
/* The following types are missing: wxToolBar
    ADD_CLASS_METHOD(CreateToolBar,"wxToolBar * wxFrame::CreateToolBar(long int style = -0x00000000000000001, wxWindowID id = -0x00000000000000001, wxString const & name = wxToolBarNameStr)  (http://docs.wxwidgets.org/stable/wx_wxframe.html#createtoolbar)")
*/
/* The following types are missing: wxToolBar
    ADD_CLASS_METHOD(SetToolBar,"void wxFrame::SetToolBar(wxToolBar * toolbar)  (http://docs.wxwidgets.org/stable/wx_wxframe.html#settoolbar)")
*/
    ADD_CLASS_METHOD(GetClientAreaOrigin,"wxPoint wxFrame::GetClientAreaOrigin()  (http://docs.wxwidgets.org/stable/wx_wxframe.html#getclientareaorigin)")
    ADD_CLASS_METHOD(GtkOnSize,"void wxFrame::GtkOnSize()  (http://docs.wxwidgets.org/stable/wx_wxframe.html#gtkonsize)")
    ADD_CLASS_METHOD(OnInternalIdle,"void wxFrame::OnInternalIdle()  (http://docs.wxwidgets.org/stable/wx_wxframe.html#oninternalidle)")
    ADD_CLASS_METHOD(UpdateMenuBarSize,"void wxFrame::UpdateMenuBarSize()  (http://docs.wxwidgets.org/stable/wx_wxframe.html#updatemenubarsize)")
    ADD_CLASS_METHOD(GetClassInfo,"wxClassInfo * wxFrame::GetClassInfo()  (http://docs.wxwidgets.org/stable/wx_wxframe.html#getclassinfo)")





    void AddMethods(WrapClass<wxFrame>::ptr this_ptr )
    {
      
      // Add members from wxFrameBase
      WrapClass_wxFrameBase::ptr parent_wxFrameBase(        boost::dynamic_pointer_cast<WrapClass_wxFrameBase >(this_ptr));
      parent_wxFrameBase->AddMethods(parent_wxFrameBase);


      // check that the method name is not a token
      
      // Adding standard methods 
      AddVar_Create( this_ptr);
/* The following types are missing: wxStatusBar
      AddVar_CreateStatusBar( this_ptr);
*/
/* The following types are missing: wxStatusBar
      AddVar_SetStatusBar( this_ptr);
*/
/* The following types are missing: wxToolBar
      AddVar_CreateToolBar( this_ptr);
*/
/* The following types are missing: wxToolBar
      AddVar_SetToolBar( this_ptr);
*/
      AddVar_GetClientAreaOrigin( this_ptr);
      AddVar_GtkOnSize( this_ptr);
      AddVar_OnInternalIdle( this_ptr);
      AddVar_UpdateMenuBarSize( this_ptr);
      AddVar_GetClassInfo( this_ptr);



      // Add public fields
      AMIObject::ptr tmpobj(amiobject.lock());
      if (!tmpobj.get()) return;
      Variables::ptr context(tmpobj->GetContext());
      
      /* type not available
      // Adding public member m_menuBarDetached
      boost::shared_ptr<bool > var_m_menuBarDetached_ptr(&GetObj()->m_menuBarDetached, smartpointer_nodeleter<bool >());
      BasicVariable::ptr var_m_menuBarDetached = AMILabType<bool >::CreateVarFromSmtPtr(var_m_menuBarDetached_ptr);
      if (var_m_menuBarDetached.get()) {
        var_m_menuBarDetached->Rename("m_menuBarDetached");
        context->AddVar(var_m_menuBarDetached,context);
      }
      */
      
      // Adding public member m_menuBarHeight
      boost::shared_ptr<int > var_m_menuBarHeight_ptr(&GetObj()->m_menuBarHeight, smartpointer_nodeleter<int >());
      BasicVariable::ptr var_m_menuBarHeight = AMILabType<int >::CreateVarFromSmtPtr(var_m_menuBarHeight_ptr);
      if (var_m_menuBarHeight.get()) {
        var_m_menuBarHeight->Rename("m_menuBarHeight");
        context->AddVar(var_m_menuBarHeight,context);
      }
      
      /* type not available
      // Adding public member m_toolBarDetached
      boost::shared_ptr<bool > var_m_toolBarDetached_ptr(&GetObj()->m_toolBarDetached, smartpointer_nodeleter<bool >());
      BasicVariable::ptr var_m_toolBarDetached = AMILabType<bool >::CreateVarFromSmtPtr(var_m_toolBarDetached_ptr);
      if (var_m_toolBarDetached.get()) {
        var_m_toolBarDetached->Rename("m_toolBarDetached");
        context->AddVar(var_m_toolBarDetached,context);
      }
      */

    };
};


#endif // _wrap_wxFrame_h
