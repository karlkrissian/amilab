/****************************************************************
Created by Carmelo Quintana Hern�dez
email: a3182@dis.ulpgc.es
*****************************************************************/

#ifndef AMI_CORRELATION2D_H
#define AMI_CORRELATION2D_H


/* Function to remove noise using a median filter in a neigborhood of a lattice */
void ami_qhc_noise_median_filter_2df (
    float **image, /* Original image (input and output data) */
    int dimX, int dimY, /* Image dimensions */
    int windowRadius, /* Radius of the window we use to compute the median */
    float percentage, /* If relative error (image value point, mediam) > percentaje the we apply median filter */
    int nIter, /* Number of the times we apply the procedure */
    int xInit, int yInit, /* Initial point of the lattice */
    int xIntervalSize, int yIntervalSize /* Point displacement in the lattice */
    );

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
    );

/* Function to extrapolate the 2D optic flow to points where is not defined */
void ami_qhc_optic_flow_extrapolation_2df (
    float **u, float **v, /* Flow to extrapolate */
    int xInit, int yInit, /* Initial point of the lattice */
    int xIntervalSize, int yIntervalSize, /* Point displacement in the lattice */
    float displacement, /* Warping displacement to control that correlation window is not centered in the point */
    int dimX, int dimY /* Image dimensions */
    );

/* Function to extrapolate the 2D optic flow to points where is not defined with clasification images */
void ami_qhc_optic_flow_extrapolation_2df_clasification (
    float **u, float **v, /* Flow to extrapolate */
    unsigned char **cla, /* Clasification image */
    int xInit, int yInit, /* Initial point of the lattice */
    int xIntervalSize, int yIntervalSize, /* Point displacement in the lattice */
    float displacement, /* Warping displacement to control that correlation window is not centered in the point */
    int dimX, int dimY, /* Image dimensions */
    unsigned char umbralClasification /* Umbral of clasification image */
    );

/* Function to compute 2D optif flow using a correlation technique */
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
    );

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
    );

/****************************************************************************************
 ****************************************************************************************/

 
#define inImage(x, y, width, height) (((x >= 0) && (x < width)) && ((y >= 0) && (y < height)))

#define trueValue(i,max) ((i > 0) ? ((i < max) ? i : max-1) : 0);

#define trueValueFourierMinus(i,max) ((i > 0) ? -1 : max-1-i);

#define trueValueFourierPlus(i,max) ((i < (max-1)) ? 1 : -i);

#define interpolateBilinear(image,i,j,dx,dy) image[i][j]*(1-dx)*(1-dy)+image[i+1][j]*(dx)*(1-dy)+image[i][j+1]*(1-dx)*(dy)+image[i+1][j+1]*(dx)*(dy);

#define ami_qhc_malloc4d(direccion,tipo,d1,d2,d3,d4) { int m1; \
          direccion = (tipo ****) malloc(sizeof(tipo ***)*(d1)); \
          for (m1 = 0; m1 < d1; m1++) { ami_malloc3d(direccion[m1],tipo,d2,d3,d4); } \
        }

#define ami_qhc_free4d(direccion,d1) { int m1; \
          for (m1 = 0; m1 < d1; m1++) { ami_free3d(direccion[m1]); } \
          free(direccion); \
        }

#define vector2Matriz(v,m,dimX,dimY,tipo) { int i, j; \
    	  for (i = 0; i < dimX; i++) \
	    for (j = 0; j < dimY; j++)  m[i][j] = (tipo) v[j*dimX+i]; \
	}

#define matriz2Vector(m,v,dimX,dimY,tipo) { int i, j; \
    	  for (i = 0; i < dimX; i++) \
	    for (j = 0; j < dimY; j++) v[j*dimX+i] = (tipo) m[i][j]; \
	}

#endif /* _CORRELACION2_ */
