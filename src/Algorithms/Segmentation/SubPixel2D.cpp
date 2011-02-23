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
//#include "wrap_wxColour.h"
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
//Minimum radius for generating 9x5 windows
#define RMINGAUSS 	3.0

//Minimum radius for estimate inside a 3x3 window
#define RMIN3x3 1.7

//Primitive of the circle
#define P(x) (yc*(x) + 0.5*r*r*asin((x-xc)/r) + 0.5*(x-xc)*sqrt(r*r-(x-xc)*(x-xc)))

//Test if the indexes are inside the image, when calculate a partial
double imval(InrImage* input, int x,int y, int z){
  if (input->CoordOK(x,y,z)) 
    return (*input)(x,y,z);
  else 
//    cout << "out of image range (" << x << ", " << y << ", " << z << ")" << endl;
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

//Limits for ComputeCurveWindowColor
int Lims[5][2] = {{-1,-1}, {-4,4}, {-4,4}, {-4,4}, {1,1}};

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
  input        = inp_image;
  threshold    = (double)thres;
  linear_case  = lc;
  denoised     = new InrImage(WT_DOUBLE,"denoised.inr.gz",input);
}

//Destructor
SubPixel2D::~SubPixel2D()
{
  delete(denoised);
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

//Get the denoised image
InrImage* SubPixel2D::getDenoised()
{
  return denoised;
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

//Average3x3 method. It averages the input image for reduce the noise
void Average3x3 (InrImage* input, InrImage* result, double a00, double a01, 
                 double a11)
{
  double sum;
  double s = (double) a00 + 4*a01 + 4*a11;
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
  
  Average3x3(input, denoised, A00, A01, A11);
  setInput(denoised);
  
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
//also detects edges of 2px or more, using the original input image
void SubPixel2D::DenoisingGus()
{ 
  int margen = 5;
  double A, B;
  //Partials
  double parx, pary;
  double partial;
  int m, k, p;
  double par0, par1;
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
  
  //We start copying the input image and averege it
  InrImage input_copy(WT_DOUBLE,"input_copy.inr.gz",input);
  input_copy = *input;
  Average3x3(input, denoised, A00, A01, A11);
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
        
        //We search if there are other near edge (2 and 3 pixels case)
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
        
        //We compare with the low threshold
        //if (fabs(A-B) < low_threshold) continue;
        
        //If there are a second near edge, we create a new subimage form the original
        //and averaged it after for computing the edge
        if (bor2d || bor2u)
        {
          //My new synthetic image (11x5, because it's YMAX case)
          InrImage* fprime = new InrImage(5,11,1,WT_DOUBLE,"fprime.inr.gz");

          //Center of the 11x5 image (5,2)
          int fprimex=2;
          int fprimey=5;
          //We fill the synthetic image with the original values of the input
          for(int indj = -5; indj<=5; indj++)
          {
            for(int indi = -2; indi<=2; indi++)
            {
              fprime->BufferPos(fprimex+indi,fprimey+indj,z);
              fprime->FixeValeur(input_copy(x+indi,y+indj,z));
            }
          }
          //If top edge, update B on F' top 
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
          //If lower edge, update A in F' bottom
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
 
          //Average F' obtaining G'
          fprimex = 2;
          fprimey = 5;
          for(int indj = -4; indj<=4; indj++)
          {
            for(int indi= -1; indi<=1; indi++)
            {
              int posx = fprimex+indi;
              int posy = fprimey+indj;
              double suma = 0;
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
          //With the averaged image, we compute the sums of the columns with the 
          //subimage
          for (SL=0, k=ll1; k<=ll2; k++) 
            SL += (*fprime)(fprimex-1,fprimey+k,z);
          for (SM=0, k=mm1; k<=mm2; k++) 
            SM += (*fprime)(fprimex,fprimey+k,z);
          for (SR=0, k=rr1; k<=rr2; k++) 
            SR += (*fprime)(fprimex+1,fprimey+k,z);
          delete(fprime);
        }
        else //Else, we compute the sums of the columns with the big image
        {
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
        
        //We search if there are other near edge (2 and 3 pixels case)
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
        
        //We compare with the low threshold
        //if (fabs(A-B) < low_threshold) continue;
        
        //If there are a second near edge, we create a new subimage form the original
        //and averaged it after for computing the edge
        if (bor2d || bor2u)
        {
          //My new synthetic image (5x11, because it's XMAX case)
          InrImage* fprime = new InrImage(11,5,1,WT_DOUBLE,"fprime.inr.gz");
          //Center of the 5x11 image (2,5)
          int fprimex=5;
          int fprimey=2;
          //We fill the synthetic image with the original values of the input
          for(int indj = -2; indj<=2; indj++)
          {
            for(int indi = -5; indi<=5; indi++)
            {
              fprime->BufferPos(fprimex+indi,fprimey+indj,z);
              fprime->FixeValeur(input_copy(x+indi,y+indj,z));
            }
          }
          //If top edge, update B on F' top
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
          //If lower edge, update A in F' bottom
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
      
          //Average F' obtaining G'
          fprimex = 5;
          fprimey = 2;
          for(int indj = -1; indj<=1; indj++)
          {
            for(int indi= -4; indi<=4; indi++)
            {
              int posx = fprimex+indi;
              int posy = fprimey+indj;
              double suma = 0;
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
          //With the averaged image, we compute the sums of the rows with the 
          //subimage
          for (SL=0, k=ll1; k<=ll2; k++) 
            SL += (*fprime)(fprimex+k,fprimey-1,z);
          for (SM=0, k=mm1; k<=mm2; k++) 
            SM += (*fprime)(fprimex+k,fprimey,z);
          for (SR=0, k=rr1; k<=rr2; k++) 
            SR += (*fprime)(fprimex+k,fprimey+1,z);
          delete(fprime);
        }
        else //Else, we compute the sums of the rows with the big image
        {                  
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
}


//---------------------------------------------
// RESTORATION
//---------------------------------------------

/*With the gradient vector, the displacement inside the pixel and colors at
 both sides of the edge, we compute the color of the pixel. A is down and B is
 up.*/
double ComputePixelColor (double gx, double gy, double d, double A, double B)
{
  double m = fabs(gx/gy);	// Line equation -> y=d-mx;
  double y1, y2, x1, x2;
  double area;
  double result;
  
  //We compute the cut with the pixel vertical limits
  y1 = d + 0.5 * m;
  y2 = d - 0.5 * m;
  
  //The line pass down of the pixel
  if (y2>0.5) area = 0.0;
	else
  {
    //The line cuts the pixel right-down
    if (y1>0.5) {
      x1 = (d-0.5) / m;
      area =0.5 * (0.5-x1) * (0.5-y2);
    }
    else
    {
      //The line cuts the pixel from left to right
      if (y2>-0.5) {
        area = (0.5-y1) + 0.5 *(y1-y2);
      }
      else
      {
        //The line cuts the pixel left-up
        if (y1>-0.5) {
          x2 = (d+0.5) / m;
          area = 0.5 * (y1+0.5) * (x2+0.5);
          area = 1 - area;
        }
        else
        {
          //The line pass up the pixel
          area = 1.0;
        }
      }
    }
  }
     
  //We return the A and B percentage
  //printf ("y1=%f, y2=%f x1=%f x2=%f area=%f\n", y1,y2,x1,x2,area);
  result = area*A + (1-area)*B;
  return ((double) result);
}


/*With an edge <gx,gy> with des displacement and A and B colors, we generate
 a 9x5 subimage with an ideal ramp for this values. If edgeCase is XMAX, the
 subimage will be 5x9.*/
void ComputeWindowColor (unsigned char edgeCase, double gx, double gy, double des,
                         double A, double B, double *win)
{
  int s;
  double m;
  double absgx = fabs(gx);
  double absgy = fabs(gy);
  
  //If XMAX, we invert the axis
  if (edgeCase == XMAX) 
  { 
    SWAP_DOUBLE (gx, gy); 
    SWAP_DOUBLE (absgx, absgy);
  }
  
  //gx<gy in absolute value. If gy<0, we invert the values
  if (gy<0) 
  {
    gx = -gx;
    gy = -gy; 
    SWAP_DOUBLE (A, B); 
  }
  
  //Compute the window
  m = absgx / absgy; 
  for (int i=-2; i<=2; i++) 
    for (int j=Lims[i+2][0]; j<=Lims[i+2][1]; j++) 
    {
      s = 9*i + j + 22; //(i+2)*9+(j+4);
      win[s] = ComputePixelColor (absgx, absgy, des-j-i*m, A, B);
    }
  
  //If gx<0, we swap the lateral columns
  if (gx<0) for (int n=0; n<9; n++) 
  { 
    SWAP_DOUBLE (win[n+9], win[n+27]);
    win[5] = win[41];
    win[39] = win[3];
  }
  
  return;
}


/*Compute the pixel intensity value based on circle equation and inside and
  outside intensities*/
double ComputeCurvePixelColor(double xc, double yc, double r, double D, double F)
{
  //With the circunference (x-xc)2 + (y-yc)2 = r2, the intensity D in and the
  //intensity F out, we compute the pixel color
  double t, x0, x1, area;
  
  //cout << "xc=" << xc << " yc=" << yc << " r=" << r << " D=" << D << " F=" << F << endl;
  
  //Pass the center to right down (xc>0, yc<0, xc>-yc)
  xc = fabs(xc);
  yc = fabs(yc);
  if (xc < yc) 
  { 
    SWAP_DOUBLE (xc, yc);
  }
  yc = -yc;
  
  //If the pixel is outside, we return F
  if (yc+r<=-0.5 || xc-r>=0.5) 
    return (F);
  
  //Compute the cuts
  x0 = xc - sqrt(r*r - (-0.5-yc)*(-0.5-yc));
  if (x0 < xc-r) 
    x0 = xc-r;
  if (yc+r <= 0.5) 
    x1 = 0.5;
	else 
    x1 = xc - sqrt( r*r - (0.5-yc)*(0.5-yc));
	
  //If the pixel is inside, we return D
  if (x1 <= -0.5) 
    return (D); 
  
  //All posible cases
  if (yc <= -0.5) 
  {
  	if (x0 >= 0.5) 
      return (F);
    if (x0 > -0.5) 
    {
      if (x1 < 0.5)  
        area = P(x1) - P(x0) - 0.5*(x1+x0) + 0.5;
      else 
        area = P(0.5) - P(x0) - 0.5*x0 + 0.25;
    } 
    else 
    {
      if (x1 < 0.5)
        area = P(x1) - P(-0.5) - 0.5*x1 + 0.75;
      else 
        area = P(0.5) - P(-0.5) + 0.5;
    }
  } 
  else 
  {
    t = xc - r;
    if (x1 < 0.5) 
    {
      if (t >= -0.5)
      {
        area = 2 * (P(x0) - P(t) - yc*(x0-t)) +
				P(x1) - P(x0) - 0.5*(x1+x0) + 0.5;
      }
      else 
      {
        area = 2 * (P(x0) - P(-0.5) - yc*(x0+0.5)) +
				P(x1) - P(x0) - 0.5*(x1+x0) + 0.5;
      }
    } 
    else 
    {
      if (x0 <= 0.5)
      {
        area = 2 * (P(x0) - P(t) - yc*(x0-t)) +
				P(0.5) - P(x0) - 0.5*x0 + 0.25;
      }
      else 
        area = 2 * (P(0.5) - P(t) - yc*(0.5-t));
    }
  }

  return (double)(F + area*(D-F));
}


/*With an edge <gx,gy> with des displacement and A and B colors, we generate
 a 9x5 synthetic subimage with an ideal parable for this values.
 We compute the curve y=a+bx+cx2 (-v=a+bu+cu2).
 If edgeCase is equal to XMAX, the subimage will be 5x9.*/
void ComputeCurveWindowColor (unsigned char edgeCase, double gx, double gy,
                              double des, double cu, double A, double B,
                              double *win, int winsize)
{
  double absgx = fabs(gx);
  double absgy = fabs(gy); 
  double xc, yc, r, mod;
  int pen, s;
  double D, F;
  
  
  //If the radius is large, we consider a line not a parable 
  if (fabs(cu) < 0.001) 
  {
    ComputeWindowColor (edgeCase, gx, gy, des, A, B, win);
    return;
  }
  
  //If XMAX, we invert x and y axis
  if (edgeCase == XMAX) 
  { 
    SWAP_DOUBLE (gx, gy); 
    SWAP_DOUBLE (absgx, absgy);
  }
  
  //gx<gy in absolute value. If gy<0, we invert the colors and curvature
  if (gy<0) 
  { 
    SWAP_DOUBLE (A, B);
    cu = -cu;
  }
  
  //Compute the circle radius
  r = 1.0 / cu;
  
  //If it is very small, we put other
  if (winsize!=3 && fabs(r)<RMINGAUSS) r = (r>0)? RMINGAUSS : -RMINGAUSS;
  
  //We walk from  the circle for finding the center, in parametrics
  mod = sqrt (absgx*absgx+absgy*absgy);
  xc = r * absgx / mod;
  yc = -des - (absgy * r)/mod; 
  
  //We compute the window slope
  pen = (gx*gy>=0.0)? 1 : -1;
  
  //We compute the colors inside and outside
  if (r>0) 
  { 
    D=A; 
    F=B;
  } 
  else 
  { 
    D=B; 
    F=A;
  }
  r = fabs(r);
  
  // Compute the window
  for (int i=-2; i<=2; i++) 
    for (int j=Lims[i+2][0]; j<=Lims[i+2][1]; j++) 
    {
      s = 9*i + j + 22;  //(i+2)*9+(j+4);
      win[s] = ComputeCurvePixelColor (xc-i, yc+j, r, D, F);
    }

  
  //If the slope is negative, we exchanges de lateral columns
  if (pen<0) for (int n=0; n<9; n++) {
    SWAP_DOUBLE (win[n+9], win[n+27]); 
    win[5] = win[41];
    win[39] = win[3];
  }
  
  return;
}

/*This function update the intensities and counters images.*/
void UpdateImages(InrImage* input, InrImage * C, InrImage* I, int x, int y, int z, 
                  unsigned char edgeCase, double gx, double gy, double des, 
                  double cu, double A, double B, int linear_case, int m,
                  int l1, int l2, int m1, int m2, int r1, int r2)
{
  //Synthetic window
  double win[45];
  double s;
  
  //Margins treatment
  if (edgeCase == YMAX) 
  {
    //Top and bottom cases
    if (y<4 || y>C->DimY()-5) 
    {
      //Top edge, we estimate B
      if (y<4) 
      {
        B = 0;
        s = 0;
        //L
        for (int k = l1; k<-1+m; k++, s++)  
          B += (*input)(x-1,y+k,z);
        //M
        for (int k = m1; k<-1; k++, s++)  
          B += (*input)(x,y+k,z);
        //R
        for (int k = r1; k<-1-m; k++, s++)  
          B += (*input)(x+1,y+k,z);
        
        B /= s;
      }
      //Bottom edge, we estimate A
      if (y>C->DimY()-5) 
      {
        A = 0;
        s = 0;
        //L
        for (int k = 2+m; k<=l2; k++, s++)  
          A += (*input)(x-1,y+k,z);
        //M
        for (int k = 2; k<=m2; k++, s++)  
          A += (*input)(x,y+k,z);
        //R
        for (int k = 2-m; k<=r2; k++, s++)  
          A += (*input)(x+1,y+k,z);
       
        A /= s;
      }
      //Generate the synthetic window
      //Left
      for(int k = l1; k<=l2; k++)
      {
        C->BufferPos(x-1,y+k,z);
        C->FixeValeur((*C)(x-1,y+k,z)+1);
        I->BufferPos(x-1,y+k,z);
        if (k<-1+m) 
          I->FixeValeur((*I)(x-1,y+k,z) + B);
        else 
        {
          if (k>1+m)
            I->FixeValeur((*I)(x-1,y+k,z) + A);
          else 
            I->FixeValeur((*I)(x-1,y+k,z) + (*input)(x-1,y+k,z));
        }
      }
      //Midle
      for(int k = m1; k<=m2; k++)
      {
        C->BufferPos(x, y+k, z);
        C->FixeValeur((*C)(x,y+k,z)+1);
        I->BufferPos(x,y+k,z);
        if (k<-1)
          I->FixeValeur((*I)(x,y+k,z) + B);
        else 
        {
          if (k>1)
            I->FixeValeur((*I)(x,y+k,z) + A);
          else
            I->FixeValeur((*I)(x,y+k,z) + (*input)(x,y+k,z));
        }
      }
      //Right
      for(int k = r1; k<=r2; k++)
      {
        C->BufferPos(x+1, y+k, z);
        C->FixeValeur((*C)(x+1,y+k,z)+1);
        I->BufferPos(x+1, y+k, z);
        if (k<-1-m)
          I->FixeValeur((*I)(x+1, y+k, z) + B);
        else 
        {
          if (k>1-m)
            I->FixeValeur((*I)(x+1, y+k, z) + A);
          else
            I->FixeValeur((*I)(x+1, y+k, z) + (*input)(x+1, y+k, z));
        }
      }
      
      return;
    }
  }
  else 
  {
    //Left and right cases
    if (x<4 || x>C->DimX()-5) 
    {
      //Left edge, we estimate B
      if (x<4) 
      {
        B = 0;
        s = 0;
        for (int k = l1; k<=-1+m; k++, s++) 
          B += (*input)(x+k,y-1,z);
        for (int k = m1; k<=-1; k++, s++) 
          B += (*input)(x+k,y,z);
        for (int k = r1; k<=-1-m; k++, s++) 
          B += (*input)(x+k,y+1,z);
        B /= s;
      }
      //Rightn edge, we estimate A
      if (x>C->DimX()-5) 
      {
        A = 0;
        s = 0;
        for (int k = 2+m; k<=l2; k++, s++)
          A += (*input)(x+k,y-1,z);
        for (int k = 2; k<=m2; k++, s++)
          A += (*input)(x+k,y,z);
        for (int k = 2-m; k<=r2; k++, s++)
          A += (*input)(x+k,y+1,z);
        A /= s;
      }
      //Generate the synthetic window
      //Up
      for(int k = l1; k<=l2; k++)
      {
        C->BufferPos(x+k, y-1, z);
        C->FixeValeur((*C)(x+k, y-1, z) + 1);
        I->BufferPos(x+k, y-1, z);
        if (k<-1+m)
          I->FixeValeur((*I)(x+k, y-1, z) + B);
        else 
        {
          if (k>1+m)
            I->FixeValeur((*I)(x+k, y-1, z) + A);
          else 
            I->FixeValeur((*I)(x+k, y-1, z) + (*input)(x+k, y-1, z));
        }
      }
      //Midle
      for(int k = m1; k<=m2; k++)
      {
        C->BufferPos(x+k, y, z);
        C->FixeValeur((*C)(x+k, y, z) + 1);
        I->BufferPos(x+k, y, z);
        if (k<-1)
          I->FixeValeur((*I)(x+k, y, z) + B);
        else 
        {
          if (k>1)
            I->FixeValeur((*I)(x+k, y, z) + A);
          else 
            I->FixeValeur((*I)(x+k, y, z) + (*input)(x+k, y, z));
        }
      }
      //Down
      for(int k = r1; k<=r2; k++)
      {
        C->BufferPos(x+k,y+1,z);
        C->FixeValeur((*C)(x+k,y+1,z) + 1);
        I->BufferPos(x+k,y+1,z);
        if (k<-1-m)
          I->FixeValeur((*I)(x+k,y+1,z) + B);
        else 
        {
          if (k>1-m)
            I->FixeValeur((*I)(x+k,y+1,z) + A);
          else 
            I->FixeValeur((*I)(x+k,y+1,z) + (*input)(x+k,y+1,z));
        }
      }
      
      return;
    }
  }

  if (A<B)
  {
    SWAP_DOUBLE(A,B);
  }
  
  //Compute the synthetic window values
  if (linear_case)
  {
    ComputeWindowColor(edgeCase, gx, gy, des, A, B, win);
  }
  else 
  {
    ComputeCurveWindowColor(edgeCase, gx, gy, des, -cu, A, B, win, 9);
  }
  
  
  if (edgeCase == YMAX)
  {
    //Left
    for(int k = l1; k<=l2; k++)
    {
      I->BufferPos(x-1, y+k, z);
      C->BufferPos(x-1, y+k, z);
      I->FixeValeur((*I)(x-1, y+k, z) + win[k+13]*10);
      C->FixeValeur(((*C)(x-1, y+k, z)) + 10);
    }
    
    //Midle
    for(int k = m1; k<=m2; k++)
    {
      I->BufferPos(x, y+k, z);
      C->BufferPos(x, y+k, z);
      I->FixeValeur((*I)(x, y+k, z) + win[k+22]*1000);
      C->FixeValeur(((*C)(x, y+k, z)) + 1000);
    }
    
    //Right
    for(int k = r1; k<=r2; k++)
    {
      I->BufferPos(x+1, y+k, z);
      C->BufferPos(x+1, y+k, z);
      I->FixeValeur((*I)(x+1, y+k, z) + win[k+31]*10);
      C->FixeValeur(((*C)(x+1, y+k, z)) + 10);
    }
  }
  else
  {
    //Left
    for(int k = l1; k<=l2; k++)
    {
      I->BufferPos(x+k, y-1, z);
      C->BufferPos(x+k, y-1, z);
      I->FixeValeur((*I)(x+k, y-1, z) + win[k+13]*10);
      C->FixeValeur(((*C)(x+k, y-1, z)) + 10);
    }
    
    //Midle
    for(int k = m1; k<=m2; k++)
    {
      I->BufferPos(x+k, y, z);
      C->BufferPos(x+k, y, z);
      I->FixeValeur((*I)(x+k, y, z) + win[k+22]*1000);
      C->FixeValeur(((*C)(x+k, y, z)) + 1000);
    }
    
    //Right
    for(int k = r1; k<=r2; k++)
    {
      I->BufferPos(x+k, y+1, z);
      C->BufferPos(x+k, y+1, z);
      I->FixeValeur((*I)(x+k, y+1, z) + win[k+31]*10);
      C->FixeValeur(((*C)(x+k, y+1, z)) + 10);
    }
  }
}


//Version with floating window and very close edges
void SubPixel2D::SubpixelDenoising(int niter)
{
  int margin = 1;
  double A, B;
  //Counters image
  InrImage::ptr C = InrImage::ptr(new InrImage(input->DimX(), input->DimY(), 
                                               input->DimZ(), WT_UNSIGNED_SHORT,
                                               "counters.inr.gz"));
  //Intensities image
  InrImage::ptr I = InrImage::ptr(new InrImage(input->DimX(), input->DimY(), 
                                               input->DimZ(), WT_DOUBLE,
                                               "intensities.inr.gz"));
  //Averaged image
  InrImage::ptr G = InrImage::ptr(new InrImage(input->DimX(), input->DimY(),
                                               input->DimZ(), WT_DOUBLE,
                                               "averaged.inr.gz"));

  //Partial derivatives
  double parx, pary, partial;
  //Pointers to upos and vpos
  int *u, *v;
  //Indexes of the partials
  int upos[] = { 0, 0, 0, 0, 0, 0, 0, 0};
  int vpos[] = { -1,-3, 0,-2, 2, 0, 3, 1};
  int m, k, p;
  double par0, par1;
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
  
  //Limits for computing synthetic images
  Lims[1][0] = Lims[2][0] = Lims[3][0] = -4;
  Lims[1][1] = Lims[2][1] = Lims[3][1] = 4;
  InrImage input_copy(WT_DOUBLE,"input_copy.inr.gz",input);
  //Begins the iterative method
  for(int index=0; index<niter; index++)
  {
    //Initialize to zero the counters, intensities and averaged image
    C->InitZero();
    I->InitZero();
    //G->InitZero();
    //Make a copy of the input image
    input_copy = *input;
    //1st we average the input image
    Average3x3(input, G.get(), A00, A01, A11);
    //And set it as the input image for compute the partial derivatives
    *input = *(G.get());
    //If we are in a intermediate iteration, we must clear the border pixel vector
    borderPixelVector.clear();
    
    //For all pixels inside G
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
          partial = fabs(pary);
          //The partial must be maximum in the column or row
          if (partial < threshold) continue;
          if (y>2) if (fabs(FF(x+u[0],y+v[0],z) - FF(x+u[1],y+v[1],z)) > partial) continue;
          if (y>1) if (fabs(FF(x+u[2],y+v[2],z) - FF(x+u[3],y+v[3],z)) > partial) continue;
          if (y<input->DimY()-2) if (fabs(FF(x+u[4],y+v[4],z) - FF(x+u[5],y+v[5],z)) > partial) continue;
          if (y<input->DimY()-3) if (fabs(FF(x+u[6],y+v[6],z) - FF(x+u[7],y+v[7],z)) > partial) continue;
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
          
          //We search if there are other near edge (2 and 3 pixels case)
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
          
          //We compare with the low threshold
          //if (fabs(A-B) < low_threshold) continue;
          
          //If there are a second near edge, we create a new subimage form the original
          //and averaged it after for computing the edge
          if (bor2d || bor2u)
          {
            int mini, minj, maxi, maxj;
            //My new subimage (11x5, because it's YMAX case)
            InrImage* fprime = new InrImage(5,11,1,WT_DOUBLE,"fprime.inr.gz");
            //Near of the margins, the subimage is a little different
            minj = (y>4) ? -5 : -y;
            maxj = (y<input->DimY()-5) ? 5 : input->DimY()-1-y;
            if (x==1)
            {
              mini = -1;
              for(int j=minj; j<=maxj; j++) //1st column of the image
              {
                fprime->BufferPos(0,j+5,z);
                fprime->FixeValeur(2*input_copy(0,y+j,z) 
                                   - input_copy(1,y+j,z));
              }
            }
            else 
              mini = -2;
            if (x==input->DimX()-2)
            {
              maxi = 1;
              for (int j=minj; j<=maxj; j++) //Last column of the image
              {
                fprime->BufferPos(4,j+5,z);
                fprime->FixeValeur(2*input_copy(input_copy.DimX()-1,y+j,z)
                                   -input_copy(input_copy.DimX()-2,y+j,z));
              }
            }
            else 
              maxi = 2;
            
            if (minj>-5)
              for (int i=mini; i<=maxi; i++)
              {
                fprime->BufferPos(i+2,minj+4,z);
                fprime->FixeValeur(2*input_copy(x+i,0,z)
                                   -input_copy(x+i,1,z));
              }
            if (maxj<5)
              for (int i=mini; i<=maxi; i++)
              {
                fprime->BufferPos(i+2,maxj+6,z);
                fprime->FixeValeur(2*input_copy(x+i,input_copy.DimY()-1,z)
                                   -input_copy(x+i,input_copy.DimY()-2,z));
              }

            //We fill the synthetic image with the original values of the input
            for(int indj = minj; indj<=maxj; indj++)
            {
              for(int indi = mini; indi<=maxi; indi++)
              {
                fprime->BufferPos(indi+2,indj+5,z);
                fprime->FixeValeur(input_copy(x+indi,y+indj,z));
              }
            }
            //If top edge, update B on F' top
            if (bor2u)
            {
              par0 = ffyu (x-2, y+l1+p,z);
              int ll = (par0*pary>0)? l1+p-1 : l1+p;
              par1 = ffyu (x+2, y+r1+1-p,z);
              int rr = (par1*pary>0)? r1-p : r1+1-p;
              for (int k=-5; k<=ll; k++)
              {
                fprime->BufferPos(0,k+5,z);
                fprime->FixeValeur(B);
              }
              for (int k=-5; k<=l1; k++)
              {
                fprime->BufferPos(1,k+5,z);
                fprime->FixeValeur(B);
              }
              for (int k=-5; k<=m1; k++)
              {
                fprime->BufferPos(2,k+5,z);
                fprime->FixeValeur(B);
              }
              for (int k=-5; k<=r1; k++)
              {
                fprime->BufferPos(3,k+5,z);
                fprime->FixeValeur(B);
              }
              for (int k=-5; k<=rr; k++)
              {
                fprime->BufferPos(4,k+5,z);
                fprime->FixeValeur(B);
              }
              ll1=-3+m; mm1=-3; rr1=-3-m;
            }
            //If lower edge, update A in F' bottom
            if (bor2d)
            {
              par0 = ffyd (x-2, y+l2+p-1,z);
              int ll = (par0*pary>0)? l2+p : l2+p-1;
              par1 = ffyd (x+2, y+r2-p,z);
              int rr = (par1*pary>0)? r2+1-p : r2-p;					
              for (int k=ll; k<=5; k++)
              {
                fprime->BufferPos(0,k+5,z);
                fprime->FixeValeur(A);
              }
              for (int k=l2; k<=5; k++)
              {
                fprime->BufferPos(1,k+5,z);
                fprime->FixeValeur(A);
              }
              for (int k=m2; k<=5; k++)
              {
                fprime->BufferPos(2,k+5,z);
                fprime->FixeValeur(A);
              }
              for (int k=r2; k<=5; k++)
              {
                fprime->BufferPos(3,k+5,z);
                fprime->FixeValeur(A);
              }
              for (int k=rr; k<=5; k++)
              {
                fprime->BufferPos(4,k+5,z);
                fprime->FixeValeur(A);
              }
              ll2=3+m;  mm2=3;  rr2=3-m;
            }
            //Average F' obtaining G'
            //Central position of the subimage (2,5)
            int fprimex = 2;
            int fprimey = 5;
            for(int indj = -4; indj<=4; indj++)
            {
              for(int indi= -1; indi<=1; indi++)
              {
                int posx = fprimex+indi;
                int posy = fprimey+indj;
                double suma = 0;
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
            //With the averaged image, we compute the sums of the columns with the 
            //subimage
            for (SL=0, k=ll1; k<=ll2; k++) 
              SL += (*fprime)(fprimex-1,fprimey+k,z);
            for (SM=0, k=mm1; k<=mm2; k++) 
              SM += (*fprime)(fprimex,fprimey+k,z);
            for (SR=0, k=rr1; k<=rr2; k++) 
              SR += (*fprime)(fprimex+1,fprimey+k,z);
            delete(fprime);
          }
          else //Else, we compute the sums of the columns with the big image
          {            
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
          
          
          //Set the calculated values on the borderPixel object
          pixel.setBorderPixelValues(A, B, YMAX, a, b, c, cu, x, y);
          //Add edge pixel to the vector
          borderPixelVector.push_back(pixel);
          
          //Update the counters and intensities images
          UpdateImages(&input_copy, C.get(), I.get(), x, y, z, YMAX, gx, gy, des, 
                       cu, A, B, linear_case, m, l1, l2, m1, m2, r1, r2);
        }
        else
        {
          //Horizontal window
          u = vpos;
          v = upos;
          partial = fabs(parx);

          //The partial must be maximum in the column or row
          if (partial < threshold) continue;
          if (x>2) if (fabs(FF(x+u[0],y+v[0],z) - FF(x+u[1],y+v[1],z)) > partial) continue;
          if (x>1) if (fabs(FF(x+u[2],y+v[2],z) - FF(x+u[3],y+v[3],z)) > partial) continue;
          if (x<input->DimX()-2) if (fabs(FF(x+u[4],y+v[4],z) - FF(x+u[5],y+v[5],z)) > partial) continue;
          if (x<input->DimX()-3) if (fabs(FF(x+u[6],y+v[6],z) - FF(x+u[7],y+v[7],z)) > partial) continue;

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
          
          //We search if there are other near edge (2 and 3 pixels case)
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
          if (j1>-4 && x+j1-2>=0)
          {
            par0 = (x+j1-2>0) ? ffx(x+j1-2,y+i1,z) : ffxr(0,y+i1,z);
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
          if (j2<4 && x+j2+2<=input->DimY()-1)
          {
            par0 = (x+j2+2<input->DimX()-1) ? ffx(x+j2+2,y+i2,z) : ffxl(input->DimX()-1,y+i2,z);
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
          
          //We compare with the low threshold
          //if (fabs(A-B) < low_threshold) continue;
          
          //If there are a second near edge, we create a new subimage form the original
          //and averaged it after for computing the edge
          if (bor2d || bor2u)
          {
            int mini, minj, maxi, maxj;
            //My new subimage (5x11, because it's XMAX case)
            InrImage* fprime = new InrImage(11,5,1,WT_DOUBLE,"fprime.inr.gz");
            //Near of the margin the subimage is a little different
            minj = (x>4) ? -5 : -x;
            maxj = (x<input->DimX()-5) ? 5 : input->DimX()-1-x;
            if (y==1)
            {
              mini = -1;
              for (int j=minj; j<=maxj; j++)
              {
                fprime->BufferPos(j+5,0,z);
                fprime->FixeValeur(2*input_copy(x+j,0,z)
                                   - input_copy(x+j,1,z));
              }
            }
            else 
              mini = -2;
            if (y == input->DimY()-2)
            {
              maxi = 1;
              for (int j=minj; j<=maxj; j++)
              {
                fprime->BufferPos(j+5,4,z);
                fprime->FixeValeur(2*input_copy(x+j,input_copy.DimY()-1,z)
                                   - input_copy(x+j,input_copy.DimY()-2,z));
              }
            }
            else 
              maxi = 2;
            
            if (minj>-5)
              for (int i=mini; i<=maxi; i++)
              {
                fprime->BufferPos(minj+4, i+2, z);
                fprime->FixeValeur(2*input_copy(0,y+i,z)
                                   - input_copy(1,y+i,z));
              }
            if (maxj<5)
              for (int i=mini; i<=maxi; i++)
              {
                fprime->BufferPos(maxj+6, i+2, z);
                fprime->FixeValeur(2*input_copy(input_copy.DimX()-1,y+i,z)
                                   - input_copy(input_copy.DimX()-2,y+i,z));
              }
            
            //We fill the synthetic image with the original values of the input
            for(int indj = minj; indj<=maxj; indj++)
            {
              for(int indi = mini; indi<=maxi; indi++)
              {
                fprime->BufferPos(indj+5, indi+2, z);
                fprime->FixeValeur(input_copy(x+indj,y+indi,z));
              }
            }
            //If top edge, update B on F' top
            if (bor2u)
            {
              par0 = ffxl (x+l1+p, y-2,z);
              int ll = (par0*parx>0)? l1+p-1 : l1+p;
              par1 = ffxl (x+r1+1-p, y+2,z);
              int rr = (par1*parx>0)? r1-p : r1+1-p;
              for (int k=-5; k<=ll; k++)
              {
                fprime->BufferPos(5+k,0,z);
                fprime->FixeValeur(B);
              }
              for (int k=-5; k<=l1; k++)
              {
                fprime->BufferPos(5+k,1,z);
                fprime->FixeValeur(B);
              }
              for (int k=-5; k<=m1; k++)
              {
                fprime->BufferPos(5+k,2,z);
                fprime->FixeValeur(B);
              }
              for (int k=-5; k<=r1; k++)
              {
                fprime->BufferPos(5+k,3,z);
                fprime->FixeValeur(B);
              }
              for (int k=-5; k<=rr; k++)
              {
                fprime->BufferPos(5+k,4,z);
                fprime->FixeValeur(B);
              }
              ll1=-3+m; mm1=-3; rr1=-3-m;
            }
            //If lower edge, update A in F' bottom
            if (bor2d)
            {
              par0 = ffxr (x+l2+p-1, y-2,z);
              int ll = (par0*parx>0)? l2+p : l2+p-1;
              par1 = ffxr (x+r2-p, y+2,z);
              int rr = (par1*parx>0)? r2+1-p : r2-p;					
              for (int k=ll; k<=5; k++)
              {
                fprime->BufferPos(5+k,0,z);
                fprime->FixeValeur(A);
              }
              for (int k=l2; k<=5; k++)
              {
                fprime->BufferPos(5+k,1,z);
                fprime->FixeValeur(A);
              }
              for (int k=m2; k<=5; k++)
              {
                fprime->BufferPos(5+k,2,z);
                fprime->FixeValeur(A);
              }
              for (int k=r2; k<=5; k++)
              {
                fprime->BufferPos(5+k,3,z);
                fprime->FixeValeur(A);
              }
              for (int k=rr; k<=5; k++)
              {
                fprime->BufferPos(5+k,4,z);
                fprime->FixeValeur(A);
              }
              ll2=3+m;  mm2=3;  rr2=3-m;
            }
            
            //Average F' obtaining G'
            //Center position of the subimage (5,2)
            int fprimex = 5;
            int fprimey = 2;
            for(int indj = -1; indj<=1; indj++)
            {
              for(int indi= -4; indi<=4; indi++)
              {
                int posx = fprimex+indi;
                int posy = fprimey+indj;
                double suma = 0;
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
            //With the averaged image, we compute the sums of the rows with the 
            //subimage
            for (SL=0, k=ll1; k<=ll2; k++) 
              SL += (*fprime)(fprimex+k,fprimey-1,z);
            for (SM=0, k=mm1; k<=mm2; k++) 
              SM += (*fprime)(fprimex+k,fprimey,z);
            for (SR=0, k=rr1; k<=rr2; k++) 
              SR += (*fprime)(fprimex+k,fprimey+1,z);
            delete(fprime);
          }
          else //Else, we compute the sums of the rows with the big image
          {                    
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
                    
          //Set the calculated values on the borderPixel object
          pixel.setBorderPixelValues(A, B, XMAX, a, b, c, cu, x, y);
          //Add edge pixel to the vector
          borderPixelVector.push_back(pixel);
          
          UpdateImages(&input_copy, C.get(), I.get(), x, y, z, XMAX, gx, gy, des, 
                       cu, A, B, linear_case, m, l1, l2, m1, m2, r1, r2);
        }
      }
    }
    //Con las imágenes resultantes, se rellena la nueva imagen de entrada
    //With the result, we fill the input image for the next iteration
    for (int y = 0; y < G->DimY(); y++)
    {
      for (int x = 0; x < G->DimX(); x++)
      {
        if ((*C)(x,y,z) > 0)
        {
          input->BufferPos(x,y,z);
          //The value is the quotien of the intensity and the counter
          input->FixeValeur(((*I)(x,y,z))/((*C)(x,y,z)));
        }
      }
    }
  }
}




