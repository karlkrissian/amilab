/**
 * C++ Interface: wrap_vtkTransform
 *
 * Description: wrapping vtkTransform
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_vtkTransform_h_
#define _wrap_vtkTransform_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "vtkTransform.h"

// include what is needed for inheritence and for types ...

#include "wrap_vtkLinearTransform.h"


#ifndef vtkTransform_declared
  #define vtkTransform_declared
  AMI_DECLARE_TYPE(vtkTransform);
#endif

// TODO: check for inheritence ...
class WrapClass_vtkTransform : public WrapClass<vtkTransform>
    , public   WrapClass_vtkLinearTransform
{
  DEFINE_CLASS(WrapClass_vtkTransform);

  protected:
    typedef WrapClass<vtkTransform>::ptr _parentclass_ptr;
    typedef vtkTransform ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<vtkTransform>& GetObj() const { return WrapClass<vtkTransform>::GetObj(); }

    /// Constructor
    WrapClass_vtkTransform(boost::shared_ptr<vtkTransform > si): 
    WrapClass<vtkTransform>(si)
    , WrapClass_vtkLinearTransform(si)
    {}

    /// Destructor
    ~WrapClass_vtkTransform()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( vtkTransform*);

    // Static methods
    
    ADD_CLASS_STATICMETHOD(New,"vtkTransform * vtkTransform::New() (http://docs.wxwidgets.org/stable/wx_vtktransform.html#new).");
    ADD_CLASS_STATICMETHOD(IsTypeOf,"int vtkTransform::IsTypeOf(char const * type) (http://docs.wxwidgets.org/stable/wx_vtktransform.html#istypeof).");
    ADD_CLASS_STATICMETHOD(SafeDownCast,"vtkTransform * vtkTransform::SafeDownCast(vtkObjectBase * o) (http://docs.wxwidgets.org/stable/wx_vtktransform.html#safedowncast).");
    ADD_CLASS_STATICMETHOD(GetOrientation,"void vtkTransform::GetOrientation(double * orient, vtkMatrix4x4 * matrix) (http://docs.wxwidgets.org/stable/wx_vtktransform.html#getorientation).");



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(IsA,"int vtkTransform::IsA(char const * type)  (http://docs.wxwidgets.org/stable/wx_vtktransform.html#isa)")
    ADD_CLASS_METHOD(NewInstance,"vtkTransform * vtkTransform::NewInstance()  (http://docs.wxwidgets.org/stable/wx_vtktransform.html#newinstance)")
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
    ADD_CLASS_METHOD(PrintSelf,"void vtkTransform::PrintSelf(ostream & os, vtkIndent indent)  (http://docs.wxwidgets.org/stable/wx_vtktransform.html#printself)")
*/
    ADD_CLASS_METHOD(Identity,"void vtkTransform::Identity()  (http://docs.wxwidgets.org/stable/wx_vtktransform.html#identity)")
    ADD_CLASS_METHOD(Inverse,"void vtkTransform::Inverse()  (http://docs.wxwidgets.org/stable/wx_vtktransform.html#inverse)")
    ADD_CLASS_METHOD(Translate_1,"void vtkTransform::Translate(double x, double y, double z)  (http://docs.wxwidgets.org/stable/wx_vtktransform.html#translate)")
    ADD_CLASS_METHOD(Translate,"vtkTransform::Translate()  (http://docs.wxwidgets.org/stable/wx_vtktransform.html#translate)")
    ADD_CLASS_METHOD(Translate_2,"void vtkTransform::Translate(double const * x)  (http://docs.wxwidgets.org/stable/wx_vtktransform.html#translate)")
    ADD_CLASS_METHOD(Translate_3,"void vtkTransform::Translate(float const * x)  (http://docs.wxwidgets.org/stable/wx_vtktransform.html#translate)")
    ADD_CLASS_METHOD(RotateWXYZ_1,"void vtkTransform::RotateWXYZ(double angle, double x, double y, double z)  (http://docs.wxwidgets.org/stable/wx_vtktransform.html#rotatewxyz)")
    ADD_CLASS_METHOD(RotateWXYZ,"vtkTransform::RotateWXYZ()  (http://docs.wxwidgets.org/stable/wx_vtktransform.html#rotatewxyz)")
    ADD_CLASS_METHOD(RotateWXYZ_2,"void vtkTransform::RotateWXYZ(double angle, double const * axis)  (http://docs.wxwidgets.org/stable/wx_vtktransform.html#rotatewxyz)")
    ADD_CLASS_METHOD(RotateWXYZ_3,"void vtkTransform::RotateWXYZ(double angle, float const * axis)  (http://docs.wxwidgets.org/stable/wx_vtktransform.html#rotatewxyz)")
    ADD_CLASS_METHOD(RotateX,"void vtkTransform::RotateX(double angle)  (http://docs.wxwidgets.org/stable/wx_vtktransform.html#rotatex)")
    ADD_CLASS_METHOD(RotateY,"void vtkTransform::RotateY(double angle)  (http://docs.wxwidgets.org/stable/wx_vtktransform.html#rotatey)")
    ADD_CLASS_METHOD(RotateZ,"void vtkTransform::RotateZ(double angle)  (http://docs.wxwidgets.org/stable/wx_vtktransform.html#rotatez)")
    ADD_CLASS_METHOD(Scale_1,"void vtkTransform::Scale(double x, double y, double z)  (http://docs.wxwidgets.org/stable/wx_vtktransform.html#scale)")
    ADD_CLASS_METHOD(Scale,"vtkTransform::Scale()  (http://docs.wxwidgets.org/stable/wx_vtktransform.html#scale)")
    ADD_CLASS_METHOD(Scale_2,"void vtkTransform::Scale(double const * s)  (http://docs.wxwidgets.org/stable/wx_vtktransform.html#scale)")
    ADD_CLASS_METHOD(Scale_3,"void vtkTransform::Scale(float const * s)  (http://docs.wxwidgets.org/stable/wx_vtktransform.html#scale)")
    ADD_CLASS_METHOD(SetMatrix_1,"void vtkTransform::SetMatrix(vtkMatrix4x4 * matrix)  (http://docs.wxwidgets.org/stable/wx_vtktransform.html#setmatrix)")
    ADD_CLASS_METHOD(SetMatrix,"vtkTransform::SetMatrix()  (http://docs.wxwidgets.org/stable/wx_vtktransform.html#setmatrix)")
    ADD_CLASS_METHOD(SetMatrix_2,"void vtkTransform::SetMatrix(double const * elements)  (http://docs.wxwidgets.org/stable/wx_vtktransform.html#setmatrix)")
    ADD_CLASS_METHOD(Concatenate_1,"void vtkTransform::Concatenate(vtkMatrix4x4 * matrix)  (http://docs.wxwidgets.org/stable/wx_vtktransform.html#concatenate)")
    ADD_CLASS_METHOD(Concatenate,"vtkTransform::Concatenate()  (http://docs.wxwidgets.org/stable/wx_vtktransform.html#concatenate)")
    ADD_CLASS_METHOD(Concatenate_2,"void vtkTransform::Concatenate(double const * elements)  (http://docs.wxwidgets.org/stable/wx_vtktransform.html#concatenate)")
    ADD_CLASS_METHOD(Concatenate_3,"void vtkTransform::Concatenate(vtkLinearTransform * transform)  (http://docs.wxwidgets.org/stable/wx_vtktransform.html#concatenate)")
    ADD_CLASS_METHOD(PreMultiply,"void vtkTransform::PreMultiply()  (http://docs.wxwidgets.org/stable/wx_vtktransform.html#premultiply)")
    ADD_CLASS_METHOD(PostMultiply,"void vtkTransform::PostMultiply()  (http://docs.wxwidgets.org/stable/wx_vtktransform.html#postmultiply)")
    ADD_CLASS_METHOD(GetNumberOfConcatenatedTransforms,"int vtkTransform::GetNumberOfConcatenatedTransforms()  (http://docs.wxwidgets.org/stable/wx_vtktransform.html#getnumberofconcatenatedtransforms)")
    ADD_CLASS_METHOD(GetConcatenatedTransform,"vtkLinearTransform * vtkTransform::GetConcatenatedTransform(int i)  (http://docs.wxwidgets.org/stable/wx_vtktransform.html#getconcatenatedtransform)")
    ADD_CLASS_METHOD(GetOrientation_1,"void vtkTransform::GetOrientation(double * orient)  (http://docs.wxwidgets.org/stable/wx_vtktransform.html#getorientation)")
    ADD_CLASS_METHOD(GetOrientation,"vtkTransform::GetOrientation()  (http://docs.wxwidgets.org/stable/wx_vtktransform.html#getorientation)")
    ADD_CLASS_METHOD(GetOrientation_2,"void vtkTransform::GetOrientation(float * orient)  (http://docs.wxwidgets.org/stable/wx_vtktransform.html#getorientation)")
    ADD_CLASS_METHOD(GetOrientation_3,"double * vtkTransform::GetOrientation()  (http://docs.wxwidgets.org/stable/wx_vtktransform.html#getorientation)")
    ADD_CLASS_METHOD(GetOrientationWXYZ_1,"void vtkTransform::GetOrientationWXYZ(double * wxyz)  (http://docs.wxwidgets.org/stable/wx_vtktransform.html#getorientationwxyz)")
    ADD_CLASS_METHOD(GetOrientationWXYZ,"vtkTransform::GetOrientationWXYZ()  (http://docs.wxwidgets.org/stable/wx_vtktransform.html#getorientationwxyz)")
    ADD_CLASS_METHOD(GetOrientationWXYZ_2,"void vtkTransform::GetOrientationWXYZ(float * wxyz)  (http://docs.wxwidgets.org/stable/wx_vtktransform.html#getorientationwxyz)")
    ADD_CLASS_METHOD(GetOrientationWXYZ_3,"double * vtkTransform::GetOrientationWXYZ()  (http://docs.wxwidgets.org/stable/wx_vtktransform.html#getorientationwxyz)")
    ADD_CLASS_METHOD(GetPosition_1,"void vtkTransform::GetPosition(double * pos)  (http://docs.wxwidgets.org/stable/wx_vtktransform.html#getposition)")
    ADD_CLASS_METHOD(GetPosition,"vtkTransform::GetPosition()  (http://docs.wxwidgets.org/stable/wx_vtktransform.html#getposition)")
    ADD_CLASS_METHOD(GetPosition_2,"void vtkTransform::GetPosition(float * pos)  (http://docs.wxwidgets.org/stable/wx_vtktransform.html#getposition)")
    ADD_CLASS_METHOD(GetPosition_3,"double * vtkTransform::GetPosition()  (http://docs.wxwidgets.org/stable/wx_vtktransform.html#getposition)")
    ADD_CLASS_METHOD(GetScale_1,"void vtkTransform::GetScale(double * scale)  (http://docs.wxwidgets.org/stable/wx_vtktransform.html#getscale)")
    ADD_CLASS_METHOD(GetScale,"vtkTransform::GetScale()  (http://docs.wxwidgets.org/stable/wx_vtktransform.html#getscale)")
    ADD_CLASS_METHOD(GetScale_2,"void vtkTransform::GetScale(float * scale)  (http://docs.wxwidgets.org/stable/wx_vtktransform.html#getscale)")
    ADD_CLASS_METHOD(GetScale_3,"double * vtkTransform::GetScale()  (http://docs.wxwidgets.org/stable/wx_vtktransform.html#getscale)")
    ADD_CLASS_METHOD(GetInverse_1,"void vtkTransform::GetInverse(vtkMatrix4x4 * inverse)  (http://docs.wxwidgets.org/stable/wx_vtktransform.html#getinverse)")
    ADD_CLASS_METHOD(GetTranspose,"void vtkTransform::GetTranspose(vtkMatrix4x4 * transpose)  (http://docs.wxwidgets.org/stable/wx_vtktransform.html#gettranspose)")
    ADD_CLASS_METHOD(SetInput,"void vtkTransform::SetInput(vtkLinearTransform * input)  (http://docs.wxwidgets.org/stable/wx_vtktransform.html#setinput)")
    ADD_CLASS_METHOD(GetInput,"vtkLinearTransform * vtkTransform::GetInput()  (http://docs.wxwidgets.org/stable/wx_vtktransform.html#getinput)")
    ADD_CLASS_METHOD(GetInverseFlag,"int vtkTransform::GetInverseFlag()  (http://docs.wxwidgets.org/stable/wx_vtktransform.html#getinverseflag)")
    ADD_CLASS_METHOD(Push,"void vtkTransform::Push()  (http://docs.wxwidgets.org/stable/wx_vtktransform.html#push)")
    ADD_CLASS_METHOD(Pop,"void vtkTransform::Pop()  (http://docs.wxwidgets.org/stable/wx_vtktransform.html#pop)")
    ADD_CLASS_METHOD(CircuitCheck,"int vtkTransform::CircuitCheck(vtkAbstractTransform * transform)  (http://docs.wxwidgets.org/stable/wx_vtktransform.html#circuitcheck)")
    ADD_CLASS_METHOD(GetInverse,"vtkTransform::GetInverse()  (http://docs.wxwidgets.org/stable/wx_vtktransform.html#getinverse)")
    ADD_CLASS_METHOD(GetInverse_2,"vtkAbstractTransform * vtkTransform::GetInverse()  (http://docs.wxwidgets.org/stable/wx_vtktransform.html#getinverse)")
    ADD_CLASS_METHOD(MakeTransform,"vtkAbstractTransform * vtkTransform::MakeTransform()  (http://docs.wxwidgets.org/stable/wx_vtktransform.html#maketransform)")
    ADD_CLASS_METHOD(GetMTime,"long unsigned int vtkTransform::GetMTime()  (http://docs.wxwidgets.org/stable/wx_vtktransform.html#getmtime)")
    ADD_CLASS_METHOD(MultiplyPoint_1,"void vtkTransform::MultiplyPoint(float const * in, float * out)  (http://docs.wxwidgets.org/stable/wx_vtktransform.html#multiplypoint)")
    ADD_CLASS_METHOD(MultiplyPoint,"vtkTransform::MultiplyPoint()  (http://docs.wxwidgets.org/stable/wx_vtktransform.html#multiplypoint)")
    ADD_CLASS_METHOD(MultiplyPoint_2,"void vtkTransform::MultiplyPoint(double const * in, double * out)  (http://docs.wxwidgets.org/stable/wx_vtktransform.html#multiplypoint)")





    void AddMethods(WrapClass<vtkTransform>::ptr this_ptr );
    

};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClassvtkTransform_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_vtkTransform_h
