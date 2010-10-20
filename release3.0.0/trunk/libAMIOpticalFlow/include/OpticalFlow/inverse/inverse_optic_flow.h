#ifndef _INVERSE_OPTIC_FLOW_H
#define _INVERSE_OPTIC_FLOW_H

#include "src/namespace.h"
#include <vector>
#include <algorithm>
#include <numeric>

#ifndef WIN32
//#include <algo.h>
#endif

BEGIN_AMI_METHOD

#define OCLUSION 9999

template<class real>
real norm2_comp(real v, real u){
   return v * v < u * u;
}

template <class real>
class inverse_optic_flow {

   template <class image>
   void fill_hole(image &utmp, image &u, int i, int j, int nx, int ny) {

      //rellenamos el agujero por una media de los vecinos que no sean oclusin
      const int im = (i == 0)? 0: i-1;
      const int id = (i == nx-1)? nx-1: i+1;
      const int jm = (j == 0)? 0: j-1;
      const int jd = (j == ny-1)? ny-1: j+1;

      const real mm = u[im + nx * jm];
      const real m_ = u[im + nx * j ];
      const real md = u[im + nx * jd];
      const real _m = u[i  + nx * jm];
      const real _d = u[i  + nx * jd];
      const real dm = u[id + nx * jm];
      const real d_ = u[id + nx * j ];
      const real dd = u[id + nx * jd];

      real average = 0;
      int nvalores = 0;

      if(mm * mm < OCLUSION){
         average += mm;
         nvalores++;
      }
      if(m_ * m_ < OCLUSION){
         average += m_;
         nvalores++;
      }
      if(md * md < OCLUSION){
         average += md;
         nvalores++;
      }
      if(_m * _m < OCLUSION){
         average += _m;
         nvalores++;
      }
      if(_d * _d < OCLUSION){
         average += _d;
         nvalores++;
      }
      if(dm * dm < OCLUSION){
         average += dm;
         nvalores++;
      }
      if(d_ * d_ < OCLUSION){
         average += d_;
         nvalores++;
      }
      if(dd * dd < OCLUSION){
         average += dd;
         nvalores++;
      }

      if(nvalores > 0)

          utmp[i + nx * j] = average / nvalores;

   }

   template <class image>
   void fill_holes(image &u, int nx, int ny) {

      bool oclusion = true;
      int size = nx * ny;
      real *utmp = new float[size];

      while(oclusion) {

         oclusion = false;

         for(int i = 0; i < nx; i++)

            for(int j = 0; j < ny; j++) {

               utmp[i + nx * j] = u[i + nx * j];

               if(u[i + nx * j] == OCLUSION) {

                  oclusion = true;

                  fill_hole(utmp, u, i, j, nx, ny);
              }
            }

         copy(&utmp[0], &utmp[size], &u[0]);
      }
      delete utmp;
   }


   template <class image>
   void compute_inverse(const image &u, const image &v, image &u_, image &v_,
                        int nx, int ny) {

      int size = nx * ny;

      std::vector<real> *uu_ = new std::vector<real> [size];
      std::vector<real> *vv_ = new std::vector<real> [size];
      std::vector<real> *peso_ = new std::vector<real> [size];

      //en este bucle vamos metiendo la parte proporcional correspondiente
      //en cada punto de la inversa (al final se calcula una media)
      for(int i = 0; i < nx; i++)

         for(int j = 0; j < ny; j++) {

              //warpeamos el flujo
              const real du = u[i + nx * j];
              const real dv = v[i + nx * j];

              const real uu = (real) (i + du);
              const real vv = (real) (j + dv);

              const int sx = (uu < 0)? -1: 1;
              const int sy = (vv < 0)? -1: 1;

              int x  = (int) uu;
              int y  = (int) vv;

              int dx = x + sx;
              int dy = y + sy;

              if(x < 0) x = 0;
              else if (x >= nx) x = nx - 1;
              if(y < 0) y = 0;
              else if (y >= ny) y = ny - 1;

              if(dx < 0) dx = 0;
              else if (dx >= nx) dx = nx - 1;
              if(dy < 0) dy = 0;
              else if (dy >= ny) dy = ny - 1;

              //if(x >= 0 && x < nx && y > 0 && y < ny &&
                // dx >= 0 && dx < nx && dy >= 0 && dy < ny) {

                 const int pos1 = x + nx * y;
                 const int pos2 = dx + nx * y;
                 const int pos3 = x + nx * dy;
                 const int pos4 = dx + nx * dy;

                 const real e1 = ((real) sx * (uu - x));
                 const real E1 = ((real) 1.0 - e1);
                 const real e2 = ((real) sy * (vv - y));
                 const real E2 = ((real) 1.0 - e2);


                 //metemos en los cuatro puntos la proporcion correspondiente
                 const real peso1 = E1 * E2;
                 const real peso2 = e1 * E2;
                 const real peso3 = E1 * e2;
                 const real peso4 = e1 * e2;

                 uu_[pos1].push_back(-du * peso1);
                 uu_[pos2].push_back(-du * peso2);
                 uu_[pos3].push_back(-du * peso3);
                 uu_[pos4].push_back(-du * peso4);

                 vv_[pos1].push_back(-dv * peso1);
                 vv_[pos2].push_back(-dv * peso2);
                 vv_[pos3].push_back(-dv * peso3);
                 vv_[pos4].push_back(-dv * peso4);

                 peso_[pos1].push_back(peso1);
                 peso_[pos2].push_back(peso2);
                 peso_[pos3].push_back(peso3);
                 peso_[pos4].push_back(peso4);
              //}
         }

      //calculamos la media para cada posicion de todos los valores que han
      //caido en el punto
      for(int i = 0; i < size; i++) {

         //La forma de seleccionar el valor es un poco peligroso:
         //  Si fuera una aplicacin biyectiva --> no problem con calcular suma
         //  C�culo del m�imo tampoco es lo correcto
         //  Calcular una media no es adecuado, puesto que influyen menos unos que otros
         // Calculamos la suma, pero habr�que refinar

         //en peso se mete una ponderacin de los flujos que van a dar a un punto
         real peso = 0;
         if(!peso_[i].empty())
           peso = (real) std::accumulate(peso_[i].begin(), peso_[i].end(), 0.0);

         if(!uu_[i].empty() && peso > 0.0)
            u_[i] = (real) std::accumulate(uu_[i].begin(), uu_[i].end(), 0.0) / peso;
         else
            u_[i] = OCLUSION;    //esto es una oclusin

         if(!vv_[i].empty() && peso > 0.0)
            v_[i] = (real) std::accumulate(vv_[i].begin(), vv_[i].end(), 0.0) / peso;
         else
            v_[i] = OCLUSION;    //esto es una oclusin
      }

      delete []uu_;
      delete []vv_;
      delete []peso_;

      //rellenamos los posibles huecos que hayan podido quedar
      fill_holes(u_,nx, ny);
      fill_holes(v_,nx, ny);

   }


public:

   template <class image>
   int operator()(const image &u, const image &v, image &u_, image &v_,
                  int nx, int ny) {

      compute_inverse(u, v, u_, v_, nx, ny);
      return 0;
   }

};


END_AMI_METHOD

#endif
