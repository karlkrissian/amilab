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

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// 
//  Routines from numerical recipes in C
//

#define vector(b,e) new float[e-b+2];

#define free_vector(v) delete [] v;

#define ROTATE(a,i,j,k,l) g=a[i][j]; h=a[k][l]; a[i][j]=g-s*(h+g*tau); \
  a[k][l]=h+s*(g-h*tau);


int jacobi(float** a, int n, float d[], float** v, int *nrot)
//
//
// Computes all eigenvalues and eigenvectors of a real symmetric matrix
// a[1..n][1..n]. On output, elements of a above the diagonal are destroyed.
// d[1..n] returns the eigenvalues of a.
// v[1..n][1..n] is a matrix whose columns contain, on output, the normalized
// eigenvectors of a.
// nrot returns the number of Jacobi rotations that were required.
//

{
  int   j,iq,ip,i;
  float tresh,theta,tau,t,sm,s,h,c,*b,*z;
  float g;

  b=vector(1,n);
  z=vector(1,n);

  // Initialize to identity matrix
  for(ip=0;ip<n; ip++) {
    for(iq=0;iq<n;iq++) v[ip][iq]=0.0;
    v[ip][ip]=1.0;
  }

  // Initializa b and d to the diagonal of a.
  // This vector will accumulate terms of the form ta(p,q) as in eq. ()
  for (ip=0;ip<n; ip++) {
    b[ip]=d[ip]=a[ip][ip];
    z[ip]=0.0;
  }


  *nrot=0;
  for(i=1;i<=50;i++) {

    // Sum off-diagonal elements
    sm=0.0;
    for(ip=0;ip<n-1;ip++) {
      for(iq=ip+1;iq<n;iq++) {
        sm += fabs(a[ip][iq]);
      }
    }

    // The normal return, which relies on 
    // quadratic convergence to machine underflow.
    if (sm==0.0) {
      free_vector(z);
      free_vector(b);
      return 1;
    }

    
    if (i<4)
      // ... on the first 3 sweeps
      tresh=0.2*sm/(n*n);
    else
      // ... thereafter
      tresh=0.0;

    for(ip=0;ip<n-1;ip++) 
      {
	for(iq=ip+1;iq<n;iq++) 	
	  {
	    g=100.0*fabs(a[ip][iq]);
	    // After 4 sweeps, skip the rotation if the off-diagonal element is small.
	    if ((i>4)  && ((float) (fabs(d[ip])+g) == (float) fabs(d[ip]))
		&& ((float) (fabs(d[iq])+g) == (float) fabs(d[iq])))
	      a[ip][iq] = 0.0;
	    else 
	      if (fabs(a[ip][iq]) > tresh) {
		h=d[iq]-d[ip];
		if ((float)(fabs(h)+g) == (float) fabs(h))
		  // t=1/(2*theta)
		  t=(a[ip][iq])/h;
		else {
		  theta=0.5*h/(a[ip][iq]);
		  t=1.0/(fabs(theta)+sqrt(1.0+theta*theta));
		  if (theta < 0.0) t=-t;
		}
		c=1.0/sqrt(1.0+t*t);
		s=t*c;
		tau=s/(1.0+c);
		h=t*a[ip][iq];
		z[ip] -= h;
		z[iq] += h;
		d[ip] -= h;
		d[iq] += h;
		a[ip][iq] = 0.0;
		for(j=0;j<=ip-1;j++) {
		  // Case of rotations 1<=j<p
		  ROTATE(a,j,ip,j,iq)
		    }
		for(j=ip+1;j<=iq-1;j++) {
		  // Case of rotations p<j<q
		  ROTATE(a,ip,j,j,iq)
		    }
		for(j=iq+1;j<n;j++) {
		  // Case of rotations q<=j<n
		  ROTATE(a,ip,j,iq,j)
		    }
		for(j=0;j<n;j++) {
		  ROTATE(v,j,ip,j,iq)
		    }
		++(*nrot);
	      }
	  }  

      }
      for(ip=0;ip<n;ip++) {
	   b[ip] += z[ip];
	   d[ip] = b[ip];
	   z[ip] = 0.0;
      }

  }
  
  fprintf(stderr,"Too many iterations in routine Jacobi\n");

  free_vector(z);
  free_vector(b);
  return 0;
}


void eigsrt(float d[], float** v, int n)
//
// Given the eigenvalues d[0..n-1] and the eigenvectors
// v[0..n-1][0..n-1] as output from jacobi or tqli,
// this routine sorts the eigenvalues into descending order,
// and rearranges the columns of v correspondingly.
//
{
  int k,j,i;
  float p;

  for(i=0;i<n-1;i++) {
    p=d[k=i];
    for(j=i+1;j<n;j++)
      if (d[j] >=p) p=d[k=j];
    if (k!=i) {
      d[k] = d[i];
      d[i] = p;
      for(j=0;j<n;j++) {
	p=v[j][i];
	v[j][i] = v[j][k];
	v[j][k] = p;
      }
    }
  }

}


void eigsrt_abs(float d[], float** v, int n)
//
// Given the eigenvalues d[0..n-1] and the eigenvectors
// v[0..n-1][0..n-1] as output from jacobi or tqli,
// this routine sorts the eigenvalues into descending order of absolute values,
// and rearranges the columns of v correspondingly.
//
{
  int k,j,i;
  float p;

  for(i=0;i<n-1;i++) {
    p=fabs(d[k=i]);
    for(j=i+1;j<n;j++)
      if (fabs(d[j]) >=p) p=fabs(d[k=j]);
    if (k!=i) {
      p = d[k];
      d[k] = d[i];
      d[i] = p;
      for(j=0;j<n;j++) {
	p=v[j][i];
	v[j][i] = v[j][k];
	v[j][k] = p;
      }
    }
  }

}


void eigsrt_inc(float d[], float** v, int n)
//
// Given the eigenvalues d[0..n-1] and the eigenvectors
// v[0..n-1][0..n-1] as output from jacobi or tqli,
// this routine sorts the eigenvalues into descending order,
// and rearranges the columns of v correspondingly.
//
{
  int k,j,i;
  float p;

  for(i=0;i<n-1;i++) {
    p=d[k=i];
    for(j=i+1;j<n;j++)
      if (d[j] <=p) p=d[k=j];
    if (k!=i) {
      d[k] = d[i];
      d[i] = p;
      for(j=0;j<n;j++) {
	p=v[j][i];
	v[j][i] = v[j][k];
	v[j][k] = p;
      }
    }
  }

}
