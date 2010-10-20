#include "ami_prototypes.h"
#include "ami_correlation2D.h"

/* Function to remove noise using a median filter in a neigborhood of a lattice */
void ami_qhc_noise_median_filter_2df (
    float **image, /* Original image (input and output data) */
    int dimX, int dimY, /* Image dimensions */
    int windowRadius, /* Radius of the window we use to compute the median */
    float percentage, /* If relative error (image value point, mediam) > percentaje the we apply median filter */
    int nIter, /* Number of the times we apply the procedure */
    int xInit, int yInit, /* Initial point of the lattice */
    int xIntervalSize, int yIntervalSize /* Point displacement in the lattice */
    )
{
  int i, j, k, l, m, n, windowSize = (1+2*windowRadius)*(1+2*windowRadius), tempX, tempY;
  float *xP, mean, **image2;
  
  /* We allocate memory */
  ami_malloc1d(xP,float,windowSize); ami_calloc2d(image2,float,dimX,dimY);
  
  /* The loop */
  for (m = 0; m < nIter; m++) {
    for (i = xInit; i < dimX; i += xIntervalSize) {
      for (j = yInit; j < dimY; j += yIntervalSize) {
	for (n = 0, k = -windowRadius; k <= windowRadius; k++) {
	  tempX = i+k*xIntervalSize;
	  for (l = -windowRadius; l <= windowRadius; l++) {
	    tempY = j+l*yIntervalSize;
	    if (inImage(tempX,tempY,dimX,dimY)) xP[n++] = image[tempX][tempY]; /* Fill the matrix of the neigborhood */
	  }
	}
	mean = ami_mediana_float(n/2,n,xP);
	image2[i][j] = (fabs(image[i][j]-mean) > (percentage*(0.75*fabs(mean)+0.25*fabs(image[i][j])))) ? mean : image[i][j]; 
      }
    }
    ami_matriz_copia(image2,image,dimX,dimY); /* Copy the new version of the lattice */
  }
  
  /* Free memory */    
  free(xP); ami_free2d(image2);
}


/************************************************************************************************************************************/

/* Function to remove noise using a median filter in a neigborhood of a lattice with clasification images */
void ami_qhc_noise_median_filter_2df_clasification (
    float **image, /* Original image (input and output data) */
    unsigned char **cla, /* Clasification image */
    int dimX, int dimY, /* Image dimensions */
    int windowRadius, /* Radius of the window we use to compute the median */
    float percentage, /* If relative error (image value point, mediam) > percentaje the we apply median filter */
    int nIter, /* Number of the times we apply the procedure */
    int xInit, int yInit, /* Initial point of the lattice */
    int xIntervalSize, int yIntervalSize, /* Point displacement in the lattice */
    unsigned char umbralClasification /* Umbral of clasification image */
    )
{
  int i, j, k, l, m, n, windowSize = (1+2*windowRadius)*(1+2*windowRadius), tempX, tempY;
  float *xP, mean, **image2;
  unsigned char umbral;
  
  /* We allocate memory */
  ami_malloc1d(xP,float,windowSize); ami_calloc2d(image2,float,dimX,dimY);
  
  /* The loop */
  for (m = 0; m < nIter; m++) {
    for (i = xInit; i < dimX; i += xIntervalSize) {
      for (j = yInit; j < dimY; j += yIntervalSize) {
	if ((umbral = cla[i][j]) >= umbralClasification) {
	  for (n = 0, k = -windowRadius; k <= windowRadius; k++) {
	    tempX = i+k*xIntervalSize;
	    for (l = -windowRadius; l <= windowRadius; l++) {
	      tempY = j+l*yIntervalSize;
	      if ((inImage(tempX,tempY,dimX,dimY)) && (cla[tempX][tempY] == umbral))
		xP[n++] = image[tempX][tempY]; /* Fill the matrix of the neigborhood */
	    }
	  }
	  mean = ami_mediana_float(n/2,n,xP);
	  image2[i][j] = (fabs(image[i][j]-mean) > (percentage*(0.75*fabs(mean)+0.25*fabs(image[i][j])))) ? mean : image[i][j]; 
	}
      }
    }
    ami_matriz_copia(image2,image,dimX,dimY); /* Copy the new version of the lattice */
  }
  
  /* Free memory */    
  free(xP); ami_free2d(image2);
}


/************************************************************************************************************************************/

void ami_qhc_aux_extrapolation(
    int var, /* Var */
    int init, /* Initial point */
    int intervalSize, /* Displacement between points */
    int dim, /* Dimension */
    float displacement, /* displacement */
    int *var2, /* Output var */
    float *d /* Output displacement */
    ) 
{ 
  int auxvar2;
  float auxd;
  
  if (var < init) { auxvar2 = init; auxd = displacement; } 
  else { auxvar2 = init+((int)((var-init)/intervalSize))*intervalSize; }
  
  if ((auxvar2+intervalSize) >= dim) { auxvar2 -= intervalSize; auxd = intervalSize; } 
  else { auxd = var-auxvar2+displacement; } 
  
  *var2 = auxvar2; *d = auxd;
}


/* Function to extrapolate the 2D optic flow to points where is not defined */
void ami_qhc_optic_flow_extrapolation_2df (
    float **u, float **v, /* Flow to extrapolate */ 
    int xInit, int yInit, /* Initial point of the lattice */ 
    int xIntervalSize, int yIntervalSize, /* Point displacement in the lattice */ 
    float displacement, /* Warping displacement to control that correlation window is not centered in the point */ 
    int dimX, int dimY /* Image dimensions */ 
    ) 
{ 
  int i, j, i2, j2, intervalX, intervalY; 
  float dx, dy, valueX, valueY, den = xIntervalSize*yIntervalSize; 
  
  for (i = 0; i < dimX; i++) { 
    ami_qhc_aux_extrapolation(i,xInit,xIntervalSize,dimX,displacement,&i2,&dx); 
    valueX = xIntervalSize-dx; intervalX = i2+xIntervalSize; 
    for (j = 0; j < dimY; j++) { /* Actualize vars */ 
      ami_qhc_aux_extrapolation(j,yInit,yIntervalSize,dimY,displacement,&j2,&dy); 
      valueY = yIntervalSize-dy;  intervalY = j2+yIntervalSize; 
      /* We extrapolate the flow */ 
      u[i][j] = ((valueX*dy*u[i2][intervalY])+(valueX*valueY*u[i2][j2])+(dx*valueY*u[intervalX][j2])+(dx*dy*u[intervalX][intervalY]))/den; 
      v[i][j] = ((valueX*dy*v[i2][intervalY])+(valueX*valueY*v[i2][j2])+(dx*valueY*v[intervalX][j2])+(dx*dy*v[intervalX][intervalY]))/den; 
    } 
  } 
}  


/************************************************************************************************************************************/

/* Function to extrapolate the 2D optic flow to points where is not defined with clasification images */
void ami_qhc_optic_flow_extrapolation_2df_clasification (
    float **u, float **v, /* Flow to extrapolate */ 
    unsigned char **cla, /* Clasification image */
    int xInit, int yInit, /* Initial point of the lattice */ 
    int xIntervalSize, int yIntervalSize, /* Point displacement in the lattice */ 
    float displacement, /* Warping displacement to control that correlation window is not centered in the point */ 
    int dimX, int dimY, /* Image dimensions */ 
    unsigned char umbralClasification /* Umbral of clasification image */
    )
{
  int i, j, i2, j2, intervalX, intervalY; 
  float dx, dy, valueX, valueY, den = xIntervalSize*yIntervalSize, temp;
  unsigned char umbral; 
  float a0, a1, a2, a3;// b0, b1, b2, b3; 
  
  for (i = 0; i < dimX; i++) { 
    ami_qhc_aux_extrapolation(i,xInit,xIntervalSize,dimX,displacement,&i2,&dx); 
    valueX = xIntervalSize-dx; intervalX = i2+xIntervalSize; 
    for (j = 0; j < dimY; j++) { /* Actualize vars */ 
      if ((umbral = cla[i][j]) >= umbralClasification) {
	ami_qhc_aux_extrapolation(j,yInit,yIntervalSize,dimY,displacement,&j2,&dy); 
	valueY = yIntervalSize-dy;  intervalY = j2+yIntervalSize; 
	/* We extrapolate the flow */
	a0 = (umbral == cla[i2][intervalY]) ? valueX*dy : 0; a1 = (umbral == cla[i2][j2]) ? valueX*valueY : 0;
	a2 = (umbral == cla[intervalX][j2]) ? dx*valueY : 0; a3 = (umbral == cla[intervalX][intervalY]) ? dx*dy : 0;
	/*b0 = (a0 != 0) ? a0 : 1; b1 = (a1 != 0) ? a1 : 1; b2 = (a2 != 0) ? a2 : 1; b3 = (a3 != 0) ? a3 : 1; 
	  temp = b0*b1*b2*b3*den;*/ 
	temp = den;
	u[i][j] = ((a0*u[i2][intervalY])+(a1*u[i2][j2])+(a2*u[intervalX][j2])+(a3*u[intervalX][intervalY]))/temp; 
	v[i][j] = ((a0*v[i2][intervalY])+(a1*v[i2][j2])+(a2*v[intervalX][j2])+(a3*v[intervalX][intervalY]))/temp; 
      } 
    }
  } 
}


/****************************************************************************************************************************/ 
 
void ami_qhc_normalizar_matriz( 
    float ***matriz, /* Input matrix */ 
    int dimX, int dimY, int dimZ /* Dimension of the matrix */ 
    ) 
{ 
  int ml, m2, m3; 
  double alh = 0; 
  
  for (ml = 0; ml < dimX; ml++) 
    for (m2 = 0; m2 < dimY; m2++) 
      for (m3 = 0; m3 < dimZ; m3++) 
	alh += matriz[ml][m2][m3]*matriz[ml][m2][m3]; 
  
  if (alh > 0){  
    alh = sqrt(alh);  
    for (ml = 0; ml < dimX; ml++)  
      for (m2 = 0; m2 < dimY; m2++)  
	for (m3 = 0; m3 < dimZ; m3++)  
	  matriz[ml][m2][m3] /= alh;  
  } 
} 


void ami_qhc_subpixel_precision_gaussian ( 
    float ln1, float ln2, float ln3, /* Correlation values (minus, center and plus respectly) */ 
    int sizeCorrelationWindow, /* Dimension of the correlation window */ 
    float **u, /* Optic flow vector */ 
    int i, int j, /* Actual position */ 
    int value, /* Default value */ 
    float **c /* Confidence vector */
    ) 
{ 
  float den, paso; 
  
  if ((ln1 > ln2) || (ln3 > ln2) || (ln1 <= 0) || (ln2 <= 0) || (ln3 <= 0)) { paso = value; c[i][j] = 0; } 
  else { 
    ln1 = log(ln1); ln2 = log(ln2); ln3 = log(ln3); den = 2.*(ln1-2.*ln2+ln3); c[i][j] = 2*ln2-ln1-ln3; 
    paso = (den == 0) ? value : (value+(ln1-ln3)/den);
  } 
  u[i][j] += (paso < sizeCorrelationWindow/2) ? paso : (paso-sizeCorrelationWindow);
} 


/* Function to compute 2D optic flow using a correlation technique */ 
void ami_qhc_optic_flow_correlation ( 
    float ***image1, float ***image2, /* Input images */ 
    int dimX, int dimY, /* Dimension of the images */ 
    float **u, float **v, /* Input/output computed flow */ 
    float **c, /* Correlation value normalized between -1 and 1 */ 
    float **cX, float **cY, /* Confidence value in the x/y axe */ 
    int xInit, int yInit, /* Initial coordenate point to compute the correlation */ 
    int xIntervalSize, int yIntervalSize, /* Displacement between points for computing the correlation */ 
    int sizeCorrelationWindow[2], /* Size of correlation window (it can be different in each axe) and it has to be a power of 2 */ 
    float windowDeformation, /* Window parameter to control the warping in the correlation window;  
				windowDeformation = 0 -> image2 is warped using flow in all points of the window,  
				windowDedormation = 1 -> image2 is warped using flow in the central point of the window */ 
    int nImages /* Number of pair of images */
    ) 
{ 
  float ****da1C, ****da2C, **u2, **v2, x, y, maxCorrelation, sumCorrelation, dx, dy; 
  int i, i1, i2, i3, i4, j, j1, j2, j3, j4, di1, di2, dj1, dj2, k;
//  unsigned char valueClasification;
  
  /* We allocate memory */ 
  ami_qhc_malloc4d(da1C,float,(nImages+1),1,sizeCorrelationWindow[0],sizeCorrelationWindow[1]);
  ami_qhc_malloc4d(da2C,float,nImages,1,sizeCorrelationWindow[0],sizeCorrelationWindow[1]);
  ami_malloc2d(u2,float,dimX,dimY); ami_malloc2d(v2,float,dimX,dimY); 
  
  /* We copy the current flow */ 
  ami_matriz_copia(u,u2,dimX,dimY); ami_matriz_copia(v,v2,dimX,dimY); 
  
  /* We inicialize the correlation and confidence vectors */ 
  for (i = 0; i < dimX; i++)  
    for (j = 0; j < dimY; j++) { c[i][j] = cX[i][j] = cY[i][j] = 0.; } 
  
  /* We compute the correlation in each point of the lattice */ 
  for (i = xInit; i < dimX; i += xIntervalSize) { 
    for (j = yInit; j < dimY; j += yIntervalSize) {
      /* We compute each subwindow */ 
      int i2min = i-(sizeCorrelationWindow[0]/2);
      int i2max = i+(sizeCorrelationWindow[0]/2);
      if (i2min==i2max) i2max=i2min+1;
      for (i3 = 0, i2 = i2min; i2 < i2max; i2++, i3++) { 
	i1 = trueValue(i2,dimX); 
      int j2min = j-(sizeCorrelationWindow[1]/2);
      int j2max = j+(sizeCorrelationWindow[1]/2);
      if (j2min==j2max) j2max=j2min+1;
	for (j3 = 0, j2 = j2min; j2 < j2max; j2++, j3++) {  
	  j1 = trueValue(j2,dimY);  
	  x = i1+(1.-windowDeformation)*u2[i1][j1]+windowDeformation*u2[i][j]; 
	  y = j1+(1.-windowDeformation)*v2[i1][j1]+windowDeformation*v2[i][j];
	  if (x < 0) { i4 = 0; dx = 0; } else if (x >= (dimX-1)) { i4 = dimX-2; dx = 1; } else { i4 = x; dx = x-i4; }
	  if (y < 0) { j4 = 0; dy = 0; } else if (y >= (dimY-1)) { j4 = dimY-2; dy = 1; } else { j4 = y; dy = y-j4; }
	  for (k = 0; k < nImages; k++) { 
	    da1C[k][0][i3][j3] = image1[k][i1][j1]; 
	    da2C[k][0][i3][j3] = interpolateBilinear(image2[k],i4,j4,dx,dy);
	  }
	}
      } 
      
      /* We normalize the subwindows and compute the correlations */ 
      for (k = 0; k < nImages; k++) { 
	ami_qhc_normalizar_matriz(da1C[k],1,sizeCorrelationWindow[0],sizeCorrelationWindow[1]); 
	ami_qhc_normalizar_matriz(da2C[k],1,sizeCorrelationWindow[0],sizeCorrelationWindow[1]); 
	ami_fft_correlation(da1C[k],da2C[k],(long)1,(long)sizeCorrelationWindow[0],(long)sizeCorrelationWindow[1]); 
      } 
      
      /* We compute the maximun of the correlation to estimate the flow taking into account the periodicity of the signal */ 
      for (maxCorrelation = -(nImages+1), i3 = j3 = -1, i2 = 0; i2 < sizeCorrelationWindow[0]; i2++)  	       
	for (j2 = 0; j2 < sizeCorrelationWindow[1]; j2++) {
	  for (sumCorrelation = k = 0; k < nImages; k++) sumCorrelation += da1C[k][0][i2][j2]; /* First, we add the correlation values */
		    da1C[nImages][0][i2][j2] = sumCorrelation; /* IMPORTANT: da1C[nImages] = Sum_k da1C[k] */
		    if (sumCorrelation > maxCorrelation) { maxCorrelation = sumCorrelation; i3 = i2; j3 = j2; } 
	}   
      
      /* We check the maxCorrelation position. */
      if ((i3 == -1) || (j3 == -1)) { printf("Incorrect position.\n"); } 
      else {
	/* We compute the correlation maximum with subpixel precision using a gaussian */ 
	di1 = trueValueFourierMinus(i3,sizeCorrelationWindow[0]); 
di2 = trueValueFourierPlus(i3,sizeCorrelationWindow[0]); 
	dj1 = trueValueFourierMinus(j3,sizeCorrelationWindow[1]); 
dj2 = trueValueFourierPlus(j3,sizeCorrelationWindow[1]); 
	ami_qhc_subpixel_precision_gaussian(da1C[nImages][0][i3+di1][j3],maxCorrelation,da1C[nImages][0][i3+di2][j3],
					    sizeCorrelationWindow[0],u,i,j,i3,cX);
	ami_qhc_subpixel_precision_gaussian(da1C[nImages][0][i3][j3+dj1],maxCorrelation,da1C[nImages][0][i3][j3+dj2],
					    sizeCorrelationWindow[1],v,i,j,j3,cY);
	
	/* We fill the correlation */ 
	c[i][j] = maxCorrelation; 
      } 
    } 
  }
  
  /* We free the memory */
  ami_qhc_free4d(da1C,nImages+1); ami_qhc_free4d(da2C,nImages); ami_free2d(u2); ami_free2d(v2);
}


/* Function to compute 2D optif flow using a correlation technique with clasification images */ 
void ami_qhc_optic_flow_correlation_clasification ( 
    float ***image1, float ***image2, /* Input images */ 
    unsigned char **cla1, unsigned char **cla2, /* Clasification images */
    int dimX, int dimY, /* Dimension of the images */ 
    float **u, float **v, /* Input/output computed flow */ 
    float **c, /* Correlation value normalized between -1 and 1 */ 
    float **cX, float **cY, /* Confidence value in the x/y axe */ 
    int xInit, int yInit, /* Initial coordenate point to compute the correlation */ 
    int xIntervalSize, int yIntervalSize, /* Displacement between points for computing the correlation */ 
    int sizeCorrelationWindow[2], /* Size of correlation window (it can be different in each axe) and it has to be a power of 2 */ 
    float windowDeformation, /* Window parameter to control the warping in the correlation window;  
				windowDeformation = 0 -> image2 is warped using flow in all points of the window,  
				windowDedormation = 1 -> image2 is warped using flow in the central point of the window */ 
    int nImages, /* Number of pair of images */
    unsigned char umbralClasification /* Umbral of clasification images */
    ) 
{ 
  float ****da1C, ****da2C, **u2, **v2, x, y, maxCorrelation, sumCorrelation, dx, dy; 
  int i, i1, i2, i3, i4, i5, j, j1, j2, j3, j4, j5, limiti2, limitj2, di1, di2, dj1, dj2, k;
  unsigned char valueClasification;
  
  
  /* We allocate memory */ 
  ami_qhc_malloc4d(da1C,float,(nImages+1),1,sizeCorrelationWindow[0],sizeCorrelationWindow[1]);  
  ami_qhc_malloc4d(da2C,float,(nImages+1),1,sizeCorrelationWindow[0],sizeCorrelationWindow[1]); 
  ami_malloc2d(u2,float,dimX,dimY); ami_malloc2d(v2,float,dimX,dimY); 
    
  /* We copy the current flow */ 
  ami_matriz_copia(u,u2,dimX,dimY); ami_matriz_copia(v,v2,dimX,dimY); 
  
  /* We inicialize the correlation and confidence vectors */ 
  for (i = 0; i < dimX; i++)  
    for (j = 0; j < dimY; j++) { c[i][j] = cX[i][j] = cY[i][j] = 0.; } 
  
  /* We compute the correlation in each point of the lattice */ 
  for (i = xInit; i < dimX; i += xIntervalSize) { 
    for (j = yInit; j < dimY; j += yIntervalSize) { 
      if (((unsigned char) (valueClasification = cla1[i][j])) >= umbralClasification) { /* Is this a point of interest ? */
	/* We compute each subwindow */ 
	for (i3 = 0, i2 = i-(sizeCorrelationWindow[0]/2), limiti2 = i+(sizeCorrelationWindow[0]/2); i2 < limiti2; i2++, i3++) { 
	  i1 = trueValue(i2,dimX); 
	  for (j3 = 0, j2 = j-(sizeCorrelationWindow[1]/2), limitj2 = j+(sizeCorrelationWindow[1]/2); j2 < limitj2; j2++, j3++) {  
	    j1 = trueValue(j2,dimY);  
	    x = i1+(1.-windowDeformation)*u2[i1][j1]+windowDeformation*u2[i][j]; 
	    y = j1+(1.-windowDeformation)*v2[i1][j1]+windowDeformation*v2[i][j];
	    if (x < 0) { i5 = i4 = 0; dx = 0; } else if (x >= (dimX-1)) { i5 = i4 = dimX-2; dx = 1; } else { i4 = x; dx = x-i4; i5 = x+0.5; }
	    if (y < 0) { j5 = j4 = 0; dy = 0; } else if (y >= (dimY-1)) { j5 = j4 = dimY-2; dy = 1; } else { j4 = y; dy = y-j4; j5 = y+0.5; }
	    for (k = 0; k < nImages; k++) { 
	      da1C[k][0][i3][j3] = image1[k][i1][j1]; da2C[k][0][i3][j3] = interpolateBilinear(image2[k],i4,j4,dx,dy);
	    }
	    da2C[nImages][0][i3][j3] = (float) cla2[i5][j5]; /* IMPORTANT: da2C[nImages] = cla2 */
	  }
	} 
	
	/* We normalize the subwindows and compute the correlations */ 
	for (k = 0; k < nImages; k++) { 
	  ami_qhc_normalizar_matriz(da1C[k],1,sizeCorrelationWindow[0],sizeCorrelationWindow[1]); 
	  ami_qhc_normalizar_matriz(da2C[k],1,sizeCorrelationWindow[0],sizeCorrelationWindow[1]); 
	  ami_fft_correlation(da1C[k],da2C[k],(long)1,(long)sizeCorrelationWindow[0],(long)sizeCorrelationWindow[1]); 
	} 
	
	/* We compute the maximun of the correlation to estimate the flow taking into account the periodicity of the signal */ 
	for (maxCorrelation = -(nImages+1), i3 = j3 = -1, i2 = 0; i2 < sizeCorrelationWindow[0]; i2++)  	       
	  for (j2 = 0; j2 < sizeCorrelationWindow[1]; j2++) {
	    for (sumCorrelation = k = 0; k < nImages; k++) sumCorrelation += da1C[k][0][i2][j2]; /* First, we add the correlation values */
	    da1C[nImages][0][i2][j2] = sumCorrelation; /* IMPORTANT: da1C[nImages] = Sum_k da1C[k] */
	    if ((((unsigned char) da2C[nImages][0][i2][j2]) == valueClasification) && 
		(sumCorrelation > maxCorrelation)) { maxCorrelation = sumCorrelation; i3 = i2; j3 = j2; } 
	  }   
	
	/* We check the maxCorrelation position. */
	if ((i3 == -1) || (j3 == -1)) { printf("Incorrect position.\n"); } 
	else {
	  /* We compute the correlation maximum with subpixel precision using a gaussian */ 
	  di1 = trueValueFourierMinus(i3,sizeCorrelationWindow[0]); di2 = trueValueFourierPlus(i3,sizeCorrelationWindow[0]); 
	  dj1 = trueValueFourierMinus(j3,sizeCorrelationWindow[1]); dj2 = trueValueFourierPlus(j3,sizeCorrelationWindow[1]); 
	  ami_qhc_subpixel_precision_gaussian(da1C[nImages][0][i3+di1][j3],maxCorrelation,da1C[nImages][0][i3+di2][j3],sizeCorrelationWindow[0],u,i,j,i3,cX);
	  ami_qhc_subpixel_precision_gaussian(da1C[nImages][0][i3][j3+dj1],maxCorrelation,da1C[nImages][0][i3][j3+dj2],sizeCorrelationWindow[1],v,i,j,j3,cY);
	  
	  /* We fill the correlation */ 
	  c[i][j] = maxCorrelation;
	} 
      } 
    }
  }
  
  /* We free the memory */
  ami_qhc_free4d(da1C,nImages+1); ami_qhc_free4d(da2C,nImages+1); ami_free2d(u2); ami_free2d(v2);
}


/**************************************************************************************/
/* Function to compute a second order warping (it returns the interpolated value) */
//float ami_image_warping_2d_2o(
//    float **image, /* Original image (input data) */
//    float *u, /*  flow used to compute image displacement (input data) */
//    float x0, float y0, /* Point where the displacement is centered (input data) */
//    float x, float y, /* Point to be displaced by the local flow (input data) */
//    int dimX, int dimY /* Image dimensions (input data) */
//    )
//{
//  int i, j;
//  float x2, y2, dx, dy; //value;
  
  /* We compute the displacement */
//  x2 = x+u[0]+u[2]*(x-x0)+u[3]*(y-y0); y2 = y+u[1]+u[4]*(x-x0)+u[5]*(y-y0);
//  if (x2 < 0) { i = 0; dx = 0; } else if (x2 >= (dimX-1)) { i = dimX-2; dx = 1; } else { i = x2; dx = x2-i; }
//  if (y2 < 0) { j = 0; dy = 0; } else if (y2 >= (dimY-1)) { j = dimY-2; dy = 1; } else { j = y2; dy = y2-j; }
  /* We interpolate using bilinear algorithm */
//  return (interpolateBilinear(image,i,j,dx,dy)); 
//}

