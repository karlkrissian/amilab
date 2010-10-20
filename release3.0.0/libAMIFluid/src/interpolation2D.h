#ifndef _INTERPOLATION2D_
#define _INTERPOLATION2D_


#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#define MAXITER 1000
#define TOL 0.00000001

template <typename real>
real F(real x, real y, real *c)
{
 real result;
 result=c[0]+
	c[1]*x+
	c[2]*y+
	c[3]*x*y+
	c[4]*x*x+
	c[5]*y*y+
	c[6]*x*x*y+
	c[7]*x*y*y+
	c[8]*x*x*y*y;
 return(result);
}

/* CALCULAR VECTOR DE COEFICIENTES c[9] A PARTIR DE LOS VALORES DE LA 
CORRELACION DADOS EN EL VECTOR Co[9] (9 VALORES QUE RECORREN LA VECINDAD
DEL PUNTO DE IZQUIERDA A DERECHA Y DE ABAJO A ARRIBA  	*/
template <typename real>
void CalculoCoeficientes(real *Co,real *c)
{
  
 c[0]=Co[4];
 c[1]=-0.5*Co[3]+0.5*Co[5];
 c[2]=-0.5*Co[1]+0.5*Co[7];
 c[3]=0.25*Co[0]-0.25*Co[2]-0.25*Co[6]+0.25*Co[8];
 c[4]=0.5*Co[3]-Co[4]+0.5*Co[5];
 c[5]=0.5*Co[1]-Co[4]+0.5*Co[7];
 c[6]=-0.25*Co[0]+0.5*Co[1]-0.25*Co[2]+0.25*Co[6]-0.5*Co[7]+0.25*Co[8];
 c[7]=-0.25*Co[0]+0.25*Co[2]+0.5*Co[3]-0.5*Co[5]-0.25*Co[6]+0.25*Co[8];
 c[8]=0.25*Co[0]-0.5*Co[1]+0.25*Co[2]-0.5*Co[3]+Co[4]-0.5*Co[5]+0.25*Co[6]+
      -0.5*Co[7]+0.25*Co[8];

}

/* CALCULO DE LA MATRIZ HESSIANA */
template <typename real>
void HF(real x, real y, real *c, real (*H)[2])
{
  H[0][0]=2*c[4]+2*c[6]*y+2*c[8]*y*y;
  H[0][1]=H[1][0]=c[3]+2*c[6]*x+2*c[7]*y+4*c[8]*x*y;
  H[1][1]=2*c[5]+2*c[7]*x+2*c[8]*x*x;

}

/* RESUELVO SISTEMA CON EL HESSIANO. DEVUELVE 0 SI HA TERMINADO CORRECTAMENTE */
template <typename real>
int ResolverSistema(real (*H)[2], real *b, real *sol)
{
  real det=H[0][0]*H[1][1]-H[0][1]*H[1][0];
  if(det==0) return(-1);
  sol[0]=(b[0]*H[1][1]-b[1]*H[0][1])/det;
  sol[1]=(b[1]*H[0][0]-b[0]*H[1][0])/det;
  return(0);
}

/* CALCULO DEL GRADIENTE DE LA FUNCION  F(x,y) */
template <typename real>
void Grad(real x, real y, real *c, real *G)
{
  G[0]=c[1]+c[3]*y+2*c[4]*x+2*c[6]*x*y+c[7]*y*y+2*c[8]*x*y*y;
  G[1]=c[2]+c[3]*x+2*c[5]*y+c[6]*x*x+2*c[7]*x*y+2*c[8]*x*x*y;
}

/* CALCULO EL MAXIMO POR EL METODO DE NEWTON. DEVUELVO -1 SI TERMINO
   INCORRECTAMENTE. SI NO DEVUELVO EL NUMERO DE ITERACIONES  */
template <typename real>
int Newton(real *Co, real *sol)
{
  real G[2],b[2],H[2][2],c[9];
  int i;
  sol[0]=sol[1]=0;
  CalculoCoeficientes(Co,c);
  for(i=0;i<MAXITER;i++){
    Grad(sol[0],sol[1],c,G);
    if( (G[0]*G[0]+G[1]*G[1])<TOL ){
        if(sol[0]>1 || sol[0]<-1 || sol[1]>1 || sol[1]<-1) return(-1);
        return(i);
      }
    HF(sol[0],sol[1],c,H);
    if(  ResolverSistema(H,G,b)==-1) return(-1);
    sol[0]-=b[0];
    sol[1]-=b[1];    
  }
  return(-1);
   
}

template <typename real>
real G(real x, real y)
{
 return( (0.5-0.1*(x-0.35)*(x-0.35))*(0.5-0.1*(y+1)*(y+1)) );
}

/*main()
{
 double Co[9],sol[2];
 int i;
 Co[0]=G(-1.,-1.) ;
 Co[1]=G(0.,-1.);
 Co[2]=G(1.,-1.);

 Co[3]=G(-1.,0.);
 Co[4]=G(0.,0.);
 Co[5]=G(1.,0.);

 Co[6]=G(-1.,1.);
 Co[7]=G(0.,1.);
 Co[8]=G(1.,1.);

 i=Newton(Co,sol);
 printf("Numero de Iteraciones = %d\n",i);
 if(i>-1)
   printf("sol[0]=%g, sol[1]=%g\n",sol[0],sol[1]);
}

*/

#endif
