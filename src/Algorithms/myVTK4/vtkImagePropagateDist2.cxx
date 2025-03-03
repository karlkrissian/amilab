/*  ==================================================
    Module : vtkLevelSets
    Authors: Karl Krissian
    Email  : karl@bwh.harvard.edu

    This module implements a Active Contour evolution
    for segmentation of 2D and 3D images.
    It implements a 'codimension 2' levelsets as an
    option for the smoothing term.
    It comes with a Tcl/Tk interface for the '3D Slicer'.
    ==================================================
    Copyright (C) 2003  LMI, Laboratory of Mathematics in Imaging, 
    Brigham and Women's Hospital, Boston MA USA

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
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

    ================================================== 
   The full GNU Lesser General Public License file is in vtkLevelSets/LesserGPL_license.txt
*/

#if defined(WIN32)
  #define _CRT_SECURE_NO_WARNINGS
#endif

#include "vtkImagePropagateDist2.h"
#include "vtkObjectFactory.h"
//#include "vtkScalars.h"
#include "vtkFloatArray.h"
#include "vtkPointData.h"
#include "vtkImageData.h"
#include "vtkStructuredPointsWriter.h"

#ifndef vtkFloatingPointType
#define vtkFloatingPointType double
#endif

//#define TRUE    1
//#define FALSE   0
#define EPSILON 1E-5

#define min(x,y) (((x)<(y))?(x):(y))
#define max(x,y) (((x)>(y))?(x):(y))


#define dist2(a,b,c)  (sq[abs(a)]+sq[abs(b)]+sq[abs(c)])
#define dist(a,b,c)  (distance[abs(a)][abs(b)][abs(c)])


//vtkCxxRevisionMacro(vtkImagePropagateDist2,"$Revision: 1.0$")

//
//---------------------------------------------------------------------------
vtkImagePropagateDist2* vtkImagePropagateDist2::New()
{
  // First try to create the object from the vtkObjectFactory
  vtkObject* ret = vtkObjectFactory::CreateInstance("vtkImagePropagateDist2");
  if(ret)
    {
    return (vtkImagePropagateDist2*)ret;
    }
  // If the factory was unable to create the object, then create it here.
  return new vtkImagePropagateDist2;
}


//----------------------------------------------------------------------------
// Constructor sets default values
vtkImagePropagateDist2::vtkImagePropagateDist2()
{

  maxdist   = 10.0;
  mindist   = -10.0;

  // by default set the coefficients given in Borgefors96

  inputImage           = NULL;
  inputImage_allocated = 0;

  //  save_intermediate_images = 1;
  save_intermediate_images = 0;
  trial_loop = 0;

  narrowband = NULL;
  bandsize   = 0;

  output_array    = NULL;

  float_array = NULL;
  float_array_allocated = 0;

  list0.clear();
  list1.clear();
  list_remaining_trial.clear();
  list_elts=NULL;

} // vtkImagePropagateDist2()


//---------------------------------------------------------------------------
// Destructor
vtkImagePropagateDist2::~vtkImagePropagateDist2()
//              ---------------
{

  FreeLists();

  if (inputImage_allocated) {
    inputImage->Delete();
    inputImage=NULL;
  }

  if (float_array_allocated) {
    float_array->Delete();
    float_array = NULL;
    float_array_allocated = 0;
  }

} // ~vtkImagePropagateDist2()


//---------------------------------------------------------------------------
// Init params and copy data to float
void vtkImagePropagateDist2::InitParam( vtkImageData* input, vtkImageData* output)
//                   ---------
{
  int type;


  inputImage = input;

  if (inputImage == NULL) {
    vtkErrorMacro("Missing input");
    return;
  }
  else {

    // check the image is in float format, or convert
    type = input->GetScalarType();
    if (type != VTK_FLOAT) {
      vtkDebugMacro(<<"making a copy of the input into float format");
      // Create a copy of the data
      inputImage = vtkImageData::New();

      vtkImageData::SetScalarType( VTK_FLOAT, inputImage->GetInformation());
      vtkImageData::SetNumberOfScalarComponents(1, inputImage->GetInformation());
      inputImage->SetDimensions( input->GetDimensions());
      inputImage->SetOrigin(     input->GetOrigin());
      inputImage->SetSpacing(    input->GetSpacing());
      
      inputImage->CopyAndCastFrom(input,input->GetExtent());
      inputImage_allocated = 1;
    }
    else
      inputImage = input;

    tx = this->inputImage->GetDimensions()[0];
    ty = this->inputImage->GetDimensions()[1];
    tz = this->inputImage->GetDimensions()[2];
    txy = tx*ty;
    imsize = txy*tz;
    
    extent[0] = 0;
    extent[1] = tx-1;
    extent[2] = 0;
    extent[3] = ty-1;
    extent[4] = 0;
    extent[5] = tz-1;
                                                      
    //--- outputImage
    outputImage      = output;
    
    outputImage->SetDimensions(inputImage->GetDimensions() );
    outputImage->SetSpacing(   inputImage->GetSpacing() );
    vtkImageData::SetScalarType(VTK_FLOAT, outputImage->GetInformation()); 
    vtkImageData::SetNumberOfScalarComponents(1, outputImage->GetInformation());

    if (output_array != NULL) {
      if (float_array_allocated) {
    float_array->Delete();
    float_array = NULL;
    float_array_allocated = 0;
      }
      float_array = vtkFloatArray::New();
      float_array_allocated = 1;
      float_array->SetArray(output_array,imsize,1);
      outputImage->GetPointData()->SetScalars(float_array);
    } 
    else {
      outputImage->AllocateScalars(outputImage->GetInformation());
    }

    //    outputImage->CopyAndCastFrom(this->inputImage,
    //                                 this->inputImage->GetExtent());
  }
    
} //  InitParam()


//----------------------------------------------------------------------------
// This method is passed  input and output data, and executes the filter
// algorithm to fill the output from the input.
void vtkImagePropagateDist2::ExecuteData(vtkDataObject *outData)
//                   -------
{

  InitParam( this->GetImageDataInput(0), this->GetOutput());

  InitLists();

  if (tz == 1) {
    IsoSurfDist2D();
    PropagateDanielsson2D();
  }
  else {
    if (narrowband==NULL) IsoSurfDist3D();
    // no multithread yet ...
    else                  IsoSurfDist3D_band( 0, bandsize-1);

    //PropagateDanielsson3D();
    PropagateDanielsson3D_new();
  }

  //  FreeLists();


} // ExecuteData()

//----------------------------------------------------------------------
void vtkImagePropagateDist2::IsoSurfDist2D( )
{

  register int          x,y,p;
  register int          n;
  register int          sign, neigh_sign;
  register float        val,val0,val1,diff;
  register float        val0_new,val1_new;
  register int          displace[2];  
  register float        Grad[2];
  register vtkFloatingPointType        vs[3];
  register float        norm=0;
  unsigned char         grad_computed;
  register float*       inPtr;
  register float*       outPtr;

  this->inputImage->GetSpacing(vs);

  IsoSurfDistInit( );

  displace[0] = 1;
  displace[1] = tx;

  for(y=0; y<=ty-2; y++) {
  inPtr  = (float*) inputImage ->GetScalarPointer(0,y,0);
  for(x=0; x<=tx-2; x++) {

    val0 = *inPtr-threshold;
    sign = (val0>0); 
    grad_computed = false;

    for(n=0;n<=1;n++) {

      val1 = *(inPtr+displace[n])-threshold;
      neigh_sign =  (val1>0);

      if (sign != neigh_sign) {

    if (!grad_computed) {
      // gradient estimation
      Grad[0] = (*(inPtr+1)  - *inPtr)/vs[0];
      Grad[1] = (*(inPtr+tx) - *inPtr)/vs[1];
      
      // Normalization
      norm = sqrt(Grad[0]*Grad[0]+Grad[1]*Grad[1]);
      grad_computed = true;
      if (norm<EPSILON) 
        fprintf(stderr, " %d %d %d norm=%f \n",x,y,0,norm);
    }

    if (sign)
      diff = val0-val1;
    else
      diff = val1-val0;

        if (diff<EPSILON) {
      fprintf(stderr," %d %d %d %d  %f diff< %f \n",x,y,0,n,diff, 
          EPSILON);
      continue;
    }

    if (norm>EPSILON) {
          val = fabs(Grad[n])*vs[n]/norm/diff;
      val0_new = val0*val;
      val1_new = val1*val;

      if (fabs(val0_new)*vs[n]>1) {
        fprintf(stderr," %d %d %d %d  val0=%f val1=%f val0_new=%f \n",
            x,y,0,n,val0,val1,val0_new);
      }

      if (fabs(val1_new)*vs[n]>1) {
        fprintf(stderr," %d %d %d %d  val0=%f val1=%f val1_new=%f \n",
            x,y,0,n,val0,val1,val1_new);
      }

      outPtr  = (float*) outputImage ->GetScalarPointer(x,y,0);
      if (fabs(val0_new)<fabs(*outPtr)) {
        *outPtr = val0_new;
            p = x+y*tx;
        if (list_elts[p].GetTrack()==-1) {
          list0.push_back(p);
        }
        list_elts[p].Init(val0_new*Grad[0]/norm,
                  val0_new*Grad[1]/norm,
                  0,
                  POINT_SET_FRONT,
              p,
              val0_new*val0_new);
      } // end if
      
      outPtr  +=  displace[n];
      if (fabs(val1_new)<fabs(*outPtr)) {
        *outPtr  = val1_new;
            p = x+y*tx+displace[n];
        if (list_elts[p].GetTrack()==-1) list0.push_back(p);
        list_elts[p].Init(val1_new*Grad[0]/norm,
                  val1_new*Grad[1]/norm,
                  0,
                  POINT_SET_FRONT,
              p,
              val1_new*val1_new);
      } // end if

    } else
      fprintf(stderr,"Func_IsoSurfDist2D() \t norm<=EPSILON \n");

      } // end if (sign != sign_neigh)
    } // end for n

    inPtr++;

  } // end for x
  } // end for y


} // IsoSurfDist2D()


//----------------------------------------------------------------------
void vtkImagePropagateDist2::IsoSurfDist3D( )
{

  register int          x,y,z,p;
  register int          n;
  register int          sign, neigh_sign;
  register float        val,val0,val1,diff;
  register float        val0_new,val1_new;
  register int          displace[3];  
  register float        Grad[3];
  register vtkFloatingPointType        vs[3];
  register float        norm=0;
  unsigned char         grad_computed;
  register float*       inPtr;
  register float*       inPtr1;
  register float*       outPtr;

  fprintf(stderr,"IsoSurf3D() begin \n");

  this->inputImage->GetSpacing(vs);


  fprintf(stderr,"IsoSurf3D() initfar \n");

  IsoSurfDistInit( );

  displace[0] = 1;
  displace[1] = tx;
  displace[2] = txy;

  fprintf(stderr,"IsoSurf3D() compute \n");

  // for safety on the list...
  for(z=1; z<=tz-3; z++) {
  for(y=1; y<=ty-3; y++) {
  inPtr  = (float*) inputImage ->GetScalarPointer(1,y,z);
  for(x=1; x<=tx-3; x++) {

    val0 = *inPtr-threshold;
    sign = (val0>0); 
    grad_computed = false;

    for(n=0;n<=2;n++) {

      inPtr1 = inPtr+displace[n];
      val1 = *inPtr1-threshold;
      neigh_sign =  (val1>0);

      if (sign != neigh_sign) {

    if (!grad_computed) {
      // gradient estimation
      Grad[0] = (*(inPtr+1)  - *inPtr)/vs[0];
      Grad[1] = (*(inPtr+tx) - *inPtr)/vs[1];
      Grad[2] = (*(inPtr+txy)- *inPtr)/vs[2];

      // Normalization
      norm = sqrt(Grad[0]*Grad[0]+Grad[1]*Grad[1]+Grad[2]*Grad[2]);
      grad_computed = true;
    }
      

    if (sign)
      diff = val0-val1;
    else
      diff = val1-val0;

        if (diff<EPSILON) {
      fprintf(stderr," %d %d %d %d  %f diff< %f \n",x,y,z,n,diff,
          EPSILON);
      continue;
    }


    if (norm<EPSILON)
      fprintf(stderr, " %d %d %d norm=%f \n",x,y,z,norm);


    if (norm>EPSILON) {
          val = fabs(Grad[n])*vs[n]/norm/diff;

      val0_new = val0*val;
      val1_new = val1*val;

      outPtr  = (float*) outputImage ->GetScalarPointer(x,y,z);
      if (fabs(val0_new)<fabs(*outPtr)) {
        *outPtr = val0_new;
            p = x+y*tx+z*txy;
        if (list_elts[p].GetTrack()==-1) list0.push_back(p);
        list_elts[p].Init(val0_new*Grad[0]/norm,
                  val0_new*Grad[1]/norm,
                  val0_new*Grad[2]/norm,
                  POINT_SET_FRONT,
              p,
              ((val0_new>0)?val0_new*val0_new:-val0_new*val0_new));
      } // end if
      
      outPtr  +=  displace[n];
      if (fabs(val1_new)<fabs(*outPtr)) {
        *outPtr  = val1_new;
            p = x+y*tx+z*txy+displace[n];
        if (list_elts[p].GetTrack()==-1) list0.push_back(p);
        list_elts[p].Init(val1_new*Grad[0]/norm,
                  val1_new*Grad[1]/norm,
                  val1_new*Grad[2]/norm,
                  POINT_SET_FRONT,
              p,
              ((val1_new>0)?val1_new*val1_new:-val1_new*val1_new));
      } // end if
    } else
      fprintf(stderr,"Func_IsoSurfDist3D() \t norm<=EPSILON \n");

      } // end if  (sign != sign_neigh)
    } // end for n

    inPtr++;

  } // end for x
  } // end for y
  } // end for z

  fprintf(stderr,"IsoSurf3D() end \n");

} // IsoSurfDist3D()


//----------------------------------------------------------------------
void vtkImagePropagateDist2::IsoSurfDist3D_band( int first_band, int last_band)
{

  register int          x=0,y=0,z=0,p;
  register int          nbp; // narrow band position
  register int          i,n;
  register int          sign, neigh_sign;
  register float        val,val0,val1,diff;
  register float        val0_new,val1_new;
  register int          displace[3];  
  register float        Grad[3];
  register vtkFloatingPointType        vs[3];
  register float        norm=0;
  unsigned char         grad_computed;
  register float*       inPtr0;
  register float*       outPtr0;
  register float*       inPtr;
  register float*       outPtr;
  register float*       inPtr1;

  fprintf(stderr,"IsoSurfDist3D_band() begin \n");

  this->inputImage->GetSpacing(vs);


  fprintf(stderr,"IsoSurfDist3D_band() initfar \n");

  IsoSurfDistInit( );

  displace[0] = 1;
  displace[1] = tx;
  displace[2] = txy;

  inPtr0   = (float*) inputImage  ->GetScalarPointer();
  outPtr0  = (float*) outputImage ->GetScalarPointer();

  fprintf(stderr,"IsoSurfDist3D_band() compute \n");

  for(i=first_band;i<=last_band;i++) {

    nbp = narrowband[i];
    inPtr  = inPtr0+nbp;

    val0 = *inPtr-threshold;
    sign = (val0>0); 
    grad_computed = false;

    for(n=0;n<=2;n++) {

      inPtr1 = inPtr+displace[n];
      val1 = *inPtr1-threshold;
      neigh_sign =  (val1>0);

      if (sign != neigh_sign) {

    if (!grad_computed) {
      // gradient estimation
      Grad[0] = (*(inPtr+1)  - *inPtr)/vs[0];
      Grad[1] = (*(inPtr+tx) - *inPtr)/vs[1];
      Grad[2] = (*(inPtr+txy)- *inPtr)/vs[2];

      // Normalization
      norm = sqrt(Grad[0]*Grad[0]+Grad[1]*Grad[1]+Grad[2]*Grad[2]);
      grad_computed = true;
    }
      

    if (sign)
      diff = val0-val1;
    else
      diff = val1-val0;

        if (diff<EPSILON) {
      fprintf(stderr," %d %d %d %d  %f diff< %f \n",x,y,z,n,diff,
          EPSILON);
      continue;
    }


    if (norm<EPSILON)
      fprintf(stderr, " %d %d %d norm=%f \n",x,y,z,norm);


    if (norm>EPSILON) {
          val = fabs(Grad[n])*vs[n]/norm/diff;

      val0_new = val0*val;
      val1_new = val1*val;

      outPtr  =  outPtr0+nbp;
      if (fabs(val0_new)<fabs(*outPtr)) {
        *outPtr = val0_new;
        p = nbp;
        if (list_elts[p].GetTrack()==-1) 
          list0.push_back(p);
        list_elts[nbp].Init(val0_new*Grad[0]/norm,
                  val0_new*Grad[1]/norm,
                  val0_new*Grad[2]/norm,
                  POINT_SET_FRONT,
                p,
                val0_new*val0_new);
      } // end if
      
      outPtr  +=  displace[n];
      if (fabs(val1_new)<fabs(*outPtr)) {
        *outPtr  = val1_new;
            p = nbp+displace[n];
        if (list_elts[p].GetTrack()==-1) list0.push_back(p);
        list_elts[p].Init(val1_new*Grad[0]/norm,
                  val1_new*Grad[1]/norm,
                  val1_new*Grad[2]/norm,
                  POINT_SET_FRONT,
              p,
              val1_new*val1_new);
      } // end if
    } else
      fprintf(stderr,"Func_IsoSurfDist3D() \t norm<=EPSILON \n");

      } // end if  (sign != sign_neigh)
    } // end for n


  } // end for i, parsing narrow band

  fprintf(stderr,"IsoSurfDist3D_band() end \n");

} // IsoSurfDist3D_band()


//----------------------------------------------------------------------
void vtkImagePropagateDist2::IsoSurfDistInit( )
{

  register float*   inPtr;
  register float*   outPtr;
  register int      i;

  inPtr  = (float*) inputImage ->GetScalarPointer();
  outPtr = (float*) outputImage->GetScalarPointer();

  //  if (narrowband==NULL) {
    for (i=0; i<imsize; i++) {
      if (*inPtr > threshold)      
        *outPtr = maxdist;
      else
        if (*inPtr < threshold)      
          *outPtr = mindist;
        else                   
          *outPtr = 0;
      inPtr++;
      outPtr++;
    }
    /*
  } else {
    for(i=0;i<bandsize;i++) {
      p = narrowband[i];
      if (inPtr[p] > threshold)      
        outPtr[p] = maxdist;
      else
      if (inPtr[p] < threshold)      
        outPtr[p] = mindist;
      else                   
        outPtr[p] = 0;
    }
  }
    */

} // IsoSurfDistInit( )


//--------------------------------------------------------------
void vtkImagePropagateDist2::PropagateDanielsson2D( )
{
  // 0: know values in the front
  // 1: value to compute in the front
  register float     dx, dy;
  register int       n[8];
  register int       nx[8];
  register int       ny[8];
  register int       l;
  register int       tp;
  register int       p,pn; //, k

  int                x0, y0, x1, y1;
  float                dxp, dyp;
  float                dxpn, dypn;
  int                i, j;
  register float known_dist_pos;
  register float known_dist_neg;
  register float next_dist_pos = 0;
  register float next_dist_neg = 0;
  register float step_dist;

  int       iteration;
  float     val_min_pos, val_max_pos;
  float     val_min_neg, val_max_neg;
  register float     val;
  register float     val0;

  PD_element2 pt0;
  float* buf;
  float* bufn;
  int distmap_count = 0;
  //  PreComputeDistanceArray();

  //  memcpy(outputImage->GetScalarPointer(),
  //     inputImage->GetScalarPointer(),
  //     imsize*sizeof(float));

  buf    = ( float* ) outputImage ->GetScalarPointer();

  //------- initialize neighbors
  l = 0;
  for ( i = -1;i <= 1;i += 1 )
    for ( j = -tx;j <= tx;j += tx ) {
      if ( ( i == 0 ) && ( j == 0 ) ) continue;
      ( ( i < 0 ) ? nx[l] = -1 : ( ( i > 0 ) ? nx[l] = 1 : nx[l] = 0 ) );
      ( ( j < 0 ) ? ny[l] = -1 : ( ( j > 0 ) ? ny[l] = 1 : ny[l] = 0 ) );
      n[l] = i + j;
      l++;
    }
  if ( mindist > 0 ) mindist = 0;
  if ( maxdist < 0 ) maxdist = 0;

  step_dist  = 0.7;
  known_dist_pos = 0;
  known_dist_neg = 0;

  //--- First list list0 already created by IsoSurfDist2D

  iteration = 0;

  // Already done ...
  //  for(k=0;k<list0_size;k++) list_elts[list0[k]].SetState(POINT_SET_FRONT);
  known_dist_pos = 0;
  known_dist_neg = 0;

  printf ( "list0_size = %5d \n", ( int ) list0.size() );

  SaveDistance ( distmap_count );
  SaveState ( distmap_count );
  SaveProjection ( distmap_count++ );

  //  SaveTrajectories2D(distmap_count++);

  list_remaining_trial.clear();

  while ( ( known_dist_pos < maxdist ) || ( known_dist_neg > mindist ) ) {

    val_min_pos = maxdist;
    val_min_neg = 1;
    val_max_pos = -1;
    val_max_neg = mindist;

    iteration++;
    //    printf("known dist [%3.3f,%3.3f] \n",known_dist_neg,known_dist_pos);
    if ( known_dist_pos < maxdist ) next_dist_pos = known_dist_pos + step_dist;
    if ( known_dist_neg > mindist ) next_dist_neg = known_dist_neg - step_dist;

    //------ Create the trial points
    list1.clear();

    // Put the remaining trial points in the list
    for(int_list_it it = list_remaining_trial.begin();
        it != list_remaining_trial.end();
        it++) {
      p = *it;
      list1.push_back ( p );
      list_elts[p].SetState ( POINT_TRIAL_INLIST );
    }
    list_remaining_trial.clear();

    std::list<int>::iterator it;
    for ( it = list0.begin(); it != list0.end(); it++ ) {
      p    = *it;
      pt0  = list_elts[p];
      tp   = pt0.GetTrack();
      val0 = buf[tp];

      if ( buf[p] > 0 ) {
        val_min_pos = min ( val_min_pos, buf[p] );
        val_max_pos = max ( val_max_pos, buf[p] );
      } else {
        val_min_neg = min ( val_min_neg, buf[p] );
        val_max_neg = max ( val_max_neg, buf[p] );
      }


      x0 = p % tx;
      y0 = ( ( p - x0 ) / tx ) % ty;

      dxp = pt0.X();
      dyp = pt0.Y();

      // Check the neighbors for trial
      for ( l = 0;l < 8;l++ ) {

        // checking the scalar product
        // I should check the equivalence ...
        //        if ((dxp*nx[l]+dyp*ny[l])<0) continue;

        pn = p + n[l];
        x1 = x0 + nx[l];
        y1 = y0 + ny[l];

        // Check the limits
        if ( ( x1 >= 0 ) && ( x1 < tx ) && ( y1 >= 0 ) && ( y1 < ty ) ) {

          PD_element2& neighbor = list_elts[pn];

          switch ( neighbor.GetState() ) {
            case POINT_NOT_PARSED:
              neighbor.SetState ( POINT_TRIAL );
            case POINT_TRIAL:
              list1.push_back ( pn );
              neighbor.SetState ( POINT_TRIAL_INLIST );
            case POINT_TRIAL_INLIST:
              // Update here the values of the trial points
              dx = pt0.X() + nx[l];
              dy = pt0.Y() + ny[l];
              bufn = buf + pn;
              // Positive side
              if ( *bufn > 0 ) {
                val = sqrt ( dx * dx + dy * dy );
                if ( val < *bufn ) {
                  if ( val < known_dist_pos ) {
                    printf ( "val<known_dist_pos; val0=%f val=%f (dx,dy)=(%3.2f,%3.2f)\n", val0, val, dx, dy );
                    printf ( "point (%3d,%3d) \n", x1, y1 );
                  }
                  *bufn = val;
                  neighbor.SetPosTrack ( dx, dy, 0, tp );
                  neighbor.SetPrevNeighbor ( l );
                }
              } else
                // Negative side
                if ( *bufn < 0 ) {
                  val = - sqrt ( dx * dx + dy * dy );
                  if ( val > *bufn ) {
                    if ( val > known_dist_neg ) {
                      printf ( "val>known_dist_neg; val0=%f val=%f (dx,dy)=(%3.2f,%3.2f)\n", val0, val, dx, dy );
                      printf ( "point (%3d,%3d) \n", x1, y1 );
                    }
                    *bufn = val;
                    neighbor.SetPosTrack ( dx, dy, 0, tp );
                    neighbor.SetPrevNeighbor ( l );
                  }
                } // end if
              //        else
              //fprintf(stderr," *bufn == 0 ! \n");
              break;

            case POINT_SET_FRONT:
            case POINT_SET:
              // check for skeleton ...
              if ( ( buf[p] < 0 ) &&
                   ( buf[pn] < 0 ) &&
                   ( !pt0.GetSkeleton() ) &&
                   ( !neighbor.GetSkeleton() ) ) {
                dxpn = neighbor.X();
                dypn = neighbor.Y();
                if ( ( dxp*dxpn + dyp*dypn ) < 0 ) {
                  if ( buf[p] < buf[pn] )
                    list_elts[p].SetSkeleton ( 1 );
                  else
                    list_elts[pn].SetSkeleton ( 1 );
                }
              }

          } // end switch

        } // if pn in [0,size-1]
      } // for l in [0,7]
    } // for k in [0,list0_size-1]


    SaveDistance ( distmap_count );
    SaveState ( distmap_count );
    SaveProjection ( distmap_count++ );
    //    SaveTrajectories2D(distmap_count++);

    printf ( "pos [%2.2f, %2.2f]  neg [%2.2f, %2.2f] \n",
             val_min_pos, val_max_pos,
             val_min_neg, val_max_neg
           );

    list_elts[*it].SetState ( POINT_SET );

    // First iteration, we complete list0 ...
    if ( iteration > 1 ) list0.clear();
    known_dist_pos = next_dist_pos;
    known_dist_neg = next_dist_neg;

    //    val_min = maxdist;
    list_remaining_trial.clear();
    for ( int_list_it it = list1.begin();
          it != list1.end();
          it++ ) {
      p = *it;
      // update the list of known points in the front
      if ( ( ( buf[p] > 0 )
             && ( buf[p] <= known_dist_pos )
             && ( known_dist_pos < maxdist )
           ) ||
           (
             ( buf[p] < 0 )
             && ( buf[p] >= known_dist_neg )
             && ( known_dist_neg > mindist ) )
         ) {
        list0.push_back ( p );
        list_elts[p].SetState ( POINT_SET_FRONT );
        //    if (fabs(buf[p])<val_min)
        //      val_min = fabs(buf[p]);
      } else
        if ( ( ( buf[p] > 0 ) && ( known_dist_pos < maxdist ) ) ||
             ( ( buf[p] < 0 ) && ( known_dist_neg > mindist ) ) ) {
          list_remaining_trial.push_back(p);
          list_elts[p].SetState ( POINT_TRIAL );
        }
    }

    SaveDistance ( distmap_count );
    SaveState ( distmap_count );
    SaveProjection ( distmap_count++ );

    //    printf("list0_size = %5d  min = %f, borne max = %f \n",
    //       list0_size, val_min, known_dist_pos+step_dist);
  } // end while

  //  save_intermediate_images = 1;
  //  SaveProjection(0);
  //  SaveSkeleton(0);
  //  FreeDistanceArray();

  fprintf ( stderr, "vtkImagePropagateDist2::PropagateDanielsson2D() end \n" );

} // PropagateDanielsson2D()


//----------------------------------------------------------------------
void vtkImagePropagateDist2::PreComputeDistanceArray()
{
  int i;
  int x,y,z;
  float maxd;

  maxd = (maxdist>-mindist?maxdist:-mindist);

  //------ Precomputes distances
  sq_size = (int) (maxd+2); 
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

}

//----------------------------------------------------------------------
void vtkImagePropagateDist2::FreeDistanceArray()
{
  int x,y;

  delete [] sq;
  delete [] sqroot;

  for(x=0;x<sq_size;x++)
    for(y=0;y<sq_size;y++) delete [] distance[x][y];
  for(x=0;x<sq_size;x++) delete [] distance[x];
  delete [] distance;

} // FreeDistanceArray()

//----------------------------------------------------------------------
void vtkImagePropagateDist2::InitLists()
{
  fprintf(stderr,"vtkImagePropagateDist2::InitLists()\n");

  // list of points in the front
  list0.clear();
  // list of trial points
  list1.clear();
  // list of trial points
  list_remaining_trial.clear();

  // Use a lot of memory: to be improved ...
  if (list_elts==NULL)  
    list_elts = new PD_element2[imsize];
  else
    // lent ... mais ok pour l'instant !
    for(int i=0;i<imsize;i++) {
      list_elts[i].Init(0,0,0,POINT_NOT_PARSED,-1,0);
      list_elts[i].SetPrevNeighbor(-1);
      list_elts[i].SetSkeleton(0);
    }

  list1.clear();
  list_remaining_trial.clear();

} // InitLists()


//----------------------------------------------------------------------
void vtkImagePropagateDist2::FreeLists()
{
  //------ Allocate the information
  list0.clear();
  list1.clear();
  list_remaining_trial.clear();

  if (list_elts!=NULL) {
    delete [] list_elts;
    list_elts = NULL;
  }


} // FreeLists()


//----------------------------------------------------------------------
void vtkImagePropagateDist2::PropagateDanielsson3D( )
{

    // 0: know values in the front
    // 1: value to compute in the front  
    register float     dx,dy,dz;
    register int       n[26];
    register int       nx[26];
    register int       ny[26];
    register int       nz[26];
    register int       l;
    register int       tp;
    register int       p,k,pn;

    int                x0,y0,z0,x1,y1,z1,p0;
    float                dxp,dyp,dzp;
    float                dxpn,dypn,dzpn;
    int                i,j;
    register float known_dist_pos;
    register float known_dist_neg;
    register float next_dist_pos;
    register float next_dist_neg;
    register float step_dist;

    int       iteration;
    float     val_min_pos,val_max_pos;
    float     val_min_neg,val_max_neg;
    register float     val;
    PD_element2 pt0;
    float* buf;
    float* bufn;
    int distmap_count = 0;


    //  PreComputeDistanceArray();

    //  memcpy(outputImage->GetScalarPointer(),
    //     inputImage->GetScalarPointer(),
    //     imsize*sizeof(float));

  buf    = (float*) outputImage ->GetScalarPointer();

  //------- initialize neighbors
  l = 0;
  for(i=-1;i<=1;i+=1)
    for(j=-tx;j<=tx;j+=tx)
      for(k=-txy;k<=txy;k+=txy) {
    if ((i==0)&&(j==0)&&(k==0)) continue;
        ((i<0)?nx[l]=-1:((i>0)?nx[l]=1:nx[l]=0));
        ((j<0)?ny[l]=-1:((j>0)?ny[l]=1:ny[l]=0));
        ((k<0)?nz[l]=-1:((k>0)?nz[l]=1:nz[l]=0));
    n[l]=i+j+k;
    l++;
      }

  if (mindist>0) mindist = 0;
  if (maxdist<0) maxdist = 0;

  step_dist  = 0.6;
  known_dist_pos = 0;
  known_dist_neg = 0;

  //--- First list list0 already created by IsoSurfDist3D

  iteration = 0;

  // Already done ...
  //  for(k=0;k<list0_size;k++) list_elts[list0[k]].SetState(POINT_SET_FRONT);
  next_dist_pos = known_dist_pos = 0;
  next_dist_neg = known_dist_neg = 0;

  SaveDistance(      distmap_count);
  SaveState(         distmap_count);
  SaveTrajectories3D(distmap_count++);

  list_remaining_trial.clear();

  while ((known_dist_pos<maxdist)||(known_dist_neg>mindist)) {

    val_min_pos = maxdist; 
    val_min_neg = 1;
    val_max_pos = -1;
    val_max_neg = mindist;

    iteration++;
    printf("known dist [%3.3f,%3.3f] \n",known_dist_neg,known_dist_pos);
    if (known_dist_pos<maxdist) next_dist_pos = known_dist_pos+step_dist;
    if (known_dist_neg>mindist) next_dist_neg = known_dist_neg-step_dist;

    //------ Create the trial points
    list1.clear();

    // Put the remaining trial points in the list
    for(int_list_it it = list_remaining_trial.begin();
        it != list_remaining_trial.end();
        it++) {
      p = *it;
      list1.push_back(p);
      list_elts[p].SetState(POINT_TRIAL_INLIST);
    }
    list_remaining_trial.clear();

    std::list<int>::iterator it;
    for(it=list0.begin();it!=list0.end();it++) {
      p    = *it;
      pt0  = list_elts[p];
      tp   = pt0.GetTrack();

      if (buf[p]>0) {
       val_min_pos = min(val_min_pos,buf[p]);
       val_max_pos = max(val_max_pos,buf[p]);
      } else {
       val_min_neg = min(val_min_neg,buf[p]);
       val_max_neg = max(val_max_neg,buf[p]);
      }

      x0 = p%tx;
      p0 = (p-x0)/tx;
      y0 = p0%ty;
      z0 = (p0-y0)/ty;

      dxp = pt0.X();
      dyp = pt0.Y();
      dzp = pt0.Z();

      // Check the neighbors for trial
      for(l=0;l<26;l++) {
    
    //        if ((dxp*nx[l]+dyp*ny[l]+dzp*nz[l])<0) continue;
    
    pn = p+n[l];
    x1 = x0+nx[l];
    y1 = y0+ny[l];
    z1 = z0+nz[l];
        // Check the limits
    if   ((x1>=0)&&(x1<tx)&&
            (y1>=0)&&(y1<ty)&&
            (z1>=0)&&(z1<tz))
      
      {


        PD_element2& neighbor = list_elts[pn];

        if (neighbor.GetTrack()==tp) continue;


    switch (neighbor.GetState()) {
    case POINT_NOT_PARSED:
      neighbor.SetState(POINT_TRIAL);
    case POINT_TRIAL:
      list1.push_back(pn);
      neighbor.SetState(POINT_TRIAL_INLIST);
    case POINT_TRIAL_INLIST:
      dx = pt0.X()+nx[l];
      dy = pt0.Y()+ny[l];
      dz = pt0.Z()+nz[l];
      bufn = buf+pn;
      // Positive side
      if (*bufn>0) {
        val =  dx*dx+dy*dy+dz*dz;
        if (val<*bufn) {
          /*
        if (val<known_dist_pos) {
        printf("val<known_dist_pos; val0=%f val=%f (dx,dy,dz)=(%f,%f,%f)\n",val0, val,dx,dy,dz);
        printf("point (%3d,%3d,%3d) \n",x1,y1,z1);
        }
          */
          *bufn = val;
          neighbor.SetPosTrack( dx,dy,dz, tp);
          neighbor.SetPrevNeighbor(l);
        }
      } else
        // Negative side
        if (*bufn<0) {
          val =  - dx*dx+dy*dy+dz*dz;
          if (val>*bufn) {
        /*
          if (val>known_dist_neg) {
          printf("val>known_dist_neg; val0=%f val=%f (dx,dy,dz)=(%f,%f,%f)\n",val0,val,dx,dy,dz);
          printf("point (%3d,%3d,%3d) \n",x1,y1,z1);
          }
        */
        *bufn = val;
        neighbor.SetPosTrack( dx,dy,dz, tp);
        neighbor.SetPrevNeighbor(l);
          }
        } // end if
      //        else
      //  fprintf(stderr," *bufn == 0 ! \n");
      break;
      
        case POINT_SET_FRONT:
        case POINT_SET:
        // check for skeleton ...
        if ((buf[p]<0)&&
        (buf[pn]<0)&&
        (!pt0.GetSkeleton())&&
        (!neighbor.GetSkeleton())) 
        {
        
        dxpn = neighbor.X();
        dypn = neighbor.Y();
        dzpn = neighbor.Z();
        if ((dxp*dxpn+dyp*dypn+dzp*dzpn)<0) {
        if (buf[p]<buf[pn])
            list_elts[p].SetSkeleton(1);
        else
            list_elts[pn].SetSkeleton(1);
        }
        } 
      
    } // end switch
    
      } // if pn in [0,size-1]
      } // for l in [0,25]
    } // for 
    

    SaveDistance(      distmap_count);
    SaveState(         distmap_count);
    SaveTrajectories3D(distmap_count++);

    printf("pos [%2.2f, %2.2f]  neg [%2.2f, %2.2f] \n",
      val_min_pos,val_max_pos,
      val_min_neg,val_max_neg
      );

    for(int_list_it it=list0.begin();it!=list0.end();it++)  
      list_elts[*it].SetState( POINT_SET);

    // First iteration, we complete list0 ...
    if (iteration>1) {
      list0.clear();
    }

    known_dist_pos = next_dist_pos;
    known_dist_neg = next_dist_neg;

    //    val_min = maxdist;
    list_remaining_trial.clear();

    for ( int_list_it it = list1.begin();
          it != list1.end();
          it++) {
      p = *it;

      // update the list of known points in the front
      if (((buf[p]>0)&&(buf[p]<=known_dist_pos)&&(known_dist_pos<maxdist))||
          ((buf[p]<0)&&(buf[p]>=known_dist_neg)&&(known_dist_neg>mindist))) {
        list0.push_back(p);
        list_elts[p].SetState( POINT_SET_FRONT);
        //if (fabs(buf[p])<val_min)
        //  val_min = fabs(buf[p]);
      }
      else 
        if (((buf[p]>0)&&(known_dist_pos<maxdist))||
           ((buf[p]<0)&&(known_dist_neg>mindist)))
        {
          list_remaining_trial.push_back(p);
          list_elts[p].SetState( POINT_TRIAL);
      }
    }



  } // end while


} // PropagateDanielsson3D()


float vtkImagePropagateDist2::ComputeDistance(const float& dx, const float& dy, const float& dz)
{
  //  return sqrt(dx*dx+dy*dy+dz*dz);
  return dx*dx+dy*dy+dz*dz;
}

//----------------------------------------------------------------------
void vtkImagePropagateDist2::new3D_update_neighbors2( const int& p,  int* n, float* buf)
{

    register int       tp,pn;
    register float     dxp,dyp,dzp;
    register int       p0,x0,y0,z0;

    list_elts[p].GetPosTrack(dxp,dyp,dzp,tp);

    x0 = p%tx;
    p0 = (p-x0)/tx;
    y0 = p0%ty;
    z0 = (p0-y0)/ty;
  
    // Check for image limits...

    register float    dxpp = dxp+1;
    register float    dxpm = dxp-1;

    register float    dypp = dyp+1;
    register float    dypm = dyp-1;

    register float    dzpp = dzp+1;
    register float    dzpm = dzp-1;

    /* this optimition seems slower in fact
    register float  dxp2  = dxp+dxp;
    register float  dxp2p = 1+dxp2;
    register float  dxp2m = 1-dxp2;

    register float  dyp2  = dyp+dyp;
    register float  dyp2p = 1+dyp2;
    register float  dyp2m = 1-dyp2;

    register float  dzp2  = dzp+dzp;
    register float  dzp2p = 1+dzp2;
    register float  dzp2m = 1-dzp2;
    */

    register float current_dist=list_elts[p].GetSquareDist();
    if (current_dist<0) current_dist=-current_dist;

    register float    val; 

    // This procedure is not safe because we can endup out of the image ...

    // go manually through all neighbors ???

#define DISTANCE(x,y,z) (x*x+y*y+z*z) 
    //#define DISTANCE(x,y,z) ComputeDistance(x,y,z)

// TODO: get rid of this macro ..
#define DIRECT_NEIGHBOR(incim,dx1,dy1,dz1,sum) {    \
    pn = p+incim; \
    switch (list_elts[pn].GetState()) { \
    case POINT_NOT_PARSED:  { \
    register PD_element2& neighbor = list_elts[pn]; \
    list1.push_back(pn); \
    neighbor.SetState(POINT_TRIAL_INLIST);\
    val =    DISTANCE(dx1,dy1,dz1);\
    if (buf[pn]<=0)   val =  -val;\
    neighbor.SetPosTrack( dx1,dy1,dz1, tp, val);\
      }  break;\
\
    case POINT_TRIAL_INLIST:  {\
    register PD_element2& neighbor = list_elts[pn];\
    if (neighbor.GetTrack()==tp) break;\
    register float     neigh_dist;\
\
    neigh_dist = neighbor.GetSquareDist();\
    val = DISTANCE(dx1,dy1,dz1);\
    if (neigh_dist>0) {\
      if (val<neigh_dist)  neighbor.SetPosTrack( dx1,dy1,dz1, tp,val);\
    } else {\
      val=-val;\
      if (val>neigh_dist) neighbor.SetPosTrack( dx1,dy1,dz1, tp,val);\
    }\
      }  break;\
    }} // end switch // end of DEFINE block 

    // we could get rid of the last parameter: sum
    // -X+Y+Z+ -X+Y+Z- -X-Y-Z+ -X+-Y-Z-

    if (x0>0) {
      if (y0>0) {
        if (z0>0)  DIRECT_NEIGHBOR(n[0],  dxpm, dypm, dzpm, dxp2m+dyp2m+dzp2m)
                   DIRECT_NEIGHBOR(n[1],  dxpm, dypm, dzp , dxp2m+dyp2m      )
        if (z0<tz-1) DIRECT_NEIGHBOR(n[2],  dxpm, dypm, dzpp, dxp2m+dyp2m+dzp2p)
      }

      if (z0>0)  DIRECT_NEIGHBOR(n[3],  dxpm, dyp,  dzpm, dxp2m      +dzp2m)
                 DIRECT_NEIGHBOR(  -1,  dxpm, dyp,  dzp , dxp2m            )
      if (z0<tz-1) DIRECT_NEIGHBOR(n[5],  dxpm, dyp,  dzpp, dxp2m      +dzp2p)

      if (y0<ty-1) {
        if (z0>0)  DIRECT_NEIGHBOR(n[6],  dxpm, dypp, dzpm, dxp2m+dyp2p+dzp2m)
                   DIRECT_NEIGHBOR(n[7],  dxpm, dypp, dzp , dxp2m+dyp2p      )
        if (z0<tz-1) DIRECT_NEIGHBOR(n[8],  dxpm, dypp, dzpp, dxp2m+dyp2p+dzp2p)
      }
    }

    if (y0>0) {
      if (z0>0)  DIRECT_NEIGHBOR(n[9],  dxp,  dypm, dzpm,       dyp2m+dzp2m)
                 DIRECT_NEIGHBOR( -tx,  dxp,  dypm, dzp ,       dyp2m      )
      if (z0<tz-1) DIRECT_NEIGHBOR(n[11], dxp,  dypm, dzpp,       dyp2m+dzp2p)
    }

    if (z0>0)  DIRECT_NEIGHBOR( -txy, dxp,  dyp,  dzpm,             dzp2m)
    if (z0<tz-1) DIRECT_NEIGHBOR(  txy, dxp,  dyp,  dzpp,             dzp2p)

    if (y0<ty-1) {
      if (z0>0)  DIRECT_NEIGHBOR(n[14], dxp,  dypp, dzpm,       dyp2p+dzp2m)
                 DIRECT_NEIGHBOR( tx,   dxp,  dypp, dzp ,       dyp2p      )
      if (z0<tz-1) DIRECT_NEIGHBOR(n[16], dxp,  dypp, dzpp,       dyp2p+dzp2p)
    }

    if (x0<tx-1) {
      if (y0>0) {
        if (z0>0)  DIRECT_NEIGHBOR(n[17], dxpp, dypm, dzpm,dxp2p+dyp2m +dzp2m)
                   DIRECT_NEIGHBOR(n[18], dxpp, dypm, dzp ,dxp2p+dyp2m      )
        if (z0<tz-1) DIRECT_NEIGHBOR(n[19], dxpp, dypm, dzpp,dxp2p+dyp2m +dzp2p)
      }

      if (z0>0)  DIRECT_NEIGHBOR(n[20], dxpp, dyp,  dzpm,dxp2p+       dzp2m)
                 DIRECT_NEIGHBOR( 1,    dxpp, dyp,  dzp ,dxp2p            )
      if (z0<tz-1) DIRECT_NEIGHBOR(n[22], dxpp, dyp,  dzpp,dxp2p+       dzp2p)

      if (y0<ty-1) {
        if (z0>0)  DIRECT_NEIGHBOR(n[23], dxpp, dypp, dzpm,dxp2p+dyp2p +dzp2m)
                   DIRECT_NEIGHBOR(n[24], dxpp, dypp, dzp ,dxp2p+dyp2p      )
        if (z0<tz-1) DIRECT_NEIGHBOR(n[25], dxpp, dypp, dzpp,dxp2p+dyp2p +dzp2p)
      }
    }


} // new3D_update_neighbors2



//----------------------------------------------------------------------
void vtkImagePropagateDist2::new3D_update_neighbors( int p, int* n, int* nx, int* ny, int* nz, float* buf)
{

    register int       l;
    register int       tp,pn;
    float              dxp,dyp,dzp;

    list_elts[p].GetPosTrack(dxp,dyp,dzp,tp);
    // go manually through all neighbors ???

    // Check the neighbors for trial
    for(l=0;l<26;l++) {
       //neighbors_type[state]++;

      pn = p+n[l];
      switch (list_elts[pn].GetState()) {
     
       case POINT_SET_FRONT:  continue;
       case POINT_SET:        continue;
       case POINT_NOT_PARSED:
     {
       register float     val;
       register float     dx,dy,dz;
       PD_element2& neighbor = list_elts[pn];
         list1.push_back(pn);
         neighbor.SetState(POINT_TRIAL_INLIST);
         dx = dxp+nx[l];
         dy = dyp+ny[l];
         dz = dzp+nz[l];
         if (buf[pn]>0)   val =    ComputeDistance(dx,dy,dz);
         else             val =  - ComputeDistance(dx,dy,dz);
         neighbor.SetPosTrack( dx,dy,dz, tp, val);
     neighbor.SetPrevNeighbor(l);
     }
         break;
       case POINT_TRIAL_INLIST:
     {

     PD_element2& neighbor = list_elts[pn];
     if (neighbor.GetTrack()==tp) {
       int l1 = neighbor.GetPrevNeighbor();
       int pnl1 = pn-n[l1];
       if (fabs(neighbor.GetSquareDist()-list_elts[p].GetSquareDist())>
           fabs(neighbor.GetSquareDist()-list_elts[pnl1].GetSquareDist()))
         {
           neighbor.SetPrevNeighbor(l);
         }
       total_track_discarded++;
       continue;
     }
       register float     neigh_dist;
       register float     val;
       register float     dx,dy,dz;

         dx = dxp+nx[l];
         dy = dyp+ny[l];
         dz = dzp+nz[l];
         neigh_dist = neighbor.GetSquareDist();
         // Positive side
         if (neigh_dist>0) {
           val =  ComputeDistance(dx,dy,dz);
           if (val<neigh_dist) {
             neighbor.SetPosTrack( dx,dy,dz, tp,val);
         neighbor.SetPrevNeighbor(l);
       }
           
         } else {
           // Negative side
       val =  - ComputeDistance(dx,dy,dz);
       if (val>neigh_dist) {
         neighbor.SetPosTrack( dx,dy,dz, tp,val);
         neighbor.SetPrevNeighbor(l);
       }
         } // end if
     }
         break;
      } // end switch
    
      } // for l in [0,25]

}

//----------------------------------------------------------------------
void vtkImagePropagateDist2::PropagateDanielsson3D_new( )
{

  // 0: know values in the front
  // 1: value to compute in the front
  register int       n[26];
  register int       nx[26];
  register int       ny[26];
  register int       nz[26];
  register int       l;
  register int       p, k;
  int                i, j;
  register float known_dist_pos;
  register float known_dist_neg;
  register float known_dist_pos2;
  register float known_dist_neg2;
  register float next_dist_pos;
  register float next_dist_neg;
  register float step_dist;

  int       iteration;
  register float     val;

  PD_element2 pt0;
  float* buf;
  int distmap_count = 0;



  //  PreComputeDistanceArray();

  //  memcpy(outputImage->GetScalarPointer(),
  //     inputImage->GetScalarPointer(),
  //     imsize*sizeof(float));

  buf    = ( float* ) outputImage ->GetScalarPointer();

  //------- initialize neighbors
  l = 0;
  for ( i = -1;i <= 1;i += 1 )
    for ( j = -tx;j <= tx;j += tx )
      for ( k = -txy;k <= txy;k += txy ) {
        if ( ( i == 0 ) && ( j == 0 ) && ( k == 0 ) ) continue;
        ( ( i < 0 ) ? nx[l] = -1 : ( ( i > 0 ) ? nx[l] = 1 : nx[l] = 0 ) );
        ( ( j < 0 ) ? ny[l] = -1 : ( ( j > 0 ) ? ny[l] = 1 : ny[l] = 0 ) );
        ( ( k < 0 ) ? nz[l] = -1 : ( ( k > 0 ) ? nz[l] = 1 : nz[l] = 0 ) );
        n[l] = i + j + k;
        l++;
      }

  if ( mindist > 0 ) mindist = 0;
  if ( maxdist < 0 ) maxdist = 0;

  step_dist  = 0.6;
  known_dist_pos = 0;
  known_dist_neg = 0;

  //--- First list list0 already created by IsoSurfDist3D

  iteration = 0;

  // Already done ...
  //  for(k=0;k<list0_size;k++) list_elts[list0[k]].SetState(POINT_SET_FRONT);
  next_dist_pos = known_dist_pos = 0;
  next_dist_neg = known_dist_neg = 0;

  SaveDistance ( distmap_count );
  SaveState ( distmap_count );
  SaveTrajectories3D ( distmap_count++ );

  list_remaining_trial.clear();

  while ( ( known_dist_pos < maxdist ) || ( known_dist_neg > mindist ) ) {

    iteration++;
    printf ( "known dist [%3.3f,%3.3f] \n", known_dist_neg, known_dist_pos );
    if ( known_dist_pos < maxdist ) next_dist_pos = known_dist_pos + step_dist;
    if ( known_dist_neg > mindist ) next_dist_neg = known_dist_neg - step_dist;

    //------ Create the trial points
    list1.swap(list_remaining_trial);
    list_remaining_trial.clear();

    for ( k = 0;k < 5;k++ ) neighbors_type[k] = 0;
    total_track_discarded = 0;
    min_dist_neighbors = 3;


    //    printf("list0_size .. = %9d \n",list0_size);
    for (int_list_it it = list0.begin();it != list0.end();it++ )  {
      new3D_update_neighbors2 ( *it, n, buf );
    }

    /*
    for(k=0;k<5;k++) {
      printf("neighbors_type[%d] \t %8d \n",k,neighbors_type[k]);
    }
    printf("total_track_discarded=%d \n",total_track_discarded);
    */

    // Apply the square root to the points that are already set
    for ( int_list_it it = list0.begin();
          it != list0.end();
          it++ )  {
      p = *it;
      list_elts[p].SetState ( POINT_SET );
      val = list_elts[p].GetSquareDist();
      if ( val > 0 )
        buf[p] = sqrt ( val );
      else
        buf[p] = -sqrt ( -val );

      int l = list_elts[p].GetPrevNeighbor();
      if ( l != -1 ) {
        float val0 = buf[p-n[l]];
        if ( fabs ( buf[p] - val0 ) < min_dist_neighbors )
          min_dist_neighbors = fabs ( buf[p] - val0 );
      }
    }

    printf ( "min dist = %f \n", min_dist_neighbors );


    // First iteration, we complete list0 ...
    if ( iteration > 1 ) {
      list0.clear();
    }


    known_dist_pos = next_dist_pos;
    known_dist_neg = next_dist_neg;

    known_dist_pos2 = known_dist_pos * known_dist_pos;
    known_dist_neg2 = -known_dist_neg * known_dist_neg;

    //    val_min = maxdist;
    list_remaining_trial.clear();
    i = 0;

    printf ( "list1_size = %9d \n", (int)list1.size() );

    for ( int_list_it it = list1.begin();
          it != list1.end();
          it++) {
      p = *it;
      val = list_elts[p].GetSquareDist();
      // update the list of known points in the front
      if ( ( ( val > 0 ) && ( val <= known_dist_pos2 ) && ( known_dist_pos < maxdist ) ) ||
           ( ( val < 0 ) && ( val >= known_dist_neg2 ) && ( known_dist_neg > mindist ) ) ) {
        list0.push_back ( p );
        list_elts[p].SetState ( POINT_SET_FRONT );
        //if (fabs(buf[p])<val_min)
        //  val_min = fabs(buf[p]);
      } else
        if ( ( ( val > 0 ) && ( known_dist_pos < maxdist ) ) ||
             ( ( val < 0 ) && ( known_dist_neg > mindist ) ) ) {
          list_remaining_trial.push_back(p);
          list_elts[p].SetState ( POINT_TRIAL_INLIST );
          i++;
        }
    }
    printf ( "number of points set to trial %d \n", i );

  } // end while

} // PropagateDanielsson3D_new()



//----------------------------------------------------------------------
void vtkImagePropagateDist2::SaveTrajectories2D( int num)
{

  if (!save_intermediate_images) return;  

  register int       l;
  register int       nx[8];
  register int       ny[8];
  
  
  vtkStructuredPointsWriter *writer = vtkStructuredPointsWriter::New();
  vtkImageData* copyImage = vtkImageData::New();
  float* ptr;
  char name[255];
  int  i,j;
  
  // Initialize neighbors
  l = 0;
  for(i=-1;i<=1;i+=1)
    for(j=-tx;j<=tx;j+=tx)
      {
    if ((i==0)&&(j==0)) continue;
    ((i<0)?nx[l]=-1:((i>0)?nx[l]=1:nx[l]=0));
    ((j<0)?ny[l]=-1:((j>0)?ny[l]=1:ny[l]=0));
    l++;
      }
  
  vtkImageData::SetScalarType( VTK_FLOAT, copyImage->GetInformation());
  vtkImageData::SetNumberOfScalarComponents(1, copyImage->GetInformation());
  copyImage->SetDimensions( outputImage->GetDimensions());
  copyImage->SetOrigin(     outputImage->GetOrigin());
  copyImage->SetSpacing(    outputImage->GetSpacing());
  
  copyImage->AllocateScalars( copyImage->GetInformation());
  //     copyImage->CopyAndCastFrom(outputImage,
  //                outputImage->GetExtent());

  // Save X component  
  ptr = (float*) copyImage->GetScalarPointer();
  for(i=0;i<imsize;i++) {
    if (list_elts[i].GetPrevNeighbor()!=-1)
      *ptr = nx[(int)list_elts[i].GetPrevNeighbor()];
    else
      *ptr = 0;
    ptr++;
  }
  
  writer->SetInputData(copyImage);
  sprintf(name,"trajectory%d_X.vtk",num);
  writer->SetFileName(name);
  writer->SetFileTypeToBinary();
  writer->Write();

  fprintf(stderr,"%s saved \n",name);

  // Save Y component  
  ptr = (float*) copyImage->GetScalarPointer();
  for(i=0;i<imsize;i++) {
    if (list_elts[i].GetPrevNeighbor()!=-1)
      *ptr = ny[(int)list_elts[i].GetPrevNeighbor()];
    else
      *ptr = 0;
    ptr++;
  }
  
  writer->SetInputData(copyImage);
  sprintf(name,"trajectory%d_Y.vtk",num);
  writer->SetFileName(name);
  writer->SetFileTypeToBinary();
  writer->Write();


  copyImage->Delete();
  writer->Delete();

  fprintf(stderr,"%s saved \n",name);

} // SaveTrajectories2D()


//----------------------------------------------------------------------
void vtkImagePropagateDist2::SaveTrajectories3D( int num)
{

  if (!save_intermediate_images) return;  

  register int       l;
  register int       nx[26];
  register int       ny[26];
  register int       nz[26];
  
  
  vtkStructuredPointsWriter *writer = vtkStructuredPointsWriter::New();
  vtkImageData* copyImage = vtkImageData::New();
  float* ptr;
  char name[255];
  int  i,j,k;
  
  // Initialize neighbors
  l = 0;
  for(i=-1;i<=1;i+=1)
    for(j=-tx;j<=tx;j+=tx)
      for(k=-txy;k<=txy;k+=txy) {
    if ((i==0)&&(j==0)&&(k==0)) continue;
        ((i<0)?nx[l]=-1:((i>0)?nx[l]=1:nx[l]=0));
        ((j<0)?ny[l]=-1:((j>0)?ny[l]=1:ny[l]=0));
        ((k<0)?nz[l]=-1:((k>0)?nz[l]=1:nz[l]=0));
    l++;
      }
  
  vtkImageData::SetScalarType( VTK_FLOAT, copyImage->GetInformation());
  vtkImageData::SetNumberOfScalarComponents(1, copyImage->GetInformation());
  copyImage->SetDimensions( outputImage->GetDimensions());
  copyImage->SetOrigin(     outputImage->GetOrigin());
  copyImage->SetSpacing(    outputImage->GetSpacing());
  
  copyImage->AllocateScalars(copyImage->GetInformation());
  //     copyImage->CopyAndCastFrom(outputImage,
  //                outputImage->GetExtent());

  // Save X component  
  ptr = (float*) copyImage->GetScalarPointer();
  for(i=0;i<imsize;i++) {
    if (list_elts[i].GetPrevNeighbor()!=-1)
      *ptr = nx[(int)list_elts[i].GetPrevNeighbor()];
    else
      *ptr = 0;
    ptr++;
  }
  
  writer->SetInputData(0,copyImage);
  sprintf(name,"trajectory%d_X.vtk",num);
  writer->SetFileName(name);
  writer->SetFileTypeToBinary();
  writer->Write();

  fprintf(stderr,"%s saved \n",name);

  // Save Y component  
  ptr = (float*) copyImage->GetScalarPointer();
  for(i=0;i<imsize;i++) {
    if (list_elts[i].GetPrevNeighbor()!=-1)
      *ptr = ny[(int)list_elts[i].GetPrevNeighbor()];
    else
      *ptr = 0;
    ptr++;
  }
  
  writer->SetInputData(copyImage);
  sprintf(name,"trajectory%d_Y.vtk",num);
  writer->SetFileName(name);
  writer->SetFileTypeToBinary();
  writer->Write();

  // Save Z component  
  ptr = (float*) copyImage->GetScalarPointer();
  for(i=0;i<imsize;i++) {
    if (list_elts[i].GetPrevNeighbor()!=-1)
      *ptr = nz[(int)list_elts[i].GetPrevNeighbor()];
    else
      *ptr = 0;
    ptr++;
  }
  
  writer->SetInputData(copyImage);
  sprintf(name,"trajectory%d_Z.vtk",num);
  writer->SetFileName(name);
  writer->SetFileTypeToBinary();
  writer->Write();


  copyImage->Delete();
  writer->Delete();

  fprintf(stderr,"%s saved \n",name);

} // SaveTrajectories3D()


//----------------------------------------------------------------------
void vtkImagePropagateDist2::SaveProjection( int num)
{

  if (!save_intermediate_images) return;  

  
  vtkStructuredPointsWriter *writer = vtkStructuredPointsWriter::New();
  vtkImageData* copyImageX = vtkImageData::New();
  vtkImageData* copyImageY = vtkImageData::New();
  vtkImageData* copyImageZ = vtkImageData::New();
  float* ptrX;
  float* ptrY;
  float* ptrZ;
  char name[255];
  int  i;
  
  
  vtkImageData::SetScalarType( VTK_FLOAT,       copyImageX->GetInformation());
  vtkImageData::SetNumberOfScalarComponents(1,  copyImageX->GetInformation());
  copyImageX->SetDimensions( outputImage->GetDimensions());
  copyImageX->SetOrigin(     outputImage->GetOrigin());
  copyImageX->SetSpacing(    outputImage->GetSpacing());
  copyImageX->AllocateScalars(copyImageX->GetInformation());

  vtkImageData::SetScalarType( VTK_FLOAT,       copyImageY->GetInformation());
  vtkImageData::SetNumberOfScalarComponents(1,  copyImageY->GetInformation());
  copyImageY->SetDimensions( outputImage->GetDimensions());
  copyImageY->SetOrigin(     outputImage->GetOrigin());
  copyImageY->SetSpacing(    outputImage->GetSpacing());
  copyImageY->AllocateScalars(copyImageY->GetInformation());

  vtkImageData::SetScalarType( VTK_FLOAT,       copyImageZ->GetInformation());
  vtkImageData::SetNumberOfScalarComponents(1,  copyImageZ->GetInformation());
  copyImageZ->SetDimensions( outputImage->GetDimensions());
  copyImageZ->SetOrigin(     outputImage->GetOrigin());
  copyImageZ->SetSpacing(    outputImage->GetSpacing());
  copyImageZ->AllocateScalars(copyImageZ->GetInformation());


  ptrX = (float*) copyImageX->GetScalarPointer();
  ptrY = (float*) copyImageY->GetScalarPointer();
  ptrZ = (float*) copyImageZ->GetScalarPointer();
  for(i=0;i<imsize;i++) {
    *ptrX = -list_elts[i].X();
    *ptrY = -list_elts[i].Y();
    *ptrZ = -list_elts[i].Z();
    
    ptrX++;
    ptrY++;
    ptrZ++;
  }
  
  writer->SetInputData(copyImageX);
  sprintf(name,"projection%d_X.vtk",num);
  writer->SetFileName(name);
  writer->SetFileTypeToBinary();
  writer->Write();

  fprintf(stderr,"%s saved \n",name);

  writer->SetInputData(copyImageY);
  sprintf(name,"projection%d_Y.vtk",num);
  writer->SetFileName(name);
  writer->SetFileTypeToBinary();
  writer->Write();

  fprintf(stderr,"%s saved \n",name);

  writer->SetInputData(copyImageZ);
  sprintf(name,"projection%d_Z.vtk",num);
  writer->SetFileName(name);
  writer->SetFileTypeToBinary();
  writer->Write();

  fprintf(stderr,"%s saved \n",name);

  copyImageX->Delete();
  copyImageY->Delete();
  copyImageZ->Delete();
  writer->Delete();

} // SaveProjection()


//----------------------------------------------------------------------
void vtkImagePropagateDist2::SaveState( int num)
{
  int i;

  if (!save_intermediate_images) return;  

  vtkStructuredPointsWriter *writer = vtkStructuredPointsWriter::New();
  vtkImageData* copyImage = vtkImageData::New();
  unsigned char* ptr;
  char name[255];
  
  vtkImageData::SetScalarType( VTK_UNSIGNED_CHAR, copyImage->GetInformation());
  vtkImageData::SetNumberOfScalarComponents(1,    copyImage->GetInformation());
  copyImage->SetDimensions( outputImage->GetDimensions());
  copyImage->SetOrigin(     outputImage->GetOrigin());
  copyImage->SetSpacing(    outputImage->GetSpacing());
  
  copyImage->AllocateScalars(copyImage->GetInformation());
  //     copyImage->CopyAndCastFrom(outputImage,
  //                outputImage->GetExtent());

  // Save state
  ptr = (unsigned char*) copyImage->GetScalarPointer();
  for(i=0;i<imsize;i++) {
    *ptr = list_elts[i].GetState();
    ptr++;
  }
  
  writer->SetInputData(copyImage);
  sprintf(name,"State%d.vtk",num);
  writer->SetFileName(name);
  writer->SetFileTypeToBinary();
  writer->Write();

  fprintf(stderr,"%s saved \n",name);

  copyImage->Delete();
  writer->Delete();


} // SaveState()


//----------------------------------------------------------------------
void vtkImagePropagateDist2::SaveSkeleton( int num)
{

  if (!save_intermediate_images) return;  

  
  vtkStructuredPointsWriter *writer = vtkStructuredPointsWriter::New();
  vtkImageData* copyImage = vtkImageData::New();
  unsigned char* ptr;
  char name[255];
  int  i;
  
  
  vtkImageData::SetScalarType( VTK_UNSIGNED_CHAR, copyImage->GetInformation());
  vtkImageData::SetNumberOfScalarComponents(1,    copyImage->GetInformation());
  copyImage->SetDimensions( outputImage->GetDimensions());
  copyImage->SetOrigin(     outputImage->GetOrigin());
  copyImage->SetSpacing(    outputImage->GetSpacing());
  
  copyImage->AllocateScalars(copyImage->GetInformation());
  //     copyImage->CopyAndCastFrom(outputImage,
  //                outputImage->GetExtent());

  // Save skeleton
  ptr = (unsigned char*) copyImage->GetScalarPointer();
  for(i=0;i<imsize;i++) {
    *ptr = list_elts[i].GetSkeleton();
    ptr++;
  }
  
  writer->SetInputData(copyImage);
  sprintf(name,"Skeleton%d.vtk",num);
  writer->SetFileName(name);
  writer->SetFileTypeToBinary();
  writer->Write();

  fprintf(stderr,"%s saved \n",name);

  copyImage->Delete();
  writer->Delete();

} // SaveSkeleton()


//----------------------------------------------------------------------
void vtkImagePropagateDist2::SaveDistance( int num)
{

  if (!save_intermediate_images) return;  

    vtkStructuredPointsWriter *writer = vtkStructuredPointsWriter::New();
    vtkImageData* copyImage = vtkImageData::New();
    float* ptr;
    char name[255];
    int  i;
    float* buf;

    buf    = (float*) outputImage ->GetScalarPointer();
    
    vtkImageData::SetScalarType( VTK_UNSIGNED_CHAR, copyImage->GetInformation());
    vtkImageData::SetNumberOfScalarComponents(1,    copyImage->GetInformation());
    copyImage->SetDimensions( outputImage->GetDimensions());
    copyImage->SetOrigin(     outputImage->GetOrigin());
    copyImage->SetSpacing(    outputImage->GetSpacing());
    
    copyImage->AllocateScalars(copyImage->GetInformation());
    //     copyImage->CopyAndCastFrom(outputImage,
    //                outputImage->GetExtent());
    
    ptr = (float*) copyImage->GetScalarPointer();
    for(i=0;i<imsize;i++) {
      *ptr = buf[i];
      ptr++;
    }
    
    writer->SetInputData(copyImage);
    sprintf(name,"distmap%d.vtk",num);
    writer->SetFileName(name);
    writer->SetFileTypeToBinary();
    writer->Write();

    copyImage->Delete();
    writer->Delete();


    fprintf(stderr,"%s saved \n",name);

} // SaveDistance()


//----------------------------------------------------------------------------
void vtkImagePropagateDist2::SetNarrowBand( int* band, int size)
{
  narrowband = band;
  bandsize = size;
}

//----------------------------------------------------------------------
void vtkImagePropagateDist2::GetSkeleton( vtkImageData* skeleton)
{

  float* ptr;
  int  i;
  float n;
  
  
  if (skeleton->GetScalarType() != VTK_FLOAT) {
    fprintf(stderr,"vtkImagePropagateDist2::GetSkeleton() skeleton image must be VTK_FLOAT \n");
  }

  // Save skeleton
  ptr = (float*) skeleton->GetScalarPointer();
  for(i=0;i<imsize;i++) {
     n = list_elts[i].GetSkeleton();
     ptr[i] = n;
  }
  

} // GetSkeleton()


//----------------------------------------------------------------------
void vtkImagePropagateDist2::PrintSelf(ostream& os, vtkIndent indent)
{
   vtkImageAlgorithm::PrintSelf(os,indent);

} // PrintSelf()
