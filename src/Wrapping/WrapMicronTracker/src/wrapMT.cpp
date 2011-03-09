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
                       Gets the 2D images from a MT camera\n\
                       ";
    char parameters[] =" \n\
                       Parameters:\
                       \n\
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
    unsigned char *pixelsr,*pixelsl;
    
    if (!get_val_ptr_param<InrImage>(  left,      p, n)) HelpAndReturnVarPtr;
    if (!get_val_ptr_param<InrImage>(  right,      p, n)) HelpAndReturnVarPtr;
    if (!get_val_ptr_param<MCamera>(  cam,      p, n)) HelpAndReturnVarPtr;
    if(!cam->getImages( &laddr, &raddr )) printf("Error in obtain images \n");

    InrImageIteratorBase::ptr iterR = right->CreateIterator(); 
    InrImageIteratorBase::ptr iterL = left->CreateIterator();

    if((iterR == NULL) || (iterL == NULL)) HelpAndReturnVarPtr;
    if((laddr == NULL) || (raddr == NULL)) HelpAndReturnVarPtr;
    printf("Dimensiones de las imagenes leidas: %d filas - %d columnas \n",right->DimY(),right->DimX());
    // x COLUMNAS - y FILAS
    printf("Dimensiones de las imagenes camara: %d filas- %d  columnas\n",cam->getYRes(),cam->getXRes());
   
    //se solicitan las imagenes a mitad de tamaño
    pixelsr = (unsigned char *)raddr;
    pixelsl = (unsigned char *)laddr;
    
    //Cam resolution    
    int dimx= cam->getXRes();
    int dimy= cam->getYRes();

    double valor;

    if (
          (left->GetFormat()  == WT_UNSIGNED_CHAR)&&
          (left->DimX()       == dimx) &&
          (left->DimY()       == dimy) &&
          (left->DimZ()       == 1) &&
          (left->GetVDim()    == 1) &&
          (right->GetFormat() == WT_UNSIGNED_CHAR) &&
          (right->DimX()      == dimx) &&
          (right->DimY()      == dimy) &&
          (right->DimZ()      == 1) &&
          (right->GetVDim()   == 1) 
       ) 
    {
      size_t size = dimx*dimy;
      memcpy(left->GetData(), pixelsl,size);
      memcpy(right->GetData(),pixelsr,size);

    } else {

      printf("dimensiones  %d filas %d columnas\n",dimy,dimx);
      iterR->InitBuffer();
      iterL->InitBuffer();

      for(int i=0; i<dimy;i++)
        for(int j=0;j<dimx;j++) {
          //Right image
          //iterR->BufferPos(j,i,0);
          valor = (double)*(pixelsr+(i*dimx)+j);
          iterR->SetDoubleValue(valor);
          //Left image
          //iterL->BufferPos(j,i,0);
          valor = (double)*(pixelsl+(i*dimx)+j);
          iterL->SetDoubleValue(valor);

          (*iterR)++;
          (*iterL)++;
   
           
              //iterR->SetDoubleValue((double)laddr[i][j]);
             
              //iterL->BufferPos(i,j,0);
             
              //iterL->SetDoubleValue((double)laddr[i][j]);
   
            /*  left->SetBufferPos(i,j,0);
              left->SetValue(laddr[i,j]);*/

          }
    }

    return BasicVariable::ptr();
 } // GetImageMT()
