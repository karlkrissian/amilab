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


#ifndef _NOYAUPARAMETRE_HPP
#define _NOYAUPARAMETRE_HPP

#include "widget.hpp"


#define MAX_ARGS         20

#define EMPILE_VERTICAL   1
#define EMPILE_HORIZONTAL 2

//==============================================================================
/**
   class Noyau Parametre
   class de base pour tous les types de param�tres
 */
class NoyauParametre : public CWidget
//     ==============
{

protected:

  Widget    _separateur;

  Widget        _first_widget;

// Attachement
  Widget        _attache_gauche;
  Widget        _attache_haut;

  Widget        _attache_bas;
  Widget        _attache_droite;

  unsigned char       _separe;

  unsigned char       _visible;

  void*     _callback;
  void*     _calldata;

  unsigned char       _value_changed; // permet de savoir si la valeur a changee
                // apres la fonction RecupereValeur()

  int   n;
  Arg       args[ MAX_ARGS ];

   //
  void AjouteSeparateur( Widget precedent);
  //   ----------------

public:

  int        _type_empilement;

  //
  Constructeur NoyauParametre( Widget parent);
  //----------

  //
  virtual Destructeur NoyauParametre();
  //        ---------

  //
  void Separe() {  _separe = true; }
  //   ------

  //
  Widget GetSeparator() {  return _separateur; }
  //     ------------

  //
  void Attache(Widget haut, Widget gauche, Widget bas = NULL, Widget droite=NULL) 
  //   -------
  {
    _attache_gauche = gauche; 
    _attache_haut = haut;
    _attache_bas = bas;
    _attache_droite = droite;
  }

  ///
  void SetStackDirection( int type_empilement)
  //   -----------------
  {
    _type_empilement = type_empilement;
  }

  //
  void ChangedValueCallback( void* callback, void* calldata) 
  //   --------------------
  {  
      _callback = callback; _calldata = calldata; 
  }


  /// Set de Drag Callback like the changed value callback
  virtual void SetDragCallback( ) {}
  //             ---------------

  ///
  unsigned char Visible() { return _visible; }
  //

  ///
  void FixeVisible( unsigned char visible ) { _visible=visible; }
  //

  ///
  virtual void UnManage() {  XtUnmanageChild(_widget); }
  //

  ///
  virtual void Manage()  { XtManageChild(_widget); }
  //

  ///
  void AttachePrecedent( Widget precedent_haut,
             Widget precedent_gauche=NULL);
  //

  //
  virtual void CreeParametre( Widget precedent_haut,
  //             -------------
                Widget precedent_gauche);

  //
  virtual void RecupereValeur() {}
  //             --------------


  //
  unsigned char ValueChanged() { return _value_changed; }
  //      ------------


  //
  virtual unsigned char VerifieContraintes() { return(true); }
  //                ------------------


  //
  virtual Widget DernierWidget() { return(NULL); }
  //               -------------

  //
  virtual Widget GetWidget() { return(NULL); }
  //               -----------

  ///
  Widget operator() (Widget) { return GetWidget();}
  //

  //
  virtual Widget FirstWidget() { return _first_widget ; }
  //               -----------


/** Cette methode permet de remettre a jour les
   contraintes du parametre dans le widget
*/ 
  virtual void MAJ_Contraintes() {}
  //             ---------------

/** Cette methode permet de remettre a jour la
   valeur du parametre dans le widget
*/ 
  virtual void MAJ() {}
  //             ---

  ///
  unsigned char  ReadPixmap(char* pixname, Pixmap& pix);
  //

  ///
  unsigned char  ReadPixmap(char** pixstring, Pixmap& pix);
  //

}; // NoyauParametre





#endif // _NOYAUPARAMETRE_HPP
