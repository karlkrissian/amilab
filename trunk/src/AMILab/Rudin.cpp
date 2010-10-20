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

#include "Rudin.h"

//
double minmod(double a, double b) 
//     ------
{
  if ((a>0)&&(b>0)) {
	return (a<b?a:b);
      }
      else
	if  ((a<0)&&(b<0)) {
	  return (a>b?a:b);
	}
	else 
	  return 0.0;

}

//
//
InrImage* Func_RudinMultiplicative2D(InrImage* input, float dt, int num_iterations, int attach, int scheme)
//        --------------------------
// attach: 1 use the data attachment
//         0 no data attachment
//
// scheme: 0 Rudin with minmod
//         1 central differences
{

  double dx,dy=0.0,norm;
  int x,y,n;
  int tx;

  double div;

  InrImage* res1;
  InrImage* res2;
  float* res1_buf;
  float* res2_buf;

  float I0;
  float* I;
  float* Ip0;
  float* Im0;
  float* I0m;
  float* I0p;
  float* Ipm;
  float* Ipp;
  float* Imm;
  float* Imp;

  double A1,B1,C1,A2,C2;
  double S1, S2;
  double dg_du;
  double dgm12_du; // d(g-1)^2 / du

  double det,mu,lambda;
//  double variance;

  double current_noise_mean;
  double current_noise_sd;

  res1 = new InrImage(WT_FLOAT, "Rudin.ami.gz",input);
  res2 = new InrImage(WT_FLOAT, "Rudin.ami.gz",input);

  (*res1) = (*input);

  tx =  input->DimX();

  Pour(n,1,num_iterations)

    res1_buf = (float*) res1->Buffer(); 
    res2_buf = (float*) res2->Buffer(); 

    A1 = B1 = C1 = A2 = C2 = 0.0;
    S1 = S2 = 0;

    current_noise_mean=0;
    current_noise_sd=0;

    Pour(y,0,input->DimY()-1)
    Pour(x,0,input->DimX()-1)

      I0 = (*input)(x,y,0);

      I   = res1_buf;
      Im0 = I;
      Ip0 = I;
      I0m = I;
      I0p = I;

      if (x<input->DimX()-1) Ip0 += 1;
      if (y<input->DimY()-1) I0p += tx;
      if (x>0)               Im0 -= 1;
      if (y>0)               I0m -= tx;

      Imm = Im0;
      Imp = Im0;
      Ipm = Ip0;
      Ipp = Ip0;

      if (y<input->DimY()-1) {
        Imp += tx;
        Ipp += tx;
      }
      if (y>0) {
        Imm -= tx;
        Ipm -= tx;
      }

      // --------------------------------------------------
      // 1. compute div( nabla I / || nabla I || )
      // --------------------------------------------------

      div = 0;
      // Gradient at x+1/2
      dx = (*Ip0)-(*I);
      switch (scheme) {
      case 0: dy = minmod(*I0p-*I,*I-*I0m); break;
      case 1: dy = ((*Ipp)-(*Ipm) + ( (*I0p)-(*I0m)))/4; break;
      case 2: dy = minmod(*I0p-*I+*Ipp-*Ip0,*I-*I0m+*Ip0-*Ipm)/2.0; break;
      }

      norm = sqrt(dx*dx+dy*dy);
      if (norm>1E-2) div += dx/norm;

      // Gradient at x-1/2
      dx = (*I)-(*Im0);
      switch (scheme) {
      case 0: dy = minmod(*Imp-*Im0,*Im0-*Imm); break;
      case 1: dy = ((*Imp)-(*Imm) + ( (*I0p)-(*I0m)))/4; break;
      case 2: dy = minmod(*Imp-*Im0+*I0p-*I,*Im0-*Imm+*I-*I0m)/2.0; break;
      }
      norm = sqrt(dx*dx+dy*dy);
      if (norm>1E-2) div -= dx/norm;

      // Gradient at y+1/2
      switch (scheme) {
      case 0: dx = minmod(*Ip0-*I,*I-*Im0); break;
      case 1: dx = ((*Ipp)-(*Imp) + ( (*Ip0)-(*Im0)))/4; break;
      case 2: dx = minmod(*Ip0-*I+*Ipp-*I0p,*I-*Im0+*I0p-*Imp)/2.0; break;
      }
      dy = (*I0p)-(*I);
      norm = sqrt(dx*dx+dy*dy);
      if (norm>1E-2) div += dy/norm;

      // Gradient at y-1/2
      switch (scheme) {
      case 0: dx = minmod(*Ipm-*I0m,*I0m-*Imm); break;
      case 1: dx = ((*Ipm)-(*Imm) + ( (*Ip0)-(*Im0)))/4; break;
      case 2: dx = minmod(*Ipm-*I0m+*Ip0-*I,*I0m-*Imm+*I-*Im0)/2.0; break;
      }
      dy = (*I)-(*I0m);
      norm = sqrt(dx*dx+dy*dy);
      if (norm>1E-2) div -= dy/norm;

      //--------------------------------------------------
      // Compute the different coefficients
      //--------------------------------------------------

      if ((attach)&&((*I)>0.9)) {
        dg_du  = - I0/((*I)*(*I));
        dgm12_du = - 2.0*I0*I0/((*I)*(*I)*(*I));

        A1 += dg_du*dgm12_du;
        B1 += dg_du*dg_du;
        C1 += dg_du*div;
        A2 += dgm12_du*dgm12_du;
        C2 += dgm12_du*div;

	/*
	double v = (*I)+dt*div;
	S1 += I0*I0/ v/v;
	S2 += I0*I0*I0*I0/(v*v*v)/((*I)*(*I)*(*I));
	*/

      }

      current_noise_mean += I0/(*I);
      current_noise_sd   += I0*I0/(*I)/(*I);

      // Add the divergence to the result
      *res2_buf = *res1_buf+div*dt;

      res1_buf++;
      res2_buf++;

    FinPour
    FinPour


    // compute lambda and mu

    if (attach) {
    // compute determinant
    det = A1*A1-A2*B1;
    if (fabsf(det)>1E-10) {
      mu     = - A2*C1+A1*C2;
      lambda = A1*C1 - B1*C2;
      mu /= det;
      lambda /=det;
      //

      /*
      // try new option
      variance = 0.5*0.5;

      S1 /= input->Size();
      S2 /= input->Size();
      lambda= (S1 - variance -1)/(2*dt*S2);
      if (lambda<-1) {
	printf("lambda = %f, changing to -1  \n",lambda);
	lambda=-10;
      }
      if (lambda>10) {
	printf("lambda = %f, changing to 10  \n",lambda);
	lambda=10;
      }
      mu=0;

      */
    }
    else
      {
	fprintf(stderr,"it %d, Rudin Multiplicative: determinant = %f < 1E-10 ... !!! \n",n,det);
	lambda = mu = 0;
      }

    // Update the constraints

    res1_buf = (float*) res1->Buffer(); 
    res2_buf = (float*) res2->Buffer(); 

    Pour(y,0,input->DimY()-1)
    Pour(x,0,input->DimX()-1)

      I0 = (*input)(x,y,0);
      I   = res1_buf;

      if ((*I)>0.9) {
        dg_du    = - I0/((*I)*(*I));
	//        dgm12_du = 2.0*I0*((*I)-I0)/((*I)*(*I)*(*I));
        dgm12_du = -2*I0*I0/((*I)*(*I)*(*I));

	*res2_buf += - dt*(lambda*dgm12_du + mu*dg_du);   
      }

      res1_buf++;
      res2_buf++;

    FinPour
    FinPour

    if (n%10 ==0) {
      printf("iteration %d, lambda = %f, mu = %f \n",n,lambda,mu);
    }
    } // attach
    else 
      {
	if (n%10 ==0) {
	  printf("it %d \t",n);fflush(stdout);
	}
      }
    if (n%10 ==0) {
      current_noise_mean /= input->Size();
      current_noise_sd   /= input->Size();
      printf("noise : (%3.3f,%3.3f) \n",
	     current_noise_mean,
	     sqrt(current_noise_sd-current_noise_mean*current_noise_mean));
    }
    (*res1) = (*res2);

  FinPour // iterations


  delete res1;
  return res2;

} // Func_RudinMultiplicative2D()


//----------------------------------------------------------------------
//
void ComputeGradientP(float* I, double& d1, double& d2, double& d3, 
		      int p1, int p2, int m2, int p3, int m3, int scheme)
{
  // Gradient at x+1/2
  d1 = (*(I+p1))-(*I);
  switch (scheme) {
  case 0: 
    d2 = minmod(*(I+p2)-*I,*I-*(I+m2)); 
    d3 = minmod(*(I+p3)-*I,*I-*(I+m3)); 
    break;
    //case 1: dy = (*(I+px+py)-*(I+px+my) +  *(I+py)-*(I+my))/4; break;
    //case 1: dz = (*(I+px+pz)-*(I+px+mz) +  *(I+pz)-*(I+mz))/4; break;
  case 2: 
    d2 = minmod(*(I+p2)-*I     +*(I+p1+p2)-*(I+p1),
		*I     -*(I+m2)+*(I+p1)   -*(I+p1+m2))/2.0;
    d3 = minmod(*(I+p3)-*I     +*(I+p1+p3)-*(I+p1),
		*I     -*(I+m3)+*(I+p1)   -*(I+p1+m3))/2.0;
    break;
  default: fprintf(stderr, "Rudin, scheme not available ...\n");
  }

}

//----------------------------------------------------------------------
//
void ComputeGradientM(float* I, double& d1, double& d2, double& d3, 
		      int m1, int p2, int m2, int p3, int m3, int scheme)
{
  float* Im1 = I+m1;

  // Gradient at x-1/2
  d1 = (*Im1)-(*I);
  switch (scheme) {
  case 0: 
    d2 = minmod(*(Im1+p2)-*Im1,*Im1-*(Im1+m2)); 
    d3 = minmod(*(Im1+p3)-*Im1,*Im1-*(Im1+m3)); 
    break;
    //case 1: dy = (*(I+px+py)-*(I+px+my) +  *(I+py)-*(I+my))/4; break;
    //case 1: dz = (*(I+px+pz)-*(I+px+mz) +  *(I+pz)-*(I+mz))/4; break;
  case 2: 
    d2 = minmod(*(Im1+p2)-*Im1     +*(I+p2)-*(I),
		*Im1     -*(Im1+m2)+*I     -*(I+m2))/2.0;
    d3 = minmod(*(Im1+p3)-*Im1     +*(I+p3)-*I,
		*Im1     -*(Im1+m3)+*I     -*(I+m3))/2.0;
    break;
  default: fprintf(stderr, "Rudin, scheme not available ...\n");
  }

}

//----------------------------------------------------------------------
//
InrImage* Func_RudinMultiplicative3D(InrImage* input, float dt, int num_iterations, int attach, int scheme)
//        --------------------------
// attach: 1 use the data attachment
//         0 no data attachment
//
// scheme: 0 Rudin with minmod
//         1 central differences
{

  double dx,dy,dz,norm;
  int x,y,z,n;
  int tx,txy;

  double div;

  InrImage* res1;
  InrImage* res2;
  float* res1_buf;
  float* res2_buf;

  float I0;
  float* I;
  int px,py,pz,mx,my,mz;

  double A1,B1,C1,A2,C2;
  double S1, S2;
  double dg_du;
  double dgm12_du; // d(g-1)^2 / du

  double det,mu,lambda;
//  double variance;

  double current_noise_mean;
  double current_noise_sd;

  res1 = new InrImage(WT_FLOAT, "Rudin.ami.gz",input);
  res2 = new InrImage(WT_FLOAT, "Rudin.ami.gz",input);

  (*res1) = (*input);

  tx  =  input->DimX();
  txy =  input->DimX()*input->DimY();

  Pour(n,1,num_iterations)

    res1_buf = (float*) res1->Buffer(); 
    res2_buf = (float*) res2->Buffer(); 

    A1 = B1 = C1 = A2 = C2 = 0.0;
    S1 = S2 = 0;

    current_noise_mean=0;
    current_noise_sd=0;

    Pour(z,0,input->DimZ()-1)
    Pour(y,0,input->DimY()-1)
    Pour(x,0,input->DimX()-1)

      I0 = (*input)(x,y,z);

      I   = res1_buf;

      px = 1;
      mx = -1;
      py = tx;
      my = -tx;
      pz = txy;
      mz = -txy;

      if (x==input->DimX()-1) px=0;
      if (x==0)               mx=0;
      if (y==input->DimY()-1) py=0;
      if (y==0)               my=0;
      if (z==input->DimZ()-1) pz=0;
      if (z==0)               mz=0;


      dx=dy=dz=0;
      // --------------------------------------------------
      // 1. compute div( nabla I / || nabla I || )
      // --------------------------------------------------

      div = 0;
      // Gradient at x+1/2
      ComputeGradientP(I,dx,dy,dz,px,py,my,pz,mz, scheme);
      norm = sqrt(dx*dx+dy*dy+dz*dz);
      if (norm>1E-5) div += dx/norm;

      // Gradient at x-1/2
      ComputeGradientM(I,dx,dy,dz,mx,py,my,pz,mz, scheme);
      norm = sqrt(dx*dx+dy*dy+dz*dz);
      if (norm>1E-5) div += dx/norm;

     // Gradient at y+1/2
      ComputeGradientP(I,dy,dx,dz,py,px,mx,pz,mz, scheme);
      norm = sqrt(dx*dx+dy*dy+dz*dz);
      if (norm>1E-5) div += dy/norm;

      // Gradient at y-1/2
      ComputeGradientM(I,dy,dx,dz,my,px,mx,pz,mz, scheme);
      norm = sqrt(dx*dx+dy*dy+dz*dz);
      if (norm>1E-5) div += dy/norm;

     // Gradient at z+1/2
      ComputeGradientP(I,dz,dx,dy,pz,px,mx,py,my, scheme);
      norm = sqrt(dx*dx+dy*dy+dz*dz);
      if (norm>1E-5) div += dz/norm;

      // Gradient at z-1/2
      ComputeGradientM(I,dz,dx,dy,mz,px,mx,py,my, scheme);
      norm = sqrt(dx*dx+dy*dy+dz*dz);
      if (norm>1E-5) div += dz/norm;


      //--------------------------------------------------
      // Compute the different coefficients
      //--------------------------------------------------

      if ((attach)&&((*I)>0.9)) {
        dg_du  = - I0/((*I)*(*I));
        dgm12_du = - 2.0*I0*I0/((*I)*(*I)*(*I));

        A1 += dg_du*dgm12_du;
        B1 += dg_du*dg_du;
        C1 += dg_du*div;
        A2 += dgm12_du*dgm12_du;
        C2 += dgm12_du*div;

	/*
	double v = (*I)+dt*div;
	S1 += I0*I0/ v/v;
	S2 += I0*I0*I0*I0/(v*v*v)/((*I)*(*I)*(*I));
	*/

      }

      current_noise_mean += I0/(*I);
      current_noise_sd   += I0*I0/(*I)/(*I);

      // Add the divergence to the result
      *res2_buf = *res1_buf+div*dt;

      res1_buf++;
      res2_buf++;

    FinPour // x
    FinPour // y
    FinPour // z


    // compute lambda and mu

    if (attach) {
    // compute determinant
    det = A1*A1-A2*B1;
    if (fabsf(det)>1E-10) {
      mu     = - A2*C1+A1*C2;
      lambda = A1*C1 - B1*C2;
      mu /= det;
      lambda /=det;
      //

      /*
      // try new option
      variance = 0.5*0.5;

      S1 /= input->Size();
      S2 /= input->Size();
      lambda= (S1 - variance -1)/(2*dt*S2);
      if (lambda<-1) {
	printf("lambda = %f, changing to -1  \n",lambda);
	lambda=-10;
      }
      if (lambda>10) {
	printf("lambda = %f, changing to 10  \n",lambda);
	lambda=10;
      }
      mu=0;

       */
    }
    else
      {
	fprintf(stderr,"it %d, Rudin Multiplicative: determinant = %f < 1E-10 ... !!! \n",n,det);
	lambda = mu = 0;
      }

    // Update the constraints

    res1_buf = (float*) res1->Buffer(); 
    res2_buf = (float*) res2->Buffer(); 

    Pour(z,0,input->DimZ()-1)
    Pour(y,0,input->DimY()-1)
    Pour(x,0,input->DimX()-1)

      I0 = (*input)(x,y,z);
      I   = res1_buf;

      if ((*I)>0.9) {
        dg_du    = - I0/((*I)*(*I));
	//        dgm12_du = 2.0*I0*((*I)-I0)/((*I)*(*I)*(*I));
        dgm12_du = -2*I0*I0/((*I)*(*I)*(*I));

	*res2_buf += - dt*(lambda*dgm12_du + mu*dg_du);   
      }

      res1_buf++;
      res2_buf++;

    FinPour // x
    FinPour // y
    FinPour // z

    if (n%10 ==0) {
      printf("iteration %d, lambda = %f, mu = %f \n",n,lambda,mu);
    }
    } // attach
    else 
      {
	if (n%10 ==0) {
	  printf("it %d \t",n);fflush(stdout);
	}
      }
    if (n%10 ==0) {
      current_noise_mean /= input->Size();
      current_noise_sd   /= input->Size();
      printf("noise : (%3.3f,%3.3f) \n",
	     current_noise_mean,
	     sqrt(current_noise_sd-current_noise_mean*current_noise_mean));
    }
    (*res1) = (*res2);

  FinPour // iterations


  delete res1;
  return res2;

} // Func_RudinMultiplicative3D()


