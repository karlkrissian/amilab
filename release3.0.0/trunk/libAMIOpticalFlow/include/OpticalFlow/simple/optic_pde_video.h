#ifndef _OPTIC_PDE_H
#define _OPTIC_PDE_H

#include <list>
#include "src/namespace.h"

#include <exception>
#include <iostream>
#include <math.h>

#include "optic_scheme_video.h"
#include "src/gradient.h"
#include "src/weights.h"
#include "src/warp.h"


#define ERROR 0.01

#define LINEAR 0
#define NON_LINEAR 1



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

        //si las imagenes son de una tonalidad --> maxima prioridad a regularizacion
        if(maxgrad >= 0.000000000001)
           C  = 1/ (alpha * maxgrad);
        else
           C = 999999999.9;

	     std::cout << "Lambda: " << lambda << std::endl;
	     std::cout << "C: " << C;
    }


    template <class image>
    void crear(std::vector<image> &I, int size) {

       for( typename std::vector<image>::iterator i = I.begin(); i != I.end(); i++)

          (*i) = new real[size];
    }

    template <class image>
    void borrar(std::vector<image> &I) {

       for( typename std::vector<image>::iterator i = I.begin(); i != I.end(); i++)

          delete [](*i);
    }


  public:


    template <typename image, class out>
    void operator () ( const std::vector<image> &I, std::vector<image> &u,
                       std::vector<image> &v, int nx, int ny,
                       const real T, const real dt,
                       const real alpha, const real betaa, const real gamm,
                       const real isotropy, out &print = std::cout) {

        int size = nx * ny;
        int frames = I.size();
        int frames_ = frames - 1;
        beta = betaa;
        gamma = gamm;

        // general functions of StereoFlow
        std::vector<real *> Ix(frames);
        std::vector<real *> Iy(frames);
        std::vector<real *> Iw(frames_); 
        std::vector<real *> Ixw(frames_);
        std::vector<real *> Iyw(frames_);
        std::vector<real *> uk(frames_);
        std::vector<real *> ux(frames_);
        std::vector<real *> uy(frames_);
        std::vector<real *> uw(frames_-1);
        std::vector<real *> uwx(frames_-1);
        std::vector<real *> uwy(frames_-1);
        std::vector<real *> vk(frames_);
        std::vector<real *> vx(frames_);
        std::vector<real *> vy(frames_);
        std::vector<real *> vw(frames_-1);
        std::vector<real *> vwx(frames_-1);
        std::vector<real *> vwy(frames_-1);
        std::vector<real *> Difa(frames_);
        std::vector<real *> Difb(frames_);
        std::vector<real *> Difc(frames_);
        std::vector<real *> phi(frames_);

        crear(Ix, size);
        crear(Iy, size);
        crear(Iw, size);
        crear(Ixw, size);
        crear(Iyw, size);
        crear(uk, size);
        crear(uw, size);
        crear(ux, size);
        crear(uy, size);
        crear(uwx, size);
        crear(uwy, size);
        crear(vk, size);
        crear(vw, size);
        crear(vx, size);
        crear(vy, size);
        crear(vwx, size);
        crear(vwy, size);
        crear(Difa, size);
        crear(Difb, size);
        crear(Difc, size);
        crear(phi, size);

        // computing the gradient of I1 and I2
        for(int i = 0; i < frames; i++) {
           NM_AMI_MATH::gradient<real> gradient;
           gradient(I[i], Ix[i], Iy[i], nx, ny);
        }

        find_lambda(Ix[0], Iy[0], size, isotropy, alpha);

        // weight functions
        std::vector<weights<real, difusion_tensor> > wght(frames_);
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

              //weight functions PRUEBA
              NM_AMI_MATH::gradient<real> gradient;
              gradient(u[i], ux[i], uy[i], nx, ny);
  	           gradient(v[i], vx[i], vy[i], nx, ny);

  	           //find_lambda(ux[i], uy[i], size, isotropy, alpha);
              //wght[i].compute(ux[i], uy[i], nx, ny, lambda);
           }
           for(int i = 1; i < frames_; i++) {
              warp W;
              W(u[i], u[i-1], v[i-1],  uw[i-1],  nx, ny);
              //if(nx >90) {
              //print << u[i-1] << nx << ny;
              //print << uw[i-1] << nx << ny;
              //}
              W(v[i], u[i-1], v[i-1],  vw[i-1],  nx, ny);
              W(ux[i], u[i-1], v[i-1], uwx[i-1], nx, ny);
              W(vx[i], u[i-1], v[i-1], vwx[i-1], nx, ny);
              W(uy[i], u[i-1], v[i-1], uwy[i-1], nx, ny);
              W(vy[i], u[i-1], v[i-1], vwy[i-1], nx, ny);

              phip(u[i-1], v[i-1], uw[i-1], vw[i-1], phi[i-1], nx, ny);

           }

           real error =  1.0;
           while ( error > ERROR ) {

                error = 0;

	             for(int i = 0; i < size; i++) {

                    pde  scheme;
                    real p=0.0;

                    for(int n = 0; n < frames_; n++)

                       p = scheme (I[n], Iw[n], Ixw[n], Iyw[n], uk[n], vk[n],
                                   uw[n], vw[n], uwx[n], vwx[n], uwy[n], vwy[n],
                                   phi[n], wght[n], u[n], v[n], dt, C, 0, i, ((frames_-1) - n) == 0);

                    if ( p > error ) error = p;
                }

	             for(int i = size - 1; i >= 0; i--) {

                    pde  scheme;
                    real p=0.0;

                    for(int n = 0; n < frames_; n++)

                       p = scheme (I[n], Iw[n], Ixw[n], Iyw[n], uk[n], vk[n],
                                   uw[n], vw[n], uwx[n], vwx[n], uwy[n], vwy[n],
                                   phi[n], wght[n], u[n], v[n],  dt, C, 1, i, ((frames_-1) - n) == 0);

                    if ( p > error ) error = p;
                }
                print << error << ", ";
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
        borrar(ux);
        borrar(uy);
        borrar(uwx);
        borrar(uwy);
        borrar(vk);
        borrar(vw);
        borrar(vx);
        borrar(vy);
        borrar(vwx);
        borrar(vwy);
        borrar(Difa);
        borrar(Difb);
        borrar(Difc);
        borrar(phi);
    }
};


END_AMI_METHOD

#endif
