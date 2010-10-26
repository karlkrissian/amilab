
// This class will slice a 2D/3D image 

// option 1: give it an InrImage*
// option 2: make it template and give it a pointer to the image data

// drawing:
// could use OpenGL
// have a class for intensity mapping

template <class PixelType>
class ImageDraw {

private:

  // image dimensions
  int dim[3];
  // Rectangular region of interest
  int ROI[3][2];
  // pointer to all the data
  PixelType* im;
  // slice orientation
  int orientation; // 0:XY, 1:XZ, 2:YZ
  int cursor_pos[3];
  float voxel_size[3];

private:

  void AllocateImage(int,int);

public:

  unsigned char* RGB_image;
  int RGB_width;
  int RGB_height;

  unsigned char* GetRGBImage() { return RGB_image; }
  int GetRGBwidth()  { return RGB_width;  }
  int GetRGBheight() { return RGB_height; }

  ImageDraw();

  // delete allocated image
  ~ImageDraw();

  void Apply(int width_dir, int height_dir, int width, int height );

  void SetInput(PixelType* data, int dimx, int dimy, int dimz) {
    this->im = data;
    this->dim[0] = dimx;
    this->dim[1] = dimy;
    this->dim[2] = dimz;
    this->SetROI(0,dimx-1,0,dimy-1,0,dimz-1);
  }

  void SetVoxelSize(float vx, float vy , float vz) { 
     this->voxel_size[0]=vx;
     this->voxel_size[1]=vy;
     this->voxel_size[2]=vz;
  }

  void SetCursorPosition(int px, int py, int pz)
  {
    this->cursor_pos[0] = px;
    this->cursor_pos[1] = py;
    this->cursor_pos[2] = pz;
  }

  void SetROI(int xmin, int xmax, int ymin, int ymax, int zmin, int zmax) {
    this->ROI[0][0] = xmin;
    this->ROI[0][1] = xmax;
    this->ROI[1][0] = ymin;
    this->ROI[1][1] = ymax;
    this->ROI[2][0] = zmin;
    this->ROI[2][1] = zmax;
  }

  void DrawRectangle( int x1, int y1, int x2, int y2, unsigned char color);

};

#include "ImageDraw.tpp"
