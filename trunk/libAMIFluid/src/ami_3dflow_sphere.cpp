/* THIS PROGRAM COMPUTES 3D OPTIC FLOW IN VOLUMES USING THE BASIC HORN-SHUNCK METHOD WITH PYRAMIDAL APPROACH */
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <fstream>
#include <stddef.h>
#include <fcntl.h>
#include <math.h>


#include "ami_3dflow_sphere.hpp"

using namespace std;

/*
*/
void ami_draw_sphere( float cx, float cy, float cz, float radius, 
                      int dim_x, int dim_y, int dim_z, float*** image,
                      int color, int background_color )
{
  
//  printf("ami_draw_sphere \n");
  float r2 = radius*radius;
  float r2_in  = (radius-0.5*sqrt(3.))*(radius-0.5*sqrt(3.));
  float r2_out = (radius+0.5*sqrt(3.))*(radius+0.5*sqrt(3.));

  for(int i=(int)(cx-radius);i<=cx+radius;i++) {
    for(int j=(int)(cy-radius);j<=cy+radius;j++)
      for(int k=(int)(cz-radius);k<=cz+radius;k++)
      {
        float d2 = (i-cx)*(i-cx)+(j-cy)*(j-cy)+(k-cz)*(k-cz);
	if (d2<r2_out)
          if(i>=0 && i<dim_x && j>=0 && j<dim_y && k>=0 && k<dim_z)
        {
          if (d2<r2_in)
            image[i][j][k]=color;
          else {
            // implement partial volume effect
            int nsub = 7; // number of subdivisions along each direction
            float step=1.0/nsub;
            float px,py,pz,px2,py2,pz2;
            int n=0;
            for (px=i-0.5+step/2; px<i+0.5; px+=step) {
              px2=(px-cx)*(px-cx);
              for (py=j-0.5+step/2; py<j+0.5; py+=step) {
                py2= (py-cy)*(py-cy);
                for (pz=k-0.5+step/2; pz<k+0.5; pz+=step) {
                  pz2=(pz-cz)*(pz-cz); 
                  if (px2+py2+pz2<r2) n++;
                }
              }
            }
            image[i][j][k] = background_color+
                (color-background_color)*1.0*n/(nsub*nsub*nsub);
          }
        }
      }
      }

//  printf("ami_draw_sphere end\n");
} // ami_draw_sphere()


/***********************************************************************************************/
/* FUNCTION TO GENERATE THE 3D FLOW ASSOCIATED TO AN IRROTATIONAL FLOW WITH AN SPHERE OBSTACLE */
void ami_3d_flow_sphere_obstacle_generation(
    float ***image_1, /* volumen 1 generated (output data) */
    float ***image_2, /* volumen 2 generated (output data) */
    ami_v3f center, /* CENTER OF THE SPHERE */
    float radius,/* RADIUS OF THE SPHERE */
    float velocity, /* velocidad del flujo en el eje x */
    float density, // number of spheres per voxel (much lower than 1)
    ami_v3f ***u,/* FLOW GENERATED (OUTPUT DATA */
    int dim_x,int dim_y,int dim_z, /*IMAGE DIMENSION */
    int symmetric) /* generate the image in a symmetric way */
{
    int background_color = 0;
    int   sphere_color=17;

    // We generate the flow and the background of image_1 and image_2
    for(int i=0; i<dim_x; i++)
        for(int j=0; j<dim_y; j++)
            for(int k=0; k<dim_z; k++)
            {
                float x = i-center[0], y = j-center[1], z = k-center[2];
                float r = sqrt((double) x*x+y*y+z*z);

                if(r <= radius)
                {
                    for(int l=0;l<3;l++)
                        u[i][j][k][l]=0;
                }
                else
                {
                    //u[i][j][k][0] = velocity*((3*(x*y*y+x*z*z))/(4*radius*r*r*r) - (3*(radius*x*y*y+radius*x*z*z))/(4*r*r*r*r*r));
                    //u[i][j][k][1] = velocity*(y/(radius*radius) - (3*y)/(2*radius*r) + (radius*y)/(2*r*r*r) + (3*(y*y*y+y*z*z))/(4*radius*r*r*r) - (3*radius*(y*y*y+y*z*z))/(4*r*r*r*r*r));
                    //u[i][j][k][2] = velocity*(z/(radius*radius) - (3*z)/(2*radius*r) + (radius*z)/(2*r*r*r) + (3*(z*z*z+y*y*z))/(4*radius*r*r*r) - (3*radius*(z*z*z+y*y*z))/(4*r*r*r*r*r));
                    u[i][j][k][0] = velocity*(1 - (3*radius)*(2*x*x+y*y+z*z)/(4*r*r*r) + (radius*radius*radius)*(2*x*x-y*y-z*z)/(4*r*r*r*r*r));
                    u[i][j][k][1] = velocity*(-(3*radius*x*y)/(4*r*r*r) + (3*radius*radius*radius*x*y)/(4*r*r*r*r*r));
                    u[i][j][k][2] = velocity*(-(3*radius*x*z)/(4*r*r*r) + (3*radius*radius*radius*x*z)/(4*r*r*r*r*r));
                }
                image_1[i][j][k]=background_color; //BACKGROUND
                image_2[i][j][k]=background_color; //BACKGROUND
            }

    // WE DRAW THE SPHERE:

    ami_draw_sphere(center[0],center[1],center[2],radius,
                    dim_x,dim_y,dim_z,image_1,sphere_color,background_color);
    
    ami_draw_sphere(center[0],center[1],center[2],radius,
                    dim_x,dim_y,dim_z,image_2,sphere_color,background_color);
    /*
    for(int i=(int)(center[0]-radius);i<=center[0]+radius;i++)
        for(int j=(int)(center[1]-radius);j<=center[1]+radius;j++)
            for(int k=(int)(center[2]-radius);k<=center[2]+radius;k++)
            {
                float norm = (i-center[0])*(i-center[0])+(j-center[1])*(j-center[1])+(k-center[2])*(k-center[2]);
                if(sqrt(norm)<=radius && i>=0 && i<dim_x && j>=0 && j<dim_y && k>=0 && k<dim_z)
                {
                    image_2[i][j][k]=sphere_color;
                    //printf("punto de esfera\n");
                }

            }
    */
    
    // WE DEFINE PARTICLES WITHOUT INTERCEPTION
    int n_cercle = (int) (1.0*(dim_x*dim_y*dim_z-3./4.*PI*radius*radius*radius)*density);
    int l=0;
    do
    {
        ami_v3f c_cercle;
        int m = 1;
        float minradius=0.75;
        float maxradius=2;
        float r_cercle = minradius+(maxradius-minradius)*((double) rand()/RAND_MAX);
        c_cercle[0] = (((double) rand()/RAND_MAX)*dim_x);
        c_cercle[1] = (((double) rand()/RAND_MAX)*dim_y);
        c_cercle[2] = (((double) rand()/RAND_MAX)*dim_z);
        int xmin=(int)(c_cercle[0]-r_cercle);
        int xmax=(int)(c_cercle[0]+r_cercle);
        int ymin=(int)(c_cercle[1]-r_cercle);
        int ymax=(int)(c_cercle[1]+r_cercle);
        int zmin=(int)(c_cercle[2]-r_cercle);
        int zmax=(int)(c_cercle[2]+r_cercle);
        
        if (xmin<0) xmin=0;
        if (ymin<0) ymin=0;
        if (zmin<0) zmin=0;
        if (xmax>dim_x-1) xmax=dim_x-1;
        if (ymax>dim_y-1) ymax=dim_y-1;
        if (zmax>dim_z-1) zmax=dim_z-1;
        
        float x = c_cercle[0]-center[0];
        float y = c_cercle[1]-center[1];
        float z = c_cercle[2]-center[2];
        float r = sqrt((double) x*x+y*y+z*z);
        float dx=0.0,dy=0.0,dz=0.0;

        if(r >= radius)
        {
            dx = velocity*(1 - (3*radius)*(2*x*x+y*y+z*z)/(4*r*r*r) +       (radius*radius*radius)*(2*x*x-y*y-z*z)/(4*r*r*r*r*r));
            dy = velocity*(-(3*radius*x*y)/(4*r*r*r) + (3*radius*radius*radius*x*y)/(4*r*r*r*r*r));
            dz = velocity*(-(3*radius*x*z)/(4*r*r*r) +  (3*radius*radius*radius*x*z)/(4*r*r*r*r*r));
        }

        for(int i=xmin;i<=xmax;i++)
            for(int j=ymin;j<=ymax;j++)
                for(int k=zmin;k<=zmax;k++)
                   if(image_1[i][j][k]!=background_color) 
                   {
                     m=0;
                     k=zmax+1;j=ymax+1;i=xmax+1;
                   }
        if (m == 1)
        {
            int color_cercle = (int) (background_color + (255-background_color)*((double) rand()/RAND_MAX));
            l++;
            if (l%100==0)
                printf("number of spheres %d \n",l);
            
            if (!symmetric) {
                ami_draw_sphere(c_cercle[0],c_cercle[1],c_cercle[2],r_cercle,
                                dim_x,dim_y,dim_z,image_1,color_cercle,background_color);
                // draw displaced sphere in image 1
                ami_draw_sphere(c_cercle[0]+dx,c_cercle[1]+dy,c_cercle[2]+dz,r_cercle,
                                dim_x,dim_y,dim_z,image_2,color_cercle,background_color);
            }
            else {
                ami_draw_sphere(c_cercle[0]-dx/2,c_cercle[1]-dy/2,c_cercle[2]-dz/2,r_cercle,
                                dim_x,dim_y,dim_z,image_1,color_cercle,background_color);
                // draw displaced sphere in image 1
                ami_draw_sphere(c_cercle[0]+dx/2,c_cercle[1]+dy/2,c_cercle[2]+dz/2,r_cercle,
                                dim_x,dim_y,dim_z,image_2,color_cercle,background_color);
            }
                /*
            for(int i=(int)(c_cercle[0]-r_cercle);i<=c_cercle[0]+r_cercle;i++)
            {
                for(int j=(int)(c_cercle[1]-r_cercle);j<=c_cercle[1]+r_cercle;j++)
                {
                    for(int k=(int)(c_cercle[2]-r_cercle);k<=c_cercle[2]+r_cercle;k++)
                    {
                        float norm = (i-c_cercle[0])*(i-c_cercle[0])+(j-c_cercle[1])*(j-c_cercle[1])+(k-c_cercle[2])*(k-c_cercle[2]);
                        if(sqrt(norm)<=r_cercle && i>=0 && i<dim_x && j>=0 && j<dim_y && k>=0 && k<dim_z)
                            image_2[i][j][k]=color_cercle;
                    }
                }
            }
            */
        }
    }
    while (l<n_cercle);
    // WE APPLY A CONVOLUTION TO FILTER THE VOLUME
    //float beta_2[3] = {0.,0.,0.};
    //ami_convolution_3d(image_2,beta_2,dim_x,dim_y,dim_z);

    // WE DEFINE image_1 BY WARPING image_2
   // ami_image_interpolation_3df(image_2,u,image_1,dim_x,dim_y,dim_z);
}



/***********************************************************************************************/
/* FUNCTION TO GENERATE THE 3D FLOW BASED ON A DISPLACEMENT IMAGE 
*/
void ami_3d_flow_from_displacement(float ***image_1,float ***image_2,
                 ami_v3f*** displ,
                 float density,
                 unsigned char*** mask, // mask image: 255 solid object (no particles) 0: air (particles) 
                 int dim_x,int dim_y,int dim_z, 
                 int symmetric)
{
    int background_color = 0;

    // We initialize the flow to 0 and the 2 images to the background intensity
    for(int i=0; i<dim_x; i++)
        for(int j=0; j<dim_y; j++)
            for(int k=0; k<dim_z; k++)
            {
                image_1[i][j][k]=background_color; //BACKGROUND
                image_2[i][j][k]=background_color; //BACKGROUND
            }

    // WE DEFINE PARTICLES WITHOUT INTERCEPTION
    int n_cercle = (int) (1.0*dim_x*dim_y*dim_z*density);
    int l=0;
    do
    {
        ami_v3f c_cercle;
        float minradius=0.75;
        float maxradius=2;
        float r_cercle = minradius+(maxradius-minradius)*((double) rand()/RAND_MAX);
        c_cercle[0] = (((double) rand()/RAND_MAX)*dim_x);
        c_cercle[1] = (((double) rand()/RAND_MAX)*dim_y);
        c_cercle[2] = (((double) rand()/RAND_MAX)*dim_z);
        int xmin=(int)(c_cercle[0]-r_cercle);
        int xmax=(int)(c_cercle[0]+r_cercle);
        int ymin=(int)(c_cercle[1]-r_cercle);
        int ymax=(int)(c_cercle[1]+r_cercle);
        int zmin=(int)(c_cercle[2]-r_cercle);
        int zmax=(int)(c_cercle[2]+r_cercle);
        
        if (xmin<0) xmin=0;
        if (ymin<0) ymin=0;
        if (zmin<0) zmin=0;
        if (xmax>dim_x-1) xmax=dim_x-1;
        if (ymax>dim_y-1) ymax=dim_y-1;
        if (zmax>dim_z-1) zmax=dim_z-1;
        
        int x0 = (int) c_cercle[0];
        int x1 = (int) c_cercle[1];
        int x2 = (int) c_cercle[2];
        ami_v3f d,dx;
        dx[0] = c_cercle[0]-x0; 
        dx[1] = c_cercle[1]-x1;
        dx[2] = c_cercle[2]-x2;

        // interpolate value of displ at (x,y,z)
        ami_point_interpolation_v3f(displ,x0,x1,x2,dx,d,dim_x,dim_y,dim_z);

        int m = 1;
        // check that the particule is in the air
        for(int i=xmin;i<=xmax;i++)
            for(int j=ymin;j<=ymax;j++)
                for(int k=zmin;k<=zmax;k++)
                   if(mask[i][j][k]!=0) 
                   {
                     m=0;
                     k=zmax+1;j=ymax+1;i=xmax+1;
                   }
        if (m == 1)
        {
            int color_cercle = (int)  (background_color+(255.0-background_color)*((double) rand()/RAND_MAX));
            l++;
            if (l%1000==0)
                printf("number of spheres %d / %d \n",l,n_cercle);
            
            if (!symmetric) {
                ami_draw_sphere(c_cercle[0],c_cercle[1],c_cercle[2],r_cercle,
                                dim_x,dim_y,dim_z,image_1,color_cercle,background_color);
                // draw displaced sphere in image 1
                ami_draw_sphere(c_cercle[0]+d[0],c_cercle[1]+d[1],c_cercle[2]+d[2],r_cercle,
                                dim_x,dim_y,dim_z,image_2,color_cercle,background_color);
            }
            else {
                ami_draw_sphere(c_cercle[0]-d[0]/2.0,c_cercle[1]-d[1]/2.0,c_cercle[2]-d[2]/2.0,
                                r_cercle,
                                dim_x,dim_y,dim_z,image_1,color_cercle,background_color);
                // draw displaced sphere in image 1
                ami_draw_sphere(c_cercle[0]+d[0]/2.0,c_cercle[1]+d[1]/2.0,c_cercle[2]+d[2]/2.0,
                                r_cercle,
                                dim_x,dim_y,dim_z,image_2,color_cercle,background_color);
            }
        }
    }
    while (l<n_cercle);
} // ami_3d_flow_from_displacement()
