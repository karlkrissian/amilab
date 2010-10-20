#ifndef _OPTIC_PDE_H
#define _OPTIC_PDE_H

#include "src/namespace.h"

#include <exception>
#include <iostream>
#include <math.h>
#include <list.h>

#include "optic_scheme_video.h"
#include "inverse_optic_flow.h"
#include "src/gradient.h"
#include "src/weights.h"
#include "src/warp.h"


#include "src/file_uv.h"



#define ERROR 0.01

#define LINEAR 0
#define NON_LINEAR 1
#define NON_LINEAR2 2
#define TV 3
#define NORM_LINEAR 4

#define EPSILON 0.001


BEGIN_AMI_METHOD

template <typename real, typename difusion_tensor>
class optic_pde_video {

    typedef NM_AMI_UTIL::warp<real> warp;
    typedef NM_AMI_METHOD::optic_scheme_video<real> pde;

protected:

    real C, lambda, beta, gamma;

    void phip(const real *u, const real *v, const real *uw, const real *vw,
              real *phi, int nx, int ny, int phi_type = NON_LINEAR) {

       switch(phi_type) {
          case LINEAR:
              for(int i = 0; i < nx * ny; i++) phi[i] = beta;
              break;
          case NON_LINEAR:
              for(int i = 0; i < nx * ny; i++) {
                  const real du = u[i] - uw[i];
                  const real dv = v[i] - vw[i];
                  const real du2 = du * du;
                  const real dv2 = dv * dv;
                  const real norm2 = du2 + dv2;
                  phi[i] = beta * exp(-norm2 / gamma);// /gamma;

              }
              break;
          case 2:
              for(int i = 0; i < nx * ny; i++) {
                  const real du = u[i] - uw[i];
                  const real dv = v[i] - vw[i];
                  const real du2 = du * du;
                  const real dv2 = dv * dv;
                  const real norm2 = du2 + dv2;
                  const real f = 1 - norm2 / gamma;
                  phi[i] = beta * exp(f) * f / gamma;

              }
              break;
          case TV:     //TV temporal no parece que de buen resultado
              for(int i = 0; i < nx * ny; i++) {
                  const real du = u[i] - uw[i];
                  const real dv = v[i] - vw[i];
                  const real du2 = du * du;
                  const real dv2 = dv * dv;
                  const real norm2 = du2 + dv2;
                  phi[i] = beta / sqrt(norm2 + EPSILON * EPSILON);
              }
              break;
          case NORM_LINEAR:
              for(int i = 0; i < nx * ny; i++) {
                  const real du2 = u[i] * u[i];
                  const real dv2 = v[i] * v[i];
                  const real duw2 = uw[i] * uw[i];
                  const real dvw2 = vw[i] * vw[i];
                  const real norm = du2 + dv2 - duw2 -dvw2;

                  //const real norm2 = (norm < 0)? -norm:norm;
                  const real signo = (norm < 0)? -1:1;

                  const real norm2 = norm * norm;
                  phi[i] = 2 * beta * norm;
                  //phi[i] = -2 * norm * exp((float) -norm2/gamma) / gamma;
                  //phi[i] = -2 * beta * pow(norm,-3);
                  //phi[i] = beta * exp(-norm2 / gamma);
                  //phi[i] = /*signo */ beta;
              }
              break;
       }
    }

    template <typename image>
    void find_lambda(const image &Ix, const image &Iy, int size,
                     const real isotropy, const real alpha ) {

        std::list<real> N;

	     real  maxgrad = 0;

	     for(int i = 0; i < size; i++) {

              const real norm = Ix[i] * Ix[i] + Iy[i] * Iy[i];

              if ( norm  > maxgrad ) {maxgrad = norm;}

              N.push_back(norm);
           }

        N.sort();
        int target = (int) (isotropy * N.size());

        typename std::list<real>::iterator i = N.begin();
        for ( int count = 0; count < target; count ++, i ++ );

        lambda =  (*i);

        if(lambda * lambda < 0.001 ) lambda += 0.01;

        //si las imágenes son de una tonalidad --> maxima prioridad a regularizacion
        if(maxgrad >= 0.000000000001)
           C  = 1/ (alpha * maxgrad);
        else
           C = 999999999.9;

	     std::cout << "Lambda: " << lambda << std::endl;
	     std::cout << "C: " << C;
    }


    template <class image>
    void crear(vector<image> &I, int size) {

       for(typename vector<image>::iterator i = I.begin(); i != I.end(); i++)

          (*i) = new real[size];
    }

    template <class image>
    void borrar(vector<image> &I) {

       for( typename vector<image>::iterator i = I.begin(); i != I.end(); i++)

          delete [](*i);
    }


  public:


    template <typename image, class out>
    void operator () ( const vector<image> &I, vector<image> &u,
                       vector<image> &v, int nx, int ny,
                       const real T, const real dt,
                       const real alpha, const real betaa, const real gamm,
                       const real isotropy, out &print = std::cout) {

		print << " VIDEO INVERSO (OPTIC_PDEEE_FILE)" << "\n";
                       
        int size = nx * ny;
        int frames = I.size();
        int frames_ = frames - 1;
        beta = betaa;
        gamma = gamm;

        // general functions of StereoFlow
        vector<real *> Ix(frames);
        vector<real *> Iy(frames);
        vector<real *> Iw(frames_);
        vector<real *> Ixw(frames_);
        vector<real *> Iyw(frames_);
        vector<real *> uk(frames_);
        vector<real *> ux(frames_);
        vector<real *> uy(frames_);
        vector<real *> uw(frames_-1);
        vector<real *> uw_(frames_-1);
        vector<real *> uwx(frames_-1);
        vector<real *> uwy(frames_-1);
        vector<real *> vk(frames_);
        vector<real *> vx(frames_);
        vector<real *> vy(frames_);
        vector<real *> vw(frames_-1);
        vector<real *> vw_(frames_-1);
        vector<real *> vwx(frames_-1);
        vector<real *> vwy(frames_-1);
        vector<real *> Difa(frames_);
        vector<real *> Difb(frames_);
        vector<real *> Difc(frames_);
        vector<real *> phi(frames_-1);
        vector<real *> phi_(frames_-1);

        crear(Ix, size);
        crear(Iy, size);
        crear(Iw, size);
        crear(Ixw, size);
        crear(Iyw, size);
        crear(uk, size);
        crear(uw, size);
        crear(uw_, size);
        crear(ux, size);
        crear(uy, size);
        crear(uwx, size);
        crear(uwy, size);
        crear(vk, size);
        crear(vw, size);
        crear(vw_, size);
        crear(vx, size);
        crear(vy, size);
        crear(vwx, size);
        crear(vwy, size);
        crear(Difa, size);
        crear(Difb, size);
        crear(Difc, size);
        crear(phi, size);
        crear(phi_, size);

        // computing the gradient of I1 and I2
        for(int i = 0; i < frames; i++) {
           NM_AMI_MATH::gradient<real> gradient;
           gradient(I[i], Ix[i], Iy[i], nx, ny);
        }

        find_lambda(Ix[0], Iy[0], size, isotropy, alpha);

        // weight functions
        vector<weights<real, difusion_tensor> > wght(frames_);
        for(int i = 0; i < frames_; i++)
           wght[i].compute(Ix[i], Iy[i], nx, ny, lambda );


        for(real t = 0; t < T; t += dt ) {

           print << t << ": ";

           for(int i = 0; i < frames_; i++) {
              warp W;
              W(I[i + 1],  u[i], v[i], Iw[i],  nx, ny);

              W(Ix[i + 1], u[i], v[i], Ixw[i], nx, ny);
              W(Iy[i + 1], u[i], v[i], Iyw[i], nx, ny);

              std::copy(&u[i][0], &u[i][size], uk[i]);
              std::copy(&v[i][0], &v[i][size], vk[i]);

              //find_lambda(ux[i], uy[i], size, isotropy, alpha);
              //wght[i].compute(ux[i], uy[i], nx, ny, lambda);
           }


           real error =  1.0;
           while ( error > ERROR ) {

            error = 0;

            for(int i = 1; i < frames_; i++) {

              //weight functions PRUEBA
              NM_AMI_MATH::gradient<real> gradient;
              gradient(u[i], ux[i], uy[i], nx, ny);
              gradient(v[i], vx[i], vy[i], nx, ny);

              warp W;
              W(u[i], u[i-1], v[i-1],  uw[i-1],  nx, ny);
              W(v[i], u[i-1], v[i-1],  vw[i-1],  nx, ny);
              W(ux[i], u[i-1], v[i-1], uwx[i-1], nx, ny);
              W(vx[i], u[i-1], v[i-1], vwx[i-1], nx, ny);
              W(uy[i], u[i-1], v[i-1], uwy[i-1], nx, ny);
              W(vy[i], u[i-1], v[i-1], vwy[i-1], nx, ny);

              phip(u[i-1], v[i-1], uw[i-1], vw[i-1], phi[i-1], nx, ny);

            }

            // aqui calculamos las inversas del flujo optico y sus warps
            real *u_1 = new real[size];
            real *v_1 = new real[size];
            for(int i = 0; i < frames_ - 1; i++) {

              inverse_optic_flow<real> inverse;
              inverse(u[i], v[i], u_1, v_1, nx, ny);

              //NM_AMI_FILE::save_uv<real>(u_1, v_1, nx, ny, ("Inversas" +AnsiString(i)+".uv").c_str());

              warp W;
              W(u[i], u_1, v_1,  uw_[i],  nx, ny);
              W(v[i], u_1, v_1,  vw_[i],  nx, ny);


              phip(u[i+1], v[i+1], uw_[i], vw_[i], phi_[i], nx, ny);

            }
            delete []u_1;
            delete []v_1;


            for(int iter = 0; iter <1; iter++) {

	        for(int i = 0; i < size; i++) {

                    pde  scheme;
                    real p;

                    for(int n = 0; n < frames_; n++)

                       p = scheme (I[n], Iw[n], Ixw[n], Iyw[n], uk[n], vk[n],
                                   uw[n], vw[n], uwx[n], vwx[n], uwy[n], vwy[n], uw_[n-1], vw_[n-1],
                                   phi[n], phi_[n-1], wght[n], u[n], v[n], dt, C, 0, i,
                                   (real) (n/(frames_-1.0)));

                    if ( p > error ) error = p;
                }

	        for(int i = size - 1; i >= 0; i--) {

                    pde  scheme;
                    real p;

                    for(int n = frames_ - 1; n >= 0 ; n--)

                       p = scheme (I[n], Iw[n], Ixw[n], Iyw[n], uk[n], vk[n],
                                   uw[n], vw[n], uwx[n], vwx[n], uwy[n], vwy[n],  uw_[n-1], vw_[n-1],
                                   phi[n], phi_[n-1], wght[n], u[n], v[n],  dt, C, 1, i,
                                   (real) (n/(frames_-1.0)));

                    if ( p > error ) error = p;
                }

                print << error << ", ";
               }
            }
            print << "\n";

        }

        borrar(Ix);
        borrar(Iy);
        borrar(Iw);
        borrar(Ixw);
        borrar(Iyw);
        borrar(uk);
        borrar(uw);
        borrar(uw_);
        borrar(ux);
        borrar(uy);
        borrar(uwx);
        borrar(uwy);
        borrar(vk);
        borrar(vw);
        borrar(vw_);
        borrar(vx);
        borrar(vy);
        borrar(vwx);
        borrar(vwy);
        borrar(Difa);
        borrar(Difb);
        borrar(Difc);
        borrar(phi);
        borrar(phi_);
    }
};


END_AMI_METHOD

#endif
