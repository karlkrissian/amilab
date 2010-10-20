#ifndef AMI_OPTIC_FLOW_PDE_3D_H
#define AMI_OPTIC_FLOW_PDE_3D_H

#include "ami_utilities_3d.h"

#include "ami_optic_flow_pde_param.h"


void ami_matriz_vector_3d(ami_m3x3f A, double x[3], ami_v3f v);
void ami_matriz_vector_2d(ami_m3x3f* A, double* x, ami_v3f v);

/**
 * FUNCTION TO COMPUTE A 3D OPTIC FLOW USING THE HORN_SHUNCK METHOD          
 */
int ami_horn_schunck_optic_flow_3d(float ***image_1,float ***image_2,ami_v3f ***u,
				   const PDEOpticFlowParam& param, 
				   int dim_x,int dim_y,int dim_z);
/**
 * FUNCTION TO COMPUTE A 3D OPTIC FLOW with incompressibility constraint          
 */
int ami_incrompressible_optical_flow_3d(float ***image_1,float ***image_2,ami_v3f ***u,
				   const PDEOpticFlowParam& param, 
				   int dim_x,int dim_y,int dim_z);

/**
 * FUNCTION TO COMPUTE A 3D(or 2D) OPTIC FLOW USING THE HORN_SHUNCK METHOD WITH EXPLICIT SCHEME
 */
int ami_horn_schunck_optic_flow_explicit(float ***image_1,float ***image_2,ami_v3f ***u,
					 ami_v3f alfa, float total_time, float dt,
					 int dim_x,int dim_y,int dim_z , const PDEOpticFlowParam& param );




#endif

