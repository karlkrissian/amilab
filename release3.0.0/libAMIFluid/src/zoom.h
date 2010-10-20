#ifndef _ZOOM_H
#define _ZOOM_H

#include "namespace.h"


// this class computes the zoom for all the Image

BEGIN_AMI_UTIL


template<class real>
class zoom{

       template <typename image>
       real value (const image &I, int nx, int ny, int i, int j,
                   real factor) {

           if (factor <= 1.0){
               const int k =(int)((real)i/factor);
               const int l =(int)((real)j/factor);

               int mx = k - 1;
               int dx = k + 1;
               int my = l - 1;
               int dy = l + 1;

               if(mx < 0) mx = 0;
               if(dx >= nx) dx = nx - 1;
               if(my < 0) my = 0;
               if(dy >= ny) dy = ny - 1;


               return
                     0.07842776544 * (I[mx + nx * my] + I[mx + nx * dy] + I[dx + nx * my] + I[dx + nx * dy]) +

                     0.1231940459 * (I[k + nx * my] + I[mx + nx * l] + I[dx + nx * l] + I[k + nx * dy]) +

                     0.1935127547 * I[k + nx * l];
           }
           else {
                int k =  (int) ((real)i/factor);
                int l =  (int) ((real)j/factor);

                return I[k + nx * l];
          }
       }


    public:

        template <typename image>
        int operator () (const image &I, image &Iout, int nx, int ny, real factor){

            int nxx = (int)((real) nx * factor + 0.5);
            int nyy = (int)((real) ny * factor + 0.5);

            for (int i = 0; i < nxx; i++)

                for (int j = 0; j < nyy; j++)

                    Iout[i + nxx * j] = value (I, nx, ny, i, j, factor);

            return 0;
        }


        template <typename image>
        int operator () (const image &I, image &Iout, int nx, int ny, int nxx, int nyy){

            const real factor = ((real)nxx / nx);

            for (int i = 0; i < nxx; i++)

                for (int j = 0; j < nyy; j++)

                  try {
                    Iout[i + nxx * j] = value(I, nx, ny, i, j, factor);
                    }
                    catch(...){
                    }

            return 0;
        }     
};

END_AMI_UTIL


#endif
