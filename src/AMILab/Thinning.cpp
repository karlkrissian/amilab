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


#include "vtkMinHeap.h"

#include "style.hpp"
#include "inrimage.hpp"

#include "Coordonnees.hpp"


static int N26_star[27][27]; // 26 adjacent neighbors for each point in 
                             // the N26* neighborhood:
                             // N26_star[i][0] = number of neighbors

static int N18[27][27]; // 6 adjacent neighbors for each point in 
                        // the N18 neighborhood:
                        // N18[i][0] = number of neighbors

static int pos[3][3][3];
static int neighbors_pos  [27];
static int neighbors_place[27][3];


static unsigned char IsSimple( InrImage* im, int x, int y, int z, int& cc1, int& cc2);

//----------------------------------------------------------------------
//
class TrialPoint {

public:
  int   x,y,z;
  float value;

  TrialPoint()
  {
    x = y = z = 0;
    value = 1000;
  }

  TrialPoint(int px, int py, int pz, float val)
  {
    x     = px;
    y     = py;
    z     = pz;
    value = val;
  }

  TrialPoint& operator=(const TrialPoint& p)
  {
    x     = p.x;
    y     = p.y;
    z     = p.z;
    value = p.value;
    return *this;
  }


  friend int operator < ( const TrialPoint& p1, const TrialPoint& p2)
  {
    return (p1.value < p2.value);
  }

  friend int operator > ( const TrialPoint& p1, const TrialPoint& p2)
  {
    return (p1.value > p2.value);
  }

  friend ostream& operator << (ostream&, const TrialPoint& p);

}; // TrialPoint


//----------------------------------------------------------------------
void Thin_init_pos( InrImage* im)
//   -------------
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

//----------------------------------------------------------------------
void init_neighborhoods()
//   ------------------
{

  
    int i,j,k;
    int i1,j1,k1;
    int n,nb1,nb2;
    unsigned char n1_ok,n2_ok;

  Pour(i,0,2)
  Pour(j,0,2)
  Pour(k,0,2)

    n  = pos[i][j][k];
    nb1 = 0;
    nb2 = 0;

    n1_ok = ((i!=1)||(j!=1)||(k!=1));
    n2_ok = ((i==1)||(j==1)||(k==1));

    Pour(i1,-1,1)
    Pour(j1,-1,1)
    Pour(k1,-1,1)

      if (i+i1<0) continue;
      if (j+j1<0) continue;
      if (k+k1<0) continue;

      if (i+i1>2) continue;
      if (j+j1>2) continue;
      if (k+k1>2) continue;

      if ((i1==0)&&(j1==0)&&(k1==0)) continue;
  
      if (n1_ok)
      if ((i+i1 != 1)||(j+j1 != 1)||(k+k1 != 1)) {
        nb1++;
        N26_star[n][nb1] = pos[i+i1][j+j1][k+k1];
      }

      if (n2_ok)
      if ((i+i1 == 1)||(j+j1 == 1)||(k+k1 == 1)) {
        if ( ((i1==0)&&((j1==0)||(k1==0))) || ((j1==0)&&(k1==0)) ) {
	  nb2++;
	  N18[n][nb2] = pos[i+i1][j+j1][k+k1];
	}
      }

    FinPour
    FinPour
    FinPour

    N26_star[n][0] = nb1;
    N18     [n][0] = nb2;

  FinPour
  FinPour
  FinPour

} // init_neighborhoods()


//----------------------------------------------------------------------
bool IsEndPointLine( InrImage* im, int x, int y, int z)
//      ----------
{
  
    int n,nb;
    int x1,y1,z1;

  Si Non((*im)(x,y,z)) AlorsFait return false;

  nb = 0;
  Pour(n,0,26)
    x1 = x+neighbors_place[n][0];
    y1 = y+neighbors_place[n][1];
    z1 = z+neighbors_place[n][2];
    
    Si im->CoordOK(x1,y1,z1) Et (*im)(x1,y1,z1)>0 AlorsFait nb++;
    Si nb>2 AlorsFait break;

  FinPour

  return (nb==2);

} // IsEndPointLine()


//--------------------------------------------------------------------------
//  Check if a point is a surface border point: 26-connected case
// Add an extra test to make sure it is not a line end point.
// we want only surfaces here...
//----------------------------------------------------------------------
bool IsEndPointSurface( InrImage* im, int x, int y, int z)
//      ----------
{

  int i, j, count = 0;
  int x1,y1,z1;
  int planes26[9][8][3]= {
    { {0, -1, -1}, {0, 0, -1}, {0, 1, -1}, {0, 1, 0},
      {0, 1, 1},   {0, 0, 1}, {0, -1, 1},  {0, -1, 0}
    },
    
    { {-1, 0, -1}, {0, 0, -1}, {1, 0, -1}, {1, 0, 0},  
      {1, 0, 1},   {0, 0, 1}, {-1, 0, 1},  {-1, 0, 0}
    },
    
    {
      {-1, -1, 0}, {0, -1, 0}, {1, -1, 0}, {1, 0, 0},
      {1, 1, 0}, {0, 1, 0}, {-1, 1, 0}, {-1, 0, 0}
    },
    
    {
      {-1, -1, -1}, {0, 0, -1}, {1, 1, -1}, {1, 1, 0},
      {1, 1, 1}, {0, 0, 1}, {-1, -1, 1},{-1, -1, 0} 
    },
    
    {
      {1, -1, -1}, {0, 0, -1}, {-1, 1, -1}, {-1, 1, 0},
      {-1, 1, 1}, {0, 0, 1}, {1, -1, 1}, {1, -1, 0}
    },
    
    {
      {-1, -1, -1}, {-1, 0, -1}, {-1, 1, -1}, {0, 1, 0}, 
      {1, 1, 1}, {1, 0, 1}, {1, -1, 1}, {0, -1, 0}
    },
    
    {
      {1, -1, -1}, {1, 0, -1}, {1, 1, -1}, {0, 1, 0}, 
      {-1, 1, 1},  {-1, 0, 1}, {-1, -1, 1},{0, -1, 0}
    },
    
    {
      {-1, -1, -1},{0, -1, -1},{1, -1, -1},{1, 0, 0},
      {1, 1, 1}, {0, 1, 1}, {-1, 1, 1}, {-1, 0, 0}
    },
    
    {
      {-1, 1, -1},{0, 1, -1},{1, 1, -1},{1, 0, 0},
      {1, -1, 1},{0, -1, 1},{-1, -1, 1}, {-1, 0, 0}
    }
  };
  
  if (!(*im)(x,y,z))            return false;
    
  for (j=0; j<9; j++) { 
    count = 0;
    for (i=0; i<8; i++) {
      x1=x+planes26[j][i][0]; 
      y1=y+planes26[j][i][1]; 
      z1=z+planes26[j][i][2];
      if (im->CoordOK(x1,y1,z1) && ((*im)(x1,y1,z1))>0) count++;
    }
    if (count==1) return true;
  }
  return false;

} // IsEndPointSurface()


//----------------------------------------------------------------------
bool IsEndPoint( InrImage* im, int x, int y, int z, int endpoint_type)
//            ----------
{
  
    bool ok = false;

  #define ENDPOINT_LINE    1
  #define ENDPOINT_SURFACE 2

  Si Non((*im)(x,y,z)) AlorsFait return false;

  if (endpoint_type & ENDPOINT_LINE)
    ok = IsEndPointLine(im,x,y,z);

  if (!ok && (endpoint_type & ENDPOINT_SURFACE))
    ok = (!IsEndPointLine(im,x,y,z)) & IsEndPointSurface(im,x,y,z);

  return ok;
}



//----------------------------------------------------------------------
InrImage* Func_SimplePoints( InrImage* im)
//        -----------------
{
  
    int        x,y,z;
    int        cc1,cc2;
    InrImage*  im_simple;


  im_simple  = new InrImage(WT_UNSIGNED_SHORT,"simple.ami.gz",im);

  im_simple->InitImage(0);
  
  im->InitBuffer();
  im_simple->InitBuffer();
  Pour(z,0,im->_tz-1)
  Pour(y,0,im->_ty-1)
  Pour(x,0,im->_tx-1)

    Si (im->ValeurBuffer()) Alors
      IsSimple(im,x,y,z,cc1,cc2);
      im_simple->FixeValeur( cc1+10*cc2);
    FinSi

    im_simple->IncBuffer();
    im->IncBuffer();

  FinPour
  FinPour
  FinPour

  return im_simple;

}

//----------------------------------------------------------------------
void ParseCC( int* domain, 
//   -------
	      int neighborhood[27][27], 
	      int* cc,
	      int point, 
	      int num_cc )
{

   
    int l;
    int neighbor;
    int list[27];
    int size;

  cc[point] = num_cc;
  list[0] = point;
  size = 1;

  while (size>0) {
    size--;
    point = list[size];
    
    Pour(l,1,neighborhood[point][0])
      neighbor = neighborhood[point][l];
      if ((domain[neighbor])&&(cc[neighbor] == 0)) {
        cc[neighbor] = num_cc;
	list[size]   = neighbor;
        size++;
      }
    FinPour
  }

} // ParseCC()

//----------------------------------------------------------------------
unsigned char IsSimple( InrImage* im, int x, int y, int z, int& cc1, int& cc2)
//      --------
{

  int cc[27];
  int i,j,k,n,n1;
  int nb_cc;
  int domain[27];

  // position of the points 6-adjacents to the central point
  int six_adj[6] = {4,10,12,14,16,22};

  cc1 = cc2 = 0;

  Si Non(im->CoordOK(x,y,z)) AlorsFait return false;

  // First Check: C*(P) = 1

  nb_cc = 0;

  Pour(n,0,26)
    cc[n] = 0;
  FinPour

  Pour(i,0,2)
  Pour(j,0,2)
  Pour(k,0,2)
    n = pos[i][j][k];
    if (im->CoordOK(x+i-1,y+j-1,z+k-1))
      domain[n] = (N26_star[n][0]) && 
	          ((*im)(x+i-1,y+j-1,z+k-1) );
    else
      domain[n] = 0;
  FinPour
  FinPour
  FinPour

  Pour(n,0,26)
    // if the point is in the domain
    // and is not yet connected: create new connex component
    if (( domain[n])&&(cc[n] == 0)) {
      nb_cc++;
      // Parse the connect component
      ParseCC(domain,N26_star,cc,n,nb_cc);
    }
  FinPour

  cc1 = nb_cc;
  if (nb_cc != 1) return 0;

  // Second Check: C-(P) = 1

  nb_cc = 0;

  Pour(n,0,26)
    cc[n] = 0;
  FinPour

  Pour(i,0,2)
  Pour(j,0,2)
  Pour(k,0,2)
    n = pos[i][j][k];
    if (im->CoordOK(x+i-1,y+j-1,z+k-1))
      domain[n] = (N18[n][0]) && 
	          (!(*im)(x+i-1,y+j-1,z+k-1) );
    else
      domain[n] = 0;
  FinPour
  FinPour
  FinPour

  Pour(n,0,5)
    n1 = six_adj[n];
    // if the point is in the domain
    // and is not yet connected: create new connex component
    if (( domain[n1]) && (cc[n1] == 0)) {
      nb_cc++;
      // Parse the connect component
      ParseCC(domain,N18,cc,n1,nb_cc);
    }
  FinPour

  cc2 = nb_cc;
  return (nb_cc == 1);

} // IsSimple()


//----------------------------------------------------------------------
InrImage* Func_Thinning( InrImage* im, InrImage* criterion, float min_threshold, float max_threshold, int endpoint_type) 
//        -------------
{

  
    InrImage*   res;
    int         x,y,z;
    int         x1,y1,z1;
    int         n;
    unsigned char     contour;
    TrialPoint  p;
    int         it;
    int         remove_number;
    int         cc1,cc2;
    InrImage*   im_heap;
    vtkMinHeap<TrialPoint>  heap;
    //    InrImage*   im_removed;
 
  Thin_init_pos( im);
  init_neighborhoods();

  res = new InrImage(WT_UNSIGNED_CHAR,"thinning.ami.gz",im);

  im_heap    = new InrImage(WT_UNSIGNED_SHORT,"heap.ami.gz",im);
  im_heap->InitImage(0);
  //  im_removed = new InrImage(WT_UNSIGNED_SHORT,"removed.ami.gz",im);
  //  im_removed->InitImage(0);


  res->InitBuffer();
  im->InitBuffer();
  Repeter
    if (im->ValeurBuffer()> 0)
      res->FixeValeur( 255);
    else
      res->FixeValeur( 0);
    res->IncBuffer();
  JusquA Non(im->IncBuffer()) FinRepeter


  // Initialize the heap to the contour point which are simple
  Pour(z,1,res->_tz-2)
  Pour(y,1,res->_ty-2)
    res->BufferPos(1,y,z);
    Pour(x,1,res->_tx-2)

      contour = false;
      if (res->ValeurBuffer()) {
        Pour(n,0,26)
          if (!(res->ValeurBuffer(neighbors_pos[n]))) {
            contour=true;
            break;
          }
        FinPour
      }
      Si (contour) Et IsSimple(res,x,y,z,cc1,cc2) Alors
        heap += TrialPoint(x,y,z, (*criterion)(x,y,z));
        im_heap->BufferPos(x,y,z);
        im_heap->FixeValeur(1);
      FinSi
      res->IncBuffer();
    FinPour
  FinPour
  FinPour



  it = 0;
  remove_number = 1;

  //
  while (heap.Size()>0) {

    it++;
    Si (it%10000==0) Alors
      if (it!=0) fprintf(stderr,"\b\b\b\b\b\b");
      fprintf(stderr,"%6d / %6d",it,heap.Size());
      fflush(stderr);
    FinSi

    /*
    Si (it<5) Alors
      sprintf(name,"heap_%02d.ami.gz",it);
      CreateHeapImage();
      im_heap->Sauve(name);

      sprintf(name,"simple_%02d.ami.gz",it);
      CreateSimpleImage( res);
      im_simple->Sauve(name);

      //    Sinon
      //      break;
    FinSi
    */

    p = heap.GetMin();
    if (p.value > max_threshold) break;

    Si IsSimple(res,p.x,p.y,p.z,cc1,cc2) Alors
      Si Non(IsEndPoint(res,p.x,p.y,p.z,endpoint_type)) Ou 
         (*criterion)(p.x,p.y,p.z) < min_threshold 
      Alors 
        // remove P
        res->BufferPos(p.x,p.y,p.z);
        res->FixeValeur(0);

        // set im_heap to 2 to say the point has already been parsed
        im_heap->BufferPos(p.x,p.y,p.z);
        im_heap->FixeValeur(2);

	//	im_removed->BufferPos(p.x,p.y,p.z);
	//	im_removed->FixeValeur(remove_number);
	//        remove_number++;

	// Add neighbors to the heap
        Pour(n,0,26)
	  x1 = p.x+neighbors_place[n][0];
          y1 = p.y+neighbors_place[n][1];
          z1 = p.z+neighbors_place[n][2];
          Si Non(res->CoordOK(x1,y1,z1)) AlorsFait continue;
          Si res->ValeurBuffer(neighbors_pos[n])==255 Alors
            Si ((*im_heap)(x1,y1,z1)==0) &&
	        IsSimple(res,x1,y1,z1,cc1,cc2)  
            Alors
    	      heap += TrialPoint(x1,y1,z1,(*criterion)(x1,y1,z1));
  	      im_heap->BufferPos(x1,y1,z1);
	      im_heap->FixeValeur(1);
            FinSi
          FinSi
        FinPour
      Sinon
        res->BufferPos(p.x,p.y,p.z);
        res->FixeValeur(127);
      FinSi
    Sinon
      // set im_heap to 2 to say the point has already been parsed
      im_heap->BufferPos(p.x,p.y,p.z);
      im_heap->FixeValeur(0);
    FinSi    

  }

  //  im_removed->Sauve();

  delete im_heap;
  //  delete im_removed;

  res      ->InitBuffer();
  criterion->InitBuffer();
  Pour(z,0,res->_tz-1)
  Pour(y,0,res->_ty-1)
  Pour(x,0,res->_tx-1)

    Si res->ValeurBuffer() Et criterion->ValeurBuffer()>max_threshold Alors
      res->FixeValeur(0);
    FinSi

    res      ->IncBuffer();
    criterion->IncBuffer();
  FinPour
  FinPour
  FinPour

  return res;

} // Func_thinning()
