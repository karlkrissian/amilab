/**
 * *************************************************************************
 *
 * \file THIS FILE IMPLEMENTS FUNCTIONS FOR READING/WRITING IMAGES.
 * \author Luis Alvarez (lalvarez@dis.ulpgc.es)
 * \date 16-10-2005
 *
 * *************************************************************************
*/


#include "TIFF.h"
#include "ami.h"
#include "ami_prototypes.h"

#include "ami_image_file.h"

/* FUNCTION TO WRITE A 24 bits COLOR BMP FORMAT IMAGE  (RETURN 0 IF FINISH PROPERLY -1 OTHERWISE). WE INVERSE THE ROW ORDER */
int ami_write_bmp_inverse_rows(char name[200], unsigned char *red, unsigned char *green, unsigned char *blue, int width, int height)
{
   int i,j,k;
   //unsigned char r,g,b;
   long cont;
   HEADER header;
   INFOHEADER infoheader;
   FILE *fptr;
   long size,m;
   unsigned char *image;

   /* Open file */
   if ((fptr = fopen(name,"wb")) == NULL) {
      fprintf(stderr,"Unable to open BMP file \"%s\"\n",name);
      return(-1);
   }

   /* Header Definition */
   header.type = (unsigned short int) 'M'*256+'B';
   header.size = (unsigned int) 3*width*height+54;
   header.reserved1 = 0;
   header.reserved2 = 0;
   header.offset = (unsigned int) 54;


  /* We write the header */
   if (fwrite(&header.type,sizeof(unsigned short),1,fptr) != 1) {
      fprintf(stderr,"Failed to write BMP info header\n");
      return(-1);
   }
   if (fwrite(&header.size,sizeof(unsigned int),1,fptr) != 1) {
      fprintf(stderr,"Failed to write BMP info header\n");
      return(-1);
   }
   if (fwrite(&header.reserved1,sizeof(unsigned short),1,fptr) != 1) {
      fprintf(stderr,"Failed to write BMP info header\n");
      return(-1);
   }
   if (fwrite(&header.reserved2,sizeof(unsigned short),1,fptr) != 1) {
      fprintf(stderr,"Failed to write BMP info header\n");
      return(-1);
   }
   if (fwrite(&header.offset,sizeof(unsigned int),1,fptr) != 1) {
      fprintf(stderr,"Failed to write BMP info header\n");
      return(-1);
   }


   /* INFOHEADER DEFINITION */
   infoheader.size = 40;
   infoheader.width = width;
   infoheader.height = height;
   infoheader.planes = (unsigned short int) 1;
   infoheader.bits = (unsigned short int) 24;
   infoheader.compression = (unsigned int) 0;
   infoheader.imagesize=(3*width + width%4)*height;//3*width*height;
   infoheader.xresolution=2834;
   infoheader.yresolution=2834;
   infoheader.ncolours = (unsigned int) 0 ;
   infoheader.importantcolours = (unsigned int) 0;

//   fprintf(stderr,"header: %d \t infohearder: %d", sizeof(HEADER), sizeof(INFOHEADER) );

   /* We write the infoheaderinformation */
   if (fwrite(&infoheader,sizeof(INFOHEADER),1,fptr) != 1) {
      fprintf(stderr,"Failed to write BMP info header\n");
      return(-1);
   }

   size=(3*width + width%4)*height;//width*height;	

   /* WE STORE THE IMAGE INFORMATION IN image */
   image=(unsigned char*)malloc(size*sizeof(unsigned char));
   //printf("size*3=%d\n",size*3);
   //cont=0;
   //for(m=0;m<size;m++){ image[cont]=blue[m]; image[cont+1]=green[m]; image[cont+2]=red[m]; cont+=3;}
   cont=0;
   for(i=0; i<height; i++){
     for(j=0; j<width; j++){
         m=(3*width+width%4)*(height-1-i) + 3*j;
         //m=3*((height-1-i)*width+j);
	image[m]=blue[i*width+j]; image[m+1]=green[i*width+j]; image[m+2]=red[i*width+j];
        //image[cont++]=blue[i*width + j]; image[cont++]=green[i*width + j]; image[cont++]=red[i*width + j];
     }
     // Rellenar bytes con 0 para obtener tamaño de fila múltiplo de 4 (considerando los 3 bytes RGB)
     for(k=0; k<width%4; k++) image[m+2+k]=0;
   }
/*   for(i=0;i<height;i++){
	 for(j=0;j<width;j++){
	    m=3*((height-1-i)*width+j);
		image[m]=blue[i*width+j]; image[m+1]=green[i*width+j]; image[m+2]=red[i*width+j];
	 }
   }

   /* We write the image */
  if (fwrite(image,size,1,fptr) != 1) {
     fprintf(stderr,"Image write failed\n");
     free(image);
     return(-1);
   }

   fclose(fptr);
   free(image);
   return(0);
}




/* FUNCTION TO READ A 24 bits COLOR BMP FORMAT IMAGE  (RETURN 0 IF FINISH PROPERLY -1 OTHERWISE) */
int ami_read_bmp(const char name[200], unsigned char **red, unsigned char **green, unsigned char **blue, int *width, int *height)
{
   int i,j;
   //int k;
   //unsigned char r,g,b;
   HEADER header;
   INFOHEADER infoheader;
   FILE *fptr;
   long size,cont;
   unsigned char *image;

   /* Open file */
   if ((fptr = fopen(name,"rb")) == NULL) {
      fprintf(stderr,"Unable to open BMP file \"%s\"\n",name);
      return(-1);
   }

   /* Read and check the header */
   if (fread(&header.type,sizeof(unsigned short),1,fptr) != 1) {
       fprintf(stderr,"Image read failed\n");
       return(-1);
   }

   /* Read and check the header */
   fprintf(stderr,"ID is: %d, should be %d\n",header.type,'M'*256+'B');
   if (header.type != (int) 'M'*256+'B') {
     fprintf(stderr,"Sorry, the file is not a bmp image file (magic number not correct)\n");
     return(-1);
   }

   if (fread(&header.size,sizeof(unsigned int),1,fptr) != 1) {
               fprintf(stderr,"Image read failed\n");
               return(-1);
            }

   fprintf(stderr,"File size is %d bytes\n",header.size);
   if (fread(&header.reserved1,sizeof(unsigned short),1,fptr) != 1) {
               fprintf(stderr,"Image read failed\n");
               return(-1);
            }

   if (fread(&header.reserved2,sizeof(unsigned short),1,fptr) != 1) {
               fprintf(stderr,"Image read failed\n");
               return(-1);
   }
   fprintf(stderr,"header.reserved1 = %d \n",header.reserved1);
   if (fread(&header.offset,sizeof(unsigned int),1,fptr) != 1) {
               fprintf(stderr,"Image read failed\n");
               return(-1);
    }
    fprintf(stderr,"header.reserved2 = %d \n",header.reserved2);
    fprintf(stderr,"Offset to image data is %d bytes\n",header.offset);

   /* Read and check the information header */
   if (fread(&infoheader,sizeof(INFOHEADER),1,fptr) != 1) {
      fprintf(stderr,"Failed to read BMP info header\n");
      return(-1);
   }
   fprintf(stderr,"Header size = %d \n",infoheader.size);
   fprintf(stderr,"Image size = %d x %d\n",infoheader.width,infoheader.height);
   fprintf(stderr,"Number of colour planes is %d\n",infoheader.planes);
   fprintf(stderr,"Bits per pixel is %d\n",infoheader.bits);
   fprintf(stderr,"Compression type is %d\n",infoheader.compression);
   fprintf(stderr,"Infoheader.imagesize is %d\n",infoheader.imagesize);
   fprintf(stderr,"Infoheader.xresolution=%d infoheader.yresolution=%d \n",infoheader.xresolution,infoheader.yresolution);
   fprintf(stderr,"Number of colours is %d\n",infoheader.ncolours);
   fprintf(stderr,"Number of required colours is %d\n",
      infoheader.importantcolours);

   /* WE CHECK THE 24 bits */
   if(infoheader.bits!=24){
	   fprintf(stderr,"Sorry, function only implemented for 24 bits colour format\n");
       return(-1);
   }
   /* WE CHECK COMPRESSION */
   if(infoheader.compression!=0){
	   fprintf(stderr,"Sorry, function only implemented image without compression \n");
       return(-1);
   }
   /* WE CHECK THE 24 bits */
   if(infoheader.ncolours!=0){
	   fprintf(stderr,"Sorry, function only implemented for 24 bits colour format\n");
       return(-1);
   }
   /* WE CHECK THE 24 bits */
   if(infoheader.importantcolours!=0){
	   fprintf(stderr,"Sorry, function only implemented for 24 bits colour format\n");
       return(-1);
   }


   /* WE FIT DIMENSIONS AND ALLOCATE MEMORY FOR THE IMAGE */
   *width=infoheader.width; *height=infoheader.height;
   size = (3*(*width) + (*width)%4)*(*height);
   //size=(*width)*(*height);
   *red=(unsigned char*) malloc(size*sizeof(unsigned char));
   *green=(unsigned char*) malloc(size*sizeof(unsigned char));
   *blue=(unsigned char*) malloc(size*sizeof(unsigned char));

  /* WE STORE THE IMAGE INFORMATION IN image */
   image=(unsigned char*)malloc(size*sizeof(unsigned char));

   /* We read the image */
   if (fread(image,size,1,fptr) != 1) {
     fprintf(stderr,"Image read failed\n");
     free(image);
     return(-1);
   }

   cont=0;
   for(i=0; i<(*height); i++){
     for(j=0; j<(*width); j++){
       (*blue)[i*(*width) + j]=image[cont++]; (*green)[i*(*width) + j]=image[cont++]; (*red)[i*(*width) + j]=image[cont++];
     }
     // Ignorar bytes rellenados con 0 para tamaño de fila múltiplo de 4 (considerando los 3 bytes RGB)
     cont+=(*width)%4;
   }

//   for(m=0;m<size;m++){ (*blue)[m]=image[cont]; (*green)[m]=image[cont+1]; (*red)[m]=image[cont+2]; cont+=3;}


   fclose(fptr);
   free(image);
   return(0);
}


/* FUNCTION TO WRITE A 24 bits COLOR BMP FORMAT IMAGE  (RETURN 0 IF FINISH PROPERLY -1 OTHERWISE) */
int ami_write_bmp(char name[200], unsigned char *red, unsigned char *green, unsigned char *blue, int width, int height)
{
   int i,j,k;
   //unsigned char r,g,b;
   HEADER header;
   INFOHEADER infoheader;
   FILE *fptr;
   long cont,size;
   unsigned char *image;

   /* Open file */
   if ((fptr = fopen(name,"wb")) == NULL) {
      fprintf(stderr,"Unable to open BMP file \"%s\"\n",name);
      return(-1);
   }

   /* Header Definition */
   header.type = (unsigned short int) 'M'*256+'B';
   header.size = (unsigned int) 3*width*height+54;
   header.reserved1 = 0;
   header.reserved2 = 0;
   header.offset = (unsigned int) 54;


  /* We write the header */
   if (fwrite(&header.type,sizeof(unsigned short),1,fptr) != 1) {
      fprintf(stderr,"Failed to write BMP info header\n");
      return(-1);
   }
   if (fwrite(&header.size,sizeof(unsigned int),1,fptr) != 1) {
      fprintf(stderr,"Failed to write BMP info header\n");
      return(-1);
   }
   if (fwrite(&header.reserved1,sizeof(unsigned short),1,fptr) != 1) {
      fprintf(stderr,"Failed to write BMP info header\n");
      return(-1);
   }
   if (fwrite(&header.reserved2,sizeof(unsigned short),1,fptr) != 1) {
      fprintf(stderr,"Failed to write BMP info header\n");
      return(-1);
   }
   if (fwrite(&header.offset,sizeof(unsigned int),1,fptr) != 1) {
      fprintf(stderr,"Failed to write BMP info header\n");
      return(-1);
   }


   /* INFOHEADER DEFINITION */
   infoheader.size = 40;
   infoheader.width = width;
   infoheader.height = height;
   infoheader.planes = (unsigned short int) 1;
   infoheader.bits = (unsigned short int) 24;
   infoheader.compression = (unsigned int) 0;
   infoheader.imagesize=(3*width + width%4)*height;//3*width*height;
   infoheader.xresolution=2834;
   infoheader.yresolution=2834;
   infoheader.ncolours = (unsigned int) 0 ;
   infoheader.importantcolours = (unsigned int) 0;



   /* We write the infoheaderinformation */
   if (fwrite(&infoheader,sizeof(INFOHEADER),1,fptr) != 1) {
      fprintf(stderr,"Failed to write BMP info header\n");
      return(-1);
   }

   size=(3*width + width%4)*height;//width*height;

   /* WE STORE THE IMAGE INFORMATION IN image */
   image=(unsigned char*)malloc(size*sizeof(unsigned char));
   //printf("size*3=%d\n",size*3);
   cont=0;
   for(i=0; i<height; i++){
     for(j=0; j<width; j++){
       image[cont++]=blue[i*width + j]; image[cont++]=green[i*width + j]; image[cont++]=red[i*width + j];
     }
     // Rellenar bytes con 0 para obtener tamaño de fila múltiplo de 4 (considerando los 3 bytes RGB)
     for(k=0; k<width%4; k++) image[cont++]=0;
   }
   //for(m=0;m<size;m++){ image[cont]=blue[m]; image[cont+1]=green[m]; image[cont+2]=red[m]; cont+=3;}

   /* We write the image */
  if (fwrite(image,size,1,fptr) != 1) {
     fprintf(stderr,"Image write failed\n");
     free(image);
     return(-1);
   }

   fclose(fptr);
   free(image);
   return(0);
}


/******************************************************************************************************************/
/* FUNCTION TO READ A 1024 X 1024 MSG IMAGE WITH 16 BITS DEPTH. WE USE AN UNSIGNED SHORT VECTOR TO KEEP THE IMAGE */
/******************************************************************************************************************/
//int ami_read_msg_1024_1024_16b_unsigned_short_v2(char name[200],unsigned short *image)
int ami_read_msg_16b_unsigned_short_v2(char name[200],unsigned short *image, int width, int height )
{
   int i;
   //int j,k;
   //   int width=1024;
   //   int height=1024;
   //long m, size=width*height;
   FILE *fptr;
   //int min,max;

   /* Open file */
   if ((fptr = fopen(name,"rb")) == NULL) {
      fprintf(stderr,"Unable to open tif file \"%s\"\n",name);
      return(-1);
   }

    //printf("WE READ THE IMAGE \n");
	/*for(i=0;i<height;i++){
        if (fread(&image[height-1-i],width*sizeof(unsigned short),1,fptr) != 1) {
             fprintf(stderr,"Image read failed\n");
             return(-1);
        }
    }*/

	//printf("WE READ THE IMAGE \n");
	for(i=0;i<height;i++){
        //if (fread(&image[(height-1-i)*width],width*sizeof(unsigned short),1,fptr) != 1) {
		if (fread(&image[i*width],width*sizeof(unsigned short),1,fptr) != 1) {
             fprintf(stderr,"Image read failed\n");
             return(-1);
        }
    }


   fclose(fptr);
   return(0);
}



/******************************************************************************************************************/
/* FUNCTION TO READ A 1024 X 1024 MSG IMAGE WITH 8 BITS DEPTH. WE USE AN UNSIGNED SHORT VECTOR TO KEEP THE IMAGE */
/******************************************************************************************************************/
//int ami_read_msg_1024_1024_8b_unsigned_char(char name[200],unsigned char **image)
int ami_read_msg_8b_unsigned_char(char name[200],unsigned char **image, int width, int height )
{
   int i;
   //int j,k;
   //int width=1024;
   //int height=1024;
   //long m,
   long size=width*height;
   FILE *fptr;
   unsigned char *image_p;
   //int min,max;

   /* Open file */
   if ((fptr = fopen(name,"rb")) == NULL) {
      fprintf(stderr,"Unable to open msg file \"%s\"\n",name);
      return(-1);
   }

   /* WE STORE THE IMAGE INFORMATION IN image */
   image_p=(unsigned char *)malloc(size*sizeof(unsigned char));

    //printf("WE READ THE IMAGE \n");
	for(i=0;i<height;i++){
        //if (fread(&image_p[(height-1-i)*width],width*sizeof(unsigned char),1,fptr) != 1) {
		if (fread(&image_p[i*width],width*sizeof(unsigned char),1,fptr) != 1) {
             fprintf(stderr,"Image read failed\n");
			 free(image_p);
             return(-1);
        }
    }


   *image=image_p;
   fclose(fptr);
   return(0);
}



/******************************************************************************************************************/
/* FUNCTION TO READ A 1024 X 1024 MSG IMAGE WITH 16 BITS DEPTH. WE USE AN UNSIGNED SHORT VECTOR TO KEEP THE IMAGE */
/******************************************************************************************************************/
//int ami_read_msg_1024_1024_16b_unsigned_short(char name[200],unsigned short **image)
int ami_read_msg_16b_unsigned_short(const char name[200],unsigned short **image, int width, int height )
{
   int i;
   //int j,k;
   //int width=1024;
   //int height=1024;
   //long m;
   long size=width*height;
   FILE *fptr;
   unsigned short *image_p;
   //int min,max;

   /* Open file */
   if ((fptr = fopen(name,"rb")) == NULL) {
      fprintf(stderr,"Unable to open tif file \"%s\"\n",name);
      return(-1);
   }

   /* WE STORE THE IMAGE INFORMATION IN image */
   image_p=(unsigned short *)malloc(size*sizeof(unsigned short));

   /* We read the header */
   //printf("WE READ THE HEADER INFORMATION \n");
/*   if (fread(image_p,186,1,fptr) != 1) {
     fprintf(stderr,"Image read failed\n");
     free(image_p);
     return(-1);
   } */

    //printf("WE READ THE IMAGE \n");
  /*  if (fread(image_p,size*sizeof(unsigned short),1,fptr) != 1) {
     fprintf(stderr,"Image read failed\n");
     free(image_p);
     return(-1);
   }*/

    //printf("WE READ THE IMAGE \n");
	for(i=0;i<height;i++){
        //if (fread(&image_p[(height-1-i)*width],width*sizeof(unsigned short),1,fptr) != 1) {
		if (fread(&image_p[i*width],width*sizeof(unsigned short),1,fptr) != 1) {
             fprintf(stderr,"Image read failed\n");
			 free(image_p);
             return(-1);
        }
    }


   *image=image_p;
   fclose(fptr);
   return(0);
}



/******************************************************************************************************************/
/* FUNCTION TO WRITE A 1024 X 1024 MSG IMAGE WITH 16 BITS DEPTH. WE USE AN UNSIGNED SHORT VECTOR TO KEEP THE IMAGE */
/******************************************************************************************************************/
//int ami_write_msg_1024_1024_16b_unsigned_short(char name[200],unsigned short *image)
int ami_write_msg_16b_unsigned_short(char name[200],unsigned short *image, int width, int height )
{
   //int i,j,k;
   //int width=1024;
   //int height=1024;
   //long m;
   long size=width*height;
   FILE *fptr;
   //int min,max;

   /* Open file */
   if ((fptr = fopen(name,"wb")) == NULL) {
      fprintf(stderr,"Unable to open file \"%s\"\n",name);
      return(-1);
   }

    if (fwrite(image,size*sizeof(unsigned short),1,fptr) != 1) {
     fprintf(stderr,"Image write failed\n");
     return(-1);
   }
   fclose(fptr);
   return(0);
}



/*****************************************************************************************************************/
/* FUNCTION TO READ 1024 X 1024 TIF (8 BITS) IMAGE AND RETURN IN A FLOAT POINTER
******************************************************************************************************************/
//int ami_read_tiff_1024_1024_8b_float(char name[200],float *image_output)
int ami_read_tiff_8b_float(const char name[200],float *image_output, int width, int height )
{
   int i;
   //int j,k;
   //int width=1024;
   //int height=1024;
   long m,size=width*height;
   FILE *fptr;
   unsigned char *image;
   //int min,max;

   /* WE ALLOCATE MEMORY */
   ami_malloc1d(image,unsigned char,size);

   /* Open file */
   if ((fptr = fopen(name,"rb")) == NULL) {
      fprintf(stderr,"Unable to open tif file \"%s\"\n",name);
      return(-1);
   }

    /* WE STORE THE IMAGE INFORMATION IN image */

   /* We read the header */
   //printf("WE READ THE HEADER INFORMATION \n");
//   if (fread(image,8,1,fptr) != 1) {
   if (fread(image,186,1,fptr) != 1) {     
     fprintf(stderr,"Image read failed\n");
     free(image);
     return(-1);
   }

    //printf("WE READ THE IMAGE \n");
 /*   if (fread(image,size*sizeof(unsigned char),1,fptr) != 1) {
     fprintf(stderr,"Image read failed\n");
     free(image);
     return(-1);
   }*/

     //printf("WE READ THE IMAGE \n");
	for(i=0;i<height;i++){
        //if (fread(&image[(height-1-i)*width],width*sizeof(unsigned char),1,fptr) != 1) {
		  if (fread(&image[(i)*width],width*sizeof(unsigned char),1,fptr) != 1) {
             fprintf(stderr,"Image read failed\n");
			 free(image);
             return(-1);
        }
    }


    /* WE COPY image IN image_output */
	for(m=0;m<size;m++)
    image_output[m]=image[m];

   free(image);
   fclose(fptr);

   return(0);
}


/******************************************************************************************************************/
/* FUNCTION TO READ A 1280 X 1024 TIF IMAGE WITH 16 BITS DEPTH. WE USE AN UNSIGNED SHORT VECTOR TO KEEP THE IMAGE */
/******************************************************************************************************************/
//int ami_read_tiff_1280_1024_16b_unsigned_short( char name[200],unsigned short **image)
int ami_read_tiff_16b_unsigned_short(const char name[200],unsigned short **image, int width, int height )
{
   int i;
   //int j,k;
   //int width=1280;
   //int height=1024;
   //long m;
   long size=width*height;
   FILE *fptr;
   unsigned short *image_p;
   //int min,max;

   /* Open file */
   if ((fptr = fopen(name,"rb")) == NULL) {
      fprintf(stderr,"Unable to open tif file \"%s\"\n",name);
      return(-1);
   }

    /* WE STORE THE IMAGE INFORMATION IN image */
   image_p=(unsigned short *)malloc(size*sizeof(unsigned short));

   /* We read the header */
   //printf("WE READ THE HEADER INFORMATION \n");
   if (fread(image_p,186,1,fptr) != 1) {
     fprintf(stderr,"Image read failed\n");
     free(image_p);
     return(-1);
   }

    //printf("WE READ THE IMAGE \n");
   /* if (fread(image_p,size*sizeof(unsigned short),1,fptr) != 1) {
     fprintf(stderr,"Image read failed\n");
     free(image_p);
     return(-1);
   }*/

    //printf("WE READ THE IMAGE \n");
	for(i=0;i<height;i++){
        //if (fread(&image_p[(height-1-i)*width],width*sizeof(unsigned short),1,fptr) != 1) {
		if (fread(&image_p[i*width],width*sizeof(unsigned short),1,fptr) != 1) {

             fprintf(stderr,"Image read failed\n");
			 free(image_p);
             return(-1);
        }
    }


   *image=image_p;
   fclose(fptr);
   return(0);
}


/************************************************************************************************************
  FUNCTION TO READ A 2D IMAGE IN THE TIF FORMAT OF MSG OR PIV AND IN 24 BIT BMP FORMAT
************************************************************************************************************/
int ami_read_image2d(const char name[200], /* name of the file in disk */
                 float ***image_output,/* address of the pointer to the float output image*/
				 int *width, /* width of the output image */
				 int *height, /* height of the output image */
				 int type) /* type = 0 : 1024x1024 8 bits tif PIV image
				              type = 1 : 1024x1024 16 bits tif MSG image
							  type = 2 : 1280x1024 16 bits tif PIV image
							  type = 3 : a bmp image */
{
  int i,j;
  long m,size;
  float **image;
  unsigned short *image_us;
  if(type==0){
	*width=1024;
	*height=1024;
	ami_malloc2d(image,float,*height,*width);
//    if(ami_read_tiff_1024_1024_8b_float(name,image[0])!=0){ ami_free2d(image); return(-1); }  
    if(ami_read_tiff_8b_float(name,image[0], *width, *height)!=0){ ami_free2d(image); return(-1); }
    *image_output=image;
	return(0);
  }
  else if(type==1){
	*width=1024;
	*height=1024;
//	if(ami_read_msg_1024_1024_16b_unsigned_short(name,&image_us)!=0){ return(-1); }  
	if(ami_read_msg_16b_unsigned_short(name,&image_us, *width, *height)!=0){ return(-1); }
    ami_malloc2d(image,float,*height,*width);
	size=(*width)*(*height);
    for(m=0;m<size;m++) image[0][m]=image_us[m];
    *image_output=image;
	free(image_us);
	return(0);
  }
  else if(type==2){
	*width=1280;
	*height=1024;
//	if(ami_read_tiff_1280_1024_16b_unsigned_short(name,&image_us)!=0){ return(-1); }
	if(ami_read_tiff_16b_unsigned_short(name,&image_us, *width, *height )!=0){ return(-1); }
    ami_malloc2d(image,float,*height,*width);
	size=(*width)*(*height);
    for(m=0;m<size;m++) image[0][m]=image_us[m];
    *image_output=image;
	free(image_us);
	return(0);
  }
  else if(type==3){
	unsigned char *red,*green,*blue;
    if( ami_read_bmp(name,&red,&green,&blue,width,height)!=0 ) return(-1);
	ami_malloc2d(image,float,*height,*width);
	size=(*width)*(*height);
    for(m=0;m<size;m++) image[0][m]=((float) red[m] + (float) green[m] + (float) blue[m])/3.  ;
    *image_output=image;
	return(0);
  }
  else if(type==4){
    /* Read a tiff file with:
       - 8 or 16 bits -> float
       - No compression
       - 0 = black or 0 = white
       - Order MSB2LSB
       - Planar config
    */
    int charOrShort = 0;
    float *tmpimage;

    if( read_tiff( name, &tmpimage, width, height, &charOrShort ) == -1 )    return(-1);
    ami_malloc2d(image,float,*height,*width);
    size=(*width)*(*height);

    for(i=0; i<*width;i++) {
       for(j=0; j<*height; j++) {
        image[j][i] = tmpimage[j*(*width)+i];
       }
    }
    
    /*//for(m=0;m<size;m++) image[0][m] = tmpimage[m];
    for(i=0; i<*height;i++) {
       for(j=0; j<*width; j++) {
        image[i][j] = tmpimage[i*(*width)+j];
       }
    }*/
    
    *image_output=image;
    free(tmpimage);
    printf("width: %d,  height: %d,  char: %d\n", *width, *height, charOrShort);


    return(0);

//    *width=2000;
//    *height=2000;
//    if(ami_read_tiff_16b_unsigned_short(name,&image_us, *width, *height )!=0){ return(-1); }
//	if(ami_read_tiff_2000_2000_16b_unsigned_short(name,&image_us)!=0){ return(-1); }
        //printf("Image read properly\n");
//	ami_malloc2d(image,float,*height,*width);
//	size=(*width)*(*height);
//        for(m=0;m<size;m++) image[0][m]=image_us[m];
//	*image_output=image;
//	free(image_us);
//	return(0);
  }
  return(-1);
}


/************************************************************************************************************
  FUNCTION TO READ A 2D IMAGE IN THE TIF FORMAT OF MSG OR PIV AND IN 24 BIT BMP FORMAT
************************************************************************************************************/
int ami_read_image2dv(const char name[200], /* name of the file in disk */
                 float *image_output,/* address of the pointer to the float output image*/
				 int width, /* width of the output image */
				 int height, /* height of the output image */
				 int type) /* type = 0 : 8 bits tif PIV image
				              type = 1 : 16 bits tif MSG image
							  type = 2 : 16 bits tif PIV image
							  type = 3 : a bmp image
							  type = 4 : a TIFF image (from library) */                
{
  //int i,j;
  long m;
  //long size;
  float *image;
  unsigned short *image_us;
  
  if(type==0) { // type = 0 : 8 bits tif PIV image
  
    if(ami_read_tiff_8b_float(name, image_output, width, height)!=0) { return(-1); }
    
    return(0);
    
  }  
  else if(type==1) {  // type = 1 : 16 bits tif MSG image

    if(ami_read_msg_16b_unsigned_short(name, &image_us, width, height)!=0) { return(-1); }

    for(m=0;m<width*height;m++) image_output[m] = (float) image_us[m];
    
    free(image_us);
    
    return(0);
    
  }
  else if(type==2) {  // type = 2 : 16 bits tif PIV image

    if(ami_read_tiff_16b_unsigned_short( name, &image_us, width, height )!=0) { return(-1); }

    for(m=0;m<width*height;m++) image_output[m] = (float) image_us[m];  
  
    free(image_us);
    
    return(0);
    
  }
  else if(type==3){ // type = 3 : a bmp image
  
    unsigned char *red,*green,*blue;
    
    if( ami_read_bmp( name, &red, &green, &blue, &width, &height)!=0 ) return(-1);

    for(m=0;m<width*height;m++) image_output[m] = ((float) red[m] + (float) green[m] + (float) blue[m])/3. ;

    return(0);

  }
  else if(type==4){ // type = 4 : a TIFF image (from library)

    /* Read a tiff file with:
       - 8 or 16 bits -> float
       - No compression
       - 0 = black or 0 = white
       - Order MSB2LSB
       - Planar config
    */
    int charOrShort = 0;

    if( read_tiff( name, &image, &width, &height, &charOrShort ) == -1 )    return(-1);

    for(m=0;m<width*height;m++) image_output[m] = image[m];

    printf("Width: %d,  height: %d,  char: %d\n", width, height, charOrShort);

    return(0);
  }

  return(-1);
}
