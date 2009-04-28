// la funcion es GrabaImagenTGA (name, data, width, height)
 /* los datos vienen RGB juntos por cada pixel */
 /* la imagen viene grabada de abajo hacia arriba */


#include "TGA.h"
#ifdef HAVE_MALLOC_H
  #include <malloc.h>
#else
  #include <stdlib.h>
#endif

/**************************************************************************************************/
BYTE escribir_tga (char *fichero, tga_attr *attr)
  {
    FILE *handle;
    BYTE *buffer;
    short dir;
    WORD scan, colum;
    DWORD space, index, cindex, pos;

    if ((handle = fopen (fichero,WRITE_MODE)) == NULL) return 1;
    attr->header.dummy01 = attr->header.dummy02 = 0;
    attr->header.control = 0x02;
    attr->header.dummy03 = attr->header.dummy04 = 0;
    attr->header.dummy05 = attr->header.dummy06 = 0;
    attr->header.dummy07 = attr->header.dummy08 = 0;
    attr->header.dummy09 = attr->header.dummy10 = 0;
    attr->header.dummy11 = 0;
    attr->header.coc_ancho = attr->ancho / 256;
    attr->header.mod_ancho = attr->ancho % 256;
    attr->header.coc_alto  = attr->alto / 256;
    attr->header.mod_alto  = attr->alto % 256;
    attr->header.bits_pixel = 0x18;
    if (fwrite (&attr->header, sizeof (tga_cabecera), 1, handle) != 1) return 2;
    space = (DWORD) attr->ancho * (DWORD) attr->alto;
    buffer = (BYTE *) malloc (space * 3);
    if (buffer == NULL) return 3;
    if (((attr->header.top_down / 0x20) % 2) == 0) {
      index = space - attr->ancho; dir = -attr->ancho;
    }
    else {
      index = 0; dir = attr->ancho;
    }

    for (scan = 0, pos = 0; scan < attr->alto; scan++, index += dir)
      for (colum = 0, cindex = index; colum < attr->ancho; colum++, cindex++) {
	buffer [pos++] = attr->blue [cindex];
	buffer [pos++] = attr->green [cindex];
	buffer [pos++] = attr->red [cindex];
      }
    if (fwrite (buffer, space, 3, handle) != 3) return 2;
    free (buffer);
    fclose (handle);
    return 0;
  }

/**************************************************************************************************/


void GrabaImagenTGA(char *name, unsigned char *data,
		    int width, int height,
		    int mode)
{
 /* los datos vienen RGB juntos por cada pixel */
 /* la imagen viene grabada de abajo hacia arriba */
 /* mode puede ser MODE_GRIS o MODE_RGB */

 unsigned char *datacols[3];
 tga_attr attr;
 int i, j, n=0, size=width*height;

 for (i=0;i<3;i++) datacols[i] = (unsigned char *) malloc (size);
 for (j=height-1; j>=0; j--) for (i=0; i<width; i++) {

   if (mode==MODE_GRIS) {
     datacols[0][j*width+i] = data[n];
     datacols[1][j*width+i] = data[n];
     datacols[2][j*width+i] = data[n];
     n++;
   }
   else
   if (mode==MODE_RGB) {
     datacols[0][j*width+i] = data[n];  n++;
     datacols[1][j*width+i] = data[n];  n++;
     datacols[2][j*width+i] = data[n];  n++;
   }

 }

 attr.ancho = width;
 attr.alto = height;
 attr.red = datacols[0];
 attr.green = datacols[1];
 attr.blue = datacols[2];
 escribir_tga (name, &attr);

 for (i=0;i<3;i++) free(datacols[i]);
}
