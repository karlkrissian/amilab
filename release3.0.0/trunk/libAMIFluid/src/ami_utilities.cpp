
#if defined(_MSC_VER)
#define _USE_MATH_DEFINES
#include <math.h>
#endif

#include "ami_utilities.h"
#include "ami_image_file.h"
#include "ami.h"


/**
 * FUNCION QUE DIBUJA UN SEGMENTO 
 *
 * \param data  IMAGEN DONDE SE VA A DIBUJAR EL SEGMENTO
 * \param width,height  DIMENSIONES DE LA IMAGEN
 * \param x0,y0  COORDENADAS 1 PUNTO DEL SEGMENTO 
 * \param x1,y1  COORDENADAS 2 PUNTO DEL SEGMENTO 
 * \param color  COLOR CON EL QUE SE RELLENA EL SEGMENTO 
 */
void ami_dibujar_segmento(
   float *data, /* IMAGEN DONDE SE VA A DIBUJAR EL SEGMENTO */
   int width, int height, /* DIMENSIONES DE LA IMAGEN */
   int x0, int y0, /* COORDENADAS 1 PUNTO DEL SEGMENTO */
   int x1, int y1,  /* COORDENADAS 2 PUNTO DEL SEGMENTO */
   float color)     /* COLOR CON EL QUE SE RELLENA EL SEGMENTO */
{
 int incx = ami_abs(x1 - x0);
 int incy = ami_abs(y1 - y0);
 int p, dx, dy;
 int x, y;
 int temp;
 int nx=width;
// int ny=height;

 if (incx>incy) {
   if (x0>x1){
     temp=x0; x0=x1; x1=temp;
     temp=y0; y0=y1; y1=temp;
   }
   x=x0; y=y0;
   p = 2*incy - incx;
   dy = (y1>y0)? 1 : -1;
   data[y*nx+x] = color;
   do {
     if (p<0) {
       p += 2*incy;
     } else {
       p += 2*incy - 2*incx;
       y += dy;
     }
     x++;
     data[y*nx+x] = color;
   } while (x<x1);
 } else {
     if (y0>y1) {
       temp=x0; x0=x1; x1=temp;
       temp=y0; y0=y1; y1=temp;
     }
     x=x0; y=y0;
     p = 2*incx - incy;
     dx = (x1>x0)? 1 : -1;
     data[y*nx+x] = color;
     do {
       if (p<0) {
         p += 2*incx;
       } else {
         p += 2*incx - 2*incy;
	 x += dx;
       }
       y++;
       data[y*nx+x] = color;
    } while (y<y1);
  }
}


/**
 * ALGORITMO DE SEMILLA PARA RELLENAR LA IMAGEN A PARTIR DE UN NIVEL CON OTRO NIVEL
 *
 * \param m  POSICION DEL PUNTO ACTUAL 
 * \param imagen  IMAGEN DE ENTRADA 
 * \param width  ANCHO DE LA IMAGEN
 * \param size  TAMANO DE LA IMAGEN 
 * \param nivel1  NIVEL QUE SE VA MODIFICAR
 * \param nivel2  NIVEL CON EL QUE SE RELLENA
 */
void ami_semilla(
   long m /* POSICION DEL PUNTO ACTUAL */,
   float *imagen /* IMAGEN DE ENTRADA */ ,
   unsigned short width /* ANCHO DE LA IMAGEN*/ ,
   long size/* TAMANO DE LA IMAGEN */ ,
   float nivel1 /* NIVEL QUE SE VA MODIFICAR */,
   float nivel2 /* NIVEL CON EL QUE SE RELLENA*/)
{
   imagen[m]=nivel2;
   if((m-1)>=0){
   	if(imagen[m-1]==nivel1 )
   	    ami_semilla(m-1,imagen,width,size,nivel1,nivel2);
   }
   if((m+1)<size){
   	if(imagen[m+1]==nivel1)
   	    ami_semilla(m+1,imagen,width,size,nivel1,nivel2);
   }
   if((m-width)>=0){
   	if(imagen[m-width]==nivel1)
   	    ami_semilla(m-width,imagen,width,size,nivel1,nivel2);
   }
   if((m+width)<size){
   	if(imagen[m+width]==nivel1)
   	    ami_semilla(m+width,imagen,width,size,nivel1,nivel2);
   }
}


/**
 * Convol:								
 * It returns the result in the same image.		
 */
void Convol(float **image, int nx, int ny, float **mask, int mx, int my)
{
    float **aux, sum;
    int i, j, k, l;
    int mxx, myy, dimx, dimy;
    mxx=(int)mx/2; myy=(int)my/2;
    dimx=nx+2*mxx; dimy=ny+2*myy;

    /* storage memory */
    //alloc_matrix(&aux, dimx, dimy);
    ami_malloc2d(aux,float,dimx,dimy);

    /* copy the image */
    for(i=0;i<nx;i++)
	for(j=0;j<ny;j++)
	    aux[i+mxx][j+myy]=image[i][j];


    /* fill the borders */
    /* first rows */
    for(i=0;i<mxx;i++)
	for(j=0;j<ny;j++)
	    aux[i][j+myy]=image[0][j];
    /* last rows */
    for(i=nx;i<nx+mxx;i++)
	for(j=0;j<ny;j++)
	    aux[i+mxx][j+myy]=image[nx-1][j];
    /* first columns */
    for(j=0;j<myy;j++)
	for(i=0;i<nx;i++)
	    aux[i+mxx][j]=image[i][0];
    /* last columns */
    for(j=ny;j<ny+myy;j++)
	for(i=0;i<nx;i++)
	    aux[i+mxx][j+myy]=image[i][ny-1];

    /* fill top-left corner */
    for(i=0;i<mxx;i++)
	for(j=0;j<myy;j++)
	    aux[i][j]=image[0][0];
    /* fill top-right corner */
    for(i=0;i<mxx;i++)
	for(j=ny;j<ny+myy;j++)
	    aux[i][j+myy]=image[0][ny-1];
    /* fill bottom-left corner */
    for(i=nx;i<nx+mxx;i++)
	for(j=0;j<myy;j++)
	    aux[i+mxx][j]=image[nx-1][0];
    /* fill bottom-right corner */
    for(i=nx;i<nx+mxx;i++)
	for(j=ny;j<ny+myy;j++)
	    aux[i+mxx][j+myy]=image[nx-1][ny-1];

   /* printf("We have already copied the corners\n");*/

    /* we begin with the convolution */
    for(i=mxx;i<nx+mxx;i++)
	for(j=myy;j<ny+myy;j++){
	    sum=0;
	    for(k=0;k<mx;k++)
		for(l=0;l<my;l++)
		    sum+=aux[i-mxx+k][j-myy+l]*mask[k][l];
	    /* printf("(%d, %d) , ", i, j);*/
	    /* we put the result in the original image */
	    image[i-mxx][j-myy]=sum;
	}

    ami_free2d(aux);
}






/**
 * EZoom:								    
 * This function makes a zoom by reducing the size of the "input" 	    
 * image in a "scale" factor.
 * We create a new image ("output") and modify the initial dimensions.
 */
float **EZoom(float **input, long *nx, long *ny, long scale)
{
    long i, j, ii, jj;
    float **output;

    /* allocate zoom matrix */
    //alloc_matrix (&output, (long)((float)*nx/scale+0.5), (long)((float)*ny/scale+0.5));
    /*printf("nx, ny(%ld, %ld), (%lf, %lf) scale=%ld\n", *nx, *ny, ((float)*nx/scale+0.5), ((float)*ny/scale+0.5), scale);*/
	ami_malloc2d(output, float, (long)((float)*nx/scale+0.5), (long)((float)*ny/scale+0.5));


    /* zoomization */
    ii=0;
    for(i=0;i<*nx;i+=scale){
	jj=0;
	for(j=0;j<*ny;j+=scale){
	    output[ii][jj]=input[i][j];
	    jj++;
	}
	ii++;
    }

    /* new dimensions */
    *nx=(long)((float)*nx/scale+0.5);
    *ny=(long)((float)*ny/scale+0.5);

	//printf("EZoom: nx=%d ny=%d\n",(int) *nx, (int) *ny);
    //scanf("%d",&i);
    /*printf(" salimos del zoom\n");*/

    return output;
}

/**
 * DZoom:								    
 * This function realizes the opposite to the previous one	and 	    
 * multiply the input by scale to keep the correspondence.	    
 */
float **DZoom(float **input, long maxx, long maxy, long nx, long ny, long scale)
{
    long i, j, ii, jj, k, l;
    float **output;

    /* new dimensions */
    nx=(long)(nx*scale);
    ny=(long)(ny*scale);

    /* allocate zoom matrix */
    //alloc_matrix (&output, maxx, maxy);
	ami_malloc2d(output, float, maxx, maxy);

    /*printf("nx, ny(%ld, %ld), max(x, y)=(%ld, %ld) scale=%ld\n", nx, ny, maxx, maxy, scale);*/

    /* zoomization */
    ii=0;
    for(i=0;i<nx;i+=scale){
	jj=0;
	for(j=0;j<ny;j+=scale){
	    for(k=0;k<scale;k++)
		for(l=0;l<scale;l++){
			if(((k+i)<maxx)&&((j+l)<maxy))
			    output[i+k][j+l]=scale*input[ii][jj];
		}
	    jj++;
	}
	ii++;
    }
	/*printf("Salimos del Dzoom\n");*/
    //printf("DZoom: nx=%d ny=%d\n",(int) nx, (int) ny);
    //scanf("%d",&i);

    return output;
}



/**
 *	ZoomSerie:							     
 *	This procedure computes several zooms for a given image.	    
 *	It applies a
 */
long ZoomSerie(float **f, float ****fout, long nx, long ny, long Nitera)
{
    long i, ii, jj, nxx, nyy, mx, my;
    char name[40];
    float **faux, **faux1;
/*    GraphicWindow **fzoom;*/
    float **mask;

    /* initializations */
    nxx=nx;nyy=ny;
    mx=my=3;

    /* allocate storage */
    *fout = (float ***) malloc (Nitera * sizeof(float *));
    /*fzoom=(GraphicWindow**)malloc(Nitera*sizeof(GraphicWindow*));*/
    //alloc_matrix (&faux1, nx, ny);
    //alloc_matrix (&mask, mx, my);
	ami_malloc2d(faux1, float,nx, ny);
    ami_malloc2d (mask, float,mx, my);

    /* mask values */
    mask[0][0]=mask[2][0]=mask[0][2]=mask[2][2]=0.07842776544;
    mask[1][0]=mask[0][1]=mask[1][2]=mask[2][1]=0.1231940459;
    mask[1][1]=0.1935127547;

    /* make the first zoom (image does not change)*/
    faux=EZoom(f, &nx, &ny, 1);

    /* copy the image */
    for(ii=0;ii<nx;ii++)
   	for( jj=0;jj<ny;jj++)
	    faux1[ii][jj]=faux[ii][jj];


    ami_free2d(faux);


    /* the rest of zooms */
    for(i=0;i<Nitera;i++)
    {
	/* make the next zoom */
	Convol(faux1, nx, ny, mask, mx, my);

	/* create the next image */
        sprintf(name,"Zoom_%ld", i*2);
        /*fzoom[i]=CreateImage(name,RIM,nx,ny,name);*/
        //alloc_matrix (&((*fout)[i]), nx, ny);
		ami_malloc2d((*fout)[i],float,nx,ny);

        /* keep the convolved image */
        for(ii=0;ii<nx;ii++)
	    for( jj=0;jj<ny;jj++){
		((*fout)[i])[ii][jj]=faux1[ii][jj];
    		/*fzoom[i]->RIMdata[jj*nx+ii]=faux1[ii][jj];*/
	    }

        faux=EZoom(faux1, &nx, &ny, 2);

        /* copy the image */
        for(ii=0;ii<nx;ii++)
	    for( jj=0;jj<ny;jj++)
		faux1[ii][jj]=faux[ii][jj];

        // disalloc_matrix (faux, nx, ny);
        ami_free2d (faux);


        /*ShowImage(fzoom[i]);*/
    }

    /* disalloc storage */
    //disalloc_matrix (faux1, nxx, nyy);
    //disalloc_matrix (mask, mx, my);
    ami_free2d(faux1);
	ami_free2d(mask);

    return Nitera;
}




/**
 * FUNCTION TO CREATE A 1024 X 1024 HISTOGRAM OF AN IMAGE AND TO SAVE IT AS A BMP FILE 
 */
int ami_histogram_1024_1024_16b_unsigned_short(char name[200],unsigned short *image,float **histograme)
{
  int i,j; //,k;
   int width=1024;
   int height=1024;
   long m,size=width*height;
//   float min;
   float max;
   unsigned char *red,*green,*blue;

   /* WE ALLOCATE THE MEMORY WE NEED */
   ami_malloc1d(red,unsigned char,size);
   ami_malloc1d(green,unsigned char,size);
   ami_malloc1d(blue,unsigned char,size);
   ami_calloc1d((*histograme),float,width);
   for(m=0;m<size;m++) red[m]=green[m]=blue[m]=255;
   for(m=0;m<size;m++) (*histograme)[image[m]>=width?width-1:image[m]]++;

   ami_max_vector((*histograme),i,max,width);
   for(j=0;j<width;j++){
	   for(i=0;i<height*(*histograme)[j]/(max*1.1);i++){
		   m=i*width+j;
		   red[m]=green[m]=blue[m]=0;
       }
   }

   ami_write_bmp(name,red,green,blue,width,height);
   free(red); free(green); free(blue);
     return(0);
}



/**
 * FUNCTION TO NORMALIZE THE HISTOGRAM OF image_2 TO FIT THE HISTOGRAM OF image_1 
 * WE IMPOSE THAT SUM_{k=0,..i}h_1[k] + uniform_distribution_weight * SUM_{k=0,..i}u_1[k] =
 * SUM_{k=0,..j}h_2[k] + uniform_distribution_weight * SUM_{k=0,..j}u_2[k], where u_1[] and
 * u_2[] are uniform distribution with the same mean and standard deviation than h_1 and h_2 
 */
void ami_histogram_normalization(float *image_1,float *image_2,long size_1,long size_2,float uniform_distribution_weight)
{
  long m,k,i,j,dim_1,dim_2;
  long double min_1,max_1,min_2,max_2,sum_1,sum_2,valor,sum_k,m_1,m_2,sd_1,sd_2,r_sd,a,b;
  long double *h_1,*h_2,*vector_transformacion_histograma;

  //printf("uniform_distribution_weight=%f\n",uniform_distribution_weight);
  /* WE COMPUTE THE MAX AND MIN OF THE IMAGES */
  ami_max_vector(image_1,i,max_1,size_1);
  ami_max_vector(image_2,i,max_2,size_2);
  ami_min_vector(image_1,i,min_1,size_1);
  ami_min_vector(image_2,i,min_2,size_2);
  dim_1=(long int)(max_1-min_1+1);
  dim_2=(long int)(max_2-min_2+1);

  /* WE COMPUTE MEAN AND STANDARD DEVIATION OF IMAGES */
  ami_media_vector(image_1,m_1,size_1);
  ami_desviacion_standard_vector(image_1,sd_1,size_1,m_1);
  ami_media_vector(image_2,m_2,size_2);
  ami_desviacion_standard_vector(image_2,sd_2,size_2,m_2);
  r_sd=sd_1/sd_2;

  a=(m_1-min_1)/sd_1;
  b=(m_2-min_2)/sd_2;
  if(b>a) a=b;



  printf("image_1 mean=%f, sd=%f\n",(float) m_1,(float) sd_1);
  printf("image_2 mean=%f, sd=%f\n",(float) m_2,(float) sd_2);

  /* WE ALLOCATE MEMORY FOR THE HISTOGRAM */
  ami_calloc1d(h_1,long double,dim_1);
  ami_calloc1d(h_2,long double,dim_2);
  ami_calloc1d(vector_transformacion_histograma,long double,dim_2);

  /* WE FILL THE HISTOGRAMS */
  for(m=0;m<size_1;m++) h_1[(int) (image_1[m]-min_1)]++;
  for(m=0;m<size_2;m++) h_2[(int) (image_2[m]-min_2)]++;

  /* WE NORMALIZE THE HISTOGRAMS IN ORDER TO SUM 1 */
  for(m=0;m<dim_1;m++) h_1[m]/=size_1;
  for(m=0;m<dim_2;m++) h_2[m]/=size_2;
  //ami_printf1d("h_1",h_1,dim_1);


  /* WE COMPUTE THE TRANSFORMATION VECTOR TO NORMALIZE THE HISTOGRAME OF image_2 */
  valor=0;
  sum_1=uniform_distribution_weight*(min_1-(m_1-a*sd_1))/(2.*a*sd_1);
  sum_2=uniform_distribution_weight*(min_2-(m_2-a*sd_2))/(2.*a*sd_2);
  j=0;
  for(i=0;i<dim_2;i++){
	sum_2+=1.*h_2[i]+uniform_distribution_weight/(2.*a*sd_2);
	k=j;
    //printf("estoy fuera i=%d, j=%d, k=%d sum_1=%f, sum_2=%f \n",i,j,k,sum_1,sum_2);
	sum_k=sum_1;
	while(sum_1<sum_2 && j<dim_1){
	  sum_1+=1.*h_1[j]+uniform_distribution_weight/(2.*a*sd_1);
	  j++;
    }
	if(j>k){
	  valor=k+(j-k)*(sum_1-sum_2)/(sum_1-sum_k);
	  vector_transformacion_histograma[i]=valor;
    }
	else{
	  vector_transformacion_histograma[i]=j;
    }
	//printf("i=%d, j=%d, k=%d sum_1=%f, sum_2=%f valor=%f\n",i,j,k,(float)sum_1,(float)sum_2,(float)valor);
  }


  /* WE TRANSFORM image_2 */
  for(m=0;m<size_2;m++)
	  image_2[m]=min_1+vector_transformacion_histograma[(int) (image_2[m]-min_2)];

  ami_media_vector(image_1,max_1,size_1);
  ami_media_vector(image_2,max_2,size_2);
  for(m=0;m<size_2;m++)
	image_2[m]=m_1+(image_2[m]-max_2);
  ami_media_vector(image_2,max_2,size_2);



  //printf("mean image_1 =%f average image_2 =%f\n",(float) max_1,(float) max_2);

  free(h_1);free(h_2); free(vector_transformacion_histograma);
//scanf("%d",&i);
}



/**
 * WINDOW MEDIAN FILTER                                                                       
 */
void ami_window_median_filter(float *image,int width,int height,int window_radius)
{
  int i,j,k,n,l,size2=(2*window_radius+1)*(2*window_radius+1);
  float *image_aux,*vaux;
  long m,size=width*height;

  ami_malloc1d(image_aux,float,size);
  ami_malloc1d(vaux,float,size2);

  for(m=0;m<size;m++) image_aux[m]=image[m];
  for(i=window_radius;i<(height-window_radius);i++){
	for(j=window_radius;j<(width-window_radius);j++){
	  l=0;
	  for(k=-window_radius;k<=window_radius;k++)
	    for(n=-window_radius;n<=window_radius;n++)
		  vaux[l++]=image_aux[(i+k)*width+(j+n)];
	  image[i*width+j]=ami_mediana_float(size2/2,size2,vaux);
    }
  }

  free(image_aux); free(vaux);
}




/**
 * CALCULA UNA AFININIDAD A PARTIR DE UN CONJUNTO DE CORRESPONDENCIAS DE 3 PUNTOS
 *
 * \param x,y  COORDINATES IN THE FIRST IMAGE 
 * \param xn,yn  COORDINATES IN THE SECOND IMAGE
 * \param H  OUTPUT AFFINITY
 * \param N  NUMBER OF CORRESPONDING POINTS (N=3)
 */
int ami_calculo_afinidad_3p(double *x,double *y /* COORDINATES IN THE FIRST IMAGE */,
                           double *xn,double *yn /* COORDINATES IN THE SECOND IMAGE */ ,
			   double H[3][3] /* OUTPUT AFFINITY*/,
			   int N /* NUMBER OF CORRESPONDING POINTS (N=3)*/)
{
  int i,j; //,k;
  double **A,*b,m[3];

  if(N!=3){
    printf("The number of corresponding points have to be 3\n");
    return(-1);
  }

  ami_calloc2d(A,double,6,6);
  ami_malloc1d(b,double,6);

  /* WE FILL THE MATRIX RELATIONS BETTWEEN POINTS TO COMPUTE THE AFFININTY*/
  for(i=0;i<3;i++){
    A[2*i][0]=x[i];
    A[2*i][1]=y[i];
    A[2*i][2]=1;
    b[2*i]=xn[i];
    A[2*i+1][3]=x[i];
    A[2*i+1][4]=y[i];
    A[2*i+1][5]=1;
    b[2*i+1]=yn[i];
  }

  /* WE COMPUTE THE HOMOGRAPHY USING THE GAUSS METHOD TO SOLVE THE LINEAR SYSTEM*/

  if(ami_gauss(A,b,6)==-1)
    return(-1);

  for(i=0;i<2;i++)
    for(j=0;j<3;j++)
      H[i][j]=b[i*3+j];
  H[2][0]=H[2][1]=0.;
  H[2][2]=1.;

  /* WE TEST THE HOMOGRAPHY */
/*
  printf("Test of the homography quality\n");
  for(i=0;i<N;i++){
    printf("(x,y)=(%f,%f), ",x[i],y[i]);
    printf("(xn,yn)=(%f,%f), ",xn[i],yn[i]);
    m[0]=x[i]; m[1]=y[i]; m[2]=1.;
    ami_matriz_vector(H,m,b,3,3);
    printf("(H(x,y)-(xn,yn)=(%1.1e,%1.1e)\n",b[0]/b[2]-xn[i],b[1]/b[2]-yn[i]);
  }
*/
  ami_free2d(A);
  free(b);
  return(0);

}





/**
 * FUNCION QUE CALCULA LA DISTANCIA DE UN PUNTO A UN SEGMENTO 
 *
 * \param x0,y0,x1,y1  COORDENADAS DEL SEGMENTO
 * \param x,y  COORDENADAS DEL PUNTO 
 *
 * \return DEVOLVEMOS EL MAXIMO ENTRE LA DISTANCIA A LA RECTA Y LA DISTANCIA DE LA PROYECCION AL SEGMENTO
 */
float ami_distancia_punto_segmento(
        int x0,int y0,int x1,int y1, /* COORDENADAS DEL SEGMENTO */
		int x,int y)  /* COORDENADAS DEL PUNTO */
{
  double dx=(x1-x0);
  double dy=(y1-y0);
  double norma;
  double nx=(x-x0);
  double ny=(y-y0);
  double p1,p2;

  /* CALCULAMOS EL VECTOR DIRECTOR DEL SEGMENTO */
  norma=dx*dx+dy*dy;
  if(norma<=0){
    return((float) sqrt((double) nx*nx+ny*ny));
  }
  norma=sqrt(norma);
  dx/=norma;
  dy/=norma;

  /* CALCULAMOS LAS COMPONENTES DEL VECTOR (nx,ny) EN LA BASE ASOCIADA A (dx,dy) */
  p1=dx*nx+dy*ny;
  p2=ami_abs(-dy*nx+dx*ny);

  /* COMPROBAMOS SI LA PROYECCI� SE SALE DEL SEGMENTO */
  p1=(p1>0?(p1<norma?0:(p1-norma)):-p1);

  /* DEVOLVEMOS EL MAXIMO ENTRE LA DISTANCIA A LA RECTA Y LA DISTANCIA DE LA
  PROYECCION AL SEGMENTO */
  if(p1>p2) return((float) p1);
  else return((float) p2);

}

/**
 * FUNCION QUE DETERMINA SI UN PUNTO CAE DENTRO DE UN RECTANGULO DEFORMADO. 
 *
 * \param x0,y0,x1,y1,x2,y2,x3,y3  COORDENADAS PUNTOS TETRAEDRO 
 * \param x,y  COORDENADAS PUNTO 
 *
 * \return DEVUELVE 0 SI EL PUNTO ESTA DENTRO Y -1 EN CASO CONTRARIO.
 */
int ami_test_interior_rectangulo(
   int x0,int y0,int x1,int y1,int x2,int y2,int x3,int y3, /* COORDENADAS PUNTOS TETRAEDRO */
   int x,int y) /* COORDENADAS PUNTO */
{
  double **A,*u,*v;
  ami_malloc2d(A,double,2,2);
  ami_malloc1d(u,double,2);
  ami_malloc1d(v,double,2);

  /* CALCULAMOS LAS COMPONENTES u[] DE (x2-x0,y2-y0) EN LA BASE DEL RECTANGULO DEFORMADO */
  A[0][0]=x1-x0; A[0][1]=x3-x0; u[0]=x2-x0;
  A[1][0]=y1-y0; A[1][1]=y3-y0; u[1]=y2-y0;
  if(ami_gauss(A,u,2)!=0){
	  ami_free2d(A); free(u); free(v);
	  return(-2);
  }

  /* CALCULAMOS LAS COMPONENTES v[] DE (x-x0,y-y0) EN LA BASE DEL RECTANGULO DEFORMADO */
  A[0][0]=x1-x0; A[0][1]=x3-x0; v[0]=x-x0;
  A[1][0]=y1-y0; A[1][1]=y3-y0; v[1]=y-y0;
  if(ami_gauss(A,v,2)!=0){
	  ami_free2d(A); free(u); free(v);
	  return(-2);
  }

  /* EL PUNTO ESTA DENTRO DEL RECTANGULO SI 0<=v[0]<=u[0] y 0<=v[1]<=u[1] */
  ami_free2d(A);
  if(v[0]>=0 && v[0]<=u[0] && v[1]>=0 && v[1]<=u[1]){
     free(u); free(v);
     return(0);
  }
  else{
     free(u); free(v);
     return(-1);
  }
}



/**
 * FUNCION QUE EVALUA LOS SPLINES EN UN PUNTO.
 *  
 * \param x  COORDENADAS PUNTOS INTERPOLANTES 
 * \param N  NUMERO DE PUNTOS INTERPOLANTES 
 * \param s  COEFICIENTES DE LOS POLINOMIOS SPLINES 
 * \param z  COORDENADA DEL PUNTO DONDE SE VA A INTERPOLAR 
 *
 * \return RETORNA EL VALOR INTERPOLADO
 */
float ami_evaluar_splines(
float *x, /* COORDENADAS PUNTOS INTERPOLANTES */
int N, /* NUMERO DE PUNTOS INTERPOLANTES */
float **s, /* COEFICIENTES DE LOS POLINOMIOS SPLINES */
float z)  /* COORDENADA DEL PUNTO DONDE SE VA A INTERPOLAR */
{
  int i,j;
  float t;

  /* CALCULAMOS EN QUE INTERVALO SE ENCUENTRA EL PUNTO */
  j=0;
  i=1;
  while(i<N && x[i]<z){
	i++;
	j++;
  }

  /* EVALUAMOS EL POLINOMIO DE GRADO 3 CORRESPONDIENTE */
  t=z-x[j];
  //printf("j=%d ",j);

  return(s[j][0]+t*s[j][1]+t*t*s[j][2]+t*t*t*s[j][3]);

  }

/**
 * FUNCION QUE CREA LOS SPLINES CUBICOS. 
 *
 * \param x  COORDENADAS PUNTOS INTERPOLANTES 
 * \param y  VALORES INTERPOLACION 
 * \param N  NUMERO DE PUNTOS A INTERPOLAR 
 * \param s  MATRIZ DONDE SE GUARDAN LOS POLINOMIOS SPLINES DE GRADO 3.
 *           ESTA MATRIZ TIENE DIMENSION Nx4 (AUNQUE LOS POLINOMIOS DE
 *			 INTERES SON N-1).
 *
 * \return RETORNA 0 SI TERMINA BIEN
 ********************************************************/
int ami_crear_splines(
float *x, /* COORDENADAS PUNTOS INTERPOLANTES */
float *y, /* VALORES INTERPOLACION */
int N,    /* NUMERO DE PUNTOS A INTERPOLAR */
float **s) /* MATRIZ DONDE SE GUARDAN LOS POLINOMIOS SPLINES DE GRADO 3.
              ESTA MATRIZ TIENE DIMENSION Nx4 (AUNQUE LOS POLINOMIOS DE
			  INTERES SON N-1 */
{
	double **A, *b = (double*)malloc(sizeof(double)*N);
	float *h;
	int i; //,j;

	/* TOMAMOS MEMORIA E INICIALIZAMOS LA MATRIZ A */
    ami_calloc2d(A, double, N, N);
	ami_malloc1d(h,float,N);

	/* CALCULAMOS INCREMENTOS ENTRE PUNTOS */
	for(i=0;i<(N-1);i++){
	  h[i]=x[i+1]-x[i];
	  if(h[i]<=0.){
		  printf("Error funcion ami_spline, puntos no estan ordenados\n");
		  return -1;
	  }
    }


	/* Hallamos los coeficientes a */
	for (i=0;i<N;i++) s[i][0] = y[i];

	/* Rellenamos la matriz A y el vector de t�minos
       independientes b */
	A[0][0] = 1.;
	b[0] = 0.;

	for (i=1;i<(N-1);i++)
	{
		A[i][i] = 2.0*(h[i-1]+h[i]);
		A[i][i-1] = h[i-1];
		A[i][(i+1)%N] = h[i];
		b[i] = 3.0*(s[(i+1)%N][0]-s[i][0])/h[i] -
			   3.0*(s[i][0]-s[i-1][0])/h[i-1];
	}

	A[N-1][N-1]=1.;
	b[N-1]=0.;

	ami_printf2d("A",A,N,N);
	ami_printf1d("b",b,N);

	/* Resolvemos el sistema de ecuaciones */
	if (ami_gauss(A,b,N) < 0) return -1;

	/* Calculamos los coeficientes b, c y d */
	for (i=0;i<(N-1);i++)
	{
		s[i][2] = b[i];
		s[i][1] = (s[(i+1)%N][0]-s[i][0])/h[i] -
			       h[i]*(2.0*b[i]+b[(i+1)%N])/3.0;
		s[i][3] = (b[(i+1)%N]-b[i])/(3.0*h[i]);
	}

	/* Liberamos memoria */
	free(b); free(h);
	ami_free2d(A);

	return 0;
}



/**
 * FUNCION QUE CALCULA EL VALOR DE UN VECTOR QUE DEJA k ELEMENTOS A LA IZQUIERDA EN PRECISION UNSIGNED CHAR
 */
unsigned char ami_mediana_unsigned_char(int k, int n, unsigned char *x)
{
	int i,ir,j,l,mid;
	unsigned char a,*y;
	ami_malloc1d(y,unsigned char,n);
	ami_vector_copia(x,y,n);

	l=0;
	ir=n-1;
	for (;;) {
		if (ir <= l+1) {
			if (ir == l+1 && y[ir] < y[l]) {
			  ami_swap_uchar(y[l],y[ir])
			}
            a=y[k];
			free(y);
			return a;
		} else {
			mid=(l+ir) >> 1;
			ami_swap_uchar(y[mid],y[l+1])
			if (y[l] > y[ir]) {
				ami_swap_uchar(y[l],y[ir])
			}
			if (y[l+1] > y[ir]) {
				ami_swap_uchar(y[l+1],y[ir])
			}
			if (y[l] > y[l+1]) {
				ami_swap_uchar(y[l],y[l+1])

			}
			i=l+1;
			j=ir;
			a=y[l+1];
			for (;;) {
				do i++; while (y[i] < a);
				do j--; while (y[j] > a);
				if (j < i) break;
				ami_swap_uchar(y[i],y[j])
			}
			y[l+1]=y[j];
			y[j]=a;
			if (j >= k) ir=j-1;
			if (j <= k) l=i;
		}
	}

}



/**
 * FUNCION QUE CALCULA EL VALOR DE UN VECTOR QUE DEJA k ELEMENTOS A LA IZQUIERDA EN PRECISION INT 
 */
int ami_mediana_int(int k, int n, int *x)
{
	int i,ir,j,l,mid;
	int a,*y;
	ami_malloc1d(y,int,n);
	ami_vector_copia(x,y,n);

	l=0;
	ir=n-1;
	for (;;) {
		if (ir <= l+1) {
			if (ir == l+1 && y[ir] < y[l]) {
				ami_swap_int(y[l],y[ir])
			}
            a=y[k];
			free(y);
			return a;
		} else {
			mid=(l+ir) >> 1;
			ami_swap_int(y[mid],y[l+1])
			if (y[l] > y[ir]) {
				ami_swap_int(y[l],y[ir])
			}
			if (y[l+1] > y[ir]) {
				ami_swap_int(y[l+1],y[ir])
			}
			if (y[l] > y[l+1]) {
				ami_swap_int(y[l],y[l+1])

			}
			i=l+1;
			j=ir;
			a=y[l+1];
			for (;;) {
				do i++; while (y[i] < a);
				do j--; while (y[j] > a);
				if (j < i) break;
				ami_swap_int(y[i],y[j])
			}
			y[l+1]=y[j];
			y[j]=a;
			if (j >= k) ir=j-1;
			if (j <= k) l=i;
		}
	}

}



/**
 * FUNCION QUE CALCULA EL VALOR DE UN VECTOR QUE DEJA k ELEMENTOS A LA IZQUIERDA EN PRECISION FLOAT 
 * SI n IMPAR LA MEDIANA CORRESPONDE A k= (TRUNCACION) n/2                                          
 */
float ami_mediana_float(int k, int n, float *x)
{
	int i,ir,j,l,mid;
	float a,*y;
	ami_malloc1d(y,float,n);
	ami_vector_copia(x,y,n);

	l=0;
	ir=n-1;
	for (;;) {
		if (ir <= l+1) {
			if (ir == l+1 && y[ir] < y[l]) {
				ami_swap(y[l],y[ir])
			}
            a=y[k];
			free(y);
			return a;
		} else {
			mid=(l+ir) >> 1;
			ami_swap(y[mid],y[l+1])
			if (y[l] > y[ir]) {
				ami_swap(y[l],y[ir])
			}
			if (y[l+1] > y[ir]) {
				ami_swap(y[l+1],y[ir])
			}
			if (y[l] > y[l+1]) {
				ami_swap(y[l],y[l+1])

			}
			i=l+1;
			j=ir;
			a=y[l+1];
			for (;;) {
				do i++; while (y[i] < a);
				do j--; while (y[j] > a);
				if (j < i) break;
				ami_swap(y[i],y[j])
			}
			y[l+1]=y[j];
			y[j]=a;
			if (j >= k) ir=j-1;
			if (j <= k) l=i;
		}
	}

}


/**
 * APPROXIMATION TO GAUSSIAN FILTER USING ALVAREZ-MAZORRA ALGORITHM
 *
 * \param rim  Original picture and output picture
 * \param sigma_x  Standard deviation of the gaussian in the horizontal axis direction
 * \param sigma_y  Standard deviation of the gaussian in the vertical axis direction 
 * \param precision  Non-negative number to indicate the precisin of the convolution 
 * \param width,height  Image dimensions 
 */
void ami_gauss_conv_alma(
float *rim,  /* Original picture and output picture*/
float sigma_x,    /* standard deviation of the gaussian in the horizontal axis direction*/
float sigma_y,    /* standard deviation of the gaussian in the vertical axis direction */
float precision,  /* non-negative number to indicate the precisin of the convolution */
int width,int height) /* image dimensions */
{
   unsigned long m,M,cont;
   unsigned short i,j,nx1,ny1;
   double *z;
   float l_x=0.0,v_x=0.0,l_y=0.0,v_y=0.0;
   int nx=height;
   int ny=width;
   int Nc_x=(int) (precision*sigma_x>1?precision*sigma_x:1);
   float t_x=sigma_x*sigma_x/(2*Nc_x);
   int Nc_y=(int) (precision*sigma_y>1?precision*sigma_y:1);
   float t_y=sigma_y*sigma_y/(2*Nc_y);
   int Nc_a=(Nc_x>Nc_y)?Nc_x:Nc_y;

   /* DEFINIMOS LOS PARAMETROS DEL ALGORITMO EN X E Y*/
   if(t_x>0){
     l_x=(1.+2.*t_x-sqrt((double) 4*t_x+1))/(2*t_x);
     v_x=l_x/t_x;
   }
   if(t_y>0){
     l_y=(1.+2.*t_y-sqrt((double) 4*t_y+1))/(2*t_y);
     v_y=l_y/t_y;
   }
   nx1=nx-1; ny1=ny-1;
   M=nx*ny;

   /* COGEMOS MEMORIA PARA EL VECTOR DE PASO */
   if(nx>ny)
	z=(double *) malloc(nx*sizeof(double));
   else
 	z=(double *) malloc(ny*sizeof(double));

   /* BUCLE PRINCIPAL DE LAS ITERACIONES */
   for(cont=0;cont<Nc_a;cont++){
     if(t_x>0 && cont<Nc_x){
       for(j=0;j<ny;j++){
         z[0]=rim[j]/(1-l_x);
         m=j;
         for(i=1;i<nx;i++){
           z[i]=rim[m+=ny]+l_x*z[i-1];
         }
         rim[m]=z[nx1]/(1-l_x);
         i=nx-1;
         while(i>0){
	       rim[m-ny]=(z[--i]+l_x*rim[m]);
           m-=ny;
         }
       }
	   m=0;
       while(m<M) rim[m++]*=v_x;
	 }
	 if(t_y>0 && cont<Nc_y){
       m=0;
       for(i=0;i<nx;i++){
         z[0]=rim[m]/(1-l_y);
         for(j=1;j<ny;j++){
           z[j]=rim[++m]+l_y*z[j-1];
         }
         rim[m]=z[ny1]/(1-l_y);
         j=ny1;
         while(j>0){
           --m;
	       rim[m]=z[--j]+l_y*rim[m+1];
         }
         m+=ny;
       }
       m=0;
       while(m<M) rim[m++]*=v_y;
     }
  }
  free(z);
}


/**
 * FUNCION QUE CALCULA LAS ORIENTACIONES Y LA NORMA CUADRADO DEL GRADIENTE DE CADA PIXEL
 *
 * \param image  INPUT IMAGE  
 * \param width  IMAGE WIDTH 
 * \param height  IMAGE HEIGHT 
 * \param sigma  STANDARD DEVIATION OF THE GAUSSIAN 
 * \param alpha  ORIENTATION OUTPUT 
 * \param norma_gradiente  GRADIENT NORM OUTPUT 
 */
int ami_orientation_estimation(float *image, /* INPUT IMAGE  */
                               int width, /* IMAGE WIDTH */
                               int height, /* IMAGE HEIGHT */
			       float sigma, /* STANDARD DEVIATION OF THE GAUSSIAN */
			       float *alpha, /* ORIENTATION OUTPUT */
			       float *norma_gradiente) /* GRADIENT NORM OUTPUT */
{
  int i,j,k;
  double ux,uy,c1,d1,coef1,coef2;
  float **image_x,**image_y,**image_xy;
  double **A,*AUT;
  long m; //,size=width*height;

  coef1=sqrt((double) 2.);
  coef2=0.25*(2.-coef1);
  coef1=0.5*(coef1-1);
  ami_calloc2d(image_x,float,height,width);
  ami_calloc2d(image_y,float,height,width);
  ami_calloc2d(image_xy,float,height,width);
  ami_malloc2d(A,double,2,2);
  ami_malloc1d(AUT,double,2);

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
  if(sigma>0.){
    ami_gauss_conv(sigma,(long) height,(long) width,(float) 1,(float) 1,(float) 5.,(long) 1,image_x);
    ami_gauss_conv(sigma,(long) height,(long) width,(float) 1,(float) 1,(float) 5.,(long) 1,image_y);
    ami_gauss_conv(sigma,(long) height,(long) width,(float) 1,(float) 1,(float) 5.,(long) 1,image_xy);
  }
  for(i=0;i<height;i++){
    for(j=0;j<width;j++){
      m=i*width+j;
      A[0][0]=image_x[0][m]; A[1][1]=image_y[0][m]; A[0][1]=A[1][0]=image_xy[0][m];
      ami_jacobi_autovalores_autovectores(A,AUT,A,2,0.00001);
      if(AUT[0]>AUT[1]){
        norma_gradiente[m]=AUT[0];
	k=0;
      }
      else{
        norma_gradiente[m]=AUT[1];
        k=1;
      }
      if(ami_abs(A[1][k])>0) alpha[m]=atan(A[0][k]/A[1][k]);
      else alpha[m]=M_PI/2;
    }
  }

  ami_free2d(image_x);  ami_free2d(image_y);  ami_free2d(image_xy); ami_free2d(A); free(AUT);
  return(0);

}


/**
 * ECUACION DE LA RECTA QUE PASA POR LOS PUNTOS v0 v1 EVALUADA EN EL PUNTO v            
 */
float ami_recta2d(ami_punto2d v0,ami_punto2d v1,ami_punto2d v)
{
  float result;
  result= (v1.x-v0.x)*(v.y-v0.y)-(v1.y-v0.y)*(v.x-v0.x);
  return(result);
}

/**
 * FUNCION RECURSIVA PARA IR CALCULANDO LOS PUNTOS INTERIORES DE UN TRIANGULO POR
 * ALGORITMO DE SEMILLA.                                                                
 */
void ami_introducir_punto2d_triangulo(int i,int j,ami_punto2d v0,ami_punto2d v1,ami_punto2d v2,
     int **A,int xmin,int ymin,int xmax,int ymax,int **mx,int **my,int *Np)
{
  ami_punto2d v;
   A[i-xmin][j-ymin]=1;
  *Np=*Np+1;
  *mx=(int*)realloc(*mx,sizeof(int)*(*Np));
  *my=(int*)realloc(*my,sizeof(int)*(*Np));
  (*mx)[(*Np)-1]=i; (*my)[(*Np)-1]=j;

  if(i>xmin){

    if(A[i-xmin-1][j-ymin]==0){

      v.x=i-1; v.y=j;
      if(ami_recta2d(v0,v1,v)<=0 && ami_recta2d(v1,v2,v)<=0 && ami_recta2d(v2,v0,v)<=0){

        ami_introducir_punto2d_triangulo(i-1,j,v0,v1,v2,A,xmin,ymin,xmax,ymax,mx,my,Np);
      }
    }
  }

  if(j>ymin){
    if(A[i-xmin][j-ymin-1]==0){
      v.x=i; v.y=j-1;
      if(ami_recta2d(v0,v1,v)<=0 && ami_recta2d(v1,v2,v)<=0 && ami_recta2d(v2,v0,v)<=0){
        ami_introducir_punto2d_triangulo(i,j-1,v0,v1,v2,A,xmin,ymin,xmax,ymax,mx,my,Np);
      }
    }
  }

  if(i<(xmax-1)){
    if(A[i-xmin+1][j-ymin]==0){
      v.x=i+1; v.y=j;
      if(ami_recta2d(v0,v1,v)<=0 && ami_recta2d(v1,v2,v)<=0 && ami_recta2d(v2,v0,v)<=0){
        ami_introducir_punto2d_triangulo(i+1,j,v0,v1,v2,A,xmin,ymin,xmax,ymax,mx,my,Np);
      }
    }
  }

  if(j<(ymax-1)){
    if(A[i-xmin][j-ymin+1]==0){
      v.x=i; v.y=j+1;
      if(ami_recta2d(v0,v1,v)<=0 && ami_recta2d(v1,v2,v)<=0 && ami_recta2d(v2,v0,v)<=0){
        ami_introducir_punto2d_triangulo(i,j+1,v0,v1,v2,A,xmin,ymin,xmax,ymax,mx,my,Np);
      }
    }
  }

}


/**
 * FUNCION QUE CALCULA LOS PUNTOS INTERIORES DE UN TRIANGULO EN 2D EN COORDENADAS
 * FLOTANTES. LOS PUNTOS INTERIORES SE DEVUELVEN EN COORDENADAS ENTERAS EN LOS PUNTEROS
 * mx Y my. EL NUMERO DE PUNTOS INTERIORES SE DEVUELVE EN EL PUNTERO Np                  
 */
void ami_rellenar_triangulo2d(double x0,double y0,double x1,double y1,double x2,
                     double y2, int **mx,int **my,int *Np)
{
  int i,j,**A,xmin,ymin,xmax,ymax;
  ami_punto2d v0,v1,v2;
  v0.x=x0; v0.y=y0;
  v1.x=x1; v1.y=y1;
  v2.x=x2; v2.y=y2;
  if(ami_recta2d(v0,v1,v2)>0.){
    v1.x=x0; v1.y=y0;
    v0.x=x1; v0.y=y1;
  }
  xmin=(int) x0; xmax=(int) x0+1; ymin=(int) y0;  ymax=(int)y0+1;
  if(x1<xmin) xmin=(int) x1; if(x2<xmin) xmin=(int) x2;
  if(y1<ymin) ymin=(int) y1; if(y2<ymin) ymin=(int) y2;
  if(x1>xmax) xmax=(int) x1+1; if(x2>xmax) xmax=(int) x2+1;
  if(y1>ymax) ymax=(int) y1+1; if(y2>ymax) ymax=(int) y2+1;
  ami_calloc2d(A,int,(xmax-xmin),(ymax-ymin));

  i=(int)((x0+x1+x2)/3.+0.5); j=(int)((y0+y1+y2)/3.+0.5);
  *mx=NULL; *my=NULL; *Np=0;
  ami_introducir_punto2d_triangulo(i,j,v0,v1,v2,A,xmin,ymin,xmax,ymax,mx,my,Np);
  ami_free2d(A);

}

/**
 * METODO DE JACOBI PARA CALCULAR AUTOVALORES Y AUTOVECTORES DE UNA MATRIZ SIMETRICA.
 * LA MATRIZ A Y B PUEDEN SER LA MISMA 
 *
 * \param A  MATRIZ SIMETRICA 
 * \param x  VECTOR DE AUTOVALORES 
 * \param B  MATRIZ DE AUTOVECTORES 
 * \param N  DIMENSION MATRIZ 
 * \param _TOL  TOLERANCIA PARA LA CONVERGENCIA 
 */
int ami_jacobi_autovalores_autovectores(double **A /* MATRIZ SIMETRICA */
                           ,double *x  /* VECTOR DE AUTOVALORES */
                           ,double **B /* MATRIZ DE AUTOVECTORES */
                           ,int N /* DIMENSION MATRIZ */
                           ,double _TOL /* TOLERANCIA PARA LA CONVERGENCIA */)
{
 int i,j,k,p,q,l,seguir=0;
 double T,C,CO,SI,D,min,**A2;
 int NiterMax=10000;

 ami_malloc2d(A2,double,N,N);
 ami_matriz_copia(A,A2,N,N);

 /* INICIALIZAMOS LA MATRIZ DE AUTOVECTORES */
 for(i=0;i<N;i++){
  for(j=0;j<N;j++)
    B[i][j]=0.;
  B[i][i]=1.;
 }

 for(k=0;k<NiterMax;k++){
 // if(k==0 || k==1 || k==2) ami_printf2d("B",B,N,N);
   if(seguir==1){
     /* ORDENAMOS LOS AUTOVALORES Y AUTOVECTORES */
     for(i=0;i<N-1;i++){
       min=ami_abs(A2[i][i]); j=i;
       for(l=i+1;l<N;l++){
         if(min>ami_abs(A2[l][l])){
	   j=l;
	   min=ami_abs(A2[l][l]);
	 }
       }
       if(i!=j){
         T=A2[j][j];
         A2[j][j]=A2[i][i];
         A2[i][i]=T;
	 for(l=0;l<N;l++){
	   T=B[l][i];
	   B[l][i]=B[l][j];
	   B[l][j]=T;
	 }
       }

     }
     for(i=0;i<N;i++)
       x[i]=A2[i][i];
     ami_free2d(A2);
     return(k);
   }
   seguir=1;
   for(p=0;p<N;p++){
     for(q=p+1;q<N;q++){
       if(fabs(A2[p][q])>_TOL){
         seguir=0;
         C=(A2[q][q]-A2[p][p])/(2.*A2[p][q]);
         if(C<0)
           T=-C-sqrt(1.+C*C);
         else
           T=-C+sqrt(1.+C*C);
         CO=1./sqrt(1.+T*T);
         SI=CO*T;
	 for(j=0;j<N;j++){
           D=B[j][p];
	   B[j][p]=CO*D-SI*B[j][q];
	   B[j][q]=SI*D+CO*B[j][q];
	 }

         for(j=0;j<N;j++){
           if(j!=p && j!=q){
             D=A2[p][j];
             A2[j][p]=A2[p][j]=CO*D-SI*A2[q][j];
             A2[j][q]=A2[q][j]=SI*D+CO*A2[q][j];
           }
         }
         A2[p][p]=A2[p][p]-T*A2[p][q];
         A2[q][q]=A2[q][q]+T*A2[p][q];
         A2[p][q]=A2[q][p]=0.;
       }
     }
   }
 }
 ami_free2d(A2);
 return(-1);
}


/**
   FUNCION QUE CALCULA LA INTERSECCION DE UNA RECTA Y UN TRIANGULO. X0,X1,X2 REPRESENTAN LOS
   VERTICES DEL TRIANGULO 3D. F EL FOCO (PUNTO POR DONDE PASA EL VECTOR DIRECTOR DE LA RECTA)
   Y D EL VECTOR DIRECTOR DE LA RECTA.
   LA FUNCION DEVUELVE 3 VALORES EN X. SI EL VECTOR DIRECTOR D ESTA NORMALIZADO,
   EL PRIMER VALOR X[0] REPRESENTA LA DISTANCIA DEL PUNTO DE INTERSECCION CON EL FOCO F. LOS OTROS
   DOS VALORES X[1],X[2]. INDICAN QUE EL PUNTO DE INTERSECCION X SE EXPRESA COMO
   X=(1-X[1]-X[2])*X0+X[1]*X1+X[2]*X2. EL PUNTO INTERSECCION CAE DENTRO DEL TRIANGULO SI
   SE CUMPLE QUE (1-X[1]-X[2]),X[1],X[2] son todos positivos. 
 */
int ami_recta_triangulo(p3D X0,p3D X1,p3D X2,p3D F,p3D D,p3D X)
{
  double A[3][3],b[3];
  A[0][0]=D[0]; A[1][0]=D[1]; A[2][0]=D[2];
  A[0][1]=X0[0]-X1[0]; A[1][1]=X0[1]-X1[1]; A[2][1]=X0[2]-X1[2];
  A[0][2]=X0[0]-X2[0]; A[1][2]=X0[1]-X2[1]; A[2][2]=X0[2]-X2[2];
  b[0]=X0[0]-F[0]; b[1]=X0[1]-F[1]; b[2]=X0[2]-F[2];
  if(ami_gauss3x3(A,b)==-1){
    X[0]=X[1]=X[2]=-1;
    return(-1);
  }
  X[0]=b[0]; X[1]=b[1]; X[2]=b[2];
  X[0]=ami_abs(X[0]);
  return(0);
}

/**
 * FUNCION QUE CALCULA LA CORRELACION A VENTANAS 
 * OJO ESTA FUNCION NO FUNCIONA HAY QUE CAMBIAR EL XMW_average 
 *
 * \param I1,I2  IMAGENES DE ENTRADA 
 * \param C  CORRELACION MAXIMA 
 * \param X,Y  DESPLAZAMIENTOS EN X E Y 
 * \param radio_w  RADIO DE LA VENTANA DE COMPARACION 
 * \param radio_w_b  RADIO VENTANA BUSQUEDA EN LA SEGUNAD IMAGEN 
 * \param width,height  TAMAÑO DE LA IMAGEN
 * \param umbral_correlacion  VALOR MINIMO CORRELACION PARA MOVER EL PUNTO
 */
int ami_correlacion(float *I1,float *I2,/* IMAGENES DE ENTRADA */
                    float *C, /* CORRELACION MAXIMA */
                    float *X,
                    float *Y, /*  DESPLAZAMIENTOS EN X E Y */
                    int radio_w, /* RADIO DE LA VENTANA DE COMPARACION */
                    int radio_w_b, /* RADIO VENTANA BUSQUEDA EN LA SEGUNAD IMAGEN */
                    int width,
                    int height, /* TAMA� DE LA IMAGEN */
                    float umbral_correlacion) /* VALOR MINIMO CORRELACION PARA MOVER EL
                                                 PUNTO */
{
  int i,j,m,n,ki,kj;
  float *S_I1,*S_I2,*M_I1,*M_I2,*M_I1_I2;
  long p,q,size=width*height;
  double paso;

  ami_malloc1d(S_I1,float,size);
  ami_malloc1d(S_I2,float,size);
  ami_malloc1d(M_I1,float,size);
  ami_malloc1d(M_I2,float,size);
  ami_malloc1d(M_I1_I2,float,size);

  for(p=0;p<size;p++){
    C[p]=umbral_correlacion;
    X[p]=Y[p]=0;
    M_I1[p]=I1[p];
    M_I2[p]=I2[p];
    S_I1[p]=I1[p]*I1[p];
    S_I2[p]=I2[p]*I2[p];
  }
  /*XMWaverage_rim(M_I1,radio_w,1,width,height);
  XMWaverage_rim(M_I2,radio_w,1,width,height);
  XMWaverage_rim(S_I1,radio_w,1,width,height);
  XMWaverage_rim(S_I2,radio_w,1,width,height);*/
  for(p=0;p<size;p++){
    paso=S_I1[p]-M_I1[p]*M_I1[p];
    S_I1[p]=paso>0?sqrt(paso):0.;
    paso=S_I2[p]-M_I2[p]*M_I2[p];
    S_I2[p]=paso>0?sqrt(paso):0.;
  }

  for(m=-radio_w_b;m<=radio_w_b;m++){
    for(n=-radio_w_b;n<=radio_w_b;n++){
      for(i=0;i<height;i++){
        for(j=0;j<width;j++){
           ki=(i+m)>0?i+m:(-(i+m));
           ki=ki<height?ki:(2*(height-1)-ki);
           kj=(j+n)>0?j+n:(-(j+n));
           kj=kj<width?kj:(2*(width-1)-kj);
           M_I1_I2[i*width+j]=I1[i*width+j]*I2[ki*width+kj];
    /*       if(ki==0 || ki==(height-1) || kj==0 || kj==(width-1))
             M_I1_I2[i*width+j]=0; */
        }
      }
      /*XMWaverage_rim(M_I1_I2,radio_w,1, width, height);*/
      for(i=radio_w;i<height-radio_w;i++){
        for(j=radio_w;j<width-radio_w;j++){
          if((i+m)>=0 && (i+m)<height && (j+n)>=0 && (j+n)<width){
            p=i*width+j;
            q=(i+m)*width+j+n;
            paso=S_I1[p]*S_I2[q];
            if(paso>0.){
              paso=(M_I1_I2[p]-M_I1[p]*M_I2[q])/paso;
              if(paso>C[p]){
                C[p]=paso;
                X[p]=n;
                Y[p]=m;
              }
            }
          }
        }
      }
    }
  }

  free(S_I1); free(S_I2); free(M_I1); free(M_I2); free(M_I1_I2);
  return(0);

}

/**
 * TEST PARA COMPROBAR SI UN PUNTO ES INTERIOR A UN TRIANGULO.
 *
 * \param x,y  COORDENADAS TRIANGULO 
 * \param cx,cy  COORDENADAS PUNTO
 *
 * \return DEVUELVE 0 SI EL PUNTO ES INTERIOR Y -1 SI EL PUNTO ES EXTERIOR.
 */
int ami_interior_triangulo(double *x,double *y,/* COORDENADAS TRIANGULO */
                           double cx,double cy) /* COORDENADAS PUNTO)  */
{
  double a,b;
  int i;
  for(i=0;i<3;i++){
    a=(x[(i+1)%3]-x[i])*(cy-y[i])-(y[(i+1)%3]-y[i])*(cx-x[i]);
    b=(x[(i+1)%3]-x[i])*(y[(i+2)%3]-y[i])-(y[(i+1)%3]-y[i])*(x[(i+2)%3]-x[i]);
    if(a*b<0.)
      return(-1);
  }
  return(0);
}

/**
 * CALCULA UNA AFININIDAD A PARTIR DE UN CONJUNTO DE CORRESPONDENCIAS DE 3 PUNTOS 
 *
 * \param x,y  COORDINATES IN THE FIRST IMAGE 
 * \param xn,yn  COORDINATES IN THE SECOND IMAGE 
 * \param H  OUTPUT AFFINITY
 * \param N  NUMBER OF CORRESPONDING POINTS (N=3) 
*/
int ami_calculo_afinidad(double *x,double *y /* COORDINATES IN THE FIRST IMAGE */,
                           double *xn,double *yn /* COORDINATES IN THE SECOND IMAGE */ ,
			   double H[3][3] /* OUTPUT AFFINITY*/,
			   int N /* NUMBER OF CORRESPONDING POINTS (N=3)*/)
{
  int i,j;
  double **A,*b,**B,m[3],*c;

  if(N<3){
    printf("Error in ami_calculo_afinidad(): The number of corresponding points have to be bigger than 2\n");
    return(-1);
  }

  ami_calloc2d(A,double,6,6);
  ami_malloc1d(b,double,6);
  ami_calloc2d(B,double,2*N,6);
  ami_malloc1d(c,double,2*N);


  /* WE FILL THE MATRIX RELATIONS BETTWEEN POINTS TO COMPUTE THE AFFININTY*/
  for(i=0;i<N;i++){
    B[2*i][0]=x[i];
    B[2*i][1]=y[i];
    B[2*i][2]=1;
    c[2*i]=xn[i];
    B[2*i+1][3]=x[i];
    B[2*i+1][4]=y[i];
    B[2*i+1][5]=1;
    c[2*i+1]=yn[i];
  }


  /* WE BUILT THE MATRIX SYSTEM */
  ami_matriz_traspuesta_vector(B,c,b,6,2*N);
  printf("ok2_bis\n");
  ami_matriz_traspuesta_matriz(B,B,A,6,2*N,6);

  /* WE COMPUTE THE HOMOGRAPHY USING THE GAUSS METHOD TO SOLVE THE LINEAR SYSTEM*/


  if(ami_gauss(A,b,6)==-1)
    return(-1);


  for(i=0;i<2;i++)
    for(j=0;j<3;j++)
      H[i][j]=b[i*3+j];
  H[2][0]=H[2][1]=0.;
  H[2][2]=1.;

  /* WE TEST THE HOMOGRAPHY */
/*  printf("Test of the homography quality\n");
  for(i=0;i<N;i++){
    printf("(x,y)=(%f,%f), ",x[i],y[i]);
    printf("(xn,yn)=(%f,%f), ",xn[i],yn[i]);
    m[0]=x[i]; m[1]=y[i]; m[2]=1.;
    ami_matriz_vector(H,m,b,3,3);
    printf("(H(x,y)-(xn,yn)=(%1.1e,%1.1e)\n",b[0]/b[2]-xn[i],b[1]/b[2]-yn[i]);
  }
*/
  ami_free2d(A); ami_free2d(B);
  free(b); free(c);
  return(0);

}


/**
 * METODO DE JACOBI PARA CALCULAR AUTOVALORES DE UNA MATRIZ SIMETRICA.
 * LOS AUTOVALORES QUEDAN EN LA DIAGONAL DE LA MATRIZ.
 *
 * \param A  MATRIZ SIMETRICA 
 * \param N  DIMENSION MATRIZ 
 * \param _TOL  TOLERANCIA PARA LA CONVERGENCIA 
 */
int ami_jacobi_autovalores(double **A /* MATRIZ SIMETRICA */
                           ,int N /* DIMENSION MATRIZ */
                           ,double _TOL /* TOLERANCIA PARA LA CONVERGENCIA */)
{
 int j,k,p,q,seguir=0;
 double T,C,CO,SI,D;
 int NiterMax=10000;
 for(k=0;k<NiterMax;k++){
   if(seguir==1)
     return(k);
   seguir=1;
   for(p=0;p<N;p++){
     for(q=p+1;q<N;q++){
       if(fabs(A[p][q])>_TOL){
         seguir=0;
         C=(A[q][q]-A[p][p])/(2.*A[p][q]);
         if(C<0)
           T=-C-sqrt(1.+C*C);
         else
           T=-C+sqrt(1.+C*C);
         CO=1./sqrt(1.+T*T);
         SI=CO*T;
         for(j=0;j<N;j++){
           if(j!=p && j!=q){
             D=A[p][j];
             A[j][p]=A[p][j]=CO*D-SI*A[q][j];
             A[j][q]=A[q][j]=SI*D+CO*A[q][j];
           }
         }
         A[p][p]=A[p][p]-T*A[p][q];
         A[q][q]=A[q][q]+T*A[p][q];
         A[p][q]=A[q][p]=0.;
       }
     }
   }
 }
 return(-1);
}

/**
 * APLICACION DE UNA HOMOGRAFIA SOBRE UNA IMAGEN ADAPTANDO EL TAMA� DE LA NUEVA IMAGEN
 *
 * \param H  Matriz de homografia
 * \param image_input  Imagen de entrada 
 * \param image_output  Puntero imagen de salida 
 * \param width_input,height_input  Dimensiones imagen original 
 * \param width_output,height_output  PUNTEROS TAMANO NUEVA IMAGEN
 */
int ami_aplicacion_homografia_adaptativa(
			  double H[3][3], /* Matriz de homografia */
			  float *image_input, /* imagen de entrada */
			  float **image_output, /* puntero imagen de salida */
			  int width_input,      /* Dimensiones imagen original */
			  int height_input,
			  int *width_output,   /* PUNTEROS TAMANO NUEVA IMAGEN */
			  int *height_output
			  )
{
  int i,j;
  double H_1[3][3]; /* INVERSE OF THE HOMOGRAPHY */
  double x[4],y[4]; /* COORDENATE POINTS OF THE IMAGE RECTANGLE TRANSFORMATION */
  double v[3],paso[3],xmin,xmax,ymin,ymax,px,py,g;
  long m,size=width_input*height_input;
  int m1,m2,m3,m4;

  /* WE COMPUTE H_1*/
  if(ami_inversa3x3((double**)H,(double**)H_1)==-1)
    return(-1);
  printf("The inverse of the homography is given by:\n");
  ami_printf2d("H_1",H_1,3,3);

  /* WE COMPUTE THE TRANSFORMATION OF THE COORDINATES OF THE WINDOWS CORNERS */
  x[0]=0; x[1]=width_input; x[2]=0; x[3]=width_input;
  y[0]=0; y[1]=0; y[2]=height_input; y[3]=height_input;

  /* WE COMPUTE THE TRANSFORMATION ON THE COORDENATES OF THE IMAGE RECTANGLE */
  for(i=0;i<4;i++){
    v[0]=x[i]; v[1]=y[i]; v[2]=1.;
    ami_matriz_vector(H,v,paso,3,3);
    x[i]=paso[0]/paso[2]; y[i]=paso[1]/paso[2];
  }
  printf("The coordinates of proyection of the boundary of the image are given by:\n");
  ami_printf1d("x",x,4);
  ami_printf1d("y",y,4);

  /* WE COMPUTE THE MAXIMUN AND MINIMUM OF THE Y COORDINATES */
  ymin=y[0]; ymax=y[0];
  for(j=1;j<4;j++){
    if(y[j]<ymin) ymin=y[j];
    else if(y[j]>ymax) ymax=y[j];
  }
  /* WE COMPUTE THE MAXIMUN AND MINIMUM OF THE X COORDINATES */
  /* FOR THE FIRST IMAGE */
  xmin=x[0]; xmax=x[0];
  for(j=1;j<4;j++){
    if(x[j]<xmin) xmin=x[j];
    else if(x[j]>xmax) xmax=x[j];
  }
  *width_output=(int)(xmax-xmin);
  *height_output=(int)(ymax-ymin);
  *image_output=(float *)malloc(sizeof(float)*(*width_output)*(*height_output));

  /* WE FILL IN WHITE THE BACKGROUND OF THE OUTPUT IMAGE */
  size=(*height_output)*(*width_output);
  for(m=0;m<size;m++)
    (*image_output)[m]=255;
  /* WE FILL THE  OUTPUT IMAGE */
  for(i=0;i<(*height_output);i++){
    for(j=0;j<(*width_output);j++){
      v[0]=xmin+j*(xmax-xmin)/(*width_output);
      v[1]=ymin+i*(ymax-ymin)/(*height_output);
      v[2]=1.;
      ami_matriz_vector(H_1,v,paso,3,3);
      paso[0]/=paso[2];
      paso[1]/=paso[2];
      if(paso[1]>-0.1 && paso[1]<(height_input-0.9) && paso[0]>-0.1 && paso[0]<(width_input-0.9)){
        if(paso[0]<0) paso[0]=0;
        if(paso[1]<0) paso[1]=0;
	m1=(int)(((int) paso[1])*width_input+paso[0]);
	m2=(paso[1]<(height_input-1))?m1+width_input:m1;
	m3=(paso[0]<(width_input-1))?m2+1:m2;
        m4=(paso[0]<(width_input-1))?m1+1:m1;
        py=paso[1]-((int) paso[1]);
        px=paso[0]-((int) paso[0]);
	g=(1-px)*((1-py)*image_input[m1]+py*image_input[m2])+
	   px*((1-py)*image_input[m4]+py*image_input[m3]);
	(*image_output)[i*(*width_output)+j]=g;
      }
    }
  }
  return(0);
}

/**
 * APLICACION DE UNA HOMOGRAFIA SOBRE UNA IMAGEN (IMAGEN RESULTADO MANTIENE EL TAMANO)
 *
 * \param H  Matriz de homografia
 * \param image_input  Imagen de entrada 
 * \param image_output  Imagen de salida 
 * \param width,height 
 */
int ami_aplicacion_homografia(
			  double H[3][3], /* Matriz de homografia */
			  float *image_input, /* imagen de entrada */
			  float *image_output, /* imagen de salida */
			  int width,
			  int height
			  )
{
  int i,j;
  double H_1[3][3]; /* INVERSE OF THE HOMOGRAPHY */
  double x[4],y[4]; /* COORDENATE POINTS OF THE IMAGE RECTANGLE TRANSFORMATION */
  double v[3],paso[3],xmin,xmax,ymin,ymax,px,py,g;
  long m,size=width*height;
  int m1,m2,m3,m4;
  /* WE FILL IN WIDTH THE OUTPUT IMAGE */
  for(m=0;m<size;m++)
    image_output[m]=255;

  /* WE COMPUTE H_1*/
  if(ami_inversa3x3((double**)H,(double**)H_1)==-1)
    return(-1);
  printf("The inverse of the homography is given by:\n");
  ami_printf2d("H_1",H_1,3,3);

  /* WE COMPUTE THE TRANSFORMATION OF THE COORDINATES OF THE WINDOWS CORNERS */
  x[0]=0; x[1]=width; x[2]=0; x[3]=width;
  y[0]=0; y[1]=0; y[2]=height; y[3]=height;

  /* WE COMPUTE THE TRANSFORMATION ON THE COORDENATES OF THE IMAGE RECTANGLE */
  for(i=0;i<4;i++){
    v[0]=x[i]; v[1]=y[i]; v[2]=1.;
    ami_matriz_vector(H,v,paso,3,3);
    x[i]=paso[0]/paso[2]; y[i]=paso[1]/paso[2];
  }
  printf("The coordinates of proyection of the boundary of the image are given by:\n");
  ami_printf1d("x",x,4);
  ami_printf1d("y",y,4);

  /* WE COMPUTE THE MAXIMUN AND MINIMUM OF THE Y COORDINATES */
  ymin=y[0]; ymax=y[0];
  for(j=1;j<4;j++){
    if(y[j]<ymin) ymin=y[j];
    else if(y[j]>ymax) ymax=y[j];
  }
  /* WE COMPUTE THE MAXIMUN AND MINIMUM OF THE X COORDINATES */
  /* FOR THE FIRST IMAGE */
  xmin=x[0]; xmax=x[0];
  for(j=1;j<4;j++){
    if(x[j]<xmin) xmin=x[j];
    else if(x[j]>xmax) xmax=x[j];
  }

  /* WE FILL THE  OUTPUT IMAGE */
  for(i=0;i<height;i++){
    for(j=0;j<width;j++){
      v[0]=xmin+j*(xmax-xmin)/width;
      v[1]=ymin+i*(ymax-ymin)/height;
      v[2]=1.;
      ami_matriz_vector(H_1,v,paso,3,3);
      paso[0]/=paso[2];
      paso[1]/=paso[2];
      if(paso[1]>-0.1 && paso[1]<(height-0.9) && paso[0]>-0.1 && paso[0]<(width-0.9)){
        if(paso[0]<0) paso[0]=0;
        if(paso[1]<0) paso[1]=0;
	m1=(int)(((int) paso[1])*width+paso[0]);
	m2=(paso[1]<(height-1))?m1+width:m1;
	m3=(paso[0]<(width-1))?m2+1:m2;
        m4=(paso[0]<(width-1))?m1+1:m1;
        py=paso[1]-((int) paso[1]);
        px=paso[0]-((int) paso[0]);
	g=(1-px)*((1-py)*image_input[m1]+py*image_input[m2])+
	   px*((1-py)*image_input[m4]+py*image_input[m3]);
	image_output[i*width+j]=g;
      }
    }
  }
  return(0);
}


/**
 * FUNCION QUE CALCULA LOS AUTOVALORES Y AUTOVECTORES DE UNA MATRIZ 2X2 SIMETRICA 
 *
 * \param M  MATRIZ DE ENTRADA 
 * \param A  MATRIZ DE AUTOVECTORES POR FILAS ORDENADOS DE MENOR A MAYOR 
 * \param autovalorminimo  AUTOVALOR MINIMO 
 * \param autovalormaximo  AUTOVALOR MAXIMO 
 */
void ami_autovectores2x2_simetrica(double M[2][2] /* MATRIZ DE ENTRADA */,
				   double A[2][2] /* MATRIZ DE AUTOVECTORES POR FILAS ORDENADOS
						     DE MENOR A MAYOR */,
				   double *autovalorminimo /* AUTOVALOR MINIMO */,
				   double *autovalormaximo /* AUTOVALOR MAXIMO */)
{
  double a=M[0][0];
  double b=M[0][1];
  double c=M[1][1];
  double dis=(a-c)*(a-c)+4.*b*b;
  double norma;
  if(dis<=0.){
    A[0][0]=A[0][1]=A[1][0]=A[1][1]=*autovalorminimo=*autovalormaximo=0;
  }
  dis=sqrt(dis);
  norma=a+c;
  if(norma>0.){
    *autovalorminimo=0.5*(norma-dis);
    *autovalormaximo=0.5*(norma+dis);
    norma=sqrt((c-a+dis)*(c-a+dis)+4.*b*b);
    A[1][0]=2.*b/norma;
    A[1][1]=(c-a+dis)/norma;
    A[0][0]=-A[1][1];
    A[0][1]=A[1][0];
  }
  else{
    *autovalorminimo=0.5*(norma+dis);
    *autovalormaximo=0.5*(norma-dis);
    norma=sqrt((c-a+dis)*(c-a+dis)+4.*b*b);
    A[0][0]=2.*b/norma;
    A[0][1]=(c-a+dis)/norma;
    A[1][0]=-A[0][1];
    A[1][1]=A[0][0];
  }
}

/**
 * FUNCION QUE CALCULA EL GRADIENTE DE UNA IMAGEN 
 *
 * \param image  ORIGINAL IMAGE 
 * \param width,height  IMAGE SIZE 
 * \param image_x,image_y  OUTPUT GRADIENT
 */
void ami_grad(float *image,/* ORIGINAL IMAGE */
	      int width,int height,/* IMAGE SIZE */
	      float *image_x,float *image_y /* OUTPUT GRADIENT */)
{
  int i,j;
  long m,size=width*height;
  double coef1,coef2,c1,d1;
  coef1=sqrt((double) 2.);
  coef2=0.25*(2.-coef1);
  coef1=0.5*(coef1-1);

  /* BUCLE PRINCIPAL */
  for(i=1;i<height-1;i++){
    for(j=1;j<width-1;j++){
      m=i*width+j;
      c1=image[m+width+1]-image[m-width-1];
      d1=image[m-width+1]-image[m+width-1];
      image_y[m]=coef1*(image[m+width]-image[m-width])+coef2*(c1-d1);
      image_x[m]=-(coef1*(image[m+1]-image[m-1])+coef2*(c1+d1));
    }
  }

  /* EN LOS BORDES ASIGNAMOS 0 A LAS DERIVADAS */
  for(m=0;m<width;m++){
    image_y[m]=image_y[size-1-m]=0.;
    image_x[m]=image_x[size-1-m]=0.;
  }
  for(m=0;m<(size-1);m+=width){
    image_y[m]=image_y[m+width-1]=0.;
    image_x[m]=image_x[m+width-1]=0.;
  }
}


/**
 * FUNCION QUE CALCULA LA CONVOLUCION CON UNA GAUSSIANA             
 *
 * \param sigma  Standard deviation of Gaussian 
 * \param nx  Image dimension in x direction
 * \param ny  Image dimension in y direction 
 * \param hx  Pixel size in x direction 
 * \param hy  Pixel size in y direction 
 * \param precision  Cutoff at precision * sigma 
 * \param bc  Type of boundary condition (0=Dirichlet, 1=reflecing, 2=periodic)
 * \param f  Input: original image ;  output: smoothed 
 */
void ami_gauss_conv
     (float    sigma,     /* standard deviation of Gaussian */
      long     nx,        /* image dimension in x direction */
      long     ny,        /* image dimension in y direction */
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
nx-=2;
ny-=2;
length = (long)(precision * sigma / hx) + 1;
if ((bc != 0) && (length > nx))
   {
   printf("gauss_conv: sigma too large \n");
   exit(0);
   }

/* allocate storage for convolution vector */
ami_malloc1d(conv,float,length+1);

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
ami_malloc1d(help,float,nx+length+length+1);

for (j=1; j<=ny; j++)
    {
    /* copy in row vector */
    for (i=1; i<=nx; i++)
        help[i+length-1] = f[i][j];

    /* assign boundary conditions */
    if (bc == 0) /* Dirichlet boundary conditions */
       for (p=1; p<=length; p++)
           {
           help[length-p]      = 0.0;
           help[nx+length-1+p] = 0.0;
           }
    else if (bc == 1) /* reflecting b.c. */
       for (p=1; p<=length; p++)
           {
           help[length-p]      = help[length+p-1];
           help[nx+length-1+p] = help[nx+length-p];
           }
    else if (bc == 2) /* periodic b.c. */
       for (p=1; p<=length; p++)
           {
           help[length-p]      = help[nx+length-p];
           help[nx+length-1+p] = help[length+p-1];
           }

    /* convolution step */
    for (i=length; i<=nx+length-1; i++)
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
if ((bc != 0) && (length > ny))
   {
   printf("gauss_conv: sigma too large \n");
   exit(0);
   }

/* allocate storage for convolution vector */
ami_malloc1d(conv,float,length + 1);

/* calculate entries of convolution vector */
for (j=0; j<=length; j++)
    conv[j] = 1 / (sigma * sqrt(2.0 * M_PI))
              * exp (- (j * j * hy * hy) / (2.0 * sigma * sigma));

/* normalization */
sum = conv[0];
for (j=1; j<=length; j++)
    sum = sum + 2.0 * conv[j];
for (j=0; j<=length; j++)
    conv[j] = conv[j] / sum;

/* allocate storage for a row */
ami_malloc1d(help,float,ny+length+length+1);

for (i=1; i<=nx; i++)
    {
    /* copy in column vector */
    for (j=1; j<=ny; j++)
        help[j+length-1] = f[i][j];

    /* assign boundary conditions */
    if (bc == 0) /* Dirichlet boundary conditions */
       for (p=1; p<=length; p++)
           {
           help[length-p]      = 0.0;
           help[ny+length-1+p] = 0.0;
           }
    else if (bc == 1) /* reflecting b.c. */
       for (p=1; p<=length; p++)
           {
           help[length-p]      = help[length+p-1];
           help[ny+length-1+p] = help[ny+length-p];
           }
    else if (bc == 2) /* periodic b.c. */
       for (p=1; p<=length; p++)
           {
           help[length-p]      = help[ny+length-p];
           help[ny+length-1+p] = help[length+p-1];
           }

    /* convolution step */
    for (j=length; j<=ny+length-1; j++)
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
free(help);

/* disallocate convolution vector */
free(conv);

return;

} /* gauss_conv */


/**
 * CALCULA UNA HOMOGRAFIA A PARTIR DE UN CONJUNTO DE CORRESPONDENCIAS DE PUNTOS
 *
 * \param x,y  COORDINATES IN THE FIRST IMAGE 
 * \param xn,yn  COORDINATES IN THE SECON IMAGE 
 * \param H  OUTPUT HOMOGRAFY
 * \param N  NUMBER OF CORRESPONDING POINTS 
 */
int ami_calculo_homografia(double *x,double *y /* COORDINATES IN THE FIRST IMAGE */,
                           double *xn,double *yn /* COORDINATES IN THE SECON IMAGE */ ,
			   double H[3][3] /* OUTPUT HOMOGRAFY*/,
			   int N /* NUMBER OF CORRESPONDING POINTS */)
{
  int i,j;
  double **A,**At,**AxA,*v,paso,m[3],b[3],media1[2],media2[2],s1,s2;
  double N1[3][3],N2[3][3],PASO[3][3];
  double sqr2=sqrt((double) 2.);

  /* WE COMPUTE THE MEDIA AND STANDARD DEVIATION OF THE DATA */
  media1[0]=media1[1]=media2[0]=media2[1]=s1=s2=0;
  for(i=0;i<N;i++){
    media1[0]+=x[i];
    media1[1]+=y[i];
    media2[0]+=xn[i];
    media2[1]+=yn[i];
  }
  for(i=0;i<2;i++){
    media1[i]/=N;
    media2[i]/=N;
  }
  for(i=0;i<N;i++){
   s1+=(x[i]-media1[0])*(x[i]-media1[0])+(y[i]-media1[1])*(y[i]-media1[1]);
   s2+=(xn[i]-media2[0])*(xn[i]-media2[0])+(yn[i]-media2[1])*(yn[i]-media2[1]);
  }
  s1=sqrt(s1/N);
  s2=sqrt(s2/N);
  s1/=sqr2;
  s2/=sqr2;

  /* WE NORMALIZE THE DATA AND DEFINE THE NORMALIZATION MATRIX N1 AND N2 */
  for(i=0;i<N;i++){
    x[i]=(x[i]-media1[0])/s1;
    y[i]=(y[i]-media1[1])/s1;
    xn[i]=(xn[i]-media2[0])/s2;
    yn[i]=(yn[i]-media2[1])/s2;
  }
  N1[0][0]=1.; N1[0][1]=0; N1[0][2]=-media1[0];
  N1[1][0]=0.; N1[1][1]=1.; N1[1][2]=-media1[1];
  N1[2][0]=0.; N1[2][1]=0.; N1[2][2]=s1;
  N2[0][0]=1.; N2[0][1]=0.; N2[0][2]=-media2[0];
  N2[1][0]=0.; N2[1][1]=1.; N2[1][2]=-media2[1];
  N2[2][0]=0.; N2[2][1]=0.; N2[2][2]=s2;


  ami_calloc2d(A,double,2*N,9);
  ami_malloc2d(At,double,9,2*N);
  ami_malloc2d(AxA,double,9,9);
  ami_malloc1d(v,double,9);

  /* WE FILL THE MATRIX RELATIONS BETTWEEN POINTS TO COMPUTE THE HOMOGRAPHY */
  for(i=0;i<N;i++){
    A[2*i][0]=x[i];
    A[2*i][1]=y[i];
    A[2*i][2]=1.;
    A[2*i][6]=-x[i]*xn[i];
    A[2*i][7]=-y[i]*xn[i];
    A[2*i][8]=-xn[i];
    A[2*i+1][3]=x[i];
    A[2*i+1][4]=y[i];
    A[2*i+1][5]=1.;
    A[2*i+1][6]=-x[i]*yn[i];
    A[2*i+1][7]=-y[i]*yn[i];
    A[2*i+1][8]=-yn[i];
  }

  /* WE NORMALIZE MATRIZ A */
  for(i=0;i<2*N;i++)
    ami_normalizar_vector(A[i],9);


ami_printf2d("A",A,2*N,9);

  /* WE COMPUTE THE HOMOGRAPHY USING A LINEAR METHOD */
  ami_matriz_traspuesta(A,At,2*N,9);
  ami_matriz_matriz(At,A,AxA,9,2*N,9);
ami_printf2d("AxA",AxA,9,9);
  if(ami_autovalor_minimo(AxA,v,&paso,9)==-1){
    ami_free2d(A);
    ami_free2d(At);
    ami_free2d(AxA);
    free(v);
    return(-1);
  }
ami_printf1d("v",v,9);
  for(i=0;i<3;i++)
    for(j=0;j<3;j++)
      H[i][j]=v[i*3+j];

  /* WE TEST THE HOMOGRAPHY */
  printf("Test of the homography quality\n");
  for(i=0;i<N;i++){
    printf("(x,y)=(%f,%f), ",x[i],y[i]);
    printf("(x',y')=(%f,%f), ",xn[i],yn[i]);
    m[0]=x[i]; m[1]=y[i]; m[2]=1.;
    ami_matriz_vector(H,m,b,3,3);
    printf("(H(x,y)-(x',y')=(%1.1e,%1.1e)\n",b[0]/b[2]-xn[i],b[1]/b[2]-yn[i]);
  }

  /* WE RECOVER THE ORIGINAL HOMOGRAPHY */
  ami_inversa3x3((double**)N2,(double**)PASO);
  ami_matriz_matriz(PASO,H,N2,3,3,3);
  ami_matriz_matriz(N2,N1,H,3,3,3);
  printf("\nComputed Homography:\n");
  ami_printf2d("H",H,3,3);

  ami_free2d(A);
  ami_free2d(At);
  ami_free2d(AxA);
  free(v);
  return(0);

}



/**
 * CALCULA LA INTERSECCION DE 2 RECTAS 2D                   
 *
 * \param recta1,recta2  Coeficientes que determinan las dos rectas 
 * \param x,y  SALIDA punto de interseccion de las rectas
 */
int ami_punto_interseccion_2_rectas(double recta1[3],double recta2[3],double *x,double *y)
     /* double recta1[3],recta2[3]; Coeficientes que determinan las dos rectas */
     /* double *x,*y; SALIDA punto de interseccion de las rectas */
{
  double det;
  det=recta1[0]*recta2[1]-recta1[1]*recta2[0];
  if(det==0){
    printf("Rectas paralelas. Imposible Calculo Interseccion\n");
    return(-1);
  }
  *x=(recta1[1]*recta2[2]-recta1[2]*recta2[1])/det;
  *y=(recta1[2]*recta2[0]-recta1[0]*recta2[2])/det;
  return(0);


}
/**
 * CALCULA LA RECTA QUE MEJOR APROXIMA UN CONJUNTO DE PUNTOS 2D
 *
 * \param recta  COEFICIENTES DE LA RECTA 2D (SALIDA)
 * \param Puntos2D  COORDENADAS DE LOS PUNTOS 2D 
 * \param N  NUMERO DE PUNTOS
 */
int ami_calculo_recta2d(double recta[3],double **Puntos2D,int N)     
{
  int i,j,k;
  double suu,suv,svv,um,vm,h,r[4][3],min,paso,norma;
  double cero=0.00000000000001;

  if(N<2){
    printf("Numero de puntos para el Calculo de la recta 2D menor que 2\n");
    return(-1);
  }
  suu=0; suv=0; svv=0; um=0; vm=0;
  for(i=0;i<N;i++){
    um+=Puntos2D[i][0];
    vm+=Puntos2D[i][1];
  }
  um/=N; vm/=N;
  for(i=0;i<N;i++){
    suu+=(Puntos2D[i][0]-um)*(Puntos2D[i][0]-um);
    svv+=(Puntos2D[i][1]-vm)*(Puntos2D[i][1]-vm);
    suv+=(Puntos2D[i][0]-um)*(Puntos2D[i][1]-vm);
  }
  suu/=N; svv/=N; suv/=N;
  /*  printf("um=%f,vm=%f,suu=%f,svv=%f,suv=%f",um,vm,suu,svv,suv); */
  if(fabs(suv)<= cero){
    if(suu<svv && svv>cero){
      recta[0]=1; recta[1]=0; recta[2]=-um;
      return(0);
    }
    if(svv<suu && suu>cero){
      recta[0]=0; recta[1]=1; recta[2]=-vm;
      return(0);
    }
    printf("No se pudo calcular la recta 2D\n");
    return(-1);
  }

  r[2][1]=r[3][1]=r[0][0]=r[1][0]=1.;
  h=0.5*(suu-svv)/suv;
  if(h>0){
    r[0][1]=-h-sqrt(1.+h*h);
    r[0][2]=-(um+r[0][1]*vm);
    r[1][1]=-1./r[0][1];
    r[1][2]=-(um+r[1][1]*vm);
    r[2][0]=h+sqrt(1.+h*h);
    r[2][2]=-(r[2][0]*um+vm);
    r[3][0]=-1./r[2][0];
    r[3][2]=-(r[3][0]*um+vm);
  }
  else{
    r[0][1]=-h+sqrt(1+h*h);
    r[0][2]=-(um+r[0][1]*vm);
    r[1][1]=-1./r[0][1];
    r[1][2]=-(um+r[1][1]*vm);
    r[2][0]=h-sqrt(1+h*h);
    r[2][2]=-(r[2][0]*um+vm);
    r[3][0]=-1./r[2][0];
    r[3][2]=-(r[3][0]*um+vm);
  }

  for(j=0;j<4;j++){
    norma=sqrt(r[j][0]*r[j][0]+r[j][1]*r[j][1]);
    for(i=0;i<3;i++)
      r[j][i]/=norma;
  }

  min=0.; k=0;
  for(i=0;i<N;i++){
   paso=r[0][0]*Puntos2D[i][0]+r[0][1]*Puntos2D[i][1]+r[0][2];
   min+=fabs(paso);
  }
  for(j=1;j<4;j++){
    h=0;
    for(i=0;i<N;i++){
      paso=r[j][0]*Puntos2D[i][0]+r[j][1]*Puntos2D[i][1]+r[j][2];
      h+=fabs(paso);
    }
    if(h<min){
      k=j;
      min=h;
    }
  }

  recta[0]=r[k][0]; recta[1]=r[k][1]; recta[2]=r[k][2];
  return(0);
}



/**
 * CALCULA LA RECTA QUE MEJOR APROXIMA UN CONJUNTO DE PUNTOS 2D  
 * DE FORMA ROBUSTA.                          
 *
 * \param recta  COEFICIENTES DE LA RECTA 2D (SALIDA) 
 * \param Puntos2D  COORDENADAS DE LOS PUNTOS 2D 
 * \param N  NUMERO DE PUNTOS 
 * \param dmax  DISTANCIA MAXIMA ADMITIDA ENTRE UN PUNTO Y LA RECTA 
 *
 * \return DEVUELVE EL NUMERO DE PUNTOS UTILIZADOS PARA EL CALCULO DE LA RECTA ROBUSTA
 */
int ami_calculo_recta2d_robusto(double recta[3],double **Puntos2D,int N,float dmax)     
{
  int i,j,k,Nmax,Nr;
  double **Puntos2Dbis; /* PUNTOS PARA CALCULAR LA RECTA FINAL */
  double r[3];

  if(N<3){
    printf("Numero de puntos para el Calculo de la recta 2D Robusta menor que 3\n");
    return(-1);
  }
  /* RESERVO MEMORIA PARA CALCULAR LA RECTA QUE PASA POR DOS PUNTOS */
  ami_malloc2d(Puntos2Dbis,double,2,2);
  /* RECORRO TODOS LOS POSIBLES PARES DE PUNTOS PARA CALCULAR LA RECTA ASOCIADA */
  Nmax=0;
  for(i=0;i<N;i++){
    for(j=i+1;j<N;j++){
      for(k=0;k<2;k++){
	Puntos2Dbis[0][k]=Puntos2D[i][k];
	Puntos2Dbis[1][k]=Puntos2D[j][k];
      }
      if(ami_calculo_recta2d(r,Puntos2Dbis,2)>-1){
	Nr=0;
	for(k=0;k<N;k++){
	  if(fabs(r[0]*Puntos2D[k][0]+r[1]*Puntos2D[k][1]+r[2])<dmax)
	    Nr++;
	}
	if(Nr>Nmax){
	  Nmax=Nr;
	  for(k=0;k<3;k++)
	    recta[k]=r[k];
	}
      }
    }
  }
  ami_free2d(Puntos2Dbis);
  /* RECALCULO LA RECTA QUE MAS PUNTOS CONTIENE */
  ami_malloc2d(Puntos2Dbis,double,Nmax,2);
  Nr=0;
  for(k=0;k<N;k++){
    if(fabs(recta[0]*Puntos2D[k][0]+recta[1]*Puntos2D[k][1]+recta[2])<dmax){
	Puntos2Dbis[Nr][0]=Puntos2D[k][0];
	Puntos2Dbis[Nr][1]=Puntos2D[k][1];
	Nr++;
    }
  }
  if(ami_calculo_recta2d(recta,Puntos2Dbis,Nmax)>-1){
    ami_free2d(Puntos2Dbis);
    return(Nmax);
  }
  else{
    ami_free2d(Puntos2Dbis);
    return(-1);
  }
}





/**
 * FUNCION QUE CALCULA AUTOVALOR Y AUTOVECTOR MINIMO MATRIZ     
 * VALE PARA MATRICES SIMETRICAS Y SEMIDEFINIDA POSITIVAS       
 *
 * \param B  MATRIZ DE ENTRADA 
 * \param v  AUTOVECTOR CALCULADO DE AUTOVALOR MINIMO 
 * \param l  AUTOVALOR MINIMO 
 * \param N  DIMENSION MATRIZ 
 */
int ami_autovalor_minimo_old(double **B,double *v,double *l,int N)
{
  int i,j,k;
  double **B_1;
  double *aux,norma=0.0,error=0.0,error2=0.0;
  int ami_max_iterR=1000;
  double ERRORMAXIMO=0.00000001;
  ERRORMAXIMO*=ERRORMAXIMO;
  B_1=(double**)malloc(sizeof(double*)*N);
  for(i=0;i<N;i++)
    B_1[i]=(double*)malloc(sizeof(double)*N);
  aux=(double*)malloc(sizeof(double)*N);


  /* CALCULO INVERSA DE B */
  for(i=0;i<N;i++)
    B[i][i]+=0.00001;
  if(ami_inversa(B,B_1,N)==-1){
    if(ami_inversa(B,B_1,N)==-1){
      for(i=0;i<N;i++)
        free(B_1[i]);
      free(B_1);
      free(aux);
      return(-1);
    }
  }


  /* INICIALIZAMOS v */
  for(i=0;i<N;i++)
    aux[i]=v[i]=1.;


  /* REALIZAMOS LAS ITERACIONES */
  k=0;
	while((k++)<ami_max_iterR){
	/* ami_gauss(B,aux,N); */
	aux=ami_MxV(B_1,v,aux,N);
    norma=0;
   for(j=0;j<N;j++)
     norma+=aux[j]*aux[j];
   if(norma<=0){
     for(i=0;i<N;i++)
      free(B_1[i]);
    free(B_1);
    free(aux);

    printf("Problemas Calculo Autovector\n");
    return(-1);
   }
   norma=sqrt(norma);
   error=0; error2=0;
   for(i=0;i<N;i++){
      aux[i]/=norma;
      error+=(aux[i]-v[i])*(aux[i]-v[i]);
      error2+=(aux[i]+v[i])*(aux[i]+v[i]);
      v[i]=aux[i];
   }
   if(error>error2) error=error2;
   printf("funcion ami_autovalor_minimo : error=%e\n",error);
   if(error<ERRORMAXIMO)
     k=ami_max_iterR+5;
  }

  for(i=0;i<N;i++)
   free(B_1[i]);
  free(B_1);
  free(aux);
  if(k>ami_max_iterR+3 || (0.0000001*error)<ERRORMAXIMO){
    *l=1./norma;
    return(0);
  }
  printf("Excedido Numero Maximo de Iteraciones Para Calculo Autovector\n");
  return(-1);

}

/**
 * FUNCION QUE CALCULA AUTOVALOR Y AUTOVECTOR MINIMO MATRIZ      
 * VALE PARA MATRICES SIMETRICAS Y SEMIDEFINIDA POSITIVAS   
 *
 * \param B  MATRIZ DE ENTRADA 
 * \param v  AUTOVECTOR CALCULADO DE AUTOVALOR MINIMO 
 * \param l  AUTOVALOR MINIMO 
 * \param N  DIMENSION MATRIZ 
 */
int ami_autovalor_minimo(double **B,double *v,double *l,int N)
{
  int i; //,j,k;
  double **B_J,*x,*aux;
  double ERRORMAXIMO=0.00000001;
  ERRORMAXIMO*=ERRORMAXIMO;

  ami_malloc1d(x,double,N);
  ami_malloc1d(aux,double,N);
  ami_malloc2d(B_J,double,N,N);
  i=ami_jacobi_autovalores_autovectores(B,x,B_J,N,10e-20);
  if(i==-1){
    printf("Problemas Metodo de Jacobi en el Calculo de autovectores\n");
    return(-1);
  }
  /*ami_printf1d("autovalores",x,N);*/
  for(i=0;i<N;i++)
    v[i]=B_J[i][0];
  ami_normalizar_vector(v,N);
  *l=x[0];


  /* MEJORAMOS UN POCO EL AUTOVECTOR POR EL METODO DE LA POTENCIA */

   /* INICIALIZAMOS v */
 /* for(i=0;i<N;i++)
    aux[i]=v[i]; */

  /* REALIZAMOS LAS ITERACIONES */
 /* k=0;
  while((k++)<ami_max_iterR){
     ami_gauss(B,aux,N);
     norma=0;
     for(j=0;j<N;j++)
       norma+=aux[j]*aux[j];
     if(norma<=0){
       free(aux);
       ami_free2d(B_J);
       free(x);
        printf("Problemas Calculo Autovector\n");
       return(-1);
     }
     norma=sqrt(norma);
     error=0; error2=0;
     for(i=0;i<N;i++){
       aux[i]/=norma;
       error+=(aux[i]-v[i])*(aux[i]-v[i]);
       error2+=(aux[i]+v[i])*(aux[i]+v[i]);
       v[i]=aux[i];
     }
     if(error>error2) error=error2;
     printf("funcion ami_autovalor_minimo : error=%e\n\n",error);
     if(error<ERRORMAXIMO)
       k=ami_max_iterR+5;
  } */

  free(aux);
  ami_free2d(B_J);
  free(x);
  return(0);

 /* if(k>ami_max_iterR+3 || (0.0000001*error)<ERRORMAXIMO){
    *l=1./norma;
    return(0);
  }
  printf("Excedido Numero Maximo de Iteraciones Para Calculo Autovector\n");
  return(-1);
  */
}


/**
 * METODO DE GAUSS PARA RESOLVER SISTEMAS DE ECUACIONES DE 3x3
 *
 * \return DEVUELVE LA SOLUCION EN EL VECTOR b.
 */
int ami_gauss3x3(double A[3][3],double b[3])
/* double A[3][3],b[3]; */
{
  double PASO[3][4],max,paso,mul;
  int i,j,i_max,k;

  for(i=0;i<3;i++){
    for(j=0;j<3;j++){
      PASO[i][j]=A[i][j];
    }
    PASO[i][3]=b[i];
  }

  for(i=0;i<3;i++){
    max=fabs(PASO[i][i]);
    i_max=i;
    for(j=i;j<3;j++){
       if(fabs(PASO[j][i])>max){
         i_max=j; max=fabs(PASO[j][i]);
       }
    }
    if(max<10e-30){
      printf("Sistema no tiene Solucion\n"); return(-1);
    }
    if(i_max>i){
      for(k=0;k<=3;k++){
        paso=PASO[i][k];
        PASO[i][k]=PASO[i_max][k];
        PASO[i_max][k]=paso;
      }
    }
    for(j=i+1;j<3;j++){
      mul=-PASO[j][i]/PASO[i][i];
      for(k=i;k<=3;k++) PASO[j][k]+=mul*PASO[i][k];
    }
  }
  if(fabs(PASO[2][2])<10e-30){
      printf("Sistema no tiene Solucion\n"); return(-1);
    }

  for(i=2;i>0;i--){
    for(j=i-1;j>=0;j--){
      mul=-PASO[j][i]/PASO[i][i];
      for(k=i;k<=3;k++) PASO[j][k]+=mul*PASO[i][k];
    }
  }
  for(i=0;i<3;i++)
      b[i]=PASO[i][3]/PASO[i][i];

   return(0);
}


/**
 * CALCULO DE LA MATRIZ INVERSA POR EL METODO DE GAUSS-JORDAN MATRICES 3x3 
 */
int ami_inversa3x3(double** A,double** A_1)
     /* double A[3][3],A_1[3][3]; */
{
  double PASO[3][6],max,paso,mul;
  int i,j,i_max,k;

  for(i=0;i<3;i++){
    for(j=0;j<3;j++){
      PASO[i][j]=A[i][j];
      PASO[i][j+3]=0.;
    }
  }
  for(i=0;i<3;i++)
      PASO[i][i+3]=1.;

  for(i=0;i<3;i++){
    max=fabs(PASO[i][i]);
    i_max=i;
    for(j=i;j<3;j++){
       if(fabs(PASO[j][i])>max){
         i_max=j; max=fabs(PASO[j][i]);
       }
    }

    if(max<10e-30){
      printf("Sistema no tiene Solucion\n"); return(-1);
    }
    if(i_max>i){
      for(k=0;k<6;k++){
        paso=PASO[i][k];
        PASO[i][k]=PASO[i_max][k];
        PASO[i_max][k]=paso;
      }
    }

    for(j=i+1;j<3;j++){
      mul=-PASO[j][i]/PASO[i][i];
      for(k=i;k<6;k++) PASO[j][k]+=mul*PASO[i][k];
    }
  }
  if(fabs(PASO[2][2])<10e-30){
      printf("Sistema no tiene Solucion\n"); return(-1);
    }

  for(i=2;i>0;i--){
    for(j=i-1;j>=0;j--){
      mul=-PASO[j][i]/PASO[i][i];
      for(k=i;k<6;k++) PASO[j][k]+=mul*PASO[i][k];
    }
  }
  for(i=0;i<3;i++)
    for(j=3;j<6;j++)
      PASO[i][j]/=PASO[i][i];

  for(i=0;i<3;i++)
    for(j=0;j<3;j++)
      A_1[i][j]=PASO[i][j+3];

   return(0);
}


/**
 * CALCULO DE LA MATRIZ INVERSA  (MATRICES 2x2) 
 */
int ami_inversa2x2(double** A,double** A_1)
{
  double det;

  det = A[0][0]*A[1][1]-A[0][1]*A[1][0];
  if (fabsf(det)<1E-10) {
      printf("ami_inversa2x2: system with no solution\n");
      return(-1);
  }
  A_1[0][0] =  A[1][1]/det;
  A_1[0][1] = -A[0][1]/det;
  A_1[1][0] = -A[1][0]/det;
  A_1[1][1] =  A[0][0]/det;
  return 0;
}

/**
 * METODO DE GAUSS PARA RESOLVER SISTEMAS DE ECUACIONES
 *
 * \return DEVUELVE LA SOLUCION EN EL VECTOR b 
 */
int ami_gauss(double **A,double *b,int N)
     /*double **A,*b; int N; */
{
  double **PASO,max,paso,mul;
  int i,j,i_max,k;
  PASO=(double **)malloc(sizeof(double*)*N);
  for(i=0;i<N;i++)
    PASO[i]=(double *)malloc(sizeof(double)*(N+1));

  for(i=0;i<N;i++){
    for(j=0;j<N;j++){
      PASO[i][j]=A[i][j];
    }
    PASO[i][N]=b[i];
  }

  for(i=0;i<N;i++){
    max=fabs(PASO[i][i]);
    i_max=i;
    for(j=i;j<N;j++){
       if(fabs(PASO[j][i])>max){
         i_max=j; max=fabs(PASO[j][i]);
       }
    }
    if(max<10e-30){
      printf("Sistema no tiene Solucion 0\n");
      for(i=0;i<N;i++)
        free(PASO[i]);
      free(PASO);
      return(-1);
    }
    if(i_max>i){
      for(k=0;k<=N;k++){
        paso=PASO[i][k];
        PASO[i][k]=PASO[i_max][k];
        PASO[i_max][k]=paso;
      }
    }
    for(j=i+1;j<N;j++){
      mul=-PASO[j][i]/PASO[i][i];
      for(k=i;k<=N;k++) PASO[j][k]+=mul*PASO[i][k];
    }
  }
  if(fabs(PASO[N-1][N-1])<10e-30){
      printf("Sistema no tiene Solucion 1\n");
      for(i=0;i<N;i++)
       free(PASO[i]);
      free(PASO);
      return(-1);
    }

  for(i=N-1;i>0;i--){
    for(j=i-1;j>=0;j--){
      mul=-PASO[j][i]/PASO[i][i];
      for(k=i;k<=N;k++) PASO[j][k]+=mul*PASO[i][k];
    }
  }
  for(i=0;i<N;i++)
      b[i]=PASO[i][N]/PASO[i][i];

  for(i=0;i<N;i++)
    free(PASO[i]);
  free(PASO);
  return(0);
}


/**
 * FUNCION PARA MULTIPLICAR MATRIZ Y VECTOR
 *
 * \param a  Matriz de entrada
 * \param x  Vector de entrada 
 * \param v  Vector de salida 
 * \param dim  Dimension de la matriz y vector 
 */
double *ami_MxV(double **a,double *x, double *v,int dim)
{
  int i,j;
  for(i=0;i<dim;i++){
    v[i]=a[i][0]*x[0];
    for(j=1;j<dim;j++)
       v[i]+=a[i][j]*x[j];
  }
  return(v);
}

/**
 * FUNCION PARA MULTIPLICAR VECTOR Y VECTOR                  
 *
 * \param x  Vector de entrada 
 * \param v  Vector de entrada 
 * \param dim  Dimension de los vectores 
 */
double ami_VxV(double *x,double *v,int dim)
{
  int i;
  double sol=x[0]*v[0];
  for(i=1;i<dim;i++)
    sol+=x[i]*v[i];
  return(sol);
}

/**
 * FUNCION PARA MULTIPLICAR  UNA MATRIZ Y SU TRASPUESTA     
 *
 * \param a  Matriz de entrada 
 * \param as  Matriz de salida 
 * \param dimf  N filas matriz a 
 * \param dimc  N columnas matriz a 
 */
double **ami_MxM(double **a,double **as,int dimf,int dimc)
{
  int i,j;
  for(i=0;i<dimf;i++){
    for(j=i;j<dimf;j++)
       as[j][i]=as[i][j]=ami_VxV(a[i],a[j],dimc);
  }
  return(as);
}


/**
 * CALCULO DE LA MATRIZ INVERSA POR EL METODO DE GAUSS-JORDAN
 */
int ami_inversa(double **A,double **A_1,int N)
     /* double **A,**A_1; int N; */
{
    
  if (N==2) return ami_inversa2x2(A,A_1);
  if (N==3) return ami_inversa3x3(A,A_1);
  
  double **PASO,max,paso,mul;
  int i,j,i_max,k;
  PASO=(double **)malloc(sizeof(double*)*N);
  for(i=0;i<N;i++)
    PASO[i]=(double *)malloc(sizeof(double)*(N*2));

  for(i=0;i<N;i++){
    for(j=0;j<N;j++){
      PASO[i][j]=A[i][j];
      PASO[i][j+N]=0.;
    }
  }
  for(i=0;i<N;i++)
      PASO[i][i+N]=1.;

  for(i=0;i<N;i++){
    max=fabs(PASO[i][i]);
    i_max=i;
    for(j=i;j<N;j++){
       if(fabs(PASO[j][i])>max){
         i_max=j; max=fabs(PASO[j][i]);
       }
    }

    if(max<10e-30){
      printf("Matriz No Invertible\n");
      for(i=0;i<N;i++)
       free(PASO[i]);
      free(PASO);
      return(-1);
    }
    if(i_max>i){
      for(k=0;k<2*N;k++){
        paso=PASO[i][k];
        PASO[i][k]=PASO[i_max][k];
        PASO[i_max][k]=paso;
      }
    }

    for(j=i+1;j<N;j++){
      mul=-PASO[j][i]/PASO[i][i];
      for(k=i;k<2*N;k++) PASO[j][k]+=mul*PASO[i][k];
    }
  }
  if(fabs(PASO[N-1][N-1])<10e-30){
      printf("Matriz No-Invertible\n");
      for(i=0;i<N;i++)
       free(PASO[i]);
      free(PASO);
      return(-1);
    }

  for(i=N-1;i>0;i--){
    for(j=i-1;j>=0;j--){
      mul=-PASO[j][i]/PASO[i][i];
      for(k=i;k<2*N;k++) PASO[j][k]+=mul*PASO[i][k];
    }
  }
  for(i=0;i<N;i++)
    for(j=N;j<2*N;j++)
      PASO[i][j]/=PASO[i][i];

  for(i=0;i<N;i++)
    for(j=0;j<N;j++)
      A_1[i][j]=PASO[i][j+N];
  for(i=0;i<N;i++)
    free(PASO[i]);
  free(PASO);


  return(0);
}

/**
 * FUNCTION TO COMPUTE A GRADIENT OF A 2D IMAGE USING A 3x3 MASK 
*/
void ami_grad_2df_3x3(float **image,/* ORIGINAL IMAGE */
    float **image_x,float **image_y,/* OUTPUT IMAGE GRADIENT */
	int dim_x,int dim_y) /* IMAGE DIMENSIONS */
{
  int i,j;
//  float dx1,dx2,dy1,dy2;
  double coef1,coef2; //,c1,d1;
  coef1=sqrt((double) 2.);
  coef2=0.25*(2.-coef1);
  coef1=0.5*(coef1-1);
  /* WE COMPUTE THE DERIVATIVES */
  for(i=1;i<(dim_x-1);i++){
	for(j=1;j<(dim_y-1);j++){
	  image_x[i][j]=coef1*(image[i+1][j]-image[i-1][j])+
	                coef2*(image[i+1][j+1]-image[i-1][j+1]+image[i+1][j-1]-image[i-1][j-1]);        ;
	  image_y[i][j]=coef1*(image[i][j+1]-image[i][j-1])+
	                coef2*(image[i+1][j+1]-image[i+1][j-1]+image[i-1][j+1]-image[i-1][j-1]);
	}
  }
  /* WE FILL THE BOUNDARY VALUES */
  for(i=0;i<dim_x;i++){
	image_x[i][0]=image_x[i][1]; image_x[i][dim_y-1]=image_x[i][dim_y-2];
	image_y[i][0]=image_y[i][1]; image_y[i][dim_y-1]=image_y[i][dim_y-2];
  }
  for(j=0;j<dim_y;j++){
	image_x[0][j]=image_x[1][j]; image_x[dim_x-1][j]=image_x[dim_x-2][j];
	image_y[0][j]=image_y[1][j]; image_y[dim_x-1][j]=image_y[dim_x-2][j];
  }
}
/**
 * FUNCTION TO COMPUTE A BASIC GRADIENT OF A 2D IMAGE 
 */
void ami_grad_2df(float **image,/* ORIGINAL IMAGE */
    float **image_x,float **image_y,/* OUTPUT IMAGE GRADIENT */
	int dim_x,int dim_y) /* IMAGE DIMENSIONS */
{
  int i,j;
  float dx1,dx2,dy1,dy2;
  /* WE COMPUTE THE DERIVATIVES */
  for(i=1;i<(dim_x-1);i++){
	for(j=1;j<(dim_y-1);j++){
	  dx1=image[i+1][j]-image[i][j];
	  dx2=image[i][j]-image[i-1][j];
	  dy1=image[i][j+1]-image[i][j];
	  dy2=image[i][j]-image[i][j-1];
	  image_x[i][j]=fabs(dx1)>fabs(dx2)?dx1:dx2;
	  image_y[i][j]=fabs(dy1)>fabs(dy2)?dy1:dy2;
	}
  }
  /* WE FILL THE BOUNDARY VALUES */
  for(i=0;i<dim_x;i++){
	image_x[i][0]=image_x[i][1]; image_x[i][dim_y-1]=image_x[i][dim_y-2];
	image_y[i][0]=image_y[i][1]; image_y[i][dim_y-1]=image_y[i][dim_y-2];
  }
  for(j=0;j<dim_y;j++){
	image_x[0][j]=image_x[1][j]; image_x[dim_x-1][j]=image_x[dim_x-2][j];
	image_y[0][j]=image_y[1][j]; image_y[dim_x-1][j]=image_y[dim_x-2][j];
  }
}

/**
 * FUNCTION TO REMOVE NOISE USING A MEDIAN FILTER IN A NEIGBORHOOD 
*/
void ami_noise_median_filter_2df(
    float **image,/* ORIGINAL IMAGE (INPUT AND OUTPUT DATA */
	int dim_x,int dim_y,/* IMAGE DIMENSIONS */
	int window_radius,/* RADIUS OF THE WINDOW WE USE TO COMPUTE THE MEDIAN */
	float percentage,/* IF RELATIVE ERROR(IMAGE VALUE POINT,MEDIAN) >PERCENTAJE THEN WE APPLY MEDIAN FILTER */
    int Niter) /* NUMBER OF TIMES WE APPLY THE PROCEDURE */
{
  int i,j,k,l,m,window_size=(1+2*window_radius)*(1+2*window_radius);
  float *x_p,mean,**image_2;
  int N;
  ami_malloc1d(x_p,float,window_size);
  ami_calloc2d(image_2,float,dim_x,dim_y);
  for(m=0;m<Niter;m++){
    ami_matriz_copia(image,image_2,dim_x,dim_y);
    for(i=0;i<dim_x;i++){
      for(j=0;j<dim_y;j++){
	    N=0;
        for(k=-1;k<2;k++)
	      for(l=-1;l<2;l++)
	        if( (i+k)>=0 && (i+k)<dim_x && (j+l)>=0 && (j+l)<dim_y ){ x_p[N]=image[i+k][j+l]; N++;}
        mean=ami_mediana_float(N/2,N,x_p);
	    if( fabs(image[i][j]-mean) > ( percentage*( 0.75*fabs(mean)+0.25*fabs(image[i][j])) ) ){image_2[i][j]=mean;}
	  }
    }
    ami_matriz_copia(image_2,image,dim_x,dim_y);
  }
  free(x_p); ami_free2d(image_2);
}


