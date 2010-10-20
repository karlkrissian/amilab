#ifndef _OPTIC_FLOW_H
#define _OPTIC_FLOW_H

#include <math.h>

#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>

#include "namespace.h"
#include "correlation.h"
#include "zoom.h"
#include "optic_pde.h"


#include "src/DT_isotropic.h"
#include "src/DT_perona_malik.h"
#include "src/DT_anisotropic.h"
#include "src/DT_nagel.h"
#include "src/difusion_tensor.h"

//#include "mycorr2d.h"

BEGIN_AMI_METHOD


template <class real>
class optic_flow {

      //typedef difusion_tensor<real, DT_isotropic<real> > DifTensor;
      //typedef difusion_tensor<real, DT_perona_malik<real> > DifTensor;
      //typedef difusion_tensor<real, DT_anisotropic<real> > DifTensor;
      typedef DT_nagel<real> DifTensor;

      real Nu;

   public:

        template<class image, class out>
        int operator() (const image &I1, const image &I2,
        	               image &u, image &v, int nx, int ny,
		                  int n_zoom = 3, real alpha = 0.6, real isotropy = 0.1,
		                  real T = 500, real dt = 10, real nu = 0.5, out &print = std::cout) {

                Nu = nu;
                return compute_optic_flow(I1, I2, u, v, nx, ny, n_zoom,
                                          alpha, isotropy, T, dt, print);
        }


   private:

        template <class image, class out>
        int compute_optic_flow(const image &I1, const image &I2, image &u,
                               image &v, int nx, int ny, int n_zoom,
                               real alpha, real isotropy, real T, real dt, out &print) {

                const int scales = n_zoom + 1;

                std::vector<real *> I1z(scales);
                std::vector<real *> I2z(scales);
                std::vector<real *> uz(scales);
                std::vector<real *> vz(scales);

                std::vector<int> nxx(scales);
                std::vector<int> nyy(scales);

                nxx[0] = nx;
                nyy[0] = ny;

                
                create_scales(I1, I2, I1z, I2z, uz, vz, nxx, nyy, scales, print);

                for(int zoom = n_zoom; zoom >=0; zoom --) {

                   print << "Scale " << zoom << "\n";


	                if( zoom == n_zoom  && nxx[zoom] > 30 && nyy[zoom] > 30 ) {

                           int radio = 1; //4; //std::max(nxx[zoom]/10, nyy[zoom]/10);
                           int d = std::max(nxx[zoom]/8, nyy[zoom]/8);

                           print << "correlation: radio=" << radio << " d=+-" << d << "\n";

/*
	                        NM_AMI_UTIL::correlation<real> correlate;
	                        correlate (I1z[zoom], I2z[zoom], uz[zoom], vz[zoom],
                                      nxx[zoom], nyy[zoom], radio, -d, d, 1, print);
*/

                  // .......................
/*
	                           NM_AMI_UTIL::mycorrelation2D<real> correlate2D;
	                           correlate2D( I1z[zoom], I2z[zoom], uz[zoom], vz[zoom],
                                          nxx[zoom], nyy[zoom], 16, 0 );
*/
	                } 


                   optic_pde<real, DifTensor >  optic;
                   optic(I1z[zoom], I2z[zoom], uz[zoom], vz[zoom], nxx[zoom], nyy[zoom],
                         T, dt, alpha, isotropy, print);

                   if(zoom){

                      NM_AMI_UTIL::zoom<real> de_zoom;


	                    de_zoom (uz[zoom], uz[zoom-1], nxx[zoom], nyy[zoom], nxx[zoom-1], nyy[zoom-1]);
                      de_zoom (vz[zoom], vz[zoom-1], nxx[zoom], nyy[zoom], nxx[zoom-1], nyy[zoom-1]);

                      int size = nxx[zoom-1] * nyy[zoom-1];
                      std::transform(uz[zoom-1], &uz[zoom-1][size], uz[zoom-1],
                                     std::bind2nd(std::multiplies<real>(), 1 / Nu));
                      std::transform(vz[zoom-1], &vz[zoom-1][size], vz[zoom-1],
                                     std::bind2nd(std::multiplies<real>(), 1 / Nu));
                   }
                }

                int size = nxx[0] * nyy[0];
                std::copy(uz[0], &uz[0][size], &u[0]);
                std::copy(vz[0], &vz[0][size], &v[0]);

                delete_scales(I1z, I2z, uz, vz, scales);

                return 0;
        }


        template<class image, class out>
        void create_scales(const image &I1, const image &I2,
                           std::vector<real *> &I1z, std::vector<real *> &I2z,
                           std::vector<real *> &uz,  std::vector<real *> &vz,
                           std::vector<int>    &nx,  std::vector<int>     &ny,
                           int n_zoom, out &print) {

                int size = nx[0] * ny[0];

                I1z[0] = new real[size];
                I2z[0] = new real[size];

                //Suavizamos un poco las imagenes originales
                NM_AMI_UTIL::zoom<real> reduce;
                reduce (I1, I1z[0], nx[0], ny[0], 1);
                reduce (I2, I2z[0], nx[0], ny[0], 1);

                //La otra opcin es copiarlas directamente --> da peor resultado
                //std::copy(&I1[0], &I1[size], I1z[0]);
                //std::copy(&I2[0], &I2[size], I2z[0]);


                uz[0] = new real[size];
                vz[0] = new real[size];
                std::fill_n(uz[0], size, 0.0);
                std::fill_n(vz[0], size, 0.0);

                
                for(int t = 1; t < n_zoom; t++ ) {

                        nx[t] = (int) ((real) (nx[t-1] * Nu + 0.5));
                        ny[t] = (int) ((real) (ny[t-1] * Nu + 0.5));

                        int size = nx[t] * ny[t];
                        I1z[t] = new real[size];
                        I2z[t] = new real[size];
                        uz[t]  = new real[size];
                        vz[t]  = new real[size];


                        NM_AMI_UTIL::zoom<real> reduce;

                        reduce (I1z[t-1], I1z[t], nx[t-1], ny[t-1], Nu);
                        reduce (I2z[t-1], I2z[t], nx[t-1], ny[t-1], Nu);

                        reduce (uz[t-1],  uz[t],  nx[t-1], ny[t-1], Nu);
                        reduce (vz[t-1],  vz[t],  nx[t-1], ny[t-1], Nu);
                }
        }


        void delete_scales(std::vector<real *> &I1z, std::vector<real *> &I2z,
                           std::vector<real *> &uz,  std::vector<real *> &vz, int n) {

                for(int i = 0; i < n; i++) {

                        delete [] I1z[i];
                        delete [] I2z[i];
                        delete [] uz[i];
                        delete [] vz[i];
                }
        }


};


END_AMI_METHOD


#endif


// &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&& &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&& &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
// &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&& &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&& &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
// &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&& &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&& &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
// &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&& &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&& &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
// &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&& &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&& &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&

//#define MOD_BEST_SOL
//#define GAUSSIAN_SMOOTHING

#if (0)
           #ifdef GAUSSIAN_SMOOTHING

            /* Gaussian smoothing */
            //  void gauss_conv (float sigma,long height,long width,float hx,float hy, float precision,long bc,float**f);

            real **out1, **out2;
            real **origin1, **origin2;

            try {

                 out1 = new real*[ny+1];
                 out2 = new real*[ny+1];

                 origin1 = new real*[ny];
                 origin2 = new real*[ny];


                 for (int jj=0; jj<ny+1; jj++)  {

                    out1[jj] = new real [nx+1];
                    out2[jj] = new real [nx+1];

                    if (jj > 0) {

                        origin1[jj-1] = new real [nx];
                        origin2[jj-1] = new real [nx];
                    }
                 }


                 for (int ii = 0; ii<ny; ii++)   //
                    for (int jj = 0; jj<nx; jj++)  {

                      out1[ii][jj] = I1[ii*nx + jj];
                      out2[ii][jj] = I2[ii*nx + jj];

                      origin1[ii][jj] = I1[ii*nx + jj];
                      origin2[ii][jj] = I2[ii*nx + jj];
                    }

              }
              catch (std::bad_alloc) {        // error
                std::cout << "Memory unallocated...";
                exit(-1);                     // finish with error
              }

      // ..........................................................

              gauss_conv ( 4.0, ny, nx, 1, 1, 5.0, 1, out1 );
              gauss_conv ( 4.0, ny, nx, 1, 1, 5.0, 1, out2 );

                 for (int ii = 0; ii<ny; ii++)   //
                    for (int jj = 0; jj<nx; jj++)  {

                      I1[ii*nx + jj] = origin1[ii][jj] - out1[ii][jj];
                      I2[ii*nx + jj] = origin2[ii][jj] - out2[ii][jj];
                    }

      // .................................

              for (int jj=0; jj<ny+1; jj++) {

                      delete [] out1[jj];
                      delete [] out2[jj];

                    if (jj > 0) {

                      delete [] origin1[jj-1];
                      delete [] origin2[jj-1];

                      }
              }

              delete [] out1;
              delete [] out2;

              delete [] origin1;
              delete [] origin2;

      // .................................

           #endif

// &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&& &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&& &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
// &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&& &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&& &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
           
           #ifdef MOD_BEST_SOL
/*
                if ( n_zoom == 0 ) {

                  std::copy(&u[0], &u[nx*ny], uz[0] );
                  std::copy(&v[0], &v[nx*ny], vz[0] );

                  std::cout << "copiando..." << std::endl;
                }
*/
           #endif

#endif
