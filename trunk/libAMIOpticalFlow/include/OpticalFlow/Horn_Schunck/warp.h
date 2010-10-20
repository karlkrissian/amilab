#ifndef SYMMETRIC_WARP_H
#define SYMMETRIC_WARP_H

#define Neumann //Symmetric //Periodic  //Flow //

template <typename real>
class warp {

  public:

     template <class image>
     inline int operator() (const image &I, const image &u, const image &v,
                            image &Iw, const int nx, const int ny, bool plus = true) {
        if(plus)
           warp_positive(I, u, v, Iw, nx, ny);
        else
           warp_negative(I, u, v, Iw, nx, ny);
	return 1;
     }

  private:

     //I(x+h)
     template <class image>
     int warp_positive(const image &I, const image &u, const image &v,
                       image &Iw, const int nx, const int ny) {

        for(int i = 0; i < nx; i++)

           for(int j = 0; j < ny; j++) {

              const real uu = ((real) i + u[i + nx * j]);
              const real vv = ((real) j + v[i + nx * j]);
              const int xx = (int) uu;
              const int yy = (int) vv;

              const int sx = (uu < 0)? -1: 1;
              const int sy = (vv < 0)? -1: 1;

#ifdef Neumann
              int x  = neumann(xx, nx);
              int y  = neumann(yy, ny);

              int dx = neumann(xx + sx, nx);
              int dy = neumann(yy + sy, ny);
#else
#ifdef Periodic
              int x  = periodic(xx, nx);
              int y  = periodic(yy, ny);

              int dx = periodic(xx + sx, nx);
              int dy = periodic(yy + sy, ny);

#else
#ifdef Symmetric
              int x  = symmetric(xx, nx);
              int y  = symmetric(yy, ny);

              int dx = symmetric(xx + sx, nx);
              int dy = symmetric(yy + sy, ny);
#else
              int x  = flow(xx, i, nx);
              int y  = flow(yy, j, ny);

              int dx = flow(xx + sx, i, nx);
              int dy = flow(yy + sy, j, ny);
#endif
#endif
#endif

              const real p1 = I[x + nx * y];
              const real p2 = I[dx + nx * y];
              const real p3 = I[x + nx * dy];
              const real p4 = I[dx + nx * dy];

              const real e1 = ((real) sx * (uu - xx));
              const real E1 = ((real) 1.0 - e1);
              const real e2 = ((real) sy * (vv - yy));
              const real E2 = ((real) 1.0 - e2);

              const real w1 = E1 * p1 + e1 * p2;
              const real w2 = E1 * p3 + e1 * p4;

              Iw[i + nx * j] = E2 * w1 + e2 * w2;
           }

        return 0;
     }

     
     //I(x-h)
     template <class image>
     int warp_negative(const image &I, const image &u, const image &v,
                       image &Iw, const int nx, const int ny) {

        for(int i = 0; i < nx; i++)

           for(int j = 0; j < ny; j++) {

              const real uu = ((real) i - u[i + nx * j]);
              const real vv = ((real) j - v[i + nx * j]);
              const int xx = (int) uu;
              const int yy = (int) vv;

              const int sx = (uu < 0)? -1: 1;
              const int sy = (vv < 0)? -1: 1;

#ifdef Neumann
              int x  = neumann(xx, nx);
              int y  = neumann(yy, ny);

              int dx = neumann(xx + sx, nx);
              int dy = neumann(yy + sy, ny);
#else
#ifdef Periodic
              int x  = periodic(xx, nx);
              int y  = periodic(yy, ny);

              int dx = periodic(xx + sx, nx);
              int dy = periodic(yy + sy, ny);

#else
#ifdef Symmetric
              int x  = symmetric(xx, nx);
              int y  = symmetric(yy, ny);

              int dx = symmetric(xx + sx, nx);
              int dy = symmetric(yy + sy, ny);
#else
              int x  = flow(xx, i, nx);
              int y  = flow(yy, j, ny);

              int dx = flow(xx + sx, i, nx);
              int dy = flow(yy + sy, j, ny);
#endif
#endif
#endif

              const real p1 = I[x + nx * y];
              const real p2 = I[dx + nx * y];
              const real p3 = I[x + nx * dy];
              const real p4 = I[dx + nx * dy];

              const real e1 = ((real) sx * (uu - xx));
              const real E1 = ((real) 1.0 - e1);
              const real e2 = ((real) sy * (vv - yy));
              const real E2 = ((real) 1.0 - e2);

              const real w1 = E1 * p1 + e1 * p2;
              const real w2 = E1 * p3 + e1 * p4;

              Iw[i + nx * j] = E2 * w1 + e2 * w2;
           }

        return 0;
     }


     int neumann(int x, int nx) {

        if(x < 0) x = 0;
        else if (x >= nx) x = nx - 1;

        return x;
     }

     int periodic(int x, int nx) {

        if(x < 0) {
           x =  nx + x % nx -1;
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

     int flow(int x, int o, int nx) {

        if(x < 0 || x >= nx) x = o;
//        else if (x >= nx) x = nx - 1;

        return x;
     }


};

#endif
