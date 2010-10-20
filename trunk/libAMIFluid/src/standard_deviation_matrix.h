#ifndef _STANDARD_DEVIATION_
#define _STANDARD_DEVIATION_

#include <math.h>
#include "average_matrix.h"


BEGIN_AMI_MATH


/**************************************************************************/
/***** THIS CLASS    COMPUTES THE STANDARD DEVIATION OF A MATRIX      *****/
/***** BY AN OPTIMAL METHOD	 				                            *****/
/***** I:	The matriz	 				                                  *****/
/***** average: A matrix containing the average in each position      *****/
/***** nx, ny:	Image size					                               *****/
/***** output:	Output matrix containig the standard deviation	       *****/
/*****								                                        *****/
/***** function--> sigma=sqrt(avg(I*I)-(avg(I)*avg(I)))		          *****/
/**************************************************************************/

template <typename real>
class standard_deviation_matrix {

  public:

    template <typename image>
    standard_deviation_matrix(const image &I, const image &average,
			    image &output, int nx, int ny, int radius) {

      int i, j;
      int size = nx * ny;

      real *I_square = new real[size];
      real *average_square = new real[size];

      /* compute the square of the matrix */
      for( i = 0; i < size; i++ )

	         I_square[i] = I[i] * I[i];

      /* compute the average on the I square */
      NM_AMI_MATH::average_matrix<real>(I_square, average_square, nx, ny, radius);

      /* compute the standard deviation all over the matrix */
      for( i = 0; i < size; i++ ) {

         real avg = average_square[i] - average[i] * average[i];

         if(avg < 0) avg = 0;

         output[i] = (real) sqrt(avg);
      }

      delete []I_square;
      delete []average_square;
    }
};

END_AMI_MATH

#endif
