#ifndef _EUCLIDEAN_ERROR_H
#define _EUCLIDEAN_ERROR_H

#include <iostream>
#include <math.h>
 
//borde = 15
//min = -1
//max = 9999999


template <class real, class image>
real euclidean_error(const image &U1, const image &V1,
		    const image &U2, const image &V2, int nx, int ny,
		    int border, real min, real max,
		    const image &Ocl = image()) {

    real sum = 0;
    real N = 0;

    for(int x = 0; x < nx; x++)
      for(int y = 0; y < ny; y++) {

        if((x >= border && y >= border) &&
           (x < nx-border && y < ny -border) && 
           (fabs(U1[x + y * nx]) > min && fabs(U1[x + y * nx]) < max) &&
	        (Ocl[x + y * nx]>0.9) ) {

	        real U = U1[x + y * nx] - U2[x + y * nx];
	        real V = V1[x + y * nx] - V2[x + y * nx];

	        sum += sqrt(U * U + V * V);

	        N += 1;

        }

    }

    std::cout << "\t" << N << "\t\n";

    if (N > 0)
      return sum / N;
    else
      return 9999.0;

}

#endif
