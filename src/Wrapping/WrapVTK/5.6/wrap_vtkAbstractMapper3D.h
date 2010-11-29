/**
 * C++ Interface: wrap_vtkAbstractMapper3D
 *
 * Description: wrapping vtkAbstractMapper3D
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_vtkAbstractMapper3D_h_
#define _wrap_vtkAbstractMapper3D_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "vtk_includes.h"

// include what is needed for inheritence and for types ...

#include "wrap_vtkAbstractMapper.h"



AMI_DECLARE_TYPE(vtkAbstractMapper3D);

// TODO: check for inheritence ...
class WrapClass_vtkAbstractMapper3D : public WrapClass<vtkAbstractMapper3D>
    , public   WrapClass_vtkAbstractMapper
{
  DEFINE_CLASS(WrapClass_vtkAbstractMapper3D);

  protected:
    typedef WrapClass<vtkAbstractMapper3D>::ptr _parentclass_ptr;
    typedef vtkAbstractMapper3D ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<vtkAbstractMapper3D>& GetObj() const { return WrapClass<vtkAbstractMapper3D>::GetObj(); }

    /// Constructor
    WrapClass_vtkAbstractMapper3D(boost::shared_ptr<vtkAbstractMapper3D > si): 
    WrapClass<vtkAbstractMapper3D>(si)
    , WrapClass_vtkAbstractMapper(si)
    {}

    /// Destructor
    ~WrapClass_vtkAbstractMapper3D()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    


    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( vtkAbstractMapper3D*);

    // Static methods
    
    ADD_CLASS_STATICMETHOD(IsTypeOf,"int vtkAbstractMapper3D::IsTypeOf(char const * type) (http://docs.wxwidgets.org/stable/wx_vtkabstractmapper3d.html#istypeof).");
    ADD_CLASS_STATICMETHOD(SafeDownCast,"vtkAbstractMapper3D * vtkAbstractMapper3D::SafeDownCast(vtkObjectBase * o) (http://docs.wxwidgets.org/stable/wx_vtkabstractmapper3d.html#safedowncast).");



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(IsA,"int vtkAbstractMapper3D::IsA(char const * type)  (http://docs.wxwidgets.org/stable/wx_vtkabstractmapper3d.html#isa)")
    ADD_CLASS_METHOD(NewInstance,"vtkAbstractMapper3D * vtkAbstractMapper3D::NewInstance()  (http://docs.wxwidgets.org/stable/wx_vtkabstractmapper3d.html#newinstance)")
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
    ADD_CLASS_METHOD(PrintSelf,"void vtkAbstractMapper3D::PrintSelf(ostream & os, vtkIndent indent)  (http://docs.wxwidgets.org/stable/wx_vtkabstractmapper3d.html#printself)")
*/
    ADD_CLASS_METHOD(GetBounds,"void vtkAbstractMapper3D::GetBounds(double * bounds)  (http://docs.wxwidgets.org/stable/wx_vtkabstractmapper3d.html#getbounds)")
    ADD_CLASS_METHOD(GetCenter_1,"double * vtkAbstractMapper3D::GetCenter()  (http://docs.wxwidgets.org/stable/wx_vtkabstractmapper3d.html#getcenter)")
    ADD_CLASS_METHOD(GetCenter,"vtkAbstractMapper3D::GetCenter()  (http://docs.wxwidgets.org/stable/wx_vtkabstractmapper3d.html#getcenter)")
    ADD_CLASS_METHOD(GetCenter_2,"void vtkAbstractMapper3D::GetCenter(double * center)  (http://docs.wxwidgets.org/stable/wx_vtkabstractmapper3d.html#getcenter)")
    ADD_CLASS_METHOD(GetLength,"double vtkAbstractMapper3D::GetLength()  (http://docs.wxwidgets.org/stable/wx_vtkabstractmapper3d.html#getlength)")
    ADD_CLASS_METHOD(IsARayCastMapper,"int vtkAbstractMapper3D::IsARayCastMapper()  (http://docs.wxwidgets.org/stable/wx_vtkabstractmapper3d.html#isaraycastmapper)")
    ADD_CLASS_METHOD(IsARenderIntoImageMapper,"int vtkAbstractMapper3D::IsARenderIntoImageMapper()  (http://docs.wxwidgets.org/stable/wx_vtkabstractmapper3d.html#isarenderintoimagemapper)")





    void AddMethods(WrapClass<vtkAbstractMapper3D>::ptr this_ptr );

};


#endif // _wrap_vtkAbstractMapper3D_h
