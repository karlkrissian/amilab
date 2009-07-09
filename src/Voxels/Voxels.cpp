/***********************************************************/
/***********************************************************
Este fichero va a incluir las funciones OpenGL que llamara Karl
desde su ventana. Se va a compilar en una libreria aparte llamada
libVoxels.so

***********************************************************/

/*** Estas instrucciones OpenGL deberian estar activadas antes
de llamar a la funcion PintaVoxels:

 glEnable (GL_COLOR_MATERIAL);
 glColorMaterial (GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
 glEnable(GL_CULL_FACE);
 glCullFace(GL_BACK);

     Para llamar a la funcion PintaSeccionVoxels es igual pero
cambiando glEnable(GL_CULL_FACE) por glDisable

******************************************************/

#ifdef WIN32
  #include <windows.h>
#endif

#include <GL/gl.h>
#include <GL/glext.h>

//extern "C" {
#ifndef WIN32
#include <GL/glx.h>
//extern void glBlendEquation (GLenum);
#endif
//}


#include <stdio.h>

#include "Voxels.h"

#define RANGO3D       100     // el cubo de voxels se encuentra entre -100 y 100
        // OJO: tambien esta definido en OGL.c

#define LIMIT_MIP_QUADS 300000

/***********************************************************/

void PintaSeccionVoxels (InrImage* im,
       char seccion, short a,
       float mincol, float maxcol,
       ParamZoom zoom)
/* Voy a pintar una secci� del cubo de voxels, segn el valor de secci�.
   Si secci�=1 -> Es el plano XY, secci� Z=a.
   Si secci�=2 -> Es el plano XZ, secci� Y=a.
   Si secci�=3 -> Es el plano YZ, secci� X=a. */
{

#define COLOR(c) \
 ((c<mincol)?0:((c>maxcol)?255:(255*(c-mincol)/(maxcol-mincol)) ) )

  // GLfloat c;
 long i,j,k;
 // long pos;
 GLubyte col;
 // long x,y,z;
 long maxn;

 short nx = im->DimX();
 short ny = im->DimY();
 short nz = im->DimZ();

 float vs[3] = { im->VoxSizeX(), im->VoxSizeY(), im->VoxSizeZ() };

 // long nxy=(long)nx*ny;

 float tr_x =  im->TrX();
 float tr_y =  im->TrY();
 float tr_z =  im->TrZ();

 printf("tr = %f %f %f \n",tr_x,tr_y,tr_z);

 // inicializacion de parametros de OpenGL
 glEnable (GL_COLOR_MATERIAL);
 glColorMaterial (GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
 glDisable(GL_CULL_FACE);
 glCullFace(GL_BACK);

 // si la seccion se pasa de rango acabamos
 if ((seccion==1) && (a>=nz)) return;
 if ((seccion==2) && (a>=ny)) return;
 if ((seccion==3) && (a>=nx)) return;

 // buscamos la dimension maxima, para saber el tama� de voxel
 maxn = nx;
 if (ny>maxn) maxn = ny;
 if (nz>maxn) maxn = nz;

 // Inicializamos el dibujo de cuadrados
 // glPushMatrix();
 // glTranslatef (-RANGO3D*(float)nx/maxn, -RANGO3D*(float)ny/maxn, -RANGO3D*(float)nz/maxn);
 glBegin (GL_QUADS);

 switch (seccion) {
    case 1: // Pintamos la imagen XY
        for (j=zoom._ymin; j<=zoom._ymax; j++)
    for (i=zoom._xmin; i<zoom._xmax; i++) {
            col = (GLubyte) COLOR((*im)(i,j,a));
      glColor3ub(col,col,col);
            glNormal3f(0,0,1);
            glVertex3f(vs[0]*(i-0.5)+tr_x, vs[1]*(j-0.5)+tr_y, vs[2]*(a)+tr_z);
            glVertex3f(vs[0]*(i+0.5)+tr_x, vs[1]*(j-0.5)+tr_y, vs[2]*(a)+tr_z);
            glVertex3f(vs[0]*(i+0.5)+tr_x, vs[1]*(j+0.5)+tr_y, vs[2]*(a)+tr_z);
            glVertex3f(vs[0]*(i-0.5)+tr_x, vs[1]*(j+0.5)+tr_y, vs[2]*(a)+tr_z);
         }
        break;

    case 2: // Pintamos la imagen XZ
        for (k=zoom._zmin; k<zoom._zmax; k++)
    for (i=zoom._xmin; i<zoom._xmax; i++) {
            col = (GLubyte) COLOR((*im)(i,a,k));
      glColor3ub(col,col,col);
            glNormal3f(0,1,0);
            glVertex3f(vs[0]*(i-0.5)+tr_x, vs[1]*(a)+tr_y, vs[2]*(k-0.5)+tr_z);
            glVertex3f(vs[0]*(i-0.5)+tr_x, vs[1]*(a)+tr_y, vs[2]*(k+0.5)+tr_z);
            glVertex3f(vs[0]*(i+0.5)+tr_x, vs[1]*(a)+tr_y, vs[2]*(k+0.5)+tr_z);
            glVertex3f(vs[0]*(i+0.5)+tr_x, vs[1]*(a)+tr_y, vs[2]*(k-0.5)+tr_z);
         }
        break;

    case 3: // Pintamos la imagen YZ
        for (k=zoom._zmin; k<zoom._zmax; k++)
    for (j=zoom._ymin; j<zoom._ymax; j++) {
            col = (GLubyte) COLOR((*im)(a,j,k));
      glColor3ub(col,col,col);
            glNormal3f(1,0,0);
            glVertex3f(vs[0]*(a)+tr_x, vs[1]*(j-0.5)+tr_y, vs[2]*(k+0.5)+tr_z);
            glVertex3f(vs[0]*(a)+tr_x, vs[1]*(j-0.5)+tr_y, vs[2]*(k-0.5)+tr_z);
            glVertex3f(vs[0]*(a)+tr_x, vs[1]*(j+0.5)+tr_y, vs[2]*(k-0.5)+tr_z);
            glVertex3f(vs[0]*(a)+tr_x, vs[1]*(j+0.5)+tr_y, vs[2]*(k+0.5)+tr_z);
         }
        break;
  }

 // acabo con los cuadrados
 glEnd();
 // glPopMatrix();
}

/***********************************************************/

long PintaVoxels (InrImage* im,
    float umb1, float umb2, float mincol, float maxcol)
/* Voy a pintar todo el cubo de voxels. Para ello voy a hacerlo de 3 tandas.
Se supone que el voxel (0,0,0) es la esquina trasera inferior izquierda.
La z crece hacia m� la x hacia la derecha, y la y hacia arriba.
Primero, trabajando con la pared xz, voy mirando cuando entro en el umbral,
y esa cara se dibuja de frente. Ahora sabemos que estamos dentro del objeto
y no pinto nada. Si me vuelvo a salir del umbral, esa cara se pinta de
espalda. Y as�para los tres planos principales.
El color con el que pinto es una interpolacion:
  col<=mincol   0
  mincol<=col<=maxcol entre 0 y 255
  maxcol<=col   255.
El tama� de cada voxel viene dado por las variables (vx,vy,vz).*/
{
 long num=0;
 long i, j, k, pos;
 char dentro=0; // 0 si estoy fuera del s�ido. 1 si estoy dentro
 GLubyte col;
 float colf;
 float difcol = maxcol-mincol;
 short nx = im->DimX();
 short ny = im->DimY();
 short nz = im->DimZ();

 float vx=im->VoxSizeX();
 float vy=im->VoxSizeY();
 float vz=im->VoxSizeZ();

 long nxy=(long)nx*ny;

 float tr_x =  im->TrX();
 float tr_y =  im->TrY();
 float tr_z =  im->TrZ();

 //printf ("PintaVoxels");
 //printf ("Umbrales=(%.2f,%.2f). ", umb1, umb2);
 //printf ("Colores=(%.2f,%.2f). ", mincol, maxcol);
 //printf ("Tam.Voxels=(%.2f,%.2f,%.2f)\n",vx,vy,vz);

 // inicializacion de parametros de OpenGL
 glEnable (GL_COLOR_MATERIAL);
 glColorMaterial (GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
 glEnable (GL_CULL_FACE);
 glCullFace(GL_BACK);

 // Inicializamos el dibujo de cuadrados
 glBegin (GL_QUADS);

 // Plano XY
 for (j=0; j<ny; j++) for (i=0; i<nx; i++) {
    dentro = 0;
    for (k=nz-1; k>=0; k--) {
        pos = k*nxy + j*nx + i;  // me pongo al comienzo de la recta {y=j;x=i}
        colf = (*im)(i,j,k);
  if (colf<=mincol) col=0; else
  if (colf>=maxcol) col=255; else
  col = (GLubyte)((colf-mincol)/difcol*255);

        // si estando fuera me encuentro un voxel dentro del umbral,
        // pinto esa cara de frente
        if ((!dentro) && (colf>=umb1) && (colf<=umb2)) {
            glColor3ub(col,col,col);
            glNormal3f(0,0,1);
            glVertex3f( vx*(i-0.5)+tr_x,
                        vy*(j-0.5)+tr_y,
                        vz*(k+0.5)+tr_z);
            glVertex3f(vx*(i+0.5)+tr_x, vy*(j-0.5)+tr_y, vz*(k+0.5)+tr_z);
            glVertex3f(vx*(i+0.5)+tr_x, vy*(j+0.5)+tr_y, vz*(k+0.5)+tr_z);
            glVertex3f(vx*(i-0.5)+tr_x, vy*(j+0.5)+tr_y, vz*(k+0.5)+tr_z);
            dentro = 1; // estoy dentro del s�ido
            num++;
         }

        // si estando dentro me encuentro un voxel fuera del umbral,
        // pinto esa cara de espalda
        if ((dentro) && ((colf<umb1) || (colf>umb2))) {
            pos+= nxy;  // uso el color del voxel anterior
            colf = (*im)(i,j,k+1);
      if (colf<=mincol) col=0; else
      if (colf>=maxcol) col=255; else
      col = (GLubyte)((colf-mincol)/difcol*255);
            glColor3ub(col,col,col);
            glNormal3f(0,0,-1);
            glVertex3f(vx*(i-0.5)+tr_x, vy*(j-0.5)+tr_y, vz*(k+0.5)+tr_z);
            glVertex3f(vx*(i-0.5)+tr_x, vy*(j+0.5)+tr_y, vz*(k+0.5)+tr_z);
            glVertex3f(vx*(i+0.5)+tr_x, vy*(j+0.5)+tr_y, vz*(k+0.5)+tr_z);
            glVertex3f(vx*(i+0.5)+tr_x, vy*(j-0.5)+tr_y, vz*(k+0.5)+tr_z);
            dentro = 0; // estoy dentro del s�ido
            num++;
         }
     }

     // si llego al final estando dentro tengo que pintar el final
     if (dentro) {
        glColor3ub(col,col,col);
        glNormal3f(0,0,-1);
        glVertex3f(vx*(i-0.5)+tr_x, vy*(j-0.5)+tr_y, vz*(-0.5)+tr_z);
        glVertex3f(vx*(i-0.5)+tr_x, vy*(j+0.5)+tr_y, vz*(-0.5)+tr_z);
        glVertex3f(vx*(i+0.5)+tr_x, vy*(j+0.5)+tr_y, vz*(-0.5)+tr_z);
        glVertex3f(vx*(i+0.5)+tr_x, vy*(j-0.5)+tr_y, vz*(-0.5)+tr_z);
        num++;
      }
  }

 // Plano YZ
 for (k=0; k<nz; k++) for (j=0; j<ny; j++) {
    dentro = 0;
    for (i=nx-1; i>=0; i--) {
        pos = k*nxy + j*nx + i;  // me pongo al comienzo de la recta {y=j;z=k}
        colf = (*im)(i,j,k);
  if (colf<=mincol) col=0; else
  if (colf>=maxcol) col=255; else
  col = (GLubyte)((colf-mincol)/difcol*255);

        // si estando fuera me encuentro un voxel por debajo del umbral,
        // pinto esa cara de frente
        if ((!dentro) && (colf>=umb1) && (colf<=umb2)) {
            glColor3ub(col,col,col);
            glNormal3f(1,0,0);
            glVertex3f(vx*(i+0.5)+tr_x, vy*(j-0.5)+tr_y, vz*(k+0.5)+tr_z);
            glVertex3f(vx*(i+0.5)+tr_x, vy*(j-0.5)+tr_y, vz*(k-0.5)+tr_z);
            glVertex3f(vx*(i+0.5)+tr_x, vy*(j+0.5)+tr_y, vz*(k-0.5)+tr_z);
            glVertex3f(vx*(i+0.5)+tr_x, vy*(j+0.5)+tr_y, vz*(k+0.5)+tr_z);
            dentro = 1; // estoy dentro del s�ido
            num++;
         }

        // si estando dentro me encuentro un voxel que supera el umbral,
        // pinto esa cara de espalda
        if ((dentro) && ((colf<umb1) || (colf>umb2))) {
            pos+= 1;  // uso el color del voxel anterior
            colf = (*im)(i+1,j,k);
      if (colf<=mincol) col=0; else
      if (colf>=maxcol) col=255; else
      col = (GLubyte)((colf-mincol)/difcol*255);
            glColor3ub(col,col,col);
            glNormal3f(-1,0,0);
            glVertex3f(vx*(i+0.5)+tr_x, vy*(j-0.5)+tr_y, vz*(k+0.5)+tr_z);
            glVertex3f(vx*(i+0.5)+tr_x, vy*(j+0.5)+tr_y, vz*(k+0.5)+tr_z);
            glVertex3f(vx*(i+0.5)+tr_x, vy*(j+0.5)+tr_y, vz*(k-0.5)+tr_z);
            glVertex3f(vx*(i+0.5)+tr_x, vy*(j-0.5)+tr_y, vz*(k-0.5)+tr_z);
            dentro = 0; // estoy dentro del s�ido
            num++;
         }
     }

     // si llego al final estando dentro tengo que pintar el final
     if (dentro) {
        glColor3ub(col,col,col);
        glNormal3f(-1,0,0);
        glVertex3f(vx*(-0.5)+tr_x, vy*(j-0.5)+tr_y, vz*(k+0.5)+tr_z);
        glVertex3f(vx*(-0.5)+tr_x, vy*(j+0.5)+tr_y, vz*(k+0.5)+tr_z);
        glVertex3f(vx*(-0.5)+tr_x, vy*(j+0.5)+tr_y, vz*(k-0.5)+tr_z);
        glVertex3f(vx*(-0.5)+tr_x, vy*(j-0.5)+tr_y, vz*(k-0.5)+tr_z);
        num++;
      }
  }

 // Plano XZ
 for (k=0; k<nz; k++) for (i=0; i<nx; i++) {
    dentro = 0;
    for (j=ny-1; j>=0; j--) {
        pos = k*nxy + j*nx + i;  // me pongo al comienzo de la recta {y=j;z=k}
        colf = (*im)(i,j,k);
  if (colf<=mincol) col=0; else
  if (colf>=maxcol) col=255; else
  col = (GLubyte)((colf-mincol)/difcol*255);

        // si estando fuera me encuentro un voxel por debajo del umbral,
        // pinto esa cara de frente
        if ((!dentro) && (colf>=umb1) && (colf<=umb2)) {
            glColor3ub(col,col,col);
            glNormal3f(0,1,0);
            glVertex3f(vx*(i-0.5)+tr_x, vy*(j+0.5)+tr_y, vz*(k-0.5)+tr_z);
            glVertex3f(vx*(i-0.5)+tr_x, vy*(j+0.5)+tr_y, vz*(k+0.5)+tr_z);
            glVertex3f(vx*(i+0.5)+tr_x, vy*(j+0.5)+tr_y, vz*(k+0.5)+tr_z);
            glVertex3f(vx*(i+0.5)+tr_x, vy*(j+0.5)+tr_y, vz*(k-0.5)+tr_z);
            dentro = 1; // estoy dentro del s�ido
            num++;
         }

        // si estando dentro me encuentro un voxel que supera el umbral,
        // pinto esa cara de espalda
        if ((dentro) && ((colf<umb1) || (colf>umb2))) {
            pos+= nx;  // uso el color del voxel anterior
            colf = (*im)(i,j+1,k);
      if (colf<=mincol) col=0; else
      if (colf>=maxcol) col=255; else
      col = (GLubyte)((colf-mincol)/difcol*255);
            glColor3ub(col,col,col);
            glNormal3f(0,-1,0);
            glVertex3f(vx*(i-0.5)+tr_x, vy*(j+0.5)+tr_y, vz*(k-0.5)+tr_z);
            glVertex3f(vx*(i+0.5)+tr_x, vy*(j+0.5)+tr_y, vz*(k-0.5)+tr_z);
            glVertex3f(vx*(i+0.5)+tr_x, vy*(j+0.5)+tr_y, vz*(k+0.5)+tr_z);
            glVertex3f(vx*(i-0.5)+tr_x, vy*(j+0.5)+tr_y, vz*(k+0.5)+tr_z);
            dentro = 0; // estoy dentro del s�ido
            num++;
         }
     }

     // si llego al final estando dentro tengo que pintar el final
     if (dentro) {
        glColor3ub(col,col,col);
        glNormal3f(0,-1,0);
        glVertex3f(vx*(i-0.5)+tr_x, vy*(-0.5)+tr_y, vz*(k-0.5)+tr_z);
        glVertex3f(vx*(i+0.5)+tr_x, vy*(-0.5)+tr_y, vz*(k-0.5)+tr_z);
        glVertex3f(vx*(i+0.5)+tr_x, vy*(-0.5)+tr_y, vz*(k+0.5)+tr_z);
        glVertex3f(vx*(i-0.5)+tr_x, vy*(-0.5)+tr_y, vz*(k+0.5)+tr_z);
        num++;
      }
  }

 // acabo con los cuadrados
 glEnd();
 glDisable (GL_COLOR_MATERIAL);
 return (num);
}



GLubyte ColorImage(float I, float minI, float maxI)
{
  if (I<=minI) return 0;
  if (I>=maxI) return 255;
  return (GLubyte)((I-minI)/(maxI-minI)*255);
}

/***********************************************************/

void CreateMIP(InrImage::ptr im,
         float minTh, float maxTh,
         float minI, float maxI,
         int max_quads,
               bool full)
//
// Creates OpenGL MIPS
//
// im is the image
// minTh and maxTh are the min and max thresholds
// minI and maxI are the linear intensity mapping
// vx,vy,vz is the voxel size in X,Y,Z
//

{
  long   x,  y,   z;
  float xs,  ys,  zs;
// float vsxh,vsyh,vszh;
  GLubyte col,col1,col2,col3,col4;
  float I;
  int nb_quads;
  InrImage::ptr Colors;
  InrImage::ptr DrawCubes;

  int   dx, dy,dz;
  float dvx, dvy,dvz;

  Colors = InrImage::ptr ( new InrImage ( WT_UNSIGNED_CHAR,"Colors.ami.gz",im.get() ) );
  Colors->InitImage ( 0 );
  Colors->InitBuffer();
  im->InitBuffer();
  Repeter
  I = im->ValeurBuffer();
  Si I>=minTh Et I<=maxTh AlorsFait
  Colors->FixeValeur ( ColorImage ( I,minI,maxI ) );
  im->IncBuffer();
  JusquA Non ( Colors->IncBuffer() ) FinRepeter

  DrawCubes = InrImage::ptr( new InrImage(WT_UNSIGNED_CHAR,"CreateMIP_DrawCubes.ami.gz",im.get()));
  DrawCubes->InitImage(0);
  // TODO: finish filling DrawCubes

  glEnable ( GL_BLEND );
  glDisable ( GL_DEPTH_TEST );
  glBlendFunc ( GL_ONE, GL_ONE );
// glBlendEquation(GL_MAX_EXT);
  #ifndef WIN32
    #if (defined(GL_EXT_texture3D))&&(!defined(__APPLE__))
      //PFNGLBLENDEQUATIONPROC glBlendEquation;
      //glBlendEquation = (PFNGLBLENDEQUATIONPROC) glXGetProcAddress((const GLubyte*)"glBlendEquation");
      glBlendEquation ( GL_MAX );
    #else
      glBlendEquation ( GL_MAX );
    #endif
  #else
    PFNGLBLENDEQUATIONPROC glBlendEquation;
    glBlendEquation = (PFNGLBLENDEQUATIONPROC) wglGetProcAddress("glBlendEquation");
    glBlendEquation ( GL_MAX );
  #endif

  glDisable ( GL_LIGHTING );
  glDisable ( GL_CULL_FACE );
//glEnable( GL_CULL_FACE);


// Inicializamos el dibujo de cuadrados
  glBegin ( GL_QUADS );

  /*
   vsxh = 0.5*im->VoxSizeX();
   vsyh = 0.5*im->VoxSizeY();
   vszh = 0.5*im->VoxSizeZ();
  */

  dx = 1;
  dy = 1;
  dz = 1;
  dvx = dx*im->VoxSizeX();
  dvy = dy*im->VoxSizeY();
  dvz = dz*im->VoxSizeZ();

  nb_quads = 0;

// Plano XY
  for ( z=0;z<=im->_tz-1;z+=dz )
  {
    zs=im->SpacePosZ ( z );
    for ( y=0;y<=im->_ty-1;y+=dy )
    {
      ys=im->SpacePosY ( y );
      for ( x=0;x<=im->_tx-1;x+=dx )
      {
        xs=im->SpacePosX ( x );

        // Draw a face if any point within the 2 touching cubes
        // is positive

        if ( nb_quads<max_quads*100000 )
        {
          col = ( GLubyte ) ( *Colors ) ( x,y,z );
          // Essayer glColor4f(r,g,b,alpha)
          // z constant
          if ((x<im->DimX()-1)&&(y<im->DimY()-1)) {
          col1 = col;
          col2 = ( GLubyte ) ( *Colors ) ( x+dx,y,  z );
          col3 = ( GLubyte ) ( *Colors ) ( x+dx,y+dy,z );
          col4 = ( GLubyte ) ( *Colors ) ( x,   y+dy,z );

          Si col1>0 Ou col2>0 Ou col3>0 Ou col4>0 Alors
            glColor3ub ( col1,col1,col1 );
            glVertex3f ( xs,    ys,    zs );
            glColor3ub ( col2,col2,col2 );
            glVertex3f ( xs+dvx, ys,    zs );
            glColor3ub ( col3,col3,col3 );
            glVertex3f ( xs+dvx, ys+dvy, zs );
            glColor3ub ( col4,col4,col4 );
            glVertex3f ( xs,    ys+dvy, zs );
            nb_quads++;
            if ( ( nb_quads % 10000 ) ==0 )
              printf ( "nb points treated %d \n",nb_quads );
            }
          }

          // y constant
          if ((x<im->DimX()-1)&&(z<im->DimZ()-1)) {
          col1 = col;
          col2 = ( GLubyte ) ( *Colors ) ( x+dx,y,z );
          col3 = ( GLubyte ) ( *Colors ) ( x+dx,y,z+dz );
          col4 = ( GLubyte ) ( *Colors ) ( x,  y,z+dz );

          Si col1>0 Ou col2>0 Ou col3>0 Ou col4>0 Alors
            glColor3ub ( col1,col1,col1 );
            glVertex3f ( xs,    ys,    zs );
            glColor3ub ( col2,col2,col2 );
            glVertex3f ( xs+dvx, ys,    zs );
            glColor3ub ( col3,col3,col3 );
            glVertex3f ( xs+dvx, ys, zs+dvz );
            glColor3ub ( col4,col4,col4 );
            glVertex3f ( xs,    ys, zs+dvz );
            nb_quads++;
            if ( ( nb_quads % 10000 ) ==0 )
              printf ( "nb points treated %d \n",nb_quads );
          FinSi
          }

          // x constant
          if ((y<im->DimY()-1)&&(z<im->DimZ()-1)) {
          col1 = col;
          col2 = ( GLubyte ) ( *Colors ) ( x,y+dy,z );
          col3 = ( GLubyte ) ( *Colors ) ( x,y+dy,z+dz );
          col4 = ( GLubyte ) ( *Colors ) ( x,y,  z+dz );

          Si col1>0 Ou col2>0 Ou col3>0 Ou col4>0 Alors
            glColor3ub ( col1, col1,  col1 );
            glVertex3f ( xs,   ys,    zs );
            glColor3ub ( col2, col2,  col2 );
            glVertex3f ( xs,   ys+dvy, zs );
            glColor3ub ( col3, col3,  col3 );
            glVertex3f ( xs,   ys+dvy, zs+dvz );
            glColor3ub ( col4, col4,  col4 );
            glVertex3f ( xs,   ys,    zs+dvz );
            nb_quads++;
            if ( ( nb_quads % 10000 ) ==0 )
              printf ( "nb points treated %d \n",nb_quads );
          FinSi
          }

        } // less than maximum

      } // for x
    } // for y
  } // for z

// End
  glEnd();

  glDisable ( GL_BLEND );
  glEnable ( GL_DEPTH_TEST );
  glEnable ( GL_LIGHTING );
  glEnable ( GL_CULL_FACE );


}

