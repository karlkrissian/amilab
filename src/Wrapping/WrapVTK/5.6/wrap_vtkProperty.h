/**
 * C++ Interface: wrap_vtkProperty
 *
 * Description: wrapping vtkProperty
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_vtkProperty_h_
#define _wrap_vtkProperty_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "vtkProperty.h"

// include what is needed for inheritence and for types ...

#include "wrap_vtkObject.h"



AMI_DECLARE_TYPE(vtkProperty);

// TODO: check for inheritence ...
class WrapClass_vtkProperty : public WrapClass<vtkProperty>
    , public   WrapClass_vtkObject
{
  DEFINE_CLASS(WrapClass_vtkProperty);

  protected:
    typedef WrapClass<vtkProperty>::ptr _parentclass_ptr;
    typedef vtkProperty ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<vtkProperty>& GetObj() const { return WrapClass<vtkProperty>::GetObj(); }

    /// Constructor
    WrapClass_vtkProperty(boost::shared_ptr<vtkProperty > si): 
    WrapClass<vtkProperty>(si)
    , WrapClass_vtkObject(si)
    {}

    /// Destructor
    ~WrapClass_vtkProperty()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( vtkProperty*);

    // Static methods
    
    ADD_CLASS_STATICMETHOD(IsTypeOf,"int vtkProperty::IsTypeOf(char const * type) (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#istypeof).");
    ADD_CLASS_STATICMETHOD(SafeDownCast,"vtkProperty * vtkProperty::SafeDownCast(vtkObjectBase * o) (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#safedowncast).");
    ADD_CLASS_STATICMETHOD(New,"vtkProperty * vtkProperty::New() (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#new).");



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(IsA,"int vtkProperty::IsA(char const * type)  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#isa)")
    ADD_CLASS_METHOD(NewInstance,"vtkProperty * vtkProperty::NewInstance()  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#newinstance)")
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
    ADD_CLASS_METHOD(PrintSelf,"void vtkProperty::PrintSelf(ostream & os, vtkIndent indent)  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#printself)")
*/
    ADD_CLASS_METHOD(DeepCopy,"void vtkProperty::DeepCopy(vtkProperty * p)  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#deepcopy)")
    ADD_CLASS_METHOD(Render,"void vtkProperty::Render(vtkActor * param0, vtkRenderer * param1)  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#render)")
    ADD_CLASS_METHOD(BackfaceRender,"void vtkProperty::BackfaceRender(vtkActor * param0, vtkRenderer * param1)  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#backfacerender)")
    ADD_CLASS_METHOD(PostRender,"void vtkProperty::PostRender(vtkActor * param0, vtkRenderer * param1)  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#postrender)")
    ADD_CLASS_METHOD(GetLighting,"bool vtkProperty::GetLighting()  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#getlighting)")
    ADD_CLASS_METHOD(SetLighting,"void vtkProperty::SetLighting(bool _arg)  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#setlighting)")
    ADD_CLASS_METHOD(LightingOn,"void vtkProperty::LightingOn()  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#lightingon)")
    ADD_CLASS_METHOD(LightingOff,"void vtkProperty::LightingOff()  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#lightingoff)")
    ADD_CLASS_METHOD(SetInterpolation,"void vtkProperty::SetInterpolation(int _arg)  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#setinterpolation)")
    ADD_CLASS_METHOD(GetInterpolationMinValue,"int vtkProperty::GetInterpolationMinValue()  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#getinterpolationminvalue)")
    ADD_CLASS_METHOD(GetInterpolationMaxValue,"int vtkProperty::GetInterpolationMaxValue()  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#getinterpolationmaxvalue)")
    ADD_CLASS_METHOD(GetInterpolation,"int vtkProperty::GetInterpolation()  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#getinterpolation)")
    ADD_CLASS_METHOD(SetInterpolationToFlat,"void vtkProperty::SetInterpolationToFlat()  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#setinterpolationtoflat)")
    ADD_CLASS_METHOD(SetInterpolationToGouraud,"void vtkProperty::SetInterpolationToGouraud()  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#setinterpolationtogouraud)")
    ADD_CLASS_METHOD(SetInterpolationToPhong,"void vtkProperty::SetInterpolationToPhong()  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#setinterpolationtophong)")
    ADD_CLASS_METHOD(GetInterpolationAsString,"char const * vtkProperty::GetInterpolationAsString()  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#getinterpolationasstring)")
    ADD_CLASS_METHOD(SetRepresentation,"void vtkProperty::SetRepresentation(int _arg)  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#setrepresentation)")
    ADD_CLASS_METHOD(GetRepresentationMinValue,"int vtkProperty::GetRepresentationMinValue()  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#getrepresentationminvalue)")
    ADD_CLASS_METHOD(GetRepresentationMaxValue,"int vtkProperty::GetRepresentationMaxValue()  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#getrepresentationmaxvalue)")
    ADD_CLASS_METHOD(GetRepresentation,"int vtkProperty::GetRepresentation()  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#getrepresentation)")
    ADD_CLASS_METHOD(SetRepresentationToPoints,"void vtkProperty::SetRepresentationToPoints()  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#setrepresentationtopoints)")
    ADD_CLASS_METHOD(SetRepresentationToWireframe,"void vtkProperty::SetRepresentationToWireframe()  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#setrepresentationtowireframe)")
    ADD_CLASS_METHOD(SetRepresentationToSurface,"void vtkProperty::SetRepresentationToSurface()  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#setrepresentationtosurface)")
    ADD_CLASS_METHOD(GetRepresentationAsString,"char const * vtkProperty::GetRepresentationAsString()  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#getrepresentationasstring)")
    ADD_CLASS_METHOD(SetColor_1,"void vtkProperty::SetColor(double r, double g, double b)  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#setcolor)")
    ADD_CLASS_METHOD(SetColor,"vtkProperty::SetColor()  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#setcolor)")
    ADD_CLASS_METHOD(SetColor_2,"void vtkProperty::SetColor(double * a)  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#setcolor)")
    ADD_CLASS_METHOD(GetColor_1,"double * vtkProperty::GetColor()  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#getcolor)")
    ADD_CLASS_METHOD(GetColor,"vtkProperty::GetColor()  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#getcolor)")
    ADD_CLASS_METHOD(GetColor_2,"void vtkProperty::GetColor(double * rgb)  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#getcolor)")
    ADD_CLASS_METHOD(GetColor_3,"void vtkProperty::GetColor(double & r, double & g, double & b)  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#getcolor)")
    ADD_CLASS_METHOD(SetAmbient,"void vtkProperty::SetAmbient(double _arg)  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#setambient)")
    ADD_CLASS_METHOD(GetAmbientMinValue,"double vtkProperty::GetAmbientMinValue()  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#getambientminvalue)")
    ADD_CLASS_METHOD(GetAmbientMaxValue,"double vtkProperty::GetAmbientMaxValue()  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#getambientmaxvalue)")
    ADD_CLASS_METHOD(GetAmbient,"double vtkProperty::GetAmbient()  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#getambient)")
    ADD_CLASS_METHOD(SetDiffuse,"void vtkProperty::SetDiffuse(double _arg)  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#setdiffuse)")
    ADD_CLASS_METHOD(GetDiffuseMinValue,"double vtkProperty::GetDiffuseMinValue()  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#getdiffuseminvalue)")
    ADD_CLASS_METHOD(GetDiffuseMaxValue,"double vtkProperty::GetDiffuseMaxValue()  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#getdiffusemaxvalue)")
    ADD_CLASS_METHOD(GetDiffuse,"double vtkProperty::GetDiffuse()  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#getdiffuse)")
    ADD_CLASS_METHOD(SetSpecular,"void vtkProperty::SetSpecular(double _arg)  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#setspecular)")
    ADD_CLASS_METHOD(GetSpecularMinValue,"double vtkProperty::GetSpecularMinValue()  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#getspecularminvalue)")
    ADD_CLASS_METHOD(GetSpecularMaxValue,"double vtkProperty::GetSpecularMaxValue()  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#getspecularmaxvalue)")
    ADD_CLASS_METHOD(GetSpecular,"double vtkProperty::GetSpecular()  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#getspecular)")
    ADD_CLASS_METHOD(SetSpecularPower,"void vtkProperty::SetSpecularPower(double _arg)  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#setspecularpower)")
    ADD_CLASS_METHOD(GetSpecularPowerMinValue,"double vtkProperty::GetSpecularPowerMinValue()  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#getspecularpowerminvalue)")
    ADD_CLASS_METHOD(GetSpecularPowerMaxValue,"double vtkProperty::GetSpecularPowerMaxValue()  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#getspecularpowermaxvalue)")
    ADD_CLASS_METHOD(GetSpecularPower,"double vtkProperty::GetSpecularPower()  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#getspecularpower)")
    ADD_CLASS_METHOD(SetOpacity,"void vtkProperty::SetOpacity(double _arg)  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#setopacity)")
    ADD_CLASS_METHOD(GetOpacityMinValue,"double vtkProperty::GetOpacityMinValue()  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#getopacityminvalue)")
    ADD_CLASS_METHOD(GetOpacityMaxValue,"double vtkProperty::GetOpacityMaxValue()  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#getopacitymaxvalue)")
    ADD_CLASS_METHOD(GetOpacity,"double vtkProperty::GetOpacity()  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#getopacity)")
    ADD_CLASS_METHOD(SetAmbientColor_1,"void vtkProperty::SetAmbientColor(double _arg1, double _arg2, double _arg3)  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#setambientcolor)")
    ADD_CLASS_METHOD(SetAmbientColor,"vtkProperty::SetAmbientColor()  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#setambientcolor)")
    ADD_CLASS_METHOD(SetAmbientColor_2,"void vtkProperty::SetAmbientColor(double * _arg)  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#setambientcolor)")
    ADD_CLASS_METHOD(GetAmbientColor_1,"double * vtkProperty::GetAmbientColor()  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#getambientcolor)")
    ADD_CLASS_METHOD(GetAmbientColor,"vtkProperty::GetAmbientColor()  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#getambientcolor)")
    ADD_CLASS_METHOD(GetAmbientColor_2,"void vtkProperty::GetAmbientColor(double & _arg1, double & _arg2, double & _arg3)  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#getambientcolor)")
    ADD_CLASS_METHOD(GetAmbientColor_3,"void vtkProperty::GetAmbientColor(double * _arg)  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#getambientcolor)")
    ADD_CLASS_METHOD(SetDiffuseColor_1,"void vtkProperty::SetDiffuseColor(double _arg1, double _arg2, double _arg3)  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#setdiffusecolor)")
    ADD_CLASS_METHOD(SetDiffuseColor,"vtkProperty::SetDiffuseColor()  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#setdiffusecolor)")
    ADD_CLASS_METHOD(SetDiffuseColor_2,"void vtkProperty::SetDiffuseColor(double * _arg)  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#setdiffusecolor)")
    ADD_CLASS_METHOD(GetDiffuseColor_1,"double * vtkProperty::GetDiffuseColor()  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#getdiffusecolor)")
    ADD_CLASS_METHOD(GetDiffuseColor,"vtkProperty::GetDiffuseColor()  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#getdiffusecolor)")
    ADD_CLASS_METHOD(GetDiffuseColor_2,"void vtkProperty::GetDiffuseColor(double & _arg1, double & _arg2, double & _arg3)  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#getdiffusecolor)")
    ADD_CLASS_METHOD(GetDiffuseColor_3,"void vtkProperty::GetDiffuseColor(double * _arg)  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#getdiffusecolor)")
    ADD_CLASS_METHOD(SetSpecularColor_1,"void vtkProperty::SetSpecularColor(double _arg1, double _arg2, double _arg3)  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#setspecularcolor)")
    ADD_CLASS_METHOD(SetSpecularColor,"vtkProperty::SetSpecularColor()  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#setspecularcolor)")
    ADD_CLASS_METHOD(SetSpecularColor_2,"void vtkProperty::SetSpecularColor(double * _arg)  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#setspecularcolor)")
    ADD_CLASS_METHOD(GetSpecularColor_1,"double * vtkProperty::GetSpecularColor()  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#getspecularcolor)")
    ADD_CLASS_METHOD(GetSpecularColor,"vtkProperty::GetSpecularColor()  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#getspecularcolor)")
    ADD_CLASS_METHOD(GetSpecularColor_2,"void vtkProperty::GetSpecularColor(double & _arg1, double & _arg2, double & _arg3)  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#getspecularcolor)")
    ADD_CLASS_METHOD(GetSpecularColor_3,"void vtkProperty::GetSpecularColor(double * _arg)  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#getspecularcolor)")
    ADD_CLASS_METHOD(GetEdgeVisibility,"int vtkProperty::GetEdgeVisibility()  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#getedgevisibility)")
    ADD_CLASS_METHOD(SetEdgeVisibility,"void vtkProperty::SetEdgeVisibility(int _arg)  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#setedgevisibility)")
    ADD_CLASS_METHOD(EdgeVisibilityOn,"void vtkProperty::EdgeVisibilityOn()  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#edgevisibilityon)")
    ADD_CLASS_METHOD(EdgeVisibilityOff,"void vtkProperty::EdgeVisibilityOff()  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#edgevisibilityoff)")
    ADD_CLASS_METHOD(SetEdgeColor_1,"void vtkProperty::SetEdgeColor(double _arg1, double _arg2, double _arg3)  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#setedgecolor)")
    ADD_CLASS_METHOD(SetEdgeColor,"vtkProperty::SetEdgeColor()  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#setedgecolor)")
    ADD_CLASS_METHOD(SetEdgeColor_2,"void vtkProperty::SetEdgeColor(double * _arg)  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#setedgecolor)")
    ADD_CLASS_METHOD(GetEdgeColor_1,"double * vtkProperty::GetEdgeColor()  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#getedgecolor)")
    ADD_CLASS_METHOD(GetEdgeColor,"vtkProperty::GetEdgeColor()  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#getedgecolor)")
    ADD_CLASS_METHOD(GetEdgeColor_2,"void vtkProperty::GetEdgeColor(double & _arg1, double & _arg2, double & _arg3)  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#getedgecolor)")
    ADD_CLASS_METHOD(GetEdgeColor_3,"void vtkProperty::GetEdgeColor(double * _arg)  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#getedgecolor)")
    ADD_CLASS_METHOD(SetLineWidth,"void vtkProperty::SetLineWidth(float _arg)  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#setlinewidth)")
    ADD_CLASS_METHOD(GetLineWidthMinValue,"float vtkProperty::GetLineWidthMinValue()  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#getlinewidthminvalue)")
    ADD_CLASS_METHOD(GetLineWidthMaxValue,"float vtkProperty::GetLineWidthMaxValue()  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#getlinewidthmaxvalue)")
    ADD_CLASS_METHOD(GetLineWidth,"float vtkProperty::GetLineWidth()  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#getlinewidth)")
    ADD_CLASS_METHOD(SetLineStipplePattern,"void vtkProperty::SetLineStipplePattern(int _arg)  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#setlinestipplepattern)")
    ADD_CLASS_METHOD(GetLineStipplePattern,"int vtkProperty::GetLineStipplePattern()  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#getlinestipplepattern)")
    ADD_CLASS_METHOD(SetLineStippleRepeatFactor,"void vtkProperty::SetLineStippleRepeatFactor(int _arg)  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#setlinestipplerepeatfactor)")
    ADD_CLASS_METHOD(GetLineStippleRepeatFactorMinValue,"int vtkProperty::GetLineStippleRepeatFactorMinValue()  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#getlinestipplerepeatfactorminvalue)")
    ADD_CLASS_METHOD(GetLineStippleRepeatFactorMaxValue,"int vtkProperty::GetLineStippleRepeatFactorMaxValue()  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#getlinestipplerepeatfactormaxvalue)")
    ADD_CLASS_METHOD(GetLineStippleRepeatFactor,"int vtkProperty::GetLineStippleRepeatFactor()  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#getlinestipplerepeatfactor)")
    ADD_CLASS_METHOD(SetPointSize,"void vtkProperty::SetPointSize(float _arg)  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#setpointsize)")
    ADD_CLASS_METHOD(GetPointSizeMinValue,"float vtkProperty::GetPointSizeMinValue()  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#getpointsizeminvalue)")
    ADD_CLASS_METHOD(GetPointSizeMaxValue,"float vtkProperty::GetPointSizeMaxValue()  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#getpointsizemaxvalue)")
    ADD_CLASS_METHOD(GetPointSize,"float vtkProperty::GetPointSize()  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#getpointsize)")
    ADD_CLASS_METHOD(GetBackfaceCulling,"int vtkProperty::GetBackfaceCulling()  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#getbackfaceculling)")
    ADD_CLASS_METHOD(SetBackfaceCulling,"void vtkProperty::SetBackfaceCulling(int _arg)  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#setbackfaceculling)")
    ADD_CLASS_METHOD(BackfaceCullingOn,"void vtkProperty::BackfaceCullingOn()  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#backfacecullingon)")
    ADD_CLASS_METHOD(BackfaceCullingOff,"void vtkProperty::BackfaceCullingOff()  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#backfacecullingoff)")
    ADD_CLASS_METHOD(GetFrontfaceCulling,"int vtkProperty::GetFrontfaceCulling()  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#getfrontfaceculling)")
    ADD_CLASS_METHOD(SetFrontfaceCulling,"void vtkProperty::SetFrontfaceCulling(int _arg)  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#setfrontfaceculling)")
    ADD_CLASS_METHOD(FrontfaceCullingOn,"void vtkProperty::FrontfaceCullingOn()  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#frontfacecullingon)")
    ADD_CLASS_METHOD(FrontfaceCullingOff,"void vtkProperty::FrontfaceCullingOff()  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#frontfacecullingoff)")
/* The following types are missing: vtkXMLMaterial
    ADD_CLASS_METHOD(GetMaterial,"vtkXMLMaterial * vtkProperty::GetMaterial()  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#getmaterial)")
*/
    ADD_CLASS_METHOD(GetMaterialName,"char * vtkProperty::GetMaterialName()  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#getmaterialname)")
    ADD_CLASS_METHOD(LoadMaterial_1,"void vtkProperty::LoadMaterial(char const * name)  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#loadmaterial)")
    ADD_CLASS_METHOD(LoadMaterialFromString,"void vtkProperty::LoadMaterialFromString(char const * materialxml)  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#loadmaterialfromstring)")
    ADD_CLASS_METHOD(LoadMaterial,"vtkProperty::LoadMaterial()  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#loadmaterial)")
/* The following types are missing: vtkXMLMaterial
    ADD_CLASS_METHOD(LoadMaterial_2,"void vtkProperty::LoadMaterial(vtkXMLMaterial * param0)  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#loadmaterial)")
*/
    ADD_CLASS_METHOD(SetShading,"void vtkProperty::SetShading(int _arg)  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#setshading)")
    ADD_CLASS_METHOD(GetShading,"int vtkProperty::GetShading()  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#getshading)")
    ADD_CLASS_METHOD(ShadingOn,"void vtkProperty::ShadingOn()  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#shadingon)")
    ADD_CLASS_METHOD(ShadingOff,"void vtkProperty::ShadingOff()  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#shadingoff)")
/* The following types are missing: vtkShaderProgram
    ADD_CLASS_METHOD(GetShaderProgram,"vtkShaderProgram * vtkProperty::GetShaderProgram()  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#getshaderprogram)")
*/
    ADD_CLASS_METHOD(AddShaderVariable_1,"void vtkProperty::AddShaderVariable(char const * name, int numVars, int * x)  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#addshadervariable)")
    ADD_CLASS_METHOD(AddShaderVariable,"vtkProperty::AddShaderVariable()  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#addshadervariable)")
    ADD_CLASS_METHOD(AddShaderVariable_2,"void vtkProperty::AddShaderVariable(char const * name, int numVars, float * x)  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#addshadervariable)")
    ADD_CLASS_METHOD(AddShaderVariable_3,"void vtkProperty::AddShaderVariable(char const * name, int numVars, double * x)  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#addshadervariable)")
    ADD_CLASS_METHOD(AddShaderVariable_4,"void vtkProperty::AddShaderVariable(char const * name, int v)  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#addshadervariable)")
    ADD_CLASS_METHOD(AddShaderVariable_5,"void vtkProperty::AddShaderVariable(char const * name, float v)  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#addshadervariable)")
    ADD_CLASS_METHOD(AddShaderVariable_6,"void vtkProperty::AddShaderVariable(char const * name, double v)  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#addshadervariable)")
    ADD_CLASS_METHOD(AddShaderVariable_7,"void vtkProperty::AddShaderVariable(char const * name, int v1, int v2)  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#addshadervariable)")
    ADD_CLASS_METHOD(AddShaderVariable_8,"void vtkProperty::AddShaderVariable(char const * name, float v1, float v2)  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#addshadervariable)")
    ADD_CLASS_METHOD(AddShaderVariable_9,"void vtkProperty::AddShaderVariable(char const * name, double v1, double v2)  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#addshadervariable)")
    ADD_CLASS_METHOD(AddShaderVariable_10,"void vtkProperty::AddShaderVariable(char const * name, int v1, int v2, int v3)  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#addshadervariable)")
    ADD_CLASS_METHOD(AddShaderVariable_11,"void vtkProperty::AddShaderVariable(char const * name, float v1, float v2, float v3)  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#addshadervariable)")
    ADD_CLASS_METHOD(AddShaderVariable_12,"void vtkProperty::AddShaderVariable(char const * name, double v1, double v2, double v3)  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#addshadervariable)")
/* The following types are missing: vtkTexture
    ADD_CLASS_METHOD(SetTexture_1,"void vtkProperty::SetTexture(char const * name, vtkTexture * texture)  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#settexture)")
*/
/* The following types are missing: vtkTexture
    ADD_CLASS_METHOD(GetTexture_1,"vtkTexture * vtkProperty::GetTexture(char const * name)  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#gettexture)")
*/
    ADD_CLASS_METHOD(SetTexture,"vtkProperty::SetTexture()  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#settexture)")
/* The following types are missing: vtkTexture
    ADD_CLASS_METHOD(SetTexture_2,"void vtkProperty::SetTexture(int unit, vtkTexture * texture)  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#settexture)")
*/
    ADD_CLASS_METHOD(GetTexture,"vtkProperty::GetTexture()  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#gettexture)")
/* The following types are missing: vtkTexture
    ADD_CLASS_METHOD(GetTexture_2,"vtkTexture * vtkProperty::GetTexture(int unit)  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#gettexture)")
*/
    ADD_CLASS_METHOD(RemoveTexture_1,"void vtkProperty::RemoveTexture(int unit)  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#removetexture)")
    ADD_CLASS_METHOD(RemoveTexture,"vtkProperty::RemoveTexture()  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#removetexture)")
    ADD_CLASS_METHOD(RemoveTexture_2,"void vtkProperty::RemoveTexture(char const * name)  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#removetexture)")
    ADD_CLASS_METHOD(RemoveAllTextures,"void vtkProperty::RemoveAllTextures()  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#removealltextures)")
    ADD_CLASS_METHOD(GetNumberOfTextures,"int vtkProperty::GetNumberOfTextures()  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#getnumberoftextures)")
    ADD_CLASS_METHOD(ReleaseGraphicsResources,"void vtkProperty::ReleaseGraphicsResources(vtkWindow * win)  (http://docs.wxwidgets.org/stable/wx_vtkproperty.html#releasegraphicsresources)")





    void AddMethods(WrapClass<vtkProperty>::ptr this_ptr );
    
    /*
     * Adds the constructor and the static methods to the given context
     */
    static void AddStaticMethods( Variables::ptr& context);

};


#endif // _wrap_vtkProperty_h
