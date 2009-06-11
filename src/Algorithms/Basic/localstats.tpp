//
// C++ Implementation: localstats
//
// Description: 
//
//
// Author: Karl Krissian <krissian@dis.ulpgc.es>, (C) 2009
//
// Copyright: See COPYING file that comes with this distribution
//
//

/*
  sum squared neighborhoods of size (2*size+1)
  along one axis
  could add   boundary_cond: 0 mirror
                             1 extension
  only mirror boundaries at the moment
*/

#include <omp.h>
#include "Timing.hpp"
#include "amilab_messages.h"

#include "FastVector.hpp"

/*
#include "Timing.hpp"
extern Timing localmeanX;
extern Timing localmeanY;
extern Timing localmeanZ;
*/

#define USE_TIMING 

#ifdef USE_TIMING 
  #define START_TIMING( message ) \
      std::string timing_mess = (boost::format("%1% %2%") % __func__ % (message).str()).str(); \
      Timing timer(timing_mess); \
      timer.Debut(); 
  
  #define END_TIMING \
      timer.Fin(); \
      timer.AddCumul(); \
      timer.AfficheCumul(cout); 
#else
  #define START_TIMING( ) 
  #define END_TIMING 
#endif


template<class T,class TInc>
void FastLocalDiffX( InrImage* in, InrImage* out, 
                      int size, int axis, 
                      const ImageExtent<int>& extent,
                      const unsigned char& stepsize=4)
{

  START_TIMING(boost::format("%1%, %2%, x%3%") 
                  % typeid(T).name() 
                  % typeid(TInc).name()
                  % (int) stepsize)

  short     dim[3]    = { in->DimX(), in->DimY(), in->DimZ() };
  int       diminc[3] = { 1, in->DimX(), in->DimX()*in->DimY() };
  int       dir[3];
  int       dirinc[3];
  int       pos[3] = {0,0,0};
  unsigned char ns;

  T*        buf;
  T*        bufmin;
  T*        bufmax;
  register T* res_buf;

  // check that input and output are of the right type ???

  dir[0] = (axis+2)%3; // 2
  dir[1] = (axis+1)%3; // 1
  dir[2] = axis; // 0
  
  dirinc[0] = diminc[dir[0]];
  dirinc[1] = diminc[dir[1]];
  dirinc[2] = diminc[dir[2]];

  int dim0 = dim[dir[0]];
  int dim1 = dim[dir[1]];
  int dim2 = dim[dir[2]];

  int& p0 = pos[dir[0]];
  int& p1 = pos[dir[1]];
  int& p2 = pos[dir[2]];
  int  p;

  TInc dir2_inc = 1;
  if (dir[2]>=1) dir2_inc *=dim[0];
  if (dir[2]>=2) dir2_inc *=dim[1];

  int p0_min  = extent.GetMin(dir[0]);
  int p0_max  = extent.GetMax(dir[0]);
  int p1_min  = extent.GetMin(dir[1]);
  int p1_max  = extent.GetMax(dir[1]);
  int p2_min  = extent.GetMin(dir[2]);
  int p2_max  = extent.GetMax(dir[2]);

  int p2_size = extent.GetSize(dir[2]);

  T* in_data  = (T*) in ->GetData();
  T* out_data = (T*) out->GetData();

  FVector<float,short> vmin( dim[0]);
  FVector<float,short> vmax( dim[0]);
  FVector<float,short> vres( dim[0]);

  // along dir0
  for ( p0=p0_min; p0<=p0_max; p0++ )
  {
    //cout << "p0 = " << p0 << endl;
    p1 = p1_min;
    p2 = p2_min;
    long displ  = p2*dirinc[2] +p1*dirinc[1]+p0*dirinc[0];
    for ( ; p1<=p1_max; p1++, displ += dirinc[1] )
    {

      //cout << "p1 = " << p1 << endl;
      buf = bufmax = bufmin  = ( T* ) in_data  + displ;
      // begin of line within extent
      res_buf = ( T* ) out_data + displ;


      if (p2_size<=2*size+1) {
        // keep initial image
        for(p2=p2_min;p2<=p2_max;p2++) 
            *res_buf++  = *buf++;
      } else {
  
        register short p2_leftlimit  = p2_min+size;
        // we can compute up to dim2-1-size safely
        register short p2_rightlimit = p2_max-size;
  
        //---------- LEFT BOUNDARY
        // start at 0
        // we extend the boundaries
  
        bufmin    +=size;
        bufmax    +=size;
        *res_buf++ = *bufmax;
  
        register short pos;
        register short maxpos = p2_leftlimit+1;

        // go up to p2_leftlimit
        for (pos=p2_min+1;pos<maxpos;pos++)
          *res_buf++ = *++bufmax - *bufmin--;
        // at this point, bufmin points to the first pixel of the line
  
        //---------- CENTER

        maxpos = p2_rightlimit+1;
        bufmax++; 

        // go until alignment
        pos=p2_leftlimit+1;
        /*
        while (((unsigned long) res_buf & 15)&&(pos<maxpos)) {
          *res_buf++ = *bufmax++ - *bufmin++; 
          pos++;
        }
        */

        short vsize = ((maxpos-pos)/4)*4;
        vmin.CopyData(bufmin,vsize);
        vmax.CopyData(bufmax,vsize);
        vres.CopyData(res_buf,vsize);
        FVector_sub_float_sse_uua<float,short>(vmax,vmin,vres);
        bufmin  += vsize;
        bufmax  += vsize;
        res_buf += vsize;
        pos     += vsize;
        while (pos<maxpos) {
          *res_buf++ = *bufmax++ - *bufmin++; 
          pos++;
        }
/*
        // check remaining points
        for(pos=p2_leftlimit+1;pos+stepsize-1<maxpos;pos+=stepsize) {
          for(ns=0;ns<stepsize;ns++) {
           res_buf[ns] = bufmax[ns] - bufmin[ns]; 
          }
          res_buf+=stepsize;
          bufmax +=stepsize;
          bufmin +=stepsize;
        }
        while(pos++<maxpos) {
          *res_buf++ = *bufmax++ - *bufmin++; 
        }
*/
        bufmax--;

        //---------- RIGHT BOUNDARY

        // here bufmax should point to the last pixel of the line
        for(pos=p2_rightlimit+1;pos<=p2_max;pos++)
          *res_buf++ += *--bufmax - *bufmin++;
  
  
      } // end else, if dim2-1<=size

    } // for p1
  } // for p0

  END_TIMING

} // FastLocalDiffX<T>



template<class T,class TInc>
void FastLocalSumX_noborder( InrImage* in, InrImage* out, 
                      int size, 
                      const ImageExtent<int>& extent)
{

  START_TIMING(boost::format("%1%, %2%") 
                  % typeid(T).name() 
                  % typeid(TInc).name())

  int d = 2*size+1;
  float* in_buf;
  float* vmin_buf;
  float* vmax_buf;
  float* vres_buf;
  int new_size    = in->Size()-d;
  short i;

  short xmin = extent.GetMin(0);
  short xmax = extent.GetMax(0);
  short ymin = extent.GetMin(1);
  short ymax = extent.GetMax(1);
  short zmin = extent.GetMin(2);
  short zmax = extent.GetMax(2);

  // 2*size+1 needs to be smaller than the extent in X !!
  // now need to go line by line
  int x,y,z;
  float sum;
  for (z=zmin;z<=zmax;z++) {
    for (y=ymin;y<=ymax;y++) {
      // position buffers at the beginning of the lines
      out->BufferPos(xmin+size,y,z);
      vres_buf = (float*)out->BufferPtr();
      // initialize sum
      in->BufferPos(xmin,y,z);
      in_buf = (float*) in->BufferPtr();
      sum = 0;
      for(i=0;i<d;i++) sum += in_buf[i];
      // go through the line
      *vres_buf = sum; // sum from xmin to xmin+2*size included
      vres_buf++; // at xmin+size+1
      vmin_buf = in_buf;
      vmax_buf = in_buf+d;

      for(x=xmin+size+1;x<=xmax-size;x++) {
        sum += *vmax_buf++-*vmin_buf++;
        *vres_buf++ = sum;
      }

    }
  }

  END_TIMING

} // FastLocalSumX_noborder<T>


template<class T,class TInc>
void FastLocalSumY_noborder( InrImage* in, InrImage* out, 
                      int size, 
                      const ImageExtent<int>& extent)
{
  START_TIMING(boost::format("%1%, %2%") 
                  % typeid(T).name() 
                  % typeid(TInc).name())

  int d = 2*size+1;
  float* in_buf;
  float* vmin_buf;
  float* vmax_buf;
  float* vres_buf;
  int new_size    = in->Size()-d;
  short i;

  short xmin = extent.GetMin(0);
  short xmax = extent.GetMax(0);
  short ymin = extent.GetMin(1);
  short ymax = extent.GetMax(1);
  short zmin = extent.GetMin(2);
  short zmax = extent.GetMax(2);

  // 2*size+1 needs to be smaller and the extent in X !!
  // now need to go line by line
  int x,y,z;
  unsigned short incy = in->DimX(); // limit to approx. 64000 dim in X
  float sum[incy];

  for (z=zmin;z<=zmax;z++) {
    // initialize sums
    for(x=xmin;x<=xmax;x++) sum[x] = 0; // use memset here?
    for(i=0;i<d;i++) {
      in->BufferPos(0,ymin+i,z);
      in_buf = (float*) in->BufferPtr();
      for(x=xmin;x<=xmax;x++) {
        //if ((z==zmin)&&(x==xmin))
        // cout << boost::format(" value at %1% %2% %3% : %4%") % x % (ymin+i) % z % in_buf[x] << endl;
        sum[x] += in_buf[x];
      }
    }
    // initialize positions
    in->BufferPos(0,ymin,z);
    in_buf = (float*) in->BufferPtr();

    out->BufferPos(0,ymin+size,z); // hyp: ymin+size < ymax !!
    vres_buf = (float*)out->BufferPtr();

    // set values at ymin+size
    for(x=xmin;x<=xmax;x++) vres_buf[x] = sum[x];

    // increment positions
    vres_buf += incy; // at ymin+size+1
    vmin_buf = in_buf;
    vmax_buf = in_buf+d*incy;

    for (y=ymin+size+1;y<=ymax-size;y++) {
      for(x=xmin;x<=xmax;x++) {
        sum[x] += vmax_buf[x]-vmin_buf[x];
        vres_buf[x] = sum[x];
      }

      // move to next line
      vres_buf += incy;
      vmin_buf += incy;
      vmax_buf += incy;
    }
  }

  END_TIMING

} // FastLocalSumY_noborder<T>


template<class T,class TInc>
void FastLocalSumZ_noborder( InrImage* in, InrImage* out, 
                      int size, 
                      const ImageExtent<int>& extent,
                      const unsigned char& stepsize=4)
{
  START_TIMING(boost::format("%1%, %2%, x%3%") 
                  % typeid(T).name() 
                  % typeid(TInc).name()
                  % (int)stepsize)

  int d = 2*size+1;
  float* in_buf;
  float* vmin_buf;
  float* vmax_buf;
  float* vres_buf;
  float* vmin_buf1;
  float* vmax_buf1;
  float* vres_buf1;
  int new_size    = in->Size()-d;
  short i;

  short xmin = extent.GetMin(0);
  short xmax = extent.GetMax(0);
  short ymin = extent.GetMin(1);
  short ymax = extent.GetMax(1);
  short zmin = extent.GetMin(2);
  short zmax = extent.GetMax(2);

  // 2*size+1 needs to be smaller and the extent in X !!
  // now need to go line by line
  int x,y,z;
  unsigned short dx = in->DimX(); // limit to approx. 64000 dim in X
  unsigned short dy = in->DimY(); // limit to approx. 64000 dim in X


  int line_size = xmax-xmin+1;
  cout << "line_size = " << line_size << endl;
  // ensure multiple of 4 to help alignment of the beginning of each line
  line_size = floor(line_size/4)*4+4;
  cout << "line_size = " << line_size << endl;
  float sum[dy][line_size];

  for(y=ymin;y<=ymax;y++)
    for(x=xmin;x<=xmax;x++) sum[y][x] = 0; // use memset here?

  // initialize sums
  for(i=0;i<d;i++) {
    in->BufferPos(0,ymin,zmin+i);
    in_buf = (float*) in->BufferPtr();
    for(y=ymin;y<=ymax;y++) {
      float* sum1 = sum[y];
      for(x=xmin;x<=xmax;x++) *sum1++ += in_buf[x];
      in_buf += dx;
    } // y
  } // i

  out->BufferPos(0,ymin,zmin+size); // hyp: ymin+size < ymax !!
  vres_buf = (float*)out->BufferPtr();

  // set values at zmin+size
  for(y=ymin;y<=ymax;y++) {
    float* sum1      = sum[y];
    for(x=xmin;x<=xmax;x++)  vres_buf[x] = *sum1++;
    vres_buf += dx; // point to the beginning of next line
  } // y

  for (z=zmin+size+1;z<=zmax-size;z++) {

    // initialize positions
    in->BufferPos(0,ymin,z);
    in_buf = (float*) in->BufferPtr();

    vmin_buf = in_buf-(size+1)*dx*dy;          // at 0,ymin,zmin
    vmax_buf = in_buf+size*dx*dy;  // at 0,ymin,zmin+(2*size+1)

    out->BufferPos(0,ymin,z); 
    vres_buf = (float*)out->BufferPtr();

    for(y=ymin;y<=ymax;y++) {
      float* sum1      = sum[y];
      short xmax1=xmax-stepsize;
      unsigned char ns;
      x = xmin;
      vres_buf1=vres_buf;
      vmin_buf1=vmin_buf;
      vmax_buf1=vmax_buf;
      while(x<=xmax1) {
        for(ns=0;ns<stepsize;ns++) {
          *sum1 += *vmax_buf1++ - *vmin_buf1++;
          *vres_buf1++ = *sum1++;
        }
        x         += stepsize;
      }
      while(x<=xmax) {
        *sum1 += *vmax_buf1++ - *vmin_buf1++;
        *vres_buf1++ = *sum1++;
        x         ++;
      }
      vres_buf += dx; // point to the beginning of next line
      vmax_buf += dx;
      vmin_buf += dx;
    } // end for y
  } // end for z

  END_TIMING

} // FastLocalSumZ_noborder<T>

template<class T,class TInc>
void FastLocalSumX( InrImage* in, InrImage* out, 
                      int size, int axis, 
                      const ImageExtent<int>& extent,
                      const unsigned char& stepsize=4)
{

  START_TIMING(boost::format("%1%, %2%, stepsize %3% ") 
                  % typeid(T).name() 
                  % typeid(TInc).name()
                  % (int)stepsize )

  int       dim[3] = { in->DimX(), in->DimY(), in->DimZ() };
  int       dir[3];
  int       pos[3] = {0,0,0};
  unsigned char ns;

  T*        buf[stepsize];
  T*        bufmin[stepsize];
  T*        bufmax[stepsize];
  register T*        res_buf[stepsize];
  register float     sum[stepsize];
  int       num_values;

  // check that input and output are of the right type ???
  dir[0] = (axis+1)%3; // 1
  dir[1] = (axis+2)%3; // 2
  dir[2] = axis; // 0
  
  int dim0 = dim[dir[0]];
  int dim1 = dim[dir[1]];
  int dim2 = dim[dir[2]];

  int& p0 = pos[dir[0]];
  int& p1 = pos[dir[1]];
  int& p2 = pos[dir[2]];
  int  p;

  TInc dir2_inc = 1;
  if (dir[2]>=1) dir2_inc *=dim[0];
  if (dir[2]>=2) dir2_inc *=dim[1];

  int p0_min  = extent.GetMin(dir[0]);
  int p0_max  = extent.GetMax(dir[0]);
  int p1_min  = extent.GetMin(dir[1]);
  int p1_max  = extent.GetMax(dir[1]);
  int p2_min  = extent.GetMin(dir[2]);
  int p2_max  = extent.GetMax(dir[2]);

  int p2_size = extent.GetSize(dir[2]);

  T* in_data  = (T*) in ->GetData();
  T* out_data = (T*) out->GetData();

  // along dir0
  for ( p0=p0_min; p0<=p0_max; p0++ )
  {
    for ( p1=p1_min; p1+stepsize-1<=p1_max; p1+=stepsize )
    {
      p2 = p2_min;
      long displ  = (pos[2]*dim[1]+pos[1])*dim[0]+pos[0];

      for(ns=0;ns<stepsize;ns++) {
        buf[ns] = bufmax[ns] = bufmin[ns]  = ( T* ) in_data  + displ + ns*dim[1]*dim[0];
        // begin of line within extent
        res_buf[ns] = ( T* ) out_data + displ + ns*dim[1]*dim[0];
      }


      if (p2_size<=2*size+1) {
        // fill all values with mean*size
        for(ns=0;ns<stepsize;ns++) 
          sum[ns] = 0;
        for(p2=p2_min;p2<=p2_max;p2++) {
          for(ns=0;ns<stepsize;ns++) 
            sum[ns] += *buf[ns]++;
        }
        for(ns=0;ns<stepsize;ns++) 
          sum[ns]  = sum[ns]/dim2*(2*size+1.0); // rescale to size
        for(p2=p2_min;p2<=p2_max;p2++) {
          for(ns=0;ns<stepsize;ns++) 
            *res_buf[ns]++  = sum[ns];
        }
      } else {
  
        register unsigned short p2_leftlimit  = p2_min+size;
        // we can compute up to dim2-1-size safely
        register unsigned short p2_rightlimit = p2_max-size;
  
        // sum variable could cumulate numerical errors
        // 3 loops to deal with boundaries
  
        //---------- LEFT BOUNDARY
        // start at 0
        // we extend the boundaries
        for(ns=0;ns<stepsize;ns++) 
          sum[ns]        =  *bufmax[ns];
  
        for ( p=1; p<=size; p++ )
        {
          for(ns=0;ns<stepsize;ns++) {
            bufmin[ns]    ++;
            bufmax[ns]    ++;
            sum[ns] += *bufmin[ns] +*bufmax[ns];
          }
        } // for p
        for(ns=0;ns<stepsize;ns++) 
          *res_buf[ns]++ = sum[ns];
  
        register unsigned short pos;
        register unsigned short maxpos = p2_leftlimit+1;

        // go up to p2_leftlimit
        for (pos=p2_min+1;pos<maxpos;pos++)
        {
          for(ns=0;ns<stepsize;ns++) {
            bufmax[ns] ++;
            sum[ns] += *bufmax[ns] - *bufmin[ns];
            bufmin[ns] --;
            *res_buf[ns] = sum[ns];
            res_buf[ns] ++;
          }
        } // for p2 [0,p2_leftlimit]
        // at this point, bufmin points to the first pixel of the line
  
        //---------- CENTER


        pos=p2_leftlimit+1;
        maxpos = p2_rightlimit+1;
        for(ns=0;ns<stepsize;ns++) 
          bufmax[ns]++; 
        // check remaining points
        while(pos<maxpos)
        {
          for(ns=0;ns<stepsize;ns++) {
            sum[ns] += *bufmax[ns]++ - *bufmin[ns]++; 
            *res_buf[ns]++ = sum[ns]; 
          }
          pos++;
        } // while pos<maxpos
        for(ns=0;ns<stepsize;ns++) 
          bufmax[ns]--;

        //---------- RIGHT BOUNDARY

        // here bufmax should point to the last pixel of the line
        for(pos=p2_rightlimit+1;pos<=p2_max;pos++)
        {
          for(ns=0;ns<stepsize;ns++) {
            bufmax[ns] --;
            sum[ns] += *bufmax[ns] - *bufmin[ns];
            bufmin[ns] ++;
            *res_buf[ns]++ = sum[ns];
          }
        } // for p2 [p2_rightlimit,dim2-1]
  
  
      } // end else, if dim2-1<=size

    } // for p1
  } // for p0

  END_TIMING

} // FastLocalSumX<T>


//
// to speed-up, try to run on 4 rows at once ???
//
template<class T,class TInc>
void FastLocalSumDirNonX( InrImage* in, InrImage* out, 
                      int size, int axis, 
                      const ImageExtent<int>& extent,
                      const unsigned char& stepsize=8)
{

  char axis_name[3] = {'X','Y','Z'};
  START_TIMING(boost::format("%1%, %2%, axis %3% x%4%") 
                  % typeid(T).name() 
                  % typeid(TInc).name()
                  % axis_name[axis]
                  % (int) stepsize)

  int       dim[3] = { in->DimX(), in->DimY(), in->DimZ() };
  int       dir[3];
  int       pos[3] = {0,0,0};
  T*        buf;
  T*        bufmin;
  T*        bufmax;
  register T*        res_buf;

  register float    sum[stepsize]; // compute 4 sums in parallel

  register unsigned char ns;

  int       num_values;

  // check that input and output are of the right type ???
  dir[0] = (axis+1)%3; // Z
  dir[1] = (axis+2)%3;  // X
  dir[2] = axis;
  // force dir[1] to be X axis for optimization
  switch(axis) {
    case 1: dir[0] = 2; dir[1] = 0; break;
    case 2: dir[0] = 1; dir[1] = 0; break;
    default:
      cerr << __func__ << " axis should be 1 or 2 " << endl;
  }
  
  int dim0 = dim[dir[0]];
  int dim1 = dim[dir[1]];
  int dim2 = dim[dir[2]];

  int& p0 = pos[dir[0]];
  int& p1 = pos[dir[1]];
  int& p2 = pos[dir[2]];
  int  p;


  TInc dir2_inc = 1;
  if (dir[2]>=1) dir2_inc *=dim[0];
  if (dir[2]>=2) dir2_inc *=dim[1];

  int p0_min  = extent.GetMin(dir[0]);
  int p0_max  = extent.GetMax(dir[0]);
  int p1_min  = extent.GetMin(dir[1]);
  int p1_max  = extent.GetMax(dir[1]);
  int p2_min  = extent.GetMin(dir[2]);
  int p2_max  = extent.GetMax(dir[2]);

  int p2_size = extent.GetSize(dir[2]);

  T* in_data  = (T*) in ->GetData();
  T* out_data = (T*) out->GetData();

  // along dir0
  for ( p0=p0_min; p0<=p0_max; p0++ )
  {
    // do 4 rows at once ??
    for ( p1=p1_min; p1+stepsize-1<=p1_max; p1+=stepsize )
    {
      p2 = p2_min;
      in->BufferPos(pos[0],pos[1],pos[2]);
      buf = bufmax = bufmin  = ( T* ) in->BufferPtr();

      // begin of line within extent
      out->BufferPos(pos[0],pos[1],pos[2]);
      res_buf = ( T* ) out->BufferPtr();

      if (p2_size<=2*size+1) {
        // fill all values with mean*size

        for (ns=0;ns<stepsize;ns++) sum[ns] = 0;

        for(p2=p2_min;p2<=p2_max;p2++) {
          for (ns=0;ns<stepsize;ns++) sum[ns] += buf[ns];
          buf += dir2_inc;
        }
        for (ns=0;ns<stepsize;ns++)
          sum[ns] = sum[ns]/dim2*(2*size+1.0); // rescale to size
        for(p2=p2_min;p2<=p2_max;p2++) {
          for (ns=0;ns<stepsize;ns++) res_buf[ns] = sum[ns];
          res_buf += dir2_inc;
        }
      } else {
  
        register unsigned short p2_leftlimit  = p2_min+size;
        // we can compute up to dim2-1-size safely
        register unsigned short p2_rightlimit = p2_max-size;
  
        // sum variable could cumulate numerical errors
        // 3 loops to deal with boundaries
  
        //---------- LEFT BOUNDARY
        // start at 0
        // we extend the boundaries
        for (ns=0;ns<stepsize;ns++)
          sum[ns]        =  bufmax[ns];
  
        for ( p=1; p<=size; p++ )
        {
            bufmin    += dir2_inc; // mirror 
            bufmax    += dir2_inc; 
            for (ns=0;ns<stepsize;ns++)
              sum[ns] += bufmin[ns]+bufmax[ns];
        } // for p
        for (ns=0;ns<stepsize;ns++)
          res_buf[ns] = sum[ns];
        res_buf += dir2_inc;
  
        register unsigned short pos;
        register unsigned short maxpos = p2_leftlimit+1;

        // go up to p2_leftlimit
        for (pos=p2_min+1;pos<maxpos;pos++)
        {
          bufmax += dir2_inc; 
          for (ns=0;ns<stepsize;ns++) {
            sum[ns] += bufmax[ns] - bufmin[ns];
            res_buf[ns] = sum[ns];
          }
          bufmin -= dir2_inc; // - because of mirror
          res_buf += dir2_inc;
        } // for p2 [0,p2_leftlimit]
        // at this point, bufmin points to the first pixel of the line
  
        //---------- CENTER

        // do loop unrolling here ??

        pos=p2_leftlimit+1;
        maxpos = p2_rightlimit+1; 
        // manual unroll x10
        // check remaining points
        while(pos<maxpos)
        {
          bufmax += dir2_inc; 
          for (ns=0;ns<stepsize;ns++) {
            sum[ns] += bufmax[ns] - bufmin[ns]; 
            res_buf[ns] = sum[ns]; 
          }
          bufmin += dir2_inc; 
          res_buf += dir2_inc; 
          pos++;
        } // while pos<maxpos

        //---------- RIGHT BOUNDARY

        // here bufmax should point to the last pixel of the line
        for(pos=p2_rightlimit+1;pos<=p2_max;pos++)
        {
          bufmax -= dir2_inc; // mirror boundary
          for (ns=0;ns<stepsize;ns++) {
            sum[ns] += bufmax[ns] - bufmin[ns];
            res_buf[ns] = sum[ns];
          }
          bufmin += dir2_inc;
          res_buf += dir2_inc;
        } // for p2 [p2_rightlimit,dim2-1]
  
  
      } // end else, if dim2-1<=size

    } // for p1
  } // for p0

  END_TIMING

} // FastLocalSumDirNonX<T>


//------------------------------------------------------------------------------
template<class T>
void FastLocalSumDirNonX( InrImage* in, InrImage* out, 
                      int size, int axis, 
                      const ImageExtent<int>& extent)
{
  //START_TIMING(boost::format("%1%, %2%") 
  //                % typeid(T).name() )

  // 1. check increment value
  if (axis==0) {
    cerr << "\t Calling FastLocalSumDirNonX along X axis ! cancelled ..." << endl;
    return;
  }
  long inc = in->DimX();
  if (axis>1) inc *= in->DimY();

  if (inc <= std::numeric_limits<unsigned char>::max()+1) 
    FastLocalSumDirNonX<T,unsigned char>(in,out,size,axis,extent);
  else
  if (inc <= std::numeric_limits<unsigned short>::max()+1) 
    FastLocalSumDirNonX<T,unsigned short>(in,out,size,axis,extent);
  else
  if (inc <= std::numeric_limits<unsigned int>::max()+1) 
    FastLocalSumDirNonX<T,unsigned int>(in,out,size,axis,extent);
  else
  if (inc <= std::numeric_limits<unsigned long>::max()+1) 
    FastLocalSumDirNonX<T,unsigned long>(in,out,size,axis,extent);

  //END_TIMING

} // FastLocalSumDirNonX<T>


//----------------------------------------------------------------------
template<class T,class TInc>
void FastLocalSumDir( InrImage* in, InrImage* out, 
                      int size, int axis, 
                      const ImageExtent<int>& extent)
{
  START_TIMING(boost::format("%1%, %2%") 
                  % typeid(T).name() 
                  % typeid(TInc).name())

  int       dim[3] = { in->DimX(), in->DimY(), in->DimZ() };
  int       dir[3];
  int       pos[3] = {0,0,0};
  T*        buf;
  T*        bufmin;
  T*        bufmax;
  register T*        res_buf;
  register double    sum;
  int       num_values;

  // check that input and output are of the right type ???
  dir[0] = (axis+1)%3;
  dir[1] = (axis+2)%3;
  dir[2] = axis;
  
  int dim0 = dim[dir[0]];
  int dim1 = dim[dir[1]];
  int dim2 = dim[dir[2]];

  int& p0 = pos[dir[0]];
  int& p1 = pos[dir[1]];
  int& p2 = pos[dir[2]];
  int  p;

  TInc dir2_inc = 1;
  if (dir[2]>=1) dir2_inc *=dim[0];
  if (dir[2]>=2) dir2_inc *=dim[1];

  int p0_min  = extent.GetMin(dir[0]);
  int p0_max  = extent.GetMax(dir[0]);
  int p1_min  = extent.GetMin(dir[1]);
  int p1_max  = extent.GetMax(dir[1]);
  int p2_min  = extent.GetMin(dir[2]);
  int p2_max  = extent.GetMax(dir[2]);

  int p2_size = extent.GetSize(dir[2]);

  T* in_data  = (T*) in ->GetData();
  T* out_data = (T*) out->GetData();

  // along dir0
  for ( p0=p0_min; p0<=p0_max; p0++ )
  {
    for ( p1=p1_min; p1<=p1_max; p1++ )
    {
      p2 = p2_min;
      long displ = (pos[2]*dim[1]+pos[1])*dim[0]+pos[0];
      buf = bufmax = bufmin  = ( T* ) in_data  + displ;

      // begin of line within extent
      res_buf = ( T* ) out_data + displ;

      if (p2_size<=2*size+1) {
        // fill all values with mean*size
        sum = 0;
        for(p2=p2_min;p2<=p2_max;p2++) {
          sum += *buf;
          buf += dir2_inc;
        }
        sum = sum/dim2*(2*size+1.0); // rescale to size
        for(p2=p2_min;p2<=p2_max;p2++) {
          *res_buf = sum;
          res_buf += dir2_inc;
        }
      } else {
  
        register unsigned short p2_leftlimit  = p2_min+size;
        // we can compute up to dim2-1-size safely
        register unsigned short p2_rightlimit = p2_max-size;
  
        // sum variable could cumulate numerical errors
        // 3 loops to deal with boundaries
  
        //---------- LEFT BOUNDARY
        // start at 0
        // we extend the boundaries
        sum        =  *bufmax;
  
        for ( p=1; p<=size; p++ )
        {
            bufmin    += dir2_inc; // mirror 
            bufmax    += dir2_inc; 
            sum += *bufmin+*bufmax;
        } // for p
        *res_buf = sum;
        res_buf += dir2_inc;
  
        register unsigned short pos;
        register unsigned short maxpos = p2_leftlimit+1;

        // go up to p2_leftlimit
        for (pos=p2_min+1;pos<maxpos;pos++)
        {
          bufmax += dir2_inc; 
          sum += *bufmax - *bufmin;
          bufmin -= dir2_inc; // - because of mirror
          *res_buf = sum;
          res_buf += dir2_inc;
        } // for p2 [0,p2_leftlimit]
        // at this point, bufmin points to the first pixel of the line
  
        //---------- CENTER

        // do loop unrolling here ??
        #define ITERATE_CENTER  \
          bufmax += dir2_inc; \
          sum += *bufmax - *bufmin; \
          bufmin += dir2_inc; \
          *res_buf = sum; \
          res_buf += dir2_inc; \
          pos++;

        pos=p2_leftlimit+1;
        maxpos = p2_rightlimit+1; 
        // manual unroll x10
        /*
        while(pos+9<maxpos)
        {
          ITERATE_CENTER;
          ITERATE_CENTER;
          ITERATE_CENTER;
          ITERATE_CENTER;
          ITERATE_CENTER;
          ITERATE_CENTER;
          ITERATE_CENTER;
          ITERATE_CENTER;
          ITERATE_CENTER;
          ITERATE_CENTER;
        } // while pos+4<maxpos
        */
        // check remaining points
        while(pos<maxpos)
        {
          ITERATE_CENTER;
        } // while pos<maxpos

        //---------- RIGHT BOUNDARY

        // here bufmax should point to the last pixel of the line
        for(pos=p2_rightlimit+1;pos<=p2_max;pos++)
        {
          bufmax -= dir2_inc; // mirror boundary
          sum += *bufmax - *bufmin;
          bufmin += dir2_inc;
          *res_buf = sum;
          res_buf += dir2_inc;
        } // for p2 [p2_rightlimit,dim2-1]
  
  
      } // end else, if dim2-1<=size

    } // for p1
  } // for p0

  END_TIMING

} // FastLocalSumDir<T>


//------------------------------------------------------------------------------
template<class T>
void FastLocalSumDir( InrImage* in, InrImage* out, 
                      int size, int axis, 
                      const ImageExtent<int>& extent)
{
  //START_TIMING(boost::format("%1%, %2%") 
  //                % typeid(T).name() )

  // 1. check increment value
  long inc = 1;
  if (axis>0) inc *= in->DimX();
  if (axis>1) inc *= in->DimY();

  if (inc <= std::numeric_limits<unsigned char>::max()+1) 
    FastLocalSumDir<T,unsigned char>(in,out,size,axis,extent);
  else
  if (inc <= std::numeric_limits<unsigned short>::max()+1) 
    FastLocalSumDir<T,unsigned short>(in,out,size,axis,extent);
  else
  if (inc <= std::numeric_limits<unsigned int>::max()+1) 
    FastLocalSumDir<T,unsigned int>(in,out,size,axis,extent);
  else
  if (inc <= std::numeric_limits<unsigned long>::max()+1) 
    FastLocalSumDir<T,unsigned long>(in,out,size,axis,extent);

  //END_TIMING

} // FastLocalSumDir<T>


//--------------------------------------------------
// separable optimized version
// input
// res and tmp must be of the same type and dimensions
// that corresponds to the template parameter
template <class T>
void     Func_localsum( InrImage* im, InrImage*& res, 
                        InrImage*& tmp, int size,
                        ImageExtent<int>& extent)
{

  START_TIMING(boost::format("%1%") 
                  % typeid(T).name() )

  InrImage* tmp1;
  #define swap_pointers(p1,p2) \
    { tmp1=p1; p1 = p2; p2 = tmp1; }

  {
    if (im->GetFormat()==tmp->GetFormat()) {
      FastLocalDiffX<T,unsigned char>(im,res,size,0,extent,1);
      FastLocalSumX_noborder<T,unsigned char>(im,res,size,extent);
    }
    else {
      ( *tmp ) = ( *im );
      FastLocalDiffX<T,unsigned char>(tmp,res,size,0,extent,1);
      FastLocalSumX_noborder<T,unsigned char>(im,res,size,extent);
    }
  
  }

  {
    if (im->GetFormat()==tmp->GetFormat()) {
/*
      FastLocalSumX<T,unsigned char>(im,res,size,0,extent,32);
      FastLocalSumX<T,unsigned char>(im,res,size,0,extent,16);
      FastLocalSumX<T,unsigned char>(im,res,size,0,extent,8);
*/
      FastLocalSumX<T,unsigned char>(im,res,size,0,extent,4);
      FastLocalSumX<T,unsigned char>(im,res,size,0,extent,1);
    }
    else {
      ( *tmp ) = ( *im );
/*
//      FastLocalSumX<T,unsigned char>(im,res,size,0,extent,32);
      FastLocalSumX<T,unsigned char>(im,res,size,0,extent,16);
      FastLocalSumX<T,unsigned char>(im,res,size,0,extent,8);
*/
      FastLocalSumX<T,unsigned char>(im,res,size,0,extent,4);
      FastLocalSumX<T,unsigned char>(im,res,size,0,extent,1);
    }
  }

  {
    swap_pointers(tmp,res);

    FastLocalSumY_noborder<T,unsigned short>(im,res,size,extent);

//    FastLocalSumDirNonX<T,unsigned short>(tmp,res,size,1,extent,32);
    FastLocalSumDirNonX<T,unsigned short>(tmp,res,size,1,extent,16);
    FastLocalSumDirNonX<T,unsigned short>(tmp,res,size,1,extent,8);
/*
    FastLocalSumDirNonX<T,unsigned short>(tmp,res,size,1,extent,4);
    FastLocalSumDirNonX<T,unsigned short>(tmp,res,size,1,extent,1);
*/
  }

  if ( im->DimZ() >1 ) {
    swap_pointers(tmp,res);
    if (im->DimX()*im->DimY() <= std::numeric_limits<unsigned short>::max()+1) {

      FastLocalSumZ_noborder<T,unsigned short>(im,res,size,extent,16);
      FastLocalSumZ_noborder<T,unsigned short>(im,res,size,extent,8);
      FastLocalSumZ_noborder<T,unsigned short>(im,res,size,extent,4);
      FastLocalSumZ_noborder<T,unsigned short>(im,res,size,extent,1);

      FastLocalSumDirNonX<T,unsigned short>(tmp,res,size,2,extent,64);
      FastLocalSumDirNonX<T,unsigned short>(tmp,res,size,2,extent,32);
      FastLocalSumDirNonX<T,unsigned short>(tmp,res,size,2,extent,16);
      FastLocalSumDirNonX<T,unsigned short>(tmp,res,size,2,extent,8);
      FastLocalSumDirNonX<T,unsigned short>(tmp,res,size,2,extent,4);
      FastLocalSumDirNonX<T,unsigned short>(tmp,res,size,2,extent,1);
    }
    else {
      FastLocalSumZ_noborder<T,unsigned int>(im,res,size,extent,16);
      FastLocalSumZ_noborder<T,unsigned int>(im,res,size,extent,8);
      FastLocalSumZ_noborder<T,unsigned int>(im,res,size,extent,4);
      FastLocalSumZ_noborder<T,unsigned int>(im,res,size,extent,1);

      FastLocalSumDirNonX<T,unsigned int>(tmp,res,size,2,extent,64);
      FastLocalSumDirNonX<T,unsigned int>(tmp,res,size,2,extent,32);
      FastLocalSumDirNonX<T,unsigned int>(tmp,res,size,2,extent,16);
      FastLocalSumDirNonX<T,unsigned int>(tmp,res,size,2,extent,8);
      FastLocalSumDirNonX<T,unsigned int>(tmp,res,size,2,extent,4);
      FastLocalSumDirNonX<T,unsigned int>(tmp,res,size,2,extent,1);
    }
  }

  END_TIMING
}


//--------------------------------------------------
// separable optimized version with smart pointers
// using temporary image as input
// res and tmp must be of the same type and dimensions
// that corresponds to the template parameter
template <class T>
void     Func_localsum( InrImage::ptr& tmp, InrImage::ptr& res, 
                        int size, ImageExtent<int>& extent)
{
  FastLocalSumDir<T>(tmp.get(),res.get(),size,0,extent);

  tmp.swap(res);
  FastLocalSumDirNonX<T>(tmp.get(),res.get(),size,1,extent,16);

  if ( tmp->DimZ() >1 ) {
    tmp.swap(res);
      FastLocalSumDirNonX<T>(tmp.get(),res.get(),size,2,extent,16);
  }

}

