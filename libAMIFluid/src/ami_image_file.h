
#ifndef _AMI_IMAGE_FILE_H_
#define _AMI_IMAGE_FILE_H_

/* FUNCTION TO WRITE A 24 bits COLOR BMP FORMAT IMAGE  (RETURN 0 IF FINISH PROPERLY -1 OTHERWISE). WE INVERSE THE ROW ORDER */
int ami_write_bmp_inverse_rows(char name[200], unsigned char *red, unsigned char *green, unsigned char *blue, int width, int height);


/* FUNCTION TO READ A 24 bits COLOR BMP FORMAT IMAGE  (RETURN 0 IF FINISH PROPERLY -1 OTHERWISE) */
int ami_read_bmp(const char name[200], unsigned char **red, unsigned char **green, unsigned char **blue, int *width, int *height);


/* FUNCTION TO WRITE A 24 bits COLOR BMP FORMAT IMAGE  (RETURN 0 IF FINISH PROPERLY -1 OTHERWISE) */
int ami_write_bmp(char name[200], unsigned char *red, unsigned char *green, unsigned char *blue, int width, int height);

/******************************************************************************************************************/
/* FUNCTION TO READ A 1024 X 1024 MSG IMAGE WITH 16 BITS DEPTH. WE USE AN UNSIGNED SHORT VECTOR TO KEEP THE IMAGE */
/******************************************************************************************************************/
//int ami_read_msg_1024_1024_16b_unsigned_short_v2(char name[200],unsigned short *image)
int ami_read_msg_16b_unsigned_short_v2(char name[200],unsigned short *image, int width, int height );

/******************************************************************************************************************/
/* FUNCTION TO READ A 1024 X 1024 MSG IMAGE WITH 8 BITS DEPTH. WE USE AN UNSIGNED SHORT VECTOR TO KEEP THE IMAGE */
/******************************************************************************************************************/
//int ami_read_msg_1024_1024_8b_unsigned_char(char name[200],unsigned char **image)
int ami_read_msg_8b_unsigned_char(char name[200],unsigned char **image, int width, int height );

/******************************************************************************************************************/
/* FUNCTION TO READ A 1024 X 1024 MSG IMAGE WITH 16 BITS DEPTH. WE USE AN UNSIGNED SHORT VECTOR TO KEEP THE IMAGE */
/******************************************************************************************************************/
//int ami_read_msg_1024_1024_16b_unsigned_short(char name[200],unsigned short **image)
int ami_read_msg_16b_unsigned_short(const char name[200],unsigned short **image, int width, int height );


/******************************************************************************************************************/
/* FUNCTION TO WRITE A 1024 X 1024 MSG IMAGE WITH 16 BITS DEPTH. WE USE AN UNSIGNED SHORT VECTOR TO KEEP THE IMAGE */
/******************************************************************************************************************/
//int ami_write_msg_1024_1024_16b_unsigned_short(char name[200],unsigned short *image)
int ami_write_msg_16b_unsigned_short(char name[200],unsigned short *image, int width, int height );

/*****************************************************************************************************************/
/* FUNCTION TO READ 1024 X 1024 TIF (8 BITS) IMAGE AND RETURN IN A FLOAT POINTER
******************************************************************************************************************/
//int ami_read_tiff_1024_1024_8b_float(char name[200],float *image_output)
int ami_read_tiff_8b_float(const char name[200],float *image_output, int width, int height );


/******************************************************************************************************************/
/* FUNCTION TO READ A 1280 X 1024 TIF IMAGE WITH 16 BITS DEPTH. WE USE AN UNSIGNED SHORT VECTOR TO KEEP THE IMAGE */
/******************************************************************************************************************/
//int ami_read_tiff_1280_1024_16b_unsigned_short( char name[200],unsigned short **image)
int ami_read_tiff_16b_unsigned_short(const char name[200],unsigned short **image, int width, int height );

/************************************************************************************************************
  FUNCTION TO READ A 2D IMAGE IN THE TIF FORMAT OF MSG OR PIV AND IN 24 BIT BMP FORMAT
************************************************************************************************************/
int ami_read_image2d(const char name[200], /* name of the file in disk */
                 float ***image_output,/* address of the pointer to the float output image*/
				 int *width, /* width of the output image */
				 int *height, /* height of the output image */
				 int type); /* type = 0 : 1024x1024 8 bits tif PIV image
				              type = 1 : 1024x1024 16 bits tif MSG image
							  type = 2 : 1280x1024 16 bits tif PIV image
							  type = 3 : a bmp image */


/************************************************************************************************************
  FUNCTION TO READ A 2D IMAGE IN THE TIF FORMAT OF MSG OR PIV AND IN 24 BIT BMP FORMAT
************************************************************************************************************/
int ami_read_image2dv(const char name[200], /* name of the file in disk */
                 float *image_output,/* address of the pointer to the float output image*/
				 int width, /* width of the output image */
				 int height, /* height of the output image */
				 int type); /* type = 0 : 8 bits tif PIV image
				              type = 1 : 16 bits tif MSG image
							  type = 2 : 16 bits tif PIV image
							  type = 3 : a bmp image
							  type = 4 : a TIFF image (from library) */                



#endif //  _AMI_IMAGE_FILE_H_
