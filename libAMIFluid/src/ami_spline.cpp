
#include "ami_spline.h"
#include <math.h>
#include <stdio.h>
#include <float.h>

#include "ami_config.h"

#ifdef HAVE_MALLOC_H
#include <malloc.h>
#else
#include <stdlib.h>
#endif

static void  ConvertToInterpolationCoefficients(
					double	c[],		/* input samples --> output coefficients */
					long	DataLength,	/* number of samples or coefficients */
					double	z[],		/* poles */
					long	NbPoles,	/* number of poles */
					double	Tolerance	/* admissible relative error */
				);

static double	InitialCausalCoefficient(
					double	c[],		/* coefficients */
					long	DataLength,	/* number of coefficients */
					double	z,			/* actual pole */
					double	Tolerance	/* admissible relative error */
				);

static void		GetZline(
					float	***Image,        /* input image array */
					long	x,			/* x coordinate of the selected line */
					long	y,			/* y coordinate of the selected line */
					double	Line[],		/* output linear array */
					long	Height		/* length of the line */
				);

static void		GetColumn(
					float	***Image,        /* input image array */
					long	x,			/* x coordinate of the selected line */
					long	z,			/* z coordinate of the selected line */
					double	Line[],		/* output linear array */
					long	Height		/* length of the line */
				);

static void		GetRow(
					float	***Image,		/* input image array */
					long	y,			/* y coordinate of the selected line */
					long	z,			/* z coordinate of the selected line */
					double	Line[],		/* output linear array */
					long	Width		/* length of the line */
				);

static double	InitialAntiCausalCoefficient(
					double	c[],		/* coefficients */
					long	DataLength,	/* number of samples or coefficients */
					double	z			/* actual pole */
				);

/*****************************************************************************
 *	Definition of static procedures
 ****************************************************************************/
/*--------------------------------------------------------------------------*/
static void  ConvertToInterpolationCoefficients(
					double	c[],		/* input samples --> output coefficients */
					long	DataLength,	/* number of samples or coefficients */
					double	z[],		/* poles */
					long	NbPoles,	/* number of poles */
					double	Tolerance	/* admissible relative error */
				)
{ /* begin ConvertToInterpolationCoefficients */

	double	Lambda = 1.0;
	long	n, k;

	/* special case required by mirror boundaries */
	if (DataLength == 1L) {
		return;
	}
	/* compute the overall gain */
	for (k = 0L; k < NbPoles; k++) {
		Lambda = Lambda * (1.0 - z[k]) * (1.0 - 1.0 / z[k]);
	}
	/* apply the gain */
	for (n = 0L; n < DataLength; n++) {
		c[n] *= Lambda;
	}
	/* loop over all poles */
	for (k = 0L; k < NbPoles; k++) {
		/* causal initialization */
		c[0] = InitialCausalCoefficient(c, DataLength, z[k], Tolerance);
		/* causal recursion */
		for (n = 1L; n < DataLength; n++) {
			c[n] += z[k] * c[n - 1L];
		}
		/* anticausal initialization */
		c[DataLength - 1L] = InitialAntiCausalCoefficient(c, DataLength, z[k]);
		/* anticausal recursion */
		for (n = DataLength - 2L; 0 <= n; n--) {
			c[n] = z[k] * (c[n + 1L] - c[n]);
		}
	}
} /* end ConvertToInterpolationCoefficients */

/*--------------------------------------------------------------------------*/
static double	InitialCausalCoefficient(
					double	c[],		/* coefficients */
					long	DataLength,	/* number of coefficients */
					double	z,			/* actual pole */
					double	Tolerance	/* admissible relative error */
				)
{ /* begin InitialCausalCoefficient */

	double	Sum, zn, z2n, iz;
	long	n, Horizon;

	/* this initialization corresponds to mirror boundaries */
	Horizon = DataLength;
	if (Tolerance > 0.0) {
		Horizon = (long)ceil(log(Tolerance) / log(fabs(z)));
	}
	if (Horizon < DataLength) {
		/* accelerated loop */
		zn = z;
		Sum = c[0];
		for (n = 1L; n < Horizon; n++) {
			Sum += zn * c[n];
			zn *= z;
		}
		return(Sum);
	}
	else {
		/* full loop */
		zn = z;
		iz = 1.0 / z;
		z2n = pow(z, (double)(DataLength - 1L));
		Sum = c[0] + z2n * c[DataLength - 1L];
		z2n *= z2n * iz;
		for (n = 1L; n <= DataLength - 2L; n++) {
			Sum += (zn + z2n) * c[n];
			zn *= z;
			z2n *= iz;
		}
		return(Sum / (1.0 - zn * zn));
	}
} /* end InitialCausalCoefficient */

/*--------------------------------------------------------------------------*/
static void		GetZline(
					float	***Image,        /* input image array */
					long	x,			/* x coordinate of the selected line */
					long	y,			/* z coordinate of the selected line */
					double	Line[],		/* output linear array */
					long	dim		/* length of the line */
				)
{ /* begin GetZline */

	long	z;

	for (z = 0L; z < dim; z++) {
		Line[z] = (double) Image[x][y][z];
	}
} /* end GetZline */

/*--------------------------------------------------------------------------*/
static void		GetColumn(
					float	***Image,        /* input image array */
					long	x,			/* x coordinate of the selected line */
					long	z,			/* z coordinate of the selected line */
					double	Line[],		/* output linear array */
					long	Height		/* length of the line */
				)
{ /* begin GetColumn */

	long	y;

	for (y = 0L; y < Height; y++) {
		Line[y] = (double) Image[x][y][z];
	}
} /* end GetColumn */

/*--------------------------------------------------------------------------*/
static void		GetRow(
					float	***Image,		/* input image array */
					long	y,			/* y coordinate of the selected line */
					long	z,			/* z coordinate of the selected line */
					double	Line[],		/* output linear array */
					long	Width		/* length of the line */
				)
{ /* begin GetRow */

	long	x;

	for (x = 0L; x < Width; x++) {
		Line[x] = (double) Image[x][y][z];
	}
} /* end GetRow */

/*--------------------------------------------------------------------------*/
static double	InitialAntiCausalCoefficient(
					double	c[],		/* coefficients */
					long	DataLength,	/* number of samples or coefficients */
					double	z			/* actual pole */
				)

{ /* begin InitialAntiCausalCoefficient */

	/* this initialization corresponds to mirror boundaries */
	return((z / (z * z - 1.0)) * (z * c[DataLength - 2L] + c[DataLength - 1L]));
} /* end InitialAntiCausalCoefficient */

/*--------------------------------------------------------------------------*/
static void		PutZline(
					float	***Image,		/* output image array */
					long	x,			/* x coordinate of the selected line */
					long	y,			/* y coordinate of the selected line */
					double	Line[],		/* input linear array */
					long	dim		/* length of the line and height of the image */
				)

{ /* begin PutZline */

	long	z;

	for (z = 0L; z < dim; z++) {
		Image[x][y][z] = (float)Line[z];
	}
} /* end PutZline */

/*--------------------------------------------------------------------------*/
static void		PutColumn(
					float	***Image,		/* output image array */
					long	x,			/* x coordinate of the selected line */
					long	z,			/* z coordinate of the selected line */
					double	Line[],		/* input linear array */
					long	Height		/* length of the line and height of the image */
				)

{ /* begin PutColumn */

	long	y;

	for (y = 0L; y < Height; y++) {
		Image[x][y][z] = (float)Line[y];
	}
} /* end PutColumn */

/*--------------------------------------------------------------------------*/
static void		PutRow(
					float	***Image,		/* output image array */
					long	y,			/* y coordinate of the selected line */
					long	z,			/* z coordinate of the selected line */
					double	Line[],		/* input linear array */
					long	Width		/* length of the line and width of the image */
				)

{ /* begin PutRow */

	long	x;

	for (x = 0L; x < Width; x++) {
		Image[x][y][z] = (float)Line[x];
	}
} /* end PutRow */



/* ======================================================================
 */
int ami_spline_SamplesToCoefficients2D(
	       float	***Image,	       /* in-place processing */
	       long	Width,	       /* width of the image */
	       long	Height,	       /* height of the image */
               long	SplineDegree   /* degree of the spline model */
				)
{

	double	*Line;
	double	Pole[4];
	long	NbPoles;
	long	x, y;

	/* recover the poles from a lookup table */
	switch (SplineDegree) {
		case 2L:
			NbPoles = 1L;
			Pole[0] = sqrt(8.0) - 3.0;
			break;
		case 3L:
			NbPoles = 1L;
			Pole[0] = sqrt(3.0) - 2.0;
			break;
		case 4L:
			NbPoles = 2L;
			Pole[0] = sqrt(664.0 - sqrt(438976.0)) + sqrt(304.0) - 19.0;
			Pole[1] = sqrt(664.0 + sqrt(438976.0)) - sqrt(304.0) - 19.0;
			break;
		case 5L:
			NbPoles = 2L;
			Pole[0] = sqrt(135.0 / 2.0 - sqrt(17745.0 / 4.0)) + sqrt(105.0 / 4.0)
				- 13.0 / 2.0;
			Pole[1] = sqrt(135.0 / 2.0 + sqrt(17745.0 / 4.0)) - sqrt(105.0 / 4.0)
				- 13.0 / 2.0;
			break;
		case 6L:
			NbPoles = 3L;
			Pole[0] = -0.48829458930304475513011803888378906211227916123938;
			Pole[1] = -0.081679271076237512597937765737059080653379610398148;
			Pole[2] = -0.0014141518083258177510872439765585925278641690553467;
			break;
		case 7L:
			NbPoles = 3L;
			Pole[0] = -0.53528043079643816554240378168164607183392315234269;
			Pole[1] = -0.12255461519232669051527226435935734360548654942730;
			Pole[2] = -0.0091486948096082769285930216516478534156925639545994;
			break;
		case 8L:
			NbPoles = 4L;
			Pole[0] = -0.57468690924876543053013930412874542429066157804125;
			Pole[1] = -0.16303526929728093524055189686073705223476814550830;
			Pole[2] = -0.023632294694844850023403919296361320612665920854629;
			Pole[3] = -0.00015382131064169091173935253018402160762964054070043;
			break;
		case 9L:
			NbPoles = 4L;
			Pole[0] = -0.60799738916862577900772082395428976943963471853991;
			Pole[1] = -0.20175052019315323879606468505597043468089886575747;
			Pole[2] = -0.043222608540481752133321142979429688265852380231497;
			Pole[3] = -0.0021213069031808184203048965578486234220548560988624;
			break;
		default:
			printf("Invalid spline degree\n");
			return(1);
	}

	/* convert the image samples into interpolation coefficients */
	/* in-place separable process, along x */
	Line = (double *)malloc((size_t)(Width * (long)sizeof(double)));
	if (Line == (double *)NULL) {
		printf("Row allocation failed\n");
		return(1);
	}
	for (y = 0L; y < Height; y++) {
		GetRow(Image, y,0, Line, Width);
		ConvertToInterpolationCoefficients(Line, Width, Pole, NbPoles, DBL_EPSILON);
		PutRow(Image, y,0, Line, Width);
	}
	free(Line);

	/* in-place separable process, along y */
	Line = (double *)malloc((size_t)(Height * (long)sizeof(double)));
	if (Line == (double *)NULL) {
		printf("Column allocation failed\n");
		return(1);
	}
	for (x = 0L; x < Width; x++) {
		GetColumn(Image, x, 0, Line, Height);
		ConvertToInterpolationCoefficients(Line, Height, Pole, NbPoles, DBL_EPSILON);
		PutColumn(Image, x, 0, Line, Height);
	}
	free(Line);

	return(0);
}


/*  ======================================================================
 */
double ami_spline_InterpolatedValue2D(
               float	***Bcoeff,     /* input B-spline array of coefficients */
	       long	Width,	     /* width of the image */
	       long	Height,	     /* height of the image */
	       double	x,	     /* x coordinate where to interpolate */
	       double	y,	     /* y coordinate where to interpolate */
	       long	SplineDegree /* degree of the spline model */
				)
{
	double	xWeight[10], yWeight[10];
	double	interpolated;
	double	w, w2, w4, t, t0, t1;
	long	xIndex[10], yIndex[10];
	long	Width2 = 2L * Width - 2L, Height2 = 2L * Height - 2L;
	long	i, j, k;

	/* compute the interpolation indexes */
	if (SplineDegree & 1L) {
		i = (long)floor(x) - SplineDegree / 2L;
		j = (long)floor(y) - SplineDegree / 2L;
		for (k = 0L; k <= SplineDegree; k++) {
			xIndex[k] = i++;
			yIndex[k] = j++;
		}
	}
	else {
		i = (long)floor(x + 0.5) - SplineDegree / 2L;
		j = (long)floor(y + 0.5) - SplineDegree / 2L;
		for (k = 0L; k <= SplineDegree; k++) {
			xIndex[k] = i++;
			yIndex[k] = j++;
		}
	}

	/* compute the interpolation weights */
	switch (SplineDegree) {
		case 2L:
			/* x */
			w = x - (double)xIndex[1];
			xWeight[1] = 3.0 / 4.0 - w * w;
			xWeight[2] = (1.0 / 2.0) * (w - xWeight[1] + 1.0);
			xWeight[0] = 1.0 - xWeight[1] - xWeight[2];
			/* y */
			w = y - (double)yIndex[1];
			yWeight[1] = 3.0 / 4.0 - w * w;
			yWeight[2] = (1.0 / 2.0) * (w - yWeight[1] + 1.0);
			yWeight[0] = 1.0 - yWeight[1] - yWeight[2];
			break;
		case 3L:
			/* x */
			w = x - (double)xIndex[1];
			xWeight[3] = (1.0 / 6.0) * w * w * w;
			xWeight[0] = (1.0 / 6.0) + (1.0 / 2.0) * w * (w - 1.0) - xWeight[3];
			xWeight[2] = w + xWeight[0] - 2.0 * xWeight[3];
			xWeight[1] = 1.0 - xWeight[0] - xWeight[2] - xWeight[3];
			/* y */
			w = y - (double)yIndex[1];
			yWeight[3] = (1.0 / 6.0) * w * w * w;
			yWeight[0] = (1.0 / 6.0) + (1.0 / 2.0) * w * (w - 1.0) - yWeight[3];
			yWeight[2] = w + yWeight[0] - 2.0 * yWeight[3];
			yWeight[1] = 1.0 - yWeight[0] - yWeight[2] - yWeight[3];
			break;
		case 4L:
			/* x */
			w = x - (double)xIndex[2];
			w2 = w * w;
			t = (1.0 / 6.0) * w2;
			xWeight[0] = 1.0 / 2.0 - w;
			xWeight[0] *= xWeight[0];
			xWeight[0] *= (1.0 / 24.0) * xWeight[0];
			t0 = w * (t - 11.0 / 24.0);
			t1 = 19.0 / 96.0 + w2 * (1.0 / 4.0 - t);
			xWeight[1] = t1 + t0;
			xWeight[3] = t1 - t0;
			xWeight[4] = xWeight[0] + t0 + (1.0 / 2.0) * w;
			xWeight[2] = 1.0 - xWeight[0] - xWeight[1] - xWeight[3] - xWeight[4];
			/* y */
			w = y - (double)yIndex[2];
			w2 = w * w;
			t = (1.0 / 6.0) * w2;
			yWeight[0] = 1.0 / 2.0 - w;
			yWeight[0] *= yWeight[0];
			yWeight[0] *= (1.0 / 24.0) * yWeight[0];
			t0 = w * (t - 11.0 / 24.0);
			t1 = 19.0 / 96.0 + w2 * (1.0 / 4.0 - t);
			yWeight[1] = t1 + t0;
			yWeight[3] = t1 - t0;
			yWeight[4] = yWeight[0] + t0 + (1.0 / 2.0) * w;
			yWeight[2] = 1.0 - yWeight[0] - yWeight[1] - yWeight[3] - yWeight[4];
			break;
		case 5L:
			/* x */
			w = x - (double)xIndex[2];
			w2 = w * w;
			xWeight[5] = (1.0 / 120.0) * w * w2 * w2;
			w2 -= w;
			w4 = w2 * w2;
			w -= 1.0 / 2.0;
			t = w2 * (w2 - 3.0);
			xWeight[0] = (1.0 / 24.0) * (1.0 / 5.0 + w2 + w4) - xWeight[5];
			t0 = (1.0 / 24.0) * (w2 * (w2 - 5.0) + 46.0 / 5.0);
			t1 = (-1.0 / 12.0) * w * (t + 4.0);
			xWeight[2] = t0 + t1;
			xWeight[3] = t0 - t1;
			t0 = (1.0 / 16.0) * (9.0 / 5.0 - t);
			t1 = (1.0 / 24.0) * w * (w4 - w2 - 5.0);
			xWeight[1] = t0 + t1;
			xWeight[4] = t0 - t1;
			/* y */
			w = y - (double)yIndex[2];
			w2 = w * w;
			yWeight[5] = (1.0 / 120.0) * w * w2 * w2;
			w2 -= w;
			w4 = w2 * w2;
			w -= 1.0 / 2.0;
			t = w2 * (w2 - 3.0);
			yWeight[0] = (1.0 / 24.0) * (1.0 / 5.0 + w2 + w4) - yWeight[5];
			t0 = (1.0 / 24.0) * (w2 * (w2 - 5.0) + 46.0 / 5.0);
			t1 = (-1.0 / 12.0) * w * (t + 4.0);
			yWeight[2] = t0 + t1;
			yWeight[3] = t0 - t1;
			t0 = (1.0 / 16.0) * (9.0 / 5.0 - t);
			t1 = (1.0 / 24.0) * w * (w4 - w2 - 5.0);
			yWeight[1] = t0 + t1;
			yWeight[4] = t0 - t1;
			break;
		case 6L:
			/* x */
			w = x - (double)xIndex[3];
			xWeight[0] = 1.0 / 2.0 - w;
			xWeight[0] *= xWeight[0] * xWeight[0];
			xWeight[0] *= xWeight[0] / 720.0;
			xWeight[1] = (361.0 / 192.0 - w * (59.0 / 8.0 + w
				* (-185.0 / 16.0 + w * (25.0 / 3.0 + w * (-5.0 / 2.0 + w)
				* (1.0 / 2.0 + w))))) / 120.0;
			xWeight[2] = (10543.0 / 960.0 + w * (-289.0 / 16.0 + w
				* (79.0 / 16.0 + w * (43.0 / 6.0 + w * (-17.0 / 4.0 + w
				* (-1.0 + w)))))) / 48.0;
			w2 = w * w;
			xWeight[3] = (5887.0 / 320.0 - w2 * (231.0 / 16.0 - w2
				* (21.0 / 4.0 - w2))) / 36.0;
			xWeight[4] = (10543.0 / 960.0 + w * (289.0 / 16.0 + w
				* (79.0 / 16.0 + w * (-43.0 / 6.0 + w * (-17.0 / 4.0 + w
				* (1.0 + w)))))) / 48.0;
			xWeight[6] = 1.0 / 2.0 + w;
			xWeight[6] *= xWeight[6] * xWeight[6];
			xWeight[6] *= xWeight[6] / 720.0;
			xWeight[5] = 1.0 - xWeight[0] - xWeight[1] - xWeight[2] - xWeight[3]
				- xWeight[4] - xWeight[6];
			/* y */
			w = y - (double)yIndex[3];
			yWeight[0] = 1.0 / 2.0 - w;
			yWeight[0] *= yWeight[0] * yWeight[0];
			yWeight[0] *= yWeight[0] / 720.0;
			yWeight[1] = (361.0 / 192.0 - w * (59.0 / 8.0 + w
				* (-185.0 / 16.0 + w * (25.0 / 3.0 + w * (-5.0 / 2.0 + w)
				* (1.0 / 2.0 + w))))) / 120.0;
			yWeight[2] = (10543.0 / 960.0 + w * (-289.0 / 16.0 + w
				* (79.0 / 16.0 + w * (43.0 / 6.0 + w * (-17.0 / 4.0 + w
				* (-1.0 + w)))))) / 48.0;
			w2 = w * w;
			yWeight[3] = (5887.0 / 320.0 - w2 * (231.0 / 16.0 - w2
				* (21.0 / 4.0 - w2))) / 36.0;
			yWeight[4] = (10543.0 / 960.0 + w * (289.0 / 16.0 + w
				* (79.0 / 16.0 + w * (-43.0 / 6.0 + w * (-17.0 / 4.0 + w
				* (1.0 + w)))))) / 48.0;
			yWeight[6] = 1.0 / 2.0 + w;
			yWeight[6] *= yWeight[6] * yWeight[6];
			yWeight[6] *= yWeight[6] / 720.0;
			yWeight[5] = 1.0 - yWeight[0] - yWeight[1] - yWeight[2] - yWeight[3]
				- yWeight[4] - yWeight[6];
			break;
		case 7L:
			/* x */
			w = x - (double)xIndex[3];
			xWeight[0] = 1.0 - w;
			xWeight[0] *= xWeight[0];
			xWeight[0] *= xWeight[0] * xWeight[0];
			xWeight[0] *= (1.0 - w) / 5040.0;
			w2 = w * w;
			xWeight[1] = (120.0 / 7.0 + w * (-56.0 + w * (72.0 + w
				* (-40.0 + w2 * (12.0 + w * (-6.0 + w)))))) / 720.0;
			xWeight[2] = (397.0 / 7.0 - w * (245.0 / 3.0 + w * (-15.0 + w
				* (-95.0 / 3.0 + w * (15.0 + w * (5.0 + w
				* (-5.0 + w))))))) / 240.0;
			xWeight[3] = (2416.0 / 35.0 + w2 * (-48.0 + w2 * (16.0 + w2
				* (-4.0 + w)))) / 144.0;
			xWeight[4] = (1191.0 / 35.0 - w * (-49.0 + w * (-9.0 + w
				* (19.0 + w * (-3.0 + w) * (-3.0 + w2))))) / 144.0;
			xWeight[5] = (40.0 / 7.0 + w * (56.0 / 3.0 + w * (24.0 + w
				* (40.0 / 3.0 + w2 * (-4.0 + w * (-2.0 + w)))))) / 240.0;
			xWeight[7] = w2;
			xWeight[7] *= xWeight[7] * xWeight[7];
			xWeight[7] *= w / 5040.0;
			xWeight[6] = 1.0 - xWeight[0] - xWeight[1] - xWeight[2] - xWeight[3]
				- xWeight[4] - xWeight[5] - xWeight[7];
			/* y */
			w = y - (double)yIndex[3];
			yWeight[0] = 1.0 - w;
			yWeight[0] *= yWeight[0];
			yWeight[0] *= yWeight[0] * yWeight[0];
			yWeight[0] *= (1.0 - w) / 5040.0;
			w2 = w * w;
			yWeight[1] = (120.0 / 7.0 + w * (-56.0 + w * (72.0 + w
				* (-40.0 + w2 * (12.0 + w * (-6.0 + w)))))) / 720.0;
			yWeight[2] = (397.0 / 7.0 - w * (245.0 / 3.0 + w * (-15.0 + w
				* (-95.0 / 3.0 + w * (15.0 + w * (5.0 + w
				* (-5.0 + w))))))) / 240.0;
			yWeight[3] = (2416.0 / 35.0 + w2 * (-48.0 + w2 * (16.0 + w2
				* (-4.0 + w)))) / 144.0;
			yWeight[4] = (1191.0 / 35.0 - w * (-49.0 + w * (-9.0 + w
				* (19.0 + w * (-3.0 + w) * (-3.0 + w2))))) / 144.0;
			yWeight[5] = (40.0 / 7.0 + w * (56.0 / 3.0 + w * (24.0 + w
				* (40.0 / 3.0 + w2 * (-4.0 + w * (-2.0 + w)))))) / 240.0;
			yWeight[7] = w2;
			yWeight[7] *= yWeight[7] * yWeight[7];
			yWeight[7] *= w / 5040.0;
			yWeight[6] = 1.0 - yWeight[0] - yWeight[1] - yWeight[2] - yWeight[3]
				- yWeight[4] - yWeight[5] - yWeight[7];
			break;
		case 8L:
			/* x */
			w = x - (double)xIndex[4];
			xWeight[0] = 1.0 / 2.0 - w;
			xWeight[0] *= xWeight[0];
			xWeight[0] *= xWeight[0];
			xWeight[0] *= xWeight[0] / 40320.0;
			w2 = w * w;
			xWeight[1] = (39.0 / 16.0 - w * (6.0 + w * (-9.0 / 2.0 + w2)))
				* (21.0 / 16.0 + w * (-15.0 / 4.0 + w * (9.0 / 2.0 + w
				* (-3.0 + w)))) / 5040.0;
			xWeight[2] = (82903.0 / 1792.0 + w * (-4177.0 / 32.0 + w
				* (2275.0 / 16.0 + w * (-487.0 / 8.0 + w * (-85.0 / 8.0 + w
				* (41.0 / 2.0 + w * (-5.0 + w * (-2.0 + w)))))))) / 1440.0;
			xWeight[3] = (310661.0 / 1792.0 - w * (14219.0 / 64.0 + w
				* (-199.0 / 8.0 + w * (-1327.0 / 16.0 + w * (245.0 / 8.0 + w
				* (53.0 / 4.0 + w * (-8.0 + w * (-1.0 + w)))))))) / 720.0;
			xWeight[4] = (2337507.0 / 8960.0 + w2 * (-2601.0 / 16.0 + w2
				* (387.0 / 8.0 + w2 * (-9.0 + w2)))) / 576.0;
			xWeight[5] = (310661.0 / 1792.0 - w * (-14219.0 / 64.0 + w
				* (-199.0 / 8.0 + w * (1327.0 / 16.0 + w * (245.0 / 8.0 + w
				* (-53.0 / 4.0 + w * (-8.0 + w * (1.0 + w)))))))) / 720.0;
			xWeight[7] = (39.0 / 16.0 - w * (-6.0 + w * (-9.0 / 2.0 + w2)))
				* (21.0 / 16.0 + w * (15.0 / 4.0 + w * (9.0 / 2.0 + w
				* (3.0 + w)))) / 5040.0;
			xWeight[8] = 1.0 / 2.0 + w;
			xWeight[8] *= xWeight[8];
			xWeight[8] *= xWeight[8];
			xWeight[8] *= xWeight[8] / 40320.0;
			xWeight[6] = 1.0 - xWeight[0] - xWeight[1] - xWeight[2] - xWeight[3]
				- xWeight[4] - xWeight[5] - xWeight[7] - xWeight[8];
			/* y */
			w = y - (double)yIndex[4];
			yWeight[0] = 1.0 / 2.0 - w;
			yWeight[0] *= yWeight[0];
			yWeight[0] *= yWeight[0];
			yWeight[0] *= yWeight[0] / 40320.0;
			w2 = w * w;
			yWeight[1] = (39.0 / 16.0 - w * (6.0 + w * (-9.0 / 2.0 + w2)))
				* (21.0 / 16.0 + w * (-15.0 / 4.0 + w * (9.0 / 2.0 + w
				* (-3.0 + w)))) / 5040.0;
			yWeight[2] = (82903.0 / 1792.0 + w * (-4177.0 / 32.0 + w
				* (2275.0 / 16.0 + w * (-487.0 / 8.0 + w * (-85.0 / 8.0 + w
				* (41.0 / 2.0 + w * (-5.0 + w * (-2.0 + w)))))))) / 1440.0;
			yWeight[3] = (310661.0 / 1792.0 - w * (14219.0 / 64.0 + w
				* (-199.0 / 8.0 + w * (-1327.0 / 16.0 + w * (245.0 / 8.0 + w
				* (53.0 / 4.0 + w * (-8.0 + w * (-1.0 + w)))))))) / 720.0;
			yWeight[4] = (2337507.0 / 8960.0 + w2 * (-2601.0 / 16.0 + w2
				* (387.0 / 8.0 + w2 * (-9.0 + w2)))) / 576.0;
			yWeight[5] = (310661.0 / 1792.0 - w * (-14219.0 / 64.0 + w
				* (-199.0 / 8.0 + w * (1327.0 / 16.0 + w * (245.0 / 8.0 + w
				* (-53.0 / 4.0 + w * (-8.0 + w * (1.0 + w)))))))) / 720.0;
			yWeight[7] = (39.0 / 16.0 - w * (-6.0 + w * (-9.0 / 2.0 + w2)))
				* (21.0 / 16.0 + w * (15.0 / 4.0 + w * (9.0 / 2.0 + w
				* (3.0 + w)))) / 5040.0;
			yWeight[8] = 1.0 / 2.0 + w;
			yWeight[8] *= yWeight[8];
			yWeight[8] *= yWeight[8];
			yWeight[8] *= yWeight[8] / 40320.0;
			yWeight[6] = 1.0 - yWeight[0] - yWeight[1] - yWeight[2] - yWeight[3]
				- yWeight[4] - yWeight[5] - yWeight[7] - yWeight[8];
			break;
		case 9L:
			/* x */
			w = x - (double)xIndex[4];
			xWeight[0] = 1.0 - w;
			xWeight[0] *= xWeight[0];
			xWeight[0] *= xWeight[0];
			xWeight[0] *= xWeight[0] * (1.0 - w) / 362880.0;
			xWeight[1] = (502.0 / 9.0 + w * (-246.0 + w * (472.0 + w
				* (-504.0 + w * (308.0 + w * (-84.0 + w * (-56.0 / 3.0 + w
				* (24.0 + w * (-8.0 + w))))))))) / 40320.0;
			xWeight[2] = (3652.0 / 9.0 - w * (2023.0 / 2.0 + w * (-952.0 + w
				* (938.0 / 3.0 + w * (112.0 + w * (-119.0 + w * (56.0 / 3.0 + w
				* (14.0 + w * (-7.0 + w))))))))) / 10080.0;
			xWeight[3] = (44117.0 / 42.0 + w * (-2427.0 / 2.0 + w * (66.0 + w
				* (434.0 + w * (-129.0 + w * (-69.0 + w * (34.0 + w * (6.0 + w
				* (-6.0 + w))))))))) / 4320.0;
			w2 = w * w;
			xWeight[4] = (78095.0 / 63.0 - w2 * (700.0 + w2 * (-190.0 + w2
				* (100.0 / 3.0 + w2 * (-5.0 + w))))) / 2880.0;
			xWeight[5] = (44117.0 / 63.0 + w * (809.0 + w * (44.0 + w
				* (-868.0 / 3.0 + w * (-86.0 + w * (46.0 + w * (68.0 / 3.0 + w
				* (-4.0 + w * (-4.0 + w))))))))) / 2880.0;
			xWeight[6] = (3652.0 / 21.0 - w * (-867.0 / 2.0 + w * (-408.0 + w
				* (-134.0 + w * (48.0 + w * (51.0 + w * (-4.0 + w) * (-1.0 + w)
				* (2.0 + w))))))) / 4320.0;
			xWeight[7] = (251.0 / 18.0 + w * (123.0 / 2.0 + w * (118.0 + w
				* (126.0 + w * (77.0 + w * (21.0 + w * (-14.0 / 3.0 + w
				* (-6.0 + w * (-2.0 + w))))))))) / 10080.0;
			xWeight[9] = w2 * w2;
			xWeight[9] *= xWeight[9] * w / 362880.0;
			xWeight[8] = 1.0 - xWeight[0] - xWeight[1] - xWeight[2] - xWeight[3]
				- xWeight[4] - xWeight[5] - xWeight[6] - xWeight[7] - xWeight[9];
			/* y */
			w = y - (double)yIndex[4];
			yWeight[0] = 1.0 - w;
			yWeight[0] *= yWeight[0];
			yWeight[0] *= yWeight[0];
			yWeight[0] *= yWeight[0] * (1.0 - w) / 362880.0;
			yWeight[1] = (502.0 / 9.0 + w * (-246.0 + w * (472.0 + w
				* (-504.0 + w * (308.0 + w * (-84.0 + w * (-56.0 / 3.0 + w
				* (24.0 + w * (-8.0 + w))))))))) / 40320.0;
			yWeight[2] = (3652.0 / 9.0 - w * (2023.0 / 2.0 + w * (-952.0 + w
				* (938.0 / 3.0 + w * (112.0 + w * (-119.0 + w * (56.0 / 3.0 + w
				* (14.0 + w * (-7.0 + w))))))))) / 10080.0;
			yWeight[3] = (44117.0 / 42.0 + w * (-2427.0 / 2.0 + w * (66.0 + w
				* (434.0 + w * (-129.0 + w * (-69.0 + w * (34.0 + w * (6.0 + w
				* (-6.0 + w))))))))) / 4320.0;
			w2 = w * w;
			yWeight[4] = (78095.0 / 63.0 - w2 * (700.0 + w2 * (-190.0 + w2
				* (100.0 / 3.0 + w2 * (-5.0 + w))))) / 2880.0;
			yWeight[5] = (44117.0 / 63.0 + w * (809.0 + w * (44.0 + w
				* (-868.0 / 3.0 + w * (-86.0 + w * (46.0 + w * (68.0 / 3.0 + w
				* (-4.0 + w * (-4.0 + w))))))))) / 2880.0;
			yWeight[6] = (3652.0 / 21.0 - w * (-867.0 / 2.0 + w * (-408.0 + w
				* (-134.0 + w * (48.0 + w * (51.0 + w * (-4.0 + w) * (-1.0 + w)
				* (2.0 + w))))))) / 4320.0;
			yWeight[7] = (251.0 / 18.0 + w * (123.0 / 2.0 + w * (118.0 + w
				* (126.0 + w * (77.0 + w * (21.0 + w * (-14.0 / 3.0 + w
				* (-6.0 + w * (-2.0 + w))))))))) / 10080.0;
			yWeight[9] = w2 * w2;
			yWeight[9] *= yWeight[9] * w / 362880.0;
			yWeight[8] = 1.0 - yWeight[0] - yWeight[1] - yWeight[2] - yWeight[3]
				- yWeight[4] - yWeight[5] - yWeight[6] - yWeight[7] - yWeight[9];
			break;
		default:
			printf("Invalid spline degree\n");
			return(0.0);
	}

	/* apply the mirror boundary conditions */
	for (k = 0L; k <= SplineDegree; k++) {
		xIndex[k] = (Width == 1L) ? (0L) : ((xIndex[k] < 0L) ?
			(-xIndex[k] - Width2 * ((-xIndex[k]) / Width2))
			: (xIndex[k] - Width2 * (xIndex[k] / Width2)));
		if (Width <= xIndex[k]) {
			xIndex[k] = Width2 - xIndex[k];
		}
		yIndex[k] = (Height == 1L) ? (0L) : ((yIndex[k] < 0L) ?
			(-yIndex[k] - Height2 * ((-yIndex[k]) / Height2))
			: (yIndex[k] - Height2 * (yIndex[k] / Height2)));
		if (Height <= yIndex[k]) {
			yIndex[k] = Height2 - yIndex[k];
		}
	}

	/* perform interpolation */
	interpolated = 0.0;
	for (j = 0L; j <= SplineDegree; j++) {
		w = 0.0;
		for (i = 0L; i <= SplineDegree; i++) {
			w += xWeight[i] * Bcoeff[xIndex[i]][yIndex[j]][0];
		}
		interpolated += yWeight[j] * w;
	}

	return(interpolated);
}


/*
  image is accessed by Image[x][y][z]
*/
int ami_spline_SamplesToCoefficients3D(
	       float	***Image,        /* in-place processing */
	       long     dimx,	       /* image dimension */
	       long	dimy,	       /* image dimension */
	       long	dimz,	       /* image dimension */
               long	SplineDegree   /* degree of the spline model */
				)

{
	double	*Line;
	double	Pole[4];
	long	NbPoles;
	long	x, y,z;

	/* recover the poles from a lookup table */
	switch (SplineDegree) {
		case 2L:
			NbPoles = 1L;
			Pole[0] = sqrt(8.0) - 3.0;
			break;
		case 3L:
			NbPoles = 1L;
			Pole[0] = sqrt(3.0) - 2.0;
			break;
		default:
			printf("Invalid spline degree\n");
			return(1);
	}

	/* convert the image samples into interpolation coefficients */
	/* in-place separable process, along x */
	Line = (double *)malloc((size_t)(dimx * (long)sizeof(double)));
	if (Line == (double *)NULL) {
		printf("Row allocation failed\n");
		return(1);
	}
	for (z = 0L; z < dimz; z++) {
	for (y = 0L; y < dimy; y++) {
		GetRow(Image, y, z, Line, dimx);
		ConvertToInterpolationCoefficients(Line, dimx, Pole, NbPoles, DBL_EPSILON);
		PutRow(Image, y, z, Line, dimx);
	}
	}
	free(Line);

	/* in-place separable process, along y */
	Line = (double *)malloc((size_t)(dimy * (long)sizeof(double)));
	if (Line == (double *)NULL) {
		printf("Column allocation failed\n");
		return(1);
	}
	for (x = 0L; x < dimx; x++) {
	for (z = 0L; z < dimz; z++) {
		GetColumn(Image,  x, z, Line, dimy);
		ConvertToInterpolationCoefficients(Line, dimy, Pole, NbPoles, DBL_EPSILON);
		PutColumn(Image, x, z, Line, dimy);
	}
        }
	free(Line);

	/* in-place separable process, along z */
	Line = (double *)malloc((size_t)(dimz * (long)sizeof(double)));
	if (Line == (double *)NULL) {
		printf("Zline allocation failed\n");
		return(1);
	}
	for (x = 0L; x < dimx; x++) {
	for (y = 0L; y < dimy; y++) {
		GetZline(Image,  x, y, Line, dimz);
		ConvertToInterpolationCoefficients(Line, dimz, Pole, NbPoles, DBL_EPSILON);
		PutZline(Image, x, y, Line, dimz);
	}
        }
	free(Line);

	return(0);
}

double ami_spline_InterpolatedValue3D(
               float	***Bcoeff,    /* input B-spline array of coefficients */
	       long	dimx,	     /* image dimension in X */
	       long	dimy,	     /* image dimension in Y */
	       long	dimz,	     /* image dimension in Z */
	       double	x,	     /* x coordinate where to interpolate */
	       double	y,	     /* y coordinate where to interpolate */
	       double	z,	     /* z coordinate where to interpolate */
	       long	SplineDegree /* degree of the spline model */
				)
{
	double	xWeight[10], yWeight[10], zWeight[10];
	double	interpolated,interpolatedy;
	double	w;
	long	xIndex[10], yIndex[10],zIndex[10];
	long	dimx2 = 2L * dimx - 2L;
        long    dimy2 = 2L * dimy - 2L;
        long    dimz2 = 2L * dimz - 2L;
	long	i, j, k,l;

	/* compute the interpolation indexes */
	if (SplineDegree & 1L) {
		i = (long)floor(x) - SplineDegree / 2L;
		j = (long)floor(y) - SplineDegree / 2L;
		k = (long)floor(z) - SplineDegree / 2L;
		for (l = 0L; l <= SplineDegree; l++) {
			xIndex[l] = i++;
			yIndex[l] = j++;
			zIndex[l] = k++;
		}
	}
	else {
		i = (long)floor(x + 0.5) - SplineDegree / 2L;
		j = (long)floor(y + 0.5) - SplineDegree / 2L;
		k = (long)floor(z + 0.5) - SplineDegree / 2L;
		for (l = 0L; l <= SplineDegree; l++) {
			xIndex[l] = i++;
			yIndex[l] = j++;
			zIndex[l] = k++;
		}
	}

	/* compute the interpolation weights */
	switch (SplineDegree) {
		case 2L:
			/* x */
			w = x - (double)xIndex[1];
			xWeight[1] = 3.0 / 4.0 - w * w;
			xWeight[2] = (1.0 / 2.0) * (w - xWeight[1] + 1.0);
			xWeight[0] = 1.0 - xWeight[1] - xWeight[2];
			/* y */
			w = y - (double)yIndex[1];
			yWeight[1] = 3.0 / 4.0 - w * w;
			yWeight[2] = (1.0 / 2.0) * (w - yWeight[1] + 1.0);
			yWeight[0] = 1.0 - yWeight[1] - yWeight[2];
			/* z */
			w = z - (double)zIndex[1];
			zWeight[1] = 3.0 / 4.0 - w * w;
			zWeight[2] = (1.0 / 2.0) * (w - zWeight[1] + 1.0);
			zWeight[0] = 1.0 - zWeight[1] - zWeight[2];
			break;
		case 3L:
			/* x */
			w = x - (double)xIndex[1];
			xWeight[3] = (1.0 / 6.0) * w * w * w;
			xWeight[0] = (1.0 / 6.0) + (1.0 / 2.0) * w * (w - 1.0) - xWeight[3];
			xWeight[2] = w + xWeight[0] - 2.0 * xWeight[3];
			xWeight[1] = 1.0 - xWeight[0] - xWeight[2] - xWeight[3];
			/* y */
			w = y - (double)yIndex[1];
			yWeight[3] = (1.0 / 6.0) * w * w * w;
			yWeight[0] = (1.0 / 6.0) + (1.0 / 2.0) * w * (w - 1.0) - yWeight[3];
			yWeight[2] = w + yWeight[0] - 2.0 * yWeight[3];
			yWeight[1] = 1.0 - yWeight[0] - yWeight[2] - yWeight[3];
			/* z */
			w = z - (double)zIndex[1];
			zWeight[3] = (1.0 / 6.0) * w * w * w;
			zWeight[0] = (1.0 / 6.0) + (1.0 / 2.0) * w * (w - 1.0) - zWeight[3];
			zWeight[2] = w + zWeight[0] - 2.0 * zWeight[3];
			zWeight[1] = 1.0 - zWeight[0] - zWeight[2] - zWeight[3];
			break;
		default:
			printf("Invalid spline degree\n");
			return(0.0);
	}

	/* apply the mirror boundary conditions */
	for (l = 0L; l <= SplineDegree; l++) {
		xIndex[l] = (dimx == 1L) ? (0L) : ((xIndex[l] < 0L) ?
			(-xIndex[l] - dimx2 * ((-xIndex[l]) / dimx2))
			: (xIndex[l] - dimx2 * (xIndex[l] / dimx2)));
		if (dimx <= xIndex[l]) {
			xIndex[l] = dimx2 - xIndex[l];
		}
		yIndex[l] = (dimy == 1L) ? (0L) : ((yIndex[l] < 0L) ?
			(-yIndex[l] - dimy2 * ((-yIndex[l]) / dimy2))
			: (yIndex[l] - dimy2 * (yIndex[l] / dimy2)));
		if (dimy <= yIndex[l]) {
			yIndex[l] = dimy2 - yIndex[l];
		}
		zIndex[l] = (dimz == 1L) ? (0L) : ((zIndex[l] < 0L) ?
			(-zIndex[l] - dimz2 * ((-zIndex[l]) / dimz2))
			: (zIndex[l] - dimz2 * (zIndex[l] / dimz2)));
		if (dimz <= zIndex[l]) {
			zIndex[l] = dimz2 - zIndex[l];
		}
	}

	/* perform interpolation */
	interpolated = 0.0;
	for (k = 0L; k <= SplineDegree; k++) {
                interpolatedy = 0.0;
		for (j = 0L; j <= SplineDegree; j++) {
			w = 0.0;
			for (i = 0L; i <= SplineDegree; i++) {
				w += xWeight[i] * Bcoeff[xIndex[i]][yIndex[j]][zIndex[k]];
			}
			interpolatedy += yWeight[j] * w;
		}
           interpolated += zWeight[k]*interpolatedy;
        }

	return(interpolated);
}
