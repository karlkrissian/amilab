//
// C++ Implementation: wrap_stdvector
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
#include "wrap_stdvector.h"


//
// static member for creating a variable from a pointer to dwControlPoint
//
template <class T>
Variable<AMIObject>::ptr WrapClass_StdVector<T>::CreateVar( std::vector<T>* sp)
{
  boost::shared_ptr<std::vector<T> > obj_ptr(sp);
  return 
    WrapClass<std::vector<T> >::CreateVar(
      new WrapClass_StdVector<T>( obj_ptr));
}


//---------------------------------------------------
//  StdVector Constructor
//---------------------------------------------------
template <class T>
void  WrapClass_StdVector<T>::
  wrap_StdVector::SetParametersComments() 
{
  ADDPARAMCOMMENT("integer: initial size (def:0).");
  ADDPARAMCOMMENT("Variable: optional variable to fill the initial elements.");
  return_comments = "A wrapped StdVector object.";
}
//---------------------------------------------------
template <class T>
BasicVariable::ptr WrapClass_StdVector<T>::
  wrap_StdVector::CallMember( ParamList* p)
{
  if (!p) ClassHelpAndReturn;
  int n=0;
  int initial_size = 0;
  get_val_param<int>(initial_size,p,n);

//  Variable<AMIObject>::ptr lvar;
//  boost::shared_ptr<std::vector<T> > lobj;

  T lobj;

  std::vector<T>* v = new std::vector<T>();
  // implementation for standard builtin types, not objects
  if (get_val_param<T>(lobj,p,n)) {
    if (initial_size>0)  {
      for (int i=0; i<initial_size; i++)
        v->push_back(lobj);
    }
  } else {
    CLASS_MESSAGE("Needs a valid variable as second parameter.");
  }
  return WrapClass_StdVector<T>::CreateVar(v);
}


//===================================================
// Nested class members
//===================================================

//---------------------------------------------------
//  push_back
//---------------------------------------------------
template <class T>
void WrapClass_StdVector<T>::wrap_push_back::SetParametersComments() 
{
  ADDPARAMCOMMENT("variable: input variable to add.");
}
//---------------------------------------------------
template <class T>
BasicVariable::ptr WrapClass_StdVector<T>::wrap_push_back::CallMember( ParamList* p)
{
  
  T var;
  int   n = 0;
  if (!get_val_param<T>(var, p, n)) ClassHelpAndReturn;
  this->_objectptr->_obj->push_back(var);

  return BasicVariable::ptr();
}


//---------------------------------------------------
//  pop_back
//---------------------------------------------------
template <class T>
void WrapClass_StdVector<T>::wrap_pop_back::SetParametersComments() {}
//---------------------------------------------------
template <class T>
BasicVariable::ptr WrapClass_StdVector<T>::wrap_pop_back::CallMember( ParamList* p)
{
  this->_objectptr->_obj->pop_back();
  return BasicVariable::ptr();
}


//---------------------------------------------------
//  size
//---------------------------------------------------
template <class T>
void WrapClass_StdVector<T>::wrap_size::SetParametersComments() 
{
  return_comments = "Vector size (int variable).";
}
//---------------------------------------------------
template <class T>
BasicVariable::ptr WrapClass_StdVector<T>::wrap_size::CallMember( ParamList* p)
{
  int size = this->_objectptr->_obj->size();
  // create integer variable to return
  RETURN_VAR(int,size);
}


//---------------------------------------------------
//  front
//---------------------------------------------------
template <class T>
void WrapClass_StdVector<T>::wrap_front::SetParametersComments() 
{
  return_comments = "Vector first element (variable).";
}
//---------------------------------------------------
template <class T>
BasicVariable::ptr WrapClass_StdVector<T>::wrap_front::CallMember( ParamList* p)
{
  if (this->_objectptr->_obj->empty()) 
    return BasicVariable::ptr();
  else
  {
    T val = this->_objectptr->_obj->front();
    return AMILabType<T>::CreateVar(new T(val));
  }
}

//---------------------------------------------------
//  back
//---------------------------------------------------
template <class T>
void WrapClass_StdVector<T>::wrap_back::SetParametersComments() 
{
  return_comments = "Vector last element (variable).";
}
//---------------------------------------------------
template <class T>
BasicVariable::ptr WrapClass_StdVector<T>::wrap_back::CallMember( ParamList* p)
{
  if (this->_objectptr->_obj->empty()) 
    return BasicVariable::ptr();
  else
  {
    T val = this->_objectptr->_obj->back();
    return AMILabType<T>::CreateVar(new T(val));
  }
}


//---------------------------------------------------
//  at
//---------------------------------------------------
template <class T>
void WrapClass_StdVector<T>::wrap_at::SetParametersComments() 
{
  ADDPARAMCOMMENT("int   : vector position");
  return_comments = "Element at the given location if valid (variable).";
}
//---------------------------------------------------
template <class T>
BasicVariable::ptr WrapClass_StdVector<T>::wrap_at::CallMember( ParamList* p)
{

  int pos = 0;
  int n=0;
  if (!get_int_param(pos, p, n)) ClassHelpAndReturn;

  if ((pos<0)||(pos>=(int)this->_objectptr->_obj->size())) 
    return BasicVariable::ptr();
  else
  {
    T val = this->_objectptr->_obj->at(pos);
    return AMILabType<T>::CreateVar(new T(val));
  }
}

//---------------------------------------------------
//  clear
//---------------------------------------------------
template <class T>
void WrapClass_StdVector<T>::wrap_clear::SetParametersComments() {}
//---------------------------------------------------
template <class T>
BasicVariable::ptr WrapClass_StdVector<T>::wrap_clear::CallMember( ParamList* p)
{
  this->_objectptr->_obj->clear(); 
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  setelement
//---------------------------------------------------
template <class T>
void WrapClass_StdVector<T>::
      wrap_setelement::SetParametersComments() 
{
  ADDPARAMCOMMENT("Integer: position");
  ADDPARAMCOMMENT("Variable");
}
//---------------------------------------------------
template <class T>
BasicVariable::ptr WrapClass_StdVector<T>::
      wrap_setelement::CallMember( ParamList* p)
{
  int n = 0;
  int pos = 0;
  T var;

  if (!get_val_param<int>(pos, p, n)) ClassHelpAndReturn;
  if (!get_val_param<T>  (var, p, n)) ClassHelpAndReturn;

  if ((pos<0)||(pos>=(int)this->_objectptr->_obj->size())) 
    return BasicVariable::ptr();
  else
      (*this->_objectptr->_obj)[pos] = var;
  return BasicVariable::ptr();
}

/* TODO
//---------------------------------------------------
//  left_assign
//---------------------------------------------------
template <class T>
void WrapClass_StdVector<T>::
      wrap_left_assign::SetParametersComments() 
{
  ADDPARAMCOMMENT("Variable of type wrapped StdVector.");
}
//---------------------------------------------------
template <class T>
BasicVariable::ptr WrapClass_StdVector<T>::
      wrap_left_assign::CallMember( ParamList* p)
{
  int n = 0;
  CLASS_GET_OBJECT_PARAM(StdVector,_var,_obj);

  if (_obj.get()) {
    this->_objectptr->_obj = _obj;
  }
  return BasicVariable::ptr();
}
*/

//---------------------------------------------------
//  assign
//---------------------------------------------------
template <class T>
void WrapClass_StdVector<T>::
      wrap_assign::SetParametersComments() 
{
  ADDPARAMCOMMENT("Variable of type wrapped StdVector.");
}
//---------------------------------------------------
template <class T>
BasicVariable::ptr WrapClass_StdVector<T>::
      wrap_assign::CallMember( ParamList* p)
{
  int n = 0;
  Variable<AMIObject>::ptr lvar;
  boost::shared_ptr<std::vector<T> > lobj;
  get_obj_param<std::vector<T> >(lvar,lobj,p,n);

  if (lobj.get()) {
    *this->_objectptr->_obj = *lobj;
  }
  return BasicVariable::ptr();
}

