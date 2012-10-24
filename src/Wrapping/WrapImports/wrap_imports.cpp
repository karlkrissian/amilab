//
// C++ Implementation: wrap_imports
//
// Description: 
// Description:
//
//
// Author: Karl Krissian <>, (C) 2009
//
// Copyright: See COPYING file that comes with this distribution
//
//



#include "AMILabConfig.h"

#ifdef AMI_WRAP_MICRONTRACKER
  //#include "wrap_Ultrasound.h"
  #include "addwrap_us.h"
#endif


#include "paramlist.h"
#include "wrapfunctions.hpp"

// needed to allow NULL pointer parameter
extern Variable<int>::ptr nullvar;
extern bool CheckNullVar(ParamList* _p, int _n);

//#include "wrapfunction_class.h"
#include "VarContexts.hpp"
//#include "wrapfunctions_draw.h"
#include "wrap_imports.h"
#include "ami_class.h"
#include "ami_object.h"
//#include "wrap_imagedraw.h"

#include "Variable_string.h"
#include "wrap_MainFrame.h"
#include "wrap_wxDrawingWindow.h"

#include "addwrap_common.h"

#include "wrapSystem.h"
#include "wrapITK.h"
#include "wrapAMIFluid.h"
#include "wrapFilters.h"
#include "wrap_wxsamples.h"
#include "wrap_wxfunctions.h"


#include "wrap_parampanel.h"
#include "wrap_varlist.h"
#include "wrap_varvector.h"
#include "wrap_File.h"


#include "addwrap_wx.h"
#include "addwrap_algorithms.h"

// Includes and declarations needed for language
#include "addwrap_language.h"

#ifndef VarContexts_declared
  #define VarContexts_declared
  AMI_DECLARE_TYPE(VarContexts);
#endif

#ifdef AMI_WRAP_MICRONTRACKER
  #include "addwrap_mt.h"
  #include "wrapMT.h"
#endif

#include "wrap_vtkLevelSets.h"

#include "wrap_wxEditor.h"

#include "MainFrame.h"

#include "wrap_ReadRawImages.h"
//#include "wrap_amiImageExtent.h"
#include "wrap_SurfacePoly.h"
#include "wrap_DessinImage.h"


#include "wrap_Viewer3D.h"
#include "wrap_GLTransfMatrix.h"

#include "wrap_dwControlPoint.h"
#include "wrap_dwCurve.h"
#include "wrap_dwControlledCurve.h"

#include "wrap_RGBTransformComponent.h"
#include "wrap_RGBTransformHSV.h"
#include "wrap_RGBTransformInc.h"
#include "wrap_RGBTransformGamma.h"

  
#include "wrap_stdvector.h"

#ifndef BasicVariable_declared
  #define BasicVariable_declared
  AMI_DECLARE_TYPE(BasicVariable);
#endif

#include "wrapVTK.h"
#include "wrapVTKTools.h"
#include "wrapWxVTK.h"
#include "wrap_wxApp.h"
#include "wrap_wxConfigBase.h"
//#include "wrap_TestTemplateClass__LT__int__GT__.h"

#include "LanguageBaseConfigure.h"
LanguageBase_VAR_IMPORT VarContexts  Vars;

#include "AMILabConfigure.h"

AMILab_VAR_IMPORT MainFrame*  GB_main_wxFrame;
AMILab_VAR_IMPORT wxConfig*   GB_Config;
AMILab_VAR_IMPORT wxApp*      GB_wxApp;
extern std::string  GB_cmdline;


/**
 * Default wrapping
 */
void AddWrapImports()
{

  // Language
  {
    // Create new instance of the class
    AMIObject::ptr amiobject(new AMIObject);
    amiobject->SetName("Language");

    // Add Wrapped classes and functions
    AddWrapLanguage(  amiobject);
    AddWrapAmilab(    amiobject);
    AddWrapSystem(    amiobject);

    // Add context to builtin as 'default' context
    Vars.GetBuiltinContext()->AddVar<AMIObject>( amiobject->GetName().c_str(), 
                                                 amiobject,
                                                 Vars.GetBuiltinContext());
    Vars.GetBuiltinContext()->AddDefault(amiobject->GetContext());
  }

  // Graphical Interface
  {
    // Create new instance of the class
    AMIObject::ptr amiobject(new AMIObject);
    amiobject->SetName("Interface");

    // Add Wrapped classes and functions
    AddWrapDessinImage( amiobject);
    AddWrapViewer3D(    amiobject);

    WrapClass_wxDrawingWindow::AddVar_wxDrawingWindow(amiobject->GetContext());
    WrapClass_ParamPanel     ::AddVar_ParamPanel     (amiobject->GetContext());

    // Color Transforms
    WrapClass_RGBTransformComponent::AddVar_RGBTransformComponent( amiobject->GetContext());
    WrapClass_RGBTransformHSV      ::AddVar_RGBTransformHSV( amiobject->GetContext());
    WrapClass_RGBTransformInc      ::AddVar_RGBTransformInc( amiobject->GetContext());
    WrapClass_RGBTransformGamma    ::AddVar_RGBTransformGamma( amiobject->GetContext());

    // Add context to builtin as 'default' context
    Vars.GetBuiltinContext()->AddVar<AMIObject>( amiobject->GetName().c_str(), 
                                                 amiobject,
                                                 Vars.GetBuiltinContext());
    Vars.GetBuiltinContext()->AddDefault(amiobject->GetContext());
  }

  // Algorithms
  {
    // Create new instance of the class
    AMIObject::ptr amiobject(new AMIObject);
    amiobject->SetName("Algorithms");

    // Add Wrapped classes and functions
    AddWrapAlgorithms(  amiobject);
    AddWrapFilters(     amiobject);

    WrapClass_vtkLevelSets  ::AddVar_vtkLevelSets(amiobject->GetContext());

    // Add context to builtin as 'default' context
    Vars.GetBuiltinContext()->AddVar<AMIObject>( amiobject->GetName().c_str(), 
                                                 amiobject,
                                                 Vars.GetBuiltinContext());
    Vars.GetBuiltinContext()->AddDefault(amiobject->GetContext());
  }
  
  // Structures
  {
    // Create new instance of the class
    AMIObject::ptr amiobject(new AMIObject);
    amiobject->SetName("DataStructures");

    // Add Wrapped classes and functions
    AddWrapIO(              amiobject);
    //AddWrapImage(           amiobject);
    AddWrapSurface(         amiobject);
    AddWrapGLTransfMatrix(  amiobject);
    AddWrapBasicTypes(      amiobject);

    // Add context to builtin as 'default' context
    Vars.GetBuiltinContext()->AddVar<AMIObject>( amiobject->GetName().c_str(), 
                                                 amiobject,
                                                 Vars.GetBuiltinContext());
    Vars.GetBuiltinContext()->AddDefault(amiobject->GetContext());
  }

  // Libraries
  {
    // Create new instance of the class
    AMIObject::ptr amiobject(new AMIObject);
    amiobject->SetName("Libraries");

    // Add Wrapped classes and functions
    AddWrapWxWidgets( amiobject);
    AddWrapWXSamples( amiobject);

    AddWrapVTK(       amiobject);
    AddWrapVTKTools(  amiobject);
    AddWrapWxVTK(     amiobject);
    AddWrapITK(       amiobject);
    AddWrapFluid(     amiobject);

    #ifdef AMI_WRAP_MICRONTRACKER
      AddWrapMicronTracker();
    #endif
    #ifdef AMI_WRAP_MICRONTRACKER
      AddWrapUltrasound();
    #endif

    // Add context to builtin as 'default' context
    Vars.GetBuiltinContext()->AddVar<AMIObject>( amiobject->GetName().c_str(), 
                                                 amiobject,
                                                 Vars.GetBuiltinContext());
    Vars.GetBuiltinContext()->AddDefault(amiobject->GetContext());
  }

  // Others
  {
    // Create new instance of the class
    AMIObject::ptr amiobject(new AMIObject);
    amiobject->SetName("Others");

    // Add context to builtin as 'default' context
    Vars.GetBuiltinContext()->AddVar<AMIObject>( amiobject->GetName().c_str(), 
                                                 amiobject,
                                                 Vars.GetBuiltinContext());
    Vars.GetBuiltinContext()->AddDefault(amiobject->GetContext());
  }

}

void AddWrapWxWidgets(AMIObject::ptr& obj)
{

  // Create a new context (or namespace)
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wx");

  // Add classes to wx context
  wrap_wx_classes(  amiobject->GetContext());
  wrap_wx_functions(amiobject->GetContext());

  ADDLOCAL_OBJECTVAR_NAME(amiobject,C_wrap_varfunction,
                          "LaunchDefaultBrowser",
                          wrap_LaunchDefaultBrowser);

  ADDLOCAL_OBJECTVAR_NAME(amiobject,C_wrap_varfunction,"FromWxString", wrap_FromWxString);

  // Add wx context to builtin
  obj->GetContext()->AddVar<AMIObject>( amiobject->GetName().c_str(),
      amiobject,obj->GetContext());

}

//---------------------------------------------
void AddWrapAlgorithms(AMIObject::ptr& obj)
{

  // Create a new context (or namespace)
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("algorithms");

  // Add classes to wx context
  wrap_algorithms_classes(amiobject->GetContext());
  wrap_algorithms_functions(amiobject->GetContext());

  // Add wx context to builtin
  obj->GetContext()->AddVar<AMIObject>( amiobject->GetName().c_str(), 
      amiobject,obj->GetContext());

  obj->GetContext()->AddDefault(amiobject->GetContext());
  
}


//---------------------------------------------
BasicVariable::ptr wrap_GetObjPointerAsString( ParamList* p)
{
  char functionname[] = "GetObjPointerAsString";
  char description[]=" \n\
                    returns a string representation of the object pointer\n\
                    ";
    char parameters[] =" \n\
                       Parameters:\n\
                       variable\n\
                       Return:\n\
                       Returns a variable of type string\n\
                       ";

  if (!p) HelpAndReturnVarPtr;
  BasicVariable::ptr val;
  std::string res;
  if (p->GetNumParam()==1) val = p->GetParam(0);
  if (val.get()) {
    // Convert to AMIObject
    Variable<AMIObject>::ptr newvar (boost::dynamic_pointer_cast<Variable<AMIObject> >(val));
// TODO Create virtual class member to obtain pointer information ...
/*    if (newvar.get()) {
      res = GetPointerAsString(newvar->Pointer()->GetWrappedObject().get());
    }*/
  }
  return AMILabType<std::string>::CreateVar(res);
}

//---------------------------------------------
BasicVariable::ptr wrap_WrapVariable( ParamList* p)
{
  char functionname[] = "WrapVariable";
  char description[]=" \n\
                    Convert a variable to a variable of variable\n\
                    ";
    char parameters[] =" \n\
                       Parameters:\n\
                       variable\n\
                       Return:\n\
                       Returns a variable of type Variable<BasicVariable>\n\
                       ";

  if (!p) HelpAndReturnVarPtr;
//  int n=0;
  BasicVariable::ptr val;
  if (p->GetNumParam()==1) val = p->GetParam(0);
  if (val.get()) {
    BasicVariable::ptr res = AMILabType<BasicVariable>::CreateVarFromSmtPtr(val);
    return res;
  }
  return BasicVariable::ptr();
}



//---------------------------------------------
void AddWrapLanguage(AMIObject::ptr& obj)
{


// Create a new context (or namespace)
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("language");

  // Add classes to language context
  // PROBLEM WITH DOUBLE DEFINITION OF WrapClass<AMIObject>::name_as_string() ???
  wrap_language_classes(amiobject->GetContext());

  //std::cout << "wrap import Vars : " << &Vars << std::endl;
  // Add Vars: all the variable contexts
  // create from the pointer, without deleter ...
  BasicVariable::ptr vars = AMILabType<VarContexts>::CreateVar(&Vars,true);
  amiobject->GetContext()->AddVar("Vars", vars, Vars.GetBuiltinContext());

  ADDLOCAL_OBJECTVAR_NAME(amiobject,C_wrap_varfunction,
                          "WrapVariable",
                          wrap_WrapVariable);

  ADDLOCAL_OBJECTVAR_NAME(amiobject,C_wrap_varfunction,
                          "GetObjPointerAsString",
                          wrap_GetObjPointerAsString);

  // Add context to obj context
  obj->GetContext()->AddVar<AMIObject>( amiobject->GetName().c_str(), 
      amiobject,obj->GetContext());



}


#ifdef AMI_WRAP_MICRONTRACKER
  void AddWrapMicronTracker()
  {
    AddWrapMT();
  }
  void AddWrapUltrasound()
  {
      // Create us context
      AMIObject::ptr amiobject(new AMIObject);
      amiobject->SetName("us");
      // Add classes to mt context
      wrap_us_classes(amiobject->GetContext());

      // Add mt context to builtin
      Vars.GetBuiltinContext()->AddVar<AMIObject>( amiobject->GetName().c_str(),
      amiobject,Vars.GetBuiltinContext());
      //AddWrapUS();

  }
#endif

/*#ifdef AMI_WRAP_MICRONTRACKER
  void AddWrapUltrasound()
  {
    WrapClass_Ultrasound::AddVar_Ultrasound( Vars.GetBuiltinContext());
  }
#endif*/


void AddWrapAmilab(AMIObject::ptr& obj)
{

  Variables::ptr context = obj->GetContext();
  
  BasicVariable::ptr vartrue  = AMILabType<bool>::CreateVar(true);
  BasicVariable::ptr varfalse = AMILabType<bool>::CreateVar(false);

  context->AddVar( "true",vartrue,context);
  context->AddVar( "false",varfalse,context);

  // NULL variable
  context->AddVar( "NULL",nullvar,context);

  // Create new instance of the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("ami");

  WrapClass_wxEditor::AddVar_wxEditor( amiobject->GetContext());

  // Add the MainFrame as an object
  BasicVariable::ptr mainframe_var = WrapClass_MainFrame::CreateVar(GB_main_wxFrame);
  amiobject->GetContext()->AddVar("MainFrame", mainframe_var, amiobject->GetContext());

  // create variable, but without deleter !!!
  BasicVariable::ptr config_var = AMILabType<wxConfigBase>::CreateVar(GB_Config,true);
  amiobject->GetContext()->AddVar("AMILabConfig", config_var, amiobject->GetContext());

  // Add the App as an object
  BasicVariable::ptr app_var = AMILabType<wxApp>::CreateVar(GB_wxApp,true);
  amiobject->GetContext()->AddVar("wxApp", app_var, amiobject->GetContext());
  
  // Add the command line as a string, with a reference to the global variable and no deleter
  BasicVariable::ptr cmdline_var = AMILabType<std::string>::CreateVar(&GB_cmdline,true);
  amiobject->GetContext()->AddVar("CommandLine", cmdline_var, amiobject->GetContext());
  
  WrapClass_dwControlPoint   ::AddVar_dwControlPoint(    amiobject->GetContext());
  WrapClass_dwCurve          ::AddVar_dwCurve(           amiobject->GetContext());
  WrapClass_dwControlledCurve::AddVar_dwControlledCurve( amiobject->GetContext());

  // 3. add the variables to this instance
  context->AddVar<AMIObject>( amiobject->GetName().c_str(),
      amiobject,context);


}

void AddWrapIO(AMIObject::ptr& obj)
{
  // Create new instance of the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("IO");

  AddVar_ReadRawImages2D(     amiobject->GetContext());
  AddVar_ReadRawImage3D(      amiobject->GetContext());
  AddVar_ReadRawVectImage3D(  amiobject->GetContext());

  // 3. add the variables to this instance
  obj->GetContext()->AddVar<AMIObject>( amiobject->GetName().c_str(),
    amiobject,
    obj->GetContext());
}

/*
//--------------------------------------------
void AddWrapImage(AMIObject::ptr& obj)
{
  // Create new instance of the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("image");

  AddVar_ImageExtent(     amiobject->GetContext());

  // 3. add the variables to this instance
  obj->GetContext()->AddVar<AMIObject>( amiobject->GetName().c_str(),
    amiobject,
    obj->GetContext());
}
*/

//--------------------------------------------
void AddWrapSurface(AMIObject::ptr& obj)
{
  WrapClass_SurfacePoly::AddVar_SurfacePoly( obj->GetContext());
}

//--------------------------------------------
void AddWrapDessinImage(AMIObject::ptr& obj)
{
  WrapClass_DessinImage::AddVar_DessinImage( obj->GetContext());
}

//--------------------------------------------
void AddWrapViewer3D(AMIObject::ptr& obj)
{
  WrapClass_Viewer3D::AddVar_Viewer3D( obj->GetContext());
}

//--------------------------------------------
void AddWrapGLTransfMatrix(AMIObject::ptr& obj)
{
  WrapClass_GLTransfMatrix::AddVar_GLTransfMatrix( obj->GetContext());
}

//--------------------------------------------
void AddWrapBasicTypes(AMIObject::ptr& obj)
{

  WrapClass_VarVector::AddVar_VarVector( obj->GetContext());
  wrap_common_classes(obj->GetContext());
  

  BasicVariable::ptr std_cout_var = 
    AMILabType<std::ostream>::CreateVar(&std::cout,true);
  obj->GetContext()->AddVar("cout", std_cout_var, obj->GetContext());

  BasicVariable::ptr std_cerr_var = 
    AMILabType<std::ostream>::CreateVar(&std::cerr,true);
  obj->GetContext()->AddVar("cerr", std_cerr_var, obj->GetContext());
  
  BasicVariable::ptr std_clog_var = 
    AMILabType<std::ostream>::CreateVar(&std::clog,true);
  obj->GetContext()->AddVar("clog", std_clog_var, obj->GetContext());

  WrapClass_File::AddVar_File( obj->GetContext());

  
}

