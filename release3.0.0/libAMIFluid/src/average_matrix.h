#ifndef _AVERAGEMATRIX_
#define _AVERAGEMATRIX_

#include "namespace.h"
/******************************************************************************/
/***	THIS FILE CONTAINS THE CLASS     TO COMPUTE THE AVERAGE OF A MATRIX   ***/
/***	THE AVERAGE IS CALCULATED BY ROWS AND THEN BY COLUMNS		             ***/
/******************************************************************************/

BEGIN_AMI_MATH


template <typename real>
class average_matrix{

    /******************************************************************************/
    /***	AVERAGE BY ROWS						        ***/
    /******************************************************************************/
    template <typename image>
    void average_row(const image &input, image &output, int nx , int ny, int radius)
    {
      int i, j;
      real *b;

      if(radius>0){
         /* alloc storage */
	      b = new real[ny];

	      for( i = 0; i < nx; i++ ){
	         /* border of matrix */
	         b[0] = input[i + nx];

            for( j = 2; j <= radius; j++ )

               b[0] += input[i + nx * j];

            b[0] = 2. * b[0] + input[i];

            /* first part untill size of radius */
            for( j = 1; j <= radius; j++ ) {

                    int posy1 = radius + 1 - j;
                    int posy2 = radius + j;

                    //boundary tests
                    if(posy1 < 0) posy1 = 0;
                    else if(posy1 >= ny) posy1 = ny - 1;
                    if(posy2 < 0) posy2 = 0;
                    else if(posy2 >= ny) posy2 = ny - 1;

	                 b[j] = b[j-1] - input[i + nx * posy1] + input[i + nx * posy2];
            }

            /* main part */
            for( j = radius+1; j < ny-radius; j++) {

                    int posy1 = j - radius - 1;
                    int posy2 = radius + j;

                    //boundary tests
                    if(posy1 < 0) posy1 = 0;
                    else if(posy1 >= ny) posy1 = ny - 1;
                    if(posy2 < 0) posy2 = 0;
                    else if(posy2 >= ny) posy2 = ny - 1;

	               b[j] = b[j-1] - input[i + nx * posy1] + input[i + nx * posy2];
            }

            /* last part before end of row */
	         for( j = ny-radius; j < ny; j++ ) {

                    int posy1 = j - radius - 1;
                    int posy2 = 2*ny-j-radius-2;

                    //boundary tests
                    if(posy1 < 0) posy1 = 0;
                    else if(posy1 >= ny) posy1 = ny - 1;
                    if(posy2 < 0) posy2 = 0;
                    else if(posy2 >= ny) posy2 = ny - 1;


  	                 b[j] = b[j-1] - input[i + nx * posy1] + input[i + nx * posy2];
            }

            /* copy the result in output */
	         for( j = 0; j < ny; j++ )

	               output[i + nx * j] = b[j];

         }

	      /* disalloc storage */
	      delete []b;
      }
      else

         for( i = 0; i < nx; i++ )

	         for( j = 0; j < ny; j++ )

	            output[i + nx * j] = input[i + nx * j];
      
      
    }

    /******************************************************************************/
    /***	AVERAGE BY COLUMNS						                                   ***/
    /******************************************************************************/
    template <typename image>
    void average_column(const image &input, image &output, int nx, int ny, int radius)
    {
      int i, j;
      real *b;

      if(radius>0){
	      /* alloc storage */

         b = new real[nx];

	      for( j = 0; j < ny; j++ ){
	         /* border of matrix */
            b[0] = input[1 + nx * j];

            for( i = 2; i <= radius; i++ )

	            b[0] += input[i + nx * j];

            b[0] = 2. * b[0] + input[nx * j];

	         /* first part untill size of radius */
	         for( i = 1; i <= radius; i++ ) {

               int posx1 = radius+1-i;
               int posx2 = i+radius;

               if(posx1 < 0) posx1 = 0;
               else if(posx1 >= nx) posx1 = nx - 1;
               if(posx2 < 0) posx2 = 0;
               else if(posx2 >= nx) posx2 = nx - 1;

               b[i] = b[i-1] - input[posx1 + nx * j] + input[posx2 + nx * j];
            }

	         /* main part */
	         for( i = radius+1; i < nx-radius; i++ ) {

               int posx1 = i-radius-1;
               int posx2 = i+radius;

               if(posx1 < 0) posx1 = 0;
               else if(posx1 >= nx) posx1 = nx - 1;
               if(posx2 < 0) posx2 = 0;
               else if(posx2 >= nx) posx2 = nx - 1;

               b[i] = b[i-1] - input[posx1 + nx * j] + input[posx2 + nx * j];
            }

            /* last part before end of row */
	         for( i = nx-radius; i < nx; i++ ) {

               int posx1 = i-radius-1;
               int posx2 = 2*nx-i-radius-2;

               if(posx1 < 0) posx1 = 0;
               else if(posx1 >= nx) posx1 = nx - 1;
               if(posx2 < 0) posx2 = 0;
               else if(posx2 >= nx) posx2 = nx - 1;

	            b[i] = b[i-1] - input[posx1 + nx * j] + input[posx2 + nx * j];
            }

            /* copy the result in output */
	         for( i = 0; i < nx; i++ ){

	            output[i + nx * j] = b[i];
	            /*printegerf("%f, ", b[i]);*/
            }
         }

	      /* disalloc storage */
	      delete [] b;
      }
      else

       for( i = 0; i < nx; i++ )

	       for( j = 0; j < ny; j++ )

	          output[i + nx * j] = input[i + nx * j];
    }


  public:

    template <typename image>
    average_matrix(const image &input, image &output, int nx, int ny, int radius)
    {
      int i, j;
      real norm;

      /* compute the average by rows */
      average_row( input, output, nx, ny, radius );

      /* then compute the average by columns */
      average_column(output, output, nx, ny, radius );

      /* normalize */
      norm = 1. / ((real)(2*radius+1) * (2*radius+1));


      for( i = 0; i < nx; i++)

	      for( j = 0; j < ny; j++)

	         output[i + nx * j] *= norm;
    }


};

END_AMI_MATH


#endif
