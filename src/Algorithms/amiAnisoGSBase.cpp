//
// C++ Implementation: AnisoGSBase
//
// Description: Denoising Filter
//
//
// Author: Karl Krissian <krissian@dis.ulpgc.es>, (C) 2009
//
// Copyright: See COPYING file that comes with this distribution
//
//

#include "amiAnisoGSBase.h"


#include "localstats.h"
#include "func_globalstats.h"
#include "func_imagebasictools.h"
#include "Eigen.hpp"
#include "CurvaturasPrincipales.hpp"
#include "filtrage_rec.hpp"

#define IncX(I)  ((x<tx-1)?(I+1):I)
#define Inc2X(I) ((x<tx-2)?(I+1):I)
#define DecX(I)  ((x>0)?(I-1):I)

#define IncY(I)  ((y<ty-1)?(I+tx):I)
#define Inc2Y(I) ((y<ty-2)?(I+tx):I)
#define DecY(I)  ((y>0)?(I-tx):I)

#define IncZ(I)  ((z<tz-1)?(I+txy):I)
#define Inc2Z(I) ((z<tz-2)?(I+txy):I)
#define DecZ(I)  ((z>0)?(I-txy):I)


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

#include <limits>
#ifdef min
  #undef min
#endif
#ifdef max
  #undef max
#endif

template<typename T>
inline bool ispositivevalue(const T& value)
{
  return  (value==0) 
          ||
          ( (value >= std::numeric_limits<T>::min()) 
            && 
            (value <= std::numeric_limits<T>::max()));
}


double CubicRoot(double x) {
  if (x==0) return 0;
  if (x>0) return exp(log(x)/3.0);
  if (x<0) return -exp(log(-x)/3.0);
  return 0;
}




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

//------------------------------------------------------------------------------
InrImage::ptr ami::AnisoGSBase::GetOutput()
{
  InrImage* imres = this->Getresult_image();
  int bs = this->boundary_extension_size;

  InrImage::ptr res(Func_SubImage( imres,
                        bs,bs,bs,
                        imres->DimX()-1-bs,
                        imres->DimY()-1-bs,
                        imres->DimZ()-1-bs));

  // Set translation and voxel size ?
  return res;
}

//------------------------------------------------------------------------------
InrImage::ptr ami::AnisoGSBase::Run(InrImage::ptr input, float sigma, float k, 
                                float beta, int nb_iter)
{
  ami::AnisoGSBase::ptr aniso(new ami::AnisoGS());
  aniso->Init(input.get(),sigma,k,beta);

  if (nb_iter < 1) nb_iter = 1;

  //int error = 0;
  for(int i=1;i<=nb_iter;i++){
    //error = 
    aniso->Iterate();
  }

  InrImage* imres = aniso->result_image;
  int bs = aniso->boundary_extension_size;

  InrImage::ptr res(
                    Func_SubImage( imres,
                        bs,bs,bs,
                        imres->DimX()-1-bs,
                        imres->DimY()-1-bs,
                        imres->DimZ()-1-bs));
  // Set translation and voxel size ?

  return res;
}


//------------------------------------------------------------------------------
// Destructor
ami::AnisoGSBase::~AnisoGS()
{

  DeleteCoefficients();
  
  if ( filtre     != NULL ) {
    delete filtre;
    filtre = NULL;
  } // end if
  
  if ( filtre_rec != NULL ) {
    delete filtre_rec;
    filtre_rec = NULL;
  } // end if
  
  if ( this->image_lissee != NULL ) {
    delete this->image_lissee;
    this->image_lissee=NULL;
  } // end if
  
  if ( this->im_tmp != NULL ) {
    delete this->im_tmp;
    this->im_tmp = NULL;
  } // end if
  
  if ( this->image_c != NULL ) {
    delete this->image_c;
    this->image_c = NULL;
  } // end if
  
  if ( divFim != NULL ) {
    delete divFim;
    divFim = NULL;
  } // end if
  
  if ( !(opt_mem) && (image_entree_allouee) ) {
    delete image_entree;
    image_entree=NULL;
  } // end if
      
  if (tensor_xx!=NULL) { delete tensor_xx;  tensor_xx=NULL; }
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

// Extend Boundary Conditions
void ami::AnisoGSBase::ExtendBoundariesVonNeumann( InrImage* input)
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
//  input->Sauve("boundary_test.ami.gz");
}

// Compute image_entree
void ami::AnisoGSBase::CreateBoundariesVonNeumann( InrImage* input)
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
void  ami::AnisoGSBase::ComputeLocalPlanStats(InrImage* im, float x, float y, float z, 
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
void  ami::AnisoGSBase::ComputeLocalDirStats(InrImage* im, float x, float y, float z, t_3Point e,
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
        fprintf(stderr,"ami::AnisoGSBase::ComputeLocalDirStats() \t Too many values \n");
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
void ami::AnisoGSBase::EstimateNoiseStandardDeviation( InrImage* im)
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
    JusquA !(noise_im->IncBuffer())
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
  if ( x>0 && x<tx-1 && y>0 && y<ty-1 && z>0 && z<tz-1 
  ) {
    mean += buf[i];
      nb_points++;
        } // end if
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
  if ( x>0 && x<tx-1 && y>0 && y<ty-1 && z>0 && z<tz-1 
  ) {
    d  = buf[i]-mean;
    this->variance += d*d;
        } // end if
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

} // ami::AnisoGSBase::EstimateNoiseStandardDeviation()


//----------------------------------------------------------------------
void ami::AnisoGSBase::InitCoefficients()
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
  for(x=0;x<=tx-1;x++) {
    alpha_y[x] = gamma_y[x] = 0;
  } // endfor

  if ( mode == MODE_3D ) {
    int y;

    alpha_z = new float*[tx];
    gamma_z = new float*[tx];
    for(x=0;x<=tx-1;x++) {
      alpha_z[x] = new float[image_entree->_ty];
      gamma_z[x] = new float[image_entree->_ty];


      for(y=0;y<=ty-1;y++) {
  alpha_z[x][y] = gamma_z[x][y] = 0;
      } // endfor

    } // endfor

  } // end if

} // ami::AnisoGSBase::InitCoefficients()


//----------------------------------------------------------------------
void ami::AnisoGSBase::ResetCoefficients()
//
{

  
    int x;

  alpha_x = gamma_x = 0;

  for(x=0;x<=tx-1;x++) {
    alpha_y[x] = gamma_y[x] = 0;
  } // endfor

  if ( mode == MODE_3D ) {
    int y;

    for(x=0;x<=tx-1;x++) {
      for(y=0;y<=ty-1;y++) {
  alpha_z[x][y] = gamma_z[x][y] = 0;
      } // endfor
    } // endfor

  } // end if
} // ami::AnisoGSBase::ResetCoefficients()


//----------------------------------------------------------------------
void ami::AnisoGSBase::DeleteCoefficients()
//
{

  if ( alpha_y != NULL ) {

    delete [] alpha_y;
    alpha_y = NULL;
    delete [] gamma_y;
    gamma_y = NULL;

    if ( mode == MODE_3D ) {
      int i;

      for(i=0;i<=tx-1;i++) {
        delete [] alpha_z[i];
        delete [] gamma_z[i];
      } // endfor
      delete [] alpha_z;
      delete [] gamma_z;

    } // end if
  } // end if

} // ami::AnisoGSBase::DeleteCoefficients()


//----------------------------------------------------------------------
void ami::AnisoGSBase::InitNeighborhood(float* I,int x,int y)
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
void ami::AnisoGSBase::Grad2D(float* I,float grad[2])
//            ----
{
  grad[0] = (*Ixp   -  *Ixm )/2.0;
  grad[1] = (*Iyp   -  *Iym )/2.0;
}

//----------------------------------------------------------------------
// gradient vector at (x+1/2,y,z)
//
void ami::AnisoGSBase::Grad2DShiftX(float* I,t_3Point& grad)
//            ----------
{
  grad.x = *Ixp   -  *I0;
  grad.y = ((*Ixpyp+*Iyp)  - (*Ixpym+*Iym))/4.0;
}

//----------------------------------------------------------------------
// gradient vector at (x,y+1/2,z)
//
void ami::AnisoGSBase::Grad2DShiftY(float* I,t_3Point& grad)
//            ----------
{
  grad.x = ((*Ixpyp+*Ixp)  - (*Ixmyp+*Ixm))/4.0;
  grad.y = *Iyp   -  *I0;
}




//----------------------------------------------------------------------
double ami::AnisoGSBase::Compute_q0_subvol( InrImage* im)
{

  InrImage* subvol;
  InrImage::ptr im2 = this->SRAD_ROI;
  int xmin,xmax,ymin,ymax,zmin,zmax;
  double var;
  double mean;
  double tmp,total;

  if (this->SRAD_ROI==NULL)
    {
      fprintf(stderr,"ami::AnisoGSBase::Compute_q0_subvol() \t SRAD_ROI==NULL\n");
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
double ami::AnisoGSBase::function_c_Kuan(double q_2, double q0_2)
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
double ami::AnisoGSBase::function_c_Lee(double q_2, double q0_2)
{
  double tmp;
  if (fabsf(q0_2)<1E-4) return 0;
  if (q_2<0) q_2 = 0;
  tmp = 1.0/(1.0+(q_2-q0_2)/(q0_2*(1+q0_2)));
  if (tmp>1) tmp=1;
  return tmp;
} // function_c_Lee

//----------------------------------------------------------------------
double ami::AnisoGSBase::Compute_sigma2_MRI(InrImage* im)
//
{
  InrImage::ptr im2 = this->SRAD_ROI;
  int xmin,xmax,ymin,ymax,zmin,zmax;
  double var;
  double mean;
  double tmp,total;

  if (this->SRAD_ROI==NULL)
    {
      fprintf(stderr,"ami::AnisoGSBase::Compute_sigma2_MRI() \t SRAD_ROI==NULL\n");
      return 0.0;
    }
  xmin = (int) ((im2->TrX()-im->TrX())/im2->VoxSizeX()+0.5);
  ymin = (int) ((im2->TrY()-im->TrY())/im2->VoxSizeY()+0.5);
  zmin = (int) ((im2->TrZ()-im->TrZ())/im2->VoxSizeZ()+0.5);
  xmax = (int) ((im2->TrX()-im->TrX())/im2->VoxSizeX()+im2->DimX()-1+0.5);
  ymax = (int) ((im2->TrY()-im->TrY())/im2->VoxSizeY()+im2->DimY()-1+0.5);
  zmax = (int) ((im2->TrZ()-im->TrZ())/im2->VoxSizeZ()+im2->DimZ()-1+0.5);
  InrImage::ptr subvol( Func_SubImage(  im,
                                        xmin,ymin,zmin,
                                        xmax,ymax,zmax));
  
  mean   = Func_mean(subvol.get());

  subvol->InitBuffer();
  total =0;
  do {
    tmp = subvol->ValeurBuffer()-mean;
    total += tmp*tmp;
  }
  while(subvol->IncBuffer());
  total = total/subvol->Size();
  var=total;

  if ((mean*mean)<var) {
    printf("ami::AnisoGSBase::Compute_sigma2_MRI() mean*mean < var ...\n");
    return mean/2.0;
  } else {
    return (mean-sqrt(mean*mean-var))/2.0;
  }
}

//----------------------------------------------------------------------
double ami::AnisoGSBase::Compute_sigma2_MRI_mode(InrImage* im)
//
{

  return Func_Compute_sigma2_MRI_mode(im,this->SRAD_ROI);

/*
  InrImage* subvol;
  InrImage* im2 = this->SRAD_ROI;
  int xmin,xmax,ymin,ymax,zmin,zmax;

  if (this->SRAD_ROI==NULL)
    {
      fprintf(stderr,"ami::AnisoGSBase::Compute_sigma2_MRI_mode() \t SRAD_ROI==NULL\n");
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

//------------------------------------------------------------------------------
double ami::AnisoGSBase::Compute_sigma2_Gaussian_mode(InrImage* im)
//
{
  return Func_Compute_sigma2_Gaussian_mode(im,this->SRAD_ROI);
}

//------------------------------------------------------------------------------
double ami::AnisoGSBase::function_c_MRI(double sigma2, double vg, double meang)
{
#define var_epsilon 1E-4
  double tmp;
  if (fabsf(vg)<var_epsilon) return 0.0;
  if (meang<=sigma2) return 0.0;
  tmp =4.0*sigma2*(meang-sigma2)/vg;

  return tmp;
#undef var_epsilon
} // function_c_MRI

//----------------------------------------------------------------------
void ami::AnisoGSBase::ComputeImage_c(InrImage* im)
//            --------------
{

  int x,y,z; //,n,i;
  double I,Ixm,Iym,Izm,Ixp,Iyp,Izp,mean1,mean2,q0_2=0.0,q2;
  double sigma2=0.0;

/*
 *  int mode = MODE_KUAN;

//  printf("ami::AnisoGSBase::ComputeImage_c() \t contour mode = %d \n",this->contours_mode);
  switch (this->contours_mode)
    {
    case CONTOURS_OSRAD:
      mode = MODE_KUAN;
      break;
    case CONTOURS_RNRAD:
      mode = MODE_MRI;
      break;
    case CONTOURS_NRAD:
      mode = MODE_MRI;
      break;
    }
*/

  if ((this->contours_mode==CONTOURS_OSRAD)||
      (this->contours_mode==CONTOURS_NRAD))
    {

      if ( this->image_c == NULL ) 
      this->image_c = new InrImage(WT_FLOAT, "image_c.ami.gz", im);

      // we limit for the moment to Kuan's function with Yu's neighborhood

      // precompute image of coefficients
      switch (noise_model)
        {
        case NOISE_LEE:
        case NOISE_KUAN:
        case NOISE_GAUSSIAN_ADDITIVE:
          q0_2= Compute_q0_subvol(im);
          printf("q0_2 = %f \n",q0_2);
          break;
        case NOISE_RICIAN:
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
      delete image_I2;
      image_I2= NULL;

      // 1. Compute c
      for (z=0;z<tz;z++)
        {
          for (y=0;y<ty;y++)
            {
              for (x=0;x<tx;x++)
                {
                  I = (*im)(x,y,z);
                  if (fabsf(I)<1) I=1;
                  if (x>0)     Ixm = (*im)(x-1,y,z);
                  else Ixm = I;
                  if (y>0)     Iym = (*im)(x,y-1,z);
                  else Iym = I;
                  if (z>0)     Izm = (*im)(x,y,z-1);
                  else Izm = I;

                  if (x<tx-1)  Ixp = (*im)(x+1,y,z);
                  else Ixp = I;
                  if (y<ty-1)  Iyp = (*im)(x,y+1,z);
                  else Iyp = I;
                  if (z<tz-1)  Izp = (*im)(x,y,z+1);
                  else Izp = I;

                  // other (simpler version of q2):
                  switch (neighborhood)
                    {
                    case 0:
                      mean1 = Ixm+Ixp+Iym+Iyp;
                      mean2 = Ixm*Ixm+Ixp*Ixp+Iym*Iym+Iyp*Iyp;
                      if (tz==1)
                        {
                          mean1/=4.0;
                          mean2/=4.0;
                        }
                      else
                        {
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
                  switch (noise_model)
                    {
                    case NOISE_LEE:
                      image_c->FixeValeur( function_c_Lee( q2, q0_2));
                      break;
                    case NOISE_KUAN:
                      image_c->FixeValeur( function_c_Kuan( q2, q0_2));
                      break;
                    case NOISE_GAUSSIAN_ADDITIVE: 
                      image_c->FixeValeur( function_c_additive(mean2-mean1*mean1,
                                                               q0_2)); 
                      break;
                    case NOISE_RICIAN:
                      image_c->FixeValeur( function_c_MRI( sigma2, 
                                                           mean2-mean1*mean1, 
                                                           mean1));
                      break;
                    }
                }
            }
        } // for z

      if (neighborhood>0)
        {
          delete image_mean_I;
          image_mean_I  = NULL;
          delete image_mean_I2;
          image_mean_I2 = NULL;
        }

    } //
  else
    CLASS_ERROR((boost::format("contours_mode %1% not supported")%
                  contours_mode).str().c_str());
//  image_c->Sauve();

}

//------------------------------------------------------------------------------
void ami::AnisoGSBase::Smooth(InrImage* image, float sigma)
{
    GeneralGaussianFilter* filtre;

  filtre = new GeneralGaussianFilter(image, MODE_3D);
//  filtre->SetScaleUnit(PIXEL_SPACE);
  filtre->Utilise_Image(   true);
  filtre->UtiliseGradient( false);
  filtre->InitDerivees();
  filtre->SetSupportSize(4);

  filtre->GammaNormalise(  true);

  filtre->InitFiltre( sigma, MY_FILTRE_CONV);
  filtre->CalculFiltres();
  (*image) = (*(*filtre)(IM_sigma));
  delete filtre;
}

//------------------------------------------------------------------------------
void ami::AnisoGSBase::ComputeStructureTensor(InrImage* im, float sigma1, 
                                          float sigma2)
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
    GeneralGaussianFilter* filtre;
//    char            resname[100];

  double tmp;
  if (contours_mode==CONTOURS_NRAD) {
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
    if ( (im->_format == WT_FLOAT) ) {
      image = im;
    } else {
      // conversion de l'image initiale en float
      image    = new InrImage( WT_FLOAT, "image_reel.inr.gz", im);
      (*image) = (*im);
    } // end if
  }

  if (tensor_xx==NULL) tensor_xx =  new InrImage( WT_FLOAT, "Tensor_xx", image);
  if (tensor_xy==NULL) tensor_xy =  new InrImage( WT_FLOAT, "Tensor_xy", image);
  if (tensor_xz==NULL) tensor_xz =  new InrImage( WT_FLOAT, "Tensor_xz", image);
  if (tensor_yy==NULL) tensor_yy =  new InrImage( WT_FLOAT, "Tensor_yy", image);
  if (tensor_yz==NULL) tensor_yz =  new InrImage( WT_FLOAT, "Tensor_yz", image);
  if (tensor_zz==NULL) tensor_zz =  new InrImage( WT_FLOAT, "Tensor_zz", image);


  // Initialisation des images des d�riv�es 
  filtre = new GeneralGaussianFilter(image, MODE_3D);
//  filtre->SetScaleUnit(PIXEL_SPACE);
  filtre->Utilise_Image(   false);
  filtre->UtiliseGradient( true);
  filtre->InitDerivees();
  filtre->GammaNormalise( true);
  filtre->SetSupportSize(5);
  filtre->InitFiltre( sigma1, MY_FILTRE_CONV);  
  filtre->CalculFiltres( );

  // Calcul des coefficients du tenseur non liss�

  tensor_xx->InitBuffer();
  tensor_xy->InitBuffer();
  tensor_xz->InitBuffer();
  tensor_yy->InitBuffer();
  tensor_yz->InitBuffer();
  tensor_zz->InitBuffer();

  for(z= 0;z<= image->_tz - 1;z++) {
  for(y= 0;y<= image->_ty - 1;y++) {
  for(x= 0;x<= image->_tx - 1;x++) {

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

  } // endfor
  } // endfor
  } // endfor

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




//------------------------------------------------------------------------------
void ami::AnisoGSBase::ComputeEigenVectors()
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


//------------------------------------------------------------------------------
void ami::AnisoGSBase::InitFlux( t_3Point& e0,t_3Point& e1,t_3Point& e2)
//            --------
{
      e0.x = 1; e0.y = 0; e0.z = 0;
      e1.x = 0; e1.y = 1; e1.z = 0;
      e2.x = 0; e2.y = 0; e2.z = 1;

} // InitFlux()


//------------------------------------------------------------------------------
void ami::AnisoGSBase::InitNeighborhood(float* I,int x,int y, int z)
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
void ami::AnisoGSBase::Grad(float* I,float grad[3])
//            ----
{
  grad[0] = (*Ixp   -  *Ixm )/2.0;
  grad[1] = (*Iyp   -  *Iym )/2.0;
  grad[2] = (*Izp   -  *Izm )/2.0;
}

//------------------------------------------------------------------------------
// gradient vector at (x+1/2,y,z)
//
void ami::AnisoGSBase::GradShiftX(float* I,float grad[3])
//            ----------
{
  grad[0] = *Ixp   -  *I0;
  grad[1] = ((*Ixpyp+*Iyp)  - (*Ixpym+*Iym))/4.0;
  grad[2] = ((*Ixpzp+*Izp)  - (*Ixpzm+*Izm))/4.0;
}

//------------------------------------------------------------------------------
// gradient vector at (x,y+1/2,z)
//
void ami::AnisoGSBase::GradShiftY(float* I,float grad[3])
//            ----------
{
  grad[0] = ((*Ixpyp+*Ixp)  - (*Ixmyp+*Ixm))/4.0;
  grad[1] = *Iyp   -  *I0;
  grad[2] = ((*Iypzp+*Izp)  - (*Iypzm+*Izm))/4.0;
}

//------------------------------------------------------------------------------
// gradient vector at (x,y,z+1/2)
//
void ami::AnisoGSBase::GradShiftZ(float* I,float grad[3])
//            ----------
{
  grad[0] = ((*Ixpzp+*Ixp)  - (*Ixmzp+*Ixm))/4.0;
  grad[1] = ((*Iypzp+*Iyp)  - (*Iymzp+*Iym))/4.0;
  grad[2] = *Izp   -  *I0;
}

//------------------------------------------------------------------------------
// Hessian Matrix at (x,y,z)
//
void ami::AnisoGSBase::Hessian(float* I,float** H)
//            -------
{
  H[0][0] = (*Ixp - 2*(*I0) + *Ixm);
  H[1][1] = (*Iyp - 2*(*I0) + *Iym);
  H[2][2] = (*Izp - 2*(*I0) + *Izm);
  H[1][0] = H[0][1] = ((*Ixpyp - *Ixmyp) - (*Ixpym - *Ixmym))/4.0;
  H[2][0] = H[0][2] = ((*Ixpzp - *Ixmzp) - (*Ixpzm - *Ixmzm))/4.0;
  H[2][1] = H[1][2] = ((*Iypzp - *Iymzp) - (*Iypzm - *Iymzm))/4.0;
}


//------------------------------------------------------------------------------
// Hessian Matrix at (x+1/2,y,z)
//
void ami::AnisoGSBase::HessianShiftX(float* I,float H[3][3])
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

//------------------------------------------------------------------------------
// Hessian Matrix at (x,y+1/2,z)
//
void ami::AnisoGSBase::HessianShiftY(float* I,float H[3][3])
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

//------------------------------------------------------------------------------
// Hessian Matrix at (x,y,z+1/2)
//
void ami::AnisoGSBase::HessianShiftZ(float* I,float H[3][3])
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


//------------------------------------------------------------------------------
float ami::AnisoGSBase::Norm(float v[3])
//             ----
{
  return sqrt(v[0]*v[0]+v[1]*v[1]+v[2]*v[2]);
} // Norm()


//------------------------------------------------------------------------------
float ami::AnisoGSBase::ScalarProduct(const t_Gradient v1, const t_3Point v2)
//             -------------
{
  return v1.x*v2.x+
         v1.y*v2.y+
         v1.z*v2.z;
}


//------------------------------------------------------------------------
// Computes the eigenvectors of the structure tensor at a position
// x,y,z displaced by 0.5 in the coordinate given by coord
//
void ami::AnisoGSBase::StructTensor_eigenvectors( int coord, int x, int y, int z, 
                                              t_3Point& e0, t_3Point& e1, 
                                              t_3Point& e2)
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

//------------------------------------------------------------------------------
unsigned char ami::AnisoGSBase::convert_uchar(double val)
{
  return (unsigned char) MIN(255,MAX(0,(val+1.0)*127.5));
}

#define MAX_SHORT 32700.0

//------------------------------------------------------------------------------
short ami::AnisoGSBase::convert_short(double val)
{
  return (short) MIN(MAX_SHORT,MAX(-MAX_SHORT,val*MAX_SHORT));
}

//------------------------------------------------------------------------------
void ami::AnisoGSBase::GetVectors( int coord, int x, int y, int z, 
                               t_3Point& e0, t_3Point& e1, t_3Point& e2)
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
//------------------------------------------------------------------------------
// Get Principal Curvature Directions
//
void ami::AnisoGSBase::PrincipalCurvatures(float grad[3], float H[3][3], 
                                       float norm_grad,
//            -------------------
          t_3Point& e0, t_3Point& e1, t_3Point& e2)
{
  
    float vmax[3];
    float vmin[3];
    float lmin;
    float lmax;

  // Calcul de la base (e0, e1, e2):
  if ( CurvaturasPrincipales(  H, 
           (float*) grad, 
           (float*) vmax, 
           (float*) vmin, 
           &lmax, &lmin,
           1E-2) != -1 ) {
    e0.x = grad[0]/norm_grad;
    e0.y = grad[1]/norm_grad;
    e0.z = grad[2]/norm_grad;
    e1.x = vmax[0]; e1.y = vmax[1]; e1.z = vmax[2];
    e2.x = vmin[0]; e2.y = vmin[1]; e2.z = vmin[2];
  } else {
    fprintf(stderr,"CurvaturasPrincipales failed \n");
  //    fprintf(stderr,"  %d %d %d \n", x,y,z);
    fprintf(stderr," grad = %f %f %f \n", grad[0], grad[1], grad[2]);
  } // end if
}






//------------------------------------------------------------------------------
void ami::AnisoGSBase::Init(InrImage* in, 
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

  if ( tz>1 ) { mode=MODE_3D; } else { mode=MODE_2D; } // end if

  if ( opt_mem ) {
    use_filtre_rec = true;
  } // end if

/*  if ( (opt_mem) || (in->_format == WT_FLOAT) ) {
    image_entree = in;
    image_entree_allouee=false;
  } else {
    // conversion de l'image initiale en float
    image_entree = new InrImage( WT_FLOAT, "image_reel.inr.gz", in);
    image_entree_allouee=true;
    (*image_entree) = (*in);
  } // end if
*/
  // Creates input image extending boundaries
  this->input_image = in;

  this->ROI_xmin = 0;
  this->ROI_ymin = 0;
  this->ROI_zmin = 0;
  this->ROI_xmax = input_image->DimX()-1;
  this->ROI_ymax = input_image->DimY()-1;
  this->ROI_zmax = input_image->DimZ()-1;
//  if  ((mode != MODE_2D)&&(result_image->DimZ()>1)&&(!DistanceMap))
//  {
    switch (local_structure_mode) {
    case LOCAL_STRUCT_CURV:
    case LOCAL_STRUCT_TENSOR:
      this->CreateBoundariesVonNeumann(in);
      this->ROI_xmin = this->boundary_extension_size;
      this->ROI_ymin = this->boundary_extension_size;
      this->ROI_xmax = image_entree->DimX()-1-boundary_extension_size;
      this->ROI_ymax = image_entree->DimY()-1-boundary_extension_size;
      if  ((mode != MODE_2D)&&(image_entree->DimZ()>1)) {
        this->ROI_zmin = this->boundary_extension_size;
        this->ROI_zmax = image_entree->DimZ()-1-boundary_extension_size;
      }
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
//  }
  
  this->image_lissee = new InrImage( WT_FLOAT, "image_lissee.inr.gz", image_entree);

  if ( use_filtre_rec ) {
    filtre_rec = new FiltrageRec(this->image_lissee);
  } else {
    filtre = new GeneralGaussianFilter(image_entree, 
        mode);
    filtre->GammaNormalise(false);
    filtre->InitFiltre( sigma, MY_FILTRE_CONV );  
  } // end if

  InitCoefficients();

  //--- result_image
    sprintf(resname,"%s.AnisoGS",in->GetName());
  this->result_image = new InrImage( WT_FLOAT, resname, image_entree);

  (*this->result_image)=(*image_entree);

  // start with a smoothed image for testing
  /*
  filtre->MyFiltre( in, this->image_lissee,           0, -1, -1);
  filtre->MyFiltre( this->image_lissee, this->image_lissee, -1, 0, -1);
  filtre->MyFiltre( this->image_lissee, this->image_lissee, -1, -1, 0);
  (*this->result_image) = (*this->image_lissee);
  */

  iteration = 0;
  loop = 2; // loop at 2nd iteration
  max_loop = 6;


} // Init()


