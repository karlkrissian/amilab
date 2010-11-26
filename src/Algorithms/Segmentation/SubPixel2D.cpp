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

//Minimum radius for estimate inside a 3x3 window
#define RMIN3x3 1.7

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

//Swap double
double DOUBLE_TEMP;
#define SWAP_DOUBLE(a,b) DOUBLE_TEMP=a; a=b; b=DOUBLE_TEMP

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
  denoised    = NULL;
}

//Destructor
SubPixel2D::~SubPixel2D(){}

void copyImage(InrImage* input, InrImage* output, int margin)
{
  int z = 0;
  for(int x=margin;x<input->DimX()-margin;x++)
  {
    for(int y=margin;y<input->DimY()-margin;y++)
    {
      input->BufferPos(x, y, z);
      input->FixeValeur((*output)(x,y,z));
    }
  }
}

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
void SubPixel2D::Promedio3x3 (InrImage* input, InrImage* result, 
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
  int m, k, p;
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
  
  //Vamos a empezar por copiar la imagen original y luego promediarla
  InrImage input_copy(WT_DOUBLE,"input_copy.inr.gz",input);
  denoised = new InrImage(WT_DOUBLE,"denoised.inr.gz",input);
  Promedio3x3(input, denoised, A00, A01, A11);
  input_copy = *input;
  setInput(denoised);
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
        p = (m+1) / 2;
        
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
        
        //If the intensity jump is less than the threshold, continue
        if (fabs(A-B) < threshold) continue;
        
        
        //**********************************************************************
        
        //PARTE NUEVA DE LOS BORDES CERCANOS (CASOS GROSOR 2 Y 3 PXLS.)
        
        //Ahora hay que mirar si hay un segundo borde muy cercano (caso 2 y 3 px)
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
            if (m>0)
              B = (input_copy(x,y+m1,z) + input_copy(x-1,y+l1,z))/2;
            else 
              B = (input_copy(x,y+m1,z) + input_copy(x+1,y+r1,z))/2;
          }
        }
        if (j2<4 && y+j2+2<=input->DimY()-1)
        {
          par0 = (y+j2+2<input->DimY()-1) ? ffy(x+i2,y+j2+2,z) : ffyu(x+i2,input->DimY()-1,z);
          par0 = fabs(par0);
          if (par0>partial/4 && par0>threshold)
          {
            bor2d = true; //There is a 2nd near border down
            if (m>0)
              A = (input_copy(x,y+m2,z) + input_copy(x+1,y+r2,z))/2;
            else
              A = (input_copy(x,y+m2,z) + input_copy(x-1,y+l2,z))/2;
          }
        }
        
        //jinqué el 10 porque si, en la interfaz de Agustín pregunta por este umbral chico!!!!
        if (fabs(A-B) < 10) continue;
        //numbordes++; esto estaba en el código de Agustín
        
        //Si hay un borde cercano crearemos una nueva subimagen a partir de la original
        //que luego suavizaremos para calcular el contorno
        if (bor2d || bor2u)
        {
          //Mi nueva imagencita sintética 11x5
          InrImage* fprime = new InrImage(5,11,1,WT_DOUBLE,"fprime.inr.gz");
          //El pseudocódigo dice:
          //Si contorno superior o contorno inferior:
          //crear una imagen F' centrada en (i,j) copiando los píxeles de F
          //mi pixel i,j de la imagen grande es el 5,2 de la imagen 11x5
          //Center of the 11x5 image
          int fprimex=2;
          int fprimey=5;
          for(int indj = -5; indj<=5; indj++)
          {
            for(int indi = -2; indi<=2; indi++)
            {
              fprime->BufferPos(fprimex+indi,fprimey+indj,z);
              fprime->FixeValeur(input_copy(x+indi,y+indj,z));
            }
          }
          //si contorno superior actualizar B en la zona superior de F'
          if (bor2u)
          {
            par0 = ffyu (x-2, y+l1+p,z);
            int ll = (par0*pary>0)? l1+p-1 : l1+p;
            par1 = ffyu (x+2, y+r1+1-p,z);
            int rr = (par1*pary>0)? r1-p : r1+1-p;
            fprimex = 0;
            for (int k=-5; k<=ll; k++)
            {
              fprime->BufferPos(fprimex,fprimey+k,z);
              fprime->FixeValeur(B);
            }
            fprimex = 1;
            for (int k=-5; k<=l1; k++)
            {
              fprime->BufferPos(fprimex,fprimey+k,z);
              fprime->FixeValeur(B);
            }
            fprimex = 2;
            for (int k=-5; k<=m1; k++)
            {
              fprime->BufferPos(fprimex,fprimey+k,z);
              fprime->FixeValeur(B);
            }
            fprimex = 3;
            for (int k=-5; k<=r1; k++)
            {
              fprime->BufferPos(fprimex,fprimey+k,z);
              fprime->FixeValeur(B);
            }
            fprimex = 4;
            for (int k=-5; k<=rr; k++)
            {
              fprime->BufferPos(fprimex,fprimey+k,z);
              fprime->FixeValeur(B);
            }
            ll1=-3+m; mm1=-3; rr1=-3-m;
          }
          //si contorno inferior actualizar A en la zona inferior de F'
          if (bor2d)
          {
            par0 = ffyd (x-2, y+l2+p-1,z);
            int ll = (par0*pary>0)? l2+p : l2+p-1;
            par1 = ffyd (x+2, y+r2-p,z);
            int rr = (par1*pary>0)? r2+1-p : r2-p;					
            fprimex = 0;
            for (int k=ll; k<=5; k++)
            {
              fprime->BufferPos(fprimex,fprimey+k,z);
              fprime->FixeValeur(A);
            }
            fprimex = 1;
            for (int k=l2; k<=5; k++)
            {
              fprime->BufferPos(fprimex,fprimey+k,z);
              fprime->FixeValeur(A);
            }
            fprimex = 2;
            for (int k=m2; k<=5; k++)
            {
              fprime->BufferPos(fprimex,fprimey+k,z);
              fprime->FixeValeur(A);
            }
            fprimex = 3;
            for (int k=r2; k<=5; k++)
            {
              fprime->BufferPos(fprimex,fprimey+k,z);
              fprime->FixeValeur(A);
            }
            fprimex = 4;
            for (int k=rr; k<=5; k++)
            {
              fprime->BufferPos(fprimex,fprimey+k,z);
              fprime->FixeValeur(A);
            }
            ll2=3+m;  mm2=3;  rr2=3-m;
          }
          //suavizar F' para obtener G'
          //esto sería llamar a Promedio3x3 pero sólo para esta imagencita chica
          //o hacerlo aquí directamente como Agustín:
          //actualizo la posición del centro de la imagen chica
          fprimex = 2;
          fprimey = 5;
          for(int indj = -4; indj<=4; indj++)
          {
            for(int indi= -1; indi<=1; indi++)
            {
              int posx = fprimex+indi;
              int posy = fprimey+indj;
              int suma = 0;
              suma += (*fprime)(posx-1,posy-1,z) + (*fprime)(posx,posy-1,z) + 
                      (*fprime)(posx+1,posy-1,z);
              suma += (*fprime)(posx-1,posy,z) + (*fprime)(posx,posy,z) + 
                      (*fprime)(posx+1,posy,z);
              suma += (*fprime)(posx-1,posy+1,z) + (*fprime)(posx,posy+1,z) + 
                      (*fprime)(posx+1,posy+1,z);
              fprime->BufferPos(posx,posy,z);
              fprime->FixeValeur(suma/9);
            }
          }
          //Calcular parábola P según el Lema 6.1 a partir de la imagen G'
          //esto es aplicar el método... creo (solo tengo que hacer las sumitas)
          for (SL=0, k=ll1; k<=ll2; k++) 
            SL += (*fprime)(fprimex-1,fprimey+k,z);
          for (SM=0, k=mm1; k<=mm2; k++) 
            SM += (*fprime)(fprimex,fprimey+k,z);
          for (SR=0, k=rr1; k<=rr2; k++) 
            SR += (*fprime)(fprimex+1,fprimey+k,z);
          delete(fprime);
        }
        else //En caso contrario se calculan las sumas como siempre
        {
          //**********************************************************************
          
          
          //Calculate the sums of the columns
          for (SL=0, k=l1; k<=l2; k++) 
            SL += FF(x-1,y+k,z);
          for (SM=0, k=m1; k<=m2; k++) 
            SM += FF(x,y+k,z);
          for (SR=0, k=r1; k<=r2; k++) 
            SR += FF(x+1,y+k,z);
        }
       
        
        //Calculate the coefficients of the curve
        f = 2 * (A-B);
        a = (2*SM - (1+2*mm2)*A - (1-2*mm1)*B) / f;
        b = (SR - SL + A*(ll2-rr2) + B*(rr1-ll1)) / f;		
        if (!linear_case)
        {
          c = (SL + SR - 2*SM + A*(2*mm2-ll2-rr2) - B*(2*mm1-ll1-rr1)) / f;
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
        p = (m+1) / 2;
        
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
        
        //**********************************************************************
        
        //PARTE NUEVA PARA CONTORNOS MUY CERCANOS (2 Y 3 PXLS) CASO VENTANA HORIZONTAL
        
        //Initialize the image limits
        ll1 = l1; mm1 = m1; rr1 = r1;
        ll2 = l2; mm2 = m2; rr2 = r2;
        bor2d = bor2u = false;
        int i1, i2, j1, j2;
        double par0;
        if (partial > 2*fabs(pary))
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
          par0 = (y+j1-2>0) ? ffx(x+j1-2,y+i1,z) : ffxr(0,y+i1,z);
          par0 = fabs(par0);
          if (par0 > partial/4 && par0>threshold)
          {
            bor2u = true; //There is a 2nd near border up
            if (m>0)
              B = (input_copy(x+m1,y,z) + input_copy(x+l1,y-1,z))/2;
            else 
              B = (input_copy(x+m1,y,z) + input_copy(x+r1,y+1,z))/2;
          }
        }
        if (j2<4 && y+j2+2<=input->DimY()-1)
        {
          par0 = (y+j2+2<input->DimY()-1) ? ffx(x+j2+2,y+i2,z) : ffxl(input->DimX()-1,y+i2,z);
          par0 = fabs(par0);
          if (par0>partial/4 && par0>threshold)
          {
            bor2d = true; //There is a 2nd near border down
            if (m>0)
              A = (input_copy(x+m2,y,z) + input_copy(x+r2,y+1,z))/2;
            else
              A = (input_copy(x+m2,y,z) + input_copy(x+l2,y-1,z))/2;
          }
        }
        
        //jinqué el 10 porque si, en la interfaz de Agustín pregunta por este umbral chico!!!!
        if (fabs(A-B) < 10) continue;
        //numbordes++; esto estaba en el código de Agustín
        
        //Si hay un borde cercano crearemos una nueva subimagen a partir de la original
        //que luego suavizaremos para calcular el contorno
        if (bor2d || bor2u)
        {
          //Mi nueva imagencita sintética 5x11
          InrImage* fprime = new InrImage(11,5,1,WT_DOUBLE,"fprime.inr.gz");
          //El pseudocódigo dice:
          //Si contorno superior o contorno inferior:
          //crear una imagen F' centrada en (i,j) copiando los píxeles de F
          //mi pixel i,j de la imagen grande es el 2,5 de la imagen 5x11
          //Center of the 5x11 image
          int fprimex=5;
          int fprimey=2;
          for(int indj = -2; indj<=2; indj++)
          {
            for(int indi = -5; indi<=5; indi++)
            {
              fprime->BufferPos(fprimex+indi,fprimey+indj,z);
              fprime->FixeValeur(input_copy(x+indi,y+indj,z));
            }
          }
          //si contorno superior actualizar B en la zona superior de F'
          if (bor2u)
          {
            par0 = ffxl (x+l1+p, y-2,z);
            int ll = (par0*parx>0)? l1+p-1 : l1+p;
            par1 = ffxl (x+r1+1-p, y+2,z);
            int rr = (par1*parx>0)? r1-p : r1+1-p;
            fprimey = 0;
            for (int k=-5; k<=ll; k++)
            {
              fprime->BufferPos(fprimex+k,fprimey,z);
              fprime->FixeValeur(B);
            }
            fprimey = 1;
            for (int k=-5; k<=l1; k++)
            {
              fprime->BufferPos(fprimex+k,fprimey,z);
              fprime->FixeValeur(B);
            }
            fprimey = 2;
            for (int k=-5; k<=m1; k++)
            {
              fprime->BufferPos(fprimex+k,fprimey,z);
              fprime->FixeValeur(B);
            }
            fprimey = 3;
            for (int k=-5; k<=r1; k++)
            {
              fprime->BufferPos(fprimex+k,fprimey,z);
              fprime->FixeValeur(B);
            }
            fprimey = 4;
            for (int k=-5; k<=rr; k++)
            {
              fprime->BufferPos(fprimex+k,fprimey,z);
              fprime->FixeValeur(B);
            }
            ll1=-3+m; mm1=-3; rr1=-3-m;
          }
          //si contorno inferior actualizar A en la zona inferior de F'
          if (bor2d)
          {
            par0 = ffxr (x+l2+p-1, y-2,z);
            int ll = (par0*parx>0)? l2+p : l2+p-1;
            par1 = ffxr (x+r2-p, y+2,z);
            int rr = (par1*parx>0)? r2+1-p : r2-p;					
            fprimey = 0;
            for (int k=ll; k<=5; k++)
            {
              fprime->BufferPos(fprimex+k,fprimey,z);
              fprime->FixeValeur(A);
            }
            fprimey = 1;
            for (int k=l2; k<=5; k++)
            {
              fprime->BufferPos(fprimex+k,fprimey,z);
              fprime->FixeValeur(A);
            }
            fprimey = 2;
            for (int k=m2; k<=5; k++)
            {
              fprime->BufferPos(fprimex+k,fprimey,z);
              fprime->FixeValeur(A);
            }
            fprimey = 3;
            for (int k=r2; k<=5; k++)
            {
              fprime->BufferPos(fprimex+k,fprimey,z);
              fprime->FixeValeur(A);
            }
            fprimey = 4;
            for (int k=rr; k<=5; k++)
            {
              fprime->BufferPos(fprimex+k,fprimey,z);
              fprime->FixeValeur(A);
            }
            ll2=3+m;  mm2=3;  rr2=3-m;
          }
          //suavizar F' para obtener G'
          //esto sería llamar a Promedio3x3 pero sólo para esta imagencita chica
          //o hacerlo aquí directamente como Agustín:
          //actualizo la posición del centro de la imagen chica
          fprimex = 5;
          fprimey = 2;
          for(int indj = -1; indj<=1; indj++)
          {
            for(int indi= -4; indi<=4; indi++)
            {
              int posx = fprimex+indi;
              int posy = fprimey+indj;
              int suma = 0;
              suma += (*fprime)(posx-1,posy-1,z) + (*fprime)(posx,posy-1,z) + 
                      (*fprime)(posx+1,posy-1,z);
              suma += (*fprime)(posx-1,posy,z) + (*fprime)(posx,posy,z) + 
                      (*fprime)(posx+1,posy,z);
              suma += (*fprime)(posx-1,posy+1,z) + (*fprime)(posx,posy+1,z) + 
                      (*fprime)(posx+1,posy+1,z);
              fprime->BufferPos(posx,posy,z);
              fprime->FixeValeur(suma/9);
            }
          }
          //Calcular parábola P según el Lema 6.1 a partir de la imagen G'
          //esto es aplicar el método... creo (solo tengo que hacer las sumitas)
          for (SL=0, k=ll1; k<=ll2; k++) 
            SL += (*fprime)(fprimex+k,fprimey-1,z);
          for (SM=0, k=mm1; k<=mm2; k++) 
            SM += (*fprime)(fprimex+k,fprimey,z);
          for (SR=0, k=rr1; k<=rr2; k++) 
            SR += (*fprime)(fprimex+k,fprimey+1,z);
          delete(fprime);
        }
        else //En caso contrario se calculan las sumas como siempre
        {        
          //**********************************************************************
          
          //Calculate sums of the rows 
          for (SL=0, k=l1; k<=l2; k++) 
            SL += FF(x+k,y-1,z);
          for (SM=0, k=m1; k<=m2; k++) 
            SM += FF(x+k,y,z);
          for (SR=0, k=r1; k<=r2; k++) 
            SR += FF(x+k,y+1,z);
        }
        
        //Calculate the coefficients of the curve
        f = 2 * (A-B);
        a = (2*SM - (1+2*mm2)*A - (1-2*mm1)*B) / f;
        b = (SR - SL + A*(ll2-rr2) + B*(rr1-ll1)) / f;		
        if (!linear_case) {
          c = (SL + SR - 2*SM + A*(2*mm2-ll2-rr2) - B*(2*mm1-ll1-rr1)) / f;
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
        //Add edge pixel to the vector
        borderPixelVector.push_back(pixel);
        
      } //End else
    } //End x for
  } //End y for
    //delete(input_copy);
  delete(denoised);
}


//---------------------------------------------
// RESTORATION
//---------------------------------------------

//Versión con la ventana fija de 9x3. Restauración básica de imágenes
//Voy a tener dos funcioncitas. Una, la que es la de restaurar imagen, se va a
//llamar SubpixelDenoising (como dijo Agustín) y una auxiliar que usa, como
//en el pseudo-código de la tesis se llama ActualizarImágenes le voy a poner
//UpdateImages.

//Hacen falta un par de funciones para calcula el color que le toca a cada pixel
//diferenciándose para el caso de una recta y de una curva.
//Estas funciones miran si el pixel cae por encima o por debajo, devolviendo el
//valor de intensidad adecuado en cada caso. Si por el pixel pasa la recta (o curva)
//entonces se calcula la integral y se devuelve cuál es el valor de intensidad
//que le toca al pixel en función del área. En el código de Agustín estas funciones
//eran CalculaColorPixelRecto y CalculaColorPixelCurvo. Aquí las llamaré como
//ComputeStraightPixelColor y ComputeCurvePixelColor.
//También me hace falta otra función que estima una circunferencia a partir de
//la parábola (BuscaCircunf -> SearchCircle) y que dice si converge o no
//poniendo luego en función de eso el valor del peso en la imagencita chica
//sintética


//LO ESTABA HACIENDO MAL: Las funciones eran CalculaColorVentanita y
//CalculaColorVentanita Curva

//ComputeWindowColor
void ComputeWindowColor (unsigned char edgeCase, double gx, double gy, double des,
                         double A, double B, double *win)
{
  
}
void CalculaColorVentanita (unsigned char caso, float gx, float gy, float des, 
					float A, float B, float *vent, int debug)
/* Dado un borde <gx,gy> con desplazamiento des y colores A y B, generamos
  una subimagen 9x5 sintética con una rampa ideal para esos valores.
  Si la pendiente es mayor que 1, la subimagen será 5x9 (horizontal).
  En realidad no es según la pendiente, sino segun el caso (YMAX o XMAX).
  La subventanita viene grabada por columnas, de izquierda a derecha, y aunque
  es rectangular, luego solo se utilizaran columnas de 7 tomadas en diagonal, y 
  columnas de 1 solo pixel en las laterales (para el error que habia en los
  45º del círculo. */
{
int i, j, n, s;
float m;
float absgx = fabs(gx);
float absgy = fabs(gy);
int pen;

// si la pendiente es mayor que 1, invertimos los ejes x e y. 
if (caso == XMAX) { 
	SWAP_FLOAT (gx, gy); 
	SWAP_FLOAT (absgx, absgy);
 }

// ahora gx<gy en valor absoluto. Si gy<0, invertimos la situación
if (gy<0) {
	gx = -gx;
	gy = -gy; 
	SWAP_FLOAT (A, B); 
 }

if (debug) printf ("en ventanita: radio=inf G=(%f,%f) des=%f\n",
		gx,gy,des);

// calculamos la ventanita
m = absgx / absgy; 
for (i=-2; i<=2; i++) 
	for (j=Lims[i+2][0]; j<=Lims[i+2][1]; j++) {
		s = 9*i + j + 22;  //(i+2)*9+(j+4);
		vent[s] = CalculaColorPixel (absgx, absgy, des-j-i*m, A, B);
	 }
	 
// si gx<0, intercambiamos las columnas laterales
if (gx<0) for (n=0; n<9; n++) { 
	SWAP_FLOAT (vent[n+9], vent[n+27]);
	//SWAP_FLOAT (vent[n], vent[n+36]);
	vent[5] = vent[41];
	vent[39] = vent[3];
 }

if (!debug) return;

// imprimimos resultados ventanita 
if (caso == YMAX) {			// ventanita vertical
	for (j=-4; j<=4; j++) {
		for (i=-2; i<=2; i++) printf ("%f ", vent[(i+2)*9+(j+4)]);
		printf ("\n");
	 }
 } else {			// ventanita horizontal
	for (i=-2; i<=2; i++) {
		for (j=-4; j<=4; j++) printf ("%f ", vent[(i+2)*9+(j+4)]);
		printf ("\n");
	 }
 }
}


//ComputeCurveWindowColor
void ComputeCurveWindowColor (unsigned char edgeCase, double gx, double gy,
                              double des, double cu, double A, double B,
                              double *win, int winsize)
{
  
}
void CalculaColorVentanitaCurva (unsigned char caso, float gx, float gy, 
					float des, float cu,
					float A, float B, float *vent, 
					int debug, int tamvent)
/* Dado un borde <gx,gy> con desplazamiento des y colores A y B, generamos
  una subimagen 9x5 sintética con una parábola ideal para esos valores.
  Para ello calculamos la curva y=a+bx+cx2 (-v=a+bu+cu2).
  Si la pendiente es mayor que 1, la subimagen será 5x9 (horizontal). 
  Si solo1pixel=true, la subimagen generada es 1x1.
  En realidad no es según la pendiente, sino segun el caso (YMAX o XMAX).
  La subventanita viene grabada por columnas, de izquierda a derecha, y aunque
  es rectangular, luego solo se utilizaran columnas de 7 tomadas en diagonal, y 
  columnas de 1 solo pixel en las laterales (para el error que habia en los
  45º del círculo). 
  tamvent indica el tamaño de la ventana a generar
   1: 1 solo pixel
   3: 3x3 (al final esta no se esta usando, sino que se llama a la funcion
   		CalculaVentanita3x3)
   9: 9x5     */
{
double a, b, c, t;
int n, i, j;
double absgx = fabs(gx);
double absgy = fabs(gy); 
double xc, yc, r, mod;
int pen, s;
double D, F;

/***********************
// calculamos los coeficientes de la parabola
a = -des;
b = absgx / absgy;
t = sqrt (1+b*b);
c = - t * t * t * cu / 2;
if (debug) printf ("a=%f b=%f c=%f\n",a,b,c);

// calculamos la ventanita
for (n=0, j=-3; j<=3; j++) for (i=-1; i<=1; i++, n++) 
	vent[n] = CalculaColorPixelCurvo_viejo (a+b*i+c*i*i+j, b+2*c*i, c, A, B);
return;	
/***********************************/

// si el radio es muy grande, consideramos un caso plano
if (fabs(cu) < 0.001) {
	CalculaColorVentanita (caso, gx, gy, des, A, B, vent, debug);
	return;
 }

// si la pendiente es mayor que 1, invertimos los ejes x e y. 
if (caso == XMAX) { 
	SWAP_FLOAT (gx, gy); 
	SWAP_DOUBLE (absgx, absgy);
 }

// ahora gx<gy en valor absoluto. Si gy<0, invertimos colores y curvatura
if (gy<0) { 
	SWAP_FLOAT (A, B);
	cu = -cu;
 }

// calculamos el radio del círculo
r = 1.0 / cu;

// si es muy chico ponemos otro
if (tamvent!=3 && fabs(r)<RMINGAUSS) r = (r>0)? RMINGAUSS : -RMINGAUSS;

// en parametricas caminamos desde el circulo para hallar el centro
mod = sqrt (absgx*absgx+absgy*absgy);
xc = r * absgx / mod;
yc = -des - (absgy * r)/mod; 

if (debug) printf ("en ventanita: radio=%f centro=(%f,%f) G=(%f,%f) des=%f\n",
		r,xc,yc,gx,gy,des);

// calculamos la pendiente de la ventanita
pen = (gx*gy>=0.0)? 1 : -1;

// calculamos los colores dentro y fuera
if (r>0) { D=A; F=B;} else { D=B; F=A;}
r = fabs(r);

// calculamos la ventanita
switch (tamvent) {
   	case 1: vent[0] = CalculaColorPixelCurvo (xc, yc, r, D, F);
	 	break;
		
	case 3: for (j=-1; j<=1; j++) for (i=-1; i<=1; i++) {
			s = 9*i + j + 22;  //(i+2)*9+(j+4);
			vent[s] = CalculaColorPixelCurvo (xc-i, yc+j, r, D, F);
		 }
		break;

	case 9: for (i=-2; i<=2; i++) for (j=Lims[i+2][0]; j<=Lims[i+2][1]; j++) {
			s = 9*i + j + 22;  //(i+2)*9+(j+4);
			vent[s] = CalculaColorPixelCurvo (xc-i, yc+j, r, D, F);
		 }
		break;
 } 	
	 
// si la pendiente es negativa, intercambiamos las columnas laterales
if (pen<0) for (n=0; n<9; n++) {
	SWAP_FLOAT (vent[n+9], vent[n+27]); 
	//SWAP_FLOAT (vent[n], vent[n+36]);
	vent[5] = vent[41];
	vent[39] = vent[3];
 }

if (!debug) return;

// imprimimos resultados ventanita 
switch (tamvent) {
	case 1: printf ("color calculado para el pixel = %f\n", vent[0]);
		break;
	
	case 9:
	if (caso == YMAX) {		// ventanita vertical
		for (j=-4; j<=4; j++) {
			for (i=-2; i<=2; i++) printf ("%f ", vent[(i+2)*9+(j+4)]);
			printf ("\n");
		 }
	  } else {			// ventanita horizontal
	 	for (i=-2; i<=2; i++) {
			for (j=-4; j<=4; j++) printf ("%f ", vent[(i+2)*9+(j+4)]);
			printf ("\n");
	  	 }
 	
 	 }
 }
}

//Compute the pixel intensity value based on line equation and up and down 
//intensities
//double ComputeStraightPixelColor(double a, double b, double A, double B)
//{
//  //Given the line y=a+bx, with A down and B up, we compute the pixel color
//  double x0=-0.5, x1=0.5;
//  double area;
//  
//  //We make b always positive
//  if (b<0) 
//    b = -b;
//  
//  //If the line don't cross the pixel, return B or A
//  if (a+0.5*b < -0.5) 
//    return (B);
//  if (a-0.5*b > 0.5) 
//    return (A);
//  
//  //Horizontal
//  if (b<1e-4) 
//    area = a+0.5;
//  else 
//  { 
//    //Compute the cuts and integrate
//    if (a-0.5*b < -0.5) 
//      x0 = (-0.5-a) / b; 
//    if (a+0.5*b > 0.5)  
//      x1 = (0.5-a) / b;
//    area = (a+0.5)*(x1-x0) + b/2*(x1*x1-x0*x0);
//    if (x1<0.5) 
//      area += 0.5-x1;
//  }
//	
//  //Return the color
////  if (isnan(area*A + (1-area)*B)) {
////    cout << "intensidad nan en recto" << endl;
////    cout << "a:" << a << " b:" << b << " A:" << A << " B:" << B << endl;
////  }
//
//  return (area*A + (1-area)*B);
//}

//Compute the pixel intensity value based on circle equation and inside and
//outside intensities
//double ComputeCurvePixelColor(double xc, double yc, double r, double D, double F)
//{
//  //With the circunference (x-xc)2 + (y-yc)2 = r2, the intensity D in and the
//  //intensity F out, we compute the pixel color
//  double t, x0, x1, area;
//  
//  //cout << "xc=" << xc << " yc=" << yc << " r=" << r << " D=" << D << " F=" << F << endl;
//  
//  //Pass the center to right down (xc>0, yc<0, xc>-yc)
//  xc = fabs(xc);
//  yc = fabs(yc);
//  if (xc < yc) 
//  { 
//    SWAP_DOUBLE (xc, yc);
//  }
//  yc = -yc;
//  
//  //If the pixel is outside, we return F
//  if (yc+r<=-0.5 || xc-r>=0.5) 
//    return (F);
//  
//  //Compute the cuts
//  x0 = xc - sqrt(r*r - (-0.5-yc)*(-0.5-yc));
//  if (x0 < xc-r) 
//    x0 = xc-r;
//  if (yc+r <= 0.5) 
//    x1 = 0.5;
//	else 
//    x1 = xc - sqrt( r*r - (0.5-yc)*(0.5-yc));
//	
//  //If the pixel is inside, we return D
//  if (x1 <= -0.5) 
//    return (D); 
//  
//  // miramos los casos (ver folio aparte) ¿¿comorl??
//  //All posible cases
//  if (yc <= -0.5) 
//  {
//  	if (x0 >= 0.5) 
//      return (F);
//    if (x0 > -0.5) 
//    {
//      if (x1 < 0.5)  
//        area = P(x1) - P(x0) - 0.5*(x1+x0) + 0.5;
//      else 
//        area = P(0.5) - P(x0) - 0.5*x0 + 0.25;
//    } 
//    else 
//    {
//      if (x1 < 0.5)
//        area = P(x1) - P(-0.5) - 0.5*x1 + 0.75;
//      else 
//        area = P(0.5) - P(-0.5) + 0.5;
//    }
//  } 
//  else 
//  {
//    t = xc - r;
//    if (x1 < 0.5) 
//    {
//      if (t >= -0.5)
//        area = 2 * (P(x0) - P(t) - yc*(x0-t)) +
//				P(x1) - P(x0) - 0.5*(x1+x0) + 0.5;
//      else 
//        area = 2 * (P(x0) - P(-0.5) - yc*(x0+0.5)) +
//				P(x1) - P(x0) - 0.5*(x1+x0) + 0.5;
//    } 
//    else 
//    {
//      if (x0 <= 0.5)
//        area = 2 * (P(x0) - P(t) - yc*(x0-t)) +
//				P(0.5) - P(x0) - 0.5*x0 + 0.25;
//      else 
//        area = 2 * (P(0.5) - P(t) - yc*(0.5-t));
//    }
//  }
//  
//  //Return the color
////  if (isnan(F + area*(D-F))) {
////    cout << "intensidad nan en curvo" << endl;
////    cout << "xc:" << xc << " yc:" << yc << " r:" << r << " D:" << D << " F:" << F << endl;
////    cout << "area: " << area << endl;
////  }
//  return (F + area*(D-F));
//}

//With the parable a+bx+cx^2, using the limits, it goes refining a circle
//bool SearchCircle(double &a, double &b, double &c, double A, double B, int l1,
//                  int l2, int m1, int m2, int r1, int r2)
//{
//  double vents[55], vent[55]/*, ventprev[55]*/;	// la ventana donde voy a generar es de 11x5
//  double raiz, r, xc, yc, D, F;
//  int i, j, n, k, iter=0;
//  double a0, a1/*, a2*/, b0, b1/*, b2*/, c0, c1/*, c2*/;
//  double SL, SM, SR, f;
//  double aprev, bprev, cprev;
//  double fa, fb, fc;
//  //double err, errprev=1e10;
//  /*
//   // parametros para imagenes sinteticas
//   int maxiter=1000;	// número máximo de iteraciones para converger
//   double umbral1=1e-7;	// si a,b,c varían menos de esto, ya podemos acabar
//   double umbral2=1e-1;	// si despues de maxiter a,b,c varían menos de esto, ya acabamos
//   */
//  // parametros para imagenes reales
//  int maxiter=100;	// número máximo de iteraciones para converger
//  double umbral1=1e-5;	// si a,b,c varían menos de esto, ya podemos acabar
//  double umbral2=1e-2;	// si despues de maxiter a,b,c varían menos de esto, ya acabamos
//  
//  // guardamos la parábola original
//  aprev=a0=a; bprev=b0=b; cprev=c0=c;
//  
//  //for (n=0; n<55; n++) ventprev[n] = 0;
//  
//  // iteramos hasta converger
//  do {
//    
//    // generamos una ventanita sintetica
//    raiz = sqrt (1+b*b);
//    r = raiz * raiz * raiz / (-2*c);
//    if (isnan(r) || fabs(r)>RMAX) {	
//      // caso recto, por lo que generamos una recta
//      //		if (iter>95) printf ("---R=inf a=%f b=%f c=%f\n", a, b, c);  
//      for (i=-2; i<=2; i++) for (j=-2; j<=2; j++)
//        vent[(i+2)*11+j+5] = ComputeStraightPixelColor(a+i*b+j, b, A, B);		
//      /*			
//       for (j=-2; j<=2; j++) {
//       for (i=-2; i<=2; i++) printf ("%.1f ", vent[(i+2)*11+j+5]);
//       printf ("\n");
//       }
//       */		
//			
//    } else {
//      // caso curvo, por lo que generamos un circulo
//      xc = b * r / raiz;
//      yc = a - r / raiz;	
//      if (c<=0) { D=A; F=B;} else { D=B; F=A;}
//      //if (iter>995) printf ("iter %d ---R=%f C=(%f,%f) a=%f b=%f c=%f\n",iter,r, xc, yc, a, b, c);	
//      for (i=-2; i<=2; i++) for (j=-2; j<=2; j++)
//        vent[(i+2)*11+j+5] = ComputeCurvePixelColor(xc-i, yc+j, fabs(r), D, F);
//    }
//    
//    // suavizamos la imagen
//    for (i=-1; i<=1; i++) for (j=-1; j<=1; j++) {
//      n = (i+2)*11+j+5;
//      vents[n] = (vent[n-12]+vent[n-11]+vent[n-10]+vent[n-1]+vent[n]+vent[n+1]+vent[n+10]+vent[n+11]+vent[n+12]) / 9;
//    }
//    
//    // sumamos las columnas
//    for (SL=0, k=l1; k<=l2; k++) SL += vents[11+k+5];
//    for (SM=0, k=m1; k<=m2; k++) SM += vents[22+k+5];
//    for (SR=0, k=r1; k<=r2; k++) SR += vents[33+k+5];
//    //	printf ("S = %f %f %f\n", SL, SM, SR);
//    
//    // buscamos la parabola que daria mi metodo
//    f = 2 * (A-B);
//    c1 = (SL + SR - 2*SM + A*(2*m2-l2-r2) - B*(2*m1-l1-r1)) / f;
//    b1 = (SR - SL + A*(l2-r2) + B*(r1-l1)) / f;		
//    a1 = (2*SM - (1+2*m2)*A - (1-2*m1)*B) / f - 0.75*c1;
//    //printf ("  estimada a1=%f b1=%f c1=%f\n", a1, b1, c1);
//    
//    // actualizamos la nueva parábola
//    a = a0 - a1 + a;
//    b = b0 - b1 + b;
//    c = c0 - c1 + c;
//    //	printf ("a=%f a0=%f a1=%f\n", a, a0, a1);
//    //tot_iter++;
//		
//    // miramos si hay convergencia
//    fa=fabs(a-aprev); fb=fabs(b-bprev); fc=fabs(c-cprev); 
//    //	if (iter>95) printf ("iter=%d fa=%f fb=%f fc=%f\n", iter, fa, fb, fc);
//    if (fa>1 || fb>1 || fc>1 || isnan(a) || isnan(b) || isnan(c)) break;
//    if (fa<umbral1 && fb<umbral1 && fc<umbral1) return(true); 
//    if (++iter>maxiter) {
//      if (fa<umbral2 && fb<umbral2 && fc<umbral2) return(true); 
//      else break;
//    }
//    aprev=a; bprev=b; cprev=c;
//    
//    /*
//     // miramos si hay convergencia
//     double dif;
//     iter++;
//     if (isnan(a) || isnan(b) || isnan(c)) break;
//     for (err=0,i=-1; i<=1; i++) for (j=-1; j<=1; j++) {
//     n = (i+2)*11+j+5;
//     dif = vent[n] - ventprev[n];
//     err += dif * dif;
//     ventprev[n] = vent[n];
//     }
//     printf ("iter %d error=%f\n", iter, err);
//     //	if (++iter>maxiter && err>0.1) break;
//     if (err>errprev) break; else errprev=err;
//     if (err<1e-6) {return(true);}
//     */
//    
//  } while (true);  
//  
//  // no converge
//  a=a0; b=b0; c=c0;
//  // printf ("no converge\n");
//  return(false);
//}

void UpdateImages(InrImage* C, InrImage* I, int x, int y, int z, 
                  unsigned char edgeCase, double a, double b, double c, double A,
                  double B)
{
  //Hay que meter en I y en C lo que corresponde
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
  
  double root = sqrt(1+b*b);
  double r    = root*root*root / (-2*c);
  double xc   = b * r / root;
  double yc   = a - r / root;
  double pixel_value, D, F;
  
  
  if (c<=0) 
  {
    D=A;
    F=B;
  }
  else 
  {
    D=B;
    F=A;
  }

  bool conv = SearchCircle(a, b, c, A, B, -1, 1, -1, 1, -1, 1);
  
  for (int i=hmin;i<=hmax;i++)
  {
    for (int j=vmin;j<=vmax;j++)
    {
      //Se calcula el valor correspondiente de intensidad
      if (isnan(r) || fabs(r)>RMAX) 
      {
        if (edgeCase == YMAX)
          pixel_value = ComputeStraightPixelColor(a+i*b+j, b, A, B);
        else 
          pixel_value = ComputeStraightPixelColor(a+j*b+i, b, A, B);
      }
      else 
      {
        if (fabs(r)<RMIN3x3) r = (r>0)? RMIN3x3 : -RMIN3x3;
        if (edgeCase == YMAX)
          pixel_value = ComputeCurvePixelColor(xc-i, yc+j, fabs(r), D, F);
        else 
          pixel_value = ComputeCurvePixelColor(-yc-i, -xc+j, fabs(r), D, F);
      }
      //Se mete el valor en la imagen de intensidad y se incrementa la imagen
      //de contadores
      I->BufferPos(x+i,y+j,z);
      C->BufferPos(x+i,y+j,z);
      //Based on convergence and the central row/column set the weight value
      if (conv) 
      {
        if (edgeCase == YMAX)
          weight = (i==0) ? 1000 : 10;
        else 
          weight = (j==0) ? 1000 : 10;
      }
      else 
      {
        if (edgeCase == YMAX)
          weight = (i==0) ? 10 : 2;
        else 
          weight = (j==0) ? 10 : 2;
      }
      //Set the intensity value and increment the pixel counter  
      I->FixeValeur((*I)(x+i,y+j,z) + pixel_value*weight);
      C->FixeValeur(((*C)(x+i,y+j,z)) + weight);
    }
  }
}


//Versión con la ventana de tamaño fijo 9x3
void SubPixel2D::SubpixelDenoising(int niter)
{
  int margin = 4;
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

  //For third dimension
  int z = 0;
  //Partial derivatives
  float parx, pary, partial;
  //Pointers to upos and vpos
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
  int m;
  
  for(int index=0; index<niter; index++)
  {
    C->InitZero();
    I->InitZero();
    G->InitZero();
    
    //1º Se promedia la imagen de entrada y se deja en G
    Promedio3x3(input, G.get(), A00, A01, A11);
    
    //Para que funcionen las macros de parciales tengo que jincar G como input
    //setInput(G.get());
    copyImage(input, G.get(), margin);
    //*input = *(G.get());
    //Para todos los pixels de G

    borderPixelVector.clear();
   
    for(int y = margin; y < G->DimY()-margin; y++)
    {
      for(int x = margin; x < G->DimX()-margin; x++)
      {
        pary = ffy(x,y,z);
        parx = ffx(x,y,z);
        if (parx*parx + pary*pary < threshold*threshold) continue;
        if (fabs(pary) >= fabs(parx))
        {
          //Vertical window
          u = upos;
          v = vpos;
          //The partial must be maximum in the column
          partial = fabs(FF(x+u[0],y+v[0],z) - FF(x+u[1],y+v[1],z));
          if (partial < threshold) continue;
          if (fabs(FF(x+u[2],y+v[2],z) - FF(x+u[3],y+v[3],z)) > partial) continue;
          if (fabs(FF(x+u[4],y+v[4],z) - FF(x+u[5],y+v[5],z)) > partial) continue;
          if (fabs(FF(x+u[6],y+v[6],z) - FF(x+u[7],y+v[7],z)) > partial) continue;
          if (fabs(FF(x+u[8],y+v[8],z) - FF(x+u[9],y+v[9],z)) > partial) continue;
          
          m = (ffx(x,y,z)*ffy(x,y,z)>0) ? 1 : -1;
          B = ((double) FF(x-m,y-3,z) + FF(x-m,y-4,z) + FF(x,y-4,z)) / 3.0;
          A = ((double) FF(x,y+4,z) + FF(x+m,y+4,z) + FF(x+m,y+3,z)) / 3.0;
          if (fabs(A-B)<threshold) continue;
          
          //Calculamos las sumas y los coeficientes de la parábola
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
          
          gx_n  = (ffx(x,y,z)>0) ? b*d : -b*d;
          gy_n  = (ffy(x,y,z)>0) ? d   : -d;
          des_n = (ffy(x,y,z)>0) ? -a  : a;
          
          if (ffy(x,y,z)<0) cu_n = -cu_n;
          
          //Set the calculated values on the borderPixel object
          pixel.setBorderPixelValues(A, B, YMAX, a, b, c, cu_n, x, y);
          //Add edge pixel to the vector
          borderPixelVector.push_back(pixel);
          
//          UpdateImages(input, C.get(), I.get(), x, y, z, YMAX, borderPixelVector,
//                       linear_case, threshold);
          UpdateImages(C.get(), I.get(), x, y, z, YMAX, a, b, c, A, B);
        }
        else
        {
          //Horizontal window
          u = vpos;
          v = upos;
          //The partial must be maximum in the row
          partial = fabs(FF(x+u[0],y+v[0],z) - FF(x+u[1],y+v[1],z));
          if (partial < threshold) continue;
          if (fabs(FF(x+u[2],y+v[2],z) - FF(x+u[3],y+v[3],z)) > partial) continue;
          if (fabs(FF(x+u[4],y+v[4],z) - FF(x+u[5],y+v[5],z)) > partial) continue;
          if (fabs(FF(x+u[6],y+v[6],z) - FF(x+u[7],y+v[7],z)) > partial) continue;
          if (fabs(FF(x+u[8],y+v[8],z) - FF(x+u[9],y+v[9],z)) > partial) continue;

          m = (ffx(x,y,z)*ffy(x,y,z)>0) ? 1 : -1;
          B = ((double) FF(x-3,y-m,z) + FF(x-4,y-m,z) + FF(x-4,y,z)) / 3.0;
          A = ((double) FF(x+4,y,z) + FF(x+4,y+m,z) + FF(x+3,y+m,z)) / 3.0;
          if (fabs(A-B)<threshold) continue;

          //Calculamos las sumas y los coeficientes de la parábola
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
          
          gx_n  = (ffx(x,y,z)>0) ? d   : -d;
          gy_n  = (ffy(x,y,z)>0) ? b*d : -b*d; 
          des_n = (ffx(x,y,z)>0) ? -a  : a;
          
          if (ffx(x,y,z)<0) cu_n = -cu_n;
                    
          //Set the calculated values on the borderPixel object
          pixel.setBorderPixelValues(A, B, XMAX, a, b, c, cu_n, x, y);
          //Add edge pixel to the vector
          borderPixelVector.push_back(pixel);
          
//          UpdateImages(input, C.get(), I.get(), x, y, z, XMAX, borderPixelVector,
//                       linear_case, threshold);
          UpdateImages(C.get(), I.get(), x, y, z, XMAX, a, b, c, A, B);
        }
      }
    }
    //*input = *(G.get());
    //Con las imágenes resultantes, se rellena la nueva imagen de entrada
    for (int y = margin; y < G->DimY()-margin; y++)
    {
      for (int x = margin; x < G->DimX()-margin; x++)
      {
        if ((*C)(x,y,z) > 0)
        {
          input->BufferPos(x,y,z);
          input->FixeValeur(((*I)(x,y,z))/((*C)(x,y,z)));
        }
      }
    }
  }
}


//Versión con ventana flotante y bordes muy cercanos (aún no)
/*void SubPixel2D::SubpixelDenoising(int niter)
{
  int margin = 4;
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

  //For third dimension
  int z = 0;
  //Partial derivatives
  float parx, pary, partial;
  //Pointers to upos and vpos
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
  int m;
  
  for(int index=0; index<niter; index++)
  {
    C->InitZero();
    I->InitZero();
    G->InitZero();
    
    //1º Se promedia la imagen de entrada y se deja en G
    Promedio3x3(input, G.get(), A00, A01, A11);
    
    //Para que funcionen las macros de parciales tengo que jincar G como input
    //setInput(G.get());
    copyImage(input, G.get(), margin);
    //*input = *(G.get());
    //Para todos los pixels de G

    borderPixelVector.clear();
   
    for(int y = margin; y < G->DimY()-margin; y++)
    {
      for(int x = margin; x < G->DimX()-margin; x++)
      {
        pary = ffy(x,y,z);
        parx = ffx(x,y,z);
        if (parx*parx + pary*pary < threshold*threshold) continue;
        if (fabs(pary) >= fabs(parx))
        {
          //Vertical window
          u = upos;
          v = vpos;
          //The partial must be maximum in the column
          partial = fabs(FF(x+u[0],y+v[0],z) - FF(x+u[1],y+v[1],z));
          if (partial < threshold) continue;
          if (fabs(FF(x+u[2],y+v[2],z) - FF(x+u[3],y+v[3],z)) > partial) continue;
          if (fabs(FF(x+u[4],y+v[4],z) - FF(x+u[5],y+v[5],z)) > partial) continue;
          if (fabs(FF(x+u[6],y+v[6],z) - FF(x+u[7],y+v[7],z)) > partial) continue;
          if (fabs(FF(x+u[8],y+v[8],z) - FF(x+u[9],y+v[9],z)) > partial) continue;
          
          m = (ffx(x,y,z)*ffy(x,y,z)>0) ? 1 : -1;
          B = ((double) FF(x-m,y-3,z) + FF(x-m,y-4,z) + FF(x,y-4,z)) / 3.0;
          A = ((double) FF(x,y+4,z) + FF(x+m,y+4,z) + FF(x+m,y+3,z)) / 3.0;
          if (fabs(A-B)<threshold) continue;
          
          //Calculamos las sumas y los coeficientes de la parábola
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
          
          gx_n  = (ffx(x,y,z)>0) ? b*d : -b*d;
          gy_n  = (ffy(x,y,z)>0) ? d   : -d;
          des_n = (ffy(x,y,z)>0) ? -a  : a;
          
          if (ffy(x,y,z)<0) cu_n = -cu_n;
          
          //Set the calculated values on the borderPixel object
          pixel.setBorderPixelValues(A, B, YMAX, a, b, c, cu_n, x, y);
          //Add edge pixel to the vector
          borderPixelVector.push_back(pixel);
          
//          UpdateImages(input, C.get(), I.get(), x, y, z, YMAX, borderPixelVector,
//                       linear_case, threshold);
          UpdateImages(C.get(), I.get(), x, y, z, YMAX, a, b, c, A, B);
        }
        else
        {
          //Horizontal window
          u = vpos;
          v = upos;
          //The partial must be maximum in the row
          partial = fabs(FF(x+u[0],y+v[0],z) - FF(x+u[1],y+v[1],z));
          if (partial < threshold) continue;
          if (fabs(FF(x+u[2],y+v[2],z) - FF(x+u[3],y+v[3],z)) > partial) continue;
          if (fabs(FF(x+u[4],y+v[4],z) - FF(x+u[5],y+v[5],z)) > partial) continue;
          if (fabs(FF(x+u[6],y+v[6],z) - FF(x+u[7],y+v[7],z)) > partial) continue;
          if (fabs(FF(x+u[8],y+v[8],z) - FF(x+u[9],y+v[9],z)) > partial) continue;

          m = (ffx(x,y,z)*ffy(x,y,z)>0) ? 1 : -1;
          B = ((double) FF(x-3,y-m,z) + FF(x-4,y-m,z) + FF(x-4,y,z)) / 3.0;
          A = ((double) FF(x+4,y,z) + FF(x+4,y+m,z) + FF(x+3,y+m,z)) / 3.0;
          if (fabs(A-B)<threshold) continue;

          //Calculamos las sumas y los coeficientes de la parábola
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
          
          gx_n  = (ffx(x,y,z)>0) ? d   : -d;
          gy_n  = (ffy(x,y,z)>0) ? b*d : -b*d; 
          des_n = (ffx(x,y,z)>0) ? -a  : a;
          
          if (ffx(x,y,z)<0) cu_n = -cu_n;
                    
          //Set the calculated values on the borderPixel object
          pixel.setBorderPixelValues(A, B, XMAX, a, b, c, cu_n, x, y);
          //Add edge pixel to the vector
          borderPixelVector.push_back(pixel);
          
//          UpdateImages(input, C.get(), I.get(), x, y, z, XMAX, borderPixelVector,
//                       linear_case, threshold);
          UpdateImages(C.get(), I.get(), x, y, z, XMAX, a, b, c, A, B);
        }
      }
    }
    //*input = *(G.get());
    //Con las imágenes resultantes, se rellena la nueva imagen de entrada
    for (int y = margin; y < G->DimY()-margin; y++)
    {
      for (int x = margin; x < G->DimX()-margin; x++)
      {
        if ((*C)(x,y,z) > 0)
        {
          input->BufferPos(x,y,z);
          input->FixeValeur(((*I)(x,y,z))/((*C)(x,y,z)));
        }
      }
    }
  }
}*/



