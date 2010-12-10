/**
 * C++ Interface: wrap_vtkPointSet
 *
 * Description: wrapping vtkPointSet
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_vtkPointSet_h_
#define _wrap_vtkPointSet_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "vtkPointSet.h"

// include what is needed for inheritence and for types ...

#include "wrap_vtkDataSet.h"



AMI_DECLARE_TYPE(vtkPointSet);

// TODO: check for inheritence ...
class WrapClass_vtkPointSet : public WrapClass<vtkPointSet>
    , public   WrapClass_vtkDataSet
{
  DEFINE_CLASS(WrapClass_vtkPointSet);

  protected:
    typedef WrapClass<vtkPointSet>::ptr _parentclass_ptr;
    typedef vtkPointSet ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<vtkPointSet>& GetObj() const { return WrapClass<vtkPointSet>::GetObj(); }

    /// Constructor
    WrapClass_vtkPointSet(boost::shared_ptr<vtkPointSet > si): 
    WrapClass<vtkPointSet>(si)
    , WrapClass_vtkDataSet(si)
    {}

    /// Destructor
    ~WrapClass_vtkPointSet()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    


    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( vtkPointSet*);

    // Static methods
    
    ADD_CLASS_STATICMETHOD(IsTypeOf,"int vtkPointSet::IsTypeOf(char const * type) (http://docs.wxwidgets.org/stable/wx_vtkpointset.html#istypeof).");
    ADD_CLASS_STATICMETHOD(SafeDownCast,"vtkPointSet * vtkPointSet::SafeDownCast(vtkObjectBase * o) (http://docs.wxwidgets.org/stable/wx_vtkpointset.html#safedowncast).");
    /* The following types are missing: vtkInformation
    ADD_CLASS_STATICMETHOD(GetData_1,"vtkPointSet * vtkPointSet::GetData(vtkInformation * info) (http://docs.wxwidgets.org/stable/wx_vtkpointset.html#getdata).");
    */
    ADD_CLASS_STATICMETHOD(GetData,"vtkPointSet::GetData() (http://docs.wxwidgets.org/stable/wx_vtkpointset.html#getdata).");
    /* The following types are missing: vtkInformationVector
    ADD_CLASS_STATICMETHOD(GetData_2,"vtkPointSet * vtkPointSet::GetData(vtkInformationVector * v, int i = 0) (http://docs.wxwidgets.org/stable/wx_vtkpointset.html#getdata).");
    */



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(IsA,"int vtkPointSet::IsA(char const * type)  (http://docs.wxwidgets.org/stable/wx_vtkpointset.html#isa)")
    ADD_CLASS_METHOD(NewInstance,"vtkPointSet * vtkPointSet::NewInstance()  (http://docs.wxwidgets.org/stable/wx_vtkpointset.html#newinstance)")
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
    ADD_CLASS_METHOD(PrintSelf,"void vtkPointSet::PrintSelf(ostream & os, vtkIndent indent)  (http://docs.wxwidgets.org/stable/wx_vtkpointset.html#printself)")
*/
    ADD_CLASS_METHOD(Initialize,"void vtkPointSet::Initialize()  (http://docs.wxwidgets.org/stable/wx_vtkpointset.html#initialize)")
    ADD_CLASS_METHOD(CopyStructure,"void vtkPointSet::CopyStructure(vtkDataSet * pd)  (http://docs.wxwidgets.org/stable/wx_vtkpointset.html#copystructure)")
    ADD_CLASS_METHOD(GetNumberOfPoints,"vtkIdType vtkPointSet::GetNumberOfPoints()  (http://docs.wxwidgets.org/stable/wx_vtkpointset.html#getnumberofpoints)")
    ADD_CLASS_METHOD(GetPoint_1,"double * vtkPointSet::GetPoint(vtkIdType ptId)  (http://docs.wxwidgets.org/stable/wx_vtkpointset.html#getpoint)")
    ADD_CLASS_METHOD(GetPoint,"vtkPointSet::GetPoint()  (http://docs.wxwidgets.org/stable/wx_vtkpointset.html#getpoint)")
    ADD_CLASS_METHOD(GetPoint_2,"void vtkPointSet::GetPoint(vtkIdType ptId, double * x)  (http://docs.wxwidgets.org/stable/wx_vtkpointset.html#getpoint)")
    ADD_CLASS_METHOD(FindPoint_1,"vtkIdType vtkPointSet::FindPoint(double * x)  (http://docs.wxwidgets.org/stable/wx_vtkpointset.html#findpoint)")
    ADD_CLASS_METHOD(FindPoint,"vtkPointSet::FindPoint()  (http://docs.wxwidgets.org/stable/wx_vtkpointset.html#findpoint)")
    ADD_CLASS_METHOD(FindPoint_2,"vtkIdType vtkPointSet::FindPoint(double x, double y, double z)  (http://docs.wxwidgets.org/stable/wx_vtkpointset.html#findpoint)")
/* The following types are missing: vtkCell
    ADD_CLASS_METHOD(FindCell_1,"vtkIdType vtkPointSet::FindCell(double * x, vtkCell * cell, vtkIdType cellId, double tol2, int & subId, double * pcoords, double * weights)  (http://docs.wxwidgets.org/stable/wx_vtkpointset.html#findcell)")
*/
    ADD_CLASS_METHOD(FindCell,"vtkPointSet::FindCell()  (http://docs.wxwidgets.org/stable/wx_vtkpointset.html#findcell)")
/* The following types are missing: vtkCell, vtkGenericCell
    ADD_CLASS_METHOD(FindCell_2,"vtkIdType vtkPointSet::FindCell(double * x, vtkCell * cell, vtkGenericCell * gencell, vtkIdType cellId, double tol2, int & subId, double * pcoords, double * weights)  (http://docs.wxwidgets.org/stable/wx_vtkpointset.html#findcell)")
*/
    ADD_CLASS_METHOD(GetMTime,"long unsigned int vtkPointSet::GetMTime()  (http://docs.wxwidgets.org/stable/wx_vtkpointset.html#getmtime)")
    ADD_CLASS_METHOD(ComputeBounds,"void vtkPointSet::ComputeBounds()  (http://docs.wxwidgets.org/stable/wx_vtkpointset.html#computebounds)")
    ADD_CLASS_METHOD(Squeeze,"void vtkPointSet::Squeeze()  (http://docs.wxwidgets.org/stable/wx_vtkpointset.html#squeeze)")
    ADD_CLASS_METHOD(SetPoints,"void vtkPointSet::SetPoints(vtkPoints * param0)  (http://docs.wxwidgets.org/stable/wx_vtkpointset.html#setpoints)")
    ADD_CLASS_METHOD(GetPoints,"vtkPoints * vtkPointSet::GetPoints()  (http://docs.wxwidgets.org/stable/wx_vtkpointset.html#getpoints)")
    ADD_CLASS_METHOD(GetActualMemorySize,"long unsigned int vtkPointSet::GetActualMemorySize()  (http://docs.wxwidgets.org/stable/wx_vtkpointset.html#getactualmemorysize)")
    ADD_CLASS_METHOD(ShallowCopy,"void vtkPointSet::ShallowCopy(vtkDataObject * src)  (http://docs.wxwidgets.org/stable/wx_vtkpointset.html#shallowcopy)")
    ADD_CLASS_METHOD(DeepCopy,"void vtkPointSet::DeepCopy(vtkDataObject * src)  (http://docs.wxwidgets.org/stable/wx_vtkpointset.html#deepcopy)")





    void AddMethods(WrapClass<vtkPointSet>::ptr this_ptr );
    
    /*
     * Adds the constructor and the static methods to the given context
     */
    static void AddStaticMethods( Variables::ptr& context);

};


#endif // _wrap_vtkPointSet_h
