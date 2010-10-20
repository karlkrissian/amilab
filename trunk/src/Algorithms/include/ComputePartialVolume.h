//
// C++ Interface: ComputePartialVolume
//
// Description: Estimate the partial volume creating an image
//  between 0 and 1 (0 for negative intensity values, 1 for positive values)
//
// Author:  <Karl Krissian>, (C) 2009
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _ComputePartialVolume_h_
#define _ComputePartialVolume_h_

#include "inrimage.hpp"

//
double RecursivePositiveVolume( double val[8], double subvols[8], 
                                double volume, int subdiv_level );

//
InrImage* ComputePartialVolume(InrImage* input, int resolution=3);

//
InrImage* ComputePartialVolumeSubdiv(InrImage* input, int subdiv=2);

#endif // _ComputePartialVolume_h_
