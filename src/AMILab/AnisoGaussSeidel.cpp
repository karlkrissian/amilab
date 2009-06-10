/*
    ==================================================
    Software : AMILab
    Authors  : Karl Krissian
    Email    : karl@bwh.harvard.edu

    AMILab is a language for image processing
    ==================================================
    Copyright (C) 1996-2005  Karl Krissian

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

    ================================================== 
   The full GNU Lesser General Public License file is in Devel/Sources/Prog/LesserGPL_license.txt
*/
/* Calcul des courbures principales
 *
 *
 * Karl KRISSIAN
 * fichier AnisoGaussSeidel.c
 *
 * 2D and 3D Restoration with Anisotropic diffusion
 * 
 */

#include <pthread.h>

#include "style.hpp"
#include "inrimage.hpp"
#include "math1.hpp"
#include "DeriveesLissees.hpp"
#include "filtrage_rec.hpp"
#include "DirPrincipales.hpp"
#include "CurvaturasPrincipales.hpp"
#include "AnisoGaussSeidel.h"
#include "stdio.h"
//#include "fonctions.h"
#include "localstats.h"

#include "FloatMatrix.hpp"
#include "Eigen.hpp"

#include "DefineClass.hpp"
#include "amilab_messages.h"

#define DER_DISCR 1
#define DER_GAUSS 2

#define MODE_2D 2
#define MODE_3D 3

#define GAUSSIAN_NOISE 0
#define SPECKLE_NOISE  1

#define CONTOURS_GRAD      0
#define CONTOURS_SRAD      1  // use Yu and Acton term for contours
#define CONTOURS_RNRAD     2  // Rician Noise Reducing Anisotropic Diffusion
#define CONTOURS_RNRAD_NEW 3  // Rician Noise Reducing Anisotropic Diffusion, new version using
                             // directional local statistics for the diffusion matrix

#define IMPLICIT 1

#define LOCAL_STRUCT_CURV   0 // use gradient and princ. curv. for the
                              // description of the local structure
#define LOCAL_STRUCT_TENSOR 1 // Use the structure tensor

#define DIFF_MATRIX_EIGEN_SUM 0 // version of the eigenvalues of the diffusion matrix using a sum of the local diffusion coefficients 
#define DIFF_MATRIX_EIGEN_MAX 1 // version using the maximum

#define AddSetGetVar( name, type) \
  type  name; \
  void Set##name( type _arg) \
  { \
    this->name = _arg; \
  };  \
  type Get##name() \
  { \
    return this->name; \
  };

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))


#include "func_globalstats.h"
#include "func_imagebasictools.h"

double CubicRoot(double x) {
  if (x==0) return 0;
  if (x>0) return exp(log(x)/3.0);
  if (x<0) return -exp(log(-x)/3.0);
  return 0;
}


#define IncX(I)  ((x<tx-1)?(I+1):I)
#define Inc2X(I) ((x<tx-2)?(I+1):I)
#define DecX(I)  ((x>0)?(I-1):I)

#define IncY(I)  ((y<ty-1)?(I+tx):I)
#define Inc2Y(I) ((y<ty-2)?(I+tx):I)
#define DecY(I)  ((y>0)?(I-tx):I)

#define IncZ(I)  ((z<tz-1)?(I+txy):I)
#define Inc2Z(I) ((z<tz-2)?(I+txy):I)
#define DecZ(I)  ((z>0)?(I-txy):I)


// Solving a 3rd order polynomial equation
// of type a.X^3+b.X^2+c=0
//
void Solve3rdOrder(float _a, float _b, float _c, double w[3], int& nb_solutions) 
//   -------------
{
  double a0,a1,a2;
  double b,c,d2,d;
  //  double w0,w1,w2;
  double p,q;
  double tmp1,tmp2;

  nb_solutions=0;
  
  // solve the _c==0 issue when beta is zero
  if (_c==0) {
    if (fabsf(_a)>1E-5) {
      w[0] = -_b/_a;
      nb_solutions=1;
    }
    return;
  }


  a2 = _b/_a;
  a1 = 0;
  a0 = _c/_a;

  b = a1/3-a2*a2/9;
  c = a0/2-a1*a2/6+a2*a2*a2/27;

  // the equation become
  // w^3+3.b.w+2.c=0
  // with w=X+a2/3

  d2=b*b*b+c*c;
  if (d2>=0) {
    d=sqrt(d2);
    // the mandatory real root is:
    p =   CubicRoot(c+d);
    q = - CubicRoot(c-d);
    w[0] = - (p-q);
    nb_solutions++;
    if (d==0) {
      w[1] = p;
      nb_solutions++;
    }
  }
  else {
    tmp1 = 1.0/3.0*acos(c/sqrt(-b*b*b));
    tmp2 = sqrt(-b);
    w[0] = -2*tmp2*cos(tmp1);
    w[1] = tmp2*(cos(tmp1)+sqrt(3.0)*sin(tmp1));
    w[2] = tmp2*(cos(tmp1)-sqrt(3.0)*sin(tmp1));
    nb_solutions=3;
  }

  // update to the solution of the initial equation
  if (nb_solutions>0) w[0]+=-a2/3.0;
  if (nb_solutions>1) w[1]+=-a2/3.0;
  if (nb_solutions>2) w[2]+=-a2/3.0;

} // Solve3rdOrder()



class AnisoGS {

  DEFINE_CLASS(AnisoGS);

 public:

  //-------  Images
  InrImage* input_image; // original input image
  InrImage* image_entree  ; // copy for processing
  InrImage* image_resultat;
  InrImage* image_lissee  ;
  InrImage* im_tmp        ;
  InrImage* image_c; // coefficients for SRAD type filtering

  InrImage* tensor_xx;
  InrImage* tensor_xy;
  InrImage* tensor_xz;
  InrImage* tensor_yy;
  InrImage* tensor_yz;
  InrImage* tensor_zz;

  InrImage* eigenvect_xp;
  InrImage* eigenvect_yp;
  InrImage* eigenvect_zp;

  AddSetGetVar(dt,float);
  AddSetGetVar(neighborhood,int);


  AddSetGetVar( mask, InrImage*)
 
  InrImage* divFim        ;

  double   planstats_sigma;
  double   dirstats_sigma;

  unsigned char   image_entree_allouee;
  int       boundary_extension_size;
  
  float      alpha_x, gamma_x;
  float*     alpha_y;
  float*     gamma_y;
  float**    alpha_z;
  float**    gamma_z;
  
  
  FiltreRecursif*  filtre;
  FiltrageRec*     filtre_rec;
  DeriveesLissees* DerLiss;
  
  
  //-------- Parameters
  int     mode;
  unsigned char    use_filtre_rec;
  unsigned char    opt_mem;
  float       sigma;

  AddSetGetVar( beta, float)

  int     iteration;
  int     loop, max_loop;
  float       k;
  float       epsilon;
  int     tx,ty,tz,txy;

  int ROI_xmin,ROI_xmax;
  int ROI_ymin,ROI_ymax;
  int ROI_zmin,ROI_zmax;

  //-------- Precomputed pointers to neighborhood
  float* I0;
  float* Ixp;
  float* Ixm;
  float* Iyp;
  float* Iym;
  float* Izp;
  float* Izm;
  float* Ixpxp;
  float* Iypyp;
  float* Izpzp;
  float* Ixpyp;
  float* Ixpym;
  float* Ixmyp;
  float* Ixmym;
  float* Ixpzp;
  float* Ixpzm;
  float* Ixmzp;
  float* Ixmzm;
  float* Iypzp;
  float* Iypzm;
  float* Iymzp;
  float* Iymzm;

  float* Ixpypzp;
  float* Ixpypzm;
  float* Ixpymzp;
  float* Ixpymzm;
  float* Ixmypzp;
  float* Ixmypzm;
  float* Ixmymzp;
  float* Ixmymzm; 
 
  // for structure tensor eigenvectors
  FloatMatrix*     matrice;
  float            vap[3];
  FloatMatrix*     vec_propre;

  AddSetGetVar(tang_coeff, float)

  AddSetGetVar(maxcurv_coeff, float)
  AddSetGetVar(mincurv_coeff, float)

  // noise Gaussian or Speckle, by default Gaussian
  AddSetGetVar(noise_type, int)
  AddSetGetVar(noise_standard_deviation, float)
  unsigned char noise_SD_preset;
  double variance;

  // estimated data attachment coeff
  AddSetGetVar(estimated_DA_coeff,float);
  
  // If true, uses the norm of the smoothed gradient
  // as parameter of the first diffusion function
  // otherwise uses the first order derivative of intensity
  // in the direction of the smoothed gradient.
  AddSetGetVar(SmoothedParam,unsigned char);

  // Computes Euclidian distance maps
  AddSetGetVar(DistanceMap,unsigned char);
  
  // Get the minimal and maximal intensity of the initial image
  // to limit unstabilities
  float min_intensity;
  float max_intensity;

  //  int       contours_mode;
  //  InrImage* SRAD_ROI;

  AddSetGetVar( contours_mode,int);
  AddSetGetVar( SRAD_ROI,     InrImage*);
  AddSetGetVar( local_structure_mode,  int);
  AddSetGetVar( diffusion_eigenvalues_mode,  int);

  AnisoGS()
    {
      InitParam();
    }

  ~AnisoGS()
    {

      DeleteCoefficients();
      
      Si filtre     != NULL Alors
	delete filtre;
        filtre = NULL;
      FinSi
	
      Si filtre_rec != NULL Alors
	delete filtre_rec;
        filtre_rec = NULL;
      FinSi
	
      Si this->image_lissee != NULL Alors
	delete this->image_lissee;
        this->image_lissee=NULL;
      FinSi
	
      Si this->im_tmp != NULL Alors
	delete this->im_tmp;
        this->im_tmp = NULL;
      FinSi
	
      Si this->image_c != NULL Alors
	delete this->image_c;
        this->image_c = NULL;
      FinSi
	
      Si divFim != NULL Alors
	delete divFim;
        divFim = NULL;
      FinSi
	
      Si Non(opt_mem) Et (image_entree_allouee) Alors
	delete image_entree;
        image_entree=NULL;
      FinSi
      mask = NULL;
      
    if (tensor_xx!=NULL) { delete tensor_xx; tensor_xx=NULL; }
    if (tensor_xy!=NULL) { delete tensor_xy; tensor_xy=NULL; }
    if (tensor_xz!=NULL) { delete tensor_xz; tensor_xz=NULL; }
    if (tensor_yy!=NULL) { delete tensor_yy; tensor_yy=NULL; }
    if (tensor_yz!=NULL) { delete tensor_yz; tensor_yz=NULL; }
    if (tensor_zz!=NULL) { delete tensor_zz; tensor_zz=NULL; }

    if (eigenvect_xp!=NULL) { delete eigenvect_xp; eigenvect_xp=NULL; }
    if (eigenvect_yp!=NULL) { delete eigenvect_yp; eigenvect_yp=NULL; }
    if (eigenvect_zp!=NULL) { delete eigenvect_zp; eigenvect_zp=NULL; }

    delete matrice;
    delete vec_propre;

    }

  void InitParam() {
    image_entree  = NULL;
    this->image_resultat= NULL;
    this->image_lissee  = NULL;
    this->im_tmp        = NULL;
    this->image_c       = NULL;
    this->tensor_xx     = NULL;
    this->tensor_xy     = NULL;
    this->tensor_xz     = NULL;
    this->tensor_yy     = NULL;
    this->tensor_yz     = NULL;
    this->tensor_zz     = NULL;
    this->eigenvect_xp  = NULL;
    this->eigenvect_yp  = NULL;
    this->eigenvect_zp  = NULL;
    mask          = NULL;

    this->planstats_sigma = 1.0;
    this->dirstats_sigma  = 1.5;

    divFim        = NULL;

    boundary_extension_size = MAX((int)(2*planstats_sigma+1.5),
                                  (int)(2*dirstats_sigma+1.5));

    matrice    = new FloatMatrix(3,3);
    vec_propre = new FloatMatrix(3,3);

    use_filtre_rec = false;
    opt_mem        = false;

    tang_coeff    = 1.0;
    maxcurv_coeff = 0.0;
    mincurv_coeff = 1.0;

    local_structure_mode       = LOCAL_STRUCT_CURV;
    diffusion_eigenvalues_mode = DIFF_MATRIX_EIGEN_SUM;

    noise_type = GAUSSIAN_NOISE;
    noise_standard_deviation = -1;
    noise_SD_preset=0;
    variance = 0;

    epsilon     = 1E-2;

    SmoothedParam = false;

    filtre_rec = NULL;
    filtre = NULL;

    DistanceMap = 0;

    contours_mode  = CONTOURS_GRAD;
    this->SRAD_ROI = NULL;


    neighborhood = 1;
    dt = 0.05;
  }

  void ExtendBoundariesVonNeumann( InrImage* input);
  void CreateBoundariesVonNeumann( InrImage* input);

  void EstimateNoiseStandardDeviation( InrImage* im);

  void InitCoefficients();
  void ResetCoefficients();
  void DeleteCoefficients();


  double Compute_q0_subvol( InrImage* im);
  double function_c_Kuan(double q_2, double q0_2);
  double function_c_Lee(double q_2, double q0_2);

  double Compute_sigma2_MRI(InrImage* im);
  double Compute_sigma2_MRI_mode(InrImage* im);
  double function_c_MRI(double sigma2, double vg, double meang);

  void Smooth(InrImage* im, float sigma);
  void ComputeStructureTensor(InrImage* im, float sigma1, float sigma2);
  void ComputeEigenVectors();

  void ComputeImage_c(InrImage*);

  float Itere2D(   InrImage* im );
  float Itere3D(   InrImage* im );
  float Itere3D_2( InrImage* im );

  float Itere3D_2_new( InrImage* im );
  float Itere3D_ST_RNRAD( InrImage* im );

  float Itere3D_distance( InrImage* im );
  float Itere3D_distance_flux( InrImage* im );
  float Itere3D_Flux( InrImage* im , InrImage* VectField, float coeff);
  float Itere3D_3( InrImage* im );

  void Init(InrImage* in, float p_sigma, float p_k, float p_beta);

  float Iterate();

  float IterateFlux( InrImage* vect, float coeff);

  void InitFlux( t_3Point& e0,t_3Point& e1,t_3Point& e2);

  // for 2D
  void InitNeighborhood(float* I,int x,int y);
  void Grad2D(float* I,float grad[2]);
  void Grad2DShiftX(float* I, t_3Point& grad);
  void Grad2DShiftY(float* I, t_3Point& grad);

  // for 3D
  void InitNeighborhood(float* I,int x,int y, int z);
  void Grad(float* I,float grad[3]);
  void GradShiftX(float* I,float grad[3]);
  void GradShiftY(float* I,float grad[3]);
  void GradShiftZ(float* I,float grad[3]);
  void Hessian(float* I,float** H);
  void HessianShiftX(float* I,float H[3][3]);
  void HessianShiftY(float* I,float H[3][3]);
  void HessianShiftZ(float* I,float H[3][3]);

  float Norm(float v[3]);
  float ScalarProduct(const t_Gradient v1, const t_3Point v2);

  void PrincipalCurvatures(float grad[3], float H[3][3],  float norm_grad,
                    t_3Point& e0, t_3Point& e1, t_3Point& e2);

  void StructTensor_eigenvectors( int coord, int x, int y, int z, t_3Point& e0, t_3Point& e1, t_3Point& e2);

  unsigned char convert_uchar(double val);
  short         convert_short(double val);
  void GetVectors(int coord, int x, int y, int z, t_3Point& e0, t_3Point& e1, t_3Point& e2);

  // Compute the local  mean and standard deviation within a plan,
  // using a Gaussian of standard deviation sd
  void ComputeLocalPlanStats(InrImage* im, float x, float y, float z, 
    t_3Point d1,t_3Point d2,
    float sd, double& mean, double& var);

  // Compute the local directional mean and standard deviation,
  // using a Gaussian of standard deviation sd
  void ComputeLocalDirStats(InrImage* im, float x, float y, float z, t_3Point e,
    float sd, double& mean, double& var);

}; // end class AnisoGS


static AnisoGS* static_AnisoGS = NULL;


//static float   *in;
//#define phi0(x)         exp(-((x)*(x)/k/k))
#define phi0(x)         exp(-0.5*((x)*(x)/k/k))
#define phi1(x)         tang_coeff

//#define phi3D_0(x) exp(-((x)*(x)/k/k))
//#define phi3D_0(x) exp(-0.5*((x)*(x)/k/k))
//#define phi3D_0(x) 1.0/(x+0.001)
//#define phi3D_0(x) tanh((x)/k)/(x)
#define phi3D_0(x) 1.0/(1.0+(x)*(x)/k/k)


#define phi3D_1(x) maxcurv_coeff
#define phi3D_2(x) mincurv_coeff

#ifndef macro_min
  #define macro_min(n1,n2) ((n1)<(n2)?(n1):(n2))
#endif

#ifndef macro_max
  #define macro_max(n1,n2) ((n1)>(n2)?(n1):(n2))
#endif 


// Extend Boundary Conditions
void AnisoGS::ExtendBoundariesVonNeumann( InrImage* input)
{
  int x,y,z;
  int x1,y1,z1;
  int dx= input->DimX();
  int dy= input->DimY();
  int dz= input->DimZ();
  int bs = boundary_extension_size;

  input->InitBuffer();
  for(z=0;z<dz;z++)
  for(y=0;y<dy;y++)
  for(x=0;x<dx;x++)
  {
    x1=x;y1=y;z1=z;
    if (x<bs)      x1 = bs;
    if (x>dx-1-bs) x1=dx-1-bs;
    if (y<bs)      y1 = bs;
    if (y>dy-1-bs) y1=dy-1-bs;
    // only for 3D images
    if (dz>1) {
      if (z<bs)      z1 = bs;
      if (z>dz-1-bs) z1=dz-1-bs;
    }

    if ((x1!=x)||(y1!=y)||(z1!=z))
      input->FixeValeur((*input)(x1,y1,z1));

    input->IncBuffer();
  }
  input->Sauve("boundary_test.ami.gz");
}

// Compute image_entree
void AnisoGS::CreateBoundariesVonNeumann( InrImage* input)
{
  int ext = 2*boundary_extension_size;
  int bs = boundary_extension_size;
  int new_dimz;
  float new_trz;

  if (input->DimZ()==1) {
    new_dimz = 1;
    new_trz = input->TrZ();
  } else {
    new_dimz = input->DimZ() + ext;
    new_trz = input->TrZ()-1.0*bs*input->VoxSizeZ();
  }

  image_entree = new InrImage(  input->DimX() + ext,
                                input->DimY() + ext,
                                new_dimz,
                                WT_FLOAT, 
                                "input_image.inr.gz");
  image_entree->SetVoxelSize( input->VoxSizeX(),
                                    input->VoxSizeY(),
                                    input->VoxSizeZ());
  image_entree->SetTranslation( input->TrX()-1.0*bs*input->VoxSizeX(),
                                input->TrY()-1.0*bs*input->VoxSizeY(),
                                new_trz);
  image_entree_allouee=true;
  if (input->DimZ()==1) 
    Func_PutImage(image_entree,input,
                  boundary_extension_size,
                  boundary_extension_size,
                  0);
  else
    Func_PutImage(image_entree,input,
                  boundary_extension_size,
                  boundary_extension_size,
                  boundary_extension_size);

  ExtendBoundariesVonNeumann(image_entree);
}


// Compute the local directional mean and standard deviation,
// using a Gaussian of standard deviation sd
void  AnisoGS::ComputeLocalPlanStats(InrImage* im, float x, float y, float z, 
    t_3Point d1,t_3Point d2,
    float sd, double& mean, double& var)
{
//#define MAX_VALUES 100
  // 1. store intensity values
//  double intensities[MAX_VALUES];
//  double Gaussian[MAX_VALUES];

  float p1,p2;

  double fp1x,fp1y,fp1z;
  double fp2x,fp2y,fp2z;

  int px,py,pz;
  int px1,py1,pz1;
//  int i,index=0;
//  double sum_gauss = 0.0,twosd2;
  float p1_step = 1;
  float p2_step = 1;
  float size = 2*sd;
  double mean2,val;
  int nval=0;

//  twosd2 = 2*sd*sd;

  fp2x = x-size*d2.x-size*d1.x+0.5;
  fp2y = y-size*d2.y-size*d1.y+0.5;
  fp2z = z-size*d2.z-size*d1.z+0.5;
  mean  = 0.0;
  mean2 = 0.0;

  for(p2=-size;p2<=size;p2+=p2_step,fp2x+=d2.x,fp2y+=d2.y,fp2z+=d2.z) {
    fp1x = fp2x;
    fp1y = fp2y;
    fp1z = fp2z;
    px1=py1=pz1=-100;
    for(p1=-size;p1<=size;p1+=p1_step,fp1x+=d1.x,fp1y+=d1.y,fp1z+=d1.z) {
        px=(int) fp1x;
        py=(int) fp1y;
        pz=(int) fp1z;
        // don't add twice the same point
        if (((px!=px1)||(py!=py1)||(pz!=pz1))&
            ((px!=(int)(fp1x-d2.x))||(py!=(int)(fp1y-d2.y))||(pz!=(int)(fp1z-d2.z))))
        {
        val = (*im)(px,py,pz);
        mean  += val;
        mean2 += val*val;
        nval++;
        }
      px1 = px;
      py1 = py;
      pz1 = pz;
    }
  }

  if (nval==0) {
    printf("ComputeLocalPlanStats\n at %0.1f %0.1f %0.1f , no point found within the image domain ...\n",x,y,z);
    printf(" d1 %f %f %f d2 %f %f %f \n",d1.x,d1.y,d1.z,d2.x,d2.y,d2.z);
    mean=var=0;
  } else {
    mean  /= nval;
    mean2 /= nval;
    var = mean2-mean*mean;
  }


} // ComputeLocalPlanStats


// Compute the local directional mean and standard deviation,
// using a Gaussian of standard deviation sd
void  AnisoGS::ComputeLocalDirStats(InrImage* im, float x, float y, float z, t_3Point e,
    float sd, double& mean, double& var)
{
//#define MAX_VALUES 100
  // 1. store intensity values
//  double intensities[MAX_VALUES];
//  double Gaussian[MAX_VALUES];

  float p;
  double fpx,fpy,fpz;
  int px,py,pz;
  int px1,py1,pz1;
//  int i,index=0;
//  double sum_gauss = 0.0,twosd2;
  float p_step = 1;
  float size = 2*sd;
  double mean2,val;
  int nval=0;

  px1=py1=pz1=-100;
//  twosd2 = 2*sd*sd;

  fpx = x-size*e.x+0.5;
  fpy = y-size*e.y+0.5;
  fpz = z-size*e.z+0.5;
  mean  = 0.0;
  mean2 = 0.0;

  for(p=-size;p<=size;p+=p_step,fpx+=e.x,fpy+=e.y,fpz+=e.z) {
    px=(int) fpx;
    py=(int) fpy;
    pz=(int) fpz;
    // don't add twice the same point
    if ((px!=px1)||(py!=py1)||(pz!=pz1))
    {
      val = (*im)(px,py,pz);
      mean  += val;
      mean2 += val*val;
      nval++;
    }
    px1 = px;
    py1 = py;
    pz1 = pz;
  }

  if (nval==0) {
    printf("ComputeLocalDirStats\n e= %f %f %f no point found within the image domain ...\n",e.x,e.y,e.z);
    mean=var=0;
  } else {
    mean  /= nval;
    mean2 /= nval;
    var = mean2-mean*mean;
  }

/*
  for(p=-3*sd;p<=3*sd;p+=p_step) {
    px=(int) (0.5+x+p*e.x);
    py=(int) (0.5+y+p*e.y);
    pz=(int) (0.5+z+p*e.z);
    // don't add twice the same point
    if ((px!=px1)||(py!=py1)||(pz!=pz1))
    if (im->CoordOK(px,py,pz)) {
  //    intensities[index] = im->InterpLinIntensite(px,py,pz);
      intensities[index] = (*im)(px,py,pz);
      // for now don't check boundaries since the linear interpolation method can deal with them
      Gaussian[index] = exp(-p*p/(twosd2)); // this could be pre-computed ...
      sum_gauss += Gaussian[index];
      if (index<MAX_VALUES-1)
        index++;
      else {
        fprintf(stderr,"AnisoGS::ComputeLocalDirStats() \t Too many values \n");
        break;
      }
    }
  }

  if (sum_gauss==0) {
    printf("ComputeLocalDirStats\n e= %f %f %f no point found within the image domain ...\n",e.x,e.y,e.z);
  }

  // mean
  mean = 0.0;
  for(i=0;i<index;i++) {
    mean += intensities[i]*Gaussian[i];
  }
  mean /= sum_gauss;

  // variance
  var = 0.0;
  for(i=0;i<index;i++) {
    var += (intensities[i]-mean)*(intensities[i]-mean)*Gaussian[i];
  }
  var /= sum_gauss;
*/ 

} // ComputeLocalDirStats

//----------------------------------------------------------------------
void AnisoGS::EstimateNoiseStandardDeviation( InrImage* im)
//
// Computes the noise standard deviation estimate
// given the current filtered image 'im'
//
{
  InrImage* noise_im;
  double    mean;
  double     d;
  float*    buf;
  int       i,x,y,z;
  int       nb_points;
  int       mask_size;


  noise_im=NULL;
  switch (noise_type) {
  case GAUSSIAN_NOISE: 
    noise_im = (*image_entree)-(*im);
    break;
  case SPECKLE_NOISE:
    noise_im = (*image_entree)-(*im);

    // Divide by sqrt(im)
    im->InitBuffer();
    noise_im->InitBuffer();
    Repeter
      if (im->ValeurBuffer()>1)
	noise_im->FixeValeur(noise_im->ValeurBuffer()/sqrt(im->ValeurBuffer()));
      im->IncBuffer();
    JusquA Non(noise_im->IncBuffer())
    FinRepeter
    break;
  }


  // remove the border from the computation
  if (mask==NULL) {
    buf = (float*) noise_im->Buffer();
    // Computes the mean
    mean = 0;

    i = 0;
    nb_points=0;
    for(z=0;z<tz;z++)
    for(y=0;y<ty;y++)
      for(x=0;x<tx;x++) {
	Si x>0 Et x<tx-1 Et y>0 Et y<ty-1 Et z>0 Et z<tz-1 
	Alors
	  mean += buf[i];
  	  nb_points++;
        FinSi
	i++;
      }

    //for(i=0;i<im->Size();i++) mean += buf[i];
    //mean /= 1.0*im->Size();
    mean /= 1.0*nb_points;

    // Computes the standard deviation
    this->variance = 0;

    i = 0;
    for(z=0;z<tz;z++)
    for(y=0;y<ty;y++)
      for(x=0;x<tx;x++) {
	Si x>0 Et x<tx-1 Et y>0 Et y<ty-1 Et z>0 Et z<tz-1 
	Alors
	  d  = buf[i]-mean;
	  this->variance += d*d;
        FinSi
	i++;
      }
    this->variance /= 1.0*nb_points;

  }
  else {
    buf = (float*) noise_im->Buffer();

    // Computes the mean
    mean = 0;
    mask_size = 0;
    mask->InitBuffer();

    for(i=0;i<im->Size();i++) {
      if (mask->ValeurBuffer()>0.5) {
	mean += buf[i];
	mask_size++;
      }
      mask->IncBuffer();
    }
    mean /= 1.0*mask_size;

    // Computes the standard deviation
    this->variance = 0;
    mask->InitBuffer();

    for(i=0;i<im->Size();i++) {
      if (mask->ValeurBuffer()>0.5) {
	d  = buf[i]-mean;
	this->variance += d*d;
      }
      mask->IncBuffer();
    }

    this->variance /= 1.0*mask_size;

  }

  delete noise_im;

  fprintf(stderr,"Noise mean=%3.3f; VARIANCE=%3.3f; SD=%3.3f \n",
	  mean,this->variance,sqrt(this->variance));  

  // BUG fixed take the square root of the variance!!!
  this->noise_standard_deviation = sqrt(this->variance);

} // AnisoGS::EstimateNoiseStandardDeviation()


//----------------------------------------------------------------------
void AnisoGS::InitCoefficients()
//
{

  
    int x;

  tx = image_entree->_tx;
  ty = image_entree->_ty;
  tz = image_entree->_tz;
  txy = tx*image_entree->_ty;

  alpha_y = new float[tx];
  gamma_y = new float[tx];

  alpha_x = gamma_x = 0;
  Pour(x,0,tx-1)
    alpha_y[x] = gamma_y[x] = 0;
  FinPour

  Si mode == MODE_3D Alors
    int y;

    alpha_z = new float*[tx];
    gamma_z = new float*[tx];
    Pour(x,0,tx-1)
      alpha_z[x] = new float[image_entree->_ty];
      gamma_z[x] = new float[image_entree->_ty];


      Pour(y,0,ty-1)
	alpha_z[x][y] = gamma_z[x][y] = 0;
      FinPour

    FinPour

  FinSi

} // AnisoGS::InitCoefficients()


//----------------------------------------------------------------------
void AnisoGS::ResetCoefficients()
//
{

  
    int x;

  alpha_x = gamma_x = 0;

  Pour(x,0,tx-1)
    alpha_y[x] = gamma_y[x] = 0;
  FinPour

  Si mode == MODE_3D Alors
    int y;

    Pour(x,0,tx-1)
      Pour(y,0,ty-1)
	alpha_z[x][y] = gamma_z[x][y] = 0;
      FinPour
    FinPour

  FinSi
} // AnisoGS::ResetCoefficients()


//----------------------------------------------------------------------
void AnisoGS::DeleteCoefficients()
//
{

  Si alpha_y != NULL Alors

    delete [] alpha_y;
    alpha_y = NULL;
    delete [] gamma_y;
    gamma_y = NULL;

    Si mode == MODE_3D Alors
      int i;

      Pour(i,0,tx-1)
        delete [] alpha_z[i];
        delete [] gamma_z[i];
      FinPour
      delete [] alpha_z;
      delete [] gamma_z;

    FinSi
  FinSi

} // AnisoGS::DeleteCoefficients()


//----------------------------------------------------------------------
void AnisoGS::InitNeighborhood(float* I,int x,int y)
//
{
  //
  // check image limits to avoid problems...
  //

  //printf ("%d %d %d\n",x,y,z );


  this->I0  = I;
  this->Ixp = IncX(I);  
  this->Ixm = DecX(I);

  this->Iyp = IncY(I);
  this->Iym = DecY(I);

  this->Ixpxp = Inc2X(Ixp);
  this->Iypyp = Inc2Y(Iyp);

  this->Ixpyp = IncY(Ixp);
  this->Ixpym = DecY(Ixp);
  this->Ixmyp = IncY(Ixm);
  this->Ixmym = DecY(Ixm);

}


//----------------------------------------------------------------------
// gradient vector at (x,y,z)
//
void AnisoGS::Grad2D(float* I,float grad[2])
//            ----
{
  grad[0] = (*Ixp   -  *Ixm )/2.0;
  grad[1] = (*Iyp   -  *Iym )/2.0;
}

//----------------------------------------------------------------------
// gradient vector at (x+1/2,y,z)
//
void AnisoGS::Grad2DShiftX(float* I,t_3Point& grad)
//            ----------
{
  grad.x = *Ixp   -  *I0;
  grad.y = ((*Ixpyp+*Iyp)  - (*Ixpym+*Iym))/4.0;
}

//----------------------------------------------------------------------
// gradient vector at (x,y+1/2,z)
//
void AnisoGS::Grad2DShiftY(float* I,t_3Point& grad)
//            ----------
{
  grad.x = ((*Ixpyp+*Ixp)  - (*Ixmyp+*Ixm))/4.0;
  grad.y = *Iyp   -  *I0;
}




//----------------------------------------------------------------------
double AnisoGS::Compute_q0_subvol( InrImage* im)
{

  InrImage* subvol;
  InrImage* im2 = this->SRAD_ROI;
  int xmin,xmax,ymin,ymax,zmin,zmax;
  double var;
  double mean;
  double tmp,total;

  if (this->SRAD_ROI==NULL)
    {
      fprintf(stderr,"AnisoGS::Compute_q0_subvol() \t SRAD_ROI==NULL\n");
      return 0.0;
    }

  xmin = (int) ((im2->TrX()-im->TrX())/im2->VoxSizeX()+0.5);
  ymin = (int) ((im2->TrY()-im->TrY())/im2->VoxSizeY()+0.5);
  zmin = (int) ((im2->TrZ()-im->TrZ())/im2->VoxSizeZ()+0.5);
  xmax = (int) ((im2->TrX()-im->TrX())/im2->VoxSizeX()+im2->DimX()-1+0.5);
  ymax = (int) ((im2->TrY()-im->TrY())/im2->VoxSizeY()+im2->DimY()-1+0.5);
  zmax = (int) ((im2->TrZ()-im->TrZ())/im2->VoxSizeZ()+im2->DimZ()-1+0.5);
  subvol = Func_SubImage( im,
			  xmin,ymin,zmin,
			  xmax,ymax,zmax);
  mean   = Func_mean(subvol);

  subvol->InitBuffer();
  total =0;
  do {
    tmp = subvol->ValeurBuffer()-mean;
    total += tmp*tmp;
  }
  while(subvol->IncBuffer());

  printf("mean, total = %f %f \n",mean,total);

  total = total/subvol->Size();
  var=total;

  delete subvol;

  if (mean>0) return var/mean/mean;   else return 0;

} // Compute_q0_subvol


//----------------------------------------------------------------------
double AnisoGS::function_c_Kuan(double q_2, double q0_2)
{
  double tmp;

  if (fabsf(q0_2)<1E-4) return 0;
  if (q_2<1E-4)  q_2 = 1E-4;
  tmp =(1.0+1.0/q_2)/(1.0+1.0/q0_2);
  //  if (tmp>50) tmp = 50;

  double limit=q0_2/4.0;
  limit = (1.0+1.0/limit)/(1.0+1.0/q0_2);
  //  double limit = 1;
  if (tmp>limit) tmp=limit;
  return tmp;
} // function_c_Kuan

//----------------------------------------------------------------------
double AnisoGS::function_c_Lee(double q_2, double q0_2)
{
  double tmp;
  if (fabsf(q0_2)<1E-4) return 0;
  if (q_2<0) q_2 = 0;
  tmp = 1.0/(1.0+(q_2-q0_2)/(q0_2*(1+q0_2)));
  if (tmp>1) tmp=1;
  return tmp;
} // function_c_Lee

//----------------------------------------------------------------------
double AnisoGS::Compute_sigma2_MRI(InrImage* im)
//
{
  InrImage* subvol;
  InrImage* im2 = this->SRAD_ROI;
  int xmin,xmax,ymin,ymax,zmin,zmax;
  double var;
  double mean;
  double tmp,total;

  if (this->SRAD_ROI==NULL)
    {
      fprintf(stderr,"AnisoGS::Compute_sigma2_MRI() \t SRAD_ROI==NULL\n");
      return 0.0;
    }
  xmin = (int) ((im2->TrX()-im->TrX())/im2->VoxSizeX()+0.5);
  ymin = (int) ((im2->TrY()-im->TrY())/im2->VoxSizeY()+0.5);
  zmin = (int) ((im2->TrZ()-im->TrZ())/im2->VoxSizeZ()+0.5);
  xmax = (int) ((im2->TrX()-im->TrX())/im2->VoxSizeX()+im2->DimX()-1+0.5);
  ymax = (int) ((im2->TrY()-im->TrY())/im2->VoxSizeY()+im2->DimY()-1+0.5);
  zmax = (int) ((im2->TrZ()-im->TrZ())/im2->VoxSizeZ()+im2->DimZ()-1+0.5);
  subvol = Func_SubImage( im,
              xmin,ymin,zmin,
              xmax,ymax,zmax);
  
  mean   = Func_mean(subvol);

  subvol->InitBuffer();
  total =0;
  do {
    tmp = subvol->ValeurBuffer()-mean;
    total += tmp*tmp;
  }
  while(subvol->IncBuffer());
  total = total/subvol->Size();
  var=total;

  delete subvol;
 
  if (mean*mean<var) {
    printf("AnisoGS::Compute_sigma2_MRI() mean*mean < var ...\n");
    return mean/2.0;
  } else {
    return (mean-sqrt(mean*mean-var))/2.0;
  }
}

//----------------------------------------------------------------------
double AnisoGS::Compute_sigma2_MRI_mode(InrImage* im)
//
{

  return Func_Compute_sigma2_MRI_mode(im,this->SRAD_ROI);

/*
  InrImage* subvol;
  InrImage* im2 = this->SRAD_ROI;
  int xmin,xmax,ymin,ymax,zmin,zmax;

  if (this->SRAD_ROI==NULL)
    {
      fprintf(stderr,"AnisoGS::Compute_sigma2_MRI_mode() \t SRAD_ROI==NULL\n");
      return 0.0;
    }
  xmin = (int) (im->SpaceToVoxelX(im2->SpacePosX(0))+0.5);
  ymin = (int) (im->SpaceToVoxelY(im2->SpacePosY(0))+0.5);
  zmin = (int) (im->SpaceToVoxelZ(im2->SpacePosZ(0))+0.5);
  xmax = (int) (im->SpaceToVoxelX(im2->SpacePosX(im2->DimX()-1))+0.5);
  ymax = (int) (im->SpaceToVoxelY(im2->SpacePosY(im2->DimY()-1))+0.5);
  zmax = (int) (im->SpaceToVoxelZ(im2->SpacePosZ(im2->DimZ()-1))+0.5);
  subvol = Func_SubImage( im, xmin,ymin,zmin, xmax,ymax,zmax);

//----------------------------------------------------------
  InrImage* im1;
  InrImage* im1_mean;
  InrImage* im1_var;
  double mean,std;
  double tmp,total;
  int neigh_size;

  // compute square root of image
  im1 = new InrImage(WT_FLOAT,"im1.ami.gz",subvol);
  im1->InitBuffer();
  subvol->InitBuffer();
  do {
    tmp = subvol->ValeurBuffer();
    if (tmp<0) tmp = 0.01;
    im1->FixeValeur(sqrt(tmp));
    subvol->IncBuffer();
  }
  while(im1->IncBuffer());

  delete subvol;
  
  neigh_size=2;

  im1_mean = Func_localmean2(im1,neigh_size);
  // unbiased version
  im1_var  = Func_localSD2(im1,im1_mean,neigh_size,1);


//  mean   = Func_mean(im1);
//  printf("mean(im1) %f   \n",mean);
//  mean   = Func_mean(im1_mean);
//  printf("mean(local mean) %f   \n",mean);
  mean   = Func_mean(im1_var);
//  printf("mean(local var) %f   \n",mean);

  im1_var->InitBuffer();
  total =0;
  do {
    tmp = im1_var->ValeurBuffer()-mean;
    total += tmp*tmp;
  }
  while(im1_var->IncBuffer());
  total = total/im1_var->Size();
  std=sqrt(total);

//  printf("mean %f std %f  \n",mean,std);

  // histogram of values between mean +/- 2*std
  double hist_min = 0;
  double hist_max = mean+2*std;
  int hist_size = (int)((hist_max-hist_min+1.0)*5.0);

  InrImage* im_hist = Func_Histogram(im1_var,hist_min,hist_max,hist_size);


  int maxpos = 0;
  int val,valmax = 0;
  int pos=0;

  im_hist->InitBuffer();
  do {
    val= (int) im_hist->ValeurBuffer();
    if (val>valmax) {
        valmax = val;
        maxpos = pos;
    }
    pos++;
  }
  while(im_hist->IncBuffer());

  delete im1;
  delete im1_mean;
  delete im1_var;
  delete im_hist;

//  return (hist_min+maxpos*hist_step);
  float sigma_max = im_hist->SpacePosX(maxpos);
  return sigma_max*sigma_max;
*/
}

//----------------------------------------------------------------------
double AnisoGS::function_c_MRI(double sigma2, double vg, double meang)
{
  double tmp;
  if (fabsf(vg)<1E-4) return 0.0;
  if (meang<=sigma2) return 0.0;
  tmp =4.0*sigma2*(meang-sigma2)/vg;

  return tmp;
} // function_c_MRI

//----------------------------------------------------------------------
void AnisoGS::ComputeImage_c(InrImage* im)
//            --------------
{
   
    int x,y,z; //,n,i;
    double I,Ixm,Iym,Izm,Ixp,Iyp,Izp,mean1,mean2,q0_2=0.0,q2;
    double sigma2=0.0;


#define MODE_LEE       0
#define MODE_KUAN      1
#define MODE_ADDITIVE  2
#define MODE_MRI       3
#define MODE_MRI_NEW   4

  int mode = MODE_KUAN;

//  printf("AnisoGS::ComputeImage_c() \t contour mode = %d \n",this->contours_mode);
  switch(this->contours_mode) {
    case CONTOURS_SRAD:       mode = MODE_KUAN; break;
    case CONTOURS_RNRAD:      mode = MODE_MRI;  break;
    case CONTOURS_RNRAD_NEW:  mode = MODE_MRI;  break;
  }

  if ((this->contours_mode==CONTOURS_SRAD)||
      (this->contours_mode==CONTOURS_RNRAD)||
      (this->contours_mode==CONTOURS_RNRAD_NEW)) {

    Si this->image_c == NULL AlorsFait
      this->image_c = new InrImage(WT_FLOAT, "image_c.ami.gz", im);

    // we limit for the moment to Kuan's function with Yu's neighborhood

    // precompute image of coefficients
    switch (mode) {
      case MODE_LEE:
      case MODE_KUAN:
      case MODE_ADDITIVE:
        q0_2= Compute_q0_subvol(im);
        printf("q0_2 = %f \n",q0_2);
        break;
      case MODE_MRI:
/*        sigma2 = Compute_sigma2_MRI(im);
        printf("sigma = %f \n",sqrt(sigma2));
*/
        sigma2 = Compute_sigma2_MRI_mode(im);
        printf("noise SD = %3.2f \t",sqrt(sigma2));
        break;
    }
    
    // Precompute mean of I and mean of I^2
    InrImage* image_mean_I  = NULL;
    InrImage* image_I2      = NULL;
    InrImage* image_mean_I2 = NULL;


    image_mean_I  = Func_localmean2(im,neighborhood);
    image_I2 = (*im)*(*im);
    image_mean_I2 = Func_localmean2(image_I2, neighborhood); 
    delete image_I2; image_I2= NULL;

    // 1. Compute c
    for (z=0;z<tz;z++) {
      for (y=0;y<ty;y++) {
	for (x=0;x<tx;x++) {
	  I = (*im)(x,y,z);
	  if (fabsf(I)<1) I=1;
	  if (x>0)     Ixm = (*im)(x-1,y,z); else Ixm = I;
	  if (y>0)     Iym = (*im)(x,y-1,z); else Iym = I;
	  if (z>0)     Izm = (*im)(x,y,z-1); else Izm = I;
	  
	  if (x<tx-1)  Ixp = (*im)(x+1,y,z); else Ixp = I;
	  if (y<ty-1)  Iyp = (*im)(x,y+1,z); else Iyp = I;
	  if (z<tz-1)  Izp = (*im)(x,y,z+1); else Izp = I;
	  
	  // other (simpler version of q2):
	  switch (neighborhood) {
	  case 0: 
	    mean1 = Ixm+Ixp+Iym+Iyp;
	    mean2 = Ixm*Ixm+Ixp*Ixp+Iym*Iym+Iyp*Iyp;
	    if (tz==1) {
	      mean1/=4.0;
	      mean2/=4.0;
	    }
	    else {
	      mean1+=Izm+Izp;
	      mean2+=Izm*Izm+Izp*Izp;
	      mean1/=6.0;
	      mean2/=6.0;
	    }
	    break;
/*
	    //mean1 = (Ixm+Ixp+Iym+Iyp)/4.0;
	    //mean2 = (Ixm*Ixm+Ixp*Ixp+Iym*Iym+Iyp*Iyp)/4.0;
	    // adding the central point for stability
	    mean1 = (Ixm+Ixp+Iym+Iyp+I)/5.0;
	    mean2 = (Ixm*Ixm+Ixp*Ixp+Iym*Iym+Iyp*Iyp+I*I)/5.0;
*/
	    break;
	  default:
	    mean1 = (*image_mean_I) (x,y,z);
	    mean2 = (*image_mean_I2)(x,y,z);
	  }

	  if (fabsf(mean1)>1E-6) 
	    q2    = mean2/(mean1*mean1)-1;
	  else q2 = 0;
	  
	  image_c->BufferPos(x,y,z);
	  switch (mode) {
	  case MODE_LEE:  image_c->FixeValeur( function_c_Lee(     q2,               q0_2)); break;
	  case MODE_KUAN: image_c->FixeValeur( function_c_Kuan(    q2,               q0_2)); break;
	    //	  case MODE_ADDITIVE: image_c->FixeValeur( function_c_additive(mean2-mean1*mean1,q0_2)); break;
      case MODE_MRI: image_c->FixeValeur( function_c_MRI( sigma2, mean2-mean1*mean1, mean1));
        break;
	  }
	}
      }
    } // for z

    if (neighborhood>0) {
      delete image_mean_I;  image_mean_I  = NULL;
      delete image_mean_I2; image_mean_I2 = NULL;
    }

  } //
  else
    CLASS_ERROR("contours_mode mode supported");
//  image_c->Sauve();

}

//----------------------------------------------------------------------------------
void AnisoGS::Smooth(InrImage* image, float sigma)
{
    FiltreRecursif* filtre;

  filtre = new FiltreRecursif(image, MODE_3D);
//  filtre->SetScaleUnit(PIXEL_SPACE);
  filtre->Utilise_Image(   true);
  filtre->UtiliseGradient( false);
  filtre->InitDerivees();
  filtre->FixeFacteurSupport(4);

  filtre->GammaNormalise(  true);

  filtre->InitFiltre( sigma, MY_FILTRE_CONV);
  filtre->CalculFiltres();
  (*image) = (*(*filtre)(IM_sigma));
  delete filtre;
}

//----------------------------------------------------------------------------------
void AnisoGS::ComputeStructureTensor(InrImage* im, float sigma1, float sigma2)
{

printf("sig1 %f sig2 %f \n",sigma1,sigma2);
  if (im->_tz == 1)
  {
    fprintf(stderr, "structure tensor not yet available in 2D ! \n");
    return;
  }


    FloatMatrix     matrice(3,3);
    FloatMatrix     matriceinit(3,3);
//    float           vap[3];
    FloatMatrix     vec_propre(3,3);
    int          x,y,z;
//    unsigned char         Diagonale = false;
    Vect3D<double>  grad;
//    int             niter;
    InrImage*       image;
    FiltreRecursif* filtre;
//    char            resname[100];

  double tmp;
  if (contours_mode==CONTOURS_RNRAD_NEW) {
    // compute on the square root of the intensity
    image = new InrImage( WT_FLOAT, "sqrt_im", im);
    image->InitBuffer();
    im->InitBuffer();
    do {
      tmp = im->ValeurBuffer();
      tmp = (tmp>0?tmp:0);
      image->FixeValeur(sqrt(tmp));
      im->IncBuffer();
    } while (image->IncBuffer());
  } else 
  {
    Si (im->_format == WT_FLOAT) Alors
      image = im;
    Sinon
      // conversion de l'image initiale en float
      image    = new InrImage( WT_FLOAT, "image_reel.inr.gz", im);
      (*image) = (*im);
    FinSi
  }

  if (tensor_xx==NULL) tensor_xx =  new InrImage( WT_FLOAT, "Tensor_xx", image);
  if (tensor_xy==NULL) tensor_xy =  new InrImage( WT_FLOAT, "Tensor_xy", image);
  if (tensor_xz==NULL) tensor_xz =  new InrImage( WT_FLOAT, "Tensor_xz", image);
  if (tensor_yy==NULL) tensor_yy =  new InrImage( WT_FLOAT, "Tensor_yy", image);
  if (tensor_yz==NULL) tensor_yz =  new InrImage( WT_FLOAT, "Tensor_yz", image);
  if (tensor_zz==NULL) tensor_zz =  new InrImage( WT_FLOAT, "Tensor_zz", image);


  // Initialisation des images des d�riv�es 
  filtre = new FiltreRecursif(image, MODE_3D);
//  filtre->SetScaleUnit(PIXEL_SPACE);
  filtre->Utilise_Image(   false);
  filtre->UtiliseGradient( true);
  filtre->InitDerivees();
  filtre->GammaNormalise( true);
  filtre->FixeFacteurSupport(5);
  filtre->InitFiltre( sigma1, MY_FILTRE_CONV);  
  filtre->CalculFiltres( );

  // Calcul des coefficients du tenseur non liss�

  tensor_xx->InitBuffer();
  tensor_xy->InitBuffer();
  tensor_xz->InitBuffer();
  tensor_yy->InitBuffer();
  tensor_yz->InitBuffer();
  tensor_zz->InitBuffer();

  Pour( z, 0, image->_tz - 1)
  Pour( y, 0, image->_ty - 1)
  Pour( x, 0, image->_tx - 1)

    grad = filtre->Gradient(x,y,z);
    tensor_xx->FixeValeur( grad.x*grad.x);
    tensor_xy->FixeValeur( grad.x*grad.y);
    tensor_xz->FixeValeur( grad.x*grad.z);
    tensor_yy->FixeValeur( grad.y*grad.y);
    tensor_yz->FixeValeur( grad.y*grad.z);
    tensor_zz->FixeValeur( grad.z*grad.z);

    tensor_xx->IncBuffer();
    tensor_xy->IncBuffer();
    tensor_xz->IncBuffer();
    tensor_yy->IncBuffer();
    tensor_yz->IncBuffer();
    tensor_zz->IncBuffer();

  FinPour
  FinPour
  FinPour

  delete filtre;

  // Lissage du tenseur
  // Pas optimise...
  Smooth( tensor_xx, sigma2);
  Smooth( tensor_xy, sigma2);
  Smooth( tensor_xz, sigma2);
  Smooth( tensor_yy, sigma2);
  Smooth( tensor_yz, sigma2);
  Smooth( tensor_zz, sigma2);


  if (image!=im) delete image;


} // ComputeStructureTensor()




//----------------------------------------------------------------------------------
void AnisoGS::ComputeEigenVectors()
{
  int x,y,z;
  t_3Point e0, e1, e2;

  if (eigenvect_xp==NULL) 
    eigenvect_xp =  new InrImage( image_entree->DimX(),
                                      image_entree->DimY(),
                                      image_entree->DimZ(),
                                      6, // for e1 and e2
                                      WT_SIGNED_SHORT,
                                      "Eigenvect_xp.ami.gz");
  if (eigenvect_yp==NULL) 
    eigenvect_yp =  new InrImage(   image_entree->DimX(),
                                    image_entree->DimY(),
                                    image_entree->DimZ(),
                                     6, // for e1 and e2
                                      WT_SIGNED_SHORT,
                                      "Eigenvect_yp.ami.gz");
  if (eigenvect_zp==NULL) 
    eigenvect_zp =  new InrImage( image_entree->DimX(),
                                      image_entree->DimY(),
                                      image_entree->DimZ(),
                                      6, // for e1 and e2
                                      WT_SIGNED_SHORT,
                                      "Eigenvect_zp.ami.gz");

  printf("Pre-Computing eigenvectors \n");
  for(z=ROI_zmin;z<=ROI_zmax;z++)
  for(y=ROI_ymin;y<=ROI_ymax;y++)
  for(x=ROI_xmin;x<=ROI_xmax;x++) {

    // theta in ]-pi/2,pi/2]
    // phi in ]-pi/2,pi/2]
    // x = cos(theta)*cos(phi)
    // y = cos(theta)*sin(phi)
    // z = sin(theta)

    // x+0.5dx,y,z
    this->StructTensor_eigenvectors(0,x,y,z,e0,e1,e2);

    // e1
    eigenvect_xp->BufferPos(x,y,z);
    eigenvect_xp->VectFixeValeur(0,convert_short(e1.x));
    eigenvect_xp->VectFixeValeur(1,convert_short(e1.y));
    eigenvect_xp->VectFixeValeur(2,convert_short(e1.z));
    eigenvect_xp->VectFixeValeur(3,convert_short(e2.x));
    eigenvect_xp->VectFixeValeur(4,convert_short(e2.y));
    eigenvect_xp->VectFixeValeur(5,convert_short(e2.z));

    // x,y+0.5dy,z
    this->StructTensor_eigenvectors(1,x,y,z,e0,e1,e2);

    eigenvect_yp->BufferPos(x,y,z);
    eigenvect_yp->VectFixeValeur(0,convert_short(e1.x));
    eigenvect_yp->VectFixeValeur(1,convert_short(e1.y));
    eigenvect_yp->VectFixeValeur(2,convert_short(e1.z));
    eigenvect_yp->VectFixeValeur(3,convert_short(e2.x));
    eigenvect_yp->VectFixeValeur(4,convert_short(e2.y));
    eigenvect_yp->VectFixeValeur(5,convert_short(e2.z));


    this->StructTensor_eigenvectors(2,x,y,z,e0,e1,e2);

    eigenvect_zp->BufferPos(x,y,z);
    eigenvect_zp->VectFixeValeur(0,convert_short(e1.x));
    eigenvect_zp->VectFixeValeur(1,convert_short(e1.y));
    eigenvect_zp->VectFixeValeur(2,convert_short(e1.z));
    eigenvect_zp->VectFixeValeur(3,convert_short(e2.x));
    eigenvect_zp->VectFixeValeur(4,convert_short(e2.y));
    eigenvect_zp->VectFixeValeur(5,convert_short(e2.z));


  } // for z,y,z
  printf("done \n");
/*
eigenvect_xp->Sauve();
eigenvect_yp->Sauve();
eigenvect_zp->Sauve();
*/
}


//----------------------------------------------------------------------
float AnisoGS::Itere2D ( InrImage* im )
//
{


  int x,y,z; //,n,i;
  float   val0,val1;
  float  val1_implicit=0;
  float   val1div;
  float   u_e0;
  float   u_e1;
  float   alpha1_x, gamma1_x;
  float   alpha1_y, gamma1_y;
  float*  in;
  register float    *Iconv;
//    float gradient[2];
//    float hessien[2][2];

  t_3Point e0;
  t_3Point e1;
  float     norm;

  t_Gradient grad;

  float   erreur; //,norm_grad;
  int nb_points_instables;
  int erreur_x=0,erreur_y=0,erreur_z=0;

  double   phi0_value=0;

  float     sum_divF;
  long int  nb_calculated_points;
  float     u,u0;
  float     divF;
//    char      divFname[100];

  unsigned char mask_test;


  ComputeImage_c ( im );

  ResetCoefficients();
  Si this->im_tmp == NULL AlorsFait
  this->im_tmp = new InrImage ( WT_FLOAT, "im_tmp.inr.gz", im );

  im->InitBuffer();


  erreur = 0;

  nb_points_instables = 0;

  in = ( float* ) im->Buffer();

  Si use_filtre_rec Alors
  ( *this->image_lissee ) = ( *im );
  filtre_rec->Filtre ( sigma,5 );
  Sinon
  printf ( "MyFiltre \n" );
  filtre->MyFiltre ( im,           this->image_lissee, 0, -1, -1 );
  filtre->MyFiltre ( this->image_lissee, this->image_lissee, -1, 0, -1 );
  FinSi

  Iconv = ( float* ) this->image_lissee->Buffer();

  nb_calculated_points = 0;
  sum_divF = 0;

  printf ( "beta = %f\n",beta );

  Pour ( z,0,im->_tz-1 )
  Pour ( y,0,im->_ty-1 )
  Pour ( x,0,im->_tx-1 )


  val0 = *in;
  mask_test = ( mask==NULL ) || ( ( mask!=NULL ) && ( ( *mask ) ( x,y,z ) >0.5 ) );

  if (x>0 Et x<tx-1 Et y>0 Et y<ty-1) {

  InitNeighborhood ( Iconv,x,y,z );

  // Gradient en (x+1/2,y)
  //----- Calcul de alpha1_x, gamma1_x
  grad.x = * ( in+1 ) - * ( in );
  grad.y = ( * ( in + tx ) - * ( in - tx ) + * ( in+tx+1 ) - * ( in-tx+1 ) ) / 4.0;

  // Calcul du gradient (x+1/2,y)
  this->Grad2DShiftX ( Iconv,e0 );


  norm = sqrt ( e0.x*e0.x+e0.y*e0.y );
  if (norm > 1E-5) {
  e0.x /= norm;
  e0.y /= norm;
  } else {
  e0.x = 1.0;
  e0.y = 0;
  }
  e1.x = -e0.y;
  e1.y = e0.x;

  // Derivees directionnelles
  u_e0 = grad.x*e0.x + grad.y*e0.y;
  u_e1 = grad.x*e1.x + grad.y*e1.y;

  if ( ( x== ( int ) ( im->_tx/2 ) ) && ( y== ( int ) ( im->_ty/2 ) ) )
  {
    printf ( " x+, e0 %f %f e1 %f %f \n",e0.x,e0.y,e1.x,e1.y );
  }

  switch ( contours_mode )
  {
    case CONTOURS_GRAD:
      Si SmoothedParam Alors
      phi0_value = phi0 ( norm );
      Sinon
      phi0_value = phi0 ( u_e0 );
      FinSi
      break;
    case CONTOURS_SRAD:
    case CONTOURS_RNRAD:
      phi0_value = ( ( *image_c ) ( x,y,z ) + ( *image_c ) ( x+1,y,z ) ) /2.0;
  }

  if ( ( x== ( int ) ( im->_tx/2 ) ) && ( y== ( int ) ( im->_ty/2 ) ) )
  {
    printf ( " x+, phi0 %f phi1 %f \n",phi0_value,phi1 ( u_e1 ) );
  }
  alpha1_x = phi0_value*e0.x*e0.x +
             phi1 ( u_e1 ) *e1.x*e1.x;

  gamma1_x  = grad.y* ( e0.y*phi0_value*e0.x +
                        e1.y*phi1 ( u_e1 ) *e1.x );

  //----- Calcul de alpha1_y, gamma1_y
  //
  // Gradient en (x,y+1/2)
  //
  grad.x = ( * ( in   +1 )-* ( in   -1 ) +* ( in   +1+tx )-* ( in   -1+tx ) ) /4.0;
  grad.y = * ( in   +tx ) - * ( in );

  this->Grad2DShiftY ( Iconv,e0 );

  // Calcul de e0, e1

  norm = sqrt ( e0.x*e0.x+e0.y*e0.y );
  Si norm > 1E-5 Alors
  e0.x /= norm;
  e0.y /= norm;
  Sinon
  e0.x = 1.0;
  e0.y = 0.0;
  FinSi

  e1.x = -e0.y;
  e1.y = e0.x;

  // Derivees directionnelles
  u_e0 = grad.x*e0.x + grad.y*e0.y;
  u_e1 = grad.x*e1.x + grad.y*e1.y;

  switch ( contours_mode )
  {
    case CONTOURS_GRAD:
      Si SmoothedParam Alors
      phi0_value = phi0 ( norm );
      Sinon
      phi0_value = phi0 ( u_e0 );
      FinSi
      break;
    case CONTOURS_SRAD:
    case CONTOURS_RNRAD:
      phi0_value = ( ( *image_c ) ( x,y,z ) + ( *image_c ) ( x,y+1,z ) ) /2.0;
  }

  alpha1_y = phi0_value*e0.y*e0.y +
             phi1 ( u_e1 ) *e1.y*e1.y;

  gamma1_y = grad.x*e0.x*phi0_value*e0.y +
             grad.x*e1.x*phi1 ( u_e1 ) *e1.y;

  //----- Mise a jour de l'image

  val1    = 0;
  val1div = 0;


  val1 += alpha1_x  * ( * ( in+1 ) ) +
          alpha_x   * ( * ( in-1 ) ) +
          gamma1_x  - gamma_x;

  val1div += alpha1_x + alpha_x;

  val1 += alpha1_y  * ( * ( in+tx ) ) +
          alpha_y [x]  * ( * ( in-tx ) ) +
          gamma1_y  - gamma_y[x];

  val1div += alpha1_y + alpha_y[x];

  switch ( noise_type )
  {
    case GAUSSIAN_NOISE:
      if ( mask_test )
      {
        divF = ( val1 - *in * val1div ) * ( *in- ( *image_entree ) ( x,y,z ) );
        sum_divF += divF;
        nb_calculated_points++;
      }

      val1    += this->beta* ( *image_entree ) ( x,y,z );
      val1div += this->beta;

      switch ( contours_mode )
      {
        case CONTOURS_GRAD:
          Si fabsf ( val1div ) >1E-4 Alors
          val1 /= val1div;
          Sinon
          fprintf ( stderr,"AnisoGaussSeidel.c:Itere3D() \t fabsf(val1div)<1E-4 \n" );
          FinSi
          break;
        case CONTOURS_SRAD:
        case CONTOURS_RNRAD:
          /*    Si fabsf(val1div)>1E-4 Alors
              val1 /= val1div;
            Sinon
              fprintf(stderr,"AnisoGaussSeidel.c:Itere3D() \t fabsf(val1div)<1E-4 \n");
            FinSi
          */
          val1 = ( *in + dt*val1 ) / ( 1+dt*val1div );
          break;
      }
      break;

    case SPECKLE_NOISE:
      u0 = ( *image_entree ) ( x,y,z );
      u  = *in;

      if ( mask_test&& ( fabsf ( u+u0 ) >1E-4 ) && ( u>1 ) && ( u0>1 ) )
      {
        divF = ( val1 - u * val1div ) * ( u-u0 ) / ( u+u0 ) *u;
        sum_divF += divF;
        nb_calculated_points++;
      }

      if ( ( u>1 ) && ( u0>1 ) )
      {
        //
        // See if we can get a more implicit scheme
        // by solving a 3rd order equation:
        //
#ifdef IMPLICIT
        double w[3];
        int nb_solutions;
        Solve3rdOrder ( val1div,- ( val1-this->beta ),
                        -this->beta* ( u0*u0 ),w,nb_solutions );
        if ( nb_solutions==1 )
          val1_implicit = w[0];
        else
        {
          //printf(" 3rd order equation %d solutions %3.2f %3.2f %3.2f \n",
          //   nb_solutions,w[0],w[1],w[2]);
          if ( w[0]>0 ) val1_implicit = w[0];
          else
            if ( w[1]>0 ) val1_implicit = w[1];
            else
              if ( w[2]>0 ) val1_implicit = w[2];
        }
        val1=val1_implicit;
#else
        val1  += beta* ( ( u0*u0 ) / ( u*u )-1 );

        Si fabsf ( val1div ) >1E-4 Alors
        val1 /= val1div;
        Sinon
        fprintf ( stderr,"AnisoGaussSeidel.c:Itere3D() \t fabsf(val1div)<1E-4 \n" );
        FinSi
        break;
      }

#endif
      }

      break;
  }

  alpha_y[x] = alpha1_y;
  alpha_x    = alpha1_x;

  gamma_y[x] = gamma1_y;
  gamma_x    = gamma1_x;


  Si fabsf ( val1-val0 ) > epsilon Alors
  nb_points_instables++;
  FinSi

  Si fabsf ( val1-val0 ) > erreur Alors
  erreur = fabsf ( val1-val0 );
  erreur_x = x;
  erreur_y = y;
  erreur_z = z;
  FinSi

  this->im_tmp->BufferPos ( x,y,z );
  this->im_tmp->FixeValeur ( val1 );
  }
  else {
    alpha_y[x] = 0;
    alpha_x    = 0;
    gamma_y[x] = 0;
    gamma_x    = 0;
    this->im_tmp->BufferPos ( x,y,z );
    this->im_tmp->FixeValeur ( (*image_entree)(x,y,z) );
  }

  in++;
  Iconv++;

  FinPour
  FinPour
  FinPour


  ( *im ) = ( *this->im_tmp );

  cout << endl;
  cout << " Erreur = " << erreur << endl;
  cout << "( " << erreur_x << ", "
  << erreur_y << ", "
  << erreur_z << " )" << endl;
  cout << "nb de points variables " << nb_points_instables << endl;



  if ( noise_standard_deviation <0 )
  {
    /*    fprintf(stderr,"noise SD <0 ?\n");
        estimated_DA_coeff = sum_divF/(1.0*nb_calculated_points);
        fprintf(stderr,"lambda estimation for noise/sigma_noise^2 = %f \n",
          estimated_DA_coeff);
    */
  }
  else
  {
    estimated_DA_coeff =sum_divF/ ( 1.0*nb_calculated_points ) /this->variance;
    fprintf ( stderr,"sum_divF=%3.2f, nb_calculated_points = %5d, variance = %3.3f, \n ===  lambda estimation for noise = %f \n",
              sum_divF, ( int ) nb_calculated_points,this->variance, estimated_DA_coeff );
    if ( ( noise_SD_preset ) && ( estimated_DA_coeff>0 ) )
      this->beta = estimated_DA_coeff;
    fprintf ( stderr, "\n -- Setting beta to %2.2f \n\n",beta );
  }



  return erreur;

} // AnisoGS::Itere2D()


//----------------------------------------------------------------------
void AnisoGS::InitFlux( t_3Point& e0,t_3Point& e1,t_3Point& e2)
//            --------
{
      e0.x = 1; e0.y = 0; e0.z = 0;
      e1.x = 0; e1.y = 1; e1.z = 0;
      e2.x = 0; e2.y = 0; e2.z = 1;

} // InitFlux()


//----------------------------------------------------------------------
void AnisoGS::InitNeighborhood(float* I,int x,int y, int z)
//
{
  //
  // check image limits to avoid problems...
  //

  //printf ("%d %d %d\n",x,y,z );


  I0  = I;
  Ixp = IncX(I);  
  Ixm = DecX(I);

  Iyp = IncY(I);
  Iym = DecY(I);

  Izp = IncZ(I);
  Izm = DecZ(I);

  Ixpxp = Inc2X(Ixp);
  Iypyp = Inc2Y(Iyp);
  Izpzp = Inc2Z(Izp);

  Ixpyp = IncY(Ixp);
  Ixpym = DecY(Ixp);
  Ixmyp = IncY(Ixm);
  Ixmym = DecY(Ixm);
  Ixpzp = IncZ(Ixp);
  Ixpzm = DecZ(Ixp);
  Ixmzp = IncZ(Ixm);
  Ixmzm = DecZ(Ixm);

  Iypzp = IncZ(Iyp);
  Iypzm = DecZ(Iyp);
  Iymzp = IncZ(Iym);
  Iymzm = DecZ(Iym);

  Ixpypzm = DecZ(Ixpyp);
  Ixpypzp = IncZ(Ixpyp);
  Ixpymzm = DecZ(Ixpym);
  Ixpymzp = IncZ(Ixpym);
  Ixmypzm = DecZ(Ixmyp);
  Ixmypzp = IncZ(Ixmyp);
  Ixmymzm = DecZ(Ixmym);
  Ixmymzp = IncZ(Ixmym);
}



//----------------------------------------------------------------------
// gradient vector at (x,y,z)
//
void AnisoGS::Grad(float* I,float grad[3])
//            ----
{
  grad[0] = (*Ixp   -  *Ixm )/2.0;
  grad[1] = (*Iyp   -  *Iym )/2.0;
  grad[2] = (*Izp   -  *Izm )/2.0;
}

//----------------------------------------------------------------------
// gradient vector at (x+1/2,y,z)
//
void AnisoGS::GradShiftX(float* I,float grad[3])
//            ----------
{
  grad[0] = *Ixp   -  *I0;
  grad[1] = ((*Ixpyp+*Iyp)  - (*Ixpym+*Iym))/4.0;
  grad[2] = ((*Ixpzp+*Izp)  - (*Ixpzm+*Izm))/4.0;
}

//----------------------------------------------------------------------
// gradient vector at (x,y+1/2,z)
//
void AnisoGS::GradShiftY(float* I,float grad[3])
//            ----------
{
  grad[0] = ((*Ixpyp+*Ixp)  - (*Ixmyp+*Ixm))/4.0;
  grad[1] = *Iyp   -  *I0;
  grad[2] = ((*Iypzp+*Izp)  - (*Iypzm+*Izm))/4.0;
}

//----------------------------------------------------------------------
// gradient vector at (x,y,z+1/2)
//
void AnisoGS::GradShiftZ(float* I,float grad[3])
//            ----------
{
  grad[0] = ((*Ixpzp+*Ixp)  - (*Ixmzp+*Ixm))/4.0;
  grad[1] = ((*Iypzp+*Iyp)  - (*Iymzp+*Iym))/4.0;
  grad[2] = *Izp   -  *I0;
}

//----------------------------------------------------------------------
// Hessian Matrix at (x,y,z)
//
void AnisoGS::Hessian(float* I,float** H)
//            -------
{
  H[0][0] = (*Ixp - 2*(*I0) + *Ixm);
  H[1][1] = (*Iyp - 2*(*I0) + *Iym);
  H[2][2] = (*Izp - 2*(*I0) + *Izm);
  H[1][0] = H[0][1] = ((*Ixpyp - *Ixmyp) - (*Ixpym - *Ixmym))/4.0;
  H[2][0] = H[0][2] = ((*Ixpzp - *Ixmzp) - (*Ixpzm - *Ixmzm))/4.0;
  H[2][1] = H[1][2] = ((*Iypzp - *Iymzp) - (*Iypzm - *Iymzm))/4.0;
}


//----------------------------------------------------------------------
// Hessian Matrix at (x+1/2,y,z)
//
void AnisoGS::HessianShiftX(float* I,float H[3][3])
//            -------------
{
  H[0][0] = ((*Ixpxp-*I0)-(*Ixp-*Ixm))/2.0;
  H[1][0] = H[0][1] = ((*Ixpyp-*Iyp)-(*Ixpym-*Iym))/2.0;
  H[2][0] = H[0][2] = ((*Ixpzp-*Izp)-(*Ixpzm-*Izm))/2.0;
  H[1][1] = ((*Iyp  -2*(*I0) +*Iym  ) +
	     (*Ixpyp-2*(*Ixp)+*Ixpym) )/2.0;
  H[2][1] = 
  H[1][2] = ( (*Iypzp-*Iymzp)-
	      (*Iypzm-*Iymzm)+
	      (*Ixpypzp-*Ixpymzp)-
	      (*Ixpypzm-*Ixpymzm))/8.0;
  H[2][2] = ( *Izp  -2*(*I0) + *Izm  +
	      *Ixpzp-2*(*Ixp)+ *Ixpzm)/2.0;

}

//----------------------------------------------------------------------
// Hessian Matrix at (x,y+1/2,z)
//
void AnisoGS::HessianShiftY(float* I,float H[3][3])
//            -------------
{
  H[0][0] = (*Ixp  -2*(*I0) +*Ixm  +
             *Ixpyp-2*(*Iyp)+*Ixmyp)/2.0;
  H[1][0] = H[0][1] = ((*Ixpyp-*Ixmyp)-(*Ixp-*Ixm))/2.0;
  H[2][0] = H[0][2] = ((*Ixpzp  -*Ixmzp  )-
                       (*Ixpzm  -*Ixmzm  )+
		       (*Ixpypzp-*Ixmypzp)-
                       (*Ixpypzm-*Ixmypzm))/8.0;
  H[1][1] = ((*Iypyp-*I0)-(*Iyp-*Iym))/2.0;
  H[2][1] = H[1][2] = ((*Iypzp-*Izp)-(*Iypzm-*Izm))/2.0;
  H[2][2] = ( *Izp  -2*(*I0) +*Izm +
              *Iypzp-2*(*Iyp)+*Iypzm)/2.0;

}

//----------------------------------------------------------------------
// Hessian Matrix at (x,y,z+1/2)
//
void AnisoGS::HessianShiftZ(float* I,float H[3][3])
//            -------------
{

  H[0][0] = (*Ixp  -2*(*I0) +*Ixm +
	     *Ixpzp-2*(*Izp)+*Ixmzp)/2.0;
  H[1][0] = H[0][1] = ( (*Ixpyp-*Ixmyp) -
		        (*Ixpym-*Ixmym) +
		        (*Ixpypzp-*Ixmypzp)-
		        (*Ixpymzp-*Ixmymzp) )/8.0;

  H[2][0] = H[0][2] = ((*Ixpzp-*Ixmzp)-
                       (*Ixp  -*Ixm  ))/2.0;
  H[1][1] = ( *Iyp  -2*(*I0) +*Iym +
	      *Iypzp-2*(*Izp)+*Iymzp )/2.0;

  H[2][1] = H[1][2] = ((*Iypzp-*Iymzp)-(*Iyp-*Iym))/2.0;
  H[2][2] = ((*Izpzp-*I0)-(*Izp-*Izm))/2.0;

}


//----------------------------------------------------------------------
float AnisoGS::Norm(float v[3])
//             ----
{
  return sqrt(v[0]*v[0]+v[1]*v[1]+v[2]*v[2]);
} // Norm()


//----------------------------------------------------------------------
float AnisoGS::ScalarProduct(const t_Gradient v1, const t_3Point v2)
//             -------------
{
  return v1.x*v2.x+
         v1.y*v2.y+
         v1.z*v2.z;
}


//----------------------------------------------------------------
// Computes the eigenvectors of the structure tensor at a position
// x,y,z displaced by 0.5 in the coordinate given by coord
//
void AnisoGS::StructTensor_eigenvectors( int coord, int x, int y, int z, t_3Point& e0, t_3Point& e1, t_3Point& e2)
{
  
    int x1,y1,z1;
    unsigned char         Diagonale = false;

    tensor_xx->BufferPos(x,y,z);
    tensor_xy->BufferPos(x,y,z);
    tensor_xz->BufferPos(x,y,z);
    tensor_yy->BufferPos(x,y,z);
    tensor_yz->BufferPos(x,y,z);
    tensor_zz->BufferPos(x,y,z);

    (*matrice)[0][0] = (float) tensor_xx->ValeurBuffer();
    (*matrice)[0][1] = (float) tensor_xy->ValeurBuffer();
    (*matrice)[0][2] = (float) tensor_xz->ValeurBuffer();
    (*matrice)[1][1] = (float) tensor_yy->ValeurBuffer();
    (*matrice)[1][2] = (float) tensor_yz->ValeurBuffer();
    (*matrice)[2][2] = (float) tensor_zz->ValeurBuffer();

    x1=x;y1=y;z1=z;
    switch (coord) {
      case 0: x1++; break;
      case 1: y1++; break;
      case 2: z1++; break;
    }

    tensor_xx->BufferPos(x1,y1,z1);
    tensor_xy->BufferPos(x1,y1,z1);
    tensor_xz->BufferPos(x1,y1,z1);
    tensor_yy->BufferPos(x1,y1,z1);
    tensor_yz->BufferPos(x1,y1,z1);
    tensor_zz->BufferPos(x1,y1,z1);

    (*matrice)[0][0] += tensor_xx->ValeurBuffer();
    (*matrice)[0][1] += tensor_xy->ValeurBuffer();
    (*matrice)[0][2] += tensor_xz->ValeurBuffer();
    (*matrice)[1][1] += tensor_yy->ValeurBuffer();
    (*matrice)[1][2] += tensor_yz->ValeurBuffer();
    (*matrice)[2][2] += tensor_zz->ValeurBuffer();

    (*matrice)[1][0] = (*matrice)[0][1];
    (*matrice)[2][0] = (*matrice)[0][2];
    (*matrice)[2][1] = (*matrice)[1][2];

      // Calcul des vep et des vap dans les images associ�es
      int niter;
      Diagonale = jacobi( (float**)(*matrice), 3, 
                  vap, 
                  (float**)(*vec_propre), 
                  &niter );

      if (Diagonale) {


        eigsrt(vap,  *vec_propre, 3);

        e0.x = (*vec_propre)[0][0]; 
        e0.y = (*vec_propre)[1][0]; 
        e0.z = (*vec_propre)[2][0];

        e1.x = (*vec_propre)[0][1]; 
        e1.y = (*vec_propre)[1][1]; 
        e1.z = (*vec_propre)[2][1];

        e2.x = (*vec_propre)[0][2]; 
        e2.y = (*vec_propre)[1][2]; 
        e2.z = (*vec_propre)[2][2];
    }
    else {
    fprintf(stderr,"Struture Tensor, diagonalization pb ...\n");
       e0.x = 1.0;
       e0.y = 0.0;
       e0.z = 0.0;
       e1.x = 0.0;
       e1.y = 1.0;
       e1.z = 0.0;
       e2.x = 0.0;
       e2.y = 0.0;
       e2.z = 1.0;
    }
}

//----------------------------------------------------------------------
unsigned char AnisoGS::convert_uchar(double val)
{
  return (unsigned char) MIN(255,MAX(0,(val+1.0)*127.5));
}

#define MAX_SHORT 32700.0

//----------------------------------------------------------------------
short AnisoGS::convert_short(double val)
{
  return (short) MIN(MAX_SHORT,MAX(-MAX_SHORT,val*MAX_SHORT));
}

//----------------------------------------------------------------------
void AnisoGS::GetVectors( int coord, int x, int y, int z, t_3Point& e0, t_3Point& e1, t_3Point& e2)
{
  InrImage* ev=NULL;
  short* ev_buf;

  switch(coord) {
    case 0: ev = eigenvect_xp;   break;
    case 1: ev = eigenvect_yp;   break;
    case 2: ev = eigenvect_zp;   break;
  }

  ev->BufferPos(x,y,z);
  ev_buf = (short*) ev->BufferPtr();
  e1.x = MIN(1.0,ev_buf[0]/MAX_SHORT); 
  e1.y = MIN(1.0,ev_buf[1]/MAX_SHORT);
  e1.z = MIN(1.0,ev_buf[2]/MAX_SHORT);

  e2.x = MIN(1.0,ev_buf[3]/MAX_SHORT); 
  e2.y = MIN(1.0,ev_buf[4]/MAX_SHORT);
  e2.z = MIN(1.0,ev_buf[5]/MAX_SHORT);

  e0.x = e1.y*e2.z-e1.z*e2.y;
  e0.y = e1.z*e2.x-e1.x*e2.z;
  e0.z = e1.x*e2.y-e1.y*e2.x;
}

// 
//----------------------------------------------------------------------
// Get Principal Curvature Directions
//
void AnisoGS::PrincipalCurvatures(float grad[3], float H[3][3], float norm_grad,
//            -------------------
				  t_3Point& e0, t_3Point& e1, t_3Point& e2)
{
  
    float vmax[3];
    float vmin[3];
    float lmin;
    float lmax;

  // Calcul de la base (e0, e1, e2):
  Si CurvaturasPrincipales(  H, 
			     (float*) grad, 
			     (float*) vmax, 
			     (float*) vmin, 
			     &lmax, &lmin,
			     1E-2) != -1 Alors
    e0.x = grad[0]/norm_grad;
    e0.y = grad[1]/norm_grad;
    e0.z = grad[2]/norm_grad;
    e1.x = vmax[0]; e1.y = vmax[1]; e1.z = vmax[2];
    e2.x = vmin[0]; e2.y = vmin[1]; e2.z = vmin[2];
  Sinon
    fprintf(stderr,"CurvaturasPrincipales failed \n");
  //    fprintf(stderr,"  %d %d %d \n", x,y,z);
    fprintf(stderr," grad = %f %f %f \n", grad[0], grad[1], grad[2]);
  FinSi
}

//----------------------------------------------------------------------
// using only minimal curvature direction
float AnisoGS::Itere3D( InrImage* im )
//
{

   
    int x,y,z; //,n,i;
    float   val0,val1;
    float   val1div;
    float   u_e0;
//    float   u_e1;
    float   u_e2;
    float   alpha1_x, gamma1_x;
    float   alpha1_y, gamma1_y;
    float   alpha1_z, gamma1_z;
    float*  in;
    register float    *Iconv; 
    float gradient[3];
    float hessien[3][3];
    float vmax[3];
    float vmin[3];
    float lmin;
    float lmax;

    t_3Point e0;
//    t_3Point e1;
    t_3Point e2;

    t_Gradient grad;

    float   erreur,norm_grad;
    double diff;
    int nb_points_instables;
    int erreur_x=0,erreur_y=0,erreur_z=0;
    double   phi0_value=0;


  ComputeImage_c(im);

  ResetCoefficients();
  Si this->im_tmp == NULL AlorsFait
    this->im_tmp = new InrImage(WT_FLOAT, "im_tmp.inr.gz", im);

  im->InitBuffer();

  erreur = 0;

  nb_points_instables = 0;

  in = (float*) im->Buffer();

  Si use_filtre_rec Alors
    (*this->image_lissee) = (*im);
    filtre_rec->Filtre(sigma,5);
  Sinon
    filtre->MyFiltre( im, this->image_lissee,           0, -1, -1);
    filtre->MyFiltre( this->image_lissee, this->image_lissee, -1, 0, -1);
    filtre->MyFiltre( this->image_lissee, this->image_lissee, -1, -1, 0);
  FinSi

  Iconv = (float*) this->image_lissee->Buffer();  

  diff = 0;

  Pour(z,0,tz-1)

    Si z==0 Alors
      printf("z = %3d",z);
      fflush(stdout);
    Sinon 
      printf("\b\b\b");
      printf("%3d",z);
      fflush(stdout);
    FinSi

  Pour(y,0,ty-1)
  Pour(x,0,tx-1)
  
    // Calcul du gradient et du Hessien
    Si x>0 Et x<tx-1 Alors
      gradient[0] = (*(Iconv+1) - *(Iconv-1))/2.0;
      hessien[0][0] = (*(Iconv+1) - 2*(*Iconv) + *(Iconv-1));

      Si y>0 Et y<ty-1 Alors
        hessien[1][0] = hessien[0][1] = 
	    ((*(Iconv+1+tx) - *(Iconv-1+tx))
           -
	     (*(Iconv+1-tx) - *(Iconv-1-tx)))
	    /4.0;
      Sinon
        hessien[1][0] = hessien[0][1] = 0.0;
      FinSi

      Si z>0 Et z<tz-1 Alors
        hessien[2][0] = hessien[0][2] = 
	    ((*(Iconv+1+txy) - *(Iconv-1+txy))
           -
	     (*(Iconv+1-txy) - *(Iconv-1-txy)))
	    /4.0;
      Sinon
        hessien[2][0] = hessien[0][2] = 0.0;
      FinSi

    Sinon
      gradient[0] = 0.0;
      hessien[0][0] = 0.0;
    FinSi

    Si y>0 Et y<ty-1 Alors
      gradient[1] = (*(Iconv+tx) - *(Iconv-tx))/2.0;
      hessien[1][1] = (*(Iconv+tx) - 2*(*Iconv) + *(Iconv-tx));

      Si z>0 Et z<tz-1 Alors
        hessien[2][1] = hessien[1][2] = 
	    ((*(Iconv+tx+txy) - *(Iconv-tx+txy))
           -
	     (*(Iconv+tx-txy) - *(Iconv-tx-txy)))
	    /4.0;
      Sinon
        hessien[2][1] = hessien[1][2] = 0.0;
      FinSi

    Sinon
      gradient[1] = 0.0;
      hessien[1][1] = 0.0;
    FinSi

    Si z>0 Et z<tz-1 Alors
      gradient[2] = (*(Iconv+txy) - *(Iconv-txy))/2.0;
      hessien[2][2] = (*(Iconv+txy) - 2*(*Iconv) + *(Iconv-txy));
    Sinon
      gradient[2] = 0.0;
      hessien[2][2] = 0.0;
    FinSi

    val0 = *in;

// Diffusion anisotrope

    norm_grad =  this->Norm(gradient);

  Si norm_grad > 0.1 Alors

    // Calcul de la base (e0, e1, e2):
    Si CurvaturasPrincipales(  hessien, 
			       (float*) gradient, 
			       (float*) vmax, 
			       (float*) vmin, 
			       &lmax, &lmin,
			       1E-2) != -1 Alors
      e0.x = gradient[0]/norm_grad;
      e0.y = gradient[1]/norm_grad;
      e0.z = gradient[2]/norm_grad;

//        e1.x = vmax[0];
//        e1.y = vmax[1];
//        e1.z = vmax[2];

      e2.x = vmin[0];
      e2.y = vmin[1];
      e2.z = vmin[2];

    Sinon

      fprintf(stderr,"CurvaturasPrincipales failed \n");

      fprintf(stderr,"  %d %d %d \n", x,y,z);
      fprintf(stderr," grad = %f %f %f \n", gradient[0], gradient[1], gradient[2]);

      e0.x = gradient[0]/norm_grad;
      e0.y = gradient[1]/norm_grad;
      e0.z = gradient[2]/norm_grad;

      e2.x = -e0.y;
      e2.y = e0.x;
      e2.z = 0.0;

    FinSi

    //----- Calcul de alpha1_x, gamma1_x

    // Gradient en (x+1/2,y,z)
    Si (x < tx - 1) Et (z > 0) Et (z < tz - 1)  Alors
      grad.z = ( 
      	   *(in + txy     ) - *(in - txy     )
                 +
                 *(in + txy + 1 ) - *(in - txy + 1 )
               ) / 4.0;
    Sinon
      grad.z = 0;
    FinSi

    Si (x<tx-1) Et (y > 0)Et(y < ty-1) Alors
      grad.y = ( *(in + tx)     - *(in - tx)    
                 +
                 *(in + tx + 1) - *(in - tx + 1 ) 
               )/ 4.0;
    Sinon
      grad.y = 0;
    FinSi
 
    Si (x < tx-1)  Alors
      grad.x = *(in+1) - *(in);
    Sinon
      grad.x = 0;
    FinSi

    // Derivees directionnelles
    u_e0 = grad.x*e0.x + grad.y*e0.y + grad.z*e0.z;
    //      u_e1 = grad.x*e1.x + grad.y*e1.y + grad.z*e1.z;
    u_e2 = grad.x*e2.x + grad.y*e2.y + grad.z*e2.z;

    switch(contours_mode) {
      case CONTOURS_GRAD: phi0_value = phi3D_0(u_e0); break;
      case CONTOURS_SRAD: 
      case CONTOURS_RNRAD:
       phi0_value = ((*image_c)(x,y,z)+(*image_c)(x+1,y,z))/2.0; break;
    }

    alpha1_x = phi0_value*e0.x*e0.x + 
               phi3D_2(u_e2)*e2.x*e2.x;

    gamma1_x = (grad.y*e0.y + grad.z*e0.z)*phi0_value   *e0.x + 
               (grad.y*e2.y + grad.z*e2.z)*phi3D_2(u_e2)*e2.x;


    //----- Calcul de alpha1_y, gamma1_y 
   
    // Gradient en (x,y+1/2)
    Si (y < ty -1) Et (z > 0) Et ( z < tz - 1)  Alors
      grad.z = (
                *(in + txy      ) - *(in - txy      )
                +
                *(in + txy + tx) - *(in - txy + tx)
               ) / 4.0;
    Sinon
      grad.z = 0;
    FinSi

    Si  y < ty -1  Alors
      grad.y = *(in+tx) - *(in);
    Sinon
      grad.y  = 0;
    FinSi
 
    //  gradient en X
    Si (y < ty -1) Et (x > 0) Et (x< tx-1)  Alors
      grad.x = ( *(in + 1      ) - *(in - 1      ) 
                 +
                 *(in + 1 + tx) - *(in - 1 + tx)
               ) / 4.0;
    Sinon
      grad.x = 0;
    FinSi


    // Derivees directionnelles
    u_e0 = grad.x*e0.x + grad.y*e0.y + grad.z*e0.z;
    //      u_e1 = grad.x*e1.x + grad.y*e1.y + grad.z*e1.z;
    u_e2 = grad.x*e2.x + grad.y*e2.y + grad.z*e2.z;

    switch(contours_mode) {
      case CONTOURS_GRAD: phi0_value = phi3D_0(u_e0); break;
      case CONTOURS_SRAD: 
      case CONTOURS_RNRAD:
       phi0_value = ((*image_c)(x,y,z)+(*image_c)(x,y+1,z))/2.0; break;
    }

    alpha1_y = phi0_value*e0.y*e0.y + 
               phi3D_2(u_e2)*e2.y*e2.y;

    gamma1_y = (grad.x*e0.x + grad.z*e0.z)*phi0_value*e0.y + 
               (grad.x*e2.x + grad.z*e2.z)*phi3D_2(u_e2)*e2.y;


    //----- Calcul de alpha1_z, gamma1_z 
   
    //  gradient en Z
    Si z < tz -1  Alors
      grad.z = *(in + txy) - *(in);
    Sinon
      grad.z = 0;
    FinSi

    //  gradient en Y
    Si (z < tz - 1) Et (y > 0) Et ( y < ty - 1 ) Alors
      grad.y = (
                *(in + tx       ) - *(in - tx       )
                +
                *(in + tx + txy) - *(in - tx + txy)
               ) / 4.0;
    Sinon
      grad.y = 0;
    FinSi
 
    //  gradient en X
    Si (z < tz-1) Et (x > 0) Et ( x < tx - 1 ) Alors
      grad.x = (
    	    *(in + 1) - *(in - 1)
                +
    	    *(in + 1 + txy) - *(in - 1 + txy)
    	    ) / 4.0;
    Sinon
      grad.x = 0;
    FinSi


    // Derivees directionnelles
    u_e0 = grad.x*e0.x + grad.y*e0.y + grad.z*e0.z;
    //      u_e1 = grad.x*e1.x + grad.y*e1.y + grad.z*e1.z;
    u_e2 = grad.x*e2.x + grad.y*e2.y + grad.z*e2.z;

    switch(contours_mode) {
      case CONTOURS_GRAD: phi0_value = phi3D_0(u_e0); break;
      case CONTOURS_SRAD: 
      case CONTOURS_RNRAD:
       phi0_value = ((*image_c)(x,y,z)+(*image_c)(x,y,z+1))/2.0; break;
    }

    alpha1_z = phi0_value*e0.z*e0.z + 
               phi3D_2(u_e2)*e2.z*e2.z;

    gamma1_z = (grad.x*e0.x + grad.y*e0.y)*phi0_value*e0.z + 
               (grad.x*e2.x + grad.y*e2.y)*phi3D_2(u_e2)*e2.z;

    //----- Mise a jour de l'image

    val1    =  this->beta*(*image_entree)(x,y,z);
    val1div =  this->beta;

    Si (x>0)Et(x<tx-1) Alors
      val1    += alpha1_x    * (*(in+1  )) +
                 alpha_x     * (*(in-1  )) +
                 gamma1_x  - gamma_x;

      val1div += alpha1_x + alpha_x;
    FinSi

    Si (y>0)Et(y<ty-1) Alors
      val1    += alpha1_y     * (*(in+tx )) +
                 alpha_y[x]   * (*(in-tx )) +
                 gamma1_y  - gamma_y[x];

      val1div += alpha1_y + alpha_y[x];
    FinSi

    Si (z>0) Et (z<tz-1) Alors
      val1    += alpha1_z      * (*(in+txy  )) +
                 alpha_z[x][y] * (*(in-txy  )) +
                 gamma1_z  - gamma_z[x][y];

      val1div += alpha1_z + alpha_z[x][y];
    FinSi

    switch(contours_mode) {
      case CONTOURS_GRAD:
        Si fabsf(val1div)>1E-4 Alors
	      val1 /= val1div;
        Sinon
	      fprintf(stderr,"AnisoGaussSeidel.c:Itere3D() \t fabsf(val1div)<1E-4 \n");
        FinSi
	  break;
      case CONTOURS_SRAD:
      case CONTOURS_RNRAD:
        val1 = (*in + dt*val1)/(1+dt*val1div);
        break;
    }

    alpha_z[x][y] = alpha1_z;
    alpha_y[x]    = alpha1_y;
    alpha_x       = alpha1_x;

    gamma_z[x][y] = gamma1_z;
    gamma_y[x]    = gamma1_y;
    gamma_x       = gamma1_x;

  Sinon

    val1 = *in;
    
    alpha_z[x][y] = 
    alpha_y[x]    = 
    alpha_x       = 
    gamma_z[x][y] = 
    gamma_y[x]    = 
    gamma_x       = 0;

  FinSi


    Si fabsf(val1-val0) > epsilon Alors
      nb_points_instables++;
    FinSi

    diff += (val1-val0)*(val1-val0);
    Si fabsf(val1-val0) > erreur Alors
      erreur = fabsf(val1-val0);
      erreur_x = x;
      erreur_y = y;
      erreur_z = z;
    FinSi

    this->im_tmp->BufferPos(x,y,z);
    this->im_tmp->FixeValeur(val1);

    in++;
    Iconv++;

  FinPour
  FinPour
  FinPour

  (*im) = (*this->im_tmp);

/*
  cout << endl;
  cout << " Erreur = " << erreur << endl;
  cout << "( " << erreur_x << ", " 
               << erreur_y << ", " 
               << erreur_z << " )" << endl; 
  cout << "nb de points variables " << nb_points_instables << endl;
*/
  diff /= txy*tz;

  cout << "diff =" << sqrt(diff) << endl;

  return erreur;

} // AnisoGS::Itere3D()



//----------------------------------------------------------------------
// using minimal and maximal curvature directions
//
// Extension for taking into account the noise characteristics:
// Gaussian noise or
// Speckle noise 
//
// Use a mask for the processing if the mask image is set.
//
float AnisoGS::Itere3D_2_new( InrImage* im )
//
{
    int x,y,z; //,n,i;
    float   val0,val1;
    float   val1_implicit=0;
    float   val1div;
    float   u_e0;
    float   u_e1;
    float   u_e2;
    float   alpha1_x, gamma1_x;
    float   alpha1_y, gamma1_y;
    float   alpha1_z, gamma1_z;
    float*  in;
    register float    *Iconv; 
    float gradient[3];
    float hessien[3][3];

    t_3Point e0;
    t_3Point e1;
    t_3Point e2;

    t_Gradient grad;

    float   erreur,norm_grad;
    double diff;
    int nb_points_instables;
    int erreur_x=0,erreur_y=0,erreur_z=0;

    // Sum over all the points
    float     sum_divF;
    long int  nb_calculated_points;

    // Sum over the points that don't evolve too much
    float     sum_divF2;
    long int  nb_calculated_points2;

    float        u,u0;
    float        divF=0;
    std::string  divFname;

    unsigned char mask_test;
//    double    phi0_value=0;
    double    lambda0=0,lambda1=0,lambda2=0;
    double    sigma2=0.0; // variance of the noise
 
/*    double   planstats_sigma = 2.0;
    double   dirstats_sigma = 2.0;
*/
//    double lambda_threshold = 0.6;

    int      xp,xm,yp,ym,zp,zm,incx,incy,incz;
    float    min_normgrad = 0.1;
  // pre-compute information

  // printf("Itere3D_2_new \n");

  if (contours_mode!=CONTOURS_RNRAD_NEW) {
    ComputeImage_c(im);
  } else {
    ComputeImage_c(im);
    sigma2 = Compute_sigma2_MRI_mode(im);
  }

  ResetCoefficients();
  // pb: the coefficients are not good for multi-threading ???

  Si this->im_tmp == NULL AlorsFait
    this->im_tmp = new InrImage(WT_FLOAT, "im_tmp.inr.gz", im);
  Si divFim == NULL Alors
    divFim = new InrImage(WT_FLOAT, divFname.c_str() , im);
  FinSi

  divFim->InitImage(0);
  im->InitBuffer();
  erreur = 0;
  nb_points_instables = 0;
  in = (float*) im->Buffer();
  Si use_filtre_rec Alors
    (*this->image_lissee) = (*im);
    filtre_rec->Filtre(sigma,5);
  Sinon
    filtre->MyFiltre( im, this->image_lissee,           0, -1, -1);
    filtre->MyFiltre( this->image_lissee, this->image_lissee, -1, 0, -1);
    filtre->MyFiltre( this->image_lissee, this->image_lissee, -1, -1, 0);
  FinSi

  Iconv = (float*) this->image_lissee->Buffer();  

  diff = 0;

  nb_calculated_points = 0;
  sum_divF = 0;

  nb_calculated_points2 = 0;
  sum_divF2 = 0;

  Pour(z,ROI_zmin,ROI_zmax)
    Si z==ROI_zmin Alors
      printf("z = %3d",z);
      fflush(stdout);
    Sinon 
      printf("\b\b\b");
      printf("%3d",z);
      fflush(stdout);
    FinSi

  // reset  coefficients
  Pour(x,0,tx-1)
    alpha_y[x]    = gamma_y[x]    = 0;
  FinPour

  Pour(y,ROI_ymin,ROI_ymax)
  // reset X coefficients
  alpha_x       = gamma_x = 0;

  im->BufferPos(ROI_xmin,y,z);
  in = (float*) im->BufferPtr();
  image_lissee->BufferPos(ROI_xmin,y,z);
  Iconv = (float*) image_lissee->BufferPtr();

  Pour(x,ROI_xmin,ROI_xmax)
  
    val1 = val0 = *in;
    mask_test = (mask==NULL)||((mask!=NULL)&&((*mask)(x,y,z)>0.5));
    xp=1;
    xm=-1;
    incx=1;
    if (x==tx-1) { xp=0; incx=0; }
    if (x==0)    xm=0;

    yp=tx;
    ym=-tx;
    incy=1;
    if (y==ty-1) { yp=0; incy = 0; }
    if (y==0)    ym=0;

    zp=txy;
    zm=-txy;
    incz=1;
    if (z==tz-1) { zp=0; incz = 0; }
    if (z==0)    zm=0;


    Si x>ROI_xmin Et x<ROI_xmax Et y>ROI_ymin Et y<ROI_ymax Et z>ROI_zmin Et z<ROI_zmax
    Alors

      InitNeighborhood(Iconv,x,y,z);
      // Gradient en (x+1/2,y,z)
      //----- Calcul de alpha1_x, gamma1_x
      grad.x = *(in+xp) - *(in);
      grad.y = ( *(in+yp) - *(in+ym) + *(in+yp+xp) -*(in+ym+xp) )/ 4.0;
      grad.z = ( *(in+zp) - *(in+zm) + *(in+zp+xp)- *(in+zm+xp) )/ 4.0;

      // Calcul du gradient, du hessien en (x+1/2,y,z)
      this->GradShiftX(Iconv,gradient);
      // Courbures principales
      norm_grad =  this->Norm(gradient);
      InitFlux(e0,e1,e2);
      if (norm_grad > min_normgrad) {
        this->HessianShiftX(Iconv,hessien);
        this->PrincipalCurvatures(gradient,hessien,norm_grad,e0,e1,e2);
      }
      // Derivees directionnelles
      u_e0 = this->ScalarProduct(grad,e0);
      u_e1 = this->ScalarProduct(grad,e1);
      u_e2 = this->ScalarProduct(grad,e2);

    switch ( contours_mode )
    {
    case CONTOURS_GRAD: 
        lambda0 = phi3D_0(u_e0); 
        lambda1 = phi3D_1(u_e1);
        lambda2 = phi3D_2(u_e2);
        break;
    case CONTOURS_SRAD:
    case CONTOURS_RNRAD:
        lambda0 = ( ( *image_c ) ( x,y,z ) + ( *image_c ) ( x+incx,y,z ) ) /2.0; 
        lambda1 = phi3D_1(u_e1);
        lambda2 = phi3D_2(u_e2);
        break;
    case CONTOURS_RNRAD_NEW:
        double mean,var;
        lambda0 = ( (*image_c)(x,y,z) + (*image_c)(x+incx,y,z) ) /2.0; 
        if (lambda0>2) lambda0=2;
        if (lambda0<1) {
          ComputeLocalPlanStats(im, (float)x+((float)incx)/2.0, (float) y, (float) z,  e1,e2, planstats_sigma, mean,var);
           switch (diffusion_eigenvalues_mode) {
           case DIFF_MATRIX_EIGEN_SUM:
              lambda1 = lambda0 + function_c_MRI( sigma2, var, mean); 
              break;
           case DIFF_MATRIX_EIGEN_MAX:
              lambda1 = MAX(lambda0,function_c_MRI( sigma2, var, mean)); 
              break;
           }
        } else lambda1 = lambda0;
        if (lambda1<1) {
          ComputeLocalDirStats(im, (float)x+((float)incx)/2.0, (float) y, (float) z,  e2, dirstats_sigma, mean,var);
           switch (diffusion_eigenvalues_mode) {
           case DIFF_MATRIX_EIGEN_SUM:
              lambda2 = lambda1 + function_c_MRI( sigma2, var, mean);
              break;
           case DIFF_MATRIX_EIGEN_MAX:
              lambda2 = MAX(lambda1,function_c_MRI( sigma2, var, mean));
              break;
           }
        } else lambda2 = lambda1;
        if (lambda1>1) lambda1=1;
        if (lambda2>1) lambda2=1;
        break;
    }


      alpha1_x = lambda0 *e0.x*e0.x + 
                 lambda1 *e1.x*e1.x +
                 lambda2 *e2.x*e2.x;

      gamma1_x = (grad.y*e0.y + grad.z*e0.z)* lambda0 *e0.x + 
                 (grad.y*e1.y + grad.z*e1.z)* lambda1 *e1.x +
                 (grad.y*e2.y + grad.z*e2.z)* lambda2 *e2.x;

//if ((x%10==0)&&(y==(int)(im->_ty/2))&&(z==(int)(im->_tz/2))) {
//  printf(" %d x+, alpha1_x %f  gamma1_x %f \n",x,alpha1_x,gamma1_x);
//}


/*if ((x==tx-1)&&(y==10)&&(z==10)) {
  printf("lambda0 %f lambda1 %f lambda2 %f \n",lambda0,lambda1,lambda2);
  printf("alpha1_x %f, alpha1_y %f, alpha1_z %f, val1 %f val1div %f \n",
    alpha1_x,alpha1_y,alpha1_z,val1,val1div); 
  printf("gamma1_x %f, gamma1_y %f, gamma1_z %f \n",
    gamma1_x,gamma1_y,gamma1_z); 
  printf("alpha_x %f, alpha_y[x] %f, alpha_z[x][y] %f \n",
    alpha_x,alpha_y[x],alpha_z[x][y]); 
  printf("gamma_x %f, gamma_y[x] %f, gamma_z[x][y] %f \n",
    gamma_x,gamma_y[x],gamma_z[x][y]); 
}
*/
      //----- Calcul de alpha1_y, gamma1_y 
   
      // Gradient en (x,y+1/2)
      grad.x = (*(in+xp)-*(in+xm)+*(in+xp+yp)-*(in+xm+yp))/4.0;
      grad.y =  *(in+yp) - *(in);
      grad.z = (*(in+zp)-*(in+zm)+*(in+zp+yp)-*(in+zm+yp))/4.0;

      // Calcul du gradient, du hessien en (x,y+1/2,z)
      this->GradShiftY(Iconv,gradient);
      // Courbures principales
      norm_grad =  this->Norm(gradient);
      InitFlux(e0,e1,e2);
      if (norm_grad > min_normgrad) {
	this->HessianShiftY(Iconv,hessien);
	this->PrincipalCurvatures(gradient,hessien,norm_grad,e0,e1,e2);
      }
      // Derivees directionnelles
      u_e0 = this->ScalarProduct(grad,e0);
      u_e1 = this->ScalarProduct(grad,e1);
      u_e2 = this->ScalarProduct(grad,e2);

    switch ( contours_mode )
    {
    case CONTOURS_GRAD: 
        lambda0 = phi3D_0(u_e0); 
        lambda1 = phi3D_1(u_e1);
        lambda2 = phi3D_2(u_e2);
        break;
    case CONTOURS_SRAD:
    case CONTOURS_RNRAD:
        lambda0 = ((*image_c)(x,y,z)+(*image_c)(x,y+incy,z))/2.0;
        lambda1 = phi3D_1(u_e1);
        lambda2 = phi3D_2(u_e2);
        break;
    case CONTOURS_RNRAD_NEW:
        double mean,var;
        lambda0 = ((*image_c)(x,y,z)+(*image_c)(x,y+incy,z))/2.0;
        if (lambda0>2) lambda0=2;
        if (lambda0<1) {
          ComputeLocalPlanStats(im, (float)x, (float) y+((float)incy)/2.0, (float) z,  e1,e2, planstats_sigma, mean,var);
           switch (diffusion_eigenvalues_mode) {
           case DIFF_MATRIX_EIGEN_SUM:
              lambda1 = lambda0 + function_c_MRI( sigma2, var, mean); 
              break;
           case DIFF_MATRIX_EIGEN_MAX:
              lambda1 = MAX(lambda0,function_c_MRI( sigma2, var, mean)); 
              break;
           }
        } else lambda1 = lambda0;
        if (lambda1<1) {
          ComputeLocalDirStats(im, (float)x, (float) y+((float)incy)/2.00, (float) z,  e2, dirstats_sigma, mean,var);
           switch (diffusion_eigenvalues_mode) {
           case DIFF_MATRIX_EIGEN_SUM:
              lambda2 = lambda1 + function_c_MRI( sigma2, var, mean);
              break;
           case DIFF_MATRIX_EIGEN_MAX:
              lambda2 = MAX(lambda1,function_c_MRI( sigma2, var, mean));
              break;
           }
        } else lambda2 = lambda1;
        if (lambda1>1) lambda1=1;
        if (lambda2>1) lambda2=1;
        break;
    }

      alpha1_y = lambda0 *e0.y*e0.y + 
                 lambda1 *e1.y*e1.y +
                 lambda2 *e2.y*e2.y;

      gamma1_y = (grad.x*e0.x + grad.z*e0.z)* lambda0 *e0.y + 
                 (grad.x*e1.x + grad.z*e1.z)* lambda1 *e1.y +
                 (grad.x*e2.x + grad.z*e2.z)* lambda2 *e2.y;

//if ((x%10==0)&&(y==(int)(im->_ty/2))&&(z==(int)(im->_tz/2))) {
//  printf(" %d y+, alpha1_y %f  gamma1_y %f \n",x, alpha1_y,gamma1_y);
//}

      //----- Calcul de alpha1_z, gamma1_z 
      grad.x = (*(in+xp) - *(in+xm) + *(in+xp+zp) - *(in+xm+zp))/4.0;
      grad.y = (*(in+yp) - *(in+ym) + *(in+yp+zp) - *(in+ym+zp))/4.0; 
      grad.z = *(in+zp)-*in;

      // Calcul du gradient, du hessien en (x,y,z+1/2)
      this->GradShiftZ(Iconv,gradient);

      // Courbures principales
      norm_grad =  this->Norm(gradient);
      InitFlux(e0,e1,e2);
      if (norm_grad > min_normgrad) {
  	    this->HessianShiftZ(Iconv,hessien);
	    this->PrincipalCurvatures(gradient,hessien,norm_grad,e0,e1,e2);
      }
      // Derivees directionnelles
      u_e0 = this->ScalarProduct(grad,e0);
      u_e1 = this->ScalarProduct(grad,e1);
      u_e2 = this->ScalarProduct(grad,e2);

    switch ( contours_mode )
    {
    case CONTOURS_GRAD: 
        lambda0 = phi3D_0(u_e0); 
        lambda1 = phi3D_1(u_e1);
        lambda2 = phi3D_2(u_e2);
        break;
    case CONTOURS_SRAD:
    case CONTOURS_RNRAD:
        lambda0 = ((*image_c)(x,y,z)+(*image_c)(x,y,z+incz))/2.0;
        lambda1 = phi3D_1(u_e1);
        lambda2 = phi3D_2(u_e2);
        break;
    case CONTOURS_RNRAD_NEW:
        double mean,var;
        lambda0 = ((*image_c)(x,y,z)+(*image_c)(x,y,z+incz))/2.0;
        if (lambda0>2) lambda0=2;
        if (lambda0<1) {
          ComputeLocalPlanStats(im, (float)x, (float) y, (float) z+((float)incz)/2.0,  e1,e2, planstats_sigma, mean,var);
           switch (diffusion_eigenvalues_mode) {
           case DIFF_MATRIX_EIGEN_SUM:
              lambda1 = lambda0 + function_c_MRI( sigma2, var, mean); 
              break;
           case DIFF_MATRIX_EIGEN_MAX:
              lambda1 = MAX(lambda0,function_c_MRI( sigma2, var, mean)); 
              break;
           }
        } else lambda1 = lambda0;
        if (lambda1<1) {
          ComputeLocalDirStats(im, (float)x, (float) y, (float) z+((float)incz)/2.0,  e2, dirstats_sigma, mean,var);
           switch (diffusion_eigenvalues_mode) {
           case DIFF_MATRIX_EIGEN_SUM:
              lambda2 = lambda1 + function_c_MRI( sigma2, var, mean);
              break;
           case DIFF_MATRIX_EIGEN_MAX:
              lambda2 = MAX(lambda1,function_c_MRI( sigma2, var, mean));
              break;
           }
        } else lambda2 = lambda1;
        if (lambda1>1) lambda1=1;
        if (lambda2>1) lambda2=1;
        break;
    }


      alpha1_z = lambda0 *e0.z*e0.z + 
                 lambda1 *e1.z*e1.z +
                 lambda2 *e2.z*e2.z;

      gamma1_z = (grad.x*e0.x + grad.y*e0.y) * lambda0 *e0.z + 
                 (grad.x*e1.x + grad.y*e1.y) * lambda1 *e1.z +
                 (grad.x*e2.x + grad.y*e2.y) * lambda2 *e2.z;

//if ((x%10==0)&&(y==(int)(im->_ty/2))&&(z==(int)(im->_tz/2))) {
//  printf(" %d z+, alpha1_z %f  gamma1_z %f \n",x,alpha1_z,gamma1_z);
//}

      //----- Mise a jour de l'image

/*
if (x==ROI_xmin) alpha_x  = gamma_x  = 0;
if (x==ROI_xmax) alpha1_x = gamma1_x = 0;
if (y==ROI_ymin) alpha_y[x]  = gamma_y[x]  = 0;
if (y==ROI_ymax) alpha1_y    = gamma1_y = 0;
if (z==ROI_zmin) alpha_z[x][y]  = gamma_z[x][y]  = 0;
if (z==ROI_zmax) alpha1_z       = gamma1_z       = 0;
*/

      val1    =  0;
      val1div =  0;


      val1    += alpha1_x    * (*(in+xp  )) +
                 alpha_x     * (*(in+xm  )) +
                 gamma1_x  - gamma_x;

      val1div += alpha1_x + alpha_x;


      val1    += alpha1_y     * (*(in+yp )) +
                 alpha_y[x]   * (*(in+ym )) +
                 gamma1_y  - gamma_y[x];

      val1div += alpha1_y + alpha_y[x];


      val1    += alpha1_z      * (*(in+zp  )) +
                 alpha_z[x][y] * (*(in+zm  )) +
                 gamma1_z  - gamma_z[x][y];

      val1div += alpha1_z + alpha_z[x][y];


    switch ( noise_type )
    {
    case GAUSSIAN_NOISE:
        if ( mask_test )
        {
            divF = ( val1 - *in * val1div ) * ( *in- ( *image_entree ) ( x,y,z ) );
            sum_divF += divF;
            nb_calculated_points++;
        }
    

        val1    += this->beta* ( *image_entree ) ( x,y,z );
        val1div += this->beta;
    
        switch ( contours_mode )
        {
            case CONTOURS_GRAD:
                Si fabsf ( val1div ) >1E-4 Alors
                val1 /= val1div;
                Sinon
                fprintf ( stderr,"AnisoGaussSeidel.c:Itere3D() \t fabsf(val1div)<1E-4 \n" );
                FinSi
                break;
            case CONTOURS_SRAD:
            case CONTOURS_RNRAD:
            case CONTOURS_RNRAD_NEW:
                val1 = ( *in + dt*val1 ) / ( 1+dt*val1div );
                break;
        }
    
        break;
    
    case SPECKLE_NOISE:
        u0 = ( *image_entree ) ( x,y,z );
        u  = *in;
    
        if ( mask_test&& ( fabsf ( u+u0 ) >1E-4 ) && ( u>1 ) && ( u0>1 ) )
        {
            divF = ( val1 - u * val1div ) * ( u-u0 ) / ( u+u0 ) *u;
            /*
            if (divF<-1000) {
              printf("val1 %03.1f, u %03.1f, val1div %03.1f, u0  %03.1f --> divF  %03.1f\n",
                 val1,u,val1div,u0,divF);
            }
            */
            sum_divF += divF;
            nb_calculated_points++;
        }
        else
            divF = 0;
    
        if ( ( u>1 ) && ( u0>1 ) )
        {
            //
            // See if we can get a more implicit scheme
            // by solving a 3rd order equation:
            //
    #ifdef IMPLICIT
            double w[3];
            int nb_solutions;
            Solve3rdOrder ( val1div,- ( val1-this->beta ),
                            -this->beta* ( u0*u0 ),w,nb_solutions );
            if ( nb_solutions==1 )
                val1_implicit = w[0];
            else
            {
                /*
                printf(" 3rd order equation %d solutions %3.2f %3.2f %3.2f \n",
                   nb_solutions,w[0],w[1],w[2]);
                */
                if ( w[0] >=0 ) val1_implicit = w[0];
                else
                    if ( w[1] >=0 ) val1_implicit = w[1];
                    else
                        if ( w[2] >=0 ) val1_implicit = w[2];
            }
            val1=val1_implicit;
    #else
            val1  += beta* ( ( u0*u0 ) / ( u*u )-1 );
            Si fabsf ( val1div ) >1E-4 Alors
            val1 /= val1div;
            Sinon
            fprintf ( stderr,"AnisoGaussSeidel.c:Itere3D() \t fabsf(val1div)<1E-4 \n" );
            FinSi
    #endif
        }
    
        break;
    } // switch noise type

      if (fabsf(val1-*in)<0.1) {
        sum_divF2 += divF;
        nb_calculated_points2++;
      }

      if (divFim!=NULL) {
	divFim->BufferPos(x,y,z);
	divFim->FixeValeur(divF);
      }


      alpha_z[x][y] = alpha1_z;
      alpha_y[x]    = alpha1_y;
      alpha_x       = alpha1_x;

      gamma_z[x][y] = gamma1_z;
      gamma_y[x]    = gamma1_y;
      gamma_x       = gamma1_x;


    Sinon

      val1 = *in;
    
      alpha_z[x][y] = 
      alpha_y[x]    = 
      alpha_x       = 
      gamma_z[x][y] = 
      gamma_y[x]    = 
      gamma_x       = 0;

    FinSi

    Si fabsf(val1-val0) > epsilon Alors
      nb_points_instables++;
    FinSi

    diff += (val1-val0)*(val1-val0);
    Si fabsf(val1-val0) > erreur Alors
      erreur = fabsf(val1-val0);
      erreur_x = x;
      erreur_y = y;
      erreur_z = z;
    FinSi

    this->im_tmp->BufferPos(x,y,z);

    if (val1<min_intensity) {
      //      fprintf(stderr,"I=%3.2f<min, (%3d,%3d,%3d) \n",val1,x,y,z);
      val1=min_intensity;
    }
    if (val1>max_intensity) {
      //      fprintf(stderr,"I=%3.2f<max, (%3d,%3d,%3d) \n",val1,x,y,z);
      val1=max_intensity;
    }

    this->im_tmp->FixeValeur(val1);

    in++;
    Iconv++;

  FinPour
  FinPour
  FinPour

  ExtendBoundariesVonNeumann(im_tmp);
  (*im) = (*this->im_tmp);

/*
  cout << endl;
  cout << " Erreur = " << erreur << endl;
  cout << "( " << erreur_x << ", " 
               << erreur_y << ", " 
               << erreur_z << " )" << endl; 
  cout << "nb de points variables " << nb_points_instables << endl;
*/
  diff /= txy*tz;

  cout << "\t diff =" << sqrt(diff) << "\t";

  if (noise_standard_deviation <0) {
/*    fprintf(stderr,"noise SD <0 ?\n");
    estimated_DA_coeff = sum_divF/(1.0*nb_calculated_points);
    fprintf(stderr,"lambda estimation for noise/sigma_noise^2 = %f \n", 
	    estimated_DA_coeff);
*/
  }
  else {
    estimated_DA_coeff =sum_divF/(1.0*nb_calculated_points)/this->variance;
    fprintf(stderr,"sum_divF=%3.2f, nb_calculated_points = %5d, variance = %3.3f, \n ===  lambda estimation for noise = %f \n", 
	    sum_divF,(int)nb_calculated_points,this->variance, estimated_DA_coeff);

      if ((noise_SD_preset)&&(estimated_DA_coeff>0))
	this->beta = estimated_DA_coeff;
      fprintf(stderr, "\n  Setting beta to %2.2f \n\n",beta);

    estimated_DA_coeff =sum_divF2/(1.0*nb_calculated_points2)/this->variance;
    fprintf(stderr,
	    " ===  lambda2 estimation for noise = %f, %02.2f percent of points \n", 
	    estimated_DA_coeff,
	    (nb_calculated_points2*100.0/nb_calculated_points));

    /*
    // set to the 2nd estimation
    if ( (nb_calculated_points2*100.0/nb_calculated_points) > 80 ) {
      if ((noise_SD_preset)&&(estimated_DA_coeff>0))
	this->beta = estimated_DA_coeff;
      fprintf(stderr, "\n  Setting beta to %2.2f \n\n",beta);
    }
    */
  }

  divFname = (boost::format("divF_%03d.ami.gz") % iteration).str();
//divFim->Sauve(divFname);

  return erreur;

} // AnisoGS::Itere3D_2_new()



//----------------------------------------------------------------------
// using minimal and maximal curvature directions
//
// Extension for taking into account the noise characteristics:
// Rician Noise
// Use of the structure tensor for filtering
//
// Use a mask for the processing if the mask image is set.
//
float AnisoGS::Itere3D_ST_RNRAD( InrImage* im )
//
{
    int x,y,z; //,n,i;
    float   val0,val1;
    float   val1_implicit=0;
    float   val1div;
    float   u_e0;
    float   u_e1;
    float   u_e2;
    float   alpha1_x, gamma1_x;
    float   alpha1_y, gamma1_y;
    float   alpha1_z, gamma1_z;
    float*  in;
    register float    *Iconv=NULL; 
//    float gradient[3];
//    float hessien[3][3];

    t_3Point e0;
    t_3Point e1;
    t_3Point e2;

    t_Gradient grad;

    float   erreur = 0; //,norm_grad;
    double diff;
    int nb_points_instables;
    int erreur_x=0,erreur_y=0,erreur_z=0;

    // Sum over all the points
    float     sum_divF;
    long int  nb_calculated_points;

    // Sum over the points that don't evolve too much
    float     sum_divF2;
    long int  nb_calculated_points2;

    float     u,u0;
    float     divF=0;
    std::string    divFname;

    unsigned char mask_test;
//    double    phi0_value=0;
    double    lambda0=0,lambda1=0,lambda2=0;
    double    sigma2=0.0; // variance of the noise
 
/*
    double   planstats_sigma = 1.0;
    double   dirstats_sigma  = 1.5;
*/
//    double lambda_threshold = 0.6;

//    double        diff_coeff;
    unsigned char speedup_skip;
    long          speedup_counter = 0;

    int      xp,xm,yp,ym,zp,zm,incx,incy,incz;
  // pre-compute information

  // printf("Itere3D_2_new \n");

  if ((iteration==1)&&(loop==2)) {
    ComputeStructureTensor(im,0.7,sigma);
    ComputeEigenVectors();
  }


/*  // first iteration twice, use Tensor from the second
  if ((iteration==loop)&&(loop<=max_loop)) {
    ComputeStructureTensor(im,0.7,sigma);
    ComputeEigenVectors();
    printf("copy back input image \n");
    (*im) = (*image_entree);
    iteration = 1;
    loop+=2;
  }
*/
  if (iteration==loop) {
    ComputeStructureTensor(im,0.7,sigma);
    ComputeEigenVectors();
//    printf("copy back image \n");
//    (*im) = (*image_c);
    loop+=2;
  }

  if (contours_mode!=CONTOURS_RNRAD_NEW) {
    ComputeImage_c(im);
  } else {
    ComputeImage_c(im);
    sigma2 = Compute_sigma2_MRI_mode(im);
  }


  ResetCoefficients();


  // pb: the coefficients are not good for multi-threading ???

  Si this->im_tmp == NULL AlorsFait
    this->im_tmp = new InrImage(WT_FLOAT, "im_tmp.inr.gz", im);
  Si divFim == NULL Alors
    divFim = new InrImage(WT_FLOAT, divFname.c_str() , im);
  FinSi

  divFim->InitImage(0);
  im->InitBuffer();
  erreur = 0;
  nb_points_instables = 0;
  in = (float*) im->Buffer();

  diff = 0;

  nb_calculated_points = 0;
  sum_divF = 0;

  nb_calculated_points2 = 0;
  sum_divF2 = 0;

//printf("diff eigen mode : %d\n",diffusion_eigenvalues_mode);

  Pour(z,ROI_zmin,ROI_zmax)
    Si z==ROI_zmin Alors
      printf("z = %3d",z);
      fflush(stdout);
    Autrement
    Si (z-ROI_zmin)%5 == 0 Alors
      printf("\b\b\b");
      printf("%3d",z);
      fflush(stdout);
    FinSi

  // reset Y coefficients
  Pour(x,0,tx-1)
    alpha_y[x] = gamma_y[x] = 0;
  FinPour

  Pour(y,ROI_ymin,ROI_ymax)
  // reset X coefficients
  alpha_x = gamma_x = 0;
  im->BufferPos(ROI_xmin,y,z);
  in = (float*) im->BufferPtr();

  Pour(x,ROI_xmin,ROI_xmax)
  
    val1 = val0 = *in;
    mask_test = (mask==NULL)||((mask!=NULL)&&((*mask)(x,y,z)>0.5));
    xp=1;
    xm=-1;
    incx=1;

// not necessary since boundary is taken care of
//    if (x==tx-1) { xp=0; incx=0; }
//    if (x==0)    xm=0;

    yp=tx;
    ym=-tx;
    incy=1;
//    if (y==ty-1) { yp=0; incy = 0; }
//    if (y==0)    ym=0;

    zp=txy;
    zm=-txy;
    incz=1;
//    if (z==tz-1) { zp=0; incz = 0; }
//    if (z==0)    zm=0;

    speedup_skip = 0;

/*
    if ((contours_mode==CONTOURS_SRAD)     ||
        (contours_mode==CONTOURS_RNRAD)    ||
        (contours_mode==CONTOURS_RNRAD_NEW) ) {
      diff_coeff = ( *image_c ) ( x,y,z );
      // do a scalar diffusion to speed-up the process
      if (diff_coeff>0.5) {
        alpha1_x =  ( diff_coeff + (*image_c)(x+incx,y,z) ) /2.0;;
        alpha1_y =  ( diff_coeff + (*image_c)(x,y+incy,z) ) /2.0;;
        alpha1_z =  ( diff_coeff + (*image_c)(x,y,z+incz) ) /2.0;;

        gamma1_x = gamma1_y = gamma1_z = 0;
        speedup_skip = 1;
        speedup_counter++;
      }
    }
*/

    if (!speedup_skip) {
      InitNeighborhood(Iconv,x,y,z);

      // Gradient en (x+1/2,y,z)
      //----- Calcul de alpha1_x, gamma1_x
      grad.x = *(in+xp) - *(in);
      grad.y = ( *(in+yp) - *(in+ym) + *(in+yp+xp) -*(in+ym+xp) )/ 4.0;
      grad.z = ( *(in+zp) - *(in+zm) + *(in+zp+xp)- *(in+zm+xp) )/ 4.0;

      // get vectors
      this->GetVectors(0,x,y,z,e0,e1,e2);

    switch ( contours_mode )
    {
    case CONTOURS_GRAD: 
        u_e0 = this->ScalarProduct(grad,e0);
        u_e1 = this->ScalarProduct(grad,e1);
        u_e2 = this->ScalarProduct(grad,e2);
        lambda0 = phi3D_0(u_e0); 
        lambda1 = phi3D_1(u_e1);
        lambda2 = phi3D_2(u_e2);
        break;
    case CONTOURS_SRAD:
    case CONTOURS_RNRAD:
        u_e1 = this->ScalarProduct(grad,e1);
        u_e2 = this->ScalarProduct(grad,e2);
        lambda0 = ( ( *image_c ) ( x,y,z ) + ( *image_c ) ( x+incx,y,z ) ) /2.0; 
        lambda1 = phi3D_1(u_e1);
        lambda2 = phi3D_2(u_e2);
        break;
    case CONTOURS_RNRAD_NEW:
        double mean,var;
        lambda0 = ( (*image_c)(x,y,z) + (*image_c)(x+incx,y,z) ) /2.0; 
  //      if (lambda0>2) lambda0=2;
        if (lambda0<1) {
          ComputeLocalPlanStats(im, (float)x+((float)incx)/2.0, (float) y, (float) z,  e1,e2, planstats_sigma, mean,var);
          lambda1 = function_c_MRI( sigma2, var, mean); 
          lambda1 *= 6./4.; // convert for 2D normalization
           switch (diffusion_eigenvalues_mode) {
           case DIFF_MATRIX_EIGEN_SUM:
              lambda1 = lambda0 + lambda1; 
              break;
           case DIFF_MATRIX_EIGEN_MAX:
              lambda1 = MAX(lambda0,lambda1); 
              break;
           }
        } else lambda1 = lambda0;
        if (lambda1<1) {
          ComputeLocalDirStats(im, (float)x+((float)incx)/2.0, (float) y, (float) z,  e2, dirstats_sigma, mean,var);
          lambda2 = function_c_MRI( sigma2, var, mean);
          lambda2 *= 6./2.; // convert for 1D normalization
           switch (diffusion_eigenvalues_mode) {
           case DIFF_MATRIX_EIGEN_SUM:
              lambda2 += lambda1;
              break;
           case DIFF_MATRIX_EIGEN_MAX:
              lambda2 = MAX(lambda1,lambda2);
              break;
           }
        } else lambda2 = lambda1;
        if (lambda1>1) lambda1=1;
        if (lambda2>1) lambda2=1;
        break;
    }
//    lambda2 = 0;

      alpha1_x = lambda0 *e0.x*e0.x + 
                 lambda1 *e1.x*e1.x +
                 lambda2 *e2.x*e2.x;

      gamma1_x = (grad.y*e0.y + grad.z*e0.z)* lambda0 *e0.x + 
                 (grad.y*e1.y + grad.z*e1.z)* lambda1 *e1.x +
                 (grad.y*e2.y + grad.z*e2.z)* lambda2 *e2.x;


      //----- Calcul de alpha1_y, gamma1_y 
   
      // Gradient en (x,y+1/2)
      grad.x = (*(in+xp)-*(in+xm)+*(in+xp+yp)-*(in+xm+yp))/4.0;
      grad.y =  *(in+yp) - *(in);
      grad.z = (*(in+zp)-*(in+zm)+*(in+zp+yp)-*(in+zm+yp))/4.0;

      this->GetVectors(1,x,y,z,e0,e1,e2);

    switch ( contours_mode )
    {
    case CONTOURS_GRAD: 
        // Derivees directionnelles
        u_e0 = this->ScalarProduct(grad,e0);
        u_e1 = this->ScalarProduct(grad,e1);
        u_e2 = this->ScalarProduct(grad,e2);
        lambda0 = phi3D_0(u_e0); 
        lambda1 = phi3D_1(u_e1);
        lambda2 = phi3D_2(u_e2);
        break;
    case CONTOURS_SRAD:
    case CONTOURS_RNRAD:
      // Derivees directionnelles
      u_e1 = this->ScalarProduct(grad,e1);
      u_e2 = this->ScalarProduct(grad,e2);
        lambda0 = ((*image_c)(x,y,z)+(*image_c)(x,y+incy,z))/2.0;
        lambda1 = phi3D_1(u_e1);
        lambda2 = phi3D_2(u_e2);
        break;
    case CONTOURS_RNRAD_NEW:
        double mean,var;
        lambda0 = ((*image_c)(x,y,z)+(*image_c)(x,y+incy,z))/2.0;
//        if (lambda0>2) lambda0=2;
        if (lambda0<1) {
          ComputeLocalPlanStats(im, (float)x, (float) y+((float)incy)/2.0, (float) z,  e1,e2, planstats_sigma, mean,var);
          lambda1 = function_c_MRI( sigma2, var, mean); 
          lambda1 *= 6./4.; // convert for 2D normalization
           switch (diffusion_eigenvalues_mode) {
           case DIFF_MATRIX_EIGEN_SUM:
              lambda1 += lambda0; 
              break;
           case DIFF_MATRIX_EIGEN_MAX:
              lambda1 = MAX(lambda0,lambda1); 
              break;
           }
        } else lambda1 = lambda0;
        if (lambda1<1) {
          ComputeLocalDirStats(im, (float)x, (float) y+((float)incy)/2.00, (float) z,  e2, dirstats_sigma, mean,var);
          lambda2 = function_c_MRI( sigma2, var, mean);
          lambda2 *= 6./2.; // convert for 1D normalization
           switch (diffusion_eigenvalues_mode) {
           case DIFF_MATRIX_EIGEN_SUM:
              lambda2 += lambda1;
              break;
           case DIFF_MATRIX_EIGEN_MAX:
              lambda2 = MAX(lambda1,lambda2);
              break;
           }
        } else lambda2 = lambda1;
        if (lambda1>1) lambda1=1;
        if (lambda2>1) lambda2=1;
        break;
    }

//    lambda2 = 0;

      alpha1_y = lambda0 *e0.y*e0.y + 
                 lambda1 *e1.y*e1.y +
                 lambda2 *e2.y*e2.y;

      gamma1_y = (grad.x*e0.x + grad.z*e0.z)* lambda0 *e0.y + 
                 (grad.x*e1.x + grad.z*e1.z)* lambda1 *e1.y +
                 (grad.x*e2.x + grad.z*e2.z)* lambda2 *e2.y;


      //----- Calcul de alpha1_z, gamma1_z 
      grad.x = (*(in+xp) - *(in+xm) + *(in+xp+zp) - *(in+xm+zp))/4.0;
      grad.y = (*(in+yp) - *(in+ym) + *(in+yp+zp) - *(in+ym+zp))/4.0; 
      grad.z = *(in+zp)-*in;

      this->GetVectors(2,x,y,z,e0,e1,e2);

    switch ( contours_mode )
    {
    case CONTOURS_GRAD: 
        // Derivees directionnelles
        u_e0 = this->ScalarProduct(grad,e0);
        u_e1 = this->ScalarProduct(grad,e1);
        u_e2 = this->ScalarProduct(grad,e2);
        lambda0 = phi3D_0(u_e0); 
        lambda1 = phi3D_1(u_e1);
        lambda2 = phi3D_2(u_e2);
        break;
    case CONTOURS_SRAD:
    case CONTOURS_RNRAD:
        // Derivees directionnelles
        u_e1 = this->ScalarProduct(grad,e1);
        u_e2 = this->ScalarProduct(grad,e2);
        lambda0 = ((*image_c)(x,y,z)+(*image_c)(x,y,z+incz))/2.0;
        lambda1 = phi3D_1(u_e1);
        lambda2 = phi3D_2(u_e2);
        break;
    case CONTOURS_RNRAD_NEW:
        double mean,var;
        lambda0 = ((*image_c)(x,y,z)+(*image_c)(x,y,z+incz))/2.0;
//        if (lambda0>2) lambda0=2;
        if (lambda0<1) {
          ComputeLocalPlanStats(im, (float)x, (float) y, (float) z+((float)incz)/2.0,  e1,e2, planstats_sigma, mean,var);
          lambda1 = function_c_MRI( sigma2, var, mean); 
          lambda1 *= 6./4.; // convert for 2D normalization
           switch (diffusion_eigenvalues_mode) {
           case DIFF_MATRIX_EIGEN_SUM:
              lambda1 += lambda0 ; 
              break;
           case DIFF_MATRIX_EIGEN_MAX:
              lambda1 = MAX(lambda0,lambda1); 
              break;
           }
        } else lambda1 = lambda0;
        if (lambda1<1) {
          ComputeLocalDirStats(im, (float)x, (float) y, (float) z+((float)incz)/2.0,  e2, dirstats_sigma, mean,var);
          lambda2 = function_c_MRI( sigma2, var, mean);
          lambda2 *= 6./2.; // convert for 1D normalization
           switch (diffusion_eigenvalues_mode) {
           case DIFF_MATRIX_EIGEN_SUM:
              lambda2 += lambda1;
              break;
           case DIFF_MATRIX_EIGEN_MAX:
              lambda2 = MAX(lambda1,lambda2);
              break;
           }
        } else lambda2 = lambda1;
        if (lambda1>1) lambda1=1;
        if (lambda2>1) lambda2=1;
        break;
    }

//    lambda2 = 0;

      alpha1_z = lambda0 *e0.z*e0.z + 
                 lambda1 *e1.z*e1.z +
                 lambda2 *e2.z*e2.z;

      gamma1_z = (grad.x*e0.x + grad.y*e0.y) * lambda0 *e0.z + 
                 (grad.x*e1.x + grad.y*e1.y) * lambda1 *e1.z +
                 (grad.x*e2.x + grad.y*e2.y) * lambda2 *e2.z;

     } // speedup_skip
      //----- Mise a jour de l'image

      val1    =  0;
      val1div =  0;


      val1    += alpha1_x    * (*(in+xp  )) +
                 alpha_x     * (*(in+xm  )) +
                 gamma1_x  - gamma_x;

      val1div += alpha1_x + alpha_x;


      val1    += alpha1_y     * (*(in+yp )) +
                 alpha_y[x]   * (*(in+ym )) +
                 gamma1_y  - gamma_y[x];

      val1div += alpha1_y + alpha_y[x];


      val1    += alpha1_z      * (*(in+zp  )) +
                 alpha_z[x][y] * (*(in+zm  )) +
                 gamma1_z  - gamma_z[x][y];

      val1div += alpha1_z + alpha_z[x][y];


    switch ( noise_type )
    {
    case GAUSSIAN_NOISE:
        if ( mask_test )
        {
            divF = ( val1 - *in * val1div ) * ( *in- ( *image_entree ) ( x,y,z ) );
            sum_divF += divF;
            nb_calculated_points++;
        }
    

        val1    += this->beta* ( *image_entree ) ( x,y,z );
        val1div += this->beta;
    
        switch ( contours_mode )
        {
            case CONTOURS_GRAD:
                Si fabsf ( val1div ) >1E-4 Alors
                val1 /= val1div;
                Sinon
                fprintf ( stderr,"AnisoGaussSeidel.c:Itere3D() \t fabsf(val1div)<1E-4 \n" );
                FinSi
                break;
            case CONTOURS_SRAD:
            case CONTOURS_RNRAD:
            case CONTOURS_RNRAD_NEW:
                val1 = ( *in + dt*val1 ) / ( 1+dt*val1div );
                break;
        }
    
        break;
    
    case SPECKLE_NOISE:
        u0 = ( *image_entree ) ( x,y,z );
        u  = *in;
    
        if ( mask_test&& ( fabsf ( u+u0 ) >1E-4 ) && ( u>1 ) && ( u0>1 ) )
        {
            divF = ( val1 - u * val1div ) * ( u-u0 ) / ( u+u0 ) *u;
            /*
            if (divF<-1000) {
              printf("val1 %03.1f, u %03.1f, val1div %03.1f, u0  %03.1f --> divF  %03.1f\n",
                 val1,u,val1div,u0,divF);
            }
            */
            sum_divF += divF;
            nb_calculated_points++;
        }
        else
            divF = 0;
    
        if ( ( u>1 ) && ( u0>1 ) )
        {
            //
            // See if we can get a more implicit scheme
            // by solving a 3rd order equation:
            //
    #ifdef IMPLICIT
            double w[3];
            int nb_solutions;
            Solve3rdOrder ( val1div,- ( val1-this->beta ),
                            -this->beta* ( u0*u0 ),w,nb_solutions );
            if ( nb_solutions==1 )
                val1_implicit = w[0];
            else
            {
                /*
                printf(" 3rd order equation %d solutions %3.2f %3.2f %3.2f \n",
                   nb_solutions,w[0],w[1],w[2]);
                */
                if ( w[0] >=0 ) val1_implicit = w[0];
                else
                    if ( w[1] >=0 ) val1_implicit = w[1];
                    else
                        if ( w[2] >=0 ) val1_implicit = w[2];
            }
            val1=val1_implicit;
    #else
            val1  += beta* ( ( u0*u0 ) / ( u*u )-1 );
            Si fabsf ( val1div ) >1E-4 Alors
            val1 /= val1div;
            Sinon
            fprintf ( stderr,"AnisoGaussSeidel.c:Itere3D() \t fabsf(val1div)<1E-4 \n" );
            FinSi
    #endif
        }
    
        break;
    } // switch noise type

      if (fabsf(val1-*in)<0.1) {
        sum_divF2 += divF;
        nb_calculated_points2++;
      }

      if (divFim!=NULL) {
    divFim->BufferPos(x,y,z);
    divFim->FixeValeur(divF);
      }


      alpha_z[x][y] = alpha1_z;
      alpha_y[x]    = alpha1_y;
      alpha_x       = alpha1_x;

      gamma_z[x][y] = gamma1_z;
      gamma_y[x]    = gamma1_y;
      gamma_x       = gamma1_x;

/*
    Sinon

      val1 = *in;
    
      alpha_z[x][y] = 
      alpha_y[x]    = 
      alpha_x       = 
      gamma_z[x][y] = 
      gamma_y[x]    = 
      gamma_x       = 0;

    FinSi
*/

    Si fabsf(val1-val0) > epsilon Alors
      nb_points_instables++;
    FinSi

    diff += (val1-val0)*(val1-val0);
    Si fabsf(val1-val0) > erreur Alors
      erreur = fabsf(val1-val0);
      erreur_x = x;
      erreur_y = y;
      erreur_z = z;
    FinSi

    this->im_tmp->BufferPos(x,y,z);

    if (val1<min_intensity) {
      //      fprintf(stderr,"I=%3.2f<min, (%3d,%3d,%3d) \n",val1,x,y,z);
      val1=min_intensity;
    }
    if (val1>max_intensity) {
      //      fprintf(stderr,"I=%3.2f<max, (%3d,%3d,%3d) \n",val1,x,y,z);
      val1=max_intensity;
    }

    this->im_tmp->FixeValeur(val1);

    in++;
    Iconv++;

  FinPour
  FinPour
  FinPour

  // backup previous image in image_c
  ExtendBoundariesVonNeumann(im_tmp);
  (*image_c) = (*im);
  (*im) = (*this->im_tmp);

  printf(" speedup %3.3f %% \n",speedup_counter/(1.0*txy*tz)*100.0);

/*
  cout << endl;
  cout << " Erreur = " << erreur << endl;
  cout << "( " << erreur_x << ", " 
               << erreur_y << ", " 
               << erreur_z << " )" << endl; 
  cout << "nb de points variables " << nb_points_instables << endl;
*/
  diff /= txy*tz;

  cout << "\t diff =" << sqrt(diff) << "\t";

  if (noise_standard_deviation <0) {
/*    fprintf(stderr,"noise SD <0 ?\n");
    estimated_DA_coeff = sum_divF/(1.0*nb_calculated_points);
    fprintf(stderr,"lambda estimation for noise/sigma_noise^2 = %f \n", 
        estimated_DA_coeff);
*/
  }
  else {
    estimated_DA_coeff =sum_divF/(1.0*nb_calculated_points)/this->variance;
    fprintf(stderr,"sum_divF=%3.2f, nb_calculated_points = %5d, variance = %3.3f, \n ===  lambda estimation for noise = %f \n", 
        sum_divF,(int)nb_calculated_points,this->variance, estimated_DA_coeff);

      if ((noise_SD_preset)&&(estimated_DA_coeff>0))
    this->beta = estimated_DA_coeff;
      fprintf(stderr, "\n  Setting beta to %2.2f \n\n",beta);

    estimated_DA_coeff =sum_divF2/(1.0*nb_calculated_points2)/this->variance;
    fprintf(stderr,
        " ===  lambda2 estimation for noise = %f, %02.2f percent of points \n", 
        estimated_DA_coeff,
        (nb_calculated_points2*100.0/nb_calculated_points));

    /*
    // set to the 2nd estimation
    if ( (nb_calculated_points2*100.0/nb_calculated_points) > 80 ) {
      if ((noise_SD_preset)&&(estimated_DA_coeff>0))
    this->beta = estimated_DA_coeff;
      fprintf(stderr, "\n  Setting beta to %2.2f \n\n",beta);
    }
    */
  }

  divFname = (boost::format("divF_%03d.ami.gz") % iteration).str();
//divFim->Sauve(divFname);


  return erreur;

} // AnisoGS::Itere3D_ST_RNRAD()



//----------------------------------------------------------------------
// Euclidian distance approximation
//
// 
//
float AnisoGS::Itere3D_distance( InrImage* im )
//
{

   
    int x,y,z; //,n,i;
    float   val0,val1;
    float*  in;
//    register float    *Iconv; 

    float   erreur,norm_grad;
    double diff;
    int nb_points_instables;
    int erreur_x=0,erreur_y=0,erreur_z=0;

    // Sum over all the points
    long int  nb_calculated_points;

    // Sum over the points that don't evolve too much
    long int  nb_calculated_points2;

    float     u=0,u0;

    unsigned char mask_test;

//    t_Gradient grad;

double laplacian, meancurv=0;
double dx,dy,dz,dxx,dyy,dzz,dxy,dxz,dyz;
double norm_grad2,dx2,dy2,dz2;

//double Dx,Dy,Dz;

int xp,xm,yp,ym,zp,zm;

  Si this->im_tmp == NULL AlorsFait
    this->im_tmp = new InrImage(WT_FLOAT, "im_tmp.inr.gz", im);

  im->InitBuffer();
  erreur = 0;
  nb_points_instables = 0;
  in = (float*) im->Buffer();

  diff = 0;

  nb_calculated_points = 0;
  nb_calculated_points2 = 0;

  Pour(z,0,tz-1)
    Si z==0 Alors
      printf("z = %3d",z);
      fflush(stdout);
    Sinon 
      printf("\b\b\b");
      printf("%3d",z);
      fflush(stdout);
    FinSi
  Pour(y,0,ty-1)
  Pour(x,0,tx-1)
  
    val1 = val0 = *in;
    mask_test = (mask==NULL)||((mask!=NULL)&&((*mask)(x,y,z)>0.5));

    Si x>0 Et x<tx-1 Et y>0 Et y<ty-1 Et z>0 Et z<tz-1 Et fabs(*in)<4-1E-3
    Alors

    xp=1;
    xm=-1;
    yp=tx;
    ym=-tx;
    zp=txy;
    zm=-txy;

    // Different way to calculate the evolution
    // laplacian-curvature

    //
    dxx = *(in+xp) -2*(*in)+*(in+xm);
    dyy = *(in+yp) -2*(*in)+*(in+ym);
    dzz = *(in+zp) -2*(*in)+*(in+zm);

    laplacian = dxx+dyy+dzz;

    dx = (*(in+xp) -*(in+xm))/2.0;
    dy = (*(in+yp) -*(in+ym))/2.0;
    dz = (*(in+zp) -*(in+zm))/2.0;

    dx2=dx*dx;
    dy2=dy*dy;
    dz2=dz*dz;

    dxy = ((*(in+1 +tx )-*(in-1 +tx ))-(*(in+1 -tx )-*(in- 1-tx )))/4.0;
    dxz = ((*(in+1 +txy)-*(in-1 +txy))-(*(in+1 -txy)-*(in- 1-txy)))/4.0;
    dyz = ((*(in+tx+txy)-*(in-tx+txy))-(*(in+tx-txy)-*(in-tx-txy)))/4.0;

    norm_grad2 = dx*dx+dy*dy+dz*dz;
    norm_grad=sqrt(norm_grad2);

    if (norm_grad2>1E-3) {
      meancurv= 0.5*((dyy+dzz)*dx2+(dxx+dzz)*dy2+(dxx+dyy)*dz2)-
	(dx*dy*dxy+dy*dz*dyz+dx*dz*dxz);
      meancurv/=norm_grad2/norm_grad;
    }


/*
if (*in>0)
  val1 = *in + 0.05*(1-norm_grad);
else
  val1 = *in - 0.05*(1-norm_grad);
  //
  */


  /*
Dx=0;
if (fabs(*(in+1)-*in  )>Dx) Dx=fabs(*(in+1)-*in);
if (fabs(*(in)-*(in-1))>Dx) Dx=fabs(*(in)-*(in-1));

Dy=0;
if (fabs(*(in+tx)-*in)>Dy) Dy=fabs(*(in+tx)-*in);
if (fabs(*(in)-*(in-tx))>Dy) Dy=fabs(*(in)-*(in-tx));

Dz=0;
if (fabs(*(in+txy)-*in)>Dz) Dz=fabs(*(in+txy)-*in);
if (fabs(*(in)-*(in-txy))>Dz) Dz=fabs(*(in)-*(in-txy));


if (Dx*Dx+Dy*Dy+Dz*Dz>1) {
//if (norm_grad2>1) {
   if (fabs(meancurv)<1) val1=*in+0.05*meancurv;
}   else {
      if (fabs(meancurv)<1) val1=*in-0.05*meancurv;
}


//       val1  += 0.02*(laplacian+meancurv);
//       val1 = *in + 0.05*(laplacian+meancurv);
*/

      // semi-implit scheme
      if (meancurv>6) meancurv=6;
      if (meancurv<-6) meancurv=-6;

u0 = (*image_entree)(x,y,z);

/*
if ((u0<0.5)&&(u0>-0.5)) {
  val1 = (*(in+xp)+*(in+xm)+*(in+yp)+*(in+ym)+*(in+zp)+*(in+zm)-meancurv+beta*u0)/(6.0+beta);
}
else

  val1 = (*(in+xp)+*(in+xm)+*(in+yp)+*(in+ym)+*(in+zp)+*(in+zm)-meancurv)/6.0;
*/
if ((u0<0.5)&&(u0>-0.5)) {
val1 = *in + 0.1*(dxx+dyy+dzz-meancurv+beta*(u0-u));
}
else
val1 = *in + 0.1*(dxx+dyy+dzz-meancurv);

      if (fabsf(val1-*in)<0.1) {
        nb_calculated_points2++;
      }

    Sinon

      val1 = *in;
    
    FinSi


    Si fabsf(val1-val0) > epsilon Alors
      nb_points_instables++;
    FinSi

    diff += (val1-val0)*(val1-val0);
    Si fabsf(val1-val0) > erreur Alors
      erreur = fabsf(val1-val0);
      erreur_x = x;
      erreur_y = y;
      erreur_z = z;
    FinSi

    this->im_tmp->BufferPos(x,y,z);


    this->im_tmp->FixeValeur(val1);

    in++;

  FinPour
  FinPour
  FinPour

  (*im) = (*this->im_tmp);

  cout << endl;
  cout << " Erreur = " << erreur << endl;
  cout << "( " << erreur_x << ", " 
               << erreur_y << ", " 
               << erreur_z << " )" << endl; 
  cout << "nb de points variables " << nb_points_instables << endl;

  cout << "diff =" << sqrt(diff) << endl;

  return erreur;

} // AnisoGS::Itere3D_distance()


//----------------------------------------------------------------------
// Euclidian distance approximation
//
// 
//
float AnisoGS::Itere3D_distance_flux( InrImage* im )
//
{

   
    int x,y,z; //,n,i;
    float   val0,val1;
//    float   val1_implicit;
    float   val1div;
    float   alpha1_x;
    float   alpha1_y;
    float   alpha1_z;
    float*  in;
//    register float    *Iconv; 

    float   erreur,norm_grad;
    double diff;
    int nb_points_instables;
    int erreur_x=0,erreur_y=0,erreur_z=0;

    // Sum over all the points
    float     sum_divF;
    long int  nb_calculated_points;

    // Sum over the points that don't evolve too much
    float     sum_divF2;
    long int  nb_calculated_points2;

//    float     u,u0;
    float     divF=0;
    std::string     divFname;

    unsigned char mask_test;

    t_Gradient grad;

//double norm_grad2,dx2,dy2,dz2;

//double Dx,Dy,Dz;

int xp,xm,yp,ym,zp,zm;
double maxerr=0.5;

  ResetCoefficients();
  Si this->im_tmp == NULL AlorsFait
    this->im_tmp = new InrImage(WT_FLOAT, "im_tmp.inr.gz", im);
  Si divFim == NULL Alors
    divFim = new InrImage(WT_FLOAT, divFname.c_str() , im);
  FinSi

  divFim->InitImage(0);
  im->InitBuffer();
  erreur = 0;
  nb_points_instables = 0;
  in = (float*) im->Buffer();

  diff = 0;

  nb_calculated_points = 0;
  sum_divF = 0;

  nb_calculated_points2 = 0;
  sum_divF2 = 0;

  Pour(z,0,tz-1)
    Si z==0 Alors
      printf("z = %3d",z);
      fflush(stdout);
    Sinon 
      printf("\b\b\b");
      printf("%3d",z);
      fflush(stdout);
    FinSi
  Pour(y,0,ty-1)
  Pour(x,0,tx-1)
  
    val1 = val0 = *in;
    mask_test = (mask==NULL)||((mask!=NULL)&&((*mask)(x,y,z)>0.5));

    Si x>0 Et x<tx-1 Et y>0 Et y<ty-1 Et z>0 Et z<tz-1 
    // Et fabs(*in)<4-1E-3
    Alors

    xp=1;
    xm=-1;
    yp=tx;
    ym=-tx;
    zp=txy;
    zm=-txy;



    // Gradient en (x+1/2,y,z)
    //----- Calcul de alpha1_x, gamma1_x
if ((fabs(*in)<3.99)&&(fabs(*(in+1))<3.99)) {
    grad.x = *(in+1) - *(in);
    grad.y = ( *(in + tx) - *(in - tx) + *(in+tx+1) - *(in-tx+1) )/ 4.0;
    grad.z = (*(in+txy)   - *(in-txy  )+ *(in+txy+1)- *(in-txy+1))/ 4.0;

    // Derivees directionnelles
    norm_grad=sqrt(grad.x*grad.x+grad.y*grad.y+grad.z*grad.z);


    if (norm_grad<1-maxerr) norm_grad=1-maxerr;
    if (norm_grad>1+maxerr) norm_grad=1+maxerr;
    alpha1_x = (norm_grad-1)/norm_grad;
    alpha1_x=1;
}
else
alpha1_x = 0;


    //----- Calcul de alpha1_y, gamma1_y 
   
if ((fabs(*in)<3.99)&&(fabs(*(in+tx))<3.99)) {
    // Gradient en (x,y+1/2)
    grad.x = (*(in   +1)-*(in   -1)+*(in   +1+tx)-*(in   -1+tx))/4.0;
    grad.y = *(in   +tx) - *(in);
    grad.z = (*(in   +txy)-*(in   -txy)+*(in   +txy+tx)-*(in   -txy+tx))/4.0;

    // Derivees directionnelles
    norm_grad = sqrt(grad.x*grad.x+grad.y*grad.y+grad.z*grad.z);

    if (norm_grad<1-maxerr) norm_grad=1-maxerr;
    if (norm_grad>1+maxerr) norm_grad=1+maxerr;
    alpha1_y = (norm_grad-1)/norm_grad;
    alpha1_y=1;
}
else
alpha1_y = 0;


    //----- Calcul de alpha1_z, gamma1_z 
if ((fabs(*in)<3.99)&&(fabs(*(in+txy))<3.99)) {
    grad.x = (*(in+1 ) - *(in-1 ) + *(in+1 +txy) - *(in-1 +txy))/4.0;
    grad.y = (*(in+tx) - *(in-tx) + *(in+tx+txy) - *(in-tx+txy))/4.0; 
    grad.z = *(in+txy)-*in;

    norm_grad = sqrt(grad.x*grad.x+grad.y*grad.y+grad.z*grad.z);
      
    if (norm_grad<1-maxerr) norm_grad=1-maxerr;
    if (norm_grad>1+maxerr) norm_grad=1+maxerr;
    alpha1_z = (norm_grad-1)/norm_grad;
    alpha1_z=1;
}
else
alpha1_z = 0;


    //----- Mise a jour de l'image

    val1    =  0;
    val1div =  0;

    val1    += alpha1_x    * (*(in+1  )) +  alpha_x     * (*(in-1  )) ;
    val1div += alpha1_x + alpha_x;

    val1    += alpha1_y    * (*(in+tx )) +  alpha_y[x]   * (*(in-tx ));
    val1div += alpha1_y + alpha_y[x];

    val1    += alpha1_z    * (*(in+txy)) +  alpha_z[x][y] * (*(in-txy  ));
    val1div += alpha1_z + alpha_z[x][y];


      val1    += this->beta*(*image_entree)(x,y,z);
      val1div += this->beta;
	 
//      Si fabsf(val1div)>1E-3 Alors
      //val1 /=val1div;
      val1 = *in + 0.05*(val1-val1div*(*in));
//      Sinon
//         fprintf(stderr,"AnisoGaussSeidel.c:Itere3D() \t fabsf(val1div)<1E-4 \n");
//      FinSi


      if (fabsf(val1-*in)<0.1) {
        nb_calculated_points2++;
      }

      if (divFim!=NULL) {
	divFim->BufferPos(x,y,z);
	divFim->FixeValeur(divF);
      }


      alpha_z[x][y] = alpha1_z;
      alpha_y[x]    = alpha1_y;
      alpha_x       = alpha1_x;

    Sinon

      val1 = *in;
    
      alpha_z[x][y] = 
      alpha_y[x]    = 
      alpha_x       = 0;

    FinSi


    Si fabsf(val1-val0) > epsilon Alors
      nb_points_instables++;
    FinSi

    diff += (val1-val0)*(val1-val0);
    Si fabsf(val1-val0) > erreur Alors
      erreur = fabsf(val1-val0);
      erreur_x = x;
      erreur_y = y;
      erreur_z = z;
    FinSi

    this->im_tmp->BufferPos(x,y,z);


    this->im_tmp->FixeValeur(val1);

    in++;

  FinPour
  FinPour
  FinPour

  (*im) = (*this->im_tmp);

  cout << endl;
  cout << " Erreur = " << erreur << endl;
  cout << "( " << erreur_x << ", " 
               << erreur_y << ", " 
               << erreur_z << " )" << endl; 
  cout << "nb de points variables " << nb_points_instables << endl;

  cout << "diff =" << sqrt(diff) << endl;

  return erreur;

} // AnisoGS::Itere3D_distance_flux()




//----------------------------------------------------------------------
// using minimal and maximal curvature directions
//
float AnisoGS::Itere3D_Flux( InrImage* im , InrImage* VectField, float coeff)
//
{

   
    int x,y,z; //,n,i;
    float   val0,val1;
    float   val1div;
    float   u_e0;
    float   alpha1_x, gamma1_x;
    float   alpha1_y, gamma1_y;
    float   alpha1_z, gamma1_z;
    float*  in;

    Vect3D<float> e0;
    t_Gradient grad;

    float   erreur; //,norm_grad;
    double diff;
    int nb_points_instables;
    int erreur_x=0,erreur_y=0,erreur_z=0;
    unsigned char weak_norm=0;


  ResetCoefficients();
  Si this->im_tmp == NULL AlorsFait
    this->im_tmp = new InrImage(WT_FLOAT, "im_tmp.inr.gz", im);

  im->InitBuffer();

  erreur = 0;

  nb_points_instables = 0;

  in   = (float*) im->Buffer();

  diff = 0;

  Pour(z,0,tz-1)

     /*
    Si z==0 Alors
      printf("z = %3d",z);
      fflush(stdout);
    Sinon 
      printf("\b\b\b");
      printf("%3d",z);
      fflush(stdout);
    FinSi
     */

  Pour(y,0,ty-1)
  Pour(x,0,tx-1)
  

    val1 = val0 = *in;

    Si x>0 Et x<tx-1 Et y>0 Et y<ty-1 Et z>0 Et z<tz-1 Alors

      // Gradient en (x+1/2,y,z)
      //----- Calcul de alpha1_x, gamma1_x
      grad.x = *(in+1) - *(in);
      grad.y = ( *(in + tx) - *(in - tx) + *(in+tx+1) - *(in-tx+1) )/ 4.0;
      grad.z = (*(in+txy)   - *(in-txy  )+ *(in+txy+1)- *(in-txy+1))/ 4.0;


      e0.x = ((*VectField)(x,y,z,0)+(*VectField)(x+1,y,z,0));
      e0.y = ((*VectField)(x,y,z,1)+(*VectField)(x+1,y,z,1));
      e0.z = ((*VectField)(x,y,z,2)+(*VectField)(x+1,y,z,2));
      try {
        e0.Normalise();
      } catch (NormeFaible) {
	weak_norm = true;
      }

      Si Non(weak_norm) Alors
        // Derivees directionnelles
        u_e0 = grad.x*e0.x + grad.y*e0.y + grad.z*e0.z;
        alpha1_x = coeff*e0.x*e0.x; 
        gamma1_x = (grad.y*e0.y + grad.z*e0.z)*coeff*e0.x;
      Sinon
        alpha1_x = 0;
        gamma1_x = 0;
      FinSi

      //----- Calcul de alpha1_y, gamma1_y 
   
      // Gradient en (x,y+1/2)
      grad.x = (*(in   +1)-*(in   -1)+*(in   +1+tx)-*(in   -1+tx))/4.0;
      grad.y = *(in   +tx) - *(in);
      grad.z = (*(in   +txy)-*(in   -txy)+*(in   +txy+tx)-*(in   -txy+tx))/4.0;

      e0.x = ((*VectField)(x,y,z,0)+(*VectField)(x,y+1,z,0));
      e0.y = ((*VectField)(x,y,z,1)+(*VectField)(x,y+1,z,1));
      e0.z = ((*VectField)(x,y,z,2)+(*VectField)(x,y+1,z,2));
      try {
        e0.Normalise();
      } catch (NormeFaible) {
	weak_norm = true;
      }
 
      Si Non(weak_norm) Alors
        // Derivees directionnelles
        u_e0 = grad.x*e0.x + grad.y*e0.y + grad.z*e0.z;
        alpha1_y = coeff*e0.y*e0.y;
        gamma1_y = (grad.x*e0.x + grad.z*e0.z)*coeff*e0.y;
      Sinon
        alpha1_y = 0;
        gamma1_y = 0;
      FinSi

      //----- Calcul de alpha1_z, gamma1_z 
      grad.x = (*(in+1 ) - *(in-1 ) + *(in+1 +txy) - *(in-1 +txy))/4.0;
      grad.y = (*(in+tx) - *(in-tx) + *(in+tx+txy) - *(in-tx+txy))/4.0; 
      grad.z = *(in+txy)-*in;

      e0.x = ((*VectField)(x,y,z,0)+(*VectField)(x,y,z+1,0));
      e0.y = ((*VectField)(x,y,z,1)+(*VectField)(x,y,z+1,1));
      e0.z = ((*VectField)(x,y,z,2)+(*VectField)(x,y,z+1,2));
      try {
        e0.Normalise();
      } catch (NormeFaible) {
	weak_norm = true;
      }

      Si Non(weak_norm) Alors
        // Derivees directionnelles
        u_e0 = grad.x*e0.x + grad.y*e0.y + grad.z*e0.z;
        alpha1_z = coeff*e0.z*e0.z;
        gamma1_z = (grad.x*e0.x + grad.y*e0.y)*coeff*e0.z;
      Sinon
        alpha1_z = 0;
        gamma1_z = 0;
      FinSi


      //----- Mise a jour de l'image

      val1    =  beta*(*image_entree)(x,y,z);
      val1div =  beta;

      val1    += alpha1_x    * (*(in+1  )) +
                 alpha_x     * (*(in-1  )) +
                 gamma1_x  - gamma_x;

      val1div += alpha1_x + alpha_x;

      val1    += alpha1_y     * (*(in+tx )) +
                 alpha_y[x]   * (*(in-tx )) +
                 gamma1_y  - gamma_y[x];

      val1div += alpha1_y + alpha_y[x];

      val1    += alpha1_z      * (*(in+txy  )) +
                 alpha_z[x][y] * (*(in-txy  )) +
                 gamma1_z  - gamma_z[x][y];

      val1div += alpha1_z + alpha_z[x][y];

      Si fabsf(val1div)>1E-4 Alors
        val1 /= val1div;
      Sinon
        fprintf(stderr,"AnisoGaussSeidel.c:Itere3D() \t fabsf(val1div)<1E-4 \n");
      FinSi

      alpha_z[x][y] = alpha1_z;
      alpha_y[x]    = alpha1_y;
      alpha_x       = alpha1_x;

      gamma_z[x][y] = gamma1_z;
      gamma_y[x]    = gamma1_y;
      gamma_x       = gamma1_x;

    Sinon

      val1 = *in;
    
      alpha_z[x][y] = 
      alpha_y[x]    = 
      alpha_x       = 
      gamma_z[x][y] = 
      gamma_y[x]    = 
      gamma_x       = 0;

    FinSi


    Si fabsf(val1-val0) > epsilon Alors
      nb_points_instables++;
    FinSi

    diff += (val1-val0)*(val1-val0);
    Si fabsf(val1-val0) > erreur Alors
      erreur = fabsf(val1-val0);
      erreur_x = x;
      erreur_y = y;
      erreur_z = z;
    FinSi

    this->im_tmp->BufferPos(x,y,z);
    this->im_tmp->FixeValeur(val1);

    in++;

  FinPour
  FinPour
  FinPour

  (*im) = (*this->im_tmp);

  cout << endl;
  cout << " Erreur = " << erreur << endl;
  cout << "( " << erreur_x << ", " 
               << erreur_y << ", " 
               << erreur_z << " )" << endl; 
  cout << "nb de points variables " << nb_points_instables << endl;

  diff /= txy*tz;

  cout << "diff =" << sqrt(diff) << endl;

  return erreur;

} // AnisoGS::Itere3D_Flux()



//----------------------------------------------------------------------
// using minimal and maximal curvature directions
//
// discretization u_x(x+dx/2) = 1/4 (u(x+2*dx)-u(x)+u(x+dx)-u(x-dx))
//
float  AnisoGS::Itere3D_3( InrImage* im )
//
{

   
    int x,y,z; //,n,i;
    double   val0,val1;
    double   val1div;
    double   u_e0;
    double   u_e1;
    double   u_e2;
    double   alpha1_x, gamma1_x;
    double   alpha1_y, gamma1_y;
    double   alpha1_z, gamma1_z;
    float*  in;
    register float    *Iconv; 
    float gradient[3];
    float hessien[3][3];
//    float vmax[3];
//    float vmin[3];
//    float lmin;
//    float lmax;

    t_3Point e0;
    t_3Point e1;
    t_3Point e2;

    t_Gradient grad;

    float   erreur,norm_grad;
    double diff;
    int nb_points_instables;
    int erreur_x=0,erreur_y=0,erreur_z=0;


  ResetCoefficients();
  Si this->im_tmp == NULL AlorsFait
    this->im_tmp = new InrImage(WT_FLOAT, "im_tmp.inr.gz", im);

  im->InitBuffer();

  erreur = 0;

  nb_points_instables = 0;

  in = (float*) im->Buffer();

  Si use_filtre_rec Alors
    (*this->image_lissee) = (*im);
    filtre_rec->Filtre(sigma,5);
  Sinon
    filtre->MyFiltre( im, this->image_lissee,           0, -1, -1);
    filtre->MyFiltre( this->image_lissee, this->image_lissee, -1, 0, -1);
    filtre->MyFiltre( this->image_lissee, this->image_lissee, -1, -1, 0);
  FinSi

  Iconv = (float*) this->image_lissee->Buffer();  

  diff = 0;

  Pour(z,0,tz-1)

    Si z==0 Alors
      printf("z = %3d",z);
      fflush(stdout);
    Sinon 
      printf("\b\b\b");
      printf("%3d",z);
      fflush(stdout);
    FinSi

  Pour(y,0,ty-1)
  Pour(x,0,tx-1)
  

    val1 = val0 = *in;

    Si x>1 Et x<tx-2 Et y>1 Et y<ty-2 Et z>1 Et z<tz-2 Alors

      // Gradient en (x+1/2,y,z)
      //----- Calcul de alpha1_x, gamma1_x
      grad.x = (*(in+2)-*(in-1))/8.0+ (*(in+1)- *in)*3.0/8.0;
      grad.y = ( *(in + tx) - *(in - tx) + *(in+tx+1) - *(in-tx+1) )/ 4.0;
      grad.z = (*(in+txy)   - *(in-txy  )+ *(in+txy+1)- *(in-txy+1))/ 4.0;

      // Calcul du gradient, du hessien en (x+1/2,y,z)
      gradient[0] = (*(Iconv+2)-*(Iconv) + *(Iconv+1) - *(Iconv-1))/4.0;
      gradient[1] = ((*(Iconv+tx )-*(Iconv-tx ))+(*(Iconv+tx+1 )-*(Iconv-tx+1 )))/4.0;
      gradient[2] = ((*(Iconv+txy)-*(Iconv-txy))+(*(Iconv+txy+1)-*(Iconv-txy+1)))/4.0;

      hessien[0][0] = ((*(Iconv+2)-*Iconv)-(*(Iconv+1)-*(Iconv-1)))/2.0;
      hessien[1][0] = 
      hessien[0][1] = ((*(Iconv+1+tx)-*(Iconv+tx))-(*(Iconv+1-tx)-*(Iconv-tx)))/2.0;
      hessien[2][0] = 
      hessien[0][2] = ((*(Iconv+1+txy)-*(Iconv+txy))-(*(Iconv+1-txy)-*(Iconv-txy)))/2.0;
      hessien[1][1] = (*(Iconv+tx) - 2*(*Iconv) + *(Iconv-tx));
      hessien[2][1] = 
      hessien[1][2] = ( (*(Iconv+tx+txy)-*(Iconv-tx+txy)) -
                          (*(Iconv+tx-txy)-*(Iconv-tx-txy))  )/4.0;
      hessien[2][2] = (*(Iconv+txy) - 2*(*Iconv) + *(Iconv-txy));

      // Courbures principales
      norm_grad =  this->Norm(gradient);
      InitFlux(e0,e1,e2);

      Si norm_grad > 0.1 Alors
        // Calcul de la base (e0, e1, e2):
        this->PrincipalCurvatures(gradient,hessien,norm_grad,e0,e1,e2);
      FinSi

      // Derivees directionnelles
      u_e0 = this->ScalarProduct(grad,e0);
      u_e1 = this->ScalarProduct(grad,e1);
      u_e2 = this->ScalarProduct(grad,e2);

      alpha1_x = 3.0/8.0*(phi3D_0(u_e0)*e0.x*e0.x + 
			  phi3D_1(u_e1)*e1.x*e1.x +
			  phi3D_2(u_e2)*e2.x*e2.x );

      gamma1_x = ((*(in+2)-*(in-1))/8.0*e0.x+grad.y*e0.y + grad.z*e0.z)
                 *phi3D_0(u_e0)*e0.x + 
                 ((*(in+2)-*(in-1))/8.0*e1.x+grad.y*e1.y + grad.z*e1.z)
                 *phi3D_1(u_e1)*e1.x +
                 ((*(in+2)-*(in-1))/8.0*e2.x+grad.y*e2.y + grad.z*e2.z)
                 *phi3D_2(u_e2)*e2.x;


      //----- Calcul de alpha1_y, gamma1_y 
   
      // Gradient en (x,y+1/2)
      grad.x = (*(in   +1)-*(in   -1)+*(in   +1+tx)-*(in   -1+tx))/4.0;
//      grad.y = (-*in + *(in+tx));
      grad.y = (*(in+2*tx)-*(in-tx))/8.0+(*(in+tx)-*in)*3.0/8.0;
      grad.z = (*(in   +txy)-*(in   -txy)+*(in   +txy+tx)-*(in   -txy+tx))/4.0;

      // Calcul du gradient, du hessien en (x,y+1/2,z)
      gradient[0] = ((*(Iconv+1)-*(Iconv-1))+(*(Iconv+1+tx)-*(Iconv-1+tx)))/4.0;
      gradient[1] = (*(Iconv+2*tx)-*(Iconv)+*(Iconv+tx)-*(Iconv-tx))/4.0;
      gradient[2] = ((*(Iconv+txy)-*(Iconv-txy))+(*(Iconv+txy+tx)-*(Iconv-txy+tx)))/4.0;

      hessien[0][0] = (*(Iconv+1)-2*(*Iconv)+*(Iconv-1));
      hessien[1][0] = 
      hessien[0][1] = ((*(Iconv+1+tx)-*(Iconv-1+tx))-(*(Iconv+1)-*(Iconv-1)))/2.0;
      hessien[2][0] = 
      hessien[0][2] = ((*(Iconv+1+txy)-*(Iconv-1+txy))-
                         (*(Iconv+1-txy)-*(Iconv-1-txy)) )/4.0;
      hessien[1][1] = ((*(Iconv+2*tx) - (*Iconv)) - (*(Iconv+tx)-*(Iconv-tx)))/2.0;
      hessien[2][1] = 
      hessien[1][2] = ( (*(Iconv+tx+txy)-*(Iconv+txy)) -
                        (*(Iconv+tx-txy)-*(Iconv-txy))  )/2.0;
      hessien[2][2] = (*(Iconv+txy) - 2*(*Iconv) + *(Iconv-txy));

      // Courbures principales
      norm_grad =  this->Norm(gradient);
      InitFlux(e0,e1,e2);

      Si norm_grad > 0.1 Alors
        // Calcul de la base (e0, e1, e2):
        this->PrincipalCurvatures(gradient,hessien,norm_grad,e0,e1,e2);
      FinSi

      // Derivees directionnelles
      u_e0 = this->ScalarProduct(grad,e0);
      u_e1 = this->ScalarProduct(grad,e1);
      u_e2 = this->ScalarProduct(grad,e2);

      alpha1_y = 3.0/8.0*(phi3D_0(u_e0)*e0.y*e0.y + 
			phi3D_1(u_e1)*e1.y*e1.y +
			phi3D_2(u_e2)*e2.y*e2.y);

      gamma1_y = (grad.x*e0.x + (*(in+2*tx)-*(in-tx))/8.0*e0.y + grad.z*e0.z)
                 *phi3D_0(u_e0)*e0.y + 
                 (grad.x*e1.x + (*(in+2*tx)-*(in-tx))/8.0*e1.y + grad.z*e1.z)
                 *phi3D_1(u_e1)*e1.y +
                 (grad.x*e2.x + (*(in+2*tx)-*(in-tx))/8.0*e2.y + grad.z*e2.z)
                 *phi3D_2(u_e2)*e2.y;
		 

      //----- Calcul de alpha1_z, gamma1_z 
      grad.x = (*(in+1 ) - *(in-1 ) + *(in+1 +txy) - *(in-1 +txy))/4.0;
      grad.y = (*(in+tx) - *(in-tx) + *(in+tx+txy) - *(in-tx+txy))/4.0; 
//      grad.z = (-*in+*(in+txy));
      grad.z = (*(in+2*txy)-*(in-txy))/8.0+(*(in+txy)-*in)*3.0/8.0;

      // Calcul du gradient, du hessien en (x,y,z+1/2)
      gradient[0] = (float) ((*(Iconv+1)-*(Iconv-1))+(*(Iconv+1+txy)-*(Iconv-1+txy)))/4.0;
      gradient[1] = (float) ((*(Iconv+tx)-*(Iconv-tx))+(*(Iconv+tx+txy)-*(Iconv-tx+txy)))/4.0;
      gradient[2] = (float) (*(Iconv+2*txy)-*Iconv+*(Iconv+txy)-*(Iconv-txy))/4.0;
//      gradient[2] = (-*Iconv+*(Iconv+txy));

      hessien[0][0] = *(Iconv+1)-2*(*Iconv)+*(Iconv-1);
      hessien[1][0] = 
      hessien[0][1] = ((*(Iconv+1+tx)-*(Iconv-1+tx))-
			 (*(Iconv+1-tx)-*(Iconv-1-tx)))/4.0;
      hessien[2][0] = 
      hessien[0][2] = ((*(Iconv+1+txy)-*(Iconv-1+txy))-
                         (*(Iconv+1    )-*(Iconv-1    )) )/2.0;
      hessien[1][1] = *(Iconv+tx) - 2*(*Iconv) + *(Iconv-tx);
      hessien[2][1] = 
      hessien[1][2] = ( (*(Iconv+tx+txy)-*(Iconv-tx+txy)) -
                        (*(Iconv+tx    )-*(Iconv-tx    ))  )/2.0;
      hessien[2][2] = ((*(Iconv+2*txy)-*(Iconv    )) - 
        	       (*(Iconv+  txy)-*(Iconv-txy))  )/2.0;
      // Courbures principales
      norm_grad =  this->Norm(gradient);
      InitFlux(e0,e1,e2);

      Si norm_grad > 0.1 Alors
        // Calcul de la base (e0, e1, e2):
        this->PrincipalCurvatures(gradient,hessien,norm_grad,e0,e1,e2);
      FinSi

      // Derivees directionnelles
      u_e0 = this->ScalarProduct(grad,e0);
      u_e1 = this->ScalarProduct(grad,e1);
      u_e2 = this->ScalarProduct(grad,e2);

      alpha1_z = 3.0/8.0*(phi3D_0(u_e0)*e0.z*e0.z + 
			phi3D_1(u_e1)*e1.z*e1.z +
			phi3D_2(u_e2)*e2.z*e2.z);

      gamma1_z = (grad.x*e0.x + grad.y*e0.y + (*(in+2*txy)-*(in-txy))/8.0*e0.z)
                 *phi3D_0(u_e0)*e0.z + 
                 (grad.x*e1.x + grad.y*e1.y + (*(in+2*txy)-*(in-txy))/8.0*e1.z)
                 *phi3D_1(u_e1)*e1.z +
                 (grad.x*e2.x + grad.y*e2.y + (*(in+2*txy)-*(in-txy))/8.0*e2.z)
                 *phi3D_2(u_e2)*e2.z;
		 

      //----- Mise a jour de l'image

      val1    =  beta*(*image_entree)(x,y,z);
      val1div =  beta;

      val1    += alpha1_x    * (*(in+1  )) +
                 alpha_x     * (*(in-1  )) +
                 gamma1_x  - gamma_x;

      val1div += alpha1_x + alpha_x;

      val1    += alpha1_y     * (*(in+tx )) +
                 alpha_y[x]   * (*(in-tx )) +
                 gamma1_y  - gamma_y[x];

      val1div += alpha1_y + alpha_y[x];

      val1    += alpha1_z      * (*(in+txy  )) +
                 alpha_z[x][y] * (*(in-txy  )) +
                 gamma1_z  - gamma_z[x][y];

      val1div += alpha1_z + alpha_z[x][y];

      Si fabsf(val1div)>1E-4 Alors
        val1 /= val1div;
      Sinon
        fprintf(stderr,"AnisoGaussSeidel.c:Itere3D() \t fabsf(val1div)<1E-4 \n");
      FinSi

      alpha_z[x][y] = alpha1_z;
      alpha_y[x]    = alpha1_y;
      alpha_x       = alpha1_x;

      gamma_z[x][y] = gamma1_z;
      gamma_y[x]    = gamma1_y;
      gamma_x       = gamma1_x;

    Sinon

      val1 = *in;
    
      alpha_z[x][y] = 
      alpha_y[x]    = 
      alpha_x       = 
      gamma_z[x][y] = 
      gamma_y[x]    = 
      gamma_x       = 0;

    FinSi


    Si fabsf(val1-val0) > epsilon Alors
      nb_points_instables++;
    FinSi

    diff += (val1-val0)*(val1-val0);
    Si fabsf(val1-val0) > erreur Alors
      erreur = fabsf(val1-val0);
      erreur_x = x;
      erreur_y = y;
      erreur_z = z;
    FinSi

    this->im_tmp->BufferPos(x,y,z);
    this->im_tmp->FixeValeur(val1);

    in++;
    Iconv++;

  FinPour
  FinPour
  FinPour

  (*im) = (*this->im_tmp);

  cout << endl;
  cout << " Erreur = " << erreur << endl;
  cout << "( " << erreur_x << ", " 
               << erreur_y << ", " 
               << erreur_z << " )" << endl; 
  cout << "nb de points variables " << nb_points_instables << endl;

  diff /= txy*tz;

  cout << "diff =" << sqrt(diff) << endl;

  return erreur;

} //  AnisoGS::Itere3D_3()



//----------------------------------------------------------------------
void AnisoGS::Init(InrImage* in, 
			float p_sigma, 
			float p_k,
			float p_beta
			)
{
  
    char resname[100];

  InitParam();

  sigma       = p_sigma;
  beta        = p_beta;
  k           = p_k;

  tx = in->_tx;
  ty = in->_ty;
  tz = in->_tz;
  txy = tx*ty;

  in->MinMax(&min_intensity,&max_intensity);

  Si tz>1 Alors mode=MODE_3D; Sinon mode=MODE_2D; FinSi

  Si opt_mem Alors
    use_filtre_rec = true;
  FinSi

/*  Si (opt_mem) Ou (in->_format == WT_FLOAT) Alors
    image_entree = in;
    image_entree_allouee=false;
  Sinon
    // conversion de l'image initiale en float
    image_entree = new InrImage( WT_FLOAT, "image_reel.inr.gz", in);
    image_entree_allouee=true;
    (*image_entree) = (*in);
  FinSi
*/
  // Creates input image extending boundaries
  this->input_image = in;

  switch (local_structure_mode) {
   case LOCAL_STRUCT_CURV:
   case LOCAL_STRUCT_TENSOR:
     this->CreateBoundariesVonNeumann(in);
     this->ROI_xmin = this->boundary_extension_size;
     this->ROI_ymin = this->boundary_extension_size;
     this->ROI_zmin = this->boundary_extension_size;
     this->ROI_xmax = image_entree->DimX()-1-boundary_extension_size;
     this->ROI_ymax = image_entree->DimY()-1-boundary_extension_size;
     this->ROI_zmax = image_entree->DimZ()-1-boundary_extension_size;
   break;
/*
   case LOCAL_STRUCT_CURV:
    printf("LOCAL_STRUCT_CURV \n");
    image_entree = new InrImage( WT_FLOAT, "image_reel.inr.gz", in);
    image_entree_allouee=true;
    (*image_entree) = (*in);
    this->boundary_extension_size=0;
     this->ROI_xmin = this->boundary_extension_size;
     this->ROI_ymin = this->boundary_extension_size;
     this->ROI_zmin = this->boundary_extension_size;
     this->ROI_xmax = image_entree->DimX()-1-boundary_extension_size;
     this->ROI_ymax = image_entree->DimY()-1-boundary_extension_size;
     this->ROI_zmax = image_entree->DimZ()-1-boundary_extension_size;
   break;
*/
  }

  this->image_lissee = new InrImage( WT_FLOAT, "image_lissee.inr.gz", image_entree);

  Si use_filtre_rec Alors
    filtre_rec = new FiltrageRec(this->image_lissee);
  Sinon
    filtre = new FiltreRecursif(image_entree, 
				mode);
    filtre->GammaNormalise(false);
    filtre->InitFiltre( sigma, MY_FILTRE_CONV );  
  FinSi

  InitCoefficients();

  //--- image_resultat
    sprintf(resname,"%s.AnisoGS",in->Nom());
  this->image_resultat = new InrImage( WT_FLOAT, resname, image_entree);

  (*this->image_resultat)=(*image_entree);

  // start with a smoothed image for testing
  /*
  filtre->MyFiltre( in, this->image_lissee,           0, -1, -1);
  filtre->MyFiltre( this->image_lissee, this->image_lissee, -1, 0, -1);
  filtre->MyFiltre( this->image_lissee, this->image_lissee, -1, -1, 0);
  (*this->image_resultat) = (*this->image_lissee);
  */

  iteration = 0;
  loop = 2; // loop at 2nd iteration
  max_loop = 6;


} // Init()


//----------------------------------------------------------------------
void Func_InitAnisoGS(InrImage* in, 
			   float p_sigma, 
			   float p_k,
			   float p_beta
			   )
{

  if (static_AnisoGS!=NULL) delete static_AnisoGS;

  static_AnisoGS=new AnisoGS();

  static_AnisoGS->Init(in,p_sigma,p_k,p_beta);

} // Func_InitAnisoGS()

//----------------------------------------------------------------------
void Func_SetCoeffAnisoGS( float p_tang  )
{
  static_AnisoGS->Settang_coeff(p_tang);
}

//----------------------------------------------------------------------
void Func_SetCoeffAnisoGS3D( float cmin, float cmax  )
{
  static_AnisoGS->Setmincurv_coeff(cmin);
  static_AnisoGS->Setmaxcurv_coeff(cmax);
}

//----------------------------------------------------------------------
void      Func_AnisoGS_SetNoiseType( int nt)
//
{
  switch (nt) {
  case GAUSSIAN_NOISE:
  case SPECKLE_NOISE:
    static_AnisoGS->Setnoise_type( nt);
    break;
  default:
    fprintf(stderr,"Func_AnisoGS_SetNoiseType(%d) \t bad noise type \n",nt);
  }
}

//----------------------------------------------------------------------
void      Func_AnisoGS_SetDistanceMap( unsigned char dm)
//
{

  static_AnisoGS->SetDistanceMap(dm);
}

//----------------------------------------------------------------------
void Func_AnisoGS_SetMask( InrImage* m  )
{
  static_AnisoGS->Setmask(m);
}


//----------------------------------------------------------------------
void      Func_AnisoGS_SetDataCoeff( float datacoeff  )
//
{
  static_AnisoGS->Setbeta(datacoeff);
}


//----------------------------------------------------------------------
void      Func_AnisoGS_SetNoiseSD( float noiseSD  )
//
{
  static_AnisoGS->Setnoise_standard_deviation( noiseSD);
}


//----------------------------------------------------------------------
float      Func_AnisoGS_GetNoiseSD(  )
//
{
  return static_AnisoGS->Getnoise_standard_deviation();
}


//----------------------------------------------------------------------
float      Func_AnisoGS_GetDAcoeff(  )
//
{
  return static_AnisoGS->Getestimated_DA_coeff();
}


//----------------------------------------------------------------------
void Func_SetSmoothedParam( unsigned char sp  )
{
  static_AnisoGS->SetSmoothedParam( sp);
}



//----------------------------------------------------------------------
void Func_AnisoGS_SetSRAD_ROI( InrImage* SRAD_roi)
{
  printf("Func_AnisoGS_SetSRAD_ROI()\n");
  static_AnisoGS->SetSRAD_ROI(      SRAD_roi);
  static_AnisoGS->Setcontours_mode( CONTOURS_SRAD);
}

//----------------------------------------------------------------------
void Func_AnisoGS_SetRNRAD_ROI( InrImage* RNRAD_roi)
{
  printf("Func_AnisoGS_SetRNRAD_ROI()\n");
  static_AnisoGS->SetSRAD_ROI(      RNRAD_roi);
  static_AnisoGS->Setcontours_mode( CONTOURS_RNRAD);
}

//----------------------------------------------------------------------
void Func_AnisoGS_SetRNRAD_ROI_NEW( InrImage* RNRAD_roi)
{
  printf("Func_AnisoGS_SetRNRAD_NEW_ROI()\n");
  static_AnisoGS->SetSRAD_ROI(      RNRAD_roi);
  static_AnisoGS->Setcontours_mode( CONTOURS_RNRAD_NEW);
}

//----------------------------------------------------------------------
void Func_AnisoGS_Setneighborhood( int n)
{
  static_AnisoGS->Setneighborhood( n);
}

//----------------------------------------------------------------------
void Func_AnisoGS_Setdt( float dt)
{
  static_AnisoGS->Setdt( dt);
}

//----------------------------------------------------------------------
void      Func_SetLocalStructureMode( int local_struct_mode)
{
  static_AnisoGS->Setlocal_structure_mode( local_struct_mode);
}

//----------------------------------------------------------------------
void      Func_SetEigenvaluesMode( int eigenvalues_mode)
{
  static_AnisoGS->Setdiffusion_eigenvalues_mode( eigenvalues_mode);
}

//----------------------------------------------------------------------
float AnisoGS::Iterate()
//   ----------------
{

  float       erreur = 0;

  Si this->image_resultat==NULL Alors
    cerr << __func__ << " image_resultat==NULL, AnisoGS not initialized " << endl;
    return 0.0;
  FinSi

  // check if the standard deviation of the noise has been set
  if (iteration==0) {
    noise_SD_preset = (noise_standard_deviation!=-1);
    if (noise_SD_preset)
      this->variance = this->noise_standard_deviation*
	this->noise_standard_deviation;
  } 

  iteration++;
  printf("\n -- Iter. %d, beta = %03.2f \t", iteration,beta);

  Si ((mode == MODE_2D)||(image_resultat->DimZ()==1)) Alors
    erreur = Itere2D(    this->image_resultat);
  Sinon
    if (DistanceMap)
     erreur = Itere3D_distance(this->image_resultat);
     //      erreur = Itere3D_distance_flux(this->image_resultat);
    else
//    Si maxcurv_coeff > 1E-5 Alors
      printf("local struct mode %d \n",local_structure_mode);
      switch (local_structure_mode) {
        case LOCAL_STRUCT_TENSOR:
          erreur = Itere3D_ST_RNRAD( this->image_resultat);
        break;
        case LOCAL_STRUCT_CURV:
          erreur = Itere3D_2_new( this->image_resultat);
        break;
      }
//    Sinon
//      erreur = Itere3D(       this->image_resultat);
//    FinSi
  FinSi

  if (!noise_SD_preset)
    //    EstimateNoiseStandardDeviation(this->image_resultat);
  printf(" Max. Intens. change = %3.2f --  ",erreur);
  
  return erreur;

} // AnisoGS::Iterate()


//----------------------------------------------------------------------
float Func_ItereAnisoGS()
//   -----------------
{

  if (static_AnisoGS != NULL)
    return static_AnisoGS->Iterate();
  else
    return 0;

} // Func_ItereAnisoGS()


//----------------------------------------------------------------------
float AnisoGS::IterateFlux( InrImage* vect, float coeff)
//   --------------------
{

  
    float       erreur;

  Si vect== NULL Alors
    fprintf(stderr,"Func_ItereFlux() \t NULL vector \n");
    return 0.0;
  FinSi

  Si Non(vect->VectorialFormat()) Alors
    fprintf(stderr,"Func_ItereFlux() \t input image not in  vectorial format \n");
    return 0.0;
  FinSi

  Si this->image_resultat==NULL Alors
    fprintf(stderr,"Func_ItereFlux() AnisoGS not initialized \n");
    return 0.0;
  FinSi

  iteration++;

  Si mode == MODE_2D Alors
    fprintf(stderr,"Func_ItereFlux() 2D mode not supported yet \n");
    return 0.0;
  //    erreur = Itere2D(    this->image_resultat);
  Sinon
    erreur = Itere3D_Flux( this->image_resultat, vect, coeff);
  FinSi
    
  printf(" iteration %d : %f \n", iteration,erreur);
  
  return erreur;

} // AnisoGS::IterateFlux()


//----------------------------------------------------------------------
float Func_ItereFlux( InrImage* vect, float coeff)
//   --------------
{

  if (static_AnisoGS != NULL)
    return static_AnisoGS->IterateFlux(vect,coeff);
  else
    return 0;

} // Func_ItereAnisoGS()



//----------------------------------------------------------------------
int Func_EndAnisoGS()
{

  delete static_AnisoGS;
  static_AnisoGS = NULL;

  return 1;

} // Func_EndAnisoGS()


//----------------------------------------------------------------------
InrImage* Func_AnisoGS_GetOutput()
{

  if (static_AnisoGS != NULL) {
    InrImage* imres = static_AnisoGS->image_resultat;
    InrImage* res;
    int bs = static_AnisoGS->boundary_extension_size;

    res = Func_SubImage( imres,
                          bs,bs,bs,
                          imres->DimX()-1-bs,
                          imres->DimY()-1-bs,
                          imres->DimZ()-1-bs);

    // Set translation and voxel size ?

    return res;
  }
  else
    return NULL;

} // Func_GetOutput()


//----------------------------------------------------------------------
InrImage* Func_AnisoGS_GetDiffusionCoeff()
{
  InrImage* res;

  if (static_AnisoGS != NULL) {
    if (static_AnisoGS->image_c!=NULL) {
      res = new InrImage(WT_FLOAT, "imagec_copy.ami.gz",  static_AnisoGS->image_c);
      (*res) = (*static_AnisoGS->image_c);
      return res;
    }
    else {
      printf("static_AnisoGS->image_c == NULL \n");
      return NULL;
    }
  }
  else
    return NULL;

} // Func_GetDiffusionCoeff()




