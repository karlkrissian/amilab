/*
 *  SubVoxel3D.cpp
 *  AMILab
 */

#include "SubVoxel3D.h"
#include <cmath>

//Border type macros
#define XMAX  1
#define YMAX  2
#define ZMAX  3

//3D partials
//Test if the indexes are inside the image, when calculate a partial
double valim(InrImage* input, int x,int y, int z){
  if (input->CoordOK(x,y,z)) 
    return (*input)(x,y,z);
  else 
//    cout << "out of image range (" << x << ", " << y << ", " << z << ")" << endl;
  return 0;
}
//Access to a voxel
#define F(x,y,z)    valim(input,x,y,z)
//Partials
#define fx(x,y,z)   (F(x+1,y,z) - F(x-1,y,z))
#define fy(x,y,z)   (F(x,y+1,z) - F(x,y-1,z))
#define fz(x,y,z)   (F(x,y,z+1) - F(x,y,z-1))
#define fxl(x,y,z)  (F(x,y,z)   - F(x-1,y,z))
#define fxr(x,y,z)	(F(x+1,y,z) - F(x,y,z))
#define fyd(x,y,z) 	(F(x,y,z)   - F(x,y-1,z))
#define fyu(x,y,z)	(F(x,y+1,z) - F(x,y,z))
#define fzb(x,y,z) 	(F(x,y,z)   - F(x,y,z-1))
#define fzf(x,y,z)	(F(x,y,z+1) - F(x,y,z))

//---------------------------------------------
//borderVoxel class methods
//---------------------------------------------
void borderVoxel::setBorderVoxelValues(double intA, double intB, 
                                       unsigned char bord,double coef_a, 
                                       double coef_b, double coef_c,
                                       double coef_d, double coef_f, 
                                       double coef_g, double cu, 
                                       int posx, int posy, int posz,
                                       double normx, double normy, double normz)
{
  //Intensities
  A         = intA;
  B         = intB;
  //Border type
  border    = bord;
  //Paraboloid coefficients
  a         = coef_a;
  b         = coef_b;
  c         = coef_c;
  d         = coef_d;
  f         = coef_f;
  g         = coef_g;
  //Curvature
  curvature = cu;
  //Position
  px        = posx;
  py        = posy;
  pz        = posz;
  //Normal
  nx = normx;
  ny = normy;
  nz = normz;
}

double borderVoxel::getAIntensity()
{
  return A;
}

double borderVoxel::getBIntensity()
{
  return B;
}

unsigned char borderVoxel::getBorder()
{
  return border;
}

double borderVoxel::getCoefficient_a()
{
  return a;
}

double borderVoxel::getCoefficient_b()
{
  return b;
}

double borderVoxel::getCoefficient_c()
{
  return c;
}

double borderVoxel::getCoefficient_d()
{
  return d;
}

double borderVoxel::getCoefficient_f()
{
  return f;
}

double borderVoxel::getCoefficient_g()
{
  return g;
}

double borderVoxel::getCurvature()
{
  return curvature;
}

int borderVoxel::getPosX()
{
  return px;
}

int borderVoxel::getPosY()
{
  return py;
}

int borderVoxel::getPosZ()
{
  return pz;
}

double borderVoxel::getNx()
{
  return nx;
}
double borderVoxel::getNy()
{
  return ny;
}
double borderVoxel::getNz()
{
  return nz;
}

void borderVoxel::printBorderVoxel(int linear_case)
{
  cout << "----------------------------------" << endl;
  cout << "Voxel (" << px << ", " << py << ", " << pz << ")" << endl;
  const char* tb = (border==2) ? "YMAX" : "XMAX";
  cout << "Border       = " << tb << endl;
  cout << "A intensity  = " << A << endl;
  cout << "B intensity  = " << B << endl;
  cout << "Paraboloid coefficients: a = " << a << ", b = " << b << ", c = " << c;
  cout << ", d = " << d << ", f = " << f << ", g = " << g << endl;
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
//SubVoxel3D class methods
//---------------------------------------------
//Constructor
SubVoxel3D::SubVoxel3D(InrImage* inp_image, float thres)
{
  input       = inp_image;
  threshold   = thres;
}

//Destructor
SubVoxel3D::~SubVoxel3D() {}

//Get the vector with the border voxels
vector<borderVoxel> SubVoxel3D::getBorderVoxelVector()
{
  return borderVoxelVector;
}

//Fill the images with the edges information
void SubVoxel3D::fillImages(InrImage::ptr AIntensity, InrImage::ptr BIntensity, 
                  InrImage::ptr border, InrImage::ptr a, InrImage::ptr b, 
                  InrImage::ptr c, InrImage::ptr d, InrImage::ptr f, 
                  InrImage::ptr g, InrImage::ptr curvature, 
                  InrImage::ptr posx, InrImage::ptr posy, InrImage::ptr posz,
                  InrImage::ptr nx, InrImage::ptr ny, InrImage::ptr nz)
{
  int x = 0;
  int y = 0;
  int z = 0;
  
  for(vector<borderVoxel>::iterator i=borderVoxelVector.begin(); 
      i!= borderVoxelVector.end(); i++, x++)
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
    //Coefficient d
    d->BufferPos(x,y,z);
    d->FixeValeur(i->getCoefficient_d());
    //Coefficient f
    f->BufferPos(x,y,z);
    f->FixeValeur(i->getCoefficient_f());
    //Coefficient g
    g->BufferPos(x,y,z);
    g->FixeValeur(i->getCoefficient_g());
    //Curvature
    curvature->BufferPos(x,y,z);
    curvature->FixeValeur(i->getCurvature());
    //X position
    posx->BufferPos(x,y,z);
    posx->FixeValeur(i->getPosX());
    //Y position
    posy->BufferPos(x,y,z);
    posy->FixeValeur(i->getPosY());
    //Z position
    posz->BufferPos(x,y,z);
    posz->FixeValeur(i->getPosZ());
    //Normal x component
    nx->BufferPos(x,y,z);
    nx->FixeValeur(i->getNx());
    //Normal y component
    ny->BufferPos(x,y,z);
    ny->FixeValeur(i->getNy());
    //Normal z component
    nz->BufferPos(x,y,z);
    nz->FixeValeur(i->getNz());
  }
}

//3D subpixel method for second order edges
void SubVoxel3D::GradienteCurvo3D()
{
  //Margin at the limits of the image
  int margin = 3;
  int dx, dy, dz;
  int m;
  //, nn;
  unsigned char edge_type;
  //Intenisities
  double A, B;
  //Paraboloid coefficients
  double a, b, c, d, f, g;
  float partial;
  //Sums
  double S1, S2, S3, S4, S5, S6;
  //borderVoxel variable for store edge parameters
  borderVoxel voxel;
  
  //For all voxels
  for (int z = margin; z < input->DimZ() - margin; z++)
  {
    for (int y = margin; y < input->DimY() -  margin; y++)
    {
      for (int x = margin; x < input->DimX() - margin; x++)
      {
//        cout << "Pos (" << x << ", " << y << ", " << z << ")" << endl;
        //We search the maximum partial (x, y or z)
        if ((fabs(fy(x,y,z)) > fabs(fx(x,y,z))) && (fabs(fy(x,y,z)) > fabs(fz(x,y,z))))
        { //cout << "YMAX" << endl;
          //The maximum partial is in y
          partial = fabs(fy(x,y,z));
          
          //The partial must be bigger than the threshold and the bigest of the column
          if (partial < threshold)         continue;
          if (fabs(fy(x,y-2,z)) > partial) continue;
          if (fabs(fy(x,y-1,z)) > partial) continue;
          if (fabs(fy(x,y+1,z)) > partial) continue;
          if (fabs(fy(x,y+2,z)) > partial) continue;
          
          //We estimate the intensity at both sides of the edge
          dx = (fx(x,y,z)*fy(x,y,z) < 0) ? 1 : -1;
          dz = (fz(x,y,z)*fy(x,y,z) < 0) ? 1 : -1;
          A  = F(x+dx,y-3,z-dz) + F(x+dx,y-3,z) + F(x+dx,y-3,z+dz) + F(x,y-3,z) +
               F(x,y-3,z+dz) + F(x-dx,y-3,z+dz) + F(x+dx,y-2,z) +
               F(x+dx,y-2,z+dz) + F(x,y-2,z+dz);
          A /= 9.0;
          B  = F(x-dx,y+3,z+dz) + F(x-dx,y+3,z) + F(x-dx,y+3,z-dz) + F(x,y+3,z) +
               F(x,y+3,z-dz) + F(x+dx,y+3,z-dz) + F(x-dx,y+2,z) +
               F(x-dx,y+2,z-dz) + F(x,y+2,z-dz);
          B /= 9.0;
          
          //If the difference is lower than the threshold, we must continue
          if (fabs(A-B) < threshold) continue;
          
          //It's a voxel edge
          edge_type = YMAX;
          m         = (fx(x,y,z) * fz(x,y,z) >= 0) ? 1 : -1;
          //nn        = (fy(x,y,z) < 0) ? 1 : -1;
          
          //We compute the column sums
          S1 = S2 = S3 = S4 = S5 = S6 = 0.0;
          for (int yk = y-margin; yk<=y+margin ; yk++)
          {
            S1 += F(x+1,yk,z);
            S2 += F(x,yk,z-1);
            S3 += F(x,yk,z);
            S4 += F(x,yk,z+1);
            S5 += F(x-1,yk,z);
            S6 += F(x+1,yk,z-m) + F(x-1,yk,z+m);
          }
        }
        else
        {
          if (fabs(fx(x,y,z)) > fabs(fz(x,y,z)))
          { //cout << "XMAX" << endl;
            //The maximum partial is in x
            partial = fabs(fx(x,y,z));
            
            //The partial must be bigger than the threshold and the bigest of the column
            if (partial < threshold)         continue;
            if (fabs(fx(x-2,y,z)) > partial) continue;
            if (fabs(fx(x-1,y,z)) > partial) continue;
            if (fabs(fx(x+1,y,z)) > partial) continue;
            if (fabs(fx(x+2,y,z)) > partial) continue;
            
            //We estimate the intensity at both sides of the edge
            dy = (fy(x,y,z)*fx(x,y,z) < 0) ? 1 : -1;
            dz = (fz(x,y,z)*fx(x,y,z) < 0) ? 1 : -1;
            A  = F(x-3,y+dy,z-dz) + F(x-3,y+dy,z) + F(x-3,y+dy,z+dz) + F(x-3,y,z) +
                 F(x-3,y,z+dz) + F(x-3,y-dy,z+dz) + F(x-2,y+dy,z) +
                 F(x-2,y+dy,z+dz) + F(x-2,y,z+dz);
            A /= 9.0;
            B  = F(x+3,y-dy,z+dz) + F(x+3,y-dy,z) + F(x+3,y-dy,z-dz) + F(x+3,y,z) +
                 F(x+3,y,z-dz) + F(x+3,y+dy,z-dz) + F(x+2,y-dy,z) +
                 F(x+2,y-dy,z-dz) + F(x+2,y,z-dz);
            B /= 9.0;
            
            //If the difference is lower than the threshold, we must continue
            if (fabs(A-B) < threshold) continue;
            
            //It's a voxel edge
            edge_type = XMAX;
            m         = (fy(x,y,z)*fz(x,y,z) >= 0) ? 1 : -1;
            //nn        = (fx(x,y,z) < 0) ? 1 : -1;
            
            //We compute the column sums
            S1 = S2 = S3 = S4 = S5 = S6 = 0.0;
            for (int xk = x-margin; xk <= x+margin; xk++)
            {
              S1 += F(xk,y+1,z);
              S2 += F(xk,y,z-1);
              S3 += F(xk,y,z);
              S4 += F(xk,y,z+1);
              S5 += F(xk,y-1,z);
              S6 += F(xk,y+1,z-m) + F(xk,y-1,z+m);
            }
          }
          else 
          { //cout << "ZMAX" << endl;
            //The maximum partial is in z
            partial = fabs(fz(x,y,z));
            
            //The partial must be bigger than the threshold and the bigest of the column
            if (partial<threshold)         continue;
            if (fabs(fz(x,y,z-2))>partial) continue;
            if (fabs(fz(x,y,z-1))>partial) continue;
            if (fabs(fz(x,y,z+1))>partial) continue;
            if (fabs(fz(x,y,z+2))>partial) continue;
            
            //We estimate the intensity at both sides of the edge
            dx = (fx(x,y,z)*fz(x,y,z) < 0) ? 1 : -1;
            dy = (fy(x,y,z)*fz(x,y,z) < 0) ? 1 : -1;
            A  = F(x+dx,y-dy,z-3) + F(x+dx,y,z-3) + F(x+dx,y+dy,z-3) + F(x,y,z-3) +
                 F(x,y+dy,z-3) + F(x-dx,y+dy,z-3) + F(x+dx,y,z-2) +
                 F(x+dx,y+dy,z-2) + F(x,y+dy,z-2);
            A /= 9.0;
            B  = F(x-dx,y+dy,z+3) + F(x-dx,y,z+3) + F(x-dx,y-dy,z+3) + F(x,y,z+3) +
                 F(x,y-dy,z+3) + F(x+dx,y-dy,z+3) + F(x-dx,y,z+2) +
                 F(x-dx,y-dy,z+2) + F(x,y-dy,z+2);
            B /= 9.0;
            
            //If the difference is lower than the threshold, we must continue
            if (fabs(A-B) < threshold) continue;
            
            //It's a voxel edge
            edge_type = ZMAX;
            m         = (fx(x,y,z)*fy(x,y,z) >= 0) ? 1 : -1;
            //nn        = (fz(x,y,z) < 0) ? 1 : -1;
            
            //We compute the column sums
            S1 = S2 = S3 = S4 = S5 = S6 = 0.0;
            for (int zk = z-margin; zk <= z+margin; zk++)
            {
              S1 += F(x+1,y,zk);
              S2 += F(x,y-1,zk);
              S3 += F(x,y,zk);
              S4 += F(x,y+1,zk);
              S5 += F(x-1,y,zk);
              S6 += F(x+1,y-m,zk) + F(x-1,y+m,zk);
            }
          } //end else z max
        } // end else y max
        
        //At any case, we compute the paraboloid coefficients.
        a = (28*S3-S1-S2-S4-S5-84*A-84*B) / 24 / (A-B);
        b = (S1-S5) / 2 / (A-B);
        c = (S4-S2) / 2 / (A-B);
        d = (S1+S5-2*S3) / 2 / (A-B);
        f = m * (S1+S2+S4+S5-S6-2*S3) / 2 / (A-B);
        g = (S2+S4-2*S3) / 2 / (A-B);
        
        //We compute the normal components
        double mod = (A-B) / sqrt(1+b*b+c*c);
        double nx = mod*b;
        double ny = -mod;
        double nz = mod*c;
        //Depending of the edge type, interchange the components of the normal
        if (edge_type==XMAX)
        {
          double temp=nx;
          nx=ny;
          ny=temp;
        }
        
        if (edge_type==ZMAX)
        {
          double temp=nz;
          nz=ny;
          ny=temp;
        }
        
        //Set the edge parameters
        voxel.setBorderVoxelValues(A, B, edge_type, a, b, c, d, f, g, 0.0, 
                                   x, y, z, nx, ny, nz);
        borderVoxelVector.push_back(voxel);
      } // end for x
    } // end for y
  } // end for z
} //end GradienteCurvo3D






