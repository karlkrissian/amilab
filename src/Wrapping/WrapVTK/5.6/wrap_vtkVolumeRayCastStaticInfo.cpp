/**
 * C++ Interface: wrap_vtkVolumeRayCastStaticInfo
 *
 * Description: wrapping vtkVolumeRayCastStaticInfo
 * File generated automatically using CableSwig xml output and a python script
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

//#include "VarContexts.hpp"
#include "wrapfunctions.hpp"
#include "ami_class.h"
#include "ami_object.h"
#include "ami_function.h"

#include "wrap_vtkVolumeRayCastStaticInfo.h"

// get all the required includes
// #include "..."
#ifndef vtkVolume_declared
  #define vtkVolume_declared
  AMI_DECLARE_TYPE(vtkVolume)
#endif
#ifndef vtkRenderer_declared
  #define vtkRenderer_declared
  AMI_DECLARE_TYPE(vtkRenderer)
#endif
#ifndef vtkVolumeRayCastStaticInfo_declared
  #define vtkVolumeRayCastStaticInfo_declared
  AMI_DECLARE_TYPE(vtkVolumeRayCastStaticInfo)
#endif



// needed to allow NULL pointer parameter
extern Variable<int>::ptr nullvar;
extern bool CheckNullVar(ParamList* _p, int _n);

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<vtkVolumeRayCastStaticInfo>::CreateVar( ParamList* p)
{
  WrapClass_vtkVolumeRayCastStaticInfo::wrap_vtkVolumeRayCastStaticInfo construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_HASCOPY(vtkVolumeRayCastStaticInfo);
AMI_DEFINE_VARFROMSMTPTR(vtkVolumeRayCastStaticInfo);


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to vtkVolumeRayCastStaticInfo
//
Variable<AMIObject>::ptr WrapClass_vtkVolumeRayCastStaticInfo::CreateVar( vtkVolumeRayCastStaticInfo* sp)
{
  boost::shared_ptr<vtkVolumeRayCastStaticInfo> di_ptr(
    sp,
    wxwindow_nodeleter<vtkVolumeRayCastStaticInfo>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<vtkVolumeRayCastStaticInfo>::CreateVar(
      new WrapClass_vtkVolumeRayCastStaticInfo(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_vtkVolumeRayCastStaticInfo::AddMethods(WrapClass<vtkVolumeRayCastStaticInfo>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding copy method 
  AddVar___copy__( this_ptr);
  // Adding standard methods 

  // Adding operators
  AddVar___assign__( this_ptr);



  // Add public fields and Enumerations
  AMIObject::ptr tmpobj(amiobject.lock());
  if (!tmpobj.get()) return;
  Variables::ptr context(tmpobj->GetContext());
  
  // Adding public member Volume
  boost::shared_ptr<vtkVolume > var_Volume_ptr(GetObj()->Volume, smartpointer_nodeleter<vtkVolume >());
  if (var_Volume_ptr.get()) {
    BasicVariable::ptr var_Volume = AMILabType<vtkVolume >::CreateVarFromSmtPtr(var_Volume_ptr);
    if (var_Volume.get()) {
      var_Volume->Rename("Volume");
      context->AddVar(var_Volume,context);
    }
  }
  
  // Adding public member Renderer
  boost::shared_ptr<vtkRenderer > var_Renderer_ptr(GetObj()->Renderer, smartpointer_nodeleter<vtkRenderer >());
  if (var_Renderer_ptr.get()) {
    BasicVariable::ptr var_Renderer = AMILabType<vtkRenderer >::CreateVarFromSmtPtr(var_Renderer_ptr);
    if (var_Renderer.get()) {
      var_Renderer->Rename("Renderer");
      context->AddVar(var_Renderer,context);
    }
  }
  
  /* ArrayType not implemented
  // Adding public member WorldToVoxelsMatrix
  boost::shared_ptr<float > var_WorldToVoxelsMatrix_ptr(&GetObj()->WorldToVoxelsMatrix, smartpointer_nodeleter<float >());
  if (var_WorldToVoxelsMatrix_ptr.get()) {
    BasicVariable::ptr var_WorldToVoxelsMatrix = AMILabType<float >::CreateVarFromSmtPtr(var_WorldToVoxelsMatrix_ptr);
    if (var_WorldToVoxelsMatrix.get()) {
      var_WorldToVoxelsMatrix->Rename("WorldToVoxelsMatrix");
      context->AddVar(var_WorldToVoxelsMatrix,context);
    }
  }
  */
  
  /* ArrayType not implemented
  // Adding public member VoxelsToWorldMatrix
  boost::shared_ptr<float > var_VoxelsToWorldMatrix_ptr(&GetObj()->VoxelsToWorldMatrix, smartpointer_nodeleter<float >());
  if (var_VoxelsToWorldMatrix_ptr.get()) {
    BasicVariable::ptr var_VoxelsToWorldMatrix = AMILabType<float >::CreateVarFromSmtPtr(var_VoxelsToWorldMatrix_ptr);
    if (var_VoxelsToWorldMatrix.get()) {
      var_VoxelsToWorldMatrix->Rename("VoxelsToWorldMatrix");
      context->AddVar(var_VoxelsToWorldMatrix,context);
    }
  }
  */
  
  /* ArrayType not implemented
  // Adding public member ViewToVoxelsMatrix
  boost::shared_ptr<float > var_ViewToVoxelsMatrix_ptr(&GetObj()->ViewToVoxelsMatrix, smartpointer_nodeleter<float >());
  if (var_ViewToVoxelsMatrix_ptr.get()) {
    BasicVariable::ptr var_ViewToVoxelsMatrix = AMILabType<float >::CreateVarFromSmtPtr(var_ViewToVoxelsMatrix_ptr);
    if (var_ViewToVoxelsMatrix.get()) {
      var_ViewToVoxelsMatrix->Rename("ViewToVoxelsMatrix");
      context->AddVar(var_ViewToVoxelsMatrix,context);
    }
  }
  */
  
  // Adding public member ClippingPlane
  boost::shared_ptr<float > var_ClippingPlane_ptr(GetObj()->ClippingPlane, smartpointer_nodeleter<float >());
  if (var_ClippingPlane_ptr.get()) {
    BasicVariable::ptr var_ClippingPlane = AMILabType<float >::CreateVarFromSmtPtr(var_ClippingPlane_ptr);
    if (var_ClippingPlane.get()) {
      var_ClippingPlane->Rename("ClippingPlane");
      context->AddVar(var_ClippingPlane,context);
    }
  }
  
  // Adding public member NumberOfClippingPlanes
  boost::shared_ptr<int > var_NumberOfClippingPlanes_ptr(&GetObj()->NumberOfClippingPlanes, smartpointer_nodeleter<int >());
  if (var_NumberOfClippingPlanes_ptr.get()) {
    BasicVariable::ptr var_NumberOfClippingPlanes = AMILabType<int >::CreateVarFromSmtPtr(var_NumberOfClippingPlanes_ptr);
    if (var_NumberOfClippingPlanes.get()) {
      var_NumberOfClippingPlanes->Rename("NumberOfClippingPlanes");
      context->AddVar(var_NumberOfClippingPlanes,context);
    }
  }
  
  // Adding public member CameraThickness
  boost::shared_ptr<float > var_CameraThickness_ptr(&GetObj()->CameraThickness, smartpointer_nodeleter<float >());
  if (var_CameraThickness_ptr.get()) {
    BasicVariable::ptr var_CameraThickness = AMILabType<float >::CreateVarFromSmtPtr(var_CameraThickness_ptr);
    if (var_CameraThickness.get()) {
      var_CameraThickness->Rename("CameraThickness");
      context->AddVar(var_CameraThickness,context);
    }
  }
  
  // Adding public member ScalarDataType
  boost::shared_ptr<int > var_ScalarDataType_ptr(&GetObj()->ScalarDataType, smartpointer_nodeleter<int >());
  if (var_ScalarDataType_ptr.get()) {
    BasicVariable::ptr var_ScalarDataType = AMILabType<int >::CreateVarFromSmtPtr(var_ScalarDataType_ptr);
    if (var_ScalarDataType.get()) {
      var_ScalarDataType->Rename("ScalarDataType");
      context->AddVar(var_ScalarDataType,context);
    }
  }
  
  /* Cannot wrap void* 
  // Adding public member ScalarDataPointer
  boost::shared_ptr<void > var_ScalarDataPointer_ptr(GetObj()->ScalarDataPointer, smartpointer_nodeleter<void >());
  if (var_ScalarDataPointer_ptr.get()) {
    BasicVariable::ptr var_ScalarDataPointer = AMILabType<void >::CreateVarFromSmtPtr(var_ScalarDataPointer_ptr);
    if (var_ScalarDataPointer.get()) {
      var_ScalarDataPointer->Rename("ScalarDataPointer");
      context->AddVar(var_ScalarDataPointer,context);
    }
  }
  */
  
  /* ArrayType not implemented
  // Adding public member DataIncrement
  boost::shared_ptr<int > var_DataIncrement_ptr(&GetObj()->DataIncrement, smartpointer_nodeleter<int >());
  if (var_DataIncrement_ptr.get()) {
    BasicVariable::ptr var_DataIncrement = AMILabType<int >::CreateVarFromSmtPtr(var_DataIncrement_ptr);
    if (var_DataIncrement.get()) {
      var_DataIncrement->Rename("DataIncrement");
      context->AddVar(var_DataIncrement,context);
    }
  }
  */
  
  /* ArrayType not implemented
  // Adding public member DataSize
  boost::shared_ptr<int > var_DataSize_ptr(&GetObj()->DataSize, smartpointer_nodeleter<int >());
  if (var_DataSize_ptr.get()) {
    BasicVariable::ptr var_DataSize = AMILabType<int >::CreateVarFromSmtPtr(var_DataSize_ptr);
    if (var_DataSize.get()) {
      var_DataSize->Rename("DataSize");
      context->AddVar(var_DataSize,context);
    }
  }
  */
  
  /* ArrayType not implemented
  // Adding public member DataSpacing
  boost::shared_ptr<double > var_DataSpacing_ptr(&GetObj()->DataSpacing, smartpointer_nodeleter<double >());
  if (var_DataSpacing_ptr.get()) {
    BasicVariable::ptr var_DataSpacing = AMILabType<double >::CreateVarFromSmtPtr(var_DataSpacing_ptr);
    if (var_DataSpacing.get()) {
      var_DataSpacing->Rename("DataSpacing");
      context->AddVar(var_DataSpacing,context);
    }
  }
  */
  
  /* ArrayType not implemented
  // Adding public member DataOrigin
  boost::shared_ptr<double > var_DataOrigin_ptr(&GetObj()->DataOrigin, smartpointer_nodeleter<double >());
  if (var_DataOrigin_ptr.get()) {
    BasicVariable::ptr var_DataOrigin = AMILabType<double >::CreateVarFromSmtPtr(var_DataOrigin_ptr);
    if (var_DataOrigin.get()) {
      var_DataOrigin->Rename("DataOrigin");
      context->AddVar(var_DataOrigin,context);
    }
  }
  */
  
  // Adding public member Shading
  boost::shared_ptr<int > var_Shading_ptr(&GetObj()->Shading, smartpointer_nodeleter<int >());
  if (var_Shading_ptr.get()) {
    BasicVariable::ptr var_Shading = AMILabType<int >::CreateVarFromSmtPtr(var_Shading_ptr);
    if (var_Shading.get()) {
      var_Shading->Rename("Shading");
      context->AddVar(var_Shading,context);
    }
  }
  
  // Adding public member ColorChannels
  boost::shared_ptr<int > var_ColorChannels_ptr(&GetObj()->ColorChannels, smartpointer_nodeleter<int >());
  if (var_ColorChannels_ptr.get()) {
    BasicVariable::ptr var_ColorChannels = AMILabType<int >::CreateVarFromSmtPtr(var_ColorChannels_ptr);
    if (var_ColorChannels.get()) {
      var_ColorChannels->Rename("ColorChannels");
      context->AddVar(var_ColorChannels,context);
    }
  }
  
  /* ArrayType not implemented
  // Adding public member Color
  boost::shared_ptr<float > var_Color_ptr(&GetObj()->Color, smartpointer_nodeleter<float >());
  if (var_Color_ptr.get()) {
    BasicVariable::ptr var_Color = AMILabType<float >::CreateVarFromSmtPtr(var_Color_ptr);
    if (var_Color.get()) {
      var_Color->Rename("Color");
      context->AddVar(var_Color,context);
    }
  }
  */
  
  // Adding public member InterpolationType
  boost::shared_ptr<int > var_InterpolationType_ptr(&GetObj()->InterpolationType, smartpointer_nodeleter<int >());
  if (var_InterpolationType_ptr.get()) {
    BasicVariable::ptr var_InterpolationType = AMILabType<int >::CreateVarFromSmtPtr(var_InterpolationType_ptr);
    if (var_InterpolationType.get()) {
      var_InterpolationType->Rename("InterpolationType");
      context->AddVar(var_InterpolationType,context);
    }
  }
  
  // Adding public member RedDiffuseShadingTable
  boost::shared_ptr<float > var_RedDiffuseShadingTable_ptr(GetObj()->RedDiffuseShadingTable, smartpointer_nodeleter<float >());
  if (var_RedDiffuseShadingTable_ptr.get()) {
    BasicVariable::ptr var_RedDiffuseShadingTable = AMILabType<float >::CreateVarFromSmtPtr(var_RedDiffuseShadingTable_ptr);
    if (var_RedDiffuseShadingTable.get()) {
      var_RedDiffuseShadingTable->Rename("RedDiffuseShadingTable");
      context->AddVar(var_RedDiffuseShadingTable,context);
    }
  }
  
  // Adding public member GreenDiffuseShadingTable
  boost::shared_ptr<float > var_GreenDiffuseShadingTable_ptr(GetObj()->GreenDiffuseShadingTable, smartpointer_nodeleter<float >());
  if (var_GreenDiffuseShadingTable_ptr.get()) {
    BasicVariable::ptr var_GreenDiffuseShadingTable = AMILabType<float >::CreateVarFromSmtPtr(var_GreenDiffuseShadingTable_ptr);
    if (var_GreenDiffuseShadingTable.get()) {
      var_GreenDiffuseShadingTable->Rename("GreenDiffuseShadingTable");
      context->AddVar(var_GreenDiffuseShadingTable,context);
    }
  }
  
  // Adding public member BlueDiffuseShadingTable
  boost::shared_ptr<float > var_BlueDiffuseShadingTable_ptr(GetObj()->BlueDiffuseShadingTable, smartpointer_nodeleter<float >());
  if (var_BlueDiffuseShadingTable_ptr.get()) {
    BasicVariable::ptr var_BlueDiffuseShadingTable = AMILabType<float >::CreateVarFromSmtPtr(var_BlueDiffuseShadingTable_ptr);
    if (var_BlueDiffuseShadingTable.get()) {
      var_BlueDiffuseShadingTable->Rename("BlueDiffuseShadingTable");
      context->AddVar(var_BlueDiffuseShadingTable,context);
    }
  }
  
  // Adding public member RedSpecularShadingTable
  boost::shared_ptr<float > var_RedSpecularShadingTable_ptr(GetObj()->RedSpecularShadingTable, smartpointer_nodeleter<float >());
  if (var_RedSpecularShadingTable_ptr.get()) {
    BasicVariable::ptr var_RedSpecularShadingTable = AMILabType<float >::CreateVarFromSmtPtr(var_RedSpecularShadingTable_ptr);
    if (var_RedSpecularShadingTable.get()) {
      var_RedSpecularShadingTable->Rename("RedSpecularShadingTable");
      context->AddVar(var_RedSpecularShadingTable,context);
    }
  }
  
  // Adding public member GreenSpecularShadingTable
  boost::shared_ptr<float > var_GreenSpecularShadingTable_ptr(GetObj()->GreenSpecularShadingTable, smartpointer_nodeleter<float >());
  if (var_GreenSpecularShadingTable_ptr.get()) {
    BasicVariable::ptr var_GreenSpecularShadingTable = AMILabType<float >::CreateVarFromSmtPtr(var_GreenSpecularShadingTable_ptr);
    if (var_GreenSpecularShadingTable.get()) {
      var_GreenSpecularShadingTable->Rename("GreenSpecularShadingTable");
      context->AddVar(var_GreenSpecularShadingTable,context);
    }
  }
  
  // Adding public member BlueSpecularShadingTable
  boost::shared_ptr<float > var_BlueSpecularShadingTable_ptr(GetObj()->BlueSpecularShadingTable, smartpointer_nodeleter<float >());
  if (var_BlueSpecularShadingTable_ptr.get()) {
    BasicVariable::ptr var_BlueSpecularShadingTable = AMILabType<float >::CreateVarFromSmtPtr(var_BlueSpecularShadingTable_ptr);
    if (var_BlueSpecularShadingTable.get()) {
      var_BlueSpecularShadingTable->Rename("BlueSpecularShadingTable");
      context->AddVar(var_BlueSpecularShadingTable,context);
    }
  }
  
  /* Type not available
  // Adding public member EncodedNormals
  boost::shared_ptr<short unsigned int > var_EncodedNormals_ptr(GetObj()->EncodedNormals, smartpointer_nodeleter<short unsigned int >());
  if (var_EncodedNormals_ptr.get()) {
    BasicVariable::ptr var_EncodedNormals = AMILabType<short unsigned int >::CreateVarFromSmtPtr(var_EncodedNormals_ptr);
    if (var_EncodedNormals.get()) {
      var_EncodedNormals->Rename("EncodedNormals");
      context->AddVar(var_EncodedNormals,context);
    }
  }
  */
  
  // Adding public member GradientMagnitudes
  boost::shared_ptr<unsigned char > var_GradientMagnitudes_ptr(GetObj()->GradientMagnitudes, smartpointer_nodeleter<unsigned char >());
  if (var_GradientMagnitudes_ptr.get()) {
    BasicVariable::ptr var_GradientMagnitudes = AMILabType<unsigned char >::CreateVarFromSmtPtr(var_GradientMagnitudes_ptr);
    if (var_GradientMagnitudes.get()) {
      var_GradientMagnitudes->Rename("GradientMagnitudes");
      context->AddVar(var_GradientMagnitudes,context);
    }
  }
  
  /* ArrayType not implemented
  // Adding public member ImageInUseSize
  boost::shared_ptr<int > var_ImageInUseSize_ptr(&GetObj()->ImageInUseSize, smartpointer_nodeleter<int >());
  if (var_ImageInUseSize_ptr.get()) {
    BasicVariable::ptr var_ImageInUseSize = AMILabType<int >::CreateVarFromSmtPtr(var_ImageInUseSize_ptr);
    if (var_ImageInUseSize.get()) {
      var_ImageInUseSize->Rename("ImageInUseSize");
      context->AddVar(var_ImageInUseSize,context);
    }
  }
  */
  
  /* ArrayType not implemented
  // Adding public member ImageMemorySize
  boost::shared_ptr<int > var_ImageMemorySize_ptr(&GetObj()->ImageMemorySize, smartpointer_nodeleter<int >());
  if (var_ImageMemorySize_ptr.get()) {
    BasicVariable::ptr var_ImageMemorySize = AMILabType<int >::CreateVarFromSmtPtr(var_ImageMemorySize_ptr);
    if (var_ImageMemorySize.get()) {
      var_ImageMemorySize->Rename("ImageMemorySize");
      context->AddVar(var_ImageMemorySize,context);
    }
  }
  */
  
  /* ArrayType not implemented
  // Adding public member ImageViewportSize
  boost::shared_ptr<int > var_ImageViewportSize_ptr(&GetObj()->ImageViewportSize, smartpointer_nodeleter<int >());
  if (var_ImageViewportSize_ptr.get()) {
    BasicVariable::ptr var_ImageViewportSize = AMILabType<int >::CreateVarFromSmtPtr(var_ImageViewportSize_ptr);
    if (var_ImageViewportSize.get()) {
      var_ImageViewportSize->Rename("ImageViewportSize");
      context->AddVar(var_ImageViewportSize,context);
    }
  }
  */
  
  /* ArrayType not implemented
  // Adding public member ImageOrigin
  boost::shared_ptr<int > var_ImageOrigin_ptr(&GetObj()->ImageOrigin, smartpointer_nodeleter<int >());
  if (var_ImageOrigin_ptr.get()) {
    BasicVariable::ptr var_ImageOrigin = AMILabType<int >::CreateVarFromSmtPtr(var_ImageOrigin_ptr);
    if (var_ImageOrigin.get()) {
      var_ImageOrigin->Rename("ImageOrigin");
      context->AddVar(var_ImageOrigin,context);
    }
  }
  */
  
  // Adding public member Image
  boost::shared_ptr<unsigned char > var_Image_ptr(GetObj()->Image, smartpointer_nodeleter<unsigned char >());
  if (var_Image_ptr.get()) {
    BasicVariable::ptr var_Image = AMILabType<unsigned char >::CreateVarFromSmtPtr(var_Image_ptr);
    if (var_Image.get()) {
      var_Image->Rename("Image");
      context->AddVar(var_Image,context);
    }
  }
  
  // Adding public member RowBounds
  boost::shared_ptr<int > var_RowBounds_ptr(GetObj()->RowBounds, smartpointer_nodeleter<int >());
  if (var_RowBounds_ptr.get()) {
    BasicVariable::ptr var_RowBounds = AMILabType<int >::CreateVarFromSmtPtr(var_RowBounds_ptr);
    if (var_RowBounds.get()) {
      var_RowBounds->Rename("RowBounds");
      context->AddVar(var_RowBounds,context);
    }
  }
  
  // Adding public member MIPFunction
  boost::shared_ptr<int > var_MIPFunction_ptr(&GetObj()->MIPFunction, smartpointer_nodeleter<int >());
  if (var_MIPFunction_ptr.get()) {
    BasicVariable::ptr var_MIPFunction = AMILabType<int >::CreateVarFromSmtPtr(var_MIPFunction_ptr);
    if (var_MIPFunction.get()) {
      var_MIPFunction->Rename("MIPFunction");
      context->AddVar(var_MIPFunction,context);
    }
  }
  
  // Adding public member MaximizeOpacity
  boost::shared_ptr<int > var_MaximizeOpacity_ptr(&GetObj()->MaximizeOpacity, smartpointer_nodeleter<int >());
  if (var_MaximizeOpacity_ptr.get()) {
    BasicVariable::ptr var_MaximizeOpacity = AMILabType<int >::CreateVarFromSmtPtr(var_MaximizeOpacity_ptr);
    if (var_MaximizeOpacity.get()) {
      var_MaximizeOpacity->Rename("MaximizeOpacity");
      context->AddVar(var_MaximizeOpacity,context);
    }
  }


  


  // Adding Bases

};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClassvtkVolumeRayCastStaticInfo_AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("vtkVolumeRayCastStaticInfo");
    WrapClass_vtkVolumeRayCastStaticInfo::AddVar_vtkVolumeRayCastStaticInfo_1(amiobject->GetContext());
  WrapClass_vtkVolumeRayCastStaticInfo::AddVar_vtkVolumeRayCastStaticInfo(amiobject->GetContext());
  WrapClass_vtkVolumeRayCastStaticInfo::AddVar_vtkVolumeRayCastStaticInfo_2(amiobject->GetContext());


  // Static methods 

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor vtkVolumeRayCastStaticInfo::._88(vtkVolumeRayCastStaticInfo const & param0)
//---------------------------------------------------
void WrapClass_vtkVolumeRayCastStaticInfo::
    wrap_vtkVolumeRayCastStaticInfo_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkVolumeRayCastStaticInfo, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeRayCastStaticInfo::
    wrap_vtkVolumeRayCastStaticInfo_1::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkVolumeRayCastStaticInfo > param0_smtptr;
  if (!get_val_smtptr_param<vtkVolumeRayCastStaticInfo >(param0_smtptr,_p,_n,true,true,false)) ClassHelpAndReturn;
  vtkVolumeRayCastStaticInfo const & param0 = *param0_smtptr;

  vtkVolumeRayCastStaticInfo* _newobj = new vtkVolumeRayCastStaticInfo(param0);
  BasicVariable::ptr res = WrapClass_vtkVolumeRayCastStaticInfo::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor vtkVolumeRayCastStaticInfo::vtkVolumeRayCastStaticInfo(...)
//---------------------------------------------------
void WrapClass_vtkVolumeRayCastStaticInfo::
    wrap_vtkVolumeRayCastStaticInfo::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeRayCastStaticInfo::
    wrap_vtkVolumeRayCastStaticInfo::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkVolumeRayCastStaticInfo::wrap_vtkVolumeRayCastStaticInfo_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkVolumeRayCastStaticInfo::wrap_vtkVolumeRayCastStaticInfo_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor vtkVolumeRayCastStaticInfo::._88()
//---------------------------------------------------
void WrapClass_vtkVolumeRayCastStaticInfo::
    wrap_vtkVolumeRayCastStaticInfo_2::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeRayCastStaticInfo::
    wrap_vtkVolumeRayCastStaticInfo_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkVolumeRayCastStaticInfo* _newobj = new vtkVolumeRayCastStaticInfo();
  BasicVariable::ptr res = WrapClass_vtkVolumeRayCastStaticInfo::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of 'copy' method for vtkVolumeRayCastStaticInfo.
//---------------------------------------------------
void WrapClass_vtkVolumeRayCastStaticInfo::
    wrap___copy__::SetParametersComments()
{
  return_comments="A copy of the vtkVolumeRayCastStaticInfo object within a new variable.";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeRayCastStaticInfo::
    wrap___copy__::CallMember( ParamList* _p)
{
    return AMILabType<vtkVolumeRayCastStaticInfo >::CreateVar( new vtkVolumeRayCastStaticInfo(*(this->_objectptr->GetObj())));
}

//---------------------------------------------------
//  Wrapping of vtkVolumeRayCastStaticInfo & vtkVolumeRayCastStaticInfo::operator =(vtkVolumeRayCastStaticInfo const & param0)
//---------------------------------------------------
void WrapClass_vtkVolumeRayCastStaticInfo::
    wrap___assign__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkVolumeRayCastStaticInfo, "parameter named 'param0'")
  return_comments="returning a variable of type vtkVolumeRayCastStaticInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeRayCastStaticInfo::
    wrap___assign__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkVolumeRayCastStaticInfo > param0_smtptr;
  if (!get_val_smtptr_param<vtkVolumeRayCastStaticInfo >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkVolumeRayCastStaticInfo const & param0 = *param0_smtptr;

  vtkVolumeRayCastStaticInfo & res =   (*this->_objectptr->GetObj()) = (param0);
  return AMILabType<vtkVolumeRayCastStaticInfo >::CreateVar(res);
}

