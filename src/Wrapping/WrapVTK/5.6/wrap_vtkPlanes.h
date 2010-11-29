/**
 * C++ Interface: wrap_vtkPlanes
 *
 * Description: wrapping vtkPlanes
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_vtkPlanes_h_
#define _wrap_vtkPlanes_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "vtk_includes.h"

// include what is needed for inheritence and for types ...

#include "wrap_vtkImplicitFunction.h"



AMI_DECLARE_TYPE(vtkPlanes);

// TODO: check for inheritence ...
class WrapClass_vtkPlanes : public WrapClass<vtkPlanes>
    , public   WrapClass_vtkImplicitFunction
{
  DEFINE_CLASS(WrapClass_vtkPlanes);

  protected:
    typedef WrapClass<vtkPlanes>::ptr _parentclass_ptr;
    typedef vtkPlanes ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<vtkPlanes>& GetObj() const { return WrapClass<vtkPlanes>::GetObj(); }

    /// Constructor
    WrapClass_vtkPlanes(boost::shared_ptr<vtkPlanes > si): 
    WrapClass<vtkPlanes>(si)
    , WrapClass_vtkImplicitFunction(si)
    {}

    /// Destructor
    ~WrapClass_vtkPlanes()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( vtkPlanes*);

    // Static methods
    
    ADD_CLASS_STATICMETHOD(New,"vtkPlanes * vtkPlanes::New() (http://docs.wxwidgets.org/stable/wx_vtkplanes.html#new).");
    ADD_CLASS_STATICMETHOD(IsTypeOf,"int vtkPlanes::IsTypeOf(char const * type) (http://docs.wxwidgets.org/stable/wx_vtkplanes.html#istypeof).");
    ADD_CLASS_STATICMETHOD(SafeDownCast,"vtkPlanes * vtkPlanes::SafeDownCast(vtkObjectBase * o) (http://docs.wxwidgets.org/stable/wx_vtkplanes.html#safedowncast).");



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(IsA,"int vtkPlanes::IsA(char const * type)  (http://docs.wxwidgets.org/stable/wx_vtkplanes.html#isa)")
    ADD_CLASS_METHOD(NewInstance,"vtkPlanes * vtkPlanes::NewInstance()  (http://docs.wxwidgets.org/stable/wx_vtkplanes.html#newinstance)")
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
    ADD_CLASS_METHOD(PrintSelf,"void vtkPlanes::PrintSelf(ostream & os, vtkIndent indent)  (http://docs.wxwidgets.org/stable/wx_vtkplanes.html#printself)")
*/
    ADD_CLASS_METHOD(EvaluateFunction_1,"double vtkPlanes::EvaluateFunction(double * x)  (http://docs.wxwidgets.org/stable/wx_vtkplanes.html#evaluatefunction)")
    ADD_CLASS_METHOD(EvaluateFunction,"vtkPlanes::EvaluateFunction()  (http://docs.wxwidgets.org/stable/wx_vtkplanes.html#evaluatefunction)")
    ADD_CLASS_METHOD(EvaluateFunction_2,"double vtkPlanes::EvaluateFunction(double x, double y, double z)  (http://docs.wxwidgets.org/stable/wx_vtkplanes.html#evaluatefunction)")
    ADD_CLASS_METHOD(EvaluateGradient,"void vtkPlanes::EvaluateGradient(double * x, double * n)  (http://docs.wxwidgets.org/stable/wx_vtkplanes.html#evaluategradient)")
    ADD_CLASS_METHOD(SetPoints,"void vtkPlanes::SetPoints(vtkPoints * param0)  (http://docs.wxwidgets.org/stable/wx_vtkplanes.html#setpoints)")
    ADD_CLASS_METHOD(GetPoints,"vtkPoints * vtkPlanes::GetPoints()  (http://docs.wxwidgets.org/stable/wx_vtkplanes.html#getpoints)")
    ADD_CLASS_METHOD(SetNormals,"void vtkPlanes::SetNormals(vtkDataArray * normals)  (http://docs.wxwidgets.org/stable/wx_vtkplanes.html#setnormals)")
    ADD_CLASS_METHOD(GetNormals,"vtkDataArray * vtkPlanes::GetNormals()  (http://docs.wxwidgets.org/stable/wx_vtkplanes.html#getnormals)")
    ADD_CLASS_METHOD(SetFrustumPlanes,"void vtkPlanes::SetFrustumPlanes(double * planes)  (http://docs.wxwidgets.org/stable/wx_vtkplanes.html#setfrustumplanes)")
    ADD_CLASS_METHOD(SetBounds_1,"void vtkPlanes::SetBounds(double * bounds)  (http://docs.wxwidgets.org/stable/wx_vtkplanes.html#setbounds)")
    ADD_CLASS_METHOD(SetBounds,"vtkPlanes::SetBounds()  (http://docs.wxwidgets.org/stable/wx_vtkplanes.html#setbounds)")
    ADD_CLASS_METHOD(SetBounds_2,"void vtkPlanes::SetBounds(double xmin, double xmax, double ymin, double ymax, double zmin, double zmax)  (http://docs.wxwidgets.org/stable/wx_vtkplanes.html#setbounds)")
    ADD_CLASS_METHOD(GetNumberOfPlanes,"int vtkPlanes::GetNumberOfPlanes()  (http://docs.wxwidgets.org/stable/wx_vtkplanes.html#getnumberofplanes)")
/* The following types are missing: vtkPlane
    ADD_CLASS_METHOD(GetPlane_1,"vtkPlane * vtkPlanes::GetPlane(int i)  (http://docs.wxwidgets.org/stable/wx_vtkplanes.html#getplane)")
*/
    ADD_CLASS_METHOD(GetPlane,"vtkPlanes::GetPlane()  (http://docs.wxwidgets.org/stable/wx_vtkplanes.html#getplane)")
/* The following types are missing: vtkPlane
    ADD_CLASS_METHOD(GetPlane_2,"void vtkPlanes::GetPlane(int i, vtkPlane * plane)  (http://docs.wxwidgets.org/stable/wx_vtkplanes.html#getplane)")
*/





    void AddMethods(WrapClass<vtkPlanes>::ptr this_ptr );

};


#endif // _wrap_vtkPlanes_h
