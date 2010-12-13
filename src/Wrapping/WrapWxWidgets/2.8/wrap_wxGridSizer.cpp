/**
 * C++ Interface: wrap_wxGridSizer
 *
 * Description: wrapping wxGridSizer
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

#include "wrap_wxGridSizer.h"

// get all the required includes
// #include "..."
#ifndef wxGridSizer_declared
  #define wxGridSizer_declared
  AMI_DECLARE_TYPE(wxGridSizer)
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
BasicVariable::ptr WrapClass<wxGridSizer>::CreateVar( ParamList* p)
{
  WrapClass_wxGridSizer::wrap_wxGridSizer construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_HASCOPY(wxGridSizer);
AMI_DEFINE_VARFROMSMTPTR(wxGridSizer);


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxGridSizer
//
Variable<AMIObject>::ptr WrapClass_wxGridSizer::CreateVar( wxGridSizer* sp)
{
  boost::shared_ptr<wxGridSizer> di_ptr(
    sp,
    wxwindow_nodeleter<wxGridSizer>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxGridSizer>::CreateVar(
      new WrapClass_wxGridSizer(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxGridSizer::AddMethods(WrapClass<wxGridSizer>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding copy method 
  AddVar___copy__( this_ptr);
  // Adding standard methods 
  AddVar_RecalcSizes( this_ptr);
  AddVar_CalcMin( this_ptr);
  AddVar_SetCols( this_ptr);
  AddVar_SetRows( this_ptr);
  AddVar_SetVGap( this_ptr);
  AddVar_SetHGap( this_ptr);
  AddVar_GetCols( this_ptr);
  AddVar_GetRows( this_ptr);
  AddVar_GetVGap( this_ptr);
  AddVar_GetHGap( this_ptr);
  AddVar_GetClassInfo( this_ptr);

  // Adding operators
  AddVar___assign__( this_ptr);



  // Add public fields and Enumerations
  AMIObject::ptr tmpobj(amiobject.lock());
  if (!tmpobj.get()) return;
  Variables::ptr context(tmpobj->GetContext());


  


  // Adding Bases

  // Add base parent wxSizer
  boost::shared_ptr<wxSizer > parent_wxSizer(  boost::dynamic_pointer_cast<wxSizer >(this_ptr->GetObj()));
  BasicVariable::ptr var_wxSizer = AMILabType<wxSizer >::CreateVarFromSmtPtr(parent_wxSizer);
  context->AddVar("wxSizer",var_wxSizer);
  // Set as a default context
  Variable<AMIObject>::ptr obj_wxSizer = boost::dynamic_pointer_cast<Variable<AMIObject> >(var_wxSizer);
  context->AddDefault(obj_wxSizer->Pointer()->GetContext());

};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxGridSizer_AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxGridSizer");
    WrapClass_wxGridSizer::AddVar_wxGridSizer_1(amiobject->GetContext());
  WrapClass_wxGridSizer::AddVar_wxGridSizer(amiobject->GetContext());
  WrapClass_wxGridSizer::AddVar_wxGridSizer_2(amiobject->GetContext());
  WrapClass_wxGridSizer::AddVar_wxGridSizer_3(amiobject->GetContext());


  // Static methods 

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxGridSizer::wxGridSizer(wxGridSizer const & param0)
//---------------------------------------------------
void WrapClass_wxGridSizer::
    wrap_wxGridSizer_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxGridSizer, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxGridSizer::
    wrap_wxGridSizer_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxGridSizer > param0_smtptr;
  if (!get_val_smtptr_param<wxGridSizer >(param0_smtptr,_p,_n,true,true,true)) ClassReturnEmptyVar;
  wxGridSizer const & param0 = *param0_smtptr;

  wxGridSizer* _newobj = new wxGridSizer(param0);
  BasicVariable::ptr res = WrapClass_wxGridSizer::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor wxGridSizer::wxGridSizer(...)
//---------------------------------------------------
void WrapClass_wxGridSizer::
    wrap_wxGridSizer::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxGridSizer::
    wrap_wxGridSizer::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxGridSizer::wrap_wxGridSizer_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxGridSizer::wrap_wxGridSizer_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxGridSizer::wrap_wxGridSizer_3 m3;
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor wxGridSizer::wxGridSizer(int rows, int cols, int vgap, int hgap)
//---------------------------------------------------
void WrapClass_wxGridSizer::
    wrap_wxGridSizer_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'rows'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'cols'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'vgap'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'hgap'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxGridSizer::
    wrap_wxGridSizer_2::CallMember( ParamList* _p)
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

  wxGridSizer* _newobj = new wxGridSizer(rows, cols, vgap, hgap);
  BasicVariable::ptr res = WrapClass_wxGridSizer::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of Constructor wxGridSizer::wxGridSizer(int cols, int vgap = 0, int hgap = 0)
//---------------------------------------------------
void WrapClass_wxGridSizer::
    wrap_wxGridSizer_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'cols'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'vgap' (def:0)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'hgap' (def:0)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxGridSizer::
    wrap_wxGridSizer_3::CallMember( ParamList* _p)
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

  wxGridSizer* _newobj = new wxGridSizer(cols, vgap, hgap);
  BasicVariable::ptr res = WrapClass_wxGridSizer::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of 'copy' method for wxGridSizer.
//---------------------------------------------------
void WrapClass_wxGridSizer::
    wrap___copy__::SetParametersComments()
{
  return_comments="A copy of the wxGridSizer object within a new variable.";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxGridSizer::
    wrap___copy__::CallMember( ParamList* _p)
{
    return AMILabType<wxGridSizer >::CreateVar( new wxGridSizer(*(this->_objectptr->GetObj())));
}

//---------------------------------------------------
//  Wrapping of void wxGridSizer::RecalcSizes()
//---------------------------------------------------
void WrapClass_wxGridSizer::
    wrap_RecalcSizes::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxGridSizer::
    wrap_RecalcSizes::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->RecalcSizes();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxSize wxGridSizer::CalcMin()
//---------------------------------------------------
void WrapClass_wxGridSizer::
    wrap_CalcMin::SetParametersComments()
{
  return_comments="returning a variable of type wxSize";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxGridSizer::
    wrap_CalcMin::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxSize res =   this->_objectptr->GetObj()->CalcMin();
  return AMILabType<wxSize >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxGridSizer::SetCols(int cols)
//---------------------------------------------------
void WrapClass_wxGridSizer::
    wrap_SetCols::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'cols'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxGridSizer::
    wrap_SetCols::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int cols;
  if (!get_val_param<int >(cols,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetCols(cols);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxGridSizer::SetRows(int rows)
//---------------------------------------------------
void WrapClass_wxGridSizer::
    wrap_SetRows::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'rows'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxGridSizer::
    wrap_SetRows::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int rows;
  if (!get_val_param<int >(rows,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetRows(rows);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxGridSizer::SetVGap(int gap)
//---------------------------------------------------
void WrapClass_wxGridSizer::
    wrap_SetVGap::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'gap'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxGridSizer::
    wrap_SetVGap::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int gap;
  if (!get_val_param<int >(gap,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetVGap(gap);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxGridSizer::SetHGap(int gap)
//---------------------------------------------------
void WrapClass_wxGridSizer::
    wrap_SetHGap::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'gap'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxGridSizer::
    wrap_SetHGap::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int gap;
  if (!get_val_param<int >(gap,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetHGap(gap);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int wxGridSizer::GetCols()
//---------------------------------------------------
void WrapClass_wxGridSizer::
    wrap_GetCols::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxGridSizer::
    wrap_GetCols::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetCols();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int wxGridSizer::GetRows()
//---------------------------------------------------
void WrapClass_wxGridSizer::
    wrap_GetRows::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxGridSizer::
    wrap_GetRows::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetRows();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int wxGridSizer::GetVGap()
//---------------------------------------------------
void WrapClass_wxGridSizer::
    wrap_GetVGap::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxGridSizer::
    wrap_GetVGap::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetVGap();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int wxGridSizer::GetHGap()
//---------------------------------------------------
void WrapClass_wxGridSizer::
    wrap_GetHGap::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxGridSizer::
    wrap_GetHGap::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetHGap();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxClassInfo * wxGridSizer::GetClassInfo()
//---------------------------------------------------
void WrapClass_wxGridSizer::
    wrap_GetClassInfo::SetParametersComments()
{
  return_comments="returning a variable of type wxClassInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxGridSizer::
    wrap_GetClassInfo::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxClassInfo * res =   this->_objectptr->GetObj()->GetClassInfo();
  BasicVariable::ptr res_var = AMILabType<wxClassInfo >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxGridSizer & wxGridSizer::operator =(wxGridSizer const & param0)
//---------------------------------------------------
void WrapClass_wxGridSizer::
    wrap___assign__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxGridSizer, "parameter named 'param0'")
  return_comments="returning a variable of type wxGridSizer";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxGridSizer::
    wrap___assign__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxGridSizer > param0_smtptr;
  if (!get_val_smtptr_param<wxGridSizer >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxGridSizer const & param0 = *param0_smtptr;

  wxGridSizer & res =   (*this->_objectptr->GetObj()) = (param0);
  return AMILabType<wxGridSizer >::CreateVar(res);
}

