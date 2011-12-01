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
//#include "VarContexts.hpp"

//#include "LanguageBaseConfigure.h"
//LanguageBase_VAR_IMPORT VarContexts  Vars;

#include "wrap_MCamera.h"
#include "wrap_XPoints.h"
#include "wrap_MTCollection_Collection.h"
#include <math.h>

#ifndef WX_PRECOMP
    #include "wx/wx.h"
#endif
#include "wx/wx.h"
#include "wx/mstream.h"
#include "wx/stream.h"
#include "wrap_vtkMatrix4x4.h"
#include "wrap_wxBitmap.h"


extern Variable<int>::ptr nullvar;



/*
//---------------------------------------------------------
void AddWrapMT() {

  // Create mt context
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("mt");
  
  ADDLOCAL_OBJECTVAR_NAME( amiobject,C_wrap_varfunction, "GetImageMT",  GetImageMT);
  ADDLOCAL_OBJECTVAR_NAME( amiobject,C_wrap_varfunction, "GetStoreXpointMT",  GetStoreXpointMT);
  ADDLOCAL_OBJECTVAR_NAME( amiobject,C_wrap_varfunction, "FillGrid",  FillGrid);
  

  // Add classes to mt context
  wrap_mt_classes(amiobject->GetContext());

  // Add mt context to builtin
  Vars.GetBuiltinContext()->AddVar<AMIObject>( amiobject->GetName().c_str(),
      amiobject,Vars.GetBuiltinContext());

}
*/

/************************************************************/ 
/*                    GetImageMT                            */
/*      Read a 2D images from a MicronTracker camera        */
/************************************************************/
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
  
    //se solicitan las imagenes a mitad de tamaño
    pixelsr = (unsigned char *)raddr;
    pixelsl = (unsigned char *)laddr;
    
    //Cam resolution    
    int dimx= cam->getXRes();
    int dimy= cam->getYRes();
    unsigned char* data;
    data = (unsigned char *)malloc( (dimx*dimy*3)*sizeof(unsigned char) );

    //grey scale
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
    wxBitmap* bitmap = new wxBitmap(MTimage);
  
    double valor;
    //make sure correct image from param
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

 } // GetImageMT()



/************************************************************/ 
/*                  GetStoreXpointMT                        */
/*      Get Xpoints and store it in Collection class        */
/************************************************************/
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

    //Store detected Xpoints 
    xpointsCollection = new MTCollection::Collection(pXPoints->detectedXPoints(cam)); 

	  if (xpointsCollection->count() == 0) {
		  delete xpointsCollection; 
      return nullvar;
		  //return;
	  }

	  double x[3], y[3];
	  double x3,y3,z3;
	  int XPNum=1;
	  MTXPoint* XP;
    //Fill Collection
	  for (XPNum = 1; XPNum <= xpointsCollection->count(); XPNum++)
		{
		  XP = new MTXPoint(xpointsCollection->itemI(XPNum));
			XP->Position2D(&x[0], &y[0], &x[1], &y[1], &x[2], &y[2]);
			XP->Position3D(&x3, &y3, &z3);
			XP->setIndex(XPNum);
    }
    return AMILabType<MTCollection::Collection>::CreateVar(xpointsCollection);
 } // GetStoreXpointMT()


/************************************************************/ 
/*                    FillGrid                              */
/*      Process a frame a fill in the grid the pixels       */
/*      appropriate based on its transformation matrix.     */
/************************************************************/
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
                           Range to transform in grid coordenates V{x,y,z}\n\
                           Scale in [X,Y] pixel->cm\n\
                           Resolution:voxel tam\n\
                           Interpolation Grid Image 3D\n\
                           ";
                       
                
    InrImage* grid;
    InrImage* count_grid;
    InrImage* frame;
    vtkMatrix4x4* matrix;
    double* minrange,*scale;
    double voxeltam;
    int dimx;
    int dimy;
    int n=0;
    double count = 0;
    double actual_value = 0;
 
    if (!get_val_ptr_param<InrImage>(  grid,      p, n)) HelpAndReturnVarPtr;
    if (!get_val_ptr_param<vtkMatrix4x4>(  matrix,      p, n)) HelpAndReturnVarPtr;
    if (!get_val_ptr_param<InrImage>(  frame,      p, n)) HelpAndReturnVarPtr;
    if (!get_val_ptr_param<double>(  minrange,      p, n)) HelpAndReturnVarPtr;
    if (!get_val_ptr_param<double>(  scale,      p, n)) HelpAndReturnVarPtr;
    if (!get_val_param<double>(  voxeltam,      p, n)) HelpAndReturnVarPtr;
    if (!get_val_ptr_param<InrImage>(  count_grid,      p, n)) HelpAndReturnVarPtr;
     
    dimx = frame->DimX();
    dimy = frame->DimY();
     
    InrImageIteratorBase::ptr iterG = grid->CreateIterator(); 
    InrImageIteratorBase::ptr iterC = count_grid->CreateIterator(); 
    InrImageIteratorBase::ptr iterF = frame->CreateIterator();

    if((iterG == NULL) || (iterF == NULL)) HelpAndReturnVarPtr;
    int intensidad;
    iterG->InitBuffer();
    iterF->InitBuffer();
    double in[4],out[4];
    //coordenada homogénea
    in[2] = 0;
    in[3] = 1;
    int x2grid,y2grid,z2grid;
    //recorrer frame
    for(int i=0; i<dimy;i++){
      for(int j=0;j<dimx;j++) {
        
        //valor de la coordenada i*dimy+j
        intensidad = iterF->GetDoubleValue();
        
        in[0] = j * scale[0];
        in[1] = i * scale[1];

        //multiplicar coordenada actual de la imagen por la matriz de transformacion, ´descubrir a qué coordenada corresponde para la cámara
        matrix->MultiplyPoint(in,out);

        //mover las coordenadas contenidas en out en el rango del grid ya que el grid empieza en cero, escalar por la resolución (tam voxel)
        x2grid = floor((out[0]- minrange[0]) /voxeltam);
        y2grid = floor((out[1]- minrange[1])/voxeltam);
        z2grid = floor((out[2]- minrange[2])/voxeltam);
        
        //corregir posibles fugas de rango
        if(x2grid>(grid->DimX()-1)){
            printf("errorx_max %d:\n",x2grid);
           x2grid = grid->DimX() - 1;  
           
        }
        if(y2grid>(grid->DimY()-1)){
          printf("errory_max %d:\n",y2grid);
          y2grid = grid->DimY()-1;
          
        }
        if(z2grid>(grid->DimZ()-1)){
           printf("errorz_max %d:\n",z2grid);
          z2grid = grid->DimZ()-1;
         
        }
        if(x2grid<0){
          printf("errorx_min %d:\n",x2grid);
           x2grid = 0;
           
        }
        if(y2grid<0){
          printf("errory_min %d:\n",y2grid);
          y2grid = 0;
          
        }
        if(z2grid<0){
          printf("errorz_min %d:\n",z2grid);
          z2grid = 0;  
        }
        //check contador de accesos
        iterC->BufferPos( x2grid, y2grid, z2grid );
        count = iterC->GetDoubleValue();

        //Pintar en las coordenadas del grid obtenidas la intensidad 
        iterG->BufferPos( x2grid, y2grid, z2grid );
        
        if(count>0){
          actual_value = iterG->GetDoubleValue();
          //interpolar
          intensidad = (actual_value*count + intensidad)/(count+1);
          iterG->SetDoubleValue(intensidad);
        }
        else{
          iterG->SetDoubleValue(intensidad);
        }

        //aumentar el contador de accesos a esa posición        
        iterC->SetDoubleValue(count+1);
        
        (*iterF)++;   //es más rápido que el BufferPos

       }
  }
  return BasicVariable::ptr();

 } // FillGrid()