//
// C++ Implementation: wrap_varlist
//
// Description: Wrapping of a list of variables
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
#include "wrap_varlist.h"


#define RETURN_VARINT(val,name)             \
  std::string varname = (boost::format("%1%_id")%name).str();\
  int_ptr varint(new int(val));\
  Variable<int>::ptr varres( new Variable<int>(varname, varint));\
  return varres;


extern VarContexts  Vars;

AMIObject* AddWrapVarList( const VarList::ptr& objectptr)
{
  // Create new instance of the class
  AMIObject* amiobject = new AMIObject;
  amiobject->SetName("varlist");

  // Set the object context
  Variables::ptr previous_ocontext = Vars.GetObjectContext();
  Vars.SetObjectContext(amiobject->GetContext());

  ADDMEMBER("push_front",       VarList, push_front);
  ADDMEMBER("push_back",        VarList, push_back);

  ADDMEMBER("pop_front",       VarList, pop_front);
  ADDMEMBER("pop_back",        VarList, pop_back);

  ADDMEMBER("size",             VarList, size);

  ADDMEMBER("front",            VarList, front);
  ADDMEMBER("back",             VarList, back);

  // Restore the object context
  Vars.SetObjectContext(previous_ocontext);

  return amiobject;
}

//---------------------------------------------------
BasicVariable::ptr wrap_VarList( ParamList* p)
{
    char functionname[] = "VarList";
    char description[]=" \n\
      New VarList object, store a list of variables (smart pointers). \n\
            ";
    char parameters[] =" \n\
      - no parameter \n\
            ";

  VarList::ptr pp(new VarList());

  AMIObject::ptr amiobject(AddWrapVarList(pp));
  Variable<AMIObject>::ptr varres(
      new Variable<AMIObject>("tmp_varlist",amiobject));

  return varres;

}


//---------------------------------------------------
//  push_front
//---------------------------------------------------
void wrap_VarListpush_front::SetParametersComments() 
{
  ADDPARAMCOMMENT("variable: input variable to add.");
}
//---------------------------------------------------
BasicVariable::ptr wrap_VarListpush_front::CallMember( ParamList* p)
{
  
  BasicVariable::ptr var;
  int   n = 0;

  if (!get_generic_var_param(var, p, n))         ClassHelpAndReturn;
  // probably still "naive" implementation, need to check for the permanence of the smart pointer ?
  // or is it ok?
  // do we want explicit copy or reference of the variable contents ??
  this->_objectptr->list.push_front(var);

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  push_back
//---------------------------------------------------
void wrap_VarListpush_back::SetParametersComments() 
{
  ADDPARAMCOMMENT("variable: input variable to add.");
}
//---------------------------------------------------
BasicVariable::ptr wrap_VarListpush_back::CallMember( ParamList* p)
{
  
  BasicVariable::ptr var;
  int   n = 0;

  if (!get_generic_var_param(var, p, n))         ClassHelpAndReturn;
  // probably still "naive" implementation, need to check for the permanence of the smart pointer ?
  // or is it ok?
  // do we want explicit copy or reference of the variable contents ??
  this->_objectptr->list.push_back(var);

  return BasicVariable::ptr();
}


//---------------------------------------------------
//  pop_front
//---------------------------------------------------
void wrap_VarListpop_front::SetParametersComments() {}
//---------------------------------------------------
BasicVariable::ptr wrap_VarListpop_front::CallMember( ParamList* p)
{
  this->_objectptr->list.pop_front();
  return BasicVariable::ptr();
}


//---------------------------------------------------
//  pop_back
//---------------------------------------------------
void wrap_VarListpop_back::SetParametersComments() {}
//---------------------------------------------------
BasicVariable::ptr wrap_VarListpop_back::CallMember( ParamList* p)
{
  this->_objectptr->list.pop_back();
  return BasicVariable::ptr();
}


//---------------------------------------------------
//  size
//---------------------------------------------------
void wrap_VarListsize::SetParametersComments() 
{
  return_comments = "List size (int variable).";
}
//---------------------------------------------------
BasicVariable::ptr wrap_VarListsize::CallMember( ParamList* p)
{
  int size = this->_objectptr->list.size();
  // create integer variable to return
  RETURN_VARINT(size,"list_size");
}


//---------------------------------------------------
//  front
//---------------------------------------------------
void wrap_VarListfront::SetParametersComments() 
{
  return_comments = "list first element (variable).";
}
//---------------------------------------------------
BasicVariable::ptr wrap_VarListfront::CallMember( ParamList* p)
{
  if (this->_objectptr->list.empty()) 
    return BasicVariable::ptr();
  else
    return this->_objectptr->list.front();
}

//---------------------------------------------------
//  back
//---------------------------------------------------
void wrap_VarListback::SetParametersComments() 
{
  return_comments = "list last element (variable).";
}
//---------------------------------------------------
BasicVariable::ptr wrap_VarListback::CallMember( ParamList* p)
{
  if (this->_objectptr->list.empty()) 
    return BasicVariable::ptr();
  else
    return this->_objectptr->list.back();
}

