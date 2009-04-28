#include <stdlib.h>
#include <stdio.h>
#include "ami_prototypes.h"

/**
 * AUXILIARY FUNCTION TO COMPUTE A FFT
 */
void fourn(float *data, long *nn, int ndim, int isign)
{
	int idim;
	long i1,i2,i3,i2rev,i3rev,ip1,ip2,ip3,ifp1,ifp2;
	long ibit,k1,k2,n,nprev,nrem,ntot;
	float tempi,tempr;
	double theta,wi,wpi,wpr,wr,wtemp;

	for (ntot=1,idim=1;idim<=ndim;idim++)
		ntot *= nn[idim-1];
	nprev=1;
	for (idim=ndim;idim>=1;idim--) {
		n=nn[idim-1];
		nrem=ntot/(n*nprev);
		ip1=nprev << 1;
		ip2=ip1*n;
		ip3=ip2*nrem;
		i2rev=1;
		for (i2=1;i2<=ip2;i2+=ip1) {
			if (i2 < i2rev) {
				for (i1=i2;i1<=i2+ip1-2;i1+=2) {
					for (i3=i1;i3<=ip3;i3+=ip2) {
						i3rev=i2rev+i3-i2;
						SWAP(data[i3-1],data[i3rev-1]);
						SWAP(data[i3],data[i3rev]);
					}
				}
			}
			ibit=ip2 >> 1;
			while (ibit >= ip1 && i2rev > ibit) {
				i2rev -= ibit;
				ibit >>= 1;
			}
			i2rev += ibit;
		}
		ifp1=ip1;
		while (ifp1 < ip2) {
			ifp2=ifp1 << 1;
			theta=isign*6.28318530717959/(ifp2/ip1);
			wtemp=sin(0.5*theta);
			wpr = -2.0*wtemp*wtemp;
			wpi=sin(theta);
			wr=1.0;
			wi=0.0;
			for (i3=1;i3<=ifp1;i3+=ip1) {
				for (i1=i3;i1<=i3+ip1-2;i1+=2) {
					for (i2=i1;i2<=ip3;i2+=ifp2) {
						k1=i2;
						k2=k1+ifp1;
						tempr=(float)wr*data[k2-1]-(float)wi*data[k2];
						tempi=(float)wr*data[k2]+(float)wi*data[k2-1];
						data[k2-1]=data[k1-1]-tempr;
						data[k2]=data[k1]-tempi;
						data[k1-1] += tempr;
						data[k1] += tempi;
					}
				}
				wr=(wtemp=wr)*wpr-wi*wpi+wr;
				wi=wi*wpr+wtemp*wpi+wi;
			}
			ifp1=ifp2;
		}
		nprev *= n;
	}
}


/**
 * FUNCTION TO COMPUTE A 3D FFT
 *
 * \param data  input and output dat 
 * \param speq  output 2D matrix 
 * \param nn1,nn2,nn3  dimensions of the 3D matrix (it has to be power of 2) 
 * \param isign   isign==1 means direct FFT isign=-1 means inverse FFT 
 */
void rlft3(
  float ***data, /* input and output dat */
  float **speq, /* output 2D matrix */
  long nn1, long nn2, long nn3, /* dimensions of the 3D matrix (it has to be power of 2) */
  int isign) /* isign==1 means direct FFT isign=-1 means inverse FFT */
{
	long i1,i2,i3,j1,j2,j3,nn[4],ii3;
	double theta,wi,wpi,wpr,wr,wtemp;
	float c1,c2,h1r,h1i,h2r,h2i;

    /* WE CHECK IN THE DIMENSION ARE POWER OF 2 */
	i1=nn1;
	while(i1!=1){
	 if(i1%2==0) i1=i1/2;
	 else{ printf("dimensions of signal are not power of 2\n"); exit(-1);}
	}
	i1=nn2;
	while(i1!=1){
	 if(i1%2==0) i1=i1/2;
	 else{ printf("dimensions of signal are not power of 2\n"); exit(-1);}
	}
    i1=nn3;
	while(i1!=1){
	 if(i1%2==0) i1=i1/2;
	 else{ printf("dimensions of signal are not power of 2\n"); exit(-1);}
	}

    /* WE CHECK THE CONTIGUITY OF DATA ARRAY */
	if (1+&data[nn1-1][nn2-1][nn3-1]-&data[0][0][0] != nn1*nn2*nn3)
		printf("rlft3: problem with dimensions or contiguity of data array\n");
	c1=0.5;
	c2 = -0.5*isign;
	theta=isign*(6.28318530717959/nn3);
	wtemp=sin(0.5*theta);
	wpr = -2.0*wtemp*wtemp;
	wpi=sin(theta);
	nn[0]=nn1;
	nn[1]=nn2;
	nn[2]=nn3 >> 1;
	if (isign == 1) {
		fourn(&data[0][0][0],nn,3,isign);
		for (i1=1;i1<=nn1;i1++)
			for (i2=1,j2=0;i2<=nn2;i2++) {
				speq[i1-1][++j2-1]=data[i1-1][i2-1][0];
				speq[i1-1][++j2-1]=data[i1-1][i2-1][1];
			}
	}
	for (i1=1;i1<=nn1;i1++) {
		j1=(i1 != 1 ? nn1-i1+2 : 1);
		wr=1.0;
		wi=0.0;
		for (ii3=1,i3=1;i3<=(nn3>>2)+1;i3++,ii3+=2) {
			for (i2=1;i2<=nn2;i2++) {
				if (i3 == 1) {
					j2=(i2 != 1 ? ((nn2-i2)<<1)+3 : 1);
					h1r=c1*(data[i1-1][i2-1][0]+speq[j1-1][j2-1]);
					h1i=c1*(data[i1-1][i2-1][1]-speq[j1-1][j2]);
					h2i=c2*(data[i1-1][i2-1][0]-speq[j1-1][j2-1]);
					h2r= -c2*(data[i1-1][i2-1][1]+speq[j1-1][j2]);
					data[i1-1][i2-1][0]=h1r+h2r;
					data[i1-1][i2-1][1]=h1i+h2i;
					speq[j1-1][j2-1]=h1r-h2r;
					speq[j1-1][j2]=h2i-h1i;
				} else {
					j2=(i2 != 1 ? nn2-i2+2 : 1);
					j3=nn3+3-(i3<<1);
					h1r=c1*(data[i1-1][i2-1][ii3-1]+data[j1-1][j2-1][j3-1]);
					h1i=c1*(data[i1-1][i2-1][ii3]-data[j1-1][j2-1][j3]);
					h2i=c2*(data[i1-1][i2-1][ii3-1]-data[j1-1][j2-1][j3-1]);
					h2r= -c2*(data[i1-1][i2-1][ii3]+data[j1-1][j2-1][j3]);
					data[i1-1][i2-1][ii3-1]=h1r+wr*h2r-wi*h2i;
					data[i1-1][i2-1][ii3]=h1i+wr*h2i+wi*h2r;
					data[j1-1][j2-1][j3-1]=h1r-wr*h2r+wi*h2i;
					data[j1-1][j2-1][j3]= -h1i+wr*h2i+wi*h2r;
				}
			}
			wr=(wtemp=wr)*wpr-wi*wpi+wr;
			wi=wi*wpr+wtemp*wpi+wi;
		}
	}
	if (isign == -1)
		fourn(&data[0][0][0],nn,3,isign);
}


/**
 * FUNCTION TO COMPUTE A 3D CONVOLUTION USING FFT THE CONVOLVED SIGNAL IS RETURNED IN data1 POINTER 
 *
 * \param data1  input first image and output image convolution 
 * \param data2  input second image 
 * \param nn1,nn2,nn3  image dimension (it has to be power of 2) 
 */
void ami_fft_convolucion(
  float ***data1, /* input first image and output image convolution */
  float ***data2, /* input second image */
  long nn1, long nn2, long nn3) /* image dimension (it has to be power of 2) */
{
	int j;
	//int k,l;
	float fac,r,i,*sp1,*sp2;
	long size_2=nn1*nn2*nn3/2;
	float **speq1,**speq2;

	ami_malloc2d(speq1,float,nn1,nn2<<1);
	ami_malloc2d(speq2,float,nn1,nn2<<1);

	/* WE COMPUTE FFT TRANSFORM */
	rlft3(data1,speq1,nn1,nn2,nn3,1);
	rlft3(data2,speq2,nn1,nn2,nn3,1);

	/* FACTOR NEEDED TO GET NORMALIZED INVERSE */
	fac=2.0/(nn1*nn2*nn3);

	/* WE COMPUTE THE PRODUCT OF FFT TRANSFORM */
	sp1=&data1[0][0][0];
	sp2=&data2[0][0][0];
	for(j=1;j<=size_2;j++){
	  r=sp1[0]*sp2[0]-sp1[1]*sp2[1];
	  i=sp1[0]*sp2[1]+sp1[1]*sp2[0];
	  sp1[0]=fac*r;
	  sp1[1]=fac*i;
	  sp1+=2;
	  sp2+=2;
	}
	sp1=&speq1[0][0];
	sp2=&speq2[0][0];
	for(j=1;j<=nn1*nn2;j++){
	  r=sp1[0]*sp2[0]-sp1[1]*sp2[1];
	  i=sp1[0]*sp2[1]+sp1[1]*sp2[0];
	  sp1[0]=fac*r;
	  sp1[1]=fac*i;
	  sp1+=2;
	  sp2+=2;
	}
    sp1=&data1[0][0][0];
	/* WE COMPUTE THE INVERSE FFT */
	rlft3(data1,speq1,nn1,nn2,nn3,-1);

	ami_free2d(speq1);
	ami_free2d(speq2);

	/* WE PRINT THE OUTPUT */
	/*for(j=1;j<nn1;j++){
	  for(k=1=;k<nn2;k++){
		for(l=1=;l<=nn3;l++){
		  printf("%1.2f ",data1[j-1][k-1][l-1]);
	    }
		printf("\n");
      }
	  printf("\n");
    }*/

}


/**
 * FUNCTION TO COMPUTE A 3D CORRELATION USING FFT THE CONVOLVED SIGNAL IS RETURNED IN data1 POINTER 
 *
 * \param data1  input first image and output image correlation 
 * \param data2  input second image 
 * \param nn1,nn2,nn3  image dimension (it has to be power of 2) 
 */
void ami_fft_correlation(
float ***data1, /* input first image and output image correlation */
float ***data2, /* input second image */
long nn1, long nn2, long nn3) /* image dimension (it has to be power of 2) */
{
	int j;
	//int k,l;
	float fac,r,i,*sp1,*sp2;
	long size_2=nn1*nn2*nn3/2;
	float **speq1,**speq2;

	ami_malloc2d(speq1,float,nn1,nn2<<1);
	ami_malloc2d(speq2,float,nn1,nn2<<1);

	/* WE COMPUTE FFT TRANSFORM */
	rlft3(data1,speq1,nn1,nn2,nn3,1);
	rlft3(data2,speq2,nn1,nn2,nn3,1);

	/* FACTOR NEEDED TO GET NORMALIZED INVERSE */
	fac=2.0/(nn1*nn2*nn3);

	/* WE COMPUTE THE PRODUCT OF FFT TRANSFORM */
	sp1=&data1[0][0][0];
	sp2=&data2[0][0][0];
	for(j=1;j<=size_2;j++){
	  r=sp1[0]*sp2[0]+sp1[1]*sp2[1];
	  i=sp1[0]*sp2[1]-sp1[1]*sp2[0];
	  sp1[0]=fac*r;
	  sp1[1]=fac*i;
	  sp1+=2;
	  sp2+=2;
	}
	sp1=&speq1[0][0];
	sp2=&speq2[0][0];
	for(j=1;j<=nn1*nn2;j++){
	  r=sp1[0]*sp2[0]+sp1[1]*sp2[1];
	  i=sp1[0]*sp2[1]-sp1[1]*sp2[0];
	  sp1[0]=fac*r;
	  sp1[1]=fac*i;
	  sp1+=2;
	  sp2+=2;
	}
	/* WE COMPUTE THE INVERSE FFT */
	rlft3(data1,speq1,nn1,nn2,nn3,-1);

	ami_free2d(speq1);
	ami_free2d(speq2);


}





/**
 * 3D FFT COMPUTATION OF A GAUSSIAN FUNCTION OF STANDARD DEVIATIONS st,sx,sy 
 * THE OUTPUT ARE IN data1 AND speq1 POINTER. IN THE CASE OF THE DIMENSION
 * nn1 BE EQUAL TO 1 WE RETURN A 2D FFT                                      
 */
void ami_fft_gauss(float ***data1, float **speq1, long nn1, long nn2, long nn3, float st, float sx, float sy)
{
  long j,k,l;
  float ssx,ssy,sst;
  double C;
  if(nn1>1){
	C=(1./(sx*sy*st))*(1./(2.*M_PI*sqrt(2.*M_PI)));
    for(j=1;j<=nn1;j++){
      for(k=1;k<=nn2;k++){
	    for(l=1;l<=nn3;l++){
			sst=nn1/2.+1.-ami_abs(j-nn1/2.-1.);
			ssx=nn2/2.+1.-ami_abs(k-nn2/2.-1.);
			ssy=nn3/2.+1.-ami_abs(l-nn3/2.-1.);
		    data1[j-1][k-1][l-1]=C*exp( -((ssx-1.)*(ssx-1)/(2.*sx*sx)+(ssy-1)*(ssy-1)/(2.*sy*sy)+(sst-1)*(sst-1)/(2.*st*st)) );
		  //data2[j-1][k-1][l-1]=1;
	    }
      }
    }
  }

  else{
	C=(1./(sx*sy))*(1./(2.*M_PI));
    for(j=1;j<=nn1;j++){
      for(k=1;k<=nn2;k++){
	    for(l=1;l<=nn3;l++){
			ssx=nn2/2.+1.-ami_abs(k-nn2/2.-1.);
			ssy=nn3/2.+1.-ami_abs(l-nn3/2.-1.);
		    data1[j-1][k-1][l-1]=C*exp( -((ssx-1.)*(ssx-1)/(2.*sx*sx)+(ssy-1)*(ssy-1)/(2.*sy*sy) ) );
		  //data2[j-1][k-1][l-1]=1;
	    }
      }
    }
  }
  /* WE PRINT THE INPUT GAUSSIAN FUNCTION */
 /* printf("\n\n\n");
  for(j=1;j<=nn1;j++){
	  for(k=1;k<=nn2;k++){
		for(l=1;l<=nn3;l++){
		  printf("%1.4f ",data1[j-1][k-1][l-1]);
	    }
		printf("\n");
      }
	  printf("\n");
  }*/
  /* WE TEST THAT THE INTEGRAL IS EQUAL TO 1 */
  {
	float average, *paso;
    paso=&data1[0][0][0];
    ami_media_vector(paso,average,(nn1*nn2*nn3));
	average*=(nn1*nn2*nn3);
	printf("SUM=%f\n\n",average);
    /* WE CORRECT THE IMAGE IN ORDER TO THE INTEGRAL BE 1 */
	k=nn1*nn2*nn3;
	for(j=0;j<k;j++) paso[j]/=average;
  }

  rlft3(data1,speq1,nn1,nn2,nn3,1);

}


/**
 * FUNCTION TO COMPUTE A 3D CONVOLUTION WITH A GAUSSIAN FUNCTION USING FFT THE CONVOLVED SIGNAL IS
 * RETURNED IN data1 POINTER. THE FFT OF THE GAUSSIAN FUNCTION HAS BEEN PREVIOUSLY COMPUTED AND STORED
 * IN data2 AND speq2 POINTER                                                                       
 */
void ami_fft_gauss_convolucion(float ***data1, float ***data2, float **speq2, long nn1, long nn2, long nn3)
{
	int j;
	//int k,l;
	float fac,r,i,*sp1,*sp2;
	long size_2=nn1*nn2*nn3/2;
	float **speq1;

	ami_malloc2d(speq1,float,nn1,nn2<<1);

	/* WE COMPUTE FFT TRANSFORM */
	rlft3(data1,speq1,nn1,nn2,nn3,1);

	/* FACTOR NEEDED TO GET NORMALIZED INVERSE */
	fac=2.0/(nn1*nn2*nn3);

	/* WE COMPUTE THE PRODUCT OF FFT TRANSFORM */
	sp1=&data1[0][0][0];
	sp2=&data2[0][0][0];
	for(j=1;j<=size_2;j++){
	  r=sp1[0]*sp2[0]-sp1[1]*sp2[1];
	  i=sp1[0]*sp2[1]+sp1[1]*sp2[0];
	  sp1[0]=fac*r;
	  sp1[1]=fac*i;
	  sp1+=2;
	  sp2+=2;
	}
	sp1=&speq1[0][0];
	sp2=&speq2[0][0];
	for(j=1;j<=nn1*nn2;j++){
	  r=sp1[0]*sp2[0]-sp1[1]*sp2[1];
	  i=sp1[0]*sp2[1]+sp1[1]*sp2[0];
	  sp1[0]=fac*r;
	  sp1[1]=fac*i;
	  sp1+=2;
	  sp2+=2;
	}
    sp1=&data1[0][0][0];
	/* WE COMPUTE THE INVERSE FFT */
	rlft3(data1,speq1,nn1,nn2,nn3,-1);

	ami_free2d(speq1);

}
