
//#include <vtkGPURayCasting.h>
#include <vtkAlgorithm.h>
#include <vtkAlgorithmOutput.h>
#include <vtkBoxWidget.h>
#include <vtkBMPReader.h>
#include <vtkCamera.h>
#include <vtkCameraInterpolator.h>
#include <vtkCommand.h>
#include <vtkColorTransferFunction.h>
#include <vtkDirectory.h>
#include <vtkGPUVolumeRayCastMapper.h>
#include <vtkGPUVolumeRayCastMapper.h>
#include <vtkImageData.h>
#include <vtkImageReader2.h>
#include <vtkImageReader2Factory.h>
#include <vtkImageResample.h>
#include <vtkInformation.h>
#include <vtkInteractorStyleImage.h>
#include <vtkInteractorStyleTrackball.h>
#include <vtkJPEGReader.h> 
#include <vtkPiecewiseFunction.h>
#include <vtkPlanes.h>
#include <vtkPlaneSource.h>
#include <vtkPolyData.h>
#include <vtkPolyDataMapper.h>
#include <vtkPolyDataNormals.h>
#include <vtkRenderer.h>
#include <vtkRendererCollection.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkSphereSource.h>
#include <vtkVolume.h>
#include <vtkVolumeProperty.h>
#include <vtkVolumeRayCastMapper.h>
#include <vtkVolumeRayCastCompositeFunction.h> 
#include <vtkOpenGLGPUVolumeRayCastMapper.h>
#include <vtkProperty.h>
#include <vtkTexture.h>
#include <vtkTexturedSphereSource.h>
#include <vtkTransform.h>
#include <vtkWindowToImageFilter.h>
#include <vtkArrowSource.h>
#include <vtkImageFFT.h>
#include <vtkImageRFFT.h>
#include <vtkImageFourierCenter.h>
#include <vtkGlyph3D.h>
#include <vtkDoubleArray.h>
