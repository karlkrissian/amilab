/**
 * C++ Interface: wrap_wxSizer
 *
 * Description: wrapping wxSizer
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
#include "wrap_wxSizerItem.h"
#include "wrap_wxWindow.h"
#include "wrap_wxObject.h"
#include "wrap_wxSizer.h"
#include "wrap_wxSizerFlags.h"
#include "boost/numeric/conversion/cast.hpp"
#include "wrap_wxSize.h"
#include "wrap_wxPoint.h"
#include "wrap_wxSizerItemList.h"
#include "wrap_wxClassInfo.h"


#include "wrap_wxSizer.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxSizer>::CreateVar( ParamList* p)
{
  // No variable creation for an abstract class ...
  return BasicVariable::ptr();

}


AMI_DEFINE_WRAPPEDTYPE_ABSTRACT(wxSizer);
AMI_DEFINE_VARFROMSMTPTR(wxSizer);


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxSizer
//
Variable<AMIObject>::ptr WrapClass_wxSizer::CreateVar( wxSizer* sp)
{
  boost::shared_ptr<wxSizer> di_ptr(
    sp,
    wxwindow_nodeleter<wxSizer>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxSizer>::CreateVar(
      new WrapClass_wxSizer(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxSizer::AddMethods(WrapClass<wxSizer>::ptr this_ptr )
{
  
      // Add members from wxObject
      WrapClass_wxObject::ptr parent_wxObject(        boost::dynamic_pointer_cast<WrapClass_wxObject >(this_ptr));
      parent_wxObject->AddMethods(parent_wxObject);
      // Add members from wxClientDataContainer
      WrapClass_wxClientDataContainer::ptr parent_wxClientDataContainer(        boost::dynamic_pointer_cast<WrapClass_wxClientDataContainer >(this_ptr));
      parent_wxClientDataContainer->AddMethods(parent_wxClientDataContainer);


  // check that the method name is not a token
  
      // Adding standard methods 
      AddVar_Add_1( this_ptr);
      AddVar_Add( this_ptr);
      AddVar_Add_2( this_ptr);
      AddVar_Add_3( this_ptr);
      AddVar_Add_4( this_ptr);
      AddVar_Add_5( this_ptr);
      AddVar_Add_6( this_ptr);
      AddVar_AddSpacer( this_ptr);
      AddVar_AddStretchSpacer( this_ptr);
      AddVar_Insert_1( this_ptr);
      AddVar_Insert( this_ptr);
      AddVar_Insert_2( this_ptr);
      AddVar_Insert_3( this_ptr);
      AddVar_Insert_4( this_ptr);
      AddVar_Insert_5( this_ptr);
      AddVar_Insert_6( this_ptr);
      AddVar_InsertSpacer( this_ptr);
      AddVar_InsertStretchSpacer( this_ptr);
      AddVar_Prepend_1( this_ptr);
      AddVar_Prepend( this_ptr);
      AddVar_Prepend_2( this_ptr);
      AddVar_Prepend_3( this_ptr);
      AddVar_Prepend_4( this_ptr);
      AddVar_Prepend_5( this_ptr);
      AddVar_Prepend_6( this_ptr);
      AddVar_PrependSpacer( this_ptr);
      AddVar_PrependStretchSpacer( this_ptr);
      AddVar_SetContainingWindow( this_ptr);
      AddVar_GetContainingWindow( this_ptr);
      AddVar_Remove_1( this_ptr);
      AddVar_Remove( this_ptr);
      AddVar_Remove_2( this_ptr);
      AddVar_Detach_1( this_ptr);
      AddVar_Detach( this_ptr);
      AddVar_Detach_2( this_ptr);
      AddVar_Detach_3( this_ptr);
      AddVar_Replace_1( this_ptr);
      AddVar_Replace( this_ptr);
      AddVar_Replace_2( this_ptr);
      AddVar_Replace_3( this_ptr);
      AddVar_Clear( this_ptr);
      AddVar_DeleteWindows( this_ptr);
      AddVar_SetMinSize_1( this_ptr);
      AddVar_SetMinSize( this_ptr);
      AddVar_SetMinSize_2( this_ptr);
      AddVar_SetItemMinSize_1( this_ptr);
      AddVar_SetItemMinSize( this_ptr);
      AddVar_SetItemMinSize_2( this_ptr);
      AddVar_SetItemMinSize_3( this_ptr);
      AddVar_SetItemMinSize_4( this_ptr);
      AddVar_SetItemMinSize_5( this_ptr);
      AddVar_SetItemMinSize_6( this_ptr);
      AddVar_GetSize( this_ptr);
      AddVar_GetPosition( this_ptr);
      AddVar_GetMinSize( this_ptr);
      AddVar_Layout( this_ptr);
      AddVar_ComputeFittingClientSize( this_ptr);
      AddVar_ComputeFittingWindowSize( this_ptr);
      AddVar_Fit( this_ptr);
      AddVar_FitInside( this_ptr);
      AddVar_SetSizeHints( this_ptr);
      AddVar_SetVirtualSizeHints( this_ptr);
      AddVar_GetChildren( this_ptr);
      AddVar_SetDimension( this_ptr);
      AddVar_GetItem_1( this_ptr);
      AddVar_GetItem( this_ptr);
      AddVar_GetItem_2( this_ptr);
      AddVar_GetItem_3( this_ptr);
      AddVar_Show_1( this_ptr);
      AddVar_Show( this_ptr);
      AddVar_Show_2( this_ptr);
      AddVar_Show_3( this_ptr);
      AddVar_Hide_1( this_ptr);
      AddVar_Hide( this_ptr);
      AddVar_Hide_2( this_ptr);
      AddVar_Hide_3( this_ptr);
      AddVar_IsShown_1( this_ptr);
      AddVar_IsShown( this_ptr);
      AddVar_IsShown_2( this_ptr);
      AddVar_IsShown_3( this_ptr);
      AddVar_ShowItems( this_ptr);
      AddVar_Show_4( this_ptr);
      AddVar_GetClassInfo( this_ptr);

      // Adding operators
      AddVar___assign__( this_ptr);



  
};

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of wxSizerItem * wxSizer::Add(wxWindow * window, int proportion = 0, int flag = 0, int border = 0, wxObject * userData = 0l)
//---------------------------------------------------
void WrapClass_wxSizer::
    wrap_Add_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'window'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'proportion' (def:0)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'flag' (def:0)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'border' (def:0)")
  ADDPARAMCOMMENT_TYPE( wxObject, "parameter named 'userData' (def:0l)")
  return_comments="returning a variable of type wxSizerItem";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizer::
    wrap_Add_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>5) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxWindow > window_smtptr;
  if (!get_val_smtptr_param<wxWindow >(window_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxWindow* window = window_smtptr.get();

  int proportion = 0;
  if (!get_val_param<int >(proportion,_p,_n)) ClassReturnEmptyVar;

  int flag = 0;
  if (!get_val_param<int >(flag,_p,_n)) ClassReturnEmptyVar;

  int border = 0;
  if (!get_val_param<int >(border,_p,_n)) ClassReturnEmptyVar;

  boost::shared_ptr<wxObject > userData_smtptr;
  if (!get_val_smtptr_param<wxObject >(userData_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxObject* userData = userData_smtptr.get();

  wxSizerItem * res =   this->_objectptr->GetObj()->Add(window, proportion, flag, border, userData);
  BasicVariable::ptr res_var = WrapClass_wxSizerItem::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxSizer::Add(...)
//---------------------------------------------------
void WrapClass_wxSizer::
    wrap_Add::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizer::
    wrap_Add::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxSizer::wrap_Add_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxSizer::wrap_Add_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxSizer::wrap_Add_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  WrapClass_wxSizer::wrap_Add_4 m4(this->_objectptr);
  res = m4.CallMember(_p);
  if (!m4.Get_arg_failure()) return res;
  WrapClass_wxSizer::wrap_Add_5 m5(this->_objectptr);
  res = m5.CallMember(_p);
  if (!m5.Get_arg_failure()) return res;
  WrapClass_wxSizer::wrap_Add_6 m6(this->_objectptr);
  res = m6.CallMember(_p);
  if (!m6.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxSizerItem * wxSizer::Add(wxSizer * sizer, int proportion = 0, int flag = 0, int border = 0, wxObject * userData = 0l)
//---------------------------------------------------
void WrapClass_wxSizer::
    wrap_Add_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxSizer, "parameter named 'sizer'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'proportion' (def:0)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'flag' (def:0)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'border' (def:0)")
  ADDPARAMCOMMENT_TYPE( wxObject, "parameter named 'userData' (def:0l)")
  return_comments="returning a variable of type wxSizerItem";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizer::
    wrap_Add_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>5) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxSizer > sizer_smtptr;
  if (!get_val_smtptr_param<wxSizer >(sizer_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxSizer* sizer = sizer_smtptr.get();

  int proportion = 0;
  if (!get_val_param<int >(proportion,_p,_n)) ClassReturnEmptyVar;

  int flag = 0;
  if (!get_val_param<int >(flag,_p,_n)) ClassReturnEmptyVar;

  int border = 0;
  if (!get_val_param<int >(border,_p,_n)) ClassReturnEmptyVar;

  boost::shared_ptr<wxObject > userData_smtptr;
  if (!get_val_smtptr_param<wxObject >(userData_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxObject* userData = userData_smtptr.get();

  wxSizerItem * res =   this->_objectptr->GetObj()->Add(sizer, proportion, flag, border, userData);
  BasicVariable::ptr res_var = WrapClass_wxSizerItem::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxSizerItem * wxSizer::Add(int width, int height, int proportion = 0, int flag = 0, int border = 0, wxObject * userData = 0l)
//---------------------------------------------------
void WrapClass_wxSizer::
    wrap_Add_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'width'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'height'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'proportion' (def:0)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'flag' (def:0)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'border' (def:0)")
  ADDPARAMCOMMENT_TYPE( wxObject, "parameter named 'userData' (def:0l)")
  return_comments="returning a variable of type wxSizerItem";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizer::
    wrap_Add_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>6) ClassReturnEmptyVar;
  int _n=0;

  int width;
  if (!get_val_param<int >(width,_p,_n)) ClassReturnEmptyVar;

  int height;
  if (!get_val_param<int >(height,_p,_n)) ClassReturnEmptyVar;

  int proportion = 0;
  if (!get_val_param<int >(proportion,_p,_n)) ClassReturnEmptyVar;

  int flag = 0;
  if (!get_val_param<int >(flag,_p,_n)) ClassReturnEmptyVar;

  int border = 0;
  if (!get_val_param<int >(border,_p,_n)) ClassReturnEmptyVar;

  boost::shared_ptr<wxObject > userData_smtptr;
  if (!get_val_smtptr_param<wxObject >(userData_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxObject* userData = userData_smtptr.get();

  wxSizerItem * res =   this->_objectptr->GetObj()->Add(width, height, proportion, flag, border, userData);
  BasicVariable::ptr res_var = WrapClass_wxSizerItem::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxSizerItem * wxSizer::Add(wxWindow * window, wxSizerFlags const & flags)
//---------------------------------------------------
void WrapClass_wxSizer::
    wrap_Add_4::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'window'")
  ADDPARAMCOMMENT_TYPE( wxSizerFlags, "parameter named 'flags'")
  return_comments="returning a variable of type wxSizerItem";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizer::
    wrap_Add_4::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxWindow > window_smtptr;
  if (!get_val_smtptr_param<wxWindow >(window_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxWindow* window = window_smtptr.get();

  boost::shared_ptr<wxSizerFlags > flags_smtptr;
  if (!get_val_smtptr_param<wxSizerFlags >(flags_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxSizerFlags const & flags = *flags_smtptr;

  wxSizerItem * res =   this->_objectptr->GetObj()->Add(window, flags);
  BasicVariable::ptr res_var = WrapClass_wxSizerItem::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxSizerItem * wxSizer::Add(wxSizer * sizer, wxSizerFlags const & flags)
//---------------------------------------------------
void WrapClass_wxSizer::
    wrap_Add_5::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxSizer, "parameter named 'sizer'")
  ADDPARAMCOMMENT_TYPE( wxSizerFlags, "parameter named 'flags'")
  return_comments="returning a variable of type wxSizerItem";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizer::
    wrap_Add_5::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxSizer > sizer_smtptr;
  if (!get_val_smtptr_param<wxSizer >(sizer_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxSizer* sizer = sizer_smtptr.get();

  boost::shared_ptr<wxSizerFlags > flags_smtptr;
  if (!get_val_smtptr_param<wxSizerFlags >(flags_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxSizerFlags const & flags = *flags_smtptr;

  wxSizerItem * res =   this->_objectptr->GetObj()->Add(sizer, flags);
  BasicVariable::ptr res_var = WrapClass_wxSizerItem::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxSizerItem * wxSizer::Add(wxSizerItem * item)
//---------------------------------------------------
void WrapClass_wxSizer::
    wrap_Add_6::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxSizerItem, "parameter named 'item'")
  return_comments="returning a variable of type wxSizerItem";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizer::
    wrap_Add_6::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxSizerItem > item_smtptr;
  if (!get_val_smtptr_param<wxSizerItem >(item_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxSizerItem* item = item_smtptr.get();

  wxSizerItem * res =   this->_objectptr->GetObj()->Add(item);
  BasicVariable::ptr res_var = WrapClass_wxSizerItem::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxSizerItem * wxSizer::AddSpacer(int size)
//---------------------------------------------------
void WrapClass_wxSizer::
    wrap_AddSpacer::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'size'")
  return_comments="returning a variable of type wxSizerItem";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizer::
    wrap_AddSpacer::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int size;
  if (!get_val_param<int >(size,_p,_n)) ClassHelpAndReturn;

  wxSizerItem * res =   this->_objectptr->GetObj()->AddSpacer(size);
  BasicVariable::ptr res_var = WrapClass_wxSizerItem::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxSizerItem * wxSizer::AddStretchSpacer(int prop = 1)
//---------------------------------------------------
void WrapClass_wxSizer::
    wrap_AddStretchSpacer::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'prop' (def:1)")
  return_comments="returning a variable of type wxSizerItem";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizer::
    wrap_AddStretchSpacer::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int prop = 1;
  if (!get_val_param<int >(prop,_p,_n)) ClassHelpAndReturn;

  wxSizerItem * res =   this->_objectptr->GetObj()->AddStretchSpacer(prop);
  BasicVariable::ptr res_var = WrapClass_wxSizerItem::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxSizerItem * wxSizer::Insert(size_t index, wxWindow * window, int proportion = 0, int flag = 0, int border = 0, wxObject * userData = 0l)
//---------------------------------------------------
void WrapClass_wxSizer::
    wrap_Insert_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'index'")
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'window'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'proportion' (def:0)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'flag' (def:0)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'border' (def:0)")
  ADDPARAMCOMMENT_TYPE( wxObject, "parameter named 'userData' (def:0l)")
  return_comments="returning a variable of type wxSizerItem";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizer::
    wrap_Insert_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>6) ClassReturnEmptyVar;
  int _n=0;

  long index_long;
  if (!get_val_param<long >(index_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int index = boost::numeric_cast<long unsigned int >(index_long);

  boost::shared_ptr<wxWindow > window_smtptr;
  if (!get_val_smtptr_param<wxWindow >(window_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxWindow* window = window_smtptr.get();

  int proportion = 0;
  if (!get_val_param<int >(proportion,_p,_n)) ClassReturnEmptyVar;

  int flag = 0;
  if (!get_val_param<int >(flag,_p,_n)) ClassReturnEmptyVar;

  int border = 0;
  if (!get_val_param<int >(border,_p,_n)) ClassReturnEmptyVar;

  boost::shared_ptr<wxObject > userData_smtptr;
  if (!get_val_smtptr_param<wxObject >(userData_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxObject* userData = userData_smtptr.get();

  wxSizerItem * res =   this->_objectptr->GetObj()->Insert(index, window, proportion, flag, border, userData);
  BasicVariable::ptr res_var = WrapClass_wxSizerItem::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxSizer::Insert(...)
//---------------------------------------------------
void WrapClass_wxSizer::
    wrap_Insert::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizer::
    wrap_Insert::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxSizer::wrap_Insert_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxSizer::wrap_Insert_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxSizer::wrap_Insert_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  WrapClass_wxSizer::wrap_Insert_4 m4(this->_objectptr);
  res = m4.CallMember(_p);
  if (!m4.Get_arg_failure()) return res;
  WrapClass_wxSizer::wrap_Insert_5 m5(this->_objectptr);
  res = m5.CallMember(_p);
  if (!m5.Get_arg_failure()) return res;
  WrapClass_wxSizer::wrap_Insert_6 m6(this->_objectptr);
  res = m6.CallMember(_p);
  if (!m6.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxSizerItem * wxSizer::Insert(size_t index, wxSizer * sizer, int proportion = 0, int flag = 0, int border = 0, wxObject * userData = 0l)
//---------------------------------------------------
void WrapClass_wxSizer::
    wrap_Insert_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'index'")
  ADDPARAMCOMMENT_TYPE( wxSizer, "parameter named 'sizer'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'proportion' (def:0)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'flag' (def:0)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'border' (def:0)")
  ADDPARAMCOMMENT_TYPE( wxObject, "parameter named 'userData' (def:0l)")
  return_comments="returning a variable of type wxSizerItem";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizer::
    wrap_Insert_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>6) ClassReturnEmptyVar;
  int _n=0;

  long index_long;
  if (!get_val_param<long >(index_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int index = boost::numeric_cast<long unsigned int >(index_long);

  boost::shared_ptr<wxSizer > sizer_smtptr;
  if (!get_val_smtptr_param<wxSizer >(sizer_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxSizer* sizer = sizer_smtptr.get();

  int proportion = 0;
  if (!get_val_param<int >(proportion,_p,_n)) ClassReturnEmptyVar;

  int flag = 0;
  if (!get_val_param<int >(flag,_p,_n)) ClassReturnEmptyVar;

  int border = 0;
  if (!get_val_param<int >(border,_p,_n)) ClassReturnEmptyVar;

  boost::shared_ptr<wxObject > userData_smtptr;
  if (!get_val_smtptr_param<wxObject >(userData_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxObject* userData = userData_smtptr.get();

  wxSizerItem * res =   this->_objectptr->GetObj()->Insert(index, sizer, proportion, flag, border, userData);
  BasicVariable::ptr res_var = WrapClass_wxSizerItem::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxSizerItem * wxSizer::Insert(size_t index, int width, int height, int proportion = 0, int flag = 0, int border = 0, wxObject * userData = 0l)
//---------------------------------------------------
void WrapClass_wxSizer::
    wrap_Insert_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'index'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'width'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'height'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'proportion' (def:0)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'flag' (def:0)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'border' (def:0)")
  ADDPARAMCOMMENT_TYPE( wxObject, "parameter named 'userData' (def:0l)")
  return_comments="returning a variable of type wxSizerItem";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizer::
    wrap_Insert_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>7) ClassReturnEmptyVar;
  int _n=0;

  long index_long;
  if (!get_val_param<long >(index_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int index = boost::numeric_cast<long unsigned int >(index_long);

  int width;
  if (!get_val_param<int >(width,_p,_n)) ClassReturnEmptyVar;

  int height;
  if (!get_val_param<int >(height,_p,_n)) ClassReturnEmptyVar;

  int proportion = 0;
  if (!get_val_param<int >(proportion,_p,_n)) ClassReturnEmptyVar;

  int flag = 0;
  if (!get_val_param<int >(flag,_p,_n)) ClassReturnEmptyVar;

  int border = 0;
  if (!get_val_param<int >(border,_p,_n)) ClassReturnEmptyVar;

  boost::shared_ptr<wxObject > userData_smtptr;
  if (!get_val_smtptr_param<wxObject >(userData_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxObject* userData = userData_smtptr.get();

  wxSizerItem * res =   this->_objectptr->GetObj()->Insert(index, width, height, proportion, flag, border, userData);
  BasicVariable::ptr res_var = WrapClass_wxSizerItem::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxSizerItem * wxSizer::Insert(size_t index, wxWindow * window, wxSizerFlags const & flags)
//---------------------------------------------------
void WrapClass_wxSizer::
    wrap_Insert_4::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'index'")
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'window'")
  ADDPARAMCOMMENT_TYPE( wxSizerFlags, "parameter named 'flags'")
  return_comments="returning a variable of type wxSizerItem";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizer::
    wrap_Insert_4::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  long index_long;
  if (!get_val_param<long >(index_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int index = boost::numeric_cast<long unsigned int >(index_long);

  boost::shared_ptr<wxWindow > window_smtptr;
  if (!get_val_smtptr_param<wxWindow >(window_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxWindow* window = window_smtptr.get();

  boost::shared_ptr<wxSizerFlags > flags_smtptr;
  if (!get_val_smtptr_param<wxSizerFlags >(flags_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxSizerFlags const & flags = *flags_smtptr;

  wxSizerItem * res =   this->_objectptr->GetObj()->Insert(index, window, flags);
  BasicVariable::ptr res_var = WrapClass_wxSizerItem::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxSizerItem * wxSizer::Insert(size_t index, wxSizer * sizer, wxSizerFlags const & flags)
//---------------------------------------------------
void WrapClass_wxSizer::
    wrap_Insert_5::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'index'")
  ADDPARAMCOMMENT_TYPE( wxSizer, "parameter named 'sizer'")
  ADDPARAMCOMMENT_TYPE( wxSizerFlags, "parameter named 'flags'")
  return_comments="returning a variable of type wxSizerItem";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizer::
    wrap_Insert_5::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  long index_long;
  if (!get_val_param<long >(index_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int index = boost::numeric_cast<long unsigned int >(index_long);

  boost::shared_ptr<wxSizer > sizer_smtptr;
  if (!get_val_smtptr_param<wxSizer >(sizer_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxSizer* sizer = sizer_smtptr.get();

  boost::shared_ptr<wxSizerFlags > flags_smtptr;
  if (!get_val_smtptr_param<wxSizerFlags >(flags_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxSizerFlags const & flags = *flags_smtptr;

  wxSizerItem * res =   this->_objectptr->GetObj()->Insert(index, sizer, flags);
  BasicVariable::ptr res_var = WrapClass_wxSizerItem::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxSizerItem * wxSizer::Insert(size_t index, wxSizerItem * item)
//---------------------------------------------------
void WrapClass_wxSizer::
    wrap_Insert_6::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'index'")
  ADDPARAMCOMMENT_TYPE( wxSizerItem, "parameter named 'item'")
  return_comments="returning a variable of type wxSizerItem";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizer::
    wrap_Insert_6::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  long index_long;
  if (!get_val_param<long >(index_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int index = boost::numeric_cast<long unsigned int >(index_long);

  boost::shared_ptr<wxSizerItem > item_smtptr;
  if (!get_val_smtptr_param<wxSizerItem >(item_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxSizerItem* item = item_smtptr.get();

  wxSizerItem * res =   this->_objectptr->GetObj()->Insert(index, item);
  BasicVariable::ptr res_var = WrapClass_wxSizerItem::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxSizerItem * wxSizer::InsertSpacer(size_t index, int size)
//---------------------------------------------------
void WrapClass_wxSizer::
    wrap_InsertSpacer::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'index'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'size'")
  return_comments="returning a variable of type wxSizerItem";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizer::
    wrap_InsertSpacer::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  long index_long;
  if (!get_val_param<long >(index_long,_p,_n)) ClassHelpAndReturn;
  long unsigned int index = boost::numeric_cast<long unsigned int >(index_long);

  int size;
  if (!get_val_param<int >(size,_p,_n)) ClassHelpAndReturn;

  wxSizerItem * res =   this->_objectptr->GetObj()->InsertSpacer(index, size);
  BasicVariable::ptr res_var = WrapClass_wxSizerItem::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxSizerItem * wxSizer::InsertStretchSpacer(size_t index, int prop = 1)
//---------------------------------------------------
void WrapClass_wxSizer::
    wrap_InsertStretchSpacer::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'index'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'prop' (def:1)")
  return_comments="returning a variable of type wxSizerItem";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizer::
    wrap_InsertStretchSpacer::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  long index_long;
  if (!get_val_param<long >(index_long,_p,_n)) ClassHelpAndReturn;
  long unsigned int index = boost::numeric_cast<long unsigned int >(index_long);

  int prop = 1;
  if (!get_val_param<int >(prop,_p,_n)) ClassHelpAndReturn;

  wxSizerItem * res =   this->_objectptr->GetObj()->InsertStretchSpacer(index, prop);
  BasicVariable::ptr res_var = WrapClass_wxSizerItem::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxSizerItem * wxSizer::Prepend(wxWindow * window, int proportion = 0, int flag = 0, int border = 0, wxObject * userData = 0l)
//---------------------------------------------------
void WrapClass_wxSizer::
    wrap_Prepend_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'window'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'proportion' (def:0)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'flag' (def:0)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'border' (def:0)")
  ADDPARAMCOMMENT_TYPE( wxObject, "parameter named 'userData' (def:0l)")
  return_comments="returning a variable of type wxSizerItem";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizer::
    wrap_Prepend_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>5) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxWindow > window_smtptr;
  if (!get_val_smtptr_param<wxWindow >(window_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxWindow* window = window_smtptr.get();

  int proportion = 0;
  if (!get_val_param<int >(proportion,_p,_n)) ClassReturnEmptyVar;

  int flag = 0;
  if (!get_val_param<int >(flag,_p,_n)) ClassReturnEmptyVar;

  int border = 0;
  if (!get_val_param<int >(border,_p,_n)) ClassReturnEmptyVar;

  boost::shared_ptr<wxObject > userData_smtptr;
  if (!get_val_smtptr_param<wxObject >(userData_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxObject* userData = userData_smtptr.get();

  wxSizerItem * res =   this->_objectptr->GetObj()->Prepend(window, proportion, flag, border, userData);
  BasicVariable::ptr res_var = WrapClass_wxSizerItem::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxSizer::Prepend(...)
//---------------------------------------------------
void WrapClass_wxSizer::
    wrap_Prepend::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizer::
    wrap_Prepend::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxSizer::wrap_Prepend_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxSizer::wrap_Prepend_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxSizer::wrap_Prepend_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  WrapClass_wxSizer::wrap_Prepend_4 m4(this->_objectptr);
  res = m4.CallMember(_p);
  if (!m4.Get_arg_failure()) return res;
  WrapClass_wxSizer::wrap_Prepend_5 m5(this->_objectptr);
  res = m5.CallMember(_p);
  if (!m5.Get_arg_failure()) return res;
  WrapClass_wxSizer::wrap_Prepend_6 m6(this->_objectptr);
  res = m6.CallMember(_p);
  if (!m6.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxSizerItem * wxSizer::Prepend(wxSizer * sizer, int proportion = 0, int flag = 0, int border = 0, wxObject * userData = 0l)
//---------------------------------------------------
void WrapClass_wxSizer::
    wrap_Prepend_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxSizer, "parameter named 'sizer'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'proportion' (def:0)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'flag' (def:0)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'border' (def:0)")
  ADDPARAMCOMMENT_TYPE( wxObject, "parameter named 'userData' (def:0l)")
  return_comments="returning a variable of type wxSizerItem";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizer::
    wrap_Prepend_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>5) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxSizer > sizer_smtptr;
  if (!get_val_smtptr_param<wxSizer >(sizer_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxSizer* sizer = sizer_smtptr.get();

  int proportion = 0;
  if (!get_val_param<int >(proportion,_p,_n)) ClassReturnEmptyVar;

  int flag = 0;
  if (!get_val_param<int >(flag,_p,_n)) ClassReturnEmptyVar;

  int border = 0;
  if (!get_val_param<int >(border,_p,_n)) ClassReturnEmptyVar;

  boost::shared_ptr<wxObject > userData_smtptr;
  if (!get_val_smtptr_param<wxObject >(userData_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxObject* userData = userData_smtptr.get();

  wxSizerItem * res =   this->_objectptr->GetObj()->Prepend(sizer, proportion, flag, border, userData);
  BasicVariable::ptr res_var = WrapClass_wxSizerItem::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxSizerItem * wxSizer::Prepend(int width, int height, int proportion = 0, int flag = 0, int border = 0, wxObject * userData = 0l)
//---------------------------------------------------
void WrapClass_wxSizer::
    wrap_Prepend_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'width'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'height'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'proportion' (def:0)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'flag' (def:0)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'border' (def:0)")
  ADDPARAMCOMMENT_TYPE( wxObject, "parameter named 'userData' (def:0l)")
  return_comments="returning a variable of type wxSizerItem";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizer::
    wrap_Prepend_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>6) ClassReturnEmptyVar;
  int _n=0;

  int width;
  if (!get_val_param<int >(width,_p,_n)) ClassReturnEmptyVar;

  int height;
  if (!get_val_param<int >(height,_p,_n)) ClassReturnEmptyVar;

  int proportion = 0;
  if (!get_val_param<int >(proportion,_p,_n)) ClassReturnEmptyVar;

  int flag = 0;
  if (!get_val_param<int >(flag,_p,_n)) ClassReturnEmptyVar;

  int border = 0;
  if (!get_val_param<int >(border,_p,_n)) ClassReturnEmptyVar;

  boost::shared_ptr<wxObject > userData_smtptr;
  if (!get_val_smtptr_param<wxObject >(userData_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxObject* userData = userData_smtptr.get();

  wxSizerItem * res =   this->_objectptr->GetObj()->Prepend(width, height, proportion, flag, border, userData);
  BasicVariable::ptr res_var = WrapClass_wxSizerItem::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxSizerItem * wxSizer::Prepend(wxWindow * window, wxSizerFlags const & flags)
//---------------------------------------------------
void WrapClass_wxSizer::
    wrap_Prepend_4::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'window'")
  ADDPARAMCOMMENT_TYPE( wxSizerFlags, "parameter named 'flags'")
  return_comments="returning a variable of type wxSizerItem";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizer::
    wrap_Prepend_4::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxWindow > window_smtptr;
  if (!get_val_smtptr_param<wxWindow >(window_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxWindow* window = window_smtptr.get();

  boost::shared_ptr<wxSizerFlags > flags_smtptr;
  if (!get_val_smtptr_param<wxSizerFlags >(flags_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxSizerFlags const & flags = *flags_smtptr;

  wxSizerItem * res =   this->_objectptr->GetObj()->Prepend(window, flags);
  BasicVariable::ptr res_var = WrapClass_wxSizerItem::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxSizerItem * wxSizer::Prepend(wxSizer * sizer, wxSizerFlags const & flags)
//---------------------------------------------------
void WrapClass_wxSizer::
    wrap_Prepend_5::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxSizer, "parameter named 'sizer'")
  ADDPARAMCOMMENT_TYPE( wxSizerFlags, "parameter named 'flags'")
  return_comments="returning a variable of type wxSizerItem";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizer::
    wrap_Prepend_5::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxSizer > sizer_smtptr;
  if (!get_val_smtptr_param<wxSizer >(sizer_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxSizer* sizer = sizer_smtptr.get();

  boost::shared_ptr<wxSizerFlags > flags_smtptr;
  if (!get_val_smtptr_param<wxSizerFlags >(flags_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxSizerFlags const & flags = *flags_smtptr;

  wxSizerItem * res =   this->_objectptr->GetObj()->Prepend(sizer, flags);
  BasicVariable::ptr res_var = WrapClass_wxSizerItem::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxSizerItem * wxSizer::Prepend(wxSizerItem * item)
//---------------------------------------------------
void WrapClass_wxSizer::
    wrap_Prepend_6::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxSizerItem, "parameter named 'item'")
  return_comments="returning a variable of type wxSizerItem";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizer::
    wrap_Prepend_6::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxSizerItem > item_smtptr;
  if (!get_val_smtptr_param<wxSizerItem >(item_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxSizerItem* item = item_smtptr.get();

  wxSizerItem * res =   this->_objectptr->GetObj()->Prepend(item);
  BasicVariable::ptr res_var = WrapClass_wxSizerItem::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxSizerItem * wxSizer::PrependSpacer(int size)
//---------------------------------------------------
void WrapClass_wxSizer::
    wrap_PrependSpacer::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'size'")
  return_comments="returning a variable of type wxSizerItem";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizer::
    wrap_PrependSpacer::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int size;
  if (!get_val_param<int >(size,_p,_n)) ClassHelpAndReturn;

  wxSizerItem * res =   this->_objectptr->GetObj()->PrependSpacer(size);
  BasicVariable::ptr res_var = WrapClass_wxSizerItem::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxSizerItem * wxSizer::PrependStretchSpacer(int prop = 1)
//---------------------------------------------------
void WrapClass_wxSizer::
    wrap_PrependStretchSpacer::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'prop' (def:1)")
  return_comments="returning a variable of type wxSizerItem";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizer::
    wrap_PrependStretchSpacer::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int prop = 1;
  if (!get_val_param<int >(prop,_p,_n)) ClassHelpAndReturn;

  wxSizerItem * res =   this->_objectptr->GetObj()->PrependStretchSpacer(prop);
  BasicVariable::ptr res_var = WrapClass_wxSizerItem::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of void wxSizer::SetContainingWindow(wxWindow * window)
//---------------------------------------------------
void WrapClass_wxSizer::
    wrap_SetContainingWindow::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'window'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizer::
    wrap_SetContainingWindow::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxWindow > window_smtptr;
  if (!get_val_smtptr_param<wxWindow >(window_smtptr,_p,_n)) ClassHelpAndReturn;
  wxWindow* window = window_smtptr.get();

  this->_objectptr->GetObj()->SetContainingWindow(window);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxWindow * wxSizer::GetContainingWindow()
//---------------------------------------------------
void WrapClass_wxSizer::
    wrap_GetContainingWindow::SetParametersComments()
{
  return_comments="returning a variable of type wxWindow";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizer::
    wrap_GetContainingWindow::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxWindow * res =   this->_objectptr->GetObj()->GetContainingWindow();
  BasicVariable::ptr res_var = WrapClass_wxWindow::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of bool wxSizer::Remove(wxSizer * sizer)
//---------------------------------------------------
void WrapClass_wxSizer::
    wrap_Remove_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxSizer, "parameter named 'sizer'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizer::
    wrap_Remove_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxSizer > sizer_smtptr;
  if (!get_val_smtptr_param<wxSizer >(sizer_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxSizer* sizer = sizer_smtptr.get();

  bool res =   this->_objectptr->GetObj()->Remove(sizer);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxSizer::Remove(...)
//---------------------------------------------------
void WrapClass_wxSizer::
    wrap_Remove::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizer::
    wrap_Remove::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxSizer::wrap_Remove_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxSizer::wrap_Remove_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of bool wxSizer::Remove(int index)
//---------------------------------------------------
void WrapClass_wxSizer::
    wrap_Remove_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'index'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizer::
    wrap_Remove_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  int index;
  if (!get_val_param<int >(index,_p,_n)) ClassReturnEmptyVar;

  bool res =   this->_objectptr->GetObj()->Remove(index);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxSizer::Detach(wxWindow * window)
//---------------------------------------------------
void WrapClass_wxSizer::
    wrap_Detach_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'window'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizer::
    wrap_Detach_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxWindow > window_smtptr;
  if (!get_val_smtptr_param<wxWindow >(window_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxWindow* window = window_smtptr.get();

  bool res =   this->_objectptr->GetObj()->Detach(window);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxSizer::Detach(...)
//---------------------------------------------------
void WrapClass_wxSizer::
    wrap_Detach::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizer::
    wrap_Detach::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxSizer::wrap_Detach_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxSizer::wrap_Detach_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxSizer::wrap_Detach_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of bool wxSizer::Detach(wxSizer * sizer)
//---------------------------------------------------
void WrapClass_wxSizer::
    wrap_Detach_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxSizer, "parameter named 'sizer'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizer::
    wrap_Detach_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxSizer > sizer_smtptr;
  if (!get_val_smtptr_param<wxSizer >(sizer_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxSizer* sizer = sizer_smtptr.get();

  bool res =   this->_objectptr->GetObj()->Detach(sizer);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxSizer::Detach(int index)
//---------------------------------------------------
void WrapClass_wxSizer::
    wrap_Detach_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'index'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizer::
    wrap_Detach_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  int index;
  if (!get_val_param<int >(index,_p,_n)) ClassReturnEmptyVar;

  bool res =   this->_objectptr->GetObj()->Detach(index);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxSizer::Replace(wxWindow * oldwin, wxWindow * newwin, bool recursive = false)
//---------------------------------------------------
void WrapClass_wxSizer::
    wrap_Replace_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'oldwin'")
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'newwin'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'recursive' (def:false)")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizer::
    wrap_Replace_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxWindow > oldwin_smtptr;
  if (!get_val_smtptr_param<wxWindow >(oldwin_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxWindow* oldwin = oldwin_smtptr.get();

  boost::shared_ptr<wxWindow > newwin_smtptr;
  if (!get_val_smtptr_param<wxWindow >(newwin_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxWindow* newwin = newwin_smtptr.get();

  int recursive_int = ((false==true)?1:0);;
  if (!get_val_param<int >(recursive_int,_p,_n)) ClassReturnEmptyVar;
  bool recursive = (bool) (recursive_int>0.5);

  bool res =   this->_objectptr->GetObj()->Replace(oldwin, newwin, recursive);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxSizer::Replace(...)
//---------------------------------------------------
void WrapClass_wxSizer::
    wrap_Replace::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizer::
    wrap_Replace::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxSizer::wrap_Replace_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxSizer::wrap_Replace_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxSizer::wrap_Replace_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of bool wxSizer::Replace(wxSizer * oldsz, wxSizer * newsz, bool recursive = false)
//---------------------------------------------------
void WrapClass_wxSizer::
    wrap_Replace_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxSizer, "parameter named 'oldsz'")
  ADDPARAMCOMMENT_TYPE( wxSizer, "parameter named 'newsz'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'recursive' (def:false)")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizer::
    wrap_Replace_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxSizer > oldsz_smtptr;
  if (!get_val_smtptr_param<wxSizer >(oldsz_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxSizer* oldsz = oldsz_smtptr.get();

  boost::shared_ptr<wxSizer > newsz_smtptr;
  if (!get_val_smtptr_param<wxSizer >(newsz_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxSizer* newsz = newsz_smtptr.get();

  int recursive_int = ((false==true)?1:0);;
  if (!get_val_param<int >(recursive_int,_p,_n)) ClassReturnEmptyVar;
  bool recursive = (bool) (recursive_int>0.5);

  bool res =   this->_objectptr->GetObj()->Replace(oldsz, newsz, recursive);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxSizer::Replace(size_t index, wxSizerItem * newitem)
//---------------------------------------------------
void WrapClass_wxSizer::
    wrap_Replace_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'index'")
  ADDPARAMCOMMENT_TYPE( wxSizerItem, "parameter named 'newitem'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizer::
    wrap_Replace_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  long index_long;
  if (!get_val_param<long >(index_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int index = boost::numeric_cast<long unsigned int >(index_long);

  boost::shared_ptr<wxSizerItem > newitem_smtptr;
  if (!get_val_smtptr_param<wxSizerItem >(newitem_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxSizerItem* newitem = newitem_smtptr.get();

  bool res =   this->_objectptr->GetObj()->Replace(index, newitem);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of void wxSizer::Clear(bool delete_windows = false)
//---------------------------------------------------
void WrapClass_wxSizer::
    wrap_Clear::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'delete_windows' (def:false)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizer::
    wrap_Clear::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int delete_windows_int = ((false==true)?1:0);;
  if (!get_val_param<int >(delete_windows_int,_p,_n)) ClassHelpAndReturn;
  bool delete_windows = (bool) (delete_windows_int>0.5);

  this->_objectptr->GetObj()->Clear(delete_windows);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxSizer::DeleteWindows()
//---------------------------------------------------
void WrapClass_wxSizer::
    wrap_DeleteWindows::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizer::
    wrap_DeleteWindows::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->DeleteWindows();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxSizer::SetMinSize(int width, int height)
//---------------------------------------------------
void WrapClass_wxSizer::
    wrap_SetMinSize_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'width'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'height'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizer::
    wrap_SetMinSize_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  int width;
  if (!get_val_param<int >(width,_p,_n)) ClassReturnEmptyVar;

  int height;
  if (!get_val_param<int >(height,_p,_n)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->SetMinSize(width, height);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxSizer::SetMinSize(...)
//---------------------------------------------------
void WrapClass_wxSizer::
    wrap_SetMinSize::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizer::
    wrap_SetMinSize::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxSizer::wrap_SetMinSize_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxSizer::wrap_SetMinSize_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void wxSizer::SetMinSize(wxSize const & size)
//---------------------------------------------------
void WrapClass_wxSizer::
    wrap_SetMinSize_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 'size'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizer::
    wrap_SetMinSize_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxSize > size_smtptr;
  if (!get_val_smtptr_param<wxSize >(size_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxSize const & size = *size_smtptr;

  this->_objectptr->GetObj()->SetMinSize(size);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxSizer::SetItemMinSize(wxWindow * window, int width, int height)
//---------------------------------------------------
void WrapClass_wxSizer::
    wrap_SetItemMinSize_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'window'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'width'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'height'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizer::
    wrap_SetItemMinSize_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxWindow > window_smtptr;
  if (!get_val_smtptr_param<wxWindow >(window_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxWindow* window = window_smtptr.get();

  int width;
  if (!get_val_param<int >(width,_p,_n)) ClassReturnEmptyVar;

  int height;
  if (!get_val_param<int >(height,_p,_n)) ClassReturnEmptyVar;

  bool res =   this->_objectptr->GetObj()->SetItemMinSize(window, width, height);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxSizer::SetItemMinSize(...)
//---------------------------------------------------
void WrapClass_wxSizer::
    wrap_SetItemMinSize::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizer::
    wrap_SetItemMinSize::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxSizer::wrap_SetItemMinSize_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxSizer::wrap_SetItemMinSize_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxSizer::wrap_SetItemMinSize_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  WrapClass_wxSizer::wrap_SetItemMinSize_4 m4(this->_objectptr);
  res = m4.CallMember(_p);
  if (!m4.Get_arg_failure()) return res;
  WrapClass_wxSizer::wrap_SetItemMinSize_5 m5(this->_objectptr);
  res = m5.CallMember(_p);
  if (!m5.Get_arg_failure()) return res;
  WrapClass_wxSizer::wrap_SetItemMinSize_6 m6(this->_objectptr);
  res = m6.CallMember(_p);
  if (!m6.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of bool wxSizer::SetItemMinSize(wxWindow * window, wxSize const & size)
//---------------------------------------------------
void WrapClass_wxSizer::
    wrap_SetItemMinSize_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'window'")
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 'size'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizer::
    wrap_SetItemMinSize_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxWindow > window_smtptr;
  if (!get_val_smtptr_param<wxWindow >(window_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxWindow* window = window_smtptr.get();

  boost::shared_ptr<wxSize > size_smtptr;
  if (!get_val_smtptr_param<wxSize >(size_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxSize const & size = *size_smtptr;

  bool res =   this->_objectptr->GetObj()->SetItemMinSize(window, size);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxSizer::SetItemMinSize(wxSizer * sizer, int width, int height)
//---------------------------------------------------
void WrapClass_wxSizer::
    wrap_SetItemMinSize_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxSizer, "parameter named 'sizer'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'width'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'height'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizer::
    wrap_SetItemMinSize_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxSizer > sizer_smtptr;
  if (!get_val_smtptr_param<wxSizer >(sizer_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxSizer* sizer = sizer_smtptr.get();

  int width;
  if (!get_val_param<int >(width,_p,_n)) ClassReturnEmptyVar;

  int height;
  if (!get_val_param<int >(height,_p,_n)) ClassReturnEmptyVar;

  bool res =   this->_objectptr->GetObj()->SetItemMinSize(sizer, width, height);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxSizer::SetItemMinSize(wxSizer * sizer, wxSize const & size)
//---------------------------------------------------
void WrapClass_wxSizer::
    wrap_SetItemMinSize_4::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxSizer, "parameter named 'sizer'")
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 'size'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizer::
    wrap_SetItemMinSize_4::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxSizer > sizer_smtptr;
  if (!get_val_smtptr_param<wxSizer >(sizer_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxSizer* sizer = sizer_smtptr.get();

  boost::shared_ptr<wxSize > size_smtptr;
  if (!get_val_smtptr_param<wxSize >(size_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxSize const & size = *size_smtptr;

  bool res =   this->_objectptr->GetObj()->SetItemMinSize(sizer, size);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxSizer::SetItemMinSize(size_t index, int width, int height)
//---------------------------------------------------
void WrapClass_wxSizer::
    wrap_SetItemMinSize_5::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'index'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'width'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'height'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizer::
    wrap_SetItemMinSize_5::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  long index_long;
  if (!get_val_param<long >(index_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int index = boost::numeric_cast<long unsigned int >(index_long);

  int width;
  if (!get_val_param<int >(width,_p,_n)) ClassReturnEmptyVar;

  int height;
  if (!get_val_param<int >(height,_p,_n)) ClassReturnEmptyVar;

  bool res =   this->_objectptr->GetObj()->SetItemMinSize(index, width, height);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxSizer::SetItemMinSize(size_t index, wxSize const & size)
//---------------------------------------------------
void WrapClass_wxSizer::
    wrap_SetItemMinSize_6::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'index'")
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 'size'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizer::
    wrap_SetItemMinSize_6::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  long index_long;
  if (!get_val_param<long >(index_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int index = boost::numeric_cast<long unsigned int >(index_long);

  boost::shared_ptr<wxSize > size_smtptr;
  if (!get_val_smtptr_param<wxSize >(size_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxSize const & size = *size_smtptr;

  bool res =   this->_objectptr->GetObj()->SetItemMinSize(index, size);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of wxSize wxSizer::GetSize()
//---------------------------------------------------
void WrapClass_wxSizer::
    wrap_GetSize::SetParametersComments()
{
  return_comments="returning a variable of type wxSize";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizer::
    wrap_GetSize::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxSize res =   this->_objectptr->GetObj()->GetSize();
  return AMILabType<wxSize >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxPoint wxSizer::GetPosition()
//---------------------------------------------------
void WrapClass_wxSizer::
    wrap_GetPosition::SetParametersComments()
{
  return_comments="returning a variable of type wxPoint";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizer::
    wrap_GetPosition::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxPoint res =   this->_objectptr->GetObj()->GetPosition();
  return AMILabType<wxPoint >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxSize wxSizer::GetMinSize()
//---------------------------------------------------
void WrapClass_wxSizer::
    wrap_GetMinSize::SetParametersComments()
{
  return_comments="returning a variable of type wxSize";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizer::
    wrap_GetMinSize::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxSize res =   this->_objectptr->GetObj()->GetMinSize();
  return AMILabType<wxSize >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxSizer::Layout()
//---------------------------------------------------
void WrapClass_wxSizer::
    wrap_Layout::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizer::
    wrap_Layout::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Layout();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxSize wxSizer::ComputeFittingClientSize(wxWindow * window)
//---------------------------------------------------
void WrapClass_wxSizer::
    wrap_ComputeFittingClientSize::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'window'")
  return_comments="returning a variable of type wxSize";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizer::
    wrap_ComputeFittingClientSize::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxWindow > window_smtptr;
  if (!get_val_smtptr_param<wxWindow >(window_smtptr,_p,_n)) ClassHelpAndReturn;
  wxWindow* window = window_smtptr.get();

  wxSize res =   this->_objectptr->GetObj()->ComputeFittingClientSize(window);
  return AMILabType<wxSize >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxSize wxSizer::ComputeFittingWindowSize(wxWindow * window)
//---------------------------------------------------
void WrapClass_wxSizer::
    wrap_ComputeFittingWindowSize::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'window'")
  return_comments="returning a variable of type wxSize";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizer::
    wrap_ComputeFittingWindowSize::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxWindow > window_smtptr;
  if (!get_val_smtptr_param<wxWindow >(window_smtptr,_p,_n)) ClassHelpAndReturn;
  wxWindow* window = window_smtptr.get();

  wxSize res =   this->_objectptr->GetObj()->ComputeFittingWindowSize(window);
  return AMILabType<wxSize >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxSize wxSizer::Fit(wxWindow * window)
//---------------------------------------------------
void WrapClass_wxSizer::
    wrap_Fit::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'window'")
  return_comments="returning a variable of type wxSize";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizer::
    wrap_Fit::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxWindow > window_smtptr;
  if (!get_val_smtptr_param<wxWindow >(window_smtptr,_p,_n)) ClassHelpAndReturn;
  wxWindow* window = window_smtptr.get();

  wxSize res =   this->_objectptr->GetObj()->Fit(window);
  return AMILabType<wxSize >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxSizer::FitInside(wxWindow * window)
//---------------------------------------------------
void WrapClass_wxSizer::
    wrap_FitInside::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'window'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizer::
    wrap_FitInside::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxWindow > window_smtptr;
  if (!get_val_smtptr_param<wxWindow >(window_smtptr,_p,_n)) ClassHelpAndReturn;
  wxWindow* window = window_smtptr.get();

  this->_objectptr->GetObj()->FitInside(window);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxSizer::SetSizeHints(wxWindow * window)
//---------------------------------------------------
void WrapClass_wxSizer::
    wrap_SetSizeHints::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'window'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizer::
    wrap_SetSizeHints::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxWindow > window_smtptr;
  if (!get_val_smtptr_param<wxWindow >(window_smtptr,_p,_n)) ClassHelpAndReturn;
  wxWindow* window = window_smtptr.get();

  this->_objectptr->GetObj()->SetSizeHints(window);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxSizer::SetVirtualSizeHints(wxWindow * window)
//---------------------------------------------------
void WrapClass_wxSizer::
    wrap_SetVirtualSizeHints::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'window'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizer::
    wrap_SetVirtualSizeHints::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxWindow > window_smtptr;
  if (!get_val_smtptr_param<wxWindow >(window_smtptr,_p,_n)) ClassHelpAndReturn;
  wxWindow* window = window_smtptr.get();

  this->_objectptr->GetObj()->SetVirtualSizeHints(window);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxSizerItemList & wxSizer::GetChildren()
//---------------------------------------------------
void WrapClass_wxSizer::
    wrap_GetChildren::SetParametersComments()
{
  return_comments="returning a variable of type wxSizerItemList";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizer::
    wrap_GetChildren::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxSizerItemList & res =   this->_objectptr->GetObj()->GetChildren();
  return AMILabType<wxSizerItemList >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxSizer::SetDimension(int x, int y, int width, int height)
//---------------------------------------------------
void WrapClass_wxSizer::
    wrap_SetDimension::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'width'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'height'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizer::
    wrap_SetDimension::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>4) ClassHelpAndReturn;
  int _n=0;

  int x;
  if (!get_val_param<int >(x,_p,_n)) ClassHelpAndReturn;

  int y;
  if (!get_val_param<int >(y,_p,_n)) ClassHelpAndReturn;

  int width;
  if (!get_val_param<int >(width,_p,_n)) ClassHelpAndReturn;

  int height;
  if (!get_val_param<int >(height,_p,_n)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetDimension(x, y, width, height);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxSizerItem * wxSizer::GetItem(wxWindow * window, bool recursive = false)
//---------------------------------------------------
void WrapClass_wxSizer::
    wrap_GetItem_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'window'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'recursive' (def:false)")
  return_comments="returning a variable of type wxSizerItem";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizer::
    wrap_GetItem_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxWindow > window_smtptr;
  if (!get_val_smtptr_param<wxWindow >(window_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxWindow* window = window_smtptr.get();

  int recursive_int = ((false==true)?1:0);;
  if (!get_val_param<int >(recursive_int,_p,_n)) ClassReturnEmptyVar;
  bool recursive = (bool) (recursive_int>0.5);

  wxSizerItem * res =   this->_objectptr->GetObj()->GetItem(window, recursive);
  BasicVariable::ptr res_var = WrapClass_wxSizerItem::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxSizer::GetItem(...)
//---------------------------------------------------
void WrapClass_wxSizer::
    wrap_GetItem::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizer::
    wrap_GetItem::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxSizer::wrap_GetItem_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxSizer::wrap_GetItem_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxSizer::wrap_GetItem_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxSizerItem * wxSizer::GetItem(wxSizer * sizer, bool recursive = false)
//---------------------------------------------------
void WrapClass_wxSizer::
    wrap_GetItem_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxSizer, "parameter named 'sizer'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'recursive' (def:false)")
  return_comments="returning a variable of type wxSizerItem";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizer::
    wrap_GetItem_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxSizer > sizer_smtptr;
  if (!get_val_smtptr_param<wxSizer >(sizer_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxSizer* sizer = sizer_smtptr.get();

  int recursive_int = ((false==true)?1:0);;
  if (!get_val_param<int >(recursive_int,_p,_n)) ClassReturnEmptyVar;
  bool recursive = (bool) (recursive_int>0.5);

  wxSizerItem * res =   this->_objectptr->GetObj()->GetItem(sizer, recursive);
  BasicVariable::ptr res_var = WrapClass_wxSizerItem::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxSizerItem * wxSizer::GetItem(size_t index)
//---------------------------------------------------
void WrapClass_wxSizer::
    wrap_GetItem_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'index'")
  return_comments="returning a variable of type wxSizerItem";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizer::
    wrap_GetItem_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  long index_long;
  if (!get_val_param<long >(index_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int index = boost::numeric_cast<long unsigned int >(index_long);

  wxSizerItem * res =   this->_objectptr->GetObj()->GetItem(index);
  BasicVariable::ptr res_var = WrapClass_wxSizerItem::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of bool wxSizer::Show(wxWindow * window, bool show = true, bool recursive = false)
//---------------------------------------------------
void WrapClass_wxSizer::
    wrap_Show_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'window'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'show' (def:true)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'recursive' (def:false)")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizer::
    wrap_Show_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxWindow > window_smtptr;
  if (!get_val_smtptr_param<wxWindow >(window_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxWindow* window = window_smtptr.get();

  int show_int = ((true==true)?1:0);;
  if (!get_val_param<int >(show_int,_p,_n)) ClassReturnEmptyVar;
  bool show = (bool) (show_int>0.5);

  int recursive_int = ((false==true)?1:0);;
  if (!get_val_param<int >(recursive_int,_p,_n)) ClassReturnEmptyVar;
  bool recursive = (bool) (recursive_int>0.5);

  bool res =   this->_objectptr->GetObj()->Show(window, show, recursive);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxSizer::Show(...)
//---------------------------------------------------
void WrapClass_wxSizer::
    wrap_Show::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizer::
    wrap_Show::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxSizer::wrap_Show_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxSizer::wrap_Show_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxSizer::wrap_Show_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  WrapClass_wxSizer::wrap_Show_4 m4(this->_objectptr);
  res = m4.CallMember(_p);
  if (!m4.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of bool wxSizer::Show(wxSizer * sizer, bool show = true, bool recursive = false)
//---------------------------------------------------
void WrapClass_wxSizer::
    wrap_Show_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxSizer, "parameter named 'sizer'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'show' (def:true)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'recursive' (def:false)")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizer::
    wrap_Show_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxSizer > sizer_smtptr;
  if (!get_val_smtptr_param<wxSizer >(sizer_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxSizer* sizer = sizer_smtptr.get();

  int show_int = ((true==true)?1:0);;
  if (!get_val_param<int >(show_int,_p,_n)) ClassReturnEmptyVar;
  bool show = (bool) (show_int>0.5);

  int recursive_int = ((false==true)?1:0);;
  if (!get_val_param<int >(recursive_int,_p,_n)) ClassReturnEmptyVar;
  bool recursive = (bool) (recursive_int>0.5);

  bool res =   this->_objectptr->GetObj()->Show(sizer, show, recursive);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxSizer::Show(size_t index, bool show = true)
//---------------------------------------------------
void WrapClass_wxSizer::
    wrap_Show_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'index'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'show' (def:true)")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizer::
    wrap_Show_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  long index_long;
  if (!get_val_param<long >(index_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int index = boost::numeric_cast<long unsigned int >(index_long);

  int show_int = ((true==true)?1:0);;
  if (!get_val_param<int >(show_int,_p,_n)) ClassReturnEmptyVar;
  bool show = (bool) (show_int>0.5);

  bool res =   this->_objectptr->GetObj()->Show(index, show);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxSizer::Hide(wxSizer * sizer, bool recursive = false)
//---------------------------------------------------
void WrapClass_wxSizer::
    wrap_Hide_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxSizer, "parameter named 'sizer'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'recursive' (def:false)")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizer::
    wrap_Hide_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxSizer > sizer_smtptr;
  if (!get_val_smtptr_param<wxSizer >(sizer_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxSizer* sizer = sizer_smtptr.get();

  int recursive_int = ((false==true)?1:0);;
  if (!get_val_param<int >(recursive_int,_p,_n)) ClassReturnEmptyVar;
  bool recursive = (bool) (recursive_int>0.5);

  bool res =   this->_objectptr->GetObj()->Hide(sizer, recursive);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxSizer::Hide(...)
//---------------------------------------------------
void WrapClass_wxSizer::
    wrap_Hide::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizer::
    wrap_Hide::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxSizer::wrap_Hide_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxSizer::wrap_Hide_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxSizer::wrap_Hide_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of bool wxSizer::Hide(wxWindow * window, bool recursive = false)
//---------------------------------------------------
void WrapClass_wxSizer::
    wrap_Hide_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'window'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'recursive' (def:false)")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizer::
    wrap_Hide_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxWindow > window_smtptr;
  if (!get_val_smtptr_param<wxWindow >(window_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxWindow* window = window_smtptr.get();

  int recursive_int = ((false==true)?1:0);;
  if (!get_val_param<int >(recursive_int,_p,_n)) ClassReturnEmptyVar;
  bool recursive = (bool) (recursive_int>0.5);

  bool res =   this->_objectptr->GetObj()->Hide(window, recursive);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxSizer::Hide(size_t index)
//---------------------------------------------------
void WrapClass_wxSizer::
    wrap_Hide_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'index'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizer::
    wrap_Hide_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  long index_long;
  if (!get_val_param<long >(index_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int index = boost::numeric_cast<long unsigned int >(index_long);

  bool res =   this->_objectptr->GetObj()->Hide(index);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxSizer::IsShown(wxWindow * window)
//---------------------------------------------------
void WrapClass_wxSizer::
    wrap_IsShown_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'window'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizer::
    wrap_IsShown_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxWindow > window_smtptr;
  if (!get_val_smtptr_param<wxWindow >(window_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxWindow* window = window_smtptr.get();

  bool res =   this->_objectptr->GetObj()->IsShown(window);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxSizer::IsShown(...)
//---------------------------------------------------
void WrapClass_wxSizer::
    wrap_IsShown::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizer::
    wrap_IsShown::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxSizer::wrap_IsShown_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxSizer::wrap_IsShown_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxSizer::wrap_IsShown_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of bool wxSizer::IsShown(wxSizer * sizer)
//---------------------------------------------------
void WrapClass_wxSizer::
    wrap_IsShown_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxSizer, "parameter named 'sizer'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizer::
    wrap_IsShown_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxSizer > sizer_smtptr;
  if (!get_val_smtptr_param<wxSizer >(sizer_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxSizer* sizer = sizer_smtptr.get();

  bool res =   this->_objectptr->GetObj()->IsShown(sizer);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxSizer::IsShown(size_t index)
//---------------------------------------------------
void WrapClass_wxSizer::
    wrap_IsShown_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'index'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizer::
    wrap_IsShown_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  long index_long;
  if (!get_val_param<long >(index_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int index = boost::numeric_cast<long unsigned int >(index_long);

  bool res =   this->_objectptr->GetObj()->IsShown(index);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of void wxSizer::ShowItems(bool show)
//---------------------------------------------------
void WrapClass_wxSizer::
    wrap_ShowItems::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'show'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizer::
    wrap_ShowItems::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int show_int;
  if (!get_val_param<int >(show_int,_p,_n)) ClassHelpAndReturn;
  bool show = (bool) (show_int>0.5);

  this->_objectptr->GetObj()->ShowItems(show);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxSizer::Show(bool show)
//---------------------------------------------------
void WrapClass_wxSizer::
    wrap_Show_4::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'show'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizer::
    wrap_Show_4::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  int show_int;
  if (!get_val_param<int >(show_int,_p,_n)) ClassReturnEmptyVar;
  bool show = (bool) (show_int>0.5);

  this->_objectptr->GetObj()->Show(show);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxClassInfo * wxSizer::GetClassInfo()
//---------------------------------------------------
void WrapClass_wxSizer::
    wrap_GetClassInfo::SetParametersComments()
{
  return_comments="returning a variable of type wxClassInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizer::
    wrap_GetClassInfo::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxClassInfo * res =   this->_objectptr->GetObj()->GetClassInfo();
  BasicVariable::ptr res_var = WrapClass_wxClassInfo::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxSizer & wxSizer::operator =(wxSizer const & param0)
//---------------------------------------------------
void WrapClass_wxSizer::
    wrap___assign__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxSizer, "parameter named 'param0'")
  return_comments="returning a variable of type wxSizer";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizer::
    wrap___assign__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxSizer > param0_smtptr;
  if (!get_val_smtptr_param<wxSizer >(param0_smtptr,_p,_n)) ClassHelpAndReturn;
  wxSizer const & param0 = *param0_smtptr;

  wxSizer & res =   (*this->_objectptr->GetObj()) = (param0);
  return AMILabType<wxSizer >::CreateVar(res);
}

