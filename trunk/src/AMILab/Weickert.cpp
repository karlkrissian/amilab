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

#include "AMILabConfig.h"

#include "DeriveesLissees.hpp"
#include "filtrage_rec.hpp"
#include "FloatMatrix.hpp"
#include "Eigen.hpp"
//#include "fonctions.h"


#define MODE_2D 2
#define MODE_3D 3

extern  unsigned char       GB_debug;

//-------  Images
static InrImage* image_entree  = NULL;
static InrImage* image_resultat= NULL;
static InrImage* image_lissee  = NULL;
static InrImage* im_tmp        = NULL;

static unsigned char   image_entree_allouee;

static InrImage* m00  = NULL;
static InrImage* m01  = NULL;
static InrImage* m11  = NULL;


static InrImage* m02  = NULL;
static InrImage* m12  = NULL;
static InrImage* m22  = NULL;

//static InrImage*       image_coherence = NULL;

static GeneralGaussianFilter*  filtre;

//-------- Parameters
static int     mode;
static float       sigma;
static float       rho;
static float       lambda;
static float       Coh; // Coherence theshold
static float       alpha;
static float       dt;
static int     tx,ty,tz,txy;
static int     iteration;
static int     diff_type;

#define COHERENCE_DIFFUSION 0
#define EDGE_DIFFUSION      1


static void Lissage( InrImage* image, float sigma, InrImage* mask);


//----------------------------------------------------------------------
float diff_func(float s2)
//
{

  float t=s2/lambda/lambda;

  Si t<1E-4 Alors
    return 1;
  Sinon
    t=t*t;
    t=t*t;
    return 1-exp(-3.31488/t);
  FinSi

} // fonc_diff()


//----------------------------------------------------------------------
void ComputeMatrix2D(InrImage* im)
//
{

  
    int     x,y,z; 
    float      grad[2];
    float      orth[2];
    float       gradnorm2;
    float       v00,v01,v11;
    float*     Iconv;

  Si GB_debug AlorsFait fprintf(stderr,"ComputeMatrix2D() begin \n");

  filtre->MyFiltre( im, image_lissee, 0, 0, -1);

  Iconv = (float*) image_lissee->Buffer();  

  Si m00 == NULL AlorsFait m00 = new InrImage(WT_FLOAT,"m00.ami.gz",im);
  Si m01 == NULL AlorsFait m01 = new InrImage(WT_FLOAT,"m01.ami.gz",im);
  Si m11 == NULL AlorsFait m11 = new InrImage(WT_FLOAT,"m11.ami.gz",im);

  m00->InitBuffer();
  m01->InitBuffer();
  m11->InitBuffer();

  Pour(z,0,im->_tz-1)
  Pour(y,0,im->_ty-1)
  Pour(x,0,im->_tx-1)

    Si x>0 Et x< tx-1 Et y>0 Et y<ty-1 Alors

      // Computation of the smoothed gradient
      grad[0] = (*(Iconv+1 )-*(Iconv- 1))/2.0;
      grad[1] = (*(Iconv+tx)-*(Iconv-tx))/2.0;
 
      orth[0] = -grad[1];
      orth[1] = grad[0];

      v00 = grad[0]*grad[0];
      v01 = grad[0]*grad[1];
      v11 = grad[1]*grad[1];

      gradnorm2 = v00+v11;
 
      v00 *= diff_func(gradnorm2);
      v01 *= diff_func(gradnorm2);
      v11 *= diff_func(gradnorm2);

      v00 += orth[0]*orth[0];
      v01 += orth[0]*orth[1];
      v11 += orth[1]*orth[1];

      v00 /= gradnorm2;
      v01 /= gradnorm2;
      v11 /= gradnorm2;

      m00->FixeValeur(v00);
      m01->FixeValeur(v01);
      m11->FixeValeur(v11);

    Sinon

      m00->FixeValeur(0);
      m01->FixeValeur(0);
      m11->FixeValeur(0);

    FinSi

    Iconv++;
    m00->IncBuffer();
    m01->IncBuffer();
    m11->IncBuffer();

  FinPour
  FinPour
  FinPour  

  Si GB_debug AlorsFait fprintf(stderr,"ComputeMatrix2D() end \n");

} // ComputeMatrix2D()



//----------------------------------------------------------------------
void Lissage( InrImage* image, float sigma, InrImage* mask)
//
{

  
    GeneralGaussianFilter* filtre;

  filtre = new GeneralGaussianFilter(image, MODE_3D);
  filtre->SetScaleUnit(PIXEL_SPACE);
  filtre->Utilise_Image(   true);
  filtre->UtiliseGradient( false);
  filtre->InitDerivees();
  filtre->GammaNormalise(  false);
  filtre->InitFiltre( sigma, MY_FILTRE_CONV);
  filtre->CalculFiltres( mask);
  (*image) = (*(*filtre)(IM_sigma));
  delete filtre;

} // Lissage()


//----------------------------------------------------------------------
//
void ComputeMatrix3D(InrImage* im)
//
{

  
    int     x,y,z; 
    float       v00,v01,v11,v02,v12,v22;
    float*     Iconv;
    Vect3D<double>  grad;
    FloatMatrix     matrice(3,3);
    float           vap[3];
    float           lambda[3];
    FloatMatrix     vec_propre(3,3);
    int             niter;
    unsigned char         Diagonale = false;
    double      kappa;

/*
  Si image_coherence == NULL Alors
    image_coherence = new InrImage(WT_FLOAT,"coherence.ami.gz",im);
    image_coherence->InitImage(0.0);
  FinSi
*/

  Si GB_debug AlorsFait fprintf(stderr,"ComputeMatrix3D() begin \n");

  filtre->MyFiltre( im, image_lissee, 0, 0, -1);

  Iconv = (float*) image_lissee->Buffer();  

  Si m00 == NULL AlorsFait m00 = new InrImage(WT_FLOAT,"m00.ami.gz",im);
  Si m01 == NULL AlorsFait m01 = new InrImage(WT_FLOAT,"m01.ami.gz",im);
  Si m11 == NULL AlorsFait m11 = new InrImage(WT_FLOAT,"m11.ami.gz",im);
  Si m02 == NULL AlorsFait m02 = new InrImage(WT_FLOAT,"m02.ami.gz",im);
  Si m12 == NULL AlorsFait m12 = new InrImage(WT_FLOAT,"m12.ami.gz",im);
  Si m22 == NULL AlorsFait m22 = new InrImage(WT_FLOAT,"m22.ami.gz",im);

  // Computation the structure tensor

  m00->InitBuffer();
  m01->InitBuffer();
  m11->InitBuffer();
  m02->InitBuffer();
  m12->InitBuffer();
  m22->InitBuffer();

  Pour(z,0,im->_tz-1)
  Pour(y,0,im->_ty-1)
  Pour(x,0,im->_tx-1)

    Si x>0 Et x<tx-1 Et y>0 Et y<ty-1 Et z>0 Et z<tz-1 Alors

      grad.x = (*(Iconv+1)  -*(Iconv-1  ))/2.0;
      grad.y = (*(Iconv+tx) -*(Iconv-tx ))/2.0;
      grad.z = (*(Iconv+txy)-*(Iconv-txy))/2.0;
 
    Sinon

      grad.x = grad.y = grad.z = 0.0;

    FinSi

    m00->FixeValeur( grad.x*grad.x );
    m01->FixeValeur( grad.x*grad.y );
    m11->FixeValeur( grad.y*grad.y );
    m02->FixeValeur( grad.x*grad.z );
    m12->FixeValeur( grad.y*grad.z );
    m22->FixeValeur( grad.z*grad.z );

    m00->IncBuffer();
    m01->IncBuffer();
    m11->IncBuffer();
    m02->IncBuffer();
    m12->IncBuffer();
    m22->IncBuffer();
    Iconv++;

  FinPour
  FinPour
  FinPour

  Lissage( m00, rho, NULL);
  Lissage( m01, rho, NULL);
  Lissage( m11, rho, NULL);
  Lissage( m02, rho, NULL);
  Lissage( m12, rho, NULL);
  Lissage( m22, rho, NULL);


  // Computation of the diffusion matrix

  m00->InitBuffer();
  m01->InitBuffer();
  m11->InitBuffer();
  m02->InitBuffer();
  m12->InitBuffer();
  m22->InitBuffer();

  Pour(z,0,im->_tz-1)
  Pour(y,0,im->_ty-1)
  Pour(x,0,im->_tx-1)

    Si x>0 Et x<tx-1 Et y>0 Et y<ty-1 Et z>0 Et z<tz-1 Alors

      matrice[0][0] = m00->ValeurBuffer();
      matrice[0][1] = 
      matrice[1][0] = m01->ValeurBuffer();
      matrice[0][2] =
      matrice[2][0] = m02->ValeurBuffer();
      matrice[1][1] = m11->ValeurBuffer();
      matrice[1][2] =
      matrice[2][1] = m12->ValeurBuffer();
      matrice[2][2] = m22->ValeurBuffer();

      // Calcul des vep et des vap dans les images associ�es

      Diagonale = jacobi( matrice, 3, 
			  vap, 
			  vec_propre, 
			  &niter );

      Si Diagonale Alors
        eigsrt(vap,  vec_propre, 3);

        // Computation of kappa (coherence)
        kappa = 0;
        kappa += (vap[0]-vap[1])*(vap[0]-vap[1]);
        kappa += (vap[0]-vap[2])*(vap[0]-vap[2]);
        kappa += (vap[1]-vap[2])*(vap[1]-vap[2]);

//        image_coherence->BufferPos(x,y,z);
//        image_coherence->FixeValeur(kappa);

        // Computation of the lambda_i
        lambda[0] = lambda[1] = alpha;
        Si kappa<1E-5 Alors
  	  lambda[2] = alpha;
        Sinon
  	  lambda[2] = alpha + (1-alpha)*exp(-Coh/kappa);
        FinSi

        // Computation of the diffusion matrix
        v00 = lambda[0]*vec_propre[0][0]*vec_propre[0][0];
        v01 = lambda[0]*vec_propre[0][0]*vec_propre[1][0];
        v02 = lambda[0]*vec_propre[0][0]*vec_propre[2][0];
        v11 = lambda[0]*vec_propre[1][0]*vec_propre[1][0];
        v12 = lambda[0]*vec_propre[1][0]*vec_propre[2][0];
        v22 = lambda[0]*vec_propre[2][0]*vec_propre[2][0];

        v00 += lambda[1]*vec_propre[0][1]*vec_propre[0][1];
        v01 += lambda[1]*vec_propre[0][1]*vec_propre[1][1];
        v02 += lambda[1]*vec_propre[0][1]*vec_propre[2][1];
        v11 += lambda[1]*vec_propre[1][1]*vec_propre[1][1];
        v12 += lambda[1]*vec_propre[1][1]*vec_propre[2][1];
        v22 += lambda[1]*vec_propre[2][1]*vec_propre[2][1];

        v00 += lambda[2]*vec_propre[0][2]*vec_propre[0][2];
        v01 += lambda[2]*vec_propre[0][2]*vec_propre[1][2];
        v02 += lambda[2]*vec_propre[0][2]*vec_propre[2][2];
        v11 += lambda[2]*vec_propre[1][2]*vec_propre[1][2];
        v12 += lambda[2]*vec_propre[1][2]*vec_propre[2][2];
        v22 += lambda[2]*vec_propre[2][2]*vec_propre[2][2];

      FinSi

    Sinon

    FinSi

    Iconv++;
    m00->IncBuffer();
    m01->IncBuffer();
    m11->IncBuffer();
    m02->IncBuffer();
    m12->IncBuffer();
    m22->IncBuffer();


  FinPour
  FinPour
  FinPour  

  //  Vars.AddImage("im_kappa",image_coherence);

  Si GB_debug AlorsFait fprintf(stderr,"ComputeMatrix3D() end \n");

} // ComputeMatrix3D()



//----------------------------------------------------------------------
void IterateWeickert2D( InrImage* im )
//
{

   
    int x,y,z;
    int i,j;
    float   val0;
    float   M[3][3];
    float*  in;
    float*  out;
    float*  in1;
    float*  in2;
    float*  mA;
    float*  mB;
    float*  mC;

#define mask(i,j) M[i+1][j+1]

  Si im_tmp == NULL AlorsFait
    im_tmp = new InrImage(WT_FLOAT, "im_tmp.inr.gz", im);

  ComputeMatrix2D(im);

  in  = (float*) im    ->Buffer();
  out = (float*) im_tmp->Buffer();
  mA   = (float*) m00   ->Buffer();
  mB   = (float*) m01   ->Buffer();
  mC   = (float*) m11   ->Buffer();

  Pour(z,0,im->_tz-1)
  Pour(y,0,im->_ty-1)
  Pour(x,0,im->_tx-1)
  
    Si x>0 Et x< tx-1 Et y>0 Et y<ty-1 Alors

      mask(-1, 1) = -(*(mB-1)+*(mB+tx))/2.0;
      mask( 0, 1) =  (*(mC+tx)+*mC);
      mask( 1, 1) =  (*(mB+1)+*(mB+tx))/2.0;

      mask(-1, 0) =  (*(mA-1)+*mA);
      mask( 0, 0) = -(*(mA-1 )+ 2*(*mA)+*(mA+1 )+ 
                      *(mC-tx)+ 2*(*mC)+*(mC+tx) );
      mask( 1, 0) =  (*(mA+1)+*mA);

      mask(-1,-1) =  (*(mB-1)+*(mB-tx))/2.0;
      mask( 0,-1) =  (*(mC-tx)+*mC);
      mask( 1,-1) = -(*(mB+1)+*(mB-tx))/2.0;

      val0 = 0;

      in1  = in -1 -tx;

      Pour(j,-1,1)
        in2 = in1;
        Pour(i,-1,1)
          val0 += mask(i,j)* *in2;
          in2++;
        FinPour
        in1 += tx;
      FinPour

      *out = *in + dt*val0/2;
    Sinon
      *out = *in;

    FinSi

    in++;
    out++;
    mA++;
    mB++;
    mC++;

  FinPour
  FinPour
  FinPour

  (*im) = (*im_tmp);

#undef mask

} // IterateWeickert2D()


//----------------------------------------------------------------------
void IterateWeickert3D( InrImage* im )
//
{

   
    int x,y,z;
    int i,j,k;
    float   val0;
    float   M[3][3][3];
    float*  in;
    float*  out;
    float*  in1;
    float*  in2;
    float*  in3;
    float*  mA;
    float*  mB;
    float*  mC;
    float*  mD;
    float*  mE;
    float*  mF;

#define mask(i,j,k) M[i+1][j+1][k+1]

  Si im_tmp == NULL AlorsFait
    im_tmp = new InrImage(WT_FLOAT, "im_tmp.inr.gz", im);

  ComputeMatrix3D(im);

  in  = (float*) im    ->Buffer();
  out = (float*) im_tmp->Buffer();
  mA   = (float*) m00   ->Buffer();
  mB   = (float*) m01   ->Buffer();
  mC   = (float*) m02   ->Buffer();
  mD   = (float*) m11   ->Buffer();
  mE   = (float*) m12   ->Buffer();
  mF   = (float*) m22   ->Buffer();

  Pour(z,0,im->_tz-1)
  Pour(y,0,im->_ty-1)
  Pour(x,0,im->_tx-1)
  
    Si x>0 Et x< tx-1 Et y>0 Et y<ty-1 Et z>0 Et z<tz-1 Alors

      // Z-
      mask(-1, 1,-1) =  0;
      mask( 0, 1,-1) = -(*(mE-txy)+*(mE+tx))/2.0;
      mask( 1, 1,-1) =  0;

      mask(-1, 0,-1) =  (*(mC-1)+*(mC-txy))/2.0;
      mask( 0, 0,-1) =  (*(mF-txy )+ *mF);
      mask( 1, 0,-1) = -(*(mC+1)+*(mC-txy))/2.0;

      mask(-1,-1,-1) =  0;
      mask( 0,-1,-1) =  (*(mE-txy)+*(mE-tx))/2.0;
      mask( 1,-1,-1) =  0;

      // Z
      mask(-1, 1, 0) = -(*(mB-1)+*(mB+tx))/2.0;
      mask( 0, 1, 0) =  (*(mD+tx)+*mD);
      mask( 1, 1, 0) =  (*(mB+1)+*(mB+tx))/2.0;

      mask(-1, 0, 0) =  (*(mA-1)+*mA);
      mask( 0, 0, 0) = -(
			 *(mA-1  )+ 2*(*mA)+*(mA+1  )+ 
			 *(mD-tx )+ 2*(*mD)+*(mD+tx )+
			 *(mF-txy)+ 2*(*mF)+*(mF+txy)
			 );
      mask( 1, 0, 0) =  (*(mA+1)+*mA);

      mask(-1,-1, 0) =  (*(mB-1)+*(mB-tx))/2.0;
      mask( 0,-1, 0) =  (*(mD-tx)+*mD);
      mask( 1,-1, 0) = -(*(mB+1)+*(mB-tx))/2.0;

      // Z+
      mask(-1, 1, 1) =  0;
      mask( 0, 1, 1) =  (*(mE+txy)+*(mE+tx))/2.0;
      mask( 1, 1, 1) =  0;

      mask(-1, 0, 1) = -(*(mC-1)+*(mC-txy))/2.0;
      mask( 0, 0, 1) =  (*(mF+txy )+ *mF);
      mask( 1, 0, 1) =  (*(mC+1)+*(mC+txy))/2.0;

      mask(-1,-1, 1) =  0;
      mask( 0,-1, 1) = -(*(mE+txy)+*(mE-tx))/2.0;
      mask( 1,-1, 1) =  0;

      val0 = 0;


      in1  = in -1 -tx - txy;

      Pour(k,-1,1)
        in2 = in1;
        Pour(j,-1,1)
          in3 = in2;
          Pour(i,-1,1)
            val0 += mask(i,j,k)* *in3;
            in3++;
          FinPour
          in2 += tx;
        FinPour
        in1 += txy;
      FinPour

      *out = *in + dt*val0/2;
    Sinon
      *out = *in;

    FinSi

    in++;
    out++;
    mA++;
    mB++;
    mC++;
    mD++;
    mE++;
    mF++;

  FinPour
  FinPour
  FinPour

  (*im) = (*im_tmp);

#undef mask

} // IterateWeickert3D()


//----------------------------------------------------------------------
InrImage* Func_InitWeickert(InrImage* in, 
			    float p_sigma, 
			    float p_lambda,
			    float p_dt
			    )
{
  
    char resname[100];

  Si GB_debug AlorsFait fprintf(stderr,"Func_InitWeickert() begin \n");

  diff_type = EDGE_DIFFUSION;

  im_tmp = NULL;

  sigma       = p_sigma;
  lambda      = p_lambda;
  dt          = p_dt;

  tx = in->_tx;
  ty = in->_ty;
  tz = in->_tz;
  txy = tx*ty;

  Si tz>1 Alors mode=MODE_3D; Sinon mode=MODE_2D; FinSi

  // conversion de l'image initiale en float
  image_entree = new InrImage( WT_FLOAT, "image_reel.inr.gz", in);
  image_entree_allouee=true;
  (*image_entree) = (*in);

  //--- image_resultat
  sprintf(resname,"%s.Weickert",in->GetName());
  image_resultat = new InrImage( WT_FLOAT, resname, in);
  (*image_resultat)=(*in);

  filtre = NULL;
  image_lissee = new InrImage( WT_FLOAT, "image_lissee.inr.gz", in);

  filtre = new GeneralGaussianFilter(image_entree, 
				mode);
  filtre->GammaNormalise(false);
  filtre->InitFiltre( sigma, MY_FILTRE_CONV );  


  iteration = 0;

  Si GB_debug AlorsFait fprintf(stderr,"Func_InitWeickert() end \n");

  return image_resultat;

} // Func_InitWeickert()


//----------------------------------------------------------------------
InrImage* Func_InitWeickertCoherence(InrImage* in, 
				     float p_sigma, 
				     float p_rho, 
				     float p_C,
				     float p_alpha,
				     float p_dt
			    )
{
  
    char resname[100];

  Si GB_debug AlorsFait fprintf(stderr,"Func_InitWeickert() begin \n");

  diff_type = COHERENCE_DIFFUSION;

  im_tmp = NULL;

  sigma       = p_sigma;
  rho         = p_rho;
  Coh         = p_C;
  alpha       = p_alpha;
  dt          = p_dt;

  tx = in->_tx;
  ty = in->_ty;
  tz = in->_tz;
  txy = tx*ty;

  Si tz>1 Alors mode=MODE_3D; Sinon mode=MODE_2D; FinSi

  // conversion de l'image initiale en float
  image_entree = new InrImage( WT_FLOAT, "image_reel.inr.gz", in);
  image_entree_allouee=true;
  (*image_entree) = (*in);

  //--- image_resultat
  sprintf(resname,"%s.Weickert",in->GetName());
  image_resultat = new InrImage( WT_FLOAT, resname, in);
  (*image_resultat)=(*in);

  filtre = NULL;
  image_lissee = new InrImage( WT_FLOAT, "image_lissee.inr.gz", in);

  filtre = new GeneralGaussianFilter(image_entree, 
				mode);
  filtre->GammaNormalise(false);
  filtre->InitFiltre( sigma, MY_FILTRE_CONV );  


  iteration = 0;

  Si GB_debug AlorsFait fprintf(stderr,"Func_InitWeickert() end \n");

  return image_resultat;

} // Func_InitWeickert()


//----------------------------------------------------------------------
void Func_IterateWeickert()
{

  Si GB_debug AlorsFait fprintf(stderr,"Func_IterateWeickert() begin \n");

  Si image_resultat==NULL Alors
    fprintf(stderr,"Func_IterateWeickert() Weickert not initialized \n");
    return;
  FinSi

  iteration++;

  Si mode == MODE_2D Alors
    Si diff_type == EDGE_DIFFUSION Alors
      IterateWeickert2D(    image_resultat);
    Sinon
      fprintf(stderr,"Func_IterateWeickert()\t 2D coherence diffusion not implemented \n");
    FinSi
  Sinon
    Si diff_type == COHERENCE_DIFFUSION Alors
      IterateWeickert3D(    image_resultat);
    Sinon
      fprintf(stderr,"Func_IterateWeickert()\t 3D edge diffusion not implemented \n");
    FinSi
  FinSi
    
  printf(" iteration %d \n", iteration);
  
  Si GB_debug AlorsFait fprintf(stderr,"Func_IterateWeickert() end \n");

} // Func_IterateWeickert()



//----------------------------------------------------------------------
int Func_EndWeickert()
{


  Si filtre     != NULL Alors
    delete filtre;
    filtre = NULL;
  FinSi

  Si image_lissee != NULL Alors
    delete image_lissee;
    image_lissee=NULL;
  FinSi

  Si im_tmp != NULL Alors
    delete im_tmp;
    im_tmp = NULL;
  FinSi

  Si m00 != NULL Alors
    delete m00;
    m00 = NULL;
  FinSi

  Si m01 != NULL Alors
    delete m01;
    m01 = NULL;
  FinSi

  Si m11 != NULL Alors
    delete m11;
    m11 = NULL;
  FinSi

  Si m02 != NULL Alors
    delete m02;
    m02 = NULL;
  FinSi

  Si m12 != NULL Alors
    delete m12;
    m12 = NULL;
  FinSi

  Si m22 != NULL Alors
    delete m22;
    m22 = NULL;
  FinSi

  delete image_entree;
  image_entree=NULL;

  return 1;

} // Func_EndWeickert()
