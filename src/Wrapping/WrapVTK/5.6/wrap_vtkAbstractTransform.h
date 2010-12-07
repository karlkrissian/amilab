/**
 * C++ Interface: wrap_vtkAbstractTransform
 *
 * Description: wrapping vtkAbstractTransform
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_vtkAbstractTransform_h_
#define _wrap_vtkAbstractTransform_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "vtk_includes.h"

// include what is needed for inheritence and for types ...

#include "wrap_vtkObject.h"



AMI_DECLARE_TYPE(vtkAbstractTransform);

// TODO: check for inheritence ...
class WrapClass_vtkAbstractTransform : public WrapClass<vtkAbstractTransform>
    , public   WrapClass_vtkObject
{
  DEFINE_CLASS(WrapClass_vtkAbstractTransform);

  protected:
    typedef WrapClass<vtkAbstractTransform>::ptr _parentclass_ptr;
    typedef vtkAbstractTransform ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<vtkAbstractTransform>& GetObj() const { return WrapClass<vtkAbstractTransform>::GetObj(); }

    /// Constructor
    WrapClass_vtkAbstractTransform(boost::shared_ptr<vtkAbstractTransform > si): 
    WrapClass<vtkAbstractTransform>(si)
    , WrapClass_vtkObject(si)
    {}

    /// Destructor
    ~WrapClass_vtkAbstractTransform()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    


    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( vtkAbstractTransform*);

    // Static methods
    
    ADD_CLASS_STATICMETHOD(IsTypeOf,"int vtkAbstractTransform::IsTypeOf(char const * type) (http://docs.wxwidgets.org/stable/wx_vtkabstracttransform.html#istypeof).");
    ADD_CLASS_STATICMETHOD(SafeDownCast,"vtkAbstractTransform * vtkAbstractTransform::SafeDownCast(vtkObjectBase * o) (http://docs.wxwidgets.org/stable/wx_vtkabstracttransform.html#safedowncast).");



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(IsA,"int vtkAbstractTransform::IsA(char const * type)  (http://docs.wxwidgets.org/stable/wx_vtkabstracttransform.html#isa)")
    ADD_CLASS_METHOD(NewInstance,"vtkAbstractTransform * vtkAbstractTransform::NewInstance()  (http://docs.wxwidgets.org/stable/wx_vtkabstracttransform.html#newinstance)")
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
    ADD_CLASS_METHOD(PrintSelf,"void vtkAbstractTransform::PrintSelf(ostream & os, vtkIndent indent)  (http://docs.wxwidgets.org/stable/wx_vtkabstracttransform.html#printself)")
*/
    ADD_CLASS_METHOD(TransformPoint_1,"void vtkAbstractTransform::TransformPoint(float const * in, float * out)  (http://docs.wxwidgets.org/stable/wx_vtkabstracttransform.html#transformpoint)")
    ADD_CLASS_METHOD(TransformPoint,"vtkAbstractTransform::TransformPoint()  (http://docs.wxwidgets.org/stable/wx_vtkabstracttransform.html#transformpoint)")
    ADD_CLASS_METHOD(TransformPoint_2,"void vtkAbstractTransform::TransformPoint(double const * in, double * out)  (http://docs.wxwidgets.org/stable/wx_vtkabstracttransform.html#transformpoint)")
    ADD_CLASS_METHOD(TransformPoint_3,"double * vtkAbstractTransform::TransformPoint(double x, double y, double z)  (http://docs.wxwidgets.org/stable/wx_vtkabstracttransform.html#transformpoint)")
    ADD_CLASS_METHOD(TransformPoint_4,"double * vtkAbstractTransform::TransformPoint(double const * point)  (http://docs.wxwidgets.org/stable/wx_vtkabstracttransform.html#transformpoint)")
    ADD_CLASS_METHOD(TransformFloatPoint_1,"float * vtkAbstractTransform::TransformFloatPoint(float x, float y, float z)  (http://docs.wxwidgets.org/stable/wx_vtkabstracttransform.html#transformfloatpoint)")
    ADD_CLASS_METHOD(TransformFloatPoint,"vtkAbstractTransform::TransformFloatPoint()  (http://docs.wxwidgets.org/stable/wx_vtkabstracttransform.html#transformfloatpoint)")
    ADD_CLASS_METHOD(TransformFloatPoint_2,"float * vtkAbstractTransform::TransformFloatPoint(float const * point)  (http://docs.wxwidgets.org/stable/wx_vtkabstracttransform.html#transformfloatpoint)")
    ADD_CLASS_METHOD(TransformDoublePoint_1,"double * vtkAbstractTransform::TransformDoublePoint(double x, double y, double z)  (http://docs.wxwidgets.org/stable/wx_vtkabstracttransform.html#transformdoublepoint)")
    ADD_CLASS_METHOD(TransformDoublePoint,"vtkAbstractTransform::TransformDoublePoint()  (http://docs.wxwidgets.org/stable/wx_vtkabstracttransform.html#transformdoublepoint)")
    ADD_CLASS_METHOD(TransformDoublePoint_2,"double * vtkAbstractTransform::TransformDoublePoint(double const * point)  (http://docs.wxwidgets.org/stable/wx_vtkabstracttransform.html#transformdoublepoint)")
    ADD_CLASS_METHOD(TransformNormalAtPoint_1,"void vtkAbstractTransform::TransformNormalAtPoint(float const * point, float const * in, float * out)  (http://docs.wxwidgets.org/stable/wx_vtkabstracttransform.html#transformnormalatpoint)")
    ADD_CLASS_METHOD(TransformNormalAtPoint,"vtkAbstractTransform::TransformNormalAtPoint()  (http://docs.wxwidgets.org/stable/wx_vtkabstracttransform.html#transformnormalatpoint)")
    ADD_CLASS_METHOD(TransformNormalAtPoint_2,"void vtkAbstractTransform::TransformNormalAtPoint(double const * point, double const * in, double * out)  (http://docs.wxwidgets.org/stable/wx_vtkabstracttransform.html#transformnormalatpoint)")
    ADD_CLASS_METHOD(TransformNormalAtPoint_3,"double * vtkAbstractTransform::TransformNormalAtPoint(double const * point, double const * normal)  (http://docs.wxwidgets.org/stable/wx_vtkabstracttransform.html#transformnormalatpoint)")
    ADD_CLASS_METHOD(TransformDoubleNormalAtPoint,"double * vtkAbstractTransform::TransformDoubleNormalAtPoint(double const * point, double const * normal)  (http://docs.wxwidgets.org/stable/wx_vtkabstracttransform.html#transformdoublenormalatpoint)")
    ADD_CLASS_METHOD(TransformFloatNormalAtPoint,"float * vtkAbstractTransform::TransformFloatNormalAtPoint(float const * point, float const * normal)  (http://docs.wxwidgets.org/stable/wx_vtkabstracttransform.html#transformfloatnormalatpoint)")
    ADD_CLASS_METHOD(TransformVectorAtPoint_1,"void vtkAbstractTransform::TransformVectorAtPoint(float const * point, float const * in, float * out)  (http://docs.wxwidgets.org/stable/wx_vtkabstracttransform.html#transformvectoratpoint)")
    ADD_CLASS_METHOD(TransformVectorAtPoint,"vtkAbstractTransform::TransformVectorAtPoint()  (http://docs.wxwidgets.org/stable/wx_vtkabstracttransform.html#transformvectoratpoint)")
    ADD_CLASS_METHOD(TransformVectorAtPoint_2,"void vtkAbstractTransform::TransformVectorAtPoint(double const * point, double const * in, double * out)  (http://docs.wxwidgets.org/stable/wx_vtkabstracttransform.html#transformvectoratpoint)")
    ADD_CLASS_METHOD(TransformVectorAtPoint_3,"double * vtkAbstractTransform::TransformVectorAtPoint(double const * point, double const * vector)  (http://docs.wxwidgets.org/stable/wx_vtkabstracttransform.html#transformvectoratpoint)")
    ADD_CLASS_METHOD(TransformDoubleVectorAtPoint,"double * vtkAbstractTransform::TransformDoubleVectorAtPoint(double const * point, double const * vector)  (http://docs.wxwidgets.org/stable/wx_vtkabstracttransform.html#transformdoublevectoratpoint)")
    ADD_CLASS_METHOD(TransformFloatVectorAtPoint,"float * vtkAbstractTransform::TransformFloatVectorAtPoint(float const * point, float const * vector)  (http://docs.wxwidgets.org/stable/wx_vtkabstracttransform.html#transformfloatvectoratpoint)")
    ADD_CLASS_METHOD(TransformPoints,"void vtkAbstractTransform::TransformPoints(vtkPoints * inPts, vtkPoints * outPts)  (http://docs.wxwidgets.org/stable/wx_vtkabstracttransform.html#transformpoints)")
    ADD_CLASS_METHOD(TransformPointsNormalsVectors,"void vtkAbstractTransform::TransformPointsNormalsVectors(vtkPoints * inPts, vtkPoints * outPts, vtkDataArray * inNms, vtkDataArray * outNms, vtkDataArray * inVrs, vtkDataArray * outVrs)  (http://docs.wxwidgets.org/stable/wx_vtkabstracttransform.html#transformpointsnormalsvectors)")
    ADD_CLASS_METHOD(GetInverse,"vtkAbstractTransform * vtkAbstractTransform::GetInverse()  (http://docs.wxwidgets.org/stable/wx_vtkabstracttransform.html#getinverse)")
    ADD_CLASS_METHOD(SetInverse,"void vtkAbstractTransform::SetInverse(vtkAbstractTransform * transform)  (http://docs.wxwidgets.org/stable/wx_vtkabstracttransform.html#setinverse)")
    ADD_CLASS_METHOD(DeepCopy,"void vtkAbstractTransform::DeepCopy(vtkAbstractTransform * param0)  (http://docs.wxwidgets.org/stable/wx_vtkabstracttransform.html#deepcopy)")
    ADD_CLASS_METHOD(Update,"void vtkAbstractTransform::Update()  (http://docs.wxwidgets.org/stable/wx_vtkabstracttransform.html#update)")
    ADD_CLASS_METHOD(CircuitCheck,"int vtkAbstractTransform::CircuitCheck(vtkAbstractTransform * transform)  (http://docs.wxwidgets.org/stable/wx_vtkabstracttransform.html#circuitcheck)")
    ADD_CLASS_METHOD(GetMTime,"long unsigned int vtkAbstractTransform::GetMTime()  (http://docs.wxwidgets.org/stable/wx_vtkabstracttransform.html#getmtime)")
    ADD_CLASS_METHOD(UnRegister,"void vtkAbstractTransform::UnRegister(vtkObjectBase * O)  (http://docs.wxwidgets.org/stable/wx_vtkabstracttransform.html#unregister)")





    void AddMethods(WrapClass<vtkAbstractTransform>::ptr this_ptr );
    
    /*
     * Adds the constructor and the static methods to the given context
     */
    static void AddStaticMethods( Variables::ptr& context);

};


#endif // _wrap_vtkAbstractTransform_h
