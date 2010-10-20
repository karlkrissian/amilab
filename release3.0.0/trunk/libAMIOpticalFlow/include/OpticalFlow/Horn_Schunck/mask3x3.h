#ifndef _MASK3x3_H
#define _MASK3x3_H

// this class applies a mask to an Image


template <typename real>
class mask3x3 {

    public:

        template <typename image>
        int operator () (const image &in, image &out, int nx,  int ny,
                         const real m[3][3]) {

          //gradient on the whole image
           for(int x = 0; x < nx; x++)

              for(int y = 0; y < ny; y++) {

                 int mx = x - 1;
                 int my = y - 1;
                 int dx = x + 1;
                 int dy = y + 1;

                 if(mx < 0)   mx = 0;
                 if(dx >= nx) dx = nx - 1;
                 if(my < 0)   my = 0;
                 if(dy >= ny) dy = ny - 1;

                 out[x + y *nx] = m[0][0] * in[mx + my * nx] +
                                  m[0][1] * in[ x + my * nx] +
                                  m[0][2] * in[dx + my * nx] +
                                  m[1][0] * in[mx +  y * nx] +
                                  m[1][1] * in[ x +  y * nx] +
                                  m[1][2] * in[dx +  y * nx] +
                                  m[2][0] * in[mx + dy * nx] +
                                  m[2][1] * in[ x + dy * nx] +
                                  m[2][2] * in[dx + dy * nx];

              }

           return 0;
        }


};


#endif
