/**
 * C++ Interface: wrap_vtkHomogeneousTransform
 *
 * Description: wrapping vtkHomogeneousTransform
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

#include "wrap_vtkHomogeneousTransform.h"

// get all the required includes
// #include "..."
#ifndef vtkHomogeneousTransform_declared
  #define vtkHomogeneousTransform_declared
  AMI_DECLARE_TYPE(vtkHomogeneousTransform)
#endif
#ifndef vtkObjectBase_declared
  #define vtkObjectBase_declared
  AMI_DECLARE_TYPE(vtkObjectBase)
#endif
#ifndef vtkIndent_declared
  #define vtkIndent_declared
  AMI_DECLARE_TYPE(vtkIndent)
#endif
#ifndef vtkPoints_declared
  #define vtkPoints_declared
  AMI_DECLARE_TYPE(vtkPoints)
#endif
#ifndef vtkDataArray_declared
  #define vtkDataArray_declared
  AMI_DECLARE_TYPE(vtkDataArray)
#endif
#ifndef vtkMatrix4x4_declared
  #define vtkMatrix4x4_declared
  AMI_DECLARE_TYPE(vtkMatrix4x4)
#endif



// needed to allow NULL pointer parameter
extern Variable<int>::ptr nullvar;
extern bool CheckNullVar(ParamList* _p, int _n);

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<vtkHomogeneousTransform>::CreateVar( ParamList* p)
{
  // No variable creation for an abstract class ...
  return BasicVariable::ptr();

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(vtkHomogeneousTransform);
AMI_DEFINE_VARFROMSMTPTR(vtkHomogeneousTransform);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<vtkHomogeneousTransform>::CreateVar( vtkHomogeneousTransform* val, bool nodeleter)
{ 
  boost::shared_ptr<vtkHomogeneousTransform> obj_ptr(val,smartpointer_nodeleter<vtkHomogeneousTransform>());
  return AMILabType<vtkHomogeneousTransform>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to vtkHomogeneousTransform
//
Variable<AMIObject>::ptr WrapClass_vtkHomogeneousTransform::CreateVar( vtkHomogeneousTransform* sp)
{
  boost::shared_ptr<vtkHomogeneousTransform> di_ptr(
    sp,
    wxwindow_nodeleter<vtkHomogeneousTransform>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<vtkHomogeneousTransform>::CreateVar(
      new WrapClass_vtkHomogeneousTransform(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_vtkHomogeneousTransform::AddMethods(WrapClass<vtkHomogeneousTransform>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding standard methods 
  AddVar_IsA( this_ptr);
  AddVar_NewInstance( this_ptr);
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
  AddVar_PrintSelf( this_ptr);
*/
  AddVar_TransformPoints( this_ptr);
  AddVar_TransformPointsNormalsVectors( this_ptr);
  AddVar_GetMatrix_1( this_ptr);
  AddVar_GetMatrix( this_ptr);
  AddVar_GetMatrix_2( this_ptr);
  AddVar_GetHomogeneousInverse( this_ptr);
  AddVar_InternalTransformPoint_1( this_ptr);
  AddVar_InternalTransformPoint( this_ptr);
  AddVar_InternalTransformPoint_2( this_ptr);



  

  


  // Get the current context
  AMIObject::ptr tmpobj(amiobject.lock());
  if (!tmpobj.get()) return;
  Variables::ptr context(tmpobj->GetContext());

  // Add base parent vtkAbstractTransform
  boost::shared_ptr<vtkAbstractTransform > parent_vtkAbstractTransform(  boost::dynamic_pointer_cast<vtkAbstractTransform >(this_ptr->GetObj()));
  BasicVariable::ptr var_vtkAbstractTransform = AMILabType<vtkAbstractTransform >::CreateVarFromSmtPtr(parent_vtkAbstractTransform);
  context->AddVar("vtkAbstractTransform",var_vtkAbstractTransform);
  // Set as a default context
  Variable<AMIObject>::ptr obj_vtkAbstractTransform = boost::dynamic_pointer_cast<Variable<AMIObject> >(var_vtkAbstractTransform);
  context->AddDefault(obj_vtkAbstractTransform->Pointer()->GetContext());

};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClassvtkHomogeneousTransform_AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("vtkHomogeneousTransform");
  
  // Static methods 
  WrapClass_vtkHomogeneousTransform::AddVar_IsTypeOf(amiobject->GetContext());
  WrapClass_vtkHomogeneousTransform::AddVar_SafeDownCast(amiobject->GetContext());

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of int vtkHomogeneousTransform::IsTypeOf(char const * type)
//---------------------------------------------------
void WrapClass_vtkHomogeneousTransform::
    wrap_static_IsTypeOf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkHomogeneousTransform::
    wrap_static_IsTypeOf::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<std::string > type_string;
  if (!get_val_smtptr_param<std::string >(type_string,_p,_n,true,false,false)) ClassHelpAndReturn;
  char const * type = type_string->c_str();

  int res =   vtkHomogeneousTransform::IsTypeOf(type);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of vtkHomogeneousTransform * vtkHomogeneousTransform::SafeDownCast(vtkObjectBase * o)
//---------------------------------------------------
void WrapClass_vtkHomogeneousTransform::
    wrap_static_SafeDownCast::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkObjectBase, "parameter named 'o'")
  return_comments="returning a variable of type vtkHomogeneousTransform";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkHomogeneousTransform::
    wrap_static_SafeDownCast::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  vtkObjectBase* o;
  if (CheckNullVar(_p,_n))  {
    o=(vtkObjectBase*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkObjectBase > o_smtptr;
    if (!get_val_smtptr_param<vtkObjectBase >(o_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    o = o_smtptr.get();
  }

  vtkHomogeneousTransform * res =   vtkHomogeneousTransform::SafeDownCast(o);
  BasicVariable::ptr res_var = AMILabType<vtkHomogeneousTransform >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of int vtkHomogeneousTransform::IsA(char const * type)
//---------------------------------------------------
void WrapClass_vtkHomogeneousTransform::
    wrap_IsA::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkHomogeneousTransform::
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
//  Wrapping of vtkHomogeneousTransform * vtkHomogeneousTransform::NewInstance()
//---------------------------------------------------
void WrapClass_vtkHomogeneousTransform::
    wrap_NewInstance::SetParametersComments()
{
  return_comments="returning a variable of type vtkHomogeneousTransform";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkHomogeneousTransform::
    wrap_NewInstance::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkHomogeneousTransform * res =   this->_objectptr->GetObj()->NewInstance();
  BasicVariable::ptr res_var = AMILabType<vtkHomogeneousTransform >::CreateVar(res,true);
  return res_var;
}
/* The following types are missing: basic_ostream<char,std::char_traits<char> >

//---------------------------------------------------
//  Wrapping of void vtkHomogeneousTransform::PrintSelf(ostream & os, vtkIndent indent)
//---------------------------------------------------
void WrapClass_vtkHomogeneousTransform::
    wrap_PrintSelf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( basic_ostream<char,std::char_traits<char> >, "parameter named 'os'")
  ADDPARAMCOMMENT_TYPE( vtkIndent, "parameter named 'indent'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkHomogeneousTransform::
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
//  Wrapping of void vtkHomogeneousTransform::TransformPoints(vtkPoints * inPts, vtkPoints * outPts)
//---------------------------------------------------
void WrapClass_vtkHomogeneousTransform::
    wrap_TransformPoints::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkPoints, "parameter named 'inPts'")
  ADDPARAMCOMMENT_TYPE( vtkPoints, "parameter named 'outPts'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkHomogeneousTransform::
    wrap_TransformPoints::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  vtkPoints* inPts;
  if (CheckNullVar(_p,_n))  {
    inPts=(vtkPoints*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkPoints > inPts_smtptr;
    if (!get_val_smtptr_param<vtkPoints >(inPts_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    inPts = inPts_smtptr.get();
  }

  vtkPoints* outPts;
  if (CheckNullVar(_p,_n))  {
    outPts=(vtkPoints*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkPoints > outPts_smtptr;
    if (!get_val_smtptr_param<vtkPoints >(outPts_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    outPts = outPts_smtptr.get();
  }

  this->_objectptr->GetObj()->TransformPoints(inPts, outPts);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkHomogeneousTransform::TransformPointsNormalsVectors(vtkPoints * inPts, vtkPoints * outPts, vtkDataArray * inNms, vtkDataArray * outNms, vtkDataArray * inVrs, vtkDataArray * outVrs)
//---------------------------------------------------
void WrapClass_vtkHomogeneousTransform::
    wrap_TransformPointsNormalsVectors::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkPoints, "parameter named 'inPts'")
  ADDPARAMCOMMENT_TYPE( vtkPoints, "parameter named 'outPts'")
  ADDPARAMCOMMENT_TYPE( vtkDataArray, "parameter named 'inNms'")
  ADDPARAMCOMMENT_TYPE( vtkDataArray, "parameter named 'outNms'")
  ADDPARAMCOMMENT_TYPE( vtkDataArray, "parameter named 'inVrs'")
  ADDPARAMCOMMENT_TYPE( vtkDataArray, "parameter named 'outVrs'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkHomogeneousTransform::
    wrap_TransformPointsNormalsVectors::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>6) ClassHelpAndReturn;
  int _n=0;

  vtkPoints* inPts;
  if (CheckNullVar(_p,_n))  {
    inPts=(vtkPoints*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkPoints > inPts_smtptr;
    if (!get_val_smtptr_param<vtkPoints >(inPts_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    inPts = inPts_smtptr.get();
  }

  vtkPoints* outPts;
  if (CheckNullVar(_p,_n))  {
    outPts=(vtkPoints*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkPoints > outPts_smtptr;
    if (!get_val_smtptr_param<vtkPoints >(outPts_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    outPts = outPts_smtptr.get();
  }

  vtkDataArray* inNms;
  if (CheckNullVar(_p,_n))  {
    inNms=(vtkDataArray*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkDataArray > inNms_smtptr;
    if (!get_val_smtptr_param<vtkDataArray >(inNms_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    inNms = inNms_smtptr.get();
  }

  vtkDataArray* outNms;
  if (CheckNullVar(_p,_n))  {
    outNms=(vtkDataArray*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkDataArray > outNms_smtptr;
    if (!get_val_smtptr_param<vtkDataArray >(outNms_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    outNms = outNms_smtptr.get();
  }

  vtkDataArray* inVrs;
  if (CheckNullVar(_p,_n))  {
    inVrs=(vtkDataArray*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkDataArray > inVrs_smtptr;
    if (!get_val_smtptr_param<vtkDataArray >(inVrs_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    inVrs = inVrs_smtptr.get();
  }

  vtkDataArray* outVrs;
  if (CheckNullVar(_p,_n))  {
    outVrs=(vtkDataArray*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkDataArray > outVrs_smtptr;
    if (!get_val_smtptr_param<vtkDataArray >(outVrs_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    outVrs = outVrs_smtptr.get();
  }

  this->_objectptr->GetObj()->TransformPointsNormalsVectors(inPts, outPts, inNms, outNms, inVrs, outVrs);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkHomogeneousTransform::GetMatrix(vtkMatrix4x4 * m)
//---------------------------------------------------
void WrapClass_vtkHomogeneousTransform::
    wrap_GetMatrix_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkMatrix4x4, "parameter named 'm'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkHomogeneousTransform::
    wrap_GetMatrix_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  vtkMatrix4x4* m;
  if (CheckNullVar(_p,_n))  {
    m=(vtkMatrix4x4*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkMatrix4x4 > m_smtptr;
    if (!get_val_smtptr_param<vtkMatrix4x4 >(m_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    m = m_smtptr.get();
  }

  this->_objectptr->GetObj()->GetMatrix(m);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkHomogeneousTransform::GetMatrix(...)
//---------------------------------------------------
void WrapClass_vtkHomogeneousTransform::
    wrap_GetMatrix::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkHomogeneousTransform::
    wrap_GetMatrix::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkHomogeneousTransform::wrap_GetMatrix_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkHomogeneousTransform::wrap_GetMatrix_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of vtkMatrix4x4 * vtkHomogeneousTransform::GetMatrix()
//---------------------------------------------------
void WrapClass_vtkHomogeneousTransform::
    wrap_GetMatrix_2::SetParametersComments()
{
  return_comments="returning a variable of type vtkMatrix4x4";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkHomogeneousTransform::
    wrap_GetMatrix_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  vtkMatrix4x4 * res =   this->_objectptr->GetObj()->GetMatrix();
  BasicVariable::ptr res_var = AMILabType<vtkMatrix4x4 >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of vtkHomogeneousTransform * vtkHomogeneousTransform::GetHomogeneousInverse()
//---------------------------------------------------
void WrapClass_vtkHomogeneousTransform::
    wrap_GetHomogeneousInverse::SetParametersComments()
{
  return_comments="returning a variable of type vtkHomogeneousTransform";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkHomogeneousTransform::
    wrap_GetHomogeneousInverse::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkHomogeneousTransform * res =   this->_objectptr->GetObj()->GetHomogeneousInverse();
  BasicVariable::ptr res_var = AMILabType<vtkHomogeneousTransform >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of void vtkHomogeneousTransform::InternalTransformPoint(float const * in, float * out)
//---------------------------------------------------
void WrapClass_vtkHomogeneousTransform::
    wrap_InternalTransformPoint_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( float, "parameter named 'in'")
  ADDPARAMCOMMENT_TYPE( float, "parameter named 'out'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkHomogeneousTransform::
    wrap_InternalTransformPoint_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  float* in;
  if (CheckNullVar(_p,_n))  {
    in=(float*)NULL;
    _n++;
  } else {
    boost::shared_ptr<float > in_smtptr;
    if (!get_val_smtptr_param<float >(in_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    in = in_smtptr.get();
  }

  float* out;
  if (CheckNullVar(_p,_n))  {
    out=(float*)NULL;
    _n++;
  } else {
    boost::shared_ptr<float > out_smtptr;
    if (!get_val_smtptr_param<float >(out_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    out = out_smtptr.get();
  }

  this->_objectptr->GetObj()->InternalTransformPoint(in, out);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkHomogeneousTransform::InternalTransformPoint(...)
//---------------------------------------------------
void WrapClass_vtkHomogeneousTransform::
    wrap_InternalTransformPoint::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkHomogeneousTransform::
    wrap_InternalTransformPoint::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkHomogeneousTransform::wrap_InternalTransformPoint_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkHomogeneousTransform::wrap_InternalTransformPoint_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkHomogeneousTransform::InternalTransformPoint(double const * in, double * out)
//---------------------------------------------------
void WrapClass_vtkHomogeneousTransform::
    wrap_InternalTransformPoint_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'in'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'out'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkHomogeneousTransform::
    wrap_InternalTransformPoint_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  double* in;
  if (CheckNullVar(_p,_n))  {
    in=(double*)NULL;
    _n++;
  } else {
    boost::shared_ptr<double > in_smtptr;
    if (!get_val_smtptr_param<double >(in_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    in = in_smtptr.get();
  }

  double* out;
  if (CheckNullVar(_p,_n))  {
    out=(double*)NULL;
    _n++;
  } else {
    boost::shared_ptr<double > out_smtptr;
    if (!get_val_smtptr_param<double >(out_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    out = out_smtptr.get();
  }

  this->_objectptr->GetObj()->InternalTransformPoint(in, out);
  return BasicVariable::ptr();
}

