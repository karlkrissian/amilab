//
// C++ Implementation: ImageDraw
//
// Description: 
//
//
// Author: Karl Krissian,,, <karl@UBUNTU-KARL>, (C) 2007
//
// Copyright: See COPYING file that comes with this distribution
//
//


template <class T> 
ImageDraw<T>::ImageDraw() 
{
  this->RGB_image = NULL;
  for(int i=0;i<3;i++)  this->voxel_size[i] = 1.0;
}

template <class T> 
ImageDraw<T>::~ImageDraw() 
{
  if (this->RGB_image!=NULL)
    delete [] this->RGB_image;
}


//----------------------------------------------------------------
template <class T>
void ImageDraw<T>::AllocateImage( int width, int height)
//              -------------
{
  if (this->RGB_image!=NULL)
    delete [] this->RGB_image;

  printf("Allocating %d %d \n",width,height);

  this->RGB_width  = width;
  this->RGB_height = height; 
  this->RGB_image = new unsigned char[width*height*3];
}

//----------------------------------------------------------------
template <class T>
void ImageDraw<T>::DrawRectangle( int x1, int y1, int x2, int y2, 
//                 -------------
unsigned char color)
{
  int x,y;
  unsigned char* buf1;
  unsigned char* buf2;

//  printf("Draw Rectangle %2d %2d %2d %2d %3d \n",x1,y1,x2,y2,color);

  buf1 = RGB_image+3*(x1+y1*RGB_width);

  for(y=y1;y<y2;y++) {
    buf2=buf1;
    for(x=x1;x<x2;x++)  {
      *buf2++ = color;
      *buf2++ = color;
      *buf2++ = color;
    }
    buf1 += RGB_width*3;
  }

}

//----------------------------------------------------------------
template <class T>
void ImageDraw<T>::Apply(int width_dir, int height_dir, int width, int height )
//              -----
{
	register int         x,y;
	register float       px,py;
	register float       px1,py1;
        T* im_buf0 = NULL;
        T* im_buf = NULL;

	int wo,ho; // width and height orientation
	int pw,ph; // image pixel width and height
        float size_x,size_y;
        int step_x =0,step_y =0;
        float unit_size_x,unit_size_y,unit_size;

  // compute the directions
  wo = abs(width_dir);
  ho = abs(height_dir);

  // compute voxel size in each direction
  pw = abs(ROI[wo-1][1]-ROI[wo-1][0]+1);
  ph = abs(ROI[ho-1][1]-ROI[ho-1][0]+1);

  // compute the spatial unit size
  unit_size_x = width/(pw*this->voxel_size[wo-1]);
  unit_size_y = height/(ph*this->voxel_size[ho-1]);

#define macro_min(a,b) ((a)<(b)?(a):(b))
  unit_size = macro_min(unit_size_x,unit_size_y);
  printf("unit size %2.2f \n",unit_size);

  size_x = this->voxel_size[wo-1]*unit_size;
  size_y = this->voxel_size[ho-1]*unit_size;
  printf("size  x and y %2.2f %2.2f\n",size_x,size_y);

  //--- On rajoute 1E-4 pour etre sur d'arrondir a la valeur superieure et d'eviter
  //--- un plantage: A VERIFIER SI C'EST NECESSAIRE ...
  AllocateImage( (int) (pw*size_x+1E-4), 
	         (int) (ph*size_y+1E-4));

  // initialize step_x and step_y
  switch (wo) {
    case 1: step_x=1; break;
    case 2: step_x=dim[0]; break;
    case 3: step_x=dim[0]*dim[1]; break;
  }
  switch (ho) {
    case 1: step_y=1; break;
    case 2: step_y=dim[0]; break;
    case 3: step_y=dim[0]*dim[1]; break;
  }

  // empezar en la position del cursor de la tercera coordenada
  if ((wo!=1)&&(ho!=1)) im_buf0 = im + this->cursor_pos[0];
  else
  if ((wo!=2)&&(ho!=2)) im_buf0 = im + this->cursor_pos[1]*dim[0];
  else
  if ((wo!=3)&&(ho!=3)) im_buf0 = im + this->cursor_pos[2]*dim[0]*dim[1];

  printf("ROI %d %d %d %d %d %d \n",
	this->ROI[0][0],this->ROI[0][1],
	this->ROI[1][0],this->ROI[1][1],
	this->ROI[2][0],this->ROI[2][1]);

  px = 0;
  for( x=this->ROI[wo-1][0]; x<=this->ROI[wo-1][1]; x++) {
    px1 = px+size_x;
    im_buf = im_buf0 + x*step_x + this->ROI[ho-1][0]*step_y;
    py = 0;

    for( y=this->ROI[ho-1][0]; y<=this->ROI[ho-1][1]; y++) {

      py1 = py+size_y;
/*      Si _image->_format != WT_RGB Alors
        couleur = _tab_intensite_couleur[ IntensiteBuffer() ];
      Sinon
        couleur = _palette->RGB( 
				(unsigned short) _image->VectValeurBuffer(0),
				(unsigned short) _image->VectValeurBuffer(1),
				(unsigned short) _image->VectValeurBuffer(2)
                               );
      FinSi
*/
      this->DrawRectangle( (int) px,            (int) py, 
                          (int) (px1+1E-4),
			  (int) (py1+1E-4), 
			  (unsigned char) *im_buf);
      im_buf += step_y;
      py = py1;

    } // y

    px = px1;
  } // x

} // Apply()

