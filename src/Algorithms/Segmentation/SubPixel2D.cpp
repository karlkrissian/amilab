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
#include "AnalyticLine.h"
#include "ComputePartialVolume.h"
#include <wx/colour.h>

//Type of edge: Vertical or horizontal (based on the maximum partial)
#define XMAX	1
#define YMAX	2

//Maximum and minimum radius (in pixels) in an image (used on SupGradGausCurvo)
//A radius greater is considered as a line
#define RMAX	200.0
//Lower radius are considered as noise
#define RMIN	10.0

//Primitive of the circle
#define P(x) (yc*(x) + 0.5*r*r*asin((x-xc)/r) + 0.5*(x-xc)*sqrt(r*r-(x-xc)*(x-xc)))

//Test if the indexes are inside the image, when calculate a partial
double imval(InrImage* input, int x,int y, int z){
  if (input->CoordOK(x,y,z)) 
    return (*input)(x,y,z);
  else 
    cout << "out of image range (" << x << ", " << y << ", " << z << ")" << endl;
  return 0;
}
//Partials
#define FF(x,y,z)		imval(input,x,y,z)
#define ffx(x,y,z) 	(FF(x+1,y,z) - FF(x-1,y,z))
#define ffy(x,y,z) 	(FF(x,y+1,z) - FF(x,y-1,z))
#define ffyd(x,y,z) (FF(x, y+1, z) - FF(x,y,z))
#define ffyu(x,y,z)	(FF(x,y,z) - FF(x,y-1,z))
#define ffxl(x,y,z) (FF(x,y,z) - FF(x-1,y,z))
#define ffxr(x,y,z)	(FF(x+1,y,z) - FF(x,y,z))

//Swap int
int INT_TEMP;
#define SWAP_INT(a,b) INT_TEMP=a; a=b; b=INT_TEMP

//Coefficients of the mask
double A00 = (double) 1 / 9;
double A01 = (double) 1 / 9;
double A11 = (double) 1 / 9;


//---------------------------------------------
//borderPixel class methods
//---------------------------------------------
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
}


//---------------------------------------------
//SubPixel2D class methods
//---------------------------------------------
//Constructor
SubPixel2D::SubPixel2D(InrImage* inp_image, float thres, int lc)
{
  input       = inp_image;
  threshold   = thres;
  linear_case = lc;
}

//Destructor
SubPixel2D::~SubPixel2D(){}

//Optimize parable
void SubPixel2D::OptimizarParabola (double &a, double &b, double &c, 
                                    double threshold, double rmin, double rmax)
{
  double cu, temp, f=0.75;
  double a0, b0, c0, xc, yc, raiz;
  double a1, b1, c1, a2, b2, c2;
  double p1, p3, p5, pm1, pm3, pm5;
  bool   inv_signo = false;
  double r, rprev, rvar, rvar0=10;
  
  //Calculate curvature
  raiz = sqrt (1+b*b);
  cu   = raiz * raiz * raiz;
  cu   = -2*c / cu;
  r    = fabs(1/cu);
  
  //cout << "Start a = " << a << " b = " << b << " c = " << c << " r = " << r << endl;
  
  //From here, always is true that c<0 and cu>0
  //if the curvature is too small, we don't use the factor correction
  if (r > rmax) return;
  
  //If the curvature is too large, it must be an error.
  //2 alternatives: If we believe that is a small radius, we can generate the arc
  //of minimum R. But, if we beleve that is noise, we can generate a straight line
  if (r < rmin) {			
    //Generating arc with small R
    cu   = (cu>0)? 1/rmin : -1/rmin;
    a   += f * c;
    temp = sqrt(1+b*b);
    c    = cu * temp * temp * temp / (-2);
    a   -= f * c;
    //cout << "r very small " << r << endl;
    return;
  }
  
  //Only it works for parables with negative c
  if (c>0) {
    inv_signo = true;
    a         = -a; 
    c         = -c;
  }	
  
  //Save original values returned by the method
  a0 = a; b0 = b; c0 = c;
  
	
  //Many iterations that the factor indacates
  do { 		
    //Calculate the center of the circle
    xc  = b * r / raiz;
    yc  = a - (r/raiz);
		
    //Calculate the primitives of the circle
    p5  = P(2.5);
    p3  = P(1.5);
    p1  = P(0.5);
    pm1 = P(-0.5);
    pm3 = P(-1.5);
    pm5 = P(-2.5);
    
    //Calculate new coefficients
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
     cout << "a0 = " << a0 << " a1 = " << a1 << " a2 = " << a2 << endl;
     cout << "b0 = " << b0 << " b1 = " << b1 << " b2 = " << b2 << endl;
     cout << "c0 = " << c0 << " c1 = " << c1 << " c2 = " << c2 << endl;
     */	
    //Review that the factor correction has a correct value
    if (isnan(a) || isnan(b) || isnan(c) 
        || fabs(a2-a1)>0.5 || fabs(b2-b1)>fabs(b0) 
        || fabs(c2-c1)>fabs(c0)) {
      a = a0;
      b = b0;
      c = c0;
      break;
    }
    
    //We see the variation of the radius
    rprev = r;
    raiz  = sqrt (1+b*b);
    cu    = raiz * raiz * raiz;
    cu    = -2*c / cu;
    r     = 1 / cu;
    rvar  = fabs(r-rprev) / rprev;
    //cout << "a = " << a << " b = " << b << " c = " << c << " C = (" << xc << ", " << yc << ") r = " << r << "var(r) = " << rvar << endl;
    if (rvar > rvar0) break;
    rvar0 = rvar;
    
  } while (rvar > threshold);
  
  //If we change de sign, we restore it
  if (inv_signo) { a = -a; c = -c; }
}

//drawBorder method
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
    for(int i=0; i<norm_pts->DimX(); i++)
    {
      if ((*inside)(i,0,0))
      {
        viewer->DrawLineZ((*norm_pts)(i,0,0,0), (*norm_pts)(i,0,0,1), 
                          (*norm_pts)(i,0,0,2), (*norm_pts)(i,0,0,3));
        
        //Draw the arrowhead
        double px, py;
        px = ((*border_pts)(i,0,0,0)+(*norm_pts)(i,0,0,2)) / 2;
        py = ((*border_pts)(i,0,0,1)+(*norm_pts)(i,0,0,3)) / 2;
        
        viewer->DrawLineZ((*norm_pts)(i,0,0,2), (*norm_pts)(i,0,0,3), px, py);
        
        px = ((*border_pts)(i,0,0,2)+(*norm_pts)(i,0,0,2)) / 2;
        py = ((*border_pts)(i,0,0,3)+(*norm_pts)(i,0,0,3)) / 2;
        
        viewer->DrawLineZ((*norm_pts)(i,0,0,2), (*norm_pts)(i,0,0,3), px, py);
      }
    }
  }
  //Refresh the viewer
  viewer->DrawingAreaDisplay();
}

//Set input image method
void SubPixel2D::setInput(InrImage* inp_image)
{
  input = inp_image;
}

//Get the input image
InrImage* SubPixel2D::getInput()
{
  return input;
}

//Get the border pixel vector
vector<borderPixel> SubPixel2D::getBorderPixelVector()
{
  return borderPixelVector;
}

//Basic SubPixel 2D detection method, using a 5x3 window (1st and 2nd order)
void SubPixel2D::SuperGradienteCurvo() 
{
  //Calculate the gradient module, the argument, displacement and curvature
  
  int nx = input->DimX();
  int ny = input->DimY();
  double sr, sm, sl, s1, s2;
  short margin = 4;
  double a, b, c;
  double A, B, mod;
  double den;
  double gx_n, gy_n, des_n, cu_n;
  double partial;
  //Pointers for partials indexes (based on maximum partial)
  int *u, *v;
  unsigned char edgeCase;
  //Partials and sums indexes
  int upos[] = {	 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  //partials
		 1, 1, 1, 1, 1, 0, 0, 0, 0, 0,-1,-1,-1,-1,-1 };     //sums
  int vpos[] = {	 1,-1,-1,-3, 0,-2, 2, 0, 3, 1, 0,-2, 	//partials
      -2,-1, 0, 1, 2,-2,-1, 0, 1, 2,-2,-1, 0, 1, 2};    //sums
  //3rd component of InrImage
  int z = 0;
  //BorderPixel object
  borderPixel pixel; 
  
  //For all pixels
  for (int y = margin; y < ny-margin; y++)
  {
    for (int x = margin; x < nx-margin; x++)
    {
      //Initialize sums
      sr = sm = sl = 0.0;	
      
      //Based on maximum partial, we decide the case
      if (fabs(ffy(x,y,z))>fabs(ffx(x,y,z))) 
      {
        edgeCase = YMAX;
        u        = upos;
        v        = vpos;
      }
      else 
      {
        edgeCase = XMAX;
        u        = vpos;
        v        = upos;
      }
      
      int m = (ffx(x,y,z)*ffy(x,y,z)>0) ? 1 : -1;
      
      if (edgeCase==XMAX) 
      {
        A  = ((double) FF(x+2,y,z) + FF(x+2,y+m,z) + FF(x+1,y+m,z)) / 3.0;
        B  = ((double) FF(x-1,y-m,z) + FF(x-2,y-m,z) + FF(x-2,y,z)) / 3.0;
      } 
      else 
      {
        A  = ((double) FF(x,y+2,z) + FF(x+m,y+2,z) + FF(x+m,y+1,z)) / 3.0;
        B  = ((double) FF(x-m,y-1,z) + FF(x-m,y-2,z) + FF(x,y-2,z)) / 3.0;
      }
      
      partial = fabs(FF(x+u[0],y+v[0],z) - FF(x+u[1],y+v[1],z));
      //If the partial is less than the threshold, continue to the next pixel
      if (partial < threshold) continue;
      //The partial must be maximum in the column or row
      if (fabs(FF(x+u[2],y+v[2],z) - FF(x+u[3],y+v[3],z)) > partial) continue;
      if (fabs(FF(x+u[4],y+v[4],z) - FF(x+u[5],y+v[5],z)) > partial) continue;
      if (fabs(FF(x+u[6],y+v[6],z) - FF(x+u[7],y+v[7],z)) > partial) continue;
      if (fabs(FF(x+u[8],y+v[8],z) - FF(x+u[9],y+v[9],z)) > partial) continue;
      
      //This avoid edges with a thickness of two, when the maximum partial match
      if (partial == fabs(FF(x+u[10],y+v[10],z) - FF(x+u[11],y+v[11],z))) continue;
      
      //Sum rows (or columns)
      for (int t=12; t<17; t++)
        sr += (double) FF(x+u[t],y+v[t],z);
      for (int t=17; t<22; t++)
        sm += (double) FF(x+u[t],y+v[t],z);
      for (int t=22; t<27; t++)
        sl += (double) FF(x+u[t],y+v[t],z);
      
      s1 = sr + sl;
      s2 = sm;
      
      mod = A - B;
      
      //cout << "mod = " << mod << " m = "<< m << endl;
      //cout << "sl = " << sl << " sr = " << sr << endl;
      
      //If the intensity jump is less than the threshold, continue
      if (fabs(mod)< threshold) continue;
      
      //Calculate the coefficients of the parable
      b = (sr-sl) / 2 / mod;
      //cout << "sr="<<sr<<" sl="<<sl<<" mod="<<mod<<endl;
      c = (linear_case) ? 0 : (sl+sr-2*sm) / 2 / mod;
      a = (26*s2-60*A-60*B-s1) / 24 / mod;
      
      //Calculate gradient and displacement
      den = sqrt (1 + b*b);
      if (edgeCase == YMAX) 
      {
        gx_n  = b / den * mod;
        gy_n  = 1 / den * mod;
        des_n = (ffy(x,y,z) > 0) ? -a : a;
      }
      else 
      {
        gx_n  = 1 / den * mod;
        gy_n  = b / den * mod;
        des_n = (ffx(x,y,z) > 0) ? -a : a;
      }	 
      
      //Update gradient signs
      if (ffx(x,y,z) <= 0) gx_n = -gx_n;
      if (ffy(x,y,z) <= 0) gy_n = -gy_n;
      
      //Calculate curvature
      cu_n = 2*c / den / den / den;
      
      //Optimize parable
      OptimizarParabola (a, b, c, 0.001, RMIN, RMAX);
      den  = sqrt (1 + b*b);
      cu_n = 2*c / den / den / den;
      
      //The curvature sign changes based on partial value
      if (edgeCase == YMAX && ffy(x,y,z)<0) cu_n= -cu_n;
      if (edgeCase == XMAX && ffx(x,y,z)<0) cu_n= -cu_n;

      //cout << "pixel (" << x << ", " << y << ") a = " << a << " b = " << b << " c = " << c << " R = " << 1/cu_n << endl;

      //Set the calculated values on the borderPixel object
      pixel.setBorderPixelValues(A, B, edgeCase, a, b, c, cu_n, x, y);
      //Add edge pixel to the vector
      borderPixelVector.push_back(pixel);
    }
  }
}

//fillImages method. Is used before create the AMIObject for the interpreted languaje
void SubPixel2D::fillImages(InrImage::ptr AIntensity, InrImage::ptr BIntensity, 
                            InrImage::ptr border, InrImage::ptr a,
                            InrImage::ptr b, InrImage::ptr c, 
                            InrImage::ptr curvature, 
                            InrImage::ptr posx, InrImage::ptr posy)
{
  
  int x = 0;
  int y = 0;
  int z = 0;
  
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

//Promedio3x3 method. It averages the input image for reduce the noise
void SubPixel2D::Promedio3x3 (InrImage* result, 
                              double a00, double a01, double a11)
{
  double sum;
  float s = (float) a00 + 4*a01 + 4*a11;
  int x, y;
  int z = 0;
  
  //Inside the image
  for (y=1; y<input->DimY()-1; y++)
  {
    for (x=1; x<input->DimX()-1; x++) 
    {
      sum  = a00/s * FF(x,y,z);
      sum += a01/s * (FF(x-1,y,z)+FF(x+1,y,z)+FF(x,y-1,z)+FF(x,y+1,z));
      sum += a11/s * (FF(x-1,y-1,z)+FF(x+1,y-1,z)+FF(x-1,y+1,z)+FF(x+1,y+1,z));
      result->BufferPos(x,y,z);
      result->FixeValeur(sum);
    }
  }
  
  
  //Margins
  //TOP
  y = 0;
  for(x=1; x<input->DimX()-1; x++)
  {
    sum = ((*input)(x-1,y,z)+(*input)(x,y,z)+(*input)(x+1,y,z)) / 3;
    result->BufferPos(x,y,z);
    result->FixeValeur(sum);
  }
  //BOTTOM
  y = input->DimY()-1;
  for(x=1; x<input->DimX()-1; x++)
  {
    sum = ((*input)(x-1,y,z)+(*input)(x,y,z)+(*input)(x+1,y,z)) / 3;
    result->BufferPos(x,y,z);
    result->FixeValeur(sum);
  }
  //LEFT
  x = 0;
  for(y=1; y<input->DimY()-1; y++)
  {
    sum = ((*input)(x,y-1,z)+(*input)(x,y,z)+(*input)(x,y+1,z)) / 3;
    result->BufferPos(x,y,z);
    result->FixeValeur(sum);
  }
  //RIGHT
  x = input->DimX()-1;
  for (y=1; y<input->DimY()-1; y++)
  {
    sum = ((*input)(x,y-1,z)+(*input)(x,y,z)+(*input)(x,y+1,z)) /3;
    result->BufferPos(x,y,z);
    result->FixeValeur(sum);
  }
  
  //Corners
  //0,0,0 left-up corner |-
  sum = (2*(*input)(0,0,0)+(*input)(1,0,0)+(*input)(0,1,0)) / 4;
  result->BufferPos(0,0,0);
  result->FixeValeur(sum);
  //DimX-1,0,0 right-up corner -|
  sum = (2*(*input)(input->DimX()-1,0,0)+(*input)(input->DimX()-2,0,0)+
          (*input)(input->DimX()-1,1,0)) / 4;
  result->BufferPos(input->DimX()-1,0,0);
  result->FixeValeur(sum);
  //0,DimY-1,0 left-down corner |_
  sum = (2*(*input)(0,input->DimY()-1,0)+(*input)(0,input->DimY()-2,0)+
          (*input)(1,input->DimY()-1,0)) / 4;
  result->BufferPos(0,input->DimY()-1,0);
  result->FixeValeur(sum);
  //DimX-1,DimY-1,0 right-down corner _|
  sum = (2*(*input)(input->DimX()-1,input->DimY()-1,0)+
            (*input)(input->DimX()-1, input->DimY()-2,0)+
            (*input)(input->DimX()-2,input->DimY()-1,0)) / 4;
  result->BufferPos(input->DimX()-1,input->DimY()-1,0);
  result->FixeValeur(sum);
}

//Subpixel2D method for noisy images. It use a 9x3 window (staggered window)
void SubPixel2D::SuperGradienteGaussianoCurvo()
{
  int margin = 4; 
  double A, B;
  double S1, S2, S3;
  double a, b, c, d;
  double f = (1+24*A01+48*A11) / 12;
  double partial;
  double gx_n, gy_n, des_n, cu_n, abscu;
  //Pointers for partials indexes (based on maximum partial)
  int *u, *v;
  unsigned char edgeCase;
  int upos[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,	//Partials
                 0, 1, 1, 0,-1,-1,              //A and B
                 -1,-1,-1,-1,-1,-1,-1,          //Sums of the columns 
                 0, 0, 0, 0, 0, 0, 0, 
                 1, 1, 1, 1, 1, 1, 1 };
  int vpos[] = { 1,-1,-1,-3, 0,-2, 2, 0, 3, 1,	//Partials
                 4, 3, 4,-4,-3,-4,              //A and B
                -2,-1, 0, 1, 2, 3, 4,           //Sums of the columns
                -3,-2,-1, 0, 1, 2, 3,	
                -4,-3,-2,-1, 0, 1, 2 };
  int z = 0;
  borderPixel pixel;
  
  //For all pixels
  for (int y = margin; y < input->DimY()-margin; y++) 
  {
    for (int x = margin; x < input->DimX()-margin; x++) 
    {
      //Based on maximum partial, we decide the case
      if (fabs(ffy(x,y,z))>=fabs(ffx(x,y,z))) 
      {
        edgeCase = YMAX;
        u        = upos;
        v        = vpos;
      } 
      else 
      {
        edgeCase = XMAX;
        u        = vpos;
        v        = upos;
      }
      
      //Calculate A and B
      int m = (ffx(x,y,z)*ffy(x,y,z)>0) ? 1 : -1;
      if (edgeCase==XMAX) 
      {
        B  = ((double) FF(x-3,y-m,z) + FF(x-4,y-m,z) + FF(x-4,y,z)) / 3.0;
        A  = ((double) FF(x+4,y,z) + FF(x+4,y+m,z) + FF(x+3,y+m,z)) / 3.0;
      } 
      else 
      {
        B  = ((double) FF(x-m,y-3,z) + FF(x-m,y-4,z) + FF(x,y-4,z)) / 3.0;
        A  = ((double) FF(x,y+4,z) + FF(x+m,y+4,z) + FF(x+m,y+3,z)) / 3.0;
      }
      
      //If the intensity jump is less than the threshold, continue
      if (fabs(A-B)<threshold) continue;
      //The partial must be maximum in the column or row
      partial = fabs(FF(x+u[0],y+v[0],z) - FF(x+u[1],y+v[1],z));
      if (partial < threshold) continue;
      if (fabs(FF(x+u[2],y+v[2],z) - FF(x+u[3],y+v[3],z)) > partial) continue;
      if (fabs(FF(x+u[4],y+v[4],z) - FF(x+u[5],y+v[5],z)) > partial) continue;
      if (fabs(FF(x+u[6],y+v[6],z) - FF(x+u[7],y+v[7],z)) > partial) continue;
      if (fabs(FF(x+u[8],y+v[8],z) - FF(x+u[9],y+v[9],z)) > partial) continue;
      
      //Calculate sums of the columns (or rows)
      S1 = S2 = S3 = 0.0;
      for (int t=-3; t<=3; t++) {
        S1 += FF(x+u[19+t],y+v[19+t],z);
        S2 += FF(x+u[26+t],y+v[26+t],z);
        S3 += FF(x+u[33+t],y+v[33+t],z);
      }
      
      //Calculate the coefficients of the parable
      a = (2*S2 - 7*(A+B)) / (2*(A-B));
      b = 1.0 + (S3-S1) / (2*(A-B));
      c = (linear_case) ? 0 : (S3+S1-2*S2) / (2*(A-B)); //In 1st order, c=0
      a -= f * c;
      
      //Calculate curvature
      cu_n  = sqrt (1+b*b);
      cu_n *= cu_n * cu_n;
      cu_n  = 2*c / cu_n;
      abscu = fabs(cu_n);
      
      //Calculate gradient and displacement
      d = (A-B) / sqrt(1+b*b);
      if (edgeCase==YMAX) 
      {
        gx_n  = (ffx(x,y,z)>0) ? b*d : -b*d;
        gy_n  = (ffy(x,y,z)>0) ? d   : -d;
        des_n = (ffy(x,y,z)>0) ? -a  : a;
      } 
      else 
      {
        gx_n  = (ffx(x,y,z)>0) ? d   : -d;
        gy_n  = (ffy(x,y,z)>0) ? b*d : -b*d; 
        des_n = (ffx(x,y,z)>0) ? -a  : a;
      }  
      
      //The sign of the curvatura change based on partial value
      if (edgeCase == YMAX && ffy(x,y,z)<0) cu_n = -cu_n;
      if (edgeCase == XMAX && ffx(x,y,z)<0) cu_n = -cu_n;
      
      //Set the calculated values on the borderPixel object
      pixel.setBorderPixelValues(A, B, edgeCase, a, b, c, cu_n, x, y);
      //Add edge pixel to the vector
      borderPixelVector.push_back(pixel);
    } //End x for
  } //End y for
}

//Advanced SubPixel2D method for noisy images. It use a dynamic window (variable limits)
void SubPixel2D::DenoisingGus()
{ 
  int margen = 4;
  double A, B;
  //Partials
  float parx, pary;
  double partial;
  int m, k;
  float par0, par1;
  //Limits of the window
  int l1, l2, m1, m2, r1, r2;
  //Limits for read from the image
  int ll1, ll2, mm1, mm2, rr1, rr2;
  //Second border near flags
  bool bor2u, bor2d;
  //Sums (columns or rows)
  double SL, SM, SR;
  //Coefficients of the curve
  double a, b, c=0;
  //Denominator for calculate coefficients
  double f;
  //Gradients, displacement and curvature
  double gx, gy, des, cu=0;
  //3rd component of the InrImage
  int z = 0;
  //borderPixel object for the pixels of the edge
  borderPixel pixel;
  //Pointers to the indexes of the partials
  int *u,*v;
  //Indexes of the partials
  int upos[] = { 0, 0, 0, 0, 0, 0, 0, 0};
  int vpos[] = { -1,-3, 0,-2, 2, 0, 3, 1};	 
  
  //For all pixels
  for (int y = margen; y < input->DimY()-margen; y++) 
  {
    for (int x = margen; x < input->DimX()-margen; x++) 
    {
      //What's the greatest partial?
      pary = ffy(x,y,z);
      parx = ffx(x,y,z);
      
      if (fabs(pary) >= fabs(parx)) 
      {
        //Vertical window
        u = upos;
        v = vpos;
        
        partial = fabs(pary);
        //The partial must be maximum in the column or row
        if (partial < threshold) continue;
        if (fabs(FF(x+u[0],y+v[0],z) - FF(x+u[1],y+v[1],z)) > partial) continue;
        if (fabs(FF(x+u[2],y+v[2],z) - FF(x+u[3],y+v[3],z)) > partial) continue;
        if (fabs(FF(x+u[4],y+v[4],z) - FF(x+u[5],y+v[5],z)) > partial) continue;
        if (fabs(FF(x+u[6],y+v[6],z) - FF(x+u[7],y+v[7],z)) > partial) continue;
        
        m = (parx*pary >= 0) ? 1 : -1;
        
        //Calculate the limits of the window
        //Left
        for (par0 = ffyu(x-m,y,z), l1=-1; l1>=-2; l1--)
        {
          if (y+l1==0) break;
          par1 = ffyu(x-m, y+l1,z);
          if (fabs(par0)<fabs(par1) || par0*par1<0) break;
          par0 = par1;
        }
        if (y<input->DimY()-2)
        {
          for (par0 = ffyd(x-m,y+1,z), l2=2; l2<=3; l2++)
          {
            if (y+l2==input->DimY()-1) break;
            par1 = ffyd(x-m,y+l2,z);
            if (fabs(par0)<fabs(par1) || par0*par1<0) break;
            par0 = par1;
          }
        } 
        else l2 = 1;
        //Middle
        for (par0 = ffyu(x,y,z), m1=-1; m1>=-3; m1--) 
        {
					if (y+m1==0) break;	
					par1 = ffyu(x,y+m1,z);
					if (fabs(par0)<fabs(par1) || par0*par1<0) break;
					par0 = par1;
        } 
        for (par0 = ffyd(x,y,z), m2=1; m2<=3; m2++) 
        {
					if (y+m2==input->DimY()-1) break;
					par1 = ffyd(x,y+m2,z);
					if (fabs(par0)<fabs(par1) || par0*par1<0) break;
					par0 = par1;
        }
        //Right
        if (y>1) for (par0 = ffyu(x+m,y-1,z), r1=-2; r1>=-3; r1--) 
        {
					if (y+r1==0) break;
					par1 = ffyu(x+m,y+r1,z);
					if (fabs(par0)<fabs(par1) || par0*par1<0) break;
					par0 = par1;
        }
        else r1 = -1;
        for (par0 = ffyd(x+m,y,z), r2=1; r2<=2; r2++) 
        {
					if (y+r2==input->DimY()-1) break;
					par1 = ffyd(x+m,y+r2,z);
					if (fabs(par0)<fabs(par1) || par0*par1<0) break;
					par0 = par1;
        }
        
        //If m is negative, swap 'l' and 'r' limits
        if (m<0) 
        { 
          SWAP_INT(l1,r1);
          SWAP_INT(l2,r2);
        }
        
        //Calculate A and B (A under and B over edge)
        if (m>0) 
        {
          A = (FF(x,y+m2,z) + FF(x+1,y+r2,z)) / 2;
          B = (FF(x,y+m1,z) + FF(x-1,y+l1,z)) / 2;
        }
        else
        {
          A = (FF(x,y+m2,z) + FF(x-1,y+l2,z)) / 2;
          B = (FF(x,y+m1,z) + FF(x+1,y+r1,z)) / 2;
        }
        
        //Ahora hay que mirar si hay un segundo borde muy cercano (caso 2 y 3 px)**********************
        //Initialize the image limits
        ll1 = l1; mm1 = m1; rr1 = r1;
        ll2 = l2; mm2 = m2; rr2 = r2;
        bor2d = bor2u = false;
        int i1, i2, j1, j2;
        double par0;
        if (partial > 2*fabs(parx))
        {
          i1 = i2 = 0;
          j1 = m1;
          j2 = m2;
        }
        else 
        {
          i1 = -m;
          i2 = m;
          if (m>0)
          {
            j1 = l1;
            j2 = r2;
          }
          else 
          {
            j1 = r1;
            j2 = l2;
          }
        }
        if (j1>-4 && y+j1-2>=0)
        {
          par0 = (y+j1-2>0) ? ffy(x+i1,y+j1-2,z) : ffyd(x+i1,0,z);
          par0 = fabs(par0);
          if (par0 > partial/4 && par0>threshold)
          {
            bor2u = true; //There is a 2nd near border up
            if (m>0) //NECESITO LA IMAGEN ORIGINAL, TENGO QUE CAMBIAR COSAS!!!! original es rimt en el código de Agustín
              B = (*original)(x,y+m1,z) + (*original)(x-1,y+l1,z)/2;
            else 
              B = (*original)(x,y+m1,z) + (*original)(x+1,y+r1,z)/2;
          }
        }
        if (j2<4 && y+j2+2<=input->DimY()-1)
        { //Revisar las parciales, ahora no sé si tengo que coger la promediada o la de entrada :-S
          par0 = (y+j2+2<input->DimY()-1) ? ffy(x+i2,y+j2+2,z) : ffyu(x+i2,input->DimY()-1);
          par0 = fabs(par0);
          if (par0>partial/4 && par0>threshold)
          {
            bor2d = true; //There is a 2nd near border down
            if (m>0)
              A = (*original)(x,y+m2,z) + (*original)(x+1,y+r2,z)/2;
            else
              A = (*original)(x,y+m2,z) + (*original)(x-1,y+l2,z)/2;
          }
        }
        
        //If the intensity jump is less than the threshold, continue
        //if (fabs(A-B) < threshold) continue; CUIDADO, COMENTÉ ESTO POR LO QUE PUSE DEBAJO!!
        //jinqué el 10 porque si, en la interfaz de agustín pregunta por este umbral chico!!!!
        if (fabs(A-B) < 10) continue;
        //numbordes++;
        
        //Si hay un borde cercano crearemos una nueva subimagen a partir de la original
        //que luego suavizaremos para calcular el contorno
        if (bor2d || bor2u)
        {
          //Mi nueva imagencita sintética 11x5
          InrImage::ptr synthetic11x5 = InrImage::ptr(new InrImage(11,5,1,WT_DOUBLE,"11x5.inr.gz"));
          //Usando imagen original (AQUÍ ME PIERDO UN POCO EN EL CÓDIGO DE AGUSTÍN, VOY A GUIARME POR LA TESIS PAG. 176 EN ADELANTE)
//          int mini,minj,maxi,maxj;
//          minj = (y>4) ? -5 : -y;
//          maxj = (y<input->DimY()-5) ? 5 : input->DimY()-1-y;
//          if (x==1)
//          {
//            mini = -1;
//            for(int j=minj; j<=maxj; j++)
//            {
//              
//            }
//          }
//          else 
//            mini = -2;
          
          //volvemos a usar la imagen suavizada
          
          //El pseudocódigo dice:
          //Si contorno superior o contorno inferior:
          //crear una imagen F' centrada en (i,j) copiando los píxeles de F
          //si contorno superior actualizar B en la zona superior de F'
          //si contorno inferior actualizar A en la zona inferior de F'
          //suavizar F' para obtener G'
          //Calcular parábola P según el Lema 6.1 a partir de la imagen G'
        }
        
        //Calculate the sums of the columns
        for (SL=0, k=l1; k<=l2; k++) 
          SL += FF(x-1,y+k,z);
        for (SM=0, k=m1; k<=m2; k++) 
          SM += FF(x,y+k,z);
        for (SR=0, k=r1; k<=r2; k++) 
          SR += FF(x+1,y+k,z);
        
        //Calculate the coefficients of the curve
        f = 2 * (A-B);
        a = (2*SM - (1+2*m2)*A - (1-2*m1)*B) / f;
        b = (SR - SL + A*(l2-r2) + B*(r1-l1)) / f;		
        if (!linear_case)
        {
          c = (SL + SR - 2*SM + A*(2*m2-l2-r2) - B*(2*m1-l1-r1)) / f;
          a -= ((1+24*A01+48*A11)/12) * c;
        }
        
        //Calculate gradient, displacement and curvature
        f   = (A-B) / sqrt(1+b*b);
        gx  = b * f;
        gy  = f;
        des = -a;
        if (!linear_case)
        {
          cu = sqrt (1+b*b);
          cu *= cu * cu;
          cu = 2*c / cu;
          if (pary<0)
            cu = -cu;
        }
        
        //Set values on the borderPixel object
        pixel.setBorderPixelValues(A, B, YMAX, a, b, c, cu, x, y);
        cout << "estoy entrando aquí (" << x << ", " << y << ")" << "a=" << a << " b=" << b << " c=" << c << endl;
        if(x==48 && y==50)
          pixel.printBorderPixel(linear_case);
        //Add edge pixel to the vector
        borderPixelVector.push_back(pixel);
        
      }
      else 
      {
        //Horizontal window
        u = vpos;
        v = upos;
        partial = fabs(parx);
        //The partial must be maximum in the column or row
        if (partial < threshold) continue;
        if (fabs(FF(x+u[0],y+v[0],z) - FF(x+u[1],y+v[1],z)) > partial) continue;
        if (fabs(FF(x+u[2],y+v[2],z) - FF(x+u[3],y+v[3],z)) > partial) continue;
        if (fabs(FF(x+u[4],y+v[4],z) - FF(x+u[5],y+v[5],z)) > partial) continue;
        if (fabs(FF(x+u[6],y+v[6],z) - FF(x+u[7],y+v[7],z)) > partial) continue;

        m = (parx*pary >= 0) ? 1 : -1;
        
        //Calculate the limits of the window
        //Left
        for (par0 = ffxl(x,y-m,z), l1=-1; l1>=-2; l1--)
        {
					if (x+l1==0) break;
					par1 = ffxl(x+l1,y-m,z);
					if (fabs(par0)<fabs(par1) || par0*par1<0) break;
					par0 = par1;
        } 
        if (x<input->DimX()-2) for (par0 = ffxr(x+1,y-m,z),l2=2; l2<=3; l2++) 
        {
					if (x+l2==input->DimX()-1) break;
					par1 = ffxr(x+l2,y-m,z);
					if (fabs(par0)<fabs(par1) || par0*par1<0) break;
					par0 = par1;
        } 
        else
          l2 = 1;
        //Medium
        for (par0 = ffxl(x,y,z), m1=-1; m1>=-3; m1--) 
        {
					if (x+m1==0) break;	
					par1 = ffxl(x+m1,y,z);
					if (fabs(par0)<fabs(par1) || par0*par1<0) break;
					par0 = par1;
        } 
        for (par0 = ffxr(x,y,z), m2=1; m2<=3; m2++) 
        {
					if (x+m2==input->DimX()-1) break;
					par1 = ffxr(x+m2,y,z);
					if (fabs(par0)<fabs(par1) || par0*par1<0) break;
					par0 = par1;
        } 
        //Right
        if (x>1) for (par0 = ffxl(x-1,y+m,z), r1=-2; r1>=-3; r1--) 
        {
					if (x+r1==0) break;
					par1 = ffxl(x+r1,y+m,z);
					if (fabs(par0)<fabs(par1) || par0*par1<0) break;
					par0 = par1;
        }
        else
          r1 = -1;
        for (par0 = ffxr(x,y+m,z), r2=1; r2<=2; r2++)
        {
					if (x+r2==input->DimX()-1) break;
					par1 = ffxr(x+r2,y+m,z);
					if (fabs(par0)<fabs(par1) || par0*par1<0) break;
					par0 = par1;
        }
        
        //If m is negative, swap 'l' and 'r' limits
        if (m<0) 
        { 
          SWAP_INT(l1,r1);
          SWAP_INT(l2,r2);
        }
        
        //Calculate A and B (A under and B over edge)
        if (m>0) 
        {
          A = (FF(x+m2,y,z) + FF(x+r2,y+1,z)) / 2;
          B = (FF(x+m1,y,z) + FF(x+l1,y-1,z)) / 2;
        }
        else
        {
          A = (FF(x+m2,y,z) + FF(x+l2,y-1,z)) / 2;
          B = (FF(x+m1,y,z) + FF(x+r1,y+1,z)) / 2;
        }
        
        //If the intensity jump is less than the threshold, continue
        if (fabs(A-B) < threshold) continue;
        
        //Calculate sums of the rows 
        for (SL=0, k=l1; k<=l2; k++) 
          SL += FF(x+k,y-1,z);
        for (SM=0, k=m1; k<=m2; k++) 
          SM += FF(x+k,y,z);
        for (SR=0, k=r1; k<=r2; k++) 
          SR += FF(x+k,y+1,z);
        
        //Calculate the coefficients of the curve
        f = 2 * (A-B);
        a = (2*SM - (1+2*m2)*A - (1-2*m1)*B) / f;
        b = (SR - SL + A*(l2-r2) + B*(r1-l1)) / f;		
        if (!linear_case) {
          c = (SL + SR - 2*SM + A*(2*m2-l2-r2) - B*(2*m1-l1-r1)) / f;
          a -= ((1+24*A01+48*A11)/12) * c;
        }
        
        //Calculate gradient, displacement and curvature
        f = (A-B) / sqrt(1+b*b);
        gx = f;
        gy = b * f;
        des = -a;
        if (!linear_case) {
          cu = sqrt (1+b*b);
          cu *= cu * cu;
          cu = 2*c / cu;
          if (parx<0) 
            cu = -cu;
        }
        
        //Set values on the borderPixel object
        pixel.setBorderPixelValues(A, B, XMAX, a, b, c, cu, x, y);
        cout << "estoy entrando aquí (" << x << ", " << y << ")" << "a=" << a << " b=" << b << " c=" << c << endl;
        //Add edge pixel to the vector
        borderPixelVector.push_back(pixel);
        
      } //End else
    } //End x for
  } //End y for
}


//---------------------------------------------
// RESTORATION
//---------------------------------------------

//Versión con la ventana fija de 9x3. Restauración básica de imágenes
//Voy a tener dos funcioncitas. Una, la que es la de restaurar imagen, se va a
//llamar SubpixelDenoising (como dijo Agustín) y una auxiliar que usa, como
//en el pseudo-código de la tesis se llama ActualizarImágenes le voy a poner
//UpdateImages.

void UpdateImages(InrImage* input, InrImage* C, InrImage* I, int x, int y, int z, 
                  unsigned char edgeCase, vector<borderPixel> &borderPixelVector,
                  int linear_case)
{
  int *u, *v;
  int upos[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,	//Partials
                 0, 1, 1, 0,-1,-1,              //A and B
                 -1,-1,-1,-1,-1,-1,-1,          //Sums of the columns 
                 0, 0, 0, 0, 0, 0, 0, 
                 1, 1, 1, 1, 1, 1, 1 };
  int vpos[] = { 1,-1,-1,-3, 0,-2, 2, 0, 3, 1,	//Partials
                 4, 3, 4,-4,-3,-4,              //A and B
                -2,-1, 0, 1, 2, 3, 4,           //Sums of the columns
                -3,-2,-1, 0, 1, 2, 3,	
                -4,-3,-2,-1, 0, 1, 2 };
  borderPixel pixel;
  double A, B, S1, S2, S3;
  double a, b, c, d;
  double gx_n, gy_n, des_n, cu_n, abscu;
  double f = (1+24*A01+48*A11) / 12;
  int m = (ffx(x,y,z)*ffy(x,y,z)>0) ? 1 : -1;
  
  if (edgeCase == YMAX)
  {
    u = upos;
    v = vpos;
    B = ((double) FF(x-m,y-3,z) + FF(x-m,y-4,z) + FF(x,y-4,z)) / 3.0;
    A = ((double) FF(x,y+4,z) + FF(x+m,y+4,z) + FF(x+m,y+3,z)) / 3.0;
  }
  else 
  {
    u = vpos;
    v = upos;
    B = ((double) FF(x-3,y-m,z) + FF(x-4,y-m,z) + FF(x-4,y,z)) / 3.0;
    A = ((double) FF(x+4,y,z) + FF(x+4,y+m,z) + FF(x+3,y+m,z)) / 3.0;
  }
  S1 = S2 = S3 = 0.0;
  for (int t=-3; t<=3; t++) 
  {
    S1 += FF(x+u[19+t],y+v[19+t],z);
    S2 += FF(x+u[26+t],y+v[26+t],z);
    S3 += FF(x+u[33+t],y+v[33+t],z);
  }
  
  //Calculate the coefficients of the parable
  a = (2*S2 - 7*(A+B)) / (2*(A-B));
  b = 1.0 + (S3-S1) / (2*(A-B));
  c = (linear_case) ? 0 : (S3+S1-2*S2) / (2*(A-B)); //In 1st order, c=0
  a -= f * c;
  
  //Calculate curvature
  cu_n  = sqrt (1+b*b);
  cu_n *= cu_n * cu_n;
  cu_n  = 2*c / cu_n;
  abscu = fabs(cu_n);
  
  //Calculate gradient and displacement
  d = (A-B) / sqrt(1+b*b);
  if (edgeCase==YMAX) 
  {
    gx_n  = (ffx(x,y,z)>0) ? b*d : -b*d;
    gy_n  = (ffy(x,y,z)>0) ? d   : -d;
    des_n = (ffy(x,y,z)>0) ? -a  : a;
  } 
  else 
  {
    gx_n  = (ffx(x,y,z)>0) ? d   : -d;
    gy_n  = (ffy(x,y,z)>0) ? b*d : -b*d; 
    des_n = (ffx(x,y,z)>0) ? -a  : a;
  }  
  
  //The sign of the curvature change based on partial value
  if (edgeCase == YMAX && ffy(x,y,z)<0) cu_n = -cu_n;
  if (edgeCase == XMAX && ffx(x,y,z)<0) cu_n = -cu_n;
  
  //Set the calculated values on the borderPixel object
  pixel.setBorderPixelValues(A, B, edgeCase, a, b, c, cu_n, x, y);
  //Add edge pixel to the vector
  borderPixelVector.push_back(pixel);
  
  //Ahora hay que calcular la imagencita nueva  con las intensidades. Voy a usar
  //la función que nos hicimos pa generar una imagen sintética. Mi imagen ahora será
  //de 9x3 y el ángulo será el que venga dado por la inversa de la pendiente 
  //(ojo con el signo)
  ComputePV pv;
  //tengo que calcular en grados, porque atan me lo da en radianes
  double alpha = (atan(b)*180)/M_PI;
  cout << "alfa = " << alpha << endl;
  AnalyticFunctionBase::ptr line; 
  InrImage::ptr in;
  InrImage::ptr res;
  if (edgeCase == YMAX) 
  {
    in  = InrImage::ptr(new InrImage(3,9,1,WT_FLOAT,"in.inr.gz"));
    line = AnalyticLine::ptr(new AnalyticLine(alpha,a,1));
  }
  else 
  {
    in  = InrImage::ptr(new InrImage(9,3,1,WT_FLOAT,"in.inr.gz"));
    line = AnalyticLine::ptr(new AnalyticLine(alpha,a,4));
  }
  pv.setInputImage(in);
  pv.setAnalyticFunction(line);
  res = pv.ComputeAnalyticPartialSurfaceSubdiv(A, B);
  //Ahora hay que meter en I y en C lo que corresponde
  //Esto habrá que hacerlo mejor por el rollo de la ventana escalonada
  //ventana vertical
  //Para acelerar las iteraciones (converja más rápido)
  int weight = 100; 
  //Punto central de la ventana
  int px = 1; 
  int py = 4; 
  //Límites horizontales
  int hmin = -1; 
  int hmax = 1; 
  //Límites verticales
  int vmin = -4; 
  int vmax = 4;
  //Intercambio to' si la ventana está tumba'
  if (edgeCase==XMAX) 
  {
    SWAP_INT(px,py);
    SWAP_INT(hmin,vmin);
    SWAP_INT(hmax,vmax);
  }
  
  for (int i=hmin;i<=hmax;i++)
  {
    for (int j=vmin;j<=vmax;j++)
    {
      //Se mete la imagen en la imagen de intensidad y se incrementa la imagen
      //de contadores
      I->BufferPos(x+i,y+j,z);
      C->BufferPos(x+i,y+j,z);
      if ((edgeCase==YMAX&&i==0) || (edgeCase==XMAX&&j==0)) //La columna/fila central tiene más peso
      {
        I->FixeValeur((*I)(x+i,y+j,z) + (*res)(px+i,py+j,z)*weight);
        C->FixeValeur(((*C)(x+i,y+j,z)) + weight);
      }
      else
      {
        I->FixeValeur((*I)(x+i,y+j,z) + (*res)(px+i,py+j,z));
        C->FixeValeur(((*C)(x+i,y+j,z)) + 1);
      }
    }
  }
}

void copyImage(InrImage* input, InrImage::ptr output)
{
  int z = 0;
  for(int x=0;x<input->DimX();x++)
  {
    for(int y=0;y<input->DimY();y++)
    {
      input->BufferPos(x, y, z);
      input->FixeValeur((*output)(x,y,z));
    }
  }
}

void SubPixel2D::SubpixelDenoising(int niter)
{
  int margin = 4;
//  cout << "entro en SubpixelDenoising" << endl;
  //Crear imagen de contadores y de intensidades e inicializarlas a cero
  InrImage::ptr C = InrImage::ptr(new InrImage(input->DimX(), input->DimY(), 
                                               input->DimZ(), WT_DOUBLE,
                                               "counters.inr.gz"));
  InrImage::ptr I = InrImage::ptr(new InrImage(input->DimX(), input->DimY(), 
                                               input->DimZ(), WT_DOUBLE,
                                               "intensities.inr.gz"));
  InrImage::ptr G = InrImage::ptr(new InrImage(input->DimX(), input->DimY(),
                                               input->DimZ(), WT_DOUBLE,
                                               "averaged.inr.gz"));
//  InrImage::ptr Grad = InrImage::ptr(new InrImage(input->DimX(), input->DimY(),
//                                                  input->DimZ(), WT_DOUBLE,
//                                                  "modgrad.inr.gz"));
  //For third dimension
  int z = 0;
  //Partial derivatives
  float parx, pary, partial;
  //Pointers to the indexes of the partials
  int *u,*v;
  //Indexes of the partials
  int upos[] = { 0, 0, 0, 0, 0, 0, 0, 0};
  int vpos[] = { -1,-3, 0,-2, 2, 0, 3, 1};	 
  vector<borderPixel> vecaux; //Vector auxiliar para las iteraciones
  
  //Pa' probar por ahora, hay q poder pillar el niter que diga el user
  for(int index=0; index<niter; index++)
  {
//    cout << "index = " << index << endl;
    C->InitZero();
    I->InitZero();
    G->InitZero();
//    cout << "inicializo a cero las imágenes" << endl;
    //  Grad->InitZero();
    
    //1º Se promedia la imagen de entrada y se deja en G
    Promedio3x3(G.get(), (double)1/9, (double)1/9, (double)1/9);
//    cout << "hago el promediado" << endl;
    
    //Para que funcionen las macros de parciales tengo que jincar G como input
    //setInput(G.get());
    copyImage(input, G);
    //2º Se calcula el gradiente
    //ComputeModGrad(G, Grad);
    //Para todos los pixels de G
    //Habría que cargarse los pixels que estuvieran en borderPixelVector de una iteracion anterior
    if (index!=0 && vecaux.size()!=0) 
    {
      //Me aseguro que en borderPixelVector siempre tengo bordes y no me los estoy cargando
      borderPixelVector = vecaux;
      vecaux.erase(vecaux.begin(), vecaux.end());
    }
   
//    cout << "me cepillo en borderPixelVector" << endl;
    for(int y = margin; y < G->DimY()-margin; y++)
    {
//      cout << "\ty = " << y << endl;
      for(int x = margin; x < G->DimX()-margin; x++)
      {
//        cout << "\t\tx = " << x << endl;
        pary = ffy(x,y,z);
        parx = ffx(x,y,z);
//        cout << "producto de las parciales" << parx*parx+pary*pary << endl;
//        cout << "valor de la imagen en (" << x << ", " << y << ") = " << (*input)(x,y,z) << endl;
        if (parx*parx + pary*pary < threshold*threshold) continue;
        if (fabs(pary) >= fabs(parx))
        {
          partial = pary;
          //Vertical window
          u = upos;
          v = vpos;
          //Is it maximum in the column?
          if (fabs(FF(x+u[0],y+v[0],z) - FF(x+u[1],y+v[1],z)) > partial) continue;
          if (fabs(FF(x+u[2],y+v[2],z) - FF(x+u[3],y+v[3],z)) > partial) continue;
          if (fabs(FF(x+u[4],y+v[4],z) - FF(x+u[5],y+v[5],z)) > partial) continue;
          if (fabs(FF(x+u[6],y+v[6],z) - FF(x+u[7],y+v[7],z)) > partial) continue;
//          cout << "la parcial máxima es en y. Voy a llamar a UpdateImages" << endl;
          UpdateImages(input, C.get(), I.get(), x, y, z, YMAX, vecaux,
                       linear_case);
//          cout << "vuelvo de update images en parcial máxima y." << endl;
        }
        else
        {
          partial = parx;
          //Horizontal window
          u = vpos;
          v = upos;
          //Is it maximum in the row?
          if (fabs(FF(x+u[0],y+v[0],z) - FF(x+u[1],y+v[1],z)) > partial) continue;
          if (fabs(FF(x+u[2],y+v[2],z) - FF(x+u[3],y+v[3],z)) > partial) continue;
          if (fabs(FF(x+u[4],y+v[4],z) - FF(x+u[5],y+v[5],z)) > partial) continue;
          if (fabs(FF(x+u[6],y+v[6],z) - FF(x+u[7],y+v[7],z)) > partial) continue;
//          cout << "la parcial máxima es en x. Voy a llamar a UpdateImages" << endl;
          UpdateImages(input, C.get(), I.get(), x, y, z, XMAX, vecaux,
                       linear_case);
//          cout << "vuelvo de update images en parcial máxima x." << endl;
        }
      }
    }
    //Con las imágenes resultantes, se rellena la nueva imagen de entrada
    for (int y = margin; y < G->DimY()-margin; y++)
    {
      for (int x = margin; x < G->DimX()-margin; x++)
      {
        if ((*C)(x,y,z) > 0)
        {
          input->BufferPos(x,y,z);
          input->FixeValeur((*I)(x,y,z)/(*C)(x,y,z));
//          cout << "valor final que meto: " << (*I)(x,y,z)/(*C)(x,y,z) << endl;
        }
      }
    }
  }
//  cout << "salgo de SubpixelDenoising" << endl;
}
