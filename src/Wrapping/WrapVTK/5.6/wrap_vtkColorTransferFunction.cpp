/**
 * C++ Interface: wrap_vtkColorTransferFunction
 *
 * Description: wrapping vtkColorTransferFunction
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
#include "wrap_vtkColorTransferFunction.h"
#include "wrap_vtkObjectBase.h"
#include "wrap_vtkIndent.h"


#include "wrap_vtkColorTransferFunction.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<vtkColorTransferFunction>::CreateVar( ParamList* p)
{
  WrapClass_vtkColorTransferFunction::wrap_static_New construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(vtkColorTransferFunction);
AMI_DEFINE_VARFROMSMTPTR(vtkColorTransferFunction);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<vtkColorTransferFunction>::CreateVar( vtkColorTransferFunction* val, bool nodeleter)
{ 
  boost::shared_ptr<vtkColorTransferFunction> obj_ptr(val,smartpointer_nodeleter<vtkColorTransferFunction>());
  return AMILabType<vtkColorTransferFunction>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to vtkColorTransferFunction
//
Variable<AMIObject>::ptr WrapClass_vtkColorTransferFunction::CreateVar( vtkColorTransferFunction* sp)
{
  boost::shared_ptr<vtkColorTransferFunction> di_ptr(
    sp,
    wxwindow_nodeleter<vtkColorTransferFunction>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<vtkColorTransferFunction>::CreateVar(
      new WrapClass_vtkColorTransferFunction(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_vtkColorTransferFunction::AddMethods(WrapClass<vtkColorTransferFunction>::ptr this_ptr )
{
  
      // Add members from vtkScalarsToColors
      WrapClass_vtkScalarsToColors::ptr parent_vtkScalarsToColors(        boost::dynamic_pointer_cast<WrapClass_vtkScalarsToColors >(this_ptr));
      parent_vtkScalarsToColors->AddMethods(parent_vtkScalarsToColors);


  // check that the method name is not a token
  
      // Adding standard methods 
      AddVar_IsA( this_ptr);
      AddVar_NewInstance( this_ptr);
      AddVar_DeepCopy( this_ptr);
      AddVar_ShallowCopy( this_ptr);
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
      AddVar_PrintSelf( this_ptr);
*/
      AddVar_GetSize( this_ptr);
      AddVar_AddRGBPoint_1( this_ptr);
      AddVar_AddRGBPoint( this_ptr);
      AddVar_AddRGBPoint_2( this_ptr);
      AddVar_AddHSVPoint_1( this_ptr);
      AddVar_AddHSVPoint( this_ptr);
      AddVar_AddHSVPoint_2( this_ptr);
      AddVar_RemovePoint( this_ptr);
      AddVar_AddRGBSegment( this_ptr);
      AddVar_AddHSVSegment( this_ptr);
      AddVar_RemoveAllPoints( this_ptr);
      AddVar_GetColor_1( this_ptr);
      AddVar_GetColor( this_ptr);
      AddVar_GetColor_2( this_ptr);
      AddVar_GetRedValue( this_ptr);
      AddVar_GetGreenValue( this_ptr);
      AddVar_GetBlueValue( this_ptr);
      AddVar_GetNodeValue( this_ptr);
      AddVar_SetNodeValue( this_ptr);
      AddVar_MapValue( this_ptr);
      AddVar_GetRange_1( this_ptr);
      AddVar_GetRange( this_ptr);
      AddVar_GetRange_2( this_ptr);
      AddVar_GetRange_3( this_ptr);
      AddVar_AdjustRange( this_ptr);
      AddVar_GetTable_1( this_ptr);
      AddVar_GetTable( this_ptr);
      AddVar_GetTable_2( this_ptr);
      AddVar_GetTable_3( this_ptr);
      AddVar_BuildFunctionFromTable( this_ptr);
      AddVar_SetClamping( this_ptr);
      AddVar_GetClampingMinValue( this_ptr);
      AddVar_GetClampingMaxValue( this_ptr);
      AddVar_GetClamping( this_ptr);
      AddVar_ClampingOn( this_ptr);
      AddVar_ClampingOff( this_ptr);
      AddVar_SetColorSpace( this_ptr);
      AddVar_GetColorSpaceMinValue( this_ptr);
      AddVar_GetColorSpaceMaxValue( this_ptr);
      AddVar_SetColorSpaceToRGB( this_ptr);
      AddVar_SetColorSpaceToHSV( this_ptr);
      AddVar_SetColorSpaceToLab( this_ptr);
      AddVar_SetColorSpaceToDiverging( this_ptr);
      AddVar_GetColorSpace( this_ptr);
      AddVar_SetHSVWrap( this_ptr);
      AddVar_GetHSVWrap( this_ptr);
      AddVar_HSVWrapOn( this_ptr);
      AddVar_HSVWrapOff( this_ptr);
      AddVar_SetScale( this_ptr);
      AddVar_SetScaleToLinear( this_ptr);
      AddVar_SetScaleToLog10( this_ptr);
      AddVar_GetScale( this_ptr);
      AddVar_GetDataPointer( this_ptr);
      AddVar_FillFromDataPointer( this_ptr);
/* The following types are missing: void
      AddVar_MapScalarsThroughTable2( this_ptr);
*/
      AddVar_SetAllowDuplicateScalars( this_ptr);
      AddVar_GetAllowDuplicateScalars( this_ptr);
      AddVar_AllowDuplicateScalarsOn( this_ptr);
      AddVar_AllowDuplicateScalarsOff( this_ptr);



  
};

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of vtkColorTransferFunction * vtkColorTransferFunction::New()
//---------------------------------------------------
void WrapClass_vtkColorTransferFunction::
    wrap_static_New::SetParametersComments()
{
  return_comments="returning a variable of type vtkColorTransferFunction";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkColorTransferFunction::
    wrap_static_New::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkColorTransferFunction * res =   vtkColorTransferFunction::New();
  BasicVariable::ptr res_var = WrapClass_vtkColorTransferFunction::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of int vtkColorTransferFunction::IsTypeOf(char const * type)
//---------------------------------------------------
void WrapClass_vtkColorTransferFunction::
    wrap_static_IsTypeOf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkColorTransferFunction::
    wrap_static_IsTypeOf::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<std::string > type_string;
  if (!get_val_smtptr_param<std::string >(type_string,_p,_n,true,false,false)) ClassHelpAndReturn;
  char const * type = type_string->c_str();

  int res =   vtkColorTransferFunction::IsTypeOf(type);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of vtkColorTransferFunction * vtkColorTransferFunction::SafeDownCast(vtkObjectBase * o)
//---------------------------------------------------
void WrapClass_vtkColorTransferFunction::
    wrap_static_SafeDownCast::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkObjectBase, "parameter named 'o'")
  return_comments="returning a variable of type vtkColorTransferFunction";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkColorTransferFunction::
    wrap_static_SafeDownCast::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkObjectBase > o_smtptr;
  if (!get_val_smtptr_param<vtkObjectBase >(o_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkObjectBase* o = o_smtptr.get();

  vtkColorTransferFunction * res =   vtkColorTransferFunction::SafeDownCast(o);
  BasicVariable::ptr res_var = WrapClass_vtkColorTransferFunction::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of int vtkColorTransferFunction::IsA(char const * type)
//---------------------------------------------------
void WrapClass_vtkColorTransferFunction::
    wrap_IsA::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkColorTransferFunction::
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
//  Wrapping of vtkColorTransferFunction * vtkColorTransferFunction::NewInstance()
//---------------------------------------------------
void WrapClass_vtkColorTransferFunction::
    wrap_NewInstance::SetParametersComments()
{
  return_comments="returning a variable of type vtkColorTransferFunction";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkColorTransferFunction::
    wrap_NewInstance::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkColorTransferFunction * res =   this->_objectptr->GetObj()->NewInstance();
  BasicVariable::ptr res_var = WrapClass_vtkColorTransferFunction::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of void vtkColorTransferFunction::DeepCopy(vtkColorTransferFunction * f)
//---------------------------------------------------
void WrapClass_vtkColorTransferFunction::
    wrap_DeepCopy::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkColorTransferFunction, "parameter named 'f'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkColorTransferFunction::
    wrap_DeepCopy::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkColorTransferFunction > f_smtptr;
  if (!get_val_smtptr_param<vtkColorTransferFunction >(f_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkColorTransferFunction* f = f_smtptr.get();

  this->_objectptr->GetObj()->DeepCopy(f);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkColorTransferFunction::ShallowCopy(vtkColorTransferFunction * f)
//---------------------------------------------------
void WrapClass_vtkColorTransferFunction::
    wrap_ShallowCopy::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkColorTransferFunction, "parameter named 'f'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkColorTransferFunction::
    wrap_ShallowCopy::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkColorTransferFunction > f_smtptr;
  if (!get_val_smtptr_param<vtkColorTransferFunction >(f_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkColorTransferFunction* f = f_smtptr.get();

  this->_objectptr->GetObj()->ShallowCopy(f);
  return BasicVariable::ptr();
}
/* The following types are missing: basic_ostream<char,std::char_traits<char> >

//---------------------------------------------------
//  Wrapping of void vtkColorTransferFunction::PrintSelf(ostream & os, vtkIndent indent)
//---------------------------------------------------
void WrapClass_vtkColorTransferFunction::
    wrap_PrintSelf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( basic_ostream<char,std::char_traits<char> >, "parameter named 'os'")
  ADDPARAMCOMMENT_TYPE( vtkIndent, "parameter named 'indent'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkColorTransferFunction::
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
//  Wrapping of int vtkColorTransferFunction::GetSize()
//---------------------------------------------------
void WrapClass_vtkColorTransferFunction::
    wrap_GetSize::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkColorTransferFunction::
    wrap_GetSize::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetSize();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int vtkColorTransferFunction::AddRGBPoint(double x, double r, double g, double b)
//---------------------------------------------------
void WrapClass_vtkColorTransferFunction::
    wrap_AddRGBPoint_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'r'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'g'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'b'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkColorTransferFunction::
    wrap_AddRGBPoint_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>4) ClassReturnEmptyVar;
  int _n=0;

  double x;
  if (!get_val_param<double >(x,_p,_n,true,true)) ClassReturnEmptyVar;

  double r;
  if (!get_val_param<double >(r,_p,_n,true,true)) ClassReturnEmptyVar;

  double g;
  if (!get_val_param<double >(g,_p,_n,true,true)) ClassReturnEmptyVar;

  double b;
  if (!get_val_param<double >(b,_p,_n,true,true)) ClassReturnEmptyVar;

  int res =   this->_objectptr->GetObj()->AddRGBPoint(x, r, g, b);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkColorTransferFunction::AddRGBPoint(...)
//---------------------------------------------------
void WrapClass_vtkColorTransferFunction::
    wrap_AddRGBPoint::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkColorTransferFunction::
    wrap_AddRGBPoint::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkColorTransferFunction::wrap_AddRGBPoint_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkColorTransferFunction::wrap_AddRGBPoint_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of int vtkColorTransferFunction::AddRGBPoint(double x, double r, double g, double b, double midpoint, double sharpness)
//---------------------------------------------------
void WrapClass_vtkColorTransferFunction::
    wrap_AddRGBPoint_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'r'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'g'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'b'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'midpoint'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'sharpness'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkColorTransferFunction::
    wrap_AddRGBPoint_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>6) ClassReturnEmptyVar;
  int _n=0;

  double x;
  if (!get_val_param<double >(x,_p,_n,true,true)) ClassReturnEmptyVar;

  double r;
  if (!get_val_param<double >(r,_p,_n,true,true)) ClassReturnEmptyVar;

  double g;
  if (!get_val_param<double >(g,_p,_n,true,true)) ClassReturnEmptyVar;

  double b;
  if (!get_val_param<double >(b,_p,_n,true,true)) ClassReturnEmptyVar;

  double midpoint;
  if (!get_val_param<double >(midpoint,_p,_n,true,true)) ClassReturnEmptyVar;

  double sharpness;
  if (!get_val_param<double >(sharpness,_p,_n,true,true)) ClassReturnEmptyVar;

  int res =   this->_objectptr->GetObj()->AddRGBPoint(x, r, g, b, midpoint, sharpness);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int vtkColorTransferFunction::AddHSVPoint(double x, double h, double s, double v)
//---------------------------------------------------
void WrapClass_vtkColorTransferFunction::
    wrap_AddHSVPoint_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'h'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 's'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'v'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkColorTransferFunction::
    wrap_AddHSVPoint_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>4) ClassReturnEmptyVar;
  int _n=0;

  double x;
  if (!get_val_param<double >(x,_p,_n,true,true)) ClassReturnEmptyVar;

  double h;
  if (!get_val_param<double >(h,_p,_n,true,true)) ClassReturnEmptyVar;

  double s;
  if (!get_val_param<double >(s,_p,_n,true,true)) ClassReturnEmptyVar;

  double v;
  if (!get_val_param<double >(v,_p,_n,true,true)) ClassReturnEmptyVar;

  int res =   this->_objectptr->GetObj()->AddHSVPoint(x, h, s, v);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkColorTransferFunction::AddHSVPoint(...)
//---------------------------------------------------
void WrapClass_vtkColorTransferFunction::
    wrap_AddHSVPoint::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkColorTransferFunction::
    wrap_AddHSVPoint::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkColorTransferFunction::wrap_AddHSVPoint_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkColorTransferFunction::wrap_AddHSVPoint_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of int vtkColorTransferFunction::AddHSVPoint(double x, double h, double s, double v, double midpoint, double sharpness)
//---------------------------------------------------
void WrapClass_vtkColorTransferFunction::
    wrap_AddHSVPoint_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'h'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 's'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'v'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'midpoint'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'sharpness'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkColorTransferFunction::
    wrap_AddHSVPoint_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>6) ClassReturnEmptyVar;
  int _n=0;

  double x;
  if (!get_val_param<double >(x,_p,_n,true,true)) ClassReturnEmptyVar;

  double h;
  if (!get_val_param<double >(h,_p,_n,true,true)) ClassReturnEmptyVar;

  double s;
  if (!get_val_param<double >(s,_p,_n,true,true)) ClassReturnEmptyVar;

  double v;
  if (!get_val_param<double >(v,_p,_n,true,true)) ClassReturnEmptyVar;

  double midpoint;
  if (!get_val_param<double >(midpoint,_p,_n,true,true)) ClassReturnEmptyVar;

  double sharpness;
  if (!get_val_param<double >(sharpness,_p,_n,true,true)) ClassReturnEmptyVar;

  int res =   this->_objectptr->GetObj()->AddHSVPoint(x, h, s, v, midpoint, sharpness);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int vtkColorTransferFunction::RemovePoint(double x)
//---------------------------------------------------
void WrapClass_vtkColorTransferFunction::
    wrap_RemovePoint::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'x'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkColorTransferFunction::
    wrap_RemovePoint::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  double x;
  if (!get_val_param<double >(x,_p,_n,true,false)) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->RemovePoint(x);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkColorTransferFunction::AddRGBSegment(double x1, double r1, double g1, double b1, double x2, double r2, double g2, double b2)
//---------------------------------------------------
void WrapClass_vtkColorTransferFunction::
    wrap_AddRGBSegment::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'x1'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'r1'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'g1'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'b1'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'x2'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'r2'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'g2'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'b2'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkColorTransferFunction::
    wrap_AddRGBSegment::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>8) ClassHelpAndReturn;
  int _n=0;

  double x1;
  if (!get_val_param<double >(x1,_p,_n,true,false)) ClassHelpAndReturn;

  double r1;
  if (!get_val_param<double >(r1,_p,_n,true,false)) ClassHelpAndReturn;

  double g1;
  if (!get_val_param<double >(g1,_p,_n,true,false)) ClassHelpAndReturn;

  double b1;
  if (!get_val_param<double >(b1,_p,_n,true,false)) ClassHelpAndReturn;

  double x2;
  if (!get_val_param<double >(x2,_p,_n,true,false)) ClassHelpAndReturn;

  double r2;
  if (!get_val_param<double >(r2,_p,_n,true,false)) ClassHelpAndReturn;

  double g2;
  if (!get_val_param<double >(g2,_p,_n,true,false)) ClassHelpAndReturn;

  double b2;
  if (!get_val_param<double >(b2,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->AddRGBSegment(x1, r1, g1, b1, x2, r2, g2, b2);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkColorTransferFunction::AddHSVSegment(double x1, double h1, double s1, double v1, double x2, double h2, double s2, double v2)
//---------------------------------------------------
void WrapClass_vtkColorTransferFunction::
    wrap_AddHSVSegment::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'x1'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'h1'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 's1'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'v1'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'x2'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'h2'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 's2'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'v2'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkColorTransferFunction::
    wrap_AddHSVSegment::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>8) ClassHelpAndReturn;
  int _n=0;

  double x1;
  if (!get_val_param<double >(x1,_p,_n,true,false)) ClassHelpAndReturn;

  double h1;
  if (!get_val_param<double >(h1,_p,_n,true,false)) ClassHelpAndReturn;

  double s1;
  if (!get_val_param<double >(s1,_p,_n,true,false)) ClassHelpAndReturn;

  double v1;
  if (!get_val_param<double >(v1,_p,_n,true,false)) ClassHelpAndReturn;

  double x2;
  if (!get_val_param<double >(x2,_p,_n,true,false)) ClassHelpAndReturn;

  double h2;
  if (!get_val_param<double >(h2,_p,_n,true,false)) ClassHelpAndReturn;

  double s2;
  if (!get_val_param<double >(s2,_p,_n,true,false)) ClassHelpAndReturn;

  double v2;
  if (!get_val_param<double >(v2,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->AddHSVSegment(x1, h1, s1, v1, x2, h2, s2, v2);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkColorTransferFunction::RemoveAllPoints()
//---------------------------------------------------
void WrapClass_vtkColorTransferFunction::
    wrap_RemoveAllPoints::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkColorTransferFunction::
    wrap_RemoveAllPoints::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->RemoveAllPoints();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of double * vtkColorTransferFunction::GetColor(double x)
//---------------------------------------------------
void WrapClass_vtkColorTransferFunction::
    wrap_GetColor_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'x'")
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkColorTransferFunction::
    wrap_GetColor_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  double x;
  if (!get_val_param<double >(x,_p,_n,true,true)) ClassReturnEmptyVar;

  double * res =   this->_objectptr->GetObj()->GetColor(x);
  return AMILabType<double >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkColorTransferFunction::GetColor(...)
//---------------------------------------------------
void WrapClass_vtkColorTransferFunction::
    wrap_GetColor::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkColorTransferFunction::
    wrap_GetColor::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkColorTransferFunction::wrap_GetColor_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkColorTransferFunction::wrap_GetColor_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkColorTransferFunction::GetColor(double x, double * rgb)
//---------------------------------------------------
void WrapClass_vtkColorTransferFunction::
    wrap_GetColor_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'rgb'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkColorTransferFunction::
    wrap_GetColor_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  double x;
  if (!get_val_param<double >(x,_p,_n,true,true)) ClassReturnEmptyVar;

  boost::shared_ptr<double > rgb_smtptr;
  if (!get_val_smtptr_param<double >(rgb_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  double* rgb = rgb_smtptr.get();

  this->_objectptr->GetObj()->GetColor(x, rgb);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of double vtkColorTransferFunction::GetRedValue(double x)
//---------------------------------------------------
void WrapClass_vtkColorTransferFunction::
    wrap_GetRedValue::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'x'")
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkColorTransferFunction::
    wrap_GetRedValue::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  double x;
  if (!get_val_param<double >(x,_p,_n,true,false)) ClassHelpAndReturn;

  double res =   this->_objectptr->GetObj()->GetRedValue(x);
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of double vtkColorTransferFunction::GetGreenValue(double x)
//---------------------------------------------------
void WrapClass_vtkColorTransferFunction::
    wrap_GetGreenValue::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'x'")
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkColorTransferFunction::
    wrap_GetGreenValue::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  double x;
  if (!get_val_param<double >(x,_p,_n,true,false)) ClassHelpAndReturn;

  double res =   this->_objectptr->GetObj()->GetGreenValue(x);
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of double vtkColorTransferFunction::GetBlueValue(double x)
//---------------------------------------------------
void WrapClass_vtkColorTransferFunction::
    wrap_GetBlueValue::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'x'")
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkColorTransferFunction::
    wrap_GetBlueValue::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  double x;
  if (!get_val_param<double >(x,_p,_n,true,false)) ClassHelpAndReturn;

  double res =   this->_objectptr->GetObj()->GetBlueValue(x);
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int vtkColorTransferFunction::GetNodeValue(int index, double * val)
//---------------------------------------------------
void WrapClass_vtkColorTransferFunction::
    wrap_GetNodeValue::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'index'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'val'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkColorTransferFunction::
    wrap_GetNodeValue::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  int index;
  if (!get_val_param<int >(index,_p,_n,true,false)) ClassHelpAndReturn;

  boost::shared_ptr<double > val_smtptr;
  if (!get_val_smtptr_param<double >(val_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  double* val = val_smtptr.get();

  int res =   this->_objectptr->GetObj()->GetNodeValue(index, val);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int vtkColorTransferFunction::SetNodeValue(int index, double * val)
//---------------------------------------------------
void WrapClass_vtkColorTransferFunction::
    wrap_SetNodeValue::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'index'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'val'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkColorTransferFunction::
    wrap_SetNodeValue::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  int index;
  if (!get_val_param<int >(index,_p,_n,true,false)) ClassHelpAndReturn;

  boost::shared_ptr<double > val_smtptr;
  if (!get_val_smtptr_param<double >(val_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  double* val = val_smtptr.get();

  int res =   this->_objectptr->GetObj()->SetNodeValue(index, val);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of unsigned char * vtkColorTransferFunction::MapValue(double v)
//---------------------------------------------------
void WrapClass_vtkColorTransferFunction::
    wrap_MapValue::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'v'")
  return_comments="returning a variable of type unsigned char";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkColorTransferFunction::
    wrap_MapValue::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  double v;
  if (!get_val_param<double >(v,_p,_n,true,false)) ClassHelpAndReturn;

  unsigned char * res =   this->_objectptr->GetObj()->MapValue(v);
  return AMILabType<unsigned char >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of double * vtkColorTransferFunction::GetRange()
//---------------------------------------------------
void WrapClass_vtkColorTransferFunction::
    wrap_GetRange_1::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkColorTransferFunction::
    wrap_GetRange_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  double * res =   this->_objectptr->GetObj()->GetRange();
  return AMILabType<double >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkColorTransferFunction::GetRange(...)
//---------------------------------------------------
void WrapClass_vtkColorTransferFunction::
    wrap_GetRange::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkColorTransferFunction::
    wrap_GetRange::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkColorTransferFunction::wrap_GetRange_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkColorTransferFunction::wrap_GetRange_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_vtkColorTransferFunction::wrap_GetRange_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkColorTransferFunction::GetRange(double & _arg1, double & _arg2)
//---------------------------------------------------
void WrapClass_vtkColorTransferFunction::
    wrap_GetRange_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg1'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg2'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkColorTransferFunction::
    wrap_GetRange_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<double > _arg1_smtptr;
  if (!get_val_smtptr_param<double >(_arg1_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  double & _arg1 = *_arg1_smtptr;

  boost::shared_ptr<double > _arg2_smtptr;
  if (!get_val_smtptr_param<double >(_arg2_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  double & _arg2 = *_arg2_smtptr;

  this->_objectptr->GetObj()->GetRange(_arg1, _arg2);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkColorTransferFunction::GetRange(double * _arg)
//---------------------------------------------------
void WrapClass_vtkColorTransferFunction::
    wrap_GetRange_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkColorTransferFunction::
    wrap_GetRange_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<double > _arg_smtptr;
  if (!get_val_smtptr_param<double >(_arg_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  double* _arg = _arg_smtptr.get();

  this->_objectptr->GetObj()->GetRange(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkColorTransferFunction::AdjustRange(double * range)
//---------------------------------------------------
void WrapClass_vtkColorTransferFunction::
    wrap_AdjustRange::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'range'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkColorTransferFunction::
    wrap_AdjustRange::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<double > range_smtptr;
  if (!get_val_smtptr_param<double >(range_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  double* range = range_smtptr.get();

  int res =   this->_objectptr->GetObj()->AdjustRange(range);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkColorTransferFunction::GetTable(double x1, double x2, int n, double * table)
//---------------------------------------------------
void WrapClass_vtkColorTransferFunction::
    wrap_GetTable_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'x1'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'x2'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'n'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'table'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkColorTransferFunction::
    wrap_GetTable_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>4) ClassReturnEmptyVar;
  int _n=0;

  double x1;
  if (!get_val_param<double >(x1,_p,_n,true,true)) ClassReturnEmptyVar;

  double x2;
  if (!get_val_param<double >(x2,_p,_n,true,true)) ClassReturnEmptyVar;

  int n;
  if (!get_val_param<int >(n,_p,_n,true,true)) ClassReturnEmptyVar;

  boost::shared_ptr<double > table_smtptr;
  if (!get_val_smtptr_param<double >(table_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  double* table = table_smtptr.get();

  this->_objectptr->GetObj()->GetTable(x1, x2, n, table);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkColorTransferFunction::GetTable(...)
//---------------------------------------------------
void WrapClass_vtkColorTransferFunction::
    wrap_GetTable::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkColorTransferFunction::
    wrap_GetTable::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkColorTransferFunction::wrap_GetTable_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkColorTransferFunction::wrap_GetTable_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_vtkColorTransferFunction::wrap_GetTable_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkColorTransferFunction::GetTable(double x1, double x2, int n, float * table)
//---------------------------------------------------
void WrapClass_vtkColorTransferFunction::
    wrap_GetTable_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'x1'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'x2'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'n'")
  ADDPARAMCOMMENT_TYPE( float, "parameter named 'table'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkColorTransferFunction::
    wrap_GetTable_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>4) ClassReturnEmptyVar;
  int _n=0;

  double x1;
  if (!get_val_param<double >(x1,_p,_n,true,true)) ClassReturnEmptyVar;

  double x2;
  if (!get_val_param<double >(x2,_p,_n,true,true)) ClassReturnEmptyVar;

  int n;
  if (!get_val_param<int >(n,_p,_n,true,true)) ClassReturnEmptyVar;

  boost::shared_ptr<float > table_smtptr;
  if (!get_val_smtptr_param<float >(table_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  float* table = table_smtptr.get();

  this->_objectptr->GetObj()->GetTable(x1, x2, n, table);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of unsigned char const * vtkColorTransferFunction::GetTable(double x1, double x2, int n)
//---------------------------------------------------
void WrapClass_vtkColorTransferFunction::
    wrap_GetTable_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'x1'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'x2'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'n'")
  return_comments="returning a variable of type unsigned char";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkColorTransferFunction::
    wrap_GetTable_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  double x1;
  if (!get_val_param<double >(x1,_p,_n,true,true)) ClassReturnEmptyVar;

  double x2;
  if (!get_val_param<double >(x2,_p,_n,true,true)) ClassReturnEmptyVar;

  int n;
  if (!get_val_param<int >(n,_p,_n,true,true)) ClassReturnEmptyVar;

  unsigned char const * res =   this->_objectptr->GetObj()->GetTable(x1, x2, n);
  return AMILabType<unsigned char >::CreateVar(const_cast<unsigned char *>(res),true);
}

//---------------------------------------------------
//  Wrapping of void vtkColorTransferFunction::BuildFunctionFromTable(double x1, double x2, int size, double * table)
//---------------------------------------------------
void WrapClass_vtkColorTransferFunction::
    wrap_BuildFunctionFromTable::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'x1'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'x2'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'size'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'table'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkColorTransferFunction::
    wrap_BuildFunctionFromTable::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>4) ClassHelpAndReturn;
  int _n=0;

  double x1;
  if (!get_val_param<double >(x1,_p,_n,true,false)) ClassHelpAndReturn;

  double x2;
  if (!get_val_param<double >(x2,_p,_n,true,false)) ClassHelpAndReturn;

  int size;
  if (!get_val_param<int >(size,_p,_n,true,false)) ClassHelpAndReturn;

  boost::shared_ptr<double > table_smtptr;
  if (!get_val_smtptr_param<double >(table_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  double* table = table_smtptr.get();

  this->_objectptr->GetObj()->BuildFunctionFromTable(x1, x2, size, table);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkColorTransferFunction::SetClamping(int _arg)
//---------------------------------------------------
void WrapClass_vtkColorTransferFunction::
    wrap_SetClamping::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkColorTransferFunction::
    wrap_SetClamping::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int _arg;
  if (!get_val_param<int >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetClamping(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkColorTransferFunction::GetClampingMinValue()
//---------------------------------------------------
void WrapClass_vtkColorTransferFunction::
    wrap_GetClampingMinValue::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkColorTransferFunction::
    wrap_GetClampingMinValue::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetClampingMinValue();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int vtkColorTransferFunction::GetClampingMaxValue()
//---------------------------------------------------
void WrapClass_vtkColorTransferFunction::
    wrap_GetClampingMaxValue::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkColorTransferFunction::
    wrap_GetClampingMaxValue::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetClampingMaxValue();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int vtkColorTransferFunction::GetClamping()
//---------------------------------------------------
void WrapClass_vtkColorTransferFunction::
    wrap_GetClamping::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkColorTransferFunction::
    wrap_GetClamping::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetClamping();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkColorTransferFunction::ClampingOn()
//---------------------------------------------------
void WrapClass_vtkColorTransferFunction::
    wrap_ClampingOn::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkColorTransferFunction::
    wrap_ClampingOn::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->ClampingOn();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkColorTransferFunction::ClampingOff()
//---------------------------------------------------
void WrapClass_vtkColorTransferFunction::
    wrap_ClampingOff::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkColorTransferFunction::
    wrap_ClampingOff::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->ClampingOff();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkColorTransferFunction::SetColorSpace(int _arg)
//---------------------------------------------------
void WrapClass_vtkColorTransferFunction::
    wrap_SetColorSpace::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkColorTransferFunction::
    wrap_SetColorSpace::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int _arg;
  if (!get_val_param<int >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetColorSpace(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkColorTransferFunction::GetColorSpaceMinValue()
//---------------------------------------------------
void WrapClass_vtkColorTransferFunction::
    wrap_GetColorSpaceMinValue::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkColorTransferFunction::
    wrap_GetColorSpaceMinValue::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetColorSpaceMinValue();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int vtkColorTransferFunction::GetColorSpaceMaxValue()
//---------------------------------------------------
void WrapClass_vtkColorTransferFunction::
    wrap_GetColorSpaceMaxValue::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkColorTransferFunction::
    wrap_GetColorSpaceMaxValue::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetColorSpaceMaxValue();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkColorTransferFunction::SetColorSpaceToRGB()
//---------------------------------------------------
void WrapClass_vtkColorTransferFunction::
    wrap_SetColorSpaceToRGB::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkColorTransferFunction::
    wrap_SetColorSpaceToRGB::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetColorSpaceToRGB();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkColorTransferFunction::SetColorSpaceToHSV()
//---------------------------------------------------
void WrapClass_vtkColorTransferFunction::
    wrap_SetColorSpaceToHSV::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkColorTransferFunction::
    wrap_SetColorSpaceToHSV::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetColorSpaceToHSV();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkColorTransferFunction::SetColorSpaceToLab()
//---------------------------------------------------
void WrapClass_vtkColorTransferFunction::
    wrap_SetColorSpaceToLab::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkColorTransferFunction::
    wrap_SetColorSpaceToLab::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetColorSpaceToLab();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkColorTransferFunction::SetColorSpaceToDiverging()
//---------------------------------------------------
void WrapClass_vtkColorTransferFunction::
    wrap_SetColorSpaceToDiverging::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkColorTransferFunction::
    wrap_SetColorSpaceToDiverging::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetColorSpaceToDiverging();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkColorTransferFunction::GetColorSpace()
//---------------------------------------------------
void WrapClass_vtkColorTransferFunction::
    wrap_GetColorSpace::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkColorTransferFunction::
    wrap_GetColorSpace::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetColorSpace();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkColorTransferFunction::SetHSVWrap(int _arg)
//---------------------------------------------------
void WrapClass_vtkColorTransferFunction::
    wrap_SetHSVWrap::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkColorTransferFunction::
    wrap_SetHSVWrap::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int _arg;
  if (!get_val_param<int >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetHSVWrap(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkColorTransferFunction::GetHSVWrap()
//---------------------------------------------------
void WrapClass_vtkColorTransferFunction::
    wrap_GetHSVWrap::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkColorTransferFunction::
    wrap_GetHSVWrap::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetHSVWrap();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkColorTransferFunction::HSVWrapOn()
//---------------------------------------------------
void WrapClass_vtkColorTransferFunction::
    wrap_HSVWrapOn::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkColorTransferFunction::
    wrap_HSVWrapOn::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->HSVWrapOn();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkColorTransferFunction::HSVWrapOff()
//---------------------------------------------------
void WrapClass_vtkColorTransferFunction::
    wrap_HSVWrapOff::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkColorTransferFunction::
    wrap_HSVWrapOff::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->HSVWrapOff();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkColorTransferFunction::SetScale(int _arg)
//---------------------------------------------------
void WrapClass_vtkColorTransferFunction::
    wrap_SetScale::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkColorTransferFunction::
    wrap_SetScale::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int _arg;
  if (!get_val_param<int >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetScale(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkColorTransferFunction::SetScaleToLinear()
//---------------------------------------------------
void WrapClass_vtkColorTransferFunction::
    wrap_SetScaleToLinear::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkColorTransferFunction::
    wrap_SetScaleToLinear::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetScaleToLinear();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkColorTransferFunction::SetScaleToLog10()
//---------------------------------------------------
void WrapClass_vtkColorTransferFunction::
    wrap_SetScaleToLog10::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkColorTransferFunction::
    wrap_SetScaleToLog10::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetScaleToLog10();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkColorTransferFunction::GetScale()
//---------------------------------------------------
void WrapClass_vtkColorTransferFunction::
    wrap_GetScale::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkColorTransferFunction::
    wrap_GetScale::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetScale();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of double * vtkColorTransferFunction::GetDataPointer()
//---------------------------------------------------
void WrapClass_vtkColorTransferFunction::
    wrap_GetDataPointer::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkColorTransferFunction::
    wrap_GetDataPointer::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  double * res =   this->_objectptr->GetObj()->GetDataPointer();
  return AMILabType<double >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of void vtkColorTransferFunction::FillFromDataPointer(int param0, double * param1)
//---------------------------------------------------
void WrapClass_vtkColorTransferFunction::
    wrap_FillFromDataPointer::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'param0'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'param1'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkColorTransferFunction::
    wrap_FillFromDataPointer::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  int param0;
  if (!get_val_param<int >(param0,_p,_n,true,false)) ClassHelpAndReturn;

  boost::shared_ptr<double > param1_smtptr;
  if (!get_val_smtptr_param<double >(param1_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  double* param1 = param1_smtptr.get();

  this->_objectptr->GetObj()->FillFromDataPointer(param0, param1);
  return BasicVariable::ptr();
}
/* The following types are missing: void

//---------------------------------------------------
//  Wrapping of void vtkColorTransferFunction::MapScalarsThroughTable2(void * input, unsigned char * output, int inputDataType, int numberOfValues, int inputIncrement, int outputIncrement)
//---------------------------------------------------
void WrapClass_vtkColorTransferFunction::
    wrap_MapScalarsThroughTable2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( void, "parameter named 'input'")
  ADDPARAMCOMMENT_TYPE( unsigned char, "parameter named 'output'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'inputDataType'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'numberOfValues'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'inputIncrement'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'outputIncrement'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkColorTransferFunction::
    wrap_MapScalarsThroughTable2::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>6) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<void > input_smtptr;
  if (!get_val_smtptr_param<void >(input_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  void* input = input_smtptr.get();

  boost::shared_ptr<unsigned char > output_smtptr;
  if (!get_val_smtptr_param<unsigned char >(output_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  unsigned char* output = output_smtptr.get();

  int inputDataType;
  if (!get_val_param<int >(inputDataType,_p,_n,true,false)) ClassHelpAndReturn;

  int numberOfValues;
  if (!get_val_param<int >(numberOfValues,_p,_n,true,false)) ClassHelpAndReturn;

  int inputIncrement;
  if (!get_val_param<int >(inputIncrement,_p,_n,true,false)) ClassHelpAndReturn;

  int outputIncrement;
  if (!get_val_param<int >(outputIncrement,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->MapScalarsThroughTable2(input, output, inputDataType, numberOfValues, inputIncrement, outputIncrement);
  return BasicVariable::ptr();
}
*/

//---------------------------------------------------
//  Wrapping of void vtkColorTransferFunction::SetAllowDuplicateScalars(int _arg)
//---------------------------------------------------
void WrapClass_vtkColorTransferFunction::
    wrap_SetAllowDuplicateScalars::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkColorTransferFunction::
    wrap_SetAllowDuplicateScalars::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int _arg;
  if (!get_val_param<int >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetAllowDuplicateScalars(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkColorTransferFunction::GetAllowDuplicateScalars()
//---------------------------------------------------
void WrapClass_vtkColorTransferFunction::
    wrap_GetAllowDuplicateScalars::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkColorTransferFunction::
    wrap_GetAllowDuplicateScalars::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetAllowDuplicateScalars();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkColorTransferFunction::AllowDuplicateScalarsOn()
//---------------------------------------------------
void WrapClass_vtkColorTransferFunction::
    wrap_AllowDuplicateScalarsOn::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkColorTransferFunction::
    wrap_AllowDuplicateScalarsOn::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->AllowDuplicateScalarsOn();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkColorTransferFunction::AllowDuplicateScalarsOff()
//---------------------------------------------------
void WrapClass_vtkColorTransferFunction::
    wrap_AllowDuplicateScalarsOff::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkColorTransferFunction::
    wrap_AllowDuplicateScalarsOff::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->AllowDuplicateScalarsOff();
  return BasicVariable::ptr();
}

