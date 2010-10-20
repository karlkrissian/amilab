 /** 
 * **************************************************************************
 *
 *  Flow_methods.h:  Fichero que implementa varios metodo para el circulo
 *                 del flujo optico teniendo en cuenta el tiempo.
 *
 * **************************************************************************
**/

#ifndef _FLOW_METHODS_
#define _FLOW_METHODS_

#include <vector>
#include <namespace.h>

// ....................................................

#define WRITE_ASCII


#define OPTIC_FLOW_VIDEO_SIMPLE
//#define OPTIC_FLOW_VIDEO_SF
//#define OPTIC_FLOW_VIDEO_INVERSO
//#define OPTIC_FLOW_VIDEO_MULTICHANNEL

// .......................

//#ifndef OPTIC_FLOW_VIDEO_SIMPLE
//#endif

//#define TV_FLOW
//#define JW_FLOW

// .......................


#ifdef OPTIC_FLOW_VIDEO_SIMPLE
   #include "version_simple/optic_flow_video.h"
#endif

#ifdef OPTIC_FLOW_VIDEO_SF
   #include "version_sftemporal/optic_flow_video.h"
#endif

#ifdef OPTIC_FLOW_VIDEO_INVERSO
   #include "version_inversa/optic_flow_video.h"
#endif

#ifdef OPTIC_FLOW_VIDEO_MULTICHANNEL
   #include "version_multichannel/optic_flow_video.h"
#endif



#include "optic_flow.h"


#ifdef TV_FLOW
   //#include "TV_optic_flow.h"
   #include "src/TV_optic_flow.h"
#endif

#ifdef JW_FLOW
   #include "version_jweickert/JW_optic_flow_video.h"
#endif


// ....................................................

typedef float real;

#include "file_uv.h"
#include "euclidean_error.h"
#include "angular_error.h"

// -----------
#include "ami_estadisticos.h"
// -----------

#include "TOpticFlow.h"


#ifdef WRITE_ASCII
   #include "arrows_color.h"
#endif

// ....................................................


const int ERROR_BORDER = 8;
const real MIN_ERROR_BORDER = 0.0001;
const real MAX_ERROR_BORDER = 999999.0;


// -----------------------------------------------------------------------------------
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// -----------------------------------------------------------------------------------

// *************************************************************************
// *************************************************************************


/**
 * Ami_write_paramfile. Save in a file the params of pde results.
 *
 */
int ami_write_paramfile( const std::string &method, int x_init, int y_init,int x_interval_size, int y_interval_size,
                         const int Nzoom, const real &alpha, const real &beta, const real &gamma, const real &lambda,
                         const real &T, const real &dt, const real &nu, const char *ofn )
{
    std::ofstream ofs( ofn );

    if ( ofs.is_open() )  {

        ofs << "# AMI Optic Flow PDE " << method << " method parameters." << std::endl;
        ofs << "#" << std::endl;
        ofs << "# horizontal initial coordinate point = $ " << x_init << std::endl;
        ofs << "# vertical initial coordinate point = $ " << y_init << std::endl;
        ofs << "# horizontal displacement between points = $ " << x_interval_size << std::endl;
        ofs << "# vertical displacement between points = $ " << x_interval_size << std::endl;
        ofs << "#" << std::endl;
        ofs << "# Nzoom = $ " << Nzoom << std::endl;
        ofs << "#" << std::endl;
        ofs << "# Alpha = $ " << alpha << std::endl;
        ofs << "# Beta = $ " << beta << std::endl;
        ofs << "# Gamma = $ " << gamma << std::endl;
        ofs << "# Lambda = $ " << lambda << std::endl;
        ofs << "#" << std::endl;
        ofs << "# T = $ " << T << std::endl;
        ofs << "# dt = $ " << dt << std::endl;
        ofs << "# nu = $ " << nu << std::endl;
        ofs << "#" << std::endl;

        // ..............................................

        ofs.close();
    }
    else
    {
       std::cerr << "Error opening file:  " << ofn << std::endl;
       return -1;
    }

    return 0;
}


// -----------------------------------------------------------------------------------
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// -----------------------------------------------------------------------------------

/*
template <class image>
void error1frame( const std::string &str, const image &u, const image &v, int w, int h )
{

      real *uc = new real[w*h];
      real *vc = new real[w*h];
      NM_AMI_FILE::read_uv<real>(uc, vc, w, h, str.c_str() );
      
      std::cout << std::endl << std::endl;
      std::cout << angular_error<real>(uc, vc, u, v, w, h, ERROR_BORDER, MIN_ERROR_BORDER, MAX_ERROR_BORDER, uc) << " ";
      std::cout << euclidean_error<real>(uc, vc, u, v, w, h, ERROR_BORDER, MIN_ERROR_BORDER, MAX_ERROR_BORDER, uc) ;
      std::cout << std::endl << std::endl;

      delete []uc;
      delete []vc;

}
*/

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

template <class image>
void Calcular_Error( const std::vector<std::string> &str, const std::vector<image> &u, const std::vector<image> &v,
                     const std::vector<image> &mask, int w, int h, int NFRAMES )
{

   for(int t = 0; t < NFRAMES-1; t++) {

      real *uc = new real[w*h];
      real *vc = new real[w*h];
      NM_AMI_FILE::read_uv<real>(uc, vc, w, h, str[t].c_str() );


      std::cout << angular_error<real>(uc, vc, u[t], v[t], w, h, ERROR_BORDER, MIN_ERROR_BORDER, MAX_ERROR_BORDER, mask[t] ) << " ";
      std::cout << euclidean_error<real>(uc, vc, u[t], v[t], w, h, ERROR_BORDER, MIN_ERROR_BORDER, MAX_ERROR_BORDER, mask[t] ) << "\n";

      delete []uc;
      delete []vc;
   }

}


//---------------------------------------------------------------------------


// SIMPLEFLOW_VIDEO
template <class image>
void SIMPLEflow_video( std::vector<image> &images, std::vector<image> &u, std::vector<image> &v,
                      const std::vector<image> &mask, int w, int h,
                      const int Nzoom, const real alpha, const real beta, const real gamma, const real lambda,
                      const real T, const real dt, const real nu, int n,
                      const std::string &outputfn, const std::vector<std::string> &outUVfn )
{
   NM_AMI_UTIL::TOpticFlow<real> convert;

   NM_AMI_METHOD::optic_flow_video<real> optic_flow;
   optic_flow(images, u, v, w, h, Nzoom, alpha, beta, gamma, lambda, T, dt, nu, std::cout );


   // .....................

#ifdef WRITE_ASCII
   std::string ofn_param( outputfn + std::string("_pde_param.txt") );
   ami_write_paramfile( "VD", 0, 0, 1, 1, Nzoom, alpha, beta, gamma, lambda, T, dt, nu, ofn_param.c_str() );
#endif

   // .....................

   for(int t = 0; t < n /*NFRAMES*/ - 1; t++)
   {

#if (0)
      std::string ofn = outputfn + std::string("00.uv");
      convert.itoa( ofn, t, 44 ); //9 );
#else
      std::string ofn = std::string("00") + outputfn + std::string(".uv");
      convert.itoa( ofn, t, 1 );
#endif


      //flujo optico normal
     #ifdef WRITE_ASCII

        ami_write_optic_flow_v2( (ofn + std::string(".txt")).c_str(), ofn_param.c_str(), u[t], v[t], w, h, 0, 0, 1, 1);
     #else
        //NM_AMI_FILE::save_uv<real>(u[t], v[t], w, h, ofn.c_str() );
     #endif

        std::cerr << "Salvando las  imagenes con las flechas... " << std::endl;
        save_arrows_color<real>( u.begin(), u.end(), v.begin(), v.end(), images.begin(), std::string("arrows_VD") + ofn, w, h);


     NM_AMI_FILE::save_uv<real>(u[t], v[t], w, h, ofn.c_str() );

   }

   Calcular_Error( outUVfn, u, v, mask, w, h, n );
}


//---------------------------------------------------------------------------


//SIMPLEFLOW
template <class image>
void SIMPLEflow( std::vector<image> &images, std::vector<image> &u, std::vector<image> &v,
                  const std::vector<image> &mask, int w, int h,
                  const int Nzoom, const real alpha, const real lambda,
                  const real T, const real dt, const real nu, int n,
                  const std::string &outputfn, const std::vector<std::string> &outUVfn )
{
   NM_AMI_UTIL::TOpticFlow<real> convert;

   // .....................

#ifdef WRITE_ASCII
   std::string ofn_param( outputfn + std::string("_pde_param.txt") );
   ami_write_paramfile( "SF", 0, 0, 1, 1, Nzoom, alpha, 0.0, 0.0, lambda, T, dt, nu, ofn_param.c_str() );
#endif

   // .....................


   for(int t = 0; t < n /*NFRAMES*/ - 1; t++)
   {
      NM_AMI_METHOD::optic_flow<real> optic_flow;

      optic_flow( images[t], images[t+1], u[t], v[t], w, h, Nzoom, alpha, lambda, T, dt, nu, std::cout );

#if (0)
      std::string ofn = outputfn + std::string("00.uv");
      convert.itoa( ofn, t, 44 ); //9 );
#else
      std::string ofn = std::string("00") + outputfn + std::string(".uv");
      convert.itoa( ofn, t, 1 );
#endif


      //flujo optico normal
     #ifdef WRITE_ASCII

       //savemediaimage( (ofn + std::string(".txt") ).c_str(), u[t], v[t], w, h, UV_NULL_VALUE );

       ami_write_optic_flow_v2( (ofn + std::string("_v2.txt") ).c_str(), ofn_param.c_str(), u[t], v[t], w, h, 0, 0, 1, 1);
     #else
        //NM_AMI_FILE::save_uv<real>(u[t], v[t], w, h, ofn.c_str() );
     #endif

        std::cerr << "Salvando las  imagenes con las flechas... " << std::endl;
        save_arrows_color<real>( u.begin(), u.end(), v.begin(), v.end(), images.begin(), std::string("arrows_SF") + ofn, w, h);


     // NM_AMI_FILE::save_uv<real>(u[t], v[t], w, h, ofn.c_str() );
   }

   //Calcular_Error( outUVfn, u, v, mask, w, h, n );
}


// -----------------------------------------------------------------------------------
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// -----------------------------------------------------------------------------------

#ifdef OPTIC_FLOW_VIDEO_MULTICHANNEL

template <class image>
void MultiChannel_Flow_video( const std::vector< std::vector<image> > &images, 
		      std::vector<image> &u, std::vector<image> &v,
                      const std::vector<image> &mask, int w, int h,
                      const int Nzoom, const real alpha, const std::vector<real> &beta, const real gamma, 
		      const real lambda,
                      const real T, const real dt, const real nu, int n,
                      const std::string &outputfn, const std::vector<std::string> &outUVfn )
{
   NM_AMI_UTIL::TOpticFlow<real> convert;

   int nz = images.size();
   int nc = images[0].size();

   NM_AMI_METHOD::optic_flow_video<real> optic_flow;
   optic_flow( images, u, v, w, h, nz, nc, beta, Nzoom, alpha, gamma,
	       lambda, T, dt, nu, std::cout );

   // .....................

/*
#ifdef WRITE_ASCII
   std::string ofn_param( outputfn + std::string("_pde_param.txt") );
//   ami_write_paramfile( "MC", 0, 0, 1, 1, Nzoom, alpha, beta, gamma, lambda, T, dt, nu, ofn_param.c_str() );
#endif
*/

   // .....................

   for(int t = 0; t < n /*NFRAMES*/ - 1; t++)
   {

#if (0)
      std::string ofn = outputfn + std::string("00.uv");
      convert.itoa( ofn, t, 44 ); //9 );
#else
      std::string ofn = std::string("00") + outputfn + std::string(".uv");
      convert.itoa( ofn, t, 1 );
#endif


      //flujo optico normal
     #ifdef WRITE_ASCII

	std::vector<real *> ss( nz );

	for (int i=0; i<nz; i++)
                ss[i] = images[i][0];


        //ami_write_optic_flow_v2( ( ofn + std::string(".txt")).c_str(), ofn.c_str(), u[t], v[t], w, h, 0, 0, 1, 1);
        ami_write_optic_flow_v2( ( ofn + std::string(".txt")).c_str(), "mcheader.txt", u[t], v[t], w, h, 0, 0, 1, 1);


        std::cerr << "Salvando las  imagenes con las flechas... " << std::endl;
        save_arrows_color<real>( u.begin(), u.end(), v.begin(), v.end(), ss.begin(), std::string("arrows_MC") + ofn, w, h);


/*
template <class real, class input_iterator>
void save_arrows_color( input_iterator first_u, input_iterator last_u, input_iterator first_v, input_iterator la
st_v, input_iterator imgs, std::string file, int width, int height )
*/
     #endif

     //NM_AMI_FILE::save_uv<real>(u[t], v[t], w, h, ofn.c_str() );

   }

// ATENCION: NO SE CALCULA EL ERROR. Esta funcion esta fue creada para hacer las pruebas de VINCE para un articulo de revista dentro del proyecto fluid. Esta secuencia no tiene ground truth.
   //Calcular_Error( outUVfn, u, v, mask, w, h, n );
}

#endif

//---------------------------------------------------------------------------

// JWFLOW
#ifdef JW_FLOW

template <class image>
void JWflow( std::vector<image> &images, std::vector<image> &u, std::vector<image> &v,
              const std::vector<image> &mask, int w, int h,
              const int Nzoom, const real alpha, //const real lambda,
	      const real T, const real dt, const real nu, int n,
	      const std::string &outputfn, const std::vector<std::string> &outUVfn )
{
   NM_AMI_UTIL::TOpticFlow<real> convert;

   NM_AMI_METHOD::JW_optic_flow_video<real> optic_flow;
   optic_flow(images, u, v, w, h, Nzoom, alpha, /*lambda,*/ T, dt, nu, std::cout );
   

   for(int t = 0; t < n /*NFRAMES*/ - 1; t++) {

      std::string ofn = std::string("00") + outputfn + std::string(".uv");
      convert.itoa( ofn, t, 1 );

      NM_AMI_FILE::save_uv<real>(u[t], v[t], w, h, ofn.c_str() );

//      error1frame( outUVfn[t], u[t], v[t], w, h );
//      break;
   }

   Calcular_Error( outUVfn, u, v, mask, w, h, n );
}

#endif


//---------------------------------------------------------------------------

// TVFLOW
#ifdef TV_FLOW
template <class image>
void TVflow( std::vector<image> &images, std::vector<image> &u, std::vector<image> &v,
              const std::vector<image> &mask, int w, int h,
              const int Nzoom, const real alpha, const real T, const real dt, const real nu,
              int n, const std::string &outputfn, const std::vector<std::string> &outUVfn )
{

   NM_AMI_UTIL::TOpticFlow<real> convert;


   for(int t = 0; t < n /*NFRAMES*/ - 1; t++) {

      NM_AMI_METHOD::TV_optic_flow<real> optic_flow;
      optic_flow(images[t], images[t+1], u[t], v[t], w, h, Nzoom, alpha, T, dt, nu, std::cout );


#if (0)
      std::string ofn = outputfn + std::string("00.uv");
      convert.itoa( ofn, t, 44 ); //9 );
#else
      std::string ofn = std::string("00") + outputfn + std::string(".uv");
      convert.itoa( ofn, t, 1 );
#endif


     #ifdef WRITE_ASCII

        ami_write_optic_flow_v2( (ofn + std::string(".txt") ).c_str(), ofn_param.c_str(), u[t], v[t], w, h, 0, 0, 1, 1);
     #else
        //NM_AMI_FILE::save_uv<real>(u[t], v[t], w, h, ofn.c_str() );
     #endif

      NM_AMI_FILE::save_uv<real>(u[t], v[t], w, h, ofn.c_str() );

//      error1frame( outUVfn[t], u[t], v[t], w, h );
//      break;
   }

   Calcular_Error( outUVfn, u, v, mask, w, h, n );

}
#endif


//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

#endif


#if (0)
int savemediaimage( const char *output_name, real *u, real *v, int width, int height, const real &NULL_VALUE )
{
    std::ofstream ofs( output_name );

    ofs << "#" << std::endl << "#:#" << std::endl << "#" << std::endl;
    ofs << width << " " << height << std::endl;

    for (int i=0; i<height; i++)
       for (int j=0; j<width; j++) {

         if ( u[i*width+j] != NULL_VALUE  &&  v[i*width+j] != NULL_VALUE ) {

            ofs << j << " " << i  << " " << u[i*width+j] << " " << -v[i*width+j] << std::endl;
         }

       }

    ofs.close();

    return 0;
}
#endif
