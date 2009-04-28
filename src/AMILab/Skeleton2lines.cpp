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

#include "surface.hpp"
#include "style.hpp"
#include "inrimage.hpp"
#include "TableauDyn.hpp"

static int pos[3][3][3];
static int neighbors_pos  [27];
static int neighbors_place[27][3];


class extremity {

public:
  int x,y,z;
  //  int nb_links;

  extremity()
    {
      x=y=z=  0;
      //nb_links = 0;
    }

  extremity(int x0, int y0, int z0)
    {
      x  = x0;
      y  = y0;
      z  = z0;
      //      n0 = nb_links;
    }
};

//----------------------------------------------------------------------
void init_pos( InrImage* im)
//   --------
{

  
    int i,j,k,n;

  Pour(i,0,2)
  Pour(j,0,2)
  Pour(k,0,2)

    n                   = i+j*3+k*9;
    pos[i][j][k]        = n;
    neighbors_pos[n]    = i-1+((j-1)+(k-1)*im->_ty)*im->_tx;
    neighbors_place[n][0] = i-1;
    neighbors_place[n][1] = j-1;
    neighbors_place[n][2] = k-1;

  FinPour
  FinPour
  FinPour

} // Thin_init_pos()


//-----------------------------------------------------
SurfacePoly* Func_Skeleton2lines( InrImage* im)
{

  
    InrImage*    neighbors;
    InrImage*    endpoint;
    InrImage*    loop; // check for loops looking at the number of points in a 2x2x2 neighborhood
    int          x,y,z;
    int          x0,y0,z0;
    int          x1=0,y1=0,z1=0;
    int          x2,y2,z2;
    int          l;
    int          l0,n;

    int          nb_lines;
    int          nb_points;
//    int          nb_ext; // number of extremities
    TableauDyn<extremity> tab_ext;
    int          found;
    int          e;
    float        meanx,meany,meanz;

    SurfacePoly* surf;
    InrImage*    pointid;

    float        translation[3];
    int          remaining_loop;

  im->GetTranslation( translation[0], translation[1], translation[2]);


  loop = new InrImage(WT_SIGNED_INT,"loop.ami.gz",im);
  loop->InitImage(0);

  pointid = new InrImage(WT_SIGNED_INT,"pointid.ami.gz",im);
  pointid->InitImage(-1);

  surf = new SurfacePoly();

  init_pos(im);

  //------------ Check the number of neighbors -------------------
  //----------- Add the points to the surface with their numbers
  neighbors = new InrImage(WT_SIGNED_SHORT, "neighbors.ami.gz",im);

  // This image allows to avoid going twice through the same connection
  // by avoiding creating lines on points having more than 2 neighbors
  endpoint  = new InrImage(WT_UNSIGNED_CHAR,"endpoint.ami.gz", im);
  endpoint->InitImage(0);

  im       ->InitBuffer();
  neighbors->InitBuffer();

  Pour(z,0,im->_tz-1)
  Pour(y,0,im->_ty-1)
  Pour(x,0,im->_tx-1)

    n = 0;
    Si im->ValeurBuffer() > 0 Alors

      // Add the point and update the pointid image
      surf->AddPoint(
		     x*im->_size_x+translation[0],
		     y*im->_size_y+translation[1],
		     z*im->_size_z+translation[2]
		     );
      pointid->BufferPos(x,y,z);
      pointid->FixeValeur(surf->NbPoints()-1);

      // Compute the number of neighbors
      Pour(l,0,26)
        Si l==13 AlorsFait continue;
        x1 = x+neighbors_place[l][0];
        y1 = y+neighbors_place[l][1];
        z1 = z+neighbors_place[l][2];

        Si im->CoordOK(x1,y1,z1) Et (*im)(x1,y1,z1)>0 Alors
	  n++;
        FinSi
      FinPour

    FinSi

    Si n==1 Ou n>2 Alors
      tab_ext += extremity(x,y,z);
    FinSi

    Si n>2 Alors
      endpoint->BufferPos(x,y,z);
      endpoint->FixeValeur(1);
    FinSi

    neighbors->FixeValeur(n);
    im       ->IncBuffer();
    neighbors->IncBuffer();
  FinPour
  FinPour
  FinPour

  neighbors->Sauve();

  //--------------------------------------------------
  // Check for local loops and create mean point of loops 2x2x2 neighborhoods
  //

  im  ->InitBuffer();
  loop->InitBuffer();
  Pour(z,0,im->_tz-2)
  Pour(y,0,im->_ty-2)
  Pour(x,0,im->_tx-2)
    n = ((*im)(x,y,z)  >0)+ ((*im)(x+1,y,z)  >0)+((*im)(x,y+1,z)  >0)+((*im)(x+1,y+1,z)  >0) +
        ((*im)(x,y,z+1)>0)+ ((*im)(x+1,y,z+1)>0)+((*im)(x,y+1,z+1)>0)+((*im)(x+1,y+1,z+1)>0);
    if (n>2) {
      printf("%d %d %d --> n=%d\n",x,y,z,n);
      // compute the mean
      meanx=meany=meanz=0;
      for (x1=x;x1<=x+1;x1++)
	for (y1=y;y1<=y+1;y1++)
	  for (z1=z;z1<=z+1;z1++) {
	    if ((*im)(x1,y1,z1)>0) {
	      meanx+=x1;
	      meany+=y1;
	      meanz+=z1;
	    }      
	  }
      surf->AddPoint( (meanx*1.0/n)*im->_size_x+translation[0],
		      (meany*1.0/n)*im->_size_y+translation[1],
		      (meanz*1.0/n)*im->_size_z+translation[2] );
      // set the value to the corresponding voxels
      for (x1=x;x1<=x+1;x1++)
	for (y1=y;y1<=y+1;y1++)
	  for (z1=z;z1<=z+1;z1++) {
	    if ((*im)(x1,y1,z1)>0) {
	      loop->BufferPos(x1,y1,z1);
	      loop->FixeValeur(surf->NbPoints()-1);
	    }      
	  }
      
      // take care of the local loop: create a new point as the mean
      // and set its number to each location
    }
  FinPour
  FinPour
  FinPour


  //--------------- Create the lines ----------------------
  do {
  nb_lines = 0;
  Pour(e,0,tab_ext.NbElts()-1)
    x0 = tab_ext[e].x;
    y0 = tab_ext[e].y;
    z0 = tab_ext[e].z;
    l0 = 0;
    nb_points = 0;
    TantQue (*neighbors)(x0,y0,z0)>0 Faire
      //      printf("%03d : %2d %2d %2d Begin \n",nb_lines,x0,y0,z0);
      neighbors->BufferPos(x0,y0,z0);
      neighbors->FixeValeur(neighbors->ValeurBuffer()-1);

      // look for the positive link
      // beginning at the position of the last found positive neighbor
      found = false;

      Pour(l,l0,26)

        Si l==13  AlorsFait continue;
        x1 = x0+neighbors_place[l][0];
        y1 = y0+neighbors_place[l][1];
        z1 = z0+neighbors_place[l][2];
        Si im->CoordOK(x1,y1,z1) Et (*neighbors)(x1,y1,z1)>0 Alors
	  found = true;
  	  // position on the next neighbor 
  	  l0 = l+1;
          break;
        FinSi
      FinPour

      Si Non(found) Alors
        fprintf(stderr,"Func_skeleton2lines \t Error ? \n");
        neighbors->Sauve("pb.ami.gz");
        delete neighbors;
        delete pointid;
	return NULL;
      FinSi

      // Decide if the line must be created
      nb_points=0;
      if ((*loop)(x0,y0,z0)&&((*loop)(x0,y0,z0)==(*loop)(x1,y1,z1))) {
	neighbors->BufferPos(x1,y1,z1);
	neighbors->FixeValeur(neighbors->ValeurBuffer()-1);
	continue;
      } else {
	surf->NewLine();
	if ((*loop)(x0,y0,z0)) {
	  surf->LineAddPointNumber((int) (*loop)(x0,y0,z0));
	  nb_points++;
	}
	surf->LineAddPointNumber((int) (*pointid)(x0,y0,z0));
	nb_points++;
      }

      // 1. follow the line
      TantQue found Et (*neighbors)(x1,y1,z1)==2 
	            Et Non((*endpoint)(x1,y1,z1))
      Faire
        // Chercher le point suivant
        found = false;

        Pour(l,0,26)

          Si l==13 AlorsFait continue;
          x2 = x1+neighbors_place[l][0];
          y2 = y1+neighbors_place[l][1];
          z2 = z1+neighbors_place[l][2];

          Si Non((x2==x0)Et(y2==y0)Et(z2==z0))  Et
	     im->CoordOK(x2,y2,z2)              Et 
             (*neighbors)(x2,y2,z2)>0
          Alors
            neighbors->BufferPos(x1,y1,z1);
            neighbors->FixeValeur(0);
	    x0 = x1;
	    y0 = y1;
	    z0 = z1;
            // Add the point to the line
            surf->LineAddPointNumber((int) (*pointid)(x0,y0,z0));
//            printf("(%2d %2d %2d) ",x0,y0,z0);
            nb_points++;
	    x1 = x2;
	    y1 = y2;
	    z1 = z2;
            found = true;
            break;
          FinSi

        FinPour

        Si Non(found) Alors
	    printf("pb ? next point not found (%d %d %d) \n",x1,y1,z1);
        FinSi
            
      FinTantQue

      surf->LineAddPointNumber((int) (*pointid)(x1,y1,z1));
      nb_points++;
      if ((*loop)(x1,y1,z1)) {
	  surf->LineAddPointNumber((int) (*loop)(x1,y1,z1));
	  nb_points++;
      }
      surf->EndLine();

      neighbors->BufferPos(x1,y1,z1);
      neighbors->FixeValeur(neighbors->ValeurBuffer()-1);
      
      nb_lines++;

      // reset x0
      x0 = tab_ext[e].x;
      y0 = tab_ext[e].y;
      z0 = tab_ext[e].z;

    FinTantQue
  FinPour

  // Check for remaining loops
  remaining_loop=0;
  neighbors->InitBuffer();
  Pour(z,0,im->_tz-1)
    Pour(y,0,im->_ty-1)
      Pour(x,0,im->_tx-1)
        Si neighbors->ValeurBuffer() > 0 Alors
          tab_ext.VideTableau();
          tab_ext += extremity(x,y,z);
          remaining_loop=1;
          break;
        FinSi
        neighbors->IncBuffer();
      FinPour
      if (remaining_loop) break;
    FinPour
    if (remaining_loop) break;
  FinPour
    }
  while (remaining_loop);

  delete neighbors;
  delete pointid;
  delete endpoint;

  return surf;

} // Func_Skeleton2lines
