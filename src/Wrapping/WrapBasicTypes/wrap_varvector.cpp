//
// C++ Implementation: wrap_varvector
//
// Description: Wrapping of a vector of variables
//
//
// Author: Karl krissian <>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//

#include "paramlist.h"

#include "VarContexts.hpp"
#include "wrapfunctions.hpp"
//#include "wrapfunctions_draw.h"
#include "ami_class.h"
#include "ami_object.h"
#include "wrap_varvector.h"


//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<VarVector>::CreateVar( ParamList* p)
{
  WrapClass_VarVector::wrap_VarVector construct;
  return construct.CallMember(p);
}

AMI_DEFINE_WRAPPEDTYPE_HASCOPY(VarVector);
AMI_DEFINE_VARFROMSMTPTR(VarVector);

/*
//
// static member for creating a variable from a pointer to VarVector
//
Variable<AMIObject>::ptr WrapClass_VarVector::CreateVar( VarVector* vv)
{
  boost::shared_ptr<VarVector> vv_ptr(vv);
  return 
    WrapClass<VarVector>::CreateVar(
      new WrapClass_VarVector( vv_ptr));
}
*/

//---------------------------------------------------
//  VarVector Constructor
//---------------------------------------------------
void  WrapClass_VarVector::wrap_VarVector::SetParametersComments() 
{
  ADDPARAMCOMMENT("integer: initial size (def:0).");
  ADDPARAMCOMMENT("Variable: optional variable to fill the initial elements.");
  return_comments = "A wrapped VarVector object.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_VarVector::wrap_VarVector::CallMember( ParamList* p)
{
  if (!p) ClassHelpAndReturn;
  int n=0;
  int initial_size = 0;
  get_val_param<int>(initial_size,p,n);
  
  BasicVariable::ptr v(p->GetParam(n++));

  VarVector* vv = new VarVector();
  if ((initial_size>0)&&(v.get()))  {
    for (int i=0; i<initial_size; i++)
      vv->push_back(v->NewCopy());
  } else {
    CLASS_MESSAGE("Needs a valid variable as second parameter.");
  }

  boost::shared_ptr<VarVector> vv_ptr(vv);

  return WrapClass<VarVector>::CreateVar(new WrapClass_VarVector(vv_ptr));
}

//===================================================
// Nested class members
//===================================================

//---------------------------------------------------
//  push_back
//---------------------------------------------------
void WrapClass_VarVector::wrap_push_back::SetParametersComments() 
{
  ADDPARAMCOMMENT("variable: input variable to add.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_VarVector::wrap_push_back::CallMember( ParamList* p)
{
  
  BasicVariable::ptr var;
  int   n = 0;

  if (!get_generic_var_param(var, p, n))         ClassHelpAndReturn;
  // probably still "naive" implementation, need to check for the permanence of the smart pointer ?
  // or is it ok?
  // do we want explicit copy or reference of the variable contents ??
  cout << "_objectptr" << _objectptr << endl; 

  this->_objectptr->_obj->push_back(var);

  return BasicVariable::ptr();
}


//---------------------------------------------------
//  pop_back
//---------------------------------------------------
void WrapClass_VarVector::wrap_pop_back::SetParametersComments() {}
//---------------------------------------------------
BasicVariable::ptr WrapClass_VarVector::wrap_pop_back::CallMember( ParamList* p)
{
  this->_objectptr->_obj->pop_back();
  return BasicVariable::ptr();
}


//---------------------------------------------------
//  size
//---------------------------------------------------
void WrapClass_VarVector::wrap_size::SetParametersComments() 
{
  return_comments = "Vector size (int variable).";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_VarVector::wrap_size::CallMember( ParamList* p)
{
  int size = this->_objectptr->_obj->size();
  // create integer variable to return
  RETURN_VAR(int,size);
}


//---------------------------------------------------
//  front
//---------------------------------------------------
void WrapClass_VarVector::wrap_front::SetParametersComments() 
{
  return_comments = "Vector first element (variable).";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_VarVector::wrap_front::CallMember( ParamList* p)
{
  if (this->_objectptr->_obj->empty()) 
    return BasicVariable::ptr();
  else
    return this->_objectptr->_obj->front();
}

//---------------------------------------------------
//  back
//---------------------------------------------------
void WrapClass_VarVector::wrap_back::SetParametersComments() 
{
  return_comments = "Vector last element (variable).";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_VarVector::wrap_back::CallMember( ParamList* p)
{
  if (this->_objectptr->_obj->empty()) 
    return BasicVariable::ptr();
  else
    return this->_objectptr->_obj->back();
}


//---------------------------------------------------
//  at
//---------------------------------------------------
void WrapClass_VarVector::wrap_at::SetParametersComments() 
{
  ADDPARAMCOMMENT("int   : vector position");
  return_comments = "Element at the given location if valid (variable).";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_VarVector::wrap_at::CallMember( ParamList* p)
{

  int pos = 0;
  int n=0;
  if (!get_int_param(pos, p, n)) ClassHelpAndReturn;

  if ((pos<0)||(pos>=(int)this->_objectptr->_obj->size())) 
    return BasicVariable::ptr();
  else
    return this->_objectptr->_obj->at(pos);
}

//---------------------------------------------------
//  clear
//---------------------------------------------------
void WrapClass_VarVector::wrap_clear::SetParametersComments() {}
//---------------------------------------------------
BasicVariable::ptr WrapClass_VarVector::wrap_clear::CallMember( ParamList* p)
{
  this->_objectptr->_obj->clear(); 
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  setelement
//---------------------------------------------------
void WrapClass_VarVector::
      wrap_setelement::SetParametersComments() 
{
  ADDPARAMCOMMENT("Integer: position");
  ADDPARAMCOMMENT("Variable");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_VarVector::
      wrap_setelement::CallMember( ParamList* p)
{
  int n = 0;
  int pos = 0;

  if (!get_int_param(pos, p, n)) ClassHelpAndReturn;
  BasicVariable::ptr v(p->GetParam(n++));

  if ((pos<0)||(pos>=(int)this->_objectptr->_obj->size())) 
    return BasicVariable::ptr();
  else
    if (v.get()) {
      (*this->_objectptr->_obj)[pos] = v;
    }
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  left_assign
//---------------------------------------------------
void WrapClass_VarVector::
      wrap_left_assign::SetParametersComments() 
{
  ADDPARAMCOMMENT("Variable of type wrapped VarVector.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_VarVector::
      wrap_left_assign::CallMember( ParamList* p)
{
  int n = 0;
  CLASS_GET_OBJECT_PARAM(VarVector,_var,_obj);

  if (_obj.get()) {
    this->_objectptr->_obj = _obj;
  }
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  assign
//---------------------------------------------------
void WrapClass_VarVector::
      wrap_assign::SetParametersComments() 
{
  ADDPARAMCOMMENT("Variable of type wrapped VarVector.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_VarVector::
      wrap_assign::CallMember( ParamList* p)
{
  int n = 0;
  CLASS_GET_OBJECT_PARAM(VarVector,var,_obj);

  if (_obj.get()) {
    this->_objectptr->_obj = _obj;
  }
  return BasicVariable::ptr();
}


