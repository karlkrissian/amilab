#ifndef _GRADIENT_H
#define _GRADIENT_H

#include "namespace.h"
#include <math.h>


#define GRADIENTR2 1.4142135623730950488
//#define GR8 2.8284271247461900976
#define GRADIENTC  .14644660940672623779  //1 / ( 4 + R8 );

// this class computes the gradient of a pixel in an Image
//

BEGIN_AMI_MATH


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

/*   ESTA FORMA ES MAS RAPIDA, PERO HAY QUE REVISARLO BIEN
           //gradient on the whole image
           for(int x = 1; x < nx - 1; x++)

              for(int y = 1; y < ny - 1; y++) {

                 const int mx = x - 1;
                 const int my = y - 1;
                 const int dx = x + 1;
                 const int dy = y + 1;

                 Iy[x + nx * y] = GRADIENTC * ( -I[mx + nx * my] + I[mx + nx * dy]
			                                       -I[dx + nx * my] + I[dx + nx * dy]+
			                         GRADIENTR2 * (-I[x  + nx * my] + I[x  + nx * dy]));

                 Ix[x + nx * y] = GRADIENTC * ( -I[mx + nx * my] - I[mx + nx * dy]
				                                    +I[dx + nx * my] + I[dx + nx * dy]+
                                  GRADIENTR2 * (-I[mx + nx * y ] + I[dx + nx * y ]));
              }

           //gradient on the first columns
           for(int y = 1; y < ny - 1; y++) {

              const int my = y - 1;
              const int dx = 1;
              const int dy = y + 1;

              Iy[nx * y] = GRADIENTC * ( -I[nx * my] + I[nx * dy]
                                         -I[dx + nx * my] + I[dx + nx * dy]+
                           GRADIENTR2 * (-I[nx * my] + I[nx * dy]));

              Ix[nx * y] = GRADIENTC * ( -I[nx * my] - I[nx * dy]
			                                +I[dx + nx * my] + I[dx + nx * dy]+
                           GRADIENTR2 * (-I[nx * y ] + I[dx + nx * y ]));
           }

           //gradient on the last column
           for(int y = 1; y < ny - 1; y++) {

              const int mx = nx - 2;
              const int my = y - 1;
              const int dx = nx - 1;
              const int dy = y + 1;

              Iy[nx - 1 + nx * y] = GRADIENTC * ( -I[mx + nx * my] + I[mx + nx * dy]
			                                         -I[dx + nx * my] + I[dx + nx * dy]+
			                           GRADIENTR2 * (-I[dx + nx * my] + I[dx + nx * dy]));

              Ix[nx - 1 + nx * y] = GRADIENTC * ( -I[mx + nx * my] - I[mx + nx * dy]
				                                      +I[dx + nx * my] + I[dx + nx * dy]+
                                    GRADIENTR2 * (-I[mx + nx * y ] + I[dx + nx * y ]));
            }

           //gradient on the first row
           for(int x = 1; x < nx - 1; x++){

              const int mx = x - 1;
              const int my = 0;
              const int dx = x + 1;
              const int dy = 1;

              Iy[x] = GRADIENTC * ( -I[mx] + I[mx + nx]
			                           -I[dx] + I[dx + nx]+
			             GRADIENTR2 * (-I[x ] + I[x  + nx]));

              Ix[x] = GRADIENTC * ( -I[mx] - I[mx + nx]
				                        +I[dx] + I[dx + nx]+
                      GRADIENTR2 * (-I[mx] + I[dx ]));
           }

          //gradient on the last row
           for(int x = 1; x < nx - 1; x++) {

              const int y  = ny - 1;
              const int mx = x - 1;
              const int my = y - 1;
              const int dx = x + 1;
              const int dy = y;

              Iy[x + nx * y] = GRADIENTC * ( -I[mx + nx * my] + I[mx + nx * dy]
			                                    -I[dx + nx * my] + I[dx + nx * dy]+
			                      GRADIENTR2 * (-I[x  + nx * my] + I[x  + nx * dy]));

              Ix[x + nx * y] = GRADIENTC * ( -I[mx + nx * my] - I[mx + nx * dy]
				                                 +I[dx + nx * my] + I[dx + nx * dy]+
                               GRADIENTR2 * (-I[mx + nx * y ] + I[dx + nx * y ]));
           }

           //gradient at the corners
           Iy[0] = GRADIENTC * ( -I[0] + I[nx]
                                 -I[1] + I[1 + nx]+
                   GRADIENTR2 * (-I[0] + I[1]));

           Ix[0] = GRADIENTC * ( -I[0] - I[nx]
                                 +I[1] + I[1 + nx]+
                   GRADIENTR2 * (-I[0] + I[1]));


           Iy[nx-1] = GRADIENTC * ( -I[nx - 2] + I[2 * nx - 2]
                                    -I[nx - 1] + I[2 * nx - 1]+
                      GRADIENTR2 * (-I[nx - 1] + I[2 * nx - 1]));

           Ix[nx-1] = GRADIENTC * ( -I[nx - 2] - I[2 * nx - 2]
                                    +I[nx - 1] + I[2 * nx - 1]+
                      GRADIENTR2 * (-I[nx - 2] + I[nx - 1]));


           Iy[nx * ny - nx] = GRADIENTC * ( -I[nx * (ny - 2)] + I[nx * ny - nx]
			                                 -I[nx * (ny - 2) + 1] + I[nx * ny - nx + 1]+
			                   GRADIENTR2 * (-I[nx * (ny - 2)] + I[nx * (ny - 2)]));

           Ix[nx * ny - nx] = GRADIENTC * ( -I[nx * (ny - 2)] - I[nx * ny - nx]
			                                 +I[nx * (ny - 2) + 1] + I[nx * ny - nx + 1]+
                            GRADIENTR2 * (-I[nx * ny - nx] + I[nx * ny - nx + 1]));


           Iy[nx * ny - 1] = GRADIENTC * ( -I[nx * (ny - 1) - 2] + I[nx * nx - 2]
			                                  -I[nx * (ny - 1) - 1] + I[nx * ny - 1]+
			                    GRADIENTR2 * (-I[nx * (ny - 1) - 1] + I[nx * ny - 1]));

           Ix[nx * ny - 1] = GRADIENTC * ( -I[nx * (ny - 1) - 2] - I[nx * nx - 2]
			                                  +I[nx * (ny - 1) - 1] + I[nx * ny - 1]+
                             GRADIENTR2 * (-I[nx * ny - 2] + I[nx * ny - 1]));
                         */
           return 0;
        }


// 5%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%5
// 5%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%5
// 5%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%5
// 5%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%5

        template <typename image>
        int temporal (const image &I_1, /*const image &I,*/ const image &I1, image &It, int nx,  int ny) {

          // temporal gradient on the whole image
           for(int x = 0; x < nx; x++)

              for(int y = 0; y < ny; y++) {

                 int my = y - 1;
                 int dy = y + 1;

                 if(my < 0) my = 0;
                 if(dy >= ny) dy = ny - 1;


                 It[x + nx * y] = GRADIENTC * ( -I_1[ x + nx * my] - I_1[x + nx * dy]
			                                       +I1[x + nx * my] + I1[x + nx * dy] +
			                         GRADIENTR2 * (-I_1[x  + nx * y] + I1[x  + nx * y] ) );

              }

           return 0;
        }

};


END_AMI_MATH

#endif

/*
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
*/
