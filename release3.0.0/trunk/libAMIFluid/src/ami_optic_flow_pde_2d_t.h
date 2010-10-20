#ifndef AMI_OPTIC_FLOW_PDE_2D_T_H
#define AMI_OPTIC_FLOW_PDE_2D_T_H

#include "ami_utilities_3d.h"

#include "ami_optic_flow_pde_param.h"

/**
 * FUNCTION TO COMPUTE A 2D OPTIC FLOW FOR A SEQUENCE OF IMAGES USING TEMPORAL SMOOTHING
 */
int ami_optic_flow_2d_t(float ***image,ami_v3f ***u,
			const PDEOpticFlowParam& param,
			int dim_x,int dim_y,int dim_t);


#endif // AMI_OPTIC_FLOW_PDE_2D_T_H

