/*
 *----------------------------------------------------------------------------
 *	This C program is based on the following paper:
 *		P. Thevenaz, T. Blu, M. Unser, "Interpolation Revisited,"
 *		IEEE Transactions on Medical Imaging,
 *		vol. 19, no. 7, pp. 739-758, July 2000.
 *----------------------------------------------------------------------------
 *	EPFL/STI/IOA/LIB/BM.4.137
 *	Philippe Thevenaz
 *	Station 17
 *	CH-1015 Lausanne VD
 *----------------------------------------------------------------------------
 *	phone (CET):	+41(21)693.51.61
 *	fax:			+41(21)693.37.01
 *	RFC-822:		philippe.thevenaz@epfl.ch
 *	X-400:			/C=ch/A=400net/P=switch/O=epfl/S=thevenaz/G=philippe/
 *	URL:			http://bigwww.epfl.ch/
 *----------------------------------------------------------------------------
 */


#ifndef AMI_SPLINE_H
#define AMI_SPLINE_H


/*
  image is accessed by Image[x][y]
*/
int ami_spline_SamplesToCoefficients2D(
	       float	***Image,        /* in-place processing */
	       long	Width,	       /* width of the image */
	       long	Height,	       /* height of the image */
               long	SplineDegree   /* degree of the spline model */
				);

double ami_spline_InterpolatedValue2D(
               float	***Bcoeff,    /* input B-spline array of coefficients */
	       long	Width,	     /* width of the image */
	       long	Height,	     /* height of the image */
	       double	x,	     /* x coordinate where to interpolate */
	       double	y,	     /* y coordinate where to interpolate */
	       long	SplineDegree /* degree of the spline model */
				);


/*
  image is accessed by Image[x][y][z]
*/
int ami_spline_SamplesToCoefficients3D(
	       float	***Image,        /* in-place processing */
	       long     dimx,	       /* image dimension */
	       long	dimy,	       /* image dimension */
	       long	dimz,	       /* image dimension */
               long	SplineDegree   /* degree of the spline model */
				);



double ami_spline_InterpolatedValue3D(
               float	***Bcoeff,    /* input B-spline array of coefficients */
	       long	dimx,	     /* image dimension in X */
	       long	dimy,	     /* image dimension in Y */
	       long	dimz,	     /* image dimension in Z */
	       double	x,	     /* x coordinate where to interpolate */
	       double	y,	     /* y coordinate where to interpolate */
	       double	z,	     /* z coordinate where to interpolate */
	       long	SplineDegree /* degree of the spline model */
				);

#endif // AMI_SPLINE_H
