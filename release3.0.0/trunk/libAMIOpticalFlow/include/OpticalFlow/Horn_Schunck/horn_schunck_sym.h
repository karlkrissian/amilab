#ifndef _HORN_SCHUNCK_SYM_H
#define _HORN_SCHUNCK_SYM_H

//Esta clase implementa el m�odo de Horn & Schunck multipiramidal con middle optical flow
// esquemas expl�ito e implic�o

#include "src/namespace.h"
#include "src/gradient.h"
#include "warp.h"
#include "mask3x3.h"
#include "src/zoom.h"
#include "file_image.h"
#include "file_uv.h"
#include <math.h>

#define TOL 0.0001

template<class real, bool implicit = true>
class horn_schunck_sym {


  public:

     // this function is for the scale-space scheme
     template<class image, class out>
     int operator()(const image &I1, const image &I2, image &u, image &v,
                    const int nx, const int ny, real sigma = 10, const real sigma_n = 0.5, const real decay_rate = 0.95,
                    const real alpha = 2, const real T = 500, const real dt = 10,
                    out &print = std::cout, const int verbose = 1){

        const int size = nx * ny;
        real *I1s = new real[size];
        real *I2s = new real[size];

        std::fill_n(&u[0], size, 0.0);
        std::fill_n(&v[0], size, 0.0);

        while(sigma >= sigma_n) {

          if(verbose) print << "Scale " << sigma << "\n";
	           /*     if( zoom == n_zoom  && nxx[zoom] > 30 && nyy[zoom] > 30 ) {
                           int radio = 8;//std::max(nxx[zoom]/10, nyy[zoom]/10);
                           int d = std::max(nxx[zoom]/8, nyy[zoom]/8);

                           print << "correlation: radio=" << radio << " d=+-" << d << "\n";
	                        NM_AMI_UTIL::correlation<real> correlate;
	                        correlate (I1z[zoom], I2z[zoom], uz[zoom], vz[zoom],
                                      nxx[zoom], nyy[zoom], radio, -d, d, 1, print);
	                } */
          std::copy(&I1[0], &I1[size], I1s);
          std::copy(&I2[0], &I2[size], I2s);

          //next scale
          gaussian<real> gauss;
          gauss(I1s, nx, ny, sigma);
          //print << I1s << nx << ny;
          gauss(I2s, nx, ny, sigma);
//          print << I2s << nx << ny;

          if(implicit)
             compute_implicit(I1s, I2s, u, v, nx, ny,
                              alpha, T, dt, print, verbose);
          else
             compute_explicit(I1s, I2s, u, v, nx, ny,
                              alpha, T, dt, print, verbose);
          sigma *= decay_rate;
        }


          if(implicit)
             compute_implicit(I1, I2, u, v, nx, ny,
                              alpha, T, dt, print, verbose);
          else
             compute_explicit(I1, I2, u, v, nx, ny,
                              alpha, T, dt, print, verbose);

        delete []I1s;
        delete []I2s;
        return 0;
    }


     // this function is for the multipyramidal scheme
     template<class image, class out>
     int operator()(const image &I1, const image &I2, image &u, image &v,
                    const int nx, const int ny, const int n_zoom = 3, const real alpha = 10,
                    const real T = 500, const real dt = 10, const real Nu = 0.5, out &print = std::cout,
                    const int verbose = 0){

        const int scales = n_zoom + 1;

        std::vector<real *> I1z(scales);
        std::vector<real *> I2z(scales);
        std::vector<real *> uz(scales);
        std::vector<real *> vz(scales);

        std::vector<int> nxx(scales);
        std::vector<int> nyy(scales);

        nxx[0] = nx;
        nyy[0] = ny;

        create_scales(I1, I2, I1z, I2z, uz, vz, nxx, nyy, scales, Nu, print);

        for(int z = n_zoom; z >=0; z --) {

          if(verbose) print << "Scale " << z << "\n";
	           /*     if( zoom == n_zoom  && nxx[zoom] > 30 && nyy[zoom] > 30 ) {
                           int radio = 8;//std::max(nxx[zoom]/10, nyy[zoom]/10);
                           int d = std::max(nxx[zoom]/8, nyy[zoom]/8);

                           print << "correlation: radio=" << radio << " d=+-" << d << "\n";
	                        NM_AMI_UTIL::correlation<real> correlate;
	                        correlate (I1z[zoom], I2z[zoom], uz[zoom], vz[zoom],
                                      nxx[zoom], nyy[zoom], radio, -d, d, 1, print);
	                } */

          if(implicit)
             compute_implicit(I1z[z], I2z[z], uz[z], vz[z], nxx[z], nyy[z],
                              alpha, T, dt, print, verbose);
          else
             compute_explicit(I1z[z], I2z[z], uz[z], vz[z], nxx[z], nyy[z],
                              alpha, T, dt, print, verbose);

          if(z){
             NM_AMI_UTIL::zoom<real> de_zoom;
             de_zoom (uz[z], uz[z-1], nxx[z], nyy[z], nxx[z-1], nyy[z-1]);
             de_zoom (vz[z], vz[z-1], nxx[z], nyy[z], nxx[z-1], nyy[z-1]);

             int size = nxx[z-1] * nyy[z-1];
             std::transform(uz[z-1], &uz[z-1][size], uz[z-1],
                            std::bind2nd(std::multiplies<real>(), 1 / Nu));
             std::transform(vz[z-1], &vz[z-1][size], vz[z-1],
                            std::bind2nd(std::multiplies<real>(), 1 / Nu));

          }

        }

        int size = nxx[0] * nyy[0];
        std::copy(uz[0], &uz[0][size], &u[0]);
        std::copy(vz[0], &vz[0][size], &v[0]);

        delete_scales(I1z, I2z, uz, vz, scales);

        return 0;
    }

  private:

     template<class image, class out>
     int compute_implicit(const image &I1, const image &I2, image &u, image &v,
                          const int nx, const int ny, const real alpha, const real T,
                          const real dt, out &print, int verbose){

        const int size = nx * ny;
        const real C   = computeC2(I1, I2, nx, ny, alpha); //computeC(I1, I2, nx, ny, alpha);

        real *I1x  = new real[size];
        real *I1y  = new real[size];
        real *I1w  = new real[size];
        real *I1xw = new real[size];
        real *I1yw = new real[size];
        real *I2x  = new real[size];
        real *I2y  = new real[size];
        real *I2w  = new real[size];
        real *I2xw = new real[size];
        real *I2yw = new real[size];
        real *uk   = new real[size];
        real *vk   = new real[size];

        NM_AMI_MATH::gradient<real> gradiente;
        gradiente(I1, I1x, I1y, nx, ny);
        gradiente(I2, I2x, I2y, nx, ny);

        for(real t = 0; t < T; t += dt) {

           if(verbose) print << t << ": ";

           warp<real> W;
           W(I1,  u, v, I1w,  nx, ny, false);
           W(I1x, u, v, I1xw, nx, ny, false);
           W(I1y, u, v, I1yw, nx, ny, false);
           W(I2,  u, v, I2w,  nx, ny, true );
           W(I2x, u, v, I2xw, nx, ny, true );
           W(I2y, u, v, I2yw, nx, ny, true );

           std::copy(&(u[0]), &(u[size]), uk);
     	   std::copy(&(v[0]), &(v[size]), vk);

           real error =  1.0;
           while(error > TOL) {

              error = 0;

              for(int j = 0; j < ny; j++)

                for(int k=0; k < nx; k++){

                 const int i = k + j *nx;
                 const real u_   = u[i];
                 const real v_   = v[i];
                 const real diff = I1w[i] - I2w[i];
                 const real Sx = I1xw[i] + I2xw[i];
                 const real Sy = I1yw[i] + I2yw[i];

                 const real difv = (v[i] - vk[i]);
                 const real Du   = (4 + C * Sx * Sx);
                 const real Nu   = C * (diff + uk[i] * Sx - Sy * difv) * Sx +
                                   div(u, k, j, nx, ny);

                 u[i] = (u[i] + dt * Nu ) / ( 1. + dt * Du );

                 const real difu = (u[i] - uk[i]);
                 const real Dv   = (4 + C * Sy * Sy);
                 const real Nv   = C * (diff - Sx * difu + vk[i] * Sy) * Sy +
                                   div(v, k, j, nx, ny);

                 v[i] = (v[i] + dt * Nv ) / ( 1. + dt * Dv );

                 real p = (u[i] - u_) * (u[i] - u_) +
                          (v[i] - v_) * (v[i] - v_);
                 if ( p > error ) error = p;
              }

              for(int j = ny-1; j >= 0; j--)

                for(int k = nx-1; k >= 0; k--){

                 const int i = k + j *nx;
                 const real u_   = u[i];
                 const real v_   = v[i];
                 const real diff = I1w[i] - I2w[i];
                 const real Sx = I1xw[i] + I2xw[i];
                 const real Sy = I1yw[i] + I2yw[i];

                 const real difu = (u[i] - uk[i]);
                 const real Dv   = (4 + C * Sy * Sy);
                 const real Nv   = C * (diff - Sx * difu + vk[i] * Sy) * Sy +
                                   div(v, k, j, nx, ny);

                 v[i] = (v[i] + dt * Nv ) / ( 1. + dt * Dv );

                 const real difv = (v[i] - vk[i]);
                 const real Du   = (4 + C * Sx * Sx);
                 const real Nu   = C * (diff + uk[i] * Sx - Sy * difv) * Sx +
                                   div(u, k, j, nx, ny);

                 u[i] = (u[i] + dt * Nu ) / ( 1. + dt * Du );

                 real p = (u[i] - u_) * (u[i] - u_) +
                          (v[i] - v_) * (v[i] - v_);
                 if ( p > error ) error = p;
               }
               if(verbose)  print << error << ", ";
            }
            if(verbose)  print << "\n";

        }

        delete []I1x;
        delete []I1y;
        delete []I1w;
        delete []I1xw;
        delete []I1yw;
        delete []I2x;
        delete []I2y;
        delete []I2w;
        delete []I2xw;
        delete []I2yw;
        delete []uk;
        delete []vk;
        
        return 0;

     }


     template<class image, class out>
     int compute_explicit(const image &I1, const image &I2, image &u, image &v,
                          const int nx, const int ny, const real alpha, const real T,
                          const real dt, out &print, int verbose){

        const int size = nx * ny;
        const real C   = computeC2(I1, I2, nx, ny, alpha); //computeC(I1, I2, nx, ny, alpha);

        real *I1x  = new real[size];
        real *I1y  = new real[size];
        real *I1w  = new real[size];
        real *I1xw = new real[size];
        real *I1yw = new real[size];
        real *I2x  = new real[size];
        real *I2y  = new real[size];
        real *I2w  = new real[size];
        real *I2xw = new real[size];
        real *I2yw = new real[size];
        real *uk   = new real[size];
        real *vk   = new real[size];
        real *div_u = new real[size];
        real *div_v = new real[size];

        NM_AMI_MATH::gradient<real> gradiente;
        gradiente(I1, I1x, I1y, nx, ny);
        gradiente(I2, I2x, I2y, nx, ny);

        for(real t = 0; t < T; t += dt) {

           if(verbose) print << t << ": ";

           warp<real> W;
           W(I1,  u, v, I1w,  nx, ny, false);
           W(I1x, u, v, I1xw, nx, ny, false);
           W(I1y, u, v, I1yw, nx, ny, false);
           W(I2,  u, v, I2w,  nx, ny, true );
           W(I2x, u, v, I2xw, nx, ny, true );
           W(I2y, u, v, I2yw, nx, ny, true );

           std::copy(&(u[0]), &(u[size]), uk);
     	   std::copy(&(v[0]), &(v[size]), vk);

           const real m[3][3]={{0, 1, 0}, {1, -4, 1}, {0, 1, 0}};
           mask3x3<real> mascara;
           mascara(u, div_u, nx, ny, m);
           mascara(v, div_v, nx, ny, m);

           for(int i = 0; i < size; i++) {

                 const real diff = I1w[i] - I2w[i];
                 const real Sx = I1xw[i] + I2xw[i];
                 const real Sy = I1yw[i] + I2yw[i];
                 const real Nu = C * diff * Sx + div_u[i];
                 const real Nv = C * diff * Sy + div_v[i];
                 u[i] = uk[i] + dt * Nu ;
                 v[i] = vk[i] + dt * Nv ;
           }
           for(int i = size - 1; i >= 0; i--) {

                 const real diff = I1w[i] - I2w[i];
                 const real Sx = I1xw[i] + I2xw[i];
                 const real Sy = I1yw[i] + I2yw[i];
                 const real Nu = C * diff * Sx + div_u[i];
                 const real Nv = C * diff * Sy + div_v[i];
                 u[i] = uk[i] + dt * Nu ;
                 v[i] = vk[i] + dt * Nv ;
           }
           if(verbose)  print << "\n";
        }

        delete []I1x;
        delete []I1y;
        delete []I1w;
        delete []I1xw;
        delete []I1yw;
        delete []I2x;
        delete []I2y;
        delete []I2w;
        delete []I2xw;
        delete []I2yw;
        delete []uk;
        delete []vk;
        delete []div_u;
        delete []div_v;

        return 0;

     }


     template<class image>
     real computeC(const image &I1, const image &I2, const int nx, const int ny,
                   const real alpha) {

       const int size = nx * ny;

       real *I1x = new real[size];
       real *I1y = new real[size];
       real *I2x = new real[size];
       real *I2y = new real[size];

       NM_AMI_MATH::gradient<real> gradiente;
       gradiente(I1, I1x, I1y, nx, ny);

       gradiente(I2, I2x, I2y, nx, ny);

       real  maxgrad = 0;

       for(int i = 0; i < size; i++) {

              const real norm1 = (I1x[i] * I1x[i] + I1y[i] * I1y[i]);
              const real norm2 = (I2x[i] * I2x[i] + I2y[i] * I2y[i]);

              maxgrad = std::max(norm1 + norm2, maxgrad);
       }

       delete []I1x;
       delete []I1y;
       delete []I2x;
       delete []I2y;

       return 1/ (alpha * (maxgrad + 0.000000000001));
     }


     template<class image>
     real computeC2(const image &I1, const image &I2, const int nx, const int ny,
                    const real alpha) {

       const int size = nx * ny;

       real *I1x = new real[size];
       real *I1y = new real[size];
       real *I2x = new real[size];
       real *I2y = new real[size];

       NM_AMI_MATH::gradient<real> gradiente;
       gradiente(I1, I1x, I1y, nx, ny);

       gradiente(I2, I2x, I2y, nx, ny);

       real  norm = 0;

       for(int i = 0; i < size; i++)

              norm += (I1x[i] * I1x[i] + I1y[i] * I1y[i]) +
                      (I2x[i] * I2x[i] + I2y[i] * I2y[i]);

       norm /= size;
       
       delete []I1x;
       delete []I1y;
       delete []I2x;
       delete []I2y;

       return 1/ (alpha * (norm + 0.000000000001));
     }
     
     template<class image>
     real div(const image &in, int x, int y, int nx, int ny) {

                 int mx = x - 1;
                 int my = y - 1;
                 int dx = x + 1;
                 int dy = y + 1;

                 if(mx < 0) mx = 0;
                 if(dx >= nx) dx = nx - 1;
                 if(my < 0) my = 0;
                 if(dy >= ny) dy = ny - 1;

                 return in[ x + my * nx] + in[mx +  y * nx] +
                        in[dx +  y * nx] + in[ x + dy * nx];

     }



     template<class image, class out>
     void create_scales(const image &I1, const image &I2,
                        std::vector<real *> &I1z, std::vector<real *> &I2z,
                        std::vector<real *> &uz,  std::vector<real *> &vz,
                        std::vector<int>    &nx,  std::vector<int>     &ny,
                        int n_zoom, const real Nu, out &print) {

        int size = nx[0] * ny[0];

        I1z[0] = new real[size];
        I2z[0] = new real[size];

        //Suavizamos un poco las imagenes originales
        NM_AMI_UTIL::zoom<real> reduce;
        reduce (I1, I1z[0], nx[0], ny[0], 1);
        reduce (I2, I2z[0], nx[0], ny[0], 1);
        uz[0] = new real[size];
        vz[0] = new real[size];
        std::fill_n(uz[0], size, 0.0);
        std::fill_n(vz[0], size, 0.0);

        for(int t = 1; t < n_zoom; t++ ) {

           nx[t] = (int)((real) (nx[t-1] * Nu + 0.5));
           ny[t] = (int)((real) (ny[t-1] * Nu + 0.5));

           int size = nx[t] * ny[t];
           I1z[t] = new real[size];
           I2z[t] = new real[size];
           uz[t]  = new real[size];
           vz[t]  = new real[size];
           //char s[10];
           
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

#endif
