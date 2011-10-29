// Code from Andre Robatino

#include "dist_squared.hpp"

#define size_t long int
#define mxCalloc(a,b) malloc((a)*(b))
#define mxFree free

#ifdef HAVE_MALLOC_H
  #include <malloc.h>
#else
  #include <stdlib.h>
#endif

int dist_squared(int, size_t *, float *, unsigned char *, unsigned char, float *);

static void recursive_add_dist_squared(int, float *);

static void process_row(int, float *);

static size_t *g_axis_len, *g_stride;
static float *g_deltax, *g_tmp, *g_tmp_row, **g_j, *g_x, **g_recip, **g_square;

#ifndef FLT_MAX
#define FLT_MAX 1E30
#endif

//----------------------------------------------------------------------
int dist_squared( InrImage* im1, InrImage* im2)
//  ------------
{
     int rank;
     size_t axis_len[3];
     float  deltax[3];
//     register char *inimage;
//     register char inobject;
//     float *outdist_squared;

  if (im1->_tz >1) rank = 3;
  else
  if (im1->_ty >1) rank = 2;
  else             rank = 1;

  axis_len[0] = im1->_tx;
  axis_len[1] = im1->_ty;
  axis_len[2] = im1->_tz;

  deltax[0] = im1->_size_x;
  deltax[1] = im1->_size_y;
  deltax[2] = im1->_size_z;

  if (im1->_format !=WT_UNSIGNED_CHAR) {
    fprintf(stderr,"dist_squared() \t input image must be unsigned char \n");
    return 0;
  }

  if (im2->_format !=WT_FLOAT) {
    fprintf(stderr,"dist_squared() \t input image must be float \n");
    return 0;
  }

  dist_squared(rank,axis_len,deltax,
	       (unsigned char*) im1->Buffer(),
	       255,
	       (float*) im2->Buffer()
	       );

  return 1;
}


//----------------------------------------------------------------------
int dist_squared(
//  ------------
     int rank,
     size_t *axis_len,
     float *deltax,
     register unsigned char *inimage,
     register unsigned char inobject,
     float *outdist_squared)
{

  size_t max_axis_len, data_len;
  register size_t len;
  register float *p, *p2, ftmp, ftmp2;
  int i;

  if(!(rank >= 0)) return 0;
  if (rank == 0) {
    *outdist_squared = (*inimage == inobject)? 0.f : FLT_MAX;
    return 0;
  }

  g_stride = (size_t *)mxCalloc(rank,sizeof(size_t));
  max_axis_len = 2;
  data_len = 1;
  for (i=0; i<rank; i++) {
    if (!(axis_len[i] > 1)) return 0;
    if (!(deltax[i] != 0.f)) return 0;
    if (max_axis_len < axis_len[i]) max_axis_len = axis_len[i];
    g_stride[i] = data_len;
    data_len *= axis_len[i];
  }

  g_tmp = (float *)mxCalloc(max_axis_len,sizeof(float));
  g_tmp_row = (float *)mxCalloc(max_axis_len,sizeof(float));
  g_j = (float **)mxCalloc(max_axis_len,sizeof(float *));
  g_x = (float *)mxCalloc(max_axis_len,sizeof(float));
  p = outdist_squared;
  len = g_stride[rank - 1];

  while (len--) {
    *p++ = (*inimage++ == inobject)? 0.f : FLT_MAX;
  }

  p2 = outdist_squared;
  ftmp = deltax[rank - 1];
  if (ftmp < 0.f) ftmp = -ftmp;
  len = data_len - g_stride[rank - 1];
  while (len--) {
    if (*inimage++ == inobject) *p = 0.f;
    else if ((*p = *p2) != FLT_MAX) *p += ftmp;
    p++;
    p2++;
  }
  if (rank > 1) {
    g_axis_len = axis_len;
    g_deltax = deltax;
    g_recip = (float **)mxCalloc(rank - 1,sizeof(float *));
    g_square = (float **)mxCalloc(rank - 1,sizeof(float *));
    for (i=0; i<rank-1; i++) {
      g_recip[i] = (float *)mxCalloc(axis_len[i] + 1,sizeof(float));
      g_square[i] = (float *)mxCalloc(axis_len[i] + 1,sizeof(float));
      len = axis_len[i];
      do {
        ftmp2 = len*deltax[i];
        if (ftmp2 < 0.f) ftmp2 = -ftmp2;
        g_recip[i][len] = 0.5f/ftmp2;
        g_square[i][len] = ftmp2*ftmp2;
      } while (--len);
    }
    while (p2 != outdist_squared) {
      len = g_stride[rank - 1];
      while (len--) {
        --p2;
        if (*--p != FLT_MAX) {
          ftmp2 = *p + ftmp;
          *p *= *p;
          if (*p2 > ftmp2) *p2 = ftmp2;
        }
      }
      recursive_add_dist_squared(rank-2, p);
    }
    len = g_stride[rank - 1];
    while (len--) {
      if (*--p != FLT_MAX) *p *= *p;
    }
    recursive_add_dist_squared(rank-2, p);
    for (i=0; i<rank-1; i++) {
      mxFree(g_recip[i]);
      mxFree(g_square[i]);
    }
    mxFree(g_recip);
    mxFree(g_square);
  } else {
    len = data_len - 1;
    while (len--) {
      --p2;
      if (*--p != FLT_MAX) {
        ftmp2 = *p + ftmp;
        *p *= *p;
        if (*p2 > ftmp2) *p2 = ftmp2;
      }
    }
    if (*--p != FLT_MAX) *p *= *p;
  }
  mxFree(g_tmp);
  mxFree(g_tmp_row);
  mxFree(g_j);
  mxFree(g_x);
  return 0;
}


//----------------------------------------------------------------------
static void recursive_add_dist_squared(
//          --------------------------
     int axis,
     float *start)
{
  size_t len;
  float *p, *p_end, *p2, *p2_end, *p3;

  if (axis == 0) {
    process_row(0, start);
    return;
  }

  len = g_stride[axis];
  p = start;
  p_end = p + len;
  p2_end = g_tmp + g_axis_len[axis];
  while (p != p_end) {
    p2 = g_tmp;
    p3 = p;
    while (p2 != p2_end) {
      *p2++ = *p3;
      p3 += len;
    }
    process_row(axis, g_tmp);
    p2 = g_tmp;
    p3 = p++;
    while (p2 != p2_end) {
      *p3 = *p2++;
      p3 += len;
    }
  }

  p = start;
  len = g_axis_len[axis];
  while (len--) {
    recursive_add_dist_squared(axis-1, p);
    p += g_stride[axis];
  }
  return;

} // recursive_add_dist_squared()


//----------------------------------------------------------------------
static void process_row(
//          -----------
     int axis,
     float *start)
{
  register size_t len;
  register float *p, *p2, *p3, *p_end, pv, p2v, **jp, **j2p, **j_end, *x2p;
  register float x, x0, x2, *recip, *square, dx;

  dx = g_deltax[axis];
  if (dx < 0.f) dx = -dx;
  j_end = g_j;
  p = start;
  p_end = start + g_axis_len[axis];
  do {
    if (*p != FLT_MAX) *j_end++ = p;
  } while (++p != p_end);
  if (j_end == g_j) return;
  jp = j2p = g_j;
  x2p = g_x;
  *g_x = -FLT_MAX;
  if (++jp != j_end) {
    pv = *(p = *jp);
    p2v = *(p2 = *j2p);
    x2 = -FLT_MAX;
    x0 = dx*(p - start);
    square = g_square[axis];
    recip = g_recip[axis];
    while (1) {
      len = p - p2;
      x = x0 + (pv - p2v - square[len])*recip[len];
      if (x > x2) {
        *++j2p = p;
        *++x2p = x;
        if (++jp == j_end) break;
        p2 = p;
        p2v = pv;
        x2 = x;
        pv = *(p = *jp);
        x0 = dx*(p - start);
      } else {
        p2v = *(p2 = *--j2p);
        x2 = *--x2p;
      }
    }
  }

  len = g_axis_len[axis];
  p = p_end = g_tmp_row + len;
  p3 = start + len;
  while (len--) {
    x = dx*len;
    while (*x2p > x) {
      j2p--;
      x2p--;
    }
    p2 = *j2p;
    x = dx*(--p3 - p2);
    *--p = *p2 + x*x;
  }
  p2 = start;
  while (p != p_end) *p2++ = *p++;

  return;

} // process_row
