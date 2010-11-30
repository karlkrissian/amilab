/**
 * C++ Interface: wrap_vtkDataSet
 *
 * Description: wrapping vtkDataSet
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_vtkDataSet_h_
#define _wrap_vtkDataSet_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "vtk_includes.h"

// include what is needed for inheritence and for types ...

#include "wrap_vtkDataObject.h"



AMI_DECLARE_TYPE(vtkDataSet);

// TODO: check for inheritence ...
class WrapClass_vtkDataSet : public WrapClass<vtkDataSet>
    , public   WrapClass_vtkDataObject
{
  DEFINE_CLASS(WrapClass_vtkDataSet);

  protected:
    typedef WrapClass<vtkDataSet>::ptr _parentclass_ptr;
    typedef vtkDataSet ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<vtkDataSet>& GetObj() const { return WrapClass<vtkDataSet>::GetObj(); }

    /// Constructor
    WrapClass_vtkDataSet(boost::shared_ptr<vtkDataSet > si): 
    WrapClass<vtkDataSet>(si)
    , WrapClass_vtkDataObject(si)
    {}

    /// Destructor
    ~WrapClass_vtkDataSet()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    


    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( vtkDataSet*);

    // Static methods
    
    ADD_CLASS_STATICMETHOD(IsTypeOf,"int vtkDataSet::IsTypeOf(char const * type) (http://docs.wxwidgets.org/stable/wx_vtkdataset.html#istypeof).");
    ADD_CLASS_STATICMETHOD(SafeDownCast,"vtkDataSet * vtkDataSet::SafeDownCast(vtkObjectBase * o) (http://docs.wxwidgets.org/stable/wx_vtkdataset.html#safedowncast).");
    /* The following types are missing: vtkInformation
    ADD_CLASS_STATICMETHOD(GetData_1,"vtkDataSet * vtkDataSet::GetData(vtkInformation * info) (http://docs.wxwidgets.org/stable/wx_vtkdataset.html#getdata).");
    */
    ADD_CLASS_STATICMETHOD(GetData,"vtkDataSet::GetData() (http://docs.wxwidgets.org/stable/wx_vtkdataset.html#getdata).");
    /* The following types are missing: vtkInformationVector
    ADD_CLASS_STATICMETHOD(GetData_2,"vtkDataSet * vtkDataSet::GetData(vtkInformationVector * v, int i = 0) (http://docs.wxwidgets.org/stable/wx_vtkdataset.html#getdata).");
    */



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(IsA,"int vtkDataSet::IsA(char const * type)  (http://docs.wxwidgets.org/stable/wx_vtkdataset.html#isa)")
    ADD_CLASS_METHOD(NewInstance,"vtkDataSet * vtkDataSet::NewInstance()  (http://docs.wxwidgets.org/stable/wx_vtkdataset.html#newinstance)")
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
    ADD_CLASS_METHOD(PrintSelf,"void vtkDataSet::PrintSelf(ostream & os, vtkIndent indent)  (http://docs.wxwidgets.org/stable/wx_vtkdataset.html#printself)")
*/
    ADD_CLASS_METHOD(CopyAttributes,"void vtkDataSet::CopyAttributes(vtkDataSet * ds)  (http://docs.wxwidgets.org/stable/wx_vtkdataset.html#copyattributes)")
    ADD_CLASS_METHOD(GetPoint,"void vtkDataSet::GetPoint(vtkIdType id, double * x)  (http://docs.wxwidgets.org/stable/wx_vtkdataset.html#getpoint)")
    ADD_CLASS_METHOD(GetCellBounds,"void vtkDataSet::GetCellBounds(vtkIdType cellId, double * bounds)  (http://docs.wxwidgets.org/stable/wx_vtkdataset.html#getcellbounds)")
    ADD_CLASS_METHOD(GetCellTypes,"void vtkDataSet::GetCellTypes(vtkCellTypes * types)  (http://docs.wxwidgets.org/stable/wx_vtkdataset.html#getcelltypes)")
/* The following types are missing: vtkIdList, vtkIdList
    ADD_CLASS_METHOD(GetCellNeighbors,"void vtkDataSet::GetCellNeighbors(vtkIdType cellId, vtkIdList * ptIds, vtkIdList * cellIds)  (http://docs.wxwidgets.org/stable/wx_vtkdataset.html#getcellneighbors)")
*/
    ADD_CLASS_METHOD(FindPoint,"vtkIdType vtkDataSet::FindPoint(double x, double y, double z)  (http://docs.wxwidgets.org/stable/wx_vtkdataset.html#findpoint)")
/* The following types are missing: vtkCell, vtkCell
    ADD_CLASS_METHOD(FindAndGetCell,"vtkCell * vtkDataSet::FindAndGetCell(double * x, vtkCell * cell, vtkIdType cellId, double tol2, int & subId, double * pcoords, double * weights)  (http://docs.wxwidgets.org/stable/wx_vtkdataset.html#findandgetcell)")
*/
    ADD_CLASS_METHOD(GetMTime,"long unsigned int vtkDataSet::GetMTime()  (http://docs.wxwidgets.org/stable/wx_vtkdataset.html#getmtime)")
/* The following types are missing: vtkCellData
    ADD_CLASS_METHOD(GetCellData,"vtkCellData * vtkDataSet::GetCellData()  (http://docs.wxwidgets.org/stable/wx_vtkdataset.html#getcelldata)")
*/
/* The following types are missing: vtkPointData
    ADD_CLASS_METHOD(GetPointData,"vtkPointData * vtkDataSet::GetPointData()  (http://docs.wxwidgets.org/stable/wx_vtkdataset.html#getpointdata)")
*/
    ADD_CLASS_METHOD(Squeeze,"void vtkDataSet::Squeeze()  (http://docs.wxwidgets.org/stable/wx_vtkdataset.html#squeeze)")
    ADD_CLASS_METHOD(ComputeBounds,"void vtkDataSet::ComputeBounds()  (http://docs.wxwidgets.org/stable/wx_vtkdataset.html#computebounds)")
    ADD_CLASS_METHOD(GetBounds_1,"double * vtkDataSet::GetBounds()  (http://docs.wxwidgets.org/stable/wx_vtkdataset.html#getbounds)")
    ADD_CLASS_METHOD(GetBounds,"vtkDataSet::GetBounds()  (http://docs.wxwidgets.org/stable/wx_vtkdataset.html#getbounds)")
    ADD_CLASS_METHOD(GetBounds_2,"void vtkDataSet::GetBounds(double * bounds)  (http://docs.wxwidgets.org/stable/wx_vtkdataset.html#getbounds)")
    ADD_CLASS_METHOD(GetCenter_1,"double * vtkDataSet::GetCenter()  (http://docs.wxwidgets.org/stable/wx_vtkdataset.html#getcenter)")
    ADD_CLASS_METHOD(GetCenter,"vtkDataSet::GetCenter()  (http://docs.wxwidgets.org/stable/wx_vtkdataset.html#getcenter)")
    ADD_CLASS_METHOD(GetCenter_2,"void vtkDataSet::GetCenter(double * center)  (http://docs.wxwidgets.org/stable/wx_vtkdataset.html#getcenter)")
    ADD_CLASS_METHOD(GetLength,"double vtkDataSet::GetLength()  (http://docs.wxwidgets.org/stable/wx_vtkdataset.html#getlength)")
    ADD_CLASS_METHOD(Initialize,"void vtkDataSet::Initialize()  (http://docs.wxwidgets.org/stable/wx_vtkdataset.html#initialize)")
    ADD_CLASS_METHOD(GetScalarRange_1,"void vtkDataSet::GetScalarRange(double * range)  (http://docs.wxwidgets.org/stable/wx_vtkdataset.html#getscalarrange)")
    ADD_CLASS_METHOD(GetScalarRange,"vtkDataSet::GetScalarRange()  (http://docs.wxwidgets.org/stable/wx_vtkdataset.html#getscalarrange)")
    ADD_CLASS_METHOD(GetScalarRange_2,"double * vtkDataSet::GetScalarRange()  (http://docs.wxwidgets.org/stable/wx_vtkdataset.html#getscalarrange)")
    ADD_CLASS_METHOD(GetActualMemorySize,"long unsigned int vtkDataSet::GetActualMemorySize()  (http://docs.wxwidgets.org/stable/wx_vtkdataset.html#getactualmemorysize)")
    ADD_CLASS_METHOD(GetDataObjectType,"int vtkDataSet::GetDataObjectType()  (http://docs.wxwidgets.org/stable/wx_vtkdataset.html#getdataobjecttype)")
    ADD_CLASS_METHOD(ShallowCopy,"void vtkDataSet::ShallowCopy(vtkDataObject * src)  (http://docs.wxwidgets.org/stable/wx_vtkdataset.html#shallowcopy)")
    ADD_CLASS_METHOD(DeepCopy,"void vtkDataSet::DeepCopy(vtkDataObject * src)  (http://docs.wxwidgets.org/stable/wx_vtkdataset.html#deepcopy)")
    ADD_CLASS_METHOD(CheckAttributes,"int vtkDataSet::CheckAttributes()  (http://docs.wxwidgets.org/stable/wx_vtkdataset.html#checkattributes)")
    ADD_CLASS_METHOD(GenerateGhostLevelArray,"void vtkDataSet::GenerateGhostLevelArray()  (http://docs.wxwidgets.org/stable/wx_vtkdataset.html#generateghostlevelarray)")
/* The following types are missing: vtkFieldData
    ADD_CLASS_METHOD(GetAttributesAsFieldData,"vtkFieldData * vtkDataSet::GetAttributesAsFieldData(int type)  (http://docs.wxwidgets.org/stable/wx_vtkdataset.html#getattributesasfielddata)")
*/
    ADD_CLASS_METHOD(GetNumberOfElements,"vtkIdType vtkDataSet::GetNumberOfElements(int type)  (http://docs.wxwidgets.org/stable/wx_vtkdataset.html#getnumberofelements)")





    void AddMethods(WrapClass<vtkDataSet>::ptr this_ptr );

};


#endif // _wrap_vtkDataSet_h
