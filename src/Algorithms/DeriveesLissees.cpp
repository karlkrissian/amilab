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
//  
//  fichier DeriveesLissees
//
//  Karl Krissian    Las Palmas 10 07 2000
//




#include "DeriveesLissees.hpp"

//---------------------------------------------------------------------------

void CalculaHessiano (float *TD, int nx, int ny, int nz, float H[3][3])
/*  Calcula la matriz hessiana del voxel (x,y,z), y lo devuelve en H. */
{
 long nxy = (long) nx*ny;
 float ALFAH = 0.5;
 float BETAH = 0.25;
 float GAMMAH = 0.5;


 // derivada segunda de u con x
 H[0][0] = (1-ALFAH-BETAH) * (*(TD+1) + *(TD-1) - 2**(TD)) +
   ALFAH/4 *   (*(TD+nx+1) + *(TD+nx-1) - 2**(TD+nx) +
		*(TD-nx+1) + *(TD-nx-1) - 2**(TD-nx) +
		*(TD+nxy+1) + *(TD+nxy-1) - 2**(TD+nxy) +
		*(TD-nxy+1) + *(TD-nxy-1) - 2**(TD-nxy)) +
   BETAH/4 *   (*(TD+nx+nxy+1) + *(TD+nx+nxy-1) - 2**(TD+nx+nxy) +
		*(TD-nx+nxy+1) + *(TD-nx+nxy-1) - 2**(TD-nx+nxy) +
		*(TD+nx-nxy+1) + *(TD+nx-nxy-1) - 2**(TD+nx-nxy) +
		*(TD-nx-nxy+1) + *(TD-nx-nxy-1) - 2**(TD-nx-nxy));

 // derivada segunda de u con y
 H[1][1] = (1-ALFAH-BETAH) * (*(TD+nx) + *(TD-nx) - 2**(TD)) +
   ALFAH/4 *   (*(TD+1+nx) + *(TD+1-nx) - 2**(TD+1) +
		*(TD-1+nx) + *(TD-1-nx) - 2**(TD-1) +
		*(TD+nxy+nx) + *(TD+nxy-nx) - 2**(TD+nxy) +
		*(TD-nxy+nx) + *(TD-nxy-nx) - 2**(TD-nxy)) +
   BETAH/4 *   (*(TD+1+nxy+nx) + *(TD+1+nxy-nx) - 2**(TD+1+nxy) +
		*(TD-1+nxy+nx) + *(TD-1+nxy-nx) - 2**(TD-1+nxy) +
		*(TD+1-nxy+nx) + *(TD+1-nxy-nx) - 2**(TD+1-nxy) +
		*(TD-1-nxy+nx) + *(TD-1-nxy-nx) - 2**(TD-1-nxy));
 
 // derivada segunda de u con z
 H[2][2] = (1-ALFAH-BETAH) * (*(TD+nxy) + *(TD-nxy) - 2**(TD)) +
   ALFAH/4 *   (*(TD+nx+nxy) + *(TD+nx-nxy) - 2**(TD+nx) +
		*(TD-nx+nxy) + *(TD-nx-nxy) - 2**(TD-nx) +
		*(TD+1+nxy) + *(TD+1-nxy) - 2**(TD+1) +
		*(TD-1+nxy) + *(TD-1-nxy) - 2**(TD-1)) +
   BETAH/4 *   (*(TD+nx+1+nxy) + *(TD+nx+1-nxy) - 2**(TD+nx+1) +
		*(TD-nx+1+nxy) + *(TD-nx+1-nxy) - 2**(TD-nx+1) +
		*(TD+nx-1+nxy) + *(TD+nx-1-nxy) - 2**(TD+nx-1) +
		*(TD-nx-1+nxy) + *(TD-nx-1-nxy) - 2**(TD-nx-1));
 
 // derivada cruzada de u con x e y
 H[0][1] = (1-GAMMAH)/4 * (*(TD+1+nx) + *(TD-1-nx)
			   - *(TD+1-nx) - *(TD-1+nx)) +
   GAMMAH/8 *  (*(TD+nxy+1+nx) + *(TD+nxy-1-nx)
		- *(TD+nxy+1-nx) - *(TD+nxy-1+nx) +
		*(TD-nxy+1+nx) + *(TD-nxy-1-nx)
		- *(TD-nxy+1-nx) - *(TD-nxy-1+nx));
 H[1][0] = H[0][1];

 // derivada cruzada de u con x y z
 H[0][2] = (1-GAMMAH)/4 * (*(TD+1+nxy) + *(TD-1-nxy)
			   - *(TD+1-nxy) - *(TD-1+nxy)) +
   GAMMAH/8 *  (*(TD+nx+1+nxy) + *(TD+nx-1-nxy)
		- *(TD+nx+1-nxy) - *(TD+nx-1+nxy) +
		*(TD-nx+1+nxy) + *(TD-nx-1-nxy)
		- *(TD-nx+1-nxy) - *(TD-nx-1+nxy));
 H[2][0] = H[0][2];
 
 // derivada cruzada de u con y y z
 H[1][2] = (1-GAMMAH)/4 * (*(TD+nx+nxy) + *(TD-nx-nxy)
			   - *(TD+nx-nxy) - *(TD-nx+nxy)) +
   GAMMAH/8 *  (*(TD+1+nx+nxy) + *(TD+1-nx-nxy)
		- *(TD+1+nx-nxy) - *(TD+1-nx+nxy) +
		*(TD-1+nx+nxy) + *(TD-1-nx-nxy)
		- *(TD-1+nx-nxy) - *(TD-1-nx+nxy));
 H[2][1] = H[1][2];
}

//---------------------------------------------------------------------------
//
void Gradiente3D (float *TD, int nx, int ny, int nz, float G[3])
/*  Calcula la norma del vector gradiente del voxel (x,y,z) */
{
 long nxy = (long) nx*ny;
 //long pos;
 // float ALFA = 0.51902604799;
 // float BETA = 0.32627341364;

 float ALFA8    = 0.0648782559984609; // ALPHA/8
 float BETA8    = 0.0407841767041326; // BETA/8
 float UNOMENOS = 0.0773502691896257; // (1-BETA-ALPHA)/2

 register float* posp;
 register float* posm;
 register long   d0,d1,d2;

 // pos = z*nxy + y*nx + x;

 // derivada de u con x
 d0 = 1;
 d1 = nx;
 d2 = nxy;
 posp = TD+d0;
 posm = TD-d0;

 G[0] = UNOMENOS * (*(posp)       - *(posm))      +
        ALFA8 *  (*(posp+d1)    - *(posm+d1)    +
                  *(posp-d1)    - *(posm-d1)    +
                  *(posp+d2)    - *(posm+d2)    +
                  *(posp-d2)    - *(posm-d2))   +
        BETA8 *  (*(posp+d1+d2) - *(posm+d1+d2) +
                  *(posp-d1+d2) - *(posm-d1+d2) +
                  *(posp+d1-d2) - *(posm+d1-d2) +
                  *(posp-d1-d2) - *(posm-d1-d2));

 // derivada de u con y
 d0 = nx;
 d1 = 1;
 d2 = nxy;
 posp = TD+d0;
 posm = TD-d0;

 G[1] = UNOMENOS * (*(posp)       - *(posm))      +
        ALFA8 *  (*(posp+d1)    - *(posm+d1)    +
                  *(posp-d1)    - *(posm-d1)    +
                  *(posp+d2)    - *(posm+d2)    +
                  *(posp-d2)    - *(posm-d2))   +
        BETA8 *  (*(posp+d1+d2) - *(posm+d1+d2) +
                  *(posp-d1+d2) - *(posm-d1+d2) +
                  *(posp+d1-d2) - *(posm+d1-d2) +
                  *(posp-d1-d2) - *(posm-d1-d2));

 // derivada de u con z
 d0 = nxy;
 d1 = nx;
 d2 = 1;
 posp = TD+d0;
 posm = TD-d0;

 G[2] = UNOMENOS * (*(posp)       - *(posm))      +
        ALFA8 *  (*(posp+d1)    - *(posm+d1)    +
                  *(posp-d1)    - *(posm-d1)    +
                  *(posp+d2)    - *(posm+d2)    +
                  *(posp-d2)    - *(posm-d2))   +
        BETA8 *  (*(posp+d1+d2) - *(posm+d1+d2) +
                  *(posp-d1+d2) - *(posm-d1+d2) +
                  *(posp+d1-d2) - *(posm+d1-d2) +
                  *(posp-d1-d2) - *(posm-d1-d2));

}



//======================================================================
// class DeriveesLissees
//======================================================================


//----------------------------------------------------------------------
DeriveesLissees ::  DeriveesLissees( InrImage* image_entree, 
//
							   float sigma,
							   int dimension)
{

  _mask  = NULL;
  _image = image_entree;

  _dimension = dimension;

  _taille_x = image_entree->_tx;
  _taille_y = image_entree->_ty;
  _taille_z = image_entree->_tz;

  _dx  = _taille_x;
  _dxy = _taille_x*_taille_y;

  _sigma = sigma;

  Si _sigma > 0.1 Alors
    filtre = new GeneralGaussianFilter(image_entree, dimension);
    filtre->DontUseVoxelSize();
    InitImagesDeriveesLissees();
    filtre->GammaNormalise(false);
    filtre->InitFiltre( _sigma, MY_FILTRE_CONV );  
  FinSi

} // Constructor


//----------------------------------------------------------------------
DeriveesLissees :: ~DeriveesLissees()
//
{

  Si _sigma > 0.1 Alors
    LibereImagesDeriveesLissees();
  FinSi

} // Destructor



//------------------------------------------------------------------------
unsigned char  DeriveesLissees :: InitImagesDeriveesLissees()
//                                    -------------------------
{

  //--- Espace ---------------------------------

  Exx0 = new InrImage(_taille_x, _taille_y, _taille_z, WT_FLOAT, "Exx0");  
  Si Exx0 == NULL AlorsRetourne false;
  
  Si _dimension == MODE_3D Alors

    Exx1 = new InrImage(_taille_x, _taille_y, _taille_z, WT_FLOAT, "Exx1");  
    Si Exx1 == NULL AlorsRetourne false;

    E002 = new InrImage(_taille_x, _taille_y, _taille_z, WT_FLOAT, "E002");  
    Si E002 == NULL AlorsRetourne false;

  FinSi

  //--- Plan ---------------------------------

  Px00 = new InrImage(_taille_x, _taille_y, 1, WT_FLOAT, "Px00");  
  Si Px00 == NULL AlorsRetourne false;
  
  Px10 = new InrImage(_taille_x, _taille_y, 1, WT_FLOAT, "Px10");  
  Si Px10 == NULL AlorsRetourne false;

  P020 = new InrImage(_taille_x, _taille_y, 1, WT_FLOAT, "P020");  
  Si P020 == NULL AlorsRetourne false;


  Si _dimension == MODE_3D Alors

    Px01 = new InrImage(_taille_x, _taille_y, 1, WT_FLOAT, "Px01");
    Si Px01 == NULL AlorsRetourne false;

    P011 = new InrImage(_taille_x, _taille_y, 1, WT_FLOAT, "P011");  
    Si P011 == NULL AlorsRetourne false;

  FinSi

  //--- Ligne ---------------------------------

  L100 = new InrImage(_taille_x, 1, 1, WT_FLOAT, "L100");
  Si L100 == NULL AlorsRetourne false;

  L200 = new InrImage(_taille_x, 1, 1, WT_FLOAT, "L200");  
  Si L200 == NULL AlorsRetourne false;

  L010 = new InrImage(_taille_x, 1, 1, WT_FLOAT, "L010");  
  Si L010 == NULL AlorsRetourne false;

  L110 = new InrImage(_taille_x, 1, 1, WT_FLOAT, "L110");  
  Si L110 == NULL AlorsRetourne false;

  Si _dimension == MODE_3D Alors

    L001 = new InrImage(_taille_x, 1, 1, WT_FLOAT, "L001");  
    Si L001 == NULL AlorsRetourne false;

    L101 = new InrImage(_taille_x, 1, 1, WT_FLOAT, "L101");  
    Si L101 == NULL AlorsRetourne false;

  FinSi

  return true;

} // InitImagesDeriveesLissees()



//------------------------------------------------------------------------
void DeriveesLissees :: LibereImagesDeriveesLissees()
//                                ---------------------------
{

  delete Exx0;

  delete Px00;
  delete Px10;
  delete P020;

  delete L100;
  delete L200;
  delete L010;
  delete L110;


  Si _dimension == MODE_3D Alors
  
    delete Exx1;
    delete E002;

    delete Px01;
    delete P011;

    delete L001;
    delete L101;

  FinSi

} // LibereImagesDeriveesLissees()


//------------------------------------------------------
void  DeriveesLissees :: Filtre( InrImage* im, InrImage* res,
//                                     ------
               int der_x, int der_y, int der_z)
{

  unsigned char continuer;

  Si (der_x == -1) Et (der_y == -1) Et (der_z == -1) Alors
    // copie de num_image_res dans res
    im ->InitBuffer();
    res->InitBuffer();
    Repeter
      res->FixeValeur( im->ValeurBuffer());
      im->IncBuffer();
      continuer = res->IncBuffer();
    JusquA Non(continuer) FinRepeter

  Sinon

    filtre->MyFiltre( im, res, der_x, der_y, der_z);

  FinSi

} // Filtre()


//------------------------------------------------------
void  DeriveesLissees :: InitImagePlan( InrImage* in, 
//                                 -------------
						  InrImage* res, int z)
{

  res->SetImageData(_taille_x, _taille_y, 1, WT_FLOAT,
		    (void*) ( ((float*) in->Buffer()) + z*_dxy ));

} // InitImagePlan()


//------------------------------------------------------
void  DeriveesLissees :: InitImageLigne( InrImage* in, 
//                                 --------------
						   InrImage* res, int y)
{ 

  res->SetImageData(_taille_x, 1, 1, WT_FLOAT,
		    (void*) ( ((float*) in->Buffer()) + y*_dx ));

} // InitImageLigne()


//------------------------------------------------------
void  DeriveesLissees :: CalculFonction2D( InrImage* image_entree,
//                                 ----------------
						   void* fonction, void* data)
{ 

  
    int x,y,z;
    register float    *gx, *gy;
    register float    *Hxx, *Hyy, *Hxy; 
    InrImage         im_aux;
    float gradient[2];
    float hessien[2][2];

  Filtre( image_entree, Exx0, -1, -1, -1);

  //--- Calcul de la nouvelle image  ---
  Pour( z, 0, _taille_z -1)

    InitImagePlan( Exx0, &im_aux, z);
    Filtre( &im_aux, Px00, -1, 0, -1);
    Filtre( &im_aux, Px10, -1, 1, -1);
    Filtre( &im_aux, P020, -1, 2, -1);
    Filtre( P020,    P020,  0,-1, -1);
    Hyy = (float*) P020->Buffer();

    Pour( y, 0, _taille_y -1)

      InitImageLigne( Px00, &im_aux, y);
      Filtre( &im_aux, L100,  1, -1, -1);
      Filtre( &im_aux, L200,  2, -1, -1);

      gx  = (float*) L100->Buffer();
      Hxx = (float*) L200->Buffer();

      InitImageLigne( Px10, &im_aux, y);
      Filtre( &im_aux, L010,  0, -1, -1);
      Filtre( &im_aux, L110,  1, -1, -1);

      gy  = (float*) L010->Buffer();
      Hxy = (float*) L110->Buffer();

      Pour( x, 0, _taille_x-1)

        gradient[0] = *gx;
        gradient[1] = *gy;

        hessien[0][0] = *Hxx;
        hessien[1][0] = hessien[1][0] = *Hxy;
        hessien[1][1] = *Hyy;

        ((void (*)(float[2], float[2][2], void*)) fonction)(gradient, 
							    hessien, 
							    data);

        Hxx++; Hyy++;
        Hxy++; 
        gx++;  gy++; 
 
      FinPour // x
    FinPour // y
  FinPour // z


} // CalculFonction2D()

 

//------------------------------------------------------
void  DeriveesLissees :: CalculFonction2D_disc(  InrImage* image_entree,
//                                 ---------------
						     void* fonction, void* data)
{ 

  
    int x,y,z;
    register float    *Iconv; 
    InrImage         im_aux;
    float gradient[2];
    float hessien[2][2];

  Filtre( image_entree, Exx0, 0, 0, -1);
  Iconv = (float*) Exx0->Buffer();

  //--- Calcul de la nouvelle image  ---
  Pour( z, 0, _taille_z -1)
    Pour( y, 0, _taille_y -1)
      Pour( x, 0, _taille_x-1)

        Si x>0 Et x<_taille_x-1 Alors
          gradient[0] = (*(Iconv+1) - *(Iconv-1))/2.0;
          hessien[0][0] = (*(Iconv+1) - 2*(*Iconv) + *(Iconv-1));

          Si y>0 Et y<_taille_y-1 Alors
            hessien[1][0] = hessien[0][1] = 
	      ((*(Iconv+1+_dx) - *(Iconv-1+_dx))
               -
	       (*(Iconv+1-_dx) - *(Iconv-1-_dx)))
	      /4.0;
          Sinon
            hessien[1][0] = hessien[0][1] = 0.0;
          FinSi

        Sinon
  	  gradient[0] = 0.0;
  	  hessien[0][0] = 0.0;
        FinSi

        Si y>0 Et y<_taille_y-1 Alors
          gradient[1] = (*(Iconv+_dx) - *(Iconv-_dx))/2.0;
          hessien[1][1] = (*(Iconv+_dx) - 2*(*Iconv) + *(Iconv-_dx));
        Sinon
  	  gradient[1] = 0.0;
  	  hessien[1][1] = 0.0;
        FinSi

        
        ((void (*)(float[2], float[2][2], void*)) fonction)(gradient, 
							    hessien, 
							    data);

        Iconv++;
 
      FinPour // x
    FinPour // y
  FinPour // z


} // CalculFonction2D_disc()

 

 

//------------------------------------------------------
void  DeriveesLissees :: CalculFonction3D_disc(  InrImage* image_entree,
//                                 ---------------
						     void* fonction, void* data)
{ 

  
    int x,y,z;
    register float    *Iconv; 
    InrImage         im_aux;
    float gradient[3];
    float hessien[3][3];

  Si _sigma>0.1 Alors
    Filtre( image_entree, Exx0, 0, 0, 0);
    Iconv = (float*) Exx0->Buffer();
  Sinon
    Si image_entree->_format != WT_FLOAT Alors
      fprintf(stderr, "DeriveesLissees::CalculFonction3D_disc() \t Non float image \n");
      return;
    Sinon
      Iconv = (float*) image_entree->Buffer();
    FinSi
  FinSi

  //--- Calcul de la nouvelle image  ---
  Pour( z, 0, _taille_z -1)

      Si z==0 Alors
        printf(" z = ");
      Sinon
        printf("\b\b\b");  
      FinSi
      printf("%3d",z); fflush(stdout);
      Si z==_taille_z-1 AlorsFait printf("\b\b\b\b\b\b\b");

    Pour( y, 0, _taille_y -1)
      Pour( x, 0, _taille_x-1)

        Si x>0 Et x<_taille_x-1 Alors
          gradient[0] = (*(Iconv+1) - *(Iconv-1))/2.0;
          hessien[0][0] = (*(Iconv+1) - 2*(*Iconv) + *(Iconv-1));

          Si y>0 Et y<_taille_y-1 Alors
            hessien[1][0] = hessien[0][1] = 
	      ((*(Iconv+1+_dx) - *(Iconv-1+_dx))
               -
	       (*(Iconv+1-_dx) - *(Iconv-1-_dx)))
	      /4.0;
          Sinon
            hessien[1][0] = hessien[0][1] = 0.0;
          FinSi

          Si z>0 Et z<_taille_z-1 Alors
            hessien[2][0] = hessien[0][2] = 
	      ((*(Iconv+1+_dxy) - *(Iconv-1+_dxy))
               -
	       (*(Iconv+1-_dxy) - *(Iconv-1-_dxy)))
	      /4.0;
          Sinon
            hessien[2][0] = hessien[0][2] = 0.0;
          FinSi

        Sinon
  	  gradient[0] = 0.0;
  	  hessien[0][0] = 0.0;
        FinSi

        Si y>0 Et y<_taille_y-1 Alors
          gradient[1] = (*(Iconv+_dx) - *(Iconv-_dx))/2.0;
          hessien[1][1] = (*(Iconv+_dx) - 2*(*Iconv) + *(Iconv-_dx));

          Si z>0 Et z<_taille_z-1 Alors
            hessien[2][1] = hessien[1][2] = 
	      ((*(Iconv+_dx+_dxy) - *(Iconv-_dx+_dxy))
               -
	       (*(Iconv+_dx-_dxy) - *(Iconv-_dx-_dxy)))
	      /4.0;
          Sinon
            hessien[2][1] = hessien[1][2] = 0.0;
          FinSi

        Sinon
  	  gradient[1] = 0.0;
  	  hessien[1][1] = 0.0;
        FinSi

        Si z>0 Et z<_taille_z-1 Alors
          gradient[2] = (*(Iconv+_dxy) - *(Iconv-_dxy))/2.0;
          hessien[2][2] = (*(Iconv+_dxy) - 2*(*Iconv) + *(Iconv-_dxy));
        Sinon
  	  gradient[2] = 0.0;
  	  hessien[2][2] = 0.0;
        FinSi

        
        ((void (*)(float[3], float[3][3], void*)) fonction)(gradient, 
							    hessien, 
							    data);

        Iconv++;
 
      FinPour // x
    FinPour // y
  FinPour // z

} // CalculFonction3D_disc()


//------------------------------------------------------
void  DeriveesLissees :: CalculFonction3D_luis(  InrImage* image_entree,
//                                 ---------------
						     void* fonction, void* data)
{ 

  
    int x,y,z;
    register float    *Iconv; 
    InrImage         im_aux;
    float gradient[3];
    float hessien[3][3];

  Si _sigma>0.1 Alors
    Filtre( image_entree, Exx0, 0, 0, 0);
    Iconv = (float*) Exx0->Buffer();
  Sinon
    Si image_entree->_format != WT_FLOAT Alors
      fprintf(stderr, "DeriveesLissees::CalculFonction3D_disc() \t Non float image \n");
      return;
    Sinon
      Iconv = (float*) image_entree->Buffer();
    FinSi
  FinSi

  //--- Calcul de la nouvelle image  ---
  Pour( z, 0, _taille_z -1)

      Si z==0 Alors
        printf(" z = ");
      Sinon
        printf("\b\b\b");  
      FinSi
      printf("%3d",z); fflush(stdout);
      Si z==_taille_z-1 AlorsFait printf("\b\b\b\b\b\b\b");

    Pour( y, 0, _taille_y -1)
      Pour( x, 0, _taille_x-1)

        Si x>0 Et x<_taille_x-1 Et
           y>0 Et y<_taille_y-1 Et
           z>0 Et z<_taille_z-1 
        Alors
          Gradiente3D ( Iconv, 
		        _taille_x, 
		        _taille_y, 
		        _taille_z, 
		        gradient);
          CalculaHessiano ( Iconv, 
			    _taille_x, 
			    _taille_y, 
			    _taille_z, 
			    hessien);
        Sinon
          gradient[0] =
          gradient[1] =
  	  gradient[2] = 0;

          hessien[0][0] =
          hessien[0][1] =
          hessien[0][2] =
          hessien[1][0] =
          hessien[1][1] =
          hessien[1][2] =
          hessien[2][0] =
          hessien[2][1] =
          hessien[2][2] = 0;
        FinSi

        
        ((void (*)(float[3], float[3][3], void*)) fonction)(gradient, 
							    hessien, 
							    data);

        Iconv++;
 
      FinPour // x
    FinPour // y
  FinPour // z

} // CalculFonction3D_luis()

 
