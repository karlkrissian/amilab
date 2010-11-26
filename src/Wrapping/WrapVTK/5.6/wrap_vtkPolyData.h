/**
 * C++ Interface: wrap_vtkPolyData
 *
 * Description: wrapping vtkPolyData
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_vtkPolyData_h_
#define _wrap_vtkPolyData_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "vtk_includes.h"

// include what is needed for inheritence and for types ...

//#include "wrap_vtkPointSet.h"



AMI_DECLARE_TYPE(vtkPolyData);

// TODO: check for inheritence ...
class WrapClass_vtkPolyData : public WrapClass<vtkPolyData>
    //, public  WrapClass_vtkPointSet
{
  DEFINE_CLASS(WrapClass_vtkPolyData);

  protected:
    typedef WrapClass<vtkPolyData>::ptr _parentclass_ptr;
    typedef vtkPolyData ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<vtkPolyData>& GetObj() const { return WrapClass<vtkPolyData>::GetObj(); }

    /// Constructor
    WrapClass_vtkPolyData(boost::shared_ptr<vtkPolyData > si): 
    WrapClass<vtkPolyData>(si)
    //, WrapClass_vtkPointSet(si)
    {}

    /// Destructor
    ~WrapClass_vtkPolyData()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( vtkPolyData*);

    // Static methods
    
    ADD_CLASS_STATICMETHOD(New,"vtkPolyData * vtkPolyData::New() (http://docs.wxwidgets.org/stable/wx_vtkpolydata.html#new).");
    ADD_CLASS_STATICMETHOD(IsTypeOf,"int vtkPolyData::IsTypeOf(char const * type) (http://docs.wxwidgets.org/stable/wx_vtkpolydata.html#istypeof).");
    ADD_CLASS_STATICMETHOD(SafeDownCast,"vtkPolyData * vtkPolyData::SafeDownCast(vtkObjectBase * o) (http://docs.wxwidgets.org/stable/wx_vtkpolydata.html#safedowncast).");
    /* The following types are missing: vtkInformation
    ADD_CLASS_STATICMETHOD(GetData_1,"vtkPolyData * vtkPolyData::GetData(vtkInformation * info) (http://docs.wxwidgets.org/stable/wx_vtkpolydata.html#getdata).");
    */
    ADD_CLASS_STATICMETHOD(GetData,"vtkPolyData::GetData() (http://docs.wxwidgets.org/stable/wx_vtkpolydata.html#getdata).");
    /* The following types are missing: vtkInformationVector
    ADD_CLASS_STATICMETHOD(GetData_2,"vtkPolyData * vtkPolyData::GetData(vtkInformationVector * v, int i = 0) (http://docs.wxwidgets.org/stable/wx_vtkpolydata.html#getdata).");
    */



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(IsA,"int vtkPolyData::IsA(char const * type)  (http://docs.wxwidgets.org/stable/wx_vtkpolydata.html#isa)")
    ADD_CLASS_METHOD(NewInstance,"vtkPolyData * vtkPolyData::NewInstance()  (http://docs.wxwidgets.org/stable/wx_vtkpolydata.html#newinstance)")
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
    ADD_CLASS_METHOD(PrintSelf,"void vtkPolyData::PrintSelf(ostream & os, vtkIndent indent)  (http://docs.wxwidgets.org/stable/wx_vtkpolydata.html#printself)")
*/
    ADD_CLASS_METHOD(GetDataObjectType,"int vtkPolyData::GetDataObjectType()  (http://docs.wxwidgets.org/stable/wx_vtkpolydata.html#getdataobjecttype)")
    ADD_CLASS_METHOD(CopyStructure,"void vtkPolyData::CopyStructure(vtkDataSet * ds)  (http://docs.wxwidgets.org/stable/wx_vtkpolydata.html#copystructure)")
/* The following types are missing: long long int
    ADD_CLASS_METHOD(GetNumberOfCells,"vtkIdType vtkPolyData::GetNumberOfCells()  (http://docs.wxwidgets.org/stable/wx_vtkpolydata.html#getnumberofcells)")
*/
/* The following types are missing: vtkCell, long long int
    ADD_CLASS_METHOD(GetCell_1,"vtkCell * vtkPolyData::GetCell(vtkIdType cellId)  (http://docs.wxwidgets.org/stable/wx_vtkpolydata.html#getcell)")
*/
    ADD_CLASS_METHOD(GetCell,"vtkPolyData::GetCell()  (http://docs.wxwidgets.org/stable/wx_vtkpolydata.html#getcell)")
/* The following types are missing: long long int, vtkGenericCell
    ADD_CLASS_METHOD(GetCell_2,"void vtkPolyData::GetCell(vtkIdType cellId, vtkGenericCell * cell)  (http://docs.wxwidgets.org/stable/wx_vtkpolydata.html#getcell)")
*/
/* The following types are missing: long long int
    ADD_CLASS_METHOD(GetCellType,"int vtkPolyData::GetCellType(vtkIdType cellId)  (http://docs.wxwidgets.org/stable/wx_vtkpolydata.html#getcelltype)")
*/
/* The following types are missing: long long int
    ADD_CLASS_METHOD(GetCellBounds,"void vtkPolyData::GetCellBounds(vtkIdType cellId, double * bounds)  (http://docs.wxwidgets.org/stable/wx_vtkpolydata.html#getcellbounds)")
*/
/* The following types are missing: long long int, vtkIdList, vtkIdList
    ADD_CLASS_METHOD(GetCellNeighbors,"void vtkPolyData::GetCellNeighbors(vtkIdType cellId, vtkIdList * ptIds, vtkIdList * cellIds)  (http://docs.wxwidgets.org/stable/wx_vtkpolydata.html#getcellneighbors)")
*/
/* The following types are missing: vtkIdList, vtkPointLocator
    ADD_CLASS_METHOD(CopyCells,"void vtkPolyData::CopyCells(vtkPolyData * pd, vtkIdList * idList, vtkPointLocator * locator = 0l)  (http://docs.wxwidgets.org/stable/wx_vtkpolydata.html#copycells)")
*/
/* The following types are missing: long long int, vtkIdList
    ADD_CLASS_METHOD(GetCellPoints_1,"void vtkPolyData::GetCellPoints(vtkIdType cellId, vtkIdList * ptIds)  (http://docs.wxwidgets.org/stable/wx_vtkpolydata.html#getcellpoints)")
*/
/* The following types are missing: long long int, vtkIdList
    ADD_CLASS_METHOD(GetPointCells_1,"void vtkPolyData::GetPointCells(vtkIdType ptId, vtkIdList * cellIds)  (http://docs.wxwidgets.org/stable/wx_vtkpolydata.html#getpointcells)")
*/
    ADD_CLASS_METHOD(ComputeBounds,"void vtkPolyData::ComputeBounds()  (http://docs.wxwidgets.org/stable/wx_vtkpolydata.html#computebounds)")
    ADD_CLASS_METHOD(Squeeze,"void vtkPolyData::Squeeze()  (http://docs.wxwidgets.org/stable/wx_vtkpolydata.html#squeeze)")
    ADD_CLASS_METHOD(GetMaxCellSize,"int vtkPolyData::GetMaxCellSize()  (http://docs.wxwidgets.org/stable/wx_vtkpolydata.html#getmaxcellsize)")
/* The following types are missing: vtkCellArray
    ADD_CLASS_METHOD(SetVerts,"void vtkPolyData::SetVerts(vtkCellArray * v)  (http://docs.wxwidgets.org/stable/wx_vtkpolydata.html#setverts)")
*/
/* The following types are missing: vtkCellArray
    ADD_CLASS_METHOD(GetVerts,"vtkCellArray * vtkPolyData::GetVerts()  (http://docs.wxwidgets.org/stable/wx_vtkpolydata.html#getverts)")
*/
/* The following types are missing: vtkCellArray
    ADD_CLASS_METHOD(SetLines,"void vtkPolyData::SetLines(vtkCellArray * l)  (http://docs.wxwidgets.org/stable/wx_vtkpolydata.html#setlines)")
*/
/* The following types are missing: vtkCellArray
    ADD_CLASS_METHOD(GetLines,"vtkCellArray * vtkPolyData::GetLines()  (http://docs.wxwidgets.org/stable/wx_vtkpolydata.html#getlines)")
*/
/* The following types are missing: vtkCellArray
    ADD_CLASS_METHOD(SetPolys,"void vtkPolyData::SetPolys(vtkCellArray * p)  (http://docs.wxwidgets.org/stable/wx_vtkpolydata.html#setpolys)")
*/
/* The following types are missing: vtkCellArray
    ADD_CLASS_METHOD(GetPolys,"vtkCellArray * vtkPolyData::GetPolys()  (http://docs.wxwidgets.org/stable/wx_vtkpolydata.html#getpolys)")
*/
/* The following types are missing: vtkCellArray
    ADD_CLASS_METHOD(SetStrips,"void vtkPolyData::SetStrips(vtkCellArray * s)  (http://docs.wxwidgets.org/stable/wx_vtkpolydata.html#setstrips)")
*/
/* The following types are missing: vtkCellArray
    ADD_CLASS_METHOD(GetStrips,"vtkCellArray * vtkPolyData::GetStrips()  (http://docs.wxwidgets.org/stable/wx_vtkpolydata.html#getstrips)")
*/
/* The following types are missing: long long int
    ADD_CLASS_METHOD(GetNumberOfVerts,"vtkIdType vtkPolyData::GetNumberOfVerts()  (http://docs.wxwidgets.org/stable/wx_vtkpolydata.html#getnumberofverts)")
*/
/* The following types are missing: long long int
    ADD_CLASS_METHOD(GetNumberOfLines,"vtkIdType vtkPolyData::GetNumberOfLines()  (http://docs.wxwidgets.org/stable/wx_vtkpolydata.html#getnumberoflines)")
*/
/* The following types are missing: long long int
    ADD_CLASS_METHOD(GetNumberOfPolys,"vtkIdType vtkPolyData::GetNumberOfPolys()  (http://docs.wxwidgets.org/stable/wx_vtkpolydata.html#getnumberofpolys)")
*/
/* The following types are missing: long long int
    ADD_CLASS_METHOD(GetNumberOfStrips,"vtkIdType vtkPolyData::GetNumberOfStrips()  (http://docs.wxwidgets.org/stable/wx_vtkpolydata.html#getnumberofstrips)")
*/
/* The following types are missing: long long int
    ADD_CLASS_METHOD(Allocate_1,"void vtkPolyData::Allocate(vtkIdType numCells = 1000, int extSize = 1000)  (http://docs.wxwidgets.org/stable/wx_vtkpolydata.html#allocate)")
*/
    ADD_CLASS_METHOD(Allocate,"vtkPolyData::Allocate()  (http://docs.wxwidgets.org/stable/wx_vtkpolydata.html#allocate)")
/* The following types are missing: long long int
    ADD_CLASS_METHOD(Allocate_2,"void vtkPolyData::Allocate(vtkPolyData * inPolyData, vtkIdType numCells = 1000, int extSize = 1000)  (http://docs.wxwidgets.org/stable/wx_vtkpolydata.html#allocate)")
*/
/* The following types are missing: long long int
    ADD_CLASS_METHOD(InsertNextCell_1,"int vtkPolyData::InsertNextCell(int type, int npts, vtkIdType * pts)  (http://docs.wxwidgets.org/stable/wx_vtkpolydata.html#insertnextcell)")
*/
    ADD_CLASS_METHOD(InsertNextCell,"vtkPolyData::InsertNextCell()  (http://docs.wxwidgets.org/stable/wx_vtkpolydata.html#insertnextcell)")
/* The following types are missing: vtkIdList
    ADD_CLASS_METHOD(InsertNextCell_2,"int vtkPolyData::InsertNextCell(int type, vtkIdList * pts)  (http://docs.wxwidgets.org/stable/wx_vtkpolydata.html#insertnextcell)")
*/
    ADD_CLASS_METHOD(Reset,"void vtkPolyData::Reset()  (http://docs.wxwidgets.org/stable/wx_vtkpolydata.html#reset)")
    ADD_CLASS_METHOD(BuildCells,"void vtkPolyData::BuildCells()  (http://docs.wxwidgets.org/stable/wx_vtkpolydata.html#buildcells)")
    ADD_CLASS_METHOD(BuildLinks,"void vtkPolyData::BuildLinks(int initialSize = 0)  (http://docs.wxwidgets.org/stable/wx_vtkpolydata.html#buildlinks)")
    ADD_CLASS_METHOD(DeleteCells,"void vtkPolyData::DeleteCells()  (http://docs.wxwidgets.org/stable/wx_vtkpolydata.html#deletecells)")
    ADD_CLASS_METHOD(DeleteLinks,"void vtkPolyData::DeleteLinks()  (http://docs.wxwidgets.org/stable/wx_vtkpolydata.html#deletelinks)")
    ADD_CLASS_METHOD(GetPointCells,"vtkPolyData::GetPointCells()  (http://docs.wxwidgets.org/stable/wx_vtkpolydata.html#getpointcells)")
/* The following types are missing: long long int, short unsigned int, long long int
    ADD_CLASS_METHOD(GetPointCells_2,"void vtkPolyData::GetPointCells(vtkIdType ptId, short unsigned int & ncells, vtkIdType * & cells)  (http://docs.wxwidgets.org/stable/wx_vtkpolydata.html#getpointcells)")
*/
/* The following types are missing: long long int, long long int, long long int, vtkIdList
    ADD_CLASS_METHOD(GetCellEdgeNeighbors,"void vtkPolyData::GetCellEdgeNeighbors(vtkIdType cellId, vtkIdType p1, vtkIdType p2, vtkIdList * cellIds)  (http://docs.wxwidgets.org/stable/wx_vtkpolydata.html#getcelledgeneighbors)")
*/
    ADD_CLASS_METHOD(GetCellPoints,"vtkPolyData::GetCellPoints()  (http://docs.wxwidgets.org/stable/wx_vtkpolydata.html#getcellpoints)")
/* The following types are missing: long long int, long long int, long long int
    ADD_CLASS_METHOD(GetCellPoints_2,"void vtkPolyData::GetCellPoints(vtkIdType cellId, vtkIdType & npts, vtkIdType * & pts)  (http://docs.wxwidgets.org/stable/wx_vtkpolydata.html#getcellpoints)")
*/
    ADD_CLASS_METHOD(IsTriangle,"int vtkPolyData::IsTriangle(int v1, int v2, int v3)  (http://docs.wxwidgets.org/stable/wx_vtkpolydata.html#istriangle)")
/* The following types are missing: long long int, long long int
    ADD_CLASS_METHOD(IsEdge,"int vtkPolyData::IsEdge(vtkIdType p1, vtkIdType p2)  (http://docs.wxwidgets.org/stable/wx_vtkpolydata.html#isedge)")
*/
/* The following types are missing: long long int, long long int
    ADD_CLASS_METHOD(IsPointUsedByCell,"int vtkPolyData::IsPointUsedByCell(vtkIdType ptId, vtkIdType cellId)  (http://docs.wxwidgets.org/stable/wx_vtkpolydata.html#ispointusedbycell)")
*/
/* The following types are missing: long long int, long long int
    ADD_CLASS_METHOD(ReplaceCell,"void vtkPolyData::ReplaceCell(vtkIdType cellId, int npts, vtkIdType * pts)  (http://docs.wxwidgets.org/stable/wx_vtkpolydata.html#replacecell)")
*/
/* The following types are missing: long long int, long long int, long long int
    ADD_CLASS_METHOD(ReplaceCellPoint,"void vtkPolyData::ReplaceCellPoint(vtkIdType cellId, vtkIdType oldPtId, vtkIdType newPtId)  (http://docs.wxwidgets.org/stable/wx_vtkpolydata.html#replacecellpoint)")
*/
/* The following types are missing: long long int
    ADD_CLASS_METHOD(ReverseCell,"void vtkPolyData::ReverseCell(vtkIdType cellId)  (http://docs.wxwidgets.org/stable/wx_vtkpolydata.html#reversecell)")
*/
/* The following types are missing: long long int
    ADD_CLASS_METHOD(DeletePoint,"void vtkPolyData::DeletePoint(vtkIdType ptId)  (http://docs.wxwidgets.org/stable/wx_vtkpolydata.html#deletepoint)")
*/
/* The following types are missing: long long int
    ADD_CLASS_METHOD(DeleteCell,"void vtkPolyData::DeleteCell(vtkIdType cellId)  (http://docs.wxwidgets.org/stable/wx_vtkpolydata.html#deletecell)")
*/
    ADD_CLASS_METHOD(RemoveDeletedCells,"void vtkPolyData::RemoveDeletedCells()  (http://docs.wxwidgets.org/stable/wx_vtkpolydata.html#removedeletedcells)")
    ADD_CLASS_METHOD(InsertNextLinkedPoint_1,"int vtkPolyData::InsertNextLinkedPoint(int numLinks)  (http://docs.wxwidgets.org/stable/wx_vtkpolydata.html#insertnextlinkedpoint)")
    ADD_CLASS_METHOD(InsertNextLinkedPoint,"vtkPolyData::InsertNextLinkedPoint()  (http://docs.wxwidgets.org/stable/wx_vtkpolydata.html#insertnextlinkedpoint)")
    ADD_CLASS_METHOD(InsertNextLinkedPoint_2,"int vtkPolyData::InsertNextLinkedPoint(double * x, int numLinks)  (http://docs.wxwidgets.org/stable/wx_vtkpolydata.html#insertnextlinkedpoint)")
/* The following types are missing: long long int
    ADD_CLASS_METHOD(InsertNextLinkedCell,"int vtkPolyData::InsertNextLinkedCell(int type, int npts, vtkIdType * pts)  (http://docs.wxwidgets.org/stable/wx_vtkpolydata.html#insertnextlinkedcell)")
*/
/* The following types are missing: long long int, long long int
    ADD_CLASS_METHOD(ReplaceLinkedCell,"void vtkPolyData::ReplaceLinkedCell(vtkIdType cellId, int npts, vtkIdType * pts)  (http://docs.wxwidgets.org/stable/wx_vtkpolydata.html#replacelinkedcell)")
*/
/* The following types are missing: long long int
    ADD_CLASS_METHOD(RemoveCellReference,"void vtkPolyData::RemoveCellReference(vtkIdType cellId)  (http://docs.wxwidgets.org/stable/wx_vtkpolydata.html#removecellreference)")
*/
/* The following types are missing: long long int
    ADD_CLASS_METHOD(AddCellReference,"void vtkPolyData::AddCellReference(vtkIdType cellId)  (http://docs.wxwidgets.org/stable/wx_vtkpolydata.html#addcellreference)")
*/
/* The following types are missing: long long int, long long int
    ADD_CLASS_METHOD(RemoveReferenceToCell,"void vtkPolyData::RemoveReferenceToCell(vtkIdType ptId, vtkIdType cellId)  (http://docs.wxwidgets.org/stable/wx_vtkpolydata.html#removereferencetocell)")
*/
/* The following types are missing: long long int, long long int
    ADD_CLASS_METHOD(AddReferenceToCell,"void vtkPolyData::AddReferenceToCell(vtkIdType ptId, vtkIdType cellId)  (http://docs.wxwidgets.org/stable/wx_vtkpolydata.html#addreferencetocell)")
*/
/* The following types are missing: long long int
    ADD_CLASS_METHOD(ResizeCellList,"void vtkPolyData::ResizeCellList(vtkIdType ptId, int size)  (http://docs.wxwidgets.org/stable/wx_vtkpolydata.html#resizecelllist)")
*/
    ADD_CLASS_METHOD(Initialize,"void vtkPolyData::Initialize()  (http://docs.wxwidgets.org/stable/wx_vtkpolydata.html#initialize)")
    ADD_CLASS_METHOD(GetUpdateExtent_1,"void vtkPolyData::GetUpdateExtent(int & piece, int & numPieces, int & ghostLevel)  (http://docs.wxwidgets.org/stable/wx_vtkpolydata.html#getupdateextent)")
    ADD_CLASS_METHOD(GetUpdateExtent,"vtkPolyData::GetUpdateExtent()  (http://docs.wxwidgets.org/stable/wx_vtkpolydata.html#getupdateextent)")
    ADD_CLASS_METHOD(GetUpdateExtent_2,"int * vtkPolyData::GetUpdateExtent()  (http://docs.wxwidgets.org/stable/wx_vtkpolydata.html#getupdateextent)")
    ADD_CLASS_METHOD(GetUpdateExtent_3,"void vtkPolyData::GetUpdateExtent(int & x0, int & x1, int & y0, int & y1, int & z0, int & z1)  (http://docs.wxwidgets.org/stable/wx_vtkpolydata.html#getupdateextent)")
    ADD_CLASS_METHOD(GetUpdateExtent_4,"void vtkPolyData::GetUpdateExtent(int * extent)  (http://docs.wxwidgets.org/stable/wx_vtkpolydata.html#getupdateextent)")
    ADD_CLASS_METHOD(GetPiece,"int vtkPolyData::GetPiece()  (http://docs.wxwidgets.org/stable/wx_vtkpolydata.html#getpiece)")
    ADD_CLASS_METHOD(GetNumberOfPieces,"int vtkPolyData::GetNumberOfPieces()  (http://docs.wxwidgets.org/stable/wx_vtkpolydata.html#getnumberofpieces)")
    ADD_CLASS_METHOD(GetGhostLevel,"int vtkPolyData::GetGhostLevel()  (http://docs.wxwidgets.org/stable/wx_vtkpolydata.html#getghostlevel)")
    ADD_CLASS_METHOD(GetActualMemorySize,"long unsigned int vtkPolyData::GetActualMemorySize()  (http://docs.wxwidgets.org/stable/wx_vtkpolydata.html#getactualmemorysize)")
    ADD_CLASS_METHOD(ShallowCopy,"void vtkPolyData::ShallowCopy(vtkDataObject * src)  (http://docs.wxwidgets.org/stable/wx_vtkpolydata.html#shallowcopy)")
    ADD_CLASS_METHOD(DeepCopy,"void vtkPolyData::DeepCopy(vtkDataObject * src)  (http://docs.wxwidgets.org/stable/wx_vtkpolydata.html#deepcopy)")
    ADD_CLASS_METHOD(RemoveGhostCells,"void vtkPolyData::RemoveGhostCells(int level)  (http://docs.wxwidgets.org/stable/wx_vtkpolydata.html#removeghostcells)")
/* The following types are missing: long long int, vtkDataArray
    ADD_CLASS_METHOD(GetScalarFieldCriticalIndex_1,"int vtkPolyData::GetScalarFieldCriticalIndex(vtkIdType pointId, vtkDataArray * scalarField)  (http://docs.wxwidgets.org/stable/wx_vtkpolydata.html#getscalarfieldcriticalindex)")
*/
    ADD_CLASS_METHOD(GetScalarFieldCriticalIndex,"vtkPolyData::GetScalarFieldCriticalIndex()  (http://docs.wxwidgets.org/stable/wx_vtkpolydata.html#getscalarfieldcriticalindex)")
/* The following types are missing: long long int
    ADD_CLASS_METHOD(GetScalarFieldCriticalIndex_2,"int vtkPolyData::GetScalarFieldCriticalIndex(vtkIdType pointId, int fieldId)  (http://docs.wxwidgets.org/stable/wx_vtkpolydata.html#getscalarfieldcriticalindex)")
*/
/* The following types are missing: long long int
    ADD_CLASS_METHOD(GetScalarFieldCriticalIndex_3,"int vtkPolyData::GetScalarFieldCriticalIndex(vtkIdType pointId, char const * fieldName)  (http://docs.wxwidgets.org/stable/wx_vtkpolydata.html#getscalarfieldcriticalindex)")
*/





    void AddMethods(WrapClass<vtkPolyData>::ptr this_ptr );

};


#endif // _wrap_vtkPolyData_h
