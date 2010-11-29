/**
 * C++ Interface: wrap_vtkScalarsToColors
 *
 * Description: wrapping vtkScalarsToColors
 * File generated automatically using CableSwig xml output and a python script
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

//#include "VarContexts.hpp"
#include "wrapfunctions.hpp"
#include "ami_class.h"
#include "ami_object.h"
#include "ami_function.h"

// get all the required includes
// #include "..."
#include "wrap_vtkScalarsToColors.h"
#include "wrap_vtkObjectBase.h"
#include "wrap_vtkIndent.h"
#include "wrap_vtkUnsignedCharArray.h"
#include "wrap_vtkDataArray.h"


#include "wrap_vtkScalarsToColors.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<vtkScalarsToColors>::CreateVar( ParamList* p)
{
  // No variable creation for an abstract class ...
  return BasicVariable::ptr();

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(vtkScalarsToColors);
AMI_DEFINE_VARFROMSMTPTR(vtkScalarsToColors);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<vtkScalarsToColors>::CreateVar( vtkScalarsToColors* val, bool nodeleter)
{ 
  boost::shared_ptr<vtkScalarsToColors> obj_ptr(val,smartpointer_nodeleter<vtkScalarsToColors>());
  return AMILabType<vtkScalarsToColors>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to vtkScalarsToColors
//
Variable<AMIObject>::ptr WrapClass_vtkScalarsToColors::CreateVar( vtkScalarsToColors* sp)
{
  boost::shared_ptr<vtkScalarsToColors> di_ptr(
    sp,
    wxwindow_nodeleter<vtkScalarsToColors>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<vtkScalarsToColors>::CreateVar(
      new WrapClass_vtkScalarsToColors(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_vtkScalarsToColors::AddMethods(WrapClass<vtkScalarsToColors>::ptr this_ptr )
{
  
      // Add members from vtkObject
      WrapClass_vtkObject::ptr parent_vtkObject(        boost::dynamic_pointer_cast<WrapClass_vtkObject >(this_ptr));
      parent_vtkObject->AddMethods(parent_vtkObject);


  // check that the method name is not a token
  
      // Adding standard methods 
      AddVar_IsA( this_ptr);
      AddVar_NewInstance( this_ptr);
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
      AddVar_PrintSelf( this_ptr);
*/
      AddVar_IsOpaque( this_ptr);
      AddVar_Build( this_ptr);
      AddVar_SetRange( this_ptr);
      AddVar_GetColor( this_ptr);
      AddVar_GetOpacity( this_ptr);
      AddVar_GetLuminance( this_ptr);
      AddVar_SetAlpha( this_ptr);
      AddVar_GetAlpha( this_ptr);
      AddVar_MapScalars( this_ptr);
      AddVar_SetVectorMode( this_ptr);
      AddVar_GetVectorMode( this_ptr);
      AddVar_SetVectorModeToMagnitude( this_ptr);
      AddVar_SetVectorModeToComponent( this_ptr);
      AddVar_SetVectorComponent( this_ptr);
      AddVar_GetVectorComponent( this_ptr);
      AddVar_MapScalarsThroughTable_1( this_ptr);
      AddVar_MapScalarsThroughTable( this_ptr);
      AddVar_MapScalarsThroughTable_2( this_ptr);
      AddVar_ConvertUnsignedCharToRGBA( this_ptr);
      AddVar_UsingLogScale( this_ptr);



  
};

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of int vtkScalarsToColors::IsTypeOf(char const * type)
//---------------------------------------------------
void WrapClass_vtkScalarsToColors::
    wrap_static_IsTypeOf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkScalarsToColors::
    wrap_static_IsTypeOf::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<std::string > type_string;
  if (!get_val_smtptr_param<std::string >(type_string,_p,_n,true,false,false)) ClassHelpAndReturn;
  char const * type = type_string->c_str();

  int res =   vtkScalarsToColors::IsTypeOf(type);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of vtkScalarsToColors * vtkScalarsToColors::SafeDownCast(vtkObjectBase * o)
//---------------------------------------------------
void WrapClass_vtkScalarsToColors::
    wrap_static_SafeDownCast::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkObjectBase, "parameter named 'o'")
  return_comments="returning a variable of type vtkScalarsToColors";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkScalarsToColors::
    wrap_static_SafeDownCast::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkObjectBase > o_smtptr;
  if (!get_val_smtptr_param<vtkObjectBase >(o_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkObjectBase* o = o_smtptr.get();

  vtkScalarsToColors * res =   vtkScalarsToColors::SafeDownCast(o);
  BasicVariable::ptr res_var = WrapClass_vtkScalarsToColors::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of int vtkScalarsToColors::IsA(char const * type)
//---------------------------------------------------
void WrapClass_vtkScalarsToColors::
    wrap_IsA::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkScalarsToColors::
    wrap_IsA::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<std::string > type_string;
  if (!get_val_smtptr_param<std::string >(type_string,_p,_n,true,false,false)) ClassHelpAndReturn;
  char const * type = type_string->c_str();

  int res =   this->_objectptr->GetObj()->IsA(type);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of vtkScalarsToColors * vtkScalarsToColors::NewInstance()
//---------------------------------------------------
void WrapClass_vtkScalarsToColors::
    wrap_NewInstance::SetParametersComments()
{
  return_comments="returning a variable of type vtkScalarsToColors";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkScalarsToColors::
    wrap_NewInstance::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkScalarsToColors * res =   this->_objectptr->GetObj()->NewInstance();
  BasicVariable::ptr res_var = WrapClass_vtkScalarsToColors::CreateVar(res);
  return res_var;
}
/* The following types are missing: basic_ostream<char,std::char_traits<char> >

//---------------------------------------------------
//  Wrapping of void vtkScalarsToColors::PrintSelf(ostream & os, vtkIndent indent)
//---------------------------------------------------
void WrapClass_vtkScalarsToColors::
    wrap_PrintSelf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( basic_ostream<char,std::char_traits<char> >, "parameter named 'os'")
  ADDPARAMCOMMENT_TYPE( vtkIndent, "parameter named 'indent'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkScalarsToColors::
    wrap_PrintSelf::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<basic_ostream<char,std::char_traits<char> > > os_smtptr;
  if (!get_val_smtptr_param<basic_ostream<char,std::char_traits<char> > >(os_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  ostream & os = *os_smtptr;

  vtkIndent indent;
  if (!get_val_param<vtkIndent >(indent,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->PrintSelf(os, indent);
  return BasicVariable::ptr();
}
*/

//---------------------------------------------------
//  Wrapping of int vtkScalarsToColors::IsOpaque()
//---------------------------------------------------
void WrapClass_vtkScalarsToColors::
    wrap_IsOpaque::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkScalarsToColors::
    wrap_IsOpaque::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->IsOpaque();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkScalarsToColors::Build()
//---------------------------------------------------
void WrapClass_vtkScalarsToColors::
    wrap_Build::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkScalarsToColors::
    wrap_Build::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Build();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkScalarsToColors::SetRange(double * rng)
//---------------------------------------------------
void WrapClass_vtkScalarsToColors::
    wrap_SetRange::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'rng'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkScalarsToColors::
    wrap_SetRange::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<double > rng_smtptr;
  if (!get_val_smtptr_param<double >(rng_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  double* rng = rng_smtptr.get();

  this->_objectptr->GetObj()->SetRange(rng);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of double * vtkScalarsToColors::GetColor(double v)
//---------------------------------------------------
void WrapClass_vtkScalarsToColors::
    wrap_GetColor::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'v'")
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkScalarsToColors::
    wrap_GetColor::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  double v;
  if (!get_val_param<double >(v,_p,_n,true,false)) ClassHelpAndReturn;

  double * res =   this->_objectptr->GetObj()->GetColor(v);
  return AMILabType<double >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of double vtkScalarsToColors::GetOpacity(double param0)
//---------------------------------------------------
void WrapClass_vtkScalarsToColors::
    wrap_GetOpacity::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'param0'")
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkScalarsToColors::
    wrap_GetOpacity::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  double param0;
  if (!get_val_param<double >(param0,_p,_n,true,false)) ClassHelpAndReturn;

  double res =   this->_objectptr->GetObj()->GetOpacity(param0);
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of double vtkScalarsToColors::GetLuminance(double x)
//---------------------------------------------------
void WrapClass_vtkScalarsToColors::
    wrap_GetLuminance::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'x'")
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkScalarsToColors::
    wrap_GetLuminance::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  double x;
  if (!get_val_param<double >(x,_p,_n,true,false)) ClassHelpAndReturn;

  double res =   this->_objectptr->GetObj()->GetLuminance(x);
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkScalarsToColors::SetAlpha(double alpha)
//---------------------------------------------------
void WrapClass_vtkScalarsToColors::
    wrap_SetAlpha::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'alpha'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkScalarsToColors::
    wrap_SetAlpha::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  double alpha;
  if (!get_val_param<double >(alpha,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetAlpha(alpha);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of double vtkScalarsToColors::GetAlpha()
//---------------------------------------------------
void WrapClass_vtkScalarsToColors::
    wrap_GetAlpha::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkScalarsToColors::
    wrap_GetAlpha::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  double res =   this->_objectptr->GetObj()->GetAlpha();
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of vtkUnsignedCharArray * vtkScalarsToColors::MapScalars(vtkDataArray * scalars, int colorMode, int component)
//---------------------------------------------------
void WrapClass_vtkScalarsToColors::
    wrap_MapScalars::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkDataArray, "parameter named 'scalars'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'colorMode'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'component'")
  return_comments="returning a variable of type vtkUnsignedCharArray";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkScalarsToColors::
    wrap_MapScalars::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>3) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkDataArray > scalars_smtptr;
  if (!get_val_smtptr_param<vtkDataArray >(scalars_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkDataArray* scalars = scalars_smtptr.get();

  int colorMode;
  if (!get_val_param<int >(colorMode,_p,_n,true,false)) ClassHelpAndReturn;

  int component;
  if (!get_val_param<int >(component,_p,_n,true,false)) ClassHelpAndReturn;

  vtkUnsignedCharArray * res =   this->_objectptr->GetObj()->MapScalars(scalars, colorMode, component);
  BasicVariable::ptr res_var = WrapClass_vtkUnsignedCharArray::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of void vtkScalarsToColors::SetVectorMode(int _arg)
//---------------------------------------------------
void WrapClass_vtkScalarsToColors::
    wrap_SetVectorMode::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkScalarsToColors::
    wrap_SetVectorMode::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int _arg;
  if (!get_val_param<int >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetVectorMode(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkScalarsToColors::GetVectorMode()
//---------------------------------------------------
void WrapClass_vtkScalarsToColors::
    wrap_GetVectorMode::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkScalarsToColors::
    wrap_GetVectorMode::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetVectorMode();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkScalarsToColors::SetVectorModeToMagnitude()
//---------------------------------------------------
void WrapClass_vtkScalarsToColors::
    wrap_SetVectorModeToMagnitude::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkScalarsToColors::
    wrap_SetVectorModeToMagnitude::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetVectorModeToMagnitude();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkScalarsToColors::SetVectorModeToComponent()
//---------------------------------------------------
void WrapClass_vtkScalarsToColors::
    wrap_SetVectorModeToComponent::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkScalarsToColors::
    wrap_SetVectorModeToComponent::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetVectorModeToComponent();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkScalarsToColors::SetVectorComponent(int _arg)
//---------------------------------------------------
void WrapClass_vtkScalarsToColors::
    wrap_SetVectorComponent::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkScalarsToColors::
    wrap_SetVectorComponent::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int _arg;
  if (!get_val_param<int >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetVectorComponent(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkScalarsToColors::GetVectorComponent()
//---------------------------------------------------
void WrapClass_vtkScalarsToColors::
    wrap_GetVectorComponent::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkScalarsToColors::
    wrap_GetVectorComponent::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetVectorComponent();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkScalarsToColors::MapScalarsThroughTable(vtkDataArray * scalars, unsigned char * output, int outputFormat)
//---------------------------------------------------
void WrapClass_vtkScalarsToColors::
    wrap_MapScalarsThroughTable_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkDataArray, "parameter named 'scalars'")
  ADDPARAMCOMMENT_TYPE( unsigned char, "parameter named 'output'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'outputFormat'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkScalarsToColors::
    wrap_MapScalarsThroughTable_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<vtkDataArray > scalars_smtptr;
  if (!get_val_smtptr_param<vtkDataArray >(scalars_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  vtkDataArray* scalars = scalars_smtptr.get();

  boost::shared_ptr<unsigned char > output_smtptr;
  if (!get_val_smtptr_param<unsigned char >(output_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  unsigned char* output = output_smtptr.get();

  int outputFormat;
  if (!get_val_param<int >(outputFormat,_p,_n,true,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->MapScalarsThroughTable(scalars, output, outputFormat);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkScalarsToColors::MapScalarsThroughTable(...)
//---------------------------------------------------
void WrapClass_vtkScalarsToColors::
    wrap_MapScalarsThroughTable::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkScalarsToColors::
    wrap_MapScalarsThroughTable::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkScalarsToColors::wrap_MapScalarsThroughTable_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkScalarsToColors::wrap_MapScalarsThroughTable_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkScalarsToColors::MapScalarsThroughTable(vtkDataArray * scalars, unsigned char * output)
//---------------------------------------------------
void WrapClass_vtkScalarsToColors::
    wrap_MapScalarsThroughTable_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkDataArray, "parameter named 'scalars'")
  ADDPARAMCOMMENT_TYPE( unsigned char, "parameter named 'output'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkScalarsToColors::
    wrap_MapScalarsThroughTable_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<vtkDataArray > scalars_smtptr;
  if (!get_val_smtptr_param<vtkDataArray >(scalars_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  vtkDataArray* scalars = scalars_smtptr.get();

  boost::shared_ptr<unsigned char > output_smtptr;
  if (!get_val_smtptr_param<unsigned char >(output_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  unsigned char* output = output_smtptr.get();

  this->_objectptr->GetObj()->MapScalarsThroughTable(scalars, output);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of vtkUnsignedCharArray * vtkScalarsToColors::ConvertUnsignedCharToRGBA(vtkUnsignedCharArray * colors, int numComp, int numTuples)
//---------------------------------------------------
void WrapClass_vtkScalarsToColors::
    wrap_ConvertUnsignedCharToRGBA::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkUnsignedCharArray, "parameter named 'colors'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'numComp'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'numTuples'")
  return_comments="returning a variable of type vtkUnsignedCharArray";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkScalarsToColors::
    wrap_ConvertUnsignedCharToRGBA::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>3) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkUnsignedCharArray > colors_smtptr;
  if (!get_val_smtptr_param<vtkUnsignedCharArray >(colors_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkUnsignedCharArray* colors = colors_smtptr.get();

  int numComp;
  if (!get_val_param<int >(numComp,_p,_n,true,false)) ClassHelpAndReturn;

  int numTuples;
  if (!get_val_param<int >(numTuples,_p,_n,true,false)) ClassHelpAndReturn;

  vtkUnsignedCharArray * res =   this->_objectptr->GetObj()->ConvertUnsignedCharToRGBA(colors, numComp, numTuples);
  BasicVariable::ptr res_var = WrapClass_vtkUnsignedCharArray::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of int vtkScalarsToColors::UsingLogScale()
//---------------------------------------------------
void WrapClass_vtkScalarsToColors::
    wrap_UsingLogScale::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkScalarsToColors::
    wrap_UsingLogScale::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->UsingLogScale();
  return AMILabType<int >::CreateVar(res);
}

