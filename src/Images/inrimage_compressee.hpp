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
 * $Log: inrimage_compressee.hpp,v $
 * Revision 1.2  2005/11/16 14:03:09  karl
 * added LGPL license
 *
 * Revision 1.1.1.1  2004/02/02 20:47:08  karl
 * source code in C++
 *
 * Revision 1.1.1.1  2000/04/07 16:12:13  karl
 * Sources code
 *
 * Revision 1.6  1998/10/02 20:08:15  kkrissia
 * Creation d'une classe InrImage Template
 *
 ***************************************************************************/
//  Fichier inrimage2.hpp
// 
// Creation d'une classe InrImage permettant de
// manipuler les images dans le format inrimage
//
// Version sans la librairie epidaure
//
// Karl KRISSIAN	Sophia Antipolis, le 30-05-96
//

// Ce qui peut etre interessant : 
//
// 1. definition d'une region d'interet :
//    i.e. d'un tableau de booleen


// 2. Gerer les affichages Maple a l'aide
//    d'une classe speciale
//


// 3. Penser a la gestion des erreurs ...
//
//


// Creer des operations independantes du type de l'image
//

// Operation de conversion de types
//


#ifndef _INRIMAGE_COMPRESSEE_HPP
#define _INRIMAGE_COMPRESSEE_HPP

#include "style.hpp"
#include "chaine.hpp"

//@Include: /u/broca/0/kkrissia/Sources/Prog/Commun/include/chaine.doc  /user/jmontagn/src/Zinrimage/*.h

#include "inrimage.hpp"



//----------------------------------------------------------
void InitMasque( InrImage* image_mask, InrImage*& image_mask2, long& nbpoints);
//   ----------




/** Utilise InrImage en stockant moins de points en memoire vive
*/
class InrImageCompressee : public InrImage
//     ==================
{

public:
  /// Exceptions
  //@{
    class ErreurAllocation
    {
    };

    class ErreurMethodeNonGeree
    {
    };
  //@}

protected:

  ///
  InrImage* _masque_positions;

  /// Nombre de voxels dont les valeurs sont stockees
  int    _nb_points;

/** @name Tableaux des valeurs stockees pour les differents formats */
  //@{
    ///
    FORMAT_UNSIGNED_CHAR*    _valeurs_UNSIGNED_CHAR;

    ///
    FORMAT_UNSIGNED_SHORT*   _valeurs_UNSIGNED_SHORT;

    ///
    FORMAT_SIGNED_SHORT*     _valeurs_SIGNED_SHORT;

    ///
    FORMAT_SIGNED_INT*       _valeurs_SIGNED_INT;

    ///
    FORMAT_FLOAT*            _valeurs_FLOAT;

    ///
    FORMAT_DOUBLE*           _valeurs_DOUBLE;

    /// RGB
    FORMAT_RGB*              _valeurs_RGB;

    /// Vecteur de Float
    FORMAT_FLOAT_VECTOR*     _valeurs_FLOAT_VECTOR;
//@}


private:

  // Operation d'allocation, de lecture, d'ecriture
  ///
  unsigned char   Lit() throw (ErreurLecture);

  ///
  unsigned char   Alloue();
  ///
  unsigned char   Ecrit() throw (ImageWriteError);
  ///
  unsigned char   Desalloue();

  /// initialisation du tableau de positions _positions[z][y]
  unsigned char   InitPositions();

  /// initialisation du tableau de positions _positions[z][y]
  unsigned char   EffacePositions() {  return true;}

  ///
  WORDTYPE  ZimageFormat( int format);

public:


  /** @name 2-Diff�rents constructeurs  et le destructeur */
  //@{
 
    /**
      Cree une nouvelle image au format specifie en utilisant
      les dimensions de l'image image (taille, taille des voxels)
      image est le masque utilise pour la compression
    */
    Constructeur InrImageCompressee( WORDTYPE format, char* nom, 
				     InrImage* image, int nb_points);

    Destructeur  InrImageCompressee();
  //@}

  /** @name 3-Acc�s aux champs de la classe */
  //@{
    /** 
      @return pointeur sur les donnees
    */

    ///
    char*    Nom() { return _nom;}
    //            ---

  //@}

    /// Initialisation tous les voxels a la valeurs val
    void InitImage( double val);
    //   ---------
 
    /// Copie d'images
    unsigned char operator=( InrImage& im);
    //      ---------


  /** @name 4-M�thode li�es � la gestion du buffer */
  //@{
    /** Op�ration de parcours de buffer inter-formats
     */
    void InitBuffer( int pos = 0);
    //   ----------

    //  
     void BufferPos( int x, int y, int z)
    //   ---------
    {

     _buffer_SIGNED_INT     = (_positions_SIGNED_INT[z][y] + x);  
      _pos_buf = ((unsigned long) z*_ty + y)* _tx + x;

    } // BufferPos()


    /**
       Pointeur sur la position courante du buffer
    */
    void*  BufferPtr() throw (ErreurMethodeNonGeree)
    //     ---------
    {

      cerr<< " InrImageCompressee:BufferPtr   ErreurMethodeNonGeree \n";
      throw ErreurMethodeNonGeree();
//      return NULL;

    } // BufferPtr()


    /**
       Fonction en ligne
       Incr�mentation du buffer
    */
    int IncBuffer( int inc=1)
    //     ---------
    {

      Si ++_pos_buf >= _taille AlorsRetourne 0;
      _buffer_SIGNED_INT     += inc;
      return 1;

    } // IncBuffer()


    /**
       Renvoie la valeur de l'image � la position courante du buffer
    */
    double ValeurBuffer( )
    //         ------------
    {

      SelonQue (WORDTYPE) _format Vaut

        Valeur WT_DOUBLE:         return _valeurs_DOUBLE        [*_buffer_SIGNED_INT];
        Valeur WT_FLOAT:          return _valeurs_FLOAT         [*_buffer_SIGNED_INT];
        Valeur WT_UNSIGNED_CHAR:  return _valeurs_UNSIGNED_CHAR [*_buffer_SIGNED_INT];
        Valeur WT_UNSIGNED_SHORT: return _valeurs_UNSIGNED_SHORT[*_buffer_SIGNED_INT];
        Valeur WT_SIGNED_SHORT:   return _valeurs_SIGNED_SHORT  [*_buffer_SIGNED_INT];
        Valeur WT_SIGNED_INT:     return _valeurs_SIGNED_INT    [*_buffer_SIGNED_INT];

        Defaut: printf("InrImageCompressee::ValeurBuffer()\t format non gere...\n");

      FinSelonQue

      return 0;

    } // ValeurBuffer()


    //
    double ValeurBuffer( int inc)
    //   ------------
    // Renvoie la valeur du buffer+inc
    {

      SelonQue (WORDTYPE) _format Vaut

        Valeur WT_DOUBLE:         
            return _valeurs_DOUBLE        [*(_buffer_SIGNED_INT + inc)];
        Valeur WT_FLOAT:          
            return _valeurs_FLOAT         [*(_buffer_SIGNED_INT + inc)];
        Valeur WT_UNSIGNED_CHAR:  
            return _valeurs_UNSIGNED_CHAR [*(_buffer_SIGNED_INT + inc)];
        Valeur WT_UNSIGNED_SHORT: 
            return _valeurs_UNSIGNED_SHORT[*(_buffer_SIGNED_INT + inc)];
        Valeur WT_SIGNED_SHORT:   
            return _valeurs_SIGNED_SHORT  [*(_buffer_SIGNED_INT + inc)];
        Valeur WT_SIGNED_INT:     
            return _valeurs_SIGNED_INT    [*(_buffer_SIGNED_INT + inc)];

        Defaut: printf("InrImageCompressee::InterpLinIntensite()\t format non gere...\n");

      FinSelonQue
 
      return 0;

    } // ValeurBuffer()

    /**
      Renvoie la valeur du buffer pour la coordonnee i (0:x, 1:y, 2:z)
    */
    double VectValeurBuffer( int i )
    //         ----------------
    {

      SelonQue (WORDTYPE) _format Vaut
    //        Valeur WT_RGB:
        Valeur WT_FLOAT_VECTOR: return _valeurs_FLOAT_VECTOR[(*_buffer_SIGNED_INT)+i];
        Defaut: printf("InrImageCompressee::VectValeurBuffer()\t format non gere...\n");
      FinSelonQue

      return 0;

    } // VectValeurBuffer()


    void FixeValeur( double val)
    //   ----------
    // Fixe la valeur de l'image au point courant du buffer
    {

      SelonQue (WORDTYPE) _format Vaut

        Valeur WT_DOUBLE:         _valeurs_DOUBLE        [*_buffer_SIGNED_INT] = 
              (FORMAT_DOUBLE)         val;
        FinValeur

        Valeur WT_FLOAT:          _valeurs_FLOAT         [*_buffer_SIGNED_INT] = 
              (FORMAT_FLOAT)          val;
        FinValeur

        Valeur WT_UNSIGNED_CHAR:  _valeurs_UNSIGNED_CHAR [*_buffer_SIGNED_INT] = 
              (FORMAT_UNSIGNED_CHAR)  val;
        FinValeur

        Valeur WT_UNSIGNED_SHORT: _valeurs_UNSIGNED_SHORT[*_buffer_SIGNED_INT] = 
              (FORMAT_UNSIGNED_SHORT) val;
        FinValeur

        Valeur WT_SIGNED_SHORT:  _valeurs_SIGNED_SHORT   [*_buffer_SIGNED_INT] = 
              (FORMAT_SIGNED_SHORT)   val; 
        FinValeur

        Valeur WT_SIGNED_INT:    _valeurs_SIGNED_INT     [*_buffer_SIGNED_INT] = 
              (FORMAT_SIGNED_INT)     val; 
        FinValeur

        Valeur WT_RGB:         
          _valeurs_RGB[(*_buffer_SIGNED_INT)  +0]   =
          _valeurs_RGB[(*_buffer_SIGNED_INT)  +1]   =
          _valeurs_RGB[(*_buffer_SIGNED_INT)  +2]   =
               (FORMAT_UNSIGNED_CHAR)    val;
        FinValeur

        Valeur WT_FLOAT_VECTOR:         
          _valeurs_FLOAT_VECTOR[(*_buffer_SIGNED_INT)  +0]   =
          _valeurs_FLOAT_VECTOR[(*_buffer_SIGNED_INT)  +1]   =
          _valeurs_FLOAT_VECTOR[(*_buffer_SIGNED_INT)  +2]   =
               (FORMAT_FLOAT)    val;
        FinValeur

        Defaut: printf("InrImageCompressee::FixeValeur()\t format non gere...\n");

      FinSelonQue

    } // FixeValeur()


    //
    void VectFixeValeurs( double valx, double valy, double valz)
    //   ---------------
    // Fixe la valeur de l'image au point courant du buffer
    {

      SelonQue (WORDTYPE) _format Vaut

        Valeur WT_RGB:         
          _valeurs_RGB[(*_buffer_SIGNED_INT)+0] = (FORMAT_UNSIGNED_CHAR) valx;
          _valeurs_RGB[(*_buffer_SIGNED_INT)+1] = (FORMAT_UNSIGNED_CHAR) valy;
          _valeurs_RGB[(*_buffer_SIGNED_INT)+2] = (FORMAT_UNSIGNED_CHAR) valz;
        FinValeur

        Valeur WT_FLOAT_VECTOR:         
          _valeurs_FLOAT_VECTOR[(*_buffer_SIGNED_INT)+0] = (FORMAT_FLOAT) valx;
          _valeurs_FLOAT_VECTOR[(*_buffer_SIGNED_INT)+1] = (FORMAT_FLOAT) valy;
          _valeurs_FLOAT_VECTOR[(*_buffer_SIGNED_INT)+2] = (FORMAT_FLOAT) valz;
        FinValeur

        Defaut: printf("InrImageCompressee::VectFixeValeur()\t format non gere...\n");
  
      FinSelonQue
  
    } // VectFixeValeur()


  //@}


  /** @name 5- Lecture-Ecriture, Sauvegarde de l'image */
  //@{

    ///
    unsigned char Sauve( const char* nom = (char*)NULL) throw (ErreurMethodeNonGeree)
    //     ---------
    {

      
        InrImage* image;

      Si nom!=NULL Alors
        _nom = nom;
      FinSi

      cout << " Sauvegarde de " << _nom << "\n";

      image      = new InrImage( _format, _nom, this );
      image->InitBuffer();
      InitBuffer();
      Repeter
        image->FixeValeur( ValeurBuffer());
        IncBuffer();
      JusquA Non(image->IncBuffer()) FinRepeter
      image->Sauve();
      delete image;

      return true;

    } // ()



    ///
    Chaine* MessageErreur();
    //      -------------

  //@}


  /** @name 6-Red�finitions d'op�rateurs */
  //@{
    /**
     */
    operator t_Image*() throw (ErreurMethodeNonGeree)
    //     ---------
    {

      cerr<< " InrImageCompressee:t_Image*...   ErreurMethodeNonGeree \n";
      throw ErreurMethodeNonGeree();

//      return (t_Image*) NULL;

    } // ()

 
    /* 
      */
    operator t_Image() throw (ErreurMethodeNonGeree)
    //     ---------
    {

      cerr<< " InrImageCompressee:t_Image...   ErreurMethodeNonGeree \n";
      throw ErreurMethodeNonGeree();


    } // ()


    // 
    operator inrimage*() throw (ErreurMethodeNonGeree)
    //     ---------
    {

      cerr<< " InrImageCompressee:inrimage*...   ErreurMethodeNonGeree \n";
      throw ErreurMethodeNonGeree();

//     return (inrimage*) NULL;

    } // ()

 
    // 
    operator inrimage() throw (ErreurMethodeNonGeree)
    //     ---------
    {

      cerr<< " InrImageCompressee:inrimage...   ErreurMethodeNonGeree \n";
      throw ErreurMethodeNonGeree();

    } // ()


    //  {\bf Operator(x,y,z) }
    double operator()( int x, int y, int z)
    //         --------
    {

      SelonQue (WORDTYPE) _format Vaut
 
        Valeur WT_DOUBLE:
          return _valeurs_DOUBLE         [_positions_SIGNED_INT[z][y][x]];

        Valeur WT_FLOAT:
          return _valeurs_FLOAT          [_positions_SIGNED_INT[z][y][x]];

        Valeur WT_UNSIGNED_CHAR: 
           return _valeurs_UNSIGNED_CHAR [_positions_SIGNED_INT[z][y][x]];

        Valeur WT_UNSIGNED_SHORT:
           return _valeurs_UNSIGNED_SHORT[_positions_SIGNED_INT[z][y][x]];

        Valeur WT_SIGNED_SHORT:
           return _valeurs_SIGNED_SHORT  [_positions_SIGNED_INT[z][y][x]];

        Valeur WT_SIGNED_INT:
           return _valeurs_SIGNED_INT    [_positions_SIGNED_INT[z][y][x]];

        Defaut: printf("InrImageCompressee::operator()\t format non gere...\n");

      FinSelonQue

      return 0;

    }


    //  {\em Operator(x,y,z,coord) }
    double operator()( int x, int y, int z, int coord)
    //         --------
    {

      SelonQue (WORDTYPE) _format Vaut

        Valeur WT_RGB:
          return _valeurs_RGB[_positions_SIGNED_INT[z][y][x]+coord];

        Valeur WT_FLOAT_VECTOR:
          return _valeurs_FLOAT_VECTOR[_positions_SIGNED_INT[z][y][x]+coord];

        Defaut: printf("InrImageCompressee::operator(x,y,z,coord)\t format non gere...\n");

      FinSelonQue

      return 0;

    }


  //@}


  // Interpolation Lin�aire de l'intensit� au point (x,y,z)
  double InterpLinIntensite2( double dx1, double dx2, int tx1, int tx2)
  //   -------------------
  {

    
      register double coeff00,coeff01,coeff10,coeff11;
      register int     tx12;
      register double res;

    coeff00 = 1.0 - dx1;
    coeff10 = dx1;

    coeff01 = coeff00 * dx2;
    coeff11 = coeff10 * dx2;

    coeff00 -= coeff01;
    coeff10 -= coeff11;

    tx12 = tx1+tx2;

    SelonQue (WORDTYPE) _format Vaut

      Valeur WT_FLOAT:
        res  = coeff00* _valeurs_FLOAT[*(_buffer_SIGNED_INT    ) ] + 
               coeff10* _valeurs_FLOAT[*(_buffer_SIGNED_INT+tx1) ] +
               coeff01* _valeurs_FLOAT[*(_buffer_SIGNED_INT+tx2) ] + 
               coeff11* _valeurs_FLOAT[*(_buffer_SIGNED_INT+tx12)];
      FinValeur

      Defaut: printf("InrImage::InterpLinIntensite2()\t format non gere...\n");

    FinSelonQue

    return res;

  } // InterpLinIntensite2()


  /** Interpolation Lin�aire de l'intensit� au point (x,y,z)
   en coordonn�es r�elles
   Prendre en compte la taille des voxels ???
   Pour une image 3D ...
  */
  double InterpLinIntensite( float x, float y, float z)
  //         ------------------
  {
    
      register int     xi,yi,zi;
      register double dx,dy,dz;
      register double res;
      register double coeff000,coeff010,coeff100,coeff110;
      register double coeff001,coeff011,coeff101,coeff111;

    Si (x < 0) Ou ( x > _tx-1) Ou
       (y < 0) Ou ( y > _ty-1) Ou
       (z < 0) Ou ( z > _tz-1) AlorsRetourne 0;

    xi = (int) x;           
    yi = (int) y;           
    zi = (int) z;

    dx = x - (double)xi;   
    dy = y - (double)yi;   
    dz = z - (double)zi;

    Si xi == _tx-1 Alors      xi = _tx-2;      dx = 1.0;    FinSi
    Si yi == _ty-1 Alors      yi = _ty-2;      dy = 1.0;    FinSi
    Si zi == _tz-1 Alors      zi = _tz-2;      dz = 1.0;    FinSi

    Si dx < 1E-10 Alors
      BufferPos(xi,yi,zi);
      return InterpLinIntensite2(dy,dz,_tx,_txy);
    FinSi

    Si dy < 1E-10 Alors
      BufferPos(xi,yi,zi);
      return InterpLinIntensite2(dx,dz,1,_txy);
    FinSi

    Si dz < 1E-10 Alors
      BufferPos(xi,yi,zi);
      return InterpLinIntensite2(dx,dy,1,_tx);
    FinSi

    /*--- calcul des poids associ�s � chaque point ---*/
    // 16 multiplication, 12 additions, 8 affectations
    // coeff000 = (1.0 - dx) * (1.0 - dy) * (1.0 - dz);
    // coeff100 = dx         * (1.0 - dy) * (1.0 - dz);
    // coeff010 = (1.0 - dx) * dy         * (1.0 - dz);
    // coeff110 = dx         * dy         * (1.0 - dz);
    // coeff001= (1.0 - dx) * (1.0 - dy)  * dz;
    // coeff101 = dx         * (1.0 - dy) * dz;
    // coeff011 = (1.0 - dx) * dy         * dz;
    // coeff111 = dx         * dy         * dz;


    // 6 multiplication, 7 additions, 14 affectations
    coeff000 = 1.0 - dx;
    coeff100 = dx;

    coeff010 = coeff000 * dy;
    coeff110 = coeff100 * dy;

    coeff000 -= coeff010;
    coeff100 -= coeff110;

    coeff001 = coeff000*dz; 
    coeff101 = coeff100*dz; 
    coeff011 = coeff010*dz; 
    coeff111 = coeff110*dz; 

    coeff000 -= coeff001;
    coeff100 -= coeff101;
    coeff010 -= coeff011;
    coeff110 -= coeff111;

// BufferPos(xi,yi,zi);
// res  = coeff000*ValeurBuffer()       + coeff100*ValeurBuffer(1);
// res += coeff010*ValeurBuffer(tx)     + coeff110*ValeurBuffer(tx+1);
// res += coeff001*ValeurBuffer(txy)    + coeff101*ValeurBuffer(txy+1);
// res += coeff011*ValeurBuffer(txy+tx) + coeff111*ValeurBuffer(txy+tx+1);

    //--- Calcul de l'intensit�
    SelonQue (WORDTYPE) _format Vaut

      Valeur WT_FLOAT:
        _buffer_SIGNED_INT = (_positions_SIGNED_INT[zi][yi] + xi); 

        res  = coeff000* _valeurs_FLOAT[*(_buffer_SIGNED_INT           )]  + 
               coeff100* _valeurs_FLOAT[*(_buffer_SIGNED_INT         +1)]  + 
               coeff010* _valeurs_FLOAT[*(_buffer_SIGNED_INT     +_tx  )]  + 
               coeff110* _valeurs_FLOAT[*(_buffer_SIGNED_INT     +_tx+1)]  +
               coeff001* _valeurs_FLOAT[*(_buffer_SIGNED_INT+_txy      )]  + 
               coeff101* _valeurs_FLOAT[*(_buffer_SIGNED_INT+_txy    +1)]  +
               coeff011* _valeurs_FLOAT[*(_buffer_SIGNED_INT+_txy+_tx  )]  + 
               coeff111* _valeurs_FLOAT[*(_buffer_SIGNED_INT+_txy+_tx+1)];
      FinValeur

      Defaut: printf("InrImage::InterpLinIntensite()\t format non gere...\n");

    FinSelonQue

    return res;

  } // InterpLinIntensite()


}; // InrImageCompressee


#endif // _INRIMAGE_COMPRESSEE_HPP

