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


// don't use 'const' here, it causes memory problems ....
AMIObject::ptr AddWrapVarVector(  WrapClass_vector::ptr& objectptr)
{
  // Create new instance of the class
  AMIObject::ptr amiobject( new AMIObject);
  amiobject->SetName("varvector");

  //--- nested classes
  // initialization, pointer to amiobject
  // keeping a weak pointer to allow variable deletion
  objectptr->SetAMIObject(amiobject);

  // at least keeps the pointer alive: otherwise could be risky ...
  // mutual smart pointers, never deleted ???
  // amiobject->SetWrappedObject(objectptr);

  // objectptr would be deleted if not maintained by the function ...
  objectptr->AddVar_push_back( objectptr);
  objectptr->AddVar_pop_back(  objectptr);
  objectptr->AddVar_size(      objectptr);
  objectptr->AddVar_front(     objectptr);
  objectptr->AddVar_back(      objectptr);
  objectptr->AddVar_at(        objectptr);
  objectptr->AddVar_clear(     objectptr);

  return amiobject;
}

//---------------------------------------------------
BasicVariable::ptr wrap_VarVector( ParamList* p)
{
    char functionname[] = "VarVector";
    char description[]=" \n\
      New VarVector object, store a vector of variables (smart pointers). \n\
            ";
    char parameters[] =" \n\
      - no parameter \n\
            ";

  WrapClass_vector::ptr pp(new WrapClass_vector());

  AMIObject::ptr amiobject(AddWrapVarVector(pp));
  Variable<AMIObject>::ptr varres(
    new Variable<AMIObject>( "tmp_varvector", amiobject));

  return varres;

}


//===================================================
// Nested class members
//===================================================

//---------------------------------------------------
//  push_back
//---------------------------------------------------
void WrapClass_vector::wrap_push_back::SetParametersComments() 
{
  ADDPARAMCOMMENT("variable: input variable to add.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_vector::wrap_push_back::CallMember( ParamList* p)
{
  
  BasicVariable::ptr var;
  int   n = 0;

  if (!get_generic_var_param(var, p, n))         ClassHelpAndReturn;
  // probably still "naive" implementation, need to check for the permanence of the smart pointer ?
  // or is it ok?
  // do we want explicit copy or reference of the variable contents ??
  cout << "_objectptr" << _objectptr << endl; 

  this->_objectptr->vector.push_back(var);

  return BasicVariable::ptr();
}


//---------------------------------------------------
//  pop_back
//---------------------------------------------------
void WrapClass_vector::wrap_pop_back::SetParametersComments() {}
//---------------------------------------------------
BasicVariable::ptr WrapClass_vector::wrap_pop_back::CallMember( ParamList* p)
{
  this->_objectptr->vector.pop_back();
  return BasicVariable::ptr();
}


//---------------------------------------------------
//  size
//---------------------------------------------------
void WrapClass_vector::wrap_size::SetParametersComments() 
{
  return_comments = "Vector size (int variable).";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_vector::wrap_size::CallMember( ParamList* p)
{
  int size = this->_objectptr->vector.size();
  // create integer variable to return
  RETURN_VARINT(size,"Vector_size");
}


//---------------------------------------------------
//  front
//---------------------------------------------------
void WrapClass_vector::wrap_front::SetParametersComments() 
{
  return_comments = "Vector first element (variable).";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_vector::wrap_front::CallMember( ParamList* p)
{
  if (this->_objectptr->vector.empty()) 
    return BasicVariable::ptr();
  else
    return this->_objectptr->vector.front();
}

//---------------------------------------------------
//  back
//---------------------------------------------------
void WrapClass_vector::wrap_back::SetParametersComments() 
{
  return_comments = "Vector last element (variable).";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_vector::wrap_back::CallMember( ParamList* p)
{
  if (this->_objectptr->vector.empty()) 
    return BasicVariable::ptr();
  else
    return this->_objectptr->vector.back();
}


//---------------------------------------------------
//  at
//---------------------------------------------------
void WrapClass_vector::wrap_at::SetParametersComments() 
{
  ADDPARAMCOMMENT("int   : vector position");
  return_comments = "Element at the given location if valid (variable).";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_vector::wrap_at::CallMember( ParamList* p)
{

  int pos = 0;
  int n=0;
  if (!get_int_param(pos, p, n)) ClassHelpAndReturn;

  if ((pos<0)||(pos>=this->_objectptr->vector.size())) 
    return BasicVariable::ptr();
  else
    return this->_objectptr->vector.at(pos);
}

//---------------------------------------------------
//  clear
//---------------------------------------------------
void WrapClass_vector::wrap_clear::SetParametersComments() {}
//---------------------------------------------------
BasicVariable::ptr WrapClass_vector::wrap_clear::CallMember( ParamList* p)
{
  this->_objectptr->vector.clear(); 
  return BasicVariable::ptr();
}


