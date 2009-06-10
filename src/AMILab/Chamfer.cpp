/*
    ==================================================
    Software : AMILab
    Authors  : Karl Krissian
    Email    : karl@bwh.harvard.edu

    AMILab is a language for image processing
    ==================================================
    Copyright (C) 1996-2005  Karl Krissian

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

    ================================================== 
   The full GNU Lesser General Public License file is in Devel/Sources/Prog/LesserGPL_license.txt
*/

//#include "fonctions.h"
#include "inrimage.hpp"
#include "math1.hpp"
//#include "paramlist.h"

//#include "Variable.hpp"
//#include "Variables.hpp"
#include "FloatMatrix.hpp"
#include "Timing.hpp"
#include "Chamfer.h"

//
// Computes a Chamfer distance transform
//
InrImage* Func_Chamfer(InrImage* im, float a, float b, float c)
{
  register int x,y,z,i,n;
  register int j,k;
  InrImage* res;
  register int   neighbor[13];
  register float dist_neighbor[13];
  register float min,val=0;
  register float* buf;
  Timing duree;

  duree.Debut();

  res = new InrImage(WT_FLOAT,"Chamfer.ami.gz",im);

  fprintf(stderr,"Func_Chamfer() \t initialization() \n");

  i = 0;
  Pour(z,-1,1)
  Pour(y,-1,1)
  Pour(x,-1,1)
    Si i>12 AlorsFait break;
    n = abs(x)+abs(y)+abs(z);
    neighbor[i]      = (z*im->_ty+y)*im->_tx + x;
    SelonQue n Vaut
      Valeur 1: dist_neighbor[i] = a; FinValeur
      Valeur 2: dist_neighbor[i] = b; FinValeur
      Valeur 3: dist_neighbor[i] = c; FinValeur
      Defaut: fprintf(stderr,"Chamfer error \n");
    FinSelonQue
    i++;
  FinPour
  FinPour
  FinPour

  (*res) = (*im);

  // First pass


  fprintf(stderr,"Func_Chamfer() \t first pass \n");

  for(z=1;z<im->_tz-1;z++)
    for(y=1;y<im->_ty-1;y++) {
      res->BufferPos(1,y,z);
      buf = (float*) res->BufferPtr();
      for(x=1;x<im->_tx-1;x++) {

	// check the minimum
	min = *buf;
	Pour(i,0,12)
	  val = *(buf+neighbor[i])+dist_neighbor[i];
          Si val<min AlorsFait min = val;
	FinPour

        *buf = min;
	buf++;
      }
    }


  // Second pass
  fprintf(stderr,"Func_Chamfer() \t second pass \n");

  for(z=im->_tz-2;z>0;z--)
    for(y=im->_ty-2;y>0;y--) {
      res->BufferPos(im->_tx-2,y,z);
      buf = (float*) res->BufferPtr();
      for(x=im->_tx-2;x>0;x--) {

	// check the minimum
        min = *buf;
	Pour(i,0,12)
	  val = *(buf-neighbor[i])+dist_neighbor[i];
          Si val<min AlorsFait min = val;
	FinPour

	*buf = min;
	buf--;
      }
    }


  fprintf(stderr,"Func_Chamfer() \t borders \n");

  // Compute the borders
  for(z=0;z<=im->_tz-1;z++) 
    for(y=0;y<=im->_ty-1;y++)
      for(x=0;x<=im->_tx-1;x++) 
	if ((x==0)||(x==im->_tx-1)||
            (y==0)||(y==im->_ty-1)||
            (z==0)||(z==im->_tz-1)) {

	  min = (*res)(x,y,z);
	  Pour(i,-1,1)
	  Pour(j,-1,1)
	  Pour(k,-1,1)
            Si res->CoordOK(x+i,y+j,z+k) Alors
              n = abs(i)+abs(j)+abs(k);
    	      Si n==0 AlorsFait continue;
              SelonQue n Vaut
                Valeur 1: val = (*res)(x+i,y+j,z+k)+a; FinValeur
                Valeur 2: val = (*res)(x+i,y+j,z+k)+b; FinValeur
                Valeur 3: val = (*res)(x+i,y+j,z+k)+c; FinValeur
                Defaut: fprintf(stderr,"Chamfer error \n");
              FinSelonQue
              Si val<min AlorsFait min = val;
            FinSi
          FinPour
          FinPour
          FinPour

	if ((x==127)&&(y==84)&&(z==36)) 
	  fprintf(stderr,"(127,84,36) min %f \n",min);

	  res->BufferPos(x,y,z);
	  res->FixeValeur(min);
	  
	}

  duree.Fin();
  

  cout << duree << endl;

  return res;
  
} // void Chamfer()


//
// Computes a Chamfer distance transform
// Other (faster?) implementation
//
InrImage* Func_Chamfer2(InrImage* im, float a, float b, float c, float dmax)
{
  register int x,y,z,i,n;
  register int j,k;
  int i1,i2,i3;
  InrImage* res;
  register int   neighbor[13];
  register float dist_neighbor[13];
  register int neighbor1[3];
  register int neighbor2[6];
  register int neighbor3[4];
  register float min,val=0;
  register float* buf;
  register float* buf1;
  register float* buf2;
  register float* buf3;
  register int imin,imax,jmin,jmax,kmin,kmax;
  register int tx,ty,tz,txy;
  Timing duree;

  if (im->DimZ()==1) return Func_Chamfer2_2D(im,a,b,dmax);

  duree.Debut();

  res = new InrImage(WT_FLOAT,"Chamfer2.ami.gz",im);

  fprintf(stderr,"Func_Chamfer() \t initialization() \n");

  tx  = im->DimX();
  ty  = im->DimY();
  tz  = im->DimZ();
  txy = tx*ty;

  i = 0;
  i1 = i2 = i3 = 0;
  Pour(z,-1,1)
  Pour(y,-1,1)
  Pour(x,-1,1)
    Si i>12 AlorsFait break;
    n = abs(x)+abs(y)+abs(z);
    neighbor[i]      = (z*ty+y)*tx + x;
    SelonQue n Vaut
      Valeur 1: 
        dist_neighbor[i] = a; 
        neighbor1[i1] = neighbor[i];
        i1++;
      FinValeur
      Valeur 2: 
        dist_neighbor[i] = b; 
        neighbor2[i2] = neighbor[i];
        i2++;
      FinValeur
      Valeur 3: 
        dist_neighbor[i] = c; 
        neighbor3[i3] = neighbor[i];
        i3++;
      FinValeur
      Defaut: fprintf(stderr,"Chamfer error \n");
    FinSelonQue
    i++;
  FinPour
  FinPour
  FinPour

  // I could avoid this ?
  Si im->_format==WT_FLOAT Alors
    // memcopy
    buf  = (float*) res->Buffer();
    buf1 = (float*) im->Buffer();
    memcpy(buf,buf1,txy*tz*4);
  Sinon
    im->InitBuffer();
    buf = (float*) res->Buffer();
    Repeter
      *buf = im->ValeurBuffer();
      buf++;
    JusquA Non(im->IncBuffer()) FinRepeter
  FinSi

  // First pass

  fprintf(stderr,"Func_Chamfer() \t first pass \n");

  for(z=1;z<tz-1;z++)
    for(y=1;y<ty-1;y++) {
      res->BufferPos(1,y,z);
      buf = (float*) res->BufferPtr();
      for(x=1;x<tx-1;x++) {

        if (*buf<dmax) {
	  // C6 neighbors
	  val = *buf+a;
	  
	  buf1 = buf-neighbor1[0]; if (val < *buf1) *buf1 = val;
	  buf1 = buf-neighbor1[1]; if (val < *buf1) *buf1 = val;
	  buf1 = buf-neighbor1[2]; if (val < *buf1) *buf1 = val;
	  
	  // C18 neighbors
	  val = *buf+b;
	  
	  buf1 = buf-neighbor2[0]; if (val < *buf1) *buf1 = val;
	  buf1 = buf-neighbor2[1]; if (val < *buf1) *buf1 = val;
	  buf1 = buf-neighbor2[2]; if (val < *buf1) *buf1 = val;
	  buf1 = buf-neighbor2[3]; if (val < *buf1) *buf1 = val;
	  buf1 = buf-neighbor2[4]; if (val < *buf1) *buf1 = val;
	  buf1 = buf-neighbor2[5]; if (val < *buf1) *buf1 = val;
	  
	  // C26 neighbors
	  val = *buf+c;
	  
	  buf1 = buf-neighbor3[0]; if (val < *buf1) *buf1 = val;
	  buf1 = buf-neighbor3[1]; if (val < *buf1) *buf1 = val;
	  buf1 = buf-neighbor3[2]; if (val < *buf1) *buf1 = val;
	  buf1 = buf-neighbor3[3]; if (val < *buf1) *buf1 = val;
	}

	buf++;
      }
    }

  // Second pass
  fprintf(stderr,"Func_Chamfer() \t second pass \n");

  for(z=tz-2;z>0;z--)
    for(y=ty-2;y>0;y--) {
      res->BufferPos(tx-2,y,z);
      buf = (float*) res->BufferPtr();
      for(x=tx-2;x>0;x--) {

        if (*buf<dmax) {

	  // C6 neighbors
	  val = *buf+a;
	  
	  buf1 = buf+neighbor1[0]; if (val < *buf1) *buf1 = val;
	  buf1 = buf+neighbor1[1]; if (val < *buf1) *buf1 = val;
	  buf1 = buf+neighbor1[2]; if (val < *buf1) *buf1 = val;
	  
	  // C18 neighbors
	  val = *buf+b;
	  
	  buf1 = buf+neighbor2[0]; if (val < *buf1) *buf1 = val;
	  buf1 = buf+neighbor2[1]; if (val < *buf1) *buf1 = val;
	  buf1 = buf+neighbor2[2]; if (val < *buf1) *buf1 = val;
	  buf1 = buf+neighbor2[3]; if (val < *buf1) *buf1 = val;
	  buf1 = buf+neighbor2[4]; if (val < *buf1) *buf1 = val;
	  buf1 = buf+neighbor2[5]; if (val < *buf1) *buf1 = val;
	  
	  // C26 neighbors
	  val = *buf+c;
	  
	  buf1 = buf+neighbor3[0]; if (val < *buf1) *buf1 = val;
	  buf1 = buf+neighbor3[1]; if (val < *buf1) *buf1 = val;
	  buf1 = buf+neighbor3[2]; if (val < *buf1) *buf1 = val;
	  buf1 = buf+neighbor3[3]; if (val < *buf1) *buf1 = val;
	}

	buf--;
      }
    }

  duree.Fin();
  cout << duree << endl;

  fprintf(stderr,"Func_Chamfer() \t borders \n");


  buf = (float*) res->Buffer();

  // Compute the borders: too slow, and not really correct ...
  // should compute 6 2D distances for each face ...
  for(z=0;z<=tz-1;z++) 
    for(y=0;y<=ty-1;y++)
      for(x=0;x<=tx-1;x++) {
	if ((x==0)||(x==tx-1)||
            (y==0)||(y==ty-1)||
            (z==0)||(z==tz-1)) {

	  min =*buf;

	  if (x==0) imin = 0; else imin = -1;
	  if (y==0) jmin = 0; else jmin = -1;
	  if (z==0) kmin = 0; else kmin = -1;

	  if (x==tx-1) imax = 0; else imax = 1;
	  if (y==ty-1) jmax = 0; else jmax = 1;
	  if (z==tz-1) kmax = 0; else kmax = 1;

	  buf1 = buf + imin;
	  Pour(i,imin,imax)
  	    buf2 = buf1;
  	    if (jmin==-1) buf2 -= tx;
  	    Pour(j,jmin,jmax)
  	      buf3 = buf2;
  	      if (kmin==-1) buf3 -= txy;
	      Pour(k,kmin,kmax)
                n = abs(i)+abs(j)+abs(k);
                SelonQue n Vaut
		  Valeur 0: continue;
                  Valeur 1: val = *buf3+a; FinValeur
                  Valeur 2: val = *buf3+b; FinValeur
                  Valeur 3: val = *buf3+c; FinValeur
                  Defaut: fprintf(stderr,"Chamfer error \n");
                FinSelonQue
                Si val<min AlorsFait min = val;
                buf3 += txy;
              FinPour
	      buf2 += tx;
            FinPour
	    buf1++;
          FinPour


	  *buf = min;
	  buf++;
	  
	}
        else

	  // jump directly to the last voxel of the line
	  if (x==1) {
	    x   += tx-3;
	    buf += tx-3;
	    buf++;
	  }
	  else {
	    fprintf(stderr,"Chamfer2() \t we should not get here !!! \n");

	    buf++;

	  }

      }


  return res;
  
} // void Chamfer2()

/* should I use this kind of function ???
 *
inline void update_neighbors_pos(float* buf1, float val,
				 float a, float b, float c,
				 int neighbor1[3],
				 int neighbor2[6],
				 int neighbor3[4]
				 )
{
  register float* buf1;
  register float  val;

  // C6 neighbors
  val = *buf+a;
  
  buf1 = buf-neighbor1[0]; if (val < *buf1) *buf1 = val;
  buf1 = buf-neighbor1[1]; if (val < *buf1) *buf1 = val;
  buf1 = buf-neighbor1[2]; if (val < *buf1) *buf1 = val;
	  
  // C18 neighbors
  val = *buf+b;
  
  buf1 = buf-neighbor2[0]; if (val < *buf1) *buf1 = val;
  buf1 = buf-neighbor2[1]; if (val < *buf1) *buf1 = val;
  buf1 = buf-neighbor2[2]; if (val < *buf1) *buf1 = val;
  buf1 = buf-neighbor2[3]; if (val < *buf1) *buf1 = val;
  buf1 = buf-neighbor2[4]; if (val < *buf1) *buf1 = val;
  buf1 = buf-neighbor2[5]; if (val < *buf1) *buf1 = val;
  
  // C26 neighbors
  val = *buf+c;
  
  buf1 = buf-neighbor3[0]; if (val < *buf1) *buf1 = val;
  buf1 = buf-neighbor3[1]; if (val < *buf1) *buf1 = val;
  buf1 = buf-neighbor3[2]; if (val < *buf1) *buf1 = val;
  buf1 = buf-neighbor3[3]; if (val < *buf1) *buf1 = val;

} // update_neighbors()
*/


//
// Computes a Chamfer distance transform
// Other (faster?) implementation
//
InrImage* Func_Chamfer2Signed(InrImage* im, float a, float b, float c, float dmax)
{
  register int x,y,z,i,n;
  register int j,k;
  int i1,i2,i3;
  InrImage* res;
  register int   neighbor[13];
  register float dist_neighbor[13];
  register int neighbor1[3];
  register int neighbor2[6];
  register int neighbor3[4];
  register float min,val=0;
  register float* buf;
  register float* buf1;
  register float* buf2;
  register float* buf3;
  register int imin,imax,jmin,jmax,kmin,kmax;
  register int tx,ty,tz,txy;
  Timing duree;

  if (im->DimZ()==1) return Func_Chamfer2Signed_2D(im,a,b,dmax);

  duree.Debut();

  res = new InrImage(WT_FLOAT,"Chamfer2.ami.gz",im);

  fprintf(stderr,"Func_Chamfer() \t initialization() \n");

  tx  = im->DimX();
  ty  = im->DimY();
  tz  = im->DimZ();
  txy = tx*ty;

  i = 0;
  i1 = i2 = i3 = 0;
  Pour(z,-1,1)
  Pour(y,-1,1)
  Pour(x,-1,1)
    Si i>12 AlorsFait break;
    n = abs(x)+abs(y)+abs(z);
    neighbor[i]      = (z*ty+y)*tx + x;
    SelonQue n Vaut
      Valeur 1: 
        dist_neighbor[i] = a; 
        neighbor1[i1] = neighbor[i];
        i1++;
      FinValeur
      Valeur 2: 
        dist_neighbor[i] = b; 
        neighbor2[i2] = neighbor[i];
        i2++;
      FinValeur
      Valeur 3: 
        dist_neighbor[i] = c; 
        neighbor3[i3] = neighbor[i];
        i3++;
      FinValeur
      Defaut: fprintf(stderr,"Chamfer error \n");
    FinSelonQue
    i++;
  FinPour
  FinPour
  FinPour

  // 
  Si im->_format==WT_FLOAT Alors
    // memcopy
    buf  = (float*) res->Buffer();
    buf1 = (float*) im->Buffer();
    memcpy(buf,buf1,txy*tz*4);
  Sinon
    im->InitBuffer();
    buf = (float*) res->Buffer();
    Repeter
      *buf = im->ValeurBuffer();
      buf++;
    JusquA Non(im->IncBuffer()) FinRepeter
  FinSi

  // First pass

  fprintf(stderr,"Func_Chamfer() \t first pass \n");

  for(z=1;z<tz-1;z++)
    for(y=1;y<ty-1;y++) {
      res->BufferPos(1,y,z);
      buf = (float*) res->BufferPtr();
      for(x=1;x<tx-1;x++) {

	if (*buf> dmax) { buf++; continue; }
	if (*buf<-dmax) { buf++; continue; }

	if (*buf>-a) {
	  // C6 neighbors
	  val = *buf+a;
	  
	  buf1 = buf-neighbor1[0]; if (val < *buf1) *buf1 = val;
	  buf1 = buf-neighbor1[1]; if (val < *buf1) *buf1 = val;
	  buf1 = buf-neighbor1[2]; if (val < *buf1) *buf1 = val;
	  
	  // C18 neighbors
	  val = *buf+b;
	  
	  buf1 = buf-neighbor2[0]; if (val < *buf1) *buf1 = val;
	  buf1 = buf-neighbor2[1]; if (val < *buf1) *buf1 = val;
	  buf1 = buf-neighbor2[2]; if (val < *buf1) *buf1 = val;
	  buf1 = buf-neighbor2[3]; if (val < *buf1) *buf1 = val;
	  buf1 = buf-neighbor2[4]; if (val < *buf1) *buf1 = val;
	  buf1 = buf-neighbor2[5]; if (val < *buf1) *buf1 = val;
	  
	  // C26 neighbors
	  val = *buf+c;
	  
	  buf1 = buf-neighbor3[0]; if (val < *buf1) *buf1 = val;
	  buf1 = buf-neighbor3[1]; if (val < *buf1) *buf1 = val;
	  buf1 = buf-neighbor3[2]; if (val < *buf1) *buf1 = val;
	  buf1 = buf-neighbor3[3]; if (val < *buf1) *buf1 = val;
	}
	if (*buf<a) {
	  // C6 neighbors
	  val = *buf-a;
	  
	  buf1 = buf-neighbor1[0]; if (val > *buf1) *buf1 = val;
	  buf1 = buf-neighbor1[1]; if (val > *buf1) *buf1 = val;
	  buf1 = buf-neighbor1[2]; if (val > *buf1) *buf1 = val;
	  
	  // C18 neighbors
	  val = *buf-b;
	  
	  buf1 = buf-neighbor2[0]; if (val > *buf1) *buf1 = val;
	  buf1 = buf-neighbor2[1]; if (val > *buf1) *buf1 = val;
	  buf1 = buf-neighbor2[2]; if (val > *buf1) *buf1 = val;
	  buf1 = buf-neighbor2[3]; if (val > *buf1) *buf1 = val;
	  buf1 = buf-neighbor2[4]; if (val > *buf1) *buf1 = val;
	  buf1 = buf-neighbor2[5]; if (val > *buf1) *buf1 = val;
	  
	  // C26 neighbors
	  val = *buf-c;
	  
	  buf1 = buf-neighbor3[0]; if (val > *buf1) *buf1 = val;
	  buf1 = buf-neighbor3[1]; if (val > *buf1) *buf1 = val;
	  buf1 = buf-neighbor3[2]; if (val > *buf1) *buf1 = val;
	  buf1 = buf-neighbor3[3]; if (val > *buf1) *buf1 = val;
	}
	buf++;
      }
    }

  // Second pass
  fprintf(stderr,"Func_Chamfer() \t second pass \n");

  for(z=tz-2;z>0;z--)
    for(y=ty-2;y>0;y--) {
      res->BufferPos(tx-2,y,z);
      buf = (float*) res->BufferPtr();
      for(x=tx-2;x>0;x--) {

	if (*buf> dmax) { buf--; continue; }
	if (*buf<-dmax) { buf--; continue; }

        if (*buf>-a) {

	  // C6 neighbors
	  val = *buf+a;
	  
	  buf1 = buf+neighbor1[0]; if (val < *buf1) *buf1 = val;
	  buf1 = buf+neighbor1[1]; if (val < *buf1) *buf1 = val;
	  buf1 = buf+neighbor1[2]; if (val < *buf1) *buf1 = val;
	  
	  // C18 neighbors
	  val = *buf+b;
	  
	  buf1 = buf+neighbor2[0]; if (val < *buf1) *buf1 = val;
	  buf1 = buf+neighbor2[1]; if (val < *buf1) *buf1 = val;
	  buf1 = buf+neighbor2[2]; if (val < *buf1) *buf1 = val;
	  buf1 = buf+neighbor2[3]; if (val < *buf1) *buf1 = val;
	  buf1 = buf+neighbor2[4]; if (val < *buf1) *buf1 = val;
	  buf1 = buf+neighbor2[5]; if (val < *buf1) *buf1 = val;
	  
	  // C26 neighbors
	  val = *buf+c;
	  
	  buf1 = buf+neighbor3[0]; if (val < *buf1) *buf1 = val;
	  buf1 = buf+neighbor3[1]; if (val < *buf1) *buf1 = val;
	  buf1 = buf+neighbor3[2]; if (val < *buf1) *buf1 = val;
	  buf1 = buf+neighbor3[3]; if (val < *buf1) *buf1 = val;
	}
        if (*buf<a) {

	  // C6 neighbors
	  val = *buf-a;
	  
	  buf1 = buf+neighbor1[0]; if (val > *buf1) *buf1 = val;
	  buf1 = buf+neighbor1[1]; if (val > *buf1) *buf1 = val;
	  buf1 = buf+neighbor1[2]; if (val > *buf1) *buf1 = val;
	  
	  // C18 neighbors
	  val = *buf-b;
	  
	  buf1 = buf+neighbor2[0]; if (val > *buf1) *buf1 = val;
	  buf1 = buf+neighbor2[1]; if (val > *buf1) *buf1 = val;
	  buf1 = buf+neighbor2[2]; if (val > *buf1) *buf1 = val;
	  buf1 = buf+neighbor2[3]; if (val > *buf1) *buf1 = val;
	  buf1 = buf+neighbor2[4]; if (val > *buf1) *buf1 = val;
	  buf1 = buf+neighbor2[5]; if (val > *buf1) *buf1 = val;
	  
	  // C26 neighbors
	  val = *buf-c;
	  
	  buf1 = buf+neighbor3[0]; if (val > *buf1) *buf1 = val;
	  buf1 = buf+neighbor3[1]; if (val > *buf1) *buf1 = val;
	  buf1 = buf+neighbor3[2]; if (val > *buf1) *buf1 = val;
	  buf1 = buf+neighbor3[3]; if (val > *buf1) *buf1 = val;
	}

	buf--;
      }
    }

  duree.Fin();
  cout << duree << endl;

  fprintf(stderr,"Func_Chamfer() \t borders \n");


  buf = (float*) res->Buffer();

  // Compute the borders: too slow, and not really correct ...
  // should compute 6 2D distances for each face ...
  for(z=0;z<=tz-1;z++) 
    for(y=0;y<=ty-1;y++)
      for(x=0;x<=tx-1;x++) {
	if ((x==0)||(x==tx-1)||
            (y==0)||(y==ty-1)||
            (z==0)||(z==tz-1)) {

	  min =*buf;

	  if (x==0) imin = 0; else imin = -1;
	  if (y==0) jmin = 0; else jmin = -1;
	  if (z==0) kmin = 0; else kmin = -1;

	  if (x==tx-1) imax = 0; else imax = 1;
	  if (y==ty-1) jmax = 0; else jmax = 1;
	  if (z==tz-1) kmax = 0; else kmax = 1;

	  buf1 = buf + imin;
	  Pour(i,imin,imax)
  	    buf2 = buf1;
  	    if (jmin==-1) buf2 -= tx;
  	    Pour(j,jmin,jmax)
  	      buf3 = buf2;
  	      if (kmin==-1) buf3 -= txy;
	      Pour(k,kmin,kmax)
                n = abs(i)+abs(j)+abs(k);
                SelonQue n Vaut
		  Valeur 0: continue;
                  Valeur 1: val = *buf3+a; FinValeur
                  Valeur 2: val = *buf3+b; FinValeur
                  Valeur 3: val = *buf3+c; FinValeur
                  Defaut: fprintf(stderr,"Chamfer error \n");
                FinSelonQue
                Si val<min AlorsFait min = val;
                buf3 += txy;
              FinPour
	      buf2 += tx;
            FinPour
	    buf1++;
          FinPour


	  *buf = min;
	  buf++;
	  
	}
        else

	  // jump directly to the last voxel of the line
	  if (x==1) {
	    x   += tx-3;
	    buf += tx-3;
	    buf++;
	  }
	  else {
	    fprintf(stderr,"Chamfer2() \t we should not get here !!! \n");

	    buf++;

	  }

      }


  return res;
  
} // void Chamfer2Signed()


//
// Computes a Chamfer distance transform
// Other (faster?) implementation
//
InrImage* Func_Chamfer2_2D(InrImage* im, float a, float b, float dmax)
{
  register int x,y,i,n;
  register int j;
  int i1,i2;
  InrImage* res;
  register int   neighbor[4];
  register float dist_neighbor[4];
  register int neighbor1[2];
  register int neighbor2[2];
  register float min,val=0;
  register float* buf;
  register float* buf1;
  register int imin,imax,jmin,jmax; //,kmin,kmax;
  //  register int x1,y1,z1;


  res = new InrImage(WT_FLOAT,"Chamfer2.ami.gz",im);


  i = 0;
  i1 = i2 = 0;

  Pour(y,-1,1)
  Pour(x,-1,1)
    Si i>3 AlorsFait break;
    n = abs(x)+abs(y);
    neighbor[i]      = y*im->_tx + x;
    SelonQue n Vaut
      Valeur 1: 
        dist_neighbor[i] = a; 
        neighbor1[i1] = neighbor[i];
        i1++;
      FinValeur
      Valeur 2: 
        dist_neighbor[i] = b; 
        neighbor2[i2] = neighbor[i];
        i2++;
      FinValeur
      Defaut: fprintf(stderr,"Func_Chamfer2_2D() \t Chamfer error n = %d (%d,%d)\n",n,x,y);
    FinSelonQue
    i++;
  FinPour
  FinPour

  // I could avoid this ?
  (*res) = (*im);

  // First pass


  for(y=1;y<im->_ty-1;y++) {
    res->BufferPos(1,y);
    buf = (float*) res->BufferPtr();
    for(x=1;x<im->_tx-1;x++) {
      
      if (*buf<dmax) {
	// C4 neighbors
	val = *buf+a;
	buf1 = buf-neighbor1[0]; if (val < *buf1) *buf1 = val;
	buf1 = buf-neighbor1[1]; if (val < *buf1) *buf1 = val;
	
	// C8 neighbors
	val = *buf+b;
	buf1 = buf-neighbor2[0]; if (val < *buf1) *buf1 = val;
	buf1 = buf-neighbor2[1]; if (val < *buf1) *buf1 = val;
      }
	
      buf++;
    }
  }

  // Second pass

  for(y=im->_ty-2;y>0;y--) {
    res->BufferPos(im->_tx-2,y);
    buf = (float*) res->BufferPtr();
    for(x=im->_tx-2;x>0;x--) {

      if (*buf<dmax) {
	// C4 neighbors
	val = *buf+a;
	buf1 = buf+neighbor1[0]; if (val < *buf1) *buf1 = val;
	buf1 = buf+neighbor1[1]; if (val < *buf1) *buf1 = val;
	
	// C8 neighbors
	val = *buf+b;
	buf1 = buf+neighbor2[0]; if (val < *buf1) *buf1 = val;
	buf1 = buf+neighbor2[1]; if (val < *buf1) *buf1 = val;
      }

      buf--;
    }
  }


  buf = (float*) res->Buffer();

  // Compute the borders
  for(y=0;y<=im->_ty-1;y++)
    for(x=0;x<=im->_tx-1;x++) {
      if ((x==0)||(x==im->_tx-1)||
	  (y==0)||(y==im->_ty-1)){
	
	if (x==0) imin = 0; else imin = -1;
	if (y==0) jmin = 0; else jmin = -1;
	
	if (x==im->_tx-1) imax = 0; else imax = 1;
	if (y==im->_ty-1) jmax = 0; else jmax = 1;
          

	min = *buf;

	Pour(i,imin,imax)
	Pour(j,jmin,jmax)
	  n = abs(i)+abs(j);
	  Si n==0 AlorsFait continue;
	  SelonQue n Vaut
                Valeur 1: val = (*res)(x+i,y+j)+a; FinValeur
                Valeur 2: val = (*res)(x+i,y+j)+b; FinValeur
                Defaut: fprintf(stderr,"Func_Chamfer2_2D() \t Chamfer error (%d,%d) \n",x,y);
          FinSelonQue
          Si val<min AlorsFait min = val;
        FinPour
        FinPour

	res->BufferPos(x,y);
	res->FixeValeur(min);
	  
      }

      buf++;
    }  

  return res;
  
} // void Func_Chamfer2_2D()


//
// Computes a Chamfer distance transform
// Other (faster?) implementation
//
InrImage* Func_Chamfer2Signed_2D(InrImage* im, float a, float b, float dmax)
{
  register int x,y,i,n;
  register int j;
  int i1,i2;
  InrImage* res;
  register int   neighbor[4];
  register float dist_neighbor[4];
  register int neighbor1[2];
  register int neighbor2[2];
  register float min,val=0;
  register float* buf;
  register float* buf1;
  register int imin,imax,jmin,jmax; //,kmin,kmax;
  //  register int x1,y1,z1;


  res = new InrImage(WT_FLOAT,"Chamfer2.ami.gz",im);


  i = 0;
  i1 = i2 = 0;

  Pour(y,-1,1)
  Pour(x,-1,1)
    Si i>3 AlorsFait break;
    n = abs(x)+abs(y);
    neighbor[i]      = y*im->_tx + x;
    SelonQue n Vaut
      Valeur 1: 
        dist_neighbor[i] = a; 
        neighbor1[i1] = neighbor[i];
        i1++;
      FinValeur
      Valeur 2: 
        dist_neighbor[i] = b; 
        neighbor2[i2] = neighbor[i];
        i2++;
      FinValeur
      Defaut: fprintf(stderr,"Func_Chamfer2_2D() \t Chamfer error n = %d (%d,%d)\n",n,x,y);
    FinSelonQue
    i++;
  FinPour
  FinPour

  // I could avoid this ?
  (*res) = (*im);

  // First pass


  for(y=1;y<im->_ty-1;y++) {
    res->BufferPos(1,y);
    buf = (float*) res->BufferPtr();
    for(x=1;x<im->_tx-1;x++) {
      
      if (*buf> dmax) { buf++; continue; }
      if (*buf<-dmax) { buf++; continue; }

      if (*buf>-a) {
	// C4 neighbors
	val = *buf+a;
	buf1 = buf-neighbor1[0]; if (val < *buf1) *buf1 = val;
	buf1 = buf-neighbor1[1]; if (val < *buf1) *buf1 = val;
	
	// C8 neighbors
	val = *buf+b;
	buf1 = buf-neighbor2[0]; if (val < *buf1) *buf1 = val;
	buf1 = buf-neighbor2[1]; if (val < *buf1) *buf1 = val;
      }
      if (*buf<a) {
	// C4 neighbors
	val = *buf-a;
	buf1 = buf-neighbor1[0]; if (val > *buf1) *buf1 = val;
	buf1 = buf-neighbor1[1]; if (val > *buf1) *buf1 = val;
	
	// C8 neighbors
	val = *buf-b;
	buf1 = buf-neighbor2[0]; if (val > *buf1) *buf1 = val;
	buf1 = buf-neighbor2[1]; if (val > *buf1) *buf1 = val;
      }
	
      buf++;
    }
  }

  // Second pass

  for(y=im->_ty-2;y>0;y--) {
    res->BufferPos(im->_tx-2,y);
    buf = (float*) res->BufferPtr();
    for(x=im->_tx-2;x>0;x--) {

      if (*buf> dmax) { buf--; continue; }
      if (*buf<-dmax) { buf--; continue; }

      if (*buf>-a) {
	// C4 neighbors
	val = *buf+a;
	buf1 = buf+neighbor1[0]; if (val < *buf1) *buf1 = val;
	buf1 = buf+neighbor1[1]; if (val < *buf1) *buf1 = val;
	
	// C8 neighbors
	val = *buf+b;
	buf1 = buf+neighbor2[0]; if (val < *buf1) *buf1 = val;
	buf1 = buf+neighbor2[1]; if (val < *buf1) *buf1 = val;
      }
      if (*buf<a) {
	// C4 neighbors
	val = *buf-a;
	buf1 = buf+neighbor1[0]; if (val > *buf1) *buf1 = val;
	buf1 = buf+neighbor1[1]; if (val > *buf1) *buf1 = val;
	
	// C8 neighbors
	val = *buf-b;
	buf1 = buf+neighbor2[0]; if (val > *buf1) *buf1 = val;
	buf1 = buf+neighbor2[1]; if (val > *buf1) *buf1 = val;
      }

      buf--;
    }
  }


  buf = (float*) res->Buffer();

  // Compute the borders
  for(y=0;y<=im->_ty-1;y++)
    for(x=0;x<=im->_tx-1;x++) {
      if ((x==0)||(x==im->_tx-1)||
	  (y==0)||(y==im->_ty-1)){
	
	if (x==0) imin = 0; else imin = -1;
	if (y==0) jmin = 0; else jmin = -1;
	
	if (x==im->_tx-1) imax = 0; else imax = 1;
	if (y==im->_ty-1) jmax = 0; else jmax = 1;
          

	min = *buf;

	Pour(i,imin,imax)
	Pour(j,jmin,jmax)
	  n = abs(i)+abs(j);
	  Si n==0 AlorsFait continue;
	  SelonQue n Vaut
                Valeur 1: val = (*res)(x+i,y+j)+a; FinValeur
                Valeur 2: val = (*res)(x+i,y+j)+b; FinValeur
                Defaut: fprintf(stderr,"Func_Chamfer2_2D() \t Chamfer error (%d,%d) \n",x,y);
          FinSelonQue
          Si val<min AlorsFait min = val;
        FinPour
        FinPour

	res->BufferPos(x,y);
	res->FixeValeur(min);
	  
      }

      buf++;
    }  

  return res;
  
} // void Func_Chamfer2Signed_2D()
