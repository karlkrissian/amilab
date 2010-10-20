
#include "ami.h"

int ami_leer_vector(char name[100],double **v)
{
 int i,nss; 
  FILE *f; 
  if(f=fopen( name, "r"),!f){
    printf("Problema con la apertura del fichero\n");
    return(-1); 
  } 
  fscanf(f,"%d\n",&nss); 
  if(nss<0){ 
    printf("Error de Dimension\n"); 
    return(-1); 
  } 
  *v=(double*)malloc(sizeof(double)*nss);
  for(i=0;i<nss;i++) fscanf(f,"%lf\n",&((*v)[i])); 
  fclose(f); 
  return(nss); 
}

int ami_escribir_vector(char name[100], int dimension, double *v) 
{ 
  int i; 
  FILE *f; 
  if(f=fopen(name, "w"),!f){
    printf("Problema con la escritura del fichero\n");
    return(-1); 
  } 
  fprintf(f,"%d\n",dimension);
  for(i=0;i<dimension;i++) fprintf(f,"%lf\n",v[i]); 
  fclose(f); 
  return 0; 
} 
