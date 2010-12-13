/**
 * C++ Interface: wrap_vtkPolyDataNormals
 *
 * Description: wrapping vtkPolyDataNormals
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_vtkPolyDataNormals_h_
#define _wrap_vtkPolyDataNormals_h_

/*
#include "Variable.hpp"
#include "ami_object.h"
*/
#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "paramlist.h"

#include "vtkPolyDataNormals.h"

// include what is needed for inheritence and for types ...

#include "wrap_vtkPolyDataAlgorithm.h"


#ifndef vtkPolyDataNormals_declared
  #define vtkPolyDataNormals_declared
  AMI_DECLARE_TYPE(vtkPolyDataNormals);
#endif

// TODO: check for inheritence ...
class WrapClass_vtkPolyDataNormals : public WrapClass<vtkPolyDataNormals>
    , public   WrapClass_vtkPolyDataAlgorithm
{
  DEFINE_CLASS(WrapClass_vtkPolyDataNormals);

  protected:
    typedef WrapClass<vtkPolyDataNormals>::ptr _parentclass_ptr;
    typedef vtkPolyDataNormals ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<vtkPolyDataNormals>& GetObj() const { return WrapClass<vtkPolyDataNormals>::GetObj(); }

    /// Constructor
    WrapClass_vtkPolyDataNormals(boost::shared_ptr<vtkPolyDataNormals > si): 
    WrapClass<vtkPolyDataNormals>(si)
    , WrapClass_vtkPolyDataAlgorithm(si)
    {}

    /// Destructor
    ~WrapClass_vtkPolyDataNormals()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( vtkPolyDataNormals*);

    // Static methods
    
    ADD_CLASS_STATICMETHOD(IsTypeOf,"int vtkPolyDataNormals::IsTypeOf(char const * type) (http://docs.wxwidgets.org/stable/wx_vtkpolydatanormals.html#istypeof).");
    ADD_CLASS_STATICMETHOD(SafeDownCast,"vtkPolyDataNormals * vtkPolyDataNormals::SafeDownCast(vtkObjectBase * o) (http://docs.wxwidgets.org/stable/wx_vtkpolydatanormals.html#safedowncast).");
    ADD_CLASS_STATICMETHOD(New,"vtkPolyDataNormals * vtkPolyDataNormals::New() (http://docs.wxwidgets.org/stable/wx_vtkpolydatanormals.html#new).");



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(IsA,"int vtkPolyDataNormals::IsA(char const * type)  (http://docs.wxwidgets.org/stable/wx_vtkpolydatanormals.html#isa)")
    ADD_CLASS_METHOD(NewInstance,"vtkPolyDataNormals * vtkPolyDataNormals::NewInstance()  (http://docs.wxwidgets.org/stable/wx_vtkpolydatanormals.html#newinstance)")
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
    ADD_CLASS_METHOD(PrintSelf,"void vtkPolyDataNormals::PrintSelf(ostream & os, vtkIndent indent)  (http://docs.wxwidgets.org/stable/wx_vtkpolydatanormals.html#printself)")
*/
    ADD_CLASS_METHOD(SetFeatureAngle,"void vtkPolyDataNormals::SetFeatureAngle(double _arg)  (http://docs.wxwidgets.org/stable/wx_vtkpolydatanormals.html#setfeatureangle)")
    ADD_CLASS_METHOD(GetFeatureAngleMinValue,"double vtkPolyDataNormals::GetFeatureAngleMinValue()  (http://docs.wxwidgets.org/stable/wx_vtkpolydatanormals.html#getfeatureangleminvalue)")
    ADD_CLASS_METHOD(GetFeatureAngleMaxValue,"double vtkPolyDataNormals::GetFeatureAngleMaxValue()  (http://docs.wxwidgets.org/stable/wx_vtkpolydatanormals.html#getfeatureanglemaxvalue)")
    ADD_CLASS_METHOD(GetFeatureAngle,"double vtkPolyDataNormals::GetFeatureAngle()  (http://docs.wxwidgets.org/stable/wx_vtkpolydatanormals.html#getfeatureangle)")
    ADD_CLASS_METHOD(SetSplitting,"void vtkPolyDataNormals::SetSplitting(int _arg)  (http://docs.wxwidgets.org/stable/wx_vtkpolydatanormals.html#setsplitting)")
    ADD_CLASS_METHOD(GetSplitting,"int vtkPolyDataNormals::GetSplitting()  (http://docs.wxwidgets.org/stable/wx_vtkpolydatanormals.html#getsplitting)")
    ADD_CLASS_METHOD(SplittingOn,"void vtkPolyDataNormals::SplittingOn()  (http://docs.wxwidgets.org/stable/wx_vtkpolydatanormals.html#splittingon)")
    ADD_CLASS_METHOD(SplittingOff,"void vtkPolyDataNormals::SplittingOff()  (http://docs.wxwidgets.org/stable/wx_vtkpolydatanormals.html#splittingoff)")
    ADD_CLASS_METHOD(SetConsistency,"void vtkPolyDataNormals::SetConsistency(int _arg)  (http://docs.wxwidgets.org/stable/wx_vtkpolydatanormals.html#setconsistency)")
    ADD_CLASS_METHOD(GetConsistency,"int vtkPolyDataNormals::GetConsistency()  (http://docs.wxwidgets.org/stable/wx_vtkpolydatanormals.html#getconsistency)")
    ADD_CLASS_METHOD(ConsistencyOn,"void vtkPolyDataNormals::ConsistencyOn()  (http://docs.wxwidgets.org/stable/wx_vtkpolydatanormals.html#consistencyon)")
    ADD_CLASS_METHOD(ConsistencyOff,"void vtkPolyDataNormals::ConsistencyOff()  (http://docs.wxwidgets.org/stable/wx_vtkpolydatanormals.html#consistencyoff)")
    ADD_CLASS_METHOD(SetAutoOrientNormals,"void vtkPolyDataNormals::SetAutoOrientNormals(int _arg)  (http://docs.wxwidgets.org/stable/wx_vtkpolydatanormals.html#setautoorientnormals)")
    ADD_CLASS_METHOD(GetAutoOrientNormals,"int vtkPolyDataNormals::GetAutoOrientNormals()  (http://docs.wxwidgets.org/stable/wx_vtkpolydatanormals.html#getautoorientnormals)")
    ADD_CLASS_METHOD(AutoOrientNormalsOn,"void vtkPolyDataNormals::AutoOrientNormalsOn()  (http://docs.wxwidgets.org/stable/wx_vtkpolydatanormals.html#autoorientnormalson)")
    ADD_CLASS_METHOD(AutoOrientNormalsOff,"void vtkPolyDataNormals::AutoOrientNormalsOff()  (http://docs.wxwidgets.org/stable/wx_vtkpolydatanormals.html#autoorientnormalsoff)")
    ADD_CLASS_METHOD(SetComputePointNormals,"void vtkPolyDataNormals::SetComputePointNormals(int _arg)  (http://docs.wxwidgets.org/stable/wx_vtkpolydatanormals.html#setcomputepointnormals)")
    ADD_CLASS_METHOD(GetComputePointNormals,"int vtkPolyDataNormals::GetComputePointNormals()  (http://docs.wxwidgets.org/stable/wx_vtkpolydatanormals.html#getcomputepointnormals)")
    ADD_CLASS_METHOD(ComputePointNormalsOn,"void vtkPolyDataNormals::ComputePointNormalsOn()  (http://docs.wxwidgets.org/stable/wx_vtkpolydatanormals.html#computepointnormalson)")
    ADD_CLASS_METHOD(ComputePointNormalsOff,"void vtkPolyDataNormals::ComputePointNormalsOff()  (http://docs.wxwidgets.org/stable/wx_vtkpolydatanormals.html#computepointnormalsoff)")
    ADD_CLASS_METHOD(SetComputeCellNormals,"void vtkPolyDataNormals::SetComputeCellNormals(int _arg)  (http://docs.wxwidgets.org/stable/wx_vtkpolydatanormals.html#setcomputecellnormals)")
    ADD_CLASS_METHOD(GetComputeCellNormals,"int vtkPolyDataNormals::GetComputeCellNormals()  (http://docs.wxwidgets.org/stable/wx_vtkpolydatanormals.html#getcomputecellnormals)")
    ADD_CLASS_METHOD(ComputeCellNormalsOn,"void vtkPolyDataNormals::ComputeCellNormalsOn()  (http://docs.wxwidgets.org/stable/wx_vtkpolydatanormals.html#computecellnormalson)")
    ADD_CLASS_METHOD(ComputeCellNormalsOff,"void vtkPolyDataNormals::ComputeCellNormalsOff()  (http://docs.wxwidgets.org/stable/wx_vtkpolydatanormals.html#computecellnormalsoff)")
    ADD_CLASS_METHOD(SetFlipNormals,"void vtkPolyDataNormals::SetFlipNormals(int _arg)  (http://docs.wxwidgets.org/stable/wx_vtkpolydatanormals.html#setflipnormals)")
    ADD_CLASS_METHOD(GetFlipNormals,"int vtkPolyDataNormals::GetFlipNormals()  (http://docs.wxwidgets.org/stable/wx_vtkpolydatanormals.html#getflipnormals)")
    ADD_CLASS_METHOD(FlipNormalsOn,"void vtkPolyDataNormals::FlipNormalsOn()  (http://docs.wxwidgets.org/stable/wx_vtkpolydatanormals.html#flipnormalson)")
    ADD_CLASS_METHOD(FlipNormalsOff,"void vtkPolyDataNormals::FlipNormalsOff()  (http://docs.wxwidgets.org/stable/wx_vtkpolydatanormals.html#flipnormalsoff)")
    ADD_CLASS_METHOD(SetNonManifoldTraversal,"void vtkPolyDataNormals::SetNonManifoldTraversal(int _arg)  (http://docs.wxwidgets.org/stable/wx_vtkpolydatanormals.html#setnonmanifoldtraversal)")
    ADD_CLASS_METHOD(GetNonManifoldTraversal,"int vtkPolyDataNormals::GetNonManifoldTraversal()  (http://docs.wxwidgets.org/stable/wx_vtkpolydatanormals.html#getnonmanifoldtraversal)")
    ADD_CLASS_METHOD(NonManifoldTraversalOn,"void vtkPolyDataNormals::NonManifoldTraversalOn()  (http://docs.wxwidgets.org/stable/wx_vtkpolydatanormals.html#nonmanifoldtraversalon)")
    ADD_CLASS_METHOD(NonManifoldTraversalOff,"void vtkPolyDataNormals::NonManifoldTraversalOff()  (http://docs.wxwidgets.org/stable/wx_vtkpolydatanormals.html#nonmanifoldtraversaloff)")





    void AddMethods(WrapClass<vtkPolyDataNormals>::ptr this_ptr );
    

};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClassvtkPolyDataNormals_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_vtkPolyDataNormals_h
