/* Generation of 2 synthetic images of fluid motion around a sphere */


#include "ami_prototypes.h"



/*********************************************************************************
    BEGIN OF PROTOPYPES OF 3D OPTIC FLOW FUNCTIONS
**********************************************************************************/

/* FUNCTION TO GENERATE THE 3D FLOW ASSOCIATED TO AN IRROTATIONAL FLOW WITH AN SPHERE OBSTACLE */
void ami_3d_flow_sphere_obstacle_generation(float ***image_1,float ***image_2,ami_v3f center,
                 float radius,float velocity,float density,ami_v3f ***u, 
                 int dim_x,int dim_y,int dim_z, int symmetric=0);

/* FUNCTION TO GENERATE THE 3D FLOW BASED ON A DISPLACEMENT IMAGE */
void ami_3d_flow_from_displacement(float ***image_1,float ***image_2,ami_v3f*** displ,
                 float density,unsigned char*** mask,
                 int dim_x,int dim_y,int dim_z, int symmetric=0);

/*********************************************************************************
    END OF PROTOPYPES OF 3D OPTIC FLOW FUNCTIONS
**********************************************************************************/

