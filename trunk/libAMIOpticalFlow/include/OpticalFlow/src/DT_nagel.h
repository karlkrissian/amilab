#ifndef _NAGELENKELMANNDIFUSIONTENSOR_
#define _NAGELENKELMANNDIFUSIONTENSOR_

#include "difusion_tensor.h"


#define TOPMIN 0.0001

BEGIN_AMI_METHOD

    template <typename real>
    class DT_nagel {


    public:

        template <class T>
        inline const  real A (const T &Ix, const T &Iy, const int pos,
                              const real lambda = 0) {

            const real lambda2 = lambda * lambda;

            const real I2x = Ix[pos] * Ix[pos];
	         const real I2y = Iy[pos] * Iy[pos];
	         const real N2  = I2x + I2y + 2 * lambda2;

	         return (I2y + lambda2) / N2;

        }

        template <class T>
        inline const  real B (const T &Ix, const T &Iy, const int pos,
                              const real lambda = 0) {

            const real lambda2 = lambda * lambda;

            const real I2x = Ix[pos] * Ix[pos];
	         const real I2y = Iy[pos] * Iy[pos];
	         const real N2  = I2x + I2y + 2 * lambda2;

	         return -Ix[pos] * Iy[pos] / N2;
        }

        template <class T>
        inline const  real C (const T &Ix, const T &Iy, const int pos,
                              const real lambda = 0) const {

            const real lambda2 = lambda * lambda;

            const real I2x = Ix[pos] * Ix[pos];
	         const real I2y = Iy[pos] * Iy[pos];
	         const real N2  = I2x + I2y + 2 * lambda2;


	         return (I2x + lambda2) / N2;

        }



    };

END_AMI_METHOD

#endif
