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

#include "VarContexts.hpp"
#include "wrapfunctions.hpp"
#include "wrapWxVTK.h"
#include "vtk_common.h"

#include "LanguageBaseConfigure.h"
LanguageBase_VAR_IMPORT VarContexts  Vars;


// all the needed vtk files

// standard VTK
#include "vtkPolyData.h"

#include "wxMedical3Frame.h"
#include "wxVTKFrame.h"
#include "wrap_wxVTKRenderWindowInteractor.h"

#include "addwrap_vtk.h"
#include "inrimage.hpp"



//---------------------------------------------------------
void AddWrapWxVTK(AMIObject::ptr& obj) {

  // Create vtk context
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxvtk");
  // Set the object context
  Variables::ptr previous_ocontext = Vars.GetObjectContext();
  Vars.SetObjectContext(amiobject->GetContext());

    ADDOBJECTVAR_NAME( C_wrap_varfunction,   "wxVTKMedical3",        
                       wrap_wxVTKMedical3);
    ADDOBJECTVAR_NAME( C_wrap_varfunction,   "wxVTKFrame",           
                       wrap_wxVTKFrame);

    WrapClass_wxVTKRenderWindowInteractor::
      AddVar_wxVTKRenderWindowInteractor(amiobject->GetContext());

  // Restore the object context
  Vars.SetObjectContext(previous_ocontext);
  // Add vtktools context to builtin
  obj->GetContext()->AddVar<AMIObject>( amiobject->GetName().c_str(), 
      amiobject,obj->GetContext());

}



//
BasicVariable::ptr wrap_wxVTKMedical3(ParamList* p)
{

    char functionname[] = "wxVTKMedical3";
    char description[]=" \n\
                       ";
    char parameters[] =" \n\
                       Parameters:\
                       \n\
                       ";

    InrImage* input;
    int   n=0;

    vtkImageData_ptr                vtk_image;
    //  printf("1 \n");

    if (!get_val_ptr_param<InrImage>(  input,      p, n)) HelpAndReturnVarPtr;
    vtk_image = (vtkImageData_ptr) (*input);

    // create the main application window
    wxMedical3Frame *frame = new wxMedical3Frame(vtk_image,_T("wxWindows-VTK App"),
            wxPoint(50, 50), wxSize(450, 340));
//    frame->SetInput(vtk_image);

    // and show it (the frames, unlike simple controls, are not shown when
    // created initially)
    frame->Show(TRUE);


    return BasicVariable::ptr();


} // wrap_wxVTKMedical3()


//
BasicVariable::ptr wrap_wxVTKFrame(ParamList* p)
{

  char functionname[] = "wxVTKFrame";
  char description[]=" \n\
                      ";
  char parameters[] =" wxFrame with a vtkWindowInteractor inside\n\
                      Parameters:\
                      Return: Returns a variable of type vtkRenderWindowInterator\
                      \n\
                      ";

  // create the main application window
  wxVTKFrame *vtkframe = new wxVTKFrame(_T("wxWindows-VTK App"),
          wxPoint(50, 50), wxSize(450, 340));
  vtkframe->Show(TRUE);
  wxVTKRenderWindowInteractor* renwininteract = vtkframe->GetRenderWindowInteractor();
  return AMILabType<wxVTKRenderWindowInteractor>::CreateVar(renwininteract);

} // wrap_wxVTKFrame()
