/****************************************************************************/
/* image.h *       image                                            */
/*******************                                                        */
/* LIBRARY : image                                                      */
/* COMMENT : Volumetric Image Processing including image conversion, image filtering, 
  mathematical morphology and connected coomponent computation */
/* AUTHOR : H. Delingette and J. Montagnat                                  */
/* SEEALSO :                                                                */
/****************************************************************************/

#ifndef __IMAGE__
#define __IMAGE__

#ifdef __cplusplus
extern "C" {
#endif

#include <core.h>
#include <Zinrimage.h>


/* The size of the sampling of the unit sphere for computing 
the gradient and edge force in a 3D image */


#define DEFAULT_SPHERE_FREQUENCY 3
  /* The level of tesselation of the unit sphere to store gradient direction vectors */
#define DEFAULT_DIRECTION_VECTOR_ARRAY_SIZE 20*DEFAULT_SPHERE_FREQUENCY*DEFAULT_SPHERE_FREQUENCY
  /* The number of unit vectors of the spherical dome when the unit sphere is tesselated with 
     frequency DEFAULT_SPHERE_FREQUENCY */

typedef enum 
{ 
  SLICE_X = 0, /* Slice with X=column=constant */
  SLICE_Y = 1, /* Slice with Y=row=constant */
  SLICE_Z = 2  /* Slice with Z=plane=constant */
} SLICE_GEOMETRY;
/* the different geometry of a slice of a volumetric image */

typedef enum 
{ 
 ALONG_ROW,
 ALONG_COLUMN,
 ALONG_PLANE
} IMAGE_DIRECTION;
/* The three direction in a volumetric image along which is performed the filtering */

typedef union {
  unsigned char c; /* an unsigned char */
  short int si; /* a signed short int */
  unsigned short int usi; /* an unsigned short int */
  int i; /* a signed int */
  unsigned int ui;/* an unsigned int */
  LONG li; /* a long int */
  unsigned LONG uli;/* an unsigned  long int */
  float f;/* a float */
  double d; /* a double */
  unsigned char rgba[4]; /* a RGBA value */  
} IMAGE_VALUE, *PTRIMAGE_VALUE;


typedef enum
{ 
  FOUR_CONNECTIVITY = 4, /* Four connectivity : the voxels sharing an edge in the same plane are considered
			    as neighbors */
  SIX_CONNECTIVITY = 6,/* Six connectivity : the voxels sharing a face  in 3D are considered
			    as neighbors */
  EIGHT_CONNECTIVITY = 8,/* Eight connectivity : the voxels sharing a vertex in the same plane are considered
			    as neighbors */
  EIGHTEEN_CONNECTIVITY = 18,/* Eighteen connectivity : the voxels sharing an edge in 3D are considered
			    as neighbors */
  TWENTY_SIX_CONNECTIVITY = 26/* Twenty six connectivity : the voxels sharing a vertex in 3D are considered
				 as neighbors */
} CONNECTIVITY_TYPE;
/* The type of connectivity ( or neighborhood ) for a 2D and 3D image */

typedef enum
{  
  NO_FILTERING, /* No filtering is performed */
  SMOOTHING_FILTER, /* the intensity  of the image is smoothed */
  FIRST_DERIVATIVE, /* The first derivative of the intensity is smoothed */
  SECOND_DERIVATIVE, /* The second derivative of the intensity is smoothed */
  THIRD_DERIVATIVE  /* The third derivative of the intensity is smoothed */
} FILTER_DERIVATIVE;
/* The type of filtering performed : */

typedef enum 
{ 
  DERICHE_GAUSSIAN, /* The approximation of the Gaussian proposed by Deriche 
		       that tends to make the filter more isotropic */
  MARTA_GAUSSIAN,/* The approximation of the Gaussian proposed by Marta Fidrich
		       that tends to make the filter more isotropic */
  DERICHE_STEP_EDGE /* The initial Deriche recursive filter */
} RECURSIVE_FILTER_TYPE;
/* the different type of recursive filtering. Each type corresponds to a
 proposed kernel to convolute with */

typedef struct 
{
  RECURSIVE_FILTER_TYPE filter_type; /* The type of filter */
  FILTER_DERIVATIVE filter_derivative; /* What should we compute */
  
  double alpha; /* The spatial extent of the filter : this is linked to the spatial extent of
		 filter by the relation alpha = SIGMA_TO_ALPHA/(2*sigma+1)*/

  int margin; /* The number of pixels that is used to enlarge the image for filtering. This is set 
		 by gradient3DRecursiveImage() and gradient2DRecursiveImage() to floor(sigma) */

  double sd1; /* Coefficient used in the recursive implementatation : set automatically when 
	       choosing the filter type */
  double sd2;/* Coefficient used in the recursive implementatation : set automatically when 
	       choosing the filter type */
  double sd3;/* Coefficient used in the recursive implementatation : set automatically when 
	       choosing the filter type */
  double sd4;/* Coefficient used in the recursive implementatation : set automatically when 
	       choosing the filter type */
  
  double sp0;/* Coefficient used in the recursive implementatation : set automatically when 
	       choosing the filter type */
  double sp1;/* Coefficient used in the recursive implementatation : set automatically when 
	       choosing the filter type */
  double sp2;/* Coefficient used in the recursive implementatation : set automatically when 
	       choosing the filter type */
  double sp3;/* Coefficient used in the recursive implementatation : set automatically when 
	       choosing the filter type */

  double sn0;/* Coefficient used in the recursive implementatation : set automatically when 
	       choosing the filter type */
  double sn1;/* Coefficient used in the recursive implementatation : set automatically when 
	       choosing the filter type */
  double sn2;/* Coefficient used in the recursive implementatation : set automatically when 
	       choosing the filter type */
  double sn3;/* Coefficient used in the recursive implementatation : set automatically when 
	       choosing the filter type */
  double sn4;/* Coefficient used in the recursive implementatation : set automatically when 
	       choosing the filter type */
} RECURSIVE_FILTER, *PTRRECURSIVE_FILTER;

typedef enum
{
  COMPONENT_BINARY, /* Only the binary image is outputed */
  COMPONENT_LABEL /* An unsigned short image is outputed corresponding to the
		     different labels of the connected components */
} COMPONENT_OUPUT;
/* The type of output that is desired when computing the connected component */

typedef struct {
  int min_size;      /* minimum size of connected components */
  int max_nbcc;      /* maximum number of connected components */
  COMPONENT_OUPUT   output;   /* output: binary image or label image */
} *PTRCONNEXE_PARAMETER, CONNEXE_PARAMETER;
/* The parameter of the connected component computation */

typedef enum
{ 
  FILL_THIS_COLOR, /* Fill a connected component with a given color */
  FILL_ALL_BUT_THIS_COLOR
} FILL_MODE;




typedef enum {
  UNKNOWN_TEXTURE /* Usually a texture loaded from a file */ ,
  ZONE_TEXTURE,
  TEXTURE_MAP,
  TEXTURE_CAMERA_MAP,
  TEXTURE_ENVIRONNEMENT
} TEXTURE_KIND;
/* The different types of texture image */

/* ============  TEXTURE  ===================*/
typedef struct point_texture
{

  TEXTURE_KIND texture_kind; /* The type of texture */

  PTRINRIMAGE image; /* The PTRINRIMAGE pointer describing the image */

  int rank; /* The rank in the list of textures */

  char name[FILENAME_LENGTH]; /* the filename of the texture */

  struct point_texture *following; /* The following texture in list */

  struct point_texture *previous; /* The previous texture in list */

} TEXTURE, *PTRTEXTURE;
/* The texture data structure */

/*-------- File texture.c---------*/
PTRTEXTURE load_texture (char *filename /* name of the image */);
/* Loads and returns  a 2D or 3D texture image. returns NULL when the loading fails */

PTRTEXTURE texture_alloc ();
/* Allocate a texture data structure. The texture type is initialized as UNKNOWN_TEXTURE */


void remove_texture (PTRTEXTURE texture /* The texture image */);
/* Frees all memory buffers associated  with a texture image */

void get_color(PTRTEXTURE texture /* The texture image */, 
	       int row /* A row index */, int col /* a column index */,int plane  /* a plane index */,
	       float color[3] /* The RGB color indexes coded  between 0.0 and 1.0 */);
/* Store in color[3] the RGB components of the color of the voxel store in texture->image->array[plane][row][col] */

/*-------- File image_operators.c --------*/
void addTwoImages(PTRINRIMAGE image1 /* The first operand image */, 
		  PTRINRIMAGE image2 /* The second operand image. It must of the same type than image1*/, 
		  PTRINRIMAGE output /* The resulting image. It must have been previously allocated 
				      and of the same type and size as  image1 and  image2*. output may be
				      the same as image2 */);
/* Store in output, the sum of the pixel value of image1 and the pixel value of image2 located
   as the same pixel position. The three images must be of the same type and output must  have been 
   previously allocated. output may the same image as image 1 or image 2*/

void mulTwoImages(PTRINRIMAGE image1 /* The first operand image */, 
		  PTRINRIMAGE image2 /* The second operand image. It must of the same type than image1*/, 
		  PTRINRIMAGE output /* The resulting image. It must have been previously allocated 
				      and of the same type and size as  image1 and  image2*. output may be
				      the same as image2 */);
/* Store in output, the product of the pixel value of image1 and the pixel value of image2 located
   as the same pixel position. The three images must be of the same type and output must  have been 
   previously allocated. output may the same image as image 1 or image 2*/

void divTwoImages(PTRINRIMAGE image1 /* The first operand image */, 
		  PTRINRIMAGE image2 /* The second operand image. It must of the same type than image1*/, 
		  PTRINRIMAGE output /* The resulting image. It must have been previously allocated 
				      and of the same type and size as  image1 and  image2*. output may be
				      the same as image2 */);
/* Store in output, the division of the pixel value of image1 and the pixel value of image2 located
   as the same pixel position. If a  pixel value in image2 is zero then store zero in the output image.
   The three images must be of the same type and output must  have been 
   previously allocated. output may the same image as image 1 or image 2*/

void subTwoImages(PTRINRIMAGE image1 /* The first operand image */, 
		  PTRINRIMAGE image2 /* The second operand image. It must of the same type than image1*/, 
		  PTRINRIMAGE output /* The resulting image. It must have been previously allocated 
				      and of the same type and size as  image1 and  image2*. output may be
				      the same as image2 */);
/* Store in output, the difference of the pixel value of image1 and the pixel value of image2 located
   as the same pixel position. The three images must be of the same type and output must  have been 
   previously allocated. output may the same image as image 1 or image 2*/

void andTwoImages(PTRINRIMAGE image1 /* The first operand image */, 
		  PTRINRIMAGE image2 /* The second operand image. It must of the same type than image1*/, 
		  PTRINRIMAGE output /* The resulting image. It must have been previously allocated 
				      and of the same type and size as  image1 and  image2*. output may be
				      the same as image2 */);
/* Store in output, the logical and of the pixel value of image1 and the pixel value of image2 located
   as the same pixel position. The three images must be of the same type and size. output must  have been 
   previously allocated. output may the same image as image 1 or image 2*/

void orTwoImages(PTRINRIMAGE image1 /* The first operand image */, 
		 PTRINRIMAGE image2 /* The second operand image. It must of the same type than image1*/, 
		 PTRINRIMAGE output /* The resulting image. It must have been previously allocated 
				      and of the same type and size as  image1 and  image2*. output may be
				      the same as image2 */);
/* Store in output, the logical or of the pixel value of image1 and the pixel value of image2 located
   as the same pixel position. The three images must be of the same type  and size and output must  have been 
   previously allocated. output may the same image as image 1 or image 2*/

void xorTwoImages(PTRINRIMAGE image1 /* The first operand image */, 
		  PTRINRIMAGE image2 /* The second operand image. It must of the same type than image1*/, 
		  PTRINRIMAGE output /* The resulting image. It must have been previously allocated 
				      and of the same type and size as  image1 and  image2*. output may be
				      the same as image2 */);
/* Store in output, the logical xor of the pixel value of image1 and the pixel value of image2 located
   as the same pixel position.  The three images must be of the same type  and size and output must  have been 
   previously allocated. output may the same image as image 1 or image 2*/

void inverseImage(PTRINRIMAGE image /* The  operand image */, 
		  PTRINRIMAGE output /* The resulting image. It must have been previously allocated 
				      and of the same type and size as  image. output may be
				      the same as image */);
/* Store in output, the logical not of the pixel value of image located
   as the same pixel position.  The two images must be of the same type and size and output must  have been 
   previously allocated. output may the same image as image*/

void addConstantToImage(PTRINRIMAGE image/* The  operand image */,  double value/* a constant */);
/* Increment each pixel of image with the constant value*/

void mulConstantToImage(PTRINRIMAGE image/* The  operand image */, double value/* a constant */);
/* Multiply each pixel of image with the constant value*/

void melImages(PTRINRIMAGE output/* The output image */, 
	       PTRINRIMAGE input/* The input image that must be of the same type than output*/,
	       int cout /* The column number of the origin in the output image */, 
	       int rout /* The row number of the origin in the output image */, 
	       int pout /* The plane number of the origin in the output image */, 
	       int cin /* The column number of the origin in the input image */,
	       int rin /* The row number of the origin in the input image */, 
	       int pin /* The plane number of the origin in the input image */,
	       int dcol /* The number of columns of the voxel block */, 
	       int drow /* The number of rows of the voxel block */, 
	       int dp /* The number of planes of the voxel block */);
/* Copy in the output image a 3D block of voxels from the input image. The two images must have the
   same voxel type must may not have the same size. The block is deliminated by 
cin <= c <= cin+dcol, rin <= r <= rin+drow, pin <= p <= pin+dp in the input image and by 
cout <= c <= cout+dcol, rout <= r <= rout+drow, pout <= p <= pout+dp in the output image. */

void flipInrimage(PTRINRIMAGE image /* The image */, 
		  SLICE_GEOMETRY plane_direction/* The plane that is used for the symmetry */);
/* Apply an orthogonal symmetry parallel the plane whose direction is given by 
   plane_direction and that passes through the center voxel of the image */

/*-------- File threshold.c --------*/
void ternarizeImage(PTRINRIMAGE image /* The input and output image*/,
		    IMAGE_VALUE lt /* The low_threshold*/,
		    IMAGE_VALUE ht /* The high threshold*/,
		    IMAGE_VALUE background /* The background value of the output image*/,
		    IMAGE_VALUE lf /* The low foreground */, 
		    IMAGE_VALUE hf/* The high foreground */);
/* Apply a double thresholding on image. If a pixel value v < lt then it is set to background.
   If lt <= v < ht then it is set to lf and if v>= ht then it is set to hf */

void ternarizeImageToOtherFormat(PTRINRIMAGE input /* The input  image*/,
				 IMAGE_VALUE lt /* The low_threshold*/,
				 IMAGE_VALUE ht /* The high threshold*/,
				 PTRINRIMAGE output /* The output image. It must have the same size as the input image*/,
				 IMAGE_VALUE background /* The background value of the output image*/,
				 IMAGE_VALUE lf /* The low foreground */, 
				 IMAGE_VALUE hf/* The high foreground */);
/* Apply a double thresholding on the input image and store it in the output image.
   We call v a pixel of the input image and w its corresponding pixel in the output image.
   If a pixel value v < lt then w is set to background.
   If lt <= v < ht then w is set to lf and if v>= ht then w is set to hf */

void binarizeImage(PTRINRIMAGE image/* The input and output image*/,
		   IMAGE_VALUE background/* background value*/,
		   IMAGE_VALUE foreground /* foreground value */);
/*  Binarize an image. If a pixel value v is not a background pixel then it is set to foreground */


void binarizeImageToOtherFormat(PTRINRIMAGE input /* The input  image*/,
				IMAGE_VALUE background_input/* The background of the input image*/,
				PTRINRIMAGE output /* The output image. It must have the same size as the input image*/,
				IMAGE_VALUE background_output/* background value of the output image*/,
				IMAGE_VALUE foreground_output /* foreground value of the output image*/);
/*  Binarize an image. If  we call v a pixel of the input image and w its corresponding pixel 
    in the output image, then if v is not a background pixel then w is set to foreground_output otherwise w is set
    to background_output*/

void thresholdInrimage(PTRINRIMAGE image/* The input and output image*/, 
		       IMAGE_VALUE lt /* The low_threshold*/, IMAGE_VALUE ht /* The high threshold*/,
		       IMAGE_VALUE background /* background value */, 
		       IMAGE_VALUE foreground /* foreground value */);
/* Thresholds an image. If a pixel value v is such as lt <= v <= ht then v is set to foreground 
   otherwise it is set to background */

void cropHistogram(PTRINRIMAGE image/* The input and output image*/, 
		   IMAGE_VALUE lt /* The low_threshold*/, 
		   IMAGE_VALUE ht /* The high threshold*/,
		   IMAGE_VALUE min_value /* the low value*/, 
		   IMAGE_VALUE max_value /* The high value */);
/* Crop the Histogramm of an image. If a pixel value v < lt, then v is set to min_value. 
   If v > ht then it is set max_value. Otherwise it remains unchanged */

void greyLevelsWindow(PTRINRIMAGE  image/* The input and output image*/, 
		      int z /* Indicate which slice should be windowed. If z<0 then all slices
			       are windowed*/, 
		      IMAGE_VALUE lt /* The low threshold*/,
		      IMAGE_VALUE ht /* The high threshold*/);
/* Apply windowing on the image. If a pixel value v < lt then is it set to the minimum value of the image type. 
   If v> ht then is it set to the maximum value of the image type. Otherwise the voxel value is linearly
   interpolated between the minimum and the maximum voxel value */


/*-------- File convert.c --------*/
PTRINRIMAGE duplicateInrimage(PTRINRIMAGE input /* the image to duplicate */);
/* creates a copy of the input image. The returned image as the same voxel size */

LONG imageValueToLong(IMAGE_VALUE iv/* An image value*/, 
		      WORDTYPE type /* word type of the image value*/);
/* Converts an image value structure of type "type" into a long int */

double imageValueToDouble(IMAGE_VALUE iv/* An image value*/,
			  WORDTYPE type /* word type of the image value*/);
/* Converts an image value structure of type "type" into a double */

IMAGE_VALUE intToImageValue(int value/* an int value*/, 
			    WORDTYPE type /* The word type of the outputed image value */);
/* Converts an integer value into an image value structure */

IMAGE_VALUE doubleToImageValue(double value/* a double value*/, 
			       WORDTYPE  type /* The word type of the outputed image value */);
/* Converts a double value into an image value structure */

PTRINRIMAGE convertCastInrimage(PTRINRIMAGE image /* The input image*/, 
				WORDTYPE type /* the word type to convert the image to */);
/* Create an image into of the same size than the input image but of type "type".
   The pixels are converted to the type "type" with a cast */

PTRINRIMAGE convertScaleInrimage(PTRINRIMAGE image /* The input image*/, 
				 WORDTYPE type /* the word type to convert the image to */);
/* Create an image into of the same size than the input image but of type "type".
   The pixels are converted to the type "type" by scaling them to the minimum and maximum
   value of type*/

void copyCastInrimage(PTRINRIMAGE input /* The input image */,
		      PTRINRIMAGE output /* the output image. It must have the same size as
					  input and must have been previously allocated*/);
/* Copy the input image into output image. The pixels are converted to the type "type" with a cast */


void copyScaleInrimage(PTRINRIMAGE input /* The input image */,
		       PTRINRIMAGE output /* the output image. It must have the same size as
					  input and must have been previously allocated*/);
/* Copy the input image into output image.    The pixels are converted to the type "type" 
   by scaling them to the minimum and maximum  value of type*/

void copyLineToDoubleBuffer(WORDTYPE type /* The type of the input buffer*/,
			    void *input /* the input array of size length*step*/,
			    double *output /* The output double array of size length*/,
			    unsigned int length /*The length of the output array*/,
			    unsigned int step /* The parameter is equal to 1 if input is a line
						 buffer or is the number of columns if input is
						 a 2D array */);
/* Copy the content of the buffer "input" into the "output" line array. Voxel values of 
   the input array are cast as double values. "input" may be a line buffer 
   if step = 1 or an 2D array if strp = ncols */

void copyLineToFloatBuffer(WORDTYPE type /* The type of the input buffer*/,
			   void *input /* the input array of size length*step*/,
			   float *output /* The output double array of size length*/,
			   unsigned int length /*The length of the output array*/,
			   unsigned int step /* The parameter is 1 if input is a line buffer or
						is the number of columns if input is a 2D array */);
/* Copy the content of the buffer "input" into the "output" line array. Voxel values of 
   the input array are cast as float values. "input" may be a line buffer 
   if step = 1 or an 2D array if strp = ncols */


/*-------- File morpho.c---------*/
void dilationImage(PTRINRIMAGE image /* The input and output image */,
		   CONNECTIVITY_TYPE connectivity /* The type of structuring element*/,
		   IMAGE_VALUE background /* background value */,
		   IMAGE_VALUE foreground /* foreground value */);
/* Apply an dilation morphological operation on an image. The image is binarized based on 
   the background and foreground values */

void erosionImage(PTRINRIMAGE image /* The input and output image */,
		   CONNECTIVITY_TYPE connectivity /* The type of structuring element*/,
		   IMAGE_VALUE background /* background value */,
		   IMAGE_VALUE foreground /* foreground value */);
/* Apply an erosion morphological operation on an image. The image is binarized based on 
   the background and foreground values */

void openingImage(PTRINRIMAGE image /* The input and output image */,
		  int niter /* The number of iterations of the erosion and dilation operations */,
		  CONNECTIVITY_TYPE connectivity /* The type of structuring element*/,
		  IMAGE_VALUE background /* background value */,
		  IMAGE_VALUE foreground /* foreground value */);
/* Apply an opening morphological operation on an image. The dilation and erosion operations
   are iterated "niter" times. The image is binarized based on 
   the background and foreground values */

void closureImage(PTRINRIMAGE image /* The input and output image */,
		  int niter /* The number of iterations of the dilation and erosion  operations */,
		  CONNECTIVITY_TYPE connectivity /* The type of structuring element*/,
		  IMAGE_VALUE background /* background value */,
		  IMAGE_VALUE foreground /* foreground value */);
/* Apply an closure morphological operation on an image. The dilation and erosion operations
   are iterated "niter" times. The image is binarized based on 
   the background and foreground values */


/*-------- File inrtools.c -------*/
PTRINRIMAGE createPlane(PTRINRIMAGE image /* The input image */, 
			int plane /* The plane number */);
/* Creates a sub-image corresponding to one slice on the input image.
   No memory allocation is performed since it shares the buffer of image->data
   The data  pointer of the returned image is pointing on the buffer 
   image->data + z*image->nrows*image->ncols*sizeofImageVoxel(image). 
   The array pointer of the returned image is set with the index3DArray() 
   procedure */

void freePlane(PTRINRIMAGE image /* The image to be freed */);
/* Free a slice-image created by the function createPlane() */

int sameImageValue(WORDTYPE type /* The word type of the two image values*/,
		   IMAGE_VALUE v1 /* First image value */, 
		   IMAGE_VALUE v2 /* Second image value */);
/* Compare the two images values v1 and v2 of the same type "type"*/
  
int sameVoxelValue(PTRINRIMAGE image /* The input image*/, 
		   int row /* The row index of the voxel */, 
		   int col /* The column index of the voxel */, 
		   int plane /* The plane index of the voxel */, 
		   IMAGE_VALUE v /* The image value to compare with */);
/* Compare the image value v with the voxel image ->array[plane][row][col] */

int scanImageValue(WORDTYPE type /* The type of the image value */, 
		   char *string /* The string to scan from */, 
		   PTRIMAGE_VALUE v /* The pointer on the image value to 
				       read from the string */);
/* Scan the string "string" to read an image value. Return 0 if the scan
   has not been completed and 1 otherwise. The scan is performed through
   sscanf() */

void printImageValue(WORDTYPE type /* The type of the image value v */, 
		     char *string /* The string to print in*/, 
		     IMAGE_VALUE v /* The image value to print */);
/* print in the string "string" the image value v with the function sprintf() */

void setVoxelValue(PTRINRIMAGE image /* The image */, 
		   int row /* The row index of the voxel */,
		   int col /* The column index of the voxel */, 
		   int plane /* The plane index of the voxel */, 
		   IMAGE_VALUE v /* The image value to set */);
/* Sets the voxel [plane][row][col] to v */

IMAGE_VALUE getVoxelValue(PTRINRIMAGE image /* The image */, 
		   int row /* The row index of the voxel */,
		   int col /* The column index of the voxel */, 
		   int plane /* The plane index of the voxel */);
/* Returns the voxel value of the voxel [plane][row][col] */

LONG getVoxelValueAsLong(PTRINRIMAGE image /* The image */, 
		   int row /* The row index of the voxel */,
		   int col /* The column index of the voxel */, 
		   int plane /* The plane index of the voxel */);
/* Returns the voxel value of the voxel [plane][row][col]  as a LONG */

double getVoxelValueAsDouble(PTRINRIMAGE image /* The image */, 
		   int row /* The row index of the voxel */,
		   int col /* The column index of the voxel */, 
		   int plane /* The plane index of the voxel */);
/* Returns the voxel value of the voxel [plane][row][col]  as a double */

void computeImageMinMax(PTRINRIMAGE image /* input image */,
			PTRIMAGE_VALUE min /* The computed minimum value of the image */,
			PTRIMAGE_VALUE max /* The computed maximum value of the image */);
/* Computes the minimum and maximum value of the image "image" */

IMAGE_VALUE getMinImageValue(WORDTYPE type /* The image type */ );
/* returns the minimum value of a voxel of type "type" */

IMAGE_VALUE getMaxImageValue(WORDTYPE type /* The image type */ );
/* returns the maximum value of a voxel of type "type" */

void mask(PTRINRIMAGE input /* The input image */, 
	  PTRINRIMAGE mask /* The mask image of same size than input. The mask
			    image must be of type WT_UNSIGNED_CHAR, 
			    WT_SIGNED_SHORT, WT_UNSIGNED_SHORT */, 
	  PTRINRIMAGE output /* The output image of same size and type than the 
				input image. The image buffers must have been 
				previously allocated */);
/* Creates a masked image "output" given an input image and a mask image
   if the mask value is not null then copy a voxel of the input image into the
   output. Otherwise put 0 in the output image */

int imageBounds(PTRINRIMAGE image /* The input image */, 
		int *colmin /* The minimum column index of the non-background voxels */,
		int *colmax /* The maximum column index of the non-background voxels */, 
		int *rowmin /* The minimum row index of the non-background voxels */, 
		int *rowmax /* The maximum row index of the non-background voxels */,
		int *planemin /* The minimum plane index of the non-background voxels */, 
		int *planemax /* The maximum plane index of the non-background voxels */,
		PTRIMAGE_VALUE min /* The computed minimum image value of the image. 
				      This value is considered as the background value */, 
		PTRIMAGE_VALUE max  /* The computed maximum image value of the image. */);
/* Computes the bounding box of non-background voxels. The background is 
   considered to be the minimum voxel value of the image. Computes the 
   maximum voxel value of the image */

PTRINRIMAGE crop(PTRINRIMAGE image /* The input image*/ , 
		 int colmin /* The minimum column index */, 
		 int rowmin  /* The minimum row index */, 
		 int planemin /* The minimum plane index */, 
		 int colmax /* The maximum column index */, 
		 int rowmax /* The maximum row index */, 
		 int planemax /* The maximum column index */);
/* Creates a cropped image of an input image with the same image type */


void box(inrimage *inr /* inrimage to draw the box in */,
	 int x1 /* x min bound of box drawn */,
	 int y1 /* y min bound of box drawn */,
	 int z1 /* z min bound of box drawn */,
	 int x2 /* x max bound of box drawn */,
	 int y2 /* y max bound of box drawn */,
	 int z2 /* z max bound of box drawn */,
	 double mean /* box color */,
	 double dev /* standard deviation of gaussian noise */);
/* Draws a box from (x1, y1, z1) to (x2, y2, z2) in an inrimage.<br>
   The box color is mean. If dev is not null, a gaussian noise is used. */


void line2D(PTRINRIMAGE /* The input image */, 
	    int col1 /* The column index of the first extremity */, 
	    int row1 /* The row index of the first extremity */, 
	    int col2 /* The column index of the second extremity */, 
	    int row2 /* The row index of the second extremity */, 
	    int plane /* The plane index of the two extremities */, 
	    IMAGE_VALUE v /* The image value of thee drawn line */);
/* draw a 2D line with image value v between the two extremities 
   (row1,col1) and (row2,col2) */

BOOLEAN compareImages(PTRINRIMAGE image1 /* First image */,
		      PTRINRIMAGE image2 /* Second image */);
/* Test if two images have the same size, type and if the two buffers 
   are the same */

PTRINRIMAGE computeVectorNorm3D(PTRINRIMAGE vx /* image of the x coordinate */,
				PTRINRIMAGE vy /* image of the y coordinate */,
				PTRINRIMAGE vz /* image of the z coordinate */);
/* Returns a WT_FLOAT image where each voxel is the norm of the vector 
   (vx,vy,vz) ie sqrt( vx*vx + vy*vy + vz*vz )*/

PTRINRIMAGE computeVectorNorm2D(PTRINRIMAGE vx /* image of the x coordinate */,
				PTRINRIMAGE vy /* image of the y coordinate */);
/* Returns a WT_FLOAT image where each voxel is the norm of the vector 
   (vx,vy) ie sqrt( vx*vx + vy*vy )*/

BOOLEAN sameImageSize(PTRINRIMAGE image1 /* First image */,
		      PTRINRIMAGE image2 /* Second image */);
/* Tests if two images have the size (rows, columns, planes ) */

BOOLEAN inImage(PTRINRIMAGE image /* the image */,
		int row /* The row index */, 
		int col /* The column index */, 
		int plane /* The plane index */);
/* Tests if voxel [rowe,col,plane} lies inside the image "image". Returns true if it
 does and false otherwise*/

/*-------- File recursive_filters.c -------*/
PTRRECURSIVE_FILTER recursiveFilterAlloc(); /* allocate the recursive filter 
					       parameter */

PTRRECURSIVE_FILTER InitRecursiveFilter(double alpha /* parameter that is 
							related to the size of the filter */, 
					RECURSIVE_FILTER_TYPE filter_type /* The type of recursive filter */, 
					FILTER_DERIVATIVE /* The order of the filter */, 
					int margin /* The margin of the filter */);
/* This procedure returns a data structure describing the parameters of a 
   recursive filter */

void filterRecursiveImage(PTRINRIMAGE input /* The input image */, 
			  double ***output /* The output buffer. The buffer 
					      must have been previously allocated */, 
			  PTRRECURSIVE_FILTER filter_parameter /* the parameter of the filter after it was created by InitRecursiveFilter() */,
			  IMAGE_DIRECTION direction /* The direction where the filter is applied */);
/* apply a recursive filter described by "filter_parameter" on the input image 
   along the direction "direction" and store the results in the output buffer */

void filterRecursiveImageFloat(PTRINRIMAGE input /* The input image */, 
			       float ***output /* The output buffer. The buffer 
					      must have been previously allocated */, 
			       PTRRECURSIVE_FILTER filter_parameter /* the parameter of the filter after it was created by InitRecursiveFilter() */,
			       IMAGE_DIRECTION direction /* The direction where the filter is applied */);
/* apply a recursive filter described by "filter_parameter" on the input image 
   along the direction "direction" and store the results in the output buffer */

void gradient2DRecursiveImage(PTRINRIMAGE image /* the input image */,
			      PTRINRIMAGE dr /* The gradient along row direction. It must be of type WT_FLOAT  */,
			      PTRINRIMAGE dc /* The gradient along column direction. It must be of type WT_FLOAT  */,
			      RECURSIVE_FILTER_TYPE filter_type /* The type of recursive filter */,
			      double sigma /* The extension of the filter */);
/* Computes the 2D gradient of an input image. The first derivatives 
   are stored in the "dr" and "dc" images and are computed by applying
   a recursive filter of type "filter_type" and of extension "sigma" */

void gradient3DRecursiveImage(PTRINRIMAGE image /* the input image */,
			      PTRINRIMAGE dr /* The gradient along row direction. It must be of type WT_FLOAT */,
			      PTRINRIMAGE dc /* The gradient along column direction. It must be of type WT_FLOAT */,
			      PTRINRIMAGE dp /* The gradient along plane direction. It must be of type WT_FLOAT  */,
			      RECURSIVE_FILTER_TYPE filter_type /* The type of recursive filter */,
			      double sigma /* The extension of the filter */);
/* Computes the 2D gradient of an input image. The first derivatives 
   are stored in the "dr" and "dc" images and are computed by applying
   a recursive filter of type "filter_type" and of extension "sigma" */

void laplacian2DRecursiveImage(PTRINRIMAGE image /* the input image */,
			      PTRINRIMAGE laplacian /* The Laplacian of the input image. It must be of type WT_FLOAT  */,
			      RECURSIVE_FILTER_TYPE filter_type /* The type of recursive filter */,
			      double sigma /* The extension of the filter */);
/* Computes the 2D laplacian of an input image. The result is stored in the 
   "laplacian" image and is computed by applying
   a recursive filter of type "filter_type" and of extension "sigma". The 
   image buffer "laplacian" must have been previously allocated*/

void laplacian3DRecursiveImage(PTRINRIMAGE image /* the input image */,
			      PTRINRIMAGE laplacian /* The Laplacian of the input image. It must be of type WT_FLOAT  */,
			      RECURSIVE_FILTER_TYPE filter_type /* The type of recursive filter */,
			      double sigma /* The extension of the filter */);
/* Computes the 3D laplacian of an input image. The result is stored in the 
   "laplacian" image and is computed by applying
   a recursive filter of type "filter_type" and of extension "sigma". The 
   image buffer "laplacian" must have been previously allocated*/

void smoothing2DRecursiveImage(PTRINRIMAGE image /* the input and output image */,
			       RECURSIVE_FILTER_TYPE filter_type /* The type of recursive filter */,
			       double sigma /* The extension of the filter */);
/* Apply a 2D smoothing on an input image. The result is stored in the input
   image is computed by applying a recursive filter of type "filter_type" and of
   extension "sigma".*/


void smoothing3DRecursiveImage(PTRINRIMAGE image /* the input and output image */,
			       RECURSIVE_FILTER_TYPE filter_type /* The type of recursive filter */,
			       double sigma /* The extension of the filter */);
/* Apply a 3D smoothing on an input image. The result is stored in the input
   image is computed by applying a recursive filter of type "filter_type" and of
   extension "sigma".*/



/*-------- File gradient.c -------*/
VECT  *createDirectionArray(int frequency /* The frequency of the spherical dome */);
/* Creates a vector array corresponding to the position of unit vector on a 
   spherical dome of frequency "frequency". The size of the array is 
   20 * frequency *frequency */

PTRINRIMAGE  createImage3DGradientDirection(PTRINRIMAGE dr /* The gradient along row direction. It must be of type WT_FLOAT */,
					    PTRINRIMAGE dc /* The gradient along column direction. It must be of type WT_FLOAT */,
					    PTRINRIMAGE dp /* The gradient along plane direction. It must be of type WT_FLOAT  */,
					    int frequency /* The frequency of the spherical dome. It must be > 0 and < 57 */);
/* Creates an image whose value represents the direction of the gradient vector.    The returned image is of type WT_UNSIGNED_CHAR if frequency <= 3 and of
   type WT_UNSIGNED_SHORT otherwise. For each voxel, we compute the normalized 
   gradient vector and find in the vector array created with 
   createDirectionArray() what is the index of closest vector and store 
   this index in the output image */

PTRINRIMAGE  createImage2DGradientDirection(PTRINRIMAGE dr /* The gradient along row direction. It must be of type WT_FLOAT */,
					    PTRINRIMAGE dc /* The gradient along column direction. It must be of type WT_FLOAT */,
					    int frequency /* The frequency of the spherical dome. It must be > 0 and < 57 */);
/* Creates an image whose value represents the direction of the gradient vector.    The returned image is of type WT_UNSIGNED_CHAR if frequency <= 3 and of
   type WT_UNSIGNED_SHORT otherwise. For each voxel, we compute the normalized 
   gradient vector and find in the vector array created with 
   createDirectionArray() what is the index of closest vector and store 
   this index in the output image */

void keepGradientExtrema2D(PTRINRIMAGE gradient /* The input and output gradient norm image */,
			   PTRINRIMAGE dr /* The normalized gradient along row direction. It must be of type WT_FLOAT */,
			   PTRINRIMAGE dc /* The normalized gradient along column direction. It must be of type WT_FLOAT */,
			   float minimum_gradient /* Threshold on the gradient norm */);
/* Filter the gradient norm image, by keeping voxels that are a local maximum of 
   the gradient norm in the gradient direction. Sets other voxels to zero.
   "dr" and "dc" are images representing the gradient direction and therefore 
   must be normalized :  dr*dr + dc*dc =1. If the gradient norm is less than 
   "minimum_gradient" then sets the gradient norm to zero */

void keepGradientExtrema3D(PTRINRIMAGE gradient /* The input and output gradient norm image */,
			   PTRINRIMAGE dr /* The normalized gradient along row direction. It must be of type WT_FLOAT */,
			   PTRINRIMAGE dc /* The normalized gradient along column direction. It must be of type WT_FLOAT */,
			   PTRINRIMAGE dp /* The normalized gradient along plane direction. It must be of type WT_FLOAT */,
			   float minimum_gradient /* Threshold on the gradient norm */);
/* Filter the gradient norm image, by keeping voxels that are a local maximum of 
   the gradient norm in the gradient direction. Sets other voxels to zero.
   "dr", "dc" and "dp" are images representing the gradient direction and 
   therefore must be normalized :  dr*dr + dc*dc + dp*dp =1. If the gradient 
   norm is less than "minimum_gradient" then sets the gradient norm to zero */

/*-------- File line_convolution.c -------*/
void lineConvoluteImage(PTRINRIMAGE input /* the input image */, 
			double ***output /* The output double buffer. It must have been previously allocated*/,
			double *filter /* the filter array of size "filter_size" */,
			int filter_size /* The size of the filter array */,
			IMAGE_DIRECTION direction /* The direction where the filter is applied */);
/* Apply a convolution along a line direction, given by "direction" on the
   input image and saves the result in the output double buffer. The values of 
   the border voxels are duplicated */

void lineConvoluteImageFloat(PTRINRIMAGE input /* the input image */, 
			float ***output /* The output float buffer. It must have been previously allocated*/,
			double *filter /* the filter array of size "filter_size" */,
			int filter_size /* The size of the filter array */,
			IMAGE_DIRECTION direction /* The direction where the filter is applied */);
/* Apply a convolution along a line direction, given by "direction" on the
   input image and saves the result in the output float buffer. The values of 
   the border voxels are duplicated */

void gradient2DSobelImage(PTRINRIMAGE image /* the input image */,
			  PTRINRIMAGE dr /* The gradient along row direction. It must be of type WT_FLOAT and has the same size as the input image  */,
			  PTRINRIMAGE dc /* The gradient along column direction. It must be of type WT_FLOAT  and has the same size as the input image */,
			  int filter_size /* The extension of the filter */);
/* Computes the 2D gradient of an input image. The first derivatives 
   are stored in the "dr" and "dc" images and are computed by applying
   Sobel Filters of extension "sigma" */

void gradient3DSobelImage(PTRINRIMAGE image /* the input image */,
			  PTRINRIMAGE dr /* The gradient along row direction. It must be of type WT_FLOAT and has the same size as the input image  */,
			  PTRINRIMAGE dc /* The gradient along column direction. It must be of type WT_FLOAT  and has the same size as the input image */,
			  PTRINRIMAGE dp /* The gradient along plane direction. It must be of type WT_FLOAT  and has the same size as the input image */,
			  int filter_size /* The extension of the filter */);
/* Computes the 3D gradient of an input image. The first derivatives 
   are stored in the "dr" and "dc" and "dp" images and are computed by applying
   Sobel Filters of extension "sigma" */

void smoothing2DGaussianImage(PTRINRIMAGE image /* the input and output image */,
			      int filter_size /* The extension of the filter */);
/* Apply a 2D smoothing on an input image. The result is stored in the input
   image is computed by convolving the image with an approximation of the 
   Gaussian filter with limited support of size "filter_size".*/

void smoothing3DGaussianImage(PTRINRIMAGE image /* the input and output image */,
			      int filter_size /* The extension of the filter */);
/* Apply a 2D smoothing on an input image. The result is stored in the input
   image is computed by convolving the image with an approximation of the 
   Gaussian filter with limited support of size "filter_size".*/


/*-------- File connexe.c -------*/
PTRCONNEXE_PARAMETER connectedParameterAlloc();
/* Creates a structure to store parameters for connected component analysis */

PTRINRIMAGE getConnectedComponentBinary(PTRINRIMAGE image /* The input image */, 
					IMAGE_VALUE background /* The background value */, 
					IMAGE_VALUE foreground /* The foreground value */,
					CONNECTIVITY_TYPE connectivity /* The type of connectivity */,
					PTRCONNEXE_PARAMETER par /* The parameter of the connected component analysis */);
/* Perfomed connected component computation on a binary image. The image is 
   binarize based on the background and foreground value. If 
   par->output==COMPONENT_LABEL then returns a WT_UNSIGNED_SHORT image with the 
   labels of the connected components. if the input image is already of type 
   WT_UNSIGNED_SHORT then returns the labeled input image.
   if par->output==BINARY_OUTPUT then saves the selected connected component 
   in the input buffer and returns the input image */

PTRINRIMAGE getConnectedComponentThreshold(PTRINRIMAGE image /* The input image */, 
					   IMAGE_VALUE lt /* low threshold */,
					   IMAGE_VALUE ht /* High threshold */, 
					   IMAGE_VALUE background /* The background value */, 
					   IMAGE_VALUE foreground /* The foreground value */,
					CONNECTIVITY_TYPE connectivity /* The type of connectivity */,
					PTRCONNEXE_PARAMETER par /* The parameter of the connected component analysis */);
/* Perfomed connected component computation on a binary image. The image is 
   first thresholds based on the low threshold lt and high threshold ht. If 
   par->output==COMPONENT_LABEL then returns a WT_UNSIGNED_SHORT image with the 
   labels of the connected components. if the input image is already of type 
   WT_UNSIGNED_SHORT then returns the labeled input image.
   if par->output==BINARY_OUTPUT then saves the selected connected component 
   in the input buffer and returns the input image */

PTRINRIMAGE getHysteresisThresholding(PTRINRIMAGE image /* The input and output image */, 
					   IMAGE_VALUE lt /* low threshold */,
					   IMAGE_VALUE ht /* High threshold */, 
					   IMAGE_VALUE background /* The background value */, 
					   IMAGE_VALUE foreground /* The foreground value */,
					CONNECTIVITY_TYPE connectivity /* The type of connectivity */,
					PTRCONNEXE_PARAMETER par /* The parameter of the connected component analysis */);
/* Perfomed hysteresis thresholding connected component computation on a 
   binary image.  If par->output==COMPONENT_LABEL then returns a 
   WT_UNSIGNED_SHORT image with the labels of the connected components. 
   If the input image is already of type WT_UNSIGNED_SHORT then returns 
   the labeled input image.  If par->output==BINARY_OUTPUT then saves 
   the selected connected component in the input buffer and returns 
   the input image */

int select3DConnexComponent(PTRINRIMAGE image /* The image */, 
			    FILL_MODE fmode, 
			    CONNECTIVITY_TYPE connectivity,
			    int col, int row, int plane, IMAGE_VALUE stop_color, 
			    IMAGE_VALUE fill_color);

int select2DConnexComponent(PTRINRIMAGE image /* The image */, 
			    SLICE_GEOMETRY direction, 
			    FILL_MODE fmode,
			    CONNECTIVITY_TYPE connectivity, 
			    int col, int row, int plane, 
			    IMAGE_VALUE stop_color,
			    IMAGE_VALUE fill_color);

int label(PTRINRIMAGE, PTRINRIMAGE);

void  fillImage2D(PTRINRIMAGE image /* The image */,
		  IMAGE_VALUE background /* The background value */,
		  IMAGE_VALUE foreground /* The foreground value */);
/* First binarize the image based on the background and foreground value.
   Then fill the hollow 2D connected components */   

void  fillImage3D(PTRINRIMAGE image /* The image */,
		  IMAGE_VALUE background /* The background value */,
		  IMAGE_VALUE foreground /* The foreground value */);
/* First binarize the image based on the background and foreground value.
   Then fill the hollow 3D connected components */   



#ifdef __cplusplus
}
#endif

#endif





