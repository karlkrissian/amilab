#ifndef _OPTIC_FLOW_VIDEO_H
#define _OPTIC_FLOW_VIDEO_H


#include <math.h>

#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>

#include "src/namespace.h"
//#include "src/correlation.h"
#include "src/zoom.h"
#include "optic_pde_video.h"
//#include "optic_pde_video_explicit.h"

#include "src/DT_isotropic.h"
#include "src/DT_perona_malik.h"
#include "src/DT_nagel.h"
#include "src/difusion_tensor.h"

/*
#include "ami.h"
#include "ami_correlation2D.h"
#include "file_uv.h"
*/

//#include "mycorr2d.h"


BEGIN_AMI_METHOD


template <class real>
class optic_flow_video {

      //typedef Schemes::DifusionTensor<real,Schemes::DTPierre<real> > DifTensor;
      //typedef difusion_tensor<real, DT_isotropic<real> > DifTensor;
      //typedef difusion_tensor<real, DT_perona_malik<real> > DifTensor;
      //typedef Schemes::DifusionTensor<real,Schemes::DTAnisotropic<real> > DifTensor;
      typedef DT_nagel<real> DifTensor;

      real Nu;

   public:

        template<class image, class out>
        int operator() (const std::vector<image> &I, std::vector<image> &u,
                        std::vector<image> &v, int nx, int ny,
		                  int n_zoom = 3, real alpha = 0.6, real beta = 0.3, real gamma = 1,
                        real isotropy = 0.1, real T = 500, real dt = 10, real nu = 0.5,
                        out &print = std::cout) {

                Nu = nu;
                printf("optic_flow_video \t n_zoom %d alpha %f beta %f \n",n_zoom,alpha,beta);

                return compute_optic_flow(I, u, v, nx, ny, n_zoom,
                                          alpha, beta, gamma, isotropy, T, dt, print);
        }


   private:

        void itoa( std::string &numero, int n, int pos ) {

            numero[pos] = ((char) (n % 10 + '0'));
            n /= 10;
            numero[pos - 1] = ((char) (n % 10 + '0'));
        }


        template <class image, class out>
        int compute_optic_flow(const std::vector<image> &I, std::vector<image> &u,
                               std::vector<image> &v, int nx, int ny, int n_zoom,
                               real alpha, real beta, real gamma, real isotropy,
                               real T, real dt, out &print) {

                const int scales = n_zoom + 1;
                const int frames = I.size();

                std::vector<std::vector<real *> > Iz(scales);
                std::vector<std::vector<real *> > uz(scales);
                std::vector<std::vector<real *> > vz(scales);

                std::vector<int> nxx(scales);
                std::vector<int> nyy(scales);

                nxx[0] = nx;
                nyy[0] = ny;

                create_scales(I, Iz, uz, vz, nxx, nyy, scales, frames, print);

                for(int zoom = n_zoom; zoom >=0; zoom --) {

                   print << "Scale " << zoom << "\n";

/*
	                if( zoom == n_zoom  && nxx[zoom] > 30 && nyy[zoom] > 30 ) {

                           int radio = 1; //8;//std::max(nxx[zoom]/10, nyy[zoom]/10);
                           int d = std::max(nxx[zoom]/8, nyy[zoom]/8);

                           print << "correlation: radio=" << radio << " d=+-" << d << "\n";


                           for(int i = 0; i < frames - 1; i++) {

//                             
//	                           NM_AMI_UTIL::correlation<real> correlate;
//	                           correlate (Iz[zoom][i], Iz[zoom][i+1], uz[zoom][i], vz[zoom][i],
//                                         nxx[zoom], nyy[zoom], radio, -d, d, 1, print);
//

// URGENTE: PREGUNTAR A JAVIER
#if (0)
                  // .......................

                            float **image1_pos, ** image2_pos;

                            ami_malloc2d( image1_pos, float, nxx[zoom], nyy[zoom] );
                            ami_malloc2d( image2_pos, float, nxx[zoom], nyy[zoom] );                            

                            float **flowX_pos, **flowY_pos;

                            ami_malloc2d( flowX_pos, float, nxx[zoom], nyy[zoom] );
                            ami_malloc2d( flowY_pos, float, nxx[zoom], nyy[zoom] );

                            float **corr_pos, **conf_x_pos, **conf_y_pos;

                            ami_malloc2d( corr_pos, float, nxx[zoom], nyy[zoom] );
                            
                            ami_malloc2d( conf_x_pos, float, nxx[zoom], nyy[zoom] );
                            ami_malloc2d( conf_y_pos, float, nxx[zoom], nyy[zoom] );

                  // .......................

                            for( int ii=0; ii<nyy[zoom]; ii++ )

                                 for( int jj=0; jj<nxx[zoom]; jj++ ) {

                                     image1_pos[ii][jj] = Iz[zoom][i][ ii*nxx[zoom] + jj ];
                                     image2_pos[ii][jj] = Iz[zoom][i+1][ ii*nxx[zoom] + jj ];

                                     flowX_pos[ii][jj] = uz[zoom][i][ ii*nxx[zoom] + jj ];
                                     flowY_pos[ii][jj] = vz[zoom][i][ ii*nxx[zoom] + jj ];

                                     corr_pos[ii][jj] = 0.0;

                                     conf_x_pos[ii][jj] = 0.0;
                                     conf_y_pos[ii][jj] = 0.0;
                                 }

                  // .......................

                            int corrWin[2] = { 16, 16 };

                            ami_qhc_optic_flow_correlation (
                                    &image1_pos, &image2_pos,
                                    nxx[zoom], nyy[zoom],
                                    flowX_pos, flowY_pos,
                                    corr_pos,
                                    conf_x_pos, conf_y_pos,
                                    0, 0, 1, 1,   // xInit, yInit, xIntervalSize, yIntervalSize
                                    corrWin,
                                    1, //(float) windowDeformation,
                                    1);

                  // .......................

                            for( int ii=0; ii<nyy[zoom]; ii++ )

                                 for( int jj=0; jj<nxx[zoom]; jj++ ) {

                                     uz[zoom][i][ ii*nxx[zoom] + jj ] = flowX_pos[ii][jj];
                                     vz[zoom][i][ ii*nxx[zoom] + jj ] = flowY_pos[ii][jj];
                                 }
                                                      
                            ami_free2d( image1_pos );
                            ami_free2d( image2_pos );
                            ami_free2d( flowX_pos );
                            ami_free2d( flowY_pos );
                            ami_free2d( corr_pos );
                            ami_free2d( conf_x_pos );
                            ami_free2d( conf_y_pos );

                  // .......................

                             std::string fncorr( "eorrelation_VD_2x2_00.uv" );
                             itoa( fncorr, i, 20 );
                             NM_AMI_FILE::save_uv<real>( uz[zoom][i], vz[zoom][i], nxx[zoom], nyy[zoom], fncorr );



#else
                  // .......................

	                           NM_AMI_UTIL::mycorrelation2D<real> correlate2D;
	                           correlate2D( Iz[zoom][i], Iz[zoom][i+1], uz[zoom][i], vz[zoom][i],
                                         nxx[zoom], nyy[zoom], 16, i );


#endif
                           }
 	                } 
*/

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

                         //print << uz[zoom-1][i] << nxx[zoom-1] << nyy[zoom-1];
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
        void create_scales(const std::vector<image> &I, std::vector<std::vector<real *> > &Iz,
                           std::vector<std::vector<real *> > &uz,  std::vector<std::vector<real *> > &vz,
                           std::vector<int>    &nx,  std::vector<int>     &ny,
                           int n_zoom, int frames, out &print) {



                int size = nx[0] * ny[0];


                for(int i = 0; i < frames; i++) {

                   Iz[0].push_back(new real[size]);

                   //Suavizamos un poco las imagenes originales
                   NM_AMI_UTIL::zoom<real> reduce;
                   reduce (I[i], Iz[0][i], nx[0], ny[0], 1);
                   //print << Iz[0][i] << nx[0] << ny[0];
                   //La otra opci� es copiarlas directamente --> da peor resultado
                   //std::copy(&I[i][0], &I[i][size], Iz[0][i]);
                }

                for(int i = 0; i < frames - 1; i++) {

                   uz[0].push_back(new real[size]);
                   vz[0].push_back(new real[size]);
                   std::fill_n(uz[0][i], size, 0.0);
                   std::fill_n(vz[0][i], size, 0.0);
               }

                for(int t = 1; t < n_zoom; t++ ) {

                        nx[t] = (int) ((real) (nx[t-1] * Nu + 0.5));

                        ny[t] = (int) ((real) (ny[t-1] * Nu + 0.5));

                        int size = nx[t] * ny[t];



                        NM_AMI_UTIL::zoom<real> reduce;
                        for(int i = 0; i < frames - 1; i++) {

                           Iz[t].push_back(new real[size]);

                           uz[t].push_back(new real[size]);
                           vz[t].push_back(new real[size]);

                           reduce (Iz[t-1][i], Iz[t][i], nx[t-1], ny[t-1], Nu);
                           //print << Iz[t][i] << nx[t] << ny[t];

                           reduce (uz[t-1][i], uz[t][i],  nx[t-1], ny[t-1], Nu);
                           reduce (vz[t-1][i], vz[t][i],  nx[t-1], ny[t-1], Nu);
                        }
                        Iz[t].push_back(new real[size]);
                        reduce (Iz[t-1][frames - 1], Iz[t][frames - 1], nx[t-1], ny[t-1], Nu);
                }
        }


        void delete_scales(std::vector<std::vector<real *> > &Iz, std::vector<std::vector<real *> > &uz,
                           std::vector<std::vector<real *> > &vz) {

                for(unsigned int i = 0; i < Iz.size(); i++)

                   for(unsigned int j = 0; j < Iz[i].size(); j++)

                        delete [] Iz[i][j];

                for(unsigned int i = 0; i < uz.size(); i++)

                   for(unsigned int j = 0; j < uz[i].size(); j++) {


                        delete [] uz[i][j];
                        delete [] vz[i][j];
                }



        }
};


END_AMI_METHOD


#endif


#if (0)
void ami_qhc_optic_flow_correlation (
    float ***image1, float ***image2, /* Input images */
    int dimX, int dimY, /* Dimension of the images */
    float **u, float **v, /* Input/output computed flow */
    float **c, /* Correlation value normalized between -1 and 1 */
    float **cX, float **cY, /* Confidence value in the x/y axe */
    int xInit=0, int yInit=0, /* Initial coordenate point to compute the correlation */
    int xIntervalSize=1, int yIntervalSize=1, /* Displacement between points for computing the correlation */
    int sizeCorrelationWindow[2]={16,16}, /* Size of correlation window (it can be different in each axe) and it has to be a power of 2 */
    float windowDeformation=0, /* Window parameter to control the warping in the correlation window;
				windowDeformation = 0 -> image2 is warped using flow in all points of the window,
				windowDedormation = 1 -> image2 is warped using flow in the central point of the window */
    int nImages /* Number of pair of images */

    );
#endif




/*
        void itoa( std::string &numero, int n, int pos ) {

            numero[pos] = ((char) (n % 10 + '0'));
            n /= 10;
            numero[pos - 1] = ((char) (n % 10 + '0'));
        }
*/


/*
                            float **image1_pos, **image2_pos;

                            ami_malloc2d( image1_pos, float, nxx[zoom], nyy[zoom] );
                            ami_malloc2d( image2_pos, float, nxx[zoom], nyy[zoom] );

                            float **flowX_pos, **flowY_pos;

                            ami_malloc2d( flowX_pos, float, nxx[zoom], nyy[zoom] );
                            ami_malloc2d( flowY_pos, float, nxx[zoom], nyy[zoom] );

                            float **corr_pos, **conf_x_pos, **conf_y_pos;

                            ami_malloc2d( corr_pos, float, nxx[zoom], nyy[zoom] );

                            ami_malloc2d( conf_x_pos, float, nxx[zoom], nyy[zoom] );
                            ami_malloc2d( conf_y_pos, float, nxx[zoom], nyy[zoom] );

                  // .......................

                            for( int ii=0; ii<nyy[zoom]; ii++ )

                                 for( int jj=0; jj<nxx[zoom]; jj++ ) {

                                     image1_pos[ii][jj] = Iz[zoom][i][ ii*nxx[zoom] + jj ];
                                     image2_pos[ii][jj] = Iz[zoom][i+1][ ii*nxx[zoom] + jj ];

                                     flowX_pos[ii][jj] = 0.0; //uz[zoom][i][ ii*nxx[zoom] + jj ];
                                     flowY_pos[ii][jj] = 0.0; //vz[zoom][i][ ii*nxx[zoom] + jj ];

                                     corr_pos[ii][jj] = 0.0;

                                     conf_x_pos[ii][jj] = 0.0;
                                     conf_y_pos[ii][jj] = 0.0;
                                 }

                  // .......................

                            int corrWin[2] = { 16, 16 };

                            ami_qhc_optic_flow_correlation (
                                    &image1_pos, &image2_pos,
                                    nxx[zoom], nyy[zoom],

                                    flowX_pos, flowY_pos,
                                    corr_pos,
                                    conf_x_pos, conf_y_pos,
                                    0, 0, 1, 1,   // xInit, yInit, xIntervalSize, yIntervalSize
                                    corrWin,
                                    1, //(float) windowDeformation,  // Preguntar que incidencia tiene modificando este parametro por 0
                                    1);

                  // .......................

                            for( int ii=0; ii<nyy[zoom]; ii++ )

                                 for( int jj=0; jj<nxx[zoom]; jj++ ) {

                                     uz[zoom][i][ ii*nxx[zoom] + jj ] = flowY_pos[ii][jj]; //flowX_pos[ii][jj];
                                     vz[zoom][i][ ii*nxx[zoom] + jj ] = flowX_pos[ii][jj]; //flowY_pos[ii][jj];
                                 }

                            ami_free2d( image1_pos );
                            ami_free2d( image2_pos );
                            ami_free2d( flowX_pos );
                            ami_free2d( flowY_pos );
                            ami_free2d( corr_pos );
                            ami_free2d( conf_x_pos );
                            ami_free2d( conf_y_pos );

                  // .......................

                             std::string fncorr( "forrelation_VD_16x16_00.uv" );
                             itoa( fncorr, i, 22 );
                             NM_AMI_FILE::save_uv<real>( uz[zoom][i], vz[zoom][i], nxx[zoom], nyy[zoom], fncorr );

*/

