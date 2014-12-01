//
// C++ Implementation: wrapAMIFluid
//
// Description:
//
//
// Author: Karl Krissian,,, <karl@UBUNTU-KARL>, (C) 2006
//
// Copyright: See COPYING file that comes with this distribution
//
//

#include "paramlist.h"
#include "surface.hpp"
using namespace amilab;

#include "VarContexts.hpp"
#include "wrapfunctions.hpp"
#include "wrapVTKTools.h"
#include "vtk_common.h"

#include "wrap_SurfacePoly.h"
#include "vtkGPURayCasting.h"

#include "LanguageBaseConfigure.h"
LanguageBase_VAR_IMPORT VarContexts  Vars;

#ifndef _WITHOUT_VTK_

// all the needed vtk files

// standard VTK
#include "vtkPolyData.h"
#include "vtkSphereSource.h"

// files from myVTK library
#include "vtkMINCImageReader.h"
#include "vtkImageIsoContourDist.h"
#include "vtkImageFastSignedChamfer.h"
#include "vtkLevelSetFastMarching.h"
#include "vtkImagePropagateDist.h"
#include "vtkImagePropagateDist2.h"
#include "vtkConvexHull.h"
#include "vtkAnisoGaussSeidel.h"
#include "vtkSkeleton2Lines.h"


#include "wrap_vtkImageData.h"
#include "wrap_vtkPolyData.h"
#include "wrap_SurfacePoly.h"
#include "wrap_vtkRenderWindowInteractor.h"
#include "message_dialog.h"

//#include "addwrap_vtk.h"


#endif // _WITHOUT_VTK_



//---------------------------------------------------------
void AddWrapVTKTools(AMIObject::ptr& obj) {

  // Create vtk context
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("vtktools");
  // Set the object context
  Variables::ptr previous_ocontext = Vars.GetObjectContext();
  Vars.SetObjectContext(amiobject->GetContext());

    ADDOBJECTVAR_NAME( C_wrap_imagefunction, "vtkAnisoGaussSeidel",  
                       vtkAnisoGS);
    ADDOBJECTVAR_NAME( C_wrap_varfunction,   "vtkSkeleton2Lines",    
                       Wrap_vtkSkeleton2Lines);
    ADDOBJECTVAR_NAME( C_wrap_varfunction,   "vtkSphere",            
                       Wrap_vtkSphere);
    ADDOBJECTVAR_NAME( C_wrap_varfunction,   "vtkGPURayCasting",     
                       wrap_vtkGPURayCasting);
    ADDOBJECTVAR_NAME( C_wrap_varfunction,   "ToVtkImageData",   
                       wrap_ToVtkImageData);
    ADDOBJECTVAR_NAME( C_wrap_varfunction,   "FromVtkImageData", 
                       wrap_FromVtkImageData);

    ADDOBJECTVAR_NAME( C_wrap_varfunction,   "ToVtkPolyData",   
                       wrap_ToVtkPolyData);
    ADDOBJECTVAR_NAME( C_wrap_varfunction,   "FromVtkPolyData", 
                       wrap_FromVtkPolyData);


  // Restore the object context
  Vars.SetObjectContext(previous_ocontext);
  // Add vtktools context to builtin
  obj->GetContext()->AddVar<AMIObject>( amiobject->GetName().c_str(), 
      amiobject,obj->GetContext());

}


/** Read a 3D Flow from an ASCII file **/
InrImage* vtkAnisoGS(ParamList* p) {

#ifndef _WITHOUT_VTK_
    char functionname[] = "vtkAnisoGaussSeidel";
    char description[]=" \n\
                       Runs Anisotropic Diffusion Filter based on the \n\
                       Flux Diffusion and using the Gauss-Seidel\n\
                       numerical scheme\n\
                       ";
    char parameters[] =" \n\
                       Parameters:\n\
                       input image\n\
                       standard deviation for Gaussian smoothing sigma\n\
                       threshold on the gradient magnitude\n\
                       data attachment coefficient\n\
                       number of iterations\n\
                       number of threads (def: 1)\n\
                       ";

    InrImage* input;
    float sd;
    float threshold;
    float data_coeff;
    int iterations;
    int threads = 1;
    int n=0;

    if (!get_val_ptr_param<InrImage>(  input,      p, n)) HelpAndReturnNULL;
    if (!get_val_param<float>(  sd,         p, n)) HelpAndReturnNULL;
    if (!get_val_param<float>(  threshold,  p, n)) HelpAndReturnNULL;
    if (!get_val_param<float>(  data_coeff, p, n)) HelpAndReturnNULL;
    if (!get_int_param(    iterations, p, n)) HelpAndReturnNULL;
    if (!get_int_param(    threads   , p, n)) HelpAndReturnNULL;


    vtkImageData_ptr                vtk_image;
    InrImage*                       res;
    boost::shared_ptr<vtkAnisoGaussSeidel> vtk_aniso;
    //  printf("1 \n");
    vtk_image = vtk_new<vtkImageData>()((vtkImageData*) (*input));
    //    printf("2 \n");

    vtk_aniso = vtk_new<vtkAnisoGaussSeidel>()();
    vtk_aniso->SetInputData(              vtk_image.get());
    vtk_aniso->Setmode(               3);
    vtk_aniso->Setsigma(              sd);
    vtk_aniso->Setk(                  threshold);
    vtk_aniso->Setbeta(               data_coeff);
    vtk_aniso->SetIsoCoeff(           0.2);
    vtk_aniso->SetNumberOfIterations( iterations);
    vtk_aniso->SetNumberOfThreads(    threads);

    vtk_aniso->Update();

    //    printf("3 \n");
    res = new InrImage( vtk_aniso->GetOutput());
    //    printf("4 \n");
    return res;

#else
    fprintf(stderr," VTK not available, you need to compile with VTK ...\n");
    return NULL;
#endif // _WITHOUT_VTK_

} // vtkAnisoGS()


/** Read a 3D Flow from an ASCII file **/
BasicVariable::ptr Wrap_vtkSkeleton2Lines(ParamList* p)
{

    char functionname[] = "vtkSkeleton2Lines";
    char description[]=" \n\
                       Creates lines from a skeleton\n\
                       ";
    char parameters[] =" \n\
                       Parameters:\
                       \n\
                       input image\n\
                       Return:\
                       \n\
                       Resulting polydata as set of lines\n\
                       ";

    InrImage* input;
    int n=0;

    if (!get_val_ptr_param<InrImage>(  input,      p, n)) HelpAndReturnVarPtr;


    vtkImageData_ptr                vtk_image;
    boost::shared_ptr<vtkSkeleton2Lines>   vtk_skel2lines;
    //  printf("1 \n");
    vtk_image = (vtkImageData_ptr) (*input);
    //    printf("2 \n");

    vtk_skel2lines = vtk_new<vtkSkeleton2Lines>()();
    vtk_skel2lines->SetInputData( vtk_image.get());
    vtk_skel2lines->Update();
    vtk_skel2lines->GetOutput();


    return WrapClass_SurfacePoly::CreateVar(
      new SurfacePoly(vtk_skel2lines->GetOutput()));

    /*
    SurfacePoly::ptr surf_result( new SurfacePoly(vtk_skel2lines->GetOutput()));

    Variable<SurfacePoly>::ptr varres(
    new Variable<SurfacePoly>("vtkSkeleton2lines_result",surf_result));

    return varres;
    */


} // Wrap_vtkSkeleton2Lines()


//---------------------------------------------------------------------------
BasicVariable::ptr Wrap_vtkSphere( ParamList* p)
//            --------------
{

    char functionname[] = "vtkSphere";
    char description[]=" \n\
                       Create a sphere as a polydata\n\
                       ";
    char parameters[] =" \n\
                       Parameters:\
                       \n\
                       - radius           (def 0.5)\n\
                       - Theta resolution (def 8)\n\
                       - Phi resolution   (def 8)\n\
                       - Sphere center :\
                       3 float values (def 0,0,0) \n\
                       Return:\
                       \n\
                       A sphere polydata\n\
                       ";

    float radius    = 0.5;
    int thetares    = 8;
    int phires      = 8;
    float center[3] = {0,0,0};
    int n=0;

    if (!get_val_param<float>(         radius,      p, n)) HelpAndReturnVarPtr;
    if (!get_int_param(           thetares,    p, n)) HelpAndReturnVarPtr;
    if (!get_int_param(           phires,      p, n)) HelpAndReturnVarPtr;
    if (!get_several_params<float,3>(  center,      p, n)) HelpAndReturnVarPtr;

    boost::shared_ptr<vtkSphereSource>   vtk_sphere;

    vtk_sphere = vtk_new<vtkSphereSource>()();

    vtk_sphere->SetRadius           (radius);
    vtk_sphere->SetThetaResolution  (thetares);
    vtk_sphere->SetPhiResolution    (phires);
    vtk_sphere->SetCenter           (center[0],center[1],center[2]);

    vtk_sphere->Update();

    return WrapClass_SurfacePoly::CreateVar(new SurfacePoly(vtk_sphere->GetOutput()));


} // Wrap_vtkSphere()



/** Read a 3D Flow from an ASCII file **/
BasicVariable::ptr wrap_vtkGPURayCasting(ParamList* p)
{

    char functionname[] = "vtkCPURayCasting";
    char description[]=" \n\
                        GPU Ray Casting with VTK 5.6\n\
                       ";

    char parameters[] = "\n\
    Parameters:\n    input image\n    int   blend type:\n\
    0->MIP, 1->CompositeRamp, 2->CompositeShadeRamp, 3->CT_Skin, 4->CT_Bone, 5->RGB_Composite\n\
    float opacitywindow\n\
    float opacitylevel\n\
    int clip 0|1 \n\
    ";

    InrImage* input;
    int   n=0;
    int   blendtype=0;
    float window=4096;
    float level=2048;
    int   clip=0;

    if (!get_val_ptr_param<InrImage>(  input,      p, n)) HelpAndReturnVarPtr;

    if (!get_val_param<int>(           blendtype,    p, n)) HelpAndReturnVarPtr;

    if (!get_val_param<float>(         window,    p, n)) HelpAndReturnVarPtr;
    if (!get_val_param<float>(         level,    p, n)) HelpAndReturnVarPtr;
    if (!get_val_param<int>(           clip,    p, n)) HelpAndReturnVarPtr;

    vtkImageData_ptr                vtk_image;
    //  printf("1 \n");
    vtk_image = (vtkImageData_ptr) (*input);
    //    printf("2 \n");

    vtkGPURayCasting* volren = new vtkGPURayCasting(vtk_image, clip);
    volren->SetBlendType(blendtype);
    volren->SetOpacityMap(window,level);
    //volren->SetClip(clip);
    //volren->Display();
    volren->Show(TRUE);
    vtkRenderWindowInteractor* renwininteract = volren->GetRenderWindowInteractor();

    return AMILabType<vtkRenderWindowInteractor>::CreateVar(renwininteract);

} // Wrap_vtkSkeleton2Lines()

// //
// BasicVariable::ptr wrap_wxVTKMedical3(ParamList* p)
// {
// 
//     char functionname[] = "wxVTKMedical3";
//     char description[]=" \n\
//                        ";
//     char parameters[] =" \n\
//                        Parameters:\
//                        \n\
//                        ";
// 
//     InrImage* input;
//     int   n=0;
// 
//     vtkImageData_ptr                vtk_image;
//     //  printf("1 \n");
// 
//     if (!get_val_ptr_param<InrImage>(  input,      p, n)) HelpAndReturnVarPtr;
//     vtk_image = (vtkImageData_ptr) (*input);
// 
//     // create the main application window
//     wxMedical3Frame *frame = new wxMedical3Frame(vtk_image,_T("wxWindows-VTK App"),
//             wxPoint(50, 50), wxSize(450, 340));
// //    frame->SetInput(vtk_image);
// 
//     // and show it (the frames, unlike simple controls, are not shown when
//     // created initially)
//     frame->Show(TRUE);
// 
// 
//     return BasicVariable::ptr();
// 
// 
// } // wrap_wxVTKMedical3()
// 

//
BasicVariable::ptr wrap_ToVtkImageData(ParamList* p)
{

  char functionname[] = "ToVtkImageData";
  char description[]=" \n\
                      ";
  char parameters[] =" convert InrImage variable to vtkImageData variable\n\
                      Parameters:\n\
                        InrImage variable\n\
                      Return: Returns a variable of type vtkImageData\n\
                      \n\
                      ";

  InrImage* input;
  int   n=0;

  vtkImageData_ptr                vtk_image;
  //  printf("1 \n");

  if (!get_val_ptr_param<InrImage>(  input,      p, n)) HelpAndReturnVarPtr;
  vtk_image = (vtkImageData_ptr) (*input);

  return AMILabType<vtkImageData>::CreateVarFromSmtPtr(vtk_image);

} // wrap_ToVtkImageData()



//
BasicVariable::ptr wrap_FromVtkImageData(ParamList* p)
{

  char functionname[] = "FromVtkImageData";
  char description[]=" \n\
                      ";
  char parameters[] =" convert vtkImageData  variable to InrImage variable\n\
                      Parameters:\n\
                        vtkImageData variable\n\
                      Return: Returns a variable of type InrImage\n\
                      \n\
                      ";

  vtkImageData_ptr vtk_input;
  InrImage::ptr image;
  int   n=0;

  if (!get_val_smtptr_param<vtkImageData>( vtk_input,      p, n)) HelpAndReturnVarPtr;
  //std::cout << "vtk_input.get() " << vtk_input.get() << std::endl;
  if (vtk_input.get()) {
    image =  InrImage::ptr(new InrImage(vtk_input.get()));
    
    return Variable<InrImage>::ptr( new Variable<InrImage>(image));
  }
  else
    return BasicVariable::ptr();

} // wrap_FromVtkImageData()


//
BasicVariable::ptr wrap_ToVtkPolyData(ParamList* p)
{

  char functionname[] = "ToVtkPolyData";
  char description[]=" \n\
                      ";
  char parameters[] ="Converts a SurfacePoly variable to a vtkPolyData variable\n\
                      Parameters:\n\
                        SurfacePoly variable\n\
                      Returns: Returns a variable of type vtkPolyData\n\
                      \n\
                      ";

  SurfacePoly* input;
  int   n=0;

  boost::shared_ptr<vtkPolyData>                vtk_polydata;
  //  printf("1 \n");

  if (!get_val_ptr_param<SurfacePoly>(  input,      p, n)) HelpAndReturnVarPtr;
  vtk_polydata = boost::shared_ptr<vtkPolyData>( (vtkPolyData*) (*input), vtk_deleter<vtkPolyData>());

  return AMILabType<vtkPolyData>::CreateVarFromSmtPtr(vtk_polydata);

} // wrap_ToVtkPolyData()


//
BasicVariable::ptr wrap_FromVtkPolyData(ParamList* p)
{

  char functionname[] = "FromVtkPolyData";
  char description[]=" \n\
                      ";
  char parameters[] =" convert vtkPolyData  variable to SurfacePoly variable\n\
                      Parameters:\n\
                        vtkPolyData variable\n\
                      Return: Returns a variable of type SurfacePoly\n\
                      \n\
                      ";

  boost::shared_ptr<vtkPolyData> vtk_input;
  SurfacePoly::ptr surf;
  int   n=0;

  if (!get_val_smtptr_param<vtkPolyData>( vtk_input,      p, n)) HelpAndReturnVarPtr;
  //std::cout << "vtk_input.get() " << vtk_input.get() << std::endl;
  if (vtk_input.get()) {
    surf =  SurfacePoly::ptr(new SurfacePoly(vtk_input.get()));
    
    return AMILabType<SurfacePoly>::CreateVarFromSmtPtr( surf);
  }
  else
    return BasicVariable::ptr();

} // wrap_FromVtkPolyData()


// //
// BasicVariable::ptr wrap_wxVTKFrame(ParamList* p)
// {
// 
//   char functionname[] = "wxVTKFrame";
//   char description[]=" \n\
//                       ";
//   char parameters[] =" wxFrame with a vtkWindowInteractor inside\n\
//                       Parameters:\
//                       Return: Returns a variable of type vtkRenderWindowInterator\
//                       \n\
//                       ";
// 
//   // create the main application window
//   wxVTKFrame *vtkframe = new wxVTKFrame(_T("wxWindows-VTK App"),
//           wxPoint(50, 50), wxSize(450, 340));
//   vtkframe->Show(TRUE);
//   wxVTKRenderWindowInteractor* renwininteract = vtkframe->GetRenderWindowInteractor();
//   return AMILabType<wxVTKRenderWindowInteractor>::CreateVar(renwininteract);
// 
// } // wrap_wxVTKFrame()
