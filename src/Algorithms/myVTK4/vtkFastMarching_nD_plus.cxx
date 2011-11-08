/*  ==================================================
    Module : vtkFastMarching_nD_plus
    Authors: Karl Krissian
    Email  : krissian@dis.ulpgc.es


    Description: This class implements the Fast Marching algorithm for 4D images, using the image components as an additional dimension.

    ======================================================
    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

    ================================================== 
   The full GNU Lesser General Public License file is in vtkLevelSets/LesserGPL_license.txt
*/

 /*=========================================================================

  Program:   Visualization Toolkit
  Module:    $RCSfile: vtkFastMarching_nD_plus.cxx,v $
  Language:  C++
  Date:      $Date: 2005/03/30 19:34:33 $
  Version:   $Revision: 1.7 $

=========================================================================*/
#include "vtkFastMarching_nD_plus.h"
#include "vtkObjectFactory.h"
#include "vtkStructuredPointsWriter.h"
#include "vtkFloatArray.h"

#ifndef _WIN32
#include <strings.h>
#endif

//
//  Code by Karl Krissian oct-nov 2001
//
//  Brigham and Women's hospital
//  Surgical Planning Laboratory
//

#ifndef macro_min
  #define macro_min(n1,n2) ((n1)<(n2)?(n1):(n2))
#endif

#ifndef macro_max
  #define macro_max(n1,n2) ((n1)>(n2)?(n1):(n2))
#endif 

#define macro_abs(n)     ((n)>0?(n):-(n))

#define EPSILON 1E-5

#include <algorithm>
#include <vector>

vtkCxxRevisionMacro(vtkFastMarching_nD_plus,"$Revision: 1.0$")

//--------------------------------------------------
ostream& operator << (ostream& os, const FM_TrialPoint_nD_plus& p)
//       -----------
{

  os << p.value;
  return os;

} // operator << ( , const FM_TrialPoint_nD_plus&)

//----------------------------------------------------------------------
//  Solve  x^2 - 2.b2.x + c = 0
//
inline float SolveQuad(double b2,double c)
{

  double delta;

  delta = b2*b2-c;

  if (delta<0) {
    fprintf(stderr,"SolveQuad() \t Delta <0 \n");
    return 0;
  }

  return b2+sqrt(delta);

}

//----------------------------------------------------------------------
//  Solve a.x^2 - 2.b2.x + c = 0
//
inline float SolveQuad(double a, double b2,double c)
{

  double delta;

  delta = b2*b2-a*c;

  if (delta<0) {
    fprintf(stderr,"SolveQuad() \t Delta <0 \n");
    return 0;
  }

  return (b2+sqrt(delta))/a;

}

//----------------------------------------------------------------------
void UpdateMinHeapPos(const FM_TrialPoint_nD_plus& tp, int pos, void* data)
{
  unsigned int* mhpos     = (unsigned int*) data;

  mhpos[tp.impos]=pos;
}

//-----------------------------------------------------------------------
vtkFastMarching_nD_plus* vtkFastMarching_nD_plus::New()
{
  // First try to create the object from the vtkObjectFactory
  vtkObject* ret = vtkObjectFactory::CreateInstance("vtkFastMarching_nD_plus");
  if(ret)
    {
    return (vtkFastMarching_nD_plus*)ret;
    }
  // If the factory was unable to create the object, then create it here.
  return new vtkFastMarching_nD_plus;

} // vtkFastMarching_nD_plus::New()


//----------------------------------------------------------------------
// Construct object to extract all of the input data.
//
vtkFastMarching_nD_plus::vtkFastMarching_nD_plus() : mh(100000)
{

  mask   = NULL;
  track  = NULL;
  
  force  = NULL;
  T      = NULL;
  status = NULL;
  mhPos  = NULL;
  
  
  dim = VTK_MODE_2D;
  tx = ty = tz = tt = 1;
  vs[0] = vs[1] = vs[2] = voxelsize_time = 1;
  maxTime = 100;

  force_allocated = 0;
  mask_allocated  = 0;


  initimage    = NULL;
  initmaxdist  = 1;

  initiso      = -1E10;

  isotropic_voxels = 0;

  EvolutionScheme = 0; // Sethian

  output_array    = NULL;

  //  this->ExecuteInformation();

  UseGaussianForce = 0;

} // vtkFastMarching_nD_plus::vtkFastMarching_nD_plus()


//----------------------------------------------------------------------
vtkFastMarching_nD_plus::~vtkFastMarching_nD_plus()
{
  if (mask_allocated)  mask ->Delete();
  Setmask(NULL); // dereferencing ...

  if (force_allocated) force->Delete();
  Setinitimage(NULL); // dereferencing

  if (status != NULL) {
    delete [] status;
    status = NULL;
  }

  if (mhPos != NULL) {
    delete [] mhPos;
    mhPos = NULL;
  }

} // ~vtkFastMarching_nD_plus

//----------------------------------------------------------------------
void vtkFastMarching_nD_plus::InitParam()
{

  int type;

  //  fprintf(stderr,"vtkFastMarching_nD_plus::InitParam() begin\n");

  // Image size
  force=NULL;
  tx = this->GetInput()->GetDimensions()[0];
  ty = this->GetInput()->GetDimensions()[1];
  tz = this->GetInput()->GetDimensions()[2];
  tt = this->GetInput()->GetNumberOfScalarComponents();

  if ((tx<3)||(ty<3)||(tz<3)||(tt<3)) {
    vtkErrorMacro("Input image need to be 4D ...");
    return;
  }

  // Get force image from input
  force  = this->GetInput();
  if (force == NULL)
    {
      vtkErrorMacro("Missing input");
      return;
    }
  // check the image is in float format, or convert
  type = force->GetScalarType();
  if (type != VTK_FLOAT) {
    vtkDebugMacro(<<"making a copy of the input into float format");
    // Create a copy of the data
    force = vtkImageData::New();
    force->SetScalarType( VTK_FLOAT);
    force->SetNumberOfScalarComponents(this->GetInput()->GetNumberOfScalarComponents());
    force->SetDimensions( this->GetInput()->GetDimensions());
    force->SetOrigin(     this->GetInput()->GetOrigin());
    force->SetSpacing(    this->GetInput()->GetSpacing());

    force->CopyAndCastFrom(this->GetInput(),
               this->GetInput()->GetExtent());
    force_allocated = 1;
  }


  // The mask must be UNSIGNED_CHAR
  if (mask != NULL) {
    type = mask->GetScalarType();
    if (type != VTK_UNSIGNED_CHAR) {
      vtkDebugMacro(<<"convert mask to unsigned char");
      // Create a copy of the data
      vtkImageData* mask1;
      mask1 = vtkImageData::New();
      mask1->SetScalarType( VTK_UNSIGNED_CHAR);
      mask1->SetNumberOfScalarComponents(1);
      mask1->SetDimensions( this->mask->GetDimensions());
      mask1->SetOrigin(     this->mask->GetOrigin());
      mask1->SetSpacing(    this->mask->GetSpacing());
      
      mask1->CopyAndCastFrom(this->mask,
                 this->mask->GetExtent());
      mask           = mask1;
      mask_allocated = 1;
    } 
  }

  // The track must be unsigned int
  if (track != NULL) {
    type = track->GetScalarType();
    if (type != VTK_INT) {
      vtkDebugMacro("track image must be INT, setting to NULL");
      track = NULL;
    }
  }

  txy = tx*ty;

  inc_t = 1;
  inc_x = tt;
  inc_y = tt*tx;
  inc_z = inc_y*ty;
  imsize = inc_z*tz;

  inc[0] = inc_x;
  inc[1] = inc_y;
  inc[2] = inc_z;
  inc[3] = inc_t;

  force->GetSpacing(vs);

  // need to give it as input
  vs[3] = voxelsize_time;

  ivs2[0] = 1.0/vs[0]/vs[0];
  ivs2[1] = 1.0/vs[1]/vs[1];
  ivs2[2] = 1.0/vs[2]/vs[2];
  ivs2[3] = 1.0/vs[3]/vs[3];
  // t dimension size ?

  //  fprintf(stderr," voxel size %f %f %f \n",vs[0],vs[1],vs[2]);

  // check for isotropic voxels
  isotropic_voxels = ((vs[0]==vs[1])&&(vs[0]==vs[2])&&(vs[0]==vs[3]));

  // Check the initimage
  if (initimage != NULL) {
    if (initimage->GetScalarType() != VTK_FLOAT) {
      fprintf(stderr,"The initialization image must be of type VTK_FLOAT \n");
      initimage = NULL;
    }
    if ((initimage->GetDimensions()[0] != tx) ||
        (initimage->GetDimensions()[1] != ty) ||
        (initimage->GetDimensions()[2] != tz) ||
        (initimage->GetNumberOfScalarComponents() != tt)
        ) {
      fprintf(stderr,"The initialization image must have the same dimensions as the Force \n");
      initimage = NULL;
    }
  }


  // Default dimension mode
  if (tz>4) dim = VTK_MODE_3D; else dim = VTK_MODE_2D;        


  // Get the time image (output of the algorithm)
  T      = this->GetOutput();
  
  T->SetDimensions(this->GetInput()->GetDimensions());
  T->SetSpacing(   this->GetInput()->GetSpacing());
  T->SetScalarType(VTK_FLOAT); 
  T->SetNumberOfScalarComponents(this->GetInput()->GetNumberOfScalarComponents());

  if (output_array != NULL) {
    vtkFloatArray* da = vtkFloatArray::New();
    da->SetArray(output_array,imsize,1);
    T->GetPointData()->SetScalars(da);
  } 
  else {
    T->AllocateScalars();
  }

  // initialization of the buffers:
  // always points to the first element of the images data
  T_buf     = (float*) (this->T    ->GetScalarPointer());
  force_buf = (float*) (this->force->GetScalarPointer());

    
  // Initialization of status image
  if (status==NULL)
    status = new unsigned char[imsize];

  // Initialization of mhPos image
  if (mhPos==NULL)
    mhPos = new unsigned int[imsize];

  // initializing mhPos to 0
  memset(mhPos,0,imsize*sizeof(unsigned int));
  //  for(x=0;x<imsize;x++) mhPos[x] = 0;
    
  // Set the callback function to update the position image
  // when a value is moved in the MinHeap structure
  mh.SetMoveFunction( UpdateMinHeapPos, this->mhPos);

  // Empty the min heap structure just in case
  mh.RemoveAll();

  //  fprintf(stderr,"vtkFastMarching_nD_plus::InitParam() end \n");

} // vtkFastMarching_nD_plus::InitParam()



//----------------------------------------------------------------------
void vtkFastMarching_nD_plus::ExecuteData(vtkDataObject *outData)
{
  
  FM_TrialPoint_nD_plus p;

  //  InrImage* ImEvol;
  float last_value = 0;
  int iterations;


  //  Si dim==VTK_MODE_2D AlorsFait
  //    ImEvol = new InrImage(tx,ty,50,WT_FLOAT,"evol_fm.ami.gz");

  //  fprintf(stderr,"vtkFastMarching_nD_plus::Execute() begin ----------------------------- \n");
  //  fprintf(stderr,"vtkFastMarching_nD_plus::Execute() initparam \n");

  InitParam();

  if (force==NULL) {
    vtkErrorMacro("Initialization failed!");
    return;
  }


  bool use_target_points;
  bool stop_evolution;
  use_target_points = (!target_points.empty());
  std::cout << " use_target_points " << use_target_points << std::endl;

  if (initimage == NULL) 
  {
    vtkErrorMacro("This class needs an initialization image");
    return;
    //Init(cx,cy,cz,ct, (int) radius);
  }
  else
    if (initiso == -1E10)  
      InitWithImage();
    else
      InitIsoSurf();

  iterations = 0;
  //  printf("iterations = %7d",iterations);
  //  fflush(stdout);

  do {

    p = this->mh.GetMin();

    if ( p.value > last_value+100 ){
      last_value = p.value;
      printf("\n current val = %f \t it %d \n",last_value,iterations);
    } // end if

    T_buf[p.impos] = p.value;
    if (track!=NULL) {
      if (p.impos != this->GetPosition(p.x,p.y,p.z,p.t))
      {
       std::cout << "p.impos != GetPosition(p.x,p.y,p.z,p.t)" << std::endl;
      }
      if (p.impos==p.track) {
       std::cout << "Pb .." 
            << " at position " << p.x << "," << p.y << "," << p.z << "," << p.t
            << " p.impos == p.track"
            << std::endl;
      }
      int* track_buf = (int*)track->GetScalarPointer();
      track_buf[p.impos] = (int) p.track;
    }

    AddAcceptedPoint(p.x,p.y,p.z,p.t,p.impos);

    iterations++;
    if (((iterations % 10000==0)&&(dim==VTK_MODE_3D))||
        ((iterations % 200  ==0)&&(dim==VTK_MODE_2D))) {
      
      //      printf("\b\b\b\b\b");
      // printf("%5d",iterations/100);
      //fflush(stdout);
      //      sprintf(Tname,"T%d.ami.gz",iterations/100);
      //      this->T->Sauve(Tname);
      
//    if( (dim==VTK_MODE_2D) ){
//    n = iterations/200;
//        if( n<ImEvol->_tz ){
//    for(x=0; x<=tx-1; x++){
//    for(y=0; y<=ty-1; y++) {
//    ImEvol->BufferPos(x,y,n);
//    ImEvol->FixeValeur((*this->T)(x,y,0));
//    }
//    }
//        } // end if

    } // end if
    
    //     std::cout << this->mh << std::endl;
  
    stop_evolution =  (p.value>=this->maxTime) || 
                      (this->mh.Size() == 0)   ||
                      ((use_target_points && target_points.empty()));
  } while (!stop_evolution);

  //  printf("\n");
  

//  if ( dim==VTK_MODE_2D ){
//    ImEvol->Sauve();
//    delete ImEvol;
//  } // end if  


  // Give back a distance function in the case of isosurface
  // For LevelSet application: negative distance for intensity
  // values higher than the threshold
  
  if (initiso != -1E10) {
    float* init_buf;
    int    pos;
    init_buf   = (float*)this->initimage->GetScalarPointer();
    
    for(pos=0;pos<imsize;pos++) 
      if (init_buf[pos]<initiso) 
    T_buf     [pos] *= -1;
  }

  //  fprintf(stderr,"vtkFastMarching_nD_plus::Execute() end ----------------------------- \n");

  // Check for the maximum

} // vtkFastMarching_nD_plus::Execute()


//----------------------------------------------------------------------
//
void vtkFastMarching_nD_plus::AddAcceptedPoint( short x, short y, short z, short t, int pos)
//                            ----------------
{

  unsigned char* status_buf;
  unsigned char* mask_buf;
  register int neighbors[8];
  register short neighb_x [8];
  register short neighb_y [8];
  register short neighb_z [8];
  register short neighb_t [8];
  // direction: 0,1,2,3 for X,Y,Z,T
  unsigned char dir[8];
  int n,nb;
  register int nx,ny,nz,nt;
  double time,F,cost,val1;
  FM_TrialPoint_nD_plus   trial;

  float      value; // time of the accepted point

  // setup the neighbors
  for ( nb=0; nb<=7; nb++ )
  {
    neighbors[nb] = pos;
    neighb_x[nb]  = x;
    neighb_y[nb]  = y;
    neighb_z[nb]  = z;
    neighb_t[nb]  = t;
  }

  nb = 0;
  if ( x-1>=0 ) { neighb_x[nb] = x-1; neighbors[nb] -=inc_x; dir[nb]=0; nb++;}
  if ( x+1<tx ) { neighb_x[nb] = x+1; neighbors[nb] +=inc_x; dir[nb]=0; nb++;}
  if ( y-1>=0 ) { neighb_y[nb] = y-1; neighbors[nb] -=inc_y; dir[nb]=1; nb++;}
  if ( y+1<ty ) { neighb_y[nb] = y+1; neighbors[nb] +=inc_y; dir[nb]=1; nb++;}
  if ( z-1>=0 ) { neighb_z[nb] = z-1; neighbors[nb] -=inc_z; dir[nb]=2; nb++;}
  if ( z+1<tz ) { neighb_z[nb] = z+1; neighbors[nb] +=inc_z; dir[nb]=2; nb++;}
  if ( t-1>=0 ) { neighb_t[nb] = t-1; neighbors[nb] -=inc_t; dir[nb]=3; nb++;}
  if ( t+1<tt ) { neighb_t[nb] = t+1; neighbors[nb] +=inc_t; dir[nb]=3; nb++;}


  status_buf  = this->status+pos;
  *status_buf = VTK_VAL_ACCEPTED;

  // check for targets
  if (!target_points.empty()) {
      std::list<target_point_nD_plus>::iterator Iter;
      Iter  = target_points.begin();
      while ( Iter != target_points.end() ) {
        if ((Iter->x == x)&&(Iter->y == y)&&(Iter->z==z)&&(Iter->t==t)) {
          // remove point from target list
          Iter = target_points.erase(Iter);
         std::cout << " removed target point " << x << " " << y << " " << z << " " << t << std::endl;
        } else
        Iter++;
      }

  }

  value = T_buf[pos];

  // Tag as trial all the neighbors of A that are Known
  // if the neighbor is far, remove and add to the set of Trial
  for ( n=0; n<=nb-1; n++ )
  {

    status_buf  =  this->status+neighbors[n];

    // Check for the mask
    if ( this->mask != NULL )
    {
      mask_buf  = ( unsigned char* ) this->mask->GetScalarPointer();
      mask_buf += neighbors[n];
      if ( *mask_buf <0.5 ) continue;
    }

    switch ( *status_buf )
    {
      case VTK_VAL_FAR:
        nx = neighb_x[n];
        ny = neighb_y[n];
        nz = neighb_z[n];
        nt = neighb_t[n];
        *status_buf = VTK_VAL_TRIAL;

        //        val = this->ComputeValue(nx,ny,nz);
        //    if (val>maxTime) val = maxTime;

        time =  value;
        if ( force==initimage )
          cost = 1;
        else
        {
          F    =  force_buf[neighbors[n]];
          if ( UseGaussianForce )
            F = exp ( - ( F-IntensityMean ) * ( F-IntensityMean ) /
                      IntensityStandardDeviation/IntensityStandardDeviation );
          if ( F < 1E-5 )
            cost = 1E5;
          else
            cost = 1.0/F;
        }

        if ( isotropic_voxels )
          val1 = time+cost;
        else
          val1 = time+cost*vs[dir[n]];

        if ( val1>maxTime ) val1 = maxTime;

        //    if ((val-val1)*(val-val1)>1E-2)
        //      fprintf(stderr," (%d %d %d) val %f val1 %f \n",x,y,z);
        trial.Init ( nx,ny,nz,nt,neighbors[n],val1 );
        trial.valmin[dir[n]] = value;
        trial.SetTrack(pos);

        this->mh += trial;

        break;

      case VTK_VAL_TRIAL:

        trial=mh[mhPos[neighbors[n]]];

        // if the value has changed,
        // then update the Min Heap structure
        if ( this->ComputeValue ( trial,value,dir[n] ) )
          this->mh.ChangeValue ( mhPos[neighbors[n]],trial );

        break;
    } // end switch

  }

} // AddAcceptedPoint()



//----------------------------------------------------------------------
// Solution: ne pas s'approcher trop du bord ...
// x in [2,tx-3]
// y in [2,ty-3]
// si 3D alors z in [2,tz-3]
//
void vtkFastMarching_nD_plus::AddTrialPoints( short x, short y, short z, short t, int pos)
//                    --------------
{
  unsigned char* mask_buf;
  int npos,ndir;  // direction: 0,1,2 for X,Y,Z
  register FM_TrialPoint_nD_plus trial;
  register float valmin;

  if (mask!=NULL)
    mask_buf  = (unsigned char*) this->mask->GetScalarPointer();

  // (x+/-1,y,z,t)
  for(int incr=-1;incr<=1;incr+=2)
  {
    ndir=0; 
    npos = pos+inc[ndir]*incr;
    if ((status[npos]==VTK_VAL_FAR)&&
        ((this->mask==NULL)||((this->mask!=NULL) && (mask_buf[npos]>0.5)))
        )
    {
      status[npos] = VTK_VAL_TRIAL;
      trial.Init(x+incr,y,z,t,npos,maxTime);
      // initialize the minimums in each direction
      trial.valmin[0]=macro_min(T_buf[npos-inc[0]], T_buf[npos+inc[0]]);
      trial.valmin[1]=macro_min(T_buf[npos-inc[1]], T_buf[npos+inc[1]]);
      trial.valmin[2]=macro_min(T_buf[npos-inc[2]], T_buf[npos+inc[2]]);
      trial.valmin[3]=macro_min(T_buf[npos-inc[3]], T_buf[npos+inc[3]]);

      // put the value in the current direction to the maximum
      // in order to process the point
      valmin = trial.valmin[ndir];
      trial.valmin[ndir]=maxTime;
      this->ComputeValue(trial,valmin,ndir); 
      this->mh += trial;
    } // end if
  }

  // (x,y+/-1,z,t)
  for(int incr=-1;incr<=1;incr+=2)
  {
    ndir=1; 
    npos = pos+inc[ndir]*incr;
    if ((status[npos]==VTK_VAL_FAR)&&
        ((this->mask==NULL)||((this->mask!=NULL) && (mask_buf[npos]>0.5)))
        )
    {
      status[npos] = VTK_VAL_TRIAL;
      trial.Init(x,y+incr,z,t,npos,maxTime);
      // initialize the minimums in each direction
      trial.valmin[0]=macro_min(T_buf[npos-inc[0]], T_buf[npos+inc[0]]);
      trial.valmin[1]=macro_min(T_buf[npos-inc[1]], T_buf[npos+inc[1]]);
      trial.valmin[2]=macro_min(T_buf[npos-inc[2]],T_buf[npos+inc[2]]);
      trial.valmin[3]=macro_min(T_buf[npos-inc[3]],T_buf[npos+inc[3]]);
      // put the value in the current direction to the maximum
      // in order to process the point
      valmin = trial.valmin[ndir];
      trial.valmin[ndir]=maxTime;
      this->ComputeValue(trial,valmin,ndir); 
      this->mh += trial;
    } // end if
  }

  // (x,y,z+/-1,t)
  for(int incr=-1;incr<=1;incr+=2)
  {
    ndir=2; 
    npos = pos+inc[ndir]*incr;
    if ((status[npos]==VTK_VAL_FAR)&&
        ((this->mask==NULL)||((this->mask!=NULL) && (mask_buf[npos]>0.5)))
        )
    {
      status[npos] = VTK_VAL_TRIAL;
      trial.Init(x,y,z+incr,t,npos,maxTime);
      // initialize the minimums in each direction
      trial.valmin[0]=macro_min(T_buf[npos-inc[0]], T_buf[npos+inc[0]]);
      trial.valmin[1]=macro_min(T_buf[npos-inc[1]], T_buf[npos+inc[1]]);
      trial.valmin[2]=macro_min(T_buf[npos-inc[2]],T_buf[npos+inc[2]]);
      trial.valmin[3]=macro_min(T_buf[npos-inc[3]],T_buf[npos+inc[3]]);
      // put the value in the current direction to the maximum
      // in order to process the point
      valmin = trial.valmin[ndir];
      trial.valmin[ndir]=maxTime;
      this->ComputeValue(trial,valmin,ndir); 
      this->mh += trial;
    } // end if
  }

  // (x,y,z,t+/-1)
  for(int incr=-1;incr<=1;incr+=2)
  {
    ndir=3; 
    npos = pos+inc[ndir]*incr;
    if ((status[npos]==VTK_VAL_FAR)&&
        ((this->mask==NULL)||((this->mask!=NULL) && (mask_buf[npos]>0.5)))
        )
    {
      status[npos] = VTK_VAL_TRIAL;
      trial.Init(x,y,z,t+incr,npos,maxTime);
      // initialize the minimums in each direction
      trial.valmin[0]=macro_min(T_buf[npos-inc[0]], T_buf[npos+inc[0]]);
      trial.valmin[1]=macro_min(T_buf[npos-inc[1]], T_buf[npos+inc[1]]);
      trial.valmin[2]=macro_min(T_buf[npos-inc[2]],T_buf[npos+inc[2]]);
      trial.valmin[3]=macro_min(T_buf[npos-inc[3]],T_buf[npos+inc[3]]);
      // put the value in the current direction to the maximum
      // in order to process the point
      valmin = trial.valmin[ndir];
      trial.valmin[ndir]=maxTime;
      this->ComputeValue(trial,valmin,ndir); 
      this->mh += trial;
    } // end if
  }



} // AddTrialPoints()



/*
//----------------------------------------------------------------------
//
inline float vtkFastMarching_nD_plus::ComputeValueDijkstra( 
//                                    --------------------
                                                            FM_TrialPoint_nD_plus& trial)
{

#define macro_swap(a,b) tmp=a; a=b; b=tmp;

  register double   valmin;
  double            F,invF,invF_1,invF_2;
  double            val;
  short             x = trial.x,y = trial.y,z = trial.z;, t = trial.t;
  int               pos = trial.impos;
  register float*   T_buf1 = T_buf+pos;


  if (force==initimage) 
    F = 1;
  else {
    F = *(force_buf+pos);
    if (UseGaussianForce) 
      F = exp(-(F-IntensityMean)*(F-IntensityMean)/
          IntensityStandardDeviation/IntensityStandardDeviation);
  }


  if (F<1.0/maxTime) return maxTime;
  else invF = 1.0/F;
  invF_1 = invF*sqrt(2.0);
  invF_2 = invF*sqrt(3.0);
  valmin = maxTime;

#define CheckMin(incpos,incval) \
{\
  val = *(T_buf1+incpos)  + incval; \
  if (val<valmin) { \
    valmin = val; \
    trial.track = pos+incpos; \
  }\
}

  // minimum among direct neighbors
  if (x>0   ) CheckMin(  -inc_x, invF)
  if (x<tx-1) CheckMin(   inc_x, invF)
  if (y>0   ) CheckMin(  -inc_y, invF)
  if (y<ty-1) CheckMin(   inc_y, invF)
  if (z>0   ) CheckMin(  -inc_z, invF)
  if (z<tz-1) CheckMin(   inc_z, invF)
  if (t>0   ) CheckMin(  -inc_t, invF)
  if (t<tt-1) CheckMin(   inc_t, invF)

  // minimum among first diagonals
  // XY
  if ((x>0)&&(y>0))       CheckMin( -1-tx, invF_1)
  if ((x>0)&&(y<ty-1))    CheckMin( -1+tx, invF_1)
  if ((x<tx-1)&&(y>0))    CheckMin(  1-tx, invF_1)
  if ((x<tx-1)&&(y<ty-1)) CheckMin(  1+tx, invF_1)

  // XZ
  if ((x>0)&&(z>0))       CheckMin( -1-txy, invF_1)
  if ((x>0)&&(z<tz-1))    CheckMin( -1+txy, invF_1)
  if ((x<tx-1)&&(z>0))    CheckMin(  1-txy, invF_1)
  if ((x<tx-1)&&(z<tz-1)) CheckMin(  1+txy, invF_1)

  // YZ
  if ((y>0)&&(z>0))       CheckMin( -tx-txy, invF_1)
  if ((y>0)&&(z<tz-1))    CheckMin( -tx+txy, invF_1)
  if ((y<ty-1)&&(z>0))    CheckMin(  tx-txy, invF_1)
  if ((y<ty-1)&&(z<tz-1)) CheckMin(  tx+txy, invF_1)

  // minimum among second diagonals
  if (z>0) {
    if (y>0) {
      if (x>0)    CheckMin( -1-tx-txy, invF_2)
      if (x<tx-1) CheckMin(  1-tx-txy, invF_2)
    }
    if (y<ty-1) {
      if (x>0)    CheckMin( -1+tx-txy, invF_2)
      if (x<tx-1) CheckMin(  1+tx-txy, invF_2)
    }
  }

  if (z<tz-1) {
    if (y>0) {
      if (x>0)    CheckMin( -1-tx+txy, invF_2)
      if (x<tx-1) CheckMin(  1-tx+txy, invF_2)
    }
    if (y<ty-1) {
      if (x>0)    CheckMin( -1+tx+txy, invF_2)
      if (x<tx-1) CheckMin(  1+tx+txy, invF_2)
    }
  }

  trial.SetValue(valmin);
  return valmin;


} // LevelSetFastMarching::ComputeValueDijkstra()
*/ 

//----------------------------------------------------------------------
//
unsigned char vtkFastMarching_nD_plus::ComputeValue( FM_TrialPoint_nD_plus& trial, float val, unsigned char dir)
//                                    ------------
{

  switch (EvolutionScheme) {
    case 0: 
      if (isotropic_voxels)
        return ComputeValueSethian( trial,val,dir);
      else
        return ComputeValueSethian2( trial,val,dir);
    case 1: 
      // not implemented
      //ComputeValueDijkstra( trial);
      vtkErrorMacro("Dijkstra not implemented in 4D!");
      return 1;
    default:
      return 0;
  }

} // ComputeValue()


//----------------------------------------------------------------------
//
// For isotropic voxels
// update the minimal value of the neighbors in the direction "dir"
// then solves the second order equation
// 
// Output
//    computes trial.value
unsigned char vtkFastMarching_nD_plus::ComputeValueSethian( FM_TrialPoint_nD_plus& trial, float value, unsigned char dir)
//                                    -------------------
{

#define macro_swap(a,b) tmp=a; a=b; b=tmp;

  register double val0,val1,val2,val3;
  double F;
  double cost;
  double cost2;
  double d1,d2,d3;
  double  res;

  if (value<trial.valmin[dir])
    trial.valmin[dir] = value;
  else 
    return 0;

  // sort values
  std::vector<double> values;
  for(int n=0;n<4;n++) values.push_back(trial.valmin[n]);
  std::sort(values.begin(),values.end());

  val0 = values[0];
  val1 = values[1];
  val2 = values[2];
  val3 = values[3];


  if (force==initimage) 
    cost = 1;
  else {
    F = *(force_buf+trial.impos);
    if (UseGaussianForce) 
      F = exp(-(F-IntensityMean)*(F-IntensityMean)/
          IntensityStandardDeviation/IntensityStandardDeviation);
    if (F==1) 
      cost=1;
    else
      if (F<1E-5)  cost = 1E5;
      else         cost = 1.0/F;
  }
    
  d1 = val1-val0;

  if ( d1 > cost ) 
    res = val0+cost;
  else 
  {
    if (val1>=maxTime) 
      res = maxTime;
    else
    {
      d1    = val2-val0;
      d2    = val2-val1;
      cost2 = cost*cost;
      if ((d1*d1+d2*d2) > cost2)
      {
        // Solve in 2D
        res = SolveQuad(
                (val0+val1)/2.0, 
                (val0*val0+val1*val1-cost2)/2.0
                );
      }
      else 
      {
        d1    = val3-val0;
        d2    = val3-val1;
        d3    = val3-val2;
        if ( (d1*d1+d2*d2+d3*d3) > cost2 ) 
          // Solve in 3D
          res = SolveQuad(
                  (val0+val1+val2)/3.0,
                  (val0*val0+val1*val1+val2*val2-cost2)/3.0
                  );
        else
          if (val3>=maxTime) 
            res = maxTime;
          else
            // Solve in 4D
            res = SolveQuad(
                    (val0+val1+val2+val3)/4.0,
                    (val0*val0+val1*val1+val2*val2+val3*val3-cost2)/4.0
                    );
      }
    } // end if
  } // end if

  if (res>maxTime)
    trial.SetValue(maxTime);
  else
    trial.SetValue(res);

//  fprintf(stderr,"LevelSetFastMarching::ComputeValue() \t case not found \n");
  return 1;

} // LevelSetFastMarching::ComputeValueSethian()

// Sorting helpers
// Sort values keeping their indices
class st_minval {
  public:
    double val;
    unsigned char index;
    st_minval(const double&v, const unsigned char& i)
    {
      val = v;
      index = i;
    }
};
bool sort_val (st_minval v1,st_minval v2) { return (v1.val<v2.val); }

//----------------------------------------------------------------------
//
// Take into account the voxel size
//
//
// Input
//    vs[i]   voxel size in the direction i
//    ivs2[i] inverse of the squared voxel size in the direction i
//
// Output
//    computes trial.value
//
inline unsigned char vtkFastMarching_nD_plus::ComputeValueSethian2( FM_TrialPoint_nD_plus& trial, float value, unsigned char dir)
//                            -------------------
{

#define macro_swap(a,b) tmp=a; a=b; b=tmp;

  register double val[4];
  register double val1[4];
  double F;
  double cost;
  double cost2;
  double d1,d2,d3;
  double  res;

  // indices
  unsigned char i0,i1,i2,i3;


  if (value<trial.valmin[dir])
    trial.valmin[dir] = value;
  else 
    return 0;

  val[0] = trial.valmin[0];
  val[1] = trial.valmin[1];
  val[2] = trial.valmin[2];
  val[3] = trial.valmin[3];


  std::vector<st_minval> minvalues;
  for(int n=0; n<4; n++)  minvalues.push_back( st_minval(trial.valmin[n],n));
  std::sort(minvalues.begin(),minvalues.end(),sort_val);

  i0 = minvalues[0].index;
  i1 = minvalues[1].index;
  i2 = minvalues[2].index;
  i3 = minvalues[3].index;


  if (force==initimage) 
    cost = 1;
  else {
    F = *(force_buf+trial.impos);
    if (UseGaussianForce) 
      F = exp(-(F-IntensityMean)*(F-IntensityMean)/
          IntensityStandardDeviation/IntensityStandardDeviation);
    if (F==1) 
      cost=1;
    else
      if (F<1E-5)  cost = 1E5;
      else         cost = 1.0/F;
  }
    
  d1 = val[i1]-val[i0];

  if ( d1 > cost*vs[i0] ) 
    res = val[i0]+cost*vs[i0];
  else {
    if (val[i1]>=maxTime) 
      res = maxTime;
    else 
    {
      cost2    = cost*cost;
      val1[i0] = val[i0]*ivs2[i0];
      val1[i1] = val[i1]*ivs2[i1];
      d1    = val[i2]-val[i0];
      d2    = val[i2]-val[i1];
      if ( (d1*d1*ivs2[i0]+d2*d2*ivs2[i1]) > cost2 )
        // Solve in 2D
        res = SolveQuad(ivs2[i0]+ivs2[i1],
                val1[i0]+val1[i1],
                val[i0]*val1[i0]+val[i1]*val1[i1]-cost2
                );
      else
      {
        val1[i2] = val[i2]*ivs2[i2];
        d1    = val[i3]-val[i0];
        d2    = val[i3]-val[i1];
        d3    = val[i3]-val[i2];
        if ( (d1*d1*ivs2[i0]+d2*d2*ivs2[i1]+d3*d3*ivs2[i2]) > cost2 )
          // Solve in 3D
          res = SolveQuad(ivs2[i0]+ivs2[i1]+ivs2[i2],
                  val1[i0]+val1[i1]+val1[i2],
                  val[i0]*val1[i0]+val[i1]*val1[i1]+val[i2]*val1[i2]-cost2
                  );
        else
        {
          if (val[i3]>=maxTime) 
            res = maxTime;
          else {
            val1[i3] = val[i3]*ivs2[i3];
            // Solve in 4D
            res = SolveQuad(ivs2[i0]+ivs2[i1]+ivs2[i2]+ivs2[i3],
                    val1[i0]+val1[i1]+val1[i2]+val1[i3],
                    val[i0]*val1[i0]+val[i1]*val1[i1]+val[i2]*val1[i2]+val[i3]*val1[i3]-cost2
                    );
          }
        }
      }
    } // end if
  } // end if

  if (res>maxTime)
    trial.SetValue(maxTime);
  else
    trial.SetValue(res);

//  fprintf(stderr,"LevelSetFastMarching::ComputeValue() \t case not found \n");
  return 1;

} // LevelSetFastMarching::ComputeValueSethian2()
 

//----------------------------------------------------------------------
void vtkFastMarching_nD_plus::PrintSelf(ostream& os, vtkIndent indent)
{
  // Nothing for the moment ...
}

/*
//----------------------------------------------------------------------
//
void vtkFastMarching_nD_plus::Init(int cx, int cy, int cz, int ct, int radius)
//
{
  this->Init3D(cx,cy,cz,ct,radius);
} // vtkFastMarching_nD_plus::Init()
*/

/*
//----------------------------------------------------------------------
//
void vtkFastMarching_nD_plus::Init2D(int cx, int cy, int radius)
//                    -----
{
    int   x, y, myrad2;
    float t,dt,NG;
    int   n;
    int   margin;
    long pos;

    float*        surf;
    float         newval,val;
    float         NGx, NGy;

    float*         T_buf1;
    unsigned char* status_buf;
    float*         surf_buf;
    float*         force_buf1;

  margin=2;

  fprintf(stderr,"vtkFastMarching_nD_plus::Init2D() 1 \n");

  myrad2 = radius+margin+margin;

  fprintf(stderr,"vtkFastMarching_nD_plus::Init2D() 2 --- \n");
  // Initialisation to maxTime and VAL_FAR

  T_buf1      = T_buf;

  fprintf(stderr,"vtkFastMarching_nD_plus::Init2D() 3 \n");
  status_buf = this->status;

  for(pos=0;pos<this->T->GetNumberOfPoints();pos++) {
    T_buf1[pos]      = maxTime;
    status_buf[pos] = VTK_VAL_FAR;
  }

  fprintf(stderr,"vtkFastMarching_nD_plus::Init2D() 4 \n");

  //  if ( GB_debug AlorsFait fprintf(stderr,"LevelSetFastMarching::Init() \t 2 \n");
    if ( (this->T->FindPoint(cx-myrad2,cy-myrad2,0)<0) ||
         (this->T->FindPoint(cx+myrad2,cy+myrad2,0)<0) 
     ) {
      //      if ( GB_debug ) fprintf(stderr,"LevelSetFastMarching::Init() \t Error, out of image \n");
      return;
    } // end if
    
    //  if ( GB_debug ) fprintf(stderr,"LevelSetFastMarching::Init() \t 3 \n");

  // Initialization of mhPos image
  surf = new float[tx*ty*tz];

    
  // initializing mhPos to 0
  surf_buf = surf;
  for(pos=0;pos<tx*ty*tz;pos++) surf_buf[pos] = 0.0;

  // Distance function around the surface
  for (x=cx-myrad2; x<=cx+myrad2; x++) {
      for(y=cy-myrad2; y<=cy+myrad2; y++) {

          val =  sqrt((double)((x-cx)*(x-cx)+
                               (y-cy)*(y-cy))) - 
              (radius-margin);


          surf_buf  = surf+x+y*tx;
          *surf_buf = val;
          
          if ( val<0 ) {
              T_buf1  = (float*) this->T->GetScalarPointer(x,y,0);
              *T_buf1 = val;
          } // end if

      }
  }


  //----- Compute the time T around the surface
  //
  // Make evolving the surface forward and backward ??
  t   = 0;
  dt = 0.01;

  for (n=1; n<=1000; n++) {

      //      if ( GB_debug ) fprintf(stderr,"LevelSetFastMarching::Init() \t 7 \n");
      for (y=cy-myrad2; y<=cy+myrad2; y++) {
          for(x=cx-myrad2; x<=cx+myrad2; x++) {

              pos = x+y*tx;
              surf_buf  = surf + pos;
              val = *surf_buf;
              
              NGx = 0;
              NGx = macro_max(NGx, val- *(surf_buf+1));
              NGx = macro_max(NGx, val- *(surf_buf-1));
              NGy = 0;
              NGy = macro_max(NGy, val- *(surf_buf+tx));
              NGy = macro_max(NGy, val- *(surf_buf-tx));
              //        NG = macro_max(NGx,NGy);
              NG = sqrt(NGx*NGx+NGy*NGy);
              
              //    if (NG>0.01) printf("x %d y %d \n", x,y);
              
              force_buf1 = force_buf + pos;
              newval = val - dt*(*force_buf1)*NG;
              if ( (val>=0)&&(newval<0) ) {
                  
                  T_buf1 = (float*) this->T->GetScalarPointer(x,y,0);
                  if ( val-newval > EPSILON ) {
                      *T_buf1 = ((t-dt)*(-newval)+t*val)/(val-newval);
                  } else {
                      *T_buf1 = t-dt;
                  } // end if
              } // end if
              *surf_buf = newval;
              
          }
      }    
      t += dt;
  }


      //  if ( GB_debug ) fprintf(stderr,"LevelSetFastMarching::Init() \t 10 \n");

      //  surf->Sauve();
      //  this->T->Sauve();

  // 1. substract d to the time image
  T_buf1 =  T_buf;
  for(pos=0;pos<T->GetNumberOfPoints();pos++) 
    if (T_buf1[pos]<999) T_buf1[pos] = T_buf1[pos]-margin;

  // 2. Set the known, trial, and far away points

  for(y=cy-myrad2; y<=cy+myrad2; y++) {
      // fprintf(stderr,"y= %d \n",y);
      for(x=cx-myrad2; x<=cx+myrad2; x++) {

          T_buf1      = (float*)         this->T     ->GetScalarPointer(x,y,0);
          status_buf = this->status+x+y*tx;
          val = *T_buf1;
          
          if ( val<=0 ) {
              *status_buf = VTK_VAL_ACCEPTED;
          } else {
              if ( val<=margin ) {
                  *status_buf = VTK_VAL_TRIAL;
                  this->mh   += FM_TrialPoint_nD_plus(x,y,0,x+y*tx,val);
              } // end if
          } // end if
          
      }
  }    

    //this->T     ->Sauve("T-init.ami.gz");
    //this->status->Sauve("status-init.ami.gz");
 std::cout << mh << std::endl;

      //  delete surf;

    fprintf(stderr," vtkFastMarching_nD_plus::Init2D() end \n");

} // vtkFastMarching_nD_plus::Init2D()
*/

/*
//----------------------------------------------------------------------
//
void vtkFastMarching_nD_plus::Init3D(int cx, int cy, int cz, int radius)
//                    -----
{

  //  
    int   d=2;
    int   x,y,z;
    int   myrad2;
    float t,dt,NG;
    int   n;
    long pos;

    float*        surf;
    float         newval,val;
    float         NGx, NGy, NGz;

    float*         T_buf1;
    unsigned char* status_buf;
    float*         surf_buf;
    float*         force_buf1;

    fprintf(stderr,"Init3D() begin \n");

  myrad2 = radius+d+d;

  // Initialisation to 1000 and VAL_FAR
  T_buf1      = T_buf;

  status_buf = this->status;

  for(pos=0;pos<this->T->GetNumberOfPoints();pos++) {
    T_buf1[pos]      = maxTime;
    status_buf[pos] = VTK_VAL_FAR;
  }


  //  if ( GB_debug AlorsFait fprintf(stderr,"LevelSetFastMarching::Init() \t 2 \n");
    if ( (this->T->FindPoint(cx-myrad2,cy-myrad2,cz-myrad2)<0) ||
         (this->T->FindPoint(cx+myrad2,cy+myrad2,cz+myrad2)<0) 
     ) {
      //      if ( GB_debug )
      fprintf(stderr,"LevelSetFastMarching::Init() \t Error, out of image \n");
      return;
    } // end if
    

  // Initialization of mhPos image
  surf = new float[tx*ty*tz];

    
  // initializing mhPos to 0
  surf_buf = surf;
  for(pos=0;pos<tx*ty*tz;pos++) surf_buf[pos] = 0.0;

  // Distance function around the surface
  for(x=cx-myrad2; x <=cx+myrad2; x++) {
      for(y=cy-myrad2; y<=cy+myrad2; y++) {
          for(z=cz-myrad2; z<=cz+myrad2; z++) {

              val =  sqrt((double)((x-cx)*(x-cx)+
                                   (y-cy)*(y-cy)+
                                   (z-cz)*(z-cz))) - 
                  (radius-d);
              
              pos = x+y*tx+z*txy;
              surf_buf  = surf+pos;
              *surf_buf = val;
              
              if ( val<0 ) {
                  T_buf1  = T_buf+pos;
                  *T_buf1 = val;
              } // end if

          }
      }
  }


  //----- Compute the time T around the surface
  //
  // Make evolving the surface forward and backward ??
  t   = 0;
  dt = 0.01;

  for(n=1; n<=1000; n++) {


      for(z=cz-myrad2; z<=cz+myrad2; z++) {
          for(y=cy-myrad2; y<=cy+myrad2; y++) {
              for(x=cx-myrad2; x<=cx+myrad2; x++) {

                  pos = x+y*tx+z*txy;
                  surf_buf  = surf + pos;
                  val = *surf_buf;
                  
                  NGx = 0;
                  NGx = macro_max(NGx, val- *(surf_buf+1));
                  NGx = macro_max(NGx, val- *(surf_buf-1));
                  NGy = 0;
                  NGy = macro_max(NGy, val- *(surf_buf+tx));
                  NGy = macro_max(NGy, val- *(surf_buf-tx));
                  NGz = 0;
                  NGz = macro_max(NGz, val- *(surf_buf+txy));
                  NGz = macro_max(NGz, val- *(surf_buf-txy));
                  NG = sqrt(NGx*NGx+NGy*NGy+NGz*NGz);
                  
                  
                  //    if (NG>0.01) printf("x %d y %d \n", x,y);
                  
                  force_buf1 = force_buf + pos;
                  newval = val - dt*(*force_buf1)*NG;
        if ( (val>=0)&&(newval<0) ) {
            
            T_buf1 = T_buf + pos;
            if ( val-newval > EPSILON ) {
                *T_buf1 = ((t-dt)*(-newval)+t*val)/(val-newval);
            } else {
                *T_buf1 = t-dt;
            } // end if
        } // end if
        *surf_buf = newval;
        
              }
          }
      }    
      t += dt;
      
    }


  // 1. substract d to the time image
  T_buf1 =  T_buf;
  for(pos=0;pos<T->GetNumberOfPoints();pos++) 
    if (T_buf1[pos]<999) T_buf1[pos] = T_buf1[pos]-d;

  // 2. Set the known, trial, and far away points

  for(z=cz-myrad2; z<=cz+myrad2; z++) {
      for(y=cy-myrad2; y<=cy+myrad2; y++) {
          for(x=cx-myrad2; x<=cx+myrad2; x++) {

              pos = x+y*tx+z*txy;
              T_buf1     = T_buf+pos;
              status_buf = this->status+pos;
              val        = *T_buf1;
              
              if ( val<=0 ) {
                  *status_buf = VTK_VAL_ACCEPTED;
              } else {
                  if ( val<=d ) {
                      *status_buf = VTK_VAL_TRIAL;
                      this->mh   += FM_TrialPoint_nD_plus(x,y,z,pos,val);
                  } // end if
              } // end if
              
          }
      }
  }    
  

 std::cout << mh << std::endl;

  fprintf(stderr,"Init3D() end \n");

} // vtkFastMarching_nD_plus::Init3D()
*/

//----------------------------------------------------------------------
//
// Initialize the Fast Marching with a given image
//  
// Inputs parameters:
//   initimage   : the initial image
//   initmaxdist : the maximal distance, accept all the intensity
//                 value lower than this distance
//                 and add all the accepted values to the trial points
//
// Modified:
//    T_buf
//    status
//    trial points
//
//  We suppose the initial image positive
//
void vtkFastMarching_nD_plus::InitWithImage()
//                    -------------
{

    short          x,y,z,t;
    unsigned char* status_buf;
    float*         init_buf;
    int            pos,i;
    int*           tab_pos;
    int            npos;

    //   fprintf(stderr, "InitWithImage() .");fflush(stderr);

  status_buf = this->status;
  init_buf   = (float*)this->initimage->GetScalarPointer();

  //  fprintf(stderr, ".");fflush(stderr);

  tab_pos = new int[imsize];
  npos = 0;
 
  // initialize status to FAR
  memset(status,VTK_VAL_FAR,imsize);

  // copy the initial image into the time
  memcpy(T_buf,init_buf,imsize*sizeof(float));

  for(pos=0;pos<imsize;pos++) 
    if (init_buf[pos]<initmaxdist) {
      status_buf[pos] = VTK_VAL_ACCEPTED;
      tab_pos[npos++] = pos;
    }

  //  Set the  trial points
  //  fprintf(stderr, ".");fflush(stderr);

  for(i=0;i<npos;i++) {
    pos = tab_pos[i];
    CoordinatesFromPosition(x,y,z,t,pos);
    AddTrialPoints(x,y,z,t,pos);
  }

  delete [] tab_pos;
  // fprintf(stderr, ";\n");

} // InitWithImage()


//----------------------------------------------------------------------
//
//  Initialize the Euclidian distance for the voxels which are neighbors
//  to the isosurface
//
//  Inputs
//    initimage
//    vs[0-2]           : voxel size
//    isotropic_voxels  : tell if we should consider the voxels isotropic of size 1x1x1
//    initiso           : threshold of the isosurface
// 
//  Outputs
//    T_buf   : pointer to the data of T (resulting time for the eikonal equation)
//
//
void vtkFastMarching_nD_plus::InitIsoSurf()
//                            -----------
{

  register float          val0_new=0,val1_new=0;
  register int            pos;
  register int            sign, neigh_sign;
  register float          val0,val1,diff;
  unsigned char           grad_computed;
  register float          norm=0;
  register float          Grad[4];
  register short          x,y,z,t;
  register float*         init_buf;
  register float*         T_buf1;
  register unsigned char* status_buf;
  register int            n;
  register float          val;
  int                     nmax=0;

  // Put the result in the time image
  init_buf   = (float*)this->initimage->GetScalarPointer();

  for(pos=0;pos<imsize;pos++) {
    if (init_buf[pos]>initiso) 
      T_buf     [pos] = maxTime;
    else 
      T_buf     [pos] = -maxTime;
  }

  // Compute the distance approximation close to the surface
  // number of directions
  nmax = 3;

  for(z=0; z<=tz-2; z++) {
    for(y=0; y<=ty-2; y++) {
      for(x=0; x<=tx-2; x++) {
        init_buf   = (float*)this->initimage->GetScalarPointer(x,y,z);
        T_buf1     = T_buf + y*inc_y + z*inc_z +x*inc_x;
        for(t=0; t<=tt-2; t++) {
          val0 =  *init_buf-initiso;
          sign = (val0>0); 
          grad_computed = 0;
          for(n=0; n<=nmax; n++) {
              val1 = *(init_buf+inc[n])-initiso;
              neigh_sign =  (val1>0);
              if (sign != neigh_sign) 
              {
                if (!grad_computed) {
                  // gradient estimation
                  if (isotropic_voxels) {
                    for(int n=0; n<=nmax; n++)
                      Grad[n] = *(init_buf+inc[n]) - *init_buf;
                  } else {
                    for(int n=0; n<=nmax; n++)
                      Grad[n] = (*(init_buf+inc[n]) - *init_buf)/vs[n];
                  }
                  // Normalization
                  norm = 0;
                  for(int n=0; n<=nmax; n++)
                    norm += Grad[n]*Grad[n];
                  norm = sqrt(norm);

                  grad_computed = 1;
                  if (norm<EPSILON) 
                    fprintf(stderr, " %d %d %d norm=%f \n",x,y,z,norm);
                }

                if (sign)
                  diff = val0-val1;
                else
                  diff = val1-val0;

                if (diff<EPSILON) {
                    fprintf(stderr," %d %d %d %d  diff = %f : val0 %f val1 %f vs[n] %f diff<1-2 \n",x,y,z,n,diff,
                            val0,val1,vs[n]);
                    continue;
                }

                val = fabs(Grad[n])/norm/diff;
                if (!isotropic_voxels)  val *= vs[n];
                if (norm>EPSILON) {
                    val0_new = val0*val;
                    val1_new = val1*val;
                }
                if (fabs(val0_new)<fabs(*T_buf1)) 
                    *T_buf1 = val0_new;
                if (fabs(val1_new)<fabs(*(T_buf1+inc[n])))
                    *(T_buf1+inc[n]) = val1_new;
              }
          }
          init_buf++;
          T_buf1++;
        }
      }
    }
  }

 
  // Now initialize with positive values and set the status image

  T_buf1     = T_buf;
  status_buf = this->status;

  fprintf(stderr, "InitIsoSurf() .");fflush(stderr);

  for(pos=0;pos<imsize;pos++) {
    if (fabs(T_buf[pos])>=maxTime) {
      T_buf1    [pos] = maxTime;
      status_buf[pos] = VTK_VAL_FAR;
    }
    else { 
      T_buf1    [pos] = fabs(T_buf[pos]);
      status_buf[pos] = VTK_VAL_ACCEPTED;
    }
  }

  //  Set the  trial points
  for(z=2; z<=tz-3; z++) {
    for(y=2; y<=ty-3; y++) {
      for(x=2; x<=tx-3; x++) {
        pos = GetPosition(x,y,z,2);
        for(t=2; t<=tt-3; t++) {
          if (fabs(T_buf1[pos])<maxTime) AddTrialPoints(x,y,z,t,pos);
          pos++;
        }
      }
    }
  }

} // InitIsoSurf()

