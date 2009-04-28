#include <Options.h>

#include <Image.H>
#include <math.h>



typedef float real;
typedef SImage<real> Ima;




template <class T>
Ima *AngularError(const T &U1, const T &V1, 
		  const T &U2, const T &V2,
		  int border =15, 
		  real min = -1.0, real max = 999999.0){

    Ima *I;
    real N = 0;

    I = new Ima(U1.GetXd(), U1.GetYd());

    *I = 0;

    MapXY(U1,x,y){

        if((x >= border && y >= border) && 
           (x < U1.GetXd()-border && y < U1.GetYd()-border) && 
	   (fabs(U1(x ,y)) > min && fabs(U1(x, y)) < max)) {
            
	  real num  = U1(x,y) * U2(x,y) + V1(x,y) * V2(x,y) + 1;

	  real den1 = U1(x,y) * U1(x,y) + V1(x,y) * V1(x,y) + 1;
	  real den2 = U2(x,y) * U2(x,y) + V2(x,y) * V2(x,y) + 1;
	  real den  = sqrt(den1 * den2);

	  (*I)(x,y) = acos(num/den);
	  
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

    int  border = 0;
    real min = -1.0, max = 999999.0;

    if(argc>6) {

      border = atoi(argv[i]); i++;
  
      if(argc>7) {
  	min = atof(argv[i]); i++;

	if(argc>8) {
	  max = atof(argv[i]); i++;
	}
      }
    }
      
    Ima *I = AngularError(U1, V1, U2, V2, border, min, max);

    I->Save(argv[i]);

    delete I;

}
