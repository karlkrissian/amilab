#ifndef _DT_PERONA_MALIK_H
#define _DT_PERONA_MALIK_H

#include <math.h>

#include "namespace.h"

BEGIN_AMI_METHOD

template <typename real>
class DT_perona_malik {

    protected:

        inline const  real Phi1(const real DI2, const real k = 1) const {


            return (real) exp((double)(-DI2/(16*k*k)));

        }

        inline const  real Phi2(const real DI2, const real k = 1) const {


            return (real) exp((double)(-DI2/(16*k*k)));

        }


};

END_AMI_METHOD


#endif
