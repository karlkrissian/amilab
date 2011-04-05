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
#include "wrap_XPoints.h"
#include "wrap_MTXPoint.h"
#include "wrapMT.h"
#include "wrap_MTCollection__NS__Collection.h"

extern Variable<int>::ptr nullvar;

struct reg2D{
  double Xl, Yl; //left image
  double Xr, Yr; //right image
  double Xm, Ym; //middle image
};
struct reg3D{
  double X, Y, Z;

};
class StoreXPoint{
  int count;

  StoreXPoint(int size);
  ~StoreXPoint();
  
  void ItemPos2D(int pos,double* Xl,double* Yl,double* Xr,double* Yr,double* Xm,double* Ym);
  void ItemPos3D(int pos,double* X,double* Y,double* Z);
};

//---------------------------------------------------------
void AddWrapMT() {


  // Create mt context
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("mt");

  
  ADDLOCAL_OBJECTVAR_NAME( amiobject,C_wrap_varfunction, "GetImageMT",  GetImageMT);
  ADDLOCAL_OBJECTVAR_NAME( amiobject,C_wrap_varfunction, "GetStoreXpointMT",  GetStoreXpointMT);
  ADDLOCAL_OBJECTVAR_NAME( amiobject,C_wrap_varfunction, "Get2DXpointMT",  Get2DXpointMT);
  

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


/** Get Xpoints and store it **/
BasicVariable::ptr  GetStoreXpointMT(ParamList* p) {


    char functionname[] = "GetStoreXpointMT";
    char description[]=" \n\
                       Gets Xpoints from current frame and store it\n\
                       ";
    char parameters[] =" \n\
                       Parameters:\
                       \n\
                       Xpoints object\n\
                       camera object\n\
                       Collection object\n\
                       ";

    XPoints* pXPoints = NULL;
    MCamera* cam = NULL;
    MTCollection::Collection* xpointsCollection;
    
    
    int n = 0; 
    
    
    if (!get_val_ptr_param<XPoints>(  pXPoints,      p, n)) HelpAndReturnVarPtr;
    if (!get_val_ptr_param<MCamera>(  cam,      p, n)) HelpAndReturnVarPtr;
   
    
    
    if (pXPoints == NULL) printf("Error leyendo xpoint\n");
    if (cam == NULL)printf("Error leyendo cam\n");
    int res = pXPoints->processFrame(NULL);
    if(res!= 0) printf("Error in process frame \n");
    printf("handle xpoints %d",pXPoints->detectedXPoints(cam));
    //Store detected Xpoints 
    xpointsCollection = new MTCollection::Collection(pXPoints->detectedXPoints(cam)); 
    printf(" puntos count %d\n",xpointsCollection->count());

	  if (xpointsCollection->count() == 0) {
		  delete xpointsCollection; 
      printf("Empty Collection \n");
      return nullvar;
		  //return;
	  }

	  double x[3], y[3];
	  double x3,y3,z3;
	  int XPNum=1;
	  MTXPoint* XP;

	  for (XPNum = 1; XPNum <= xpointsCollection->count(); XPNum++)
		{
		  XP = new MTXPoint(xpointsCollection->itemI(XPNum));
			XP->Position2D(&x[0], &y[0], &x[1], &y[1], &x[2], &y[2]);
			XP->Position3D(&x3, &y3, &z3);
			XP->setIndex(XPNum);
      //Imprimir los Xpoints detectados
      printf("XPoints detected  %f %f %f \n",x3,y3,z3);
      // TODO guardar los Xpoints detectados en fichero?
    }
    return WrapClass_MTCollection__NS__Collection::CreateVar(xpointsCollection);
 } // GetStoreXpointMT()

/** Get a 2D Xpoint **/
BasicVariable::ptr  Get2DXpointMT(ParamList* p) {


    char functionname[] = "Get2DXpointMT";
    char description[]=" \n\
                       Gets Xpoints from current frame and store it\n\
                       ";
    char parameters[] =" \n\
                       Parameters:\
                       \n\
                       Collection handle\n\
                       Xl,Yl,Xr,Yr,Xm,Ym\n\
                       Item position\n\
                       ";

    double* Xl,*Yl,*Xr,*Yr,*Xm,*Ym;
    
    int handle;
    int n = 0; 
    int itempos;
      
    if (!get_int_param(  handle,      p, n)) HelpAndReturnVarPtr;
    if (!get_val_ptr_param<double>(  Xl,      p, n)) HelpAndReturnVarPtr;
    if (!get_val_ptr_param<double>(  Yl,      p, n)) HelpAndReturnVarPtr;
    if (!get_val_ptr_param<double>(  Xr,      p, n)) HelpAndReturnVarPtr;
    if (!get_val_ptr_param<double>(  Yr,      p, n)) HelpAndReturnVarPtr;
    if (!get_val_ptr_param<double>(  Xm,      p, n)) HelpAndReturnVarPtr;
    if (!get_val_ptr_param<double>(  Ym,      p, n)) HelpAndReturnVarPtr;
    if (!get_int_param(  itempos,      p, n)) HelpAndReturnVarPtr; 
    
    MTCollection::Collection* xpointsCollection = new MTCollection::Collection(handle); 
    
    int c = xpointsCollection->count();
	  if (xpointsCollection->count() == 0) {
		  delete xpointsCollection; 
      printf("Empty Collection \n");
      return BasicVariable::ptr();
		  //return;
	  }
 
	  double x3,y3,z3;
	  MTXPoint* XP;
	  
		  XP = new MTXPoint(xpointsCollection->itemI(itempos));
			XP->Position2D(Xl, Yl, Xr, Yr, Xm, Ym);
      XP->Position3D(&x3, &y3, &z3);
			XP->setIndex(itempos);
    
    return BasicVariable::ptr();
 } // Get2DXpointMT()