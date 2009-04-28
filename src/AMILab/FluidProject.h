

#ifndef _FLUIDPROJECT_H_
#define _FLUIDPROJECT_H_

#include "surface.hpp"
#include "inrimage.hpp"

namespace AMIFluid {

  //----------------------------------------------------------------------
  struct TNavig
    //     ------
  {
    // Parametros de navegacion:
    double RLAMB0, W;	// longitud, latitud del punto subsatellite (LAMBDA0 y PHI0) (leidos en grados).
    double DR;		// informe dist. del centro de la tierra al satelite / rayo(seccion) terrestre 
    double ALPHA0, ANU;	// angulos de tangage, de roulis del satelite leidos en grados 
    double ANAM;		// --
    double AX;		// indica si la foto es normal (=1) o a la inversa (= -1). 
    double XC, YC;		// coordenadas en puntos y lineas del centro de la imagen.
    double RAY;		// rayo(seccion) del disco terrestre sobre la imagen (en pixels).
  };
  
  
  InrImage* Func_ComputeAltitudes(InrImage* input, InrImage* coeff);
  InrImage* Func_Temp2Altitudes(InrImage* input);

  SurfacePoly* Func_CreateFlatMesh(InrImage* im, int orient=1);
  SurfacePoly* Func_CreateFlatMesh(InrImage* im, float minth, float maxth, int orient = 1);
  
  SurfacePoly* Func_vtkCreateFlatMesh(InrImage* im, float minth, float maxth);
  
  SurfacePoly* Func_CreateVolume(InrImage* im, float minth, float maxth,
  InrImage* lowpos, InrImage* highpos, InrImage* colors=NULL, float alpha=1.0);
  
  InrImage*    Func_Altitude2Position(InrImage* im, int type=2);
  
  InrImage*    Func_GeoCoordinates(InrImage* im, int type=2);
  
  //InrImage*    Func_EarthPosition(InrImage* im, int type);
  
  void         Func_ElevateMesh(SurfacePoly*, InrImage* im);
  
  void         Func_SetArrowParameters( float basesize, float headsize, float headpos);
  
  SurfacePoly* Func_CreateVectors(InrImage* alt1, InrImage* displ, InrImage* alt2,
                  int stepx, int stepy, float scale, int type=2, 
                  int vector_style=1 );

  /** Creates vectors in 3D from 3D displacement field **/
  SurfacePoly* Func_CreateVectors(
                  InrImage* displ,
                  int stepx, int stepy, int stepz, 
                  float scale,
                  int vector_style=1 );
  
  InrImage*    Func_ReadFlow( char* name);
  
  
  int InitCoordinates( int& i_offset, int& j_offset, TNavig& nav, std::string type);
  void COOCAR1(double RLAT, double RLONG, float& X, float& Y, int &LENVER, TNavig& nav_params);
  //void ColorMesh()
  
}

#endif
