#ifndef _INVERSE_OPTIC_FLOW_3D_H
#define _INVERSE_OPTIC_FLOW_3D_H

//#include "src/namespace.h"
#include <vector>
#include <algorithm>
#include  <numeric>
#include  <functional>


//BEGIN_AMI_METHOD

#define OCCLUSION 9999


template <class real>
class inverse_optic_flow_3d {

    template <class image>
    void fill_hole(image &utmp, image &u, int i, int j, int k, int nx, int ny, int nz) {

        //rellenamos el agujero por una media de los vecinos que no sean oclusi�
        int ii[3];
        int jj[3];
        int kk[3];

        int nxy=nx*ny;
        int j1=j*nx;
        int k1=k*nxy;

        ii[0] = (i == 0)? 0: i-1;
        ii[1] = i;
        ii[2] = (i == nx-1)? nx-1: i+1;
        
        jj[0] = (j == 0)? 0: j1-nx;
        jj[1] = j1;
        jj[2] = (j == ny-1)? (ny-1)*ny: j1+nx;
        
        kk[0] = (k == 0)? 0: k1-nxy;
        kk[1] = k1;
        kk[2] = (k == nz-1)? (nz-1)*nxy: k1+nxy;


        real average = 0;
        int nvalores = 0;
        real val;

#define CHECK_OCCLUSION(a,b,c)        \
      val = u[ii[a] + jj[b] + kk[c]]; \
      if(val != OCCLUSION) {          \
         average += val;              \
         nvalores++;                  \
      }
      

        CHECK_OCCLUSION(0,0,0)
        CHECK_OCCLUSION(0,0,1)
        CHECK_OCCLUSION(0,0,2)
        CHECK_OCCLUSION(0,1,0)
        CHECK_OCCLUSION(0,1,1)
        CHECK_OCCLUSION(0,1,2)
        CHECK_OCCLUSION(0,2,0)
        CHECK_OCCLUSION(0,2,1)
        CHECK_OCCLUSION(0,2,2)
        CHECK_OCCLUSION(1,0,0)
        CHECK_OCCLUSION(1,0,1)
        CHECK_OCCLUSION(1,0,2)
        CHECK_OCCLUSION(1,1,0)
        // CHECK_OCCLUSION(1,1,1)
        CHECK_OCCLUSION(1,1,2)
        CHECK_OCCLUSION(1,2,0)
        CHECK_OCCLUSION(1,2,1)
        CHECK_OCCLUSION(1,2,2)
        CHECK_OCCLUSION(2,0,0)
        CHECK_OCCLUSION(2,0,1)
        CHECK_OCCLUSION(2,0,2)
        CHECK_OCCLUSION(2,1,0)
        CHECK_OCCLUSION(2,1,1)
        CHECK_OCCLUSION(2,1,2)
        CHECK_OCCLUSION(2,2,0)
        CHECK_OCCLUSION(2,2,1)
        CHECK_OCCLUSION(2,2,2)

        if(nvalores > 0)
            utmp[i+j1+k1] = average / nvalores;

    }

    template <class image>
    void fill_holes(image &u, int nx, int ny, int nz) {

        bool occlusion = true;
        int size = nx * ny * nz;
        real *utmp = new float[size];
        int pos;

        while(occlusion) {
            occlusion = false;
            pos = 0;
            for(int k = 0; k < nz; k++)
                for(int j = 0; j < ny; j++) 
                    for(int i = 0; i < nx; i++) {
                        utmp[pos] = u[pos];
                        if(u[pos] == OCCLUSION) {
                            occlusion = true;
                            fill_hole(utmp, u, i, j, k, nx, ny, nz);
                        }
                        pos++;
                    }
            copy(&utmp[0], &utmp[size], &u[0]);
        }
        delete [] utmp;
    }


    template <class image>
    void compute_inverse(const image &u, const image &v, const image& w,
                         image &u_, image &v_, image &w_,
                         int nx, int ny, int nz, int fillholes=1) {

        int size = nx * ny * nz;

        real *uu_   = new real[size];
        real *vv_   = new real[size];
        real *ww_   = new real[size];
        real *peso_ = new real[size];
        
        for(int i = 0; i < size; i++) peso_[i]=0.0;

        //en este bucle vamos metiendo la parte proporcional correspondiente
        //en cada punto de la inversa (al final se calcula una media)
        for(int i = 0; i < nx; i++) {
        printf("i=%d \t",i); fflush(stdout);
            for(int j = 0; j < ny; j++) {
                for(int k = 0; k < nz; k++) {

                    //warpeamos el flujo
                    const real du = u[i + nx * (j+ny*k)];
                    const real dv = v[i + nx * (j+ny*k)];
                    const real dw = w[i + nx * (j+ny*k)];

                    const real uu = (real) (i - du);
                    const real vv = (real) (j - dv);
                    const real ww = (real) (k - dw);

                    const int sx = (uu < 0)? -1: 1;
                    const int sy = (vv < 0)? -1: 1;
                    const int sz = (ww < 0)? -1: 1;

                    int x  = (int) uu;
                    int y  = (int) vv;
                    int z  = (int) ww;

                    int dx = x + sx;
                    int dy = y + sy;
                    int dz = z + sz;

                    if(x < 0)
                        x = 0;
                    else if (x >= nx)
                        x = nx - 1;
                    if(y < 0)
                        y = 0;
                    else if (y >= ny)
                        y = ny - 1;
                    if(z < 0)
                        z = 0;
                    else if (z >= nz)
                        z = nz - 1;

                    if(dx < 0)
                        dx = 0;
                    else if (dx >= nx)
                        dx = nx - 1;
                    if(dy < 0)
                        dy = 0;
                    else if (dy >= ny)
                        dy = ny - 1;
                    if(dz < 0)
                        dz = 0;
                    else if (dz >= nz)
                        dz = nz - 1;

                    int nxy=nx *ny;
                    int py =nx *y;
                    int pdy=nx *dy;
                    int pz =nxy*z;
                    int pdz=nxy*dz;

                    const int pos1 = x  + py  + pz;
                    const int pos2 = dx + py  + pz;
                    const int pos3 = x  + pdy + pz;
                    const int pos4 = dx + pdy + pz;

                    const int pos5 = x  + py  + pdz;
                    const int pos6 = dx + py  + pdz;
                    const int pos7 = x  + pdy + pdz;
                    const int pos8 = dx + pdy + pdz;

                    const real e1 = ((real) sx * (uu - x));
                    const real E1 = ((real) 1.0 - e1);
                    const real e2 = ((real) sy * (vv - y));
                    const real E2 = ((real) 1.0 - e2);
                    const real e3 = ((real) sz * (ww - z));
                    const real E3 = ((real) 1.0 - e3);


                    //metemos en los cuatro puntos la proporcion correspondiente
                    const real peso1 = E1 * E2 * E3;
                    const real peso2 = e1 * E2 * E3;
                    const real peso3 = E1 * e2 * E3;
                    const real peso4 = e1 * e2 * E3;
                    const real peso5 = E1 * E2 * e3;
                    const real peso6 = e1 * E2 * e3;
                    const real peso7 = E1 * e2 * e3;
                    const real peso8 = e1 * e2 * e3;

                    real du2=du+du;
                    uu_[pos1] += du2 * peso1;
                    uu_[pos2] += du2 * peso2;
                    uu_[pos3] += du2 * peso3;
                    uu_[pos4] += du2 * peso4;
                    uu_[pos5] += du2 * peso5;
                    uu_[pos6] += du2 * peso6;
                    uu_[pos7] += du2 * peso7;
                    uu_[pos8] += du2 * peso8;

                    real dv2=dv+dv;
                    vv_[pos1] += dv2 * peso1;
                    vv_[pos2] += dv2 * peso2;
                    vv_[pos3] += dv2 * peso3;
                    vv_[pos4] += dv2 * peso4;
                    vv_[pos5] += dv2 * peso5;
                    vv_[pos6] += dv2 * peso6;
                    vv_[pos7] += dv2 * peso7;
                    vv_[pos8] += dv2 * peso8;

                    real dw2=dw+dw;
                    ww_[pos1] += dw2 * peso1;
                    ww_[pos2] += dw2 * peso2;
                    ww_[pos3] += dw2 * peso3;
                    ww_[pos4] += dw2 * peso4;
                    ww_[pos5] += dw2 * peso5;
                    ww_[pos6] += dw2 * peso6;
                    ww_[pos7] += dw2 * peso7;
                    ww_[pos8] += dw2 * peso8;

                    peso_[pos1] += peso1;
                    peso_[pos2] += peso2;
                    peso_[pos3] += peso3;
                    peso_[pos4] += peso4;
                    peso_[pos5] += peso5;
                    peso_[pos6] += peso6;
                    peso_[pos7] += peso7;
                    peso_[pos8] += peso8;
                } // k
            } // j
        } // i

       printf("Computing mean values \n");

        //calculamos la media para cada posicion de todos los valores que han
        //caido en el punto
        for(int i = 0; i < size; i++) {

            //La forma de seleccionar el valor es un poco peligroso:
            //  Si fuera una aplicaci� biyectiva --> no problem con calcular suma
            //  C�culo del m�imo tampoco es lo correcto
            //  Calcular una media no es adecuado, puesto que influyen menos unos que otros
            // Calculamos la suma, pero habr�que refinar

            //en peso se mete una ponderaci� de los flujos que van a dar a un punto
            if(peso_[i]>0) {
                u_[i] = (real) uu_[i]/peso_[i];
                v_[i] = (real) vv_[i]/peso_[i];
                w_[i] = (real) ww_[i]/peso_[i];
                }
            else {
                u_[i] = OCCLUSION;    //esto es una oclusion
                v_[i] = OCCLUSION;    
                w_[i] = OCCLUSION;    
                }

        }

        delete []uu_;
        delete []vv_;
        delete []ww_;
        delete []peso_;


        printf("filling holes? \n");
        if (fillholes) {
            //rellenamos los posibles huecos que hayan podido quedar
            fill_holes(u_,nx, ny, nz);
            fill_holes(v_,nx, ny, nz);
            fill_holes(w_,nx, ny, nz);
        }

        printf("OK\n");
    }


public:

    template <class image>
    int operator()(const image &u, const image &v, const image & w,
                   image &u_, image &v_, image &w_,
                   int nx, int ny, int nz,  int fillholes=0) {

        compute_inverse(u, v, w, u_, v_, w_, nx, ny,nz,fillholes);
        return 0;
    }

};


//END_AMI_METHOD

#endif
