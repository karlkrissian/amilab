#ifndef _OPTIC_SCHEME_VIDEO_H
#define _OPTIC_SCHEME_VIDEO_H

#include "src/namespace.h"

BEGIN_AMI_METHOD

template <typename real>
class optic_scheme_video {

    public:

        template <typename image, typename weights>
        real operator() ( const image &i1,    const image &i2w,
                          const image &i2xw,  const image &i2yw,
                          const image &ukk,   const image &vkk,
                          const image &uw,    const image &vw,
                          const image &uwx,   const image &vwx,
                          const image &uwy,   const image &vwy,
                          const image &phi,   const weights &wght,
                          image &u, image &v,
                          const real dt,   const real C, bool reverse,
                          int i, bool ultimoframe = 0) {

            const real i2x  = i2xw[i];
            const real i2y  = i2yw[i];

            const real Mm   = wght.Mm(i);
            const real Mu   = wght(u, i);
            const real Mv   = wght(v, i); 

            const real Diff = i1[i] - i2w[i];

            const real u_k  = ukk[i];
            const real v_k  = vkk[i];
            const real uk   = u  [i];
            const real vk   = v  [i];

            const real Fuk = Diff + i2x * u_k + i2y * v_k;
            const real Fvk = Diff + i2x * u_k + i2y * v_k;

            //parte temporal
            real TNu = 0, TNv = 0, TDu = 0, TDv = 0;
               /*
            if(!ultimoframe) {
               //const real _uwx = 1 - uwx[i];
               const real _vwx = 1 - vwx[i];
               const real _uwy = 1 - uwy[i];
               const real _vwy = 1 - vwy[i];
               const real _uwx2 = _uwx * _uwx;
               const real _vwy2 = _vwy * _vwy;
               const real nu = uw[i] - u_k * uwx[i] - vk * uwy[i];
               const real nv = vw[i] - u_k * vwx[i] - vk * vwy[i];
                                                       
               TNu = phi[i] * ((nu + v[i] * uwy[i]) * _uwx +
                               (nv + v[i] * _vwy  ) * vwx[i]);
                     //phi[i] * (uw[i] - u[i]);//
               TNv = phi[i] * ((nv + u[i] * vwx[i]) * _vwy +
                               (nu - u[i] * _uwx  ) * uwy[i]);
                     //phi[i] * (vw[i] - v[i]); //

               TDu = phi[i] * (_uwx2 - vwx[i] * vwx[i]);
               TDv = phi[i] * (_vwy2 - uwy[i] * uwy[i]);
            }
                 */
            if(!ultimoframe) {
               const real _uwx = 1 - uwx[i];
               const real _vwy = 1 - vwy[i];
               TDu = phi[i] * _uwx;
               TNu = -phi[i] * (-uw[i] * _uwx + (v[i] - vw[i]) * vwx[i]);
               TDv = phi[i] * _vwy;
               TNv = -phi[i] * (-vw[i] * _vwy + (u[i] - uw[i]) * uwy[i]);
             }




            if ( reverse ) {

                const real Av = Mv + C * i2y * ( Fvk - u[i]  * i2x ) + TNv;
                const real Bv = Mm + C * i2y * i2y + TDv;

                v[i] = (v_k + dt * Av ) / ( 1 + dt * Bv );

                const real Au = Mu + C * i2x * ( Fuk - v[i] * i2y ) + TNu;
                const real Bu = Mm + C * i2x * i2x + TDu;

                u[i] = (u_k + dt * Au ) / ( 1 + dt * Bu );
            }
            else {

                const real Au = Mu + C * i2x * ( Fuk - v[i] * i2y ) + TNu;
                const real Bu = Mm + C * i2x * i2x + TDu;

                u[i] = (u_k + dt * Au ) / ( 1 + dt * Bu );

                const real Av = Mv + C * i2y * ( Fvk - u[i] * i2x ) + TNv;
                const real Bv = Mm + C * i2y * i2y + TDv;

                v[i] = (v_k + dt * Av ) / ( 1 + dt * Bv );

            }

	         return ( (u[i] - uk) * (u[i] - uk) +
		               (v[i] - vk) * (v[i] - vk) );
        }

};

END_AMI_METHOD

#endif


// ***************************************************************************
// ***************************************************************************
// ***************************************************************************
// ***************************************************************************
// ***************************************************************************
// ***************************************************************************


#if (0)

        template <typename image, typename weights>
        real operator() ( const image &i11,    const image &i22w,
                          const image &i22xw,  const image &i22yw,
                          const image &ukk,   const image &vkk,
                          const image &uw,    const image &vw,
                          const image &uwx,   const image &vwx,
                          const image &uwy,   const image &vwy,
                          const image &phi,   const weights &wght,
                          image &u, image &v,
                          const real dt,   const real C, bool reverse,
                          int i, bool ultimoframe = 0) {

/*
        real operator() ( const std::vector<image> &i1,    const std::vector<image> &i2w,
                         const std::vector<image> &i2xw,  const std::vector<image> &i2yw,
                         const image &ukk,   const image &vkk,

			 const weights &wght,
                         image &u, image &v,
                         const real dt,   const real C, const std::vector<real> &p,
			 bool reverse,    int i, bool ultimoframe = 0) {
*/

// Codigo adaptacion

        std::vector<real> p(4);
	p[0]= 1.0;	    p[1]= 0.0;	    p[2]= 0.0;	    p[3]= 0.0;

	std::vector<image> i1(1), i2w(1), i2xw(1), i2yw(1);
	i1[0]=i11;
	i2w[0]=i22w;
	i2xw[0]=i22xw;
	i2yw[0]=i22yw;

// .................

	    const int nc = i1.size();

            const real u_k  = ukk[i];
            const real v_k  = vkk[i];
            const real uk   = u  [i];
            const real vk   = v  [i];

         // ........

            real I2xw2 = 0.0, I2yw2 = 0.0;
	    real Diff_I2xw = 0.0, Diff_I2yw = 0.0;
	    real u_I2xyw = 0.0, v_I2xyw = 0.0;

	    for (int k=0; k<nc; k++)  {

		I2xw2 += p[k] * i2xw[k][i] * i2xw[k][i];
		I2yw2 += p[k] * i2yw[k][i] * i2yw[k][i];

		Diff_I2xw += p[k] * ( i1[k][i] - i2w[k][i] + i2xw[k][i] * u_k + i2yw[k][i] * v_k ) * i2xw[k][i];
		Diff_I2yw += p[k] * ( i1[k][i] - i2w[k][i] + i2xw[k][i] * u_k + i2yw[k][i] * v_k ) * i2yw[k][i];

		u_I2xyw += p[k] * i2xw[k][i] * i2yw[k][i] * u[i];
		v_I2xyw += p[k] * i2xw[k][i] * i2yw[k][i] * v[i];
	    }

         // ........

//            const real Mm   = wght[0].Mm(i);
//            const real Mu   = wght[0](u, i);
//            const real Mv   = wght[0](v, i); 

            const real Mm   = wght.Mm(i);
            const real Mu   = wght(u, i);
            const real Mv   = wght(v, i);


            //parte temporal (suprimida en esta version del metodo)
            real TNu = 0, TNv = 0, TDu = 0, TDv = 0;

         // ........

#if (1)
	  // C = 1/alpha;

            if ( reverse ) {

                const real Av =  Mv + C * ( Diff_I2yw - u_I2xyw ) +  TNv;
                const real Bv =  Mm + C * I2yw2  + TDv;

                v[i] = (v_k + dt * Av ) / ( 1 + dt * Bv );

// .............
	        v_I2xyw = 0.0;
	        for (int k=0; k<nc; k++)    v_I2xyw += p[k] * i2xw[k][i] * i2yw[k][i] * v[i];
// .............

                const real Au = Mu + C * ( Diff_I2xw - v_I2xyw ) + TNu;
                const real Bu = Mm + C * I2xw2  + TDu;

                u[i] = (u_k + dt * Au ) / ( 1 + dt * Bu );
            }
            else {

                const real Au = Mu + C * ( Diff_I2xw - v_I2xyw ) + TNu;
                const real Bu = Mm + C * I2xw2  + TDu;

                u[i] = (u_k + dt * Au ) / ( 1 + dt * Bu );

// .............
	        u_I2xyw = 0.0;
	        for (int k=0; k<nc; k++)    u_I2xyw += p[k] * i2xw[k][i] * i2yw[k][i] * u[i];
// .............

                const real Av =  Mv + C * ( Diff_I2yw - u_I2xyw ) +  TNv;
                const real Bv =  Mm + C * I2yw2  + TDv;

                v[i] = (v_k + dt * Av ) / ( 1 + dt * Bv );

            }


	         return ( (u[i] - uk) * (u[i] - uk) +
		          (v[i] - vk) * (v[i] - vk) );
#endif

        }

#endif
