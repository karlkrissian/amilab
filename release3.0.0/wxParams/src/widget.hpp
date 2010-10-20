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
//  Fichier widget.hpp
//
//  Karl KRISSIAN Sophia Antipolis, le 7-08-96
//

#ifndef _WIDGET_HPP
#define _WIDGET_HPP
// includes for wxWidgets
#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif
#include "wx/propdlg.h"


//--------------------------------------------------

//#include "style.hpp"

/*
//=======================================================================
class CWidget
//     =======
{

protected:

  Widget  _parent;
  Widget  _widget;

  wxWindow*      _wxparent;
  
public:

   CWidget( Widget parent)
  {
    _parent = parent;
    _wxparent=NULL;
  }

  ~ CWidget()
  {
  XtUnmanageChild( _widget);
  }

  Widget GetWidget() { return _widget; }
  Widget GetParent() { return _parent; }
  //
  void FixeDimensions( int l, int h);

  //
  void FixeCouleurFond( Pixel couleur);

  void Attache( Widget haut, Widget gauche, Widget bas, Widget droite);

  void AttachePosition( int pos_h, int pos_g, int pos_b, int pos_d);

}; // CWidget

*/

//======================================================================
/*!
  \brief wxGenericWidget: a generic widget class including a callback information
*/
class wxGenericWidget  //: public wxWindow
{

protected:

  void*       _calldata;
  void*       _callback;
  bool        _enabled;
//  void*       _motif_callback;

public:
  wxGenericWidget()
  {
    _callback       = NULL;
    _calldata       = NULL;
    _enabled        = true;
//    _motif_callback = NULL;
  }
  
  virtual ~wxGenericWidget() {}

  void Callback();

  void ChangedValueCallback( void* callback, void* calldata) 
  //   --------------------
  {  
      _callback = callback; _calldata = calldata; 
  }

  
//  virtual void Show( bool) {}
  
  virtual void UpdateValue() {}
  
  virtual void Update() {}

  bool IsEnabled() const 
  {
    return _enabled;
  }

  virtual void EnableWidget(bool enable = true) {  }

};

#endif // _WIDGET_HPP
