
#ifndef _AMI_FFT_H_
#define _AMI_FFT_H_

/**
 * AUXILIARY FUNCTION TO COMPUTE A FFT
 */
void fourn(float *data, long *nn, int ndim, int isign);

/**
 * FUNCTION TO COMPUTE A 3D FFT
 *
 * \param data  input and output dat 
 * \param speq  output 2D matrix 
 * \param nn1,nn2,nn3  dimensions of the 3D matrix (it has to be power of 2) 
 * \param isign   isign==1 means direct FFT isign=-1 means inverse FFT 
 */

void rlft3(
  float ***data, /* input and output dat */
  float **speq, /* output 2D matrix */
  long nn1, long nn2, long nn3, /* dimensions of the 3D matrix (it has to be power of 2) */
  int isign); /* isign==1 means direct FFT isign=-1 means inverse FFT */

/**
 * FUNCTION TO COMPUTE A 3D CONVOLUTION USING FFT THE CONVOLVED SIGNAL IS RETURNED IN data1 POINTER 
 *
 * \param data1  input first image and output image convolution 
 * \param data2  input second image 
 * \param nn1,nn2,nn3  image dimension (it has to be power of 2) 
 */
void ami_fft_convolucion(
  float ***data1, /* input first image and output image convolution */
  float ***data2, /* input second image */
  long nn1, long nn2, long nn3); /* image dimension (it has to be power of 2) */


/**
 * FUNCTION TO COMPUTE A 3D CORRELATION USING FFT THE CONVOLVED SIGNAL IS RETURNED IN data1 POINTER 
 *
 * \param data1  input first image and output image correlation 
 * \param data2  input second image 
 * \param nn1,nn2,nn3  image dimension (it has to be power of 2) 
 */
void ami_fft_correlation(
float ***data1, /* input first image and output image correlation */
float ***data2, /* input second image */
long nn1, long nn2, long nn3); /* image dimension (it has to be power of 2) */


/**
 * 3D FFT COMPUTATION OF A GAUSSIAN FUNCTION OF STANDARD DEVIATIONS st,sx,sy 
 * THE OUTPUT ARE IN data1 AND speq1 POINTER. IN THE CASE OF THE DIMENSION
 * nn1 BE EQUAL TO 1 WE RETURN A 2D FFT                                      
 */
void ami_fft_gauss(float ***data1, float **speq1, long nn1, long nn2, long nn3, float st, float sx, float sy);


/**
 * FUNCTION TO COMPUTE A 3D CONVOLUTION WITH A GAUSSIAN FUNCTION USING FFT THE CONVOLVED SIGNAL IS
 * RETURNED IN data1 POINTER. THE FFT OF THE GAUSSIAN FUNCTION HAS BEEN PREVIOUSLY COMPUTED AND STORED
 * IN data2 AND speq2 POINTER                                                                       
 */
void ami_fft_gauss_convolucion(float ***data1, float ***data2, float **speq2, long nn1, long nn2, long nn3);


#endif // _AMI_FFT_H_
