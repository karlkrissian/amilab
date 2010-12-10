/**
 * C++ Interface: wrap_vtkAbstractVolumeMapper
 *
 * Description: wrapping vtkAbstractVolumeMapper
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_vtkAbstractVolumeMapper_h_
#define _wrap_vtkAbstractVolumeMapper_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "vtkAbstractVolumeMapper.h"

// include what is needed for inheritence and for types ...

#include "wrap_vtkAbstractMapper3D.h"



AMI_DECLARE_TYPE(vtkAbstractVolumeMapper);

// TODO: check for inheritence ...
class WrapClass_vtkAbstractVolumeMapper : public WrapClass<vtkAbstractVolumeMapper>
    , public   WrapClass_vtkAbstractMapper3D
{
  DEFINE_CLASS(WrapClass_vtkAbstractVolumeMapper);

  protected:
    typedef WrapClass<vtkAbstractVolumeMapper>::ptr _parentclass_ptr;
    typedef vtkAbstractVolumeMapper ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<vtkAbstractVolumeMapper>& GetObj() const { return WrapClass<vtkAbstractVolumeMapper>::GetObj(); }

    /// Constructor
    WrapClass_vtkAbstractVolumeMapper(boost::shared_ptr<vtkAbstractVolumeMapper > si): 
    WrapClass<vtkAbstractVolumeMapper>(si)
    , WrapClass_vtkAbstractMapper3D(si)
    {}

    /// Destructor
    ~WrapClass_vtkAbstractVolumeMapper()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    


    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( vtkAbstractVolumeMapper*);

    // Static methods
    
    ADD_CLASS_STATICMETHOD(IsTypeOf,"int vtkAbstractVolumeMapper::IsTypeOf(char const * type) (http://docs.wxwidgets.org/stable/wx_vtkabstractvolumemapper.html#istypeof).");
    ADD_CLASS_STATICMETHOD(SafeDownCast,"vtkAbstractVolumeMapper * vtkAbstractVolumeMapper::SafeDownCast(vtkObjectBase * o) (http://docs.wxwidgets.org/stable/wx_vtkabstractvolumemapper.html#safedowncast).");



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(IsA,"int vtkAbstractVolumeMapper::IsA(char const * type)  (http://docs.wxwidgets.org/stable/wx_vtkabstractvolumemapper.html#isa)")
    ADD_CLASS_METHOD(NewInstance,"vtkAbstractVolumeMapper * vtkAbstractVolumeMapper::NewInstance()  (http://docs.wxwidgets.org/stable/wx_vtkabstractvolumemapper.html#newinstance)")
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
    ADD_CLASS_METHOD(PrintSelf,"void vtkAbstractVolumeMapper::PrintSelf(ostream & os, vtkIndent indent)  (http://docs.wxwidgets.org/stable/wx_vtkabstractvolumemapper.html#printself)")
*/
    ADD_CLASS_METHOD(SetInput,"void vtkAbstractVolumeMapper::SetInput(vtkDataSet * param0)  (http://docs.wxwidgets.org/stable/wx_vtkabstractvolumemapper.html#setinput)")
    ADD_CLASS_METHOD(GetDataSetInput,"vtkDataSet * vtkAbstractVolumeMapper::GetDataSetInput()  (http://docs.wxwidgets.org/stable/wx_vtkabstractvolumemapper.html#getdatasetinput)")
    ADD_CLASS_METHOD(GetDataObjectInput,"vtkDataObject * vtkAbstractVolumeMapper::GetDataObjectInput()  (http://docs.wxwidgets.org/stable/wx_vtkabstractvolumemapper.html#getdataobjectinput)")
    ADD_CLASS_METHOD(GetBounds_1,"double * vtkAbstractVolumeMapper::GetBounds()  (http://docs.wxwidgets.org/stable/wx_vtkabstractvolumemapper.html#getbounds)")
    ADD_CLASS_METHOD(GetBounds,"vtkAbstractVolumeMapper::GetBounds()  (http://docs.wxwidgets.org/stable/wx_vtkabstractvolumemapper.html#getbounds)")
    ADD_CLASS_METHOD(GetBounds_2,"void vtkAbstractVolumeMapper::GetBounds(double * bounds)  (http://docs.wxwidgets.org/stable/wx_vtkabstractvolumemapper.html#getbounds)")
    ADD_CLASS_METHOD(SetScalarMode,"void vtkAbstractVolumeMapper::SetScalarMode(int _arg)  (http://docs.wxwidgets.org/stable/wx_vtkabstractvolumemapper.html#setscalarmode)")
    ADD_CLASS_METHOD(GetScalarMode,"int vtkAbstractVolumeMapper::GetScalarMode()  (http://docs.wxwidgets.org/stable/wx_vtkabstractvolumemapper.html#getscalarmode)")
    ADD_CLASS_METHOD(SetScalarModeToDefault,"void vtkAbstractVolumeMapper::SetScalarModeToDefault()  (http://docs.wxwidgets.org/stable/wx_vtkabstractvolumemapper.html#setscalarmodetodefault)")
    ADD_CLASS_METHOD(SetScalarModeToUsePointData,"void vtkAbstractVolumeMapper::SetScalarModeToUsePointData()  (http://docs.wxwidgets.org/stable/wx_vtkabstractvolumemapper.html#setscalarmodetousepointdata)")
    ADD_CLASS_METHOD(SetScalarModeToUseCellData,"void vtkAbstractVolumeMapper::SetScalarModeToUseCellData()  (http://docs.wxwidgets.org/stable/wx_vtkabstractvolumemapper.html#setscalarmodetousecelldata)")
    ADD_CLASS_METHOD(SetScalarModeToUsePointFieldData,"void vtkAbstractVolumeMapper::SetScalarModeToUsePointFieldData()  (http://docs.wxwidgets.org/stable/wx_vtkabstractvolumemapper.html#setscalarmodetousepointfielddata)")
    ADD_CLASS_METHOD(SetScalarModeToUseCellFieldData,"void vtkAbstractVolumeMapper::SetScalarModeToUseCellFieldData()  (http://docs.wxwidgets.org/stable/wx_vtkabstractvolumemapper.html#setscalarmodetousecellfielddata)")
    ADD_CLASS_METHOD(SelectScalarArray_1,"void vtkAbstractVolumeMapper::SelectScalarArray(int arrayNum)  (http://docs.wxwidgets.org/stable/wx_vtkabstractvolumemapper.html#selectscalararray)")
    ADD_CLASS_METHOD(SelectScalarArray,"vtkAbstractVolumeMapper::SelectScalarArray()  (http://docs.wxwidgets.org/stable/wx_vtkabstractvolumemapper.html#selectscalararray)")
    ADD_CLASS_METHOD(SelectScalarArray_2,"void vtkAbstractVolumeMapper::SelectScalarArray(char const * arrayName)  (http://docs.wxwidgets.org/stable/wx_vtkabstractvolumemapper.html#selectscalararray)")
    ADD_CLASS_METHOD(GetArrayName,"char * vtkAbstractVolumeMapper::GetArrayName()  (http://docs.wxwidgets.org/stable/wx_vtkabstractvolumemapper.html#getarrayname)")
    ADD_CLASS_METHOD(GetArrayId,"int vtkAbstractVolumeMapper::GetArrayId()  (http://docs.wxwidgets.org/stable/wx_vtkabstractvolumemapper.html#getarrayid)")
    ADD_CLASS_METHOD(GetArrayAccessMode,"int vtkAbstractVolumeMapper::GetArrayAccessMode()  (http://docs.wxwidgets.org/stable/wx_vtkabstractvolumemapper.html#getarrayaccessmode)")
    ADD_CLASS_METHOD(GetScalarModeAsString,"char const * vtkAbstractVolumeMapper::GetScalarModeAsString()  (http://docs.wxwidgets.org/stable/wx_vtkabstractvolumemapper.html#getscalarmodeasstring)")
    ADD_CLASS_METHOD(GetGradientMagnitudeScale_1,"float vtkAbstractVolumeMapper::GetGradientMagnitudeScale()  (http://docs.wxwidgets.org/stable/wx_vtkabstractvolumemapper.html#getgradientmagnitudescale)")
    ADD_CLASS_METHOD(GetGradientMagnitudeBias_1,"float vtkAbstractVolumeMapper::GetGradientMagnitudeBias()  (http://docs.wxwidgets.org/stable/wx_vtkabstractvolumemapper.html#getgradientmagnitudebias)")
    ADD_CLASS_METHOD(GetGradientMagnitudeScale,"vtkAbstractVolumeMapper::GetGradientMagnitudeScale()  (http://docs.wxwidgets.org/stable/wx_vtkabstractvolumemapper.html#getgradientmagnitudescale)")
    ADD_CLASS_METHOD(GetGradientMagnitudeScale_2,"float vtkAbstractVolumeMapper::GetGradientMagnitudeScale(int param0)  (http://docs.wxwidgets.org/stable/wx_vtkabstractvolumemapper.html#getgradientmagnitudescale)")
    ADD_CLASS_METHOD(GetGradientMagnitudeBias,"vtkAbstractVolumeMapper::GetGradientMagnitudeBias()  (http://docs.wxwidgets.org/stable/wx_vtkabstractvolumemapper.html#getgradientmagnitudebias)")
    ADD_CLASS_METHOD(GetGradientMagnitudeBias_2,"float vtkAbstractVolumeMapper::GetGradientMagnitudeBias(int param0)  (http://docs.wxwidgets.org/stable/wx_vtkabstractvolumemapper.html#getgradientmagnitudebias)")
    ADD_CLASS_METHOD(ReleaseGraphicsResources,"void vtkAbstractVolumeMapper::ReleaseGraphicsResources(vtkWindow * param0)  (http://docs.wxwidgets.org/stable/wx_vtkabstractvolumemapper.html#releasegraphicsresources)")





    void AddMethods(WrapClass<vtkAbstractVolumeMapper>::ptr this_ptr );
    
    /*
     * Adds the constructor and the static methods to the given context
     */
    static void AddStaticMethods( Variables::ptr& context);

};


#endif // _wrap_vtkAbstractVolumeMapper_h
