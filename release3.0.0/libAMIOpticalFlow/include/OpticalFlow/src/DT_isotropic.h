#ifndef _DT_ISOTROPIC_H
#define _DT_ISOTROPIC_H

#include "namespace.h"

BEGIN_AMI_METHOD

template <typename real>
class DT_isotropic {

    public:

        inline const  real Phi1(const real DI2, const real Lambda = 0) const{

            return 1;
        }


        inline const  real Phi2(const real DI2, const real Lambda = 0) const{

            return 1;
        }


};

END_AMI_METHOD

#endif
