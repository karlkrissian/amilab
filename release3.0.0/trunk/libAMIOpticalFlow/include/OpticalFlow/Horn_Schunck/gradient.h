#ifndef _GRADIENT_H
#define _GRADIENT_H

#include <math.h>


#define GRADIENTR2 1.4142135623730950488
//#define GR8 2.8284271247461900976
#define GRADIENTC  .14644660940672623779  //1 / ( 4 + R8 );

// this class computes the gradient of a pixel in an Image


template <typename real>
class gradient {

    public:

        template <typename image>
        int operator () (const image &I, image &Ix, image &Iy, int nx,  int ny) {

          //gradient on the whole image
           for(int x = 0; x < nx; x++)

              for(int y = 0; y < ny; y++) {

                 int mx = x - 1;
                 int my = y - 1;
                 int dx = x + 1;
                 int dy = y + 1;

                 if(mx < 0) mx = 0;
                 if(dx >= nx) dx = nx - 1;
                 if(my < 0) my = 0;
                 if(dy >= ny) dy = ny - 1;


                 Iy[x + nx * y] = GRADIENTC * ( -I[mx + nx * my] + I[mx + nx * dy]
			                                       -I[dx + nx * my] + I[dx + nx * dy]+
			                         GRADIENTR2 * (-I[x  + nx * my] + I[x  + nx * dy]));

                 Ix[x + nx * y] = GRADIENTC * ( -I[mx + nx * my] - I[mx + nx * dy]
				                                    +I[dx + nx * my] + I[dx + nx * dy]+
                                  GRADIENTR2 * (-I[mx + nx * y ] + I[dx + nx * y ]));
              }

           return 0;
        }

};


#endif
