/**
 * C++ Interface: wrap_vtkVolumeRayCastStaticInfo
 *
 * Description: wrapping vtkVolumeRayCastStaticInfo
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_vtkVolumeRayCastStaticInfo_h_
#define _wrap_vtkVolumeRayCastStaticInfo_h_

/*
#include "Variable.hpp"
#include "ami_object.h"
*/
#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "paramlist.h"

#include "vtkVolumeRayCastFunction.h"

// include what is needed for inheritence and for types ...



#ifndef vtkVolumeRayCastStaticInfo_declared
  #define vtkVolumeRayCastStaticInfo_declared
  AMI_DECLARE_TYPE(vtkVolumeRayCastStaticInfo);
#endif

// TODO: check for inheritence ...
class WrapClass_vtkVolumeRayCastStaticInfo : public WrapClass<vtkVolumeRayCastStaticInfo>
    
{
  DEFINE_CLASS(WrapClass_vtkVolumeRayCastStaticInfo);

  protected:
    typedef WrapClass<vtkVolumeRayCastStaticInfo>::ptr _parentclass_ptr;
    typedef vtkVolumeRayCastStaticInfo ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<vtkVolumeRayCastStaticInfo>& GetObj() const { return WrapClass<vtkVolumeRayCastStaticInfo>::GetObj(); }

    /// Constructor
    WrapClass_vtkVolumeRayCastStaticInfo(boost::shared_ptr<vtkVolumeRayCastStaticInfo > si): 
    WrapClass<vtkVolumeRayCastStaticInfo>(si)
    
    {}

    /// Destructor
    ~WrapClass_vtkVolumeRayCastStaticInfo()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(vtkVolumeRayCastStaticInfo_1,"Constructor vtkVolumeRayCastStaticInfo::._89(vtkVolumeRayCastStaticInfo const & param0) (http://docs.wxwidgets.org/stable/wx_vtkvolumeraycaststaticinfo.html#._89).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(vtkVolumeRayCastStaticInfo,"Constructor vtkVolumeRayCastStaticInfo::vtkVolumeRayCastStaticInfo() (http://docs.wxwidgets.org/stable/wx_vtkvolumeraycaststaticinfo.html#vtkvolumeraycaststaticinfo).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(vtkVolumeRayCastStaticInfo_2,"Constructor vtkVolumeRayCastStaticInfo::._89() (http://docs.wxwidgets.org/stable/wx_vtkvolumeraycaststaticinfo.html#._89).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( vtkVolumeRayCastStaticInfo*);

    // Static methods
    



    // Standard methods
    
    // Adding copy method
    ADD_CLASS_METHOD(__copy__,"Copy method, uses the copy constructor.");
    // Adding standard methods

    // Operators:
    ADD_CLASS_METHOD(__assign__,            "vtkVolumeRayCastStaticInfo & vtkVolumeRayCastStaticInfo::operator =(vtkVolumeRayCastStaticInfo const & param0) (http://docs.wxwidgets.org/stable/wx_vtkvolumeraycaststaticinfo.html#__assign__)")




    void AddMethods(WrapClass<vtkVolumeRayCastStaticInfo>::ptr this_ptr );
    

};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClassvtkVolumeRayCastStaticInfo_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_vtkVolumeRayCastStaticInfo_h
