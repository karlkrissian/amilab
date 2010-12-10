/**
 * C++ Interface: wrap_vtkMatrix4x4
 *
 * Description: wrapping vtkMatrix4x4
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_vtkMatrix4x4_h_
#define _wrap_vtkMatrix4x4_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "vtkMatrix4x4.h"

// include what is needed for inheritence and for types ...

#include "wrap_vtkObject.h"



AMI_DECLARE_TYPE(vtkMatrix4x4);

// TODO: check for inheritence ...
class WrapClass_vtkMatrix4x4 : public WrapClass<vtkMatrix4x4>
    , public   WrapClass_vtkObject
{
  DEFINE_CLASS(WrapClass_vtkMatrix4x4);

  protected:
    typedef WrapClass<vtkMatrix4x4>::ptr _parentclass_ptr;
    typedef vtkMatrix4x4 ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<vtkMatrix4x4>& GetObj() const { return WrapClass<vtkMatrix4x4>::GetObj(); }

    /// Constructor
    WrapClass_vtkMatrix4x4(boost::shared_ptr<vtkMatrix4x4 > si): 
    WrapClass<vtkMatrix4x4>(si)
    , WrapClass_vtkObject(si)
    {}

    /// Destructor
    ~WrapClass_vtkMatrix4x4()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( vtkMatrix4x4*);

    // Static methods
    
    ADD_CLASS_STATICMETHOD(New,"vtkMatrix4x4 * vtkMatrix4x4::New() (http://docs.wxwidgets.org/stable/wx_vtkmatrix4x4.html#new).");
    ADD_CLASS_STATICMETHOD(IsTypeOf,"int vtkMatrix4x4::IsTypeOf(char const * type) (http://docs.wxwidgets.org/stable/wx_vtkmatrix4x4.html#istypeof).");
    ADD_CLASS_STATICMETHOD(SafeDownCast,"vtkMatrix4x4 * vtkMatrix4x4::SafeDownCast(vtkObjectBase * o) (http://docs.wxwidgets.org/stable/wx_vtkmatrix4x4.html#safedowncast).");
    ADD_CLASS_STATICMETHOD(DeepCopy_1,"void vtkMatrix4x4::DeepCopy(double * Elements, vtkMatrix4x4 * source) (http://docs.wxwidgets.org/stable/wx_vtkmatrix4x4.html#deepcopy).");
    ADD_CLASS_STATICMETHOD(DeepCopy,"vtkMatrix4x4::DeepCopy() (http://docs.wxwidgets.org/stable/wx_vtkmatrix4x4.html#deepcopy).");
    ADD_CLASS_STATICMETHOD(DeepCopy_2,"void vtkMatrix4x4::DeepCopy(double * Elements, double const * newElements) (http://docs.wxwidgets.org/stable/wx_vtkmatrix4x4.html#deepcopy).");
    ADD_CLASS_STATICMETHOD(Zero,"void vtkMatrix4x4::Zero(double * Elements) (http://docs.wxwidgets.org/stable/wx_vtkmatrix4x4.html#zero).");
    ADD_CLASS_STATICMETHOD(Identity,"void vtkMatrix4x4::Identity(double * Elements) (http://docs.wxwidgets.org/stable/wx_vtkmatrix4x4.html#identity).");
    ADD_CLASS_STATICMETHOD(Invert_1,"void vtkMatrix4x4::Invert(vtkMatrix4x4 * in, vtkMatrix4x4 * out) (http://docs.wxwidgets.org/stable/wx_vtkmatrix4x4.html#invert).");
    ADD_CLASS_STATICMETHOD(Invert,"vtkMatrix4x4::Invert() (http://docs.wxwidgets.org/stable/wx_vtkmatrix4x4.html#invert).");
    ADD_CLASS_STATICMETHOD(Invert_2,"void vtkMatrix4x4::Invert(double const * inElements, double * outElements) (http://docs.wxwidgets.org/stable/wx_vtkmatrix4x4.html#invert).");
    ADD_CLASS_STATICMETHOD(Transpose_1,"void vtkMatrix4x4::Transpose(vtkMatrix4x4 * in, vtkMatrix4x4 * out) (http://docs.wxwidgets.org/stable/wx_vtkmatrix4x4.html#transpose).");
    ADD_CLASS_STATICMETHOD(Transpose,"vtkMatrix4x4::Transpose() (http://docs.wxwidgets.org/stable/wx_vtkmatrix4x4.html#transpose).");
    ADD_CLASS_STATICMETHOD(Transpose_2,"void vtkMatrix4x4::Transpose(double const * inElements, double * outElements) (http://docs.wxwidgets.org/stable/wx_vtkmatrix4x4.html#transpose).");
    ADD_CLASS_STATICMETHOD(MultiplyPoint_1,"void vtkMatrix4x4::MultiplyPoint(double const * Elements, float const * in, float * out) (http://docs.wxwidgets.org/stable/wx_vtkmatrix4x4.html#multiplypoint).");
    ADD_CLASS_STATICMETHOD(MultiplyPoint,"vtkMatrix4x4::MultiplyPoint() (http://docs.wxwidgets.org/stable/wx_vtkmatrix4x4.html#multiplypoint).");
    ADD_CLASS_STATICMETHOD(MultiplyPoint_2,"void vtkMatrix4x4::MultiplyPoint(double const * Elements, double const * in, double * out) (http://docs.wxwidgets.org/stable/wx_vtkmatrix4x4.html#multiplypoint).");
    ADD_CLASS_STATICMETHOD(Multiply4x4_1,"void vtkMatrix4x4::Multiply4x4(vtkMatrix4x4 * a, vtkMatrix4x4 * b, vtkMatrix4x4 * c) (http://docs.wxwidgets.org/stable/wx_vtkmatrix4x4.html#multiply4x4).");
    ADD_CLASS_STATICMETHOD(Multiply4x4,"vtkMatrix4x4::Multiply4x4() (http://docs.wxwidgets.org/stable/wx_vtkmatrix4x4.html#multiply4x4).");
    ADD_CLASS_STATICMETHOD(Multiply4x4_2,"void vtkMatrix4x4::Multiply4x4(double const * a, double const * b, double * c) (http://docs.wxwidgets.org/stable/wx_vtkmatrix4x4.html#multiply4x4).");
    ADD_CLASS_STATICMETHOD(Adjoint,"void vtkMatrix4x4::Adjoint(double const * inElements, double * outElements) (http://docs.wxwidgets.org/stable/wx_vtkmatrix4x4.html#adjoint).");
    ADD_CLASS_STATICMETHOD(Determinant,"double vtkMatrix4x4::Determinant(double const * Elements) (http://docs.wxwidgets.org/stable/wx_vtkmatrix4x4.html#determinant).");
    ADD_CLASS_STATICMETHOD(PointMultiply_1,"void vtkMatrix4x4::PointMultiply(double const * Elements, float const * in, float * out) (http://docs.wxwidgets.org/stable/wx_vtkmatrix4x4.html#pointmultiply).");
    ADD_CLASS_STATICMETHOD(PointMultiply,"vtkMatrix4x4::PointMultiply() (http://docs.wxwidgets.org/stable/wx_vtkmatrix4x4.html#pointmultiply).");
    ADD_CLASS_STATICMETHOD(PointMultiply_2,"void vtkMatrix4x4::PointMultiply(double const * Elements, double const * in, double * out) (http://docs.wxwidgets.org/stable/wx_vtkmatrix4x4.html#pointmultiply).");



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(IsA,"int vtkMatrix4x4::IsA(char const * type)  (http://docs.wxwidgets.org/stable/wx_vtkmatrix4x4.html#isa)")
    ADD_CLASS_METHOD(NewInstance,"vtkMatrix4x4 * vtkMatrix4x4::NewInstance()  (http://docs.wxwidgets.org/stable/wx_vtkmatrix4x4.html#newinstance)")
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
    ADD_CLASS_METHOD(PrintSelf,"void vtkMatrix4x4::PrintSelf(ostream & os, vtkIndent indent)  (http://docs.wxwidgets.org/stable/wx_vtkmatrix4x4.html#printself)")
*/
    ADD_CLASS_METHOD(DeepCopy_1,"void vtkMatrix4x4::DeepCopy(vtkMatrix4x4 * source)  (http://docs.wxwidgets.org/stable/wx_vtkmatrix4x4.html#deepcopy)")
    ADD_CLASS_METHOD(DeepCopy,"vtkMatrix4x4::DeepCopy()  (http://docs.wxwidgets.org/stable/wx_vtkmatrix4x4.html#deepcopy)")
    ADD_CLASS_METHOD(DeepCopy_2,"void vtkMatrix4x4::DeepCopy(double const * Elements)  (http://docs.wxwidgets.org/stable/wx_vtkmatrix4x4.html#deepcopy)")
    ADD_CLASS_METHOD(Zero,"void vtkMatrix4x4::Zero()  (http://docs.wxwidgets.org/stable/wx_vtkmatrix4x4.html#zero)")
    ADD_CLASS_METHOD(Identity,"void vtkMatrix4x4::Identity()  (http://docs.wxwidgets.org/stable/wx_vtkmatrix4x4.html#identity)")
    ADD_CLASS_METHOD(Invert_1,"void vtkMatrix4x4::Invert()  (http://docs.wxwidgets.org/stable/wx_vtkmatrix4x4.html#invert)")
    ADD_CLASS_METHOD(Transpose_1,"void vtkMatrix4x4::Transpose()  (http://docs.wxwidgets.org/stable/wx_vtkmatrix4x4.html#transpose)")
    ADD_CLASS_METHOD(MultiplyPoint_1,"void vtkMatrix4x4::MultiplyPoint(float const * in, float * out)  (http://docs.wxwidgets.org/stable/wx_vtkmatrix4x4.html#multiplypoint)")
    ADD_CLASS_METHOD(MultiplyPoint,"vtkMatrix4x4::MultiplyPoint()  (http://docs.wxwidgets.org/stable/wx_vtkmatrix4x4.html#multiplypoint)")
    ADD_CLASS_METHOD(MultiplyPoint_2,"void vtkMatrix4x4::MultiplyPoint(double const * in, double * out)  (http://docs.wxwidgets.org/stable/wx_vtkmatrix4x4.html#multiplypoint)")
    ADD_CLASS_METHOD(MultiplyPoint_3,"float * vtkMatrix4x4::MultiplyPoint(float const * in)  (http://docs.wxwidgets.org/stable/wx_vtkmatrix4x4.html#multiplypoint)")
    ADD_CLASS_METHOD(MultiplyFloatPoint,"float * vtkMatrix4x4::MultiplyFloatPoint(float const * in)  (http://docs.wxwidgets.org/stable/wx_vtkmatrix4x4.html#multiplyfloatpoint)")
    ADD_CLASS_METHOD(MultiplyDoublePoint,"double * vtkMatrix4x4::MultiplyDoublePoint(double const * in)  (http://docs.wxwidgets.org/stable/wx_vtkmatrix4x4.html#multiplydoublepoint)")
    ADD_CLASS_METHOD(Adjoint_1,"void vtkMatrix4x4::Adjoint(vtkMatrix4x4 * in, vtkMatrix4x4 * out)  (http://docs.wxwidgets.org/stable/wx_vtkmatrix4x4.html#adjoint)")
    ADD_CLASS_METHOD(Determinant_1,"double vtkMatrix4x4::Determinant()  (http://docs.wxwidgets.org/stable/wx_vtkmatrix4x4.html#determinant)")
    ADD_CLASS_METHOD(SetElement,"void vtkMatrix4x4::SetElement(int i, int j, double value)  (http://docs.wxwidgets.org/stable/wx_vtkmatrix4x4.html#setelement)")
    ADD_CLASS_METHOD(GetElement,"double vtkMatrix4x4::GetElement(int i, int j)  (http://docs.wxwidgets.org/stable/wx_vtkmatrix4x4.html#getelement)")
    ADD_CLASS_METHOD(Adjoint,"vtkMatrix4x4::Adjoint()  (http://docs.wxwidgets.org/stable/wx_vtkmatrix4x4.html#adjoint)")
    ADD_CLASS_METHOD(Adjoint_2,"void vtkMatrix4x4::Adjoint(vtkMatrix4x4 & in, vtkMatrix4x4 & out)  (http://docs.wxwidgets.org/stable/wx_vtkmatrix4x4.html#adjoint)")
    ADD_CLASS_METHOD(Determinant,"vtkMatrix4x4::Determinant()  (http://docs.wxwidgets.org/stable/wx_vtkmatrix4x4.html#determinant)")
    ADD_CLASS_METHOD(Determinant_2,"double vtkMatrix4x4::Determinant(vtkMatrix4x4 & in)  (http://docs.wxwidgets.org/stable/wx_vtkmatrix4x4.html#determinant)")
    ADD_CLASS_METHOD(Determinant_3,"double vtkMatrix4x4::Determinant(vtkMatrix4x4 * in)  (http://docs.wxwidgets.org/stable/wx_vtkmatrix4x4.html#determinant)")
    ADD_CLASS_METHOD(Invert,"vtkMatrix4x4::Invert()  (http://docs.wxwidgets.org/stable/wx_vtkmatrix4x4.html#invert)")
    ADD_CLASS_METHOD(Invert_2,"void vtkMatrix4x4::Invert(vtkMatrix4x4 & in, vtkMatrix4x4 & out)  (http://docs.wxwidgets.org/stable/wx_vtkmatrix4x4.html#invert)")
    ADD_CLASS_METHOD(Transpose,"vtkMatrix4x4::Transpose()  (http://docs.wxwidgets.org/stable/wx_vtkmatrix4x4.html#transpose)")
    ADD_CLASS_METHOD(Transpose_2,"void vtkMatrix4x4::Transpose(vtkMatrix4x4 & in, vtkMatrix4x4 & out)  (http://docs.wxwidgets.org/stable/wx_vtkmatrix4x4.html#transpose)")

    // Operators:
    ADD_CLASS_METHOD(__at___1,            "double * vtkMatrix4x4::operator [](unsigned int const i) (http://docs.wxwidgets.org/stable/wx_vtkmatrix4x4.html#__at__)")
    ADD_CLASS_METHOD(__at__,            "vtkMatrix4x4::operator []() (http://docs.wxwidgets.org/stable/wx_vtkmatrix4x4.html#__at__)")
    ADD_CLASS_METHOD(__at___2,            "double const * vtkMatrix4x4::operator [](unsigned int i) (http://docs.wxwidgets.org/stable/wx_vtkmatrix4x4.html#__at__)")




    void AddMethods(WrapClass<vtkMatrix4x4>::ptr this_ptr );
    
    /*
     * Adds the constructor and the static methods to the given context
     */
    static void AddStaticMethods( Variables::ptr& context);

};


#endif // _wrap_vtkMatrix4x4_h
