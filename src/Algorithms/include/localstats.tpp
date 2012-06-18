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

#include <boost/scoped_array.hpp>

// TODO: BufferPos() NOT THREAD SAFE !!!! try to fix it in the future

/*
  sum squared neighborhoods of size (2*size+1)
  along one axis
  could add   boundary_cond: 0 mirror
                             1 extension
  only mirror boundaries at the moment
*/

#ifdef AMI_USE_OPENMP
  #include <omp.h>
#endif

#include "Timing.hpp"
#include "amilab_messages.h"

#include "FastVector.hpp"

/*
#include "Timing.hpp"
extern Timing localmeanX;
extern Timing localmeanY;
extern Timing localmeanZ;
*/

//#define USE_TIMING 

#ifdef USE_TIMING 
  #define START_TIMING( message ) \
      std::string timing_mess = (boost::format("%1% %2%") % __func__ % (message).str()).str(); \
      Timing timer(timing_mess); \
      timer.Debut(); 
  
/*
  #define END_TIMING \
      timer.Fin(); \
      timer.AddCumul(); \
      timer.AfficheCumul(cout); 
*/

  #define END_TIMING(imsize) \
      timer.Fin(); \
      timer.AddCumul(); \
      timer.AfficheCumul(cout); \
     std::cout << " Time per million voxels: "; \
     std::cout << timer.GetCumulTimer()/(1.0*imsize)*1000000; \
     std::cout << std::endl;
/*\
     std::cout << " Time per million voxels: " \
          << timer.GetCumulTimer()/(1.0*imsize)*1000000 \
          << " /Megavoxel"<< end;
*/
#else
  #define START_TIMING(  message ) 
  #define END_TIMING( imsize )
#endif


template<class T,class TInc>
void FastLocalDiffX( InrImage* in, InrImage* out, 
                      int size, int axis, 
                      const ami::ImageExtent<int>& extent,
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

  amilab::ami_FVector<float,short> vmin( dim[0]);
  amilab::ami_FVector<float,short> vmax( dim[0]);
  amilab::ami_FVector<float,short> vres( dim[0]);

  // along dir0
  for ( p0=p0_min; p0<=p0_max; p0++ )
  {
    //cout << "p0 = " << p0 << std::endl;
    p1 = p1_min;
    p2 = p2_min;
    long displ  = p2*dirinc[2] +p1*dirinc[1]+p0*dirinc[0];
    for ( ; p1<=p1_max; p1++, displ += dirinc[1] )
    {

      //cout << "p1 = " << p1 << std::endl;
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
        #ifdef AMI_USE_SSE
          amilab::FVector_sub_float_sse_uua<float,short>(vmax,vmin,vres);
        #else
          amilab::FVector_sub<float,short>(vmax,vmin,vres);
        #endif
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

  END_TIMING(extent.GetNbVoxels())

} // FastLocalDiffX<T>



template<class T,class TInc>
void FastLocalSumX_noborder( InrImage* in, InrImage* out, 
                              int size, 
                              const ami::ImageExtent<int>& input_extent,
                              const ami::ImageExtent<int>& output_extent
                            )
{

  START_TIMING(boost::format("%1%, %2%") 
                  % typeid(T).name() 
                  % typeid(TInc).name())

  int d = 2*size+1;
  T* in_buf;
  T* vmin_buf;
  T* vmax_buf;
  T* vres_buf;
  // int new_size    = in->Size()-d;
  short i;

  short xmin = output_extent.GetMin(0);
  short xmax = output_extent.GetMax(0);
  short ymin = output_extent.GetMin(1);
  short ymax = output_extent.GetMax(1);
  short zmin = output_extent.GetMin(2);
  short zmax = output_extent.GetMax(2);

  // limits in the input image
  short xmin_input = macro_max(input_extent.GetMin(0),xmin-size);
  short xmax_input = macro_min(input_extent.GetMax(0),xmax+size);

  //cout << "xmin_input=" << xmin_input << ", xmin=" << xmin << std::endl;
  //cout << "xmax_input=" << xmax_input << ", xmax=" << xmax << std::endl;

  // 2*size+1 needs to be smaller than the extent in X !!
  // now need to go line by line
  int x,y,z;
  double sum;
  for (z=zmin;z<=zmax;z++) {
    for (y=ymin;y<=ymax;y++) {
      // position buffers at the beginning of the lines
      vres_buf = (T*)out->BufferPtr(xmin,y,z);

      // initialize sum
      in_buf = (T*) in->BufferPtr(xmin_input,y,z);
      sum = 0;
      for(i=0;i<d;i++) sum += in_buf[i];
      // go through the line

      for(i=xmin;i<=xmin_input+size;i++)
        *vres_buf++ = sum; // sum is from xmin_input to xmin_input+2*size included

      //vres_buf at xmin_input+size+1
      vmin_buf = in_buf; // xmin_input
      vmax_buf = in_buf+d; // xmin_input+2*size+1

      for(x=xmin_input+size+1;x<=xmax_input-size;x++) {
        sum += *vmax_buf++-*vmin_buf++;
        *vres_buf++ = sum;
      }

      // extend the value up to xmax
      while(x<=xmax) {
        *vres_buf++ = sum; 
        x++;
      }
    } // end for y
  } // end for z

  END_TIMING(extent.GetNbVoxels())

} // FastLocalSumX_noborder<T>


template<class T,class TInc>
void FastLocalMeanX_noborder( InrImage* in, InrImage* out, 
                      const unsigned char size, 
                      const ami::ImageExtent<int>& extent)
{

  START_TIMING(boost::format("%1%, %2%") 
                  % typeid(T).name() 
                  % typeid(TInc).name())

  register const unsigned char d = 2*size+1;
  T* in_buf;
  T* vmin_buf;
  T* vmax_buf;
  T* vres_buf;
  // int new_size    = in->Size()-d;
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
  double sum;
  for (z=zmin;z<=zmax;z++) {
    for (y=ymin;y<=ymax;y++) {
      // position buffers at the beginning of the lines
      vres_buf = (float*)out->BufferPtr(xmin,y,z);
      // initialize sum
      in_buf = (float*) in->BufferPtr(xmin,y,z);
      sum = 0;
      for(i=0;i<d;i++) sum += in_buf[i];
      // go through the line

      for(i=0;i<=size;i++)
        *vres_buf++ = sum/d; // sum is from xmin to xmin+2*size included

      //vres_buf at xmin+size+1
      vmin_buf = in_buf;
      vmax_buf = in_buf+d;

      for(x=xmin+size+1;x<=xmax-size;x++) {
        sum += *vmax_buf++-*vmin_buf++;
        *vres_buf++ = sum/d;
      }

      // extend the value up to xmax
      while(x<=xmax) {
        *vres_buf++ = sum/d; 
        x++;
      }
    } // end for y
  } // end for z

  END_TIMING(extent.GetNbVoxels())

} // FastLocalMeanX_noborder<T>


template<class T,class TInc>
void FastLocalSumY_noborder( InrImage* in, InrImage* out, 
                      int size, 
                      const ami::ImageExtent<int>& input_extent,
                      const ami::ImageExtent<int>& output_extent,
                      const unsigned char& stepsize=4)
{
  START_TIMING(boost::format("%1%, %2%, x%3%") 
                  % typeid(T).name() 
                  % typeid(TInc).name()
                  % (int)stepsize)

  int d = 2*size+1;
  T* in_buf;
  T* vmin_buf;
  T* vmax_buf;
  T* vres_buf;
  // int new_size    = in->Size()-d;
  short i;

  short xmin = output_extent.GetMin(0);
  short xmax = output_extent.GetMax(0);
  short ymin = output_extent.GetMin(1);
  short ymax = output_extent.GetMax(1);
  short zmin = output_extent.GetMin(2);
  short zmax = output_extent.GetMax(2);

  // 2*size+1 needs to be smaller and the extent in X !!
  // now need to go line by line
  int x,y,z;
  unsigned short incy = in->DimX(); // limit to approx. 64000 dim in X
  boost::scoped_array<double> sum(new double[incy]);

  for (z=zmin;z<=zmax;z++) {
    // initialize sums
    for(x=xmin;x<=xmax;x++) sum[x] = 0; // use memset here?
    for(i=0;i<d;i++) {
      in_buf = (T*) in->BufferPtr(0,ymin+i,z);
      for(x=xmin;x<=xmax;x++) {
        //if ((z==zmin)&&(x==xmin))
        //std::cout << boost::format(" value at %1% %2% %3% : %4%") % x % (ymin+i) % z % in_buf[x] << std::endl;
        sum[x] += in_buf[x];
      }
    }
    // initialize positions
    in_buf = (T*) in->BufferPtr(0,ymin,z);

    vres_buf = (T*)out->BufferPtr(0,ymin,z);

    // set values at from ymin to ymin+size
    for (y=ymin;y<=ymin+size;y++) {
      for(x=xmin;x<=xmax;x++) {
        vres_buf[x] = sum[x];
        //if (vres_buf[x]<0) {std::cout << "*1";std::cout.flush(); }
      }
      vres_buf += incy; 
    }

    //vres_buf is  at ymin+size+1
    // increment positions
    vmin_buf = in_buf;
    vmax_buf = in_buf+d*incy;

    for (y=ymin+size+1;y<=ymax-size;y++) {
      for(x=xmin;x<=xmax;x++) {
        sum[x] += vmax_buf[x]-vmin_buf[x];
        vres_buf[x] = sum[x];
       //if (vres_buf[x]<0) { 
       //  std::cout << boost::format("%1%,%2%,%3%-->%4%") % x % y % z % vres_buf[x] << std::endl; 
       //  std::cout.flush();
       // }
      }

/*
      float* sum1      = sum;
      short xmax1=xmax-stepsize;
      unsigned char ns;
      x = xmin;
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
*/
      // move to next line
      vres_buf += incy;
      vmin_buf += incy;
      vmax_buf += incy;
    } // end for y

    // extends to ymax
    while (y<=ymax) {
      for(x=xmin;x<=xmax;x++) {
        vres_buf[x] = sum[x];
        //if (vres_buf[x]<0) {std::cout << "*3";std::cout.flush(); }
      }
      vres_buf += incy; 
      y++;
    }

  } // end for z

//  END_TIMING
  END_TIMING(extent.GetNbVoxels())

} // FastLocalSumY_noborder<T>


template<class T,class TInc>
void FastLocalSumZ_noborder( InrImage* in, InrImage* out, 
                      int size, 
                      const ami::ImageExtent<int>& extent,
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
  //int new_size    = in->Size()-d;
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
  //cout << "line_size = " << line_size << std::endl;
  // ensure multiple of 4 to help alignment of the beginning of each line
  line_size = floor((double)((line_size+3.0)/4.0))*4;
  //cout << "line_size = " << line_size << std::endl;
  double** sum;
  // allocation of sum
  sum = new double*[dy];
  for(int k=0;k<dy;k++) {
	sum[k] = new double[line_size];
  }

  for(y=ymin;y<=ymax;y++)
    for(x=xmin;x<=xmax;x++) sum[y][x-xmin] = 0; // use memset here?

  // initialize sums
  for(i=0;i<d;i++) {
    in_buf = (float*) in->BufferPtr(0,ymin,zmin+i);
    for(y=ymin;y<=ymax;y++) {
      double* sum1 = sum[y];
      for(x=xmin;x<=xmax;x++) *sum1++ += in_buf[x];
      in_buf += dx;
    } // y
  } // i

  vres_buf = (float*)out->BufferPtr(0,ymin,zmin+size);

  // set values at zmin+size
  for(y=ymin;y<=ymax;y++) {
    double* sum1      = sum[y];
    for(x=xmin;x<=xmax;x++)  vres_buf[x] = *sum1++;
    vres_buf += dx; // point to the beginning of next line
  } // y

  for (z=zmin+size+1;z<=zmax-size;z++) {

    // initialize positions
    in_buf = (float*) in->BufferPtr(0,ymin,z);

    vmin_buf = in_buf-(size+1)*dx*dy;          // at 0,ymin,zmin
    vmax_buf = in_buf+size*dx*dy;  // at 0,ymin,zmin+(2*size+1)

    vres_buf = (float*)out->BufferPtr(0,ymin,z);

    for(y=ymin;y<=ymax;y++) {
      double* sum1      = sum[y];
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

  // liberation of sum
  for(int k=0;k<dy;k++)	delete [] sum[k];
  delete [] sum;

//  END_TIMING
  END_TIMING(extent.GetNbVoxels())

} // FastLocalSumZ_noborder<T>


///
/// here iterate first on y then z and x
/// allowing to keep only 1 line in memory at a time
///
template<class T,class TInc>
void FastLocalSumZ_noborder_2( InrImage* in, InrImage* out, 
                      int size, 
                      const ami::ImageExtent<int>& input_extent,
                      const ami::ImageExtent<int>& output_extent,
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
  //int new_size    = in->Size()-d;
  short i;

  short xmin = output_extent.GetMin(0);
  short xmax = output_extent.GetMax(0);
  short ymin = output_extent.GetMin(1);
  short ymax = output_extent.GetMax(1);
  short zmin = output_extent.GetMin(2);
  short zmax = output_extent.GetMax(2);

  // 2*size+1 needs to be smaller and the extent in X !!
  // now need to go line by line
  short x,y,z;
  unsigned short dx = in->DimX(); // limit to approx. 64000 dim in X
  unsigned short dy = in->DimY(); // limit to approx. 64000 dim in X
  unsigned int dxy = dx*dy;

  int line_size = xmax-xmin+1;
  boost::scoped_array<double> sum(new double[line_size]);
  double* sum1;

  for(y=ymin;y<=ymax;y++) {

    for(x=0;x<line_size;x++)  sum[x] = 0; // use memset here?

    // initialize sums
    for(i=0;i<d;i++) {
      in_buf = (float*) in->BufferPtr(xmin,y,zmin+i);
      for(x=0;x<line_size;x++) sum[x] += in_buf[x];
    } // i
  
    // hyp: ymin+size < ymax !!
    vres_buf = (float*)out->BufferPtr(xmin,y,zmin);
  
    // set values at zmin+size
    for (z=zmin;z<=zmin+size;z++) {
      for(x=0;x<line_size;x++) vres_buf[x] = sum[x];
      vres_buf += dxy; 
    }

    // initialize positions
    in_buf = (float*) in->BufferPtr(xmin,y,zmin);

    vmin_buf = in_buf;          // at xmin,y,zmin
    vmax_buf = in_buf+d*dx*dy;  // at xmin,y,zmin+(2*size+1)

    // vres_buf is at 0,y,zmin+size+1

    short xmax1;
    unsigned char ns;

    for (z=zmin+size+1;z<=zmax-size;z++) {
      xmax1=xmax-stepsize;
      x = xmin;
      sum1 = sum.get();
      vres_buf1=vres_buf;
      vmin_buf1=vmin_buf;
      vmax_buf1=vmax_buf;
      while(x<=xmax1) {
        for(ns=0;ns<stepsize;ns++) {
          *sum1 += *(vmax_buf1++) - *(vmin_buf1++);
          *(vres_buf1++) = *(sum1++);
        }
        x += stepsize;
      }
      while(x<=xmax) {
        *sum1 += *(vmax_buf1++) - *(vmin_buf1++);
        *(vres_buf1++) = *(sum1++);
        x++;
      }
      vres_buf += dxy; // point to the beginning of next line
      vmax_buf += dxy;
      vmin_buf += dxy;
    } // end for z

    // set values at zmin+size
    while(z<=zmax) {
      for(x=0;x<line_size;x++) {
        vres_buf[x] = sum[x];
      }
      vres_buf += dxy; 
      z++;
    }

  } // end for y

//  END_TIMING
  END_TIMING(extent.GetNbVoxels())

} // FastLocalSumZ_noborder_2<T>


template<class T,class TInc>
void FastLocalSumX( InrImage* in, InrImage* out, 
                      int size, int axis, 
                      const ami::ImageExtent<int>& extent,
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

  boost::scoped_array<T*> buf(new T*[stepsize]);
  boost::scoped_array<T*> bufmin(new T*[stepsize]);
  boost::scoped_array<T*> bufmax(new T*[stepsize]);
  //T*        buf[stepsize];
  //T*        bufmin[stepsize];
  //T*        bufmax[stepsize];
  register boost::scoped_array<T*> res_buf(new T*[stepsize]);
  register boost::scoped_array<double> sum(new double[stepsize]);
  //register T*        res_buf[stepsize];
  //register float     sum[stepsize];
  //int       num_values;

  // check that input and output are of the right type ???
  dir[0] = (axis+1)%3; // 1
  dir[1] = (axis+2)%3; // 2
  dir[2] = axis; // 0
  
  //int dim0 = dim[dir[0]];
  //int dim1 = dim[dir[1]];
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

//  END_TIMING
  END_TIMING(extent.GetNbVoxels())

} // FastLocalSumX<T>


//
// to speed-up, try to run on 4 rows at once ???
//
template<class T,class TInc>
void FastLocalSumDirNonX( InrImage* in, InrImage* out, 
                      int size, int axis, 
                      const ami::ImageExtent<int>& extent,
                      const unsigned char& stepsize=8)
{

  //char axis_name[3] = {'X','Y','Z'};
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

  register boost::scoped_array<double> sum(new double[stepsize]);
  //register float    sum[stepsize]; // compute 4 sums in parallel

  register unsigned char ns;

  //int       num_values;

  // check that input and output are of the right type ???
  dir[0] = (axis+1)%3; // Z
  dir[1] = (axis+2)%3;  // X
  dir[2] = axis;
  // force dir[1] to be X axis for optimization
  switch(axis) {
    case 1: dir[0] = 2; dir[1] = 0; break;
    case 2: dir[0] = 1; dir[1] = 0; break;
    default:
      std::cerr << __func__ << " axis should be 1 or 2 " << std::endl;
  }
  
  //int dim0 = dim[dir[0]];
  //int dim1 = dim[dir[1]];
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

  //T* in_data  = (T*) in ->GetData();
  //T* out_data = (T*) out->GetData();

  // along dir0
  for ( p0=p0_min; p0<=p0_max; p0++ )
  {
    // do 4 rows at once ??
    for ( p1=p1_min; p1+stepsize-1<=p1_max; p1+=stepsize )
    {
      p2 = p2_min;
      buf = bufmax = bufmin  = ( T* ) in->BufferPtr(pos[0],pos[1],pos[2]);

      // begin of line within extent
      res_buf = ( T* ) out->BufferPtr(pos[0],pos[1],pos[2]);

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

//  END_TIMING
  END_TIMING(extent.GetNbVoxels())

} // FastLocalSumDirNonX<T>


//------------------------------------------------------------------------------
template<class T>
void FastLocalSumDirNonX( InrImage* in, InrImage* out, 
                      int size, int axis, 
                      const ami::ImageExtent<int>& extent,
                      const unsigned char& stepsize=8
                      )
{
  //START_TIMING(boost::format("%1%, %2%") 
  //                % typeid(T).name() )

  // 1. check increment value
  if (axis==0) {
    std::cerr << "\t Calling FastLocalSumDirNonX along X axis ! cancelled ..." << std::endl;
    return;
  }
  long inc = in->DimX();
  if (axis>1) inc *= in->DimY();

#ifdef max
#undef max
#endif

  if (inc <= std::numeric_limits<unsigned char>::max()+1) 
    FastLocalSumDirNonX<T,unsigned char>(in,out,size,axis,extent,stepsize);
  else
  if (inc <= std::numeric_limits<unsigned short>::max()+1) 
    FastLocalSumDirNonX<T,unsigned short>(in,out,size,axis,extent,stepsize);
  else
  if (inc <= std::numeric_limits<unsigned int>::max()+1) 
    FastLocalSumDirNonX<T,unsigned int>(in,out,size,axis,extent,stepsize);
  else
  if (inc <= std::numeric_limits<unsigned long>::max()+1) 
    FastLocalSumDirNonX<T,unsigned long>(in,out,size,axis,extent,stepsize);

  //END_TIMING

} // FastLocalSumDirNonX<T>


//----------------------------------------------------------------------
template<class T,class TInc>
void FastLocalSumDir( InrImage* in, InrImage* out, 
                      int size, int axis, 
                      const ami::ImageExtent<int>& extent)
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
  //int       num_values;

  // check that input and output are of the right type ???
  dir[0] = (axis+1)%3;
  dir[1] = (axis+2)%3;
  dir[2] = axis;
  
  //int dim0 = dim[dir[0]];
  //int dim1 = dim[dir[1]];
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

//  END_TIMING
  END_TIMING(extent.GetNbVoxels())

} // FastLocalSumDir<T>


//------------------------------------------------------------------------------
template<class T>
void FastLocalSumDir( InrImage* in, InrImage* out, 
                      int size, int axis, 
                      const ami::ImageExtent<int>& extent)
{
  START_TIMING(boost::format("%1% size = %2%, axis = %3%") 
                  % typeid(T).name() % size % axis)

  // 1. check increment value
  long inc = 1;
  if (axis>0) inc *= in->DimX();
  if (axis>1) inc *= in->DimY();

  if (inc <= std::numeric_limits<unsigned char>::max()) 
    FastLocalSumDir<T,unsigned char>(in,out,size,axis,extent);
  else
  if (inc <= std::numeric_limits<unsigned short>::max()) 
    FastLocalSumDir<T,unsigned short>(in,out,size,axis,extent);
  else
  if (inc <= (long) std::numeric_limits<unsigned int>::max()) 
    FastLocalSumDir<T,unsigned int>(in,out,size,axis,extent);
  else // long is maximum here
    FastLocalSumDir<T,long>(in,out,size,axis,extent);

//  END_TIMING
  END_TIMING(extent.GetNbVoxels())

} // FastLocalSumDir<T>


//--------------------------------------------------
// separable optimized version
// input
// res and tmp must be of the same type and dimensions
// that corresponds to the template parameter
template <class T>
void     Func_localsum( InrImage* im, InrImage*& res, 
                        InrImage*& tmp, int size,
                        ami::ImageExtent<int>& extent)
{

  START_TIMING(boost::format("%1%") 
                  % typeid(T).name() )

  InrImage* tmp1;
  #define swap_pointers(p1,p2) \
    { tmp1=p1; p1 = p2; p2 = tmp1; }

  if (im->GetFormat()==tmp->GetFormat()) {
    FastLocalSumX_noborder<T,unsigned char>(im,res,size,extent,extent);
  }
  else {
    ( *tmp ) = ( *im );
    FastLocalSumX_noborder<T,unsigned char>(tmp,res,size,extent,extent);
  }

  swap_pointers(tmp,res);
  FastLocalSumY_noborder<T,unsigned short>(tmp,res,size,extent,extent);

  if ( im->DimZ() >1 ) {
    swap_pointers(tmp,res);
    if (im->DimX()*im->DimY() <= std::numeric_limits<unsigned short>::max()) {
      FastLocalSumZ_noborder_2<T,unsigned short>(tmp,res,size,extent,extent,8); 
    }
    else {
      FastLocalSumZ_noborder_2<T,unsigned int>(tmp,res,size,extent,extent,8);
    }
  }

/*
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
     // FastLocalSumX<T,unsigned char>(im,res,size,0,extent,32);
     // FastLocalSumX<T,unsigned char>(im,res,size,0,extent,16);
     // FastLocalSumX<T,unsigned char>(im,res,size,0,extent,8);
      FastLocalSumX<T,unsigned char>(im,res,size,0,extent,4);
      FastLocalSumX<T,unsigned char>(im,res,size,0,extent,1);
    }
    else {
      ( *tmp ) = ( *im );
      //FastLocalSumX<T,unsigned char>(im,res,size,0,extent,32);
      //FastLocalSumX<T,unsigned char>(im,res,size,0,extent,16);
      FastLocalSumX<T,unsigned char>(im,res,size,0,extent,8);
      FastLocalSumX<T,unsigned char>(im,res,size,0,extent,4);
      FastLocalSumX<T,unsigned char>(im,res,size,0,extent,1);
    }
  }

  {
    swap_pointers(tmp,res);

    FastLocalSumY_noborder<T,unsigned short>(im,res,size,extent);

    //FastLocalSumDirNonX<T,unsigned short>(tmp,res,size,1,extent,32);
    FastLocalSumDirNonX<T,unsigned short>(tmp,res,size,1,extent,16);
    FastLocalSumDirNonX<T,unsigned short>(tmp,res,size,1,extent,8);
    //FastLocalSumDirNonX<T,unsigned short>(tmp,res,size,1,extent,4);
    //FastLocalSumDirNonX<T,unsigned short>(tmp,res,size,1,extent,1);
  }

  if ( im->DimZ() >1 ) {
    swap_pointers(tmp,res);
    if (im->DimX()*im->DimY() <= std::numeric_limits<unsigned short>::max()+1) {

      FastLocalSumZ_noborder<T,unsigned short>(im,res,size,extent,16);
      FastLocalSumZ_noborder<T,unsigned short>(im,res,size,extent,8);
      FastLocalSumZ_noborder<T,unsigned short>(im,res,size,extent,4);
      FastLocalSumZ_noborder<T,unsigned short>(im,res,size,extent,1);

     FastLocalSumZ_noborder_2<T,unsigned short>(im,res,size,extent,16);
      FastLocalSumZ_noborder_2<T,unsigned short>(im,res,size,extent,8);
      FastLocalSumZ_noborder_2<T,unsigned short>(im,res,size,extent,4);
      FastLocalSumZ_noborder_2<T,unsigned short>(im,res,size,extent,1);
 
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

      FastLocalSumZ_noborder_2<T,unsigned int>(im,res,size,extent,16);
      FastLocalSumZ_noborder_2<T,unsigned int>(im,res,size,extent,8);
      FastLocalSumZ_noborder_2<T,unsigned int>(im,res,size,extent,4);
      FastLocalSumZ_noborder_2<T,unsigned int>(im,res,size,extent,1);

      FastLocalSumDirNonX<T,unsigned int>(tmp,res,size,2,extent,64);
      FastLocalSumDirNonX<T,unsigned int>(tmp,res,size,2,extent,32);
      FastLocalSumDirNonX<T,unsigned int>(tmp,res,size,2,extent,16);
      FastLocalSumDirNonX<T,unsigned int>(tmp,res,size,2,extent,8);
      FastLocalSumDirNonX<T,unsigned int>(tmp,res,size,2,extent,4);
      FastLocalSumDirNonX<T,unsigned int>(tmp,res,size,2,extent,1);
    }
  }
*/
//  END_TIMING
  END_TIMING(extent.GetNbVoxels())
}


//--------------------------------------------------
// separable optimized version with smart pointers
// using temporary image as input
// res and tmp must be of the same type and dimensions
// that corresponds to the template parameter
template <class T>
void     Func_localsum( InrImage::ptr& tmp, InrImage::ptr& res, 
                        int size,
                        ami::ImageExtent<int>& input_extent,
                        ami::ImageExtent<int>& output_extent
                      )
{

/*
  FastLocalSumDir<T>(tmp.get(),res.get(),size,0,extent);

  tmp.swap(res);
  FastLocalSumDirNonX<T>(tmp.get(),res.get(),size,1,extent,16);

  if ( tmp->DimZ() >1 ) {
    tmp.swap(res);
      FastLocalSumDirNonX<T>(tmp.get(),res.get(),size,2,extent,16);
  }
*/
  //input_extent.print();
  //output_extent.print();
  ami::ImageExtent<int> Xoutputextent(input_extent);
  // only set the output extent for X direction
  Xoutputextent.SetMinMax(0,output_extent.GetMin(0),output_extent.GetMax(0));
  FastLocalSumX_noborder<T,unsigned char>(  tmp.get(),res.get(),size,
                                            input_extent,Xoutputextent);

  ami::ImageExtent<int> Youtputextent(Xoutputextent);
  // set the output extent for y direction
  Youtputextent.SetMinMax(1,output_extent.GetMin(1),output_extent.GetMax(1));

  tmp.swap(res);
  FastLocalSumY_noborder<T,unsigned short>( tmp.get(),res.get(),size,
                                            Xoutputextent,
                                            Youtputextent);

  if ( tmp->DimZ() >1 ) {
    tmp.swap(res);
    if (tmp->DimX()*tmp->DimY() <= std::numeric_limits<unsigned short>::max()) {
      FastLocalSumZ_noborder_2<T,unsigned short>(tmp.get(),res.get(),size,
                          Youtputextent,output_extent,8); 
    }
    else {
      FastLocalSumZ_noborder_2<T,unsigned int>(tmp.get(),res.get(),size,
                          Youtputextent,output_extent,8);
    }
  }

}

