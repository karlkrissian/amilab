#ifndef _GAUSSIAN_H
#define _GAUSSIAN_H

#include <math.h>


// this class convolves an image with a gaussian


template <typename real>
class gaussian {


 public:


  template < class function >
    const void operator () ( function &I,
			     int xdim, int ydim, const real sigma,
			     int bc=1, int precision=5 ) {

    int i, j, k;

    const real   den    = 2*sigma*sigma;
    const int    size   = (int) (precision * sigma) + 1 ;
    const int    bdx    = xdim + size;
    const int    bdy    = ydim + size;

    if ( bc && size > xdim ) {
      printf("GaussianSmooth: sigma too large for this bc\n");
      throw 1;
    }

    real *B = new real[size];

    for(int i = 0; i < size; i++)

      B[i] = 1 / (sigma * sqrt(2.0 * 3.1415926)) * exp(-i * i / den);

    real norm = 0;

    for(int i = 0; i < size; i++)
      
      norm += B[i];

    norm *= 2; 

    norm -= B[0];
    
    for(int i = 0; i < size; i++) 
      
      B[i] /= norm; 
    
    real *R = new real[size + xdim + size];

    for ( k = 0; k < ydim; k ++ ) {

      for (i = size; i < bdx; i++) {

	R[i] = I[k * xdim + i - size];
      }

      switch ( bc )
	{
	case 0:   // Dirichlet boundary conditions

	  for( i = 0, j = bdx; i < size; i++,j++) R[i] = R[j] = 0; break;

	case 1:   // Reflecting boundary conditions

	  for(i = 0, j = bdx; i < size; i++, j++) {

	    R[i] = I[k * xdim + size-i];
	    R[j] = I[k * xdim + xdim-i-1];
	  }
	  break;

	case 2:   // Periodic boundary conditions

	  for(i=0,j=bdx;i<size;i++,j++) {

	    R[i] = I[k * xdim + xdim-size+i];
	    R[j] = I[k * xdim + i];
	  }
	  break;
	}

      for ( i=size; i<bdx; i++ ) {

	real sum = B[0] * R[i];

	for ( int j = 1; j < size; j ++ )
	  sum += B[j] * ( R[i-j] + R[i+j] );

	I[k * xdim + i - size] = sum;
      }
    }

    real *T = new real[size + ydim + size];

    for ( k = 0; k < xdim; k ++ ) {

      for ( i=size; i<bdy; i++ ) T[i] = I[(i - size) * xdim + k];

      switch ( bc )
	{
	case 0:   // Dirichlet boundary conditions

	  for ( i = 0, j = bdy; i < size; i++, j++) T[i] = T[j] = 0; break;

	case 1:   // Reflecting boundary conditions

	  for(i=0,j=bdy;i<size;i++,j++) {

	    T[i] = I[(size-i) * xdim + k];
	    T[j] = I[(ydim-i-1) * xdim + k];
	  }
	  break;

	case 2:   // Periodic boundary conditions

	  for(i=0,j=bdx;i<size;i++,j++) {

	    T[i] = I[(ydim-size+i) * xdim + k];
	    T[j] = I[i * xdim + k];
	  }
	  break;
	}

      int c;

      for ( i=size;i<bdy; i++ ) {

	real sum = B[0] * T[i];

	for ( j = 1; j < size; j ++ )
	  sum += B[j] * (T[i-j] + T[i+j]);

 	I[(i - size) * xdim + k] = sum;
      }
    }
    delete []B;
    delete []R;
    delete []T;
  }
};



#endif

