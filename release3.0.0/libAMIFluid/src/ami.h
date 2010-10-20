#ifndef AMI_H
#define AMI_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ami_abs(x) ((x)>0?(x):(-(x)))


#define ami_malloc1d(direccion,tipo,size) {direccion=(tipo *) malloc(sizeof(tipo)*(size));}





/* FUNCION QUE LEE UN VECTOR Y DEVUELVE LA DIMENSION */ 
int ami_leer_vector(char name[100],double **v);


int ami_escribir_vector(char name[100], int dimension, double *v);


#endif
