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

#include "fonctions.h"

#define POINT_NOT_PARSED 0
#define POINT_TRIAL      1
#define POINT_SET_FRONT  2
#define POINT_SET        3

#define macro_min(a,b) ((a<b)?a:b)
#define macro_max(a,b) ((a>b)?a:b)

// the input image
// contains distance values in ]-1,1[
// for initializing the front
//
InrImage* Func_PropagationDistance(InrImage* input, float max_dist)
{
    // 0: know values in the front
    // 1: value to compute in the front
    register int*      list0;
    register int*      list1;
    register int*      list2;
    register int       list0_size;
    register int       list1_size;
    register int       list2_size;
    int       list_maxsize;
    InrImage* im_state;
    register int       dx,dy,dz;
    int       n[26];
    register int l;
    float     c[26];
    register int       p,k,pn,size;
    register float*    buf;
    register unsigned char*    state_buf;
    register float*            list_buf;
    register int*              track_buf;
    int i,j;
    float known_dist;
    float step_dist;
    InrImage* track;
    InrImage* im_list;
    int       iteration;
    //    char      name[100];
    float     val_min_pos,val_max_pos;
    float     val_min_neg,val_max_neg;
    float     val_min;
    float     val;

  im_state = new InrImage(WT_UNSIGNED_CHAR,"im_state.ami.gz",input);
  im_list  = new InrImage(WT_FLOAT,"im_list.ami.gz",input);
  track    = new InrImage(WT_SIGNED_INT,"im_state.ami.gz",input);

  im_state->InitImage(0);
  track   ->InitImage(-1);
  state_buf = (unsigned char*) im_state->Buffer();
  list_buf  = (float*)         im_list->Buffer();
  track_buf = (int*)           track->Buffer();

  list_maxsize = 500000;

  list0 = new int[list_maxsize];
  list1 = new int[list_maxsize];
  list2 = new int[list_maxsize];
  list0_size = 0;
  list1_size = 0;
  list2_size = 0;

  if (input->_format != WT_FLOAT) {
    fprintf(stderr,"PropagationDistance() \t only float format as input \n");
    return NULL;
  }

  buf  = (float*) input->Buffer();
  dx = 1;
  dy = input->DimX();
  dz = dy*input->DimY();
  size = dz*input->DimZ();

  // initialize neighbors
  l = 0;
  for(i=-dx;i<=dx;i+=dx)
    for(j=-dy;j<=dy;j+=dy)
      for(k=-dz;k<=dz;k+=dz) {
	if ((i==0)&&(j==0)&&(k==0)) continue;
	n[l]=i+j+k;
	switch ((i!=0)+(j!=0)+(k!=0)) {
	case 1: c[l] = 0.92644; break;
	case 2: c[l] = 1.34065; break;
	case 3: c[l] = 1.65849; break;
	}
	//	printf(" %d %d %f \n",l,n[l],c[l]);
	l++;
      }


  step_dist  = 0.92644;
  known_dist = 0;

  // Create the first list: values in ]-1,1[
  for(p=0;p<size;p++)
    if (fabs(buf[p])<1) {
      //      buf[p]*=0.92644;
      list0[list0_size++] = p;
      state_buf[p] = POINT_SET_FRONT;
    }
    else
      if (buf[p]>0)
	buf[p] = max_dist;
      else
	buf[p] = -max_dist;

  //  im_state->Sauve("state0.ami.gz");

  iteration = 0;

  //  im_list->InitImage(0);
  //  for(k=0;k<list0_size;k++) list_buf[list0[k]] = buf[list0[k]];
  //  sprintf(name,"list0_0_%d.ami.gz",iteration);
  //  im_list->Sauve(name);

  // Compute all the values in ]-a,a[
  // use list1_size and list2_size for this purpose
  for(k=0;k<list0_size;k++) list1[k]=list0[k];
  list1_size = list0_size;

  //
  while (list1_size != 0) {
    list2_size = 0;
    for(k=1;k<list1_size;k++) {
      p = list1[k];
      // Check the neighbors for trial
      for(l=0;l<26;l++) {
	pn = p+n[l];
	if ((pn>=0)&&(pn<size)) {
	  // check buf[p]>0 for not putting negative points the first time
	  if ((state_buf[pn]!=POINT_SET_FRONT)) {
	    if (buf[pn]>0) {
	      val = buf[p]+c[l];
	      if ((val<step_dist)&&(val<buf[pn])) {
		buf[pn] = val;
  	        track_buf[pn] = p;
		list2[list2_size++] = pn;
		if (state_buf[pn]!= POINT_TRIAL) {
		  state_buf[pn] = POINT_TRIAL;
		  list0[list0_size++] = pn;
		}
	      }
	    } else {
	      val = buf[p]-c[l];
	      if ((val>-step_dist)&&(val>buf[pn])) {
		buf[pn] = val;
  	        track_buf[pn] = p;
		list2[list2_size++] = pn;
		if (state_buf[pn]!= POINT_TRIAL) {
		  state_buf[pn] = POINT_TRIAL;
		  list0[list0_size++] = pn;
		}
	      }
	    }
	  } // end if
	} // end if
      } // end for l
    } // end for k
    // copy list2 dans list1

    printf("list2_size = %5d \n",list2_size);

    for(k=0;k<list2_size;k++) list1[k] = list2[k];
    list1_size = list2_size;
  } // end while

  for(k=0;k<list0_size;k++) state_buf[list0[k]] = POINT_SET_FRONT;
  known_dist = step_dist;

  //  im_list->InitImage(0);
  //  for(k=0;k<list0_size;k++) list_buf[list0[k]] = buf[list0[k]];
  //  sprintf(name,"list0_1_%d.ami.gz",iteration);
  //  im_list->Sauve(name);

  printf("list0_size = %5d \n",list0_size);


  while (known_dist<max_dist) {

    iteration++;
    printf("known dist %f \n",known_dist);

    val_min_pos = max_dist;
    val_min_neg = 1;
    val_max_pos = -1;
    val_max_neg = -max_dist;

    // Create the trial points
    list1_size = 0;
    for(k=0;k<list0_size;k++) {
      p = list0[k];
      // Check the neighbors for trial
      for(l=0;l<26;l++) {
	pn = p+n[l];
	if ((pn>=0)&&(pn<size)) {
	  // check buf[p]>0 for not putting negative points the first time
	  if ((state_buf[pn]==POINT_NOT_PARSED)) {
	      state_buf[pn]=POINT_TRIAL;
	      list1[list1_size++]=pn;
	      if (buf[pn]>0) {
		val_min_pos = macro_min(val_min_pos,buf[p]);
		val_max_pos = macro_max(val_max_pos,buf[p]);
	      } else {
		val_min_neg = macro_min(val_min_neg,buf[p]);
		val_max_neg = macro_max(val_max_neg,buf[p]);
	      }
	  } // end if
	} // end if
      } // end for l
    }

    printf("pos [%2.2f, %2.2f]  neg [%2.2f, %2.2f] \n",
	  val_min_pos,val_max_pos,
	  val_min_neg,val_max_neg
	  );

    //    sprintf(name,"state1_%d.ami.gz",iteration);
    //    im_state->Sauve(name);

    //    im_list->InitImage(0);
    //    for(k=0;k<list1_size;k++) list_buf[list1[k]] = buf[list1[k]];
    //    sprintf(name,"list1_%d.ami.gz",iteration);
    //    im_list->Sauve(name);

    //    printf("list1_size = %5d \n",list1_size);

    // Compute the trial points
    // the smallest trial point will be >= to the lowest point
    // of list0 (n) + 1,
    // so all the points <= n+2 can be set as known ...


    for(k=0;k<list1_size;k++) {
      p = list1[k];
      // update the value using the known points
      // we use here the chamfer dist for simplicity
      // not very good ...

      // Positive side
      if (buf[p]>0) {
	for(l=0;l<26;l++) {
	  pn = p+n[l];
	  if ((pn>=0)&&(pn<size)) {
	    if (state_buf[pn]==POINT_SET_FRONT) {
	      if ((buf[pn]+c[l])<buf[p]) {
		buf[p] = buf[pn]+c[l];
		track_buf[p] = pn;
	      }
	    } // end if
	  } // end if
	} // end for l
      }

      // Negative side
      if (buf[p]<0) {
	for(l=0;l<26;l++) {
	  pn = p+n[l];
	  if ((pn>=0)&&(pn<size)) {
	    if (state_buf[pn]==POINT_SET_FRONT) {
	      if ((buf[pn]-c[l])>buf[p]) {
		buf[p] = buf[pn]-c[l];
  	        track_buf[p] = pn;
	      }
	    } // end if
	  } // end if
	} // end for l
      }

    }

    for(k=0;k<list0_size;k++)
      state_buf[list0[k]] = POINT_SET;
    list0_size = 0;

    val_min = max_dist;
    for(k=0;k<list1_size;k++) {
      p = list1[k];
      // update the list of known points in the front
      if (fabs(buf[p])<=known_dist+step_dist) {
	list0[list0_size++] = p;
	state_buf[p] = POINT_SET_FRONT;
	if (fabs(buf[p])<val_min)
	  val_min = fabs(buf[p]);
      }
      else
	state_buf[p] = POINT_NOT_PARSED;
    }


    //    sprintf(name,"state2_%d.ami.gz",iteration);
    //    im_state->Sauve(name);
    //
    //    im_list->InitImage(0);
    //    for(k=0;k<list0_size;k++) list_buf[list0[k]] = buf[list0[k]];
    //    sprintf(name,"list0_%d.ami.gz",iteration);
    //    im_list->Sauve(name);

    printf("list0_size = %5d  min = %f, borne max = %f \n",
	   list0_size, val_min, known_dist+step_dist);


    known_dist += step_dist;
  } // end while


  delete im_state;

  return track;

} // PropagationDistance()


//----------------------------------------------------------------------
InrImage* Func_PropagationDistance2(InrImage* input, float max_dist)
{
    // 0: know values in the front
    // 1: value to compute in the front
    register int*      list0;
    register int*      list1;
    register int       list0_size;
    register int       list1_size;
    int       list_maxsize;
    InrImage* im_state;
    register int       dx,dy,dz;
    register int       n[26],l;
    register float     c[26];
    register int       p,k,pn,size;
    register float*    buf;
    register unsigned char*    state_buf;
    //    register unsigned char*    list_buf;
    register int*              track_buf;
    int i,j;
    float known_dist;
    float step_dist;
    InrImage* track;
    //    InrImage* im_list;
    int       iteration;
    //    char      name[100];

  im_state = new InrImage(WT_UNSIGNED_CHAR,"im_state.ami.gz",input);
  //  im_list  = new InrImage(WT_UNSIGNED_CHAR,"im_list.ami.gz",input);
  track    = new InrImage(WT_SIGNED_INT,"im_state.ami.gz",input);

  im_state->InitImage(0);
  track   ->InitImage(-1);
  state_buf = (unsigned char*) im_state->Buffer();
  //  list_buf  = (unsigned char*) im_list->Buffer();
  track_buf = (int*) track->Buffer();

  list_maxsize = 500000;

  list0 = new int[list_maxsize];
  list1 = new int[list_maxsize];
  list0_size = 0;
  list1_size = 0;

  if (input->_format != WT_FLOAT) {
    fprintf(stderr,"PropagationDistance() \t only float format as input \n");
    return NULL;
  }

  buf  = (float*) input->Buffer();
  dx = 1;
  dy = input->DimX();
  dz = dy*input->DimY();
  size = dz*input->DimZ();

  // initialize neighbors
  l = 0;
  for(i=-dx;i<=dx;i+=dx)
    for(j=-dy;j<=dy;j+=dy)
      for(k=-dz;k<=dz;k+=dz) {
	if ((i==0)&&(j==0)&&(k==0)) continue;
	n[l]=i+j+k;
	switch ((i!=0)+(j!=0)+(k!=0)) {
	case 1: c[l] = 0.92644; break;
	case 2: c[l] = 1.34065; break;
	case 3: c[l] = 1.65849; break;
	}
	printf(" %d %d %f \n",l,n[l],c[l]);
	l++;
      }


  step_dist  = 0.92644;
  known_dist = 0;

  // Create the first list: values in ]-1,1[
  for(p=0;p<size;p++)
    if (fabs(buf[p])<1) {
      //      buf[p]*=0.92644;
      list0[list0_size++] = p;
      state_buf[p] = POINT_SET_FRONT;
    }
    else
      if (buf[p]>0)
	buf[p] = max_dist;
      else
	buf[p] = -max_dist;

  //  im_state->Sauve("state0.ami.gz");

  iteration = 0;

  //  im_list->InitImage(0);
  //  for(k=0;k<list0_size;k++) list_buf[list0[k]] = 1;
  //  sprintf(name,"list0_%d.ami.gz",iteration);
  //  im_list->Sauve(name);

  printf("list0_size = %5d \n",list0_size);


  while (known_dist<max_dist) {

    iteration++;
    printf("known dist %f \n",known_dist);

    // Create the trial points
    list1_size = 0;
    for(k=0;k<list0_size;k++) {
      p = list0[k];
      // Check the neighbors for trial
      for(l=0;l<26;l++) {
	pn = p+n[l];
	if ((pn>=0)&&(pn<size)) {
	  // check buf[p]>0 for not putting negative points the first time
	  if ((state_buf[pn]==POINT_NOT_PARSED)) {
	      state_buf[pn]=POINT_TRIAL;
	      list1[list1_size++]=pn;
	  } // end if
	} // end if
      } // end for l
    }

    //    sprintf(name,"state1_%d.ami.gz",iteration);
    //    im_state->Sauve(name);

    //    im_list->InitImage(0);
    //    for(k=0;k<list1_size;k++) list_buf[list1[k]] = 1;
    //    sprintf(name,"list1_%d.ami.gz",iteration);
    //    im_list->Sauve(name);

    //    printf("list1_size = %5d \n",list1_size);

    // Compute the trial points
    // the smallest trial point will be >= to the lowest point
    // of list0 (n) + 1,
    // so all the points <= n+2 can be set as known ...

    // the first iteration, we must have all the
    // point at distance between 0 and step_dist ...
    if (iteration>1) {
      list0_size = 0;
    }

    for(k=0;k<list1_size;k++) {
      p = list1[k];
      // update the value using the known points
      // we use here the chamfer dist for simplicity
      // not very good ...

      // Positive side
      if (buf[p]>0) {
	for(l=0;l<26;l++) {
	  pn = p+n[l];
	  if ((pn>=0)&&(pn<size)) {
	    if (state_buf[pn]==POINT_SET_FRONT) {
	      if ((buf[pn]+c[l])<buf[p])
		buf[p] = buf[pn]+c[l];
	      track_buf[p] = pn;
	    } // end if
	  } // end if
	} // end for l
      }

      // Negative side
      if (buf[p]<0) {
	for(l=0;l<26;l++) {
	  pn = p+n[l];
	  if ((pn>=0)&&(pn<size)) {
	    if (state_buf[pn]==POINT_SET_FRONT) {
	      if ((buf[pn]-c[l])>buf[p])
		buf[p] = buf[pn]-c[l];
  	        track_buf[p] = pn;
	    } // end if
	  } // end if
	} // end for l
      }

      if (fabs(buf[p])<=known_dist+step_dist) {
	list0[list0_size++] = p;
	state_buf[p] = POINT_SET_FRONT;
      }
      else
	state_buf[p] = POINT_NOT_PARSED;
    }


    //    sprintf(name,"state2_%d.ami.gz",iteration);
    //    im_state->Sauve(name);
    //
    //    im_list->InitImage(0);
    //    for(k=0;k<list0_size;k++) list_buf[list0[k]] = 1;
    //    sprintf(name,"list0_%d.ami.gz",iteration);
    //    im_list->Sauve(name);

    printf("list0_size = %5d \n",list0_size);


    known_dist += step_dist;
  } // end while


  delete im_state;

  return track;

} // PropagationDistance2()


/*
typdef struct PD_element {
  unsigned short x;
  unsigned short y;
  unsigned short z;
  float          val;
} PD_element;
*/

// the input image
// contains distance values in ]-1,1[
// for initializing the front
//
InrImage* Func_PropagationDanielsson(InrImage* input, float max_dist)
{
    // 0: know values in the front
    // 1: value to compute in the front
    register int*      list0;
    register int*      list1;
    register int*      list2;
    register int       list0_size;
    register int       list1_size;
    register int       list2_size;
    int       list_maxsize;
    InrImage* im_state;
    register int       dx0,dy0,dz0;
    register int       dx,dy,dz;
    register int       tx,ty,tz;
    register int       n[26];
    register int       nx[26];
    register int       ny[26];
    register int       nz[26];
    register int       l;
    register int       tp; //,px,py,pz;
    register int       p,k,pn,size;

    register float*    buf;
    register  short*    buf_x;
    register  short*    buf_y;
    register  short*    buf_z;
    register unsigned char*    state_buf;
    register float*            list_buf;
    register int*              track_buf;

    int                x,y,z,i,j;
    register float known_dist;
    register float next_dist;
    register float step_dist;

    InrImage* track;
    InrImage* im_list;
    int       iteration;
    //    char      name[100];
    float     val_min_pos,val_max_pos;
    float     val_min_neg,val_max_neg;
    float     val_min;
    register float     val;
    register float     val0;

    int updated;

    // precomputed table for the square
    int*    sq;
    int     sq_size;
    double*  sqroot;
    int     sqroot_size;

    double*** distance;

  sq_size = (int) (max_dist+2);
  printf("sq size = %d \n",sq_size);
  sq = new int[sq_size];
  for(i=0;i<sq_size;i++) sq[i]=i*i;

  sqroot_size = 3*sq_size*sq_size;
  sqroot = new double[sqroot_size];
  printf("sqroot size = %d \n",sqroot_size);
  for(i=0;i<sqroot_size;i++)  sqroot[i] = sqrt((double)i);

  distance = new double**[sq_size];
  for(x=0;x<sq_size;x++) distance[x] = new double*[sq_size];
  for(x=0;x<sq_size;x++)
    for(y=0;y<sq_size;y++) distance[x][y] = new double[sq_size];

  for(x=0;x<sq_size;x++)
    for(y=0;y<sq_size;y++)
      for(z=0;z<sq_size;z++)
	distance[x][y][z] = sqroot[sq[x]+sq[y]+sq[z]];

#define dist2(a,b,c)  (sq[abs(a)]+sq[abs(b)]+sq[abs(c)])
  //#define dist(a,b,c)  (sqroot[sq[abs(a)]+sq[abs(b)]+sq[abs(c)]])
#define dist(a,b,c)  (distance[abs(a)][abs(b)][abs(c)])


  im_state = new InrImage(WT_UNSIGNED_CHAR,"im_state.ami.gz",input);
  im_list  = new InrImage(WT_FLOAT,"im_list.ami.gz",input);
  track    = new InrImage(WT_SIGNED_INT,"im_track.ami.gz",input);

  im_state->InitImage(0);
  track->InitImage(-1);

  state_buf = (unsigned char*) im_state->Buffer();
  list_buf  = (float*)         im_list->Buffer();
  track_buf = (int*)           track->Buffer();

  list_maxsize = 500000;

  list0 = new int[list_maxsize];
  list1 = new int[list_maxsize];
  list2 = new int[list_maxsize];
  list0_size = 0;
  list1_size = 0;
  list2_size = 0;

  if (input->_format != WT_FLOAT) {
    fprintf(stderr,"PropagationDistance() \t only float format as input \n");
    return NULL;
  }

  buf    = (float*) input->Buffer();

  tx = 1;
  ty = input->DimX();
  tz = ty*input->DimY();
  size = tz*input->DimZ();

  buf_x  = new short[size];
  buf_y  = new short[size];
  buf_z  = new short[size];

  // initialize neighbors
  l = 0;
  for(i=-tx;i<=tx;i+=tx)
    for(j=-ty;j<=ty;j+=ty)
      for(k=-tz;k<=tz;k+=tz) {
	if ((i==0)&&(j==0)&&(k==0)) continue;
        ((i<0)?nx[l]=-1:((i>0)?nx[l]=1:nx[l]=0));
        ((j<0)?ny[l]=-1:((j>0)?ny[l]=1:ny[l]=0));
        ((k<0)?nz[l]=-1:((k>0)?nz[l]=1:nz[l]=0));
	n[l]=i+j+k;
	l++;
      }


  step_dist  = 1;
  known_dist = 0;

  // Create the first list: values in ]-1,1[
  p = 0;
  for(z=0;z<input->DimZ();z++)
  for(y=0;y<input->DimY();y++)
  for(x=0;x<input->DimX();x++)  {
    if (fabs(buf[p])<1) {
      list0[list0_size++] = p;
      buf_x[p]     = 0;
      buf_y[p]     = 0;
      buf_z[p]     = 0;
      track_buf[p] = p;
      state_buf[p] = POINT_SET_FRONT;
    }
    else
      if (buf[p]>0)
	buf[p] = max_dist;
      else
	buf[p] = -max_dist;
    p++;
  }
  //  im_state->Sauve("state0.ami.gz");

  iteration = 0;

//    im_list->InitImage(0);
//    for(k=0;k<list0_size;k++) list_buf[list0[k]] = buf[list0[k]];
//   sprintf(name,"list0_0_%d.ami.gz",iteration);
//    im_list->Sauve(name);


  for(k=0;k<list0_size;k++) state_buf[list0[k]] = POINT_SET_FRONT;
  known_dist = 0;

  //    im_list->InitImage(0);
  //    for(k=0;k<list0_size;k++) list_buf[list0[k]] = buf[list0[k]];
  //    sprintf(name,"list0_1_%d.ami.gz",iteration);
  //    im_list->Sauve(name);

  printf("list0_size = %5d \n",list0_size);


  while (known_dist<max_dist) {

    iteration++;
    printf("known dist %f \n",known_dist);

    val_min_pos = max_dist;
    val_min_neg = 1;
    val_max_pos = -1;
    val_max_neg = -max_dist;

    next_dist = known_dist+step_dist;

    // Create the trial points
    list1_size = 0;
    for(k=0;k<list0_size;k++) {
      p = list0[k];
      dx0 = buf_x[p];
      dy0 = buf_y[p];
      dz0 = buf_z[p];
      tp   = track_buf[p];
      val0 = buf[tp];

      // Check the neighbors for trial
      for(l=0;l<26;l++) {
	pn = p+n[l];
	if ((pn>=0)&&(pn<size)) {
	  // check buf[p]>0 for not putting negative points the first time
	  if ((state_buf[pn]==POINT_NOT_PARSED)) {
	      state_buf[pn]=POINT_TRIAL;
	      list1[list1_size++]=pn;
	      if (buf[pn]>0) {
		val_min_pos = macro_min(val_min_pos,buf[p]);
		val_max_pos = macro_max(val_max_pos,buf[p]);
	      } else {
		val_min_neg = macro_min(val_min_neg,buf[p]);
		val_max_neg = macro_max(val_max_neg,buf[p]);
	      }
	  } // end if

	  // Update here the values of the trial points
	  if ((state_buf[pn]==POINT_TRIAL)) {
	    dx = dx0+nx[l];
	    dy = dy0+ny[l];
	    dz = dz0+nz[l];
	    // Positive side
	    if (buf[pn]>0) {
	      val = val0 + dist(dx,dy,dz);
	      if (val<buf[pn]) {
		buf      [pn] = val;
		buf_x    [pn] = dx;
		buf_y    [pn] = dy;
		buf_z    [pn] = dz;
		track_buf[pn] = tp;
	      }
	    }
	    // Negative side
	    if (buf[pn]<0) {
	      val = val0 - dist(dx,dy,dz);
	      if (val>buf[pn]) {
		buf      [pn] = val;
		buf_x    [pn] = dx;
		buf_y    [pn] = dy;
		buf_z    [pn] = dz;
		track_buf[pn] = tp;
	      }
	    } // end if
	  } // POINT_TRIAL
	} // pn in [0,size-1]
      } // for l in [0,25]
    } // for k in [0,list0_size-1]

    printf("pos [%2.2f, %2.2f]  neg [%2.2f, %2.2f] \n",
	  val_min_pos,val_max_pos,
	  val_min_neg,val_max_neg
	  );

    //    sprintf(name,"state1_%d.ami.gz",iteration);
    //    im_state->Sauve(name);


    //    printf("list1_size = %5d \n",list1_size);

    // Compute the trial points
    // the smallest trial point will be >= to the lowest point
    // of list0 (n) + 1,
    // so all the points <= n+2 can be set as known ...



    //        im_list->InitImage(0);
    //        for(k=0;k<list1_size;k++) list_buf[list1[k]] = buf[list1[k]];
    //        sprintf(name,"list1_%d.ami.gz",iteration);
    //        im_list->Sauve(name);

    for(k=0;k<list0_size;k++)
      state_buf[list0[k]] = POINT_SET_FRONT;

    // First iteration, we complete list0 ...
    if (iteration>1) list0_size = 0;

    // Should we try to update again ???
    // Iterate until no point updated ?


    //  Once is enough ...
    //    do {
    updated = 0;
    for(k=0;k<list1_size;k++) {
      p = list1[k];
       // update the value using the known points
      // we use here the chamfer dist for simplicity
      // not very good ...
      tp   = track_buf[p];
      if (tp<0) continue;
      dx0 = buf_x[p];
      dy0 = buf_y[p];
      dz0 = buf_z[p];
      val0 = buf[tp];

      // Check the neighbors for trial
      for(l=0;l<26;l++) {
	pn = p+n[l];
	if ((pn>=0)&&(pn<size)) {
	  // Update here the values of the trial points
	  if ((state_buf[pn]==POINT_TRIAL)) {
	    dx = dx0+nx[l];
	    dy = dy0+ny[l];
	    dz = dz0+nz[l];
	    // Positive side
	    if (buf[pn]>0) {
	      val = val0 + dist(dx,dy,dz);
	      if ((val<buf[pn])&&(val<next_dist)) {
		updated++;
		buf      [pn] = val;
		buf_x    [pn] = dx;
		buf_y    [pn] = dy;
		buf_z    [pn] = dz;
		track_buf[pn] = tp;
	      }
	    } else {
	      // Negative side
	      val = val0 - dist(dx,dy,dz);
	      if ((val>buf[pn])&&(val>-next_dist)) {
		updated++;
		buf      [pn] = val;
		buf_x    [pn] = dx;
		buf_y    [pn] = dy;
		buf_z    [pn] = dz;
		track_buf[pn] = tp;
	      }
	    } // end if
	  } // POINT_TRIAL
	} // pn in [0,size-1]
      } // for l in [0,25]

    } // end for k in [0,list1_size-1]

    printf("Number of updated points: %d \n",updated);
    //   }
    //    while (updated != 0);

    val_min = max_dist;
    for(k=0;k<list1_size;k++) {
      p = list1[k];
      // update the list of known points in the front
      if (fabs(buf[p])<=known_dist+step_dist) {
	list0[list0_size++] = p;
	state_buf[p] = POINT_SET_FRONT;
	if (fabs(buf[p])<val_min)
	  val_min = fabs(buf[p]);
      }
      else
	state_buf[p] = POINT_NOT_PARSED;
    }


    //    sprintf(name,"state2_%d.ami.gz",iteration);
    //    im_state->Sauve(name);
    //
    //        im_list->InitImage(0);
    //        for(k=0;k<list0_size;k++) list_buf[list0[k]] = buf[list0[k]];
    //        sprintf(name,"list0_%d.ami.gz",iteration);
    //        im_list->Sauve(name);

    printf("list0_size = %5d  min = %f, borne max = %f \n",
	   list0_size, val_min, known_dist+step_dist);


    known_dist = next_dist;

  } // end while


  delete im_state;

  delete [] sq;
  delete [] sqroot;

  for(x=0;x<sq_size;x++)
    for(y=0;y<sq_size;y++) delete [] distance[x][y];
  for(x=0;x<sq_size;x++) delete [] distance[x];
  delete [] distance;

  return track;

} // PropagationDanielsson()



