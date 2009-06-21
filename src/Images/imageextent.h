//
// C++ Interface: imageextent
//
// Description: 
//
//
// Author:  Karl Krissian <>, (C) 2009
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _imageextent_h_
#define _imageextent_h_

//
// image extent can work in float or in integer limits
//
template <class T>
class ImageExtent {

  protected:

    T extent[3][2]; // limits for each of the 3 dimensions
    unsigned char mode; // 0: absolute, 1: relative

 public:
  ImageExtent() {
    for(int i=0; i<3; i++)
      for(int j=0; j<2; j++) extent[i][j]=0;
    mode = 0;
  }

  ImageExtent(int x1,int x2, int y1=0, int y2=0, int z1=0, int z2=0) {
    extent[0][0]=x1;
    extent[0][1]=x2;
    extent[1][0]=y1;
    extent[1][1]=y2;
    extent[2][0]=z1;
    extent[2][1]=z2;
    mode = 0;
  }

  ImageExtent(float x1,float x2, float y1=0, float y2=0, float z1=0, float z2=0) {
    extent[0][0]=x1;
    extent[0][1]=x2;
    extent[1][0]=y1;
    extent[1][1]=y2;
    extent[2][0]=z1;
    extent[2][1]=z2;
    mode = 0;
  }

  ImageExtent(InrImage* im)
  {
    extent[0][0] = 0;
    extent[1][0] = 0;
    extent[2][0] = 0;
    extent[0][1] = im->DimX()-1;
    extent[1][1] = im->DimY()-1;
    extent[2][1] = im->DimZ()-1;
    mode = 0;
  }

  const T& Xmin() const { return extent[0][0];}
  const T& Xmax() const { return extent[0][1];}
  const T& Ymin() const { return extent[1][0];}
  const T& Ymax() const { return extent[1][1];}
  const T& Zmin() const { return extent[2][0];}
  const T& Zmax() const { return extent[2][1];}

  void SetXmin(const T& val) {extent[0][0]=val;}
  void SetXmax(const T& val) {extent[0][1]=val;}
  void SetYmin(const T& val) {extent[1][0]=val;}
  void SetYmax(const T& val) {extent[1][1]=val;}
  void SetZmin(const T& val) {extent[2][0]=val;}
  void SetZmax(const T& val) {extent[2][1]=val;}

  unsigned char GetMode() {return mode;}
  void SetMode(unsigned char val) {mode = val;}

  void SetRelative( InrImage* im) {
    if (this->GetMode()==0) {
      
      extent[0][0] =  (int) (im->SpaceToVoxelX(extent[0][0])+0.5);
      extent[0][1] =  (int) (im->SpaceToVoxelX(extent[0][1])+0.5);
      if (extent[0][0]<0) extent[0][0]=0;
      if (extent[0][1]>im->DimX()-1) extent[0][1]=im->DimX()-1;

      extent[1][0] =  (int) (im->SpaceToVoxelY(extent[1][0])+0.5);
      extent[1][1] =  (int) (im->SpaceToVoxelY(extent[1][1])+0.5);
      if (extent[1][0]<0) extent[1][0]=0;
      if (extent[1][1]>im->DimY()-1) extent[1][1]=im->DimY()-1;

      extent[2][0] =  (int) (im->SpaceToVoxelZ(extent[2][0])+0.5);
      extent[2][1] =  (int) (im->SpaceToVoxelZ(extent[2][1])+0.5);
      if (extent[2][0]<0) extent[2][0]=0;
      if (extent[2][1]>im->DimZ()-1) extent[2][1]=im->DimZ()-1;

      for(int i=0; i<3; i++) 
        if (extent[i][1]<extent[i][0]) extent[i][1]=extent[i][0];

 /*
     if (GB_debug)
        printf("SetRelative (%02.2f->%02.2f, %02.2f->%02.2f, %02.2f->%02.2f) \n",
            (float)extent[0][0],(float)extent[0][1],
            (float)extent[1][0],(float)extent[1][1],
            (float)extent[2][0],(float)extent[2][1]);
*/
     mode = 1; // relative mode
    }
  }

  void print() const {
    printf("extent [%3.3f:%3.3f] [%3.3f:%3.3f] [%3.3f:%3.3f] \n",
            (float)extent[0][0],(float)extent[0][1],
            (float)extent[1][0],(float)extent[1][1],
            (float)extent[2][0],(float)extent[2][1]);
  }

  bool check_axis(const int& i) const { return ((i>=0)&&(i<=2)); }

  void SetMin(const int& i, const T& min) 
  { 
    if (check_axis(i)) extent[i][0] = min;
  }

  void SetMax(const int& i, const T& max)
  { 
    if (check_axis(i)) extent[i][1] = max;
  }

  void SetMinMax(const int& i, const T& min, const T& max)
  { 
    if (check_axis(i)) {
      extent[i][0] = min; 
      extent[i][1] = max; 
    }
  }

  int GetMin(const int& i) const
  {
    if (check_axis(i)) 
      return extent[i][0]; 
    else 
      return -1;
  }

  int GetMax(const int& i) const
  {
    if (check_axis(i)) 
      return extent[i][1]; 
    else 
      return -1;
  }

  int GetSize(const int& i) const
  {
    if (check_axis(i)) 
      return extent[i][1]-extent[i][0]+1; 
    else 
      return -1;
  }

  int GetNbVoxels() const
  {
    int size = (extent[0][1]-extent[0][0]+1);
    size *= (extent[1][1]-extent[1][0]+1);
    size *= (extent[2][1]-extent[2][0]+1);
    return size;
  }

  #ifndef macro_min
    #define macro_min(n1,n2) ((n1)<(n2)?(n1):(n2))
  #endif
  
  #ifndef macro_max
    #define macro_max(n1,n2) ((n1)>(n2)?(n1):(n2))
  #endif 

  void Intersect( const ImageExtent<T>& e)
  {
    for(int i=0; i<3; i++)
       SetMin(i, macro_max(GetMin(i), e.GetMin(i)));

    for(int i=0; i<3; i++)
       SetMax(i, macro_min(GetMax(i), e.GetMax(i)));
  }

  void SetRelative( const ImageExtent<T>& e)
  {
    // substract e.GetMin(.) for each coordinate
    for(int i=0; i<3; i++) {
       SetMin(i, GetMin(i) - e.GetMin(i));
       SetMax(i, GetMax(i) - e.GetMin(i));
    }
  }

  /// adds a size to each border within the given extent
  void AddMargin( const int& size, const ImageExtent<T>& e)
  {
    // substract e.GetMin(.) for each coordinate
    for(int i=0; i<3; i++) {
       SetMin(i, macro_max(GetMin(i) - size, e.GetMin(i)));
       SetMax(i, macro_min(GetMax(i) + size, e.GetMax(i)));
    }
  }

};

#endif // _imageextent_h_
