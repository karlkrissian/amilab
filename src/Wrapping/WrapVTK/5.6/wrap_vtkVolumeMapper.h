/**
 * C++ Interface: wrap_vtkVolumeMapper
 *
 * Description: wrapping vtkVolumeMapper
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_vtkVolumeMapper_h_
#define _wrap_vtkVolumeMapper_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "vtk_includes.h"

// include what is needed for inheritence and for types ...

#include "wrap_vtkAbstractVolumeMapper.h"



AMI_DECLARE_TYPE(vtkVolumeMapper);

// TODO: check for inheritence ...
class WrapClass_vtkVolumeMapper : public WrapClass<vtkVolumeMapper>
    , public   WrapClass_vtkAbstractVolumeMapper
{
  DEFINE_CLASS(WrapClass_vtkVolumeMapper);

  protected:
    typedef WrapClass<vtkVolumeMapper>::ptr _parentclass_ptr;
    typedef vtkVolumeMapper ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<vtkVolumeMapper>& GetObj() const { return WrapClass<vtkVolumeMapper>::GetObj(); }

    /// Constructor
    WrapClass_vtkVolumeMapper(boost::shared_ptr<vtkVolumeMapper > si): 
    WrapClass<vtkVolumeMapper>(si)
    , WrapClass_vtkAbstractVolumeMapper(si)
    {}

    /// Destructor
    ~WrapClass_vtkVolumeMapper()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    


    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( vtkVolumeMapper*);

    // Static methods
    
    ADD_CLASS_STATICMETHOD(IsTypeOf,"int vtkVolumeMapper::IsTypeOf(char const * type) (http://docs.wxwidgets.org/stable/wx_vtkvolumemapper.html#istypeof).");
    ADD_CLASS_STATICMETHOD(SafeDownCast,"vtkVolumeMapper * vtkVolumeMapper::SafeDownCast(vtkObjectBase * o) (http://docs.wxwidgets.org/stable/wx_vtkvolumemapper.html#safedowncast).");



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(IsA,"int vtkVolumeMapper::IsA(char const * type)  (http://docs.wxwidgets.org/stable/wx_vtkvolumemapper.html#isa)")
    ADD_CLASS_METHOD(NewInstance,"vtkVolumeMapper * vtkVolumeMapper::NewInstance()  (http://docs.wxwidgets.org/stable/wx_vtkvolumemapper.html#newinstance)")
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
    ADD_CLASS_METHOD(PrintSelf,"void vtkVolumeMapper::PrintSelf(ostream & os, vtkIndent indent)  (http://docs.wxwidgets.org/stable/wx_vtkvolumemapper.html#printself)")
*/
    ADD_CLASS_METHOD(SetInput_1,"void vtkVolumeMapper::SetInput(vtkImageData * param0)  (http://docs.wxwidgets.org/stable/wx_vtkvolumemapper.html#setinput)")
    ADD_CLASS_METHOD(SetInput,"vtkVolumeMapper::SetInput()  (http://docs.wxwidgets.org/stable/wx_vtkvolumemapper.html#setinput)")
    ADD_CLASS_METHOD(SetInput_2,"void vtkVolumeMapper::SetInput(vtkDataSet * param0)  (http://docs.wxwidgets.org/stable/wx_vtkvolumemapper.html#setinput)")
    ADD_CLASS_METHOD(GetInput,"vtkImageData * vtkVolumeMapper::GetInput()  (http://docs.wxwidgets.org/stable/wx_vtkvolumemapper.html#getinput)")
    ADD_CLASS_METHOD(SetBlendMode,"void vtkVolumeMapper::SetBlendMode(int _arg)  (http://docs.wxwidgets.org/stable/wx_vtkvolumemapper.html#setblendmode)")
    ADD_CLASS_METHOD(SetBlendModeToComposite,"void vtkVolumeMapper::SetBlendModeToComposite()  (http://docs.wxwidgets.org/stable/wx_vtkvolumemapper.html#setblendmodetocomposite)")
    ADD_CLASS_METHOD(SetBlendModeToMaximumIntensity,"void vtkVolumeMapper::SetBlendModeToMaximumIntensity()  (http://docs.wxwidgets.org/stable/wx_vtkvolumemapper.html#setblendmodetomaximumintensity)")
    ADD_CLASS_METHOD(SetBlendModeToMinimumIntensity,"void vtkVolumeMapper::SetBlendModeToMinimumIntensity()  (http://docs.wxwidgets.org/stable/wx_vtkvolumemapper.html#setblendmodetominimumintensity)")
    ADD_CLASS_METHOD(GetBlendMode,"int vtkVolumeMapper::GetBlendMode()  (http://docs.wxwidgets.org/stable/wx_vtkvolumemapper.html#getblendmode)")
    ADD_CLASS_METHOD(SetCropping,"void vtkVolumeMapper::SetCropping(int _arg)  (http://docs.wxwidgets.org/stable/wx_vtkvolumemapper.html#setcropping)")
    ADD_CLASS_METHOD(GetCroppingMinValue,"int vtkVolumeMapper::GetCroppingMinValue()  (http://docs.wxwidgets.org/stable/wx_vtkvolumemapper.html#getcroppingminvalue)")
    ADD_CLASS_METHOD(GetCroppingMaxValue,"int vtkVolumeMapper::GetCroppingMaxValue()  (http://docs.wxwidgets.org/stable/wx_vtkvolumemapper.html#getcroppingmaxvalue)")
    ADD_CLASS_METHOD(GetCropping,"int vtkVolumeMapper::GetCropping()  (http://docs.wxwidgets.org/stable/wx_vtkvolumemapper.html#getcropping)")
    ADD_CLASS_METHOD(CroppingOn,"void vtkVolumeMapper::CroppingOn()  (http://docs.wxwidgets.org/stable/wx_vtkvolumemapper.html#croppingon)")
    ADD_CLASS_METHOD(CroppingOff,"void vtkVolumeMapper::CroppingOff()  (http://docs.wxwidgets.org/stable/wx_vtkvolumemapper.html#croppingoff)")
    ADD_CLASS_METHOD(SetCroppingRegionPlanes_1,"void vtkVolumeMapper::SetCroppingRegionPlanes(double _arg1, double _arg2, double _arg3, double _arg4, double _arg5, double _arg6)  (http://docs.wxwidgets.org/stable/wx_vtkvolumemapper.html#setcroppingregionplanes)")
    ADD_CLASS_METHOD(SetCroppingRegionPlanes,"vtkVolumeMapper::SetCroppingRegionPlanes()  (http://docs.wxwidgets.org/stable/wx_vtkvolumemapper.html#setcroppingregionplanes)")
    ADD_CLASS_METHOD(SetCroppingRegionPlanes_2,"void vtkVolumeMapper::SetCroppingRegionPlanes(double * _arg)  (http://docs.wxwidgets.org/stable/wx_vtkvolumemapper.html#setcroppingregionplanes)")
    ADD_CLASS_METHOD(GetCroppingRegionPlanes_1,"double * vtkVolumeMapper::GetCroppingRegionPlanes()  (http://docs.wxwidgets.org/stable/wx_vtkvolumemapper.html#getcroppingregionplanes)")
    ADD_CLASS_METHOD(GetCroppingRegionPlanes,"vtkVolumeMapper::GetCroppingRegionPlanes()  (http://docs.wxwidgets.org/stable/wx_vtkvolumemapper.html#getcroppingregionplanes)")
    ADD_CLASS_METHOD(GetCroppingRegionPlanes_2,"void vtkVolumeMapper::GetCroppingRegionPlanes(double * data)  (http://docs.wxwidgets.org/stable/wx_vtkvolumemapper.html#getcroppingregionplanes)")
    ADD_CLASS_METHOD(GetVoxelCroppingRegionPlanes_1,"double * vtkVolumeMapper::GetVoxelCroppingRegionPlanes()  (http://docs.wxwidgets.org/stable/wx_vtkvolumemapper.html#getvoxelcroppingregionplanes)")
    ADD_CLASS_METHOD(GetVoxelCroppingRegionPlanes,"vtkVolumeMapper::GetVoxelCroppingRegionPlanes()  (http://docs.wxwidgets.org/stable/wx_vtkvolumemapper.html#getvoxelcroppingregionplanes)")
    ADD_CLASS_METHOD(GetVoxelCroppingRegionPlanes_2,"void vtkVolumeMapper::GetVoxelCroppingRegionPlanes(double * data)  (http://docs.wxwidgets.org/stable/wx_vtkvolumemapper.html#getvoxelcroppingregionplanes)")
    ADD_CLASS_METHOD(SetCroppingRegionFlags,"void vtkVolumeMapper::SetCroppingRegionFlags(int _arg)  (http://docs.wxwidgets.org/stable/wx_vtkvolumemapper.html#setcroppingregionflags)")
    ADD_CLASS_METHOD(GetCroppingRegionFlagsMinValue,"int vtkVolumeMapper::GetCroppingRegionFlagsMinValue()  (http://docs.wxwidgets.org/stable/wx_vtkvolumemapper.html#getcroppingregionflagsminvalue)")
    ADD_CLASS_METHOD(GetCroppingRegionFlagsMaxValue,"int vtkVolumeMapper::GetCroppingRegionFlagsMaxValue()  (http://docs.wxwidgets.org/stable/wx_vtkvolumemapper.html#getcroppingregionflagsmaxvalue)")
    ADD_CLASS_METHOD(GetCroppingRegionFlags,"int vtkVolumeMapper::GetCroppingRegionFlags()  (http://docs.wxwidgets.org/stable/wx_vtkvolumemapper.html#getcroppingregionflags)")
    ADD_CLASS_METHOD(SetCroppingRegionFlagsToSubVolume,"void vtkVolumeMapper::SetCroppingRegionFlagsToSubVolume()  (http://docs.wxwidgets.org/stable/wx_vtkvolumemapper.html#setcroppingregionflagstosubvolume)")
    ADD_CLASS_METHOD(SetCroppingRegionFlagsToFence,"void vtkVolumeMapper::SetCroppingRegionFlagsToFence()  (http://docs.wxwidgets.org/stable/wx_vtkvolumemapper.html#setcroppingregionflagstofence)")
    ADD_CLASS_METHOD(SetCroppingRegionFlagsToInvertedFence,"void vtkVolumeMapper::SetCroppingRegionFlagsToInvertedFence()  (http://docs.wxwidgets.org/stable/wx_vtkvolumemapper.html#setcroppingregionflagstoinvertedfence)")
    ADD_CLASS_METHOD(SetCroppingRegionFlagsToCross,"void vtkVolumeMapper::SetCroppingRegionFlagsToCross()  (http://docs.wxwidgets.org/stable/wx_vtkvolumemapper.html#setcroppingregionflagstocross)")
    ADD_CLASS_METHOD(SetCroppingRegionFlagsToInvertedCross,"void vtkVolumeMapper::SetCroppingRegionFlagsToInvertedCross()  (http://docs.wxwidgets.org/stable/wx_vtkvolumemapper.html#setcroppingregionflagstoinvertedcross)")
    ADD_CLASS_METHOD(ReleaseGraphicsResources,"void vtkVolumeMapper::ReleaseGraphicsResources(vtkWindow * param0)  (http://docs.wxwidgets.org/stable/wx_vtkvolumemapper.html#releasegraphicsresources)")





    void AddMethods(WrapClass<vtkVolumeMapper>::ptr this_ptr );

};


#endif // _wrap_vtkVolumeMapper_h
