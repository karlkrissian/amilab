//
// C++ Implementation: wrap_Ultrasound
//
// Description: 
//
//
// Author: Karl Krissian <krissian@dis.ulpgc.es>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//
/*
#include "wrap_Ultrasound.h"
#include <iomanip>
#include <cassert>
#include "boost/format.hpp"
#include "VarContexts.hpp"
#include "wrapfunctions.hpp"
#include "ami_class.h"
#include "ami_object.h"
#include "ami_function.h"

extern VarContexts  Vars;

extern Variable<int>::ptr nullvar;

//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<CIRPRemoteControl>::CreateVar( ParamList* p)
{
  WrapClass_Ultrasound::wrap_Ultrasound construct;
  return construct.CallMember(p);
}
//
// static member for creating a variable from a pointer to Ultrasound
//
Variable<AMIObject>::ptr WrapClass_Ultrasound::CreateVar( CIRPRemoteControl* sp)
{
   boost::shared_ptr<CIRPRemoteControl> _obj_ptr(sp);
  return 
    WrapClass<CIRPRemoteControl>::CreateVar(
      new WrapClass_Ultrasound(_obj_ptr));
}


//---------------------------------------------------
//  Ultrasound Constructor
//---------------------------------------------------
void  WrapClass_Ultrasound::
        wrap_Ultrasound::SetParametersComments() 
{
  return_comments = "A wrapped Ultrasound object.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_Ultrasound::
                    wrap_Ultrasound::CallMember( ParamList* p)
{
 
   boost::shared_ptr<CIRPRemoteControl> usound_ptr(new CIRPRemoteControl());
  return WrapClass<CIRPRemoteControl>::CreateVar(new WrapClass_Ultrasound(usound_ptr));
}

//---------------------------------------------------
//  Connect
//---------------------------------------------------
void WrapClass_Ultrasound::
      wrap_Connect::SetParametersComments() 
{
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_Ultrasound::
      wrap_Connect::CallMember( ParamList* p)
{
  boost::shared_ptr<CIRPRemoteControl> s(this->_objectptr->GetObj());
 // s->Connect();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Disconnect
//---------------------------------------------------
void WrapClass_Ultrasound::
      wrap_Disconnect::SetParametersComments() 
{
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_Ultrasound::
      wrap_Disconnect::CallMember( ParamList* p)
{
  boost::shared_ptr<CIRPRemoteControl> s(this->_objectptr->GetObj());
//  s->Disconnect();
  return BasicVariable::ptr();
}


//---------------------------------------------------
//  GetImageUltrasound
//---------------------------------------------------
void WrapClass_Ultrasound::
      wrap_GetImageUltrasound::SetParametersComments() 
{
  return_comments = "2D ultrasound image";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_Ultrasound::
      wrap_GetImageUltrasound::CallMember( ParamList* p)
{
  boost::shared_ptr<CIRPRemoteControl> s(this->_objectptr->GetObj());
  int n=0;
  return BasicVariable::ptr();

}
*/
#include "stdafx.h"
#include "paramlist.h"
#include <inrimage.hpp>
#include "VarContexts.hpp"
#include <Resource.h>
extern VarContexts  Vars;
#include "addwrap_us.h"
#include "wrap_CIRPRemoteControl.h"
#include "wrap_Ultrasound.h"
/*#include "wx/msw/window.h"
#include "wx/dlimpexp.h"*/


extern Variable<int>::ptr nullvar;


//---------------------------------------------------------
void AddWrapUS() {



  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("CIRPRemoteControl");

  
  ADDLOCAL_OBJECTVAR_NAME( amiobject,C_wrap_varfunction, "Initialize",  Initialize);
  
  

  // Add classes to us context
  wrap_us_classes(amiobject->GetContext());

  // Add us context to builtin
  Vars.GetBuiltinContext()->AddVar<AMIObject>( amiobject->GetName().c_str(),
      amiobject,Vars.GetBuiltinContext());

}


/** Initialize sockets and ultrasound machine **/
BasicVariable::ptr  Initialize(ParamList* p) {


    char functionname[] = "Initialize";
    char description[]=" \n\
                       Initialize sockets and ultrasound machine\n\
                       ";
    char parameters[] =" \n\
                       Parameters:\
                       \n\
                       CIRPRemoteControl Object\n\
                       ";

  int n=0;
  CIRPRemoteControl* m_rc;
  if (!get_val_ptr_param<CIRPRemoteControl>(  m_rc,      p, n)) HelpAndReturnVarPtr;

   // initialize sockets de ulrasonix
	if (!AfxSocketInit())
	{
		AfxMessageBox(IDP_SOCKETS_INIT_FAILED);
		//return FALSE;
	}

	AfxEnableControlContainer();

  //Inicializar API máquina ultrasonidos
 /* if (!m_rc->Initialize((HWND)GetHWND()))
		printf("Éxito al inicializar\n");      
  else
    printf("Error al inicializar\n");

    return BasicVariable::ptr();*/
return BasicVariable::ptr(); //prueba para ver si compila
 } // GetImageMT()




