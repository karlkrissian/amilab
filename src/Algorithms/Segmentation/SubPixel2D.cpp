/*
 *  SubPixel2D.cpp
 *  AMILab
 */


#ifdef WIN32
  #include <float.h>
  #define isnan _isnan
#endif

#include "SubPixel2D.h"
#include <cmath>
#include "inrimage.hpp"
#include "paramlist.h"
#include "ami_object.h"
#include "wrapfunctions.hpp"
#include <vector>
#include <iostream>
using namespace std;

#include "DessinImage.hpp"
#include "wrap_DessinImage.h"
#include "wrap_wxColour.h"
#include <wx/colour.h>

#define XMAX	1
#define YMAX	2

// valores máximo y mínimos de radios (en pixels) en una imagen (se usa en el SupGradGausCurvo)
// radios superiores se consideran rectas
#define RMAX	200.0
//1.5    	// radios inferiores se considera ruido, y se aplica caso plano
#define RMIN	10.0

// primitiva del circulo
#define P(x) (yc*(x) + 0.5*r*r*asin((x-xc)/r) + 0.5*(x-xc)*sqrt(r*r-(x-xc)*(x-xc)))

// parciales en 2D
//data[(y)*nx+(x)]
double imval(InrImage* input, int x,int y, int z){
  if (input->CoordOK(x,y,z)) 
    return (*input)(x,y,z);
  else 
    cout << "out of image range (" << x << ", " << y << ", " << z << ")" << endl;
  return 0;
}
#define FF(x,y,z)		imval(input,x,y,z)
#define ffx(x,y,z) 	(FF(x+1,y,z) - FF(x-1,y,z))
#define ffy(x,y,z) 	(FF(x,y+1,z) - FF(x,y-1,z))
#define ffyd(x,y,z) (FF(x, y+1, z) - FF(x,y,z))
#define ffyu(x,y,z)	(FF(x,y,z) - FF(x,y-1,z))
#define ffxl(x,y,z) (FF(x,y,z) - FF(x-1,y,z))
#define ffxr(x,y,z)	(FF(x+1,y,z) - FF(x,y,z))

// coeficientes de la máscara de suavizado 2D (por ahora, para probar con promedio 3x3)
double A00 = (double) 1 / 9;
double A01 = (double) 1 / 9;
double A11 = (double) 1 / 9;

//borderPixel class methods
void borderPixel::setBorderPixelValues(double intA, double intB, 
                                       unsigned char bord, double coef_a, 
                                       double coef_b, double coef_c, double cu, 
                                       int posx, int posy)
{
  A         = intA;
  B         = intB;
  border    = bord;
  a         = coef_a;
  b         = coef_b;
  c         = coef_c;
  curvature = cu;
  px        = posx;
  py        = posy;
}

double borderPixel::getAIntensity()    { return A; }

double borderPixel::getBIntensity()    { return B; }

unsigned char borderPixel::getBorder() { return border; }

double borderPixel::getCoefficient_a() { return a; }

double borderPixel::getCoefficient_b() { return b; }

double borderPixel::getCoefficient_c() { return c; }

double borderPixel::getCurvature()     { return curvature; }

int borderPixel::getPosX()             { return px; }

int borderPixel::getPosY()             { return py; }

void borderPixel::printBorderPixel(int linear_case)
{
//  if(py == 40 || py == 60){    
  cout << "----------------------------------" << endl;
  cout << "Pixel (" << px << ", " << py << ")" << endl;
  const char* tb = (border==2) ? "YMAX" : "XMAX";
  cout << "Border       = " << tb << endl;
  cout << "A intensity  = " << A << endl;
  cout << "B intensity  = " << B << endl;
  cout << "Curve coefficients: a = " << a << ", b = " << b << ", c = " << c << endl;
  if (linear_case==1)
  { 
    double rad = atan(b);
    cout << "Angle        = " << (rad*360)/(2*3.141592741) << endl;
  }
  else
  {
    cout << "Radius       = " << 1/curvature << endl;
  }
  cout << "----------------------------------" << endl;
//  }
}

//subpixel2D class methods
SubPixel2D::SubPixel2D(InrImage* inp_image, float thres, int lc)
{
  input       = inp_image;
  threshold   = thres;
  linear_case = lc;
}

SubPixel2D::~SubPixel2D(){}

void SubPixel2D::OptimizarParabola (double &a, double &b, double &c, 
                                    double umbral, double rmin, double rmax)
{
  double cu, temp, f=0.75;
  double a0, b0, c0, xc, yc, raiz;
  double a1, b1, c1, a2, b2, c2;
  double p1, p3, p5, pm1, pm3, pm5;
  bool   inv_signo = false;
  double r, rprev, rvar, rvar0=10;
  
  // calculamos la curvatura
  raiz = sqrt (1+b*b);
  cu   = raiz * raiz * raiz;
  cu   = -2*c / cu;
  r    = fabs(1/cu);
  
  //cout << "inicial a = " << a << " b = " << b << " c = " << c << " r = " << r << endl;
  
  // a partir de aqui, se cumple siempre que c<0, cu>0 
  // si la curvatura es muy pequeña, pasamos del factor de correccion
  if (r > rmax) return;
  
  // si la curvatura es muy grande debe ser un error
  // tenemos 2 alternativas: si creemos que es debido a un arco con R chico,
  // podemos generar el arco de menor R que podamos, pero si creemos que es
  // debido al ruido, podemos generar una recta
  if (r < rmin) {			
    // generando arco con R pequeño
    cu   = (cu>0)? 1/rmin : -1/rmin;
    a   += f * c;
    temp = sqrt(1+b*b);
    c    = cu * temp * temp * temp / (-2);
    a   -= f * c;
    /*
     // generando recta
     a += f * c;
     cu = c = 0.0;
     */	
    //	printf ("r muy chico %f\n", r);
    //cout << "r muy chico " << r << endl;
    return;
  }
  
  // solo sirve para parábolas con c negativo
  if (c>0) {
    inv_signo = true;
    a         = -a; 
    c         = -c;
  }	
  
  
  /*
   // corte con el suelo
   {double r = -14*c-4*a*c+b*b;
   if (r>0) {
   r = sqrt(r);
   double t1 = (-b+r)/(2*c);
   double t2 = (-b-r)/(2*c);
   if (t1>-2.5 && t1<0) printf ("la parabola corta en t1 (%.2f,-7/2)\n",t1); cout << "la parábola corta en t1 (" << t1 << ", -7/2)" << endl;
   if (t2>-2.5 && t2<0) printf ("la parabola corta en t2 (%.2f,-7/2)\n",t2); cout << "la parábola corta en t2 (" << t2 << ", -7/2)" << endl
   }
   }
   */	
  
  // salvamos los valores originales devueltos por el método
  a0 = a; b0 = b; c0 = c;
  
	
  // tantas iteraciones como indique factor
  do { 		
    // calculo el centro del circulo
    xc  = b * r / raiz;
    yc  = a - (r/raiz);
		
    // calculo las primitivas
    p5  = P(2.5);
    p3  = P(1.5);
    p1  = P(0.5);
    pm1 = P(-0.5);
    pm3 = P(-1.5);
    pm5 = P(-2.5);
    
    // calculo los nuevos coeficientes
    temp = sqrt (r*r-xc*xc);
    b1   = (p5 + pm5 - p1 -pm1) / 6;
    b2   = xc / temp;
    b    = b0 - b1 + b2;
    c1   = (p5 - pm5 -2*p3 + 2*pm3 + p1 - pm1) / 6;
    c2   = -0.5 * r * r / (temp*temp*temp);
    c    = c0 - c1 + c2;
    a1   = (p3-pm3)/3 - 0.75*c1;
    a2   = yc + temp;
    a    = a0 - a1 + a2;
    
    /*
     printf ("a0=%f a1=%f a2=%f\n", a0, a1, a2);	
     cout << "a0 = " << a0 << " a1 = " << a1 << " a2 = " << a2 << endl;
     printf ("b0=%f b1=%f b2=%f\n", b0, b1, b2);
     cout << "b0 = " << b0 << " b1 = " << b1 << " b2 = " << b2 << endl;
     printf ("c0=%f c1=%f c2=%f\n", c0, c1, c2);
     cout << "c0 = " << c0 << " c1 = " << c1 << " c2 = " << c2 << endl;
     */	
    // revisamos que el factor de corrección haya dado datos correctos
    if (isnan(a) || isnan(b) || isnan(c) 
        || fabs(a2-a1)>0.5 || fabs(b2-b1)>fabs(b0) 
        || fabs(c2-c1)>fabs(c0)) {
      a = a0;
      b = b0;
      c = c0;
      break;
    }
    
    // miramos la variación del radio
    rprev = r;
    raiz  = sqrt (1+b*b);
    cu    = raiz * raiz * raiz;
    cu    = -2*c / cu;
    r     = 1 / cu;
    rvar  = fabs(r-rprev) / rprev;
    //printf ("a=%f b=%f c=%f C=(%.2f,%.2f) r=%f var(r)=%f\n", a, b, c, xc, yc, r, rvar);
    //cout << "a = " << a << " b = " << b << " c = " << c << " C = (" << xc << ", " << yc << ") r = " << r << "var(r) = " << rvar << endl;
    if (rvar > rvar0) break;
    rvar0 = rvar;
    
  } while (rvar > umbral);
  
  // si se negó el signo se recupera
  if (inv_signo) { a = -a; c = -c; }
}



//Función para dibujar los contornos
void SubPixel2D::drawBorder(DessinImage* viewer, InrImage* inside, 
                            InrImage* border_pts,  wxColour* bcolor, 
                            int bthickness, int bstyle, int draw_normals, 
                            InrImage* norm_pts, wxColour* ncolor, 
                            int nthickness, int nstyle)
{
  //Set line parameters
  viewer->SetPenColor(*bcolor);
  if(bstyle==0)
    viewer->SetLineParameters(bthickness, wxSOLID);
  else
    viewer->SetLineParameters(bthickness, wxDOT);
  //Draw the border
  for(int i=0; i<border_pts->DimX(); i++)
  {
    if ((*inside)(i,0,0))
    {
      viewer->DrawLineZ((*border_pts)(i,0,0,0), (*border_pts)(i,0,0,1), 
                        (*border_pts)(i,0,0,2), (*border_pts)(i,0,0,3));
    }
  }

 
  if (draw_normals)
  {
    //Set line parameters
    viewer->SetPenColor(*ncolor);
    if(nstyle==0)
      viewer->SetLineParameters(nthickness, wxSOLID);
    else
      viewer->SetLineParameters(nthickness, wxDOT);
    //Draw normals
    double a,b;
    for(int i=0; i<norm_pts->DimX(); i++)
    {
      if ((*inside)(i,0,0))
      {
        viewer->DrawLineZ((*norm_pts)(i,0,0,0), (*norm_pts)(i,0,0,1), 
                          (*norm_pts)(i,0,0,2), (*norm_pts)(i,0,0,3));
        
        //double theta = atan(((*norm_pts)(i,0,0,1)-(*norm_pts)(i,0,0,3))/
//                            ((*norm_pts)(i,0,0,0)-(*norm_pts)(i,0,0,2)));
//        theta = theta*180 / M_PI;
        //double ty = (double)-((*norm_pts)(i,0,0,1)-(*norm_pts)(i,0,0,3));
//        double tx = (double)((*norm_pts)(i,0,0,0)-(*norm_pts)(i,0,0,2));
//        double theta = (double)atan(ty/tx);
//        if (tx < 0) {
//          theta += M_PI;
//        }
//        double alpha = 45.0*M_PI/180.0;
//        double dist = 0.5;
//        double xr = (*norm_pts)(i,0,0,2) + dist * cos(theta - alpha);
//        double yr = (*norm_pts)(i,0,0,3) - dist * cos(theta - alpha);
//        double xl = (*norm_pts)(i,0,0,2) + dist * cos(theta + alpha);
//        double yl = (*norm_pts)(i,0,0,3) - dist * cos(theta + alpha);
//        viewer->DrawLineZ((*norm_pts)(i,0,0,2), (*norm_pts)(i,0,0,3), xr, yr);
//        viewer->DrawLineZ((*norm_pts)(i,0,0,2), (*norm_pts)(i,0,0,3), xl, yl);
      }
    }
  }
  viewer->DrawingAreaDisplay();
}

//Set input image for gaussian method
void SubPixel2D::setInput(InrImage* inp_image)
{
  input = inp_image;
}

//Get the input image
InrImage* SubPixel2D::getInput()
{
  return input;
}
vector<borderPixel> SubPixel2D::getBorderPixelVector()
{
  return borderPixelVector;
}

//Función original del código de Agustín (con los parámetros adaptados al wrapping)
//void SuperGradienteCurvo(InrImage* input, InrImage::ptr output, float* gx, float* gy, float* des, float* cu, unsigned char* borde, float umbral, int linear_case) {
//Nuevo cambio para usar la clase borderPixel. Se pasa un vector de la stl que contiene elementos de esta clase, el cual se irá rellenando
void SubPixel2D::SuperGradienteCurvo() 
{
  
  /* Calculamos el modulo del gradiente, argumento, desplazamiento y curvatura.
  El calculo de A y B hay que mejorarlo. Ahora mismo usamos un promedio de tres 
  pixels para cada uno (encima y debajo de la curva) */
  
  int nx = input->DimX();
  int ny = input->DimY();
  long n;
//  long size = (long)nx*ny;
  double sr, sm, sl, s1, s2;
  short margen = 4;		// cerca del margen no puedo calcular el gradiente
  double a, b, c;
  double A, B, mod;
  double den;
  double gx_n, gy_n, des_n, cu_n;
  double parcial;
  int *u, *v;
  unsigned char caso;
  //int uneg[33], vneg[33];
  int upos[] = {	 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 		// parciales
		 1, 1, 1, 1, 1, 0, 0, 0, 0, 0,-1,-1,-1,-1,-1,	// sumas
                                                  //1, 1, 0,-1,-1, 0,				// A,B
 };
  int vpos[] = {	 1,-1,-1,-3, 0,-2, 2, 0, 3, 1, 0,-2, 		// parciales
      -2,-1, 0, 1, 2,-2,-1, 0, 1, 2,-2,-1, 0, 1, 2,	// sumas
                                                    //1, 2, 2,-1,-2,-2,				// A,B
   };
  int z = 0;
  
  borderPixel pixel; 
  
  // inicializamos los desplazamientos negativos
//  for (int t = 0; t < 33; t++) {
//    uneg[t] = -upos[t];
//    vneg[t] = -vpos[t];
//  }
  
  // inicializamos todo a cero 	      
//  for (long n = 0; n < size; n++) {
//    gx[n]    = gy[n] = des[n] = cu[n] = 0.0;
//    borde[n] = 0;
//  }
  
  // barremos la imagen
  for (int y = margen; y < ny-margen; y++) {
    for (int x = margen; x < nx-margen; x++) {
      n  = (long) y*nx + x;
      sr = sm = sl = 0.0;	
      
      // según la parcial que sea máxima decidimos el caso
      if (fabs(ffy(x,y,z))>fabs(ffx(x,y,z))) {
        caso = YMAX;
        u    = upos;
        v    = vpos;
      }
      else {
        caso = XMAX;
        u    = vpos;
        v    = upos;
      }
      
      int m = (ffx(x,y,z)*ffy(x,y,z)>0) ? 1 : -1;
      if (caso==XMAX) {
        A  = ((double) FF(x+2,y,z) + FF(x+2,y+m,z) + FF(x+1,y+m,z)) / 3.0;
        B  = ((double) FF(x-1,y-m,z) + FF(x-2,y-m,z) + FF(x-2,y,z)) / 3.0;
      } else {
        A  = ((double) FF(x,y+2,z) + FF(x+m,y+2,z) + FF(x+m,y+1,z)) / 3.0;
        B  = ((double) FF(x-m,y-1,z) + FF(x-m,y-2,z) + FF(x,y-2,z)) / 3.0;
      }
      
      // la parcial en y debe ser máxima en su columna
      parcial = fabs(FF(x+u[0],y+v[0],z) - FF(x+u[1],y+v[1],z));
      if (parcial < threshold) continue;
      if (fabs(FF(x+u[2],y+v[2],z) - FF(x+u[3],y+v[3],z)) > parcial) continue;
      if (fabs(FF(x+u[4],y+v[4],z) - FF(x+u[5],y+v[5],z)) > parcial) continue;
      if (fabs(FF(x+u[6],y+v[6],z) - FF(x+u[7],y+v[7],z)) > parcial) continue;
      if (fabs(FF(x+u[8],y+v[8],z) - FF(x+u[9],y+v[9],z)) > parcial) continue;
      
      // evitar que salgan bordes de grosor 2 en el caso que el
      // valor maximo de las parciales coincida
      if (parcial == fabs(FF(x+u[10],y+v[10],z) - FF(x+u[11],y+v[11],z))) continue;
      
      // sumamos las filas (columnas)
      for (int t=12; t<17; t++)
        sr += (double) FF(x+u[t],y+v[t],z);
      for (int t=17; t<22; t++)
        sm += (double) FF(x+u[t],y+v[t],z);
      for (int t=22; t<27; t++)
        sl += (double) FF(x+u[t],y+v[t],z);
      
      s1 = sr + sl;
      s2 = sm;
      
      /* version vieja de Agustin con un error al parecer
      // calculamos A y B 
      A   = ((double) FF(x+u[27],y+v[27],z) + FF(x+u[28],y+v[28],z) + FF(x+u[29],y+v[29],z)) / 3.0;
      B   = ((double) FF(x+u[30],y+v[30],z) + FF(x+u[31],y+v[31],z) + FF(x+u[32],y+v[32],z)) / 3.0;
      mod = A - B;
       */
      
      // nueva version de calculo de A y B gracias a Daniel
      
      mod = A - B;
      
//      cout << "mod = " << mod << " m = "<< m << endl;
//      cout << "sl = " << sl << " sr = " << sr << endl;
      
      
      // si está por debajo del umbral no nos sirve (ahora fabs tras la modificiación anterior)
      if (fabs(mod)< threshold) continue;
      
      // calculamos los coeficientes de la parabola
      b = (sr-sl) / 2 / mod;
//      cout << "sr="<<sr<<" sl="<<sl<<" mod="<<mod<<endl;
      c = (linear_case) ? 0 : (sl+sr-2*sm) / 2 / mod;
      //c = (s1-2*s2) / 2 / mod;
      //a = (2*sm-5*mod) / 2 / mod - c / 12; he vuelto a poner la forma antigua de calcular a (15/7/2010)
      a = (26*s2-60*A-60*B-s1) / 24 / mod;
      
      // calculamos el gradiente y el desplazamiento
      den = sqrt (1 + b*b);
      if (caso == YMAX) {
        gx_n  = b / den * mod;
        gy_n  = 1 / den * mod;
        des_n = (ffy(x,y,z) > 0) ? -a : a;
      }
      else {
        gx_n  = 1 / den * mod;
        gy_n  = b / den * mod;
        des_n = (ffx(x,y,z) > 0) ? -a : a;
      }	 
      
      // actualizamos los signos del gradiente
      if (ffx(x,y,z) <= 0) gx_n = -gx_n;
      if (ffy(x,y,z) <= 0) gy_n = -gy_n;
      
      // calculamos la curvatura
      cu_n = 2*c / den / den / den;
      
      
      OptimizarParabola (a, b, c, 0.001, RMIN, RMAX);
      den  = sqrt (1 + b*b);
      cu_n = 2*c / den / den / den;
      
      //El signo de la curvatura cambia en función del valor de la parcial
      if (caso == YMAX && ffy(x,y,z)<0) cu_n= -cu_n;
      if (caso == XMAX && ffx(x,y,z)<0) cu_n= -cu_n;

      //printf ("pixel (%d,%d) a=%f b=%f c=%f R=%f\n", x, y, a, b, c, 1/cu_n);
//      cout << "pixel (" << x << ", " << y << ") a = " << a << " b = " << b << " c = " << c << " R = " << 1/cu_n << endl;
     
      
      // volcamos los double al vector float
//      borde[n] = caso;
//      gx[n]    = (float) gx_n;
//      gy[n]    = (float) gy_n;
//      des[n]   = (float) des_n;
//      cu[n]    = (float) cu_n;

      pixel.setBorderPixelValues(A, B, caso, a, b, c, cu_n, x, y);
//      cout << "desp = " << des_n << endl;
//      pixel.printBorderPixel(linear_case);
      //Add edge pixel to the vector
      borderPixelVector.push_back(pixel);
    }
  }
}

void SubPixel2D::fillImages(vector<borderPixel> &borderPixelVector, 
                            InrImage::ptr AIntensity, InrImage::ptr BIntensity, 
                            InrImage::ptr border, InrImage::ptr a,
                            InrImage::ptr b, InrImage::ptr c, 
                            InrImage::ptr curvature, 
                            InrImage::ptr posx, InrImage::ptr posy)
{
  int x    = 0;
  int y    = 0;
  int z    = 0;
  
  for(vector<borderPixel>::iterator i=borderPixelVector.begin(); 
      i!= borderPixelVector.end(); i++, x++)
  {
    //A intensity
    AIntensity->BufferPos(x,y,z);
    AIntensity->FixeValeur(i->getAIntensity());
    //B intensity
    BIntensity->BufferPos(x,y,z);
    BIntensity->FixeValeur(i->getBIntensity());
    //Border type
    border->BufferPos(x,y,z);
    border->FixeValeur(i->getBorder());
    //Coefficient a
    a->BufferPos(x,y,z);
    a->FixeValeur(i->getCoefficient_a());
    //Coefficient b
    b->BufferPos(x,y,z);
    b->FixeValeur(i->getCoefficient_b());
    //Coefficient c
    c->BufferPos(x,y,z);
    c->FixeValeur(i->getCoefficient_c());
    //Curvature
    curvature->BufferPos(x,y,z);
    curvature->FixeValeur(i->getCurvature());
    //X position
    posx->BufferPos(x,y,z);
    posx->FixeValeur(i->getPosX());
    //Y position
    posy->BufferPos(x,y,z);
    posy->FixeValeur(i->getPosY());
  }
}

//---------------------------------------------
//Sub-pixel 2D denoising method
//---------------------------------------------

//Función de suavizado (por ahora 23/07/2010)
void SubPixel2D::Promedio3x3 (/*InrImage* input,*/ InrImage* result, 
                              double a00, double a01, double a11)
/* suavizamos la imagen rim0 con un promedio y devolvemos en rim1*/
{
  double suma;
//  long size= (long) input->DimX() * input->DimY();
  float s = (float) a00 + 4*a01 + 4*a11;
  int x, y;
  int z = 0;
  
  
  // suavizamos el interior
  for (y=1; y<input->DimY()-1; y++)
  {
    for (x=1; x<input->DimX()-1; x++) 
    {
//      n = y*nx + x;
//      suma = a00/s * rim0[n];
      suma = a00/s * FF(x,y,z);
//      suma += a01/s * (rim0[n-nx]+rim0[n+nx]+rim0[n-1]+rim0[n+1]);
      suma += a01/s * (FF(x-1,y,z)+FF(x+1,y,z)+FF(x,y-1,z)+FF(x,y+1,z));
//      suma += a11/s * (rim0[n-1-nx]+rim0[n-1+nx]+rim0[n+1-nx]+rim0[n+1+nx]);
      suma += a11/s * (FF(x-1,y-1,z)+FF(x+1,y-1,z)+FF(x-1,y+1,z)+FF(x+1,y+1,z));
//      rim1[n] = suma;	
      result->BufferPos(x,y,z);
      result->FixeValeur(suma);
    }
  }
  
  
  // promediamos los márgenes
//  for (long n=1; n<nx-1; n++)
//    rim1[n] = (rim0[n-1]+rim0[n]+rim0[n+1]) / 3;
  //TOP
  y = 0;
  for(x=1; x<input->DimX()-1; x++)
  {
    suma = ((*input)(x-1,y,z)+(*input)(x,y,z)+(*input)(x+1,y,z)) / 3;
    result->BufferPos(x,y,z);
    result->FixeValeur(suma);
  }
  
//  for (long n=size-nx+1; n<size-1; n++) 
//    rim1[n] = (rim0[n-1]+rim0[n]+rim0[n+1]) / 3;
  //BOTTOM
  y = input->DimY()-1;
  for(x=1; x<input->DimX()-1; x++)
  {
    suma = ((*input)(x-1,y,z)+(*input)(x,y,z)+(*input)(x+1,y,z)) / 3;
    result->BufferPos(x,y,z);
    result->FixeValeur(suma);
  }

//  for (long n=nx; n<size-nx; n+=nx) 
//    rim1[n] = (rim0[n-nx]+rim0[n]+rim0[n+nx]) / 3;
  //LEFT
  x = 0;
  for(y=1; y<input->DimY()-1; y++)
  {
    suma = ((*input)(x,y-1,z)+(*input)(x,y,z)+(*input)(x,y+1,z)) / 3;
    result->BufferPos(x,y,z);
    result->FixeValeur(suma);
  }

//  for (long n=2*nx-1; n<size-nx; n+=nx) 
//    rim1[n] = (rim0[n-nx]+rim0[n]+rim0[n+nx]) / 3;
  //RIGHT
  x = input->DimX()-1;
  for (y=1; y<input->DimY()-1; y++)
  {
    suma = ((*input)(x,y-1,z)+(*input)(x,y,z)+(*input)(x,y+1,z)) /3;
    result->BufferPos(x,y,z);
    result->FixeValeur(suma);
  }
  
  // promediamos las esquinas
//  rim1[0] = (2*rim0[0]+rim0[1]+rim0[nx]) / 4;
  //0,0,0 left-up corner
  suma = (2*(*input)(0,0,0)+(*input)(1,0,0)+(*input)(0,1,0)) / 4;
  result->BufferPos(0,0,0);
  result->FixeValeur(suma);
//  rim1[nx-1] = (2*rim0[nx-1]+rim0[nx-2]+rim0[2*nx-1]) / 4;
  //DimX-1,0,0 right-up corner
  suma = (2*(*input)(input->DimX()-1,0,0)+(*input)(input->DimX()-2,0,0)+
          (*input)(input->DimX()-1,1,0)) / 4;
  result->BufferPos(input->DimX()-1,0,0);
  result->FixeValeur(suma);
  //0,DimY-1,0 left-down corner
//  rim1[size-nx] = (2*rim0[size-nx]+rim0[size-2*nx]+rim0[size-nx+1]) / 4;
  suma = (2*(*input)(0,input->DimY()-1,0)+(*input)(0,input->DimY()-2,0)+
          (*input)(1,input->DimY()-1,0)) / 4;
  result->BufferPos(0,input->DimY()-1,0);
  result->FixeValeur(suma);
  //DimX-1,DimY-1,0 right-down corner
//  rim1[size-1] = (2*rim0[size-1]+rim0[size-1-nx]+rim0[size-2]) / 4;
  suma = (2*(*input)(input->DimX()-1,input->DimY()-1,0)+
            (*input)(input->DimX()-1, input->DimY()-2,0)+
            (*input)(input->DimX()-2,input->DimY()-1,0)) / 4;
  result->BufferPos(input->DimX()-1,input->DimY()-1,0);
  result->FixeValeur(suma);
}

//---------------------------------------------
//SuperGradienteGaussianoCurvo (modificado con referencia a lo anterior)
//---------------------------------------------

//void SuperGradienteGaussianoCurvo (float *data, short nx, short ny, 
//				float *gx, float *gy, float *des, float *cu, 
//				unsigned char *borde,
//				float *vecA, float *vecB, double uop, float umbral)
void SubPixel2D::SuperGradienteGaussianoCurvo()//,
                                  //int A00, int A01, int A11)
/* En vecA y vecB, en caso de no ser nulos, guardo los valores de A y B
	para cada pixel borde */
{
//  long size=(long)nx*ny;
//  long size = (long) input->DimX()*input->DimY();
  int margen = 4;		// cerca del margen no puedo calcular el gradiente 
//  int x, y;
//  long n;
  double A, B;
  double S1, S2, S3;
  double a, b, c, d;// temp;
  double f = (1+24*A01+48*A11) / 12;
//  double a1, b1, c1, a2, b2, c2, a0, b0, c0;
//  double p1, p3, p5, pm1, pm3, pm5;
  double parcial;
//  double dx, dy;
  double gx_n, gy_n, des_n, cu_n, abscu;
//  double xc, yc;
//  double r, d1, d2;
  int *u, *v;
  unsigned char caso;
//  int uneg[37], vneg[37];
  int upos[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,	// parciales
    0, 1, 1, 0,-1,-1,			// A y B (no usado)
    -1,-1,-1,-1,-1,-1,-1,		// sumas de columnas 
    0, 0, 0, 0, 0, 0, 0, 
    1, 1, 1, 1, 1, 1, 1,
  };
  int vpos[] = { 1,-1,-1,-3, 0,-2, 2, 0, 3, 1,	// parciales
    4, 3, 4,-4,-3,-4,			// A y B (no usado)
    -2,-1, 0, 1, 2, 3, 4,		// sumas de columnas
    -3,-2,-1, 0, 1, 2, 3,	
    -4,-3,-2,-1, 0, 1, 2,	 
  };
  int z = 0;
  borderPixel pixel;
  
  // inicializamos todo a cero 	 (no usado, se usa el vector de la stl)     
//  for (long n=0; n<size; n++) {
//    gx[n] = gy[n] = des[n] = cu[n] = 0.0;
//    borde[n] = 0;
//  }
  
  // inicializamos los desplazamientos negativos
//  for (int t=0; t<37; t++) {
//    uneg[t] = -upos[t];
//    vneg[t] = -vpos[t];
//  }
  
  // barremos todos los pixels
  for (int y = margen; y < input->DimY()-margen; y++) 
  {
    for (int x = margen; x < input->DimX()-margen; x++) 
    {
      // según la parcial decidimos el caso
      if (fabs(ffy(x,y,z))>=fabs(ffx(x,y,z))) {
        caso = YMAX;
        //      u = (ffx(x,y)>0)? upos : uneg;
        //      v = (ffy(x,y)>0)? vpos : vneg;
        u = upos;
        v = vpos;
      } else {
        caso = XMAX;
        //      u = (ffx(x,y)>0)? vpos : vneg;
        //      v = (ffy(x,y)>0)? upos : uneg;
        u = vpos;
        v = upos;
      }
      
      //Se calcula A y B de la misma forma que en el código anterior, salvo que ahora la ventana es más grande
      int m = (ffx(x,y,z)*ffy(x,y,z)>0) ? 1 : -1;
      if (caso==XMAX) {
        B  = ((double) FF(x-3,y-m,z) + FF(x-4,y-m,z) + FF(x-4,y,z)) / 3.0;
        A  = ((double) FF(x+4,y,z) + FF(x+4,y+m,z) + FF(x+3,y+m,z)) / 3.0;
      } else {
        B  = ((double) FF(x-m,y-3,z) + FF(x-m,y-4,z) + FF(x,y-4,z)) / 3.0;
        A  = ((double) FF(x,y+4,z) + FF(x+m,y+4,z) + FF(x+m,y+3,z)) / 3.0;
      }
      // si está por debajo del umbral no nos sirve (en valor absoluto)
      if (fabs(A-B)<threshold) continue;
      
      // la parcial en y debe ser máxima en su columna
      parcial = fabs(FF(x+u[0],y+v[0],z) - FF(x+u[1],y+v[1],z));
      if (parcial < threshold) continue;
      if (fabs(FF(x+u[2],y+v[2],z) - FF(x+u[3],y+v[3],z)) > parcial) continue;
      if (fabs(FF(x+u[4],y+v[4],z) - FF(x+u[5],y+v[5],z)) > parcial) continue;
      if (fabs(FF(x+u[6],y+v[6],z) - FF(x+u[7],y+v[7],z)) > parcial) continue;
      if (fabs(FF(x+u[8],y+v[8],z) - FF(x+u[9],y+v[9],z)) > parcial) continue;
      
      // estimamos el color de ambos lados del borde
      //    A = FF(x+u[10],y+v[10]) + FF(x+u[11],y+v[11]) + FF(x+u[12],y+v[12]);
      //    A /= 3.0;
      //    B = FF(x+u[13],y+v[13]) + FF(x+u[14],y+v[14]) + FF(x+u[15],y+v[15]);
      //    B /= 3.0;
      
      
      // guardamos A y B si es el caso
//      n = (long)y*nx + x;
//      if (vecA) {
//        vecA[n] = A;
//        vecB[n] = B;
//      }
      
      // calculamos las sumas de las columnas
      S1 = S2 = S3 = 0.0;
      for (int t=-3; t<=3; t++) {
        S1 += FF(x+u[19+t],y+v[19+t],z);
        S2 += FF(x+u[26+t],y+v[26+t],z);
        S3 += FF(x+u[33+t],y+v[33+t],z);
      }
      
      // calculamos los coeficientes de la parábola
      a = (2*S2 - 7*(A+B)) / (2*(A-B));
      b = 1.0 + (S3-S1) / (2*(A-B));
      c = (linear_case) ? 0 : (S3+S1-2*S2) / (2*(A-B)); //En caso lineal no hay curvatura
      a -= f * c;
      
      /*// si el radio es muy chico hacemos trampa
       { double raiz, r, rmin=5, cu;
       raiz = sqrt (1+b*b);
       cu = raiz * raiz * raiz;
       cu = -2*c / cu;
       r = fabs(1/cu);
       if (r < rmin) {			
       
       // generando arco con R pequeño
       cu = (cu>0)? 1/rmin : -1/rmin;
       a += f * c;
       temp = sqrt(1+b*b);
       c = cu * temp * temp * temp / (-2);
       a -= f * c;
       }
       }
       */			
      // se quiere optimizar la curvatura?? TODO: Ver que es uop para ver si hay que optimizar la curvatura
//      if (uop>1e-5) OptimizarParabola (a, b, c, uop, RMIN, RMAX);	
      
      // calculamos la curvatura
      cu_n  = sqrt (1+b*b);
      cu_n *= cu_n * cu_n;
      cu_n  = 2*c / cu_n;
      abscu = fabs(cu_n); //TODO: Ver si es necesario cambiar el signo para la normal
      
      //if (x==16 && y==16) printf ("coño: a=%f b=%f c=%f R=%f\n", a, b, c, 1/cu_n);
      
      // calculamos el gradiente y el desplazamiento
      d = (A-B) / sqrt(1+b*b);
      if (caso==YMAX) {
        gx_n  = (ffx(x,y,z)>0) ? b*d : -b*d;
        gy_n  = (ffy(x,y,z)>0) ? d   : -d;
        des_n = (ffy(x,y,z)>0) ? -a  : a;
      } else {
        gx_n  = (ffx(x,y,z)>0) ? d   : -d;
        gy_n  = (ffy(x,y,z)>0) ? b*d : -b*d; 
        des_n = (ffx(x,y,z)>0) ? -a  : a;
      }  

      //El signo de la curvatura cambia en función del valor de la parcial
      if (caso == YMAX && ffy(x,y,z)<0) cu_n = -cu_n;
      if (caso == XMAX && ffx(x,y,z)<0) cu_n = -cu_n;
      
      
      //if (SelectedGW[0]->IMGdata[n] == 150) { 
      /*
       if (x==13 && y==13) {
       //printf ("-----SuperGradienteGaussianoCurvo\n");
       printf ("pixel(%d,%d) caso=%d\n", x, y, caso);
       //if (factor) printf ("       valores viejos a=%f b=%f c=%f\n", a0, b0, c0);
       printf ("	valores nuevos a=%f b=%f c=%f\n", a, b, c);
       printf ("	G=(%f, %f). parc=(%f, %f)\n", gx_n, gy_n,ffx(x,y),ffy(x,y));
       printf ("	des=%f, cu=%f, R=%f\n", des_n, cu_n, 1/cu_n);
       printf ("	S1=%f, S2=%f, S3=%f\n", S1, S2, S3);
       }
       */
      
      // volcamos los double al vector float
//      borde[n] = caso;
//      gx[n] = (float) gx_n;
//      gy[n] = (float) gy_n;
//      des[n] = (float) des_n;
//      cu[n] = (float) cu_n;
      pixel.setBorderPixelValues(A, B, caso, a, b, c, cu_n, x, y);
//      pixel.printBorderPixel(linear_case);
      //Add edge pixel to the vector
      borderPixelVector.push_back(pixel);
    } //End x for
  } //End y for
}

