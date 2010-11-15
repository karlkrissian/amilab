/**
 * C++ Interface: wrap_wxTopLevelWindowGTK
 *
 * Description: wrapping wxTopLevelWindowGTK
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxTopLevelWindowGTK_h_
#define _wrap_wxTopLevelWindowGTK_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "wx/wx.h"

// include what is needed for inheritence and for types ...

#include "wrap_wxTopLevelWindowBase.h"


AMI_DECLARE_TYPE(wxTopLevelWindowGTK);

// TODO: check for inheritence ...
class WrapClass_wxTopLevelWindowGTK : public WrapClass<wxTopLevelWindowGTK>
    , public   WrapClass_wxTopLevelWindowBase
{
  DEFINE_CLASS(WrapClass_wxTopLevelWindowGTK);

  protected:
    typedef WrapClass<wxTopLevelWindowGTK>::ptr _parentclass_ptr;
    typedef wxTopLevelWindowGTK ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxTopLevelWindowGTK>& GetObj() const { return WrapClass<wxTopLevelWindowGTK>::GetObj(); }

    /// Constructor
    WrapClass_wxTopLevelWindowGTK(boost::shared_ptr<wxTopLevelWindowGTK > si): 
    WrapClass<wxTopLevelWindowGTK>(si)
    , WrapClass_wxTopLevelWindowBase(si)
    {}

    /// Destructor
    ~WrapClass_wxTopLevelWindowGTK()
    {
      std::cout << "~WrapClass_wxTopLevelWindowGTK()" << std::endl;
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxTopLevelWindowGTK_1,"Wrapping of wxTopLevelWindowGTK, http://docs.wxwidgets.org/stable/wx_wxtoplevelwindowgtk.html#wxtoplevelwindowgtk.");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxTopLevelWindowGTK,"Wrapping of wxTopLevelWindowGTK, http://docs.wxwidgets.org/stable/wx_wxtoplevelwindowgtk.html#wxtoplevelwindowgtk.");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxTopLevelWindowGTK_2,"Wrapping of wxTopLevelWindowGTK, http://docs.wxwidgets.org/stable/wx_wxtoplevelwindowgtk.html#wxtoplevelwindowgtk.");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxTopLevelWindowGTK*);

    // here add each method
    
    // Adding standard methods
    ADD_CLASS_METHOD(Create,"http://docs.wxwidgets.org/stable/wx_wxtoplevelwindowgtk.html#create")
    ADD_CLASS_METHOD(Maximize,"http://docs.wxwidgets.org/stable/wx_wxtoplevelwindowgtk.html#maximize")
    ADD_CLASS_METHOD(IsMaximized,"http://docs.wxwidgets.org/stable/wx_wxtoplevelwindowgtk.html#ismaximized")
    ADD_CLASS_METHOD(Iconize,"http://docs.wxwidgets.org/stable/wx_wxtoplevelwindowgtk.html#iconize")
    ADD_CLASS_METHOD(IsIconized,"http://docs.wxwidgets.org/stable/wx_wxtoplevelwindowgtk.html#isiconized")
/* The following types are missing: wxIcon
    ADD_CLASS_METHOD(SetIcon,"http://docs.wxwidgets.org/stable/wx_wxtoplevelwindowgtk.html#seticon")
*/
/* The following types are missing: wxIconBundle
    ADD_CLASS_METHOD(SetIcons,"http://docs.wxwidgets.org/stable/wx_wxtoplevelwindowgtk.html#seticons")
*/
    ADD_CLASS_METHOD(Restore,"http://docs.wxwidgets.org/stable/wx_wxtoplevelwindowgtk.html#restore")
    ADD_CLASS_METHOD(EnableCloseButton,"http://docs.wxwidgets.org/stable/wx_wxtoplevelwindowgtk.html#enableclosebutton")
    ADD_CLASS_METHOD(ShowFullScreen,"http://docs.wxwidgets.org/stable/wx_wxtoplevelwindowgtk.html#showfullscreen")
    ADD_CLASS_METHOD(IsFullScreen,"http://docs.wxwidgets.org/stable/wx_wxtoplevelwindowgtk.html#isfullscreen")
/* The following types are missing: wxRegion
    ADD_CLASS_METHOD(SetShape,"http://docs.wxwidgets.org/stable/wx_wxtoplevelwindowgtk.html#setshape")
*/
    ADD_CLASS_METHOD(RequestUserAttention,"http://docs.wxwidgets.org/stable/wx_wxtoplevelwindowgtk.html#requestuserattention")
    ADD_CLASS_METHOD(SetWindowStyleFlag,"http://docs.wxwidgets.org/stable/wx_wxtoplevelwindowgtk.html#setwindowstyleflag")
    ADD_CLASS_METHOD(Show,"http://docs.wxwidgets.org/stable/wx_wxtoplevelwindowgtk.html#show")
    ADD_CLASS_METHOD(Raise,"http://docs.wxwidgets.org/stable/wx_wxtoplevelwindowgtk.html#raise")
    ADD_CLASS_METHOD(IsActive,"http://docs.wxwidgets.org/stable/wx_wxtoplevelwindowgtk.html#isactive")
    ADD_CLASS_METHOD(SetTitle,"http://docs.wxwidgets.org/stable/wx_wxtoplevelwindowgtk.html#settitle")
    ADD_CLASS_METHOD(GetTitle,"http://docs.wxwidgets.org/stable/wx_wxtoplevelwindowgtk.html#gettitle")
    ADD_CLASS_METHOD(SetTransparent,"http://docs.wxwidgets.org/stable/wx_wxtoplevelwindowgtk.html#settransparent")
    ADD_CLASS_METHOD(CanSetTransparent,"http://docs.wxwidgets.org/stable/wx_wxtoplevelwindowgtk.html#cansettransparent")
    ADD_CLASS_METHOD(AddGrab,"http://docs.wxwidgets.org/stable/wx_wxtoplevelwindowgtk.html#addgrab")
    ADD_CLASS_METHOD(RemoveGrab,"http://docs.wxwidgets.org/stable/wx_wxtoplevelwindowgtk.html#removegrab")
    ADD_CLASS_METHOD(IsGrabbed,"http://docs.wxwidgets.org/stable/wx_wxtoplevelwindowgtk.html#isgrabbed")
    ADD_CLASS_METHOD(GtkOnSize,"http://docs.wxwidgets.org/stable/wx_wxtoplevelwindowgtk.html#gtkonsize")
    ADD_CLASS_METHOD(OnInternalIdle,"http://docs.wxwidgets.org/stable/wx_wxtoplevelwindowgtk.html#oninternalidle")
    ADD_CLASS_METHOD(SetIconizeState,"http://docs.wxwidgets.org/stable/wx_wxtoplevelwindowgtk.html#seticonizestate")
    ADD_CLASS_METHOD(DoSetSizeHints,"http://docs.wxwidgets.org/stable/wx_wxtoplevelwindowgtk.html#dosetsizehints")





    void AddMethods(WrapClass<wxTopLevelWindowGTK>::ptr this_ptr )
    {
      
      // Add members from wxTopLevelWindowBase
      WrapClass_wxTopLevelWindowBase::ptr parent_wxTopLevelWindowBase(        boost::dynamic_pointer_cast<WrapClass_wxTopLevelWindowBase >(this_ptr));
      parent_wxTopLevelWindowBase->AddMethods(parent_wxTopLevelWindowBase);


      // check that the method name is not a token
      
      // Adding standard methods 
      AddVar_Create( this_ptr);
      AddVar_Maximize( this_ptr);
      AddVar_IsMaximized( this_ptr);
      AddVar_Iconize( this_ptr);
      AddVar_IsIconized( this_ptr);
/* The following types are missing: wxIcon
      AddVar_SetIcon( this_ptr);
*/
/* The following types are missing: wxIconBundle
      AddVar_SetIcons( this_ptr);
*/
      AddVar_Restore( this_ptr);
      AddVar_EnableCloseButton( this_ptr);
      AddVar_ShowFullScreen( this_ptr);
      AddVar_IsFullScreen( this_ptr);
/* The following types are missing: wxRegion
      AddVar_SetShape( this_ptr);
*/
      AddVar_RequestUserAttention( this_ptr);
      AddVar_SetWindowStyleFlag( this_ptr);
      AddVar_Show( this_ptr);
      AddVar_Raise( this_ptr);
      AddVar_IsActive( this_ptr);
      AddVar_SetTitle( this_ptr);
      AddVar_GetTitle( this_ptr);
      AddVar_SetTransparent( this_ptr);
      AddVar_CanSetTransparent( this_ptr);
      AddVar_AddGrab( this_ptr);
      AddVar_RemoveGrab( this_ptr);
      AddVar_IsGrabbed( this_ptr);
      AddVar_GtkOnSize( this_ptr);
      AddVar_OnInternalIdle( this_ptr);
      AddVar_SetIconizeState( this_ptr);
      AddVar_DoSetSizeHints( this_ptr);



      // Add public fields
      AMIObject::ptr tmpobj(amiobject.lock());
      if (!tmpobj.get()) return;
      Variables::ptr context(tmpobj->GetContext());
      
      // Adding public member m_miniEdge
      boost::shared_ptr<int > var_m_miniEdge_ptr(&GetObj()->m_miniEdge, smartpointer_nodeleter<int >());
      BasicVariable::ptr var_m_miniEdge = AMILabType<int >::CreateVarFromSmtPtr(var_m_miniEdge_ptr);
      if (var_m_miniEdge.get()) {
        var_m_miniEdge->Rename("m_miniEdge");
        context->AddVar(var_m_miniEdge,context);
      }
      
      // Adding public member m_miniTitle
      boost::shared_ptr<int > var_m_miniTitle_ptr(&GetObj()->m_miniTitle, smartpointer_nodeleter<int >());
      BasicVariable::ptr var_m_miniTitle = AMILabType<int >::CreateVarFromSmtPtr(var_m_miniTitle_ptr);
      if (var_m_miniTitle.get()) {
        var_m_miniTitle->Rename("m_miniTitle");
        context->AddVar(var_m_miniTitle,context);
      }
      
      /* type not available
      // Adding public member m_mainWidget
      boost::shared_ptr<_GtkWidget > var_m_mainWidget_ptr(&GetObj()->m_mainWidget, smartpointer_nodeleter<_GtkWidget >());
      BasicVariable::ptr var_m_mainWidget = AMILabType<_GtkWidget >::CreateVarFromSmtPtr(var_m_mainWidget_ptr);
      if (var_m_mainWidget.get()) {
        var_m_mainWidget->Rename("m_mainWidget");
        context->AddVar(var_m_mainWidget,context);
      }
      */
      
      /* type not available
      // Adding public member m_insertInClientArea
      boost::shared_ptr<bool > var_m_insertInClientArea_ptr(&GetObj()->m_insertInClientArea, smartpointer_nodeleter<bool >());
      BasicVariable::ptr var_m_insertInClientArea = AMILabType<bool >::CreateVarFromSmtPtr(var_m_insertInClientArea_ptr);
      if (var_m_insertInClientArea.get()) {
        var_m_insertInClientArea->Rename("m_insertInClientArea");
        context->AddVar(var_m_insertInClientArea,context);
      }
      */
      
      /* type not available
      // Adding public member m_fsIsShowing
      boost::shared_ptr<bool > var_m_fsIsShowing_ptr(&GetObj()->m_fsIsShowing, smartpointer_nodeleter<bool >());
      BasicVariable::ptr var_m_fsIsShowing = AMILabType<bool >::CreateVarFromSmtPtr(var_m_fsIsShowing_ptr);
      if (var_m_fsIsShowing.get()) {
        var_m_fsIsShowing->Rename("m_fsIsShowing");
        context->AddVar(var_m_fsIsShowing,context);
      }
      */
      
      // Adding public member m_fsSaveGdkFunc
      boost::shared_ptr<long int > var_m_fsSaveGdkFunc_ptr(&GetObj()->m_fsSaveGdkFunc, smartpointer_nodeleter<long int >());
      BasicVariable::ptr var_m_fsSaveGdkFunc = AMILabType<long int >::CreateVarFromSmtPtr(var_m_fsSaveGdkFunc_ptr);
      if (var_m_fsSaveGdkFunc.get()) {
        var_m_fsSaveGdkFunc->Rename("m_fsSaveGdkFunc");
        context->AddVar(var_m_fsSaveGdkFunc,context);
      }
      
      // Adding public member m_fsSaveGdkDecor
      boost::shared_ptr<long int > var_m_fsSaveGdkDecor_ptr(&GetObj()->m_fsSaveGdkDecor, smartpointer_nodeleter<long int >());
      BasicVariable::ptr var_m_fsSaveGdkDecor = AMILabType<long int >::CreateVarFromSmtPtr(var_m_fsSaveGdkDecor_ptr);
      if (var_m_fsSaveGdkDecor.get()) {
        var_m_fsSaveGdkDecor->Rename("m_fsSaveGdkDecor");
        context->AddVar(var_m_fsSaveGdkDecor,context);
      }
      
      // Adding public member m_fsSaveFlag
      boost::shared_ptr<long int > var_m_fsSaveFlag_ptr(&GetObj()->m_fsSaveFlag, smartpointer_nodeleter<long int >());
      BasicVariable::ptr var_m_fsSaveFlag = AMILabType<long int >::CreateVarFromSmtPtr(var_m_fsSaveFlag_ptr);
      if (var_m_fsSaveFlag.get()) {
        var_m_fsSaveFlag->Rename("m_fsSaveFlag");
        context->AddVar(var_m_fsSaveFlag,context);
      }
      
      // Adding public member m_fsSaveFrame
      boost::shared_ptr<wxRect > var_m_fsSaveFrame_ptr(&GetObj()->m_fsSaveFrame, smartpointer_nodeleter<wxRect >());
      BasicVariable::ptr var_m_fsSaveFrame = AMILabType<wxRect >::CreateVarFromSmtPtr(var_m_fsSaveFrame_ptr);
      if (var_m_fsSaveFrame.get()) {
        var_m_fsSaveFrame->Rename("m_fsSaveFrame");
        context->AddVar(var_m_fsSaveFrame,context);
      }
      
      // Adding public member m_gdkFunc
      boost::shared_ptr<long int > var_m_gdkFunc_ptr(&GetObj()->m_gdkFunc, smartpointer_nodeleter<long int >());
      BasicVariable::ptr var_m_gdkFunc = AMILabType<long int >::CreateVarFromSmtPtr(var_m_gdkFunc_ptr);
      if (var_m_gdkFunc.get()) {
        var_m_gdkFunc->Rename("m_gdkFunc");
        context->AddVar(var_m_gdkFunc,context);
      }
      
      // Adding public member m_gdkDecor
      boost::shared_ptr<long int > var_m_gdkDecor_ptr(&GetObj()->m_gdkDecor, smartpointer_nodeleter<long int >());
      BasicVariable::ptr var_m_gdkDecor = AMILabType<long int >::CreateVarFromSmtPtr(var_m_gdkDecor_ptr);
      if (var_m_gdkDecor.get()) {
        var_m_gdkDecor->Rename("m_gdkDecor");
        context->AddVar(var_m_gdkDecor,context);
      }
      
      // Adding public member m_urgency_hint
      boost::shared_ptr<int > var_m_urgency_hint_ptr(&GetObj()->m_urgency_hint, smartpointer_nodeleter<int >());
      BasicVariable::ptr var_m_urgency_hint = AMILabType<int >::CreateVarFromSmtPtr(var_m_urgency_hint_ptr);
      if (var_m_urgency_hint.get()) {
        var_m_urgency_hint->Rename("m_urgency_hint");
        context->AddVar(var_m_urgency_hint,context);
      }

    };
};


#endif // _wrap_wxTopLevelWindowGTK_h
