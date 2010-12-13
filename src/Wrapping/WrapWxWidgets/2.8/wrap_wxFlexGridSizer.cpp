/**
 * C++ Interface: wrap_wxFlexGridSizer
 *
 * Description: wrapping wxFlexGridSizer
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

#include "wrap_wxFlexGridSizer.h"

// get all the required includes
// #include "..."
#include "boost/numeric/conversion/cast.hpp"
#ifndef wxArrayInt_declared
  #define wxArrayInt_declared
  AMI_DECLARE_TYPE(wxArrayInt)
#endif
#ifndef wxSize_declared
  #define wxSize_declared
  AMI_DECLARE_TYPE(wxSize)
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
BasicVariable::ptr WrapClass<wxFlexGridSizer>::CreateVar( ParamList* p)
{
  WrapClass_wxFlexGridSizer::wrap_wxFlexGridSizer construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(wxFlexGridSizer);
AMI_DEFINE_VARFROMSMTPTR(wxFlexGridSizer);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<wxFlexGridSizer>::CreateVar( wxFlexGridSizer* val, bool nodeleter)
{ 
  boost::shared_ptr<wxFlexGridSizer> obj_ptr(val,smartpointer_nodeleter<wxFlexGridSizer>());
  return AMILabType<wxFlexGridSizer>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxFlexGridSizer
//
Variable<AMIObject>::ptr WrapClass_wxFlexGridSizer::CreateVar( wxFlexGridSizer* sp)
{
  boost::shared_ptr<wxFlexGridSizer> di_ptr(
    sp,
    wxwindow_nodeleter<wxFlexGridSizer>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxFlexGridSizer>::CreateVar(
      new WrapClass_wxFlexGridSizer(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxFlexGridSizer::AddMethods(WrapClass<wxFlexGridSizer>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding standard methods 
  AddVar_AddGrowableRow( this_ptr);
  AddVar_RemoveGrowableRow( this_ptr);
  AddVar_AddGrowableCol( this_ptr);
  AddVar_RemoveGrowableCol( this_ptr);
  AddVar_SetFlexibleDirection( this_ptr);
  AddVar_GetFlexibleDirection( this_ptr);
  AddVar_SetNonFlexibleGrowMode( this_ptr);
  AddVar_GetNonFlexibleGrowMode( this_ptr);
  AddVar_GetRowHeights( this_ptr);
  AddVar_GetColWidths( this_ptr);
  AddVar_RecalcSizes( this_ptr);
  AddVar_CalcMin( this_ptr);
  AddVar_GetClassInfo( this_ptr);



  // Add public fields and Enumerations
  AMIObject::ptr tmpobj(amiobject.lock());
  if (!tmpobj.get()) return;
  Variables::ptr context(tmpobj->GetContext());


  


  // Adding Bases

  // Add base parent wxGridSizer
  boost::shared_ptr<wxGridSizer > parent_wxGridSizer(  boost::dynamic_pointer_cast<wxGridSizer >(this_ptr->GetObj()));
  BasicVariable::ptr var_wxGridSizer = AMILabType<wxGridSizer >::CreateVarFromSmtPtr(parent_wxGridSizer);
  context->AddVar("wxGridSizer",var_wxGridSizer);
  // Set as a default context
  Variable<AMIObject>::ptr obj_wxGridSizer = boost::dynamic_pointer_cast<Variable<AMIObject> >(var_wxGridSizer);
  context->AddDefault(obj_wxGridSizer->Pointer()->GetContext());

};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxFlexGridSizer_AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxFlexGridSizer");
    WrapClass_wxFlexGridSizer::AddVar_wxFlexGridSizer_1(amiobject->GetContext());
  WrapClass_wxFlexGridSizer::AddVar_wxFlexGridSizer(amiobject->GetContext());
  WrapClass_wxFlexGridSizer::AddVar_wxFlexGridSizer_2(amiobject->GetContext());


  // Static methods 

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxFlexGridSizer::wxFlexGridSizer(int rows, int cols, int vgap, int hgap)
//---------------------------------------------------
void WrapClass_wxFlexGridSizer::
    wrap_wxFlexGridSizer_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'rows'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'cols'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'vgap'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'hgap'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFlexGridSizer::
    wrap_wxFlexGridSizer_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>4) ClassReturnEmptyVar;
  int _n=0;

  int rows;
  if (!get_val_param<int >(rows,_p,_n,true,true)) ClassReturnEmptyVar;

  int cols;
  if (!get_val_param<int >(cols,_p,_n,true,true)) ClassReturnEmptyVar;

  int vgap;
  if (!get_val_param<int >(vgap,_p,_n,true,true)) ClassReturnEmptyVar;

  int hgap;
  if (!get_val_param<int >(hgap,_p,_n,true,true)) ClassReturnEmptyVar;

  wxFlexGridSizer* _newobj = new wxFlexGridSizer(rows, cols, vgap, hgap);
  BasicVariable::ptr res = WrapClass_wxFlexGridSizer::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor wxFlexGridSizer::wxFlexGridSizer(...)
//---------------------------------------------------
void WrapClass_wxFlexGridSizer::
    wrap_wxFlexGridSizer::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFlexGridSizer::
    wrap_wxFlexGridSizer::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxFlexGridSizer::wrap_wxFlexGridSizer_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxFlexGridSizer::wrap_wxFlexGridSizer_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor wxFlexGridSizer::wxFlexGridSizer(int cols, int vgap = 0, int hgap = 0)
//---------------------------------------------------
void WrapClass_wxFlexGridSizer::
    wrap_wxFlexGridSizer_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'cols'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'vgap' (def:0)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'hgap' (def:0)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFlexGridSizer::
    wrap_wxFlexGridSizer_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  int cols;
  if (!get_val_param<int >(cols,_p,_n,true,true)) ClassReturnEmptyVar;

  int vgap = 0;
  if (!get_val_param<int >(vgap,_p,_n,false,true)) ClassReturnEmptyVar;

  int hgap = 0;
  if (!get_val_param<int >(hgap,_p,_n,false,true)) ClassReturnEmptyVar;

  wxFlexGridSizer* _newobj = new wxFlexGridSizer(cols, vgap, hgap);
  BasicVariable::ptr res = WrapClass_wxFlexGridSizer::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of void wxFlexGridSizer::AddGrowableRow(size_t idx, int proportion = 0)
//---------------------------------------------------
void WrapClass_wxFlexGridSizer::
    wrap_AddGrowableRow::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'idx'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'proportion' (def:0)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFlexGridSizer::
    wrap_AddGrowableRow::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  long idx_long;
  if (!get_val_param<long >(idx_long,_p,_n,true,false)) ClassHelpAndReturn;
  long unsigned int idx = boost::numeric_cast<long unsigned int >(idx_long);

  int proportion = 0;
  if (!get_val_param<int >(proportion,_p,_n,false,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->AddGrowableRow(idx, proportion);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxFlexGridSizer::RemoveGrowableRow(size_t idx)
//---------------------------------------------------
void WrapClass_wxFlexGridSizer::
    wrap_RemoveGrowableRow::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'idx'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFlexGridSizer::
    wrap_RemoveGrowableRow::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  long idx_long;
  if (!get_val_param<long >(idx_long,_p,_n,true,false)) ClassHelpAndReturn;
  long unsigned int idx = boost::numeric_cast<long unsigned int >(idx_long);

  this->_objectptr->GetObj()->RemoveGrowableRow(idx);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxFlexGridSizer::AddGrowableCol(size_t idx, int proportion = 0)
//---------------------------------------------------
void WrapClass_wxFlexGridSizer::
    wrap_AddGrowableCol::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'idx'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'proportion' (def:0)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFlexGridSizer::
    wrap_AddGrowableCol::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  long idx_long;
  if (!get_val_param<long >(idx_long,_p,_n,true,false)) ClassHelpAndReturn;
  long unsigned int idx = boost::numeric_cast<long unsigned int >(idx_long);

  int proportion = 0;
  if (!get_val_param<int >(proportion,_p,_n,false,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->AddGrowableCol(idx, proportion);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxFlexGridSizer::RemoveGrowableCol(size_t idx)
//---------------------------------------------------
void WrapClass_wxFlexGridSizer::
    wrap_RemoveGrowableCol::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'idx'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFlexGridSizer::
    wrap_RemoveGrowableCol::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  long idx_long;
  if (!get_val_param<long >(idx_long,_p,_n,true,false)) ClassHelpAndReturn;
  long unsigned int idx = boost::numeric_cast<long unsigned int >(idx_long);

  this->_objectptr->GetObj()->RemoveGrowableCol(idx);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxFlexGridSizer::SetFlexibleDirection(int direction)
//---------------------------------------------------
void WrapClass_wxFlexGridSizer::
    wrap_SetFlexibleDirection::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'direction'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFlexGridSizer::
    wrap_SetFlexibleDirection::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int direction;
  if (!get_val_param<int >(direction,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetFlexibleDirection(direction);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int wxFlexGridSizer::GetFlexibleDirection()
//---------------------------------------------------
void WrapClass_wxFlexGridSizer::
    wrap_GetFlexibleDirection::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFlexGridSizer::
    wrap_GetFlexibleDirection::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetFlexibleDirection();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxFlexGridSizer::SetNonFlexibleGrowMode(wxFlexSizerGrowMode mode)
//---------------------------------------------------
void WrapClass_wxFlexGridSizer::
    wrap_SetNonFlexibleGrowMode::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'mode'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFlexGridSizer::
    wrap_SetNonFlexibleGrowMode::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int mode_int;
  if (!get_val_param<int >(mode_int,_p,_n,true,false)) ClassHelpAndReturn;
  wxFlexSizerGrowMode mode = (wxFlexSizerGrowMode) mode_int;

  this->_objectptr->GetObj()->SetNonFlexibleGrowMode(mode);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxFlexSizerGrowMode wxFlexGridSizer::GetNonFlexibleGrowMode()
//---------------------------------------------------
void WrapClass_wxFlexGridSizer::
    wrap_GetNonFlexibleGrowMode::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFlexGridSizer::
    wrap_GetNonFlexibleGrowMode::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxFlexSizerGrowMode res =   this->_objectptr->GetObj()->GetNonFlexibleGrowMode();
  int res_int = (int) res;
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of wxArrayInt const & wxFlexGridSizer::GetRowHeights()
//---------------------------------------------------
void WrapClass_wxFlexGridSizer::
    wrap_GetRowHeights::SetParametersComments()
{
  return_comments="returning a variable of type wxArrayInt";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFlexGridSizer::
    wrap_GetRowHeights::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxArrayInt const & res =   this->_objectptr->GetObj()->GetRowHeights();
  return AMILabType<wxArrayInt >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxArrayInt const & wxFlexGridSizer::GetColWidths()
//---------------------------------------------------
void WrapClass_wxFlexGridSizer::
    wrap_GetColWidths::SetParametersComments()
{
  return_comments="returning a variable of type wxArrayInt";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFlexGridSizer::
    wrap_GetColWidths::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxArrayInt const & res =   this->_objectptr->GetObj()->GetColWidths();
  return AMILabType<wxArrayInt >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxFlexGridSizer::RecalcSizes()
//---------------------------------------------------
void WrapClass_wxFlexGridSizer::
    wrap_RecalcSizes::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFlexGridSizer::
    wrap_RecalcSizes::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->RecalcSizes();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxSize wxFlexGridSizer::CalcMin()
//---------------------------------------------------
void WrapClass_wxFlexGridSizer::
    wrap_CalcMin::SetParametersComments()
{
  return_comments="returning a variable of type wxSize";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFlexGridSizer::
    wrap_CalcMin::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxSize res =   this->_objectptr->GetObj()->CalcMin();
  return AMILabType<wxSize >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxClassInfo * wxFlexGridSizer::GetClassInfo()
//---------------------------------------------------
void WrapClass_wxFlexGridSizer::
    wrap_GetClassInfo::SetParametersComments()
{
  return_comments="returning a variable of type wxClassInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFlexGridSizer::
    wrap_GetClassInfo::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxClassInfo * res =   this->_objectptr->GetObj()->GetClassInfo();
  BasicVariable::ptr res_var = AMILabType<wxClassInfo >::CreateVar(res,true);
  return res_var;
}

