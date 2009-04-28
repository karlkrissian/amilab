
#ifndef _AMI_TYPES_H_
#define _AMI_TYPES_H_

/*******************************************/
/* DECLARACION DE ESTRUCTURAS               */
/*******************************************/

typedef struct{float x,y;}ami_punto2d;

/* INFORMACION NECESARIA SOBRE UNA CAMARA (REDUNDANTE) */
typedef struct{
   double P[3][4];     /* Matriz de Proyeccion Normalizada =(R,t) */
   double u0,v0,au,av; /* Parametros  Intrinsecos*/
   double R[3][3];     /* Matriz de Rotacion */
   double t[3];        /* vector de traslacion */
   double x[4];        /* vector (s,l,m,n) asociado a la matriz de rotacion */
   double P_1[3][3];   /* inversa de P[3][3] Normalizada */
   double F[3][3];     /* matriz fundamental de una imagen a la siguiente */
}camara;

/* INFORMACION NECESARIA SOBRE PUNTOS PARA CALIBRAR */
typedef struct{
   int NC;       /* Numero de Camaras desde donde es visible el punto */
   int *C;       /* Indices de las Camaras desde donde es visible el punto */
   double *mx;      /* Coordenada normalizada mx del punto en la Camara C[i] */
   double *my;      /* Coordenada normalizada my del punto en la Camara C[i] */
}puntocalibracion;

typedef double p3D[3];
typedef int ami_window[4]; /* LOCAL WINDOW BOUNDS ami_window[0]=min_radius_x ami_window[1]=max_radius_x ami_window[2]=min_radius_y ami_window[3]=max_radius_y */

	 /* START OF PROTOTYPES OLD ami_bmp.h */
typedef struct {
   unsigned short int type;                 /* Magic identifier            */
   unsigned int size;                       /* File size in bytes          */
   unsigned short int reserved1, reserved2;
   unsigned int offset;                     /* Offset to image data, bytes */
} HEADER;

typedef struct {
   unsigned int size;               /* Header size in bytes      */
   int width,height;                /* Width and height of image */
   unsigned short int planes;       /* Number of colour planes   */
   unsigned short int bits;         /* Bits per pixel            */
   unsigned int compression;        /* Compression type          */
   unsigned int imagesize;          /* Image size in bytes       */
   int xresolution,yresolution;     /* Pixels per meter          */
   unsigned int ncolours;           /* Number of colours         */
   unsigned int importantcolours;   /* Important colours         */
} INFOHEADER;

typedef float ami_v3f[3];

#endif // _AMI_TYPES_H_
