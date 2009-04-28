
#ifndef _VOXELS_H_
#define _VOXELS_H_

#include "DessinImageParam.hpp"
#include "inrimage.hpp"

void PintaSeccionVoxels (InrImage* im, 
			 char seccion, short a,
			 float mincol, float maxcol,
			 ParamZoom zoom);
/* Voy a pintar una secci� del cubo de voxels, segn el valor de secci�.
   Si secci�=1 -> Es el plano XY, secci� Z=a.
   Si secci�=2 -> Es el plano XZ, secci� Y=a.
   Si secci�=3 -> Es el plano YZ, secci� X=a.*/


long PintaVoxels (InrImage* im, 
		float umb1, float umb2, float mincol, float maxcol);
/* Voy a pintar todo el cubo de voxels. Para ello voy a hacerlo de 3 tandas.
Se supone que el voxel (0,0,0) es la esquina trasera inferior izquierda.
La z crece hacia m� la x hacia la derecha, y la y hacia arriba.
Primero, trabajando con la pared xz, voy mirando cuando entro en el umbral,
y esa cara se dibuja de frente. Ahora sabemos que estamos dentro del objeto
y no pinto nada. Si me vuelvo a salir del umbral, esa cara se pinta de
espalda. Y as�para los tres planos principales. 
El color con el que pinto es una interpolacion:
	col<=mincol		0
	mincol<=col<=maxcol	entre 0 y 255
	maxcol<=col		255.
El tama� de cada voxel viene dado por las variables (vx,vy,vz).*/

void CreateMIP( InrImage::ptr im, 
                float minTh, float maxTh,
                float minI, float maxI, 
                int max_quads,
                bool full=true);
//
// Creates OpenGL MIPS
//
// im is the image
// minTh and maxTh are the min and max thresholds
// minI and maxI are the linear intensity mapping
// vx,vy,vz is the voxel size in X,Y,Z


#endif // _VOXELS_H_
