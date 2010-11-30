/**
 * C++ Interface: wrap_vtkVolumeRayCastDynamicInfo
 *
 * Description: wrapping vtkVolumeRayCastDynamicInfo
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_vtkVolumeRayCastDynamicInfo_h_
#define _wrap_vtkVolumeRayCastDynamicInfo_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "vtk_includes.h"

// include what is needed for inheritence and for types ...




AMI_DECLARE_TYPE(vtkVolumeRayCastDynamicInfo);

// TODO: check for inheritence ...
class WrapClass_vtkVolumeRayCastDynamicInfo : public WrapClass<vtkVolumeRayCastDynamicInfo>
    
{
  DEFINE_CLASS(WrapClass_vtkVolumeRayCastDynamicInfo);

  protected:
    typedef WrapClass<vtkVolumeRayCastDynamicInfo>::ptr _parentclass_ptr;
    typedef vtkVolumeRayCastDynamicInfo ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<vtkVolumeRayCastDynamicInfo>& GetObj() const { return WrapClass<vtkVolumeRayCastDynamicInfo>::GetObj(); }

    /// Constructor
    WrapClass_vtkVolumeRayCastDynamicInfo(boost::shared_ptr<vtkVolumeRayCastDynamicInfo > si): 
    WrapClass<vtkVolumeRayCastDynamicInfo>(si)
    
    {}

    /// Destructor
    ~WrapClass_vtkVolumeRayCastDynamicInfo()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(vtkVolumeRayCastDynamicInfo_1,"Constructor vtkVolumeRayCastDynamicInfo::._88(vtkVolumeRayCastDynamicInfo const & param0) (http://docs.wxwidgets.org/stable/wx_vtkvolumeraycastdynamicinfo.html#._88).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(vtkVolumeRayCastDynamicInfo,"Constructor vtkVolumeRayCastDynamicInfo::vtkVolumeRayCastDynamicInfo() (http://docs.wxwidgets.org/stable/wx_vtkvolumeraycastdynamicinfo.html#vtkvolumeraycastdynamicinfo).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(vtkVolumeRayCastDynamicInfo_2,"Constructor vtkVolumeRayCastDynamicInfo::._88() (http://docs.wxwidgets.org/stable/wx_vtkvolumeraycastdynamicinfo.html#._88).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( vtkVolumeRayCastDynamicInfo*);

    // Static methods
    



    // Standard methods
    
    // Adding copy method
    ADD_CLASS_METHOD(__copy__,"Copy method, uses the copy constructor.");
    // Adding standard methods

    // Operators:
    ADD_CLASS_METHOD(__assign__,            "vtkVolumeRayCastDynamicInfo & vtkVolumeRayCastDynamicInfo::operator =(vtkVolumeRayCastDynamicInfo const & param0) (http://docs.wxwidgets.org/stable/wx_vtkvolumeraycastdynamicinfo.html#__assign__)")




    void AddMethods(WrapClass<vtkVolumeRayCastDynamicInfo>::ptr this_ptr );
    
    /*
     * Adds the constructor and the static methods to the given context
     */
    static void AddStaticMethods( Variables::ptr& context);

};


#endif // _wrap_vtkVolumeRayCastDynamicInfo_h
