#ifndef _OPTIC_FLOW_VIDEO_H
#define _OPTIC_FLOW_VIDEO_H


#include <math.h>

#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>

#include "src/namespace.h"
#include "src/correlation.h"
#include "src/zoom.h"
#include "optic_pde_video.h"

#include "src/DT_isotropic.h"
#include "src/DT_perona_malik.h"
#include "src/DT_anisotropic.h"
#include "src/DT_nagel.h"
#include "src/difusion_tensor.h"

#include "mycorr2d.h"

BEGIN_AMI_METHOD


template <class real>
class optic_flow_video {

      //typedef difusion_tensor<real, DT_isotropic<real> > DifTensor;
      //typedef difusion_tensor<real, DT_perona_malik<real> > DifTensor;
      //typedef difusion_tensor<real, DT_anisotropic<real> > DifTensor;
      typedef DT_nagel<real> DifTensor;

      real Nu;

   public:

        template<class image, class out>
        int operator() (const vector<image> &I, vector<image> &u,
                        vector<image> &v, int nx, int ny,
		        int n_zoom = 3, real alpha = 0.6, real beta = 0.3, real gamma = 1,
                        real isotropy = 0.1, real T = 500, real dt = 10, real nu = 0.5,
                        out &print = std::cout) {

                Nu = nu;
                return compute_optic_flow(I, u, v, nx, ny, n_zoom,
                                          alpha, beta, gamma, isotropy, T, dt, print);
        }


   private:

        template <class image, class out>
        int compute_optic_flow(const vector<image> &I, vector<image> &u,
                               vector<image> &v, int nx, int ny, int n_zoom,
                               real alpha, real beta, real gamma, real isotropy,
                               real T, real dt, out &print) {


		print << " VIDEO INVERSO (OPTIC_FLOW_FILE)" << "\n";
                               
                const int scales = n_zoom + 1;
                const int frames = I.size();

                vector<vector<real *> > Iz(scales);
                vector<vector<real *> > uz(scales);
                vector<vector<real *> > vz(scales);

                vector<int> nxx(scales);
                vector<int> nyy(scales);

                nxx[0] = nx;
                nyy[0] = ny;

                create_scales(I, Iz, uz, vz, nxx, nyy, scales, frames, print);

                for(int zoom = n_zoom; zoom >=0; zoom --) {

                   print << "Scale " << zoom << "\n";


	                if( zoom == n_zoom  && nxx[zoom] > 30 && nyy[zoom] > 30 ) {

                           int radio = 1; //4; //std::max(nxx[zoom]/10, nyy[zoom]/10);
                           int d = std::max(nxx[zoom]/8, nyy[zoom]/8);

                           print << "correlation: radio=" << radio << " d=+-" << d << "\n";


                           for(int i = 0; i < frames - 1; i++) {

/*                             
	                           NM_AMI_UTIL::correlation<real> correlate;
	                           correlate (Iz[zoom][i], Iz[zoom][i+1], uz[zoom][i], vz[zoom][i],
                                         nxx[zoom], nyy[zoom], radio, -d, d, 1, print);
*/

                  // .......................

	                           NM_AMI_UTIL::mycorrelation2D<real> correlate2D;
	                           correlate2D( Iz[zoom][i], Iz[zoom][i+1], uz[zoom][i], vz[zoom][i],
                                         nxx[zoom], nyy[zoom], 16, i );

                           }

 	                }


                   optic_pde_video<real, DifTensor >  optic;
                   optic(Iz[zoom], uz[zoom], vz[zoom], nxx[zoom], nyy[zoom],
                         T, dt, alpha, beta, gamma, isotropy, print);

                   if(zoom){

                      for(int i = 0; i < frames - 1; i++) {
                         NM_AMI_UTIL::zoom<real> de_zoom;

	                      de_zoom (uz[zoom][i], uz[zoom-1][i], nxx[zoom], nyy[zoom], nxx[zoom-1], nyy[zoom-1]);
                         de_zoom (vz[zoom][i], vz[zoom-1][i], nxx[zoom], nyy[zoom], nxx[zoom-1], nyy[zoom-1]);

                         int size = nxx[zoom-1] * nyy[zoom-1];
                         std::transform(uz[zoom-1][i], &uz[zoom-1][i][size], uz[zoom-1][i],
                                        std::bind2nd(std::multiplies<real>(), 1 / Nu));
                         std::transform(vz[zoom-1][i], &vz[zoom-1][i][size], vz[zoom-1][i],
                                        std::bind2nd(std::multiplies<real>(), 1 / Nu));
                      }
                   }
                }

                int size = nxx[0] * nyy[0];

                for(int i = 0; i < frames - 1; i++) {
                   std::copy(uz[0][i], &uz[0][i][size], &u[i][0]);
                   std::copy(vz[0][i], &vz[0][i][size], &v[i][0]);
                }

                delete_scales(Iz, uz, vz);

                return 0;
        }


        template<class image, class out>
        void create_scales(const vector<image> &I, vector<vector<real *> > &Iz,
                           vector<vector<real *> > &uz,  vector<vector<real *> > &vz,
                           vector<int>    &nx,  vector<int>     &ny,
                           int n_zoom, int frames, out &print) {

                int size = nx[0] * ny[0];


                for(int i = 0; i < frames; i++) {

                   Iz[0].push_back(new real[size]);

                   //Suavizamos un poco las imagenes originales
                   NM_AMI_UTIL::zoom<real> reduce;
                   reduce (I[i], Iz[0][i], nx[0], ny[0], 1);
                   
                   //La otra opcin es copiarlas directamente --> da peor resultado
                   //std::copy(&I[i][0], &I[i][size], Iz[0][i]);
                }

                for(int i = 0; i < frames - 1; i++) {

                   uz[0].push_back(new real[size]);
                   vz[0].push_back(new real[size]);
                   std::fill_n(uz[0][i], size, 0.0);
                   std::fill_n(vz[0][i], size, 0.0);
               }

                for(int t = 1; t < n_zoom; t++ ) {

		  nx[t] = (int)((real) (nx[t-1] * Nu + 0.5));
		  ny[t] = (int)((real) (ny[t-1] * Nu + 0.5));

                        int size = nx[t] * ny[t];

                        NM_AMI_UTIL::zoom<real> reduce;
                        for(int i = 0; i < frames - 1; i++) {

                           Iz[t].push_back(new real[size]);

                           uz[t].push_back(new real[size]);
                           vz[t].push_back(new real[size]);

                           reduce (Iz[t-1][i], Iz[t][i], nx[t-1], ny[t-1], Nu);
                           reduce (uz[t-1][i], uz[t][i], nx[t-1], ny[t-1], Nu);
                           reduce (vz[t-1][i], vz[t][i], nx[t-1], ny[t-1], Nu);
                        }
                        Iz[t].push_back(new real[size]);
                        reduce (Iz[t-1][frames - 1], Iz[t][frames - 1], nx[t-1], ny[t-1], Nu);
                }
        }


        void delete_scales(vector<vector<real *> > &Iz, vector<vector<real *> > &uz,
                           vector<vector<real *> > &vz) {

                for(int i = 0; i < Iz.size(); i++)

                   for(int j = 0; j < Iz[i].size(); j++)

                        delete [] Iz[i][j];

                for(int i = 0; i < uz.size(); i++)

                   for(int j = 0; j < uz[i].size(); j++) {

                        delete [] uz[i][j];
                        delete [] vz[i][j];
                }
        }
};


END_AMI_METHOD


#endif

