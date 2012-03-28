
#include "FluidProject.h"
#include "Coordonnees.hpp"

#ifndef _WITHOUT_VTK_
#include "vtkImageData.h"
#include "vtkImageDataGeometryFilter.h"
#include "vtkClipPolyData.h"
#endif //  _WITHOUT_VTK_

#include <stdlib.h>
using namespace amilab;

#ifndef M_PI
# define M_PI           3.14159265358979323846  /* pi */
#endif

namespace AMIFluid {

// global variable
char FLUID_NAVIGATION_FILE[]= "nav_MSG_02_05_2003c0_63.dat";

// type 0: Atlantic
// type 1: Africa
// type 2: whole earth
static  char typestring[3][10] = {"NAtl","AfGG",""};

struct arrow_configuration {
  float base_size;
  float arrow_size;
  float arrow_position;
};

static arrow_configuration arrowconf = {0.05,0.1,0.85};

//----------------------------------------------------------------------
int ininav(char* archivo, TNavig &nav_params, bool print=false)
//  ------
{
	//	Fecha : 9/1/1990		Autor : Andre SZANTAI
	//	Maquina : Vax 8250, Station GPX II
	//	Traduccion de comentarios y codigo a C++: Miguel Garcia (13/11/2005)

	//	Programa de lectura de los parametros de navegacion. Repite una parte del 
	//	programa ININAV.FTN sobre el PDP 11.

	//	Todos estos parametros son reales. Los angulos ALPHA0, ANU, RLAMB0 y W 
	//	son leidos del fichero en grados y pasados a radianes.

	//	Parametros de navegacion:
	//		RLAMB0, W: longitud, latitud del punto subsatellite.
	//				(LAMBDA0 y PHI0) (leidos en grados).
	//		DR: informe dist. del centro de la tierra al satelite / 
	//			rayo(seccion) terrestre 
	//		ALPHA0, ANU: angulos de tangage, de roulis del satelite leidos en grados 
	//		AX: indica si la foto es normal (=1) o a la inversa (= -1). 
	//		XC, YC: coordenadas en puntos y lineas del centro de la imagen.
	//		RAY: rayo(seccion) del disco terrestre sobre la imagen (en pixels).

	double DRA = atan(1.) * 4 / 180;	// Factor de conversion de grados a radianes

	//    -----   lectura de los parametros de navegacion : -
	FILE* fd; 
	if (fd = fopen(archivo,"r"), !fd) {
	  // try with the environment variable
          char* fluid_nav_path = NULL;
          char fullname[256];
          fluid_nav_path = getenv("FLUID_NAV_PATH");
	  if (fluid_nav_path!=NULL) {
	    sprintf(fullname,"%s/%s",fluid_nav_path,archivo);
	    fd=fopen(fullname,"r");
	    if (!fd) {
	      printf("Error \t File %s could not be read \n",archivo);
	      return -1;
	    }
	  }	  
	}
	fscanf(fd,"%lf%lf%lf%lf", &nav_params.AX, &nav_params.RLAMB0, &nav_params.W, &nav_params.DR);
	fscanf(fd,"%lf%lf%lf", &nav_params.ALPHA0, &nav_params.ANU, &nav_params.ANAM);
	fscanf(fd,"%lf%lf%lf", &nav_params.XC, &nav_params.YC, &nav_params.RAY);
	fclose(fd);

	// Conversion a radianes:
	nav_params.ANU = nav_params.ANU * DRA;		
	nav_params.ALPHA0 = nav_params.ALPHA0 * DRA;
	nav_params.RLAMB0 = nav_params.RLAMB0 * DRA;	
	nav_params.W = nav_params.W * DRA;

	// Se muestran los parametros leidos:
	if (print)
	{
		printf(" ************* PARÁMETROS DE NAVEGACIÓN (angulos en grados) ************\n");
		printf("  LONGITUD = %6.2lf\tLATITUD = %6.2lf\tD/R = %16.2lf\n",nav_params.RLAMB0/DRA,nav_params.W/DRA,nav_params.DR);
		printf("  RAYO = %10.2lf\tXC = %11.2lf\tYC = %17.2lf\n",nav_params.RAY,nav_params.XC,nav_params.YC);
		printf("  ALPHA0 = %8.3lf\tANU = %10.3lf\tANAM = %15.10lf\n",nav_params.ALPHA0/DRA,nav_params.ANU/DRA,nav_params.ANAM);
		printf("  Sentido de la imagen: AX = %3.0lf.\n",nav_params.AX);
		printf(" ***********************************************************************\n");
	}

	return 0;
}


//----------------------------------------------------------------------
int coogeo(double X, double Y, double &FI, double &RLAMB, TNavig nav_params)
//  ------
{
	//	Fecha : 10/1/1990		Autor : Andre SZANTAI
	//	Maquina : la plupart
	//	Traduccion de comentarios y codigo a C++: Miguel Garcia (13/11/2005)

	//	COOGEO transforma las coordenadas cartesianas en coordenadas
	//	geograficas (longitud y latitud).
	//	¡Atencion! Este subprograma es una version modificada del COOGEO.FTN de 
	//	PDP 11. Todos los angulos leidos o calculados estan en RADIANES.
	//	Modificacion: ALFA corregido 13/4/1990.

	//	Parametros de navegacion:
	//		RLAMB0, W: longitud, latitud del punto subsatellite.
	//			(LAMBDA0 y PHI0) (en radianes).
	//		DR: informe dist. centro de la tierra al satelite / 
	//			rayo(seccion) terrestre 
	//		ALPHA0, ANU: angulos de tangage, de roulis del satelite leidos en radianes.
	//		AX: indica si la foto es normal (=1) o a la inversa (=-1.). 
	//		XC, YC: coordenadas en puntos y lineas del centro de la imagen.
	//		RAY: rayo(seccion) del disco terrestre sobre la imagen (en pixels).

	double RD = asin(1/nav_params.DR); // Ángulo con el que se ve la mitad de la tierra: TETA max.

	double TETA = nav_params.AX * (X-nav_params.XC) * RD / nav_params.RAY;	// TETA y ALPHA : angulos con los que 
	//#	ALPHA = (ANAM*Y-YC)*RD/RAY + ALPHA0	// es visto el punto a estudiar
	//					   	 con relacion al punto subsatelite.
	double ALPHA = (Y+nav_params.AX*nav_params.YC) * nav_params.ANAM * RD / nav_params.RAY + nav_params.ALPHA0;	// Correccion 13/4/1990
	double COTETA = cos(TETA);
	double SITETA = sin(TETA);
	double FI1,RLAMB1;

	if (ALPHA == 0.)
	{
		FI1 = 0.;
		RLAMB1 = SITETA * (nav_params.DR*COTETA - sqrt(1-nav_params.DR*nav_params.DR*SITETA*SITETA));
	}
	else
	{
		double COSALF = cos(ALPHA);
		double SINALF = sin(ALPHA);
		double PROD = nav_params.DR*COTETA*COSALF;
		double A = PROD*PROD - nav_params.DR*nav_params.DR + 1;
		if (A < 0.) // Se controla si A es negativa (por SQRT)
		{
			FI = 0.;
			RLAMB = 0.;
			//printf("Resultado no significativo. Posiblemente el punto se encuentra fuera de la esfera terrestre.\n");
			return -1;
		} 
		FI = SINALF * (PROD- sqrt(A));
		FI1 = asin(FI);			// FI1 y RLAMB1 : coord. que no tienen en cuenta
		RLAMB1 = SITETA*FI*COSALF/(cos(FI1)*SINALF);	// angulos de tangage y 
						//					// de roulis (ANU) del sat.
	}	

	//   ******    CÁLCULO QUE TIENE EN CUENTA EL TANGAGE Y ROULIS DEL SATÉLITE  *****
	double FI2 = FI1;
	double COSANU = cos(nav_params.ANU);
	double SINANU = sin(nav_params.ANU);
	double SINFI2 = sin(FI2);
	double COSFI2 = cos(FI2);
	FI1 = SINFI2*COSANU + RLAMB1*COSFI2*SINANU;
	FI1 = asin(FI1);
	double COSFI1 = cos(FI1);
	double SINFI1 = sin(FI1);
	RLAMB1 = (-SINFI2*SINANU + RLAMB1*COSFI2*COSANU) / COSFI1;
	RLAMB1 = asin(RLAMB1);
	FI = COSFI1*cos(RLAMB1)*sin(nav_params.W) + SINFI1*cos(nav_params.W);
	FI = asin(FI);				// Latitud real en radianes.
	RLAMB = COSFI1 / cos(FI) * sin(RLAMB1);
	RLAMB = asin(RLAMB);			// Longitud en radianes.
	int K = 0;
	if ((fabs(nav_params.RLAMB0) > M_PI/2.) && (fabs(RLAMB+nav_params.RLAMB0) > M_PI)) K=1;
	RLAMB = RLAMB - K*2*M_PI + nav_params.RLAMB0;
	return 0;
}



//----------------------------------------------------------------------
void COOCAR1(double RLAT, double RLONG, float& X, float& Y, 
//   -------
	     int &LENVER, TNavig& nav_params)
{
//	Date : 27/2/1990		Modifieur :Andre SZANTAI
//	Machines : la plupart

//	 Calcule les coordonnees cartesiennes a partir de la longitude et la
//	latitude d'un point sur la terre . C'est une version modifiee du
//	programme COOCAR du PDP 11 .
//	 Tous les angles SONT et RESTENT en RADIANS .
//	Modification : correction de ALPHA le 13/4/1990 .

//		RLONG,RLAT : longitude, latitude du point a traiter (en rad).
//		X, Y : coord. cartesiennes (point, ligne) du point traite
//			(sont recuperees a la fin)

//	COMMON	/NAVIG/	RLAMB0, W, DR, ALPHA0, ANU, ANAM, AX, XC, YC, RAY
//		RLAMB0, W : longitude, latitude du point subsatellite.
//			 (LAMBDA0 et PHI0) (en radians) .
//		DR : rapport dist. centre de la terre au satellite /
//			rayon terrestre
//		ALPHA0, ANU : angles de tangage, de roulis du sat. (en rad.).
//		ANAM : coefficient d'anamorphose en Y (en general voisin de 1)
//		AX : sens de l'image; AX = -1 : a l'envers, AX = 1 : a l'endroit
//		XC, YC : coordonnee (pt., ligne) du centre sur l'image .
//		RAY : rayon du disque terrestre sur l'image

	double ARSIN = asin(1./nav_params.DR);		// Angle sous lequel on voit la moitie
//					   de la terre : TETA max.	
        double RLAMB = RLONG - nav_params.RLAMB0;		// Longitude corrigee.
	double COSW = cos(nav_params.W);
	double SINW = sin(nav_params.W);
	double COSFI = cos(RLAT);
	double SINFI = sin(RLAT);
	double COSLAM = cos(RLAMB);
	double D = COSFI*COSLAM*COSW + SINFI*SINW;
	if (D*nav_params.DR<1) {		// Tests des points "derriere" le disque
	  LENVER = 1;
	  return;
	} else {
	  LENVER = 0;
	}

	double A = SINFI * COSW - COSFI * COSLAM * SINW;
	double FIP1= asin(A);			// FIP1 : latitude obtenue apres une
//					   1ere rotation du repere.
	double COSFP1 = cos(FIP1);

	double BB = sin(RLAMB) * COSFI / COSFP1;

	double RLAMP1 = asin(BB);		// RLAMP1 : long. obtenue apres une 
//					   1ere rotation du repere.
	double RAC,ALPHA,C;
	if(nav_params.ANU==0) {
	  RAC = sqrt(nav_params.DR*nav_params.DR - 2*nav_params.DR*COSFP1*cos(RLAMP1) + COSFP1*COSFP1);
	  ALPHA = atan( sin(FIP1)/RAC)-nav_params.ALPHA0;
	  C = sin(RLAMP1)*COSFP1/RAC;
	} else {				// Cas avec ANU non nul.
	  double SINLAM=sin(RLAMP1);
	  double SINFIP=sin(FIP1);
	  double SINANU=sin(nav_params.ANU);
	  double COSANU=cos(nav_params.ANU);
	  double A = -COSFP1*SINLAM*SINANU+SINFIP*COSANU;	// A : sin (FIP2)
//					// FIP2 : lat. obtenue apres une 2eme
//					   rotation du repere (due a l'angle
//					   de roulis du satellite).
	  double COSFP2 = sqrt(1-A*A);
	  double BB = (COSFP1*SINLAM*COSANU + SINFIP*SINANU) / COSFP2;
	  double COSLA2 = sqrt(1-BB*BB);		// COSLA2 : cos (nouvelle longitude)
	  RAC = sqrt(nav_params.DR*nav_params.DR - 2*nav_params.DR*COSFP2*COSLA2 + COSFP2*COSFP2);
	  ALPHA = atan(A/RAC) - nav_params.ALPHA0;	// Angle lie a la ligne (Y).
	  C = BB * COSFP2 / RAC;
	}
	double TETA = asin(C);			// Angle lie aux points (X).
	X = TETA / ARSIN;
	Y = ALPHA / ARSIN;
	X = nav_params.AX*X*nav_params.RAY + nav_params.XC;		// Point (reel)
	Y = Y*nav_params.RAY/nav_params.ANAM - nav_params.AX*nav_params.YC;		// Ligne (correction du 13/3/1990)
     //#	Y = (Y*nav_params.RAY + nav_params.YC) /nav_params.ANAM		// Ligne

return;
}


//----------------------------------------------------------------------
InrImage* Func_ComputeAltitudes(InrImage* input, InrImage* coeff)
{
	/* coeff  coeficientes relacionados con el canal empleado y la imagen:
		* 0 -> alfa (slope) para calcular la radiancia
		* 1 -> R0 (offset) para calcular la radiancia
		* 2 -> vc (numero de onda central) para calcular la temperatura
		* 3 -> A para calcular la temperatura
		* 4 -> B para calcular la temperatura
	*/

	InrImage* altitudes = new InrImage(WT_SIGNED_INT,"altitudes.ami",input);

	// Se recorre la imagen de entrada calculando la altitud de cada pixel:
	input->InitBuffer();
	altitudes->InitBuffer();
	do
	{
		int C = (int)input->ValeurBuffer(); // valor IR						
		double R1 = (*coeff)(1,0,0) + C*(*coeff)(0,0,0); // radiancia: R1 = R0 + alfa·C

		// Se calcula la temperatura: T = (((C2·vc)/ln(((C1·vc^3)/R1)+1))-B)/A
		const double C1 = 1.19104e-5;
		const double C2 = 1.43877;
		double T = (((C2*(*coeff)(2,0,0))/log(((C1*pow((*coeff)(2,0,0),3))/R1)+1))-(*coeff)(4,0,0))/(*coeff)(3,0,0);

		// Se calcula la altitud: z = (T - T0)/gamma
		double const T0 = 288.15; // 15ºC en K
		double const gamma = -6.5e-3;
		int result = (int)((T-T0)/gamma);
		result = result < 0 ? 0 : result; // si es menor que cero se devuelve cero			
		altitudes->FixeValeur(result);

		// Se pasa a la siguiente posición:		
		altitudes->IncBuffer();

	} while (input->IncBuffer());
	return altitudes;
}


//----------------------------------------------------------------------
InrImage* Func_Temp2Altitudes(InrImage* input)
{
/** compute the altitudes from the temperature 
*/
	InrImage* altitudes = new InrImage(WT_SIGNED_INT,"altitudes.ami",input);

	// Se recorre la imagen de entrada calculando la altitud de cada pixel:
	input->InitBuffer();
	altitudes->InitBuffer();
	do
	{
		double T =(float)input->ValeurBuffer();
		// Se calcula la altitud: z = (T - T0)/gamma
		double const T0 = 288.15; // 15ºC en K
		double const gamma = -6.5e-3;
		int result = (int)((T-T0)/gamma);
		result = result < 0 ? 0 : result; // si es menor que cero se devuelve cero			
		altitudes->FixeValeur(result);

		// Se pasa a la siguiente posición:		
		altitudes->IncBuffer();

	} while (input->IncBuffer());
	return altitudes;
}


//----------------------------------------------------------------------
SurfacePoly* Func_CreateFlatMesh(InrImage* im, int orient)
//           -------------------
{

  InrImage* pointid;
  int x,y,ptid,n,tx,i;
  int neighbor[4];

  pointid = new InrImage(WT_SIGNED_INT,"pointid.ami.gz",im);
  pointid->InitImage(-1);

  SurfacePoly* surf;

  surf = new SurfacePoly;

  surf->NewSurface();

  im     ->InitBuffer();
  pointid->InitBuffer();
  ptid=0;



  Pour(y,0,im->DimY()-1)
    Pour(x,0,im->DimX()-1)

      if (im->ValeurBuffer()>0.5) {
	double x1,y1;
	x1 = (double)x*im->VoxSizeX()+im->TrX();
	y1 = (double)y*im->VoxSizeY()+im->TrY();
	surf   ->AddPoint(x1,y1,0);
	pointid->FixeValeur(ptid);
	ptid++;
      }
      im     ->IncBuffer();
      pointid->IncBuffer();
    FinPour
  FinPour

  tx=im->DimX();
  if (orient==1) {
	neighbor[0]=0;
	neighbor[1]=tx;
	neighbor[2]=tx+1;
	neighbor[3]=1;
  } else
  {
	neighbor[3]=0;
	neighbor[2]=tx;
	neighbor[1]=tx+1;
	neighbor[0]=1;
  }

  pointid->InitBuffer();

  Pour(y,0,im->DimY()-2)
    pointid->BufferPos(0,y,0);
    Pour(x,0,im->DimX()-2)

      n=0;
      Pour(i,0,3)
        n += pointid->ValeurBuffer(neighbor[i])>=0; 
      FinPour

      if (n>=3) {
	// Create Polygon
	surf->NewPoly();
        Pour(i,0,3)
	  ptid = (int) pointid->ValeurBuffer(neighbor[i]);
  	  if (ptid>=0) surf->PolyAddPointNumber(ptid);
        FinPour
	  /*
	// close the polygon
	ptid = (int) pointid->ValeurBuffer(neighbor[0]);
	if (ptid>=0) 
	  surf->PolyAddPointNumber(ptid);
	else 
	  surf->PolyAddPointNumber((int)pointid->ValeurBuffer(neighbor[1]));
	  */
        surf->EndPoly();
      }


      pointid->IncBuffer();
    FinPour
  FinPour



  delete pointid;
  return surf;

}


//----------------------------------------------------------------------
SurfacePoly* Func_CreateFlatMesh(InrImage* im, float minth, float maxth, int orient)
//           -------------------
{
  InrImage* pointid;
  int x,y,ptid,tx,i,j;
  int neighbor[4];
  int nx[4];
  int ny[4];
  int in[4];
  float val[4];
  int x1,y1,x2,y2;
  float a,b;
  float prev_val, current_val;
  float epsilon;
  int nb_points;

  pointid = new InrImage(WT_SIGNED_INT,"pointid.ami.gz",im);
  pointid->InitImage(-1);

  SurfacePoly* surf;

  surf = new SurfacePoly;

  surf->NewSurface();

  im     ->InitBuffer();
  pointid->InitBuffer();
  ptid=0;

  epsilon = 1E-3;
  minth -= epsilon;
  maxth += epsilon;

  Pour(y,0,im->DimY()-1)
    Pour(x,0,im->DimX()-1)

    if ((im->ValeurBuffer()>=minth)&&(im->ValeurBuffer()<=maxth)) {
      double x1,y1;
      x1 = (double)x*im->VoxSizeX()+im->TrX();
      y1 = (double)y*im->VoxSizeY()+im->TrY();
	surf   ->AddPoint(x1,y1,0);
	pointid->FixeValeur(ptid);
	ptid++;
      }
      im     ->IncBuffer();
      pointid->IncBuffer();
    FinPour
  FinPour

      printf("num points = %d \n",surf->GetNumberOfPoints());

  tx=im->DimX();
  if (orient==1) {
    neighbor[0]=0;    nx[0] = 0; ny[0] = 0;
    neighbor[1]=tx;   nx[1] = 0; ny[1] = 1;
    neighbor[2]=tx+1; nx[2] = 1; ny[2] = 1;
    neighbor[3]=1;    nx[3] = 1; ny[3] = 0;
  } else
  {
    neighbor[3]=0;    nx[3] = 0; ny[3] = 0;
    neighbor[2]=tx;   nx[2] = 0; ny[2] = 1;
    neighbor[1]=tx+1; nx[1] = 1; ny[1] = 1;
    neighbor[0]=1;    nx[0] = 1; ny[0] = 0;
  }


  Pour(y,0,im->DimY()-2)
    pointid->BufferPos(0,y,0);
    im     ->BufferPos(0,y,0);
    Pour(x,0,im->DimX()-2)

      //      printf("x,y = %d %d \n",x,y);
      // values
      Pour(i,0,3)
        val[i] = im->ValeurBuffer(neighbor[i]);
        in[i]  = (val[i]>=minth)&&(val[i]<=maxth);
      FinPour


      //     printf("start poly \n",x,y);
      nb_points=0;

      if (in[0]) {
	ptid = (int) pointid->ValeurBuffer(neighbor[0]);
	if (ptid>=0) {
	  if (nb_points==0) surf->NewPoly();
	  surf->PolyAddPointNumber(ptid);
	  nb_points++;
	}
      }

      for (i=0;i<=3;i++) {
	//	printf("i=%d \n",i);
	j = (i+1)%4;
	// segment 0->1
	prev_val    = val[i];
	current_val = val[j];
	
	if (((!in[i])&&(in[j]))||((in[i])&&(!in[j]))) {
	  // interpolate a point
	  if (!in[i]) 
	    if (prev_val<minth) {
	      a = minth-prev_val;
	      b = current_val-minth;
	    } else {
	      a = prev_val-maxth;
	      b = maxth-current_val;
	    }
	  else
	    if (current_val<minth) {
	      a = prev_val-minth;
	      b = minth-current_val;
	    } else {
	      a = maxth-prev_val;
	      b = current_val-maxth;
	    }
	  x1 = x+nx[i];   y1 = y+ny[i];
	  x2 = x+nx[j]; y2 = y+ny[j];
	  if (a+b>1E-5) {
	    double Px,Py;
	    Px = (double)(x1*b+x2*a)/(a+b)*im->VoxSizeX()+im->TrX();
	    Py = (double)(y1*b+y2*a)/(a+b)*im->VoxSizeY()+im->TrY();
	    surf   ->AddPoint(Px,Py,0);
	    if (nb_points==0) surf->NewPoly();
	    surf->PolyAddPointNumber(surf->GetNumberOfPoints()-1);
	    nb_points++;
	  }
	}

	if ((in[j])&&(j!=0)) {
	      ptid = (int) pointid->ValeurBuffer(neighbor[j]);
	      if (ptid>=0) {
		if (nb_points==0) surf->NewPoly();
		surf->PolyAddPointNumber(ptid);
		nb_points++;
	      }
	}
      } // for i

      if (nb_points>0) surf->EndPoly();

      pointid->IncBuffer();
      im     ->IncBuffer();
    FinPour
  FinPour



  delete pointid;  return surf;

} // Func_CreateFlatMesh()


//----------------------------------------------------------------------
SurfacePoly* Func_vtkCreateFlatMesh(InrImage* im, float minth, float maxth)
//           ----------------------
{
#ifndef _WITHOUT_VTK_
  
    vtkImageData*               vtk_image;
    vtkImageDataGeometryFilter* vtkgeom;
    vtkClipPolyData*            clip;
    vtkClipPolyData*            clip2;
    SurfacePoly*           res;


  // Convert InrImage to vtkImageData
  vtk_image = (vtkImageData*) (*im);

   vtkgeom = vtkImageDataGeometryFilter::New();
  vtkgeom->SetInput(vtk_image);
  vtkgeom->Update();

  clip = vtkClipPolyData::New();
  clip->SetInput(vtkgeom->GetOutput());
  clip->SetValue(minth);
  clip->Update();
  clip2 = vtkClipPolyData::New();
  clip2->SetInput(clip->GetOutput());
  clip2->SetValue(maxth);
  clip2->InsideOutOn();
  clip2->Update();

  res = new SurfacePoly( clip2->GetOutput());

  clip2   ->Delete();
  clip    ->Delete();
  vtkgeom ->Delete();

  return res;
#else
  fprintf(stderr, "Func_vtkCreateFlatMesh()\t VTK not available ...\n");
  return NULL;
#endif // _WITHOUT_VTK_

} // Func_vtkCreateFlatMesh()



//----------------------------------------------------------------------
// create a close surface composed of a top and a bottom surface
// lowpos and highpos are 2D images of 3D vectors
// im is a 2D image
// for all pixels within minth and maxth in im, 
// the top surface is created by the parametric mesh
// (x,y)->highpos(x,y) where (x,y) verifies im(x,y) in [minth,maxth]
// and the bottom surface is created by
// (x,y)->lowpos(x,y) where (x,y) verifies im(x,y) in [minth,maxth]
SurfacePoly* Func_CreateVolume(InrImage* im, float minth, float maxth,
//           -------------------
  InrImage* lowpos, InrImage* highpos, InrImage* colors, float alpha)
{
  
  InrImage* lowpointid;
   InrImage* highpointid;
  int x,y,ptid,tx,i,i1,j;
  int neighbor[4];
  int nx[4];
  int ny[4];
  int in[4];
  float val[4];
  int x1,y1,x2,y2;
  float a,b;
  float prev_val, current_val;
  float epsilon;
  int nb_points;
  
  int interpolated_points[4];
  int nb_ipoints,nb_ipoints2;

printf("begin CreateVolume() \n");

  lowpointid = new InrImage(WT_SIGNED_INT,"lowpointid.ami.gz",im);
  lowpointid->InitImage(-1);
  highpointid = new InrImage(WT_SIGNED_INT,"highpointid.ami.gz",im);
  highpointid->InitImage(-1);

  SurfacePoly* surf;

  surf = new SurfacePoly;

  surf->NewSurface();

  im     ->InitBuffer();
  lowpointid->InitBuffer();
  highpointid->InitBuffer();
  ptid=0;

  epsilon = 1E-3;
  minth -= epsilon;
  maxth += epsilon;

  Pour(y,0,im->DimY()-1)
    Pour(x,0,im->DimX()-1)

      if ((im->ValeurBuffer()>=minth)&&(im->ValeurBuffer()<=maxth)) {
        double x1,y1,z1;
        x1 = (*lowpos)(x,y,0,0);
        y1 = (*lowpos)(x,y,0,1);
        z1 = (*lowpos)(x,y,0,2);
        surf   ->AddPoint(x1,y1,z1);
        surf   ->SetOpacity(0);
        lowpointid->FixeValeur(ptid);
        ptid++;
        x1 = (*highpos)(x,y,0,0);
        y1 = (*highpos)(x,y,0,1);
        z1 = (*highpos)(x,y,0,2);
        surf   ->AddPoint(x1,y1,z1);
        if (colors!=NULL) {
          if (colors->_format!=WT_RGB) {
            fprintf(stderr,"CreateVolume() image of colors not in RGB format ! \n");
          } else {
            surf->SetColor((unsigned char)(*colors)(x,y,0,0),
                           (unsigned char)(*colors)(x,y,0,1),
                           (unsigned char)(*colors)(x,y,0,2),
                           alpha);
          }
        }
        highpointid->FixeValeur(ptid);
        ptid++;
      }
      im     ->IncBuffer();
      lowpointid->IncBuffer();
      highpointid->IncBuffer();
    FinPour
  FinPour

      printf("num points = %d \n",surf->GetNumberOfPoints());

  tx=im->DimX();
  neighbor[0]=0;    nx[0] = 0; ny[0] = 0;
  neighbor[1]=tx;   nx[1] = 0; ny[1] = 1;
  neighbor[2]=tx+1; nx[2] = 1; ny[2] = 1;
  neighbor[3]=1;    nx[3] = 1; ny[3] = 0;


  Pour(y,0,im->DimY()-2)
    lowpointid->BufferPos(0,y,0);
    highpointid->BufferPos(0,y,0);
    im     ->BufferPos(0,y,0);
    Pour(x,0,im->DimX()-2)

      //      printf("x,y = %d %d \n",x,y);
      // values
      Pour(i,0,3)
        val[i] = im->ValeurBuffer(neighbor[i]);
        in[i]  = (val[i]>=minth)&&(val[i]<=maxth);
      FinPour

      //============ process higher part
      //     printf("start poly \n",x,y);
      nb_points=0;
      nb_ipoints=0;

      if (in[0]) {
	ptid = (int) highpointid->ValeurBuffer(neighbor[0]);
	if (ptid>=0) {
	  if (nb_points==0) surf->NewPoly();
	  surf->PolyAddPointNumber(ptid);
	  nb_points++;
	}
      }

      for (i=0;i<=3;i++) {
	//	printf("i=%d \n",i);
	j = (i+1)%4;
	// segment 0->1
	prev_val    = val[i];
	current_val = val[j];
	

	if (((!in[i])&&(in[j]))||((in[i])&&(!in[j]))) {
	  // interpolate a point, but not the altitude
	  if (!in[i]) 
	    if (prev_val<minth) {
	      a = minth-prev_val;
	      b = current_val-minth;
	    } else {
	      a = prev_val-maxth;
	      b = maxth-current_val;
	    }
	  else
	    if (current_val<minth) {
	      a = prev_val-minth;
	      b = minth-current_val;
	    } else {
	      a = maxth-prev_val;
	      b = current_val-maxth;
	    }
	  x1 = x+nx[i]; y1 = y+ny[i];
	  x2 = x+nx[j]; y2 = y+ny[j];
	  if (a+b>1E-5) {
	    double Px,Py;
	    double vxl,vyl,vzl;
	    double vxh,vyh,vzh;
	    Px = (x1*b+x2*a)/(a+b);
	    Py = (y1*b+y2*a)/(a+b);
	    // get interpolated vector at (Px,Py)
	    vxl = highpos->InterpLinIntensite(Px,Py,0,0);
	    vyl = highpos->InterpLinIntensite(Px,Py,0,1);
	    vzl = highpos->InterpLinIntensite(Px,Py,0,2);
	    vxh = highpos->InterpLinIntensite(Px,Py,0,0);
	    vyh = highpos->InterpLinIntensite(Px,Py,0,1);
	    vzh = highpos->InterpLinIntensite(Px,Py,0,2);
	    surf   ->AddPoint((vxl+vxh)/2.0,(vyl+vyh)/2.0,(vzl+vzh)/2.0);
	    interpolated_points[nb_ipoints]=surf->GetNumberOfPoints()-1;
	    if (nb_points==0) surf->NewPoly();
	    surf->PolyAddPointNumber(surf->GetNumberOfPoints()-1);
	    nb_points++;
	    nb_ipoints++;
	    //printf("added ipoint %d \n",nb_ipoints);
	  }
	}

	if ((in[j])&&(j!=0)) {
	      ptid = (int) highpointid->ValeurBuffer(neighbor[j]);
	      if (ptid>=0) {
		if (nb_points==0) surf->NewPoly();
		surf->PolyAddPointNumber(ptid);
		nb_points++;
	      }
	}
      } // for i

      if (nb_points>0) surf->EndPoly();


      //============ process lower part
      //     printf("start poly \n",x,y);
      nb_points=0;
      nb_ipoints2=0; //because we go through the points in the other direction

      if (in[0]) {
	ptid = (int) lowpointid->ValeurBuffer(neighbor[0]);
	if (ptid>=0) {
	  if (nb_points==0) surf->NewPoly();
	  surf->PolyAddPointNumber(ptid);
	  nb_points++;
	}
      }

      // inverse order for the lower part
      for (i1=4;i1>=1;i1--) {
	//	printf("i=%d \n",i);
	i = (i1)%4;
	j = i1-1;
	// segment 0->1
	prev_val    = val[i];
	current_val = val[j];
	

	if (((!in[i])&&(in[j]))||((in[i])&&(!in[j]))) {
	  // interpolate a point
	  if (!in[i]) 
	    if (prev_val<minth) {
	      a = minth-prev_val;
	      b = current_val-minth;
	    } else {
	      a = prev_val-maxth;
	      b = maxth-current_val;
	    }
	  else
	    if (current_val<minth) {
	      a = prev_val-minth;
	      b = minth-current_val;
	    } else {
	      a = maxth-prev_val;
	      b = current_val-maxth;
	    }
	  x1 = x+nx[i]; y1 = y+ny[i];
	  x2 = x+nx[j]; y2 = y+ny[j];
	  if (a+b>1E-5) {
            // the point was already added in the lower surface
	    if (nb_points==0) surf->NewPoly();
	    // we parse the points in the other direction
	    // so we invert the order of the values in interpolated_points too
	    //printf("%d %d \n",nb_ipoints,nb_ipoints2);
	    surf->PolyAddPointNumber(interpolated_points[nb_ipoints-1-nb_ipoints2]);
	    nb_points++;
	    nb_ipoints2++;
	  }
	}

	if ((in[j])&&(j!=0)) {
	      ptid = (int) lowpointid->ValeurBuffer(neighbor[j]);
	      if (ptid>=0) {
		if (nb_points==0) surf->NewPoly();
		surf->PolyAddPointNumber(ptid);
		nb_points++;
	      }
	}
      } // for i

      if (nb_points>0) surf->EndPoly();
      
      lowpointid->IncBuffer();
      highpointid->IncBuffer();
      im     ->IncBuffer();
    FinPour
  FinPour



  delete lowpointid;  
  delete highpointid;  
  return surf;


} // Func_vtkCreateVolume()



//----------------------------------------------------------------------
int InitCoordinates( int& i_offset, int& j_offset, TNavig& nav, std::string type)
//   --------------
{
  // Se comprueba el tipo de imagen para saber los offsets a aplicar en los píxeles:
  if (type == "AfGG")
    {
      // Conversión:
      // Lr = La - 1301  ;  Cr = Ca - 1226;  ==>  La = Lr + 1301  ;  Ca = Cr + 1226 
      i_offset = 1302;
      j_offset = 1227;
    }
  else if (type == "NAtl")
    {
      // Conversión:
      // Lr = La - 171  ;  Cr = Ca - 1101;  ==>   La = Lr + 171  ;  Ca = Cr + 1101
      i_offset = 172;
      j_offset = 1102;
    }
  else if (type == "")
    {
      // Conversión:
      // Lr = La - 171  ;  Cr = Ca - 1101;  ==>   La = Lr + 171  ;  Ca = Cr + 1101
      i_offset = 0;
      j_offset = 0;
    }
  else
    {
      std::cerr << "No se reconoce el tipo de la imagen de entrada. Debe ser AfGG o NAtl" << std::endl;
      return 0;
    }
  
  // Parámetros de navegación:
  if (ininav(FLUID_NAVIGATION_FILE,nav)) return 1; // se cargan los parametros de navegacion
  else 
    return 0;
}


//----------------------------------------------------------------------
/**
	Calcula las coordenadas cartesianas 3D de los píxeles de una imagen MSG en función de sus altitudes,
	usando como origen el centro de la esfera terrestre.

*/
int coordenadas_esfera(InrImage* im, std::string type, float* coordenadas)
//  ------------------
{
	const int RT = 6371229;		// Rayo (seccion) terrestre medio en m.
	int i_offset, j_offset;
	TNavig nav_params;
	int width = im->DimX();
	InitCoordinates(i_offset,j_offset,nav_params, type);

	im->InitBuffer();

	// Se recorre la matriz de altitudes, calculando sus coordenadas:
	for (int i=0; i<im->DimY(); i++)
	  for (int j=0; j<im->DimX(); j++)
		{
		  // Se obtienen las coordenadas polares (r,theta (longitud),phi)
		  // Use image information (voxel size and translation)
		  double i1 = (double) i*im->VoxSizeY()+im->TrY();
		  double j1 = (double) j*im->VoxSizeX()+im->TrX();
		  double X = (double)(j1 +j_offset);
		  double Y = (double)(i1 +i_offset);
		  double latitud, longitud;
		  if (!coogeo(X,Y,latitud,longitud,nav_params)) // controlamos que estén dentro de la esfera
		    {
		      double r   = (*im)(j,i) + RT;
		      double phi = M_PI/2 - latitud;
		      
		      // Se transforma a cartesianas:
		      coordenadas[3*(i*width+j)+0] = r*cos(longitud)*sin(phi); // x
		      coordenadas[3*(i*width+j)+1] = r*sin(longitud)*sin(phi); // y
		      coordenadas[3*(i*width+j)+2] = r*cos(phi); // z			
		    }
		  else {
		    coordenadas[3*(i*width+j)+0] = 0; // x
		    coordenadas[3*(i*width+j)+1] = 0; // y
		    coordenadas[3*(i*width+j)+2] = 0; // z			
		    //fprintf(stderr,"coordenadas_esfera() out of the limits \n");
		  }
		}
	
	return 1;
}


//----------------------------------------------------------------------
InrImage* Func_Altitude2Position(InrImage* im, int type)
//        ----------------------
{
  InrImage* res;


  if ((type<0)||(type>1)) return NULL;
  res = new InrImage(WT_FLOAT,3,"pos.ami.gz",im);
  coordenadas_esfera(im,typestring[type], (float*)res->GetData());

  return res;
}

//----------------------------------------------------------------------
InrImage* Func_GeoCoordinates(InrImage* im, int type)
//        -------------------
{
  int i_offset, j_offset;
  TNavig nav_params;
  InrImage* res;
  double latitud, longitud;
  double i1,j1,X,Y;

  if ((type<0)||(type>1)) return NULL;

  InitCoordinates(i_offset,j_offset,nav_params, typestring[type]);
  res = new InrImage(WT_FLOAT,3,"geocoord.ami.gz",im);
  res->InitBuffer();

  for (int i=0; i<im->DimY(); i++)
    for (int j=0; j<im->DimX(); j++)
      {
	i1 = (double) i*im->VoxSizeY()+im->TrY();
	j1 = (double) j*im->VoxSizeX()+im->TrX();
	X = (double)(j1 +j_offset);
	Y = (double)(i1 +i_offset);
	if (!coogeo(X,Y,latitud,longitud,nav_params)) // controlamos que estén dentro de la esfera 
	  {
	    //	    if (((int)i%100==0)&&((int)j%100==0)) printf("%d,%d, (X,Y)=(%g,%g) --> (%g,%g) \n",i,j,X,Y,latitud,longitud);
	    res->VectFixeValeurs(latitud,longitud,0);
	  }
	else
	  {
	    fprintf(stderr,"Func_GeoCoordinates()\t out of the limits \n");
	    res->VectFixeValeurs(0,0,-1);
	  }
	res->IncBuffer();
      }


  return res;
} // Func_GeoCoordinates()

//----------------------------------------------------------------------
void Func_ElevateMesh(SurfacePoly* surf, InrImage* im)
//   ----------------
{

  int n;
  float x,y;
  float vx,vy,vz;


  Pour(n,0,surf->GetNumberOfPoints()-1)
    Point3DPoly& pt = surf->GetPoint(n);
    x = (pt.X()-im->TrX())/im->VoxSizeX();
    y = (pt.Y()-im->TrY())/im->VoxSizeY();
    if (x<0) x=0;
    if (y<0) y=0;
    if (x>im->DimX()-1) x=im->DimX()-1;
    if (y>im->DimY()-1) y=im->DimY()-1;
    switch(im->GetVDim()) {
    case 1:
      pt.pt.z =  im->InterpLinIntensite(x,y);
      break;
    case 2:
      vx = im->InterpLinIntensite(x,y,0,0);
      vy = im->InterpLinIntensite(x,y,0,1);
      pt.pt.Init( vx,vy,pt.Z());
      break;
    case 3:
      vx = im->InterpLinIntensite(x,y,0,0);
      vy = im->InterpLinIntensite(x,y,0,1);
      vz = im->InterpLinIntensite(x,y,0,2);
      pt.pt.Init( vx,vy,vz);
      break;
      }
    /*    if (fabsf(vx)<1E-2) {
      printf("(%f ,%f) --> %f %f %f \n",x,y,vx,vy,vz);
    }
    */
  FinPour
  surf->UpdateLimits();
}

//void ColorMesh()

//----------------------------------------------------------------------
void         Func_SetArrowParameters( float basesize, float headsize, float headpos)
{
  arrowconf.base_size      = basesize;
  arrowconf.arrow_size     = headsize;
  arrowconf.arrow_position = headpos;
} // Func_SetArrowParameters( )
  

//----------------------------------------------------------------------
void AddArrow(SurfacePoly* surf, int &ptid, float p0x, float p0y, float p0z, float p1x, float p1y, float p1z, float scale, int vector_style=1)
//   --------
{
  int npoints;

  npoints = surf->NbPoints();
//  if (npoints!=ptid) printf("%d %d \n", npoints, ptid);

  switch (vector_style) {
  case 0:
    // lines
    // First point
    surf   ->AddPoint(p0x,p0y,p0z);
    surf   ->AddPoint(p0x+scale*(p1x-p0x),
		      p0y+scale*(p1y-p0y),
		      p0z+scale*(p1z-p0z));
    surf ->NewLine();
    surf ->LineAddPointNumber(npoints);
    surf ->LineAddPointNumber(npoints+1);
    surf ->EndLine();
    ptid += 2;
    break;
  case 1:
  {
    // vectors
    Point_3D<float> p0(p0x,p0y,p0z);
    Point_3D<float> p1(p1x,p1y,p1z);
    Vect3D<float> v0;

    v0 = p1 - p0; // Vect3D<float>

    if (Norme(v0)<1E-5) return;

    // get an orthogonal base
    int argmin=0;
    if (fabs(v0.x)>fabs(v0.y))
      if (fabs(v0.y)>fabs(v0.z))
	argmin=2;
      else
	argmin=1;
    else
      if (fabs(v0.x)>fabs(v0.z))
	argmin=2;
      else
	argmin=0;      
    Vect3D<float> v1(0,0,0);
    if (argmin==0) {
      v1.y = -v0.z;
      v1.z =  v0.y;
    } else 
      if (argmin==1) {
	v1.x = -v0.z;
	v1.z = v0.x;
      } else
	{
	  v1.x = -v0.y;
	  v1.y = v0.x;
	}

    try {
      Vect3D<float> v2;
      v2 = v0^v1;
      v1.Normalise();
      v2.Normalise();

      // creation du 1er tetrahedre:
      // 4 points    
      v0 = v0*scale;
      float v0n = Norme(v0);
      float basesize = arrowconf.base_size;
      
      surf   ->AddPoint(p0+v0);
      surf   ->AddPoint(p0+v1*v0n*basesize);
      surf   ->AddPoint(p0+(v1*(float)cos(2*PI/3.0)+v2*(float)sin(2*PI/3.0))*v0n*basesize);
      surf   ->AddPoint(p0+(v1*(float)cos(4*PI/3.0)+v2*(float)sin(4*PI/3.0))*v0n*basesize);
      
      // add the polygons
      //      printf("4 more polys \n");
      surf->NewPoly();
      surf->PolyAddPointNumber(npoints);
      surf->PolyAddPointNumber(npoints+1);
      surf->PolyAddPointNumber(npoints+2);
      surf->EndPoly();
      
      surf->NewPoly();
      surf->PolyAddPointNumber(npoints);
      surf->PolyAddPointNumber(npoints+2);
      surf->PolyAddPointNumber(npoints+3);
      surf->EndPoly();
      
      surf->NewPoly();
      surf->PolyAddPointNumber(npoints);
      surf->PolyAddPointNumber(npoints+3);
      surf->PolyAddPointNumber(npoints+1);
      surf->EndPoly();
      
      
      surf->NewPoly();
      surf->PolyAddPointNumber(npoints+1);
      surf->PolyAddPointNumber(npoints+3);
      surf->PolyAddPointNumber(npoints+2);
      surf->EndPoly();

      // creation du 2e tetrahedre:
      // 4 points    
      float arrowsize = arrowconf.arrow_size;
      float arrowpos  = arrowconf.arrow_position;
      
      surf   ->AddPoint(p0+v0*arrowpos+v1*v0n*arrowsize);
      surf   ->AddPoint(p0+v0*arrowpos+(v1*(float)cos(2*PI/3.0)+v2*(float)sin(2*PI/3.0))*v0n*arrowsize);
      surf   ->AddPoint(p0+v0*arrowpos+(v1*(float)cos(4*PI/3.0)+v2*(float)sin(4*PI/3.0))*v0n*arrowsize);
      
      surf->NewPoly();
      surf->PolyAddPointNumber(npoints);
      surf->PolyAddPointNumber(npoints+4);
      surf->PolyAddPointNumber(npoints+5);
      surf->EndPoly();
      
      surf->NewPoly();
      surf->PolyAddPointNumber(npoints);
      surf->PolyAddPointNumber(npoints+5);
      surf->PolyAddPointNumber(npoints+6);
      surf->EndPoly();
      
      surf->NewPoly();
      surf->PolyAddPointNumber(npoints);
      surf->PolyAddPointNumber(npoints+6);
      surf->PolyAddPointNumber(npoints+4);
      surf->EndPoly();
      
      
      surf->NewPoly();
      surf->PolyAddPointNumber(npoints+4);
      surf->PolyAddPointNumber(npoints+6);
      surf->PolyAddPointNumber(npoints+5);
      surf->EndPoly();

    }
    catch (NormeFaible) {
      fprintf(stderr,"Norme faible ... \n");
    }
    } // case 1
    break;
  
  case 2:
  {
    int base_faces=5;
    
    // vectors
    Point_3D<float> p0(p0x,p0y,p0z);
    Point_3D<float> p1(p1x,p1y,p1z);
    Vect3D<float> v0;

    v0 = p1 - p0; // Vect3D<float>

    if (Norme(v0)<1E-5) return;

    // get an orthogonal base
    int argmin=0;
    if (fabs(v0.x)>fabs(v0.y))
      if (fabs(v0.y)>fabs(v0.z))
	argmin=2;
      else
	argmin=1;
    else
      if (fabs(v0.x)>fabs(v0.z))
	argmin=2;
      else
	argmin=0;      
    Vect3D<float> v1(0,0,0);
    if (argmin==0) {
      v1.y = -v0.z;
      v1.z =  v0.y;
    } else 
      if (argmin==1) {
	v1.x = -v0.z;
	v1.z = v0.x;
      } else
	{
	  v1.x = -v0.y;
	  v1.y = v0.x;
	}

    try {
      Vect3D<float> v2;
      v2 = v0^v1;
      v1.Normalise();
      v2.Normalise();

      v0 = v0*scale;
      float v0n = Norme(v0);
      float basesize = arrowconf.base_size;
      float arrowsize = arrowconf.arrow_size;
      float arrowpos  = arrowconf.arrow_position;
      int n;
      
      // Create the base polygon
      for( n=0; n<base_faces;n++) {
        surf   ->AddPoint(p0+(v1*(float)cos(-n*2.0*PI/base_faces)+
                              v2*(float)sin(-n*2.0*PI/base_faces)
                             )*v0n*basesize);
      }
      
      // Create the top  polygon
      for( n=0; n<base_faces;n++) {
        surf   ->AddPoint(p0+v0*arrowpos+
                              (v1*(float)cos(-n*2.0*PI/base_faces)+
                               v2*(float)sin(-n*2.0*PI/base_faces)
                              )*v0n*basesize);
      }
      
      // Add base polygon
      surf->NewPoly();
      for( n=0; n<base_faces;n++) {
        surf->PolyAddPointNumber(npoints+n);
      }
      surf->EndPoly();
      
      // Add square for each face
      for( n=0; n<base_faces;n++) {
        int n1 = (n+1)%base_faces;
        surf->NewPoly();
        surf->PolyAddPointNumber(npoints+n+base_faces);
        surf->PolyAddPointNumber(npoints+n1 +base_faces);
        surf->PolyAddPointNumber(npoints+n1);
        surf->PolyAddPointNumber(npoints+n);
        surf->EndPoly();
      }

      // Create of the head tetrahedron:
      // 4 points    
      int n0 = 2*base_faces;
      for( n=0; n<base_faces;n++) {
        surf   ->AddPoint(p0+v0*arrowpos+
                             (v1*(float)cos(-n*2.0*PI/base_faces)+
                              v2*(float)sin(-n*2.0*PI/base_faces)
                             )*v0n*arrowsize);
      }
      surf   ->AddPoint(p0+v0);
      
      // base polygon
      surf->NewPoly();
      for( n=0; n<base_faces;n++) {
        surf->PolyAddPointNumber(npoints+n0+n);
      }
      surf->EndPoly();
      
      // Add triangle for each face
      for( n=0; n<base_faces;n++) {
        int n1 = (n+1)%base_faces;
        surf->NewPoly();
          surf->PolyAddPointNumber(npoints+n0+base_faces);
          surf->PolyAddPointNumber(npoints+n0+n1);
          surf->PolyAddPointNumber(npoints+n0+n);
        surf->EndPoly();
      }

    }
    catch (NormeFaible) {
      fprintf(stderr,"Norme faible ... \n");
    }
    } // case 2
    break;
  };

}


//----------------------------------------------------------------------
//
// atl1 is the altitude image at time t
// displ is the displacement field between t and t+dt
// alt2 is the altitude image at time t+dt
//
SurfacePoly* Func_CreateVectors(InrImage* alt1, InrImage* displ, InrImage* alt2, 
//           ------------------
				int stepx, int stepy, float scale, int type, int vector_style )
{

  if ((type<0)||(type>1)) return NULL;

  float pos0x=0,pos0y=0,pos0z=0;
  float pos1x=0,pos1y=0,pos1z=0;
  float vx,vy,x1,y1;
  int x,y,ptid;

  SurfacePoly* surf;


  const int RT = 6371229;		// Rayo (seccion) terrestre medio en m.
  int i_offset, j_offset;
  TNavig nav_params;

  double X,Y,latitud, longitud;

  InitCoordinates(i_offset,j_offset,nav_params,typestring[type]);

  surf = new SurfacePoly;
  surf->NewSurface();

  alt1->InitBuffer();

  ptid=0;
  for(x=0;x<alt1->DimX(); x+=stepx)
  for(y=0;y<alt1->DimY(); y+=stepy)
    {
      vx=(*displ)(x,y,0,0);
      vy=(*displ)(x,y,0,1);

      // Se obtienen las coordenadas polares (r,theta (longitud),phi)
      // 1st point at time t
      x1 = (double) x*displ->VoxSizeX()+displ->TrX();
      y1 = (double) y*displ->VoxSizeY()+displ->TrY();
      X = (double)((float)x1 +j_offset);
      Y = (double)((float)y1 +i_offset);
      if (!coogeo(X,Y,latitud,longitud,nav_params)) // controlamos que estén dentro de la esfera
	{
	  double r = (*alt1)(x,y) + RT;
	  double phi = M_PI/2 - latitud;
	  // Se transforma a cartesianas:
	  pos0x = r*cos(longitud)*sin(phi); // x
	  pos0y = r*sin(longitud)*sin(phi); // y
	  pos0z = r*cos(phi); // z			
	}

      // Se obtienen las coordenadas polares (r,theta (longitud),phi)
      // Second point at time t+td
      x1 = (double) x*displ->VoxSizeX()+displ->TrX();
      y1 = (double) y*displ->VoxSizeY()+displ->TrY();
      X = (double)((float)x1+vx +j_offset);
      Y = (double)((float)y1+vy +i_offset);
      if (!coogeo(X,Y,latitud,longitud,nav_params)) // controlamos que estén dentro de la esfera
	{
	  double r = alt2->InterpLinIntensite((float)x+vx,(float)y+vy) + RT;
	  double phi = M_PI/2 - latitud;
	  // Se transforma a cartesianas:
	  pos1x = r*cos(longitud)*sin(phi); // x
	  pos1y = r*sin(longitud)*sin(phi); // y
	  pos1z = r*cos(phi); // z			
	}


      AddArrow(surf,ptid,pos0x,pos0y,pos0z,pos1x,pos1y,pos1z,scale,vector_style);

    }

  return surf;

} // Func_CreateVectors()

/** Creates vectors in 3D from 3D displacement field **/
SurfacePoly* Func_CreateVectors(
                  InrImage* displ,
                  int stepx, int stepy, int stepz, 
                  float scale, 
                  int vector_style )
{
  float vx,vy,vz;
  float x1,y1,z1;
  float x2,y2,z2;
  int x,y,z,ptid;

  SurfacePoly* surf;

  surf = new SurfacePoly;
  surf->NewSurface();

  displ->InitBuffer();

  for(x=0;x<displ->DimX(); x+=stepx)
  for(y=0;y<displ->DimY(); y+=stepy)
  for(z=0;z<displ->DimZ(); z+=stepz)
    {
      vx=(*displ)(x,y,z,0);
      vy=(*displ)(x,y,z,1);
      vz=(*displ)(x,y,z,2);

      // Se obtienen las coordenadas polares (r,theta (longitud),phi)
      // Second point at time t+td
      x1 = (double) x*displ->VoxSizeX()+displ->TrX();
      y1 = (double) y*displ->VoxSizeY()+displ->TrY();
      z1 = (double) z*displ->VoxSizeZ()+displ->TrZ();

      x2 = (double) x1+vx*displ->VoxSizeX();
      y2 = (double) y1+vy*displ->VoxSizeY();
      z2 = (double) z1+vz*displ->VoxSizeZ();

      AddArrow(surf,ptid,x1,y1,z1,x2,y2,z2,scale,vector_style);
    }

  return surf;
} // Func_CreateVectors()

//----------------------------------------------------------------------
//
//	FUNCTION TO READ AN ASCCI FILE WITH THE OPTIC FLOW INFORMATION
//   IMPORTANT: WE INVERSE THE ROW ORDER (U, V images have 1d)
// 

int ami_read_optic_flow_v2(
  const char* name, /** name of the input flow file */
  float **u, float **v, /** output flow matrix */ 
  int *width, int *height, char tag[50]) /** image dimensions */
{
  int i,j,c;
  FILE *fptr;
  char paso[200];
  long m,size;
  float up,vp,*u2,*v2;

  // Open file
  if ((fptr = fopen(name,"r")) == NULL) {
    fprintf(stderr,"Unable to open  file \"%s\"\n",name);
    return(-2);
  }

// ...................

  // WE SKIP THE COMMENT HEAD PART OF THE FILE
  fscanf(fptr, "%s",paso);
  while(paso[0]=='#' ) {
 
     if ( paso[1]==':' && paso[2]=='#' ) {

	fscanf(fptr, "%s",paso);
        strcpy( tag, paso );

        //printf("Tag: %s  %s  %s\n", tag, paso, paso+4 );
     }

     while( (c=getc(fptr)) != '\n' );

     fscanf(fptr, "%s",paso);
//	printf("paso : %s\n",paso);
  }

// ...................

  // WE READ THE IMAGE DIMENSION
  *width=atoi(paso);
  fscanf(fptr,"%d",height);
  size=(*width)*(*height);
  printf("dimensions : %d %d\n",*width,*height);

  // WE SKIP THE COMMENT HEAD PART OF THE FILE
  fscanf(fptr, "%s",paso);
  while(paso[0]=='#' ) {
 
     if ( paso[1]==':' && paso[2]=='#' ) {

	fscanf(fptr, "%s",paso);
        strcpy( tag, paso );

        //printf("Tag: %s  %s  %s\n", tag, paso, paso+4 );
     }

     while( (c=getc(fptr)) != '\n' );

     fscanf(fptr, "%s",paso);
//	printf("paso : %s\n",paso);
  }


  // WE ALLOCATE MEMORY FOR THE FLOW MATRIX AND WE INITIALIZE TO (0,0) THE FLOW
  u2 = new float[size];
  v2 = new float[size];

#ifndef UV_NULL_VALUE
#define UV_NULL_VALUE 10000.0
#endif

  // Init images with a NULL value (10000)
  for(m=0;m<size;m++)
  {
      u2[m] = UV_NULL_VALUE; //(float) NULL_VALUE;
      v2[m] = UV_NULL_VALUE; //(float) NULL_VALUE;
  }


  // WE FILL THE FLOW MATRIX WITH THE FILE INFORMATION AND WE INVERSE THE ROW ORDER
  for(m=0;m<size;m++){

/*  
#ifdef PX_2PRECISION
 	  if( fscanf(fptr,"%d %d %1.2f %1.2f\n",&j,&i,&up,&vp)!=EOF){

#else
 	  if( fscanf(fptr,"%d %d %f %f\n",&j,&i,&up,&vp)!=EOF){
#endif
*/

 	  if( fscanf(fptr,"%d %d %f %f\n",&j,&i,&up,&vp)!=EOF){
    

#ifdef TOP_LEFT_ORIGIN

		u2[i*(*width) + j] = up;
		v2[i*(*width) + j] = -vp;    
#else

		////u2[*height-1-i][j]=up;
		////v2[*height-1-i][j]=vp;

		u2[(*height-1-i)*(*width) + j] = up;
		v2[(*height-1-i)*(*width) + j] = vp;  
#endif

	  }
	  else m=size;
  }

  fclose(fptr);
  *u=u2;
  *v=v2;

  return(0);
}

//----------------------------------------------------------------------
InrImage*    Func_ReadFlow( const char* name)
{
  float *u, *v;
  float *pu,*pv;
  int width, height;
  char tag[250];
  InrImage* res;

  ami_read_optic_flow_v2(name,&u,&v,&width,&height,tag);

  res = new InrImage(width,height,1,3,WT_FLOAT);
  res->InitBuffer();
  pu=u; pv=v;
  for (int y=0; y<height; y++)
    for (int x=0; x<width; x++)
      {
	res->VectFixeValeurs(*pu,-*pv,0);
	res->IncBuffer();
	pu++; pv++;
      }
  delete [] u;
  delete [] v;


  return res;

} // Func_ReadFlow()

} // namespace AMIFluid
