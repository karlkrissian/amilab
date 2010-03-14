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


extern VarContexts  Vars;

AMIObject* AddWrapVarVector( const VarVector::ptr& objectptr)
{
  // Create new instance of the class
  AMIObject* amiobject = new AMIObject;
  amiobject->SetName("varvector");

  // Set the object context
  Variables::ptr previous_ocontext = Vars.GetObjectContext();
  Vars.SetObjectContext(amiobject->GetContext());

  ADDMEMBER("push_back",        VarVector, push_back);

  ADDMEMBER("pop_back",        VarVector, pop_back);

  ADDMEMBER("size",             VarVector, size);

  ADDMEMBER("front",            VarVector, front);
  ADDMEMBER("back",             VarVector, back);

  ADDMEMBER("at",               VarVector, at);

  // Restore the object context
  Vars.SetObjectContext(previous_ocontext);

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

  VarVector::ptr pp(new VarVector());

  AMIObject::ptr amiobject(AddWrapVarVector(pp));
  Variable<AMIObject>::ptr varres(
    new Variable<AMIObject>( "tmp_varvector", amiobject));

  return varres;

}


//---------------------------------------------------
//  push_back
//---------------------------------------------------
void wrap_VarVectorpush_back::SetParametersComments() 
{
  ADDPARAMCOMMENT("variable: input variable to add.");
}
//---------------------------------------------------
BasicVariable::ptr wrap_VarVectorpush_back::CallMember( ParamList* p)
{
  
  BasicVariable::ptr var;
  int   n = 0;

  if (!get_generic_var_param(var, p, n))         ClassHelpAndReturn;
  // probably still "naive" implementation, need to check for the permanence of the smart pointer ?
  // or is it ok?
  // do we want explicit copy or reference of the variable contents ??
  this->_objectptr->vector.push_back(var);

  return BasicVariable::ptr();
}


//---------------------------------------------------
//  pop_back
//---------------------------------------------------
void wrap_VarVectorpop_back::SetParametersComments() {}
//---------------------------------------------------
BasicVariable::ptr wrap_VarVectorpop_back::CallMember( ParamList* p)
{
  this->_objectptr->vector.pop_back();
  return BasicVariable::ptr();
}


//---------------------------------------------------
//  size
//---------------------------------------------------
void wrap_VarVectorsize::SetParametersComments() 
{
  return_comments = "Vector size (int variable).";
}
//---------------------------------------------------
BasicVariable::ptr wrap_VarVectorsize::CallMember( ParamList* p)
{
  int size = this->_objectptr->vector.size();
  // create integer variable to return
  RETURN_VARINT(size,"Vector_size");
}


//---------------------------------------------------
//  front
//---------------------------------------------------
void wrap_VarVectorfront::SetParametersComments() 
{
  return_comments = "Vector first element (variable).";
}
//---------------------------------------------------
BasicVariable::ptr wrap_VarVectorfront::CallMember( ParamList* p)
{
  if (this->_objectptr->vector.empty()) 
    return BasicVariable::ptr();
  else
    return this->_objectptr->vector.front();
}

//---------------------------------------------------
//  back
//---------------------------------------------------
void wrap_VarVectorback::SetParametersComments() 
{
  return_comments = "Vector last element (variable).";
}
//---------------------------------------------------
BasicVariable::ptr wrap_VarVectorback::CallMember( ParamList* p)
{
  if (this->_objectptr->vector.empty()) 
    return BasicVariable::ptr();
  else
    return this->_objectptr->vector.back();
}


//---------------------------------------------------
//  at
//---------------------------------------------------
void wrap_VarVectorat::SetParametersComments() 
{
  ADDPARAMCOMMENT("int   : vector position");
  return_comments = "Element at the given location if valid (variable).";
}
//---------------------------------------------------
BasicVariable::ptr wrap_VarVectorat::CallMember( ParamList* p)
{

  int pos = 0;
  int n=0;
  if (!get_int_param(pos, p, n)) ClassHelpAndReturn;

  if ((pos<0)&&(pos>=this->_objectptr->vector.size())) 
    return BasicVariable::ptr();
  else
    return this->_objectptr->vector.at(pos);
}



