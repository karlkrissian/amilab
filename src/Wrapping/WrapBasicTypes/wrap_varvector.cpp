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


#include "VarContexts.hpp"
#include "wrapfunctions.hpp"
#include "wrapfunctions_draw.h"
#include "ami_class.h"
#include "ami_object.h"
#include "wrap_varvector.h"


#define RETURN_VARINT(val,name)             \
  std::string varname = (boost::format("%1%_id")%name).str();\
  int_ptr varint(new int(val));\
  Variable<int>::ptr varres( new Variable<int>(varname, varint));\
  return varres;

//-------------------------------------------------------------------------
AMIObject::ptr AddWrap_VarVector(  WrapClass_VarVector::ptr& objectptr)
{
  // Create new instance of the class
  AMIObject::ptr amiobject( new AMIObject);
  amiobject->SetName("VarVector");
  amiobject->SetWrappedObject(objectptr);
  objectptr->SetAMIObject(amiobject);
  objectptr->AddMethods( objectptr);
  return amiobject;
}

//----------------------------------------------------------
Variable<AMIObject>::ptr CreateVar_VarVector( const VarVector& vv)
{
  // here VarVector can be deleted
  WrapClass_VarVector::ptr sip(new WrapClass_VarVector(vv));
  AMIObject::ptr amiobject(AddWrap_VarVector(sip));
  Variable<AMIObject>::ptr varres(
      new Variable<AMIObject>( amiobject));
  return varres;
}

//---------------------------------------------------
//  VarVector Constructor
//---------------------------------------------------
void  wrap_VarVector::SetParametersComments() 
{
  ADDPARAMCOMMENT("integer: initial size (def:0).");
  ADDPARAMCOMMENT("Variable: optional variable to fill the initial elements.");
  return_comments = "A wrapped VarVector object.";
}
//---------------------------------------------------
BasicVariable::ptr wrap_VarVector::CallMember( ParamList* p)
{
  if (!p) ClassHelpAndReturn;
  int n=0;
  int initial_size = 0;
  get_val_param<int>(initial_size,p,n);
  
  BasicVariable::ptr v(p->GetParam(n++));

  VarVector vv;
  if ((initial_size>0)&&(v.get()))  {
    for (int i=0; i<initial_size; i++)
      vv.push_back(v->NewCopy());
  } else {
    CLASS_MESSAGE("Needs a valid variable as second parameter.");
  }
  return CreateVar_VarVector(vv);
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

  this->_objectptr->_obj.push_back(var);

  return BasicVariable::ptr();
}


//---------------------------------------------------
//  pop_back
//---------------------------------------------------
void WrapClass_VarVector::wrap_pop_back::SetParametersComments() {}
//---------------------------------------------------
BasicVariable::ptr WrapClass_VarVector::wrap_pop_back::CallMember( ParamList* p)
{
  this->_objectptr->_obj.pop_back();
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
  int size = this->_objectptr->_obj.size();
  // create integer variable to return
  RETURN_VARINT(size,"Vector_size");
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
  if (this->_objectptr->_obj.empty()) 
    return BasicVariable::ptr();
  else
    return this->_objectptr->_obj.front();
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
  if (this->_objectptr->_obj.empty()) 
    return BasicVariable::ptr();
  else
    return this->_objectptr->_obj.back();
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

  if ((pos<0)||(pos>=this->_objectptr->_obj.size())) 
    return BasicVariable::ptr();
  else
    return this->_objectptr->_obj.at(pos);
}

//---------------------------------------------------
//  clear
//---------------------------------------------------
void WrapClass_VarVector::wrap_clear::SetParametersComments() {}
//---------------------------------------------------
BasicVariable::ptr WrapClass_VarVector::wrap_clear::CallMember( ParamList* p)
{
  this->_objectptr->_obj.clear(); 
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

  if ((pos<0)||(pos>=this->_objectptr->_obj.size())) 
    return BasicVariable::ptr();
  else
    if (v.get()) {
      this->_objectptr->_obj[pos] = v;
    }
  return BasicVariable::ptr();
}


