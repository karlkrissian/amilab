/**
 * C++ Interface: wrap_wxMiniFrame
 *
 * Description: wrapping wxMiniFrame
 * File generated automatically using CableSwig xml output and a python script
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

//#include "VarContexts.hpp"
#include "wrapfunctions.hpp"
#include "ami_class.h"
#include "ami_object.h"
#include "ami_function.h"

// get all the required includes
// #include "..."
#include "wrap_wxBitmap.h"
#include "wrap_wxWindow.h"
#include "wrap_wxString.h"
#include "wrap_wxPoint.h"
#include "wrap_wxSize.h"
#include "wrap_wxClassInfo.h"


#include "wrap_wxMiniFrame.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxMiniFrame>::CreateVar( ParamList* p)
{
  WrapClass_wxMiniFrame::wrap_wxMiniFrame construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(wxMiniFrame);
AMI_DEFINE_VARFROMSMTPTR(wxMiniFrame);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<wxMiniFrame>::CreateVar( wxMiniFrame* val, bool nodeleter)
{ 
  boost::shared_ptr<wxMiniFrame> obj_ptr(val,smartpointer_nodeleter<wxMiniFrame>());
  return AMILabType<wxMiniFrame>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxMiniFrame
//
Variable<AMIObject>::ptr WrapClass_wxMiniFrame::CreateVar( wxMiniFrame* sp)
{
  boost::shared_ptr<wxMiniFrame> di_ptr(
    sp,
    wxwindow_nodeleter<wxMiniFrame>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxMiniFrame>::CreateVar(
      new WrapClass_wxMiniFrame(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxMiniFrame::AddMethods(WrapClass<wxMiniFrame>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
      // Adding standard methods 
      AddVar_GetClassInfo( this_ptr);
      AddVar_Create( this_ptr);
      AddVar_SetTitle( this_ptr);



  // Add public fields
      AMIObject::ptr tmpobj(amiobject.lock());
      if (!tmpobj.get()) return;
      Variables::ptr context(tmpobj->GetContext());
      
      // Adding public member m_isDragging
      boost::shared_ptr<bool > var_m_isDragging_ptr(&GetObj()->m_isDragging, smartpointer_nodeleter<bool >());
      if (var_m_isDragging_ptr.get()) {
        BasicVariable::ptr var_m_isDragging = AMILabType<bool >::CreateVarFromSmtPtr(var_m_isDragging_ptr);
        if (var_m_isDragging.get()) {
          var_m_isDragging->Rename("m_isDragging");
          context->AddVar(var_m_isDragging,context);
        }
      }
      
      // Adding public member m_oldX
      boost::shared_ptr<int > var_m_oldX_ptr(&GetObj()->m_oldX, smartpointer_nodeleter<int >());
      if (var_m_oldX_ptr.get()) {
        BasicVariable::ptr var_m_oldX = AMILabType<int >::CreateVarFromSmtPtr(var_m_oldX_ptr);
        if (var_m_oldX.get()) {
          var_m_oldX->Rename("m_oldX");
          context->AddVar(var_m_oldX,context);
        }
      }
      
      // Adding public member m_oldY
      boost::shared_ptr<int > var_m_oldY_ptr(&GetObj()->m_oldY, smartpointer_nodeleter<int >());
      if (var_m_oldY_ptr.get()) {
        BasicVariable::ptr var_m_oldY = AMILabType<int >::CreateVarFromSmtPtr(var_m_oldY_ptr);
        if (var_m_oldY.get()) {
          var_m_oldY->Rename("m_oldY");
          context->AddVar(var_m_oldY,context);
        }
      }
      
      // Adding public member m_diffX
      boost::shared_ptr<int > var_m_diffX_ptr(&GetObj()->m_diffX, smartpointer_nodeleter<int >());
      if (var_m_diffX_ptr.get()) {
        BasicVariable::ptr var_m_diffX = AMILabType<int >::CreateVarFromSmtPtr(var_m_diffX_ptr);
        if (var_m_diffX.get()) {
          var_m_diffX->Rename("m_diffX");
          context->AddVar(var_m_diffX,context);
        }
      }
      
      // Adding public member m_diffY
      boost::shared_ptr<int > var_m_diffY_ptr(&GetObj()->m_diffY, smartpointer_nodeleter<int >());
      if (var_m_diffY_ptr.get()) {
        BasicVariable::ptr var_m_diffY = AMILabType<int >::CreateVarFromSmtPtr(var_m_diffY_ptr);
        if (var_m_diffY.get()) {
          var_m_diffY->Rename("m_diffY");
          context->AddVar(var_m_diffY,context);
        }
      }
      
      // Adding public member m_closeButton
      boost::shared_ptr<wxBitmap > var_m_closeButton_ptr(&GetObj()->m_closeButton, smartpointer_nodeleter<wxBitmap >());
      if (var_m_closeButton_ptr.get()) {
        BasicVariable::ptr var_m_closeButton = AMILabType<wxBitmap >::CreateVarFromSmtPtr(var_m_closeButton_ptr);
        if (var_m_closeButton.get()) {
          var_m_closeButton->Rename("m_closeButton");
          context->AddVar(var_m_closeButton,context);
        }
      }


  // Adding Bases

  // Add base parent wxFrame
  boost::shared_ptr<wxFrame > parent_wxFrame(  boost::dynamic_pointer_cast<wxFrame >(this_ptr->GetObj()));
  BasicVariable::ptr var_wxFrame = AMILabType<wxFrame >::CreateVarFromSmtPtr(parent_wxFrame);
  context->AddVar("wxFrame",var_wxFrame);
  // Set as a default context
  Variable<AMIObject>::ptr obj_wxFrame = boost::dynamic_pointer_cast<Variable<AMIObject> >(var_wxFrame);
  context->AddDefault(obj_wxFrame->Pointer()->GetContext());

};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClass_wxMiniFrame::AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxMiniFrame");
    WrapClass_wxMiniFrame::AddVar_wxMiniFrame_1(amiobject->GetContext());
  WrapClass_wxMiniFrame::AddVar_wxMiniFrame(amiobject->GetContext());
  WrapClass_wxMiniFrame::AddVar_wxMiniFrame_2(amiobject->GetContext());


  // Static methods 

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxMiniFrame::wxMiniFrame()
//---------------------------------------------------
void WrapClass_wxMiniFrame::
    wrap_wxMiniFrame_1::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMiniFrame::
    wrap_wxMiniFrame_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxMiniFrame* _newobj = new wxMiniFrame();
  BasicVariable::ptr res = WrapClass_wxMiniFrame::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor wxMiniFrame::wxMiniFrame(...)
//---------------------------------------------------
void WrapClass_wxMiniFrame::
    wrap_wxMiniFrame::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMiniFrame::
    wrap_wxMiniFrame::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxMiniFrame::wrap_wxMiniFrame_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxMiniFrame::wrap_wxMiniFrame_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor wxMiniFrame::wxMiniFrame(wxWindow * parent, wxWindowID id, wxString const & title, wxPoint const & pos = wxDefaultPosition, wxSize const & size = wxDefaultSize, long int style = 536870976, wxString const & name = wxFrameNameStr)
//---------------------------------------------------
void WrapClass_wxMiniFrame::
    wrap_wxMiniFrame_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'parent'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'id'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'title'")
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'pos' (def:wxDefaultPosition)")
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 'size' (def:wxDefaultSize)")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'style' (def:536870976)")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'name' (def:wxFrameNameStr)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMiniFrame::
    wrap_wxMiniFrame_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>7) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxWindow > parent_smtptr;
  if (!get_val_smtptr_param<wxWindow >(parent_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxWindow* parent = parent_smtptr.get();

  int id;
  if (!get_val_param<int >(id,_p,_n,true,true)) ClassReturnEmptyVar;

  boost::shared_ptr<wxString > title_smtptr;
  if (!get_val_smtptr_param<wxString >(title_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxString const & title = *title_smtptr;

  boost::shared_ptr<wxPoint > pos_smtptr;
  if (!get_val_smtptr_param<wxPoint >(pos_smtptr,_p,_n,false,false,true)) ClassReturnEmptyVar;
  // Setting default value if no value is returned
  wxPoint const & pos = ( pos_smtptr.get() ? (*pos_smtptr) : wxDefaultPosition );

  boost::shared_ptr<wxSize > size_smtptr;
  if (!get_val_smtptr_param<wxSize >(size_smtptr,_p,_n,false,false,true)) ClassReturnEmptyVar;
  // Setting default value if no value is returned
  wxSize const & size = ( size_smtptr.get() ? (*size_smtptr) : wxDefaultSize );

  long style_long = 536870976;;
  if (!get_val_param<long >(style_long,_p,_n,false,true)) ClassReturnEmptyVar;
  long int style = style_long;

  boost::shared_ptr<wxString > name_smtptr;
  if (!get_val_smtptr_param<wxString >(name_smtptr,_p,_n,false,false,true)) ClassReturnEmptyVar;
  // Setting default value if no value is returned
  wxString const & name = ( name_smtptr.get() ? (*name_smtptr) : wxString(wxFrameNameStr) );

  wxMiniFrame* _newobj = new wxMiniFrame(parent, id, title, pos, size, style, name);
  BasicVariable::ptr res = WrapClass_wxMiniFrame::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of wxClassInfo * wxMiniFrame::GetClassInfo()
//---------------------------------------------------
void WrapClass_wxMiniFrame::
    wrap_GetClassInfo::SetParametersComments()
{
  return_comments="returning a variable of type wxClassInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMiniFrame::
    wrap_GetClassInfo::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxClassInfo * res =   this->_objectptr->GetObj()->GetClassInfo();
  BasicVariable::ptr res_var = WrapClass_wxClassInfo::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of bool wxMiniFrame::Create(wxWindow * parent, wxWindowID id, wxString const & title, wxPoint const & pos = wxDefaultPosition, wxSize const & size = wxDefaultSize, long int style = 536870976, wxString const & name = wxFrameNameStr)
//---------------------------------------------------
void WrapClass_wxMiniFrame::
    wrap_Create::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'parent'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'id'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'title'")
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'pos' (def:wxDefaultPosition)")
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 'size' (def:wxDefaultSize)")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'style' (def:536870976)")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'name' (def:wxFrameNameStr)")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMiniFrame::
    wrap_Create::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>7) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxWindow > parent_smtptr;
  if (!get_val_smtptr_param<wxWindow >(parent_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxWindow* parent = parent_smtptr.get();

  int id;
  if (!get_val_param<int >(id,_p,_n,true,false)) ClassHelpAndReturn;

  boost::shared_ptr<wxString > title_smtptr;
  if (!get_val_smtptr_param<wxString >(title_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & title = *title_smtptr;

  boost::shared_ptr<wxPoint > pos_smtptr;
  if (!get_val_smtptr_param<wxPoint >(pos_smtptr,_p,_n,false,false,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  wxPoint const & pos = ( pos_smtptr.get() ? (*pos_smtptr) : wxDefaultPosition );

  boost::shared_ptr<wxSize > size_smtptr;
  if (!get_val_smtptr_param<wxSize >(size_smtptr,_p,_n,false,false,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  wxSize const & size = ( size_smtptr.get() ? (*size_smtptr) : wxDefaultSize );

  long style_long = 536870976;;
  if (!get_val_param<long >(style_long,_p,_n,false,false)) ClassHelpAndReturn;
  long int style = style_long;

  boost::shared_ptr<wxString > name_smtptr;
  if (!get_val_smtptr_param<wxString >(name_smtptr,_p,_n,false,false,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  wxString const & name = ( name_smtptr.get() ? (*name_smtptr) : wxString(wxFrameNameStr) );

  bool res =   this->_objectptr->GetObj()->Create(parent, id, title, pos, size, style, name);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxMiniFrame::SetTitle(wxString const & title)
//---------------------------------------------------
void WrapClass_wxMiniFrame::
    wrap_SetTitle::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'title'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMiniFrame::
    wrap_SetTitle::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > title_smtptr;
  if (!get_val_smtptr_param<wxString >(title_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & title = *title_smtptr;

  this->_objectptr->GetObj()->SetTitle(title);
  return BasicVariable::ptr();
}

