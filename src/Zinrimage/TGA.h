
#ifndef _ESCRIBE_TGA_HPP_
#define _ESCRIBE_TGA_HPP_


#include <stdio.h>

// la funcion es GrabaImagenTGA (name, data, width, height)
 /* los datos vienen RGB juntos por cada pixel */
 /* la imagen viene grabada de abajo hacia arriba */

/*****************************************************************/

#define BYTE unsigned char
#define WORD  unsigned short
#define DWORD unsigned int
#define READ_MODE  "r"
#define WRITE_MODE "w"

#define MODE_GRIS 1
#define MODE_RGB  2

typedef struct {
	  BYTE dummy01, dummy02;
	  BYTE control;
	  BYTE dummy03, dummy04, dummy05;
	  BYTE dummy06, dummy07, dummy08;
	  BYTE dummy09, dummy10, dummy11;
	  BYTE mod_ancho, coc_ancho;
	  BYTE mod_alto, coc_alto;
	  BYTE bits_pixel;
	  BYTE top_down;
	} tga_cabecera;

typedef struct {
	  tga_cabecera header;
	  WORD  ancho, alto;
	  BYTE *red, *green, *blue;
	} tga_attr;

/**************************************************************************************************/
BYTE escribir_tga (char *fichero, tga_attr *attr);

/**************************************************************************************************/

void GrabaImagenTGA (char *name, unsigned char *data, int width, int height, int mode);
 /* los datos vienen RGB juntos por cada pixel */
 /* la imagen viene grabada de abajo hacia arriba */


#endif // _ESCRIBE_TGA_HPP_
