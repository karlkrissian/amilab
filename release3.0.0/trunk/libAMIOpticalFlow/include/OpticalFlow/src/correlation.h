#ifndef _CORRELATION_H
#define _CORRELATION_H

#include "namespace.h"

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <algorithm>

#include "interpolation2D.h"
#include "average_matrix.h"
#include "standard_deviation_matrix.h"

#ifdef ABS
#undef ABS
#endif
#define ABS(x) (((x)>0.)?(x):-(x))


#define REALCORRELATION   0
#define NORMALCORRELATION 1

BEGIN_AMI_UTIL


template <class real>
class correlation{

    typedef struct flowf
    {
      real x;
      real y;
    }flow;


    // THIS PART IS FOR THE INTERPOLATED CORRELATION IN WHERE WE ESTIMATE
    // THE OPTIC FLOW IN REAL PRECISION
    // THE RESULT IS BETTER THAN IN THE INTEGER CASE, BUT THIS IS VERY SLOW

    flow interpolation2D(int basex, int basey, int px, int py,
			 real **values) const
    {
      real Co[9], sol[2];
      flow result;
      int i;

      /* values of the polinomyum */
      Co[0]=values[px+1+basex][py-1+basey];
      Co[1]=values[px+1+basex][py+basey];
      Co[2]=values[px+1+basex][py+1+basey];
      Co[3]=values[px+basex][py-1+basey];
      Co[4]=values[px+basex][py+basey];
      Co[5]=values[px+basex][py+1+basey];
      Co[6]=values[px-1+basex][py-1+basey];
      Co[7]=values[px-1+basex][py+basey];
      Co[8]=values[px-1+basex][py+1+basey];

      /* apply the newton method to obtain the maximum */
      i=Newton(Co,sol);

      if(i>-1){
         /* return the result */
         result.x=(float) -sol[0]+px;
	      result.y=(float) sol[1]+py;
      }
      else{
	      result.x=-0.00001;
	      result.y=-0.00001;
      }
      return result;
    }


    template <typename image>
    real correlate(const image &I1, const image &I2, const real *average1,
         const real *average2, const real *deviation1, const real *deviation2,
         int nx, int ny, int  xo, int yo, int radius, int taux, int tauy)    {

      real correlation, K;
      int i, j, k, l, k1, l1;
      int x1 = xo + taux;
      int y1 = yo + tauy;

      if( x1 >= nx )     x1 = nx - 1;
      else if ( x1 < 0 ) x1 = 0;

      if( y1 >= ny )    y1 = ny - 1;
      else if ( y1 < 0) y1 = 0;


      // we start computing the correlation
      correlation = 0.0;
      for( i = xo - radius; i <= xo + radius; i++ )

	      for( j = yo - radius; j <= yo + radius; j++ ){

	         k  = i;
	         k1 = k + taux;
	         l  = j;
	         l1 = l + tauy;

	         // boundary tests
	         if( k < 0)          k = 0;
	         else if( k >= nx )  k = nx - 1;

	         if( k1 < 0)         k1 = 0;
	         else if( k1 >= nx ) k1 = nx -1;

	         if( l < 0)          l = 0;
	         else if( l >= ny )  l = ny - 1;

	         if( l1 < 0 )        l1 = 0;
	         else if( l1 >= ny ) l1 = ny -1;

	         // iterative correlation
	         //correlation += (I1(k,l) - average1(xo,yo)) * (I2(k1,l1) - average2(x1,y1));
	         correlation += (I1[k + nx * l] * I2[k1 + nx * l1]);
         }


      real area = (real)(2*radius+1) * (2*radius+1);

      K = area * deviation1[xo + nx * yo] * deviation2[x1 + nx * y1];

      correlation -= area * ( average1[xo + nx * yo] * average2[x1 + nx * y1]);


      if( ABS(K) > 0.000001 ) correlation = 1 / K * correlation;
      else correlation = 0.0;

      return correlation;
    }


    template <typename image>
    flow max_correlation(const image &I1, const image &I2,
			 const image &average1,   const image &average2,
			 const image &deviation1, const image &deviation2,
          int nx, int ny, int xo, int yo, int radius, int  d0, int df) {

      real  **correlations;
      real  correlation, cmaximo = .51;
      int   taux, tauy, tmaximox = 0, tmaximoy = 0, i;
      flow  opticflow;
      int   tbasex=-d0, tbasey=-d0;

      correlations = (real **) new real[-d0+df+1];

      for( i = 0; i < -d0+df+1; i++)

	   correlations[i] =(real *) new real[-d0+df+1];

      /* we start computing the max correlation */
      opticflow.x = opticflow.y = 0.0;

      for(taux = d0; taux <= df; taux++){

	      for(tauy = d0; tauy <= df; tauy++){

	      /* compute the correlation for "taux,tauy" */
	      correlation = correlate(I1, I2, average1, average2,
				  deviation1, deviation2, nx, ny, xo, yo, radius,
				  taux, tauy);

         /* test for the maximum correlation */
	      if( correlation >= cmaximo ){

             if( correlation == cmaximo &&
		           (tmaximox * tmaximox + tmaximoy * tmaximoy <
		           taux*taux + tauy*tauy) ){

	              cmaximo=correlation;
	              tmaximox=taux;
	              tmaximoy=tauy;
             }
	          else if (correlation>cmaximo){

	              cmaximo=correlation;
	              tmaximox=taux;
	              tmaximoy=tauy;

             }

         }
	      /* store the results */
	      correlations[taux+tbasex][tauy+tbasey] = correlation;

      }
      }

      /* adjust of vector positions */
      if(tmaximox == df)       tmaximox--;
      else if(tmaximox == d0) tmaximox++;

      if(tmaximoy == df)       tmaximoy--;
      else if(tmaximoy == d0) tmaximoy++;

      /* calculation of opticflow */
      opticflow = interpolation2D(tbasex, tbasey, tmaximox, tmaximoy, correlations);

      for ( i = 0; i < -d0+df+1; i++ )

	       delete [] correlations[i];

      delete [] correlations;

      /* return the displacement associated with the maximum correlation */
      return opticflow;

    }



    template <typename image, class out>
    void real_correlation (const image &I1, const image &I2, image &U, image &V,
                           int nx, int ny, int radius, int d0, int df, out &print) {

      int  xo, yo;
      const int size = nx * ny;

      flow flw;

      real *average1 = new real[size];
      real *average2 = new real[size];
      real *deviation1 = new real[size];
      real *deviation2 = new real[size];

      // compute averages and standard deviations
      // NOTA: utilizamos como radio el tamaño de la ventana en X
      NM_AMI_MATH::average_matrix<real>(I1, average1, nx, ny, radius);
      NM_AMI_MATH::average_matrix<real>(I2, average2, nx, ny, radius);
      NM_AMI_MATH::standard_deviation_matrix<real>(I1, average1, deviation1, nx, ny, radius);
      NM_AMI_MATH::standard_deviation_matrix<real>(I2, average2, deviation2, nx, ny, radius);

      // we start computing the optic flow correlation
      print << "Starting Correlation " <<  nx << "," <<  ny << "\n";

      for( xo = 0; xo < nx; xo++ ){

	      for( yo = 0; yo < ny; yo++ ){

            // iterative correlation
	         flw = max_correlation(I1, I2, average1, average2, deviation1, deviation2,
                                  nx, ny, xo, yo, radius, d0, df);

            U[xo + nx * yo] = flw.x;
	         V[xo + nx * yo] = flw.y;

         }
	      print << "...row " << xo;
      }

      delete []average1;
      delete []average2;
      delete []deviation1;
      delete []deviation2;

    }





    // THIS PART IS FOR THE NORMAL CORRELATION IN WHERE WE ESTIMATE
    // THE OPTIC FLOW IN INTEGER PRECISION
    // THE RESULT IS WORSE THAN IN THE REAL CASE, BUT THIS IS VERY FAST

    template <typename image>
    void compute_tau_matrix(const image &I1, const image &I2, const image &average1,
                            const image &average2, const image &deviation1,
                            const image &deviation2, image &tau_average,
                            int nx, int ny, const int taux,  const int tauy,
                            const int radius) {

      const int size = nx * ny;

      real *KL = new real[size];

      for(int i = 0; i < nx; i++)

         for(int j = 0; j < ny; j++) {

            int posx = i + taux;
            int posy = j + tauy;

            //test for the boundaries
            if(posx >= nx) posx = nx - 1;
            else if(posx < 0) posx = 0;

            if(posy >= ny) posy = ny - 1;
            else if(posy < 0) posy = 0;

            KL[i + nx * j] = ( I1[i + nx * j] * I2[posx + nx * posy] );
        }

      NM_AMI_MATH::average_matrix<real>(KL, tau_average, nx, ny, radius);

      for(int i = 0; i < nx; i++)

         for(int j = 0; j < ny; j++) {

            int posx = i + taux;
            int posy = j + tauy;

            //test for the boundaries
            if(posx >= nx) posx = nx - 1;
            else if(posx < 0) posx = 0;

            if(posy >= ny) posy = ny - 1;
            else if(posy < 0) posy = 0;

            const real K = deviation1[i + nx * j] * deviation2[posx + nx * posy];

	         if( ABS(K) > 0.0001 )

	             tau_average[i + nx * j] = (tau_average[i + nx * j] -
                                           average1[i + nx * j] * average2[posx + nx * posy]) / K;

            else

               tau_average[i + nx * j] = 0.0;

      }

      delete []KL;
    }



    template <typename image, class out>
    void integer_correlation ( const image &I1, const image &I2, image &u, image &v,
		      	                int nx, int ny, int radius, int d0x, int dfx,
                               int d0y, int dfy, out &print)  {

      const int size = nx * ny;

      real *average1 = new real[size];
      real *average2 = new real[size];
      real *deviation1 = new real[size];
      real *deviation2 = new real[size];
      real *correlation = new real[size];
      real *tau_average = new real[size];

      // compute averages and standard deviations
      // NOTA: utilizamos como radio el tamaño de la ventana en X
      NM_AMI_MATH::average_matrix<real>(I1, average1, nx, ny, radius);
      NM_AMI_MATH::average_matrix<real>(I2, average2, nx, ny, radius);
      NM_AMI_MATH::standard_deviation_matrix<real>(I1, average1, deviation1, nx, ny, radius);
      NM_AMI_MATH::standard_deviation_matrix<real>(I2, average2, deviation2, nx, ny, radius);

      std::fill(&u[0], &u[size], real());
      std::fill(&v[0], &v[size], real());
      std::fill(&correlation[0], &correlation[size], real(0.6));

      // we start computing the optic flow correlation
      print << "Starting Correlation " <<  nx << "," <<  ny << "\n";

      d0x--; dfx++;
      d0y--; dfy++;

     for (int tx = d0x; tx <= dfx; tx++) {

	     for (int ty = d0y; ty <= dfy; ty++){

	        compute_tau_matrix(I1, I2, average1, average2, deviation1, deviation2,
                             tau_average, nx, ny, tx, ty, radius);

           for(int i = 0; i < size; i++)

                 if (tau_average[i] >=  correlation[i]){

                   correlation[i] = tau_average[i];

                   if ((tx > d0x) && (tx < dfx) && (ty > d0y) && (ty < dfy)){

                      u[i] = (real) tx;
                      v[i] = (real) ty;
                   }
                 }
        }
        print << "tau: from " << tx << " to " << dfx;

      }
      delete []average1;
      delete []average2;
      delete []deviation1;
      delete []deviation2;
      delete []correlation;
      delete []tau_average;

    }

  public:


    template <typename image, class out>
    void operator ()(const image &I1, const image &I2, image &u, image &v,
                     int nx, int ny, int radius, int d0x, int dfx,
                     int d0y, int dfy, int type = 1, out &print = std::cout)
    {

      // type = 1 is the normal (integer) fast correlation
      // otherwise is interpolated real correlation

      if( type == 1)

	      integer_correlation(I1, I2, u, v, nx, ny, radius, d0x, dfx, d0y, dfy, print);

      else

	      real_correlation(I1, I2, u, v, nx, ny, radius, d0x, dfx, print);

    }



    template <typename image, class out>
    void operator ()(const image &I1, const image &I2, image &u, image &v,
                     int nx, int ny, int radius, int d0, int df, int type = 1,
                     out &print = std::cout)
    {

      operator() (I1, I2, u, v, nx, ny, radius, d0, df, d0, df, type, print);

    }



    template <typename image>
    void horizontal ( const image &I1, const image &I2, image &L,
                      int nx, int ny, int radius, int d0, int df,
		      int type = 1 )
    {

      image L0 = L;

      operator() (I1, I2, L, L0, nx ,ny, radius, d0, df, 0, 0, type);

    }


    template <typename image>
    void vertical ( const image &I1, const image &I2, image &L,
                    int nx, int ny, int radius, int d0, int df,
		    int type = 1 )
    {

      image L0 = L;

      operator() (I1, I2, L0, L, nx, ny, radius, 0, 0, d0, df, type);

    }

};


END_AMI_UTIL

#endif
