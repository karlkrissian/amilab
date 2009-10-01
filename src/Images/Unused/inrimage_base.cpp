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
 * $Revision: 1.2 $
 * $Log: inrimage_base.cpp,v $
 * Revision 1.2  2005/11/16 14:03:09  karl
 * added LGPL license
 *
 * Revision 1.1.1.1  2004/02/02 20:47:08  karl
 * source code in C++
 *
 * Revision 1.1.1.1  2000/04/07 16:12:08  karl
 * Sources code
 *
 * Revision 1.2  1998/10/02 20:05:46  kkrissia
 * InrImage Template
 *
 ***************************************************************************/

//  Fichier inrimage2_base.cpp
// 
// Creation d'une classe InrImage permettant de
// manipuler les images dans le format inrimage
//
// Version sans la librairie epidaure
//
// Karl KRISSIAN	Sophia Antipolis, le 08-12-96
//

#include "style.hpp"

#include "inrimage_base.hpp"

using namespace std;

//==========================================================================
// MEMBRES PROTEGES
//==========================================================================

//--------------------------------------------------------------------------
unsigned char InrImageBase::LitEntete( )
//                    ---------
{

  INRIMAGE_HEADER* ptr;
  inrimage*        ptr_image;

  printf("lecture de l'ent�te de %s \n", (char*) _nom);

  Si (_nom == "<") Alors
    // entree standard
    printf("InrImage::LitEntete()\t on ne lit pas que ");
    printf("l'entete sur l'entree standard\n");
    ptr_image = readZInrimage( NULL);
    _inrimage_allouee = true;
  Sinon
    ptr = readZInrimageHeader( (char*) _nom);
    ptr_image = ptr->inr;
    _inrimage_allouee = false;
  FinSi

  Si ptr_image == NULL Alors
    E_SETERR(E_ERRR, "reading in file", (char*) _nom);
    return false;
  FinSi

  _inrimage = ptr_image;
  init_from_inrimage( _inrimage);

  return true;

} // LitEntete()


//-----------------------------------------------------------------------
void InrImageBase::init_from_inrimage(inrimage* inr)
{
  _tx     = inr->ncols;
  _ty     = inr->nrows;
  _tz     = inr->nplanes;
  _vdim   = inr->vdim;
  _txy    = _tx*_ty;
  _size_x = inr->vx;
  _size_y = inr->vy;
  _size_z = inr->vz;
  _format = inr->type;

} //init_from_inrimage()

//-----------------------------------------------------------------------
unsigned char InrImageBase::Read()
{
  inrimage* ptr;

  printf("lecture de %s \n", (char*) _nom);
  Si (_nom == "<") Alors
    // entree standard
    ptr = readZInrimage( NULL);
  Sinon
    ptr = readZInrimage( (char*) _nom);
  FinSi

  Si ptr == NULL Alors
    E_SETERR(E_ERRR, "reading in file", (char*) _nom);
    return false;
  FinSi

  _inrimage = ptr;
  init_from_inrimage( _inrimage);

  _inrimage_allouee = true;

  return true;
}


//-----------------------------------------------------------------------
unsigned char InrImageBase::Alloue()
{
  cout << _tx << ";" << _ty << ";" << _tz << endl;
  cout << _format << ";" << TailleFormat[_format] << endl;
  printf("allocation de %s \t taille = %d \n", (char*) _nom, 
         _tx*_ty*_tz*TailleFormat[_format]*_vdim);
  _inrimage = createInrimage( _tx, _ty, _tz, VectorDim[_format], 
			      (WORDTYPE) _format );
  return true;
}


//-----------------------------------------------------------------------
unsigned char InrImageBase::Ecrit()
{
  writeZInrimage( _inrimage, (char*) _nom);
  return true;
}


//-----------------------------------------------------------------------
unsigned char InrImageBase::Desalloue()
{
  printf("liberation de %s \n", (char*) _nom);
  freeInrimage(_inrimage);
  return true;
}


//--------------------------------------------------------------------------
unsigned char InrImageBase::LitMaple(const char* nom )
//                    --------     
{

  
    char chaine[100];
    int    x;
    float      r;
    FILE*     fic;

  fic = fopen( nom, "r");
  Si fic == NULL Alors
    printf("InrImage::LitMaple()\t Erreur dans l'ouverture du fichier de %s \n", nom);
    return false;
  FinSi

  fscanf(fic,"Type:\t%s\n",chaine);
  printf("chaine = '%s'\n",chaine);
  Si strcmp(chaine,"Image1D")!=0 Alors
    printf("InrImage::LitMaple()\t Erreur, Pour lecture d'image 1D uniquement ... \n");
    return false;
  FinSi

  // Initialisation
  _nom = nom;
  _nom += ".inr";

  fscanf(fic,"Dimension:\t%d\n",&_tx);
  _ty = _tz = 1;

  _size_x = _size_y = _size_z = 1;

  _format = WT_FLOAT;

  // Allocation
  Alloue();

  // Lecture
  Pour(x,0,_tx-1)
    fscanf(fic,"%f\t",&r);
    ((float*)_inrimage->data)[x]=r;
  FinPour

  fclose(fic);

  return true;

} // LitMaple()


//--------------------------------------------------------------------------
unsigned char InrImageBase::EcritMaple(const char* nom )
//                    ----------     
{

  
    int    x;
    float      r;
    FILE*     fic;

  fic = fopen( nom, "w");
  Si fic == NULL Alors
    printf(" Erreur dans l'ouverture du fichier de %s \n", nom);
    return false;
  FinSi

  fprintf(fic,"Type:\tImage1D\n");
  fprintf(fic,"Dimension:\t%d\n",_tx);

  Pour(x,0,_tx-1)
    r = ((float*)_inrimage->data)[x];
    fprintf(fic,"%f\t",r);
  FinPour

  fclose(fic);

  return true;

} // EcritMaple()


//==========================================================================
// MEMBRES PUBLICS
//==========================================================================

//-----------------------------------------------------------------------
InrImageBase::InrImageBase( const char* nom)
{
  //----- Lecture de l'image d'entree
  _nom = nom;
  _message_erreur = "";
  Read();
}

//-----------------------------------------------------------------------
InrImageBase::InrImageBase( const char* nom, int type)
{
  Si type != TYPE_MAPLE AlorsRetourne;
  LitMaple( nom);
}


//-----------------------------------------------------------------------
InrImageBase::InrImageBase( int dimx, 
			    int dimy, 
			    int dimz, 
			    const char* nom)
{
  Si nom == NULL Alors
    _nom = "sans_nom.inr";
  Sinon
    _nom = nom;
  FinSi
  _tx = dimx;
  _ty = dimy;
  _tz = dimz;
  _txy = _tx*_ty;
  _size_x = _size_y = _size_z = 1;
}

//-----------------------------------------------------------------------
InrImageBase::~InrImageBase()
{
  Si _inrimage_allouee AlorsFait Desalloue();
}


//----------------------------------------------------------------
void InrImageBase::SetVoxelSize( float sx, float sy, float sz)
//                 ------------------
{

  _size_x = sx;
  _size_y = sy;
  _size_z = sz;

} // SetVoxelSize()


//--------------------------------------------------------------------------
// Defaut char* nom = NULL
unsigned char InrImageBase::Sauve(const char* nom )
//                    -----
{

  Si nom!=NULL Alors
    _nom = nom;
  FinSi
  return Ecrit();

}

