//
// C++ Implementation: wrap_ImageExtent
//
// Description: 
//
//
// Author: Karl Krissian <krissian@dis.ulpgc.es>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//

#include "wrap_ImageExtent.h"

#include "VarContexts.hpp"
#include "wrapfunctions.hpp"
#include "ami_class.h"
#include "ami_object.h"
#include "ami_function.h"

//-------------------------------------------------------------------------
AMIObject::ptr AddWrap_ImageExtent(  WrapClass_ImageExtent::ptr& objectptr)
{
  // Create new instance of the class
  AMIObject::ptr amiobject( new AMIObject);
  amiobject->SetName("ImageExtent");
  amiobject->SetWrappedObject(objectptr);
  objectptr->SetAMIObject(amiobject);
  objectptr->AddMethods( objectptr);
  return amiobject;
}

//----------------------------------------------------------
Variable<AMIObject>::ptr CreateVar_ImageExtent( ImageExtent<float>* si)
{
  // here ImageExtent can be deleted
  boost::shared_ptr<ImageExtent<float> > si_ptr( si );
  WrapClass_ImageExtent::ptr sip(new WrapClass_ImageExtent(si_ptr));
  AMIObject::ptr amiobject(AddWrap_ImageExtent(sip));
  Variable<AMIObject>::ptr varres(
      new Variable<AMIObject>( amiobject));
  return varres;
}

//---------------------------------------------------
//  ImageExtent Constructor
//---------------------------------------------------
void  wrap_ImageExtent::SetParametersComments() 
{
  return_comments = "A wrapped ImageExtent<float> object.";
}
//---------------------------------------------------
BasicVariable::ptr wrap_ImageExtent::CallMember( ParamList* p)
{
  if (!p) ClassHelpAndReturn;
  return CreateVar_ImageExtent(new ImageExtent<float>());
}

//---------------------------------------------------
//  Xmin
//---------------------------------------------------
void WrapClass_ImageExtent::wrap_Xmin::SetParametersComments() 
{
  return_comments = "float: minimum position in X";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_ImageExtent::
        wrap_Xmin::CallMember( ParamList* p)
{
  RETURN_VAR(float,_objectptr->_obj->Xmin());
}

//---------------------------------------------------
//  Xmax
//---------------------------------------------------
void WrapClass_ImageExtent::wrap_Xmax::SetParametersComments() 
{
  return_comments = "float: maximum position in X";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_ImageExtent::
        wrap_Xmax::CallMember( ParamList* p)
{
  RETURN_VAR(float,_objectptr->_obj->Xmax());
}

//---------------------------------------------------
//  Ymin
//---------------------------------------------------
void WrapClass_ImageExtent::wrap_Ymin::SetParametersComments() 
{
  return_comments = "float: minimum position in Y";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_ImageExtent::
        wrap_Ymin::CallMember( ParamList* p)
{
  RETURN_VAR(float,_objectptr->_obj->Ymin());
}

//---------------------------------------------------
//  Ymax
//---------------------------------------------------
void WrapClass_ImageExtent::wrap_Ymax::SetParametersComments() 
{
  return_comments = "float: maximum position in Y";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_ImageExtent::
        wrap_Ymax::CallMember( ParamList* p)
{
  RETURN_VAR(float,_objectptr->_obj->Ymax());
}

//---------------------------------------------------
//  Zmin
//---------------------------------------------------
void WrapClass_ImageExtent::wrap_Zmin::SetParametersComments() 
{
  return_comments = "float: minimum position in Z";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_ImageExtent::
        wrap_Zmin::CallMember( ParamList* p)
{
  RETURN_VAR(float,_objectptr->_obj->Zmin());
}

//---------------------------------------------------
//  Zmax
//---------------------------------------------------
void WrapClass_ImageExtent::wrap_Zmax::SetParametersComments() 
{
  return_comments = "float: maximum position in Z";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_ImageExtent::
        wrap_Zmax::CallMember( ParamList* p)
{
  RETURN_VAR(float,_objectptr->_obj->Zmax());
}

//---------------------------------------------------
//  SetXmin
//---------------------------------------------------
void WrapClass_ImageExtent::wrap_SetXmin::SetParametersComments() 
{
  ADDPARAMCOMMENT("float: minimal position in X.");
  return_comments = "float: new minimal position in X";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_ImageExtent::
        wrap_SetXmin::CallMember( ParamList* p)
{
  float minx  = 0;
  int n = 0;
  if (!get_val_param<float>( minx, p, n)) ClassHelpAndReturn;
  _objectptr->_obj->SetXmin(minx);
  RETURN_VAR(float,_objectptr->_obj->Xmin());
}

//---------------------------------------------------
//  SetXmax
//---------------------------------------------------
void WrapClass_ImageExtent::wrap_SetXmax::SetParametersComments() 
{
  ADDPARAMCOMMENT("float: maximal position in X.");
  return_comments = "float: new maximal position in X";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_ImageExtent::
        wrap_SetXmax::CallMember( ParamList* p)
{
  float maxx  = 0;
  int n = 0;
  if (!get_val_param<float>( maxx, p, n)) ClassHelpAndReturn;
  _objectptr->_obj->SetXmax(maxx);
  RETURN_VAR(float,_objectptr->_obj->Xmax());
}

//---------------------------------------------------
//  SetYmin
//---------------------------------------------------
void WrapClass_ImageExtent::wrap_SetYmin::SetParametersComments() 
{
  ADDPARAMCOMMENT("float: minimal position in Y.");
  return_comments = "float: new minimal position in Y";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_ImageExtent::
        wrap_SetYmin::CallMember( ParamList* p)
{
  float miny  = 0;
  int n = 0;
  if (!get_val_param<float>( miny, p, n)) ClassHelpAndReturn;
  _objectptr->_obj->SetYmin(miny);
  RETURN_VAR(float,_objectptr->_obj->Ymin());
}

//---------------------------------------------------
//  SetYmax
//---------------------------------------------------
void WrapClass_ImageExtent::wrap_SetYmax::SetParametersComments() 
{
  ADDPARAMCOMMENT("float: maximal position in Y.");
  return_comments = "float: new maximal position in Y";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_ImageExtent::
        wrap_SetYmax::CallMember( ParamList* p)
{
  float maxy  = 0;
  int n = 0;
  if (!get_val_param<float>( maxy, p, n)) ClassHelpAndReturn;
  _objectptr->_obj->SetYmax(maxy);
  RETURN_VAR(float,_objectptr->_obj->Ymax());
}

//---------------------------------------------------
//  SetZmin
//---------------------------------------------------
void WrapClass_ImageExtent::wrap_SetZmin::SetParametersComments() 
{
  ADDPARAMCOMMENT("float: minimal position in Z.");
  return_comments = "float: new minimal position in Z";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_ImageExtent::
        wrap_SetZmin::CallMember( ParamList* p)
{
  float minz  = 0;
  int n = 0;
  if (!get_val_param<float>( minz, p, n)) ClassHelpAndReturn;
  _objectptr->_obj->SetZmin(minz);
  RETURN_VAR(float,_objectptr->_obj->Zmin());
}

//---------------------------------------------------
//  SetZmax
//---------------------------------------------------
void WrapClass_ImageExtent::wrap_SetZmax::SetParametersComments() 
{
  ADDPARAMCOMMENT("float: maximal position in Z.");
  return_comments = "float: new maximal position in Z";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_ImageExtent::
        wrap_SetZmax::CallMember( ParamList* p)
{
  float maxz  = 0;
  int n = 0;
  if (!get_val_param<float>( maxz, p, n)) ClassHelpAndReturn;
  _objectptr->_obj->SetZmax(maxz);
  RETURN_VAR(float,_objectptr->_obj->Zmax());
}

//---------------------------------------------------
//  print
//---------------------------------------------------
void WrapClass_ImageExtent::wrap_print::SetParametersComments() 
{}
//---------------------------------------------------
BasicVariable::ptr WrapClass_ImageExtent::
        wrap_print::CallMember( ParamList* p)
{
  _objectptr->_obj->print();
  return BasicVariable::ptr();
}
