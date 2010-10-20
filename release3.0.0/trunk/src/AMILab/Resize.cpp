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

//#include "style.hpp"
//#include "DessinImage.hpp"
#include "inrimage.hpp"
#include "math1.hpp"

// spline interpolation
extern "C" {
#include    "coeff.h"
#include    "interpol.h"
}

extern unsigned char GB_debug;

/*
//#define MacroInterpoleCoeff2D( xr,yr, coeff)                           \
//  xi = (int)xr;           yi = (int)yr;                          \
//  dx = xr - (double)xi;   dy = yr - (double)yi;                  \
//  //--- interpolation de la 1ere derivee ---                   \
//  coeff[0][0][0] = (1.0 - dx) * (1.0 - dy);  // xi,   yi       \
//  coeff[0][1][0] = dx         * (1.0 - dy);  // xi+1, yi       \
//  coeff[1][0][0] = (1.0 - dx) * dy        ;  // xi,   yi+1     \
//  coeff[1][1][0] = dx         * dy        ;  // xi+1, yi+1      

//#define MacroInterpoleScalaire2D( coeff, im, res)                                               \
//  res  = coeff[0][0][0] * im->ValeurBuffer()  + coeff[0][1][0] * im->ValeurBuffer(1);     \
//  res += coeff[1][0][0] * im->ValeurBuffer(tx)+ coeff[1][1][0] * im->ValeurBuffer(tx+1);  
*/

//----------------------------------------------------------------------
InrImage* Func_MeanHalfSize( InrImage* in, int dimension)
//
{
    register int    dimx,dimy,dimz;
    register int    x1,y1,z1;
    register int    x,y,z=0;
    register float      val;
    InrImage* out;
    char newname[256];
    float tx,ty,tz;

  in->GetTranslation(tx,ty,tz);

  dimx = (in->DimX()/2);
  dimy = (in->DimY()/2);
  Si dimension==3 Alors
    dimz = (in->DimZ()/2);
    if (dimz==0) dimz =1;
  Sinon
    dimz = in->DimZ();
  FinSi

  std::cout << dimx << ":" << dimy << ":" << dimz << ":\n";
  sprintf(newname,"%s-div2.ami.gz",in->GetName());
  out = new InrImage( dimx, dimy, dimz, WT_FLOAT, newname);
  out->InitImage( 0.0);


  Pour( z1, 0, dimz - 1)
  Pour( y1, 0, dimy - 1)
  Pour( x1, 0, dimx - 1)

    x = 2*x1;  
    y = 2*y1;

    Si dimension == 3 Alors
      z = 2*z1;
      val = (*in)( x,y,  z)   +  (*in)(x+1,y  ,z  ) +
            (*in)( x,y+1,z)   +  (*in)(x+1,y+1,z  ) +
            (*in)( x,y,  z+1) +  (*in)(x+1,y  ,z+1) +
            (*in)( x,y+1,z+1) +  (*in)(x+1,y+1,z+1);
      val /= 8.0;
    Sinon
      z = z1;
      val = (*in)( x,y,  z)   +  (*in)(x+1,y  ,z  ) +
            (*in)( x,y+1,z)   +  (*in)(x+1,y+1,z  );
      val /= 4.0;
    FinSi

    out->BufferPos(x1,y1,z1);
    out->FixeValeur( val);

  FinPour
  FinPour
    // to do : progress system
    Si GB_debug Alors
      Si z > 0 Alors 
        printf("\b\b\b");
      Sinon
        printf("Calcul du r�ultat : ");
      FinSi
      printf("%3d",z); 
      fflush(stdout);
    FinSi

  FinPour

  Si dimension == 3 Alors
    out->SetVoxelSize(
                in->_size_x * 2,
                in->_size_y * 2,
                in->_size_z * 2
                );
    out->SetTranslation(tx+in->_size_x/2.0,
                        ty+in->_size_y/2.0,
                        tz+in->_size_z/2.0);
  Sinon
    out->SetVoxelSize(
                in->_size_x * 2,
                in->_size_y * 2,
                in->_size_z
                );
    out->SetTranslation(tx+in->_size_x/2.0,
                        ty+in->_size_y/2.0,
                        tz);
  FinSi



  return out;

} // Func_MeanHalfSize()



//----------------------------------------------------------------------
// if interpolate ==0: nearest neighbor
// 1: linear interpolation
// 2: spline interpolation (only 2D)
InrImage* Func_Resize( InrImage* in, int newsizex, int newsizey, int newsizez, 
               unsigned char interpolate, int spline_degree)
//
{
  InrImage* out;
  register float    x1, y1, z1;
  register int    x, y, z;
  int i;
//    int xi,yi,zi;
// double   xr,yr,zr;
//    double   dx,dy,dz;
//    double   coeff[2][2][2];
  double   res;
  unsigned long tx, txy;
  char newname[256];

  Si(newsizex == 0) Ou(newsizey == 0) Ou(newsizez == 0) Alors
  fprintf(stderr, " Resize() \t Error, one of the dimensions is zero !\n");
  return NULL;
  FinSi

  float tr_x, tr_y, tr_z;

  in->GetTranslation(tr_x, tr_y, tr_z);


  sprintf(newname, "%s-resized.ami.gz", in->GetName());
  out = new InrImage(newsizex, newsizey, newsizez, in->GetVDim(), in->_format, (char*) newname);

//  Si dimension == UNKNOWN Alors
//    Si in->DimZ() > 1 Alors
//      dimension = MODE_3D;
//    Sinon
//      dimension = MODE_2D;
//    FinSi
//  FinSi

  // check if 2D spline interpolation
  InrImage* im_splinecoeff = NULL;
  float*    splinecoeff_buf = NULL;

  InrImage* im_splinecoeff_r = NULL;
  float*    splinecoeff_buf_r = NULL;
  InrImage* im_splinecoeff_g = NULL;
  float*    splinecoeff_buf_g = NULL;
  InrImage* im_splinecoeff_b = NULL;
  float*    splinecoeff_buf_b = NULL;

  if ((interpolate == 2) && (in->DimZ() == 1)) {
    if (in->ScalarFormat()) {
      im_splinecoeff = new InrImage(WT_FLOAT, "splinecoeff.ami.gz", in);
      (*im_splinecoeff) = (*in);
      splinecoeff_buf = (float*)im_splinecoeff->GetData();
      SamplesToCoefficients(splinecoeff_buf, in->DimX(), in->DimY(), spline_degree);
    } else {
      // process Red component
      im_splinecoeff_r = new InrImage(WT_FLOAT, "splinecoeff_r.ami.gz", in);
      in->InitBuffer();
      im_splinecoeff_r->InitBuffer();

      do {
        im_splinecoeff_r->FixeValeur(in->VectValeurBuffer(0));
        im_splinecoeff_r->IncBuffer();
      } while (in->IncBuffer());

      splinecoeff_buf_r = (float*)im_splinecoeff_r->GetData();

      SamplesToCoefficients(splinecoeff_buf_r, in->DimX(), in->DimY(), spline_degree);

      // process Green component
      im_splinecoeff_g = new InrImage(WT_FLOAT, "splinecoeff_g.ami.gz", in);

      in->InitBuffer();

      im_splinecoeff_g->InitBuffer();

      do {
        im_splinecoeff_g->FixeValeur(in->VectValeurBuffer(1));
        im_splinecoeff_g->IncBuffer();
      } while (in->IncBuffer());

      splinecoeff_buf_g = (float*)im_splinecoeff_g->GetData();

      SamplesToCoefficients(splinecoeff_buf_g, in->DimX(), in->DimY(), spline_degree);

      // process Blue component
      im_splinecoeff_b = new InrImage(WT_FLOAT, "splinecoeff_b.ami.gz", in);

      in->InitBuffer();

      im_splinecoeff_b->InitBuffer();

      do {
        im_splinecoeff_b->FixeValeur(in->VectValeurBuffer(2));
        im_splinecoeff_b->IncBuffer();
      } while (in->IncBuffer());

      splinecoeff_buf_b = (float*)im_splinecoeff_b->GetData();

      SamplesToCoefficients(splinecoeff_buf_b, in->DimX(), in->DimY(), spline_degree);
    }
  }

  tx = in->DimX();

  txy = tx * in->DimY();

  in->InitBuffer();
  out->InitBuffer();

  for (z = 0; z <= out->DimZ() - 1;z++) {
    for (y = 0; y <= out->DimY() - 1; y++) {
      for (x = 0; x <= out->DimX() - 1; x++) {

        // TODO: check consistency of coordinates !! what are the continuous limits of a voxel?
        x1 =  1.0 * x / (out->DimX() - 1) * (in->DimX() - 1);
        y1 =  1.0 * y / (out->DimY() - 1) * (in->DimY() - 1);

        if (out->DimZ() > 1) {
          z1 =  1.0 * z / (out->DimZ() - 1) * (in->DimZ() - 1);
        } else {
          z1 = 0;
        }

        if (interpolate == 1) {
          // linear interpolation
          if (in->ScalarFormat()) {
            res = in->InterpLinIntensite(x1, y1, z1);
            out->FixeValeur(res);
          } else {
            for (i = 0;i < in->GetVDim();i++) {
              out->VectFixeValeur(i, in->InterpLinIntensite(x1, y1, z1, i));
            }
          }
        } else
          if ((interpolate == 2) && (in->DimZ() == 1)) {
            // spline interpolation
            if (in->ScalarFormat()) {
              res = (float)InterpolatedValue(splinecoeff_buf, in->DimX(), in->DimY(),
                                             x1, y1, spline_degree);
              out->FixeValeur(res);
            } else {
              // to do spline interpolation for vectors
              float red   = (float)InterpolatedValue(splinecoeff_buf_r, in->DimX(), in->DimY(),
                                                     x1, y1, spline_degree);
              float green = (float)InterpolatedValue(splinecoeff_buf_g, in->DimX(), in->DimY(),
                                                     x1, y1, spline_degree);
              float blue  = (float)InterpolatedValue(splinecoeff_buf_b, in->DimX(), in->DimY(),
                                                     x1, y1, spline_degree);
              out->VectFixeValeurs(red, green, blue);
            }
          }
          else {
            in->BufferPos((int) x1, (int) y1, (int) z1);

            if (in->ScalarFormat()) {
              out->FixeValeur(in->ValeurBuffer());
            } else {
              for (i = 0;i < in->GetVDim();i++)
                out->VectFixeValeur(i, in->VectValeurBuffer(i));
            }
          }

        out->IncBuffer();

      }
    }

    // to do : progress system
    if (GB_debug) {
      if (z > 0) {
        printf("\b\b\b");
      } else {
        printf("Calcul du r�ultat : ");
      }

      printf("%3d", z);

      fflush(stdout);
    }
  }

  out->SetVoxelSize(

    (in->_size_x * in->DimX()) / (1.0*out->DimX()),
    (in->_size_y * in->DimY()) / (1.0*out->DimY()),
    (in->_size_z * in->DimZ()) / (1.0*out->DimZ())
  );

  //  out->Sauve();

  out->SetTranslation(tr_x, tr_y, tr_z);

  if ((interpolate == 2) && (in->DimZ() == 1))
  {
    if (in->ScalarFormat()) {
      delete im_splinecoeff;
    } else {
      delete im_splinecoeff_r;
      delete im_splinecoeff_g;
      delete im_splinecoeff_b;
    }
  }

  return out;

} // Func_Resize()

