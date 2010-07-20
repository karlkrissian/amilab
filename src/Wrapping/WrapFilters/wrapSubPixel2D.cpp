/*
 *  subPixel2D.cpp
 */
#ifdef WIN32
  #include <float.h>
  #define isnan _isnan
#endif

#include "wrapSubPixel2D.h"
#include <cmath>
#include "inrimage.hpp"
#include "paramlist.h"
#include "ami_object.h"
#include "wrapfunctions.hpp"
#include <vector>
#include <iostream>
using namespace std;

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


//borderPixel class methods
void borderPixel::setBorderPixelValues(double intA, double intB, unsigned char bord,
                                       double coef_a, double coef_b, double coef_c,
                                       double cu, int posx, int posy)
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

void borderPixel::printBorderPixel()
{
  cout << "----------------------------------" << endl;
  cout << "Pixel (" << px << ", " << py << ")" << endl;
  cout << "Border       = " << (int)border << endl;
  cout << "A intensity  = " << A << endl;
  cout << "B intensity  = " << B << endl;
  cout << "Curve coefficients: a = " << a << ", b = " << b << ", c = " << c << endl;
  if (c==0)
  { 
    double rad = atan(b);
    cout << "Angle        = " << (rad*360)/(2*3.141592741) << endl;
  }
  else
  {
    cout << "Radius       = " << 1/curvature << endl;
  }
  cout << "----------------------------------" << endl;
}


inline void OptimizarParabola (double &a, double &b, double &c, double umbral, double rmin, double rmax) {
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

//Función original del código de Agustín (con los parámetros adaptados al wrapping)
//void SuperGradienteCurvo(InrImage* input, InrImage::ptr output, float* gx, float* gy, float* des, float* cu, unsigned char* borde, float umbral, int linear_case) {
//Nuevo cambio para usar la clase borderPixel. Se pasa un vector de la stl que contiene elementos de esta clase, el cual se irá rellenando
void SuperGradienteCurvo(InrImage* input, vector<borderPixel> &borderPixelVector, float umbral, int linear_case) {
  
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
  int uneg[33], vneg[33];
  int upos[] = {	 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 		// parciales
		 1, 1, 1, 1, 1, 0, 0, 0, 0, 0,-1,-1,-1,-1,-1,	// sumas
		 1, 1, 0,-1,-1, 0,				// A,B
 };
  int vpos[] = {	 1,-1,-1,-3, 0,-2, 2, 0, 3, 1, 0,-2, 		// parciales
      -2,-1, 0, 1, 2,-2,-1, 0, 1, 2,-2,-1, 0, 1, 2,	// sumas
       1, 2, 2,-1,-2,-2,				// A,B
   };
  int z = 0;
  
  borderPixel pixel;
  
  // inicializamos los desplazamientos negativos
  for (int t = 0; t < 33; t++) {
    uneg[t] = -upos[t];
    vneg[t] = -vpos[t];
  }
  
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
        u    = (ffx(x,y,z)>0)? upos : uneg;
        v    = (ffy(x,y,z)>0)? vpos : vneg;
      }
      else {
        caso = XMAX;
        u    = (ffx(x,y,z)>0)? vpos : vneg;
        v    = (ffy(x,y,z)>0)? upos : uneg;
      }
      
      // la parcial en y debe ser máxima en su columna
      parcial = fabs(FF(x+u[0],y+v[0],z) - FF(x+u[1],y+v[1],z));
      if (parcial < umbral) continue;
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
      int m = (ffx(x,y,z)*ffy(x,y,z)>0) ? 1 : -1;
      if (caso==XMAX) {
        A  = ((double) FF(x+2,y,z) + FF(x+2,y+m,z) + FF(x+1,y+m,z)) / 3.0;
        B  = ((double) FF(x-1,y-m,z) + FF(x-2,y-m,z) + FF(x-2,y,z)) / 3.0;
      } else {
        A  = ((double) FF(x,y+2,z) + FF(x+m,y+2,z) + FF(x+m,y+1,z)) / 3.0;
        B  = ((double) FF(x-m,y-1,z) + FF(x-m,y-2,z) + FF(x,y-2,z)) / 3.0;
      }
      mod = A - B;
      
      cout << "mod = " << mod << " m = "<< m << endl;
      cout << "sl = " << sl << " sr = " << sr << endl;
      
      
      // si está por debajo del umbral no nos sirve (ahora fabs tras la modificiación anterior)
      if (fabs(mod)< umbral) continue;
      
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
      
      
      
      if(c!=0) OptimizarParabola (a, b, c, 0.001, RMIN, RMAX);
      den  = sqrt (1 + b*b);
      cu_n = 2*c / den / den / den;
      //printf ("pixel (%d,%d) a=%f b=%f c=%f R=%f\n", x, y, a, b, c, 1/cu_n);
//      cout << "pixel (" << x << ", " << y << ") a = " << a << " b = " << b << " c = " << c << " R = " << 1/cu_n << endl;
//      cout << "g(x) = " << gx_n << " g(y) = " << gy_n << endl;
//      cout << "A    = " << A << endl;
//      cout << "B    = " << B << endl;
//      if (c==0){ 
//        double rad = atan(b);
//        cout << "Angle= " << (rad*360)/(2*3.141592741) << endl;
//      }
     
      
      // volcamos los double al vector float
//      borde[n] = caso;
//      gx[n]    = (float) gx_n;
//      gy[n]    = (float) gy_n;
//      des[n]   = (float) des_n;
//      cu[n]    = (float) cu_n;

      pixel.setBorderPixelValues(A, B, caso, a, b, c, cu_n, x, y);
//      cout << "desp = " << des_n << endl;
      pixel.printBorderPixel();
      //Add edge pixel to the vector
      borderPixelVector.push_back(pixel);
    }
  }
}

void fillImages(vector<borderPixel> &borderPixelVector, InrImage::ptr AIntensity,
                InrImage::ptr BIntensity, InrImage::ptr border, InrImage::ptr a,
                InrImage::ptr b, InrImage::ptr c, InrImage::ptr curvature, 
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

//float *data, int nx, int ny, float *gx, float *gy, float *des, float *cu, unsigned char *borde, float umbral)
BasicVariable::ptr wrapSubpixel2D (ParamList* p) {
  //Information
	char functionname[] = "wrapSubpixel2D";
  char description[]=" \n\
	Aplicates edge subpixel detection method for 2D images \n\
	\n\
	";
  char parameters[] =" \n\
	Parameters:\n\
	input: The input image\n\
	umbral: Threshold\n\
	linear_case: Says if it's first or second order\n\
	";
  
  InrImage* input;
  int num = 0;
  //Get input image
  if (!get_val_ptr_param<InrImage>(input, p, num)) HelpAndReturnVarPtr;
  InrImage::ptr output (new InrImage(WT_FLOAT, "sub2DResult.ami.gz", input)); 
  output->InitZero(); //Ahora mismo la imagen de salida está vacía!!!!!!!!!!!!!
  
//  float* gx = new float[input->DimX()*input->DimY()];
//  float* gy = new float[input->DimX()*input->DimY()];
//  float* des = new float[input->DimX()*input->DimY()];
//  float* cu = new float[input->DimX()*input->DimY()];
//  unsigned char* borde = new unsigned char[input->DimX()*input->DimY()];
  //------
  float umbral;
  int linear_case;
  vector<borderPixel> borderPixelVector;
  
  //Get params
  if (!get_val_param<float>(umbral, p, num)) HelpAndReturnVarPtr;
  if (!get_int_param(linear_case, p, num)) HelpAndReturnVarPtr;
  
  //Calls to SuperGradienteCurvo
  //SuperGradienteCurvo(input, output, gx, gy, des, cu, borde, umbral, linear_case);
  SuperGradienteCurvo(input, borderPixelVector, umbral, linear_case);
  
  //Se crea el AMIObject y se encapsulan dentro las imágenes que representan cada parámetro
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("Sub-pixel2D");
  int size = borderPixelVector.size();
  //InrImages for params
  InrImage::ptr AIntensity = InrImage::ptr(new InrImage(size, 1, 1, WT_DOUBLE,
                                                        "aintensity.inr.gz"));
  InrImage::ptr BIntensity = InrImage::ptr(new InrImage(size, 1, 1, WT_DOUBLE,
                                                        "bintensity.inr.gz"));
  InrImage::ptr border     = InrImage::ptr(new InrImage(size, 1, 1, WT_UNSIGNED_CHAR,
                                                        "border.inr.gz"));
  InrImage::ptr a          = InrImage::ptr(new InrImage(size, 1, 1, WT_DOUBLE,
                                                        "acoef.inr.gz"));
  InrImage::ptr b          = InrImage::ptr(new InrImage(size, 1, 1, WT_DOUBLE,
                                                        "bcoef.inr.gz"));
  InrImage::ptr c          = InrImage::ptr(new InrImage(size, 1, 1, WT_DOUBLE,
                                                        "ccoef.inr.gz"));
  InrImage::ptr curvature  = InrImage::ptr(new InrImage(size, 1, 1, WT_DOUBLE,
                                                        "curvature.inr.gz"));
  InrImage::ptr posx       = InrImage::ptr(new InrImage(size, 1, 1, WT_UNSIGNED_SHORT,
                                                        "xpos.inr.gz"));
  InrImage::ptr posy       = InrImage::ptr(new InrImage(size, 1, 1, WT_UNSIGNED_SHORT,
                                                        "ypos.inr.gz"));
  
  //Fill InrImages
  fillImages(borderPixelVector, AIntensity, BIntensity, border, a, b, c, 
             curvature, posx, posy);
  //Add to amiobject
  amiobject->GetContext()->AddVar<InrImage>("aintensity", AIntensity, 
                                            amiobject->GetContext());
  amiobject->GetContext()->AddVar<InrImage>("bintensity", BIntensity,
                                            amiobject->GetContext());
  amiobject->GetContext()->AddVar<InrImage>("border", border,
                                            amiobject->GetContext());
  amiobject->GetContext()->AddVar<InrImage>("acoef", a,
                                            amiobject->GetContext());
  amiobject->GetContext()->AddVar<InrImage>("bcoef", b,
                                            amiobject->GetContext());
  amiobject->GetContext()->AddVar<InrImage>("ccoef", c,
                                            amiobject->GetContext());
  amiobject->GetContext()->AddVar<InrImage>("curvature", curvature,
                                            amiobject->GetContext());
  amiobject->GetContext()->AddVar<InrImage>("xpos", posx,
                                            amiobject->GetContext());
  amiobject->GetContext()->AddVar<InrImage>("ypos", posy,
                                            amiobject->GetContext());

  //Borramos la solución temporal y por ahora se devuelve input tal cual
//  delete[] borde;
//  delete[] gx;
//  delete[] gy;
//  delete[] des;
//  delete[] cu;
  
//  Variable<InrImage>::ptr result(
//    new Variable<InrImage>( "subpixel_result",
//                            output));
  Variable<AMIObject>::ptr result(
      new Variable<AMIObject>(amiobject));
  return result;

}

