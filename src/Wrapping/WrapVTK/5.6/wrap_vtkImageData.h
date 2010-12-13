/**
 * C++ Interface: wrap_vtkImageData
 *
 * Description: wrapping vtkImageData
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_vtkImageData_h_
#define _wrap_vtkImageData_h_

/*
#include "Variable.hpp"
#include "ami_object.h"
*/
#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "paramlist.h"

#include "vtkImageData.h"

// include what is needed for inheritence and for types ...

#include "wrap_vtkDataSet.h"


#ifndef vtkImageData_declared
  #define vtkImageData_declared
  AMI_DECLARE_TYPE(vtkImageData);
#endif

// TODO: check for inheritence ...
class WrapClass_vtkImageData : public WrapClass<vtkImageData>
    , public   WrapClass_vtkDataSet
{
  DEFINE_CLASS(WrapClass_vtkImageData);

  protected:
    typedef WrapClass<vtkImageData>::ptr _parentclass_ptr;
    typedef vtkImageData ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<vtkImageData>& GetObj() const { return WrapClass<vtkImageData>::GetObj(); }

    /// Constructor
    WrapClass_vtkImageData(boost::shared_ptr<vtkImageData > si): 
    WrapClass<vtkImageData>(si)
    , WrapClass_vtkDataSet(si)
    {}

    /// Destructor
    ~WrapClass_vtkImageData()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( vtkImageData*);

    // Static methods
    
    ADD_CLASS_STATICMETHOD(New,"vtkImageData * vtkImageData::New() (http://docs.wxwidgets.org/stable/wx_vtkimagedata.html#new).");
    ADD_CLASS_STATICMETHOD(IsTypeOf,"int vtkImageData::IsTypeOf(char const * type) (http://docs.wxwidgets.org/stable/wx_vtkimagedata.html#istypeof).");
    ADD_CLASS_STATICMETHOD(SafeDownCast,"vtkImageData * vtkImageData::SafeDownCast(vtkObjectBase * o) (http://docs.wxwidgets.org/stable/wx_vtkimagedata.html#safedowncast).");
    /* The following types are missing: vtkInformation
    ADD_CLASS_STATICMETHOD(GetData_1,"vtkImageData * vtkImageData::GetData(vtkInformation * info) (http://docs.wxwidgets.org/stable/wx_vtkimagedata.html#getdata).");
    */
    ADD_CLASS_STATICMETHOD(GetData,"vtkImageData::GetData() (http://docs.wxwidgets.org/stable/wx_vtkimagedata.html#getdata).");
    /* The following types are missing: vtkInformationVector
    ADD_CLASS_STATICMETHOD(GetData_2,"vtkImageData * vtkImageData::GetData(vtkInformationVector * v, int i = 0) (http://docs.wxwidgets.org/stable/wx_vtkimagedata.html#getdata).");
    */



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(IsA,"int vtkImageData::IsA(char const * type)  (http://docs.wxwidgets.org/stable/wx_vtkimagedata.html#isa)")
    ADD_CLASS_METHOD(NewInstance,"vtkImageData * vtkImageData::NewInstance()  (http://docs.wxwidgets.org/stable/wx_vtkimagedata.html#newinstance)")
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
    ADD_CLASS_METHOD(PrintSelf,"void vtkImageData::PrintSelf(ostream & os, vtkIndent indent)  (http://docs.wxwidgets.org/stable/wx_vtkimagedata.html#printself)")
*/
    ADD_CLASS_METHOD(CopyStructure,"void vtkImageData::CopyStructure(vtkDataSet * ds)  (http://docs.wxwidgets.org/stable/wx_vtkimagedata.html#copystructure)")
    ADD_CLASS_METHOD(GetDataObjectType,"int vtkImageData::GetDataObjectType()  (http://docs.wxwidgets.org/stable/wx_vtkimagedata.html#getdataobjecttype)")
    ADD_CLASS_METHOD(GetNumberOfCells,"vtkIdType vtkImageData::GetNumberOfCells()  (http://docs.wxwidgets.org/stable/wx_vtkimagedata.html#getnumberofcells)")
    ADD_CLASS_METHOD(GetNumberOfPoints,"vtkIdType vtkImageData::GetNumberOfPoints()  (http://docs.wxwidgets.org/stable/wx_vtkimagedata.html#getnumberofpoints)")
    ADD_CLASS_METHOD(GetPoint_1,"double * vtkImageData::GetPoint(vtkIdType ptId)  (http://docs.wxwidgets.org/stable/wx_vtkimagedata.html#getpoint)")
    ADD_CLASS_METHOD(GetPoint,"vtkImageData::GetPoint()  (http://docs.wxwidgets.org/stable/wx_vtkimagedata.html#getpoint)")
    ADD_CLASS_METHOD(GetPoint_2,"void vtkImageData::GetPoint(vtkIdType id, double * x)  (http://docs.wxwidgets.org/stable/wx_vtkimagedata.html#getpoint)")
/* The following types are missing: vtkCell
    ADD_CLASS_METHOD(GetCell_1,"vtkCell * vtkImageData::GetCell(vtkIdType cellId)  (http://docs.wxwidgets.org/stable/wx_vtkimagedata.html#getcell)")
*/
    ADD_CLASS_METHOD(GetCell,"vtkImageData::GetCell()  (http://docs.wxwidgets.org/stable/wx_vtkimagedata.html#getcell)")
/* The following types are missing: vtkGenericCell
    ADD_CLASS_METHOD(GetCell_2,"void vtkImageData::GetCell(vtkIdType cellId, vtkGenericCell * cell)  (http://docs.wxwidgets.org/stable/wx_vtkimagedata.html#getcell)")
*/
    ADD_CLASS_METHOD(GetCellBounds,"void vtkImageData::GetCellBounds(vtkIdType cellId, double * bounds)  (http://docs.wxwidgets.org/stable/wx_vtkimagedata.html#getcellbounds)")
    ADD_CLASS_METHOD(FindPoint_1,"vtkIdType vtkImageData::FindPoint(double x, double y, double z)  (http://docs.wxwidgets.org/stable/wx_vtkimagedata.html#findpoint)")
    ADD_CLASS_METHOD(FindPoint,"vtkImageData::FindPoint()  (http://docs.wxwidgets.org/stable/wx_vtkimagedata.html#findpoint)")
    ADD_CLASS_METHOD(FindPoint_2,"vtkIdType vtkImageData::FindPoint(double * x)  (http://docs.wxwidgets.org/stable/wx_vtkimagedata.html#findpoint)")
/* The following types are missing: vtkCell
    ADD_CLASS_METHOD(FindCell_1,"vtkIdType vtkImageData::FindCell(double * x, vtkCell * cell, vtkIdType cellId, double tol2, int & subId, double * pcoords, double * weights)  (http://docs.wxwidgets.org/stable/wx_vtkimagedata.html#findcell)")
*/
    ADD_CLASS_METHOD(FindCell,"vtkImageData::FindCell()  (http://docs.wxwidgets.org/stable/wx_vtkimagedata.html#findcell)")
/* The following types are missing: vtkCell, vtkGenericCell
    ADD_CLASS_METHOD(FindCell_2,"vtkIdType vtkImageData::FindCell(double * x, vtkCell * cell, vtkGenericCell * gencell, vtkIdType cellId, double tol2, int & subId, double * pcoords, double * weights)  (http://docs.wxwidgets.org/stable/wx_vtkimagedata.html#findcell)")
*/
/* The following types are missing: vtkCell, vtkCell
    ADD_CLASS_METHOD(FindAndGetCell,"vtkCell * vtkImageData::FindAndGetCell(double * x, vtkCell * cell, vtkIdType cellId, double tol2, int & subId, double * pcoords, double * weights)  (http://docs.wxwidgets.org/stable/wx_vtkimagedata.html#findandgetcell)")
*/
    ADD_CLASS_METHOD(GetCellType,"int vtkImageData::GetCellType(vtkIdType cellId)  (http://docs.wxwidgets.org/stable/wx_vtkimagedata.html#getcelltype)")
/* The following types are missing: vtkIdList
    ADD_CLASS_METHOD(GetCellPoints,"void vtkImageData::GetCellPoints(vtkIdType cellId, vtkIdList * ptIds)  (http://docs.wxwidgets.org/stable/wx_vtkimagedata.html#getcellpoints)")
*/
/* The following types are missing: vtkIdList
    ADD_CLASS_METHOD(GetPointCells,"void vtkImageData::GetPointCells(vtkIdType ptId, vtkIdList * cellIds)  (http://docs.wxwidgets.org/stable/wx_vtkimagedata.html#getpointcells)")
*/
    ADD_CLASS_METHOD(ComputeBounds,"void vtkImageData::ComputeBounds()  (http://docs.wxwidgets.org/stable/wx_vtkimagedata.html#computebounds)")
    ADD_CLASS_METHOD(GetMaxCellSize,"int vtkImageData::GetMaxCellSize()  (http://docs.wxwidgets.org/stable/wx_vtkimagedata.html#getmaxcellsize)")
    ADD_CLASS_METHOD(Initialize,"void vtkImageData::Initialize()  (http://docs.wxwidgets.org/stable/wx_vtkimagedata.html#initialize)")
    ADD_CLASS_METHOD(SetDimensions_1,"void vtkImageData::SetDimensions(int i, int j, int k)  (http://docs.wxwidgets.org/stable/wx_vtkimagedata.html#setdimensions)")
    ADD_CLASS_METHOD(SetDimensions,"vtkImageData::SetDimensions()  (http://docs.wxwidgets.org/stable/wx_vtkimagedata.html#setdimensions)")
    ADD_CLASS_METHOD(SetDimensions_2,"void vtkImageData::SetDimensions(int const * dims)  (http://docs.wxwidgets.org/stable/wx_vtkimagedata.html#setdimensions)")
    ADD_CLASS_METHOD(GetDimensions_1,"int * vtkImageData::GetDimensions()  (http://docs.wxwidgets.org/stable/wx_vtkimagedata.html#getdimensions)")
    ADD_CLASS_METHOD(GetDimensions,"vtkImageData::GetDimensions()  (http://docs.wxwidgets.org/stable/wx_vtkimagedata.html#getdimensions)")
    ADD_CLASS_METHOD(GetDimensions_2,"void vtkImageData::GetDimensions(int * dims)  (http://docs.wxwidgets.org/stable/wx_vtkimagedata.html#getdimensions)")
    ADD_CLASS_METHOD(ComputeStructuredCoordinates,"int vtkImageData::ComputeStructuredCoordinates(double * x, int * ijk, double * pcoords)  (http://docs.wxwidgets.org/stable/wx_vtkimagedata.html#computestructuredcoordinates)")
    ADD_CLASS_METHOD(GetVoxelGradient,"void vtkImageData::GetVoxelGradient(int i, int j, int k, vtkDataArray * s, vtkDataArray * g)  (http://docs.wxwidgets.org/stable/wx_vtkimagedata.html#getvoxelgradient)")
    ADD_CLASS_METHOD(GetPointGradient,"void vtkImageData::GetPointGradient(int i, int j, int k, vtkDataArray * s, double * g)  (http://docs.wxwidgets.org/stable/wx_vtkimagedata.html#getpointgradient)")
    ADD_CLASS_METHOD(GetDataDimension,"int vtkImageData::GetDataDimension()  (http://docs.wxwidgets.org/stable/wx_vtkimagedata.html#getdatadimension)")
    ADD_CLASS_METHOD(ComputePointId,"vtkIdType vtkImageData::ComputePointId(int * ijk)  (http://docs.wxwidgets.org/stable/wx_vtkimagedata.html#computepointid)")
    ADD_CLASS_METHOD(ComputeCellId,"vtkIdType vtkImageData::ComputeCellId(int * ijk)  (http://docs.wxwidgets.org/stable/wx_vtkimagedata.html#computecellid)")
    ADD_CLASS_METHOD(SetAxisUpdateExtent,"void vtkImageData::SetAxisUpdateExtent(int axis, int min, int max)  (http://docs.wxwidgets.org/stable/wx_vtkimagedata.html#setaxisupdateextent)")
    ADD_CLASS_METHOD(GetAxisUpdateExtent,"void vtkImageData::GetAxisUpdateExtent(int axis, int & min, int & max)  (http://docs.wxwidgets.org/stable/wx_vtkimagedata.html#getaxisupdateextent)")
    ADD_CLASS_METHOD(UpdateInformation,"void vtkImageData::UpdateInformation()  (http://docs.wxwidgets.org/stable/wx_vtkimagedata.html#updateinformation)")
    ADD_CLASS_METHOD(SetExtent_1,"void vtkImageData::SetExtent(int * extent)  (http://docs.wxwidgets.org/stable/wx_vtkimagedata.html#setextent)")
    ADD_CLASS_METHOD(SetExtent,"vtkImageData::SetExtent()  (http://docs.wxwidgets.org/stable/wx_vtkimagedata.html#setextent)")
    ADD_CLASS_METHOD(SetExtent_2,"void vtkImageData::SetExtent(int x1, int x2, int y1, int y2, int z1, int z2)  (http://docs.wxwidgets.org/stable/wx_vtkimagedata.html#setextent)")
    ADD_CLASS_METHOD(GetExtent_1,"int * vtkImageData::GetExtent()  (http://docs.wxwidgets.org/stable/wx_vtkimagedata.html#getextent)")
    ADD_CLASS_METHOD(GetExtent,"vtkImageData::GetExtent()  (http://docs.wxwidgets.org/stable/wx_vtkimagedata.html#getextent)")
    ADD_CLASS_METHOD(GetExtent_2,"void vtkImageData::GetExtent(int & _arg1, int & _arg2, int & _arg3, int & _arg4, int & _arg5, int & _arg6)  (http://docs.wxwidgets.org/stable/wx_vtkimagedata.html#getextent)")
    ADD_CLASS_METHOD(GetExtent_3,"void vtkImageData::GetExtent(int * _arg)  (http://docs.wxwidgets.org/stable/wx_vtkimagedata.html#getextent)")
    ADD_CLASS_METHOD(GetEstimatedMemorySize,"long unsigned int vtkImageData::GetEstimatedMemorySize()  (http://docs.wxwidgets.org/stable/wx_vtkimagedata.html#getestimatedmemorysize)")
    ADD_CLASS_METHOD(GetScalarTypeMin,"double vtkImageData::GetScalarTypeMin()  (http://docs.wxwidgets.org/stable/wx_vtkimagedata.html#getscalartypemin)")
    ADD_CLASS_METHOD(GetScalarTypeMax,"double vtkImageData::GetScalarTypeMax()  (http://docs.wxwidgets.org/stable/wx_vtkimagedata.html#getscalartypemax)")
    ADD_CLASS_METHOD(GetScalarSize,"int vtkImageData::GetScalarSize()  (http://docs.wxwidgets.org/stable/wx_vtkimagedata.html#getscalarsize)")
    ADD_CLASS_METHOD(GetIncrements_1,"vtkIdType * vtkImageData::GetIncrements()  (http://docs.wxwidgets.org/stable/wx_vtkimagedata.html#getincrements)")
    ADD_CLASS_METHOD(GetIncrements,"vtkImageData::GetIncrements()  (http://docs.wxwidgets.org/stable/wx_vtkimagedata.html#getincrements)")
    ADD_CLASS_METHOD(GetIncrements_2,"void vtkImageData::GetIncrements(vtkIdType & incX, vtkIdType & incY, vtkIdType & incZ)  (http://docs.wxwidgets.org/stable/wx_vtkimagedata.html#getincrements)")
    ADD_CLASS_METHOD(GetIncrements_3,"void vtkImageData::GetIncrements(vtkIdType * inc)  (http://docs.wxwidgets.org/stable/wx_vtkimagedata.html#getincrements)")
    ADD_CLASS_METHOD(GetContinuousIncrements,"void vtkImageData::GetContinuousIncrements(int * extent, vtkIdType & incX, vtkIdType & incY, vtkIdType & incZ)  (http://docs.wxwidgets.org/stable/wx_vtkimagedata.html#getcontinuousincrements)")
    ADD_CLASS_METHOD(GetScalarPointerForExtent,"void * vtkImageData::GetScalarPointerForExtent(int * extent)  (http://docs.wxwidgets.org/stable/wx_vtkimagedata.html#getscalarpointerforextent)")
    ADD_CLASS_METHOD(GetScalarPointer_1,"void * vtkImageData::GetScalarPointer(int * coordinates)  (http://docs.wxwidgets.org/stable/wx_vtkimagedata.html#getscalarpointer)")
    ADD_CLASS_METHOD(GetScalarPointer,"vtkImageData::GetScalarPointer()  (http://docs.wxwidgets.org/stable/wx_vtkimagedata.html#getscalarpointer)")
    ADD_CLASS_METHOD(GetScalarPointer_2,"void * vtkImageData::GetScalarPointer(int x, int y, int z)  (http://docs.wxwidgets.org/stable/wx_vtkimagedata.html#getscalarpointer)")
    ADD_CLASS_METHOD(GetScalarPointer_3,"void * vtkImageData::GetScalarPointer()  (http://docs.wxwidgets.org/stable/wx_vtkimagedata.html#getscalarpointer)")
    ADD_CLASS_METHOD(GetScalarComponentAsFloat,"float vtkImageData::GetScalarComponentAsFloat(int x, int y, int z, int component)  (http://docs.wxwidgets.org/stable/wx_vtkimagedata.html#getscalarcomponentasfloat)")
    ADD_CLASS_METHOD(SetScalarComponentFromFloat,"void vtkImageData::SetScalarComponentFromFloat(int x, int y, int z, int component, float v)  (http://docs.wxwidgets.org/stable/wx_vtkimagedata.html#setscalarcomponentfromfloat)")
    ADD_CLASS_METHOD(GetScalarComponentAsDouble,"double vtkImageData::GetScalarComponentAsDouble(int x, int y, int z, int component)  (http://docs.wxwidgets.org/stable/wx_vtkimagedata.html#getscalarcomponentasdouble)")
    ADD_CLASS_METHOD(SetScalarComponentFromDouble,"void vtkImageData::SetScalarComponentFromDouble(int x, int y, int z, int component, double v)  (http://docs.wxwidgets.org/stable/wx_vtkimagedata.html#setscalarcomponentfromdouble)")
    ADD_CLASS_METHOD(AllocateScalars,"void vtkImageData::AllocateScalars()  (http://docs.wxwidgets.org/stable/wx_vtkimagedata.html#allocatescalars)")
    ADD_CLASS_METHOD(CopyAndCastFrom_1,"void vtkImageData::CopyAndCastFrom(vtkImageData * inData, int * extent)  (http://docs.wxwidgets.org/stable/wx_vtkimagedata.html#copyandcastfrom)")
    ADD_CLASS_METHOD(CopyAndCastFrom,"vtkImageData::CopyAndCastFrom()  (http://docs.wxwidgets.org/stable/wx_vtkimagedata.html#copyandcastfrom)")
    ADD_CLASS_METHOD(CopyAndCastFrom_2,"void vtkImageData::CopyAndCastFrom(vtkImageData * inData, int x0, int x1, int y0, int y1, int z0, int z1)  (http://docs.wxwidgets.org/stable/wx_vtkimagedata.html#copyandcastfrom)")
    ADD_CLASS_METHOD(Crop,"void vtkImageData::Crop()  (http://docs.wxwidgets.org/stable/wx_vtkimagedata.html#crop)")
    ADD_CLASS_METHOD(GetActualMemorySize,"long unsigned int vtkImageData::GetActualMemorySize()  (http://docs.wxwidgets.org/stable/wx_vtkimagedata.html#getactualmemorysize)")
    ADD_CLASS_METHOD(SetSpacing_1,"void vtkImageData::SetSpacing(double _arg1, double _arg2, double _arg3)  (http://docs.wxwidgets.org/stable/wx_vtkimagedata.html#setspacing)")
    ADD_CLASS_METHOD(SetSpacing,"vtkImageData::SetSpacing()  (http://docs.wxwidgets.org/stable/wx_vtkimagedata.html#setspacing)")
    ADD_CLASS_METHOD(SetSpacing_2,"void vtkImageData::SetSpacing(double * _arg)  (http://docs.wxwidgets.org/stable/wx_vtkimagedata.html#setspacing)")
    ADD_CLASS_METHOD(GetSpacing_1,"double * vtkImageData::GetSpacing()  (http://docs.wxwidgets.org/stable/wx_vtkimagedata.html#getspacing)")
    ADD_CLASS_METHOD(GetSpacing,"vtkImageData::GetSpacing()  (http://docs.wxwidgets.org/stable/wx_vtkimagedata.html#getspacing)")
    ADD_CLASS_METHOD(GetSpacing_2,"void vtkImageData::GetSpacing(double & _arg1, double & _arg2, double & _arg3)  (http://docs.wxwidgets.org/stable/wx_vtkimagedata.html#getspacing)")
    ADD_CLASS_METHOD(GetSpacing_3,"void vtkImageData::GetSpacing(double * _arg)  (http://docs.wxwidgets.org/stable/wx_vtkimagedata.html#getspacing)")
    ADD_CLASS_METHOD(SetOrigin_1,"void vtkImageData::SetOrigin(double _arg1, double _arg2, double _arg3)  (http://docs.wxwidgets.org/stable/wx_vtkimagedata.html#setorigin)")
    ADD_CLASS_METHOD(SetOrigin,"vtkImageData::SetOrigin()  (http://docs.wxwidgets.org/stable/wx_vtkimagedata.html#setorigin)")
    ADD_CLASS_METHOD(SetOrigin_2,"void vtkImageData::SetOrigin(double * _arg)  (http://docs.wxwidgets.org/stable/wx_vtkimagedata.html#setorigin)")
    ADD_CLASS_METHOD(GetOrigin_1,"double * vtkImageData::GetOrigin()  (http://docs.wxwidgets.org/stable/wx_vtkimagedata.html#getorigin)")
    ADD_CLASS_METHOD(GetOrigin,"vtkImageData::GetOrigin()  (http://docs.wxwidgets.org/stable/wx_vtkimagedata.html#getorigin)")
    ADD_CLASS_METHOD(GetOrigin_2,"void vtkImageData::GetOrigin(double & _arg1, double & _arg2, double & _arg3)  (http://docs.wxwidgets.org/stable/wx_vtkimagedata.html#getorigin)")
    ADD_CLASS_METHOD(GetOrigin_3,"void vtkImageData::GetOrigin(double * _arg)  (http://docs.wxwidgets.org/stable/wx_vtkimagedata.html#getorigin)")
    ADD_CLASS_METHOD(SetScalarTypeToFloat,"void vtkImageData::SetScalarTypeToFloat()  (http://docs.wxwidgets.org/stable/wx_vtkimagedata.html#setscalartypetofloat)")
    ADD_CLASS_METHOD(SetScalarTypeToDouble,"void vtkImageData::SetScalarTypeToDouble()  (http://docs.wxwidgets.org/stable/wx_vtkimagedata.html#setscalartypetodouble)")
    ADD_CLASS_METHOD(SetScalarTypeToInt,"void vtkImageData::SetScalarTypeToInt()  (http://docs.wxwidgets.org/stable/wx_vtkimagedata.html#setscalartypetoint)")
    ADD_CLASS_METHOD(SetScalarTypeToUnsignedInt,"void vtkImageData::SetScalarTypeToUnsignedInt()  (http://docs.wxwidgets.org/stable/wx_vtkimagedata.html#setscalartypetounsignedint)")
    ADD_CLASS_METHOD(SetScalarTypeToLong,"void vtkImageData::SetScalarTypeToLong()  (http://docs.wxwidgets.org/stable/wx_vtkimagedata.html#setscalartypetolong)")
    ADD_CLASS_METHOD(SetScalarTypeToUnsignedLong,"void vtkImageData::SetScalarTypeToUnsignedLong()  (http://docs.wxwidgets.org/stable/wx_vtkimagedata.html#setscalartypetounsignedlong)")
    ADD_CLASS_METHOD(SetScalarTypeToShort,"void vtkImageData::SetScalarTypeToShort()  (http://docs.wxwidgets.org/stable/wx_vtkimagedata.html#setscalartypetoshort)")
    ADD_CLASS_METHOD(SetScalarTypeToUnsignedShort,"void vtkImageData::SetScalarTypeToUnsignedShort()  (http://docs.wxwidgets.org/stable/wx_vtkimagedata.html#setscalartypetounsignedshort)")
    ADD_CLASS_METHOD(SetScalarTypeToUnsignedChar,"void vtkImageData::SetScalarTypeToUnsignedChar()  (http://docs.wxwidgets.org/stable/wx_vtkimagedata.html#setscalartypetounsignedchar)")
    ADD_CLASS_METHOD(SetScalarTypeToSignedChar,"void vtkImageData::SetScalarTypeToSignedChar()  (http://docs.wxwidgets.org/stable/wx_vtkimagedata.html#setscalartypetosignedchar)")
    ADD_CLASS_METHOD(SetScalarTypeToChar,"void vtkImageData::SetScalarTypeToChar()  (http://docs.wxwidgets.org/stable/wx_vtkimagedata.html#setscalartypetochar)")
    ADD_CLASS_METHOD(SetScalarType,"void vtkImageData::SetScalarType(int param0)  (http://docs.wxwidgets.org/stable/wx_vtkimagedata.html#setscalartype)")
    ADD_CLASS_METHOD(GetScalarType,"int vtkImageData::GetScalarType()  (http://docs.wxwidgets.org/stable/wx_vtkimagedata.html#getscalartype)")
    ADD_CLASS_METHOD(GetScalarTypeAsString,"char const * vtkImageData::GetScalarTypeAsString()  (http://docs.wxwidgets.org/stable/wx_vtkimagedata.html#getscalartypeasstring)")
    ADD_CLASS_METHOD(SetNumberOfScalarComponents,"void vtkImageData::SetNumberOfScalarComponents(int n)  (http://docs.wxwidgets.org/stable/wx_vtkimagedata.html#setnumberofscalarcomponents)")
    ADD_CLASS_METHOD(GetNumberOfScalarComponents,"int vtkImageData::GetNumberOfScalarComponents()  (http://docs.wxwidgets.org/stable/wx_vtkimagedata.html#getnumberofscalarcomponents)")
    ADD_CLASS_METHOD(CopyTypeSpecificInformation,"void vtkImageData::CopyTypeSpecificInformation(vtkDataObject * image)  (http://docs.wxwidgets.org/stable/wx_vtkimagedata.html#copytypespecificinformation)")
/* The following types are missing: vtkInformation, vtkInformation, vtkInformation
    ADD_CLASS_METHOD(CopyInformationToPipeline,"void vtkImageData::CopyInformationToPipeline(vtkInformation * request, vtkInformation * input, vtkInformation * output, int forceCopy)  (http://docs.wxwidgets.org/stable/wx_vtkimagedata.html#copyinformationtopipeline)")
*/
/* The following types are missing: vtkInformation
    ADD_CLASS_METHOD(CopyInformationFromPipeline,"void vtkImageData::CopyInformationFromPipeline(vtkInformation * request)  (http://docs.wxwidgets.org/stable/wx_vtkimagedata.html#copyinformationfrompipeline)")
*/
    ADD_CLASS_METHOD(PrepareForNewData,"void vtkImageData::PrepareForNewData()  (http://docs.wxwidgets.org/stable/wx_vtkimagedata.html#preparefornewdata)")
    ADD_CLASS_METHOD(ShallowCopy,"void vtkImageData::ShallowCopy(vtkDataObject * src)  (http://docs.wxwidgets.org/stable/wx_vtkimagedata.html#shallowcopy)")
    ADD_CLASS_METHOD(DeepCopy,"void vtkImageData::DeepCopy(vtkDataObject * src)  (http://docs.wxwidgets.org/stable/wx_vtkimagedata.html#deepcopy)")
    ADD_CLASS_METHOD(GetArrayPointerForExtent,"void * vtkImageData::GetArrayPointerForExtent(vtkDataArray * array, int * extent)  (http://docs.wxwidgets.org/stable/wx_vtkimagedata.html#getarraypointerforextent)")
    ADD_CLASS_METHOD(GetArrayPointer,"void * vtkImageData::GetArrayPointer(vtkDataArray * array, int * coordinates)  (http://docs.wxwidgets.org/stable/wx_vtkimagedata.html#getarraypointer)")
    ADD_CLASS_METHOD(GetArrayIncrements,"void vtkImageData::GetArrayIncrements(vtkDataArray * array, vtkIdType * increments)  (http://docs.wxwidgets.org/stable/wx_vtkimagedata.html#getarrayincrements)")
    ADD_CLASS_METHOD(ComputeInternalExtent,"void vtkImageData::ComputeInternalExtent(int * intExt, int * tgtExt, int * bnds)  (http://docs.wxwidgets.org/stable/wx_vtkimagedata.html#computeinternalextent)")
    ADD_CLASS_METHOD(GetExtentType,"int vtkImageData::GetExtentType()  (http://docs.wxwidgets.org/stable/wx_vtkimagedata.html#getextenttype)")





    void AddMethods(WrapClass<vtkImageData>::ptr this_ptr );
    

};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClassvtkImageData_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_vtkImageData_h
