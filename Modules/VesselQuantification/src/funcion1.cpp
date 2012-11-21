
#include "funcion1.h"

using namespace std;
using namespace VesselQuantif;

//------------------------------------------------------------------------------
double LineResample::Funcion(double s, const Line& cubspline)
{
  double dx,dy,dz,f;
  
  dx = (3*cubspline[0][0]*s*s)+(2*cubspline[1][0]*s)+(cubspline[2][0]);
  dx = dx*dx;
  dy = (3*cubspline[0][1]*s*s)+(2*cubspline[1][1]*s)+(cubspline[2][1]);
  dy = dy*dy;
  dz = (3*cubspline[0][2]*s*s)+(2*cubspline[1][2]*s)+(cubspline[2][2]);
  dz= dz*dz;
  f = sqrt(dx+dy+dz);
  return f;
}



//------------------------------------------------------------------------------
Line LineResample::Kochanek(const Line& V)
{
  Line mul(4);

  int H[4][4],i,j,k;
  double sum;
  //Se inicializa la matriz de Hermite
  H[0][0]=2;  H[0][1]=-2; H[0][2]=1;  H[0][3]=1;
  H[1][0]=-3; H[1][1]=3;  H[1][2]=-2; H[1][3]=-1;
  H[2][0]=0;  H[2][1]=0;  H[2][2]=1;  H[2][3]=0;
  H[3][0]=1;  H[3][1]=0;  H[3][2]=0;  H[3][3]=0;
  
  sum=0.;
  for (i=0;i<3;i++)
    for(j=0;j<2;j++)
        {
          for(k=0;k<3;k++)
              sum=sum+H[i][k]*V[k][j];
                  
          mul[i][j]= sum;
          sum=0;                
        }   
  return mul;
}

//------------------------------------------------------------------------------
Point3D LineResample::DerivadaPunto(const Line& line,int i)
{
    Point3D D;
    
    D[0] = (line[i+1][0]-line[i-1][0])/2.0;
    D[1] = (line[i+1][1]-line[i-1][1])/2.0;
    D[2] = (line[i+1][2]-line[i-1][2])/2.0; 
    return D; 
 }
 
//------------------------------------------------------------------------------
Line LineResample::construir(const Line& line,int i)
{
    Line V(4);
    Point3D D1,D2;
    int k;
    Line mul;

    D1 = DerivadaPunto(line,i);
    D2 = DerivadaPunto(line,i+1);   
         
    for(k=0;k<2;k++)
    {
       V[0][k]= line[i][k];
       V[1][k]= line[i+1][k];
       V[2][k]= D1[k];
       V[3][k]= D2[k];
     }                    
    
    mul = Kochanek(V);
    mul.Print("mul");
    
    return mul;
}

//------------------------------------------------------------------------------
double LineResample::LongArco(double x, double b,const Line& CS, int subdiv) 
{
  //calculamos la longitud de arco mediante el método de Simpson (integral)
  double x1,sumatoria,acum,paso;
  acum = 0.0;
  x1=0.0;
  paso= (b-x)/subdiv;
  
  while(x1<=b)
  {             
    x1=x+paso;  
    sumatoria = ((Funcion(x1,CS)+Funcion(x,CS)+4*Funcion((x+x1)/2,CS))/6)
                *(x1-x);
    acum = acum + sumatoria;
    x =x+paso;
    
  }
  // printf("\n acum = %lf",acum);
  return acum;
}   

//------------------------------------------------------------------------------
Line LineResample::CenterlineEquidistante(double long_fija, 
                                          const Line& centerline, double paso)
{
  double a,b=1;
  double acum,inf,sup,longitud;
  Line Puntos;
  Line tabla;
  Point3D punto;
  Line mul;
  int j,i,n;
  j=0;
  i=0;
  acum = 0.0;
  inf=a;

  for (n=1; n<centerline.size()-2; n++)
  {       
    //Calculo la derivada de los puntos Di,Di+1
    mul = construir(centerline,n);
    a=0;// aquí empieza el otro spline
    while(a<=b)
    {             
      sup=a+paso;
      longitud=LongArco(a,sup,mul); 
  
      printf("\n mat[%d] = %lf  %lf   %lf",i,a,sup,longitud);
      //voy sumando la longitud de arco mientras sea <= long_fija
      acum = acum+longitud;
      if (acum>long_fija)//se toma el primer pto cuya long es mayor a la fija
      {
//         tabla[j][0]=inf;  //punto inferior
//         tabla[j][1]=sup ; //punto superior 
//         tabla[j][2]=acum;  //longitud de arco 
        tabla.points.push_back(Point3D(inf,sup,acum));

        punto[0]= (3*mul[0][0]*sup*sup)+(2*mul[1][0]*sup)+(mul[2][0]);//Px
        punto[1]= (3*mul[0][1]*sup*sup)+(2*mul[1][1]*sup)+(mul[2][1]);//Py
        punto[2]= (3*mul[0][2]*sup*sup)+(2*mul[1][2]*sup)+(mul[2][2]);//Pz
        
        Puntos.points.push_back(punto);
        
        //printf("\n                   tabla[%d]= %lf  %lf %lf %lf",j,Puntos[j][0],Puntos[j][1],Puntos[j][2],tabla[j][2]);  
        j++;     
        acum =0.;
        inf= sup;      
      }
      a=sup;
      i++;
        
    }
    printf("\n npuntos=%d",Puntos.size());
  }
   
  return Puntos;
  //imprimir tabla
      //    for(j=0;j<1000;j++)
        //      printf("\n                   tabla[%d]= %lf  %lf %lf",j,tabla[j][0],tabla[j][1],tabla[j][2]); 
 }
 
 
       
// //------------------------------------------------------------------------------
// int main()
// {
//    double a,b,resp,paso,longitud;
//    int n;
//    
//    Line centerline;
//    
//    centerline.points.push_back(Point3D(11,2.3,3.6));
//    centerline.points.push_back(Point3D(4.1,5.3,6.8));
//    centerline.points.push_back(Point3D(8.7,2.8,5.9));
// //    centerline.points.push_back(Point3D(11,2.3,3.6));
// //    centerline.points.push_back(Point3D(11,2.3,3.6));
// //    centerline.points.push_back(Point3D(11,2.3,3.6));
// //    centerline.points.push_back(Point3D(11,2.3,3.6));
// //    [7][3]={{},{},{},{1.10,4.11,7.12},{8.13,6.14,1.5},{1.6,12.7,15.8},{19,20,21}};
//      
//    longitud = 0.5;
//    CenterlineEquidistante(longitud,centerline);
//    system("pause"); 
// }
