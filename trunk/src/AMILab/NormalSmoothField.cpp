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

#include "style.hpp"
#include "inrimage.hpp"
#include "TableauDyn.hpp"
#include "Coordonnees.hpp"
#include "vtkMinHeap.h"


class NS_Point {

public:

  int x;
  int y;
  int z;
  float value;

  NS_Point() 
    {
      x=y=z=0;
      value=0.0; 
    }

  NS_Point(int ix,int iy, int iz,
	   float val)
    { x = ix; y=iy; z=iz; 
      value = val; }

  NS_Point& operator=(const NS_Point& p)
  {
    x     = p.x;
    y     = p.y;
    z     = p.z;
    value = p.value;
    return *this;
  }


  friend int operator < ( const NS_Point& p1, const NS_Point& p2)
  {
    return (p1.value < p2.value);
  }

  friend int operator > ( const NS_Point& p1, const NS_Point& p2)
  {
    return (p1.value > p2.value);
  }

  //  friend ostream& operator << (ostream&, const NS_Point& p);

};

static vtkMinHeap<NS_Point> point_list;

static InrImage* res2;

static    int       positive_neighbors[13][3];
static    int       neighbor_position[3][3][3];


//----------------------------------------------------------------------
Vect3D<float> FindVectorNormalTo(Vect3D<float> v)
//            ------------------
{

  
    Vect3D<float> v1,v2;

  Si fabs(v.x)<fabs(v.y) Et fabs(v.x)<fabs(v.z) Alors
    v1.Init(1,0,0);
  Autrement
  Si fabs(v.y)<fabs(v.x) Et fabs(v.y)<fabs(v.z) Alors
    v1.Init(0,1,0);
  Autrement
    v1.Init(0,0,1);

  v2 = v^v1;

  try {
    v2.Normalise();
  }
  catch ( NormeFaible)
  {
    v2 = v1;
  }

  return v2;
    
} // FindVectorNormalTo()


//----------------------------------------------------------------------
void AddNeighbors( int x, int y, int z, Vect3D<float>& v, InrImage* status)
//
{

    int i,j,k;
    int x1,y1,z1;
    Vect3D<float> v0;
    float val;

  Pour(i,-1,1)
  Pour(j,-1,1)
  Pour(k,-1,1)
    x1 = x+i;
    y1 = y+j;
    z1 = z+k;
    Si status->CoordOK(x1,y1,z1) Et (*status)(x1,y1,z1)==0 Alors
      v0.Init(i,j,k);
      val = fabs(v0*v);
      point_list += NS_Point(x1,y1,z1,val);
      status->BufferPos(x1,y1,z1);
      status->FixeValeur(1);
    FinSi
  FinPour
  FinPour
  FinPour

} // AddNeighbors()


//----------------------------------------------------------------------
unsigned char FindNextPoint( int x0, int y0, int z0, int& x1, int& y1, int& z1, 
		       InrImage* status)
//
{

  
    int x,y,z;


//  status->Sauve("status2.ami.gz");

  status->InitBuffer();

  Pour(z,0,status->_tz-1)
  Pour(y,0,status->_ty-1)
  Pour(x,0,status->_tx-1)

    Si status->ValeurBuffer() == 0 Alors
      x1 = x;
      y1 = y;
      z1 = z;
      return true;
    FinSi

    status->IncBuffer();

  FinPour
  FinPour
  FinPour

  return false;

} // FindNextPoint()


//----------------------------------------------------------------------
void InitList( int x0, int y0, int z0, InrImage* im, InrImage* res, InrImage* status)
//
{

  
    Vect3D<float> v1,v2,v3;

  im->BufferPos(x0,y0,z0);
  v1.Init( im->VectValeurBuffer(0),
	   im->VectValeurBuffer(1),
	   im->VectValeurBuffer(2));
  v2 = FindVectorNormalTo(v1);

  res->BufferPos(x0,y0,z0);
  res->VectFixeValeurs( v2.x, v2.y, v2.z);
  
  v2 = v1^v2;
  res2->BufferPos(x0,y0,z0);
  res2->VectFixeValeurs( v2.x, v2.y, v2.z);
  
  status->BufferPos(x0,y0,z0);
  status->FixeValeur(2);
  AddNeighbors(x0,y0,z0,v2,status);

} // InitList()


//----------------------------------------------------------------------
InrImage*    Func_NormalSmoothField( InrImage* im, InrImage* mask)
//           ----------------------
{

  
    InrImage* res;
    InrImage* status;
    Vect3D<float> v1,v2,v3;
    Vect3D<float> w2,w3;
    int x,y,z,n,n1,it;
    int x0,y0,z0;
    NS_Point p;
    int i,k,j,x1,y1,z1;

//  list.VideTableau();
  while (point_list.Size() != 0) point_list.GetMin();

  Si (!im->VectorialFormat()) Alors
    fprintf(stderr,"Func_NormalSmoothField() \t image not vectorial \n");
    return NULL;
  FinSi

  res    = new InrImage(WT_FLOAT,3, "NormalSmoothed.ami.gz", im);
  res->InitImage(0,0,0);

  res2    = new InrImage(WT_FLOAT,3, "NormalSmoothed2.ami.gz", im);
  res2->InitImage(0,0,0);

  status = new InrImage(WT_UNSIGNED_CHAR,"Status.ami.gz", im);
  status->InitImage(0);

  // First point
  x0 = y0 = z0 = 0;

  Si mask!= NULL Alors
    status->InitBuffer();
    mask->InitBuffer();

    Pour(z,0,status->_tz-1)
    Pour(y,0,status->_ty-1)
    Pour(x,0,status->_tx-1)
      Si mask->ValeurBuffer() == 0 Alors
        status->FixeValeur(3);
      Sinon
        Si x0==0 Et y0==0 Et z==0 Alors
          x0 = x;
          y0 = y;
          z0 = z;
        FinSi
      FinSi
      mask->IncBuffer();
      status->IncBuffer();
    FinPour
    FinPour
    FinPour

  FinSi
  
    //    status->Sauve("status1.ami.gz");

  // Initialize the vector orthogonal to the first point
  InitList(x0,y0,z0,im,res,status);

  while  ((point_list.Size() == 0) Et  FindNextPoint(x0,y0,z0,x1,y1,z1,status)) 
  {
    x0 = x1;
    y0 = y1;
    z0 = z1;
    InitList(x0,y0,z0,im,res,status);
  }

  it = 0;

  TantQue point_list.Size() > 0 Faire
    n = point_list.Size();
    it ++;
    Si it%10000 == 0 AlorsFait
      fprintf(stderr,"it %d size %d \n",it,n);

    p = point_list.GetMin();

    im->BufferPos(p.x,p.y,p.z);
    v1.Init( im->VectValeurBuffer(0),
	     im->VectValeurBuffer(1),
	     im->VectValeurBuffer(2));

    // Take the mean vector between the neighbors already parsed
    v3.Init(0,0,0);
    w3.Init(0,0,0);

    n = n1 = 0;
    Pour(i,-1,1)
    Pour(j,-1,1)
    Pour(k,-1,1)
      x1 = p.x+i;
      y1 = p.y+j;
      z1 = p.z+k;
      Si res->CoordOK(x1,y1,z1) Alors
        Si (*status)(x1,y1,z1)==2 Alors
          res->BufferPos(x1,y1,z1);
          v2.Init(res->VectValeurBuffer(0),
		  res->VectValeurBuffer(1),
		  res->VectValeurBuffer(2));
          v3 = v3 + v2;

          res2->BufferPos(x1,y1,z1);
          w2.Init(res2->VectValeurBuffer(0),
		  res2->VectValeurBuffer(1),
		  res2->VectValeurBuffer(2));
          w3 = w3 + w2;

          n++;
        Autrement
        Si (*status)(x1,y1,z1)==1 Alors
  	  n1++;
        FinSi
      FinSi
    FinPour
    FinPour
    FinPour

    v3 = ((float)(1.0/n))*v3;
 
    v2 = v3 - (v3*v1)*v1;
    try {
      v2.Normalise();
    }
    catch ( NormeFaible)
    {
      fprintf(stderr,"Weak vector norm after projection n = %d ,n1 = %d, %d %d %d\n",
	      n,n1,
	      p.x,p.y,p.z);

      /*
      Si n1>0 Alors
	point_list.Supprime(list.Size()-1);
        point_list.Insere(0,p);
        continue;
      FinSi
      */

      v2 = FindVectorNormalTo(v1);
    }

    res->BufferPos(p.x,p.y,p.z);
    res->VectFixeValeurs( v2.x, v2.y, v2.z);

    w3 = ((float)(1.0/n))*w3;
 
    w3 = w3 - (w3*v1)*v1;
    w2 = v1^v2;

    Si w2*w3 < 0 Alors
      w2 = ((float)(-1))*w2;
    FinSi
 
    res2->BufferPos(p.x,p.y,p.z);
    res2->VectFixeValeurs( w2.x, w2.y, w2.z);

//    n = point_list.Size()-1;
//    point_list.Supprime(n);

    status->BufferPos(p.x,p.y,p.z);
    status->FixeValeur(2);

    AddNeighbors(p.x,p.y,p.z,v2,status);

    while  ((point_list.Size() == 0) Et  FindNextPoint(p.x,p.y,p.z,x0,y0,z0,status)) 
    {
      p.x = x0;
      p.y = y0;
      p.z = z0;
      InitList(p.x,p.y,p.z,im,res,status);
    }

  FinTantQue

  delete status;

  res2->Sauve();
  delete res2;

  return res;

} // NormalSmoothField()


//----------------------------------------------------------------------
void PropagateCC(int x,int y,int z,int ncc,
		 InrImage* cc,
		 InrImage* connectivity,
		 InrImage* im,
		 InrImage* mask)
//
{

  
    NS_Point       p;
    int            i,j,k,np;
    int            x1,y1,z1;
    //unsigned short connect;
    unsigned char        belong;
    InrImage*      list_status;
    unsigned long  nbpts;
    Vect3D<float>  v1,v0;
    float          val;

  printf("PropagateCC(%d,%d,%d,%d,...) ",x,y,z,ncc);

  list_status = new InrImage(WT_UNSIGNED_CHAR,"list_status.ami.gz",cc);
  list_status->InitImage(0);

  nbpts = 0;

  while (point_list.Size() != 0) point_list.GetMin();

  point_list += NS_Point(x,y,z,0);
  list_status->BufferPos(x,y,z);
  list_status->FixeValeur(1);

  while (point_list.Size() != 0) {

    p = point_list.GetMin();

    // mark the point so that we don't add it again to the list
    list_status->BufferPos(p.x,p.y,p.z);
    list_status->FixeValeur(2);

    // Check if the point can be added to the component
    belong = true;
    Pour(i,-1,1)
    Pour(j,-1,1)
    Pour(k,-1,1)
      Si Non(belong) AlorsFait break;
      x1 = p.x+i;
      y1 = p.y+j;
      z1 = p.z+k;
      Si cc->CoordOK(x1,y1,z1) Et (*mask)(x1,y1,z1) 
         Et (*cc)(x1,y1,z1) == ncc
      Alors
	np = neighbor_position[i+1][j+1][k+1];
        Si np>0 Alors 
	  // Check the corresponding bit for directions
          // Si 0 alors les directions sont les memes
  	  Si (((unsigned short) (*connectivity)(p.x,p.y,p.z)) & ((unsigned short) (1<<np))) != 0 Alors
  	    belong = false;
          FinSi
        Autrement
        Si np<0 Alors
	  // Check the corresponding bit for directions
          // Si 0 alors les directions sont les memes
  	  Si (((unsigned short)(*connectivity)(x1,y1,z1)) & ((unsigned short)(1<<-np))) != 0 Alors
	    belong = false;
          FinSi
        FinSi
      FinSi
    FinPour
    FinPour
    FinPour


    Si belong Alors
	    //      printf("(%d,%d,%d) ",p.x,p.y,p.z);
      // Add the point to the connex component
      cc->BufferPos(p.x,p.y,p.z);
      cc->FixeValeur(ncc);

      // Add neighbors in the mask, with the same direction as the list
      // and which don't belong to any current connex component
      // and which have not been processed yet

      im->BufferPos(p.x,p.y,p.z);
      v0.Init(im->VectValeurBuffer(0),im->VectValeurBuffer(1),im->VectValeurBuffer(2));

      Pour(i,-1,1)
      Pour(j,-1,1)
      Pour(k,-1,1)
        x1 = p.x+i;
        y1 = p.y+j;
        z1 = p.z+k;
        Si cc->CoordOK(x1,y1,z1) Et (*mask)(x1,y1,z1) 
	  Et (*cc)(x1,y1,z1)==0 Et (*list_status)(x1,y1,z1)==0
        Alors
  	  np = neighbor_position[i+1][j+1][k+1];
          Si np>0 Alors 
	    // Check the corresponding bit for directions
            // if 0 then the directions are the same
  	    Si ((unsigned short)(*connectivity)(p.x,p.y,p.z) & (unsigned short)(1<<np)) == 0 Alors
              v1.Init(i,j,k);
              val = fabs(v0*v1);
  	      point_list += NS_Point(x1,y1,z1,val);
              list_status->BufferPos(x1,y1,z1);
              list_status->FixeValeur(1);
            FinSi
          Autrement
          Si np<0 Alors
	    // Check the corresponding bit for directions
            // if 0 then the directions are the same
  	    Si ((unsigned short)(*connectivity)(x1,y1,z1) & (unsigned short)(1<<-np)) == 0 Alors
              v1.Init(i,j,k);
              val = fabs(v0*v1);
  	      point_list += NS_Point(x1,y1,z1,val);
              list_status->BufferPos(x1,y1,z1);
              list_status->FixeValeur(1);
            FinSi
          FinSi
        FinSi
      FinPour
      FinPour
      FinPour
    Sinon
	      //      printf(" cc %d point %d %d %d : belong=false \n", ncc,p.x,p.y,p.z);
    FinSi

  }

  printf("\n");

  delete list_status;

} // PropagateCC()


class links_type {

 public:
  unsigned short pos;
  unsigned short neg;

  links_type() { pos=neg=0; }

};


//----------------------------------------------------------------------
// look localy at the changes in direction of a vector field
//
InrImage*  Func_DirConnectivity( InrImage* im, InrImage* mask)
//         --------------------
{

  
    int       x,y,z;
    int       x1,y1,z1;
    int       i,j,k;
    float     vx,vy,vz;
    float     ux,uy,uz;
    double    ps;
    InrImage* connectivity;
    InrImage* cc;  // connex components
    int       ncc; // number of connex components
    int       n,c;
    unsigned char   ccfound;
    links_type*    links; // number of positive and negative scalar product at the frontier for each connex component
    links_type**   tab_links; // number of positive and negative scalar product at the frontier 
                         // between two cc
    int        current_cc;
    int        neighbor_cc;
    int        np,nn;
    int        invert;
    int        merge_with;
    int        max_connections;
    float      criterion;
    float      min_criterion;

  // In the 26 neighborhood of a voxel,
  // we define an order: 13 positive and 13 negative neighbors
  // based on their position
  neighbor_position[0][0][0] = 0;

  n = 0;
  Pour(i,0,1)
  Pour(j,-1,1)
  Pour(k,-1,1)
     Si (i>0) Ou ((i==0)Et(j>0)) Ou ((i==0)Et(j==0)Et(k>0)) Alors
       positive_neighbors[n][0] = i;
       positive_neighbors[n][1] = j;
       positive_neighbors[n][2] = k;
       neighbor_position[ i+1][ j+1][ k+1] =  n;
       neighbor_position[-i+1][-j+1][-k+1] = -n;
       n++;
     FinSi
  FinPour
  FinPour
  FinPour

  // We pre-compute for each of the 13 positive neighbors of each voxel
  // the scalar product of the vectors of the neighbors
  // and store the 13 bits result (1 if negative 0 otherwise) in a unsigned short 
  // image
  connectivity = new InrImage(WT_UNSIGNED_SHORT,"connect.ami.gz",im);
  connectivity->InitImage(0);
  Pour(z,0,im->_tz-1)
  Pour(y,0,im->_ty-1)
  Pour(x,0,im->_tx-1)
    Si (*mask)(x,y,z) Alors
      vx = (*im)(x,y,z,0);
      vy = (*im)(x,y,z,1);
      vz = (*im)(x,y,z,2);
      c = 0;
      Pour(n,0,12)
        x1 = x+positive_neighbors[n][0];
        y1 = y+positive_neighbors[n][1];
        z1 = z+positive_neighbors[n][2];
        Si im->CoordOK(x1,y1,z1) Et (*mask)(x1,y1,z1) Alors
 	  im->BufferPos(x1,y1,z1);
          ux = im->VectValeurBuffer(0);
          uy = im->VectValeurBuffer(1);
          uz = im->VectValeurBuffer(2);
          ps = vx*ux + vy*uy + vz*uz;
          Si ps < 0 AlorsFait  c += 1<<n;
        FinSi
      FinPour
      connectivity->BufferPos(x,y,z);
      connectivity->FixeValeur(c);
    FinSi
  FinPour
  FinPour
  FinPour

  // Compute connex components with same local direction
  cc = new InrImage(WT_UNSIGNED_SHORT,"cc.ami.gz",im);
  cc->InitImage(0);
  ncc = 0;
 
  Repeter
    ccfound = false;
    Pour(z,0,cc->_tz-1)
    Pour(y,0,cc->_ty-1)
    Pour(x,0,cc->_tx-1)
      Si (*mask)(x,y,z) Et (*cc)(x,y,z) == 0 Alors
        ncc++;
        PropagateCC(x,y,z,ncc,cc,connectivity,im,mask);
        ccfound = true;
      FinSi
    FinPour
    FinPour
    FinPour
  JusquA ccfound==false FinRepeter


  // Compute the number of outer positive and negative scalar products
  // at the frontier of each cc
  links = new links_type[ncc+1];
  tab_links = new links_type*[ncc+1];
  Pour(i,1,ncc)
     tab_links[i] = new links_type[ncc+1];
  FinPour

  Pour(z,0,im->_tz-1)
  Pour(y,0,im->_ty-1)
  Pour(x,0,im->_tx-1)
    current_cc = (int) (*cc)(x,y,z);
    Si current_cc>0 Alors
      Pour(i,-1,1)
      Pour(j,-1,1)
      Pour(k,-1,1)
        x1 = x+i;
        y1 = y+j;
        z1 = z+k;
	Si cc->CoordOK(x1,y1,z1) Alors
  	  neighbor_cc= (int) (*cc)(x1,y1,z1);
	  Si neighbor_cc>0 Et neighbor_cc!=current_cc Alors
  	    np = neighbor_position[i+1][j+1][k+1];
            Si np>0 Alors 
	      // Check the corresponding bit for directions
              // if 0 then the directions are the same
  	      Si ((unsigned short)(*connectivity)(x,y,z) & (unsigned short)(1<<np)) == 0 Alors
  	        links[current_cc].pos++;
  	        tab_links[current_cc][neighbor_cc].pos++;
	      Sinon
  	        links[current_cc].neg++;
  	        tab_links[current_cc][neighbor_cc].neg++;
              FinSi
            Autrement
            Si np<0 Alors
	      // Check the corresponding bit for directions
              // if 0 then the directions are the same
  	      Si ((unsigned short)(*connectivity)(x1,y1,z1) & (unsigned short)(1<<-np)) == 0 Alors
  	        links[current_cc].pos++;
  	        tab_links[current_cc][neighbor_cc].pos++;
	      Sinon
  	        links[current_cc].neg++;
  	        tab_links[current_cc][neighbor_cc].neg++;
              FinSi
            FinSi
          FinSi
        FinSi
      FinPour
      FinPour
      FinPour
    FinSi
  FinPour
  FinPour
  FinPour

  // Display the links
  Pour(i,1,ncc)
    Si links[i].pos!=0 Ou links[i].neg!= 0 Alors
      printf("cc %03d:(%03d,%03d) --> ",
	   i,
	   links[i].pos,
	   links[i].neg
	   );
      Pour(j,1,ncc)
        Si tab_links[i][j].pos!= 0 Ou tab_links[i][j].neg != 0 AlorsFait
         printf("%3d:(%03d,%03d)  ",j,tab_links[i][j].pos,tab_links[i][j].neg);
      FinPour
      printf("\n");
    FinSi
  FinPour


  Repeter
    // Decide of the component to invert 
    // and update the array of links
    // and merge them with the cc with which they have most connections 
    merge_with = 0;
    invert     = 0;
    min_criterion = -1;

    Pour(i,1,ncc)
      // Set a criterion to select the next cc to invert
      // first select the cc with 0 positive scalar products
      // and the maximum negative scalar products
      // second select the cc with the minimum ratio pos/neg
      Si  links[i].neg>links[i].pos Alors
        Si links[i].pos==0 Alors
          criterion = 1.0/(float)links[i].neg;
        Sinon
          criterion = 1.0+(float)links[i].pos/(float)links[i].neg;
        FinSi

        Si min_criterion == -1 Ou criterion<min_criterion Alors
          invert = i;
          min_criterion = criterion;
        FinSi
      FinSi

    FinPour

    Si invert>0 Alors 
      i = invert;
      max_connections = 0;
      printf("Invert %d \n",i);
      n = links[i].neg;
      links[i].neg = links[i].pos;
      links[i].pos = n;
      Pour(j,1,ncc)
        nn = tab_links[i][j].neg;
        np = tab_links[i][j].pos;
        Si nn != 0 Ou np != 0 Alors
          links[j].neg += np-nn;
          links[j].pos += nn-np;
          tab_links[i][j].neg = tab_links[j][i].neg = np;
          tab_links[i][j].pos = tab_links[j][i].pos = nn;

  	  Si  tab_links[i][j].pos>max_connections Alors
  	    max_connections = tab_links[i][j].pos;
            merge_with = j;
          FinSi

        FinSi
      FinPour

      Si merge_with != 0 AlorsFait printf("merge with %d \n",merge_with);

      // Invert the components chosen for inversion
      // and merge
      Pour(z,0,im->_tz-1)
      Pour(y,0,im->_ty-1)
      Pour(x,0,im->_tx-1)
        cc->BufferPos(x,y,z);
        current_cc = (int) cc->ValeurBuffer();
        Si  invert == current_cc Alors
          im->BufferPos(x,y,z);
          ux = im->VectValeurBuffer(0);
          uy = im->VectValeurBuffer(1);
          uz = im->VectValeurBuffer(2);
          im->VectFixeValeurs(-ux,-uy,-uz);
          Si merge_with != 0 AlorsFait
            cc->FixeValeur(merge_with);
        FinSi
      FinPour
      FinPour
      FinPour

      // Remove links between invert and merge_with
      links[merge_with].pos -= tab_links[merge_with][invert].pos;
      links[merge_with].neg -= tab_links[merge_with][invert].neg;
      tab_links[merge_with][invert].pos = 0;
      tab_links[merge_with][invert].neg = 0;
      tab_links[invert][merge_with].pos = 0;
      tab_links[invert][merge_with].neg = 0;
      links[invert].pos                 = 0;
      links[invert].neg                 = 0;  
      
      // Move links from invert to merge_with
      Pour(i,1,ncc)
        Si i!=invert Et i!=merge_with Alors
  	  tab_links[merge_with][i].pos += tab_links[invert][i].pos;
  	  tab_links[merge_with][i].neg += tab_links[invert][i].neg;
  	  tab_links[i][merge_with].pos += tab_links[invert][i].pos;
  	  tab_links[i][merge_with].neg += tab_links[invert][i].neg;
          links[merge_with].pos        += tab_links[invert][i].pos;
          links[merge_with].neg        += tab_links[invert][i].neg;

          tab_links[invert][i].pos  = 0;
          tab_links[invert][i].neg  = 0;
          tab_links[i][invert].pos  = 0;
          tab_links[i][invert].neg  = 0;
        FinSi
      FinPour

    FinSi


    Pour(i,1,ncc)
      Si links[i].pos!=0 Ou links[i].neg!= 0 Alors
        printf("cc %03d:(%03d,%03d) --> ",
	     i,
	     links[i].pos,
	     links[i].neg
	     );
        Pour(j,1,ncc)
          Si tab_links[i][j].pos!= 0 Ou tab_links[i][j].neg != 0 AlorsFait
           printf("%3d:(%03d,%03d)  ",j,tab_links[i][j].pos,tab_links[i][j].neg);
        FinPour
        printf("\n");
      FinSi
    FinPour

  JusquA invert==0 FinRepeter



  connectivity->Sauve();
  delete connectivity;

  Pour(i,1,ncc)
     delete [] tab_links[i];
  FinPour
  delete [] tab_links;
  delete [] links;

  return cc;
 
} // Func_DirConnectivity()


//----------------------------------------------------------------------
void    Func_OrientField( InrImage* im, InrImage* mask)
//      ----------------
{

  
    int       x,y,z;
    int       x1,y1,z1;
    int       i,j,k;
    int       np,nn;
    float     vx,vy,vz;
    float     mx,my,mz;
    double    ps;

  Pour(z,0,im->_tz-1)
  Pour(y,0,im->_ty-1)
  Pour(x,0,im->_tx-1)
    Si (*mask)(x,y,z) Alors
      np = nn = 0;
      vx = (*im)(x,y,z,0);
      vy = (*im)(x,y,z,1);
      vz = (*im)(x,y,z,2);
      mx = my = mz = 0;
      Pour(i,0,1)
      Pour(j,0,1)
      Pour(k,0,1)
        Si i==0 Et j==0 Et k==0 AlorsFait continue;
        x1 = x+i;
        y1 = y+j;
        z1 = z+k;
        Si im->CoordOK(x1,y1,z1) Et (*mask)(x1,y1,z1) Alors
 	  im->BufferPos(x1,y1,z1);
          mx += im->VectValeurBuffer(0);
          my += im->VectValeurBuffer(1);
          mz += im->VectValeurBuffer(2);
        FinSi
      FinPour
      FinPour
      FinPour
      ps = mx*vx + my*vy + mz*vz;
      Si ps<0 Alors
	im->BufferPos(x,y,z);
        im->VectFixeValeurs(-vx,-vy,-vz);
      FinSi
    FinSi
  FinPour
  FinPour
  FinPour

} // Func_OrientField()


//----------------------------------------------------------------------
// Orient toward positive axis
//
void    Func_OrientPositive( InrImage* im, InrImage* mask)
//      ------------------------
{

  
    int       x,y,z;
//    int       x1,y1,z1;
//    int       i,j,k;
    int       np,nn;
    float     vx,vy,vz;
    float     max;
//    double    ps;

  Pour(z,0,im->_tz-1)
  Pour(y,0,im->_ty-1)
  Pour(x,0,im->_tx-1)
    Si (*mask)(x,y,z) Alors
      np = nn = 0;
      vx = (*im)(x,y,z,0);
      vy = (*im)(x,y,z,1);
      vz = (*im)(x,y,z,2);
      max = vx;
      Si fabs(vy)>fabs(max) AlorsFait max = vy;
      Si fabs(vy)>fabs(max) AlorsFait max = vz;

      Si max <0 Alors
	im->BufferPos(x,y,z);
        im->VectFixeValeurs(-vx,-vy,-vz);
      FinSi
    FinSi
  FinPour
  FinPour
  FinPour

} // Func_OrientPositive()


