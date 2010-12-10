/**
 * C++ Interface: wrap_vtkAlgorithm
 *
 * Description: wrapping vtkAlgorithm
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_vtkAlgorithm_h_
#define _wrap_vtkAlgorithm_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "vtkAlgorithm.h"

// include what is needed for inheritence and for types ...

#include "wrap_vtkObject.h"



AMI_DECLARE_TYPE(vtkAlgorithm);

// TODO: check for inheritence ...
class WrapClass_vtkAlgorithm : public WrapClass<vtkAlgorithm>
    , public   WrapClass_vtkObject
{
  DEFINE_CLASS(WrapClass_vtkAlgorithm);

  protected:
    typedef WrapClass<vtkAlgorithm>::ptr _parentclass_ptr;
    typedef vtkAlgorithm ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<vtkAlgorithm>& GetObj() const { return WrapClass<vtkAlgorithm>::GetObj(); }

    /// Constructor
    WrapClass_vtkAlgorithm(boost::shared_ptr<vtkAlgorithm > si): 
    WrapClass<vtkAlgorithm>(si)
    , WrapClass_vtkObject(si)
    {}

    /// Destructor
    ~WrapClass_vtkAlgorithm()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( vtkAlgorithm*);

    // Static methods
    
    ADD_CLASS_STATICMETHOD(New,"vtkAlgorithm * vtkAlgorithm::New() (http://docs.wxwidgets.org/stable/wx_vtkalgorithm.html#new).");
    ADD_CLASS_STATICMETHOD(IsTypeOf,"int vtkAlgorithm::IsTypeOf(char const * type) (http://docs.wxwidgets.org/stable/wx_vtkalgorithm.html#istypeof).");
    ADD_CLASS_STATICMETHOD(SafeDownCast,"vtkAlgorithm * vtkAlgorithm::SafeDownCast(vtkObjectBase * o) (http://docs.wxwidgets.org/stable/wx_vtkalgorithm.html#safedowncast).");
    /* The following types are missing: vtkInformationIntegerKey
    ADD_CLASS_STATICMETHOD(INPUT_IS_OPTIONAL,"vtkInformationIntegerKey * vtkAlgorithm::INPUT_IS_OPTIONAL() (http://docs.wxwidgets.org/stable/wx_vtkalgorithm.html#input_is_optional).");
    */
    /* The following types are missing: vtkInformationIntegerKey
    ADD_CLASS_STATICMETHOD(INPUT_IS_REPEATABLE,"vtkInformationIntegerKey * vtkAlgorithm::INPUT_IS_REPEATABLE() (http://docs.wxwidgets.org/stable/wx_vtkalgorithm.html#input_is_repeatable).");
    */
    /* The following types are missing: vtkInformationInformationVectorKey
    ADD_CLASS_STATICMETHOD(INPUT_REQUIRED_FIELDS,"vtkInformationInformationVectorKey * vtkAlgorithm::INPUT_REQUIRED_FIELDS() (http://docs.wxwidgets.org/stable/wx_vtkalgorithm.html#input_required_fields).");
    */
    /* The following types are missing: vtkInformationStringVectorKey
    ADD_CLASS_STATICMETHOD(INPUT_REQUIRED_DATA_TYPE,"vtkInformationStringVectorKey * vtkAlgorithm::INPUT_REQUIRED_DATA_TYPE() (http://docs.wxwidgets.org/stable/wx_vtkalgorithm.html#input_required_data_type).");
    */
    /* The following types are missing: vtkInformationInformationVectorKey
    ADD_CLASS_STATICMETHOD(INPUT_ARRAYS_TO_PROCESS,"vtkInformationInformationVectorKey * vtkAlgorithm::INPUT_ARRAYS_TO_PROCESS() (http://docs.wxwidgets.org/stable/wx_vtkalgorithm.html#input_arrays_to_process).");
    */
    /* The following types are missing: vtkInformationIntegerKey
    ADD_CLASS_STATICMETHOD(INPUT_PORT,"vtkInformationIntegerKey * vtkAlgorithm::INPUT_PORT() (http://docs.wxwidgets.org/stable/wx_vtkalgorithm.html#input_port).");
    */
    /* The following types are missing: vtkInformationIntegerKey
    ADD_CLASS_STATICMETHOD(INPUT_CONNECTION,"vtkInformationIntegerKey * vtkAlgorithm::INPUT_CONNECTION() (http://docs.wxwidgets.org/stable/wx_vtkalgorithm.html#input_connection).");
    */
    /* The following types are missing: vtkExecutive
    ADD_CLASS_STATICMETHOD(SetDefaultExecutivePrototype,"void vtkAlgorithm::SetDefaultExecutivePrototype(vtkExecutive * proto) (http://docs.wxwidgets.org/stable/wx_vtkalgorithm.html#setdefaultexecutiveprototype).");
    */
    /* The following types are missing: vtkInformationIntegerKey
    ADD_CLASS_STATICMETHOD(PRESERVES_DATASET,"vtkInformationIntegerKey * vtkAlgorithm::PRESERVES_DATASET() (http://docs.wxwidgets.org/stable/wx_vtkalgorithm.html#preserves_dataset).");
    */
    /* The following types are missing: vtkInformationIntegerKey
    ADD_CLASS_STATICMETHOD(PRESERVES_GEOMETRY,"vtkInformationIntegerKey * vtkAlgorithm::PRESERVES_GEOMETRY() (http://docs.wxwidgets.org/stable/wx_vtkalgorithm.html#preserves_geometry).");
    */
    /* The following types are missing: vtkInformationIntegerKey
    ADD_CLASS_STATICMETHOD(PRESERVES_BOUNDS,"vtkInformationIntegerKey * vtkAlgorithm::PRESERVES_BOUNDS() (http://docs.wxwidgets.org/stable/wx_vtkalgorithm.html#preserves_bounds).");
    */
    /* The following types are missing: vtkInformationIntegerKey
    ADD_CLASS_STATICMETHOD(PRESERVES_TOPOLOGY,"vtkInformationIntegerKey * vtkAlgorithm::PRESERVES_TOPOLOGY() (http://docs.wxwidgets.org/stable/wx_vtkalgorithm.html#preserves_topology).");
    */
    /* The following types are missing: vtkInformationIntegerKey
    ADD_CLASS_STATICMETHOD(PRESERVES_ATTRIBUTES,"vtkInformationIntegerKey * vtkAlgorithm::PRESERVES_ATTRIBUTES() (http://docs.wxwidgets.org/stable/wx_vtkalgorithm.html#preserves_attributes).");
    */
    /* The following types are missing: vtkInformationIntegerKey
    ADD_CLASS_STATICMETHOD(PRESERVES_RANGES,"vtkInformationIntegerKey * vtkAlgorithm::PRESERVES_RANGES() (http://docs.wxwidgets.org/stable/wx_vtkalgorithm.html#preserves_ranges).");
    */



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(IsA,"int vtkAlgorithm::IsA(char const * type)  (http://docs.wxwidgets.org/stable/wx_vtkalgorithm.html#isa)")
    ADD_CLASS_METHOD(NewInstance,"vtkAlgorithm * vtkAlgorithm::NewInstance()  (http://docs.wxwidgets.org/stable/wx_vtkalgorithm.html#newinstance)")
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
    ADD_CLASS_METHOD(PrintSelf,"void vtkAlgorithm::PrintSelf(ostream & os, vtkIndent indent)  (http://docs.wxwidgets.org/stable/wx_vtkalgorithm.html#printself)")
*/
    ADD_CLASS_METHOD(HasExecutive,"int vtkAlgorithm::HasExecutive()  (http://docs.wxwidgets.org/stable/wx_vtkalgorithm.html#hasexecutive)")
/* The following types are missing: vtkExecutive
    ADD_CLASS_METHOD(GetExecutive,"vtkExecutive * vtkAlgorithm::GetExecutive()  (http://docs.wxwidgets.org/stable/wx_vtkalgorithm.html#getexecutive)")
*/
/* The following types are missing: vtkExecutive
    ADD_CLASS_METHOD(SetExecutive,"void vtkAlgorithm::SetExecutive(vtkExecutive * executive)  (http://docs.wxwidgets.org/stable/wx_vtkalgorithm.html#setexecutive)")
*/
/* The following types are missing: vtkInformation, vtkInformationVector * *, vtkInformationVector
    ADD_CLASS_METHOD(ProcessRequest,"int vtkAlgorithm::ProcessRequest(vtkInformation * request, vtkInformationVector * * inInfo, vtkInformationVector * outInfo)  (http://docs.wxwidgets.org/stable/wx_vtkalgorithm.html#processrequest)")
*/
/* The following types are missing: vtkInformation, vtkInformationVector * *, vtkInformationVector
    ADD_CLASS_METHOD(ComputePipelineMTime,"int vtkAlgorithm::ComputePipelineMTime(vtkInformation * request, vtkInformationVector * * inInfoVec, vtkInformationVector * outInfoVec, int requestFromOutputPort, long unsigned int * mtime)  (http://docs.wxwidgets.org/stable/wx_vtkalgorithm.html#computepipelinemtime)")
*/
/* The following types are missing: vtkInformation
    ADD_CLASS_METHOD(ModifyRequest,"int vtkAlgorithm::ModifyRequest(vtkInformation * request, int when)  (http://docs.wxwidgets.org/stable/wx_vtkalgorithm.html#modifyrequest)")
*/
/* The following types are missing: vtkInformation
    ADD_CLASS_METHOD(GetInputPortInformation,"vtkInformation * vtkAlgorithm::GetInputPortInformation(int port)  (http://docs.wxwidgets.org/stable/wx_vtkalgorithm.html#getinputportinformation)")
*/
/* The following types are missing: vtkInformation
    ADD_CLASS_METHOD(GetOutputPortInformation,"vtkInformation * vtkAlgorithm::GetOutputPortInformation(int port)  (http://docs.wxwidgets.org/stable/wx_vtkalgorithm.html#getoutputportinformation)")
*/
/* The following types are missing: vtkInformation
    ADD_CLASS_METHOD(GetInformation,"vtkInformation * vtkAlgorithm::GetInformation()  (http://docs.wxwidgets.org/stable/wx_vtkalgorithm.html#getinformation)")
*/
/* The following types are missing: vtkInformation
    ADD_CLASS_METHOD(SetInformation,"void vtkAlgorithm::SetInformation(vtkInformation * param0)  (http://docs.wxwidgets.org/stable/wx_vtkalgorithm.html#setinformation)")
*/
    ADD_CLASS_METHOD(GetNumberOfInputPorts,"int vtkAlgorithm::GetNumberOfInputPorts()  (http://docs.wxwidgets.org/stable/wx_vtkalgorithm.html#getnumberofinputports)")
    ADD_CLASS_METHOD(GetNumberOfOutputPorts,"int vtkAlgorithm::GetNumberOfOutputPorts()  (http://docs.wxwidgets.org/stable/wx_vtkalgorithm.html#getnumberofoutputports)")
    ADD_CLASS_METHOD(Register,"void vtkAlgorithm::Register(vtkObjectBase * o)  (http://docs.wxwidgets.org/stable/wx_vtkalgorithm.html#register)")
    ADD_CLASS_METHOD(UnRegister,"void vtkAlgorithm::UnRegister(vtkObjectBase * o)  (http://docs.wxwidgets.org/stable/wx_vtkalgorithm.html#unregister)")
    ADD_CLASS_METHOD(SetAbortExecute,"void vtkAlgorithm::SetAbortExecute(int _arg)  (http://docs.wxwidgets.org/stable/wx_vtkalgorithm.html#setabortexecute)")
    ADD_CLASS_METHOD(GetAbortExecute,"int vtkAlgorithm::GetAbortExecute()  (http://docs.wxwidgets.org/stable/wx_vtkalgorithm.html#getabortexecute)")
    ADD_CLASS_METHOD(AbortExecuteOn,"void vtkAlgorithm::AbortExecuteOn()  (http://docs.wxwidgets.org/stable/wx_vtkalgorithm.html#abortexecuteon)")
    ADD_CLASS_METHOD(AbortExecuteOff,"void vtkAlgorithm::AbortExecuteOff()  (http://docs.wxwidgets.org/stable/wx_vtkalgorithm.html#abortexecuteoff)")
    ADD_CLASS_METHOD(SetProgress,"void vtkAlgorithm::SetProgress(double _arg)  (http://docs.wxwidgets.org/stable/wx_vtkalgorithm.html#setprogress)")
    ADD_CLASS_METHOD(GetProgressMinValue,"double vtkAlgorithm::GetProgressMinValue()  (http://docs.wxwidgets.org/stable/wx_vtkalgorithm.html#getprogressminvalue)")
    ADD_CLASS_METHOD(GetProgressMaxValue,"double vtkAlgorithm::GetProgressMaxValue()  (http://docs.wxwidgets.org/stable/wx_vtkalgorithm.html#getprogressmaxvalue)")
    ADD_CLASS_METHOD(GetProgress,"double vtkAlgorithm::GetProgress()  (http://docs.wxwidgets.org/stable/wx_vtkalgorithm.html#getprogress)")
    ADD_CLASS_METHOD(UpdateProgress,"void vtkAlgorithm::UpdateProgress(double amount)  (http://docs.wxwidgets.org/stable/wx_vtkalgorithm.html#updateprogress)")
    ADD_CLASS_METHOD(SetProgressText,"void vtkAlgorithm::SetProgressText(char const * ptext)  (http://docs.wxwidgets.org/stable/wx_vtkalgorithm.html#setprogresstext)")
    ADD_CLASS_METHOD(GetProgressText,"char * vtkAlgorithm::GetProgressText()  (http://docs.wxwidgets.org/stable/wx_vtkalgorithm.html#getprogresstext)")
    ADD_CLASS_METHOD(GetErrorCode,"long unsigned int vtkAlgorithm::GetErrorCode()  (http://docs.wxwidgets.org/stable/wx_vtkalgorithm.html#geterrorcode)")
    ADD_CLASS_METHOD(SetInputArrayToProcess_1,"void vtkAlgorithm::SetInputArrayToProcess(int idx, int port, int connection, int fieldAssociation, char const * name)  (http://docs.wxwidgets.org/stable/wx_vtkalgorithm.html#setinputarraytoprocess)")
    ADD_CLASS_METHOD(SetInputArrayToProcess,"vtkAlgorithm::SetInputArrayToProcess()  (http://docs.wxwidgets.org/stable/wx_vtkalgorithm.html#setinputarraytoprocess)")
    ADD_CLASS_METHOD(SetInputArrayToProcess_2,"void vtkAlgorithm::SetInputArrayToProcess(int idx, int port, int connection, int fieldAssociation, int fieldAttributeType)  (http://docs.wxwidgets.org/stable/wx_vtkalgorithm.html#setinputarraytoprocess)")
/* The following types are missing: vtkInformation
    ADD_CLASS_METHOD(SetInputArrayToProcess_3,"void vtkAlgorithm::SetInputArrayToProcess(int idx, vtkInformation * info)  (http://docs.wxwidgets.org/stable/wx_vtkalgorithm.html#setinputarraytoprocess)")
*/
    ADD_CLASS_METHOD(SetInputArrayToProcess_4,"void vtkAlgorithm::SetInputArrayToProcess(int idx, int port, int connection, char const * fieldAssociation, char const * attributeTypeorName)  (http://docs.wxwidgets.org/stable/wx_vtkalgorithm.html#setinputarraytoprocess)")
/* The following types are missing: vtkInformation
    ADD_CLASS_METHOD(GetInputArrayInformation,"vtkInformation * vtkAlgorithm::GetInputArrayInformation(int idx)  (http://docs.wxwidgets.org/stable/wx_vtkalgorithm.html#getinputarrayinformation)")
*/
    ADD_CLASS_METHOD(RemoveAllInputs,"void vtkAlgorithm::RemoveAllInputs()  (http://docs.wxwidgets.org/stable/wx_vtkalgorithm.html#removeallinputs)")
    ADD_CLASS_METHOD(GetOutputDataObject,"vtkDataObject * vtkAlgorithm::GetOutputDataObject(int port)  (http://docs.wxwidgets.org/stable/wx_vtkalgorithm.html#getoutputdataobject)")
    ADD_CLASS_METHOD(GetInputDataObject,"vtkDataObject * vtkAlgorithm::GetInputDataObject(int port, int connection)  (http://docs.wxwidgets.org/stable/wx_vtkalgorithm.html#getinputdataobject)")
/* The following types are missing: vtkAlgorithmOutput
    ADD_CLASS_METHOD(SetInputConnection_1,"void vtkAlgorithm::SetInputConnection(int port, vtkAlgorithmOutput * input)  (http://docs.wxwidgets.org/stable/wx_vtkalgorithm.html#setinputconnection)")
*/
    ADD_CLASS_METHOD(SetInputConnection,"vtkAlgorithm::SetInputConnection()  (http://docs.wxwidgets.org/stable/wx_vtkalgorithm.html#setinputconnection)")
/* The following types are missing: vtkAlgorithmOutput
    ADD_CLASS_METHOD(SetInputConnection_2,"void vtkAlgorithm::SetInputConnection(vtkAlgorithmOutput * input)  (http://docs.wxwidgets.org/stable/wx_vtkalgorithm.html#setinputconnection)")
*/
/* The following types are missing: vtkAlgorithmOutput
    ADD_CLASS_METHOD(AddInputConnection_1,"void vtkAlgorithm::AddInputConnection(int port, vtkAlgorithmOutput * input)  (http://docs.wxwidgets.org/stable/wx_vtkalgorithm.html#addinputconnection)")
*/
    ADD_CLASS_METHOD(AddInputConnection,"vtkAlgorithm::AddInputConnection()  (http://docs.wxwidgets.org/stable/wx_vtkalgorithm.html#addinputconnection)")
/* The following types are missing: vtkAlgorithmOutput
    ADD_CLASS_METHOD(AddInputConnection_2,"void vtkAlgorithm::AddInputConnection(vtkAlgorithmOutput * input)  (http://docs.wxwidgets.org/stable/wx_vtkalgorithm.html#addinputconnection)")
*/
/* The following types are missing: vtkAlgorithmOutput
    ADD_CLASS_METHOD(RemoveInputConnection,"void vtkAlgorithm::RemoveInputConnection(int port, vtkAlgorithmOutput * input)  (http://docs.wxwidgets.org/stable/wx_vtkalgorithm.html#removeinputconnection)")
*/
/* The following types are missing: vtkAlgorithmOutput
    ADD_CLASS_METHOD(GetOutputPort_1,"vtkAlgorithmOutput * vtkAlgorithm::GetOutputPort(int index)  (http://docs.wxwidgets.org/stable/wx_vtkalgorithm.html#getoutputport)")
*/
    ADD_CLASS_METHOD(GetOutputPort,"vtkAlgorithm::GetOutputPort()  (http://docs.wxwidgets.org/stable/wx_vtkalgorithm.html#getoutputport)")
/* The following types are missing: vtkAlgorithmOutput
    ADD_CLASS_METHOD(GetOutputPort_2,"vtkAlgorithmOutput * vtkAlgorithm::GetOutputPort()  (http://docs.wxwidgets.org/stable/wx_vtkalgorithm.html#getoutputport)")
*/
    ADD_CLASS_METHOD(GetNumberOfInputConnections,"int vtkAlgorithm::GetNumberOfInputConnections(int port)  (http://docs.wxwidgets.org/stable/wx_vtkalgorithm.html#getnumberofinputconnections)")
    ADD_CLASS_METHOD(GetTotalNumberOfInputConnections,"int vtkAlgorithm::GetTotalNumberOfInputConnections()  (http://docs.wxwidgets.org/stable/wx_vtkalgorithm.html#gettotalnumberofinputconnections)")
/* The following types are missing: vtkAlgorithmOutput
    ADD_CLASS_METHOD(GetInputConnection,"vtkAlgorithmOutput * vtkAlgorithm::GetInputConnection(int port, int index)  (http://docs.wxwidgets.org/stable/wx_vtkalgorithm.html#getinputconnection)")
*/
    ADD_CLASS_METHOD(Update,"void vtkAlgorithm::Update()  (http://docs.wxwidgets.org/stable/wx_vtkalgorithm.html#update)")
    ADD_CLASS_METHOD(UpdateInformation,"void vtkAlgorithm::UpdateInformation()  (http://docs.wxwidgets.org/stable/wx_vtkalgorithm.html#updateinformation)")
    ADD_CLASS_METHOD(UpdateWholeExtent,"void vtkAlgorithm::UpdateWholeExtent()  (http://docs.wxwidgets.org/stable/wx_vtkalgorithm.html#updatewholeextent)")
    ADD_CLASS_METHOD(ConvertTotalInputToPortConnection,"void vtkAlgorithm::ConvertTotalInputToPortConnection(int ind, int & port, int & conn)  (http://docs.wxwidgets.org/stable/wx_vtkalgorithm.html#converttotalinputtoportconnection)")
    ADD_CLASS_METHOD(SetReleaseDataFlag,"void vtkAlgorithm::SetReleaseDataFlag(int param0)  (http://docs.wxwidgets.org/stable/wx_vtkalgorithm.html#setreleasedataflag)")
    ADD_CLASS_METHOD(GetReleaseDataFlag,"int vtkAlgorithm::GetReleaseDataFlag()  (http://docs.wxwidgets.org/stable/wx_vtkalgorithm.html#getreleasedataflag)")
    ADD_CLASS_METHOD(ReleaseDataFlagOn,"void vtkAlgorithm::ReleaseDataFlagOn()  (http://docs.wxwidgets.org/stable/wx_vtkalgorithm.html#releasedataflagon)")
    ADD_CLASS_METHOD(ReleaseDataFlagOff,"void vtkAlgorithm::ReleaseDataFlagOff()  (http://docs.wxwidgets.org/stable/wx_vtkalgorithm.html#releasedataflagoff)")
    ADD_CLASS_METHOD(UpdateExtentIsEmpty_1,"int vtkAlgorithm::UpdateExtentIsEmpty(vtkDataObject * output)  (http://docs.wxwidgets.org/stable/wx_vtkalgorithm.html#updateextentisempty)")
    ADD_CLASS_METHOD(UpdateExtentIsEmpty,"vtkAlgorithm::UpdateExtentIsEmpty()  (http://docs.wxwidgets.org/stable/wx_vtkalgorithm.html#updateextentisempty)")
/* The following types are missing: vtkInformation
    ADD_CLASS_METHOD(UpdateExtentIsEmpty_2,"int vtkAlgorithm::UpdateExtentIsEmpty(vtkInformation * pinfo, int extentType)  (http://docs.wxwidgets.org/stable/wx_vtkalgorithm.html#updateextentisempty)")
*/
    ADD_CLASS_METHOD(ComputePriority,"double vtkAlgorithm::ComputePriority()  (http://docs.wxwidgets.org/stable/wx_vtkalgorithm.html#computepriority)")





    void AddMethods(WrapClass<vtkAlgorithm>::ptr this_ptr );
    
    /*
     * Adds the constructor and the static methods to the given context
     */
    static void AddStaticMethods( Variables::ptr& context);

};


#endif // _wrap_vtkAlgorithm_h
