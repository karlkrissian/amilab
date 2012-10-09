/**
 * C++ Interface: wrap_ContinuousMorphology
 *
 * Description: wrapping ContinuousMorphology
 *
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#include "wrap_ContinuousMorphology.h"

#include "wrapfunctions.hpp"
#include "ami_class.h"
#include "ami_object.h"
#include "ami_function.h"
#include "wrapfunction_class.h"



//-------------------------------------------------------------------------
AMIObject::ptr AddWrap_ContinuousMorphology(  WrapClass_ContinuousMorphology::ptr& objectptr)
{
  // Create new instance of the class
  AMIObject::ptr amiobject( new AMIObject);
  amiobject->SetName("ContinuousMorphology");
  amiobject->SetWrappedObject(objectptr);
  objectptr->SetAMIObject(amiobject);
  objectptr->AddMethods( objectptr);
  return amiobject;
}

//----------------------------------------------------------
Variable<AMIObject>::ptr CreateVar_ContinuousMorphology( ContinuousMorphology* _obj)
{
  // Create smart pointer with own deleter
  boost::shared_ptr<ContinuousMorphology> _obj_ptr( _obj );

  WrapClass_ContinuousMorphology::ptr _objp(new WrapClass_ContinuousMorphology(_obj_ptr));
  AMIObject::ptr amiobject(AddWrap_ContinuousMorphology(_objp));
  Variable<AMIObject>::ptr varres(
      new Variable<AMIObject>( amiobject));
  return varres;
}

//---------------------------------------------------
// Method that adds wrapping of ContinuousMorphology
//---------------------------------------------------

void  wrap_ContinuousMorphology::SetParametersComments() 
{
  return_comments = "A wrapped ContinuousMorphology object.";
}

//---------------------------------------------------
BasicVariable::ptr wrap_ContinuousMorphology::CallMember( ParamList* p)
{
  return CreateVar_ContinuousMorphology(new ContinuousMorphology());
}

//---------------------------------------------------
//  SetScheme
//---------------------------------------------------
void WrapClass_ContinuousMorphology::
      wrap_SetScheme::SetParametersComments() 
{
  ADDPARAMCOMMENT_TYPE(int,"Type the scheme (1:Osher & Sethian, 2:Brockett & Maragos, 3:Experimental)");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_ContinuousMorphology::
      wrap_SetScheme::CallMember( ParamList* p)
{
  boost::shared_ptr<ContinuousMorphology> oCM(this->_objectptr->GetObj());

  if (!p) ClassHelpAndReturn;
  int n=0;
  GET_PARAM(int,scheme,1);

  oCM->SetScheme(scheme);

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  SetLimits
//---------------------------------------------------
void WrapClass_ContinuousMorphology::
      wrap_SetLimits::SetParametersComments() 
{
  ADDPARAMCOMMENT_TYPE(float,"Lower limit.");
  ADDPARAMCOMMENT_TYPE(float,"Upper limit.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_ContinuousMorphology::
      wrap_SetLimits::CallMember( ParamList* p)
{
  boost::shared_ptr<ContinuousMorphology> oCM(this->_objectptr->GetObj());

  if (!p) ClassHelpAndReturn;
  int n=0;
  GET_PARAM(int,lower,0);
  GET_PARAM(int,upper,0);

  oCM->SetLimits(lower,upper);

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  EDP
//---------------------------------------------------
void WrapClass_ContinuousMorphology::
      wrap_EDP::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE(InrImage,"A image.");
  ADDPARAMCOMMENT_TYPE(float,"Image size.");
  ADDPARAMCOMMENT_TYPE(float,"Number of step.");
  ADDPARAMCOMMENT_TYPE(int,"Type of operation to be performed.");
  return_comments = "A new image morphological.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_ContinuousMorphology::
      wrap_EDP::CallMember( ParamList* p)
{
  boost::shared_ptr<ContinuousMorphology> oCM(this->_objectptr->GetObj());

  Variable<InrImage>::ptr varim;

  if (!p) ClassHelpAndReturn;
  int n=0;
  if (!get_var_param<InrImage>(varim,p,n)) ClassHelpAndReturn;
  GET_PARAM(float,size,0);
  GET_PARAM(float,step,0);
  GET_PARAM(int,type,0);

  InrImage::ptr image(varim->Pointer());

  if (image.get())
    return Variable<InrImage>::ptr(
      new Variable<InrImage>(InrImage::ptr(oCM->EDP(image.get(),size,step,type))));
  else
    ClassHelpAndReturn;

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Dilate
//---------------------------------------------------
void WrapClass_ContinuousMorphology::
      wrap_Dilate::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE(InrImage,"A image.");
  ADDPARAMCOMMENT_TYPE(float,"Image size.");
  ADDPARAMCOMMENT_TYPE(float,"Number of step.");
  return_comments = "A new image morphological greyscale dilatation.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_ContinuousMorphology::
      wrap_Dilate::CallMember( ParamList* p)
{
  boost::shared_ptr<ContinuousMorphology> oCM(this->_objectptr->GetObj());

  Variable<InrImage>::ptr varim;

  if (!p) ClassHelpAndReturn;
  int n=0;
  if (!get_var_param<InrImage>(varim,p,n)) ClassHelpAndReturn;
  GET_PARAM(float,size,0);
  GET_PARAM(float,step,0);

  InrImage::ptr image(varim->Pointer());

  if (image.get())
    return Variable<InrImage>::ptr(
      new Variable<InrImage>(InrImage::ptr(oCM->Dilate(image.get(),size,step))));
  else
    ClassHelpAndReturn;

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Erode
//---------------------------------------------------
void WrapClass_ContinuousMorphology::
      wrap_Erode::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE(InrImage,"A image.");
  ADDPARAMCOMMENT_TYPE(float,"Image size.");
  ADDPARAMCOMMENT_TYPE(float,"Number of step.");
  return_comments = "A new image morphological greyscale erosion.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_ContinuousMorphology::
      wrap_Erode::CallMember( ParamList* p)
{
  boost::shared_ptr<ContinuousMorphology> oCM(this->_objectptr->GetObj());

  Variable<InrImage>::ptr varim;

  if (!p) ClassHelpAndReturn;
  int n=0;
  if (!get_var_param<InrImage>(varim,p,n)) ClassHelpAndReturn;
  GET_PARAM(float,size,0);
  GET_PARAM(float,step,0);

  InrImage::ptr image(varim->Pointer());

  if (image.get())
    return Variable<InrImage>::ptr(
      new Variable<InrImage>(InrImage::ptr(oCM->Erode(image.get(),size,step))));
  else
    ClassHelpAndReturn;

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Open
//---------------------------------------------------
void WrapClass_ContinuousMorphology::
      wrap_Open::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE(InrImage,"A image.");
  ADDPARAMCOMMENT_TYPE(float,"Image size.");
  ADDPARAMCOMMENT_TYPE(float,"Number of step.");
  return_comments = "A new image morphological greyscale opening.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_ContinuousMorphology::
      wrap_Open::CallMember( ParamList* p)
{
  boost::shared_ptr<ContinuousMorphology> oCM(this->_objectptr->GetObj());

  Variable<InrImage>::ptr varim;

  if (!p) ClassHelpAndReturn;
  int n=0;
  if (!get_var_param<InrImage>(varim,p,n)) ClassHelpAndReturn;
  GET_PARAM(float,size,0);
  GET_PARAM(float,step,0);

  InrImage::ptr image(varim->Pointer());

  if (image.get())
    return Variable<InrImage>::ptr(
      new Variable<InrImage>(InrImage::ptr(oCM->Open(image.get(),size,step))));
  else
    ClassHelpAndReturn;

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Close
//---------------------------------------------------
void WrapClass_ContinuousMorphology::
      wrap_Close::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE(InrImage,"A image.");
  ADDPARAMCOMMENT_TYPE(float,"Image size.");
  ADDPARAMCOMMENT_TYPE(float,"Number of step.");
  return_comments = "A new image morphological greyscale closing.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_ContinuousMorphology::
      wrap_Close::CallMember( ParamList* p)
{
  boost::shared_ptr<ContinuousMorphology> oCM(this->_objectptr->GetObj());

  Variable<InrImage>::ptr varim;

  if (!p) ClassHelpAndReturn;
  int n=0;
  if (!get_var_param<InrImage>(varim,p,n)) ClassHelpAndReturn;
  GET_PARAM(float,size,0);
  GET_PARAM(float,step,0);

  InrImage::ptr image(varim->Pointer());

  if (image.get())
    return Variable<InrImage>::ptr(
      new Variable<InrImage>(InrImage::ptr(oCM->Close(image.get(),size,step))));
  else
    ClassHelpAndReturn;

  return BasicVariable::ptr();
}