#ifndef AMICHI2_H
#define AMICHI2_H

#define NPOINTS_CHI2 9
#define MBASE_FUN 9

float basefunction(int, float, float);
float partial_x_basefunction(int, float, float);
float partial_y_basefunction(int, float, float);
float ami_vorticity_2d_chi2_9p(int, int , float **, float **, int, int);
float ami_vorticity_2d_chi2_9p_ij(int ,int , float **, float **,int , int );
void ami_free_vorticity_equation();
void ami_allocate_vorticity_equation();

#endif
