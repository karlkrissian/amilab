/**
 * C++ Interface: wrap_vtkDataObject
 *
 * Description: wrapping vtkDataObject
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_vtkDataObject_h_
#define _wrap_vtkDataObject_h_

/*
#include "Variable.hpp"
#include "ami_object.h"
*/
#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "paramlist.h"

#include "vtkDataObject.h"

// include what is needed for inheritence and for types ...

#include "wrap_vtkObject.h"


#ifndef vtkDataObject_declared
  #define vtkDataObject_declared
  AMI_DECLARE_TYPE(vtkDataObject);
#endif

// TODO: check for inheritence ...
class WrapClass_vtkDataObject : public WrapClass<vtkDataObject>
    , public   WrapClass_vtkObject
{
  DEFINE_CLASS(WrapClass_vtkDataObject);

  protected:
    typedef WrapClass<vtkDataObject>::ptr _parentclass_ptr;
    typedef vtkDataObject ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<vtkDataObject>& GetObj() const { return WrapClass<vtkDataObject>::GetObj(); }

    /// Constructor
    WrapClass_vtkDataObject(boost::shared_ptr<vtkDataObject > si): 
    WrapClass<vtkDataObject>(si)
    , WrapClass_vtkObject(si)
    {}

    /// Destructor
    ~WrapClass_vtkDataObject()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( vtkDataObject*);

    // Static methods
    
    ADD_CLASS_STATICMETHOD(New,"vtkDataObject * vtkDataObject::New() (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#new).");
    ADD_CLASS_STATICMETHOD(IsTypeOf,"int vtkDataObject::IsTypeOf(char const * type) (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#istypeof).");
    ADD_CLASS_STATICMETHOD(SafeDownCast,"vtkDataObject * vtkDataObject::SafeDownCast(vtkObjectBase * o) (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#safedowncast).");
    ADD_CLASS_STATICMETHOD(SetGlobalReleaseDataFlag,"void vtkDataObject::SetGlobalReleaseDataFlag(int val) (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#setglobalreleasedataflag).");
    ADD_CLASS_STATICMETHOD(GetGlobalReleaseDataFlag,"int vtkDataObject::GetGlobalReleaseDataFlag() (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#getglobalreleasedataflag).");
    /* The following types are missing: vtkInformation, vtkInformation
    ADD_CLASS_STATICMETHOD(GetActiveFieldInformation,"vtkInformation * vtkDataObject::GetActiveFieldInformation(vtkInformation * info, int fieldAssociation, int attributeType) (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#getactivefieldinformation).");
    */
    /* The following types are missing: vtkInformation, vtkInformation
    ADD_CLASS_STATICMETHOD(GetNamedFieldInformation,"vtkInformation * vtkDataObject::GetNamedFieldInformation(vtkInformation * info, int fieldAssociation, char const * name) (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#getnamedfieldinformation).");
    */
    /* The following types are missing: vtkInformation
    ADD_CLASS_STATICMETHOD(RemoveNamedFieldInformation,"void vtkDataObject::RemoveNamedFieldInformation(vtkInformation * info, int fieldAssociation, char const * name) (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#removenamedfieldinformation).");
    */
    /* The following types are missing: vtkInformation, vtkInformation
    ADD_CLASS_STATICMETHOD(SetActiveAttribute,"vtkInformation * vtkDataObject::SetActiveAttribute(vtkInformation * info, int fieldAssociation, char const * attributeName, int attributeType) (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#setactiveattribute).");
    */
    /* The following types are missing: vtkInformation
    ADD_CLASS_STATICMETHOD(SetActiveAttributeInfo,"void vtkDataObject::SetActiveAttributeInfo(vtkInformation * info, int fieldAssociation, int attributeType, char const * name, int arrayType, int numComponents, int numTuples) (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#setactiveattributeinfo).");
    */
    /* The following types are missing: vtkInformation
    ADD_CLASS_STATICMETHOD(SetPointDataActiveScalarInfo,"void vtkDataObject::SetPointDataActiveScalarInfo(vtkInformation * info, int arrayType, int numComponents) (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#setpointdataactivescalarinfo).");
    */
    ADD_CLASS_STATICMETHOD(GetAssociationTypeAsString,"char const * vtkDataObject::GetAssociationTypeAsString(int associationType) (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#getassociationtypeasstring).");
    /* The following types are missing: vtkInformationStringKey
    ADD_CLASS_STATICMETHOD(DATA_TYPE_NAME,"vtkInformationStringKey * vtkDataObject::DATA_TYPE_NAME() (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#data_type_name).");
    */
    /* The following types are missing: vtkInformationDataObjectKey
    ADD_CLASS_STATICMETHOD(DATA_OBJECT,"vtkInformationDataObjectKey * vtkDataObject::DATA_OBJECT() (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#data_object).");
    */
    /* The following types are missing: vtkInformationIntegerKey
    ADD_CLASS_STATICMETHOD(DATA_EXTENT_TYPE,"vtkInformationIntegerKey * vtkDataObject::DATA_EXTENT_TYPE() (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#data_extent_type).");
    */
    /* The following types are missing: vtkInformationIntegerPointerKey
    ADD_CLASS_STATICMETHOD(DATA_EXTENT,"vtkInformationIntegerPointerKey * vtkDataObject::DATA_EXTENT() (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#data_extent).");
    */
    /* The following types are missing: vtkInformationIntegerKey
    ADD_CLASS_STATICMETHOD(DATA_PIECE_NUMBER,"vtkInformationIntegerKey * vtkDataObject::DATA_PIECE_NUMBER() (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#data_piece_number).");
    */
    /* The following types are missing: vtkInformationIntegerKey
    ADD_CLASS_STATICMETHOD(DATA_NUMBER_OF_PIECES,"vtkInformationIntegerKey * vtkDataObject::DATA_NUMBER_OF_PIECES() (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#data_number_of_pieces).");
    */
    /* The following types are missing: vtkInformationIntegerKey
    ADD_CLASS_STATICMETHOD(DATA_NUMBER_OF_GHOST_LEVELS,"vtkInformationIntegerKey * vtkDataObject::DATA_NUMBER_OF_GHOST_LEVELS() (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#data_number_of_ghost_levels).");
    */
    /* The following types are missing: vtkInformationDoubleKey
    ADD_CLASS_STATICMETHOD(DATA_RESOLUTION,"vtkInformationDoubleKey * vtkDataObject::DATA_RESOLUTION() (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#data_resolution).");
    */
    /* The following types are missing: vtkInformationDoubleVectorKey
    ADD_CLASS_STATICMETHOD(DATA_TIME_STEPS,"vtkInformationDoubleVectorKey * vtkDataObject::DATA_TIME_STEPS() (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#data_time_steps).");
    */
    /* The following types are missing: vtkInformationInformationVectorKey
    ADD_CLASS_STATICMETHOD(POINT_DATA_VECTOR,"vtkInformationInformationVectorKey * vtkDataObject::POINT_DATA_VECTOR() (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#point_data_vector).");
    */
    /* The following types are missing: vtkInformationInformationVectorKey
    ADD_CLASS_STATICMETHOD(CELL_DATA_VECTOR,"vtkInformationInformationVectorKey * vtkDataObject::CELL_DATA_VECTOR() (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#cell_data_vector).");
    */
    /* The following types are missing: vtkInformationInformationVectorKey
    ADD_CLASS_STATICMETHOD(VERTEX_DATA_VECTOR,"vtkInformationInformationVectorKey * vtkDataObject::VERTEX_DATA_VECTOR() (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#vertex_data_vector).");
    */
    /* The following types are missing: vtkInformationInformationVectorKey
    ADD_CLASS_STATICMETHOD(EDGE_DATA_VECTOR,"vtkInformationInformationVectorKey * vtkDataObject::EDGE_DATA_VECTOR() (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#edge_data_vector).");
    */
    /* The following types are missing: vtkInformationIntegerKey
    ADD_CLASS_STATICMETHOD(FIELD_ARRAY_TYPE,"vtkInformationIntegerKey * vtkDataObject::FIELD_ARRAY_TYPE() (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#field_array_type).");
    */
    /* The following types are missing: vtkInformationIntegerKey
    ADD_CLASS_STATICMETHOD(FIELD_ASSOCIATION,"vtkInformationIntegerKey * vtkDataObject::FIELD_ASSOCIATION() (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#field_association).");
    */
    /* The following types are missing: vtkInformationIntegerKey
    ADD_CLASS_STATICMETHOD(FIELD_ATTRIBUTE_TYPE,"vtkInformationIntegerKey * vtkDataObject::FIELD_ATTRIBUTE_TYPE() (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#field_attribute_type).");
    */
    /* The following types are missing: vtkInformationIntegerKey
    ADD_CLASS_STATICMETHOD(FIELD_ACTIVE_ATTRIBUTE,"vtkInformationIntegerKey * vtkDataObject::FIELD_ACTIVE_ATTRIBUTE() (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#field_active_attribute).");
    */
    /* The following types are missing: vtkInformationIntegerKey
    ADD_CLASS_STATICMETHOD(FIELD_NUMBER_OF_COMPONENTS,"vtkInformationIntegerKey * vtkDataObject::FIELD_NUMBER_OF_COMPONENTS() (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#field_number_of_components).");
    */
    /* The following types are missing: vtkInformationIntegerKey
    ADD_CLASS_STATICMETHOD(FIELD_NUMBER_OF_TUPLES,"vtkInformationIntegerKey * vtkDataObject::FIELD_NUMBER_OF_TUPLES() (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#field_number_of_tuples).");
    */
    /* The following types are missing: vtkInformationIntegerKey
    ADD_CLASS_STATICMETHOD(FIELD_OPERATION,"vtkInformationIntegerKey * vtkDataObject::FIELD_OPERATION() (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#field_operation).");
    */
    /* The following types are missing: vtkInformationDoubleVectorKey
    ADD_CLASS_STATICMETHOD(FIELD_RANGE,"vtkInformationDoubleVectorKey * vtkDataObject::FIELD_RANGE() (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#field_range).");
    */
    /* The following types are missing: vtkInformationDoubleVectorKey
    ADD_CLASS_STATICMETHOD(PIECE_FIELD_RANGE,"vtkInformationDoubleVectorKey * vtkDataObject::PIECE_FIELD_RANGE() (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#piece_field_range).");
    */
    /* The following types are missing: vtkInformationIntegerVectorKey
    ADD_CLASS_STATICMETHOD(PIECE_EXTENT,"vtkInformationIntegerVectorKey * vtkDataObject::PIECE_EXTENT() (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#piece_extent).");
    */
    /* The following types are missing: vtkInformationStringKey
    ADD_CLASS_STATICMETHOD(FIELD_NAME,"vtkInformationStringKey * vtkDataObject::FIELD_NAME() (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#field_name).");
    */
    /* The following types are missing: vtkInformationDoubleVectorKey
    ADD_CLASS_STATICMETHOD(ORIGIN,"vtkInformationDoubleVectorKey * vtkDataObject::ORIGIN() (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#origin).");
    */
    /* The following types are missing: vtkInformationDoubleVectorKey
    ADD_CLASS_STATICMETHOD(SPACING,"vtkInformationDoubleVectorKey * vtkDataObject::SPACING() (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#spacing).");
    */
    /* The following types are missing: vtkInformationIntegerKey
    ADD_CLASS_STATICMETHOD(DATA_GEOMETRY_UNMODIFIED,"vtkInformationIntegerKey * vtkDataObject::DATA_GEOMETRY_UNMODIFIED() (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#data_geometry_unmodified).");
    */
    /* The following types are missing: vtkInformationDataObjectKey
    ADD_CLASS_STATICMETHOD(SIL,"vtkInformationDataObjectKey * vtkDataObject::SIL() (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#sil).");
    */
    /* The following types are missing: vtkInformation
    ADD_CLASS_STATICMETHOD(GetData_1,"vtkDataObject * vtkDataObject::GetData(vtkInformation * info) (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#getdata).");
    */
    ADD_CLASS_STATICMETHOD(GetData,"vtkDataObject::GetData() (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#getdata).");
    /* The following types are missing: vtkInformationVector
    ADD_CLASS_STATICMETHOD(GetData_2,"vtkDataObject * vtkDataObject::GetData(vtkInformationVector * v, int i = 0) (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#getdata).");
    */



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(IsA,"int vtkDataObject::IsA(char const * type)  (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#isa)")
    ADD_CLASS_METHOD(NewInstance,"vtkDataObject * vtkDataObject::NewInstance()  (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#newinstance)")
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
    ADD_CLASS_METHOD(PrintSelf,"void vtkDataObject::PrintSelf(ostream & os, vtkIndent indent)  (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#printself)")
*/
/* The following types are missing: vtkSource
    ADD_CLASS_METHOD(GetSource,"vtkSource * vtkDataObject::GetSource()  (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#getsource)")
*/
/* The following types are missing: vtkSource
    ADD_CLASS_METHOD(SetSource,"void vtkDataObject::SetSource(vtkSource * s)  (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#setsource)")
*/
/* The following types are missing: vtkInformation
    ADD_CLASS_METHOD(GetInformation,"vtkInformation * vtkDataObject::GetInformation()  (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#getinformation)")
*/
/* The following types are missing: vtkInformation
    ADD_CLASS_METHOD(SetInformation,"void vtkDataObject::SetInformation(vtkInformation * param0)  (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#setinformation)")
*/
/* The following types are missing: vtkInformation
    ADD_CLASS_METHOD(GetPipelineInformation,"vtkInformation * vtkDataObject::GetPipelineInformation()  (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#getpipelineinformation)")
*/
/* The following types are missing: vtkInformation
    ADD_CLASS_METHOD(SetPipelineInformation,"void vtkDataObject::SetPipelineInformation(vtkInformation * param0)  (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#setpipelineinformation)")
*/
/* The following types are missing: vtkAlgorithmOutput
    ADD_CLASS_METHOD(GetProducerPort,"vtkAlgorithmOutput * vtkDataObject::GetProducerPort()  (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#getproducerport)")
*/
    ADD_CLASS_METHOD(GetMTime,"long unsigned int vtkDataObject::GetMTime()  (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#getmtime)")
    ADD_CLASS_METHOD(Initialize,"void vtkDataObject::Initialize()  (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#initialize)")
    ADD_CLASS_METHOD(ReleaseData,"void vtkDataObject::ReleaseData()  (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#releasedata)")
    ADD_CLASS_METHOD(ShouldIReleaseData,"int vtkDataObject::ShouldIReleaseData()  (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#shouldireleasedata)")
    ADD_CLASS_METHOD(GetDataReleased,"int vtkDataObject::GetDataReleased()  (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#getdatareleased)")
    ADD_CLASS_METHOD(SetReleaseDataFlag,"void vtkDataObject::SetReleaseDataFlag(int param0)  (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#setreleasedataflag)")
    ADD_CLASS_METHOD(GetReleaseDataFlag,"int vtkDataObject::GetReleaseDataFlag()  (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#getreleasedataflag)")
    ADD_CLASS_METHOD(ReleaseDataFlagOn,"void vtkDataObject::ReleaseDataFlagOn()  (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#releasedataflagon)")
    ADD_CLASS_METHOD(ReleaseDataFlagOff,"void vtkDataObject::ReleaseDataFlagOff()  (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#releasedataflagoff)")
    ADD_CLASS_METHOD(GlobalReleaseDataFlagOn,"void vtkDataObject::GlobalReleaseDataFlagOn()  (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#globalreleasedataflagon)")
    ADD_CLASS_METHOD(GlobalReleaseDataFlagOff,"void vtkDataObject::GlobalReleaseDataFlagOff()  (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#globalreleasedataflagoff)")
/* The following types are missing: vtkFieldData
    ADD_CLASS_METHOD(SetFieldData,"void vtkDataObject::SetFieldData(vtkFieldData * param0)  (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#setfielddata)")
*/
/* The following types are missing: vtkFieldData
    ADD_CLASS_METHOD(GetFieldData,"vtkFieldData * vtkDataObject::GetFieldData()  (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#getfielddata)")
*/
    ADD_CLASS_METHOD(Register,"void vtkDataObject::Register(vtkObjectBase * o)  (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#register)")
    ADD_CLASS_METHOD(UnRegister,"void vtkDataObject::UnRegister(vtkObjectBase * o)  (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#unregister)")
    ADD_CLASS_METHOD(Update,"void vtkDataObject::Update()  (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#update)")
    ADD_CLASS_METHOD(UpdateInformation,"void vtkDataObject::UpdateInformation()  (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#updateinformation)")
    ADD_CLASS_METHOD(PropagateUpdateExtent,"void vtkDataObject::PropagateUpdateExtent()  (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#propagateupdateextent)")
    ADD_CLASS_METHOD(TriggerAsynchronousUpdate,"void vtkDataObject::TriggerAsynchronousUpdate()  (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#triggerasynchronousupdate)")
    ADD_CLASS_METHOD(UpdateData,"void vtkDataObject::UpdateData()  (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#updatedata)")
    ADD_CLASS_METHOD(GetEstimatedMemorySize,"long unsigned int vtkDataObject::GetEstimatedMemorySize()  (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#getestimatedmemorysize)")
    ADD_CLASS_METHOD(SetUpdateExtent_1,"void vtkDataObject::SetUpdateExtent(int piece, int numPieces, int ghostLevel)  (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#setupdateextent)")
    ADD_CLASS_METHOD(SetUpdateExtent,"vtkDataObject::SetUpdateExtent()  (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#setupdateextent)")
    ADD_CLASS_METHOD(SetUpdateExtent_2,"void vtkDataObject::SetUpdateExtent(int piece, int numPieces)  (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#setupdateextent)")
    ADD_CLASS_METHOD(SetUpdateExtent_3,"void vtkDataObject::SetUpdateExtent(int x0, int x1, int y0, int y1, int z0, int z1)  (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#setupdateextent)")
    ADD_CLASS_METHOD(SetUpdateExtent_4,"void vtkDataObject::SetUpdateExtent(int * extent)  (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#setupdateextent)")
    ADD_CLASS_METHOD(GetUpdateExtent_1,"int * vtkDataObject::GetUpdateExtent()  (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#getupdateextent)")
    ADD_CLASS_METHOD(GetUpdateExtent,"vtkDataObject::GetUpdateExtent()  (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#getupdateextent)")
    ADD_CLASS_METHOD(GetUpdateExtent_2,"void vtkDataObject::GetUpdateExtent(int & x0, int & x1, int & y0, int & y1, int & z0, int & z1)  (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#getupdateextent)")
    ADD_CLASS_METHOD(GetUpdateExtent_3,"void vtkDataObject::GetUpdateExtent(int * extent)  (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#getupdateextent)")
    ADD_CLASS_METHOD(GetDataObjectType,"int vtkDataObject::GetDataObjectType()  (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#getdataobjecttype)")
    ADD_CLASS_METHOD(GetUpdateTime,"long unsigned int vtkDataObject::GetUpdateTime()  (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#getupdatetime)")
    ADD_CLASS_METHOD(SetUpdateExtentToWholeExtent,"void vtkDataObject::SetUpdateExtentToWholeExtent()  (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#setupdateextenttowholeextent)")
    ADD_CLASS_METHOD(GetPipelineMTime,"long unsigned int vtkDataObject::GetPipelineMTime()  (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#getpipelinemtime)")
    ADD_CLASS_METHOD(GetActualMemorySize,"long unsigned int vtkDataObject::GetActualMemorySize()  (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#getactualmemorysize)")
    ADD_CLASS_METHOD(CopyInformation,"void vtkDataObject::CopyInformation(vtkDataObject * data)  (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#copyinformation)")
    ADD_CLASS_METHOD(CopyTypeSpecificInformation,"void vtkDataObject::CopyTypeSpecificInformation(vtkDataObject * data)  (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#copytypespecificinformation)")
    ADD_CLASS_METHOD(SetUpdatePiece,"void vtkDataObject::SetUpdatePiece(int piece)  (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#setupdatepiece)")
    ADD_CLASS_METHOD(SetUpdateNumberOfPieces,"void vtkDataObject::SetUpdateNumberOfPieces(int num)  (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#setupdatenumberofpieces)")
    ADD_CLASS_METHOD(GetUpdatePiece,"int vtkDataObject::GetUpdatePiece()  (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#getupdatepiece)")
    ADD_CLASS_METHOD(GetUpdateNumberOfPieces,"int vtkDataObject::GetUpdateNumberOfPieces()  (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#getupdatenumberofpieces)")
    ADD_CLASS_METHOD(SetUpdateGhostLevel,"void vtkDataObject::SetUpdateGhostLevel(int level)  (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#setupdateghostlevel)")
    ADD_CLASS_METHOD(GetUpdateGhostLevel,"int vtkDataObject::GetUpdateGhostLevel()  (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#getupdateghostlevel)")
    ADD_CLASS_METHOD(SetRequestExactExtent,"void vtkDataObject::SetRequestExactExtent(int flag)  (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#setrequestexactextent)")
    ADD_CLASS_METHOD(GetRequestExactExtent,"int vtkDataObject::GetRequestExactExtent()  (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#getrequestexactextent)")
    ADD_CLASS_METHOD(RequestExactExtentOn,"void vtkDataObject::RequestExactExtentOn()  (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#requestexactextenton)")
    ADD_CLASS_METHOD(RequestExactExtentOff,"void vtkDataObject::RequestExactExtentOff()  (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#requestexactextentoff)")
    ADD_CLASS_METHOD(SetWholeExtent_1,"void vtkDataObject::SetWholeExtent(int x0, int x1, int y0, int y1, int z0, int z1)  (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#setwholeextent)")
    ADD_CLASS_METHOD(SetWholeExtent,"vtkDataObject::SetWholeExtent()  (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#setwholeextent)")
    ADD_CLASS_METHOD(SetWholeExtent_2,"void vtkDataObject::SetWholeExtent(int * extent)  (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#setwholeextent)")
    ADD_CLASS_METHOD(GetWholeExtent_1,"int * vtkDataObject::GetWholeExtent()  (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#getwholeextent)")
    ADD_CLASS_METHOD(GetWholeExtent,"vtkDataObject::GetWholeExtent()  (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#getwholeextent)")
    ADD_CLASS_METHOD(GetWholeExtent_2,"void vtkDataObject::GetWholeExtent(int & x0, int & x1, int & y0, int & y1, int & z0, int & z1)  (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#getwholeextent)")
    ADD_CLASS_METHOD(GetWholeExtent_3,"void vtkDataObject::GetWholeExtent(int * extent)  (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#getwholeextent)")
    ADD_CLASS_METHOD(SetWholeBoundingBox_1,"void vtkDataObject::SetWholeBoundingBox(double x0, double x1, double y0, double y1, double z0, double z1)  (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#setwholeboundingbox)")
    ADD_CLASS_METHOD(SetWholeBoundingBox,"vtkDataObject::SetWholeBoundingBox()  (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#setwholeboundingbox)")
    ADD_CLASS_METHOD(SetWholeBoundingBox_2,"void vtkDataObject::SetWholeBoundingBox(double * bb)  (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#setwholeboundingbox)")
    ADD_CLASS_METHOD(GetWholeBoundingBox_1,"double * vtkDataObject::GetWholeBoundingBox()  (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#getwholeboundingbox)")
    ADD_CLASS_METHOD(GetWholeBoundingBox,"vtkDataObject::GetWholeBoundingBox()  (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#getwholeboundingbox)")
    ADD_CLASS_METHOD(GetWholeBoundingBox_2,"void vtkDataObject::GetWholeBoundingBox(double & x0, double & x1, double & y0, double & y1, double & z0, double & z1)  (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#getwholeboundingbox)")
    ADD_CLASS_METHOD(GetWholeBoundingBox_3,"void vtkDataObject::GetWholeBoundingBox(double * extent)  (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#getwholeboundingbox)")
    ADD_CLASS_METHOD(SetMaximumNumberOfPieces,"void vtkDataObject::SetMaximumNumberOfPieces(int param0)  (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#setmaximumnumberofpieces)")
    ADD_CLASS_METHOD(GetMaximumNumberOfPieces,"int vtkDataObject::GetMaximumNumberOfPieces()  (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#getmaximumnumberofpieces)")
/* The following types are missing: vtkInformation, vtkInformation, vtkInformation
    ADD_CLASS_METHOD(CopyInformationToPipeline_1,"void vtkDataObject::CopyInformationToPipeline(vtkInformation * request, vtkInformation * input, vtkInformation * output, int forceCopy)  (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#copyinformationtopipeline)")
*/
    ADD_CLASS_METHOD(CopyInformationToPipeline,"vtkDataObject::CopyInformationToPipeline()  (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#copyinformationtopipeline)")
/* The following types are missing: vtkInformation, vtkInformation
    ADD_CLASS_METHOD(CopyInformationToPipeline_2,"void vtkDataObject::CopyInformationToPipeline(vtkInformation * request, vtkInformation * input)  (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#copyinformationtopipeline)")
*/
/* The following types are missing: vtkInformation
    ADD_CLASS_METHOD(CopyInformationFromPipeline,"void vtkDataObject::CopyInformationFromPipeline(vtkInformation * request)  (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#copyinformationfrompipeline)")
*/
    ADD_CLASS_METHOD(DataHasBeenGenerated,"void vtkDataObject::DataHasBeenGenerated()  (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#datahasbeengenerated)")
    ADD_CLASS_METHOD(PrepareForNewData,"void vtkDataObject::PrepareForNewData()  (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#preparefornewdata)")
    ADD_CLASS_METHOD(ShallowCopy,"void vtkDataObject::ShallowCopy(vtkDataObject * src)  (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#shallowcopy)")
    ADD_CLASS_METHOD(DeepCopy,"void vtkDataObject::DeepCopy(vtkDataObject * src)  (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#deepcopy)")
/* The following types are missing: vtkExtentTranslator
    ADD_CLASS_METHOD(SetExtentTranslator,"void vtkDataObject::SetExtentTranslator(vtkExtentTranslator * translator)  (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#setextenttranslator)")
*/
/* The following types are missing: vtkExtentTranslator
    ADD_CLASS_METHOD(GetExtentTranslator,"vtkExtentTranslator * vtkDataObject::GetExtentTranslator()  (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#getextenttranslator)")
*/
    ADD_CLASS_METHOD(GetExtentType,"int vtkDataObject::GetExtentType()  (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#getextenttype)")
    ADD_CLASS_METHOD(Crop,"void vtkDataObject::Crop()  (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#crop)")
/* The following types are missing: vtkDataSetAttributes
    ADD_CLASS_METHOD(GetAttributes,"vtkDataSetAttributes * vtkDataObject::GetAttributes(int type)  (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#getattributes)")
*/
/* The following types are missing: vtkFieldData
    ADD_CLASS_METHOD(GetAttributesAsFieldData,"vtkFieldData * vtkDataObject::GetAttributesAsFieldData(int type)  (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#getattributesasfielddata)")
*/
    ADD_CLASS_METHOD(GetAttributeTypeForArray,"int vtkDataObject::GetAttributeTypeForArray(vtkAbstractArray * arr)  (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#getattributetypeforarray)")
    ADD_CLASS_METHOD(GetNumberOfElements,"vtkIdType vtkDataObject::GetNumberOfElements(int type)  (http://docs.wxwidgets.org/stable/wx_vtkdataobject.html#getnumberofelements)")





    void AddMethods(WrapClass<vtkDataObject>::ptr this_ptr );
    

};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClassvtkDataObject_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_vtkDataObject_h
