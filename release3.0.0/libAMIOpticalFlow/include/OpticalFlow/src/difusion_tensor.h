#ifndef _DIFUSION_TENSOR_H
#define _DIFUSION_TENSOR_H

#include "namespace.h"

// ESTA ES UNA CLASE GENERAL DE DIFUSION TENSOR
//
// LA FORMULA DEL TENSOR ES LA SIGUIENTE:
//
// ( Phi1 I2y + Phi2 I2x      -Ix Iy (Phi1 - Phi2))
// ( -Ix Iy (Phi1 - Phi2)     Phi1 I2x + Phi2 I2y )/(I2x + I2y)
//
// Las clases que sean padre de esta, tienen que definir las Phi1 y Phi2
// de acuerdo al criterio que sigan.
//
// Las clases ancestras tienen que empezar por "DT"



BEGIN_AMI_METHOD

#define MINVALUE 0.0001

template <typename real, typename TensorType>
class difusion_tensor: public TensorType{

protected:

    inline const real Phi1(const real DI2, const real lambda = 0) const{

        return TensorType::Phi1(DI2, lambda);

    }


    inline const real Phi2(const real DI2, const real lambda = 0) const{

        return TensorType::Phi2(DI2, lambda);

    }



public:

    template <class image>
    inline const  real A (const image &Ix, const image &Iy, const int pos, const real lambda = 0) const {


      const real I2x = Ix[pos] * Ix[pos];
      const real I2y = Iy[pos] * Iy[pos];
      const real N2  = I2x + I2y;

      if (N2 <MINVALUE) return 1;
      else
	      return (Phi1(N2, lambda) * I2y +
		           Phi2(N2, lambda) * I2x)/ N2;

    }

    template <class T>
    inline const  real B (const T &Ix, const T &Iy, const int pos, const real lambda = 0) const {

      const real I2x = Ix[pos] * Ix[pos];
      const real I2y = Iy[pos] * Iy[pos];
      const real N2  = I2x + I2y;

        if (N2 <MINVALUE) return 0;
        else
            return -Ix[pos] * Iy[pos] * (Phi1(N2, lambda) -
                               Phi2(N2, lambda))/ N2;

    }

    template <class T>
    inline const  real C (const T &Ix, const T &Iy, const int pos, const real lambda = 0) const {

      const real I2x = Ix[pos] * Ix[pos];
      const real I2y = Iy[pos] * Iy[pos];
      const real N2  = I2x + I2y;

      if (N2 <MINVALUE) return 1;
      else
	      return (Phi1(N2, lambda) * I2x +
		           Phi2(N2, lambda) * I2y)/ N2;

    }

};

END_AMI_METHOD

#endif
