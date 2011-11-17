//
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
#include <inrimage.hpp>
#include "VarContexts.hpp"

extern VarContexts  Vars;

#include "addwrap_mt.h"
#include "wrap_MCamera.h"
#include "wrap_Cameras.h"
#include "wrapMT.h"

//---------------------------------------------------------
void AddWrapMT() {


  // Create mt context
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("mt");

  ADDLOCAL_OBJECTVAR_NAME( amiobject,C_wrap_varfunction, "GetImageMT",  GetImageMT);
  //ADDVAR_NAME( C_wrap_procedure, "GetImageMT",  GetImageMT);

  // Add classes to mt context
  wrap_mt_classes(amiobject->GetContext());

  // Add mt context to builtin
  Vars.GetBuiltinContext()->AddVar<AMIObject>( amiobject->GetName().c_str(),
      amiobject,Vars.GetBuiltinContext());

}


/** Read a 2D images from a MT camera **/
BasicVariable::ptr  GetImageMT(ParamList* p) {


    char functionname[] = "GetImageMT";
    char description[]=" \n\
                       Gets the 2D images from a MT camera. \n\
                       ";
    char parameters[] =" \n\
                       Parameters:\n\
                       left image\n\
                       right image\n\
                       camera object\n\
                       ";

    InrImage* left;
    InrImage* right;
    MCamera* cam;
    int n=0;
    
    unsigned char ** laddr;
    unsigned char ** raddr;
    
    if (!get_val_ptr_param<InrImage>(  left,      p, n));// HelpAndReturnNULL;
    if (!get_val_ptr_param<InrImage>(  right,      p, n));// HelpAndReturnNULL;
    if (!get_val_ptr_param<MCamera>(  cam,      p, n));// HelpAndReturnNULL;

    cam->getHalfSizeImages( &laddr, &raddr, cam->getXRes(), cam->getYRes() );

    InrImageIteratorBase::ptr iterR = right->CreateIterator(); 
    InrImageIteratorBase::ptr iterL = right->CreateIterator(); 
    for(int i=0; i<right->DimX();i++)
        for(int j=0;j<right->DimY();j++) {
            iterR->BufferPos(i,j,0);
            iterR->SetDoubleValue(laddr[i][j]);
            iterL->BufferPos(i,j,0);
            iterL->SetDoubleValue(laddr[i][j]);
          /*  left->SetBufferPos(i,j,0);
            left->SetValue(laddr[i,j]);*/

        }
    return BasicVariable::ptr();
 } // GetImageMT()
