/**
 * C++ Interface: wrap_vtkHomogeneousTransform
 *
 * Description: wrapping vtkHomogeneousTransform
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_vtkHomogeneousTransform_h_
#define _wrap_vtkHomogeneousTransform_h_

/*
#include "Variable.hpp"
#include "ami_object.h"
*/
#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "paramlist.h"

#include "vtkHomogeneousTransform.h"

// include what is needed for inheritence and for types ...

#include "wrap_vtkAbstractTransform.h"


#ifndef vtkHomogeneousTransform_declared
  #define vtkHomogeneousTransform_declared
  AMI_DECLARE_TYPE(vtkHomogeneousTransform);
#endif

// TODO: check for inheritence ...
class WrapClass_vtkHomogeneousTransform : public WrapClass<vtkHomogeneousTransform>
    , public   WrapClass_vtkAbstractTransform
{
  DEFINE_CLASS(WrapClass_vtkHomogeneousTransform);

  protected:
    typedef WrapClass<vtkHomogeneousTransform>::ptr _parentclass_ptr;
    typedef vtkHomogeneousTransform ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<vtkHomogeneousTransform>& GetObj() const { return WrapClass<vtkHomogeneousTransform>::GetObj(); }

    /// Constructor
    WrapClass_vtkHomogeneousTransform(boost::shared_ptr<vtkHomogeneousTransform > si): 
    WrapClass<vtkHomogeneousTransform>(si)
    , WrapClass_vtkAbstractTransform(si)
    {}

    /// Destructor
    ~WrapClass_vtkHomogeneousTransform()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    


    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( vtkHomogeneousTransform*);

    // Static methods
    
    ADD_CLASS_STATICMETHOD(IsTypeOf,"int vtkHomogeneousTransform::IsTypeOf(char const * type) (http://docs.wxwidgets.org/stable/wx_vtkhomogeneoustransform.html#istypeof).");
    ADD_CLASS_STATICMETHOD(SafeDownCast,"vtkHomogeneousTransform * vtkHomogeneousTransform::SafeDownCast(vtkObjectBase * o) (http://docs.wxwidgets.org/stable/wx_vtkhomogeneoustransform.html#safedowncast).");



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(IsA,"int vtkHomogeneousTransform::IsA(char const * type)  (http://docs.wxwidgets.org/stable/wx_vtkhomogeneoustransform.html#isa)")
    ADD_CLASS_METHOD(NewInstance,"vtkHomogeneousTransform * vtkHomogeneousTransform::NewInstance()  (http://docs.wxwidgets.org/stable/wx_vtkhomogeneoustransform.html#newinstance)")
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
    ADD_CLASS_METHOD(PrintSelf,"void vtkHomogeneousTransform::PrintSelf(ostream & os, vtkIndent indent)  (http://docs.wxwidgets.org/stable/wx_vtkhomogeneoustransform.html#printself)")
*/
    ADD_CLASS_METHOD(TransformPoints,"void vtkHomogeneousTransform::TransformPoints(vtkPoints * inPts, vtkPoints * outPts)  (http://docs.wxwidgets.org/stable/wx_vtkhomogeneoustransform.html#transformpoints)")
    ADD_CLASS_METHOD(TransformPointsNormalsVectors,"void vtkHomogeneousTransform::TransformPointsNormalsVectors(vtkPoints * inPts, vtkPoints * outPts, vtkDataArray * inNms, vtkDataArray * outNms, vtkDataArray * inVrs, vtkDataArray * outVrs)  (http://docs.wxwidgets.org/stable/wx_vtkhomogeneoustransform.html#transformpointsnormalsvectors)")
    ADD_CLASS_METHOD(GetMatrix_1,"void vtkHomogeneousTransform::GetMatrix(vtkMatrix4x4 * m)  (http://docs.wxwidgets.org/stable/wx_vtkhomogeneoustransform.html#getmatrix)")
    ADD_CLASS_METHOD(GetMatrix,"vtkHomogeneousTransform::GetMatrix()  (http://docs.wxwidgets.org/stable/wx_vtkhomogeneoustransform.html#getmatrix)")
    ADD_CLASS_METHOD(GetMatrix_2,"vtkMatrix4x4 * vtkHomogeneousTransform::GetMatrix()  (http://docs.wxwidgets.org/stable/wx_vtkhomogeneoustransform.html#getmatrix)")
    ADD_CLASS_METHOD(GetHomogeneousInverse,"vtkHomogeneousTransform * vtkHomogeneousTransform::GetHomogeneousInverse()  (http://docs.wxwidgets.org/stable/wx_vtkhomogeneoustransform.html#gethomogeneousinverse)")
    ADD_CLASS_METHOD(InternalTransformPoint_1,"void vtkHomogeneousTransform::InternalTransformPoint(float const * in, float * out)  (http://docs.wxwidgets.org/stable/wx_vtkhomogeneoustransform.html#internaltransformpoint)")
    ADD_CLASS_METHOD(InternalTransformPoint,"vtkHomogeneousTransform::InternalTransformPoint()  (http://docs.wxwidgets.org/stable/wx_vtkhomogeneoustransform.html#internaltransformpoint)")
    ADD_CLASS_METHOD(InternalTransformPoint_2,"void vtkHomogeneousTransform::InternalTransformPoint(double const * in, double * out)  (http://docs.wxwidgets.org/stable/wx_vtkhomogeneoustransform.html#internaltransformpoint)")





    void AddMethods(WrapClass<vtkHomogeneousTransform>::ptr this_ptr );
    

};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClassvtkHomogeneousTransform_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_vtkHomogeneousTransform_h
