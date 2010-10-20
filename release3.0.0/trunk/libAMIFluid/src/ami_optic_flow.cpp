/**
 * *************************************************************************
 *
 * \file THIS FILE IMPLEMENTS OPTICFLOW METHODS.
 * \author Luis Alvarez (lalvarez@dis.ulpgc.es)
 * \date 16-10-2005
 *
 * *************************************************************************
*/

#include <string.h>
#include "ami_prototypes.h"
#include "ami_optic_flow.h"
#include "ami.h"

//const float UV_NULL_VALUE = 10000;

/**
	FUNCTION TO CONVERT A 1D FLOAT IMAGE IN A 3D STRUCTURE TENSOR IMAGE
*/
void ami_convert_image_1d_float_to_3d_unsigned_char(float *image,int width,int height, unsigned char *red,
          unsigned char *green, unsigned char *blue,
		  float center, /**< center of displacement of the float image value */
		  float zoom) /**< zoom to apply to the float image value */
{
  long m,size=width*height;
  float value;

  for(m=0;m<size;m++){
	value=image[m]*zoom+center;
    if(value>255) value=255;
	else if(value<0) value=0;
	red[m]=green[m]=blue[m]=(unsigned char) value;
  }
}



/**
	FUNCION PARA DIBUJAR UN VECTOR EN LA posx, posy EN LA IMAGEN
    imgDestino, CON UNA VELOCIDAD DE valx, valy			    
*/

void ami_draw_arrow(unsigned char *red,unsigned char *green,unsigned char *blue,int width,int height,
                   unsigned char red_arrow,unsigned char green_arrow,unsigned char blue_arrow,
                   int posy, int posx, float valx, float valy,
		           float Umbral, float angCabeza, float lonCab, float magFlecha)
{
    float bx=(float)posx, by=(float)posy;	/* punto final de la flecha */
    float ax, ay;	/* desplazamiento del origen con respecto al final */
    float cx, cy;		/* variables para calcular los puntos de la cabeza */
    float cx1, cy1;		/* variables para calcular los puntos de la cabeza */
    float ax1, ax2, ay1, ay2;	/* variables intermedias para el calculo de la cabeza */
    float modulo, lonTronco;
    float lonCabeza;

    /* modificacion para que las flechas salgan en valor logaritmico */
 /*   ax=-(valx>0?log( 1.+10.*valx):-log( 1.-10.*valx) );
    ay=-(valy>0?log( 1.+10.*valy):-log( 1.-10.*valy) );*/
    ax=-valx;
    ay=-valy;
   lonTronco=fabs(ax)>fabs(ay)?fabs(ax):fabs(ay);
   //ax=(ax>0)?5.*magFlecha*ax/(1+0.5*ax):5.*magFlecha*ax/(1-0.5*ax);
   //ay=(ay>0)?5.*magFlecha*ay/(1+0.5*ay):5.*magFlecha*ay/(1-0.5*ay);
   ax*=magFlecha;
   ay*=magFlecha;

   bx-=ax;
   by-=ay;

    /*printf("VALX=%f, VALY=%lf, ax=%f, ay=%f, tronco=%f\n", valx,valy,ax, ay, lonTronco);*/
    /* comprobamos que haya movimiento en el punto */
    if(lonTronco>Umbral){
      lonTronco=sqrt(ax*ax+ay*ay);
      /*printf("Dibujamos esta flecha______\n");*/
      /* dibujamos el tronco de la flecha */
      if(bx<0) bx=0;
      if(bx>width) bx=width;
	  //if(bx>=height) bx=height-1;
      if(by<0) by=0;
      if(by>height) by=height;
	  //if(by>=width) by=width-1;
	  ami_draw_segment(red,green,blue,width,height,red_arrow,green_arrow,blue_arrow,posx,posy,(int)bx, (int)by);
      //ami_draw_segment(red,green,blue,width,height,red_arrow,green_arrow,blue_arrow,posy,posx,(int)bx, (int)by);

      /* vamos a dibujar la cabeza */
      ax1=ax*cos(angCabeza)+ay*sin(angCabeza);	/* rotacion para el primer palo */
      ay1=-ax*sin(angCabeza)+ay*cos(angCabeza);
      ax2=ax*cos(angCabeza)-ay*sin(angCabeza);	/* rotacion para el segundo palo */
      ay2=ax*sin(angCabeza)+ay*cos(angCabeza);
      modulo=sqrt(ax1*ax1+ay1*ay1);

      lonCabeza=lonCab*lonTronco;	/* tamao de la cabeza a la mitad del tronco */
      if(modulo>0.000001){
	    /* dibujamos el primer palo de la cabeza */
	    cx=ax1/modulo*lonCabeza+bx;
	    cy=ay1/modulo*lonCabeza+by;
	    if(cx<0) cx=0;
	    if(cx>width) cx=width;
	    if(cy<0) cy=0;
	    if(cy>height) cy=height;
        /*   DrawLine(imgDestino, (int)cx, (int)cy, (int)bx, (int)by);*/
		ami_draw_segment(red,green,blue,width,height,red_arrow,green_arrow,blue_arrow,(int)cx,(int)cy,(int)bx, (int)by);

	    /* dibujamos el segundo palo de la cabeza */
	    cx1=ax2/modulo*lonCabeza+bx;
	    cy1=ay2/modulo*lonCabeza+by;
	    if(cx1<0) cx1=0;
	    if(cx1>width) cx1=width;
	    if(cy1<0) cy=0;
	    if(cy1>height) cy1=height;
        /*  DrawLine(imgDestino, (int)cx1, (int)cy1,(int) bx, (int)by);*/
        ami_draw_segment(red,green,blue,width,height,red_arrow,green_arrow,blue_arrow,(int)cx1,(int)cy1,(int)bx, (int)by);

	    /* dibujamos la tercera linea */
        //  DrawLine(imgDestino, (int)cx1, (int)cy1,(int) cx, (int)cy);

	    /* rellenamos la cabeza de la flecha */
	    /*ami_fill_triangle(red,green,blue,width,height,red_arrow,green_arrow,blue_arrow,
                        (int)cx, (int)cy, (int)cx1, (int)cy1, (int)bx, (int)by); */
      }
   }
}

/**
	FUNCTION TO DRAW THE OPTIC FLOW ARROW IMAGE
*/
void ami_draw_optic_flow_arrow(
    unsigned char *red,unsigned char *green,unsigned char *blue, /* pointer to the output image */
    int width,int height,  /* image dimension */
    unsigned char red_arrow,unsigned char green_arrow,unsigned char blue_arrow, /* color for the arrow */
    float Umbral, /* minimum size of the arrow to be drawn */
	float angCabeza, /* head arrow angle */
	float lonCab,  /* factor of amplitud for head arrow size */
	float magFlecha, /* factor of magnitud for arrow size */
	float **u,float **v, /* flow to be drawn in the image */
	int x_init, int y_init, /* coordinates of the initial point to draw the first arrow */
	int x_interval_size, int y_interval_size, /* displacement between consecutives arrows */
	int median_filter_radius) /* median filter to apply to the flow (u,v) before drawing the arrow */
{
  int i_min,i_max,j_min,j_max,i0,j0,i,j;
  float *um=NULL,*vm=NULL,u0,v0;
  long m;
  //long size=width*height;

  /* WE ALLOCATE MEMORY FOR VECTOR TO COMPUTE FLOW MEDIAN */
  if(median_filter_radius>0){
	ami_malloc1d(um,float, (2*median_filter_radius+1)*(2*median_filter_radius+1));
	ami_malloc1d(vm,float, (2*median_filter_radius+1)*(2*median_filter_radius+1));
  }

  /* WE DRAW THE ARROWS IN THE IMAGE */
  for(i=y_init;i<height;i+=y_interval_size){
	for(j=x_init;j<width;j+=x_interval_size){
	  /* WE COMPUTE A MEDIAN FILTER ON THE FLOW */
	  if(median_filter_radius>0){
		i_min=ami_max(0,(i-median_filter_radius));
		i_max=ami_min((height-1),(i+median_filter_radius));
		j_min=ami_max(0,(j-median_filter_radius));
		j_max=ami_min((width-1),(j+median_filter_radius));
		m=0;
		for(i0=i_min;i0<=i_max;i0++){
		  for(j0=j_min;j0<=j_max;j0++){
			um[m]=u[i0][j0];
			vm[m]=v[i0][j0];
			m++;
		  }
		}
        u0=ami_mediana_float(m/2,m,um);
		v0=ami_mediana_float(m/2,m,vm);
      }
	  else{
		u0=u[i][j];
		v0=v[i][j];
	  }
	  /* WE DRAW THE ARROW IN THE IMAGE */
	  ami_draw_arrow(red,green,blue,width,height,red_arrow,green_arrow,blue_arrow,
                     i,j,u0,v0,Umbral,angCabeza,lonCab,magFlecha);

	}
  }

  /* WE FREE THE MEMORY */
  if(median_filter_radius>0){ free(um); free(vm); }
}


// ............................................................................
// ............................................................................
// ............................................................................


/**
	FUNCTION TO DRAW THE OPTIC FLOW ARROW IMAGE
*/
void ami_draw_optic_flow_arrow_v2(
    unsigned char *red,unsigned char *green,unsigned char *blue, /* pointer to the output image */
    int width,int height,  /* image dimension */
    unsigned char red_arrow,unsigned char green_arrow,unsigned char blue_arrow, /* color for the arrow */
    float Umbral, /* minimum size of the arrow to be drawn */
	float angCabeza, /* head arrow angle */
	float lonCab,  /* factor of amplitud for head arrow size */
	float magFlecha, /* factor of magnitud for arrow size */
	float *u,float *v, /* flow to be drawn in the image */
	int x_init, int y_init, /* coordinates of the initial point to draw the first arrow */
	int x_interval_size, int y_interval_size, /* displacement between consecutives arrows */
	int median_filter_radius) /* median filter to apply to the flow (u,v) before drawing the arrow */
{
  int i_min,i_max,j_min,j_max,i0,j0,i,j;
  float *um=NULL,*vm=NULL,u0,v0;
  long m;
  //long size=width*height;

  /* WE ALLOCATE MEMORY FOR VECTOR TO COMPUTE FLOW MEDIAN */
  if(median_filter_radius>0){
	ami_malloc1d(um,float, (2*median_filter_radius+1)*(2*median_filter_radius+1));
	ami_malloc1d(vm,float, (2*median_filter_radius+1)*(2*median_filter_radius+1));
  }

  /* WE DRAW THE ARROWS IN THE IMAGE */
  for(i=y_init;i<height;i+=y_interval_size){
	for(j=x_init;j<width;j+=x_interval_size){
	  /* WE COMPUTE A MEDIAN FILTER ON THE FLOW */
	  if(median_filter_radius>0){
		i_min=ami_max(0,(i-median_filter_radius));
		i_max=ami_min((height-1),(i+median_filter_radius));
		j_min=ami_max(0,(j-median_filter_radius));
		j_max=ami_min((width-1),(j+median_filter_radius));
		m=0;
		for(i0=i_min;i0<=i_max;i0++){
		  for(j0=j_min;j0<=j_max;j0++){
			um[m]=u[i0*width + j0]; //u[i0][j0];
			vm[m]=v[i0*width + j0]; //v[i0][j0];
			m++;
		  }
		}
        u0=ami_mediana_float(m/2,m,um);
	v0=ami_mediana_float(m/2,m,vm);
      }
	  else{
		u0=u[i*width + j]; //u[i][j];
		v0=v[i*width + j]; //v[i][j];
	  }
	  /* WE DRAW THE ARROW IN THE IMAGE */
	  ami_draw_arrow(red,green,blue,width,height,red_arrow,green_arrow,blue_arrow,
                     i,j,u0,v0,Umbral,angCabeza,lonCab,magFlecha);

	}
  }

  /* WE FREE THE MEMORY */
  if(median_filter_radius>0){ free(um); free(vm); }

}

// ............................................................................
// ............................................................................
// ............................................................................

/**
	FUNCION QUE DIBUJA UN SEGMENTO EN COLOR
*/
void ami_draw_segment(
   unsigned char *red,unsigned char *green,unsigned char *blue,int width,int height,
              unsigned char red_arrow,unsigned char green_arrow,unsigned char blue_arrow,
   int x0, int y0, /* COORDENADAS 1 PUNTO DEL SEGMENTO */
   int x1, int y1)  /* COORDENADAS 2 PUNTO DEL SEGMENTO */

{
 int incx = ami_abs(x1 - x0);
 int incy = ami_abs(y1 - y0);
 int p, dx, dy;
 int x, y;
 int temp;

 if(x0<0 || x0>=width || x1<0 || x1>=width) return;
 if(y0<0 || y0>=height || y1<0 || y1>=height) return;


 if (incx>incy) {
   if (x0>x1){
     temp=x0; x0=x1; x1=temp;
     temp=y0; y0=y1; y1=temp;
   }
   x=x0; y=y0;
   p = 2*incy - incx;
   dy = (y1>y0)? 1 : -1;
   red[y*width+x] = red_arrow;
   green[y*width+x] = green_arrow;
   blue[y*width+x] = blue_arrow;

   do {
     if (p<0) {
       p += 2*incy;
     } else {
       p += 2*incy - 2*incx;
       y += dy;
     }
     x++;
     red[y*width+x] = red_arrow;
     green[y*width+x] = green_arrow;
     blue[y*width+x] = blue_arrow;

   } while (x<x1);
 } else {
     if (y0>y1) {
       temp=x0; x0=x1; x1=temp;
       temp=y0; y0=y1; y1=temp;
     }
     x=x0; y=y0;
     p = 2*incx - incy;
     dx = (x1>x0)? 1 : -1;
     red[y*width+x] = red_arrow;
     green[y*width+x] = green_arrow;
     blue[y*width+x] = blue_arrow;

     do {
       if (p<0) {
         p += 2*incx;
       } else {
         p += 2*incx - 2*incy;
	 x += dx;
       }
       y++;
       red[y*width+x] = red_arrow;
       green[y*width+x] = green_arrow;
       blue[y*width+x] = blue_arrow;

    } while (y<y1);
  }
}



/**
  FUNCION TO WRITE AN ARROW BMP FILE WITH THE INFORMATION OF THE OPTIC FLOW (u,v)
*/
int ami_write_bmp_arrow_file(char name[200],unsigned char *red,unsigned char *green,unsigned char *blue,int width,int height,
                   unsigned char red_arrow,unsigned char green_arrow,unsigned char blue_arrow,
		           float Umbral, float angCabeza, float lonCab, float magFlecha,
				   float **u,float **v,int x_init, int y_init, int x_interval_size, int y_interval_size, int median_filter_radius, int zoom)

{
	unsigned char *red_zoom,*green_zoom,*blue_zoom;
	int width_zoom_arrow=width;
	int height_zoom_arrow=height;
	long m,size=width*height;

	if(zoom<1) {printf("ERROR in ami_write_bmp_arrow_file(): zoom has to be bigger than 0\n"); return(-1);}

   /* WE ALLOCATE MEMORY FOR  ARROW IMAGE */
	ami_malloc1d(red_zoom,unsigned char,width*height);
	ami_malloc1d(green_zoom,unsigned char,width*height);
    ami_malloc1d(blue_zoom,unsigned char,width*height);

	/* WE COPY THE IMAGE IN THE ARROW IMAGE */
	for(m=0;m<size;m++){
		red_zoom[m]=red[m];
		green_zoom[m]=green[m];
		blue_zoom[m]=blue[m];
    }

    /* WE FILL THE IMAGE WITH ARROWS */
	ami_draw_optic_flow_arrow_zoom(&red_zoom,&green_zoom,&blue_zoom,&width_zoom_arrow,&height_zoom_arrow,red_arrow,green_arrow,blue_arrow,
	   Umbral,angCabeza,lonCab,magFlecha/zoom,u,v,x_init,y_init,x_interval_size,y_interval_size,median_filter_radius/zoom,zoom);
    //ami_draw_optic_flow_arrow_zoom(&red_zoom,&green_zoom,&blue_zoom,&height_zoom_arrow,&width_zoom_arrow,red_arrow,green_arrow,blue_arrow,
	   //Umbral,angCabeza,lonCab,magFlecha/zoom,u,v,x_init,y_init,x_interval_size,y_interval_size,median_filter_radius/zoom,zoom);

	/* WE SAVE THE IMAGE ON DISK */
    ami_write_bmp_inverse_rows(name,red_zoom,green_zoom,blue_zoom,width_zoom_arrow,height_zoom_arrow);
    
	/* WE FREE THE MEMORY */
    free(red_zoom); free(green_zoom); free(blue_zoom);
    return(0);
}


/**
	FUNCTION TO DRAW THE OPTIC FLOW ARROW FIELD SAME FUNCTION THAT ABOVE BUT INCLUDING 
	A zoom FACTOR TO ZOOM DOWN THE IMAGE BEFORE DRAWING THE ARROWS  
*/
void ami_draw_optic_flow_arrow_zoom(unsigned char **red,unsigned char **green,unsigned char **blue,int *width,int *height,
                   unsigned char red_arrow,unsigned char green_arrow,unsigned char blue_arrow,
		           float Umbral, float angCabeza, float lonCab, float magFlecha,
				   float **u,float **v,int x_init, int y_init, int x_interval_size, int y_interval_size, int median_filter_radius, int zoom)


{
  int i_min,i_max,j_min,j_max,i0,j0,i,j;
  float *um=NULL,*vm=NULL,u0,v0;
  unsigned char *red_p,*green_p,*blue_p;
  int width_p=(*width)/zoom;
  int height_p=(*height)/zoom;
  long m,size=width_p*height_p;

  /* WE ALLOCATE MEMORY FOR THE NEW IMAGE AND COPY THE INPUT IMAGE */
  if(zoom>1){
    ami_malloc1d(red_p,unsigned char,size);
    ami_malloc1d(green_p,unsigned char,size);
    ami_malloc1d(blue_p,unsigned char,size);
    for(i=0;i<height_p;i++){
	  for(j=0;j<width_p;j++){
	    red_p[i*width_p+j]=(*red)[i*zoom*(*width)+j*zoom];
	    green_p[i*width_p+j]=(*green)[i*zoom*(*width)+j*zoom];
	    blue_p[i*width_p+j]=(*blue)[i*zoom*(*width)+j*zoom];
	  }
    }
  }
  else{
   red_p=*red;
   green_p=*green;
   blue_p=*blue;
  }

  /* WE ALLOCATE MEMORY FOR VECTOR TO COMPUTE FLOW MEDIAN */
  if(median_filter_radius>0){
	ami_malloc1d(um,float, (2*median_filter_radius+1)*(2*median_filter_radius+1));
	ami_malloc1d(vm,float, (2*median_filter_radius+1)*(2*median_filter_radius+1));
  }
//printf("6:*width=%d, *height=%d, x_init=%d y_init=%d \n",*width,*height,x_init,y_init);
//printf("x_interval_size=%d, y_interval_size=%d\n",x_interval_size,y_interval_size);

  /* WE DRAW THE ARROWS IN THE IMAGE */
  for(i=y_init;i<(*height);i+=y_interval_size){
	for(j=x_init;j<(*width);j+=x_interval_size){
	  //printf("(%d,%d)\n",i,j);
	  /* WE COMPUTE A MEDIAN FILTER ON THE FLOW */
	  if(median_filter_radius>0){
		i_min=ami_max(0,(i-median_filter_radius));
		i_max=ami_min((*height-1),(i+median_filter_radius));
		j_min=ami_max(0,(j-median_filter_radius));
		j_max=ami_min((*width-1),(j+median_filter_radius));
		m=0;
		for(i0=i_min;i0<=i_max;i0++){
		  for(j0=j_min;j0<=j_max;j0++){
			um[m]=u[i0][j0];
			vm[m]=v[i0][j0];
			m++;
		  }
		}

        u0=ami_mediana_float(m/2,m,um);
		v0=ami_mediana_float(m/2,m,vm);
      }
	  else{
		u0=u[i][j];
		v0=v[i][j];
	  }
	  /* WE DRAW THE ARROW IN THE IMAGE */

	  //ami_draw_arrow(red_p,green_p,blue_p,width_p,height_p,red_arrow,green_arrow,blue_arrow,
                    // i/zoom,j/zoom,u0,v0,Umbral,angCabeza,lonCab,magFlecha);
      ami_draw_arrow(red_p,green_p,blue_p,width_p,height_p,red_arrow,green_arrow,blue_arrow,
                     i/zoom,j/zoom,u0,v0,Umbral,angCabeza,lonCab,magFlecha);

	}
  }

  /* WE FREE THE MEMORY */
  if(median_filter_radius>0){ free(um); free(vm); }
  if(zoom>1){
	  free(*red); free(*green); free(*blue);
      *red=red_p; *blue=blue_p; *green=green_p;
      *width=width_p; *height=height_p;
  }

}


/**
	FUNCTION TO EXTEND THE BOUNDARY OF AN IMAGE BY MIRRORING 

	\param v image matrix 
	\param height size in x direction 
	\param width size in y direction 
*/
void dummies

(float **v,        /* image matrix */
 long  height,     /* size in x direction */
 long  width)     /* size in y direction */

   /** creates dummy boundaries by mirroring */

{
  long i, j;  /* loop variables */

  for (i=1; i<=height; i++)
    {
      v[i][0]    = v[i][1];
      v[i][width+1] = v[i][width];
    }

  for (j=0; j<=width+1; j++)
    {
      v[0][j]    = v[1][j];
      v[height+1][j] = v[height][j];
    }
  return;
}

/* ---------------------------------------------------------------------- */

/*
	\param sigma standard deviation of Gaussian 
	\param height image dimension in x direction 
	\param width image dimension in y direction 
	\param hx pixel size in x direction 
	\param hy pixel size in y direction 
	\param precision cutoff at precision * sigma 
	\param bc type of boundary condition (0=Dirichlet, 1=reflecing, 2=periodic)
	\param f input: original image ;  output: smoothed
*/
void gauss_conv

(float    sigma,     /* standard deviation of Gaussian */
 long     height,        /* image dimension in x direction */
 long     width,        /* image dimension in y direction */
 float    hx,        /* pixel size in x direction */
 float    hy,        /* pixel size in y direction */
 float    precision, /* cutoff at precision * sigma */
 long     bc,        /* type of boundary condition */
 /* 0=Dirichlet, 1=reflecing, 2=periodic */
 float    **f)       /* input: original image ;  output: smoothed */


     /**
	Gaussian convolution.
     */


{
  long    i, j, p;              /* loop variables */
  long    length;               /* convolution vector: 0..length */
  float   sum;                  /* for summing up */
  float   *conv;                /* convolution vector */
  float   *help;                /* row or column with dummy boundaries */


  /* ------------------------ diffusion in x direction -------------------- */

  /* calculate length of convolution vector */
  length = (long)(precision * sigma / hx) + 1;
  if ((bc != 0) && (length > height))
    {
      printf("gauss_conv: sigma too large \n");
      exit(0);
    }

/* allocate storage for convolution vector */
  ami_malloc1d (conv, float,length+1);

  /* calculate entries of convolution vector */
  for (i=0; i<=length; i++)
    conv[i] = 1 / (sigma * sqrt(2.0 * 3.1415926))
      * exp (- (i * i * hx * hx) / (2.0 * sigma * sigma));

  /* normalization */
  sum = conv[0];
  for (i=1; i<=length; i++)
    sum = sum + 2.0 * conv[i];
  for (i=0; i<=length; i++)
    conv[i] = conv[i] / sum;

  /* allocate storage for a row */
  ami_malloc1d (help, float,height+length+length);

  for (j=1; j<=width; j++)
    {
    /* copy in row vector */
      for (i=1; i<=height; i++)
        help[i+length-1] = f[i][j];

      /* assign boundary conditions */
      if (bc == 0) /* Dirichlet boundary conditions */
	for (p=1; p<=length; p++)
	  {
	    help[length-p]      = 0.0;
	    help[height+length-1+p] = 0.0;
	  }
      else if (bc == 1) /* reflecting b.c. */
	for (p=1; p<=length; p++)
	  {
	    help[length-p]      = help[length+p-1];
	    help[height+length-1+p] = help[height+length-p];
	  }
      else if (bc == 2) /* periodic b.c. */
	for (p=1; p<=length; p++)
	  {
           help[length-p]      = help[height+length-p];
           help[height+length-1+p] = help[length+p-1];
           }

      /* convolution step */
      for (i=length; i<=height+length-1; i++)
        {
	  /* calculate convolution */
	  sum = conv[0] * help[i];
	  for (p=1; p<=length; p++)
            sum = sum + conv[p] * (help[i+p] + help[i-p]);
	  /* write back */
        f[i-length+1][j] = sum;
        }
    } /* for j */

  /* disallocate storage for a row */
  free(help);

  /* disallocate convolution vector */
  free(conv);

  /* ------------------------ diffusion in y direction -------------------- */

  /* calculate length of convolution vector */
  length = (long)(precision * sigma / hy) + 1;
  if ((bc != 0) && (length > width))
    {
      printf("gauss_conv: sigma too large \n");
      exit(0);
    }

  /* allocate storage for convolution vector */
  ami_malloc1d (conv,float, length + 1);

  /* calculate entries of convolution vector */
  for (j=0; j<=length; j++)
    conv[j] = 1 / (sigma * sqrt(2.0 * 3.1415927))
      * exp (- (j * j * hy * hy) / (2.0 * sigma * sigma));

  /* normalization */
  sum = conv[0];
  for (j=1; j<=length; j++)
    sum = sum + 2.0 * conv[j];
  for (j=0; j<=length; j++)
    conv[j] = conv[j] / sum;

  /* allocate storage for a row */
  ami_malloc1d (help, float,width+length+length);

  for (i=1; i<=height; i++)
    {
      /* copy in column vector */
      for (j=1; j<=width; j++)
        help[j+length-1] = f[i][j];

      /* assign boundary conditions */
      if (bc == 0) /* Dirichlet boundary conditions */
	for (p=1; p<=length; p++)
	  {
	    help[length-p]      = 0.0;
	    help[width+length-1+p] = 0.0;
	  }
      else if (bc == 1) /* reflecting b.c. */
	for (p=1; p<=length; p++)
	  {
	    help[length-p]      = help[length+p-1];
	    help[width+length-1+p] = help[width+length-p];
	  }
      else if (bc == 2) /* periodic b.c. */
	for (p=1; p<=length; p++)
	  {
           help[length-p]      = help[width+length-p];
           help[width+length-1+p] = help[length+p-1];
	  }

      /* convolution step */
      for (j=length; j<=width+length-1; j++)
        {
	  /* calculate convolution */
	  sum = conv[0] * help[j];
	  for (p=1; p<=length; p++)
            sum = sum + conv[p] * (help[j+p] + help[j-p]);
	  /* write back */
	  f[i][j-length+1] = sum;
        }
    } /* for i */

  /* disallocate storage for a row */
  free (help);

  /* disallocate convolution vector */
  free (conv);

  return;

} /* gauss_conv */

/* ------------------------------------------------------------------------ */

/*
	\param dtype type of smoothness term 
	\param fx x derivative of image, unchanged 
	\param fy y derivative of image, unchanged 
	\param uv x component of flow, unchanged 
	\param height image dimension in x direction 
	\param width image dimension in y direction 
	\param hx pixel size in x direction 
	\param hy pixel size in y direction 
	\param lambda contrast parameter 
	\param d11 component [1,1] of diffusion tensor, output 
	\param d12 component [1,2] of diffusion tensor, output 
	\param d22 component [2,2] of diffusion tensor, output 
*/
void diffusion_tensor

     (long     dtype,       /* type of smoothness term */
      float    **fx,        /* x derivative of image, unchanged */
      float    **fy,        /* y derivative of image, unchanged */
      float    **uv,         /* x component of flow, unchanged */
      long     height,          /* image dimension in x direction */
      long     width,          /* image dimension in y direction */
      float    hx,          /* pixel size in x direction */
      float    hy,          /* pixel size in y direction */
      float    lambda,      /* contrast parameter */
      float    **d11,       /* component [1,1] of diffusion tensor, output */
      float    **d12,       /* component [1,2] of diffusion tensor, output */
      float    **d22)       /* component [2,2] of diffusion tensor, output */

/**
 Calculates diffusion tensor according to the type of the smoothness term.
*/

{
long    i, j;            /* loop variables */
float   weight;          /* time saver */
float   grad_sqr,grad_sqr1;        /* time saver */
float   lambda_sqr;      /* time saver */
float   two_hx, two_hy;  /* time savers */
float   ux, uy;  /* flow derivatives */

lambda_sqr = lambda * lambda;

if (dtype == 0)
   /* Horn/Schunck */
   for (i=1; i<=height; i++)
    for (j=1; j<=width; j++)
        {
        d11[i][j] = 1.0;
        d12[i][j] = 0.0;
        d22[i][j] = 1.0;
        }

if (dtype == 1)
   /* image driven, isotropic */
   for (i=1; i<=height; i++)
    for (j=1; j<=width; j++)
        {
        grad_sqr  = fx[i][j] * fx[i][j] + fy[i][j] * fy[i][j];
        d11[i][j] = 1.0 / sqrt (1.0 + grad_sqr / lambda_sqr);
        d12[i][j] = 0.0;
        d22[i][j] = d11[i][j];
        }

if (dtype == 2)
   /* image driven, anisotropic (Nagel) */
   for (i=1; i<=height; i++)
    for (j=1; j<=width; j++)
        {
        grad_sqr  = fx[i][j] * fx[i][j] + fy[i][j] * fy[i][j];
        weight    = 1.0 / (grad_sqr + 2.0 * lambda_sqr);
        d11[i][j] =   weight * (lambda_sqr + fy[i][j] * fy[i][j]);
        d12[i][j] = - weight * fx[i][j] * fy[i][j];
        d22[i][j] =   weight * (lambda_sqr + fx[i][j] * fx[i][j]);
        }

/*if (dtype == 3)*/
   /* flow driven, isotropic */
/*   {
   two_hx = 2.0 * hx;
   two_hy = 2.0 * hy;
   dummies (u, height, width);
   dummies (v, height, width);
   for (i=1; i<=height; i++)
    for (j=1; j<=width; j++)
        {
        ux = (u[i+1][j] - u[i-1][j]) / two_hx;
        uy = (u[i][j+1] - u[i][j-1]) / two_hy;
        vx = (v[i+1][j] - v[i-1][j]) / two_hx;
        vy = (v[i][j+1] - v[i][j-1]) / two_hy;
        grad_sqr = ux * ux + uy * uy + vx * vx + vy * vy;
        d11[i][j] = 1.0 / sqrt (1.0 + grad_sqr / lambda_sqr);
        d12[i][j] = 0.0;
        d22[i][j] = d11[i][j];
        }
   }
*/

if (dtype == 3)
   /* flow driven, isotropic */
   {
   two_hx = 2.0 * hx;
   two_hy = 2.0 * hy;
   dummies (uv, height, width);
   for (i=1; i<=height; i++)
    for (j=1; j<=width; j++)
        {
        grad_sqr1  = fx[i][j] * fx[i][j] + fy[i][j] * fy[i][j];
        ux = (uv[i+1][j] - uv[i-1][j]) / two_hx;
        uy = (uv[i][j+1] - uv[i][j-1]) / two_hy;
        grad_sqr = ux * ux + uy * uy;
        d11[i][j] = 1.0 / sqrt (1.0 + grad_sqr1 / lambda_sqr)*1.0 / sqrt (1.0 + grad_sqr / lambda_sqr);
        d12[i][j] = 0.0;
        d22[i][j] = d11[i][j];
        }
   }

return;

} /* diffusion_tensor */

/* ------------------------------------------------------------------------ */

/*
	\param f image, unchanged 
	\param u x component of optic flow, unchanged 
	\param v v component of optic flow, unchanged 
	\param height image dimension in x direction 
	\param width image dimension in y direction 
	\param fs f shifted by (u,v) and interpolated, output 
*/
void interpolation

     (float    **f,         /* image, unchanged */
      float    **u,         /* x component of optic flow, unchanged */
      float    **v,         /* v component of optic flow, unchanged */
      long     height,          /* image dimension in x direction */
      long     width,          /* image dimension in y direction */
      float    **fs)        /* f shifted by (u,v) and interpolated, output */

/**
 shifts input image f by optic flow vector (u,v) and interpolates linearly
*/

{
long    i, j;             /* loop variables */
long    i1, i2, j1, j2;   /* indices of 4 nearest neighbours */
float   x, y;             /* shifted coordinates */
float   alpha, beta;      /* interpolation weights */

dummies (f, height, width);
for (i=1; i<=height; i++)
 for (j=1; j<=width; j++)
     {
     /* calculate corresponding value (x,y) for pixel (i,j) */
     x = (float) i + u[i][j];
     y = (float) j + v[i][j];
     /* boundary modifications */
     if (x < 1)  x = 1;
     if (y < 1)  y = 1;
     if (x > height) x = height;
     if (y > width) y = width;
     /* find indices of 4 closest neighbours */
     i1 = (long) (x - 0.4999999);
     i2 = i1 + 1;
     j1 = (long) (y - 0.4999999);
     j2 = j1 + 1;
     /* linear interpolation */
     alpha = x - (float) i1;
     beta  = y - (float) j1;
     fs[i][j] = (1.0 - alpha) * (1.0 - beta) * f[i1][j1]
              + alpha         * (1.0 - beta) * f[i2][j1]
              + (1.0 - alpha) * beta         * f[i1][j2]
              + alpha         * beta         * f[i2][j2];
     }
return;

} /* interpolation */


/*
	\param ht time step size, 0 < ht <= 0.25 
	\param height image dimension in x direction 
	\param width image dimension in y direction 
	\param hx pixel size in x direction 
	\param hy pixel size in y direction 
	\param f1 f1 image, unchanged 
	\param f2s f2 image shifted by flow, unchanged 
	\param f2xs x derivative of f2, shifted by flow, unchanged 
	\param f2ys y derivative of f2, shifted by flow, unchanged 
	\param dxx diffusion tensor element [1,1], unchanged 
	\param dxy diffusion tensor element [1,2], unchanged 
	\param dyy diffusion tensor element [2,2], unchanged 
	\param alpha smoothness weight 
	\param u x component of optic flow, changed 
	\param v v component of optic flow, changed 
	\param Niter Number of iterations for Gauss-Seidel 
	\param f1x Image derivative 
	\param f1y Image derivatice 
*/
int relax_2

     (float    ht,          /* time step size, 0 < ht <= 0.25 */
      long     height,          /* image dimension in x direction */
      long     width,          /* image dimension in y direction */
      float    hx,          /* pixel size in x direction */
      float    hy,          /* pixel size in y direction */
      float    **f1,        /* f1 image, unchanged */
      float    **f2s,       /* f2 image shifted by flow, unchanged */
      float    **f2xs,      /* x derivative of f2, shifted by flow, unchanged */
      float    **f2ys,      /* y derivative of f2, shifted by flow, unchanged */
      float    **dxx,       /* diffusion tensor element [1,1], unchanged */
      float    **dxy,       /* diffusion tensor element [1,2], unchanged */
      float    **dyy,       /* diffusion tensor element [2,2], unchanged */
      float    alpha,       /* smoothness weight */
      float    **u,         /* x component of optic flow, changed */
      float    **v,         /* v component of optic flow, changed */
      int Niter,            /* Number of iterations for Gauss-Seidel */
      float **f1x,          /* Image derivative */
      float **f1y)          /* Image derivatice */


/**
 Optic flow iteration by regarding it as a coupled system of
 two nonlinear diffusion-reaction equations with a common
 diffusion tensor.
*/

{
long     i, j, k;                 /* loop variables */
float error;
/*float   **u1, **v1;           intermediate results */
float   help, rxx, rxy, ryy;  /* time savers */
float   **wN, **wNE, **wE, **wSE;     /* weights */
float   **wS, **wSW, **wW, **wNW;     /* weights */
float   **Den;		      /* Denominator of implicit scheme */
float   Gneig;		      /* Value of neighbours */
float   **Fuk, **Fvk;	      /* Second term of diffusion equations F(uk,vk) */
float   **norm,normmax=0;

/* ---- allocate storage ---- */

/*ami_malloc2d (u1, float,height+2, width+2);
ami_malloc2d (v1, float,height+2, width+2);*/
ami_malloc2d (wN, float,height+2, width+2);
ami_malloc2d (wNE,float, height+2, width+2);
ami_malloc2d (wE, float,height+2, width+2);
ami_malloc2d (wSE, float,height+2, width+2);
ami_malloc2d (wS, float,height+2, width+2);
ami_malloc2d (wSW, float,height+2, width+2);
ami_malloc2d (wW, float,height+2, width+2);
ami_malloc2d (wNW,float, height+2, width+2);
ami_malloc2d (Den, float,height+2, width+2);
ami_malloc2d (Fuk, float,height+2, width+2);
ami_malloc2d (Fvk,float, height+2, width+2);
ami_malloc2d (norm,float, height+2, width+2);


/* Computation of the norm of the gradient of I1 */

for(i=1;i<=height;i++)
  for(j=1;j<=width;j++){
    norm[i][j]=f1x[i][j]*f1x[i][j]+f1y[i][j]*f1y[i][j];
    if(norm[i][j]>normmax) normmax=norm[i][j];
  }
if(normmax>0){
/*  normmax*=normmax; */
  normmax=1./normmax;
  for(i=1;i<=height;i++)
   for(j=1;j<=width;j++)
    norm[i][j]=normmax;
  }

/* ---- copy u, v into u1, v1 ---- */

/*for (i=1; i<=height; i++)
 for (j=1; j<=width; j++)
 {
     u1[i][j] = u[i][j];
     v1[i][j] = v[i][j];
 }

*/
/* ---- time savers ---- */

help = ht / alpha;
rxx  = ht / (2.0 * hx * hx);
ryy  = ht / (2.0 * hy * hy);
rxy  = ht / (4.0 * hx * hy);


/* ---- dummy boundaries ---- */

/*dummies (u1,  height, width);
dummies (v1,  height, width);*/
dummies (dxx, height, width);
dummies (dxy, height, width);
dummies (dyy, height, width);

/* weight matrices */
for (i=1; i<=height; i++)
  for (j=1; j<=width; j++){
     /* weights */
     wE[i][j]  =   rxx * (dxx[i+1][j]   + dxx[i][j]);
     wW[i][j]  =   rxx * (dxx[i-1][j]   + dxx[i][j]);
     wS[i][j]  =   ryy * (dyy[i][j+1]   + dyy[i][j]);
     wN[i][j]  =   ryy * (dyy[i][j-1]   + dyy[i][j]);
     wSE[i][j] =   rxy * (dxy[i+1][j+1] + dxy[i][j]);
     wNW[i][j] =   rxy * (dxy[i-1][j-1] + dxy[i][j]);
     wNE[i][j] = - rxy * (dxy[i+1][j-1] + dxy[i][j]);
     wSW[i][j] = - rxy * (dxy[i-1][j+1] + dxy[i][j]);

     /* boundary correction of weights */
     if (i==1)  wSW[i][j] = wW[i][j] = wNW[i][j] = 0.0;
     if (i==height) wNE[i][j] = wE[i][j] = wSE[i][j] = 0.0;
     if (j==1)  wNW[i][j] = wN[i][j] = wNE[i][j] = 0.0;
     if (j==width) wSE[i][j] = wS[i][j] = wSW[i][j] = 0.0;

     /* computation of the influence of previous instant for u[i,j] */
     Fuk[i][j]= (help*norm[i][j] * (f1[i][j] - f2s[i][j] + u[i][j] * f2xs[i][j]
		    + v[i][j] * f2ys[i][j]) * f2xs[i][j]) + u[i][j];

     /* computation of the influence of previous instant for v[i,j] */
     Fvk[i][j]= (help*norm[i][j] * (f1[i][j] - f2s[i][j] + u[i][j] * f2xs[i][j]
		    + v[i][j] * f2ys[i][j]) * f2ys[i][j]) + v[i][j];

     /* Denominator of implicit scheme */
     Den[i][j]=1.+ wE[i][j] + wW[i][j] + wS[i][j] + wN[i][j] + wSE[i][j]
	    + wNW[i][j] + wSW[i][j] + wNE[i][j];
  }


dummies (wN, height, width);
dummies (wNE, height, width);
dummies (wE, height, width);
dummies (wSE, height, width);
dummies (wS, height, width);
dummies (wSW, height, width);
dummies (wW, height, width);
dummies (wNW, height, width);
dummies (Den, height, width);
dummies (Fuk, height, width);
dummies (Fvk, height, width);


/* ---- evolution ---- */
k=0;
error=1.;
while(k<Niter || error>0.1){
 dummies (u, height, width);
 dummies (v, height, width);
 error=0;


 /* first pass from left right and up to bottom */
 /* printf("-- First pass   "); */
 for (i=1; i<=height; i++)
  for (j=1; j<=width; j++)
     {
       float paso=u[i][j];

     /* Diffusion of the first equation. Computation of the neighbours */
     Gneig= wE[i][j] * u[i+1][j]
               + wW[i][j]  *  u[i-1][j]
               + wS[i][j]  *  u[i][j+1]
               + wN[i][j]  *  u[i][j-1]
               + wSE[i][j] *  u[i+1][j+1]
               + wNW[i][j] *  u[i-1][j-1]
               + wSW[i][j] *  u[i-1][j+1]
               + wNE[i][j] *  u[i+1][j-1];

     /* diffusing */
     u[i][j]= (Gneig + Fuk[i][j] - help*norm[i][j]*v[i][j]*f2xs[i][j]*f2ys[i][j])
		/(Den[i][j] + help *norm[i][j]* f2xs[i][j]*f2xs[i][j]);
     if((i>15 && i<(height-15) && j>15 && j<(width-15)) && ABS(u[i][j]-paso)>error) error=ABS(u[i][j]-paso);


     /* Diffusion of the second equation. Computation of the neighbours */
     paso=v[i][j];
     Gneig= wE[i][j]  *  v[i+1][j]
               + wW[i][j]  *  v[i-1][j]
               + wS[i][j]  *  v[i][j+1]
               + wN[i][j]  *  v[i][j-1]
               + wSE[i][j] *  v[i+1][j+1]
               + wNW[i][j] *  v[i-1][j-1]
               + wSW[i][j] *  v[i-1][j+1]
               + wNE[i][j] *  v[i+1][j-1];


     /* diffusing */
     v[i][j]= (Gneig + Fvk[i][j] - help*norm[i][j]*u[i][j]*f2xs[i][j]*f2ys[i][j])
		/(Den[i][j] + help *norm[i][j]* f2ys[i][j]*f2ys[i][j]);

     if((i>15 && i<(height-15) && j>15 && j<(width-15)) && ABS(v[i][j]-paso)>error) error=ABS(v[i][j]-paso);
 }



 /* Second pass from right left and bottom up*/
 /* printf("-- Second pass\n"); */
 for (i=height; i>=1; i--)
  for (j=width; j>=1; j--)
     {

     float paso=v[i][j];
     /* Diffusion of the second equation. Computation of the neighbours */
     Gneig= wE[i][j]  *  v[i+1][j]
               + wW[i][j]  *  v[i-1][j]
               + wS[i][j]  *  v[i][j+1]
               + wN[i][j]  *  v[i][j-1]
               + wSE[i][j] *  v[i+1][j+1]
               + wNW[i][j] *  v[i-1][j-1]
               + wSW[i][j] *  v[i-1][j+1]
               + wNE[i][j] *  v[i+1][j-1];


     /* diffusing */
     v[i][j]= (Gneig + Fvk[i][j] - help*norm[i][j]*u[i][j]*f2xs[i][j]*f2ys[i][j])
		/(Den[i][j] + help *norm[i][j]* f2ys[i][j]*f2ys[i][j]);

     if(ABS(v[i][j]-paso)>error) error=ABS(v[i][j]-paso);


     /* Diffusion of the first equation. Computation of the neighbours */
     paso=u[i][j];
     Gneig= wE[i][j] * u[i+1][j]
               + wW[i][j]  *  u[i-1][j]
               + wS[i][j]  *  u[i][j+1]
               + wN[i][j]  *  u[i][j-1]
               + wSE[i][j] *  u[i+1][j+1]
               + wNW[i][j] *  u[i-1][j-1]
               + wSW[i][j] *  u[i-1][j+1]
               + wNE[i][j] *  u[i+1][j-1];

     /* diffusing */
     u[i][j]= (Gneig + Fuk[i][j] - help*norm[i][j]*v[i][j]*f2xs[i][j]*f2ys[i][j])
		/(Den[i][j] + help *norm[i][j]* f2xs[i][j]*f2xs[i][j]);

     if(ABS(u[i][j]-paso)>error) error=ABS(u[i][j]-paso);

 }

 k++;
 //printf("k=%d, error=%f\n",(int)k,error);
}


/* ---- disallocate storage ---- */

/*ami_free2d (u1);
ami_free2d (v1);
*/

ami_free2d (wN);
ami_free2d (wNE);
ami_free2d (wE);
ami_free2d (wSE);
ami_free2d (wS);
ami_free2d (wSW);
ami_free2d (wW);
ami_free2d (wNW);
ami_free2d (Den);
ami_free2d (Fuk);
ami_free2d (Fvk);
ami_free2d (norm);

 return(k);
} /* relax */


/* ---------------------------------------------------------------------- */

/*
	\param height image dimension in x direction 
	\param width image dimension in y direction 
	\param hx pixel size in x direction 
	\param hy pixel size in y direction 
	\param f1 f2 image, unchanged 
	\param f2s f2 image shifted by flow, unchanged 
	\param f2xs x derivative of f2, shifted by flow, unchanged 
	\param f2ys y derivative of f2, shifted by flow, unchanged 
	\param dxx diffusion tensor element [1,1], unchanged 
	\param dxy diffusion tensor element [1,2], unchanged 
	\param dyy diffusion tensor element [2,2], unchanged 
	\param alpha smoothness weight 
	\param u x component of optic flow, unchanged 
	\param v v component of optic flow, unchanged 
	\param err L2 norm of residue, output
*/
void L2_residue

     (long     height,          /* image dimension in x direction */
      long     width,          /* image dimension in y direction */
      float    hx,          /* pixel size in x direction */
      float    hy,          /* pixel size in y direction */
      float    **f1,        /* f2 image, unchanged */
      float    **f2s,       /* f2 image shifted by flow, unchanged */
      float    **f2xs,      /* x derivative of f2, shifted by flow, unchanged */
      float    **f2ys,      /* y derivative of f2, shifted by flow, unchanged */
      float    **dxx,       /* diffusion tensor element [1,1], unchanged */
      float    **dxy,       /* diffusion tensor element [1,2], unchanged */
      float    **dyy,       /* diffusion tensor element [2,2], unchanged */
      float    alpha,       /* smoothness weight */
      float    **u,         /* x component of optic flow, unchanged */
      float    **v,         /* v component of optic flow, unchanged */
      float    *err)        /* L2 norm of residue, output */

/**
 calculates L2 norm of residue, divided by pixel number
*/

{
long    i, j;                 /* loop variables */
float   res;                  /* time saver */
float   help;                 /* time saver */
float   rxx, rxy, ryy;        /* time savers */
float   wN, wNE, wE, wSE;     /* weights */
float   wS, wSW, wW, wNW;     /* weights */


/* ---- calculates L2 norms of RHS and residue ---- */

dummies (u,   height, width);
dummies (v,   height, width);
dummies (dxx, height, width);
dummies (dxy, height, width);
dummies (dyy, height, width);

rxx  = 1.0 / (2.0 * hx * hx);
ryy  = 1.0 / (2.0 * hy * hy);
rxy  = 1.0 / (4.0 * hx * hy);

res = 0.0;

for (i=1; i<=height; i++)
 for (j=1; j<=width; j++)
     {
     /* weights */
     wE  =   rxx * (dxx[i+1][j]   + dxx[i][j]);
     wW  =   rxx * (dxx[i-1][j]   + dxx[i][j]);
     wS  =   ryy * (dyy[i][j+1]   + dyy[i][j]);
     wN  =   ryy * (dyy[i][j-1]   + dyy[i][j]);
     wSE =   rxy * (dxy[i+1][j+1] + dxy[i][j]);
     wNW =   rxy * (dxy[i-1][j-1] + dxy[i][j]);
     wNE = - rxy * (dxy[i+1][j-1] + dxy[i][j]);
     wSW = - rxy * (dxy[i-1][j+1] + dxy[i][j]);

     /* boundary correction of weights */
     if (i==1)  wSW = wW = wNW = 0.0;
     if (i==height) wNE = wE = wSE = 0.0;
     if (j==1)  wNW = wN = wNE = 0.0;
     if (j==width) wSE = wS = wSW = 0.0;

     help =   wE  *  (u[i+1][j]   - u[i][j])
            + wW  *  (u[i-1][j]   - u[i][j])
            + wS  *  (u[i][j+1]   - u[i][j])
            + wN  *  (u[i][j-1]   - u[i][j])
            + wSE *  (u[i+1][j+1] - u[i][j])
            + wNW *  (u[i-1][j-1] - u[i][j])
            + wSW *  (u[i-1][j+1] - u[i][j])
            + wNE *  (u[i+1][j-1] - u[i][j])
            + (f1[i][j] - f2s[i][j]) * f2xs[i][j] / alpha;

     res  = res + help * help;

     help =   wE  *  (v[i+1][j]   - v[i][j])
            + wW  *  (v[i-1][j]   - v[i][j])
            + wS  *  (v[i][j+1]   - v[i][j])
            + wN  *  (v[i][j-1]   - v[i][j])
            + wSE *  (v[i+1][j+1] - v[i][j])
            + wNW *  (v[i-1][j-1] - v[i][j])
            + wSW *  (v[i-1][j+1] - v[i][j])
            + wNE *  (v[i+1][j-1] - v[i][j])
            + (f1[i][j] - f2s[i][j]) * f2ys[i][j] / alpha;

     res  = res + help * help;
     }

*err = sqrt(res) / (height * width);

return;

} /* L2_residue */

/*--------------------------------------------------------------------------*/

/*
	\param u image, unchanged 
	\param height pixel number in x direction 
	\param width pixel number in x direction 
	\param min minimum, output 
	\param max maximum, output 
	\param mean mean, output 
	\param vari variance, output 
*/
void analyse

     (float   **u,         /* image, unchanged */
      long    height,          /* pixel number in x direction */
      long    width,          /* pixel number in x direction */
      float   *min,        /* minimum, output */
      float   *max,        /* maximum, output */
      float   *mean,       /* mean, output */
      float   *vari)       /* variance, output */

/*
 calculates minimum, maximum, mean and variance of an image u
*/

{
long    i, j;       /* loop variables */
float   help;       /* auxiliary variable */
double  help2;      /* auxiliary variable */

*min  = u[1][1];
*max  = u[1][1];
help2 = 0.0;
for (i=1; i<=height; i++)
 for (j=1; j<=width; j++)
     {
     if (u[i][j] < *min) *min = u[i][j];
     if (u[i][j] > *max) *max = u[i][j];
     help2 = help2 + (double)u[i][j];
     }
*mean = (float)help2 / (height * width);

*vari = 0.0;
for (i=1; i<=height; i++)
 for (j=1; j<=width; j++)
     {
     help  = u[i][j] - *mean;
     *vari = *vari + help * help;
     }
*vari = *vari / (height * width);

return;

} /* analyse */

/*--------------------------------------------------------------------------*/

#define SWAP2(a,b) {temp=(a); (a)=(b); (b)=temp;}


/**
	\param k k-th smallest value 
	\param n size of R: 1..n 
	\param arr array, changed on output 
*/
float select2

     (unsigned long   k,         /* k-th smallest value */
      unsigned long   n,         /* size of R: 1..n */
      float           *arr)      /* array, changed on output */

/**
 Returns the k-th smallest value in the array R[1..n]. The input
 array will be rearranged to have this value in location R[k], with all
 smaller elements moved to R[1..k-1] (in arbitrary order) and all
 larger elements in R[k+1..n] (also in arbitrary order).
 Ref.: Press et al.: Numerical recipes in C. Second Edition, Chapter 8,
       Cambridge University Press, 1992.
       http://cfatab.harvard.edu/nr/bookc.html
*/

{
unsigned long  i, ir, j, l, mid=0;
float          a, temp;

l=1;
ir=n;
for (;;)
    {
    if (ir <= l+1)
       {
       if (ir == l+1 && arr[ir] < arr[l])
          SWAP2(arr[mid],arr[l+1]);
       return arr[k];
       }
    else
       {
       mid=(l+ir) >> 1;
       SWAP2(arr[mid],arr[l+1]);
       if (arr[l+1] > arr[ir])
          SWAP2(arr[l+1],arr[ir]);
       if (arr[l] > arr[ir])
          SWAP2(arr[l],arr[ir]);
       if (arr[l+1] > arr[l])
          SWAP2(arr[l+1],arr[l]);
       i=l+1;
       j=ir;
       a=arr[l];
       for (;;)
           {
           do i++; while (arr[i] < a);
           do j--; while (arr[j] > a);
           if (j < i) break;
	   SWAP2(arr[i],arr[j]);
	   }
       arr[l]=arr[j];
       arr[j]=a;
       if (j >= k) ir=j-1;
       if (j <= k) l=i;
       } /* else */
    } /* for */

return 0;
}

#undef SWAP2


/*--------------------------------------------------------------------------*/

/**
	\param fx image derivative, unchanged 
	\param fy image derivative, unchanged 
	\param height pixel number in x direction 
	\param width pixel number in y direction 
	\param hx pixel size in x direction 
	\param hy pixel size in y direction 
	\param quantile fraction of gradients <= lambda 
	\param check verbose mode for check==1 
	\param lambda contrast parameter, output 
*/
void find_lambda

     (float  **fx,      /* image derivative, unchanged */
      float  **fy,      /* image derivative, unchanged */
      long   height,        /* pixel number in x direction */
      long   width,        /* pixel number in y direction */
      float  hx,        /* pixel size in x direction */
      float  hy,        /* pixel size in y direction */
      float  quantile,  /* fraction of gradients <= lambda */
      long   check,     /* verbose mode for check==1 */
      float  *lambda)   /* contrast parameter, output */

/**
  determines the contrast parameter lambda in such a way that
  the fraction quantile of gradients is smaller than lambda
*/


{
long    i, j, k;           /* loop variables */
//long m;
//float   help;                 /* result for lambda */
float   *w;                   /* coherence of f in each pixel */


//if (check == 1) printf("adapting lambda\n");


/* ---- allocate storage ---- */

ami_malloc1d (w, float,height * width + 1);


/* ---- calculate coherence vector w #include <stdlib.h>
#include <stdio.h>
---- */

k = 0;
for (i=1; i<=height; i++)
 for (j=1; j<=width; j++)
     {
     k = k + 1;
     w[k] = sqrt (fx[i][j] * fx[i][j] + fy[i][j] * fy[i][j]);
     }


/* ---- determine lambda by means of a w-histogramme ---- */

k = (long) (quantile * height * width);
if (k < 1) k = 1;
*lambda = select2 (k, height * width, w)+0.01;
// if (check == 1) printf("lambda:  %14.2f \n\n", *lambda);


/* ---- disallocate storage ---- */

free (w);

return;

} /* find_lambda */

/*--------------------------------------------------------------------------*/

/** 
	\param height image dimension in x direction 
	\param width image dimension in y direction 
	\param hx pixel size in x direction 
	\param hy pixel size in y direction 
	\param ff1 first image, unchanged 
	\param ff2 second image, unchanged 
	\param sigma Gaussian scale smoothing image data 
	\param T stopping time 
	\param alpha smoothness weight 
	\param dtype type of smoothness term 
	\param quantile isotropy fraction 
	\param ht convergence bound for relative residue 
	\param u x component of optic flow, changed 
	\param v y component of optic flow, changed 
	\param Niter Number of Iterations for Gauss-Seidel 
*/

void optic_flow

     (long     height,          /* image dimension in x direction */
      long     width,          /* image dimension in y direction */
      float    hx,          /* pixel size in x direction */
      float    hy,          /* pixel size in y direction */
      float    **ff1,       /* first image, unchanged */
      float    **ff2,       /* second image, unchanged */
      float    sigma,       /* Gaussian scale smoothing image data */
      float    T,           /* stopping time */
      float    alpha,       /* smoothness weight */
      long     dtype,       /* type of smoothness term */
      float    quantile,    /* isotropy fraction */
      float    ht,          /* convergence bound for relative residue */
      float    **u,         /* x component of optic flow, changed */
      float    **v,         /* y component of optic flow, changed */
      int Niter)            /* Number of Iterations for Gauss-Seidel */

/**
 This procedures
 - determines a heuristic upper bound for the step size ht
 - iterates as long as the L2 norm of the residue is decreasing
   and above a specified fraction of the L2 norm of the initial
   residue
 - creates the following outputs:
   if precision reached: new flow estimates
   if nonconvergent:     initial flow
   convergence behaviour is described in variable "converged"
*/

{
long   i, j;                    /* loop variables */
float  t;                       /* time */
//float  vari0;                   /* minimum, maximum, mean of initial flow magnitude */
float  **f1, **f2;              /* tsmoothed versions of images ff1, ff2 */
float  **f2s, **f2xs, **f2ys;   /* translation of f1, f1x, f1y by flow (u,v) */
float  **du11, **du12, **du22;  /* diffusion tensor components for flow u*/
float  **dv11, **dv12, **dv22;  /* diffusion tensor components for flow v*/
float  **f1x, **f1y;            /* image derivatives */
float  **f2x, **f2y;            /* image derivatives */
float  **u0, **v0;              /* initial optic flow components */
float  lambda;                  /* contrast parameter */
//float  help;                    /* time saver */
//float  maxgrad;                 /* max (|f1x|, |f1y|) over all pixels */
//int ii,jj;
int krelax;
double SQRT_2=sqrt((double) 2.);
double NORM=1./(4.+sqrt((double) 8.));


/* allocate storage */
ami_malloc2d (f1,  float, height+2, width+2);
ami_malloc2d (f2,  float, height+2, width+2);
ami_malloc2d (f1x, float, height+2, width+2);
ami_malloc2d (f1y, float, height+2, width+2);
ami_malloc2d (f2x, float, height+2, width+2);
ami_malloc2d (f2y, float, height+2, width+2);
ami_malloc2d (f2s, float, height+2, width+2);
ami_malloc2d (f2xs, float,height+2, width+2);
ami_malloc2d (f2ys,float, height+2, width+2);
ami_malloc2d (du11, float, height+2, width+2);
ami_malloc2d (du12, float, height+2, width+2);
ami_malloc2d (du22, float, height+2, width+2);
ami_malloc2d (dv11,  float,height+2, width+2);
ami_malloc2d (dv12, float, height+2, width+2);
ami_malloc2d (dv22, float, height+2, width+2);
ami_malloc2d (u0,  float, height+2, width+2);
ami_malloc2d (v0, float,  height+2, width+2);

/* create copies of initial flow data */
for (i=1; i<=height; i++)
 for (j=1; j<=width; j++)
     {
     u0[i][j] = u[i][j];
     v0[i][j] = v[i][j];
     f1[i][j] = ff1[i][j];
     f2[i][j] = ff2[i][j];
     }

/* Gaussian smoothing */
if (sigma > 0.0)
   {

      gauss_conv (sigma, height, width, hx, hy, 5.0, 1, f1);
      gauss_conv (sigma, height, width, hx, hy, 5.0, 1, f2);

   }

/* calculate image derivatives f1x, f1y */
dummies (f1, height, width);
dummies (f2, height, width);
for (i=1; i<=height; i++)
 for (j=1; j<=width; j++)
  {
   if(/*i==1 || j==1 || i==height || j==width ||
      i==2 || j==2 || i==height-1 || j==width-1 ||
      i==3 || j==3 || i==height-2 || j==width-2 */ 2==3){
       f2x[i][j]=f2y[i][j]=0.;
   }
   else{
     f1x[i][j] = (SQRT_2 * (f1[i+1][j] - f1[i-1][j])+
                (f1[i+1][j+1] - f1[i-1][j+1])+
                (f1[i+1][j-1] - f1[i-1][j-1])) * NORM ;
     f1y[i][j] = (SQRT_2 * (f1[i][j+1] - f1[i][j-1]) +
                 (f1[i+1][j+1] - f1[i+1][j-1])+
                 (f1[i-1][j+1] - f1[i-1][j-1])) * NORM;
     f2x[i][j] = (SQRT_2 * (f2[i+1][j] - f2[i-1][j])+
                (f2[i+1][j+1] - f2[i-1][j+1])+
                (f2[i+1][j-1] - f2[i-1][j-1])) * NORM ;
     f2y[i][j] = (SQRT_2 * (f2[i][j+1] - f2[i][j-1]) +
                 (f2[i+1][j+1] - f2[i+1][j-1])+
                 (f2[i-1][j+1] - f2[i-1][j-1])) * NORM;
   }
}

/* calculate shifted vectors f1s, f1xs, f1ys */
interpolation (f2,  u, v, height, width, f2s);
interpolation (f2x, u, v, height, width, f2xs);
interpolation (f2y, u, v, height, width, f2ys);

/* determine lambda */
 find_lambda (f1x, f1y, height, width, hx, hy, quantile, 1, &lambda);

/* estimation of the diffusion tensor */
diffusion_tensor (dtype, f1x, f1y, u, height, width, hx, hy, lambda, du11, du12, du22);
/*diffusion_tensor (dtype, f1x, f1y, v, height, width, hx, hy, lambda, dv11, dv12, dv22);
*/

/* loop */
t=0;
while (t < T )
  {
    /* perform 1 iterations */
    t = t + 1.0 * ht;
    for (i=1; i<=1; i++)
      {
	/* calculate shifted vectors */
	interpolation (f2,  u, v, height, width, f2s);
	interpolation (f2x, u, v, height, width, f2xs);
	interpolation (f2y, u, v, height, width, f2ys);
	krelax=relax_2 (ht, height, width, hx, hy, f1, f2s, f2xs, f2ys,
		      du11, du12, du22, alpha, u, v,Niter,f1x,f1y);

      } /* for */



  } /* while */


/* disallocate storage */
 ami_free2d (f1);
 ami_free2d (f2);
 ami_free2d (f1x);
 ami_free2d (f1y);
 ami_free2d (f2x);
 ami_free2d (f2y);
 ami_free2d (f2s);
 ami_free2d (f2xs);
 ami_free2d (f2ys);
 ami_free2d (du11);
 ami_free2d (du12);
 ami_free2d (du22);
 ami_free2d (dv11);
 ami_free2d (dv12);
 ami_free2d (dv22);
 ami_free2d (u0);
 ami_free2d (v0);

 return;

} /* optic_flow */


/**
	\param dimx image dimension in x direction 
	\param dimy image dimension in y direction 
	\param hx pixel size in x direction 
	\param hy pixel size in y direction 
	\param ff1 first image, unchanged 
	\param ff2 second image, unchanged 
	\param sigma Gaussian scale smoothing image data 
	\param T stopping time 
	\param alpha smoothness weight 
	\param dtype type of smoothness term 
	\param quantile isotropy fraction 
	\param ht time step size 
	\param u x component of optic flow, changed 
	\param v y component of optic flow, changed 
	\param Niter Number of Iterations for Gauss-Seidel 
	\param Nzoom Number of zooms to apply in the piramidal approach 
*/
void optic_flow_zoom

     (long     dimx,          /* image dimension in x direction */
      long     dimy,          /* image dimension in y direction */
      float    hx,          /* pixel size in x direction */
      float    hy,          /* pixel size in y direction */
      float    *ff1,        /* first image, unchanged */
      float    *ff2,        /* second image, unchanged */
      float    sigma,       /* Gaussian scale smoothing image data */
      float    T,           /* stopping time */
      float    alpha,       /* smoothness weight */
      long     dtype,       /* type of smoothness term */
      float    quantile,    /* isotropy fraction */
      float    ht,          /* time step size */
      float    ***u,         /* x component of optic flow, changed */
      float    ***v,         /* y component of optic flow, changed */
      int Niter,            /* Number of Iterations for Gauss-Seidel */
	  long Nzoom)            /* Number of zooms to apply in the piramidal approach */

{
    float  **f1,**f2,***f1zoom, ***f2zoom;  /* auxiliary images */
    //float **faux;
    float  **vaux, **uaux;  /* auxiliary optic flow components */
    long   i, j, k;              /* loop variables */
    long   Nx, Ny, dimx_1=0, dimy_1=0;               /* image size in x, y direction */
    //float  dt;                   /* time step size */
    /*float  lambda;      */         /* contrast parameter */
    long mm;
    //long size;
    //int ii,jj;
    //char name[40],nameu[40], com[200]="KK", titulo[50]="OptFlowMovie";
    float Nitera;
    //char *ufile, *vfile, outputU[100]="UMatrix", outpu  	tV[100]="VMatrix";
	float **u2=NULL,**v2=NULL;
	int l;

    printf("\n ---------------------------------------------------------------\n");
    printf("OPTIC FLOW CALCULATION WITH VARIOUS SMOOTHNESS TERMS AND PYRAMIDAL APPROACH \n");
    printf("NONLINEARIZED OPTIC FLOW CONSTRAINT\n");
    printf("MULTISCALE APPROACH\n");
    printf("IMPLICIT ZOOM SCHEME FOR CORRESPONDING DIFFUSION FILTERS\n\n");
	printf("NUMBER OF RESOLUTION SCALES : %ld\n",Nzoom);
	printf("SD OF THE GAUSSIAN CONVOLUTION AT EACH SCALE : %f\n",sigma);
	printf("STOPPING TIME TO SOLVE THE UNDERLYING PDE: %f\n",T);
	printf("TIME DISCRETIZATION FOR SOLVING THE UNDERLYING PDE: %f\n",ht);
	printf("NUMBER OF ITERATIONs TO SOLVE THE GAUSS-SEIDEL SYSTEM TO SOLVE THE PDE: %d\n",Niter);
	printf("SMOOTHNESS WEIGHT PARAMETER: %f\n",alpha);
	printf("TYPE OF SMOOTHING TERM: %d\n",(int) dtype);
	printf("ISOTROPIC FRACTION FOR THE NAGEL-ENKELMANN OPERATOR: %f\n\n",quantile);


	/* allocate storage */
    ami_malloc2d (f1,float, dimx+2, dimy+2);
    ami_malloc2d (f2, float,dimx+2, dimy+2);

    /* read image data */
	mm=0;
	int x,y;
    for (y=1; y<=dimy; y++)
	  for (x=1; x<=dimx; x++){
	    f1[x][y] = ff1[mm];
	    f2[x][y] = ff2[mm];
		mm++;
      }

   /* ---- zoom optic flow calculation ---- */
    Nx=dimx+2;
    Ny=dimy+2;

    /* create different zoomed images from two original ones */
    dummies (f1, dimx, dimy);
    dummies (f2, dimx, dimy);
    Nitera=ZoomSerie(f1, &f1zoom, Nx, Ny, Nzoom);
    Nzoom=ZoomSerie(f2, &f2zoom, Nx, Ny, Nzoom);

	/* Computing the optic flow using a piramidal approach */
	while(Nzoom>0)
    {
	  //printf("-------------------------\nNext Zoom: dimx %ld, dimy %ld\n",dimx,dimy);

	  /* image size for the next iteration */


	  dimx=(long)((float)Nx/pow(2., (int)(Nzoom-1) )+1-1/pow(2.,(int) (Nzoom-1) ));
	  dimy=(long)((float)Ny/pow(2., (int) (Nzoom-1) )+1-1/pow(2., (int) (Nzoom-1) ));

	  //dimx=(long)((float)((Nx-2)/pow(2, Nzoom-1))+2);
	  //dimy=(long)((float)((Ny-2)/pow(2, Nzoom-1))+2);
	  //printf("OH0 dimx=%d dimy=%d\n",(int) dimx, (int) dimy);


//	  dimx=(long)((float)Nx/pow(2, Nzoom-1)+1-1/pow(2, Nzoom-1));
//	  dimy=(long)((float)Ny/pow(2, Nzoom-1)+1-1/pow(2, Nzoom-1));


	  if(Nzoom==Nitera){
	    /* allocate storage */
	    ami_malloc2d (u2,float, dimx, dimy);
	    ami_malloc2d (v2,float, dimx, dimy);

	    /* initialize */
	    for (i=0; i<dimx; i++)
    		for (j=0; j<dimy; j++)
		    u2[i][j]=v2[i][j]=0.0;

	    /* compute the correlation between images */
	    /*InterCorrelation_Flow(f1zoom[Nzoom-1], f2zoom[Nzoom-1], u, v, dimx, dimy, 2, 2,
			-10, 10, -10, 10);*/
	    dimx_1=dimx;
	    dimy_1=dimy;
	  }
	  else{
	    uaux=u2;
	    u2=DZoom(uaux, dimx, dimy, dimx_1, dimy_1, 2);
	    vaux=v2;
	    v2=DZoom(vaux, dimx, dimy, dimx_1, dimy_1, 2);
	    ami_free2d (uaux);
	    ami_free2d (vaux);
	    dimx_1=dimx;
	    dimy_1=dimy;
	  }

      /* optic flow calculation */
      l=0;
	  // printf("----------------------------------------------------- \n");

	  optic_flow (dimx-2, dimy-2, hx, hy, f1zoom[Nzoom-1], f2zoom[Nzoom-1], sigma, T,
		    alpha, dtype, quantile, ht,
		    u2, v2, Niter);

      Nzoom--;

    }

	//*u=u2; *v=v2;
    dimx=Nx;
    dimy=Ny;
    Nzoom=(long int)Nitera;


    /* ---- disallocate storage ---- */
    ami_free2d (f1);
    ami_free2d (f2);


    //printf("Liberando memoria %ld, %ld, %ld\n", Nzoom, dimx, dimy);
    for(i=0;i<Nzoom;i++){
        ami_free2d (f1zoom[i]);
        ami_free2d (f2zoom[i]);
	    dimx=(long)((float)dimx/2+0.5);
	    dimy=(long)((float)dimy/2+0.5);
    }
    //printf("Liberando memoria principal %ld\n", Nzoom);
    free(f1zoom);
    free(f2zoom);

	/* WE ORDER THE u AND v vector */
	dimx=Nx; dimy=Ny;
//printf("OH1 dimx=%d dimy=%d\n",(int) dimx, (int) dimy);
	{
	  float **up,**vp;
	  ami_malloc2d(up,float,dimy-2,dimx-2);
	  ami_malloc2d(vp,float,dimy-2,dimx-2);
	  for(j=1;j<(dimy-1);j++){
	    for(k=1;k<(dimx-1);k++){
		  up[j-1][k-1]=u2[k][j];
	          vp[j-1][k-1]=v2[k][j];
		  //printf("%d %d %f %f\n",j,k,u2[k][j],vp[j-1][k-1]);
		}
	  }
	  //printf("OH2\n");

	  ami_free2d((u2));
	  ami_free2d((v2));
	  //printf("OH3\n");

	  *u=up;
	  *v=vp;
    }


    //printf("The end\n");

}




/**	FUNCI� PARA CALCULAR M�IMOS */
int ami_max(int a, int b)
{
    return ((a>b)?(a):(b));
}

/**	FUNCI� PARA CALCULAR M�IMOS */
int ami_min(int a, int b)
{
    return ((a>b)?(b):(a));
}


/**
	FUNCION PARA RELLENAR UN TRIANGULO CUYOS VERTICES SON cxi, cyi	    
*/

void ami_fill_triangle(unsigned char *red,unsigned char *green,unsigned char *blue,int width,int height,
              unsigned char red_arrow,unsigned char green_arrow,unsigned char blue_arrow,
              int cx1, int cy1, int cx2, int cy2, int cx3, int cy3 )
{
    int maxX, maxY;
    int minX, minY;
    int i,j;

    /* obtenemos el cuadro que engloba al triangulo */
    maxX=ami_max(cx1, ami_max(cx2, cx3));
    minX=ami_min(cx1, ami_min(cx2, cx3));
    maxY=ami_max(cy1, ami_max(cy2, cy3));
    minY=ami_min(cy1, ami_min(cy2, cy3));

    /* empezamos a rellenar */
    for(i=minY;i<=maxY;i++)
	for(j=minX;j<=maxX;j++)
	    if((((j-cx2)*(cy1-cy2)-(cx1-cx2)*(i-cy2))*
		((j-cx3)*(cy2-cy3)-(cx2-cx3)*(i-cy3)))>0){
		    if(((j-cx1)*(cy3-cy1)-(cx3-cx1)*(i-cy1))>0){
			red[i*width+j]=red_arrow;
			green[i*width+j]=green_arrow;
			blue[i*width+j]=blue_arrow;
		    }
		}
}




/**
  FUNCTION TO COMPUTE THE OPTIC FLOW USING A CORRELATION TECHNIQUE

  \param image1,image2 input images 
  \param width,height dimension of the images 
  \param u,v output computed flow 
  \param x_init,y_init initial coordinate point to compute the correlation 
  \param x_interval_size,y_interval_size displacement between points for computing the correlation
  \param size_correlation_window size of correlation window. it has to be a power of 2 
*/
void optic_flow_correlation(
  float **image1,float **image2, /* input images */
  int width,int height, /* dimension of the images */
  float ***u,float ***v, /* output computed flow */
  int x_init,int y_init, /* initial coordinate point to compute the correlation */
  int x_interval_size, int y_interval_size, /* displacement between points for computing the correlation */
  int size_correlation_window) /* size of correlation window. it has to be a power of 2 */
{
  float ***da1_c,***da2_c,correlation,**u2,**v2;
  int i2,j2,i1,j1,i,j;
  long m;

  printf("\n ----------------------------------------------------- \n");
  printf("OPTIC FLOW ESTIMATION BY CORRELATION ON A DISCRETE SET OF POINTS ON THE IMAGE \n");
  printf("THE CORRELATION WINDOW SIZE IS %d X %d\n",size_correlation_window,size_correlation_window);
  printf("THE INIT PIXEL COORDINATE POINT IN THE IMAGE TO ESTIMATE CORRELATION IS : (%d,%d)\n",y_init,x_init);
  printf("THE DISPLACEMENT BETWEEN CONSECUTIVE POINTS IS : (%d,%d)\n\n",y_interval_size,x_interval_size);


  /* WE ALLOCATE MEMORY */
  ami_malloc3d(da1_c,float,1,size_correlation_window,size_correlation_window);
  ami_malloc3d(da2_c,float,1,size_correlation_window,size_correlation_window);
  ami_calloc2d_init(u2,float,height,width,UV_NULL_VALUE);
  ami_calloc2d_init(v2,float,height,width,UV_NULL_VALUE);

  /* WE COMPUTE THE CORRELATION IN EACH SUBWINDOW */
	for(i=y_init;i<height;i+=y_interval_size){
	  for(j=x_init;j<width;j+=x_interval_size){
		 m=0;
		 for(i2=i-size_correlation_window/2;i2<(i+size_correlation_window/2);i2++){
           for(j2=j-size_correlation_window/2;j2<(j+size_correlation_window/2);j2++){
			   i1=i2<0?0:(i2<height?i2:height-1);
			   j1=j2<0?0:(j2<width?j2:width-1);
			   da1_c[0][0][m]=image1[i1][j1];
			   da2_c[0][0][m]=image2[i1][j1];
			   m++;
		   }
		 }
         /* WE COMPUTE THE CORRELATION */
		 ami_fft_correlation(da1_c,da2_c, (long) 1, (long) size_correlation_window, (long) size_correlation_window);
		 /* WE COMPUTE THE MAXIMUN OF THE CORRELATION TO ESTIMATE THE FLOW TAKING INTO ACCOUNT THE PERIODICITY OF THE SIGNAL */
         correlation=-10e+10;
		 for(i2=0;i2<size_correlation_window;i2++){
		   for(j2=0;j2<size_correlation_window;j2++){
			 if(da1_c[0][i2][j2]>correlation){
			   correlation=da1_c[0][i2][j2];
			   if(i2<size_correlation_window/2) v2[i][j]=i2; else v2[i][j]=i2-size_correlation_window;
			   if(j2<size_correlation_window/2) u2[i][j]=j2; else u2[i][j]=j2-size_correlation_window;
			 }
		   }
	     }
	  }
	}

	/* WE STORE THE OUTPUT FLOW IN (u,v) */
	*u=u2;
	*v=v2;
	/* WE FREE THE MEMORY */
    ami_free3d(da1_c);
	ami_free3d(da2_c);

}



/**
	FUNCTION WHICH COMPUTES THE TENSOR STRUCTURE INFORMATION AT A GIVEN SCALE            

	\param image INPUT IMAGE  
	\param width IMAGE WIDTH 
	\param height IMAGE HEIGHT 
	\param sigma STANDARD DEVIATION OF THE GAUSSIAN 
	\param convolved_image IMAGE CONVOLVED WITH THE GAUSSIAN 
	\param eigenvalue_min MINIMUM EIGENVALUE OF THE STRUCTURE TENSOR 
	\param eigenvalue_max MAXIMUM EIGENVALUE OF THE STRUCTURE TENSOR 
	\param eigenvector_max_x X-COMPONENT OF THE EIGENVECTOR ASOCIATED TO THE MAXIMUM EIGENVALUE 
	\param eigenvector_max_y Y-COMPONENT OF THE EIGENVECTOR ASOCIATED TO THE MAXIMUM EIGENVALUE 
*/
int ami_structure_tensor_information(float *image, /* INPUT IMAGE  */
                               int width, /* IMAGE WIDTH */
                               int height, /* IMAGE HEIGHT */
			       float sigma, /* STANDARD DEVIATION OF THE GAUSSIAN */
			       float *convolved_image, /* IMAGE CONVOLVED WITH THE GAUSSIAN */
			       float *eigenvalue_min, /* MINIMUM EIGENVALUE OF THE STRUCTURE TENSOR */
				   float *eigenvalue_max, /* MAXIMUM EIGENVALUE OF THE STRUCTURE TENSOR */
				   float *eigenvector_max_x, /* X-COMPONENT OF THE EIGENVECTOR ASOCIATED TO THE MAXIMUM EIGENVALUE */
				   float *eigenvector_max_y) /* Y-COMPONENT OF THE EIGENVECTOR ASOCIATED TO THE MAXIMUM EIGENVALUE */
{
  int i,j;
  //int k;
  double ux,uy,c1,d1,coef1,coef2;
  float **image_x,**image_y,**image_xy,**image_c;
  double **A,*AUT;
  long m,size=width*height;

  /* WE DEFINE SOME COEFICIENTS FOR THE GRADIENT MASK */
  coef1=sqrt((double) 2.);
  coef2=0.25*(2.-coef1);
  coef1=0.5*(coef1-1);

  /* WE ALLOCATE AUXILIARY MEMORY */
  ami_calloc2d(image_x,float,height,width);
  ami_calloc2d(image_y,float,height,width);
  ami_calloc2d(image_xy,float,height,width);
  ami_calloc2d(image_c,float,height,width);
  ami_malloc2d(A,double,2,2);
  ami_malloc1d(AUT,double,2);

  /* WE COMPUTE THE GRADIENT VECTOR */
  for(i=0;i<height;i++){
    for(j=0;j<width;j++){
      m=i*width+j;
      if(i==0 || i==(height-1) || j==0 || j==(width-1)){
	ux=uy=0;
      }
      else{
	c1=image[m+width+1]-image[m-width-1];
	d1=image[m-width+1]-image[m+width-1];
	uy=coef1*(image[m+width]-image[m-width])+coef2*(c1-d1);
	ux=-(coef1*(image[m+1]-image[m-1])+coef2*(c1+d1));
      }
      image_x[0][m]=ux*ux;
      image_y[0][m]=uy*uy;
      image_xy[0][m]=ux*uy;
    }
  }
  for(m=0;m<size;m++) convolved_image[m]=image_c[0][m]=image[m];

  /* WE PERFORM GAUSSIAN CONVOLUTION FOR ESTIMATING THE STRUCTURE TENSOR */
  if(sigma>0.){
	//ami_gauss_conv_alma(image_c[0],sigma,sigma,0.,width,height);
	//ami_gauss_conv_alma(image_x[0],sigma,sigma,0.,width,height);
	//ami_gauss_conv_alma(image_y[0],sigma,sigma,0.,width,height);
	//ami_gauss_conv_alma(image_xy[0],sigma,sigma,0.,width,height);

	ami_gauss_conv(sigma,(long) height,(long) width,(float) 1,(float) 1,(float) 3.,(long) 1,image_c);
    ami_gauss_conv(sigma,(long) height,(long) width,(float) 1,(float) 1,(float) 3.,(long) 1,image_x);
    ami_gauss_conv(sigma,(long) height,(long) width,(float) 1,(float) 1,(float) 3.,(long) 1,image_y);
    ami_gauss_conv(sigma,(long) height,(long) width,(float) 1,(float) 1,(float) 3.,(long) 1,image_xy);

	for(m=0;m<size;m++) convolved_image[m]=image_c[0][m];

  }

  /* WE COMPUTE THE EIGENVALUES AND EIGENVECTOR OF THE STRUCTURE TENSOR WE KEEP THE INFORMATION OF THE EIGENVALUES
     AND THE EIGENVECTOR ASSOCIATED TO THE MAXIMUM EIGENVALUE */
  for(i=0;i<height;i++){
    for(j=0;j<width;j++){
      m=i*width+j;
      A[0][0]=image_x[0][m]; A[1][1]=image_y[0][m]; A[0][1]=A[1][0]=image_xy[0][m];
      ami_jacobi_autovalores_autovectores(A,AUT,A,2,0.00001);
      if(AUT[0]>AUT[1]){
        eigenvalue_max[m]=AUT[0]; eigenvalue_min[m]=AUT[1];
		eigenvector_max_x[m]=A[0][0]; eigenvector_max_y[m]=A[1][0];
		//if(eigenvalue_max[m]>5) printf("(i=%d,j=%d), eigenvector=(%f,%f)\n",i,j,eigenvector_max_x[m],eigenvector_max_y[m]);
      }
      else{
		eigenvalue_max[m]=AUT[1]; eigenvalue_min[m]=AUT[0];
		eigenvector_max_x[m]=A[0][1]; eigenvector_max_y[m]=A[1][1];
		//if(eigenvalue_max[m]>5) printf("(i=%d,j=%d), eigenvector=(%f,%f)\n",i,j,eigenvector_max_x[m],eigenvector_max_y[m]);
      }
    }
  }

  ami_free2d(image_x);  ami_free2d(image_y);  ami_free2d(image_xy); ami_free2d(image_c); ami_free2d(A); free(AUT);
  return(0);

}



/**
	THIS FUNCTION USES THE STRUCTURE TENSOR INFORMATION AT DIFFERENT SCALES TO ESTIMATE THE OPTIC FLOW BETWEEN IMAGE PAIRS 
	
	\param width IMAGE WIDTH 
	\param height IMAGE HEIGHT 
	\param Nscales NUMBER OF SCALES 
	\param sigma_1 STANDARD DEVIATION OF THE GAUSSIAN FOR THE DIFFERENT SCALES 
    \param convolved_image_1 IMAGE CONVOLVED WITH THE GAUSSIAN FOR THE DIFFERENT SCALES 
	\param eigenvalue_min_1 MINIMUM EIGENVALUE OF THE STRUCTURE TENSOR FOR THE DIFFERENT SCALES 
	\param eigenvalue_max_1 MAXIMUM EIGENVALUE OF THE STRUCTURE TENSOR FOR THE DIFFERENT SCALES 
	\param eigenvector_max_x_1 X-COMPONENT OF THE EIGENVECTOR ASOCIATED TO THE MAXIMUM EIGENVALUE FOR THE DIFFERENT SCALES
	\param eigenvector_max_y_1 Y-COMPONENT OF THE EIGENVECTOR ASOCIATED TO THE MAXIMUM EIGENVALUE FOR THE DIFFERENT SCALES
	\param sigma_2 STANDARD DEVIATION OF THE GAUSSIAN FOR THE DIFFERENT SCALES 
	\param convolved_image_2 IMAGE CONVOLVED WITH THE GAUSSIAN FOR THE DIFFERENT SCALES 
	\param eigenvalue_min_2 MINIMUM EIGENVALUE OF THE STRUCTURE TENSOR FOR THE DIFFERENT SCALES 
	\param eigenvalue_max_2 MAXIMUM EIGENVALUE OF THE STRUCTURE TENSOR FOR THE DIFFERENT SCALES 
	\param eigenvector_max_x_2 X-COMPONENT OF THE EIGENVECTOR ASOCIATED TO THE MAXIMUM EIGENVALUE FOR THE DIFFERENT SCALES
	\param eigenvector_max_y_2 Y-COMPONENT OF THE EIGENVECTOR ASOCIATED TO THE MAXIMUM EIGENVALUE FOR THE DIFFERENT SCALES
	\param window_radius WINDOWS RADIUS FOR SEARCHING IN THE OTHER IMAGE 
	\param weigth WEIGHT FOR THE DIFFERENT PARAMETERS (THE DIMENSION OF WEIGHTS IS Nscales X 4
	\param eigenvalue_max_1_treshold MINIMUM VALUE OF (max eigenvalue_max_1[i]) FOR OPTIC FLOW COMPUTATION
	\param x DISPLACEMENT OBTAINED IN THE x DIRECTION 
	\param y DISPLACEMENT OBTAINED IN THE x DIRECTION 
	\param width_xy SIZE OF THE X AND Y IMAGE 
	\param height_xy SIZE OF THE X AND Y IMAGE 
	\param energy_error 
*/
int ami_optic_flow_structure_tensor_scales(
                   int width, /* IMAGE WIDTH */
                   int height, /* IMAGE HEIGHT */
				   int Nscales, /* NUMBER OF SCALES */
			       float *sigma_1, /* STANDARD DEVIATION OF THE GAUSSIAN FOR THE DIFFERENT SCALES */
			       float **convolved_image_1, /* IMAGE CONVOLVED WITH THE GAUSSIAN FOR THE DIFFERENT SCALES */
			       float **eigenvalue_min_1, /* MINIMUM EIGENVALUE OF THE STRUCTURE TENSOR FOR THE DIFFERENT SCALES */
				   float **eigenvalue_max_1, /* MAXIMUM EIGENVALUE OF THE STRUCTURE TENSOR FOR THE DIFFERENT SCALES */
				   float **eigenvector_max_x_1, /* X-COMPONENT OF THE EIGENVECTOR ASOCIATED TO THE MAXIMUM EIGENVALUE FOR THE DIFFERENT SCALES*/
				   float **eigenvector_max_y_1, /* Y-COMPONENT OF THE EIGENVECTOR ASOCIATED TO THE MAXIMUM EIGENVALUE FOR THE DIFFERENT SCALES*/
				   float *sigma_2, /* STANDARD DEVIATION OF THE GAUSSIAN FOR THE DIFFERENT SCALES */
			       float **convolved_image_2, /* IMAGE CONVOLVED WITH THE GAUSSIAN FOR THE DIFFERENT SCALES */
			       float **eigenvalue_min_2, /* MINIMUM EIGENVALUE OF THE STRUCTURE TENSOR FOR THE DIFFERENT SCALES */
				   float **eigenvalue_max_2, /* MAXIMUM EIGENVALUE OF THE STRUCTURE TENSOR FOR THE DIFFERENT SCALES */
				   float **eigenvector_max_x_2, /* X-COMPONENT OF THE EIGENVECTOR ASOCIATED TO THE MAXIMUM EIGENVALUE FOR THE DIFFERENT SCALES*/
				   float **eigenvector_max_y_2, /* Y-COMPONENT OF THE EIGENVECTOR ASOCIATED TO THE MAXIMUM EIGENVALUE FOR THE DIFFERENT SCALES*/
				   ami_window window_radius, /* WINDOWS RADIUS FOR SEARCHING IN THE OTHER IMAGE */
				   float **weigth, /* WEIGHT FOR THE DIFFERENT PARAMETERS (THE DIMENSION OF WEIGHTS IS Nscales X 4*/
                   float eigenvalue_max_1_treshold, /* MINIMUM VALUE OF (max eigenvalue_max_1[i]) FOR OPTIC FLOW COMPUTATION */
				   float *x, /* DISPLACEMENT OBTAINED IN THE x DIRECTION */
				   float *y, /* DISPLACEMENT OBTAINED IN THE x DIRECTION */
				   int width_xy, /* SIZE OF THE X AND Y IMAGE */
				   int height_xy, /* SIZE OF THE X AND Y IMAGE */
				   float *energy_error)
{
   int i,j,k,i0,j0,i1,j1,n,i2,j2,inc_i,inc_j;
   float min_error,min;
   //float max;
   long m,m2,m1;
   //long size=width*height;
   float *v_aux,m_v;
   ami_malloc1d(v_aux,float,Nscales);

   /* TO SPEED UP THE ALGORITHM THE OPTIC FLOW IS COMPUTED IN A LOWER RESOLUTION. HERE WE DEFINE THE INCREMENT FOR ZOOMING */
   inc_i= height/height_xy;
   inc_j=width/width_xy;

   /* WE GO ACROSS image_1 */
   i2=-1;
   for(i0=0;i0<height;i0+=inc_i){
	 i2++;
	 j2=-1;
	 //printf("PROCESSING ROW : %d\n",i0);
	 for(j0=0;j0<width;j0+=inc_j){
	   j2++;
	   m=i0*width+j0;
	   m1=i2*width_xy+j2;
	   energy_error[m1]=99.;
	   /* WE INITIALIZE THE FLOW TO (0,5,05) TO BE CAPABLE TO RECOGNIZE IF THE OPTIC FLOW HAVE BEEN COMPUTED BY THE ALGORITHM IN A POSTPROCESSING STEP*/
	   x[m1]=y[m1]=0.5;
	   /* IF THE GRADIENT OF THE IMAGE IN THE POINT IS SMALL AT EVERY SCALE WE DO NOT COMPUTE THE OPTIC FLOW */
	   n=0;
	   while(n<Nscales){ if(eigenvalue_max_1[n][m]>eigenvalue_max_1_treshold) n=Nscales+1; else n++; }
       if(n==Nscales) continue;
	   /* WE GO ACROSS THE SEARCH WINDOW IN IMAGE image_2 */
	   min_error=1e20;
       for(i=window_radius[2];i<=window_radius[3];i+=1){
	     for(j=window_radius[0];j<=window_radius[1];j+=1){
	       i1=(i0+i)<0?0:((i0+i)>=height?(height-1):(i0+i));
		   j1=(j0+j)<0?0:((j0+j)>=width?(width-1):(j0+j));
		   m2=i1*width+j1;
		   /* WE COMPUTE THE MEDIAN OF THE SCALAR PRODUCT OF POINT ORIENTATION FOR DIFFERENT SCALES */
		   for(n=0;n<Nscales;n++) v_aux[n]=fabs( (double) eigenvector_max_x_1[n][m]*eigenvector_max_x_2[n][m2]+eigenvector_max_y_1[n][m]*eigenvector_max_y_2[n][m2] );
		   m_v=ami_mediana_float(Nscales/2,Nscales,v_aux);
		   /* WE COMPUTE IN min THE POINT ENERGY DISTANCE CRITERIUM */
		   min=0;
	       for(k=0;k<Nscales;k++){
             min+=weigth[k][0]*fabs((double) convolved_image_1[k][m]-convolved_image_2[k][m2]);
			 min+=weigth[k][1]*fabs((double) eigenvalue_min_1[k][m]-eigenvalue_min_2[k][m2]);
			 min+=weigth[k][2]*fabs((double) eigenvalue_max_1[k][m]-eigenvalue_max_2[k][m2]);
			 min+=weigth[k][3]*fabs((double) v_aux[k]-m_v)*(eigenvalue_max_1[k][m]-eigenvalue_min_1[k][m])/(eigenvalue_max_1[k][m]+10e-20);
		   }
		   if(min<min_error){min_error=min; x[m1]=i1-i0;y[m1]=j1-j0; }
	     }
       }
	   //printf("x[%d]=%f, y[%d]=%f min_error=%f\n",(int) m1,x[m1],(int) m1,y[m1],min_error);
	   energy_error[m1]=min_error;
	 }
   }

   free(v_aux);
   return(0);

}






/**
	FUNCION QUE CALCULA EL TENSOR DE ESTRUCTURA Y TODA LA INFORMACION ASOCIADA SIMULTANEAMENTE EN VARIAS ESCALAS  

	\param image INPUT IMAGE  
	\param width IMAGE WIDTH 
	\param height IMAGE HEIGHT 
	\param Nscales NUMBER OF SCALES 
	\param sigma STANDARD DEVIATION OF THE GAUSSIAN FOR THE DIFFERENT SCALES 
	\param convolved_image IMAGE CONVOLVED WITH THE GAUSSIAN FOR THE DIFFERENT SCALES 
	\param eigenvalue_min MINIMUM EIGENVALUE OF THE STRUCTURE TENSOR FOR THE DIFFERENT SCALES 
	\param eigenvalue_max MAXIMUM EIGENVALUE OF THE STRUCTURE TENSOR FOR THE DIFFERENT SCALES 
	\param eigenvector_max_x X-COMPONENT OF THE EIGENVECTOR ASOCIATED TO THE MAXIMUM EIGENVALUE FOR THE DIFFERENT SCALES
	\param eigenvector_max_y Y-COMPONENT OF THE EIGENVECTOR ASOCIATED TO THE MAXIMUM EIGENVALUE FOR THE DIFFERENT SCALES
*/
int ami_structure_tensor_information_scales(
                   float *image, /* INPUT IMAGE  */
                   int width, /* IMAGE WIDTH */
                   int height, /* IMAGE HEIGHT */
				   int Nscales, /* NUMBER OF SCALES */
			       float *sigma, /* STANDARD DEVIATION OF THE GAUSSIAN FOR THE DIFFERENT SCALES */
			       float **convolved_image, /* IMAGE CONVOLVED WITH THE GAUSSIAN FOR THE DIFFERENT SCALES */
			       float **eigenvalue_min, /* MINIMUM EIGENVALUE OF THE STRUCTURE TENSOR FOR THE DIFFERENT SCALES */
				   float **eigenvalue_max, /* MAXIMUM EIGENVALUE OF THE STRUCTURE TENSOR FOR THE DIFFERENT SCALES */
				   float **eigenvector_max_x, /* X-COMPONENT OF THE EIGENVECTOR ASOCIATED TO THE MAXIMUM EIGENVALUE FOR THE DIFFERENT SCALES*/
				   float **eigenvector_max_y) /* Y-COMPONENT OF THE EIGENVECTOR ASOCIATED TO THE MAXIMUM EIGENVALUE FOR THE DIFFERENT SCALES*/
{
   int i;
   //int j;
   //float max,min;
   //long size=width*height;
   for(i=0;i<Nscales;i++){
	     ami_structure_tensor_information(image,width,height,sigma[i],convolved_image[i],eigenvalue_min[i],eigenvalue_max[i],eigenvector_max_x[i],eigenvector_max_y[i]);
   }
   return(0);

}


/**
	FUNCTION TO COMPUTE THE OPTIC FLOW BETWEEN 2 IMAGES USING THE STRUCTURE TENSOR INFORMATION

	\param image_1,image_2 input images
	\param width,height image dimensions 
	\param u,v output flow estimated 
	\param parameter_file file name with the parameters of the function 	
*/
int optic_flow_structure_tensor(
  float *image_1,float *image_2, /* input images */
  int width,int height, /* image dimensions */
  float ***u,float ***v, /* output flow estimated */
  char parameter_file[200]) /* file name with the parameters of the function */
{

  int i,j,Nscales;
  //int k,n,l;
  float *sigma,**convolved_image_1,**eigenvalue_min_1,**eigenvalue_max_1,**eigenvector_max_x_1,**eigenvector_max_y_1;
  //float max,min;
  float **convolved_image_2,**eigenvalue_min_2,**eigenvalue_max_2,**eigenvector_max_x_2,**eigenvector_max_y_2,**weigth;
  float **up,**vp;
  //long m;
  long size=width*height;
  //char name[200],name_1[200],name_2[200];
  //float *paso;
  ami_window window_radius;
  float eigenvalue_max_1_treshold,*energy_error;
  int zoom_factor,local_window_search_radius,radius_window_median_filter;
  float **v_max;
  //FILE *fptr;

  /* WE OPEN THE PARAMETER FILE */
 /* if ((fptr = fopen(parameter_file,"r")) == NULL) {
    fprintf(stderr,"Unable to open  parameter file %s\n",parameter_file);
    return(-2);
  }
  fscanf(fptr,"%d\n",&Nscales);
  ami_malloc1d(sigma,float,Nscales);
  for(i=0;i<Nscales;i++) fscanf(fptr,"%f\n",&(sigma[i]));
  fscanf(fptr,"%f\n",&eigenvalue_max_1_treshold);
  for(k=0;k<4;k++) fscanf(fptr,"%d\n",&(window_radius[k]));
  fscanf(fptr,"%d\n",&zoom_factor);
  fscanf(fptr,"%d\n",&local_window_search_radius);
  fscanf(fptr,"%d\n",&radius_window_median_filter);
  ami_malloc2d(weigth,float,Nscales,4);
  for(i=0;i<Nscales;i++) fscanf(fptr,"%f\n",&(weigth[i][0]));
  for(i=0;i<Nscales;i++) fscanf(fptr,"%f\n",&(weigth[i][1]));
  for(i=0;i<Nscales;i++) fscanf(fptr,"%f\n",&(weigth[i][2]));
  for(i=0;i<Nscales;i++) fscanf(fptr,"%f\n",&(weigth[i][3]));
  fclose(fptr); */

  if( ami_read_parameters_optic_flow_structure_tensor(parameter_file,&Nscales,&sigma,&eigenvalue_max_1_treshold,
         window_radius,&zoom_factor,&local_window_search_radius,&radius_window_median_filter,&weigth )!=0) return(-1);


  /* WE PRINT PARAMETER INFORMATION */
  printf("Parameters Information:\n");
  printf("Number of Scales to compute the structure tensor information = %d\n",Nscales);
  for(i=0;i<Nscales;i++)
	printf("Standard Deviation of the Gaussian for scale %d =%f\n",i,sigma[i]);
  printf("Minimun Intensity Gradient to Compute the flow = %f\n",eigenvalue_max_1_treshold);
  printf("   For lower Minimun Intensity value the flow is fitted to (x[m],y[m])=(0.5,0.5)\n");
  printf("Window search radius to look for point correspondence in the second image = %d %d %d %d\n",window_radius[0],window_radius[1],window_radius[2],window_radius[3]);
  printf("Number of ZOOM level of resolution to speed up the algorithm = %d\n",zoom_factor);
  printf(" window search radius in the zooming up process = %d\n",local_window_search_radius);
  printf("median filter window radius to apply to the flow obtained in the higher level of ZOOM resolution = %d\n",radius_window_median_filter);
  for(i=0;i<Nscales;i++)
	printf("Weight of the parameter Image Intensity at Scale %d =%f\n",i,weigth[i][0]);
  for(i=0;i<Nscales;i++)
	printf("Weight of the parameter Minimun Eigenvalue of Structure Tensor at Scale %d =%f\n",i,weigth[i][1]);
  for(i=0;i<Nscales;i++)
	printf("Weight of the parameter Maximun Eigenvalue of Structure Tensor at Scale %d =%f\n",i,weigth[i][2]);
  for(i=0;i<Nscales;i++)
	printf("Weight of the parameter Orientation Coherence of eigenvectors of Structure Tensor at Scale %d =%f\n",i,weigth[i][3]);


  /* WE ALLOCATE MEMORY FOR ALL VECTOR WE NEED */
  ami_malloc2d(convolved_image_1,float,Nscales,size);
  ami_malloc2d(eigenvalue_min_1,float,Nscales,size);
  ami_malloc2d(eigenvalue_max_1,float,Nscales,size);
  ami_malloc2d(eigenvector_max_x_1,float,Nscales,size);
  ami_malloc2d(eigenvector_max_y_1,float,Nscales,size);

  ami_malloc2d(convolved_image_2,float,Nscales,size);
  ami_malloc2d(eigenvalue_min_2,float,Nscales,size);
  ami_malloc2d(eigenvalue_max_2,float,Nscales,size);
  ami_malloc2d(eigenvector_max_x_2,float,Nscales,size);
  ami_malloc2d(eigenvector_max_y_2,float,Nscales,size);

  ami_calloc2d_init(up,float,height,width,UV_NULL_VALUE);
  ami_calloc2d_init(vp,float,height,width,UV_NULL_VALUE);
  ami_calloc1d(energy_error,float,size);

  ami_malloc2d(v_max,float,Nscales,4);


  /* WE COMPUTE THE STRUCTURE TENSOR INFORMATION FOR BOTH IMAGES */
  printf("We compute the structure tensor information for image 1 \n");
  ami_structure_tensor_information_scales(image_1,width,height,Nscales,sigma,convolved_image_1,eigenvalue_min_1,
		   eigenvalue_max_1,eigenvector_max_x_1,eigenvector_max_y_1);
  printf("We compute the structure tensor information for image 2 \n");
  ami_structure_tensor_information_scales(image_2,width,height,Nscales,sigma,convolved_image_2,eigenvalue_min_2,
		   eigenvalue_max_2,eigenvector_max_x_2,eigenvector_max_y_2);

  /* WE NORMALIZE THE PARAMETER WEIGHTS USING THE MAX OF EACH PARAMETER FOR IMAGE 1*/
  /* WE MODIFY WEIGHT PARAMETERS FOLLOWING THE MAXIMA OF THE FIRST IMAGE */
  for(i=0;i<Nscales;i++){
    ami_max_vector(convolved_image_1[i],j,v_max[i][0],size);
   	weigth[i][0]/=v_max[i][0];
	ami_max_vector(eigenvalue_min_1[i],j,v_max[i][1],size);
	weigth[i][1]/=v_max[i][1];
	ami_max_vector(eigenvalue_max_1[i],j,v_max[i][2],size);
	weigth[i][2]/=v_max[i][2];
  }

  /* WE COMPUTE THE DISPLACEMENT USING A ZOOMING TECHNIQUE TO SPEED UP THE ALGORITHM */
  ami_optic_flow_structure_tensor_scales_zoom(width,height,Nscales,sigma,convolved_image_1,eigenvalue_min_1,eigenvalue_max_1,
        eigenvector_max_x_1,eigenvector_max_y_1,sigma,convolved_image_2,eigenvalue_min_2,eigenvalue_max_2,eigenvector_max_x_2,
		eigenvector_max_y_2,window_radius,weigth,eigenvalue_max_1_treshold,up[0],vp[0],zoom_factor,local_window_search_radius,
		radius_window_median_filter,energy_error);

  /* WE FREE THE MEMORY */
  ami_free2d(convolved_image_1);
  ami_free2d(eigenvalue_min_1);
  ami_free2d(eigenvalue_max_1);
  ami_free2d(eigenvector_max_x_1);
  ami_free2d(eigenvector_max_y_1);

  ami_free2d(convolved_image_2);
  ami_free2d(eigenvalue_min_2);
  ami_free2d(eigenvalue_max_2);
  ami_free2d(eigenvector_max_x_2);
  ami_free2d(eigenvector_max_y_2);

  free(energy_error);
  ami_free2d(v_max);

  /* WE CHANGE THE ORIENTATION OF THE FLOW IN THE VERTICAL DIRECTION */
  //for(m=0;m<size;m++){ up[0][m]*=-1.; }

  /* WE FILL THE OUTPUT FLOW */
  *v=up;
  *u=vp;

  return(0);
}


/**
	FUNCTION  TO SAVE MULTISCALE STRUCTURE TENSOR OPTIC FLOW ESTIMATION METHOD PARAMETER
*/
int ami_save_parameter_file_optic_flow_structure_tensor(char name[200],int Nscales,float *sigma,float eigenvalue_max_1_treshold,
               ami_window window_radius,int zoom_factor,int local_window_search_radius,int radius_window_median_filter,float **weigth )
 {
    int i;
    //int k,j;
    FILE *fptr;
    
    /* Open file */
    if ((fptr = fopen(name,"w")) == NULL) {
      fprintf(stderr,"Unable to open  parameter file \"%s\"\n",name);
      return(-2);
    }
    fprintf(fptr,"%d\n",Nscales);
    for(i=0;i<Nscales;i++) fprintf(fptr,"%f\n",(sigma[i]));
    fprintf(fptr,"%f\n",eigenvalue_max_1_treshold);
	for(i=0;i<4;i++)
      fprintf(fptr,"%d\n",window_radius[i]);
    fprintf(fptr,"%d\n",zoom_factor);
    fprintf(fptr,"%d\n",local_window_search_radius);
    fprintf(fptr,"%d\n",radius_window_median_filter);
    for(i=0;i<Nscales;i++) fprintf(fptr,"%f\n",(weigth[i][0]));
    for(i=0;i<Nscales;i++) fprintf(fptr,"%f\n",(weigth[i][1]));
    for(i=0;i<Nscales;i++) fprintf(fptr,"%f\n",(weigth[i][2]));
    for(i=0;i<Nscales;i++) fprintf(fptr,"%f\n",(weigth[i][3]));
    fclose(fptr);

	return(0);
  }




/**
	FUNCTION TO SAVE IN ASCII FORMAT ALL THE INFORMATION OF THE OPTIC FLOW WITH 2 DIGIT FLOAT PRECISION
*/
int ami_save_optic_flow_information(char name[200],float *x,float *y,float *energy_error,float *disparity_symmetry_error,int width,int height)
{
  int i,j;
  long m;
  //long size=width*height;
  FILE *fptr;

   if ((fptr = fopen(name,"w")) == NULL) {
      fprintf(stderr,"Unable to open output file \"%s\"\n",name);
      return(-1);
   }

   fprintf(fptr,"Point Coordinates displacement energy_error disparity_symmetry_error\n");
   for(i=0;i<height;i++){
	   for(j=0;j<width;j++){
		   m=i*width+j;
	       fprintf(fptr,"(%d,%d) (%2.2f,%2.2f) %2.2f %2.2f\n",j,i,y[m],x[m],energy_error[m],disparity_symmetry_error[m]);
	   }
   }
   fclose(fptr);

   return(0);
}



/**
	FUNCTION TO SAVE IN ASCII FORMAT THE DISPLACEMENT OF THE OPTIC FLOW WITH 2 DIGIT FLOAT PRECISION 
*/
int ami_save_displacement(char name[200],float *d,int width,int height)
{
  long m,size=width*height;
  FILE *fptr;

   if ((fptr = fopen(name,"w")) == NULL) {
      fprintf(stderr,"Unable to open output file \"%s\"\n",name);
      return(-1);
   }

   for(m=0;m<size;m++){
	fprintf(fptr,"%2.2f\n",d[m]);
   }
   fclose(fptr);

   return(0);
}



/**
	THIS FUNCTION USES THE STRUCTURE TENSOR INFORMATION AT DIFFERENT SCALES TO ESTIMATE THE OPTIC FLOW BETWEEN IMAGE PAIRS
	IT USES THE OPTIC FLOW INFORMATION IN A HIGHER ZOOM LEVEL TO SPEED UP THE ALGORITHM                                    
	
	\param width IMAGE WIDTH 
	\param height IMAGE HEIGHT
	\param Nscales NUMBER OF SCALES
	\param sigma_1 STANDARD DEVIATION OF THE GAUSSIAN FOR THE DIFFERENT SCALES
	\param convolved_image_1 IMAGE CONVOLVED WITH THE GAUSSIAN FOR THE DIFFERENT SCALES
	\param eigenvalue_min_1 MINIMUM EIGENVALUE OF THE STRUCTURE TENSOR FOR THE DIFFERENT SCALES 
	\param eigenvalue_max_1 MAXIMUM EIGENVALUE OF THE STRUCTURE TENSOR FOR THE DIFFERENT SCALES 
	\param eigenvector_max_x_1 X-COMPONENT OF THE EIGENVECTOR ASOCIATED TO THE MAXIMUM EIGENVALUE FOR THE DIFFERENT SCALES
	\param eigenvector_max_y_1 Y-COMPONENT OF THE EIGENVECTOR ASOCIATED TO THE MAXIMUM EIGENVALUE FOR THE DIFFERENT SCALES
	\param sigma_2 STANDARD DEVIATION OF THE GAUSSIAN FOR THE DIFFERENT SCALES
	\param convolved_image_2 IMAGE CONVOLVED WITH THE GAUSSIAN FOR THE DIFFERENT SCALES 
	\param eigenvalue_min_2 MINIMUM EIGENVALUE OF THE STRUCTURE TENSOR FOR THE DIFFERENT SCALES 
	\param eigenvalue_max_2 MAXIMUM EIGENVALUE OF THE STRUCTURE TENSOR FOR THE DIFFERENT SCALES 
	\param eigenvector_max_x_2 X-COMPONENT OF THE EIGENVECTOR ASOCIATED TO THE MAXIMUM EIGENVALUE FOR THE DIFFERENT SCALES
	\param eigenvector_max_y_2 Y-COMPONENT OF THE EIGENVECTOR ASOCIATED TO THE MAXIMUM EIGENVALUE FOR THE DIFFERENT SCALES
	\param window_radius WINDOWS RADIUS FOR SEARCHING IN THE OTHER IMAGE 
	\param weigth WEIGHT FOR THE DIFFERENT PARAMETERS (THE DIMENSION OF WEIGHTS IS Nscales X 4
	\param eigenvalue_max_1_treshold MINIMUM VALUE OF (max eigenvalue_max_1[i]) FOR OPTIC FLOW COMPUTATION 
	\param x_1 DISPLACEMENT OBTAINED IN THE x DIRECTION INPUT
	\param y_1 DISPLACEMENT OBTAINED IN THE x DIRECTION INPUT
	\param width_xy_1 SIZE OF THE X AND Y IMAGE INPUT
	\param height_xy_1 SIZE OF THE X AND Y IMAGE INPUT
	\param x_2 DISPLACEMENT OBTAINED IN THE x DIRECTION INPUT
	\param y_2 DISPLACEMENT OBTAINED IN THE x DIRECTION INPUT
	\param width_xy_2 SIZE OF THE X AND Y IMAGE INPUT
	\param height_xy_2 SIZE OF THE X AND Y IMAGE INPUT
	\param energy_error
*/
int ami_optic_flow_structure_tensor_scales_zoom_up(
                   int width, /* IMAGE WIDTH */
                   int height, /* IMAGE HEIGHT */
				   int Nscales, /* NUMBER OF SCALES */
			       float *sigma_1, /* STANDARD DEVIATION OF THE GAUSSIAN FOR THE DIFFERENT SCALES */
			       float **convolved_image_1, /* IMAGE CONVOLVED WITH THE GAUSSIAN FOR THE DIFFERENT SCALES */
			       float **eigenvalue_min_1, /* MINIMUM EIGENVALUE OF THE STRUCTURE TENSOR FOR THE DIFFERENT SCALES */
				   float **eigenvalue_max_1, /* MAXIMUM EIGENVALUE OF THE STRUCTURE TENSOR FOR THE DIFFERENT SCALES */
				   float **eigenvector_max_x_1, /* X-COMPONENT OF THE EIGENVECTOR ASOCIATED TO THE MAXIMUM EIGENVALUE FOR THE DIFFERENT SCALES*/
				   float **eigenvector_max_y_1, /* Y-COMPONENT OF THE EIGENVECTOR ASOCIATED TO THE MAXIMUM EIGENVALUE FOR THE DIFFERENT SCALES*/
				   float *sigma_2, /* STANDARD DEVIATION OF THE GAUSSIAN FOR THE DIFFERENT SCALES */
			       float **convolved_image_2, /* IMAGE CONVOLVED WITH THE GAUSSIAN FOR THE DIFFERENT SCALES */
			       float **eigenvalue_min_2, /* MINIMUM EIGENVALUE OF THE STRUCTURE TENSOR FOR THE DIFFERENT SCALES */
				   float **eigenvalue_max_2, /* MAXIMUM EIGENVALUE OF THE STRUCTURE TENSOR FOR THE DIFFERENT SCALES */
				   float **eigenvector_max_x_2, /* X-COMPONENT OF THE EIGENVECTOR ASOCIATED TO THE MAXIMUM EIGENVALUE FOR THE DIFFERENT SCALES*/
				   float **eigenvector_max_y_2, /* Y-COMPONENT OF THE EIGENVECTOR ASOCIATED TO THE MAXIMUM EIGENVALUE FOR THE DIFFERENT SCALES*/
				   int window_radius, /* WINDOWS RADIUS FOR SEARCHING IN THE OTHER IMAGE */
				   float **weigth, /* WEIGHT FOR THE DIFFERENT PARAMETERS (THE DIMENSION OF WEIGHTS IS Nscales X 4*/
                   float eigenvalue_max_1_treshold, /* MINIMUM VALUE OF (max eigenvalue_max_1[i]) FOR OPTIC FLOW COMPUTATION */
				   float *x_1, /* DISPLACEMENT OBTAINED IN THE x DIRECTION INPUT*/
				   float *y_1, /* DISPLACEMENT OBTAINED IN THE x DIRECTION INPUT*/
				   int width_xy_1, /* SIZE OF THE X AND Y IMAGE INPUT*/
				   int height_xy_1, /* SIZE OF THE X AND Y IMAGE INPUT*/
				   float *x_2, /* DISPLACEMENT OBTAINED IN THE x DIRECTION INPUT*/
				   float *y_2, /* DISPLACEMENT OBTAINED IN THE x DIRECTION INPUT*/
				   int width_xy_2, /* SIZE OF THE X AND Y IMAGE INPUT*/
				   int height_xy_2, /* SIZE OF THE X AND Y IMAGE INPUT*/
				   float *energy_error)

{
   int i,j,k,i0,j0,i1,j1,n,i2,j2,inc_i,inc_j,i3,j3,i4,j4;
   //float max;
   float min_error,min;
   long m,m2,m1;
   //long size=width*height;
   float *v_aux,m_v,*v_orden_x,*v_orden_y;
   int xmax,xmin,ymax,ymin;

   /* THE ZOOM FACTOR BETWEEN THE 2 ZOOM LEVEL HAVE TO BE 2 */
   if( width_xy_1!=(width_xy_2/2) || height_xy_1!=(height_xy_2/2) ) {
	   printf("Error in ami_optic_flow_structure_tensor_scales_zoom_up() : dimension of output displacement have to be the double of input displacement\n");
	   return(-1);
   }

   /* WE ALLOCATE MEMORY FOR THE AUXILIARY VECTOR WE NEED TO DEFINE THE SEARCH WINDOW */
   ami_malloc1d(v_aux,float,Nscales);
   ami_malloc1d(v_orden_x,float,9);
   ami_malloc1d(v_orden_y,float,9);

   /* TO SPEED UP THE ALGORITHM THE OPTIC FLOW IS COMPUTED IN A LOWER RESOLUTION. HERE WE DEFINE THE INCREMENT FOR ZOOMING */
   inc_i= height/height_xy_2;
   inc_j=width/width_xy_2;

   /* WE GO ACROSS image_1 */
   i2=-1;
   for(i0=0;i0<height;i0+=inc_i){
	 i2++;
	 j2=-1;
	 //printf("PROCESSING ROW : %d\n",i0);
	 for(j0=0;j0<width;j0+=inc_j){
	   j2++;
	   m=i0*width+j0;
	   m1=i2*width_xy_2+j2;
	   energy_error[m1]=99.;
	   /* WE INITIALIZE THE FLOW TO (0,5,05) TO BE CAPABLE TO RECOGNIZE IF THE OPTIC FLOW HAVE BEEN COMPUTED BY THE ALGORITHM IN A POSTPROCESSING STEP*/
	   x_2[m1]=y_2[m1]=0.5;
	   /* IF THE GRADIENT OF THE IMAGE IN THE POINT IS SMALL AT EVERY SCALE WE DO NOT COMPUTE THE OPTIC FLOW */
	   n=0;
	   while(n<Nscales){ if(eigenvalue_max_1[n][m]>eigenvalue_max_1_treshold) n=Nscales+1; else n++; }
       if(n==Nscales) continue;
	   /* WE GO ACROSS THE SEARCH WINDOW IN IMAGE image_2 */
	   /* WE CENTERED THE WINDOW SEARCH FOLLOWING THE MAXIMUM AND MINIMUM OF (x_1[],y_1[]) IN A 3X3 NEIGBORHOOD */
	   min_error=1e20;
	   i3=i2/2; j3=j2/2; n=0;
	   /* WE COMPUTE THE MAXIMUM AND MINIMUM OF (x_1[],y_1[]) IN A 3X3 NEIGBORHOOD */
	   for(i=-1;i<2;i++){
		 for(j=-1;j<2;j++){
		   i4=(i3+i)<0?0:((i3+i)>=(height_xy_1-1)?(height_xy_1-1):(i3+i));
		   j4=(j3+j)<0?0:((j3+j)>=(width_xy_1-1)?(width_xy_1-1):(j3+j));
		   v_orden_x[n]=x_1[i4*width_xy_1+j4];
		   v_orden_y[n++]=y_1[i4*width_xy_1+j4];
		 }
	   }
	   ami_max_vector(v_orden_x,i,xmax,9);
	   ami_max_vector(v_orden_y,i,ymax,9);
	   ami_min_vector(v_orden_x,i,xmin,9);
	   ami_min_vector(v_orden_y,i,ymin,9);
       /* WE LOOK FOR THE ENERGY MINIMUM IN THE WINDOW SEARCH */
       for(i=-window_radius+xmin;i<=window_radius+xmax;i+=1){
	     for(j=-window_radius+ymin;j<=window_radius+ymax;j+=1){
		   i1=i0+i;
	       i1=(i1<0)?0:(i1>=height-1)?(height-1):i1;
		   j1=j0+j;
		   j1=j1<0?0:j1>=width?(width-1):j1;
		   m2=i1*width+j1;
		   //printf("i1=%d,j1=%d\n",i1,j1);
		   /* WE COMPUTE THE MEDIAN OF THE SCALAR PRODUCT OF POINT ORIENTATION FOR DIFFERENT SCALES */
		   for(n=0;n<Nscales;n++) v_aux[n]=fabs( (double) eigenvector_max_x_1[n][m]*eigenvector_max_x_2[n][m2]+eigenvector_max_y_1[n][m]*eigenvector_max_y_2[n][m2] );
		   m_v=ami_mediana_float(Nscales/2,Nscales,v_aux);
		   /* WE COMPUTE IN min THE POINT ENERGY DISTANCE CRITERIUM */
		   min=0;
	       for(k=0;k<Nscales;k++){
             min+=weigth[k][0]*fabs((double) convolved_image_1[k][m]-convolved_image_2[k][m2]);
			 min+=weigth[k][1]*fabs((double) eigenvalue_min_1[k][m]-eigenvalue_min_2[k][m2]);
			 min+=weigth[k][2]*fabs((double) eigenvalue_max_1[k][m]-eigenvalue_max_2[k][m2]);
			 min+=weigth[k][3]*fabs((double) v_aux[k]-m_v)*(eigenvalue_max_1[k][m]-eigenvalue_min_1[k][m])/(eigenvalue_max_1[k][m]+10e-20);
		   }
		   if(min<min_error){min_error=min; x_2[m1]=i1-i0;y_2[m1]=j1-j0; }
	     }
       }
	   //printf("x[%d]=%f, y[%d]=%f min_error=%f\n",(int) m1,x[m1],(int) m1,y[m1],min_error);
	   energy_error[m1]=min_error;
	 }
   }

   free(v_aux); free(v_orden_x); free(v_orden_y);
   return(0);

}


/**
	THIS FUNCTION USES THE STRUCTURE TENSOR INFORMATION AT DIFFERENT SCALES TO ESTIMATE THE OPTIC FLOW BETWEEN IMAGE PAIRS
    USING A ZOOM TO SPEED UP THE ALGORITHM

	\param width IMAGE WIDTH
	\param height IMAGE HEIGHT
	\param Nscales NUMBER OF SCALES
	\param sigma_1 STANDARD DEVIATION OF THE GAUSSIAN FOR THE DIFFERENT SCALES
	\param convolved_image_1 IMAGE CONVOLVED WITH THE GAUSSIAN FOR THE DIFFERENT SCALES
	\param eigenvalue_min_1 MINIMUM EIGENVALUE OF THE STRUCTURE TENSOR FOR THE DIFFERENT SCALES
	\param eigenvalue_max_1 MAXIMUM EIGENVALUE OF THE STRUCTURE TENSOR FOR THE DIFFERENT SCALES
	\param eigenvector_max_x_1 X-COMPONENT OF THE EIGENVECTOR ASOCIATED TO THE MAXIMUM EIGENVALUE FOR THE DIFFERENT SCALES
	\param eigenvector_max_y_1 Y-COMPONENT OF THE EIGENVECTOR ASOCIATED TO THE MAXIMUM EIGENVALUE FOR THE DIFFERENT SCALES
	\param sigma_2 STANDARD DEVIATION OF THE GAUSSIAN FOR THE DIFFERENT SCALES
	\param convolved_image_2 IMAGE CONVOLVED WITH THE GAUSSIAN FOR THE DIFFERENT SCALES
	\param eigenvalue_min_2 MINIMUM EIGENVALUE OF THE STRUCTURE TENSOR FOR THE DIFFERENT SCALES
	\param eigenvalue_max_2 MAXIMUM EIGENVALUE OF THE STRUCTURE TENSOR FOR THE DIFFERENT SCALES
	\param eigenvector_max_x_2 X-COMPONENT OF THE EIGENVECTOR ASOCIATED TO THE MAXIMUM EIGENVALUE FOR THE DIFFERENT SCALES
	\param eigenvector_max_y_2 Y-COMPONENT OF THE EIGENVECTOR ASOCIATED TO THE MAXIMUM EIGENVALUE FOR THE DIFFERENT SCALES
	\param window_radius WINDOWS RADIUS FOR SEARCHING IN THE OTHER IMAGE
	\param weigth WEIGHT FOR THE DIFFERENT PARAMETERS (THE DIMENSION OF WEIGHTS IS Nscales X 4
	\param eigenvalue_max_1_treshold MINIMUM VALUE OF (max eigenvalue_max_1[i]) FOR OPTIC FLOW COMPUTATION
	\param x DISPLACEMENT OBTAINED IN THE x DIRECTION 
	\param y DISPLACEMENT OBTAINED IN THE x DIRECTION
	\param zoom_factor ZOOM FACTOR TO SPEED UP THE ALGORITHM (REPRESENTS THE NUMBER OS ZOOM WE APPLY)
	\param local_window_search_radius RADIUS OF THE SEARCH LOCAL WINDOW
	\param radius_window_median_filter RADIUS OF THE WINDOW TO APPLY A MEDIAN FILTER
	\param energy_error
*/
int ami_optic_flow_structure_tensor_scales_zoom(
                   int width, /* IMAGE WIDTH */
                   int height, /* IMAGE HEIGHT */
				   int Nscales, /* NUMBER OF SCALES */
			       float *sigma_1, /* STANDARD DEVIATION OF THE GAUSSIAN FOR THE DIFFERENT SCALES */
			       float **convolved_image_1, /* IMAGE CONVOLVED WITH THE GAUSSIAN FOR THE DIFFERENT SCALES */
			       float **eigenvalue_min_1, /* MINIMUM EIGENVALUE OF THE STRUCTURE TENSOR FOR THE DIFFERENT SCALES */
				   float **eigenvalue_max_1, /* MAXIMUM EIGENVALUE OF THE STRUCTURE TENSOR FOR THE DIFFERENT SCALES */
				   float **eigenvector_max_x_1, /* X-COMPONENT OF THE EIGENVECTOR ASOCIATED TO THE MAXIMUM EIGENVALUE FOR THE DIFFERENT SCALES*/
				   float **eigenvector_max_y_1, /* Y-COMPONENT OF THE EIGENVECTOR ASOCIATED TO THE MAXIMUM EIGENVALUE FOR THE DIFFERENT SCALES*/
				   float *sigma_2, /* STANDARD DEVIATION OF THE GAUSSIAN FOR THE DIFFERENT SCALES */
			       float **convolved_image_2, /* IMAGE CONVOLVED WITH THE GAUSSIAN FOR THE DIFFERENT SCALES */
			       float **eigenvalue_min_2, /* MINIMUM EIGENVALUE OF THE STRUCTURE TENSOR FOR THE DIFFERENT SCALES */
				   float **eigenvalue_max_2, /* MAXIMUM EIGENVALUE OF THE STRUCTURE TENSOR FOR THE DIFFERENT SCALES */
				   float **eigenvector_max_x_2, /* X-COMPONENT OF THE EIGENVECTOR ASOCIATED TO THE MAXIMUM EIGENVALUE FOR THE DIFFERENT SCALES*/
				   float **eigenvector_max_y_2, /* Y-COMPONENT OF THE EIGENVECTOR ASOCIATED TO THE MAXIMUM EIGENVALUE FOR THE DIFFERENT SCALES*/
				   ami_window window_radius, /* WINDOWS RADIUS FOR SEARCHING IN THE OTHER IMAGE */
				   float **weigth, /* WEIGHT FOR THE DIFFERENT PARAMETERS (THE DIMENSION OF WEIGHTS IS Nscales X 4*/
                   float eigenvalue_max_1_treshold, /* MINIMUM VALUE OF (max eigenvalue_max_1[i]) FOR OPTIC FLOW COMPUTATION */
				   float *x, /* DISPLACEMENT OBTAINED IN THE x DIRECTION */
				   float *y, /* DISPLACEMENT OBTAINED IN THE x DIRECTION */
				   int zoom_factor, /* ZOOM FACTOR TO SPEED UP THE ALGORITHM (REPRESENTS THE NUMBER OS ZOOM WE APPLY) */
				   int local_window_search_radius, /* RADIUS OF THE SEARCH LOCAL WINDOW */
				   int radius_window_median_filter, /* RADIUS OF THE WINDOW TO APPLY A MEDIAN FILTER */
				   float *energy_error)
{
  //int i,j,k;
  int n;
  int width_xy,height_xy;
  long m,size2;

  /* WE DEFINE THE IMAGE DIMENSION AT THE HIGHER ZOOM LEVEL */
  width_xy=(int) (width/pow((double) 2.,(double) zoom_factor));
  height_xy=(int)(height/pow((double) 2.,(double) zoom_factor));
  size2=width_xy*height_xy;

  printf("WE COMPUTE THE DISPLACEMENT BETWEEN IMAGES AT THE HIGHER ZOOM LEVEL \n");
  ami_optic_flow_structure_tensor_scales(width,height,Nscales,sigma_1,convolved_image_1,eigenvalue_min_1,eigenvalue_max_1,
                   eigenvector_max_x_1,eigenvector_max_y_1,sigma_2,convolved_image_2,eigenvalue_min_2,eigenvalue_max_2,eigenvector_max_x_2,
				   eigenvector_max_y_2,window_radius,weigth,eigenvalue_max_1_treshold,x,y,width_xy,height_xy,energy_error);

  printf("WE APPLY A WINDOW MEDIAN FILTER TO THE COMPUTED DISPLACEMENT\n");
  if(radius_window_median_filter>0){
    ami_window_median_filter(x,width_xy,height_xy,radius_window_median_filter);
    ami_window_median_filter(y,width_xy,height_xy,radius_window_median_filter);
  }

  printf("ZOOMING UP THE OPTIC FLOW DISPLACEMENT\n");
  n=0;
  while((width_xy)<width){
   int width_xy_3=width_xy*2;
   int height_xy_3=height_xy*2;
   int size3=width_xy_3*height_xy_3;
   float *x_3,*y_3;
   printf("WE COMPUTE DISPLACEMENT AT ZOOM FACTOR LEVEL %d\n",n++);
   if(radius_window_median_filter>0){
     ami_window_median_filter(x,width_xy,height_xy,radius_window_median_filter);
     ami_window_median_filter(y,width_xy,height_xy,radius_window_median_filter);
   }
   ami_malloc1d(x_3,float,size3);
   ami_malloc1d(y_3,float,size3);
   ami_optic_flow_structure_tensor_scales_zoom_up(width,height,Nscales,sigma_1,convolved_image_1,eigenvalue_min_1,eigenvalue_max_1,
                   eigenvector_max_x_1,eigenvector_max_y_1,sigma_2,convolved_image_2,eigenvalue_min_2,eigenvalue_max_2,eigenvector_max_x_2,
				   eigenvector_max_y_2,local_window_search_radius,weigth,eigenvalue_max_1_treshold,x,y,width_xy,height_xy,x_3,y_3,width_xy_3,height_xy_3,energy_error);
   for(m=0;m<size3;m++){x[m]=x_3[m]; y[m]=y_3[m];}
   free(x_3); free(y_3);
   width_xy=width_xy_3;
   height_xy=height_xy_3;
  }
  return (0);
}


// ....................................................................................
// ....................................................................................

// ....................................................................................
// ....................................................................................

/**
 *
 *	FUNCTION TO READ AN ASCCI FILE WITH THE OPTIC FLOW INFORMATION
 *   IMPORTANT: WE INVERSE THE ROW ORDER
 * 
 */
int ami_read_optic_flow(
  char name[200],/* name of the input flow file */
  float ***u,float ***v,/* output flow matrix */
  int *width,int *height) /* image dimensions */
{
  int i,j,c;
  //int k;
  FILE *fptr;
  char paso[200];
  long m,size;
  float up,vp,**u2,**v2;

  /* Open file  */
  if ((fptr = fopen(name,"r")) == NULL) {
    fprintf(stderr,"Unable to open  file \"%s\"\n",name);
    return(-2);
  }

  /* WE SKIP THE COMMENT HEAD PART OF THE FILE */
  fscanf(fptr, "%s",paso);
  while(paso[0]=='#' ){
	while((c=getc(fptr))!='\n') ;
	fscanf(fptr, "%s",paso);
	printf("paso : %s\n",paso);
  }

  /* WE READ THE IMAGE DIMENSION */
  *width=atoi(paso);
  fscanf(fptr,"%d",height);
  size=(*width)*(*height);
  printf("dimensions : %d %d\n",*width,*height);

  /* WE ALLOCATE MEMORY FOR THE FLOW MATRIX AND WE INITIALIZE TO (0,0) THE FLOW */
  ami_calloc2d(u2,float,*height,*width);
  ami_calloc2d(v2,float,*height,*width);

  /* WE FILL THE FLOW MATRIX WITH THE FILE INFORMATION AND WE INVERSE THE ROW ORDER */
  for(m=0;m<size;m++){
	  if( fscanf(fptr,"%d %d %f %f\n",&j,&i,&up,&vp)!=EOF){

#ifdef TOP_LEFT_ORIGIN

		u2[i][j]=up;
		v2[i][j]=-vp;
#else

		u2[*height-1-i][j]=up;
		v2[*height-1-i][j]=vp;
#endif
      
	  }
	  else m=size;
  }

  fclose(fptr);
  *u=u2;
  *v=v2;
  return(0);

}

// ....................................................................................
// ....................................................................................

/**
 *
 *	FUNCTION TO READ AN ASCCI FILE WITH THE OPTIC FLOW INFORMATION
 *   IMPORTANT: WE INVERSE THE ROW ORDER (U, V images have 1d)
 * 
 */
int ami_read_optic_flow_v2(
  char name[200], /** name of the input flow file */
  float **u, float **v, /** output flow matrix */ 
  int *width, int *height, char tag[50]) /** image dimensions */
{
  int i,j,c;
  //int k;
  FILE *fptr;
  char paso[200];
  long m,size;
  float up,vp,*u2,*v2;

  // Open file
  if ((fptr = fopen(name,"r")) == NULL) {
    fprintf(stderr,"Unable to open  file \"%s\"\n",name);
    return(-2);
  }

// ...................

  // WE SKIP THE COMMENT HEAD PART OF THE FILE
  fscanf(fptr, "%s",paso);
  while(paso[0]=='#' ) {
 
     if ( paso[1]==':' && paso[2]=='#' ) {

	fscanf(fptr, "%s",paso);
        strcpy( tag, paso );

        //printf("Tag: %s  %s  %s\n", tag, paso, paso+4 );
     }

     while( (c=getc(fptr)) != '\n' );

     fscanf(fptr, "%s",paso);
//	printf("paso : %s\n",paso);
  }

// ...................

  // WE READ THE IMAGE DIMENSION
  *width=atoi(paso);
  fscanf(fptr,"%d",height);
  size=(*width)*(*height);
  printf("dimensions : %d %d\n",*width,*height);


  // WE ALLOCATE MEMORY FOR THE FLOW MATRIX AND WE INITIALIZE TO (0,0) THE FLOW
  ami_calloc1d( u2, float, size );  // *height, *width );
  ami_calloc1d( v2, float, size );  // *height, *width );

  // Init images with a NULL value (10000)
  for(m=0;m<size;m++)
  {
      u2[m] = UV_NULL_VALUE; //(float) NULL_VALUE;
      v2[m] = UV_NULL_VALUE; //(float) NULL_VALUE;
  }


  // WE FILL THE FLOW MATRIX WITH THE FILE INFORMATION AND WE INVERSE THE ROW ORDER
  for(m=0;m<size;m++){

 	  if( fscanf(fptr,"%d %d %f %f\n",&j,&i,&up,&vp)!=EOF){


#ifdef TOP_LEFT_ORIGIN

		u2[i*(*width) + j] = up;
		v2[i*(*width) + j] = -vp;
#else

		u2[(*height-1-i)*(*width) + j] = up;
		v2[(*height-1-i)*(*width) + j] = -vp;

//		u2[i*(*width) + j] = up;
//		v2[i*(*width) + j] = vp; //-vp;
#endif

	  }
	  else m=size;
  }

  fclose(fptr);
  *u=u2;
  *v=v2;

  return(0);
}

// ....................................................................................
// ....................................................................................

// ....................................................................................
// ....................................................................................


/**
	FUNCTION TO WRITE AN ASCCI FILE WITH THE OPTIC FLOW INFORMATION INCLUDING PARAMETERS
    IMPORTANT: WE INVERSE THE ROW ORDER 

	\param name name of the outpput flow file
	\param parameter_file name of the parameter file to be included in the header of the flow file
	\param u,v flow matrix
	\param width,height dimension of the images
	\param x_init
	\param y_init
	\param x_interval_size
	\param y_interval_size  
*/
int ami_write_optic_flow(
   char name[200],/* name of the outpput flow file */
   char parameter_file[200],/* name of the parameter file to be included in the header of the flow file */
   float **u,float **v, /* flow matrix */
   int width,int height, /* dimension of the images */
int x_init, int y_init,int x_interval_size, int y_interval_size)
{
  int i,j,c;
  //int k;
  FILE *fptr,*gptr;
  //char paso[200];

  /* Open file output */
  if ((fptr = fopen(name,"w")) == NULL) {
    fprintf(stderr,"Unable to open  file \"%s\"\n",name);
    return(-2);
  }

   /* Open parameter file */
  if ((gptr = fopen(parameter_file,"r")) == NULL) {
    fprintf(stderr,"Unable to open  parameter file \"%s\"\n",name);
    return(-2);
  }

  /* We copy the parameter file as header of the flow file */
  while( (c=getc(gptr))!=EOF){
	putc(c,fptr);
  }
  fclose(gptr);

  /* We add some extra information */
  fprintf(fptr,"%s FILE FORMAT : \n","#");
  fprintf(fptr,"%s IMAGE DIMENSIONS  \n","#");
  fprintf(fptr,"%s HORIZONTAL_COORDINATE_PIXEL VERTICAL_COORDINATE_PIXEL HORIZONTAL_FLOW_COMPONENT VERTICAL_FLOW_COMPONENT \n","#");
  fprintf(fptr,"%s INITIAL COORDINATE PIXEL POINT : (%d,%d) \n","#",x_init,y_init);
  fprintf(fptr,"%s DISPLACEMENT BETWEEN PIXELS : (%d,%d) \n","#",x_interval_size,y_interval_size);

  /* We write in the file the image dimensions */
  fprintf(fptr,"%d %d\n",width,height);

  /* We write in the file the flow information. WE INVERSE THE ORDER OF ROWS */
  for(i=y_init;i<height;i+=y_interval_size)
	  for(j=x_init;j<width;j+=x_interval_size){
		  //fprintf(fptr,"%d %d %1.1f %1.1f\n",j,i,u[height-1-i][j],v[height-1-i][j]);

#ifdef TOP_LEFT_ORIGIN

     #ifdef PX_2PRECISION
            fprintf(fptr,"%d %d %1.2f %1.2f\n",j,i,u[i][j],-v[i][j]);
     #else
            fprintf(fptr,"%d %d %1.1f %1.1f\n",j,i,u[i][j],-v[i][j]);
     #endif

#else


     #ifdef PX_2PRECISION
            fprintf(fptr,"%d %d %1.2f %1.2f\n",j,i,u[height-1-i][j],-v[height-1-i][j]);
//            fprintf(fptr,"%d %d %1.2f %1.2f\n",j,i,u[i][j],-v[i][j]);
     #else
            fprintf(fptr,"%d %d %1.1f %1.1f\n",j,i,u[height-1-i][j],-v[height-1-i][j]);
//            fprintf(fptr,"%d %d %1.1f %1.1f\n",j,i,u[i][j],-v[i][j]);
     #endif

#endif

      }
  fclose(fptr);
  return(0);

}



// .............................................
// .............................................

/**
	FUNCTION TO WRITE AN ASCCI FILE WITH THE OPTIC FLOW INFORMATION INCLUDING PARAMETERS
    IMPORTANT: WE INVERSE THE ROW ORDER

	\param name name of the outpput flow file
	\param parameter_file name of the parameter file to be included in the header of the flow file
	\param u,v flow matrix
	\param width,height dimension of the images
	\param x_init
	\param y_init
	\param x_interval_size
	\param y_interval_size
*/
int ami_write_optic_flow_v2(
   const char name[200],/* name of the outpput flow file */
   const char parameter_file[200],/* name of the parameter file to be included in the header of the flow file */
   float *u,float *v, /* flow matrix */
   int width,int height, /* dimension of the images */
   int x_init, int y_init,int x_interval_size, int y_interval_size)
{
  int i,j,c;
  //int k;
  FILE *fptr,*gptr;
  //char paso[200];

  /* Open file output */
  if ((fptr = fopen(name,"w")) == NULL) {
    fprintf(stderr,"Unable to open  file \"%s\"\n",name);
    return(-2);
  }

   /* Open parameter file */

  if ((gptr = fopen(parameter_file,"r")) == NULL) {
    fprintf(stderr,"Unable to open  parameter file \"%s\"\n",name);
    return(-2);
  }

  // We copy the parameter file as header of the flow file 
  while( (c=getc(gptr))!=EOF){
    putc(c,fptr);
  }
  fclose(gptr);

  
  /* We add some extra information */
  fprintf(fptr,"%s FILE FORMAT : \n","#");
  fprintf(fptr,"%s IMAGE DIMENSIONS  \n","#");
  fprintf(fptr,"%s HORIZONTAL_COORDINATE_PIXEL VERTICAL_COORDINATE_PIXEL HORIZONTAL_FLOW_COMPONENT VERTICAL_FLOW_COMPONENT \n","#");
  fprintf(fptr,"%s INITIAL COORDINATE PIXEL POINT : (%d,%d) \n","#",x_init,y_init);
  fprintf(fptr,"%s DISPLACEMENT BETWEEN PIXELS : (%d,%d) \n","#",x_interval_size,y_interval_size);

  /* We write in the file the image dimensions */
  fprintf(fptr,"%d %d\n",width,height);

  /* We write in the file the flow information. WE INVERSE THE ORDER OF ROWS */
  for(i=y_init;i<height;i+=y_interval_size)
	  for(j=x_init;j<width;j+=x_interval_size){
		  //fprintf(fptr,"%d %d %1.1f %1.1f\n",j,i,u[height-1-i][j],v[height-1-i][j]);

#ifdef TOP_LEFT_ORIGIN

     #ifdef PX_2PRECISION
            fprintf(fptr,"%d %d %1.2f %1.2f\n",j,i,u[i*width+j],-v[i*width+j]);
     #else
            fprintf(fptr,"%d %d %1.1f %1.1f\n",j,i,u[i*width+j],-v[i*width+j]);
     #endif

#else

     #ifdef PX_2PRECISION
            fprintf(fptr,"%d %d %1.2f %1.2f\n",j,i,u[(height-1-i)*width+j],-v[(height-1-i)*width+j]);
//            fprintf(fptr,"%d %d %1.2f %1.2f\n",j,i,u[i*width+j],-v[i*width+j]);
     #else
            fprintf(fptr,"%d %d %1.1f %1.1f\n",j,i,u[(height-1-i)*width+j],-v[(height-1-i)*width+j]);     
//            fprintf(fptr,"%d %d %1.1f %1.1f\n",j,i,u[i*width+j],-v[i*width+j]);
     #endif

#endif

      }
  fclose(fptr);
  return(0);

}


// .............................................
// .............................................



/**
	FUNCTION  TO SAVE MULTISCALE STRUCTURE TENSOR OPTIC FLOW ESTIMATION METHOD PARAMETER
*/
int ami_write_parameters_optic_flow_structure_tensor(char name[200],int Nscales,float *sigma,float eigenvalue_max_1_treshold,
               ami_window window_radius,int zoom_factor,int local_window_search_radius,int radius_window_median_filter,float **weigth )
 {
    int i;
    //int k,j;
	FILE *fptr;
	/* Open file */
    if ((fptr = fopen(name,"w")) == NULL) {
      fprintf(stderr,"Unable to open  parameter file \"%s\"\n",name);
      return(-2);
    }
	fprintf(fptr,"%s\n","# AMI Optic Flow Structure Tensor method parameters \n");
    fprintf(fptr,"%s = $ %d \n","# Number of Scales to compute the structure tensor information ", Nscales);
    for(i=0;i<Nscales;i++)
	  fprintf(fptr,"%s %d = $ %f \n","# Gaussian standard deviation at scale  ",i,sigma[i] );
    fprintf(fptr,"%s = $ %f \n","# Threshold on the maximun eiggenvalue ",eigenvalue_max_1_treshold);
	fprintf(fptr,"%s = $ %d \n","# Mimimum horizontal value in the search window ",window_radius[0]);
    fprintf(fptr,"%s = $ %d \n","# Maximum horizontal value in the search window ",window_radius[1]);
    fprintf(fptr,"%s = $ %d \n","# Mimimum vertical value in the search window ",window_radius[2]);
    fprintf(fptr,"%s = $ %d \n","# Maximum vertical value in the search window ",window_radius[3]);
    fprintf(fptr,"%s = $ %d \n","# ZOOM in the piramidal approach ", zoom_factor);
    fprintf(fptr,"%s = $ %d \n","#  Window Sarch Radius in the ZOOM process ", local_window_search_radius);
    fprintf(fptr,"%s = $ %d \n","# Radius of the Window Median Filter ", radius_window_median_filter);
    for(i=0;i<Nscales;i++)
	  fprintf(fptr,"%s %d = $ %f \n","# Weight of Gaussian convolution parameter at scale  ",i,weigth[i][0] );
    for(i=0;i<Nscales;i++)
	  fprintf(fptr,"%s %d = $ %f \n","# Weight of Maximum eigenvalue parameter at scale  ",i,weigth[i][1] );
    for(i=0;i<Nscales;i++)
	  fprintf(fptr,"%s %d = $ %f \n","# Weight of Minimum eigenvalue parameter at scale  ",i,weigth[i][2] );
    for(i=0;i<Nscales;i++)
	  fprintf(fptr,"%s %d = $ %f \n","# Weight of the MultiOrientation parameter at scale  ",i,weigth[i][3] );


    fclose(fptr);

	return(0);
  }

 /**
	FUNCTION TO READ  MULTISCALE STRUCTURE TENSOR OPTIC FLOW ESTIMATION METHOD PARAMETER
*/
int ami_read_parameters_optic_flow_structure_tensor(char name[200],int *Nscales,float **sigma,float *eigenvalue_max_1_treshold,
               ami_window window_radius,int *zoom_factor,int *local_window_search_radius,int *radius_window_median_filter,float ***weigth )
{
  int k;
  //int i,j;
  char paso[200];
  float *sigma2,**weigth2,pf;
  FILE *fptr;
  /* Open file */
  if ((fptr = fopen(name,"r")) == NULL) {
    fprintf(stderr,"Unable to open  parameter file \"%s\"\n",name);
    return(-2);
  }

  k=0;
  while( (fscanf(fptr, "%s",paso)!=EOF) && k==0 ){
   if(paso[0]=='$'){
	  fscanf(fptr, "%d",Nscales);
	  k++;
	}
  }
  /* WE ALLOCATE MEMORY */
  ami_malloc1d(sigma2,float,*Nscales);
  ami_malloc2d(weigth2,float,*Nscales,4);

  k=0;
  while( (fscanf(fptr, "%s",paso)!=EOF) && k<*Nscales ){
   if(paso[0]=='$'){
	  fscanf(fptr,"%f\n",&pf);
	  sigma2[k]=pf;
	  k++;
	}
  }

  k=0;
  while( (fscanf(fptr, "%s",paso)!=EOF) && k==0 ){
   if(paso[0]=='$'){
	  fscanf(fptr,"%f\n",eigenvalue_max_1_treshold);
	  k++;
	}
  }

  k=0;
  while( (fscanf(fptr, "%s",paso)!=EOF) && k<4 ){
   if(paso[0]=='$'){
	  fscanf(fptr,"%d\n",&(window_radius[k]));
	  k++;
	}
  }

  k=0;
  while( (fscanf(fptr, "%s",paso)!=EOF) && k==0 ){
   if(paso[0]=='$'){
	  fscanf(fptr,"%d\n",zoom_factor);
	  k++;
	}
  }

  k=0;
  while( (fscanf(fptr, "%s",paso)!=EOF) && k==0 ){
   if(paso[0]=='$'){
	  fscanf(fptr,"%d\n",local_window_search_radius);
	  k++;
	}
  }

  k=0;
  while( (fscanf(fptr, "%s",paso)!=EOF) && k==0 ){
   if(paso[0]=='$'){
	  fscanf(fptr,"%d\n",radius_window_median_filter);
	  k++;
	}
  }

  k=0;
  while( (fscanf(fptr, "%s",paso)!=EOF) && k<*Nscales ){
   if(paso[0]=='$'){
	  fscanf(fptr,"%f\n",&pf);
	  weigth2[k][0]=pf;
	  k++;
	}
  }

  k=0;
  while( (fscanf(fptr, "%s",paso)!=EOF) && k<*Nscales ){
   if(paso[0]=='$'){
	  fscanf(fptr,"%f\n",&pf);
	  weigth2[k][1]=pf;
	  k++;
	}
  }

  k=0;
  while( (fscanf(fptr, "%s",paso)!=EOF) && k<*Nscales ){
   if(paso[0]=='$'){
	  fscanf(fptr,"%f\n",&pf);
	  weigth2[k][2]=pf;
	  k++;
	}
  }

  k=0;
  while( (fscanf(fptr, "%s",paso)!=EOF) && k<*Nscales ){
   if(paso[0]=='$'){
	  fscanf(fptr,"%f\n",&pf);
	  weigth2[k][3]=pf;
	  k++;
	}
  }

  fclose(fptr);
  *weigth=weigth2;
  *sigma=sigma2;
  if(k!=*Nscales) { printf(" ami_read_parameters_optic_flow_structure_tensor() read problem \n"); return(-1); }
  return(0);
}



/**
	FUNCTION TO WRITE IN DISK THE PARAMETERS OF THE AMI CORRELATION OPTIC FLOW METHOD

	\param name name for the parameter file 
	\param x_init,y_init initial coordinate point to compute the correlation 
	\param x_interval_size,y_interval_size displacement between points for computing the correlation
	\param size_correlation_window size of correlation window. it has to be a power of 2
 */
int ami_write_parameters_optic_flow_correlation(
  char name[200], /* name for the parameter file */
  int x_init,int y_init, /* initial coordinate point to compute the correlation */
  int x_interval_size, int y_interval_size, /* displacement between points for computing the correlation */
  int size_correlation_window) /* size of correlation window. it has to be a power of 2 */
{
  FILE *fptr;
  /* Open file */
  if ((fptr = fopen(name,"w")) == NULL) {
    fprintf(stderr,"Unable to open  parameter file \"%s\"\n",name);
    return(-2);
  }
  fprintf(fptr,"%s\n","# AMI Optic Flow CORRELATION method parameters \n");
  fprintf(fptr,"%s = $ %d \n","# horizontal initial coordinate point", x_init);
  fprintf(fptr,"%s = $ %d \n","# vertical initial coordinate point",y_init);
  fprintf(fptr,"%s = $ %d \n","# horizontal displacement between points",x_interval_size);
  fprintf(fptr,"%s = $ %d \n","# vertical displacement between points",y_interval_size);
  fprintf(fptr,"%s = $ %d \n","# size of correlation window. it has to be a power of 2 ",size_correlation_window);

  fclose(fptr);
  return(0);

}


/**
	FUNCTION TO READ FROM DISK THE PARAMETERS OF THE AMI CORRELATION OPTIC FLOW METHOD

	\param name name for the parameter file
	\param x_init,y_init initial coordinate point to compute the correlation
	\param x_interval_size,y_interval_size displacement between points for computing the correlation
	\param size_correlation_window size of correlation window. it has to be a power of 2
 */
int ami_read_parameters_optic_flow_correlation(
  char name[200], /* name for the parameter file */
  int *x_init,int *y_init, /* initial coordinate point to compute the correlation */
  int *x_interval_size, int *y_interval_size, /* displacement between points for computing the correlation */
  int *size_correlation_window) /* size of correlation window. it has to be a power of 2 */
{
  //int j;
  int i,Nparams=5;
  char paso[200];
  FILE *fptr;
  /* Open file */
  if ((fptr = fopen(name,"r")) == NULL) {
    fprintf(stderr,"Unable to open  parameter file \"%s\"\n",name);
    return(-2);
  }
  i=0;
  while( (fscanf(fptr, "%s",paso)!=EOF) && i<Nparams ){
	if(i==0 && paso[0]=='$'){
	  fscanf(fptr, "%d",x_init);
	  i++;
	}
	else if(i==1 && paso[0]=='$'){
	  fscanf(fptr, "%d",y_init);
	  i++;
	}
	else if(i==2 && paso[0]=='$'){
	  fscanf(fptr, "%d",x_interval_size);
	  i++;
	}
	else if(i==3 && paso[0]=='$'){
	  fscanf(fptr, "%d",y_interval_size);
	  i++;
	}
	else if(i==4 && paso[0]=='$'){
	  fscanf(fptr, "%d",size_correlation_window);
	  i++;
	}
  }

  if(i!=Nparams) return(-1);

  fclose(fptr);
  return(0);
}


/**
	FUNCTION TO WRITE IN DISK THE PARAMETERS OF THE AMI PDE OPTIC FLOW METHOD
	
	\param name
	\param hx pixel size in x direction 
	\param hy pixel size in y direction
	\param sigma Gaussian scale smoothing image data
	\param T stopping time
	\param alpha smoothness weight
	\param dtype type of smoothness term
	\param quantile isotropy fraction 
	\param ht time step size 
	\param Niter Number of Iterations for Gauss-Seidel 
	\param Nzoom Number of zooms to apply in the piramidal approach
 */
int ami_write_parameters_optic_flow_pde(
  char name[200],
  float    hx,          /* pixel size in x direction */
  float    hy,          /* pixel size in y direction */
  float    sigma,       /* Gaussian scale smoothing image data */
  float    T,           /* stopping time */
  float    alpha,       /* smoothness weight */
  long     dtype,       /* type of smoothness term */
  float    quantile,    /* isotropy fraction */
  float    ht,          /* time step size */
  int Niter,            /* Number of Iterations for Gauss-Seidel */
  long Nzoom)           /* Number of zooms to apply in the piramidal approach */
{
  FILE *fptr;
  /* Open file */
  if ((fptr = fopen(name,"w")) == NULL) {
    fprintf(stderr,"Unable to open  parameter file \"%s\"\n",name);
    return(-2);
  }
  fprintf(fptr,"%s\n","# AMI Optic Flow PDE method parameters \n");
  fprintf(fptr,"%s = $ %f \n","# pixel size in x direction",hx);
  fprintf(fptr,"%s = $ %f \n","# pixel size in y direction",hy);
  fprintf(fptr,"%s = $ %f \n","# Gaussian scale smoothing image data",sigma);
  fprintf(fptr,"%s = $ %f \n","# Stopping time for solving the pde",T);
  fprintf(fptr,"%s = $ %f \n","# smoothness weight",alpha);
  fprintf(fptr,"%s = $ %d \n","# type of smoothness term",(int) dtype);
  fprintf(fptr,"%s = $ %f \n","# isotropy fraction",quantile);
  fprintf(fptr,"%s = $ %f \n","# time step size",ht);
  fprintf(fptr,"%s = $ %d \n","# Number of Iterations for Gauss-Seidel",(int) Niter);
  fprintf(fptr,"%s = $ %d \n","# Number of zooms to apply in the piramidal approach",(int) Nzoom );

  fclose(fptr);
  return(0);
}

/**
     FUNCTION TO READ FROM DISK THE PARAMETERS OF THE AMI PDE OPTIC FLOW METHOD

     \param name
     \param hx pixel size in x direction
	 \param hy pixel size in y direction
	 \param sigma Gaussian scale smoothing image data
	 \param T stopping time
	 \param alpha smoothness weight
	 \param dtype type of smoothness term
	 \param quantile isotropy fraction
	 \param ht time step size
	 \param Niter Number of Iterations for Gauss-Seidel
	 \param Nzoom Number of zooms to apply in the piramidal approach
  */  
int ami_read_parameters_optic_flow_pde(
  char name[200],
  float    *hx,          /* pixel size in x direction */
  float    *hy,          /* pixel size in y direction */
  float    *sigma,       /* Gaussian scale smoothing image data */
  float    *T,           /* stopping time */
  float    *alpha,       /* smoothness weight */
  long     *dtype,       /* type of smoothness term */
  float    *quantile,    /* isotropy fraction */
  float    *ht,          /* time step size */
  int *Niter,            /* Number of Iterations for Gauss-Seidel */
  long *Nzoom)            /* Number of zooms to apply in the piramidal approach */
{
  int i,j,Nparams=10;
  char paso[200];
  FILE *fptr;
  /* Open file */
  if ((fptr = fopen(name,"r")) == NULL) {
    fprintf(stderr,"Unable to open  parameter file \"%s\"\n",name);
    return(-2);
  }
  i=0;
  while( (fscanf(fptr, "%s",paso)!=EOF) && i<Nparams  ){
	if(i==0 && paso[0]=='$'){
	  fscanf(fptr, "%f",hx);
	  i++;
	}
	else if(i==1 && paso[0]=='$'){
	  fscanf(fptr, "%f",hy);
	  i++;
	}
	else if(i==2 && paso[0]=='$'){
	  fscanf(fptr, "%f",sigma);
	  i++;
	}
	else if(i==3 && paso[0]=='$'){
	  fscanf(fptr, "%f",T);
	  i++;
	}
	else if(i==4 && paso[0]=='$'){
	  fscanf(fptr, "%f",alpha);
	  i++;
	}
	else if(i==5 && paso[0]=='$'){
	  fscanf(fptr, "%d",&j);
	  *dtype=j;
	  i++;
	}
	else if(i==6 && paso[0]=='$'){
	  fscanf(fptr, "%f",quantile);
	  i++;
	}
	else if(i==7 && paso[0]=='$'){
	  fscanf(fptr, "%f",ht);
	  i++;
	}
	else if(i==8 && paso[0]=='$'){
	  fscanf(fptr, "%d",Niter);
	  i++;
	}
	else if(i==9 && paso[0]=='$'){
	  fscanf(fptr, "%d",&j);
	  *Nzoom=j;
	  i++;
	}
  }

  if(i!=Nparams) return(-1);

  fclose(fptr);
  return(0);
}
