#ifndef _ANGULAR_ERROR_H
#define _ANGULAR_ERROR_H

#include <iostream>
#include <math.h>


//borde = 15
//min = -1
//max = 9999999

template <class real, class image>
real angular_error(const image &U1, const image &V1,
		  const image &U2, const image &V2, int nx, int ny,
		  int border, real min, real max,
		  const image &Ocl){

    real sum = 0.0;
    real N = 0.0;

    for(int x = 0; x < nx; x++)
      for(int y = 0; y < ny; y++) {

        if((x >= border && y >= border) &&
           (x < nx-border && y < ny -border) &&
           (fabs(U1[x + y * nx]) > min && fabs(U1[x + y * nx]) < max) &&
	        (Ocl[x + y * nx]>0.9) ) {

	        real num  = U1[x + y * nx] * U2[x + y * nx] +
                       V1[x + y * nx] * V2[x + y * nx] + 1.0;

	        real den1 = U1[x + y * nx] * U1[x + y * nx] +
                       V1[x + y * nx] * V1[x + y * nx] + 1.0;

	        real den2 = U2[x + y * nx] * U2[x + y * nx] +
                       V2[x + y * nx] * V2[x + y * nx] + 1.0;

	        real den  = sqrt((double)den1 * den2);

           if(num < den && den > 0.00001) {

              sum += acos((double)num/den);
	           N += 1.0;
           }

        }

    }

    std::cout << "\t" << N << "\t\n";

    if (N > 0.0001)
      return (sum * 180.0) / (N * 3.1415926);
    else
      return 9999.0;
}

#endif
