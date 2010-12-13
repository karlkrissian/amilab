/**
 * C++ Interface: wrap_wxSizerItem
 *
 * Description: wrapping wxSizerItem
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

#include "wrap_wxSizerItem.h"

// get all the required includes
// #include "..."
#ifndef wxWindow_declared
  #define wxWindow_declared
  AMI_DECLARE_TYPE(wxWindow)
#endif
#ifndef wxObject_declared
  #define wxObject_declared
  AMI_DECLARE_TYPE(wxObject)
#endif
#ifndef wxSizerFlags_declared
  #define wxSizerFlags_declared
  AMI_DECLARE_TYPE(wxSizerFlags)
#endif
#ifndef wxSizer_declared
  #define wxSizer_declared
  AMI_DECLARE_TYPE(wxSizer)
#endif
#ifndef wxSize_declared
  #define wxSize_declared
  AMI_DECLARE_TYPE(wxSize)
#endif
#ifndef wxPoint_declared
  #define wxPoint_declared
  AMI_DECLARE_TYPE(wxPoint)
#endif
#ifndef wxRect_declared
  #define wxRect_declared
  AMI_DECLARE_TYPE(wxRect)
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
BasicVariable::ptr WrapClass<wxSizerItem>::CreateVar( ParamList* p)
{
  WrapClass_wxSizerItem::wrap_wxSizerItem construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(wxSizerItem);
AMI_DEFINE_VARFROMSMTPTR(wxSizerItem);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<wxSizerItem>::CreateVar( wxSizerItem* val, bool nodeleter)
{ 
  boost::shared_ptr<wxSizerItem> obj_ptr(val,smartpointer_nodeleter<wxSizerItem>());
  return AMILabType<wxSizerItem>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxSizerItem
//
Variable<AMIObject>::ptr WrapClass_wxSizerItem::CreateVar( wxSizerItem* sp)
{
  boost::shared_ptr<wxSizerItem> di_ptr(
    sp,
    wxwindow_nodeleter<wxSizerItem>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxSizerItem>::CreateVar(
      new WrapClass_wxSizerItem(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxSizerItem::AddMethods(WrapClass<wxSizerItem>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding standard methods 
  AddVar_DeleteWindows( this_ptr);
  AddVar_DetachSizer( this_ptr);
  AddVar_GetSize( this_ptr);
  AddVar_CalcMin( this_ptr);
  AddVar_SetDimension( this_ptr);
  AddVar_GetMinSize( this_ptr);
  AddVar_GetMinSizeWithBorder( this_ptr);
  AddVar_SetMinSize_1( this_ptr);
  AddVar_SetMinSize( this_ptr);
  AddVar_SetMinSize_2( this_ptr);
  AddVar_SetInitSize( this_ptr);
  AddVar_SetRatio_1( this_ptr);
  AddVar_SetRatio( this_ptr);
  AddVar_SetRatio_2( this_ptr);
  AddVar_SetRatio_3( this_ptr);
  AddVar_GetRatio( this_ptr);
  AddVar_GetRect( this_ptr);
  AddVar_IsWindow( this_ptr);
  AddVar_IsSizer( this_ptr);
  AddVar_IsSpacer( this_ptr);
  AddVar_SetProportion( this_ptr);
  AddVar_GetProportion( this_ptr);
  AddVar_SetFlag( this_ptr);
  AddVar_GetFlag( this_ptr);
  AddVar_SetBorder( this_ptr);
  AddVar_GetBorder( this_ptr);
  AddVar_GetWindow( this_ptr);
  AddVar_GetSizer( this_ptr);
  AddVar_GetSpacer( this_ptr);
  AddVar_IsShown( this_ptr);
  AddVar_Show( this_ptr);
  AddVar_SetUserData( this_ptr);
  AddVar_GetUserData( this_ptr);
  AddVar_GetPosition( this_ptr);
  AddVar_SetWindow( this_ptr);
  AddVar_SetSizer( this_ptr);
  AddVar_SetSpacer_1( this_ptr);
  AddVar_SetSpacer( this_ptr);
  AddVar_SetSpacer_2( this_ptr);
  AddVar_GetClassInfo( this_ptr);



  

  


  // Get the current context
  AMIObject::ptr tmpobj(amiobject.lock());
  if (!tmpobj.get()) return;
  Variables::ptr context(tmpobj->GetContext());

  // Add base parent wxObject
  boost::shared_ptr<wxObject > parent_wxObject(  boost::dynamic_pointer_cast<wxObject >(this_ptr->GetObj()));
  BasicVariable::ptr var_wxObject = AMILabType<wxObject >::CreateVarFromSmtPtr(parent_wxObject);
  context->AddVar("wxObject",var_wxObject);
  // Set as a default context
  Variable<AMIObject>::ptr obj_wxObject = boost::dynamic_pointer_cast<Variable<AMIObject> >(var_wxObject);
  context->AddDefault(obj_wxObject->Pointer()->GetContext());

};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxSizerItem_AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxSizerItem");
    WrapClass_wxSizerItem::AddVar_wxSizerItem_1(amiobject->GetContext());
  WrapClass_wxSizerItem::AddVar_wxSizerItem(amiobject->GetContext());
  WrapClass_wxSizerItem::AddVar_wxSizerItem_2(amiobject->GetContext());
  WrapClass_wxSizerItem::AddVar_wxSizerItem_3(amiobject->GetContext());
  WrapClass_wxSizerItem::AddVar_wxSizerItem_4(amiobject->GetContext());
  WrapClass_wxSizerItem::AddVar_wxSizerItem_5(amiobject->GetContext());
  WrapClass_wxSizerItem::AddVar_wxSizerItem_6(amiobject->GetContext());
  WrapClass_wxSizerItem::AddVar_wxSizerItem_7(amiobject->GetContext());


  // Static methods 

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxSizerItem::wxSizerItem(wxWindow * window, int proportion, int flag, int border, wxObject * userData)
//---------------------------------------------------
void WrapClass_wxSizerItem::
    wrap_wxSizerItem_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'window'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'proportion'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'flag'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'border'")
  ADDPARAMCOMMENT_TYPE( wxObject, "parameter named 'userData'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerItem::
    wrap_wxSizerItem_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>5) ClassReturnEmptyVar;
  int _n=0;

  wxWindow* window;
  if (CheckNullVar(_p,_n))  {
    window=(wxWindow*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxWindow > window_smtptr;
    if (!get_val_smtptr_param<wxWindow >(window_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    window = window_smtptr.get();
  }

  int proportion;
  if (!get_val_param<int >(proportion,_p,_n,true,true)) ClassReturnEmptyVar;

  int flag;
  if (!get_val_param<int >(flag,_p,_n,true,true)) ClassReturnEmptyVar;

  int border;
  if (!get_val_param<int >(border,_p,_n,true,true)) ClassReturnEmptyVar;

  wxObject* userData;
  if (CheckNullVar(_p,_n))  {
    userData=(wxObject*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxObject > userData_smtptr;
    if (!get_val_smtptr_param<wxObject >(userData_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    userData = userData_smtptr.get();
  }

  wxSizerItem* _newobj = new wxSizerItem(window, proportion, flag, border, userData);
  BasicVariable::ptr res = WrapClass_wxSizerItem::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor wxSizerItem::wxSizerItem(...)
//---------------------------------------------------
void WrapClass_wxSizerItem::
    wrap_wxSizerItem::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerItem::
    wrap_wxSizerItem::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxSizerItem::wrap_wxSizerItem_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxSizerItem::wrap_wxSizerItem_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxSizerItem::wrap_wxSizerItem_3 m3;
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  WrapClass_wxSizerItem::wrap_wxSizerItem_4 m4;
  res = m4.CallMember(_p);
  if (!m4.Get_arg_failure()) return res;
  WrapClass_wxSizerItem::wrap_wxSizerItem_5 m5;
  res = m5.CallMember(_p);
  if (!m5.Get_arg_failure()) return res;
  WrapClass_wxSizerItem::wrap_wxSizerItem_6 m6;
  res = m6.CallMember(_p);
  if (!m6.Get_arg_failure()) return res;
  WrapClass_wxSizerItem::wrap_wxSizerItem_7 m7;
  res = m7.CallMember(_p);
  if (!m7.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor wxSizerItem::wxSizerItem(wxWindow * window, wxSizerFlags const & flags)
//---------------------------------------------------
void WrapClass_wxSizerItem::
    wrap_wxSizerItem_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'window'")
  ADDPARAMCOMMENT_TYPE( wxSizerFlags, "parameter named 'flags'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerItem::
    wrap_wxSizerItem_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  wxWindow* window;
  if (CheckNullVar(_p,_n))  {
    window=(wxWindow*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxWindow > window_smtptr;
    if (!get_val_smtptr_param<wxWindow >(window_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    window = window_smtptr.get();
  }

  boost::shared_ptr<wxSizerFlags > flags_smtptr;
  if (!get_val_smtptr_param<wxSizerFlags >(flags_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxSizerFlags const & flags = *flags_smtptr;

  wxSizerItem* _newobj = new wxSizerItem(window, flags);
  BasicVariable::ptr res = WrapClass_wxSizerItem::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of Constructor wxSizerItem::wxSizerItem(wxSizer * sizer, int proportion, int flag, int border, wxObject * userData)
//---------------------------------------------------
void WrapClass_wxSizerItem::
    wrap_wxSizerItem_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxSizer, "parameter named 'sizer'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'proportion'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'flag'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'border'")
  ADDPARAMCOMMENT_TYPE( wxObject, "parameter named 'userData'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerItem::
    wrap_wxSizerItem_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>5) ClassReturnEmptyVar;
  int _n=0;

  wxSizer* sizer;
  if (CheckNullVar(_p,_n))  {
    sizer=(wxSizer*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxSizer > sizer_smtptr;
    if (!get_val_smtptr_param<wxSizer >(sizer_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    sizer = sizer_smtptr.get();
  }

  int proportion;
  if (!get_val_param<int >(proportion,_p,_n,true,true)) ClassReturnEmptyVar;

  int flag;
  if (!get_val_param<int >(flag,_p,_n,true,true)) ClassReturnEmptyVar;

  int border;
  if (!get_val_param<int >(border,_p,_n,true,true)) ClassReturnEmptyVar;

  wxObject* userData;
  if (CheckNullVar(_p,_n))  {
    userData=(wxObject*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxObject > userData_smtptr;
    if (!get_val_smtptr_param<wxObject >(userData_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    userData = userData_smtptr.get();
  }

  wxSizerItem* _newobj = new wxSizerItem(sizer, proportion, flag, border, userData);
  BasicVariable::ptr res = WrapClass_wxSizerItem::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of Constructor wxSizerItem::wxSizerItem(wxSizer * sizer, wxSizerFlags const & flags)
//---------------------------------------------------
void WrapClass_wxSizerItem::
    wrap_wxSizerItem_4::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxSizer, "parameter named 'sizer'")
  ADDPARAMCOMMENT_TYPE( wxSizerFlags, "parameter named 'flags'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerItem::
    wrap_wxSizerItem_4::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  wxSizer* sizer;
  if (CheckNullVar(_p,_n))  {
    sizer=(wxSizer*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxSizer > sizer_smtptr;
    if (!get_val_smtptr_param<wxSizer >(sizer_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    sizer = sizer_smtptr.get();
  }

  boost::shared_ptr<wxSizerFlags > flags_smtptr;
  if (!get_val_smtptr_param<wxSizerFlags >(flags_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxSizerFlags const & flags = *flags_smtptr;

  wxSizerItem* _newobj = new wxSizerItem(sizer, flags);
  BasicVariable::ptr res = WrapClass_wxSizerItem::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of Constructor wxSizerItem::wxSizerItem(int width, int height, int proportion, int flag, int border, wxObject * userData)
//---------------------------------------------------
void WrapClass_wxSizerItem::
    wrap_wxSizerItem_5::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'width'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'height'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'proportion'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'flag'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'border'")
  ADDPARAMCOMMENT_TYPE( wxObject, "parameter named 'userData'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerItem::
    wrap_wxSizerItem_5::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>6) ClassReturnEmptyVar;
  int _n=0;

  int width;
  if (!get_val_param<int >(width,_p,_n,true,true)) ClassReturnEmptyVar;

  int height;
  if (!get_val_param<int >(height,_p,_n,true,true)) ClassReturnEmptyVar;

  int proportion;
  if (!get_val_param<int >(proportion,_p,_n,true,true)) ClassReturnEmptyVar;

  int flag;
  if (!get_val_param<int >(flag,_p,_n,true,true)) ClassReturnEmptyVar;

  int border;
  if (!get_val_param<int >(border,_p,_n,true,true)) ClassReturnEmptyVar;

  wxObject* userData;
  if (CheckNullVar(_p,_n))  {
    userData=(wxObject*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxObject > userData_smtptr;
    if (!get_val_smtptr_param<wxObject >(userData_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    userData = userData_smtptr.get();
  }

  wxSizerItem* _newobj = new wxSizerItem(width, height, proportion, flag, border, userData);
  BasicVariable::ptr res = WrapClass_wxSizerItem::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of Constructor wxSizerItem::wxSizerItem(int width, int height, wxSizerFlags const & flags)
//---------------------------------------------------
void WrapClass_wxSizerItem::
    wrap_wxSizerItem_6::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'width'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'height'")
  ADDPARAMCOMMENT_TYPE( wxSizerFlags, "parameter named 'flags'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerItem::
    wrap_wxSizerItem_6::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  int width;
  if (!get_val_param<int >(width,_p,_n,true,true)) ClassReturnEmptyVar;

  int height;
  if (!get_val_param<int >(height,_p,_n,true,true)) ClassReturnEmptyVar;

  boost::shared_ptr<wxSizerFlags > flags_smtptr;
  if (!get_val_smtptr_param<wxSizerFlags >(flags_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxSizerFlags const & flags = *flags_smtptr;

  wxSizerItem* _newobj = new wxSizerItem(width, height, flags);
  BasicVariable::ptr res = WrapClass_wxSizerItem::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of Constructor wxSizerItem::wxSizerItem()
//---------------------------------------------------
void WrapClass_wxSizerItem::
    wrap_wxSizerItem_7::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerItem::
    wrap_wxSizerItem_7::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxSizerItem* _newobj = new wxSizerItem();
  BasicVariable::ptr res = WrapClass_wxSizerItem::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of void wxSizerItem::DeleteWindows()
//---------------------------------------------------
void WrapClass_wxSizerItem::
    wrap_DeleteWindows::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerItem::
    wrap_DeleteWindows::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->DeleteWindows();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxSizerItem::DetachSizer()
//---------------------------------------------------
void WrapClass_wxSizerItem::
    wrap_DetachSizer::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerItem::
    wrap_DetachSizer::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->DetachSizer();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxSize wxSizerItem::GetSize()
//---------------------------------------------------
void WrapClass_wxSizerItem::
    wrap_GetSize::SetParametersComments()
{
  return_comments="returning a variable of type wxSize";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerItem::
    wrap_GetSize::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxSize res =   this->_objectptr->GetObj()->GetSize();
  return AMILabType<wxSize >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxSize wxSizerItem::CalcMin()
//---------------------------------------------------
void WrapClass_wxSizerItem::
    wrap_CalcMin::SetParametersComments()
{
  return_comments="returning a variable of type wxSize";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerItem::
    wrap_CalcMin::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxSize res =   this->_objectptr->GetObj()->CalcMin();
  return AMILabType<wxSize >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxSizerItem::SetDimension(wxPoint const & pos, wxSize const & size)
//---------------------------------------------------
void WrapClass_wxSizerItem::
    wrap_SetDimension::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'pos'")
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 'size'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerItem::
    wrap_SetDimension::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxPoint > pos_smtptr;
  if (!get_val_smtptr_param<wxPoint >(pos_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxPoint const & pos = *pos_smtptr;

  boost::shared_ptr<wxSize > size_smtptr;
  if (!get_val_smtptr_param<wxSize >(size_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxSize const & size = *size_smtptr;

  this->_objectptr->GetObj()->SetDimension(pos, size);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxSize wxSizerItem::GetMinSize()
//---------------------------------------------------
void WrapClass_wxSizerItem::
    wrap_GetMinSize::SetParametersComments()
{
  return_comments="returning a variable of type wxSize";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerItem::
    wrap_GetMinSize::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxSize res =   this->_objectptr->GetObj()->GetMinSize();
  return AMILabType<wxSize >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxSize wxSizerItem::GetMinSizeWithBorder()
//---------------------------------------------------
void WrapClass_wxSizerItem::
    wrap_GetMinSizeWithBorder::SetParametersComments()
{
  return_comments="returning a variable of type wxSize";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerItem::
    wrap_GetMinSizeWithBorder::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxSize res =   this->_objectptr->GetObj()->GetMinSizeWithBorder();
  return AMILabType<wxSize >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxSizerItem::SetMinSize(wxSize const & size)
//---------------------------------------------------
void WrapClass_wxSizerItem::
    wrap_SetMinSize_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 'size'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerItem::
    wrap_SetMinSize_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxSize > size_smtptr;
  if (!get_val_smtptr_param<wxSize >(size_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxSize const & size = *size_smtptr;

  this->_objectptr->GetObj()->SetMinSize(size);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxSizerItem::SetMinSize(...)
//---------------------------------------------------
void WrapClass_wxSizerItem::
    wrap_SetMinSize::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerItem::
    wrap_SetMinSize::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxSizerItem::wrap_SetMinSize_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxSizerItem::wrap_SetMinSize_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void wxSizerItem::SetMinSize(int x, int y)
//---------------------------------------------------
void WrapClass_wxSizerItem::
    wrap_SetMinSize_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerItem::
    wrap_SetMinSize_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  int x;
  if (!get_val_param<int >(x,_p,_n,true,true)) ClassReturnEmptyVar;

  int y;
  if (!get_val_param<int >(y,_p,_n,true,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->SetMinSize(x, y);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxSizerItem::SetInitSize(int x, int y)
//---------------------------------------------------
void WrapClass_wxSizerItem::
    wrap_SetInitSize::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerItem::
    wrap_SetInitSize::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  int x;
  if (!get_val_param<int >(x,_p,_n,true,false)) ClassHelpAndReturn;

  int y;
  if (!get_val_param<int >(y,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetInitSize(x, y);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxSizerItem::SetRatio(int width, int height)
//---------------------------------------------------
void WrapClass_wxSizerItem::
    wrap_SetRatio_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'width'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'height'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerItem::
    wrap_SetRatio_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  int width;
  if (!get_val_param<int >(width,_p,_n,true,true)) ClassReturnEmptyVar;

  int height;
  if (!get_val_param<int >(height,_p,_n,true,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->SetRatio(width, height);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxSizerItem::SetRatio(...)
//---------------------------------------------------
void WrapClass_wxSizerItem::
    wrap_SetRatio::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerItem::
    wrap_SetRatio::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxSizerItem::wrap_SetRatio_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxSizerItem::wrap_SetRatio_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxSizerItem::wrap_SetRatio_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void wxSizerItem::SetRatio(wxSize const & size)
//---------------------------------------------------
void WrapClass_wxSizerItem::
    wrap_SetRatio_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 'size'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerItem::
    wrap_SetRatio_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxSize > size_smtptr;
  if (!get_val_smtptr_param<wxSize >(size_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxSize const & size = *size_smtptr;

  this->_objectptr->GetObj()->SetRatio(size);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxSizerItem::SetRatio(float ratio)
//---------------------------------------------------
void WrapClass_wxSizerItem::
    wrap_SetRatio_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( float, "parameter named 'ratio'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerItem::
    wrap_SetRatio_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  float ratio;
  if (!get_val_param<float >(ratio,_p,_n,true,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->SetRatio(ratio);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of float wxSizerItem::GetRatio()
//---------------------------------------------------
void WrapClass_wxSizerItem::
    wrap_GetRatio::SetParametersComments()
{
  return_comments="returning a variable of type float";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerItem::
    wrap_GetRatio::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  float res =   this->_objectptr->GetObj()->GetRatio();
  return AMILabType<float >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxRect wxSizerItem::GetRect()
//---------------------------------------------------
void WrapClass_wxSizerItem::
    wrap_GetRect::SetParametersComments()
{
  return_comments="returning a variable of type wxRect";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerItem::
    wrap_GetRect::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxRect res =   this->_objectptr->GetObj()->GetRect();
  return AMILabType<wxRect >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxSizerItem::IsWindow()
//---------------------------------------------------
void WrapClass_wxSizerItem::
    wrap_IsWindow::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerItem::
    wrap_IsWindow::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsWindow();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxSizerItem::IsSizer()
//---------------------------------------------------
void WrapClass_wxSizerItem::
    wrap_IsSizer::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerItem::
    wrap_IsSizer::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsSizer();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxSizerItem::IsSpacer()
//---------------------------------------------------
void WrapClass_wxSizerItem::
    wrap_IsSpacer::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerItem::
    wrap_IsSpacer::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsSpacer();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxSizerItem::SetProportion(int proportion)
//---------------------------------------------------
void WrapClass_wxSizerItem::
    wrap_SetProportion::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'proportion'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerItem::
    wrap_SetProportion::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int proportion;
  if (!get_val_param<int >(proportion,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetProportion(proportion);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int wxSizerItem::GetProportion()
//---------------------------------------------------
void WrapClass_wxSizerItem::
    wrap_GetProportion::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerItem::
    wrap_GetProportion::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetProportion();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxSizerItem::SetFlag(int flag)
//---------------------------------------------------
void WrapClass_wxSizerItem::
    wrap_SetFlag::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'flag'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerItem::
    wrap_SetFlag::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int flag;
  if (!get_val_param<int >(flag,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetFlag(flag);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int wxSizerItem::GetFlag()
//---------------------------------------------------
void WrapClass_wxSizerItem::
    wrap_GetFlag::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerItem::
    wrap_GetFlag::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetFlag();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxSizerItem::SetBorder(int border)
//---------------------------------------------------
void WrapClass_wxSizerItem::
    wrap_SetBorder::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'border'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerItem::
    wrap_SetBorder::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int border;
  if (!get_val_param<int >(border,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetBorder(border);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int wxSizerItem::GetBorder()
//---------------------------------------------------
void WrapClass_wxSizerItem::
    wrap_GetBorder::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerItem::
    wrap_GetBorder::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetBorder();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxWindow * wxSizerItem::GetWindow()
//---------------------------------------------------
void WrapClass_wxSizerItem::
    wrap_GetWindow::SetParametersComments()
{
  return_comments="returning a variable of type wxWindow";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerItem::
    wrap_GetWindow::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxWindow * res =   this->_objectptr->GetObj()->GetWindow();
  BasicVariable::ptr res_var = AMILabType<wxWindow >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxSizer * wxSizerItem::GetSizer()
//---------------------------------------------------
void WrapClass_wxSizerItem::
    wrap_GetSizer::SetParametersComments()
{
  return_comments="returning a variable of type wxSizer";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerItem::
    wrap_GetSizer::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxSizer * res =   this->_objectptr->GetObj()->GetSizer();
  BasicVariable::ptr res_var = AMILabType<wxSizer >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxSize wxSizerItem::GetSpacer()
//---------------------------------------------------
void WrapClass_wxSizerItem::
    wrap_GetSpacer::SetParametersComments()
{
  return_comments="returning a variable of type wxSize";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerItem::
    wrap_GetSpacer::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxSize res =   this->_objectptr->GetObj()->GetSpacer();
  return AMILabType<wxSize >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxSizerItem::IsShown()
//---------------------------------------------------
void WrapClass_wxSizerItem::
    wrap_IsShown::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerItem::
    wrap_IsShown::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsShown();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxSizerItem::Show(bool show)
//---------------------------------------------------
void WrapClass_wxSizerItem::
    wrap_Show::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( bool, "parameter named 'show'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerItem::
    wrap_Show::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  bool show;
  if (!get_val_param<bool >(show,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Show(show);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxSizerItem::SetUserData(wxObject * userData)
//---------------------------------------------------
void WrapClass_wxSizerItem::
    wrap_SetUserData::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxObject, "parameter named 'userData'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerItem::
    wrap_SetUserData::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  wxObject* userData;
  if (CheckNullVar(_p,_n))  {
    userData=(wxObject*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxObject > userData_smtptr;
    if (!get_val_smtptr_param<wxObject >(userData_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    userData = userData_smtptr.get();
  }

  this->_objectptr->GetObj()->SetUserData(userData);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxObject * wxSizerItem::GetUserData()
//---------------------------------------------------
void WrapClass_wxSizerItem::
    wrap_GetUserData::SetParametersComments()
{
  return_comments="returning a variable of type wxObject";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerItem::
    wrap_GetUserData::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxObject * res =   this->_objectptr->GetObj()->GetUserData();
  BasicVariable::ptr res_var = AMILabType<wxObject >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxPoint wxSizerItem::GetPosition()
//---------------------------------------------------
void WrapClass_wxSizerItem::
    wrap_GetPosition::SetParametersComments()
{
  return_comments="returning a variable of type wxPoint";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerItem::
    wrap_GetPosition::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxPoint res =   this->_objectptr->GetObj()->GetPosition();
  return AMILabType<wxPoint >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxSizerItem::SetWindow(wxWindow * window)
//---------------------------------------------------
void WrapClass_wxSizerItem::
    wrap_SetWindow::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'window'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerItem::
    wrap_SetWindow::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  wxWindow* window;
  if (CheckNullVar(_p,_n))  {
    window=(wxWindow*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxWindow > window_smtptr;
    if (!get_val_smtptr_param<wxWindow >(window_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    window = window_smtptr.get();
  }

  this->_objectptr->GetObj()->SetWindow(window);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxSizerItem::SetSizer(wxSizer * sizer)
//---------------------------------------------------
void WrapClass_wxSizerItem::
    wrap_SetSizer::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxSizer, "parameter named 'sizer'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerItem::
    wrap_SetSizer::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  wxSizer* sizer;
  if (CheckNullVar(_p,_n))  {
    sizer=(wxSizer*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxSizer > sizer_smtptr;
    if (!get_val_smtptr_param<wxSizer >(sizer_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    sizer = sizer_smtptr.get();
  }

  this->_objectptr->GetObj()->SetSizer(sizer);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxSizerItem::SetSpacer(wxSize const & size)
//---------------------------------------------------
void WrapClass_wxSizerItem::
    wrap_SetSpacer_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 'size'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerItem::
    wrap_SetSpacer_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxSize > size_smtptr;
  if (!get_val_smtptr_param<wxSize >(size_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxSize const & size = *size_smtptr;

  this->_objectptr->GetObj()->SetSpacer(size);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxSizerItem::SetSpacer(...)
//---------------------------------------------------
void WrapClass_wxSizerItem::
    wrap_SetSpacer::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerItem::
    wrap_SetSpacer::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxSizerItem::wrap_SetSpacer_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxSizerItem::wrap_SetSpacer_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void wxSizerItem::SetSpacer(int width, int height)
//---------------------------------------------------
void WrapClass_wxSizerItem::
    wrap_SetSpacer_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'width'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'height'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerItem::
    wrap_SetSpacer_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  int width;
  if (!get_val_param<int >(width,_p,_n,true,true)) ClassReturnEmptyVar;

  int height;
  if (!get_val_param<int >(height,_p,_n,true,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->SetSpacer(width, height);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxClassInfo * wxSizerItem::GetClassInfo()
//---------------------------------------------------
void WrapClass_wxSizerItem::
    wrap_GetClassInfo::SetParametersComments()
{
  return_comments="returning a variable of type wxClassInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerItem::
    wrap_GetClassInfo::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxClassInfo * res =   this->_objectptr->GetObj()->GetClassInfo();
  BasicVariable::ptr res_var = AMILabType<wxClassInfo >::CreateVar(res,true);
  return res_var;
}

