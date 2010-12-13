/**
 * C++ Interface: wrap_vtkLinearTransform
 *
 * Description: wrapping vtkLinearTransform
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_vtkLinearTransform_h_
#define _wrap_vtkLinearTransform_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "vtkLinearTransform.h"

// include what is needed for inheritence and for types ...

#include "wrap_vtkHomogeneousTransform.h"


#ifndef vtkLinearTransform_declared
  #define vtkLinearTransform_declared
  AMI_DECLARE_TYPE(vtkLinearTransform);
#endif

// TODO: check for inheritence ...
class WrapClass_vtkLinearTransform : public WrapClass<vtkLinearTransform>
    , public   WrapClass_vtkHomogeneousTransform
{
  DEFINE_CLASS(WrapClass_vtkLinearTransform);

  protected:
    typedef WrapClass<vtkLinearTransform>::ptr _parentclass_ptr;
    typedef vtkLinearTransform ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<vtkLinearTransform>& GetObj() const { return WrapClass<vtkLinearTransform>::GetObj(); }

    /// Constructor
    WrapClass_vtkLinearTransform(boost::shared_ptr<vtkLinearTransform > si): 
    WrapClass<vtkLinearTransform>(si)
    , WrapClass_vtkHomogeneousTransform(si)
    {}

    /// Destructor
    ~WrapClass_vtkLinearTransform()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    


    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( vtkLinearTransform*);

    // Static methods
    
    ADD_CLASS_STATICMETHOD(IsTypeOf,"int vtkLinearTransform::IsTypeOf(char const * type) (http://docs.wxwidgets.org/stable/wx_vtklineartransform.html#istypeof).");
    ADD_CLASS_STATICMETHOD(SafeDownCast,"vtkLinearTransform * vtkLinearTransform::SafeDownCast(vtkObjectBase * o) (http://docs.wxwidgets.org/stable/wx_vtklineartransform.html#safedowncast).");



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(IsA,"int vtkLinearTransform::IsA(char const * type)  (http://docs.wxwidgets.org/stable/wx_vtklineartransform.html#isa)")
    ADD_CLASS_METHOD(NewInstance,"vtkLinearTransform * vtkLinearTransform::NewInstance()  (http://docs.wxwidgets.org/stable/wx_vtklineartransform.html#newinstance)")
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
    ADD_CLASS_METHOD(PrintSelf,"void vtkLinearTransform::PrintSelf(ostream & os, vtkIndent indent)  (http://docs.wxwidgets.org/stable/wx_vtklineartransform.html#printself)")
*/
    ADD_CLASS_METHOD(TransformNormal_1,"void vtkLinearTransform::TransformNormal(float const * in, float * out)  (http://docs.wxwidgets.org/stable/wx_vtklineartransform.html#transformnormal)")
    ADD_CLASS_METHOD(TransformNormal,"vtkLinearTransform::TransformNormal()  (http://docs.wxwidgets.org/stable/wx_vtklineartransform.html#transformnormal)")
    ADD_CLASS_METHOD(TransformNormal_2,"void vtkLinearTransform::TransformNormal(double const * in, double * out)  (http://docs.wxwidgets.org/stable/wx_vtklineartransform.html#transformnormal)")
    ADD_CLASS_METHOD(TransformNormal_3,"double * vtkLinearTransform::TransformNormal(double x, double y, double z)  (http://docs.wxwidgets.org/stable/wx_vtklineartransform.html#transformnormal)")
    ADD_CLASS_METHOD(TransformNormal_4,"double * vtkLinearTransform::TransformNormal(double const * normal)  (http://docs.wxwidgets.org/stable/wx_vtklineartransform.html#transformnormal)")
    ADD_CLASS_METHOD(TransformFloatNormal_1,"float * vtkLinearTransform::TransformFloatNormal(float x, float y, float z)  (http://docs.wxwidgets.org/stable/wx_vtklineartransform.html#transformfloatnormal)")
    ADD_CLASS_METHOD(TransformFloatNormal,"vtkLinearTransform::TransformFloatNormal()  (http://docs.wxwidgets.org/stable/wx_vtklineartransform.html#transformfloatnormal)")
    ADD_CLASS_METHOD(TransformFloatNormal_2,"float * vtkLinearTransform::TransformFloatNormal(float const * normal)  (http://docs.wxwidgets.org/stable/wx_vtklineartransform.html#transformfloatnormal)")
    ADD_CLASS_METHOD(TransformDoubleNormal_1,"double * vtkLinearTransform::TransformDoubleNormal(double x, double y, double z)  (http://docs.wxwidgets.org/stable/wx_vtklineartransform.html#transformdoublenormal)")
    ADD_CLASS_METHOD(TransformDoubleNormal,"vtkLinearTransform::TransformDoubleNormal()  (http://docs.wxwidgets.org/stable/wx_vtklineartransform.html#transformdoublenormal)")
    ADD_CLASS_METHOD(TransformDoubleNormal_2,"double * vtkLinearTransform::TransformDoubleNormal(double const * normal)  (http://docs.wxwidgets.org/stable/wx_vtklineartransform.html#transformdoublenormal)")
    ADD_CLASS_METHOD(TransformVector_1,"double * vtkLinearTransform::TransformVector(double x, double y, double z)  (http://docs.wxwidgets.org/stable/wx_vtklineartransform.html#transformvector)")
    ADD_CLASS_METHOD(TransformVector,"vtkLinearTransform::TransformVector()  (http://docs.wxwidgets.org/stable/wx_vtklineartransform.html#transformvector)")
    ADD_CLASS_METHOD(TransformVector_2,"double * vtkLinearTransform::TransformVector(double const * normal)  (http://docs.wxwidgets.org/stable/wx_vtklineartransform.html#transformvector)")
    ADD_CLASS_METHOD(TransformVector_3,"void vtkLinearTransform::TransformVector(float const * in, float * out)  (http://docs.wxwidgets.org/stable/wx_vtklineartransform.html#transformvector)")
    ADD_CLASS_METHOD(TransformVector_4,"void vtkLinearTransform::TransformVector(double const * in, double * out)  (http://docs.wxwidgets.org/stable/wx_vtklineartransform.html#transformvector)")
    ADD_CLASS_METHOD(TransformFloatVector_1,"float * vtkLinearTransform::TransformFloatVector(float x, float y, float z)  (http://docs.wxwidgets.org/stable/wx_vtklineartransform.html#transformfloatvector)")
    ADD_CLASS_METHOD(TransformFloatVector,"vtkLinearTransform::TransformFloatVector()  (http://docs.wxwidgets.org/stable/wx_vtklineartransform.html#transformfloatvector)")
    ADD_CLASS_METHOD(TransformFloatVector_2,"float * vtkLinearTransform::TransformFloatVector(float const * vec)  (http://docs.wxwidgets.org/stable/wx_vtklineartransform.html#transformfloatvector)")
    ADD_CLASS_METHOD(TransformDoubleVector_1,"double * vtkLinearTransform::TransformDoubleVector(double x, double y, double z)  (http://docs.wxwidgets.org/stable/wx_vtklineartransform.html#transformdoublevector)")
    ADD_CLASS_METHOD(TransformDoubleVector,"vtkLinearTransform::TransformDoubleVector()  (http://docs.wxwidgets.org/stable/wx_vtklineartransform.html#transformdoublevector)")
    ADD_CLASS_METHOD(TransformDoubleVector_2,"double * vtkLinearTransform::TransformDoubleVector(double const * vec)  (http://docs.wxwidgets.org/stable/wx_vtklineartransform.html#transformdoublevector)")
    ADD_CLASS_METHOD(TransformPoints,"void vtkLinearTransform::TransformPoints(vtkPoints * inPts, vtkPoints * outPts)  (http://docs.wxwidgets.org/stable/wx_vtklineartransform.html#transformpoints)")
    ADD_CLASS_METHOD(TransformNormals,"void vtkLinearTransform::TransformNormals(vtkDataArray * inNms, vtkDataArray * outNms)  (http://docs.wxwidgets.org/stable/wx_vtklineartransform.html#transformnormals)")
    ADD_CLASS_METHOD(TransformVectors,"void vtkLinearTransform::TransformVectors(vtkDataArray * inVrs, vtkDataArray * outVrs)  (http://docs.wxwidgets.org/stable/wx_vtklineartransform.html#transformvectors)")
    ADD_CLASS_METHOD(TransformPointsNormalsVectors,"void vtkLinearTransform::TransformPointsNormalsVectors(vtkPoints * inPts, vtkPoints * outPts, vtkDataArray * inNms, vtkDataArray * outNms, vtkDataArray * inVrs, vtkDataArray * outVrs)  (http://docs.wxwidgets.org/stable/wx_vtklineartransform.html#transformpointsnormalsvectors)")
    ADD_CLASS_METHOD(GetLinearInverse,"vtkLinearTransform * vtkLinearTransform::GetLinearInverse()  (http://docs.wxwidgets.org/stable/wx_vtklineartransform.html#getlinearinverse)")
    ADD_CLASS_METHOD(InternalTransformPoint_1,"void vtkLinearTransform::InternalTransformPoint(float const * in, float * out)  (http://docs.wxwidgets.org/stable/wx_vtklineartransform.html#internaltransformpoint)")
    ADD_CLASS_METHOD(InternalTransformPoint,"vtkLinearTransform::InternalTransformPoint()  (http://docs.wxwidgets.org/stable/wx_vtklineartransform.html#internaltransformpoint)")
    ADD_CLASS_METHOD(InternalTransformPoint_2,"void vtkLinearTransform::InternalTransformPoint(double const * in, double * out)  (http://docs.wxwidgets.org/stable/wx_vtklineartransform.html#internaltransformpoint)")
    ADD_CLASS_METHOD(InternalTransformNormal_1,"void vtkLinearTransform::InternalTransformNormal(float const * in, float * out)  (http://docs.wxwidgets.org/stable/wx_vtklineartransform.html#internaltransformnormal)")
    ADD_CLASS_METHOD(InternalTransformNormal,"vtkLinearTransform::InternalTransformNormal()  (http://docs.wxwidgets.org/stable/wx_vtklineartransform.html#internaltransformnormal)")
    ADD_CLASS_METHOD(InternalTransformNormal_2,"void vtkLinearTransform::InternalTransformNormal(double const * in, double * out)  (http://docs.wxwidgets.org/stable/wx_vtklineartransform.html#internaltransformnormal)")
    ADD_CLASS_METHOD(InternalTransformVector_1,"void vtkLinearTransform::InternalTransformVector(float const * in, float * out)  (http://docs.wxwidgets.org/stable/wx_vtklineartransform.html#internaltransformvector)")
    ADD_CLASS_METHOD(InternalTransformVector,"vtkLinearTransform::InternalTransformVector()  (http://docs.wxwidgets.org/stable/wx_vtklineartransform.html#internaltransformvector)")
    ADD_CLASS_METHOD(InternalTransformVector_2,"void vtkLinearTransform::InternalTransformVector(double const * in, double * out)  (http://docs.wxwidgets.org/stable/wx_vtklineartransform.html#internaltransformvector)")





    void AddMethods(WrapClass<vtkLinearTransform>::ptr this_ptr );
    

};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClassvtkLinearTransform_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_vtkLinearTransform_h
