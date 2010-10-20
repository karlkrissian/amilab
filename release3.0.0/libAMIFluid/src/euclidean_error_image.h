#include <Options.h>

#include <Image.H>
#include <math.h>



typedef float real;
typedef SImage<real> Ima;




template <class T>
Ima * EuclideanError(const T &U1, const T &V1, 
		    const T &U2, const T &V2,
		    int border = 15, 
		    real min, real max){

    Ima  *I;
    real N = 0;

    I = new Ima (U1.GetXd(), U1.GetYd());

    *I = 0;

    MapXY(U1,x,y){

        if((x >= border && y >= border) && 
           (x < U1.GetXd()-border && y < U1.GetYd()-border) && 
	   (fabs(U1(x ,y)) > min && fabs(U1(x, y)) < max)) {
            
	  real U = U1(x,y) - U2(x,y);
	  real V = V1(x,y) - V2(x,y);

	  (*I)(x,y) = sqrt(U * U + V * V);
	  
	  N += 1;

        }

    }

    return I;

}



int main ( int argc, char **argv ) {


    options_t Call ( argc, argv ); 
    Call.nooption  ( 5, 5, "Uc Vc Ue Ve Iout [border min max]");
    Call.end ();
    
    int i = 1;

    const Ima U1 = argv[i]; i++;
    const Ima V1 = argv[i]; i++;
    const Ima U2 = argv[i]; i++;
    const Ima V2 = argv[i]; i++;

    real border = 0, min = -1.0, max = 999999.0;

    if(argc>6) {

      border = atoi(argv[i]); i++;
  
      if(argc>7) {
  	min = atof(argv[i]); i++;

	if(argc>8) {
	  max = atof(argv[i]); i++;
	}
      }
    }
      
    Ima *I = EuclideanError(U1, V1, U2, V2, border, min, max);

    I->Save(argv[i]);

    delete I;

}
