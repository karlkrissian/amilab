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

#include "LanguageBaseConfigure.h"
LanguageBase_VAR_IMPORT VarContexts  Vars;

#include "addwrap_mt.h"
#include "wrap_MCamera.h"
#include "wrap_Cameras.h"
#include "wrap_XPoints.h"
#include "wrap_MTXPoint.h"
#include "wrapMT.h"
#include "wrap_MTCollection_Collection.h"
#include "wrap_wxBitmap.h"
#include <math.h>

#ifndef WX_PRECOMP
    #include "wx/wx.h"
#endif
#include "wx/wx.h"
#include "wx/mstream.h"
#include "wx/stream.h"
#include "wrap_vtkMatrix4x4.h"


extern Variable<int>::ptr nullvar;



//---------------------------------------------------------
void AddWrapMT() {


  // Create mt context
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("mt");

  
  ADDLOCAL_OBJECTVAR_NAME( amiobject,C_wrap_varfunction, "GetImageMT",  GetImageMT);
  ADDLOCAL_OBJECTVAR_NAME( amiobject,C_wrap_varfunction, "GetStoreXpointMT",  GetStoreXpointMT);
  ADDLOCAL_OBJECTVAR_NAME( amiobject,C_wrap_varfunction, "Get2DXpointMT",  Get2DXpointMT);
  ADDLOCAL_OBJECTVAR_NAME( amiobject,C_wrap_varfunction, "FillGrid",  FillGrid);
  

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
    
    //wxInitAllImageHandlers();
    if (!get_val_ptr_param<InrImage>(  left,      p, n)) HelpAndReturnVarPtr;
    if (!get_val_ptr_param<InrImage>(  right,      p, n)) HelpAndReturnVarPtr;
    if (!get_val_ptr_param<MCamera>(  cam,      p, n)) HelpAndReturnVarPtr;
    if(!cam->getImages( &laddr, &raddr )) printf("Error in obtain images \n");

    InrImageIteratorBase::ptr iterR = right->CreateIterator(); 
    InrImageIteratorBase::ptr iterL = left->CreateIterator();

    if((iterR == NULL) || (iterL == NULL)) HelpAndReturnVarPtr;
    if((laddr == NULL) || (raddr == NULL)) HelpAndReturnVarPtr;
  //  printf("Dimensiones de las imagenes leidas: %d filas - %d columnas \n",right->DimY(),right->DimX());
    // x COLUMNAS - y FILAS
  //  printf("Dimensiones de las imagenes camara: %d filas- %d  columnas\n",cam->getYRes(),cam->getXRes());
   
    //se solicitan las imagenes a mitad de tamaño
    pixelsr = (unsigned char *)raddr;
    pixelsl = (unsigned char *)laddr;
    
    //Cam resolution    
    int dimx= cam->getXRes();
    int dimy= cam->getYRes();
    //unsigned char  data[307200];
      unsigned char* data;
//memcpy(data, pixelsl,(dimx*dimy));
data = (unsigned char *)malloc( (dimx*dimy*3)*sizeof(unsigned char) );


//for (int i =0;i<307200;i++) {if(pixelsl[i]>256 || pixelsl[i]< 0) printf("%d/n",pixelsl[i]);}
//for (int i =0;i<50;i++)  printf("%d/n",pixelsl[i]);
//for (int i =0;i<307200;i++) {if(data[i]>256 || data[i]< 0) printf("%d\n",data[i]);}
//es escala de grises
int j =0;
for (int i =0;i<(dimx*dimy);i++) {
  data[j++]= pixelsl[i];
  data[j++]= pixelsl[i];
  data[j++]= pixelsl[i];
}
wxImage MTimage(dimx,dimy);
//setdata exige que los datos tengan tamaño The data given must have the size (width*height*3) 
MTimage.SetData(data);
MTimage.Rescale(320,240);
//MTimage.SaveFile("C:\\prueba.bmp",wxBITMAP_TYPE_BMP);
wxBitmap* bitmap = new wxBitmap(MTimage);
    //wxImage MTimage(dimx,dimy,pixelsl,true);

  //    MTimage.SaveFile("C:\\prueba.pgm",wxBITMAP_TYPE_PNM ); EXAMPLE
  //  size_t size = dimx*dimy;
      //wxMemoryInputStream InputMemStream(pixelsl, size); 
      //wxImage USimage(InputMemStream);
//wxBitmap *bitmap1 = new wxBitmap(data[0],dimx,dimy);
//wxBitmap *bitmap1 = new wxBitmap(
//bitmap1->SaveFile("C:\\prueba.pgm",wxBITMAP_TYPE_PNM);
 //     wxImage MTimage(dimx,dimy,pixelsl,true);
//      MTimage.SaveFile("C:\\prueba.pgm",wxBITMAP_TYPE_PNM );
      //wxBitmap* bitmap = new wxBitmap(MTimage,1);
//bitmap->SaveFile("C:\\prueba.jpeg",wxBITMAP_TYPE_BMP);
  //  unsigned char * data = new unsigned char[dimx*dimy];
//int a = 2; //borrar esto despues punto de control
   // wxImage* MTimage = new wxImage(dimx,dimy,pixelsl,true);
   // memcpy(data, pixelsl,size);
   //wxImage* MTimage = new wxImage();
//wxImage image(dimx,dimy,data);
//wxImage* image2 = new wxImage(dimx,dimy,data);
//wxImage image3(dimy,dimx,data);
//wxImage* image4 = new wxImage(dimy,dimx,data);
//wxBitmap *bitmap1 = new wxBitmap((const char*)pixelsl,dimx,dimy);
//bitmap1->SaveFile("C:\\prueba.jpeg",wxBITMAP_TYPE_JPEG);
//wxBitmap *bitmap2 = new wxBitmap(data[0],wxBITMAP_TYPE_BMP ,dimx,dimy)
//wxBitmap *bitmap3 = new wxBitmap(bla)
  
  //  wxBitmap* bitmap = new wxBitmap(wxImage(dimx,dimy,data));

  
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

     // printf("dimensiones  %d filas %d columnas\n",dimy,dimx);
      iterR->InitBuffer();
      iterL->InitBuffer();

      for(int i=0; i<dimy;i++)
        for(int j=0;j<dimx;j++) {
          //Right image
          valor = (double)*(pixelsr+(i*dimx)+j);
          iterR->SetDoubleValue(valor);
          //Left image
          valor = (double)*(pixelsl+(i*dimx)+j);
          iterL->SetDoubleValue(valor);

          (*iterR)++;
          (*iterL)++;
   
           


          }
    }

  return WrapClass_wxBitmap::CreateVar(bitmap);
//    return BasicVariable::ptr();
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
  //  printf("handle xpoints %d",pXPoints->detectedXPoints(cam));
    //Store detected Xpoints 
    xpointsCollection = new MTCollection::Collection(pXPoints->detectedXPoints(cam)); 
  //  printf(" puntos count %d\n",xpointsCollection->count());

	  if (xpointsCollection->count() == 0) {
		  delete xpointsCollection; 
    //  printf("Empty Collection \n");
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
     // printf("XPoints detected  %f %f %f \n",x3,y3,z3);
      // TODO guardar los Xpoints detectados en fichero?
    }
    return AMILabType<MTCollection::Collection>::CreateVar(xpointsCollection);
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
     // printf("Empty Collection \n");
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



BasicVariable::ptr  FillGrid(ParamList* p) {


    char functionname[] = "FillGrid";
    char description[]=" \n\
                       Fill the volumen grid\n\
                       ";

    char parameters[] =" \n\
                          Parameters:\
                          \n\
                           Grid-Image 3D\n\
                           Transformation matrix\n\
                           Frame\n\
                           Range to transform\n\
                           ";
                       
             

    
    InrImage* grid;
    InrImage* frame;
    vtkMatrix4x4* matrix;
    double* minrange;
    int dimx;
    int dimy;
    int n=0;

    

    if (!get_val_ptr_param<InrImage>(  grid,      p, n)) HelpAndReturnVarPtr;
    if (!get_val_ptr_param<vtkMatrix4x4>(  matrix,      p, n)) HelpAndReturnVarPtr;
    if (!get_val_ptr_param<InrImage>(  frame,      p, n)) HelpAndReturnVarPtr;
    //if (!get_val_ptr_param<int>( dimx,      p, n)) HelpAndReturnVarPtr;
    //if (!get_val_ptr_param<int>(  dimy,      p, n)) HelpAndReturnVarPtr;
    if (!get_val_ptr_param<double>(  minrange,      p, n)) HelpAndReturnVarPtr;
    
   // printf("dimx %d \n",(*dimx));
   // printf("dimx %d \n",(*dimy));
    printf("range 0:%f,1:%f,2:%f \n",minrange[0],minrange[1],minrange[2]);
    printf("matrix %f %f %f %f \n %f %f %f %f \n %f %f %f %f \n %f %f %f %f ",matrix->GetElement(0,0),matrix->GetElement(0,1),matrix->GetElement(0,2),
matrix->GetElement(0,3),matrix->GetElement(1,0),matrix->GetElement(1,1),matrix->GetElement(1,2),matrix->GetElement(1,3),matrix->GetElement(2,0),matrix->GetElement(2,1),matrix->GetElement(2,2),
matrix->GetElement(2,3),matrix->GetElement(3,0),matrix->GetElement(3,1),matrix->GetElement(3,2),matrix->GetElement(3,3));

    
    
    //printf("dim x de la imagen %d\n",frame->DimX());
    //printf("dim y de la imagen %d\n",frame->DimY());
    dimx = frame->DimX();
    dimy = frame->DimY();

    printf("dim x del grid %d\n",grid->DimX());
    printf("dim y del grid %d\n",grid->DimY());
    printf("dim z del grid %d\n",grid->DimZ());
    
   // frame->Sauve("C:\\miimagen.bmp");ok

    
    InrImageIteratorBase::ptr iterG = grid->CreateIterator(); 
    InrImageIteratorBase::ptr iterF = frame->CreateIterator();

    if((iterG == NULL) || (iterF == NULL)) HelpAndReturnVarPtr;
    int intensidad;
    iterG->InitBuffer();
    iterF->InitBuffer();
    double in[4],out[4];
    in[2] = 0;
    in[3] = 1;
    int x2grid,y2grid,z2grid;
    for(int i=0; i<(dimy-1);i++){
      for(int j=0;j<(dimx-1);j++) {
        //recorrer frame
        //valor de la coordenada i*dimy+j
        intensidad = iterF->GetDoubleValue();
        
        in[0] = i;
        in[1] = j;

        //multiplicar coordenada actual de la imagen por la matriz de transformacion, ´descubrir a qué coordenada corresponde para la cámara
        matrix->MultiplyPoint(in,out);

        //mover las coordenadas contenidas en out en el rango del grid ya que el grid empieza en cero, escalar por la resolución (tam voxel)
        x2grid = floor((out[0]- minrange[0]) /0.2);
        y2grid = floor((out[1]- minrange[1])/0.2);
        z2grid = floor((out[2]- minrange[2])/0.2);
        
        //Pintar en las coordenadas del grid obtenidas la intensidad 
        iterG->BufferPos( x2grid, y2grid, z2grid );
        iterG->SetDoubleValue(intensidad);

        (*iterF)++;   

        }
  }

  return BasicVariable::ptr();

 } // FillGrid()