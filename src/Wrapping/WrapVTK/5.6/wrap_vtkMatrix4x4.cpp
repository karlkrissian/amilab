/**
 * C++ Interface: wrap_vtkMatrix4x4
 *
 * Description: wrapping vtkMatrix4x4
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
#include "wrap_vtkMatrix4x4.h"
#include "wrap_vtkObjectBase.h"
#include "wrap_vtkIndent.h"
#include "boost/numeric/conversion/cast.hpp"


#include "wrap_vtkMatrix4x4.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<vtkMatrix4x4>::CreateVar( ParamList* p)
{
  WrapClass_vtkMatrix4x4::wrap_static_New construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(vtkMatrix4x4);
AMI_DEFINE_VARFROMSMTPTR(vtkMatrix4x4);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<vtkMatrix4x4>::CreateVar( vtkMatrix4x4* val, bool nodeleter)
{ 
  boost::shared_ptr<vtkMatrix4x4> obj_ptr(val,smartpointer_nodeleter<vtkMatrix4x4>());
  return AMILabType<vtkMatrix4x4>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to vtkMatrix4x4
//
Variable<AMIObject>::ptr WrapClass_vtkMatrix4x4::CreateVar( vtkMatrix4x4* sp)
{
  boost::shared_ptr<vtkMatrix4x4> di_ptr(
    sp,
    wxwindow_nodeleter<vtkMatrix4x4>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<vtkMatrix4x4>::CreateVar(
      new WrapClass_vtkMatrix4x4(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_vtkMatrix4x4::AddMethods(WrapClass<vtkMatrix4x4>::ptr this_ptr )
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
      AddVar_DeepCopy_1( this_ptr);
      AddVar_DeepCopy( this_ptr);
      AddVar_DeepCopy_2( this_ptr);
      AddVar_Zero( this_ptr);
      AddVar_Identity( this_ptr);
      AddVar_Invert_1( this_ptr);
      AddVar_Transpose_1( this_ptr);
      AddVar_MultiplyPoint_1( this_ptr);
      AddVar_MultiplyPoint( this_ptr);
      AddVar_MultiplyPoint_2( this_ptr);
      AddVar_MultiplyPoint_3( this_ptr);
      AddVar_MultiplyFloatPoint( this_ptr);
      AddVar_MultiplyDoublePoint( this_ptr);
      AddVar_Adjoint_1( this_ptr);
      AddVar_Determinant_1( this_ptr);
      AddVar_SetElement( this_ptr);
      AddVar_GetElement( this_ptr);
      AddVar_Adjoint( this_ptr);
      AddVar_Adjoint_2( this_ptr);
      AddVar_Determinant( this_ptr);
      AddVar_Determinant_2( this_ptr);
      AddVar_Determinant_3( this_ptr);
      AddVar_Invert( this_ptr);
      AddVar_Invert_2( this_ptr);
      AddVar_Transpose( this_ptr);
      AddVar_Transpose_2( this_ptr);

      // Adding operators
      AddVar___at___1( this_ptr);
      AddVar___at__( this_ptr);
      AddVar___at___2( this_ptr);



  // Add public fields
      AMIObject::ptr tmpobj(amiobject.lock());
      if (!tmpobj.get()) return;
      Variables::ptr context(tmpobj->GetContext());
      
      /* type not available
      // Adding public member Element
      boost::shared_ptr< > var_Element_ptr(&GetObj()->Element, smartpointer_nodeleter< >());
      if (var_Element_ptr.get()) {
        BasicVariable::ptr var_Element = AMILabType< >::CreateVarFromSmtPtr(var_Element_ptr);
        if (var_Element.get()) {
          var_Element->Rename("Element");
          context->AddVar(var_Element,context);
        }
      }
      */

};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClass_vtkMatrix4x4::AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("vtkMatrix4x4");
  
  // Static methods 
  WrapClass_vtkMatrix4x4::AddVar_New(amiobject->GetContext());
  WrapClass_vtkMatrix4x4::AddVar_IsTypeOf(amiobject->GetContext());
  WrapClass_vtkMatrix4x4::AddVar_SafeDownCast(amiobject->GetContext());
  WrapClass_vtkMatrix4x4::AddVar_DeepCopy_1(amiobject->GetContext());
  WrapClass_vtkMatrix4x4::AddVar_DeepCopy(amiobject->GetContext());
  WrapClass_vtkMatrix4x4::AddVar_DeepCopy_2(amiobject->GetContext());
  WrapClass_vtkMatrix4x4::AddVar_Zero(amiobject->GetContext());
  WrapClass_vtkMatrix4x4::AddVar_Identity(amiobject->GetContext());
  WrapClass_vtkMatrix4x4::AddVar_Invert_1(amiobject->GetContext());
  WrapClass_vtkMatrix4x4::AddVar_Invert(amiobject->GetContext());
  WrapClass_vtkMatrix4x4::AddVar_Invert_2(amiobject->GetContext());
  WrapClass_vtkMatrix4x4::AddVar_Transpose_1(amiobject->GetContext());
  WrapClass_vtkMatrix4x4::AddVar_Transpose(amiobject->GetContext());
  WrapClass_vtkMatrix4x4::AddVar_Transpose_2(amiobject->GetContext());
  WrapClass_vtkMatrix4x4::AddVar_MultiplyPoint_1(amiobject->GetContext());
  WrapClass_vtkMatrix4x4::AddVar_MultiplyPoint(amiobject->GetContext());
  WrapClass_vtkMatrix4x4::AddVar_MultiplyPoint_2(amiobject->GetContext());
  WrapClass_vtkMatrix4x4::AddVar_Multiply4x4_1(amiobject->GetContext());
  WrapClass_vtkMatrix4x4::AddVar_Multiply4x4(amiobject->GetContext());
  WrapClass_vtkMatrix4x4::AddVar_Multiply4x4_2(amiobject->GetContext());
  WrapClass_vtkMatrix4x4::AddVar_Adjoint(amiobject->GetContext());
  WrapClass_vtkMatrix4x4::AddVar_Determinant(amiobject->GetContext());
  WrapClass_vtkMatrix4x4::AddVar_PointMultiply_1(amiobject->GetContext());
  WrapClass_vtkMatrix4x4::AddVar_PointMultiply(amiobject->GetContext());
  WrapClass_vtkMatrix4x4::AddVar_PointMultiply_2(amiobject->GetContext());

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of vtkMatrix4x4 * vtkMatrix4x4::New()
//---------------------------------------------------
void WrapClass_vtkMatrix4x4::
    wrap_static_New::SetParametersComments()
{
  return_comments="returning a variable of type vtkMatrix4x4";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMatrix4x4::
    wrap_static_New::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkMatrix4x4 * res =   vtkMatrix4x4::New();
  BasicVariable::ptr res_var = WrapClass_vtkMatrix4x4::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of int vtkMatrix4x4::IsTypeOf(char const * type)
//---------------------------------------------------
void WrapClass_vtkMatrix4x4::
    wrap_static_IsTypeOf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMatrix4x4::
    wrap_static_IsTypeOf::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<std::string > type_string;
  if (!get_val_smtptr_param<std::string >(type_string,_p,_n,true,false,false)) ClassHelpAndReturn;
  char const * type = type_string->c_str();

  int res =   vtkMatrix4x4::IsTypeOf(type);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of vtkMatrix4x4 * vtkMatrix4x4::SafeDownCast(vtkObjectBase * o)
//---------------------------------------------------
void WrapClass_vtkMatrix4x4::
    wrap_static_SafeDownCast::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkObjectBase, "parameter named 'o'")
  return_comments="returning a variable of type vtkMatrix4x4";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMatrix4x4::
    wrap_static_SafeDownCast::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkObjectBase > o_smtptr;
  if (!get_val_smtptr_param<vtkObjectBase >(o_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkObjectBase* o = o_smtptr.get();

  vtkMatrix4x4 * res =   vtkMatrix4x4::SafeDownCast(o);
  BasicVariable::ptr res_var = WrapClass_vtkMatrix4x4::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of void vtkMatrix4x4::DeepCopy(double * Elements, vtkMatrix4x4 * source)
//---------------------------------------------------
void WrapClass_vtkMatrix4x4::
    wrap_static_DeepCopy_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'Elements'")
  ADDPARAMCOMMENT_TYPE( vtkMatrix4x4, "parameter named 'source'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMatrix4x4::
    wrap_static_DeepCopy_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<double > Elements_smtptr;
  if (!get_val_smtptr_param<double >(Elements_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  double* Elements = Elements_smtptr.get();

  boost::shared_ptr<vtkMatrix4x4 > source_smtptr;
  if (!get_val_smtptr_param<vtkMatrix4x4 >(source_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  vtkMatrix4x4* source = source_smtptr.get();

  vtkMatrix4x4::DeepCopy(Elements, source);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... static vtkMatrix4x4::DeepCopy(...)
//---------------------------------------------------
void WrapClass_vtkMatrix4x4::
    wrap_static_DeepCopy::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMatrix4x4::
    wrap_static_DeepCopy::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkMatrix4x4::wrap_static_DeepCopy_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkMatrix4x4::wrap_static_DeepCopy_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkMatrix4x4::DeepCopy(double * Elements, double const * newElements)
//---------------------------------------------------
void WrapClass_vtkMatrix4x4::
    wrap_static_DeepCopy_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'Elements'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'newElements'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMatrix4x4::
    wrap_static_DeepCopy_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<double > Elements_smtptr;
  if (!get_val_smtptr_param<double >(Elements_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  double* Elements = Elements_smtptr.get();

  boost::shared_ptr<double > newElements_smtptr;
  if (!get_val_smtptr_param<double >(newElements_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  double* newElements = newElements_smtptr.get();

  vtkMatrix4x4::DeepCopy(Elements, newElements);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkMatrix4x4::Zero(double * Elements)
//---------------------------------------------------
void WrapClass_vtkMatrix4x4::
    wrap_static_Zero::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'Elements'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMatrix4x4::
    wrap_static_Zero::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<double > Elements_smtptr;
  if (!get_val_smtptr_param<double >(Elements_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  double* Elements = Elements_smtptr.get();

  vtkMatrix4x4::Zero(Elements);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkMatrix4x4::Identity(double * Elements)
//---------------------------------------------------
void WrapClass_vtkMatrix4x4::
    wrap_static_Identity::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'Elements'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMatrix4x4::
    wrap_static_Identity::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<double > Elements_smtptr;
  if (!get_val_smtptr_param<double >(Elements_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  double* Elements = Elements_smtptr.get();

  vtkMatrix4x4::Identity(Elements);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkMatrix4x4::Invert(vtkMatrix4x4 * in, vtkMatrix4x4 * out)
//---------------------------------------------------
void WrapClass_vtkMatrix4x4::
    wrap_static_Invert_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkMatrix4x4, "parameter named 'in'")
  ADDPARAMCOMMENT_TYPE( vtkMatrix4x4, "parameter named 'out'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMatrix4x4::
    wrap_static_Invert_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<vtkMatrix4x4 > in_smtptr;
  if (!get_val_smtptr_param<vtkMatrix4x4 >(in_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  vtkMatrix4x4* in = in_smtptr.get();

  boost::shared_ptr<vtkMatrix4x4 > out_smtptr;
  if (!get_val_smtptr_param<vtkMatrix4x4 >(out_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  vtkMatrix4x4* out = out_smtptr.get();

  vtkMatrix4x4::Invert(in, out);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... static vtkMatrix4x4::Invert(...)
//---------------------------------------------------
void WrapClass_vtkMatrix4x4::
    wrap_static_Invert::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMatrix4x4::
    wrap_static_Invert::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkMatrix4x4::wrap_static_Invert_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkMatrix4x4::wrap_static_Invert_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkMatrix4x4::Invert(double const * inElements, double * outElements)
//---------------------------------------------------
void WrapClass_vtkMatrix4x4::
    wrap_static_Invert_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'inElements'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'outElements'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMatrix4x4::
    wrap_static_Invert_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<double > inElements_smtptr;
  if (!get_val_smtptr_param<double >(inElements_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  double* inElements = inElements_smtptr.get();

  boost::shared_ptr<double > outElements_smtptr;
  if (!get_val_smtptr_param<double >(outElements_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  double* outElements = outElements_smtptr.get();

  vtkMatrix4x4::Invert(inElements, outElements);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkMatrix4x4::Transpose(vtkMatrix4x4 * in, vtkMatrix4x4 * out)
//---------------------------------------------------
void WrapClass_vtkMatrix4x4::
    wrap_static_Transpose_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkMatrix4x4, "parameter named 'in'")
  ADDPARAMCOMMENT_TYPE( vtkMatrix4x4, "parameter named 'out'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMatrix4x4::
    wrap_static_Transpose_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<vtkMatrix4x4 > in_smtptr;
  if (!get_val_smtptr_param<vtkMatrix4x4 >(in_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  vtkMatrix4x4* in = in_smtptr.get();

  boost::shared_ptr<vtkMatrix4x4 > out_smtptr;
  if (!get_val_smtptr_param<vtkMatrix4x4 >(out_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  vtkMatrix4x4* out = out_smtptr.get();

  vtkMatrix4x4::Transpose(in, out);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... static vtkMatrix4x4::Transpose(...)
//---------------------------------------------------
void WrapClass_vtkMatrix4x4::
    wrap_static_Transpose::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMatrix4x4::
    wrap_static_Transpose::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkMatrix4x4::wrap_static_Transpose_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkMatrix4x4::wrap_static_Transpose_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkMatrix4x4::Transpose(double const * inElements, double * outElements)
//---------------------------------------------------
void WrapClass_vtkMatrix4x4::
    wrap_static_Transpose_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'inElements'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'outElements'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMatrix4x4::
    wrap_static_Transpose_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<double > inElements_smtptr;
  if (!get_val_smtptr_param<double >(inElements_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  double* inElements = inElements_smtptr.get();

  boost::shared_ptr<double > outElements_smtptr;
  if (!get_val_smtptr_param<double >(outElements_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  double* outElements = outElements_smtptr.get();

  vtkMatrix4x4::Transpose(inElements, outElements);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkMatrix4x4::MultiplyPoint(double const * Elements, float const * in, float * out)
//---------------------------------------------------
void WrapClass_vtkMatrix4x4::
    wrap_static_MultiplyPoint_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'Elements'")
  ADDPARAMCOMMENT_TYPE( float, "parameter named 'in'")
  ADDPARAMCOMMENT_TYPE( float, "parameter named 'out'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMatrix4x4::
    wrap_static_MultiplyPoint_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<double > Elements_smtptr;
  if (!get_val_smtptr_param<double >(Elements_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  double* Elements = Elements_smtptr.get();

  boost::shared_ptr<float > in_smtptr;
  if (!get_val_smtptr_param<float >(in_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  float* in = in_smtptr.get();

  boost::shared_ptr<float > out_smtptr;
  if (!get_val_smtptr_param<float >(out_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  float* out = out_smtptr.get();

  vtkMatrix4x4::MultiplyPoint(Elements, in, out);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... static vtkMatrix4x4::MultiplyPoint(...)
//---------------------------------------------------
void WrapClass_vtkMatrix4x4::
    wrap_static_MultiplyPoint::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMatrix4x4::
    wrap_static_MultiplyPoint::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkMatrix4x4::wrap_static_MultiplyPoint_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkMatrix4x4::wrap_static_MultiplyPoint_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkMatrix4x4::MultiplyPoint(double const * Elements, double const * in, double * out)
//---------------------------------------------------
void WrapClass_vtkMatrix4x4::
    wrap_static_MultiplyPoint_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'Elements'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'in'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'out'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMatrix4x4::
    wrap_static_MultiplyPoint_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<double > Elements_smtptr;
  if (!get_val_smtptr_param<double >(Elements_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  double* Elements = Elements_smtptr.get();

  boost::shared_ptr<double > in_smtptr;
  if (!get_val_smtptr_param<double >(in_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  double* in = in_smtptr.get();

  boost::shared_ptr<double > out_smtptr;
  if (!get_val_smtptr_param<double >(out_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  double* out = out_smtptr.get();

  vtkMatrix4x4::MultiplyPoint(Elements, in, out);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkMatrix4x4::Multiply4x4(vtkMatrix4x4 * a, vtkMatrix4x4 * b, vtkMatrix4x4 * c)
//---------------------------------------------------
void WrapClass_vtkMatrix4x4::
    wrap_static_Multiply4x4_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkMatrix4x4, "parameter named 'a'")
  ADDPARAMCOMMENT_TYPE( vtkMatrix4x4, "parameter named 'b'")
  ADDPARAMCOMMENT_TYPE( vtkMatrix4x4, "parameter named 'c'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMatrix4x4::
    wrap_static_Multiply4x4_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<vtkMatrix4x4 > a_smtptr;
  if (!get_val_smtptr_param<vtkMatrix4x4 >(a_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  vtkMatrix4x4* a = a_smtptr.get();

  boost::shared_ptr<vtkMatrix4x4 > b_smtptr;
  if (!get_val_smtptr_param<vtkMatrix4x4 >(b_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  vtkMatrix4x4* b = b_smtptr.get();

  boost::shared_ptr<vtkMatrix4x4 > c_smtptr;
  if (!get_val_smtptr_param<vtkMatrix4x4 >(c_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  vtkMatrix4x4* c = c_smtptr.get();

  vtkMatrix4x4::Multiply4x4(a, b, c);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... static vtkMatrix4x4::Multiply4x4(...)
//---------------------------------------------------
void WrapClass_vtkMatrix4x4::
    wrap_static_Multiply4x4::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMatrix4x4::
    wrap_static_Multiply4x4::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkMatrix4x4::wrap_static_Multiply4x4_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkMatrix4x4::wrap_static_Multiply4x4_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkMatrix4x4::Multiply4x4(double const * a, double const * b, double * c)
//---------------------------------------------------
void WrapClass_vtkMatrix4x4::
    wrap_static_Multiply4x4_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'a'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'b'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'c'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMatrix4x4::
    wrap_static_Multiply4x4_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<double > a_smtptr;
  if (!get_val_smtptr_param<double >(a_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  double* a = a_smtptr.get();

  boost::shared_ptr<double > b_smtptr;
  if (!get_val_smtptr_param<double >(b_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  double* b = b_smtptr.get();

  boost::shared_ptr<double > c_smtptr;
  if (!get_val_smtptr_param<double >(c_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  double* c = c_smtptr.get();

  vtkMatrix4x4::Multiply4x4(a, b, c);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkMatrix4x4::Adjoint(double const * inElements, double * outElements)
//---------------------------------------------------
void WrapClass_vtkMatrix4x4::
    wrap_static_Adjoint::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'inElements'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'outElements'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMatrix4x4::
    wrap_static_Adjoint::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<double > inElements_smtptr;
  if (!get_val_smtptr_param<double >(inElements_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  double* inElements = inElements_smtptr.get();

  boost::shared_ptr<double > outElements_smtptr;
  if (!get_val_smtptr_param<double >(outElements_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  double* outElements = outElements_smtptr.get();

  vtkMatrix4x4::Adjoint(inElements, outElements);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of double vtkMatrix4x4::Determinant(double const * Elements)
//---------------------------------------------------
void WrapClass_vtkMatrix4x4::
    wrap_static_Determinant::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'Elements'")
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMatrix4x4::
    wrap_static_Determinant::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<double > Elements_smtptr;
  if (!get_val_smtptr_param<double >(Elements_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  double* Elements = Elements_smtptr.get();

  double res =   vtkMatrix4x4::Determinant(Elements);
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkMatrix4x4::PointMultiply(double const * Elements, float const * in, float * out)
//---------------------------------------------------
void WrapClass_vtkMatrix4x4::
    wrap_static_PointMultiply_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'Elements'")
  ADDPARAMCOMMENT_TYPE( float, "parameter named 'in'")
  ADDPARAMCOMMENT_TYPE( float, "parameter named 'out'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMatrix4x4::
    wrap_static_PointMultiply_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<double > Elements_smtptr;
  if (!get_val_smtptr_param<double >(Elements_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  double* Elements = Elements_smtptr.get();

  boost::shared_ptr<float > in_smtptr;
  if (!get_val_smtptr_param<float >(in_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  float* in = in_smtptr.get();

  boost::shared_ptr<float > out_smtptr;
  if (!get_val_smtptr_param<float >(out_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  float* out = out_smtptr.get();

  vtkMatrix4x4::PointMultiply(Elements, in, out);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... static vtkMatrix4x4::PointMultiply(...)
//---------------------------------------------------
void WrapClass_vtkMatrix4x4::
    wrap_static_PointMultiply::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMatrix4x4::
    wrap_static_PointMultiply::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkMatrix4x4::wrap_static_PointMultiply_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkMatrix4x4::wrap_static_PointMultiply_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkMatrix4x4::PointMultiply(double const * Elements, double const * in, double * out)
//---------------------------------------------------
void WrapClass_vtkMatrix4x4::
    wrap_static_PointMultiply_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'Elements'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'in'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'out'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMatrix4x4::
    wrap_static_PointMultiply_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<double > Elements_smtptr;
  if (!get_val_smtptr_param<double >(Elements_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  double* Elements = Elements_smtptr.get();

  boost::shared_ptr<double > in_smtptr;
  if (!get_val_smtptr_param<double >(in_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  double* in = in_smtptr.get();

  boost::shared_ptr<double > out_smtptr;
  if (!get_val_smtptr_param<double >(out_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  double* out = out_smtptr.get();

  vtkMatrix4x4::PointMultiply(Elements, in, out);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkMatrix4x4::IsA(char const * type)
//---------------------------------------------------
void WrapClass_vtkMatrix4x4::
    wrap_IsA::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMatrix4x4::
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
//  Wrapping of vtkMatrix4x4 * vtkMatrix4x4::NewInstance()
//---------------------------------------------------
void WrapClass_vtkMatrix4x4::
    wrap_NewInstance::SetParametersComments()
{
  return_comments="returning a variable of type vtkMatrix4x4";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMatrix4x4::
    wrap_NewInstance::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkMatrix4x4 * res =   this->_objectptr->GetObj()->NewInstance();
  BasicVariable::ptr res_var = WrapClass_vtkMatrix4x4::CreateVar(res);
  return res_var;
}
/* The following types are missing: basic_ostream<char,std::char_traits<char> >

//---------------------------------------------------
//  Wrapping of void vtkMatrix4x4::PrintSelf(ostream & os, vtkIndent indent)
//---------------------------------------------------
void WrapClass_vtkMatrix4x4::
    wrap_PrintSelf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( basic_ostream<char,std::char_traits<char> >, "parameter named 'os'")
  ADDPARAMCOMMENT_TYPE( vtkIndent, "parameter named 'indent'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMatrix4x4::
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
//  Wrapping of void vtkMatrix4x4::DeepCopy(vtkMatrix4x4 * source)
//---------------------------------------------------
void WrapClass_vtkMatrix4x4::
    wrap_DeepCopy_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkMatrix4x4, "parameter named 'source'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMatrix4x4::
    wrap_DeepCopy_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<vtkMatrix4x4 > source_smtptr;
  if (!get_val_smtptr_param<vtkMatrix4x4 >(source_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  vtkMatrix4x4* source = source_smtptr.get();

  this->_objectptr->GetObj()->DeepCopy(source);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkMatrix4x4::DeepCopy(...)
//---------------------------------------------------
void WrapClass_vtkMatrix4x4::
    wrap_DeepCopy::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMatrix4x4::
    wrap_DeepCopy::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkMatrix4x4::wrap_DeepCopy_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkMatrix4x4::wrap_DeepCopy_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkMatrix4x4::DeepCopy(double const * Elements)
//---------------------------------------------------
void WrapClass_vtkMatrix4x4::
    wrap_DeepCopy_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'Elements'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMatrix4x4::
    wrap_DeepCopy_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<double > Elements_smtptr;
  if (!get_val_smtptr_param<double >(Elements_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  double* Elements = Elements_smtptr.get();

  this->_objectptr->GetObj()->DeepCopy(Elements);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkMatrix4x4::Zero()
//---------------------------------------------------
void WrapClass_vtkMatrix4x4::
    wrap_Zero::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMatrix4x4::
    wrap_Zero::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Zero();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkMatrix4x4::Identity()
//---------------------------------------------------
void WrapClass_vtkMatrix4x4::
    wrap_Identity::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMatrix4x4::
    wrap_Identity::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Identity();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkMatrix4x4::Invert()
//---------------------------------------------------
void WrapClass_vtkMatrix4x4::
    wrap_Invert_1::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMatrix4x4::
    wrap_Invert_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->Invert();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkMatrix4x4::Transpose()
//---------------------------------------------------
void WrapClass_vtkMatrix4x4::
    wrap_Transpose_1::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMatrix4x4::
    wrap_Transpose_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->Transpose();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkMatrix4x4::MultiplyPoint(float const * in, float * out)
//---------------------------------------------------
void WrapClass_vtkMatrix4x4::
    wrap_MultiplyPoint_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( float, "parameter named 'in'")
  ADDPARAMCOMMENT_TYPE( float, "parameter named 'out'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMatrix4x4::
    wrap_MultiplyPoint_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<float > in_smtptr;
  if (!get_val_smtptr_param<float >(in_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  float* in = in_smtptr.get();

  boost::shared_ptr<float > out_smtptr;
  if (!get_val_smtptr_param<float >(out_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  float* out = out_smtptr.get();

  this->_objectptr->GetObj()->MultiplyPoint(in, out);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkMatrix4x4::MultiplyPoint(...)
//---------------------------------------------------
void WrapClass_vtkMatrix4x4::
    wrap_MultiplyPoint::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMatrix4x4::
    wrap_MultiplyPoint::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkMatrix4x4::wrap_MultiplyPoint_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkMatrix4x4::wrap_MultiplyPoint_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_vtkMatrix4x4::wrap_MultiplyPoint_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkMatrix4x4::MultiplyPoint(double const * in, double * out)
//---------------------------------------------------
void WrapClass_vtkMatrix4x4::
    wrap_MultiplyPoint_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'in'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'out'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMatrix4x4::
    wrap_MultiplyPoint_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<double > in_smtptr;
  if (!get_val_smtptr_param<double >(in_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  double* in = in_smtptr.get();

  boost::shared_ptr<double > out_smtptr;
  if (!get_val_smtptr_param<double >(out_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  double* out = out_smtptr.get();

  this->_objectptr->GetObj()->MultiplyPoint(in, out);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of float * vtkMatrix4x4::MultiplyPoint(float const * in)
//---------------------------------------------------
void WrapClass_vtkMatrix4x4::
    wrap_MultiplyPoint_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( float, "parameter named 'in'")
  return_comments="returning a variable of type float";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMatrix4x4::
    wrap_MultiplyPoint_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<float > in_smtptr;
  if (!get_val_smtptr_param<float >(in_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  float* in = in_smtptr.get();

  float * res =   this->_objectptr->GetObj()->MultiplyPoint(in);
  return AMILabType<float >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of float * vtkMatrix4x4::MultiplyFloatPoint(float const * in)
//---------------------------------------------------
void WrapClass_vtkMatrix4x4::
    wrap_MultiplyFloatPoint::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( float, "parameter named 'in'")
  return_comments="returning a variable of type float";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMatrix4x4::
    wrap_MultiplyFloatPoint::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<float > in_smtptr;
  if (!get_val_smtptr_param<float >(in_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  float* in = in_smtptr.get();

  float * res =   this->_objectptr->GetObj()->MultiplyFloatPoint(in);
  return AMILabType<float >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of double * vtkMatrix4x4::MultiplyDoublePoint(double const * in)
//---------------------------------------------------
void WrapClass_vtkMatrix4x4::
    wrap_MultiplyDoublePoint::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'in'")
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMatrix4x4::
    wrap_MultiplyDoublePoint::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<double > in_smtptr;
  if (!get_val_smtptr_param<double >(in_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  double* in = in_smtptr.get();

  double * res =   this->_objectptr->GetObj()->MultiplyDoublePoint(in);
  return AMILabType<double >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of void vtkMatrix4x4::Adjoint(vtkMatrix4x4 * in, vtkMatrix4x4 * out)
//---------------------------------------------------
void WrapClass_vtkMatrix4x4::
    wrap_Adjoint_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkMatrix4x4, "parameter named 'in'")
  ADDPARAMCOMMENT_TYPE( vtkMatrix4x4, "parameter named 'out'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMatrix4x4::
    wrap_Adjoint_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<vtkMatrix4x4 > in_smtptr;
  if (!get_val_smtptr_param<vtkMatrix4x4 >(in_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  vtkMatrix4x4* in = in_smtptr.get();

  boost::shared_ptr<vtkMatrix4x4 > out_smtptr;
  if (!get_val_smtptr_param<vtkMatrix4x4 >(out_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  vtkMatrix4x4* out = out_smtptr.get();

  this->_objectptr->GetObj()->Adjoint(in, out);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of double vtkMatrix4x4::Determinant()
//---------------------------------------------------
void WrapClass_vtkMatrix4x4::
    wrap_Determinant_1::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMatrix4x4::
    wrap_Determinant_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  double res =   this->_objectptr->GetObj()->Determinant();
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkMatrix4x4::SetElement(int i, int j, double value)
//---------------------------------------------------
void WrapClass_vtkMatrix4x4::
    wrap_SetElement::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'i'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'j'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'value'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMatrix4x4::
    wrap_SetElement::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>3) ClassHelpAndReturn;
  int _n=0;

  int i;
  if (!get_val_param<int >(i,_p,_n,true,false)) ClassHelpAndReturn;

  int j;
  if (!get_val_param<int >(j,_p,_n,true,false)) ClassHelpAndReturn;

  double value;
  if (!get_val_param<double >(value,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetElement(i, j, value);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of double vtkMatrix4x4::GetElement(int i, int j)
//---------------------------------------------------
void WrapClass_vtkMatrix4x4::
    wrap_GetElement::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'i'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'j'")
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMatrix4x4::
    wrap_GetElement::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  int i;
  if (!get_val_param<int >(i,_p,_n,true,false)) ClassHelpAndReturn;

  int j;
  if (!get_val_param<int >(j,_p,_n,true,false)) ClassHelpAndReturn;

  double res =   this->_objectptr->GetObj()->GetElement(i, j);
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkMatrix4x4::Adjoint(...)
//---------------------------------------------------
void WrapClass_vtkMatrix4x4::
    wrap_Adjoint::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMatrix4x4::
    wrap_Adjoint::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkMatrix4x4::wrap_Adjoint_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkMatrix4x4::wrap_Adjoint_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkMatrix4x4::Adjoint(vtkMatrix4x4 & in, vtkMatrix4x4 & out)
//---------------------------------------------------
void WrapClass_vtkMatrix4x4::
    wrap_Adjoint_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkMatrix4x4, "parameter named 'in'")
  ADDPARAMCOMMENT_TYPE( vtkMatrix4x4, "parameter named 'out'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMatrix4x4::
    wrap_Adjoint_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<vtkMatrix4x4 > in_smtptr;
  if (!get_val_smtptr_param<vtkMatrix4x4 >(in_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  vtkMatrix4x4 & in = *in_smtptr;

  boost::shared_ptr<vtkMatrix4x4 > out_smtptr;
  if (!get_val_smtptr_param<vtkMatrix4x4 >(out_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  vtkMatrix4x4 & out = *out_smtptr;

  this->_objectptr->GetObj()->Adjoint(in, out);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkMatrix4x4::Determinant(...)
//---------------------------------------------------
void WrapClass_vtkMatrix4x4::
    wrap_Determinant::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMatrix4x4::
    wrap_Determinant::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkMatrix4x4::wrap_Determinant_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkMatrix4x4::wrap_Determinant_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_vtkMatrix4x4::wrap_Determinant_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of double vtkMatrix4x4::Determinant(vtkMatrix4x4 & in)
//---------------------------------------------------
void WrapClass_vtkMatrix4x4::
    wrap_Determinant_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkMatrix4x4, "parameter named 'in'")
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMatrix4x4::
    wrap_Determinant_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<vtkMatrix4x4 > in_smtptr;
  if (!get_val_smtptr_param<vtkMatrix4x4 >(in_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  vtkMatrix4x4 & in = *in_smtptr;

  double res =   this->_objectptr->GetObj()->Determinant(in);
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of double vtkMatrix4x4::Determinant(vtkMatrix4x4 * in)
//---------------------------------------------------
void WrapClass_vtkMatrix4x4::
    wrap_Determinant_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkMatrix4x4, "parameter named 'in'")
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMatrix4x4::
    wrap_Determinant_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<vtkMatrix4x4 > in_smtptr;
  if (!get_val_smtptr_param<vtkMatrix4x4 >(in_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  vtkMatrix4x4* in = in_smtptr.get();

  double res =   this->_objectptr->GetObj()->Determinant(in);
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkMatrix4x4::Invert(...)
//---------------------------------------------------
void WrapClass_vtkMatrix4x4::
    wrap_Invert::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMatrix4x4::
    wrap_Invert::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkMatrix4x4::wrap_Invert_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkMatrix4x4::wrap_Invert_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkMatrix4x4::Invert(vtkMatrix4x4 & in, vtkMatrix4x4 & out)
//---------------------------------------------------
void WrapClass_vtkMatrix4x4::
    wrap_Invert_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkMatrix4x4, "parameter named 'in'")
  ADDPARAMCOMMENT_TYPE( vtkMatrix4x4, "parameter named 'out'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMatrix4x4::
    wrap_Invert_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<vtkMatrix4x4 > in_smtptr;
  if (!get_val_smtptr_param<vtkMatrix4x4 >(in_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  vtkMatrix4x4 & in = *in_smtptr;

  boost::shared_ptr<vtkMatrix4x4 > out_smtptr;
  if (!get_val_smtptr_param<vtkMatrix4x4 >(out_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  vtkMatrix4x4 & out = *out_smtptr;

  this->_objectptr->GetObj()->Invert(in, out);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkMatrix4x4::Transpose(...)
//---------------------------------------------------
void WrapClass_vtkMatrix4x4::
    wrap_Transpose::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMatrix4x4::
    wrap_Transpose::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkMatrix4x4::wrap_Transpose_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkMatrix4x4::wrap_Transpose_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkMatrix4x4::Transpose(vtkMatrix4x4 & in, vtkMatrix4x4 & out)
//---------------------------------------------------
void WrapClass_vtkMatrix4x4::
    wrap_Transpose_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkMatrix4x4, "parameter named 'in'")
  ADDPARAMCOMMENT_TYPE( vtkMatrix4x4, "parameter named 'out'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMatrix4x4::
    wrap_Transpose_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<vtkMatrix4x4 > in_smtptr;
  if (!get_val_smtptr_param<vtkMatrix4x4 >(in_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  vtkMatrix4x4 & in = *in_smtptr;

  boost::shared_ptr<vtkMatrix4x4 > out_smtptr;
  if (!get_val_smtptr_param<vtkMatrix4x4 >(out_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  vtkMatrix4x4 & out = *out_smtptr;

  this->_objectptr->GetObj()->Transpose(in, out);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of double * vtkMatrix4x4::operator [](unsigned int const i)
//---------------------------------------------------
void WrapClass_vtkMatrix4x4::
    wrap___at___1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'i'")
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMatrix4x4::
    wrap___at___1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  long i_long;
  if (!get_val_param<long >(i_long,_p,_n,true,true)) ClassReturnEmptyVar;
  unsigned int i = boost::numeric_cast<unsigned int >(i_long);

  double * res =   (*this->_objectptr->GetObj()) [ (i)];
  return AMILabType<double >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkMatrix4x4::[](...)
//---------------------------------------------------
void WrapClass_vtkMatrix4x4::
    wrap___at__::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMatrix4x4::
    wrap___at__::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkMatrix4x4::wrap___at___1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkMatrix4x4::wrap___at___2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of double const * vtkMatrix4x4::operator [](unsigned int i)
//---------------------------------------------------
void WrapClass_vtkMatrix4x4::
    wrap___at___2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'i'")
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMatrix4x4::
    wrap___at___2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  long i_long;
  if (!get_val_param<long >(i_long,_p,_n,true,true)) ClassReturnEmptyVar;
  unsigned int i = boost::numeric_cast<unsigned int >(i_long);

  double const * res =   (*this->_objectptr->GetObj()) [ (i)];
  return AMILabType<double >::CreateVar(const_cast<double *>(res),true);
}

