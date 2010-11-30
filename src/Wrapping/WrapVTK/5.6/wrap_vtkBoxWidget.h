/**
 * C++ Interface: wrap_vtkBoxWidget
 *
 * Description: wrapping vtkBoxWidget
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_vtkBoxWidget_h_
#define _wrap_vtkBoxWidget_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "vtk_includes.h"

// include what is needed for inheritence and for types ...

#include "wrap_vtk3DWidget.h"



AMI_DECLARE_TYPE(vtkBoxWidget);

// TODO: check for inheritence ...
class WrapClass_vtkBoxWidget : public WrapClass<vtkBoxWidget>
    , public   WrapClass_vtk3DWidget
{
  DEFINE_CLASS(WrapClass_vtkBoxWidget);

  protected:
    typedef WrapClass<vtkBoxWidget>::ptr _parentclass_ptr;
    typedef vtkBoxWidget ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<vtkBoxWidget>& GetObj() const { return WrapClass<vtkBoxWidget>::GetObj(); }

    /// Constructor
    WrapClass_vtkBoxWidget(boost::shared_ptr<vtkBoxWidget > si): 
    WrapClass<vtkBoxWidget>(si)
    , WrapClass_vtk3DWidget(si)
    {}

    /// Destructor
    ~WrapClass_vtkBoxWidget()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( vtkBoxWidget*);

    // Static methods
    
    ADD_CLASS_STATICMETHOD(New,"vtkBoxWidget * vtkBoxWidget::New() (http://docs.wxwidgets.org/stable/wx_vtkboxwidget.html#new).");
    ADD_CLASS_STATICMETHOD(IsTypeOf,"int vtkBoxWidget::IsTypeOf(char const * type) (http://docs.wxwidgets.org/stable/wx_vtkboxwidget.html#istypeof).");
    ADD_CLASS_STATICMETHOD(SafeDownCast,"vtkBoxWidget * vtkBoxWidget::SafeDownCast(vtkObjectBase * o) (http://docs.wxwidgets.org/stable/wx_vtkboxwidget.html#safedowncast).");



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(IsA,"int vtkBoxWidget::IsA(char const * type)  (http://docs.wxwidgets.org/stable/wx_vtkboxwidget.html#isa)")
    ADD_CLASS_METHOD(NewInstance,"vtkBoxWidget * vtkBoxWidget::NewInstance()  (http://docs.wxwidgets.org/stable/wx_vtkboxwidget.html#newinstance)")
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
    ADD_CLASS_METHOD(PrintSelf,"void vtkBoxWidget::PrintSelf(ostream & os, vtkIndent indent)  (http://docs.wxwidgets.org/stable/wx_vtkboxwidget.html#printself)")
*/
    ADD_CLASS_METHOD(SetEnabled,"void vtkBoxWidget::SetEnabled(int param0)  (http://docs.wxwidgets.org/stable/wx_vtkboxwidget.html#setenabled)")
    ADD_CLASS_METHOD(PlaceWidget_1,"void vtkBoxWidget::PlaceWidget(double * bounds)  (http://docs.wxwidgets.org/stable/wx_vtkboxwidget.html#placewidget)")
    ADD_CLASS_METHOD(PlaceWidget,"vtkBoxWidget::PlaceWidget()  (http://docs.wxwidgets.org/stable/wx_vtkboxwidget.html#placewidget)")
    ADD_CLASS_METHOD(PlaceWidget_2,"void vtkBoxWidget::PlaceWidget()  (http://docs.wxwidgets.org/stable/wx_vtkboxwidget.html#placewidget)")
    ADD_CLASS_METHOD(PlaceWidget_3,"void vtkBoxWidget::PlaceWidget(double xmin, double xmax, double ymin, double ymax, double zmin, double zmax)  (http://docs.wxwidgets.org/stable/wx_vtkboxwidget.html#placewidget)")
    ADD_CLASS_METHOD(GetPlanes,"void vtkBoxWidget::GetPlanes(vtkPlanes * planes)  (http://docs.wxwidgets.org/stable/wx_vtkboxwidget.html#getplanes)")
    ADD_CLASS_METHOD(SetInsideOut,"void vtkBoxWidget::SetInsideOut(int _arg)  (http://docs.wxwidgets.org/stable/wx_vtkboxwidget.html#setinsideout)")
    ADD_CLASS_METHOD(GetInsideOut,"int vtkBoxWidget::GetInsideOut()  (http://docs.wxwidgets.org/stable/wx_vtkboxwidget.html#getinsideout)")
    ADD_CLASS_METHOD(InsideOutOn,"void vtkBoxWidget::InsideOutOn()  (http://docs.wxwidgets.org/stable/wx_vtkboxwidget.html#insideouton)")
    ADD_CLASS_METHOD(InsideOutOff,"void vtkBoxWidget::InsideOutOff()  (http://docs.wxwidgets.org/stable/wx_vtkboxwidget.html#insideoutoff)")
    ADD_CLASS_METHOD(GetTransform,"void vtkBoxWidget::GetTransform(vtkTransform * t)  (http://docs.wxwidgets.org/stable/wx_vtkboxwidget.html#gettransform)")
    ADD_CLASS_METHOD(SetTransform,"void vtkBoxWidget::SetTransform(vtkTransform * t)  (http://docs.wxwidgets.org/stable/wx_vtkboxwidget.html#settransform)")
    ADD_CLASS_METHOD(GetPolyData,"void vtkBoxWidget::GetPolyData(vtkPolyData * pd)  (http://docs.wxwidgets.org/stable/wx_vtkboxwidget.html#getpolydata)")
    ADD_CLASS_METHOD(GetHandleProperty,"vtkProperty * vtkBoxWidget::GetHandleProperty()  (http://docs.wxwidgets.org/stable/wx_vtkboxwidget.html#gethandleproperty)")
    ADD_CLASS_METHOD(GetSelectedHandleProperty,"vtkProperty * vtkBoxWidget::GetSelectedHandleProperty()  (http://docs.wxwidgets.org/stable/wx_vtkboxwidget.html#getselectedhandleproperty)")
    ADD_CLASS_METHOD(HandlesOn,"void vtkBoxWidget::HandlesOn()  (http://docs.wxwidgets.org/stable/wx_vtkboxwidget.html#handleson)")
    ADD_CLASS_METHOD(HandlesOff,"void vtkBoxWidget::HandlesOff()  (http://docs.wxwidgets.org/stable/wx_vtkboxwidget.html#handlesoff)")
    ADD_CLASS_METHOD(GetFaceProperty,"vtkProperty * vtkBoxWidget::GetFaceProperty()  (http://docs.wxwidgets.org/stable/wx_vtkboxwidget.html#getfaceproperty)")
    ADD_CLASS_METHOD(GetSelectedFaceProperty,"vtkProperty * vtkBoxWidget::GetSelectedFaceProperty()  (http://docs.wxwidgets.org/stable/wx_vtkboxwidget.html#getselectedfaceproperty)")
    ADD_CLASS_METHOD(GetOutlineProperty,"vtkProperty * vtkBoxWidget::GetOutlineProperty()  (http://docs.wxwidgets.org/stable/wx_vtkboxwidget.html#getoutlineproperty)")
    ADD_CLASS_METHOD(GetSelectedOutlineProperty,"vtkProperty * vtkBoxWidget::GetSelectedOutlineProperty()  (http://docs.wxwidgets.org/stable/wx_vtkboxwidget.html#getselectedoutlineproperty)")
    ADD_CLASS_METHOD(SetOutlineFaceWires,"void vtkBoxWidget::SetOutlineFaceWires(int param0)  (http://docs.wxwidgets.org/stable/wx_vtkboxwidget.html#setoutlinefacewires)")
    ADD_CLASS_METHOD(GetOutlineFaceWires,"int vtkBoxWidget::GetOutlineFaceWires()  (http://docs.wxwidgets.org/stable/wx_vtkboxwidget.html#getoutlinefacewires)")
    ADD_CLASS_METHOD(OutlineFaceWiresOn,"void vtkBoxWidget::OutlineFaceWiresOn()  (http://docs.wxwidgets.org/stable/wx_vtkboxwidget.html#outlinefacewireson)")
    ADD_CLASS_METHOD(OutlineFaceWiresOff,"void vtkBoxWidget::OutlineFaceWiresOff()  (http://docs.wxwidgets.org/stable/wx_vtkboxwidget.html#outlinefacewiresoff)")
    ADD_CLASS_METHOD(SetOutlineCursorWires,"void vtkBoxWidget::SetOutlineCursorWires(int param0)  (http://docs.wxwidgets.org/stable/wx_vtkboxwidget.html#setoutlinecursorwires)")
    ADD_CLASS_METHOD(GetOutlineCursorWires,"int vtkBoxWidget::GetOutlineCursorWires()  (http://docs.wxwidgets.org/stable/wx_vtkboxwidget.html#getoutlinecursorwires)")
    ADD_CLASS_METHOD(OutlineCursorWiresOn,"void vtkBoxWidget::OutlineCursorWiresOn()  (http://docs.wxwidgets.org/stable/wx_vtkboxwidget.html#outlinecursorwireson)")
    ADD_CLASS_METHOD(OutlineCursorWiresOff,"void vtkBoxWidget::OutlineCursorWiresOff()  (http://docs.wxwidgets.org/stable/wx_vtkboxwidget.html#outlinecursorwiresoff)")
    ADD_CLASS_METHOD(SetTranslationEnabled,"void vtkBoxWidget::SetTranslationEnabled(int _arg)  (http://docs.wxwidgets.org/stable/wx_vtkboxwidget.html#settranslationenabled)")
    ADD_CLASS_METHOD(GetTranslationEnabled,"int vtkBoxWidget::GetTranslationEnabled()  (http://docs.wxwidgets.org/stable/wx_vtkboxwidget.html#gettranslationenabled)")
    ADD_CLASS_METHOD(TranslationEnabledOn,"void vtkBoxWidget::TranslationEnabledOn()  (http://docs.wxwidgets.org/stable/wx_vtkboxwidget.html#translationenabledon)")
    ADD_CLASS_METHOD(TranslationEnabledOff,"void vtkBoxWidget::TranslationEnabledOff()  (http://docs.wxwidgets.org/stable/wx_vtkboxwidget.html#translationenabledoff)")
    ADD_CLASS_METHOD(SetScalingEnabled,"void vtkBoxWidget::SetScalingEnabled(int _arg)  (http://docs.wxwidgets.org/stable/wx_vtkboxwidget.html#setscalingenabled)")
    ADD_CLASS_METHOD(GetScalingEnabled,"int vtkBoxWidget::GetScalingEnabled()  (http://docs.wxwidgets.org/stable/wx_vtkboxwidget.html#getscalingenabled)")
    ADD_CLASS_METHOD(ScalingEnabledOn,"void vtkBoxWidget::ScalingEnabledOn()  (http://docs.wxwidgets.org/stable/wx_vtkboxwidget.html#scalingenabledon)")
    ADD_CLASS_METHOD(ScalingEnabledOff,"void vtkBoxWidget::ScalingEnabledOff()  (http://docs.wxwidgets.org/stable/wx_vtkboxwidget.html#scalingenabledoff)")
    ADD_CLASS_METHOD(SetRotationEnabled,"void vtkBoxWidget::SetRotationEnabled(int _arg)  (http://docs.wxwidgets.org/stable/wx_vtkboxwidget.html#setrotationenabled)")
    ADD_CLASS_METHOD(GetRotationEnabled,"int vtkBoxWidget::GetRotationEnabled()  (http://docs.wxwidgets.org/stable/wx_vtkboxwidget.html#getrotationenabled)")
    ADD_CLASS_METHOD(RotationEnabledOn,"void vtkBoxWidget::RotationEnabledOn()  (http://docs.wxwidgets.org/stable/wx_vtkboxwidget.html#rotationenabledon)")
    ADD_CLASS_METHOD(RotationEnabledOff,"void vtkBoxWidget::RotationEnabledOff()  (http://docs.wxwidgets.org/stable/wx_vtkboxwidget.html#rotationenabledoff)")





    void AddMethods(WrapClass<vtkBoxWidget>::ptr this_ptr );
    
    /*
     * Adds the constructor and the static methods to the given context
     */
    static void AddStaticMethods( Variables::ptr& context);

};


#endif // _wrap_vtkBoxWidget_h
