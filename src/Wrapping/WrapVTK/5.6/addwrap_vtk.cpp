/*
 * Automatic wrapping of 'vtk' library for AMILab.
 * File: wrap/addwrap_vtk.cpp
 * Generated by the script './parse_xml2.py'
 * Date: '01-12-2010'
 */

// Currently 66 objects (classes,structures,typedefs,...) are wrapped 
#include "wrap_vtk3DWidget.h"
#include "wrap_vtkAbstractArray.h"
#include "wrap_vtkAbstractMapper.h"
#include "wrap_vtkAbstractMapper3D.h"
#include "wrap_vtkAbstractTransform.h"
#include "wrap_vtkAbstractVolumeMapper.h"
#include "wrap_vtkActor.h"
#include "wrap_vtkActorCollection.h"
#include "wrap_vtkAlgorithm.h"
#include "wrap_vtkBoxWidget.h"
#include "wrap_vtkCamera.h"
#include "wrap_vtkCellTypes.h"
#include "wrap_vtkCollection.h"
#include "wrap_vtkColorTransferFunction.h"
#include "wrap_vtkCommand.h"
#include "wrap_vtkDataArray.h"
#include "wrap_vtkDataObject.h"
#include "wrap_vtkDataSet.h"
#include "wrap_vtkGPUVolumeRayCastMapper.h"
#include "wrap_vtkHomogeneousTransform.h"
#include "wrap_vtkImageData.h"
#include "wrap_vtkImplicitFunction.h"
#include "wrap_vtkIndent.h"
#include "wrap_vtkIntArray.h"
#include "wrap_vtkInteractorObserver.h"
#include "wrap_vtkInteractorStyle.h"
#include "wrap_vtkInteractorStyleImage.h"
#include "wrap_vtkInteractorStyleSwitch.h"
#include "wrap_vtkInteractorStyleTrackball.h"
#include "wrap_vtkInteractorStyleTrackballCamera.h"
#include "wrap_vtkLinearTransform.h"
#include "wrap_vtkMatrix4x4.h"
#include "wrap_vtkObject.h"
#include "wrap_vtkObjectBase.h"
#include "wrap_vtkOpenGLGPUVolumeRayCastMapper.h"
#include "wrap_vtkPiecewiseFunction.h"
#include "wrap_vtkPlanes.h"
#include "wrap_vtkPointSet.h"
#include "wrap_vtkPoints.h"
#include "wrap_vtkPolyData.h"
#include "wrap_vtkProp.h"
#include "wrap_vtkProp3D.h"
#include "wrap_vtkPropCollection.h"
#include "wrap_vtkProperty.h"
#include "wrap_vtkRenderWindow.h"
#include "wrap_vtkRenderWindowInteractor.h"
#include "wrap_vtkRenderer.h"
#include "wrap_vtkRendererCollection.h"
#include "wrap_vtkScalarsToColors.h"
#include "wrap_vtkStdString.h"
#include "wrap_vtkTimeStamp.h"
#include "wrap_vtkTransform.h"
#include "wrap_vtkUnicodeString.h"
#include "wrap_vtkUnsignedCharArray.h"
#include "wrap_vtkVariant.h"
#include "wrap_vtkViewport.h"
#include "wrap_vtkVolume.h"
#include "wrap_vtkVolumeCollection.h"
#include "wrap_vtkVolumeMapper.h"
#include "wrap_vtkVolumeProperty.h"
#include "wrap_vtkVolumeRayCastCompositeFunction.h"
#include "wrap_vtkVolumeRayCastDynamicInfo.h"
#include "wrap_vtkVolumeRayCastFunction.h"
#include "wrap_vtkVolumeRayCastMapper.h"
#include "wrap_vtkVolumeRayCastStaticInfo.h"
#include "wrap_vtkWindow.h"

/*
 * Adding all the wrapped classes to the library context.
 * @param context the library context.
 */
void wrap_vtk_classes( Variables::ptr& context)
{

  // Create a macro to simplify ...
  #define ADD_VTK_CLASS(classname) \
    WrapClass_##classname::AddStaticMethods( context);

  ADD_VTK_CLASS( vtk3DWidget)
  ADD_VTK_CLASS( vtkAbstractArray)
  ADD_VTK_CLASS( vtkAbstractMapper)
  ADD_VTK_CLASS( vtkAbstractMapper3D)
  ADD_VTK_CLASS( vtkAbstractTransform)
  ADD_VTK_CLASS( vtkAbstractVolumeMapper)
  ADD_VTK_CLASS( vtkActor)
  ADD_VTK_CLASS( vtkActorCollection)
  ADD_VTK_CLASS( vtkAlgorithm)
  ADD_VTK_CLASS( vtkBoxWidget)
  ADD_VTK_CLASS( vtkCamera)
  ADD_VTK_CLASS( vtkCellTypes)
  ADD_VTK_CLASS( vtkCollection)
  ADD_VTK_CLASS( vtkColorTransferFunction)
  ADD_VTK_CLASS( vtkCommand)
  ADD_VTK_CLASS( vtkDataArray)
  ADD_VTK_CLASS( vtkDataObject)
  ADD_VTK_CLASS( vtkDataSet)
  ADD_VTK_CLASS( vtkGPUVolumeRayCastMapper)
  ADD_VTK_CLASS( vtkHomogeneousTransform)
  ADD_VTK_CLASS( vtkImageData)
  ADD_VTK_CLASS( vtkImplicitFunction)
  ADD_VTK_CLASS( vtkIndent)
  ADD_VTK_CLASS( vtkIntArray)
  ADD_VTK_CLASS( vtkInteractorObserver)
  ADD_VTK_CLASS( vtkInteractorStyle)
  ADD_VTK_CLASS( vtkInteractorStyleImage)
  ADD_VTK_CLASS( vtkInteractorStyleSwitch)
  ADD_VTK_CLASS( vtkInteractorStyleTrackball)
  ADD_VTK_CLASS( vtkInteractorStyleTrackballCamera)
  ADD_VTK_CLASS( vtkLinearTransform)
  ADD_VTK_CLASS( vtkMatrix4x4)
  ADD_VTK_CLASS( vtkObject)
  ADD_VTK_CLASS( vtkObjectBase)
  ADD_VTK_CLASS( vtkOpenGLGPUVolumeRayCastMapper)
  ADD_VTK_CLASS( vtkPiecewiseFunction)
  ADD_VTK_CLASS( vtkPlanes)
  ADD_VTK_CLASS( vtkPointSet)
  ADD_VTK_CLASS( vtkPoints)
  ADD_VTK_CLASS( vtkPolyData)
  ADD_VTK_CLASS( vtkProp)
  ADD_VTK_CLASS( vtkProp3D)
  ADD_VTK_CLASS( vtkPropCollection)
  ADD_VTK_CLASS( vtkProperty)
  ADD_VTK_CLASS( vtkRenderWindow)
  ADD_VTK_CLASS( vtkRenderWindowInteractor)
  ADD_VTK_CLASS( vtkRenderer)
  ADD_VTK_CLASS( vtkRendererCollection)
  ADD_VTK_CLASS( vtkScalarsToColors)
  ADD_VTK_CLASS( vtkStdString)
  ADD_VTK_CLASS( vtkTimeStamp)
  ADD_VTK_CLASS( vtkTransform)
  ADD_VTK_CLASS( vtkUnicodeString)
  ADD_VTK_CLASS( vtkUnsignedCharArray)
  ADD_VTK_CLASS( vtkVariant)
  ADD_VTK_CLASS( vtkViewport)
  ADD_VTK_CLASS( vtkVolume)
  ADD_VTK_CLASS( vtkVolumeCollection)
  ADD_VTK_CLASS( vtkVolumeMapper)
  ADD_VTK_CLASS( vtkVolumeProperty)
  ADD_VTK_CLASS( vtkVolumeRayCastCompositeFunction)
  ADD_VTK_CLASS( vtkVolumeRayCastDynamicInfo)
  ADD_VTK_CLASS( vtkVolumeRayCastFunction)
  ADD_VTK_CLASS( vtkVolumeRayCastMapper)
  ADD_VTK_CLASS( vtkVolumeRayCastStaticInfo)
  ADD_VTK_CLASS( vtkWindow)

  #undef ADD_VTK_CLASS
}

