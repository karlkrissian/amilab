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
//  Fichier widget.cpp
//
//  Karl KRISSIAN	Sophia Antipolis, le 7-08-96
//

#include "widget.hpp"
#include <stdio.h>


/*
//-----------------------------------------------------------------------
void CWidget :: FixeDimensions( int largeur, int hauteur)
//                        --------------
{

  
	Arg	args[8];
	int	n;

  if (_widget == NULL ) return;

  n = 0;
  XtSetArg( args[n], XmNwidth,  largeur);  n++;
  XtSetArg( args[n], XmNheight, hauteur);  n++;

  XtSetValues( _widget, args, n);  

} // FixeDimensions()


//-----------------------------------------------------------------------
void CWidget :: FixeCouleurFond( Pixel couleur)
//                        ---------------
{

  
	Arg	args[8];
	int	n;

  if (_widget == NULL ) return;

  n = 0;
  XtSetArg( args[n], XmNbackground,  couleur);  n++;

  XtSetValues( _widget, args, n);  

} // FixeCouleurFond()


//-----------------------------------------------------------------------
void CWidget :: Attache( Widget haut, Widget gauche, 
//                        -------
			Widget bas, Widget droite)
{

  
	Arg	args[8];
	int	n;

  if (_widget == NULL ) return;

  // attachment done with wxWidgets
  //  if (_wxparent != NULL) return;

//  fprintf(stderr,"CWidget Attache() \n");

  n = 0;

  ATTACHE( XmNtopAttachment,     haut,   n)
  ATTACHE( XmNbottomAttachment,  bas,    n)
  ATTACHE( XmNrightAttachment,   droite, n)
  ATTACHE( XmNleftAttachment,    gauche, n)

  XtSetValues( _widget, args, n);  

} // Attache()


//-----------------------------------------------------------------------
void CWidget :: AttachePosition(  int pos_h, int pos_g, 
//                        ---------------
					    int pos_b, int pos_d) 
{

  
	Arg	args[8];
	int	n;

  if (_widget == NULL ) return;

  // attachment done with wxWidgets
  //if (_wxparent != NULL) return;

  n = 0;
  if (pos_h != -1) {
    XtSetArg( args[n], XmNtopAttachment,    XmATTACH_POSITION );  n++;
    XtSetArg( args[n], XmNtopPosition,        pos_h); 		  n++;
  } // end if
  if (pos_b != -1) {
    XtSetArg( args[n], XmNbottomAttachment, XmATTACH_POSITION ); n++;
    XtSetArg( args[n], XmNbottomPosition,     pos_b); 		 n++;
  } // end if
  if (pos_d != -1) {
    XtSetArg( args[n], XmNrightAttachment,  XmATTACH_POSITION ); n++;
    XtSetArg( args[n], XmNrightPosition,      pos_d); 		 n++;
  } // end if
  if (pos_g != -1) {
    XtSetArg( args[n], XmNleftAttachment,   XmATTACH_POSITION );  n++;
    XtSetArg( args[n], XmNleftPosition,       pos_g); 	          n++;
  } // end if

  XtSetValues( _widget, args, n);  

} // AttachePosition()

*/

//======================================================================
//

void wxGenericWidget::Callback()
//
{
    if (this->_callback!=NULL) {
      void (*pf)( void*) = (void (*)(void*)) this->_callback;
      //      printf("calling _callback\n");
      pf( this->_calldata);
    }
/*
    if (this->_motif_callback!=NULL) {
      XtCallbackProc pf = (XtCallbackProc) this->_motif_callback;
      //if (GB_debug) fprintf(stderr,"calling _motif_callback\n");
      pf(NULL, this->_calldata, NULL);
    }
*/
}
