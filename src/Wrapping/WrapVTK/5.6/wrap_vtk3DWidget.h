/**
 * C++ Interface: wrap_vtk3DWidget
 *
 * Description: wrapping vtk3DWidget
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_vtk3DWidget_h_
#define _wrap_vtk3DWidget_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "vtk3DWidget.h"

// include what is needed for inheritence and for types ...

#include "wrap_vtkInteractorObserver.h"


#ifndef vtk3DWidget_declared
  #define vtk3DWidget_declared
  AMI_DECLARE_TYPE(vtk3DWidget);
#endif

// TODO: check for inheritence ...
class WrapClass_vtk3DWidget : public WrapClass<vtk3DWidget>
    , public   WrapClass_vtkInteractorObserver
{
  DEFINE_CLASS(WrapClass_vtk3DWidget);

  protected:
    typedef WrapClass<vtk3DWidget>::ptr _parentclass_ptr;
    typedef vtk3DWidget ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<vtk3DWidget>& GetObj() const { return WrapClass<vtk3DWidget>::GetObj(); }

    /// Constructor
    WrapClass_vtk3DWidget(boost::shared_ptr<vtk3DWidget > si): 
    WrapClass<vtk3DWidget>(si)
    , WrapClass_vtkInteractorObserver(si)
    {}

    /// Destructor
    ~WrapClass_vtk3DWidget()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    


    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( vtk3DWidget*);

    // Static methods
    
    ADD_CLASS_STATICMETHOD(IsTypeOf,"int vtk3DWidget::IsTypeOf(char const * type) (http://docs.wxwidgets.org/stable/wx_vtk3dwidget.html#istypeof).");
    ADD_CLASS_STATICMETHOD(SafeDownCast,"vtk3DWidget * vtk3DWidget::SafeDownCast(vtkObjectBase * o) (http://docs.wxwidgets.org/stable/wx_vtk3dwidget.html#safedowncast).");



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(IsA,"int vtk3DWidget::IsA(char const * type)  (http://docs.wxwidgets.org/stable/wx_vtk3dwidget.html#isa)")
    ADD_CLASS_METHOD(NewInstance,"vtk3DWidget * vtk3DWidget::NewInstance()  (http://docs.wxwidgets.org/stable/wx_vtk3dwidget.html#newinstance)")
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
    ADD_CLASS_METHOD(PrintSelf,"void vtk3DWidget::PrintSelf(ostream & os, vtkIndent indent)  (http://docs.wxwidgets.org/stable/wx_vtk3dwidget.html#printself)")
*/
    ADD_CLASS_METHOD(PlaceWidget_1,"void vtk3DWidget::PlaceWidget()  (http://docs.wxwidgets.org/stable/wx_vtk3dwidget.html#placewidget)")
    ADD_CLASS_METHOD(PlaceWidget,"vtk3DWidget::PlaceWidget()  (http://docs.wxwidgets.org/stable/wx_vtk3dwidget.html#placewidget)")
    ADD_CLASS_METHOD(PlaceWidget_2,"void vtk3DWidget::PlaceWidget(double xmin, double xmax, double ymin, double ymax, double zmin, double zmax)  (http://docs.wxwidgets.org/stable/wx_vtk3dwidget.html#placewidget)")
    ADD_CLASS_METHOD(SetProp3D,"void vtk3DWidget::SetProp3D(vtkProp3D * param0)  (http://docs.wxwidgets.org/stable/wx_vtk3dwidget.html#setprop3d)")
    ADD_CLASS_METHOD(GetProp3D,"vtkProp3D * vtk3DWidget::GetProp3D()  (http://docs.wxwidgets.org/stable/wx_vtk3dwidget.html#getprop3d)")
    ADD_CLASS_METHOD(SetInput,"void vtk3DWidget::SetInput(vtkDataSet * param0)  (http://docs.wxwidgets.org/stable/wx_vtk3dwidget.html#setinput)")
    ADD_CLASS_METHOD(GetInput,"vtkDataSet * vtk3DWidget::GetInput()  (http://docs.wxwidgets.org/stable/wx_vtk3dwidget.html#getinput)")
    ADD_CLASS_METHOD(SetPlaceFactor,"void vtk3DWidget::SetPlaceFactor(double _arg)  (http://docs.wxwidgets.org/stable/wx_vtk3dwidget.html#setplacefactor)")
    ADD_CLASS_METHOD(GetPlaceFactorMinValue,"double vtk3DWidget::GetPlaceFactorMinValue()  (http://docs.wxwidgets.org/stable/wx_vtk3dwidget.html#getplacefactorminvalue)")
    ADD_CLASS_METHOD(GetPlaceFactorMaxValue,"double vtk3DWidget::GetPlaceFactorMaxValue()  (http://docs.wxwidgets.org/stable/wx_vtk3dwidget.html#getplacefactormaxvalue)")
    ADD_CLASS_METHOD(GetPlaceFactor,"double vtk3DWidget::GetPlaceFactor()  (http://docs.wxwidgets.org/stable/wx_vtk3dwidget.html#getplacefactor)")
    ADD_CLASS_METHOD(SetHandleSize,"void vtk3DWidget::SetHandleSize(double _arg)  (http://docs.wxwidgets.org/stable/wx_vtk3dwidget.html#sethandlesize)")
    ADD_CLASS_METHOD(GetHandleSizeMinValue,"double vtk3DWidget::GetHandleSizeMinValue()  (http://docs.wxwidgets.org/stable/wx_vtk3dwidget.html#gethandlesizeminvalue)")
    ADD_CLASS_METHOD(GetHandleSizeMaxValue,"double vtk3DWidget::GetHandleSizeMaxValue()  (http://docs.wxwidgets.org/stable/wx_vtk3dwidget.html#gethandlesizemaxvalue)")
    ADD_CLASS_METHOD(GetHandleSize,"double vtk3DWidget::GetHandleSize()  (http://docs.wxwidgets.org/stable/wx_vtk3dwidget.html#gethandlesize)")





    void AddMethods(WrapClass<vtk3DWidget>::ptr this_ptr );
    

};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClassvtk3DWidget_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_vtk3DWidget_h
