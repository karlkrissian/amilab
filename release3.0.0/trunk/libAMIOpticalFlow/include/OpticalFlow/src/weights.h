#ifndef _WEIGHTS_H
#define _WEIGHTS_H

#include "namespace.h"


BEGIN_AMI_METHOD

template <typename real, typename DifTen>
class weights{

  // diffusion tensor
  real *Difa;
  real *Difb;
  real *Difc;

  // weight functions
  real *d1;
  real *d2;
  real *d3;
  real *d4;
  real *d5;
  real *d6;
  real *d7;
  real *d8;

  int nx, ny;

public:

  weights(): Difa(), Difb(), Difc(), d1(), d2(), d3(), d4(), d5(), d6(), d7(), d8() {}

  template<typename image>
  weights(const image &Ix, const image &Iy, int nxx, int nyy,
		    const real lambda ){

    compute(Ix, Iy, nxx, nyy, lambda);

  }

  template<typename image>
  void compute(const image &Ix, const image &Iy, int nxx, int nyy,
		    const real lambda ){

//	std::cout << " Weights ..." << "\n";
        
    nx = nxx;
    ny = nyy;
    int size = nx * ny;

    Difa = new real[size];
    Difb = new real[size];
    Difc = new real[size];
    d1 = new real[size];
    d2 = new real[size];
    d3 = new real[size];
    d4 = new real[size];
    d5 = new real[size];
    d6 = new real[size];
    d7 = new real[size];
    d8 = new real[size];

    // computing difusion tensor
    for(int i = 0; i < nx; i++)

       for(int j = 0; j < ny; j++) {

          DifTen D;

          int pos = i + nx * j;

          Difa[pos] = D.A (Ix, Iy, pos, lambda);
          Difb[pos] = D.B (Ix, Iy, pos, lambda);
          Difc[pos] = D.C (Ix, Iy, pos, lambda);
       }

    // computing weights
    for(int i = 0; i < nx; i++)

       for(int j = 0; j < ny; j++) {

          const int pos = i + nx * j;
          const int dx = (i+1 >= nx)? 0: 1;
          const int mx = (i-1 < 0)? 0: -1;
          const int dy = (j+1 >= ny)? 0: nx;
          const int my = (j-1 < 0)? 0: -nx;

          const real apz = Difa[pos + dx] ;
          const real amz = Difa[pos + mx];
          const real azz = Difa[pos];

          const real czp = Difc[pos + dy];
          const real czm = Difc[pos + my];
          const real czz = Difc[pos];

          const real bmm = Difb[pos + mx + my];
          const real bpm = Difb[pos + dx + my];
          const real bmp = Difb[pos + mx + dy];
          const real bpp = Difb[pos + dx + dy];
          const real bzz = Difb[pos];

          d1[pos] =  0.50 * (apz+azz);
          d2[pos] =  0.50 * (amz+azz);
          d3[pos] =  0.50 * (czp+czz);
          d4[pos] =  0.50 * (czm+czz);
          d5[pos] =  0.25 * (bpp+bzz);
          d6[pos] =  0.25 * (bmm+bzz);
          d7[pos] = -0.25 * (bpm+bzz);
          d8[pos] = -0.25 * (bmp+bzz);
    }
  }

  ~weights() {
    delete []Difa;
    delete []Difb;
    delete []Difc;
    delete []d1;
    delete []d2;
    delete []d3;
    delete []d4;
    delete []d5;
    delete []d6;
    delete []d7;
    delete []d8;
  }



  real Mm(const int pos) const {

    return (d1[pos] + d2[pos] + d3[pos] + d4[pos] +
	         d5[pos] + d6[pos] + d7[pos] + d8[pos]);

  }

  template<typename image>
  int divergence(const image &u, image &div, const int nx, const int ny) {

    for(int i = 0; i < nx; i++)

       for(int j = 0; j < ny; j++) {

          const int pos = i + nx * j;
          const int dx = (i+1 >= nx)? 0: 1;
          const int mx = (i-1 < 0)? 0: -1;
          const int dy = (j+1 >= ny)? 0: nx;
          const int my = (j-1 < 0)? 0: -nx;

          div[pos] = (d6[pos] * u[pos + mx + my] + d4[pos] * u[pos + my] + d7[pos] * u[pos + dx + my] +
                      d2[pos] * u[pos + mx]+                               d1[pos] * u[pos + dx]      +
                      d8[pos] * u[pos + mx + dy] + d3[pos] * u[pos + dy] + d5[pos] * u[pos + dx + dy]);
       }

    return 0;
  }


  template<typename image>
  real operator () ( const image &u, int pos)
    const {

    int j = pos / nx;
    int i = pos - j * nx;

    const int dx = (i+1 >= nx)? 0: 1;
    const int mx = (i-1 < 0)? 0: -1;
    const int dy = (j+1 >= ny)? 0: nx;
    const int my = (j-1 < 0)? 0: -nx;

    return (d6[pos] * u[pos + mx + my] + d4[pos] * u[pos + my] + d7[pos] * u[pos + dx + my] +
            d2[pos] * u[pos + mx]+                               d1[pos] * u[pos + dx]      +
            d8[pos] * u[pos + mx + dy] + d3[pos] * u[pos + dy] + d5[pos] * u[pos + dx + dy]);
  }
};


END_AMI_METHOD

#endif

