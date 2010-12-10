/**
 * C++ Interface: wrap_vtkProp3D
 *
 * Description: wrapping vtkProp3D
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_vtkProp3D_h_
#define _wrap_vtkProp3D_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "vtkProp3D.h"

// include what is needed for inheritence and for types ...

#include "wrap_vtkProp.h"



AMI_DECLARE_TYPE(vtkProp3D);

// TODO: check for inheritence ...
class WrapClass_vtkProp3D : public WrapClass<vtkProp3D>
    , public   WrapClass_vtkProp
{
  DEFINE_CLASS(WrapClass_vtkProp3D);

  protected:
    typedef WrapClass<vtkProp3D>::ptr _parentclass_ptr;
    typedef vtkProp3D ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<vtkProp3D>& GetObj() const { return WrapClass<vtkProp3D>::GetObj(); }

    /// Constructor
    WrapClass_vtkProp3D(boost::shared_ptr<vtkProp3D > si): 
    WrapClass<vtkProp3D>(si)
    , WrapClass_vtkProp(si)
    {}

    /// Destructor
    ~WrapClass_vtkProp3D()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    


    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( vtkProp3D*);

    // Static methods
    
    ADD_CLASS_STATICMETHOD(IsTypeOf,"int vtkProp3D::IsTypeOf(char const * type) (http://docs.wxwidgets.org/stable/wx_vtkprop3d.html#istypeof).");
    ADD_CLASS_STATICMETHOD(SafeDownCast,"vtkProp3D * vtkProp3D::SafeDownCast(vtkObjectBase * o) (http://docs.wxwidgets.org/stable/wx_vtkprop3d.html#safedowncast).");



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(IsA,"int vtkProp3D::IsA(char const * type)  (http://docs.wxwidgets.org/stable/wx_vtkprop3d.html#isa)")
    ADD_CLASS_METHOD(NewInstance,"vtkProp3D * vtkProp3D::NewInstance()  (http://docs.wxwidgets.org/stable/wx_vtkprop3d.html#newinstance)")
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
    ADD_CLASS_METHOD(PrintSelf,"void vtkProp3D::PrintSelf(ostream & os, vtkIndent indent)  (http://docs.wxwidgets.org/stable/wx_vtkprop3d.html#printself)")
*/
    ADD_CLASS_METHOD(ShallowCopy,"void vtkProp3D::ShallowCopy(vtkProp * prop)  (http://docs.wxwidgets.org/stable/wx_vtkprop3d.html#shallowcopy)")
    ADD_CLASS_METHOD(SetPosition_1,"void vtkProp3D::SetPosition(double _arg1, double _arg2, double _arg3)  (http://docs.wxwidgets.org/stable/wx_vtkprop3d.html#setposition)")
    ADD_CLASS_METHOD(SetPosition,"vtkProp3D::SetPosition()  (http://docs.wxwidgets.org/stable/wx_vtkprop3d.html#setposition)")
    ADD_CLASS_METHOD(SetPosition_2,"void vtkProp3D::SetPosition(double * _arg)  (http://docs.wxwidgets.org/stable/wx_vtkprop3d.html#setposition)")
    ADD_CLASS_METHOD(GetPosition_1,"double * vtkProp3D::GetPosition()  (http://docs.wxwidgets.org/stable/wx_vtkprop3d.html#getposition)")
    ADD_CLASS_METHOD(GetPosition,"vtkProp3D::GetPosition()  (http://docs.wxwidgets.org/stable/wx_vtkprop3d.html#getposition)")
    ADD_CLASS_METHOD(GetPosition_2,"void vtkProp3D::GetPosition(double * data)  (http://docs.wxwidgets.org/stable/wx_vtkprop3d.html#getposition)")
    ADD_CLASS_METHOD(AddPosition_1,"void vtkProp3D::AddPosition(double * deltaPosition)  (http://docs.wxwidgets.org/stable/wx_vtkprop3d.html#addposition)")
    ADD_CLASS_METHOD(AddPosition,"vtkProp3D::AddPosition()  (http://docs.wxwidgets.org/stable/wx_vtkprop3d.html#addposition)")
    ADD_CLASS_METHOD(AddPosition_2,"void vtkProp3D::AddPosition(double deltaX, double deltaY, double deltaZ)  (http://docs.wxwidgets.org/stable/wx_vtkprop3d.html#addposition)")
    ADD_CLASS_METHOD(SetOrigin_1,"void vtkProp3D::SetOrigin(double _arg1, double _arg2, double _arg3)  (http://docs.wxwidgets.org/stable/wx_vtkprop3d.html#setorigin)")
    ADD_CLASS_METHOD(SetOrigin,"vtkProp3D::SetOrigin()  (http://docs.wxwidgets.org/stable/wx_vtkprop3d.html#setorigin)")
    ADD_CLASS_METHOD(SetOrigin_2,"void vtkProp3D::SetOrigin(double * _arg)  (http://docs.wxwidgets.org/stable/wx_vtkprop3d.html#setorigin)")
    ADD_CLASS_METHOD(GetOrigin_1,"double * vtkProp3D::GetOrigin()  (http://docs.wxwidgets.org/stable/wx_vtkprop3d.html#getorigin)")
    ADD_CLASS_METHOD(GetOrigin,"vtkProp3D::GetOrigin()  (http://docs.wxwidgets.org/stable/wx_vtkprop3d.html#getorigin)")
    ADD_CLASS_METHOD(GetOrigin_2,"void vtkProp3D::GetOrigin(double * data)  (http://docs.wxwidgets.org/stable/wx_vtkprop3d.html#getorigin)")
    ADD_CLASS_METHOD(SetScale_1,"void vtkProp3D::SetScale(double _arg1, double _arg2, double _arg3)  (http://docs.wxwidgets.org/stable/wx_vtkprop3d.html#setscale)")
    ADD_CLASS_METHOD(SetScale,"vtkProp3D::SetScale()  (http://docs.wxwidgets.org/stable/wx_vtkprop3d.html#setscale)")
    ADD_CLASS_METHOD(SetScale_2,"void vtkProp3D::SetScale(double * _arg)  (http://docs.wxwidgets.org/stable/wx_vtkprop3d.html#setscale)")
    ADD_CLASS_METHOD(GetScale_1,"double * vtkProp3D::GetScale()  (http://docs.wxwidgets.org/stable/wx_vtkprop3d.html#getscale)")
    ADD_CLASS_METHOD(GetScale,"vtkProp3D::GetScale()  (http://docs.wxwidgets.org/stable/wx_vtkprop3d.html#getscale)")
    ADD_CLASS_METHOD(GetScale_2,"void vtkProp3D::GetScale(double * data)  (http://docs.wxwidgets.org/stable/wx_vtkprop3d.html#getscale)")
    ADD_CLASS_METHOD(SetScale_3,"void vtkProp3D::SetScale(double s)  (http://docs.wxwidgets.org/stable/wx_vtkprop3d.html#setscale)")
    ADD_CLASS_METHOD(SetUserTransform,"void vtkProp3D::SetUserTransform(vtkLinearTransform * transform)  (http://docs.wxwidgets.org/stable/wx_vtkprop3d.html#setusertransform)")
    ADD_CLASS_METHOD(GetUserTransform,"vtkLinearTransform * vtkProp3D::GetUserTransform()  (http://docs.wxwidgets.org/stable/wx_vtkprop3d.html#getusertransform)")
    ADD_CLASS_METHOD(SetUserMatrix,"void vtkProp3D::SetUserMatrix(vtkMatrix4x4 * matrix)  (http://docs.wxwidgets.org/stable/wx_vtkprop3d.html#setusermatrix)")
    ADD_CLASS_METHOD(GetUserMatrix,"vtkMatrix4x4 * vtkProp3D::GetUserMatrix()  (http://docs.wxwidgets.org/stable/wx_vtkprop3d.html#getusermatrix)")
    ADD_CLASS_METHOD(GetMatrix_1,"void vtkProp3D::GetMatrix(vtkMatrix4x4 * m)  (http://docs.wxwidgets.org/stable/wx_vtkprop3d.html#getmatrix)")
    ADD_CLASS_METHOD(GetMatrix,"vtkProp3D::GetMatrix()  (http://docs.wxwidgets.org/stable/wx_vtkprop3d.html#getmatrix)")
    ADD_CLASS_METHOD(GetMatrix_2,"void vtkProp3D::GetMatrix(double * m)  (http://docs.wxwidgets.org/stable/wx_vtkprop3d.html#getmatrix)")
    ADD_CLASS_METHOD(GetBounds,"void vtkProp3D::GetBounds(double * bounds)  (http://docs.wxwidgets.org/stable/wx_vtkprop3d.html#getbounds)")
    ADD_CLASS_METHOD(GetCenter,"double * vtkProp3D::GetCenter()  (http://docs.wxwidgets.org/stable/wx_vtkprop3d.html#getcenter)")
    ADD_CLASS_METHOD(GetXRange,"double * vtkProp3D::GetXRange()  (http://docs.wxwidgets.org/stable/wx_vtkprop3d.html#getxrange)")
    ADD_CLASS_METHOD(GetYRange,"double * vtkProp3D::GetYRange()  (http://docs.wxwidgets.org/stable/wx_vtkprop3d.html#getyrange)")
    ADD_CLASS_METHOD(GetZRange,"double * vtkProp3D::GetZRange()  (http://docs.wxwidgets.org/stable/wx_vtkprop3d.html#getzrange)")
    ADD_CLASS_METHOD(GetLength,"double vtkProp3D::GetLength()  (http://docs.wxwidgets.org/stable/wx_vtkprop3d.html#getlength)")
    ADD_CLASS_METHOD(RotateX,"void vtkProp3D::RotateX(double param0)  (http://docs.wxwidgets.org/stable/wx_vtkprop3d.html#rotatex)")
    ADD_CLASS_METHOD(RotateY,"void vtkProp3D::RotateY(double param0)  (http://docs.wxwidgets.org/stable/wx_vtkprop3d.html#rotatey)")
    ADD_CLASS_METHOD(RotateZ,"void vtkProp3D::RotateZ(double param0)  (http://docs.wxwidgets.org/stable/wx_vtkprop3d.html#rotatez)")
    ADD_CLASS_METHOD(RotateWXYZ,"void vtkProp3D::RotateWXYZ(double param0, double param1, double param2, double param3)  (http://docs.wxwidgets.org/stable/wx_vtkprop3d.html#rotatewxyz)")
    ADD_CLASS_METHOD(SetOrientation_1,"void vtkProp3D::SetOrientation(double param0, double param1, double param2)  (http://docs.wxwidgets.org/stable/wx_vtkprop3d.html#setorientation)")
    ADD_CLASS_METHOD(SetOrientation,"vtkProp3D::SetOrientation()  (http://docs.wxwidgets.org/stable/wx_vtkprop3d.html#setorientation)")
    ADD_CLASS_METHOD(SetOrientation_2,"void vtkProp3D::SetOrientation(double * a)  (http://docs.wxwidgets.org/stable/wx_vtkprop3d.html#setorientation)")
    ADD_CLASS_METHOD(GetOrientation_1,"double * vtkProp3D::GetOrientation()  (http://docs.wxwidgets.org/stable/wx_vtkprop3d.html#getorientation)")
    ADD_CLASS_METHOD(GetOrientation,"vtkProp3D::GetOrientation()  (http://docs.wxwidgets.org/stable/wx_vtkprop3d.html#getorientation)")
    ADD_CLASS_METHOD(GetOrientation_2,"void vtkProp3D::GetOrientation(double * o)  (http://docs.wxwidgets.org/stable/wx_vtkprop3d.html#getorientation)")
    ADD_CLASS_METHOD(GetOrientationWXYZ,"double * vtkProp3D::GetOrientationWXYZ()  (http://docs.wxwidgets.org/stable/wx_vtkprop3d.html#getorientationwxyz)")
    ADD_CLASS_METHOD(AddOrientation_1,"void vtkProp3D::AddOrientation(double param0, double param1, double param2)  (http://docs.wxwidgets.org/stable/wx_vtkprop3d.html#addorientation)")
    ADD_CLASS_METHOD(AddOrientation,"vtkProp3D::AddOrientation()  (http://docs.wxwidgets.org/stable/wx_vtkprop3d.html#addorientation)")
    ADD_CLASS_METHOD(AddOrientation_2,"void vtkProp3D::AddOrientation(double * a)  (http://docs.wxwidgets.org/stable/wx_vtkprop3d.html#addorientation)")
    ADD_CLASS_METHOD(PokeMatrix,"void vtkProp3D::PokeMatrix(vtkMatrix4x4 * matrix)  (http://docs.wxwidgets.org/stable/wx_vtkprop3d.html#pokematrix)")
    ADD_CLASS_METHOD(InitPathTraversal,"void vtkProp3D::InitPathTraversal()  (http://docs.wxwidgets.org/stable/wx_vtkprop3d.html#initpathtraversal)")
    ADD_CLASS_METHOD(GetMTime,"long unsigned int vtkProp3D::GetMTime()  (http://docs.wxwidgets.org/stable/wx_vtkprop3d.html#getmtime)")
    ADD_CLASS_METHOD(GetUserTransformMatrixMTime,"long unsigned int vtkProp3D::GetUserTransformMatrixMTime()  (http://docs.wxwidgets.org/stable/wx_vtkprop3d.html#getusertransformmatrixmtime)")
    ADD_CLASS_METHOD(ComputeMatrix,"void vtkProp3D::ComputeMatrix()  (http://docs.wxwidgets.org/stable/wx_vtkprop3d.html#computematrix)")
    ADD_CLASS_METHOD(GetMatrix_3,"vtkMatrix4x4 * vtkProp3D::GetMatrix()  (http://docs.wxwidgets.org/stable/wx_vtkprop3d.html#getmatrix)")
    ADD_CLASS_METHOD(GetIsIdentity,"int vtkProp3D::GetIsIdentity()  (http://docs.wxwidgets.org/stable/wx_vtkprop3d.html#getisidentity)")





    void AddMethods(WrapClass<vtkProp3D>::ptr this_ptr );
    
    /*
     * Adds the constructor and the static methods to the given context
     */
    static void AddStaticMethods( Variables::ptr& context);

};


#endif // _wrap_vtkProp3D_h
