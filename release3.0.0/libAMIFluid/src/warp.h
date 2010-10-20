#ifndef WARP_H
#define WARP_H

#include "namespace.h"

BEGIN_AMI_UTIL

#define Neumann //Symmetric //Periodic  //

template <typename real>
class warp {

     int neumann(int x, int nx) {

        if(x < 0) x = 0;
        else if (x >= nx) x = nx - 1;

        return x;
     }

     int periodic(int x, int nx) {

        if(x < 0) {
           const int n   = 1 - (int)(x/(nx+1));
           const int ixx = x + n * nx;

           x =   ixx% nx;
        }
        else if(x >= nx) {
           x = x % nx;
        }

        return x;

     }


     int symmetric(int x, int nx) {
        if(x < 0) {
           const int borde = nx - 1;
           const int xx = -x;
           const int n  = (int)(xx/borde) % 2;

           if ( n ) x = borde - ( xx % borde );
           else x = xx % borde;
        }
        else if ( x >= nx ) {
           const int borde = nx - 1;
           const int n = (int)(x/borde) % 2;

           if ( n ) x = borde - ( x % borde );
           else x = x % borde;
        }

        return x;
     }

  public:

     template <class image>
     int operator() (const image &I, const image &u, const image &v,
                     image &Iw, const int nx, const int ny ) {


        for(int i = 0; i < nx; i++)

           for(int j = 0; j < ny; j++) {

              const real uu = (real) (i + u[i + nx * j]);
              const real vv = (real) (j + v[i + nx * j]);

              const int sx = (uu < 0)? -1: 1;
              const int sy = (vv < 0)? -1: 1;

#ifdef Neumann
              int x  = neumann((int) uu, nx);
              int y  = neumann((int) vv, ny);

              int dx = neumann(x + sx, nx);
              int dy = neumann(y + sy, ny);
#else
#ifdef Periodic
              int x  = periodic((int) uu, nx);
              int y  = periodic((int) vv, ny);

              int dx = periodic(x + sx, nx);
              int dy = periodic(y + sy, ny);

#else
#ifdef Symmetric
              int x  = symmetric((int) uu, nx);
              int y  = symmetric((int) vv, ny);

              int dx = symmetric(x + sx, nx);
              int dy = symmetric(y + sy, ny);
#endif
#endif
#endif

              const real p1 = I[x + nx * y];
              const real p2 = I[dx + nx * y];
              const real p3 = I[x + nx * dy];
              const real p4 = I[dx + nx * dy];

              const real e1 = ((real) sx * (uu - x));
              const real E1 = ((real) 1.0 - e1);
              const real e2 = ((real) sy * (vv - y));
              const real E2 = ((real) 1.0 - e2);

              const real w1 = E1 * p1 + e1 * p2;
              const real w2 = E1 * p3 + e1 * p4;

              Iw[i + nx * j] = E2 * w1 + e2 * w2;
           }

        return 0;
     }
};

END_AMI_UTIL

#endif
