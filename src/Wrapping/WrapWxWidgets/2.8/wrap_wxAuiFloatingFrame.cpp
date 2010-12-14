/**
 * C++ Interface: wrap_wxAuiFloatingFrame
 *
 * Description: wrapping wxAuiFloatingFrame
 * File generated automatically using CableSwig xml output and a python script
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

/*
//#include "VarContexts.hpp"
#include "wrapfunctions.hpp"
#include "ami_class.h"
#include "ami_object.h"
#include "ami_function.h"
*/

#include "wrap_wxAuiFloatingFrame.h"

// get all the required includes
// #include "..."
#ifndef wxWindow_declared
  #define wxWindow_declared
  AMI_DECLARE_TYPE(wxWindow)
#endif
#ifndef wxAuiManager_declared
  #define wxAuiManager_declared
  AMI_DECLARE_TYPE(wxAuiManager)
#endif
#ifndef wxAuiPaneInfo_declared
  #define wxAuiPaneInfo_declared
  AMI_DECLARE_TYPE(wxAuiPaneInfo)
#endif
#ifndef wxClassInfo_declared
  #define wxClassInfo_declared
  AMI_DECLARE_TYPE(wxClassInfo)
#endif



// needed to allow NULL pointer parameter
extern Variable<int>::ptr nullvar;
extern bool CheckNullVar(ParamList* _p, int _n);

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxAuiFloatingFrame>::CreateVar( ParamList* p)
{
  WrapClass_wxAuiFloatingFrame::wrap_wxAuiFloatingFrame construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(wxAuiFloatingFrame);
AMI_DEFINE_VARFROMSMTPTR(wxAuiFloatingFrame);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<wxAuiFloatingFrame>::CreateVar( wxAuiFloatingFrame* val, bool nodeleter)
{ 
  boost::shared_ptr<wxAuiFloatingFrame> obj_ptr(val,smartpointer_nodeleter<wxAuiFloatingFrame>());
  return AMILabType<wxAuiFloatingFrame>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxAuiFloatingFrame
//
Variable<AMIObject>::ptr WrapClass_wxAuiFloatingFrame::CreateVar( wxAuiFloatingFrame* sp)
{
  boost::shared_ptr<wxAuiFloatingFrame> di_ptr(
    sp,
    wxwindow_nodeleter<wxAuiFloatingFrame>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxAuiFloatingFrame>::CreateVar(
      new WrapClass_wxAuiFloatingFrame(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxAuiFloatingFrame::AddMethods(WrapClass<wxAuiFloatingFrame>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding standard methods 
  AddVar_SetPaneWindow( this_ptr);
  AddVar_GetOwnerManager( this_ptr);
  AddVar_GetClassInfo( this_ptr);



  // Add public fields and Enumerations
  AMIObject::ptr tmpobj(amiobject.lock());
  if (!tmpobj.get()) return;
  Variables::ptr context(tmpobj->GetContext());


  


  // Adding Bases

  // Add base parent wxMiniFrame
  boost::shared_ptr<wxMiniFrame > parent_wxMiniFrame(  boost::dynamic_pointer_cast<wxMiniFrame >(this_ptr->GetObj()));
  BasicVariable::ptr var_wxMiniFrame = AMILabType<wxMiniFrame >::CreateVarFromSmtPtr(parent_wxMiniFrame);
  context->AddVar("wxMiniFrame",var_wxMiniFrame);
  // Set as a default context
  Variable<AMIObject>::ptr obj_wxMiniFrame = boost::dynamic_pointer_cast<Variable<AMIObject> >(var_wxMiniFrame);
  context->AddDefault(obj_wxMiniFrame->Pointer()->GetContext());

};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxAuiFloatingFrame_AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxAuiFloatingFrame");
    WrapClass_wxAuiFloatingFrame::AddVar_wxAuiFloatingFrame(amiobject->GetContext());


  // Static methods 

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxAuiFloatingFrame::wxAuiFloatingFrame(wxWindow * parent, wxAuiManager * owner_mgr, wxAuiPaneInfo const & pane, wxWindowID id = wxID_ANY, long int style = 541067338)
//---------------------------------------------------
void WrapClass_wxAuiFloatingFrame::
    wrap_wxAuiFloatingFrame::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'parent'")
  ADDPARAMCOMMENT_TYPE( wxAuiManager, "parameter named 'owner_mgr'")
  ADDPARAMCOMMENT_TYPE( wxAuiPaneInfo, "parameter named 'pane'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'id' (def:wxID_ANY)")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'style' (def:541067338)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiFloatingFrame::
    wrap_wxAuiFloatingFrame::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>5) ClassHelpAndReturn;
  int _n=0;

  wxWindow* parent;
  if (CheckNullVar(_p,_n))  {
    parent=(wxWindow*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxWindow > parent_smtptr;
    if (!get_val_smtptr_param<wxWindow >(parent_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    parent = parent_smtptr.get();
  }

  wxAuiManager* owner_mgr;
  if (CheckNullVar(_p,_n))  {
    owner_mgr=(wxAuiManager*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxAuiManager > owner_mgr_smtptr;
    if (!get_val_smtptr_param<wxAuiManager >(owner_mgr_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    owner_mgr = owner_mgr_smtptr.get();
  }

  boost::shared_ptr<wxAuiPaneInfo > pane_smtptr;
  if (!get_val_smtptr_param<wxAuiPaneInfo >(pane_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxAuiPaneInfo const & pane = *pane_smtptr;

  int id = wxID_ANY;
  if (!get_val_param<int >(id,_p,_n,false,false)) ClassHelpAndReturn;

  long style_long = 541067338;;
  if (!get_val_param<long >(style_long,_p,_n,false,false)) ClassHelpAndReturn;
  long int style = style_long;

  wxAuiFloatingFrame* _newobj = new wxAuiFloatingFrame(parent, owner_mgr, pane, id, style);
  BasicVariable::ptr res = WrapClass_wxAuiFloatingFrame::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of void wxAuiFloatingFrame::SetPaneWindow(wxAuiPaneInfo const & pane)
//---------------------------------------------------
void WrapClass_wxAuiFloatingFrame::
    wrap_SetPaneWindow::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxAuiPaneInfo, "parameter named 'pane'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiFloatingFrame::
    wrap_SetPaneWindow::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxAuiPaneInfo > pane_smtptr;
  if (!get_val_smtptr_param<wxAuiPaneInfo >(pane_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxAuiPaneInfo const & pane = *pane_smtptr;

  this->_objectptr->GetObj()->SetPaneWindow(pane);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxAuiManager * wxAuiFloatingFrame::GetOwnerManager()
//---------------------------------------------------
void WrapClass_wxAuiFloatingFrame::
    wrap_GetOwnerManager::SetParametersComments()
{
  return_comments="returning a variable of type wxAuiManager";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiFloatingFrame::
    wrap_GetOwnerManager::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxAuiManager * res =   this->_objectptr->GetObj()->GetOwnerManager();
  BasicVariable::ptr res_var = AMILabType<wxAuiManager >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxClassInfo * wxAuiFloatingFrame::GetClassInfo()
//---------------------------------------------------
void WrapClass_wxAuiFloatingFrame::
    wrap_GetClassInfo::SetParametersComments()
{
  return_comments="returning a variable of type wxClassInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiFloatingFrame::
    wrap_GetClassInfo::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxClassInfo * res =   this->_objectptr->GetObj()->GetClassInfo();
  BasicVariable::ptr res_var = AMILabType<wxClassInfo >::CreateVar(res,true);
  return res_var;
}

