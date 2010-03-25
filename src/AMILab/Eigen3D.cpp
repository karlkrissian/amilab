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
/***************************************************************************
 * $Author: karl $
 * $Revision: 1.4 $
 * $Log: Eigen3D.c,v $
 * Revision 1.4  2006/02/21 18:26:17  karl
 * many changes
 *
 * Revision 1.3  2005/11/16 14:03:07  karl
 * added LGPL license
 *
 * Revision 1.2  2005/08/08 17:24:54  karl
 * SRAD implementation + warnings fix
 *
 * Revision 1.1.1.1  2004/02/02 20:47:07  karl
 * source code in C++
 *
 * Revision 1.1.1.1  2003/08/14 07:16:14  karl
 * Source code
 *
 * Revision 1.5  2001/03/16 23:55:22  karl
 * *** empty log message ***
 ***************************************************************************/



#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#include "fonctions.h"
#include "VarContexts.hpp"
#include "math1.hpp"
#include "inrimage.hpp"
#include "FloatMatrix.hpp"
#include "Eigen.hpp"

extern    VarContexts  Vars;
extern    unsigned char GB_debug;

//extern unsigned char verbose;



//---------------------------------------------------------
//
unsigned char      Func_Eigen2D( char* varname,
			   InrImage* Mxx, InrImage* Mxy,
			   InrImage* Myy, 
			   InrImage* mask)
{

  

    FloatMatrix     H_2D(2,2);
    FloatMatrix     VP_2D(2,2);
    float           vap[2];
    int             num_rot;
    unsigned char         VapHessien = false;

    int          x,y,z;
    InrImage::ptr       image_vep1;
    InrImage::ptr       image_vep2;
    InrImage::ptr       image_vap1;
    InrImage::ptr       image_vap2;
    std::string         resname;

//  verbose = true;

  image_vep1 = InrImage::ptr( new InrImage( WT_FLOAT,3,  "E-vep1.inr.gz", Mxx));
  image_vep2 = InrImage::ptr( new InrImage( WT_FLOAT,3,  "E-vep2.inr.gz", Mxx));
  image_vep1->InitImage( 0.0, 0.0, 0.0);
  image_vep2->InitImage( 0.0, 0.0, 0.0);

  image_vap1 = InrImage::ptr( new InrImage( WT_FLOAT,  "E-vap1.inr.gz", Mxx));
  image_vap2 = InrImage::ptr( new InrImage( WT_FLOAT,  "E-vap2.inr.gz", Mxx));
  image_vap1->InitImage( 0.0);
  image_vap2->InitImage( 0.0);

  // Initialisation des images 
  Mxx->InitBuffer();
  Mxy->InitBuffer();
  Myy->InitBuffer();

  image_vep1->InitBuffer();  
  image_vep2->InitBuffer();  

  image_vap1->InitBuffer();  
  image_vap2->InitBuffer();  

  z = 0;
  Pour( y, 0, Mxx->_ty - 1)
  Pour( x, 0, Mxx->_tx - 1)

    Si (mask==NULL) Ou (*mask)(x,y,z)>127 Alors

      H_2D[0][0] = Mxx->ValeurBuffer();
      H_2D[1][0] = 
      H_2D[0][1] = Mxy->ValeurBuffer();
      H_2D[1][1] = Myy->ValeurBuffer();

      VapHessien = jacobi( H_2D, 2, vap, VP_2D, &num_rot );

      Si VapHessien Alors
        eigsrt(vap, VP_2D, 2);
        image_vep1->VectFixeValeurs( VP_2D[0][0],  VP_2D[1][0],  0);
        image_vep2->VectFixeValeurs( VP_2D[0][1],  VP_2D[1][1],  0);
        image_vap1->FixeValeur( vap[0]);
        image_vap2->FixeValeur( vap[1]);
      FinSi
    FinSi

    Mxx->IncBuffer();
    Mxy->IncBuffer();
    Myy->IncBuffer();

    image_vep1->IncBuffer();  
    image_vep2->IncBuffer();  

    image_vap1->IncBuffer();  
    image_vap2->IncBuffer();  

  FinPour
  FinPour

  BasicVariable::ptr var;

  resname = (boost::format("%s_Evep1") % varname).str();
  Vars.AddVar<InrImage>(resname,image_vep1);

  resname = (boost::format("%s_Evep2") % varname).str();
  Vars.AddVar<InrImage>(resname,image_vep2);

  resname = (boost::format("%s_Evap1") % varname).str();
  Vars.AddVar<InrImage>(resname,image_vap1);

  resname = (boost::format("%s_Evap2") % varname).str();
  Vars.AddVar<InrImage>(resname,image_vap2);

  return true;

} // end Func_Eigen2D()

//---------------------------------------------------------
// Func_HessianMatrix
//---------------------------------------------------------

unsigned char      Func_Eigen3D( char* varname,
			   InrImage* Mxx, InrImage* Mxy, InrImage* Mxz,
			   InrImage* Myy, InrImage* Myz, InrImage* Mzz,
			   InrImage* mask)
{

  

    FloatMatrix     H_3D(3,3);
    FloatMatrix     VP_3D(3,3);
    float           vap[3];
    int             num_rot;
    unsigned char         VapHessien = false;

    int          x,y,z;
    InrImage::ptr       image_vep1;
    InrImage::ptr       image_vep2;
    InrImage::ptr       image_vep3;
    InrImage::ptr       image_vap1;
    InrImage::ptr       image_vap2;
    InrImage::ptr       image_vap3;
    std::string         resname;

//  verbose = true;

  Si Mxx->_tz == 1 AlorsFait return false;

  image_vep1 =  InrImage::ptr(new InrImage( WT_FLOAT, 3, "E-vep1.inr.gz", Mxx));
  image_vep2 =  InrImage::ptr(new InrImage( WT_FLOAT, 3, "E-vep2.inr.gz", Mxx));
  image_vep3 =  InrImage::ptr(new InrImage( WT_FLOAT, 3, "E-vep3.inr.gz", Mxx));
  image_vep1->InitImage( 0.0, 0.0, 0.0);
  image_vep2->InitImage( 0.0, 0.0, 0.0);
  image_vep3->InitImage( 0.0, 0.0, 0.0);

  image_vap1 =  InrImage::ptr(new InrImage( WT_FLOAT,  "E-vap1.inr.gz", Mxx));
  image_vap2 =  InrImage::ptr(new InrImage( WT_FLOAT,  "E-vap2.inr.gz", Mxx));
  image_vap3 =  InrImage::ptr(new InrImage( WT_FLOAT,  "E-vap3.inr.gz", Mxx));
  image_vap1->InitImage( 0.0);
  image_vap2->InitImage( 0.0);
  image_vap3->InitImage( 0.0);

  // Initialisation des images 

  Mxx->InitBuffer();
  Mxy->InitBuffer();
  Mxz->InitBuffer();
  Myy->InitBuffer();
  Myz->InitBuffer();
  Mzz->InitBuffer();

  image_vep1->InitBuffer();  
  image_vep2->InitBuffer();  
  image_vep3->InitBuffer();  

  image_vap1->InitBuffer();  
  image_vap2->InitBuffer();  
  image_vap3->InitBuffer();  


  Pour( z, 0, Mxx->_tz - 1)
  Pour( y, 0, Mxx->_ty - 1)
  Pour( x, 0, Mxx->_tx - 1)

    Si (mask==NULL) Ou (*mask)(x,y,z)>127 Alors

      H_3D[0][0] = Mxx->ValeurBuffer();
      H_3D[1][0] = 
      H_3D[0][1] = Mxy->ValeurBuffer();
      H_3D[0][2] = 
      H_3D[2][0] = Mxz->ValeurBuffer();
      H_3D[1][1] = Myy->ValeurBuffer();
      H_3D[1][2] = 
      H_3D[2][1] = Myz->ValeurBuffer();
      H_3D[2][2] = Mzz->ValeurBuffer();

      VapHessien = jacobi( H_3D, 3, vap, VP_3D, &num_rot );

      Si VapHessien Alors
        eigsrt(vap, VP_3D, 3);
        image_vep1->VectFixeValeurs( VP_3D[0][0],  VP_3D[1][0],  VP_3D[2][0]);
        image_vep2->VectFixeValeurs( VP_3D[0][1],  VP_3D[1][1],  VP_3D[2][1]);
        image_vep3->VectFixeValeurs( VP_3D[0][2],  VP_3D[1][2],  VP_3D[2][2]);
        image_vap1->FixeValeur( vap[0]);
        image_vap2->FixeValeur( vap[1]);
        image_vap3->FixeValeur( vap[2]);
      FinSi
    FinSi

    Mxx->IncBuffer();
    Mxy->IncBuffer();
    Mxz->IncBuffer();
    Myy->IncBuffer();
    Myz->IncBuffer();
    Mzz->IncBuffer();

    image_vep1->IncBuffer();  
    image_vep2->IncBuffer();  
    image_vep3->IncBuffer();  

    image_vap1->IncBuffer();  
    image_vap2->IncBuffer();  
    image_vap3->IncBuffer();  

  FinPour
  FinPour
  FinPour

  BasicVariable::ptr var;

  resname = (boost::format("%s_Evep1") % varname).str();
  Vars.AddVar<InrImage>(resname,image_vep1);

  resname = (boost::format("%s_Evep2") % varname).str();
  Vars.AddVar<InrImage>(resname,image_vep2);

  resname = (boost::format("%s_Evep3") % varname).str();
  Vars.AddVar<InrImage>(resname,image_vep3);

  resname = (boost::format("%s_Evap1") % varname).str();
  Vars.AddVar<InrImage>(resname,image_vap1);

  resname = (boost::format("%s_Evap2") % varname).str();
  Vars.AddVar<InrImage>(resname,image_vap2);

  resname = (boost::format("%s_Evap3") % varname).str();
  Vars.AddVar<InrImage>(resname,image_vap3);

  return true;

} // end Func_Eigen3D()

