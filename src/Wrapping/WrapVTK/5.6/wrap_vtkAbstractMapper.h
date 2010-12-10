/**
 * C++ Interface: wrap_vtkAbstractMapper
 *
 * Description: wrapping vtkAbstractMapper
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_vtkAbstractMapper_h_
#define _wrap_vtkAbstractMapper_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "vtkAbstractMapper.h"

// include what is needed for inheritence and for types ...

#include "wrap_vtkAlgorithm.h"



AMI_DECLARE_TYPE(vtkAbstractMapper);

// TODO: check for inheritence ...
class WrapClass_vtkAbstractMapper : public WrapClass<vtkAbstractMapper>
    , public   WrapClass_vtkAlgorithm
{
  DEFINE_CLASS(WrapClass_vtkAbstractMapper);

  protected:
    typedef WrapClass<vtkAbstractMapper>::ptr _parentclass_ptr;
    typedef vtkAbstractMapper ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<vtkAbstractMapper>& GetObj() const { return WrapClass<vtkAbstractMapper>::GetObj(); }

    /// Constructor
    WrapClass_vtkAbstractMapper(boost::shared_ptr<vtkAbstractMapper > si): 
    WrapClass<vtkAbstractMapper>(si)
    , WrapClass_vtkAlgorithm(si)
    {}

    /// Destructor
    ~WrapClass_vtkAbstractMapper()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( vtkAbstractMapper*);

    // Static methods
    
    ADD_CLASS_STATICMETHOD(IsTypeOf,"int vtkAbstractMapper::IsTypeOf(char const * type) (http://docs.wxwidgets.org/stable/wx_vtkabstractmapper.html#istypeof).");
    ADD_CLASS_STATICMETHOD(SafeDownCast,"vtkAbstractMapper * vtkAbstractMapper::SafeDownCast(vtkObjectBase * o) (http://docs.wxwidgets.org/stable/wx_vtkabstractmapper.html#safedowncast).");
    ADD_CLASS_STATICMETHOD(GetScalars,"vtkDataArray * vtkAbstractMapper::GetScalars(vtkDataSet * input, int scalarMode, int arrayAccessMode, int arrayId, char const * arrayName, int & cellFlag) (http://docs.wxwidgets.org/stable/wx_vtkabstractmapper.html#getscalars).");



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(IsA,"int vtkAbstractMapper::IsA(char const * type)  (http://docs.wxwidgets.org/stable/wx_vtkabstractmapper.html#isa)")
    ADD_CLASS_METHOD(NewInstance,"vtkAbstractMapper * vtkAbstractMapper::NewInstance()  (http://docs.wxwidgets.org/stable/wx_vtkabstractmapper.html#newinstance)")
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
    ADD_CLASS_METHOD(PrintSelf,"void vtkAbstractMapper::PrintSelf(ostream & os, vtkIndent indent)  (http://docs.wxwidgets.org/stable/wx_vtkabstractmapper.html#printself)")
*/
    ADD_CLASS_METHOD(GetMTime,"long unsigned int vtkAbstractMapper::GetMTime()  (http://docs.wxwidgets.org/stable/wx_vtkabstractmapper.html#getmtime)")
    ADD_CLASS_METHOD(ReleaseGraphicsResources,"void vtkAbstractMapper::ReleaseGraphicsResources(vtkWindow * param0)  (http://docs.wxwidgets.org/stable/wx_vtkabstractmapper.html#releasegraphicsresources)")
    ADD_CLASS_METHOD(GetTimeToDraw,"double vtkAbstractMapper::GetTimeToDraw()  (http://docs.wxwidgets.org/stable/wx_vtkabstractmapper.html#gettimetodraw)")
/* The following types are missing: vtkPlane
    ADD_CLASS_METHOD(AddClippingPlane,"void vtkAbstractMapper::AddClippingPlane(vtkPlane * plane)  (http://docs.wxwidgets.org/stable/wx_vtkabstractmapper.html#addclippingplane)")
*/
/* The following types are missing: vtkPlane
    ADD_CLASS_METHOD(RemoveClippingPlane,"void vtkAbstractMapper::RemoveClippingPlane(vtkPlane * plane)  (http://docs.wxwidgets.org/stable/wx_vtkabstractmapper.html#removeclippingplane)")
*/
    ADD_CLASS_METHOD(RemoveAllClippingPlanes,"void vtkAbstractMapper::RemoveAllClippingPlanes()  (http://docs.wxwidgets.org/stable/wx_vtkabstractmapper.html#removeallclippingplanes)")
/* The following types are missing: vtkPlaneCollection
    ADD_CLASS_METHOD(SetClippingPlanes_1,"void vtkAbstractMapper::SetClippingPlanes(vtkPlaneCollection * param0)  (http://docs.wxwidgets.org/stable/wx_vtkabstractmapper.html#setclippingplanes)")
*/
/* The following types are missing: vtkPlaneCollection
    ADD_CLASS_METHOD(GetClippingPlanes,"vtkPlaneCollection * vtkAbstractMapper::GetClippingPlanes()  (http://docs.wxwidgets.org/stable/wx_vtkabstractmapper.html#getclippingplanes)")
*/
    ADD_CLASS_METHOD(SetClippingPlanes,"vtkAbstractMapper::SetClippingPlanes()  (http://docs.wxwidgets.org/stable/wx_vtkabstractmapper.html#setclippingplanes)")
    ADD_CLASS_METHOD(SetClippingPlanes_2,"void vtkAbstractMapper::SetClippingPlanes(vtkPlanes * planes)  (http://docs.wxwidgets.org/stable/wx_vtkabstractmapper.html#setclippingplanes)")
    ADD_CLASS_METHOD(ShallowCopy,"void vtkAbstractMapper::ShallowCopy(vtkAbstractMapper * m)  (http://docs.wxwidgets.org/stable/wx_vtkabstractmapper.html#shallowcopy)")





    void AddMethods(WrapClass<vtkAbstractMapper>::ptr this_ptr );
    
    /*
     * Adds the constructor and the static methods to the given context
     */
    static void AddStaticMethods( Variables::ptr& context);

};


#endif // _wrap_vtkAbstractMapper_h
