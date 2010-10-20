/**
 * *************************************************************************
 *
 * \file This file has functions that draws arrows that shows the optical flow
 *       computed from a set of images.
 * \author Agustin Salgado (asalgado@dis.ulpgc.es)
 * \date 18-11-2005
 *
 * *************************************************************************
*/

#ifndef _ARROWS_COLOR_
#define _ARROWS_COLOR_

#include "ami_prototypes.h"



#define ArrowsMax(a, b) ((a>b)?(a):(b))
#define ArrowsMin(a, b) ((a>b)?(b):(a))



// ************************************************************************************
// ************************************************************************************

template <class real, class vector, class matrix>
void cp_vec2mat( const vector &in, matrix &out, int width, int height )
{

  try {

     out = new real*[height];

     for (int j = 0; j <height; j++)
        out[j] = new real [width];


     for (int i = 0; i<height; i++)   //
        for (int j = 0; j<width; j++)

          out[i][j] = in[i*width + j];

  // ..........................................................

  }
  catch (std::bad_alloc) {        // error
    std::cout << "Memory unallocated...";
    exit(-1);                     // finish with error
  }

}

/// ..........................................................................


/**
 * Save_arrows_color. It draws in an image in each  computes the average angular error of a set of pixels.
 *
 * \param first_u  First element fo First U image.
 * \param V1  First V image.
 * \param U2  Second U image.
 * \param V2  Second V imagea.
 * \param nx  Image width.
 * \param ny  Image height.
 * \param xinit  X origin.
 * \param yinit  Y origin.
 * \param dis_x  X displacement.
 * \param dis_y  Y displacement.
 * \param min  Minimum displacement magnitude ( to take into account).
 * \param min  Maximum displacement magnitude ( to take into account).
 * \param Npixels  Number of pixels with non NULL values.
 *
 * \return Return the average angular error of a set of pixels..
 */
template <class real, class input_iterator>
void save_arrows_color( input_iterator first_u, input_iterator last_u, input_iterator first_v, input_iterator last_v, input_iterator imgs, std::string file, int width, int height )
{
  int j = 0;

//  *********************

  unsigned char *red,*green,*blue;
  float *paso;

  unsigned char red_arrow=255; /* red color for the arrow */
  unsigned char green_arrow=0; /* green color for the arrow */
  unsigned char blue_arrow=0;  /* blue color for the arrow */
  float Umbral=0.01;    /*  minimun size of the size of arrow to to drawn */
  float angCabeza=M_PI/4;;  /* angle of the arrow head */
  float lonCab=0.3; //0.25;   /* factor of size of the arrow head */
  int x_init=3;        /* x coordinate of the init point where a arrow is drawn */
  int y_init=3;        /* y coordinate of the init point where a arrow is drawn */
  int x_interval_size=12; //32; /* x interval spacing size  of the points where a arrow is drawn */
  int y_interval_size=12; //32; /* y interval spacing size  of the points where a arrow is drawn */

  float magFlecha=4.; //6.; //4.;  /* factor of size of the arrow */
  int median_filter_radius=1; /* radius of the median filter to apply to the flow (u,v) before drawing the arrow */
  int zoom_arrow=1; //2;  /* zoom to apply to the initial image before drawing the arrows */

  long size = width*height;

//  *********************

  /* WE ALLOCATE MEMORY FOR ALL VECTOR WE NEED */
  ami_malloc1d(red,unsigned char,size);
  ami_malloc1d(green,unsigned char,size);
  ami_malloc1d(blue,unsigned char,size);


//  *********************

  while (first_u != last_u)
  {
     char a[10];
     sprintf(a, "%.3d", j++);

     std::string fn (file + a + ".bmp");

     char name[200]; // = "arrows.bmp";
     strcpy(name, fn.c_str() );

  // ........................

    // WE COMPUTE THE MEDIAN OF THE MODULUS OF THE FLOW FOR NORMALIZATION PURPOSES IN THE BMP IMAGE
     ami_malloc1d(paso,float,size);

     for(int m=0;m<size;m++) paso[m] = sqrt((double) (*first_u)[m]* (*first_u)[m] + (*first_v)[m]* (*first_v)[m]);
     float norm = ami_mediana_float(size/2,size,paso);
     free(paso);

     printf("median of the modulus of the flow =%f\n",norm);
     norm += 10e-10;

  // ........................

     real **uimg, **vimg;
     cp_vec2mat<real>( *first_u, uimg, width, height );
     cp_vec2mat<real>( *first_v, vimg, width, height );

     // ......
     //std::cout << "w: " << width << "\th: " << height << std::endl;

     real img_zoom = 64./norm;
     if (norm < 0.00001 )    img_zoom = 0;

     ami_convert_image_1d_float_to_3d_unsigned_char(*imgs, width, height, red, green, blue, 128., img_zoom );

     ami_write_bmp_arrow_file( name, red, green, blue, width, height, red_arrow, green_arrow, blue_arrow, Umbral,
                               angCabeza, lonCab, magFlecha/*/(0.01+norm)*/, uimg, vimg, x_init, y_init,
                               x_interval_size, y_interval_size, median_filter_radius+2, zoom_arrow );

     first_u++;    first_v++;     imgs++;


   // .................................

     for (int j = 0; j <height; j++) {

        delete [] uimg[j];
        delete [] vimg[j];
    }

        delete [] uimg;
        delete [] vimg;

   // .................................
  }

    free(red); free(green); free(blue);

}

// ************************************************************************************
// ************************************************************************************
// ************************************************************************************

template <class real, class uvimages, class image>
void save_multi_arrows_color( const uvimages &u, const uvimages &v, const image &img, const std::string &file, const std::vector<std::string> &imageslst, int nimgs, int width, int height )
{

  unsigned char *red,*green,*blue;
  float *paso;

  unsigned char red_arrow=255; /* red color for the arrow */
  unsigned char green_arrow=0; /* green color for the arrow */
  unsigned char blue_arrow=0;  /* blue color for the arrow */
  float Umbral=0.01;    /*  minimun size of the size of arrow to to drawn */
  float angCabeza=M_PI/4;  /* angle of the arrow head */
  float lonCab=0.25;   /* factor of size of the arrow head */
  int x_init_arrow=0;//3;        /* x coordinate of the init point where a arrow is drawn */
  int y_init_arrow=0;//3; //2;        /* y coordinate of the init point where a arrow is drawn */
  int x_interval_size_arrow=30; //32; /* x interval spacing size  of the points where a arrow is drawn */
  int y_interval_size_arrow=30; //32; /* y interval spacing size  of the points where a arrow is drawn */

  float magFlecha=4.;  /* factor of size of the arrow */
  int median_filter_radius=0; /* radius of the median filter to apply to the flow (u,v) before drawing the arrow */
  int zoom_arrow=1;   /* zoom to apply to the initial image before drawing the arrows */

  long size = width*height;

//  *********************

  /* WE ALLOCATE MEMORY FOR ALL VECTOR WE NEED */
  ami_malloc1d(red,unsigned char,size);
  ami_malloc1d(green,unsigned char,size);
  ami_malloc1d(blue,unsigned char,size);

//  *********************

   ami_convert_image_1d_float_to_3d_unsigned_char( img, width, height, red, green, blue, 0, 0.5 );

   char name[200];
   std::string fn (file + ".bmp");
   strcpy(name, fn.c_str() );

// .............

   for( int i=0; i<nimgs-1; i++ ) {
//   for( int i=nimgs-2; i>=0; i-- ) {

      if(i==0) { red_arrow=255; green_arrow=0; blue_arrow=0; }
      if(i==1) { red_arrow=0; green_arrow=255; blue_arrow=0; }
      if(i==2) { red_arrow=0; green_arrow=0; blue_arrow=255; }
      if(i>2) { red_arrow=0; green_arrow=255; blue_arrow=255; }

      ami_draw_optic_flow_arrow_v2( red, green, blue, width, height, red_arrow, green_arrow, blue_arrow,
                                 Umbral, angCabeza, lonCab, magFlecha, u[i], v[i],
                                 x_init_arrow, y_init_arrow, x_interval_size_arrow, y_interval_size_arrow, 0 );

   }




#ifdef TOP_LEFT_ORIGIN
   ami_write_bmp_inverse_rows( name, red, green, blue, width, height );
#else
   ami_write_bmp( name, red, green, blue, width, height );

   std::cout << "bottom left" << std::endl;
#endif

// ..........


   if ( nimgs != imageslst.size() ) return;

   for(int i=0; i<nimgs; i++ ){
	 for( int j=0; j<nimgs; j++ ){

	   ami_convert_image_1d_float_to_3d_unsigned_char( img, width, height, red, green, blue, 0, 0.5 );

//	   //sprintf(name,"%s_%s.bmp",argv[i+3],argv[j+3]);
	   std::string fn ( file + "_" + imageslst[i] + "_" + imageslst[j] + ".bmp" );
	   strcpy(name, fn.c_str() );


	   red_arrow=255; green_arrow=0; blue_arrow=0;

	   ami_draw_optic_flow_arrow_v2( red, green, blue, width, height, red_arrow, green_arrow, blue_arrow,
                                 Umbral, angCabeza, lonCab, magFlecha, u[i], v[i],
                                 x_init_arrow, y_init_arrow, x_interval_size_arrow, y_interval_size_arrow, 0 );

           red_arrow=0; green_arrow=255; blue_arrow=0;

	   ami_draw_optic_flow_arrow_v2( red, green, blue, width, height, red_arrow, green_arrow, blue_arrow,
                                 Umbral, angCabeza, lonCab, magFlecha, u[j], v[j],
                                 x_init_arrow, y_init_arrow, x_interval_size_arrow, y_interval_size_arrow, 0 );

#ifdef TOP_LEFT_ORIGIN
	   ami_write_bmp_inverse_rows( name, red, green, blue, width, height );
#else
	   ami_write_bmp( name, red, green, blue, width, height );
#endif

	}
  }

  free(red); free(green); free(blue);

}


// ************************************************************************************
// ************************************************************************************

// ************************************************************************************
// ************************************************************************************

template <class real, class uvimages, class image>
void save_diff_image( const uvimages &u, const uvimages &v, const image &img, const std::string &file, int nimgs,
                        int width, int height, const real &NULL_VALUE )
{
  unsigned char *red,*green,*blue;
  long size = width*height;

//  *********************

  /* WE ALLOCATE MEMORY FOR ALL VECTOR WE NEED */
  ami_malloc1d(red,unsigned char,size);
  ami_malloc1d(green,unsigned char,size);
  ami_malloc1d(blue,unsigned char,size);

//  *********************

   // WE READ THE IMAGE FROM THE OPTIC FLOW IS COMPUTED
   ami_convert_image_1d_float_to_3d_unsigned_char( img, width, height, red, green, blue, 0, 0.5 );

   char name[200];
   std::string fn (file + ".bmp");
   strcpy(name, fn.c_str() );

// .............

  for(int i=0; i<width*height; i++)  {

       if ( u[i] != NULL_VALUE ) {

          if ( u[i] != 0 ){

              red[i] = 0;
              green[i] = 255;  // green
              blue[i] = 0;
          }
          else {

              red[i] = 255;    // red
              green[i] = 0;
              blue[i] = 0;
          }

       }
   }

// .....

#ifdef TOP_LEFT_ORIGIN
   ami_write_bmp_inverse_rows( name, red, green, blue, width, height );
#else
   ami_write_bmp( name, red, green, blue, width, height );
#endif


// ..........

  free(red); free(green); free(blue);

// .............

}

#endif
