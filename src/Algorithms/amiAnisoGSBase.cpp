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

#include "amiEigenDecomp_NRAD.h"
#include "amiImageToImageFilter.h"

#include <wx/thread.h>

#include "dsyevj3.h"
#include "dsyevq3.h"
#include "dsyevh3.h"


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

/*
//------------------------------------------------------------------------------
InrImage::ptr ami::AnisoGSBase::Run(InrImage::ptr input, float sigma, float k, 
                                float beta, int nb_iter)
{
  ami::AnisoGSBase::ptr aniso(new ami::AnisoGSBase());
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
*/

//------------------------------------------------------------------------------
// Destructor
ami::AnisoGSBase::~AnisoGSBase()
{

/*
 *  if ( filtre     != NULL ) {
    delete filtre;
    filtre = NULL;
  } // end if
  
  if ( filtre_rec != NULL ) {
    delete filtre_rec;
    filtre_rec = NULL;
  } // end if
  */

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
      
  if (eigendecomp_mode==INITIAL) {
    if (tensor_xx!=NULL) { delete tensor_xx;  tensor_xx=NULL; }
    if (tensor_xy!=NULL) { delete tensor_xy; tensor_xy=NULL; }
    if (tensor_xz!=NULL) { delete tensor_xz; tensor_xz=NULL; }
    if (tensor_yy!=NULL) { delete tensor_yy; tensor_yy=NULL; }
    if (tensor_yz!=NULL) { delete tensor_yz; tensor_yz=NULL; }
    if (tensor_zz!=NULL) { delete tensor_zz; tensor_zz=NULL; }
  }

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
double ami::AnisoGSBase::function_c_additive(double q_2, double q0_2)
{
  double tmp;
  if (fabsf(q0_2)<1E-4) return 0;
  if (q_2<1E-3*q0_2) {
    //    printf("function_c(q_2<0,q0_2) ...\n");
    return 0;
  }
  tmp = q0_2/q_2;
  return tmp;
} // function_c_additive

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

}

//------------------------------------------------------------------------------
double ami::AnisoGSBase::Compute_sigma2_Gaussian_mode(InrImage* im, 
                                                      int neighborhood)
//
{
  return Func_Compute_sigma2_Gaussian_mode(im,this->SRAD_ROI, neighborhood);
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


//------------------------------------------------------------------------------
void ami::AnisoGSBase::Smooth(InrImage* image, float sigma)
{
    GeneralGaussianFilter* filtre;

  filtre = new GeneralGaussianFilter(image, MODE_3D);
  filtre->Set_use_new_filter(UseNewConvolutionFilter);
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
void ami::AnisoGSBase::ComputeStructureTensor(InrImage* im, float sigma_1, 
                                          float sigma_2)
{
//std::cout << "*" << std::endl;
  Timing gradient_timing;
  Timing Tensor_timing;
  Timing Smoothing_timing;
  Timing Smoothing_timing2;
  
//  std::cout << "Begin ami::AnisoGSBase::ComputeStructureTensor()" << std::endl;
//std::cout << "*" << std::endl;
  printf("sig1 %f sig2 %f \n",sigma_1,sigma_2);
//std::cout << "*" << std::endl;
  structtensor_time.Debut();
//std::cout << "*" << std::endl;
  if (im->_tz == 1)
  {
    fprintf(stderr, "structure tensor not yet available in 2D ! \n");
    return;
  }
//std::cout << "*" << std::endl;


    FloatMatrix     matrice(3,3);
    FloatMatrix     matriceinit(3,3);
//    float           vap[3];
    FloatMatrix     vec_propre(3,3);
    int          x,y,z;
//    unsigned char         Diagonale = false;
    Vect3D<double>  grad;
//    int             niter;
    InrImage*       image;
    GeneralGaussianFilter::ptr filtre;
//    char            resname[100];

//std::cout << "*" << std::endl;
  double tmp;
  if (InputIsSquared) {
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

//std::cout << "*" << std::endl;

  if (eigendecomp_mode==INITIAL) {
    if (tensor_xx==NULL) 
      tensor_xx =  new InrImage( WT_FLOAT,1, "Tensor_xx", image);
    if (tensor_xy==NULL) 
      tensor_xy =  new InrImage( WT_FLOAT,1, "Tensor_xy", image);
    if (tensor_xz==NULL) 
      tensor_xz =  new InrImage( WT_FLOAT,1, "Tensor_xz", image);
    if (tensor_yy==NULL) 
      tensor_yy =  new InrImage( WT_FLOAT,1, "Tensor_yy", image);
    if (tensor_yz==NULL) 
      tensor_yz =  new InrImage( WT_FLOAT,1, "Tensor_yz", image);
    if (tensor_zz==NULL) 
      tensor_zz =  new InrImage( WT_FLOAT,1, "Tensor_zz", image);
  } else {
    if (!tensor_im.get()) {
      tensor_im = InrImage::ptr(new InrImage(WT_FLOAT,6,"Tensor_im",image));
    }
  }

//std::cout << "*" << std::endl;

  gradient_timing.Debut();
  // Initialisation des images des d�riv�es 
  filtre = GeneralGaussianFilter::ptr(new GeneralGaussianFilter(image, MODE_3D));
//  filtre->SetScaleUnit(PIXEL_SPACE);
  
  filtre->InitDerivees();
  filtre->Set_use_new_filter(UseNewConvolutionFilter);
  filtre->Utilise_Image(   false);
  filtre->UtiliseGradient( true);
  filtre->GammaNormalise( true);
  filtre->SetSupportSize(5);
  filtre->InitFiltre( sigma_1, MY_FILTRE_CONV);  
  //std::cout << "CalculFiltres()" << std::endl;
  filtre->CalculFiltres( );
  gradient_timing.Fin();
  if (show_timing)
    std::cout << "gradient timing " << gradient_timing << std::endl;

  // Calcul des coefficients du tenseur non liss�
  Tensor_timing.Debut();
  float* Txx_ptr;
  float* Txy_ptr;
  float* Txz_ptr;
  float* Tyy_ptr;
  float* Tyz_ptr;
  float* Tzz_ptr;
  float* T_ptr;
  if (eigendecomp_mode==INITIAL) {
    Txx_ptr = (float*)tensor_xx->GetData();
    Txy_ptr = (float*)tensor_xy->GetData();
    Txz_ptr = (float*)tensor_xz->GetData();
    Tyy_ptr = (float*)tensor_yy->GetData();
    Tyz_ptr = (float*)tensor_yz->GetData();
    Tzz_ptr = (float*)tensor_zz->GetData();
  } else {
    T_ptr = (float*) tensor_im->GetData();
  }
  bool skip_voxel;

  for(z= 0;z<= image->_tz - 1;z++) {
  for(y= 0;y<= image->_ty - 1;y++) {
  for(x= 0;x<= image->_tx - 1;x++) {

    skip_voxel=false;
    if ((image_c!=NULL)&&(SpeedUp_c)) {
      skip_voxel = (*image_c)(x,y,z)>SpeedUp_c_lowerbound;
    }
    if (!skip_voxel) {
      grad = filtre->Gradient(x,y,z);
      if (eigendecomp_mode==INITIAL) {
        *Txx_ptr =  grad.x*grad.x;
        *Txy_ptr =  grad.x*grad.y;
        *Txz_ptr =  grad.x*grad.z;
        *Tyy_ptr =  grad.y*grad.y;
        *Tyz_ptr =  grad.y*grad.z;
        *Tzz_ptr =  grad.z*grad.z;
      } else {
        T_ptr[0] = grad.x*grad.x;
        T_ptr[1] = grad.x*grad.y;
        T_ptr[2] = grad.x*grad.z;
        T_ptr[3] = grad.y*grad.y;
        T_ptr[4] = grad.y*grad.z;
        T_ptr[5] = grad.z*grad.z;
      }
    }

    if (eigendecomp_mode==INITIAL) {
      Txx_ptr++;
      Txy_ptr++;
      Txz_ptr++;
      Tyy_ptr++;
      Tyz_ptr++;
      Tzz_ptr++;
    } else 
      T_ptr += 6;

  } // endfor
  } // endfor
  } // endfor

  Tensor_timing.Fin();
  if (show_timing)
    std::cout << "Tensor_timing " << Tensor_timing << std::endl;

  filtre.reset();

  Smoothing_timing.Debut();
  // Lissage du tenseur
  // Pas optimise...
  //std::cout << "smooth xx" << std::endl;
  if (eigendecomp_mode==INITIAL) {
    Smooth( tensor_xx, sigma_2);
    Smooth( tensor_xy, sigma_2);
    Smooth( tensor_xz, sigma_2);
    Smooth( tensor_yy, sigma_2);
    Smooth( tensor_yz, sigma_2);
    Smooth( tensor_zz, sigma_2);
  } else {
    // create an image of one tensor component
    InrImage::ptr comp_image(new InrImage(WT_FLOAT,1,
                                          "comp_image.ami.gz",image));
    float* C_ptr;
    // for each component
    for(int c=0; c<6; c++) {
      // fill the component image with the values
      T_ptr = (float*) tensor_im->GetData();
      C_ptr = (float*) comp_image->GetData();
      for(int n=0; n<image->Size();n++) 
      {
        *C_ptr = T_ptr[c];
        C_ptr++;
        T_ptr+=6;
      }
      // Smooth the component
      Smoothing_timing2.Debut();
      Smooth( comp_image.get(), sigma_2);
      Smoothing_timing2.Fin();
      Smoothing_timing2.AddCumul();
      // put back the values in the tensor
      T_ptr = (float*) tensor_im->GetData();
      C_ptr = (float*) comp_image->GetData();
      for(int n=0; n<image->Size();n++) 
      {
        T_ptr[c] = *C_ptr;
        C_ptr++;
        T_ptr+=6;
      }
    }
  }
  Smoothing_timing.Fin();
  if (show_timing) {
    std::cout << "Smoothing_timing " << Smoothing_timing << std::endl;
    std::cout << "Smoothing_timing2 " << std::endl;
    Smoothing_timing2.AfficheCumul(std::cout);
  }

  if (image!=im) delete image;

  structtensor_time.Fin();
  structtensor_time.AddCumul();
//  std::cout << "End ami::AnisoGSBase::ComputeStructureTensor()" << std::endl;
  if (show_timing) 
    std::cout << structtensor_time << std::endl;

} // ComputeStructureTensor()


//------------------------------------------------------------------------------
void ami::AnisoGSBase::ComputeEigenVectors()
{
  switch(eigendecomp_mode) {
    case INITIAL:
      ComputeEigenVectors_initial();
      break;
    case NEW:
      ComputeEigenVectors_new();
      break;
  }
}

//------------------------------------------------------------------------------
void ami::AnisoGSBase::ComputeEigenVectors_initial()
{
  //std::cout << "Begin ami::AnisoGSBase::ComputeEigenVectors_initial()" << std::endl;
  eigendecomp_time.Debut();
  
  int x,y,z;
  t_3Point e0, e1, e2;


  if (!eigenvect_xp.get()) 
    eigenvect_xp =  InrImage::ptr(new InrImage( WT_SIGNED_SHORT,
                                                6, // for e1 and e2
                                                "Eigenvect_xp.ami.gz",
                                                image_entree));
  if (!eigenvect_yp.get()) 
    eigenvect_yp =  InrImage::ptr(new InrImage( WT_SIGNED_SHORT,
                                                6, // for e1 and e2
                                                "Eigenvect_yp.ami.gz",
                                                image_entree));

  if (!eigenvect_zp.get()) 
    eigenvect_zp =  InrImage::ptr(new InrImage( WT_SIGNED_SHORT,
                                                6, // for e1 and e2
                                                "Eigenvect_zp.ami.gz",
                                                image_entree));

  printf("Pre-Computing eigenvectors \n");
  for(z=ROI_zmin;z<=ROI_zmax;z++)
  for(y=ROI_ymin;y<=ROI_ymax;y++)
  for(x=ROI_xmin;x<=ROI_xmax;x++) {

    // theta in ]-pi/2,pi/2]
    // phi in ]-pi/2,pi/2]
    // x = cos(theta)*cos(phi)
    // y = cos(theta)*sin(phi)
    // z = sin(theta)

    bool skip_voxel=false;
    if ((image_c!=NULL)&&(SpeedUp_c)) {
      skip_voxel = (*image_c)(x,y,z)>SpeedUp_c_lowerbound;
    }

    if (!skip_voxel) {
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
    }


  } // for z,y,z
  printf("done \n");
/*
eigenvect_xp->Sauve();
eigenvect_yp->Sauve();
eigenvect_zp->Sauve();
*/
  eigendecomp_time.Fin();
  eigendecomp_time.AddCumul();
  
  //std::cout << "End ami::AnisoGSBase::ComputeEigenVectors()" << std::endl;
  if (show_timing)
    std::cout << eigendecomp_time << std::endl;
}


//------------------------------------------------------------------------------
void ami::AnisoGSBase::ComputeEigenVectors_new()
{
  std::cout << "Begin ami::AnisoGSBase::ComputeEigenVectors_new()" << std::endl;
  eigendecomp_time.Debut();

  if (!eigenvect2_xp.get()) 
    eigenvect2_xp =  InrImage::ptr(new InrImage(  WT_FLOAT,3,
                                                  "Eigenvect2_xp.ami.gz",
                                                  image_entree
                                               ));
  if (!eigenvect3_xp.get()) 
    eigenvect3_xp =  InrImage::ptr(new InrImage(  WT_FLOAT,3,
                                                  "Eigenvect3_xp.ami.gz",
                                                  image_entree
                                               ));
  if (!eigenvect2_yp.get()) 
    eigenvect2_yp =  InrImage::ptr(new InrImage(  WT_FLOAT,3,
                                                  "Eigenvect2_yp.ami.gz",
                                                  image_entree
                                               ));
  if (!eigenvect3_yp.get()) 
    eigenvect3_yp =  InrImage::ptr(new InrImage(  WT_FLOAT,3,
                                                  "Eigenvect3_yp.ami.gz",
                                                  image_entree
                                               ));
  if (!eigenvect2_zp.get()) 
    eigenvect2_zp =  InrImage::ptr(new InrImage(  WT_FLOAT,3,
                                                  "Eigenvect2_zp.ami.gz",
                                                  image_entree
                                               ));
  if (!eigenvect3_zp.get()) 
    eigenvect3_zp =  InrImage::ptr(new InrImage(  WT_FLOAT,3,
                                                  "Eigenvect3_zp.ami.gz",
                                                  image_entree
                                               ));

  // 1. need to create mask image
  InrImage::ptr local_mask;
  if ((image_c!=NULL)&&(SpeedUp_c)) {
    local_mask = InrImage::ptr(new InrImage(WT_UNSIGNED_CHAR,1,"mask.ami.gz",
                                      image_entree));
    unsigned char* mask_ptr = (unsigned char*) local_mask   ->GetData();
    float* c_ptr            = (float*)         image_c->GetData();
    for(int i=0;i<image_entree->Size();i++) {
      if (*c_ptr>SpeedUp_c_lowerbound)
        *mask_ptr = 0;
      else
        *mask_ptr = 255;
      c_ptr++;
      mask_ptr++;
    }
  }
    
  ami::ImageToImageFilterParam ed_param;
  // need to have the whole tensor in one image ...
  ed_param.SetInput(tensor_im);
  ed_param.SetNumberOfThreads(wxThread::GetCPUCount());
  ami::ImageExtent<int> extent;

#ifndef macro_min
  #define macro_min(n1,n2) ((n1)<(n2)?(n1):(n2))
#endif

  extent.SetMinMax(0,ROI_xmin,macro_min(ROI_xmax,image_entree->DimX()-2));
  extent.SetMinMax(1,ROI_ymin,macro_min(ROI_ymax,image_entree->DimY()-2));
  extent.SetMinMax(2,ROI_zmin,macro_min(ROI_zmax,image_entree->DimZ()-2));
  ed_param.SetOutputExtent(extent);

  // Eigenvectors at x+1/2
  ami::EigenDecomp_NRAD::ptr ed(new ami::EigenDecomp_NRAD());
  ed->SetParameters(ed_param);
  if ((image_c!=NULL)&&(SpeedUp_c)) {
    //ed->Setmask(local_mask);
  }
  ed->Setdiag_algorithm(ami::EigenDecomp::KOPP_HYBRID);
  ed->Setenable_eigenvalue1(false);
  ed->Setenable_eigenvalue2(false);
  ed->Setenable_eigenvalue3(false);
  ed->Setenable_eigenvector1(false);
  ed->Setenable_eigenvector2(true);
  ed->Setenable_eigenvector3(true);
  ed->Sethalf_displ(ami::EigenDecomp_NRAD::HALF_DISPL_X);
  ed->Seteigenvector2(eigenvect2_xp);
  ed->Seteigenvector3(eigenvect3_xp);
  ed->Run();

  // Eigenvectors at y+1/2
  ed->Sethalf_displ(ami::EigenDecomp_NRAD::HALF_DISPL_Y);
  ed->Seteigenvector2(eigenvect2_yp);
  ed->Seteigenvector3(eigenvect3_yp);
  ed->Run();

  // Eigenvectors at z+1/2
  ed->Sethalf_displ(ami::EigenDecomp_NRAD::HALF_DISPL_Z);
  ed->Seteigenvector2(eigenvect2_zp);
  ed->Seteigenvector3(eigenvect3_zp);
  ed->Run();
  ed.reset();

  //printf("done \n");

  eigendecomp_time.Fin();
  eigendecomp_time.AddCumul();
  
  std::cout << "End ami::AnisoGSBase::ComputeEigenVectors_new()" << std::endl;
  if (show_timing)
    std::cout << eigendecomp_time << std::endl;
}


//------------------------------------------------------------------------------
void ami::AnisoGSBase::InitFlux( t_3Point& e0,t_3Point& e1,t_3Point& e2)
//            --------
{
      e0.x = 1; e0.y = 0; e0.z = 0;
      e1.x = 0; e1.y = 1; e1.z = 0;
      e2.x = 0; e2.y = 0; e2.z = 1;

} // InitFlux()


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
      std::cerr << "Struture Tensor, diagonalization pb ..." 
                << "at ("<< x << ", " << y << ", " << z << ")"
                << std::endl;
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
  
  if ((!Eigenvectors_onfly)||(eigendecomp_mode==INITIAL)) {
    if (eigendecomp_mode==INITIAL)
    {
      InrImage::ptr ev;
      short* ev_buf;

      switch(coord) {
        case 0: ev = eigenvect_xp;   break;
        case 1: ev = eigenvect_yp;   break;
        case 2: ev = eigenvect_zp;   break;
      }

      ev->BufferPos(x,y,z);
      ev_buf = (short*) ev->BufferPtr();
      e1.x = MIN(1.0,(float)ev_buf[0]/MAX_SHORT); 
      e1.y = MIN(1.0,(float)ev_buf[1]/MAX_SHORT);
      e1.z = MIN(1.0,(float)ev_buf[2]/MAX_SHORT);

      e2.x = MIN(1.0,(float)ev_buf[3]/MAX_SHORT); 
      e2.y = MIN(1.0,(float)ev_buf[4]/MAX_SHORT);
      e2.z = MIN(1.0,(float)ev_buf[5]/MAX_SHORT);
    } else {
      InrImage::ptr ev2;
      InrImage::ptr ev3;
      switch(coord) {
        case 0: ev2 = eigenvect2_xp;  ev3 = eigenvect3_xp;   break;
        case 1: ev2 = eigenvect2_yp;  ev3 = eigenvect3_yp;   break;
        case 2: ev2 = eigenvect2_zp;  ev3 = eigenvect3_zp;   break;
      }
      int inc_x,inc_y,inc_z;
      ev2->GetBufferIncrements(inc_x,inc_y,inc_z);
      long d = x*inc_x+y*inc_y+z*inc_z;
      //ev2->BufferPos(x,y,z);
      //ev3->BufferPos(x,y,z);
      float* ev2_buf = ((float*) ev2->GetData())+d;
      float* ev3_buf = ((float*) ev3->GetData())+d;
      e1.x = ev2_buf[0];
      e1.y = ev2_buf[1];
      e1.z = ev2_buf[2];
      if (e1.x!=e1.x) {
        std::cout << "Numerical problem e1 at " 
                  << "(" << x << "," << y << "," << z << ") " 
                  <<", setting to(1,0,0)" << std::endl;
        e1.x = 1;
        e1.y = 0;
        e1.z = 0;
      }

      e2.x = ev3_buf[0];
      e2.y = ev3_buf[1];
      e2.z = ev3_buf[2];
      if (e2.x!=e2.x) {
        std::cout << "Numerical problem e2 at " 
                  << "(" << x << "," << y << "," << z << ") " 
                  << ", setting (0,1,1)" << std::endl;
        e2.x = 0;
        e2.y = 1;
        e2.z = 0;
      }
    }

    e0.x = e1.y*e2.z-e1.z*e2.y;
    e0.y = e1.z*e2.x-e1.x*e2.z;
    e0.z = e1.x*e2.y-e1.y*e2.x;
  } else {
    double          mat_d[3][3];
    double          vap_d[3];
    double          vep_d[3][3];
    int             success;
    int             inc[3];
    
    tensor_im->GetBufferIncrements(inc[0],inc[1],inc[2]);
    float* T_ptr = (float*) tensor_im->GetData();
    T_ptr       += x*inc[0]+y*inc[1]+z*inc[2];

    /// fill the matrix
    {
      int i,j;
      int n=0;
      for(i=0;i<3;i++)
      for(j=0;j<3;j++) {
        if (i<=j) {
          mat_d[i][j]  = T_ptr[n];
          mat_d[i][j] += T_ptr[n+inc[coord]]; 
          n++;
        } else {
          mat_d[i][j] = mat_d[j][i];
        }
      }
    }
    
    // Using hybrid method
    success = dsyevh3(  mat_d, 
                        vep_d, 
                        vap_d);
    if (success!=0) std::cout << "Error in diagonalization" << std::endl;

    // sort in descending order
    int i0 = 0, i1 = 1, i2 = 2, tmp;
    #define macro_swap(a,b) \
      { tmp = a; a = b; b = tmp; }

    if (vap_d[i0]<vap_d[i1]) macro_swap(i0,i1)
    if (vap_d[i1]<vap_d[i2]) {
      macro_swap(i1,i2)
      if (vap_d[i0]<vap_d[i1]) macro_swap(i0,i1)
    }
    
    // return the vectors
    e0.x = vep_d[0][i0];
    e0.y = vep_d[1][i0];
    e0.z = vep_d[2][i0];

    e1.x = vep_d[0][i1];
    e1.y = vep_d[1][i1];
    e1.z = vep_d[2][i1];

    e2.x = vep_d[0][i2];
    e2.y = vep_d[1][i2];
    e2.z = vep_d[2][i2];
  }
  
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
void ami::AnisoGSBase::Init(InrImage::ptr in, 
      int nb_threads
      )
{
  char resname[100];

  T = 0;
  InitParam();

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


  switch (local_structure_mode) {
    case LOCAL_STRUCT_CURV:
    case LOCAL_STRUCT_TENSOR:
      this->CreateBoundariesVonNeumann(in.get());
      this->ROI_xmin = this->boundary_extension_size;
      this->ROI_ymin = this->boundary_extension_size;
      this->ROI_xmax = image_entree->DimX()-1-boundary_extension_size;
      this->ROI_ymax = image_entree->DimY()-1-boundary_extension_size;
      if  ((mode != MODE_2D)&&(image_entree->DimZ()>1)) {
        this->ROI_zmin = this->boundary_extension_size;
        this->ROI_zmax = image_entree->DimZ()-1-boundary_extension_size;
      }
    break;
  }
  
/*
 *  filtre = new GeneralGaussianFilter(image_entree, 
      mode);
  filtre->Set_use_new_filter(UseNewConvolutionFilter);
  filtre->GammaNormalise(false);
  filtre->InitFiltre( sigma, MY_FILTRE_CONV );  
*/

  tx = image_entree->_tx;
  ty = image_entree->_ty;
  tz = image_entree->_tz;
  txy = tx*image_entree->_ty;

  //--- result_image
    sprintf(resname,"%s.AnisoGS",in->GetName());
  this->result_image = new InrImage( WT_FLOAT, resname, image_entree);

  (*this->result_image)=(*image_entree);

  iteration = 0;
  loop = 2; // loop at 2nd iteration
  max_loop = 6;

  // Initialize parameters of the ImageToImageFilter
  ami::ImageToImageFilterParam filter_param;
  // need to have the whole tensor in one image ...
  filter_param.SetInput(in);
  if (nb_threads<=0)
    filter_param.SetNumberOfThreads(wxThread::GetCPUCount());
  else
    filter_param.SetNumberOfThreads(nb_threads);
  ami::ImageExtent<int> extent;
  extent.SetMinMax(0,ROI_xmin,ROI_xmax);
  extent.SetMinMax(1,ROI_ymin,ROI_ymax);
  extent.SetMinMax(2,ROI_zmin,ROI_zmax);
  filter_param.SetOutputExtent(extent);
  SetParameters(filter_param);
// 
} // Init()


